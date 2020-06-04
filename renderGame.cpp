#include "renderGame.h"
#include "externVariables.h"
#include "creatWallandPoint.h"

void RenderGame()
{

    //Clear screen
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    SDL_RenderClear(gRenderer);

    //Render walls
    for (int i = 1; i <= NUMBER_WALLS; i++)
        SDL_RenderDrawRect(gRenderer, &walls[i]);

    //Render background
    background.render(0, 0);

    //Render cherry
    for (int i = 1; i <= 4; i++) {
        if (cherryX[i] == -1 && cherryY[i] == -1) continue;
        sprites.render(cherryX[i], cherryY[i], &cherry);
    }

    //Render points
    for (int rowi = 1; rowi <= NUMBER_ROW; rowi++)
        for (int coli = 1; coli <= NUMBER_COL; coli++)
            if (!isEateanPoint[rowi][coli])
                sprites.render(pointX[rowi][coli], pointY[rowi][coli], &point);

    //Render Pacman
    pacman.render();

    //Render Ghosts
    for (int i = 1; i <= 4; i++)
        if (ghosts[i].timeDeath == -1)
            ghosts[i].render(i - 1);

    //Score
    SDL_Color textColor = { 255, 255, 255 };
    Text.loadFromRenderedText("HIGH SCORE", textColor);
    Text.render(810, 30);
    Text.loadFromRenderedText(to_string(Score), textColor);
    Text.render(900, 90);

    //Lives
    Text.loadFromRenderedText("LIVES", textColor);
    Text.render(870, 300);
    Text.loadFromRenderedText(to_string(pacman.Lives), textColor);
    Text.render(920, 350);

    //Update screen
    SDL_RenderPresent( gRenderer );
}

void resetEverything()
{
    //Create Walls
    createWalls();
    createPoint();

    //Create Pacman & Ghost Animation & Point
    getPacmanAnimation();
    getGhostAnimation();

    //Reset frames and score
    frames = 0;
    Score = 0;

    //Reset ghosts and pacman
    pacman.reset();
    pacman.direct = 0;
    pacman.Lives = 3;
    pacman.eatCherry = false;
    pacman.timeEatCherry = 0;

    for (int i = 1; i <= NUMBER_GHOSTS; i++)
        ghosts[i].resetGhost();

    //Play opening music
    RenderGame();
    Mix_PlayChannel(1, opening, 0);

    while (Mix_Playing(1) != 0) {
        SDL_Delay(200);
    }

    //Play theme music
    Mix_PlayMusic( theme, -1 );
}

void isPlayAgain(bool& quit)
{
    SDL_Event e;
    while(true)
    {
        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_KEYDOWN)
            {
                switch( e.key.keysym.sym )
                {
                    case SDLK_y:
                    {
                        quit = false;
                        resetEverything();
                        return;
                    }
                    case SDLK_n:
                    {
                        return;
                    }
                }
            }
        }
        SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 255 );
        SDL_RenderClear( gRenderer );
        gameOver.render(0, 0);
        SDL_Color textColor = { 255, 255, 255 };
        Text.loadFromRenderedText("Press Y to play again!", textColor);
        Text.render(250, 620);
        Text.loadFromRenderedText("Press N to exit game!", textColor);
        Text.render(250, 700);
        SDL_RenderPresent( gRenderer );
    }
}
