#ifndef __FIELD_DATA_H__
#define __FIELD_DATA_H__

////////////////////////////////////////
#define MK_UWORD(arr,index) ((((arr)[(index) + 1] << 8) & 0xff00) | ((arr)[(index)] & 0x00ff))
#define SPLIT_UWORD(dst,index,src) (dst)[(index)] = (src) & 0xff; (dst)[(index)+1] = ((src) >> 8) & 0xff

#define CURINDEX (D_00CC0CF8[D_00CC0964])
#define CURSCRIPT ((unsigned char *)D_00CBF5E8 + CURINDEX)
//one ugly macro(for C_0060F750.cpp && C_0060B9D0.cpp)
#define MK_SCRIPT_INDEX(dst,ent,scrindex,local_1) \
	local_1 = D_00CBF5E8->f_06 * 4; \
	(dst) = ((unsigned char*)(D_00CBF5E8 + 1))[D_00CBF5E8->f_02 * 8 + (ent) * 0x40 + (scrindex) * 2 + (local_1)]; \
	(dst) |= (D_00CBF5E8->f_02 * 8 + (ent) * 0x40 + (unsigned char*)(D_00CBF5E8 + 1) + (scrindex) * 2)[(local_1) + 1] << 8
////////////////////////////////////////
struct t_main_88 {//size 0x88
	/*00*/short f_00;//0CC1670
	/*02*/short f_02;//0CC1672
	/*04*/unsigned char *f_04;//eye states//0CC1674
	/*08*/char f_08;//0CC1678
	/*09*/char __09[1];//0CC1679
	/*0a*/short f_0a;//eye blink counter?//0CC167A
	/*0c*/int f_0c,f_10,f_14;//x,y,z?//0CC167C,0CC1680,0CC1684
	/*18*/int f_18,f_1c,f_20;//0CC1688,0CC168C,0CC1690
	/*24*/char __24[8];//0CC1694
	/*2c*/int f_2c;//0CC169C
	/*30*/short f_30;//length?//0CC16A0
	/*32*/short f_32;//phase?//0CC16A2
	/*34*/char __34[1];//0CC16A4
	/*35*/unsigned char f_35;//some angle//0CC16A5
	/*36*/unsigned char f_36;//some angle//0CC16A6
	/*37*/unsigned char f_37;//0CC16A7
	//-- "TURN" --
	/*38*/unsigned char f_38;//0CC16A8
	/*39*/unsigned char f_39;//length?//0CC16A9
	/*3a*/unsigned char f_3a;//phase?//0CC16AA
	/*3b*/unsigned char f_3b;//state?0CC16AB
	/*3c*/short f_3c,f_3e;//start,end?//0CC16AC,0CC16AE
	//-- "OFST" --
	/*40*/int f_40; short f_44,f_46;//0CC16B0,0CC16B4,0CC16B6
	/*48*/int f_48; short f_4c,f_4e;//0CC16B8,0CC16BC,0CC16BE
	/*50*/int f_50; short f_54,f_56;//0CC16C0,0CC16C4,0CC16C6
	/*58*/unsigned short f_58;//0CC16C8
	/*5a*/unsigned short f_5a;//0CC16CA
	/*5c*/unsigned char f_5c;//0CC16CC
	//-- --
	/*5d*/unsigned char f_5d;//entity index for triggers?//0CC16CD
	/*5e*/char bPerformTrigger;//0CC16CE
	/*5f*/char f_5f;//"SOLID"?//0CC16CF
	/*60*/char bENTERTriggered;//0CC16D0
	/*61*/char f_61;//0CC16D1
	/*62*/char f_62;//0CC16D2
	/*63*/char bControlType;//0CC16D3
	/*64*/char f_64;//0CC16D4
	/*65*/char __65[1];//0CC16D5
	/*66*/short f_66;//0CC16D6
	/*68*/short f_68;//0CC16D8
	/*6a*/short f_6a;//0CC16DA
	/*6c*/short f_6c;//0CC16DC
	/*6e*/short f_6e;//0CC16DE
	/*70*/short f_70;//0CC16E0
	/*72*/unsigned short f_72;//0CC16E2
	/*74*/unsigned short f_74;//0CC16E4
	/*76*/unsigned short f_76;//0CC16E6
	/*78*/unsigned short f_78;//some walkmesh indice?//0CC16E8
	/*7a*/unsigned short f_7a;//0CC16EA
	/*7c*/int f_7c,f_80,f_84;//0CC16EC,0CC16F0,0CC16F4
};

struct t_script_190 {//size 0x190
	unsigned char f_000;
	char __001[3];
	int f_004;
	int f_008;
	int f_00c;
	int f_010;
	int f_014;
	short f_018;
	short f_01a;
	unsigned short f_01c;
	char __01e[2];
	char f_020;//character id?
	char f_021;
	unsigned short f_022;//# of objects in f_024/f_17c
	int f_024[0x50];
	int f_164;
	int f_168;
	int f_16c;
	int f_170;
	unsigned short f_174;
	char __176[2];
	struct t_plytopd_e4 *f_178;
	struct t_animationHeader **f_17c;
	struct tRenderState *f_180;
	struct tRenderState *f_184[3];
};

struct t_local_zzz_20 {
	int f_00;
	int f_04;
	int f_08;
	float f_0c;
	float f_10;
	float f_14;
	float f_18;
	float f_1c;
};

