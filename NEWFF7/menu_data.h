/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
#ifndef __MENU_DATA_H__
#define __MENU_DATA_H__

struct t_input_config {//size 0x38?
	/*00*/int dwX,dwY;
	/*08*/int dwPageWidth,dwPageHeight;
	/*10*/int dwReserved1;
	/*14*/int dwPage;
	/*18*/int dwWidth,dwHeight;
	/*20*/int dwReserved2;
	/*24*/int dwCounter;
	/*28*/int dwHAttr;
	/*2c*/int dwVAttr;
	/*30*/int dwTransition;
	/*34*/int dwAllowsPgDnPgUp;
};

struct t_menu_rect {//size 8
	/*00*/short wX;
	/*02*/short wY;
	/*04*/short f_04;
	/*06*/short f_06;
};

//00DC20A0/size 0x1500=3*0x700?
struct t_menu_battle_700 {//size 0x700 = 0x20 * 0x38
	/*000*/struct t_input_config f_000;//menu[1]?//00DC20A0
	/*038*/struct t_input_config f_038;//menu[5]?//00DC20D8
	/*070*/struct t_input_config f_070;//menu[6]?//00DC2110
	/*0A8*/struct t_input_config f_0a8;//menu[7]?//00DC2148
	/*0E0*/struct t_input_config f_0e0;//menu[4]?//00DC2180//int _00DC2184; int _00DC2194;
	/*118*/struct t_input_config f_118;//menu[0x18]?//00DC21B8
	/*150*/struct t_input_config f_150;//menu[0x14]?//00DC21F0
	/*188*/struct t_input_config f_188;//menu[0x1c]?//00DC2228
	/*1c0*/struct t_input_config f_1c0;//menu[9]?//00DC2260
	/*1f8*/char __pad[0x4d0];//0x4d0 = 0x16 * 0x38
	/*6c8*/struct t_input_config f_6c8;//menu[0x13]?//00DC2768
};

struct t_menu_shop_local___ {//size 0x24?
	/*00*/unsigned char f_00;
	/*01*/unsigned char f_01;
	/*02*/char __02[2];
	/*04*/int f_04;
	/*08*/char __08[2];
	/*0a*/short f_0a[8];
	/*1a*/unsigned char f_1a[5][2];
};

struct t_menu_scroller_0e {//size 0xe
	/*00*/short f_00;
	/*02*/short f_02;
	/*04*/short f_04;
	//struct t_menu_rect f_06;?
	/*06*/short f_06,f_08,f_0a,f_0c;//wX,wY,wWidth,wHeight
};

struct t_menu_small_gauge_14 {//size 0x14
	/*00*/short wX,wY;
	/*04*/short wWidth,wHeight;
	/*08*/short wVal,wMax;
	/*0c*/short f_0c;
	/*0e*/short wExVal;
	/*10*/tBGRA f_10;
};

//kernel.bin|section 0
struct t_battle_local_08_IIII {//size 8
	/*00*/unsigned char f_00;
	/*01*/unsigned char bTargetFlags;
	/*02*/char f_02;
	/*03*/char f_03;
	/*04*/unsigned short f_04;
	/*06*/unsigned short f_06;
};

//kernel.bin|section 1
//kernel.bin|section 4[items]
struct t_menu_temp_1c {//size 0x1c
	/*00*/unsigned char f_00;//00DB9690
	/*01*/unsigned char f_01;//00DB9691
	/*02*/unsigned char f_02;//00DB9692
	/*03*/char __03[1];//00DB9693
	/*04*/unsigned short wMPCost;//00DB9694
	/*06*/short wSoundId;//00DB9696
	/*08*/unsigned short f_08[2];//00DB9698
	/*0c*/unsigned char bTargetFlags;//00DB969C
	/*0d*/unsigned char bEffectId;//index in D_008FE5E8[]?//00DB969D
	/*0e*/unsigned char f_0e;//00DB969E
	/*0f*/unsigned char f_0f;//00DB969F
	/*10*/unsigned char f_10;//00DB96A0
	/*11*/unsigned char f_11;//00DB96A1
	/*12*/unsigned char f_12;//00DB96A2
	/*13*/unsigned char f_13;//00DB96A3
	/*14*/int f_14;//00DB96A4
	/*18*/unsigned short f_18;//00DB96A8
	/*1a*/unsigned short f_1a;//00DB96AA
};

