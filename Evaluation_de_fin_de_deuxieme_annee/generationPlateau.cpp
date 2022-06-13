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



/*void ecriture_texte()
{
    SDL_Surface* ecran = NULL, * texte = NULL;

    void SDL_WM_SetCaption(const char* title, const char* icon);

    int SDL_Flip(SDL_Surface * screen);

    SDL_Surface* SDL_SetVideoMode(int width, int height, int bpp, Uint32 flags);

    SDL_Rect position;
    SDL_Event event;
    TTF_Font* police = NULL;
    SDL_Color couleurNoire = { 0, 0, 0 };
    int continuer = 1;
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    ecran = SDL_SetVideoMode(640, 480, 32, "SDL_HWSURFACE"  || "SDL_DOUBLEBUF");
    SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);
    //Chargement de la police
    police = TTF_OpenFont("assets/arial.ttf", 36);
    //Ecriture du texte dans la SDL_Surface "texte" en mode Blended (optimal)
    texte = TTF_RenderText_Blended(police, "Salut les Zér0s !", couleurNoire);
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        }
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        position.x = 60;
        position.y = 370;
        SDL_BlitSurface(texte, NULL, ecran, &position); //Blit du texte par-dessus 
        SDL_Flip(ecran);
    }
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(texte);
    SDL_Quit();
}*/