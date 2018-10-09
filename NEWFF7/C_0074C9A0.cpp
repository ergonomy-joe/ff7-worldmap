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
struct t_pepe_4074 {
	char f_0000[0x70];//__00DFC4F0
	int f_0070[0x1000];//0DFC560
	struct POLY_GT3 *f_4000;//0E00560//0E045D4
};
////////////////////////////////////////
//texture animation related
short D_009699B0[0x16] = {
	0x00,0x08,0x10,0x18,0x20,0x28,0x2C,0x30,
	0x34,0x38,0x3C,0x40,0x44,0x48,0x4C,0x50,
	0x54,0x58,0x5C,0x60,0x64,0x68
};
//009699DC  00 00 00 00
struct {
	int D_009699E0;// = 0x190;
	int __009699E4;//  00 00 00 00
	int __009699E8;//  00 00 00 00
	int __009699EC;//  0C 00 00 00
	int __009699F0;//  22 00 00 00
} some_world_obj = {
	0x190,
	0,
	0,
	0xc,
	0x22
};
//009699F4  00 00 00 00
const char *__009699F8[] = {
	/*00969A78*/"SCR-H",
	/*00969A80*/"FROM ",
	/*00969A88*/"JUMP ",
	/*00969A90*/"OLD  ",
	/*00969A98*/"NEW  ",
};
//00969A0C  00 00 00 00
const char *D_00969A10[] = {
	/*00969AA0*/".MAP",
	/*00969AA8*/".BOT",
	/*00969AB0*/".TXZ",
	/*00969AB8*/".EV",
	/*00969ABC*/".BSZ",
	/*00969AC4*/"S.TXZ"
};
const char *D_00969A28[] = {
	/*00969AD4*/".MAP",
	/*00969ADC*/".BOT",
	/*00969AE4*/".TXZ",
	/*00969AEC*/".EV",
	/*00969AF0*/".BSZ",
	/*00969AF8*/"S.TXZ"
};
int D_00969A40[] = {
	0x321B6F83,
	0x321B6F87,
	0x321B6FF3,
	0x325B7FF7,
	0x375B7FFF,
	0
};
//00969A54  00 00 00 00
int D_00969A58[] = {
	0x000005DC,
	0x00000708,
	0x00000708,
	0x00000708
};
int D_00969A68[] = {
	0x00002710,
	0x00001B58,
	0x00001B58,
	0x00000FA0
};
//00969A78	"SCR-H"
//00969A80	"FROM "
//00969A88	"JUMP "
//00969A90	"OLD  "
//00969A98	"NEW  "
//00969AA0	".MAP"
//00969AA8	".BOT"
//00969AB0	".TXZ"
//00969AB8	".EV"
//00969ABC	".BSZ"
//00969AC4	"S.TXZ"

//00969ACC	"wm/WM"

//00969AD4	".MAP"
//00969ADC	".BOT"
//00969AE4	".TXZ"
//00969AEC	".EV"
//00969AF0	".BSZ"
//00969AF8	"S.TXZ"

//00969B00	"WM"
//00969B04	"wm.ta"
//00969B0C	"mes"
//00969B10	"field.tbl"
//00969B1C	"atn.tbl"
//00969B24	"enc_w.bin"
////////////////////////////////////////
int D_00DE6A04;
int D_00DE6A08;//highwind state
int D_00DE6A0C;
struct POLY_GT3 *D_00DE6A10;
int D_00DE6A14;
short D_00DE6A18;
int D_00DE6A1C;
struct MATRIX D_00DE6A20;
int D_00DE6A40;
char D_00DE6A48[0x100];//todo
int D_00DE6B48;
int D_00DE6B4C;
int D_00DE6B54;
int D_00DE6B58;
int D_00DE6B5C;
int D_00DE6B60;
int D_00DE6B64;
int D_00DE6B6C;
int D_00DE6B70;
struct t_wm_8a0 D_00DE6B78;//"enc_w.bin"
short D_00DE7418;
int D_00DE741C;
unsigned char D_00DE7420[0xe000];//"wm.ta"
int D_00DF5420;
int D_00DF5424;
int D_00DF5428;
int D_00DF542C;
short D_00DF5430;
int D_00DF5434;
int D_00DF5438;
char *D_00DF543C;
int D_00DF5440;
struct POLY_GT3 *D_00DF5444;
unsigned char D_00DF5448[0x7000];//"??WM"
struct MATRIX D_00DFC448;
int D_00DFC468;
int D_00DFC46C;
int D_00DFC470;
int D_00DFC474;
int D_00DFC478;
int D_00DFC47C;
int D_00DFC480;
int D_00DFC484;
int D_00DFC488;
int D_00DFC48C;
int D_00DFC490;
int D_00DFC494;
int D_00DFC498;
int D_00DFC49C;
int D_00DFC4A0;//earthquake effect flag
int D_00DFC4A4;
int D_00DFC4A8;
int D_00DFC4AC;
int D_00DFC4B4;
int D_00DFC4B8;
int D_00DFC4BC;
char D_00DFC4C0[0x30];
struct t_pepe_4074 D_00DFC4F0[2];
int D_00E045D8;
int D_00E045DC;
int D_00E045E0;
int D_00E045E4;
int D_00E045E8;
int D_00E045EC;//go to menu
int D_00E045F0;
//00E045F4
////////////////////////////////////////
//<empty>:some error management?
void C_0074C9A0(int _p08) {
}

int C_0074C9A5() {
	return D_00DE6A1C;
}

struct POLY_GT3 *C_0074C9AF(unsigned bp08) {
	struct POLY_GT3 *local_1;

	if(&(D_00DE6A10[bp08]) < &(D_00DF5444[0xd00])) {
		local_1 = D_00DE6A10;
		D_00DE6A10 += bp08;
	} else {
		C_0074C9A0(1);//<empty>:some error management?
	}

	return local_1;
}

char *C_0074CA00(int bp08, int bp0c) {
	char local_1[2];

	strcpy(D_00DE6A48, D_009A06B8);
	strcat(D_00DE6A48, /*00969ACC*/"wm/WM");
	local_1[0] = (bp0c < 0xa)?bp0c + 0x30:bp0c + 0x37;
	local_1[1] = 0;
	strcat(D_00DE6A48, local_1);
	strcat(D_00DE6A48, D_00969A10[bp08]);

	return D_00DE6A48;
}

char *C_0074CAEC(int bp08, int bp0c) {
	char local_1[2];

	strcpy(D_00DFC4C0, /*00969B00*/"WM");
	local_1[0] = (bp0c < 0xa)?bp0c + 0x30:bp0c + 0x37;
	local_1[1] = 0;
	strcat(D_00DFC4C0, local_1);
	strcat(D_00DFC4C0, D_00969A28[bp08]);

	return D_00DFC4C0;
}

//set earthquake effect
void C_0074CBB5(int bp08) {
	D_00DFC4A0 = bp08;
}

void *C_0074CBC2() {
	void *local_2;
	int local_1;

	local_1 = 0x9c4;
	if(local_1 > 0xfff)
		local_1 = 0xfff;
	if(D_00DFC4AC)
		local_2 = &(D_00E36114[local_1]);
	else
		local_2 = 0;

	return local_2;
}

int C_0074CECA(int, unsigned char);

