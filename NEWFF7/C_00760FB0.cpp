/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//WORLD MAP -- scripts(events?) engine

#include "ff7.h"
#include "wm_data.h"
#include "menu_data.h"
#include "loadmenu.h"
////////////////////////////////////////
#define FF7_CLAMP(v,lo,up) min((up), max((lo), (v)))
////////////////////////////////////////
struct t_wm_local_stackElement {//size 8
	/*00*/int dwValue;
	/*04*/unsigned short wOpcode;
	/*06*/char __06[2];
};

//world map coordinate related
struct t_wm_local_8_rrr {//size 8
	/*00*/int f_00;
		//0~18:x
		//19~23:model type
		//24~31:angle
	/*04*/int f_04;
		//0~17:y
		//18~31:z
};

struct t_wm_evHeaderEntry {//size 4
	/*00*/unsigned short wId;
	/*02*/unsigned short wOffset;
};
////////////////////////////////////////
void *D_00E399B8;//"WM?.EV" base
//00E399BC
unsigned char D_00E399C0[0x40];
struct t_local_unknown_c0 *D_00E39A00;
//00E39A04
struct VECTOR D_00E39A08;
struct t_local_unknown_c0 D_00E39A18;
struct t_local_unknown_c0 *D_00E39AD8;//current model(2)
struct t_wm_local_stackElement *D_00E39ADC;
struct t_local_unknown_c0 D_00E39AE0;
int D_00E39BA0[2];//chara who left related
int D_00E39BA8[2];//new chara related
int D_00E39BB0;
short D_00E39BB4;//[vehicle related]model tilt x?
short D_00E39BB8;//[vehicle related]model y?
short D_00E39BBC;//[vehicle related]model z?
int D_00E39BC0;
//00E39BC4
struct t_local_unknown_c0 D_00E39BC8[0x10];
struct t_wm_b8 *D_00E3A7C8;
struct t_local_unknown_c0 *D_00E3A7CC;
struct t_local_unknown_c0 *D_00E3A7D0;//current model(1)
struct t_local_unknown_c0 *D_00E3A7D4;
struct t_wm_local_8_rrr *D_00E3A7D8;
int D_00E3A7DC;
unsigned char *D_00E3A7E0[4];
struct t_wm_local_stackElement D_00E3A7F0[4];
unsigned short *D_00E3A810;//"WM?.EV" offset 0x400
//00E3A814
struct VECTOR D_00E3A818[3];
int D_00E3A848;//[]x?
int D_00E3A84C;//[]y?
int D_00E3A850;
int D_00E3A854;
int D_00E3A858;
short D_00E3A85C;
////////////////////////////////////////
void C_00761134(struct t_local_unknown_c0 *);//clean struct?

void C_00760FB0(void *bp08) {
	int i;

	for(i = 0; i < 0xf; i ++)
		D_00E39BC8[i].pNext = &(D_00E39BC8[i + 1]);
	D_00E39BC8[i].pNext = 0;
	D_00E3A7D4 = D_00E39BC8;
	D_00E39A00 =
	D_00E39AD8 =
	D_00E3A7D0 = 0;

	C_00761134(&D_00E39A18);//clean struct?
	C_00761134(&D_00E39AE0);//clean struct?
	D_00E39AE0.bModelType = WM_MODELID_09;
	D_00E39A18.pNext = 0;
	D_00E39AE0.pNext = 0;

	C_00762F75(0, 0, 0);//wm:set model tilt x,y,z?
	D_00E3A7D8 = (struct t_wm_local_8_rrr *)bp08;
	D_00E3A848 =
	D_00E3A84C = 0;
	D_00E3A850 =
	D_00E3A854 =
	D_00E39BB0 = 0;
}

//wm:alloc new model
struct t_local_unknown_c0 *C_007610B3() {
	struct t_local_unknown_c0 *local_1;

	local_1 = D_00E3A7D4;
	if(local_1 == 0)
		C_0074C9A0(0x32);//<empty>:some error management?
	D_00E3A7D4 = local_1->pNext;
	local_1->pNext = D_00E39A00;
	D_00E39A00 =
	D_00E39AD8 = local_1;
	C_00761134(local_1);//clean struct?

	return local_1;
}

void C_0076110B() {
	struct t_local_unknown_c0 *local_1;

	for(local_1 = D_00E39A00; local_1; local_1 = local_1->pNext)
		local_1->f_5e = 0;
}

//clean struct?
void C_00761134(struct t_local_unknown_c0 *bp08) {
	struct {
		unsigned *pEnd;//local_2
		unsigned *p;//local_1
	}lolo;

	bp08->f_5e = 0;
	//-- --
	lolo.pEnd = (unsigned *)(bp08 + 1);
	lolo.p = (unsigned *)bp08 + 1;//(unsigned *)&(bp08->f_04)
	while(lolo.p < lolo.pEnd) {
		*lolo.p = 0;
		lolo.p ++;
	}//end while
}

int C_00761176() {
	struct t_local_unknown_c0 *local_1;

	for(
		local_1 = D_00E39A00;
		local_1 && local_1->bModelType < 32;
		local_1 = local_1->pNext
	);

	return local_1 != 0;
}

void C_007611FF(struct t_local_unknown_c0 *);

void C_007611AE() {
	struct t_local_unknown_c0 *local_1;

	if(D_00E3A7D0 && D_00E39AD8 && D_00E39AD8->f_08 == 0) {
		local_1 = D_00E3A7D0;
		C_007611FF(local_1);
		D_00E39AD8->f_08 = local_1;
		D_00E3A7D0 = D_00E39AD8;
	}
}

void C_007611FF(struct t_local_unknown_c0 *bp08) {
	struct {
		struct t_wm_b8 *local_3;
		struct t_local_unknown_c0 *local_2;
		struct t_local_unknown_c0 *local_1;
	}lolo;

	if(bp08 == D_00E39AD8)
		D_00E39AD8 = 0;
	if(bp08 == D_00E3A7D0)
		D_00E3A7D0 = 0;
	for(
		lolo.local_1 = D_00E39A00;
		lolo.local_1;
		lolo.local_1 = lolo.local_1->pNext
	) {
		if(lolo.local_1->f_04 == bp08)
			lolo.local_1->f_04 = 0;
		if(lolo.local_1->f_08 == bp08)
			lolo.local_1->f_08 = 0;
	}//end for
	for(
		lolo.local_2 = 0, lolo.local_1 = D_00E39A00;
		lolo.local_1 && lolo.local_1 != bp08;
		lolo.local_2 = lolo.local_1, lolo.local_1 = lolo.local_1->pNext
	);
	if(lolo.local_1) {
		if(lolo.local_2)
			lolo.local_2->pNext = lolo.local_1->pNext;
		else
			D_00E39A00 = lolo.local_1->pNext;
	}
	if(lolo.local_1)
		lolo.local_1->pNext = 0;
	//-- unused stuff? --
	lolo.local_3 = C_00768A37(bp08->bModelType);
	if(lolo.local_3 && lolo.local_3->f_01 == 0xe) {
		C_0075E024(lolo.local_3);//wm:<empty>
		bp08->f_5e = 0;
	}
	//-- --
}

void C_00761407(struct t_local_unknown_c0 *);

void C_00761313() {
	struct t_local_unknown_c0 *local_1;

	if(D_00E3A7D0 && D_00E3A7D0->f_08) {
		local_1 = D_00E3A7D0->f_08;
		C_00761407(local_1);
		local_1->f_04 = D_00E3A7D0;
		local_1->sPos = D_00E3A7D0->sPos;
		local_1->sPrevPos = D_00E3A7D0->sPrevPos;
		local_1->f_40 = D_00E3A7D0->f_40;
		local_1->wDirection = D_00E3A7D0->wDirection;
		local_1->f_3c = D_00E3A7D0->f_3c;
		local_1->f_3e = D_00E3A7D0->f_3e;
		local_1->f_51 |= 2;
		D_00E3A7D0->f_08 = 0;
		D_00E3A7D0 = local_1;
	}
}

void C_00761407(struct t_local_unknown_c0 *bp08) {
	if(bp08 && bp08->pNext == 0) {
		bp08->pNext = D_00E39A00;
		D_00E39A00 = bp08;
	}
}

void C_0076142D() {
	struct t_local_unknown_c0 *local_1;

	if(D_00E39AD8 && D_00E39AD8->f_08) {
		local_1 = D_00E39AD8->f_08;
		C_00761407(local_1);
		local_1->f_04 = D_00E39AD8;
		local_1->sPos = D_00E39AD8->sPos;
		local_1->sPrevPos = D_00E39AD8->sPrevPos;
		local_1->f_40 = D_00E39AD8->f_40;
		local_1->wDirection = D_00E39AD8->wDirection;
		local_1->f_3c = D_00E39AD8->f_3c;
		local_1->f_3e = D_00E39AD8->f_3e;
		local_1->f_51 |= 2;
		D_00E39AD8->f_08 = 0;
		D_00E39AD8 = local_1;
	}
}

int C_00761521() {
	return D_00E39AD8?D_00E39AD8->f_08 != 0:0;
}

void C_0076156B(struct t_local_unknown_c0 *);

void C_0076154F() {
	if(D_00E3A7D0)
		C_0076156B(D_00E3A7D0);
}

void C_0076156B(struct t_local_unknown_c0 *bp08) {
	C_007611FF(bp08);
	bp08->pNext = D_00E3A7D4;
	D_00E3A7D4 = bp08;
	D_00E3A7C8 = C_00768A37(bp08->bModelType);
	if(D_00E3A7C8)
		D_00E3A7C8->f_24 = 0;
}

void C_007615BA() {
	if(D_00E39AD8)
		C_0076156B(D_00E39AD8);
}

void C_007615D6() {
	if(D_00E3A7D0 && D_00E3A7D0->f_08) {
		C_0076156B(D_00E3A7D0->f_08);
		D_00E3A7D0->f_08 = 0;
	}
}

void C_0076160D() {
	if(D_00E39AD8 && D_00E39AD8->f_08) {
		C_0076156B(D_00E39AD8->f_08);
		D_00E39AD8->f_08 = 0;
	}
}

//wm:chunk unloaded?
void C_00761644(short wChunkX/*bp08*/, short wChunkY/*bp0c*/) {
	struct {
		struct t_wm_local_08 *local_2;
		struct t_local_unknown_c0 *local_1;
	}lolo;

	for(
		lolo.local_1 = D_00E39A00;
		lolo.local_1;
		lolo.local_1 = lolo.local_1->pNext
	) {
		for(
			lolo.local_2 = &(lolo.local_1->f_60[0]);
			lolo.local_2 < &(lolo.local_1->f_60[6]);
			lolo.local_2 ++
		) {
			if(lolo.local_2->wChunkX == wChunkX && lolo.local_2->wChunkY == wChunkY)
				lolo.local_2->f_00 = 0;
		}//end for
	}//end for
}

//wm:set some info(1)?
void C_007616B3() {
	if(D_00E3A7D0)
		D_00E39AD8 = D_00E3A7D0;
}

//wm:set some info(2)?
void C_007616CB() {
	if(D_00E39AD8)
		D_00E3A7D0 = D_00E39AD8;
}

struct t_wm_local_08 *C_007616E3() {
	return D_00E3A7D0?D_00E3A7D0->f_60:0;
}

//wm:get model type(1)?
int C_0076170B() {
	return D_00E39AD8?D_00E39AD8->bModelType:0;
}

//wm:get model type(2)?
int C_00761735() {
	return D_00E3A7D0?D_00E3A7D0->bModelType:0;
}

struct t_local_unknown_c0 *C_0076175F() {
	return D_00E39AD8;
}

//wm:is current model in list(1)?
int C_00761769(int dwMask/*bp08*/) {
	return (D_00E3A7D0 && D_00E3A7D0->bModelType < 32)?((dwMask & (1 << D_00E3A7D0->bModelType)) != 0):0;
}

