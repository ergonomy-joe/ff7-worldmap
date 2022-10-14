/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
#ifndef __FF7_H__
#define __FF7_H__

#define __JOE_FIX_BUGS__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <direct.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <io.h>
#include <process.h>
#include <windows.h>
#include <d3d.h>
#include <ddraw.h>
#include <dinput.h>
//====---- ----====
#include "ff7_macros.h"
#include "ff7_structs.h"
#include "ff7_sound.h"

//====---- ----====
extern void C_00401000(void);//battle:yama:init:...
extern int C_00401018(void);//battle:yama:init:...
extern int C_00404A7D(void);//currently inserted CD #?
extern void C_00404B4A(int, struct t_aa0 *);//called on WM_DEVICECHANGE
//====---- from C_00404D80.cpp ----====
extern int C_00404D80(void);//Get "Graphics/Mode" Key
//====---- ----====
extern int C_004069FD(struct t_aa0 *);//prepare graphic driver?
//====---- from initpath.cpp ----====
extern char *D_009A0698;//AppPath
extern char *D_009A069C;//MoviePath
extern int   D_009A06A0;//sound "on" flag
extern char *D_009A06A4;//music path
extern char *D_009A06A8;//sound path
extern char *D_009A06AC;//midi path
extern int   D_009A06B0;//midi "on" flag
extern char *D_009A06B4;//a path
extern char *D_009A06B8;//DataPath
extern int   D_009A06BC;//FullInstall
extern char *D_009A06C0;//DataDrive
extern char *D_009A06C4;//minigame path

extern void C_00406D10(void);//initpath:start?
extern void C_004073F7(void);//initpath:clean?
extern int C_004074DA(int, int);//initpath:set music&sfx volume?
extern int C_004075B0(void);//initpath:get music&sfx volume?
extern const char *C_004076EA(void);//initpath:...
extern const char *C_004076FE(void);//minigame path(1)?
extern const char *C_0040776F(void);//minigame path(2)?
extern const char *C_004077E0(void);//minigame path(3)?
extern const char *C_00407851(void);//minigame path(4)?
extern const char *C_004078C2(void);//minigame path(5)?
extern const char *C_00407933(void);//minigame path(6)?
//====---- from main.cpp ----====
extern void C_00408116(void);//main:after field?
extern int C_004082BF(void);//main:open main archives?
extern void C_00408747(int, int, const char *, HDC);//main:debug printf?
extern void C_00408FA6(struct t_aa0 *);//MainDispatcher[BEGIN][callback]
extern void C_004090C7(struct t_aa0 *);//MainDispatcher[END][callback]
extern void C_004090E6(struct t_aa0 *);//MainDispatcher[UPDATE][callback]
extern void C_00409DF1(int, int, int, struct t_aa0 *);//MainDispatcher[ONMOUSE][callback]
extern void C_00409E39(int, int, int, struct t_aa0 *);//MainDispatcher[ONKEY][callback]
extern void C_0040A091(int, int);//main:some base init/config?
//====---- from C_0040A460.cpp ----====
extern int C_0040AAB0(void);//set time event -- counters?
extern void C_0040AB52(void);//kill time event -- counters?
extern int C_0040AC84(void);//get frame count
//====---- from sm_movie.cpp ----====
extern int *C_0040AC9A(void);//sm_movie:...
extern void C_0040B1C0(void);
extern void C_0040B27B(void);//sm_movie:...
//====---- smcdfile.cpp ----====
extern void *D_007B7470;//in scmdfile.cpp

extern unsigned char *D_009A13A8;
extern void *D_009A13AC;
extern void *D_009A13BC;//in smcdfile.cpp?C_00419360.cpp?

extern int C_00419210(const char *, int, int, void **, void (*)(void));//smcdfile:load file?
extern int C_004192D9(const char *, int, void **, void (*)(void));//smcdfile:load & inflate file?
//====---- ----====
extern void C_00419360(void);//reset "TEXT heap"?
extern void *C_00419379(int);//alloc memory on "TEXT heap"?
extern int C_004193C2(int, int);
extern unsigned char *C_0041963C(unsigned, int, int);
extern unsigned char *C_00419442(int);
extern unsigned char *C_00419491(int);
extern void C_00419E50(void *);//gzip related:set input buffer?
extern unsigned short C_00419E5D(void);//gzip related:get field[file type]?
extern unsigned short C_00419EAA(void);//gzip related:get field[inflated size]?
extern int C_00419EF7(void *);//gzip related:inflate(1)?
extern int C_00419F91(unsigned char *, void *, int);//gzip related:inflate(2)?
//====---- from battle.cpp ----====
extern int D_007C0B24;
//====---- from C_00414EE0.cpp ----====
extern int C_00414EE0(const char *, ...);//unused debug printf?
extern void C_00414EE7(void);
extern void C_00414EEC(void);
//====---- from movie.cpp ----====
extern int D_009A1010;//movie is_playing(part of a struct?)

extern int C_00416995(const char *, int, LPDIRECTDRAW, LPDIRECTDRAW2);//prepare_movie
extern void C_00417759(void);//release_movie_objects
extern int C_00417A4C(void);//restore movie surface
extern int C_00417AB0(void);//start_movie
extern int C_00417BB2(void);
extern int C_00417F39(LPDIRECTDRAWSURFACE);//update_movie_sample
extern int C_00418613(void);//get_movie_frame
extern int C_004186B6(void);//movie is playing
extern int C_004186C7(void);
extern int C_004186D1(void);
//====---- from C_0041A1B0.cpp ----====
//high-level input module
//0xde = DIK_APPS[last DIK] + 1
#define LOCAL_DIK_DE 0xde

#define LOCAL_DIK_MOUSE_B1 0xdf
#define LOCAL_DIK_MOUSE_B2 0xe0
#define LOCAL_DIK_MOUSE_B3 0xe1
//0xe2
#define LOCAL_DIK_JOY_UP 0xe3
#define LOCAL_DIK_JOY_DOWN 0xe4
#define LOCAL_DIK_JOY_LEFT 0xe5
#define LOCAL_DIK_JOY_RIGHT 0xe6
//0xe7~0xea
#define LOCAL_DIK_JOY_B1 0xeb
#define LOCAL_DIK_JOY_B2 0xec
#define LOCAL_DIK_JOY_B3 0xed
#define LOCAL_DIK_JOY_B4 0xee
#define LOCAL_DIK_JOY_B5 0xef
#define LOCAL_DIK_JOY_B6 0xf0
#define LOCAL_DIK_JOY_B7 0xf1
#define LOCAL_DIK_JOY_B8 0xf2
#define LOCAL_DIK_JOY_B9 0xf3
#define LOCAL_DIK_JOY_BA 0xf4

#define PAD_00 BIT(0)
#define PAD_01 BIT(1)
#define PAD_02 BIT(2)
#define PAD_03 BIT(3)
#define PAD_04 BIT(4)
#define PAD_05 BIT(5)
#define PAD_06 BIT(6)
#define PAD_07 BIT(7)
#define PAD_08 BIT(8)
#define PAD_09 BIT(9)
#define PAD_10 BIT(10)
#define PAD_11 BIT(11)
#define PAD_UP BIT(12)
#define PAD_RIGHT BIT(13)
#define PAD_DOWN BIT(14)
#define PAD_LEFT BIT(15)
#define PAD_16 BIT(16)
#define PAD_17 BIT(17)
#define PAD_18 BIT(18)
#define PAD_19 BIT(19)
#define PAD_20 BIT(20)
#define PAD_21 BIT(21)
#define PAD_22 BIT(22)
#define PAD_23 BIT(23)
#define PAD_24 BIT(24)

#define PAD_ANYKEY 0xffffffff

extern unsigned D_009A85E8[/*3*/][25];//input related

/*0041A1B0*/extern void PAD_init(struct t_aa0 *);
/*0041A214*/extern void PAD_clean(void);
/*0041A21E*/extern void PAD_refresh(struct t_aa0 *);
/*0041A7EF*/extern void PAD_setCommand(int, unsigned, int);
/*0041A96D*/extern void C_0041A96D(void);//key map #2?[kbd]
/*0041AB67*/extern unsigned PAD_test(unsigned);
/*0041AB74*/extern unsigned PAD_testTrigger(unsigned);
/*0041B08F*/extern int PAD_getMouseMask(void);
/*0041B099*/extern int PAD_testRepeat(unsigned);
/*0041B0CE*/extern int PAD_getMouseMaskRepeat(void);
/*0041B0D8*/extern void PAD_setRepeatParams(int, int);
/*0041B1B8*/extern int PAD_isMouseButtonPressed(int);
/*0041B22B*/extern int PAD_isKeyPressed(unsigned);
//====---- from C_0041CF10.cpp ----====
extern void C_0041CF10(unsigned char *, unsigned char *);//some inflate function?
//====---- ----====
extern int C_0041D090(unsigned char *, unsigned char *, unsigned short *);
extern int C_0041D20A(unsigned char *, unsigned short *);
extern unsigned char *C_0041D2E5(int);
//====---- ----====
/*0041D300*/extern int gunzip(unsigned char *, void *);//gzip inflate function?
//====---- from input.cpp ----====
extern int D_009A85D4;//from input:current mask
extern int D_009A85E0;//from input:trigger mask

extern int C_0041EEA0(struct t_aa0 *);
extern void C_0041EF0E(void);//clean direct input driver?
extern LPDIMOUSESTATE C_0041F139(void);//get mouse info?
extern unsigned char *C_0041F55E(void);//get keyboard map?
extern int C_0041F678(void);
extern struct t_input_98 *C_0041F7D8(void);//get joypad related object?
extern int C_0041F766(void);
extern LPDIDEVICEOBJECTDATA C_0041F5F5(void);
extern int C_0041F32A(void);
extern LPDIDEVICEOBJECTDATA C_0041F1C3(void);
//====---- ----====


//====---- from C_00620510.cpp ----====
extern FILE *C_00620510(const char *, const char *);//sort of fopen?
extern short C_0062052E(FILE *);//sort of fclose?
extern void C_00620550(FILE *, int, unsigned short);//sort of fseek?
extern int C_0062056E(FILE *);//sort of ftell?
extern int C_0062057F(FILE *);//filesize?
extern short C_006205CC(FILE *, void *);//sort of fread 1 byte
extern short C_00620602(FILE *, void *);//sort of fread 2 bytes?
//extern short __00620638(FILE *, void *);//sort of fread 4 bytes?
extern short C_0062066E(FILE *, void *, unsigned);//sort of fread n bytes?
extern short C_006206B3(FILE *, void *, int);//sort of fwrite n bytes?
extern short C_006206ED(FILE *, unsigned char);//sort of fwrite 1 byte?
extern short C_00620723(FILE *, unsigned short);//sort of fwrite 2 bytes?
extern short C_00620759(FILE *, unsigned int);//sort of fwrite 4 bytes?
//====---- ----====


