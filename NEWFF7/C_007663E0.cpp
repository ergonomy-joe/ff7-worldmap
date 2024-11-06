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
int D_00E3A86C;//"leave vehicle" state?
int D_00E3A870;//"X" button short trigger counter?
int D_00E3A874;//[unused]counter/flag for enter vehicle?
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
	C_007616B3();//wm:set some info(1)?
	local_2.vx = local_2.vy = 0;
	switch(C_00761735()) {//wm:get model type(2)?
		case WM_MODELID_05: case WM_MODELID_13:
			local_2.vz =
				bp08?bp08:
				C_00761FE8()?100:
				800
			;
			C_00753D00(&local_2, C_00761EEC());//wm:SVECTOR z rotation?
		break;
		default:
			local_2.vz = 300;
			C_00753D00(&local_2, C_00761EEC() + 0x400);//wm:SVECTOR z rotation?
	}//end switch
	C_00762E87(local_2.vx, local_2.vz);
}

//wm:some stack.push?
void C_007664C2(unsigned char bp08) {
	if(D_00E3A868 < &(D_00E3A860[8])/*00E3A868*/)
		*(D_00E3A868 ++) = bp08;
}

//some stack.pop?
unsigned char C_007664EC() {
	return (D_00E3A868 > &(D_00E3A860[0]))?*(--D_00E3A868):0;
}

//wm:some stack.peek?
unsigned char C_00766526() {
	return (D_00E3A868 > &(D_00E3A860[0]))?*(D_00E3A868 - 1):0;
}

//wm:some stack.set element 0?
void C_00766553(int bp08) {
	D_00E3A860[0] = bp08;
}

//wm:some stack.is not empty?
int C_00766560() {
	return (D_00E3A868 > &(D_00E3A860[0]));
}

//wm:"O" button near a vehicle?
void C_00766574() {
	struct {
		struct VECTOR local_5;
		int dwModelType;//local_1
	}lolo;

	lolo.dwModelType = C_00761735();//wm:get model type(2)?
	//-- --
	if(lolo.dwModelType == WM_MODELID_05 && D_00E3A878) {
		C_00761FAA(1);
		C_0074D4F7(1);//wm:set "highwind" state?
		return;
	}
	//-- --
	if(C_007620B6()) {//else 00766678
		C_00762763(&lolo.local_5);//wm:get model pos(1)?
		C_0075027C(&lolo.local_5, C_0076170B() == WM_MODELID_03?-1:1);//wm:set some pos?
		C_007664C2(C_00761735());//wm:get model type(2)?
		//-- --
		if(C_007618B7()) {//wm:is current model a chocobo(2)?
			C_007611AE();
			C_0075E5C0(2);//wm:play song
			return;
		}
		//-- --
		C_007615D6();
		C_0076154F();
		C_007616CB();//wm:set some info(2)?
		switch(C_00761735()) {//wm:get model type(2)?
			case WM_MODELID_03://"highwind"?
				C_00761FAA(1);
				C_0074D4F7(1);//wm:set "highwind" state?
				C_0075BB25();
				if(C_0075E64D() < 6)//wm:get current song?
					C_0075E5C0(C_00766C33() == 0?3:1);//wm:play song
			break;
			case WM_MODELID_06://"buggy"?
				C_0075E6CC(0x1ec);//wm:start/stop SFX?
			break;
		}//end switch
	}
}

int C_007666FF(void);//can leave vehicle here?

//wm:"X" button short trigger?
void C_0076667C() {
	int dwModelType;

	dwModelType = C_00761735();//wm:get model type(2)?
	if(D_00E3A86C == 0) {//else 007666FB
		if(C_007666FF()) {//can leave vehicle here?//else 007666E7
			if(dwModelType == WM_MODELID_03 || (dwModelType == WM_MODELID_05 && C_00761FE8())) {
				C_0074D4F7(-1);//wm:set "highwind" state?
			} else {
				C_0074D438(0, 2);//wm:set enable something?
			}
			D_00E3A86C = 1;//start leave vehicle
			if(dwModelType == WM_MODELID_03 || dwModelType == WM_MODELID_04)
				C_00763D6C(1);//wm:set enable/disable script?
		}
		//-- descent in north crater --
		if(C_00762136() == 0x1b)//wm:get current terrain?
			C_007640BC(9);//wm:start script(2)?
	}
}

//can leave vehicle here?
int C_007666FF() {
	int bp_04;

	bp_04 = C_00762136();//wm:get current terrain?
	if(C_00761844())//wm:is current model a chocobo(1)?
		return (0x221B0F03 >> bp_04) & 1;
	switch(C_00761735()) {//wm:get model type(2)?
		case WM_MODELID_03: return bp_04 == 0;
		case WM_MODELID_06: return (0x221B0F83 >> bp_04) & 1;
		case WM_MODELID_05: return (0x70 >> bp_04) & 1;
		case WM_MODELID_13: return 1;
	}//end switch

	return 0;
}

//wm:start "leave vehicle"?
void C_007667A3() {
	D_00E3A86C = 1;//start leave vehicle
}

