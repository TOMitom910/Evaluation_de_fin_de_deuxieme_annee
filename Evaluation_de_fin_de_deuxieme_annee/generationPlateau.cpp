#include "generationPlateau.h"


void generation_carre_plein(SDL_Renderer* renderer, int x, int y, int w, int h, int r, int g, int b)
{

    SDL_Rect rect;
    // select the position and the dimension of the rect
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    // Select the color for drawing.
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);             

    //Fill the rect on the renderer
    SDL_RenderFillRect(renderer, &rect);                         
}

void generation_carre_vide(SDL_Renderer* renderer, int x, int y, int w, int h, int r, int g, int b)
{

    SDL_Rect rect;
    // select the position and the dimension of the rect
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    // Select the color for drawing.
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    //Draw the rect on the renderer
    SDL_RenderDrawRect(renderer, &rect);
}

void ecriture_texte()
{
}