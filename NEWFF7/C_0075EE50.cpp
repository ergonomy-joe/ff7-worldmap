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
short D_00E36100;
short D_00E36104;
short D_00E36108;
int D_00E3610C;
////////////////////////////////////////
void C_0075EE50(struct t_script_20 *bp08) {
	D_00CC0960[0] = 0xFF;
	D_00CC0960[4] = 0xFF;
	D_00CBF5E8 = bp08;
	D_00CBF5E8->f_04 = 8;
	C_00768C7A();
	D_00CBF9D8 = &D_00CC0D88;
}

void C_0075EE86(int bp08) {
	if(D_00CFF5B8[0].wStatus == 0) {
		D_00E36108 =
		D_00E36100 = 0;
		C_00769050(0, bp08);//dialog:refresh(1)
	}
}

void C_0075EEBB(short bp08, short bp0c, short bp10) {
	if(D_00CFF5B8[0].wStatus == 0) {
		D_00E36108 = bp0c;
		D_00E36100 = bp10;
		C_007693A1(0, bp08, (unsigned char)D_00E36108, (unsigned char)D_00E36100, &D_00E36104);//dialog:refresh(2)
	}
}

int C_0075EF01() {
	return !(D_00CFF5B8[0].wStatus == 0);
}

int C_0075EF13() {
	if(D_00CFF5B8[0].wStatus && D_00CFF5B8[0].wStatus != 7)
		C_00768E3D(0);

	return !(D_00CFF5B8[0].wStatus == 0);
}

//manage text event?
void C_0075EF46() {
	int local_2;
	int local_1;

	if(D_00CFF5B8[0].wStatus) {
		local_1 = C_007186B9();//menu_input:get "current mask"
		D_00CBF9D8->f_68.dwKEYON = local_1 & ~D_00CBF9D8->f_68.dwKEY;
		D_00CBF9D8->f_68.dwKEY = local_1;
		local_1 = C_007186B9();//menu_input:get "current mask"
		D_00CBF9D8->f_78.dwKEYON = local_1 & ~D_00CBF9D8->f_78.dwKEY;
		D_00CBF9D8->f_78.dwKEY = local_1;
		if(D_00E36108 == 0 && D_00E36100 == 0) {
			local_2 = C_00769050(0, 0);//dialog:refresh(1)
		} else {
			local_2 = C_007693A1(0, 0, (unsigned char)D_00E36108, (unsigned char)D_00E36100, &D_00E36104);//dialog:refresh(2)
		}
		D_00E3610C = 1;
	}
}

short C_0075F00E() {
	return (D_00CFF5B8[0].wStatus == 0)?D_00E36104:-1;
}

void C_0075F038(short *bp08) {
	if(bp08)
		C_00768F48(0, bp08[0], bp08[1], bp08[2], bp08[3]);//dialog:set location and size
}

void C_0075F06C(int bp08, int bp0c) {
	C_00768EC3(0, bp08, bp0c);
}
