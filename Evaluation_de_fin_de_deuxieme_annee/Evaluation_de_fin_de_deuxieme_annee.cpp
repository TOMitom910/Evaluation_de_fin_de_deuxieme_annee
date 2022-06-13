#include "SDL.h"
#include "SDL_ttf.h"
#include <stdio.h>
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
        for (int j = 0 + i; j < 8+i; j++)
        {
            if ((j % 2 == 0) )
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

    ecriture_texte();
    // Up until now everything was drawn behind the scenes.
    // This will show the new, red contents of the window.
    
    SDL_RenderPresent(renderer);

    // The window is open: could enter program loop here (see SDL_PollEvent())
 

    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}