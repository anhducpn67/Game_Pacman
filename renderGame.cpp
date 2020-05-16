#include "renderGame.h"
#include "externVariables.h"

void RenderGame()
{
    //Clear screen
    SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 255 );
    SDL_RenderClear( gRenderer );

    //Render wall
    for (int i = 1; i <= numbers_Wall; i++)
        SDL_RenderDrawRect( gRenderer, &wall[i] );

    //Render background
    background.render(0, 0);

    //Render cherry
    for (int i = 1; i <= 4; i++)
    {
        if (cherryX[i] == -1 && cherryY[i] == -1)   continue;
        sprites.render(cherryX[i], cherryY[i], &cherry);
    }

    //Render points
    for (int rowi = 1; rowi <= nRow; rowi++)
    for (int coli = 1; coli <= nCol; coli++)
        if (!isEateanPoint[rowi][coli])
            sprites.render(pointX[rowi][coli], pointY[rowi][coli], &point);

    //Render Pacman
    pacman.render();

    //Render Ghosts
    for (int i = 1; i <= 4; i++)
        if (ghost[i].timeDeath == -1)
            ghost[i].render(i - 1);

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