//kernel.bin|section 5[weapons]
struct t_menu_temp_2c {//size 0x2c
	/*00*/unsigned char bTargetFlags;//00DBE730
	/*01*/unsigned char f_01;//00DBE731
	/*02*/unsigned char f_02;//00DBE732
	/*03*/char __03[1];//00DBE733
	/*04*/unsigned char f_04;//00DBE734
	/*05*/unsigned char f_05;//00DBE735
	/*06*/unsigned char f_06;//00DBE736
	/*07*/unsigned char f_07;//00DBE737
	/*08*/unsigned char f_08;//00DBE738
	/*09*/unsigned char f_09;//00DBE739
	/*0a*/char __0a[1];//00DBE73A
	/*0b*/unsigned char f_0b;//00DBE73B
	/*0c*/unsigned short f_0c;//00DBE73C
	/*0e*/unsigned short f_0e;//00DBE73E
	/*10*/unsigned short f_10;//00DBE740
	/*12*/char __12[2];//00DBE742
	/*14*/unsigned char f_14[4];//00DBE744
	/*18*/unsigned char f_18[4];//00DBE748
	/*1c*/unsigned char f_1c[8];//00DBE74C
	/*24*/unsigned char abSoundId[3];//00DBE754
	/*27*/unsigned char f_27;//00DBE757
	/*28*/unsigned short f_28;//00DBE758
	/*2a*/unsigned short f_2a;//00DBE75A
};

//kernel.bin|section 6[armors]
struct t_menu_temp_24 {//size 0x24
	/*00*/char __00[1];//00DBCCE0
	/*01*/unsigned char f_01;//00DBCCE1
	/*02*/unsigned char f_02;//00DBCCE2
	/*03*/unsigned char f_03;//00DBCCE3
	/*04*/unsigned char f_04;//00DBCCE4
	/*05*/unsigned char f_05;//00DBCCE5
	/*06*/unsigned char f_06;//00DBCCE6
	/*07*/char __07[2];//00DBCCE7
	/*09*/unsigned char f_09[8];//00DBCCE9
	/*11*/unsigned char f_11;//00DBCCF1
	/*12*/unsigned short f_12;//00DBCCF2
	/*14*/unsigned short f_14;//00DBCCF4
	/*16*/char __16[2];//00DBCCF6
	/*18*/unsigned char f_18[4];//00DBCCF8
	/*1c*/unsigned char f_1c[4];//00DBCCFC
	/*20*/unsigned short f_20;//00DBCD00
	/*22*/char __22[2];//00DBCD02
};

//kernel.bin|section 7[accessories]
struct t_menu_temp_10 {//size 0x10
	/*00*/unsigned char f_00[2];//00DBCAE0
	/*01*/unsigned char f_02[2];//00DBCAE2
	/*04*/unsigned char f_04;//00DBCAE4
	/*05*/unsigned char f_05;//00DBCAE5
	/*06*/unsigned short f_06;//00DBCAE6
	/*08*/int f_08;//00DBCAE8
	/*0c*/unsigned short f_0c;//00DBCAEC
	/*0e*/unsigned short f_0e;//00DBCAEE
};

//kernel.bin|section 8[materia]
struct t_menu_temp_14 {//size 0x14
	/*00*/unsigned short f_00[4];//00DBDF60
	/*08*/unsigned char f_08;//00DBDF68
	/*09*/unsigned char f_09;//00DBDF69
	/*0a*/unsigned char f_0a;//00DBDF6A
	/*0b*/unsigned char f_0b;//00DBDF6B
	/*0c*/unsigned char f_0c;//00DBDF6C
	/*0d*/unsigned char f_0d;//00DBDF6D
	/*0e*/unsigned char f_0e[6];//00DBDF6E
};

