/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//WORLD MAP -- light related

#include "ff7.h"
#include "wm_data.h"
////////////////////////////////////////
tBGRA D_00E360F0;
struct t_light_5ac *D_00E360F4;//light system(2)
struct t_light_5ac *D_00E360F8;//light system(1)
////////////////////////////////////////
//wm:create light system(1)
struct t_light_5ac *C_0075E7A0(int bp08) {
	struct {
		D3DVECTOR pos_Light1;//local_33
		D3DVECTOR pos_Light2;//local_30
		struct t_light_5ac *local_27;
		D3DVECTOR pos_Light0;//local_26
		D3DVECTOR local_23;
		tBGRA col_Light0;//local_20
		tBGRA local_19;
		D3DMATRIX local_18;
		tBGRA col_Light2;//local_2
		tBGRA col_Light1;//local_1
	}lolo;

	C_0075E029(&lolo.local_18);//wm:init matrix(switch y z axis)?
	if(bp08 != 2) {
		// 0.16088867f -0.1003418f  -0.9848633f
		//-0.375f       0.81762695f  0.4489746f
		// 0.7128906f   0.35986328f  0.6064453f
		lolo.pos_Light0.x =   659.0f/4096.0f; lolo.pos_Light0.y = - 411.0f/4096.0f; lolo.pos_Light0.z = -4034.0f/4096.0f;
		lolo.pos_Light1.x = -1536.0f/4096.0f; lolo.pos_Light1.y =  3349.0f/4096.0f; lolo.pos_Light1.z =  1839.0f/4096.0f;
		lolo.pos_Light2.x =  2920.0f/4096.0f; lolo.pos_Light2.y =  1474.0f/4096.0f; lolo.pos_Light2.z =  2484.0f/4096.0f;

		lolo.local_23.x = lolo.pos_Light0.x; lolo.local_23.y = lolo.pos_Light0.y; lolo.local_23.z = lolo.pos_Light0.z;
		fast_multRotByVector(&lolo.local_18, &lolo.local_23, &lolo.pos_Light0);
		lolo.local_23.x = lolo.pos_Light1.x; lolo.local_23.y = lolo.pos_Light1.y; lolo.local_23.z = lolo.pos_Light1.z;
		fast_multRotByVector(&lolo.local_18, &lolo.local_23, &lolo.pos_Light1);
		lolo.local_23.x = lolo.pos_Light2.x; lolo.local_23.y = lolo.pos_Light2.y; lolo.local_23.z = lolo.pos_Light2.z;
		fast_multRotByVector(&lolo.local_18, &lolo.local_23, &lolo.pos_Light2);

		lolo.col_Light0.bgra = 0xff6e6e6e;
		lolo.col_Light1.bgra = 0xffaaaaaa;
		lolo.col_Light2.bgra = 0xff3c3c3c;

		lolo.local_19.c.r = 0x40;
		lolo.local_19.c.g = 0x40;
		lolo.local_19.c.b = 0x40;
		lolo.local_19.c.a = 0xff;
	} else {
		lolo.pos_Light0.x = 0; lolo.pos_Light0.y = 1.0f; lolo.pos_Light0.z = 0;
		lolo.pos_Light1.x = 0; lolo.pos_Light1.y = 0; lolo.pos_Light1.z = 0;
		lolo.pos_Light2.x = 0; lolo.pos_Light2.y = 0; lolo.pos_Light2.z = 0;

		lolo.local_23.x = lolo.pos_Light0.x; lolo.local_23.y = lolo.pos_Light0.y; lolo.local_23.z = lolo.pos_Light0.z;
		fast_multRotByVector(&lolo.local_18, &lolo.local_23, &lolo.pos_Light0);
		lolo.local_23.x = lolo.pos_Light1.x; lolo.local_23.y = lolo.pos_Light1.y; lolo.local_23.z = lolo.pos_Light1.z;
		fast_multRotByVector(&lolo.local_18, &lolo.local_23, &lolo.pos_Light1);
		lolo.local_23.x = lolo.pos_Light2.x; lolo.local_23.y = lolo.pos_Light2.y; lolo.local_23.z = lolo.pos_Light2.z;
		fast_multRotByVector(&lolo.local_18, &lolo.local_23, &lolo.pos_Light2);

		lolo.col_Light0.bgra = 0xffffffff;
		lolo.col_Light1.bgra = 0xff000000;
		lolo.col_Light2.bgra = 0xff000000;

		lolo.local_19.c.r = 0x20;
		lolo.local_19.c.g = 0x20;
		lolo.local_19.c.b = 0x30;
		lolo.local_19.c.a = 0xff;
	}
	lolo.local_27 = C_0069CA53(&lolo.pos_Light0, &lolo.pos_Light1, &lolo.pos_Light2, lolo.col_Light0, lolo.col_Light1, lolo.col_Light2, lolo.local_19);//light:create light system

	return lolo.local_27;
}

//wm:create light system(2)
struct t_light_5ac *C_0075E9B3(int bp08) {
	struct {
		D3DVECTOR pos_Light1;//local_14
		D3DVECTOR pos_Light2;//local_11
		struct t_light_5ac *local_8;
		D3DVECTOR pos_Light0;//local_7
		tBGRA col_Light0;//local_4
		tBGRA local_3;
		tBGRA col_Light2;//local_2
		tBGRA col_Light1;//local_1
	}lolo;

