#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void generation_carre_plein(SDL_Renderer *renderer, int x, int y, int w, int h, int r, int g, int b);

void generation_carre_vide(SDL_Renderer* renderer, int x, int y, int w, int h, int r, int g, int b);

void ecriture_texte(SDL_Window* window, SDL_Renderer* renderer, int x, int y, const char * texte);