
#include "mapNod.h"

firstMapNode * initListMap(firstMapNode * list, char * defaultMap) {
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
    m = malloc(sizeof(m));
    m->name = malloc(sizeof(char) * 100);
    strcpy(m->name, mapName);
    ptr = list->firstMap;
    while (ptr->next != NULL) {
        ptr->next = ptr->next;
        printf("\nhello\n");
    }
    ptr->next = m;
    return list;
}