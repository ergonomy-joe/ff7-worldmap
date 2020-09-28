/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
#ifndef __FF7_STRUCTS_H__
#define __FF7_STRUCTS_H__

//====---- ----====
typedef union {
	struct {
		unsigned char r,g,b,a;
	} c;
	unsigned int rgba;
} tRGBA;

typedef union {
	struct {
		unsigned char b,g,r,a;
	} c;
	unsigned int bgra;
} tBGRA;

//tRGBA rgba = {rr, gg, bb};
#define tRGBA_init(rgba,rr,gg,bb) ((rgba).c.r = (rr), (rgba).c.g = (gg), (rgba).c.b = (bb), memset(&((rgba).c.a), 0, 1))

struct fBGRA {
	float b, g, r, a;
};

typedef char t_string_20[0x20];//for scripts?

struct VECTOR {//size 0x10
	/*00*/int f_00;//vx
	/*04*/int f_04;//vy
	/*08*/int f_08;//vz
	/*0c*/int f_0c;
};

struct SVECTOR {//size 8
	/*00*/short f_00;//vx
	/*02*/short f_02;//vy
	/*04*/short f_04;//vz
	/*06*/short f_06;//???
};

//SVECTOR sv = {x, y, z};
#define SVECTOR_init(sv,x,y,z) ((sv).f_00 = (x), (sv).f_02 = (y), (sv).f_04 = (z), memset(&((sv).f_06), 0, 2))
//VECTOR v = {x, y, z};
#define VECTOR_init(sv,x,y,z) ((sv).f_00 = (x), (sv).f_04 = (y), (sv).f_08 = (z), memset(&((sv).f_0c), 0, 4))

#pragma pack(1)
struct MATRIX {//size 0x1e
	/*00*/short f_00[3][3];/*3x3 rotation matrix*/
	/*12*/int f_12[3];/*transfer vector*/
};
#pragma pack()

struct tBlendMode {//size 0x24
	/*00*/int f_00;
	/*04*/int f_04;
	/*08*/int dwBlendAlpha;
	/*0c*/D3DBLEND dwSrcBlend;
	/*10*/int f_10;//dwSrcBlendCaps
	/*14*/D3DBLEND dwDstBlend;
	/*18*/int f_18;//dwDestBlendCaps
	/*1c*/int f_1c;
	/*20*/int f_20;
};

//gl_code driver?
struct t_gl_code_450 {
	/*000*/int f_000;
	/*004*/int f_004;
	/*008*/struct fBGRA f_008;//clear color?
	/*018*/HGLRC f_018;
	/*01c*/PIXELFORMATDESCRIPTOR f_01c;//size 0x28
	/*044*/float f_044[0x100];//some lookup table/palette
	/*444*/int f_444;
	/*448*/int f_448;
	/*44c*/int f_44c;
};

struct t_gl_code_10 {
	/*00*/float f_00;//red(or blue)
	/*04*/float f_04;//green
	/*08*/float f_08;//blue(or red)
	/*0c*/float f_0c;//alpha
};

struct t_gl_code_14 {
	/*00*/float *f_00;//red(or blue)
	/*04*/float *f_04;//green
	/*08*/float *f_08;//blue(or red)
	/*0c*/float *f_0c;//alpha
	/*10*/struct t_gl_code_10 *f_10;
};

//some flag for gl_code:"GL INIT ..."
struct t_gl_code_0c {
	/*00*/int f_00;//front face CW?CCW?
	/*04*/int f_04;//double buffer
	/*08*/int f_08;//"full" (unused)
};

//texture group?
struct t_gl_code_08 {//size 8
	/*00*/int f_00;//# textures
	/*04*/int *f_04;//textures "name" array
};

struct tMatrixInfo {//size 0x2c
	//-- unused stuff --
	/*00*/int f_00;//has "matrix stack" flag
	/*04*/int f_04;//# elements in f_0c and f_10
	/*08*/char __08[4];
	/*0c*/unsigned char *f_0c;//[unused]
	/*10*/LPD3DMATRIX f_10;//an array
	//-- --
	/*14*/LPD3DMATRIX f_14;//world matrix
	/*18*/LPD3DMATRIX f_18;//view matrix
	/*1c*/LPD3DMATRIX f_1c;//projection matrix
	//--
	/*20*/D3DMATRIXHANDLE f_20;//world matrix related
	/*24*/D3DMATRIXHANDLE f_24;//view matrix related
	/*28*/D3DMATRIXHANDLE f_28;//projection matrix related
};

struct t_ComplexBlendInfo {
	/*00*/unsigned char f_00[8];
	//-- --
	/*08*/tRGBA f_08;//TODO: actually tBGRA
	/*0c*/void (*f_0c)(LPD3DMATRIX);
	/*10*/void (*f_10)(void);//multiple callback?
	//-- used by dx_mesh? --
	/*14*/float f_14;
	/*18*/float f_18;
	/*1c*/float f_1c;
	/*20*/float f_20;
	//-- --
	/*24*/float f_24;
	/*28*/float f_28;
	/*2c*/int f_2c;
	/*30*/struct tRenderState *f_30;
	//-- --
	/*34*/unsigned char f_34[0x10];
};

struct t_tim_08_bis {//size 8
	/*00*/short w_DX,w_DY;
	/*04*/short w_W,w_H;
};

//palette(CLUT) info?
struct t_tim_palette {//size 0x10
	/*00*/int dw_BNUM;//data size + 0xc
	/*04*/struct t_tim_08_bis f_04;
	/*0c*/unsigned short *f_0c;//palette data
};

struct t_tim_fileHeader {//size 8
	/*00*/int dw_ID;
	/*04*/int dw_FLAG;
};

struct t_tim_info {//size 0x44
	/*00*/struct t_tim_fileHeader *f_00;
	/*04*/int f_04;//palette size?
	/*08*/struct t_tim_palette *p_timPalette_CLUT;
	/*0c*/struct t_tim_palette *p_timPalette_DATA;
	/*10*/int dwBPP;
	/*14*/int dwWidth,dwHeight;
	//-- --
	/*1c*/int dwTexWidth,dwTexHeight;
	/*24*/int dwTexX,dwTexY;
	/*2c*/int f_2c;
	/*30*/int f_30;//some flags
	/*34*/int f_34;//some flag
	//-- --
	/*38*/int f_38;
	/*3c*/int f_3c;
	/*30*/tRGBA f_40;
};

//used by "coaster"
struct t_dx_sfx_xxx_08 {//size 8
	/*00*/LPD3DMATRIX f_00;
	/*04*/struct t_dx_sfx_84 *f_04;
};

struct t_g_drv_GroupInfo {//size 0x38
	/*00*/int dwMaterialType;
	/*04*/int f_04;//start indice
	/*08*/int f_08;//# triangles
	/*0c*/int f_0c;//start vertex
	/*10*/int f_10;//# vertices
	/*14*/char __14[0x18];
	/*2c*/int f_2c;//start [u,v]
	/*30*/int f_30;//has [u,v]/is textured?
	/*34*/int f_34;
};

struct t_g_drv_0c {//size 0xc
	/*00*/float f_00;//x
	/*04*/float f_04;//y
	/*08*/float f_08;//z
};

struct t_g_drv_FTexCoord {//size 8
	/*00*/float fU;
	/*04*/float fV;
};

//"PLY"
struct t_plytopd_PolygonDescriptor {//size 0x38
	/*00*/int dwIsQuad;
	/*04*/int dwIsLine;
	/*08*/int dwIsPolygon;//triangle/quad
	/*0c*/int dwIsSprite;
	/*10*/int dwWidth,dwHeight;
	/*18*/int f_18[4];//vertex indices
	/*28*/int f_28[4];//normal indices
};

//"MAT"
struct t_plytopd_MaterialDescriptor {//size 0x58
	/*00*/int dwMaterialType;//0/1/2/3/4
	/*04*/int f_04;//semi-transparency rate
	/*08*/int f_08;//flag
	/*0c*/int f_0c;
	/*10*/int f_10;
	/*14*/tRGBA f_14[4];
	/*24*/int f_24;
	/*28*/int f_28;
	/*2c*/struct t_g_drv_FTexCoord f_2c[4];
	//-- --
	/*4c*/int f_4c;
	/*50*/int dwTpage;
	/*54*/int dwClut;
};

struct t_local_plytopd_24 {//size 0x24
	/*00*/char *p_HRC;//HRC file name
	/*04*/char *f_04;
	/*08*/char *f_08;//folder
	/*0c*/char *f_0c;//extension
	//-- --
	/*10*/int f_10;//dwFPS?
	/*14*/int f_14;//# of elements in f_18?
	/*18*/struct t_direct_20 **f_18;//animations names?
	/*1c*/struct t_direct_FileList *f_1c;
	/*20*/struct t_plytopd_e4 *f_20;
};

struct t_plytopd_0c {//size 0xc
	/*00*/int f_00;//failed flag?
	/*04*/struct t_tim_info *f_04;
	/*08*/struct tTexHeader *f_08;
};

struct t_polygon_TriangleInfo {//size 0x18
	/*00*/unsigned short f_00;
	/*02*/unsigned short f_02[3];//vertex indices
	/*08*/unsigned short f_08[3];//normal indices
	/*0e*/unsigned short __0e[3];
	/*14*/unsigned short __14[2];
};

struct t_dx_sfx_84 {//size 0x84
	/*00*/struct t_dx_sfx_e0 *f_00;
	/*04*/int dwPolygonType;
	/*08*/int f_08;//[unused?]
	/*0c*/struct t_g_drv_0c f_0c[4];
	/*3c*/struct { float f_00,f_04; } f_3c[4];//texcoords
	/*5c*/tRGBA f_5c[4];//colors
	/*6c*/float f_6c[4];
	/*7c*/void *f_7c;
	/*80*/int f_80;//palette index
};

struct t_instance_8 {//size 0x8
	/*00*/unsigned dwFrameCounter;
	/*04*/struct t_heap_3c *f_04;
};