//====---- FF7 Library ----====
extern int C_0065EC65(int, int, int, int, int, int);//unused_console:init?
extern void C_0065ED18(int);//unused_console:refresh/reset?
extern void C_0065ED27(void);//unused_console:clean?
//====---- ----====
extern struct MATRIX *C_0065EE0C(struct MATRIX *, struct MATRIX *, struct MATRIX *);
extern struct VECTOR *C_0065EF96(struct MATRIX *, struct SVECTOR *, struct VECTOR *);//matrix_X_vector[local]?
extern struct SVECTOR *C_0065F08B(struct MATRIX *, struct SVECTOR *, struct SVECTOR *);
extern struct VECTOR *C_0065F257(struct MATRIX *, struct VECTOR *, struct VECTOR *);
extern void C_0065F56D(short, struct MATRIX *);//rotation y
extern void C_0065F5FA(short, struct MATRIX *);
extern struct MATRIX *C_0065F687(struct SVECTOR *, struct MATRIX *);
extern struct MATRIX *C_0065F6FC(struct SVECTOR *, struct MATRIX *);
extern struct MATRIX *C_0065F76F(struct MATRIX *);
extern struct MATRIX *C_0065F7E5(struct MATRIX *, struct MATRIX *, struct MATRIX *);
extern void C_0065F85B(struct t_g_drv_0c *, LPD3DMATRIX);//general rotation matrix(1)
extern void C_0065F987(struct t_g_drv_0c *, LPD3DMATRIX);//general rotation matrix(2)
//====---- from mem.cpp ----====
/*0065FB40*/extern void mem_free(void *, const char *, int);
/*0065FDA1*/extern void *mem_malloc(int, const char *, int);
/*0065FF59*/extern void *mem_calloc(int, int, const char *, int);
extern void C_006600F2(int, void *);//mem:ZeroMem
extern void C_006602C1(int);//mem:set debug on/off?
extern void C_006602D9(void);//mem:USAGE(1)?
extern void C_006602EC(void);//mem:USAGE(2)?
/*006602FF*/extern void *mem_memdup(int, void *);
/*00660344*/extern char *mem_strdup(const char *);
//====---- from C_00660370.cpp ----====
/*00660370*/extern void TS_getCPUTimeStamp(PLARGE_INTEGER);//get CPU's time stamp counter
/*00660385*/extern void TS_add(PLARGE_INTEGER, PLARGE_INTEGER);//LARGE_INTEGER add?
/*006603A0*/extern void TS_diff(PLARGE_INTEGER, PLARGE_INTEGER, PLARGE_INTEGER);//LARGE_INTEGER diff?
/*006603C3*/extern int TS_compare(PLARGE_INTEGER, PLARGE_INTEGER);//LARGE_INTEGER cmp?
/*0066042D*/extern double TS_toDouble(PLARGE_INTEGER);//LARGE_INTEGER to double?
/*00660457*/extern void TS_doubleToTimestamp(double, PLARGE_INTEGER);//double to LARGE_INTEGER?
/*00660489*/extern double TS_getCyclesPerSecond(PLARGE_INTEGER);
//====---- from g_drv.cpp ----====
//WIREFRAME
#define G_DRV_STATE_00 0
//TEXTURE
#define G_DRV_STATE_01 1
//FILTER
#define G_DRV_STATE_02 2
//TEXTUREPERSPECTIVE
#define G_DRV_STATE_03 3
//TEXTUREMAPBLEND
#define G_DRV_STATE_04 4
//WRAPU
#define G_DRV_STATE_05 5
//WRAPV
#define G_DRV_STATE_06 6
//???
//#define G_DRV_STATE_07 7
//COLORKEY
#define G_DRV_STATE_08 8
//DITHER
#define G_DRV_STATE_09 9
//ALPHABLEND
#define G_DRV_STATE_0A 0xa
//ALPHATEST
#define G_DRV_STATE_0B 0xb
//ANTIALIAS
#define G_DRV_STATE_0C 0xc
//CULLMODE
#define G_DRV_STATE_0D 0xd
//NOCULL
#define G_DRV_STATE_0E 0xe
//DEPTHTEST
#define G_DRV_STATE_0F 0xf
//DEPTHMASK
#define G_DRV_STATE_10 0x10
//SHADEMODE
#define G_DRV_STATE_11 0x11
//SPECULAR
#define G_DRV_STATE_12 0x12
//light related
#define G_DRV_STATE_13 0x13
//FOG
#define G_DRV_STATE_14 0x14
//TEXTUREADDRESS
#define G_DRV_STATE_15 0x15

