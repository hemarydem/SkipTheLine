
//gcc src/*.c -o bin/toto.app $(sdl2-config --cflags --libs) -lSDL2_image -lSDL2_ttf

//fonctio pour fréé les SDL_Texture
#include<SDL.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include "fun.h"
#define WINDOW_WIDTH (620)
#define WINDOW_HEIGHT (440)
#define SPEED (300)
#define MARIOSPEED (150)

int main(int argc, char ** argv) {
  SDL_Window * win = NULL;
  SDL_Renderer * renderer = NULL;
  int close = 0;
  int cursor = 1;
  bool selecting = false;

  SDL_Texture * menuImgTexture;
  SDL_Texture * backgroundTexture;

  SDL_Texture * jvjSelectTexture;
  SDL_Texture * onlineSelectTexture;
  SDL_Texture * optionSelectTexture;
  SDL_Texture * editorSelectTexture;
  SDL_Texture * quitSelectTexture;

  SDL_Texture * jvjNoSelectTexture;
  SDL_Texture * onlineNoSelectTexture;
  SDL_Texture * optionNoSelectTexture;
  SDL_Texture * editorNoSelectTexture;
  SDL_Texture * quitNoSelectTexture;

  SDL_Rect menu;
  SDL_Rect jvj;
  SDL_Rect online;
  SDL_Rect option;
  SDL_Rect editor;
  SDL_Rect quit;

  SDL_Rect jvjNo;
  SDL_Rect onlineNo;
  SDL_Rect optionNo;
  SDL_Rect editorNo;
  SDL_Rect quitNo;

  SDL_Texture * pikaTex;
  SDL_Texture*arenaTex;
  SDL_Texture*marioTex;
  SDL_Rect pikachu;
  SDL_Rect mario;

  if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0){
      printf("error initialisation");
      return EXIT_FAILURE;
  }
  win  = SDL_CreateWindow("Skip the Line",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH, WINDOW_HEIGHT,0);
  freeAndQuitIfNull(win == NULL,"creation window" ,win, renderer,backgroundTexture);
  renderer = SDL_CreateRenderer(win, -1,SDL_RENDERER_ACCELERATED);
  freeAndQuitIfNull(renderer == NULL,"creation renderer" ,win, renderer,backgroundTexture);

  backgroundTexture = buildTextur("img/menuImg/bckgrndMenu.jpg", renderer, backgroundTexture);
  freeAndQuitIfNull(backgroundTexture == NULL,"error creation texture" ,win, renderer,backgroundTexture);
  menuImgTexture = buildTextur("img/menuImg/selected/menu.png", renderer, menuImgTexture);
  freeAndQuitIfNull(menuImgTexture == NULL,"error creation texture" ,win, renderer,menuImgTexture);

  jvjSelectTexture = buildTextur("img/menuImg/selected/jvj.png", renderer, jvjSelectTexture);
  freeAndQuitIfNull(jvjSelectTexture == NULL,"error creation texture jvj" ,win, renderer,jvjSelectTexture);
  onlineSelectTexture = buildTextur("img/menuImg/selected/online.png", renderer, onlineSelectTexture);
  freeAndQuitIfNull(onlineSelectTexture == NULL,"error creation texture online" ,win, renderer,onlineSelectTexture);
  optionSelectTexture = buildTextur("img/menuImg/selected/option.png", renderer, optionSelectTexture);
  freeAndQuitIfNull(optionSelectTexture == NULL,"error creation texture option" ,win, renderer,optionSelectTexture);
  editorSelectTexture = buildTextur("img/menuImg/selected/editor.png", renderer, editorSelectTexture);
  freeAndQuitIfNull(editorSelectTexture == NULL,"error creation texture editor" ,win, renderer,editorSelectTexture);
  quitSelectTexture = buildTextur("img/menuImg/selected/quite.png", renderer, quitSelectTexture);
  freeAndQuitIfNull(quitSelectTexture == NULL,"error creation texture quit" ,win, renderer,quitSelectTexture);

  jvjNoSelectTexture = buildTextur("img/menuImg/unselected/jvj.png", renderer, jvjSelectTexture);
  freeAndQuitIfNull(jvjSelectTexture == NULL,"error creation texture" ,win, renderer,jvjSelectTexture);
  onlineNoSelectTexture = buildTextur("img/menuImg/unselected/online.png", renderer, onlineNoSelectTexture);
  freeAndQuitIfNull(onlineSelectTexture == NULL,"error creation texture" ,win, renderer,onlineSelectTexture);
  optionNoSelectTexture = buildTextur("img/menuImg/unselected/option.png", renderer, optionNoSelectTexture);
  freeAndQuitIfNull(optionSelectTexture == NULL,"error creation texture" ,win, renderer,optionSelectTexture);
  editorNoSelectTexture = buildTextur("img/menuImg/unselected/editor.png", renderer, editorNoSelectTexture);
  freeAndQuitIfNull(editorSelectTexture == NULL,"error creation texture" ,win, renderer,editorSelectTexture);
  quitNoSelectTexture = buildTextur("img/menuImg/unselected/quite.png", renderer, quitNoSelectTexture);
  freeAndQuitIfNull(quitSelectTexture == NULL,"error creation texture" ,win, renderer,quitSelectTexture);

  SDL_QueryTexture(menuImgTexture,NULL,NULL, &menu.w, &menu.h);


  SDL_QueryTexture(jvjNoSelectTexture,NULL,NULL, &jvjNo.w, &jvjNo.h);
  SDL_QueryTexture(onlineNoSelectTexture,NULL,NULL, &onlineNo.w, &onlineNo.h);
  SDL_QueryTexture(optionNoSelectTexture,NULL,NULL, &optionNo.w, &optionNo.h);
  SDL_QueryTexture(editorNoSelectTexture,NULL,NULL, &editorNo.w, &editorNo.h);
  SDL_QueryTexture(quitNoSelectTexture,NULL,NULL, &quitNo.w, &quitNo.h);

  SDL_QueryTexture(jvjSelectTexture,NULL,NULL, &jvj.w, &jvj.h);
  SDL_QueryTexture(onlineSelectTexture,NULL,NULL, &online.w, &online.h);
  SDL_QueryTexture(optionSelectTexture,NULL,NULL, &option.w, &option.h);
  SDL_QueryTexture(editorSelectTexture,NULL,NULL, &editor.w, &editor.h);
  SDL_QueryTexture(quitSelectTexture,NULL,NULL, &quit.w, &quit.h);


  int centered = (WINDOW_HEIGHT - menu.h) / 2;
  int gapBetweenLabel = 65;
  int y_label = 10;
  int ladderDimenssion = 3;

  initPositionAndSize(&menu ,&ladderDimenssion,&y_label,&centered);
  y_label += gapBetweenLabel;
  initPositionAndSize(&jvjNo ,&ladderDimenssion,&y_label,&centered);
  initPositionAndSize(&jvj ,&ladderDimenssion,&y_label,&centered);
  y_label += gapBetweenLabel;
  initPositionAndSize(&onlineNo ,&ladderDimenssion,&y_label,&centered);
  initPositionAndSize(&online ,&ladderDimenssion,&y_label,&centered);
  y_label += gapBetweenLabel;
  initPositionAndSize(&optionNo ,&ladderDimenssion,&y_label,&centered);
  initPositionAndSize(&option ,&ladderDimenssion,&y_label,&centered);
  y_label += gapBetweenLabel;
  initPositionAndSize(&editorNo ,&ladderDimenssion,&y_label,&centered);
  initPositionAndSize(&editor ,&ladderDimenssion,&y_label,&centered);
  y_label += gapBetweenLabel;
  initPositionAndSize(&quit ,&ladderDimenssion,&y_label,&centered);
  initPositionAndSize(&quitNo ,&ladderDimenssion,&y_label,&centered);

  while (!close) {
      SDL_Event event;
      while (SDL_PollEvent(&event) == 1) {
          if(event.type == SDL_QUIT) {
               close = 1;
          }
          switch (event.type) {
              case SDL_KEYDOWN:
                  switch (event.key.keysym.sym) {
                      case SDLK_RETURN:
                        printf("entrer\n");
                        selecting = true;
                        break;
                      case SDLK_DOWN:
                          ++cursor;
                          printf("bas\n");
                          break;
                      case SDLK_UP:
                          --cursor;
                          printf("haut\n");
                          break;
                  }
              break;
          }
      }
      if (cursor == 6) cursor = 1;
      if (cursor == 0) cursor = 5;

      SDL_RenderClear(renderer);
      SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
      SDL_RenderCopy(renderer, menuImgTexture, NULL, &menu);
      if (cursor == 1) {
        SDL_RenderCopy(renderer, jvjSelectTexture, NULL, &jvj);
        if(selecting)printf("début du jeu\n");
      } else {
        SDL_RenderCopy(renderer, jvjNoSelectTexture, NULL, &jvjNo);
      }
      if (cursor == 2) {
        SDL_RenderCopy(renderer, onlineSelectTexture, NULL, &online);
      } else {
        SDL_RenderCopy(renderer, onlineNoSelectTexture, NULL, &onlineNo);
      }
      if (cursor == 3) {
        SDL_RenderCopy(renderer, optionSelectTexture, NULL, &option);
      } else {
        SDL_RenderCopy(renderer, optionNoSelectTexture, NULL, &optionNo);
      }

      if (cursor == 4) {
        SDL_RenderCopy(renderer, editorSelectTexture, NULL, &editor);
      } else {
        SDL_RenderCopy(renderer, editorNoSelectTexture, NULL, &editorNo);
      }

      if (cursor == 5) {
        SDL_RenderCopy(renderer, quitSelectTexture, NULL, &quit);
      } else {
         SDL_RenderCopy(renderer, quitNoSelectTexture, NULL, &quitNo);
      }

      SDL_RenderPresent(renderer);
      SDL_Delay(1000/60);
  }
