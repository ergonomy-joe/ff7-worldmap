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
#define WM_MAINSTATE_0 0
#define WM_MAINSTATE_1 1
#define WM_MAINSTATE_LEAVEWORLD 2
#define WM_MAINSTATE_3 3
#define WM_MAINSTATE_TOUNDERSEA 4
#define WM_MAINSTATE_TOSURFACE 5

#define WM_MAINSTATE_6 6
#define WM_MAINSTATE_7 7
#define WM_MAINSTATE_8 8
#define WM_MAINSTATE_9 9
////////////////////////////////////////
//unused stuff(remains from psx)?
//(looks like struct t_battle_40f4)
struct t_pepe_4074 {//size 0x4074
	/*0000*/char f_0000[0x70];//__00DFC4F0
	/*0070*/int f_0070[0x1000];//0DFC560
	/*4070*/struct POLY_GT3 *f_4070;//0E00560//0E045D4
};
////////////////////////////////////////
//texture animation related
short D_009699B0[0x16] = {
	0x00,0x08,0x10,0x18,0x20,0x28,0x2C,0x30,
	0x34,0x38,0x3C,0x40,0x44,0x48,0x4C,0x50,
	0x54,0x58,0x5C,0x60,0x64,0x68
};
//009699DC  00 00 00 00
struct {
	int D_009699E0;// = 400;//90 01 00 00
	int __009699E4;//  00 00 00 00
	int __009699E8;//  00 00 00 00
	int __009699EC;//  0C 00 00 00
	int __009699F0;//  22 00 00 00
} some_world_obj = {
	400,
	0,
	0,
	0xc,
	0x22
};
//009699F4  00 00 00 00
const char *__009699F8[] = {
	/*00969A78*/"SCR-H",
	/*00969A80*/"FROM ",
	/*00969A88*/"JUMP ",
	/*00969A90*/"OLD  ",
	/*00969A98*/"NEW  ",
};
//00969A0C  00 00 00 00
const char *D_00969A10[] = {
	/*00969AA0*/".MAP",
	/*00969AA8*/".BOT",
	/*00969AB0*/".TXZ",
	/*00969AB8*/".EV",
	/*00969ABC*/".BSZ",
	/*00969AC4*/"S.TXZ"
};
const char *D_00969A28[] = {
	/*00969AD4*/".MAP",
	/*00969ADC*/".BOT",
	/*00969AE4*/".TXZ",
	/*00969AEC*/".EV",
	/*00969AF0*/".BSZ",
	/*00969AF8*/"S.TXZ"
};
//bit masks?
int D_00969A40[] = {
	0x321B6F83,
	0x321B6F87,
	0x321B6FF3,
	0x325B7FF7,
	0x375B7FFF,
	0
};
//00969A54  00 00 00 00
int D_00969A58[] = { 1500,1800,1800,1800};
int D_00969A68[] = {10000,7000,7000,4000};
//00969A78	"SCR-H"
//00969A80	"FROM "
//00969A88	"JUMP "
//00969A90	"OLD  "
//00969A98	"NEW  "
//00969AA0	".MAP"
//00969AA8	".BOT"
//00969AB0	".TXZ"
//00969AB8	".EV"
//00969ABC	".BSZ"
//00969AC4	"S.TXZ"

//00969ACC	"wm/WM"

//00969AD4	".MAP"
//00969ADC	".BOT"
//00969AE4	".TXZ"
//00969AEC	".EV"
//00969AF0	".BSZ"
//00969AF8	"S.TXZ"

//00969B00	"WM"
//00969B04	"wm.ta"
//00969B0C	"mes"
//00969B10	"field.tbl"
//00969B1C	"atn.tbl"
//00969B24	"enc_w.bin"
////////////////////////////////////////
int D_00DE6A04;
int D_00DE6A08;//highwind state
int D_00DE6A0C;
struct POLY_GT3 *D_00DE6A10;
int D_00DE6A14;
short D_00DE6A18;
int D_00DE6A1C;//backbuffer index?
struct MATRIX D_00DE6A20;//[camera]trans matrix?
int D_00DE6A40;
char D_00DE6A48[0x100];//todo
int D_00DE6B48;
int D_00DE6B4C;
int D_00DE6B54;//chocobo related parameter?
int D_00DE6B58;//[camera altitude]some flag
int D_00DE6B5C;//flag enable something?
int D_00DE6B60;
int D_00DE6B64;//[camera altitude]some counter
int D_00DE6B6C;//[camera altitude]some counter
int D_00DE6B70;//[camera]tilt angle?
struct t_wm_8a0 D_00DE6B78;//"enc_w.bin"
short D_00DE7418;
int D_00DE741C;
unsigned char D_00DE7420[0xe000];//"wm.ta"
int D_00DF5420;
int D_00DF5424;//rotation increment
int D_00DF5428;
int D_00DF542C;
short D_00DF5430;
int D_00DF5434;
int D_00DF5438;//[camera altitude]z patch
char *D_00DF543C;
int D_00DF5440;//[camera altitude]some flag(previous state)
struct POLY_GT3 *D_00DF5444;
unsigned char D_00DF5448[0x7000];//"WM?.EV"
struct MATRIX D_00DFC448;//[camera]rot matrix?
int D_00DFC468;//[camera]
int D_00DFC46C;
int D_00DFC470;//previous input mask
int D_00DFC474;
int D_00DFC478;//[camera]
int D_00DFC47C;
int D_00DFC480;//engine speed parameter[set to 2]?
int D_00DFC484;
int D_00DFC488;//unused stuff?
int D_00DFC48C;//some zoom/rotation state
int D_00DFC490;
int D_00DFC494;//some fade in/out state
int D_00DFC498;
int D_00DFC49C;
int D_00DFC4A0;//earthquake effect flag
int D_00DFC4A4;//[camera altitude]some counter
int D_00DFC4A8;
int D_00DFC4AC;
int D_00DFC4B4;//view mode?
int D_00DFC4B8;//always 0[debug stuff]?
int D_00DFC4BC;//[camera altitude]some flag
char D_00DFC4C0[0x30];
struct t_pepe_4074 D_00DFC4F0[2];
int D_00E045D8;
int D_00E045DC;//previous view mode?
int D_00E045E0;//thrust?
int D_00E045E4;//main state?
int D_00E045E8;//current map?[0:surface,1:?2:undersea,3:snowland]
int D_00E045EC;//go to menu flag
int D_00E045F0;
//00E045F4
////////////////////////////////////////
//<empty>:some error management?
void C_0074C9A0(int _p08) {
}

//wm:get backbuffer index[unused]?
int C_0074C9A5() {
	return D_00DE6A1C;
}

//wm:alloc mem for POLY_GT3[unused]?
struct POLY_GT3 *C_0074C9AF(unsigned dwCount/*bp08*/) {
	struct POLY_GT3 *local_1;

	if(&(D_00DE6A10[dwCount]) < &(D_00DF5444[0xd00])) {
		local_1 = D_00DE6A10;
		D_00DE6A10 += dwCount;
	} else {
		C_0074C9A0(1);//<empty>:some error management?
	}

	return local_1;
}

//wm:make path(1)
char *C_0074CA00(int bp08, int bp0c) {
	char local_1[2];

	strcpy(D_00DE6A48, D_009A06B8);//DataPath
	strcat(D_00DE6A48, /*00969ACC*/"wm/WM");
	local_1[0] = (bp0c < 10)?bp0c + '0':bp0c + 'A' - 10;
	local_1[1] = 0;
	strcat(D_00DE6A48, local_1);
	strcat(D_00DE6A48, D_00969A10[bp08]);

	return D_00DE6A48;
}

//make path(2)
char *C_0074CAEC(int bp08, int bp0c) {
	char local_1[2];

	//
	strcpy(D_00DFC4C0, /*00969B00*/"WM");
	local_1[0] = (bp0c < 10)?bp0c + '0':bp0c + 'A' - 10;
	local_1[1] = 0;
	strcat(D_00DFC4C0, local_1);
	strcat(D_00DFC4C0, D_00969A28[bp08]);

	return D_00DFC4C0;
}

//wm:set earthquake effect
void C_0074CBB5(int bp08) {
	D_00DFC4A0 = bp08;
}

//(unused stuff)
void *C_0074CBC2() {
	struct {
		void *local_2;
		int local_1;
	}lolo;

	lolo.local_1 = 2500;
	if(lolo.local_1 > 0xfff)
		lolo.local_1 = 0xfff;
	if(D_00DFC4AC)
		lolo.local_2 = &(D_00E36114[lolo.local_1]);
	else
		lolo.local_2 = 0;

	return lolo.local_2;
}

int C_0074CECA(int, unsigned char);//terrain/vehicle check?