//wm:is current model in list(2)?
int __007617B7(int dwMask/*bp08*/) {
	return (D_00E39AD8 && D_00E39AD8->bModelType < 32)?((dwMask & (1 << D_00E39AD8->bModelType)) != 0):0;
}

//wm:is model in list?
int C_00761805(int dwMask/*bp08*/, unsigned char bModelType/*bp0c*/) {
	return bModelType < 32?((dwMask & (1 << bModelType)) != 0):0;
}

//wm:is current model a chocobo(1)?
int C_00761844() {
	return D_00E3A7D0?(
		D_00E3A7D0->bModelType == WM_MODELID_04 ||
		D_00E3A7D0->bModelType == WM_MODELID_19 ||
		D_00E3A7D0->bModelType == WM_MODELID_41 ||
		D_00E3A7D0->bModelType == WM_MODELID_42
	):0;
}

//wm:is current model a chocobo(2)?
int C_007618B7() {
	return D_00E39AD8?(
		D_00E39AD8->bModelType == WM_MODELID_04 ||
		D_00E39AD8->bModelType == WM_MODELID_19 ||
		D_00E39AD8->bModelType == WM_MODELID_41 ||
		D_00E39AD8->bModelType == WM_MODELID_42
	):0;
}

//wm:is model a chocobo?
int C_0076192A(unsigned char bModelType/*bp08*/) {
	return (
		bModelType == WM_MODELID_04 ||
		bModelType == WM_MODELID_19 ||
		bModelType == WM_MODELID_41 ||
		bModelType == WM_MODELID_42
	);
}

void C_0076616A(struct t_local_unknown_c0 *);//load object coordinates?

void C_0076197B(int dwModelType/*bp08*/) {
	struct t_wm_local_sRect bp_08;

	if(D_00E39AD8) {
		D_00E39AD8->bModelType = dwModelType;
		switch(dwModelType) {
			case WM_MODELID_03:
				//-- add propeller --
				if(!C_00768C59())//wm:highwind has reactor?
					D_00E39AD8->f_08 = &D_00E39AE0;
				//-- --
				bp_08.wX = 24;
				bp_08.wY = 16;
				bp_08.wWidth = 14;
				bp_08.wHeight = 31;
				D_00E39AD8->f_90.f_28 = D_00E2C400;
			break;
			case WM_MODELID_10:
				bp_08.wX  = 16;
				bp_08.wY  = 0;
				bp_08.wWidth  = 15;
				bp_08.wHeight  = 15;
				D_00E39AD8->f_58 = 8 << 4;
				D_00E39AD8->f_90.f_28 = D_00E2C3E4;
			break;
			case WM_MODELID_28:
			break;
			case WM_MODELID_11:
				bp_08.wX  = 0;
				bp_08.wY  = 0;
				bp_08.wWidth  = 23;
				bp_08.wHeight  = 47;
				D_00E39AD8->f_58 = 2 << 4;
				D_00E39AD8->f_90.f_28 = D_00E2C400;
			break;
			case WM_MODELID_04:
				C_0075E4D6(WM_MODELID_04, 0);//wm:apply tint to model?
				//no break
			default:
				bp_08.wX  = 24;
				bp_08.wY  = 0;
				bp_08.wWidth  = 15;
				bp_08.wHeight  = 15;
				D_00E39AD8->f_58 = 2 << 4;
				D_00E39AD8->f_90.f_28 = D_00E2C400;
			case WM_MODELID_05:
			case WM_MODELID_13:
			break;
		}//end switch
		C_0075D482(&(D_00E39AD8->f_90), &bp_08);//wm:set model's texture coords?
		C_0076616A(D_00E39AD8);//load object coordinates?
	}
}

void C_00761B19(short wAngle/*bp08*/) {
	if(D_00E39AD8) {
		D_00E39AD8->f_40 = wAngle;
		D_00E39AD8->wDirection = wAngle;
		D_00E39AD8->f_3e = 0;
	}
}

void __00761B4E(short wAngle/*bp08*/) {
	if(D_00E3A7D0) {
		D_00E3A7D0->f_40 = wAngle;
		D_00E3A7D0->wDirection = wAngle;
		D_00E3A7D0->f_3e = 0;
	}
}

void C_00761B83(short wAngle/*bp08*/) {
	if(D_00E39AD8) {
		D_00E39AD8->f_40 = wAngle;
		D_00E39AD8->wDirection = wAngle;
	}
}

void C_00761BAC(short wAngle/*bp08*/) {
	if(D_00E39AD8) {
		D_00E39AD8->f_40 = wAngle;
		D_00E39AD8->f_3c = wAngle;
		D_00E39AD8->wDirection = wAngle;
		D_00E39AD8->f_3e = 0;
	}
}

void C_00761C07(struct t_local_unknown_c0 *, short);//model angle related?

//current model angle related?
void C_00761BEE(short bp08) {
	C_00761C07(D_00E39AD8, bp08);//model angle related?
}

//model angle related?
void C_00761C07(struct t_local_unknown_c0 *bp08, short bp0c) {
	struct {
		DECL_short(local_3);
		DECL_short(local_2);
		DECL_short(local_1);
	}lolo;

	if(bp08) {
		if(bp0c < 0)
			bp0c += 0x1000;
		lolo.local_1 = inline_abs(bp08->f_3c - bp0c);
		lolo.local_2 = inline_abs(bp08->f_3c - bp0c + 0x1000);
		lolo.local_3 = inline_abs(bp08->f_3c - bp0c - 0x1000);
		if(lolo.local_1 > lolo.local_2) {//else 00761D3C
			if(lolo.local_2 > lolo.local_3)
				bp0c += 0x1000;
			else
				bp0c -= 0x1000;
		} else {
			if(lolo.local_1 > lolo.local_3)
				bp0c += 0x1000;
		}
		bp08->f_3c = /*lolo.local_7*/(D_00DFC480 == 1)?(bp08->f_3c * 7 + bp0c) >> 3:(bp08->f_3c * 3 + bp0c) >> 2;
		if(bp08->f_3c < 0)
			bp08->f_3c += 0x1000;
		else if(bp08->f_3c >= 0x1000)
			bp08->f_3c -= 0x1000;
	}
}

void __00761DDC(short bp08) {
	C_00761C07(D_00E3A7D0, bp08);//model angle related?
}

void C_00761DF5(short bp08) {
	if(D_00E39AD8) {
		D_00E39AD8->f_3e = (D_00DFC480 == 1)?
			(D_00E39AD8->f_51 & 1)?(D_00E39AD8->f_3e * 15 + bp08) >> 4:(D_00E39AD8->f_3e * 3 + bp08) >> 2:
			(D_00E39AD8->f_51 & 1)?(D_00E39AD8->f_3e * 7 + bp08) >> 3:(D_00E39AD8->f_3e + bp08) >> 1
		;
	}
}

short C_00761EB6() {
	return D_00E39AD8?D_00E39AD8->f_3c + D_00E39AD8->f_3e:0;
}

short C_00761EEC() {
	return D_00E3A7D0?D_00E3A7D0->f_3c + D_00E3A7D0->f_3e:0;
}

void C_00761F22(int bp08) {
	if(D_00E39AD8)
		D_00E39AD8->sPos.vy += bp08;
}

int C_00761F44() {
	return D_00E39AD8?(D_00E39AD8->f_51 & 1) != 0:0;
}

int C_00761F77() {
	return D_00E3A7D0?(D_00E3A7D0->f_51 & 1) != 0:0;
}

void C_00761FAA(int bp08) {
	if(D_00E3A7D0) {
		if(bp08)
			D_00E3A7D0->f_51 |= 0x80;
		else
			D_00E3A7D0->f_51 &= ~0x80;
	}
}

int C_00761FE8() {
	return 	D_00E3A7D0?(D_00E3A7D0->f_51 & 0x80) != 0:0;
}


int C_0076201E() {
	return D_00E3A7D0?D_00E3A7D0->f_42:0;
}

//wm:set current model
int C_00762047(int dwModelType/*bp08*/) {
	struct t_local_unknown_c0 *local_1;

	for(
		local_1 = D_00E39A00;
		local_1 && local_1->bModelType != dwModelType;
		local_1 = local_1->pNext
	);
	if(local_1)
		D_00E39AD8 = local_1;

	return local_1 != 0;
}

void __0076208E() {
	if(D_00E3A7D0 && D_00E3A7D0->f_04)
		D_00E39AD8 = D_00E3A7D0->f_04;
}

int C_007620B6() {
	return (D_00E3A7D0 && D_00E39AD8 && D_00E3A7D0 != D_00E39AD8 && (D_00E39AD8->f_51 & 0x10) == 0);
}

//wm:set model type?
void C_00762102(int dwModelType/*bp08*/) {
	if(D_00E3A7D0)
		D_00E3A7D0->bModelType = dwModelType;
}

//wm:set terrain info?
void C_0076211B(int wTerrainInfo/*bp08*/) {
	if(D_00E3A7D0)
		D_00E3A7D0->wTerrainInfo = wTerrainInfo;
}

//wm:get current terrain?
//0:grass
//1:forest
//...
//6:sea
//7:swamps
//...
//0xe:bridge
int C_00762136() {
	return D_00E3A7D0?D_00E3A7D0->wTerrainInfo & 0x1f:0;
}

//wm:get location id?
int C_00762162() {
	return D_00E3A7D0?(D_00E3A7D0->wTerrainInfo >> 9) & 0x1f:0;
}

//wm:is chocobo location?
int C_00762191() {
	return D_00E3A7D0?(D_00E3A7D0->wTerrainInfo >> 15) & 1:0;
}

//wm:current terrains's script?
int C_007621C0() {
	return D_00E3A7D0?(D_00E3A7D0->wTerrainInfo >> 5) & 7:0;
}

void C_00762207(struct t_local_unknown_c0 *, struct VECTOR *);

void C_007621EF(struct VECTOR *bp08) {
	C_00762207(D_00E39AD8, bp08);
}

int C_007622E5(int, unsigned char);

void C_00762207(struct t_local_unknown_c0 *bp08, struct VECTOR *bp0c) {
	if(bp0c && bp08) {
		C_00750202(bp0c);//wm:clamp x,z?
		if(bp08->f_51 & 0x80) {
			bp08->sPos.vx = bp0c->vx;
			bp08->sPos.vz = bp0c->vz;
		} else {
			bp08->sPos = *bp0c;
			bp08->sPos.vy += C_007622E5(bp08->wTerrainInfo, bp08->bModelType);
		}
		bp08->f_42 = bp0c->vy;
		if(bp08->sPos.vx != bp08->sPrevPos.vx || bp08->sPos.vz != bp08->sPrevPos.vz)
			bp08->f_51 |= 1;
		else
			bp08->f_51 &= ~1;
	}
}

int C_007622E5(int bp08, unsigned char bModelType/*bp0c*/) {
	bp08 &= 0x1f;
	switch(bModelType) {
		case WM_MODELID_08:
			return -0xf;
		case WM_MODELID_13:
			return -0xf0;
		case WM_MODELID_25:
			return 0;
		case WM_MODELID_19:
			if((bp08 >= 3 && bp08 <= 6) || bp08 == 0x1a) {//else 007623F7
				if(D_00E3A7D0->f_51 & 1) {//else 0076239D
					if(D_00E39BB0 < 0)
						D_00E39BB0 = min(0, D_00E39BB0 + 20);
				} else {
					int bp_04 = (bp08 != 4 && bp08 != 6)?-250:-50;
					if(D_00E39BB0 > bp_04)
						D_00E39BB0 -= 10;
					else if(D_00E39BB0 < bp_04 - 20)
						D_00E39BB0 = bp_04;
				}
				return D_00E39BB0;
			}
			D_00E39BB0 = 0;
	}//end switch

	return
		(bp08 == 1 || bp08 == 0x19)?-0xc0:
		(bp08 == 4 || bp08 == 7)?-0x40:
		0;
}

