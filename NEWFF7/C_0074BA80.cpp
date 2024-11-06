/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//WORLD MAP -- 

#include "ff7.h"
#include "wm_data.h"
#include "field_data.h"
#include "menu_data.h"
////////////////////////////////////////
int __00969948 = 1;
int D_0096994C = 1;//isRendering?
int D_00969950 = 1;//allowsFrameSkip?
//00969954  00 00 00 00
double D_00969958 = 30.0;//requested frame rate
double D_00969960 = 22.0;//requested frame rate
////////////////////////////////////////
unsigned D_00DE67E8;//viewport height
//00DE67EC
LARGE_INTEGER D_00DE67F0;
unsigned D_00DE68F8;//viewport width
void (*D_00DE68FC)(void);//wm render callback
float D_00DE6900;
//00DE6904
double D_00DE6908;
LARGE_INTEGER D_00DE6910;
struct tMainCallbacks D_00DE6918;
//00DE6934
double D_00DE6938;//CPU cycles per frame?
int D_00DE6940;
//char 00DE6944[0x94]
int D_00DE69D8;
int D_00DE69DC;//go to main dispatcher
int D_00DE69E0;//"init/reset done" flag
int D_00DE69E4;
int D_00DE69EC;//skip this frame
double D_00DE69F0;
int D_00DE69F8;
//00DE69FC
////////////////////////////////////////
//WORLD MAP[ONMOUSE][callback]
void C_0074BA80(int uMsg/*_p08*/, int wParam/*_p0c*/, int lParam/*_p10*/, struct t_aa0 *_p14) {
}

//WORLD MAP[ONKEY][callback]
void C_0074BA85(int uMsg/*_p08*/, int wParam/*_p0c*/, int lParam/*_p10*/, struct t_aa0 *_p14) {
}

void __0074BA8A(int dwX/*bp08*/, int dwY/*bp0c*/, const char *pString/*bp10*/, HDC hdc/*bp14*/) {
	SetBkColor(hdc, RGB(0x00,0x00,0xff));
	SetTextColor(hdc, RGB(0xff,0xff,0x00));
	TextOut(hdc, dwX, dwY, pString, lstrlen(pString));
	TextOut(hdc, 0, D_00DE67E8 - 32, D_00E28C48, lstrlen(D_00E28C48));
}

//WORLD MAP[BEGIN][callback]
void C_0074BAF5(struct t_aa0 *bp08) {
	struct {
		int dwGrMode;//local_3
		int i;//local_2
		int local_1;
	}lolo;

	dx_dbg_puts("-=-=[START OF WORLD MAP!!!]=-=-\n");
	//-- --
	if(!D_00E045EC) {
		lolo.dwGrMode = C_00404D80();//Get "Graphics/Mode" Key
		lolo.local_1 = 0x4000|0x40|0x10|1;//0x4051
		C_006833DE(&lolo.local_1);//anm:set some flags?
		C_0075E6BD();//wm:reset SFX?
		D_00E2C41C =
		D_00E2C420 = 0;
		if(lolo.dwGrMode == 2) {
			D_00E2C424 = 0;
			D_00E2C428 = 0;
			D_00DE69D8 = 2;
			D_00DE6900 = 2.0f;
			D_00DE68F8 = 640;
			D_00DE67E8 = 480;
			C_006F193E(2);//menu:set graphic mode[world map]
		} else {
			if(lolo.dwGrMode == 1) {
				D_00E2C424 = 160;
				D_00E2C428 = 120;
				C_006F193E(1);//menu:set graphic mode[world map]
			} else {
				D_00E2C424 = 0;
				D_00E2C428 = 0;
				C_006F193E(0);//menu:set graphic mode[world map]
			}
			D_00DE69D8 = 1;
			D_00DE6900 = 1.0f;
			D_00DE68F8 = 320;
			D_00DE67E8 = 240;
		}
		C_00661966(1);//psx:set LH/RH flag?
		C_006619AA(240.0);//psx:D_0090AAF0->f_08 = (double)?
		PAD_setRepeatParams(200, 50);
		C_0075AB50();//wmdefine:init?
		D_00DE69E4 =
		D_00DE69DC =
		D_00DE69E0 = 0;//force init/reset
		for(lolo.i = 0; lolo.i < 3; lolo.i ++)
			D_00E2C430[lolo.i].f_24 = 0;
		for(lolo.i = 0; lolo.i < 0xd; lolo.i ++)
			D_00E2C808[lolo.i].f_24 = 0;
		g_drv_viewport(D_00E2C424, D_00E2C428, D_00DE68F8, D_00DE67E8, bp08);
		D_0096B414 = -1;
		bp08->fNear = 500.0f;
		bp08->fFar = 40000.0f;
	}
	//-- --
	D_00DE6938 = bp08->f_030 / D_00969958;
	D_00DE69EC = 0;
	D_00DE69F8 = 0;
	C_0074C973(1);//wm:set "isRendering"?
	C_0074C980(1);//wm:set "allowsFrameSkip"?
	C_00753879();//fade in/out related(2)?
	C_0075389C();//fade in/out related(4)?
	D_00DE6908 = bp08->f_030 / D_00969960;
}

