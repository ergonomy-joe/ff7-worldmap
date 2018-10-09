/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//WORLD MAP -- 

#include "ff7.h"
#include "wm_data.h"
//////////////////////////////////////////////////
//TODO in another module?
struct t_wm_local_0c *D_00E36110;
int *D_00E36114;
unsigned char D_00E36118[8 + 0x1000];//"mes"
short D_00E37120[0x200];//"atn.tbl"
int D_00E37520;
int D_00E37524;
//char 00E37528[0x800]?
int D_00E37D28;
struct t_wm_local_0c_xxx D_00E37D30[0x80];//"field.tbl"
struct t_wm_local_0c *D_00E38330;
//////////////////////////////////////////////////
struct t_g_drv_0c D_00E38338[0x80];//todo type/num
struct t_g_drv_0c D_00E38938[0x80];//todo type/num
float D_00E38F38[0x80][4];
D3DMATRIX D_00E39738;
D3DMATRIX D_00E39778;
int D_00E397B8[0x80];//check
//////////////////////////////////////////////////
//[local]float to int
int C_0075F090(float bp08) {
	int bp_08;
//	LARGE_INTEGER bp_0c;

	_asm FLD bp08
	_asm FISTP QWORD PTR [EBP-0xc]
	_asm MOV EAX,[EBP-0xc]
	_asm MOV bp_08,EAX

	return bp_08;
}

void C_0075F0AD(struct SVECTOR *bp08, int bp0c) {
	struct {
		float local_10;
		float local_9;
		float local_8[4];
		int local_4;
		int local_3;
		int local_2;
		int local_1;
	}lolo;

	C_006617E9(C_0066100D(), &D_00E39778);//psx:transformation to D3DMATRIX(3)
	C_0069C69F(&D_00E39778, D_00E360F4);//light:compute "result matrix"?
	C_0067D2BF(&D_00E39778, &D_00E39738);//dx_mat:matrix multiplication by "struct t_aa0::f_8d0" 4x4[transpose]
	lolo.local_3 = (D_00DE68F8 >> 1) + D_00E2C424;
	lolo.local_2 = 0;
	lolo.local_4 = 0;
	do {
		D_00E38338[lolo.local_4].f_00 = (float)bp08->f_00;
		D_00E38338[lolo.local_4].f_04 = (float)bp08->f_02;
		D_00E38338[lolo.local_4].f_08 = (float)bp08->f_04;
		C_0066CE40(&D_00E39738, &(D_00E38338[lolo.local_4]), lolo.local_8);
		C_0066CF4D(&D_00E39778, &(D_00E38338[lolo.local_4]), &(D_00E38938[lolo.local_4]));
		bp08 ++;
		lolo.local_2 -= bp0c;
		lolo.local_4 ++;
		//-- "round earth" effect? --
		if(lolo.local_2 > 0) {//else 0075F21C
			lolo.local_10 = lolo.local_2 * (1.0f/64.0f);
			lolo.local_1 += -lolo.local_3;
			if(lolo.local_1 < 0)
				lolo.local_1 = 0 - lolo.local_1;
			lolo.local_9 = lolo.local_1 * (1.0f/32.0f);
			lolo.local_10 += lolo.local_9;
			lolo.local_10 *= lolo.local_10;
			D_00E38338[lolo.local_4 - 2].f_04 -= lolo.local_10;
		}
		//-- --
		lolo.local_2 = C_0075F090(D_00E38938[lolo.local_4 - 1].f_08);
		lolo.local_1 = C_0075F090(lolo.local_8[0] / lolo.local_8[3]);
		lolo.local_2 >>= 2;
	} while(lolo.local_4 < 0x7a);
}

