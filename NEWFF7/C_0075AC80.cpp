/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//WORLD MAP -- 

#include "ff7.h"
#include "wm_data.h"
////////////////////////////////////////
struct t_wm_local_54 {//size 0x54
	/*00*/struct t_wm_local_54 *pNext;
	/*04*/struct VECTOR f_04;
	/*04*/struct SVECTOR f_14;
	/*1c*/unsigned char f_1c;
	/*1d*/unsigned char f_1d;
	/*1e*/unsigned char f_1e;//some orientation flag?
	/*1f*/unsigned char f_1f;
	//-- --
	/*20*/short f_20;
	/*22*/char __22[2];
	/*24*/struct t_wm_local_30 f_24;
};

struct t_wm_local_spr_0c {//size 0xc
	/*00*/unsigned char f_00;
	/*01*/unsigned char f_01;
	/*02*/unsigned char bWidth,bHeight;
	/*04*/unsigned char f_04,f_05,f_06,f_07;//x1,y1,x2,y2
	/*08*/short clut;
	/*0a*/char __0a,__0b;
};
////////////////////////////////////////
unsigned char *D_00E2D608;
struct t_wm_local_54 *D_00E2D60C;
//char 00E2D610[0x8000]
unsigned D_00E35610;
//00E35614
char D_00E35638[2][4];
struct t_wm_local_54 *D_00E35640;
//00E35644
struct t_wm_local_54 *D_00E35648;
int D_00E3564C;//previous song?
struct t_wm_local_54 *D_00E35650;
int D_00E35654;//music related flag
int D_00E35658;//current song?
//00E3565C
struct t_wm_local_54 D_00E35660[0x20];
//00E360E0
int D_00E360EC;
//D_00E360F0
////////////////////////////////////////
void C_0075AC80() {
	int i;

	for(i = 0; i < 0x1f; i ++)
		D_00E35660[i].pNext = &(D_00E35660[i + 1]);
	D_00E35660[i].pNext = 0;
	D_00E35640 = &(D_00E35660[0]);
	D_00E35648 =
	D_00E35650 =
	D_00E2D60C = 0;
	D_00E35610 = 0;
	for(i = 0; i < 2; i ++)
		D_00E35638[i][2] = 0;
}

void C_0075B8F3(short, short, short, int);

//wm:terrain, vehicle 2D fx?
void C_0075AD28(struct t_local_unknown_c0 *bp08, int dwDoAnim/*bp0c*/) {
	struct {//x68
		//local_23 and above for compiler
		DECL_struct_MATRIX(local_22);
		struct VECTOR local_14;
		DECL_short(local_10);
		struct SVECTOR local_9;
		int local_7;
		int local_6;
		int local_5;
		int local_4;
		int local_3;
		int dwTerrainType;//local_2
		int dwFlags_unused;//local_1
	}lolo;

	lolo.dwTerrainType = bp08->wTerrainInfo & 0x1f;
	D_00E2D200 =
	lolo.local_3 = bp08->f_3c + bp08->f_3e;
	D_00E2D1E0 = bp08->sPrevPos;

	D_00E2D1F0.vx = D_00E2D1F0.vy = D_00E2D1F0.vz = 0;
	D_00E2D1F8.vx = D_00E2D1F8.vy = D_00E2D1F8.vz = 0;

	//-- HIGHWIND --
	if(bp08->bModelType == WM_MODELID_03) {//else 0075B13E
		//-- render reactor flames --
		if(
			dwDoAnim &&
			C_00768C59() &&//wm:highwind has reactor?
			C_0074D504() >= 0 &&//wm:get "highwind" state?
			/*lolo.local_23*/inline_abs(bp08->sPos.vx - bp08->sPrevPos.vx) + /*lolo.local_24*/inline_abs(bp08->sPos.vz - bp08->sPrevPos.vz) > 100
		) {//else 0075AFEE
			lolo.local_6 = D_00E35610 % 3;
			lolo.local_7 = D_00E35610 % 6;
			lolo.local_4 = C_0074D319();//wm:get camera tilt angle?
			lolo.local_5 = lolo.local_4 * 4 + lolo.local_3;
			D_00E2D1E0 = bp08->sPos;
			D_00E2D1F8.vx = 300;
			D_00E2D1F8.vy = 400 - max(0, lolo.local_4);
			D_00E2D1F8.vz = -90;
			C_0075B8F3(lolo.local_5, 0, ((lolo.local_4 * 4 < 200)?0x24:0x27) + lolo.local_6, 0);
			C_0075B8F3(lolo.local_5, 0, lolo.local_7 + 50, 0);

			D_00E2D1F8.vx = -300;
			D_00E2D1F8.vy = 400 + min(0, lolo.local_4);
			C_0075B8F3(lolo.local_5, 0, ((lolo.local_4 * 4 > -200)?0x27:0x24) + lolo.local_6, 0);
			C_0075B8F3(lolo.local_5, 0, lolo.local_7 + 50, 0);

			D_00E2D1F8.vx = 0;
			D_00E2D1F8.vy = 300;
			D_00E2D1F8.vz = -300;
			C_0075B8F3(lolo.local_5, 0, lolo.local_6 + 0x2a, 0);
			C_0075B8F3(lolo.local_5, 0, lolo.local_7 + 50, 0);
		}
		//-- water splash --
		if(
			lolo.dwTerrainType >= 3 && lolo.dwTerrainType <= 7 &&
			bp08->sPos.vy < bp08->f_42 + 1000 &&
			(bp08->bAnimFrame % 3) == 0
		) {//else 0075B139
			D_00E2D1F8.vx = D_00E2D1F8.vy = D_00E2D1F8.vz = 0;
			D_00E2D1F0.vx = (bp08->sPos.vx - bp08->sPrevPos.vx) >> 1;
			D_00E2D1F0.vy = 50;
			D_00E2D1F0.vz = (bp08->sPos.vz - bp08->sPrevPos.vz) >> 1;
			if(/*lolo.local_25*/inline_abs(D_00E2D1F0.vx) + /*lolo.local_26*/inline_abs(D_00E2D1F0.vz) > 0x19) {//else 0075B139
				D_00E2D1E0.vx -= D_00E2D1F0.vx * 4;
				D_00E2D1E0.vy = bp08->f_42;
				D_00E2D1E0.vz -= D_00E2D1F0.vz * 4;
				C_0075B8F3(0, 0x700, 0, 0);
				C_0075B8F3(0, 0x900, 1, 0);
			}
		}
		return;//goto 0075B8EF
	}
	//-- CHOCOBO --
	if(
		dwDoAnim &&
		C_0076192A(bp08->bModelType) &&//wm:is model a chocobo?
		(bp08->bAnimFrame == 2 || bp08->bAnimFrame == 0xe) &&
		((0x1110701 >> lolo.dwTerrainType) & 1)
	) {//else 0075B21D
		D_00E2D1F0.vx = bp08->sPos.vx - bp08->sPrevPos.vx;
		D_00E2D1F0.vy = 100;
		D_00E2D1F0.vz = bp08->sPos.vz - bp08->sPrevPos.vz;
		D_00E2D1E0.vx -= D_00E2D1F0.vx;
		D_00E2D1E0.vy += 100;
		D_00E2D1E0.vz -= D_00E2D1F0.vz;
		C_0075B8F3(0, 0x800, (lolo.dwTerrainType != 0xa) + 5, 50);
		return;//goto 0075B8EF
	}
	//-- SNOW --
	if(
		lolo.dwTerrainType == 0xa &&
		C_0074D330() != 3 &&//wm:get current map id?
		dwDoAnim
	) {//else 0075B31D
		if(C_00761805(7, bp08->bModelType) && (bp08->bAnimFrame == 1 || bp08->bAnimFrame == 8)) {//else 0075B2B5
			//human
			D_00E2D1F8.vz = 0x28;
			C_0075B8F3(((bp08->bAnimFrame >> 3)?0x400:0xc00) + lolo.local_3, 0, (bp08->bAnimFrame >> 3)?2:3, 0);
		} else if(
			C_0076192A(bp08->bModelType) &&//wm:is model a chocobo?
			(bp08->bAnimFrame == 1 || bp08->bAnimFrame == 0xd)
		) {//else 0075B318
			//chocobo
			D_00E2D1F8.vz = 120;
			C_0075B8F3(((bp08->bAnimFrame >> 3)?0xc00:0x400) + lolo.local_3, 0, 4, 0);
		}
		return;//goto 0075B8EF
	}
	//-- HUMAN desert dust --
	if(
		C_00761805(7, bp08->bModelType) &&
		((lolo.dwTerrainType & 0xf) == 8 || lolo.dwTerrainType == 0x1c) &&
		(bp08->bAnimFrame == 1 || bp08->bAnimFrame == 8)
	) {//else 0075B38D
		D_00E2D1F0.vx = 0;
		D_00E2D1F0.vy = 20;
		D_00E2D1F0.vz = 0;
		C_0075B8F3(0, 0, 8, 0);
		return;//goto 0075B8EF
	}
	//-- TINY BRONCO --
	if(
		C_00761805(0x20, bp08->bModelType) &&
		C_00761FE8() == 0
	) {//else 0075B404
		if(dwDoAnim && (bp08->bAnimFrame % 3) == 0) {//else 0075B3FF
			D_00E2D1F8.vx = 400;
			C_0075B8F3(lolo.local_3, 0, 9, 0);

			D_00E2D1F8.vx = -500;
			C_0075B8F3(lolo.local_3, 0, 9, 0);
		}
		return;//goto 0075B8EF
	}
	//-- HUMAN|CHOCOBO dust --
	if(
		dwDoAnim &&
		(C_00761805(7, bp08->bModelType) || C_0076192A(bp08->bModelType)) &&
		(lolo.dwTerrainType == 1 || lolo.dwTerrainType == 0x19) &&
		(bp08->bAnimFrame % 3) == 0
	) {//else 0075B47C
		D_00E2D1E0.vy += 300;
		C_0075B8F3(lolo.local_3, 0, 0xa, 0);
		return;//goto 0075B8EF
	}
	//-- HUMAN swamp splash --
	if(
		C_00761805(7, bp08->bModelType) &&
		lolo.dwTerrainType == 7
	) {//else 0075B4F3
		if(dwDoAnim && (bp08->bAnimFrame == 1 || bp08->bAnimFrame == 8)) {
			D_00E2D1F0.vx = bp08->sPos.vx - bp08->sPrevPos.vx;
			D_00E2D1F0.vz = bp08->sPos.vz - bp08->sPrevPos.vz;
			C_0075B8F3(0, 0x800, 0xc, 0);
		}
		return;//goto 0075B8EF
	}
	//-- CHOCOBO water splash --
	if(
		dwDoAnim &&
		C_0076192A(bp08->bModelType) &&//wm:is model a chocobo?
		lolo.dwTerrainType >= 3 && lolo.dwTerrainType <= 7 &&
		(bp08->bAnimFrame == 1 || bp08->bAnimFrame == 0xd)
	) {//else 0075B553
		D_00E2D1F8.vz = -100;
		C_0075B8F3(lolo.local_3, 0, 0xd, 0);
		return;//goto 0075B8EF
	}
	//-- BUGGY --
	if(dwDoAnim && bp08->bModelType == WM_MODELID_06) {//else 0075B76C
		if(
			(lolo.dwTerrainType == 1 || lolo.dwTerrainType == 0x19) &&
			(bp08->bAnimFrame % 3) == 0
		) {//else 0075B5B5
			D_00E2D1E0.vy += 300;
			C_0075B8F3(0, 0, 0xe, 0);
		} else if((bp08->bAnimFrame % 3) == 0) {
			lolo.local_10 = (lolo.dwTerrainType != 4)?0x10:0xf;

			D_00E2D1F0.vy = 20;
			D_00E2D1F8.vy = 100;
			D_00E2D1F8.vz = -300;
			D_00E2D1F8.vx = 150;

			lolo.local_22.t[0] =
			lolo.local_22.t[1] =
			lolo.local_22.t[2] = 0;

			psx_SetTransMatrix(&lolo.local_22);

			lolo.local_22.m[0][0] =
			lolo.local_22.m[1][1] =
			lolo.local_22.m[2][2] = 0x1000;

			lolo.local_22.m[0][1] =
			lolo.local_22.m[0][2] =
			lolo.local_22.m[1][0] =
			lolo.local_22.m[1][2] =
			lolo.local_22.m[2][0] =
			lolo.local_22.m[2][1] = 0;

			C_0076312D(&lolo.local_9);
			psx_RotMatrixY(lolo.local_3, &lolo.local_22);
			psx_RotMatrixX(lolo.local_9.vx, &lolo.local_22);
			psx_RotMatrixZ(lolo.local_9.vz, &lolo.local_22);
			psx_SetRotMatrix(&lolo.local_22);
			psx_RotTrans(&D_00E2D1F8, &lolo.local_14, &lolo.dwFlags_unused);

			D_00E2D1F8.vx = lolo.local_14.vx;
			D_00E2D1F8.vy = lolo.local_14.vy;
			D_00E2D1F8.vz = lolo.local_14.vz;
			C_0075B8F3(0, 0, lolo.local_10, 0xa);

			psx_SetRotMatrix(&lolo.local_22);

			D_00E2D1F8.vx = -150;
			D_00E2D1F8.vy = 100;
			D_00E2D1F8.vz = -300;
			psx_RotTrans(&D_00E2D1F8, &lolo.local_14, &lolo.dwFlags_unused);
			D_00E2D1F8.vx = lolo.local_14.vx;
			D_00E2D1F8.vy = lolo.local_14.vy;
			D_00E2D1F8.vz = lolo.local_14.vz;

			C_0075B8F3(0, 0, lolo.local_10, 0xa);
		}
		return;//goto 0075B8EF
	}
	//-- SUBMARINE --
	if(dwDoAnim && bp08->bModelType == WM_MODELID_13) {//else 0075B811
		if(C_0074D330() == 2 && (bp08->bAnimFrame & 7) == 0) {//wm:get current map id?//else 0075B7D3
			//undersea
			D_00E2D1F8.vy = 200;
			D_00E2D1F8.vz = -400;
			D_00E2D1F0.vy = 50;
			C_0075B8F3(lolo.local_3, lolo.local_3, 0x11, 0);
		} else if(C_0074D330() == 0) {//wm:get current map id?
			//surface
			D_00E2D1F8.vy = 0xf0;
			D_00E2D1F8.vz = -500;
			C_0075B8F3(lolo.local_3, 0, (D_00E35610 & 3) + 0x2d, 0);
		}
		return;//goto 0075B8EF
	}
	//-- EMERALD WEAPON --
	if(dwDoAnim && bp08->bModelType == WM_MODELID_30 && (bp08->bAnimFrame & 0xf) == 0) {//else 0075B8B1
		D_00E2D1F8.vx = 600;
		D_00E2D1F8.vy = 1000;
		D_00E2D1F8.vz = -400;
		D_00E2D1F0.vy = 50;
		C_0075B8F3(lolo.local_3, lolo.local_3, 0x11, 0);

		D_00E2D1F8.vx = -600;
		D_00E2D1F8.vy = 1000;
		D_00E2D1F8.vz = -400;
		D_00E2D1F0.vy = 50;
		C_0075B8F3(lolo.local_3, lolo.local_3, 0x11, 0);
		return;//goto 0075B8EF
	}
	//-- WARSHIP --
	if(dwDoAnim && bp08->bModelType == WM_MODELID_08 && (bp08->bAnimFrame & 3) == 0) {//else 0075B8EF
		D_00E2D1F8.vz = -700;
		C_0075B8F3(lolo.local_3, 0, 0x12, 0);
		return;
	}
//0075B8EF
}
//-- song ids --
unsigned char D_0096D598[] = {0x0D,0x33,0x2F,0x07,0x2C,0x00,0x00,0x00};
unsigned char D_0096D5A0[] = {0x47,0x33,0x2F,0x07,0x2C,0x46,0x48,0x00};
unsigned char D_0096D5A8[] = {0x55,0x00,0x00,0x07,0x00,0x00,0x00,0x00};
unsigned char D_0096D5B0[] = {0x4D,0x00,0x00,0x07,0x00,0x00,0x00,0x00};
//-- index in D_0096D6A8,flag,unused,unused --
unsigned char D_0096D5B8[][4] = {
	{0x00,1,0,0},{0x05,1,0,0},{0x0A,1,0,0},{0x0B,1,0,0},
	{0x0C,1,0,0},{0x0D,0,0,0},{0x10,0,0,0},{0x13,1,0,0},
	{0x19,0,0,0},{0x1E,1,0,0},{0x22,0,0,0},{0x27,1,0,0},
	{0x2A,1,0,0},{0x2D,0,0,0},{0x31,0,0,0},{0x35,0,0,0},
	{0x38,0,0,0},{0x3C,0,0,0},{0x40,1,0,0},{0x14,0,0,0},
	{0x44,0,0,0},{0x4A,0,0,0},{0x4E,0,0,0},{0x4F,0,0,0},
	{0x52,1,0,0},{0x56,1,0,0},{0x5A,1,0,0},{0x5E,1,0,0},
	{0x62,1,0,0},{0x63,1,0,0},{0x64,1,0,0},{0x65,1,0,0},
	{0x66,1,0,0},{0x67,1,0,0},{0x68,1,0,0},{0x69,1,0,0},
	{0x6A,0,0,0},{0x6B,0,0,0},{0x6C,0,0,0},{0x6D,0,0,0},
	{0x6E,0,0,0},{0x6F,0,0,0},{0x70,0,0,0},{0x71,0,0,0},
	{0x72,0,0,0},{0x73,1,0,0},{0x74,1,0,0},{0x75,1,0,0},
	{0x76,1,0,0},{0x77,0,0,0},{0x7B,0,0,0},{0x7C,0,0,0},
	{0x7D,0,0,0},{0x7E,0,0,0},{0x7F,0,0,0},{0x80,0,0,0},
	{0x81,0,0,0},{0x84,0,0,0},{0x88,0,0,0},{0x00,0,0,0}
};

