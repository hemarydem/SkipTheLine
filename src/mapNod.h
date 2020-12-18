#ifndef mapNod_h
#define mapNod_h
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


typedef struct  mape mape;
struct mape{
    char name[100];
    mape * next;
    mape * last;
};

map * creatMapeNode(char * mapName);
map * addMapeNode(mape * newMape, mape * firstNodeMape);
int suppMapeNode(mape * newMape, char * nameMapeToSupp,mape * firstNodeMape);
int freeALLNodeMap(mape * firstNodeMape);