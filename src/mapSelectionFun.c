#include <SDL.h>
#include <SDL_image.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<SDL_ttf.h>
#include "fun.h"
#include "menufun.h"
#include "mapSelectionFun.h"
#include "writeFun.h"

int numOfMaps(char* str) {
  int count;
  int i = 0;
  printf("stre  = %s", str);
  while(i < strlen(str)) {
    if(str[i] == '|') count++;
    i++;
  }
  printf("nombre de map = %d\n", count);
  return count;
}

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

char ** buildArrayMaplist(char * str,int numOfLine) {
  char ** array = NULL;
  int i;
  array = malloc(sizeof(char*) * numOfLine);
  if(array != NULL) {
    for (i = 0; i < 10; i++) {
      array[i] = malloc(sizeof(char) * 100);// bloquer le nom des maps a 100 char
      if (array[i] == NULL) {
        int j = 0;
        while (j < i) {
          free(array[i]);
          j++;
        }
        free(array);
        printf("error malloc\n etMenuImagePath\n");
        return array= NULL;
      }
    }
    return array;
  }
  printf("\n error \n getMenuImagePath \n");
  return array = NULL;
}
char ** joinMapListandDataList(char ** mapsList, char * fileData, int numOfMaps) {
 int i = 0;
 char returnChar = '\0';
 char *sPtr = fileData;//start ptr
 char *ePtr = fileData;//end ptr
  while (i < numOfMaps) {
   while (*ePtr != '|')
      ePtr++;
    *ePtr = returnChar;
    printf("sPtr = %s", sPtr);
    strcpy(mapsList[i], sPtr);
    ePtr++;
    sPtr = ePtr;
    i++;
  }
  return mapsList;
}


char ** getMapList(const char* fileName) {
  char * fileData;// takke data from file
  char ** mapsList;/// will receive the final array
  FILE *fp;
  long size = getSize(fileName);// size of the file
  int sFfg;//sizeForfegets
  int mapNumber;
  if(size  == -1) { 
    printf("\n error file %s is empty", fileName);
    mapsList = NULL;
    return mapsList;
  }
  fp = fopen(fileName, "rb"); // read mode
  if (fp == NULL) {
    perror("Error opening the file.\n");
    mapsList = NULL;
    return mapsList;
  }
  sFfg = (int) size;
  fileData = malloc(sizeof(char) * sFfg + 1);
  fread(fileData, sizeof(char), sFfg, fp );
  mapNumber = numOfMaps(fileData);
  fileData[sFfg] = '\0';
  printf("The contents of %s file are:\n", fileName);
  printf("%d\n", sFfg);
  mapsList = buildArrayMaplist(fileData,mapNumber);
  mapsList = joinMapListandDataList( mapsList, fileData, mapNumber);
  fclose(fp);
  free(fileData);
  return mapsList;
}
/*i  =0;
   while(i < sFfg){
    if(mapsList[i] != '|'){
        printf("%c", mapsList[i]);
    } else {
      printf("\n");
    }
    i++;
  }*/