struct t_instance_90 {//size 0x90
	/*00*/struct t_instance_90 *pNext;
	//-- --
	/*04*/int f_04;//transform/render related?
	/*08*/struct t_dx_sfx_84 *f_08;
	/*0c*/D3DMATRIX f_0c;
	/*4c*/struct t_ComplexBlendInfo f_4c;
};

struct t_instance_18 {//size 0x18
	/*00*/int dwActive;
	/*04*/int f_04;
	/*08*/int f_08;//some matrix attribute(0:none,1:???,2:???)?
	/*0c*/unsigned dwFrameCounter;
	/*10*/struct t_instance_90 *f_10;
	/*14*/struct t_instance_8 *f_14;
};

////////////////////////////////////////
struct t_light_24 {//size 0x24
	/*00*/int f_00;//type?active?set to 0/never read
	/*04*/tBGRA f_04;
	/*08*/struct t_g_drv_0c f_08;
	/*14*/struct fBGRA f_14;
};

struct t_light_5ac {//size 0x5ac
	/*000*/unsigned dwFlags;
	/*004*/int dwLightCount;//(usualy 3)
	/*008*/struct t_light_24 *f_008[3];
	/*014*/struct fBGRA f_014;
	/*024*/struct fBGRA f_024;
	/*034*/tBGRA f_034;
	//-- temporary names, must check this --
	/*038*/D3DMATRIX f_038;//"light matrix"
	/*078*/D3DMATRIX f_078;//"color matrix"
	/*0b8*/D3DMATRIX f_0b8;//"product matrix"
	/*0f8*/D3DMATRIX f_0f8;//"result matrix"
	/*138*/int f_138;//flag for f_13c?
	/*13c*/D3DMATRIX f_13c;
	/*17c*/int f_17c;
	/*180*/tRGBA f_180;
	/*184*/float f_184;
	/*188*/tRGBA f_188;
	/*18c*/float f_18c;
	/*190*/float f_190;
	/*194*/float f_194;
	/*198*/float f_198;
	/*19c*/LPD3DMATRIX f_19c;
	/*1a0*/float f_1a0;
	/*1a4*/tRGBA f_1a4[0x100];
	/*5a4*/char __5a4[4];
	/*5a8*/tBGRA f_5a8;
};
////////////////////////////////////////

struct tTransparentElement {//size 0xa0
	/*00*/struct tTransparentElement *pNext;
	/*04*/int dwGroupIndex;
	/*08*/struct tPolygonInfo *f_08;
	/*0c*/struct tRenderState *f_0c;
	/*10*/int f_10;//use f_14?
	/*14*/D3DMATRIX f_14;
	/*54*/int f_54;//use f_58?
	/*58*/LPD3DMATRIX f_58;
	/*5c*/struct t_ComplexBlendInfo f_5c;
};

struct tTransparentHeap {//size 0xc
	/*00*/struct t_heap_3c *f_00;//heap of [struct tTransparentElement]
	/*04*/struct tTransparentElement *pHead,*pTail;
};

struct tRenderState {//size 0x64
	/*00*/int f_00;//[unused]set by dx_mat.cpp only?
	/*04*/int f_04;//[almost unused]set by dx_mat.cpp and read by dx_rend.cpp only?
	/*08*/int f_08;//flags?
	/*0c*/unsigned f_0c;//active flags?
	/*10*/int f_10;//texture related?
	/*14*/struct tTextureObj *f_14;
	//-- [unused]only set by plytopd.cpp? --
	/*18*/int f_18;
	/*1c*/int dwTpage;
	/*20*/int dwClut;
	//-- --
	/*24*/D3DSHADEMODE dwD3DShadeMode;
	/*28*/int f_28;//parameter for D3DLIGHTSTATE_AMBIENT
	/*2c*/int f_2c;//[always 0]
	/*30*/LPD3DMATERIALHANDLE f_30;//[always 0]a parameter for D3DLIGHTSTATE_MATERIAL?
	/*34*/D3DBLEND dwSrcBlend;
	/*38*/D3DBLEND dwDstBlend;
	/*3c*/int f_3c;//[unused]set by dx_mat.cpp only?
	/*40*/D3DFIXED dwAlphaRef;//[unused]parameter for D3DRENDERSTATE_ALPHAFUNC?
	/*44*/int dwBlendMode;
	/*48*/int f_48;
	/*4c*/int f_4c;
	/*50*/int f_50;
	/*54*/char __54[4];
	/*58*/int *f_58;
	/*5c*/int dwBlendAlpha;
	/*60*/int f_60;//[unused]set only?
};

//D3DVERTEX?D3DTLVERTEX?D3DLVERTEX?
struct t_dx_rend_vertex_20 {//size 0x20
	/*00*/float f_00;//x
	/*04*/float f_04;//y
	/*08*/float f_08;//z
	/*0c*/float f_0c;//rhw
	/*10*/tRGBA f_10;//TODO: actually tBGRA
	/*14*/unsigned f_14;//specular
	/*18*/float f_18;//u
	/*1c*/float f_1c;//v
};

struct tIndexedVertices {//size 0x34
	/*00*/struct tIndexedVertices *pNext;
	//
	/*04*/char __04[4];
	/*08*/int f_08;
	/*0c*/unsigned dwVertexCount;
	/*10*/unsigned char *f_10; struct t_dx_rend_vertex_20 *lpvVertices;
	/*18*/int dwIndexCount;
	/*1c*/unsigned char *f_1c; unsigned short *lpwIndices;
	/*24*/unsigned char *f_24, *lpbPalette;
	//
	/*2c*/char __2c[4];
	/*30*/struct t_dx_sfx_e0 *f_30;
};

struct tIndexedPrimitives {//size 0x28
	/*00*/char __00[4];
	/*04*/int f_04;//vertex size
	//-- parameters for DrawIndexedPrimitive(or whatever) --
	/*08*/D3DPRIMITIVETYPE d3dptPrimitiveType;
	/*0c*/D3DVERTEXTYPE dwVertexTypeDesc;
	/*10*/struct t_dx_rend_vertex_20 *lpvVertices;//[aligned f_24]
	/*14*/unsigned long dwVertexCount;
	/*18*/unsigned short *lpwIndices;
	/*1c*/int dwIndexCount;
	/*20*/unsigned dwFlags;
	//-- --
	/*24*/void *f_24;//vertices memory(unaligned)
};

struct tEdge {//size 4
	/*00*/short f_00,f_02;
};

struct tBoundingBox {//size 0x1c
	/*00*/char __00[4];
	/*04*/float x0,y0,z0;
	/*10*/float x1,y1,z1;
};

//pVertex
#define POLYGONLIST_0 0
//pNormal
#define POLYGONLIST_1 1
//size 0xc
#define POLYGONLIST_2 2
//uv
#define POLYGONLIST_3 3
//pColorVertex
#define POLYGONLIST_4 4
//pTriangleInfo
#define POLYGONLIST_5 5
//f_68/render state
#define POLYGONLIST_6 6
//pGroupInfo
#define POLYGONLIST_7 7
//some indexes
#define POLYGONLIST_8 8

struct tPolygonData {//size 0x80
	/*00*/int dwVersion;//(must be 1)
	/*04*/int f_04;
	/*08*/int dwVertexType;//vertex type(0=D3DVT_VERTEX,1=D3DVT_LVERTEX,2=D3DVT_TLVERTEX)
	/*0c*/int dwVertexCount;//# vertices(elements in pVertex/f_74)?
	/*10*/int dwNormalCount;//# elements in pNormal?
	/*14*/int f_14;//# elements in f_48?
	/*18*/int f_18;//# [u,v](elements in f_4c)?
	/*1c*/int dwColorVertexCount;//# elements in pColorVertex?
	/*20*/int dwEdgeCount;//# elements in pEdge?
	/*24*/int dwTriangleCount;//# triangles(elements in pColorTriangle/pTriangleInfo)?
	/*28*/int f_28;//# elements in f_60?
	/*2c*/int f_2c;//# elements in f_64?
	/*30*/int f_30;//# elements in f_68?
	/*34*/int dwGroupCount;//# elements in pGroupInfo?
	/*38*/int dwBoundingBoxCount;//# elements in pBoundingBox?
	/*3c*/int f_3c;//flag: has array f_74?
	//-- end of header --
	/*40*/struct t_g_drv_0c *pVertex;//"vertices"
	/*44*/struct t_g_drv_0c *pNormal;//"normal"
	/*48*/void *f_48;//object size 0xc?
	/*4c*/struct t_g_drv_FTexCoord *f_4c;//"tex coordinates"
	/*50*/tRGBA *pColorVertex;//"vertex colors"
	/*54*/tRGBA *pColorTriangle;//"polygon colors"
	/*58*/struct tEdge *pEdge;//"edges"
	/*5c*/struct t_polygon_TriangleInfo *pTriangleInfo;//"polygons"
	/*60*/void *f_60;//objects size 0x18?
	/*64*/void *f_64;//objects size 3?
	/*68*/struct tRenderState *f_68;//"hundreds"
	/*6c*/struct t_g_drv_GroupInfo *pGroupInfo;//"groups"
	/*70*/struct tBoundingBox *pBoundingBox;//"bounding box"
	/*74*/int *f_74;//"normal index table"
	/*78*/int f_78;
	//-- --
	/*7c*/struct t_list_List **f_7c;
};

struct t_light_18_bis {// size 0x18
	/*00*/struct t_g_drv_0c *f_00;//normal vector
	/*04*/struct fBGRA f_04;
	/*14*/tBGRA f_14;
};

struct t_dx_3d2d_14 {//size 0x14
	/*00*/float f_00;//x
	/*04*/float f_04;//y
	/*08*/float f_08;//z
	/*0c*/float f_0c;//hw?
	/*10*/float f_10;//never set.used by dx_3d2d.cpp
};

struct t_g_drv_LockedVertexBuffer {//size 0x24
	/*00*/char __00[4];
	/*04*/int dwVertexCount;
	/*08*/void *f_08;//struct t_dx_rend_vertex_20 *?
	/*0c*/void *f_0c;//struct t_dx_rend_vertex_20 *?[unused]
	/*10*/int *f_10;
	/*14*/struct t_g_drv_0c *f_14;
	/*18*/struct t_light_18_bis *f_18;
	/*1c*/struct t_g_drv_FTexCoord *f_1c;
	/*20*/struct tTextureObj *f_20;
};

