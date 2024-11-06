/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//WORLD MAP -- Manage Terrain

#include "ff7.h"
#include "wm_data.h"
////////////////////////////////////////
struct t_wm_local_BlockLoadInfo {//size 8
	/*00*/struct t_wm_local_BlockLoadInfo *pNext;
	/*04*/short wBlockId;//(chunkY << 2) | chunkX?
	/*06*/short f_06;//index in "pool(2)"(D_00E04928)
};

struct t_wm_local_ChunkLoadInfo {//size 8
	/*00*/struct t_wm_local_ChunkLoadInfo *pNext;
	/*04*/struct t_wm_TerrainChunkInfo *pChunk;
};
////////////////////////////////////////
#define LIST_POP(elt,lst) (elt) = (lst), (lst) = (elt)->pNext
#define LIST_PUSH(elt, lst) (elt)->pNext = (lst), (lst) = (elt)

#define LIST_REMOVE(elt, prev, lst)   \
	if(prev)                          \
		(prev)->pNext = (elt)->pNext; \
	else                              \
		(lst) = (elt)->pNext          \

#define LIST_NEXT(elt, prev) (prev) = (elt), (elt) = (elt)->pNext

#define LIST_NEXT_0(elt, prev, lst) (elt) = (prev)?(prev)->pNext:(lst)
////////////////////////////////////////
struct t_wm_TerrainChunkInfo *D_00E045F8;//[3]"loaded chunks" head?
unsigned char (*D_00E045FC)[0xb800];//[1]compressed map block data/may contain up to 9 elements
int D_00E04600;//[1]last read chunk data index
int D_00E04604;//[0]chocobo farm related flag?
struct t_wm_TerrainTriangle *D_00E04608;//[0]
struct t_wm_TerrainChunkInfo D_00E04610[0x20];//[3]"loaded chunks pool"?
int D_00E04910;//[2]
//00E04914
struct VECTOR D_00E04918;
struct t_wm_local_BlockLoadInfo D_00E04928[9];//[1]"scheduled to load pool"
unsigned char D_00E04970[0x20][0x1200];//decompressed chunk data//0x24000
struct t_wm_local_BlockLoadInfo *D_00E28970;//[1]"scheduled to load pool" head
//00E28974
struct t_wm_local_ChunkLoadInfo D_00E28978[0x40];//[2]"must load chunks" pool
struct t_wm_local_ChunkLoadInfo *D_00E28B78;//[2]"must load chunks" head
struct t_wm_local_BlockLoadInfo *D_00E28B7C;//[1]"must load pool" head
struct t_wm_local_BlockLoadInfo D_00E28B80[0x14];//[1]"must load blocks pool"
int D_00E28C20;//[1]
struct t_wm_local_BlockLoadInfo *D_00E28C24;//[1]head of "scheduled to load"
struct t_wm_local_BlockLoadInfo *D_00E28C28;//[1]head of list "loaded blocks"?
int D_00E28C2C;//[0]
struct VECTOR D_00E28C30;
int D_00E28C40;//[1]frame counter for chunk loading fade in/out
int D_00E28C44;
char D_00E28C48[0x64];//debug string
int D_00E28CAC;//[1]counter to next load?cdrom latency related?
struct t_wm_local_BlockLoadInfo *D_00E28CB0;//[1]head of "scheduled to load(2)"
int D_00E28CB4;//[1]world map state
int D_00E28CB8;
int D_00E28CBC;//[0]
int D_00E28CC0;//[0]
struct t_wm_TerrainChunkInfo *D_00E28CC4;//[3]"sheduled chunks" head?
int D_00E28CC8;
struct t_wm_TerrainChunkInfo *D_00E28CCC;//[3]head of "loaded chunks pool"?
struct t_wm_TerrainChunkInfo *D_00E28CD0;//[0]
int D_00E28CD4;//[0]bridge move counter
struct t_wm_local_ChunkLoadInfo *D_00E28CD8;//[2]"must load chunks" pool head
int D_00E28CDC;//[0]flag:allow control/move?
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

//wm:world to chunk coordinates?
void C_00750134(struct VECTOR *bp08, struct SVECTOR *bp0c, short *pChunkX/*bp10*/, short *pChunkY/*bp14*/) {
	//-- --
	if(pChunkX) {
		*pChunkX = bp08->vx >> 13;
		if(*pChunkX < 0)
			*pChunkX += 0x24;
		else if(*pChunkX >= 0x24)
			*pChunkX -= 0x24;
	}
	//-- --
	if(pChunkY) {
		*pChunkY = bp08->vz >> 13;
		if(*pChunkY < 0)
			*pChunkY += 0x1c;
		else if(*pChunkY >= 0x1c)
			*pChunkY -= 0x1c;
	}
	//-- --
	if(bp0c) {
		bp0c->vx = bp08->vx & 0x1fff;
		bp0c->vy = 0;
		bp0c->vz = bp08->vz & 0x1fff;
	}
}

//wm:clamp x,z?
void C_00750202(struct VECTOR *bp08) {
	if(bp08) {//else 0075027A
		if(bp08->vx >= (0x24 << 13))
			bp08->vx -= (0x24 << 13);
		else if(bp08->vx < 0)
			bp08->vx += (0x24 << 13);

		if(bp08->vz >= (0x1c << 13))
			bp08->vz -= (0x1c << 13);
		else if(bp08->vz < 0)
			bp08->vz += (0x1c << 13);
	}
}

//wm:set some pos?
void C_0075027C(struct VECTOR *bp08, int bp0c) {
	struct {
		int dwDiffZ;//local_2
		int dwDiffX;//local_1
	}lolo;

	if(C_0074D30F() != 2) {//wm:get some zoom/rotation mode?//else 00750427
		if(bp0c < 0)
			D_00E28CC8 = 0;
		else if(D_00E04910)
			D_00E28CC8 |= bp0c;
		if(D_00E28CC8) {//else 00750403
			if(bp08->vx - D_00E04918.vx > (0x12 << 13))
				D_00E04918.vx += (0x24 << 13);
			else if(bp08->vx - D_00E04918.vx < -(0x12 << 13))
				D_00E04918.vx -= (0x24 << 13);
			if(bp08->vz - D_00E04918.vz > (0xe << 13))
				D_00E04918.vz += (0x1c << 13);
			else if(bp08->vz - D_00E04918.vz < -(0xe << 13))
				D_00E04918.vz -= (0x1c << 13);
			D_00E04918.vx = (D_00E04918.vx * 3 + bp08->vx) >> 2;
			D_00E04918.vz = (D_00E04918.vz * 3 + bp08->vz) >> 2;
			C_00750202(&D_00E04918);//wm:clamp x,z?
#define LOCAL_ABS(res,val) if((val) > 0) (res) = (val); else (res) = -(val)
			LOCAL_ABS(lolo.dwDiffX, bp08->vx - D_00E04918.vx);
			LOCAL_ABS(lolo.dwDiffZ, bp08->vz - D_00E04918.vz);
#undef LOCAL_ABS
			D_00E28CC8 = (lolo.dwDiffX + lolo.dwDiffZ) > 10;
		} else {//else 00750427
			D_00E04918 = *bp08;
		}
	}
}

//wm:get some pos?
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

//wm:terrain init/reset stuff?
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
	D_00E28CD8 = &(D_00E28978[0]);
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

void C_007506B6() {
	C_007506C0();
}

void C_007506C0() {
	struct {
		struct t_wm_local_BlockLoadInfo *pPrevElt;//local_2
		struct t_wm_local_BlockLoadInfo *pElt;//local_1
	}lolo;

	D_00E28CBC = 0;
	if(D_00E04600 >= 0 && D_00E28CAC >= D_00DFC480 * 5) {
		for(
			lolo.pPrevElt = 0, lolo.pElt = D_00E28CB0;//head of "scheduled to load(2)"
			lolo.pElt && lolo.pElt != &(D_00E04928[D_00E04600]);
			LIST_NEXT(lolo.pElt, lolo.pPrevElt)
		);
		//-- --
		if(lolo.pElt == 0)
			C_0074C9A0(0xd);//<empty>:some error management?
		//-- --
		LIST_REMOVE(lolo.pElt, lolo.pPrevElt, D_00E28CB0);//head of "scheduled to load(2)"
		//-- back to "pool" --
		LIST_PUSH(lolo.pElt, D_00E28970);
		//-- --
		D_00E28CAC = 0;
		D_00E04600 = -1;
	}
	//-- --
	//
}

void C_00750784() {
	D_00E28CBC = 1;
}

int __00750793() {
	return D_00E28CBC;
}

void C_007509B2(struct VECTOR *);//update chunks/blocks lists?
void C_00750D99(short, short);//try load 1 scheduled chunk data?
void C_007511CD(void );//remove loaded block from list
short C_007512EA(void);//count "scheduled to load(2)"?
void C_00751408(void);//parse "must load chunks" list and decompress block data if present?
void C_0075164A(struct VECTOR *, short);//make new chunks list?
void C_00751EFC(struct VECTOR *, struct VECTOR *, struct VECTOR *, short);//render terrain:
void C_00753348(void);//<empty>

