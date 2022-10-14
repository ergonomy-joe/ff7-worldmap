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
	/*04*/short f_04;//(chunkY << 2) | chunkX?
	/*06*/short f_06;//some index
};

struct t_wm_local_08_bis {//size 8
	/*00*/struct t_wm_local_08_bis *pNext;
	/*04*/struct t_wm_local_18 *f_04;
};
////////////////////////////////////////
struct t_wm_local_18 *D_00E045F8;
unsigned char (*D_00E045FC)[0xb800];
int D_00E04600;
int D_00E04604;//chocobo farm related flag?
struct t_wm_TerrainTriangle *D_00E04608;
struct t_wm_local_18 D_00E04610[0x20];
int D_00E04910;
//00E04914
struct VECTOR D_00E04918;
struct t_wm_local_08_ter D_00E04928[9];
//D_00E04940
//struct t_wm_local_08_ter D_00E04948[]
unsigned char D_00E04970[0x20][0x1200];//0x24000
struct t_wm_local_08_ter *D_00E28970;//head of list(1)?
//00E28974
struct t_wm_local_08_bis D_00E28978[0x40];
struct t_wm_local_08_bis *D_00E28B78;
struct t_wm_local_08_ter *D_00E28B7C;
struct t_wm_local_08_ter D_00E28B80[0x14];
int D_00E28C20;
struct t_wm_local_08_ter *D_00E28C24;
struct t_wm_local_08_ter *D_00E28C28;//head of list(2)?
int D_00E28C2C;
struct VECTOR D_00E28C30;
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
int D_00E28CD4;//bridge move counter
struct t_wm_local_08_bis *D_00E28CD8;
int D_00E28CDC;
//D_00E28CE0
////////////////////////////////////////
//some inflate function[world map]?
void C_0074FFC0(unsigned char *src, unsigned char *dst) {
	struct {
		unsigned char *pRefEnd;
		unsigned char *dststart;
		int i;
		void *srcend;
		int j;
		int count;
		int flags;
		unsigned char *pRefData;
	}lolo;

	//LZSS decompression?
	//looks like Haruhiko Okumura's implementation
	// but not that much.
	lolo.count = 0;
	lolo.srcend = src + 3 + *(int *)src;
	src += sizeof(int);
	lolo.dststart = dst;
	while(1) {
		if(lolo.count == 0) {
			lolo.count = 8;
			if(src >= lolo.srcend) break;
			lolo.flags = *(src ++);
		}
		if(lolo.flags & 1) {
			//literal data
			if(src >= lolo.srcend) break;
			*(dst ++) = *(src ++);
		} else {
			//references
			if(src >= lolo.srcend) break;
			lolo.i = *(src ++);
			lolo.j = *(src ++);
			lolo.i |= (lolo.j & 0xf0) << 4;
			lolo.pRefEnd = dst + 3 + (lolo.j & 0xf);
#define N		 4096	/* size of ring buffer */
#define F		   18	/* upper limit for match_length */
			lolo.pRefData = dst - ((dst - lolo.dststart - (lolo.i - (N - F))) & (N - 1));
#undef F
#undef N
			while(lolo.pRefData < lolo.dststart) {
				*(dst ++) = 0;
				lolo.pRefData ++;
			}
			while(dst < lolo.pRefEnd) {
				*(dst ++) = *(lolo.pRefData ++);
			}
		}
		lolo.flags >>= 1;
		lolo.count --;
	}//end while
}

//VECTOR->chunk x,y?
void C_00750134(struct VECTOR *bp08, struct SVECTOR *bp0c, short *bp10, short *bp14) {
	//-- --
	if(bp10) {
		*bp10 = bp08->f_00 >> 0xd;
		if(*bp10 < 0)
			*bp10 += 0x24;
		else if(*bp10 >= 0x24)
			*bp10 -= 0x24;
	}
	//-- --
	if(bp14) {
		*bp14 = bp08->f_08 >> 0xd;
		if(*bp14 < 0)
			*bp14 += 0x1c;
		else if(*bp14 >= 0x1c)
			*bp14 -= 0x1c;
	}
	//-- --
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
	struct {
		int local_2;
		int local_1;
	}lolo;

	if(C_0074D30F() != 2) {//wm:get some zoom/rotation mode?//else 00750427
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
			if(bp08->f_00 - D_00E04918.f_00 > 0) lolo.local_1 = bp08->f_00 - D_00E04918.f_00; else lolo.local_1 = -(bp08->f_00 - D_00E04918.f_00);
			if(bp08->f_08 - D_00E04918.f_08 > 0) lolo.local_2 = bp08->f_08 - D_00E04918.f_08; else lolo.local_2 = -(bp08->f_08 - D_00E04918.f_08);
			D_00E28CC8 = (lolo.local_1 + lolo.local_2) > 0xa;
		} else {//else 00750427
			D_00E04918 = *bp08;
		}
	}
}

void C_0075042B(struct VECTOR *bp08) {
	if(bp08)
		*bp08 = D_00E04918;
}

//wm:get bridge move counter?
int C_0075045C() {
	return D_00E28CD4;
}

//wm:set bridge move counter?
void C_00750466(int bp08) {
	D_00E28CD4 = bp08;
}

void C_007504D7(void);//this module:init cont'd(1)
void C_007505D7(void);//this module:init cont'd(2)
void C_00750641(void);//this module:init cont'd(3)

void C_00750473() {
	C_007504D7();//this module:init cont'd(1)
	C_007505D7();//this module:init cont'd(2)
	C_00750641();//this module:init cont'd(3)
	D_00E04604 = 0;
	D_00E28CDC = 0;
	D_00E28CD0 = 0;
	D_00E04608 = 0;
	D_00E28CBC = 1;
	D_00E28CC0 = 0;
	D_00E28C2C = 0;
	D_00E28CD4 = 0;
}

//this module:init cont'd(1)
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

//this module:init cont'd(2)
void C_007505D7() {
	short i;

	for(i = 0; i < 0x3f; i ++)
		D_00E28978[i].pNext = &(D_00E28978[i + 1]);
	D_00E28978[i].pNext = 0;
	D_00E28CD8 = D_00E28978;

	D_00E28B78 = 0;
	D_00E04910 = 0;
}

//this module:init cont'd(3)
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
	struct {
		struct t_wm_local_08_ter *local_2;
		struct t_wm_local_08_ter *local_1;
	}lolo;

	D_00E28CBC = 0;
	if(D_00E04600 >= 0 && D_00E28CAC >= D_00DFC480 * 5) {
		for(
			lolo.local_2 = 0, lolo.local_1 = D_00E28CB0;
			lolo.local_1 && lolo.local_1 != &(D_00E04928[D_00E04600]);
			lolo.local_2 = lolo.local_1, lolo.local_1 = lolo.local_1->pNext
		);
		//-- --
		if(lolo.local_1 == 0)
			C_0074C9A0(0xd);//<empty>:some error management?
		//-- remove from current place --
		if(lolo.local_2)
			lolo.local_2->pNext = lolo.local_1->pNext;
		else
			D_00E28CB0 = lolo.local_1->pNext;
		//-- make it the new head --
		lolo.local_1->pNext = D_00E28970;
		D_00E28970 = lolo.local_1;
		//-- --
		D_00E28CAC = 0;
		D_00E04600 = -1;
	}
	//
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
void C_00751EFC(struct VECTOR *, struct VECTOR *, struct VECTOR *, short);//render terrain:
void C_00753348(void);//<empty>