//looks a lot like struct t_z_30?
struct t_addraw_30 {
	/*00*/unsigned f_00;
	/*04*/unsigned f_04;
	//-- palette related? --
	/*08*/unsigned short *lpwPalette;
	/*0c*/unsigned f_0c;//size of data in f_08 (+ 0xc)
	/*10*/short f_10,f_12;
	/*14*/unsigned short wPaletteSize,wPaletteCount;
	//-- --
	/*18*/char __18[4];
	/*1c*/void *f_1c;
	/*20*/unsigned f_20;
	/*24*/short f_24;
	/*26*/short f_26;
	/*28*/unsigned short f_28,f_2a;//wWidth,wHeight
	/*2c*/char __2c[4];
};

struct t_field_4b8 {//size 0x4b8
	int f_00;
	int f_04;
	int f_08[0x64][3];
};

//struct t_local_script_18
struct t_local_field_RaindropInfo {//size 0x18
	/*00*/struct SVECTOR f_00;//0CC0EC8
	/*08*/struct SVECTOR f_08;//0CC0ED0
	//
	/*10*/short f_10;//counter//0CC0ED8
	/*12*/short f_12;//x,y related//0CC0EDA
	/*14*/short f_14;//z related//0CC0EDC
	/*16*/short wActive;//0CC0EDE
};

//struct t_local_script_yyy
struct t_local_field_Raindrop {//size 0x12
	/*00*/struct t_dx_sfx_e0 *f_00;
	/*04*/char f_04,f_05,f_06;//set but never read//0CFFEE4,0CFFEE5,0CFFEE6
	/*07*/char __07[3];
	/*0a*/short wX0,wY0;//0CFFEEA,0CFFEEC
	/*0e*/short wX1,wY1;//0CFFEEE/0CFFEF0
};

//struct t_ad_data___1
struct t_ad_data_CAM_info {//size 0x28
	//-- matrix --
	unsigned short f_00[3][3];//rot
	char __12[2];//padding?seems to contain f_00[2][2]
	unsigned f_14[3];//trans
	//-- --
	short f_20,f_22;
	short f_24;
	char __26[2];//contains some flag?
};

//struct t_field_10
struct t_field_ShineFXLightInfo {//size 0x10
	/*00*/struct SVECTOR f_00;
	/*08*/tBGRA f_08;
	/*0c*/tBGRA f_0c;
};

struct t_field_d0 {//size 0xd0
	/*00*/int f_00;//00CC2280
	/*04*/float f_04;//clipping near?//00CC2284
	/*08*/int f_08[0x12];//model y patch offset?//00CC2288
	/*50*/int f_50[0x12];//model z patch offset?//00CC22D0
	/*98*/int f_98;//00CC2318
	/*9c*/int f_9c;//00CC231C
	/*a0*/int f_a0;//00CC2320
	/*a4*/int f_a4;//00CC2324
	/*a8*/char f_a8[0x12];//model on/off?//00CC2328
	/*ba*/unsigned char f_ba;//00CC233A
	/*bb*/char __bb;//00CC233B
	/*bc*/int f_bc;//inflated size of field file?//00CC233C
	/*c0*/struct fBGRA f_c0;//"clear" color//00CC2340
};

//struct t_field_x_0c_new
struct t_field_Line {//size 0xc
	/*00*/short wX0,wY0,wZ0;
	/*06*/short wX1,wY1,wZ1;
};

//automatic door?
struct t_field_x_10 {//size 0x10
	/*00*/struct t_field_Line f_00;
	/*0c*/unsigned char f_0c;
	/*0d*/unsigned char f_0d;
	/*0e*/unsigned char f_0e;
	/*0f*/unsigned char f_0f;
};

//exit?
struct t_field_x_18_new {//size 0x18
	/*00*/struct t_field_Line f_00;
	/*0c*/short f_0c;
	/*0e*/short f_0e;
	/*10*/short f_10;
	/*12*/unsigned short f_12;
	/*14*/unsigned char f_14;
	/*15*/char __15[3];
};

//event?
struct t_field_x_18 {//size 0x18
	/*00*/struct t_field_Line f_00;
	/*0c*/char bActive;//[sometines unsigned too]?
	/*0d*/char f_0d;//entity index for triggers?
	/*0e*/unsigned char bTrigger_4;
	/*0f*/unsigned char bTrigger_3;
	/*10*/unsigned char bTrigger_2;
	/*11*/unsigned char bTrigger_1;
	/*12*/unsigned char bTrigger_5;
	/*14*/unsigned char bTrigger_6;
	//-- --
	/*14*/unsigned char f_14;//some angle
	/*15*/unsigned char f_15;
	/*16*/unsigned char f_16;//"SLIP"
	/*17*/char __17[1];
};

