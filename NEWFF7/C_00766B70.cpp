/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//WORLD MAP -- 

#include "ff7.h"
#include "wm_data.h"
#include "menu_data.h"
#include "loadmenu.h"
////////////////////////////////////////
int D_00E3A87C;
int D_00E3A880;
int D_00E3A884;
int D_00E3A888;//encounter probability counter
int D_00E3A88C;
int D_00E3A890;
int D_00E3A894;
////////////////////////////////////////
void __00766B70() {
	int i;

	for(i = 0; i < 0x400; i ++)
		D_00DBFD38.f_0ba4[i] = 0;
}

int C_00766B9F() {
	return /*local_1*/(D_00DC08DC < 1000)?0:
		/*local_2*/(D_00DC08DC < 1580)?
			1 + ((D_00DC0956 & 1) | ((D_00DC08DC >= 1620) << 1))://1~4
			5 + ((D_00DC08DC >= 1620) | (((D_00DC0C62 & 0x10)?1:0) << 1))//5~8
	;
}

//wm:progress between 1000 and 1200?
int C_00766C33() {
	return (D_00DC08DC >= 1000 && D_00DC08DC < 1200);
}

int C_00766C6E() {
	return D_00DC0CDA;
}

void C_007671CB(void);
void C_00767218(unsigned char *, unsigned char *, int);

void C_00766C7A(int *bp08, int *forField/*bp0c*/, int bp10) {
	struct {
		struct VECTOR local_7;
		int i;//local_3
		int local_2;
		int dwChecksum;//local_1
	}lolo;

	//-- some checksum? --
	lolo.dwChecksum = 0;
	for(lolo.i = 0x380; lolo.i < 0x400; lolo.i ++)
		lolo.dwChecksum += D_00DBFD38.f_0ba4[lolo.i];
	if(lolo.dwChecksum & 0xff)
		C_0074C9A0(2);//<empty>:some error management?
	//-- --
	D_00E3A884 = /*lolo.local_8*/bp08?*bp08:0;
	D_00E3A894 = /*lolo.local_9*/forField?*forField:0;
	lolo.local_2 = (D_00DC0CD4 >> 0xc) & 3;
	C_0074D3D1((lolo.local_2 >= 0 && lolo.local_2 < 3)?lolo.local_2:0);//wm:set view mode?
	if((D_00E3A884 == 0 && D_00E3A894 == 0) || D_00E3A884 == 1 || D_00E3A884 == 2)
		C_0074D2B9(D_00DC0CD4 & 0xfff);
	C_0076831F((D_00DC0CD4 >> 0xe) & 3);//wm:set map/radar state
	C_00767218(D_00DC09E5, D_00DBFD38.f_04f8, 0);
	C_00753A01(D_00DBFD38.dwPlayTime);//wm:randomize
	C_00758D17(D_00DC0CD0);//wm:set bridges info word?
	C_00750466(D_00DC0C92);//wm:get bridge move counter?
	C_00760FB0(&D_00DC0C94);
	if(bp10) {
		D_00DC08FA &= ~0x300;
		//goto 00766EC2
	} else {
		C_00758AC4(D_00DC0CD7);
		if(D_00E3A884 == 1) {//else 00766E9A
			for(lolo.i = 0; lolo.i < 3; lolo.i ++) {
				if(D_00DC0CC4[lolo.i]) {
					C_007610B3();//wm:alloc new model
					C_0076197B(WM_MODELID_21 + lolo.i);
					lolo.local_7.f_00 = D_00DC0CC4[lolo.i] & 0xffff;
					lolo.local_7.f_04 = 0;
					lolo.local_7.f_08 = (D_00DC0CC4[lolo.i] >> 0x10) & 0xffff;
					C_007621EF(&lolo.local_7);
				}
			}//end for
		} else {
			for(lolo.i = 0; lolo.i < 3; lolo.i ++)
				D_00DC0CC4[lolo.i] = 0;
		}
	}
	C_007671CB();
}