void C_00762465(struct VECTOR *bp08) {
	C_00762207(D_00E3A7D0, bp08);
}

void C_0076247D(struct VECTOR *bp08) {
	C_00762207(D_00E3A7D0, bp08);
	if(D_00E3A7D0)
		D_00E3A7D0->sPrevPos = D_00E3A7D0->sPos;
}

void C_007624C5(struct VECTOR *bp08) {
	int local_1;

	local_1 = C_00762136();//wm:get current terrain?
	C_00762207(D_00E3A7D0, bp08);
	if(local_1 == 1 || local_1 == 0x19)
		D_00E3A854 = 0x1e;
	else if(local_1 == 2 || local_1 == 0xc)
		D_00E3A854 = 0;
	if(!(D_00E3A7D0->f_51 & 0x80) && D_00E3A854) {//else 007626EA
		D_00E3A854 -= (D_00E3A7D0->f_51 & 1) != 0;
		if(D_00E3A850) {//else 00762680
			if(D_00E3A7D0->sPos.vy > D_00E3A7D0->sPrevPos.vy ^ D_00E3A850 > 0) {
				D_00E3A850 = 0;
				D_00E3A7D0->sPos.vy = D_00E3A7D0->sPrevPos.vy;
				//goto 0076267E
			} else if(D_00E3A7D0->f_51 & 1) {//else 0076266C
				if(D_00E3A7D0->sPos.vy > D_00E3A7D0->sPrevPos.vy) {//else 00762622
					if(D_00E3A7D0->sPos.vy - D_00E3A7D0->sPrevPos.vy > D_00E3A850) {//else 00762616
						D_00E3A7D0->sPos.vy = D_00E3A7D0->sPrevPos.vy + D_00E3A850;
						D_00E3A850 <<= 1;
					} else {
						D_00E3A850 = 0;
					}
					//goto 0076266A
				} else {
					if(D_00E3A7D0->sPos.vy - D_00E3A7D0->sPrevPos.vy < D_00E3A850) {//else 00762660
						D_00E3A7D0->sPos.vy = D_00E3A7D0->sPrevPos.vy + D_00E3A850;
						D_00E3A850 <<= 1;
					} else {
						D_00E3A850 = 0;
					}
				}
				//0076266A	goto 0076267E
			} else {
				D_00E3A7D0->sPos.vy = D_00E3A7D0->sPrevPos.vy;
			}
			//0076267E	goto 007626E8
		} else {
			if(D_00E3A7D0->sPos.vy - D_00E3A7D0->sPrevPos.vy < -50) {//else 007626B5
				D_00E3A7D0->sPos.vy = D_00E3A7D0->sPrevPos.vy;
				D_00E3A850 = -1;
				//goto 007626E8
			} else if(D_00E3A7D0->sPos.vy - D_00E3A7D0->sPrevPos.vy > 50) {//else 007626E8
				D_00E3A7D0->sPos.vy = D_00E3A7D0->sPrevPos.vy;
				D_00E3A850 = 1;
			}
		}
		//007626E8	goto 007626FE
	} else {
		D_00E3A850 = 0;
		D_00E3A854 = 0;
	}
}

void C_00762702(int bp08) {
	if(D_00E3A7D0)
		D_00E3A7D0->sPos.vy = bp08;
}

void C_0076271B(int bp08) {
	if(D_00E3A7D0) {
		D_00E3A7D0->sPos.vy = bp08;
		D_00E3A7D0->f_51 |= 4;
	}
}

void __00762748(int bp08) {
	if(D_00E3A7D0)
		D_00E3A7D0->f_4e = bp08;
}

//wm:get model pos(1)?
void C_00762763(struct VECTOR *bp08) {
	if(bp08 && D_00E39AD8)
		*bp08 = D_00E39AD8->sPos;
}

//wm:get model pos(2)?
void C_00762798(struct VECTOR *bp08) {
	if(bp08 && D_00E3A7D0)
		*bp08 = D_00E3A7D0->sPos;
}

//wm:get model previous pos(1)?
void C_007627CD(struct VECTOR *bp08) {
	if(bp08 && D_00E39AD8)
		*bp08 = D_00E39AD8->sPrevPos;
}

//wm:get model previous pos(2)?
void C_00762802(struct VECTOR *bp08) {
	if(bp08 && D_00E3A7D0)
		*bp08 = D_00E3A7D0->sPrevPos;
}

void C_00762837() {
	if(D_00E39AD8) {
		if(D_00E39AD8->f_51 & 4) {
			D_00E39AD8->sPos.vx = D_00E39AD8->sPrevPos.vx;
			D_00E39AD8->sPos.vz = D_00E39AD8->sPrevPos.vz;
		} else {
			D_00E39AD8->sPos = D_00E39AD8->sPrevPos;
		}
		D_00E39AD8->f_51 &= ~1;
	}
}

void C_007628B5() {
	if(D_00E3A7D0) {
		if(D_00E3A7D0->f_51 & 4) {
			D_00E3A7D0->sPos.vx = D_00E3A7D0->sPrevPos.vx;
			D_00E3A7D0->sPos.vz = D_00E3A7D0->sPrevPos.vz;
		} else {
			D_00E3A7D0->sPos = D_00E3A7D0->sPrevPos;
		}
		D_00E3A7D0->f_51 &= ~1;
	}
}

void C_00762933() {
	if(D_00E3A7D0)
		D_00E3A7D0->f_51 &= ~2;
}

void C_00762955(int bp08) {
	if(D_00E39AD8)
		D_00E39AD8->f_5d = bp08;
}

struct t_local_unknown_c0 *C_00762993(void);

struct t_local_unknown_c0 *C_0076296E() {
	struct t_local_unknown_c0 *local_1 = 0;

	local_1 = C_00762993();
	if(local_1)
		C_00762837();

	return local_1;
}

int C_00762A21(struct t_local_unknown_c0 *, struct t_local_unknown_c0 *);

struct t_local_unknown_c0 *C_00762993() {
	struct {
		int local_2;
		struct t_local_unknown_c0 *local_1;
	}lolo;

	lolo.local_2 = 0;
	lolo.local_1 = 0;
	if(D_00E39AD8) {//else 00762A10
		if(
			D_00E39AD8->bModelType != WM_MODELID_13 ||
			C_0074D330() != 0//wm:get current map id?
		) {//else 00762A10
			for(
				lolo.local_1 = D_00E39A00;
				lolo.local_1 && !(lolo.local_2 = C_00762A21(D_00E39AD8, lolo.local_1));
				lolo.local_1 = lolo.local_1->pNext
			);
			if(lolo.local_1)
				D_00E39AD8->f_04 = lolo.local_1;
		}
	}

	return (lolo.local_2 < 2)?lolo.local_1:0;
}

unsigned char D_0096DDB0[][8] = {
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x18,0x3C,0x3C,0x18,0x00,0x00},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x18,0x3C,0x7E,0x7E,0x3C,0x18,0x00},
	{0x00,0x00,0x18,0x3C,0x3C,0x18,0x00,0x00},
	{0x00,0x00,0x18,0x3C,0x3C,0x18,0x00,0x00},
	{0x18,0x3C,0x7E,0xFF,0xFF,0x7E,0x3C,0x18},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x3C,0x7E,0xFF,0xFF,0xFF,0xFF,0x7E,0x3C},
	{0x3C,0x7E,0xFF,0xFF,0xFF,0xFF,0x7E,0x3C},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x18,0x3C,0x7E,0x7E,0x3C,0x18,0x00},
	{0x18,0x3C,0x7E,0xFF,0xFF,0x7E,0x3C,0x18},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x18,0x3C,0x3C,0x18,0x00,0x00}
};

int C_00762A21(struct t_local_unknown_c0 *bp08, struct t_local_unknown_c0 *bp0c) {
	struct {//x2c
		int local_4;
		int local_3;
		int local_2;
		int local_1;
	}lolo;

	lolo.local_1 = 0;
	if(
		bp08 && bp0c && bp08 != bp0c &&
		!(bp08->f_51 & 0x80) && !(bp0c->f_51 & 0x80) && 
		bp08->bModelType < WM_MODELID_26 && bp0c->bModelType < WM_MODELID_26 &&
		bp0c->bModelType != WM_MODELID_21 &&
		bp0c->bModelType != WM_MODELID_22 &&
		bp0c->bModelType != WM_MODELID_23
	) {
		lolo.local_3 = bp0c->sPos.vx - bp08->sPos.vx;
		if(lolo.local_3 > 0x24000)
			lolo.local_3 -= 0x48000;
		else if(lolo.local_3 < -0x24000)
			lolo.local_3 += 0x48000;
		lolo.local_4 = bp0c->sPos.vz - bp08->sPos.vz;
		if(lolo.local_4 > 0x1c000)
			lolo.local_4 -= 0x38000;
		else if(lolo.local_4 < -0x1c000)
			lolo.local_4 += 0x38000;
		if(/*lolo.local_5*/inline_abs(lolo.local_3) < 0x400 && /*lolo.local_6*/inline_abs(lolo.local_4) < 0x400) {
			lolo.local_2 = inline_abs(lolo.local_3) + inline_abs(lolo.local_4);
			lolo.local_3 = (lolo.local_3 + 0x400) >> 8;
			lolo.local_4 = (lolo.local_4 + 0x400) >> 8;
			if(lolo.local_3 >= 0 && lolo.local_3 < 8 && lolo.local_4 >= 0 && lolo.local_4 < 8) {
				lolo.local_1 = /*lolo.local_9*/
					((D_0096DDB0[bp08->bModelType][lolo.local_4] >> lolo.local_3) & 1) ||
					((D_0096DDB0[bp0c->bModelType][7 - lolo.local_4] >> (7 - lolo.local_3)) & 1);
				if(lolo.local_1) {
					lolo.local_3 = bp0c->sPos.vx - bp08->sPrevPos.vx;
					if(lolo.local_3 > 0x24000)
						lolo.local_3 -= 0x48000;
					else if(lolo.local_3 < -0x24000)
						lolo.local_3 += 0x48000;
					lolo.local_4 = bp0c->sPos.vz - bp08->sPrevPos.vz;
					if(lolo.local_4 > 0x1c000)
						lolo.local_4 -= 0x38000;
					else if(lolo.local_4 < -0x1c000)
						lolo.local_4 += 0x38000;
					if(inline_abs(lolo.local_3) + inline_abs(lolo.local_4) <= lolo.local_2)
						lolo.local_1 = 2;
				}
			}
		}
	}

	return lolo.local_1;
}

struct t_local_unknown_c0 *__00762D2A() {
	return D_00E39AD8?D_00E39AD8->f_04:0;
}

void C_00762D52() {
	if(D_00E3A7D0)
		D_00E3A7D0->f_51 |= 2;
}

void C_00762D74(struct t_wm_TerrainChunkInfo *bp08) {
	struct {
		DECL_short(wChunkY);
		struct t_local_unknown_c0 *local_5;
		DECL_short(wChunkX);
		struct SVECTOR local_3;
		struct t_local_unknown_c0 *local_1;
	}lolo;

	for(
		lolo.local_5 = 0, lolo.local_1 = D_00E39A00;
		lolo.local_1;
		lolo.local_5 = lolo.local_1, lolo.local_1 = lolo.local_1->pNext
	) {
		if(lolo.local_1 != D_00E3A7D0) {//else 00762E65
			C_00750134(&(lolo.local_1->sPos), &lolo.local_3, &lolo.wChunkX, &lolo.wChunkY);//wm:world to chunk coordinates?
			if(lolo.wChunkX == bp08->wChunkX && lolo.wChunkY == bp08->wChunkY) {//else 00762E65
				C_0074CC07(bp08, &lolo.local_3, lolo.local_1->f_60, &(lolo.local_1->f_42), 0, &(lolo.local_1->wTerrainInfo), lolo.local_1->bModelType);
				if(!(lolo.local_1->f_51 & 0x80))
					lolo.local_1->sPos.vy = lolo.local_1->f_42 + C_007622E5(lolo.local_1->wTerrainInfo, lolo.local_1->bModelType);
				lolo.local_1->f_51 |= 2;
			}
		}
	}//end for
	C_007561F6(bp08);//wm:Midgar Zolom related(2)
	C_00756B0C(bp08);
}

