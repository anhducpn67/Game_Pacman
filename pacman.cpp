#include "pacman.h"
#include "externVariables.h"

//Create Pacman
Pacman pacman;

Pacman::Pacman()
{
    //Initialize the offsets
    mPosX = 20;
    mPosY = 20;

    //Set collision box dimension
    mCollider.w = PACMAN_WIDTH;
    mCollider.h = PACMAN_HEIGHT;
    mCollider.x = mPosX;
    mCollider.y = mPosY;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}

bool checkCollision( SDL_Rect& a, SDL_Rect& b )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }


    //If none of the sides from A are outside B
    return true;
}

void Pacman::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_UP:
            {
                direct = 3;
                mVelY = -PACMAN_VEL;
                mVelX = 0;
                break;
            }
            case SDLK_DOWN:
            {
                direct = 1;
                mVelY = PACMAN_VEL;
                mVelX = 0;
                break;
            }
            case SDLK_LEFT:
            {
                direct = 2;
                mVelX = -PACMAN_VEL;
                mVelY = 0;
                break;
            }
            case SDLK_RIGHT:
            {
                direct = 0;
                mVelX = PACMAN_VEL;
                mVelY = 0;
                break;
            }
        }
    }
}

void Pacman::move( SDL_Rect wall[], int numbers_Wall)
{
    //Move Pacman left or right
    mPosX += mVelX;
    mCollider.x = mPosX;

    bool checkColl = false;
    int posWall = -1;
    for (int i = 1; i <= numbers_Wall; i++)
    {
        checkColl |= checkCollision(mCollider, wall[i]);
        if (checkColl == 1)
        {
            posWall = i;
            break;
        }
    }
    if (posWall != -1) // If char is blocked by wall[posWall]
    {
        for (int movePixel = 1; movePixel <= 15; movePixel++)
        {
            // Move char up movePixel pixels;
            mCollider.y -= movePixel;
            if (checkCollision(mCollider, wall[posWall]) == false)
            {
                mPosX -= mVelX;
                mPosY -= movePixel;
                return;
            }
            mCollider.y += movePixel;
            // Move char down movePixel pixels;
            mCollider.y += movePixel;
            if (checkCollision(mCollider, wall[posWall]) == false)
            {
                mPosX -= mVelX;
                mPosY += movePixel;
                return;
            }
            mCollider.y -= movePixel;
        }
    }

    //If Pacman went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + PACMAN_WIDTH > SCREEN_WIDTH ) || checkColl)
    {
        //Move back
        mPosX -= mVelX;
        mCollider.x = mPosX;
    }

    //Move Pacman up or down
    mPosY += mVelY;
    mCollider.y = mPosY;

    posWall = -1;

    checkColl = false;
    for (int i = 1; i <= numbers_Wall; i++)
    {
        checkColl |= checkCollision(mCollider, wall[i]);
        if (checkColl == 1)
        {
            posWall = i;
            break;
        }
    }

    if (posWall != -1) // If Pacman is blocked by wall[posWall]
    {
        for (int movePixel = 1; movePixel <= 15; movePixel++)
        {
            // Move Pacman left movePixel pixels;
            mCollider.x -= movePixel;
            if (checkCollision(mCollider, wall[posWall]) == false)
            {
                mPosY -= mVelY;
                mPosX -= movePixel;
                return;
            }
            mCollider.x += movePixel;
            // Move Pacman right movePixel pixels;
            mCollider.x += movePixel;
            if (checkCollision(mCollider, wall[posWall]) == false)
            {
                mPosY -= mVelY;
                mPosX += movePixel;
                return;
            }
            mCollider.x -= movePixel;
        }
    }

    //If Pacman went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + PACMAN_HEIGHT > SCREEN_HEIGHT ) || checkColl)
    {
        //Move back
        mPosY -= mVelY;
        mCollider.y = mPosY;
    }
}

//Pacman's animation
SDL_Rect pacmanAnimation[4][4];

void getPacmanAnimation()
{
    // 0 : Right
    pacmanAnimation[0][0].x = 850;   pacmanAnimation[0][0].y = 0;       pacmanAnimation[0][0].h = 50;   pacmanAnimation[0][0].w = 50;
    pacmanAnimation[0][1].x = 850;   pacmanAnimation[0][1].y = 50;      pacmanAnimation[0][1].h = 50;   pacmanAnimation[0][1].w = 50;
    pacmanAnimation[0][2].x = 850;   pacmanAnimation[0][2].y = 100;     pacmanAnimation[0][2].h = 50;   pacmanAnimation[0][2].w = 50;
    pacmanAnimation[0][3].x = 850;   pacmanAnimation[0][3].y = 150;     pacmanAnimation[0][3].h = 50;   pacmanAnimation[0][3].w = 50;
    // 1 : Down
    pacmanAnimation[1][0].x = 850;   pacmanAnimation[1][0].y = 150;     pacmanAnimation[1][0].h = 50;    pacmanAnimation[1][0].w = 50;
    pacmanAnimation[1][1].x = 850;   pacmanAnimation[1][1].y = 200;     pacmanAnimation[1][1].h = 50;    pacmanAnimation[1][1].w = 50;
    pacmanAnimation[1][2].x = 850;   pacmanAnimation[1][2].y = 250;     pacmanAnimation[1][2].h = 50;    pacmanAnimation[1][2].w = 50;
    pacmanAnimation[1][3].x = 850;   pacmanAnimation[1][3].y = 300;     pacmanAnimation[1][3].h = 50;    pacmanAnimation[1][3].w = 50;
    // 2 : Left
    pacmanAnimation[2][0].x = 850;   pacmanAnimation[2][0].y = 300;     pacmanAnimation[2][0].h = 50;    pacmanAnimation[2][0].w = 50;
    pacmanAnimation[2][1].x = 850;   pacmanAnimation[2][1].y = 350;     pacmanAnimation[2][1].h = 50;    pacmanAnimation[2][1].w = 50;
    pacmanAnimation[2][2].x = 850;   pacmanAnimation[2][2].y = 400;     pacmanAnimation[2][2].h = 50;    pacmanAnimation[2][2].w = 50;
    pacmanAnimation[2][3].x = 850;   pacmanAnimation[2][3].y = 450;     pacmanAnimation[2][3].h = 50;    pacmanAnimation[2][3].w = 50;
    // 3 : Up
    pacmanAnimation[3][0].x = 850;   pacmanAnimation[3][0].y = 450;     pacmanAnimation[3][0].h = 50;    pacmanAnimation[3][0].w = 50;
    pacmanAnimation[3][1].x = 850;   pacmanAnimation[3][1].y = 500;     pacmanAnimation[3][1].h = 50;    pacmanAnimation[3][1].w = 50;
    pacmanAnimation[3][2].x = 850;   pacmanAnimation[3][2].y = 550;     pacmanAnimation[3][2].h = 50;    pacmanAnimation[3][2].w = 50;
    pacmanAnimation[3][3].x = 850;   pacmanAnimation[3][3].y = 450;     pacmanAnimation[3][3].h = 50;    pacmanAnimation[3][3].w = 50;
}

void Pacman::render()
{
	sprites.render( mPosX, mPosY , &pacmanAnimation[direct][frames / 4]);
}

