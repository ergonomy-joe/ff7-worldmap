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

//map jump
#define FIELD_EVENT_01 0x01
//battle
#define FIELD_EVENT_02 0x02
//prepare movie
#define FIELD_EVENT_03 0x03
//movie
#define FIELD_EVENT_04 0x04
//ending sequence?
#define FIELD_EVENT_05 0x05
//"please enter a name"
#define FIELD_EVENT_06 0x06
//"please make a party of three"
#define FIELD_EVENT_07 0x07
//"shops"
#define FIELD_EVENT_08 0x08
//tutorial
#define FIELD_EVENT_09 0x09
//ending sequence[from world map]?
#define FIELD_EVENT_0A 0x0a

//minigame
#define FIELD_EVENT_0C 0x0c
//disk change screen
#define FIELD_EVENT_0D 0x0d
//open save menu?
#define FIELD_EVENT_0E 0x0e
//Yuffie steals materias?
#define FIELD_EVENT_0F 0x0f
//get back materia stolen by Yuffie?
#define FIELD_EVENT_10 0x10
//chara stuff-->party stuff
#define FIELD_EVENT_11 0x11
//(backup some information to D_00DBFD38.f_0a9c)
#define FIELD_EVENT_12 0x12
//(restore some information from D_00DBFD38.f_0a9c)
#define FIELD_EVENT_13 0x13
//
#define FIELD_EVENT_14 0x14
//compute HPs after highway?
#define FIELD_EVENT_15 0x15
//has all materias of type?
#define FIELD_EVENT_16 0x16
//get "MASTER ..." materia?
#define FIELD_EVENT_17 0x17
//
#define FIELD_EVENT_18 0x18
//
#define FIELD_EVENT_19 0x19
//game over
#define FIELD_EVENT_1A 0x1a

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
	/*28*/short f_28;//count objects in D_00CC1670[]//0CC0DB0
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
	/*64*/short wLastMap;//0CC0DEC
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

//entry 0(.ate)
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

struct t_main_88 {//size 0x88
	//-- "KAWAI" --
	/*00*/short wKawaiState;//0CC1670
	/*02*/short f_02;//always 0[unused]//0CC1672
	/*04*/unsigned char *pKawaiParams;//0CC1674
	//
	/*08*/char bBlinkOff; char __09;//0CC1678/0CC1679
	/*0a*/short wBlinkCounter;//eye blink//0CC167A
	//-- --
	/*0c*/int dwPosX,dwPosY,dwPosZ;//0CC167C,0CC1680,0CC1684
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
	/*5f*/char bNotSolid;//0CC16CF
	/*60*/char bENTERTriggered;//0CC16D0
	/*61*/char bTalkOff;//0CC16D1
	/*62*/char bVisible;//0CC16D2
	/*63*/char bControlType;//0CC16D3
	/*64*/char bAnimIdx; char __65;//0CC16D4/0CC16D5
	/*66*/short wAnimIncr;//0CC16D6
	/*68*/short wAnimCounter;//0CC16D8
	/*6a*/short wAnimFrameMax;//0CC16DA
	/*6c*/short f_6c;//0CC16DC
	/*6e*/short f_6e;//0CC16DE
	/*70*/short f_70;//0CC16E0
	/*72*/unsigned short wSolidRadius;//0CC16E2
	/*74*/unsigned short wTalkRange;//0CC16E4
	/*76*/unsigned short wSpeed;//0CC16E6
	/*78*/unsigned short wCurMeshIdx;//0CC16E8
	//-- "JUMP"/"LADER"/"JOIN"/"SPLIT" --
	/*7a*/unsigned short wDstMeshIdx;//0CC16EA
	/*7c*/int dwDstX,dwDstY,dwDstZ;//0CC16EC,0CC16F0,0CC16F4
};

struct t_script_190 {//size 0x190
	/*000*/unsigned char f_000;
	/*001*/char __001[3];
	/*004*/int f_004;
	/*008*/int f_008;
	/*00c*/int f_00c;
	/*010*/int f_010;
	/*014*/int f_014;
	/*018*/short f_018;
	/*01a*/short f_01a;
	/*01c*/unsigned short f_01c;
	/*012*/char __01e[2];
	/*020*/char f_020;//character id?
	/*021*/char bKawaiOp;
	/*022*/unsigned short wAnimCount;//# of objects in f_024/f_17c
	/*024*/int f_024[0x50];
	/*164*/int f_164;
	/*168*/int f_168;
	/*16c*/int f_16c;
	/*170*/int f_170;
	/*174*/unsigned short wAnimIdx;
	/*176*/char __176[2];
	/*178*/struct t_plytopd_e4 *f_178;
	/*17c*/struct t_animationHeader **f_17c;
	/*180*/struct tRenderState *f_180;
	/*184*/struct tRenderState *f_184[3];
};

