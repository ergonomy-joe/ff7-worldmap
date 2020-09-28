/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//WORLD MAP -- 

#include "ff7.h"
#include "wm_data.h"
////////////////////////////////////////
struct t_wm_local_54 {
	struct t_wm_local_54 *f_00;
	struct VECTOR f_04;
	short f_14;
	short f_16;
	short f_18;
	short f_1a;
	unsigned char f_1c;
	unsigned char f_1d;
	unsigned char f_1e;
	unsigned char f_1f;
	//
	short f_20;
	char __22[2];
	struct t_wm_local_30 f_24;
};

struct t_wm_local_spr_0c {//size 0xc
	unsigned char f_00;
	unsigned char f_01;
	unsigned char f_02;
	unsigned char f_03;
	unsigned char f_04;
	unsigned char f_05;
	unsigned char f_06;
	unsigned char f_07;
	short f_08;
	char __0a,__0b;
};
////////////////////////////////////////
unsigned char *D_00E2D608;
struct t_wm_local_54 *D_00E2D60C;
//char 00E2D610[0x8000]
unsigned D_00E35610;
//00E35614
char D_00E35638[2][4];
struct t_wm_local_54 *D_00E35640;
//00E35644
struct t_wm_local_54 *D_00E35648;
int D_00E3564C;
struct t_wm_local_54 *D_00E35650;
int D_00E35654;
int D_00E35658;
//00E3565C
struct t_wm_local_54 D_00E35660[0x20];
//00E360E0
int D_00E360EC;
//D_00E360F0
////////////////////////////////////////
void C_0075AC80() {
	int i;

	for(i = 0; i < 0x1f; i ++)
		D_00E35660[i].f_00 = &(D_00E35660[i + 1]);
	D_00E35660[i].f_00 = 0;
	D_00E35640 = &(D_00E35660[0]);
	D_00E35648 =
	D_00E35650 =
	D_00E2D60C = 0;
	D_00E35610 = 0;
	for(i = 0; i < 2; i ++)
		D_00E35638[i][2] = 0;
}

void C_0075B8F3(short, short, short, int);

void C_0075AD28(struct t_local_unknown_c0 *bp08, int bp0c) {
	struct {//x68
		//local_23 and above for compiler
		struct MATRIX local_22;
		struct VECTOR local_14;
		short local_10; char _ocal_10[2];
		struct SVECTOR local_9;
		int local_7;
		int local_6;
		int local_5;
		int local_4;
		int local_3;
		int local_2;
		int local_1;
	}lolo;

	lolo.local_2 = bp08->f_4a & 0x1f;
	D_00E2D200 =
	lolo.local_3 = bp08->f_3c + bp08->f_3e;
	D_00E2D1E0 = bp08->f_1c;

	D_00E2D1F0.f_00 = D_00E2D1F0.f_02 = D_00E2D1F0.f_04 = 0;
	D_00E2D1F8.f_00 = D_00E2D1F8.f_02 = D_00E2D1F8.f_04 = 0;

	if(bp08->f_50 == 3) {//else 0075B13E
		if(
			bp0c &&
			C_00768C59() &&
			C_0074D504() >= 0 &&
			/*lolo.local_23*/inline_abs(bp08->f_0c.f_00 - bp08->f_1c.f_00) + /*lolo.local_24*/inline_abs(bp08->f_0c.f_08 - bp08->f_1c.f_08) > 0x64
		) {//else 0075AFEE
			lolo.local_6 = D_00E35610 % 3;
			lolo.local_7 = D_00E35610 % 6;
			lolo.local_4 = C_0074D319();
			lolo.local_5 = lolo.local_4 * 4 + lolo.local_3;
			D_00E2D1E0 = bp08->f_0c;
			D_00E2D1F8.f_00 = 0x12c;
			D_00E2D1F8.f_02 = 0x190 - max(0, lolo.local_4);
			D_00E2D1F8.f_04 = -0x5a;
			C_0075B8F3(lolo.local_5, 0, ((lolo.local_4 * 4 < 0xc8)?0x24:0x27) + lolo.local_6, 0);
			C_0075B8F3(lolo.local_5, 0, lolo.local_7 + 0x32, 0);
			D_00E2D1F8.f_00 = -0x12c;
			D_00E2D1F8.f_02 = 0x190 + min(0, lolo.local_4);
			C_0075B8F3(lolo.local_5, 0, ((lolo.local_4 * 4 > -0xc8)?0x27:0x24) + lolo.local_6, 0);
			C_0075B8F3(lolo.local_5, 0, lolo.local_7 + 0x32, 0);
			D_00E2D1F8.f_00 = 0;
			D_00E2D1F8.f_02 = 0x12c;
			D_00E2D1F8.f_04 = -0x12c;
			C_0075B8F3(lolo.local_5, 0, lolo.local_6 + 0x2a, 0);
			C_0075B8F3(lolo.local_5, 0, lolo.local_7 + 0x32, 0);
		}
		if(lolo.local_2 >= 3 && lolo.local_2 <= 7 && bp08->f_0c.f_04 < bp08->f_42 + 0x3e8 && (bp08->f_53 % 3) == 0) {//else 0075B139
			D_00E2D1F8.f_00 = D_00E2D1F8.f_02 = D_00E2D1F8.f_04 = 0;
			D_00E2D1F0.f_00 = (bp08->f_0c.f_00 - bp08->f_1c.f_00) >> 1;
			D_00E2D1F0.f_02 = 0x32;
			D_00E2D1F0.f_04 = (bp08->f_0c.f_08 - bp08->f_1c.f_08) >> 1;
			if(/*lolo.local_25*/inline_abs(D_00E2D1F0.f_00) + /*lolo.local_26*/inline_abs(D_00E2D1F0.f_04) > 0x19) {//else 0075B139
				D_00E2D1E0.f_00 -= D_00E2D1F0.f_00 * 4;
				D_00E2D1E0.f_04 = bp08->f_42;
				D_00E2D1E0.f_08 -= D_00E2D1F0.f_04 * 4;
				C_0075B8F3(0, 0x700, 0, 0);
				C_0075B8F3(0, 0x900, 1, 0);
			}
		}
		// goto 0075B8EF
	} else if(bp0c && C_0076192A(bp08->f_50) && (bp08->f_53 == 2 || bp08->f_53 == 0xe) && ((0x1110701 >> lolo.local_2) & 1)) {//else 0075B21D
		D_00E2D1F0.f_00 = bp08->f_0c.f_00 - bp08->f_1c.f_00;
		D_00E2D1F0.f_02 = 0x64;
		D_00E2D1F0.f_04 = bp08->f_0c.f_08 - bp08->f_1c.f_08;
		D_00E2D1E0.f_00 -= D_00E2D1F0.f_00;
		D_00E2D1E0.f_04 += 0x64;
		D_00E2D1E0.f_08 -= D_00E2D1F0.f_04;
		C_0075B8F3(0, 0x800, (lolo.local_2 != 0xa) + 5, 0x32);
		//goto 0075B8EF
	} else if(lolo.local_2 == 0xa && C_0074D330() != 3 && bp0c) {//else 0075B31D
		if(C_00761805(7, bp08->f_50) && (bp08->f_53 == 1 || bp08->f_53 == 8)) {//else 0075B2B5
			D_00E2D1F8.f_04 = 0x28;
			C_0075B8F3(((bp08->f_53 >> 3)?0x400:0xc00) + lolo.local_3, 0, (bp08->f_53 >> 3)?2:3, 0);
		} else if(C_0076192A(bp08->f_50) && (bp08->f_53 == 1 || bp08->f_53 == 0xd)) {//else 0075B318
			D_00E2D1F8.f_04 = 0x78;
			C_0075B8F3(((bp08->f_53 >> 3)?0xc00:0x400) + lolo.local_3, 0, 4, 0);
		}
		//goto 0075B8EF
	} else if(C_00761805(7, bp08->f_50) && ((lolo.local_2 & 0xf) == 8 || lolo.local_2 == 0x1c) && (bp08->f_53 == 1 || bp08->f_53 == 8)) {//else 0075B38D
		D_00E2D1F0.f_00 = 0;
		D_00E2D1F0.f_02 = 0x14;
		D_00E2D1F0.f_04 = 0;
		C_0075B8F3(0, 0, 8, 0);
		//goto 0075B8EF
	} else if(C_00761805(0x20, bp08->f_50) && C_00761FE8() == 0) {//else 0075B404
		if(bp0c && (bp08->f_53 % 3) == 0) {//else 0075B3FF
			D_00E2D1F8.f_00 = 0x190;
			C_0075B8F3(lolo.local_3, 0, 9, 0);
			D_00E2D1F8.f_00 = -0x1f4;
			C_0075B8F3(lolo.local_3, 0, 9, 0);
		}
		//goto 0075B8EF
	} else if(bp0c && (C_00761805(7, bp08->f_50) || C_0076192A(bp08->f_50)) && (lolo.local_2 == 1 || lolo.local_2 == 0x19) && (bp08->f_53 % 3) == 0) {//else 0075B47C
		D_00E2D1E0.f_04 += 0x12c;
		C_0075B8F3(lolo.local_3, 0, 0xa, 0);
		//goto 0075B8EF
	} else if(C_00761805(7, bp08->f_50) && lolo.local_2 == 7) {//else 0075B4F3
		if(bp0c && (bp08->f_53 == 1 || bp08->f_53 == 8)) {
			D_00E2D1F0.f_00 = bp08->f_0c.f_00 - bp08->f_1c.f_00;
			D_00E2D1F0.f_04 = bp08->f_0c.f_08 - bp08->f_1c.f_08;
			C_0075B8F3(0, 0x800, 0xc, 0);
		}
		//goto 0075B8EF
	} else if(bp0c && C_0076192A(bp08->f_50) && lolo.local_2 >= 3 && lolo.local_2 <= 7 && (bp08->f_53 == 1 || bp08->f_53 == 0xd)) {//else 0075B553
		D_00E2D1F8.f_04 = -0x64;
		C_0075B8F3(lolo.local_3, 0, 0xd, 0);
		//goto 0075B8EF
	} else if(bp0c && bp08->f_50 == 6) {//else 0075B76C
		if((lolo.local_2 == 1 || lolo.local_2 == 0x19) && (bp08->f_53 % 3) == 0) {//else 0075B5B5
			D_00E2D1E0.f_04 += 0x12c;
			C_0075B8F3(0, 0, 0xe, 0);
		} else if((bp08->f_53 % 3) == 0) {
			lolo.local_10 = (lolo.local_2 != 4)?0x10:0xf;

			D_00E2D1F0.f_02 = 0x14;
			D_00E2D1F8.f_02 = 0x64;
			D_00E2D1F8.f_04 = -0x12c;
			D_00E2D1F8.f_00 = 0x96;

			lolo.local_22.f_12[0] =
			lolo.local_22.f_12[1] =
			lolo.local_22.f_12[2] = 0;

			psx_SetTransMatrix(&lolo.local_22);

			lolo.local_22.f_00[0][0] =
			lolo.local_22.f_00[1][1] =
			lolo.local_22.f_00[2][2] = 0x1000;

			lolo.local_22.f_00[0][1] =
			lolo.local_22.f_00[0][2] =
			lolo.local_22.f_00[1][0] =
			lolo.local_22.f_00[1][2] =
			lolo.local_22.f_00[2][0] =
			lolo.local_22.f_00[2][1] = 0;

			C_0076312D(&lolo.local_9);
			psx_RotMatrixY(lolo.local_3, &lolo.local_22);
			psx_RotMatrixX(lolo.local_9.f_00, &lolo.local_22);
			psx_RotMatrixZ(lolo.local_9.f_04, &lolo.local_22);
			psx_SetRotMatrix(&lolo.local_22);
			psx_RotTrans(&D_00E2D1F8, &lolo.local_14, &lolo.local_1);

			D_00E2D1F8.f_00 = lolo.local_14.f_00;
			D_00E2D1F8.f_02 = lolo.local_14.f_04;
			D_00E2D1F8.f_04 = lolo.local_14.f_08;
			C_0075B8F3(0, 0, lolo.local_10, 0xa);
			psx_SetRotMatrix(&lolo.local_22);

			D_00E2D1F8.f_00 = -0x96;
			D_00E2D1F8.f_02 = 0x64;
			D_00E2D1F8.f_04 = -0x12c;
			psx_RotTrans(&D_00E2D1F8, &lolo.local_14, &lolo.local_1);
			D_00E2D1F8.f_00 = lolo.local_14.f_00;
			D_00E2D1F8.f_02 = lolo.local_14.f_04;
			D_00E2D1F8.f_04 = lolo.local_14.f_08;

			C_0075B8F3(0, 0, lolo.local_10, 0xa);
		}
		//goto 0075B8EF
	} else if(bp0c && bp08->f_50 == 0xd) {//else 0075B811
		if(C_0074D330() == 2 && (bp08->f_53 & 7) == 0) {//else 0075B7D3
			D_00E2D1F8.f_02 = 0xc8;
			D_00E2D1F8.f_04 = -0x190;
			D_00E2D1F0.f_02 = 0x32;
			C_0075B8F3(lolo.local_3, lolo.local_3, 0x11, 0);
		} else if(C_0074D330() == 0) {
			D_00E2D1F8.f_02 = 0xF0;
			D_00E2D1F8.f_04 = -0x1f4;
			C_0075B8F3(lolo.local_3, 0, (D_00E35610 & 3) + 0x2d, 0);
		}
		//goto 0075B8EF
	} else if(bp0c && bp08->f_50 == 0x1e && (bp08->f_53 & 0xf) == 0) {//else 0075B8B1
		D_00E2D1F8.f_00 = 0x258;
		D_00E2D1F8.f_02 = 0x3E8;
		D_00E2D1F8.f_04 = -0x190;
		D_00E2D1F0.f_02 = 0x32;
		C_0075B8F3(lolo.local_3, lolo.local_3, 0x11, 0);
		D_00E2D1F8.f_00 = -0x258;
		D_00E2D1F8.f_02 = 0x3E8;
		D_00E2D1F8.f_04 = -0x190;
		D_00E2D1F0.f_02 = 0x32;
		C_0075B8F3(lolo.local_3, lolo.local_3, 0x11, 0);
		//goto 0075B8EF
	} else if(bp0c && bp08->f_50 == 8 && (bp08->f_53 & 3) == 0) {//else 0075B8EF
		D_00E2D1F8.f_04 = -0x2bc;
		C_0075B8F3(lolo.local_3, 0, 0x12, 0);
	}
//0075B8EF
}

