/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//WORLD MAP -- 

#include "ff7.h"
#include "wm_data.h"
#include "menu_data.h"
////////////////////////////////////////
unsigned char D_00E3A860[8];
unsigned char *D_00E3A868;
int D_00E3A86C;
int D_00E3A870;
int D_00E3A874;
int D_00E3A878;
////////////////////////////////////////
void C_007663E0() {
	D_00E3A86C = 0;
	D_00E3A874 = 0;
	D_00E3A868 = &(D_00E3A860[0]);
	D_00E3A878 = 0;
	D_00E3A870 = 0;
}

void C_00766417(int bp08) {
	struct SVECTOR local_2;

	C_007628B5();
	C_007616B3();
	local_2.f_00 = local_2.f_02 = 0;
	switch(C_00761735()) {//current transportation mode?
		case 5: case 0xd:
			local_2.f_04 = bp08?bp08:C_00761FE8()?0x64:0x320;
			C_00753D00(&local_2, C_00761EEC());
		break;
		default:
			local_2.f_04 = 0x12c;
			C_00753D00(&local_2, C_00761EEC() + 0x400);
	}
	C_00762E87(local_2.f_00, local_2.f_04);
}

void C_007664C2(unsigned char bp08) {
	if(D_00E3A868 < &(D_00E3A860[8])/*00E3A868*/)
		*(D_00E3A868 ++) = bp08;
}

unsigned char C_007664EC() {
	return (D_00E3A868 > &(D_00E3A860[0]))?*(--D_00E3A868):0;
}

unsigned char C_00766526() {
	return (D_00E3A868 > &(D_00E3A860[0]))?*(D_00E3A868 - 1):0;
}

void C_00766553(int bp08) {
	D_00E3A860[0] = bp08;
}

int C_00766560() {
	return (D_00E3A868 > &(D_00E3A860[0]));
}

//"O" button near a vehicle?
void C_00766574() {
	struct {
		struct VECTOR local_5;
		int local_1;
	}lolo;

	lolo.local_1 = C_00761735();//current transportation mode?
	if(lolo.local_1 == 5 && D_00E3A878) {
		C_00761FAA(1);
		C_0074D4F7(1);//set "highwind" state?
		return;
	}
	if(C_007620B6()) {//else 00766678
		C_00762763(&lolo.local_5);
		C_0075027C(&lolo.local_5, C_0076170B() == 3?-1:1);
		C_007664C2(C_00761735());
		if(C_007618B7()) {
			C_007611AE();
			C_0075E5C0(2);
			return;
		}
		C_007615D6();
		C_0076154F();
		C_007616CB();
		switch(C_00761735()) {
			case 3://"highwind"?
				C_00761FAA(1);
				C_0074D4F7(1);//set "highwind" state?
				C_0075BB25();
				if(C_0075E64D() < 6)
					C_0075E5C0(C_00766C33() == 0?3:1);
			break;
			case 6://"buggy"?
				C_0075E6CC(0x1ec);//start/stop SFX?
			break;
		}
	}
}

int C_007666FF(void);

//"X" button short trigger?
void C_0076667C() {
	int local_1;

	local_1 = C_00761735();//current transportation mode?
	if(D_00E3A86C == 0) {//else 007666FB
		if(C_007666FF()) {//else 007666E7
			if(local_1 == 3 || (local_1 == 5 && C_00761FE8())) {
				C_0074D4F7(-1);//set "highwind" state?
			} else {
				C_0074D438(0, 2);
			}
			D_00E3A86C = 1;
			if(local_1 == 3 || local_1 == 4)
				C_00763D6C(1);
		}
		if(C_00762136() == 0x1b)
			C_007640BC(9);
	}
}

int C_007666FF() {
	int bp_04;

	bp_04 = C_00762136();
	if(C_00761844())
		return (0x221B0F03 >> bp_04) & 1;
	switch(C_00761735()) {//current transportation mode?
		case 3: return bp_04 == 0;
		case 6: return (0x221B0F83 >> bp_04) & 1;
		case 5: return (0x70 >> bp_04) & 1;
		case 0xd: return 1;
	}

	return 0;
}

void C_007667A3() {
	D_00E3A86C = 1;
}