#define SWRENDERFLAG_00000001 0x00000001
#define SWRENDERFLAG_00000002 0x00000002
//
//-- [aligned quad:texture x1] --
#define SWRENDERFLAG_00000020 0x00000020
//-- [aligned quad:texture x2] --
#define SWRENDERFLAG_00000040 0x00000040
//-- [aligned quad:texture arbitrary] --
#define SWRENDERFLAG_00000080 0x00000080
//
#define SWRENDERFLAG_00000400 0x00000400
#define SWRENDERFLAG_00000800 0x00000800
//
#define SWRENDERFLAG_00004000 0x00004000
#define SWRENDERFLAG_00008000 0x00008000
#define SWRENDERFLAG_00010000 0x00010000
//
#define SWRENDERFLAG_00100000 0x00100000
//
#define SWRENDERFLAG_01000000 0x01000000

struct tPolygonInfo {//size 0xb0
	/*00*/int dwActive;
	/*04*/int dwClipped;
	/*08*/char __08[8];
	/*10*/int dwGroupCount;//# of elements in f_50?
	/*14*/struct t_instance_18 f_14;
	/*2c*/int f_2c;
	/*30*/struct tPolygonData *f_30;
	/*34*/struct tRenderState *f_34;
	/*38*/int f_38;//flag related to f_3c
	/*3c*/struct tRenderState **f_3c;//indexed by f_10 too
	/*40*/struct tMatrixInfo *f_40;
	/*44*/struct t_light_5ac *f_44;//void *
	/*48*/LPUNKNOWN *f_48;
	/*4c*/LPDIRECT3DEXECUTEBUFFER *f_4c;
	/*50*/struct tIndexedPrimitives **f_50;//indexed by f_10
	/*54*/void *f_54;
	/*58*/struct t_dx_3d2d_14 *f_58;
	/*5c*/struct t_g_drv_LockedVertexBuffer *f_5c;
	//-- --
	/*60*/int f_60;//sizeof(0x34)?
	/*64*/LPD3DLVERTEX f_64;
	/*68*/int f_68;//sizeof(0x20)?
	/*6c*/void *f_6c;//something size 0x20
	/*70*/int f_70;//sizeof(0x20)?
	/*74*/void *f_74;//something size 0x10
	/*78*/int f_78;//sizeof(0x3f)?
	/*7c*/char __7c[0x18];
	/*94*/int f_94;
	/*98*/char __98[4];
	/*9c*/struct t_ComplexBlendInfo *f_9c;
	/*a0*/struct tRenderState *f_a0[2];//for C_005D1BA4; is it correct?
	/*a8*/unsigned dwSWRenderFlags;//property mask?(copied from "struct t_rsd_74::f_70")
	/*ac*/void *f_ac;
};

struct tTextureInfo {//size 0x80
	/*00*/int dwWidth;
	/*04*/int dwHeight;
	/*08*/int dwPitch;
	/*0c*/void *pPixels;
	//-- --
	/*10*/int dwUsePalette;
	/*14*/int dwBitsPerIndex;
	/*18*/int f_18;//indexed to 8bit?
	/*1c*/int f_1c;//total palette size?
	/*20*/int f_20;//palette size
	/*24*/tRGBA *f_24;//palette?
	//-- --
	/*28*/int dwBitsPerPixel;
	/*2c*/int dwBytesPerPixel;
	/*30*/int dwRedBitCount,dwGreenBitCount,dwBlueBitCount,dwAlphaBitCount;
	/*40*/int dwRedMask,dwGreenMask,dwBlueMask,dwAlphaMask;
	/*50*/int dwRedShift,dwGreenShift,dwBlueShift,dwAlphaShift;
	/*60*/int dwRedUnusedBits,dwGreenUnusedBits,dwBlueUnusedBits,dwAlphaUnusedBits;
	/*70*/int dwRedMax,dwGreenMax,dwBlueMax,dwAlphaMax;
};

struct tTextureObj {//size 0xa0
	/*00*/LPDIRECTDRAWSURFACE f_00;
	/*04*/LPDIRECT3DTEXTURE2 f_04;
	/*08*/LPDIRECTDRAWSURFACE f_08;
	/*0c*/LPDIRECT3DTEXTURE2 f_0c;
	/*10*/DDSURFACEDESC f_10;//size 0x6c
	/*7c*/D3DTEXTUREHANDLE dwTextureHandle;
	//--
	/*80*/struct tTextureInfo *f_80;
	/*84*/struct tTexHeader *f_84;
	/*88*/int dwCurrentPaletteIndex;
	/*8c*/struct tPalette *f_8c;
	/*90*/char __90[8];
	/*98*/int *f_98;
	/*9c*/struct t_gl_code_08 *f_9c;//only for opengl?
};

struct t_dx_sfx_70 {//size 0x70
	/*00*/struct t_heap_3c *f_00;//of [struct t_dx_sfx_e0]
	/*04*/struct t_heap_3c *f_04;//of [struct t_dx_sfx_84]
	/*08*/struct t_heap_3c *f_08;//of [struct tIndexedVertices]
	/*0c*/struct t_heap_3c *f_0c;//of objects size 0xa0?
	/*10*/struct tPolygonData *f_10[0x10];
	/*50*/int f_50;
	/*54*/int f_54;
	//-- indices --
	/*58*/void *f_58;//triangle[flag 1]
	/*5c*/void *f_5c;//quad[flag 1]
	/*60*/void *f_60;//triangle[flag 0]
	/*64*/void *f_64;//quad[flag 0]
	/*68*/void *f_68;//line
	//-- --
	/*6c*/struct t_aa0 *f_6c;
};

//"TF2D.P"
#define DX_SFX_TYPE_00 0x00
//"TF3D.P"
#define DX_SFX_TYPE_01 0x01
//"TG2D.P"
#define DX_SFX_TYPE_02 0x02
//"TG3D.P"
#define DX_SFX_TYPE_03 0x03
//"T2D.P"
#define DX_SFX_TYPE_04 0x04
//"T3D.P"
#define DX_SFX_TYPE_05 0x05
//"TGT2D.P"
#define DX_SFX_TYPE_06 0x06
//"TGT3D.P"
#define DX_SFX_TYPE_07 0x07
//"SF2D.P"
#define DX_SFX_TYPE_08 0x08
//"SF3D.P"
#define DX_SFX_TYPE_09 0x09
//"SG2D.P"
#define DX_SFX_TYPE_0A 0x0a
//"SG3D.P"
#define DX_SFX_TYPE_0B 0x0b
//"S2D.P"
#define DX_SFX_TYPE_0C 0x0c
//"S3D.P"
#define DX_SFX_TYPE_0D 0x0d
//"SGT2D.P"
#define DX_SFX_TYPE_0E 0x0e
//"SGT3D.P"
#define DX_SFX_TYPE_0F 0x0f
//unused?
#define DX_SFX_TYPE_10 0x10
//variation on DX_SFX_TYPE_0C
#define DX_SFX_TYPE_11 0x11
//line flat
#define DX_SFX_TYPE_12 0x12
//line gouraud
#define DX_SFX_TYPE_13 0x13

struct t_dx_sfx_e0 {//size 0xe0
	/*00*/int dwPolygonType;//polygon type?0x00~0x11
	/*04*/int f_04;
	/*08*/int f_08;//some flag for unused stuff
	/*0c*/struct tRenderState *f_0c;
	/*10*/struct tMatrixInfo *f_10;
	/*14*/struct tPolygonInfo *f_14;
	/*18*/int f_18;
	/*1c*/struct t_dx_sfx_3c *f_1c;
	/*20*/void *f_20;
	/*24*/float f_24,f_28;//texture[u,v] or [width,height]?
	/*2c*/struct t_dx_sfx_70 *f_2c;
	/*30*/struct t_instance_8 *f_30;
	/*34*/unsigned f_34;//flags:from "struct t_rsd_74::f_2c"
	//-- --
	/*38*/int f_38;//# vert per polygon
	/*3c*/int f_3c;//# ind per polygon
	/*40*/int f_40;//vertex size
	/*44*/int f_44;//indice size
	/*48*/int f_48;
	/*4c*/int f_4c;
	/*50*/int dwCapacity;
	/*54*/int dwFrameCounter;
	/*58*/void *f_58;
	//-- for lines? --
	/*5c*/int f_5c;//# vert per line
	/*60*/int f_60;//# ind per line
	/*64*/int f_64;//vertex size
	/*68*/int f_68;//indice size
	/*6c*/void *f_6c;
	//-- --
	/*70*/union {
		unsigned char *asUnsignedChar;
		struct t_dx_rend_vertex_20 *asVertex;
	} f_70;//vertices
	/*74*/void *f_74;//indices
	/*78*/unsigned char *lpbCurPalette;
	/*7c*/unsigned dwLastPalette;
	/*80*/unsigned char *f_80;//vertices
	/*84*/unsigned char *f_84;//indices
	/*88*/unsigned char *lpbNextPalette;
	/*8c*/struct tIndexedVertices *f_8c;
	/*90*/void (*f_90)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);
	/*94*/void (*f_94)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);
	//
	/*98*/int f_98;
	/*9c*/LPD3DMATRIX f_9c;
	/*a0*/D3DMATRIX f_a0;
};

//-- used for some member copy[TODO] --
struct some_stupid_stuff { char __00[4]; };
#define STUPID(a,b) *(struct some_stupid_stuff *)&(a) = *(struct some_stupid_stuff *)&(b)
//-- --

//info for frambuffer capture?
struct t_dx_sfx_b8 {//size 0xb8
	/*00*/int f_00;//flag "sys"(tem memory)?
	/*04*/int f_04;//some x?
	/*08*/int f_08;//some y?
	/*0c*/int f_0c;//some width?
	/*10*/int f_10;//some height?
	/*14*/int f_14;//some x ratio?
	/*18*/int f_18;//some y ratio?
	/*1c*/int f_1c;//color key on?
	/*20*/int f_20;//another width?
	/*24*/int f_24;//another height?
	/*28*/int f_28;//bytes per row?
	/*2c*/int f_2c;//bytes per pixel?
	/*30*/void *f_30;//locked surface?
	/*34*/struct tTextureInfo f_34;//size 0x80
	/*b4*/void *f_b4;//image data?
};

