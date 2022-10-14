/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//WORLD MAP -- 

#include "ff7.h"
#include "wm_data.h"
////////////////////////////////////////
struct t_wm_unused_stuff_24 {//size 0x24
	char __00[0x24];
};

struct t_wm_unused_stuff {
	/*00*/char __00[0x10];
	/*10*/struct t_wm_unused_stuff_24 *f_10;
	/*14*/
		//...?
};
////////////////////////////////////////
int D_00E3A8A8;
int D_00E3A8AC;
struct t_wm_unused_stuff *D_00E3A8B0;
int D_00E3A8B4;
int D_00E3A8B8;
int D_00E3A8BC;
char D_00E3A8C0[WM_MAX_MODELID];
int D_00E3B0F0;
int D_00E3B0F4;
char D_00E3B0F8[WM_MAX_MODELID];
int D_00E3B124;//"highwind has reactor" flag?
int D_00E3B128;
int D_00E3B12C;
////////////////////////////////////////
void C_007688E0() {
	int i;

	for(i = 0; i < WM_MAX_MODELID; i ++) {
		D_00E3B0F8[i] = -1;
		D_00E3A8C0[i] = 0;
	}//end for
	D_00E3A8B0 = 0;
	D_00E3A8B8 = 0;
	D_00E3B128 =
	D_00E3A8A8 =
	D_00E3B0F4 = 0;
	D_00E3A8BC = 0;

	D_00E3A8B4 =
	D_00E3A8AC =
	D_00E3B12C = 
	D_00E3B0F0 = 0;

	D_00E3B124 = 0;
}

void C_0076898A() {
	int i;

	//-- unused? --
	if(D_00E3B0F4) {
		D_00E3B0F4 = 0;
		D_00E3B0F0 = 3;
		for(i = 0; i < WM_MAX_MODELID; i ++)
			D_00E3A8C0[i] = 0;
		for(i = 0x20; i < WM_MAX_MODELID; i ++)
			D_00E3B0F8[i] = -1;
	}
	//-- --
}

void C_007689F7() {
	//-- unused? --
	if(D_00E3B0F4 && C_00761176() == 0)
		C_0076898A();
	//-- --
	if(D_00E3B0F0) {
		D_00E3B0F0 --;
		if(D_00E3B0F0 == 0)
			C_00750784();
	}
}

void C_00768B36(short);

struct t_wm_b8 *C_00768A37(short wModelId/*bp08*/) {
	struct {
		struct t_wm_unused_stuff_24 *local_2_unused;
		int local_1;
	}lolo;

	if(wModelId < 0 || wModelId >= WM_MAX_MODELID)
		wModelId = WM_MODELID_00;
	if(D_00E3B0F8[wModelId] < 0) {//else 00768A8B
		if(wModelId < 3) {
			C_00768B36(wModelId);
		} else if(wModelId  < 0x20) {
			return 0;
		}
	}
	if(wModelId < 3)
		return D_00E3B128?D_00E2C430:0;
	if(wModelId < 0x20)//else 00768AE4
		return /*lolo.local_3*/D_00E3A8A8?&(D_00E2C808[D_00E3B0F8[wModelId] - 1]):0;
	//-- unused? --
	if(D_00E3B0F4) {
		lolo.local_1 = D_00E3B0F8[wModelId] - 0xd;
		if(D_00E3A8C0[wModelId] == 0) {
			lolo.local_2_unused = &(D_00E3A8B0->f_10[lolo.local_1]);
			D_00E3A8C0[wModelId] = 1;
		}

		return 0;
	}
	//-- --

	return 0;
}

void C_00768B82(void);

void C_00768B36(short wModelId/*bp08*/) {
	if(D_00E3A8AC == 0 && C_007538C9(2)) {
		D_00E3B128 = 0;
		C_00759A65(wModelId);//wmfile:load 3d models[chara]?
		D_00E3A8AC = 1;
	}
	D_00E3B12C = wModelId;
	C_00768B82();
}

void C_00768BA9(void);

void C_00768B82() {
	if(D_00E3A8AC) {
		D_00E3A8AC = 0;
		C_0075395E(2);
		C_00768BA9();
	}
}

void C_00768BA9() {
	D_00E3B128 = 1;
	D_00E3B0F8[0] =
	D_00E3B0F8[1] =
	D_00E3B0F8[2] = -1;
	D_00E3B0F8[D_00E3B12C] = 0;
}

void C_00768BF5(void);

void C_00768BE2(short bp08) {
	D_00E3A8B4 = bp08;
	C_00768BF5();
}

char D_0096DF10[][0x20] = {
	{ 0, 0, 0,-1, 1, 2, 3, 9,-1,-1,-1,-1, 5,-1, 8, 6, 7,-1,-1,-1,-1,-1,-1,-1, 4,10,-1,-1,-1,-1,-1,-1},
	{ 0, 0, 0, 3, 1,-1,-1, 9,-1,10,12,-1, 5, 4, 8, 6, 7,-1,-1, 2,-1,-1,-1,-1,11,13,-1,-1,-1,-1,-1,-1},
	{ 0, 0, 0, 3, 1,-1,-1,-1,-1,10,12,-1, 5, 4, 8, 6, 7,-1,-1, 2, 9,-1,-1,-1,11,13,-1,-1,-1,-1,-1,-1},
	{ 0, 0, 0, 3, 1,-1,-1, 9,-1,10,12,-1, 5, 4, 8, 6, 7,-1,-1, 2,-1,-1,-1,-1,11,13,-1,-1,-1,-1,-1,-1},
	{ 0, 0, 0, 3, 1,-1,-1,-1,-1,10,12,-1, 5, 4, 8, 6, 7,-1,-1, 2, 9,-1,-1,-1,11,13,-1,-1,-1,-1,-1,-1},
	{ 0, 0, 0, 3, 1,-1,-1,-1,-1,10,-1,12, 5, 4, 8, 6, 7,-1,-1, 2, 9,-1,-1,-1,11,13,-1,-1,-1,-1,-1,-1},
	{ 0, 0, 0, 3, 1,-1,-1,-1,-1,10,-1,12, 5, 4, 8, 6, 7,-1,-1, 2, 9,-1,-1,-1,11,13,-1,-1,-1,-1,-1,-1},
	{ 0, 0, 0, 3, 1,-1,-1,-1,-1,10,-1,-1, 5, 4, 8, 6, 7,-1,-1, 2, 9,-1,-1,-1,-1,12,-1,-1,-1,11,-1,-1},
	{ 0, 0, 0, 3, 1,-1,-1,-1,-1,10,-1,-1, 5, 4, 8, 6, 7,-1,-1, 2, 9,-1,-1,-1,-1,12,-1,-1,-1,11,-1,-1},
	{ 0, 0, 0,-1,-1,-1,-1, 2, 1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{ 0, 0, 0,-1,-1,-1,-1, 2, 1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{ 0, 0, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 1,-1,-1,-1, 2, 3,-1,-1,-1,-1,-1,-1,-1, 4, 5, 6,-1, 7,-1},
	{ 0, 0, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 1, 2, 3,-1,-1,-1,-1,-1,-1,-1,-1}
};

void C_00768BF5() {
	int i;

	for(i = 3; i < 0x20; i ++)
		D_00E3B0F8[i] = D_0096DF10[D_00E3A8B4][i];
	D_00E3A8A8 = 1;
}

void C_00768C3D() {
	D_00E3A8AC = 0;
}

//wm:set "highwind has reactor"?
void C_00768C4C(int bp08) {
	D_00E3B124 = bp08;
}

//wm:highwind has reactor?
int C_00768C59() {
	return D_00E3B124;
}