struct t_local_zzz_20 {//size 0x20
	/*00*/int f_00;
	/*04*/int f_04;
	/*08*/int f_08;
	/*0c*/float f_0c;
	/*10*/float f_10;
	/*14*/float f_14;
	/*18*/float f_18;
	/*1c*/float f_1c;
};

//looks a lot like struct t_z_30?
struct t_addraw_30 {//size 0x30
	/*00*/unsigned f_00;
	/*04*/unsigned f_04;
	//-- palette section? --
	/*08*/unsigned short *lpwPalette;
	/*0c*/unsigned dwPaletteSectionSize;//size of data in lpwPalette (+ 0xc)
	/*10*/short wPalX,wPalY;
	/*14*/unsigned short wPaletteSize,wPaletteCount;
	/*18*/char __18[4];
	//-- image section? --
	/*1c*/void *lpwImage;
	/*20*/unsigned dwImageSectionSize;
	/*24*/short wImgX,wImgY;
	/*28*/unsigned short wWidth,wHeight;
	/*2c*/char __2c[4];
};

struct t_field_4b8 {//size 0x4b8
	/*00*/int f_00;
	/*04*/int f_04;
	/*08*/int f_08[0x64][3];
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
	/*00*/unsigned short f_00[3][3];//rot
	/*12*/char __12[2];//padding?seems to contain f_00[2][2]
	/*14*/unsigned f_14[3];//trans
	//-- --
	/*20*/short f_20,f_22;
	/*24*/short f_24;//parameter for psx_SetGeomScreen?
	/*26*/char __26[2];//contains some flag?
};

//struct t_field_10
struct t_field_ShineFXLightInfo {//size 0x10
	/*00*/struct SVECTOR f_00;
	/*08*/tBGRA f_08;
	/*0c*/tBGRA f_0c;
};

struct t_field_d0 {//size 0xd0
	/*00*/int f_00;//model lighting related flag?00CC2280
	/*04*/float f_04;//clipping near?//00CC2284
	/*08*/int f_08[0x12];//model y patch offset?//00CC2288
	/*50*/int f_50[0x12];//model z patch offset?//00CC22D0
	/*98*/int f_98;//00CC2318
	/*9c*/int f_9c;//00CC231C
	/*a0*/int f_a0;//00CC2320
	/*a4*/int f_a4;//00CC2324
	/*a8*/char f_a8[0x12];//model on/off?//00CC2328
	/*ba*/unsigned char f_ba;//line trigger inhibition related?//00CC233A
	/*bb*/char __bb;//00CC233B
	/*bc*/int f_bc;//inflated size of field file?//00CC233C
	/*c0*/struct fBGRA f_c0;//"clear" color//00CC2340
};

