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
struct t_wm_local_8_ttt {
	int f_00;
	unsigned short f_04;
	char __06[2];
};

//world map coordinate related
struct t_wm_local_8_rrr {
	int f_00;
	int f_04;
};

struct t_wm_local_4 {
	unsigned short f_00;
	unsigned short f_02;
};
////////////////////////////////////////
void *D_00E399B8;
//00E399BC
unsigned char D_00E399C0[0x40];
struct t_local_unknown_c0 *D_00E39A00;
//00E39A04
struct VECTOR D_00E39A08;
struct t_local_unknown_c0 D_00E39A18;
struct t_local_unknown_c0 *D_00E39AD8;
struct t_wm_local_8_ttt *D_00E39ADC;
struct t_local_unknown_c0 D_00E39AE0;
int D_00E39BA0[2];
int D_00E39BA8[2];
int D_00E39BB0;
short D_00E39BB4;
short D_00E39BB8;
short D_00E39BBC;
int D_00E39BC0;
//00E39BC4
struct t_local_unknown_c0 D_00E39BC8[0x10];
struct t_wm_b8 *D_00E3A7C8;
struct t_local_unknown_c0 *D_00E3A7CC;
struct t_local_unknown_c0 *D_00E3A7D0;
struct t_local_unknown_c0 *D_00E3A7D4;
struct t_wm_local_8_rrr *D_00E3A7D8;
int D_00E3A7DC;
unsigned char *D_00E3A7E0[4];
struct t_wm_local_8_ttt D_00E3A7F0[4];
unsigned short *D_00E3A810;
//00E3A814
struct VECTOR D_00E3A818[3];
int D_00E3A848;
int D_00E3A84C;
int D_00E3A850;
int D_00E3A854;
int D_00E3A858;
short D_00E3A85C;
////////////////////////////////////////
void C_00761134(struct t_local_unknown_c0 *);
void C_00762F75(int, int, int);

void C_00760FB0(struct t_wm_local_8_rrr *bp08) {
	int i;

	for(i = 0; i < 0xf; i ++)
		D_00E39BC8[i].pNext = &(D_00E39BC8[i + 1]);
	D_00E39BC8[i].pNext = 0;
	D_00E3A7D4 = D_00E39BC8;
	D_00E39A00 =
	D_00E39AD8 =
	D_00E3A7D0 = 0;
	C_00761134(&D_00E39A18);
	C_00761134(&D_00E39AE0);
	D_00E39AE0.f_50 = 9;
	D_00E39A18.pNext = 0;
	D_00E39AE0.pNext = 0;
	C_00762F75(0, 0, 0);
	D_00E3A7D8 = bp08;
	D_00E3A848 =
	D_00E3A84C = 0;
	D_00E3A850 =
	D_00E3A854 =
	D_00E39BB0 = 0;
}

struct t_local_unknown_c0 *C_007610B3() {
	struct t_local_unknown_c0 *local_1;

	local_1 = D_00E3A7D4;
	if(local_1 == 0)
		C_0074C9A0(0x32);//<empty>:some error management?
	D_00E3A7D4 = local_1->pNext;
	local_1->pNext = D_00E39A00;
	D_00E39A00 =
	D_00E39AD8 = local_1;
	C_00761134(local_1);

	return local_1;
}

void C_0076110B() {
	struct t_local_unknown_c0 *local_1;

	for(local_1 = D_00E39A00; local_1; local_1 = local_1->pNext)
		local_1->f_5e = 0;
}

//clean struct?
void C_00761134(struct t_local_unknown_c0 *bp08) {
	struct {
		unsigned *local_2;
		unsigned *local_1;
	}lolo;

	bp08->f_5e = 0;
	lolo.local_2 = (unsigned *)(bp08 + 1);
	lolo.local_1 = (unsigned *)bp08 + 1;
	while(lolo.local_1 < lolo.local_2) {
		*lolo.local_1 = 0;
		lolo.local_1 ++;
	}
}

int C_00761176() {
	struct t_local_unknown_c0 *local_1;

	for(local_1 = D_00E39A00; local_1 && local_1->f_50 < 0x20; local_1 = local_1->pNext);

	return local_1 != 0;
}

void C_007611FF(struct t_local_unknown_c0 *);

void C_007611AE() {
	struct t_local_unknown_c0 *local_1;

	if(D_00E3A7D0 && D_00E39AD8 && D_00E39AD8->f_08 == 0) {
		local_1 = D_00E3A7D0;
		C_007611FF(local_1);
		D_00E39AD8->f_08 = local_1;
		D_00E3A7D0 = D_00E39AD8;
	}
}

void C_007611FF(struct t_local_unknown_c0 *bp08) {
	struct {
		struct t_wm_b8 *local_3;
		struct t_local_unknown_c0 *local_2;
		struct t_local_unknown_c0 *local_1;
	}lolo;

	if(bp08 == D_00E39AD8)
		D_00E39AD8 = 0;
	if(bp08 == D_00E3A7D0)
		D_00E3A7D0 = 0;
	for(lolo.local_1 = D_00E39A00; lolo.local_1; lolo.local_1 = lolo.local_1->pNext) {
		if(lolo.local_1->f_04 == bp08)
			lolo.local_1->f_04 = 0;
		if(lolo.local_1->f_08 == bp08)
			lolo.local_1->f_08 = 0;
	}
	for(lolo.local_2 = 0, lolo.local_1 = D_00E39A00; lolo.local_1 && lolo.local_1 != bp08; lolo.local_2 = lolo.local_1, lolo.local_1 = lolo.local_1->pNext);
	if(lolo.local_1) {
		if(lolo.local_2)
			lolo.local_2->pNext = lolo.local_1->pNext;
		else
			D_00E39A00 = lolo.local_1->pNext;
	}
	if(lolo.local_1)
		lolo.local_1->pNext = 0;
	lolo.local_3 = C_00768A37(bp08->f_50);
	if(lolo.local_3 && lolo.local_3->f_01 == 0xe) {
		C_0075E024(lolo.local_3);
		bp08->f_5e = 0;
	}
}

void C_00761407(struct t_local_unknown_c0 *);

void C_00761313() {
	struct t_local_unknown_c0 *local_1;

	if(D_00E3A7D0 && D_00E3A7D0->f_08) {
		local_1 = D_00E3A7D0->f_08;
		C_00761407(local_1);
		local_1->f_04 = D_00E3A7D0;
		local_1->f_0c = D_00E3A7D0->f_0c;
		local_1->f_1c = D_00E3A7D0->f_1c;
		local_1->f_40 = D_00E3A7D0->f_40;
		local_1->f_4c = D_00E3A7D0->f_4c;
		local_1->f_3c = D_00E3A7D0->f_3c;
		local_1->f_3e = D_00E3A7D0->f_3e;
		local_1->f_51 |= 2;
		D_00E3A7D0->f_08 = 0;
		D_00E3A7D0 = local_1;
	}
}

void C_00761407(struct t_local_unknown_c0 *bp08) {
	if(bp08 && bp08->pNext == 0) {
		bp08->pNext = D_00E39A00;
		D_00E39A00 = bp08;
	}
}

void C_0076142D() {
	struct t_local_unknown_c0 *local_1;

	if(D_00E39AD8 && D_00E39AD8->f_08) {
		local_1 = D_00E39AD8->f_08;
		C_00761407(local_1);
		local_1->f_04 = D_00E39AD8;
		local_1->f_0c = D_00E39AD8->f_0c;
		local_1->f_1c = D_00E39AD8->f_1c;
		local_1->f_40 = D_00E39AD8->f_40;
		local_1->f_4c = D_00E39AD8->f_4c;
		local_1->f_3c = D_00E39AD8->f_3c;
		local_1->f_3e = D_00E39AD8->f_3e;
		local_1->f_51 |= 2;
		D_00E39AD8->f_08 = 0;
		D_00E39AD8 = local_1;
	}
}

int C_00761521() {
	return D_00E39AD8?D_00E39AD8->f_08 != 0:0;
}

void C_0076156B(struct t_local_unknown_c0 *);

void C_0076154F() {
	if(D_00E3A7D0)
		C_0076156B(D_00E3A7D0);
}

void C_0076156B(struct t_local_unknown_c0 *bp08) {
	C_007611FF(bp08);
	bp08->pNext = D_00E3A7D4;
	D_00E3A7D4 = bp08;
	D_00E3A7C8 = C_00768A37(bp08->f_50);
	if(D_00E3A7C8)
		D_00E3A7C8->f_24 = 0;
}

void C_007615BA() {
	if(D_00E39AD8)
		C_0076156B(D_00E39AD8);
}

void C_007615D6() {
	if(D_00E3A7D0 && D_00E3A7D0->f_08) {
		C_0076156B(D_00E3A7D0->f_08);
		D_00E3A7D0->f_08 = 0;
	}
}

void C_0076160D() {
	if(D_00E39AD8 && D_00E39AD8->f_08) {
		C_0076156B(D_00E39AD8->f_08);
		D_00E39AD8->f_08 = 0;
	}
}

void C_00761644(short bp08, short bp0c) {
	struct {
		struct t_wm_local_08 *local_2;
		struct t_local_unknown_c0 *local_1;
	}lolo;

	for(lolo.local_1 = D_00E39A00; lolo.local_1; lolo.local_1 = lolo.local_1->pNext) {
		for(lolo.local_2 = &(lolo.local_1->f_60[0]); lolo.local_2 < &(lolo.local_1->f_60[6]); lolo.local_2 ++) {
			if(lolo.local_2->f_04 == bp08 && lolo.local_2->f_06 == bp0c)
				lolo.local_2->f_00 = 0;
		}//end for
	}//end for
}

void C_007616B3() {
	if(D_00E3A7D0)
		D_00E39AD8 = D_00E3A7D0;
}

void C_007616CB() {
	if(D_00E39AD8)
		D_00E3A7D0 = D_00E39AD8;
}

struct t_wm_local_08 *C_007616E3() {
	return D_00E3A7D0?D_00E3A7D0->f_60:0;
}

int C_0076170B() {
	return D_00E39AD8?D_00E39AD8->f_50:0;
}

//current transportation mode
int C_00761735() {
	return D_00E3A7D0?D_00E3A7D0->f_50:0;
}

struct t_local_unknown_c0 *C_0076175F() {
	return D_00E39AD8;
}

int C_00761769(int bp08) {
	return (D_00E3A7D0 && D_00E3A7D0->f_50 < 0x20)?((bp08 & (1 << D_00E3A7D0->f_50)) != 0):0;
}

int __007617B7(int bp08) {
	return (D_00E39AD8 && D_00E39AD8->f_50 < 0x20)?((bp08 & (1 << D_00E39AD8->f_50)) != 0):0;
}

int C_00761805(int bp08, unsigned char bp0c) {
	return bp0c < 0x20?((bp08 & (1 << bp0c)) != 0):0;
}