int C_0074CC07(struct t_wm_local_18 *bp08, struct SVECTOR *bp0c, struct t_wm_local_08 *bp10, short *bp14, struct t_wm_local_0c **bp18, short *bp1c, unsigned char bp20) {
	struct {
		int local_12;
		int local_11;
		struct t_wm_local_0c *local_10;
		int local_9;
		struct t_wm_local_0c *local_8;
		int local_7;
		struct SVECTOR *local_6;//size 8
		struct t_wm_local_08 *local_5;//size 8
		int local_4;
		int local_3;
		int local_2;
		int local_1;
	}lolo;

	lolo.local_6 = &D_00E2D5D8;
	*lolo.local_6 = *bp0c;
	lolo.local_2 = *bp14;
	lolo.local_9 = 0x7FFFFFFF;
	lolo.local_3 = 0;
	lolo.local_10 = 0;
	if(bp10) {
		for(lolo.local_5 = bp10; lolo.local_5 < &(bp10[6]) && lolo.local_3 <= 0; lolo.local_5 ++) {
			if(lolo.local_5->f_00)
			if(lolo.local_5->f_04 == bp08->f_10 && lolo.local_5->f_06 == bp08->f_12)
			if(C_0076085F(lolo.local_5->f_00, lolo.local_6, &lolo.local_1)) {
				lolo.local_12 = lolo.local_5->f_00->f_03 | (lolo.local_5->f_00->f_0b << 8);
				lolo.local_11 = lolo.local_1;
				lolo.local_3 = -1;
				if(C_0074CECA(lolo.local_12, bp20)) {
					lolo.local_10 = lolo.local_5->f_00;
					lolo.local_3 = 1;
				}
			}
		}
	}
	if(lolo.local_3 == 0) {//else 0074CE8F
		for(lolo.local_8 = bp08->f_04; lolo.local_8 < &(bp08->f_04[bp08->f_14]); lolo.local_8 ++) {
			if(C_0076085F(lolo.local_8, lolo.local_6, &lolo.local_1)) {
				lolo.local_7 = lolo.local_8->f_03 | (lolo.local_8->f_0b << 8);
				lolo.local_4 = /*lolo.local_14*/(bp20 != 3 && bp20  != 5 && D_00E045E8 != 2)?
					/*lolo.local_13*/inline_abs(lolo.local_1 - lolo.local_2)
				:
					lolo.local_1
				;
				if(lolo.local_9 > lolo.local_4) {
					lolo.local_3 ++;
					lolo.local_9 = lolo.local_4;
					lolo.local_10 = lolo.local_8;
					lolo.local_12 = lolo.local_7;
					lolo.local_11 = lolo.local_1;
				}
			}
		}
		if(lolo.local_3) {//else 0074CE8F
			if(bp10 && lolo.local_10) {//else 0074CE6D
				for(lolo.local_5 = &(bp10[4]); lolo.local_5 >= bp10; lolo.local_5 --) {
					lolo.local_5[1] = lolo.local_5[0];
				}
				bp10->f_00 = lolo.local_10;
				bp10->f_04 = bp08->f_10;
				bp10->f_06 = bp08->f_12;
			}
			if(C_0074CECA(lolo.local_12, bp20) == 0) {
				lolo.local_10 = 0;
				lolo.local_3 = 0;
			}
		}
	}
	if(bp1c)
		*bp1c = lolo.local_12;
	if(bp14)
		*bp14 = lolo.local_11;
	if(bp18)
		*bp18 = lolo.local_10;

	return lolo.local_3 > 0;
}

int C_0074DB52(void);

int C_0074CECA(int bp08, unsigned char bp0c) {
	struct {
		int bp_08;
		int bp_04;
	}lolo;

	lolo.bp_08 = (bp08 & 0xe0) != 0xe0;
	lolo.bp_04 = /*bp_0c*/(C_00762136() == 0xd || C_00762136() == 0xe) && (C_00761735() == bp0c);
	switch(bp0c) {
		case 0x00:
		case 0x01:
		case 0x02:
			return BIT_ISSET_2(lolo.bp_04?0x20006000:0x721B6F83, bp08);
		case 0x04:
			if(C_00766B53() == 2)
				return BIT_ISSET_2(lolo.bp_04?0x20006000:0x321B6F83, bp08) && lolo.bp_08;
			return BIT_ISSET_2(lolo.bp_04?0x20006000:0x321B6F83, bp08);
		case 0x13:
			if(C_00766B53() == 2)
				return BIT_ISSET_2(lolo.bp_04?0x20006000:0x321B6F83, bp08) && lolo.bp_08;
			return BIT_ISSET_2(lolo.bp_04?0x20006000:D_00969A40[C_0074DB52()], bp08);
		case 0x03:
			if(C_00766B53() == 2)
				return BIT_ISSET_2(0x021B6F83, bp08) && lolo.bp_08;
			return D_00DE6A08 >= 0?1:((bp08 & 0x1f)?0:1);
		case 0x05:
			if(C_00761FE8()) {
				if(C_00766B53() == 2)
					return BIT_ISSET_2(0x70, bp08);
				return D_00DE6A08 >= 0?1:BIT_ISSET_2(0x70, bp08);
			}
			if(C_00766B53() == 2)
				return BIT_ISSET_2(0x20800, bp08);
			return BIT_ISSET_2(0x70, bp08);
		case 0x06:
			if(C_00766B53() == 2)
				return BIT_ISSET_2(0x21B6F83, bp08) && lolo.bp_08;
			return BIT_ISSET_2(0x331B6F13, bp08);
		case 0x0d:
			if(C_00766B53() == 2)
				return BIT_ISSET_2(0x21B6F83, bp08) && lolo.bp_08;
			return BIT_ISSET_2(0x04048008, bp08);
		case 0x08:
			return BIT_ISSET_2(0x04040008, bp08);
		case 0x64:
			return (bp08 & 0x1f) == 7;
	}

	return 1;
}

int C_0074D28E() {
	return D_00DFC4B4;
}

int C_0074D298() {
	return D_00DFC474 & 0xfff;
}

void C_0074D2A7(int bp08) {
	D_00DFC484 = bp08 & 0xfff;
}

void C_0074D2B9(int bp08) {
	D_00DFC474 =
	D_00DFC484 = bp08 & 0xfff;
}

void C_0074D2D7(int bp08) {
	D_00DFC48C = bp08;
	if(bp08 == 1) {
		D_00DFC47C = D_00969A68[D_00DFC4B4];
		D_00DE6A0C = D_00969A58[D_00DFC4B4];
	}
}

int C_0074D30F() {
	return D_00DFC48C;
}

int C_0074D319() {
	return D_00DE6B70;
}

void C_0074D323(int bp08) {
	D_00DE6B70 = bp08;
}

int C_0074D330() {
	return D_00E045E8;
}

void C_0074D33A(struct SVECTOR *bp08) {
	struct {
		struct MATRIX local_15;
		struct VECTOR local_7;
		int local_3;
		struct SVECTOR local_2;
	}lolo;

	lolo.local_2 = *bp08;
	lolo.local_2.f_02 = -D_00DE6A04;
	C_00663673(&D_00DFC448);//psx:SetRotMatrix?
	C_00663707(&D_00DE6A20);//psx:SetTransMatrix?
	C_00662ECC(&lolo.local_2, &lolo.local_7, &lolo.local_3);//psx:RotTrans
	C_00663766(&lolo.local_15, &lolo.local_7);//psx:set translate vector?
	C_00663707(&lolo.local_15);//psx:SetTransMatrix?
}

void C_0074D3A7() {
	C_00663673(&D_00DFC448);//psx:SetRotMatrix?
	C_00663707(&D_00DE6A20);//psx:SetTransMatrix?
}

short C_0074D3C6() {
	return D_00DE7418;
}

void C_0074D3D1(int bp08) {
	D_00E045DC = D_00DFC4B4;
	D_00DFC4B4 = bp08;
	if((D_00DFC4B4 == 0 || D_00DFC4B4 == 1) && D_00E045E8 != 3)
		D_00DFC484 = 0;
	D_00DF542C = D_00DFC4B4?0xa0:0x78;
	D_00DE741C = (D_00DFC4B4 != 3) * 0x78;
}

void C_0074D438(int bp08, int bp0c) {
	struct VECTOR local_4;

	if(bp08) {
		if(bp0c == D_00DFC4A8 || D_00DFC4A8 == 6) {
			D_00DE6B5C = 1;
			C_00762798(&local_4);
			C_0075027C(&local_4, (bp0c == 3 && D_00DFC4A8 != 6)?0:1);
		}
	} else {
		D_00DE6B5C = 0;
		D_00DFC4A8 = bp0c;
	}
}