unsigned char D_0096D598[] = {0x0D,0x33,0x2F,0x07,0x2C,0x00,0x00,0x00};
unsigned char D_0096D5A0[] = {0x47,0x33,0x2F,0x07,0x2C,0x46,0x48,0x00};
unsigned char D_0096D5A8[] = {0x55,0x00,0x00,0x07,0x00,0x00,0x00,0x00};
unsigned char D_0096D5B0[] = {0x4D,0x00,0x00,0x07,0x00,0x00,0x00,0x00};

unsigned char D_0096D5B8[][4] = {
	{0x00,1,0,0}, {0x05,1,0,0}, {0x0A,1,0,0}, {0x0B,1,0,0},
#define D_0096D5D4 (D_0096D5B8[7][0])
	{0x0C,1,0,0}, {0x0D,0,0,0}, {0x10,0,0,0}, {0x13,1,0,0},
	{0x19,0,0,0}, {0x1E,1,0,0}, {0x22,0,0,0}, {0x27,1,0,0},
	{0x2A,1,0,0}, {0x2D,0,0,0}, {0x31,0,0,0}, {0x35,0,0,0},
	{0x38,0,0,0}, {0x3C,0,0,0}, {0x40,1,0,0}, {0x14,0,0,0},
	{0x44,0,0,0}, {0x4A,0,0,0}, {0x4E,0,0,0}, {0x4F,0,0,0},
	{0x52,1,0,0}, {0x56,1,0,0}, {0x5A,1,0,0}, {0x5E,1,0,0},
	{0x62,1,0,0}, {0x63,1,0,0}, {0x64,1,0,0}, {0x65,1,0,0},
	{0x66,1,0,0}, {0x67,1,0,0}, {0x68,1,0,0}, {0x69,1,0,0},
	{0x6A,0,0,0}, {0x6B,0,0,0}, {0x6C,0,0,0}, {0x6D,0,0,0},
	{0x6E,0,0,0}, {0x6F,0,0,0}, {0x70,0,0,0}, {0x71,0,0,0},
	{0x72,0,0,0}, {0x73,1,0,0}, {0x74,1,0,0}, {0x75,1,0,0},
	{0x76,1,0,0}, {0x77,0,0,0}, {0x7B,0,0,0}, {0x7C,0,0,0},
	{0x7D,0,0,0}, {0x7E,0,0,0}, {0x7F,0,0,0}, {0x80,0,0,0},
#define D_0096D69C (D_0096D5B8[0x39][0])
	{0x81,0,0,0}, {0x84,0,0,0}, {0x88,0,0,0}, {0x00,0,0,0}
};