int C_00761844() {
	return D_00E3A7D0?
		(D_00E3A7D0->f_50 != 4 && D_00E3A7D0->f_50 != 0x13 && D_00E3A7D0->f_50 != 0x29 && D_00E3A7D0->f_50 != 0x2a)?0:1
		:0
	;
}

int C_007618B7() {
	return D_00E39AD8?
		(D_00E39AD8->f_50 != 4 && D_00E39AD8->f_50 != 0x13 && D_00E39AD8->f_50 != 0x29 && D_00E39AD8->f_50 != 0x2a)?0:1
		:0
	;
}

int C_0076192A(unsigned char bp08) {
	return (bp08 != 4 && bp08 != 0x13 && bp08 != 0x29 && bp08 != 0x2a)?0:1;
}

void C_0076616A(struct t_local_unknown_c0 *);//load object coordinates?

void C_0076197B(int bp08) {
	short bp_08[4];

	if(D_00E39AD8) {
		D_00E39AD8->f_50 = bp08;
		switch(bp08) {
			case 3:
				if(C_00768C59() == 0)
					D_00E39AD8->f_08 = &D_00E39AE0;
				bp_08[0] = 0x18;
				bp_08[1] = 0x10;
				bp_08[2] = 0xe;
				bp_08[3] = 0x1f;
				D_00E39AD8->f_90.f_28 = D_00E2C400;
			break;
			case 0xa:
				bp_08[0]  = 0x10;
				bp_08[1]  = 0;
				bp_08[2]  = 0xf;
				bp_08[3]  = 0xf;
				D_00E39AD8->f_58 = 0x80;
				D_00E39AD8->f_90.f_28 = D_00E2C3E4;
			break;
			case 0x1c:
			break;
			case 0xb:
				bp_08[0]  = 0;
				bp_08[1]  = 0;
				bp_08[2]  = 0x17;
				bp_08[3]  = 0x2f;
				D_00E39AD8->f_58 = 0x20;
				D_00E39AD8->f_90.f_28 = D_00E2C400;
			break;
			case 4:
				C_0075E4D6(4, 0);
				//no break
			default:
				bp_08[0]  = 0x18;
				bp_08[1]  = 0;
				bp_08[2]  = 0xf;
				bp_08[3]  = 0xf;
				D_00E39AD8->f_58 = 0x20;
				D_00E39AD8->f_90.f_28 = D_00E2C400;
			case 5:
			case 0xd:
			break;
		}//end switch
		C_0075D482(&(D_00E39AD8->f_90), bp_08);
		C_0076616A(D_00E39AD8);//load object coordinates?
	}
}

void C_00761B19(short bp08) {
	if(D_00E39AD8) {
		D_00E39AD8->f_40 = bp08;
		D_00E39AD8->f_4c = bp08;
		D_00E39AD8->f_3e = 0;
	}
}

void __00761B4E(short bp08) {
	if(D_00E3A7D0) {
		D_00E3A7D0->f_40 = bp08;
		D_00E3A7D0->f_4c = bp08;
		D_00E3A7D0->f_3e = 0;
	}
}

void C_00761B83(short bp08) {
	if(D_00E39AD8) {
		D_00E39AD8->f_40 = bp08;
		D_00E39AD8->f_4c = bp08;
	}
}

void C_00761BAC(short bp08) {
	if(D_00E39AD8) {
		D_00E39AD8->f_40 = bp08;
		D_00E39AD8->f_3c = bp08;
		D_00E39AD8->f_4c = bp08;
		D_00E39AD8->f_3e = 0;
	}
}

void C_00761C07(struct t_local_unknown_c0 *, short);

void C_00761BEE(short bp08) {
	C_00761C07(D_00E39AD8, bp08);
}

void C_00761C07(struct t_local_unknown_c0 *bp08, short bp0c) {
	struct {
		short local_3; char _ocal_3[2];
		short local_2; char _ocal_2[2];
		short local_1; char _ocal_1[2];
	}lolo;

	if(bp08) {
		if(bp0c < 0)
			bp0c += 0x1000;
		lolo.local_1 = inline_abs(bp08->f_3c - bp0c);
		lolo.local_2 = inline_abs(bp08->f_3c - bp0c + 0x1000);
		lolo.local_3 = inline_abs(bp08->f_3c - bp0c - 0x1000);
		if(lolo.local_1 > lolo.local_2) {//else 00761D3C
			if(lolo.local_2 > lolo.local_3)
				bp0c += 0x1000;
			else
				bp0c -= 0x1000;
		} else {
			if(lolo.local_1 > lolo.local_3)
				bp0c += 0x1000;
		}
		bp08->f_3c = /*lolo.local_7*/(D_00DFC480 == 1)?(bp08->f_3c * 7 + bp0c) >> 3:(bp08->f_3c * 3 + bp0c) >> 2;
		if(bp08->f_3c < 0)
			bp08->f_3c += 0x1000;
		else if(bp08->f_3c >= 0x1000)
			bp08->f_3c -= 0x1000;
	}
}

void __00761DDC(short bp08) {
	C_00761C07(D_00E3A7D0, bp08);
}

void C_00761DF5(short bp08) {
	if(D_00E39AD8) {
		D_00E39AD8->f_3e = (D_00DFC480 == 1)?
			(D_00E39AD8->f_51 & 1)?(D_00E39AD8->f_3e * 0xf + bp08) >> 4:(D_00E39AD8->f_3e * 3 + bp08) >> 2:
			(D_00E39AD8->f_51 & 1)?(D_00E39AD8->f_3e * 7 + bp08) >> 3:(D_00E39AD8->f_3e + bp08) >> 1
		;
	}
}

short C_00761EB6() {
	return D_00E39AD8?D_00E39AD8->f_3c + D_00E39AD8->f_3e:0;
}

short C_00761EEC() {
	return D_00E3A7D0?D_00E3A7D0->f_3c + D_00E3A7D0->f_3e:0;
}

void C_00761F22(int bp08) {
	if(D_00E39AD8)
		D_00E39AD8->f_0c.f_04 += bp08;
}

int C_00761F44() {
	return D_00E39AD8?(D_00E39AD8->f_51 & 1) != 0:0;
}

int C_00761F77() {
	return D_00E3A7D0?(D_00E3A7D0->f_51 & 1) != 0:0;
}

void C_00761FAA(int bp08) {
	if(D_00E3A7D0) {
		if(bp08)
			D_00E3A7D0->f_51 |= 0x80;
		else
			D_00E3A7D0->f_51 &= ~0x80;
	}
}

int C_00761FE8() {
	return 	D_00E3A7D0?(D_00E3A7D0->f_51 & 0x80) != 0:0;
}


int C_0076201E() {
	return D_00E3A7D0?D_00E3A7D0->f_42:0;
}

int C_00762047(int bp08) {
	struct t_local_unknown_c0 *local_1;

	for(local_1 = D_00E39A00; local_1 && local_1->f_50 != bp08; local_1 = local_1->pNext);
	if(local_1)
		D_00E39AD8 = local_1;

	return local_1 != 0;
}

void __0076208E() {
	if(D_00E3A7D0 && D_00E3A7D0->f_04)
		D_00E39AD8 = D_00E3A7D0->f_04;
}

int C_007620B6() {
	return (D_00E3A7D0 && D_00E39AD8 && D_00E3A7D0 != D_00E39AD8 && (D_00E39AD8->f_51 & 0x10) == 0);
}

void C_00762102(int bp08) {
	if(D_00E3A7D0)
		D_00E3A7D0->f_50 = bp08;
}

void C_0076211B(int bp08) {
	if(D_00E3A7D0)
		D_00E3A7D0->f_4a = bp08;
}

int C_00762136() {
	return D_00E3A7D0?D_00E3A7D0->f_4a & 0x1f:0;
}

int C_00762162() {
	return D_00E3A7D0?(D_00E3A7D0->f_4a >> 9) & 0x1f:0;
}

int C_00762191() {
	return D_00E3A7D0?(D_00E3A7D0->f_4a >> 0xf) & 1:0;
}

int C_007621C0() {
	return D_00E3A7D0?(D_00E3A7D0->f_4a >> 5) & 7:0;
}

void C_00762207(struct t_local_unknown_c0 *, struct VECTOR *);

void C_007621EF(struct VECTOR *bp08) {
	C_00762207(D_00E39AD8, bp08);
}

int C_007622E5(int, unsigned char);

void C_00762207(struct t_local_unknown_c0 *bp08, struct VECTOR *bp0c) {
	if(bp0c && bp08) {
		C_00750202(bp0c);
		if(bp08->f_51 & 0x80) {
			bp08->f_0c.f_00 = bp0c->f_00;
			bp08->f_0c.f_08 = bp0c->f_08;
		} else {
			bp08->f_0c = *bp0c;
			bp08->f_0c.f_04 += C_007622E5(bp08->f_4a, bp08->f_50);
		}
		bp08->f_42 = bp0c->f_04;
		if(bp08->f_0c.f_00 != bp08->f_1c.f_00 || bp08->f_0c.f_08 != bp08->f_1c.f_08)
			bp08->f_51 |= 1;
		else
			bp08->f_51 &= ~1;
	}
}

int C_007622E5(int bp08, unsigned char bp0c) {
	bp08 &= 0x1f;
	switch(bp0c) {
		case 8:
			return -0xf;
		case 0xd:
			return -0xf0;
		case 0x19:
			return 0;
		case 0x13:
			if((bp08 >= 3 && bp08 <= 6) || bp08 == 0x1a) {//else 007623F7
				if(D_00E3A7D0->f_51 & 1) {//else 0076239D
					if(D_00E39BB0 < 0)
						D_00E39BB0 = min(0, D_00E39BB0 + 0x14);
				} else {
					int bp_04 = (bp08 != 4 && bp08 != 6)?-0xfa:-0x32;
					if(D_00E39BB0 > bp_04)
						D_00E39BB0 -= 0xa;
					else if(D_00E39BB0 < bp_04 - 0x14)
						D_00E39BB0 = bp_04;
				}
				return D_00E39BB0;
			}
			D_00E39BB0 = 0;
	}//end switch

	return (bp08 != 1 && bp08 != 0x19)?(bp08 != 4 && bp08 != 7)?0:-0x40:-0xc0;
}

void C_00762465(struct VECTOR *bp08) {
	C_00762207(D_00E3A7D0, bp08);
}

void C_0076247D(struct VECTOR *bp08) {
	C_00762207(D_00E3A7D0, bp08);
	if(D_00E3A7D0)
		D_00E3A7D0->f_1c = D_00E3A7D0->f_0c;
}

