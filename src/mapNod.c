
#include "mapNod.h"



firstMapNode * creatMapeNode(char * mapName) {
    printf("\ncreatMapeNode is running\n");
    firstMapNode  * fmNode = malloc(sizeof(firstMapNode*));
    map * m = malloc(sizeof(map*));
    if(m == NULL || fmNode == NULL) {
        exit(EXIT_FAILURE);
    }
    m->next = NULL;
    m->last = NULL;
    strcpy(m->name,mapName);
    return fmNode;
}
/*
map * addMapeNode(map * newMap, map * firstNodeMap) {// muste the firstNodeMape in param
    printf("\naddMapNode is running\n");
    bool i = true;
    map * ptr;
    ptr = firstNodeMap;
    while (i) {
        if (ptr->next == NULL) {
            ptr->next = newMap;
            i = false;
        } else {
            ptr = ptr->next;
        }
    }
    return newMap;
}

int suppMapNode(map * newMap, char * nameMapToSupp,map * firstNodeMap) {// muste the firstNodeMape in param
    printf("\nsuppMapNode is running\n");
    bool i = true;
    map * ptr;
    map * SafePtr;
    ptr = firstNodeMap;
    SafePtr = firstNodeMap;
    while (i) {
        if (strcmp(ptr->name, nameMapToSupp) == 0) {
            ptr->last->next = ptr->next;//the node last ptr take in his next next of ptr
            ptr->next->last = ptr->last;//the node next ptr take in his last last of ptr
            free(ptr);
            i = false;
        } else {
            ptr = ptr->next;
        }
    }
    return 1;
}

int freeALLNodeMap(map * firstNodeMap) {// muste the firstNodeMape in param
    bool i = true;
    map * ptr;
    ptr = firstNodeMap;
    while (i) {
        if (ptr->next == NULL) {
            free(ptr);
            i = false;
        } else {
            ptr = ptr->next;
            free(ptr->last);
        }
    }
    return 1;
}

void initNodeMaps(char** maps, map * firstNodeMap) {
    int i = 0;
    map * ptr;
    ptr = firstNodeMap;
    while (i) {
        if (ptr->next == NULL) {
            strcpy(ptr->name,maps[i]);
            break;
        } else {
            strcpy(ptr->name,maps[i]);
            ptr = ptr->next;
        }
        i++;
    }
}*/