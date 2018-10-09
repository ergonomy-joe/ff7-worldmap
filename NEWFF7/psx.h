/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
#ifndef __PSX_H__
#define __PSX_H__

//inspired by LIBGPU.H

/*
 * Primitive Handling Macros
 */
#define setlen( p, _len) 	(((struct P_TAG *)(p))->len  = (unsigned char)(_len))
#define setaddr(p, _addr)	(((struct P_TAG *)(p))->addr = (unsigned)(_addr))
#define setcode(p, _code)	(((struct P_TAG *)(p))->code = (unsigned char)(_code))

#define getlen(p)    		(unsigned char)(((struct P_TAG *)(p))->len)
#define getcode(p)   		(unsigned char)(((struct P_TAG *)(p))->code)
#define getaddr(p)   		(unsigned)(((struct P_TAG *)(p))->addr)

#define setSemiTrans(p, abe) \
	((abe)?setcode(p, getcode(p)|0x02):setcode(p, getcode(p)&~0x02))

#define setShadeTex(p, tge) \
	((tge)?setcode(p, getcode(p)|0x01):setcode(p, getcode(p)&~0x01))

#define setPolyGT3(p)	setlen(p, 9),  setcode(p, 0x34)
#define setPolyF4(p)	setlen(p, 5),  setcode(p, 0x28)
#define setPolyFT4(p)	setlen(p, 9),  setcode(p, 0x2c)
#define setPolyG4(p)	setlen(p, 8),  setcode(p, 0x38)

#define setLineG2(p)	setlen(p, 4),  setcode(p, 0x50)
#define setLineG3(p)	setlen(p, 7),  setcode(p, 0x58),(p)->pad   = 0x55555555

 /*
 * Set Primitive Colors
 */
#define setRGB0(p,_r0,_g0,_b0)						\
	(p)->r0 = _r0,(p)->g0 = _g0,(p)->b0 = _b0

#define setRGB1(p,_r1,_g1,_b1)						\
	(p)->r1 = _r1,(p)->g1 = _g1,(p)->b1 = _b1

#define setRGB2(p,_r2,_g2,_b2)						\
	(p)->r2 = _r2,(p)->g2 = _g2,(p)->b2 = _b2
	
#define setRGB3(p,_r3,_g3,_b3)						\
	(p)->r3 = _r3,(p)->g3 = _g3,(p)->b3 = _b3

/*
 * Set Primitive Screen Points
 */
#define setXY4(p,_x0,_y0,_x1,_y1,_x2,_y2,_x3,_y3) 			\
	(p)->x0 = (_x0), (p)->y0 = (_y0),				\
	(p)->x1 = (_x1), (p)->y1 = (_y1),				\
	(p)->x2 = (_x2), (p)->y2 = (_y2),				\
	(p)->x3 = (_x3), (p)->y3 = (_y3)

 /*
 * Set Primitive Texture Points
 */
#define setUVWH(p,_u0,_v0,_w,_h)					\
	(p)->u0 = (_u0),      (p)->v0 = (_v0),				\
	(p)->u1 = (_u0)+(_w), (p)->v1 = (_v0),				\
	(p)->u2 = (_u0),      (p)->v2 = (_v0)+(_h),			\
	(p)->u3 = (_u0)+(_w), (p)->v3 = (_v0)+(_h)

/*
 * Polygon Primitive Definitions
 */
struct P_TAG {
	unsigned addr: 24;
	unsigned len: 8;
	unsigned char r0,g0,b0;//f_04,f_05,f_06
	unsigned char code;//f_07
};

struct POLY_F3 {
	char __00[4];
	unsigned char r0,g0,b0;//f_04,f_05,f_06
	unsigned char code;//f_07
	//
	short x0,y0;//f_08,f_0a
	short x1,y1;//f_0c,f_0e
	short x2,y2;//f_10,f_12
};

struct POLY_F4 {
	char __00[4];
	unsigned char r0,g0,b0;//f_04,f_05,f_06
	unsigned char code;//f_07
	//
	short x0,y0;//f_08,f_0a
	short x1,y1;//f_0c,f_0e
	short x2,y2;//f_10,f_12
	short x3,y3;//f_14,f_16
};

struct POLY_FT3 {
	char __00[4];
	unsigned char r0,g0,b0;//f_04,f_05,f_06
	unsigned char code;//f_07
	//
	short x0,y0;//f_08,f_0a
	unsigned char u0,v0; unsigned short clut;//f_0c,f_0d,f_0e
	short x1,y1;//f_10,f_12
	unsigned char u1,v1;//f_14,f_15
	unsigned short tpage;//f_16
	short x2,y2;//f_18,f_1a
	unsigned char u2,v2;//f_1c,f_1d
	char __1e[2];
};

//struct t_swirl_28
struct POLY_FT4 {//size 0x28
	char __00[4];
	unsigned char r0,g0,b0;//f_04,f_05,f_06
	unsigned char code;//f_07
	//
	short x0,y0;//f_08,f_0a
	unsigned char u0,v0; unsigned short clut;//f_0c,f_0d,f_0e
	short x1,y1;//f_10,f_12
	unsigned char u1,v1; unsigned short tpage;//f_14,f_15,f_16
	short x2,y2;//f_18,f_1a
	unsigned char u2,v2; /*unsigned */short pad1;//f_1c,f_1d,__1e
	short x3,y3;//f_20,f_22
	unsigned char u3,v3; /*unsigned */short pad2;//f_24,f_25,__26
};

