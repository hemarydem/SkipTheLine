#ifndef mapSelectionFun_h
#define mapSelectionFun_h
#include <SDL.h>
#include <SDL_image.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<SDL_ttf.h>
#include "fun.h"
#include "menufun.h"
#include "mapSelectionFun.h"
#include "writeFun.h"
#endif

int numOfMaps(char* str);

long getSize(const char * filename);

char ** buildArrayMaplist(char * str,int numOfLine);

char ** joinMapListandDataList(char ** mapsList, char * fileData, int numOfMaps);

char ** getMapList(const char* fileName);