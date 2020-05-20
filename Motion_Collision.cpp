#include "Motion_Collision.h"
#include "creatWallandPoint.h"
#include "externVariables.h"

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

void Motion_Collision(bool& quit)
{

        if (pacman.isDead == true)  return;

        //Move the Pacman, Ghost and check collision
        pacman.move( wall, numbers_Wall);
        for (int i = 1; i <= numberGhosts; i++)
        {
            ghost[i].handleEvent();
            ghost[i].move(wall, numbers_Wall);
        }

        //Check if pacman hit Ghost
        for (int i = 1; i <= numberGhosts; i++)
        {
            if (ghost[i].timeDeath != -1)   continue;
            int numbersPixel = 27;
            SDL_Rect A = pacman.mCollider;
            A.w -= numbersPixel;  A.h -= numbersPixel;
            A.x += numbersPixel;  A.y += numbersPixel;
            SDL_Rect B = ghost[i].mCollider;
            B.w -= numbersPixel;   B.h -= numbersPixel;
            B.x += numbersPixel;   B.y += numbersPixel;
            if (checkCollision(A, B))
            {
                if (pacman.eatCherry == true)   //Pacman eats ghosts
                {
                    Mix_PlayChannelTimed(-1, eatghost, 0, 1000);
                    Score += 100;
                    ghost[i].timeDeath = SDL_GetTicks();
                }
                if (pacman.eatCherry == false)  //Pacman dies
                {
                    Mix_HaltMusic();
                    Mix_PlayChannel(-1, die, 0);
                    pacman.Lives -= 1;
                    pacman.isDead = true;
                    break;
                }
            }
        }

        //Check if Pacman eats point
        for (int rowi = 1; rowi <= nRow; rowi++)
        for (int coli = 1; coli <= nCol; coli++)
        {
            if (isEateanPoint[rowi][coli])   continue;
            int numbersPixel = 20;
            SDL_Rect A = pacman.mCollider;
            A.w -= numbersPixel;  A.h -= numbersPixel;
            A.x += numbersPixel;  A.y += numbersPixel;
            SDL_Rect B;
            B.x = pointX[rowi][coli] + 18;   B.y = pointY[rowi][coli] + 18;
            B.w = 20;   B.h = 20;
            if (checkCollision(A, B))   // Pacman eats point
            {
                Mix_PlayChannelTimed(-1, eatpoint, 0, 500);
                isEateanPoint[rowi][coli] = true;
                Score += 10;
            }
        }

        //Check if Pacman eats cherry
        for (int i = 1; i <= 4; i++)
        {
            if (cherryX[i] == -1 && cherryY[i] == -1) continue;
            int numbersPixel = 20;
            SDL_Rect A = pacman.mCollider;
            A.w -= numbersPixel;  A.h -= numbersPixel;
            A.x += numbersPixel;  A.y += numbersPixel;
            SDL_Rect B;
            B.x = cherryX[i] + 18;   B.y = cherryY[i] + 18;
            B.w = 20;   B.h = 20;
            if (checkCollision(A, B))
            {
                cherryX[i] = -1;
                cherryY[i] = -1;
                Score += 50;
                pacman.eatCherry = true;
                Mix_HaltMusic();
                Mix_PlayChannel(-1, pacmaneatcherry, 0);
                pacman.timeEatCherry = SDL_GetTicks();
            }
        }

        //Handle pacman ate cherry and time to reset ghosts
        if (pacman.eatCherry == true)
        {
            int nowTime = SDL_GetTicks();
            if ((nowTime - pacman.timeEatCherry) / 1000 >= 10)
            {
                pacman.eatCherry = false;
                Mix_PlayMusic( theme, -1 );
            }
        }
        for (int i = 1; i <= numberGhosts; i++)
            if (ghost[i].timeDeath != -1)
            {
                int nowTime = SDL_GetTicks();
                if ((nowTime - ghost[i].timeDeath) / 1000 >= 5)
                {
                    ghost[i].resetGhost();
                    ghost[i].timeDeath = -1;
                }
            }

        //Check if all points is eaten
        bool remain = false;
        for (int rowi = 1; rowi <= nRow; rowi++)
        for (int coli = 1; coli <= nCol; coli++)
            if (isEateanPoint[rowi][coli] == false) remain = true;
        if (remain == false) createPoint();

        // Update frames;
        frames++;
        if(frames / 4 >= 4 )
        {
            frames = 0;
        }

        if (pacman.Lives == -1)
        {
            quit = true;
        }
}

//Event handler
SDL_Event e;

void handleEvent(bool &quit)
{
    while( SDL_PollEvent( &e ) != 0 )
    {
        //User requests quit
        if( e.type == SDL_QUIT )
        {
            quit = true;
        }
        //Handle input for Pacman
        pacman.handleEvent( e );
    }

}
