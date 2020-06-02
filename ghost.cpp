#include "ghost.h"
#include "Motion_Collision.h"
#include "externVariables.h"

//Create Ghost
Ghost ghosts[NUMBER_GHOSTS + 1];

Ghost::Ghost()
{
    //Initialize the offsets
    mPosX = 380;
    mPosY = 400;

    //Set collision box dimension
    mCollider.w = GHOST_WIDTH;
    mCollider.h = GHOST_HEIGHT;
    mCollider.x = mPosX;
    mCollider.y = mPosY;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;

    // Initialize direct and isBlock
    direct = 3;
    isBlock = false;
}

void Ghost::resetGhost()
{
    mPosX = 380;
    mPosY = 400;

    //Set collision box dimension
    mCollider.w = GHOST_WIDTH;
    mCollider.h = GHOST_HEIGHT;
    mCollider.x = mPosX;
    mCollider.y = mPosY;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;

    // Initialize direct and isBlock
    direct = 3;
    isBlock = false;
}

int Distance(int X1, int Y1, int X2, int Y2)
{
    return (X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2);
}

void Ghost::handleEvent() {
//    cout << isChasing << " " << startChasingTime << "\n";
    time_t currentTime = time(nullptr);
    if (Distance(pacman.mPosX, pacman.mPosY, mPosX, mPosY) <= 15000) {
        if (!isChasing && !isTired) {
            isChasing = true;
            startChasingTime = currentTime;
        } else if (isChasing && !isTired) {
            if (!pacman.eatCherry) {
                direct = directChasing();
            }
            if (pacman.eatCherry) {
                direct = directRunAway();
            }
            if (currentTime - startChasingTime >= CHASING_TIME) {
                isChasing = false;
                isTired = true;
                startTiredTime = currentTime;
            }
        }
    } else {
        if (isChasing) {
            isChasing = false;
        }
    }
    if (isTired) {
        if (currentTime - startTiredTime >= TIRED_TIME) {
            isTired = false;
        }
    }
    if (isBlock) {
        direct = rand() % 4;
    }
    if (rand() % 100 < PROB_CHANGE_DIRECTION && !isChasing) {
        direct = rand() % 4;
    }
    switch (direct) {
        case Up: {
            mVelY = -GHOST_VEL;
            mVelX = 0;
            break;
        }
        case Down: {
            mVelY = GHOST_VEL;
            mVelX = 0;
            break;
        }
        case Left:
        {
            mVelX = -GHOST_VEL;
            mVelY = 0;
            break;
        }
        case Right:
        {
            mVelX = GHOST_VEL;
            mVelY = 0;
            break;
        }
    };
}

bool canMove(SDL_Rect ghost_temp, SDL_Rect wall[], int numbers_Wall)
{
    for (int i = 1; i <= numbers_Wall; i++)
        if (checkCollision(ghost_temp, wall[i]))    return false;
    return true;
}

int Ghost::directChasing()
{
    int dx[] = {GHOST_VEL, 0        , -GHOST_VEL, 0         };
    int dy[] = {0        , GHOST_VEL, 0         , -GHOST_VEL};
    int directChase = 0;
    int distanceMin = 1e9 + 7;
    for (int i = 0; i < 4; i++)
    {
        int X = mPosX + dx[i];
        int Y = mPosY + dy[i];
        if( ( X < 0 ) || ( X + GHOST_WIDTH > 800 ) || (Y < 0) || ( mPosY + GHOST_HEIGHT > SCREEN_HEIGHT )) continue;
        SDL_Rect ghost_temp;
        ghost_temp.x = X;             ghost_temp.y = Y;
        ghost_temp.w = GHOST_WIDTH;   ghost_temp.h = GHOST_HEIGHT;
        if (Distance(X, Y, pacman.mPosX, pacman.mPosY) < distanceMin &&
            canMove(ghost_temp, walls, NUMBER_WALLS) == true) {
            distanceMin = Distance(X, Y, pacman.mPosX, pacman.mPosY);
            directChase = i;
        }
    }
    return directChase;
}

int Ghost::directRunAway()
{
    int dx[] = {GHOST_VEL, 0        , -GHOST_VEL, 0         };
    int dy[] = {0        , GHOST_VEL, 0         , -GHOST_VEL};
    int directRunAway = 0;
    int distanceMax = 0;
    for (int i = 0; i < 4; i++)
    {
        int X = mPosX + dx[i];
        int Y = mPosY + dy[i];
        if( ( X < 0 ) || ( X + GHOST_WIDTH > 800 ) || (Y < 0) || ( mPosY + GHOST_HEIGHT > SCREEN_HEIGHT )) continue;
        SDL_Rect ghost_temp;
        ghost_temp.x = X;             ghost_temp.y = Y;
        ghost_temp.w = GHOST_WIDTH;   ghost_temp.h = GHOST_HEIGHT;
        if (Distance(X, Y, pacman.mPosX, pacman.mPosY) > distanceMax &&
            canMove(ghost_temp, walls, NUMBER_WALLS) == true) {
            distanceMax = Distance(X, Y, pacman.mPosX, pacman.mPosY);
            directRunAway = i;
        }
    }
    return directRunAway;
}