//WORLD MAP:clean?
void C_0074BD50() {
	if(D_00E045EC) {
		C_0075A921();//wmfile:clean textures & models?
		C_00759EEA();//wmfile:release 3d models[world]?
		C_0075A01D();//wmfile:release 3d models[chara]?
		C_0075ABF3();//wmdefine:clean?
		C_0075EB1E();//wm:clean lights?
	}
}

//WORLD MAP[END][callback]
void C_0074BD77(struct t_aa0 *_p08) {
	if(!D_00E045EC) {
		C_0075A921();//wmfile:clean textures & models?
		C_00759EEA();//wmfile:release 3d models[world]?
		C_0075A01D();//wmfile:release 3d models[chara]?
		C_0075ABF3();//wmdefine:clean?
		C_0075EB1E();//wm:clean lights?
		//-- --
		if(D_00CC15D0 != D_00CC15D8 || D_00CC15D8 == 0) {
			;
		} else {
			D_00CC15D8 = 0;
			D_00CC15DC = 0;
		}
		D_00CC0974 = D_00DE6940;
		D_00CC15D0 = D_00CC0D88.wEventParam;//set field id
		switch(D_00CC1644) {
			case 0://go to field
				D_00CC0D84 = MAIN_STATE_03;//(world map)
				D_00CBF9DC = MAIN_STATE_01;//(field)
			break;
			case 1://go to battle
				D_00CC0D84 = MAIN_STATE_03;//(world map)
				D_00CBF9DC = MAIN_STATE_17;//swirl(before battle)
			break;
			case 2://to ending sequence?
				D_00CC0D88.bEventType = FIELD_EVENT_0A;
			break;
		}//end switch
	}
	dx_dbg_puts("-=-=[END OF WORLD MAP!!!]=-=-\n");
}

void C_0074C7E4(struct t_aa0 *);//world.tempo?