//wm:manage ride/leave vehicle?
void C_007667B2(int bp08) {
	struct {//x3c
		unsigned local_14;
		unsigned local_13;
		DECL_short(local_12);
		int dwModelType;//local_11
		struct VECTOR local_10;
		int dwIsHighwind;//local_6
		int dwInputMask;//local_5
		struct VECTOR local_4;
	}lolo;

	lolo.dwIsHighwind = (C_00761735() == WM_MODELID_03);//wm:get model type(2)?
	//-- [unused] --
	if(D_00E3A874) {
		D_00E3A874 --;
		return;
	}
	//-- --
	if(C_0074D504() == 0 && C_0074D330() != 3) {//else 00766B4F
		lolo.dwInputMask = C_007186B9();//menu_input:get "current mask"
		if(D_00E3A86C == 0 && bp08 == 1) {
			C_00766574();//wm:"O" button near a vehicle?
			//goto 00766B28
		} else if(
			C_0074D4B6() &&//wm:get enable something?
			!(lolo.dwInputMask & (C_00761844()?(0xf000|PAD_06):PAD_06)) &&
			D_00E3A870 > 0 && D_00E3A870 < 15 &&
			(C_00761769(BIT(WM_MODELID_13)) == 0 || C_00762136() == 0x12)//wm:is current model in list(1)?//wm:get current terrain?
		) {//else 0076687B
			C_0076667C();//wm:"X" button short trigger?
			//goto 00766B28
		} else if(D_00E3A86C == 1) {
			D_00E3A86C = 2;
			//goto 00766B28
		} else if(D_00E3A86C == 2) {//else 00766B28
			D_00E3A86C = 0;
			C_007616B3();//wm:set some info(1)?
			lolo.dwModelType = C_0076170B();
			C_00762763(&lolo.local_4);//wm:get model pos(1)?
			C_007627CD(&lolo.local_10);//wm:get model previous pos(1)?
			C_0074D438(1, 2);//wm:set enable something?
			if(lolo.local_4.vx != lolo.local_10.vx || lolo.local_4.vz != lolo.local_10.vz) {//else 00766AE7
				C_00767524();
				if(lolo.dwIsHighwind) {
					C_00761FAA(0);
					C_00763D6C(0);//wm:set enable/disable script?
				}
				C_00762837();
				C_0074D323(0);//wm:set camera tilt angle?
				if(lolo.dwModelType == WM_MODELID_05 && C_00761FE8()) {
					C_00761FAA(0);
					//goto 00766AE5
				} else {
					if(lolo.dwModelType == WM_MODELID_04)
						C_00763D6C(0);//wm:set enable/disable script?
					C_00764014(lolo.dwModelType, 5);//wm:start script(1)?
					if(lolo.dwModelType == WM_MODELID_04)
						C_00763D6C(1);//wm:set enable/disable script?
					//-- --
					if(C_007618B7()) {//wm:is current model a chocobo(2)?//else 00766A18
						//-- chocobo --
						lolo.local_12 = C_00753F2E(&lolo.local_10, &lolo.local_4) - 0x400;
						C_00761B19(lolo.local_12);
						C_007664EC();//some stack.pop?
						C_0076142D();
						if(lolo.dwModelType < WM_MODELID_41)
							C_007616CB();//wm:set some info(2)?
						C_00762955(2);
						C_00761B19(lolo.local_12);
						C_0075E5C0(1);//wm:play song
						C_0074D438(0, 6);//wm:set enable something?
						if(lolo.dwModelType == WM_MODELID_04) {
							C_0075334D();
						} else if(lolo.dwModelType >= WM_MODELID_41) {
							C_00762047(C_0076736E());//wm:set current model
							C_007616CB();//wm:set some info(2)?
						}
						C_007663A8(&lolo.local_4);
						//goto 00766AE5
					} else {
						//-- other rides --
						C_007610B3();//wm:alloc new model
						lolo.local_13 = C_007664EC();//some stack.pop?
						if(C_0076192A(lolo.local_13)) {//else 00766A70
							lolo.local_14 = C_00766526();//wm:some stack.peek?
							C_0076197B(lolo.local_14);
							C_007616CB();//wm:set some info(2)?
							C_007610B3();//wm:alloc new model
							C_0076197B(lolo.local_13);
							C_007611AE();
						} else {
							C_0076197B(lolo.local_13);
							C_007616CB();//wm:set some info(2)?
							if(lolo.dwIsHighwind)
								C_0076834E();//wm:restore map/radar state?
						}
						C_0076247D(&lolo.local_4);
						C_0075E5C0(C_00761844()?2:1);//wm:play song
						if(lolo.dwModelType == WM_MODELID_06)
							C_0075E6CC(-0x1ec);//wm:start/stop SFX?
						else if(lolo.dwModelType == WM_MODELID_05)
							C_0075E6CC(-0x1ed);//wm:start/stop SFX?
						C_0075027C(&lolo.local_4, 1);//wm:set some pos?
					}
					//-- --
				}
//00766AE5	goto 00766B28
			} else {
				if(C_00761735() == WM_MODELID_03 || C_00761735() == WM_MODELID_04)//wm:get model type(2)?
					C_00763D6C(0);//wm:set enable/disable script?
				if(lolo.dwIsHighwind || (C_00761735() == WM_MODELID_05 && C_00761FE8()))
					C_0074D4F7(1);//wm:set "highwind" state?
			}
		}
		//-- "X" button short trigger counter? --
		D_00E3A870 = /*lolo.local_15*/(lolo.dwInputMask & PAD_06)?D_00E3A870 + 1:0;
	}
//00766B4F
}

//wm:get "leave vehicle" state?
int C_00766B53() {
	return D_00E3A86C;
}

void C_00766B5D(int bp08) {
	D_00E3A878 = bp08;
}