//entry 7(.inf)
struct t_ad_bk_temp_xxx {//size 0x2e4
	/*00*/char __00[9];//file name
	/*09*/char f_09;
	/*0a*/short f_0a;
	/*0c*/short f_0c,f_0e,f_10,f_12;//some rectangle(x0,y0,x1,y1)?
	/*14*/unsigned char f_14;
	/*15*/char __15[3];
	/*18*//*unsigned */short f_18,f_1a;
	/*1c*//*unsigned */short f_1c,f_1e;
	//
	/*20*/short f_20,f_22;
	/*24*/short f_24,f_26;
	/*28*/short f_28,f_2a;
	/*2c*/short f_2c,f_2e;
	/*30*/char __30[8];
	/*38*/struct t_field_x_18_new f_38[0xc];//exits
	/*158*/struct t_field_x_10 f_158[0xc];
	/*218*/unsigned char f_218[0xc];
	/*224*/int f_224[0xc][4];
};

struct t_ad_bk_4 {
	short f_00;
	unsigned short f_02;
};

struct t_adimage_temp_10 {//size 0x10
	/*00*/int f_00;//some index?//0CFF768
	/*04*/unsigned short f_04;//z?depth?//0CFF76C
	/*06*/short wX,wY;//[unused]?//0CFF76E/0CFF770
	/*0a*/char __0a[0x10 - 0x0a];//0CFF772
};

struct t_ad_data_40c {//size 0x40c
	int f_000;
	int f_004[0x100];
	int f_404;
	int f_408;
};

//palette entry?
struct t_ad_data_0c {//size 0xc
	/*00*/unsigned short w16bColor;//16-bit color?
	/*02*/unsigned char cRed,cGreen,cBlue,cAlpha;
	//
	/*06*/unsigned char bType;//(0=black,1=w/alph,2=normal,3=black w/alpha)
	/*07*/unsigned char f_07;
	/*08*/int f_08;
};

struct t_ad_Palette {//size 0xc
	/*00*/struct t_ad_data_0c *f_00;
	/*04*/unsigned short wPaletteCount;
	/*06*/unsigned short wPaletteSize;
	/*08*/unsigned short f_08;
	/*0a*/unsigned short wType;
};

//palette info for tile map
struct t_ad_data_1c {//size 0x1c
	/*00*/struct tTexHeader *f_00;
	/*04*/unsigned char *f_04;//data
	/*08*/struct t_dx_sfx_e0 *f_08;
	/*0c*/int dwActive;
	/*10*/int f_10;
	/*14*/int f_14;
	/*18*/unsigned short wDoubleSize;
	/*1a*/unsigned short wBytePerPixel;
};

struct t_ad_data_105c {//size 0x105c
	/*0000*/short wX,wY;
	/*0004*/float fZ;
	/*0008*/unsigned short f_0008;
	/*000a*/unsigned short f_000a;
	/*000c*/short f_000c;
	/*000e*/short f_000e;
	/*0010*/float fU,fV;
	/*0018*/unsigned short wTexX,wTexY;
	/*001c*/RECT f_001c;
	/*002c*/unsigned short f_002c;
	/*002e*/unsigned short f_002e;
	/*0030*/unsigned short wPalette;
	/*0032*/unsigned short wDepth;
	/*0034*/unsigned char bBGIndex;//(0 means none)
	/*0035*/unsigned char bBGMask;
	/*0036*/char __0036[2];
	//---------------------------
	//-- used by ad_image only --
	//color rectangles info?
	/*0038*/struct {//size 0x10
		unsigned short f_00,f_02;//x,y related?
		char __04[2];
		unsigned char f_06;
		char __07[1];
		unsigned short f_08;
		unsigned short f_0a;
		char __0c[4];
	} f_0038[0x100];
	/*1038*/unsigned short f_1038;//count elements in f_0038
	/*103a*/char __103a[2];
	//--                       --
	//---------------------------
	/*103c*/int f_103c;//flag for texture?
	/*1040*/int f_1040;//unused flag?dirty?
	/*1044*/int f_1044;//unused flag?dirty?
	/*1048*/int f_1048;//unused flag?dirty?
	/*104c*/int f_104c;
	/*1050*/int f_1050;
	/*1054*/unsigned short wMode;
	/*1056*/unsigned short wTexture_1;
	/*1058*/unsigned short wTexture_2;
	/*105a*/unsigned short wPage;
};

//cached light info
struct t_field_7534 {//size 0x7534
	/*00*/int f_00;//set to 1 but never read
	/*04*/int f_04[25/*0x19*/][300/*0x12c*/];
};

//some quad info
struct t_script_4c {//size 0x4c
	/*00*/struct t_dx_sfx_e0 *f_00;
	/*04*/float fX0,fY0;
	/*0c*/float fX1,fY1;
	/*14*/float fX2,fY2;
	/*1c*/float fX3,fY3;
	/*24*/float fU0,fV0;
	/*2c*/float fU1,fV1;
	/*34*/float fU2,fV2;
	/*3c*/float fU3,fV3;
	/*44*/float fZ;
	/*48*/int dwPalette;
};

