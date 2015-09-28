#include <grrlib.h>
#include <wiiuse/wpad.h>
#include "achievements.h"
#include "functions.hpp"
#pragma GCC diagnostic ignored "-Wwrite-strings"
#pragma GCC diagnostic ignored "-Wparentheses"
#define color_black 0x000000FF
#define color_white 0xFFFFFFFF
extern achievement achs[];
extern GRRLIB_ttfFont*terraria;
extern GRRLIB_texImg*img_background;
extern int points,skittlecount,hp,cheesecount,greenskittlecount;
extern u32 wpaddown;
extern sprite player,bird,donut;
extern item item1,item2,item3;
extern skittle s1,s2;
extern bool pointsach;
void achievement::achcreate(char*a,char*b){
	got=false;
	name=a;
	desc=b;
}
void achcreate(){
	achs[0].achcreate("50 Points!","Pretty self-explanatory.");
	achs[1].achcreate("Yummy","Collect 5 skittles.");
	achs[2].achcreate("Sweet Tooth","Collect 10 skittles.");
	achs[3].achcreate("That Was Close!","Have 5 health without dying.");
	achs[4].achcreate("Gross!","Collect 5 pieces of cheese.");
	achs[5].achcreate("Fuck the Police","Get -10 points.");
	achs[6].achcreate("That Was Intentional","Die with exactly 0 points.");
	achs[7].achcreate("If Only They Were M&Ms...","Collect 15 green skittles.");
	achs[8].achcreate("Completionist","Collect all of the achievements.");
}
void acdisp(achievement ac){
	char pointschar[20],hpchar[20];
	while(1){
		WPAD_ScanPads();
		wpaddown=WPAD_ButtonsDown(0);
		GRRLIB_DrawImg(0,0,img_background,0,1,1,color_white);
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
		int length=strlen(ac.desc);
		GRRLIB_Rectangle((640-(length*8)),50,(length*8),69,0x00FF00FF,1);
		GRRLIB_PrintfTTF(((640-(length*8))+2),50,terraria,ac.name,18,color_black);
		GRRLIB_PrintfTTF(((640-(length*8))+2),73,terraria,ac.desc,18,color_black);
		GRRLIB_PrintfTTF(((640-(length*8))+2),96,terraria,"Press 2!",18,color_black);
		GRRLIB_PrintfTTF(0,463,terraria,"v1.0",18,color_black);
		GRRLIB_Render();
		if(wpaddown&WPAD_BUTTON_2) break;
	}
}
void achievementcheck(){
	if(!achs[0].got){
		if(points>=50){
			achs[0].got=true;
			acdisp(achs[0]);
		}
	}
	if(!achs[1].got){
		if(skittlecount>=5){
			achs[1].got=true;
			acdisp(achs[1]);
		}
	}
	if(!achs[2].got){
		if(skittlecount>=10){
			achs[2].got=true;
			acdisp(achs[2]);
		}
	}
	if(!achs[3].got){
		if(hp>0&hp<=5){
			achs[3].got=true;
			acdisp(achs[3]);
		}
	}
	if(!achs[4].got){
		if(cheesecount>=5){
			achs[4].got=true;
			acdisp(achs[4]);
		}
	}
	if(!achs[5].got){
		if(points<=-10){
			achs[5].got=true;
			acdisp(achs[5]);
		}
	}
	if(!achs[6].got){
		if(pointsach){
			achs[6].got=true;
			acdisp(achs[6]);
		}
	}
	if(!achs[7].got){
		if(greenskittlecount>=15){
			achs[7].got=true;
			acdisp(achs[7]);
		}
	}
	if(!achs[8].got){
		if(achs[0].got&achs[1].got&achs[2].got&achs[3].got&achs[4].got&achs[5].got&achs[6].got&achs[7].got){
			achs[8].got=true;
			acdisp(achs[8]);
		}
	}
}