void C_0075F263() {
	struct {
		float local_16;
		float local_15;
		float local_14;
		int local_13;
		int local_12;
		int local_11;
		int local_10;
		int local_9;
		int local_8;
		int local_7;
		int local_6;
		int local_5;
		int local_4;
		int local_3;
		int local_2;
		int local_1;
	}lolo;

	lolo.local_13 = 0;
	lolo.local_1 = D_00E2C424;
	lolo.local_3 = D_00E2C428;
	lolo.local_2 = D_00DE68F8 + D_00E2C424;
	lolo.local_4 = D_00DE67E8 + D_00E2C428;
	C_0066CE40(&D_00E39738, &(D_00E38338[lolo.local_13]), D_00E38F38[lolo.local_13]);
	C_0066CE40(&D_00E39738, &(D_00E38338[lolo.local_13 + 1]), D_00E38F38[lolo.local_13 + 1]);
	C_0066CE40(&D_00E39738, &(D_00E38338[lolo.local_13 + 2]), D_00E38F38[lolo.local_13 + 2]);
	for(lolo.local_11 = 0x29, lolo.local_13 = 3; lolo.local_11 > 0; lolo.local_11 --, lolo.local_13 += 3) {
		C_0066CE40(&D_00E39738, &(D_00E38338[lolo.local_13]), D_00E38F38[lolo.local_13]);
		C_0066CE40(&D_00E39738, &(D_00E38338[lolo.local_13 + 1]), D_00E38F38[lolo.local_13 + 1]);
		C_0066CE40(&D_00E39738, &(D_00E38338[lolo.local_13 + 2]), D_00E38F38[lolo.local_13 + 2]);
		lolo.local_14 = 1.0f / D_00E38F38[lolo.local_13 - 3][3];
		lolo.local_15 = 1.0f / D_00E38F38[lolo.local_13 - 2][3];
		lolo.local_16 = 1.0f / D_00E38F38[lolo.local_13 - 1][3];
		D_00E38938[lolo.local_13 - 3].f_00 = D_00E38F38[lolo.local_13 - 3][0] * lolo.local_14;
		D_00E38938[lolo.local_13 - 3].f_04 = D_00E38F38[lolo.local_13 - 3][1] * lolo.local_14;
		D_00E38938[lolo.local_13 - 2].f_00 = D_00E38F38[lolo.local_13 - 2][0] * lolo.local_15;
		D_00E38938[lolo.local_13 - 2].f_04 = D_00E38F38[lolo.local_13 - 2][1] * lolo.local_15;
		D_00E38938[lolo.local_13 - 1].f_00 = D_00E38F38[lolo.local_13 - 1][0] * lolo.local_16;
		D_00E38938[lolo.local_13 - 1].f_04 = D_00E38F38[lolo.local_13 - 1][1] * lolo.local_16;
		lolo.local_5 = C_0075F090(D_00E38938[lolo.local_13 - 3].f_00);
		lolo.local_9 = C_0075F090(D_00E38938[lolo.local_13 - 3].f_04);
		lolo.local_6 = C_0075F090(D_00E38938[lolo.local_13 - 2].f_00);
		lolo.local_10 = C_0075F090(D_00E38938[lolo.local_13 - 2].f_04);
		lolo.local_8 = C_0075F090(D_00E38938[lolo.local_13 - 1].f_00);
		lolo.local_12 = C_0075F090(D_00E38938[lolo.local_13 - 1].f_04);
		D_00E397B8[lolo.local_13 - 3] = (lolo.local_5 < lolo.local_2) & (lolo.local_5 >= lolo.local_1);
		lolo.local_7 = (lolo.local_9 < lolo.local_4) & (lolo.local_9 >= lolo.local_3);
		D_00E397B8[lolo.local_13 - 3] |= lolo.local_7 << 8;
		D_00E397B8[lolo.local_13 - 2] = (lolo.local_6 < lolo.local_2) & (lolo.local_6 >= lolo.local_1);
		lolo.local_7 = (lolo.local_10 < lolo.local_4) & (lolo.local_10 >= lolo.local_3);
		D_00E397B8[lolo.local_13 - 2] |= lolo.local_7 << 8;
		D_00E397B8[lolo.local_13 - 1] = (lolo.local_8 < lolo.local_2) & (lolo.local_8 >= lolo.local_1);
		lolo.local_7 = (lolo.local_12 < lolo.local_4) & (lolo.local_12 >= lolo.local_3);
		D_00E397B8[lolo.local_13 - 1] |= lolo.local_7 << 8;
	}
}

float C_00760CC4(struct t_g_drv_0c *, struct t_g_drv_0c *, struct t_g_drv_0c *);
void C_00760D1B(float *, float *, float*, int *, int *, int *);