//WORLD MAP[UPDATE][callback]
void C_0074BE49(struct t_aa0 *bp08) {
	struct {
		char __00[0xd0];
		int local_5_unused;
		struct fBGRA local_4;
	}lolo;

	lolo.local_5_unused = 1;
	//-- --
	if(D_00DE69F8)
		C_0074C7E4(bp08);//world.tempo?
	if(D_00DE69EC)
		D_00DE69F8 = 0;
	else
		D_00DE69F8 = 1;
	TS_getCPUTimeStamp(&D_00DE67F0);
	//-- --
	PAD_refresh(0);
	C_00744B13();//sound:refresh trans?
	C_00666DDD(bp08);//reset "transparent heap"
	C_006656A4(bp08);//dx_3d2d:reset[sort related]?
	C_00666DA3(bp08);//calls "instance:reset"
	C_00666DC0(bp08);//calls "dx_sfx:reset heaps"
	lolo.local_4.r = 0;
	lolo.local_4.g = 0;
	lolo.local_4.b = 0;
	lolo.local_4.a = 1.0f;
	g_drv_clearColor(&lolo.local_4, bp08);
	g_drv_clear(1, 1, 1, bp08);
	if(g_drv_beginScene(0, bp08)) {
		if(D_00DE69EC)
			C_0074C973(0);//wm:set "isRendering"?
		else
			C_0074C973(1);//wm:set "isRendering"?
		//-------------
		//-- LAYER 0 --
		//-------------
		//-- main render --
		D_00DE6940 = C_0074DB8C(&D_00CC1644, &D_00CC1648, &D_00CC0D80, 0);
		D_00DE68FC();//wm render callback
		C_00666DF4(bp08);//render "transparent heap"
		C_006656D1(bp08);//dx_3d2d:render[sort related]?
		//-------------
		//-- LAYER 1 --
		//-------------
		//-- fade in/out? --
		C_00660E95(1, bp08);//G_DRV_84:change_layer?
		C_0066E641(D_00E2C3F4[0], bp08);//dx_spr:render
		//-- --
		if(1) {
			if(D_00DE69EC) {
				D_00DE69F8 = 1;
				D_00DE69EC = 0;
				C_0074C973(1);//wm:set "isRendering"?
				bp08->f_040 += 1.0;
				C_00666DDD(bp08);//reset "transparent heap"
				C_006656A4(bp08);//dx_3d2d:reset[sort related]?
				C_00666DA3(bp08);//calls "instance:reset"
				C_00666DC0(bp08);//calls "dx_sfx:reset heaps"
				TS_getCPUTimeStamp(&D_00DE67F0);
				PAD_refresh(0);
				//-- main render --
				D_00DE6940 = C_0074DB8C(&D_00CC1644, &D_00CC1648, &D_00CC0D80, 0);
				D_00DE68FC();//wm render callback
				C_00666DF4(bp08);//render "transparent heap"
				C_006656D1(bp08);//dx_3d2d:render[sort related]?
				//-------------
				//-- LAYER 1 --
				//-------------
				//-- fade in/out? --
				C_00660E95(1, bp08);//G_DRV_84:change_layer?
				C_0066E641(D_00E2C3F4[0], bp08);//dx_spr:render
				//-- --
			}
		}
		g_drv_endScene(bp08);
	}
	//-- --
	if(D_00DE69DC) {
		//*** to main dispatcher ***
		if(0);
		if(0);
		D_00DE69DC =
		D_00DE69E0 = 0;//force init/reset
		C_00666D47(&D_00DE6918, bp08);//get main loop callbacks?
		D_00DE6918.f_14 = C_00409DF1;//MainDispatcher[ONMOUSE][callback]
		D_00DE6918.f_18 = C_00409E39;//MainDispatcher[ONKEY][callback]
		D_00DE6918.f_10 = C_004090E6;//MainDispatcher[UPDATE][callback]
		D_00DE6918.f_08 = C_00408FA6;//MainDispatcher[BEGIN][callback]
		D_00DE6918.f_0c = C_004090C7;//MainDispatcher[END][callback]
		C_00666CF2(&D_00DE6918, bp08);//set main loop callbacks?
	} else if(D_00E045EC) {
		//*** to menu system ***
		C_00666D47(&D_00DE6918, bp08);//get main loop callbacks?
		D_00DE6918.f_14 = C_006CC619;//MENU SYSTEM[ONMOUSE][callback]
		D_00DE6918.f_18 = C_006CC61E;//MENU SYSTEM[ONKEY][callback]
		D_00DE6918.f_10 = C_006CC623;//MENU SYSTEM[UPDATE][callback]
		D_00DE6918.f_08 = C_006CD3B0;//MENU SYSTEM[BEGIN][callback]
		D_00DE6918.f_0c = C_006CD5B3;//MENU SYSTEM[END][callback]
		C_00666CF2(&D_00DE6918, bp08);//set main loop callbacks?
	}
}