int C_0074D4B6() {
	return D_00DE6B5C;
}

void C_0074D4C0(short bp08) {
	D_00DF5434 = bp08 + D_00DFC484 - 0x800;
}

int C_0074D4DC() {
	return D_00DFC4B8 == 0;
}

int C_0074D4ED() {
	return D_00E045D8;
}

//set "highwind" state?
//1 go up?
//-1 go down?
void C_0074D4F7(int bp08) {
	D_00DE6A08 = bp08;
}

//get "highwind" state?
int C_0074D504() {
	return D_00DE6A08;
}

void C_0074D50E(struct t_wm_b8 *bp08, struct SVECTOR *bp0c, struct MATRIX *bp10, int bp14) {
	struct {
		struct MATRIX local_15;
		int local_7;
		struct VECTOR local_6;
		struct SVECTOR local_2;
	}lolo;

	lolo.local_15.f_00[0][0] =
	lolo.local_15.f_00[1][1] =
	lolo.local_15.f_00[2][2] = 0x1000;

	lolo.local_15.f_00[0][1] =
	lolo.local_15.f_00[0][2] =
	lolo.local_15.f_00[1][0] =
	lolo.local_15.f_00[1][2] = 
	lolo.local_15.f_00[2][0] =
	lolo.local_15.f_00[2][1] = 0;
	C_006625AB(bp0c->f_00, &lolo.local_15);//psx:x_rotate
	C_006627CD(bp0c->f_04, &lolo.local_15);//psx:z_rotate
	C_006626BC(bp0c->f_02, &lolo.local_15);//psx:y_rotate
	C_00662035(&D_00DFC448, &lolo.local_15, bp10);//psx:...
	C_00663673(&D_00DFC448);//psx:SetRotMatrix?
	if(D_00DFC46C > 0 && bp14) {
		lolo.local_6.f_00 = D_00DE6A20.f_12[0] / 2;
		lolo.local_6.f_04 = D_00DE6A20.f_12[1] / 2;
		lolo.local_6.f_08 = D_00DE6A20.f_12[2] / 2;
		D_00DFC46C --;
		if(D_00DFC46C == 0)
			C_0075E5C0(D_00E3564C);
	} else {
		lolo.local_6.f_00 = D_00DE6A20.f_12[0];
		lolo.local_6.f_04 = D_00DE6A20.f_12[1];
		lolo.local_6.f_08 = D_00DE6A20.f_12[2];
	}
	C_00663766(bp10, &lolo.local_6);//psx:set translate vector?
	C_00663707(bp10);//psx:SetTransMatrix?
	lolo.local_2.f_00 = /*ftol*/(short)bp08->f_44.f_04.f_00;
	lolo.local_2.f_02 = /*ftol*/(short)bp08->f_44.f_04.f_04;
	lolo.local_2.f_04 = /*ftol*/(short)bp08->f_44.f_04.f_08;
	C_00662ECC(&lolo.local_2, &lolo.local_6, &lolo.local_7);//psx:RotTrans
	bp08->f_44.f_04.f_08 = 0;
	bp08->f_44.f_04.f_04 = 0;
	bp08->f_44.f_04.f_00 = 0;
	C_00663766(bp10, &lolo.local_6);//psx:set translate vector?
}

void C_0074D6BB() {
	D_00E045E4 = 5;
	D_00DFC490 = 0x14;
	C_007670F9(0);
	C_0074D438(0, 0);
	C_00755B97(0x10, 1);
}

void C_0074D6F6() {
	D_00E045E4 = 4;
	D_00DFC490 = -0x14;
	C_007670F9(0);
	C_0074D438(0, 0);
	C_00755B97(0x10, 1);
}

void C_0074D731(int bp08) {
	C_007670F9(bp08);
	D_00E045E4 = 8;
}

void C_0074D74C(int bp08) {
	if(D_00E045E4 < 1) {
		D_00DFC47C =
		D_00DE6A0C = 0;
		D_00DFC4AC = 1;
		D_00E045E4 = 1;
	}
	if(D_00E045E4 == 1) {
		D_00E045E4 = 2;
		C_0074D438(0, 0);
		C_007670F9(bp08);
		C_00755B97(0x10, 1);
		D_00E045F0 = 1;
		C_0074C980(0);//set "allowsFrameSkip"?
	}
}

void C_0074D7CD(int bp08) {
	if(D_00E045E4 < 1) {
		D_00DFC47C =
		D_00DE6A0C = 0;
		D_00DFC4AC = 1;
		D_00E045E4 = 1;
	}
	if(D_00E045E4 == 1 || D_00E045E4 == 2) {
		if(D_00CBFB6C == 0) {
			D_00E045E4 = 3;
			C_0074D438(0, 0);
			C_0076717C(bp08);
			if(C_007538B0())//get fade in/out info?
				C_0075389C();
			C_0074C973(1);//set "isRendering"?
			C_0074C980(0);//set "allowsFrameSkip"?
		} else {
			D_00DFC46C = 0x1E;
			C_00767515();
		}
	}
}

void __0074D875() {
	if(D_00E045E4 < 1) {
		D_00DFC47C =
		D_00DE6A0C = 0;
		D_00DFC4AC = 1;
		D_00E045E4 = 1;
	}
	if(D_00E045E4 == 1) {
		D_00E045E4 = 3;
		C_0074D438(0, 0);
		C_007671E1();
	}
}

int C_0074D8CF() {
	return (D_00DFC4B4 & 3) | ((C_00768343() << 2) & 0xc);
}

void C_0074D8EF(int bp08) {
	C_0074D3D1(bp08 & 3);
	C_0076831F((bp08 >> 2) & 3);//set map/radar state
}

//get string from "mes"
unsigned char *C_0074D915(short bp08) {
	if(bp08 >= 0 && bp08 < *(short *)(D_00E36118 + 8))
		return (D_00E36118 + 8) + ((short *)(D_00E36118 + 8 + 2))[bp08];

	return 0;
}

void C_0074D946() {
	D_00DFC494 = 0;
}

void C_0074D955(int bp08) {
	switch(bp08) {
		case 1:
			C_0074D438(0 ,4);
			C_00755B97(4, 1);
		break;
		case 4:
			C_0074D438(1, 4);
			C_00755B70(0x10, 1);
			bp08 = 0;
		break;
	}
	D_00DFC494 = bp08;
}

void C_0074D9B3() {
	int local_2;
	int local_1;

	local_1 = C_0074C9A5();
	switch(D_00DFC494) {
		case 1:
			if(C_00755C2F())
				D_00DFC494 = 2;
		break;
		case 2:
			local_2 = C_0040AC84();//get frame count
			if(local_2 - D_00DF5428 > 3 && local_2 - D_00DF5428 < 6)
				D_00DFC494 = 3;
			D_00DF5428 = local_2;
		break;
	}
}

void C_0074DA26(int bp08) {
	D_00DF5424 = bp08;
}

void C_0074DA33(int bp08) {
	D_00DE6B60 = bp08;
}

void C_0074DA40(int bp08) {
	D_00DFC498 = bp08;
}

void C_0074DA4D() {
	switch(D_00DFC48C) {
		case 0:
			D_00DFC484 += D_00DF5424;
			D_00DFC47C =
			D_00DE6A0C = 0;
		break;
		case 1:
			D_00DFC484 += D_00DF5424;
			D_00DFC47C += D_00DFC498;
			if(D_00DFC47C > 0x3A98)
				D_00DFC47C = 0x3A98;
			else if(D_00DFC47C < 0x3E8)
				D_00DFC47C = 0x3E8;
			D_00DE6A0C += D_00DE6B60;
			if(D_00DE6A0C > 0x780)
				D_00DE6A0C = 0x780;
			else if(D_00DE6A0C < 0x480)
				D_00DE6A0C = 0x480;
		break;
	}
}

