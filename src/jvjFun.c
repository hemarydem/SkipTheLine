#include <SDL.h>
#include <SDL_image.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "fun.h"
#include "menufun.h"

SDL_Texture  *** initJvjArray();

char ** getJvjmagePath();

SDL_Texture  *** getTextureJvJArray(SDL_Texture *** arrayT,  SDL_Renderer * renderer);

SDL_Rect  ** initJvjRectArray();