struct t_wm_local_spr_0c D_0096D6A8[] = {
	{0x81,0x01,0x20,0x20,0x00,0x20,0x0F,0x2F,0x0000,0x00,0x00},
	{0x01,0x01,0x20,0x20,0x10,0x20,0x1F,0x2F,0x0000,0x00,0x00},
	{0x01,0x01,0x20,0x20,0x20,0x20,0x2F,0x2F,0x0000,0x00,0x00},
	{0x02,0x01,0x20,0x20,0x30,0x20,0x3F,0x2F,0x0000,0x00,0x00},
	{0x02,0x01,0x20,0x20,0x40,0x20,0x4F,0x2F,0x0000,0x00,0x00},
	{0x81,0x01,0x20,0x20,0x0F,0x20,0x00,0x2F,0x0000,0x00,0x00},
	{0x01,0x01,0x20,0x20,0x1F,0x20,0x10,0x2F,0x0000,0x00,0x00},
	{0x01,0x01,0x20,0x20,0x2F,0x20,0x20,0x2F,0x0000,0x00,0x00},
	{0x02,0x01,0x20,0x20,0x3F,0x20,0x30,0x2F,0x0000,0x00,0x00},
	{0x02,0x01,0x20,0x20,0x4F,0x20,0x40,0x2F,0x0000,0x00,0x00},
	{0xFF,0x02,0x08,0x08,0x38,0x00,0x3F,0x0F,0x0001,0x00,0x00},
	{0xFF,0x02,0x08,0x08,0x30,0x00,0x37,0x0F,0x0001,0x00,0x00},
	{0xFF,0x02,0x10,0x10,0x00,0x00,0x0F,0x0F,0x0002,0x00,0x00},
	{0x81,0x01,0x20,0x20,0x00,0x30,0x0F,0x3F,0x0003,0x00,0x00},
	{0x01,0x01,0x20,0x20,0x10,0x30,0x1F,0x3F,0x0003,0x00,0x00},
	{0x01,0x01,0x20,0x20,0x20,0x30,0x2F,0x3F,0x0003,0x00,0x00},
	{0x82,0x01,0x20,0x20,0x00,0x10,0x0F,0x1F,0x0004,0x00,0x00},
	{0x02,0x01,0x20,0x20,0x10,0x10,0x1F,0x1F,0x0004,0x00,0x00},
	{0x03,0x01,0x20,0x20,0x20,0x10,0x2F,0x1F,0x0004,0x00,0x00},
	{0x8A,0x05,0x00,0x00,0xC0,0x00,0xFF,0x3F,0x0019,0x00,0x00},
	{0x83,0x00,0x20,0x20,0x80,0x80,0x9F,0x9F,0x0005,0x00,0x00},
	{0x03,0x00,0x20,0x20,0xA0,0x80,0xBF,0x9F,0x0005,0x00,0x00},
	{0x03,0x00,0x20,0x20,0x80,0xA0,0x9F,0xBF,0x0005,0x00,0x00},
	{0x03,0x00,0x20,0x20,0xA0,0xA0,0xBF,0xBF,0x0005,0x00,0x00},
	{0x03,0x00,0x20,0x20,0xA0,0xC0,0xBF,0xDF,0x0005,0x00,0x00},
	{0x81,0x01,0x10,0x10,0x00,0x40,0x07,0x47,0x0006,0x00,0x00},
	{0x01,0x01,0x10,0x10,0x08,0x40,0x0F,0x47,0x0006,0x00,0x00},
	{0x01,0x01,0x10,0x10,0x10,0x40,0x17,0x47,0x0006,0x00,0x00},
	{0x02,0x01,0x10,0x10,0x18,0x40,0x1F,0x47,0x0006,0x00,0x00},
	{0x02,0x01,0x10,0x10,0x20,0x40,0x27,0x47,0x0006,0x00,0x00},
	{0x81,0x00,0x20,0x20,0x00,0x58,0x0F,0x67,0x0007,0x00,0x00},
	{0x01,0x00,0x20,0x20,0x10,0x58,0x1F,0x67,0x0007,0x00,0x00},
	{0x02,0x00,0x20,0x20,0x20,0x58,0x2F,0x67,0x0007,0x00,0x00},
	{0x02,0x00,0x20,0x20,0x30,0x58,0x3F,0x67,0x0007,0x00,0x00},
	{0x81,0x00,0x18,0x18,0x00,0x68,0x0F,0x77,0x0008,0x00,0x00},
	{0x01,0x00,0x18,0x18,0x10,0x68,0x1F,0x7F,0x0008,0x00,0x00},
	{0x02,0x00,0x18,0x18,0x20,0x68,0x2F,0x77,0x0008,0x00,0x00},
	{0x02,0x00,0x18,0x18,0x30,0x68,0x3F,0x77,0x0008,0x00,0x00},
	{0x02,0x00,0x18,0x18,0x40,0x68,0x4F,0x77,0x0008,0x00,0x00},
	{0x82,0x00,0x20,0x20,0x00,0x90,0x17,0xA7,0x0009,0x00,0x00},
	{0x03,0x00,0x20,0x20,0x18,0x90,0x2F,0xA7,0x0009,0x00,0x00},
	{0x04,0x00,0x20,0x20,0x30,0x90,0x47,0xA7,0x0009,0x00,0x00},
	{0x82,0x00,0x18,0x18,0x00,0x80,0x0F,0x8F,0x0009,0x00,0x00},
	{0x02,0x00,0x18,0x18,0x10,0x80,0x1F,0x8F,0x0009,0x00,0x00},
	{0x02,0x00,0x18,0x18,0x20,0x80,0x2F,0x8F,0x0009,0x00,0x00},
	{0x82,0x00,0x20,0x20,0x00,0xA8,0x17,0xC7,0x000A,0x00,0x00},
	{0x02,0x00,0x20,0x20,0x18,0xA8,0x2F,0xC7,0x000A,0x00,0x00},
	{0x02,0x00,0x20,0x20,0x30,0xA8,0x47,0xC7,0x000A,0x00,0x00},
	{0x02,0x00,0x20,0x20,0x48,0xA8,0x5F,0xC7,0x000A,0x00,0x00},
	{0x82,0x00,0x30,0x30,0x00,0xC8,0x17,0xDF,0x000B,0x00,0x00},
	{0x02,0x00,0x30,0x30,0x18,0xC8,0x2F,0xDF,0x000B,0x00,0x00},
	{0x02,0x00,0x30,0x30,0x30,0xC8,0x47,0xDF,0x000B,0x00,0x00},
	{0x02,0x00,0x30,0x30,0x48,0xC8,0x5F,0xDF,0x000B,0x00,0x00},
	{0x82,0x00,0x20,0x20,0x60,0xE0,0x77,0xF7,0x000C,0x00,0x00},
	{0x02,0x00,0x20,0x20,0x78,0xE0,0x8F,0xF7,0x000C,0x00,0x00},
	{0x02,0x00,0x20,0x20,0x90,0xE0,0xA7,0xF7,0x000C,0x00,0x00},
	{0x82,0x00,0x20,0x20,0x00,0xE0,0x17,0xF7,0x000D,0x00,0x00},
	{0x02,0x00,0x20,0x20,0x18,0xE0,0x2F,0xF7,0x000D,0x00,0x00},
	{0x02,0x00,0x20,0x20,0x30,0xE0,0x47,0xF7,0x000D,0x00,0x00},
	{0x02,0x00,0x20,0x20,0x48,0xE0,0x5F,0xF7,0x000D,0x00,0x00},
	{0x82,0x00,0x18,0x18,0x40,0x00,0x4F,0x0F,0x000E,0x00,0x00},
	{0x02,0x00,0x18,0x18,0x50,0x00,0x5F,0x0F,0x000E,0x00,0x00},
	{0x02,0x00,0x18,0x18,0x60,0x00,0x6F,0x0F,0x000E,0x00,0x00},
	{0x02,0x00,0x18,0x18,0x70,0x00,0x7F,0x0F,0x000E,0x00,0x00},
	{0x82,0x00,0x18,0x18,0x80,0x00,0x8F,0x0F,0x000F,0x00,0x00},
	{0x02,0x00,0x18,0x18,0x90,0x00,0x9F,0x0F,0x000F,0x00,0x00},
	{0x02,0x00,0x18,0x18,0xA0,0x00,0xAF,0x0F,0x000F,0x00,0x00},
	{0x02,0x00,0x18,0x18,0xB0,0x00,0xBF,0x0F,0x000F,0x00,0x00},
	{0x81,0x00,0x20,0x20,0x30,0x10,0x3F,0x1F,0x0010,0x00,0x00},
	{0x01,0x00,0x20,0x20,0x40,0x10,0x4F,0x1F,0x0010,0x00,0x00},
	{0x01,0x00,0x20,0x20,0x50,0x10,0x5F,0x1F,0x0010,0x00,0x00},
	{0x01,0x00,0x20,0x20,0x60,0x10,0x6F,0x1F,0x0010,0x00,0x00},
	{0x01,0x00,0x20,0x20,0x70,0x10,0x7F,0x1F,0x0010,0x00,0x00},
	{0x01,0x00,0x20,0x20,0x80,0x10,0x8F,0x1F,0x0010,0x00,0x00},
	{0x81,0x00,0x20,0x20,0x90,0x10,0x9F,0x1F,0x0010,0x00,0x00},
	{0x01,0x00,0x20,0x20,0xA0,0x10,0xAF,0x1F,0x0010,0x00,0x00},
	{0x01,0x00,0x20,0x20,0xB0,0x10,0xBF,0x1F,0x0010,0x00,0x00},
	{0x01,0x00,0x20,0x20,0xA0,0x10,0xAF,0x1F,0x0010,0x00,0x00},
	{0x81,0x00,0x20,0x20,0x90,0x10,0x9F,0x1F,0x0010,0x00,0x00},
	{0x83,0x00,0x20,0x20,0x50,0x20,0x5F,0x2F,0x0010,0x00,0x00},
	{0x03,0x00,0x20,0x20,0x60,0x20,0x6F,0x2F,0x0010,0x00,0x00},
	{0x03,0x00,0x20,0x20,0x70,0x20,0x7F,0x2F,0x0010,0x00,0x00},
	{0x85,0x00,0x80,0x80,0xC0,0x40,0xE0,0x60,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0xC0,0x80,0xE0,0xA0,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0xC0,0xC0,0xE0,0xE0,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0x80,0x40,0xA0,0x60,0x0000,0x00,0x00},
	{0x85,0x00,0x80,0x80,0xE0,0x40,0xFF,0x60,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0xE0,0x80,0xFF,0xA0,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0xE0,0xC0,0xFF,0xE0,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0xA0,0x40,0xBF,0x60,0x0000,0x00,0x00},
	{0x85,0x00,0x80,0x80,0xC0,0x60,0xE0,0x7F,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0xC0,0xA0,0xE0,0xBF,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0xC0,0xE0,0xE0,0xFF,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0x80,0x60,0xA0,0x7F,0x0000,0x00,0x00},
	{0x85,0x00,0x80,0x80,0xE0,0x60,0xFF,0x7F,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0xE0,0xA0,0xFF,0xBF,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0xE0,0xE0,0xFF,0xFF,0x0000,0x00,0x00},
	{0x05,0x00,0x80,0x80,0xA0,0x60,0xBF,0x7F,0x0000,0x00,0x00},
	{0x9E,0x09,0x40,0x20,0x40,0x80,0x57,0x8F,0x0011,0x00,0x00},
	{0x9E,0x09,0x40,0x40,0x5F,0x90,0x48,0xA7,0x0011,0x00,0x00},
	{0x9E,0x09,0x20,0x40,0x3F,0x40,0x30,0x57,0x0011,0x00,0x00},
	{0x9E,0x09,0x40,0x40,0x5F,0xA7,0x48,0x90,0x0011,0x00,0x00},
	{0x9E,0x09,0x40,0x20,0x40,0x8F,0x57,0x80,0x0011,0x00,0x00},
	{0x9E,0x09,0x40,0x40,0x48,0xA7,0x5F,0x90,0x0011,0x00,0x00},
	{0x9E,0x09,0x20,0x40,0x30,0x40,0x3F,0x57,0x0011,0x00,0x00},
	{0x9E,0x09,0x40,0x40,0x48,0x90,0x5F,0xA7,0x0011,0x00,0x00},
	{0x81,0x01,0x10,0x10,0x30,0x30,0x3F,0x3F,0x0018,0x00,0x00},
	{0x81,0x01,0x10,0x10,0x40,0x30,0x4F,0x3F,0x0018,0x00,0x00},
	{0x81,0x01,0x10,0x10,0x50,0x30,0x5F,0x3F,0x0018,0x00,0x00},
	{0x81,0x01,0x10,0x10,0x3F,0x30,0x30,0x3F,0x0018,0x00,0x00},
	{0x81,0x01,0x10,0x10,0x4F,0x30,0x40,0x3F,0x0018,0x00,0x00},
	{0x81,0x01,0x10,0x10,0x5F,0x30,0x50,0x3F,0x0018,0x00,0x00},
	{0x81,0x01,0x10,0x10,0x60,0x30,0x6F,0x3F,0x0018,0x00,0x00},
	{0x81,0x01,0x10,0x10,0x70,0x30,0x7F,0x3F,0x0018,0x00,0x00},
	{0x81,0x01,0x10,0x10,0x80,0x30,0x8F,0x3F,0x0018,0x00,0x00},
	{0x82,0x00,0x18,0x18,0x80,0x20,0x8F,0x2F,0x0018,0x00,0x00},
	{0x82,0x00,0x18,0x18,0x90,0x20,0x9F,0x2F,0x0018,0x00,0x00},
	{0x82,0x00,0x18,0x18,0xA0,0x20,0xAF,0x2F,0x0018,0x00,0x00},
	{0x82,0x00,0x18,0x18,0xB0,0x20,0xBF,0x2F,0x0018,0x00,0x00},
	{0x84,0x00,0x30,0x30,0x40,0x40,0x57,0x57,0x0013,0x00,0x00},
	{0x04,0x00,0x30,0x30,0x58,0x40,0x6F,0x57,0x0013,0x00,0x00},
	{0x04,0x14,0x30,0x40,0x70,0x40,0x8F,0x5F,0x0013,0x00,0x00},
	{0x04,0x14,0x30,0x40,0x90,0x40,0xAF,0x5F,0x0013,0x00,0x00},
	{0x81,0x02,0x14,0x14,0x90,0x30,0x9F,0x3F,0x0014,0x00,0x00},
	{0x81,0x02,0x14,0x14,0xA0,0x30,0xAF,0x3F,0x0014,0x00,0x00},
	{0x81,0x02,0x14,0x14,0xB0,0x30,0xBF,0x3F,0x0014,0x00,0x00},
	{0x81,0x02,0x14,0x14,0xAF,0x30,0xA0,0x3F,0x0014,0x00,0x00},
	{0x81,0x02,0x14,0x14,0x9F,0x30,0x90,0x3F,0x0014,0x00,0x00},
	{0x81,0x02,0x14,0x14,0xB0,0x40,0xBF,0x4F,0x0014,0x00,0x00},
	{0x94,0x01,0x30,0x30,0xC0,0x40,0xDF,0x5F,0x0015,0x00,0x00},
	{0x14,0x01,0x30,0x30,0xE0,0x40,0xFF,0x5F,0x0015,0x00,0x00},
	{0x28,0x11,0x30,0x30,0xC0,0x60,0xDF,0x7F,0x0015,0x00,0x00},
	{0x81,0x19,0x10,0x10,0x70,0x60,0x8F,0x7F,0x0016,0x00,0x00},
	{0x01,0x19,0x10,0x10,0x90,0x60,0xAF,0x7F,0x0016,0x00,0x00},
	{0x01,0x19,0x10,0x10,0x70,0x80,0x8F,0x9F,0x0016,0x00,0x00},
	{0x01,0x19,0x10,0x10,0x90,0x80,0xAF,0x9F,0x0016,0x00,0x00},
	{0x82,0x19,0x20,0x20,0xE0,0xE0,0xFF,0xFF,0x0017,0x00,0x00},
	{0x02,0x19,0x20,0x20,0xC0,0xE0,0xDF,0xFF,0x0017,0x00,0x00},
	{0x02,0x19,0x20,0x20,0xE0,0xC0,0xFF,0xDF,0x0017,0x00,0x00},
	{0x02,0x19,0x20,0x20,0xC0,0xC0,0xDF,0xDF,0x0017,0x00,0x00},
	{0x02,0x19,0x20,0x20,0xE0,0xA0,0xFF,0xBF,0x0017,0x00,0x00},
	{0x02,0x19,0x20,0x20,0xC0,0xA0,0xDF,0xBF,0x0017,0x00,0x00},
	{0x02,0x19,0x20,0x20,0xE0,0x80,0xFF,0x9F,0x0017,0x00,0x00},
	{0x02,0x19,0x20,0x20,0xC0,0x80,0xDF,0x9F,0x0017,0x00,0x00},
	{0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0000,0x00,0x00}
//0096DD74 00 00 00 00
};

