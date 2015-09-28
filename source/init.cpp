#include <stdlib.h>
#include <grrlib.h>
#include "functions.hpp"
#include "gfx.h"
GRRLIB_texImg*img_burrito,*img_cheese,*img_skittles,*img_unicorn,*img_bird,*img_donut,*img_parachute,*img_background,*img_title,*img_credits,*img_tutorial,*img_p1,*img_p2;
extern item item1,item2,item3;
extern sprite player,player1,player2,bird,bird2,donut,donut2;
extern skittle s1,s2;
extern GRRLIB_ttfFont*terraria;
void spriteinit(){
	player.create(0,240,50,50,img_unicorn);
	player1.create(0,240,50,50,img_p1);
	player2.create(0,290,50,50,img_p2);
	bird.create(0,0,50,50,img_bird);
	bird2.create(0,0,50,50,img_bird);
	donut.create(0,0,25,25,img_donut);
	donut2.create(0,0,25,25,img_donut);
	item1.itemcreate(590,customrand(0,430),50,50);
	item2.itemcreate(590,customrand(0,430),50,50);
	item3.itemcreate(590,customrand(0,430),50,50);
	s1.skittlecreate();
	s2.skittlecreate();
}
void gfxinit(){
	terraria=GRRLIB_LoadTTF(terraria_ttf,terraria_ttf_size);
	img_unicorn=GRRLIB_LoadTexturePNG(unicorn_png);
	img_skittles=GRRLIB_LoadTexturePNG(skittles_png);
	GRRLIB_InitTileSet(img_skittles,24,24,0);
	img_cheese=GRRLIB_LoadTexturePNG(cheese_png);
	img_burrito=GRRLIB_LoadTexturePNG(burrito_png);
	img_background=GRRLIB_LoadTexturePNG(background_png);
	img_bird=GRRLIB_LoadTexturePNG(bird_png);
	img_donut=GRRLIB_LoadTexturePNG(donut_png);
	img_parachute=GRRLIB_LoadTexturePNG(parachute_png);
	img_title=GRRLIB_LoadTexturePNG(title_png);
	img_credits=GRRLIB_LoadTexturePNG(credits_png);
	img_tutorial=GRRLIB_LoadTexturePNG(tutorial_png);
	img_p1=GRRLIB_LoadTexturePNG(p1_png);
	img_p2=GRRLIB_LoadTexturePNG(p2_png);
}
void gfxdeinit(){
	GRRLIB_FreeTexture(img_unicorn);
	GRRLIB_FreeTexture(img_skittles);
	GRRLIB_FreeTexture(img_cheese);
	GRRLIB_FreeTexture(img_burrito);
	GRRLIB_FreeTTF(terraria);
	GRRLIB_FreeTexture(img_background);
	GRRLIB_FreeTexture(img_donut);
	GRRLIB_FreeTexture(img_parachute);
	GRRLIB_FreeTexture(img_bird);
	GRRLIB_FreeTexture(img_title);
	GRRLIB_FreeTexture(img_credits);
	GRRLIB_FreeTexture(img_tutorial);
	GRRLIB_FreeTexture(img_p1);
	GRRLIB_FreeTexture(img_p2);
}