void C_007624C5(struct VECTOR *bp08) {
	int local_1;

	local_1 = C_00762136();
	C_00762207(D_00E3A7D0, bp08);
	if(local_1 == 1 || local_1 == 0x19)
		D_00E3A854 = 0x1e;
	else if(local_1 == 2 || local_1 == 0xc)
		D_00E3A854 = 0;
	if((D_00E3A7D0->f_51 & 0x80) == 0 && D_00E3A854) {//else 007626EA
		D_00E3A854 -= (D_00E3A7D0->f_51 & 1) != 0;
		if(D_00E3A850) {//else 00762680
			if(D_00E3A7D0->f_0c.f_04 > D_00E3A7D0->f_1c.f_04 ^ D_00E3A850 > 0) {
				D_00E3A850 = 0;
				D_00E3A7D0->f_0c.f_04 = D_00E3A7D0->f_1c.f_04;
				//goto 0076267E
			} else if(D_00E3A7D0->f_51 & 1) {//else 0076266C
				if(D_00E3A7D0->f_0c.f_04 > D_00E3A7D0->f_1c.f_04) {//else 00762622
					if(D_00E3A7D0->f_0c.f_04 - D_00E3A7D0->f_1c.f_04 > D_00E3A850) {//else 00762616
						D_00E3A7D0->f_0c.f_04 = D_00E3A7D0->f_1c.f_04 + D_00E3A850;
						D_00E3A850 <<= 1;
					} else {
						D_00E3A850 = 0;
					}
					//goto 0076266A
				} else {
					if(D_00E3A7D0->f_0c.f_04 - D_00E3A7D0->f_1c.f_04 < D_00E3A850) {//else 00762660
						D_00E3A7D0->f_0c.f_04 = D_00E3A7D0->f_1c.f_04 + D_00E3A850;
						D_00E3A850 <<= 1;
					} else {
						D_00E3A850 = 0;
					}
				}
				//0076266A	goto 0076267E
			} else {
				D_00E3A7D0->f_0c.f_04 = D_00E3A7D0->f_1c.f_04;
			}
			//0076267E	goto 007626E8
		} else {
			if(D_00E3A7D0->f_0c.f_04 - D_00E3A7D0->f_1c.f_04 < -0x32) {//else 007626B5
				D_00E3A7D0->f_0c.f_04 = D_00E3A7D0->f_1c.f_04;
				D_00E3A850 = -1;
				//goto 007626E8
			} else if(D_00E3A7D0->f_0c.f_04 - D_00E3A7D0->f_1c.f_04 > 0x32) {//else 007626E8
				D_00E3A7D0->f_0c.f_04 = D_00E3A7D0->f_1c.f_04;
				D_00E3A850 = 1;
			}
		}
		//007626E8	goto 007626FE
	} else {
		D_00E3A850 = 0;
		D_00E3A854 = 0;
	}
}

void C_00762702(int bp08) {
	if(D_00E3A7D0)
		D_00E3A7D0->f_0c.f_04 = bp08;
}

void C_0076271B(int bp08) {
	if(D_00E3A7D0) {
		D_00E3A7D0->f_0c.f_04 = bp08;
		D_00E3A7D0->f_51 |= 4;
	}
}

void __00762748(int bp08) {
	if(D_00E3A7D0)
		D_00E3A7D0->f_4e = bp08;
}

void C_00762763(struct VECTOR *bp08) {
	if(bp08 && D_00E39AD8)
		*bp08 = D_00E39AD8->f_0c;
}

void C_00762798(struct VECTOR *bp08) {
	if(bp08 && D_00E3A7D0) {
		*bp08 = D_00E3A7D0->f_0c;
	}
}

void C_007627CD(struct VECTOR *bp08) {
	if(bp08 && D_00E39AD8)
		*bp08 = D_00E39AD8->f_1c;
}

void C_00762802(struct VECTOR *bp08) {
	if(bp08 && D_00E3A7D0)
		*bp08 = D_00E3A7D0->f_1c;
}

void C_00762837() {
	if(D_00E39AD8) {
		if(D_00E39AD8->f_51 & 4) {
			D_00E39AD8->f_0c.f_00 = D_00E39AD8->f_1c.f_00;
			D_00E39AD8->f_0c.f_08 = D_00E39AD8->f_1c.f_08;
		} else {
			D_00E39AD8->f_0c = D_00E39AD8->f_1c;
		}
		D_00E39AD8->f_51 &= ~1;
	}
}

void C_007628B5() {
	if(D_00E3A7D0) {
		if(D_00E3A7D0->f_51 & 4) {
			D_00E3A7D0->f_0c.f_00 = D_00E3A7D0->f_1c.f_00;
			D_00E3A7D0->f_0c.f_08 = D_00E3A7D0->f_1c.f_08;
		} else {
			D_00E3A7D0->f_0c = D_00E3A7D0->f_1c;
		}
		D_00E3A7D0->f_51 &= ~1;
	}
}

void C_00762933() {
	if(D_00E3A7D0)
		D_00E3A7D0->f_51 &= ~2;
}

void C_00762955(int bp08) {
	if(D_00E39AD8)
		D_00E39AD8->f_5d = bp08;
}

struct t_local_unknown_c0 *C_00762993(void);

struct t_local_unknown_c0 *C_0076296E() {
	struct t_local_unknown_c0 *local_1 = 0;
	local_1 = C_00762993();
	if(local_1)
		C_00762837();

	return local_1;
}

int C_00762A21(struct t_local_unknown_c0 *, struct t_local_unknown_c0 *);

struct t_local_unknown_c0 *C_00762993() {
	int local_2 = 0;
	struct t_local_unknown_c0 *local_1 = 0;
	if(D_00E39AD8) {//else 00762A10
		if(D_00E39AD8->f_50 != 0xd || C_0074D330()) {//else 00762A10
			for(local_1 = D_00E39A00; local_1 && !(local_2 = C_00762A21(D_00E39AD8, local_1)); local_1 = local_1->pNext);
			if(local_1)
				D_00E39AD8->f_04 = local_1;
		}
	}

	return (local_2 < 2)?local_1:0;
}

unsigned char D_0096DDB0[][8] = {
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x18,0x3C,0x3C,0x18,0x00,0x00},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x18,0x3C,0x7E,0x7E,0x3C,0x18,0x00},
	{0x00,0x00,0x18,0x3C,0x3C,0x18,0x00,0x00},
	{0x00,0x00,0x18,0x3C,0x3C,0x18,0x00,0x00},
	{0x18,0x3C,0x7E,0xFF,0xFF,0x7E,0x3C,0x18},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x3C,0x7E,0xFF,0xFF,0xFF,0xFF,0x7E,0x3C},
	{0x3C,0x7E,0xFF,0xFF,0xFF,0xFF,0x7E,0x3C},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x18,0x3C,0x7E,0x7E,0x3C,0x18,0x00},
	{0x18,0x3C,0x7E,0xFF,0xFF,0x7E,0x3C,0x18},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
	{0x00,0x00,0x18,0x3C,0x3C,0x18,0x00,0x00}
};

int C_00762A21(struct t_local_unknown_c0 *bp08, struct t_local_unknown_c0 *bp0c) {
	struct {//x2c
		int local_4;
		int local_3;
		int local_2;
		int local_1;
	}lolo;

	lolo.local_1 = 0;
	if(
		bp08 && bp0c && bp08 != bp0c &&
		(bp08->f_51 & 0x80) == 0 && (bp0c->f_51 & 0x80) == 0 && 
		bp08->f_50 < 0x1a && bp0c->f_50 < 0x1a &&
		bp0c->f_50 != 0x15 && bp0c->f_50 != 0x16 && bp0c->f_50 != 0x17
	) {
		lolo.local_3 = bp0c->f_0c.f_00 - bp08->f_0c.f_00;
		if(lolo.local_3 > 0x24000)
			lolo.local_3 -= 0x48000;
		else if(lolo.local_3 < -0x24000)
			lolo.local_3 += 0x48000;
		lolo.local_4 = bp0c->f_0c.f_08 - bp08->f_0c.f_08;
		if(lolo.local_4 > 0x1c000)
			lolo.local_4 -= 0x38000;
		else if(lolo.local_4 < -0x1c000)
			lolo.local_4 += 0x38000;
		if(/*lolo.local_5*/inline_abs(lolo.local_3) < 0x400 && /*lolo.local_6*/inline_abs(lolo.local_4) < 0x400) {
			lolo.local_2 = inline_abs(lolo.local_3) + inline_abs(lolo.local_4);
			lolo.local_3 = (lolo.local_3 + 0x400) >> 8;
			lolo.local_4 = (lolo.local_4 + 0x400) >> 8;
			if(lolo.local_3 >= 0 && lolo.local_3 < 8 && lolo.local_4 >= 0 && lolo.local_4 < 8) {
				lolo.local_1 = /*lolo.local_9*/((D_0096DDB0[bp08->f_50][lolo.local_4] >> lolo.local_3) & 1) == 0 && ((D_0096DDB0[bp0c->f_50][7 - lolo.local_4] >> (7 - lolo.local_3)) & 1) == 0?0:1;
				if(lolo.local_1) {
					lolo.local_3 = bp0c->f_0c.f_00 - bp08->f_1c.f_00;
					if(lolo.local_3 > 0x24000)
						lolo.local_3 -= 0x48000;
					else if(lolo.local_3 < -0x24000)
						lolo.local_3 += 0x48000;
					lolo.local_4 = bp0c->f_0c.f_08 - bp08->f_1c.f_08;
					if(lolo.local_4 > 0x1c000)
						lolo.local_4 -= 0x38000;
					else if(lolo.local_4 < -0x1c000)
						lolo.local_4 += 0x38000;
					if(inline_abs(lolo.local_3) + inline_abs(lolo.local_4) <= lolo.local_2)
						lolo.local_1 = 2;
				}
			}
		}
	}

	return lolo.local_1;
}

struct t_local_unknown_c0 *__00762D2A() {
	return D_00E39AD8?D_00E39AD8->f_04:0;
}

void C_00762D52() {
	if(D_00E3A7D0)
		D_00E3A7D0->f_51 |= 2;
}

void C_00762D74(struct t_wm_local_18 *bp08) {
	struct {
		short local_6; char _ocal_6[2];
		t_local_unknown_c0 *local_5;
		short local_4; char _ocal_4[2];
		struct SVECTOR local_3;
		t_local_unknown_c0 *local_1;
	}lolo;

	for(lolo.local_5 = 0, lolo.local_1 = D_00E39A00; lolo.local_1; lolo.local_5 = lolo.local_1, lolo.local_1 = lolo.local_1->pNext) {
		if(lolo.local_1 != D_00E3A7D0) {//else 00762E65
			C_00750134(&(lolo.local_1->f_0c), &lolo.local_3, &lolo.local_4, &lolo.local_6);
			if(lolo.local_4 == bp08->f_10 && lolo.local_6 == bp08->f_12) {//else 00762E65
				C_0074CC07(bp08, &lolo.local_3, lolo.local_1->f_60, &(lolo.local_1->f_42), 0, &(lolo.local_1->f_4a), lolo.local_1->f_50);
				if((lolo.local_1->f_51 & 0x80) == 0)
					lolo.local_1->f_0c.f_04 = lolo.local_1->f_42 + C_007622E5(lolo.local_1->f_4a, lolo.local_1->f_50);
				lolo.local_1->f_51 |= 2;
			}
		}
	}//end for
	C_007561F6(bp08);
	C_00756B0C(bp08);
}

