#include "InitCloseSDL.h"
#include "externVariables.h"

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
        //Initialize SDL_mixer
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
            success = false;
        }

		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Pacman", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				//Initialize SDL_ttf
                if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                    success = false;
                }
			}
		}
	}
	return success;
}

bool loadMedia()
{
	//Loading success flag
    bool success = true;

    //Open the font
    gFont = TTF_OpenFont("Fonts/pixel2.ttf", 28);
    if (gFont == NULL) {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    }

    //Load texture pacman and ghosts
    if (!sprites.loadFromFile("Images/sprites2.png")) {
        printf("Failed to load sprites texture!\n");
        success = false;
    }
    //Load Background
    if (!background.loadFromFile("Images/background.jpg")) {
        printf("Failed to load background texture!\n");
        success = false;
	}
	//Load Game Over
	if (!gameOver.loadFromFile("Images/gameover.jpg"))
    {
        printf( "Failed to load background texture!\n" );
		success = false;
    }
	return success;
}

//The music that will be played
Mix_Music *theme = NULL;

//The sound effects that will be used
Mix_Chunk *die = NULL;
Mix_Chunk *eatghost = NULL;
Mix_Chunk *eatpoint = NULL;
Mix_Chunk *opening = NULL;
Mix_Chunk *pacmaneatcherry = NULL;

bool loadSound()
{
    //Loading success flag
    bool success = true;

    //Load music
    theme = Mix_LoadMUS( "Sounds/theme1.mp3" );
    if( theme == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    //Load sound effects
    opening = Mix_LoadWAV( "Sounds/opening.ogg" );
    if( opening == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    die = Mix_LoadWAV( "Sounds/die.ogg" );
    if( die == NULL )
    {
        printf( "Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    eatghost = Mix_LoadWAV( "Sounds/eatghost.ogg" );
    if( eatghost == NULL )
    {
        printf( "Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    eatpoint = Mix_LoadWAV( "Sounds/eatcherry.mp3" );
    if( eatpoint == NULL )
    {
        printf( "Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    pacmaneatcherry = Mix_LoadWAV("Sounds/ghosts-turn-to-blue.mp3");
    if( pacmaneatcherry == NULL )
    {
        printf( "Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    return success;
}

void close()
{
	//Free loaded images
	sprites.free();
    background.free();

    //Free global font
    TTF_CloseFont( gFont );
    gFont = NULL;

    //Free the music
    Mix_FreeMusic( theme );
    theme = NULL;

    //Free the sound effects
    Mix_FreeChunk(die);
    Mix_FreeChunk(eatghost);
    Mix_FreeChunk(eatpoint);
    Mix_FreeChunk(opening);
    Mix_FreeChunk(pacmaneatcherry);
    eatghost = NULL;
    eatpoint = NULL;
    opening = NULL;
    pacmaneatcherry = NULL;

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
    TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