struct t_menu_something_size_08 {//size 8
	/*00*/unsigned char f_00;
	/*01*/unsigned char bMPCost;
	/*02*/unsigned char f_02;
	/*03*/unsigned char f_03;
	/*04*/unsigned char f_04;
	/*05*/unsigned char bTargetFlags;
	/*06*/unsigned char bStatus;
	/*07*/unsigned char f_07;
};

struct t_battle_menuEntryInfo {//size 6
	/*00*/unsigned char bType;//009AEAB8
	/*01*/unsigned char f_01;//009AEAB9
	/*02*/unsigned char bTargetFlags;//009AEABA
	/*03*/unsigned char bMenuFlags;//009AEABB
	/*04*/unsigned char f_04;//009AEABC
	/*05*/unsigned char f_05;//009AEABD
};

//limit related?
struct t_menu_something_size_5c {//size 0x5c
	/*00*/unsigned char f_00[3];//00DBA544
	/*03*/unsigned char abTargetFlags[3];//00DBA547
	/*06*/unsigned char f_06;//00DBA54A
	/*07*/unsigned char f_07;//00DBA54B
	/*08*/struct t_menu_temp_1c f_08[3];//00DBA54C
};

struct t_menu_temp_440 {//size 0x440
	/*000*/unsigned char f_000;//00DBA498
	/*001*/unsigned char f_001;//00DBA499
	/*002*/unsigned char f_002;//00DBA49A
	/*003*/unsigned char f_003;//00DBA49B
	/*004*/unsigned char f_004;//00DBA49C
	/*005*/unsigned char f_005;//00DBA49D
	/*006*/unsigned char f_006;//00DBA49E
	/*007*/unsigned char f_007;//00DBA49F
	/*008*/unsigned short f_008;//00DBA4A0
	/*00a*/unsigned short f_00a;//00DBA4A2
	/*00c*/unsigned short f_00c;//00DBA4A4
	/*00e*/unsigned short f_00e;//00DBA4A6
	/*010*/short wHP,wHPMax;//00DBA4A8,00DBA4AA
	/*014*/short wMP,wMPMax;//00DBA4AC,00DBA4AE
	/*018*/unsigned short wWait;//00DBA4B0
	/*01a*/unsigned short wLimit;//00DBA4B2
	/*01c*/unsigned short f_01c;//BARRIER(physical)//00DBA4B4
	/*01e*/unsigned short f_01e;//BARRIER(magical)//00DBA4B6
	/*020*/unsigned char f_020;//00DBA4B8
	/*021*/unsigned char bMenuColumnCount;//00DBA4B9
	/*022*/unsigned char f_022;//00DBA4BA
	/*023*/unsigned char f_023;//00DBA4BB
	/*024*/struct t_inner_03 {//size 3
		/*00*/unsigned char f_00;
		/*01*/unsigned char f_01;
		/*02*/unsigned char f_02;
	}f_024[8];//00DBA4BC
	/*03c*/unsigned short f_03c;//00DBA4D4
	/*03e*/unsigned short f_03e;//00DBA4D6
	/*040*/unsigned short f_040;//00DBA4D8
	/*042*/unsigned short f_042;//00DBA4DA
	/*044*/int f_044;//00DBA4DC
	/*048*/int f_048;//00DBA4E0
	/*04c*/struct t_battle_menuEntryInfo f_04c[0x10];//00DBA4E4
	/*108*/struct t_menu_something_size_5c f_0ac;//00DBA544
	/*2c8*/struct t_menu_something_size_08 f_108[0x38];//00DBA5A0
	/*348*/struct t_menu_something_size_08 f_2c8[0x10];//00DBA760
	/*348*/struct t_menu_something_size_08 f_348[0x18];//00DBA7E0
	/*408*/struct t_menu_temp_2c f_408;//00DBA8A0
	/*434*/char __434[3];//00DBA8CC
	/*437*/unsigned char f_437;//"Enemy Away"//00DBA8CF
	/*438*/char __438[4];//00DBA8D0
	/*43c*/unsigned char f_43c;//"Gil Plus"//00DBA8D4
	/*43d*/unsigned char f_43d;//"Enemy Lure"//00DBA8D5
	/*43e*/unsigned char f_43e;//"Chocobo Lure"//00DBA8D6
	/*43f*/unsigned char f_43f;//"Pre-Emptive"//00DBA8D7
};
////////////////////////////////////////
extern int D_00919928[];
extern unsigned char D_0091A8C0[][0x14];
extern tBGRA D_0091AB08[];
extern tBGRA D_0091EFC8[/*4*/];
extern unsigned char D_0091EFD8[/*4*3*/];
extern unsigned char D_00920540[][0xa];
extern unsigned char D_00925760[][0x24];
extern unsigned char D_00925C98[][0x30];
extern unsigned char D_00926118[][0xc];