void C_0075F68C(struct t_wm_local_0c *bp08, struct t_wm_local_0c *bp0c, struct SVECTOR *bp10, struct POLY_GT3 *bp14) {
	struct {
		//bp_100 and above for compiler
		struct t_dx_rend_vertex_20 *bp_fc;
		float bp_f8;
		struct t_dx_rend_vertex_20 *bp_f4;
		float bp_f0;
		struct t_dx_rend_vertex_20 *bp_ec;
		float bp_e8;
		tRGBA vcolor_0;//bp_e4
		unsigned char bp_e0; char _p_e0[3];
		int bp_dc;//check
		tRGBA vcolor_2;//bp_d8
		float bp_d4;
		unsigned char bp_d0; char _p_d0[3];
		tRGBA vcolor_1;//bp_cc
		struct fBGRA bp_c8[3];
		float bp_98;
		unsigned char bp_94; char _p_94[3];
		float v_2;//bp_90
		float bp_8c;
		struct SVECTOR *bp_88;
		int bp_84;
		float v_1;//bp_80
		struct t_g_drv_0c bp_7c;
		int bp_70;
		struct SVECTOR *bp_6c;
		unsigned char bp_68; char _p_68[3];
		float v_0;//bp_64
		struct t_g_drv_0c bp_60;
		float bp_54;
		struct SVECTOR *bp_50;
		unsigned bp_4c;
		int bp_48;
		int bp_44;
		struct t_g_drv_0c bp_40;
		float u_2;//bp_34
		float u_1;//bp_30
		float bp_2c;
		float bp_28;
		float u_0;//bp_24
		tBGRA bp_20[3];
		int *bp_14;
		int bp_10;
		int bp_0c;
		int bp_08;
		struct t_wm_local_0c *bp_04;
	}lolo;

	lolo.bp_08 = 0;
	lolo.bp_20[0].bgra = lolo.bp_20[1].bgra = lolo.bp_20[2].bgra = 0xffffffff;
	lolo.bp_c8[0].r = lolo.bp_c8[1].r = lolo.bp_c8[2].r = 255.0f;
	lolo.bp_c8[0].g = lolo.bp_c8[1].g = lolo.bp_c8[2].g = 255.0f;
	lolo.bp_c8[0].b = lolo.bp_c8[1].b = lolo.bp_c8[2].b = 255.0f;
	lolo.bp_c8[0].a = lolo.bp_c8[1].a = lolo.bp_c8[2].a = 255.0f;
	lolo.bp_54 = (float)/*lolo.bp_104/lolo.bp_100*/((D_00DE68F8 >> 1) + D_00E2C424);
	lolo.bp_04 = bp08;
	do {
		lolo.bp_70 = D_00E397B8[lolo.bp_04->f_00] | D_00E397B8[lolo.bp_04->f_01] | D_00E397B8[lolo.bp_04->f_02];
		if(!(lolo.bp_70 & 0xff) | !(lolo.bp_70 & 0xff00))
			goto C_00760803;//through 00760858
		//-- --
		lolo.bp_8c = D_00E38938[lolo.bp_04->f_00].f_08 - D_00E38938[lolo.bp_04->f_01].f_08;
		lolo.bp_28 = D_00E38938[lolo.bp_04->f_02].f_08;
		lolo.bp_2c = C_00760CC4(&(D_00E38938[lolo.bp_04->f_00]), &(D_00E38938[lolo.bp_04->f_01]), &(D_00E38938[lolo.bp_04->f_02]));
		if(D_00E36110 == 0)
			goto C_0075F866;//00760853
		if(D_00E36110 - lolo.bp_04)
			goto C_0075F866;//0076084E
		D_00E36110 = 0;
C_0075F866:
		//-- --
		lolo.bp_98 = D_00E38938[lolo.bp_04->f_00].f_08 - D_00E38938[lolo.bp_04->f_02].f_08;
		lolo.bp_50 = &(bp10[lolo.bp_04->f_00]);
		if(C_0075F090(lolo.bp_2c) < 0)
			goto C_00760803;//0076084C
		lolo.bp_6c = &(bp10[lolo.bp_04->f_01]);
		if(C_0075F090(lolo.bp_8c) < 0)
			goto C_0075F91F;//00760847
		lolo.bp_88 = &(bp10[lolo.bp_04->f_02]);
		if(C_0075F090(lolo.bp_98) < 0)
			goto C_0075F987;//00760842
		lolo.bp_28 = D_00E38938[lolo.bp_04->f_00].f_08;
		goto C_0075F987;//0076083D
C_0075F91F:
		lolo.bp_d4 = D_00E38938[lolo.bp_04->f_01].f_08 - D_00E38938[lolo.bp_04->f_02].f_08;
		lolo.bp_88 = &(bp10[lolo.bp_04->f_02]);
		if(C_0075F090(lolo.bp_d4) < 0)
			goto C_0075F987;//00760838
		lolo.bp_28 = D_00E38938[lolo.bp_04->f_01].f_08;
C_0075F987:
		lolo.bp_10 = C_0075F090(lolo.bp_28) - D_00E37D28;
		if(lolo.bp_10 > 0)
			goto C_0075FD4D;//00760833
		lolo.bp_94 = /*lolo.bp_108*/D_00E38938[lolo.bp_04->f_00].f_00 < lolo.bp_54;
		lolo.bp_d0 = /*lolo.bp_10c*/lolo.bp_54 < D_00E38938[lolo.bp_04->f_00].f_00;

		lolo.bp_68 = /*lolo.bp_110*/D_00E38938[lolo.bp_04->f_01].f_00 < lolo.bp_54;
		lolo.bp_e0 = /*lolo.bp_114*/lolo.bp_54 < D_00E38938[lolo.bp_04->f_01].f_00;
		lolo.bp_94 |= lolo.bp_68;
		lolo.bp_d0 |= lolo.bp_e0;

		lolo.bp_68 = /*lolo.bp_118*/D_00E38938[lolo.bp_04->f_02].f_00 < lolo.bp_54;
		lolo.bp_e0 = /*lolo.bp_11c*/lolo.bp_54 < D_00E38938[lolo.bp_04->f_02].f_00;
		lolo.bp_94 |= lolo.bp_68;
		lolo.bp_d0 |= lolo.bp_e0;

		lolo.bp_94 &= lolo.bp_d0;
		if(lolo.bp_94 == 0)
			goto C_0075FD4D;//0076082E
		lolo.bp_94 = /*lolo.bp_120*/D_00E38938[lolo.bp_04->f_00].f_04 < lolo.bp_54;
		lolo.bp_d0 = /*lolo.bp_124*/lolo.bp_54 < D_00E38938[lolo.bp_04->f_00].f_04;

		lolo.bp_68 = /*lolo.bp_128*/D_00E38938[lolo.bp_04->f_01].f_04 < lolo.bp_54;
		lolo.bp_e0 = /*lolo.bp_12c*/lolo.bp_54 < D_00E38938[lolo.bp_04->f_01].f_04;
		lolo.bp_94 |= lolo.bp_68;
		lolo.bp_d0 |= lolo.bp_e0;

		lolo.bp_68 = /*lolo.bp_130*/D_00E38938[lolo.bp_04->f_02].f_04 < lolo.bp_54;
		lolo.bp_e0 = /*lolo.bp_134*/lolo.bp_54 < D_00E38938[lolo.bp_04->f_02].f_04;
		lolo.bp_94 |= lolo.bp_68;
		lolo.bp_d0 |= lolo.bp_e0;

		lolo.bp_94 &= lolo.bp_d0;
		if(lolo.bp_94 == 0)
			goto C_0075FD4D;//00760829
		D_00E37520 = 1;
C_0075FD4D:
		if(C_0075F090(D_00E38F38[lolo.bp_04->f_00][3]) > 0 && C_0075F090(D_00E38F38[lolo.bp_04->f_01][3]) > 0 && C_0075F090(D_00E38F38[lolo.bp_04->f_02][3]) > 0) {//else 007607FA
			lolo.bp_4c = 0;
			if(D_00E37524 == 0)
				goto C_00760243;//00760824
			C_00760D1B(&(D_00E38938[lolo.bp_04->f_00].f_08), &(D_00E38938[lolo.bp_04->f_01].f_08), &(D_00E38938[lolo.bp_04->f_02].f_08), &lolo.bp_48, &lolo.bp_44, &lolo.bp_dc);
			lolo.bp_20[lolo.bp_48].bgra = D_00E2B778[0].rgba;
			lolo.bp_20[lolo.bp_44].bgra = D_00E2B778[4].rgba;
			lolo.bp_20[lolo.bp_dc].bgra = D_00E2B778[8].rgba;
			lolo.bp_c8[lolo.bp_48].r = D_00E28F40[0].r;
			lolo.bp_c8[lolo.bp_44].r = D_00E28F40[4].r;
			lolo.bp_c8[lolo.bp_dc].r = D_00E28F40[8].r;
			lolo.bp_c8[lolo.bp_48].g = D_00E28F40[0].g;
			lolo.bp_c8[lolo.bp_44].g = D_00E28F40[4].g;
			lolo.bp_c8[lolo.bp_dc].g = D_00E28F40[8].g;
			lolo.bp_c8[lolo.bp_48].b = D_00E28F40[0].b;
			lolo.bp_c8[lolo.bp_44].b = D_00E28F40[4].b;
			lolo.bp_c8[lolo.bp_dc].b = D_00E28F40[8].b;
			lolo.bp_c8[0].a =
			lolo.bp_c8[1].a =
			lolo.bp_c8[2].a = 255.0f;
//0075FF0E
			lolo.bp_10 = C_0075F090(lolo.bp_28) - D_00E37524;
			if(lolo.bp_10 <= 0)
				goto C_00760243;//0076081F
			lolo.bp_10 = (unsigned)lolo.bp_10 >> 3;
			lolo.bp_10 &= 0xffc0;
			lolo.bp_4c = lolo.bp_10;
			lolo.bp_0c = (lolo.bp_4c + 0x40) >> 2;
			lolo.bp_20[lolo.bp_48].bgra = D_00E2B778[lolo.bp_0c - 8].rgba;
			lolo.bp_20[lolo.bp_44].bgra = D_00E2B778[lolo.bp_0c - 4].rgba;
			lolo.bp_20[lolo.bp_dc].bgra = D_00E2B778[lolo.bp_0c].rgba;

			lolo.bp_c8[lolo.bp_48].b = D_00E28F40[lolo.bp_0c - 8].b;
			lolo.bp_c8[lolo.bp_48].g = D_00E28F40[lolo.bp_0c - 4].g;
			lolo.bp_c8[lolo.bp_48].r = D_00E28F40[lolo.bp_0c].r;
			lolo.bp_c8[lolo.bp_48].a = 255.0f;

			lolo.bp_c8[lolo.bp_44].b = D_00E28F40[lolo.bp_0c - 8].b;
			lolo.bp_c8[lolo.bp_44].g = D_00E28F40[lolo.bp_0c - 4].g;
			lolo.bp_c8[lolo.bp_44].r = D_00E28F40[lolo.bp_0c].r;
			lolo.bp_c8[lolo.bp_44].a = 255.0f;

			lolo.bp_c8[lolo.bp_dc].b = D_00E28F40[lolo.bp_0c - 8].b;
			lolo.bp_c8[lolo.bp_dc].g = D_00E28F40[lolo.bp_0c - 4].g;
			lolo.bp_c8[lolo.bp_dc].r = D_00E28F40[lolo.bp_0c].r;
			lolo.bp_c8[lolo.bp_dc].a = 255.0f;

			lolo.bp_10 -= 0x3c0;
			if(lolo.bp_10 <= 0)
				goto C_00760243;//0076081A
			lolo.bp_4c = 0xff;
			lolo.bp_20[lolo.bp_48].bgra = D_00E2B778[lolo.bp_4c - 8].rgba;
			lolo.bp_20[lolo.bp_44].bgra = D_00E2B778[lolo.bp_4c - 4].rgba;
			lolo.bp_20[lolo.bp_dc].bgra = D_00E2B778[lolo.bp_4c].rgba;

			lolo.bp_c8[lolo.bp_48].b = D_00E28F40[lolo.bp_4c - 8].b;
			lolo.bp_c8[lolo.bp_48].g = D_00E28F40[lolo.bp_4c - 4].g;
			lolo.bp_c8[lolo.bp_48].r = D_00E28F40[lolo.bp_4c].r;
			lolo.bp_c8[lolo.bp_48].a = 255.0f;

			lolo.bp_c8[lolo.bp_44].b = D_00E28F40[lolo.bp_4c - 8].b;
			lolo.bp_c8[lolo.bp_44].g = D_00E28F40[lolo.bp_4c - 4].g;
			lolo.bp_c8[lolo.bp_44].r = D_00E28F40[lolo.bp_4c].r;
			lolo.bp_c8[lolo.bp_44].a = 255.0f;

			lolo.bp_c8[lolo.bp_dc].b = D_00E28F40[lolo.bp_4c - 8].b;
			lolo.bp_c8[lolo.bp_dc].g = D_00E28F40[lolo.bp_4c - 4].g;
			lolo.bp_c8[lolo.bp_dc].r = D_00E28F40[lolo.bp_4c].r;
			lolo.bp_c8[lolo.bp_dc].a = 255.0f;
C_00760243:
			lolo.bp_14 = (int *)&(lolo.bp_04->f_08);
			lolo.bp_84 = *lolo.bp_14;
			lolo.bp_84 >>= 0xe;
			lolo.bp_84 &= 0x7fc;
			lolo.bp_84 >>= 2;
			if(C_0074C969()) {//get "isRendering"?//else 007607FA
				//====---- terrain triangle rendering? ----====
				if(C_0066E272(1, D_00E2BBD8[lolo.bp_84])) {//else 007607FA
					lolo.u_0 = (float)/*lolo.bp_138*/(lolo.bp_04->f_04 - D_00E2D168[lolo.bp_84].f_00) * D_00E2BBD8[lolo.bp_84]->f_24;
					lolo.v_0 = (float)/*lolo.bp_13c*/(lolo.bp_04->f_05 - D_00E2D168[lolo.bp_84].f_02) * D_00E2BBD8[lolo.bp_84]->f_28;
					lolo.u_1 = (float)/*lolo.bp_140*/(lolo.bp_04->f_06 - D_00E2D168[lolo.bp_84].f_00) * D_00E2BBD8[lolo.bp_84]->f_24;
					lolo.v_1 = (float)/*lolo.bp_144*/(lolo.bp_04->f_07 - D_00E2D168[lolo.bp_84].f_02) * D_00E2BBD8[lolo.bp_84]->f_28;
					lolo.u_2 = (float)/*lolo.bp_148*/(lolo.bp_04->f_08 - D_00E2D168[lolo.bp_84].f_00) * D_00E2BBD8[lolo.bp_84]->f_24;
					lolo.v_2 = (float)/*lolo.bp_14c*/(lolo.bp_04->f_09 - D_00E2D168[lolo.bp_84].f_02) * D_00E2BBD8[lolo.bp_84]->f_28;

					lolo.bp_40.f_00 = (float)/*lolo.bp_150*/lolo.bp_50->f_00 * (1.0f/4096.0f);
					lolo.bp_40.f_04 = (float)/*lolo.bp_154*/lolo.bp_50->f_02 * (1.0f/4096.0f);
					lolo.bp_40.f_08 = (float)/*lolo.bp_158*/lolo.bp_50->f_04 * (1.0f/4096.0f);

					lolo.bp_60.f_00 = (float)/*lolo.bp_15c*/lolo.bp_6c->f_00 * (1.0f/4096.0f);
					lolo.bp_60.f_04 = (float)/*lolo.bp_160*/lolo.bp_6c->f_02 * (1.0f/4096.0f);
					lolo.bp_60.f_08 = (float)/*lolo.bp_164*/lolo.bp_6c->f_04 * (1.0f/4096.0f);

					lolo.bp_7c.f_00 = (float)/*lolo.bp_168*/lolo.bp_88->f_00 * (1.0f/4096.0f);
					lolo.bp_7c.f_04 = (float)/*lolo.bp_16c*/lolo.bp_88->f_02 * (1.0f/4096.0f);
					lolo.bp_7c.f_08 = (float)/*lolo.bp_170*/lolo.bp_88->f_04 * (1.0f/4096.0f);

					C_0068DAE1(&(D_00E360F4->f_0f8), &lolo.bp_40, &(lolo.bp_c8[0]), &(lolo.bp_20[0]), &lolo.vcolor_0);//compute light at vertex(1)?
					C_0068DAE1(&(D_00E360F4->f_0f8), &lolo.bp_60, &(lolo.bp_c8[1]), &(lolo.bp_20[1]), &lolo.vcolor_1);//compute light at vertex(1)?
					C_0068DAE1(&(D_00E360F4->f_0f8), &lolo.bp_7c, &(lolo.bp_c8[2]), &(lolo.bp_20[2]), &lolo.vcolor_2);//compute light at vertex(1)?

					lolo.bp_e8 = 1.0f / D_00E38F38[lolo.bp_04->f_00][3];
					MK_VERTEX_0(&(D_00E2BBD8[lolo.bp_84]->f_70.asVertex[0]), lolo.bp_ec, D_00E38F38[lolo.bp_04->f_00][0] * lolo.bp_e8, D_00E38F38[lolo.bp_04->f_00][1] * lolo.bp_e8, D_00E38F38[lolo.bp_04->f_00][2] * lolo.bp_e8, lolo.bp_e8, lolo.vcolor_0.rgba, lolo.u_0, lolo.v_0);
					lolo.bp_f0 = 1.0f / D_00E38F38[lolo.bp_04->f_01][3];
					MK_VERTEX_0(&(D_00E2BBD8[lolo.bp_84]->f_70.asVertex[1]), lolo.bp_f4, D_00E38F38[lolo.bp_04->f_01][0] * lolo.bp_f0, D_00E38F38[lolo.bp_04->f_01][1] * lolo.bp_f0, D_00E38F38[lolo.bp_04->f_01][2] * lolo.bp_f0, lolo.bp_f0, lolo.vcolor_1.rgba, lolo.u_1, lolo.v_1);
					lolo.bp_f8 = 1.0f / D_00E38F38[lolo.bp_04->f_02][3];
					MK_VERTEX_0(&(D_00E2BBD8[lolo.bp_84]->f_70.asVertex[2]), lolo.bp_fc, D_00E38F38[lolo.bp_04->f_02][0] * lolo.bp_f8, D_00E38F38[lolo.bp_04->f_02][1] * lolo.bp_f8, D_00E38F38[lolo.bp_04->f_02][2] * lolo.bp_f8, lolo.bp_f8, lolo.vcolor_2.rgba, lolo.u_2, lolo.v_2);
				}
			}
		}
//007607FA
		bp14 ++;
C_00760803:
		lolo.bp_04 ++;
	} while(lolo.bp_04 != bp0c);
}

