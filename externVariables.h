#include "LTexture.h"
#include "pacman.h"
#include "ghost.h"
#include <SDL_mixer.h>

//Screen dimension constants
const int SCREEN_WIDTH = 1100;
const int SCREEN_HEIGHT = 888;
const int NUMBER_WALLS = 54;
const int NUMBER_GHOSTS = 4;
const int NUMBER_COL = 25;
const int NUMBER_ROW = 20;
const int CHASING_TIME = 6;
const int TIRED_TIME = 3;
const double PROB_CHANGE_DIRECTION = 0.2;

//Direct
const int Right = 0;
const int Down = 1;
const int Left = 2;
const int Up = 3;

extern LTexture background;
extern SDL_Window *gWindow;
extern SDL_Renderer *gRenderer;
extern LTexture sprites;
extern Pacman pacman;
extern Ghost ghosts[];
extern SDL_Rect walls[];
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
extern Mix_Music *theme;
extern Mix_Chunk *die;
extern Mix_Chunk *eatghost;
extern Mix_Chunk *eatpoint;
extern Mix_Chunk *opening;
extern Mix_Chunk *pacmaneatcherry;
extern LTexture gameOver;