void C_0075B8F3(short bp08, short bp0c, short bp10, int bp14) {
	struct {//x44
		struct VECTOR local_17;
		struct MATRIX local_13;
		int local_5;
		struct SVECTOR local_4;
		int local_2;
		struct t_wm_local_54 *local_1;
	}lolo;

	lolo.local_1 = D_00E35640;
	if(lolo.local_1) {
		D_00E35640 = lolo.local_1->f_00;
		lolo.local_1->f_00 = D_00E35648;
		D_00E35648 = lolo.local_1;
		lolo.local_13.f_12[0] =
		lolo.local_13.f_12[1] =
		lolo.local_13.f_12[2] = 0;
		psx_SetTransMatrix(&lolo.local_13);
		lolo.local_4.f_00 =
		lolo.local_4.f_04 = 0;
		lolo.local_4.f_02 = bp0c;
		psx_RotMatrixXYZ(&lolo.local_4, &lolo.local_13);
		psx_SetRotMatrix(&lolo.local_13);
		psx_RotTrans(&D_00E2D1F0, &lolo.local_17, &lolo.local_5);
		lolo.local_1->f_14 = lolo.local_17.f_00;
		lolo.local_1->f_16 = lolo.local_17.f_04;
		lolo.local_1->f_18 = lolo.local_17.f_08;
		lolo.local_1->f_04 = D_00E2D1E0;
		lolo.local_4.f_02 = bp08;
		psx_RotMatrixXYZ(&lolo.local_4, &lolo.local_13);
		psx_SetRotMatrix(&lolo.local_13);
		psx_RotTrans(&D_00E2D1F8, &lolo.local_17, &lolo.local_5);
		lolo.local_1->f_04.f_00 = D_00E2D1E0.f_00 + lolo.local_17.f_00;
		lolo.local_1->f_04.f_04 = D_00E2D1E0.f_04 + lolo.local_17.f_04;
		lolo.local_1->f_04.f_08 = D_00E2D1E0.f_08 + lolo.local_17.f_08;
		lolo.local_1->f_1a = D_00E2D200 ^ 0x800;
		lolo.local_1->f_1f = bp14;
		lolo.local_1->f_1c = D_0096D5B8[bp10][0];
		lolo.local_1->f_1e = D_0096D5B8[bp10][1];
		lolo.local_1->f_1d = D_0096D6A8[lolo.local_1->f_1c].f_00 & ~0x80;
		lolo.local_1->f_04.f_0c = 0;
		for(lolo.local_2 = 0; lolo.local_2 < 2; lolo.local_2 ++) {
			lolo.local_1->f_20 = (D_0096D6A8[lolo.local_1->f_1c].f_01 & 0x1c) == 8?0:0x80;
			lolo.local_1->f_24.f_2c = (D_0096D6A8[lolo.local_1->f_1c].f_01 & 0x1c) == 8?0x80000000:0x80808080;
			lolo.local_1->f_24.f_28 = D_00E2C404;
		}
	}
}

void C_0075BB25() {
	struct t_wm_local_spr_0c *local_1;

	D_00E2D1F0.f_00 = 0;
	D_00E2D1F0.f_02 = 0x32;
	D_00E2D1F0.f_04 = 0;
	D_00E2D200 = 0;
	C_00762798(&D_00E2D1E0);
	D_00E2D1F8.f_00 = D_00E2D1F8.f_02 =  D_00E2D1F8.f_04 = 0;
	C_0075B8F3(0, 0, 7, 0);
	local_1 = &(D_0096D6A8[D_0096D5D4]);
	local_1->f_03 = 0x10;
	local_1->f_02 = 0x10;
}

void C_0075BBB3(struct t_local_unknown_c0 *bp08, int bp0c) {
	struct {
		int bp_0c;
		int bp_08;
		struct t_wm_local_spr_0c *bp_04;
	}lolo;

	lolo.bp_08 = bp08->f_3c + bp08->f_3e;
	D_00E2D200 = bp08->f_3c;
	D_00E2D1E0 = bp08->f_1c;
	D_00E2D1F0.f_00 = D_00E2D1F0.f_02 = D_00E2D1F0.f_04 = 0;
	D_00E2D1F8.f_00 = D_00E2D1F8.f_02 = D_00E2D1F8.f_04 = 0;
	switch(bp0c) {
		case 0x14: case 0x15: case 0x16:
			D_00E2D1F8.f_02 = C_0074D28E()?0x12c:0x258;
			D_00E2D1F8.f_04 = -0xc8;
			C_0075B8F3(bp08->f_3c, 0, bp0c, 0);
		break;
		case 0x17:
			D_00E2D1F8.f_02 = C_0074D28E()?0x12c:0x258;
			D_00E2D1F8.f_04 = -0xc8;
			D_00E2D1F0.f_02 = 0x32;
			C_0075B8F3(bp08->f_3c, 0, bp0c, 0);
		break;
		case 0x01:
			D_00E2D200 = 0;
			D_00E2D1F8.f_04 = 0x1F4;
			D_00E2D1F0.f_04 = 0x1E;
			C_0075B8F3(0, 0, 0x1c, 0);
			D_00E2D1F8.f_04 = -0x1f4;
			D_00E2D1F0.f_04 = -0x1e;
			C_0075B8F3(0, 0, 0x20, 0);
			D_00E2D1F8.f_04 = 0x161;
			D_00E2D1F0.f_04 = 0x15;
			D_00E2D1F8.f_00 = 0x161;
			D_00E2D1F0.f_00 = 0x15;
			C_0075B8F3(0, 0, 0x23, 0);
			D_00E2D1F8.f_00 = -0x161;
			D_00E2D1F0.f_00 = -0x15;
			C_0075B8F3(0, 0, 0x1d, 0);
			D_00E2D1F8.f_04 = -0x161;
			D_00E2D1F0.f_04 = -0x15;
			C_0075B8F3(0 ,0, 0x1f, 0);
			D_00E2D1F8.f_00 = 0x161;
			D_00E2D1F0.f_00 = 0x15;
			C_0075B8F3(0, 0, 0x21, 0);
			D_00E2D1F8.f_04 = 0;
			D_00E2D1F0.f_04 = 0;
			D_00E2D1F8.f_00 = 0x1F4;
			D_00E2D1F0.f_00 = 0x1E;
			C_0075B8F3(0, 0, 0x22, 0);
			D_00E2D1F8.f_00 = -0x1f4;
			D_00E2D1F0.f_00 = -0x1e;
			C_0075B8F3(0, 0, 0x1e, 0);
		break;
		case 0x02:
			lolo.bp_0c = C_00753BE8() << 4;
			D_00E2D1F0.f_00 = psx_rcos(lolo.bp_0c) >> 6;
			D_00E2D1F0.f_02 = 0x78;
			D_00E2D1F8.f_04 = 0x1F4;
			C_0075B8F3(lolo.bp_0c, 0, 0x31, 0x14);
		break;
		case 0x03:
			D_00E2D1F8.f_02 = 0x12C;
			D_00E2D1F8.f_04 = -0x3e8;
			D_00E2D1F0.f_02 = 0x14;
			D_00E2D1F0.f_04 = -0xa;
			C_0075B8F3(bp08->f_3c, bp08->f_3c + C_00753BE8() * 8 - 0x400, 0x38, 1);
		break;
		case 0x04:
			D_00E2D1F8.f_00 = 0x1E;
			D_00E2D1F8.f_02 = 0x190;
			D_00E2D1F8.f_04 = 0x1F4;
			C_0075B8F3(bp08->f_3c, 0, 0x39, 0);
			lolo.bp_04 = &(D_0096D6A8[D_0096D69C]);
			lolo.bp_04->f_03 = 0xb;
			lolo.bp_04->f_02 = 0xb;
		break;
		case 0x05:
			D_00E2D1F8.f_00 = 0x1E;
			D_00E2D1F8.f_02 = 0x190;
			D_00E2D1F8.f_04 = 0x1F4;
			C_0075B8F3(bp08->f_3c, 0, 0x3a, 0);
		break;
		case 0x06:
			D_00E2D1F0.f_02 = 0x32;
			D_00E2D200 = 0;
			C_0075B8F3(0, 0, 7, 0);
			lolo.bp_04 = &(D_0096D6A8[D_0096D5D4]);
			lolo.bp_04->f_03 = 0x10;
			lolo.bp_04->f_02 = 0x10;
		break;
	}
}

void C_0075BFE5(int bp08, int bp0c, int bp10, int bp14) {
	char *local_1;

	local_1 = D_00E35638[bp08];
	local_1[0] = bp0c;
	local_1[1] = bp10;
	local_1[2] = bp14;
	local_1[3] = 0;
}

void C_0075C01B(int bp08) {
	D_00E35638[bp08][2] = 0;
}

void C_0075C0FD(void);
void C_0075CEED(void);