extern float C_006605CC(struct t_aa0 *);//g_drv:get some screen ratio?
/*00660540*/extern int g_drv_lockSurface(int);//G_DRV_08:
/*0066056E*/extern int g_drv_unlockSurface(int);//G_DRV_0C:
/*0066059C*/extern void g_drv_flip(struct t_aa0 *a);//G_DRV_10:
/*00660626*/extern void g_drv_clearAll(struct t_aa0 *);//G_DRV_18:
/*0066064A*/extern void g_drv_clear(int, int, int, struct t_aa0 *);//G_DRV_14:
/*0066067A*/extern void g_drv_viewport(int, int, int, int, struct t_aa0 *);//G_DRV_1C:
/*0066075C*/extern void g_drv_clearColor(struct fBGRA *, struct t_aa0 *);//G_DRV_20:
extern struct tPolygonInfo *C_006607A3(struct tMatrixInfo *, struct tRenderState *, struct tPolygonData *, struct t_rsd_74 *, struct t_aa0 *);//G_DRV_44:PolyLoad
extern void C_00660BE3(int, LPD3DMATRIX, struct tMatrixInfo *, struct t_aa0 *);//G_DRV_48:SetMatrix
/*00660C3A*/extern void g_drv_setRenderState(int, int, struct t_aa0 *);//G_DRV_64:
extern void C_00660C9A(struct t_aa0 *);//G_DRV_6C(1):SetRenderState[b] "gouraud"
extern void C_00660CCE(struct tRenderState *, struct t_aa0 *);//G_DRV_6C(2):SetRenderState[b]
extern void C_00660CF6(struct tRenderState *, struct t_aa0 *);//G_DRV_70:SetRenderState[c]
extern void C_00660D1E(int, struct t_aa0 *);//G_DRV_74:SetBlendMode
extern void C_00660D46(struct tRenderState *, struct t_aa0 *);//G_DRV_68:SetRenderState
extern void C_00660D6E(struct tPolygonInfo *, struct t_aa0 *);//G_DRV_78?
extern void C_00660D96(struct tTransparentHeap *, struct t_aa0 *);//G_DRV_7C:RenderTransparent
extern void C_00660E6A(struct t_dx_sfx_e0 *, struct t_aa0 *);//G_DRV_80?
extern void C_00660E95(int, struct t_aa0 *);//G_DRV_84?
/*00660EC0*/extern int g_drv_beginScene(int, struct t_aa0 *);//G_DRV_88:
/*00660EEB*/extern void g_drv_endScene(struct t_aa0 *);//G_DRV_8C:
extern int C_00660F12(int, int, tRGBA *, int, struct tPalette *, struct tTextureObj *);//G_DRV_58:PaletteSetData
extern int C_00660F54(int, struct tTextureObj *);//G_DRV_54:TextureSetPalette
extern void C_00660FBF(struct tPolygonInfo *, struct t_light_5ac *);//G_DRV_60:PolyApplyLight
//====---- from psx.cpp ----====
/*00661000*/extern void *psx_getScratchAddr(int);
extern struct MATRIX *C_0066100D(void);
extern tRGBA C_0066101A(void);
extern float C_00661027(void);
extern float C_00661034(void);
extern void C_00661053(struct SVECTOR *, struct t_g_drv_0c *);
extern void C_006610E1(struct VECTOR *, struct t_g_drv_0c *);
extern void C_006611A4(struct VECTOR *, struct t_g_drv_0c *);
extern void C_006611FB(struct MATRIX *, LPD3DMATRIX);
extern void C_0066134B(struct MATRIX *, LPD3DMATRIX);
extern void C_00661465(struct MATRIX *, LPD3DMATRIX);
extern void C_006616CF(struct MATRIX *, LPD3DMATRIX);
extern void C_006617E9(struct MATRIX *, LPD3DMATRIX);
extern void C_00661939(struct MATRIX *);
extern void C_00661966(int);
/*00661976*/extern void psx_SetGeomOffset(int, int);
extern void C_006619AA(double);
/*00661A1C*/extern void psx_SetGeomScreen(int);
/*00661AF1*/extern void psx_ReadGeomOffset(int *, int *);
/*00661B12*/extern int psx_ReadGeomScreen(void);
extern void C_00661B23(int, int);//psx:set view x,y(2)?
extern void C_00661B68(int, int);//psx:set view x,y?
/*00661C07*/extern struct VECTOR *psx_ApplyMatrix(struct MATRIX *, struct SVECTOR *, struct VECTOR *);
/*00661CA3*/extern struct VECTOR *psx_ApplyMatrixLV(struct MATRIX *, struct VECTOR *, struct VECTOR *);
/*00661D3F*/extern struct SVECTOR *psx_ApplyMatrixSV(struct MATRIX *, struct SVECTOR *, struct SVECTOR *);
/*00661DDE*/extern struct VECTOR *psx_ApplyRotMatrix(struct SVECTOR *, struct VECTOR *);
/*00661E85*/extern struct MATRIX *psx_CompMatrix(struct MATRIX *, struct MATRIX *, struct MATRIX *);
/*00661F36*/extern struct MATRIX *psx_MulMatrix(struct MATRIX *, struct MATRIX *);
/*00662035*/extern struct MATRIX *psx_MulMatrix0(struct MATRIX *, struct MATRIX *, struct MATRIX *);
/*00662134*/extern struct MATRIX *psx_MulMatrix2(struct MATRIX *, struct MATRIX *);
/*00662233*/extern struct MATRIX *psx_MulRotMatrix(struct MATRIX *);
/*0066233D*/extern struct MATRIX *psx_MulRotMatrix0(struct MATRIX *, struct MATRIX *);
/*00662447*/extern void psx_PopMatrix(void);
/*00662499*/extern void psx_PushMatrix(void);
/*006624FD*/extern int psx_rcos(int);
/*00662538*/extern int psx_rsin(int);
/*00662573*/extern int psx_ratan2(int, int);
/*006625AB*/extern struct MATRIX *psx_RotMatrixX(int, struct MATRIX *);
/*006626BC*/extern struct MATRIX *psx_RotMatrixY(int, struct MATRIX *);
/*006627CD*/extern struct MATRIX *psx_RotMatrixZ(int, struct MATRIX *);
/*006628DE*/extern struct MATRIX *psx_RotMatrixXYZ(struct SVECTOR *, struct MATRIX *);
/*00662AD8*/extern struct MATRIX *psx_RotMatrixYXZ(struct SVECTOR *, struct MATRIX *);
/*00662CD2*/extern struct MATRIX *psx_RotMatrixZYX(struct SVECTOR *, struct MATRIX *);
/*00662ECC*/extern void psx_RotTrans(struct SVECTOR *, struct VECTOR *, int *);
/*00662FA3*/extern void psx_RotTransSV(struct SVECTOR *, struct SVECTOR *, int *);
/*0066307D*/extern int psx_RotTransPers(struct SVECTOR *, int *, int *, int *);
extern void C_0066316F(int, int, int, struct MATRIX *, struct t_g_drv_0c *, struct SVECTOR *);
extern int C_0066327E(struct SVECTOR *, int *, int *, int *);
/*0066332E*/extern void psx_SetBackColor(unsigned char, unsigned char, unsigned char);
/*0066335F*/extern void psx_SetFarColor(int, int, int);
/*00663390*/extern struct MATRIX *psx_ScaleMatrix(struct MATRIX *, struct VECTOR *);
/*006634B3*/extern struct MATRIX *psx_ScaleMatrixL(struct MATRIX *, struct VECTOR *);
/*006635D6*/extern void psx_ReadRotMatrix(struct MATRIX *);
/*00663673*/extern void psx_SetRotMatrix(struct MATRIX *);
/*00663707*/extern void psx_SetTransMatrix(struct MATRIX *);
/*00663736*/extern int psx_SquareRoot0(int);
/*00663748*/extern int psx_SquareRoot12(int);
/*00663766*/extern struct MATRIX *psx_TransMatrix(struct MATRIX *, struct VECTOR *);
/*00663791*/extern struct MATRIX *psx_TransposeMatrix(struct MATRIX *, struct MATRIX *);
extern struct MATRIX *C_00663813(struct MATRIX *, struct MATRIX *);
/*006638B0*/extern int psx_VectorNormal(struct VECTOR *, struct VECTOR *);
/*00663973*/extern int psx_VectorNormalS(struct VECTOR *, struct SVECTOR *);
/*00663A48*/extern int psx_VectorNormalSS(struct SVECTOR *, struct SVECTOR *);
/*00663B32*/extern void psx_OuterProduct0(struct VECTOR *, struct VECTOR *, struct VECTOR *);
/*00663B9F*/extern void psx_OuterProduct12(struct VECTOR *, struct VECTOR *, struct VECTOR *);
extern void C_00663C1B(int);
extern void C_00663C20(void);
extern void C_00663C25(void);
extern void C_00663C2A(int, int);
//====---- from dx_dbg.cpp ----====
extern int C_00664C09(HRESULT , const char *, int);
extern void C_00664C8B(struct t_dx_dbg_14 *);//dx_dbg:release object?
extern struct t_dx_dbg_14 *C_00664D80(const char *);//dx_dbg:open log file?
extern void C_00664D93(const char *, struct t_dx_dbg_14 *);//dx_dbg:...
/*00664E30*/extern void dx_dbg_puts(const char *);
//====---- ----====
extern void C_006654BC(struct t_dx_3d2d_28 *);//dx_3d2d:...
extern struct t_dx_3d2d_28 *C_006654FB(int, int, int);//dx_3d2d:...
extern void C_006656D1(struct t_aa0 *);//dx_3d2d:...
extern void C_006656A4(struct t_aa0 *);//dx_3d2d:...
extern void C_00665793(LPD3DMATRIX, LPD3DMATRIX, struct tIndexedPrimitives *, struct tPolygonInfo *, struct tRenderState *, struct t_g_drv_GroupInfo *, struct t_aa0 *);
extern void C_00665D9A(LPD3DMATRIX, void *, struct tIndexedPrimitives *, struct tRenderState *, struct t_dx_sfx_84 *, struct t_aa0 *);
extern void C_0066695C(struct t_dx_sfx_e0 *, struct t_aa0 *);//dx_3d2d:...
//====---- from C_00666AB0.cpp ----====
extern void C_00666AB0(int, struct t_extdll_24 *);
extern int C_00666AD5(struct t_extdll_24 *, struct t_aa0 *);//load graphic dll?
extern void C_00666B85(struct t_54a74 *, struct t_aa0 *);//set "struct t_aa0:f_930"
extern struct t_54a74 *C_00666B96(struct t_aa0 *);//get "struct t_aa0:f_930"
extern struct t_f0 *C_00666BBE(struct t_aa0 *);//get "struct t_aa0::f_934"
extern int C_00666BCC(struct t_aa0 *);//get "struct t_aa0:f_838"
extern void C_00666BF0(int, struct t_aa0 *);//set "struct t_aa0:f_838/f_834"
extern void C_00666C78(struct t_aa0 *);//refresh main loop callbacks?
extern int C_00666CF2(struct tMainCallbacks *, struct t_aa0 *);//set main loop callbacks?
extern void C_00666D47(struct tMainCallbacks *, struct t_aa0 *);//get main loop callbacks?
extern void C_00666DA3(struct t_aa0 *);//calls "instance:reset"
extern void C_00666DC0(struct t_aa0 *);//calls "dx_sfx:reset heaps(1)"
extern void C_00666DDD(struct t_aa0 *);//reset "transparent heap"
extern void C_00666DF4(struct t_aa0 *);//render "transparent heap"
extern void C_00666E0F(int, struct t_aa0 *);//blend mode related:set?
extern void C_00666E43(struct t_aa0 *);//blend mode related:reset?
extern int C_00666ED7(struct t_aa0 *);//get some stat info?
extern void C_00666F09(float, float, int, struct t_dx_rend_vertex_20 *);//patch vertex [u,v]?
//====---- from psxgraph.cpp ----====
extern char D_00D8E490[];//psxgraph:scratchpad