void C_00762E87(int dwDeltaX/*bp08*/, int dwDeltaY/*bp0c*/) {
	if(D_00E39AD8) {
		if(dwDeltaX || dwDeltaY) {
			D_00E39AD8->sPos.vx += dwDeltaX;
			D_00E39AD8->sPos.vz += dwDeltaY;
			if(D_00E39AD8->sPos.vx < 0)
				D_00E39AD8->sPos.vx += 0x48000;
			if(D_00E39AD8->sPos.vx >= 0x48000)
				D_00E39AD8->sPos.vx -= 0x48000;
			if(D_00E39AD8->sPos.vz < 0)
				D_00E39AD8->sPos.vz += 0x38000;
			if(D_00E39AD8->sPos.vz >= 0x38000)
				D_00E39AD8->sPos.vz -= 0x38000;
			D_00E39AD8->f_51 |= 1;
		}
	}
}

//wm:set model tilt x,y,z?
void C_00762F75(int bp08, int bp0c, int bp10) {
	D_00E39BB4 = bp08;//model tilt x
	D_00E39BB8 = bp0c;//model tilt y
	D_00E39BBC = bp10;//model tilt z
}

int C_00762F9A(int dwX/*bp08*/, int dwZ/*bp0c*/) {
	struct {//xc8
		struct tVECTOR_F4 local_48;
		int local_44;
		D3DVECTOR local_43;
		D3DVECTOR local_40;
		int local_37;
		struct SVECTOR local_36;
		D3DMATRIX local_34;
		DECL_short(local_18);
		D3DMATRIX local_17;
		int _ocal_1;
	}lolo;

	lolo.local_36.vx = 0;
	lolo.local_36.vy = 0;
	lolo.local_36.vz = 0;
	lolo.local_36.pad = 0;
	C_0074D33A(&lolo.local_36);//wm:set trans matrix from svector?
	lolo.local_37 = (D_00DE68F8 >> 1) + D_00E2C424;
	lolo.local_40.x = (float)dwX;
	lolo.local_40.y = 0;
	lolo.local_40.z = (float)dwZ;
	C_006617E9(C_0066100D(), &lolo.local_17);//psx:transformation to D3DMATRIX(3)
	C_0067D2BF(&lolo.local_17, &lolo.local_34);//dx_mat:matrix multiplication by "struct t_aa0::f_8d0" 4x4[transpose]
	fast_multVectorByTransform(&lolo.local_34, &lolo.local_40, &lolo.local_48);
	fast_multVectorByRotTrans_Z_only(&lolo.local_17, &lolo.local_40, &lolo.local_43);
	lolo.local_44 = (int)lolo.local_43.z >> 2;
	lolo.local_18 = (int)(lolo.local_48.x / lolo.local_48.w);
	lolo.local_18 = (lolo.local_18 >= lolo.local_37)?lolo.local_18 - lolo.local_37:lolo.local_37 - lolo.local_18;
	lolo.local_44 -= C_0074D4ED();
	lolo.local_44 = (lolo.local_44 > 0)?
		((lolo.local_44 * lolo.local_44) >> 0xc) + ((lolo.local_18 * lolo.local_18) >> 0xa):
		0
	;

	return lolo.local_44 >> 2;
}

void C_0076312D(struct SVECTOR *bp08) {
	if(bp08) {
		bp08->vx = D_00E3A848;
		bp08->vy = 0;
		bp08->vz = D_00E3A84C;
	}
}

void C_007631DF(struct t_local_unknown_c0 *);

void C_0076315C() {
	struct t_local_unknown_c0 *local_1;

	for(local_1 = D_00E39A00; local_1; local_1 = local_1->pNext)
		C_007631DF(local_1);
	for(local_1 = D_00E39A00; local_1; local_1 = local_1->pNext) {
		local_1->f_51 &= ~7;
		D_00E3A7C8 = C_00768A37(local_1->bModelType);
		if(D_00E3A7C8)
			D_00E3A7C8->f_24 = 0;
	}//end for
}

void C_007631DF(struct t_local_unknown_c0 *bp08) {
	if(bp08->f_04) {
		if((bp08->f_51 & 1) || (bp08->f_04->f_51 & 1))
			bp08->f_04 = 0;
	}
	bp08->sPrevPos = bp08->sPos;
}

void C_0076328F(struct t_local_unknown_c0 *);
void C_00763B74(struct t_local_unknown_c0 *);

void C_0076323A() {
	struct t_local_unknown_c0 *local_1;

	for(local_1 = D_00E39A00; local_1; local_1 = local_1->pNext)
		C_0076328F(local_1);
	for(local_1 = D_00E39A00; local_1; local_1 = local_1->pNext)
		C_00763B74(local_1);
}

int C_00763AAE(unsigned char *);

void C_0076328F(struct t_local_unknown_c0 *bp08) {
	struct {//x74
		struct VECTOR local_20;
		int dwAnimFrame;//local_16
		struct t_wm_b8 *local_15;
		struct t_wm_local_30 *local_14;
		int dwDiffZ;//local_13
		int dwDistSq;//local_12
		int local_11;
		int dwDiffY;//local_10
		struct t_wm_b8 *local_9;
		struct SVECTOR local_8;
		int dwDiffX;//local_6
		DECL_short(wAnim);
		struct VECTOR local_4;
	}lolo;

	if(bp08->f_51 & 8)
		bp08->f_51 &= ~2;
	if(bp08 && D_00E3A7D0 && (bp08->f_51 & 2)) {//else 00763AA9
		lolo.local_9 = C_00768A37(bp08->bModelType);
		if(lolo.local_9 == 0) {
			bp08->f_51 &= ~2;
			//goto 00763AA9
		} else {
			lolo.local_15 = 0;
			if(bp08->f_08 && (lolo.local_15 = C_00768A37(bp08->f_08->bModelType)) == 0) {
				bp08->f_08->f_51 &= ~2;
				//goto 00763AA9
			} else {
				lolo.dwDistSq = 0;
				if(bp08->f_5d) {//else 0076338E
					lolo.wAnim = /*lolo.local_21*/(bp08->f_5d > 0)?bp08->f_5d:0;
					//goto 007634BF
				} else {
					lolo.dwDiffX = /*lolo.local_22*/inline_abs(bp08->sPos.vx - bp08->sPrevPos.vx);
					if(lolo.dwDiffX >= 0x24000)
						lolo.dwDiffX = 0x48000 - lolo.dwDiffX;

					lolo.dwDiffY = /*lolo.local_23*/inline_abs(bp08->sPos.vz - bp08->sPrevPos.vz);
					if(lolo.dwDiffY >= 0x1c000)
						lolo.dwDiffY = 0x38000 - lolo.dwDiffY;

					lolo.dwDistSq = lolo.dwDiffX * lolo.dwDiffX + lolo.dwDiffY * lolo.dwDiffY;
					lolo.wAnim = lolo.dwDistSq >= 100;
					if(bp08->bModelType == WM_MODELID_06) {//else 00763495
						bp08->f_58 = (bp08 == D_00E3A7D0) << 5;
						lolo.wAnim = /*lolo.local_24*/lolo.dwDistSq?C_00763AAE(&(bp08->bAnimFrame)):0;
					} else if(C_00761805(0x2000, bp08->bModelType)) {//wm:is model in list?
						bp08->f_58 = (lolo.dwDistSq > 0) << 5;
					}
				}
//007634BF
				lolo.local_9->f_01 = 0;
				if(lolo.wAnim >= lolo.local_9->bAnimationCount)
					lolo.wAnim = lolo.local_9->bAnimationCount - 1;
				//-- animation loop/one shot --
				if(bp08->bAnimFrame >= lolo.local_9->f_3c[lolo.wAnim]->dwFrameCount)
					bp08->bAnimFrame = /*lolo.local_25*/(bp08->f_51 & 0x20)?lolo.local_9->f_3c[lolo.wAnim]->dwFrameCount - 1:0;
				//-- --
				lolo.dwDiffX =
				lolo.dwDiffZ = 0;
				lolo.local_11 = 0;
				lolo.local_8.vx =
				lolo.local_8.vy =
				lolo.local_8.vz = 0;
				if((bp08->f_51 & 0x80) && bp08 == D_00E3A7D0) {
					lolo.local_9->f_44.sRot.x = (float)(D_00E39BB4 - 64);
					lolo.local_9->f_44.sRot.y = 0;
					lolo.local_9->f_44.sRot.z = 0;
					lolo.local_9->f_44.sPos.x = 0;
					lolo.local_9->f_44.sPos.y = (float)(bp08->sPos.vy - D_00DE6A04);
					lolo.local_9->f_44.sPos.z = 0;
					lolo.local_8.vy = D_00E39BB8 + bp08->f_3c + bp08->f_3e;
					lolo.local_8.vz = D_00E39BBC;
					//goto 00763710
				} else {
					C_0075042B(&lolo.local_4);//wm:get some pos?

					lolo.dwDiffX = bp08->sPos.vx - lolo.local_4.vx;
					if(lolo.dwDiffX < -0x24000)
						lolo.dwDiffX += 0x48000;
					else if(lolo.dwDiffX >= 0x24000)
						lolo.dwDiffX -= 0x48000;
					lolo.local_9->f_44.sPos.x = (float)lolo.dwDiffX;

					lolo.dwDiffZ = bp08->sPos.vz - lolo.local_4.vz;
					if(lolo.dwDiffZ < -0x1c000)
						lolo.dwDiffZ += 0x38000;
					else if(lolo.dwDiffZ >= 0x1c000)
						lolo.dwDiffZ -= 0x38000;
					lolo.local_9->f_44.sPos.z = (float)lolo.dwDiffZ;

					if(bp08 != D_00E3A7D0)
						lolo.local_11 = C_00762F9A(lolo.dwDiffX, lolo.dwDiffZ);

					lolo.dwDiffY = bp08->sPos.vy - D_00DE6A04 + bp08->f_44;
					lolo.local_9->f_44.sPos.y = (float)(lolo.dwDiffY - lolo.local_11);

					lolo.local_9->f_44.sRot.x = -64.0f;
					lolo.local_9->f_44.sRot.y = (float)((bp08->f_3c + bp08->f_3e) >> 4);
					lolo.local_9->f_44.sRot.z = 0;
				}
				if(lolo.local_15) {
					lolo.local_15->f_44.sPos.x = lolo.local_9->f_44.sPos.x;
					lolo.local_15->f_44.sPos.y = lolo.local_9->f_44.sPos.y;
					lolo.local_15->f_44.sPos.z = lolo.local_9->f_44.sPos.z;
					lolo.local_15->f_44.sRot.x = lolo.local_9->f_44.sRot.x;
					lolo.local_15->f_44.sRot.y = lolo.local_9->f_44.sRot.y;
					lolo.local_15->f_44.sRot.z = lolo.local_9->f_44.sRot.z;
				}
				if(bp08->bModelType == WM_MODELID_06) {//else 0076382E
					lolo.dwAnimFrame = bp08->bAnimFrame;
					if(D_00E3A7D0->bModelType == WM_MODELID_06 && (D_00E3A7D0->f_51 & 1)) {//else 007637F9
						C_007537AE(&lolo.local_20);
						D_00E3A848 = (D_00E3A848 * 3 - C_00753DA9(lolo.local_20.vz, -lolo.local_20.vy)) >> 2;
						D_00E3A84C = (D_00E3A84C * 3 - C_00753DA9(lolo.local_20.vx, -lolo.local_20.vy)) >> 2;
					}
					lolo.local_8.vx = D_00E3A848;
					lolo.local_8.vz = D_00E3A84C;
					C_0075E0BA(lolo.local_9, bp08, lolo.wAnim, lolo.dwAnimFrame, &lolo.local_8);
				} else {
					C_0075E0BA(lolo.local_9, bp08, lolo.wAnim, bp08->bAnimFrame, &lolo.local_8);
				}
				if(lolo.local_15) {//else 007638B7
					if(bp08->bModelType == WM_MODELID_03) {//else 0076388E
						if(bp08->f_08)
							C_0075E0BA(lolo.local_15, 0, 0, bp08->f_08->bAnimFrame, &lolo.local_8);
					} else {
						C_0075E0BA(lolo.local_15, 0, (lolo.wAnim == 0?2:3), bp08->bAnimFrame, &lolo.local_8);
					}
				}
				//-- --
				C_0075AD28(bp08, (bp08->f_51 & 1) != 0);//wm:terrain, vehicle 2D fx?
				//-- --
				if(bp08->f_58 >> 4) {
					bp08->f_59 += D_00DFC480;
					bp08->bAnimFrame += bp08->f_59 / (bp08->f_58 >> 4);
					bp08->f_59 %= bp08->f_58 >> 4;
				}
				if(bp08->bModelType == WM_MODELID_03) {//else 007639D0
					if(bp08->f_51 & 0x80)
						bp08->f_58 = 2 << 4;
					else if(bp08->f_58)
						bp08->f_58 ++;
					if(lolo.dwDistSq >= 200 && bp08->f_08) {//else 007639CE
						bp08->f_08->bAnimFrame ++;
						if(bp08->f_08->bAnimFrame >= lolo.local_9->f_3c[lolo.wAnim]->dwFrameCount)
							bp08->f_08->bAnimFrame = 0;
						//goto 00763A0B
					}
				} else if(bp08->bModelType == WM_MODELID_05) {
					if(bp08 == D_00E3A7D0)
						bp08->f_58 = 2 << 4;
					else if(bp08->f_58)
						bp08->f_58 ++;
				}
				lolo.local_14 = &(bp08->f_90);
				lolo.local_8.vx =
				lolo.local_8.vz = 0;
				if(bp08->bModelType == WM_MODELID_03) {
					lolo.local_8.vx = -10;
					lolo.local_8.vz = 80;
				} else if(bp08->bModelType == WM_MODELID_11) {
					lolo.local_8.vz = -360;
				}
				C_00753D00(&lolo.local_8, bp08->f_3c + bp08->f_3e + C_0074D319() * 4);//wm:SVECTOR z rotation?
				lolo.local_14->f_00.pad1 = lolo.dwDiffX + lolo.local_8.vx;
				bp08->f_48 = bp08->f_42 - lolo.local_11;
				lolo.local_14->f_00.pad2 = lolo.dwDiffZ + lolo.local_8.vz;
			}
		}
	}
}

