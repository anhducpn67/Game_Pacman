#include "LTexture.h"
#include "pacman.h"
#include "creatWallandPoint.h"
#include "InitCloseSDL.h"
#include "externVariables.h"
#include "renderGame.h"

using namespace std;

SDL_Rect point;
int pointX[100], pointY[100];
int nPoint = 0;
int Score = 0;
bool isEateanPoint[100];

void getPoint()
{
    point.x = 560; point.y = 600; point.h = 30; point.w = 30;
    pointX[0] = 20; pointY[0] = 25;
    // Row 1:
    for (int i = 1; i <= 11; i++)
    {
        nPoint++;
        pointX[nPoint] = pointX[nPoint - 1] + 30;
        pointY[nPoint] = pointY[nPoint - 1];
    }
    nPoint++;
    pointX[nPoint] = pointX[nPoint - 1] + 66; pointY[nPoint] = pointY[nPoint - 1];
    for (int i = 1; i <= 11; i++)
    {
        nPoint++;
        pointX[nPoint] = pointX[nPoint - 1] + 30;
        pointY[nPoint] = pointY[nPoint - 1];
    }
    // Done row 1
}

int main( int argc, char* args[] )
{
    srand(time(NULL));
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
		return 0;
	}
    //Load media
    if( !loadMedia() )
    {
        printf( "Failed to load media!\n" );
        return 0;
    }
    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //Create Walls
    createWalls();

    //Create Pacman & Ghost Animation & Point
    getPacmanAnimation();
    getGhostAnimation();
    getPoint();

    //Game loop
    while( !quit )
    {
        //Handle events on queue
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

        //Move the Pacman, Ghost and check collision
        pacman.move( wall, numbers_Wall);
        for (int i = 1; i <= 4; i++)
        {
            ghost[i].move(wall, numbers_Wall);
            ghost[i].handleEvent();
        }

        //Check if pacman hit Ghost
        for (int i = 1; i <= 4; i++)
        {
            int numbersPixel = 20;
            SDL_Rect A = pacman.mCollider;
            A.w -= numbersPixel;  A.h -= numbersPixel;
            A.x += numbersPixel;  A.y += numbersPixel;
            SDL_Rect B = ghost[i].mCollider;
            B.w -= numbersPixel;   B.h -= numbersPixel;
            B.x += numbersPixel;   B.y += numbersPixel;
            if (checkCollision(A, B))
            {
                quit = true;
                break;
            }
        }

        //Check if pacman eat point
        for (int i = 0; i <= nPoint; i++)
        {
            if (isEateanPoint[i])   continue;
            int numbersPixel = 20;
            SDL_Rect A = pacman.mCollider;
            A.w -= numbersPixel;  A.h -= numbersPixel;
            A.x += numbersPixel;  A.y += numbersPixel;
            SDL_Rect B;
            B.x = pointX[i] + 18;   B.y = pointY[i] + 18;
            B.w = 20;   B.h = 20;
            if (checkCollision(A, B))
            {
                isEateanPoint[i] = true;
                Score += 10;
            }
        }

        //Render Game
        RenderGame();

        cout << Score << "\n";

        // Test render Point
        for (int i = 0; i <= nPoint; i++)
            if (!isEateanPoint[i])
                sprites.render(pointX[i], pointY[i], &point);

        // Update frames;
        frames++;

        if(frames / 4 >= 4 )
        {
            frames = 0;
        }

        // End game
        if (quit == true)
        {

        }

        //Update screen
        SDL_RenderPresent( gRenderer );
    }
	//Free resources and close SDL
	close();
	return 0;
}