void C_00760C64(float *, float *, float *);

int C_0076085F(struct t_wm_local_0c *bp08, struct SVECTOR *bp0c, int *bp10) {
	struct {
		//local_17 and above for compiler
		float local_16[3];
		float local_13;
		float local_12;
		float local_11;
		float local_10;
		float local_9[3];
		float local_6;
		float local_5;
		float local_4;
		float local_3[3];
	}lolo;

	lolo.local_6 = /*lolo.local_17*/(float)bp0c->f_00;
	lolo.local_5 = /*lolo.local_18*/(float)bp0c->f_02;
	lolo.local_4 = /*lolo.local_19*/(float)bp0c->f_04;
	lolo.local_16[1] =
	lolo.local_3[1] = 0;
	lolo.local_16[0] = D_00E38338[bp08->f_01].f_00 - D_00E38338[bp08->f_00].f_00;
	lolo.local_16[2] = D_00E38338[bp08->f_01].f_08 - D_00E38338[bp08->f_00].f_08;
	lolo.local_3[2] = lolo.local_4 - D_00E38338[bp08->f_00].f_08;
	lolo.local_3[0] = lolo.local_6 - D_00E38338[bp08->f_00].f_00;
	lolo.local_9[1] = lolo.local_16[2] * lolo.local_3[0] - lolo.local_16[0] * lolo.local_3[2];
	if(C_0075F090(lolo.local_9[1]) > 0)
		goto C_00760C52;//00760C5E
	lolo.local_16[0] = D_00E38338[bp08->f_02].f_00 - D_00E38338[bp08->f_01].f_00;
	lolo.local_16[2] = D_00E38338[bp08->f_02].f_08 - D_00E38338[bp08->f_01].f_08;
	lolo.local_3[2] = lolo.local_4 - D_00E38338[bp08->f_01].f_08;
	lolo.local_3[0] = lolo.local_6 - D_00E38338[bp08->f_01].f_00;
	lolo.local_9[1] = lolo.local_16[2] * lolo.local_3[0] - lolo.local_16[0] * lolo.local_3[2];
	if(C_0075F090(lolo.local_9[1]) > 0)
		goto C_00760C52;//00760C5C
	lolo.local_16[0] = D_00E38338[bp08->f_00].f_00 - D_00E38338[bp08->f_02].f_00;
	lolo.local_16[2] = D_00E38338[bp08->f_00].f_08 - D_00E38338[bp08->f_02].f_08;
	lolo.local_3[2] = lolo.local_4 - D_00E38338[bp08->f_02].f_08;
	lolo.local_3[0] = lolo.local_6 - D_00E38338[bp08->f_02].f_00;
	lolo.local_9[1] = lolo.local_16[2] * lolo.local_3[0] - lolo.local_16[0] * lolo.local_3[2];
	if(C_0075F090(lolo.local_9[1]) > 0)
		goto C_00760C52;//00760C5A
	lolo.local_16[0] = D_00E38338[bp08->f_01].f_00 - D_00E38338[bp08->f_00].f_00;
	lolo.local_16[1] = D_00E38338[bp08->f_01].f_04 - D_00E38338[bp08->f_00].f_04;
	lolo.local_3[0] = D_00E38338[bp08->f_02].f_00 - D_00E38338[bp08->f_00].f_00;
	lolo.local_3[1] = D_00E38338[bp08->f_02].f_04 - D_00E38338[bp08->f_00].f_04;
	lolo.local_16[2] = D_00E38338[bp08->f_01].f_08 - D_00E38338[bp08->f_00].f_08;
	lolo.local_3[2] = D_00E38338[bp08->f_02].f_08 - D_00E38338[bp08->f_00].f_08;
	C_00760C64(lolo.local_16, lolo.local_3, lolo.local_9);
	lolo.local_9[1] *= (1.0f/256.0f);
	if(C_0075F090(lolo.local_9[1]) == 0)
		goto C_00760BFC;//00760C58
	lolo.local_10 = lolo.local_9[1] * D_00E38338[bp08->f_00].f_04;
	lolo.local_9[0] *= 1.0f/256.0f;
	lolo.local_11 = D_00E38338[bp08->f_00].f_00 - lolo.local_6;
	lolo.local_11 *= lolo.local_9[0];
	lolo.local_9[2] *= 1.0f/256.0f;
	lolo.local_12 = D_00E38338[bp08->f_00].f_08 - lolo.local_4;
	lolo.local_12 *= lolo.local_9[2];
	lolo.local_10 += lolo.local_11 + lolo.local_12;
	lolo.local_13 = lolo.local_10 / lolo.local_9[1];
	goto C_00760C3A;//00760C56
C_00760BFC:
	lolo.local_10 = D_00E38338[bp08->f_00].f_04 + D_00E38338[bp08->f_01].f_04 + D_00E38338[bp08->f_02].f_04;
	lolo.local_13 = lolo.local_10 * (1.0f/3.0f);

C_00760C3A:
	*bp10 = C_0075F090(lolo.local_13);
	return 1;

C_00760C52:
	return 0;
}

