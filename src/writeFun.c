#include "writeFun.h"


SDL_Texture * renderText(const char * message, const char* fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer) {
	//Open the font
	TTF_Font *font = TTF_OpenFont(fontFile, fontSize);
	if (font == NULL){
		printf("error\n TTF_OpenFont");
		return NULL;
	}
	//We need to first render to a surface as that's what TTF_RenderText
	//returns, then load that surface into a texture
	SDL_Surface *surf = TTF_RenderText_Blended(font, message , color);
	if (surf == NULL){
		TTF_CloseFont(font);
		printf("error\n TTF_RenderText");
		return NULL;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == NULL){
		printf("error\n CreateTextureFromSurface");
	}
	//Clean up the surface and font
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return texture;
}


char ** getMenuWords() {
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
    strcpy(array[0], "JvJ");
    strcpy(array[1], "JvJ");
    strcpy(array[2], "ONLINE");
    strcpy(array[3], "ONLINE");
    strcpy(array[4], "EDITOR");
    strcpy(array[5], "EDITOR");
    strcpy(array[6], "OPTION");
    strcpy(array[7], "OPTION");
    strcpy(array[8], "QUIT");
    strcpy(array[9], "QUIT");
    return array;
  }
  printf("\n error \n getMenuImagePath \n");
  return array;
}

SDL_Color * colorSet(SDL_Color * c, int red,int green,int blue) {
	c->r = red;
	c->r = green;
	c->r = blue;
	c->a = SDL_ALPHA_OPAQUE;// 0.0 (totally transparent aka invisible) to 1.0 (fully opaque).
	return c;
}


SDL_Texture  *** getTextureMenuArrayByttf(SDL_Texture *** arrayT,  SDL_Renderer * renderer) {
	SDL_Color green = { 0, 200, 0,SDL_ALPHA_OPAQUE};
	SDL_Color blue = {0, 50, 150,SDL_ALPHA_OPAQUE};
	/*green  = colorSet(&green, 0, 200, 0);
	blue = colorSet(&blue, 0, 50, 150);*/
  	int i;
  	char ** arrayTexturePath = getMenuWords();
  	for (i = 0; i < 10; i+=2) {
		*arrayT[i] = renderText(arrayTexturePath[i],"font/gameria/gameria/GAMERIA.ttf", blue,100,renderer);//
		if( arrayT[i] == NULL) printf(" error\n image -> %s", arrayTexturePath[i]);
		*arrayT[i + 1] = renderText(arrayTexturePath[i],"font/gameria/gameria/GAMERIA.ttf", green,100,renderer);
		if( arrayT[i + i] == NULL) printf(" error\n image -> %s", arrayTexturePath[i + 1]);
 	}
	for (i = 0; i < 10; i++)
		free(arrayTexturePath[i]);
	free(arrayTexturePath);
	return arrayT;
}
///////   for maps selection menu ///////

void setTextureMapMenuTitleByttf(firstMapNode * fNodeMap,  SDL_Renderer * renderer) {
	SDL_Color green = { 0, 200, 0,SDL_ALPHA_OPAQUE};
	SDL_Color blue = {0, 50, 150,SDL_ALPHA_OPAQUE};
	map * ptr = fNodeMap->firstMap;
	while (1) {
		ptr->selcetedBlue = renderText(ptr->name,"font/gameria/gameria/GAMERIA.ttf", blue,100,renderer);
		if( ptr->selcetedBlue == NULL) printf(" error\n map -> %s", ptr->name);
		ptr->unselcetedGreen = renderText(ptr->name,"font/gameria/gameria/GAMERIA.ttf", green,100,renderer);
		if( ptr->unselcetedGreen == NULL) printf(" error\n map -> %s", ptr->name);
		if (ptr->next == NULL) break;
		ptr = ptr->next;
	}
}