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

#define setPolyFT3(p)	setlen(p, 7),  setcode(p, 0x24)
#define setPolyGT3(p)	setlen(p, 9),  setcode(p, 0x34)
#define setPolyF4(p)	setlen(p, 5),  setcode(p, 0x28)
#define setPolyFT4(p)	setlen(p, 9),  setcode(p, 0x2c)
#define setPolyG4(p)	setlen(p, 8),  setcode(p, 0x38)
#define setPolyGT4(p)	setlen(p, 12),  setcode(p, 0x3c)

#define setLineG2(p)	setlen(p, 4),  setcode(p, 0x50)
#define setLineG3(p)	setlen(p, 7),  setcode(p, 0x58),(p)->pad   = 0x55555555

#define setTile(p)	setlen(p, 3),  setcode(p, 0x60)
#define setTile1(p)	setlen(p, 2),  setcode(p, 0x68)

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
	/*00*/unsigned addr: 24;
	/*03*/unsigned len: 8;
	/*04*/unsigned char r0,g0,b0;
	/*07*/unsigned char code;
};

struct POLY_F3 {//size 0x14
	/*00*/unsigned tag;
	/*04*/unsigned char r0,g0,b0;
	/*07*/unsigned char code;
	//
	/*08*/short x0,y0;
	/*0c*/short x1,y1;
	/*10*/short x2,y2;
};

struct POLY_F4 {//size 0x18
	/*00*/unsigned tag;
	/*04*/unsigned char r0,g0,b0;
	/*07*/unsigned char code;
	//
	/*08*/short x0,y0;
	/*0c*/short x1,y1;
	/*10*/short x2,y2;
	/*14*/short x3,y3;
};

struct POLY_FT3 {//size 0x20
	/*00*/unsigned tag;
	/*04*/unsigned char r0,g0,b0;
	/*07*/unsigned char code;
	//
	/*08*/short x0,y0;
	/*0c*/unsigned char u0,v0; unsigned short clut;
	/*10*/short x1,y1;
	/*14*/unsigned char u1,v1;
	/*16*/unsigned short tpage;
	/*18*/short x2,y2;
	/*1c*/unsigned char u2,v2; char __1e[2];
};

struct POLY_FT4 {//size 0x28
	/*00*/unsigned tag;
	/*04*/unsigned char r0,g0,b0;
	/*07*/unsigned char code;
	//
	/*08*/short x0,y0;
	/*0c*/unsigned char u0,v0; unsigned short clut;
	/*10*/short x1,y1;
	/*14*/unsigned char u1,v1; unsigned short tpage;
	/*18*/short x2,y2;
	/*1c*/unsigned char u2,v2; /*unsigned */short pad1;
	/*20*/short x3,y3;
	/*24*/unsigned char u3,v3; /*unsigned */short pad2;
};

struct POLY_G3 {//size 0x1c
	/*00*/unsigned tag;
	/*04*/unsigned char r0,g0,b0;
	/*07*/unsigned char code;
	//
	/*08*/short x0,y0;
	/*0c*/unsigned char r1,g1,b1,__0f;
	/*10*/short x1,y1;
	/*14*/unsigned char r2,g2,b2,__17;
	/*18*/short x2,y2;
};

struct POLY_G4 {//size 0x24
	/*00*/unsigned tag;
	/*04*/unsigned char r0,g0,b0;
	/*07*/unsigned char code;
	//
	/*08*/short x0,y0;
	/*0c*/unsigned char r1,g1,b1,pad1;
	/*10*/short x1,y1;
	/*14*/unsigned char r2,g2,b2,pad2;
	/*18*/short x2,y2;
	/*1c*/unsigned char r3,g3,b3,pad3;
	/*20*/short x3,y3;
};

