/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//WORLD MAP -- 

#include "ff7.h"
#include "wm_data.h"
////////////////////////////////////////
struct t_wm_local_08_ter {//size 8
	/*00*/struct t_wm_local_08_ter *pNext;
	/*04*/short f_04;
	/*06*/short f_06;
};

struct t_wm_local_08_bis {//size 8
	/*00*/struct t_wm_local_08_bis *pNext;
	/*04*/struct t_wm_local_18 *f_04;
};
////////////////////////////////////////
struct t_wm_local_18 *D_00E045F8;
unsigned char (*D_00E045FC)[0xb800];
int D_00E04600;
int D_00E04604;
struct t_wm_local_0c *D_00E04608;
struct t_wm_local_18 D_00E04610[0x20];//or 0x1f
int D_00E04910;
//00E04914
struct VECTOR D_00E04918;
struct t_wm_local_08_ter D_00E04928[9];//or 8
//D_00E04940
//struct t_wm_local_08_ter D_00E04948[]
unsigned char D_00E04970[0x20][0x1200];//0x24000
struct t_wm_local_08_ter *D_00E28970;
//00E28974
struct t_wm_local_08_bis D_00E28978[0x40];//or 0x3f?
struct t_wm_local_08_bis *D_00E28B78;
struct t_wm_local_08_ter *D_00E28B7C;
struct t_wm_local_08_ter D_00E28B80[0x14];//or 0x13?
int D_00E28C20;
struct t_wm_local_08_ter *D_00E28C24;
struct t_wm_local_08_ter *D_00E28C28;
int D_00E28C2C;
struct VECTOR D_00E28C30;//something size 0x10
int D_00E28C40;
int D_00E28C44;
char D_00E28C48[0x64];//debug string
int D_00E28CAC;
struct t_wm_local_08_ter *D_00E28CB0;
int D_00E28CB4;
int D_00E28CB8;
int D_00E28CBC;
int D_00E28CC0;
struct t_wm_local_18 *D_00E28CC4;
int D_00E28CC8;
struct t_wm_local_18 *D_00E28CCC;
struct t_wm_local_18 *D_00E28CD0;
int D_00E28CD4;
struct t_wm_local_08_bis *D_00E28CD8;
int D_00E28CDC;
//D_00E28CE0
////////////////////////////////////////
//some inflate function[world map]?
void C_0074FFC0(unsigned char *bp08, unsigned char *bp0c) {
	struct {
		unsigned char *local_8;
		unsigned char *local_7;
		int local_6;
		void *local_5;
		int local_4;
		int local_3;
		int local_2;
		unsigned char *local_1;
	}lolo;

	lolo.local_3 = 0;
	lolo.local_5 = bp08 + 3 + *(int *)bp08;
	bp08 += sizeof(int);
	lolo.local_7 = bp0c;
	while(1) {
		if(lolo.local_3 == 0) {
			lolo.local_3 = 8;
			if(bp08 >= lolo.local_5)
				break;
			lolo.local_2 = *(bp08 ++);
		}
		if(lolo.local_2 & 1) {
			if(bp08 >= lolo.local_5)
				break;
			*(bp0c ++) = *(bp08 ++);
		} else {
			if(bp08 >= lolo.local_5)
				break;
			lolo.local_6 = *(bp08 ++);
			lolo.local_4 = *(bp08 ++);
			lolo.local_6 |= (lolo.local_4 & 0xf0) << 4;
			lolo.local_8 = bp0c + 3 + (lolo.local_4 & 0xf);
			lolo.local_1 = bp0c - ((bp0c - lolo.local_7 - (lolo.local_6 - 0xfee)) & 0xfff);
			while(lolo.local_1 < lolo.local_7) {
				*(bp0c ++) = 0;
				lolo.local_1 ++;
			}
			while(bp0c < lolo.local_8) {
				*(bp0c ++) = *(lolo.local_1 ++);
			}
		}
		lolo.local_2 >>= 1;
		lolo.local_3 --;
	}
}

void C_00750134(struct VECTOR *bp08, struct SVECTOR *bp0c, short *bp10, short *bp14) {
	if(bp10) {
		*bp10 = bp08->f_00 >> 0xd;
		if(*bp10 < 0)
			*bp10 += 0x24;
		else if(*bp10 >= 0x24)
			*bp10 -= 0x24;
	}
	if(bp14) {
		*bp14 = bp08->f_08 >> 0xd;
		if(*bp14 < 0)
			*bp14 += 0x1c;
		else if(*bp14 >= 0x1c)
			*bp14 -= 0x1c;
	}
	if(bp0c) {
		bp0c->f_00 = bp08->f_00 & 0x1fff;
		bp0c->f_02 = 0;
		bp0c->f_04 = bp08->f_08 & 0x1fff;
	}
}

void C_00750202(struct VECTOR *bp08) {
	if(bp08) {//else 0075027A
		if(bp08->f_00 >= 0x48000)
			bp08->f_00 -= 0x48000;
		else if(bp08->f_00 < 0)
			bp08->f_00 += 0x48000;
		if(bp08->f_08 >= 0x38000)
			bp08->f_08 -= 0x38000;
		else if(bp08->f_08 < 0)
			bp08->f_08 += 0x38000;
	}
}

void C_0075027C(struct VECTOR *bp08, int bp0c) {
	int local_2;
	int local_1;

	if(C_0074D30F() != 2) {//else 00750427
		if(bp0c < 0)
			D_00E28CC8 = 0;
		else if(D_00E04910)
			D_00E28CC8 |= bp0c;
		if(D_00E28CC8) {//else 00750403
			if(bp08->f_00 - D_00E04918.f_00 > 0x24000)
				D_00E04918.f_00 += 0x48000;
			else if(bp08->f_00 - D_00E04918.f_00 < -0x24000)
				D_00E04918.f_00 -= 0x48000;
			if(bp08->f_08 - D_00E04918.f_08 > 0x1c000)
				D_00E04918.f_08 += 0x38000;
			else if(bp08->f_08 - D_00E04918.f_08 < -0x1c000)
				D_00E04918.f_08 -= 0x38000;
			D_00E04918.f_00 = (D_00E04918.f_00 * 3 + bp08->f_00) >> 2;
			D_00E04918.f_08 = (D_00E04918.f_08 * 3 + bp08->f_08) >> 2;
			C_00750202(&D_00E04918);
			if(bp08->f_00 - D_00E04918.f_00 > 0) local_1 = bp08->f_00 - D_00E04918.f_00; else local_1 = -(bp08->f_00 - D_00E04918.f_00);
			if(bp08->f_08 - D_00E04918.f_08 > 0) local_2 = bp08->f_08 - D_00E04918.f_08; else local_2 = -(bp08->f_08 - D_00E04918.f_08);
			D_00E28CC8 = (local_1 + local_2) > 0xa;
		} else {//else 00750427
			D_00E04918 = *bp08;//0x10
		}
	}
}

void C_0075042B(struct VECTOR *bp08) {
	if(bp08)
		*bp08 = D_00E04918;//0x10
}

int C_0075045C() {
	return D_00E28CD4;
}

void C_00750466(int bp08) {
	D_00E28CD4 = bp08;
}

void C_007504D7(void);
void C_007505D7(void);
void C_00750641(void);

void C_00750473() {
	C_007504D7();
	C_007505D7();
	C_00750641();
	D_00E04604 = 0;
	D_00E28CDC = 0;
	D_00E28CD0 = 0;
	D_00E04608 = 0;
	D_00E28CBC = 1;
	D_00E28CC0 = 0;
	D_00E28C2C = 0;
	D_00E28CD4 = 0;
}

void C_007504D7() {
	short i;

	D_00E045FC = (unsigned char (*)[0xb800])D_00E2D5F8;
	//-- --
	for(i = 0; i < 8; i ++)
		D_00E04928[i].pNext = &(D_00E04928[i + 1]);
	D_00E04928[i].pNext = 0;
	D_00E28970 = D_00E04928;

	D_00E28C28 =
	D_00E28CB0 = 0;
	//-- --
	for(i = 0; i < 0x13; i ++)
		D_00E28B80[i].pNext = &(D_00E28B80[i + 1]);
	D_00E28B80[i].pNext = 0;
	D_00E28B7C = D_00E28B80;

	D_00E28C24 = 0;
	D_00E28CAC = 0;
	D_00E28C40 = 0;
	D_00E28C20 = 0;
	D_00E04600 = -1;
	D_00E28CB4 = 0;
}

void C_007505D7() {
	short i;

	for(i = 0; i < 0x3f; i ++)
		D_00E28978[i].pNext = &(D_00E28978[i + 1]);
	D_00E28978[i].pNext = 0;
	D_00E28CD8 = D_00E28978;

	D_00E28B78 = 0;
	D_00E04910 = 0;
}

void C_00750641() {
	short i;

	for(i = 0; i < 0x1f; i ++)
		D_00E04610[i].pNext = &(D_00E04610[i + 1]);
	D_00E04610[i].pNext = 0;
	D_00E28CCC = D_00E04610;

	D_00E045F8 =
	D_00E28CC4 = 0;
}

