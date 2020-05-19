#ifndef GHOST_H
#define GHOST_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_ttf.h>

class Ghost
{
    public:
		//The dimensions of the Ghost
		static const int GHOST_WIDTH = 43;
		static const int GHOST_HEIGHT = 43;

		//Maximum axis velocity of the Ghost
		static const int GHOST_VEL = 3;

		// Direct
		int direct = 0;

		// Check if ghost is blocked;
		bool isBlock = false;

		//Reset ghost
		void resetGhost();

		//Time death
		int timeDeath = -1;

		//Initializes the variables
		Ghost();

		//Takes key presses and adjusts the Ghost's velocity
		void handleEvent();

		//Moves the Ghost
        void move( SDL_Rect wall[], int numbers_Wall);

		//Shows the Ghost on the screen
		void render(int ghosti);

		//Ghost's collision box
        SDL_Rect mCollider;

    private:
		//The X and Y offsets of the Ghost
		int mPosX, mPosY;

		//The velocity of the Ghost
		int mVelX, mVelY;
};

void getGhostAnimation();

#endif // GHOST_H
