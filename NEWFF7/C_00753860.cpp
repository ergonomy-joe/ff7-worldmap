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
struct USVECTOR {
	unsigned short f_00;
	unsigned short f_02;
	unsigned short f_04;
	unsigned short f_06;
};

struct t_wm_local_14 {
	short f_00;
	short f_02;
	short f_04;
	short f_06;
	char f_08[0xc];
};

struct t_wm_local_24 {
	struct VECTOR f_00;
	unsigned char f_10,f_11,f_12;
	unsigned char f_13;
	unsigned char f_14,f_15,f_16;
char __17;
	unsigned char f_18,f_19,f_1a;
char __1b;
	int f_1c;
	tRGBA f_20;
};

struct t_wm_local_0c_qqq {
	struct t_wm_local_18 *f_00;
	struct t_wm_local_0c *f_04;
	unsigned char f_08;
	char __9[3];
};
////////////////////////////////////////
//sky related info ?
unsigned char D_00969B58[] = {0x00,0x00,0xFF,0x00};
unsigned char D_00969B5C[] = {0xFA,0xFF,0xFF,0x00};
struct t_wm_vertexinfo D_00969B60 = {
	{0,0,0,0},
	0,0,0,0, 0x0000, 0x0000,
	0,0,0,0, 0x0140, 0x0000,
	0,0,0,0, 0x0000, 0x00B4,
	0,0,0,0, 0x0140, 0x00B4,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000
};
//00969B94  00 00 00 00
struct t_wm_local_30 D_00969B98 = {
	{
		{0},
		0x80,0x80,0x80,
		0,
		0x0000,0x0000, 0x00,0x00, 0x7ACF,
		0x0000,0x0000, 0x8F,0x00, 0,
		0x0000,0x0000, 0x00,0x3F, 0,
		0x0000,0x0000, 0x8F,0x3F, 0,
	},
	0,
	0x80FFFFFF
};
unsigned char __00969BC8[] = {
	0x00,0xF0,0x00,0xF0,0x00,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
struct MATRIX D_00969C08 = {
	{
		0x6EE,0,0,
		0x6EE,0,0,
		0x6EE,0,0,
	},
	{0,0,0}
};
//00 00
int D_00969C28[] = {0x00,0x20,0x30,0x40,0x50,0x58,0x60,0x64,0x68,0x6C,0x70,0x74,0x78,0x7C,0x7E,0x7F};
int D_00969C68[] = {0x80,0x60,0x50,0x40,0x30,0x28,0x20,0x1C,0x18,0x14,0x10,0x0C,0x08,0x04,0x02,0x01};
struct t_wm_local_14 D_00969CA8[] = {
	{0x1464,0x109A,0x0190,0x0000,{0x5C,0x5B,0x60,0x5F,0x5E,0x5D,0x56,0x55,0x59,0x5A,0x57,0x58}},
	{0x0FAB,0x0BBD,0x03E8,0x0000,{0x64,0x63,0x67,0x68,0x66,0x65,0x5E,0x5D,0x61,0x62,0x5F,0x60}},
	{0x0E93,0x0E9E,0x0064,0x0000,{0x66,0x65,0x68,0x67,0x61,0x62,0x60,0x5F,0x63,0x64,0x69,0x6A}}
};
//00969CE4  00 00 00 00
////////////////////////////////////////
struct t_wm_local_24 D_00E28CE0[0x10];
int D_00E28F20;
short D_00E28F24;
struct t_wm_local_0c_qqq *D_00E28F28[3];
//00E28F34
struct SVECTOR D_00E28F38;
struct fBGRA D_00E28F40[0x400];//or 0x100?
int D_00E29F40;
int D_00E29F44;
short D_00E29F48;
struct VECTOR D_00E29F50[3];
struct USVECTOR D_00E29F80[0x30];
int D_00E2A100[3];
short D_00E2A10C;
int D_00E2A110;
int D_00E2A114;
short D_00E2A118;
//00E2A11C
int D_00E2A120[3];
int D_00E2A12C;
//00E2A130
int D_00E2A134;
int D_00E2A138;
int D_00E2A13C;
int D_00E2A140;
//00E2A144
struct t_wm_local_08 D_00E2A148[6];
struct t_wm_local_0c_qqq *D_00E2A178;
//00E2A17C
int D_00E2A180[3];
struct USVECTOR *D_00E2A18C;
struct t_wm_local_0c_qqq D_00E2A190[0x28];
struct t_wm_local_30 D_00E2A370[2][3];//or 1?
struct t_wm_local_30 D_00E2A490[0xc];
short D_00E2A6D0;
//00E2A6D4
unsigned char D_00E2A6D8[3][2];
int D_00E2A6E0[0x100];
short D_00E2AAE0;
int D_00E2AAE4;
struct t_wm_local_18 *D_00E2AAE8[0x14];
int D_00E2AB38;
int D_00E2AB3C;
int D_00E2AB40[3];
short D_00E2AB50[0x400];
short D_00E2B350[0x100];
unsigned char D_00E2B550[0x209];
short D_00E2B75C;
int D_00E2B760;
int D_00E2B764;
int D_00E2B768[3];
//00E2B774
tRGBA D_00E2B778[0x100];
short D_00E2BB78;
struct t_wm_local_18 **D_00E2BB7C;
short D_00E2BB80;
int D_00E2BB84;
int D_00E2BB88;
short D_00E2BB8C;
struct t_wm_local_0c_qqq *D_00E2BB90;
struct t_wm_local_24 *D_00E2BB94;
int D_00E2BB98[3];
int D_00E2BBA4;
int D_00E2BBA8;
//00E2BBAC
int D_00E2BBB0[3];
short D_00E2BBBC;
int D_00E2BBC0;
int D_00E2BBC4;
int D_00E2BBC8;
//00E2BBCC
////////////////////////////////////////
//fade in/out related(1)?
void C_00753860() {
	D_00E2BBC0 = 1;
	D_00E2BBC4 = 0;
}

//fade in/out related(2)?
void C_00753879() {
	D_00E2BBC0 = 0;
}

//fade in/out related(3)?
void C_00753888() {
	D_00E2BBC8 = 1;
	C_00753860();//fade in/out related(1)?
}

//fade in/out related(4)?
void C_0075389C() {
	D_00E2BBC8 = 0;
	C_00753879();//fade in/out related(2)?
}

//get fade in/out info?
int C_007538B0() {
	return D_00E2BBC8;
}

void C_007538BA() {
	D_00E2BB84 = 0;
}

#define BIT_ISSET(v,b) ((v) & (1 << (b)))
#define BIT_SOMETEST(v,b) ((v) & ~((1 << (b)) - 1))

int C_007538C9(short bp08) {
	if(BIT_ISSET(D_00E2BB84, bp08) && !BIT_SOMETEST(D_00E2BB84, bp08 + 1))
		return 1;
	if((1 << bp08) > D_00E2BB84) {
		if(D_00E2BB84 == 1)
			C_007506C0();
		else if(D_00E2BB84 & 4)
			C_00768C3D();
		D_00E2BB84 |= 1 << bp08;

		return 1;
	}

	return 0;
}

void C_0075395E(short bp08) {
	unsigned local_1;

	if(BIT_SOMETEST(D_00E2BB84, bp08 + 1) || !BIT_ISSET(D_00E2BB84, bp08))
		C_0074C9A0(0x50);//<empty>:some error management?
	D_00E2BB84 &= ~(1 << bp08);
	if(bp08) {
		for(local_1 = 1 << (bp08 - 1); local_1 && !(D_00E2BB84 & local_1); local_1 >>= 1);
		if(local_1 == 1)
			C_00750784();
	}
}

void C_00753B73(void);

//wm:randomize
void C_00753A01(int bp08) {
	struct {//x830
		int j;//local_524
		int i;//local_523
		unsigned local_522[0x209];//bp_828
		unsigned local_1;
	}lolo;

	lolo.local_1 = 0;
	for(lolo.i = 0; lolo.i <= 0x10; lolo.i ++) {
		for(lolo.j = 0; lolo.j < 0x20; lolo.j ++) {
			bp08 = bp08 * 0x5D588B65 + 1;
			lolo.local_1 = (lolo.local_1 >> 1) | (bp08 & 0x80000000);
		}
		lolo.local_522[lolo.i] = lolo.local_1;
	}
	lolo.local_522[0x10] = (lolo.local_522[0x10] << 0x17) ^ (lolo.local_522[0] >> 9) ^ lolo.local_522[0xf];
	for(lolo.i = 0x11; lolo.i <= 0x208; lolo.i ++)
		lolo.local_522[lolo.i] = (lolo.local_522[lolo.i - 0x11] << 0x17) ^ (lolo.local_522[lolo.i - 0x10] >> 9) ^ lolo.local_522[lolo.i - 1];
	for(lolo.i = 0; lolo.i < 0x209; lolo.i ++)
		D_00E2B550[lolo.i] = lolo.local_522[lolo.i];
	C_00753B73();
	C_00753B73();
	C_00753B73();
	D_00E2A138 = 0x208;
}

void C_00753B73() {
	int i;

	for(i = 0; i < 0x20; i ++)
		D_00E2B550[i] ^= D_00E2B550[i + 0x1e9];
	for(i = 0x20; i < 0x209; i ++)
		D_00E2B550[i] ^= D_00E2B550[i - 0x20];
}

//wm:random?
int C_00753BE8() {
	if(++ D_00E2A138 >= 0x209) {
		C_00753B73();
		D_00E2A138 = 0;
	}

	return D_00E2B550[D_00E2A138];
}

int C_00753C23(struct VECTOR *bp08, struct VECTOR *bp0c) {
	struct {
		int local_3;
		int local_2;
		int local_1;
	}lolo;

	lolo.local_1 = inline_abs(bp08->f_00 - bp0c->f_00);
	if(lolo.local_1 >= 0x24000)
		lolo.local_1 = 0x48000 - lolo.local_1;
	lolo.local_2 = inline_abs(bp08->f_04 - bp0c->f_04);
	lolo.local_3 = inline_abs(bp08->f_08 - bp0c->f_08);
	if(lolo.local_3 >= 0x1c000)
		lolo.local_3 = 0x38000 - lolo.local_3;

	return lolo.local_1 + lolo.local_2 + lolo.local_3;
}

void C_00753D00(struct SVECTOR *bp08, short bp0c) {
	struct {
		struct VECTOR local_15;
		struct MATRIX local_11;
		int local_3;
		struct SVECTOR local_2;
	}lolo;

	if(bp08) {
		lolo.local_15.f_00 =
		lolo.local_15.f_04 =
		lolo.local_15.f_08 = 0;
		lolo.local_2.f_00 =
		lolo.local_2.f_04 = 0;
		lolo.local_2.f_02 = bp0c;
		C_006628DE(&lolo.local_2, &lolo.local_11);//psx:xyz_rotate(1)
		C_00663673(&lolo.local_11);//psx:SetRotMatrix?
		C_00663766(&lolo.local_11, &lolo.local_15);//psx:set translate vector?
		C_00663707(&lolo.local_11);//psx:SetTransMatrix?
		C_00662ECC(bp08, &lolo.local_15, &lolo.local_3);//psx:RotTrans
		bp08->f_00 = lolo.local_15.f_00;
		bp08->f_02 = lolo.local_15.f_04;
		bp08->f_04 = lolo.local_15.f_08;
	}
}

short C_00753DA9(int bp08, int bp0c) {
	short local_2;
	short local_1;

	local_2 = 0;
	local_1 = 0;
	if(bp08 || bp0c) {//else 00753F26
		if(bp0c >= 0) {//else 00753E71
			if(bp08 >= 0) {//else 00753E20
				local_2 = /*local_3*/(bp08 >= bp0c)?0x400 - D_00E37120[(bp0c << 8) / bp08]:D_00E37120[(bp08 << 8) / bp0c];
			} else {
				local_2 = /*local_4*/(-bp08 <= bp0c)?-D_00E37120[(-bp08 << 8) / bp0c]:D_00E37120[(bp0c << 8) / -bp08] - 0x400;
			}
		} else {
			if(bp08 < 0) {//else 00753ED5
				local_2 = /*local_5*/(-bp08 >= -bp0c)?-D_00E37120[(-bp0c << 8) / -bp08] - 0x400:D_00E37120[(-bp08 << 8) / -bp0c] - 0x800;
			} else {
				local_2 = /*local_6*/(bp08 <= -bp0c)?0x800 - D_00E37120[(bp08 << 8) / -bp0c]:D_00E37120[(-bp0c << 8) / bp08] + 0x400;
			}
		}
	}

	return local_2;
}

short C_00753F2E(struct VECTOR *bp08, struct VECTOR *bp0c) {
	return C_00753DA9(bp0c->f_00 - bp08->f_00, bp0c->f_08 - bp08->f_08);
}

void C_00753F53() {
	struct {
		int _ocal_2;
		struct t_wm_vertexinfo *local_1;
	}lolo;

	lolo.local_1 = &D_00969B60;

	lolo.local_1->r1 = D_00969B58[0]; lolo.local_1->r0 = D_00969B58[0];
	lolo.local_1->g1 = D_00969B58[1]; lolo.local_1->g0 = D_00969B58[1];
	lolo.local_1->b1 = D_00969B58[2]; lolo.local_1->b0 = D_00969B58[2];

	lolo.local_1->r3 = D_00969B5C[0]; lolo.local_1->r2 = D_00969B5C[0];
	lolo.local_1->g3 = D_00969B5C[1]; lolo.local_1->g2 = D_00969B5C[1];
	lolo.local_1->b3 = D_00969B5C[2]; lolo.local_1->b2 = D_00969B5C[2];

	lolo.local_1->rgba0 =
	lolo.local_1->rgba1 = (D_00969B58[0] << 0x10) | (D_00969B58[1] << 8) | D_00969B58[2];
	lolo.local_1->rgba2 =
	lolo.local_1->rgba3 = (D_00969B5C[0] << 0x10) | (D_00969B5C[1] << 8) | D_00969B5C[2];
	lolo.local_1->rgba0 |= 0x80000000;
	lolo.local_1->rgba1 |= 0x80000000;
	lolo.local_1->rgba2 |= 0x80000000;
	lolo.local_1->rgba3 |= 0x80000000;
	lolo.local_1->x3 = D_00DE68F8;
	lolo.local_1->x1 = D_00DE68F8;
	lolo.local_1->y2 =
	lolo.local_1->y3 = D_00DE69D8 * 0xb4;
	D_00E2A134 = 0;
}

struct t_wm_vertexinfo *C_007540E5() {
	return &D_00969B60;
}

int __007540EF() {
	return 0;
}

int C_007540F6() {
	return D_00E2A134;
}

void C_00754100(short bp08) {
	struct {
		struct VECTOR local_60;
		struct MATRIX local_56;
		int local_48;
		float local_47;
		struct SVECTOR local_46;
		D3DMATRIX local_44;
		int local_28;
		struct t_wm_vertexinfo *local_27;
		float local_26;
		D3DMATRIX local_25;
		struct SVECTOR local_9;
		struct t_g_drv_0c local_7;
		float local_4[4];
	}lolo;

	lolo.local_27 = &D_00969B60;
	lolo.local_46.f_00 = 0;
	lolo.local_46.f_02 = -D_00DE6A04;
	lolo.local_46.f_04 = -0x4000;
	C_00753D00(&lolo.local_46, -bp08);
	C_0074D33A(&lolo.local_46);
	lolo.local_7.f_00 =
	lolo.local_7.f_04 =
	lolo.local_7.f_08 = 0;
	C_006617E9(C_0066100D(), &lolo.local_25);//psx:transformation to D3DMATRIX(3)
	C_0067D2BF(&lolo.local_25, &lolo.local_44);//dx_mat:matrix multiplication by "struct t_aa0::f_8d0" 4x4[transpose]
	C_0066CE40(&lolo.local_44, &lolo.local_7, lolo.local_4);
	lolo.local_47 = 1.0f / (lolo.local_4[3] * D_00DE6900);
	lolo.local_48 = (int)(/*_ftol*/lolo.local_26 = lolo.local_4[1] * lolo.local_47) + 0x1a;
	D_00E2A134 = lolo.local_48;
	lolo.local_9.f_00 =
	lolo.local_9.f_02 = 0;
	lolo.local_9.f_04 = C_0074D319();
	C_006628DE(&lolo.local_9, &lolo.local_56);//psx:xyz_rotate(1)
	C_00663673(&lolo.local_56);//psx:SetRotMatrix?
	lolo.local_60.f_00 = D_00E2C424 + 0xa0;
	lolo.local_60.f_04 = lolo.local_48;
	lolo.local_60.f_08 = 0;
	C_00663766(&lolo.local_56, &lolo.local_60);//psx:set translate vector?
	C_00663707(&lolo.local_56);//psx:SetTransMatrix?
	lolo.local_46.f_04 = 0;

	lolo.local_46.f_00 = -0xb4;
	lolo.local_46.f_02 = -lolo.local_48 - 0x18;
	C_00662ECC(&lolo.local_46, &lolo.local_60, &lolo.local_28);//psx:RotTrans
	lolo.local_27->x0 = lolo.local_60.f_00 * D_00DE69D8;
	lolo.local_27->y0 = lolo.local_60.f_04 * D_00DE69D8;

	lolo.local_46.f_00 = 0xb4;
	lolo.local_46.f_02 = -lolo.local_48 - 0x18;
	C_00662ECC(&lolo.local_46, &lolo.local_60, &lolo.local_28);//psx:RotTrans
	lolo.local_27->x1 = lolo.local_60.f_00 * D_00DE69D8;
	lolo.local_27->y1 = lolo.local_60.f_04 * D_00DE69D8;

	lolo.local_46.f_00 = -0xb4;
	lolo.local_46.f_02 = 0;
	C_00662ECC(&lolo.local_46, &lolo.local_60, &lolo.local_28);//psx:RotTrans
	lolo.local_27->x2 = lolo.local_60.f_00 * D_00DE69D8;
	lolo.local_27->y2 = lolo.local_60.f_04 * D_00DE69D8;

	lolo.local_46.f_00 = 0xb4;
	lolo.local_46.f_02 = 0;
	C_00662ECC(&lolo.local_46, &lolo.local_60, &lolo.local_28);//psx:RotTrans
	lolo.local_27->x3 = lolo.local_60.f_00 * D_00DE69D8;
	lolo.local_27->y3 = lolo.local_60.f_04 * D_00DE69D8;
}

void C_007543D3() {
	int local_2;
	struct t_wm_local_30 *local_1;

	for(local_2 = 0; local_2 < 1; local_2 ++) {
		for(local_1 = &(D_00E2A370[local_2][0]); local_1 < &(D_00E2A370[local_2][3]); local_1 ++) {
			local_1->f_00.b0 = 0x40;
			local_1->f_00.g0 = 0x40;
			local_1->f_00.r0 = 0x40;
			local_1->f_2c = 0x807F7F7F;
			local_1->f_00.v1 = 0;
			local_1->f_00.v0 = 0;
			local_1->f_00.v3 = 0x3f;
			local_1->f_00.v2 = 0x3f;
			local_1->f_28 = D_00E2C3EC;
		}
		local_1 = &D_00969B98;
		local_1->f_28 = D_00E2C3F0;
	}
	D_00E2AAE4 = 0;
}

void C_00754493(struct t_wm_local_30 *bp08) {
	struct {
		//local_9 and above for compiler
		struct t_dx_rend_vertex_20 *local_8;
		struct t_dx_rend_vertex_20 *local_7;
		struct t_dx_rend_vertex_20 *local_6;
		struct t_dx_rend_vertex_20 *local_5;
		float local_4;
		float local_3;
		float local_2;
		float local_1;
	}lolo;

	if(bp08->f_28 == 0)
		return;
	lolo.local_2 = (float)bp08->f_00.u0 * bp08->f_28->f_24;
	lolo.local_3 = (float)bp08->f_00.u1 * bp08->f_28->f_24;
	lolo.local_4 = (float)bp08->f_00.v0 * bp08->f_28->f_28;
	lolo.local_1 = (float)bp08->f_00.v2 * bp08->f_28->f_28;
	bp08->f_00.x0 *= D_00DE69D8;
	bp08->f_00.y0 *= D_00DE69D8;
	bp08->f_00.x1 *= D_00DE69D8;
	bp08->f_00.y1 *= D_00DE69D8;
	bp08->f_00.x2 *= D_00DE69D8;
	bp08->f_00.y2 *= D_00DE69D8;
	bp08->f_00.x3 *= D_00DE69D8;
	bp08->f_00.y3 *= D_00DE69D8;
	if(C_0066E272(1, bp08->f_28)) {
		if(C_0074C969()) {//get "isRendering"?
			MK_VERTEX(&(bp08->f_28->f_70.asVertex[0]), lolo.local_5, (float)bp08->f_00.x0, (float)bp08->f_00.y0, 0.999f, 1.0f, bp08->f_2c, 0xff000000, lolo.local_2, lolo.local_4);
			MK_VERTEX(&(bp08->f_28->f_70.asVertex[1]), lolo.local_6, (float)bp08->f_00.x1, (float)bp08->f_00.y1, 0.999f, 1.0f, bp08->f_2c, 0xff000000, lolo.local_3, lolo.local_4);
			MK_VERTEX(&(bp08->f_28->f_70.asVertex[2]), lolo.local_7, (float)bp08->f_00.x2, (float)bp08->f_00.y2, 0.999f, 1.0f, bp08->f_2c, 0xff000000, lolo.local_2, lolo.local_1);
			MK_VERTEX(&(bp08->f_28->f_70.asVertex[3]), lolo.local_8, (float)bp08->f_00.x3, (float)bp08->f_00.y3, 0.999f, 1.0f, bp08->f_2c, 0xff000000, lolo.local_3, lolo.local_1);
		}
	}
}

void C_007547A6(short bp08) {
	struct {//x16c
		struct t_wm_local_30 *local_91;
		struct VECTOR local_90[0xc];//bp_168
		struct MATRIX local_42;//bp_a8
		int local_34;
		int local_33;
		int local_32;
		int local_31;
		struct SVECTOR local_30[0xc];//bp_78
		void *local_6;
		int local_5;
		struct SVECTOR local_4;
		int local_2;
		struct t_wm_local_30 *local_1;
	}lolo;

	lolo.local_32 = C_0074C9A5();
	lolo.local_1 = &(D_00E2A370[0][0]);
	lolo.local_6 = C_0074CBC2();
	if(lolo.local_6) {//else 00754E0C
		lolo.local_34 = C_0074D4ED();
		if(lolo.local_34 == 0)
			lolo.local_34 = 1;
		lolo.local_31 = (C_007540F6() - 0x2c) - (lolo.local_34 >> 8);
		if(bp08 - D_00E2BBA4 > 0x800)
			bp08 -= 0x1000;
		else if(D_00E2BBA4 - bp08 > 0x800)
			bp08 += 0x1000;
		lolo.local_2 = ((bp08 - D_00E2BBA4) * lolo.local_34) / 0x2710;
		D_00E28F20 -= lolo.local_2;
		if(D_00E28F20 < 0)
			D_00E28F20 += 0x100;
		else if(D_00E28F20 > 0xff)
			D_00E28F20 -= 0x100;
		D_00E2BBA4 += (lolo.local_2 * 0x2710) / lolo.local_34;
		D_00E2BBA4 &= 0xfff;
		lolo.local_30[0].f_00 =
		lolo.local_30[1].f_00 = -0xa0;
		lolo.local_30[2].f_00 =
		lolo.local_30[3].f_00 = D_00E28F20 - 0x160;
		lolo.local_30[4].f_00 =
		lolo.local_30[5].f_00 = D_00E28F20 - 0x60;
		lolo.local_30[6].f_00 =
		lolo.local_30[7].f_00 = 0xa0;
		lolo.local_30[0].f_02 =
		lolo.local_30[2].f_02 =
		lolo.local_30[4].f_02 =
		lolo.local_30[6].f_02 = lolo.local_31 - 0x40;
		lolo.local_30[1].f_02 =
		lolo.local_30[3].f_02 =
		lolo.local_30[5].f_02 =
		lolo.local_30[7].f_02 = lolo.local_31;
		lolo.local_30[8].f_00 =
		lolo.local_30[9].f_00 = (((-bp08 << 0x14) >> 0x14) * (lolo.local_34 - 0x1f4)) / 0x2710 - 0x48;
		lolo.local_30[0xa].f_00 =
		lolo.local_30[0xb].f_00 = lolo.local_30[8].f_00 + 0x90;
		lolo.local_30[8].f_02 =
		lolo.local_30[0xa].f_02 = lolo.local_31 - 0x70;
		lolo.local_30[9].f_02 =
		lolo.local_30[0xb].f_02 = lolo.local_31 - 0x30;
		lolo.local_4.f_00 = 
		lolo.local_4.f_02 = 0;
		lolo.local_4.f_04 = C_0074D319();
		C_006628DE(&lolo.local_4, &lolo.local_42);//psx:xyz_rotate(1)
		C_00663673(&lolo.local_42);//psx:SetRotMatrix?
		lolo.local_42.f_12[0] = D_00E2C424 + 0xa0;
		lolo.local_42.f_12[1] = 0x28;
		C_00663707(&lolo.local_42);//psx:SetTransMatrix?
		for(lolo.local_33 = 0; lolo.local_33 < 0xc; lolo.local_33 ++) {
			C_00662ECC(&(lolo.local_30[lolo.local_33]), &(lolo.local_90[lolo.local_33]), &lolo.local_5);//psx:RotTrans
		}
		if(D_00E28F20 < 0xC0) {//else 00754B38
			lolo.local_1->f_00.x0 = lolo.local_90[0].f_00;
			lolo.local_1->f_00.x2 = lolo.local_90[1].f_00;
			lolo.local_1->f_00.x1 = lolo.local_90[4].f_00;
			lolo.local_1->f_00.x3 = lolo.local_90[5].f_00;
			lolo.local_1->f_00.y0 = lolo.local_90[0].f_04;
			lolo.local_1->f_00.y2 = lolo.local_90[1].f_04;
			lolo.local_1->f_00.y1 = lolo.local_90[4].f_04;
			lolo.local_1->f_00.y3 = lolo.local_90[5].f_04;
			lolo.local_1->f_00.u0 =
			lolo.local_1->f_00.u2 = 0xc0 - D_00E28F20;
			lolo.local_1->f_00.u3 = 0xff;
			lolo.local_1->f_00.u1 = 0xff;
			C_00754493(lolo.local_1);
		} else {
			lolo.local_1->f_00.x0 = lolo.local_90[0].f_00;
			lolo.local_1->f_00.x2 = lolo.local_90[1].f_00;
			lolo.local_1->f_00.x1 = lolo.local_90[2].f_00;
			lolo.local_1->f_00.x3 = lolo.local_90[3].f_00;
			lolo.local_1->f_00.y0 = lolo.local_90[0].f_04;
			lolo.local_1->f_00.y2 = lolo.local_90[1].f_04;
			lolo.local_1->f_00.y1 = lolo.local_90[2].f_04;
			lolo.local_1->f_00.y3 = lolo.local_90[3].f_04;
			lolo.local_1->f_00.u0 =
			lolo.local_1->f_00.u2 = 0xc0 + (0xff - D_00E28F20);
			lolo.local_1->f_00.u3 = 0xff;
			lolo.local_1->f_00.u1 = 0xff;
			C_00754493(lolo.local_1);
			lolo.local_1 ++;
			lolo.local_1->f_00.x0 = lolo.local_90[2].f_00;
			lolo.local_1->f_00.x2 = lolo.local_90[3].f_00;
			lolo.local_1->f_00.x1 = lolo.local_90[4].f_00;
			lolo.local_1->f_00.x3 = lolo.local_90[5].f_00;
			lolo.local_1->f_00.y0 = lolo.local_90[2].f_04;
			lolo.local_1->f_00.y2 = lolo.local_90[3].f_04;
			lolo.local_1->f_00.y1 = lolo.local_90[4].f_04;
			lolo.local_1->f_00.y3 = lolo.local_90[5].f_04;
			lolo.local_1->f_00.u2 = 0;
			lolo.local_1->f_00.u0 = 0;
			lolo.local_1->f_00.u3 = 0xff;
			lolo.local_1->f_00.u1 = 0xff;
			C_00754493(lolo.local_1);
		}
		lolo.local_1 ++;
		lolo.local_1->f_00.x0 = lolo.local_90[4].f_00;
		lolo.local_1->f_00.x2 = lolo.local_90[5].f_00;
		lolo.local_1->f_00.x1 = lolo.local_90[6].f_00;
		lolo.local_1->f_00.x3 = lolo.local_90[7].f_00;
		lolo.local_1->f_00.y0 = lolo.local_90[4].f_04;
		lolo.local_1->f_00.y2 = lolo.local_90[5].f_04;
		lolo.local_1->f_00.y1 = lolo.local_90[6].f_04;
		lolo.local_1->f_00.y3 = lolo.local_90[7].f_04;
		lolo.local_1->f_00.u2 = 0;
		lolo.local_1->f_00.u0 = 0;
		lolo.local_1->f_00.u1 =
		lolo.local_1->f_00.u3 = 0xff - D_00E28F20;
		C_00754493(lolo.local_1);
		if(D_00E2AAE4 && lolo.local_90[0xa].f_00 > D_00E2C424 && lolo.local_90[8].f_00 < D_00E2C428 + 0x140) {
			lolo.local_91 = &D_00969B98;
			lolo.local_91->f_00.x0 = lolo.local_90[8].f_00;
			lolo.local_91->f_00.y0 = lolo.local_90[8].f_04;
			lolo.local_91->f_00.x2 = lolo.local_90[9].f_00;
			lolo.local_91->f_00.y2 = lolo.local_90[9].f_04;
			lolo.local_91->f_00.x1 = lolo.local_90[0xa].f_00;
			lolo.local_91->f_00.y1 = lolo.local_90[0xa].f_04;
			lolo.local_91->f_00.x3 = lolo.local_90[0xb].f_00;
			lolo.local_91->f_00.y3 = lolo.local_90[0xb].f_04;
			C_00754493(lolo.local_91);
		}
	}
}

void C_00754E10(int bp08) {
	D_00E2AAE4 = bp08;
}

void C_00754E6B(void);

void C_00754E1D() {
	int local_1;

	for(local_1 = 0; local_1 < 0x10; local_1 ++) {
		D_00E28CE0[local_1].f_13 = 0;
		D_00E28CE0[local_1].f_00.f_04 = 0;
	}
	D_00E2BB94 = 0;
	C_00754E6B();
}

void C_00754E6B() {
	if(C_0074D330() == 2)
		C_0066332E(0x20, 0x20, 0x30);//psx:"SetBackColor"
	else
		C_0066332E(0x40, 0x40, 0x40);//psx:"SetBackColor"
	C_0066335F(0, 0, 0);//psx:"SetFarColor"
	C_0075EB2D(C_0074D330() == 2);//wm:change light params?
}

void C_00754EBC(int bp08, int bp0c) {
	if(bp08 >= 0 && bp08 < 0x10) {
		D_00E2BB94 = &(D_00E28CE0[bp08]);
		if(bp0c != -1)
			D_00E2BB94->f_13 = bp0c;
	}
}

void C_00754EEF(int bp08, int bp0c) {
	if(D_00E2BB94 && bp08 >= 0 && bp08 < 0x24 && bp0c >= 0 && bp0c < 0x1c) {
		D_00E2BB94->f_00.f_00 &= 0x1fff;
		D_00E2BB94->f_00.f_08 &= 0x1fff;
		D_00E2BB94->f_00.f_00 |= bp08 << 0xd;
		D_00E2BB94->f_00.f_08 |= bp0c << 0xd;
	}
}

void C_00754F72(int bp08, int bp0c) {
	if(D_00E2BB94) {
		D_00E2BB94->f_00.f_00 &= ~0x1fff;
		D_00E2BB94->f_00.f_08 &= ~0x1fff;
		D_00E2BB94->f_00.f_00 |= bp08 & 0x1fff;
		D_00E2BB94->f_00.f_08 |= bp0c & 0x1fff;
	}
}

void C_00754FE2(int bp08, int bp0c, int bp10) {
	if(D_00E2BB94) {
		D_00E2BB94->f_10 = bp08;
		D_00E2BB94->f_11 = bp0c;
		D_00E2BB94->f_12 = bp10;
	}
}

void C_00755013(int bp08) {
	if(D_00E2BB94) {
		D_00E2BB94->f_1c = bp08;
	}
}

void C_0075502C(int bp08) {
	if(D_00E2BB94) {
		D_00E2BB94->f_20.rgba = bp08;
	}
}

void C_00755045(int bp08, int bp0c, int bp10) {
	if(D_00E2BB94) {
		D_00E2BB94->f_14 = bp08;
		D_00E2BB94->f_15 = bp0c;
		D_00E2BB94->f_16 = bp10;
	}
}

void C_00755076(int bp08, int bp0c, int bp10) {
	if(D_00E2BB94) {
		D_00E2BB94->f_18 = bp08;
		D_00E2BB94->f_19 = bp0c;
		D_00E2BB94->f_1a = bp10;
	}
}

//sky color transition?
void C_007550A7(struct VECTOR *bp08) {
	struct {//x54
		tRGBA sRGBA0_1;//local_21
		struct MATRIX local_20; char _ocal_20[2];
		int local_12;
		int i;//local_11
		int local_10;
		int local_9;
		unsigned dwColorG;//local_8
		int local_7;
		int local_6;
		struct t_wm_vertexinfo *local_5;
		unsigned dwColorR;//local_4
		unsigned dwColorB;//local_3
		tRGBA sRGBA2_3;//local_2
		struct t_wm_local_24 *local_1;
	}lolo;

	lolo.local_7 = 0;
	lolo.local_9 = 0;
	lolo.local_10 = C_0074C9A5();
	lolo.local_5 = &D_00969B60;
	for(lolo.i = 0; lolo.i < 0x10; lolo.i ++) {
		lolo.local_1 = &(D_00E28CE0[lolo.i]);
		if(lolo.local_1->f_13) {//else 0075540E
			lolo.local_6 = C_00753C23(bp08, &(lolo.local_1->f_00)) - (lolo.local_1->f_20.rgba << 0xa);
			if(lolo.local_6 < 0) {
				lolo.local_6 = 0;
				lolo.local_9 = 1;
			}
			lolo.local_12 = lolo.local_1->f_1c << 0xa;
			if(lolo.local_6 < lolo.local_12) {//else 0075540E
				lolo.local_7 = 1;

				lolo.local_20.f_00[0][0] = (lolo.local_6 * D_00969C08.f_00[0][0]) / lolo.local_12 + ((lolo.local_12 - lolo.local_6) * lolo.local_1->f_10 * 7) / lolo.local_12;
				lolo.local_20.f_00[1][0] = (lolo.local_6 * D_00969C08.f_00[1][0]) / lolo.local_12 + ((lolo.local_12 - lolo.local_6) * lolo.local_1->f_11 * 7) / lolo.local_12;
				lolo.local_20.f_00[2][0] = (lolo.local_6 * D_00969C08.f_00[2][0]) / lolo.local_12 + ((lolo.local_12 - lolo.local_6) * lolo.local_1->f_12 * 7) / lolo.local_12;
				C_0075EE10(&lolo.local_20);//wm:set some global light color?
				C_0075EB2D(2);//wm:change light params?
				//-- --
				lolo.dwColorR = (lolo.local_6 * D_00969B58[0] + (lolo.local_12 - lolo.local_6) * lolo.local_1->f_14) / lolo.local_12;
				if(lolo.dwColorR > 0xff)
					lolo.dwColorR = 0xff;
				lolo.sRGBA0_1.c.b = lolo.dwColorR;
				lolo.local_5->r1 = lolo.sRGBA0_1.c.b;
				lolo.local_5->r0 = lolo.sRGBA0_1.c.b;

				lolo.dwColorG = (lolo.local_6 * D_00969B58[1] + (lolo.local_12 - lolo.local_6) * lolo.local_1->f_15) / lolo.local_12;
				if(lolo.dwColorG > 0xff)
					lolo.dwColorG = 0xff;
				lolo.sRGBA0_1.c.g = lolo.dwColorG;
				lolo.local_5->g1 = lolo.sRGBA0_1.c.g;
				lolo.local_5->g0 = lolo.sRGBA0_1.c.g;

				lolo.dwColorB = (lolo.local_6 * D_00969B58[2] + (lolo.local_12 - lolo.local_6) * lolo.local_1->f_16) / lolo.local_12;
				if(lolo.dwColorB > 0xff)
					lolo.dwColorB = 0xff;
				lolo.sRGBA0_1.c.r = lolo.dwColorB;
				lolo.local_5->b1 = lolo.sRGBA0_1.c.r;
				lolo.local_5->b0 = lolo.sRGBA0_1.c.r;
				//-- --
				lolo.dwColorR = (lolo.local_6 * D_00969B5C[0] + (lolo.local_12 - lolo.local_6) * lolo.local_1->f_18) / lolo.local_12;
				if(lolo.dwColorR > 0xff)
					lolo.dwColorR = 0xff;
				lolo.sRGBA2_3.c.b = lolo.dwColorR;
				lolo.local_5->r3 = lolo.sRGBA2_3.c.b;
				lolo.local_5->r2 = lolo.sRGBA2_3.c.b;

				lolo.dwColorG = (lolo.local_6 * D_00969B5C[1] + (lolo.local_12 - lolo.local_6) * lolo.local_1->f_19) / lolo.local_12;
				if(lolo.dwColorG > 0xff)
					lolo.dwColorG = 0xff;
				lolo.sRGBA2_3.c.g = lolo.dwColorG;
				lolo.local_5->g3 = lolo.sRGBA2_3.c.g;
				lolo.local_5->g2 = lolo.sRGBA2_3.c.g;

				lolo.dwColorB = (lolo.local_6 * D_00969B5C[2] + (lolo.local_12 - lolo.local_6) * lolo.local_1->f_1a) / lolo.local_12;
				if(lolo.dwColorB > 0xff)
					lolo.dwColorB = 0xff;
				lolo.sRGBA2_3.c.r = lolo.dwColorB;
				lolo.local_5->b3 = lolo.sRGBA2_3.c.r;
				lolo.local_5->b2 = lolo.sRGBA2_3.c.r;
				//-- --
				lolo.sRGBA0_1.c.a =
				lolo.sRGBA2_3.c.a = 0x80;
				//-- --
				lolo.local_5->rgba1 = lolo.sRGBA0_1.rgba;
				lolo.local_5->rgba0 = lolo.sRGBA0_1.rgba;
				lolo.local_5->rgba3 = lolo.sRGBA2_3.rgba;
				lolo.local_5->rgba2 = lolo.sRGBA2_3.rgba;
			}
		}
	}
	if(lolo.local_7 == 0) {
		C_0075EB2D(3);//wm:change light params?
		C_00753F53();
	}
}

int C_0075542D(struct VECTOR *bp08) {
	return D_00E2BB94?C_00753C23(bp08, &(D_00E2BB94->f_00)):0;
}

short C_0075545F(struct VECTOR *bp08) {
	return D_00E2BB94?C_00753F2E(bp08, &(D_00E2BB94->f_00)):0;
}

void C_00755495() {
	D_00E2A120[0] =
	D_00E2A120[1] =
	D_00E2A120[2] = 0;

	D_00E2B768[0] =
	D_00E2B768[1] =
	D_00E2B768[2] = 0;
	
	D_00E2BBB0[0] = 0xff;
	D_00E2BBB0[1] =
	D_00E2BBB0[2] = 0;
	D_00E2A180[0] = 0xff;
	D_00E2A180[1] =
	D_00E2A180[2] = 0x80;
}

void C_00755BED(int);

//render "extra layers"?
void C_0075551A() {
	struct {
		//local_18 and above for compiler
		struct t_dx_rend_vertex_20 *local_17[4];
		struct t_dx_rend_vertex_20 *local_13[4];
		float local_9;
		float local_8;
		float local_7;
		float local_6;
		int i;//local_5
		int local_4;
		tRGBA local_3;
		int local_2;
		int local_1;
	}lolo;

	lolo.local_4 = C_0074C9A5();
	lolo.local_2 = D_00E2C424;
	lolo.local_1 = D_00E2C428;
	for(lolo.i = 0; lolo.i < 3; lolo.i ++) {
		lolo.local_3.c.b =
		lolo.local_3.c.g =
		lolo.local_3.c.r = D_00E2BBB0[lolo.i];
		lolo.local_3.c.a = D_00E2BBB0[lolo.i];
		if(D_00E2A120[lolo.i]) {//else 00755641
			D_00E2BBB0[lolo.i] += /*lolo.local_18*/lolo.i?
				D_00E2A120[lolo.i]:
				((D_00E2A120[lolo.i] * (D_00E2BBB0[lolo.i] + 0x80)) >> 8)
			;
			if(D_00E2BBB0[lolo.i] <= 0) {
				D_00E2BBB0[lolo.i] = 0;
				D_00E2A120[lolo.i] = 0;
			} else if(D_00E2BBB0[lolo.i] >= D_00E2A180[lolo.i]) {//else 00755641
				D_00E2BBB0[lolo.i] = D_00E2A180[lolo.i];
				D_00E2A120[lolo.i] = 0;
			}
		}
		if(D_00E2BBB0[lolo.i]) {//else 00755AD2
			if(lolo.i) {//else 007558C4
				//-- snow layers --
				if(C_0066E272(1, D_00E2C3F4[lolo.i])) {//else 007558BF
					if(C_0074C969()) {//get "isRendering"?//else 007558BF
						lolo.local_6 = D_00E2A6D8[lolo.i][0] * (1.0f/256.0f);
						lolo.local_7 = D_00E2A6D8[lolo.i][1] * (1.0f/256.0f);
						lolo.local_8 = (float)D_00DE68F8 * (1.0f/256.0f);
						lolo.local_9 = (float)D_00DE67E8 * (1.0f/256.0f);
						lolo.local_3.c.a = 0x80;
						//MK_QUAD_2D(D_00E2C3F4[lolo.i]->f_70.asVertex, lolo.local_13, (float)lolo.local_2, (float)lolo.local_1, (float)D_00DE68F8, (float)D_00DE67E8, 0, 1.0f, lolo.local_3.rgba, 0xff000000, lolo.local_6, lolo.local_7, lolo.local_8, lolo.local_9);
						MK_VERTEX(&(D_00E2C3F4[lolo.i]->f_70.asVertex[0]), lolo.local_13[3], (float)lolo.local_2,                     (float)lolo.local_1,                     0, 1.0f, lolo.local_3.rgba, 0xff000000, lolo.local_6, lolo.local_7);
						MK_VERTEX(&(D_00E2C3F4[lolo.i]->f_70.asVertex[1]), lolo.local_13[2], (float)lolo.local_2,                     (float)D_00DE67E8 + (float)lolo.local_1, 0, 1.0f, lolo.local_3.rgba, 0xff000000, lolo.local_6,                lolo.local_7 + lolo.local_9);
						MK_VERTEX(&(D_00E2C3F4[lolo.i]->f_70.asVertex[2]), lolo.local_13[1], (float)D_00DE68F8 + (float)lolo.local_2, (float)lolo.local_1,                     0, 1.0f, lolo.local_3.rgba, 0xff000000, lolo.local_6 + lolo.local_8, lolo.local_7);
						MK_VERTEX(&(D_00E2C3F4[lolo.i]->f_70.asVertex[3]), lolo.local_13[0], (float)D_00DE68F8 + (float)lolo.local_2, (float)D_00DE67E8 + (float)lolo.local_1, 0, 1.0f, lolo.local_3.rgba, 0xff000000, lolo.local_6 + lolo.local_8, lolo.local_7 + lolo.local_9);
					}
				}
				//goto 00755AD2
			} else {
				//-- "alpha" layer[for fade in/out] --
				if(C_0066E272(1, D_00E2C3F4[0])) {//else 00755AD2
					if(C_0074C969()) {//get "isRendering"?//else 00755AD2
						if(D_00E2BBC0) {//else 0075593B
							lolo.local_3.c.b =
							lolo.local_3.c.g =
							lolo.local_3.c.r = D_00E2BBB0[lolo.i];
							lolo.local_3.c.a = 0xff;
							if(D_00E2BBC4 == 0) {
								D_00E2BBC4 = 1;
							} else {
								D_00E2BBC4 = 0;
								D_00E2BBC0 = 0;
							}
						} else {
							lolo.local_3.c.b =
							lolo.local_3.c.g =
							lolo.local_3.c.r = 0;
						}
						//MK_QUAD_2D_NOTEXTURE(D_00E2C3F4[0]->f_70.asVertex, lolo.local_17, (float)lolo.local_2, (float)lolo.local_1, (float)D_00DE68F8, (float)D_00DE67E8, 0, 1.0f, lolo.local_3.rgba, 0xff000000);
						MK_VERTEX_NOTEXTURE(&(D_00E2C3F4[0]->f_70.asVertex[0]), lolo.local_17[3], (float)lolo.local_2,                     (float)lolo.local_1,                     0, 1.0f, lolo.local_3.rgba, 0xff000000);
						MK_VERTEX_NOTEXTURE(&(D_00E2C3F4[0]->f_70.asVertex[1]), lolo.local_17[2], (float)lolo.local_2,                     (float)D_00DE67E8 + (float)lolo.local_1, 0, 1.0f, lolo.local_3.rgba, 0xff000000);
						MK_VERTEX_NOTEXTURE(&(D_00E2C3F4[0]->f_70.asVertex[2]), lolo.local_17[1], (float)D_00DE68F8 + (float)lolo.local_2, (float)lolo.local_1,                     0, 1.0f, lolo.local_3.rgba, 0xff000000);
						MK_VERTEX_NOTEXTURE(&(D_00E2C3F4[0]->f_70.asVertex[3]), lolo.local_17[0], (float)D_00DE68F8 + (float)lolo.local_2, (float)D_00DE67E8 + (float)lolo.local_1, 0, 1.0f, lolo.local_3.rgba, 0xff000000);
					}
				}
			}
		}
		if(D_00E2B768[lolo.i]) {
			D_00E2B768[lolo.i] --;
			if(D_00E2B768[lolo.i] == 0)
				C_00755BED(lolo.i);
		}
	}//end for
	//-- compute angles for snow layers --
	D_00E2A6D8[1][0] = C_00662538((C_0040AC84() << 4) & 0xfff) >> 3;//psx:sin
	D_00E2A6D8[1][1] = D_00E2B768[1] << 3;
	D_00E2A6D8[2][0] = C_006624FD((C_0040AC84() << 4) & 0xfff) >> 4;//psx:cos
	D_00E2A6D8[2][1] = D_00E2B768[2] << 2;
	//-- --
}

void C_00755B70(int bp08, int _p0c) {
	int _dummy;

	if(D_00E2BBB0[0] > 0)
		D_00E2A120[0] = -bp08;
	else
		D_00E2A120[0] = 0;

}

void C_00755B97(int bp08, int _p0c) {
	int _dummy;

	if(D_00E2BBB0[0] < D_00E2A180[0])
		D_00E2A120[0] = bp08;
	else
		D_00E2A120[0] = 0;
}

void C_00755BC1(int bp08) {
	D_00E2A120[bp08] = (D_00E2BBB0[bp08] < D_00E2A180[bp08])?0x10:0;
}

void C_00755BED(int bp08) {
	D_00E2A120[bp08] = (D_00E2BBB0[bp08] > 0)?-0x10:0;
}

void C_00755C10(int bp08) {
	C_00755BC1(bp08);
	D_00E2B768[bp08] = 0x64;
}

int C_00755C2F() {
	return D_00E2A120[0] == 0;
}

void C_00755C40() {
	struct {
		short *local_6;
		int local_5;
		short *local_4;
		short local_3[4];
		short *local_1;
	}lolo;

	lolo.local_3[0] = 0;
	lolo.local_3[1] = 0x1e0;
	lolo.local_3[2] = 0x100;
	lolo.local_3[3] = 1;
	for(lolo.local_1 = D_00E2B350, lolo.local_6 = &(D_00E2AB50[0x400])/*==D_00E2B350*/, lolo.local_4 = &(D_00E2AB50[0]); lolo.local_4 < lolo.local_6; lolo.local_4 += 4) {
		lolo.local_4[0] = (*lolo.local_1 << 0xa) & 0x7c00;
		lolo.local_4[1] = (*lolo.local_1 << 5) & 0x7c00;
		lolo.local_4[2] = *lolo.local_1 & 0x7c00;
		lolo.local_1 ++;
	}
	for(lolo.local_5 = 0;  lolo.local_5 < 0x100; lolo.local_5 ++)
		D_00E2A6E0[lolo.local_5] = C_00753BE8() << 2;
}

void C_00755CFF(int bp08) {
	struct {
		int *local_24;
		int local_23;
		struct MATRIX local_22;//bp_58
			//bp_42
			//bp_46
		struct SVECTOR *local_14;
		int local_13;
		int local_12;
		int local_11;
		short *local_10;
		struct VECTOR local_9;
		int local_5;
		struct SVECTOR *local_4;
		int local_3;
		short local_2[3];
	}lolo;

	lolo.local_2[0] = 0;
	lolo.local_2[1] = bp08 + 0x1e0;
	lolo.local_2[2] = 0x100;
	lolo.local_2[3] = 1;
	lolo.local_22.f_00[0][0] =
	lolo.local_22.f_00[1][1] =
	lolo.local_22.f_00[2][2] = D_00969C68[bp08] << 5;
	lolo.local_22.f_00[0][1] =
	lolo.local_22.f_00[0][2] =
	lolo.local_22.f_00[1][0] =
	lolo.local_22.f_00[1][2] =
	lolo.local_22.f_00[2][0] =
	lolo.local_22.f_00[2][1] = 0;
	lolo.local_22.f_12[0] = 0;
	lolo.local_22.f_12[1] = 0;
	lolo.local_22.f_12[2] = D_00969C28[bp08] << 5;
	C_00663673(&lolo.local_22);//psx:SetRotMatrix?
	C_00663707(&lolo.local_22);//psx:SetTransMatrix?
	lolo.local_10 = D_00E2B350;
	lolo.local_24 = D_00E2A6E0;
	lolo.local_14 = (struct SVECTOR *)&(D_00E2AB50[0x400]);//==D_00E2B350
	lolo.local_11 = 0;
	for(lolo.local_4 = (struct SVECTOR *)D_00E2AB50; lolo.local_4 < lolo.local_14; lolo.local_4 ++) {
		C_00662ECC(lolo.local_4, &lolo.local_9, &lolo.local_5);//psx:RotTrans
		lolo.local_3 = *(lolo.local_24 ++);
		lolo.local_9.f_00 += lolo.local_3;
		lolo.local_9.f_04 += lolo.local_3;
		lolo.local_9.f_08 += lolo.local_3;
		*(lolo.local_10 ++) = ((lolo.local_9.f_00 >> 0xa) & 0x1f) | ((lolo.local_9.f_04 >> 5) & 0x3e0) | (lolo.local_9.f_08 & 0x7c00);
	}
	lolo.local_13 =
	lolo.local_23 = 0xbb;
	lolo.local_12 = 0xff;
	for(lolo.local_11 = 0; lolo.local_11 < 0x100; lolo.local_11 ++) {
		D_00E2B778[lolo.local_11].c.b = lolo.local_13;
		D_00E2B778[lolo.local_11].c.g = lolo.local_23;
		D_00E2B778[lolo.local_11].c.r = lolo.local_12;
		D_00E2B778[lolo.local_11].c.a = 0xff;
		if(lolo.local_11 < 0x80) {
			lolo.local_13 -= 2;
			if(lolo.local_13 < 0)
				lolo.local_13 = 0;
		} else {
			lolo.local_12 -= 2;
			if(lolo.local_12 < 0)
				lolo.local_12 = 0;
		}
		lolo.local_23 --;
		if(lolo.local_23 < 0)
			lolo.local_23 = 0;
	}
	for(lolo.local_11 = 0; lolo.local_11 < 0x100; lolo.local_11 ++) {
		D_00E28F40[lolo.local_11].r = (float)D_00E2B778[lolo.local_11].c.b;
		D_00E28F40[lolo.local_11].g = (float)D_00E2B778[lolo.local_11].c.g;
		D_00E28F40[lolo.local_11].b = (float)D_00E2B778[lolo.local_11].c.r;
		D_00E28F40[lolo.local_11].a = 255.0f;
	}
}

void C_00755F95() {
	struct {
		int local_3;
		int local_2;
		struct t_wm_local_30 *local_1;
	}lolo;

	for(lolo.local_3 = 0; lolo.local_3 < 0xc; lolo.local_3 ++) {
		lolo.local_1 = &(D_00E2A490[lolo.local_3]);
		lolo.local_1->f_2c = 0x80808080;
		lolo.local_1->f_00.clut = /*lolo.local_4*/(lolo.local_3 < 4)?7 - lolo.local_3:(lolo.local_3 >= 8)?0xc - lolo.local_3 - 1:3;
		lolo.local_1->f_00.u0 =
		lolo.local_1->f_00.u2 = (/*lolo.local_6*/(lolo.local_3 < 4)?7 - lolo.local_3:(lolo.local_3 >= 8)?0xc - lolo.local_3 - 1:3) << 4;
		lolo.local_1->f_00.v1 = 0;
		lolo.local_1->f_00.v0 = 0;
		lolo.local_1->f_00.u1 =
		lolo.local_1->f_00.u3 = lolo.local_1->f_00.u0 + 0xf;
		lolo.local_1->f_00.v2 =
		lolo.local_1->f_00.v3 = lolo.local_1->f_00.v0 + 0xf;
		lolo.local_1->f_28 = D_00E2C414;
	}
	D_00E2A10C =
	D_00E2BBBC = 0;
	D_00E2A114 =
	D_00E29F40 =
	D_00E2AB38 = 0;
	for(lolo.local_2 = 0; lolo.local_2 < 6; lolo.local_2 ++)
		D_00E2A148[lolo.local_2].f_00 = 0;
}

void C_00756138(void);

void C_0075611B() {
	if(D_00E29F40 == 0) {
		C_00756138();
		D_00E29F40 = 1;
	}
}

void C_00756138() {
	struct {
		struct VECTOR local_5;
		struct USVECTOR *local_1;
	}lolo;

	C_00762798(&lolo.local_5);
	if(lolo.local_5.f_08 < 0x23A98) {
		for(lolo.local_1 = D_00E29F80; lolo.local_1 < &(D_00E29F80[0x30])/*D_00E2A100*/; lolo.local_1 ++) {
			lolo.local_1->f_00 = 0x2008;
			lolo.local_1->f_02 = 0x6338;
			lolo.local_1->f_06 = 0;
			lolo.local_1->f_04 = 0;
		}
	} else {
		for(lolo.local_1 = D_00E29F80; lolo.local_1 < &(D_00E29F80[0x30])/*D_00E2A100*/; lolo.local_1 ++) {
			lolo.local_1->f_00 = 0x1D4C;
			lolo.local_1->f_02 = 0x11F8;
			lolo.local_1->f_06 = 0;
			lolo.local_1->f_04 = 0;
		}
	}
	D_00E2AAE0 = 0x400;
	D_00E2A18C = D_00E29F80;
}

int C_007561EC() {
	return D_00E2AB38;
}

int C_007562A9(void);

void C_007561F6(struct t_wm_local_18 *bp08) {
	struct {
		short local_8; char _ocal_8[2];
		struct SVECTOR local_7;
		short local_5; char _ocal_5[2];
		struct VECTOR local_4;
	}lolo;

	if(C_007562A9()) {
		lolo.local_4.f_00 = D_00E2A18C->f_00 + 0x34000;
		lolo.local_4.f_08 = D_00E2A18C->f_02 + 0x20000;
		C_00750134(&lolo.local_4, &lolo.local_7, &lolo.local_5, &lolo.local_8);
		if(lolo.local_5 == bp08->f_10 && lolo.local_8 == bp08->f_12) {
			D_00E2A114 = C_0074CC07(bp08, &lolo.local_7, D_00E2A148, (short *)&(D_00E2A18C->f_06), 0, 0, 0x64);
			if(D_00E2A114 == 0)
				D_00E2A18C->f_06 = 0;
		}
	}
}

int C_007562A9() {
	struct VECTOR local_4;

	C_00762798(&local_4);

	return  (D_00E29F40 && local_4.f_00 >= 0x30000 && local_4.f_00 < 0x40000 && local_4.f_08 >= 0x1c000 && local_4.f_08 < 0x2c000)?1:0;
}

void C_007564CD(void);
void C_0075692A(void);

void C_007562FF() {
	struct {
		int local_7;
		int local_6;
		struct VECTOR local_5;
		int local_1;
	}lolo;

	C_00762798(&lolo.local_5);
	if(C_007562A9()) {//else 00756470
		if(D_00E2A114 == 0) {//else 00756380
			D_00E2A18C->f_00 = ((D_00E2A18C->f_00 * 0x3f) + 0x2710) >> 6;
			D_00E2A18C->f_02 = ((D_00E2A18C->f_02 * 0x3f) + 0x3A98) >> 6;
			D_00E2AAE0 = D_00E2A18C->f_04 + 0x800;
		}
		D_00E2A114 = 0;
		lolo.local_7 = inline_abs(lolo.local_5.f_00 - D_00E2A18C->f_00 - 0x34000) + inline_abs(lolo.local_5.f_08 - D_00E2A18C->f_02 - 0x20000);
		if(lolo.local_7 > 0xc8 || (C_00761769(7) == 0 && C_00761844() == 0)) {
			C_007564CD();
		} else {
			C_007640BC(7);
			D_00E29F40 = 0;
		}
		C_0075692A();
	}
	lolo.local_6 = C_00762136() & 0x1f;
	lolo.local_1 = C_00761735();//current transportation mode?
	if(lolo.local_1 != D_00E2A12C)
		lolo.local_6 = D_00E2A110;
	D_00E2A12C = lolo.local_1;
	if(lolo.local_6 == 7 && D_00E2A110 == 0)
		D_00E2AB38 = lolo.local_5.f_00 > 0x36000;
	D_00E2A110 = lolo.local_6;
}

void C_007564CD() {
	struct {
		short local_11; char __ocal_11[2];
		short local_10; char __ocal_10[2];
		struct VECTOR local_9;
		short local_5; char __ocal_5[2];
		short local_4; char __ocal_4[2];
		struct SVECTOR local_3;
		struct USVECTOR *local_1;
	}lolo;

	lolo.local_3.f_00 =
	lolo.local_3.f_02 = 0;
	lolo.local_3.f_04 = 0x64;
	C_00753D00(&lolo.local_3, D_00E2AAE0);
	lolo.local_1 = D_00E2A18C + 1;
	if(lolo.local_1 >= &(D_00E29F80[0x30])/*D_00E2A100*/)
		lolo.local_1 = &(D_00E29F80[0]);
	lolo.local_1->f_00 = D_00E2A18C->f_00 + lolo.local_3.f_00;
	lolo.local_1->f_02 = D_00E2A18C->f_02 + lolo.local_3.f_04;
	lolo.local_1->f_04 = D_00E2AAE0;
	if((C_00761769(7) || C_00761844()) && C_00762136() == 7) {//else 0075688A
		lolo.local_5 = 0;
		C_00762798(&lolo.local_9);
		lolo.local_9.f_00 -= 0x34000;
		lolo.local_9.f_08 -= 0x20000;
		lolo.local_4 = /*lolo.local_12*/inline_abs((unsigned short)lolo.local_1->f_00 - lolo.local_9.f_00) + /*lolo.local_13*/inline_abs((unsigned short)lolo.local_1->f_02 - lolo.local_9.f_08);
		lolo.local_11 = /*lolo.local_14*/(lolo.local_4 > 0x12c)?0x493e0 / lolo.local_4:0;
		lolo.local_3.f_00 =
		lolo.local_3.f_02 = 0;
		lolo.local_3.f_04 = 0x64;
		C_00753D00(&lolo.local_3, D_00E2AAE0 + lolo.local_11);
		lolo.local_10 = /*lolo.local_15*/inline_abs(D_00E2A18C->f_00 + lolo.local_3.f_00 - lolo.local_9.f_00) + /*lolo.local_16*/inline_abs(D_00E2A18C->f_02 + lolo.local_3.f_04  - lolo.local_9.f_08);
		if(lolo.local_10 < lolo.local_4) {
			lolo.local_1->f_00 = D_00E2A18C->f_00 + lolo.local_3.f_00;
			lolo.local_1->f_02 = D_00E2A18C->f_02 + lolo.local_3.f_04;
			lolo.local_1->f_04 = D_00E2AAE0 + lolo.local_11;
		}
		lolo.local_3.f_00 =
		lolo.local_3.f_02 = 0;
		lolo.local_3.f_04 = 0x64;
		C_00753D00(&lolo.local_3, D_00E2AAE0 - lolo.local_11);
		lolo.local_10 = /*lolo.local_17*/inline_abs(D_00E2A18C->f_00 + lolo.local_3.f_00 - lolo.local_9.f_00) + /*lolo.local_18*/inline_abs(D_00E2A18C->f_02 + lolo.local_3.f_04 - lolo.local_9.f_08);
		if(lolo.local_10 < lolo.local_4) {
			lolo.local_1->f_00 = D_00E2A18C->f_00 + lolo.local_3.f_00;
			lolo.local_1->f_02 = D_00E2A18C->f_02 + lolo.local_3.f_04;
			lolo.local_1->f_04 = D_00E2AAE0 - lolo.local_11;
		}
		D_00E2AAE0 = lolo.local_1->f_04;
	} else if(D_00E2A10C -- <= 0) {
		D_00E2A10C = (C_00753BE8() + 0x40) >> 2;
		D_00E2BBBC = (C_00753BE8() - 0x80) >> 2;
	}
	D_00E2A18C = lolo.local_1;
	D_00E2AAE0 += D_00E2BBBC;
	if(D_00E2AAE0 < 0)
		D_00E2AAE0 += 0x1000;
	else if(D_00E2AAE0 >= 0x1000)
		D_00E2AAE0 -= 0x1000;
}

void C_0075692A() {
	struct {
		int local_8;
		int local_7;
		struct t_wm_local_30 *local_6;
		struct USVECTOR *local_5;
		struct VECTOR local_4;
	}lolo;

	lolo.local_7 = C_0074C9A5();
	C_0075042B(&lolo.local_4);
	lolo.local_5 = D_00E2A18C - 1;
	if(lolo.local_5 < &(D_00E29F80[0]))
		lolo.local_5 = &(D_00E29F80[0x2f]);//D_00E2A0F8
	for(lolo.local_6 = &(D_00E2A490[0]); lolo.local_6 < &(D_00E2A490[0xc])/*00E2A6D0*/; lolo.local_6 ++) {
		lolo.local_5 += 4;
		if(lolo.local_5 >= &(D_00E29F80[0x30])/*D_00E2A100*/)
			lolo.local_5 -= 0x30;
		if(C_00753366((lolo.local_5->f_00 >> 0xd) + 0x1a, ((lolo.local_5->f_02) >> 0xd) + 0x10)) {//else 00756A8B
			lolo.local_8 = lolo.local_5->f_00 + 0x34000 - lolo.local_4.f_00;
			if(lolo.local_8 < -0x7530 || lolo.local_8 > 0x7530)
				continue;
			lolo.local_6->f_00.pad1 = lolo.local_8;
			lolo.local_8 = lolo.local_5->f_02 + 0x20000 - lolo.local_4.f_08;
			if(lolo.local_8 < -0x7530 || lolo.local_8 > 0x7530)
				continue;
			lolo.local_6->f_00.pad2 = lolo.local_8;
			C_0075D544(0x12c, 0x12c, lolo.local_5->f_06 - C_00762F9A(lolo.local_6->f_00.pad1, lolo.local_6->f_00.pad2) * 4, lolo.local_5->f_04 + 0x800, lolo.local_6, 0);
		}
	}
}

void C_00756A95() {
	D_00E2BB90 =
	D_00E2A178 = 0;
	D_00E2B764 = 0;
	D_00E2BB7C = 0;
	D_00E36110 = 0;
	D_00E2BB88 =
	D_00E29F44 = 0;
	D_00E28F28[0] =
	D_00E28F28[1] =
	D_00E28F28[2] = 0;
	D_00E2BBA8 = 0;

}

void C_00756F45(struct t_wm_local_18 *);

void C_00756B0C(struct t_wm_local_18 *bp08) {
	struct {
		int bp_0c;
		struct t_wm_local_0c *bp_08;
		short bp_04; char _p_04[2];
	}lolo;

	if(D_00E2B764 && bp08 && D_00E2BB80 == bp08->f_10 && D_00E2BB8C == bp08->f_12) {//else 00756F31
		C_00756F45(bp08);
		if(
			C_0074CC07(bp08, &D_00E28F38, 0, &lolo.bp_04, &lolo.bp_08, 0, 0) &&
			(lolo.bp_08->f_0b & 0x40) == 0 &&
			(lolo.bp_08->f_03 & 0xe0) != 0xe0 &&
			BIT_ISSET_2(0x321B6F83, lolo.bp_08->f_03)
		) {//else 00756F27
			D_00E2BB90 ++;
			if(D_00E2BB90 < &(D_00E2A190[0x28])/*00E2A370*/) {//else 00756F1B
				lolo.bp_0c = 0;
				switch(D_00E2B764) {
					case 1:
						if(bp08->f_08[lolo.bp_08->f_00].f_00 > 0x1ff6 && bp08->f_08[lolo.bp_08->f_01].f_00 > 0x1ff6)
							lolo.bp_0c = 1;
						else if(bp08->f_08[lolo.bp_08->f_01].f_00 > 0x1ff6 && bp08->f_08[lolo.bp_08->f_02].f_00 > 0x1ff6)
							lolo.bp_0c = 2;
						else if(bp08->f_08[lolo.bp_08->f_02].f_00 > 0x1ff6 && bp08->f_08[lolo.bp_08->f_00].f_00 > 0x1ff6)
							lolo.bp_0c = 4;
					break;
					case 2:
						if(bp08->f_08[lolo.bp_08->f_00].f_04 > 0x1ff6 && bp08->f_08[lolo.bp_08->f_01].f_04 > 0x1ff6)
							lolo.bp_0c = 1;
						else if(bp08->f_08[lolo.bp_08->f_01].f_04 > 0x1ff6 && bp08->f_08[lolo.bp_08->f_02].f_04 > 0x1ff6)
							lolo.bp_0c = 2;
						else if(bp08->f_08[lolo.bp_08->f_02].f_04 > 0x1ff6 && bp08->f_08[lolo.bp_08->f_00].f_04 > 0x1ff6)
							lolo.bp_0c = 4;
					break;
					case 3:
						if(bp08->f_08[lolo.bp_08->f_00].f_00 < 0xa && bp08->f_08[lolo.bp_08->f_01].f_00 < 0xa)
							lolo.bp_0c = 1;
						else if(bp08->f_08[lolo.bp_08->f_01].f_00 < 0xa && bp08->f_08[lolo.bp_08->f_02].f_00 < 0xa)
							lolo.bp_0c = 2;
						else if(bp08->f_08[lolo.bp_08->f_02].f_00 < 0xa && bp08->f_08[lolo.bp_08->f_00].f_00 < 0xa)
							lolo.bp_0c = 4;
					break;
					case 4:
						if(bp08->f_08[lolo.bp_08->f_00].f_04 < 0xa && bp08->f_08[lolo.bp_08->f_01].f_04 < 0xa)
							lolo.bp_0c = 1;
						else if(bp08->f_08[lolo.bp_08->f_01].f_04 < 0xa && bp08->f_08[lolo.bp_08->f_02].f_04 < 0xa)
							lolo.bp_0c = 2;
						else if(bp08->f_08[lolo.bp_08->f_02].f_04 < 0xa && bp08->f_08[lolo.bp_08->f_00].f_04 < 0xa)
							lolo.bp_0c = 4;
					break;
				}
				if(lolo.bp_0c == 0)
					C_0074C9A0(0x48);
				D_00E2BB90->f_00 = bp08;
				D_00E2BB90->f_04 = lolo.bp_08;
				D_00E2BB90->f_08 = lolo.bp_0c;
				D_00E2B764 = 0;
			} else {
				C_0074C9A0(0x49);
			}
		} else {
			D_00E2B764 = -1;
		}
	}
}

void C_00756F45(struct t_wm_local_18 *bp08) {
	struct t_wm_local_18 **local_1;
	struct t_wm_local_0c *local_2;

	if(bp08) {
		for(local_1 = D_00E2AAE8; local_1 < D_00E2BB7C && *local_1 != bp08; local_1 ++);
		if(local_1 >= D_00E2BB7C) {
			if(D_00E2BB7C >= &(D_00E2AAE8[0x14])/*D_00E2AB38*/)
				C_0074C9A0(0x47);
			*(D_00E2BB7C ++) = bp08;
			for(local_2 = bp08->f_04; local_2 < &(bp08->f_14[bp08->f_04]); local_2 ++)
				local_2->f_0b &= ~0x40;
		}
	}
}

void C_00756FF9(struct t_wm_local_18 *bp08, struct t_wm_local_0c *bp0c) {
	struct VECTOR local_4;

	if(D_00E2BB88 == 0 || D_00E2BB88 == 2 || D_00E2BB88 == 3) {
		D_00E2BB90 = D_00E2A190;
		D_00E2BB90->f_00 = bp08;
		D_00E2BB90->f_04 = bp0c;
		D_00E2BB90->f_08 = 0;
		D_00E2A178 = 0;
		D_00E2B764 = 0;
		D_00E2BB7C = D_00E2AAE8;
		C_00756F45(bp08);
		if(bp0c)
			bp0c->f_0b |= 0x40;
		D_00E36110 = 0;
		D_00E2BB88 = 1;
		C_00762798(&local_4);
		D_00E2AB3C = /*local_5*/(local_4.f_00 >= 0x36000 && local_4.f_00 < 0x40000 && local_4.f_08 >= 0x1c000 && local_4.f_08 < 0x26000);
	}
}

void C_00757260(struct t_wm_local_0c_qqq *, struct VECTOR *);

void C_007570E8(int bp08) {
	struct {
		int local_6;
		int local_5;
		struct VECTOR local_4;
	}lolo;

	if(D_00E2BB88 == 2) {
		lolo.local_5 = C_0076170B();
		lolo.local_6 = /*lolo.local_7*/(lolo.local_5 == 0x29)?1:(lolo.local_5 == 0x2a)?2:0;
		switch(bp08) {
			case 1:
				D_00E28F28[lolo.local_6] = D_00E2A178;
				D_00E2AB40[lolo.local_6] = 5;
				C_00757260(D_00E28F28[lolo.local_6], &lolo.local_4);
				C_007621EF(&lolo.local_4);
			break;
			case 2:
				D_00E28F28[lolo.local_6] = /*lolo.local_9*/min(&(D_00E2A190[2])/*00E2A1A8*/, D_00E2A178);
				D_00E2AB40[lolo.local_6] = 7;
				C_00757260(D_00E28F28[lolo.local_6], &lolo.local_4);
				C_007621EF(&lolo.local_4);
			break;
			case 3:
				D_00E28F28[lolo.local_6] = /*lolo.local_10*/min(&(D_00E2A190[0]), D_00E2A178);
				C_00762047(4);
				C_00757260(D_00E28F28[lolo.local_6], &lolo.local_4);
				C_007621EF(&lolo.local_4);
				D_00E2AB40[lolo.local_6] = 7;
			break;
		}
		D_00E29F44 = bp08;
	}
}

void C_00757260(struct t_wm_local_0c_qqq *bp08, struct VECTOR *bp0c) {
	struct t_wm_local_0c *local_1;
	struct SVECTOR *local_2;

	if(bp0c) {
		local_1 = bp08->f_04;
		local_2 = bp08->f_00->f_08;
		bp0c->f_00 = (local_2[local_1->f_00].f_00 + local_2[local_1->f_01].f_00 + local_2[local_1->f_02].f_00) / 3 + (bp08->f_00->f_10 << 0xd);
		bp0c->f_04 = 0;
		bp0c->f_08 = (local_2[local_1->f_00].f_04 + local_2[local_1->f_01].f_04 + local_2[local_1->f_02].f_04) / 3 + (bp08->f_00->f_12 << 0xd);
	}
}

void C_0075732C(int bp08) {
	C_00762047(/*local_1*/D_00E29F44 == 3?4:/*local_2*/bp08 == 1?0x29:bp08 == 2?0x2a:0x26);
	switch(D_00E29F44) {
		case 3:
			C_007615BA();
			D_00E29F44 = 0;
		break;
		case 1:
			if(C_00761521()) {
				C_007616CB();
				C_007667A3();
			} else {
				C_00764014(C_0076170B(), 5);
			}
		break;
		case 2:
			C_0076160D();
			C_007615BA();
		break;
	}
}

void C_00757494(void);
void C_007585B7(void);

void C_007573D9() {
	C_00757494();
	if(D_00E2BBA8) {//else 00757456
		if(D_00E2BB88 == 3) {//else 00757415
			D_00E2BBA8 = 0;
			D_00E2BB88 = 0;
			C_0074D438(1, 5);
		} else if(D_00E2BB88 == 2) {//else 00757456
			C_0074D2D7(1);
			C_0074DB2B(0x1770);
			C_0074DB38(0x5dc);
			C_007640BC(8);
			D_00E2BBA8 = 0;
		}
	}
	if(D_00E29F44 == 3) {//else 0075748D
		if((D_00E2BB88 == 2 || D_00E2BB88 == 3) && D_00E2AB40[0] == 0 && D_00E2AB40[1] == 0)
			C_007570E8(3);
	}
	C_007585B7();
}

void C_0075749E(void);

void C_00757494() {
	C_0075749E();
}

int C_0075783C(unsigned char, unsigned char);
int C_00757CD4(unsigned char, unsigned char, unsigned char);
int C_00758313(struct t_wm_local_0c_qqq *);

void C_0075749E() {
	struct {
		struct t_wm_local_0c *bp_0c;
		int bp_08;
		int bp_04;
	}lolo;

	lolo.bp_08 = 1;
	if(D_00E2BB90 && D_00E2B764 == 0 && (D_00E36110 == 0 || D_00E2AB3C)) {//else 0075777B
		lolo.bp_0c = D_00E2BB90->f_04;
		D_00E36110 = lolo.bp_0c;
		switch(D_00E2BB90->f_08 & 7) {
			case 0:
				lolo.bp_04 = C_00758313(D_00E2BB90);
				D_00E2BB90->f_08 |= lolo.bp_04;
				switch(lolo.bp_04) {
					case 1: lolo.bp_08 = C_0075783C(lolo.bp_0c->f_00, lolo.bp_0c->f_01); break;
					case 2: lolo.bp_08 = C_0075783C(lolo.bp_0c->f_01, lolo.bp_0c->f_02); break;
					case 4: lolo.bp_08 = C_0075783C(lolo.bp_0c->f_02, lolo.bp_0c->f_00); break;
				}
			break;
			case 6:
				D_00E2BB90->f_08 = 7;
				lolo.bp_08 = C_0075783C(lolo.bp_0c->f_00, lolo.bp_0c->f_01);
			break;
			case 5:
				D_00E2BB90->f_08 = 7;
				lolo.bp_08 = C_0075783C(lolo.bp_0c->f_01, lolo.bp_0c->f_02);
			break;
			case 3:
				D_00E2BB90->f_08 = 7;
				lolo.bp_08 = C_0075783C(lolo.bp_0c->f_02, lolo.bp_0c->f_00);
			break;
			case 4:
				if(C_00757CD4(lolo.bp_0c->f_00, lolo.bp_0c->f_01, lolo.bp_0c->f_02)) {
					D_00E2BB90->f_08 = 5;
					lolo.bp_08 = C_0075783C(lolo.bp_0c->f_00, lolo.bp_0c->f_01);
				} else {
					D_00E2BB90->f_08 = 6;
					lolo.bp_08 = C_0075783C(lolo.bp_0c->f_01, lolo.bp_0c->f_02);
				}
			break;
			case 1:
				if(C_00757CD4(lolo.bp_0c->f_01, lolo.bp_0c->f_02, lolo.bp_0c->f_00)) {
					D_00E2BB90->f_08 = 3;
					lolo.bp_08 = C_0075783C(lolo.bp_0c->f_01, lolo.bp_0c->f_02);
				} else {
					D_00E2BB90->f_08 = 5;
					lolo.bp_08 = C_0075783C(lolo.bp_0c->f_02, lolo.bp_0c->f_00);
				}
			break;
			case 2:
				if(C_00757CD4(lolo.bp_0c->f_02, lolo.bp_0c->f_00, lolo.bp_0c->f_01)) {
					D_00E2BB90->f_08 = 6;
					lolo.bp_08 = C_0075783C(lolo.bp_0c->f_02, lolo.bp_0c->f_00);
				} else {
					D_00E2BB90->f_08 = 3;
					lolo.bp_08 = C_0075783C(lolo.bp_0c->f_00, lolo.bp_0c->f_01);
				}
			break;
			case 7:
				D_00E2BB90 --;
				if(D_00E2BB90 < &(D_00E2A190[0]))
					lolo.bp_08 = 4;
			break;
		}
	} else {//else 007577CA
		if(D_00E2B764 < 0) {//else 007577B0
			D_00E2B764 = 0;
			D_00E2BB90 --;
			if(D_00E2BB90 < &(D_00E2A190[0]))
				lolo.bp_08 = 4;
		} else {
			D_00E2B764 = 0;
			if(D_00E2BB90)
				lolo.bp_08 = 3;
		}
	}
	if(lolo.bp_08 == 3 || lolo.bp_08 == 4) {
		D_00E2A178 = D_00E2BB90;
		D_00E2BB90 = 0;
		if(D_00E2A178 >= &(D_00E2A190[0x28])/*00E2A370*/)
			D_00E2A178 --;
		D_00E2BB88 = (lolo.bp_08 != 3) + 2;
	}
}

int C_0075783C(unsigned char bp08, unsigned char bp0c) {
	struct {
		short local_7; char _ocal_7[2];
		short local_6; char _ocal_6[2];
		short local_5; char _ocal_5[2];
		short local_4; char _ocal_4[2];
		int local_3;
		int local_2;
		struct t_wm_local_0c *local_1;
	}lolo;

	for(lolo.local_3 = 0, lolo.local_1 = D_00E2BB90->f_00->f_04; lolo.local_1 < &(D_00E2BB90->f_00->f_04[D_00E2BB90->f_00->f_14]) && lolo.local_3 == 0; lolo.local_1 ++) {
		if(lolo.local_1 != D_00E2BB90->f_04) {//else 007579B5
			if(
				(bp08 == lolo.local_1->f_00 && bp0c == lolo.local_1->f_01) ||
				(bp08 == lolo.local_1->f_01 && bp0c == lolo.local_1->f_00)
			) {
				lolo.local_3 = 1;
			} else if(
				(bp08 == lolo.local_1->f_01 && bp0c == lolo.local_1->f_02) ||
				(bp08 == lolo.local_1->f_02 && bp0c == lolo.local_1->f_01)
			) {
				lolo.local_3 = 2;
			} else if(
				(bp08 == lolo.local_1->f_02 && bp0c == lolo.local_1->f_00) ||
				(bp08 == lolo.local_1->f_00 && bp0c == lolo.local_1->f_02)
			) {
				lolo.local_3 = 4;
			}
		}
	}
	lolo.local_1 --;
	if(lolo.local_3) {//else 00757A7D
		if(
			(lolo.local_1->f_0b & 0x40) == 0 &&
			(lolo.local_1->f_03 & 0xe0) != 0xe0 &&
			BIT_ISSET_2(0x321B6F83, lolo.local_1->f_03)
		) {//else 00757A71
			lolo.local_1->f_0b |= 0x40;
			D_00E2BB90 ++;
			if(D_00E2BB90 < &(D_00E2A190[0x28])/*00E2A370*/) {//else 00757A68
				D_00E2BB90->f_00 = (D_00E2BB90 - 1)->f_00;
				D_00E2BB90->f_04 = lolo.local_1;
				D_00E2BB90->f_08 = lolo.local_3;
				lolo.local_2 = 0;
			} else {
				lolo.local_2 = 3;
			}
		} else {
			lolo.local_2 = 1;
		}
	} else {
		if(D_00E2BB90 < &(D_00E2A190[0x27])/*00E2A364*/) {//else 00757CC6
			lolo.local_5 = D_00E2BB90->f_00->f_08[bp08].f_00;
			lolo.local_7 = D_00E2BB90->f_00->f_08[bp08].f_04;
			lolo.local_6 = D_00E2BB90->f_00->f_08[bp0c].f_00;
			lolo.local_4 = D_00E2BB90->f_00->f_08[bp0c].f_04;
			D_00E2BB80 = D_00E2BB90->f_00->f_10;
			D_00E2BB8C = D_00E2BB90->f_00->f_12;
			D_00E28F38.f_02 = 0;
			lolo.local_2 = 2;
			if(lolo.local_5 < 0xa && lolo.local_6 < 0xa) {//else 00757B92
				D_00E2BB80 --;
				if(D_00E2BB80 < 0)
					D_00E2BB80 = 0x23;
				D_00E28F38.f_00 = 0x1ff6;
				D_00E28F38.f_04 = (lolo.local_7 + lolo.local_4) >> 1;
				D_00E2B764 = 1;
				//goto 00757CC4
			} else if(lolo.local_7 < 0xa && lolo.local_4 < 0xa) {//else 00757BF3
				D_00E2BB8C --;
				if(D_00E2BB8C < 0)
					D_00E2BB8C = 0x1B;
				D_00E28F38.f_00 = (lolo.local_5 + lolo.local_6) >> 1;
				D_00E28F38.f_04 = 0x1ff6;
				D_00E2B764 = 2;
				//goto 00757CC4
			} else if(lolo.local_5 > 0x1ff6 && lolo.local_6 > 0x1ff6) {//else 00757C58
				D_00E2BB80 ++;
				if(D_00E2BB80 >= 0x24)
					D_00E2BB80 = 0;
				D_00E28F38.f_00 = 0xa;
				D_00E28F38.f_04 = (lolo.local_7 + lolo.local_4) >> 1;
				D_00E2B764 = 3;
				//goto 00757CC4
			} else if(lolo.local_7 > 0x1ff6 && lolo.local_4 > 0x1ff6) {//else 00757CBD
				D_00E2BB8C ++;
				if(D_00E2BB8C >= 0x1c)
					D_00E2BB8C = 0;
				D_00E28F38.f_00 = (lolo.local_5 + lolo.local_6) >> 1;
				D_00E28F38.f_04 = 0xa;
				D_00E2B764 = 4;
				//goto 00757CC4
			} else {
				lolo.local_2 = 1;
			}
		} else {
			lolo.local_2 = 3;
		}
	}

	return lolo.local_2;
}

int C_00757CD4(unsigned char bp08, unsigned char bp0c, unsigned char bp10) {
	struct {
		struct SVECTOR *local_5;
		struct VECTOR local_4;
	}lolo;

	lolo.local_5 = D_00E2BB90->f_00->f_08;
	if(D_00E2AB3C) {//else 00758000
		lolo.local_4.f_00 = 0x3A681;
		lolo.local_4.f_08 = 0x2195F;
		return
			/*lolo.local_6*/inline_abs(lolo.local_4.f_00 - ((lolo.local_5[bp08].f_00 + lolo.local_5[bp0c].f_00) >> 1) - (D_00E2BB90->f_00->f_10 << 0xd)) + /*lolo.local_7*/inline_abs(lolo.local_4.f_08 - ((lolo.local_5[bp08].f_04 + lolo.local_5[bp0c].f_04) >> 1) - (D_00E2BB90->f_00->f_12 << 0xd))
		<
			/*lolo.local_8*/inline_abs(lolo.local_4.f_00 - ((lolo.local_5[bp0c].f_00 + lolo.local_5[bp10].f_00) >> 1) - (D_00E2BB90->f_00->f_10 << 0xd)) + /*lolo.local_9*/inline_abs(lolo.local_4.f_08 - ((lolo.local_5[bp0c].f_04 + lolo.local_5[bp10].f_04) >> 1) - (D_00E2BB90->f_00->f_12 << 0xd))
		;
	} else {
		C_00762798(&lolo.local_4);
		return
			/*lolo.local_10*/inline_abs(lolo.local_4.f_00 - ((lolo.local_5[bp08].f_00 + lolo.local_5[bp0c].f_00) >> 1) - (D_00E2BB90->f_00->f_10 << 0xd)) + /*lolo.local_11*/inline_abs(lolo.local_4.f_08 - ((lolo.local_5[bp08].f_04 + lolo.local_5[bp0c].f_04) >> 1) - (D_00E2BB90->f_00->f_12 << 0xd))
		>
			/*lolo.local_12*/inline_abs(lolo.local_4.f_00 - ((lolo.local_5[bp0c].f_00 + lolo.local_5[bp10].f_00) >> 1) - (D_00E2BB90->f_00->f_10 << 0xd)) + /*lolo.local_13*/inline_abs(lolo.local_4.f_08 - ((lolo.local_5[bp0c].f_04 + lolo.local_5[bp10].f_04) >> 1) - (D_00E2BB90->f_00->f_12 << 0xd))
		;
	}
}

int C_00758313(struct t_wm_local_0c_qqq *bp08) {
	struct {
		struct VECTOR local_18;
			//int local_16;
		int local_14;
		int local_13;
		struct VECTOR local_12;
			//int local_10;
		struct SVECTOR *local_8;
		struct t_wm_local_0c *local_7;
		int local_6;
		struct VECTOR local_5;
			//int local_3;
		int local_1;
	}lolo;

	lolo.local_7 = bp08->f_04;
	lolo.local_8 = bp08->f_00->f_08;
	lolo.local_6 = 1;
	lolo.local_13 = C_0074D298();
	lolo.local_18.f_00 = (lolo.local_8[lolo.local_7->f_00].f_00 + lolo.local_8[lolo.local_7->f_01].f_00 + lolo.local_8[lolo.local_7->f_02].f_00) / 3;
	lolo.local_18.f_08 = (lolo.local_8[lolo.local_7->f_00].f_04 + lolo.local_8[lolo.local_7->f_01].f_04 + lolo.local_8[lolo.local_7->f_02].f_04) / 3;
	if(D_00E2AB3C) {//else 0075840C
		lolo.local_12.f_00 = lolo.local_18.f_00 + (bp08->f_00->f_10 << 0xd);
		lolo.local_12.f_08 = lolo.local_18.f_08 + (bp08->f_00->f_12 << 0xd);
		lolo.local_5.f_00 = 0x3A681;
		lolo.local_5.f_08 = 0x2195F;
		lolo.local_13 = C_00753F2E(&lolo.local_12, &lolo.local_5);
	} else {
		lolo.local_13 = C_0074D298();
	}
	lolo.local_5.f_00 = (lolo.local_8[lolo.local_7->f_00].f_00 + lolo.local_8[lolo.local_7->f_01].f_00) >> 1;
	lolo.local_5.f_08 = (lolo.local_8[lolo.local_7->f_00].f_04 + lolo.local_8[lolo.local_7->f_01].f_04) >> 1;
	lolo.local_14 = (C_00753F2E(&lolo.local_18, &lolo.local_5) - lolo.local_13) & 0xfff;
	if(lolo.local_14 >= 0x800)
		lolo.local_14 = 0x1000 - lolo.local_14;
	lolo.local_5.f_00 = (lolo.local_8[lolo.local_7->f_01].f_00 + lolo.local_8[lolo.local_7->f_02].f_00) >> 1;
	lolo.local_5.f_08 = (lolo.local_8[lolo.local_7->f_01].f_04 + lolo.local_8[lolo.local_7->f_02].f_04) >> 1;
	lolo.local_1 = (C_00753F2E(&lolo.local_18, &lolo.local_5) - lolo.local_13) & 0xfff;
	if(lolo.local_1 >= 0x800)
		lolo.local_1 = 0x1000 - lolo.local_1;
	if(lolo.local_14 > lolo.local_1) {
		lolo.local_14 = lolo.local_1;
		lolo.local_6 = 2;
	}
	lolo.local_5.f_00 = (lolo.local_8[lolo.local_7->f_02].f_00 + lolo.local_8[lolo.local_7->f_00].f_00) >> 1;
	lolo.local_5.f_08 = (lolo.local_8[lolo.local_7->f_02].f_04 + lolo.local_8[lolo.local_7->f_00].f_04) >> 1;
	lolo.local_1 = (C_00753F2E(&lolo.local_18, &lolo.local_5) - lolo.local_13) & 0xfff;
	if(lolo.local_1 >= 0x800)
		lolo.local_1 = 0x1000 - lolo.local_1;
	if(lolo.local_14 > lolo.local_1)
		lolo.local_6 = 4;

	return lolo.local_6;
}

void C_007585B7() {
	struct {
		struct VECTOR local_12;
		struct SVECTOR local_8;
		int local_6;
		struct VECTOR local_5;
		int local_1;
	}lolo;

	for(lolo.local_6 = 0; lolo.local_6 < 3; lolo.local_6 ++) {
		if(D_00E2AB40[lolo.local_6]) {//else 00758A29
			C_00762047(/*lolo.local_13*/(D_00E29F44 == 3)?4:/*lolo.local_14*/(lolo.local_6 == 1)?0x29:(lolo.local_6 == 2)?0x2a:0x26);
			C_00762763(&lolo.local_5);
			if(D_00E2AB40[lolo.local_6] & 4) {//else 0075869A
				if(lolo.local_5.f_00 == 0 && lolo.local_5.f_08 == 0) {//else 0075867E
					C_00757260(D_00E28F28[lolo.local_6], &lolo.local_5);
					C_007621EF(&lolo.local_5);
				} else {
					D_00E2AB40[lolo.local_6] += 4;
				}
				//goto 00758A29
			} else if(D_00E2AB40[lolo.local_6] & 8) {//else 00758A29
				if(D_00E2AB40[lolo.local_6] & 1) {//else 007587DD
					D_00E2AB40[lolo.local_6] &= ~1;
					D_00E28F28[lolo.local_6] += (D_00E2AB40[lolo.local_6] & 2) - 1;
					C_00757260(D_00E28F28[lolo.local_6], &(D_00E29F50[lolo.local_6]));
					if(D_00E28F28[lolo.local_6] > &(D_00E2A190[0]) && D_00E28F28[lolo.local_6] < D_00E2A178) {//else 007587AA
						C_00757260(D_00E28F28[lolo.local_6] + (D_00E2AB40[lolo.local_6] & 2) - 1, &lolo.local_12);
						D_00E29F50[lolo.local_6].f_00 = (lolo.local_12.f_00 + D_00E29F50[lolo.local_6].f_00) >> 1;
						D_00E29F50[lolo.local_6].f_08 = (lolo.local_12.f_08 + D_00E29F50[lolo.local_6].f_08) >> 1;
					}
					D_00E2BB98[lolo.local_6] = C_00753F2E(&lolo.local_5, &(D_00E29F50[lolo.local_6]));
					D_00E2A100[lolo.local_6] = 0x7fff;
				}
				lolo.local_8.f_00 =
				lolo.local_8.f_02 = 0;
				lolo.local_8.f_04 = 0x78;
				C_00761B19(D_00E2BB98[lolo.local_6]);
				C_00753D00(&lolo.local_8, D_00E2BB98[lolo.local_6]);
				C_00762E87(lolo.local_8.f_00, lolo.local_8.f_04);
				lolo.local_1 = /*lolo.local_15*/inline_abs(lolo.local_5.f_00 - D_00E29F50[lolo.local_6].f_00) + /*lolo.local_16*/inline_abs(lolo.local_5.f_08 - D_00E29F50[lolo.local_6].f_08);
				if(lolo.local_1 > D_00E2A100[lolo.local_6]) {//else 00758955
					D_00E2AB40[lolo.local_6] = /*lolo.local_18*/(D_00E2AB40[lolo.local_6] & 2)?
						/*lolo.local_17*/D_00E28F28[lolo.local_6] >= D_00E2A178?0:(D_00E2AB40[lolo.local_6] | 1)
					:
						/*lolo.local_19*/D_00E28F28[lolo.local_6] <= &(D_00E2A190[lolo.local_6]) + (lolo.local_6 > 0)?0:(D_00E2AB40[lolo.local_6] | 1)
					;
				}
				D_00E2A100[lolo.local_6] = lolo.local_1;
				if(D_00E2AB3C && /*lolo.local_20*/inline_abs(lolo.local_5.f_00 - 0x3a681) + /*lolo.local_21*/inline_abs(lolo.local_5.f_08 - 0x2195f) < 0x7d0)
					D_00E2AB40[lolo.local_6] = 0;
				if(D_00E2AB40[lolo.local_6] == 0) {//else 00758A29
					C_0075732C(lolo.local_6);
					if(D_00E29F44 == 2) {//else 00758A29
						if(lolo.local_6 == 2 || (lolo.local_6 == 1 && C_00762047(0x2a) == 0)) {//else 00758A29
							C_0074D2D7(0);
							C_0074D438(1, 5);
						}
					}
				}
			}
		}
	}
}

void C_00758A32(int bp08) {
	D_00E29F44 = bp08;
}

int C_00758A3F() {
	return /*local_1*/(D_00E2BB88 == 2)?1:(D_00E2BB88 == 3)?-1:0;
}

int C_00758A6C() {
	return D_00E2AB40[0] == 0 && D_00E2AB40[1] == 0 && D_00E2AB40[2] == 0?0:1;
}

void __00758AA2() {
	D_00E2BBA8 = 1;
	if(D_00E2BB88 != 1)
		D_00E2BB88 = 0;
}

void C_00758AC4(int bp08) {
	D_00E29F48 = bp08;
	D_00E2B75C =
	D_00E28F24 =
	D_00E2A118 =
	D_00E2A6D0 =
	D_00E2BB78 = 0;
}

int C_00758B12(int bp08, int bp0c) {
	struct {
		struct VECTOR local_7;
		struct SVECTOR local_3;
		short local_1; char _ocal_1[2];
	}lolo;

	lolo.local_1 = C_0074D298();
	if(D_00E28F24 == D_00E2A118) {
		D_00E2BB78 = C_00761EB6() + lolo.local_1;
		C_00755C10(1);
		C_00755C10(2);
	} else if(D_00E28F24 < D_00E2A118) {
		C_00761B83(D_00E2BB78 - lolo.local_1);
	}
	D_00E28F24 -= /*lolo.local_8*/(bp08 == 0 && D_00E28F24 >= D_00E2A118)?0:1;
	if(D_00E28F24 <= 0) {
		D_00E28F24 =
		D_00E2A6D0 = C_00753BE8() + 0x80;
		D_00E2A118 = (C_00753BE8() >> 3) + 0x40;
		D_00E2B75C = ((C_00753BE8() & 2) - 1) << 4;
	}
	if(D_00E28F24 >= D_00E2A118 && bp0c) {//else 00758CDF
		if(C_00762047(D_00E29F48 + 0x15) == 0) {
			C_007610B3();
			C_0076197B(D_00E29F48 + 0x15);
		}
		D_00E29F48 = (D_00E29F48 + 1) % 3;
		lolo.local_3.f_00 =
		lolo.local_3.f_02 = 0;
		lolo.local_3.f_04 = 0x12c;
		C_00753D00(&lolo.local_3, -lolo.local_1);
		C_00762798(&lolo.local_7);
		lolo.local_7.f_00 += lolo.local_3.f_00;
		lolo.local_7.f_08 += lolo.local_3.f_04;
		C_007621EF(&lolo.local_7);
		C_00761BAC(-lolo.local_1);
		C_007616B3();
	}

	return /*lolo.local_9*/(D_00E28F24 < D_00E2A118)?D_00E2B75C:0;
}

int C_00758D0B() {
	return D_00E29F48;
}

void C_00758D17(unsigned bp08) {
	D_00969CA8[0].f_06/*D_00969CAE*/ = bp08 & 0xff;
	D_00969CA8[1].f_06/*D_00969CC2*/ = (bp08 >> 8) & 0xff;
	D_00969CA8[2].f_06/*D_00969CD6*/ = (bp08 >> 16) & 0xff;
	D_00E2B760 = (bp08 >> 24) & 0xff;
	D_00E2A13C =
	D_00E2A140 = 0;
}

int C_00758D76() {
	return D_00969CA8[0].f_06 | (D_00969CA8[1].f_06 << 8) | (D_00969CA8[2].f_06 << 16) | D_00E2B760 << 24;
}

struct t_wm_local_14 *C_00759151(short, short);

void C_00758DA5(short bp08, short bp0c) {
	struct {
		struct SVECTOR local_28;
		struct t_g_drv_0c *local_26;
		struct VECTOR local_25;
		struct MATRIX local_21;
		char *local_13;
		struct SVECTOR local_12;
		struct VECTOR local_10;
		int local_6;
		int local_5;
		struct SVECTOR local_4;
		int local_2;
		struct t_wm_local_14 *local_1;
	}lolo;

	lolo.local_1 = C_00759151(bp08, bp0c);
	if(lolo.local_1 && lolo.local_1->f_06) {//else 00759138
		lolo.local_5 = (D_00E2B760 << 6) & 0xfff;
		D_00E2B760 ++;
		lolo.local_4.f_00 = 0;
		lolo.local_4.f_02 = lolo.local_1->f_04;
		lolo.local_4.f_04 = (lolo.local_1->f_06 * C_00662538(lolo.local_5)) >> 0x11;//psx:sin
		C_006628DE(&lolo.local_4, &lolo.local_21);//psx:xyz_rotate(1)
		C_00663673(&lolo.local_21);//psx:SetRotMatrix?
		lolo.local_10.f_00 =
		lolo.local_10.f_08 = 0;
		lolo.local_10.f_04 = 0x4e20;
		C_00663766(&lolo.local_21, &lolo.local_10);//psx:set translate vector?
		C_00663707(&lolo.local_21);//psx:SetTransMatrix?
		for(lolo.local_13 = &(lolo.local_1->f_08[0]); lolo.local_13 < &(lolo.local_1->f_08[0xc]) && *lolo.local_13 >= 0; lolo.local_13 ++) {
			lolo.local_26 = &(D_00E38338[*lolo.local_13]);
			lolo.local_12.f_00 = 0;
			lolo.local_12.f_02 = (short)lolo.local_26->f_04 - 0x4e20;
			lolo.local_12.f_04 = 0;
			C_00662ECC(&lolo.local_12, &lolo.local_10, &lolo.local_2);//psx:RotTrans
			lolo.local_26->f_00 += (float)lolo.local_10.f_00;
			lolo.local_26->f_04 = (float)lolo.local_10.f_04;
			lolo.local_26->f_08 += (float)lolo.local_10.f_08;
		}
		C_00762798(&lolo.local_10);
		C_00750134(&lolo.local_10, &lolo.local_12, 0, 0);
		if(C_0075045C()) {//else 00758F9E
			lolo.local_28.f_00 = 0;
			lolo.local_28.f_02 = 0;
			lolo.local_28.f_04 = 0x28;
			lolo.local_28.f_06 = 0;
			C_00753D00(&lolo.local_28, C_00753DA9(lolo.local_1->f_00 - lolo.local_12.f_00, lolo.local_1->f_02 - lolo.local_12.f_04));
			D_00E2A13C = lolo.local_28.f_00;
			D_00E2A140 = lolo.local_28.f_04;
			//goto 00759136
		} else {
			lolo.local_6 = (lolo.local_1->f_06 * /*lolo.local_31*/max(0, 0xdac - inline_abs(lolo.local_12.f_00 - lolo.local_1->f_00) - inline_abs(lolo.local_12.f_04 - lolo.local_1->f_02))) >> 0xc;
			lolo.local_4.f_00 = 0;
			lolo.local_4.f_02 = lolo.local_1->f_04;
			lolo.local_4.f_04 = (lolo.local_6 * C_006624FD(lolo.local_5)) >> 0x10;//psx:cos
			C_006628DE(&lolo.local_4, &lolo.local_21);//psx:xyz_rotate(1)
			C_00663673(&lolo.local_21);//psx:SetRotMatrix?
			lolo.local_12.f_00 = 0;
			lolo.local_12.f_02 = lolo.local_10.f_04 - 0x4e20;
			lolo.local_12.f_04 = 0;
			C_00662ECC(&lolo.local_12, &lolo.local_25, &lolo.local_2);//psx:RotTrans
			D_00E2A13C = lolo.local_25.f_00 >> 4;
			D_00E2A140 = lolo.local_25.f_08 >> 4;
		}
	} else {
		D_00E2A13C =
		D_00E2A140 = 0;
	}
}

struct t_wm_local_14 *C_00759151(short bp08, short bp0c) {
	return
		(bp08 == 5 && bp0c == 0x12)?&(D_00969CA8[0]):
		(bp08 == 4 && bp0c == 0x11)?&(D_00969CA8[1]):
		(bp08 == 4 && bp0c == 0xe)?&(D_00969CA8[2]):
		0
	;
}

void C_007591C2(int *bp08, int *bp0c) {
	if(bp08)
		*bp08 += D_00E2A13C;
	if(bp0c)
		*bp0c += D_00E2A140;
}

void C_007591F3() {
	struct {
		short local_7; char _ocal_7[2];
		short local_6; char _ocal_6[2];
		struct VECTOR local_5;
		struct t_wm_local_14 *local_1;
	}lolo;

	if(C_00762136() == 0xe && (C_007186B9() & 0xf000)) {//menu_input:get "current mask"
		C_00762798(&lolo.local_5);
		C_00750134(&lolo.local_5, 0, &lolo.local_6, &lolo.local_7);
		lolo.local_1 = C_00759151(lolo.local_6, lolo.local_7);
		if(lolo.local_1 && lolo.local_1->f_06 < 0x64)
			lolo.local_1->f_06 += 0xa;
		C_0075E6CC(0xcb);//start/stop SFX?
	}
	for(lolo.local_1 = &(D_00969CA8[0]); lolo.local_1 < &(D_00969CA8[3])/*00969CE4*/; lolo.local_1 ++) {
		lolo.local_1->f_06 -= lolo.local_1->f_06 > 0;
		if(lolo.local_1->f_06 == 1)
			C_0075E6CC(-0xcb);//start/stop SFX?
	}
}