void C_007506C0(void);

void C_007506B6() {
	C_007506C0();
}

void C_007506C0() {
	struct t_wm_local_08_ter *local_2;
	struct t_wm_local_08_ter *local_1;

	D_00E28CBC = 0;
	if(D_00E04600 >= 0 && D_00E28CAC >= D_00DFC480 * 5) {
		for(
			local_2 = 0, local_1 = D_00E28CB0;
			local_1 && local_1 != &(D_00E04928[D_00E04600]);
			local_2 = local_1, local_1 = local_1->pNext
		);
		if(local_1 == 0)
			C_0074C9A0(0xd);//<empty>:some error management?
		if(local_2)
			local_2->pNext = local_1->pNext;
		else
			D_00E28CB0 = local_1->pNext;
		local_1->pNext = D_00E28970;
		D_00E28970 = local_1;
		D_00E28CAC = 0;
		D_00E04600 = -1;
	}
}

void C_00750784() {
	D_00E28CBC = 1;
}

int __00750793() {
	return D_00E28CBC;
}

void C_007509B2(struct VECTOR *);
void C_00750D99(short, short);
void C_007511CD(void );
short C_007512EA(void);
void C_00751408(void);
void C_0075164A(struct VECTOR *, short);
void C_00751EFC(struct VECTOR *, struct VECTOR *, struct VECTOR *, short);
void C_00753348(void);//<empty>

void C_0075079D(short bp08, int bp0c) {
	struct {
		short local_21; char __ocal_21[2];
		int local_20;
		short local_19; char __ocal_19[2];
		struct SVECTOR local_18;
		struct VECTOR local_16;
		struct VECTOR local_12;
		struct VECTOR local_8;
		struct VECTOR local_4;
	}lolo;

	C_007616B3();
	C_00762798(&lolo.local_8);
	C_00762802(&lolo.local_4);
	if(D_00E28CBC) {//else 00750922
		lolo.local_18.f_00 =
		lolo.local_18.f_02 = 0;
		lolo.local_18.f_04 = -0x2000;//0xe000
		C_00753D00(&lolo.local_18, -bp08);
		lolo.local_16.f_00 = lolo.local_8.f_00 + lolo.local_18.f_00;
		lolo.local_16.f_04 = lolo.local_8.f_04;
		lolo.local_16.f_08 = lolo.local_8.f_08 + lolo.local_18.f_04;
		if(lolo.local_16.f_00 < 0)
			lolo.local_16.f_00 += 0x48000;
		else if(lolo.local_16.f_00 >= 0x48000)
			lolo.local_16.f_00 -= 0x48000;
		if(lolo.local_16.f_08 < 0)
			lolo.local_16.f_08 += 0x38000;
		else if(lolo.local_16.f_08 >= 0x38000)
			lolo.local_16.f_08 -= 0x38000;
		C_007509B2(&lolo.local_16);
		C_0075164A(&lolo.local_8, bp08);
		C_00750134(&lolo.local_16, 0, &lolo.local_19, &lolo.local_21);
		C_00750D99(lolo.local_19, lolo.local_21);
		C_007511CD();
		C_00751408();
		//-- --
		lolo.local_20 = D_00E28C40;
		D_00E28C40 = /*lolo.local_22*/(C_007512EA() > 2)?D_00E28C40 + 1:0;
		if(lolo.local_20 < 0x12c && D_00E28C40 >= 0x12c)
			C_0074D955(1);
		else if(lolo.local_20 >= 0x12c && D_00E28C40 == 0)
			C_0074D955(4);
		//-- --
	}
	if(C_00766B53() == 2)
		C_00766417(0);
	else if(D_00E28CC0 == 1)
		C_00766417(D_00E28C2C);
	C_00762798(&lolo.local_12);
	D_00E37D28 = 0x157C;
	D_00E37524 = C_0074D330() == 2?0x3e80:0;
	if(bp0c)
		C_00751EFC(&lolo.local_4, &lolo.local_8, &lolo.local_12, bp08);
	if(C_0074D4DC())
		C_00753348();//<empty>
}

short C_00750C20(short, short);
struct t_wm_local_08_ter *C_00750C84(struct t_wm_local_08_ter *);

void C_007509B2(struct VECTOR *bp08) {
	struct {
		int bp_2c;//local_11
		int bp_28;//local_10
		int bp_24;//local_9
		int bp_20;
		int bp_1c;//local_7
		struct t_wm_local_08_ter *bp_18;
		int bp_14;//local_5
		struct t_wm_local_08_ter *bp_10;
		struct t_wm_local_08_ter *bp_0c;//local_3
		struct t_wm_local_08_ter *bp_08;
		struct t_wm_local_08_ter *bp_04;
	}lolo;

	lolo.bp_14 = (bp08->f_00 - 0x4000) / 0x8000;
	lolo.bp_28 = (bp08->f_08 - 0x4000) / 0x8000;
	lolo.bp_1c =  (bp08->f_00 + 0x4000) / 0x8000;
	lolo.bp_2c =  (bp08->f_08 + 0x4000) / 0x8000;
	lolo.bp_0c = 0;
	for(lolo.bp_24 = lolo.bp_28; lolo.bp_24 <= lolo.bp_2c; lolo.bp_24 ++) {
		for(lolo.bp_20 = lolo.bp_14; lolo.bp_20 <= lolo.bp_1c; lolo.bp_20 ++) {
			lolo.bp_08 = D_00E28B7C;
			if(lolo.bp_08 == 0)
				C_0074C9A0(0xa);//<empty>:some error management?
			D_00E28B7C = lolo.bp_08->pNext;
			lolo.bp_08->pNext = lolo.bp_0c;
			lolo.bp_0c = lolo.bp_08;
			lolo.bp_08->f_04 = C_00750C20(lolo.bp_20, lolo.bp_24);
		}
	}
	lolo.bp_18 = 0;
	lolo.bp_04 = D_00E28C28;
	while(lolo.bp_04) {
		lolo.bp_10 = 0;
		for(lolo.bp_08 = lolo.bp_0c; lolo.bp_08 && lolo.bp_08->f_04 != lolo.bp_04->f_04; lolo.bp_10 = lolo.bp_08, lolo.bp_08 = lolo.bp_08->pNext);
		if(lolo.bp_08) {//else 00750B66
			if(lolo.bp_10)
				lolo.bp_10->pNext = lolo.bp_08->pNext;
			else
				lolo.bp_0c = lolo.bp_08->pNext;
			lolo.bp_08->pNext = D_00E28B7C;
			D_00E28B7C = lolo.bp_08;
			if(lolo.bp_18) {
				lolo.bp_18->pNext = lolo.bp_04->pNext;
				lolo.bp_04->pNext = D_00E28C28;
				D_00E28C28 = lolo.bp_04;
				lolo.bp_04 = lolo.bp_18->pNext;
			} else {
				lolo.bp_18 = lolo.bp_04;
				lolo.bp_04 = lolo.bp_04->pNext;
			}
		} else {
			lolo.bp_18 = lolo.bp_04;
			lolo.bp_04 = lolo.bp_04->pNext;
		}
	}
	for(lolo.bp_04 = D_00E28CB0; lolo.bp_04; lolo.bp_04 = lolo.bp_04->pNext) {
		lolo.bp_10 = 0;
		for(lolo.bp_08 = lolo.bp_0c; lolo.bp_08 && lolo.bp_08->f_04 != lolo.bp_04->f_04; lolo.bp_10 = lolo.bp_08, lolo.bp_08 = lolo.bp_08->pNext);
		if(lolo.bp_08) {
			if(lolo.bp_10)
				lolo.bp_10->pNext = lolo.bp_08->pNext;
			else
				lolo.bp_0c = lolo.bp_08->pNext;
			lolo.bp_08->pNext = D_00E28B7C;
			D_00E28B7C = lolo.bp_08;
		}
	}
	for(lolo.bp_08 = lolo.bp_0c; lolo.bp_08; lolo.bp_08 = C_00750C84(lolo.bp_08));
}

short C_00750C20(short bp08, short bp0c) {
	if(bp08 < 0)
		bp08 += 9;
	if(bp08 >= 9)
		bp08 -= 9;
	if(bp0c < 0)
		bp0c += 7;
	if(bp0c >= 7)
		bp0c -= 7;

	return bp0c * 9 + bp08;
}

struct t_wm_local_08_ter *C_00750D06(void);

struct t_wm_local_08_ter *C_00750C84(struct t_wm_local_08_ter *bp08) {
	struct t_wm_local_08_ter *local_2;
	struct t_wm_local_08_ter *local_1;

	local_2 = 0;
	local_1 = C_00750D06();
	if(local_1) {
		bp08->f_06 = (local_1 - D_00E04928);
		D_00E04928[bp08->f_06].f_04 = bp08->f_04;
		local_2 = bp08->pNext;
		bp08->pNext = D_00E28C24;
		D_00E28C24 = bp08;
	} else {
		local_2 = bp08->pNext;
		bp08->pNext = D_00E28B7C;
		D_00E28B7C = bp08;
	}

