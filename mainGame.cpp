#include "LTexture.h"
#include "pacman.h"
#include "creatWallandPoint.h"
#include "InitCloseSDL.h"
#include "externVariables.h"
#include "renderGame.h"
#include "Motion_Collision.h"

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
    //Load sound
    if( !loadSound() )
    {
        printf( "Failed to load music!\n" );
        return 0;
    }


    //Main loop flag
    bool quit = false;

    //Create Walls
    createWalls();
    createPoint();

    //Create Pacman & Ghost Animation & Point
    getPacmanAnimation();
    getGhostAnimation();

    //Play opening music
    RenderGame();
    Mix_PlayChannel(1, opening, 0);
    while(Mix_Playing(1) != 0)
    {
        SDL_Delay(200);
    }

    //Play theme music
    Mix_PlayMusic( theme, -1 );

    //Game loop
    while( !quit )
    {
        //Handle Events from keyboard
        handleEvent(quit);

        //Handle motion and collision
        Motion_Collision(quit);

        //Render Game
        RenderGame();

        if (quit == true)
        {
            isPlayAgain(quit);
        }
    }

	//Free resources and close SDL
	close();
	return 0;
}