//eye texture information
struct t_ad_obj_14 {
	int f_00;//I think it's a "char"
	char *f_04;
	char *f_08;
	char *f_0c;
	char *f_10;
};
////////////////////////////////////////
extern void C_0060B2C6(void);
extern int C_0060B9D0(const char *);//load ".ate" file?
extern void C_0060BACF(struct t_main_88 *);//"Init Event!"?
extern void C_0060BB58(void);
extern void C_0060D4C5(struct t_aa0 *, struct t_rsd_74 *);//from script engine?
extern void C_0060D4F3(void);//manage 2d infos(hand, arrows)?
extern void C_0060D549(void);//manage 2d infos(hand, arrows)[flag only]?
extern void C_0060DAD4(struct t_aa0 *);//ad_app:...?
extern int C_0060E96C(struct t_aa0 *);//another "FIELD[UPDATE]"?
extern void C_0060ED8A(int, int);
extern void C_0060EEA1(struct t_aa0 *);//(function for debug?)
extern void C_006137BD(void);
extern void C_0062086B(void);
extern void C_0062091B(void);//ad_data:...
extern void C_00620B20(void);//ad_data:clean current map?
extern void C_00620BDD(const char *);//ad_data:set path
extern int C_00620DB6(void);//ad_data:read MAPLIST?
extern void C_00620F24(void);//ad_data:clean?
extern int C_00620F54(unsigned short, char *);//ad_data:get map name?
extern void C_006211FF(void);
extern int C_0062120E(void);//ad_data:...
extern float C_00623C0F(struct MATRIX *, int, int, int );//ad_data:...
extern int C_0062B6F1(void);//ad_data:read map file?(called by FIELD[START])
extern void C_0062D3AE(void);//ad_image:...
extern int C_0062EC38(unsigned short, unsigned short, short, short, int, unsigned short);//ad_image:...
extern int C_0062F9D2(void *);//ad_image:...
extern int C_0062FAE3(void *);//ad_image:...
extern void C_006303A0(struct t_aa0 *, struct t_rsd_74 *);//ad_image:...
extern int C_00630734(const char *);//ad_cdr:open?
extern void *C_006308CA(int);//ad_cdr:get entry?
extern void C_006308F0(void);//ad_cdr:close?
extern void C_0063092A(const char *bp08, int bp0c);//ad_cdr:<empty>
extern void C_00630940(void);//reset offset to strings(1)
extern void C_006309AA(void);//reset offset to strings(2)
extern void C_006309E4(short);
extern int C_00633691(short);
extern void C_00633909(short, short);
extern void C_006339C0(void);//ad_human:init?
extern void C_00633A29(void);//ad_human:clean?
extern void C_00633C2F(void);//ad_human:initialize walkmesh?
extern int C_00630B3D(short);
extern void C_00630BC3(short, short, short);
extern void C_00630BEA(void);
extern void C_00630C48(short, short, short, short, short);
extern void C_00630CF4(short, short, short);
extern void C_00630D39(short, short);
extern int C_00630D50(unsigned char, unsigned char);
extern int C_006310A1(unsigned char, unsigned char, unsigned char, unsigned char, short *);
extern void C_006342C6(int);//ad_human:...
extern void C_00636284(void);//ad_human:check triggers?
extern short C_00636500(unsigned char);//ad_human:scos
extern unsigned char C_00636515(struct VECTOR *, struct VECTOR *, int *);
extern void C_00637D35(struct t_main_88 *, struct t_field_x_18 *);//ad_human:...
extern void C_00637E88(struct t_field_x_18 *bp08);//ad_human:...
extern void C_00638420(struct t_field_x_10 *);//ad_human:...
extern void C_00638801(struct t_aa0 *);
extern void C_006388EE(struct t_aa0 *);
extern int C_00638BAB(struct t_script_190 *, int);
extern struct t_animationHeader *C_00638DAD(struct t_rsd_74 *, const char *);
extern struct t_plytopd_e4 *C_00638F48(int, struct t_animationHeader *, struct t_rsd_74 *, struct t_aa0 *, const char *, const char *);
extern void C_006390D5(LPD3DMATRIX);
extern void C_00639157(struct t_aa0 *);
extern void C_006392BB(void);
extern void C_00639CAB(struct t_dx_sfx_e0 *, float, float, float, float, float, float, float, int, float, float, int);
extern void C_0063A171(struct t_script_4c *);//draw some quad?
extern void C_0063A34A(int, int, tRGBA *, int);
extern void C_0063A4C8(void);
extern void C_0063AA30(int);//tutaddr:...?
extern void C_0063ABC8(void);//tutaddr:...
extern void C_0063AC66(struct t_aa0 *);//___:init
extern void C_0063AD47(void);
extern void C_0063AD97(struct t_aa0 *);//___:refresh
extern void C_0063B84B(void);
extern int C_0063BC9D(void);
extern void C_0063BDA8(void);
extern int C_0063C17F(void);
extern void C_0063CF72(void);//ad_obj:...?
extern void C_0063CFA2(const char *);//ad_obj:set path
extern int C_0063D322(const char *);//ad_obj:...
extern int C_0063D993(const char *);//ad_obj:...
extern void C_0063E1D8(void);//ad_obj:...
extern int C_0063F494(void);//ad_tile:...
extern int C_0063E4EB(struct t_rsd_74 *, struct t_aa0 *);//ad_obj:...
extern void C_0063F635(void);//ad_tile:...
extern void C_0063F707(void);//ad_tile:...
extern void C_00640160(void);//ad_tile:some reset?
extern void C_00640213(struct t_aa0 *, unsigned short, unsigned short);//ad_tile:render BG tiles?
extern int C_00640292(struct t_aa0 *, struct t_rsd_74 *);//ad_tile:"field_load_textures"
extern void C_00640EB7(void);//ad_tile:...
extern int C_00640F22(short, short);//ad_tile:...
extern void C_0064176A(struct t_aa0 *);//ad_ddraw:init?
extern void C_006417D6(void);//ad_ddraw:clean?
extern int C_0064195B(struct t_aa0 *);//ad_ddraw:...
extern int C_006419C7(void);//ad_ddraw:"flip"
extern int C_006419E8(LPDIRECTDRAWSURFACE, void **, unsigned *);//ad_ddraw:Lock
extern int C_00641A43(LPDIRECTDRAWSURFACE);//ad_ddraw:Unlock
extern int C_00641A5E(struct t_addraw_30 *, unsigned short);//ad_ddraw:...
extern int C_00642629(LPDIRECTDRAWSURFACE, LPDIRECTDRAWSURFACE, LPRECT, LPRECT, long, LPDDBLTFX);//ad_ddraw:Blt
extern int C_006426A0(LPDIRECTDRAWSURFACE, LPDIRECTDRAWSURFACE, LPRECT, LPRECT, long);//ad_ddraw:BltFast
extern void *C_006427B6(int, int);//ad_ddraw:create some buffer
extern void C_00642DD0(void);//ad_bk:some cleaning?
extern void C_00642FC4(void);
extern void C_0064309C(void);//ad_bk:<empty>
extern int C_006430A4(int, int, int, int);//ad_bk:line?
extern int C_006430F2(int, int, int, int);//ad_bk:smooth?
extern int C_0064314F(struct SVECTOR *, struct SVECTOR *);//ad_bk:calc_3to2?
extern void C_006431BB(struct t_ad_bk_AxisShakeInfo *);//ad_bk:refresh "struct t_ad_bk_AxisShakeInfo *"
extern void C_0064341C(void);//ad_bk:check_scroll_event?
extern void C_006439AF(void);//ad_bk:...
extern void C_00643D22(void);//ad_bk:do_scroll_event?
extern void C_00644075(void);//ad_bk:update bk, models x,y?
extern void C_00644A80(struct t_aa0 *, struct t_rsd_74 *);
extern void C_00644B43(void);
extern void C_00644CEC(struct MATRIX *);
extern void C_00644E90(void);
extern void C_00644EB2(void);
extern void C_00644EE7(void);
extern int C_00645150(struct t_plytopd_e4 *, unsigned char *);
extern void C_00646310(void);
extern void C_0064631F(void);
extern void C_0064637B(unsigned short);
extern int C_006463F0(void);//ad_list:init
extern void C_00646449(void);//ad_list:clean?
extern void C_00646479(void);//ad_list:reset
extern void C_006464BA(float, float, float, float, float, int, int);//ad_list:add element
extern void C_006465FB(void);//ad_list:render
extern short C_006470E0(unsigned short, int);//ad_pal:convert 555 to ...(1)?
extern short C_00647252(unsigned short, int);//ad_pal:convert 555 to ...(2)?
extern void C_00647500(void);//ad_pal:...
extern int C_00647530(unsigned short, unsigned short, unsigned short*, int);//ad_pal:...
extern int C_00648828(unsigned short, unsigned short, unsigned  short *, int);//ad_pal:...
extern void C_00648C37(void);//ad_pal:clean?
extern short C_00648E1C(unsigned short, unsigned short, int, int);//ad_pal:...
extern void C_00648FAD(int *, void *);//ad_pal:...
extern void C_00649111(int *, void *);//ad_pal:...
extern void C_006496E0(void);
extern void C_00649697(void);//ad_pal:...
extern void C_006496BB(void);//ad_pal:...
extern void C_00649770(void);//field input reset?
extern int C_006499F7(short *, short *);//pad_read
extern void C_00649B30(struct VECTOR *, int, int, int);
extern int C_00649B50(struct t_script_190 *, unsigned char *);
extern void C_00649E1F(struct VECTOR *, struct VECTOR *, struct VECTOR *);//cross product(=newpeople.OuterProduct0)?
extern void C_00649E9A(unsigned short, int *, short *, short *, int *);
extern void C_00649F0A(unsigned short, unsigned short *);
extern void C_00649F25(unsigned short *, unsigned char, unsigned char);
extern void C_00649F46(struct VECTOR *, struct SVECTOR *, struct SVECTOR *);//some vector diff?
extern int C_00649F8A(struct VECTOR *, struct VECTOR *, struct VECTOR *, struct SVECTOR *);//[=koku.calc_z_pos]
extern int C_0064A070(int, struct t_plytopd_e4 *, unsigned char *, struct SVECTOR, int, int *);
extern void C_0064B090(void *, struct tPolygonInfo *);
extern void C_0064B0EE(void *, struct tPolygonInfo * /*TO CHECK*/);
extern void C_0064B14E(void *, struct tPolygonInfo *);
extern void C_0064B15C(void *, struct tPolygonInfo *);
extern void C_0064B563(void *, struct tPolygonInfo *);
extern void C_0064B95C(struct tSkeleton *, struct t_aa0 *);//transparency effect?
extern void C_0064BAB9(struct t_plytopd_e4 *, short, short, short, short, int);
extern void C_0064C364(void *, struct tPolygonInfo *);
extern void C_0064CA47(void *, struct tPolygonInfo *);
extern int C_0064D2E6(struct t_ad_obj_14 *, struct t_script_190 *);
extern void C_0064D4F6(struct t_script_190 *);
extern void C_0064DA3B(struct MATRIX *, struct t_field_x_18_new *);//2d infos:draw exits?
extern int C_0064E0C0(struct t_plytopd_e4 *, unsigned char *);
extern int C_0064E1B0(struct t_plytopd_e4 *, struct t_field_4b8 *, struct SVECTOR, unsigned char *);
extern int C_0064E940(struct t_plytopd_e4 *, struct t_field_4b8 *, unsigned char *, int, int, short *);
extern int C_0064EB50(struct t_plytopd_e4 *, struct t_field_4b8 *, unsigned char *);
extern int C_0064EC60(struct tSkeleton *, unsigned char *);
extern int C_0064EEE0(struct tSkeleton *, unsigned char *);
extern int C_0064EFC0(struct tSkeleton *, unsigned char *);
extern int C_0064F420(struct tSkeleton *, unsigned char *);
extern int C_0064F860(struct tSkeleton *, short, short, short);
extern void C_0064FA20(int, int, int, tBGRA *, tBGRA *);
extern int C_0064FB20(struct t_plytopd_e4 *, struct t_field_ShineFXLightInfo *, unsigned char *, int, int, int);
extern int C_0065019E(struct t_plytopd_e4 *, struct t_field_ShineFXLightInfo *, unsigned char *, int, short *);
////////////////////////////////////////
extern unsigned char D_009059A0[];//random related?
extern unsigned char D_00905AA0[];
extern int D_00905AD0;//from ad_app.cpp
extern int D_00905AD4;
extern int D_00905AD8;//release flag?
extern int D_00905ADC;
extern unsigned D_00906A70;
extern short D_00908E30[][2];
extern struct t_local_zzz_20 D_00909248[];
////////////////////////////////////////
extern unsigned char *D_00CBF578[];
extern unsigned char D_00CBF588;
extern short D_00CBF590[];
extern short D_00CBF5C0[];
extern short D_00CBF5E0[];
extern struct t_script_20 *D_00CBF5E8;//".ate" file entry #0?
extern short D_00CBF5F0[];
extern unsigned char D_00CBF600[];
extern short D_00CBF630[];
extern char D_00CBF6B8;
extern unsigned short D_00CBF6C0[][8];
extern char D_00CBF9C0;
extern /*unsigned */char D_00CBF9C8[/*0x10*/];
extern struct t_main_infos *D_00CBF9D8;
extern short D_00CBF9DC;//current game state?
extern unsigned char D_00CBF9E8[][8];
extern char D_00CBFB68;
extern char  D_00CBFB6C;
extern unsigned char D_00CBFB70[];
extern unsigned char D_00CBFBA0[][0x10];
extern unsigned char D_00CBFBE0[][8];
extern short D_00CBFC00[];
extern unsigned short D_00CBFC08[][0x10];