	return local_2;
}

struct t_wm_local_08_ter *C_00750D06() {
	struct t_wm_local_08_ter *local_2;
	struct t_wm_local_08_ter *local_1;
	
	local_1 = 0;
	if(D_00E28970) {
		local_1 = D_00E28970;
		D_00E28970 = local_1->pNext;
	} else {
		local_1 = D_00E28C28;
		if(local_1) {
			for(local_2 = 0; local_1->pNext; local_2 = local_1, local_1 = local_1->pNext);
			if(local_2)
				local_2->pNext = 0;
			else
				local_1 = 0;
		}
	}
	if(local_1) {
		local_1->pNext = D_00E28CB0;
		D_00E28CB0 = local_1;
	}

	return local_1;
}

void C_00750EFA(struct t_wm_local_08_ter *, struct t_wm_local_08_ter *);

void C_00750D99(short bp08, short bp0c) {
	struct {
		int local_10;
		struct t_wm_local_08_ter *local_9;
		int local_8;
		struct t_wm_local_08_ter *local_7;
		int local_6;
		int local_5;
		int local_4;
		struct t_wm_local_08_ter *local_3;
		struct t_wm_local_08_ter *local_2;
		int local_1;
	}lolo;

	if(D_00E28CAC == 0 && D_00E28C24 && C_007538C9(0)) {
		lolo.local_7 =
		lolo.local_9 = 0;
		lolo.local_8 = 0x7fff;
		lolo.local_3 = 0;
		for(lolo.local_2 = D_00E28C24; lolo.local_2; lolo.local_3 = lolo.local_2, lolo.local_2 = lolo.local_2->pNext) {
			lolo.local_5 = lolo.local_2->f_04 / 4;
			lolo.local_4 = lolo.local_2->f_04 - lolo.local_5 * 4;
			lolo.local_6 = /*lolo.local_11*/inline_abs(lolo.local_4 - bp08);
			if(lolo.local_6 > 0x12)
				lolo.local_6 = 0x24 - lolo.local_6;
			lolo.local_10 = /*lolo.local_12*/inline_abs(lolo.local_5 - bp0c);
			if(lolo.local_10 > 0xe)
				lolo.local_10 = 0x1c - lolo.local_10;
			lolo.local_1 = lolo.local_6 + lolo.local_10;
			if(lolo.local_8 > lolo.local_1) {
				lolo.local_8 = lolo.local_1;
				lolo.local_7 = lolo.local_2;
				lolo.local_9 = lolo.local_3;
			}
		}
		if(lolo.local_7 == 0)
			C_0074C9A0(0x22);//<empty>:some error management?
		C_00750EFA(lolo.local_7, lolo.local_9);
	}
}

void C_00750F3C(struct t_wm_local_08_ter *);

void C_00750EFA(struct t_wm_local_08_ter *bp08, struct t_wm_local_08_ter *bp0c) {
	if(bp0c)
		bp0c->pNext = bp08->pNext;
	else
		D_00E28C24 = bp08->pNext;
	C_00750F3C(bp08);
	bp08->pNext = D_00E28B7C;
	D_00E28B7C = bp08;
}

void C_007512C2(void);

void C_00750F3C(struct t_wm_local_08_ter *bp08) {
	struct {
		int local_6;
		int local_5;
		int local_4;
		int local_3;
		int local_2;
		int local_1;
	}lolo;

	lolo.local_2 = C_0074D330();
	lolo.local_1 = 
	D_00E28C20 = /*lolo.local_13*/(lolo.local_2 == 0)?
		/*lolo.local_7*/(D_00E28CB4 > 0 && bp08->f_04 == 0x32)?0x3f:
		/*lolo.local_8*/(D_00E28CB4 > 1 && bp08->f_04 == 0x29)?0x40:
		/*lolo.local_9*/(D_00E28CB4 > 1 && bp08->f_04 == 0x2a)?0x41:
		/*lolo.local_10*/(D_00E28CB4 > 2 && bp08->f_04 == 0x3c)?0x42:
		/*lolo.local_11*/(D_00E28CB4 > 3 && bp08->f_04 == 0x2f)?0x43:
		/*lolo.local_12*/(D_00E28CB4 > 3 && bp08->f_04 == 0x30)?0x44:bp08->f_04
		:
		bp08->f_04
	;
	if(lolo.local_2 == 2) {//else 007510D7
		lolo.local_4 = D_00E28C20 / 9 - 2;
		if(lolo.local_4 < 0)
			lolo.local_4 += 4;
		else if(lolo.local_4 > 3)
			lolo.local_4 -= 4;
		lolo.local_3 = D_00E28C20 % 9 - 3;
		if(lolo.local_3 < 0)
			lolo.local_3 += 3;
		else if(lolo.local_3 > 2)
			lolo.local_3 -= 3;
		lolo.local_1 = lolo.local_4 * 3 + lolo.local_3;
	} else if(lolo.local_2 == 3) {//else 0075116B
		lolo.local_6 = D_00E28C20 / 9;
		if(lolo.local_6 >= 3)
			lolo.local_6 -= 7;
		if(lolo.local_6 < 0)
			lolo.local_6 += 2;
		else if(lolo.local_6 > 1)
			lolo.local_6 -= 2;
		lolo.local_5 = D_00E28C20 % 9;
		if(lolo.local_5 >= 4)
			lolo.local_5 -= 9;
		if(lolo.local_5 < 0)
			lolo.local_5 += 2;
		else if(lolo.local_5 > 1)
			lolo.local_5 -= 2;
		lolo.local_1 = lolo.local_6 * 2 + lolo.local_5;
	}
	C_007593CD(C_0074CA00(0, lolo.local_2), lolo.local_1 * 0xb800, 0xb800, D_00E045FC[bp08->f_06], 0);//wmfile:read file
	D_00E28CAC = D_00DFC480 * 5;
	D_00E04600 = bp08->f_06;
	C_007512C2();
}

void C_00751322(struct t_wm_local_08_ter *);

void C_007511CD() {
	struct t_wm_local_08_ter *local_2;
	struct t_wm_local_08_ter *local_1;

	if(D_00E28CAC < D_00DFC480 * 5 && D_00E04600 >= 0) {//else 00751285
		for(local_2 = 0, local_1 = D_00E28CB0; local_1 && local_1 != &(D_00E04928[D_00E04600]); local_2 = local_1, local_1 = local_1->pNext);
		if(local_1 == 0)
			C_0074C9A0(0xb);//<empty>:some error management?
		if(local_2)
			local_2->pNext = local_1->pNext;
		else
			D_00E28CB0 = local_1->pNext;
		local_1->pNext = D_00E28C28;
		D_00E28C28 = local_1;
		C_00751322(local_1);
		D_00E04600 = -1;
	}
	D_00E28CAC -= /*local_3*/(D_00E28CAC && D_00E28CAC < D_00DFC480 * 5);
}

void C_007512C2() {
	if(D_00E04600 >= 0) {
		D_00E28CAC = D_00DFC480 * 5 - 1;
		C_0075395E(0);
	}
}

short C_007512EA() {
	int local_2;
	struct t_wm_local_08_ter *local_1;

	for(local_2 = 0, local_1 = D_00E28CB0; local_1; local_2 ++, local_1 = local_1->pNext);

	return local_2;
}

void C_00751374(struct t_wm_local_18 *);

void C_00751322(struct t_wm_local_08_ter *bp08) {
	struct t_wm_local_18 *local_1;

	for(local_1 = D_00E28CC4; local_1; local_1 = local_1->pNext) {
		if((local_1->f_12 >> 2) * 9 + (local_1->f_10 >> 2) == bp08->f_04)
			C_00751374(local_1);
	}
}

void C_00751374(struct t_wm_local_18 *bp08) {
	struct t_wm_local_08_bis *local_1;

	for(local_1 = D_00E28B78; local_1 && (local_1->f_04->f_10 != bp08->f_10 || local_1->f_04->f_12 != bp08->f_12); local_1 = local_1->pNext);
	if(local_1 == 0) {
		if(D_00E28CD8 == 0)
			C_0074C9A0(0x16);//<empty>:some error management?
		local_1 = D_00E28CD8;
		D_00E28CD8 = local_1->pNext;
		local_1->pNext = D_00E28B78;
		D_00E28B78 = local_1;
		local_1->f_04 = bp08;
	}
}

void C_0075155A(struct t_wm_local_18 *, struct t_wm_local_08_ter *);