struct t_wm_local_spr_0c D_0096D6A8[] = {
	{0x81,0x01,0x20,0x20,0x00,0x20,0x0F,0x2F,0x0000,0x00,0x00},
	{0x01,0x01,0x20,0x20,0x10,0x20,0x1F,0x2F,0x0000,0x00,0x00},
	{0x01,0x01,0x20,0x20,0x20,0x20,0x2F,0x2F,0x0000,0x00,0x00},
	{0x02,0x01,0x20,0x20,0x30,0x20,0x3F,0x2F,0x0000,0x00,0x00},
	{0x02,0x01,0x20,0x20,0x40,0x20,0x4F,0x2F,0x0000,0x00,0x00},
	{0x81,0x01,0x20,0x20,0x0F,0x20,0x00,0x2F,0x0000,0x00,0x00},
	{0x01,0x01,0x20,0x20,0x1F,0x20,0x10,0x2F,0x0000,0x00,0x00},
	{0x01,0x01,0x20,0x20,0x2F,0x20,0x20,0x2F,0x0000,0x00,0x00},
	{0x02,0x01,0x20,0x20,0x3F,0x20,0x30,0x2F,0x0000,0x00,0x00},
	{0x02,0x01,0x20,0x20,0x4F,0x20,0x40,0x2F,0x0000,0x00,0x00},
	{0xFF,0x02,0x08,0x08,0x38,0x00,0x3F,0x0F,0x0001,0x00,0x00},
	{0xFF,0x02,0x08,0x08,0x30,0x00,0x37,0x0F,0x0001,0x00,0x00},
	{0xFF,0x02,0x10,0x10,0x00,0x00,0x0F,0x0F,0x0002,0x00,0x00},
	{0x81,0x01,0x20,0x20,0x00,0x30,0x0F,0x3F,0x0003,0x00,0x00},
	{0x01,0x01,0x20,0x20,0x10,0x30,0x1F,0x3F,0x0003,0x00,0x00},
	{0x01,0x01,0x20,0x20,0x20,0x30,0x2F,0x3F,0x0003,0x00,0x00},
	{0x82,0x01,0x20,0x20,0x00,0x10,0x0F,0x1F,0x0004,0x00,0x00},
	{0x02,0x01,0x20,0x20,0x10,0x10,0x1F,0x1F,0x0004,0x00,0x00},
	{0x03,0x01,0x20,0x20,0x20,0x10,0x2F,0x1F,0x0004,0x00,0x00},
	{0x8A,0x05,0x00,0x00,0xC0,0x00,0xFF,0x3F,0x0019,0x00,0x00},
	{0x83,0x00,0x20,0x20,0x80,0x80,0x9F,0x9F,0x0005,0x00,0x00},
	{0x03,0x00,0x20,0x20,0xA0,0x80,0xBF,0x9F,0x0005,0x00,0x00},
	{0x03,0x00,0x20,0x20,0x80,0xA0,0x9F,0xBF,0x0005,0x00,0x00},
	{0x03,0x00,0x20,0x20,0xA0,0xA0,0xBF,0xBF,0x0005,0x00,0x00},
	{0x03,0x00,0x20,0x20,0xA0,0xC0,0xBF,0xDF,0x0005,0x00,0x00},
	{0x81,0x01,0x10,0x10,0x00,0x40,0x07,0x47,0x0006,0x00,0x00},
	{0x01,0x01,0x10,0x10,0x08,0x40,0x0F,0x47,0x0006,0x00,0x00},
	{0x01,0x01,0x10,0x10,0x10,0x40,0x17,0x47,0x0006,0x00,0x00},
	{0x02,0x01,0x10,0x10,0x18,0x40,0x1F,0x47,0x0006,0x00,0x00},
	{0x02,0x01,0x10,0x10,0x20,0x40,0x27,0x47,0x0006,0x00,0x00},
	{0x81,0x00,0x20,0x20,0x00,0x58,0x0F,0x67,0x0007,0x00,0x00},
	{0x01,0x00,0x20,0x20,0x10,0x58,0x1F,0x67,0x0007,0x00,0x00},
	{0x02,0x00,0x20,0x20,0x20,0x58,0x2F,0x67,0x0007,0x00,0x00},
	{0x02,0x00,0x20,0x20,0x30,0x58,0x3F,0x67,0x0007,0x00,0x00},
	{0x81,0x00,0x18,0x18,0x00,0x68,0x0F,0x77,0x0008,0x00,0x00},
	{0x01,0x00,0x18,0x18,0x10,0x68,0x1F,0x7F,0x0008,0x00,0x00},
	{0x02,0x00,0x18,0x18,0x20,0x68,0x2F,0x77,0x0008,0x00,0x00},
	{0x02,0x00,0x18,0x18,0x30,0x68,0x3F,0x77,0x0008,0x00,0x00},
	{0x02,0x00,0x18,0x18,0x40,0x68,0x4F,0x77,0x0008,0x00,0x00},
	{0x82,0x00,0x20,0x20,0x00,0x90,0x17,0xA7,0x0009,0x00,0x00},
	{0x03,0x00,0x20,0x20,0x18,0x90,0x2F,0xA7,0x0009,0x00,0x00},
	{0x04,0x00,0x20,0x20,0x30,0x90,0x47,0xA7,0x0009,0x00,0x00},
	{0x82,0x00,0x18,0x18,0x00,0x80,0x0F,0x8F,0x0009,0x00,0x00},
	{0x02,0x00,0x18,0x18,0x10,0x80,0x1F,0x8F,0x0009,0x00,0x00},
	{0x02,0x00,0x18,0x18,0x20,0x80,0x2F,0x8F,0x0009,0x00,0x00},
	{0x82,0x00,0x20,0x20,0x00,0xA8,0x17,0xC7,0x000A,0x00,0x00},
	{0x02,0x00,0x20,0x20,0x18,0xA8,0x2F,0xC7,0x000A,0x00,0x00},
	{0x02,0x00,0x20,0x20,0x30,0xA8,0x47,0xC7,0x000A,0x00,0x00},
	{0x02,0x00,0x20,0x20,0x48,0xA8,0x5F,0xC7,0x000A,0x00,0x00},
	{0x82,0x00,0x30,0x30,0x00,0xC8,0x17,0xDF,0x000B,0x00,0x00},
	{0x02,0x00,0x30,0x30,0x18,0xC8,0x2F,0xDF,0x000B,0x00,0x00},
	{0x02,0x00,0x30,0x30,0x30,0xC8,0x47,0xDF,0x000B,0x00,0x00},
	{0x02,0x00,0x30,0x30,0x48,0xC8,0x5F,0xDF,0x000B,0x00,0x00},
	{0x82,0x00,0x20,0x20,0x60,0xE0,0x77,0xF7,0x000C,0x00,0x00},
	{0x02,0x00,0x20,0x20,0x78,0xE0,0x8F,0xF7,0x000C,0x00,0x00},
	{0x02,0x00,0x20,0x20,0x90,0xE0,0xA7,0xF7,0x000C,0x00,0x00},
	{0x82,0x00,0x20,0x20,0x00,0xE0,0x17,0xF7,0x000D,0x00,0x00},
	{0x02,0x00,0x20,0x20,0x18,0xE0,0x2F,0xF7,0x000D,0x00,0x00},
	{0x02,0x00,0x20,0x20,0x30,0xE0,0x47,0xF7,0x000D,0x00,0x00},
	{0x02,0x00,0x20,0x20,0x48,0xE0,0x5F,0xF7,0x000D,0x00,0x00},
	{0x82,0x00,0x18,0x18,0x40,0x00,0x4F,0x0F,0x000E,0x00,0x00},
	{0x02,0x00,0x18,0x18,0x50,0x00,0x5F,0x0F,0x000E,0x00,0x00},
	{0x02,0x00,0x18,0x18,0x60,0x00,0x6F,0x0F,0x000E,0x00,0x00},
	{0x02,0x00,0x18,0x18,0x70,0x00,0x7F,0x0F,0x000E,0x00,0x00},
	{0x82,0x00,0x18,0x18,0x80,0x00,0x8F,0x0F,0x000F,0x00,0x00},
	{0x02,0x00,0x18,0x18,0x90,0x00,0x9F,0x0F,0x000F,0x00,0x00},
	{0x02,0x00,0x18,0x18,0xA0,0x00,0xAF,0x0F,0x000F,0x00,0x00},
	{0x02,0x00,0x18,0x18,0xB0,0x00,0xBF,0x0F,0x000F,0x00,0x00},
	{0x81,0x00,0x20,0x20,0x30,0x10,0x3F,0x1F,0x0010,0x00,0x00},
	{0x01,0x00,0x20,0x20,0x40,0x10,0x4F,0x1F,0x0010,0x00,0x00},
	{0x01,0x00,0x20,0x20,0x50,0x10,0x5F,0x1F,0x0010,0x00,0x00},
	{0x01,0x00,0x20,0x20,0x60,0x10,0x6F,0x1F,0x0010,0x00,0x00},
	{0x01,0x00,0x20,0x20,0x70,0x10,0x7F,0x1F,0x0010,0x00,0x00},
	{0x01,0x00,0x20,0x20,0x80,0x10,0x8F,0x1F,0x0010,0x00,0x00},
	{0x81,0x00,0x20,0x20,0x90,0x10,0x9F,0x1F,0x0010,0x00,0x00},
	{0x01,0x00,0x20,0x20,0xA0,0x10,0xAF,0x1F,0x0010,0x00,0x00},
	{0x01,0x00,0x20,0x20,0xB0,0x10,0xBF,0x1F,0x0010,0x00,0x00},
	{0x01,0x00,0x20,0x20,0xA0,0x10,0xAF,0x1F,0x0010,0x00,0x00},
	{0x81,0x00,0x20,0x20,0x90,0x10,0x9F,0x1F,0x0010,0x00,0x00},
	{0x83,0x00,0x20,0x20,0x50,0x20,0x5F,0x2F,0x0010,0x00,0x00},
	{0x03,0x00,0x20,0x20,0x60,0x20,0x6F,0x2F,0x0010,0x00,0x00},
	{0x03,0x00,0x20,0x20,0x70,0x20,0x7F,0x2F,0x0010,0x00,0x00},
	{0x85,0x00,0x80,0x80,0xC0,0x40,0xE0,0x60,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0xC0,0x80,0xE0,0xA0,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0xC0,0xC0,0xE0,0xE0,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0x80,0x40,0xA0,0x60,0x0000,0x00,0x00},
	{0x85,0x00,0x80,0x80,0xE0,0x40,0xFF,0x60,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0xE0,0x80,0xFF,0xA0,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0xE0,0xC0,0xFF,0xE0,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0xA0,0x40,0xBF,0x60,0x0000,0x00,0x00},
	{0x85,0x00,0x80,0x80,0xC0,0x60,0xE0,0x7F,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0xC0,0xA0,0xE0,0xBF,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0xC0,0xE0,0xE0,0xFF,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0x80,0x60,0xA0,0x7F,0x0000,0x00,0x00},
	{0x85,0x00,0x80,0x80,0xE0,0x60,0xFF,0x7F,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0xE0,0xA0,0xFF,0xBF,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0xE0,0xE0,0xFF,0xFF,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0xA0,0x60,0xBF,0x7F,0x0000,0x00,0x00},
	{0x9E,0x09,0x40,0x20,0x40,0x80,0x57,0x8F,0x0011,0x00,0x00},
	{0x9E,0x09,0x40,0x40,0x5F,0x90,0x48,0xA7,0x0011,0x00,0x00},
	{0x9E,0x09,0x20,0x40,0x3F,0x40,0x30,0x57,0x0011,0x00,0x00},
	{0x9E,0x09,0x40,0x40,0x5F,0xA7,0x48,0x90,0x0011,0x00,0x00},
	{0x9E,0x09,0x40,0x20,0x40,0x8F,0x57,0x80,0x0011,0x00,0x00},
	{0x9E,0x09,0x40,0x40,0x48,0xA7,0x5F,0x90,0x0011,0x00,0x00},
	{0x9E,0x09,0x20,0x40,0x30,0x40,0x3F,0x57,0x0011,0x00,0x00},
	{0x9E,0x09,0x40,0x40,0x48,0x90,0x5F,0xA7,0x0011,0x00,0x00},
	{0x81,0x01,0x10,0x10,0x30,0x30,0x3F,0x3F,0x0018,0x00,0x00},
	{0x81,0x01,0x10,0x10,0x40,0x30,0x4F,0x3F,0x0018,0x00,0x00},
	{0x81,0x01,0x10,0x10,0x50,0x30,0x5F,0x3F,0x0018,0x00,0x00},
	{0x81,0x01,0x10,0x10,0x3F,0x30,0x30,0x3F,0x0018,0x00,0x00},
	{0x81,0x01,0x10,0x10,0x4F,0x30,0x40,0x3F,0x0018,0x00,0x00},
	{0x81,0x01,0x10,0x10,0x5F,0x30,0x50,0x3F,0x0018,0x00,0x00},
	{0x81,0x01,0x10,0x10,0x60,0x30,0x6F,0x3F,0x0018,0x00,0x00},
	{0x81,0x01,0x10,0x10,0x70,0x30,0x7F,0x3F,0x0018,0x00,0x00},
	{0x81,0x01,0x10,0x10,0x80,0x30,0x8F,0x3F,0x0018,0x00,0x00},
	{0x82,0x00,0x18,0x18,0x80,0x20,0x8F,0x2F,0x0018,0x00,0x00},
	{0x82,0x00,0x18,0x18,0x90,0x20,0x9F,0x2F,0x0018,0x00,0x00},
	{0x82,0x00,0x18,0x18,0xA0,0x20,0xAF,0x2F,0x0018,0x00,0x00},
	{0x82,0x00,0x18,0x18,0xB0,0x20,0xBF,0x2F,0x0018,0x00,0x00},
	{0x84,0x00,0x30,0x30,0x40,0x40,0x57,0x57,0x0013,0x00,0x00},
	{0x04,0x00,0x30,0x30,0x58,0x40,0x6F,0x57,0x0013,0x00,0x00},
	{0x04,0x14,0x30,0x40,0x70,0x40,0x8F,0x5F,0x0013,0x00,0x00},
	{0x04,0x14,0x30,0x40,0x90,0x40,0xAF,0x5F,0x0013,0x00,0x00},
	{0x81,0x02,0x14,0x14,0x90,0x30,0x9F,0x3F,0x0014,0x00,0x00},
	{0x81,0x02,0x14,0x14,0xA0,0x30,0xAF,0x3F,0x0014,0x00,0x00},
	{0x81,0x02,0x14,0x14,0xB0,0x30,0xBF,0x3F,0x0014,0x00,0x00},
	{0x81,0x02,0x14,0x14,0xAF,0x30,0xA0,0x3F,0x0014,0x00,0x00},
	{0x81,0x02,0x14,0x14,0x9F,0x30,0x90,0x3F,0x0014,0x00,0x00},
	{0x81,0x02,0x14,0x14,0xB0,0x40,0xBF,0x4F,0x0014,0x00,0x00},
	{0x94,0x01,0x30,0x30,0xC0,0x40,0xDF,0x5F,0x0015,0x00,0x00},
	{0x14,0x01,0x30,0x30,0xE0,0x40,0xFF,0x5F,0x0015,0x00,0x00},
	{0x28,0x11,0x30,0x30,0xC0,0x60,0xDF,0x7F,0x0015,0x00,0x00},
	{0x81,0x19,0x10,0x10,0x70,0x60,0x8F,0x7F,0x0016,0x00,0x00},
	{0x01,0x19,0x10,0x10,0x90,0x60,0xAF,0x7F,0x0016,0x00,0x00},
	{0x01,0x19,0x10,0x10,0x70,0x80,0x8F,0x9F,0x0016,0x00,0x00},
	{0x01,0x19,0x10,0x10,0x90,0x80,0xAF,0x9F,0x0016,0x00,0x00},
	{0x82,0x19,0x20,0x20,0xE0,0xE0,0xFF,0xFF,0x0017,0x00,0x00},
	{0x02,0x19,0x20,0x20,0xC0,0xE0,0xDF,0xFF,0x0017,0x00,0x00},
	{0x02,0x19,0x20,0x20,0xE0,0xC0,0xFF,0xDF,0x0017,0x00,0x00},
	{0x02,0x19,0x20,0x20,0xC0,0xC0,0xDF,0xDF,0x0017,0x00,0x00},
	{0x02,0x19,0x20,0x20,0xE0,0xA0,0xFF,0xBF,0x0017,0x00,0x00},
	{0x02,0x19,0x20,0x20,0xC0,0xA0,0xDF,0xBF,0x0017,0x00,0x00},
	{0x02,0x19,0x20,0x20,0xE0,0x80,0xFF,0x9F,0x0017,0x00,0x00},
	{0x02,0x19,0x20,0x20,0xC0,0x80,0xDF,0x9F,0x0017,0x00,0x00},
	{0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0000,0x00,0x00}
//0096DD74 00 00 00 00
};