void C_0074DB2B(int bp08) {
	D_00DFC47C = bp08;
}

void C_0074DB38(int bp08) {
	D_00DE6A0C = bp08;
}

void C_0074DB45(int bp08) {
	D_00DE6B54 = bp08;
}

int C_0074DB52() {
	return D_00DE6B54;
}

void __0074DB5C() {
}

void C_0074DB61() {
	if(D_00DE69E0 == 0 && D_00DE69E4 == 0) {
		D_00E045E4 = 0;
		D_00DE69E4 = 1;
	}
}

void C_0074E1E9(short);
void C_0074E48A(void);
void C_0074E505(void);
void C_0074E633(int);//render sky gradation?
void C_0074E802(int);//texture animation
void C_0074E8CE(short);
void C_0074EA48(void);
void C_0074F87D(void);
void C_0074FBCA(void);
void C_0074FBEC(void);
void C_0074FE89(void);

int C_0074DB8C(int *bp08, int *bp0c, int *bp10, int bp14) {
	struct {
		int local_7;
		struct VECTOR local_6;
		int local_2;
		int local_1;
	}lolo;
	
	C_0074DB61();
	D_00DFC488 = 0;
	D_00DFC488 = bp14;
	if(D_00E045E4 < 9) {//else 0074E1E0
		if(D_00DE69E0 == 0) {//else 0074DE7C
			D_00E045E8 = /*lolo.local_8*/*bp08?
				C_00766C6E():
				/*lolo.local_10*/(D_00E045E4 != 6 && *bp0c != 0x1e && *bp0c != 0x1f && *bp0c != 0x2a && *bp0c != 0x38)?
					/*lolo.local_9*/(D_00E045E4 != 7 && *bp0c >= 0x3c)?3:0
				:
					2
			;
			lolo.local_2 = C_00766B9F();
			C_0074E1E9(/*lolo.local_11*/(*bp08 == 0 && *bp0c >= 0x24 && *bp0c <= 0x27)?(lolo.local_2 > 0) + 9:(D_00E045E8 == 0)?lolo.local_2:D_00E045E8 + 9);
			C_0075E683();
			C_00768C4C((lolo.local_2 != 3 && lolo.local_2 != 4 && lolo.local_2 != 6 && lolo.local_2 != 8)?0:1);
			D_00DFC4B4 = 0;
			C_00767D40();//reset map/radar
			C_00750473();
			C_00766C7A(bp08, bp0c, D_00E045E8 != 3);
			if(D_00E045E8 == 2)
				C_0074D3D1(2);
			D_00DE741C = 0;
			C_0074F87D();
			C_0074E48A();
			C_007538BA();
			C_00754E1D();
			C_00755495();
			C_00756A95();
			C_00767501();
			C_00767533(1);
			C_0074D946();
			C_0075EE50((struct t_script_20 *)D_00E36118);
			C_00755F95();
			C_007543D3();
			C_0075AC80();
			C_0076110B();
			C_007663E0();
			C_0075E697(0x7f);
			C_00763C35(&D_00DF5448);
			C_007640BC(0);
			C_007641A7();
			D_00DF5420 = (C_00761735() != 3)?0x7d0:0xfa0;
			if(*bp08 == 1 || *bp08 == 2 || D_00E045E4 == 7 || D_00E045E4 == 6)
				C_00767097();
			if(D_00E045E4 == 7 || D_00E045E4 == 6)
				C_0075378A(0xbb8);
			if(D_00E045E8 == 2) {
				C_00761FAA(1);
				C_00762702(-0xbb8);
			}
			C_007533AF();
			C_00768A37(C_0076736E());
			if(C_0075E64D() < 6)
				C_0075E5B3(1);
			if(C_0075E64D())
				C_0075E63A();
			else
				C_0075E5C0(1);
			C_0074EA48();
			D_00E045E4 = -0xf;
			D_00DE69E0 = 1;
		}
		if(D_00E045E4 < 6) {//else 0074E16B
			if(D_00E045EC == 0) {//else 0074DFBF
				C_0074E505();
				C_0074E802(D_00DFC480 - (D_00DFC480 == 1));//texture animation
				D_00E37520 = 0;
				C_0076315C();
				//-- --
				C_00762798(&lolo.local_6);
				lolo.local_1 = inline_abs(lolo.local_6.f_04 - D_00DE6A04);
				if(D_00DFC48C != 2) {//else 0074DF6C
					D_00DE6A04 = /*lolo.local_16*/(C_00761F77() == 0 && lolo.local_1 <= 0xc8)?
						/*lolo.local_15*/(lolo.local_1 > 0x32)?D_00DE6A04 + ((lolo.local_6.f_04 > D_00DE6A04)?0x32:-0x32):lolo.local_6.f_04:
						((D_00DE6A04 * 7 + lolo.local_6.f_04) >> 3)
					;
				}
				C_0074EA48();
				C_0074DA4D();
				//-- --
				C_00762798(&lolo.local_6);
				C_007550A7(&lolo.local_6);//sky color transition?
				//-- --
				C_007641A7();
				C_0074E8CE(D_00DFC474);
				C_0075079D(D_00DFC474, 1);
				C_00765F61();
				C_0074FE89();
			}
			C_0074FBEC();
			if(D_00E045EC == 0) {//else 0074E16B
				if(D_00E045E4 < 9)
					C_0075EF46();//manage text event?
				C_007591F3();
				if(
					(D_00DFC4B4 == 3 && D_00DE6A08 == 0) ||
					(D_00E045E8 == 2 && C_0075335C())
				) {//else 0074E0BB
					C_00762798(&lolo.local_6);
					lolo.local_7 = C_0076201E();
					D_00DE6A14 = lolo.local_6.f_04 > (lolo.local_7 + 0xc8);
					if(D_00DE6A14 == 0 && D_00DE6A08 == 0) {//else 0074E0BB
						if(C_00761769(0x2000))
							C_00762702(min(-0xbb8, lolo.local_7 + 0xc8));
						else if(C_00761735() == 3 || lolo.local_7 < 0x7d0)
							C_00762702(lolo.local_7 + 0xc8);
						else
							C_007628B5();
					}
				}
				//-- sky related ? --
				C_00754100(D_00DFC474);
				C_007547A6(D_00DFC474);
				//-- --
				C_0074D9B3();
				C_0075551A();//render "extra layers"?
				if(D_00E045E4 < 9 && D_00E045E8 != 3)
					C_00767D68(D_00DFC474);//render map/radar
				C_007667B2(0);
				C_007573D9();
				C_00661A1C(some_world_obj.D_009699E0);//psx:camera related?
				if(D_00E045E4 >= 0)
					C_0076323A();
				C_0075C02B();
				C_007562FF();
				C_007689F7();
				if(D_00E045E4 == 1)
					C_00767540();
				C_0074E633(D_00DFC480 - (D_00DFC480 == 1));//render sky gradation?
			}
		}
		if(D_00E045E4 >= 6) {//else 0074E1E0
			C_007640BC(1);
			while(C_0076603F())
				C_007641A7();
			C_007506B6();
			C_00767039(bp08, bp0c, bp10);
			if(*bp08 == 1) {
				C_007538C9(3);
				C_0074FBCA();
			}
			C_0075E683();
			if(D_00E045E4 == 9)
				D_00DE69DC = 1;
			D_00DE69E0 = 0;
		}
	}

	return C_0074C9A5();
}