void C_00751408() {
	struct {
		struct t_wm_local_08_ter *local_6;
		int local_5;
		struct t_wm_local_18 *local_4;
		int local_3;
		struct t_wm_local_08_bis *local_2;
		struct t_wm_local_18 *local_1;
	}lolo;

	for(lolo.local_3 = 0; D_00E28B78 && lolo.local_3 == 0; lolo.local_3 = D_00E04910) {
		lolo.local_2 = D_00E28B78;
		if(lolo.local_2->f_04 == 0)
			C_0074C9A0(0xc);//<empty>:some error management?
		lolo.local_5 = (lolo.local_2->f_04->f_12 >> 2) * 9 + (lolo.local_2->f_04->f_10 >> 2);
		for(lolo.local_6 = D_00E28C28; lolo.local_6 && lolo.local_6->f_04 != lolo.local_5; lolo.local_6 = lolo.local_6->pNext);
		if(lolo.local_6) {//else 00751547
			C_0075155A(lolo.local_2->f_04, lolo.local_6);
			lolo.local_4 = 0;
			for(lolo.local_1 = D_00E28CC4; lolo.local_1 && lolo.local_1 != lolo.local_2->f_04; lolo.local_4 = lolo.local_1, lolo.local_1 = lolo.local_1->pNext);
			if(lolo.local_1 == 0)
				C_0074C9A0(0x17);//<empty>:some error management?
			if(lolo.local_4)
				lolo.local_4->pNext = lolo.local_1->pNext;
			else
				D_00E28CC4 = lolo.local_1->pNext;
			lolo.local_1->pNext = D_00E045F8;
			D_00E045F8 = lolo.local_1;
			D_00E28B78 = lolo.local_2->pNext;
			lolo.local_2->pNext = D_00E28CD8;
			D_00E28CD8 = lolo.local_2;
		}
	}
	D_00E04910 = 1;
}

void C_0075155A(struct t_wm_local_18 *bp08, struct t_wm_local_08_ter *bp0c) {
	struct {
		short *local_3;
		unsigned char *local_2;
		unsigned *local_1;
	}lolo;

	lolo.local_1 = (unsigned *)D_00E045FC[bp0c - D_00E04928];
	lolo.local_2 = D_00E04970[bp08 - D_00E04610];
	lolo.local_1 += (lolo.local_1[(((bp08->f_12 & 3) << 2) | (bp08->f_10 & 3))] >> 2);
	C_0074FFC0((unsigned char *)lolo.local_1, lolo.local_2);//some inflate function[world map]?
	lolo.local_3 = (short *)lolo.local_2;
	bp08->f_04 = (struct t_wm_local_0c *)&(lolo.local_3[2]);
	bp08->f_14 = lolo.local_3[0];
	bp08->f_08 = (struct SVECTOR *)&(bp08->f_04[bp08->f_14]);
	bp08->f_0c = &(bp08->f_08[lolo.local_3[1]]);
	C_00760E1D(bp08->f_04, &(bp08->f_04[bp08->f_14]), 1);
}

struct t_wm_local_08_ter *C_007518F6(short);
int C_00751962(short);
int C_0075199C(void);
void C_00751AC4(struct VECTOR *, short, int [][5]);
int C_00751D44(struct t_wm_local_18 *, short, short, short *, short *);
struct t_wm_local_18 *C_00751E43(void);

void C_0075164A(struct VECTOR *bp08, short bp0c) {
	struct {
		struct t_wm_local_08_ter *bp_8c;
		short bp_88; char _p_88[2];
		int bp_84;
		short bp_80; char _p_80[2];//local_32
		short bp_7c; char _p_7c[2];//local_31
		short bp_78; char _p_78[2];//local_30
		int bp_74[5][5];//local_29
		short bp_10; char _p_10[2];//local_4
		struct t_wm_local_08_ter *bp_0c;
		short bp_08; char _p_08[2];
		struct t_wm_local_18 *bp_04;//local_1
	}lolo;

	if(C_0075199C() >= 0x10)
		return;
	C_00750134(bp08, 0, &lolo.bp_10, &lolo.bp_80);
	C_00751AC4(bp08, bp0c, lolo.bp_74);
	for(lolo.bp_04 = D_00E045F8; lolo.bp_04; lolo.bp_04 = lolo.bp_04->pNext) {
		if(C_00751D44(lolo.bp_04, lolo.bp_10, lolo.bp_80, &lolo.bp_78, &lolo.bp_7c))
			lolo.bp_74[lolo.bp_7c + 2][lolo.bp_78 + 2] = 0;
	}
	for(lolo.bp_04 = D_00E28CC4; lolo.bp_04; lolo.bp_04 = lolo.bp_04->pNext) {
		if(C_00751D44(lolo.bp_04, lolo.bp_10, lolo.bp_80, &lolo.bp_78, &lolo.bp_7c))
			lolo.bp_74[lolo.bp_7c + 2][lolo.bp_78 + 2] = 0;
	}
	for(lolo.bp_7c = 0; lolo.bp_7c < 5; lolo.bp_7c ++) {
		for(lolo.bp_78 = 0; lolo.bp_78 < 5; lolo.bp_78 ++) {
			if(lolo.bp_74[lolo.bp_7c][lolo.bp_78]) {//else 007518E8
				lolo.bp_88 = lolo.bp_78 + lolo.bp_10 - 2;
				if(lolo.bp_88 < 0)
					lolo.bp_88 += 0x24;
				else if(lolo.bp_88 >= 0x24)
					lolo.bp_88 -= 0x24;
				lolo.bp_08 = lolo.bp_7c + lolo.bp_80 - 2;
				if(lolo.bp_08 < 0)
					lolo.bp_08 += 0x1c;
				else if(lolo.bp_08 >= 0x1c)
					lolo.bp_08 -= 0x1c;
				lolo.bp_04 = C_00751E43();
				if(lolo.bp_04) {//else 007518E8
					lolo.bp_04->f_10 = lolo.bp_88;
					lolo.bp_04->f_12 = lolo.bp_08;
					lolo.bp_84 = (lolo.bp_08 >> 2) * 9 + (lolo.bp_88 >> 2);
					lolo.bp_8c = C_007518F6(lolo.bp_84);
					if(lolo.bp_8c) {
						C_00751374(lolo.bp_04);
					} else if(C_00751962(lolo.bp_84) == 0) {
						if(D_00E28B7C == 0)
							C_0074C9A0(0xf);//<empty>:some error management?
						lolo.bp_0c = D_00E28B7C;
						D_00E28B7C = lolo.bp_0c->pNext;
						lolo.bp_0c->f_04 = lolo.bp_84;
						C_00750C84(lolo.bp_0c);
					}
				}
			}
		}//end for
	}//end for
}

struct t_wm_local_08_ter *C_007518F6(short bp08) {
	struct t_wm_local_08_ter *local_2;
	struct t_wm_local_08_ter *local_1;

	for(local_2 = 0, local_1 = D_00E28C28; local_1 && local_1->f_04 != bp08; local_2 = local_1, local_1 = local_1->pNext);
	if(local_1 && local_2) {
		local_2->pNext = local_1->pNext;
		local_1->pNext = D_00E28C28;
		D_00E28C28 = local_1;
	}

	return local_1;
}

int C_00751962(short bp08) {
	struct t_wm_local_08_ter *local_1;

	for(local_1 = D_00E28CB0; local_1 && local_1->f_04 != bp08; local_1 = local_1->pNext);

	return local_1 != 0;
}

int C_0075199C() {
	struct {
		int local_5;
		struct t_wm_local_18 *local_4;
		struct t_wm_local_08_bis *local_3;
		struct t_wm_local_08_bis *local_2;
		struct t_wm_local_18 *local_1;
	}lolo;

	lolo.local_5 = 0;
	lolo.local_4 = 0;
	lolo.local_1 = D_00E28CC4;
	while(lolo.local_1) {
		if(lolo.local_1->f_16 ++ >= 0x96) {//else 00751AA1
			if(lolo.local_4)
				lolo.local_4->pNext = lolo.local_1->pNext;
			else
				D_00E28CC4 = lolo.local_1->pNext;
			lolo.local_1->pNext = D_00E28CCC;
			D_00E28CCC = lolo.local_1;
			for(lolo.local_3 = 0, lolo.local_2 = D_00E28B78; lolo.local_2 && lolo.local_2->f_04 != lolo.local_1; lolo.local_3 = lolo.local_2, lolo.local_2 = lolo.local_2->pNext);
			if(lolo.local_2) {//else 00751A80
				if(lolo.local_3)
					lolo.local_3->pNext = lolo.local_2->pNext;
				else
					D_00E28B78 = lolo.local_2->pNext;
				lolo.local_2->pNext = D_00E28CD8;
				D_00E28CD8 = lolo.local_2;
			}
			lolo.local_1 = /*lolo.local_6*/lolo.local_4?lolo.local_4->pNext:D_00E28CC4;
		} else {
			lolo.local_4 = lolo.local_1;
			lolo.local_1 = lolo.local_1->pNext;
			lolo.local_5 ++;
		}
	}

	return lolo.local_5;
}


