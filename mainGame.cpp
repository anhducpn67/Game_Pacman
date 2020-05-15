#include "LTexture.h"
#include "pacman.h"
#include "creatWallandPoint.h"
#include "externVariables.h"
#include "InitCloseSDL.h"

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

    //Create Pacman & Ghost Animation
    getPacmanAnimation();
    getGhostAnimation();

    //Load Background
    LTexture background;
    background.loadFromFile("Images/background.jpg");

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

        //Clear screen
        SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 255 );
        SDL_RenderClear( gRenderer );

        //Render wall
        for (int i = 1; i <= numbers_Wall; i++)
            SDL_RenderDrawRect( gRenderer, &wall[i] );

        //Render background
        background.render(0, 0);

        //Render Pacman
        pacman.render();

        // Render Ghost
        for (int i = 1; i <= 4; i++)
            ghost[i].render();

        //Pacman hit Ghost
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

        // Update frames;
        pacman.frames++;

        if( pacman.frames / 4 >= 4 )
        {
            pacman.frames = 0;
        }

        //Update screen
        SDL_RenderPresent( gRenderer );

        // End game
        if (quit == true)
        {

        }
    }
	//Free resources and close SDL
	close();
	return 0;
}