//wm:refresh terrain stuff?
void C_0075079D(short wAngle/*bp08*/, int bp0c) {
	struct {
		DECL_short(wChunkY);
		int local_20;
		DECL_short(wChunkX);
		struct SVECTOR local_18;
		struct VECTOR local_16;
		struct VECTOR local_12;
		struct VECTOR local_8;
		struct VECTOR local_4;
	}lolo;

	C_007616B3();//wm:set some info(1)?
	C_00762798(&lolo.local_8);//wm:get model pos(2)?
	C_00762802(&lolo.local_4);//wm:get model previous pos(2)?
	//-- --
	if(D_00E28CBC) {//else 00750922
		lolo.local_18.vx =
		lolo.local_18.vy = 0;
		lolo.local_18.vz = -0x2000;//0xe000
		C_00753D00(&lolo.local_18, -wAngle);//wm:SVECTOR z rotation?
		lolo.local_16.vx = lolo.local_8.vx + lolo.local_18.vx;
		lolo.local_16.vy = lolo.local_8.vy;
		lolo.local_16.vz = lolo.local_8.vz + lolo.local_18.vz;
		if(lolo.local_16.vx < 0)
			lolo.local_16.vx += (0x24 << 13);
		else if(lolo.local_16.vx >= (0x24 << 13))
			lolo.local_16.vx -= (0x24 << 13);
		if(lolo.local_16.vz < 0)
			lolo.local_16.vz += (0x1c << 13);
		else if(lolo.local_16.vz >= (0x1c << 13))
			lolo.local_16.vz -= (0x1c << 13);
		C_007509B2(&lolo.local_16);//update chunks/blocks lists?
		C_0075164A(&lolo.local_8, wAngle);//make new chunks list?
		C_00750134(&lolo.local_16, 0, &lolo.wChunkX, &lolo.wChunkY);//wm:world to chunk coordinates?
		C_00750D99(lolo.wChunkX, lolo.wChunkY);//try load 1 scheduled chunk data?
		C_007511CD();//remove loaded block from list
		C_00751408();//parse "must load chunks" list and decompress block data if present?
		//-- fade in/out --
		//(in case more than 2 new chunks for 5 seconds(300 frames)?)
		lolo.local_20 = D_00E28C40;
		D_00E28C40 = /*lolo.local_22*/(C_007512EA() > 2)?D_00E28C40 + 1:0;//count "scheduled to load(2)"?
		if(lolo.local_20 < 300 && D_00E28C40 >= 300)
			C_0074D955(1/*fade out*/);//wm:start some fade in/out?
		else if(lolo.local_20 >= 300 && D_00E28C40 == 0)
			C_0074D955(4/*fade out*/);//wm:start some fade in/out?
		//-- --
	}
	//-- --
	if(C_00766B53() == 2)//wm:get "leave vehicle" state?
		C_00766417(0);
	else if(D_00E28CC0 == 1)
		C_00766417(D_00E28C2C);
	//-- --
	C_00762798(&lolo.local_12);//wm:get model pos(2)?
	D_00E37D28 = 5500;//[camera occlusion]distance threshold?
	D_00E37524 = (C_0074D330() == 2)?16000:0;//[undersea fog]distance threshold?
	//-- --
	if(bp0c)
		C_00751EFC(&lolo.local_4, &lolo.local_8, &lolo.local_12, wAngle);//render terrain:
	//-- --
	if(C_0074D4DC())//wm:returns true[debug stuff?]
		C_00753348();//<empty>
	//-- --
}

short C_00750C20(short, short);//make blockId
struct t_wm_local_BlockLoadInfo *C_00750C84(struct t_wm_local_BlockLoadInfo *);

//update chunks/blocks lists?
void C_007509B2(struct VECTOR *bp08) {
	struct {
		int dwY_1;//local_11
		int dwY_0;//local_10
		int dwY;//local_9
		int dwX;//local_8
		int dwX_1;//local_7
		struct t_wm_local_BlockLoadInfo *pPrevBlock;//local_6
		int dwX_0;//local_5
		struct t_wm_local_BlockLoadInfo *bp_10;//local_4
		struct t_wm_local_BlockLoadInfo *pMustLoadHead;//local_3
		struct t_wm_local_BlockLoadInfo *pElt;//local_2
		struct t_wm_local_BlockLoadInfo *pBlock;//local_1
	}lolo;

	lolo.dwX_0 = (bp08->vx - (2 << 13)) / (4 << 13);
	lolo.dwY_0 = (bp08->vz - (2 << 13)) / (4 << 13);
	lolo.dwX_1 =  (bp08->vx + (2 << 13)) / (4 << 13);
	lolo.dwY_1 =  (bp08->vz + (2 << 13)) / (4 << 13);

	lolo.pMustLoadHead = 0;
	//-- make "must load" list --
	//(4 new elements)
	for(lolo.dwY = lolo.dwY_0; lolo.dwY <= lolo.dwY_1; lolo.dwY ++) {
		for(lolo.dwX = lolo.dwX_0; lolo.dwX <= lolo.dwX_1; lolo.dwX ++) {
			lolo.pElt = D_00E28B7C;
			//-- --
			if(lolo.pElt == 0)
				C_0074C9A0(0xa);//<empty>:some error management?
			//-- --
			D_00E28B7C = lolo.pElt->pNext;
			lolo.pElt->pNext = lolo.pMustLoadHead;
			lolo.pMustLoadHead = lolo.pElt;
			lolo.pElt->wBlockId = C_00750C20(lolo.dwX, lolo.dwY);//make blockId
		}//end for
	}//end for
	//-- remove duplicates --
	//("loaded blocks"?)
	for(lolo.pPrevBlock = 0, lolo.pBlock = D_00E28C28; lolo.pBlock; ) {//head of "loaded blocks"?
		lolo.bp_10 = 0;
		for(
			lolo.pElt = lolo.pMustLoadHead;
			lolo.pElt && lolo.pElt->wBlockId != lolo.pBlock->wBlockId;
			LIST_NEXT(lolo.pElt, lolo.bp_10)
		);
		if(lolo.pElt) {//else 00750B66
			//-- remove from list/put back in "pool" --
			LIST_REMOVE(lolo.pElt, lolo.bp_10, lolo.pMustLoadHead);
			LIST_PUSH(lolo.pElt, D_00E28B7C);
			//-- --
			if(lolo.pPrevBlock) {
				lolo.pPrevBlock->pNext = lolo.pBlock->pNext;
				//-- --
				LIST_PUSH(lolo.pBlock, D_00E28C28);//head of "loaded blocks"?
				//-- --
				lolo.pBlock = lolo.pPrevBlock->pNext;
			} else {
				LIST_NEXT(lolo.pBlock, lolo.pPrevBlock);
			}
		} else {
			LIST_NEXT(lolo.pBlock, lolo.pPrevBlock);
		}
	}//end for
	//-- remove duplicates --
	//"scheduled to load(2)"
	for(lolo.pBlock = D_00E28CB0; lolo.pBlock; lolo.pBlock = lolo.pBlock->pNext) {//head of "scheduled to load(2)"
		lolo.bp_10 = 0;
		for(
			lolo.pElt = lolo.pMustLoadHead;
			lolo.pElt && lolo.pElt->wBlockId != lolo.pBlock->wBlockId;
			LIST_NEXT(lolo.pElt, lolo.bp_10)
		);
		if(lolo.pElt) {
			//-- remove from list/put back in "pool" --
			LIST_REMOVE(lolo.pElt, lolo.bp_10, lolo.pMustLoadHead);
			LIST_PUSH(lolo.pElt, D_00E28B7C);
			//-- --
		}
	}//end for
	//-- --
	for(
		lolo.pElt = lolo.pMustLoadHead;
		lolo.pElt;
		lolo.pElt = C_00750C84(lolo.pElt)
	);
}

//make blockId
short C_00750C20(short wX/*bp08*/, short wY/*bp0c*/) {
	if(wX < 0)
		wX += 9;
	if(wX >= 9)
		wX -= 9;
	if(wY < 0)
		wY += 7;
	if(wY >= 7)
		wY -= 7;

	return wY * 9 + wX;
}

struct t_wm_local_BlockLoadInfo *C_00750D06(void);//new "scheduled" element

struct t_wm_local_BlockLoadInfo *C_00750C84(struct t_wm_local_BlockLoadInfo *bp08) {
	struct {
		struct t_wm_local_BlockLoadInfo *pNextElt;//local_2
		struct t_wm_local_BlockLoadInfo *pNewElt;//local_1
	}lolo;

	lolo.pNextElt = 0;
	lolo.pNewElt = C_00750D06();//new "scheduled" element
	if(lolo.pNewElt) {
		bp08->f_06 = (lolo.pNewElt - &(D_00E04928[0]));
		D_00E04928[bp08->f_06].wBlockId = bp08->wBlockId;
		lolo.pNextElt = bp08->pNext;
		//-- schedule to load --
		LIST_PUSH(bp08, D_00E28C24);//head of "scheduled to load"
	} else {
		lolo.pNextElt = bp08->pNext;
		//-- put back in "pool" --
		LIST_PUSH(bp08, D_00E28B7C);
	}

	return lolo.pNextElt;
}

//new "scheduled" element
struct t_wm_local_BlockLoadInfo *C_00750D06() {
	struct {
		struct t_wm_local_BlockLoadInfo *pPrevElt;//local_2
		struct t_wm_local_BlockLoadInfo *pNewElt;//local_1
	}lolo;
	