void C_0075B8F3(short bp08, short bp0c, short bp10, int bp14) {
	struct {//x44
		struct VECTOR local_17;
		DECL_struct_MATRIX(local_13);
		int dwFlags_unused;//local_5
		struct SVECTOR local_4;
		int i;//local_2
		struct t_wm_local_54 *local_1;
	}lolo;

	lolo.local_1 = D_00E35640;
	if(lolo.local_1) {
		D_00E35640 = lolo.local_1->pNext;
		lolo.local_1->pNext = D_00E35648;
		D_00E35648 = lolo.local_1;

		lolo.local_13.t[0] =
		lolo.local_13.t[1] =
		lolo.local_13.t[2] = 0;
		psx_SetTransMatrix(&lolo.local_13);

		lolo.local_4.vx =
		lolo.local_4.vz = 0;
		lolo.local_4.vy = bp0c;
		psx_RotMatrixXYZ(&lolo.local_4, &lolo.local_13);
		psx_SetRotMatrix(&lolo.local_13);
		psx_RotTrans(&D_00E2D1F0, &lolo.local_17, &lolo.dwFlags_unused);
		lolo.local_1->f_14.vx = lolo.local_17.vx;
		lolo.local_1->f_14.vy = lolo.local_17.vy;
		lolo.local_1->f_14.vz = lolo.local_17.vz;

		lolo.local_1->f_04 = D_00E2D1E0;
		lolo.local_4.vy = bp08;
		psx_RotMatrixXYZ(&lolo.local_4, &lolo.local_13);
		psx_SetRotMatrix(&lolo.local_13);
		psx_RotTrans(&D_00E2D1F8, &lolo.local_17, &lolo.dwFlags_unused);
		lolo.local_1->f_04.vx = D_00E2D1E0.vx + lolo.local_17.vx;
		lolo.local_1->f_04.vy = D_00E2D1E0.vy + lolo.local_17.vy;
		lolo.local_1->f_04.vz = D_00E2D1E0.vz + lolo.local_17.vz;

		lolo.local_1->f_14.pad = D_00E2D200 ^ 0x800;
		lolo.local_1->f_1f = bp14;
		lolo.local_1->f_1c = D_0096D5B8[bp10][0];
		lolo.local_1->f_1e = D_0096D5B8[bp10][1];
		lolo.local_1->f_1d = D_0096D6A8[lolo.local_1->f_1c].f_00 & ~0x80;
		lolo.local_1->f_04.pad = 0;
		for(lolo.i = 0; lolo.i < 2; lolo.i ++) {
			lolo.local_1->f_20 = (D_0096D6A8[lolo.local_1->f_1c].f_01 & 0x1c) == 8?0:0x80;
			lolo.local_1->f_24.f_2c = (D_0096D6A8[lolo.local_1->f_1c].f_01 & 0x1c) == 8?0x80000000:0x80808080;
			lolo.local_1->f_24.f_28 = D_00E2C404[0];
		}//end for
	}
}