void C_0074C6B0(struct t_aa0 *);//render 3d objects?

//wm:render_0(surface)(callback)
void C_0074C179() {
	struct {
		unsigned i;//local_2
		struct t_aa0 *local_1;
	}lolo;

	lolo.local_1 = C_00676578();
	if(C_0074C969() == 0)//wm:get "isRendering"?
		return;
	//-------------
	//-- LAYER 0 --
	//-------------
	C_00660E95(0, lolo.local_1);//G_DRV_84:change_layer?
	//-- terrain mesh? -- "sea"
	for(lolo.i = 0; lolo.i < 0x16; lolo.i ++) {
		C_0066E641(D_00E2BBD8[D_0096B418[lolo.i]], lolo.local_1);//dx_spr:render
	}
	//-- terrain mesh? -- "land"
	for(lolo.i = 0; lolo.i < D_00E2C420; lolo.i ++) {
		if(!C_007592E0(lolo.i))//wmfile:texture is animated?
			C_0066E641(D_00E2BBD8[lolo.i], lolo.local_1);//dx_spr:render
	}
	//-- background color --
	C_0066E641(D_00E2C3E8, lolo.local_1);//dx_spr:render
	g_drv_setRenderState(G_DRV_STATE_02, 0, lolo.local_1);
	//-- midgar zolom --
	C_0066E641(D_00E2C414, lolo.local_1);//dx_spr:render
	//-------------
	//-- LAYER 1 -- backround sky?
	//-------------
	C_00660E95(1, lolo.local_1);//G_DRV_84:change_layer?
	C_0066E641(D_00E2C3EC, lolo.local_1);//dx_spr:render
	C_0066E641(D_00E2C3F0, lolo.local_1);//dx_spr:render
	//-------------
	//-- LAYER 1 -- shadows?
	//-------------
	C_00660E95(1, lolo.local_1);//G_DRV_84:change_layer?
	g_drv_setRenderState(G_DRV_STATE_02, 0, lolo.local_1);
	C_0066E641(D_00E2C400, lolo.local_1);//dx_spr:render
	//-------------
	//-- LAYER 0 --
	//-------------
	//-- 3d objects? --
	C_00660E95(0, lolo.local_1);//G_DRV_84:change_layer?
	C_0074C6B0(lolo.local_1);//render 3d objects?
	//-------------
	//-- LAYER 1 --
	//-------------
	//-- map? --
	C_00660E95(1, lolo.local_1);//G_DRV_84:change_layer?
	C_0066E641(D_00E2C3E0, lolo.local_1);//dx_spr:render
	C_0066E641(D_00E2C3DC, lolo.local_1);//dx_spr:render
	C_0066E641(D_00E2C3D8, lolo.local_1);//dx_spr:render
	//-- vehicule fx? --
	g_drv_setRenderState(G_DRV_STATE_02, 0, lolo.local_1);
	C_0066E641(D_00E2C404[0], lolo.local_1);//dx_spr:render
	C_0066E641(D_00E2C404[1], lolo.local_1);//dx_spr:render
	C_0066E641(D_00E2C404[2], lolo.local_1);//dx_spr:render
	C_0066E641(D_00E2C404[3], lolo.local_1);//dx_spr:render
	//-- --
	//
	//-- radar? --
	C_0066E641(D_00E2C3E4, lolo.local_1);//dx_spr:render
	//-- dialog? --
	if(D_00E3610C) {
		C_006F19F3(0);//set dialog y offset?
		C_006EBF2C(D_00CFF5B8, 1, C_0074C9A5() == 0);
		C_006ECA68();
		D_00E3610C = 0;
		g_drv_viewport(D_00E2C424, D_00E2C428, D_00DE68F8, D_00DE67E8, lolo.local_1);
	}
}

