#ifndef writeFun_h
#define writeFun_h
#include <SDL.h>
#include <SDL_image.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "fun.h"
#include "menufun.h"
#endif
SDL_Texture  *** getTextureMenuArrayByttf(SDL_Texture *** arrayT,  SDL_Renderer * renderer);
SDL_Texture * renderText(const char * message, const char* fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer);
SDL_Color * colorSet(SDL_Color * c, int red,int green,int blue);
char ** getMenuWords();