int C_0074CC07(struct t_wm_TerrainChunkInfo *bp08, struct SVECTOR *bp0c, struct t_wm_local_08 *bp10, short *bp14, struct t_wm_TerrainTriangle **bp18, short *bp1c, unsigned char bModelId/*bp20*/) {
	struct {
		int dwTerrainInfo;//local_12
		int local_11;
		struct t_wm_TerrainTriangle *local_10;
		int local_9;
		struct t_wm_TerrainTriangle *local_8;
		int local_7;
		struct SVECTOR *local_6;//size 8
		struct t_wm_local_08 *local_5;//size 8
		int local_4;
		int local_3;
		int local_2;
		int local_1;
	}lolo;

	lolo.local_6 = &D_00E2D5D8;
	*lolo.local_6 = *bp0c;
	lolo.local_2 = *bp14;
	lolo.local_9 = 0x7fffffff;
	lolo.local_3 = 0;
	lolo.local_10 = 0;
	//-- --
	if(bp10) {
		for(lolo.local_5 = &(bp10[0]); lolo.local_5 < &(bp10[6]) && lolo.local_3 <= 0; lolo.local_5 ++) {
			if(lolo.local_5->f_00)
			if(lolo.local_5->wChunkX == bp08->wChunkX && lolo.local_5->wChunkY == bp08->wChunkY)
			if(C_0076085F(lolo.local_5->f_00, lolo.local_6, &lolo.local_1)) {
				lolo.dwTerrainInfo = lolo.local_5->f_00->f_03 | (lolo.local_5->f_00->f_0b << 8);
				lolo.local_11 = lolo.local_1;
				lolo.local_3 = -1;
				if(C_0074CECA(lolo.dwTerrainInfo, bModelId)) {//terrain/vehicle check?
					lolo.local_10 = lolo.local_5->f_00;
					lolo.local_3 = 1;
				}
			}
		}//end for
	}
	//-- --
	if(lolo.local_3 == 0) {//else 0074CE8F
		for(lolo.local_8 = &(bp08->f_04[0]); lolo.local_8 < &(bp08->f_04[bp08->wTriangleCount]); lolo.local_8 ++) {
			if(C_0076085F(lolo.local_8, lolo.local_6, &lolo.local_1)) {
				lolo.local_7 = lolo.local_8->f_03 | (lolo.local_8->f_0b << 8);
				lolo.local_4 = /*lolo.local_14*/(
					bModelId != WM_MODELID_03 &&
					bModelId != WM_MODELID_05 &&
					D_00E045E8 != 2
				)?/*lolo.local_13*/inline_abs(lolo.local_1 - lolo.local_2):lolo.local_1;
				if(lolo.local_9 > lolo.local_4) {
					lolo.local_3 ++;
					lolo.local_9 = lolo.local_4;
					lolo.local_10 = lolo.local_8;
					lolo.dwTerrainInfo = lolo.local_7;
					lolo.local_11 = lolo.local_1;
				}
			}
		}//end for
		if(lolo.local_3 != 0) {//else 0074CE8F
			if(bp10 && lolo.local_10) {//else 0074CE6D
				for(lolo.local_5 = &(bp10[4]); lolo.local_5 >= &(bp10[0]); lolo.local_5 --)
					lolo.local_5[1] = lolo.local_5[0];
				bp10->f_00 = lolo.local_10;
				bp10->wChunkX = bp08->wChunkX;
				bp10->wChunkY = bp08->wChunkY;
			}
			if(!C_0074CECA(lolo.dwTerrainInfo, bModelId)) {//terrain/vehicle check?
				lolo.local_10 = 0;
				lolo.local_3 = 0;
			}
		}
	}
	if(bp1c)
		*bp1c = lolo.dwTerrainInfo;
	if(bp14)
		*bp14 = lolo.local_11;
	if(bp18)
		*bp18 = lolo.local_10;

	return lolo.local_3 > 0;
}

int C_0074DB52(void);//get chocobo tint?

//terrain/vehicle check?
int C_0074CECA(int dwTerrainInfo/*bp08*/, unsigned char bModelId/*bp0c*/) {
	struct {
		int bp_08;
		int bp_04;
	}lolo;

	lolo.bp_08 = (dwTerrainInfo & 0xe0) != 0xe0;
	lolo.bp_04 = /*bp_0c*/
		(C_00762136() == 0xd || C_00762136() == 0xe/*bridge?*/) &&//wm:get current terrain?
		(C_00761735() == bModelId)//wm:get model type(2)?
	;
	switch(bModelId) {
		case WM_MODELID_00:
		case WM_MODELID_01:
		case WM_MODELID_02:
			return BIT_ISSET_2(lolo.bp_04?0x20006000:0x721B6F83, dwTerrainInfo);
		case WM_MODELID_04:
			if(C_00766B53() == 2)//wm:get "leave vehicle" state?
				return BIT_ISSET_2(lolo.bp_04?0x20006000:0x321B6F83, dwTerrainInfo) && lolo.bp_08;
			return BIT_ISSET_2(lolo.bp_04?0x20006000:0x321B6F83, dwTerrainInfo);
		case WM_MODELID_19:
			if(C_00766B53() == 2)//wm:get "leave vehicle" state?
				return BIT_ISSET_2(lolo.bp_04?0x20006000:0x321B6F83, dwTerrainInfo) && lolo.bp_08;
			return BIT_ISSET_2(lolo.bp_04?0x20006000:D_00969A40[C_0074DB52()], dwTerrainInfo);
		case WM_MODELID_03:
			if(C_00766B53() == 2)//wm:get "leave vehicle" state?
				return BIT_ISSET_2(0x021B6F83, dwTerrainInfo) && lolo.bp_08;
			return D_00DE6A08 >= 0?1:((dwTerrainInfo & 0x1f)?0:1);
		case WM_MODELID_05:
			if(C_00761FE8()) {
				if(C_00766B53() == 2)//wm:get "leave vehicle" state?
					return BIT_ISSET_2(0x70, dwTerrainInfo);
				return D_00DE6A08 >= 0?1:BIT_ISSET_2(0x70, dwTerrainInfo);
			}
			if(C_00766B53() == 2)//wm:get "leave vehicle" state?
				return BIT_ISSET_2(0x20800, dwTerrainInfo);
			return BIT_ISSET_2(0x70, dwTerrainInfo);
		case WM_MODELID_06:
			if(C_00766B53() == 2)//wm:get "leave vehicle" state?
				return BIT_ISSET_2(0x21B6F83, dwTerrainInfo) && lolo.bp_08;
			return BIT_ISSET_2(0x331B6F13, dwTerrainInfo);
		case WM_MODELID_13:
			if(C_00766B53() == 2)//wm:get "leave vehicle" state?
				return BIT_ISSET_2(0x21B6F83, dwTerrainInfo) && lolo.bp_08;
			return BIT_ISSET_2(0x4048008, dwTerrainInfo);
		case WM_MODELID_08:
			return BIT_ISSET_2(0x4040008, dwTerrainInfo);
		case 100://for midgar zolom
			return (dwTerrainInfo & 0x1f) == 7;
	}//end switch

	return 1;
}

//wm:get view mode?
//0:fix(walking)
//
//2:free cam
//3:highwind?
int C_0074D28E() {
	return D_00DFC4B4;
}

int C_0074D298() {
	return D_00DFC474 & 0xfff;
}

void C_0074D2A7(int bp08) {
	D_00DFC484 = bp08 & 0xfff;
}

void C_0074D2B9(int bp08) {
	D_00DFC474 =
	D_00DFC484 = bp08 & 0xfff;
}

//wm:set some zoom/rotation mode?
void C_0074D2D7(int bp08) {
	D_00DFC48C = bp08;
	if(bp08 == 1) {
		D_00DFC47C = D_00969A68[D_00DFC4B4];
		D_00DE6A0C = D_00969A58[D_00DFC4B4];
	}
}

//wm:get some zoom/rotation mode?
int C_0074D30F() {
	return D_00DFC48C;
}

//wm:get camera tilt angle?
int C_0074D319() {
	return D_00DE6B70;
}

//wm:set camera tilt angle?
void C_0074D323(int bp08) {
	D_00DE6B70 = bp08;
}

//wm:get current map id?
int C_0074D330() {
	return D_00E045E8;
}

//wm:set trans matrix from svector?
void C_0074D33A(struct SVECTOR *bp08) {
	struct {
		DECL_struct_MATRIX(local_15);
		struct VECTOR local_7;
		int dwFlags_unused;//local_3
		struct SVECTOR local_2;
	}lolo;

	lolo.local_2 = *bp08;
	lolo.local_2.vy = -D_00DE6A04;
	psx_SetRotMatrix(&D_00DFC448);
	psx_SetTransMatrix(&D_00DE6A20);
	psx_RotTrans(&lolo.local_2, &lolo.local_7, &lolo.dwFlags_unused);
	psx_TransMatrix(&lolo.local_15, &lolo.local_7);
	psx_SetTransMatrix(&lolo.local_15);
}

void C_0074D3A7() {
	psx_SetRotMatrix(&D_00DFC448);
	psx_SetTransMatrix(&D_00DE6A20);
}

short C_0074D3C6() {
	return D_00DE7418;
}

//wm:set view mode?
void C_0074D3D1(int bp08) {
	D_00E045DC = D_00DFC4B4;
	D_00DFC4B4 = bp08;
	if((D_00DFC4B4 == 0 || D_00DFC4B4 == 1) && D_00E045E8 != 3)
		D_00DFC484 = 0;
	D_00DF542C = (D_00DFC4B4 != 0)?160:120;
	D_00DE741C = (D_00DFC4B4 != 3) * 120;
}