extern char D_00CC040C;
extern short D_00CC0410;
extern short D_00CC0414;
extern short D_00CC0418[];
extern char D_00CC0428[][0x100];
extern short D_00CC0828;
extern unsigned char D_00CC0830[];
extern unsigned char D_00CC0860;
extern short D_00CC0868[];
extern unsigned char D_00CC0870;
extern unsigned char D_00CC0878[];
extern unsigned char D_00CC0888;
extern short D_00CC088C;
extern unsigned char D_00CC0890;//current script opcode
extern unsigned char D_00CC0894;
extern char D_00CC0898;
extern short D_00CC08A0[][8];
extern void *D_00CC08E8;
extern unsigned char D_00CC08EC;
extern void *D_00CC08F0;
extern unsigned short D_00CC0900[];
extern unsigned char D_00CC0960[];
extern unsigned char D_00CC0964;//current script/entity index
extern char D_00CC0970;
extern short D_00CC0974;
extern unsigned char D_00CC0980[];
extern unsigned char D_00CC0990;
extern unsigned char D_00CC0998[];
extern unsigned char D_00CC09B0[][8];
extern unsigned char D_00CC0B30[];
extern struct t_main_88 *D_00CC0B60;
extern char D_00CC0B64;
extern char D_00CC0B68;
extern short D_00CC0B70;
extern unsigned char D_00CC0B78[][8];