//struct tTextureInfo for Direct3D?
struct tD3DTextureInfo: tTextureInfo {//size 0x84
	/*80*/LPDDSURFACEDESC f_80;
};

struct tTexHeader {//size 0xec
	/*00*/int dwVersion;
	/*04*/int f_04;//type?flag?
	/*08*/int f_08;//color key flag
	/*0c*/int f_0c;//flag[set but never read]?
	/*10*/int f_10;
	/*14*/int f_14,f_18;//min,max bits[color]
	/*1c*/int f_1c,f_20;//min,max bits[alpha]
	/*24*/int f_24,f_28;//min,max bits[total]
	/*2c*/int f_2c;//flag(s)
	/*30*/int dwPaletteCount;
	/*34*/int dwPaletteEntryCount;
	/*38*/int dwBPP;
	/*3c*/struct tTextureInfo f_3c;
	/*bc*/int f_bc;//use color key?
	/*c0*/unsigned char *f_c0;//color key
	/*c4*/int f_c4;//alpha related
	/*c8*/int dwBlendMode;//almost not used?
	/*cc*/unsigned char f_cc;//alpha related flag
	/*cd*/unsigned char f_cd;//y mirror flag(for openGL)
	/*ce*/char __ce[2];
	/*d0*/int dwCurrentPaletteIndex;
	/*d4*/unsigned char *f_d4;//data
	/*d8*/void *f_d8;
	//-- CLUT related? --
	/*dc*/int f_dc,f_e0;
	/*e4*/int f_e4,f_e8;
};

//G_DRV
struct t_f0 {//size 0xf0
	/*00*/int (*f_00)(struct t_aa0 *);//Start
	/*04*/void (*f_04)(struct t_aa0 *);//Stop
	/*08*/int (*f_08)(int);//Lock
	/*0c*/int (*f_0c)(int);//Unlock
	/*10*/void (*f_10)(struct t_aa0 *);//Flip
	/*14*/void (*f_14)(int, int, int, struct t_aa0 *);//Clear
	/*18*/void (*f_18)(struct t_aa0 *);//ClearAll
	/*1c*/void (*f_1c)(int, int, int, int, struct t_aa0 *);//Viewport
	/*20*/void (*f_20)(struct fBGRA *, struct t_aa0 *);//ClearColor
	/*24*/int f_24;
	/*28*/struct fBGRA f_28;
	/*38*/tRGBA f_38;
	/*3c*/char __3c[4];
	/*40*/int (*f_40)(struct tPolygonInfo *);//PolyAllocMemory
	/*44*/int (*f_44)(int, struct tMatrixInfo *, struct tRenderState *, struct t_g_drv_GroupInfo *, struct tPolygonData *, struct tPolygonInfo *, struct t_aa0 *);//PolyLoad
	/*48*/void (*f_48)(int, LPD3DMATRIX, struct tMatrixInfo *, struct t_aa0 *);//SetMatrix
	/*4c*/void (*f_4c)(struct tTextureObj *);//ReleaseTexture
	/*50*/struct tTextureObj *(*f_50)(struct tTextureObj *,  struct tTexHeader *, struct tTextureInfo *);//CreateTexture
	/*54*/int (*f_54)(int, int, int, struct tPalette *, struct tTextureObj *);//PaletteChanged
	/*58*/int (*f_58)(int, int, tRGBA *, int, struct tPalette *, struct tTextureObj *);//PaletteSetData
	/*5c*/struct tBlendMode *(*f_5c)(int, struct t_aa0 *);
	/*60*/void (*f_60)(struct tPolygonInfo *, struct t_light_5ac *);//PolyApplyLight
	/*64*/void (*f_64)(int, int, struct t_aa0 *);
	/*68*/void (*f_68)(struct tRenderState *, struct t_aa0 *);//SetRenderState
	/*6c*/void (*f_6c)(struct tRenderState *, struct t_aa0 *);//SetRenderState[b]
	/*70*/void (*f_70)(struct tRenderState *, struct t_aa0 *);//SetRenderState[c]
	/*74*/void (*f_74)(int, struct t_aa0 *);//SetBlendMode
	/*78*/void (*f_78)(struct tPolygonInfo *, struct t_aa0 *);
	/*7c*/void (*f_7c)(struct tTransparentElement *, struct t_aa0 *);//RenderTransparent
	/*80*/void (*f_80)(struct t_dx_sfx_e0 *, struct t_aa0 *);
	/*84*/void (*f_84)(int, struct t_aa0 *);
	/*88*/int (*f_88)(int, struct t_aa0 *);//BeginScene
	/*8c*/void (*f_8c)(struct t_aa0 *);//EndScene
	/*90*/void (*f_90)(int, int);//callback for "sort"
	/*94*/void (*f_94)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//state(polygon type 0/8)
	/*98*/void (*f_98)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//state(polygon type 2/0xa)
	/*9c*/void (*f_9c)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//state(polygon type 4/6/0xc/0xe/0x11)[ter]
	/*a0*/void (*f_a0)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//state(polygon type 4/6/0xc/0xe/0x11)
	/*a4*/void (*f_a4)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//state(polygon type 4/6/0xc/0xe/0x11)[bis]
	/*a8*/void (*f_a8)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//render(polygon type 0/8)
	/*ac*/void (*f_ac)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//render(polygon type 2/0xa)
	/*b0*/void (*f_b0)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//render(polygon type 4/6/0xc/0xe/0x11)[ter]
	/*b4*/void (*f_b4)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//render(polygon type 4/6/0xc/0xe/0x11)
	/*b8*/void (*f_b8)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//state(polygon type 1/9)
	/*bc*/void (*f_bc)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//state(polygon type 3/0xb)
	/*c0*/void (*f_c0)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//state(polygon type 5/7/0xd/0xf)[ter]
	/*c4*/void (*f_c4)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//state(polygon type 5/7/0xd/0xf)
	/*c8*/void (*f_c8)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//state(polygon type 5/7/0xd/0xf)[bis]
	/*cc*/void (*f_cc)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//render(polygon type 1/9)
	/*d0*/void (*f_d0)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//render(polygon type 3/0xb)
	/*d4*/void (*f_d4)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//render(polygon type 5/7/0xd/0xf)[ter]
	/*d8*/void (*f_d8)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//render(polygon type 5/7/0xd/0xf)
	/*dc*/void (*f_dc)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//state(polygon type 0x12)
	/*e0*/void (*f_e0)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//state(polygon type 0x13)
	/*e4*/void (*f_e4)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//render(polygon type 0x12)
	/*e8*/void (*f_e8)(struct tPolygonInfo *, struct tIndexedVertices *, struct t_aa0 *);//render(polygon type 0x13)
	/*ec*/void (*f_ec)(struct t_aa0 *);
};

struct t_dx_rendi_e4 {//size 0xe4
	/*00*/unsigned char f_00[32];//rendering states flags?
	/*20*/int dwBlendMode;
	/*24*/int dwGouraud;
	/*28*/struct tTextureObj *f_28;
	/*2c*/struct tPolygonInfo *f_2c[0x16];
	/*84*/struct tPolygonInfo *f_84[0x16];
	/*dc*/struct tRenderState *f_dc;//flat material
	/*e0*/struct tRenderState *f_e0;//gouraud material
};

struct t_extdll_24 {//size 0x24
	/*00*/int f_00;
	/*04*/const char *f_04;
	/*08*/const char *f_08;
	/*0c*/int f_0c;
	/*10*/int f_10;
	/*14*/struct t_gl_code_450 *f_14;
	/*18*/int f_18;
	/*1c*/HMODULE f_1c;
	/*20*/FARPROC f_20;
};

struct tMainCallbacks {//size 0x1c
	/*00*/int (*f_00)(struct t_aa0 *);//main init?
	/*04*/void (*f_04)(struct t_aa0 *);//main cleanup?
	//
	/*08*/void (*f_08)(struct t_aa0 *);//begin/start
	/*0c*/void (*f_0c)(struct t_aa0 *);//end/stop
	/*10*/void (*f_10)(struct t_aa0 *);//update/refresh
	/*14*/void (*f_14)(int, int, int, struct t_aa0 *);//on mouse
	/*18*/void (*f_18)(int, int, int, struct t_aa0 *);//on key
};

//unused feature
struct t_drv_14 {//size 0x14
	/*00*/int f_00;//dwActive
	/*04*/int f_04;//dwX
	/*08*/int f_08;//dwY
	/*0c*/int f_0c;//dwWidth
	/*10*/int f_10;//dwHeight
};

#pragma pack(1)
struct t_global_fc {//size 0xfc
	/*00*/int f_00;
	//
	/*04*/int f_04;//P
	/*08*/int f_08;//V
	/*0c*/int f_0c;//G
	/*10*/int f_10;//S2
	/*14*/int f_14;//S3
	/*18*/int f_18;//M3 divisor
	/*1c*/int f_1c;//M43 divisor
	/*20*/int f_20;//M4 divisor
	/*24*/int f_24;//MR divisor
	/*28*/int f_28;//MS divisor
	/*2c*/int f_2c;
	/*30*/int f_30;
	/*34*/int f_34;
	/*38*/int f_38;
	/*3c*/int f_3c;
	/*40*/int f_40;
	/*44*/int f_44;
	/*48*/int f_48;
	/*4c*/int f_4c;
	/*50*/LARGE_INTEGER f_50;//M3 related
	/*58*/LARGE_INTEGER f_58;//M43 related
	/*60*/LARGE_INTEGER f_60;//M4 related
	/*68*/LARGE_INTEGER f_68;//MR related
	/*70*/LARGE_INTEGER f_70;//MS related
	/*78*/LARGE_INTEGER f_78;//C
	/*80*/LARGE_INTEGER f_80;//E
	/*88*/LARGE_INTEGER f_88;//RL
	/*90*/LARGE_INTEGER f_90;//P
	/*98*/LARGE_INTEGER f_98;//GDI
	/*a0*/LARGE_INTEGER f_a0;
	/*a8*/LARGE_INTEGER f_a8;
	/*b0*/LARGE_INTEGER f_b0;
	/*b8*/LARGE_INTEGER f_b8;
	/*c0*/LARGE_INTEGER f_c0;
	/*c8*/char __c8[8];
	/*d0*/LARGE_INTEGER f_d0;
	/*d8*/LARGE_INTEGER f_d8;
	/*e0*/LARGE_INTEGER f_e0;
	/*e8*/LARGE_INTEGER f_e8;
	/*f0*/int f_f0;
	/*f4*/LARGE_INTEGER f_f4;
};
#pragma pack()

