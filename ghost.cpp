#include "ghost.h"
#include "externVariables.h"

//Create Ghost
Ghost ghost[numberGhosts + 1];

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

void Ghost::handleEvent()
{
    if (isBlock == true)
        direct = rand() % 4;
    switch(direct)
    {
        case 3:
        {
            mVelY = -GHOST_VEL;
            mVelX = 0;
            break;
        }
        case 1:
        {
            mVelY = GHOST_VEL;
            mVelX = 0;
            break;
        }
        case 2:
        {
            mVelX = -GHOST_VEL;
            mVelY = 0;
            break;
        }
        case 0:
        {
            mVelX = GHOST_VEL;
            mVelY = 0;
            break;
        }
    };
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
    if( ( mPosX < 0 ) || ( mPosX + GHOST_WIDTH > SCREEN_WIDTH ) || checkColl)
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

void getGhostAnimation()
{
    ghostAnimation[0][0][0].x = 0;
    ghostAnimation[0][0][0].y = 0;
    ghostAnimation[0][0][0].w = 50;
    ghostAnimation[0][0][0].h = 50;
}

void Ghost::render()
{
	sprites.render( mPosX, mPosY , &ghostAnimation[0][0][0]);
}