void C_0075BB25() {
	struct t_wm_local_spr_0c *local_1;

	D_00E2D1F0.vx = 0;
	D_00E2D1F0.vy = 50;
	D_00E2D1F0.vz = 0;
	D_00E2D200 = 0;
	C_00762798(&D_00E2D1E0);//wm:get model pos(2)?
	D_00E2D1F8.vx = D_00E2D1F8.vy =  D_00E2D1F8.vz = 0;
	C_0075B8F3(0, 0, 7, 0);
	local_1 = &(D_0096D6A8[D_0096D5B8[7][0]]);
	local_1->bWidth =
	local_1->bHeight = 0x10;
}

//2danimfx:do anim
void C_0075BBB3(struct t_local_unknown_c0 *bp08, int dwAnimType/*bp0c*/) {
	struct {
		int bp_0c;
		int bp_08;
		struct t_wm_local_spr_0c *bp_04;
	}lolo;

	lolo.bp_08 = bp08->f_3c + bp08->f_3e;
	D_00E2D200 = bp08->f_3c;
	D_00E2D1E0 = bp08->sPrevPos;
	D_00E2D1F0.vx = D_00E2D1F0.vy = D_00E2D1F0.vz = 0;
	D_00E2D1F8.vx = D_00E2D1F8.vy = D_00E2D1F8.vz = 0;
	switch(dwAnimType) {
		case 0x14: case 0x15: case 0x16:
			D_00E2D1F8.vy = (C_0074D28E() != 0)?300:600;//wm:get view mode?
			D_00E2D1F8.vz = -200;
			C_0075B8F3(bp08->f_3c, 0, dwAnimType, 0);
		break;
		case 0x17:
			D_00E2D1F8.vy = (C_0074D28E() != 0)?300:600;//wm:get view mode?
			D_00E2D1F8.vz = -200;
			D_00E2D1F0.vy = 50;
			C_0075B8F3(bp08->f_3c, 0, dwAnimType, 0);
		break;
		case 0x01:
			D_00E2D200 = 0;
			D_00E2D1F8.vz = 500;
			D_00E2D1F0.vz = 30;
			C_0075B8F3(0, 0, 0x1c, 0);
			D_00E2D1F8.vz = -500;
			D_00E2D1F0.vz = -30;
			C_0075B8F3(0, 0, 0x20, 0);
			D_00E2D1F8.vz = 0x161;
			D_00E2D1F0.vz = 0x15;
			D_00E2D1F8.vx = 0x161;
			D_00E2D1F0.vx = 0x15;
			C_0075B8F3(0, 0, 0x23, 0);
			D_00E2D1F8.vx = -0x161;
			D_00E2D1F0.vx = -0x15;
			C_0075B8F3(0, 0, 0x1d, 0);
			D_00E2D1F8.vz = -0x161;
			D_00E2D1F0.vz = -0x15;
			C_0075B8F3(0 ,0, 0x1f, 0);
			D_00E2D1F8.vx = 0x161;
			D_00E2D1F0.vx = 0x15;
			C_0075B8F3(0, 0, 0x21, 0);
			D_00E2D1F8.vz = 0;
			D_00E2D1F0.vz = 0;
			D_00E2D1F8.vx = 500;
			D_00E2D1F0.vx = 30;
			C_0075B8F3(0, 0, 0x22, 0);
			D_00E2D1F8.vx = -500;
			D_00E2D1F0.vx = -30;
			C_0075B8F3(0, 0, 30, 0);
		break;
		case 0x02:
			lolo.bp_0c = C_00753BE8() << 4;
			D_00E2D1F0.vx = psx_rcos(lolo.bp_0c) >> 6;
			D_00E2D1F0.vy = 120;
			D_00E2D1F8.vz = 500;
			C_0075B8F3(lolo.bp_0c, 0, 0x31, 0x14);
		break;
		case 0x03:
			D_00E2D1F8.vy = 300;
			D_00E2D1F8.vz = -1000;
			D_00E2D1F0.vy = 20;
			D_00E2D1F0.vz = -10;
			C_0075B8F3(bp08->f_3c, bp08->f_3c + C_00753BE8() * 8 - 0x400, 0x38, 1);
		break;
		case 0x04:
			D_00E2D1F8.vx = 30;
			D_00E2D1F8.vy = 400;
			D_00E2D1F8.vz = 500;
			C_0075B8F3(bp08->f_3c, 0, 0x39, 0);
			lolo.bp_04 = &(D_0096D6A8[D_0096D5B8[0x39][0]]);
			lolo.bp_04->bWidth =
			lolo.bp_04->bHeight = 0xb;
		break;
		case 0x05:
			D_00E2D1F8.vx = 30;
			D_00E2D1F8.vy = 400;
			D_00E2D1F8.vz = 500;
			C_0075B8F3(bp08->f_3c, 0, 0x3a, 0);
		break;
		case 0x06:
			D_00E2D1F0.vy = 50;
			D_00E2D200 = 0;
			C_0075B8F3(0, 0, 7, 0);
			lolo.bp_04 = &(D_0096D6A8[D_0096D5B8[7][0]]);
			lolo.bp_04->bWidth =
			lolo.bp_04->bHeight = 0x10;
		break;
	}//end switch
}

//2danimfx:start
void C_0075BFE5(int dwIndex/*bp08*/, int dwModelType/*bp0c*/, int dwAnimType/*bp10*/, int dwDelay/*bp14*/) {
	char *local_1;

	local_1 = D_00E35638[dwIndex];
	local_1[0] = dwModelType;
	local_1[1] = dwAnimType;
	local_1[2] = dwDelay;
	local_1[3] = 0;
}

//2danimfx:stop
void C_0075C01B(int dwIndex/*bp08*/) {
	D_00E35638[dwIndex][2] = 0;
}

void C_0075C0FD(void);//vehicule/model fx[flames, smoke, ...](1)?
void C_0075CEED(void);//vehicule/model fx[flames, smoke, ...](2)?

//2danimfx:refresh
void C_0075C02B() {
	char *local_1;

	if(D_00E35650 && D_00E2D60C) {
		D_00E2D60C->pNext = D_00E35640;
		D_00E35640 = D_00E35650;
		D_00E35650 = 
		D_00E2D60C = 0;
	}
	C_0075C0FD();//vehicule/model fx[flames, smoke, ...](1)?
	C_0075CEED();//vehicule/model fx[flames, smoke, ...](2)?
	for(local_1 = D_00E35638[0]; local_1 < D_00E35638[2]/*00E35640*/; local_1 += 4) {
		if(local_1[2] > 0 && (local_1[3] --) <= 1) {//else 0075C0F7
			if(C_00762047(local_1[0])) {//wm:set current model//else 0075C0F0
				local_1[3] = local_1[2];
				C_0075BBB3(C_0076175F(), local_1[1]);//2danimfx:do anim
			} else {
				local_1[2] = 0;
			}
		}
	}//end for
}