struct t_0067DED0_8 {//size 8
	/*00*/int f_00;//dwFlags?
	/*04*/int f_04;//more flags
};

struct t_aa0 {//size 0xaa0
	/*000*/int f_000;//"Stop main loop" flag?
	/*004*/int f_004;//HORZRES
	/*008*/int f_008;//VERTRES
	/*00c*/int f_00c;//BITSPIXEL
	/*010*/int f_010,f_014,f_018,f_01c;//window client area info
	/*020*/int f_020;//window is minimized?
	/*024*/char __024[4];
	/*028*/double f_028;//# of frames?
	/*030*/double f_030;//CPU cycles per second?
	/*038*/LARGE_INTEGER f_038;
	/*040*/double f_040;//# of rendered frames[current]?
	/*048*/double f_048;//# of rendered frames[previous]?
	/*050*/LARGE_INTEGER f_050;
	/*058*/HINSTANCE f_058;
	/*05c*/HWND f_05c;
	/*060*/int f_060;//nCmd
	/*064*/int f_064;
	/*068*/struct t_list_List *f_068;//DirectDrawEnumerate result
	/*06c*/int f_06c;//# of display modes
	/*070*/int f_070;//# of "DISPLAY MODE MATCH"
	/*074*/LPDIRECTDRAW f_074;
	/*078*/LPDIRECTDRAW2 f_078;
	/*07c*/LPDIRECTDRAWSURFACE f_07c[3];
	/*088*/DDSURFACEDESC f_088[3];//size 0x6c
	/*1cc*/LPDIRECTDRAWSURFACE f_1cc;
	/*1d0*/LPUNKNOWN f_1d0;
	/*1d4*/LPDIRECTDRAWCLIPPER f_1d4;
	/*1d8*/int f_1d8;
	/*1dc*/DDSURFACEDESC f_1dc;//size 0x6c
	/*248*/LPDIRECTDRAW f_248;
	/*24c*/int f_24c;
	/*250*/DDSURFACEDESC f_250;//size 0x6c
	/*2bc*/struct t_list_List *f_2bc;//Direct3D::EnumDevices result
	/*2c0*/LPDIRECT3D f_2c0;
	/*2c4*/LPDIRECT3DDEVICE f_2c4;
	/*2c8*/struct t_list_List *f_2c8;//Direct3DDevice::EnumTextureFormats result
	/*2cc*/struct t_directx_20 *f_2cc;
	/*2d0*/LPDIRECT3DVIEWPORT f_2d0;
	/*2d4*/LPDIRECT3DMATERIAL f_2d4;
	/*2d8*/char __2d8[4];
	/*2dc*/LPDIRECT3D2 f_2dc;
	/*2e0*/LPDIRECT3DDEVICE2 f_2e0;
	/*2e4*/LPDIRECT3DVIEWPORT2 f_2e4;
	/*2e8*/struct t_list_List *f_2e8;//[unused?]a list of polygon for rendering
	/*2ec*/struct tPolygonInfo *f_2ec;//[renderState/matrux only?]plain/solid layer
	/*2f0*/struct tPolygonInfo *f_2f0;//[renderState only?]transparent layer
	/*2f4*/struct tStack *f_2f4;
	/*2f8*/struct tStack *f_2f8;
	/*2fc*/LPD3DMATRIX f_2fc;
	/*300*/struct t_instance_8 *f_300;
	//-- HAL triangle/line caps --
	/*304*/struct t_0067DED0_8 f_304,f_30c;
	//-- HEL triangle/line caps --
	/*314*/struct t_0067DED0_8 f_314,f_31c;
	//-- --
	/*324*/D3DDEVICEDESC f_324;//size 0xcc
	/*3f0*/D3DDEVICEDESC f_3f0;//size 0xcc
	/*4bc*/DDCAPS f_4bc;//direct draw driver caps[size 0x16c(should be DDCAPS_DX5)]
	/*628*/DDCAPS f_628;//emulation driver caps[size 0x16c(should be DDCAPS_DX5)]
	/*794*/struct t_global_fc *f_794;
	/*798*/struct t_global_fc *f_798;
	/*79c*/struct tTextureInfo f_79c;//"locked" surface?
	/*81c*/int f_81c;//"begin scene" flag
	/*820*/struct tRenderState *f_820[5];//render states?
	//-- log related --
	/*834*/int f_834;
	/*838*/int f_838;
	/*83c*/struct t_dx_dbg_14 *f_83c;
	//-- --
	/*840*/int f_840,f_844;//pointer x,y
	//viewport
	/*848*/int f_848,f_84c,f_850,f_854;//viewport x,y,width,height
	/*858*/int f_858;
	/*85c*/int f_85c;
	//
	/*860*/int f_860;//vertical "stretch" info(not used if 0)?
	/*864*/int f_864;//some (almost) unused debug flag?
	/*868*/struct t_drv_14 f_868[2];
	/*890*/D3DMATRIX f_890;//a matrix
	/*8d0*/D3DMATRIX f_8d0;//a matrix[transpose of f_890?]
	/*910*/struct t_dx_sfx_70 *f_910;
	/*914*/struct t_registry_04 *f_914;
	/*918*/struct tStack *f_918;
	//-- --
	/*91c*/int f_91c;//"dx_3d2d" related flag[always 0?]
	/*920*/struct t_dx_3d2d_28 *f_920;
	//-- --
	/*924*/int f_924;//"has new callbacks" flag
	/*928*/int f_928;//current rendering "layer"?
	/*92c*/int f_92c;//shade model related?
	/*930*/struct t_54a74 *f_930;
	/*934*/struct t_f0 *f_934;//gfx driver
	/*938*/struct tTransparentHeap *f_938;
	/*93c*/int f_93c;//flag related to f_940?
	/*940*/struct tRenderState *f_940;
	/*944*/struct t_dx_rendi_e4 *f_944;
	/*948*/int f_948;//flag "caps"?
	/*94c*/int f_94c;//flag "alpha"?
	/*950*/int f_950;
	/*954*/int f_954;//screen width?
	/*958*/int f_958;//screen height?
	/*95c*/int f_95c;//requested bits per pixel
	/*960*/int f_960;//# of surfaces?
	/*964*/int f_964;//flag "full"?
	/*968*/int f_968;//flag "p/np"?
	/*96c*/int f_96c;//flag "sys"?
	/*970*/int f_970;
	/*974*/int f_974;
	/*978*/int f_978;
	/*97c*/int f_97c;
	/*980*/char __980[4];
	/*984*/int f_984;//flag "d3d2"
	/*988*/int f_988;//flag "sw/hw"?
	/*98c*/int f_98c;//flag related to "dwDeviceZBufferBitDepth"
	/*990*/int f_990;
	/*994*/int f_994;
	/*998*/int f_998;
	//-- viewport/projection related --
	/*99c*/float f_99c;//field of view
	/*9a0*/float f_9a0;//clipping near
	/*9a4*/float f_9a4;//clipping far
	/*9a8*/float f_9a8;//x
	/*9ac*/float f_9ac;//y
	//-- --
	/*9b0*/int f_9b0;//random seed?
	/*9b4*/char *f_9b4;//windows name?
	/*9b8*/char *f_9b8;//windows class name?
	/*9bc*/int f_9bc;
	/*9c0*/WNDCLASS f_9c0;
	/*9e8*/int f_9e8;
	/*9ec*/int f_9ec;
	/*9f0*/struct tMainCallbacks f_9f0;
	/*a0c*/struct tMainCallbacks f_a0c;
	/*a28*/void (*f_a28)(int , struct t_aa0 *);//on WM_ACTIVATEAPP
	/*a2c*/void (*f_a2c)(int, int, struct t_aa0 *);//on WM_DEVICECHANGE
	/*a30*/int f_a30;
	/*a34*/int *f_a34;//r
	/*a38*/int *f_a38;//g
	/*a3c*/int *f_a3c;//b
	/*a40*/char __a40[4];
	/*a44*/struct t_SW_TriangleStack *f_a44;
	/*a48*/int f_a48;//"flip on" flag?
	/*a4c*/char __a4c[8];
	//
	/*a54*/int f_a54;//exit box is on?
	/*a58*/void (*f_a58)(struct t_aa0 *);//exit box callback
	/*a5c*/int (*f_a5c)(struct t_aa0 *);//on <CTRL+Q> callback
	//
	/*a60*/int f_a60;//current_gfx_driver
	/*a64*/char *f_a64;
	/*a68*/struct t_extdll_24 f_a68;
	/*a8c*/struct t_dll_gfx_externals *f_a8c;
	/*a90*/int f_a90;//"nvidia_fix"
	/*a94*/int f_a94;//"tnt_fix"(patch vertex {u,v})
	/*a98*/int f_a98;
	/*a9c*/char __a9c[4];
};

//====---- from list.cpp ----====
struct t_list_Node {//size 8
	/*00*/struct t_list_Node *pNext;
	/*04*/void *pData;
};

struct t_list_List {//size 0x20
	/*00*/int f_00;//allocation type
	/*04*/int f_04;
	/*08*/int dwCount;
	/*0c*/struct t_list_Node *pHead;
	/*10*/struct t_list_Node *pTail;
	/*14*/void (*f_14)(void *);//free element content
	/*18*/int (*f_18)(void *, void **);
	/*1c*/char __1c[4];//padding?
};

