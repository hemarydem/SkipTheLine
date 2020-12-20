#ifndef mapNod_h
#define mapNod_h
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL.h>
struct map {
    char * name;
    struct map * next;
    struct map * last;
    SDL_Texture * selcetedBlue;
    SDL_Texture * unselcetedGreen;
};
typedef struct map map;
struct firstMapNode {
  struct  map *firstMap;
};
typedef struct  firstMapNode firstMapNode;

firstMapNode * initListMap(firstMapNode * list, char * defaultMap);
firstMapNode * addMap(firstMapNode * list, char * mapName);

#endif
