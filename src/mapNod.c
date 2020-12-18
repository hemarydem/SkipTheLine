#include "mapNod.h"
#include<string.h>
#include<stdbool.h>

map * creatMapeNode(char * mapName){
    printf("\ncreatMapeNode is running\n");
    mape * m = malloc(sizeof(mape));
    m->next = NULL;
    m->last = NULL;
    strcpy(m->name,mapName);
    return m;
}

map * addMapeNode(mape * newMape, mape * firstNodeMape) {// muste the firstNodeMape in param
    printf("\naddMapeNode is running\n");
    int i = true;
    mape * ptr;
    ptr = firstNodeMape;
    while (i) {
        if (ptr->next == NULL) {
            ptr->next = newMape;
            i = false;
        } else {
            ptr = ptr->next;
        }
    }
    return newMape;
}

int suppMapeNode(mape * newMape, char * nameMapeToSupp,mape * firstNodeMape) {// muste the firstNodeMape in param
    printf("\nsuppMapeNode is running\n");
    int i = true;
    mape * ptr;
    mape * SafePtr;
    ptr = firstNodeMape;
    SafePtr = firstNodeMape;
    while (i) {
        if (strcmp(ptr->name, nameMapeToSupp) == 0) {
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

int freeALLNodeMap(mape * firstNodeMape) {// muste the firstNodeMape in param
    int i = true;
    mape * ptr;
    ptr = firstNodeMape;
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