//wm:set enable something?
void C_0074D438(int dwEnable/*bp08*/, int bp0c) {
	struct VECTOR local_4;

	if(dwEnable) {
		if(bp0c == D_00DFC4A8 || D_00DFC4A8 == 6) {
			D_00DE6B5C = 1;
			C_00762798(&local_4);//wm:get model pos(2)?
			C_0075027C(&local_4, (bp0c == 3 && D_00DFC4A8 != 6)?0:1);//wm:set some pos?
		}
	} else {
		D_00DE6B5C = 0;
		D_00DFC4A8 = bp0c;
	}
}

//wm:get enable something?
int C_0074D4B6() {
	return D_00DE6B5C;
}

void C_0074D4C0(short bp08) {
	D_00DF5434 = bp08 + D_00DFC484 - 0x800;
}

//wm:returns true[debug stuff]?
int C_0074D4DC() {
	return D_00DFC4B8 == 0;
}

int C_0074D4ED() {
	return D_00E045D8;
}

//wm:set "highwind" state?
//1 go up?
//-1 go down?
void C_0074D4F7(int bp08) {
	D_00DE6A08 = bp08;
}

//wm:get "highwind" state?
int C_0074D504() {
	return D_00DE6A08;
}

void C_0074D50E(struct t_wm_b8 *bp08, struct SVECTOR *pRot/*bp0c*/, struct MATRIX *bp10, int bp14) {
	struct {
		DECL_struct_MATRIX(local_15);
		int dwFlags_unused;//local_7
		struct VECTOR local_6;
		struct SVECTOR local_2;
	}lolo;

	//-- make identity matrix --
	lolo.local_15.m[0][0] =
	lolo.local_15.m[1][1] =
	lolo.local_15.m[2][2] = 0x1000;

	lolo.local_15.m[0][1] = lolo.local_15.m[0][2] =
	lolo.local_15.m[1][0] = lolo.local_15.m[1][2] = 
	lolo.local_15.m[2][0] = lolo.local_15.m[2][1] = 0;
	//-- --
	psx_RotMatrixX(pRot->vx, &lolo.local_15);
	psx_RotMatrixZ(pRot->vz, &lolo.local_15);
	psx_RotMatrixY(pRot->vy, &lolo.local_15);
	psx_MulMatrix0(&D_00DFC448, &lolo.local_15, bp10);
	psx_SetRotMatrix(&D_00DFC448);
	if(D_00DFC46C > 0 && bp14) {
		lolo.local_6.vx = D_00DE6A20.t[0] / 2;
		lolo.local_6.vy = D_00DE6A20.t[1] / 2;
		lolo.local_6.vz = D_00DE6A20.t[2] / 2;
		D_00DFC46C --;
		if(D_00DFC46C == 0)
			C_0075E5C0(D_00E3564C);//wm:play song
	} else {
		lolo.local_6.vx = D_00DE6A20.t[0];
		lolo.local_6.vy = D_00DE6A20.t[1];
		lolo.local_6.vz = D_00DE6A20.t[2];
	}
	psx_TransMatrix(bp10, &lolo.local_6);
	psx_SetTransMatrix(bp10);
	lolo.local_2.vx = /*ftol*/(short)bp08->f_44.sPos.x;
	lolo.local_2.vy = /*ftol*/(short)bp08->f_44.sPos.y;
	lolo.local_2.vz = /*ftol*/(short)bp08->f_44.sPos.z;
	psx_RotTrans(&lolo.local_2, &lolo.local_6, &lolo.dwFlags_unused);
	bp08->f_44.sPos.x =
	bp08->f_44.sPos.y =
	bp08->f_44.sPos.z = 0;
	psx_TransMatrix(bp10, &lolo.local_6);
}

//wm:go to surface
void C_0074D6BB() {
	D_00E045E4 = WM_MAINSTATE_TOSURFACE;
	D_00DFC490 = 20;
	C_007670F9(0);//wm:field infos related?
	C_0074D438(0, 0);//wm:set enable something?
	C_00755B97(0x10, 1);//wm:start fade out?
}

//go to undersea
void C_0074D6F6() {
	D_00E045E4 = WM_MAINSTATE_TOUNDERSEA;
	D_00DFC490 = -20;
	C_007670F9(0);//wm:field infos related?
	C_0074D438(0, 0);//wm:set enable something?
	C_00755B97(0x10, 1);//wm:start fade out?
}

//wm:go to field?
void C_0074D731(int bp08) {
	C_007670F9(bp08);//wm:field infos related?
	D_00E045E4 = WM_MAINSTATE_8;
}

void C_0074D74C(int bp08) {
	if(D_00E045E4 < WM_MAINSTATE_1) {
		D_00DFC47C =
		D_00DE6A0C = 0;
		D_00DFC4AC = 1;
		D_00E045E4 = WM_MAINSTATE_1;
	}
	if(D_00E045E4 == WM_MAINSTATE_1) {
		D_00E045E4 = WM_MAINSTATE_LEAVEWORLD;
		C_0074D438(0, 0);//wm:set enable something?
		C_007670F9(bp08);//wm:field infos related?
		C_00755B97(0x10, 1);//wm:start fade out?
		D_00E045F0 = 1;
		C_0074C980(0);//wm:set "allowsFrameSkip"?
	}
}

void C_0074D7CD(int dwEncounterId/*bp08*/) {
	if(D_00E045E4 < WM_MAINSTATE_1) {
		D_00DFC47C =
		D_00DE6A0C = 0;
		D_00DFC4AC = 1;
		D_00E045E4 = WM_MAINSTATE_1;
	}
	if(D_00E045E4 == WM_MAINSTATE_1 || D_00E045E4 == WM_MAINSTATE_LEAVEWORLD) {
		if(D_00CBFB6C == 0) {
			D_00E045E4 = WM_MAINSTATE_3;
			C_0074D438(0, 0);//wm:set enable something?
			C_0076717C(dwEncounterId);
			if(C_007538B0())//get fade in/out info?
				C_0075389C();
			C_0074C973(1);//wm:set "isRendering"?
			C_0074C980(0);//wm:set "allowsFrameSkip"?
		} else {
			D_00DFC46C = 30;
			C_00767515();
		}
	}
}

void __0074D875() {
	if(D_00E045E4 < WM_MAINSTATE_1) {
		D_00DFC47C =
		D_00DE6A0C = 0;
		D_00DFC4AC = 1;
		D_00E045E4 = WM_MAINSTATE_1;
	}
	if(D_00E045E4 == WM_MAINSTATE_1) {
		D_00E045E4 = WM_MAINSTATE_3;
		C_0074D438(0, 0);//wm:set enable something?
		C_007671E1();
	}
}

//wm:get view mod/map|radar state
int C_0074D8CF() {
	return
		(D_00DFC4B4 & 3) |
		((C_00768343() << 2) & 0xc)//wm:get map/radar state
	;
}

//wm:set view mod/map|radar state
void C_0074D8EF(int bp08) {
	C_0074D3D1(bp08 & 3);//wm:set view mode?
	C_0076831F((bp08 >> 2) & 3);//wm:set map/radar state
}

//wm:get string from "mes"
unsigned char *C_0074D915(short bp08) {
	if(bp08 >= 0 && bp08 < *(short *)(D_00E36118 + 8))
		return (D_00E36118 + 8) + ((short *)(D_00E36118 + 8 + 2))[bp08];

	return 0;
}

//reset some fade in/out?
void C_0074D946() {
	D_00DFC494 = 0;
}

//wm:start some fade in/out?
void C_0074D955(int bp08) {
	switch(bp08) {
		case 1://start some fade out?
			C_0074D438(0, 4);//wm:set enable something?
			C_00755B97(4, 1);//wm:start fade out?
		break;
		case 4://start some fade in?
			C_0074D438(1, 4);//wm:set enable something?
			C_00755B70(0x10, 1);//wm:start fade in?
			bp08 = 0;
		break;
	}//end switch
	D_00DFC494 = bp08;
}

//refresh some fade in/out?
void C_0074D9B3() {
	struct {
		int dwFrameCount;//local_2
		int local_1_unused;
	}lolo;

	//-- --
	lolo.local_1_unused = C_0074C9A5();//wm:get backbuffer index[unused]?
	//-- --
	switch(D_00DFC494) {
		case 1:
			if(C_00755C2F())//wm:is fade in/out over?
				D_00DFC494 = 2;
		break;
		case 2:
			lolo.dwFrameCount = C_0040AC84();//get frame count
			if(lolo.dwFrameCount - D_00DF5428 > 3 && lolo.dwFrameCount - D_00DF5428 < 6)
				D_00DFC494 = 3;
			D_00DF5428 = lolo.dwFrameCount;
		break;
	}//end switch
}

//wm:set some rotation param
void C_0074DA26(int bp08) {
	D_00DF5424 = bp08;
}

//wm:set some zoom param(1)
void C_0074DA33(int bp08) {
	D_00DE6B60 = bp08;
}

//set some zoom param(2)
void C_0074DA40(int bp08) {
	D_00DFC498 = bp08;
}

