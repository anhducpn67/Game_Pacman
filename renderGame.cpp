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

    //Render points
    for (int rowi = 1; rowi <= nRow; rowi++)
    for (int coli = 1; coli <= nCol; coli++)
        if (!isEateanPoint[rowi][coli])
            sprites.render(pointX[rowi][coli], pointY[rowi][coli], &point);

    //Render Pacman
    pacman.render();

    //Render Ghosts
    for (int i = 1; i <= 4; i++)
        ghost[i].render(i - 1);

    //Update screen
    SDL_RenderPresent( gRenderer );
}