/*
    pikaTex = buildTextur("img/pika.bmp", renderer, pikaTex);
    freeAndQuitIfNull(pikaTex == NULL,"error creation texture" ,win, renderer,pikaTex);
    arenaTex = buildTextur("img/bckgrndMenu.jpg", renderer, arenaTex);
    freeAndQuitIfNull(arenaTex == NULL,"error creation texture" ,win, renderer,pikaTex);
    marioTex = buildTextur("img/mario.bmp", renderer, marioTex);
    freeAndQuitIfNull(marioTex == NULL,"error creation texture" ,win, renderer,pikaTex);
    //prend la lngeur et la hauter de la textre
    SDL_QueryTexture(pikaTex,NULL,NULL, &pikachu.w, &pikachu.h);
    SDL_QueryTexture(marioTex,NULL,NULL, &mario.w, &mario.h);
    //multiplie par 2 la taile de l'image
    // faire une fonction pour gerer la taille des élément
    pikachu.h /= 4;
    pikachu.w /= 4;
    mario.h /= 4;
    mario.w /= 4;
    //faire une fonction pour gerer la postion de départ
    float y_pos = (WINDOW_HEIGHT - pikachu.h) / 2;
    float x_pos = (WINDOW_WIDTH - pikachu.w) / 2;
    float xVel = SPEED;
    float yVel = SPEED;
    float mario_y_pos = 10;
    float mario_x_pos = 10;
    float mario_xVel = MARIOSPEED;
    float mario_yVel = MARIOSPEED;
    int close = 0;
    int marioLastXY[2] = {mario_x_pos ,mario_yVel};
    int pikachuLastXY[2] = {x_pos ,y_pos};
    //boucle d'annimation
    while (!close) {
        //fair fonction get lastposition
        marioLastXY[0] = mario_x_pos;
        marioLastXY[1] = mario_yVel;
        pikachuLastXY[0] = x_pos;
        pikachuLastXY[1] = y_pos;
        SDL_Event event;
        while (SDL_PollEvent(&event) == 1) {
            if(event.type == SDL_QUIT) {
                 close = 1;
            }
            switch (event.type) {
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_DOWN:
                            y_pos += SPEED/30;
                            printf("bas\n");
                            break;
                        case SDLK_UP:
                            y_pos -= SPEED/30;
                            printf("haut\n");
                            break;
                        case SDLK_LEFT:
                            x_pos -= SPEED/30;
                            printf("gauche\n");
                            break;
                        case SDLK_RIGHT:
                            x_pos += SPEED/30;
                            printf("droite\n");

                            //mario commande
                        case SDLK_s:
                            mario_y_pos += MARIOSPEED/30;
                            printf("bas\n");
                            break;
                        case SDLK_z:
                            mario_y_pos -= MARIOSPEED/30;
                            printf("haut\n");
                            break;
                        case SDLK_q:
                            mario_x_pos -= MARIOSPEED/30;
                            printf("gauche\n");
                            break;
                        case SDLK_d:
                            mario_x_pos += MARIOSPEED/30;
                            printf("droite\n");
                            break;
                    }
                break;
            }
        }
        //manage colistion pikachu
        dontCrosseBorder(&xVel, &x_pos);
        dontCrosseBorder(&yVel, &y_pos);
        dontCrosseBottomBorder(WINDOW_WIDTH,pikachu.w,&xVel,&x_pos);
        dontCrosseBottomBorder(WINDOW_HEIGHT,pikachu.h,&yVel,&y_pos);
        //manage colistion mario
        dontCrosseBorder(&mario_xVel, &mario_x_pos);
        dontCrosseBorder(&mario_yVel, &mario_y_pos);
        dontCrosseBottomBorder(WINDOW_WIDTH,mario.w,&mario_xVel,&mario_x_pos);
        dontCrosseBottomBorder(WINDOW_HEIGHT,mario.h,&mario_yVel,&mario_y_pos);
        pikachu.x = (int) x_pos;
        pikachu.y = (int) y_pos;
        mario.x = (int) mario_x_pos;
        mario.y = (int) mario_y_pos;
        if (SDL_HasIntersection(&mario,&pikachu)){
            mario_x_pos = marioLastXY[0];
            mario_yVel = marioLastXY[1];
            x_pos = pikachuLastXY[0];
            y_pos = pikachuLastXY[1];
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, arenaTex, NULL, NULL);
        SDL_RenderCopy(renderer, pikaTex, NULL, &pikachu);
        SDL_RenderCopy(renderer, marioTex, NULL, &mario);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000/60);
    }
    SDL_DestroyTexture(pikaTex);
    SDL_DestroyTexture(arenaTex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();*/


SDL_DestroyTexture(menuImgTexture);
SDL_DestroyTexture(backgroundTexture);

SDL_DestroyTexture(jvjSelectTexture);
SDL_DestroyTexture(onlineSelectTexture);
SDL_DestroyTexture(optionSelectTexture);
SDL_DestroyTexture(editorSelectTexture);
SDL_DestroyTexture(quitSelectTexture);

SDL_DestroyTexture(jvjNoSelectTexture);
SDL_DestroyTexture(onlineNoSelectTexture);
SDL_DestroyTexture(optionNoSelectTexture);
SDL_DestroyTexture(editorNoSelectTexture);
SDL_DestroyTexture(quitNoSelectTexture);

SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(win);
SDL_Quit();
    return EXIT_SUCCESS;
}