//refresh some zoom/rotation?
//(this functionality is used when Ruby Weapon
//emerges from the earth, or during the warship
//cutscenes sequences, for instance)
void C_0074DA4D() {
	switch(D_00DFC48C) {
		case 0:
			D_00DFC484 += D_00DF5424;
			D_00DFC47C =
			D_00DE6A0C = 0;
		break;
		case 1:
			D_00DFC484 += D_00DF5424;

			D_00DFC47C += D_00DFC498;
			if(D_00DFC47C > 15000)
				D_00DFC47C = 15000;
			else if(D_00DFC47C < 1000)
				D_00DFC47C = 1000;

			D_00DE6A0C += D_00DE6B60;
			if(D_00DE6A0C > 1920)
				D_00DE6A0C = 1920;
			else if(D_00DE6A0C < 1152)
				D_00DE6A0C = 1152;
		break;
	}//end switch
}

//wm:set some zoom/rotation parameter(1)?
void C_0074DB2B(int bp08) {
	D_00DFC47C = bp08;
}

//wm:set some zoom/rotation parameter(2)?
void C_0074DB38(int bp08) {
	D_00DE6A0C = bp08;
}

//wm:set chocobo tint?
void C_0074DB45(int bp08) {
	D_00DE6B54 = bp08;
}

//get chocobo tint?
int C_0074DB52() {
	return D_00DE6B54;
}

void __0074DB5C() {
}

void C_0074DB61() {
	if(!D_00DE69E0 && !D_00DE69E4) {
		D_00E045E4 = WM_MAINSTATE_0;
		D_00DE69E4 = 1;
	}
}

void C_0074E1E9(short);
void C_0074E48A(void);
void C_0074E505(void);
void C_0074E633(int);//render sky gradation?
void C_0074E802(int);//texture animation
void C_0074E8CE(short);//compute camera matrix?
void C_0074EA48(void);//controls update?
void C_0074F87D(void);
void C_0074FBCA(void);
void C_0074FBEC(void);
void C_0074FE89(void);//refresh camera "altitude"

int C_0074DB8C(int *pForDispatcher/*bp08*/, int *pForField/*bp0c*/, int *pForBattle/*bp10*/, int always_0/*bp14*/) {
	struct {
		int local_7;
		struct VECTOR local_6;
		int local_2;
		int local_1;
	}lolo;
	
	C_0074DB61();
	//-- --
	D_00DFC488 = 0;
	D_00DFC488 = always_0;
	//-- --
	if(D_00E045E4 < WM_MAINSTATE_9) {//else 0074E1E0
		//-- init/reset some stuff --
		if(!D_00DE69E0) {//else 0074DE7C
			//-- set map id --
			D_00E045E8 =
				/*lolo.local_8*/*pForDispatcher != 0?C_00766C6E()://wm:get saved map id?
				/*lolo.local_10*/(D_00E045E4 == WM_MAINSTATE_6 || *pForField == 0x1e || *pForField == 0x1f || *pForField == 0x2a || *pForField == 0x38)?2:
				/*lolo.local_9*/(D_00E045E4 != WM_MAINSTATE_7 && *pForField >= 0x3c)?3:
				0
			;
			//-- --
			lolo.local_2 = C_00766B9F();
			C_0074E1E9(
				//warship cutscenes?
				/*lolo.local_11*/(*pForDispatcher == 0 && *pForField >= 0x24 && *pForField <= 0x27)?(lolo.local_2 > 0)?10:9:
				//
				(D_00E045E8 == 0)?lolo.local_2:D_00E045E8 + 9
			);
			C_0075E683();//wm:stop sfx and music?
			C_00768C4C(lolo.local_2 == 3 || lolo.local_2 == 4 || lolo.local_2 == 6 || lolo.local_2 == 8);//wm:set "highwind has reactor"?
			D_00DFC4B4 = 0;
			C_00767D40();//wm:reset map/radar
			C_00750473();//wm:terrain init/reset stuff?
			C_00766C7A(pForDispatcher, pForField, D_00E045E8 != 3);
			if(D_00E045E8 == 2)
				C_0074D3D1(2);//wm:set view mode?
			D_00DE741C = 0;
			C_0074F87D();
			C_0074E48A();
			C_007538BA();
			C_00754E1D();//wm:init sky color?
			C_00755495();
			C_00756A95();
			C_00767501();
			C_00767533(1);//wm:set random inhibits encounter?
			C_0074D946();//reset some fade in/out?
			C_0075EE50(D_00E36118);
			C_00755F95();//wm:midgar zolom related.init/reset?
			C_007543D3();//wm:init meteor related stuff?
			C_0075AC80();
			C_0076110B();
			C_007663E0();
			C_0075E697(0x7f);//wm:set music volume
			C_00763C35(&D_00DF5448);//set "WM?.EV" content
			C_007640BC(0);//wm:start script(2)?
			C_007641A7();//wm:execute scripts?
			D_00DF5420 = (C_00761735() != WM_MODELID_03)?2000:4000;//wm:get model type(2)?
			if(*pForDispatcher == 1 || *pForDispatcher == 2 || D_00E045E4 == WM_MAINSTATE_7 || D_00E045E4 == WM_MAINSTATE_6)
				C_00767097();
			if(D_00E045E4 == WM_MAINSTATE_7 || D_00E045E4 == WM_MAINSTATE_6)
				C_0075378A(3000);//wm:some patch for submarine?
			if(D_00E045E8 == 2) {
				C_00761FAA(1);
				C_00762702(-3000);
			}
			C_007533AF();//wm:map init/reset?
			C_00768A37(C_0076736E());
			if(C_0075E64D() < 6)//wm:get current song?
				C_0075E5B3(1);//wm:set music related flag on/off
			if(C_0075E64D() != 0)//wm:get current song?
				C_0075E63A();//wm:play current song?
			else
				C_0075E5C0(1);//wm:play song
			C_0074EA48();//controls update?
			D_00E045E4 = -15;
			D_00DE69E0 = 1;
		}
		//-- --
		if(D_00E045E4 < WM_MAINSTATE_6) {//else 0074E16B
			if(!D_00E045EC) {//else 0074DFBF
				C_0074E505();
				C_0074E802(D_00DFC480 - (D_00DFC480 == 1));//texture animation
				D_00E37520 = 0;
				C_0076315C();
				//-- --
				C_00762798(&lolo.local_6);//wm:get model pos(2)?
				lolo.local_1 = inline_abs(lolo.local_6.vy - D_00DE6A04);
				if(D_00DFC48C != 2) {//else 0074DF6C
					D_00DE6A04 = /*lolo.local_16*/(C_00761F77() == 0 && lolo.local_1 <= 200)?
						/*lolo.local_15*/(lolo.local_1 > 50)?D_00DE6A04 + ((lolo.local_6.vy > D_00DE6A04)?50:-50):lolo.local_6.vy:
						((D_00DE6A04 * 7 + lolo.local_6.vy) >> 3)
					;
				}
				C_0074EA48();//controls update?
				C_0074DA4D();//refresh some zoom/rotation?
				//-- --
				C_00762798(&lolo.local_6);//wm:get model pos(2)?
				C_007550A7(&lolo.local_6);//wm:sky color transition?
				//-- --
				C_007641A7();//wm:execute scripts?
				C_0074E8CE(D_00DFC474);//compute camera matrix?
				C_0075079D(D_00DFC474, 1);//wm:refresh terrain stuff?
				C_00765F61();//wm:refresh script stuff?
				C_0074FE89();//refresh camera "altitude"
			}
			//-- --
			C_0074FBEC();
			//-- --
			if(!D_00E045EC) {//else 0074E16B
				if(D_00E045E4 < WM_MAINSTATE_9)
					C_0075EF46();//wm:manage text event?
				C_007591F3();//wm:refresh bridge SFX
				//-- adapt model Y to terrain --
				if(
					(D_00DFC4B4 == 3 && D_00DE6A08 == 0) ||
					(D_00E045E8 == 2 && C_0075335C())//wm:allow control/move?
				) {//else 0074E0BB
					C_00762798(&lolo.local_6);//wm:get model pos(2)?
					lolo.local_7 = C_0076201E();
					D_00DE6A14 = lolo.local_6.vy > (lolo.local_7 + 200);
					if(D_00DE6A14 == 0 && D_00DE6A08 == 0) {//else 0074E0BB
						if(C_00761769(BIT(WM_MODELID_13)))//wm:is current model in list(1)?
							C_00762702(min(-3000, lolo.local_7 + 200));
						else if(C_00761735() == WM_MODELID_03 || lolo.local_7 < 2000)//wm:get model type(2)?
							C_00762702(lolo.local_7 + 200);
						else
							C_007628B5();
					}
				}
				//-- sky related ? --
				C_00754100(D_00DFC474);//wm:update sky related infos
				C_007547A6(D_00DFC474);//wm:render clouds(+meteor)
				//-- --
				C_0074D9B3();//refresh some fade in/out?
				C_0075551A();//wm:render "extra layers"?
				if(D_00E045E4 < WM_MAINSTATE_9 && D_00E045E8 != 3)
					C_00767D68(D_00DFC474);//wm:render map/radar
				C_007667B2(0);//wm:manage ride/leave vehicle?
				C_007573D9();//wm:chocobo related refresh?
				psx_SetGeomScreen(some_world_obj.D_009699E0);
				if(D_00E045E4 >= WM_MAINSTATE_0)
					C_0076323A();
				C_0075C02B();//2danimfx:refresh
				C_007562FF();//wm:refresh Midgar Zolom stuff?
				C_007689F7();
				if(D_00E045E4 == WM_MAINSTATE_1)
					C_00767540();
				C_0074E633(D_00DFC480 - (D_00DFC480 == 1));//render sky gradation?
			}
			//-- --
		}
		//-- --
		if(D_00E045E4 >= WM_MAINSTATE_6) {//else 0074E1E0
			C_007640BC(1);//wm:start script(2)?
			while(C_0076603F())
				C_007641A7();//wm:execute scripts?
			C_007506B6();
			C_00767039(pForDispatcher, pForField, pForBattle);
			if(*pForDispatcher == 1) {
				C_007538C9(3);//wm:start something(unused)?
				C_0074FBCA();
			}
			C_0075E683();//wm:stop sfx and music?
			if(D_00E045E4 == WM_MAINSTATE_9)
				D_00DE69DC = 1;
			D_00DE69E0 = 0;
		}
		//-- --
	}

	return C_0074C9A5();//wm:get backbuffer index[unused]?
}