//====---- from dx_dbg.cpp ----====
struct t_dx_dbg_14 {//size 0x14
	/*00*/int f_00;
	/*04*/int f_04;//flag:use "OutputDebugString"
	/*08*/int f_08;//flag:open file for each call
	/*0c*/const char *f_0c;
	/*10*/FILE *f_10;
};

//====---- from heap.cpp ----====
typedef enum {HEAP_0, HEAP_1, HEAP_2} tHeapPageType;

struct t_heap_3c {//size 0x3c
	/*00*/struct t_heap_3c *pNext;
	//
	/*04*/int f_04;//some level info?
	/*08*/int f_08;
	/*0c*/int f_0c;//heap size?
	/*10*/unsigned char *f_10;//32 bytes aligned memory[base]
	/*14*/unsigned char *f_14;//block memory[unaligned]
	/*18*/int f_18;//page size
	/*1c*/int f_1c;
	/*20*/int f_20;//# pages
	/*24*/unsigned char *f_24;//32 bytes aligned memory[current]
	/*28*/tHeapPageType f_28;//paging type/page info size?
	/*2c*/int f_2c;//remaining pages?
	/*30*/void *f_30;//page info?
	/*34*/int f_34;//???
	/*38*/void (*f_38)(int, struct t_heap_3c *);
};

//====---- from file.cpp ----====
//more like a registry entry
struct t_file_20_bis {//size 0x20
	/*00*/int f_00;
	/*04*/char *pFileName;
	/*08*/char *pDirectory;
	//
	/*0c*/char __0c[4];//padding?
	/*10*/struct {
		/*00*/int dwReferenceCounter;
		/*04*/void *pPointer;
	} f_10[2];//2 = # of registries
};

#define ARCHIVE_00 0
#define ARCHIVE_01 1
#define ARCHIVE_02 2
#define ARCHIVE_03 3
#define ARCHIVE_04 4
#define ARCHIVE_05 5
#define ARCHIVE_06 6
#define ARCHIVE_07 7
#define ARCHIVE_08 8
#define ARCHIVE_09 9
#define ARCHIVE_0A 0xa
#define ARCHIVE_0B 0xb
//#define ARCHIVE_0C 0xc
//#define ARCHIVE_0D 0xd
#define ARCHIVE_0E 0xe
#define ARCHIVE_0F 0xf
#define ARCHIVE_10 0x10
#define ARCHIVE_11 0x11

//file locator
struct t_file_10 {//size 0x10
	/*00*/int f_00;//file access?
	/*04*/int dwUseArchive;
	/*08*/int dwArchiveId;
	/*0c*/void (*f_0c)(const char *, char *);
};

//file object
struct t_file_18 {//size 0x18
	/*00*/const char *f_00;//file name
	/*04*/int f_04;//file handle/archive offset?
	/*08*/struct t_file_10 f_08;
};

//====---- from dx_graph.cpp ----====
struct t_dx_graph_18 {//size 0x18
	/*00*/int f_00;//use palette
	/*04*/int f_04;//dwRGBBitCount
	/*08*/int f_08;//dwRBitMask
	/*0c*/int f_0c;//dwGBitMask
	/*10*/int f_10;//dwBBitMask
	/*14*/int f_14;//dwRGBAlphaBitMask
};

//====---- from dx_pal.cpp ----====
struct tPalette {//size 0x40
	/*00*/int f_00;//flags
	/*04*/int f_04;//palette_size
	/*08*/int f_08;//bits_per_pixel
	/*0c*/int dwPaletteCount;
	/*10*/int f_10;//colors_per_palette
	/*14*/int f_14;//flag:free f_18 on destroy
	/*18*/tRGBA *f_18;//unsigned char *?
	/*1c*/int f_1c;
	/*20*/unsigned char *f_20;
	/*24*/struct fBGRA *f_24;
	/*28*/tRGBA *f_28;
	/*2c*/PALETTEENTRY *f_2c;
	/*30*/LPDIRECTDRAWPALETTE f_30;//direct3d object?
	/*34*/int *f_34;
	/*38*/int *f_38;//half_color_palette?
	/*3c*/struct t_gl_code_14 *f_3c;//[used by gl only, attemped freed by dx_pal]
};
//====---- from stack.cpp ----====
struct tStack {//size 0xc
	/*00*/int f_00;//max size?
	/*04*/int f_04;//current index?
	/*08*/void **f_08;
};

//====---- from registry.cpp ----====
struct t_registry_04 {//size 4
	/*00*/struct t_list_List *f_00;
};

//====---- from input.cpp ----====
struct t_input_58 {//size 0x58
	/*00*/int f_00;//xpos
	/*04*/int f_04;//ypos
	/*08*/int f_08;//"UP"
	/*0c*/int f_0c;//"DOWN"
	/*10*/int f_10;//"LEFT"
	/*14*/int f_14;//"RIGHT"
	/*18*/int f_18;//JOY_BUTTON1
	/*1c*/int f_1c;//"BUTTON 2"
	/*20*/int f_20;//JOY_BUTTON3
	/*24*/int f_24;//"BUTTON 4"
	/*28*/int f_28;//"BUTTON 5"
	/*2c*/int f_2c;//"BUTTON 6"
	/*30*/int f_30;//"BUTTON 7"
	/*34*/int f_34;//"BUTTON 8"
	/*38*/int f_38;//"BUTTON 9"
	/*3c*/int f_3c;//"BUTTON 10"
	/*40*/int f_40;//JOY_BUTTON11
	/*44*/int f_44;//JOY_BUTTON12
	/*48*/int f_48;//JOY_BUTTON13
	/*4c*/int f_4c;//JOY_BUTTON14
	/*50*/int f_50;//JOY_BUTTON15
	/*54*/int f_54;//JOY_BUTTON16
};

//===--- ---===
struct t_plytopd_74 {//size 0x74
	/*00*/int f_00;
	/*04*/struct t_g_drv_0c sPos;
	/*10*/struct t_g_drv_0c sRot;
	/*1c*/struct t_g_drv_0c sScale;
	/*28*/float fScale;
	/*2c*/D3DMATRIX f_2c;
	/*6c*/struct t_g_drv_0c *f_6c;//struct t_local_anm_0c *
	/*70*/LPD3DMATRIX f_70;
};

#pragma pack(1)
struct t_plytopd_e4 {//size 0xe4
	/*00*/int f_00;
	/*04*/int f_04;
	/*08*/int f_08;//max animation frames?
	/*0c*/int f_0c;
	/*10*/int f_10;
	/*14*/int f_14;
	/*18*/int f_18;
	/*1c*/int f_1c;
	/*20*/int f_20;
	/*24*/int f_24;
	/*28*/int f_28;
	/*2c*/int f_2c;//dwFPS?
	/*30*/float f_30;
	/*34*/struct t_animationHeader *f_34;
	/*38*/struct t_plytopd_74 f_38;
	/*ac*/int f_ac;//animation index?
	/*b0*/struct t_local_plytopd_24 *f_b0;
	/*b4*/struct tSkeleton *f_b4;
	/*b8*/struct t_aa0 *f_b8;
	/*bc*/LARGE_INTEGER f_bc;//CPU cycles per animation frame?
	/*c4*/LARGE_INTEGER f_c4;//next frame timestamp?
	/*cc*/char __cc[4];
	/*d4*/int (*f_d0)(struct t_plytopd_e4 *);
	/*d4*/struct t_file_10 f_d4;
};
#pragma pack()

struct t_plytopd_08_bis {//size 8
	/*00*/char __00[4];
	/*04*/struct t_rsd_0c *f_04;
};

struct tBone {//size 0x1c
	/*00*/char *pbName;
	/*04*/char *pbParentName;
	/*08*/int dwParentIndex;
	/*0c*/float fLength;
	/*10*/int dwRSDCount;
	/*14*/char **ppbRSDName;
	/*18*/struct t_plytopd_08_bis *f_18;//RSD file
};

struct t_plytopd_18 {//size 0x18
	/*00*/float f_RX,f_RY,f_RZ;//Rotation?
	/*0c*/float f_TX,f_TY,f_TZ;//Translation?
};

struct t_plytopd_dunno {//size 0x1c?
	/*00*/int dwActive;
	/*04*/struct t_plytopd_18 f_04;
};

struct tSkeleton {//size 0xa8
	/*00*/int f_00;
	/*04*/int f_04;
	/*08*/int dwDebugMode;
	/*0c*/int dwRSDFlags;
	/*10*/int dwBoneCount;
	/*14*/struct tBone *pBone;
	/*18*/int dwRootChildCount;
	/*1c*/struct t_list_List *f_1c;
	/*20*/struct t_aa0 *f_20;
	/*24*/D3DMATRIX f_24;
	/*64*/D3DMATRIX f_64;
	/*a4*/struct t_plytopd_dunno *f_a4;
};

//"RSD"
struct t_plytopd_RSD {//size 0x24
	/*00*/char *p_PLY;//PLY file name
	/*04*/char *p_MAT;//MAT file name
	/*08*/char *p_GRP;//GRP file name
	/*0c*/int dw_NTEX;//# of textures
	/*10*/char **ppb_TEX;//TIM files names
	/*14*/struct t_tim_info **f_14;
	/*18*/struct tTexHeader **f_18;
	/*1c*/int f_1c;//# of elements in f_20
	/*20*/struct tPolygonData **f_20;
};

//animation frame
struct t_plytopd_8 {//size 8
	/*00*/struct t_plytopd_18 *f_00;//"root_coordinate"
	/*04*/struct t_g_drv_0c *f_04;//channel list
};

/*".A" file structure:

	+--------------------------+
	| struct t_animationHeader |
	+--------------------------+

	                                        header.dwFrameCount times
	+---------------------+ +---------------------+   ...   +---------------------+
	| struct t_plytopd_18 | | struct t_plytopd_18 |   ...   | struct t_plytopd_18 |
	+---------------------+ +---------------------+   ...   +---------------------+
	| struct t_g_drv_0c   | | struct t_g_drv_0c   |   ...   | struct t_g_drv_0c   |
	| ...                 | | ...                 |   ...   | ...                 | header.dwChannelCount times
	| struct t_g_drv_0c   | | struct t_g_drv_0c   |   ...   | struct t_g_drv_0c   |
	+---------------------+ +---------------------+   ...   +---------------------+
*/