void C_00760C64(float *bp08, float *bp0c, float *bp10) {
	bp10[0] = bp08[1] * bp0c[2] - bp08[2] * bp0c[1];
	bp10[1] = bp08[2] * bp0c[0] - bp08[0] * bp0c[2];
	bp10[2] = bp08[0] * bp0c[1] - bp08[1] * bp0c[0];
}

float C_00760CC4(struct t_g_drv_0c *bp08, struct t_g_drv_0c *bp0c, struct t_g_drv_0c *bp10) {
	float local_1 =
		bp08->f_00 * bp0c->f_04 + bp0c->f_00 * bp10->f_04 + bp10->f_00 * bp08->f_04 -
		bp08->f_00 * bp10->f_04 - bp0c->f_00 * bp08->f_04 - bp10->f_00 * bp0c->f_04
	;
	return local_1;
}

void C_00760D1B(float *bp08, float *bp0c, float *bp10, int *bp14, int *bp18, int *bp1c) {
	struct {
		int local_5;
		float local_4[2];
		float local_2;
		int local_1;
	}lolo;

	lolo.local_4[0] = *bp08;
	lolo.local_4[1] = *bp0c;
	lolo.local_2 = *bp10;
	lolo.local_5 = /*lolo.local_6*/lolo.local_4[0] < lolo.local_4[1];
	lolo.local_1 = /*lolo.local_7*/lolo.local_4[lolo.local_5] < lolo.local_2?2:lolo.local_5;
	if(lolo.local_1) {//else 00760DDD
		*bp1c = lolo.local_1;
		if(lolo.local_1 == 1)
			lolo.local_5 = 2;
		else
			lolo.local_5 = 1;
		if(lolo.local_4[0] < lolo.local_4[lolo.local_5]) {
			*bp14 = 0;
			*bp18 = lolo.local_5;
		} else {
			*bp14 = lolo.local_5;
			*bp18 = 0;
		}
	} else {
		*bp1c = 0;
		if(lolo.local_4[1] < lolo.local_2) {
			*bp14 = 1;
			*bp18 = 2;
		} else {
			*bp14 = 2;
			*bp18 = 1;
		}
	}
}