extern int D_00DB9580;
extern unsigned short D_00DB9588,D_00DB958A;
extern unsigned char *D_00DB958C;//pointer to font info(size)?
//extern char D_00DB9590[];//size:0x100 = 0x20 * 8
extern struct t_battle_local_08_IIII D_00DB9590[/*0x20*/];
extern struct t_menu_temp_1c D_00DB9690[];//size:0xe00 = 0x80 * sizeof(struct t_menu_temp_1c)
extern struct t_menu_temp_440 D_00DBA498[];
extern unsigned char D_00DBCAD8,D_00DBCAD9,D_00DBCADA,D_00DBCADB;
extern struct t_menu_temp_10 D_00DBCAE0[];//size:0x200 = 0x20 * sizeof(struct t_menu_temp_10)
extern struct t_menu_temp_24 D_00DBCCE0[];//size:0x480 = 0x20 * sizeof(struct t_menu_temp_24)
extern struct t_menu_temp_1c D_00DBD160[];//size:0xe00 = 0x80 * sizeof(struct t_menu_temp_1c)
extern struct t_menu_temp_14 D_00DBDF60[];//size:0x780
extern struct t_menu_temp_2c D_00DBE730[];//size:0x1600 = 0x80 * sizeof(struct t_menu_temp_2c)
extern int D_00DBFD30;//combat related?

//extern unsigned char D_00DC0E6C;//pause related?

extern struct t_dx_sfx_e0 *D_00DC0FC8;
extern struct t_dx_sfx_e0 *D_00DC0FCC;
extern struct t_dx_sfx_e0 *D_00DC0FD0;
extern struct t_dx_sfx_e0 *D_00DC0FD4;
extern struct t_dx_sfx_e0 *D_00DC0FD8;
extern struct t_dx_sfx_e0 *D_00DC0FDC;
extern struct t_dx_sfx_e0 *D_00DC0FE0;
extern struct t_dx_sfx_e0 *D_00DC0FE4;
extern struct t_dx_sfx_e0 *D_00DC0FE8;
extern struct t_dx_sfx_e0 *D_00DC0FEC;
extern struct t_dx_sfx_e0 *D_00DC0FF0;
extern struct t_dx_sfx_e0 *D_00DC0FF4;
extern struct t_dx_sfx_e0 *D_00DC0FF8;
extern struct t_dx_sfx_e0 *D_00DC0FFC;
extern struct t_dx_sfx_e0 *D_00DC1000;
extern struct t_dx_sfx_e0 *D_00DC1004;
extern struct t_dx_sfx_e0 *D_00DC1008;
extern struct t_dx_sfx_e0 *D_00DC100C;
extern struct t_dx_sfx_e0 *D_00DC1010;
extern struct t_dx_sfx_e0 *D_00DC1014[3];
extern struct t_dx_sfx_e0 *D_00DC1020[9];
extern struct t_dx_sfx_e0 *D_00DC1044;
extern struct t_dx_sfx_e0 *D_00DC1048;
extern struct t_dx_sfx_e0 *D_00DC104C;
extern struct t_dx_sfx_e0 *D_00DC1050;
extern struct t_dx_sfx_e0 *D_00DC1054;
extern int D_00DC1058;
extern int D_00DC105C,D_00DC1060,D_00DC1064,D_00DC1068;//viewport x0,y0,w,h
extern int D_00DC106C;
extern int D_00DC1070;