void C_00762E87(int bp08, int bp0c) {
	if(D_00E39AD8) {
		if(bp08 || bp0c) {
			D_00E39AD8->f_0c.f_00 += bp08;
			D_00E39AD8->f_0c.f_08 += bp0c;
			if(D_00E39AD8->f_0c.f_00 < 0)
				D_00E39AD8->f_0c.f_00 += 0x48000;
			if(D_00E39AD8->f_0c.f_00 >= 0x48000)
				D_00E39AD8->f_0c.f_00 -= 0x48000;
			if(D_00E39AD8->f_0c.f_08 < 0)
				D_00E39AD8->f_0c.f_08 += 0x38000;
			if(D_00E39AD8->f_0c.f_08 >= 0x38000)
				D_00E39AD8->f_0c.f_08 -= 0x38000;
			D_00E39AD8->f_51 |= 1;
		}
	}
}

void C_00762F75(int bp08, int bp0c, int bp10) {
	D_00E39BB4 = bp08;
	D_00E39BB8 = bp0c;
	D_00E39BBC = bp10;
}

int C_00762F9A(int bp08, int bp0c) {
	struct {//xc8
		float local_48[4];
		int local_44;
		struct t_g_drv_0c local_43;
		struct t_g_drv_0c local_40;
		int local_37;
		struct SVECTOR local_36;
		D3DMATRIX local_34;
		short local_18; char _ocal_18[2];
		D3DMATRIX local_17;
		int _ocal_1;
	}lolo;

	lolo.local_36.f_00 = 0;
	lolo.local_36.f_02 = 0;
	lolo.local_36.f_04 = 0;
	lolo.local_36.f_06 = 0;
	C_0074D33A(&lolo.local_36);
	lolo.local_37 =  (D_00DE68F8 >> 1) + D_00E2C424;
	lolo.local_40.f_00 = (float)bp08;
	lolo.local_40.f_04 = 0;
	lolo.local_40.f_08 = (float)bp0c;
	C_006617E9(C_0066100D(), &lolo.local_17);//psx:transformation to D3DMATRIX(3)
	C_0067D2BF(&lolo.local_17, &lolo.local_34);//dx_mat:matrix multiplication by "struct t_aa0::f_8d0" 4x4[transpose]
	C_0066CE40(&lolo.local_34, &lolo.local_40, lolo.local_48);
	C_0066CF4D(&lolo.local_17, &lolo.local_40, &lolo.local_43);
	lolo.local_44 = (int)lolo.local_43.f_08 >> 2;
	lolo.local_18 = (int)(lolo.local_48[0] / lolo.local_48[3]);
	lolo.local_18 = (lolo.local_18 >= lolo.local_37)?lolo.local_18 - lolo.local_37:lolo.local_37 - lolo.local_18;
	lolo.local_44 -= C_0074D4ED();
	lolo.local_44 = (lolo.local_44 > 0)?
		((lolo.local_44 * lolo.local_44) >> 0xc) + ((lolo.local_18 * lolo.local_18) >> 0xa):
		0
	;

	return lolo.local_44 >> 2;
}

void C_0076312D(struct SVECTOR *bp08) {
	if(bp08) {
		bp08->f_00 = D_00E3A848;
		bp08->f_02 = 0;
		bp08->f_04 = D_00E3A84C;
	}
}

void C_007631DF(struct t_local_unknown_c0 *);

void C_0076315C() {
	struct t_local_unknown_c0 *local_1;

	for(local_1 = D_00E39A00; local_1; local_1 = local_1->pNext)
		C_007631DF(local_1);
	for(local_1 = D_00E39A00; local_1; local_1 = local_1->pNext) {
		local_1->f_51 &= ~7;
		D_00E3A7C8 = C_00768A37(local_1->f_50);
		if(D_00E3A7C8)
			D_00E3A7C8->f_24 = 0;
	}//end for
}

void C_007631DF(struct t_local_unknown_c0 *bp08) {
	if(bp08->f_04) {
		if((bp08->f_51 & 1) || (bp08->f_04->f_51 & 1))
			bp08->f_04 = 0;
	}
	bp08->f_1c = bp08->f_0c;
}

void C_0076328F(struct t_local_unknown_c0 *);
void C_00763B74(struct t_local_unknown_c0 *);

void C_0076323A() {
	struct t_local_unknown_c0 *local_1;

	for(local_1 = D_00E39A00; local_1; local_1 = local_1->pNext)
		C_0076328F(local_1);
	for(local_1 = D_00E39A00; local_1; local_1 = local_1->pNext)
		C_00763B74(local_1);
}

int C_00763AAE(unsigned char *);

void C_0076328F(struct t_local_unknown_c0 *bp08) {
	struct {//x74
		int local_20[4];
		int local_16;
		struct t_wm_b8 *local_15;
		struct t_wm_local_30 *local_14;
		int local_13;
		int local_12;
		int local_11;
		int local_10;
		struct t_wm_b8 *local_9;
		struct SVECTOR local_8;
		int local_6;
		short local_5; char _ocal_5[2];
		struct VECTOR local_4;
	}lolo;

	if(bp08->f_51 & 8)
		bp08->f_51 &= ~2;
	if(bp08 && D_00E3A7D0 && (bp08->f_51 & 2)) {//else 00763AA9
		lolo.local_9 = C_00768A37(bp08->f_50);
		if(lolo.local_9 == 0) {
			bp08->f_51 &= ~2;
			//goto 00763AA9
		} else {
			lolo.local_15 = 0;
			if(bp08->f_08 && (lolo.local_15 = C_00768A37(bp08->f_08->f_50)) == 0) {
				bp08->f_08->f_51 &= ~2;
				//goto 00763AA9
			} else {
				lolo.local_12 = 0;
				if(bp08->f_5d) {//else 0076338E
					lolo.local_5 = /*lolo.local_21*/(bp08->f_5d > 0)?bp08->f_5d:0;
					//goto 007634BF
				} else {
					lolo.local_6 = /*lolo.local_22*/inline_abs(bp08->f_0c.f_00 - bp08->f_1c.f_00);
					if(lolo.local_6 >= 0x24000)
						lolo.local_6 = 0x48000 - lolo.local_6;
					lolo.local_10 = /*lolo.local_23*/inline_abs(bp08->f_0c.f_08 - bp08->f_1c.f_08);
					if(lolo.local_10 >= 0x1c000)
						lolo.local_10 = 0x38000 - lolo.local_10;
					lolo.local_12 = lolo.local_6 * lolo.local_6 + lolo.local_10 * lolo.local_10;
					lolo.local_5 = lolo.local_12 >= 0x64;
					if(bp08->f_50 == 6) {//else 00763495
						bp08->f_58 = (bp08 == D_00E3A7D0) << 5;
						lolo.local_5 = /*lolo.local_24*/lolo.local_12?C_00763AAE(&(bp08->f_53)):0;
					} else if(C_00761805(0x2000, bp08->f_50)) {
						bp08->f_58 = (lolo.local_12 > 0) << 5;
					}
				}
//007634BF
				lolo.local_9->f_01 = 0;
				if(lolo.local_5 >= lolo.local_9->f_04)
					lolo.local_5 = lolo.local_9->f_04 - 1;
				if(bp08->f_53 >= lolo.local_9->f_3c[lolo.local_5]->dwFrameCount)
					bp08->f_53 = /*lolo.local_25*/(bp08->f_51 & 0x20)?lolo.local_9->f_3c[lolo.local_5]->dwFrameCount - 1:0;
				lolo.local_6 =
				lolo.local_13 = 0;
				lolo.local_11 = 0;
				lolo.local_8.f_00 =
				lolo.local_8.f_02 =
				lolo.local_8.f_04 = 0;
				if((bp08->f_51 & 0x80) && bp08 == D_00E3A7D0) {
					lolo.local_9->f_44.sRot.f_00 = (float)(D_00E39BB4 - 0x40);
					lolo.local_9->f_44.sRot.f_04 = 0;
					lolo.local_9->f_44.sRot.f_08 = 0;
					lolo.local_9->f_44.sPos.f_00 = 0;
					lolo.local_9->f_44.sPos.f_04 = (float)(bp08->f_0c.f_04 - D_00DE6A04);
					lolo.local_9->f_44.sPos.f_08 = 0;
					lolo.local_8.f_02 = D_00E39BB8 + bp08->f_3c + bp08->f_3e;
					lolo.local_8.f_04 = D_00E39BBC;
					//goto 00763710
				} else {
					C_0075042B(&lolo.local_4);

					lolo.local_6 = bp08->f_0c.f_00 - lolo.local_4.f_00;
					if(lolo.local_6 < -0x24000)
						lolo.local_6 += 0x48000;
					else if(lolo.local_6 >= 0x24000)
						lolo.local_6 -= 0x48000;
					lolo.local_9->f_44.sPos.f_00 = (float)lolo.local_6;

					lolo.local_13 = bp08->f_0c.f_08 - lolo.local_4.f_08;
					if(lolo.local_13 < -0x1c000)
						lolo.local_13 += 0x38000;
					else if(lolo.local_13 >= 0x1c000)
						lolo.local_13 -= 0x38000;
					lolo.local_9->f_44.sPos.f_08 = (float)lolo.local_13;

					if(bp08 != D_00E3A7D0)
						lolo.local_11 = C_00762F9A(lolo.local_6, lolo.local_13);
					lolo.local_10 = bp08->f_0c.f_04 - D_00DE6A04 + bp08->f_44;
					lolo.local_9->f_44.sPos.f_04 = (float)(lolo.local_10 - lolo.local_11);
					lolo.local_9->f_44.sRot.f_00 = -64.0f;
					lolo.local_9->f_44.sRot.f_04 = (float)((bp08->f_3c + bp08->f_3e) >> 4);
					lolo.local_9->f_44.sRot.f_08 = 0;
				}
				if(lolo.local_15) {
					lolo.local_15->f_44.sPos.f_00 = lolo.local_9->f_44.sPos.f_00;
					lolo.local_15->f_44.sPos.f_04 = lolo.local_9->f_44.sPos.f_04;
					lolo.local_15->f_44.sPos.f_08 = lolo.local_9->f_44.sPos.f_08;
					lolo.local_15->f_44.sRot.f_00 = lolo.local_9->f_44.sRot.f_00;
					lolo.local_15->f_44.sRot.f_04 = lolo.local_9->f_44.sRot.f_04;
					lolo.local_15->f_44.sRot.f_08 = lolo.local_9->f_44.sRot.f_08;
				}
				if(bp08->f_50 == 6) {//else 0076382E
					lolo.local_16 = bp08->f_53;
					if(D_00E3A7D0->f_50 == 6 && (D_00E3A7D0->f_51 & 1)) {//else 007637F9
						C_007537AE(lolo.local_20);
						D_00E3A848 = (D_00E3A848 * 3 - C_00753DA9(lolo.local_20[2], -lolo.local_20[1])) >> 2;
						D_00E3A84C = (D_00E3A84C * 3 - C_00753DA9(lolo.local_20[0], -lolo.local_20[1])) >> 2;
					}
					lolo.local_8.f_00 = D_00E3A848;
					lolo.local_8.f_04 = D_00E3A84C;
					C_0075E0BA(lolo.local_9, bp08, lolo.local_5, lolo.local_16, &lolo.local_8);
				} else {
					C_0075E0BA(lolo.local_9, bp08, lolo.local_5, bp08->f_53, &lolo.local_8);
				}
				if(lolo.local_15) {//else 007638B7
					if(bp08->f_50 == 3) {//else 0076388E
						if(bp08->f_08)
							C_0075E0BA(lolo.local_15, 0, 0, bp08->f_08->f_53, &lolo.local_8);
					} else {
						C_0075E0BA(lolo.local_15, 0, (lolo.local_5 == 0?0:1) + 2, bp08->f_53, &lolo.local_8);
					}
				}
				C_0075AD28(bp08, (bp08->f_51 & 1) != 0);
				if(bp08->f_58 >> 4) {
					bp08->f_59 += D_00DFC480;
					bp08->f_53 += bp08->f_59 / (bp08->f_58 >> 4);
					bp08->f_59 %= bp08->f_58 >> 4;
				}
				if(bp08->f_50 == 3) {//else 007639D0
					if(bp08->f_51 & 0x80)
						bp08->f_58 = 0x20;
					else if(bp08->f_58)
						bp08->f_58 ++;
					if(lolo.local_12 >= 0xc8 && bp08->f_08) {//else 007639CE
						bp08->f_08->f_53 ++;
						if(bp08->f_08->f_53 >= lolo.local_9->f_3c[lolo.local_5]->dwFrameCount)
							bp08->f_08->f_53 = 0;
						//goto 00763A0B
					}
				} else if(bp08->f_50 == 5) {
					if(bp08 == D_00E3A7D0)
						bp08->f_58 = 0x20;
					else if(bp08->f_58)
						bp08->f_58 ++;
				}
				lolo.local_14 = &(bp08->f_90);
				lolo.local_8.f_00 =
				lolo.local_8.f_04 = 0;
				if(bp08->f_50 == 3) {
					lolo.local_8.f_00 = -0xa;
					lolo.local_8.f_04 = 0x50;
				} else if(bp08->f_50 == 0xb){
					lolo.local_8.f_04 = -0x168;
				}
				C_00753D00(&lolo.local_8, bp08->f_3c + bp08->f_3e + C_0074D319() * 4);
				lolo.local_14->f_00.pad1 = lolo.local_6 + lolo.local_8.f_00;
				bp08->f_48 = bp08->f_42 - lolo.local_11;
				lolo.local_14->f_00.pad2 = lolo.local_13 + lolo.local_8.f_04;
			}
		}
	}
}

