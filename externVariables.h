#include "LTexture.h"
#include "pacman.h"
#include "ghost.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 888;
const int numbers_Wall = 54;
const int numberGhosts = 4;

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern LTexture sprites;
extern Pacman pacman;
extern Ghost ghost[];
extern SDL_Rect wall[];
