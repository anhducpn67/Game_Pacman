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

    //Render Pacman
    pacman.render();

    // Render Ghost
    for (int i = 1; i <= 4; i++)
        ghost[i].render(i - 1);

}