void C_00766ECB() {
	struct {
		struct VECTOR local_6;
		int i;//local_2
		int dwChecksum;//local_1
	}lolo;

	if(C_0074D28E() == 0 && C_0074D330() != 3)
		C_0074D2B9(0);
	D_00DC0CD4 =
		(C_0074D298() & 0x0fff) |
		((C_0074D28E() << 0xc) & 0x3000) |//wm:get view mode?
		((C_00768343() << 0xe) & 0xc000)//wm:get map/radar state
	;
	D_00DC0CD9 = C_00761735();//wm:current transportation mode?
	if(D_00DC0CD9 == WM_MODELID_03 && C_0076192A(C_00766526()))
		D_00DC0CD9 = WM_MAX_MODELID;
	C_0076609E();
	D_00DC0CDA = C_0074D330();//wm:get current map id?
	D_00DC0CD0 = C_00758D76();//wm:get bridges info word?
	D_00DC0C92 = C_0075045C();//wm:get bridge move counter?
	if(D_00DC0CDA == 3) {//else 00766FF2
		D_00DC0CD7 = C_00758D0B();
		for(lolo.i = 0; lolo.i < 3; lolo.i ++) {
			if(C_00762047(WM_MODELID_21 + lolo.i)) {//wm:set current model
				C_00762763(&lolo.local_6);
				D_00DC0CC4[lolo.i] = (lolo.local_6.f_00 & 0xffff) | (lolo.local_6.f_08 << 0x10);
			} else {
				D_00DC0CC4[lolo.i] = 0;
			}
		}
	}
	//-- set some checksum? --
	lolo.dwChecksum = 0;
	for(lolo.i = 0x380; lolo.i < 0x3ff; lolo.i ++)
		lolo.dwChecksum += D_00DBFD38.f_0ba4[lolo.i];
	D_00DC0CDB = -lolo.dwChecksum;
	//-- --
}

void C_00767039(int *bp08, int *pForField/*bp0c*/, int *pForBattle/*bp10*/) {
	if(bp08)//0:field,1:battle,2:[unused]
		*bp08 = D_00E3A884;
	if(pForField)//for field?
		*pForField = D_00E3A894;
	if(pForBattle)//for battle?
		*pForBattle = D_00E3A88C | ((D_00E3A880 != 0) << 29);
	D_00DC08FA |= 0x300;
	C_00766ECB();
}

void C_00767097() {
	if(D_00DC0CD9 >= WM_MODELID_03) {
		if(D_00DC0CD9 < WM_MAX_MODELID) {
			C_00762047(D_00DC0CD9);//wm:set current model
			C_00766574();//wm:"O" button near a vehicle?
		} else {
			C_00762047(WM_MODELID_19);//wm:set current model
			C_00766574();//wm:"O" button near a vehicle?
			C_00762047(WM_MODELID_03);//wm:set current model
			C_00766574();//wm:"O" button near a vehicle?
		}
		C_0074D4C0(C_00761EB6());
	}
}

void C_007670F9(int bp08) {
	struct t_wm_local_0c_xxx *local_1;

	D_00E3A884 = 0;//to field
	D_00E3A894 = bp08;
	local_1 = &(D_00E37D30[(((bp08 >> 8) * 2 - 2) & 0x1fe) | (bp08 & 1)]);
	D_00CC0D88.wEventParam = local_1->f_06;
	D_00CC0D88.f_04 = local_1->f_00;
	D_00CC0D88.f_06 = local_1->f_02;
	D_00CC0D88.f_22 = local_1->f_04;
	D_00CC0D88.f_24 = local_1->f_08;
}

void C_0076717C(int dwEncounterId/*bp08*/) {
	if(dwEncounterId & BIT(30))
		C_007670F9(0x2100);
	D_00E3A884 = 1;//to battle
	D_00E3A88C = dwEncounterId;
}

//wm:set countdown?
void C_007671AD(int bp08) {
	D_00DBFD38.dwTimer = bp08;
	D_00E3A880 = 1;
	D_00DC093B = 1;
}

void C_007671CB() {
	D_00E3A880 = 0;
	D_00DC093B = 0;
}

void C_007671E1() {
	D_00E3A884 = 2;//???
	D_00E3A894 = 0;
	D_00E3A88C = 0;
}

int C_00767204() {
	return D_00E3A884;
}

int C_0076720E() {
	return D_00E3A894;
}

void C_00767218(unsigned char *bp08, unsigned char*bp0c, int bp10) {
	struct {
		int local_5;
		int local_4;
		unsigned local_3;
		unsigned local_2;
		unsigned local_1;
	}lolo;

	lolo.local_5 = (1 << bp08[0]) | (1 << bp08[1]) | (1 << bp08[2]);
	lolo.local_4 = (1 << bp0c[0]) | (1 << bp0c[1]) | (1 << bp0c[2]);
	if(bp10)
		C_00766255(lolo.local_5, lolo.local_4);
	lolo.local_1 = lolo.local_5 & ~lolo.local_4;
	for(lolo.local_2 = 0; lolo.local_2 < 3; lolo.local_2 ++) {
		if(lolo.local_1 & (1 << bp08[lolo.local_2]))
			bp08[lolo.local_2] = 0xff;
	}//end for
	for(lolo.local_1 = ~lolo.local_5 & lolo.local_4, lolo.local_2 = lolo.local_3 = 0; lolo.local_1; lolo.local_2 ++, lolo.local_1 >>= 1) {
		if(lolo.local_1 & 1) {
			while(lolo.local_3 < 3 && bp08[lolo.local_3] != 0xff)
				lolo.local_3 ++;
			if(lolo.local_3 >= 3)
				break;
			bp08[lolo.local_3] = lolo.local_2;
			lolo.local_3 ++;
		}
	}//end for
}

