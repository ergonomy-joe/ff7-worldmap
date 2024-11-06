/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//WORLD MAP -- map/radar

#include "ff7.h"
#include "wm_data.h"
////////////////////////////////////////
//-- color on map --
int D_0096DEF0[6] = {
	0x80800000,
	0x80006000,
	0x80006060,
	0x80606060,
	0x80600060,
	0x80606000
};
//-- --
char D_0096DF08[6] = {
	WM_MODELID_00,
	WM_MODELID_06,
	WM_MODELID_05,
	WM_MODELID_03,
	WM_MODELID_13,
	WM_MODELID_19
};
//00 00
////////////////////////////////////////
struct t_wm_local_xyuv {
	short wX,wY,wU,wV;
};
////////////////////////////////////////
int D_00E3A898;
int D_00E3A89C;
int D_00E3A8A0;
////////////////////////////////////////
//wm:reset map/radar
void C_00767D40() {
	D_00E3A898 =
	D_00E3A8A0 = 0;
	D_00E3A89C = D_00DE69D8 * 8;
}

void C_00768366(float, float, float, float);//display "big map"
void C_00768530(float, float, float, float);//display "small map"
void C_007686FA(float, float, float, int, struct t_dx_sfx_e0 *);//display radar stuff?

//wm:render map/radar
void C_00767D68(short wAngle/*bp08*/) {
	struct {//xd8
		//above local_34 for compiler
		struct t_dx_rend_vertex_20 *local_33;
		struct t_dx_rend_vertex_20 *local_32;
		struct t_dx_rend_vertex_20 *local_31;
		short local_30[2];
		short local_29[2];
		short local_28[2];
		int _ocal_27;
		DECL_struct_MATRIX(local_26);
		int i;//local_18
		int dwMapY;//local_17
		int local_16_unused;
		int dwMapX;//local_15
		struct VECTOR local_14;
		struct t_wm_local_xyuv local_10;
		int dwFlags_unused;//local_8
		int dwModelType;//local_7
		struct VECTOR local_6;
		struct SVECTOR local_2;
	}lolo;

	if(D_00E3A898 < 2) {//else 0076831B
		D_00E3A89C = /*lolo.local_34*/(D_00E3A898 == 1 && C_0074D330() == 0)?
			D_00DE69D8 * 24:
			D_00DE69D8 * 8
		;
		lolo.dwMapX = D_00DE69D8 * 316 - D_00E3A89C * 11;
		lolo.dwMapY = D_00DE69D8 * 220 - D_00E3A89C * 8;
		lolo.local_16_unused = C_0074C9A5();//wm:get backbuffer index[unused]?
		lolo.dwModelType = C_00761735();//wm:get model type(2)?
		//-- positions on map --
		for(lolo.i = 0; lolo.i < 6; lolo.i ++) {
			if(/*lolo.local_36*/lolo.i?
				/*lolo.local_35*/(D_0096DF08[lolo.i] != lolo.dwModelType && C_00762047(D_0096DF08[lolo.i])):
				(C_007616B3(), 1)//wm:set some info(1)?
			) {
				C_00762763(&lolo.local_14);//wm:get model pos(1)?
				lolo.local_10.wX = lolo.dwMapX + ((D_00E3A89C * lolo.local_14.vx) >> 0xf) - D_00DE69D8 * 4 + D_00E2C424;
				lolo.local_10.wY = lolo.dwMapY + ((D_00E3A89C * lolo.local_14.vz) >> 0xf) - D_00DE69D8 * 4 + D_00E2C428;
				lolo.local_10.wV = (((((unsigned)C_0040AC84() + lolo.i * 4) >> (lolo.i != 0)) & 0x10) << (D_00E3A89C > D_00DE69D8 * 8)) + 4;
				C_007686FA(
					(float)lolo.local_10.wX,
					(float)lolo.local_10.wY,
					(float)lolo.local_10.wV,
					D_0096DEF0[lolo.i],
					D_00E2C3E4
				);//display radar stuff?
			}
		}
		//-- view cone --
		if(C_0074D28E() == 2 || C_0074D28E() == 3) {//wm:get view mode?//else 00768232
			C_00762798(&lolo.local_14);//wm:get model pos(2)?
			lolo.local_30[0] = lolo.dwMapX + ((D_00E3A89C * lolo.local_14.vx) >> 0xf) + D_00E2C424;
			lolo.local_30[1] = lolo.dwMapY + ((D_00E3A89C * lolo.local_14.vz) >> 0xf) + D_00E2C428;
			lolo.local_2.vx =
			lolo.local_2.vy = 0;
			lolo.local_2.vz = wAngle;
			psx_RotMatrixXYZ(&lolo.local_2, &lolo.local_26);
			lolo.local_6.vx = 
			lolo.local_6.vy =
			lolo.local_6.vz = 0;
			psx_TransMatrix(&lolo.local_26, &lolo.local_6);
			psx_SetRotMatrix(&lolo.local_26);
			psx_SetTransMatrix(&lolo.local_26);
			lolo.i = /*lolo.local_40*/(D_00E3A89C == D_00DE69D8 * 8)?
				D_00DE69D8 * -8:
				D_00DE69D8 * -16
			;
			lolo.local_2.vx = lolo.i >> 1;
			lolo.local_2.vy = lolo.i;
			psx_RotTrans(&lolo.local_2, &lolo.local_6, &lolo.dwFlags_unused);
			lolo.local_29[0] = lolo.local_30[0] + lolo.local_6.vx;
			lolo.local_29[1] = lolo.local_30[1] + lolo.local_6.vy;
			lolo.local_2.vx = -lolo.local_2.vx;
			psx_RotTrans(&lolo.local_2, &lolo.local_6, &lolo.dwFlags_unused);
			lolo.local_28[0] = lolo.local_30[0] + lolo.local_6.vx;
			lolo.local_28[1] = lolo.local_30[1] + lolo.local_6.vy;
			if(C_0066E272(1, D_00E2C3E0)) {//else 00768232
				if(C_0074C969()) {//wm:get "isRendering"?//else 00768232
					MK_VERTEX_NOTEXTURE(&(D_00E2C3E0->f_70.asVertex[0]), lolo.local_31, (float)lolo.local_30[0], (float)lolo.local_30[1], 0.01f, 1.0f, 0x80606000, 0xff000000);
					MK_VERTEX_NOTEXTURE(&(D_00E2C3E0->f_70.asVertex[1]), lolo.local_32, (float)lolo.local_29[0], (float)lolo.local_29[1], 0.01f, 1.0f, 0x80101000, 0xff000000);
					MK_VERTEX_NOTEXTURE(&(D_00E2C3E0->f_70.asVertex[2]), lolo.local_33, (float)lolo.local_28[0], (float)lolo.local_28[1], 0.01f, 1.0f, 0x80101000, 0xff000000);
				}
			}
		}
		//-- map --
		if(D_00E3A89C == D_00DE69D8 * 8)
			C_00768530((float)(lolo.dwMapX + D_00E2C424), (float)(lolo.dwMapY + D_00E2C428), (float)(D_00DE69D8 * 72), (float)(D_00DE69D8 * 56));//display "small map"
		else
			C_00768366((float)(lolo.dwMapX + D_00E2C424), (float)(lolo.dwMapY + D_00E2C428), (float)(D_00E3A89C * 9), (float)(D_00E3A89C * 7));//display "big map"
	}
}