void C_0075C02B() {
	char *local_1;

	if(D_00E35650 && D_00E2D60C) {
		D_00E2D60C->f_00 = D_00E35640;
		D_00E35640 = D_00E35650;
		D_00E35650 = 
		D_00E2D60C = 0;
	}
	C_0075C0FD();
	C_0075CEED();
	for(local_1 = D_00E35638[0]; local_1 < D_00E35638[2]/*00E35640*/; local_1 += 4) {
		if(local_1[2] > 0 && (local_1[3] --) <= 1) {//else 0075C0F7
			if(C_00762047(local_1[0])) {//else 0075C0F0
				local_1[3] = local_1[2];
				C_0075BBB3(C_0076175F(), local_1[1]);
			} else {
				local_1[2] = 0;
			}
		}
	}
}

void C_0075C283(struct t_wm_local_30 *, struct t_wm_local_spr_0c *, struct SVECTOR *, short);

void C_0075C0FD() {
	struct {
		struct MATRIX local_36; char _ocal_36[2];
		struct MATRIX local_28; char _ocal_28[2];
		int local_20;
		struct MATRIX local_19; char _ocal_19[2];
		int local_11;
		int local_10;
		struct SVECTOR local_9;
		struct SVECTOR local_7;
		struct VECTOR local_5;
		struct t_wm_local_54 *local_1;
	}lolo;

	lolo.local_7.f_00 = 0;
	lolo.local_7.f_02 = -C_0074D298();
	lolo.local_7.f_04 = 0;
	psx_RotMatrixYXZ(&lolo.local_7, &lolo.local_28);
	lolo.local_7.f_00 = -C_0074D3C6();
	psx_RotMatrixYXZ(&lolo.local_7, &lolo.local_19);
	C_0075042B(&lolo.local_5);
	for(lolo.local_1 = D_00E35648; lolo.local_1; lolo.local_1 = lolo.local_1->f_00) {
		lolo.local_10 = lolo.local_1->f_04.f_00 - lolo.local_5.f_00;
		lolo.local_11 = lolo.local_1->f_04.f_04 - D_00DE6A04;
		lolo.local_20 = lolo.local_1->f_04.f_08 - lolo.local_5.f_08;
		if(lolo.local_10 > -0x7530 && lolo.local_10 < 0x7530 && lolo.local_20 > -0x7530 && lolo.local_20 < 0x7530) {
			lolo.local_9.f_00 = lolo.local_10;
			lolo.local_9.f_02 = lolo.local_11 - C_00762F9A(lolo.local_10, lolo.local_20);
			lolo.local_9.f_04 = lolo.local_20;
			if(lolo.local_1->f_1e) {
				lolo.local_7.f_00 =
				lolo.local_7.f_04 = 0;
				lolo.local_7.f_02 = lolo.local_1->f_1a;
				psx_RotMatrixXYZ(&lolo.local_7, &lolo.local_36);
				psx_SetRotMatrix(&lolo.local_36);
			} else {
				psx_SetRotMatrix(&lolo.local_19);
			}
			C_0075C283(&(lolo.local_1->f_24), &(D_0096D6A8[lolo.local_1->f_1c]), &lolo.local_9, lolo.local_1->f_1e);
		}
	}
}

void C_0075C283(struct t_wm_local_30 *bp08, struct t_wm_local_spr_0c *bp0c, struct SVECTOR *bp10, short bp14) {
	struct {//x25c
		//bp_1d8 and above for compiler
		struct t_dx_rend_vertex_20 *bp_1d4;
		struct t_dx_rend_vertex_20 *bp_1d0;
		struct t_dx_rend_vertex_20 *bp_1cc;
		struct t_dx_rend_vertex_20 *bp_1c8;
		float bp_1c4;
		float bp_1c0;
		float bp_1bc;
		float bp_1b8;
		float bp_1b4;
		float bp_1b0;
		float bp_1ac;
		float bp_1a8;
		struct SVECTOR bp_1a4;
		int bp_19c;
		float bp_198;
		float bp_194;
		struct MATRIX bp_190;
		struct t_g_drv_0c bp_170;
		float bp_164;
		struct t_g_drv_0c bp_160;
		float bp_154;
		struct t_g_drv_0c bp_150;
		struct SVECTOR bp_144;
		struct t_g_drv_0c bp_13c;
		struct SVECTOR bp_130;
		struct VECTOR bp_128;
		struct SVECTOR bp_118;
		struct SVECTOR bp_110;
		int bp_108;
		D3DMATRIX bp_104;
		struct t_g_drv_0c bp_c4;
		float bp_b8[4];
		float bp_a8;
		struct t_g_drv_0c bp_a4;
		float bp_98[4];
		D3DMATRIX bp_88;
		struct t_g_drv_0c bp_48;
		float bp_3c[4];
		struct t_g_drv_0c bp_2c;
		float bp_20[4];
		struct VECTOR bp_10;
	}lolo;

	lolo.bp_128.f_00 =
	lolo.bp_128.f_04 =
	lolo.bp_128.f_08 = 0;
	psx_TransMatrix(&lolo.bp_190, &lolo.bp_128);
	psx_SetTransMatrix(&lolo.bp_190);
	lolo.bp_1a4.f_00 = (-bp0c->f_02) * 8;
	if(bp14) {
		lolo.bp_1a4.f_02 = 0;
		lolo.bp_1a4.f_04 = (-bp0c->f_03) * 8;
	} else {
		lolo.bp_1a4.f_02 = (-bp0c->f_03) * 8;
		lolo.bp_1a4.f_04 = 0;
	}
	psx_RotTrans(&lolo.bp_1a4, &lolo.bp_10, &lolo.bp_108);
	lolo.bp_110.f_00 = lolo.bp_10.f_00;
	lolo.bp_110.f_02 = lolo.bp_10.f_04;
	lolo.bp_110.f_04 = lolo.bp_10.f_08;
	lolo.bp_1a4.f_00 += bp0c->f_02 * 16;
	psx_RotTrans(&lolo.bp_1a4, &lolo.bp_10, &lolo.bp_108);
	lolo.bp_118.f_00 = lolo.bp_10.f_00;
	lolo.bp_118.f_02 = lolo.bp_10.f_04;
	lolo.bp_118.f_04 = lolo.bp_10.f_08;
	if(bp14)
		lolo.bp_1a4.f_04 += bp0c->f_03 * 16;
	else
		lolo.bp_1a4.f_02 += bp0c->f_03 * 16;
	psx_RotTrans(&lolo.bp_1a4, &lolo.bp_10, &lolo.bp_108);
	lolo.bp_144.f_00 = lolo.bp_10.f_00;
	lolo.bp_144.f_02 = lolo.bp_10.f_04;
	lolo.bp_144.f_04 = lolo.bp_10.f_08;
	lolo.bp_1a4.f_00 -= bp0c->f_02 * 16;
	psx_RotTrans(&lolo.bp_1a4, &lolo.bp_10, &lolo.bp_108);
	lolo.bp_130.f_00 = lolo.bp_10.f_00;
	lolo.bp_130.f_02 = lolo.bp_10.f_04;
	lolo.bp_130.f_04 = lolo.bp_10.f_08;
	bp08->f_00.u0 = bp08->f_00.u2 = bp0c->f_04;
	bp08->f_00.u1 = bp08->f_00.u3 = bp0c->f_06;
	bp08->f_00.v0 = bp08->f_00.v1 = bp0c->f_05;
	bp08->f_00.v2 = bp08->f_00.v3 = bp0c->f_07;
	bp08->f_00.clut = bp0c->f_08;
	switch(bp0c->f_01 & 3) {
		case 0: bp08->f_28 = D_00E2C404; break;
		case 1: bp08->f_28 = D_00E2C408; break;
		case 2: bp08->f_28 = /*lolo.bp_1dc*/(bp0c->f_08 == 0x14)?D_00E2C408:D_00E2C404; break;
		case 3: bp08->f_28 = D_00E2C410; break;
		default: bp08->f_28 = D_00E2C404;
	}//end for
	C_0074D3A7();
	psx_RotTrans(bp10, &lolo.bp_10, &lolo.bp_108);
	psx_TransMatrix(&lolo.bp_190, &lolo.bp_10);
	psx_SetTransMatrix(&lolo.bp_190);
	C_006617E9(C_0066100D(), &lolo.bp_88);//psx:transformation to D3DMATRIX(3)
	C_0067D2BF(&lolo.bp_88, &lolo.bp_104);//dx_mat:matrix multiplication by "struct t_aa0::f_8d0" 4x4[transpose]
	lolo.bp_2c.f_00 = /*lolo.bp_1e0*/(float)lolo.bp_110.f_00;
	lolo.bp_2c.f_04 = /*lolo.bp_1e4*/(float)lolo.bp_110.f_02;
	lolo.bp_2c.f_08 = /*lolo.bp_1e8*/(float)lolo.bp_110.f_04;
	lolo.bp_48.f_00 = /*lolo.bp_1ec*/(float)lolo.bp_118.f_00;
	lolo.bp_48.f_04 = /*lolo.bp_1f0*/(float)lolo.bp_118.f_02;
	lolo.bp_48.f_08 = /*lolo.bp_1f4*/(float)lolo.bp_118.f_04;
	lolo.bp_a4.f_00 = /*lolo.bp_1f8*/(float)lolo.bp_130.f_00;
	lolo.bp_a4.f_04 = /*lolo.bp_1fc*/(float)lolo.bp_130.f_02;
	lolo.bp_a4.f_08 = /*lolo.bp_200*/(float)lolo.bp_130.f_04;
	lolo.bp_c4.f_00 = /*lolo.bp_204*/(float)lolo.bp_144.f_00;
	lolo.bp_c4.f_04 = /*lolo.bp_208*/(float)lolo.bp_144.f_02;
	lolo.bp_c4.f_08 = /*lolo.bp_20c*/(float)lolo.bp_144.f_04;
	C_0066CE40(&lolo.bp_104, &lolo.bp_2c, lolo.bp_20);
	if(lolo.bp_20[3] > 0.0f) {//else 0075CED9
		C_0066CF4D(&lolo.bp_88, &lolo.bp_2c, &lolo.bp_13c);
		C_0066CE40(&lolo.bp_104, &lolo.bp_48, lolo.bp_3c);
		if(lolo.bp_3c[3] > 0.0f) {//else 0075CED9
			C_0066CF4D(&lolo.bp_88, &lolo.bp_48, &lolo.bp_150);
			C_0066CE40(&lolo.bp_104, &lolo.bp_a4, lolo.bp_98);
			if(lolo.bp_98[3] > 0.0f) {//else 0075CED9
				C_0066CF4D(&lolo.bp_88, &lolo.bp_a4, &lolo.bp_160);
				C_0066CE40(&lolo.bp_104, &lolo.bp_c4, lolo.bp_b8);
				if(lolo.bp_b8[3] > 0.0f) {//else 0075CED9
					C_0066CF4D(&lolo.bp_88, &lolo.bp_c4, &lolo.bp_170);
					lolo.bp_19c = (int)min(min(lolo.bp_13c.f_08, lolo.bp_150.f_08), lolo.bp_160.f_08);
					lolo.bp_19c = min(lolo.bp_19c, C_0075F090(lolo.bp_170.f_08)) >> 4;
					if(lolo.bp_19c >= 0 && lolo.bp_19c < 0x1000) {//else 0075CED9
						if(C_0066E272(1, bp08->f_28)) {//else 0075CED9
							if(C_0074C969()) {//get "isRendering"?//else 0075CED9
								lolo.bp_1a8 = /*lolo.bp_220*/(float)bp08->f_00.u0 * bp08->f_28->f_24;
								lolo.bp_1b8 = /*lolo.bp_224*/(float)bp08->f_00.v0 * bp08->f_28->f_28;
								lolo.bp_1ac = /*lolo.bp_228*/(float)bp08->f_00.u1 * bp08->f_28->f_24;
								lolo.bp_1bc = /*lolo.bp_22c*/(float)bp08->f_00.v1 * bp08->f_28->f_28;
								lolo.bp_1b0 = /*lolo.bp_230*/(float)bp08->f_00.u2 * bp08->f_28->f_24;
								lolo.bp_1c0 = /*lolo.bp_234*/(float)bp08->f_00.v2 * bp08->f_28->f_28;
								lolo.bp_1b4 = /*lolo.bp_238*/(float)bp08->f_00.u3 * bp08->f_28->f_24;
								lolo.bp_1c4 = /*lolo.bp_23c*/(float)bp08->f_00.v3 * bp08->f_28->f_28;
								lolo.bp_154 = 1.0f / lolo.bp_20[3];
								lolo.bp_164 = 1.0f / lolo.bp_3c[3];
								lolo.bp_194 = 1.0f / lolo.bp_98[3];
								lolo.bp_198 = 1.0f / lolo.bp_b8[3];
								bp08->f_00.x0 = C_0075F090(lolo.bp_20[0] * lolo.bp_154);
								bp08->f_00.y0 = C_0075F090(lolo.bp_20[1] * lolo.bp_154);
								bp08->f_00.x1 = C_0075F090(lolo.bp_3c[0] * lolo.bp_164);
								bp08->f_00.y1 = C_0075F090(lolo.bp_3c[1] * lolo.bp_164);
								bp08->f_00.x2 = C_0075F090(lolo.bp_98[0] * lolo.bp_194);
								bp08->f_00.y2 = C_0075F090(lolo.bp_98[1] * lolo.bp_194);
								bp08->f_00.x3 = C_0075F090(lolo.bp_b8[0] * lolo.bp_198);
								bp08->f_00.y3 = C_0075F090(lolo.bp_b8[1] * lolo.bp_198);
								if(lolo.bp_20[2] < lolo.bp_3c[2])
									lolo.bp_a8 = lolo.bp_20[2];
								else {
									lolo.bp_a8 = lolo.bp_3c[2];
									lolo.bp_154 = lolo.bp_164;
								}
								if(lolo.bp_a8 > lolo.bp_98[2]) {
									lolo.bp_a8 = lolo.bp_98[2];
									lolo.bp_154 = lolo.bp_194;
								}
								if(lolo.bp_a8 > lolo.bp_b8[2]) {
									lolo.bp_a8 = lolo.bp_b8[2];
									lolo.bp_154 = lolo.bp_198;
								}
								lolo.bp_a8 *= lolo.bp_154;
								MK_VERTEX(&(bp08->f_28->f_70.asVertex[0]), lolo.bp_1c8, (float)bp08->f_00.x0, (float)bp08->f_00.y0, lolo.bp_a8, 1.0f, bp08->f_2c, 0xff000000, lolo.bp_1a8, lolo.bp_1b8);
								MK_VERTEX(&(bp08->f_28->f_70.asVertex[1]), lolo.bp_1cc, (float)bp08->f_00.x1, (float)bp08->f_00.y1, lolo.bp_a8, 1.0f, bp08->f_2c, 0xff000000, lolo.bp_1ac, lolo.bp_1bc);
								MK_VERTEX(&(bp08->f_28->f_70.asVertex[2]), lolo.bp_1d0, (float)bp08->f_00.x2, (float)bp08->f_00.y2, lolo.bp_a8, 1.0f, bp08->f_2c, 0xff000000, lolo.bp_1b0, lolo.bp_1c0);
								MK_VERTEX(&(bp08->f_28->f_70.asVertex[3]), lolo.bp_1d4, (float)bp08->f_00.x3, (float)bp08->f_00.y3, lolo.bp_a8, 1.0f, bp08->f_2c, 0xff000000, lolo.bp_1b4, lolo.bp_1c4);
								*(bp08->f_28->lpbCurPalette) = bp08->f_00.clut;
								bp08->f_28->dwLastPalette = bp08->f_00.clut;
							}
						}
					}
				}
			}
		}
	}
}

