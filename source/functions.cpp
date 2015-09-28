#include <stdlib.h>
#include <grrlib.h>
#include "functions.hpp"
#include "gfx.h"
int customrand(int min,int max){
	return min+rand()%max;
}
void skittle::skittlecreate(){
	x=615;
	y=customrand(0,455);
	w=25;
	h=25;
	color=customrand(0,4);
	tex=img_skittles;
}
void skittle::sdisplay(){
	GRRLIB_DrawTile(x,y,tex,0,1,1,color_white,color);
}
void item::itemcreate(int a,int b,int c,int d){
	x=a;
	y=b;
	w=c;
	h=d;
	int n=customrand(1,2);
	if(n==1){
		item=cheese;
		tex=img_cheese;
	}
	else{
		item=burrito;
		tex=img_burrito;
	}
}
void sprite::create(int a,int b,int c,int d,GRRLIB_texImg*e){
	x=a;
	y=b;
	w=c;
	h=d;
	tex=e;
}
void sprite::display(){
	GRRLIB_DrawImg(x,y,tex,0,1,1,color_white);
}
bool sprite::hittest(sprite spr2){
	if(GRRLIB_PtInRect(x+w,y+(h/2),w,h,spr2.x,spr2.y)) return true;
	else return false;
}
void screendisplay(GRRLIB_texImg*background){
	GRRLIB_DrawImg(0,0,background,0,1,1,color_white);
}