struct POLY_GT3 {//size 0x28
	/*00*/char __00[4];
	/*04*/unsigned char r0,g0,b0;
	/*07*/unsigned char code;
	//
	/*08*/short x0,y0;
	/*0c*/unsigned char u0,v0; unsigned short clut;
	/*10*/unsigned char r1,g1,b1,__13;
	/*14*/short x1,y1;
	/*18*/unsigned char u1,v1; unsigned short tpage;
	/*1c*/unsigned char r2,g2,b2,__1f;
	/*20*/short x2,y2;
	/*24*/unsigned char u2,v2; char __26[2];
};

struct POLY_GT4 {//size 0x34
	/*00*/unsigned tag;
	/*04*/unsigned char r0,g0,b0;
	/*07*/unsigned char code;
	//
	/*08*/short x0,y0;
	/*0c*/unsigned char u0,v0; unsigned short clut;
	/*10*/unsigned char r1,g1,b1,__13;
	/*14*/short x1,y1;
	/*18*/unsigned char u1,v1; unsigned short tpage;
	/*1c*/unsigned char r2,g2,b2,__1f;
	/*20*/short x2,y2;
	/*24*/unsigned char u2,v2; char __26[2];
	/*28*/unsigned char r3,g3,b3,__2b;
	/*2c*/short x3,y3;
	/*30*/unsigned char u3,v3; char __32[2];
};

/*
 * Line Primitive Definitions
 */
struct LINE_F2 {//size 0x10
	/*00*/unsigned tag;
	/*04*/unsigned char r0,g0,b0;
	/*07*/unsigned char code;
	//
	/*08*/short x0,y0;
	/*0c*/short x1,y1;
};

struct LINE_G2 {//size 0x14
	/*00*/unsigned tag;
	/*04*/unsigned char r0,g0,b0;
	/*07*/unsigned char code;
	//
	/*08*/short x0,y0;
	/*0c*/unsigned char r1,g1,b1,__0f;
	/*10*/short x1,y1;
};

struct LINE_G3 {//size 0x20
	/*00*/unsigned tag;
	/*04*/unsigned char r0,g0,b0;
	/*07*/unsigned char code;
	//
	/*08*/short x0,y0;
	/*0c*/unsigned char r1,g1,b1,__0f;
	/*10*/short x1,y1;
	/*14*/unsigned char r2,g2,b2,__17;
	/*18*/short x2,y2;
	/*1c*/unsigned pad;
};

/*
 * Sprite Primitive Definitions
 */
struct SPRT {//size 0x14
	/*00*/unsigned tag;
	/*04*/unsigned char r0,g0,b0;
	/*07*/unsigned char code;
	//
	/*08*/short x0,y0;
	/*0c*/unsigned char u0,v0; unsigned short clut;
	/*10*/short w,h;
};

struct SPRT_16 {//size 0x10
	/*00*/char __00[4];
	/*04*/unsigned char r0,g0,b0;
	/*07*/unsigned char code;
	//
	/*08*/short x0,y0;
	/*0c*/unsigned char u0,v0; unsigned short clut;
};

struct SPRT_8 {//size 0x10
	/*00*/char __00[4];
	/*04*/unsigned char r0,g0,b0;
	/*07*/unsigned char code;
	//
	/*08*/short x0,y0;
	/*0c*/unsigned char u0,v0; unsigned short clut;
};

/*
 * Tile Primitive Definitions
 */
struct TILE {//size 0x10
	/*00*/unsigned tag;
	/*04*/unsigned char r0,g0,b0;
	/*07*/unsigned char code;
	//
	/*08*/short x0,y0;
	/*0c*/short w,h;
};

struct TILE_16 {//size 0xc
	/*00*/char __00[4];
	/*04*/unsigned char r0,g0,b0;
	/*07*/unsigned char code;
	//
	/*08*/short x0,y0;
};

struct TILE_8 {//size 0xc
	/*00*/char __00[4];
	/*04*/unsigned char r0,g0,b0;
	/*07*/unsigned char code;
	//
	/*08*/short x0,y0;
};

struct TILE_1 {//size 0xc
	/*00*/char __00[4];
	/*04*/unsigned char r0,g0,b0;
	/*07*/unsigned char code;
	//
	/*08*/short x0,y0;
};

#endif
