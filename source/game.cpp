#include <grrlib.h>
#include <wiiuse/wpad.h>
#include "functions.hpp"
#include "gfx.h"
#pragma GCC diagnostic ignored "-Wunused-value"
int points=0,hp=100,skittlecount=0,cheesecount=0,highscore=0,greenskittlecount=0;
int points2=0,hp2=100;
extern void achievementcheck();
extern u32 wpaddown,wpadheld,wpaddown2,wpadheld2;
char pointschar[20],hpchar[20],pointschar2[20],hpchar2[20];
sprite player,player1,player2,bird,bird2,donut,donut2;
item item1,item2,item3;
skittle s1,s2;
extern ir_t ir1,ir2;
extern GRRLIB_ttfFont*terraria;
extern enum screenenum screen;
bool p1alive=true,p2alive=true;
void sologame(){
	achievementcheck();
	player.display();
	item1.display();
	item2.display();
	item3.display();
	s1.sdisplay();
	s2.sdisplay();
	bird.display();
	donut.display();
	sprintf(pointschar,"Points : %d",points);
	GRRLIB_PrintfTTF(20,50,terraria,pointschar,18,color_black);
	sprintf(hpchar,"%d/100",hp);
	GRRLIB_PrintfTTF(20,73,terraria,hpchar,18,color_black);
	if(wpadheld&WPAD_BUTTON_LEFT) player.y+=5;
	if(wpadheld&WPAD_BUTTON_RIGHT) player.y-=5;
	if(wpadheld&WPAD_BUTTON_UP) player.x-=5;
	if(wpadheld&WPAD_BUTTON_DOWN) player.x+=5;
	if(wpaddown&WPAD_BUTTON_PLUS) screen=achievements;
	if(player.x<0) player.x=0;
	if(player.y<0) player.y=0;
	if(player.y>428) player.y=428;
	if(player.x>588) player.x=588;
	item1.x-=7;item2.x-=7;item3.x-=7;
	s1.x-=7;s2.x-=7;
	donut.y+=7;
	if(bird.x>player.x+1) bird.x-=3;
	if(bird.x<player.x-1) bird.x+=3;
	if(donut.y>505) donut.create(bird.x,bird.y,25,25,img_donut);
	if(player.hittest(donut)){
		hp-=10;
		donut.create(bird.x,bird.y,25,25,img_donut);
	}
	if(donut.y>player.y) donut.tex=img_parachute;
	else donut.tex=img_donut;
	if(player.hittest(item1)){
		if(item1.item==cheese){
			points-=2;
			hp-=25;
			cheesecount++;
		}
		else points++;
		item1.itemcreate(590,customrand(0,430),50,50);
	}
	if(player.hittest(item2)){
		if(item2.item==cheese){
			points-=2;
			hp-=25;
			cheesecount++;
		}
		else points++;
		item2.itemcreate(590,customrand(0,430),50,50);
	}
	if(player.hittest(item3)){
		if(item3.item==cheese){
			points-=2;
			hp-=25;
			cheesecount++;
		}
		else points++;
		item3.itemcreate(590,customrand(0,430),50,50);
	}
	if(player.hittest(s1)){
		hp+=10;
		s1.skittlecreate();
		skittlecount++;
		if(s1.color==1) greenskittlecount++;
	}
	if(player.hittest(s2)){
		hp+=10;
		s2.skittlecreate();
		skittlecount++;
		if(s2.color==1) greenskittlecount;
	}
	if(item1.x<=-50) item1.itemcreate(590,customrand(0,430),50,50);
	if(item2.x<=-50) item2.itemcreate(590,customrand(0,430),50,50);
	if(item3.x<=-50) item3.itemcreate(590,customrand(0,430),50,50);
	if(s1.x<=-25) s1.skittlecreate();
	if(s2.x<=-25) s2.skittlecreate();
	if(hp>100) hp=100;
	if(hp<=0) screen=gameover;
}
void coopgame(){
	if(p1alive) player1.display();
	if(p2alive) player2.display();
	item1.display();
	item2.display();
	item3.display();
	s1.sdisplay();
	s2.sdisplay();
	if(p1alive) bird.display();
	if(p2alive) bird2.display();
	if(p1alive) donut.display();
	if(p2alive) donut2.display();
	if(p1alive){
		sprintf(pointschar,"Points : %d",points);
		GRRLIB_PrintfTTF(20,50,terraria,pointschar,18,color_blue);
		sprintf(hpchar,"%d/100",hp);
		GRRLIB_PrintfTTF(20,73,terraria,hpchar,18,color_blue);
	}
	if(p2alive){
		sprintf(pointschar2,"Points: %d",points2);
		GRRLIB_PrintfTTF(550,50,terraria,pointschar2,18,color_red);
		sprintf(hpchar2,"%d/100",hp2);
		GRRLIB_PrintfTTF(550,73,terraria,hpchar2,18,color_red);
	}
	if(p1alive){
		if(wpadheld&WPAD_BUTTON_LEFT) player1.y+=5;
		if(wpadheld&WPAD_BUTTON_RIGHT) player1.y-=5;
		if(wpadheld&WPAD_BUTTON_UP) player1.x-=5;
		if(wpadheld&WPAD_BUTTON_DOWN) player1.x+=5;
		if(player1.x<0) player1.x=0;
		if(player1.y<0) player1.y=0;
		if(player1.y>428) player1.y=428;
		if(player1.x>588) player1.x=588;
	}
	if(p2alive){
		if(wpadheld2&WPAD_BUTTON_LEFT) player2.y+=5;
		if(wpadheld2&WPAD_BUTTON_RIGHT) player2.y-=5;
		if(wpadheld2&WPAD_BUTTON_UP) player2.x-=5;
		if(wpadheld2&WPAD_BUTTON_DOWN) player2.x+=5;
		if(player2.x<0) player2.x=0;
		if(player2.y<0) player2.x=0;
		if(player2.y>428) player2.y=428;
		if(player2.x>588) player2.x=588;
	}
	item1.x-=7;item2.x-=7;item3.x-=7;
	s1.x-=7;s2.x-=7;
	if(p1alive) donut.y+=7;
	if(p2alive) donut2.y+=7;
	if(p1alive){
		if(bird.x>player1.x+1) bird.x-=3;
		if(bird.x<player1.x-1) bird.x+=3;
	}
	if(p2alive){
		if(bird2.x>player2.x+1) bird2.x-=3;
		if(bird2.x<player2.x-1) bird2.x+=3;
	}
	if(p1alive){
		if(donut.y>505) donut.create(bird.x,bird.y,25,25,img_donut);
	}
	if(p2alive){
		if(donut2.y>505) donut2.create(bird2.x,bird2.y,25,25,img_donut);
	}
	if(p1alive){
		if(player1.hittest(donut)){
			hp-=10;
			donut.create(bird.x,bird.y,25,25,img_donut);
		}
	}
	if(p2alive){
		if(player2.hittest(donut)){
			hp2-=10;
			donut.create(bird.x,bird.y,25,25,img_donut);
		}
	}
	if(p1alive){
		if(player1.hittest(donut2)){
			hp-=10;
			donut2.create(bird2.x,bird2.y,25,25,img_donut);
		}
	}
	if(p2alive){
		if(player2.hittest(donut2)){
			hp2-=10;
			donut2.create(bird2.x,bird2.y,25,25,img_donut);
		}
	}
	if(p1alive){
		if(donut.y>player.y) donut.tex=img_parachute;
		else donut.tex=img_donut;
	}
	if(p2alive){
		if(donut2.y>player2.y) donut2.tex=img_parachute;
		else donut2.tex=img_donut;
	}
	if(p1alive){
		if(player1.hittest(item1)){
			if(item1.item==cheese){
				points-=2;
				hp-=25;
			}
			else points++;
			item1.itemcreate(590,customrand(0,430),50,50);
		}
		if(player1.hittest(item2)){
			if(item2.item==cheese){
				points-=2;
				hp-=25;
			}
			else points++;
			item2.itemcreate(590,customrand(0,430),50,50);
		}
		if(player1.hittest(item3)){
			if(item3.item==cheese){
				points-=2;
				hp-=25;
			}
			else points++;
			item3.itemcreate(590,customrand(0,430),50,50);
		}
		if(player1.hittest(s1)){
			hp+=10;
			s1.skittlecreate();
		}
		if(player1.hittest(s2)){
			hp+=10;
			s2.skittlecreate();
		}
	}
	if(p2alive){
		if(player2.hittest(item1)){
			if(item1.item==cheese){
				points2-=2;
				hp2-=25;
			}
			else points2++;
			item1.itemcreate(590,customrand(0,430),50,50);
		}
		if(player2.hittest(item2)){
			if(item2.item==cheese){
				points2-=2;
				hp2-=25;
			}
			else points2++;
			item2.itemcreate(590,customrand(0,430),50,50);
		}
		if(player2.hittest(item3)){
			if(item3.item==cheese){
				points2-=2;
				hp2-=25;
			}
			else points2++;
			item3.itemcreate(590,customrand(0,430),50,50);
		}
		if(player2.hittest(s1)){
			hp2+=10;
			s1.skittlecreate();
		}
		if(player2.hittest(s2)){
			hp2+=10;
			s2.skittlecreate();
		}
	}
	if(item1.x<=-50) item1.itemcreate(590,customrand(0,430),50,50);
	if(item2.x<=-50) item2.itemcreate(590,customrand(0,430),50,50);
	if(item3.x<=-50) item3.itemcreate(590,customrand(0,430),50,50);
	if(s1.x<=-25) s1.skittlecreate();
	if(s2.x<=-25) s2.skittlecreate();
	if(hp>100) hp=100;
	if(hp2>100) hp2=100;
	if(hp<=0) p1alive=false;
	if(hp2<=0) p2alive=false;
	if(!p1alive&!p2alive) screen=coopgameover;
}