int C_00763AAE(unsigned char *bp08) {
	struct {
		int bp_08;
		int bp_04;
	}lolo;

	lolo.bp_04 = D_00E3A858;
	lolo.bp_08 = C_00762136();//wm:get current terrain?
	switch(D_00E3A858) {
		case 1:
			if(lolo.bp_08 == 0xb)
				D_00E3A858 = 2;
		break;
		case 2:
			if(*bp08 > 5)
				D_00E3A858 = 3;
		break;
		case 3:
			if(lolo.bp_08 != 4 && lolo.bp_08 != 0xb)
				D_00E3A858 = 4;
		break;
		case 4:
			if(*bp08 > 5)
				D_00E3A858 = 1;
		break;
		default:
			D_00E3A858 = 1;
	}//end switch
	if(D_00E3A858 != lolo.bp_04)
		*bp08 = 0;
	
	return D_00E3A858;
}

void C_00763B74(struct t_local_unknown_c0 *bp08) {
	if(bp08 && D_00E3A7D0 && (bp08->f_51 & 2)) {
		if(
			(
				((C_00761805(7, bp08->bModelType) && !(bp08->f_5d >= 2 && bp08->f_5d <= 5)) || C_0076192A(bp08->bModelType)) &&
				(bp08 != D_00E3A7D0 || D_00E3A850 == 0) &&
				BIT_ISSET_2(0x311B6F05, bp08->wTerrainInfo)
			) ||
			bp08->bModelType == WM_MODELID_03 ||
			bp08->bModelType == WM_MODELID_11
		) {
			C_0075DEAA(bp08);//wm:shadow related?
		}
	}
}

//set "WM?.EV" content
void C_00763C35(void *bp08) {
	int i;

	D_00E399B8 = bp08;
	D_00E3A810 = (unsigned short *)((char *)bp08 + 0x400);
	D_00E39ADC = D_00E3A7F0;
	D_00E3A7E0[0] = D_00DBFD38.f_0ba4;
	D_00E3A7E0[1] =
	D_00E3A7E0[2] =
	D_00E3A7E0[3] = D_00E399C0;
	D_00E3A7CC = 0;
	D_00E39BC0 =
	D_00E3A7DC =
	D_00E3A85C = 0;
	for(i = 0; i < 0x40; i ++)
		D_00E399C0[i] = 0;
	for(i = 0; i < 3; i ++) {
		D_00E3A818[i].vx =
		D_00E3A818[i].vy =
		D_00E3A818[i].vz = 0;
	}
	D_00E39BA8[0] =
	D_00E39BA8[1] = 0;
	D_00E39BA0[0] =
	D_00E39BA0[1] = 0;
	D_00E39A08.vx =
	D_00E39A08.vy =
	D_00E39A08.vz = 0;
}

//wm:set enable/disable script?
void C_00763D6C(int bp08) {
	if(D_00E3A7D0) {
		if(bp08)
			D_00E3A7D0->f_51 |= 0x10;
		else
			D_00E3A7D0->f_51 &= ~0x10;
	}
}

void C_00763E31(int, int);//[local]start script

//start script(3)?
void C_00763DAA(int bp08) {
	if(D_00E39AD8 && !(D_00E39AD8->f_51 & 0x10))
		C_00763E31(bp08 & 0xff, FF7_CLAMP(bp08 - 2, 0, 3));//[local]start script
}

//[local]start script
void C_00763E31(int dwScriptId/*bp08*/, int dwPriority/*bp0c*/) {
	struct {
		int local_4;
		int local_3;
		struct t_wm_ScriptStackElement *local_2;
		struct t_wm_evHeaderEntry *local_1;
	}lolo;

	lolo.local_3 = 0;
	if(D_00E39AD8) {//else 00764010
		if(
			D_00E39AD8->bPriority < dwPriority ||
			(D_00E39AD8->bPriority == dwPriority && dwPriority == 3) ||
			D_00E39AD8->wScriptPC == 0
		) {//else 00764010
			if(D_00E39AD8->bStackDepth >= 4)
				C_0074C9A0(0x41);//<empty>:some error management?
			//-- push current script's context --
			if(D_00E39AD8->wScriptPC != 0) {
				lolo.local_2 = &(D_00E39AD8->f_2c[D_00E39AD8->bStackDepth]);
				D_00E39AD8->bStackDepth ++;
				lolo.local_2->wScriptPC = D_00E39AD8->wScriptPC;
				lolo.local_2->bMoveCnt = D_00E39AD8->bMoveCnt;
				lolo.local_2->bPriority = D_00E39AD8->bPriority;
				lolo.local_3 = 1;
			}
			//-- look for id in list --
			lolo.local_1 = (struct t_wm_evHeaderEntry *)((char *)D_00E399B8 + 0x200);
			for(lolo.local_4 = 0x40; lolo.local_4 && lolo.local_1->wId != dwScriptId; lolo.local_4 >>= 1) {
				if(lolo.local_1->wId < dwScriptId)
					lolo.local_1 += lolo.local_4;
				else
					lolo.local_1 -= lolo.local_4;
			}//end for
			//-- --
			if(lolo.local_1->wId == dwScriptId) {
				//found it
				D_00E39AD8->wScriptPC = lolo.local_1->wOffset;
				D_00E39AD8->bPriority = dwPriority;
			} else {
				//not found
				D_00E39AD8->wScriptPC = 0;
				D_00E39AD8->bPriority = 0;
			}
			//-- restore script's context --
			if(lolo.local_3 && D_00E39AD8->wScriptPC == 0) {//else 00764010
				D_00E39AD8->bStackDepth --;
				lolo.local_2 = &(D_00E39AD8->f_2c[D_00E39AD8->bStackDepth]);
				D_00E39AD8->wScriptPC = lolo.local_2->wScriptPC;
				D_00E39AD8->bMoveCnt = lolo.local_2->bMoveCnt;
				D_00E39AD8->bPriority = lolo.local_2->bPriority;
			}
			//-- --
		}
	}
}

//wm:start script(1)?
void C_00764014(int dwModelType/*bp08*/, int bp0c) {
	C_00762047(dwModelType);//wm:set current model
	if(D_00E39AD8 && !(D_00E39AD8->f_51 & 0x10))
		C_00763E31(0x4000 | ((dwModelType << 8) & 0x3f00) | (bp0c & 0xff), FF7_CLAMP(bp0c - 2, 0, 3));//[local]start script
}

//wm:start script(2)?
void C_007640BC(int bp08) {
	D_00E39AD8 = &D_00E39A18;
	if(bp08 == 1)
		D_00E3A7DC = 1;
	C_00763E31(bp08 & 0xff, FF7_CLAMP(bp08 - 2, 0, 3));//[local]start script
}

//start script(3)?
void C_00764142(short bp08, short bp0c) {
	struct {
		DECL_short(wChunkY);
		DECL_short(wChunkX);
	}lolo;

	D_00E39AD8 = &D_00E39A18;
	C_00750134(&(D_00E3A7D0->sPos), 0, &lolo.wChunkX, &lolo.wChunkY);//wm:world to chunk coordinates?
	C_00763E31(0x8000 | (((lolo.wChunkY * 0x24 + lolo.wChunkX) << 4) & 0x3ff0) | ((bp08 + bp0c * 5) & 0xf), 3);//[local]start script
}

void C_0076420A(struct t_local_unknown_c0 *);//execute script?

//wm:execute scripts?
void C_007641A7() {
	struct t_local_unknown_c0 *local_1;

	D_00E3A7CC = &D_00E39A18;
	D_00E39AD8 = &D_00E39A18;
	C_0076420A(&D_00E39A18);//execute script?
	for(local_1 = D_00E39A00; local_1; local_1 = local_1->pNext) {
		D_00E3A7CC =
		D_00E39AD8 = local_1;
		C_0076420A(local_1);//execute script?
	}//end for
}

void C_00764336(unsigned short);//opcode:0x000~0x0ff
void C_00764CCB(unsigned short);//opcode:0x100~0x1ff
int C_00764D59(unsigned short);//opcode:0x200~0x2ff
int C_00764F9C(unsigned short);//opcode:0x300~

