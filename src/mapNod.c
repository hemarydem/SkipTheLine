
#include "mapNod.h"

firstMapNode * initList(firstMapNode * list, char * defaultMap) {
    map * m;
    m = malloc(sizeof(m));
    list->firstMap = m;
    m->name = malloc(sizeof(char) * 100);
    m->next = NULL;
    m->last = NULL;
    strcpy(m->name, defaultMap);
    return list;
}

firstMapNode * addMap(firstMapNode * list, char * mapName) {
    map * m;
    map * ptr;
    int i = 1;
    m = malloc(sizeof(m));                   //creat map
    m->name = malloc(sizeof(char) * 100);
    m->next = NULL;
    m->last = NULL;
    strcpy(m->name, mapName);
    ptr = list->firstMap;
    while (ptr->next != NULL) {             //loop to the end of the chain
        ptr = ptr->next;
        printf("\nhello\n");
    }
    ptr->next = m;                          //link new map at the and of the chain
    m->last = ptr;                          
    return list;
}

firstMapNode * supMap(firstMapNode * list, char * mapName) {
    map * ptr;
    ptr = list->firstMap;
    while (strcmp(ptr->name, mapName) != 0) {
        ptr = ptr->next;
    }
    ptr->last->next = ptr->next;
    ptr->next->last = ptr->last->next;
    free(ptr->name);
    free(ptr);
    return list;
}

firstMapNode * showMapList(firstMapNode * list) {
    map * ptr;
    ptr = list->firstMap;
    while (ptr->next != NULL) {             //loop to the end of the chain
        ptr = ptr->next;
        printf("\n%s\n", ptr->name);
    }
    return list;
}

map * getLastMapNode(firstMapNode * list) {
    map * ptr;
    ptr = list->firstMap->next;
    while (ptr->next != NULL) {             //loop to the end of the chain
        ptr = ptr->next;
    }
    return ptr;
}

firstMapNode * initMapListName(char ** mapList,  int mapsNum, firstMapNode * list) { // A optimiser pour ne pas remonter tout le temps la colone de donné
    for (int i = 0; i < mapsNum; i++) {
        list = addMap(list,mapList[i]);
    }
    return list;
}