	switch(bp08) {
		case 0: case 3:
			lolo.pos_Light0.x = 1.0f; lolo.pos_Light0.y = 1.0f; lolo.pos_Light0.z = 1.0f;
			lolo.pos_Light1.x = 0; lolo.pos_Light1.y = 0; lolo.pos_Light1.z = 0;
			lolo.pos_Light2.x = 0; lolo.pos_Light2.y = 0; lolo.pos_Light2.z = 0;

			lolo.col_Light0.bgra = 0xff6e6e6e;
			lolo.col_Light1.bgra = 0xff000000;
			lolo.col_Light2.bgra = 0xff000000;

			lolo.local_3.c.r = 0x40;
			lolo.local_3.c.g = 0x40;
			lolo.local_3.c.b = 0x40;
			lolo.local_3.c.a = 0xff;
		break;
		case 2:
			lolo.pos_Light0.x = 0; lolo.pos_Light0.y = 1.0f; lolo.pos_Light0.z = 0;
			lolo.pos_Light1.x = 0; lolo.pos_Light1.y = 0; lolo.pos_Light1.z = 0;
			lolo.pos_Light2.x = 0; lolo.pos_Light2.y = 0; lolo.pos_Light2.z = 0;

			lolo.col_Light0.bgra = 0xff6e6e6e;
			lolo.col_Light1.bgra = 0xff000000;
			lolo.col_Light2.bgra = 0xff000000;

			lolo.local_3.c.r = 0x20;
			lolo.local_3.c.g = 0x20;
			lolo.local_3.c.b = 0x20;
			lolo.local_3.c.a = 0xff;
		break;
	}//end switch

	lolo.local_8 = C_0069CA53(&lolo.pos_Light0, &lolo.pos_Light1, &lolo.pos_Light2, lolo.col_Light0, lolo.col_Light1, lolo.col_Light2, lolo.local_3);//light:create light system

	return lolo.local_8;
}

//wm:secure clean light(2)
void C_0075EACE() {
	if(D_00E360F4) {
		C_0069C6CF(1, D_00E360F4);//light:release light system
		D_00E360F4 = 0;
	}
}

//wm:secure clean light(1)
void C_0075EAF6() {
	if(D_00E360F8) {
		C_0069C6CF(1, D_00E360F8);//light:release light system
		D_00E360F8 = 0;
	}
}

//wm:clean lights?
void C_0075EB1E() {
	C_0075EAF6();//wm:secure clean light(1)
	C_0075EACE();//wm:secure clean light(2)
}

//wm:change light params?
void C_0075EB2D(int bp08) {
	if(D_00E360F4) {
		switch(bp08) {
			case 0:
				D_00E360F4->f_008[0]->sDir.x = 1.0f; D_00E360F4->f_008[0]->sDir.y = 1.0f; D_00E360F4->f_008[0]->sDir.z = 1.0f;
				D_00E360F4->f_008[1]->sDir.x = 0; D_00E360F4->f_008[1]->sDir.y = 0; D_00E360F4->f_008[1]->sDir.z = 0;
				D_00E360F4->f_008[2]->sDir.x = 0; D_00E360F4->f_008[2]->sDir.y = 0; D_00E360F4->f_008[2]->sDir.z = 0;

				D_00E360F4->f_008[0]->color.bgra = 0xff6e6e6e;
				D_00E360F4->f_008[1]->color.bgra = 0xff000000;
				D_00E360F4->f_008[2]->color.bgra = 0xff000000;
			break;
			case 1:
				D_00E360F4->f_008[0]->sDir.x = 0; D_00E360F4->f_008[0]->sDir.y = 1.0f; D_00E360F4->f_008[0]->sDir.z = 0;
				D_00E360F4->f_008[1]->sDir.x = 0; D_00E360F4->f_008[1]->sDir.y = 0; D_00E360F4->f_008[1]->sDir.z = 0;
				D_00E360F4->f_008[2]->sDir.x = 0; D_00E360F4->f_008[2]->sDir.y = 0; D_00E360F4->f_008[2]->sDir.z = 0;

				D_00E360F4->f_008[0]->color.bgra = 0xff6e6e6e;
				D_00E360F4->f_008[1]->color.bgra = 0xff000000;
				D_00E360F4->f_008[2]->color.bgra = 0xff000000;
			break;
			case 2:
				D_00E360F4->f_008[0]->color.bgra = D_00E360F0.bgra;
				D_00E360F4->f_008[1]->color.bgra = 0xff000000;
				D_00E360F4->f_008[2]->color.bgra = 0xff000000;
			break;
			case 3:
				D_00E360F4->f_008[0]->color.bgra = 0xff6e6e6e;
				D_00E360F4->f_008[1]->color.bgra = 0xff000000;
				D_00E360F4->f_008[2]->color.bgra = 0xff000000;
			break;
		}//end switch
		C_0069BF90(D_00E360F4->f_008[0]->color, &(D_00E360F4->f_008[0]->color_norm));//light:tBGRA to fBGRA?
		C_0069C11F(&(D_00E360F4->f_008[0]->color_norm));//light:normalize fBGRA[no copy]?
		D_00E360F4->f_008[1]->color_norm.r = 0; D_00E360F4->f_008[1]->color_norm.g = 0; D_00E360F4->f_008[1]->color_norm.b = 0; D_00E360F4->f_008[1]->color_norm.a = 1.0f;
		D_00E360F4->f_008[2]->color_norm.r = 0; D_00E360F4->f_008[2]->color_norm.g = 0; D_00E360F4->f_008[2]->color_norm.b = 0; D_00E360F4->f_008[2]->color_norm.a = 1.0f;
		C_0069C5EE(D_00E360F4);//light:reset
	}
}

//wm:set some global light color?
void C_0075EE10(struct MATRIX *bp08) {
	D_00E360F0.c.r = bp08->m[0][0] >> 4;
	D_00E360F0.c.g = bp08->m[1][0] >> 4;
	D_00E360F0.c.b = bp08->m[2][0] >> 4;
	D_00E360F0.c.a = 0xff;
}