void C_0074E1E9(short bp08) {
	struct {
		int _ocal_10;
		int i;//local_9
		int _ocal_8[2];
		int local_6;
		int _ocal_5[5];
	}lolo;

	D_00DFC4F0[0].f_4070 = &(D_00E2D5FC[0]);
	D_00DFC4F0[1].f_4070 = &(D_00E2D5FC[0xd00]);
	//-- underwater/snowfield --
	if(bp08 > 10)
		D_00DFC488 = 0;
	//-- --
	C_0075A1C6(bp08);//wmfile:secure init?
#if (_MSC_VER < 1500)
	//
#else
	lolo.local_6 = 0;
#endif
	C_0075E59A(lolo.local_6);//wm:music init
	C_0075E720(bp08);//wm:set song list
	C_007688E0();
	C_00768BE2(bp08);
	C_0075931B(/*00969B04*/"wm.ta", 0xe000, D_00DE7420, 0);//wmfile:read file(archive)
	if(D_00E045E8 > 1)
		*(int *)D_00DE7420 = 0;
	C_0075931B(C_0074CAEC(3/*"WM?.EV"*/, D_00E045E8), 0x7000, D_00DF5448, 0);//wmfile:read file(archive)
	C_0075931B(/*00969B0C*/"mes", 0x1000, D_00E36118 + 8, 0);//wmfile:read file(archive)
	C_0075931B(/*00969B10*/"field.tbl", 0x600, D_00E37D30, 0);//wmfile:read file(archive)//0x80 * 0xc = 0x600
	C_0075931B(/*00969B1C*/"atn.tbl", 0x200 * 2, D_00E37120, 0);//wmfile:read file(archive)
	C_0075931B(/*00969B24*/"enc_w.bin", 0x8A0, &D_00DE6B78, 0);//wmfile:read file(archive)
	//-- some stuff for undersea --
	if(D_00E045E8 == 2) {
		C_00755C40();//undersea:init "layer" 0?
		for(lolo.i = 1; lolo.i < 2; lolo.i ++)
			C_00755CFF(lolo.i);//undersea:init "layer" 1~?
	}
	//-- --
	D_00DFC480 = 2;
	D_00DE6B5C = 1;
	D_00DFC4A8 = 0;
	D_00DFC4AC = 0;
	D_00DE6A14 = 0;
	D_00DFC4B8 = 0;
	D_00DE6A0C = 0;

	D_00DE6B4C =
	D_00DF542C = 160;

	D_00DE6A08 = 0;
	D_00DFC49C = 0;
	D_00DE6A40 = 0;
	D_00DE6B70 = 0;
	D_00DE741C = 0;

	D_00DFC484 =
	D_00DFC474 = 0;

	D_00DE6A04 = 0;
	D_00DF5438 = 0;
	D_00E36110 = 0;
	D_00DFC468 = 1500;
	D_00DFC478 = 10000;

	D_00DF5424 =
	D_00DE6B60 = 
	D_00DFC498 = 0;

	D_00DF5434 = 0;
	D_00DFC46C = 0;
	D_00DE6B54 = 0;
	D_00E045D8 = 5000;
	D_00DFC4A0 = 0;
	D_00DE6A1C = 0;
	D_00DFC48C = 0;
	D_00E045F0 = 0;
}

void C_0074E48A() {
	struct {
		int j;//bp_0c
		int i;//bp_08
		struct POLY_GT3 *bp_04;
	}lolo;

	for(lolo.i = 0; lolo.i < 2; lolo.i ++) {
		for(lolo.j = 0; lolo.j < 0xd00; lolo.j ++) {
			lolo.bp_04 = &(D_00DFC4F0[lolo.i].f_4070[lolo.j]);
			setPolyGT3(lolo.bp_04);
		}//end for
	}//end for
	C_00753F53();
}

void C_0074E5CB(void);//switch backbuffer?

void C_0074E505() {
	struct {
		int local_2;
		int local_1;
	}lolo;

	C_0074E5CB();//switch backbuffer?
	psx_SetGeomScreen(some_world_obj.D_009699E0);
	if(D_00DFC4A0) {//else 0074E58D
		//-- earthquake effect --
		if(D_00DE69D8 == 1) {
			lolo.local_1 = (C_00753BE8() >> 6) - 2;
			lolo.local_2 = D_00DE6B4C - 122 + (C_00753BE8() >> 6);
		} else {
			lolo.local_1 = ((C_00753BE8() >> 6) - 2) * 2;
			lolo.local_2 = (D_00DE6B4C - 122 + (C_00753BE8() >> 6)) * 2;
		}
		C_00661B68(lolo.local_1, lolo.local_2);//psx:set view x,y?
	} else {
		//-- normal --
		lolo.local_2 = (D_00DE69D8 == 1)?D_00DE6B4C - 120:(D_00DE6B4C - 120) * 2;
		C_00661B68(0, lolo.local_2);//psx:set view x,y?
	}
}

//switch backbuffer?
void C_0074E5CB() {
	D_00DE6A1C = !D_00DE6A1C;
	D_00DE6A10 =
	D_00DF5444 = D_00DFC4F0[D_00DE6A1C].f_4070;
	D_00E36114 = D_00DFC4F0[D_00DE6A1C].f_0070;
	D_00DF543C = D_00DFC4F0[D_00DE6A1C].f_0000;
}

//render sky gradation?
void C_0074E633(int _p08) {
	struct {
		struct t_dx_rend_vertex_20 *local_6[4];
		struct t_wm_SkyPoly *local_2;
		int local_1;
	}lolo;

	//-- unused --
	lolo.local_1 = 2500;
	if(lolo.local_1 > 0xfff)
		lolo.local_1 = 0xfff;
	//-- --
	if(D_00DFC4AC) {
		if(C_0066E272(1, D_00E2C3E8)) {
			if(C_0074C969()) {//wm:get "isRendering"?
				lolo.local_2 = C_007540E5();
				MK_VERTEX_NOTEXTURE(&(D_00E2C3E8->f_70.asVertex[0]), lolo.local_6[3], lolo.local_2->f_00.x0, lolo.local_2->f_00.y0, 0.9999f, 1.0f, lolo.local_2->bgra0, 0xff000000);
				MK_VERTEX_NOTEXTURE(&(D_00E2C3E8->f_70.asVertex[1]), lolo.local_6[2], lolo.local_2->f_00.x1, lolo.local_2->f_00.y1, 0.9999f, 1.0f, lolo.local_2->bgra1, 0xff000000);
				MK_VERTEX_NOTEXTURE(&(D_00E2C3E8->f_70.asVertex[2]), lolo.local_6[1], lolo.local_2->f_00.x2, lolo.local_2->f_00.y2, 0.9999f, 1.0f, lolo.local_2->bgra2, 0xff000000);
				MK_VERTEX_NOTEXTURE(&(D_00E2C3E8->f_70.asVertex[3]), lolo.local_6[0], lolo.local_2->f_00.x3, lolo.local_2->f_00.y3, 0.9999f, 1.0f, lolo.local_2->bgra3, 0xff000000);
			}
		}
	}
}

struct t_wm_local_ta_08 {//size 8
	/*00*/unsigned f_00;//offset in file
	/*04*/unsigned short f_04;//size of chunk
	/*06*/unsigned char f_06;//# of chunks
	/*07*/unsigned char f_07;//cycle speed parameter
};

//texture animation
void C_0074E802(int _p08) {
	struct {
		int _ocal_5;
		unsigned i;//local_4
		int _ocal_3;
		int *local_2;
		struct t_wm_local_ta_08 *local_1;
	}lolo;

	lolo.local_1 = (struct t_wm_local_ta_08 *)(D_00DE7420 + 4);
	for(lolo.i = 0; lolo.i < *(int *)D_00DE7420; lolo.i ++) {
		lolo.local_2 = (int *)D_00DE7420 + (lolo.local_1->f_00 >> 2) + (lolo.local_1->f_04 >> 2) * (((unsigned)C_0040AC84() / lolo.local_1->f_07) % lolo.local_1->f_06);
		//lolo.local_2 points to some unused texture/animation info.
		D_00E2BBD8[D_0096B448[lolo.i]] = D_00E2C658[D_009699B0[lolo.i] + (((unsigned)C_0040AC84() / lolo.local_1->f_07) % lolo.local_1->f_06)];
		lolo.local_1 ++;
	}//end for
}

