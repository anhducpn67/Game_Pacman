#ifndef INITCLOSESDL_H
#define INITCLOSESDL_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_ttf.h>

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

#endif // INITCLOSESDL_H