	lolo.pNewElt = 0;
	if(D_00E28970) {
		LIST_POP(lolo.pNewElt, D_00E28970);
	} else {
		//if no element from pool is available
		//take the tail from the "loaded blocks" list
		lolo.pNewElt = D_00E28C28;//head of "loaded blocks"?
		if(lolo.pNewElt) {
			for(
				lolo.pPrevElt = 0;
				lolo.pNewElt->pNext;
				LIST_NEXT(lolo.pNewElt, lolo.pPrevElt)
			);
			if(lolo.pPrevElt)
				lolo.pPrevElt->pNext = 0;
			else
				lolo.pNewElt = 0;
		}
	}
	if(lolo.pNewElt) {
		LIST_PUSH(lolo.pNewElt, D_00E28CB0);//head of "scheduled to load(2)"
	}

	return lolo.pNewElt;
}

void C_00750EFA(struct t_wm_local_BlockLoadInfo *, struct t_wm_local_BlockLoadInfo *);//remove from scheduled list->load

//try load 1 scheduled chunk data?
void C_00750D99(short wChunkX/*bp08*/, short wChunkY/*bp0c*/) {
	struct {
		int dwDstChunkY;//local_10
		struct t_wm_local_BlockLoadInfo *local_9;
		int dwMaxDst;//local_8
		struct t_wm_local_BlockLoadInfo *local_7;
		int dwDstChunkX;//local_6
		int dwCurChunkY;//local_5
		int dwCurChunkX;//local_4
		struct t_wm_local_BlockLoadInfo *local_3;
		struct t_wm_local_BlockLoadInfo *local_2;
		int dwDst;//local_1
	}lolo;

	if(D_00E28CAC == 0 && D_00E28C24 != 0 && C_007538C9(0)) {//wm:start something(unused)?
		lolo.local_7 =
		lolo.local_9 = 0;
		lolo.dwMaxDst = 0x7fff;
		lolo.local_3 = 0;
		for(
			lolo.local_2 = D_00E28C24;//head of "scheduled to load"
			lolo.local_2;
			LIST_NEXT(lolo.local_2, lolo.local_3)
		) {
			lolo.dwCurChunkY = lolo.local_2->wBlockId / 4;
			lolo.dwCurChunkX = lolo.local_2->wBlockId - lolo.dwCurChunkY * 4;
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
		C_00750EFA(lolo.local_7, lolo.local_9);//remove from scheduled list->load
	}
}

void C_00750F3C(struct t_wm_local_BlockLoadInfo *);//load block data

//remove from scheduled list->load
void C_00750EFA(struct t_wm_local_BlockLoadInfo *bp08, struct t_wm_local_BlockLoadInfo *bp0c) {
	LIST_REMOVE(bp08, bp0c, D_00E28C24);//head of "scheduled to load"
	C_00750F3C(bp08);//load block data
	//-- put back in "pool" --
	LIST_PUSH(bp08, D_00E28B7C);
}

void C_007512C2(void);//set "latency" counter?

//load block data
void C_00750F3C(struct t_wm_local_BlockLoadInfo *bp08) {
	struct {
		int local_6;
		int local_5;
		int local_4;
		int local_3;
		int dwMapId;//local_2
		int dwBlockId;//local_1
	}lolo;

	lolo.dwMapId = C_0074D330();//wm:get current map id?
	lolo.dwBlockId = 
	D_00E28C20 = /*lolo.local_13*/(lolo.dwMapId == 0)?
		/*lolo.local_7*/(D_00E28CB4 > 0 && bp08->wBlockId == 0x32)?0x3f:
		/*lolo.local_8*/(D_00E28CB4 > 1 && bp08->wBlockId == 0x29)?0x40:
		/*lolo.local_9*/(D_00E28CB4 > 1 && bp08->wBlockId == 0x2a)?0x41:
		/*lolo.local_10*/(D_00E28CB4 > 2 && bp08->wBlockId == 0x3c)?0x42:
		/*lolo.local_11*/(D_00E28CB4 > 3 && bp08->wBlockId == 0x2f)?0x43:
		/*lolo.local_12*/(D_00E28CB4 > 3 && bp08->wBlockId == 0x30)?0x44:
			bp08->wBlockId:
		bp08->wBlockId
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

		lolo.dwBlockId = lolo.local_4 * 3 + lolo.local_3;
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

		lolo.dwBlockId = lolo.local_6 * 2 + lolo.local_5;
	}
	C_007593CD(C_0074CA00(0/*"WM?.MAP"*/, lolo.dwMapId), lolo.dwBlockId * 0xb800, 0xb800, D_00E045FC[bp08->f_06], 0);//wmfile:read file
	//-- --
	D_00E28CAC = D_00DFC480 * 5;
	D_00E04600 = bp08->f_06;
	C_007512C2();//set "latency" counter?
}

void C_00751322(struct t_wm_local_BlockLoadInfo *);

//remove loaded block from list
void C_007511CD() {
	struct {
		struct t_wm_local_BlockLoadInfo *pPrevElt;//local_2
		struct t_wm_local_BlockLoadInfo *pElt;//local_1
	}lolo;

	//
	if(D_00E28CAC < D_00DFC480 * 5 && D_00E04600 >= 0) {//else 00751285
		for(
			lolo.pPrevElt = 0, lolo.pElt = D_00E28CB0;//head of "scheduled to load(2)"
			lolo.pElt && lolo.pElt != &(D_00E04928[D_00E04600]);
			LIST_NEXT(lolo.pElt, lolo.pPrevElt)
		);
		//-- --
		if(lolo.pElt == 0)
			C_0074C9A0(0xb);//<empty>:some error management?
		//-- remove from list --
		//"scheduled to load(2)"
		LIST_REMOVE(lolo.pElt, lolo.pPrevElt, D_00E28CB0);//head of "scheduled to load(2)"
		//-- add to list --
		//
		LIST_PUSH(lolo.pElt, D_00E28C28);//head of "loaded blocks"?
		//-- --
		C_00751322(lolo.pElt);
		D_00E04600 = -1;
	}
	//-- decrement "latency" counter --
	D_00E28CAC -= /*lolo.local_3*/(D_00E28CAC != 0 && D_00E28CAC < D_00DFC480 * 5);
}

//set "latency" counter?
void C_007512C2() {
	if(D_00E04600 >= 0) {
		D_00E28CAC = D_00DFC480 * 5 - 1;
		C_0075395E(0);//wm:stop something(unused)?
	}
}

//count "scheduled to load(2)"?
short C_007512EA() {
	struct {
		int dwCount;//local_2
		struct t_wm_local_BlockLoadInfo *local_1;
	}lolo;

	for(
		lolo.dwCount = 0, lolo.local_1 = D_00E28CB0;//head of "scheduled to load(2)"
		lolo.local_1;
		lolo.dwCount ++, lolo.local_1 = lolo.local_1->pNext
	);

	return lolo.dwCount;
}

void C_00751374(struct t_wm_TerrainChunkInfo *);//check for loaded chunks?

void C_00751322(struct t_wm_local_BlockLoadInfo *bp08) {
	struct t_wm_TerrainChunkInfo *pChunk;

	for(pChunk = D_00E28CC4; pChunk; pChunk = pChunk->pNext) {
		if((pChunk->wChunkY >> 2) * 9 + (pChunk->wChunkX >> 2) == bp08->wBlockId)
			C_00751374(pChunk);//check for loaded chunks?
	}//end for
}

//check for loaded chunks?
void C_00751374(struct t_wm_TerrainChunkInfo *pChunk/*bp08*/) {
	struct t_wm_local_ChunkLoadInfo *local_1;

	for(
		local_1 = D_00E28B78;
		local_1 && (local_1->pChunk->wChunkX != pChunk->wChunkX || local_1->pChunk->wChunkY != pChunk->wChunkY);
		local_1 = local_1->pNext
	);
	//-- if necessary, add to "must load chunks" --
	if(local_1 == 0) {
		//-- --
		if(D_00E28CD8 == 0)
			C_0074C9A0(0x16);//<empty>:some error management?
		//-- remove from "pool" --
		LIST_POP(local_1, D_00E28CD8);
		LIST_PUSH(local_1, D_00E28B78);
		//-- --
		local_1->pChunk = pChunk;
	}
}

void C_0075155A(struct t_wm_TerrainChunkInfo *, struct t_wm_local_BlockLoadInfo *);//decompress/get chunk data?

