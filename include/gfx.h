#ifndef gfx_h
#define gfx_h
#include "terraria_ttf.h"
#include "unicorn_png.h"
#include "cheese_png.h"
#include "burrito_png.h"
#include "skittles_png.h"
#include "background_png.h"
#include "bird_png.h"
#include "donut_png.h"
#include "parachute_png.h"
#include "title_png.h"
#include "credits_png.h"
#include "tutorial_png.h"
#include "p1_png.h"
#include "p2_png.h"
#define color_black 0x000000FF
#define color_red   0xFF0000FF
#define color_green 0x00FF00FF
#define color_blue  0x0000FFFF
#define color_white 0xFFFFFFFF
extern GRRLIB_texImg*img_burrito,*img_cheese,*img_skittles,*img_unicorn,*img_bird,*img_donut,*img_parachute,*img_background,*img_title,*img_credits,*img_tutorial,*img_p1,*img_p2;
extern void spriteinit();
extern void gfxinit();
extern void gfxdeinit();
#endif