extern unsigned short D_00CC0CF8[];//scripts/entities'"PCs"
extern short D_00CC0D60[];
extern int   D_00CC0D80;
extern short D_00CC0D84;//some previous game state
extern struct t_main_infos D_00CC0D88;
extern short D_00CC0EC0[];
extern short D_00CC14C8[];
extern unsigned char D_00CC14D0[/*0x100*/];//variable address space(1)
extern short D_00CC15D0;
extern short D_00CC15D4;
extern short D_00CC15D8;
extern short D_00CC15DC;
extern short D_00CC15E0;
extern short D_00CC15E4;
extern short D_00CC15E8;
extern short D_00CC15EC;
extern short D_00CC15F0;
extern short D_00CC15F4;
extern short D_00CC15F8;
extern short D_00CC15FC;
extern short D_00CC1600;
extern short D_00CC1604;
extern int D_00CC1608;
extern int D_00CC160C;
extern short D_00CC1610;
extern short D_00CC1614;
extern short D_00CC1618;
extern short D_00CC161C;
extern short D_00CC1620;
extern short D_00CC1624;
extern int D_00CC1628;
extern short D_00CC162C;
extern short D_00CC1630;
extern short D_00CC1634;
extern short D_00CC1638;

extern int   D_00CC1644;
extern int   D_00CC1648;
extern char  D_00CC164C;//unsigned?
extern unsigned char  D_00CC1650;
extern short D_00CC1654;
extern unsigned char  D_00CC1658;//unsigned?
extern unsigned char  D_00CC165C;
extern unsigned char  D_00CC1660;
extern unsigned char  D_00CC1664;//unsigned?
extern unsigned short D_00CC1668;//unsigned?
extern struct t_main_88 D_00CC1670[];
extern char D_00CC1EF0[];//TODO
//extern int D_00CC1F70;//TODO
extern struct t_field_x_18 D_00CC1F70[/*0x20*/];
extern float D_00CC2270;
extern float D_00CC2274;
extern float D_00CC2278;
extern struct t_field_d0 D_00CC2280[/*0x4b0*/];
extern int D_00CFF180[/*0x12*/];
extern struct fBGRA D_00CFF1C8;
extern struct tScreenInfo D_00CFF1D8;
extern int D_00CFF1FC;
extern int D_00CFF200;
extern int D_00CFF204;
extern int D_00CFF208;
extern int D_00CFF20C;
extern int D_00CFF210;
extern float D_00CFF214;
extern float D_00CFF218;
extern float D_00CFF21C;
extern float D_00CFF220;
extern float D_00CFF224;
extern char D_00CFF228[];