struct POLY_G3 {
	char __00[4];
	unsigned char r0,g0,b0;//f_04,f_05,f_06
	unsigned char code;//f_07
	//
	short x0,y0;//f_08,f_0a
	unsigned char r1,g1,b1,__0f;//f_0c,f_0d,f_0e
	short x1,y1;//f_10,f_12
	unsigned char r2,g2,b2,__17;//f_14,f_15,f_16
	short x2,y2;//f_18,f_1a
};

struct POLY_G4 {
	char __00[4];
	unsigned char r0,g0,b0;//f_04,f_05,f_06
	unsigned char code;//f_07
	//
	short x0,y0;//f_08,f_0a
	unsigned char r1,g1,b1,__0f;//f_0c,f_0d,f_0e
	short x1,y1;//f_10,f_12
	unsigned char r2,g2,b2,__17;//f_14,f_15,f_16
	short x2,y2;//f_18,f_1a
	unsigned char r3,g3,b3,__1f;//f_1c,f_1d,f_1e
	short x3,y3;//f_20,f_22
};

struct POLY_GT3 {
	char __00[4];
	unsigned char r0,g0,b0;//f_04,f_05,f_06
	unsigned char code;//f_07
	//
	short x0,y0;//f_08,f_0a
	unsigned char u0,v0; unsigned short clut;//f_0c,f_0d,f_0e
	unsigned char r1,g1,b1,__13;//f_10,f_11,f_12
	short x1,y1;//f_14,f_16
	unsigned char u1,v1; unsigned short tpage;//f_18,f_19,f_1a
	unsigned char r2,g2,b2,__1f;//f_1c,f_1d,f_1e
	short x2,y2;//f_20,f_22
	unsigned char u2,v2; char __26[2];//f_24,f_25
};

struct POLY_GT4 {
	char __00[4];
	unsigned char r0,g0,b0;//f_04,f_05,f_06
	unsigned char code;//f_07
	//
	short x0,y0;//f_08,f_0a
	unsigned char u0,v0; unsigned short clut;//f_0c,f_0d,f_0e
	unsigned char r1,g1,b1,__13;//f_10,f_11,f_12
	short x1,y1;//f_14,f_16
	unsigned char u1,v1; unsigned short tpage;//f_18,f_19,f_1a
	unsigned char r2,g2,b2,__1f;//f_1c,f_1d,f_1e
	short x2,y2;//f_20,f_22
	unsigned char u2,v2; char __26[2];//f_24,f_25
	unsigned char r3,g3,b3,__2b;//f_28,f_29,f_2a
	short x3,y3;//f_2c,f_2e
	unsigned char u3,v3; char __32[2];//f_30,f_31
};

/*
 * Line Primitive Definitions
 */
struct LINE_F2 {
	char __00[4];
	unsigned char r0,g0,b0;//f_04,f_05,f_06
	unsigned char code;//f_07
	//
	short x0,y0;//f_08,f_0a
	short x1,y1;//f_0c,f_0e
};

struct LINE_G2 {
	char __00[4];
	unsigned char r0,g0,b0;//f_04,f_05,f_06
	unsigned char code;//f_07
	//
	short x0,y0;//f_08,f_0a
	unsigned char r1,g1,b1,__0f;//f_0c,f_0d,f_0e
	short x1,y1;//f_10,f_12
};

struct LINE_G3 {
	char __00[4];
	unsigned char r0,g0,b0;//f_04,f_05,f_06
	unsigned char code;//f_07
	//
	short x0,y0;//f_08,f_0a
	unsigned char r1,g1,b1,__0f;//f_0c,f_0d,f_0e
	short x1,y1;//f_10,f_12
	unsigned char r2,g2,b2,__17;//f_14,f_15,f_16
	short x2,y2;//f_18,f_1a
	unsigned pad;//f_1c
};

/*
 * Sprite Primitive Definitions
 */
//"struct t_ad_data_14"
struct SPRT {
	char __00[4];
	unsigned char r0,g0,b0;//f_04,f_05,f_06
	unsigned char code;//f_07
	//
	short x0,y0;//f_08,f_0a
	unsigned char u0,v0; unsigned short clut;//f_0c,f_0d,f_0e
	short w,h;//f_10,f_12
};

struct SPRT_16 {
	char __00[4];
	unsigned char r0,g0,b0;//f_04,f_05,f_06
	unsigned char code;//f_07
	//
	short x0,y0;//f_08,f_0a
	unsigned char u0,v0; unsigned short clut;//f_0c,f_0d,f_0e
};

struct SPRT_8 {
	char __00[4];
	unsigned char r0,g0,b0;//f_04,f_05,f_06
	unsigned char code;//f_07
	//
	short x0,y0;//f_08,f_0a
	unsigned char u0,v0; unsigned short clut;//f_0c,f_0d,f_0e
};

/*
 * Tile Primitive Definitions
 */
struct TILE {
	char __00[4];
	unsigned char r0,g0,b0;//f_04,f_05,f_06
	unsigned char code;//f_07
	//
	short x0,y0;//f_08,f_0a
	short w,h;//f_0c,f_0e
};

struct TILE_16 {
	char __00[4];
	unsigned char r0,g0,b0;//f_04,f_05,f_06
	unsigned char code;//f_07
	//
	short x0,y0;//f_08,f_0a
};

struct TILE_8 {
	char __00[4];
	unsigned char r0,g0,b0;//f_04,f_05,f_06
	unsigned char code;//f_07
	//
	short x0,y0;//f_08,f_0a
};

struct TILE_1 {
	char __00[4];
	unsigned char r0,g0,b0;//f_04,f_05,f_06
	unsigned char code;//f_07
	//
	short x0,y0;//f_08,f_0a
};

#endif
