
#include <SDL.h>
#include <SDL_image.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include<SDL_ttf.h>
#include "fun.h"
#include "menufun.h"
#include "mapSelectionFun.h"
#include "writeFun.h"

int getMapList(const char* fileName) {
  char ch;
  FILE *fp;
  fp = fopen(fileName, "r"); // read mode
  if (fp == NULL) {
    perror("Error opening the file.\n");
    return 0;
  }

  printf("The contents of %s file are:\n", fileName);

  while((fgets(&ch, 1,fp)), !feof(fp)){
    if(ch  != '|'){
        printf("%c", ch);
    } else {
      printf("\n");
    }
  }

  fclose(fp);
  return 0;
}