void C_0075079D(short wAngle/*bp08*/, int bp0c) {
	struct {
		short wChunkY; char __ocal_21[2];
		int local_20;
		short wChunkX; char __ocal_19[2];
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
		C_00753D00(&lolo.local_18, -wAngle);//wm:SVECTOR z rotation?
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
		C_0075164A(&lolo.local_8, wAngle);
		C_00750134(&lolo.local_16, 0, &lolo.wChunkX, &lolo.wChunkY);//VECTOR->chunk x,y?
		C_00750D99(lolo.wChunkX, lolo.wChunkY);
		C_007511CD();
		C_00751408();
		//-- some fade in/out? --
		lolo.local_20 = D_00E28C40;
		D_00E28C40 = /*lolo.local_22*/(C_007512EA() > 2)?D_00E28C40 + 1:0;
		if(lolo.local_20 < 300 && D_00E28C40 >= 300)
			C_0074D955(1/*fade out*/);//wm:start some fade in/out?
		else if(lolo.local_20 >= 300 && D_00E28C40 == 0)
			C_0074D955(4/*fade out*/);//wm:start some fade in/out?
		//-- --
	}
	if(C_00766B53() == 2)
		C_00766417(0);
	else if(D_00E28CC0 == 1)
		C_00766417(D_00E28C2C);
	C_00762798(&lolo.local_12);
	D_00E37D28 = 5500;
	D_00E37524 = C_0074D330() == 2?16000:0;//wm:get current map id?
	if(bp0c)
		C_00751EFC(&lolo.local_4, &lolo.local_8, &lolo.local_12, wAngle);//render terrain:
	//-- --
	if(C_0074D4DC())
		C_00753348();//<empty>
	//-- --
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
			//-- --
			if(lolo.bp_08 == 0)
				C_0074C9A0(0xa);//<empty>:some error management?
			//-- --
			D_00E28B7C = lolo.bp_08->pNext;
			lolo.bp_08->pNext = lolo.bp_0c;
			lolo.bp_0c = lolo.bp_08;
			lolo.bp_08->f_04 = C_00750C20(lolo.bp_20, lolo.bp_24);
		}//end for
	}//end for
	lolo.bp_18 = 0;
	lolo.bp_04 = D_00E28C28;
	while(lolo.bp_04) {
		lolo.bp_10 = 0;
		for(
			lolo.bp_08 = lolo.bp_0c;
			lolo.bp_08 && lolo.bp_08->f_04 != lolo.bp_04->f_04;
			lolo.bp_10 = lolo.bp_08, lolo.bp_08 = lolo.bp_08->pNext
		);
		if(lolo.bp_08) {//else 00750B66
			//-- remove from current place --
			if(lolo.bp_10)
				lolo.bp_10->pNext = lolo.bp_08->pNext;
			else
				lolo.bp_0c = lolo.bp_08->pNext;
			//-- make it the new head --
			lolo.bp_08->pNext = D_00E28B7C;
			D_00E28B7C = lolo.bp_08;
			//-- --
			if(lolo.bp_18) {
				lolo.bp_18->pNext = lolo.bp_04->pNext;
				//-- make it the new head --
				lolo.bp_04->pNext = D_00E28C28;
				D_00E28C28 = lolo.bp_04;
				//-- --
				lolo.bp_04 = lolo.bp_18->pNext;
			} else {
				lolo.bp_18 = lolo.bp_04;
				lolo.bp_04 = lolo.bp_04->pNext;
			}
		} else {
			lolo.bp_18 = lolo.bp_04;
			lolo.bp_04 = lolo.bp_04->pNext;
		}
	}//end while
	for(lolo.bp_04 = D_00E28CB0; lolo.bp_04; lolo.bp_04 = lolo.bp_04->pNext) {
		lolo.bp_10 = 0;
		for(
			lolo.bp_08 = lolo.bp_0c;
			lolo.bp_08 && lolo.bp_08->f_04 != lolo.bp_04->f_04;
			lolo.bp_10 = lolo.bp_08, lolo.bp_08 = lolo.bp_08->pNext
		);
		if(lolo.bp_08) {
			if(lolo.bp_10)
				lolo.bp_10->pNext = lolo.bp_08->pNext;
			else
				lolo.bp_0c = lolo.bp_08->pNext;
			//-- make it the new head --
			lolo.bp_08->pNext = D_00E28B7C;
			D_00E28B7C = lolo.bp_08;
		}
	}//end for
	for(
		lolo.bp_08 = lolo.bp_0c;
		lolo.bp_08;
		lolo.bp_08 = C_00750C84(lolo.bp_08)
	);
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
	struct {
		struct t_wm_local_08_ter *local_2;
		struct t_wm_local_08_ter *local_1;
	}lolo;

	lolo.local_2 = 0;
	lolo.local_1 = C_00750D06();
	if(lolo.local_1) {
		bp08->f_06 = (lolo.local_1 - D_00E04928);
		D_00E04928[bp08->f_06].f_04 = bp08->f_04;
		lolo.local_2 = bp08->pNext;
		//-- make it the new head --
		bp08->pNext = D_00E28C24;
		D_00E28C24 = bp08;
	} else {
		lolo.local_2 = bp08->pNext;
		//-- make it the new head --
		bp08->pNext = D_00E28B7C;
		D_00E28B7C = bp08;
	}

	return lolo.local_2;
}

struct t_wm_local_08_ter *C_00750D06() {
	struct {
		struct t_wm_local_08_ter *local_2;
		struct t_wm_local_08_ter *local_1;
	}lolo;
	
	lolo.local_1 = 0;
	if(D_00E28970) {
		lolo.local_1 = D_00E28970;
		D_00E28970 = lolo.local_1->pNext;
	} else {
		lolo.local_1 = D_00E28C28;
		if(lolo.local_1) {
			for(
				lolo.local_2 = 0;
				lolo.local_1->pNext;
				lolo.local_2 = lolo.local_1, lolo.local_1 = lolo.local_1->pNext
			);
			if(lolo.local_2)
				lolo.local_2->pNext = 0;
			else
				lolo.local_1 = 0;
		}
	}
	if(lolo.local_1) {
		//-- make it the new head --
		lolo.local_1->pNext = D_00E28CB0;
		D_00E28CB0 = lolo.local_1;
	}

	return lolo.local_1;
}

void C_00750EFA(struct t_wm_local_08_ter *, struct t_wm_local_08_ter *);