//execute script?
void C_0076420A(struct t_local_unknown_c0 *bp08) {
	struct {
		DECL_unsigned_short(wOpcode);
		int dwPauseScript;//local_1
	}lolo;

	D_00E39BC0 = 0;
	if(D_00E3A7CC->wScriptPC) {//else 007642E1
		lolo.dwPauseScript = 0;
		while(!lolo.dwPauseScript) {
			lolo.wOpcode = D_00E3A810[D_00E3A7CC->wScriptPC ++];
			if(lolo.wOpcode < 0x100)
				C_00764336(lolo.wOpcode);//opcode:0x000~0x0ff
			else if(lolo.wOpcode < 0x200)
				C_00764CCB(lolo.wOpcode);//opcode:0x100~0x1ff
			else if(lolo.wOpcode < 0x300)
				lolo.dwPauseScript = C_00764D59(lolo.wOpcode);//opcode:0x200~0x2ff
			else
				lolo.dwPauseScript = C_00764F9C(lolo.wOpcode);//opcode:0x300~
		}//end while
	}
	//-- --
	C_00761BEE(bp08->f_40);//current model angle related?
	//-- close to a vehicle? --
	if(bp08->f_04 && D_00E3A7DC == 0 && C_0074D4B6())//wm:get enable something?
		C_00764014(bp08->f_04->bModelType, (C_007186B9() & PAD_05) == 0?3:4);//wm:start script(1)?
	//-- --
}

int C_0076488C(void);//pop param
void C_00764B8C(int);//write/push result

//opcode:0x000~0x0ff
void C_00764336(unsigned short wOpcode/*bp08*/) {
	struct {
		struct VECTOR bp_1c;
		struct t_local_unknown_c0 *bp_0c;
		int dwOp2;//bp_08
		int dwOp1;//bp_04
	}lolo;

	switch(wOpcode) {
		case 0x15://neg
			D_00E39ADC->dwValue = -C_0076488C();//pop param
		break;
		case 0x17://not
			D_00E39ADC->dwValue = !C_0076488C();//pop param
		break;
		case 0x30://product
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			D_00E39ADC->dwValue = lolo.dwOp1 * lolo.dwOp2;
		break;
		case 0x40://sum
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			D_00E39ADC->dwValue = lolo.dwOp1 + lolo.dwOp2;
		break;
		case 0x41://diff
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			D_00E39ADC->dwValue = lolo.dwOp1 - lolo.dwOp2;
		break;
		case 0x60://less than
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			D_00E39ADC->dwValue = lolo.dwOp1 < lolo.dwOp2;
		break;
		case 0x61://greater than
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			D_00E39ADC->dwValue = lolo.dwOp1 > lolo.dwOp2;
		break;
		case 0x62://less than or equal
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			D_00E39ADC->dwValue = lolo.dwOp1 <= lolo.dwOp2;
		break;
		case 0x63://greater than or equal
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			D_00E39ADC->dwValue = lolo.dwOp1 >= lolo.dwOp2;
		break;
		case 0x70://equal
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			D_00E39ADC->dwValue = lolo.dwOp1 == lolo.dwOp2;
		break;
		case 0x71://different
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			D_00E39ADC->dwValue = lolo.dwOp1 != lolo.dwOp2;
		break;
		case 0x50://left shift
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			D_00E39ADC->dwValue = lolo.dwOp1 << lolo.dwOp2;
		break;
		case 0x51://right shift
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			D_00E39ADC->dwValue = lolo.dwOp1 >> lolo.dwOp2;
		break;
		case 0x80://and
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			D_00E39ADC->dwValue = lolo.dwOp1 & lolo.dwOp2;
		break;
		case 0xa0://or
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			D_00E39ADC->dwValue = lolo.dwOp1 | lolo.dwOp2;
		break;
		case 0xb0://logical and
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			D_00E39ADC->dwValue = (lolo.dwOp1 && lolo.dwOp2)?1:0;
		break;
		case 0xc0://logical or
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			D_00E39ADC->dwValue = (lolo.dwOp1 || lolo.dwOp2);
		break;
		case 0xe0:
			lolo.dwOp2 = C_0076488C();//pop param
			C_00764B8C(lolo.dwOp2);//write/push result
		break;
		case 0x18:
			C_00754EBC(C_0076488C(), -1);//wm:start color effect zone?
			C_00762763(&lolo.bp_1c);//wm:get model pos(1)?
			D_00E39ADC->dwValue = C_0075542D(&lolo.bp_1c) >> 5;
		break;
		case 0x19:
			lolo.bp_0c = D_00E39AD8;
			D_00E39ADC->dwValue = 0;
			if(C_00762047(C_0076488C()))//wm:set current model
				D_00E39ADC->dwValue = C_00753C23(&(D_00E39AD8->sPos), &(lolo.bp_0c->sPos)) >> 4;
			D_00E39AD8 = lolo.bp_0c;
		break;
		case 0x1a:
			lolo.dwOp1 = C_0076488C();//pop param
			lolo.bp_1c = D_00E39AD8->sPos;
			lolo.bp_1c.vy = 0;
			D_00E39ADC->dwValue = /*lolo.bp_2c*/(lolo.dwOp1 >= 0 && lolo.dwOp1 < 3)?
				C_00753C23(&lolo.bp_1c, &(D_00E3A818[lolo.dwOp1])) >> 4:
				0
			;
		break;
		case 0x1b:
			C_00754EBC(C_0076488C(), -1);//wm:start color effect zone?
			C_00762763(&lolo.bp_1c);//wm:get model pos(1)?
			D_00E39ADC->dwValue = C_0075545F(&lolo.bp_1c) >> 4;
		break;
	}//end switch
	D_00E39ADC->wOpcode = 0x110;//push constant
	D_00E39ADC ++;
}

//pop param
int C_0076488C() {
	struct {
		int dwResult;//bp_08
		short *bp_04;
	}lolo;

	lolo.dwResult = 0;
	if(D_00E39ADC-- <= D_00E3A7F0)
		C_0074C9A0(0x3e);//<empty>:some error management?
	if((D_00E39ADC->wOpcode & 3) < 3) {//else 007649C4
		switch(D_00E39ADC->wOpcode & ~3) {
			case 0x110://constant
				lolo.dwResult = D_00E39ADC->dwValue;
			break;
			case 0x114://bit from bank0~3
				lolo.dwResult = (D_00E3A7E0[D_00E39ADC->wOpcode & 3][D_00E39ADC->dwValue >> 3] >> (D_00E39ADC->dwValue & 7)) & 1;
			break;
			case 0x118://byte from bank0~3
				lolo.dwResult = D_00E3A7E0[D_00E39ADC->wOpcode & 3][D_00E39ADC->dwValue];
			break;
			case 0x11c://short from bank0~3
				lolo.bp_04 = (short *)&(D_00E3A7E0[D_00E39ADC->wOpcode & 3][D_00E39ADC->dwValue]);
				if((unsigned)lolo.bp_04 & 1)
					C_0074C9A0(0x3f);//<empty>:some error management?
				lolo.dwResult = *lolo.bp_04;
			break;
		}//end switch
	} else {
		switch(D_00E39ADC->dwValue) {
			case 0: lolo.dwResult = D_00E39AD8->sPos.vx >> 13; break;//x in mesh
			case 1: lolo.dwResult = D_00E39AD8->sPos.vz >> 13; break;//y in mesh
			case 2: lolo.dwResult = D_00E39AD8->sPos.vx & 0x1fff; break;//x mesh
			case 3: lolo.dwResult = D_00E39AD8->sPos.vz & 0x1fff; break;//y mesh
			case 4: lolo.dwResult = (D_00E39AD8->f_40 >> 4)  & 0xff; break;//direction
			case 5: lolo.dwResult = C_00767204(); break;//wm:get last module id?
			case 6: lolo.dwResult = C_0076720E(); break;//wm:get last field id?
			case 7: lolo.dwResult = C_0074D8CF(); break;//wm:get view mod/map|radar state
			case 8: lolo.dwResult = C_00761735(); break;//wm:get model type(2)?
			case 0xf: lolo.dwResult = D_00E39AD8->bModelType; break;
			case 9: lolo.dwResult = C_007674DF(); break;
			case 0xa: lolo.dwResult = C_007674EB(); break;
			case 0xb: lolo.dwResult = C_007561EC(); break;//wm:is in marshlands?
			case 0xc: lolo.dwResult = C_0075F00E(); break;
			case 0xd: lolo.dwResult = (D_00E39AD8->wTerrainInfo >> 5) & 7; break;//terrain script related?
			case 0xe: lolo.dwResult = C_0076736E(); break;//wm:player's model id[cloud|tifa|cid]
			case 0x10: lolo.dwResult = C_00753BE8(); break;//wm:random?
			case 0x11: lolo.dwResult = D_00E39BA8[0]; break;//new chara related
			case 0x12: lolo.dwResult = D_00E39BA8[1]; break;//new chara related
			case 0x13: lolo.dwResult = D_00E39BA0[0]; break;//char who left related
			case 0x14: lolo.dwResult = D_00E39BA0[1]; break;//char who left related
		}//end switch
	}

	return lolo.dwResult;
}

//write/push result
void C_00764B8C(int dwValue/*bp08*/) {
	struct {
		int local_2;
		unsigned char *local_1;
	}lolo;

	if(D_00E39ADC-- <= D_00E3A7F0)
		C_0074C9A0(0x3e);//<empty>:some error management?
	//-- save value to bank --
	lolo.local_1 = D_00E3A7E0[D_00E39ADC->wOpcode & 3];
	switch(D_00E39ADC->wOpcode & ~3) {
		case 0x114://bit to bank0~3
			lolo.local_1 += D_00E39ADC->dwValue >> 3;
			lolo.local_2 = D_00E39ADC->dwValue & 7;
			*lolo.local_1 &= ~(1 << lolo.local_2);
			*lolo.local_1 |= (dwValue != 0) << lolo.local_2;
		break;
		case 0x118://byte to bank0~3
			lolo.local_1[D_00E39ADC->dwValue] = dwValue;
		break;
		case 0x11c://short to bank0~3
			lolo.local_1 += D_00E39ADC->dwValue;
			if((unsigned)lolo.local_1 & 1)
				C_0074C9A0(0x3f);//<empty>:some error management?
			*(short *)lolo.local_1 = dwValue;
		break;
		default:
			C_0074C9A0(0x40);//<empty>:some error management?
	}//end switch
	//-- push value --
	D_00E39ADC->dwValue = dwValue;
	D_00E39ADC->wOpcode = 0x110;//push constant
	D_00E39ADC ++;
	//-- --
}

//opcode:0x100~0x1ff
void C_00764CCB(unsigned short wOpcode/*bp08*/) {
	if(wOpcode == 0x100) {
		D_00E39ADC = D_00E3A7F0;
		return ;
	}
	if(D_00E39ADC == 0 || D_00E3A7CC == 0)
		C_0074C9A0(0x3d);//<empty>:some error management?
	D_00E39ADC->wOpcode = wOpcode;
	D_00E39ADC->dwValue = D_00E3A810[D_00E3A7CC->wScriptPC ++];
	D_00E39ADC ++;
}

//opcode:0x200~0x2ff
int C_00764D59(unsigned short wOpcode/*bp08*/) {
	struct {
		struct t_wm_ScriptStackElement *local_3;
		int dwPauseScript;//local_2
		struct t_local_unknown_c0 *local_1;
	}lolo;

	lolo.dwPauseScript = 0;
	switch(wOpcode) {
		case 0x200://jump
			wOpcode = D_00E3A810[D_00E3A7CC->wScriptPC ++];
			D_00E3A7CC->wScriptPC = wOpcode;
		break;
		case 0x201://conditional jump
			wOpcode = D_00E3A810[D_00E3A7CC->wScriptPC ++];
			if(!C_0076488C())//pop param
				D_00E3A7CC->wScriptPC = wOpcode;
		break;
		case 0x203:
			if(D_00E3A7CC->bStackDepth > 0) {
				//-- restore script's context --
				D_00E3A7CC->bStackDepth --;
				lolo.local_3 = &(D_00E3A7CC->f_2c[D_00E3A7CC->bStackDepth]);
				D_00E3A7CC->wScriptPC = lolo.local_3->wScriptPC;
				D_00E3A7CC->bMoveCnt = lolo.local_3->bMoveCnt;
				D_00E3A7CC->bPriority = lolo.local_3->bPriority;
			} else {
				D_00E3A7CC->wScriptPC = 0;
				D_00E3A7CC->bPriority = 0;
				if(D_00E3A7DC) {//else 00764EE9
					if(D_00E3A7CC == &D_00E39A18) {//else 00764EE7
						for(lolo.local_1 = D_00E39A00; lolo.local_1; lolo.local_1 = lolo.local_1->pNext)
							C_00764014(lolo.local_1->bModelType, 1/*on_unload*/);//wm:start script(1)?
					}
				} else {
					if(D_00E3A7CC == &D_00E39A18) {
						C_007640BC(2);//wm:start script(2)?
					} else {
						C_00764014(D_00E3A7CC->bModelType, 2/*on_tick*/);//wm:start script(1)?
					}
				}
				lolo.dwPauseScript = 1;
			}
		break;
		default://0x204~
			D_00E3A7CC->f_52 = C_0076488C();//pop param
			if(D_00E3A7CC->f_52 < 0x40) {
				C_00764014(D_00E3A7CC->f_52, wOpcode - 0x204);//wm:start script(1)?
			} else {
				D_00E3A7CC->f_52 = D_00E39AD8->bModelType;
				C_00763DAA(wOpcode - 0x204);//start script(3)?
			}
			lolo.dwPauseScript = 1;
	}//end switch

	return lolo.dwPauseScript;
}