extern int D_00CFF248;
extern int D_00CFF24C;

extern int D_00CFF254;
extern int D_00CFF258;
extern int D_00CFF25C;
//extern unsigned char D_00CFF260;
extern char D_00CFF260;
extern int D_00CFF264;
extern int D_00CFF268;
extern int D_00CFF280;
extern int D_00CFF28C;
extern int D_00CFF290;
extern int D_00CFF294;
extern int D_00CFF2AC;
extern char D_00CFF2B0[];
extern struct MATRIX D_00CFF3B0;
extern struct MATRIX D_00CFF3D8;
extern int *D_00CFF3F8;
extern int *D_00CFF3FC;
extern int *D_00CFF400;
extern int *D_00CFF404;
extern struct SPRT_16 *D_00CFF40C;
extern short D_00CFF41C;
extern int D_00CFF42C;
extern void *D_00CFF434;
extern void *D_00CFF43C;
extern void *D_00CFF448;
extern struct t_ad_bk_temp_xxx *D_00CFF454;
extern struct t_ad_data_CAM_info *D_00CFF458;
extern void *D_00CFF45C;
extern struct t_ad_bk_4 *D_00CFF460;
extern unsigned short D_00CFF468;//current MAP number?
extern int D_00CFF47C;
extern int D_00CFF480;
extern struct t_dx_sfx_e0 *D_00CFF490;
extern int D_00CFF494;
extern struct t_addraw_30 D_00CFF498;
extern struct t_addraw_30 D_00CFF4F8;
extern struct t_addraw_30 D_00CFF528;
extern int D_00CFF558;
extern int D_00CFF55C;
extern short D_00CFF560;
extern short D_00CFF564;
extern short D_00CFF568;
extern short D_00CFF56C;
extern int D_00CFF570[/*9*/];//entries offsets(9 is enough?)
extern unsigned char *D_00CFF594;
extern int D_00CFF598;
extern unsigned char *D_00CFF594;
extern int D_00CFF598;
extern int D_00CFF5B0;
extern int D_00CFF5B4;
extern struct t_script_DialogInfo_30 D_00CFF5B8[];
extern struct t_script_190 *D_00CFF738;
extern unsigned short D_00CFF73E;
extern unsigned short D_00CFF740;
//extern struct t_adhuman_8 *D_00CFF744;
extern struct SVECTOR *D_00CFF744;
extern unsigned short *D_00CFF748;
extern struct t_adhuman_10 *D_00CFF74C[4];
extern struct t_adimage_temp_10 D_00CFF768[];
extern unsigned short D_00CFF888;
extern double D_00CFF890;
extern D3DMATRIX D_00CFF898;
extern LARGE_INTEGER D_00CFF8D8;
extern LARGE_INTEGER D_00CFF8E0;
extern int D_00CFF8E8[/*0x12*/];
extern int D_00CFF930[/*0x12*/];
extern D3DMATRIX D_00CFF980;
extern D3DMATRIX D_00CFF9C0;
extern int D_00CFFA00[];
extern int D_00CFFA48[/*0x12*/];
extern int D_00CFFA90;
extern int D_00CFFA94;
extern int D_00CFFA98;//skip frame flag[field]
extern double D_00CFFAA0;
extern int D_00CFFAA8;
extern void *D_00CFFAAC;//tutorial related?
extern tBGRA D_00CFFAB0;
extern unsigned char D_00CFFAB4;
extern unsigned char D_00CFFAB8;
extern unsigned char D_00CFFABC;
extern struct t_dx_sfx_e0 *D_00CFFAC0[/*3*/];
extern int D_00CFFACC[];
extern int D_00CFFAD8;
extern int D_00CFFADC,D_00CFFAE0,D_00CFFAE4,D_00CFFAE8;//viewport for "fade"?
extern int D_00CFFAF0;
extern int D_00CFFAF4;
extern char D_00CFFAF8[128];
extern int D_00CFFB78;
extern int D_00CFFB7C;
extern int D_00CFFB80;
extern int D_00CFFB84;
extern int D_00CFFB8C;
extern struct t_light_5ac *D_00CFFB90[];