void Ghost::move( SDL_Rect wall[], int numbers_Wall)
{
    isBlock = false;

    //Move Ghost left or right
    mPosX += mVelX;
    mCollider.x = mPosX;

    bool checkColl = false;
    for (int i = 1; i <= numbers_Wall; i++)
        checkColl |= checkCollision(mCollider, wall[i]);

    //If Ghost went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + GHOST_WIDTH > 800 ) || checkColl)
    {
        //Move back
        mPosX -= mVelX;
        mCollider.x = mPosX;
        isBlock = true;
    }

    //Move Ghost up or down
    mPosY += mVelY;
    mCollider.y = mPosY;

    checkColl = false;
    for (int i = 1; i <= numbers_Wall; i++)
        checkColl |= checkCollision(mCollider, wall[i]);

    //If Ghost went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + GHOST_HEIGHT > SCREEN_HEIGHT ) || checkColl)
    {
        //Move back
        mPosY -= mVelY;
        mCollider.y = mPosY;
        isBlock = true;
    }
}

SDL_Rect ghostAnimation[4][4][4];
SDL_Rect scaredGhost[2];

void getGhostAnimation()
{
    ghostAnimation[0][Right][0].x = 0;  ghostAnimation[0][Right][0].y = 0;      ghostAnimation[0][Right][0].w = 50;     ghostAnimation[0][Right][0].h = 50;
    ghostAnimation[0][Right][1].x = 0;  ghostAnimation[0][Right][1].y = 50;     ghostAnimation[0][Right][1].w = 50;     ghostAnimation[0][Right][1].h = 50;
    ghostAnimation[0][Down][0].x = 0;   ghostAnimation[0][Down][0].y = 100;     ghostAnimation[0][Down][0].w = 50;      ghostAnimation[0][Down][0].h = 50;
    ghostAnimation[0][Down][1].x = 0;   ghostAnimation[0][Down][1].y = 150;     ghostAnimation[0][Down][1].w = 50;      ghostAnimation[0][Down][1].h = 50;
    ghostAnimation[0][Left][0].x = 0;   ghostAnimation[0][Left][0].y = 200;     ghostAnimation[0][Left][0].w = 50;      ghostAnimation[0][Left][0].h = 50;
    ghostAnimation[0][Left][1].x = 0;   ghostAnimation[0][Left][1].y = 250;     ghostAnimation[0][Left][1].w = 50;      ghostAnimation[0][Left][1].h = 50;
    ghostAnimation[0][Up][0].x = 0;     ghostAnimation[0][Up][0].y = 300;       ghostAnimation[0][Up][0].w = 50;        ghostAnimation[0][Up][0].h = 50;
    ghostAnimation[0][Up][1].x = 0;     ghostAnimation[0][Up][1].y = 350;       ghostAnimation[0][Up][1].w = 50;        ghostAnimation[0][Up][1].h = 50;

    // Scared Ghost
    scaredGhost[0].x = 0; scaredGhost[0].y = 650;   scaredGhost[0].h = 50;  scaredGhost[0].w = 50;
    scaredGhost[1].x = 0; scaredGhost[1].y = 700;   scaredGhost[1].h = 50;  scaredGhost[1].w = 50;

    for (int ghosti = 1; ghosti < 4; ghosti++)
    for (int directi = 0; directi < 4; directi++)
    for (int animationi = 0; animationi <= 1; animationi++)
    {
            ghostAnimation[ghosti][directi][animationi].x = ghostAnimation[ghosti - 1][directi][animationi].x + 50;
            ghostAnimation[ghosti][directi][animationi].y = ghostAnimation[ghosti - 1][directi][animationi].y;
            ghostAnimation[ghosti][directi][animationi].w = ghostAnimation[ghosti - 1][directi][animationi].w;
            ghostAnimation[ghosti][directi][animationi].h = ghostAnimation[ghosti - 1][directi][animationi].h;
    }
}

void Ghost::render(int ghosti)
{
    if (pacman.eatCherry == false)
        sprites.render( mPosX, mPosY , &ghostAnimation[ghosti][direct][frames / 8]);
    if (pacman.eatCherry == true)
    {
        int Time = SDL_GetTicks();
        if ((Time - pacman.timeEatCherry) / 1000 >= 7)
        {
            if (frames / 4 <= 2)
                sprites.render (mPosX, mPosY, &scaredGhost[frames / 8]);
            else
                sprites.render (mPosX, mPosY , &ghostAnimation[ghosti][direct][frames / 8]);
        }
        else
        {
            sprites.render (mPosX, mPosY, &scaredGhost[frames / 8]);
        }
    }
}
