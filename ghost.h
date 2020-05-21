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
    static const int GHOST_WIDTH = 45;
    static const int GHOST_HEIGHT = 45;

    //Maximum axis velocity of the Ghost
    static const int GHOST_VEL = 3;

    // Direct
    int direct = 0;

    // Check if ghosts is blocked;
    bool isBlock = false;

    // tiredness of chasing the freaking pacman
    bool isTired = false;

    // is chasing pacman
    bool isChasing = false;

    // time start chasing pacman
    time_t startChasingTime = 0;

    // time to recover
    time_t startTiredTime = 0;

    //Reset ghosts
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

        // Direct for chasing pacman
        int directChasing();

        // Direct for run away
        int directRunAway();

    private:
		//The X and Y offsets of the Ghost
		int mPosX, mPosY;

		//The velocity of the Ghost
		int mVelX, mVelY;
};

void getGhostAnimation();

#endif // GHOST_H