int C_00763AAE(unsigned char *bp08) {
	int bp_04 = D_00E3A858;
	int bp_08 = C_00762136();
	switch(D_00E3A858) {
		case 1:
			if(bp_08 == 0xb)
				D_00E3A858 = 2;
		break;
		case 2:
			if(*bp08 > 5)
				D_00E3A858 = 3;
		break;
		case 3:
			if(bp_08 != 4 && bp_08 != 0xb)
				D_00E3A858 = 4;
		break;
		case 4:
			if(*bp08 > 5)
				D_00E3A858 = 1;
		break;
		default:
			D_00E3A858 = 1;
	}//end switch
	if(D_00E3A858 != bp_04)
		*bp08 = 0;
	
	return D_00E3A858;
}

void C_00763B74(struct t_local_unknown_c0 *bp08) {
	if(bp08 && D_00E3A7D0 && (bp08->f_51 & 2)) {
		if(
			(
				((C_00761805(7, bp08->f_50) && !(bp08->f_5d >= 2 && bp08->f_5d <= 5)) || C_0076192A(bp08->f_50)) &&
				(bp08 != D_00E3A7D0 || D_00E3A850 == 0) &&
				BIT_ISSET_2(0x311B6F05, bp08->f_4a)
			) ||
			bp08->f_50 == 3 ||
			bp08->f_50 == 0xb
		) {
			C_0075DEAA(bp08);
		}
	}
}

void C_00763C35(void *bp08) {
	int i;

	D_00E399B8 = bp08;
	D_00E3A810 = (unsigned short *)((char *)bp08 + 0x400);
	D_00E39ADC = D_00E3A7F0;
	D_00E3A7E0[0] = D_00DBFD38.f_0ba4;
	D_00E3A7E0[1] =
	D_00E3A7E0[2] =
	D_00E3A7E0[3] = D_00E399C0;
	D_00E3A7CC = 0;
	D_00E39BC0 =
	D_00E3A7DC =
	D_00E3A85C = 0;
	for(i = 0; i < 0x40; i ++)
		D_00E399C0[i] = 0;
	for(i = 0; i < 3; i ++) {
		D_00E3A818[i].f_08 = 0;
		D_00E3A818[i].f_04 = 0;
		D_00E3A818[i].f_00 = 0;
	}
	D_00E39BA8[0] =
	D_00E39BA8[1] = 0;
	D_00E39BA0[0] =
	D_00E39BA0[1] = 0;
	D_00E39A08.f_00 =
	D_00E39A08.f_04 =
	D_00E39A08.f_08 = 0;
}

void C_00763D6C(int bp08) {
	if(D_00E3A7D0) {
		if(bp08)
			D_00E3A7D0->f_51 |= 0x10;
		else
			D_00E3A7D0->f_51 &= ~0x10;
	}
}

void C_00763E31(int, int);

void C_00763DAA(int bp08) {
	if(D_00E39AD8 && (D_00E39AD8->f_51 & 0x10) == 0)
		C_00763E31(bp08 & 0xff, min(3, max(0, bp08 - 2)));
}

void C_00763E31(int bp08, int bp0c) {
	struct {
		int local_4;
		int local_3;
		struct t_wm_local_04_bis *local_2;
		struct t_wm_local_4 *local_1;
	}lolo;

	lolo.local_3 = 0;
	if(D_00E39AD8) {//else 00764010
		if(D_00E39AD8->f_57 < bp0c || (D_00E39AD8->f_57 == bp0c && bp0c == 3) || D_00E39AD8->f_46 == 0) {//else 00764010
			if(D_00E39AD8->f_54 >= 4)
				C_0074C9A0(0x41);//<empty>:some error management?
			if(D_00E39AD8->f_46 != 0) {
				lolo.local_2 = &(D_00E39AD8->f_2c[D_00E39AD8->f_54]);
				D_00E39AD8->f_54 ++;
				lolo.local_2->f_00 = D_00E39AD8->f_46;
				lolo.local_2->f_02 = D_00E39AD8->f_56;
				lolo.local_2->f_03 = D_00E39AD8->f_57;
				lolo.local_3 = 1;
			}
			lolo.local_1 = (struct t_wm_local_4 *)((char *)D_00E399B8 + 0x200);
			for(lolo.local_4 = 0x40; lolo.local_4 && lolo.local_1->f_00 != bp08; lolo.local_4 >>= 1) {
				if(lolo.local_1->f_00 < bp08)
					lolo.local_1 += lolo.local_4;
				else
					lolo.local_1 -= lolo.local_4;
			}
			if(lolo.local_1->f_00 == bp08) {
				D_00E39AD8->f_46 = lolo.local_1->f_02;
				D_00E39AD8->f_57 = bp0c;
			} else {
				D_00E39AD8->f_46 = 0;
				D_00E39AD8->f_57 = 0;
			}
			if(lolo.local_3 && D_00E39AD8->f_46 == 0) {//else 00764010
				D_00E39AD8->f_54 --;
				lolo.local_2 = &(D_00E39AD8->f_2c[D_00E39AD8->f_54]);
				D_00E39AD8->f_46 = lolo.local_2->f_00;
				D_00E39AD8->f_56 = lolo.local_2->f_02;
				D_00E39AD8->f_57 = lolo.local_2->f_03;
			}
		}
	}
}

void C_00764014(int bp08, int bp0c) {
	C_00762047(bp08);
	if(D_00E39AD8 && (D_00E39AD8->f_51 & 0x10) == 0)
		C_00763E31(0x4000 | ((bp08 << 8) & 0x3f00) | (bp0c & 0xff), min(3, max(0, bp0c - 2)));
}

void C_007640BC(int bp08) {
	D_00E39AD8 = &D_00E39A18;
	if(bp08 == 1)
		D_00E3A7DC = 1;
	C_00763E31(bp08 & 0xff, min(3, max(0, bp08 - 2)));
}

void C_00764142(short bp08, short bp0c) {
	struct {
		short local_2; char _ocal_2[2];
		short local_1; char _ocal_1[2];
	}lolo;

	D_00E39AD8 = &D_00E39A18;
	C_00750134(&(D_00E3A7D0->f_0c), 0, &lolo.local_1, &lolo.local_2);
	C_00763E31(0x8000 | (((lolo.local_2 * 0x24 + lolo.local_1) << 4) & 0x3ff0) | ((bp08 + bp0c * 5) & 0xf), 3);
}

void C_0076420A(struct t_local_unknown_c0 *);

void C_007641A7() {
	struct t_local_unknown_c0 *local_1;

	D_00E3A7CC = &D_00E39A18;
	D_00E39AD8 = &D_00E39A18;
	C_0076420A(&D_00E39A18);
	for(local_1 = D_00E39A00; local_1; local_1 = local_1->pNext) {
		D_00E3A7CC =
		D_00E39AD8 = local_1;
		C_0076420A(local_1);
	}
}

void C_00764336(unsigned short);
void C_00764CCB(unsigned short);
int C_00764D59(unsigned short);
int C_00764F9C(unsigned short);

void C_0076420A(struct t_local_unknown_c0 *bp08) {
	struct {
		unsigned short local_2; char _ocal_2[2];
		int local_1;
	}lolo;

	D_00E39BC0 = 0;
	if(D_00E3A7CC->f_46) {//else 007642E1
		lolo.local_1 = 0;
		while(lolo.local_1 == 0) {
			lolo.local_2 = D_00E3A810[D_00E3A7CC->f_46];
			D_00E3A7CC->f_46 ++;
			if(lolo.local_2 < 0x100)
				C_00764336(lolo.local_2);
			else if(lolo.local_2 < 0x200)
				C_00764CCB(lolo.local_2);
			else if(lolo.local_2 < 0x300)
				lolo.local_1 = C_00764D59(lolo.local_2);
			else
				lolo.local_1 = C_00764F9C(lolo.local_2);
		}//end while
	}
	C_00761BEE(bp08->f_40);
	if(bp08->f_04 && D_00E3A7DC == 0 && C_0074D4B6()) {
		C_00764014(bp08->f_04->f_50, ((C_007186B9() & 0x20) == 0?0:1) + 3);
	}
}

