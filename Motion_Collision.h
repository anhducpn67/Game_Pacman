#ifndef MOTION_COLLISION_H
#define MOTION_COLLISION_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_ttf.h>

void Motion_Collision(bool& quit);
bool checkCollision( SDL_Rect& a, SDL_Rect& b );
void handleEvent(bool& quit);

#endif // MOTION_COLLISION_H