void C_00751AC4(struct VECTOR *bp08, short bp0c, int bp10[][5]) {
	struct {//xb8
		struct VECTOR bp_ac;
		struct MATRIX bp_9c; char _p_9c[2];//local_39
		struct SVECTOR bp_7c;//local_31
		int bp_74[3+1];//local_29
		short bp_64; char _p_64[2];//local_25
		short bp_60; char _p_60[2];
		struct VECTOR bp_5c;//local_23
		int bp_4c;//local_19
		struct VECTOR bp_48;//local_18
		struct SVECTOR bp_38;//local_14
		struct VECTOR bp_30;//local_12
		struct VECTOR bp_20;
		struct VECTOR bp_10;//local_4
	}lolo;

	lolo.bp_7c.f_00 = 0;
	lolo.bp_7c.f_02 = 0;
	lolo.bp_7c.f_04 = -0x1000;
	lolo.bp_7c.f_06 = 0;
	lolo.bp_38.f_00 = 0;
	lolo.bp_38.f_02 = 0;
	lolo.bp_38.f_04 = 0;
	lolo.bp_38.f_06 = 0;
	lolo.bp_48.f_00 = 0;
	lolo.bp_48.f_04 = 0;
	lolo.bp_48.f_08 = 0;
	lolo.bp_48.f_0c = 0;
	psx_TransMatrix(&lolo.bp_9c, &lolo.bp_48);
	psx_SetTransMatrix(&lolo.bp_9c);
	lolo.bp_38.f_02 = -bp0c + 0x380;
	psx_RotMatrixXYZ(&lolo.bp_38, &lolo.bp_9c);
	psx_SetRotMatrix(&lolo.bp_9c);
	psx_RotTrans(&lolo.bp_7c, &lolo.bp_10, &lolo.bp_4c);
	lolo.bp_38.f_02 = -bp0c - 0x380;
	psx_RotMatrixXYZ(&lolo.bp_38, &lolo.bp_9c);
	psx_SetRotMatrix(&lolo.bp_9c);
	psx_RotTrans(&lolo.bp_7c, &lolo.bp_30, &lolo.bp_4c);
	lolo.bp_74[0] = (bp08->f_00 & 0x1fff) - 0x1000;
	lolo.bp_74[1] = 0;
	lolo.bp_74[2] = (bp08->f_08 & 0x1fff) - 0x1000;
	lolo.bp_5c.f_04 = 0;
	for(lolo.bp_64 = -2; lolo.bp_64 <= 2; lolo.bp_64 ++) {
		for(lolo.bp_60 = -2; lolo.bp_60 <= 2; lolo.bp_60 ++) {
			if(inline_abs(lolo.bp_60) <= 1 && inline_abs(lolo.bp_64) <= 1) {//else 00751CAF
				bp10[lolo.bp_64 + 2][lolo.bp_60 + 2] = 1;
			} else {
				lolo.bp_5c.f_00 = (lolo.bp_60 << 0xd) - lolo.bp_74[0];
				lolo.bp_5c.f_08 = (lolo.bp_64 << 0xd) - lolo.bp_74[2];
				psx_OuterProduct12(&lolo.bp_10, &lolo.bp_5c, &lolo.bp_ac);
				psx_OuterProduct12(&lolo.bp_30, &lolo.bp_5c, &lolo.bp_20);
				bp10[lolo.bp_64 + 2][lolo.bp_60 + 2] = /*lolo.bp_b8*/(lolo.bp_ac.f_04 < 0 && lolo.bp_20.f_04 > 0);
			}
		}
	}
}

int C_00751D44(struct t_wm_local_18 *bp08, short bp0c, short bp10, short *bp14, short *bp18) {
	*bp14 = bp08->f_10 - bp0c;
	if(*bp14 > 0x12)
		*bp14 -= 0x24;
	else if(*bp14 < -0x12)
		*bp14 += 0x24;
	*bp18 = bp08->f_12 - bp10;
	if(*bp18 > 0xe)
		*bp18 -= 0x1c;
	else if(*bp18 < -0xe)
		*bp18 += 0x1c;

	return inline_abs(*bp14) <= 2 && inline_abs(*bp18) <= 2;
}

struct t_wm_local_18 *C_00751E43() {
	struct t_wm_local_18 *local_2;
	struct t_wm_local_18 *local_1;

	local_1 = 0;
	if(D_00E28CCC) {
		local_1 = D_00E28CCC;
		D_00E28CCC = local_1->pNext;
	} else if(D_00E045F8) {//else 00751ED3
		for(local_2 = 0, local_1 = D_00E045F8; local_1->pNext; local_2 = local_1, local_1 = local_1->pNext);
		if(local_2)
			local_2->pNext = 0;
		else
			D_00E045F8 = 0;
		C_00761644(local_1->f_10, local_1->f_12);
	}
	if(local_1) {
		local_1->pNext = D_00E28CC4;
		D_00E28CC4 = local_1;
		local_1->f_16 = 0;
	}

	return local_1;
}

struct t_wm_30_temp {
	struct VECTOR f_00;
	//	int f_00;
	//	char __04[4];
	//	int f_08;
	//	char __0c[4];
	struct SVECTOR f_10;
	struct t_wm_local_18 *f_18;
	struct t_wm_local_0c *f_1c;
	short f_20;
	short f_22;
	short f_24;
	short f_26;
	short f_28;
	short f_2a;
	char __2c[0x30 - 0x2c];
};

struct t_wm_f0_temp {
	struct t_wm_30_temp f_00[5];
};

struct t_wm_30_temp *C_00752D02(struct t_wm_local_18 *, struct t_wm_f0_temp *, short, short);
void C_007530B3(struct t_wm_f0_temp *, struct SVECTOR *, struct SVECTOR *, int);