int C_0076488C(void);
void C_00764B8C(int);

void C_00764336(unsigned short bp08) {
	struct {
		struct VECTOR bp_1c;
		struct t_local_unknown_c0 *bp_0c;
		int bp_08;
		int bp_04;
	}lolo;

	switch(bp08) {
		case 0x15:
			D_00E39ADC->f_00 = -C_0076488C();
		break;
		case 0x17:
			D_00E39ADC->f_00 = C_0076488C()?0:1;
		break;
		case 0x30:
			lolo.bp_08 = C_0076488C();
			lolo.bp_04 = C_0076488C();
			D_00E39ADC->f_00 = lolo.bp_04 * lolo.bp_08;
		break;
		case 0x40:
			lolo.bp_08 = C_0076488C();
			lolo.bp_04 = C_0076488C();
			D_00E39ADC->f_00 = lolo.bp_04 + lolo.bp_08;
		break;
		case 0x41:
			lolo.bp_08 = C_0076488C();
			lolo.bp_04 = C_0076488C();
			D_00E39ADC->f_00 = lolo.bp_04 - lolo.bp_08;
		break;
		case 0x60:
			lolo.bp_08 = C_0076488C();
			lolo.bp_04 = C_0076488C();
			D_00E39ADC->f_00 = lolo.bp_04 < lolo.bp_08;
		break;
		case 0x61:
			lolo.bp_08 = C_0076488C();
			lolo.bp_04 = C_0076488C();
			D_00E39ADC->f_00 = lolo.bp_04 > lolo.bp_08;
		break;
		case 0x62:
			lolo.bp_08 = C_0076488C();
			lolo.bp_04 = C_0076488C();
			D_00E39ADC->f_00 = lolo.bp_04 <= lolo.bp_08;
		break;
		case 0x63:
			lolo.bp_08 = C_0076488C();
			lolo.bp_04 = C_0076488C();
			D_00E39ADC->f_00 = lolo.bp_04 >= lolo.bp_08;
		break;
		case 0x70:
			lolo.bp_08 = C_0076488C();
			lolo.bp_04 = C_0076488C();
			D_00E39ADC->f_00 = lolo.bp_04 == lolo.bp_08;
		break;
		case 0x71:
			lolo.bp_08 = C_0076488C();
			lolo.bp_04 = C_0076488C();
			D_00E39ADC->f_00 = lolo.bp_04 != lolo.bp_08;
		break;
		case 0x50:
			lolo.bp_08 = C_0076488C();
			lolo.bp_04 = C_0076488C();
			D_00E39ADC->f_00 = lolo.bp_04 << lolo.bp_08;
		break;
		case 0x51:
			lolo.bp_08 = C_0076488C();
			lolo.bp_04 = C_0076488C();
			D_00E39ADC->f_00 = lolo.bp_04 >> lolo.bp_08;
		break;
		case 0x80:
			lolo.bp_08 = C_0076488C();
			lolo.bp_04 = C_0076488C();
			D_00E39ADC->f_00 = lolo.bp_04 & lolo.bp_08;
		break;
		case 0xa0:
			lolo.bp_08 = C_0076488C();
			lolo.bp_04 = C_0076488C();
			D_00E39ADC->f_00 = lolo.bp_04 | lolo.bp_08;
		break;
		case 0xb0:
			lolo.bp_08 = C_0076488C();
			lolo.bp_04 = C_0076488C();
			D_00E39ADC->f_00 = (lolo.bp_04 && lolo.bp_08)?1:0;
		break;
		case 0xc0:
			lolo.bp_08 = C_0076488C();
			lolo.bp_04 = C_0076488C();
			D_00E39ADC->f_00 = (lolo.bp_04 == 0 && lolo.bp_08 == 0)?0:1;
		break;
		case 0xe0:
			lolo.bp_08 = C_0076488C();
			C_00764B8C(lolo.bp_08);
		break;
		case 0x18:
			C_00754EBC(C_0076488C(), -1);
			C_00762763(&lolo.bp_1c);
			D_00E39ADC->f_00 = C_0075542D(&lolo.bp_1c) >> 5;
		break;
		case 0x19:
			lolo.bp_0c = D_00E39AD8;
			D_00E39ADC->f_00 = 0;
			if(C_00762047(C_0076488C()))
				D_00E39ADC->f_00 = C_00753C23(&(D_00E39AD8->f_0c), &(lolo.bp_0c->f_0c)) >> 4;
			D_00E39AD8 = lolo.bp_0c;
		break;
		case 0x1a:
			lolo.bp_04 = C_0076488C();
			lolo.bp_1c = D_00E39AD8->f_0c;
			lolo.bp_1c.f_04 = 0;
			D_00E39ADC->f_00 = /*lolo.bp_2c*/(lolo.bp_04 >= 0 && lolo.bp_04 < 3)?
				C_00753C23(&lolo.bp_1c, &(D_00E3A818[lolo.bp_04])) >> 4:
				0
			;
		break;
		case 0x1b:
			C_00754EBC(C_0076488C(), -1);
			C_00762763(&lolo.bp_1c);
			D_00E39ADC->f_00 = C_0075545F(&lolo.bp_1c) >> 4;
		break;
	}//end switch
	D_00E39ADC->f_04 = 0x110;
	D_00E39ADC ++;
}

int C_0076488C() {
	struct {
		int bp_08;
		short *bp_04;
	}lolo;

	lolo.bp_08 = 0;
	if(D_00E39ADC-- <= D_00E3A7F0)
		C_0074C9A0(0x3e);//<empty>:some error management?
	if((D_00E39ADC->f_04 & 3) < 3) {//else 007649C4
		switch(D_00E39ADC->f_04 & ~3) {
			case 0x110:
				lolo.bp_08 = D_00E39ADC->f_00;
			break;
			case 0x114:
				lolo.bp_08 = (D_00E3A7E0[D_00E39ADC->f_04 & 3][D_00E39ADC->f_00 >> 3] >> (D_00E39ADC->f_00 & 7)) & 1;
			break;
			case 0x118:
				lolo.bp_08 = D_00E3A7E0[D_00E39ADC->f_04 & 3][D_00E39ADC->f_00];
			break;
			case 0x11c:
				lolo.bp_04 = (short *)&(D_00E3A7E0[D_00E39ADC->f_04 & 3][D_00E39ADC->f_00]);
				if((unsigned)lolo.bp_04 & 1)
					C_0074C9A0(0x3f);//<empty>:some error management?
				lolo.bp_08 = *lolo.bp_04;
			break;
		}//end switch
	} else {
		switch(D_00E39ADC->f_00) {
			case 0: lolo.bp_08 = D_00E39AD8->f_0c.f_00 >> 0xd; break;
			case 1: lolo.bp_08 = D_00E39AD8->f_0c.f_08 >> 0xd; break;
			case 2: lolo.bp_08 = D_00E39AD8->f_0c.f_00 & 0x1fff; break;
			case 3: lolo.bp_08 = D_00E39AD8->f_0c.f_08 & 0x1fff; break;
			case 4: lolo.bp_08 = (D_00E39AD8->f_40 >> 4)  & 0xff; break;
			case 5: lolo.bp_08 = C_00767204(); break;
			case 6: lolo.bp_08 = C_0076720E(); break;
			case 7: lolo.bp_08 = C_0074D8CF(); break;
			case 8: lolo.bp_08 = C_00761735(); break;//current transportation mode?
			case 0xf: lolo.bp_08 = D_00E39AD8->f_50; break;
			case 9: lolo.bp_08 = C_007674DF(); break;
			case 0xa: lolo.bp_08 = C_007674EB(); break;
			case 0xb: lolo.bp_08 = C_007561EC(); break;
			case 0xc: lolo.bp_08 = C_0075F00E(); break;
			case 0xd: lolo.bp_08 = (D_00E39AD8->f_4a >> 5) & 7; break;
			case 0xe: lolo.bp_08 = C_0076736E(); break;
			case 0x10: lolo.bp_08 = C_00753BE8(); break;//wm:random?
			case 0x11: lolo.bp_08 = D_00E39BA8[0]; break;
			case 0x12: lolo.bp_08 = D_00E39BA8[1]; break;
			case 0x13: lolo.bp_08 = D_00E39BA0[0]; break;
			case 0x14: lolo.bp_08 = D_00E39BA0[1]; break;
		}//end switch
	}

	return lolo.bp_08;
}

void C_00764B8C(int bp08) {
	struct {
		int local_2;
		unsigned char *local_1;
	}lolo;

	if(D_00E39ADC-- <= D_00E3A7F0)
		C_0074C9A0(0x3e);//<empty>:some error management?
	lolo.local_1 = D_00E3A7E0[D_00E39ADC->f_04 & 3];
	switch(D_00E39ADC->f_04 & ~3) {
		case 0x114:
			lolo.local_1 += D_00E39ADC->f_00 >> 3;
			lolo.local_2 = D_00E39ADC->f_00 & 7;
			*lolo.local_1 &= ~(1 << lolo.local_2);
			*lolo.local_1 |= (bp08 != 0) << lolo.local_2;
		break;
		case 0x118:
			lolo.local_1[D_00E39ADC->f_00] = bp08;
		break;
		case 0x11c:
			lolo.local_1 += D_00E39ADC->f_00;
			if((unsigned)lolo.local_1 & 1)
				C_0074C9A0(0x3f);//<empty>:some error management?
			*(short *)lolo.local_1 = bp08;
		break;
		default:
			C_0074C9A0(0x40);//<empty>:some error management?
	}//end switch
	D_00E39ADC->f_00 = bp08;
	D_00E39ADC->f_04 = 0x110;
	D_00E39ADC ++;
}

void C_00764CCB(unsigned short bp08) {
	if(bp08 == 0x100) {
		D_00E39ADC = D_00E3A7F0;
		return ;
	}
	if(D_00E39ADC == 0 || D_00E3A7CC == 0)
		C_0074C9A0(0x3d);//<empty>:some error management?
	D_00E39ADC->f_04 = bp08;
	D_00E39ADC->f_00 = D_00E3A810[D_00E3A7CC->f_46];
	D_00E3A7CC->f_46 ++;
	D_00E39ADC ++;
}

