#include "menufun.h"
// création of variables perror voir errno variabel qui revoir l'Error -> revoit un text dans la console
SDL_Texture  *** initMenuArray() {
  SDL_Texture *** array;
  int i;
  array = malloc(sizeof(SDL_Texture**) * 10);
  if(array != NULL) {
    for (i = 0; i < 10; i++) {
        array[i] = malloc(sizeof(SDL_Texture*));
        if (array[i] == NULL) {
          int j = 0;
          while (j < i) {
            free(array[i]);
            j++;
          }
          free(array);
          printf("error malloc\n initMenuArray\n");
          return array;
        }
    }
    return array;
  }
  printf("\n initMenuTextureArray \n");
  return array;
}

//path for menu texture
char ** getMenuImagePath(){
  char ** array = NULL;
  int i;
  array = malloc(sizeof(char*) * 10);
  if(array != NULL){
    for (i = 0; i < 10; i++) {
        array[i] = malloc(sizeof(char) * 100);
        if (array[i] == NULL) {
          int j = 0;
          while (j < i) {
            free(array[i]);
            j++;
          }
          free(array);
          printf("error malloc\n etMenuImagePath\n");
          return array;
        }
    }
    strcpy(array[0], "img/menuImg/selected/jvj.png");
    strcpy(array[1], "img/menuImg/unselected/jvj.png");
    strcpy(array[2], "img/menuImg/selected/online.png");
    strcpy(array[3], "img/menuImg/unselected/online.png");
    strcpy(array[4], "img/menuImg/selected/option.png");
    strcpy(array[5], "img/menuImg/unselected/option.png");
    strcpy(array[6], "img/menuImg/selected/editor.png");
    strcpy(array[7], "img/menuImg/unselected/editor.png");
    strcpy(array[8], "img/menuImg/selected/quite.png");
    strcpy(array[9], "img/menuImg/unselected/quite.png");
    return array;
  }
  printf("\n error \n getMenuImagePath \n");
  return array;
}

//creat inithe texture
SDL_Texture  *** getTextureMenuArray(SDL_Texture *** arrayT,  SDL_Renderer * renderer){
  int i;
  char ** arrayTexturePath = getMenuImagePath();
  for (i = 0; i < 10; i+=2) {
    *arrayT[i] = buildTextur(arrayTexturePath[i], renderer, *arrayT[i]);
    if( arrayT[i] == NULL) printf(" error\n image -> %s", arrayTexturePath[i]);
    *arrayT[i + 1] = buildTextur(arrayTexturePath[i+1], renderer, *arrayT[i + 1]);
    if( arrayT[i + i] == NULL) printf(" error\n image -> %s", arrayTexturePath[i + 1]);
  }
  for (i = 0; i < 10; i++)
    free(arrayTexturePath[i]);
  free(arrayTexturePath);
  return arrayT;
}

SDL_Rect  ** initMenuRectArray() {
  SDL_Rect ** array;
  array = malloc(sizeof(SDL_Rect*) * 10);
  if(array != NULL){
    for (int i = 0; i < 10; i++) {
      array[i] =  malloc(sizeof(SDL_Rect));
      if (array[i] == NULL) {
        int j = 0;
        while (j < i) {
          free(array[i]);
          j++;
        }
        free(array);
        printf("error malloc\n initMenuRectArray\n");
        return array;
      }
    }
    return array;
  }
  printf("\n initMenuTextureArray \n");
  return array;
}

void menuJoinTextureAndRect(SDL_Texture *** arrayT, SDL_Rect ** array, int * xPositionMenu, int * yStartingPositionMenu  ,int * gapBetweenLabel,int * ladderDimenssion) {
  int i;
  for (i = 0; i < 10; i+=2) {
    SDL_QueryTexture(*arrayT[i],NULL,NULL, &array[i]->w, &array[i]->h);
    SDL_QueryTexture(*arrayT[i + 1],NULL,NULL, &array[i + 1]->w, &array[i + 1]->h);
    initPositionAndSize(array[i] ,ladderDimenssion,yStartingPositionMenu,xPositionMenu);
    initPositionAndSize(array[i + 1] ,ladderDimenssion,yStartingPositionMenu,xPositionMenu);
    *yStartingPositionMenu += *gapBetweenLabel;
  }
}

void showMenu(SDL_Renderer * renderer, SDL_Texture *** arrayT, SDL_Rect ** arrayRect, int * cursor) {
  printf("%d\n", *cursor);
  if (*cursor == 1) {
    SDL_RenderCopy(renderer, *arrayT[0], NULL, arrayRect[0]);
  } else {
    SDL_RenderCopy(renderer, *arrayT[1], NULL, arrayRect[1]);
  }
  if (*cursor == 2) {
    SDL_RenderCopy(renderer, *arrayT[2], NULL, arrayRect[2]);
  } else {
    SDL_RenderCopy(renderer, *arrayT[3], NULL, arrayRect[3]);
  }
  if (*cursor == 3) {
    SDL_RenderCopy(renderer, *arrayT[4], NULL, arrayRect[4]);
  } else {
    SDL_RenderCopy(renderer, *arrayT[5], NULL, arrayRect[5]);
  }
  if (*cursor == 4) {
    SDL_RenderCopy(renderer, *arrayT[6], NULL, arrayRect[6]);
  } else {
    SDL_RenderCopy(renderer, *arrayT[7], NULL, arrayRect[7]);
  }
  if (*cursor == 5) {
    SDL_RenderCopy(renderer, *arrayT[8], NULL, arrayRect[8]);
  } else {
     SDL_RenderCopy(renderer, *arrayT[9], NULL, arrayRect[9]);
  }
}