void C_0075CEED() {
	struct {//x20
		//bp_1c and above for compiler
		struct t_wm_local_30 *bp_14;
		unsigned char bp_10[4];//maybe tRGBA or tBGRA?
		struct t_wm_local_54 *bp_0c;
		struct t_wm_local_spr_0c *bp_08;
		struct t_wm_local_54 *bp_04;
	}lolo;

	lolo.bp_0c = 0;
	lolo.bp_04 = D_00E35648;
//0075CF02
	while(lolo.bp_04) {//else 0075D43E
		lolo.bp_14 = &(lolo.bp_04->f_24);
		lolo.bp_04->f_04.f_00 += lolo.bp_04->f_14;
		lolo.bp_04->f_04.f_04 += lolo.bp_04->f_16;
		lolo.bp_04->f_04.f_08 += lolo.bp_04->f_18;
		lolo.bp_04->f_16 -= lolo.bp_04->f_1f;
		lolo.bp_08 = &(D_0096D6A8[lolo.bp_04->f_1c]);
		if(lolo.bp_08->f_01 == 2) {//else 0075D024
			lolo.bp_04->f_20 --;
			lolo.bp_14->f_00.r0 =
			lolo.bp_14->f_00.g0 =
			lolo.bp_14->f_00.b0 = lolo.bp_04->f_20;
			*(int *)lolo.bp_10 = lolo.bp_14->f_2c;
			if(lolo.bp_04->f_1c == 0x7c) {//else 0075CFFD
				lolo.bp_10[0] --;
				lolo.bp_10[2] =
				lolo.bp_10[1] = lolo.bp_10[0];
				lolo.bp_14->f_2c = *(int *)lolo.bp_10;
			} else {
				lolo.bp_10[2] =
				lolo.bp_10[1] =
				lolo.bp_10[0] = 0;
				lolo.bp_10[3] --;
				lolo.bp_14->f_2c = *(int *)lolo.bp_10;
			}
			//goto 0075D311
		} else {
			switch(lolo.bp_08->f_01 & 0x1c) {
				case 0x04:
					lolo.bp_04->f_20 -= 0xc;
					if(lolo.bp_04->f_20 < 0)
						lolo.bp_04->f_20 = 0;
					lolo.bp_14->f_00.r0 =
					lolo.bp_14->f_00.g0 =
					lolo.bp_14->f_00.b0 = lolo.bp_04->f_20;
					*(int *)lolo.bp_10 = lolo.bp_14->f_2c;
					lolo.bp_10[2] =
					lolo.bp_10[1] =
					lolo.bp_10[0] = lolo.bp_04->f_20;
					lolo.bp_14->f_2c = *(int *)lolo.bp_10;
					lolo.bp_08->f_02 =
					lolo.bp_08->f_03 += 0x10;
				break;
				case 0x08:
					if(lolo.bp_04->f_04.f_0c) {//else 0075D163
						lolo.bp_04->f_20 -= 8;
						if(lolo.bp_04->f_20 < 0)
							lolo.bp_04->f_20 = 0;
						lolo.bp_14->f_00.r0 =
						lolo.bp_14->f_00.g0 =
						lolo.bp_14->f_00.b0 = lolo.bp_04->f_20;
						*(int *)lolo.bp_10 = lolo.bp_14->f_2c;
						lolo.bp_10[2] =
						lolo.bp_10[1] =
						lolo.bp_10[0] = lolo.bp_04->f_20;
						lolo.bp_14->f_2c = *(int *)lolo.bp_10;
					} else {
						lolo.bp_04->f_20 += 8;
						lolo.bp_14->f_00.r0 =
						lolo.bp_14->f_00.g0 =
						lolo.bp_14->f_00.b0 = lolo.bp_04->f_20;
						if(lolo.bp_14->f_00.r0 >= 0x80)
							lolo.bp_04->f_04.f_0c = 1;
					}
				break;
				case 0x0c:
					if(lolo.bp_04->f_04.f_0c == 0) {
						lolo.bp_04->f_04.f_0c = 1;
						lolo.bp_04->f_16 = 0xc8;
						lolo.bp_04->f_1f = 0x1e;
					}
				break;
				case 0x10:
					lolo.bp_04->f_20 -= 0x10;
					if(lolo.bp_04->f_20 < 0)
						lolo.bp_04->f_20 = 0;
					lolo.bp_14->f_00.r0 =
					lolo.bp_14->f_00.g0 =
					lolo.bp_14->f_00.b0 = lolo.bp_04->f_20;
					*(int *)lolo.bp_10 = lolo.bp_14->f_2c;
					lolo.bp_10[2] =
					lolo.bp_10[1] =
					lolo.bp_10[0] = lolo.bp_04->f_20;
					lolo.bp_14->f_2c = *(int *)lolo.bp_10;
				break;
				case 0x14:
					lolo.bp_04->f_20 -= 8;
					if(lolo.bp_04->f_20 < 0)
						lolo.bp_04->f_20 = 0;
					lolo.bp_14->f_00.r0 =
					lolo.bp_14->f_00.g0 =
					lolo.bp_14->f_00.b0 = lolo.bp_04->f_20;
					*(int *)lolo.bp_10 = lolo.bp_14->f_2c;
					lolo.bp_10[2] =
					lolo.bp_10[1] =
					lolo.bp_10[0] = lolo.bp_04->f_20;
					lolo.bp_14->f_2c = *(int *)lolo.bp_10;
				break;
				case 0x18:
					lolo.bp_08->f_03 += /*lolo.bp_1c*/(lolo.bp_08->f_02 < 0x20)?(lolo.bp_08->f_02 & 0xf)?3:-5:0;
					lolo.bp_08->f_02 = lolo.bp_08->f_03;
				break;
			}//end switch
		}
		lolo.bp_04->f_1d --;
		if(lolo.bp_04->f_1d == 0) {//else 0075D42B
			lolo.bp_04->f_1d = D_0096D6A8[++ lolo.bp_04->f_1c].f_00;
			if(lolo.bp_04->f_1d & 0x80) {//else 0075D42B
				if((lolo.bp_08->f_01 & 0x1c) == 0x18) {//else 0075D3C5
					while(((lolo.bp_04->f_1d = D_0096D6A8[-- lolo.bp_04->f_1c].f_00) & 0x80) == 0);
					lolo.bp_04->f_1d &= ~0x80;
				} else {
					if(lolo.bp_0c)
						lolo.bp_0c->f_00 = lolo.bp_04->f_00;
					else
						D_00E35648 = lolo.bp_04->f_00;
					lolo.bp_04->f_00 = D_00E35650;
					D_00E35650 = lolo.bp_04;
					if(D_00E2D60C == 0)
						D_00E2D60C = lolo.bp_04;
					lolo.bp_04 = /*lolo.bp_20*/lolo.bp_0c?lolo.bp_0c->f_00:D_00E35648;
					continue;
				}
			}
		}
		lolo.bp_0c = lolo.bp_04;
		lolo.bp_04 = lolo.bp_04->f_00;
	}//end while
	D_00E35610 ++;
}