//parse "must load chunks" list and decompress block data if present?
void C_00751408() {
	struct {
		struct t_wm_local_BlockLoadInfo *pBlock;//local_6
		int dwBlockId;//local_5
		struct t_wm_TerrainChunkInfo *pPrevChunk;//local_4
		int local_3;
		struct t_wm_local_ChunkLoadInfo *local_2;
		struct t_wm_TerrainChunkInfo *pChunk;//local_1
	}lolo;

	for(lolo.local_3 = 0; D_00E28B78 && !lolo.local_3; lolo.local_3 = D_00E04910) {
		lolo.local_2 = D_00E28B78;//"must load chunks"
		//-- --
		if(lolo.local_2->pChunk == 0)
			C_0074C9A0(0xc);//<empty>:some error management?
		//-- --
		lolo.dwBlockId = (lolo.local_2->pChunk->wChunkY >> 2) * 9 + (lolo.local_2->pChunk->wChunkX >> 2);
		for(
			lolo.pBlock = D_00E28C28;//head of "loaded blocks"?
			lolo.pBlock && lolo.pBlock->wBlockId != lolo.dwBlockId;
			lolo.pBlock = lolo.pBlock->pNext
		);
		if(lolo.pBlock) {//else 00751547
			C_0075155A(lolo.local_2->pChunk, lolo.pBlock);//decompress/get chunk data?
			for(
				lolo.pPrevChunk = 0, lolo.pChunk = D_00E28CC4;
				lolo.pChunk && lolo.pChunk != lolo.local_2->pChunk;
				LIST_NEXT(lolo.pChunk, lolo.pPrevChunk)
			);
			//-- --
			if(lolo.pChunk == 0)
				C_0074C9A0(0x17);//<empty>:some error management?
			//-- --
			LIST_REMOVE(lolo.pChunk, lolo.pPrevChunk, D_00E28CC4);
			LIST_PUSH(lolo.pChunk, D_00E045F8);
			D_00E28B78 = lolo.local_2->pNext;//"must load chunks"
			LIST_PUSH(lolo.local_2, D_00E28CD8);
		}
	}//end for
	D_00E04910 = 1;
}

//decompress/get chunk data?
void C_0075155A(struct t_wm_TerrainChunkInfo *pChunk/*bp08*/, struct t_wm_local_BlockLoadInfo *pBlock/*bp0c*/) {
	struct {
		short *local_3;
		unsigned char *pInflated;//local_2
		unsigned *pCompressed;//local_1
	}lolo;

	lolo.pCompressed = (unsigned *)D_00E045FC[pBlock - &(D_00E04928[0])];
	lolo.pInflated = D_00E04970[pChunk - &(D_00E04610[0])];
	lolo.pCompressed += lolo.pCompressed[((pChunk->wChunkY & 3) << 2) | (pChunk->wChunkX & 3)] >> 2;
	C_0074FFC0((unsigned char *)lolo.pCompressed, lolo.pInflated);//some inflate function[world map]?
	lolo.local_3 = (short *)lolo.pInflated;
	pChunk->f_04 = (struct t_wm_TerrainTriangle *)&(lolo.local_3[2]);
	pChunk->wTriangleCount = lolo.local_3[0];
	pChunk->pVertices = (struct SVECTOR *)&(pChunk->f_04[pChunk->wTriangleCount]);
	pChunk->pNormals = &(pChunk->pVertices[lolo.local_3[1]]);
	C_00760E1D(&(pChunk->f_04[0]), &(pChunk->f_04[pChunk->wTriangleCount]), 1);//wm:adjust terrain triangle u,v?
}

struct t_wm_local_BlockLoadInfo *C_007518F6(short);//look for in "loaded blocks"?
int C_00751962(short);//block already in "scheduled to load(2)"?
int C_0075199C(void);//refresh/count loaded chunks?
void C_00751AC4(struct VECTOR *, short, int [][5]);//make chunk "flag map"?
int C_00751D44(struct t_wm_TerrainChunkInfo *, short, short, short *, short *);//make chunk distance?
struct t_wm_TerrainChunkInfo *C_00751E43(void);//"alloc" element?

//make new chunks list?
void C_0075164A(struct VECTOR *sWorldPos/*bp08*/, short wAngle/*bp0c*/) {
	struct {
		struct t_wm_local_BlockLoadInfo *pBlock;//bp_8c
		DECL_short(wNewChunkX);
		int dwBlockId;//bp_84
		DECL_short(wChunkY);//local_32
		DECL_short(j);//local_31
		DECL_short(i);//local_30
		int bp_74[5][5];//local_29
		DECL_short(wChunkX);//local_4
		struct t_wm_local_BlockLoadInfo *bp_0c;
		DECL_short(wNewChunkY);
		struct t_wm_TerrainChunkInfo *pChunk;//local_1
	}lolo;

	//-- --
	if(C_0075199C() >= 16)//refresh/count loaded chunks?
		return;
	//-- --
	C_00750134(sWorldPos, 0, &lolo.wChunkX, &lolo.wChunkY);//wm:world to chunk coordinates?
	C_00751AC4(sWorldPos, wAngle, lolo.bp_74);//make chunk "flag map"?
	for(lolo.pChunk = D_00E045F8; lolo.pChunk; lolo.pChunk = lolo.pChunk->pNext) {
		if(C_00751D44(lolo.pChunk, lolo.wChunkX, lolo.wChunkY, &lolo.i, &lolo.j))//make chunk distance?
			lolo.bp_74[lolo.j + 2][lolo.i + 2] = 0;
	}//end for
	for(lolo.pChunk = D_00E28CC4; lolo.pChunk; lolo.pChunk = lolo.pChunk->pNext) {
		if(C_00751D44(lolo.pChunk, lolo.wChunkX, lolo.wChunkY, &lolo.i, &lolo.j))//make chunk distance?
			lolo.bp_74[lolo.j + 2][lolo.i + 2] = 0;
	}//end for
	for(lolo.j = 0; lolo.j < 5; lolo.j ++) {
		for(lolo.i = 0; lolo.i < 5; lolo.i ++) {
			if(lolo.bp_74[lolo.j][lolo.i]) {//else 007518E8
				//-- --
				lolo.wNewChunkX = lolo.i + lolo.wChunkX - 2;
				if(lolo.wNewChunkX < 0)
					lolo.wNewChunkX += 0x24;
				else if(lolo.wNewChunkX >= 0x24)
					lolo.wNewChunkX -= 0x24;
				//-- --
				lolo.wNewChunkY = lolo.j + lolo.wChunkY - 2;
				if(lolo.wNewChunkY < 0)
					lolo.wNewChunkY += 0x1c;
				else if(lolo.wNewChunkY >= 0x1c)
					lolo.wNewChunkY -= 0x1c;
				//-- --
				lolo.pChunk = C_00751E43();//"alloc" element?
				if(lolo.pChunk) {//else 007518E8
					lolo.pChunk->wChunkX = lolo.wNewChunkX;
					lolo.pChunk->wChunkY = lolo.wNewChunkY;
					lolo.dwBlockId = (lolo.wNewChunkY >> 2) * 9 + (lolo.wNewChunkX >> 2);
					lolo.pBlock = C_007518F6(lolo.dwBlockId);//look for in "loaded blocks"?
					if(lolo.pBlock) {
						C_00751374(lolo.pChunk);//check for loaded chunks?
					} else if(!C_00751962(lolo.dwBlockId)) {//block already in "scheduled to load(2)"?
						//-- --
						if(D_00E28B7C == 0)
							C_0074C9A0(0xf);//<empty>:some error management?
						//-- --
						LIST_POP(lolo.bp_0c, D_00E28B7C);
						lolo.bp_0c->wBlockId = lolo.dwBlockId;
						C_00750C84(lolo.bp_0c);
					}
				}
			}
		}//end for
	}//end for
}

//look for in "loaded blocks"?
struct t_wm_local_BlockLoadInfo *C_007518F6(short wBlockId/*bp08*/) {
	struct {
		struct t_wm_local_BlockLoadInfo *pPrevBlock;//local_2
		struct t_wm_local_BlockLoadInfo *pBlock;//local_1
	}lolo;

	for(
		lolo.pPrevBlock = 0, lolo.pBlock = D_00E28C28;//head of "loaded blocks"?
		lolo.pBlock && lolo.pBlock->wBlockId != wBlockId;
		LIST_NEXT(lolo.pBlock, lolo.pPrevBlock)
	);
	//-- put at head of list --
	if(lolo.pBlock && lolo.pPrevBlock) {
		lolo.pPrevBlock->pNext = lolo.pBlock->pNext;
		LIST_PUSH(lolo.pBlock, D_00E28C28);//head of "loaded blocks"?
	}
	//-- --

	return lolo.pBlock;
}

//block already in "scheduled to load(2)"?
int C_00751962(short wBlockId/*bp08*/) {
	struct t_wm_local_BlockLoadInfo *pElt;

	for(
		pElt = D_00E28CB0;//head of "scheduled to load(2)"
		pElt && pElt->wBlockId != wBlockId;
		pElt = pElt->pNext
	);

	return pElt != 0;
}

//refresh/count loaded chunks?
int C_0075199C() {
	struct {
		int dwCount;//local_5
		struct t_wm_TerrainChunkInfo *pPrevChunk;//local_4
		struct t_wm_local_ChunkLoadInfo *pPrevElt;//local_3
		struct t_wm_local_ChunkLoadInfo *pElt;//local_2
		struct t_wm_TerrainChunkInfo *pChunk;//local_1
	}lolo;

	lolo.dwCount = 0;
	for(lolo.pPrevChunk = 0, lolo.pChunk = D_00E28CC4; lolo.pChunk; ) {
		if(lolo.pChunk->wAge ++ >= 150) {//else 00751AA1
			LIST_REMOVE(lolo.pChunk, lolo.pPrevChunk, D_00E28CC4);
			LIST_PUSH(lolo.pChunk, D_00E28CCC);
			for(
				lolo.pPrevElt = 0, lolo.pElt = D_00E28B78;
				lolo.pElt && lolo.pElt->pChunk != lolo.pChunk;
				LIST_NEXT(lolo.pElt, lolo.pPrevElt)
			);
			if(lolo.pElt) {//else 00751A80
				LIST_REMOVE(lolo.pElt, lolo.pPrevElt, D_00E28B78);
				LIST_PUSH(lolo.pElt, D_00E28CD8);
			}
			/*lolo.local_6*/LIST_NEXT_0(lolo.pChunk, lolo.pPrevChunk, D_00E28CC4);
		} else {
			LIST_NEXT(lolo.pChunk, lolo.pPrevChunk);
			lolo.dwCount ++;
		}
	}//end for

	return lolo.dwCount;
}