int C_00764D59(unsigned short bp08) {
	struct {
		struct t_wm_local_04_bis *local_3;
		int local_2;
		struct t_local_unknown_c0 *local_1;
	}lolo;

	lolo.local_2 = 0;
	switch(bp08) {
		case 0x200:
			bp08 = D_00E3A810[D_00E3A7CC->f_46 ++];
			D_00E3A7CC->f_46 = bp08;
		break;
		case 0x201:
			bp08 = D_00E3A810[D_00E3A7CC->f_46 ++];
			if(C_0076488C() == 0)
				D_00E3A7CC->f_46 = bp08;
		break;
		case 0x203:
			if(D_00E3A7CC->f_54 > 0) {
				D_00E3A7CC->f_54 --;
				lolo.local_3 = &(D_00E3A7CC->f_2c[D_00E3A7CC->f_54]);
				D_00E3A7CC->f_46 = lolo.local_3->f_00;
				D_00E3A7CC->f_56 = lolo.local_3->f_02;
				D_00E3A7CC->f_57 = lolo.local_3->f_03;
			} else {
				D_00E3A7CC->f_46 = 0;
				D_00E3A7CC->f_57 = 0;
				if(D_00E3A7DC) {//else 00764EE9
					if(D_00E3A7CC == &D_00E39A18) {//else 00764EE7
						for(lolo.local_1 = D_00E39A00; lolo.local_1; lolo.local_1 = lolo.local_1->pNext) {
							C_00764014(lolo.local_1->f_50, 1);
						}
					}
				} else {
					if(D_00E3A7CC == &D_00E39A18) {
						C_007640BC(2);
					} else {
						C_00764014(D_00E3A7CC->f_50, 2);
					}
				}
				lolo.local_2 = 1;
			}
		break;
		default:
			D_00E3A7CC->f_52 = C_0076488C();
			if(D_00E3A7CC->f_52 < 0x40) {
				C_00764014(D_00E3A7CC->f_52, bp08 - 0x204);
			} else {
				D_00E3A7CC->f_52 = D_00E39AD8->f_50;
				C_00763DAA(bp08 - 0x204);
			}
			lolo.local_2 = 1;
	}//end switch

	return lolo.local_2;
}

int C_00764F9C(unsigned short bp08) {
	struct {
		struct VECTOR bp_34;
		struct SVECTOR bp_24;
		int bp_1c;
		int bp_18;
		struct t_local_unknown_c0 *bp_14;
		int bp_10;
		int bp_0c;
		short bp_08[4];
	}lolo;

	if(D_00E39AD8 == 0)
		C_0074C9A0(0x43);//<empty>:some error management?
	switch(bp08) {
		case 0x300:
			lolo.bp_1c = C_0076488C();
			if(C_00762047(lolo.bp_1c) == 0) {
				C_007610B3();
				C_0076197B(lolo.bp_1c);
				C_00764014(lolo.bp_1c, 0);
			}
		break;
		case 0x343:
			C_007664C2(D_00E39AD8->f_50);
			lolo.bp_14 = D_00E39AD8;
			C_007611FF(lolo.bp_14);
			lolo.bp_1c = C_0076488C();
			if(C_00762047(lolo.bp_1c) == 0) {
				C_007610B3();
				C_0076197B(lolo.bp_1c);
			}
			D_00E39AD8->f_08 = lolo.bp_14;
			D_00E39AD8->f_51 |= 2;
		break;
		case 0x302:
			C_007616CB();
			C_0074D4C0(D_00E3A7D0->f_40);
		break;
		case 0x330:
			C_00762047(C_0076488C());
		break;
		case 0x346:
			D_00E39AD8->f_50 = C_0076488C();
		break;
		case 0x307:
			C_0074D438(C_0076488C(), 3);
		break;
		case 0x336:
			D_00E39AD8->f_55 = C_0076488C();
			D_00E39AD8->f_51 |= 0x40;
		break;
		case 0x303:
			D_00E39AD8->f_55 = C_0076488C();
			D_00E39AD8->f_51 &= ~0x40;
		break;
		case 0x304:
			D_00E39AD8->f_4c =
			D_00E39AD8->f_40 = (C_0076488C() << 4) & 0xfff;
			if(D_00E39AD8 == D_00E3A7D0)
				C_0074D4C0(D_00E39AD8->f_40);
		break;
		case 0x328:
			D_00E39AD8->f_4c = (C_0076488C() << 4) & 0xfff;
		break;
		case 0x333:
			lolo.bp_14 = D_00E39AD8;
			lolo.bp_0c = C_0076488C() << 4;
			if(D_00E39AD8 && C_00762047(C_0076488C()))
				lolo.bp_14->f_40 = C_00753F2E(&(lolo.bp_14->f_0c), &(D_00E39AD8->f_0c)) + lolo.bp_0c;
			D_00E39AD8 = lolo.bp_14;
		break;
		case 0x344:
			lolo.bp_0c = C_0076488C();
			if(lolo.bp_0c >= 0 && lolo.bp_0c < 3) {
				D_00E3A818[lolo.bp_0c] = D_00E39AD8->f_0c;
				D_00E3A818[lolo.bp_0c].f_04 = 0;
			}
		break;
		case 0x345:
			lolo.bp_0c = C_0076488C();
			if(lolo.bp_0c >= 0 && lolo.bp_0c < 3) {
				D_00E39AD8->f_4c =
				D_00E39AD8->f_40 = C_00753F2E(&(D_00E39AD8->f_0c), &(D_00E3A818[lolo.bp_0c]));
			}
		break;
		case 0x308:
			lolo.bp_10 = C_0076488C();
			lolo.bp_0c = C_0076488C();
			D_00E39AD8->f_0c.f_00 &= 0x1fff;
			D_00E39AD8->f_0c.f_00 |= lolo.bp_0c << 0xd;
			D_00E39AD8->f_0c.f_08 &= 0x1fff;
			D_00E39AD8->f_0c.f_08 |= lolo.bp_10 << 0xd;
			if(D_00E39AD8->f_0c.f_00 != D_00E39AD8->f_1c.f_00 || D_00E39AD8->f_0c.f_08 != D_00E39AD8->f_1c.f_08)
				D_00E39AD8->f_51 |= 1;
		break;
		case 0x309:
			lolo.bp_10 = C_0076488C();
			lolo.bp_0c = C_0076488C();
			D_00E39AD8->f_0c.f_00 &= ~0x1fff;
			D_00E39AD8->f_0c.f_00 |= lolo.bp_0c & 0x1fff;
			D_00E39AD8->f_0c.f_08 &= ~0x1fff;
			D_00E39AD8->f_0c.f_08 |= lolo.bp_10 & 0x1fff;
			if(D_00E39AD8->f_0c.f_00 != D_00E39AD8->f_1c.f_00 || D_00E39AD8->f_0c.f_08 != D_00E39AD8->f_1c.f_08)
				D_00E39AD8->f_51 |= 1;
		break;
		case 0x347:
			lolo.bp_14 = D_00E39AD8;
			if(lolo.bp_14 && C_00762047(C_0076488C())) {
				lolo.bp_14->f_0c = D_00E39AD8->f_0c;
				lolo.bp_14->f_1c = D_00E39AD8->f_1c;
				lolo.bp_14->f_51 |= 1;
			}
			D_00E39AD8 = lolo.bp_14;
		break;
		case 0x30e:
			if(C_0076488C())
				D_00E39AD8->f_51 &= ~0x20;
			else
				D_00E39AD8->f_51 |= 0x20;
			D_00E39AD8->f_5d = C_0076488C();
			D_00E39AD8->f_53 = 0;
		break;
		case 0x353:
			C_0076247D(&D_00E39A08);
		break;
		case 0x30a:
			D_00E39AD8->f_5c = C_0076488C();
		break;
		case 0x30b:
			D_00E39AD8->f_44 = C_0076488C();
		break;
		case 0x33a:
			D_00E39AD8->f_5f = C_0076488C();
			D_00E39AD8->f_51 |= 0x80;
		break;
		case 0x34f:
			D_00E39AD8->f_0c.f_04 = C_0076488C();
			D_00E39AD8->f_51 |= 0x80;
		break;
		case 0x30d:
			C_00762837();
		break;
		case 0x30c:
			if(C_007620B6())
				C_007667B2(1);
		break;
		case 0x31a:
			C_007615BA();
		break;
		case 0x338:
			D_00E39AD8->f_51 &= ~8;
		break;
		case 0x339:
			D_00E39AD8->f_51 |= 8;
		break;
		case 0x348:
			lolo.bp_10 = C_0076488C();
			lolo.bp_0c = C_0076488C();
			C_00755B70(lolo.bp_0c, lolo.bp_10);
		break;
		case 0x33b:
			lolo.bp_10 = C_0076488C();
			lolo.bp_0c = C_0076488C();
			C_00755B97(lolo.bp_0c, lolo.bp_10);
		break;
		case 0x310:
			lolo.bp_10 = C_0076488C();
			lolo.bp_0c = C_0076488C();
			C_00754EBC(lolo.bp_0c, lolo.bp_10);
		break;
		case 0x311:
			lolo.bp_10 = C_0076488C();
			lolo.bp_0c = C_0076488C();
			C_00754EEF(lolo.bp_0c, lolo.bp_10);
		break;
		case 0x312:
			lolo.bp_10 = C_0076488C();
			lolo.bp_0c = C_0076488C();
			C_00754F72(lolo.bp_0c, lolo.bp_10);
		break;
		case 0x313:
			lolo.bp_18 = C_0076488C();
			lolo.bp_10 = C_0076488C();
			lolo.bp_0c = C_0076488C();
			C_00754FE2(lolo.bp_0c, lolo.bp_10, lolo.bp_18);
		break;
		case 0x314:
			C_0075502C(C_0076488C());
			C_00755013(C_0076488C());
		break;
		case 0x315:
			lolo.bp_18 = C_0076488C();
			lolo.bp_10 = C_0076488C();
			lolo.bp_0c = C_0076488C();
			C_00755045(lolo.bp_0c, lolo.bp_10, lolo.bp_18);
		break;
		case 0x316:
			lolo.bp_18 = C_0076488C();
			lolo.bp_10 = C_0076488C();
			lolo.bp_0c = C_0076488C();
			C_00755076(lolo.bp_0c, lolo.bp_10, lolo.bp_18);
		break;
		case 0x31c:
			C_0074D2D7(C_0076488C());
		break;
		case 0x31e:
			C_0074D2A7(C_0076488C() << 4);
		break;
		case 0x32f:
			C_0074D2B9(C_0076488C() << 4);
		break;
		case 0x31f:
			C_0074DA26(C_0076488C());
		break;
		case 0x329:
			C_0074DA33(C_0076488C());
		break;
		case 0x32a:
			C_0074DA40(C_0076488C());
		break;
		case 0x352:
			C_0074CBB5(C_0076488C());//set earthquake effect
		break;
		case 0x31d:
			C_0075E657(C_0076488C());
		break;
		case 0x320:
			C_0075611B();
		break;
		case 0x317:
			C_0075E5B3(1);
			C_0075E5C0(4);
			C_0074D7CD(C_0076488C());
		break;
		case 0x355:
			C_007671AD(C_0076488C());//set countdown?
		break;
		case 0x32b:
			C_00767533(C_0076488C());
		break;
		case 0x318:
			lolo.bp_10 = C_0076488C();
			lolo.bp_0c = C_0076488C();
			C_0074D74C(lolo.bp_0c << 8 | lolo.bp_10);
		break;
		case 0x33d:
			C_0074D731(C_0076488C());
		break;
		case 0x319:
			C_0074D8EF(C_0076488C());
		break;
		case 0x305:
			D_00E3A7CC->f_56 = C_0076488C();
		break;
		case 0x331:
			C_0076667C();//"X" button short trigger?
		break;
		case 0x33c:
			C_0074D6BB();
		break;
		case 0x335:
			C_00761313();
		break;
		case 0x354:
			if(C_0076488C())
				D_00E39AD8->f_51 &= ~0x10;
			else
				D_00E39AD8->f_51 |= 0x10;
		break;
		case 0x332:
			D_00E39AD8->f_51 |= 0x10;
			C_00758A32(3);
		break;
		case 0x337:
			C_00766B5D(C_0076488C());
		break;
		case 0x34b:
			lolo.bp_0c = C_0076488C();
			C_0074DB45(lolo.bp_0c);
			C_0075E4D6(0x13, lolo.bp_0c);
		break;
		case 0x34c:
			C_0075E4D6(0xd, C_0076488C() + 5);
		break;
		case 0x321:
			if(D_00E39AD8) {
				C_00754EBC(C_0076488C(), -1);
				C_00762763(&lolo.bp_34);
				D_00E39AD8->f_4c =
				D_00E39AD8->f_40 =
				D_00E39AD8->f_3c = C_0075545F(&lolo.bp_34);
				D_00E39AD8->f_3e = 0;
			}
		break;
		case 0x349:
			C_007537A1(C_0076488C());
		break;
		case 0x34a:
			C_0075BBB3(D_00E39AD8, C_0076488C());
		break;
		case 0x34d:
			lolo.bp_18 = C_0076488C();
			lolo.bp_10 = C_0076488C();
			lolo.bp_0c = C_0076488C();
			if(D_00E39AD8)
				C_0075BFE5(lolo.bp_0c, D_00E39AD8->f_50, lolo.bp_10, lolo.bp_18);
		break;
		case 0x34e:
			C_0075C01B(C_0076488C());
		break;
		case 0x350:
			C_00754E10(C_0076488C());
		break;
		case 0x33e:
			C_0075E5B3(1);
			lolo.bp_0c = C_0076488C();
			C_0075E5C0(lolo.bp_0c);
			if(lolo.bp_0c)
				C_0075E5B3(0);
		break;
		case 0x351:
			C_0075E697(C_0076488C());
		break;
		case 0x324:
			lolo.bp_08[3] = C_0076488C();
			lolo.bp_08[2] = C_0076488C();
			lolo.bp_08[1] = C_0076488C();
			lolo.bp_08[0] = C_0076488C();
			C_0075F038(lolo.bp_08);
		break;
		case 0x32c:
			lolo.bp_10 = C_0076488C();
			lolo.bp_0c = C_0076488C();
			C_0075F06C(lolo.bp_0c, lolo.bp_10);
		break;
		case 0x325:
			C_0075EE86(C_0076488C());
		break;
		case 0x326:
			lolo.bp_18 = C_0076488C();
			lolo.bp_10 = C_0076488C();
			lolo.bp_0c = C_0076488C();
			C_0075EEBB(lolo.bp_0c, lolo.bp_10, lolo.bp_18);
		break;
		case 0x327:
			if(C_0075F00E() < 0 && D_00E3A7DC == 0) {
				D_00E39AD8->f_46 --;

				return 1;
			}
		break;
		case 0x32d:
			if(D_00E3A7DC == 0) {
				lolo.bp_0c = C_0075EF13();
				D_00E39AD8->f_46 -= lolo.bp_0c;

				return lolo.bp_0c;
			}
		break;
		case 0x32e:
			if(D_00E3A7DC == 0) {
				lolo.bp_0c = C_0075EF01();
				D_00E39AD8->f_46 -= lolo.bp_0c;

				return lolo.bp_0c;
			}
		break;
		case 0x334:
			if(D_00E3A7DC == 0) {
				lolo.bp_14 = D_00E39AD8;
				C_00762047(D_00E3A7CC->f_52);
				lolo.bp_0c = D_00E39AD8->f_57 > 0;
				lolo.bp_14->f_46 -= lolo.bp_0c;
				D_00E39AD8 = lolo.bp_14;

				return lolo.bp_0c;
			}
		break;
		case 0x33f:
			C_0075334D();
		break;
		case 0x341:
			if(D_00E3A7DC == 0) {
				lolo.bp_0c = C_00758A3F()?0:1;
				D_00E3A7CC->f_46 -= lolo.bp_0c;

				return lolo.bp_0c;
			}
		break;
		case 0x340:
			C_007570E8(C_0076488C());
		break;
		case 0x342:
			if(D_00E3A7DC == 0) {
				lolo.bp_0c = C_00758A6C();
				D_00E3A7CC->f_46 -= lolo.bp_0c;

				return lolo.bp_0c;
			}
		break;
		case 0x306:
			if(D_00E39BC0) {
				D_00E3A7CC->f_46 --;

				return 1;
			}
			D_00E3A7CC->f_56 --;
			if(D_00E3A7CC->f_56)
				D_00E3A7CC->f_46 --;
			else
				D_00E39BC0 = 1;
			lolo.bp_24.f_00 =
			lolo.bp_24.f_02 = 0;
			lolo.bp_24.f_04 = D_00E39AD8->f_55 << (((D_00E39AD8->f_51 & 0x40)?1:0) << 2);
			C_00753D00(&lolo.bp_24, D_00E39AD8->f_4c);
			C_00762E87(lolo.bp_24.f_00, lolo.bp_24.f_04);
			D_00E39AD8->f_44 -= D_00E39AD8->f_5c;
			D_00E39AD8->f_0c.f_04 += D_00E39AD8->f_5f;

			return D_00E3A7CC->f_56 > 0;
	}//end switch
	
	return 0;
}