//wm:player's model id[cloud|tifa|cid]
int C_0076736E() {
	return
		/*local_3*/(D_00DC09E5[0] == 0 || D_00DC09E5[1] == 0 || D_00DC09E5[2] == 0)?0:
		/*local_2*/(D_00DC09E5[0] == 2 || D_00DC09E5[1] == 2 || D_00DC09E5[2] == 2)?1:
		/*local_1*/(D_00DC09E5[0] == 8 || D_00DC09E5[1] == 8 || D_00DC09E5[2] == 8)?2:
		0
	;
}

void C_0076741C() {
	C_00767218(D_00DC09E5, D_00DBFD38.f_04f8, C_0074D330() != 2);
	if(C_0074D330() != 2)
		(C_00766560()?C_00766553:C_00762102)(C_0076736E());
}

//wm:save location name?
void C_00767473(int bp08) {
	struct {
		int local_2;
		unsigned char *local_1;
	}lolo;

	lolo.local_1 = C_0074D915(bp08);//wm:get string from "mes"
	lolo.local_2 = 0x368;
	while(lolo.local_2 < 0x380 && (D_00DBFD38.f_0ba4[lolo.local_2 ++] = *(lolo.local_1 ++)) != 0xff);
}

void C_007674D2(int bp08) {
	D_00DC0CD8 = bp08;
}

int C_007674DF() {
	return D_00DC0CD8;
}

int C_007674EB() {
	return (D_00DB958A & 8)?1:0;
}

void C_00767515(void);

void C_00767501() {
	D_00E3A888 = 0;
	C_00767515();
}

void C_00767515() {
	D_00E3A87C = -140;
}

void C_00767524() {
	D_00E3A87C = -30;
}

void C_00767533(int bp08) {
	D_00E3A890 = bp08;
}

int C_00767641(void);

void C_00767540() {
	struct {
		struct VECTOR local_11;
		int local_7;
		int dwEncounterId;//local_6
		int dwMapId;//local_5
		struct VECTOR local_4;
	}lolo;

	lolo.dwMapId = C_0074D330();//wm:get current map id?
	if(D_00CC0D88.f_3b == 0 && lolo.dwMapId != 2 && C_00758A6C() == 0 && C_0074D4B6()) {
		lolo.local_7 = C_007621C0();
		C_00762798(&lolo.local_4);
		C_00762802(&lolo.local_11);
		if(C_00761769(0x47) && D_00E3A890) {//wm:is current model in list(1)?//else 00767633
			if(
				lolo.local_7 == 0 &&
				(lolo.local_4.f_00 != lolo.local_11.f_00 || lolo.local_4.f_08 != lolo.local_11.f_08)
			) {//else 00767631
				if(D_00E3A87C == 8 || D_00E3A87C == 0x10)
					C_006CC4A8();//"Cat's Bell" effect
				//-- --
				if(D_00E3A87C ++ >= 0x10) {//else 00767631
					D_00E3A87C = 0;
					lolo.dwEncounterId = C_00767641();//check encounter
					if(lolo.dwEncounterId != -1) {//else 00767631
						C_00762465(&lolo.local_11);
						C_0074D7CD(lolo.dwEncounterId);
					}
				}
				//-- --
			}
		} else {
			D_00E3A87C = 0;
		}
	}
}

char D_0096DEA0[][4] = {
	{0x00,0x09,0x00,0x11},
	{0x00,0x00,0x00,0x11},
	{0x00,0x09,0x01,0x11},
	{0x00,0x14,0x00,0x11},
	{0x00,0x09,0x08,0x11},
	{0x00,0x00,0x19,0x11},
	{0x00,0x09,0x13,0x11},
	{0x00,0x00,0x01,0x11},
	{0x00,0x00,0x01,0x11},
	{0x00,0x09,0x0E,0x11},
	{0x00,0x09,0x19,0x11},
	{0x00,0x0A,0x09,0x11},
	{0x00,0x09,0x19,0x11},
	{0x00,0x00,0x08,0x0B},
	{0x00,0x00,0x08,0x00},
	{0x00,0x00,0x01,0x00}
};

