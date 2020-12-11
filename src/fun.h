#ifndef fun_h
#define fun_h
#include <SDL.h>
#include<SDL_image.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#endif
//build
SDL_Texture * buildTextur(const char * imgPath, SDL_Renderer * renderer, SDL_Texture *texture);

char * buildStr(int size);

//init
SDL_Rect initPositionAndSize(SDL_Rect * rectContaineur, int * ladder, int * y, int * x);

//check
int freeAndQuitIfNull(int compare,const char * strErroMsg,SDL_Window * win, SDL_Renderer * renderer, SDL_Texture * tex);

//colistion
void dontCrosseBorder(float * velocity, float * position);

void dontCrosseBottomBorder(int HeightORwidht,int spriteHorW,float * velocity, float * position);
