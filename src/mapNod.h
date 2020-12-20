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

firstMapNode * initList(firstMapNode * list, char * defaultMap);
firstMapNode * addMap(firstMapNode * list, char * mapName);
firstMapNode * supMap(firstMapNode * list, char * mapName);
firstMapNode * showMapList(firstMapNode * list);
map * getLastMapNode(firstMapNode * list);
firstMapNode * initMapListName(char ** mapList,  int mapsNum,firstMapNode * list);
#endif