void C_00751EFC(struct VECTOR *bp08, struct VECTOR *bp0c, struct VECTOR *bp10, short bp14) {
	struct {//x1034
		//local_1036 and above is for compiler
		struct t_wm_f0_temp bp_102c[2][8];//local_1035
		struct MATRIX bp_12c; char _ocal_75[2];//local_75
		struct t_wm_f0_temp **bp_10c;//local_67
		int local_66;
		short bp_104; char _p_104[2];//local_65
		struct SVECTOR bp_100;
		short bp_f8; char _p_f8[2];
		struct t_wm_f0_temp **bp_f4;//local_61
		short bp_f0; char _p_f0[2];
		struct t_wm_f0_temp *bp_ec;//local_59
		struct t_wm_f0_temp *bp_e8[2];//local_58
		//struct t_wm_f0_temp *bp_e4[1];//local_57
		struct t_wm_f0_temp *bp_e0[8];
		struct SVECTOR bp_c0;//local_48
		struct t_wm_local_18 *bp_b8;
		int bp_b4[5][5];
		short bp_50; char _p_50[2];//local_20
		struct VECTOR *bp_4c;//local_19
		struct SVECTOR bp_48;//local_18
		int local_16;
		struct t_wm_f0_temp **bp_3c;
		struct t_wm_30_temp *bp_38;
		struct VECTOR local_13;
		struct SVECTOR local_9;
		struct t_wm_local_18 *bp_1c;//local_7
		struct t_wm_local_18 *bp_18;//local_6
		short bp_14; char _p_14[2];//local_5
		short bp_10; char _p_10[2];//local_4
		struct SVECTOR bp_0c;//local_3
		struct t_wm_local_18 *bp_04;
	}lolo;

	lolo.bp_4c = 0;
	lolo.bp_1c = 0;
	lolo.bp_18 = 0;
	D_00E28CDC = 0;
	lolo.bp_c0.f_02 = 0;
	//-- --
	lolo.local_16 = bp10->f_00 - bp08->f_00;
	if(lolo.local_16 < -0x24000)
		lolo.local_16 += 0x48000;
	else if(lolo.local_16 >= 0x24000)
		lolo.local_16 -= 0x48000;
	lolo.bp_c0.f_00 = lolo.local_16;
	//-- --
	lolo.local_16 = bp10->f_08 - bp08->f_08;
	if(lolo.local_16 < -0x1c000)
		lolo.local_16 += 0x38000;
	else if(lolo.local_16 >= 0x1c000)
		lolo.local_16 -= 0x38000;
	lolo.bp_c0.f_04 = lolo.local_16;
	//-- --
	psx_TransMatrix(&lolo.bp_12c, bp08);
	lolo.local_9.f_00 =
	lolo.local_9.f_04 = 0;
	C_00750134(bp0c, &lolo.bp_100, &lolo.bp_14, &lolo.bp_10);
	C_0075027C(bp0c, 0);
	C_0075042B(&lolo.local_13);
	C_00750134(&lolo.local_13, &lolo.bp_0c, &lolo.bp_50, &lolo.bp_104);
	if(lolo.bp_50 - lolo.bp_14 > 0x12)
		lolo.bp_50 -= 0x24;
	else if(lolo.bp_50 - lolo.bp_14 < -0x12)
		lolo.bp_50 += 0x24;
	if(lolo.bp_104 - lolo.bp_10 > 0xe)
		lolo.bp_104 -= 0x1c;
	else if(lolo.bp_104 - lolo.bp_10 < -0xe)
		lolo.bp_104 += 0x1c;
	if(lolo.bp_50 > lolo.bp_14)
		lolo.bp_0c.f_00 += 0x2000;
	else if(lolo.bp_50 < lolo.bp_14)
		lolo.bp_0c.f_00 -= 0x2000;
	if(lolo.bp_104 > lolo.bp_10)
		lolo.bp_0c.f_04 += 0x2000;
	else if(lolo.bp_104 < lolo.bp_10)
		lolo.bp_0c.f_04 -= 0x2000;
	if(C_0074D4DC())
		sprintf(D_00E28C48, "PS%d%d%d%d.rsd  POS: %d %d", lolo.bp_14 / 10, lolo.bp_14 % 10, lolo.bp_10 / 10, lolo.bp_10 % 10, bp0c->f_00 & 0x1fff, bp0c->f_08 & 0x1fff);
	lolo.local_9.f_02 = 0;
	psx_SetTransMatrix(&lolo.bp_12c);
	lolo.local_16 = C_00761735() == 5?0x15e:0xc8;
	lolo.local_66 = /*lolo.local_1036*/(0x500 << ((D_00E28CC0 != 1 && D_00E28CD4 == 0)?0:1)) >> 3;
	for(lolo.bp_ec = &(lolo.bp_102c[0][0]); lolo.bp_ec < &(lolo.bp_102c[0][8]); lolo.bp_ec ++) {
		C_007530B3(lolo.bp_ec, &lolo.bp_c0, &lolo.local_9, lolo.local_16);
		lolo.local_9.f_02 += lolo.local_66;
	}
	lolo.local_9.f_02 = 0;
	for(lolo.bp_ec = &(lolo.bp_102c[1][0]); lolo.bp_ec < &(lolo.bp_102c[1][8]); lolo.bp_ec ++) {
		C_007530B3(lolo.bp_ec, &lolo.bp_c0, &lolo.local_9, lolo.local_16);
		lolo.local_9.f_02 -= lolo.local_66;
	}
	lolo.bp_e8[0] = &(lolo.bp_102c[0][0]);
	lolo.bp_10c = &(lolo.bp_e8[1]);
	lolo.bp_f4 = &(lolo.bp_e8[0]);
	while(lolo.bp_f4 < lolo.bp_10c) {
		lolo.bp_50 = (*lolo.bp_f4)->f_00[0].f_20;
		lolo.bp_104 = (*lolo.bp_f4)->f_00[0].f_22;
		//--
		if(lolo.bp_f4 == &(lolo.bp_e8[0]))
			C_00762D52();
		lolo.bp_f4 ++;
		//--
		lolo.bp_b8 = 0;
		for(lolo.bp_04 = D_00E045F8; lolo.bp_04 && (lolo.bp_04->f_10 != lolo.bp_50 || lolo.bp_04->f_12 != lolo.bp_104); lolo.bp_b8 = lolo.bp_04, lolo.bp_04 = lolo.bp_04->pNext);
		if(lolo.bp_04 == 0) {
			C_00762933();
			goto C_00752AB6;
		}
		if(lolo.bp_b8)
			lolo.bp_b8->pNext = lolo.bp_04->pNext;
		else
			D_00E045F8 = lolo.bp_04->pNext;
		lolo.bp_04->pNext = 0;
		if(lolo.bp_1c == 0) {
			lolo.bp_1c = 
			lolo.bp_18 = lolo.bp_04;
		}
		if(lolo.bp_18 == 0)
			C_0074C9A0(0x11);//<empty>:some error management?
		lolo.bp_18->pNext = lolo.bp_04;
		lolo.bp_18 = lolo.bp_04;
		C_00751D44(lolo.bp_04, lolo.bp_14, lolo.bp_10, &lolo.bp_f0, &lolo.bp_f8);
		lolo.bp_48.f_00 = (lolo.bp_f0 << 0xd) - lolo.bp_0c.f_00;
		lolo.bp_48.f_02 = -lolo.bp_0c.f_02;
		lolo.bp_48.f_04 = (lolo.bp_f8 << 0xd) - lolo.bp_0c.f_04;
		C_0074D33A(&lolo.bp_48);
		C_0075F0AD(lolo.bp_04->f_08, C_0074D4ED());
		psx_ReadRotMatrix(&lolo.bp_12c);
		//--
		if(lolo.bp_f4 == &(lolo.bp_e8[1]))
			C_00758DA5(lolo.bp_14, lolo.bp_10);
		//--
		lolo.bp_38 = C_00752D02(lolo.bp_04, lolo.bp_102c[D_00E28CB8], lolo.bp_50, lolo.bp_104);
		if(lolo.bp_38) {//else 00752546
			for(lolo.bp_3c = lolo.bp_f4; lolo.bp_3c < lolo.bp_10c && ((*lolo.bp_3c)->f_00[0].f_20 != lolo.bp_38->f_20 || (*lolo.bp_3c)->f_00[0].f_22 != lolo.bp_38->f_22); lolo.bp_3c ++);
			if(lolo.bp_3c >= lolo.bp_10c) {//else 00752546
				if(lolo.bp_10c < &(lolo.bp_e0[8])) {
					*(struct t_wm_30_temp **)lolo.bp_10c = lolo.bp_38;
					lolo.bp_10c ++;
				} else {
					C_0074C9A0(0x14);//<empty>:some error management?
				}
			}
		}
		lolo.bp_38 = C_00752D02(lolo.bp_04, lolo.bp_102c[(D_00E28CB8 == 0)], lolo.bp_50, lolo.bp_104);
		if(lolo.bp_38) {//else 0075260E
			for(lolo.bp_3c = lolo.bp_f4; lolo.bp_3c < lolo.bp_10c && ((*lolo.bp_3c)->f_00[0].f_20 != lolo.bp_38->f_20 || (*lolo.bp_3c)->f_00[0].f_22 != lolo.bp_38->f_22); lolo.bp_3c ++);
			if(lolo.bp_3c >= lolo.bp_10c) {//else 0075260E
				if(lolo.bp_10c < &(lolo.bp_e0[8])) {
					*(struct t_wm_30_temp **)lolo.bp_10c = lolo.bp_38;
					lolo.bp_10c ++;
				} else {
					C_0074C9A0(0x15);//<empty>:some error management?
				}
			}
		}
		for(lolo.bp_ec = &(lolo.bp_102c[0][0]); lolo.bp_ec < &(lolo.bp_102c[1][8]); lolo.bp_ec ++) {
			for(lolo.bp_38 = &(lolo.bp_ec->f_00[0]); lolo.bp_38 < &(lolo.bp_ec->f_00[5]); lolo.bp_38 ++) {
				if(lolo.bp_38->f_20 == lolo.bp_50 && lolo.bp_38->f_22 == lolo.bp_104 && lolo.bp_38->f_24 == 1)
					lolo.bp_38->f_24 = 4;
			}
		}
		psx_SetRotMatrix(&lolo.bp_12c);
		C_00762D74(lolo.bp_04);
		C_0074D33A(&lolo.bp_48);
		C_0075F263();
		C_0075F68C(lolo.bp_04->f_04, &(lolo.bp_04->f_04[lolo.bp_04->f_14]), lolo.bp_04->f_0c, C_0074C9AF(lolo.bp_04->f_14));
	}//end while
	for(lolo.bp_ec = &(lolo.bp_102c[D_00E28CB8][0]); lolo.bp_ec < &(lolo.bp_102c[D_00E28CB8][8]) && (lolo.bp_ec->f_00[0].f_24 != 2 || lolo.bp_ec->f_00[1].f_24 != 2 || lolo.bp_ec->f_00[2].f_24 != 2 || lolo.bp_ec->f_00[3].f_24 != 2 || lolo.bp_ec->f_00[4].f_24 != 2); lolo.bp_ec ++);
	if(lolo.bp_ec < &(lolo.bp_102c[D_00E28CB8][8])) {//else 00752898
		D_00E28C30 = lolo.bp_ec->f_00[0].f_00;
		D_00E28C30.f_04 = lolo.bp_ec->f_00[0].f_28;
		C_0076211B(lolo.bp_ec->f_00[0].f_2a);
		C_007624C5(&D_00E28C30);
		lolo.bp_4c = &D_00E28C30;
		if(D_00E04604) {
			D_00E04604 = 0;
			C_00756FF9(lolo.bp_ec->f_00[0].f_18, lolo.bp_ec->f_00[0].f_1c);
		}
		D_00E28CD0 = lolo.bp_ec->f_00[0].f_18;
		D_00E04608 = lolo.bp_ec->f_00[0].f_1c;
		D_00E38330 = lolo.bp_ec->f_00[0].f_1c;
		C_00761DF5(lolo.bp_ec->f_00[0].f_26);
		//goto 00752A60
	} else if(D_00E28C44 >= 8) {//else 00752A60
		for(lolo.bp_ec = &(lolo.bp_102c[!D_00E28CB8][0]); lolo.bp_ec < &(lolo.bp_102c[!D_00E28CB8][8]) && (lolo.bp_ec->f_00[0].f_24 != 2 || lolo.bp_ec->f_00[1].f_24 != 2 || lolo.bp_ec->f_00[2].f_24 != 2 || lolo.bp_ec->f_00[3].f_24 != 2 || lolo.bp_ec->f_00[4].f_24 != 2); lolo.bp_ec ++);
		if(lolo.bp_ec < &(lolo.bp_102c[(D_00E28CB8 == 0)][8])) {//else 00752A60
			D_00E28C30 = lolo.bp_ec->f_00[0].f_00;
			D_00E28C30.f_04 = lolo.bp_ec->f_00[0].f_28;
			C_0076211B(lolo.bp_ec->f_00[0].f_2a);
			C_007624C5(&D_00E28C30);
			lolo.bp_4c = &D_00E28C30;
			if(D_00E04604) {
				D_00E04604 = 0;
				C_00756FF9(lolo.bp_ec->f_00[0].f_18, lolo.bp_ec->f_00[0].f_1c);
			}
			D_00E28CD0 = lolo.bp_ec->f_00[0].f_18;
			D_00E04608 = lolo.bp_ec->f_00[0].f_1c;
			D_00E38330 = lolo.bp_ec->f_00[0].f_1c;
			C_00761DF5(lolo.bp_ec->f_00[0].f_26);
			D_00E28CB8 = !D_00E28CB8;
			D_00E28C44 = 0;
		}
	}
	D_00E28CDC = 1;
	if(lolo.bp_4c && D_00E28CC0)
		D_00E28CC0 = 0;
	else if(lolo.bp_4c == 0 && D_00E28CC0 == 2)
		D_00E28CC0 = 1;
	D_00E28CD4 -= D_00E28CD4 > 0;
C_00752AB6:
	if(lolo.bp_4c == 0) {
		C_007628B5();
		if(C_00762136() == 0xe)
			D_00E28CD4 = 5;
	}
	D_00E28C44 ++;
	C_00750134(bp0c, &lolo.bp_100, &lolo.bp_50, &lolo.bp_104);
	C_00751AC4(bp0c, bp14, lolo.bp_b4);
	lolo.bp_b8 = 0;
	lolo.bp_04 = D_00E045F8;
	while(lolo.bp_04) {
		if(C_00751D44(lolo.bp_04, lolo.bp_50, lolo.bp_104, &lolo.bp_f0, &lolo.bp_f8) && lolo.bp_b4[lolo.bp_f8 + 2][lolo.bp_f0 + 2]) {//else 00752CC2
			lolo.bp_48.f_00 = (lolo.bp_f0 << 0xd) - lolo.bp_0c.f_00;
			lolo.bp_48.f_02 = -lolo.bp_0c.f_02;
			lolo.bp_48.f_04 = (lolo.bp_f8 << 0xd) - lolo.bp_0c.f_04;
			C_0074D33A(&lolo.bp_48);
			C_0075F0AD(lolo.bp_04->f_08, C_0074D4ED());
			C_00762D74(lolo.bp_04);
			C_0074D33A(&lolo.bp_48);
			C_0075F263();
			C_0075F68C(lolo.bp_04->f_04, &(lolo.bp_04->f_04[lolo.bp_04->f_14]), lolo.bp_04->f_0c, C_0074C9AF(lolo.bp_04->f_14));
			if(lolo.bp_b8)
				lolo.bp_b8->pNext = lolo.bp_04->pNext;
			else
				D_00E045F8 = lolo.bp_04->pNext;
			lolo.bp_04->pNext = 0;
			if(lolo.bp_1c == 0) {
				lolo.bp_1c =
				lolo.bp_18 = lolo.bp_04;
			}
			if(lolo.bp_18 == 0)
				C_0074C9A0(0x13);//<empty>:some error management?
			lolo.bp_18->pNext = lolo.bp_04;
			lolo.bp_18 = lolo.bp_04;
			lolo.bp_04 = /*lolo.bp_1034*/lolo.bp_b8?lolo.bp_b8->pNext:D_00E045F8;
			continue;
		}
		lolo.bp_b8 = lolo.bp_04;
		lolo.bp_04 = lolo.bp_04->pNext;
	}//end while
	if(lolo.bp_1c && lolo.bp_18) {
		lolo.bp_18->pNext = D_00E045F8;
		D_00E045F8 = lolo.bp_1c;
	}
}