//struct t_field_x_0c_new
struct t_field_Line {//size 0xc
	/*00*/short wX0,wY0,wZ0;
	/*06*/short wX1,wY1,wZ1;
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

//exit?
struct t_field_x_18_new {//size 0x18
	/*00*/struct t_field_Line f_00;
	/*0c*/short f_0c,f_0e;//destination x,y?
	/*10*/short f_10;//id?
	/*12*/unsigned short f_12;
	/*14*/unsigned char f_14;
	/*15*/char __15[3];
};

//automatic door
struct t_field_x_10 {//size 0x10
	/*00*/struct t_field_Line f_00;
	/*0c*/unsigned char f_0c;
	/*0d*/unsigned char f_0d;
	/*0e*/unsigned char f_0e;
	/*0f*/unsigned char f_0f;
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
	//
	/*38*/struct t_field_x_18_new f_38[0xc];//exits
	/*158*/struct t_field_x_10 f_158[0xc];//automatic doors
	/*218*/unsigned char f_218[0xc];
	/*224*/int f_224[0xc][4];
};

struct t_ad_bk_4 {//size 4
	/*00*/short wIndex;
	/*02*/unsigned short wDepth;
};

struct t_adimage_temp_10 {//size 0x10
	/*00*/int f_00;//some index?//0CFF768
	/*04*/unsigned short f_04;//z?depth?//0CFF76C
	/*06*/short wX,wY;//[unused]?//0CFF76E/0CFF770
	/*0a*/char __0a[0x10 - 0x0a];//0CFF772
};

struct t_ad_data_40c {//size 0x40c
	/*000*/int f_000;
	/*004*/int f_004[0x100];
	/*404*/int f_404;
	/*408*/int f_408;
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
	/*08*/unsigned short wPaletteIndex;
	/*0a*/unsigned short wType;
};

struct t_ad_data_1c {//size 0x1c
	/*00*/struct tTexHeader *f_00;
	/*04*/unsigned char *f_04;//data
	/*08*/struct t_dx_sfx_e0 *f_08;
	/*0c*/int dwActive;
	/*10*/int f_10;
	/*14*/int dwDoRender;
	/*18*/unsigned short wDoubleSize;
	/*1a*/unsigned short wBytePerPixel;
};

struct t_ad_data_105c {//size 0x105c
	/*0000*/short wX,wY;
	/*0004*/float fZ;
	/*0008*/unsigned short f_0008;
	/*000a*/unsigned short f_000a;
	/*000c*/short f_000c,f_000e;//wTexX,wTexY related[unused]?
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
	/*103c*/int f_103c;//{0|1}=use {wTexture_0|wTexture_1}
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
struct t_ad_obj_14 {//size 0x14
	/*00*/int f_00;//I think it's a "char"
	/*04*/char *f_04;
	/*08*/char *f_08;
	/*0c*/char *f_0c;
	/*10*/char *f_10;
};
////////////////////////////////////////
//-- C_0060B260.cpp --
extern void C_0060B2C6(void);//field:check random encounter?
extern int C_0060B9D0(const char *);//load ".ate" file?
extern void C_0060BACF(struct t_main_88 *);//"Init Event!"?
extern void C_0060BB58(void);
//-- C_0060B9D0.cpp --
extern void C_0060D4C5(struct t_aa0 *, struct t_rsd_74 *);//from script engine?
extern void C_0060D4F3(void);//manage 2d infos(hand, arrows)?
extern void C_0060D549(void);//manage 2d infos(hand, arrows)[flag only]?
//-- ad_app.cpp --
extern void C_0060DAD4(struct t_aa0 *);//ad_app:get room info?
extern void C_0060E5A8(void);//ad_app:reset some unused counter
extern int C_0060E96C(struct t_aa0 *);//FIELD[UPDATE](for "skip frame")?
extern void C_0060ED8A(int, int);//ad_app:unused init?
extern void C_0060EEA1(struct t_aa0 *);//ad_app:debug<empty>?
//-- C_0060F750.cpp --
extern void C_006137BD(void);//reset sound related struct
extern void C_0061C577(void);
//-- ad_data.cpp --
extern void C_0062086B(void);//ad_data:clean some PSX structs?
extern void C_0062091B(void);//ad_data:...
extern void C_00620B20(void);//ad_data:clean current map?
extern void C_00620BDD(const char *);//ad_data:set path
extern int C_00620DB6(void);//ad_data:read MAPLIST?
extern void C_00620F24(void);//ad_data:clean?
extern int C_00620F54(unsigned short, char *);//ad_data:get map name?
extern void C_006211FF(void);//ad_data:clean "ad_cdr" and "ad_obj"
extern int C_0062120E(void);//ad_data:...
extern float C_00623C0F(struct MATRIX *, int, int, int );//ad_data:...
extern int C_0062B6F1(void);//ad_data:read map file?(called by FIELD[START])
//-- ad_image.cpp --
extern void C_0062D3AE(void);//ad_image:...
extern int C_0062EC38(unsigned short, unsigned short, short, short, int, unsigned short);//ad_image:...
extern int C_0062F9D2(void *);//ad_image:...
extern int C_0062FAE3(void *);//ad_image:...
extern void C_006303A0(struct t_aa0 *, struct t_rsd_74 *);//ad_image:...
//-- ad_cdr.cpp --
extern int C_00630734(const char *);//ad_cdr:open?
extern void *C_006308CA(int);//ad_cdr:get entry?
extern void C_006308F0(void);//ad_cdr:close?
extern void C_0063092A(const char *bp08, int bp0c);//ad_cdr:<empty>
//-- C_00630940.cpp --
extern void C_00630940(void);//reset offset to strings(1)
extern void C_006309AA(void);//reset offset to strings(2)
extern void C_006309E4(short);//dialog:init/reset?
extern int C_00630B3D(short);//dialog:close?
extern void C_00630BC3(short, short, short);//dialog:set attributes ...
extern void C_00630BEA(void);
extern void C_00630C48(short, short, short, short, short);//dialog:set location and size
extern void C_00630CF4(short, short, short);//dialog:move
extern void C_00630D39(short, short);//dialog:set height
extern int C_00630D50(unsigned char, unsigned char);//dialog:refresh(1)
extern int C_006310A1(unsigned char, unsigned char, unsigned char, unsigned char, short *);//dialog:refresh(2)
extern int C_00633691(short);
extern void C_00633909(short, short);
//-- ad_human.CPP --
extern void C_006339C0(void);//ad_human:unused stuff.init
extern void C_00633A29(void);//ad_human:unused stuff.clean
extern void C_00633C2F(void);//ad_human:initialize walkmesh?
extern void C_006342C6(int);//ad_human:...
extern void C_00636284(void);//ad_human:check "talk"?
extern short C_00636500(unsigned char);//ad_human:scos
extern unsigned char C_00636515(struct VECTOR *, struct VECTOR *, int *);//ad_human:...
extern void C_00637D35(struct t_main_88 *, struct t_field_x_18 *);//ad_human:check line triggers?
extern void C_00637E88(struct t_field_x_18 *bp08);//ad_human:reset some line trigger?
extern void C_00638420(struct t_field_x_10 *);//ad_human:reset automatic doors?
//-- C_006384B0.cpp --
extern void C_00638801(struct t_aa0 *);
extern void C_006388EE(struct t_aa0 *);
extern int C_00638BAB(struct t_script_190 *, int);//field:set model's animation?
extern struct t_animationHeader *C_00638DAD(struct t_rsd_74 *, const char *);//field:load ".aki" file(renamed ".a")?
extern struct t_plytopd_e4 *C_00638F48(int, struct t_animationHeader *, struct t_rsd_74 *, struct t_aa0 *, const char *, const char *);//field:load ".HRC" file?
extern void C_006390D5(LPD3DMATRIX);//field:matrix with axis z and y switched?
extern void C_00639157(struct t_aa0 *);
extern void C_006392BB(void);//field:animate skeletons?
extern void C_00639CAB(struct t_dx_sfx_e0 *, float, float, float, float, float, float, float, int, float, float, int);//field:make textured quad?
extern void C_0063A171(struct t_script_4c *);//field:draw some quad?
extern void C_0063A34A(int, int, tBGRA *, int);
extern void C_0063A4C8(void);//field:camera related?
//-- tutaddr.cpp --
extern void C_0063AA30(int);//tutaddr:...?
extern void C_0063ABC8(void);//tutaddr:...
//-- C_0063AC20.cpp --
extern void C_0063AC66(struct t_aa0 *);//fade:init
extern void C_0063AD47(void);//fade:clean?
extern void C_0063AD97(struct t_aa0 *);//fade:refresh
extern void C_0063B84B(void);//fade:refresh something?
//-- C_0063BC90.cpp --
extern int C_0063BC9D(void);//field:get "exit status"?
extern void C_0063BDA8(void);
extern int C_0063C17F(void);
//-- ad_obj.cpp --
extern void C_0063CF72(void);//ad_obj:release?
extern void C_0063CFA2(const char *);//ad_obj:set path
extern int C_0063D322(const char *);//(.fcr)[for developement]
extern int C_0063D993(const char *);//get cdr entry 2(.fcc)
extern void C_0063E1D8(void);//ad_obj:some cleaning?
extern int C_0063E4EB(struct t_rsd_74 *, struct t_aa0 *);//ad_obj:load character models?
//-- ad_tile.cpp --
extern int C_0063F494(void);//ad_tile:...
extern void C_0063F635(void);//ad_tile:texture related cleaning(2)?
extern void C_0063F707(void);//ad_tile:texture related cleaning?
extern void C_00640160(void);//ad_tile:some reset?
extern void C_00640213(struct t_aa0 *, unsigned short, unsigned short);//ad_tile:render BG tiles?
extern int C_00640292(struct t_aa0 *, struct t_rsd_74 *);//ad_tile:"field_load_textures"
extern void C_00640EB7(void);//ad_tile:...
extern int C_00640F22(short, short);//ad_tile:make tile list?
//-- ad_ddraw.cpp --
extern void C_0064176A(struct t_aa0 *);//ad_ddraw:init?
extern void C_006417D6(void);//ad_ddraw:clean?
extern int C_0064195B(struct t_aa0 *);//ad_ddraw:init(2)
extern int C_006419C7(void);//ad_ddraw:flip
extern int C_006419E8(LPDIRECTDRAWSURFACE, void **, unsigned *);//ad_ddraw:Lock
extern int C_00641A43(LPDIRECTDRAWSURFACE);//ad_ddraw:Unlock
extern int C_00641A5E(struct t_addraw_30 *, unsigned short);//ad_ddraw:...
extern int C_00642629(LPDIRECTDRAWSURFACE, LPDIRECTDRAWSURFACE, LPRECT, LPRECT, long, LPDDBLTFX);//ad_ddraw:Blt
extern int C_006426A0(LPDIRECTDRAWSURFACE, LPDIRECTDRAWSURFACE, LPRECT, LPRECT, long);//ad_ddraw:BltFast
extern void *C_006427B6(int, int);//ad_ddraw:allocate surface memory?
//-- ad_bk.cpp --
extern void C_00642DD0(void);//ad_bk:some cleaning?
extern void C_00642FC4(void);//ad_bk:some sort function?
extern void C_0064309C(void);//ad_bk:<empty>
extern int C_006430A4(int, int, int, int);//ad_bk:"linear"
extern int C_006430F2(int, int, int, int);//ad_bk:"smooth"
extern int C_0064314F(struct SVECTOR *, struct SVECTOR *);//ad_bk:3D to 2D projection?
extern void C_006431BB(struct t_ad_bk_AxisShakeInfo *);//ad_bk:refresh "struct t_ad_bk_AxisShakeInfo *"
extern void C_0064341C(void);//ad_bk:check scroll event[state 0]?
extern void C_006439AF(void);//ad_bk:...
extern void C_00643D22(void);//ad_bk:refresh scroll[state 1]?
extern void C_00644075(void);//ad_bk:update bk, models x,y?
//-- C_00644A80.cpp --
extern void C_00644A80(struct t_aa0 *, struct t_rsd_74 *);//rain related:init?
extern void C_00644B43(void);//rain related:clean?
extern void C_00644CEC(struct MATRIX *);//rain related:render?
extern void C_00644E90(void);//rain related:...?
extern void C_00644EB2(void);//rain related:reset something?
extern void C_00644EE7(void);//rain related:refresh?
//-- C_00645150.cpp --
extern int C_00645150(struct t_plytopd_e4 *, unsigned char *);//field:KAWAI command 0x08/0x09(SHIBUKI)
//-- C_00646310.cpp --
extern void C_00646310(void);//field:some sound.init(1)
extern void C_0064631F(void);//field:some sound.init(2)
extern void C_0064637B(unsigned short);//field:some sound.play
//-- ad_list.cpp --
extern int C_006463F0(void);//ad_list:init
extern void C_00646449(void);//ad_list:clean?
extern void C_00646479(void);//ad_list:reset
extern void C_006464BA(float, float, float, float, float, int, int);//ad_list:add element
extern void C_006465FB(void);//ad_list:render
//-- ad_pal.cpp --
extern short C_006470E0(unsigned short, int);//ad_pal:convert 555 to ...(1)?
extern short C_00647252(unsigned short, int);//ad_pal:convert 555 to ...(2)?
extern void C_00647500(void);//ad_pal:release "struct t_ad_data_40c *" object?
extern int C_00647530(unsigned short, unsigned short, unsigned short *, int);//ad_pal:parse palette data?
extern int C_00648828(unsigned short, unsigned short, unsigned  short *, int);//ad_pal:...
extern void C_00648C37(void);//ad_pal:clean?
extern short C_00648E1C(unsigned short, unsigned short, int, int);//ad_pal:blend 2 indexed colors?
extern void C_00648FAD(int *, void *);//ad_pal:restore palette?
extern void C_00649111(int *, void *);//ad_pal:backup palette?
extern void C_00649697(void);//ad_pal:...
extern void C_006496BB(void);//ad_pal:...
//-- C_006496E0.cpp --
extern void C_006496E0(void);
//-- C_00649770.cpp --
extern void C_00649770(void);//field:input.reset
extern int C_006499F7(short *, short *);//field:input.read
//-- C_00649B30.cpp --
extern void C_00649B30(struct VECTOR *, int, int, int);//field:set vector x,y,z
//-- C_00649B50.cpp --
extern int C_00649B50(struct t_script_190 *, unsigned char *);//field:KAWAI command EYETX
//-- C_00649DE0.cpp --
extern void C_00649E1F(struct VECTOR *, struct VECTOR *, struct VECTOR *);//cross product?
extern void C_00649E9A(unsigned short, int *, short *, short *, int *);
extern void C_00649F0A(unsigned short, unsigned short *);
extern void C_00649F25(unsigned short *, unsigned char, unsigned char);//field:make depth
extern void C_00649F46(struct VECTOR *, struct SVECTOR *, struct SVECTOR *);//field:vector diff
extern int C_00649F8A(struct VECTOR *, struct VECTOR *, struct VECTOR *, struct SVECTOR *);
//-- C_0064A070.cpp --
extern int C_0064A070(int, struct t_plytopd_e4 *, unsigned char *, struct SVECTOR, int, int *);//field:perform "KAWAI" command
//-- C_0064B090.cpp --
extern void C_0064B090(void *, struct tPolygonInfo *);//(callback)
extern void C_0064B0EE(void *, struct tPolygonInfo * /*TO CHECK*/);//(callback)
extern void C_0064B14E(void *, struct tPolygonInfo *);//(callback)set polygon active?
extern void C_0064B15C(void *, struct tPolygonInfo *);//(callback)set polygon inactive?
extern void C_0064B563(void *, struct tPolygonInfo *);//(callback)
extern void C_0064B95C(struct tSkeleton *, struct t_aa0 *);//field:transparency effect?
extern void C_0064BAB9(struct t_plytopd_e4 *, short, short, short, short, int);//field:apply light to object(for KAWAI)?
extern void C_0064C364(void *, struct tPolygonInfo *);//(callback)
extern void C_0064CA47(void *, struct tPolygonInfo *);//(callback)
extern int C_0064D2E6(struct t_ad_obj_14 *, struct t_script_190 *);//field:init eye texture/material?
extern void C_0064D4F6(struct t_script_190 *);
//-- C_0064D670.cpp --
extern void C_0064DA3B(struct MATRIX *, struct t_field_x_18_new *);//2d infos:draw exits?
//-- C_0064E0C0.cpp --
extern int C_0064E0C0(struct t_plytopd_e4 *, unsigned char *);//field:apply light to object(for KAWAI/SHIBUKI)
//-- C_0064E1B0.cpp --
extern int C_0064E1B0(struct t_plytopd_e4 *, struct t_field_4b8 *, struct SVECTOR, unsigned char *);//field:KAWAI command "SHINE"
//-- C_0064E940.cpp --
extern int C_0064E940(struct t_plytopd_e4 *, struct t_field_4b8 *, unsigned char *, int, int, short *);//field:KAWAI command 0x05
//-- C_0064EB50.cpp --
extern int C_0064EB50(struct t_plytopd_e4 *, struct t_field_4b8 *, unsigned char *);//field:KAWAI command "SBOBJ"
//-- C_0064EC60.cpp --
extern int C_0064EC60(struct tSkeleton *, unsigned char *);//field:KAWAI command 0x03
//-- C_0064EEE0.cpp --
extern int C_0064EEE0(struct tSkeleton *, unsigned char *);//field:KAWAI command "ABMNT"
//-- C_0064EFC0.cpp --
extern int C_0064EFC0(struct tSkeleton *, unsigned char *);//field:KAWAI command 0x07
//-- C_0064F420.cpp --
extern int C_0064F420(struct tSkeleton *, unsigned char *);//field:KAWAI command "LIGHT"
//-- C_0064F860.cpp --
extern int C_0064F860(struct tSkeleton *, short, short, short);
extern void C_0064FA20(int, int, int, tBGRA *, tBGRA *);
//-- C_0064FB20.cpp --
extern int C_0064FB20(struct t_plytopd_e4 *, struct t_field_ShineFXLightInfo *, unsigned char *, int, int, int);//field:apply some light info?
extern int C_0065019E(struct t_plytopd_e4 *, struct t_field_ShineFXLightInfo *, unsigned char *, int, short *);//field:cache some light info?
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
extern struct t_main_88 *D_00CC0B60;//pointer to D_00CC1670[]
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
extern struct t_addraw_30 D_00CFF498[/*2*/];
extern struct t_addraw_30 D_00CFF4F8[/*2*/];
	//extern struct t_addraw_30 D_00CFF528;
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
extern char D_00CFFAF8[/*128*/];
extern int D_00CFFB78;
extern int D_00CFFB7C;
extern int D_00CFFB80;
extern int D_00CFFB84;
extern int D_00CFFB8C;//"exit status"
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