void C_0075C283(struct t_wm_local_30 *, struct t_wm_local_spr_0c *, struct SVECTOR *, short);//put 1 sprite, billboard?

//vehicule/model fx[flames, smoke, ...](1)?
void C_0075C0FD() {
	struct {
		DECL_struct_MATRIX(local_36);
		DECL_struct_MATRIX(local_28);
		int dwDiffZ;//local_20
		DECL_struct_MATRIX(local_19);
		int dwDiffY;//local_11
		int dwDiffX;//local_10
		struct SVECTOR local_9;
		struct SVECTOR local_7;
		struct VECTOR local_5;
		struct t_wm_local_54 *local_1;
	}lolo;

	lolo.local_7.vx = 0;
	lolo.local_7.vy = -C_0074D298();
	lolo.local_7.vz = 0;
	psx_RotMatrixYXZ(&lolo.local_7, &lolo.local_28);
	lolo.local_7.vx = -C_0074D3C6();
	psx_RotMatrixYXZ(&lolo.local_7, &lolo.local_19);
	C_0075042B(&lolo.local_5);//wm:get some pos?
	for(lolo.local_1 = D_00E35648; lolo.local_1; lolo.local_1 = lolo.local_1->pNext) {
		lolo.dwDiffX = lolo.local_1->f_04.vx - lolo.local_5.vx;
		lolo.dwDiffY = lolo.local_1->f_04.vy - D_00DE6A04;
		lolo.dwDiffZ = lolo.local_1->f_04.vz - lolo.local_5.vz;
		if(
			lolo.dwDiffX > -30000 && lolo.dwDiffX < 30000 &&
			lolo.dwDiffZ > -30000 && lolo.dwDiffZ < 30000
		) {
			lolo.local_9.vx = lolo.dwDiffX;
			lolo.local_9.vy = lolo.dwDiffY - C_00762F9A(lolo.dwDiffX, lolo.dwDiffZ);
			lolo.local_9.vz = lolo.dwDiffZ;
			if(lolo.local_1->f_1e) {
				lolo.local_7.vx =
				lolo.local_7.vz = 0;
				lolo.local_7.vy = lolo.local_1->f_14.pad;
				psx_RotMatrixXYZ(&lolo.local_7, &lolo.local_36);
				psx_SetRotMatrix(&lolo.local_36);
			} else {
				psx_SetRotMatrix(&lolo.local_19);
			}
			C_0075C283(&(lolo.local_1->f_24), &(D_0096D6A8[lolo.local_1->f_1c]), &lolo.local_9, lolo.local_1->f_1e);//put 1 sprite, billboard?
		}
	}//end for
}

//put 1 sprite, billboard?
void C_0075C283(struct t_wm_local_30 *bp08, struct t_wm_local_spr_0c *bp0c, struct SVECTOR *bp10, short bp14) {
	struct {//x25c
		//bp_1d8 and above for compiler
		struct t_dx_rend_vertex_20 *bp_1d4;
		struct t_dx_rend_vertex_20 *bp_1d0;
		struct t_dx_rend_vertex_20 *bp_1cc;
		struct t_dx_rend_vertex_20 *bp_1c8;
		float fV3;//bp_1c4
		float fV2;//bp_1c0
		float fV1;//bp_1bc
		float fV0;//bp_1b8
		float fU3;//bp_1b4
		float fU2;//bp_1b0
		float fU1;//bp_1ac
		float fU0;//bp_1a8
		struct SVECTOR bp_1a4;
		int dwMinZ;//bp_19c
		float fW3;//bp_198
		float fW2;//bp_194
		DECL_struct_MATRIX(bp_190);
		D3DVECTOR sVectFPost3;//bp_170
		float fW1;//bp_164
		D3DVECTOR sVectFPost2;//bp_160
		float fW0;//bp_154
		D3DVECTOR sVectFPost1;//bp_150
		struct SVECTOR sVect3;//bp_144
		D3DVECTOR sVectFPost0;//bp_13c
		struct SVECTOR sVect2;//bp_130
		struct VECTOR bp_128;
		struct SVECTOR sVect1;//bp_118
		struct SVECTOR sVect0;//bp_110
		int dwFlags_unused;//bp_108
		D3DMATRIX bp_104;
		D3DVECTOR sVectFPre3;//bp_c4
		struct tVECTOR_F4 sVectF3;//bp_b8
		float fZ;//bp_a8
		D3DVECTOR sVectFPre2;//bp_a4
		struct tVECTOR_F4 sVectF2;//bp_98
		D3DMATRIX bp_88;
		D3DVECTOR sVectFPre1;//bp_48
		struct tVECTOR_F4 sVectF1;//bp_3c
		D3DVECTOR sVectFPre0;//bp_2c
		struct tVECTOR_F4 sVectF0;//bp_20
		struct VECTOR bp_10;
	}lolo;

	lolo.bp_128.vx =
	lolo.bp_128.vy =
	lolo.bp_128.vz = 0;
	psx_TransMatrix(&lolo.bp_190, &lolo.bp_128);
	psx_SetTransMatrix(&lolo.bp_190);
	//-- --
	lolo.bp_1a4.vx = (-bp0c->bWidth) * 8;
	if(bp14) {
		lolo.bp_1a4.vy = 0;
		lolo.bp_1a4.vz = (-bp0c->bHeight) * 8;
	} else {
		lolo.bp_1a4.vy = (-bp0c->bHeight) * 8;
		lolo.bp_1a4.vz = 0;
	}
	psx_RotTrans(&lolo.bp_1a4, &lolo.bp_10, &lolo.dwFlags_unused);
	lolo.sVect0.vx = lolo.bp_10.vx;
	lolo.sVect0.vy = lolo.bp_10.vy;
	lolo.sVect0.vz = lolo.bp_10.vz;
	//-- --
	lolo.bp_1a4.vx += bp0c->bWidth * 16;
	psx_RotTrans(&lolo.bp_1a4, &lolo.bp_10, &lolo.dwFlags_unused);
	lolo.sVect1.vx = lolo.bp_10.vx;
	lolo.sVect1.vy = lolo.bp_10.vy;
	lolo.sVect1.vz = lolo.bp_10.vz;
	//-- --
	if(bp14)
		lolo.bp_1a4.vz += bp0c->bHeight * 16;
	else
		lolo.bp_1a4.vy += bp0c->bHeight * 16;
	psx_RotTrans(&lolo.bp_1a4, &lolo.bp_10, &lolo.dwFlags_unused);
	lolo.sVect3.vx = lolo.bp_10.vx;
	lolo.sVect3.vy = lolo.bp_10.vy;
	lolo.sVect3.vz = lolo.bp_10.vz;
	//-- --
	lolo.bp_1a4.vx -= bp0c->bWidth * 16;
	psx_RotTrans(&lolo.bp_1a4, &lolo.bp_10, &lolo.dwFlags_unused);
	lolo.sVect2.vx = lolo.bp_10.vx;
	lolo.sVect2.vy = lolo.bp_10.vy;
	lolo.sVect2.vz = lolo.bp_10.vz;
	//-- --
	bp08->f_00.u0 = bp08->f_00.u2 = bp0c->f_04;
	bp08->f_00.u1 = bp08->f_00.u3 = bp0c->f_06;
	bp08->f_00.v0 = bp08->f_00.v1 = bp0c->f_05;
	bp08->f_00.v2 = bp08->f_00.v3 = bp0c->f_07;
	bp08->f_00.clut = bp0c->clut;
	//-- --
	switch(bp0c->f_01 & 3) {//blend mode?
		case 0: bp08->f_28 = D_00E2C404[0]; break;
		case 1: bp08->f_28 = D_00E2C404[1]; break;
		case 2: bp08->f_28 = /*lolo.bp_1dc*/(bp0c->clut == 20)?D_00E2C404[1]:D_00E2C404[0]; break;
		case 3: bp08->f_28 = D_00E2C404[3]; break;
		default:
			bp08->f_28 = D_00E2C404[0];
	}//end for
	//-- --
	C_0074D3A7();//wm:set camera transform?
	psx_RotTrans(bp10, &lolo.bp_10, &lolo.dwFlags_unused);
	psx_TransMatrix(&lolo.bp_190, &lolo.bp_10);
	psx_SetTransMatrix(&lolo.bp_190);
	C_006617E9(C_0066100D(), &lolo.bp_88);//psx:transformation to D3DMATRIX(3)
	C_0067D2BF(&lolo.bp_88, &lolo.bp_104);//dx_mat:matrix multiplication by "struct t_aa0::f_8d0" 4x4[transpose]

	lolo.sVectFPre0.x = /*lolo.bp_1e0*/(float)lolo.sVect0.vx;
	lolo.sVectFPre0.y = /*lolo.bp_1e4*/(float)lolo.sVect0.vy;
	lolo.sVectFPre0.z = /*lolo.bp_1e8*/(float)lolo.sVect0.vz;

	lolo.sVectFPre1.x = /*lolo.bp_1ec*/(float)lolo.sVect1.vx;
	lolo.sVectFPre1.y = /*lolo.bp_1f0*/(float)lolo.sVect1.vy;
	lolo.sVectFPre1.z = /*lolo.bp_1f4*/(float)lolo.sVect1.vz;

	lolo.sVectFPre2.x = /*lolo.bp_1f8*/(float)lolo.sVect2.vx;
	lolo.sVectFPre2.y = /*lolo.bp_1fc*/(float)lolo.sVect2.vy;
	lolo.sVectFPre2.z = /*lolo.bp_200*/(float)lolo.sVect2.vz;

	lolo.sVectFPre3.x = /*lolo.bp_204*/(float)lolo.sVect3.vx;
	lolo.sVectFPre3.y = /*lolo.bp_208*/(float)lolo.sVect3.vy;
	lolo.sVectFPre3.z = /*lolo.bp_20c*/(float)lolo.sVect3.vz;

	if(fast_multVectorByTransform(&lolo.bp_104, &lolo.sVectFPre0, &lolo.sVectF0), lolo.sVectF0.w > 0.0f) {
		fast_multVectorByRotTrans_Z_only(&lolo.bp_88, &lolo.sVectFPre0, &lolo.sVectFPost0);
		if(fast_multVectorByTransform(&lolo.bp_104, &lolo.sVectFPre1, &lolo.sVectF1), lolo.sVectF1.w > 0.0f) {
			fast_multVectorByRotTrans_Z_only(&lolo.bp_88, &lolo.sVectFPre1, &lolo.sVectFPost1);
			if(fast_multVectorByTransform(&lolo.bp_104, &lolo.sVectFPre2, &lolo.sVectF2), lolo.sVectF2.w > 0.0f) {
				fast_multVectorByRotTrans_Z_only(&lolo.bp_88, &lolo.sVectFPre2, &lolo.sVectFPost2);
				if(fast_multVectorByTransform(&lolo.bp_104, &lolo.sVectFPre3, &lolo.sVectF3), lolo.sVectF3.w > 0.0f) {
					fast_multVectorByRotTrans_Z_only(&lolo.bp_88, &lolo.sVectFPre3, &lolo.sVectFPost3);

					lolo.dwMinZ = (int)min(min(lolo.sVectFPost0.z, lolo.sVectFPost1.z), lolo.sVectFPost2.z);
					lolo.dwMinZ = min(lolo.dwMinZ, C_0075F090(lolo.sVectFPost3.z)) >> 4;//wm:float to int
					if(lolo.dwMinZ >= 0 && lolo.dwMinZ < 0x1000) {//else 0075CED9
						if(C_0066E272(1, bp08->f_28)) {//else 0075CED9
							if(C_0074C969()) {//wm:get "isRendering"?//else 0075CED9
								lolo.fU0 = /*lolo.bp_220*/(float)bp08->f_00.u0 * bp08->f_28->f_24;
								lolo.fV0 = /*lolo.bp_224*/(float)bp08->f_00.v0 * bp08->f_28->f_28;
								lolo.fU1 = /*lolo.bp_228*/(float)bp08->f_00.u1 * bp08->f_28->f_24;
								lolo.fV1 = /*lolo.bp_22c*/(float)bp08->f_00.v1 * bp08->f_28->f_28;
								lolo.fU2 = /*lolo.bp_230*/(float)bp08->f_00.u2 * bp08->f_28->f_24;
								lolo.fV2 = /*lolo.bp_234*/(float)bp08->f_00.v2 * bp08->f_28->f_28;
								lolo.fU3 = /*lolo.bp_238*/(float)bp08->f_00.u3 * bp08->f_28->f_24;
								lolo.fV3 = /*lolo.bp_23c*/(float)bp08->f_00.v3 * bp08->f_28->f_28;
								lolo.fW0 = 1.0f / lolo.sVectF0.w;
								lolo.fW1 = 1.0f / lolo.sVectF1.w;
								lolo.fW2 = 1.0f / lolo.sVectF2.w;
								lolo.fW3 = 1.0f / lolo.sVectF3.w;
								bp08->f_00.x0 = C_0075F090(lolo.sVectF0.x * lolo.fW0);//wm:float to int
								bp08->f_00.y0 = C_0075F090(lolo.sVectF0.y * lolo.fW0);//wm:float to int
								bp08->f_00.x1 = C_0075F090(lolo.sVectF1.x * lolo.fW1);//wm:float to int
								bp08->f_00.y1 = C_0075F090(lolo.sVectF1.y * lolo.fW1);//wm:float to int
								bp08->f_00.x2 = C_0075F090(lolo.sVectF2.x * lolo.fW2);//wm:float to int
								bp08->f_00.y2 = C_0075F090(lolo.sVectF2.y * lolo.fW2);//wm:float to int
								bp08->f_00.x3 = C_0075F090(lolo.sVectF3.x * lolo.fW3);//wm:float to int
								bp08->f_00.y3 = C_0075F090(lolo.sVectF3.y * lolo.fW3);//wm:float to int
								if(lolo.sVectF0.z < lolo.sVectF1.z) {
									lolo.fZ = lolo.sVectF0.z;
									//lolo.fW0 = lolo.fW0;
								} else {
									lolo.fZ = lolo.sVectF1.z;
									lolo.fW0 = lolo.fW1;
								}
								if(lolo.fZ > lolo.sVectF2.z) {
									lolo.fZ = lolo.sVectF2.z;
									lolo.fW0 = lolo.fW2;
								}
								if(lolo.fZ > lolo.sVectF3.z) {
									lolo.fZ = lolo.sVectF3.z;
									lolo.fW0 = lolo.fW3;
								}
								lolo.fZ *= lolo.fW0;
								MK_VERTEX(&(bp08->f_28->f_70.asVertex[0]), lolo.bp_1c8, (float)bp08->f_00.x0, (float)bp08->f_00.y0, lolo.fZ, 1.0f, bp08->f_2c, 0xff000000, lolo.fU0, lolo.fV0);
								MK_VERTEX(&(bp08->f_28->f_70.asVertex[1]), lolo.bp_1cc, (float)bp08->f_00.x1, (float)bp08->f_00.y1, lolo.fZ, 1.0f, bp08->f_2c, 0xff000000, lolo.fU1, lolo.fV1);
								MK_VERTEX(&(bp08->f_28->f_70.asVertex[2]), lolo.bp_1d0, (float)bp08->f_00.x2, (float)bp08->f_00.y2, lolo.fZ, 1.0f, bp08->f_2c, 0xff000000, lolo.fU2, lolo.fV2);
								MK_VERTEX(&(bp08->f_28->f_70.asVertex[3]), lolo.bp_1d4, (float)bp08->f_00.x3, (float)bp08->f_00.y3, lolo.fZ, 1.0f, bp08->f_2c, 0xff000000, lolo.fU3, lolo.fV3);
								*(bp08->f_28->lpbCurPalette) = bp08->f_00.clut;
								bp08->f_28->dwLastPalette = bp08->f_00.clut;
							}
						}
					}
				}
			}
		}
	}
}