void C_00760E1D(struct t_wm_local_0c *bp08, struct t_wm_local_0c *bp0c, int bp10) {
	struct {
		int local_3;
		int local_2;
		struct t_wm_local_0c *local_1;
	}lolo;

	lolo.local_1 = bp08;
	while(lolo.local_1 != bp0c) {
		lolo.local_2 = (lolo.local_1->f_04 + lolo.local_1->f_06 + lolo.local_1->f_08) / 3;
		lolo.local_3 = (lolo.local_1->f_05 + lolo.local_1->f_07 + lolo.local_1->f_09) / 3;

		if(lolo.local_2 < lolo.local_1->f_04)
			lolo.local_1->f_04 -= bp10;
		else
			lolo.local_1->f_04 += bp10;
		if(lolo.local_2 < lolo.local_1->f_06)
			lolo.local_1->f_06 -= bp10;
		else
			lolo.local_1->f_06 += bp10;
		if(lolo.local_2 < lolo.local_1->f_08)
			lolo.local_1->f_08 -= bp10;
		else
			lolo.local_1->f_08 += bp10;

		if(lolo.local_3 < lolo.local_1->f_05)
			lolo.local_1->f_05 -= bp10;
		else
			lolo.local_1->f_05 += bp10;
		if(lolo.local_3 < lolo.local_1->f_07)
			lolo.local_1->f_07 -= bp10;
		else
			lolo.local_1->f_07 += bp10;
		if(lolo.local_3 < lolo.local_1->f_09)
			lolo.local_1->f_09 -= bp10;
		else
			lolo.local_1->f_09 += bp10;
		lolo.local_1 ++;
	}
}