//wm:render_2(undersea)(callback)
void C_0074C3F0() {
	struct {
		unsigned i;//local_2
		struct t_aa0 *local_1;
	}lolo;

	lolo.local_1 = C_00676578();
	if(C_0074C969() == 0)//wm:get "isRendering"?
		return;
	//-------------
	//-- LAYER 0 --
	//-------------
	C_00660E95(0, lolo.local_1);//G_DRV_84:change_layer?
	//-- terrain mesh? --
	for(lolo.i = 0; lolo.i < D_00E2C420; lolo.i ++) {
		C_0066E641(D_00E2BBD8[lolo.i], lolo.local_1);//dx_spr:render
	}
	//-- 3d objects? --
	//
	C_0074C6B0(lolo.local_1);//render 3d objects?
	//-------------
	//-- LAYER 1 --
	//-------------
	//-- map? --
	C_00660E95(1, lolo.local_1);//G_DRV_84:change_layer?
	C_0066E641(D_00E2C3E0, lolo.local_1);//dx_spr:render
	C_0066E641(D_00E2C3DC, lolo.local_1);//dx_spr:render
	C_0066E641(D_00E2C3D8, lolo.local_1);//dx_spr:render
	//-- vehicule fx? --
	g_drv_setRenderState(G_DRV_STATE_02, 0, lolo.local_1);
	C_0066E641(D_00E2C404[0], lolo.local_1);//dx_spr:render
	C_0066E641(D_00E2C404[1], lolo.local_1);//dx_spr:render
	C_0066E641(D_00E2C404[2], lolo.local_1);//dx_spr:render
	C_0066E641(D_00E2C404[3], lolo.local_1);//dx_spr:render
	//-- shadows? --
	C_0066E641(D_00E2C400, lolo.local_1);//dx_spr:render
	//-- radar? --
	C_0066E641(D_00E2C3E4, lolo.local_1);//dx_spr:render
	//-- dialog? --
	if(D_00E3610C) {
		C_006F19F3(0);//set dialog y offset?
		C_006EBF2C(D_00CFF5B8, 1, C_0074C9A5() == 0);
		C_006ECA68();
		D_00E3610C = 0;
		g_drv_viewport(D_00E2C424, D_00E2C428, D_00DE68F8, D_00DE67E8, lolo.local_1);
	}
}

//wm:render_3(snowfield)(callback)
void C_0074C589() {
	struct {
		unsigned i;//local_2
		struct t_aa0 *local_1;
	}lolo;

	lolo.local_1 = C_00676578();
	if(C_0074C969() == 0)//wm:get "isRendering"?
		return;
	//-------------
	//-- LAYER 0 --
	//-------------
	C_00660E95(0, lolo.local_1);//G_DRV_84:change_layer?
	//-- terrain mesh? --
	for(lolo.i = 0; lolo.i < D_00E2C420; lolo.i ++) {
		C_0066E641(D_00E2BBD8[lolo.i], lolo.local_1);//dx_spr:render
	}
	//-- 3d objects? --
	C_00660E95(0, lolo.local_1);//G_DRV_84:change_layer?
	C_0074C6B0(lolo.local_1);//render 3d objects?
	//-------------
	//-- LAYER 1 --
	//-------------
	C_00660E95(1, lolo.local_1);//G_DRV_84:change_layer?
	//-- snow --
	C_0066E641(D_00E2C3F4[1], lolo.local_1);//dx_spr:render
	C_0066E641(D_00E2C3F4[2], lolo.local_1);//dx_spr:render
	//-- shadows? --
	C_0066E641(D_00E2C400, lolo.local_1);//dx_spr:render
	//-- dialog? --
	if(D_00E3610C) {
		C_006F19F3(0);//set dialog y offset?
		C_006EBF2C(D_00CFF5B8, 1, C_0074C9A5() == 0);
		C_006ECA68();
		D_00E3610C = 0;
		g_drv_viewport(D_00E2C424, D_00E2C428, D_00DE68F8, D_00DE67E8, lolo.local_1);
	}
}

