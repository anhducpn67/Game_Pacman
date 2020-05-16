#include "LTexture.h"
#include "pacman.h"
#include "creatWallandPoint.h"
#include "InitCloseSDL.h"
#include "externVariables.h"
#include "renderGame.h"

using namespace std;

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
    createPoint();

    //Create Pacman & Ghost Animation & Point
    getPacmanAnimation();
    getGhostAnimation();

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
            if (checkCollision(A, B))
            {
                isEateanPoint[rowi][coli] = true;
                Score += 10;
            }
        }

        //Render Game
        RenderGame();

        cout << Score << "\n";

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
    }
	//Free resources and close SDL
	close();
	return 0;
}