//vehicule/model fx[flames, smoke, ...](2)?
void C_0075CEED() {
	struct {//x20
		//bp_1c and above for compiler
		struct t_wm_local_30 *bp_14;
		tBGRA bp_10;
		struct t_wm_local_54 *bp_0c;
		struct t_wm_local_spr_0c *bp_08;
		struct t_wm_local_54 *bp_04;
	}lolo;

	lolo.bp_0c = 0;
	lolo.bp_04 = D_00E35648;
//0075CF02
	while(lolo.bp_04) {//else 0075D43E
		lolo.bp_14 = &(lolo.bp_04->f_24);
		lolo.bp_04->f_04.vx += lolo.bp_04->f_14.vx;
		lolo.bp_04->f_04.vy += lolo.bp_04->f_14.vy;
		lolo.bp_04->f_04.vz += lolo.bp_04->f_14.vz;
		lolo.bp_04->f_14.vy -= lolo.bp_04->f_1f;
		lolo.bp_08 = &(D_0096D6A8[lolo.bp_04->f_1c]);
		if(lolo.bp_08->f_01 == 2) {//else 0075D024
			lolo.bp_04->f_20 --;
			lolo.bp_14->f_00.r0 =
			lolo.bp_14->f_00.g0 =
			lolo.bp_14->f_00.b0 = lolo.bp_04->f_20;
			lolo.bp_10.bgra = lolo.bp_14->f_2c;
			if(lolo.bp_04->f_1c == 0x7c) {//else 0075CFFD
				lolo.bp_10.c.r =
				lolo.bp_10.c.g = --lolo.bp_10.c.b;
				lolo.bp_14->f_2c = lolo.bp_10.bgra;
			} else {
				lolo.bp_10.c.r =
				lolo.bp_10.c.g =
				lolo.bp_10.c.b = 0;
				lolo.bp_10.c.a --;
				lolo.bp_14->f_2c = lolo.bp_10.bgra;
			}
			//goto 0075D311
		} else {
			switch(lolo.bp_08->f_01 & 0x1c) {
				case 0x04:
					lolo.bp_04->f_20 -= 0xc;
					if(lolo.bp_04->f_20 < 0)
						lolo.bp_04->f_20 = 0;
					lolo.bp_14->f_00.r0 =
					lolo.bp_14->f_00.g0 =
					lolo.bp_14->f_00.b0 = lolo.bp_04->f_20;
					lolo.bp_10.bgra = lolo.bp_14->f_2c;
					lolo.bp_10.c.r =
					lolo.bp_10.c.g =
					lolo.bp_10.c.b = lolo.bp_04->f_20;
					lolo.bp_14->f_2c = lolo.bp_10.bgra;
					lolo.bp_08->bWidth =
					lolo.bp_08->bHeight += 0x10;
				break;
				case 0x08:
					if(lolo.bp_04->f_04.pad) {//else 0075D163
						lolo.bp_04->f_20 -= 8;
						if(lolo.bp_04->f_20 < 0)
							lolo.bp_04->f_20 = 0;
						lolo.bp_14->f_00.r0 =
						lolo.bp_14->f_00.g0 =
						lolo.bp_14->f_00.b0 = lolo.bp_04->f_20;
						lolo.bp_10.bgra = lolo.bp_14->f_2c;
						lolo.bp_10.c.r =
						lolo.bp_10.c.g =
						lolo.bp_10.c.b = lolo.bp_04->f_20;
						lolo.bp_14->f_2c = lolo.bp_10.bgra;
					} else {
						lolo.bp_04->f_20 += 8;
						lolo.bp_14->f_00.r0 =
						lolo.bp_14->f_00.g0 =
						lolo.bp_14->f_00.b0 = lolo.bp_04->f_20;
						if(lolo.bp_14->f_00.r0 >= 0x80)
							lolo.bp_04->f_04.pad = 1;
					}
				break;
				case 0x0c:
					if(lolo.bp_04->f_04.pad == 0) {
						lolo.bp_04->f_04.pad = 1;
						lolo.bp_04->f_14.vy = 200;
						lolo.bp_04->f_1f = 30;
					}
				break;
				case 0x10:
					lolo.bp_04->f_20 -= 0x10;
					if(lolo.bp_04->f_20 < 0)
						lolo.bp_04->f_20 = 0;
					lolo.bp_14->f_00.r0 =
					lolo.bp_14->f_00.g0 =
					lolo.bp_14->f_00.b0 = lolo.bp_04->f_20;
					lolo.bp_10.bgra = lolo.bp_14->f_2c;
					lolo.bp_10.c.r =
					lolo.bp_10.c.g =
					lolo.bp_10.c.b = lolo.bp_04->f_20;
					lolo.bp_14->f_2c = lolo.bp_10.bgra;
				break;
				case 0x14:
					lolo.bp_04->f_20 -= 8;
					if(lolo.bp_04->f_20 < 0)
						lolo.bp_04->f_20 = 0;
					lolo.bp_14->f_00.r0 =
					lolo.bp_14->f_00.g0 =
					lolo.bp_14->f_00.b0 = lolo.bp_04->f_20;
					lolo.bp_10.bgra = lolo.bp_14->f_2c;
					lolo.bp_10.c.r =
					lolo.bp_10.c.g =
					lolo.bp_10.c.b = lolo.bp_04->f_20;
					lolo.bp_14->f_2c = lolo.bp_10.bgra;
				break;
				case 0x18:
					lolo.bp_08->bWidth =
					lolo.bp_08->bHeight += /*lolo.bp_1c*/(lolo.bp_08->bWidth < 0x20)?(lolo.bp_08->bWidth & 0xf)?3:-5:0;
				break;
			}//end switch
		}
		lolo.bp_04->f_1d --;
		if(lolo.bp_04->f_1d == 0) {//else 0075D42B
			lolo.bp_04->f_1d = D_0096D6A8[++ lolo.bp_04->f_1c].f_00;
			if(lolo.bp_04->f_1d & 0x80) {//else 0075D42B
				if((lolo.bp_08->f_01 & 0x1c) == 0x18) {//else 0075D3C5
					while(((lolo.bp_04->f_1d = D_0096D6A8[-- lolo.bp_04->f_1c].f_00) & 0x80) == 0);
					lolo.bp_04->f_1d &= ~0x80;
				} else {
					if(lolo.bp_0c)
						lolo.bp_0c->pNext = lolo.bp_04->pNext;
					else
						D_00E35648 = lolo.bp_04->pNext;
					lolo.bp_04->pNext = D_00E35650;
					D_00E35650 = lolo.bp_04;
					if(D_00E2D60C == 0)
						D_00E2D60C = lolo.bp_04;
					lolo.bp_04 = /*lolo.bp_20*/lolo.bp_0c?lolo.bp_0c->pNext:D_00E35648;
					continue;
				}
			}
		}
		lolo.bp_0c = lolo.bp_04;
		lolo.bp_04 = lolo.bp_04->pNext;
	}//end while
	D_00E35610 ++;
}