//opcode:0x300~
int C_00764F9C(unsigned short wOpcode/*bp08*/) {
	struct {
		struct VECTOR bp_34;
		struct SVECTOR bp_24;
		int dwModelType;//bp_1c
		int dwOp3;//bp_18
		struct t_local_unknown_c0 *bp_14;
		int dwOp2;//bp_10
		int dwOp1;//bp_0c
		short bp_08[4];
	}lolo;

	if(D_00E39AD8 == 0)
		C_0074C9A0(0x43);//<empty>:some error management?
	switch(wOpcode) {
		case 0x300:
			lolo.dwModelType = C_0076488C();//pop param
			if(!C_00762047(lolo.dwModelType)) {//wm:set current model
				C_007610B3();//wm:alloc new model
				C_0076197B(lolo.dwModelType);
				C_00764014(lolo.dwModelType, 0/*on_load*/);//wm:start script(1)?
			}
		break;
		case 0x343:
			C_007664C2(D_00E39AD8->bModelType);//wm:some stack.push?
			lolo.bp_14 = D_00E39AD8;
			C_007611FF(lolo.bp_14);
			lolo.dwModelType = C_0076488C();//pop param
			if(!C_00762047(lolo.dwModelType)) {//wm:set current model
				C_007610B3();//wm:alloc new model
				C_0076197B(lolo.dwModelType);
			}
			D_00E39AD8->f_08 = lolo.bp_14;
			D_00E39AD8->f_51 |= 2;
		break;
		case 0x302:
			C_007616CB();//wm:set some info(2)?
			C_0074D4C0(D_00E3A7D0->f_40);
		break;
		case 0x330:
			C_00762047(C_0076488C());//wm:set current model
		break;
		case 0x346:
			D_00E39AD8->bModelType = C_0076488C();//pop param
		break;
		case 0x307:
			C_0074D438(C_0076488C(), 3);//wm:set enable something?
		break;
		case 0x336://set speed(1)
			D_00E39AD8->bSpeed = C_0076488C();//pop param
			D_00E39AD8->f_51 |= 0x40;
		break;
		case 0x303://set speed(2)
			D_00E39AD8->bSpeed = C_0076488C();//pop param
			D_00E39AD8->f_51 &= ~0x40;
		break;
		case 0x304:
			D_00E39AD8->wDirection =
			D_00E39AD8->f_40 = (C_0076488C() << 4) & 0xfff;//pop param
			if(D_00E39AD8 == D_00E3A7D0)
				C_0074D4C0(D_00E39AD8->f_40);
		break;
		case 0x328://set direction
			D_00E39AD8->wDirection = (C_0076488C() << 4) & 0xfff;//pop param
		break;
		case 0x333:
			lolo.bp_14 = D_00E39AD8;
			lolo.dwOp1 = C_0076488C() << 4;//pop param
			if(D_00E39AD8 && C_00762047(C_0076488C()))//wm:set current model
				lolo.bp_14->f_40 = C_00753F2E(&(lolo.bp_14->sPos), &(D_00E39AD8->sPos)) + lolo.dwOp1;
			D_00E39AD8 = lolo.bp_14;
		break;
		case 0x344:
			lolo.dwOp1 = C_0076488C();//pop param
			if(lolo.dwOp1 >= 0 && lolo.dwOp1 < 3) {
				D_00E3A818[lolo.dwOp1] = D_00E39AD8->sPos;
				D_00E3A818[lolo.dwOp1].vy = 0;
			}
		break;
		case 0x345:
			lolo.dwOp1 = C_0076488C();//pop param
			if(lolo.dwOp1 >= 0 && lolo.dwOp1 < 3) {
				D_00E39AD8->wDirection =
				D_00E39AD8->f_40 = C_00753F2E(&(D_00E39AD8->sPos), &(D_00E3A818[lolo.dwOp1]));
			}
		break;
		case 0x308:
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			D_00E39AD8->sPos.vx &= 0x1fff;
			D_00E39AD8->sPos.vx |= lolo.dwOp1 << 13;
			D_00E39AD8->sPos.vz &= 0x1fff;
			D_00E39AD8->sPos.vz |= lolo.dwOp2 << 13;
			if(D_00E39AD8->sPos.vx != D_00E39AD8->sPrevPos.vx || D_00E39AD8->sPos.vz != D_00E39AD8->sPrevPos.vz)
				D_00E39AD8->f_51 |= 1;
		break;
		case 0x309:
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			D_00E39AD8->sPos.vx &= ~0x1fff;
			D_00E39AD8->sPos.vx |= lolo.dwOp1 & 0x1fff;
			D_00E39AD8->sPos.vz &= ~0x1fff;
			D_00E39AD8->sPos.vz |= lolo.dwOp2 & 0x1fff;
			if(D_00E39AD8->sPos.vx != D_00E39AD8->sPrevPos.vx || D_00E39AD8->sPos.vz != D_00E39AD8->sPrevPos.vz)
				D_00E39AD8->f_51 |= 1;
		break;
		case 0x347:
			lolo.bp_14 = D_00E39AD8;
			if(lolo.bp_14 && C_00762047(C_0076488C())) {//wm:set current model
				lolo.bp_14->sPos = D_00E39AD8->sPos;
				lolo.bp_14->sPrevPos = D_00E39AD8->sPrevPos;
				lolo.bp_14->f_51 |= 1;
			}
			D_00E39AD8 = lolo.bp_14;
		break;
		case 0x30e:
			if(C_0076488C())//pop param
				D_00E39AD8->f_51 &= ~0x20;//animation loop
			else
				D_00E39AD8->f_51 |= 0x20;//1 shot animation
			D_00E39AD8->f_5d = C_0076488C();//pop param
			D_00E39AD8->bAnimFrame = 0;
		break;
		case 0x353:
			C_0076247D(&D_00E39A08);
		break;
		case 0x30a://set vertical speed(1)?
			D_00E39AD8->f_5c = C_0076488C();//pop param
		break;
		case 0x30b://set Y(1)?
			D_00E39AD8->f_44 = C_0076488C();//pop param
		break;
		case 0x33a://set vertical speed(1)?
			D_00E39AD8->f_5f = C_0076488C();//pop param
			D_00E39AD8->f_51 |= 0x80;
		break;
		case 0x34f://set Y(2)?
			D_00E39AD8->sPos.vy = C_0076488C();//pop param
			D_00E39AD8->f_51 |= 0x80;
		break;
		case 0x30d:
			C_00762837();
		break;
		case 0x30c:
			if(C_007620B6())
				C_007667B2(1);//wm:manage ride/leave vehicle?
		break;
		case 0x31a:
			C_007615BA();
		break;
		case 0x338://unhide model
			D_00E39AD8->f_51 &= ~8;
		break;
		case 0x339://hide model
			D_00E39AD8->f_51 |= 8;
		break;
		case 0x348://fade in
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			C_00755B70(lolo.dwOp1, lolo.dwOp2);//wm:start fade in?
		break;
		case 0x33b://fade out
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			C_00755B97(lolo.dwOp1, lolo.dwOp2);//wm:start fade out?
		break;
		case 0x310:
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			C_00754EBC(lolo.dwOp1, lolo.dwOp2);//wm:start color effect zone?
		break;
		case 0x311:
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			C_00754EEF(lolo.dwOp1, lolo.dwOp2);//wm:set color effect zone chunk x,y?
		break;
		case 0x312:
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			C_00754F72(lolo.dwOp1, lolo.dwOp2);//wm:set color effect zone x,y?
		break;
		case 0x313:
			lolo.dwOp3 = C_0076488C();//pop param
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			C_00754FE2(lolo.dwOp1, lolo.dwOp2, lolo.dwOp3);//wm:set ambient light color?
		break;
		case 0x314:
			C_0075502C(C_0076488C());//wm:set color effect zone radius(2)?
			C_00755013(C_0076488C());//wm:set color effect zone radius(1)?
		break;
		case 0x315:
			lolo.dwOp3 = C_0076488C();//pop param
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			C_00755045(lolo.dwOp1, lolo.dwOp2, lolo.dwOp3);//wm:set color effect zone rgb(1)?
		break;
		case 0x316:
			lolo.dwOp3 = C_0076488C();//pop param
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			C_00755076(lolo.dwOp1, lolo.dwOp2, lolo.dwOp3);//wm:set color effect zone rgb(2)?
		break;
		case 0x31c:
			C_0074D2D7(C_0076488C());//wm:set some zoom/rotation mode?
		break;
		case 0x31e:
			C_0074D2A7(C_0076488C() << 4);
		break;
		case 0x32f:
			C_0074D2B9(C_0076488C() << 4);
		break;
		case 0x31f:
			C_0074DA26(C_0076488C());//wm:set some rotation param
		break;
		case 0x329:
			C_0074DA33(C_0076488C());//wm:set some zoom param(1)
		break;
		case 0x32a:
			C_0074DA40(C_0076488C());//wm:set some zoom param(2)
		break;
		case 0x352:
			C_0074CBB5(C_0076488C());//wm:set earthquake effect
		break;
		case 0x31d://play SFX
			C_0075E657(C_0076488C());//wm:play SFX?
		break;
		case 0x320:
			C_0075611B();//wm:reset Midgar Zolom?
		break;
		case 0x317:
			C_0075E5B3(1);//wm:set music related flag on/off
			C_0075E5C0(4);//wm:play song
			C_0074D7CD(C_0076488C());
		break;
		case 0x355:
			C_007671AD(C_0076488C());//wm:set countdown?
		break;
		case 0x32b:
			C_00767533(C_0076488C());//wm:set random inhibits encounter?
		break;
		case 0x318:
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			C_0074D74C(lolo.dwOp1 << 8 | lolo.dwOp2);
		break;
		case 0x33d:
			C_0074D731(C_0076488C());//wm:go to field?
		break;
		case 0x319:
			C_0074D8EF(C_0076488C());//wm:set view mod/map|radar state
		break;
		case 0x305://set move frame counter?
			D_00E3A7CC->bMoveCnt = C_0076488C();//pop param
		break;
		case 0x331://exit vehicle
			C_0076667C();//wm:"X" button short trigger?
		break;
		case 0x33c:
			C_0074D6BB();//wm:go to surface
		break;
		case 0x335:
			C_00761313();
		break;
		case 0x354://enable/disable script?
			if(C_0076488C())//pop param
				D_00E39AD8->f_51 &= ~0x10;
			else
				D_00E39AD8->f_51 |= 0x10;
		break;
		case 0x332:
			D_00E39AD8->f_51 |= 0x10;
			C_00758A32(3);
		break;
		case 0x337:
			C_00766B5D(C_0076488C());
		break;
		case 0x34b:
			lolo.dwOp1 = C_0076488C();//pop param
			C_0074DB45(lolo.dwOp1);//wm:set chocobo tint?
			C_0075E4D6(WM_MODELID_19, lolo.dwOp1);//wm:apply tint to model?
		break;
		case 0x34c:
			C_0075E4D6(WM_MODELID_13, C_0076488C() + 5);//wm:apply tint to model?
		break;
		case 0x321:
			if(D_00E39AD8) {
				C_00754EBC(C_0076488C(), -1);//wm:start color effect zone?
				C_00762763(&lolo.bp_34);//wm:get model pos(1)?
				D_00E39AD8->wDirection =
				D_00E39AD8->f_40 =
				D_00E39AD8->f_3c = C_0075545F(&lolo.bp_34);
				D_00E39AD8->f_3e = 0;
			}
		break;
		case 0x349:
			C_007537A1(C_0076488C());//wm:set world map state?
		break;
		case 0x34a:
			C_0075BBB3(D_00E39AD8, C_0076488C());//2danimfx:do anim
		break;
		case 0x34d:
			lolo.dwOp3 = C_0076488C();//pop param
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			if(D_00E39AD8)
				C_0075BFE5(lolo.dwOp1, D_00E39AD8->bModelType, lolo.dwOp2, lolo.dwOp3);//2danimfx:start
		break;
		case 0x34e:
			C_0075C01B(C_0076488C());//2danimfx:stop
		break;
		case 0x350:
			C_00754E10(C_0076488C());//wm:set render meteor
		break;
		case 0x33e://play song
			C_0075E5B3(1);//wm:set music related flag on/off
			lolo.dwOp1 = C_0076488C();//pop param
			C_0075E5C0(lolo.dwOp1);//wm:play song
			if(lolo.dwOp1)
				C_0075E5B3(0);//wm:set music related flag on/off
		break;
		case 0x351://set music volume
			C_0075E697(C_0076488C());//wm:set music volume
		break;
		case 0x324://start dialog
			lolo.bp_08[3] = C_0076488C();//pop param
			lolo.bp_08[2] = C_0076488C();//pop param
			lolo.bp_08[1] = C_0076488C();//pop param
			lolo.bp_08[0] = C_0076488C();//pop param
			C_0075F038(lolo.bp_08);
		break;
		case 0x32c://set dialog attributes
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			C_0075F06C(lolo.dwOp1, lolo.dwOp2);
		break;
		case 0x325://set dialog text
			C_0075EE86(C_0076488C());
		break;
		case 0x326:
			lolo.dwOp3 = C_0076488C();//pop param
			lolo.dwOp2 = C_0076488C();//pop param
			lolo.dwOp1 = C_0076488C();//pop param
			C_0075EEBB(lolo.dwOp1, lolo.dwOp2, lolo.dwOp3);
		break;
		case 0x327:
			if(C_0075F00E() < 0 && D_00E3A7DC == 0) {
				D_00E39AD8->wScriptPC --;

				return 1;
			}
		break;
		case 0x32d:
			if(D_00E3A7DC == 0) {
				lolo.dwOp1 = C_0075EF13();
				D_00E39AD8->wScriptPC -= lolo.dwOp1;

				return lolo.dwOp1;
			}
		break;
		case 0x32e:
			if(D_00E3A7DC == 0) {
				lolo.dwOp1 = C_0075EF01();
				D_00E39AD8->wScriptPC -= lolo.dwOp1;

				return lolo.dwOp1;
			}
		break;
		case 0x334:
			if(D_00E3A7DC == 0) {
				lolo.bp_14 = D_00E39AD8;
				C_00762047(D_00E3A7CC->f_52);//wm:set current model
				lolo.dwOp1 = D_00E39AD8->bPriority > 0;
				lolo.bp_14->wScriptPC -= lolo.dwOp1;
				D_00E39AD8 = lolo.bp_14;

				return lolo.dwOp1;
			}
		break;
		case 0x33f:
			C_0075334D();//wm:set chocobo farm related flag?
		break;
		case 0x341:
			if(D_00E3A7DC == 0) {
				lolo.dwOp1 = !C_00758A3F();
				D_00E3A7CC->wScriptPC -= lolo.dwOp1;

				return lolo.dwOp1;
			}
		break;
		case 0x340:
			C_007570E8(C_0076488C());
		break;
		case 0x342:
			if(D_00E3A7DC == 0) {
				lolo.dwOp1 = C_00758A6C();
				D_00E3A7CC->wScriptPC -= lolo.dwOp1;

				return lolo.dwOp1;
			}
		break;
		case 0x306://move(direction+speed)
			//-- --
			if(D_00E39BC0) {
				D_00E3A7CC->wScriptPC --;

				return 1;
			}
			D_00E3A7CC->bMoveCnt --;
			if(D_00E3A7CC->bMoveCnt)
				D_00E3A7CC->wScriptPC --;
			else
				D_00E39BC0 = 1;
			//-- do the move --
			lolo.bp_24.vx =
			lolo.bp_24.vy = 0;
			lolo.bp_24.vz = D_00E39AD8->bSpeed << (((D_00E39AD8->f_51 & 0x40)?1:0) << 2);
			C_00753D00(&lolo.bp_24, D_00E39AD8->wDirection);//wm:SVECTOR z rotation?
			C_00762E87(lolo.bp_24.vx, lolo.bp_24.vz);
			D_00E39AD8->f_44 -= D_00E39AD8->f_5c;
			D_00E39AD8->sPos.vy += D_00E39AD8->f_5f;
			//-- --

			return D_00E3A7CC->bMoveCnt > 0;
	}//end switch
	
	return 0;
}