void C_0074E1E9(short bp08) {
	struct {
		int _ocal_10;
		int i;//local_9
		int _ocal_8[2];
		int local_6;
		int _ocal_5[5];
	}lolo;

	D_00DFC4F0[0].f_4000 = &(D_00E2D5FC[0]);
	D_00DFC4F0[1].f_4000 = &(D_00E2D5FC[0xd00]);
	if(bp08 > 0xa)
		D_00DFC488 = 0;
	C_0075A1C6(bp08);//wmfile:secure init?
#if (_MSC_VER < 1500)
	//
#else
	lolo.local_6 = 0;
#endif
	C_0075E59A(lolo.local_6);
	C_0075E720(bp08);
	C_007688E0();
	C_00768BE2(bp08);
	C_0075931B(/*00969B04*/"wm.ta", 0xe000, D_00DE7420, 0);//wmfile:read file(archive)
	if(D_00E045E8 > 1)
		*(int *)D_00DE7420 = 0;
	C_0075931B(C_0074CAEC(3, D_00E045E8), 0x7000, D_00DF5448, 0);//wmfile:read file(archive)
	C_0075931B(/*00969B0C*/"mes", 0x1000, D_00E36118 + 8, 0);//wmfile:read file(archive)
	C_0075931B(/*00969B10*/"field.tbl", 0x600, D_00E37D30, 0);//wmfile:read file(archive)//0x80 * 0xc = 0x600
	C_0075931B(/*00969B1C*/"atn.tbl", 0x200 * 2, D_00E37120, 0);//wmfile:read file(archive)
	C_0075931B(/*00969B24*/"enc_w.bin", 0x8A0, &D_00DE6B78, 0);//wmfile:read file(archive)
	if(D_00E045E8 == 2) {
		C_00755C40();
		for(lolo.i = 1; lolo.i < 2; lolo.i ++)
			C_00755CFF(lolo.i);
	}
	D_00DFC480 = 2;
	D_00DE6B5C = 1;
	D_00DFC4A8 = 0;
	D_00DFC4AC = 0;
	D_00DE6A14 = 0;
	D_00DFC4B8 = 0;
	D_00DE6A0C = 0;

	D_00DE6B4C =
	D_00DF542C = 0xA0;

	D_00DE6A08 = 0;
	D_00DFC49C = 0;
	D_00DE6A40 = 0;
	D_00DE6B70 = 0;
	D_00DE741C = 0;

	D_00DFC484 =
	D_00DFC474 = 0;

	D_00DE6A04 = 0;
	D_00DF5438 = 0;
	D_00E36110 = 0;
	D_00DFC468 = 0x5DC;
	D_00DFC478 = 0x2710;

	D_00DF5424 =
	D_00DE6B60 = 
	D_00DFC498 = 0;

	D_00DF5434 = 0;
	D_00DFC46C = 0;
	D_00DE6B54 = 0;
	D_00E045D8 = 0x1388;
	D_00DFC4A0 = 0;
	D_00DE6A1C = 0;
	D_00DFC48C = 0;
	D_00E045F0 = 0;
}

void C_0074E48A() {
	struct {
		int j;//bp_0c
		int i;//bp_08
		struct POLY_GT3 *bp_04;
	}lolo;

	for(lolo.i = 0; lolo.i < 2; lolo.i ++) {
		for(lolo.j = 0; lolo.j < 0xd00; lolo.j ++) {
			lolo.bp_04 = &(D_00DFC4F0[lolo.i].f_4000[lolo.j]);
			setPolyGT3(lolo.bp_04);
		}
	}
	C_00753F53();
}

void C_0074E5CB(void);

void C_0074E505() {
	int local_2;
	int local_1;

	C_0074E5CB();
	C_00661A1C(some_world_obj.D_009699E0);//psx:camera related?
	if(D_00DFC4A0) {//else 0074E58D
		//-- earthquake effect
		if(D_00DE69D8 == 1) {
			local_1 = (C_00753BE8() >> 6) - 2;
			local_2 = D_00DE6B4C - 0x7a + (C_00753BE8() >> 6);
		} else {
			local_1 = ((C_00753BE8() >> 6) - 2) * 2;
			local_2 = (D_00DE6B4C - 0x7a + (C_00753BE8() >> 6)) * 2;
		}
		C_00661B68(local_1, local_2);//psx:set view x,y?
	} else {
		//-- normal
		local_2 = (D_00DE69D8 == 1)?D_00DE6B4C - 0x78:(D_00DE6B4C - 0x78) * 2;
		C_00661B68(0, local_2);//psx:set view x,y?
	}
}

void C_0074E5CB() {
	D_00DE6A1C = D_00DE6A1C == 0;
	D_00DE6A10 =
	D_00DF5444 = D_00DFC4F0[D_00DE6A1C].f_4000;
	D_00E36114 = D_00DFC4F0[D_00DE6A1C].f_0070;
	D_00DF543C = D_00DFC4F0[D_00DE6A1C].f_0000;
}

//render sky gradation?
void C_0074E633(int _p08) {
	struct {
		struct t_dx_rend_vertex_20 *local_6[4];
		struct t_wm_vertexinfo *local_2;
		int local_1;
	}lolo;

	//-- unused --
	lolo.local_1 = 0x9c4;
	if(lolo.local_1 > 0xfff)
		lolo.local_1 = 0xfff;
	//-- --
	if(D_00DFC4AC) {
		if(C_0066E272(1, D_00E2C3E8)) {
			if(C_0074C969()) {//get "isRendering"?
				lolo.local_2 = C_007540E5();
				MK_VERTEX_NOTEXTURE(&(D_00E2C3E8->f_70.asVertex[0]), lolo.local_6[3], lolo.local_2->x0, lolo.local_2->y0, 0.9999f, 1.0f, lolo.local_2->rgba0, 0xff000000);
				MK_VERTEX_NOTEXTURE(&(D_00E2C3E8->f_70.asVertex[1]), lolo.local_6[2], lolo.local_2->x1, lolo.local_2->y1, 0.9999f, 1.0f, lolo.local_2->rgba1, 0xff000000);
				MK_VERTEX_NOTEXTURE(&(D_00E2C3E8->f_70.asVertex[2]), lolo.local_6[1], lolo.local_2->x2, lolo.local_2->y2, 0.9999f, 1.0f, lolo.local_2->rgba2, 0xff000000);
				MK_VERTEX_NOTEXTURE(&(D_00E2C3E8->f_70.asVertex[3]), lolo.local_6[0], lolo.local_2->x3, lolo.local_2->y3, 0.9999f, 1.0f, lolo.local_2->rgba3, 0xff000000);
			}
		}
	}
}

struct t_wm_local_ta_08 {
	/*00*/unsigned f_00;//offset in file
	/*04*/unsigned short f_04;//size of chunk
	/*06*/unsigned char f_06;//# of chunks
	/*07*/unsigned char f_07;//cycle speed parameter
};

//texture animation
void C_0074E802(int _p08) {
	struct {
		int _ocal_5;
		unsigned i;//local_4
		int _ocal_3;
		int *local_2;
		struct t_wm_local_ta_08 *local_1;
	}lolo;

	lolo.local_1 = (struct t_wm_local_ta_08 *)(D_00DE7420 + 4);
	for(lolo.i = 0; lolo.i < *(int *)D_00DE7420; lolo.i ++) {
		lolo.local_2 = (int *)D_00DE7420 + (lolo.local_1->f_00 >> 2) + (lolo.local_1->f_04 >> 2) * (((unsigned)C_0040AC84() / lolo.local_1->f_07) % lolo.local_1->f_06);
		//lolo.local_2 points to some unused texture/animation info.
		D_00E2BBD8[D_0096B448[lolo.i]] = D_00E2C658[D_009699B0[lolo.i] + (((unsigned)C_0040AC84() / lolo.local_1->f_07) % lolo.local_1->f_06)];
		lolo.local_1 ++;
	}
}

int C_0074F916(void);