//wm:set model's texture coords?
void C_0075D482(struct t_wm_local_30 *bp08, struct t_wm_local_sRect *bp0c) {
	int i;

	if(bp08 && bp0c) {
		for(i = 0; i < 1; i ++) {
			bp08->f_2c = 0x80404040;
			bp08->f_00.clut = 0;
			bp08->f_00.u0 = bp08->f_00.u2 = bp0c->wX;
			bp08->f_00.v0 = bp08->f_00.v1 = bp0c->wY;
			bp08->f_00.u1 = bp08->f_00.u3 = bp0c->wX + bp0c->wWidth;
			bp08->f_00.v2 = bp08->f_00.v3 = bp0c->wY + bp0c->wHeight;
		}//end for
	}
}

void C_0075D544(short bp08, short bp0c, short bp10, short bp14, struct t_wm_local_30 *bp18, short bp1c) {
	struct {//x23c
		//local_121 and above for compiler
		struct t_dx_rend_vertex_20 *local_120;
		struct t_dx_rend_vertex_20 *local_119;
		struct t_dx_rend_vertex_20 *local_118;
		struct t_dx_rend_vertex_20 *local_117;
		float fV3;//local_116
		float fV2;//local_115
		float fV1;//local_114
		float fV0;//local_113
		float fU3;//local_112
		float fU2;//local_111
		float fU1;//local_110
		float fU0;//local_109
		int local_108;
int _ocal_107[2];
		float local_105;
		float local_104;
		DECL_struct_MATRIX(local_103);
		D3DVECTOR local_95;
		float local_92;
		D3DVECTOR local_91;
		float local_88;
		DECL_struct_MATRIX(local_87);
		D3DVECTOR local_79;
		D3DVECTOR local_76;
		struct SVECTOR local_73;
		D3DMATRIX local_71;
		D3DVECTOR local_55;
		struct tVECTOR_F4 local_52;
		float fZ;//local_48
		D3DVECTOR local_47;
		struct tVECTOR_F4 local_44;
		D3DMATRIX local_40;
int _ocal_24[2];
		struct SVECTOR local_22;
		D3DVECTOR local_20;
		struct tVECTOR_F4 local_17;
int _ocal_13[3];
		D3DVECTOR local_10;
		struct tVECTOR_F4 local_7;
int _ocal_3[3];
	}lolo;

	lolo.local_73.vx = bp18->f_00.pad1;
	lolo.local_73.vy = -D_00DE6A04;
	lolo.local_73.vz = bp18->f_00.pad2;
	C_0074D33A(&lolo.local_73);//wm:set trans matrix from svector?
	lolo.local_20.x = lolo.local_55.x = /*lolo.local_121*/(float)bp08;
	lolo.local_47.z = lolo.local_55.z = /*lolo.local_122*/(float)bp0c;
	lolo.local_10.x = lolo.local_47.x = -lolo.local_20.x;
	lolo.local_10.z = lolo.local_20.z = -lolo.local_47.z;
	lolo.local_10.y = lolo.local_20.y = lolo.local_47.y = lolo.local_55.y = /*lolo.local_123*/(float)bp10;
	lolo.local_22.vx = lolo.local_22.vz = 0;
	lolo.local_22.vy = bp14;
	psx_RotMatrixXYZ(&lolo.local_22, &lolo.local_103);
	psx_MulRotMatrix0(&lolo.local_103, &lolo.local_87);
	psx_SetRotMatrix(&lolo.local_87);
	C_006617E9(C_0066100D(), &lolo.local_40);//psx:transformation to D3DMATRIX(3)
	C_0067D2BF(&lolo.local_40, &lolo.local_71);//dx_mat:matrix multiplication by "struct t_aa0::f_8d0" 4x4[transpose]
	fast_multVectorByTransform(&lolo.local_71, &lolo.local_10, &lolo.local_7);
	fast_multVectorByTransform(&lolo.local_71, &lolo.local_20, &lolo.local_17);
	fast_multVectorByTransform(&lolo.local_71, &lolo.local_47, &lolo.local_44);
	fast_multVectorByTransform(&lolo.local_71, &lolo.local_55, &lolo.local_52);
	lolo.local_88 = 1.0f / lolo.local_7.w;
	lolo.local_92 = 1.0f / lolo.local_17.w;
	lolo.local_104 = 1.0f / lolo.local_44.w;
	lolo.local_105 = 1.0f / lolo.local_52.w;
	bp18->f_00.x0 = C_0075F090(lolo.local_7.x * lolo.local_88);//wm:float to int
	bp18->f_00.y0 = C_0075F090(lolo.local_7.y * lolo.local_88);//wm:float to int
	bp18->f_00.x1 = C_0075F090(lolo.local_17.x * lolo.local_92);//wm:float to int
	bp18->f_00.y1 = C_0075F090(lolo.local_17.y * lolo.local_92);//wm:float to int
	bp18->f_00.x2 = C_0075F090(lolo.local_44.x * lolo.local_104);//wm:float to int
	bp18->f_00.y2 = C_0075F090(lolo.local_44.y * lolo.local_104);//wm:float to int
	bp18->f_00.x3 = C_0075F090(lolo.local_52.x * lolo.local_105);//wm:float to int
	bp18->f_00.y3 = C_0075F090(lolo.local_52.y * lolo.local_105);//wm:float to int
	fast_multVectorByRotTrans_Z_only(&lolo.local_40, &lolo.local_10, &lolo.local_76);
	fast_multVectorByRotTrans_Z_only(&lolo.local_40, &lolo.local_20, &lolo.local_79);
	fast_multVectorByRotTrans_Z_only(&lolo.local_40, &lolo.local_47, &lolo.local_91);
	fast_multVectorByRotTrans_Z_only(&lolo.local_40, &lolo.local_55, &lolo.local_95);
	lolo.local_108 = (int)min(min(lolo.local_76.z, lolo.local_79.z), lolo.local_91.z);
	bp18->f_00.y0 += bp1c;
	bp18->f_00.y1 += bp1c;
	bp18->f_00.y2 += bp1c;
	bp18->f_00.y3 += bp1c;
	lolo.local_108 = min(lolo.local_108, C_0075F090(lolo.local_95.z)) >> 4;//wm:float to int
	if(
		lolo.local_108 >= 0 && lolo.local_108 < 0x1000 &&
		C_0075F090(lolo.local_7.w) > 0 &&//wm:float to int
		C_0075F090(lolo.local_17.w) > 0 &&//wm:float to int
		C_0075F090(lolo.local_44.w) > 0 &&//wm:float to int
		C_0075F090(lolo.local_52.w) > 0//wm:float to int
	) {//else 0075DEA6
		if(C_0066E272(1, bp18->f_28)) {//else 0075DEA6
			if(C_0074C969()) {//wm:get "isRendering"?//else 0075DEA6
				lolo.fU0 = /*lolo.local_128*/(float)bp18->f_00.u0 * bp18->f_28->f_24;
				lolo.fV0 = /*lolo.local_129*/(float)bp18->f_00.v0 * bp18->f_28->f_28;
				lolo.fU1 = /*lolo.local_130*/(float)bp18->f_00.u1 * bp18->f_28->f_24;
				lolo.fV1 = /*lolo.local_131*/(float)bp18->f_00.v1 * bp18->f_28->f_28;
				lolo.fU2 = /*lolo.local_132*/(float)bp18->f_00.u2 * bp18->f_28->f_24;
				lolo.fV2 = /*lolo.local_133*/(float)bp18->f_00.v2 * bp18->f_28->f_28;
				lolo.fU3 = /*lolo.local_134*/(float)bp18->f_00.u3 * bp18->f_28->f_24;
				lolo.fV3 = /*lolo.local_135*/(float)bp18->f_00.v3 * bp18->f_28->f_28;
				//
				//
				//
				//
				//
				//
				//
				//
				//
				//
				//
				//
				if(lolo.local_7.z < lolo.local_17.z) {
					lolo.fZ = lolo.local_7.z;
				} else {
					lolo.fZ = lolo.local_17.z;
					lolo.local_88 = lolo.local_92;
				}
				if(lolo.fZ > lolo.local_44.z) {
					lolo.fZ = lolo.local_44.z;
					lolo.local_88 = lolo.local_104;
				}
				if(lolo.fZ > lolo.local_52.z) {
					lolo.fZ = lolo.local_52.z;
					lolo.local_88 = lolo.local_105;
				}
				lolo.fZ *= lolo.local_88;
				MK_VERTEX(&(bp18->f_28->f_70.asVertex[0]), lolo.local_117, (float)bp18->f_00.x0, (float)bp18->f_00.y0, lolo.fZ, 1.0f, bp18->f_2c, 0xff000000, lolo.fU0, lolo.fV0);
				MK_VERTEX(&(bp18->f_28->f_70.asVertex[1]), lolo.local_118, (float)bp18->f_00.x1, (float)bp18->f_00.y1, lolo.fZ, 1.0f, bp18->f_2c, 0xff000000, lolo.fU1, lolo.fV1);
				MK_VERTEX(&(bp18->f_28->f_70.asVertex[2]), lolo.local_119, (float)bp18->f_00.x2, (float)bp18->f_00.y2, lolo.fZ, 1.0f, bp18->f_2c, 0xff000000, lolo.fU2, lolo.fV2);
				MK_VERTEX(&(bp18->f_28->f_70.asVertex[3]), lolo.local_120, (float)bp18->f_00.x3, (float)bp18->f_00.y3, lolo.fZ, 1.0f, bp18->f_2c, 0xff000000, lolo.fU3, lolo.fV3);
				*(bp18->f_28->lpbCurPalette) = bp18->f_00.clut;
				bp18->f_28->dwLastPalette = bp18->f_00.clut;
			}
		}
	}
//0075DEA6
}

//wm:shadow related?
void C_0075DEAA(struct t_local_unknown_c0 *bp08) {
	struct {
		struct t_wm_local_30 *bp_10;
		DECL_short(bp_0c);
		DECL_short(bp_08);
		int bp_04;
	}lolo;

	lolo.bp_04 = 0x20 - ((bp08->sPos.vy - bp08->f_48) >> 8);
	if(lolo.bp_04 < 0)
		lolo.bp_04 = 0;
	lolo.bp_10 = &(bp08->f_90);
	lolo.bp_10->f_00.r0 =
	lolo.bp_10->f_00.g0 =
	lolo.bp_10->f_00.b0 = lolo.bp_04;
	lolo.bp_04 = 100 - ((bp08->sPos.vy - bp08->f_48) >> 6);
	switch(bp08->bModelType) {
		case WM_MODELID_04: case WM_MODELID_19: case WM_MODELID_41: case WM_MODELID_42:
			lolo.bp_0c =
			lolo.bp_08 = (lolo.bp_04 * 3) >> 1;
		break;
		case WM_MODELID_03:
			lolo.bp_0c = lolo.bp_04 * 2;
			lolo.bp_08 = (lolo.bp_04 * 3) * 2;
		break;
		case WM_MODELID_11:
			lolo.bp_0c = (lolo.bp_04 * 3) * 2;
			lolo.bp_08 = (lolo.bp_04 * 3) * 4;
		break;
		default:
			lolo.bp_0c = lolo.bp_04;
			lolo.bp_08 = lolo.bp_04;
	}//end switch
	C_0075D544(lolo.bp_0c, lolo.bp_08, bp08->f_48, 0x800 + bp08->f_3c + bp08->f_3e + C_0074D319() * 4, lolo.bp_10, 0);
}

