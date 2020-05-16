#include "LTexture.h"
#include "pacman.h"
#include "ghost.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1100;
const int SCREEN_HEIGHT = 888;
const int numbers_Wall = 54;
const int numberGhosts = 4;
const int nCol = 25;
const int nRow = 20;

//Direct
const int Right = 0;
const int Down = 1;
const int Left = 2;
const int Up = 3;

extern LTexture background;
extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern LTexture sprites;
extern Pacman pacman;
extern Ghost ghost[];
extern SDL_Rect wall[];
extern int frames;
extern SDL_Rect point;
extern SDL_Rect cherry;
extern int pointX[30][30];
extern int pointY[30][30];
extern int Score;
extern bool isEateanPoint[30][30];
extern int cherryX[5];
extern int cherryY[5];
extern TTF_Font *gFont;
extern LTexture Text;