int C_0074F916(void);//get camera tilt?

//compute camera matrix?
void C_0074E8CE(short wAngle/*bp08*/) {
	struct {
		DECL_struct_MATRIX(local_27);
		DECL_struct_MATRIX(local_19);
		struct VECTOR local_11;
		struct VECTOR local_7;
		struct SVECTOR local_3;
		int dwTemp;//local_1
	}lolo;

	lolo.local_3.vx = C_0074F916();//get camera tilt?
	lolo.local_3.vy =
	lolo.local_3.vz = 0;
	psx_RotMatrixXYZ(&lolo.local_3, &lolo.local_27);
	lolo.local_11.vx =
	lolo.local_11.vy =
	lolo.local_11.vz = 0;
	psx_TransMatrix(&lolo.local_27, &lolo.local_11);
	psx_SetRotMatrix(&lolo.local_27);
	psx_SetTransMatrix(&lolo.local_27);

	lolo.local_3.vx =
	lolo.local_3.vy = 0;
	lolo.local_3.vz = D_00DFC478;//camera distance?
	psx_RotTrans(&lolo.local_3, &lolo.local_7, &lolo.dwTemp);
	lolo.local_11.vx = 0;
	lolo.local_11.vy = 0;
	lolo.dwTemp = (lolo.local_7.vy << 4) - D_00DE6A04;
	lolo.local_11.vz = D_00DFC478;
	psx_TransMatrix(&D_00DE6A20, &lolo.local_11);
	//-- --
	lolo.dwTemp = (lolo.dwTemp << 8) / (lolo.local_7.vz << 4);
	if(lolo.dwTemp < 0)
		lolo.dwTemp = 0;
	else if(lolo.dwTemp >= 0x200)
		lolo.dwTemp = 0x1ff;
	D_00DE7418 =
	lolo.local_3.vx = D_00E37120[lolo.dwTemp] + 0x800;
	lolo.local_3.vy = wAngle;
	lolo.local_3.vz = 0;
	psx_RotMatrixXYZ(&lolo.local_3, &lolo.local_27);
	lolo.local_3.vx =
	lolo.local_3.vy = 0;
	lolo.local_3.vz = D_00DE6B70;
	psx_RotMatrixXYZ(&lolo.local_3, &lolo.local_19);
	psx_MulMatrix0(&lolo.local_19, &lolo.local_27, &D_00DFC448);
}

