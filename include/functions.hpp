#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <grrlib.h>
extern int customrand(int,int);
enum itemenum{
	cheese,
	burrito
};
enum screenenum{
	title,
	game,
	coop,
	tutorial,
	credits,
	achievements,
	gameover,
	coopgameover
};
class sprite{
	public:
		int x,y,w,h;
		GRRLIB_texImg*tex;
		void create(int,int,int,int,GRRLIB_texImg*);
		void display();
		bool hittest(sprite);
};
class item:public sprite{
	public:
		enum itemenum item;
		void itemcreate(int,int,int,int);
};
class skittle:public sprite{
	public:
		u32 color;
		void skittlecreate();
		void sdisplay();
};
#endif