struct t_wm_30_temp *C_00752D02(struct t_wm_local_18 *bp08, struct t_wm_f0_temp *bp0c, short bp10, short bp14) {
	struct {
		int local_11;
		struct t_wm_30_temp *local_10;
		int local_9;
		struct t_wm_local_08 *local_8;
		int local_7;
		struct VECTOR local_6;
		struct t_wm_30_temp *local_2;
		int local_1;
	}lolo;

	lolo.local_1 = 0;
	lolo.local_11 = 4;
	lolo.local_10 = 0;
	C_00762798(&lolo.local_6);
	lolo.local_8 = C_007616E3();
	lolo.local_9 = C_0076170B();
	if(C_00766B53() == 2 && C_00761844() != 0) {//else 00752F21
		do {
			for(lolo.local_2 = &(bp0c[lolo.local_1].f_00[0]); lolo.local_2 < &(bp0c[lolo.local_1].f_00[5]); lolo.local_2 ++) {
				if(lolo.local_2->f_24 == 1) {//else 00752E61
					if(lolo.local_2->f_20 == bp10 && lolo.local_2->f_22 == bp14) {//else 00752E55
						lolo.local_2->f_18 = bp08;
						lolo.local_2->f_28 = lolo.local_6.f_04;
						if(C_0074CC07(bp08, &(lolo.local_2->f_10), lolo.local_8, &(lolo.local_2->f_28), &(lolo.local_2->f_1c), &(lolo.local_2->f_2a), lolo.local_9) && inline_abs(lolo.local_2->f_28 - lolo.local_6.f_04) < 0xc8)
							lolo.local_2->f_24 = 2;
						else
							lolo.local_2->f_24 = 3;
					} else if(lolo.local_10 == 0) {
						lolo.local_10 = lolo.local_2;
					}
				}
			}
			lolo.local_7 = /*lolo.local_13*/(bp0c[lolo.local_1].f_00[0].f_24 == 2 && bp0c[lolo.local_1].f_00[1].f_24 == 2 && bp0c[lolo.local_1].f_00[2].f_24 == 2 && bp0c[lolo.local_1].f_00[3].f_24 == 2 && bp0c[lolo.local_1].f_00[4].f_24 == 2);
			if(lolo.local_1 == 0 && lolo.local_7)
				break;
			lolo.local_1 ++;
			lolo.local_11 >>= 1;
		} while(lolo.local_1 < 8);
	} else {
		do {
			for(lolo.local_2 = &(bp0c[lolo.local_1].f_00[0]); lolo.local_2 < &(bp0c[lolo.local_1].f_00[5]); lolo.local_2 ++) {
				if(lolo.local_2->f_24 == 1) {
					if(lolo.local_2->f_20 == bp10 && lolo.local_2->f_22 == bp14) {//else 00752FE5
						lolo.local_2->f_18 = bp08;
						lolo.local_2->f_28 = lolo.local_6.f_04;
						if(C_0074CC07(bp08, &(lolo.local_2->f_10), lolo.local_8, &(lolo.local_2->f_28), &(lolo.local_2->f_1c), &(lolo.local_2->f_2a), lolo.local_9))
							lolo.local_2->f_24 = 2;
						else
							lolo.local_2->f_24 = 3;
					} else if(lolo.local_10 == 0) {
						lolo.local_10 = lolo.local_2;
					}
				}
			}
			lolo.local_7 = /*lolo.local_14*/(bp0c[lolo.local_1].f_00[0].f_24 == 2 && bp0c[lolo.local_1].f_00[1].f_24 == 2 && bp0c[lolo.local_1].f_00[2].f_24 == 2 && bp0c[lolo.local_1].f_00[3].f_24 == 2 && bp0c[lolo.local_1].f_00[4].f_24 == 2);
			if(lolo.local_1 == 0 && lolo.local_7)
				break;
			lolo.local_1 ++;
			lolo.local_11 >>= 1;
		} while(lolo.local_1 < 8);
	}

	return lolo.local_10;
}