extern int D_00DC1108;
extern int D_00DC1124;
extern unsigned short D_00DC1130;
extern unsigned short D_00DC1134;

extern int D_00DC1210;
extern int D_00DC1288;
extern int D_00DC1290;

extern int D_00DC12DC;//some ratio flag?

extern int D_00DC12E4;
extern int D_00DC12F4;

extern int D_00DC130C;//"is low-res" flag

extern struct t_dx_sfx_e0 *D_00DC16D8;
extern struct t_dx_sfx_e0 *D_00DC16DC;
extern struct t_dx_sfx_e0 *D_00DC16E0;
extern struct t_dx_sfx_e0 *D_00DC16E4;

extern struct t_dx_sfx_e0 *D_00DC1788;

extern struct t_dx_sfx_e0 *D_00DC1990;
extern struct t_dx_sfx_e0 *D_00DC1994;
extern struct t_dx_sfx_e0 *D_00DC1998;

extern short D_00DC1F3C;

//extern int D_00DC3D10;
extern unsigned char D_00DC3D14;
extern void *D_00DC38C4;
extern unsigned char D_00DC3BA0;
////////////////////////////////////////
extern void C_006C09C0(const char *);//(seems to be used only in case of CD ejection)[menu related]?
extern void C_006C0E2D(struct t_aa0 *);//on "Exit box"?[callback]
extern void C_006C0F60(void);//init menu system?
extern void C_006C12B1(void);//clean menu system?
extern void C_006C1468(int);
extern void C_006C1ABA(int, int);
extern void C_006C1B93(int);
extern void C_006C1CE7(void);//load "buster" resource
extern void C_006C1D8D(void);
extern void C_006C1F1B(void);
extern void C_006C4946(int, int);//set SFX&MIDI volumes?
extern int C_006C4970(void);
extern void C_006C497C(const unsigned char *, int);
extern void C_006C49CB(int, int, int);
extern void C_006C49FD(void);
extern void C_006C4D6D(void);
extern int C_006C50DD(int);//get restrictions mask?
extern int C_006C5154(int, int);//get Att/Def equip bonuses?
extern void C_006C545B(int);
extern void C_006C5A5A(int, int, int, float);//chara info[phs][HIRES]
extern void C_006C5E7E(int, int, int, float);//chara info[phs][LORES]
extern void C_006C62A2(int, int, int, float);//chara info[top menu][HIRES]
extern void C_006C66C8(int, int, int, float);//chara info[top menu][LORES]
extern void C_006C6AEE(int);//menu:go to submenu
extern unsigned char *C_006C6B06(int);
extern unsigned char *C_006C6B1B(int);
extern void C_006C96BC(void);
extern int C_006C9808(void);
extern void C_006C9812(int, int);
extern void C_006C98A6(int);//render menu header?[HIRES]
extern void C_006C9D07(int);//render menu header?[LORES]
extern int C_006CA1EF(int);//time:make hours[XX:__:__]
extern int C_006CA23F(int);//time:make minutes[__:XX:__]
extern void C_006CA32D(void);
extern int C_006CB8D6(int);
extern unsigned char *C_006CB8E2(int);//get armor material slots?
extern unsigned char *C_006CB928(int);//get weapon material slots?
extern struct t_menu_temp_24 *C_006CB96E(int);
extern struct t_menu_temp_440 *C_006CB98E(int);
extern unsigned char *C_006CB9B8(int);//get character's name?
extern void C_006CB9D2(int, int);//decrease HP?
extern void C_006CBA6A(int, int);//increase HP?
extern void C_006CBB27(int, int);//decrease MP?
extern void C_006CBBBF(int, int);//increase MP?
extern int C_006CBC7C(int);//decrease GILs?
extern void C_006CBCB9(int);//increase GILs?
extern int C_006CBCE9(void);//get GILs?
extern int C_006CBCF3(int);
extern void C_006CBD1E(void);
extern void C_006CBD82(void);
extern void C_006CBD8C(void);
extern void C_006CBD96(int);
extern void C_006CBDCE(void);
extern void C_006CBE33(void);
extern void C_006CBE3D(int);
extern void C_006CBE4E(int);
extern unsigned short C_006CBE5F(unsigned short);
extern unsigned short C_006CBF57(unsigned short);
extern void C_006CBFFA(unsigned short);//add item to inventory?
extern int C_006CC0EA(int);
extern void C_006CC173(void);
extern void C_006CC17F(int);
extern int C_006CC2ED(int, int);//<empty>
extern int C_006CC2F4(int, int);//<empty>
extern void C_006CC2FB(void);
extern void C_006CC3E8(void);//compute party's weapon/armor/accessory/materia/... related stuff?
extern void C_006CC446(void);
extern void C_006CC4A8(void);//"Cat's Bell" effect
extern void C_006CC5A2(void);
//====---- MENU SYSTEM ----====
extern void C_006CC623(struct t_aa0 *);//MENU SYSTEM[UPDATE][callback]
extern void C_006CC619(int, int, int, struct t_aa0 *);//MENU SYSTEM[ONMOUSE][callback]
extern void C_006CC61E(int, int, int, struct t_aa0 *);//MENU SYSTEM[ONKEY][callback]
extern void C_006CD3B0(struct t_aa0 *);//MENU SYSTEM[BEGIN][callback]
extern void C_006CD5B3(struct t_aa0 *);//MENU SYSTEM[END][callback]
//====---- ----====
extern void C_006CD64E(unsigned char, float);//draw alpha quad?
extern void C_006CD808(int);
extern void C_006CD815(void);//"end scene"(chara portrait?)
extern int C_006CDBF2(void);//menu.get_flag_1(render on?)
extern void C_006CDBFC(int);//menu.set_flag_1(render on?)
extern void C_006CDC09(int);//menu.set_flag_2
extern int C_006CDC16(void);//menu.get_flag_2
extern void C_006CDE2B(void);
extern void C_006CDE72(int *);//configure key menu?
extern void C_006CE64B(void);
extern void C_006CE665(void);//save "ff7input.cfg"?
extern void C_006CE6EC(void);//load "ff7input.cfg"?
extern void C_006CE79B(void);
extern void C_006CE811(char);
extern int C_006CE81E(void);//callback:...
extern void C_006CE85E(void);//menu.callback:check pause?
extern void C_006CE8B3(void);//english.callback:refresh?
extern void C_006CEA08(int, int, int, char, char, char);//<almost empty>
extern void C_006CEA17(void);//english.callback:init?
extern void C_006CEDAD(void);//english.callback:clean?
extern void C_006CEE84(void);//english.callback:render?
extern void C_006CF2AA(struct t_dx_sfx_e0 **, struct t_rsd_74 *, struct t_dx_sfx_70 *);//english.callback:...
extern void C_006D0ADE(int);//start something?<empty>
extern void C_006D0AE3(int);//end something?<empty>
extern short C_006D0AE8(short);//get battle menu state?
extern void C_006D0AF9(short, short, short);//open battle menu?
extern void C_006D0BF1(void);
extern void C_006D1B88(void *);//render target pointing hand?[HIRES]
extern void C_006D1C00(void *);//render target pointing hand?[LORES]
extern void C_006D1C78(void);//<empty>
extern void C_006D71FA(short, short);//set "in battle script display" parameters
extern void C_006D721C(short);//set "in battle target's attack display" parameters
extern void C_006D7245(void *);//battle text & info render?
extern void C_006D83C8(void);//render lower part?[HIRES]
extern void C_006D8550(void);//render lower part?[LORES]
extern void C_006DB0EE(void);//...:refresh?
extern void C_006DB0BC(void);//reset all menus?
extern void C_006DB716(void);
extern void C_006DB7AB(void *, int, int, int);
extern void C_006DC89A(void);
extern int C_006DC910(void);
extern void C_006E434E(void);
extern void C_006E6C30(tBGRA *, unsigned char, unsigned char, unsigned char);
extern void C_006E6C5B(int, int, int, float);//draw portrait[HIRES]
extern void C_006E6E66(int, int, int, int, int, float);//draw portrait[for preview][HIRES]
extern void C_006E7B6A(int, int, int, int);//[HIRES]
extern void C_006E7BA1(struct t_menu_rect *, int, int, int, int);//menu:set rect
extern void C_006E7BD1(struct t_menu_rect *, int, int);//menu:rect += {x,y}
extern void C_006E7BF8(struct t_menu_rect *, struct t_menu_rect *);//menu:copy rect
extern void C_006E7C33(void);//menu:backup color option?
extern void C_006E7C69(void);//menu:restore color option?
extern void C_006E7C9F(tBGRA *);//menu:set color option?
extern void C_006E7CD9(struct t_menu_rect *, int, float);
extern void C_006E7D20(struct t_menu_rect *, float);//window frame[HIRES]
extern void C_006EB3B8(int, int, float);//draw "hand"[HIRES]
extern int C_006EBF2C(struct t_script_DialogInfo_30 *, short, int);
extern void C_006ECA68(void);
extern void C_006ECECE(int, int, int, float);//draw portrait[LORES]
extern void C_006ED0EC(int, int, int, int, int, float);//draw portrait[for preview][LORES]
extern void C_006EDD6F(int, int, int, int);//[LORES]
extern void C_006EDE1D(struct t_menu_rect *, float);//window frame[LORES]
extern void C_006F0D7D(int, int, float);//draw "hand"[LORES]
extern void C_006F193E(int);//menu:set graphic mode[world map]
extern void C_006F19F3(int);//set dialog y offset?
extern void C_006F1A00(struct t_menu_rect *, float);//window frame(3)[HIRES]
extern void C_006F3492(struct t_menu_rect *, float);//window frame(3)[LORES]
extern void C_006F4CFF(int, unsigned char);//menu alpha related?
extern void C_006F4D15(int);//menu alpha related[on/off]?
extern void C_006F4D30(struct t_input_config *, int, int, int, int, int, int, int, int, int, int, int, int, int, int);//input_config:init
extern void C_006F4DB2(struct t_input_config *);//input_config:refresh?
extern int C_006F5317(unsigned, unsigned);//test input mask[pressed]+mouse for menu?
extern int C_006F535C(unsigned, unsigned);//test input mask[trigger]+mouse for menu?
extern unsigned C_006F53A1(unsigned);//test input mask[trigger] for menu?
extern int C_006F53B2(unsigned, unsigned);//test input mask[w repeat]+mouse for menu?
extern int C_006F53F1(unsigned);//test input mask[w repeat] for menu?
extern int C_006F5402(unsigned, unsigned, int);//test input mask for menu?
extern void C_006F5490(int);//menu:set string parameter[unused]
//-- HIRES --
extern int C_006F54A2(const unsigned char *);//ff7 string length[HIRES]
extern int C_006F564E(int, int, int, unsigned short, float);//menu.putchar[HIRES]
extern void C_006F5B03(int, int, const unsigned char *, unsigned char, float);//menu.drawString[HIRES]
extern void C_006F5C0C(int, int, unsigned char, unsigned char, float);//menu.putchar(2)[HIRES]
extern void C_006F62F7(int, int, unsigned char *, unsigned char, float);//menu.drawString(2)[HIRES]
extern void C_006F638C(struct t_menu_small_gauge_14 *, float);//render small gauge[HIRES]
extern void C_006F69AA(int, int, int, int, unsigned);//[HIRES]
extern void C_006F6A0C(struct t_menu_rect *, float);//"slot" rectangle?[HIRES]
extern void C_006F713B(struct t_menu_rect *, float);//"cursor" rectangle?[HIRES]
extern void C_006F7270(struct t_menu_scroller_0e *, float);//"scroller"?[HIRES]
extern void C_006F7346(int, int, int, int, unsigned, float);//draw gauge[HIRES]
extern void C_006F7607(int, int, int, int);//round shade box[HIRES]
extern void C_006F7BFB(int, int, int, int, int, int, int, int, int, float);//2D sprite(for battle)[HIRES]
extern void C_006F9739(int, int, int, char, char, float);//display integer[HIRES]
extern void C_006F9C44(int, int, int, unsigned char, unsigned char, float);//display integer(0-padded)[HIRES]
extern void C_006FA12F(int, int, int, int);//"end scene"(1)[HIRES]
extern void C_006FA347(void);//"end scene"(2)[HIRES]
//-- LORES --
extern int C_006FA55D(const unsigned char *);//ff7 string length[LORES]
extern int C_006FA706(int, int, int, unsigned short, float);//menu.putchar[LORES]
extern void C_006FAB2F(int, int, const unsigned char *, unsigned char, float);//menu.drawString[LORES]
extern void C_006FAC38(int, int, unsigned char, unsigned char, float);//menu.putchar(2)[LORES]
extern void C_006FB35C(int, int, unsigned char *, unsigned char, float);//menu.drawString(2)[LORES]
extern void C_006FB3FF(struct t_menu_small_gauge_14 *, float);//render small gauge[LORES]
extern void C_006FBA29(int, int, int, int, unsigned);//[LORES]
extern void C_006FBAA4(struct t_menu_rect *, float);//"slot" rectangle?[LORES]
extern void C_006FC218(struct t_menu_rect *, float);//"cursor" rectangle?[LORES]
extern void C_006FC38C(struct t_menu_scroller_0e *, float);//"scroller"?[LORES]
extern void C_006FC462(int, int, int, int, unsigned, float);//draw gauge[LORES]
extern void C_006FC73A(int, int, int, int);//round shade box[LORES]
extern void C_006FCD45(int, int, int, int, int, int, int, int, int, float);//2D sprite(for battle)[LORES]
extern void C_006FCF5B(int, int, int, char, char, float);//display integer[LORES]
extern void C_006FD48B(int, int, int, unsigned char, unsigned char, float);//display integer(0-padded)[LORES]
extern void C_006FD9A3(int, int, int, int);//"end scene"(1)[LORES]
extern void C_006FDAEB(void);//"end scene"(2)[LORES]
//-- --
extern void C_006FDC26(struct t_aa0 *);//(for chocobo)?
extern void C_006FE265(unsigned char *, const char *);//C string to ff7 string?
extern void C_006FE4BE(void);
extern void C_006FE53A(int);
extern void C_006FE8DA(int);
extern int C_006FFFAA(void);
extern void C_00701EE4(int);
extern void C_00702085(void);
extern void C_00703517(void);
extern void C_00717961(void);
extern void C_00717D32(void);
extern void C_00717EB6(int);
extern void C_00717FD6(int);
extern void C_0071810C(int);
extern void C_0071820F(void *bp08);
extern int C_00718226(void);
extern int C_007186B9(void);//menu_input:get "current mask"
extern void C_007186C8(void);
extern void C_00719C08(int);
extern void C_0071FF95(int);
extern void C_007201E2(struct t_input_config *);
extern int C_00720746(int, int);
extern void C_00720775(int, int, int);//[HIRES]
extern void C_00720AEE(int, int, int);//[LORES]
extern void C_00720F2F(void);//free savefile?
extern int C_00720F5F(int);//savefile:get some flag?
extern int C_00720F6E(int);//"save" related(2)?
extern int C_007210BC(int, int);//load savefile?
extern void C_0072237A(int);
extern int C_00722393(void);//loadmenu:refresh
extern void C_0072288F(void);
extern void C_00722913(void);
extern unsigned short C_00722ACA(unsigned short, unsigned char *);
extern int C_00722BB0(int);//fade in/out?
////////////////////////////////////////

#endif