//make chunk "flag map"?
void C_00751AC4(struct VECTOR *bp08, short wAngle/*bp0c*/, int bp10[][5]) {
	struct {//xb8
		struct VECTOR bp_ac;
		DECL_struct_MATRIX(bp_9c);//local_39
		struct SVECTOR bp_7c;//local_31
		struct VECTOR bp_74;//local_29
		DECL_short(j);//local_25
		DECL_short(i);
		struct VECTOR bp_5c;//local_23
		int dwFlags_unused;//local_19
		struct VECTOR sTrans;//local_18
		struct SVECTOR sRot;//local_14
		struct VECTOR bp_30;//local_12
		struct VECTOR bp_20;
		struct VECTOR bp_10;//local_4
	}lolo;

	//-- --
	lolo.bp_7c.vx = 0;
	lolo.bp_7c.vy = 0;
	lolo.bp_7c.vz = -0x1000;
	lolo.bp_7c.pad = 0;

	lolo.sRot.vx = 0; lolo.sRot.vy = 0; lolo.sRot.vz = 0; lolo.sRot.pad = 0;
	lolo.sTrans.vx = 0; lolo.sTrans.vy = 0; lolo.sTrans.vz = 0; lolo.sTrans.pad = 0;

	psx_TransMatrix(&lolo.bp_9c, &lolo.sTrans);
	psx_SetTransMatrix(&lolo.bp_9c);

	lolo.sRot.vy = -wAngle + 0x380;
	psx_RotMatrixXYZ(&lolo.sRot, &lolo.bp_9c);
	psx_SetRotMatrix(&lolo.bp_9c);
	psx_RotTrans(&lolo.bp_7c, &lolo.bp_10, &lolo.dwFlags_unused);

	lolo.sRot.vy = -wAngle - 0x380;
	psx_RotMatrixXYZ(&lolo.sRot, &lolo.bp_9c);
	psx_SetRotMatrix(&lolo.bp_9c);
	psx_RotTrans(&lolo.bp_7c, &lolo.bp_30, &lolo.dwFlags_unused);
	//-- --
	lolo.bp_74.vx = (bp08->vx & 0x1fff) - 0x1000;
	lolo.bp_74.vy = 0;
	lolo.bp_74.vz = (bp08->vz & 0x1fff) - 0x1000;

	lolo.bp_5c.vy = 0;
	for(lolo.j = -2; lolo.j <= 2; lolo.j ++) {
		for(lolo.i = -2; lolo.i <= 2; lolo.i ++) {
			if(inline_abs(lolo.i) <= 1 && inline_abs(lolo.j) <= 1) {//else 00751CAF
				bp10[lolo.j + 2][lolo.i + 2] = 1;
			} else {
				lolo.bp_5c.vx = (lolo.i << 13) - lolo.bp_74.vx;
				lolo.bp_5c.vz = (lolo.j << 13) - lolo.bp_74.vz;
				psx_OuterProduct12(&lolo.bp_10, &lolo.bp_5c, &lolo.bp_ac);
				psx_OuterProduct12(&lolo.bp_30, &lolo.bp_5c, &lolo.bp_20);
				bp10[lolo.j + 2][lolo.i + 2] = /*lolo.bp_b8*/(lolo.bp_ac.vy < 0 && lolo.bp_20.vy > 0);
			}
		}//end for
	}//end for
}

//make chunk distance?
int C_00751D44(
	struct t_wm_TerrainChunkInfo *bp08,
		short wChunkX/*bp0c*/, short wChunkY/*bp10*/,
		short *pwChunkX/*bp14*/, short *pwChunkY/*bp18*/
) {
	//-- --
	*pwChunkX = bp08->wChunkX - wChunkX;
	if(*pwChunkX > 0x12)
		*pwChunkX -= 0x24;
	else if(*pwChunkX < -0x12)
		*pwChunkX += 0x24;
	//-- --
	*pwChunkY = bp08->wChunkY - wChunkY;
	if(*pwChunkY > 0xe)
		*pwChunkY -= 0x1c;
	else if(*pwChunkY < -0xe)
		*pwChunkY += 0x1c;
	//-- --

	return inline_abs(*pwChunkX) <= 2 && inline_abs(*pwChunkY) <= 2;
}

//"alloc" element?
struct t_wm_TerrainChunkInfo *C_00751E43() {
	struct {
		struct t_wm_TerrainChunkInfo *pPrevChunk;//local_2
		struct t_wm_TerrainChunkInfo *pChunk;//local_1
	}lolo;

	lolo.pChunk = 0;
	if(D_00E28CCC) {
		LIST_POP(lolo.pChunk, D_00E28CCC);
	} else if(D_00E045F8) {//else 00751ED3
		for(
			lolo.pPrevChunk = 0, lolo.pChunk = D_00E045F8;
			lolo.pChunk->pNext;
			LIST_NEXT(lolo.pChunk, lolo.pPrevChunk)
		);
		if(lolo.pPrevChunk)
			lolo.pPrevChunk->pNext = 0;
		else
			D_00E045F8 = 0;
		C_00761644(lolo.pChunk->wChunkX, lolo.pChunk->wChunkY);//wm:chunk unloaded?
	}
	if(lolo.pChunk) {
		LIST_PUSH(lolo.pChunk, D_00E28CC4);
		lolo.pChunk->wAge = 0;
	}

	return lolo.pChunk;
}

struct t_wm_30_temp {//size 0x30
	/*00*/struct VECTOR f_00;
	/*10*/struct SVECTOR f_10;
	/*18*/struct t_wm_TerrainChunkInfo *f_18;
	/*1c*/struct t_wm_TerrainTriangle *f_1c;
	/*20*/short wChunkX,wChunkY;
	/*24*/short f_24;
	/*26*/short f_26;//some direction/angle?
	/*28*/short f_28;//terrain height related?
	/*2a*/short wTerrainInfo;
	/*2c*/char __2c[4];
};

struct t_wm_f0_temp {//size 0xf0
	/*00*/struct t_wm_30_temp f_00[5];
};

struct t_wm_30_temp *C_00752D02(struct t_wm_TerrainChunkInfo *, struct t_wm_f0_temp *, short, short);
void C_007530B3(struct t_wm_f0_temp *, struct SVECTOR *, struct SVECTOR *, int);//make 5 chunks info?