//controls update?
void C_0074EA48() {
	struct {//0xd0
		//local_33 and above for compiler
		int local_32;
		int local_31;
		struct VECTOR local_30;
		int dwDeltaX;//local_26
		int dwShift;//local_25
		int dwVSpeed;//local_24
		DECL_struct_MATRIX(local_23);
		int dwStrafing;//local_15
		int dwInputMask;//local_14
		struct SVECTOR local_13;
		int dwFlags_unused;//local_11
		int dwModelType;//local_10
		struct VECTOR local_9;
		struct SVECTOR local_5;
		int dwDelta;//local_3
		int local_02;//local_2;
		int dwDeltaY;//local_1
	}lolo;

	lolo.dwDeltaX =
	lolo.dwDeltaY = 0;
	C_007616B3();//wm:set some info(1)?
	lolo.dwModelType = C_00761735();//wm:get model type(2)?
	if(D_00DE6B5C && D_00DFC4B8 <= 0 && C_0075335C()) {//wm:allow control/move?//else 0074F734
		lolo.dwInputMask = C_007186B9();//menu_input:get "current mask"
		//-- --
		if(D_00DFC4B4 != 2 && D_00DFC4B4 != 3 && D_00E045E8 != 3 && (lolo.dwInputMask & (PAD_03|PAD_02)))
			C_0074D3D1(2);//wm:set view mode?
		if(lolo.dwModelType == WM_MODELID_05 && (lolo.dwInputMask & PAD_06))
			lolo.dwInputMask &= ~0xf000;
		if(C_00761769(BIT(WM_MODELID_13)) && D_00DFC4B4 == 2 && D_00E045E8 != 2 && (lolo.dwInputMask & PAD_05))
			lolo.dwInputMask &= ~PAD_DOWN;
		//-- --
		if(C_00761844()) {
			lolo.dwDelta = D_00DFC480 * 60;
			//goto 0074EB89
		} else {
			switch(lolo.dwModelType) {
				case WM_MODELID_03: lolo.dwDelta = D_00DFC480 * 120; break;
				case WM_MODELID_05: lolo.dwDelta = D_00DFC480 * 60; break;
				case WM_MODELID_06: lolo.dwDelta = D_00DFC480 * 45; break;
				default:
					lolo.dwDelta = D_00DFC480 * 30;
			}//end switch
		}
		//-- triggered PAD_00 or PAD_01 --
		if(
			((lolo.dwInputMask & PAD_00) && !(D_00DFC470 & PAD_00)) ||
			((lolo.dwInputMask & PAD_01) && !(D_00DFC470 & PAD_01))
		) {
			if(D_00DFC4B4 != 3 && D_00DE6A0C == 0 && D_00E045E8 != 2 && D_00E045E8 != 3) {
				C_0074D3D1((D_00DFC4B4 != 0)?0:2);//wm:set view mode?
				D_00DF542C = (D_00DFC4B4 != 0)?160:120;
			}
		}
		//-- --
		if(C_00761769(BIT(WM_MODELID_13)) && D_00DFC4B4 == 2 && D_00E045E8 != 2 && (lolo.dwInputMask & PAD_05))
			lolo.dwInputMask |= PAD_UP;
		//-- --
		D_00DF5430 = -1;
		if(lolo.dwInputMask & PAD_LEFT) {
			lolo.dwDeltaX = -lolo.dwDelta;
			D_00DF5430 = -0x400;
		}
		if(lolo.dwInputMask & PAD_RIGHT) {
			lolo.dwDeltaX = lolo.dwDelta;
			D_00DF5430 = 0x400;
		}
		if(lolo.dwInputMask & PAD_UP) {
			if(D_00DF5430 == -1) {
				lolo.dwDeltaY = -lolo.dwDelta;
				D_00DF5430 = 0x800;
			} else {
				lolo.dwDeltaX = (lolo.dwDeltaX * 3) >> 2;
				lolo.dwDeltaY = (lolo.dwDelta * -3) >> 2;
				D_00DF5430 += D_00DF5430 >> 1;
			}
		}
		if(lolo.dwInputMask & PAD_DOWN) {
			if(D_00DF5430 == -1) {
				lolo.dwDeltaY = lolo.dwDelta;
				D_00DF5430 = 0;
			} else {
				lolo.dwDeltaX = (lolo.dwDeltaX * 3) >> 2;
				lolo.dwDeltaY = (lolo.dwDelta * 3) >> 2;
				D_00DF5430 -= D_00DF5430 >> 1;
			}
		}
		//-- --
		if(D_00DFC4B4 == 2 || D_00DFC4B4 == 3 || D_00E045E8 == 3) {//else 0074F4FE
			lolo.dwStrafing = /*lolo.local_34*/(D_00DFC4B4 == 3 && (lolo.dwInputMask & PAD_07));
			if(D_00E045E8 == 3) {//else 0074EDEF
				D_00DFC484 += C_00758B12(lolo.dwInputMask & 0xf000, /*lolo.local_35*/(lolo.dwInputMask & PAD_05) && !(D_00DFC470 & PAD_05));
			} else if(!lolo.dwStrafing) {//else 0074EF6A
				//left
				lolo.local_31 = ((lolo.dwInputMask & PAD_02) != 0) + ((lolo.dwInputMask & /*lolo.local_36*/((D_00DFC4B4 == 2 && D_00E045E8 != 2 && (lolo.dwInputMask & PAD_DOWN)?0x2000:0x8000))) != 0);
				if(lolo.local_31)
					D_00DFC484 -= ((D_00DFC480 << 3) * lolo.local_31 * ((lolo.dwInputMask & (PAD_DOWN|PAD_UP))?1:2)) >> /*lolo.local_37*/(D_00E045E8 == 2 && (lolo.dwInputMask & PAD_02) == 0);
				//right
				lolo.local_31 = ((lolo.dwInputMask & PAD_03) != 0) + ((lolo.dwInputMask & /*lolo.local_38*/((D_00DFC4B4 == 2 && D_00E045E8 != 2 && (lolo.dwInputMask & PAD_DOWN)?0x8000:0x2000))) != 0);
				if(lolo.local_31)
					D_00DFC484 += ((D_00DFC480 << 3) * lolo.local_31 * ((lolo.dwInputMask & (PAD_DOWN|PAD_UP))?1:2)) >> /*lolo.local_39*/(D_00E045E8 == 2 && (lolo.dwInputMask & PAD_03) == 0);
			}
			if(D_00DFC484 < 0)
				D_00DFC484 += 0x1000;
			else if(D_00DFC484 >= 0x1000)
				D_00DFC484 -= 0x1000;

			lolo.local_02 = 0;
			if(lolo.dwInputMask & PAD_LEFT)
				lolo.local_02 = 0x80;
			else if(lolo.dwInputMask & PAD_RIGHT)
				lolo.local_02 = -0x80;

			if(D_00DFC4B4 == 3 || D_00E045E8 == 2) {//else 0074F121
				lolo.local_32 = ((lolo.dwInputMask & (lolo.dwStrafing?0xf000:PAD_05))?~0:0) & lolo.dwDelta;
				D_00DE6A18 = /*lolo.local_40*/(D_00E045E8 == 2)?lolo.local_32:(D_00DE6A18 * 3 + lolo.local_32) >> 2;
				if(lolo.dwStrafing) {//else 0074F0FB
					lolo.dwDeltaX = /*lolo.local_41*/(lolo.dwInputMask & PAD_LEFT)?-D_00DE6A18:(lolo.dwInputMask & PAD_RIGHT)?D_00DE6A18:0;
					lolo.dwDeltaY = /*lolo.local_43*/(lolo.dwInputMask & PAD_UP)?-D_00DE6A18:(lolo.dwInputMask & PAD_DOWN)?D_00DE6A18:0;
				} else {
					lolo.dwDeltaX = 0;
					lolo.dwDeltaY = -D_00DE6A18;
				}
				if(!(lolo.dwInputMask & PAD_05))
					lolo.local_02 = 0;
			} else if(D_00DF5430 != -1) {
				C_00761B83(D_00DF5430 - D_00DFC484);
			}
			lolo.local_13.vx = lolo.dwDeltaX;
			lolo.local_13.vy = 0;
			lolo.local_13.vz = lolo.dwDeltaY;
			lolo.local_5.vx =
			lolo.local_5.vz = 0;
			lolo.local_5.vy = -D_00DFC484;
			psx_RotMatrixXYZ(&lolo.local_5, &lolo.local_23);
			lolo.local_9.vx =
			lolo.local_9.vy =
			lolo.local_9.vz = 0;
			psx_TransMatrix(&lolo.local_23, &lolo.local_9);
			psx_SetRotMatrix(&lolo.local_23);
			psx_SetTransMatrix(&lolo.local_23);
			psx_RotTrans(&lolo.local_13, &lolo.local_30, &lolo.dwFlags_unused);
			lolo.dwDeltaX = lolo.local_30.vx;
			lolo.dwDeltaY = lolo.local_30.vz;
			//-- --
			lolo.dwVSpeed = 0;
			//-- highwind up/down --
			if(D_00DFC4B4 == 3 && !lolo.dwStrafing) {//else 0074F291
				C_00762798(&lolo.local_9);//wm:get model pos(2)?
				if(((lolo.dwInputMask & PAD_UP) && lolo.local_9.vy > 0x1f4 && D_00DE6A14 && C_00762136() != 0x1b) || lolo.local_9.vy > D_00DF5420) {
					//up
					C_00761F22(D_00DFC480 * -50);
					lolo.dwVSpeed = 10;
				} else if((lolo.dwInputMask & PAD_DOWN) && lolo.local_9.vy < D_00DF5420 - D_00DFC480 * 50) {
					//down
					C_00761F22(D_00DFC480 * 50);
					lolo.dwVSpeed = -10;
				}
			}
			//-- submarine up/down --
			if(D_00E045E8 == 2) {//else 0074F30B
				C_00762798(&lolo.local_9);//wm:get model pos(2)?
				if((lolo.dwInputMask & PAD_UP) && lolo.local_9.vy > -5000 && D_00DE6A14) {
					//up
					C_00761F22(D_00DFC480 * -30);
					lolo.dwVSpeed = 10;
				}
				if((lolo.dwInputMask & PAD_DOWN) && lolo.local_9.vy < -3000) {
					//down
					C_00761F22(D_00DFC480 * 30);
					lolo.dwVSpeed = -10;
				}
			}
			//-- highwind tilt --
			if(D_00DFC4B4 == 3) {//else 0074F3F3
				lolo.dwShift = ((/*lolo.local_46*/!(((C_00761F44() == 0 || inline_abs(D_00DE6B70) < 0x10) && lolo.local_02 == 0)) << 1) | (D_00DFC480 == 1)) + 3;//3~6
				D_00DE6B70 = (
					((1 << lolo.dwShift) - 1) * D_00DE6B70 +
					lolo.local_02 +
					(1 << (lolo.dwShift - 1))
				) >> lolo.dwShift;
				D_00E045E0 = (D_00E045E0 * 3 + lolo.dwVSpeed) >> 2;
				C_00762F75(D_00E045E0 + 4, D_00DE6B70 << 2, -D_00DE6B70 << 1);//wm:set model tilt x,y,z?
			}
			//-- --
			if(lolo.local_02 == 0 && /*lolo.local_47*/inline_abs(D_00DE6B70) <= 4)
				D_00DE6B70 = 0;
			//-- --
			if(D_00E045E8 == 3) {
				;//goto 0074F4FC
			} else {
				if(D_00DF5430 != -1) {//else 0074F4A9
					D_00DF5430 += 0x800;
					if(D_00DF5430 > 0x800)
						D_00DF5430 -= 0x1000;
					if((lolo.dwInputMask & PAD_DOWN) == 0)
						D_00DF5430 >>= 1;
					D_00DF5434 = D_00DF5430;
				} else {
					D_00DF5430 = D_00DF5434;
				}
				C_00761B83(0x800 - D_00DFC484 + (/*lolo.local_48*/(D_00DFC4B4 == 2 && D_00E045E8 != 2)?D_00DF5430:0));
			}
		} else {
			D_00DE6B70 >>= 1;
			if(D_00DF5430 != -1)
				C_00761B83(D_00DF5430);
		}
		//-- buggy engine noise? --
		if(lolo.dwModelType == WM_MODELID_06) {//else 0074F57E
			if((lolo.dwInputMask & 0xf000) && !(D_00DFC470 & 0xf000))
				C_0075E6A8(8, 0x20);//wm:engine noise params[for buggy]?
			if((lolo.dwInputMask & 0xf000) == 0 && (D_00DFC470 & 0xf000))
				C_0075E6A8(8, 0);//wm:engine noise params[for buggy]?
		}
		//-- --
		if(C_00761769(BIT(WM_MODELID_13)) && (lolo.dwInputMask & PAD_06) && !(D_00DFC470 & PAD_06)) {
			if(D_00E045E8 == 2 && C_00762136() == 3)//wm:get current terrain?
				C_0074D6BB();//wm:go to surface
			else if(C_00762136() == 3)//wm:get current terrain?
				C_0074D6F6();//go to undersea
		}
		//-- map/radar state --
		if(
			(lolo.dwInputMask & PAD_11) && !(D_00DFC470 & PAD_11) ||
			(lolo.dwInputMask & PAD_08) && !(D_00DFC470 & PAD_08)
		) {//else 0074F650
			C_0076831F(/*lolo.local_49*/(D_00E045E8 == 0)?(C_00768343() + 1) % 3:(!C_00768343() * 2));//wm:set map/radar state
		}
		//-- open menu/enter highwind --
		if((lolo.dwInputMask & PAD_04) && !(D_00DFC470 & PAD_04) && D_00E045E4 == WM_MAINSTATE_1) {//else 0074F6C6
			if(lolo.dwModelType == WM_MODELID_03) {
				C_007640BC(6);//wm:start script(2)?
			} else if(C_00761769(BIT(WM_MODELID_06)|BIT(WM_MODELID_02)|BIT(WM_MODELID_01)|BIT(WM_MODELID_00)) && C_00762136() != 0xe/*bridge?*/) {//wm:is current model in list(1)?//wm:get current terrain?
				C_00755B97(0x10, 1);//wm:start fade out?
				C_0074D438(0, 1);//wm:set enable something?
				D_00E045E4 = WM_MAINSTATE_LEAVEWORLD;
				C_0074C980(0);//wm:set "allowsFrameSkip"?
			}
		}
		//-- randomize --
		if(lolo.dwInputMask & (PAD_LEFT|PAD_RIGHT|PAD_03|PAD_02))
			C_00753BE8();//wm:random?
		//-- --
		D_00DFC470 = lolo.dwInputMask;
		//-- --
		if(C_00762136() == 0xe/*bridge?*/)//wm:get current terrain?
			C_007591C2(&lolo.dwDeltaX, &lolo.dwDeltaY);

		if(lolo.dwModelType == WM_MODELID_05)
			C_0075E6CC((lolo.dwDeltaX | lolo.dwDeltaY)?0x1ed:-0x1ed);//wm:start/stop SFX?

		C_00762E87(lolo.dwDeltaX, lolo.dwDeltaY);
		C_0076296E();
	}
	//-- --
	if(!D_00DE6B5C && C_00762136() == 0xe/*bridge?*/) {//wm:get current terrain?
		C_007591C2(&lolo.dwDeltaX, &lolo.dwDeltaY);
		C_00762E87(lolo.dwDeltaX, lolo.dwDeltaY);
		C_0076296E();
	}
	if(D_00DFC4B4 != 3)
		D_00DE6B4C = (D_00DE6B4C * 3 + D_00DF542C) >> 2;
	if(D_00DFC474 < D_00DFC484 - 0x800)
		D_00DFC474 += 0x1000;
	else if(D_00DFC474 > D_00DFC484 + 0x800)
		D_00DFC474 -= 0x1000;
	D_00DFC474 = /*lolo.local_51*/(3)?
		/*lolo.local_50*/(D_00DFC480 == 1)?
			(D_00DFC474 * 31 + D_00DFC484) >> 5:
			(D_00DFC474 * 15 + D_00DFC484) >> 4:
		/*lolo.local_52*/(D_00DFC480 == 1)?
			(D_00DFC474 *  7 + D_00DFC484) >> 3:
		(D_00DFC474 *  3 + D_00DFC484) >> 2
	;
}

