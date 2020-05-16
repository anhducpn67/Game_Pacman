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
    //Main loop flag
    bool quit = false;

    //Create Walls
    createWalls();
    createPoint();

    //Create Pacman & Ghost Animation & Point
    getPacmanAnimation();
    getGhostAnimation();

    //Game loop
    while( !quit )
    {
        //Handle Events from keyboard
        handleEvent(quit);

        //Handle motion and collision
        Motion_Collision(quit);

        //Render Game
        RenderGame();

        // End game
        if (quit == true)
        {

        }
    }
	//Free resources and close SDL
	close();
	return 0;
}

