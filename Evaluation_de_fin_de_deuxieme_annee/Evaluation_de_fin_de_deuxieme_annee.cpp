#include "generationPlateau.h"

int main(int argc, char* argv[]) {

    SDL_Window* window;                    // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        1920,                               // width, in pixels 
        1080,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );


    SDL_Renderer* renderer;

    renderer = SDL_CreateRenderer(window, -1, 0);

   SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);

   SDL_RenderClear(renderer);
    int x = 100;
    int y = 100;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0 + i; j < 8 + i; j++)
        {
            if ((j % 2 == 0))
            {
                generation_carre_plein(renderer, x, y, 100, 100, 255, 255, 255);
            }
            else
            {
                generation_carre_plein(renderer, x, y, 100, 100, 0, 0, 0);
            }
            x += 100;
        }
        x = 100;
        y += 100;

    }

     generation_carre_vide(renderer, 100, 100, 800, 800, 255, 0, 0);

   SDL_Surface* windowSurface = NULL;
   windowSurface = SDL_GetWindowSurface(window);

   if (TTF_Init() < 0)
   {
       printf("Impossible d'initialiser SDL_ttf : %s", TTF_GetError());
       return 1;
   }

   /* Charge une police depuis un fichier, avec une taille de point à 50 */
   TTF_Font* Font = TTF_OpenFont("assets/arial.ttf", 64);

   /* Si la police est nulle, il y a eu une erreur */
   if (!Font)
   {
       printf("Erreur de création de la police : %s", TTF_GetError());
       return 1;
   }

   /* Couleur du texte (ici rouge) */
   SDL_Color TextColor;
   TextColor.r = 255;
   TextColor.g = 0;
   TextColor.b = 0;

   /* On rend un texte sur une surface SDL, en utilisant notre police et notre couleur */
   SDL_Surface* TextSurface = TTF_RenderText_Solid(Font, "Salut tout le monde !", TextColor);

   /* Si la surface est nulle, il y a eu une erreur */
   if (!TextSurface)
   {
       printf("Erreur de rendu du texte : %s", TTF_GetError());
       return 1;
   }
   

   /* On peut maintenant blitter notre surface comme n'importe quelle autre */
   SDL_Rect DstRect;
   DstRect.x = 0;
   DstRect.y = 0;
   DstRect.w = TextSurface->w;
   DstRect.h = TextSurface->h;

   /* Affiche toute la surface en 0,0 */
   //SDL_BlitSurface(TextSurface, NULL, windowSurface, &DstRect);

   SDL_Texture * tex = SDL_CreateTextureFromSurface(renderer, TextSurface);
   SDL_RendererFlip  flip = SDL_FLIP_NONE;
   SDL_RenderCopyEx(renderer, tex, NULL, &DstRect, 0, 0, flip);
   SDL_RenderPresent(renderer);
   /* Libère notre surface et notre police */
   SDL_FreeSurface(TextSurface);
   TTF_CloseFont(Font);

   /* Fermeture de SDL_ttf */
   TTF_Quit();



   //ecriture_texte();

  //SDL_RenderCopy(renderer, texture, NULL, NULL);
    // The window is open: could enter program loop here (see SDL_PollEvent())

    SDL_Delay(3000);

   // SDL_DestroyRenderer(renderer);
    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}