//render 3d objects?
void C_0074C6B0(struct t_aa0 *bp08) {
	struct {
		int i;//local_2
		int dwCount;//local_1
	}lolo;

	if(C_0074C969() == 0)//wm:get "isRendering"?
		return;
	//-- main chara --
	if(D_00E2C430[0].f_24)
		C_006840DA(D_00E2C430[0].dwAnimFrame, D_00E2C430[0].f_3c[D_00E2C430[0].wAnim], &(D_00E2C430[0].f_44), D_00E2C430[0].f_40, bp08);//anm:..
	//-- --
	lolo.dwCount = C_00759EE0();//wmfile:get 3d models count[world]?
	for(lolo.i = 0; lolo.i < lolo.dwCount; lolo.i ++) {
		if(D_00E2C808[lolo.i].f_24) {
			if(D_00E2C808[lolo.i].dwIsTransparent)
				C_00660E95(1, bp08);//G_DRV_84:change_layer?
			C_006840DA(D_00E2C808[lolo.i].dwAnimFrame, D_00E2C808[lolo.i].f_3c[D_00E2C808[lolo.i].wAnim], &(D_00E2C808[lolo.i].f_44), D_00E2C808[lolo.i].f_40, bp08);//anm:..
			if(D_00E2C808[lolo.i].dwIsTransparent)
				C_00660E95(0, bp08);//G_DRV_84:change_layer?
		}
	}//end for
}

int C_0074C98D(void);//get "allowsFrameSkip"?

//world.tempo?
//(credits, battle, world, field, swirl, menu, condor, submarine and chocobo tempo are very close)
void C_0074C7E4(struct t_aa0 *bp08) {
//#pragma pack(1)
	struct {
		LARGE_INTEGER local_4;
		double local_2;
	}lolo;
//#pragma pack()

	lolo.local_2 = 0;
	TS_getCPUTimeStamp(&D_00DE6910);
	TS_diff(&D_00DE6910, &D_00DE67F0, &lolo.local_4);
	lolo.local_2 = TS_toDouble(&lolo.local_4) - 358484.5;
	if(!D_00DE69EC) {
		if(lolo.local_2 <= D_00DE6938) {
			while(lolo.local_2 < D_00DE6938) {
				TS_getCPUTimeStamp(&D_00DE6910);
				TS_diff(&D_00DE6910, &D_00DE67F0, &lolo.local_4);
				lolo.local_2 = TS_toDouble(&lolo.local_4);
			}//end while
			D_00DE69EC = 0;
			D_00DE69F0 = 0;
		} else {
			if(lolo.local_2 <= D_00DE6908) {
				D_00DE69EC = 0;
			} else {
				D_00DE69F0 = lolo.local_2 - D_00DE6908;
				if(C_0074C98D())//get "allowsFrameSkip"?
					D_00DE69EC = 1;
				else
					D_00DE69EC = 0;
			}
		}
	} else {
		while(lolo.local_2 < D_00DE6908 - D_00DE69F0) {
			TS_getCPUTimeStamp(&D_00DE6910);
			TS_diff(&D_00DE6910, &D_00DE67F0, &lolo.local_4);
			lolo.local_2 = TS_toDouble(&lolo.local_4);
		}//end while
		D_00DE69EC = 0;
		D_00DE69F0 = 0;
	}
}

//wm:get "isRendering"?
int C_0074C969() {
	return D_0096994C;
}

//wm:set "isRendering"?
void C_0074C973(int bp08) {
	D_0096994C = bp08;
}

//wm:set "allowsFrameSkip"?
void C_0074C980(int bp08) {
	D_00969950 = bp08;
}

//get "allowsFrameSkip"?
int C_0074C98D() {
	return D_00969950;
}