unsigned char D_0096DEE0[] = {0x00,0x00,0x20,0x00,0x00,0x40,0x00,0x40,0xFF,0x00,0x80,0x00,0x80,0x00,0x00,0x80};

int C_00767C55(void);
int C_00767C77(void);
int C_00767C9E(void);
int C_00767CB5(void);
int C_00767CC1(void);
int C_00767CD0(void);
int C_00767CDA(void);
int C_00767D2C(void);

//check encounter
int C_00767641() {
	struct {
		//local_15 and above for compiler
		int local_14;
		int local_13;
		int local_12;
		int dwLVL;//local_11
		int dwEncounterId;//local_10
		int local_9;
		int dwTerrain;//local_8
		int dwLocation;//local_7
		int local_6;
		int local_5;
		int local_4;
		int local_3;
		int local_2;
		struct t_wm_local_20_xxx *local_1;
	}lolo;

	lolo.local_2 = 0;
	lolo.local_6 = 0;
	lolo.local_9 = 0;
	lolo.dwEncounterId = -1;
	lolo.dwTerrain = C_00762136();//wm:get current terrain?
	lolo.dwLocation = C_00762162();//wm:get location id?
	if(C_00767C55()) {//else 00767C0B
		if(lolo.dwLocation < 0)
			lolo.dwLocation = 0;
		else if(lolo.dwLocation > 0xf)
			lolo.dwLocation = 0xf;

		if(lolo.dwTerrain == 0x10)
			lolo.dwTerrain = 0;
		if(lolo.dwTerrain == 0x18)
			lolo.dwTerrain = 8;

		if(D_0096DEA0[lolo.dwLocation][0] == lolo.dwTerrain)
			lolo.dwTerrain = 0;
		else if(D_0096DEA0[lolo.dwLocation][1] == lolo.dwTerrain)
			lolo.dwTerrain = 1;
		else if(D_0096DEA0[lolo.dwLocation][2] == lolo.dwTerrain)
			lolo.dwTerrain = 2;
		else if(D_0096DEA0[lolo.dwLocation][3] == lolo.dwTerrain)
			lolo.dwTerrain = 3;
		else
			lolo.dwTerrain = 0;

		lolo.local_1 = &(D_00DE6B78.f_0a0[lolo.dwLocation][lolo.dwTerrain]);
		lolo.local_4 = (lolo.local_1->f_00 >> 8) & 0xff;
		D_00E3A888 += /*lolo.local_15*/lolo.local_4?(C_00767C55() << 0xa) / lolo.local_4:0x7fff;
		if(
			C_00753BE8() < (D_00E3A888 >> 8) &&//wm:random?
			(lolo.local_1->f_00 & 1)
		) {//else 00767C0B
			if(
				C_00753BE8() < D_0096DEE0[lolo.dwLocation] &&//wm:random?
				(C_00762136() == 1 || C_00762136() == 0x19) &&//wm:get current terrain?
				C_00767CC1()
			) {//else 00767853
				lolo.dwLVL = C_006CB8D6(0);
				for(
					lolo.local_12 = 0;
					lolo.local_12 < 8 && lolo.dwLVL > D_00DE6B78.f_000[lolo.local_12][0];
					lolo.local_12 ++
				);
				if(lolo.local_12 >= 8)
					lolo.local_12 = 7;
				lolo.dwEncounterId = (D_00DE6B78.f_000[lolo.local_12][1] & 0x3ff) + (C_00762136() == 0x19);
				lolo.local_9 = 1;
				//goto 00767C0B
			} else {
				D_00E3A888 = 0;
				if(
					C_00762191() &&
					C_00767CB5() &&
					C_00761769(7)//wm:is current model in list(1)?
				) {
					lolo.local_3 = (C_00753BE8() << 0xc) / C_00767CB5();
					lolo.local_5 = lolo.local_1->f_16;
					if(lolo.local_5 > lolo.local_3) {
						lolo.dwEncounterId = lolo.local_1->f_16 & 0x3ff;
					} else if((lolo.local_5 += lolo.local_1->f_18) > lolo.local_3) {
						lolo.dwEncounterId = lolo.local_1->f_18 & 0x3ff;
					} else if((lolo.local_5 += lolo.local_1->f_1a) > lolo.local_3) {
						lolo.dwEncounterId = lolo.local_1->f_1a & 0x3ff;
					} else if((lolo.local_5 += lolo.local_1->f_1c) > lolo.local_3) {
						lolo.dwEncounterId = lolo.local_1->f_1c & 0x3ff;
					}
					for(lolo.local_13 = 0; lolo.local_13 < 0x20 && D_00DE6B78.f_020[lolo.local_13][0] != lolo.dwEncounterId; lolo.local_13 ++);
					if(lolo.local_13 < 0x20)
						C_007674D2(D_00DE6B78.f_020[lolo.local_13][1]);
					lolo.local_6 = lolo.dwEncounterId != -1;
				}
				lolo.local_2 = C_00753BE8() < C_00767C77();
				if(lolo.local_2 == 0) {//else 00767AC3
					if(C_00767CD0() && lolo.dwEncounterId < 0) {//else 00767A38
						lolo.local_3 = C_00753BE8() << (C_00767C9E() + 8);
						lolo.local_5 = lolo.local_1->f_0e;
						if(lolo.local_5 > lolo.local_3) {
							lolo.dwEncounterId = lolo.local_1->f_0e & 0x3ff;
						} else {
							lolo.local_5 += lolo.local_1->f_10;
							if(lolo.local_5 > lolo.local_3) {
								lolo.dwEncounterId = lolo.local_1->f_10 & 0x3ff;
							}
						}
					}
					if(C_00767CDA() && lolo.dwEncounterId < 0) {//else 00767A78
						lolo.local_3 = C_00753BE8() << 8;
						lolo.local_5 = lolo.local_1->f_12;
						if(lolo.local_5 > lolo.local_3) {
							lolo.dwEncounterId = lolo.local_1->f_12 & 0x3ff;
						}
					}
					if(C_00767D2C() && lolo.dwEncounterId < 0) {//else 00767AC3
						lolo.local_3 = C_00753BE8() << (C_00767C9E() + 8);
						lolo.local_5 = lolo.local_1->f_14;
						if(lolo.local_5 > lolo.local_3) {
							lolo.dwEncounterId = lolo.local_1->f_14 & 0x3ff;
						}
					}
				}
				if(lolo.dwEncounterId < 0) {//else 00767C0B
					lolo.local_14 = 0;
					do {
						lolo.local_3 = C_00753BE8() << 8;
						lolo.local_5 = lolo.local_1->f_02;
						if(lolo.local_5 > lolo.local_3) {
							lolo.dwEncounterId = lolo.local_1->f_02 & 0x3ff;
						} else if((lolo.local_5 += lolo.local_1->f_04) > lolo.local_3) {
							lolo.dwEncounterId = lolo.local_1->f_04 & 0x3ff;
						} else if((lolo.local_5 += lolo.local_1->f_06) > lolo.local_3) {
							lolo.dwEncounterId = lolo.local_1->f_06 & 0x3ff;
						} else if((lolo.local_5 += lolo.local_1->f_08) > lolo.local_3) {
							lolo.dwEncounterId = lolo.local_1->f_08 & 0x3ff;
						} else if((lolo.local_5 += lolo.local_1->f_0a) > lolo.local_3) {
							lolo.dwEncounterId = lolo.local_1->f_0a & 0x3ff;
						} else if((lolo.local_5 += lolo.local_1->f_0c) > lolo.local_3) {
							lolo.dwEncounterId = lolo.local_1->f_0c & 0x3ff;
						}
					} while(lolo.local_14 ++ < 1 && lolo.dwEncounterId == D_00DC0C90);
				}
			}
		}
	}
	//-- has encounter --
	if(lolo.dwEncounterId != -1) {
		D_00DC0C90 = lolo.dwEncounterId;
		C_0075E5B3(1);//wm:set music related flag on/off
		C_0075E5C0(lolo.local_6?5:4);//wm:play song
	}
	//-- --

	return lolo.dwEncounterId | (lolo.local_2 << 0x1f) | (lolo.local_9 << 0x1e);
}

int C_00767C55() {
	return D_00DBCAD9 * ((D_00DBCAD9 > 0x10) + 1);
}

int C_00767C77() {
	int local_1 = D_00DBCADB & 0x7f;
	return local_1 * ((local_1 > 0x10) + 1);
}

int C_00767C9E() {
	return (D_00DBCADB & 0x80)?1:0;
}

int C_00767CB5() {
	return D_00DBCADA;
}

int C_00767CC1() {
	return D_00DC0A61 & 1;
}

int C_00767CD0() {
	return 1;
}

int C_00767CDA() {
	struct {
		int i;//local_2
		int local_1;
	}lolo;

	lolo.local_1 = 0;
	for(lolo.i = 0; lolo.i < 3; lolo.i ++)
		lolo.local_1 += D_00DBFD38.f_04f8[lolo.i] != 0xff;

	return lolo.local_1 > 1;
}

int C_00767D2C() {
	return 1;
}