void C_0074E8CE(short bp08) {
	struct {
		struct MATRIX local_27; char _ocal_27[2];
		struct MATRIX local_19; char _ocal_19[2];
		struct VECTOR local_11;
		struct VECTOR local_7;
		struct SVECTOR local_3;
		int local_1;
	}lolo;

	lolo.local_3.f_00 = C_0074F916();
	lolo.local_3.f_02 =
	lolo.local_3.f_04 = 0;
	C_006628DE(&lolo.local_3, &lolo.local_27);//psx:xyz_rotate(1)
	lolo.local_11.f_00 =
	lolo.local_11.f_04 =
	lolo.local_11.f_08 = 0;
	C_00663766(&lolo.local_27, &lolo.local_11);//psx:set translate vector?
	C_00663673(&lolo.local_27);//psx:SetRotMatrix?
	C_00663707(&lolo.local_27);//psx:SetTransMatrix?
	lolo.local_3.f_00 =
	lolo.local_3.f_02 = 0;
	lolo.local_3.f_04 = D_00DFC478;
	C_00662ECC(&lolo.local_3, &lolo.local_7, &lolo.local_1);//psx:RotTrans
	lolo.local_11.f_00 = 0;
	lolo.local_11.f_04 = 0;
	lolo.local_1 = (lolo.local_7.f_04 << 4) - D_00DE6A04;
	lolo.local_11.f_08 = D_00DFC478;
	C_00663766(&D_00DE6A20, &lolo.local_11);//psx:set translate vector?
	lolo.local_1 = (lolo.local_1 << 8) / (lolo.local_7.f_08 << 4);
	if(lolo.local_1 < 0)
		lolo.local_1 = 0;
	else if(lolo.local_1 >= 0x200)
		lolo.local_1 = 0x1ff;
	D_00DE7418 =
	lolo.local_3.f_00 = D_00E37120[lolo.local_1] + 0x800;
	lolo.local_3.f_02 = bp08;
	lolo.local_3.f_04 = 0;
	C_006628DE(&lolo.local_3, &lolo.local_27);//psx:xyz_rotate(1)
	lolo.local_3.f_00 =
	lolo.local_3.f_02 = 0;
	lolo.local_3.f_04 = D_00DE6B70;
	C_006628DE(&lolo.local_3, &lolo.local_19);//psx:xyz_rotate(1)
	C_00662035(&lolo.local_19, &lolo.local_27, &D_00DFC448);//psx:...
}

