#include "generationPlateau.h"
#include "Gestion_jeu.h"
int x = 0;
int y = 0;

int main(int argc, char* argv[]) {



    typedef struct 
    {
       const char* couleur;
       const char* colonne;
       const  char* ligne;
    } CASE ;

   char taille = taille_echiquier();
   // char* const ptr_taille = &taille;
    CASE Tab_case[64];

    const char* tab_char[] = { "A","B","C","D","E","F","G","H","I","J"};
    const char* tab_int[] = { "1","2","3","4","5","6","7","8","9","10"};

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

    
    //printf("%d\n", taille_echiquier());

    SDL_Renderer* renderer;

    renderer = SDL_CreateRenderer(window, -1, 0);

   SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);

   SDL_RenderClear(renderer);
    int x = 100;
    int y = 100;
    int lgr_tabcase = 0;
    FILE* fp;
    fp = fopen("stock.txt", "a");
    for (int i = 0; i < taille; i++)
    {
        for (int j = 0 + i ; j < taille + i; j++)
        {
            if ((j % 2 == 0))
            {

                Tab_case[lgr_tabcase].couleur = (char*)malloc(5);
                Tab_case[lgr_tabcase].couleur = "noir";
                Tab_case[lgr_tabcase].colonne = (char*)malloc(1);
                Tab_case[lgr_tabcase].colonne = tab_char[j-i];
                Tab_case[lgr_tabcase].ligne = (char*)malloc(5);
                Tab_case[lgr_tabcase].ligne = tab_int[7 - i];

                fprintf(fp, "[%s, %s, %s]", Tab_case[lgr_tabcase].couleur, Tab_case[lgr_tabcase].colonne, Tab_case[lgr_tabcase].ligne);
                printf("[%s, %s, %s]", Tab_case[lgr_tabcase].couleur, Tab_case[lgr_tabcase].colonne, Tab_case[lgr_tabcase].ligne);

                generation_carre_plein(renderer, x, y, 100, 100, 255, 255, 255);


            }
            else
            {
                Tab_case[lgr_tabcase].couleur = (char*)malloc(5);
                Tab_case[lgr_tabcase].couleur = "blanc";
                Tab_case[lgr_tabcase].colonne = (char*)malloc(1);
                Tab_case[lgr_tabcase].colonne = tab_char[j-i];
                Tab_case[lgr_tabcase].ligne = (char*)malloc(5);
                Tab_case[lgr_tabcase].ligne = tab_int[7-i];

                fprintf(fp, "[%s, %s, %s]", Tab_case[lgr_tabcase].couleur, Tab_case[lgr_tabcase].colonne, Tab_case[lgr_tabcase].ligne);
                printf("[%s, %s, %s]", Tab_case[lgr_tabcase].couleur, Tab_case[lgr_tabcase].colonne, Tab_case[lgr_tabcase].ligne);


                generation_carre_plein(renderer, x, y, 100, 100, 0, 0, 0);
            }
            lgr_tabcase++;
            x += 100;
        }
        fprintf(fp, "\n");
        x = 100;
        y += 100;
    }

    generation_carre_vide(renderer, 100, 100, taille *100,  taille * 100, 255, 0, 0);
    
    x = 25;
    y = taille * 100 + 100;

    // boucle for pour ajouter les lettres de A a H en bas de l'échquier
    for (int i = 0; i < taille; i++)
    {
        if (TTF_Init() < 0)
        {
            printf("Impossible d'initialiser SDL_ttf : %s", TTF_GetError());
            return 1;
        }
         x += 100;
         ecriture_texte(window, renderer, x, y, tab_char[i]);

    }

   
    x = 50;
    y = taille*100 + 115;

    // boucle for pour ajouter 1 a 8 a gauche de l'echiquier
    for (int i = 0; i < taille; i++)
    {
        if (TTF_Init() < 0)
        {
            printf("Impossible d'initialiser SDL_ttf : %s", TTF_GetError());
            return 1;
        }
        y -= 100;
        ecriture_texte(window, renderer, x, y, tab_int[i]);

    }


   
    //ecriture_texte(window, renderer);

    SDL_RenderPresent(renderer);

    SDL_Delay(3000);

   // SDL_DestroyRenderer(renderer);
    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}