void C_007530B3(struct t_wm_f0_temp *bp08, struct SVECTOR *bp0c, struct SVECTOR *bp10, int bp14) {
	struct {
		struct MATRIX local_14;
		struct VECTOR local_6;
		int local_2;
		struct t_wm_30_temp *local_1;
	}lolo;

	psx_RotMatrixXYZ(bp10, &lolo.local_14);
	psx_SetRotMatrix(&lolo.local_14);
	lolo.local_1 = &(bp08->f_00[0]);
	psx_RotTrans(bp0c, &lolo.local_6, &lolo.local_2);

	lolo.local_1->f_00 = lolo.local_6;
	C_00750134(&(lolo.local_1->f_00), &(lolo.local_1->f_10), &(lolo.local_1->f_20), &(lolo.local_1->f_22));
	lolo.local_1->f_24 = 1;
	lolo.local_1->f_28 = 0;
	lolo.local_1->f_1c = 0;
	lolo.local_1->f_26 = bp10->f_02;

	lolo.local_1 ++;

	lolo.local_1->f_00 = lolo.local_6;
	lolo.local_1->f_00.f_00 -= bp14;
	C_00750134(&(lolo.local_1->f_00), &(lolo.local_1->f_10), &(lolo.local_1->f_20), &(lolo.local_1->f_22));
	lolo.local_1->f_24 = 1;
	lolo.local_1->f_28 = 0;
	lolo.local_1->f_1c = 0;
	lolo.local_1->f_26 = bp10->f_02;

	lolo.local_1 ++;

	lolo.local_1->f_00 = lolo.local_6;
	lolo.local_1->f_00.f_00 += bp14;
	C_00750134(&(lolo.local_1->f_00), &(lolo.local_1->f_10), &(lolo.local_1->f_20), &(lolo.local_1->f_22));
	lolo.local_1->f_24 = 1;
	lolo.local_1->f_28 = 0;
	lolo.local_1->f_1c = 0;
	lolo.local_1->f_26 = bp10->f_02;

	lolo.local_1 ++;

	lolo.local_1->f_00 = lolo.local_6;
	lolo.local_1->f_00.f_08 -= bp14;
	C_00750134(&(lolo.local_1->f_00), &(lolo.local_1->f_10), &(lolo.local_1->f_20), &(lolo.local_1->f_22));
	lolo.local_1->f_24 = 1;
	lolo.local_1->f_28 = 0;
	lolo.local_1->f_1c = 0;
	lolo.local_1->f_26 = bp10->f_02;

	lolo.local_1 ++;

	lolo.local_1->f_00 = lolo.local_6;
	lolo.local_1->f_00.f_08 += bp14;
	C_00750134(&(lolo.local_1->f_00), &(lolo.local_1->f_10), &(lolo.local_1->f_20), &(lolo.local_1->f_22));
	lolo.local_1->f_24 = 1;
	lolo.local_1->f_28 = 0;
	lolo.local_1->f_1c = 0;
	lolo.local_1->f_26 = bp10->f_02;
}

//<empty>
void C_00753348() {
}

void C_0075334D() {
	D_00E04604 = 1;
}

int C_0075335C() {
	return D_00E28CDC;
}

int C_00753366(short bp08, short bp0c) {
	struct t_wm_local_18 *local_1;

	for(local_1 = D_00E045F8; local_1 && (local_1->f_10 != bp08 || local_1->f_12 != bp0c); local_1 = local_1->pNext);

	return local_1 != 0;
}

char D_00969B30[] = {9,9,3,2};
char D_00969B34[] = {7,7,4,2};

void C_007533AF() {
	struct {
		int bp_28;
		int local_9;
		int bp_20;//local_8
		int bp_1c;//local_7
		int bp_18;//local_6
		int bp_14;//local_5
		struct VECTOR local_4;
	}lolo;

	C_00762798(&lolo.local_4);
	lolo.bp_14 = (lolo.local_4.f_00 - 0x4000) >> 0xf;
	lolo.bp_1c = (lolo.local_4.f_08 - 0x4000) >> 0xf;
	lolo.bp_20 = C_0074D330();
	if(lolo.bp_20 == 2) {
		lolo.bp_14 -= 3;
		lolo.bp_1c -= 2;
	}
	if(lolo.bp_14 < 0)
		lolo.bp_14 += D_00969B30[lolo.bp_20];
	if(lolo.bp_1c < 0)
		lolo.bp_1c += D_00969B34[lolo.bp_20];
	lolo.local_9 = D_00969B30[lolo.bp_20] * lolo.bp_1c + lolo.bp_14;
	if(lolo.bp_20 == 0) {//else 0075350C
		if(D_00E28CB4 > 0 && lolo.bp_14 >= 4 && lolo.bp_14 <= 5 && lolo.bp_1c >= 4 && lolo.bp_1c <= 5)
			lolo.local_9 = lolo.bp_1c * 2 + lolo.bp_14 + 0x33;
		if(D_00E28CB4 > 1 && lolo.bp_14 >= 4 && lolo.bp_14 <= 6 && lolo.bp_1c >= 3 && lolo.bp_1c <= 4)
			lolo.local_9 = (lolo.bp_1c - 3) * 3 + lolo.bp_14 + 0x3f;
		if(D_00E28CB4 > 2 && lolo.bp_14 >= 5 && lolo.bp_14 <= 6 && lolo.bp_1c >= 5)
			lolo.local_9 = lolo.bp_1c * 2 + lolo.bp_14 + 0x3a;
		if(D_00E28CB4 > 3 && lolo.bp_14 >= 1 && lolo.bp_14 <= 3 && lolo.bp_1c >= 4 && lolo.bp_1c <= 5)
			lolo.local_9 = (lolo.bp_1c - 4) * 3 + lolo.bp_14 + 0x4c;
	}
	C_007593CD(C_0074CA00(1, lolo.bp_20), (lolo.local_9 * 0xb800) * 4, 0xb800 * 4/*0x2e000*/, D_00E045FC, 0);//wmfile:read file
	D_00E28970 = &(D_00E04928[4]);
	D_00E28C28 = &(D_00E04928[0]);
	D_00E04928[3].pNext = 0;//00E04940
	for(lolo.bp_18 = 0; lolo.bp_18 < 2; lolo.bp_18 ++) {
		for(lolo.bp_28 = 0; lolo.bp_28 < 2; lolo.bp_28 ++) {
			D_00E04928[lolo.bp_18 * 2 + lolo.bp_28].f_04 = /*bp_2c*/(lolo.bp_20 == 2)?
				(((lolo.bp_1c + lolo.bp_18) % 4) + 2) * 9 + ((lolo.bp_14 + lolo.bp_28) % 3) + 3:
				/*bp_30*/(lolo.bp_20 == 3)?
					((lolo.bp_1c + lolo.bp_18) & 1) * 9 + ((lolo.bp_14 + lolo.bp_28) & 1):
					((lolo.bp_1c + lolo.bp_18) % 7) * 9 + ((lolo.bp_14 + lolo.bp_28) % 9)
			;
		}
	}
}

unsigned char *__0075363D(short bp08) {
	struct {
		struct t_wm_local_08_ter *local_4;
		struct t_wm_local_08_ter *local_3;
		struct t_wm_local_08_ter *local_2;
		struct t_wm_local_08_ter *local_1;
	}lolo;

	if(D_00E28CBC)
		C_0074C9A0(0xe);//<empty>:some error management?
	for(lolo.local_3 = 0, lolo.local_2 = D_00E28C24; lolo.local_2; lolo.local_3 = lolo.local_2, lolo.local_2 = lolo.local_2->pNext);
	if(lolo.local_3) {
		lolo.local_3->pNext = D_00E28B7C;
		D_00E28B7C = D_00E28C24;
		D_00E28C24 = 0;
	}
	for(lolo.local_4 = 0, lolo.local_1 = D_00E28CB0; lolo.local_1; lolo.local_4 = lolo.local_1, lolo.local_1 = lolo.local_1->pNext);
	if(lolo.local_4) {
		lolo.local_4->pNext = D_00E28970;
		D_00E28970 = D_00E28CB0;
		D_00E28CB0 = 0;
	}
	for(lolo.local_4 = 0, lolo.local_1 = D_00E28C28; lolo.local_1; ) {
		if(lolo.local_1 >= &(D_00E04928[bp08])) {//else 00753765
			if(lolo.local_4)
				lolo.local_4->pNext = lolo.local_1->pNext;
			else
				D_00E28C28 = lolo.local_1->pNext;
			lolo.local_1->pNext = D_00E28970;
			D_00E28970 = lolo.local_1;
			lolo.local_1 = /*lolo.local_5*/lolo.local_4?lolo.local_4->pNext:D_00E28C28;
		} else {
			lolo.local_4 = lolo.local_1;
			lolo.local_1 = lolo.local_1->pNext;
		}
	}

	return D_00E045FC[bp08];
}

void C_0075378A(int bp08) {
	D_00E28CC0 = 2;
	D_00E28C2C = bp08;
}

void C_007537A1(int bp08) {
	D_00E28CB4 = bp08;
}

void C_007537AE(int *bp08) {
	struct {
		struct SVECTOR *local_3;
		struct SVECTOR *local_2;
		struct SVECTOR *local_1;
	}lolo;

	lolo.local_2 = &(D_00E28CD0->f_0c[D_00E04608->f_00]);
	lolo.local_3 = &(D_00E28CD0->f_0c[D_00E04608->f_01]);
	lolo.local_1 = &(D_00E28CD0->f_0c[D_00E04608->f_02]);
	bp08[0] = lolo.local_2->f_00 + lolo.local_3->f_00 + lolo.local_1->f_00;
	bp08[1] = lolo.local_2->f_02 + lolo.local_3->f_02 + lolo.local_1->f_02;
	bp08[2] = lolo.local_2->f_04 + lolo.local_3->f_04 + lolo.local_1->f_04;
}
