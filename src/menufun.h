#ifndef menufun_h
#define menufun_h
#include <SDL.h>
#include <SDL_image.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "fun.h"
#endif

// return an SDL_Texture  ** array
SDL_Texture  *** initMenuArray();

char ** getMenuImagePath();

SDL_Texture  *** getTextureMenuArray(SDL_Texture *** arrayT,  SDL_Renderer * renderer);

SDL_Rect  ** initMenuRectArray();

void menuJoinTextureAndRect(SDL_Texture *** arrayT, SDL_Rect ** array, int *xPositionMenu, int *yStartingPositionMenu  ,int *gapBetweenLabel,int *ladderDimenssion);

void showMenu(SDL_Renderer * renderer, SDL_Texture *** arrayT, SDL_Rect **  arrayRect, int * cursor);