//wm:refresh script stuff?
void C_00765F61() {
	struct {
		int local_2;
		int local_1;
	}lolo;

	if(D_00E3A7DC == 0 && !(D_00E3A7D0->f_51 & 8)) {//else 0076603B
		if(C_00761769(BIT(WM_MODELID_13)))//wm:is current model in list(1)?
			lolo.local_2 = (D_00E3A7D0->sPos.vy - D_00E3A7D0->f_42) < 500;
		else
			lolo.local_2 = !(D_00E3A7D0->f_51 & 0x80);
		if(lolo.local_2) {//else 0076603B
			lolo.local_1 = C_007621C0();//wm:current terrains's script?
			if(lolo.local_1 >= 3) {//else 00766032
				if(D_00E3A85C != lolo.local_1) {//else 00766014
					D_00E3A85C = lolo.local_1;
					C_00764142(lolo.local_1 - 3, 0);//start script(3)?
				}
				if(lolo.local_1 == 7 && !C_00761769(BIT(WM_MODELID_13)))//wm:is current model in list(1)?
					C_007628B5();
			} else {
				D_00E3A85C = 0;
			}
		}
	}
}

int C_0076603F() {
	struct {
		int local_2;
		struct t_local_unknown_c0 *local_1;
	}lolo;

	lolo.local_2 = 0;
	lolo.local_2 |= D_00E39A18.wScriptPC?1:0;
	for(
		lolo.local_1 = D_00E39A00;
		lolo.local_1 && lolo.local_2 == 0;
		lolo.local_1 = lolo.local_1->pNext
	) {
		lolo.local_2 |= lolo.local_1->wScriptPC?1:0;
	}//end for

	return lolo.local_2;
}

void C_007660DB(struct t_local_unknown_c0 *);//save object coordinates?

void C_0076609E() {
	struct t_local_unknown_c0 *local_1;

	for(local_1 = D_00E39A00; local_1; local_1 = local_1->pNext) {
		if(!(local_1->f_51 & 8))
			C_007660DB(local_1);//save object coordinates?
	}//end for
}

//modelid->coordinates save slot
unsigned char D_0096DE80[32] = {
	0x00,
	0x00,
	0x00,
	0x03,
	0x01,
	0x02,
	0x03,
	0x09,
	0x09,
	0x09,
	0x05,
	0x05,
	0x09,
	0x04,
	0x09,
	0x09,
	0x09,
	0x09,
	0x09,
	0x02,
	0x09,
	0x09,
	0x09,
	0x09,
	0x09,
	0x09,
	0x09,
	0x09,
	0x09,
	0x05,
	0x09,
	0x09
};

//save object coordinates?
void C_007660DB(struct t_local_unknown_c0 *bp08) {
	struct t_wm_local_8_rrr *local_1;

	if(D_0096DE80[bp08->bModelType] < 6) {
		local_1 = &(D_00E3A7D8[D_0096DE80[bp08->bModelType]]);
		local_1->f_00 =
			(bp08->sPrevPos.vx & 0x0007ffff) |
			((bp08->bModelType << 19) & 0x00f80000) |
			((bp08->f_40 << 20) & 0xff000000)
		;
		local_1->f_04 =
			(bp08->sPrevPos.vz & 0x0003ffff) |
			((bp08->sPrevPos.vy << 18) & 0xfffc0000)
		;
	}
}

//load object coordinates?
void C_0076616A(struct t_local_unknown_c0 *bp08) {
	struct t_wm_local_8_rrr *local_1;

	for(
		local_1 = &(D_00E3A7D8[0]);
		local_1 < &(D_00E3A7D8[6]) && ((local_1->f_00 >> 19) & 0x1f) != bp08->bModelType;
		local_1 ++
	);
	//strange:bp08 non-nullity is tested here, but it is already
	// dereferenced in the above loop
	if(local_1 < &(D_00E3A7D8[6]) && bp08) {
		bp08->sPos.vx =
		bp08->sPrevPos.vx = local_1->f_00 & 0x7ffff;
		bp08->sPos.vy =
		bp08->sPrevPos.vy = local_1->f_04 >> 18;
		bp08->sPos.vz =
		bp08->sPrevPos.vz = local_1->f_04 & 0x3ffff;
		bp08->wDirection =
		bp08->f_3c =
		bp08->f_40 = (local_1->f_00 >> 20) & 0xff0;
		bp08->f_3e = 0;
	}
}

//wm:update characters list for script?
void C_00766255(int dwCharMask_old/*bp08*/, int dwCharMask_new/*bp0c*/) {
	struct {
		unsigned local_4;
		int local_3;
		unsigned dwDiff;//local_2
		int local_1;
	}lolo;

	D_00E39BA8[0] =
	D_00E39BA8[1] = 0;
	D_00E39BA0[0] =
	D_00E39BA0[1] = 0;

	lolo.local_1 = 0x40;//patch for cait sith?
	//-- charas who left --
	lolo.dwDiff = dwCharMask_old & ~dwCharMask_new;
	lolo.local_4 = 0;
	if(lolo.dwDiff & lolo.local_1) {
		D_00E39BA0[lolo.local_4 ++] = 0x26;
		lolo.dwDiff &= ~lolo.local_1;
	}
	for(lolo.local_3 = 0; lolo.local_4 < 2 && lolo.dwDiff; lolo.local_3 ++, lolo.dwDiff >>= 1) {
		if(lolo.dwDiff & 1)
			D_00E39BA0[lolo.local_4 ++] = lolo.local_3 + 0x20;
	}//end for
	//-- new charas --
	lolo.dwDiff = ~dwCharMask_old & dwCharMask_new;
	lolo.local_4 = 0;
	if(lolo.dwDiff & lolo.local_1) {
		D_00E39BA8[lolo.local_4 ++] = 0x26;
		lolo.dwDiff &= ~lolo.local_1;
	}
	for(lolo.local_3 = 0; lolo.local_4 < 2 && lolo.dwDiff; lolo.local_3 ++, lolo.dwDiff >>= 1) {
		if(lolo.dwDiff & 1)
			D_00E39BA8[lolo.local_4 ++] = lolo.local_3 + 0x20;
	}//end for
	//-- --
}

void C_007663A8(struct VECTOR *bp08) {
	D_00E39A08 = *bp08;
}