void C_0075D482(struct t_wm_local_30 *bp08, short *bp0c) {
	int i;

	if(bp08 && bp0c) {
		for(i = 0; i < 1; i ++) {
			bp08->f_2c = 0x80404040;
			bp08->f_00.clut = 0;
			bp08->f_00.u0 = bp08->f_00.u2 = bp0c[0];
			bp08->f_00.v0 = bp08->f_00.v1 = bp0c[1];
			bp08->f_00.u1 = bp08->f_00.u3 = bp0c[0] + bp0c[2];
			bp08->f_00.v2 = bp08->f_00.v3 = bp0c[1] + bp0c[3];
		}//end for
	}
}

void C_0075D544(short bp08, short bp0c, short bp10, short bp14, struct t_wm_local_30 *bp18, short bp1c) {
	struct {//x23c
		//local_121 and above for compiler
		struct t_dx_rend_vertex_20 *local_120;
		struct t_dx_rend_vertex_20 *local_119;
		struct t_dx_rend_vertex_20 *local_118;
		struct t_dx_rend_vertex_20 *local_117;
		float local_116;
		float local_115;
		float local_114;
		float local_113;
		float local_112;
		float local_111;
		float local_110;
		float local_109;
		int local_108;
int _ocal_107[2];
		float local_105;
		float local_104;
		struct MATRIX local_103; char _ocal_103[2];
		struct t_g_drv_0c local_95;
		float local_92;
		struct t_g_drv_0c local_91;
		float local_88;
		struct MATRIX local_87; char _ocal_87[2];
		struct t_g_drv_0c local_79;
		struct t_g_drv_0c local_76;
		struct SVECTOR local_73;
		D3DMATRIX local_71;
		struct t_g_drv_0c local_55;
		float local_52[4];
		float local_48;
		struct t_g_drv_0c local_47;
		float local_44[4];
		D3DMATRIX local_40;
int _ocal_24[2];
		struct SVECTOR local_22;
		struct t_g_drv_0c local_20;
		float local_17[4];
int _ocal_13[3];
		struct t_g_drv_0c local_10;
		float local_7[4];
int _ocal_3[3];
	}lolo;

	lolo.local_73.f_00 = bp18->f_00.pad1;
	lolo.local_73.f_02 = -D_00DE6A04;
	lolo.local_73.f_04 = bp18->f_00.pad2;
	C_0074D33A(&lolo.local_73);
	lolo.local_20.f_00 = lolo.local_55.f_00 = /*lolo.local_121*/(float)bp08;
	lolo.local_47.f_08 = lolo.local_55.f_08 = /*lolo.local_122*/(float)bp0c;
	lolo.local_10.f_00 = lolo.local_47.f_00 = -lolo.local_20.f_00;
	lolo.local_10.f_08 = lolo.local_20.f_08 = -lolo.local_47.f_08;
	lolo.local_10.f_04 = lolo.local_20.f_04 = lolo.local_47.f_04 = lolo.local_55.f_04 = /*lolo.local_123*/(float)bp10;
	lolo.local_22.f_00 = lolo.local_22.f_04 = 0;
	lolo.local_22.f_02 = bp14;
	psx_RotMatrixXYZ(&lolo.local_22, &lolo.local_103);
	psx_MulRotMatrix0(&lolo.local_103, &lolo.local_87);
	psx_SetRotMatrix(&lolo.local_87);
	C_006617E9(C_0066100D(), &lolo.local_40);//psx:transformation to D3DMATRIX(3)
	C_0067D2BF(&lolo.local_40, &lolo.local_71);//dx_mat:matrix multiplication by "struct t_aa0::f_8d0" 4x4[transpose]
	C_0066CE40(&lolo.local_71, &lolo.local_10, lolo.local_7);
	C_0066CE40(&lolo.local_71, &lolo.local_20, lolo.local_17);
	C_0066CE40(&lolo.local_71, &lolo.local_47, lolo.local_44);
	C_0066CE40(&lolo.local_71, &lolo.local_55, lolo.local_52);
	lolo.local_88 = 1.0f / lolo.local_7[3];
	lolo.local_92 = 1.0f / lolo.local_17[3];
	lolo.local_104 = 1.0f / lolo.local_44[3];
	lolo.local_105 = 1.0f / lolo.local_52[3];
	bp18->f_00.x0 = C_0075F090(lolo.local_7[0] * lolo.local_88);
	bp18->f_00.y0 = C_0075F090(lolo.local_7[1] * lolo.local_88);
	bp18->f_00.x1 = C_0075F090(lolo.local_17[0] * lolo.local_92);
	bp18->f_00.y1 = C_0075F090(lolo.local_17[1] * lolo.local_92);
	bp18->f_00.x2 = C_0075F090(lolo.local_44[0] * lolo.local_104);
	bp18->f_00.y2 = C_0075F090(lolo.local_44[1] * lolo.local_104);
	bp18->f_00.x3 = C_0075F090(lolo.local_52[0] * lolo.local_105);
	bp18->f_00.y3 = C_0075F090(lolo.local_52[1] * lolo.local_105);
	C_0066CF4D(&lolo.local_40, &lolo.local_10, &lolo.local_76);
	C_0066CF4D(&lolo.local_40, &lolo.local_20, &lolo.local_79);
	C_0066CF4D(&lolo.local_40, &lolo.local_47, &lolo.local_91);
	C_0066CF4D(&lolo.local_40, &lolo.local_55, &lolo.local_95);
	lolo.local_108 = (int)min(min(lolo.local_76.f_08, lolo.local_79.f_08), lolo.local_91.f_08);
	bp18->f_00.y0 += bp1c;
	bp18->f_00.y1 += bp1c;
	bp18->f_00.y2 += bp1c;
	bp18->f_00.y3 += bp1c;
	lolo.local_108 = min(lolo.local_108, C_0075F090(lolo.local_95.f_08)) >> 4;
	if(lolo.local_108 >= 0 && lolo.local_108 < 0x1000 && C_0075F090(lolo.local_7[3]) > 0 && C_0075F090(lolo.local_17[3]) > 0 && C_0075F090(lolo.local_44[3]) > 0 && C_0075F090(lolo.local_52[3]) > 0) {//else 0075DEA6
		if(C_0066E272(1, bp18->f_28)) {//else 0075DEA6
			if(C_0074C969()) {//get "isRendering"?//else 0075DEA6
				lolo.local_109 = /*lolo.local_128*/(float)bp18->f_00.u0 * bp18->f_28->f_24;
				lolo.local_113 = /*lolo.local_129*/(float)bp18->f_00.v0 * bp18->f_28->f_28;
				lolo.local_110 = /*lolo.local_130*/(float)bp18->f_00.u1 * bp18->f_28->f_24;
				lolo.local_114 = /*lolo.local_131*/(float)bp18->f_00.v1 * bp18->f_28->f_28;
				lolo.local_111 = /*lolo.local_132*/(float)bp18->f_00.u2 * bp18->f_28->f_24;
				lolo.local_115 = /*lolo.local_133*/(float)bp18->f_00.v2 * bp18->f_28->f_28;
				lolo.local_112 = /*lolo.local_134*/(float)bp18->f_00.u3 * bp18->f_28->f_24;
				lolo.local_116 = /*lolo.local_135*/(float)bp18->f_00.v3 * bp18->f_28->f_28;
				if(lolo.local_7[2] < lolo.local_17[2]) {
					lolo.local_48 = lolo.local_7[2];
				} else {
					lolo.local_48 = lolo.local_17[2];
					lolo.local_88 = lolo.local_92;
				}
				if(lolo.local_48 > lolo.local_44[2]) {
					lolo.local_48 = lolo.local_44[2];
					lolo.local_88 = lolo.local_104;
				}
				if(lolo.local_48 > lolo.local_52[2]) {
					lolo.local_48 = lolo.local_52[2];
					lolo.local_88 = lolo.local_105;
				}
				lolo.local_48 *= lolo.local_88;
				MK_VERTEX(&(bp18->f_28->f_70.asVertex[0]), lolo.local_117, (float)bp18->f_00.x0, (float)bp18->f_00.y0, lolo.local_48, 1.0f, bp18->f_2c, 0xff000000, lolo.local_109, lolo.local_113);
				MK_VERTEX(&(bp18->f_28->f_70.asVertex[1]), lolo.local_118, (float)bp18->f_00.x1, (float)bp18->f_00.y1, lolo.local_48, 1.0f, bp18->f_2c, 0xff000000, lolo.local_110, lolo.local_114);
				MK_VERTEX(&(bp18->f_28->f_70.asVertex[2]), lolo.local_119, (float)bp18->f_00.x2, (float)bp18->f_00.y2, lolo.local_48, 1.0f, bp18->f_2c, 0xff000000, lolo.local_111, lolo.local_115);
				MK_VERTEX(&(bp18->f_28->f_70.asVertex[3]), lolo.local_120, (float)bp18->f_00.x3, (float)bp18->f_00.y3, lolo.local_48, 1.0f, bp18->f_2c, 0xff000000, lolo.local_112, lolo.local_116);
				*(bp18->f_28->lpbCurPalette) = bp18->f_00.clut;
				bp18->f_28->dwLastPalette = bp18->f_00.clut;
			}
		}
	}
//0075DEA6
}

