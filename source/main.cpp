#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ogcsys.h>
#include <gccore.h>
#include <grrlib.h>
#include <wiiuse/wpad.h>
#include "achievements.h"
#include "gfx.h"
#include "functions.hpp"
#include "game.h"
#pragma GCC diagnostic ignored "-Wunused-value"
#pragma GCC diagnostic ignored "-Wparentheses"
enum screenenum screen=title;
u32 wpaddown,wpadheld,wpaddown2,wpadheld2;
bool pointsach=false,checked=false;
achievement achs[9];
ir_t ir1,ir2;
GRRLIB_ttfFont*terraria;
extern int points,points2,hp,hp2;
extern sprite player1,player2;
extern bool p1alive,p2alive;
int main(){
	WPAD_Init();
	WPAD_SetVRes(0,640+100,480+100);
	WPAD_SetDataFormat(WPAD_CHAN_ALL,WPAD_FMT_BTNS_ACC_IR);
	GRRLIB_Init();
	gfxinit();
	spriteinit();
	achcreate();
	while(1){
		WPAD_ScanPads();
		wpaddown=WPAD_ButtonsDown(0);wpadheld=WPAD_ButtonsHeld(0);
		wpaddown2=WPAD_ButtonsHeld(1);wpadheld2=WPAD_ButtonsHeld(1);
		WPAD_IR(0,&ir1);WPAD_IR(1,&ir2);
		GRRLIB_DrawImg(0,0,img_background,0,1,1,color_white);
		if(wpaddown&WPAD_BUTTON_HOME){
			gfxdeinit();
			GRRLIB_Exit();
			exit(0);
		}
		if(screen==title){
			GRRLIB_DrawImg(0,0,img_title,0,1,1,color_white);
			GRRLIB_Rectangle(ir1.x,ir1.y,20,20,color_red,1);
			GRRLIB_Rectangle(ir2.x,ir2.y,20,20,color_blue,1);
			if(wpaddown&WPAD_BUTTON_A) screen=tutorial;
			if(wpaddown&WPAD_BUTTON_1) screen=credits;
			if(wpaddown&WPAD_BUTTON_2) screen=coop;
		}
		else if(screen==tutorial){
			GRRLIB_DrawImg(0,0,img_tutorial,0,1,1,color_white);
			if(wpaddown&WPAD_BUTTON_A) screen=game;
		}
		else if(screen==credits){
			GRRLIB_DrawImg(0,0,img_credits,0,1,1,color_white);
			if(wpaddown&WPAD_BUTTON_B) screen=title;
		}
		else if(screen==game) sologame();
		else if(screen==coop) coopgame();
		else if(screen==achievements){
			for(int n=0;n<=8;n++){
				if(!achs[n].got) GRRLIB_PrintfTTF(73,(115+(n*23)),terraria,achs[n].name,18,color_red);
				else GRRLIB_PrintfTTF(73,(115+(n*23)),terraria,achs[n].name,18,color_green);
				GRRLIB_PrintfTTF(260,(115+(n*23)),terraria,achs[n].desc,18,color_black);
			}
			if(wpaddown&WPAD_BUTTON_PLUS) screen=game;
		}
		else if(screen==gameover){
			if(points>highscore) highscore=points;
			if(points==0&!checked) pointsach=true;
			checked=true;
			points=0;
			hp=100;
			char hschar[20];
			GRRLIB_PrintfTTF(320,240,terraria,"Game Over! D:",18,color_black);
			GRRLIB_PrintfTTF(320,280,terraria,"Press 2 to try again! :D",18,color_black);
			sprintf(hschar,"High Score : %d",highscore);
			GRRLIB_PrintfTTF(320,320,terraria,hschar,18,color_black);
			if(wpaddown&WPAD_BUTTON_2){
				screen=game;
				checked=false;
			}
		}
		else if(screen==coopgameover){
			char hschar1[20],hschar2[20];
			GRRLIB_PrintfTTF(320,240,terraria,"Game Over! D:",18,color_black);
			GRRLIB_PrintfTTF(320,280,terraria,"Press 2 to play again! :D",18,color_black);
			sprintf(hschar1,"P1 Score : %d",points);
			sprintf(hschar2,"P2 Score : %d",points2);
			GRRLIB_PrintfTTF(270,320,terraria,hschar1,18,color_black);
			GRRLIB_PrintfTTF(370,320,terraria,hschar2,18,color_black);
			if((wpaddown&WPAD_BUTTON_2)||(wpaddown2&WPAD_BUTTON_2)){
				screen=coop;
				points=0;points2=0;
				hp=100;hp2=100;
				player1.x=0;player2.x=0;
				player1.y=320;player2.y=370;
				p1alive=true;p2alive=true;
			}
		}
		GRRLIB_PrintfTTF(25,430,terraria,"v2.0b",18,color_black);
		GRRLIB_Render();
	}
}