extern void C_00666F87(float, float);//psxgraph:...
extern void C_00666FA7(float, float, float, float, float, float, float, float);//psxgraph:set default fZ[] fRHW[]
extern struct tVECTOR_F4 *C_00667005(int);//psxgraph:load some rot float vector[0~3]?
extern void C_0066705A(int, struct tVECTOR_F4 *);//psxgraph:...
extern void C_0066714B(int bp08, struct tVECTOR_F4 *);//psxgraph:...
extern void C_0066723C(unsigned);//psxgraph:set alpha[0]?
extern void C_00667249(unsigned, unsigned, unsigned, unsigned);//psxgraph:set alpha[0~3]?
extern void C_00667270(int);//psxgraph:...
extern void C_0066727D(int);//psxgraph:...
extern void *C_00667297(void);//psxgraph:get some scratchpad?
extern void C_006672D0(void);//psxgraph:...
extern void C_006672FA(int, int, struct t_dx_sfx_e0 *);//psxgraph:...
extern void C_006673E4(unsigned char, unsigned char, unsigned char, int, tBGRA *);//psxgraph:...
extern void C_00667482(int, int, struct t_dx_sfx_e0 *, int *);//psxgraph:...
extern void C_00667A1E(struct SVECTOR *);//psxgraph:"gte_ldv0"?
/*00667A2B*/extern void psxgraph_gte_ldv3(struct SVECTOR *, struct SVECTOR *, struct SVECTOR *);
extern void C_00667A4A(void);//psxgraph:"gte_rtps"?
/*00667A5D*/extern int psxgraph_gte_rtpt(void);
extern void C_00667A7E(struct SVECTOR *);//psxgraph:"gte_ldv0"(bis)?
extern void C_00667A8B(void);//psxgraph:"gte_rtps"(bis)?
/*00667A9E*/extern void psxgraph_gte_stflg(int *);
extern void C_00667AAC(int *);//psxgraph:"gte_stszotz"?
extern void C_00667ABE(int *);//psxgraph:"gte_stotz"?
extern void C_00667AD0(int *);//psxgraph:"gte_stopz"?
/*00667ADE*/extern void psxgraph_gte_lddp(int);
/*00667AEB*/extern void psxgraph_gte_ldrgb(unsigned char *);
/*00667B12*/extern void psxgraph_gte_strgb(unsigned char *);
/*00667B39*/extern void psxgraph_gte_dpcs(void);
extern void C_00667B56(void);//psxgraph:"gte_rtv0"?
extern void C_00667B6E(struct VECTOR *);//psxgraph:"gte_stlvnl"?
extern int C_00667B95(struct SVECTOR *, int *, int *);//psxgraph:...
extern int C_00667BBB(struct SVECTOR *, int *, int *);//psxgraph:...
extern int C_00667BE1(struct SVECTOR *, struct SVECTOR *, struct SVECTOR *, int *, int *);//psxgraph:...[identical to C_00667E43]
extern int C_00667C0F(struct SVECTOR *, struct SVECTOR *, struct SVECTOR *, struct SVECTOR *, int *, int *);//psxgraph:...[identical to C_00667F35]
extern int C_00667C85(struct SVECTOR *, struct SVECTOR *, struct SVECTOR *, int *, int *, int *, int *, int *);//psxgraph:...[identical to C_00667E71]
extern int C_00667D49(struct SVECTOR *, struct SVECTOR *, struct SVECTOR *, struct SVECTOR *, int *, int *, int *, int *, int *, int *);//psxgraph:...
extern int C_00667E43(struct SVECTOR *, struct SVECTOR *, struct SVECTOR *, int *, int *);//psxgraph:...
extern int C_00667E71(struct SVECTOR *, struct SVECTOR *, struct SVECTOR *, int *, int *, int *, int *, int *);//psxgraph:...[identical to C_00667C85]
extern int C_00667F35(struct SVECTOR *, struct SVECTOR *, struct SVECTOR *, struct SVECTOR *, int *, int *);//psxgraph:...
extern int C_00667F67(struct SVECTOR *, struct SVECTOR *, struct SVECTOR *, struct SVECTOR *, int *, int *, int *, int *, int *, int *);//psxgraph:...
extern void C_00669A37(
	unsigned,
	float, float, float, float, float, float, float, float,
	int, int, int, int, int, int, int, int, 
	int,
	float,
	float,
	struct t_dx_sfx_e0 *
);//psxgraph:draw quad()
extern void C_0066A2B9(int, int, int, int, int, int, float, float, unsigned, int, struct t_dx_sfx_e0 *);//SPRT_*
extern void C_0066A47E(void *);//psxgraph:DrawPrim?
extern void C_0066BF08(void);//psxgraph:clean something?
extern int C_0066BF8E(struct t_instance_8 *, struct t_dx_sfx_70 *);//psxgraph:"CREATE PRIMITIVE SYSTEM"
extern void C_0066C19E(int);//psxgraph:...
/*0066C287*/extern void psxgraph_DpqColor(unsigned char *, int, unsigned char *);
/*0066C371*/extern void psxgraph_DpqColor3(unsigned char *, unsigned char *, unsigned char *, int, unsigned char *, unsigned char *, unsigned char *);
extern void C_0066C3B2(int);//psxgraph:set some flag
extern int C_0066C3BF(void);//psxgraph:get some flag
//====---- ----====
extern void C_0066C42E(int, struct t_rsd_0c *);
extern void C_0066C49E(int, struct t_dx_sfx_e0 *);
extern void C_0066C4BC(int, struct tSkeleton *);
//====---- from C_0066C4F0.cpp ----====
extern void C_0066C4F0(LPD3DMATRIX);//set matrix to identity?
extern void C_0066C53C(LPD3DMATRIX);//set matrix to "something"?
extern void C_0066C56E(LPD3DMATRIX, LPD3DMATRIX, LPD3DMATRIX);
extern void C_0066C6CD(LPD3DMATRIX, LPD3DMATRIX, LPD3DMATRIX);//matrix multiplication?
extern void C_0066C984(LPD3DMATRIX, LPD3DMATRIX, LPD3DMATRIX);
extern void C_0066CC3B(LPD3DMATRIX, LPD3DMATRIX, LPD3DMATRIX);
extern void C_0066CDD6(LPD3DMATRIX, struct t_g_drv_0c *, struct t_g_drv_0c *);//matrix/vector operation?
extern void C_0066CE40(LPD3DMATRIX, struct t_g_drv_0c *, struct tVECTOR_F4 *);
extern void C_0066CED8(LPD3DMATRIX, struct t_g_drv_0c *, struct t_g_drv_0c *);
extern void C_0066CF4D(LPD3DMATRIX, struct t_g_drv_0c *, struct t_g_drv_0c *);
extern void C_0066CF7E(LPD3DMATRIX, struct t_g_drv_0c *, struct t_g_drv_0c *);
extern void C_0066CFE8(LPD3DMATRIX, struct t_g_drv_0c *, struct t_g_drv_0c *);
//====---- from dx_spr.cpp ----====
extern void C_0066D95D(unsigned, struct t_dx_sfx_e0 *);//dx_spr:prepare some render state?
extern void C_0066E104(int, struct t_dx_sfx_70 *);
extern int C_0066E272(int, struct t_dx_sfx_e0 *);//dx_spr:alloc/prepare polygon?
extern void C_0066E62C(struct t_dx_sfx_e0 *);//dx_spr:reset something?
extern void C_0066E641(struct t_dx_sfx_e0 *, struct t_aa0 *);//dx_spr:render something?
extern void C_0066E70A(int, LPD3DMATRIX, struct t_dx_sfx_e0 *);//dx_spr:...
extern int C_0066E74C(int, struct t_dx_sfx_e0 *);//dx_spr:alloc/prepare line?
//====---- from dx_sfx.cpp ----====
extern void C_00670483(struct tRenderState *);//dx_sfx:...
extern void C_006700E0(int, struct t_g_drv_LockedVertexBuffer *);
extern void C_00670144(int, struct tPolygonInfo *, struct t_aa0 *);//dx_sfx:...
extern struct t_g_drv_LockedVertexBuffer *C_00670196(int, struct tPolygonInfo *, struct t_aa0 *);//dx_sfx:...
extern struct tRenderState *C_00670350(int, struct t_rsd_74 *, struct t_aa0 *);//dx_sfx:...
extern struct tRenderState *C_00670496(int, int, const char *, struct t_rsd_74 *, struct t_aa0 *);//dx_sfx:...
extern void C_00670C97(struct t_dx_sfx_70 *);//dx_sfx:...
extern struct t_dx_sfx_70 *C_00670DA4(int, int, int, int, struct t_aa0 *);//dx_sfx:alloc "struct t_dx_sfx_70 *"
extern void C_00670F4F(struct t_dx_sfx_70 *);//dx_sfx:...
extern void C_00670F9B(struct t_dx_sfx_70 *);//dx_sfx:...
extern void C_00670FD3(struct t_dx_sfx_e0 *);//dx_sfx:...
extern void C_00671082(struct t_dx_sfx_e0 **);//dx_sfx:release "struct t_dx_sfx_e0 **"
extern struct t_dx_sfx_e0 *C_006710AC(int, int, struct t_rsd_74 *, const char *, struct t_dx_sfx_70 *);//dx_sfx:...
extern void C_006716CD(struct t_dx_sfx_e0 *);//dx_sfx:...
extern void C_006716F5(struct t_dx_sfx_e0 *);//dx_sfx:...
extern void C_00671742(int, struct tRenderState *, struct t_dx_sfx_84 *);
extern struct t_instance_90 *C_00671C71(struct t_dx_sfx_e0 *);//dx_sfx:...
extern struct t_dx_sfx_84 *C_00671D2A(int, int, int, int, int, int, float, struct t_dx_sfx_e0 *);
extern struct t_dx_sfx_84 *C_00671ED5(int, int, int, int, int, int, int, int, int, float, struct t_dx_sfx_e0 *);//dx_sfx:...
extern struct t_dx_sfx_84 *C_00672080(int, int, int, int, int, int, int, int, unsigned, float, float, struct t_dx_sfx_e0 *);//dx_sfx:...
extern struct t_dx_sfx_84 *C_00672325(int, int, int, int, int, int, int, int, int, unsigned, float, float, struct t_dx_sfx_e0 *);//dx_sfx:...
extern void C_00672C61(struct t_dx_sfx_xxx_08 *, struct t_dx_sfx_e0 *);//dx_sfx:...
extern void C_00672FBC(int, int, int, int, struct t_dx_sfx_e0 *);//dx_sfx:...
extern int C_006739D3(int, int, tRGBA *, int, struct t_dx_sfx_e0 *);//dx_sfx:PaletteSetData
extern void C_00673A25(void (*)(int, void *), struct tPolygonInfo *);//dx_sfx:...
extern void C_00673AE3(void (*)(int, void *, void *, void *), struct tPolygonInfo *, struct tPolygonInfo *);//dx_sfx:...
extern void C_00673C30(void (*)(int, void *, void *), struct tPolygonInfo *);//dx_sfx:...
extern void C_00674402(struct t_dx_sfx_b8 *);//dx_sfx:...
extern struct t_dx_sfx_e0 *C_00674418(int, int, int, struct t_dx_sfx_b8 *, struct t_instance_8 *, struct t_dx_sfx_70 *);//dx_sfx:...
//====---- from rsd.cpp ----====
extern int C_00674530(void);//rsd:get "use PSX resources" flag
extern void C_0067453A(int);//rsd:set "use PSX resources" flag
extern void C_00674551(int);//rsd:set "RSD" flags
extern void C_0067455E(struct t_rsd_74 *);//rsd:init with blend mode 4?
extern void C_006745E6(int, struct t_rsd_74 *);//rsd:set blend mode?
extern void C_00674659(int, struct t_rsd_74 *);//rsd:set struct t_rsd_74::f_20
extern void C_0067466D(struct t_rsd_0c *, struct t_aa0 *);
extern void C_006746D3(struct t_rsd_0c **, struct t_aa0 *);//rsd:...
extern struct t_rsd_0c *C_00674701(struct t_plytopd_RSD *, struct t_rsd_74 *, const char *, struct t_aa0 *);//rsd:load rsd data?
extern struct t_rsd_0c *C_00674A0A(struct t_rsd_74 *, const char *, struct t_aa0 *);//rsd:...
extern void C_00674A86(LPD3DMATRIX, struct t_rsd_0c *, struct t_aa0 *);//rsd:SetMatrix to "struct t_rsd_0c"
extern void C_00674ADD(unsigned, struct t_rsd_0c *);
extern void C_00674AF5(struct t_rsd_0c *);
extern struct tInfoListOfRSD *C_00674B09(struct tInfoListOfRSD *);//rsd:create "struct tInfoListOfRSD"
extern void C_00674B4F(struct tListOfRSD *, struct t_aa0 *);//rsd:clean "struct tListOfRSD"
extern struct tListOfRSD *C_00674BCC(int, struct t_aa0 *);//rsd:...
extern struct tListOfRSD *C_00674C3E(struct tInfoListOfRSD *, struct t_rsd_74 *, struct t_aa0 *);//rsd:load "struct tListOfRSD"
extern void C_0067504F(LPD3DMATRIX, struct tListOfRSD *, struct t_aa0 *);//rsd:set matrix to "struct tListOfRSD"
extern void C_00675098(int, void (*)(int, struct tPolygonInfo *), struct tListOfRSD *);//rsd:...
//====---- from is_lib.cpp ----====
extern void C_006750E0(int id);//is_lib:...
extern int C_00675F1D(int);
extern int C_00675511(const char *, int );//is_lib:open archive?
extern int C_006758C3(const char *);
extern int C_00675949(void);
extern int C_006759D2(const char *, int id);//is_lib:get entry offset?
extern int C_00676064(void);
extern int C_00676228(int, int id);//is_lib:seek?
extern int C_006762EA(int, int id);//is_lib:get entry size
extern int C_0067633E(int, int, void *, int);//is_lib:load entry
extern int C_006763A5(int, void *, int);
//====---- from directx.cpp ----====
extern void C_0067656B(struct t_aa0 *);//directx:set some game object?
extern struct t_aa0 *C_00676578(void);//directx:get some game obj?
extern void C_006765BD(void);//directx:clean some game object?
extern void C_00676605(struct t_aa0 *);//set quit flag to game obj?
extern int C_0067692A(HINSTANCE, struct t_aa0 *);//initialize the window/launch init callback?
extern int C_00676C56(struct t_aa0 *, const char *, const char *, int d);//windows popup?
extern struct t_aa0 *C_00676E7E(void);//directx:init some game object?
extern int C_00676F2A(struct t_aa0 *);
extern struct tD3DTextureInfo *C_00677A38(void);//graphicx.directx:alloc "struct tD3DTextureInfo"
extern void C_00677B11(struct tD3DTextureInfo *, struct t_aa0 *);//graphicx.directx:add "struct tD3DTextureInfo" to list
extern LPDIRECTDRAWSURFACE C_006778C8(int);
extern int C_00677CFF(int);
extern int C_0067806E(struct t_aa0 *);
extern void C_00679864(struct t_aa0 *);
extern int C_00679FE9(int, LPDIRECTDRAWSURFACE);
//====---- from dx_mat.cpp ----====
extern void C_0067A067(LPDIRECT3DMATERIAL *);//dx_mat:...
extern LPDIRECT3DMATERIAL C_0067A083(struct t_aa0 *);//dx_mat:create material?
extern void C_0067A11B(int, struct fBGRA *, D3DMATERIAL *);//set some D3DMATERIAL content?
extern void C_0067A1B6(struct tRenderState *);//dx_mat:release "struct tRenderState"
extern struct tRenderState *C_0067A1D4(void);//dx_mat:init structure(size 0x64)?
extern float C_0067A254(float);//dx_mat:degree2radian?
extern float C_0067A268(float);//dx_mat:radian2degree?
extern void C_0067A3AF(LPD3DMATRIX);//dx_mat:free matrix
extern LPD3DMATRIX C_0067A3D0(void);//dx_mat:alloc D3DMATRIX(size 0x40)?
extern void C_0067A5AF(LPD3DMATRIX, LPD3DMATRIX, LPD3DMATRIX);//dx_mat:3x3 conjugate multiplication?
extern void C_0067AF75(LPD3DMATRIX, LPD3DMATRIX);//dx_mat:matrix multiply too?
extern void C_0067B706(LPD3DMATRIX, struct t_g_drv_0c *, struct tVECTOR_F4 *);//dx_mat:vector x matrix(w==1)?
extern void C_0067B9F7(struct tVECTOR_F4 *, struct tVECTOR_F4 *);//dx_mat:normalize vector(1)
extern void C_0067BA56(struct tVECTOR_F4 *, struct t_dx_3d2d_14 *);//dx_mat:normalize vector(2)
extern void C_0067BAB4(struct tVECTOR_F4 *, struct t_SW_Vertex *);//dx_mat:...
extern void C_0067BC2E(LPD3DMATRIX);
extern void C_0067BC5B(LPD3DMATRIX);//dx_mat:last column to {0,0,0,1}
extern void C_0067BCD3(float, LPD3DMATRIX);
extern void C_0067BCFE(struct t_g_drv_0c *, LPD3DMATRIX);
extern void C_0067BD81(struct t_g_drv_0c *, LPD3DMATRIX);//dx_mat:make translation matrix?
extern void C_0067BE13(float, LPD3DMATRIX);
extern void C_0067BE71(float, LPD3DMATRIX);
extern void C_0067BECE(float, LPD3DMATRIX);
extern void C_0067BF2B(float, LPD3DMATRIX);
extern void C_0067BF89(float, LPD3DMATRIX);
extern void C_0067BFE6(float, LPD3DMATRIX);
extern void C_0067C17F(int, float, LPD3DMATRIX);
extern void C_0067C251(LPD3DMATRIX, LPD3DMATRIX);
extern void C_0067C2C0(LPD3DMATRIX, LPD3DMATRIX);
extern void C_0067C383(LPD3DMATRIX);
extern void C_0067C3AE(float, float, float, float, float, float, float, float, LPD3DMATRIX);
extern void C_0067C6A6(struct tMatrixInfo *);//dx_mat:destroy "struct tMatrixInfo *"
extern struct tMatrixInfo *C_0067C77C(int);//dx_mat:create "struct tMatrixInfo *"
struct tMatrixInfo *C_0067C854(void);//dx_mat:create "struct tMatrixInfo *"(0)
extern LPD3DMATRIX C_0067C9BE(int, struct tMatrixInfo *);//dx_mat:get "global" matrix
extern void C_0067CA3E(int, int, LPD3DMATRIX, struct tMatrixInfo *);
extern void C_0067CBF1(LPD3DMATRIX, struct t_aa0 *);
extern void C_0067CC1F(LPD3DMATRIX, struct t_aa0 *);
extern void C_0067CC6C(LPD3DMATRIX, struct t_aa0 *);//dx_mat:...
extern void C_0067CCDE(float, float, float, float, float, float, float, struct t_aa0 *);//dx_mat:projection matrix related?
extern int C_0067CE83(LPD3DMATRIX, LPD3DMATRIX);//dx_mat:...
extern int C_0067CE9D(LPD3DMATRIX, struct t_g_drv_0c *, struct tVECTOR_F4 *, struct tVECTOR_F4 *);
extern int C_0067CFF0(LPD3DMATRIX, struct t_g_drv_0c *, struct tVECTOR_F4 *, struct tVECTOR_F4 *);//dx_mat:...
extern int C_0067D056(LPD3DMATRIX, struct tVECTOR_F4 *, struct tVECTOR_F4 *);
extern void C_0067D2BF(LPD3DMATRIX, LPD3DMATRIX);//dx_mat:...
extern int C_0067D80A(LPD3DMATRIX, LPD3DMATRIX);//dx_mat:compute matrix inverse
//====---- from C_0067DED0.cpp ----====
extern void C_0067DF84(LPDDSCAPS);//d3d:display surface caps?
extern void C_0067E10F(LPDDCAPS);//d3d:display driver caps?
extern void C_0067F149(int, LPD3DDEVICEDESC, struct t_0067DED0_8 *, struct t_0067DED0_8 *);//d3d:display device desc?
//====---- ----====
extern void *C_0067F5F0(int, int, struct t_aa0 *);//get rendering buffer at x y?
extern void C_0067F9A3(int, int, int, int, int, void *, int, int, int, void *);//blit_1x
extern void C_0067FA09(int, int, int, int, int, void *, int, int, int, void *);//blit_2x
extern int C_00681F6D(struct tSW_BufferInfo *, struct t_aa0 *);//sw:get rendering buffer
extern void C_00681FB1(void *, struct t_aa0 *);//sw:some init?
//====---- from file.cpp ----====
/*00682076*/extern void file_initLocator(int, struct t_file_10 *);
/*00682091*/extern void file_close(struct t_file_18 *);
/*006820D2*/extern struct t_file_18 *file_open0(struct t_file_10 *, const char *);
/*006825D7*/extern struct t_file_18 *file_open(int, const char *);
/*00682601*/extern int file_read(int, void *, struct t_file_18 *);
/*00682697*/extern int file_read2(int, void *, struct t_file_18 *);
/*00682725*/extern int file_write(int, void *, struct t_file_18 *);
/*00682820*/extern void *file_allocRead(int, int , struct t_file_18 *);
/*00682891*/extern int file_tell(struct t_file_18 *);
/*006828FA*/extern void file_lseek(struct t_file_18 *, int);
extern void *C_0068295F(struct t_file_10 *, int, int *, const char *);
extern void *C_006829FE(struct t_file_10 *, int *, const char *);
/*00682A19*/extern void *file_allocLoad(int *, const char *);
/*00682A30*/extern int file_save(int, const char *, void *);
extern void C_00682A86(struct t_file_20_bis *);//file:release registry entry[used by dx_graph]
extern void C_00682B18(struct t_file_20_bis *);//(callback)[used by dx_graph]
extern struct t_file_20_bis *C_00682B29(int, const char *, const char *);//file:create registry entry[used by dx_graph]
extern int C_00682C4E(void *, void *);//file:(callback)compare element from list[used by dx_graph]?
extern int C_00682C63(int, void *, void *);//file:(callback)[used by dx_graph]
/*00682C91*/extern void file_extRemove(const char *, char *);
/*00682CFA*/extern void file_extSetCharDigitDigit(char, int, const char *, char *);
/*00682D3B*/extern void file_extChange(const char *, const char *, char *);
//====---- ----====
extern void C_00682D80(struct t_swirl_118 *);
extern void C_0068317E(struct t_swirl_124 *);
extern void C_006831AB(int, struct t_swirl_124 *);
extern struct t_swirl_124 *C_006831EF(int, struct t_swirl_124 *);
extern void C_00683263(int, struct t_swirl_124 *);
extern void C_00683311(int, int, struct t_swirl_124 *);
//====---- from anm.cpp ----====
extern void C_006833D0(int *);//anm:get some default flags?
extern void C_006833DE(int *);//anm:set some flags?
extern void C_006840DA(int, struct t_animationHeader *, struct t_plytopd_74 *, struct tSkeleton *, struct t_aa0 *);//anm:...(a big one)
extern void C_00684C32(struct t_animationHeader *, struct tSkeleton *);//anm:...
extern void C_00684CC6(struct tSkeleton *, struct t_aa0 *);//anm:render through "G_DRV_78"?
extern void C_00684E20(struct fBGRA *, struct tSkeleton *, struct t_aa0 *);//anm:...
extern void C_00684ECD(struct tSkeleton *, struct t_aa0 *);//anm:...
extern void C_00684F73(struct t_ComplexBlendInfo *, struct tSkeleton *);//anm:...
extern void C_00685028(void *, void (*)(void *, struct tPolygonInfo *), struct tSkeleton *);//anm:...
extern void C_006850DB(struct tSkeleton *);//anm:...
//====---- ----====
extern void C_00685110(struct t_global_fc *);//dx_stat:...
extern struct t_global_fc *C_00685128(void);//dx_Stat:init structure(size 0xfc)?
extern void C_0068515B(struct t_global_fc *);//dx_stat:...
extern void C_00685187(int, int, HDC, void (*)(int, int, const char *, HDC), struct t_global_fc *);//dx_stat:...
//====---- from dx_graph.cpp ----====
extern int C_00685DA0(int);//dx_graph:count bits set in dword?
extern int C_00685DF0(int);//dx_graph:first bit set in dword?
extern void C_00685E62(int, int, int, int, int, struct tTextureInfo *);//dx_graph:init "struct tTextureInfo *"
extern void C_00685FF0(LPDDPIXELFORMAT, struct tTextureInfo *);
extern void C_006860EF(struct t_dx_graph_18 *, struct tTextureInfo *);//dx_graph:init "struct tTextureInfo *"[2]
extern int C_00686143(unsigned, unsigned, unsigned);//dx_graph:...
extern int C_006861EC(tRGBA, struct tTextureInfo *);
extern int C_0068631E(int *, int *, int *, tRGBA);//dx_graph:...
extern int C_00686351(tRGBA, struct t_aa0 *);
extern void C_00686396(int *, int *, int *, struct tTextureInfo *);
extern tRGBA C_00686514(unsigned/*or int?*/, struct tTextureInfo *);//dx_graph:...
extern tRGBA C_006865F0(unsigned, int, struct tTextureInfo *);//dx_graph:...
extern void C_00686F8C(struct tTextureObj *);//dx_graph:TextureCleanPalette
extern struct tPalette *C_00686FB6(int, struct tTexHeader *, struct tTextureObj *);//dx_graph:TextureCreatePalette
extern void C_0068702C(struct tTexHeader *, struct tTextureInfo *, void *);//dx_graph:texture conversion?
extern void C_00687AB1(struct tTextureObj *);//dx_graph:registry.ReleaseTexture
extern struct tTextureObj *C_00687B53(void);//dx_graph:allocate "struct tTextureObj"
extern struct tTextureObj *C_00688AA9(struct t_rsd_74 *, struct tTexHeader *, struct t_aa0 *);//dx_graph:...
extern void C_00688B03(struct tTexHeader *);//dx_graph:clean "struct tTexHeader *"
extern void C_00688B95(struct tTexHeader *);//dx_graph:registry.clean "struct tTexHeader *"
extern struct tTextureObj *C_006888B2(struct tTextureObj *);//dx_graph:restore/reload texture[called after DDERR_SURFACELOST]?
extern struct tTexHeader *C_00688C46(void);//dx_graph:alloc "struct tTexHeader *"
extern struct tTexHeader *C_00688E19(struct t_file_10 *, const char *);//dx_graph:
extern int C_00688FA4(const char *, struct tTexHeader *);//dx_graph:
extern int C_0068924B(int, int, tRGBA *, int, struct tTextureObj *);//dx_graph:PaletteSetData
//====---- from thread.cpp ----====
extern void C_006892B0(void (*)(void), struct t_thread_10 *);//thread:init thread info?
extern void C_006892E5(struct t_thread_24 *);//thread:clean?
extern struct t_thread_24 *C_0068930C(struct t_thread_10 *);//thread:alloc?
extern int C_00689395(struct t_thread_24 *);//thread:getstate?
extern void C_006893B6(int, struct t_thread_24 *);//thread:setstate?
extern int C_0068940E(struct t_thread_24 *);//thread:start?
//====---- ----====
extern struct t_rsd_0c *C_0068A115(int, struct t_render_24 *);
extern struct t_dx_sfx_e0 *C_0068A155(int, struct t_render_24 *);//render:...
extern struct t_shp_30 *C_0068A195(int, struct t_render_24 *);//render:...
extern void C_0068A567(struct t_render_local_2c *);//render:...
extern struct t_render_local_2c *C_0068A638(int, struct t_render_for_combat_2c *);//render:"CREATE RENDER SYSTEM LIST"
extern void C_0068A871(struct t_render_local_2c *);//render:...
extern void C_0068A89A(int, int, struct t_render_local_2c *);//render:...
extern void C_0068A951(int, struct t_render_local_2c *);//render:...
extern void C_0068A9E0(struct t_render_forcombat_0c *);//render:...
extern void C_0068AA06(int, struct t_render_14 *, struct t_render_forcombat_0c *, struct t_render_24 **, struct t_render_local_2c *);//render:...
//====---- ----====
extern void C_0068AAC0(struct t_dx_rendi_e4 *, struct t_aa0 *);//dx_rendi:...
extern struct t_dx_rendi_e4 *C_0068AB84(struct t_aa0 *);
extern void C_0068B239(int, struct tRenderState *);//dx_rendi:...
extern void C_0068B4C7(struct t_aa0 *);
extern void C_0068B518(struct t_aa0 *);
extern void C_0068C9CF(struct t_rsd_0c *, struct t_aa0 *);//dx_rendi:...
//====---- ----====
extern void C_0068CF75(int, struct t_ComplexBlendInfo *);//init/reset object struct t_ComplexBlendInfo *
extern void C_0068D2B8(int, struct tPolygonInfo *, struct t_ComplexBlendInfo *);
extern void C_0068D68F(struct t_ComplexBlendInfo *, struct tPolygonInfo *);
extern void C_0068D947(struct fBGRA *, struct fBGRA *, tRGBA *);
extern void C_0068DAE1(LPD3DMATRIX, struct t_g_drv_0c *, struct fBGRA *, tBGRA *, tRGBA *);
extern void C_0068DBF4(tBGRA, fBGRA *, LPD3DMATRIX, struct t_g_drv_0c *, struct fBGRA *, tBGRA *, tRGBA *);
extern void C_0068DD1E(LPD3DMATRIX, struct t_g_drv_0c *, struct fBGRA *, tBGRA *, tRGBA *);
extern void C_0068DE75(tBGRA, fBGRA *, LPD3DMATRIX, struct t_g_drv_0c *, struct fBGRA *, tBGRA *, tRGBA *);
extern void C_0068DFF4(unsigned, int, struct tPolygonInfo *);
extern void C_0068E071(unsigned char, int, struct tPolygonInfo *);
extern void C_0068E0FD(unsigned, int, struct tPolygonInfo *);
extern void C_0068E1EF(void (*)(tRGBA *, struct t_ComplexBlendInfo *), struct t_ComplexBlendInfo *, int, struct tPolygonInfo *);
extern void C_0068E274(void (*)(struct t_dx_rend_vertex_20 *, tRGBA *), int, struct tPolygonInfo *);
extern void C_0068E2F9(void (*)(tBGRA *, struct t_dx_rend_vertex_20 *, tRGBA *), int, struct tPolygonInfo *);
extern void C_0068E39D(int, struct tPolygonInfo *);
extern void C_0068E4E3(unsigned, struct tPolygonInfo *);
extern void C_0068E565(tRGBA, struct tPolygonInfo *);
extern void C_0068E65B(struct fBGRA *, struct tPolygonInfo *);
extern void C_0068E735(struct tPolygonInfo *);
extern void C_0068E772(struct tPolygonInfo *);
extern void C_0068E7AF(struct t_dx_rend_vertex_20 *, struct t_light_5ac *);
extern void C_0068E7BE(struct t_dx_rend_vertex_20 *, struct t_light_5ac *);
extern void C_0068E7D2(struct t_dx_rend_vertex_20 *, struct t_light_5ac *);
extern void C_0068E7E6(struct t_dx_rend_vertex_20 *, struct t_light_5ac *);
extern void C_0068E87B(struct t_dx_rend_vertex_20 *, struct t_light_5ac *);
extern void C_0068E880(struct t_light_5ac *);
extern void C_0068E92D(struct tPolygonInfo *, struct t_light_5ac *);//GRAPHIC_0_60:PolyApplyLight
extern void C_0068EFCE(float, struct fBGRA *, tRGBA *);
extern void C_0068F079(float, float, struct fBGRA *, struct fBGRA *, tRGBA *);
extern void C_0068F0F8(float, int, struct tPolygonInfo *);
extern void C_0068F19E(float, float ,struct fBGRA *, int, struct tPolygonInfo *);
extern void C_0068F2D6(float, unsigned, int, struct tPolygonInfo *);
extern void C_0068F413(float, float, struct fBGRA *, unsigned, int, struct tPolygonInfo *);
extern void C_0068F557(struct fBGRA *, unsigned, int, struct tPolygonInfo *);
extern void C_0068F758(void *, struct tPolygonInfo *);//(callback)
extern void C_0068F7A0(struct t_instance_18 *);//instance:...
extern void C_0068F7BD(struct t_instance_8 *);//instance:...
extern struct t_instance_8 *C_0068F7EA(int);
extern void C_0068F839(struct t_instance_8 *);
extern struct t_instance_90 *C_0068F860(struct t_instance_18 *, struct t_instance_8 *);
//====---- from direct.cpp ----====
extern void C_0068F9AA(struct t_direct_FileList *);//direct:release?
extern struct t_direct_FileList *C_0068FBDC(int, const char *);
extern void C_0068FE4E(struct t_direct_20 **, struct t_direct_FileList *);
extern struct t_direct_20 **C_0068FE97(struct t_direct_FileList *);
extern void C_0068FF7B(struct t_direct_FileList *);
extern int C_006900FC(const char *, char *);//direct:change directory?
extern int C_006901DD(/*maybe not*/struct t_file_10 *, const char *, char *);
//====---- from plytopd.cpp ----====
extern int C_00690240(int);//plytopd:...
extern int C_00690270(int);//plytopd:...
extern void C_00691E8E(struct t_animationHeader *);
extern struct t_animationHeader *C_00691F03(int, int, int);//create ".A" object?
extern void C_00692020(int, int, struct t_plytopd_18 *, struct t_animationHeader *);//".A": set "root_coordinate"?
extern void C_0069210D(int, int, int, struct t_g_drv_0c *, struct t_animationHeader *);//".A": set RX,RY,RZ?
extern struct t_animationHeader *C_006921CE(struct t_file_10 *, const char *);
extern struct t_animationHeader *C_00692346(const char *);
extern int C_0069236E(struct t_animationHeader *, const char *);//".A": write file?
extern void C_00692412(float, struct t_animationHeader *);
extern int C_0069254C(const char *, const char *);
extern void C_00692CEE(struct tSkeleton *);
extern struct tSkeleton *C_00692E48(int);//plytopd:...
extern struct tSkeleton *C_00692EE1(struct t_file_10 *, const char *, const char *);
extern struct tSkeleton *C_006934F5(const char *, const char *);
extern void C_006937CD(struct t_rsd_08 *, struct tPolygonData *, struct t_aa0 *);//plytopd:set blend modes(2)?
extern void C_0069382E(struct tTexHeader *, struct tRenderState *);
extern void C_0069385D(struct t_rsd_74 *, int, struct tTexHeader **, struct tPolygonData *, struct t_aa0 *);//plytopd:texture related?
extern void C_00693902(const char *, struct tSkeleton *, struct t_rsd_74 *, struct t_aa0 *);
extern void C_00693E0D(int, struct tSkeleton *);
extern void C_00693FB5(struct t_plytopd_RSD *);
extern struct t_plytopd_RSD *C_00694156(struct t_file_10 *, const char *);//plytopd:parse "RSD" file?
extern void C_006946CD(struct t_plytopd_0c *);
extern struct t_plytopd_0c C_00694704(/*int *, */struct t_rsd_74 *, const char *);
extern int C_00694942(struct t_rsd_74 *, float, struct t_plytopd_RSD *);//plytopd:load TIM & PLY
extern void C_00694C80(int, int, struct tRenderState *);
extern void C_00695047(int, struct t_g_drv_0c *, struct t_g_drv_0c *, int, struct t_plytopd_PolygonDescriptor *, int, struct t_plytopd_MaterialDescriptor *, struct tPolygonData *);//plytopd:...
extern void C_00695945(struct t_plytopd_74 *);//plytopd:...
extern void C_006959D4(struct t_plytopd_e4 *);//plytopd:...
extern struct t_plytopd_e4 *C_00695A2B(int, struct t_local_plytopd_24 *, struct tSkeleton *, struct t_aa0 *);
extern void C_00695E6A(int, struct t_animationHeader *, struct t_plytopd_e4 *);
extern void C_00695EB8(int, int, int, struct t_plytopd_e4 *);
extern void C_00696214(float, struct t_plytopd_e4 *);
extern void C_006962A4(float, struct t_plytopd_e4 *);
extern struct t_plytopd_e4 *C_006968C4(int, int, struct t_local_plytopd_24 *, struct t_rsd_74 *, struct t_aa0 *);
extern void C_00696C96(struct tPolygonData *);//plytopd:set blend modes?
//====---- from tim.cpp ----====
extern void C_00696FBA(struct t_tim_info *);
extern struct t_tim_info *C_00697558(const char *);//tim:load TIM?
extern struct tTexHeader *C_00697652(int, int, int, int, struct t_tim_info *, const char *);//tim:...
extern struct tTexHeader *C_00698E80(struct t_tim_info *, const char *);//tim:...
//====---- from polygon.cpp ----====
extern void C_00699470(struct tPolygonData *);//polygon:free something?
extern void C_006997B6(struct tPolygonData *);//polygon:...
extern struct tPolygonData *C_006997C9(int, int);//polygon:alloc something?
extern void C_00699972(int, tRGBA *, struct t_g_drv_FTexCoord *, struct t_g_drv_0c *, struct t_g_drv_0c *, struct tPolygonData *);//polygon:...
extern void C_00699A7A(struct t_polygon_TriangleInfo *, struct tPolygonData *);//polygon:...
extern void C_00699E3F(struct tPolygonData *);
extern void C_0069A6CD(struct tPolygonData *);
extern void C_0069AF4F(float, struct tPolygonData *);//polygon:...
extern void C_00699B54(struct t_g_drv_0c *, struct tPolygonData *);//polygon:...
extern void C_00699BAA(struct tRenderState *, struct tPolygonData *);//polygon:...
extern void C_00699C00(struct t_g_drv_GroupInfo *, struct tPolygonData *);//polygon:...
extern void C_00699C56(struct tPolygonData *);//polygon:
extern struct tPolygonData *C_0069A028(struct t_file_10 *, int, const char *);//polygon:load "POLYGON FILE"
extern void C_0069A611(const char *, struct tPolygonData *);//polygon:write "POLYGON FILE"
//====---- from list.cpp ----====
extern struct t_list_List *C_0069B074(void (*)(void *));
extern void C_0069B0EA(struct t_list_List *);
extern struct t_list_List *C_0069B0B0(void (*)(void *));
extern void C_0069B131(struct t_list_List **);
extern int C_0069B14D(struct t_list_List *);//list:# of elements
extern void C_0069B16E(void *, struct t_list_List *);//list:add element(1)?//add to head?
extern void C_0069B1CF(void *, struct t_list_List *);
extern void C_0069B240(void *, struct t_list_List *);
extern void C_0069B2F7(int (*)(void *, void **), void **, struct t_list_List *);
extern void C_0069B361(int (*)(void *, void **), void **, struct t_list_List *);
extern void C_0069B3B0(void *);//list:(callback)
extern void *C_0069B3CB(int, int, struct t_list_List *);//list:serialize?
extern void *C_0069B493(int *, int (*)(void *, void *), void *, struct t_list_List *);
extern int C_0069B50D(int *, int (*)(void *, void *), void *, struct t_list_List *);//list:...?
extern void C_0069B56D(int (*)(void *, void *), void *, struct t_list_List *);//list:...?
extern int C_0069B647(void *, void *);//(callback)
//====---- ----====
extern void C_0069B660(const char *, struct t_aa0 *);//parse ".CFG" file?
extern void *C_0069BC10(int , int, void *);//kind of memset?
extern void *C_0069BCF8(int, int, void *);//kind of memsetdw?
extern void C_0069BD1A(int, void *, void *);//some "fast" memcpy?
extern void *C_0069BE5F(int fillColor, int, int, int, void *);//some bitblt(1)?[DWORD]
extern void *C_0069BEFB(int, int, int, int, void *, void *);//some bitblt(2)?
//====---- from light.cpp ----====
extern void C_0069BF90(tBGRA, struct fBGRA *);//light:...
extern void C_0069C032(tRGBA *, struct fBGRA *);//light:fBGRA to tRGBA?
extern void C_0069C11F(struct fBGRA *);
extern void C_0069C16A(struct fBGRA *, struct fBGRA *);//light:...
extern struct t_light_18_bis *C_0069C41F(struct t_g_drv_GroupInfo *, struct tPolygonData *);//light:...
extern void C_0069C5EE(struct t_light_5ac *);//light:...
extern void C_0069C69F(LPD3DMATRIX, struct t_light_5ac *);//light:...
extern void C_0069C6CF(int, struct t_light_5ac *);//light:...
extern struct t_light_5ac *C_0069CA53(struct t_g_drv_0c *, struct t_g_drv_0c *, struct t_g_drv_0c *, tBGRA, tBGRA, tBGRA, tBGRA);//light:...
//====---- from TexCache.cpp ----====
extern LPDIRECTDRAWSURFACE C_0069CD04(struct tTexHeader *, unsigned);//TexCache:GetByKey?
extern void C_0069CD26(void);//TexCache:clean?
extern bool C_0069CDD4(struct tTexHeader *, unsigned, LPDIRECTDRAWSURFACE);//TexCache:SetWithKey?
extern bool C_0069CE8E(struct tTexHeader *);//TexCache:release textures?
extern bool C_0069D279(unsigned someSize);//TexCache:release memory?
//====---- from trans.cpp ----====
extern void *C_0069F910(double, int, struct tTextureInfo *);//trans:...
extern void *C_0069FA43(int, struct tTextureInfo *);//trans:...
extern int *C_0069FB6C(int, struct tTextureInfo *);//trans:...
//====---- from dx_rend.cpp ----====
extern void C_0069FCD7(struct tPolygonInfo *);//dx_rend:release "struct tPolygonInfo"?
extern struct tPolygonInfo *C_0069FEB5(void);//dx_rend:allocate "struct tPolygonInfo"?
extern void C_006A21B0(void *);//(callback)clean list element
extern void C_006A21B5(struct tPolygonInfo *, struct t_aa0 *);//dx_rend:add element?
extern void C_006A21DF(struct tPolygonInfo *, struct t_aa0 *);//dx_rend:remove element
extern void C_006A239F(struct t_aa0 *);//dx_rend:init some global objects
extern void C_006A2631(struct t_aa0 *);//dx_rend:clean some global objects
extern void C_006A2736(struct tPolygonInfo *);//dx_rend:apply render state[2]
extern void C_006A2782(int, struct tRenderState *, struct tPolygonInfo *);//dx_rend:apply render state[1]
extern void C_006A27F4(struct tTransparentHeap *);//dx_rend:heap clean
extern struct tTransparentHeap *C_006A2823(int);//dx_rend:heap init
extern struct tTransparentElement *C_006A2865(struct tTransparentHeap *);//dx_rend:heap alloc
extern void C_006A28C0(struct tTransparentHeap *);//dx_rend:heap reset
//====---- from stack.cpp ----====
extern void C_006A28F0(struct tStack *);//stack:destroy
struct tStack *C_006A2924(int);//stack:create
extern void C_006A29E4(struct tStack *);//stack:push?
extern void *C_006A2A22(struct tStack *);//stack:pop?
extern void *C_006A2A73(struct tStack *);//stack:put?
//====---- from shp.cpp ----====
extern void C_006A2E34(struct t_shp_30 **);//shp:...
extern struct t_shp_30 *C_006A2E56(const char *, struct t_rsd_74 *);//shp:...
//====---- from dx_rend5.cpp ----====
extern void C_006A3280(struct t_aa0 *);
extern int C_006A3332(struct t_aa0 *);
extern int C_006A33BA(int, int, LPDIRECTDRAWSURFACE, LPDIRECT3DVIEWPORT2, struct t_aa0 *);
extern void C_006A34C8(struct tIndexedPrimitives *);
extern int C_006A3CCB(int, struct tMatrixInfo *, struct tRenderState *, struct t_g_drv_GroupInfo *, struct tPolygonData *, struct tPolygonInfo *, struct t_aa0 *);//dx_rend5:...
extern void C_006A479C(int, struct t_aa0 *);//dx_rend5:increment "ASYNC COUNT"
extern void C_006A47AE(int, struct t_list_List *, struct t_aa0 *);//dx_rend5:...
//====---- sort.cpp ----====
extern struct t_sort_20 *C_006A4F10(int, int);//sort:init?
extern int C_006A505E(struct t_sort_20 *);//sort:clean?
extern int C_006A510B(struct t_sort_20 *);//sort:...?
extern int C_006A51C1(struct t_sort_20 *, int, int, int);//sort:add node?
extern void C_006A5387(struct t_sort_20 *, void (*)(int, int));//sort:...?
//====---- from heap.cpp ----====
extern void C_006A5440(struct t_heap_3c *);//heap:destroy(recursive)
extern struct t_heap_3c *C_006A5498(int, int, int, int, void (*)(int, struct t_heap_3c *));//heap:create
extern struct t_heap_3c *C_006A5630(int, int, int);//heap:malloc something?
extern struct t_heap_3c *C_006A5659(int, int, int);//heap:calloc something?
extern void C_006A5686(struct t_heap_3c *);//heap:reset(recursive)?
extern void C_006A56C7(struct t_heap_3c *);//heap:...?
extern void *C_006A56F5(struct t_heap_3c *);//heap:new element
extern int C_006A584A(unsigned char *, struct t_heap_3c *);//heap:delete element
extern void *C_006A594D(int, struct t_heap_3c *);//heap:new elements
extern void C_006A5A70(int, struct tPalette *);
extern void C_006A5BA0(float, int, struct tPalette *);
extern void C_006A5C3B(float, float, struct fBGRA *, int, struct tPalette *);
extern void C_006A5CE2(struct fBGRA *, int, struct tPalette *);
//====---- from dx_pal.cpp ----====
extern int C_006A5E40(struct tPalette *, LPDIRECTDRAWSURFACE);
extern void C_006A5E8C(int paletteSize, int srcIndex, tRGBA *pSrc, int dstIndex, PALETTEENTRY *pDst);//dx_pal:palette copy(1)
extern void C_006A5F18(int, int, tRGBA *, int, struct fBGRA *);//dx_pal:palette copy(2)
extern void C_006A5FEB(int, int, tRGBA *, int, int *);//dx_pal:palette copy(3)
extern void C_006A604A(int, int, int, int *, tRGBA *, int *);//dx_pal:palette copy(4)
extern void C_006A609A(struct tPalette *);//dx_pal:clean "struct tPalette *"
extern struct tPalette *C_006A61AE(int, int, int, int, tRGBA *);//dx_pal:create "struct tPalette *"
//====---- from driver.cpp ----====
extern void C_006A6740(struct t_f0 *);//graphics.driver:release "struct t_f0 *"
extern struct t_f0 *C_006A675E(void);//graphics.driver:alloc "struct t_f0 *"
//====---- from dx_rendx.cpp ----====
extern void C_006A6790(struct tPolygonInfo *, struct t_aa0 *);//dx_rendx:...
//====---- from gl_code.cpp ----====
extern void C_006A6AE6(struct t_gl_code_0c *);//gl_code:clean some struct(size 0xc)
extern void C_006A6B92(void);//gl_code:CULL FACE/BACK
extern void C_006A6BAD(void);//gl_code:CULL FACE/FRONT
extern void C_006A6BC8(void);//gl_code:CULL FACE/OFF
extern void C_006A6C50(struct t_gl_code_450 *);//gl_code:clean?
extern struct t_gl_code_450 *C_006A6C9B(struct t_gl_code_0c *, struct t_aa0 *);//gl_code:"GL INIT ..."
extern void C_006A7157(struct t_gl_code_450 *);//gl_code:flush & swap buffers?
extern void C_006A71DF(void);
extern void C_006A71EF(void);
extern void C_006A71FF(float red, float green, float blue, float alpha, int, int);//gl_code: clear?
extern void C_006A7267(int);//gl_code:set dither on off
extern void C_006A728A(int);//gl_code:set depth test on/off
extern void C_006A72AD(int);//gl_code:set depth mask
extern void C_006A72C1(void);//gl_code:<almost empty>(1)
extern void C_006A72F6(void);//gl_code:<almost empty>(2)
extern void C_006A7325(struct t_gl_code_450 *);//gl_code:<almost empty>(3)
extern void C_006A736C(void);//gl_code:<almost empty>(4)
extern void C_006A739B(void);//gl_code: prepare blend?
extern void C_006A73D3(int);//gl_code:setTextureEnabled
extern void C_006A73F6(int);//gl_code:choose texture filter (linear/nearest)
extern void C_006A7457(int);
extern void C_006A7484(int);//gl_code: texture wrap s
extern void C_006A74B6(int);//gl_code: texture wrap t
extern void C_006A74E8(unsigned);//gl_code:deleteTexture
extern void C_006A74F9(int);//gl_code:bindTexture
extern unsigned C_006A753A(int, int, int, int, void *);//gl_code:createTexture
extern void C_006A768E(struct t_gl_code_14 *);//gl_code:free something?
extern struct t_gl_code_14 *C_006A772F(int);//gl_code:alloc something?
extern void C_006A77F7(int, int, tRGBA *, struct t_gl_code_14 *, struct t_gl_code_450 *);
extern void C_006A7928(int, int, int, int, tRGBA *, void *, struct tTextureObj *);//gl_code:changeTexturePalette
extern void C_006A7AC9(struct t_gl_code_08 *);//gl_code:free texture group?
extern struct t_gl_code_08 *C_006A7B47(int);//gl_code:alloc texture group?
extern int C_006A7B97(int, struct t_gl_code_08 *);//gl_code:get texture name?
extern void C_006A7BCB(int, int, struct t_gl_code_08 *);//gl_code:set texture name?
extern void C_006A7BF2(int, int, int, int, int, int, int, int, void *);//gl_code:swirl related?
extern void C_006A7DEE(int, unsigned short *, struct t_dx_rend_vertex_20 *, LPD3DMATRIX);//gl_code:draw triangles(1)?
extern void C_006A8002(int, unsigned short *, struct t_dx_rend_vertex_20 *, LPD3DMATRIX);//gl_code:draw triangles(2)?
extern void C_006A8242(int, unsigned short *, struct t_dx_rend_vertex_20 *);//gl_code:draw triangles(3)?
extern void C_006A83AE(int, unsigned short *, struct t_dx_rend_vertex_20 *);//gl_code:draw triangles(4)?
extern void C_006A8558(int, unsigned short *, struct t_dx_rend_vertex_20 *, LPD3DMATRIX);//gl_code:draw triangles(5)?
extern void C_006A87AC(int, unsigned short *, struct t_dx_rend_vertex_20 *, LPD3DMATRIX);//gl_code:draw triangles(6)?
extern void C_006A8A3E(int, unsigned short *, struct t_dx_rend_vertex_20 *);//gl_code:draw triangles(7)?
extern void C_006A8BFC(int, unsigned short *, struct t_dx_rend_vertex_20 *);//gl_code:draw triangles(8)?
extern void C_006A8DF8(unsigned short *, int, struct t_dx_rend_vertex_20 *);//gl_code:draw lines(1)?
extern void C_006A8ECD(unsigned short *, int, struct t_dx_rend_vertex_20 *);//gl_code:draw lines(2)?
//====---- from registry.cpp ----====
extern void C_006A9060(struct t_registry_04 *);//file.registry:clean?
extern struct t_registry_04 *C_006A908C(void (*)(void *));//file.registry:create?
extern int C_006A90F5(void *, int (*)(void *, void *), struct t_registry_04 *);
extern void *C_006A9132(int, void *, int (*)(int, void *, void *), struct t_registry_04 *);//TODO;file.registry:...
extern void C_006A918B(void *, struct t_registry_04 *);
extern void C_006A91A8(void *, struct t_registry_04 *);//TODO;file.registry:remove element?
extern void C_006A91C5(int (*)(void *, void **), int *, struct t_registry_04 *);
//====---- from dx_view.cpp ----====
extern void C_006A91F0(struct t_aa0 *);//dx_view:clean(1)?
extern void C_006A9252(struct t_aa0 *);//dx_view:init(1)?
extern void C_006A93FA(LPD3DVIEWPORT, struct t_aa0 *);//dx_view:viewport reset(1)?
extern void C_006A9423(LPD3DVIEWPORT, struct t_aa0 *);//dx_view:set something(1)?
extern void C_006A9466(struct t_aa0 *);
extern void C_006A9506(struct t_aa0 *);//dx_view:init(2)?
extern void C_006A9683(LPD3DVIEWPORT2, struct t_aa0 *);//dx_view:viewport reset(2)?
extern void C_006A96AC(LPD3DVIEWPORT2, struct t_aa0 *);//dx_view:set something(2)?
//====---- ----====
extern struct t_f0 *C_006A9B60(struct t_aa0 *);
extern struct t_f0 *C_006A9DF0(struct t_aa0 *);
extern struct t_f0 *C_006AA080(struct t_aa0 *);
extern void C_006AAD17(int, int, int, int, int, struct t_aa0 *);
extern void C_006AAA86(int, int, int, int, int, struct t_aa0 *);
//====---- from dx_mesh.cpp ----====
extern void C_006B27A9(LPD3DMATRIX, struct tIndexedPrimitives *, struct tPolygonInfo *, struct tRenderState *, struct t_g_drv_GroupInfo *, struct t_ComplexBlendInfo *, struct t_aa0 *);
//====---- ----====
extern void C_006B3CA0(struct tBlendModeInfo *, struct tRenderState *);//convert "struct tBlendModeInfo *" to "struct tRenderState *"?
extern struct tBlendModeInfo *C_006B3CE7(int, struct t_aa0 *);//get "struct tBlendModeInfo *"
//====---- from token.cpp ----====
extern int C_006B35D0(char, const char *);//token:count char in string
extern int C_006B362E(char, const char *);//token:first char in string?
extern int C_006B368B(int, const char *);//token:some hash?
extern float C_006B3745(const char *);//token:calls "atof"?
extern int C_006B375C(const char *);//token:calls "atoi"?
extern void C_006B376D(struct t_token_14 *);//token:release?
extern struct t_token_14 *C_006B37B7(void (*)(int, char*), struct t_file_10 *, const char *);//token:alloc?
extern struct t_token_14 *C_006B39CE(void (*)(int, char*), const char *);//token:alloc(2)?
extern int C_006B39FA(int, struct t_token_14 *);//token:get integer?
extern float C_006B3A3A(int, struct t_token_14 *);//token:get float?
extern char *C_006B3A7A(int, struct t_token_14 *);//token:get token?
extern void C_006B3AB1(int, char *);//(callback)
extern char *C_006B3B3E(void (*)(int, char*), int *, const char *);//token:...?
//====---- from gl.cpp ----====
extern struct t_gl_code_14 *C_006B3D27(struct tPalette *);
extern void C_006B418B(int, int, int, struct t_aa0 *);//GRAPHIC_3_14:Clear
extern void C_006B4AF2(struct tRenderState *, struct t_aa0 *);//GRAPHIC_3_68:SetRenderState
extern void C_006B57B8(struct tPolygonInfo *, struct t_aa0 *);//GRAPHIC_3_78?
//====---- end of FF7 Library ----====

//====---- from MENU/COMBAT ... hard to tell put let's put them here ----====
extern unsigned char D_00DC0E6C;//pause related?
extern unsigned char D_00DC0E70;
//====---- from FIELD ----====
extern short D_00CBF9DC;//current game state?
extern short D_00CC0828;
extern void *D_00CC08F0;
extern int D_00CC0D80;
extern short D_00CC0D84;//some previous game state
extern struct t_main_infos D_00CC0D88;
//====---- ----====

#endif
