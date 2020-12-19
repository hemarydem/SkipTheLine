#ifndef mapNod_h
#define mapNod_h
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL.h>
struct map {
    char name[100];
    struct map * next;
    struct map * last;
    SDL_Texture * selcetedBlue;
    SDL_Texture * unselcetedGreen;
};
typedef struct map map;
struct firstMapNode{
  struct  map *firstMap;
};
typedef struct  firstMapNode firstMapNode;
firstMapNode * creatMapeNode(char * mapName);
#endif
/*map * addMapNode(map * newMap, map * firstNodeMap);
int suppMapNode(map * newMap, char * nameMapToSupp,map * firstNodeMap);
int freeALLNodeMap(map * firstNodeMap);
void initNodeMaps(char** maps, map * firstNodeMap);*/