//shadow related?
void C_0075DEAA(struct t_local_unknown_c0 *bp08) {
	struct {
		struct t_wm_local_30 *bp_10;
		short bp_0c; char _p_0c[2];
		short bp_08; char _p_08[2];
		int bp_04;
	}lolo;

	lolo.bp_04 = 0x20 - ((bp08->f_0c.f_04 - bp08->f_48) >> 8);
	if(lolo.bp_04 < 0)
		lolo.bp_04 = 0;
	lolo.bp_10 = &(bp08->f_90);
	lolo.bp_10->f_00.r0 =
	lolo.bp_10->f_00.g0 =
	lolo.bp_10->f_00.b0 = lolo.bp_04;
	lolo.bp_04 = 0x64 - ((bp08->f_0c.f_04 - bp08->f_48) >> 6);
	switch(bp08->f_50) {
		case 0x04: case 0x13: case 0x29: case 0x2a:
			lolo.bp_0c =
			lolo.bp_08 = (lolo.bp_04 * 3) >> 1;
		break;
		case 0x03:
			lolo.bp_0c = lolo.bp_04 * 2;
			lolo.bp_08 = (lolo.bp_04 * 3) * 2;
		break;
		case 0x0b:
			lolo.bp_0c = (lolo.bp_04 * 3) * 2;
			lolo.bp_08 = (lolo.bp_04 * 3) * 4;
		break;
		default:
			lolo.bp_0c = lolo.bp_04;
			lolo.bp_08 = lolo.bp_04;
	}//end switch
	C_0075D544(lolo.bp_0c, lolo.bp_08, bp08->f_48, 0x800 + bp08->f_3c + bp08->f_3e + C_0074D319() * 4, lolo.bp_10, 0);
}

//<empty>
void C_0075E024(void *_p08) {
}

void C_0075E029(LPD3DMATRIX bp08) {
	C_0066C4F0(bp08);//set matrix to identity?
	bp08->_22 = 0;
	bp08->_23 = 1.0f;
	bp08->_32 = -1.0f;
	bp08->_33 = 0;
}

void C_0075E062(LPD3DMATRIX bp08, struct t_g_drv_0c *bp0c, float *bp10) {
	struct t_g_drv_0c local_3;

	local_3.f_00 = bp0c->f_00;
	local_3.f_04 = bp0c->f_04;
	local_3.f_08 = bp0c->f_08;
	C_0067B706(bp08, &local_3, bp10);//dx_mat:matrix x vector(w==1)
}

int C_0075E09A(int bp08) {
	if(bp08 == 0x12 || bp08 == 0x11 || bp08 == 0x1b)
		return 1;
	else
		return 0;
}

//3d models related(character, plane, ...)?
void C_0075E0BA(struct t_wm_b8 *bp08, struct t_local_unknown_c0 *bp0c, short bp10, short bp14, struct SVECTOR *bp18) {
	struct {//x298
		//local_165 and above for compiler
		struct t_ComplexBlendInfo local_163;
		int local_146;
		int local_145;
		short local_144; char _ocal_144[2];
		D3DMATRIX local_143;
		D3DMATRIX local_127;
		D3DMATRIX local_111;
		D3DMATRIX local_95;
		unsigned char local_79; char _ocal_79[3];
		D3DMATRIX local_78;
		D3DMATRIX local_62;
		struct MATRIX local_46; char _ocal_46[2];
			//bp_9e;local_46.f_1a
		float local_38[3+1];
		D3DMATRIX local_34;
		D3DMATRIX local_18;
		struct t_aa0 *local_2;
		struct VECTOR *local_1;
	}lolo;

	lolo.local_1 = &D_00E2D1E0;
	lolo.local_79 = bp0c?bp0c->f_50:-1;
	C_0074D50E(bp08, bp18, &lolo.local_46, lolo.local_79 == C_00761735());
	lolo.local_144 = bp0c?bp0c->f_4a & 0x1f:0;
	lolo.local_2 = C_00676578();//get some game object?
	C_0066C4F0(&lolo.local_95);//set matrix to identity?
	C_0067CBF1(&lolo.local_95, lolo.local_2);//dx_mat:set "struct t_aa0::f_2fc"
	C_00661465(&lolo.local_46, &lolo.local_62);//psx:transformation to D3DMATRIX(2)
	bp08->f_44.sRot.f_00 *= 360.0f/256.0f;//1.40625f
	bp08->f_44.sRot.f_04 *= 360.0f/256.0f;//1.40625f
	bp08->f_44.sRot.f_08 *= 360.0f/256.0f;//1.40625f
	C_0075E029(&lolo.local_34);
	C_0075E062(&lolo.local_62, &(bp08->f_44.sPos), lolo.local_38);
	bp08->f_44.sPos.f_00 = lolo.local_38[0];
	bp08->f_44.sPos.f_04 = lolo.local_38[1];
	bp08->f_44.sPos.f_08 = lolo.local_38[2];
	C_0067BF2B(bp08->f_44.sRot.f_00, &lolo.local_18);//dx_mat:x_rotate(2)
	C_0067BFE6(bp08->f_44.sRot.f_04, &lolo.local_78);//dx_mat:z_rotate(2)
	C_0066C56E(&lolo.local_18, &lolo.local_78, &lolo.local_127);//[optimized]matrix multiplication 3x3
	C_0066C56E(&lolo.local_62, &lolo.local_127, &lolo.local_143);//[optimized]matrix multiplication 3x3
	C_0066C56E(&lolo.local_143, &lolo.local_34, &lolo.local_111);//[optimized]matrix multiplication 3x3
	C_0066C53C(&(bp08->f_44.f_2c));//set matrix to "something"?
	C_0067C251(&lolo.local_111, &(bp08->f_44.f_2c));//dx_mat:transpose matrix 3x3
	bp08->f_44.sRot.f_00 = 0;
	bp08->f_44.sRot.f_04 = 0;
	bp08->f_44.sRot.f_08 = 0;
	bp08->f_20 = bp10;
	bp08->f_30 = bp14;
	bp08->f_24 = 1;
	bp08->f_01 = 0;
	if((((0x60400FA >> lolo.local_144) & 1) && C_0074D330() != 2 && lolo.local_79 != 3 && lolo.local_79 != 0x19) || lolo.local_79 == 0x1d)
		bp08->f_01 = 0xe;
	if(bp0c && bp0c->f_5e == 0xe && bp08->f_01 <= 0)
		C_0075E024(bp08);
	if(bp0c)
		bp0c->f_5e = bp08->f_01;
	if(0);
	if(
		lolo.local_79 == 0x12 ||
		lolo.local_79 == 0x11 ||
		lolo.local_79 == 0x1a ||
		lolo.local_79 == 0x1b ||
		lolo.local_79 == 0x1c ||
		lolo.local_79 == 0x1e
	) {//else 0075E4D1
		lolo.local_146 = 0xff - ((lolo.local_46.f_12[2] / 4 - 4000) >> 3);
		if(lolo.local_146 < 0)
			lolo.local_146 = 0;
		else if(lolo.local_146 > 0xff)
			lolo.local_146 = 0xff;
		lolo.local_145 = C_0075E09A(lolo.local_79)?0xb:9;
		C_0068CF75(lolo.local_145, &lolo.local_163);//init/reset object struct t_ComplexBlendInfo *
		lolo.local_163.f_08 = /*lolo.local_164 = */C_0066101A();//psx:get FarColor
		lolo.local_163.f_08.c.a = lolo.local_146;
		if(lolo.local_145 == 0xb)
			lolo.local_163.f_34[0] = 0;
		C_00684F73(&lolo.local_163, bp08->f_40);//anm: apply complex blend to skeleton?
	}
}

struct SVECTOR D_0096DD78[] = {
	 0x32, 0x32,-0x1e,0,
	-0x1e, 0x32,-0x1e,0,
	-0x1e, 0x32, 0x32,0,
	-0x50,-0x50,-0x50,0,
	 0x45, 0x11,-0x93,0,
	 0x00,-0xff,-0xff,0,
	-0x11,-0x0f, 0x0A,0
};

void C_0075E4D6(short bp08, short bp0c) {
	struct {
		struct fBGRA local_8;
		int _ocal_4;
		struct t_wm_b8 *local_3;
		struct t_aa0 *local_2;
		struct VECTOR *local_1;
	}lolo;

	lolo.local_1 = &D_00E2D1E0;
	lolo.local_3 = C_00768A37(bp08);
	lolo.local_2 = C_00676578();
	if(lolo.local_3) {
		lolo.local_8.r = /*lolo.local_9*/(float)D_0096DD78[bp0c].f_00 * 0.003921569f;
		lolo.local_8.g = /*lolo.local_10*/(float)D_0096DD78[bp0c].f_02 * 0.003921569f;
		lolo.local_8.b = /*lolo.local_11*/(float)D_0096DD78[bp0c].f_04 * 0.003921569f;
		lolo.local_8.a = 1.0f;
		C_00684ECD(lolo.local_3->f_40, lolo.local_2);//anm: apply set color to skeleton?
		C_00684E20(&lolo.local_8, lolo.local_3->f_40, lolo.local_2);//anm: apply add color to skeleton?
		C_006850DB(lolo.local_3->f_40);
	}
}

void C_0075E59A(int _p08) {
	D_00E35654 = 0;
	D_00E35658 = 0;
}

void C_0075E5B3(int bp08) {
	D_00E35654 = bp08;
}

void C_0075E5C0(int bp08) {
	if(D_00E35654) {//else 0075E622
		int local_1 = /*local_2*/(bp08 == 1)?0x18:(D_00E35658 == 1)?0x14:0x10;
		C_00740D80(local_1, D_00E2D608[bp08 - 1], 4, 0, 0, 0, 0, 0, 0);
	}
	D_00E3564C = D_00E35658;
	D_00E35658 = bp08;
}

void C_0075E63A() {
	C_0075E5C0(D_00E35658);
}

int C_0075E64D() {
	return D_00E35658;
}

void C_0075E657(int bp08) {
	C_0074580A(bp08);//sound:play SE?
	if(bp08 == 0xb)
		C_00753860();//fade in/out related(1)?
	else if(bp08 == 0x1b1)
		C_00753888();//fade in/out related(3)?
}

void C_0075E683() {
	C_00745B64();//sound:stop(2)?
	C_007481AD(0);
}

void C_0075E697(int bp08) {
	C_00742F37(bp08);//set_midi_volume
}

void C_0075E6A8(int bp08, int bp0c) {
	C_007481DF(bp0c, bp08);
}

//reset SFX?
void C_0075E6BD() {
	D_00E360EC = 0;
}

//start/stop SFX?
void C_0075E6CC(int bp08) {
	if(bp08 > D_00E360EC) {
		D_00E360EC = bp08;
		C_00745606(0x40, bp08, 0, 0, 0);
	} else if(bp08 == -D_00E360EC) {
		D_00E360EC = 0;
		C_00745B64();//sound:stop(2)?
		C_007481AD(0);
	}
}

void C_0075E720(int bp08) {
	switch(bp08) {
		case 0:
		case 9:
			D_00E2D608 = D_0096D598;
		break;
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 0xa:
			D_00E2D608 = D_0096D5A0;
		break;
		case 0xb:
			D_00E2D608 = D_0096D5A8;
		break;
		case 0xc:
			D_00E2D608 = D_0096D5B0;
		break;
	}//end switch
}