void C_00765F61() {
	int local_2;
	int local_1;

	if(D_00E3A7DC == 0 && (D_00E3A7D0->f_51 & 8) == 0) {//else 0076603B
		if(C_00761769(0x2000))
			local_2 = (D_00E3A7D0->f_0c.f_04 - D_00E3A7D0->f_42) < 0x1f4;
		else
			local_2 = (D_00E3A7D0->f_51 & 0x80)?0:1;
		if(local_2) {//else 0076603B
			local_1 = C_007621C0();
			if(local_1 >= 3) {//else 00766032
				if(D_00E3A85C != local_1) {//else 00766014
					D_00E3A85C = local_1;
					C_00764142(local_1 - 3, 0);
				}
				if(local_1 == 7 && C_00761769(0x2000) == 0)
					C_007628B5();
			} else {
				D_00E3A85C = 0;
			}
		}
	}
}

int C_0076603F() {
	struct {
		int local_2;
		struct t_local_unknown_c0 *local_1;
	}lolo;

	lolo.local_2 = 0;
	lolo.local_2 |= D_00E39A18.f_46?1:0;
	for(lolo.local_1 = D_00E39A00; lolo.local_1 && lolo.local_2 == 0; lolo.local_1 = lolo.local_1->pNext) {
		lolo.local_2 |= lolo.local_1->f_46?1:0;
	}//end for

	return lolo.local_2;
}

void C_007660DB(struct t_local_unknown_c0 *);//save object coordinates?

void C_0076609E() {
	struct t_local_unknown_c0 *local_1;

	for(local_1 = D_00E39A00; local_1; local_1 = local_1->pNext) {
		if((local_1->f_51 & 8) == 0)
			C_007660DB(local_1);//save object coordinates?
	}//end for
}

unsigned char D_0096DE80[] = {
	0x00,0x00,0x00,0x03,0x01,0x02,0x03,0x09,
	0x09,0x09,0x05,0x05,0x09,0x04,0x09,0x09,
	0x09,0x09,0x09,0x02,0x09,0x09,0x09,0x09,
	0x09,0x09,0x09,0x09,0x09,0x05,0x09,0x09
};

//save object coordinates?
void C_007660DB(struct t_local_unknown_c0 *bp08) {
	struct t_wm_local_8_rrr *local_1;

	if(D_0096DE80[bp08->f_50] < 6) {
		local_1 = &(D_00E3A7D8[D_0096DE80[bp08->f_50]]);
		local_1->f_00 = (bp08->f_1c.f_00 & 0x0007ffff) | ((bp08->f_50 << 0x13) & 0x00f80000) | ((bp08->f_40 << 0x14) & 0xff000000);
		local_1->f_04 = (bp08->f_1c.f_08 & 0x0003ffff) | ((bp08->f_1c.f_04 << 0x12) & 0xfffc0000);
	}
}

//load object coordinates?
void C_0076616A(struct t_local_unknown_c0 *bp08) {
	struct t_wm_local_8_rrr *local_1;

	for(local_1 = &(D_00E3A7D8[0]); local_1 < &(D_00E3A7D8[6]) && ((local_1->f_00 >> 0x13) & 0x1f) != bp08->f_50; local_1 ++);
	if(local_1 < &(D_00E3A7D8[6]) && bp08) {
		bp08->f_0c.f_00 =
		bp08->f_1c.f_00 = local_1->f_00 & 0x7ffff;
		bp08->f_0c.f_04 =
		bp08->f_1c.f_04 = local_1->f_04 >> 0x12;
		bp08->f_0c.f_08 =
		bp08->f_1c.f_08 = local_1->f_04 & 0x3ffff;
		bp08->f_4c =
		bp08->f_3c =
		bp08->f_40 = (local_1->f_00 >> 0x14) & 0xff0;
		bp08->f_3e = 0;
	}
}

void C_00766255(int bp08, int bp0c) {
	struct {
		unsigned local_4;
		int local_3;
		unsigned local_2;
		int local_1;
	}lolo;

	D_00E39BA8[0] =
	D_00E39BA8[1] = 0;
	D_00E39BA0[0] =
	D_00E39BA0[1] = 0;
	lolo.local_1 = 0x40;
	lolo.local_2 = bp08 & ~bp0c;
	lolo.local_4 = 0;
	if(lolo.local_2 & lolo.local_1) {
		D_00E39BA0[lolo.local_4 ++] = 0x26;
		lolo.local_2 &= ~lolo.local_1;
	}
	for(lolo.local_3 = 0; lolo.local_4 < 2 && lolo.local_2; lolo.local_3 ++, lolo.local_2 >>= 1) {
		if(lolo.local_2 & 1) {
			D_00E39BA0[lolo.local_4++] = lolo.local_3 + 0x20;
		}
	}
	lolo.local_2 = ~bp08 & bp0c;
	lolo.local_4 = 0;
	if(lolo.local_2 & lolo.local_1) {
		D_00E39BA8[lolo.local_4++] = 0x26;
		lolo.local_2 &= ~lolo.local_1;
	}
	for(lolo.local_3 = 0; lolo.local_4 < 2 && lolo.local_2; lolo.local_3 ++, lolo.local_2 >>= 1) {
		if(lolo.local_2 & 1) {
			D_00E39BA8[lolo.local_4 ++] = lolo.local_3 + 0x20;
		}
	}
}

void C_007663A8(struct VECTOR *bp08) {
	D_00E39A08 = *bp08;
}
