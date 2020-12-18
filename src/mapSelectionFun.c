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

long getSize(const char * filename) {
    FILE *f = fopen(filename, "ab");
    if(f != NULL) {
        long size;
        fseek(f, 0, SEEK_END);
        size = ftell(f);
        printf("\n size   = %ld\n", size);
        fclose(f);
        return size;
    }
    return -1;
}//fstat();
int getMapList(const char* fileName) {
  char * mapsList;
  FILE *fp;
  long size = getSize(fileName);
  int i, sFfg;//sizeForfegets
  if(size  == -1){ 
    printf("\n error file %s is empty", fileName);
    return (int) size;
  }
  fp = fopen(fileName, "rb"); // read mode
  if (fp == NULL) {
    perror("Error opening the file.\n");
    return 0;
  }
  sFfg = (int) size;
  mapsList = malloc(sizeof(char) * sFfg + 1);
  fread(mapsList, sizeof(char), sFfg, fp );
  mapsList[sFfg] = '\0';
  printf("The contents of %s file are:\n", fileName);
  printf("%d\n", sFfg);
  i  =0;
   while(i < sFfg){
    if(mapsList[i] != '|'){
        printf("%c", mapsList[i]);
    } else {
      printf("\n");
    }
    i++;
  }
  printf("%s", mapsList);
  fclose(fp);
  free(mapsList);
  return 0;
}