//wm:set map/radar state
void C_0076831F(short bp08) {
	D_00E3A898 = bp08;
	if(C_00761735() != WM_MODELID_03)//wm:get model type(2)?
		D_00E3A8A0 = D_00E3A898;

}

//wm:get map/radar state
short C_00768343() {
	return D_00E3A898;
}

//wm:restore map/radar state?
void C_0076834E() {
	if(D_00E3A898 == 1)
		D_00E3A898 = D_00E3A8A0;
}

//display "big map"
void C_00768366(float fX/*bp08*/, float fY/*bp0c*/, float fWidth/*bp10*/, float fHeight/*bp14*/) {
	struct {
		struct t_dx_rend_vertex_20 *local_9[4];
		float fTexHeight;//local_5
		float fTexWidth;//local_4
		float fZ;//local_3
		float fV;//local_2
		float fU;//local_1
	}lolo;

	if(C_0066E272(1, D_00E2C3DC)) {
		if(C_0074C969()) {//wm:get "isRendering"?
			lolo.fZ = 0.001f;
			lolo.fU = (1.0f/256.0f);
			lolo.fV = (1.0f/256.0f);
			lolo.fTexWidth = (214.0f/256.0f);
			lolo.fTexHeight = (166.0f/256.0f);
			MK_QUAD_2D(D_00E2C3DC->f_70.asVertex, lolo.local_9, fX, fY, fWidth, fHeight, lolo.fZ, 1.0f, 0x80ffffff, 0xff000000, lolo.fU, lolo.fV, lolo.fTexWidth, lolo.fTexHeight);
		}
	}
}

//display "small map"
void C_00768530(float fX/*bp08*/, float fY/*bp0c*/, float fWidth/*bp10*/, float fHeight/*bp14*/) {
	struct {
		struct t_dx_rend_vertex_20 *local_9[4];
		float fTexHeight;//local_5
		float fTexWidth;//local_4
		float fZ;//local_3
		float fV;//local_2
		float fU;//local_1
	}lolo;

	if(C_0066E272(1, D_00E2C3D8)) {
		if(C_0074C969()) {//wm:get "isRendering"?
			lolo.fZ = 0.001f;
			lolo.fU = 1.0f/128.0f;
			lolo.fV = 1.0f/64.0f;
			lolo.fTexWidth = 70.0f/128.0f;
			lolo.fTexHeight = 54.0f/64.0f;
			MK_QUAD_2D(D_00E2C3D8->f_70.asVertex, lolo.local_9, fX, fY, fWidth, fHeight, lolo.fZ, 1.0f, 0x80ffffff, 0xff000000, lolo.fU, lolo.fV, lolo.fTexWidth, lolo.fTexHeight);
		}
	}
}

//display radar stuff?
void C_007686FA(float fX/*bp08*/, float fY/*bp0c*/, float fV/*bp10*/, int dwColor/*bp14*/, struct t_dx_sfx_e0 *bp18) {
	struct {
		struct t_dx_rend_vertex_20 *local_10[4];
		float fTexHeight;//local_6
		float fTexWidth;//local_5
		float fZ;//local_4
		float fHeight;//local_3
		float fWidth;//local_2
		float fU;//local_1
	}lolo;

	if(C_0066E272(1, bp18)) {
		if(C_0074C969()) {//wm:get "isRendering"?
			lolo.fZ = 0;
			lolo.fWidth = (float)D_00DE69D8 * 8.0f;
			lolo.fHeight = (float)D_00DE69D8 * 8.0f;
			lolo.fU = 4.0f/128.0f;//0.03125f
			fV /= 64.0f;
			lolo.fTexWidth = 8.0f/128.0f;//0.0625f
			lolo.fTexHeight = 8.0f/64.0f;//0.125f
			MK_QUAD_2D(bp18->f_70.asVertex, lolo.local_10, fX, fY, lolo.fWidth, lolo.fHeight, lolo.fZ, 1.0f, dwColor, 0xff000000, lolo.fU, fV, lolo.fTexWidth, lolo.fTexHeight);
		}
	}
}