void C_0074F87D() {
	D_00DE6B4C = /*local_1*/(D_00E045DC == 0)?
		120 - ((D_00DE6A40 * 30) >> 8):
		160 - ((D_00DE6A40 * 70) >> 8)
	;
	some_world_obj.D_009699E0 = 400 - ((D_00DE6A40 * 200) >> 8);
	D_00DFC478 = 10000 - ((D_00DE6A40 * 6000) >> 8);
	D_00E045D8 = 5000 - ((D_00DE6A40 * 2500) >> 8);
}

//get camera tilt?
int C_0074F916() {
	struct {
		int local_11;
		struct VECTOR local_10;
		int local_6;
		struct VECTOR local_5;
		int local_1;
	}lolo;

	if(D_00DE6A08) {//else 0074FAAE
		if(D_00DFC49C == 0) {//else 0074F988
			if(D_00DE6A08 > 0) {
				C_0074D3D1(3);//wm:set view mode?
				D_00DF5420 = (C_00761735() != WM_MODELID_03)?2000:4000;//wm:get model type(2)?
			}
			D_00DE6B48 = D_00DFC484;
			if(D_00DE6B48 >= 0x800)
				D_00DE6B48 -= 0x1000;
		}
		D_00DFC49C += D_00DFC480 * ((D_00DE6A40 < 0x80) * 2 - 1);
		if(D_00DFC49C) {//else 0074FA80
			D_00DE6A40 += D_00DFC49C;
			if(D_00DE6A40 < 0)
				D_00DE6A40 = 0;
			else if(D_00DE6A40 > 0x100)
				D_00DE6A40 = 0x100;
			C_0074F87D();
			C_00762798(&lolo.local_5);//wm:get model pos(2)?
			C_00762802(&lolo.local_10);//wm:get model previous pos(2)?
			lolo.local_6 = C_0076201E();
			C_0076271B(lolo.local_6 + ((((/*lolo.local_12*/(D_00DE6A08 > 0)?D_00DF5420:lolo.local_10.vy) - lolo.local_6) * D_00DE6A40) >> 8));
			if(D_00E045DC == 0 || D_00E045DC == 1)
				D_00DFC484 = (D_00DE6A40 * D_00DE6B48) >> 8;
			//goto 0074FAAE
		} else {
			if(D_00DE6A08 < 0) {
				C_0074D3D1(D_00E045DC);//wm:set view mode?
				C_0074D438(0, 2);//wm:set enable something?
			}
			D_00DE6A08 = 0;
		}
	}
	lolo.local_11 = /*lolo.local_13*/(D_00DE6A08 < 0 && D_00E045DC == 0)?0:D_00DFC4B4;
	lolo.local_1 = /*lolo.local_14*/D_00DE6A0C?D_00DE6A0C:D_00969A58[lolo.local_11] + D_00DF5438;
	D_00DFC468 = /*lolo.local_15*/(D_00DFC480 == 1)?(D_00DFC468 * 7 + lolo.local_1) >> 3:(D_00DFC468 * 3 + lolo.local_1) >> 2;
	lolo.local_1 = /*lolo.local_16*/D_00DFC47C?D_00DFC47C:D_00969A68[lolo.local_11];
	D_00DFC478 = /*lolo.local_17*/(D_00DFC480 == 1)?(D_00DFC478 * 7 + lolo.local_1) >> 3:(D_00DFC478 * 3 + lolo.local_1) >> 2;

	return (D_00DE6A40 * ((D_00DE6A04 >> 5) + 1750) + (0x100 - D_00DE6A40) * D_00DFC468) >> 8;
}

void C_0074FBCA() {
	if(D_00CC0888 == 1) {
		C_006CC3E8();//compute party's weapon/armor/accessory/materia/... related stuff?
		C_006CBD1E();//refresh "limit" related stuff?
		D_00CC0888 = 0;
	}
}

void C_0074FE84(void);//<empty>

void C_0074FBEC() {
	struct VECTOR bp_10;

	switch(D_00E045E4) {
		case WM_MAINSTATE_0://[seems never reached]
			//-- zoom/rotation related? --
			if(D_00DFC47C) {//else 0074FC89
				D_00DFC47C += 80;
				if(D_00DFC47C >= (D_00969A68[D_00DFC4B4] >> 1) && D_00E045E8 != 2 && D_00E045E8 != 3)
					D_00DFC4AC = 1;
				if(D_00DFC47C >= D_00969A68[D_00DFC4B4]) {//else 0074FC89
					D_00DFC47C = 0;
					if(D_00DE6A0C == 0)
						D_00E045E4 = WM_MAINSTATE_1;
				}
			}

			if(D_00DE6A0C) {//else 0074FCEE
				D_00DE6A0C += 3;
				if(D_00DE6A0C >= D_00969A58[D_00DFC4B4]) {//else 0074FCEE
					D_00DE6A0C = 0;
					if(D_00E045E8 != 2 && D_00E045E8 != 3)
						D_00DFC4AC = 1;
					if(D_00DFC47C == 0)
						D_00E045E4 = WM_MAINSTATE_1;
				}
			}
		break;
		case WM_MAINSTATE_LEAVEWORLD:
			if(C_00755C2F()) {//wm:is fade in/out over?//else 0074FDB2
				if(D_00E045F0) {
					D_00E045E4 = WM_MAINSTATE_3;
					D_00E045F0 = 0;
				} else {
					if(!D_00E045EC) {//else 0074FD63
						//to menu
						C_00767473(C_00762162());//wm:save location name?
						C_00766ECB();
						C_007538C9(3);//wm:start something(unused)?
						C_0074FBCA();
						C_0074FE84();//<empty>
						D_00E045EC = 1;
						C_0075551A();//wm:render "extra layers"?
					} else {
						//from menu
						C_0075395E(3);//wm:stop something(unused)?
						C_0074D438(1, 1);//wm:set enable something?
						C_0076741C();
						C_0074E48A();
						C_0074E505();
						C_00755B70(0x10, 1);//wm:start fade in?
						D_00E045E4 = WM_MAINSTATE_1;
						D_00E045EC = 0;
						C_0074C980(1);//wm:set "allowsFrameSkip"?
					}
				}
			}
		break;
		case WM_MAINSTATE_TOUNDERSEA:
		case WM_MAINSTATE_TOSURFACE:
			C_00762798(&bp_10);//wm:get model pos(2)?
			C_00762702(bp_10.vy + D_00DFC490);
			D_00DFC490 += D_00DFC490 >> 2;
			if(C_00755C2F()) {//wm:is fade in/out over?
				D_00E045E4 = (D_00E045E4 == WM_MAINSTATE_TOUNDERSEA)?
					WM_MAINSTATE_6:
					WM_MAINSTATE_7
				;
			}
		break;
		case WM_MAINSTATE_3:
			D_00E045E4 = WM_MAINSTATE_9;
		break;
		//case WM_MAINSTATE_1:
		default:
			if(D_00E045E4 < 0) {
				D_00E045E4 ++;
				if(D_00E045E4 == 0) {
					if(D_00E045E8 != 2 && D_00E045E8 != 3)
						D_00DFC4AC = 1;
					D_00E045E4 = WM_MAINSTATE_1;
					C_00755B70(0x10, 1);//wm:start fade in?
				}
			}
	}//end switch
}

//<empty>
void C_0074FE84() {
}

//refresh camera "altitude"
void C_0074FE89() {
	if(D_00E045E4 == WM_MAINSTATE_1 && D_00E045E8 != 2) {
		D_00DE6B6C = ((D_00DE6B6C * 7) + (D_00E37520 << 8)) >> 3;
		D_00DE6B58 = (D_00DE6B6C > 0x80);
		D_00DE6B64 = /*local_1*/D_00DE6B58?D_00DE6B64 + 1:0;
		if(D_00DF5440 != D_00DE6B58) {
			D_00DFC4BC = 0;
			D_00DFC4A4 = 15;
		}
		if(C_00761F77() || D_00DE6B64 >= 15) {
			if((D_00DFC4A4 --) < 0)
				D_00DFC4BC = 1;
		}
		if(D_00DFC4BC) {//else 0074FF98
			if(D_00DE6B58) {//else 0074FF82
				if(D_00DF5438 > -350)
					D_00DF5438 -= 5;
			} else if(D_00DF5438 < 0) {
				D_00DF5438 += 5;
			}
		}
		D_00DF5440 = D_00DE6B58;
	}
}

int __0074FFA8() {
	return D_00E045E4;
}
