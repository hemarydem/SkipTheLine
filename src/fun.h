#ifndef fun_h
#define fun_h
#include <SDL.h>
#include<SDL_image.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>


SDL_Texture * buildTextur(const char * imgPath, SDL_Renderer * renderer, SDL_Texture *texture);

//check
int freeAndQuitIfNull(int compare,const char * strErroMsg,SDL_Window * win, SDL_Renderer * renderer, SDL_Texture * tex);

//colistion
void dontCrosseBorder(float * velocity, float * position);

void dontCrosseBottomBorder(int HeightORwidht,int spriteHorW,float * velocity, float * position);

//build a string
char * buildStr(int size);

//divide by lader the size of the rec in arg position it by x and y must us SDL_QueryTexture before use it
SDL_Rect initPositionAndSize(SDL_Rect * rectContaineur, int * ladder, int * y, int * x);
#endif