//render terrain:
void C_00751EFC(struct VECTOR *pVectPrevPos/*bp08*/, struct VECTOR *pVectPos_1/*bp0c*/, struct VECTOR *pVectPos_2/*bp10*/, short wAngle/*bp14*/) {
	struct {//x1034
		//local_1036 and above is for compiler
		struct t_wm_f0_temp bp_102c[2][8];//local_1035
		DECL_struct_MATRIX(bp_12c);//local_75
		struct t_wm_f0_temp **bp_10c;//local_67
		int dwIncrY;//local_66
		DECL_short(wTerrainChunkY);//local_65
		struct SVECTOR bp_100;
		DECL_short(wDiffChunkY);
		struct t_wm_f0_temp **bp_f4;//local_61
		DECL_short(wDiffChunkX);
		struct t_wm_f0_temp *bp_ec;//local_59
		struct t_wm_f0_temp *bp_e8[10];//local_58
		struct SVECTOR bp_c0;//local_48
		struct t_wm_TerrainChunkInfo *bp_b8;
		int bp_b4[5][5];
		DECL_short(wTerrainChunkX);//local_20
		struct VECTOR *bp_4c;//local_19
		struct SVECTOR bp_48;//local_18
		int dwDiff;//local_16
		struct t_wm_f0_temp **bp_3c;
		struct t_wm_30_temp *bp_38;
		struct VECTOR local_13;
		struct SVECTOR sVectRot;//local_9
		struct t_wm_TerrainChunkInfo *bp_1c;//local_7
		struct t_wm_TerrainChunkInfo *bp_18;//local_6
		DECL_short(wPlayerChunkX);//local_5
		DECL_short(wPlayerChunkY);//local_4
		struct SVECTOR bp_0c;//local_3
		struct t_wm_TerrainChunkInfo *bp_04;
	}lolo;

	lolo.bp_4c = 0;
	lolo.bp_1c = 0;
	lolo.bp_18 = 0;
	D_00E28CDC = 0;
	//-- --
	lolo.bp_c0.vy = 0;
	//x
	lolo.dwDiff = pVectPos_2->vx - pVectPrevPos->vx;
	if(lolo.dwDiff < -(0x12 << 13))
		lolo.dwDiff += (0x24 << 13);
	else if(lolo.dwDiff >= (0x12 << 13))
		lolo.dwDiff -= (0x24 << 13);
	lolo.bp_c0.vx = lolo.dwDiff;
	//z
	lolo.dwDiff = pVectPos_2->vz - pVectPrevPos->vz;
	if(lolo.dwDiff < -(0xe << 13))
		lolo.dwDiff += (0x1c << 13);
	else if(lolo.dwDiff >= (0xe << 13))
		lolo.dwDiff -= (0x1c << 13);
	lolo.bp_c0.vz = lolo.dwDiff;
	//-- --
	psx_TransMatrix(&lolo.bp_12c, pVectPrevPos);
	lolo.sVectRot.vx =
	lolo.sVectRot.vz = 0;
	C_00750134(pVectPos_1, &lolo.bp_100, &lolo.wPlayerChunkX, &lolo.wPlayerChunkY);//wm:world to chunk coordinates?
	C_0075027C(pVectPos_1, 0);//wm:set some pos?
	C_0075042B(&lolo.local_13);//wm:get some pos?
	C_00750134(&lolo.local_13, &lolo.bp_0c, &lolo.wTerrainChunkX, &lolo.wTerrainChunkY);//wm:world to chunk coordinates?
	//-- --
	if(lolo.wTerrainChunkX - lolo.wPlayerChunkX > 0x12)
		lolo.wTerrainChunkX -= 0x24;
	else if(lolo.wTerrainChunkX - lolo.wPlayerChunkX < -0x12)
		lolo.wTerrainChunkX += 0x24;
	//-- --
	if(lolo.wTerrainChunkY - lolo.wPlayerChunkY > 0xe)
		lolo.wTerrainChunkY -= 0x1c;
	else if(lolo.wTerrainChunkY - lolo.wPlayerChunkY < -0xe)
		lolo.wTerrainChunkY += 0x1c;
	//-- --
	if(lolo.wTerrainChunkX > lolo.wPlayerChunkX)
		lolo.bp_0c.vx += (1 << 13);
	else if(lolo.wTerrainChunkX < lolo.wPlayerChunkX)
		lolo.bp_0c.vx -= (1 << 13);
	//-- --
	if(lolo.wTerrainChunkY > lolo.wPlayerChunkY)
		lolo.bp_0c.vz += (1 << 13);
	else if(lolo.wTerrainChunkY < lolo.wPlayerChunkY)
		lolo.bp_0c.vz -= (1 << 13);
	//-- --
	if(C_0074D4DC()) {//wm:returns true[debug stuff?]
		sprintf(D_00E28C48, "PS%d%d%d%d.rsd  POS: %d %d",
			lolo.wPlayerChunkX / 10, lolo.wPlayerChunkX % 10,
			lolo.wPlayerChunkY / 10, lolo.wPlayerChunkY % 10,
			pVectPos_1->vx & 0x1fff, pVectPos_1->vz & 0x1fff
		);
	}
	//-- --
	lolo.sVectRot.vy = 0;
	psx_SetTransMatrix(&lolo.bp_12c);
	lolo.dwDiff = (C_00761735() == WM_MODELID_05)?350:200;//wm:get model type(2)?
	lolo.dwIncrY = /*lolo.local_1036*/(0x500 << ((D_00E28CC0 != 1 && D_00E28CD4 == 0)?0:1)) >> 3;
	for(lolo.bp_ec = &(lolo.bp_102c[0][0]); lolo.bp_ec < &(lolo.bp_102c[0][8]); lolo.bp_ec ++) {
		C_007530B3(lolo.bp_ec, &lolo.bp_c0, &lolo.sVectRot, lolo.dwDiff);//make 5 chunks info?
		lolo.sVectRot.vy += lolo.dwIncrY;
	}//end for
	lolo.sVectRot.vy = 0;
	for(lolo.bp_ec = &(lolo.bp_102c[1][0]); lolo.bp_ec < &(lolo.bp_102c[1][8]); lolo.bp_ec ++) {
		C_007530B3(lolo.bp_ec, &lolo.bp_c0, &lolo.sVectRot, lolo.dwDiff);//make 5 chunks info?
		lolo.sVectRot.vy -= lolo.dwIncrY;
	}//end for
	lolo.bp_e8[0] = &(lolo.bp_102c[0][0]);
	lolo.bp_10c = &(lolo.bp_e8[1]);
	lolo.bp_f4 = &(lolo.bp_e8[0]);
	while(lolo.bp_f4 < lolo.bp_10c) {
		lolo.wTerrainChunkX = (*lolo.bp_f4)->f_00[0].wChunkX;
		lolo.wTerrainChunkY = (*lolo.bp_f4)->f_00[0].wChunkY;
		//-- --
		if(lolo.bp_f4 == &(lolo.bp_e8[0]))
			C_00762D52();
		lolo.bp_f4 ++;
		//-- --
		for(
			lolo.bp_b8 = 0, lolo.bp_04 = D_00E045F8;
			lolo.bp_04 && (lolo.bp_04->wChunkX != lolo.wTerrainChunkX || lolo.bp_04->wChunkY != lolo.wTerrainChunkY);
			LIST_NEXT(lolo.bp_04, lolo.bp_b8)
		);
		//-- chunk not loaded yet? --
		if(lolo.bp_04 == 0) {
			C_00762933();
			goto C_00752AB6;
		}
		//-- --
		LIST_REMOVE(lolo.bp_04, lolo.bp_b8, D_00E045F8);
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
		//-- --
		C_00751D44(lolo.bp_04, lolo.wPlayerChunkX, lolo.wPlayerChunkY, &lolo.wDiffChunkX, &lolo.wDiffChunkY);//make chunk distance?
		lolo.bp_48.vx = (lolo.wDiffChunkX << 13) - lolo.bp_0c.vx;
		lolo.bp_48.vy = -lolo.bp_0c.vy;
		lolo.bp_48.vz = (lolo.wDiffChunkY << 13) - lolo.bp_0c.vz;
		C_0074D33A(&lolo.bp_48);//wm:set trans matrix from svector?
		C_0075F0AD(lolo.bp_04->pVertices, C_0074D4ED());//wm:send terrain vertices for rendering?
		//-- --
		psx_ReadRotMatrix(&lolo.bp_12c);
		//-- --
		if(lolo.bp_f4 == &(lolo.bp_e8[1]))
			C_00758DA5(lolo.wPlayerChunkX, lolo.wPlayerChunkY);//wm:refresh bridge at?
		//-- --
		lolo.bp_38 = C_00752D02(lolo.bp_04, lolo.bp_102c[D_00E28CB8], lolo.wTerrainChunkX, lolo.wTerrainChunkY);
		if(lolo.bp_38) {//else 00752546
			for(
				lolo.bp_3c = lolo.bp_f4;
				lolo.bp_3c < lolo.bp_10c && ((*lolo.bp_3c)->f_00[0].wChunkX != lolo.bp_38->wChunkX || (*lolo.bp_3c)->f_00[0].wChunkY != lolo.bp_38->wChunkY);
				lolo.bp_3c ++
			);
			if(lolo.bp_3c >= lolo.bp_10c) {//else 00752546
				if(lolo.bp_10c < &(lolo.bp_e8[10])) {
					*(struct t_wm_30_temp **)lolo.bp_10c = lolo.bp_38;
					lolo.bp_10c ++;
				} else {
					C_0074C9A0(0x14);//<empty>:some error management?
				}
			}
		}
		//-- --
		lolo.bp_38 = C_00752D02(lolo.bp_04, lolo.bp_102c[!D_00E28CB8], lolo.wTerrainChunkX, lolo.wTerrainChunkY);
		if(lolo.bp_38) {//else 0075260E
			for(
				lolo.bp_3c = lolo.bp_f4;
				lolo.bp_3c < lolo.bp_10c && ((*lolo.bp_3c)->f_00[0].wChunkX != lolo.bp_38->wChunkX || (*lolo.bp_3c)->f_00[0].wChunkY != lolo.bp_38->wChunkY);
				lolo.bp_3c ++
			);
			if(lolo.bp_3c >= lolo.bp_10c) {//else 0075260E
				if(lolo.bp_10c < &(lolo.bp_e8[10])) {
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
				if(lolo.bp_38->wChunkX == lolo.wTerrainChunkX && lolo.bp_38->wChunkY == lolo.wTerrainChunkY && lolo.bp_38->f_24 == 1)
					lolo.bp_38->f_24 = 4;
			}//end for
		}//end for
		psx_SetRotMatrix(&lolo.bp_12c);
		C_00762D74(lolo.bp_04);
		C_0074D33A(&lolo.bp_48);//wm:set trans matrix from svector?
		C_0075F263();//wm:2d clip terrain vertices?
		C_0075F68C(&(lolo.bp_04->f_04[0]), &(lolo.bp_04->f_04[lolo.bp_04->wTriangleCount]), lolo.bp_04->pNormals, C_0074C9AF(lolo.bp_04->wTriangleCount));//render terrain:1 "square"?
	}//end while
	//-- --
	for(
		lolo.bp_ec = &(lolo.bp_102c[D_00E28CB8][0]);
		lolo.bp_ec < &(lolo.bp_102c[D_00E28CB8][8]) && (lolo.bp_ec->f_00[0].f_24 != 2 || lolo.bp_ec->f_00[1].f_24 != 2 || lolo.bp_ec->f_00[2].f_24 != 2 || lolo.bp_ec->f_00[3].f_24 != 2 || lolo.bp_ec->f_00[4].f_24 != 2);
		lolo.bp_ec ++
	);
	if(lolo.bp_ec < &(lolo.bp_102c[D_00E28CB8][8])) {//else 00752898
		D_00E28C30 = lolo.bp_ec->f_00[0].f_00;
		D_00E28C30.vy = lolo.bp_ec->f_00[0].f_28;
		C_0076211B(lolo.bp_ec->f_00[0].wTerrainInfo);//wm:set terrain info?
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
		if(lolo.bp_ec < &(lolo.bp_102c[!D_00E28CB8][8])) {//else 00752A60
			D_00E28C30 = lolo.bp_ec->f_00[0].f_00;
			D_00E28C30.vy = lolo.bp_ec->f_00[0].f_28;
			C_0076211B(lolo.bp_ec->f_00[0].wTerrainInfo);//wm:set terrain info?
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
			//-- --
			D_00E28CB8 = !D_00E28CB8;
			D_00E28C44 = 0;
		}
	}
	//-- --
	D_00E28CDC = 1;
	//-- direction patch for submarine? --
	if(lolo.bp_4c && D_00E28CC0 != 0)
		D_00E28CC0 = 0;
	else if(lolo.bp_4c == 0 && D_00E28CC0 == 2)
		D_00E28CC0 = 1;
	D_00E28CD4 -= D_00E28CD4 > 0;
	//-- --
C_00752AB6:
	//-- --
	if(lolo.bp_4c == 0) {
		C_007628B5();
		if(C_00762136() == 0xe)//wm:get current terrain?
			D_00E28CD4 = 5;
	}
	//-- --
	D_00E28C44 ++;
	C_00750134(pVectPos_1, &lolo.bp_100, &lolo.wTerrainChunkX, &lolo.wTerrainChunkY);//wm:world to chunk coordinates?
	C_00751AC4(pVectPos_1, wAngle, lolo.bp_b4);//make chunk "flag map"?
	lolo.bp_b8 = 0, lolo.bp_04 = D_00E045F8;
	while(lolo.bp_04) {
		if(
			C_00751D44(lolo.bp_04, lolo.wTerrainChunkX, lolo.wTerrainChunkY, &lolo.wDiffChunkX, &lolo.wDiffChunkY) &&//make chunk distance?
			lolo.bp_b4[lolo.wDiffChunkY + 2][lolo.wDiffChunkX + 2]
		) {//else 00752CC2
			lolo.bp_48.vx = (lolo.wDiffChunkX << 13) - lolo.bp_0c.vx;
			lolo.bp_48.vy = -lolo.bp_0c.vy;
			lolo.bp_48.vz = (lolo.wDiffChunkY << 13) - lolo.bp_0c.vz;
			C_0074D33A(&lolo.bp_48);//wm:set trans matrix from svector?
			C_0075F0AD(lolo.bp_04->pVertices, C_0074D4ED());//wm:send terrain vertices for rendering?
			C_00762D74(lolo.bp_04);
			C_0074D33A(&lolo.bp_48);//wm:set trans matrix from svector?
			C_0075F263();//wm:2d clip terrain vertices?
			C_0075F68C(&(lolo.bp_04->f_04[0]), &(lolo.bp_04->f_04[lolo.bp_04->wTriangleCount]), lolo.bp_04->pNormals, C_0074C9AF(lolo.bp_04->wTriangleCount));//render terrain:1 "square"?
			LIST_REMOVE(lolo.bp_04, lolo.bp_b8, D_00E045F8);
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
			/*lolo.bp_1034*/LIST_NEXT_0(lolo.bp_04, lolo.bp_b8, D_00E045F8);
			continue;
		}
		LIST_NEXT(lolo.bp_04, lolo.bp_b8);
	}//end while
	if(lolo.bp_1c && lolo.bp_18) {
		lolo.bp_18->pNext = D_00E045F8;
		D_00E045F8 = lolo.bp_1c;
	}
}

struct t_wm_30_temp *C_00752D02(struct t_wm_TerrainChunkInfo *bp08, struct t_wm_f0_temp *bp0c, short wChunkX/*bp10*/, short wChunkY/*bp14*/) {
	struct {
		int local_11;
		struct t_wm_30_temp *local_10;
		int dwModelType;//local_9
		struct t_wm_local_08 *local_8;
		int local_7;
		struct VECTOR local_6;
		struct t_wm_30_temp *local_2;
		int local_1;
	}lolo;

	lolo.local_1 = 0;
	lolo.local_11 = 4;
	lolo.local_10 = 0;
	C_00762798(&lolo.local_6);//wm:get model pos(2)?
	lolo.local_8 = C_007616E3();
	lolo.dwModelType = C_0076170B();//wm:get model type(1)?
	if(
		C_00766B53() == 2 &&//wm:get "leave vehicle" state?
		C_00761844()//wm:is current model a chocobo(1)?
	) {//else 00752F21
		do {
			for(lolo.local_2 = &(bp0c[lolo.local_1].f_00[0]); lolo.local_2 < &(bp0c[lolo.local_1].f_00[5]); lolo.local_2 ++) {
				if(lolo.local_2->f_24 == 1) {//else 00752E61
					if(lolo.local_2->wChunkX == wChunkX && lolo.local_2->wChunkY == wChunkY) {//else 00752E55
						lolo.local_2->f_18 = bp08;
						lolo.local_2->f_28 = lolo.local_6.vy;
						if(
							C_0074CC07(bp08, &(lolo.local_2->f_10), lolo.local_8, &(lolo.local_2->f_28), &(lolo.local_2->f_1c), &(lolo.local_2->wTerrainInfo), lolo.dwModelType) &&
							inline_abs(lolo.local_2->f_28 - lolo.local_6.vy) < 200
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
					if(lolo.local_2->wChunkX == wChunkX && lolo.local_2->wChunkY == wChunkY) {//else 00752FE5
						lolo.local_2->f_18 = bp08;
						lolo.local_2->f_28 = lolo.local_6.vy;
						if(
							C_0074CC07(bp08, &(lolo.local_2->f_10), lolo.local_8, &(lolo.local_2->f_28), &(lolo.local_2->f_1c), &(lolo.local_2->wTerrainInfo), lolo.dwModelType)
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

//make 5 chunks info?
/*
	    +---+
	    |   |
	+---+---+---+
	|   | x |   |
	+---+---+---+
	    |   |
	    +---+
*/
void C_007530B3(struct t_wm_f0_temp *bp08, struct SVECTOR *bp0c, struct SVECTOR *pSVectRot/*bp10*/, int dwDiff/*bp14*/) {
	struct {
		DECL_struct_MATRIX(local_14);
		struct VECTOR local_6;
		int dwFlags_unused;//local_2
		struct t_wm_30_temp *local_1;
	}lolo;

	psx_RotMatrixXYZ(pSVectRot, &lolo.local_14);
	psx_SetRotMatrix(&lolo.local_14);
	lolo.local_1 = &(bp08->f_00[0]);
	psx_RotTrans(bp0c, &lolo.local_6, &lolo.dwFlags_unused);

	lolo.local_1->f_00 = lolo.local_6;
	//
	C_00750134(&(lolo.local_1->f_00), &(lolo.local_1->f_10), &(lolo.local_1->wChunkX), &(lolo.local_1->wChunkY));//wm:world to chunk coordinates?
	lolo.local_1->f_24 = 1;
	lolo.local_1->f_28 = 0;
	lolo.local_1->f_1c = 0;
	lolo.local_1->f_26 = pSVectRot->vy;

	lolo.local_1 ++;

	lolo.local_1->f_00 = lolo.local_6;
	lolo.local_1->f_00.vx -= dwDiff;
	C_00750134(&(lolo.local_1->f_00), &(lolo.local_1->f_10), &(lolo.local_1->wChunkX), &(lolo.local_1->wChunkY));//wm:world to chunk coordinates?
	lolo.local_1->f_24 = 1;
	lolo.local_1->f_28 = 0;
	lolo.local_1->f_1c = 0;
	lolo.local_1->f_26 = pSVectRot->vy;

	lolo.local_1 ++;

	lolo.local_1->f_00 = lolo.local_6;
	lolo.local_1->f_00.vx += dwDiff;
	C_00750134(&(lolo.local_1->f_00), &(lolo.local_1->f_10), &(lolo.local_1->wChunkX), &(lolo.local_1->wChunkY));//wm:world to chunk coordinates?
	lolo.local_1->f_24 = 1;
	lolo.local_1->f_28 = 0;
	lolo.local_1->f_1c = 0;
	lolo.local_1->f_26 = pSVectRot->vy;

	lolo.local_1 ++;

	lolo.local_1->f_00 = lolo.local_6;
	lolo.local_1->f_00.vz -= dwDiff;
	C_00750134(&(lolo.local_1->f_00), &(lolo.local_1->f_10), &(lolo.local_1->wChunkX), &(lolo.local_1->wChunkY));//wm:world to chunk coordinates?
	lolo.local_1->f_24 = 1;
	lolo.local_1->f_28 = 0;
	lolo.local_1->f_1c = 0;
	lolo.local_1->f_26 = pSVectRot->vy;

	lolo.local_1 ++;

	lolo.local_1->f_00 = lolo.local_6;
	lolo.local_1->f_00.vz += dwDiff;
	C_00750134(&(lolo.local_1->f_00), &(lolo.local_1->f_10), &(lolo.local_1->wChunkX), &(lolo.local_1->wChunkY));//wm:world to chunk coordinates?
	lolo.local_1->f_24 = 1;
	lolo.local_1->f_28 = 0;
	lolo.local_1->f_1c = 0;
	lolo.local_1->f_26 = pSVectRot->vy;
}

//<empty>
void C_00753348() {
}

//wm:set chocobo farm related flag?
void C_0075334D() {
	D_00E04604 = 1;
}

//wm:allow control/move?
int C_0075335C() {
	return D_00E28CDC;
}

//wm:(for midgar zolom)
int C_00753366(short wChunkX/*bp08*/, short wChunkY/*bp0c*/) {
	struct t_wm_TerrainChunkInfo *local_1;

	for(
		local_1 = D_00E045F8;
		local_1 && (local_1->wChunkX != wChunkX || local_1->wChunkY != wChunkY);
		local_1 = local_1->pNext
	);

	return local_1 != 0;
}

char D_00969B30[] = {9,9,3,2};//Maps Width
char D_00969B34[] = {7,7,4,2};//Maps Height
/*
	[0]surface
	----------
	+--+--+--+--+--+--+--+--+--+
	|00|01|02|03|04|05|06|07|08|
	+--+--+--+--+--+--+--+--+--+
	|09|0a|0b|0c|0d|0e|0f|10|11|
	+--+--+--+--+--+--+--+--+--+
	|12|13|14|15|16|17|18|19|1a|
	+--+--+--+--+--+--+--+--+--+
	|1b|1c|1d|1e|1f|20|21|22|23|
	+--+--+--+--+--+--+--+--+--+
	|24|25|26|27|28|29|2a|2b|2c|
	+--+--+--+--+--+--+--+--+--+
	|2d|2e|2f|30|31|32|33|34|35|
	+--+--+--+--+--+--+--+--+--+
	|36|37|38|39|3a|3b|3c|3d|3e|
	+--+--+--+--+--+--+--+--+--+


	[2]undersea
	-----------
	+--+--+--+
	|  |  |  |
	+--+--+--+
	|  |  |  |
	+--+--+--+
	|  |  |  |
	+--+--+--+
	|  |  |  |
	+--+--+--+


	[3]snowworld
	------------
	+--+--+
	|  |  |
	+--+--+
	|  |  |
	+--+--+
*/

//wm:map init/reset?
void C_007533AF() {
	struct {
		int i;
		int dwBlockId;//local_9
		int dwMapId;//local_8
		int dwBlockY;//local_7
		int j;//local_6
		int dwBlockX;//local_5
		struct VECTOR local_4;
	}lolo;

	C_00762798(&lolo.local_4);//wm:get model pos(2)?
	lolo.dwBlockX = (lolo.local_4.vx - 0x4000) >> 15;
	lolo.dwBlockY = (lolo.local_4.vz - 0x4000) >> 15;
	lolo.dwMapId = C_0074D330();//wm:get current map id?
	//-- --
	if(lolo.dwMapId == 2) {
		lolo.dwBlockX -= 3;
		lolo.dwBlockY -= 2;
	}
	//-- --
	if(lolo.dwBlockX < 0)
		lolo.dwBlockX += D_00969B30[lolo.dwMapId];
	if(lolo.dwBlockY < 0)
		lolo.dwBlockY += D_00969B34[lolo.dwMapId];
	lolo.dwBlockId = D_00969B30[lolo.dwMapId] * lolo.dwBlockY + lolo.dwBlockX;
	//-- --
	if(lolo.dwMapId == 0) {//else 0075350C
		if(D_00E28CB4 > 0 && lolo.dwBlockX >= 4 && lolo.dwBlockX <= 5 && lolo.dwBlockY >= 4 && lolo.dwBlockY <= 5)
			lolo.dwBlockId = lolo.dwBlockY * 2 + lolo.dwBlockX + 0x33;
		if(D_00E28CB4 > 1 && lolo.dwBlockX >= 4 && lolo.dwBlockX <= 6 && lolo.dwBlockY >= 3 && lolo.dwBlockY <= 4)
			lolo.dwBlockId = (lolo.dwBlockY - 3) * 3 + lolo.dwBlockX + 0x3f;
		if(D_00E28CB4 > 2 && lolo.dwBlockX >= 5 && lolo.dwBlockX <= 6 && lolo.dwBlockY >= 5)
			lolo.dwBlockId = lolo.dwBlockY * 2 + lolo.dwBlockX + 0x3a;
		if(D_00E28CB4 > 3 && lolo.dwBlockX >= 1 && lolo.dwBlockX <= 3 && lolo.dwBlockY >= 4 && lolo.dwBlockY <= 5)
			lolo.dwBlockId = (lolo.dwBlockY - 4) * 3 + lolo.dwBlockX + 0x4c;
	}
	//-- --
	C_007593CD(C_0074CA00(1/*"WM?.BOT"*/, lolo.dwMapId), (lolo.dwBlockId * 0xb800) * 4, 0xb800 * 4/*0x2e000*/, D_00E045FC, 0);//wmfile:read file
	D_00E28970 = &(D_00E04928[4]);
	D_00E28C28 = &(D_00E04928[0]);//head of "loaded blocks"?
	D_00E04928[3].pNext = 0;//00E04940
	for(lolo.j = 0; lolo.j < 2; lolo.j ++) {
		for(lolo.i = 0; lolo.i < 2; lolo.i ++) {
			D_00E04928[lolo.j * 2 + lolo.i].wBlockId =
				/*bp_2c*/(lolo.dwMapId == 2)?
					(((lolo.dwBlockY + lolo.j) % 4) + 2) * 9 + ((lolo.dwBlockX + lolo.i) % 3) + 3:
				/*bp_30*/(lolo.dwMapId == 3)?
					((lolo.dwBlockY + lolo.j) & 1) * 9 + ((lolo.dwBlockX + lolo.i) & 1):
					((lolo.dwBlockY + lolo.j) % 7) * 9 + ((lolo.dwBlockX + lolo.i) % 9)
			;
		}//end for
	}//end for
}

unsigned char *__0075363D(short bp08) {
	struct {
		struct t_wm_local_BlockLoadInfo *pPrevBlock;//local_4
		struct t_wm_local_BlockLoadInfo *local_3;
		struct t_wm_local_BlockLoadInfo *local_2;
		struct t_wm_local_BlockLoadInfo *pBlock;//local_1
	}lolo;

	//-- --
	if(D_00E28CBC)
		C_0074C9A0(0xe);//<empty>:some error management?
	//-- "scheduled to load" --
	for(
		lolo.local_3 = 0, lolo.local_2 = D_00E28C24;
		lolo.local_2;
		LIST_NEXT(lolo.local_2, lolo.local_3)
	);
	if(lolo.local_3) {
		lolo.local_3->pNext = D_00E28B7C;
		D_00E28B7C = D_00E28C24;
		D_00E28C24 = 0;
	}
	//-- "scheduled to load(2)" --
	for(
		lolo.pPrevBlock = 0, lolo.pBlock = D_00E28CB0;
		lolo.pBlock;
		LIST_NEXT(lolo.pBlock, lolo.pPrevBlock)
	);
	if(lolo.pPrevBlock) {
		lolo.pPrevBlock->pNext = D_00E28970;
		D_00E28970 = D_00E28CB0;
		D_00E28CB0 = 0;
	}
	//-- "loaded blocks" --
	for(lolo.pPrevBlock = 0, lolo.pBlock = D_00E28C28; lolo.pBlock; ) {
		if(lolo.pBlock >= &(D_00E04928[bp08])) {//else 00753765
			LIST_REMOVE(lolo.pBlock, lolo.pPrevBlock, D_00E28C28);//head of "loaded blocks"?
			//-- back in "pool" --
			LIST_PUSH(lolo.pBlock, D_00E28970);
			//-- --
			/*lolo.local_5*/LIST_NEXT_0(lolo.pBlock, lolo.pPrevBlock, D_00E28C28);//head of "loaded blocks"?
		} else {
			LIST_NEXT(lolo.pBlock, lolo.pPrevBlock);
		}
	}//end for

	return D_00E045FC[bp08];
}

//wm:some patch for submarine?
void C_0075378A(int bp08) {
	D_00E28CC0 = 2;
	D_00E28C2C = bp08;
}

//wm:set world map state?
void C_007537A1(int bp08) {
	D_00E28CB4 = bp08;
}

void C_007537AE(struct VECTOR *bp08) {
	struct {
		struct SVECTOR *pNormal_1;//local_3
		struct SVECTOR *pNormal_0;//local_2
		struct SVECTOR *pNormal_2;//local_1
	}lolo;

	lolo.pNormal_0 = &(D_00E28CD0->pNormals[D_00E04608->vect0]);
	lolo.pNormal_1 = &(D_00E28CD0->pNormals[D_00E04608->vect1]);
	lolo.pNormal_2 = &(D_00E28CD0->pNormals[D_00E04608->vect2]);
	bp08->vx = lolo.pNormal_0->vx + lolo.pNormal_1->vx + lolo.pNormal_2->vx;
	bp08->vy = lolo.pNormal_0->vy + lolo.pNormal_1->vy + lolo.pNormal_2->vy;
	bp08->vz = lolo.pNormal_0->vz + lolo.pNormal_1->vz + lolo.pNormal_2->vz;
}
