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



void ecriture_texte(SDL_Window * window, SDL_Renderer* renderer, int x, int y, const char* texte)
{
    SDL_Surface* windowSurface = NULL;
    windowSurface = SDL_GetWindowSurface(window);



    /* Charge une police depuis un fichier, avec une taille de point à 50 */
    TTF_Font* Font = TTF_OpenFont("assets/arial.ttf", 64);

    /* Si la police est nulle, il y a eu une erreur */
    /*if (!Font)
    {
        printf("Erreur de création de la police : %s", TTF_GetError());
        return 1;
    }*/

    /* Couleur du texte (ici rouge) */
    SDL_Color TextColor;
    TextColor.r = 0;
    TextColor.g = 0;
    TextColor.b = 255;

    /* On rend un texte sur une surface SDL, en utilisant notre police et notre couleur */
    SDL_Surface* TextSurface = TTF_RenderText_Solid(Font, texte, TextColor);

    /* Si la surface est nulle, il y a eu une erreur */
  /*if (!TextSurface)
    {
        printf("Erreur de rendu du texte : %s", TTF_GetError());
        return 1;
    }*/


    /* On peut maintenant blitter notre surface comme n'importe quelle autre */
    SDL_Rect DstRect;
    DstRect.x = x;
    DstRect.y = y;
    DstRect.w = TextSurface->w;
    DstRect.h = TextSurface->h;

    /* Affiche toute la surface en 0,0 */
    //SDL_BlitSurface(TextSurface, NULL, windowSurface, &DstRect);

    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, TextSurface);
    SDL_RendererFlip  flip = SDL_FLIP_NONE;
    SDL_RenderCopyEx(renderer, tex, NULL, &DstRect, 0, 0, flip);

    /* Libère notre surface et notre police */
    SDL_FreeSurface(TextSurface);

    TTF_CloseFont(Font);

    /* Fermeture de SDL_ttf */
    TTF_Quit();
}