void C_0074EA48() {
	struct {//0xd0
		//local_33 and above for compiler
		int local_32;
		int local_31;
		struct VECTOR local_30;
		int local_26;
		int local_25;
		int local_24;
		struct MATRIX local_23;
		int local_15;
		int local_14;
		struct SVECTOR local_13;
		int local_11;
		int local_10;
		struct VECTOR local_9;
		struct SVECTOR local_5;
		int local_3;
		int local_2;
		int local_1;
	}lolo;

	lolo.local_26 =
	lolo.local_1 = 0;
	C_007616B3();
	lolo.local_10 = C_00761735();//current transportation mode?
	if(D_00DE6B5C && D_00DFC4B8 <= 0 && C_0075335C()) {//else 0074F734
		lolo.local_14 = C_007186B9();//menu_input:get "current mask"
		if(D_00DFC4B4 != 2 && D_00DFC4B4 != 3 && D_00E045E8 != 3 && (lolo.local_14 & 0xc))
			C_0074D3D1(2);
		if(lolo.local_10 == 5 && (lolo.local_14 & 0x40))
			lolo.local_14 &= ~0xf000;
		if(C_00761769(0x2000) && D_00DFC4B4 == 2 && D_00E045E8 != 2 && (lolo.local_14 & 0x20))
			lolo.local_14 &= ~0x4000;
		if(C_00761844()) {
			lolo.local_3 = D_00DFC480 * 0x3c;
			//goto 0074EB89
		} else {
			switch(lolo.local_10) {
				case 3: lolo.local_3 = D_00DFC480 * 0x78; break;
				case 5: lolo.local_3 = D_00DFC480 * 0x3c; break;
				case 6: lolo.local_3 = D_00DFC480 * 0x2d; break;
				default:
					lolo.local_3 = D_00DFC480 * 0x1e;
			}
		}
		if(
			((lolo.local_14 & 1) && (D_00DFC470 & 1) == 0) ||
			((lolo.local_14 & 2) && (D_00DFC470 & 2) == 0)
		) {
			if(D_00DFC4B4 != 3 && D_00DE6A0C == 0 && D_00E045E8 != 2 && D_00E045E8 != 3) {
				C_0074D3D1(D_00DFC4B4?0:2);
				D_00DF542C = D_00DFC4B4?0xa0:0x78;
			}
		}
		if(C_00761769(0x2000) && D_00DFC4B4 == 2 && D_00E045E8 != 2 && (lolo.local_14 & 0x20))
			lolo.local_14 |= 0x1000;
		D_00DF5430 = -1;
		if(lolo.local_14 & 0x8000) {
			lolo.local_26 = -lolo.local_3;
			D_00DF5430 = -0x400;
		}
		if(lolo.local_14 & 0x2000) {
			lolo.local_26 = lolo.local_3;
			D_00DF5430 = 0x400;
		}
		if(lolo.local_14 & 0x1000) {
			if(D_00DF5430 == -1) {
				lolo.local_1 = -lolo.local_3;
				D_00DF5430 = 0x800;
			} else {
				lolo.local_26 = (lolo.local_26 * 3) >> 2;
				lolo.local_1 = (lolo.local_3 * -3) >> 2;
				D_00DF5430 += D_00DF5430 >> 1;
			}
		}
		if(lolo.local_14 & 0x4000) {
			if(D_00DF5430 == -1) {
				lolo.local_1 = lolo.local_3;
				D_00DF5430 = 0;
			} else {
				lolo.local_26 = (lolo.local_26 * 3) >> 2;
				lolo.local_1 = (lolo.local_3 * 3) >> 2;
				D_00DF5430 -= D_00DF5430 >> 1;
			}
		}
		if(D_00DFC4B4 == 2 || D_00DFC4B4 == 3 || D_00E045E8 == 3) {//else 0074F4FE
			lolo.local_15 = /*lolo.local_34*/(D_00DFC4B4 == 3 && (lolo.local_14 & 0x80));
			if(D_00E045E8 == 3) {//else 0074EDEF
				D_00DFC484 += C_00758B12(lolo.local_14 & 0xf000, /*lolo.local_35*/(lolo.local_14 & 0x20) && (D_00DFC470 & 0x20) == 0);
			} else if(lolo.local_15 == 0) {//else 0074EF6A
				lolo.local_31 = ((lolo.local_14 & 4) != 0) + ((lolo.local_14 & /*lolo.local_36*/((D_00DFC4B4 == 2 && D_00E045E8 != 2 && (lolo.local_14 & 0x4000)?0x2000:0x8000))) != 0);
				if(lolo.local_31)
					D_00DFC484 -= ((D_00DFC480 << 3) * lolo.local_31 * ((lolo.local_14 & 0x5000)?1:2)) >> /*lolo.local_37*/(D_00E045E8 == 2 && (lolo.local_14 & 4) == 0);
				lolo.local_31 = ((lolo.local_14 & 8) != 0) + ((lolo.local_14 & /*lolo.local_38*/((D_00DFC4B4 == 2 && D_00E045E8 != 2 && (lolo.local_14 & 0x4000)?0x8000:0x2000))) != 0);
				if(lolo.local_31)
					D_00DFC484 += ((D_00DFC480 << 3) * lolo.local_31 * ((lolo.local_14 & 0x5000)?1:2)) >> /*lolo.local_39*/(D_00E045E8 == 2 && (lolo.local_14 & 8) == 0);
			}
			if(D_00DFC484 < 0)
				D_00DFC484 += 0x1000;
			else if(D_00DFC484 >= 0x1000)
				D_00DFC484 -= 0x1000;
			lolo.local_2 = 0;
			if(lolo.local_14 & 0x8000)
				lolo.local_2 = 0x80;
			else if(lolo.local_14 & 0x2000)
				lolo.local_2 = -0x80;

			if(D_00DFC4B4 == 3 || D_00E045E8 == 2) {//else 0074F121
				lolo.local_32 = ((lolo.local_14 & (lolo.local_15?0xf000:0x20))?-1:0) & lolo.local_3;
				D_00DE6A18 = /*lolo.local_40*/(D_00E045E8 == 2)?lolo.local_32:(D_00DE6A18 * 3 + lolo.local_32) >> 2;
				if(lolo.local_15) {//else 0074F0FB
					lolo.local_26 = /*lolo.local_41*/(lolo.local_14 & 0x8000)?-D_00DE6A18:(lolo.local_14 & 0x2000)?D_00DE6A18:0;
					lolo.local_1 = /*lolo.local_43*/(lolo.local_14 & 0x1000)?-D_00DE6A18:(lolo.local_14 & 0x4000)?D_00DE6A18:0;
				} else {
					lolo.local_26 = 0;
					lolo.local_1 = -D_00DE6A18;
				}
				if((lolo.local_14 & 0x20) == 0)
					lolo.local_2 = 0;
			} else if(D_00DF5430 != -1) {
				C_00761B83(D_00DF5430 - D_00DFC484);
			}
			lolo.local_13.f_00 = lolo.local_26;
			lolo.local_13.f_02 = 0;
			lolo.local_13.f_04 = lolo.local_1;
			lolo.local_5.f_00 =
			lolo.local_5.f_04 = 0;
			lolo.local_5.f_02 = -D_00DFC484;
			C_006628DE(&lolo.local_5, &lolo.local_23);//psx:xyz_rotate(1)
			lolo.local_9.f_00 =
			lolo.local_9.f_04 =
			lolo.local_9.f_08 = 0;
			C_00663766(&lolo.local_23, &lolo.local_9);//psx:set translate vector?
			C_00663673(&lolo.local_23);//psx:SetRotMatrix?
			C_00663707(&lolo.local_23);//psx:SetTransMatrix?
			C_00662ECC(&lolo.local_13, &lolo.local_30, &lolo.local_11);//psx:RotTrans
			lolo.local_26 = lolo.local_30.f_00;
			lolo.local_1 = lolo.local_30.f_08;
			lolo.local_24 = 0;
			if(D_00DFC4B4 == 3 && lolo.local_15 == 0) {//else 0074F291
				C_00762798(&lolo.local_9);
				if(((lolo.local_14 & 0x1000) && lolo.local_9.f_04 > 0x1f4 && D_00DE6A14 && C_00762136() != 0x1b) || lolo.local_9.f_04 > D_00DF5420) {
					C_00761F22(D_00DFC480 * -0x32);
					lolo.local_24 = 0xa;
				} else if((lolo.local_14 & 0x4000) && lolo.local_9.f_04 < D_00DF5420 - D_00DFC480 * 0x32) {
					C_00761F22(D_00DFC480 * 0x32);
					lolo.local_24 = -0xa;
				}
			}
			if(D_00E045E8 == 2) {//else 0074F30B
				C_00762798(&lolo.local_9);
				if((lolo.local_14 & 0x1000) && lolo.local_9.f_04 > -0x1388 && D_00DE6A14) {
					C_00761F22(D_00DFC480 * -0x1e);
					lolo.local_24 = 0xa;
				}
				if((lolo.local_14 & 0x4000) && lolo.local_9.f_04 < -0xbb8) {
					C_00761F22(D_00DFC480 * 0x1e);
					lolo.local_24 = -0xa;
				}
			}
			if(D_00DFC4B4 == 3) {//else 0074F3F3
				lolo.local_25 = ((/*lolo.local_46*/!(((C_00761F44() == 0 || inline_abs(D_00DE6B70) < 0x10) && lolo.local_2 == 0)) << 1) | (D_00DFC480 == 1)) + 3;
				D_00DE6B70 = (((1 << lolo.local_25) - 1) * D_00DE6B70 + lolo.local_2 + (1 << (lolo.local_25 - 1))) >> lolo.local_25;
				D_00E045E0 = (D_00E045E0 * 3 + lolo.local_24) >> 2;
				C_00762F75(D_00E045E0 + 4, D_00DE6B70 << 2, -D_00DE6B70 << 1);
			}
			if(lolo.local_2 == 0 && /*lolo.local_47*/inline_abs(D_00DE6B70) <= 4)
				D_00DE6B70 = 0;
			if(D_00E045E8 == 3) {
				//goto 0074F4FC
			} else {
				if(D_00DF5430 != -1) {//else 0074F4A9
					D_00DF5430 += 0x800;
					if(D_00DF5430 > 0x800)
						D_00DF5430 -= 0x1000;
					if((lolo.local_14 & 0x4000) == 0)
						D_00DF5430 >>= 1;
					D_00DF5434 = D_00DF5430;
				} else {
					D_00DF5430 = D_00DF5434;
				}
				C_00761B83(0x800 - D_00DFC484 + (/*lolo.local_48*/(D_00DFC4B4 == 2 && D_00E045E8 != 2)?D_00DF5430:0));
			}
		} else {
			D_00DE6B70 >>= 1;
			if(D_00DF5430 != -1)
				C_00761B83(D_00DF5430);
		}
		if(lolo.local_10 == 6) {//else 0074F57E
			if((lolo.local_14 & 0xf000) && (D_00DFC470 & 0xf000) == 0)
				C_0075E6A8(8, 0x20);
			if((lolo.local_14 & 0xf000) == 0 && (D_00DFC470 & 0xf000))
				C_0075E6A8(8, 0);
		}
		if(C_00761769(0x2000) && (lolo.local_14 & 0x40) && (D_00DFC470 & 0x40) == 0) {
			if(D_00E045E8 == 2 && C_00762136() == 3)
				C_0074D6BB();
			else if(C_00762136() == 3)
				C_0074D6F6();
		}
		if(
			(lolo.local_14 & 0x800) && (D_00DFC470 & 0x800) == 0 ||
			(lolo.local_14 & 0x100) && (D_00DFC470 & 0x100) == 0
		) {//else 0074F650
			C_0076831F(/*lolo.local_49*/(D_00E045E8 == 0)?(C_00768343() + 1) % 3:(!C_00768343() * 2));//set map/radar state
		}
		if((lolo.local_14 & 0x10) && (D_00DFC470 & 0x10) == 0 && D_00E045E4 == 1) {//else 0074F6C6
			if(lolo.local_10 == 3) {
				C_007640BC(6);
			} else if(C_00761769(0x47) && C_00762136() != 0xe) {
				C_00755B97(0x10, 1);
				C_0074D438(0, 1);
				D_00E045E4 = 2;
				C_0074C980(0);//set "allowsFrameSkip"?
			}
		}
		if(lolo.local_14 & 0xa00c)
			C_00753BE8();
		D_00DFC470 = lolo.local_14;
		if(C_00762136() == 0xe)
			C_007591C2(&lolo.local_26, &lolo.local_1);
		if(lolo.local_10 == 5)
			C_0075E6CC((lolo.local_26 | lolo.local_1)?0x1ed:-0x1ed);//start/stop SFX?
		C_00762E87(lolo.local_26, lolo.local_1);
		C_0076296E();
	}
	if(D_00DE6B5C == 0 && C_00762136() == 0xe) {
		C_007591C2(&lolo.local_26, &lolo.local_1);
		C_00762E87(lolo.local_26, lolo.local_1);
		C_0076296E();
	}
	if(D_00DFC4B4 != 3)
		D_00DE6B4C = (D_00DE6B4C * 3 + D_00DF542C) >> 2;
	if(D_00DFC474 < D_00DFC484 - 0x800)
		D_00DFC474 += 0x1000;
	else if(D_00DFC474 > D_00DFC484 + 0x800)
		D_00DFC474 -= 0x1000;
	D_00DFC474 = /*lolo.local_51*/(3)?
		/*lolo.local_50*/D_00DFC480 == 1?(D_00DFC474 * 0x1f + D_00DFC484) >> 5:(D_00DFC474 * 0x0f + D_00DFC484) >> 4
	:
		/*lolo.local_52*/D_00DFC480 == 1?(D_00DFC474 * 0x07 + D_00DFC484) >> 3:(D_00DFC474 * 0x03 + D_00DFC484) >> 2
	;
}