void C_007667B2(int bp08) {
	struct {//x3c
		unsigned local_14;
		unsigned local_13;
		short local_12; char _ocal_12[2];
		int local_11;
		struct VECTOR local_10;
		int local_6;
		int local_5;
		struct VECTOR local_4;
	}lolo;

	lolo.local_6 = C_00761735() == 3;//current transportation mode?
	if(D_00E3A874) {
		D_00E3A874 --;
		return;
	}
	if(C_0074D504() == 0 && C_0074D330() != 3) {//else 00766B4F
		lolo.local_5 = C_007186B9();//menu_input:get "current mask"
		if(D_00E3A86C == 0 && bp08 == 1) {
			C_00766574();//"O" button near a vehicle?
			//goto 00766B28
		} else if(C_0074D4B6() && (lolo.local_5 & (C_00761844()?0xf040:0x40)) == 0 && D_00E3A870 > 0 && D_00E3A870 < 0xf && (C_00761769(0x2000) == 0 || C_00762136() == 0x12)) {//else 0076687B
			C_0076667C();//"X" button short trigger?
			//goto 00766B28
		} else if(D_00E3A86C == 1) {
			D_00E3A86C = 2;
			//goto 00766B28
		} else if(D_00E3A86C == 2) {//else 00766B28
			D_00E3A86C = 0;
			C_007616B3();
			lolo.local_11 = C_0076170B();
			C_00762763(&lolo.local_4);
			C_007627CD(&lolo.local_10);
			C_0074D438(1, 2);
			if(lolo.local_4.f_00 != lolo.local_10.f_00 || lolo.local_4.f_08 != lolo.local_10.f_08) {//else 00766AE7
				C_00767524();
				if(lolo.local_6) {
					C_00761FAA(0);
					C_00763D6C(0);
				}
				C_00762837();
				C_0074D323(0);
				if(lolo.local_11 == 5 && C_00761FE8()) {
					C_00761FAA(0);
					//goto 00766AE5
				} else {
					if(lolo.local_11 == 4)
						C_00763D6C(0);
					C_00764014(lolo.local_11, 5);
					if(lolo.local_11 == 4)
						C_00763D6C(1);
					if(C_007618B7()) {//else 00766A18
						lolo.local_12 = C_00753F2E(&lolo.local_10, &lolo.local_4) - 0x400;
						C_00761B19(lolo.local_12);
						C_007664EC();
						C_0076142D();
						if(lolo.local_11 < 0x29)
							C_007616CB();
						C_00762955(2);
						C_00761B19(lolo.local_12);
						C_0075E5C0(1);
						C_0074D438(0, 6);
						if(lolo.local_11 == 4) {
							C_0075334D();
						} else if(lolo.local_11 >= 0x29) {
							C_00762047(C_0076736E());
							C_007616CB();
						}
						C_007663A8(&lolo.local_4);
						//goto 00766AE5
					} else {
						C_007610B3();
						lolo.local_13 = C_007664EC();
						if(C_0076192A(lolo.local_13)) {//else 00766A70
							lolo.local_14 = C_00766526();
							C_0076197B(lolo.local_14);
							C_007616CB();
							C_007610B3();
							C_0076197B(lolo.local_13);
							C_007611AE();
						} else {
							C_0076197B(lolo.local_13);
							C_007616CB();
							if(lolo.local_6)
								C_0076834E();
						}
						C_0076247D(&lolo.local_4);
						C_0075E5C0(C_00761844()?2:1);
						if(lolo.local_11 == 6)
							C_0075E6CC(-0x1ec);//start/stop SFX?
						else if(lolo.local_11 == 5)
							C_0075E6CC(-0x1ed);//start/stop SFX?
						C_0075027C(&lolo.local_4, 1);
					}
				}
//00766AE5	goto 00766B28
			} else {
				if(C_00761735() == 3 || C_00761735() == 4)//current transportation mode?
					C_00763D6C(0);
				if(lolo.local_6 || (C_00761735() == 5 && C_00761FE8()))
					C_0074D4F7(1);//set "highwind" state?
			}
		}
		D_00E3A870 = /*lolo.local_15*/(lolo.local_5 & 0x40)?D_00E3A870 + 1:0;
	}
//00766B4F
}

int C_00766B53() {
	return D_00E3A86C;
}

//"X" button short trigger?
void C_00766B5D(int bp08) {
	D_00E3A878 = bp08;
}