struct t_animationHeader {//size 0x24
	/*00*/int dwVersion;//(must be 1)
	/*04*/int dwFrameCount;//num of objects in f_14?[FRAMES]
	/*08*/int dwChannelCount;//max animation frame?[CHANNELS]
	/*0c*/int f_0c;//flags?[ROTATION_ORDER]
	/*10*/void *f_10;//content buffer
	/*14*/struct t_plytopd_8 *f_14;//frame list
	/*18*/int f_18;
	/*1c*/LPD3DMATRIX f_1c;
	/*20*/LPD3DMATRIX f_20;
};

//====---- from rsd.cpp ----====
struct t_rsd_0c {//size 0xc
	/*00*/struct tMatrixInfo *f_00;
	/*04*/struct tPolygonInfo *f_04;
	/*08*/struct t_plytopd_RSD *f_08;
};

struct tInfoListOfRSD {//size 0x10
	/*00*/int f_00;
	/*04*/int f_04;
	/*08*/int f_08;//# of objects?
	/*0c*/const char **f_0c;
};

struct tListOfRSD {//size 8
	/*00*/int f_00;
	/*04*/struct t_rsd_0c **f_04;
};

struct t_rsd_08 {//TODO is this struct bigger?
	/*00*/int f_00;
	/*04*/int dwBlendMode;
};

#define RSD_00000001 0x00000001
#define RSD_00000002 0x00000002
#define RSD_00000004 0x00000004
//0x00000008
#define RSD_00000010 0x00000010
#define RSD_00000020 0x00000020
//0x00000040
//0x00000080
//0x00000100
#define RSD_00000200 0x00000200
#define RSD_00000400 0x00000400
#define RSD_00000800 0x00000800
//0x00001000
#define RSD_00002000 0x00002000
#define RSD_00004000 0x00004000
//0x00008000
//0x00010000
#define RSD_00020000 0x00020000
//0x00040000
//0x00080000
#define RSD_00100000 0x00100000
#define RSD_00200000 0x00200000
//0x00400000
//0x00800000
//0x01000000
#define RSD_02000000 0x02000000
//0x04000000
#define RSD_08000000 0x08000000
#define RSD_10000000 0x10000000
#define RSD_20000000 0x20000000

struct t_rsd_74 {//size 0x74
	/*00*/int dwRSDFlags;
	/*04*/int f_04;
	/*08*/int dwUsePSXResources;
	/*0c*/int f_0c;
	/*10*/int f_10;//some matrix attribute(0:none,1:???,2:???)?
	/*14*/int f_14;//some matrix count?
	/*18*/struct t_instance_8 *f_18;
	/*1c*/struct t_rsd_08 f_1c;
	/*24*/const char *f_24;
	/*28*/struct tTexHeader *f_28;
	/*2c*/int f_2c;//flags:copied to "struct t_dx_sfx_e0::f_34"
	/*30*/struct t_light_5ac *f_30;//void *
	/*34*/int f_34;
	/*38*/float f_38;//fScaling?for skeleton
	/*3c*/int f_3c;
	/*40*/struct t_file_10 f_40;
	/*50*/int f_50;
	/*54*/tRGBA f_54;
	/*58*/int f_58;
	/*5c*/int dwCurrentPaletteIndex;
	/*60*/char __60[0x10];
	/*70*/int f_70;//property mask(copied to "struct tPolygonInfo::dwSWRenderFlags")
};

#define t_rsd_74_init(obj,f) (obj).dwRSDFlags = (f); memset(&((obj).f_04), 0, sizeof(struct t_rsd_74) - 4);

//====---- from token.cpp ----====
struct t_token_14 {//size 0x14
	/*00*/int dwTokenCount;
	/*04*/char **ppToken;
	/*08*/int dwLength;
	/*0c*/char *pText;
	/*10*/void (*f_10)(int, char*);//tokenizer function?
};

//====---- from C_00666AB0.cpp ----====
struct t_dll_gfx_externals {//size 0x90
	void (*f_00)(void *, const char *, int);//mem:free
	void *(*f_04)(int, const char *, int);//mem:malloc
	void *(*f_08)(int, int, const char *, int);//mem:calloc
	struct tD3DTextureInfo *(*f_0c)(void);//graphicx.directx:alloc "struct tD3DTextureInfo"
	void (*f_10)(struct tD3DTextureInfo *, struct t_aa0 *);//graphicx.directx:add "struct tD3DTextureInfo" to list
	struct t_aa0 *(*f_14)(void);//graphicx.directx:get some game object?
	void (*f_18)(struct t_f0 *);//graphics.driver:release "struct t_f0 *"
	struct t_f0 *(*f_1c)(void);//graphics.driver:alloc "struct t_f0 *"
	void (*f_20)(int, int, int, int, int, struct tTextureInfo *);//dx_graph:init "struct tTextureInfo *"
	void (*f_24)(struct t_dx_graph_18 *, struct tTextureInfo *);//dx_graph:init "struct tTextureInfo *"[2]
	int (*f_28)(unsigned, unsigned, unsigned);//dx_graph:...
	int (*f_2c)(tRGBA, struct tTextureInfo *);//dx_graph:RGBA to palette?
	int (*f_30)(int *, int *, int *, tRGBA);//dx_graph:...
	int (*f_34)(tRGBA bp08, struct t_aa0 *bp0c);//dx_graph:...
	tRGBA (*f_38)(unsigned bp08, struct tTextureInfo *);//dx_graph:...
	tRGBA (*f_3c)(unsigned, int, struct tTextureInfo *);//dx_graph:...
	void (*f_40)(struct tTextureObj *);//dx_graph:TextureCleanPalette
	struct tPalette *(*f_44)(int, struct tTexHeader *, struct tTextureObj *);//dx_graph:TextureCreatePalette
	void (*f_48)(struct tTexHeader *, struct tTextureInfo *, void *);//dx_graph:texture conversion?
	void (*f_4c)(struct tTextureObj *);//dx_graph:registry.ReleaseTexture
	struct tTextureObj *(*f_50)(void);//dx_graph:allocate "struct tTextureObj"
	void (*f_54)(int, int, tRGBA *, int, PALETTEENTRY *);//dx_pal:palette copy(1)
	void (*f_58)(int, int, tRGBA *, int, struct fBGRA *);//dx_pal:palette copy(2)
	void (*f_5c)(int, int, tRGBA *, int, int *);//dx_pal:palette copy(3)
	void (*f_60)(int, int, int, int *, tRGBA *, int *);//dx_pal:palette copy(4)
	void (*f_64)(struct tPalette *);//dx_pal:clean "struct tPalette *"
	struct tPalette *(*f_68)(int, int, int, int, tRGBA *);//dx_pal:create "struct tPalette *"
	int (*f_6c)(int, int, tRGBA *, int, struct tPalette *, struct tTextureObj *);//G_DRV_58:PaletteSetData
	int (*f_70)(int, struct tTextureObj *);//G_DRV_54:TextureSetPalette
	void (*f_74)(int, struct tPalette *);//palette related 0
	void (*f_78)(float, int, struct tPalette *);//palette related 1
	void (*f_7c)(float, float, struct fBGRA *, int, struct tPalette *);//palette related 2
	void (*f_80)(struct fBGRA *, int, struct tPalette *);//palette related 3
	struct tTransparentElement *(*f_84)(struct tTransparentHeap *);//dx_rend:heap alloc
	int (*f_88)(int, struct tMatrixInfo *, struct tRenderState *, struct t_g_drv_GroupInfo *, struct tPolygonData *, struct tPolygonInfo *, struct t_aa0 *);//[option]GRAPHIC_0_44:PolyLoad
	void (*f_8c)(struct tPolygonInfo *, struct t_light_5ac *);//GRAPHIC_0_60:PolyApplyLight
};
//====---- from direct.cpp ----====
//seems to be a 32 char-long string
struct t_direct_20 {//size 0x20
	/*00*/char __00[0x20];
};

struct t_direct_FileList {//size 8
	/*00*/int dwCount;
	/*04*/struct t_direct_20 *f_04;
};
//====---- ----====
struct t_script_20 {//size 0x20
	/*00*/char __00[2];//always 0x02 0x05?
	/*02*/unsigned char f_02;//# of entities?
	/*03*/unsigned char f_03;//# of models?
	/*04*/unsigned short f_04;//offset to strings
	/*06*/unsigned short f_06;//# of AKAO offsets?
	/*08*/short f_08;//scale
	/*0a*/char __0a[6];
	/*10*/char __10[8];//creator name?
	/*18*/char __18[8];//field name?
//	followed by "unsigned char" data ?
};