void C_0074F87D() {
	D_00DE6B4C = /*local_1*/(D_00E045DC == 0)?0x78 - ((D_00DE6A40 * 0x1e) >> 8):0xa0 - ((D_00DE6A40 * 0x46) >> 8);
	some_world_obj.D_009699E0 = 0x190 - ((D_00DE6A40 * 0xc8) >> 8);
	D_00DFC478 = 0x2710 - ((D_00DE6A40 * 0x1770) >> 8);
	D_00E045D8 = 0x1388 - ((D_00DE6A40 * 0x9C4) >> 8);
}

int C_0074F916() {
	struct {
		int local_11;
		struct VECTOR local_10;
		int local_6;
		struct VECTOR local_5;
		int local_1;
	}lolo;

	if(D_00DE6A08) {//else 0074FAAE
		if(D_00DFC49C == 0) {//else 0074F988
			if(D_00DE6A08 > 0) {
				C_0074D3D1(3);
				D_00DF5420 = (C_00761735() != 3)?0x7d0:0xfa0;
			}
			D_00DE6B48 = D_00DFC484;
			if(D_00DE6B48 >= 0x800)
				D_00DE6B48 -= 0x1000;
		}
		D_00DFC49C += D_00DFC480 * ((D_00DE6A40 < 0x80) * 2 - 1);
		if(D_00DFC49C) {//else 0074FA80
			D_00DE6A40 += D_00DFC49C;
			if(D_00DE6A40 < 0)
				D_00DE6A40 = 0;
			else if(D_00DE6A40 > 0x100)
				D_00DE6A40 = 0x100;
			C_0074F87D();
			C_00762798(&lolo.local_5);
			C_00762802(&lolo.local_10);
			lolo.local_6 = C_0076201E();
			C_0076271B(lolo.local_6 + ((((/*lolo.local_12*/(D_00DE6A08 > 0)?D_00DF5420:lolo.local_10.f_04) - lolo.local_6) * D_00DE6A40) >> 8));
			if(D_00E045DC == 0 || D_00E045DC == 1)
				D_00DFC484 = (D_00DE6A40 * D_00DE6B48) >> 8;
			//goto 0074FAAE
		} else {
			if(D_00DE6A08 < 0) {
				C_0074D3D1(D_00E045DC);
				C_0074D438(0, 2);
			}
			D_00DE6A08 = 0;
		}
	}
	lolo.local_11 = /*lolo.local_13*/(D_00DE6A08 < 0 && D_00E045DC == 0)?0:D_00DFC4B4;
	lolo.local_1 = /*lolo.local_14*/D_00DE6A0C?D_00DE6A0C:D_00969A58[lolo.local_11] + D_00DF5438;
	D_00DFC468 = /*lolo.local_15*/(D_00DFC480 == 1)?(D_00DFC468 * 7 + lolo.local_1) >> 3:(D_00DFC468 * 3 + lolo.local_1) >> 2;
	lolo.local_1 = /*lolo.local_16*/D_00DFC47C?D_00DFC47C:D_00969A68[lolo.local_11];
	D_00DFC478 = /*lolo.local_17*/(D_00DFC480 == 1)?(D_00DFC478 * 7 + lolo.local_1) >> 3:(D_00DFC478 * 3 + lolo.local_1) >> 2;
	return (D_00DE6A40 * ((D_00DE6A04 >> 5) + 0x6d6) + (0x100 - D_00DE6A40) * D_00DFC468) >> 8;
}

void C_0074FBCA() {
	if(D_00CC0888 == 1) {
		C_006CC3E8();
		C_006CBD1E();
		D_00CC0888 = 0;
	}
}

void C_0074FE84(void);//<empty>

void C_0074FBEC() {
	struct VECTOR bp_10;

	switch(D_00E045E4) {
		case 0:
			if(D_00DFC47C) {//else 0074FC89
				D_00DFC47C += 0x50;
				if(D_00DFC47C >= (D_00969A68[D_00DFC4B4] >> 1) && D_00E045E8 != 2 && D_00E045E8 != 3)
					D_00DFC4AC = 1;
				if(D_00DFC47C >= D_00969A68[D_00DFC4B4]) {//else 0074FC89
					D_00DFC47C = 0;
					if(D_00DE6A0C == 0)
						D_00E045E4 = 1;
				}
			}
			if(D_00DE6A0C) {//else 0074FCEE
				D_00DE6A0C += 3;
				if(D_00DE6A0C >= D_00969A58[D_00DFC4B4]) {//else 0074FCEE
					D_00DE6A0C = 0;
					if(D_00E045E8 != 2 && D_00E045E8 != 3)
						D_00DFC4AC = 1;
					if(D_00DFC47C == 0)
						D_00E045E4 = 1;
				}
			}
		break;
		case 2:
			if(C_00755C2F()) {//else 0074FDB2
				if(D_00E045F0) {
					D_00E045E4 = 3;
					D_00E045F0 = 0;
				} else if(D_00E045EC == 0) {//else 0074FD63
					C_00767473(C_00762162());//save location name?
					C_00766ECB();
					C_007538C9(3);
					C_0074FBCA();
					C_0074FE84();//<empty>
					D_00E045EC = 1;
					C_0075551A();//render "extra layers"?
				} else {
					C_0075395E(3);
					C_0074D438(1, 1);
					C_0076741C();
					C_0074E48A();
					C_0074E505();
					C_00755B70(0x10, 1);
					D_00E045E4 = 1;
					D_00E045EC = 0;
					C_0074C980(1);//set "allowsFrameSkip"?
				}
			}
		break;
		case 4: case 5:
			C_00762798(&bp_10);
			C_00762702(bp_10.f_04 + D_00DFC490);
			D_00DFC490 += D_00DFC490 >> 2;
			if(C_00755C2F())
				D_00E045E4 = (D_00E045E4 != 4) + 6;
		break;
		case 3:
			D_00E045E4 = 9;
		break;
		//case 1:
		default:
			if(D_00E045E4 < 0) {
				D_00E045E4 ++;
				if(D_00E045E4 == 0) {
					if(D_00E045E8 != 2 && D_00E045E8 != 3)
						D_00DFC4AC = 1;
					D_00E045E4 = 1;
					C_00755B70(0x10, 1);
				}
			}
	}//end switch
}

//<empty>
void C_0074FE84() {
}

void C_0074FE89() {
	if(D_00E045E4 == 1 && D_00E045E8 != 2) {
		D_00DE6B6C = ((D_00DE6B6C * 7) + (D_00E37520 << 8)) >> 3;
		D_00DE6B58 = (D_00DE6B6C > 0x80);
		D_00DE6B64 = /*local_1*/D_00DE6B58?D_00DE6B64 + 1:0;
		if(D_00DF5440 != D_00DE6B58) {
			D_00DFC4BC = 0;
			D_00DFC4A4 = 0xF;
		}
		if(C_00761F77() || D_00DE6B64 >= 0xf) {
			if((D_00DFC4A4 --) < 0)
				D_00DFC4BC = 1;
		}
		if(D_00DFC4BC) {//else 0074FF98
			if(D_00DE6B58) {//else 0074FF82
				if(D_00DF5438 > -0x15E)
					D_00DF5438 -= 5;
			} else if(D_00DF5438 < 0) {
				D_00DF5438 += 5;
			}
		}
		D_00DF5440 = D_00DE6B58;
	}
}

int __0074FFA8() {
	return D_00E045E4;
}
