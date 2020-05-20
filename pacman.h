#ifndef PACMAN_H
#define PACMAN_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_ttf.h>
#include "ghost.h"

using namespace std;

class Pacman
{
    public:
		//The dimensions of Pacman
		static const int PACMAN_WIDTH  = 45;
		static const int PACMAN_HEIGHT = 45;

		//Maximum axis velocity of Pacman
		static const int PACMAN_VEL = 3;

		// Direct
		int direct = 0;

		//Lives
		int Lives = 3;

		//Check if Pacman eats cherry
		bool eatCherry = false;

		//Time eat cherry
		int timeEatCherry = 0;

		//Initializes the variables
		Pacman();

		//Check if pacman die
        bool isDead = false;

		//Reset pacman
		void reset();

		//Handle keyboard's events
		void handleEvent( SDL_Event& e );

		//Moves Pacman
        void move( SDL_Rect wall[], int numbers_Wall);

		//Shows Pacman on the screen
		void render();

		//Pacman's collision box
        SDL_Rect mCollider;

    private:
		//The X and Y offsets of Pacman
		int mPosX, mPosY;

		//The velocity of the Pacman
		int mVelX, mVelY;

    friend int Ghost::directChasing();
    friend void Ghost::handleEvent();
    friend int Ghost::directRunAway();
};

void getPacmanAnimation();

#endif // PACMAN_H