extern struct t_ad_data_1c *D_00CFFC70[/*0x2a*/];
extern struct tTextureInfo D_00CFFD20;
extern int D_00CFFDA0;
extern int D_00CFFDA4;
extern int D_00CFFDA8;
extern int D_00CFFDAC;

extern int D_00CFFDB8;
extern int D_00CFFDBC;
extern int D_00CFFDB8;
extern int D_00CFFDBC;
extern unsigned short D_00CFFDC0;
extern int D_00CFFDC4;
extern LPDIRECTDRAW D_00CFFDC8;
extern LPDIRECTDRAWSURFACE D_00CFFDCC;
extern LPDIRECTDRAWSURFACE D_00CFFDD0;
extern LPDIRECTDRAWSURFACE D_00CFFDD4;
extern LPDIRECTDRAWSURFACE D_00CFFDD8;
extern int D_00CFFDE0;
extern int D_00CFFDE4;//or short?
extern LPDIRECTDRAWSURFACE D_00CFFDF0;
extern unsigned short D_00CFFDF8;
extern unsigned short D_00CFFDFA;
extern unsigned short D_00CFFDFC;
extern unsigned short D_00CFFDFC;

extern struct t_ad_data_105c *D_00CFFE00;
extern int D_00CFFE04;
extern unsigned short D_00CFFE0C;
extern unsigned short D_00CFFE0E;
extern LPDIRECTDRAWSURFACE D_00CFFE18;

extern unsigned short D_00CFFE24;
extern unsigned short D_00CFFE26;
extern unsigned short D_00CFFE28;
extern struct t_ad_data_105c *D_00CFFE2C;
extern unsigned short D_00CFFE30;
extern int D_00CFFE3C;
extern int D_00CFFE40;
extern LPDIRECTDRAWSURFACE D_00CFFE48;
extern short D_00CFFE50;
extern short D_00CFFE52;
extern struct t_ad_data_105c *D_00CFFE54;
extern unsigned short D_00CFFE58;
extern unsigned short D_00CFFE5A;
extern unsigned short D_00CFFE5C;
extern unsigned short D_00CFFE70;
extern unsigned short D_00CFFE72;
extern int D_00CFFE74;
extern LPDIRECTDRAWSURFACE D_00CFFE80;
extern unsigned short D_00CFFE8C;
extern unsigned short D_00CFFE8E;
extern unsigned short D_00CFFE90;
extern struct t_ad_data_105c *D_00CFFE94;
extern unsigned short D_00CFFE98;
extern unsigned short D_00CFFE9A;
extern unsigned short D_00CFFE9C;
extern int D_00CFFEA4;
extern int D_00CFFEA8;
extern int D_00CFFECC;
extern short D_00CFFED0;
extern short D_00CFFED4;
extern short D_00CFFED8;
extern short D_00CFFEDC;

extern struct t_dx_sfx_e0 *D_00CFFF00[/*4*/];
extern float D_00CFFF10;
extern int D_00CFFF14;
extern struct t_sound_related_24 *D_00CFFF18;
extern struct t_sound_related_24 D_00CFFF38;
extern int D_00CFFF60;//start of a struct/array?

extern struct t_ad_Palette D_00D0005C;
	//extern struct t_ad_data_0c *D_00D0005C;
	//extern unsigned short D_00D00060;
	//extern unsigned short D_00D00062;
	//extern unsigned short D_00D00064;
	//extern unsigned short D_00D00066;
extern int D_00D00080;
extern struct t_ad_Palette D_00D00084;
	//extern struct t_ad_data_0c *D_00D00084;
	//extern unsigned short D_00D00088;
	//extern unsigned short D_00D0008A;
	//extern unsigned short D_00D0008C;
	//extern unsigned short D_00D0008E;
extern unsigned char D_00D00090[/*x14*/];
extern unsigned short *D_00D000A4;
extern unsigned short *D_00D000A8;
extern unsigned short *D_00D000AC;
extern unsigned short *D_00D000B0;
extern struct t_ad_pal_406 *D_00D000B4;
extern int D_00D000B8;
extern int D_00D000BC;
extern struct t_ad_data_40c *D_00D000C0;
extern unsigned char D_00D000C8[/*4*/];
extern char D_00D000D0[];
extern char D_00D001C0[];
extern short D_00D00940[][2];
extern char D_00D00D40[];
extern unsigned char D_00D00DA8[/*0x20*/];
extern unsigned char D_00D00DC8[/*0x20*/];
extern char D_00D00DE8[/*0x10*/][0x3c];
extern int D_00D011A8[/*0xf*/];
extern void *D_00D011E4;

extern struct t_field_7534 D_00D011F0[/*0x12*/];

extern float D_00D84F9C;
extern int D_00D84FA0;
extern unsigned short D_00D84FA8;

extern int D_00D85130[/*x12*/];
extern int D_00D85178;
extern struct t_light_5ac D_00D85180;
extern struct t_light_24 D_00D85730[/*3*/];
extern int D_00D8579C;
////////////////////////////////////////

#endif