struct t_script_DialogInfo_30 {//size 0x30
	/*00*/void *pText;//0CFF5B8
	/*04*/short wDialogX,wDialogY;//0CFF5BC,0CFF5BE
	/*08*/short wDialogWidth,wDialogHeight;//0CFF5C0,0CFF5C2
	/*0c*/short wDialogCurWidth,wDialogCurHeight;//0CFF5C4,0CFF5C6
	/*10*/short wRelTextY;//0CFF5C8
	/*12*/short wCharCount;//0CFF5CA
	/*14*/short wDispTextLen;//0CFF5CC
	/*16*/short wDispCRCount;//0CFF5CE
	/*18*/unsigned char f_18;//0CFF5D0
	/*19*//*unsigned */char cAttr;//1:no bg/2:bg transparent/4:unused?//0CFF5D1
	/*1a*//*unsigned */char cDisplayHand;//0CFF5D2
	/*1b*//*unsigned */char cDisplayCount;//0CFF5D3
	/*1c*//*unsigned */char f_1c;//0CFF5D4
	/*1d*//*unsigned */char f_1d;//0CFF5D5
	/*1e*/char __1e[2];
	/*20*/int dwCountValue;//0CFF5D8
	/*24*/short wRelHandX,wRelHandY;//0CFF5DC,0CFF5DE
	/*28*/short wRelCountX,wRelCountY;//0CFF5E0,0CFF5E2
	/*2c*/short wStatus;//0CFF5E4
	/*2e*/short f_2e;//0CFF5E6
};
//====---- ----====
struct t_swirl_118 {
	/*000*/int f_000;
	/*004*/struct t_rsd_0c *f_004;
	/*008*/int f_008;
	/*00c*/struct t_animationHeader *f_00c;
	/*010*/struct tSkeleton *f_010;
	/*014*/struct t_plytopd_74 f_014;
	/*088*/D3DMATRIX f_088;
	/*0c8*/int f_0c8;//color key on?alpha on?
	/*0cc*/int f_0cc;
	/*0d0*/int dwBlendMode;
	/*0d4*/struct t_instance_8 *f_0d4;
	/*0d8*/struct t_dx_sfx_70 *f_0d8;
	/*0dc*/int f_0dc;//some x?
	/*0e0*/int f_0e0;//some y?
	/*0e4*/int f_0e4;//some width?
	/*0e8*/int f_0e8;//some height?
	//-- offscreen render? --
	/*0ec*/int f_0ec;//view x?
	/*0f0*/int f_0f0;//view y?
	/*0f4*/int f_0f4;//viewport x?
	/*0f8*/int f_0f8;//viewport y?
	/*0fc*/int f_0fc;//viewport width?
	/*100*/int f_100;//viewport height?
	/*104*/int f_104;//scale info?
	//-- --
	/*108*/int f_108;//flag "sys"(tem memory)?
	/*10c*/int f_10c;//some x ratio?
	/*110*/int f_110;//some y ratio?
	/*114*/int f_114;//dwIndex
};

struct t_swirl_124 {
	/*00*/int dwState;
	/*04*/int dwIndex;
	/*08*/struct t_dx_sfx_e0 *f_08;
	/*0c*/struct t_swirl_118 f_0c;
};
//====---- ----====
struct t_shp_SPT_Header {//size 8
	/*00*/unsigned char bMagic;//0x23
	/*01*/unsigned char bVersion;//0x10 or 0x20
	/*02*/unsigned char __02[2];//padding
	/*04*/int f_04;//dwCount or dwFrameCount
};

struct t_shp_Frame_Info {//size 4
	/*00*/unsigned short __00;
	/*04*/unsigned short wCount;
};

struct t_shp_Sprite {//size 0x14
	/*00*/unsigned dwFlags;//attr(1:flipx,2:flipy,...)
	/*04*/short wX,wY;
	/*08*/short wTexX,wTexY;
	/*0c*/short tpage;
	/*0e*/short clut;
	/*10*/short wWidth,wHeight;
};

struct t_shp_08_bis {//size 8
	/*00*/struct t_shp_Frame_Info *pFrameInfo;
	/*04*/struct t_shp_Sprite *pSprites;
};

struct t_shp_30 {//size 0x30
	//-- same as struct t_shp_0c --
	/*00*/struct t_shp_SPT_Header *f_00;
	/*04*/struct t_shp_08_bis *f_04;
	/*08*/void *f_08;
	//-- --
	/*0c*/int f_0c;
	/*10*/int f_10[4];//array of tpage
	/*20*/struct t_dx_sfx_e0 *f_20[4];
};

struct t_render_for_combat_2c {//size 0x2c
	/*00*/int f_00;
	/*04*/int f_04;
	/*08*/int f_08;
	/*0c*/int f_0c;
	/*10*/int f_10;
	/*14*/int f_14;
	/*18*/int f_18;
	/*1c*/struct t_file_10 sLocator;
};

struct t_render_forcombat_0c {//size 0xc
	/*00*/int f_00;//goes to "struct t_render_24::f_10"
	/*04*/int f_04;//goes to "struct t_render_24::f_14"
	/*08*/const char *f_08;//path//goes to "struct t_render_24::f_04"
};

struct t_render_0c {//size 0xc
	/*00*/int f_00;
	union {
		//-- struct t_render_14::wFlag 0x800 on --
		struct {
			/*04*/struct t_dx_sfx_e0 *f_04;
			/*08*/struct t_shp_30 *f_08;
		}type_1;
		//-- struct t_render_14::wFlag 0x800 off --
		 struct {
			/*04*/struct t_rsd_0c *f_04;
			/*08*/struct tRenderState *f_08;
		}type_2;
		//-- --
	};
};

struct t_render_14 {//size 0x14
	/*00*/unsigned short wFlags;
	/*02*/unsigned short wScaling;
	/*04*/const char *f_04;
	/*08*/const char *f_08;
	/*0c*/unsigned f_0c;
	/*10*/char __10[4];
};

struct t_render_24 {//size 0x24
	/*00*/int dwCount;
	/*04*/const char *f_04;
	/*08*/struct t_render_14 *f_08;
	/*0c*/struct t_render_0c *f_0c;
	/*10*/int f_10;
	/*14*/int f_14;//some limit for f_1c?
	/*18*/int f_18,f_1c;//some frame counters?
	/*20*/struct t_render_24 **f_20;
};

struct t_render_local_2c {//size 0x2c
	/*00*/int f_00;
	/*04*/int dwCount;
	/*08*/struct t_render_24 **f_08;
	/*0c*/int f_0c;
	/*10*/int *f_10;
	/*14*/struct t_dx_sfx_70 *f_14;
	/*18*/struct t_instance_8 *f_18;
	/*1c*/struct t_file_10 sLocator;
};
//====---- ----====
struct t_ad_bk_AxisShakeInfo {//size 0xe
	/*00*/char bActive;
	/*01*/char bInitialized;
	/*02*/char bRandomIndex;
	/*03*/char bOffset;
	/*04*/short wPower;
	/*06*/short wStart;
	/*08*/short wEnd;
	/*0a*/short wLength;
	/*0c*/short wPhase;
};

struct t_main_infos {//size 0x132?
	/*00*/char f_00;//0CC0D88
	/*01*/char bEventType;//0CC0D89
	/*02*/short wEventParam;//0CC0D8A
	/*04*/short f_04,f_06;//0CC0D8C
	/*08*/char __08[2];//0CC0D90
	/*0a*/unsigned short f_0a,f_0c;//0CC0D92
	/*0e*/char __0e[2];//0CC0D96
	/*10*/short f_10;//0CC0D98
	//-- "VWOFT" --
	/*12*/unsigned char f_12;//length?//0CC0D9A
	/*13*/unsigned char f_13;//phase?//0CC0D9B
	/*14*/unsigned char f_14;//type?//0CC0D9C
	/*15*/char __15[1];//0CC0D9D
	/*16*/short f_16;//current offset?//0CC0D9E
	/*18*/short f_18,f_1a;//start,end?//0CC0DA0,0CC0DA2
	/*1c*/char __1c[1];//0CC0DA4
	//-- scroll related? --
	/*1d*/char bScrollType;//0CC0DA5
	/*1e*//*unsigned */char bScrollCharId;//0CC0DA6
	/*1f*//*unsigned */char bScrollState;//[0:init/1:running/2:finished]//0CC0DA7
	/*20*/unsigned short wScrollLength;//0CC0DA8
	//-- --
	/*22*/unsigned short f_22;//id//0CC0DAA
	/*24*/unsigned short f_24;//0CC0DAC
	/*26*/short f_26;//0CC0DAE
	/*28*/short f_28;//0CC0DB0
	/*2a*/short f_2a;//0CC0DB2
	/*2c*/short f_2c;//0CC0DB4
	/*2e*/short f_2e;//0CC0DB6
	/*30*/short f_30;//0CC0DB8
	/*32*/char f_32;//event related flag?dialog?//0CC0DBA
	/*33*/char f_33;//0CC0DBB
	/*34*/char f_34;//0CC0DBC
	/*35*/char f_35;//0CC0DBD
	/*36*/char f_36;//0CC0DBE
	/*37*/unsigned char f_37;//0CC0DBF
	/*38*/char f_38;//0CC0DC0
	/*39*/char f_39;//0CC0DC1
	/*3a*/char f_3a;//0CC0DC2
	/*3b*/char f_3b;//0CC0DC3
	/*3c*/char f_3c;//0CC0DC4
	/*3d*/char f_3d;//0CC0DC5
	/*3e*/short f_3e;//0CC0DC6
	/*40*/short f_40;//0CC0DC8
	/*42*/char __42[2];//0CC0DCA
	//-- --
	/*44*/int dwBattleMidiIndex;//0CC0DCC
	/*48*/int dwMidiIndex;//0CC0DD0
	//-- fade related? --
	/*4c*/short wFade_Type;//0CC0DD4
	/*4e*/short wFade_CurStep;//0CC0DD6
	/*50*/short wFade_Param;//0CC0DD8
	/*52*/short wFade_CurR,wFade_CurG,wFade_CurB;//0CC0DDA,0CC0DDC,0CC0DDE
	/*58*/short wFade_BaseR,wFade_BaseG,wFade_BaseB;//0CC0DE0,0CC0DE2,0CC0DE4
	/*5e*/short wFade_TargetR,wFade_TargetG,wFade_TargetB;//0CC0DE6,0CC0DE8,0CC0DEA
	//-- --
	/*64*/short f_64;//0CC0DEC
	/*66*/char __66[2];//0CC0DEE
	//-- keymap(1&2) --
	/*68*/struct { int dwKEY,dwPreviousKEY,dwKEYON,dwKEYOFF; } f_68,f_78;
	//-- --
	/*88*/short f_88;//movie current frame?//0CC0E10
	//-- shake related[x,y] --
	/*8a*/struct t_ad_bk_AxisShakeInfo f_8a,f_98;//0CC0E12,0CC0E20
	//-- --
	/*a6*/short f_a6,f_a8;//0CC0E2E,0CC0E30
	/*aa*/short f_aa,f_ac;//0CC0E32,0CC0E34
	/*ae*/unsigned short f_ae;//0CC0E36
	/*b0*/unsigned short f_b0;//0CC0E38
	/*b2*/unsigned char f_b2[0x40];//"IDLCK" masks//0CC0E3A
	/*f2*/unsigned char f_f2[0x40];//BG on/off?//0CC0E7A
	//__132
};

#endif