//wm:<empty>
void C_0075E024(struct t_wm_b8 *_p08) {
}

//wm:init matrix(switch y z axis)?
void C_0075E029(LPD3DMATRIX bp08) {
	fast_MatrixSetIdentity(bp08);
	bp08->_22 = 0; bp08->_23 = 1.0f;
	bp08->_32 = -1.0f; bp08->_33 = 0;
}

//[local]matrix(transform) x vector(w=1)
void C_0075E062(LPD3DMATRIX bp08, LPD3DVECTOR bp0c, struct tVECTOR_F4 *bp10) {
	D3DVECTOR local_3;

	local_3.x = bp0c->x;
	local_3.y = bp0c->y;
	local_3.z = bp0c->z;
	dx_mat_multTransformByVector(bp08, &local_3, bp10);
}

int C_0075E09A(int dwModelType/*bp08*/) {
	if(dwModelType == WM_MODELID_18 || dwModelType == WM_MODELID_17 || dwModelType == WM_MODELID_27)
		return 1;
	else
		return 0;
}

//3d models related(character, plane, ...)?
void C_0075E0BA(struct t_wm_b8 *bp08, struct t_local_unknown_c0 *bp0c, short wAnim/*bp10*/, short wAnimFrame/*bp14*/, struct SVECTOR *bp18) {
	struct {//x298
		//local_165 and above for compiler
		struct t_ComplexBlendInfo local_163;
		int dwAlpha;//local_146
		int local_145;
		DECL_short(wTerrainType);
		D3DMATRIX local_143;
		D3DMATRIX local_127;
		D3DMATRIX local_111;
		D3DMATRIX local_95;
		DECL_unsigned_char(bModelType);
		D3DMATRIX local_78;
		D3DMATRIX local_62;
		DECL_struct_MATRIX(local_46);
		struct tVECTOR_F4 local_38;
		D3DMATRIX local_34;
		D3DMATRIX local_18;
		struct t_aa0 *local_2;
		struct VECTOR *local_1;
	}lolo;

	lolo.local_1 = &D_00E2D1E0;
	lolo.bModelType = bp0c?bp0c->bModelType:-1;
	C_0074D50E(bp08, bp18, &lolo.local_46, lolo.bModelType == C_00761735());
	lolo.wTerrainType = bp0c?bp0c->wTerrainInfo & 0x1f:0;
	lolo.local_2 = C_00676578();
	fast_MatrixSetIdentity(&lolo.local_95);
	C_0067CBF1(&lolo.local_95, lolo.local_2);//dx_mat:set "struct t_aa0::f_2fc"
	C_00661465(&lolo.local_46, &lolo.local_62);//psx:transformation to D3DMATRIX(2)
	bp08->f_44.sRot.x *= 360.0f/256.0f;//1.40625f
	bp08->f_44.sRot.y *= 360.0f/256.0f;//1.40625f
	bp08->f_44.sRot.z *= 360.0f/256.0f;//1.40625f
	C_0075E029(&lolo.local_34);//wm:init matrix(switch y z axis)?
	C_0075E062(&lolo.local_62, &(bp08->f_44.sPos), &lolo.local_38);//matrix(transform) x vector(w=1)
	bp08->f_44.sPos.x = lolo.local_38.x;
	bp08->f_44.sPos.y = lolo.local_38.y;
	bp08->f_44.sPos.z = lolo.local_38.z;
	C_0067BF2B(bp08->f_44.sRot.x, &lolo.local_18);//dx_mat:x_rotate(2)
	C_0067BFE6(bp08->f_44.sRot.y, &lolo.local_78);//dx_mat:z_rotate(2)
	fast_MatrixMultiplication3x3(&lolo.local_18, &lolo.local_78, &lolo.local_127);
	fast_MatrixMultiplication3x3(&lolo.local_62, &lolo.local_127, &lolo.local_143);
	fast_MatrixMultiplication3x3(&lolo.local_143, &lolo.local_34, &lolo.local_111);
	fast_MatrixResetTrans(&(bp08->f_44.f_2c));
	C_0067C251(&lolo.local_111, &(bp08->f_44.f_2c));//dx_mat:transpose matrix 3x3
	bp08->f_44.sRot.x = 0;
	bp08->f_44.sRot.y = 0;
	bp08->f_44.sRot.z = 0;
	bp08->wAnim = wAnim;
	bp08->dwAnimFrame = wAnimFrame;
	bp08->f_24 = 1;
	//-- unused stuff? --
	bp08->f_01 = 0;
	if(
		(
			((0x60400FA >> lolo.wTerrainType) & 1) &&
			C_0074D330() != 2 &&
			lolo.bModelType != WM_MODELID_03 &&
			lolo.bModelType != WM_MODELID_25
		) || lolo.bModelType == WM_MODELID_29
	) {
		bp08->f_01 = 0xe;
	}
	if(bp0c && bp0c->f_5e == 0xe && bp08->f_01 <= 0)
		C_0075E024(bp08);//wm:<empty>
	if(bp0c)
		bp0c->f_5e = bp08->f_01;
	if(0);
	//-- underwater models? --
	if(
		lolo.bModelType == WM_MODELID_18 ||
		lolo.bModelType == WM_MODELID_17 ||
		lolo.bModelType == WM_MODELID_26 ||
		lolo.bModelType == WM_MODELID_27 ||
		lolo.bModelType == WM_MODELID_28 ||
		lolo.bModelType == WM_MODELID_30
	) {//else 0075E4D1
		lolo.dwAlpha = 0xff - ((lolo.local_46.t[2] / 4 - 4000) >> 3);
		if(lolo.dwAlpha < 0)
			lolo.dwAlpha = 0;
		else if(lolo.dwAlpha > 0xff)
			lolo.dwAlpha = 0xff;
		lolo.local_145 = C_0075E09A(lolo.bModelType)?0xb:9;
		C_0068CF75(lolo.local_145, &lolo.local_163);//init/reset object struct t_ComplexBlendInfo *
		lolo.local_163.f_08 = C_0066101A();//psx:get FarColor
		lolo.local_163.f_08.c.a = lolo.dwAlpha;
		if(lolo.local_145 == 0xb)
			lolo.local_163.f_34[0] = 0;
		C_00684F73(&lolo.local_163, bp08->f_40);//anm:apply complex blend to skeleton?
	}
}

struct SVECTOR D_0096DD78[7] = {
	{ 50,  50,- 30},//wild chocobo
	{-30,  50,- 30},//chocobo #1
	{-30,  50,  50},//chocobo #2
	{-80,- 80,- 80},//chocobo #3
	{ 69,  17,-147},//chocobo #4
	{  0,-255,-255},//submarine #1
	{-17,- 15,  10} //submarine #2
};

//wm:apply tint to model?
void C_0075E4D6(short wModelId/*bp08*/, short wTintId/*bp0c*/) {
	struct {
		struct fBGRA local_8;
		int _ocal_4;
		struct t_wm_b8 *local_3;
		struct t_aa0 *local_2;
		struct VECTOR *local_1;
	}lolo;

	lolo.local_1 = &D_00E2D1E0;
	lolo.local_3 = C_00768A37(wModelId);
	lolo.local_2 = C_00676578();
	if(lolo.local_3) {
		lolo.local_8.r = (float)D_0096DD78[wTintId].vx * (1.0f/255.0f);//0.003921569f
		lolo.local_8.g = (float)D_0096DD78[wTintId].vy * (1.0f/255.0f);//0.003921569f
		lolo.local_8.b = (float)D_0096DD78[wTintId].vz * (1.0f/255.0f);//0.003921569f
		lolo.local_8.a = 1.0f;
		C_00684ECD(lolo.local_3->f_40, lolo.local_2);//anm:apply restore color to skeleton?
		C_00684E20(&lolo.local_8, lolo.local_3->f_40, lolo.local_2);//anm:apply add color to skeleton?
		C_006850DB(lolo.local_3->f_40);//anm:apply backup color to skeleton?
	}
}

//wm:music init
void C_0075E59A(int _p08) {
	D_00E35654 = 0;
	D_00E35658 = 0;
}

//wm:set music related flag on/off
void C_0075E5B3(int bp08) {
	D_00E35654 = bp08;
}

//wm:play song
void C_0075E5C0(int bp08) {
	if(D_00E35654) {//else 0075E622
		int local_1 = /*local_2*/(bp08 == 1)?SOUND_OP_18/*"MUSIC"+cross fade*/:
			(D_00E35658 == 1)?SOUND_OP_14/*"MUSVT"*/:
			SOUND_OP_10/*"MUSIC"*/
		;
		C_00740D80(local_1, D_00E2D608[bp08 - 1], 4, 0, 0, 0, 0, 0, 0);
	}
	D_00E3564C = D_00E35658;
	D_00E35658 = bp08;
}

//wm:play current song?
void C_0075E63A() {
	C_0075E5C0(D_00E35658);//wm:play song
}

//wm:get current song?
int C_0075E64D() {
	return D_00E35658;
}

//wm:play SFX?
void C_0075E657(int bp08) {
	C_0074580A(bp08);//sound:play SE?
	if(bp08 == 0xb)
		C_00753860();//fade in/out related(1)?
	else if(bp08 == 0x1b1)
		C_00753888();//fade in/out related(3)?
}

//wm:stop sfx and music?
void C_0075E683() {
	C_00745B64();//sound:stop(2)?
	C_007481AD(0);//sound:tempo[all channels]
}

//wm:set music volume
void C_0075E697(int bp08) {
	C_00742F37(bp08);//"MIDI set volume"
}

//wm:engine noise params[for buggy]?
void C_0075E6A8(int bp08, int bp0c) {
	C_007481DF(bp0c, bp08);//sound:tempo transition[all channels]
}

//wm:reset SFX?
void C_0075E6BD() {
	D_00E360EC = 0;
}

//wm:start/stop SFX?
void C_0075E6CC(int nSoundId) {
	if(nSoundId > D_00E360EC) {
		D_00E360EC = nSoundId;
		C_00745606(0x40, nSoundId, 0, 0, 0);
	} else if(nSoundId == -D_00E360EC) {
		D_00E360EC = 0;
		C_00745B64();//sound:stop(2)?
		C_007481AD(0);//sound:tempo[all channels]
	}
}

//wm:set song list
void C_0075E720(int bp08) {
	switch(bp08) {
		case 0:
		case 9:
			D_00E2D608 = D_0096D598;
		break;
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 10:
			D_00E2D608 = D_0096D5A0;
		break;
		case 11:
			D_00E2D608 = D_0096D5A8;
		break;
		case 12:
			D_00E2D608 = D_0096D5B0;
		break;
	}//end switch
}