void C_00750D99(short wChunkX/*bp08*/, short wChunkY/*bp0c*/) {
	struct {
		int dwDstChunkY;//local_10
		struct t_wm_local_08_ter *local_9;
		int dwMaxDst;//local_8
		struct t_wm_local_08_ter *local_7;
		int dwDstChunkX;//local_6
		int dwCurChunkY;//local_5
		int dwCurChunkX;//local_4
		struct t_wm_local_08_ter *local_3;
		struct t_wm_local_08_ter *local_2;
		int dwDst;//local_1
	}lolo;

	if(D_00E28CAC == 0 && D_00E28C24 && C_007538C9(0)) {
		lolo.local_7 =
		lolo.local_9 = 0;
		lolo.dwMaxDst = 0x7fff;
		lolo.local_3 = 0;
		for(lolo.local_2 = D_00E28C24; lolo.local_2; lolo.local_3 = lolo.local_2, lolo.local_2 = lolo.local_2->pNext) {
			lolo.dwCurChunkY = lolo.local_2->f_04 / 4;
			lolo.dwCurChunkX = lolo.local_2->f_04 - lolo.dwCurChunkY * 4;
			lolo.dwDstChunkX = /*lolo.local_11*/inline_abs(lolo.dwCurChunkX - wChunkX);
			if(lolo.dwDstChunkX > 0x12)
				lolo.dwDstChunkX = 0x24 - lolo.dwDstChunkX;
			lolo.dwDstChunkY = /*lolo.local_12*/inline_abs(lolo.dwCurChunkY - wChunkY);
			if(lolo.dwDstChunkY > 0xe)
				lolo.dwDstChunkY = 0x1c - lolo.dwDstChunkY;
			lolo.dwDst = lolo.dwDstChunkX + lolo.dwDstChunkY;
			if(lolo.dwMaxDst > lolo.dwDst) {
				lolo.dwMaxDst = lolo.dwDst;
				lolo.local_7 = lolo.local_2;
				lolo.local_9 = lolo.local_3;
			}
		}//end for
		//-- --
		if(lolo.local_7 == 0)
			C_0074C9A0(0x22);//<empty>:some error management?
		//-- --
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
	//-- make it the new head --
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
		int dwMapId;//local_2
		int local_1;
	}lolo;

	lolo.dwMapId = C_0074D330();//wm:get current map id?
	lolo.local_1 = 
	D_00E28C20 = /*lolo.local_13*/(lolo.dwMapId == 0)?
		/*lolo.local_7*/(D_00E28CB4 > 0 && bp08->f_04 == 0x32)?0x3f:
		/*lolo.local_8*/(D_00E28CB4 > 1 && bp08->f_04 == 0x29)?0x40:
		/*lolo.local_9*/(D_00E28CB4 > 1 && bp08->f_04 == 0x2a)?0x41:
		/*lolo.local_10*/(D_00E28CB4 > 2 && bp08->f_04 == 0x3c)?0x42:
		/*lolo.local_11*/(D_00E28CB4 > 3 && bp08->f_04 == 0x2f)?0x43:
		/*lolo.local_12*/(D_00E28CB4 > 3 && bp08->f_04 == 0x30)?0x44:
			bp08->f_04:
		bp08->f_04
	;
	if(lolo.dwMapId == 2) {//else 007510D7
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
	} else if(lolo.dwMapId == 3) {//else 0075116B
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
	C_007593CD(C_0074CA00(0/*"WM?.MAP"*/, lolo.dwMapId), lolo.local_1 * 0xb800, 0xb800, D_00E045FC[bp08->f_06], 0);//wmfile:read file
	D_00E28CAC = D_00DFC480 * 5;
	D_00E04600 = bp08->f_06;
	C_007512C2();
}

void C_00751322(struct t_wm_local_08_ter *);

void C_007511CD() {
	struct {
		struct t_wm_local_08_ter *local_2;
		struct t_wm_local_08_ter *local_1;
	}lolo;

	//
	if(D_00E28CAC < D_00DFC480 * 5 && D_00E04600 >= 0) {//else 00751285
		for(
			lolo.local_2 = 0, lolo.local_1 = D_00E28CB0;
			lolo.local_1 && lolo.local_1 != &(D_00E04928[D_00E04600]);
			lolo.local_2 = lolo.local_1, lolo.local_1 = lolo.local_1->pNext
		);
		//-- --
		if(lolo.local_1 == 0)
			C_0074C9A0(0xb);//<empty>:some error management?
		//-- --
		if(lolo.local_2)
			lolo.local_2->pNext = lolo.local_1->pNext;
		else
			D_00E28CB0 = lolo.local_1->pNext;
		//-- make it the new head --
		lolo.local_1->pNext = D_00E28C28;
		D_00E28C28 = lolo.local_1;
		//-- --
		C_00751322(lolo.local_1);
		D_00E04600 = -1;
	}
	D_00E28CAC -= /*lolo.local_3*/(D_00E28CAC && D_00E28CAC < D_00DFC480 * 5);
}

void C_007512C2() {
	if(D_00E04600 >= 0) {
		D_00E28CAC = D_00DFC480 * 5 - 1;
		C_0075395E(0);
	}
}

short C_007512EA() {
	struct {
		int local_2;
		struct t_wm_local_08_ter *local_1;
	}lolo;

	for(
		lolo.local_2 = 0, lolo.local_1 = D_00E28CB0;
		lolo.local_1;
		lolo.local_2 ++, lolo.local_1 = lolo.local_1->pNext
	);

	return lolo.local_2;
}

void C_00751374(struct t_wm_local_18 *);

void C_00751322(struct t_wm_local_08_ter *bp08) {
	struct t_wm_local_18 *local_1;

	for(local_1 = D_00E28CC4; local_1; local_1 = local_1->pNext) {
		if((local_1->f_12 >> 2) * 9 + (local_1->f_10 >> 2) == bp08->f_04)
			C_00751374(local_1);
	}//end for
}

void C_00751374(struct t_wm_local_18 *bp08) {
	struct t_wm_local_08_bis *local_1;

	for(
		local_1 = D_00E28B78;
		local_1 && (local_1->f_04->f_10 != bp08->f_10 || local_1->f_04->f_12 != bp08->f_12);
		local_1 = local_1->pNext
	);
	if(local_1 == 0) {
		//-- --
		if(D_00E28CD8 == 0)
			C_0074C9A0(0x16);//<empty>:some error management?
		//-- --
		local_1 = D_00E28CD8;
		D_00E28CD8 = local_1->pNext;
		//-- make it the new head --
		local_1->pNext = D_00E28B78;
		D_00E28B78 = local_1;
		//-- --
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
		//-- --
		if(lolo.local_2->f_04 == 0)
			C_0074C9A0(0xc);//<empty>:some error management?
		//-- --
		lolo.local_5 = (lolo.local_2->f_04->f_12 >> 2) * 9 + (lolo.local_2->f_04->f_10 >> 2);
		for(
			lolo.local_6 = D_00E28C28;
			lolo.local_6 && lolo.local_6->f_04 != lolo.local_5;
			lolo.local_6 = lolo.local_6->pNext
		);
		if(lolo.local_6) {//else 00751547
			C_0075155A(lolo.local_2->f_04, lolo.local_6);
			lolo.local_4 = 0;
			for(
				lolo.local_1 = D_00E28CC4;
				lolo.local_1 && lolo.local_1 != lolo.local_2->f_04;
				lolo.local_4 = lolo.local_1, lolo.local_1 = lolo.local_1->pNext
			);
			//-- --
			if(lolo.local_1 == 0)
				C_0074C9A0(0x17);//<empty>:some error management?
			//-- --
			if(lolo.local_4)
				lolo.local_4->pNext = lolo.local_1->pNext;
			else
				D_00E28CC4 = lolo.local_1->pNext;
			//-- make it the new head --
			lolo.local_1->pNext = D_00E045F8;
			D_00E045F8 = lolo.local_1;
			//-- --
			D_00E28B78 = lolo.local_2->pNext;
			//-- make it the new head --
			lolo.local_2->pNext = D_00E28CD8;
			D_00E28CD8 = lolo.local_2;
		}
	}//end for
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
	bp08->f_04 = (struct t_wm_TerrainTriangle *)&(lolo.local_3[2]);
	bp08->f_14 = lolo.local_3[0];
	bp08->f_08 = (struct SVECTOR *)&(bp08->f_04[bp08->f_14]);
	bp08->f_0c = &(bp08->f_08[lolo.local_3[1]]);
	C_00760E1D(bp08->f_04, &(bp08->f_04[bp08->f_14]), 1);//wm:adjust terrain triangle u,v?
}

struct t_wm_local_08_ter *C_007518F6(short);
int C_00751962(short);
int C_0075199C(void);
void C_00751AC4(struct VECTOR *, short, int [][5]);//make chunk "flag map"?
int C_00751D44(struct t_wm_local_18 *, short, short, short *, short *);
struct t_wm_local_18 *C_00751E43(void);

void C_0075164A(struct VECTOR *bp08, short wAngle/*bp0c*/) {
	struct {
		struct t_wm_local_08_ter *bp_8c;
		short bp_88; char _p_88[2];
		int bp_84;
		short wChunkY; char _p_80[2];//local_32
		short j; char _p_7c[2];//local_31
		short i; char _p_78[2];//local_30
		int bp_74[5][5];//local_29
		short wChunkX; char _p_10[2];//local_4
		struct t_wm_local_08_ter *bp_0c;
		short bp_08; char _p_08[2];
		struct t_wm_local_18 *bp_04;//local_1
	}lolo;

	if(C_0075199C() >= 0x10)
		return;
	C_00750134(bp08, 0, &lolo.wChunkX, &lolo.wChunkY);//VECTOR->chunk x,y?
	C_00751AC4(bp08, wAngle, lolo.bp_74);//make chunk "flag map"?
	for(lolo.bp_04 = D_00E045F8; lolo.bp_04; lolo.bp_04 = lolo.bp_04->pNext) {
		if(C_00751D44(lolo.bp_04, lolo.wChunkX, lolo.wChunkY, &lolo.i, &lolo.j))
			lolo.bp_74[lolo.j + 2][lolo.i + 2] = 0;
	}//end for
	for(lolo.bp_04 = D_00E28CC4; lolo.bp_04; lolo.bp_04 = lolo.bp_04->pNext) {
		if(C_00751D44(lolo.bp_04, lolo.wChunkX, lolo.wChunkY, &lolo.i, &lolo.j))
			lolo.bp_74[lolo.j + 2][lolo.i + 2] = 0;
	}//end for
	for(lolo.j = 0; lolo.j < 5; lolo.j ++) {
		for(lolo.i = 0; lolo.i < 5; lolo.i ++) {
			if(lolo.bp_74[lolo.j][lolo.i]) {//else 007518E8
				//-- --
				lolo.bp_88 = lolo.i + lolo.wChunkX - 2;
				if(lolo.bp_88 < 0)
					lolo.bp_88 += 0x24;
				else if(lolo.bp_88 >= 0x24)
					lolo.bp_88 -= 0x24;
				//-- --
				lolo.bp_08 = lolo.j + lolo.wChunkY - 2;
				if(lolo.bp_08 < 0)
					lolo.bp_08 += 0x1c;
				else if(lolo.bp_08 >= 0x1c)
					lolo.bp_08 -= 0x1c;
				//-- --
				lolo.bp_04 = C_00751E43();
				if(lolo.bp_04) {//else 007518E8
					lolo.bp_04->f_10 = lolo.bp_88;
					lolo.bp_04->f_12 = lolo.bp_08;
					lolo.bp_84 = (lolo.bp_08 >> 2) * 9 + (lolo.bp_88 >> 2);
					lolo.bp_8c = C_007518F6(lolo.bp_84);
					if(lolo.bp_8c) {
						C_00751374(lolo.bp_04);
					} else if(C_00751962(lolo.bp_84) == 0) {
						//-- --
						if(D_00E28B7C == 0)
							C_0074C9A0(0xf);//<empty>:some error management?
						//-- --
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
	struct {
		struct t_wm_local_08_ter *local_2;
		struct t_wm_local_08_ter *local_1;
	}lolo;

	for(
		lolo.local_2 = 0, lolo.local_1 = D_00E28C28;
		lolo.local_1 && lolo.local_1->f_04 != bp08;
		lolo.local_2 = lolo.local_1, lolo.local_1 = lolo.local_1->pNext
	);
	if(lolo.local_1 && lolo.local_2) {
		lolo.local_2->pNext = lolo.local_1->pNext;
		//-- make it the new head --
		lolo.local_1->pNext = D_00E28C28;
		D_00E28C28 = lolo.local_1;
	}

	return lolo.local_1;
}

int C_00751962(short bp08) {
	struct t_wm_local_08_ter *local_1;

	for(
		local_1 = D_00E28CB0;
		local_1 && local_1->f_04 != bp08;
		local_1 = local_1->pNext
	);

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
			//-- make it the new head --
			lolo.local_1->pNext = D_00E28CCC;
			D_00E28CCC = lolo.local_1;
			//-- --
			for(
				lolo.local_3 = 0, lolo.local_2 = D_00E28B78;
				lolo.local_2 && lolo.local_2->f_04 != lolo.local_1;
				lolo.local_3 = lolo.local_2, lolo.local_2 = lolo.local_2->pNext
			);
			if(lolo.local_2) {//else 00751A80
				if(lolo.local_3)
					lolo.local_3->pNext = lolo.local_2->pNext;
				else
					D_00E28B78 = lolo.local_2->pNext;
				//-- make it the new head --
				lolo.local_2->pNext = D_00E28CD8;
				D_00E28CD8 = lolo.local_2;
			}
			lolo.local_1 = /*lolo.local_6*/lolo.local_4?lolo.local_4->pNext:D_00E28CC4;
		} else {
			lolo.local_4 = lolo.local_1;
			lolo.local_1 = lolo.local_1->pNext;
			lolo.local_5 ++;
		}
	}//end while

	return lolo.local_5;
}

//make chunk "flag map"?
void C_00751AC4(struct VECTOR *bp08, short wAngle/*bp0c*/, int bp10[][5]) {
	struct {//xb8
		struct VECTOR bp_ac;
		struct MATRIX bp_9c; char _p_9c[2];//local_39
		struct SVECTOR bp_7c;//local_31
		struct VECTOR bp_74;//local_29
		short j; char _p_64[2];//local_25
		short i; char _p_60[2];
		struct VECTOR bp_5c;//local_23
		int bp_4c;//local_19
		struct VECTOR sTrans;//local_18
		struct SVECTOR sRot;//local_14
		struct VECTOR bp_30;//local_12
		struct VECTOR bp_20;
		struct VECTOR bp_10;//local_4
	}lolo;

	//-- --
	lolo.bp_7c.f_00 = 0;
	lolo.bp_7c.f_02 = 0;
	lolo.bp_7c.f_04 = -0x1000;
	lolo.bp_7c.f_06 = 0;

	lolo.sRot.f_00 = 0; lolo.sRot.f_02 = 0; lolo.sRot.f_04 = 0; lolo.sRot.f_06 = 0;
	lolo.sTrans.f_00 = 0; lolo.sTrans.f_04 = 0; lolo.sTrans.f_08 = 0; lolo.sTrans.f_0c = 0;

	psx_TransMatrix(&lolo.bp_9c, &lolo.sTrans);
	psx_SetTransMatrix(&lolo.bp_9c);

	lolo.sRot.f_02 = -wAngle + 0x380;
	psx_RotMatrixXYZ(&lolo.sRot, &lolo.bp_9c);
	psx_SetRotMatrix(&lolo.bp_9c);
	psx_RotTrans(&lolo.bp_7c, &lolo.bp_10, &lolo.bp_4c);

	lolo.sRot.f_02 = -wAngle - 0x380;
	psx_RotMatrixXYZ(&lolo.sRot, &lolo.bp_9c);
	psx_SetRotMatrix(&lolo.bp_9c);
	psx_RotTrans(&lolo.bp_7c, &lolo.bp_30, &lolo.bp_4c);
	//-- --
	lolo.bp_74.f_00 = (bp08->f_00 & 0x1fff) - 0x1000;
	lolo.bp_74.f_04 = 0;
	lolo.bp_74.f_08 = (bp08->f_08 & 0x1fff) - 0x1000;

	lolo.bp_5c.f_04 = 0;
	for(lolo.j = -2; lolo.j <= 2; lolo.j ++) {
		for(lolo.i = -2; lolo.i <= 2; lolo.i ++) {
			if(inline_abs(lolo.i) <= 1 && inline_abs(lolo.j) <= 1) {//else 00751CAF
				bp10[lolo.j + 2][lolo.i + 2] = 1;
			} else {
				lolo.bp_5c.f_00 = (lolo.i << 0xd) - lolo.bp_74.f_00;
				lolo.bp_5c.f_08 = (lolo.j << 0xd) - lolo.bp_74.f_08;
				psx_OuterProduct12(&lolo.bp_10, &lolo.bp_5c, &lolo.bp_ac);
				psx_OuterProduct12(&lolo.bp_30, &lolo.bp_5c, &lolo.bp_20);
				bp10[lolo.j + 2][lolo.i + 2] = /*lolo.bp_b8*/(lolo.bp_ac.f_04 < 0 && lolo.bp_20.f_04 > 0);
			}
		}//end for
	}//end for
}

int C_00751D44(struct t_wm_local_18 *bp08, short bp0c, short bp10, short *pwChunkX/*bp14*/, short *pwChunkY/*bp18*/) {
	//-- --
	*pwChunkX = bp08->f_10 - bp0c;
	if(*pwChunkX > 0x12)
		*pwChunkX -= 0x24;
	else if(*pwChunkX < -0x12)
		*pwChunkX += 0x24;
	//-- --
	*pwChunkY = bp08->f_12 - bp10;
	if(*pwChunkY > 0xe)
		*pwChunkY -= 0x1c;
	else if(*pwChunkY < -0xe)
		*pwChunkY += 0x1c;
	//-- --

	return inline_abs(*pwChunkX) <= 2 && inline_abs(*pwChunkY) <= 2;
}

struct t_wm_local_18 *C_00751E43() {
	struct {
		struct t_wm_local_18 *local_2;
		struct t_wm_local_18 *local_1;
	}lolo;

	lolo.local_1 = 0;
	if(D_00E28CCC) {
		lolo.local_1 = D_00E28CCC;
		D_00E28CCC = lolo.local_1->pNext;
	} else if(D_00E045F8) {//else 00751ED3
		for(
			lolo.local_2 = 0, lolo.local_1 = D_00E045F8;
			lolo.local_1->pNext;
			lolo.local_2 = lolo.local_1, lolo.local_1 = lolo.local_1->pNext
		);
		if(lolo.local_2)
			lolo.local_2->pNext = 0;
		else
			D_00E045F8 = 0;
		C_00761644(lolo.local_1->f_10, lolo.local_1->f_12);
	}
	if(lolo.local_1) {
		//-- make it the new head --
		lolo.local_1->pNext = D_00E28CC4;
		D_00E28CC4 = lolo.local_1;
		//-- --
		lolo.local_1->f_16 = 0;
	}

	return lolo.local_1;
}

struct t_wm_30_temp {//size 0x30
	/*00*/struct VECTOR f_00;
	/*10*/struct SVECTOR f_10;
	/*18*/struct t_wm_local_18 *f_18;
	/*1c*/struct t_wm_TerrainTriangle *f_1c;
	/*20*/short f_20;
	/*22*/short f_22;
	/*24*/short f_24;
	/*26*/short f_26;
	/*28*/short f_28;
	/*2a*/short f_2a;
	/*2c*/char __2c[4];
};

struct t_wm_f0_temp {//size 0xf0
	/*00*/struct t_wm_30_temp f_00[5];
};

struct t_wm_30_temp *C_00752D02(struct t_wm_local_18 *, struct t_wm_f0_temp *, short, short);
void C_007530B3(struct t_wm_f0_temp *, struct SVECTOR *, struct SVECTOR *, int);

//render terrain:
void C_00751EFC(struct VECTOR *bp08, struct VECTOR *bp0c, struct VECTOR *bp10, short wAngle/*bp14*/) {
	struct {//x1034
		//local_1036 and above is for compiler
		struct t_wm_f0_temp bp_102c[2][8];//local_1035
		struct MATRIX bp_12c; char _ocal_75[2];//local_75
		struct t_wm_f0_temp **bp_10c;//local_67
		int local_66;
		short bp_104; char _p_104[2];//local_65
		struct SVECTOR bp_100;
		short wChunkY; char _p_f8[2];
		struct t_wm_f0_temp **bp_f4;//local_61
		short wChunkX; char _p_f0[2];
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
	C_00750134(bp0c, &lolo.bp_100, &lolo.bp_14, &lolo.bp_10);//VECTOR->chunk x,y?
	C_0075027C(bp0c, 0);
	C_0075042B(&lolo.local_13);
	C_00750134(&lolo.local_13, &lolo.bp_0c, &lolo.bp_50, &lolo.bp_104);//VECTOR->chunk x,y?
	//-- --
	if(lolo.bp_50 - lolo.bp_14 > 0x12)
		lolo.bp_50 -= 0x24;
	else if(lolo.bp_50 - lolo.bp_14 < -0x12)
		lolo.bp_50 += 0x24;
	//-- --
	if(lolo.bp_104 - lolo.bp_10 > 0xe)
		lolo.bp_104 -= 0x1c;
	else if(lolo.bp_104 - lolo.bp_10 < -0xe)
		lolo.bp_104 += 0x1c;
	//-- --
	if(lolo.bp_50 > lolo.bp_14)
		lolo.bp_0c.f_00 += 0x2000;
	else if(lolo.bp_50 < lolo.bp_14)
		lolo.bp_0c.f_00 -= 0x2000;
	//-- --
	if(lolo.bp_104 > lolo.bp_10)
		lolo.bp_0c.f_04 += 0x2000;
	else if(lolo.bp_104 < lolo.bp_10)
		lolo.bp_0c.f_04 -= 0x2000;
	//-- --
	if(C_0074D4DC())
		sprintf(D_00E28C48, "PS%d%d%d%d.rsd  POS: %d %d", lolo.bp_14 / 10, lolo.bp_14 % 10, lolo.bp_10 / 10, lolo.bp_10 % 10, bp0c->f_00 & 0x1fff, bp0c->f_08 & 0x1fff);
	//-- --
	lolo.local_9.f_02 = 0;
	psx_SetTransMatrix(&lolo.bp_12c);
	lolo.local_16 = C_00761735() == WM_MODELID_05?350:200;//wm:current transportation mode?
	lolo.local_66 = /*lolo.local_1036*/(0x500 << ((D_00E28CC0 != 1 && D_00E28CD4 == 0)?0:1)) >> 3;
	for(lolo.bp_ec = &(lolo.bp_102c[0][0]); lolo.bp_ec < &(lolo.bp_102c[0][8]); lolo.bp_ec ++) {
		C_007530B3(lolo.bp_ec, &lolo.bp_c0, &lolo.local_9, lolo.local_16);
		lolo.local_9.f_02 += lolo.local_66;
	}//end for
	lolo.local_9.f_02 = 0;
	for(lolo.bp_ec = &(lolo.bp_102c[1][0]); lolo.bp_ec < &(lolo.bp_102c[1][8]); lolo.bp_ec ++) {
		C_007530B3(lolo.bp_ec, &lolo.bp_c0, &lolo.local_9, lolo.local_16);
		lolo.local_9.f_02 -= lolo.local_66;
	}//end for
	lolo.bp_e8[0] = &(lolo.bp_102c[0][0]);
	lolo.bp_10c = &(lolo.bp_e8[1]);
	lolo.bp_f4 = &(lolo.bp_e8[0]);
	while(lolo.bp_f4 < lolo.bp_10c) {
		lolo.bp_50 = (*lolo.bp_f4)->f_00[0].f_20;
		lolo.bp_104 = (*lolo.bp_f4)->f_00[0].f_22;
		//-- --
		if(lolo.bp_f4 == &(lolo.bp_e8[0]))
			C_00762D52();
		lolo.bp_f4 ++;
		//-- --
		lolo.bp_b8 = 0;
		for(
			lolo.bp_04 = D_00E045F8;
			lolo.bp_04 && (lolo.bp_04->f_10 != lolo.bp_50 || lolo.bp_04->f_12 != lolo.bp_104);
			lolo.bp_b8 = lolo.bp_04, lolo.bp_04 = lolo.bp_04->pNext
		);
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
		//-- --
		if(lolo.bp_18 == 0)
			C_0074C9A0(0x11);//<empty>:some error management?
		//-- --
		lolo.bp_18->pNext = lolo.bp_04;
		lolo.bp_18 = lolo.bp_04;
		C_00751D44(lolo.bp_04, lolo.bp_14, lolo.bp_10, &lolo.wChunkX, &lolo.wChunkY);
		lolo.bp_48.f_00 = (lolo.wChunkX << 0xd) - lolo.bp_0c.f_00;
		lolo.bp_48.f_02 = -lolo.bp_0c.f_02;
		lolo.bp_48.f_04 = (lolo.wChunkY << 0xd) - lolo.bp_0c.f_04;
		C_0074D33A(&lolo.bp_48);
		C_0075F0AD(lolo.bp_04->f_08, C_0074D4ED());
		psx_ReadRotMatrix(&lolo.bp_12c);
		//-- --
		if(lolo.bp_f4 == &(lolo.bp_e8[1]))
			C_00758DA5(lolo.bp_14, lolo.bp_10);//wm:refresh bridge at?
		//-- --
		lolo.bp_38 = C_00752D02(lolo.bp_04, lolo.bp_102c[D_00E28CB8], lolo.bp_50, lolo.bp_104);
		if(lolo.bp_38) {//else 00752546
			for(
				lolo.bp_3c = lolo.bp_f4;
				lolo.bp_3c < lolo.bp_10c && ((*lolo.bp_3c)->f_00[0].f_20 != lolo.bp_38->f_20 || (*lolo.bp_3c)->f_00[0].f_22 != lolo.bp_38->f_22);
				lolo.bp_3c ++
			);
			if(lolo.bp_3c >= lolo.bp_10c) {//else 00752546
				if(lolo.bp_10c < &(lolo.bp_e0[8])) {
					*(struct t_wm_30_temp **)lolo.bp_10c = lolo.bp_38;
					lolo.bp_10c ++;
				} else {
					C_0074C9A0(0x14);//<empty>:some error management?
				}
			}
		}
		//-- --
		lolo.bp_38 = C_00752D02(lolo.bp_04, lolo.bp_102c[(D_00E28CB8 == 0)], lolo.bp_50, lolo.bp_104);
		if(lolo.bp_38) {//else 0075260E
			for(
				lolo.bp_3c = lolo.bp_f4;
				lolo.bp_3c < lolo.bp_10c && ((*lolo.bp_3c)->f_00[0].f_20 != lolo.bp_38->f_20 || (*lolo.bp_3c)->f_00[0].f_22 != lolo.bp_38->f_22);
				lolo.bp_3c ++
			);
			if(lolo.bp_3c >= lolo.bp_10c) {//else 0075260E
				if(lolo.bp_10c < &(lolo.bp_e0[8])) {
					*(struct t_wm_30_temp **)lolo.bp_10c = lolo.bp_38;
					lolo.bp_10c ++;
				} else {
					C_0074C9A0(0x15);//<empty>:some error management?
				}
			}
		}
		//-- --
		for(lolo.bp_ec = &(lolo.bp_102c[0][0]); lolo.bp_ec < &(lolo.bp_102c[1][8]); lolo.bp_ec ++) {
			for(lolo.bp_38 = &(lolo.bp_ec->f_00[0]); lolo.bp_38 < &(lolo.bp_ec->f_00[5]); lolo.bp_38 ++) {
				if(lolo.bp_38->f_20 == lolo.bp_50 && lolo.bp_38->f_22 == lolo.bp_104 && lolo.bp_38->f_24 == 1)
					lolo.bp_38->f_24 = 4;
			}//end for
		}//end for
		psx_SetRotMatrix(&lolo.bp_12c);
		C_00762D74(lolo.bp_04);
		C_0074D33A(&lolo.bp_48);
		C_0075F263();
		C_0075F68C(lolo.bp_04->f_04, &(lolo.bp_04->f_04[lolo.bp_04->f_14]), lolo.bp_04->f_0c, C_0074C9AF(lolo.bp_04->f_14));//render terrain:1 "square"?
	}//end while
	for(
		lolo.bp_ec = &(lolo.bp_102c[D_00E28CB8][0]);
		lolo.bp_ec < &(lolo.bp_102c[D_00E28CB8][8]) && (lolo.bp_ec->f_00[0].f_24 != 2 || lolo.bp_ec->f_00[1].f_24 != 2 || lolo.bp_ec->f_00[2].f_24 != 2 || lolo.bp_ec->f_00[3].f_24 != 2 || lolo.bp_ec->f_00[4].f_24 != 2);
		lolo.bp_ec ++
	);
	if(lolo.bp_ec < &(lolo.bp_102c[D_00E28CB8][8])) {//else 00752898
		D_00E28C30 = lolo.bp_ec->f_00[0].f_00;
		D_00E28C30.f_04 = lolo.bp_ec->f_00[0].f_28;
		C_0076211B(lolo.bp_ec->f_00[0].f_2a);
		C_007624C5(&D_00E28C30);
		lolo.bp_4c = &D_00E28C30;
		//-- chocobo farm related? --
		if(D_00E04604) {
			D_00E04604 = 0;
			C_00756FF9(lolo.bp_ec->f_00[0].f_18, lolo.bp_ec->f_00[0].f_1c);//wm:chocobo farm related?
		}
		//-- --
		D_00E28CD0 = lolo.bp_ec->f_00[0].f_18;
		D_00E04608 = lolo.bp_ec->f_00[0].f_1c;
		D_00E38330 = lolo.bp_ec->f_00[0].f_1c;
		C_00761DF5(lolo.bp_ec->f_00[0].f_26);
		//goto 00752A60
	} else if(D_00E28C44 >= 8) {//else 00752A60
		for(
			lolo.bp_ec = &(lolo.bp_102c[!D_00E28CB8][0]);
			lolo.bp_ec < &(lolo.bp_102c[!D_00E28CB8][8]) && (lolo.bp_ec->f_00[0].f_24 != 2 || lolo.bp_ec->f_00[1].f_24 != 2 || lolo.bp_ec->f_00[2].f_24 != 2 || lolo.bp_ec->f_00[3].f_24 != 2 || lolo.bp_ec->f_00[4].f_24 != 2);
			lolo.bp_ec ++
		);
		if(lolo.bp_ec < &(lolo.bp_102c[(D_00E28CB8 == 0)][8])) {//else 00752A60
			D_00E28C30 = lolo.bp_ec->f_00[0].f_00;
			D_00E28C30.f_04 = lolo.bp_ec->f_00[0].f_28;
			C_0076211B(lolo.bp_ec->f_00[0].f_2a);
			C_007624C5(&D_00E28C30);
			lolo.bp_4c = &D_00E28C30;
			//-- chocobo farm related? --
			if(D_00E04604) {
				D_00E04604 = 0;
				C_00756FF9(lolo.bp_ec->f_00[0].f_18, lolo.bp_ec->f_00[0].f_1c);//wm:chocobo farm related?
			}
			//-- --
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
	//-- --
C_00752AB6:
	if(lolo.bp_4c == 0) {
		C_007628B5();
		if(C_00762136() == 0xe)//wm:get current terrain?
			D_00E28CD4 = 5;
	}
	D_00E28C44 ++;
	C_00750134(bp0c, &lolo.bp_100, &lolo.bp_50, &lolo.bp_104);//VECTOR->chunk x,y?
	C_00751AC4(bp0c, wAngle, lolo.bp_b4);//make chunk "flag map"?
	lolo.bp_b8 = 0;
	lolo.bp_04 = D_00E045F8;
	while(lolo.bp_04) {
		if(
			C_00751D44(lolo.bp_04, lolo.bp_50, lolo.bp_104, &lolo.wChunkX, &lolo.wChunkY) &&
			lolo.bp_b4[lolo.wChunkY + 2][lolo.wChunkX + 2]
		) {//else 00752CC2
			lolo.bp_48.f_00 = (lolo.wChunkX << 0xd) - lolo.bp_0c.f_00;
			lolo.bp_48.f_02 = -lolo.bp_0c.f_02;
			lolo.bp_48.f_04 = (lolo.wChunkY << 0xd) - lolo.bp_0c.f_04;
			C_0074D33A(&lolo.bp_48);
			C_0075F0AD(lolo.bp_04->f_08, C_0074D4ED());
			C_00762D74(lolo.bp_04);
			C_0074D33A(&lolo.bp_48);
			C_0075F263();
			C_0075F68C(lolo.bp_04->f_04, &(lolo.bp_04->f_04[lolo.bp_04->f_14]), lolo.bp_04->f_0c, C_0074C9AF(lolo.bp_04->f_14));//render terrain:1 "square"?
			if(lolo.bp_b8)
				lolo.bp_b8->pNext = lolo.bp_04->pNext;
			else
				D_00E045F8 = lolo.bp_04->pNext;
			lolo.bp_04->pNext = 0;
			if(lolo.bp_1c == 0) {
				lolo.bp_1c =
				lolo.bp_18 = lolo.bp_04;
			}
			//-- --
			if(lolo.bp_18 == 0)
				C_0074C9A0(0x13);//<empty>:some error management?
			//-- --
			lolo.bp_18->pNext = lolo.bp_04;
			lolo.bp_18 = lolo.bp_04;
			lolo.bp_04 = /*lolo.bp_1034*/lolo.bp_b8?lolo.bp_b8->pNext:D_00E045F8;
			continue;
		}
		lolo.bp_b8 = lolo.bp_04;
		lolo.bp_04 = lolo.bp_04->pNext;
	}//end while
	if(lolo.bp_1c && lolo.bp_18) {
		//-- make it the new head --
		lolo.bp_18->pNext = D_00E045F8;
		D_00E045F8 = lolo.bp_1c;
	}
}

struct t_wm_30_temp *C_00752D02(struct t_wm_local_18 *bp08, struct t_wm_f0_temp *bp0c, short bp10, short bp14) {
	struct {
		int local_11;
		struct t_wm_30_temp *local_10;
		int dwModelId;//local_9
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
	lolo.dwModelId = C_0076170B();
	if(C_00766B53() == 2 && C_00761844()) {//else 00752F21
		do {
			for(lolo.local_2 = &(bp0c[lolo.local_1].f_00[0]); lolo.local_2 < &(bp0c[lolo.local_1].f_00[5]); lolo.local_2 ++) {
				if(lolo.local_2->f_24 == 1) {//else 00752E61
					if(lolo.local_2->f_20 == bp10 && lolo.local_2->f_22 == bp14) {//else 00752E55
						lolo.local_2->f_18 = bp08;
						lolo.local_2->f_28 = lolo.local_6.f_04;
						if(
							C_0074CC07(bp08, &(lolo.local_2->f_10), lolo.local_8, &(lolo.local_2->f_28), &(lolo.local_2->f_1c), &(lolo.local_2->f_2a), lolo.dwModelId) &&
							inline_abs(lolo.local_2->f_28 - lolo.local_6.f_04) < 200
						) {
							lolo.local_2->f_24 = 2;
						} else {
							lolo.local_2->f_24 = 3;
						}
					} else if(lolo.local_10 == 0) {
						lolo.local_10 = lolo.local_2;
					}
				}
			}//end for
			lolo.local_7 = /*lolo.local_13*/(
				bp0c[lolo.local_1].f_00[0].f_24 == 2 &&
				bp0c[lolo.local_1].f_00[1].f_24 == 2 &&
				bp0c[lolo.local_1].f_00[2].f_24 == 2 &&
				bp0c[lolo.local_1].f_00[3].f_24 == 2 &&
				bp0c[lolo.local_1].f_00[4].f_24 == 2
			);
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
						if(
							C_0074CC07(bp08, &(lolo.local_2->f_10), lolo.local_8, &(lolo.local_2->f_28), &(lolo.local_2->f_1c), &(lolo.local_2->f_2a), lolo.dwModelId)
							//
						) {
							lolo.local_2->f_24 = 2;
						} else {
							lolo.local_2->f_24 = 3;
						}
					} else if(lolo.local_10 == 0) {
						lolo.local_10 = lolo.local_2;
					}
				}
			}//end for
			lolo.local_7 = /*lolo.local_14*/(
				bp0c[lolo.local_1].f_00[0].f_24 == 2 &&
				bp0c[lolo.local_1].f_00[1].f_24 == 2 &&
				bp0c[lolo.local_1].f_00[2].f_24 == 2 &&
				bp0c[lolo.local_1].f_00[3].f_24 == 2 &&
				bp0c[lolo.local_1].f_00[4].f_24 == 2
			);
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
	C_00750134(&(lolo.local_1->f_00), &(lolo.local_1->f_10), &(lolo.local_1->f_20), &(lolo.local_1->f_22));//VECTOR->chunk x,y?
	lolo.local_1->f_24 = 1;
	lolo.local_1->f_28 = 0;
	lolo.local_1->f_1c = 0;
	lolo.local_1->f_26 = bp10->f_02;

	lolo.local_1 ++;

	lolo.local_1->f_00 = lolo.local_6;
	lolo.local_1->f_00.f_00 -= bp14;
	C_00750134(&(lolo.local_1->f_00), &(lolo.local_1->f_10), &(lolo.local_1->f_20), &(lolo.local_1->f_22));//VECTOR->chunk x,y?
	lolo.local_1->f_24 = 1;
	lolo.local_1->f_28 = 0;
	lolo.local_1->f_1c = 0;
	lolo.local_1->f_26 = bp10->f_02;

	lolo.local_1 ++;

	lolo.local_1->f_00 = lolo.local_6;
	lolo.local_1->f_00.f_00 += bp14;
	C_00750134(&(lolo.local_1->f_00), &(lolo.local_1->f_10), &(lolo.local_1->f_20), &(lolo.local_1->f_22));//VECTOR->chunk x,y?
	lolo.local_1->f_24 = 1;
	lolo.local_1->f_28 = 0;
	lolo.local_1->f_1c = 0;
	lolo.local_1->f_26 = bp10->f_02;

	lolo.local_1 ++;

	lolo.local_1->f_00 = lolo.local_6;
	lolo.local_1->f_00.f_08 -= bp14;
	C_00750134(&(lolo.local_1->f_00), &(lolo.local_1->f_10), &(lolo.local_1->f_20), &(lolo.local_1->f_22));//VECTOR->chunk x,y?
	lolo.local_1->f_24 = 1;
	lolo.local_1->f_28 = 0;
	lolo.local_1->f_1c = 0;
	lolo.local_1->f_26 = bp10->f_02;

	lolo.local_1 ++;

	lolo.local_1->f_00 = lolo.local_6;
	lolo.local_1->f_00.f_08 += bp14;
	C_00750134(&(lolo.local_1->f_00), &(lolo.local_1->f_10), &(lolo.local_1->f_20), &(lolo.local_1->f_22));//VECTOR->chunk x,y?
	lolo.local_1->f_24 = 1;
	lolo.local_1->f_28 = 0;
	lolo.local_1->f_1c = 0;
	lolo.local_1->f_26 = bp10->f_02;
}

//<empty>
void C_00753348() {
}

//wm:set chocobo farm related flag?
void C_0075334D() {
	D_00E04604 = 1;
}

int C_0075335C() {
	return D_00E28CDC;
}

int C_00753366(short bp08, short bp0c) {
	struct t_wm_local_18 *local_1;

	for(
		local_1 = D_00E045F8;
		local_1 && (local_1->f_10 != bp08 || local_1->f_12 != bp0c);
		local_1 = local_1->pNext
	);

	return local_1 != 0;
}

char D_00969B30[] = {9,9,3,2};
char D_00969B34[] = {7,7,4,2};

void C_007533AF() {
	struct {
		int bp_28;
		int local_9;
		int dwMapId;//local_8
		int bp_1c;//local_7
		int bp_18;//local_6
		int bp_14;//local_5
		struct VECTOR local_4;
	}lolo;

	C_00762798(&lolo.local_4);
	lolo.bp_14 = (lolo.local_4.f_00 - 0x4000) >> 0xf;
	lolo.bp_1c = (lolo.local_4.f_08 - 0x4000) >> 0xf;
	lolo.dwMapId = C_0074D330();//wm:get current map id?
	if(lolo.dwMapId == 2) {
		lolo.bp_14 -= 3;
		lolo.bp_1c -= 2;
	}
	if(lolo.bp_14 < 0)
		lolo.bp_14 += D_00969B30[lolo.dwMapId];
	if(lolo.bp_1c < 0)
		lolo.bp_1c += D_00969B34[lolo.dwMapId];
	lolo.local_9 = D_00969B30[lolo.dwMapId] * lolo.bp_1c + lolo.bp_14;
	if(lolo.dwMapId == 0) {//else 0075350C
		if(D_00E28CB4 > 0 && lolo.bp_14 >= 4 && lolo.bp_14 <= 5 && lolo.bp_1c >= 4 && lolo.bp_1c <= 5)
			lolo.local_9 = lolo.bp_1c * 2 + lolo.bp_14 + 0x33;
		if(D_00E28CB4 > 1 && lolo.bp_14 >= 4 && lolo.bp_14 <= 6 && lolo.bp_1c >= 3 && lolo.bp_1c <= 4)
			lolo.local_9 = (lolo.bp_1c - 3) * 3 + lolo.bp_14 + 0x3f;
		if(D_00E28CB4 > 2 && lolo.bp_14 >= 5 && lolo.bp_14 <= 6 && lolo.bp_1c >= 5)
			lolo.local_9 = lolo.bp_1c * 2 + lolo.bp_14 + 0x3a;
		if(D_00E28CB4 > 3 && lolo.bp_14 >= 1 && lolo.bp_14 <= 3 && lolo.bp_1c >= 4 && lolo.bp_1c <= 5)
			lolo.local_9 = (lolo.bp_1c - 4) * 3 + lolo.bp_14 + 0x4c;
	}
	C_007593CD(C_0074CA00(1/*"WM?.BOT"*/, lolo.dwMapId), (lolo.local_9 * 0xb800) * 4, 0xb800 * 4/*0x2e000*/, D_00E045FC, 0);//wmfile:read file
	D_00E28970 = &(D_00E04928[4]);
	D_00E28C28 = &(D_00E04928[0]);
	D_00E04928[3].pNext = 0;//00E04940
	for(lolo.bp_18 = 0; lolo.bp_18 < 2; lolo.bp_18 ++) {
		for(lolo.bp_28 = 0; lolo.bp_28 < 2; lolo.bp_28 ++) {
			D_00E04928[lolo.bp_18 * 2 + lolo.bp_28].f_04 = /*bp_2c*/(lolo.dwMapId == 2)?
				(((lolo.bp_1c + lolo.bp_18) % 4) + 2) * 9 + ((lolo.bp_14 + lolo.bp_28) % 3) + 3:
				/*bp_30*/(lolo.dwMapId == 3)?
					((lolo.bp_1c + lolo.bp_18) & 1) * 9 + ((lolo.bp_14 + lolo.bp_28) & 1):
					((lolo.bp_1c + lolo.bp_18) % 7) * 9 + ((lolo.bp_14 + lolo.bp_28) % 9)
			;
		}//end for
	}//end for
}

unsigned char *__0075363D(short bp08) {
	struct {
		struct t_wm_local_08_ter *local_4;
		struct t_wm_local_08_ter *local_3;
		struct t_wm_local_08_ter *local_2;
		struct t_wm_local_08_ter *local_1;
	}lolo;

	//-- --
	if(D_00E28CBC)
		C_0074C9A0(0xe);//<empty>:some error management?
	//-- --
	for(
		lolo.local_3 = 0, lolo.local_2 = D_00E28C24;
		lolo.local_2;
		lolo.local_3 = lolo.local_2, lolo.local_2 = lolo.local_2->pNext
	);
	if(lolo.local_3) {
		lolo.local_3->pNext = D_00E28B7C;
		D_00E28B7C = D_00E28C24;
		D_00E28C24 = 0;
	}
	for(
		lolo.local_4 = 0, lolo.local_1 = D_00E28CB0;
		lolo.local_1;
		lolo.local_4 = lolo.local_1, lolo.local_1 = lolo.local_1->pNext
	);
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
			//-- make it the new head --
			lolo.local_1->pNext = D_00E28970;
			D_00E28970 = lolo.local_1;
			//-- --
			lolo.local_1 = /*lolo.local_5*/lolo.local_4?lolo.local_4->pNext:D_00E28C28;
		} else {
			lolo.local_4 = lolo.local_1;
			lolo.local_1 = lolo.local_1->pNext;
		}
	}//end for

	return D_00E045FC[bp08];
}

void C_0075378A(int bp08) {
	D_00E28CC0 = 2;
	D_00E28C2C = bp08;
}

void C_007537A1(int bp08) {
	D_00E28CB4 = bp08;
}

void C_007537AE(struct VECTOR *bp08) {
	struct {
		struct SVECTOR *local_3;
		struct SVECTOR *local_2;
		struct SVECTOR *local_1;
	}lolo;

	lolo.local_2 = &(D_00E28CD0->f_0c[D_00E04608->vect0]);
	lolo.local_3 = &(D_00E28CD0->f_0c[D_00E04608->vect1]);
	lolo.local_1 = &(D_00E28CD0->f_0c[D_00E04608->vect2]);
	bp08->f_00 = lolo.local_2->f_00 + lolo.local_3->f_00 + lolo.local_1->f_00;
	bp08->f_04 = lolo.local_2->f_02 + lolo.local_3->f_02 + lolo.local_1->f_02;
	bp08->f_08 = lolo.local_2->f_04 + lolo.local_3->f_04 + lolo.local_1->f_04;
}
