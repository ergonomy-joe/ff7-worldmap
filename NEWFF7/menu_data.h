/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
#ifndef __MENU_DATA_H__
#define __MENU_DATA_H__

//00DC20A0/size 0x1500=3*0x700?
struct t_menu_battle_700 {//size 0x700 = 0x20 * 0x38
	/*0x000*/struct t_input_config f_000;//_00DC20A0
	/*0x038*/struct t_input_config f_038;//_00DC20D8
	/*0x070*/struct t_input_config f_070;//_00DC2110
	/*0x0A8*/struct t_input_config f_0a8;//_00DC2148
	/*0x0E0*/struct t_input_config f_0e0;//_00DC2180//int _00DC2184; int _00DC2194;
	/*0x118*/struct t_input_config f_118;//_00DC21B8
	/*0x150*/struct t_input_config f_150;//_00DC21F0
	/*0x188*/struct t_input_config f_188;//_00DC2228
	/*0x1c0*/struct t_input_config f_1c0;//_00DC2260
	/*0x1f8*/char __pad[0x6c8 - 0x1f8];
	/*0x6c8*/struct t_input_config f_6c8;//_00DC2768
};

struct t_menu_shop_local___ {//size 0x24?
	unsigned char f_00;
	unsigned char f_01;
	char __02[2];
	int f_04;
	char __08[2];
	short f_0a[8];
	unsigned char f_1a[5][2];
};

//aka "struct t_menu_0e"
struct t_menu_scroller_0e {//size 0xe
	short f_00;
	short f_02;
	short f_04;
	//struct t_menu_rect f_06;?
	short f_06,f_08,f_0a,f_0c;//wX,wY,wWidth,wHeight
};

//aka "struct t_menu_14"
struct t_menu_small_gauge_14 {
	/*00*/short wX,wY;
	/*04*/short wWidth,wHeight;
	/*08*/short wVal,wMax;
	/*0c*/short f_0c;
	/*0e*/short wExVal;
	/*10*/tRGBA f_10;
};

struct t_menu_temp_10 {
	unsigned char f_00[2];//_00DBCAE0
	unsigned char f_02[2];//_00DBCAE2
	unsigned char f_04;//_00DBCAE4
	unsigned char f_05;//_00DBCAE5
	unsigned short f_06;//_00DBCAE6
	int f_08;//_00DBCAE8
	unsigned short f_0c;//_00DBCAEC
	unsigned short f_0e;//_00DBCAEE
};

struct t_menu_temp_24 {
	char __00[1];//_00DBCCE0
	unsigned char f_01;//_00DBCCE1
	unsigned char f_02;//_00DBCCE2
	unsigned char f_03;//_00DBCCE3
	unsigned char f_04;//_00DBCCE4
	unsigned char f_05;//_00DBCCE5
	unsigned char f_06;//_00DBCCE6
	char __07[2];//_00DBCCE7
	unsigned char f_09[8];//_00DBCCE9
	unsigned char f_11;//_00DBCCF1
	unsigned short f_12;//_00DBCCF2
	unsigned short f_14;//_00DBCCF4
	char __16[2];//_00DBCCF6
	unsigned char f_18[4];//_00DBCCF8
	unsigned char f_1c[4];//_00DBCCFC
	unsigned short f_20;//_00DBCD00
	char __22[2];//_00DBCD02
};

struct t_menu_temp_1c {
	unsigned char f_00;//00DBD160
	unsigned char f_01;//00DBD161
	unsigned char f_02;//00DBD162
	char __03[1];//00DBD163
	unsigned short f_04;//00DBD164
	short f_06;//00DBD166
	unsigned short f_08[2];//00DBD168
	//unsigned short f_0a;//00DBD16A
	unsigned char f_0c;//00DBD16C
	unsigned char f_0d;//00DBD16D
	unsigned char f_0e;//00DBD16E
	unsigned char f_0f;//00DBD16F
	unsigned char f_10;//00DBD170
	unsigned char f_11;//00DBD171
	unsigned char f_12;//00DBD172
	unsigned char f_13;//00DBD173
	int f_14;//00DBD174
	unsigned short f_18;//00DBD178
	unsigned short f_1a;//00DBD17A
};

struct t_menu_temp_14 {
	unsigned short f_00[4];//00DBDF60
	unsigned char f_08;//00DBDF68
	unsigned char f_09;//00DBDF69
	unsigned char f_0a;//00DBDF6A
	unsigned char f_0b;//00DBDF6B
	unsigned char f_0c;//00DBDF6C
	unsigned char f_0d;//00DBDF6D
	unsigned char f_0e;//00DBDF6E
	unsigned char f_0f[5];//00DBDF6F
};

struct t_menu_temp_2c {
	unsigned char f_00;//_00DBE730
	unsigned char f_01;//_00DBE731
	unsigned char f_02;//_00DBE732
	char __03[1];//_00DBE733
	unsigned char f_04;//_00DBE734
	unsigned char f_05;//_00DBE735
	unsigned char f_06;//_00DBE736
	unsigned char f_07;//_00DBE737
	unsigned char f_08;//_00DBE738
	unsigned char f_09;//_00DBE739
	char __0a[1];//_00DBE73A
	unsigned char f_0b;//_00DBE73B
	unsigned short f_0c;//_00DBE73C
	unsigned short f_0e;//_00DBE73E
	unsigned short f_10;//_00DBE740
	char __12[2];//_00DBE742
	unsigned char f_14[4];//_00DBE744
	unsigned char f_18[4];//_00DBE748
	unsigned char f_1c[1];//_00DBE74C
	char __1d[0x24 - 0x1d];//_00DBE74D
	unsigned char f_24[3];//_00DBE754
	unsigned char f_27;//_00DBE757
	unsigned short f_28;//_00DBE758
	unsigned short f_2a;//_00DBE75A
};

struct t_menu_something_size_1c {//TODO
	unsigned char __00[0x1c];//_00DBA54C
};

struct t_menu_something_size_08 {
	unsigned char f_00;
	unsigned char f_01;
	unsigned char f_02;
	unsigned char f_03;
	unsigned char f_04;
	unsigned char f_05;
	unsigned char f_06;
	unsigned char f_07;
};
struct t_battle_local_toto_06 {
	unsigned char f_00;//009AEAB8
	unsigned char f_01;//009AEAB9
	unsigned char f_02;//009AEABA
	unsigned char f_03;//009AEABB
	unsigned char f_04;//009AEABC
	unsigned char f_05;//009AEABD
};

struct t_menu_temp_440 {
	unsigned char f_000;//_00DBA498
	unsigned char f_001;//00DBA499
	unsigned char f_002;//00DBA49A
	unsigned char f_003;//00DBA49B
	unsigned char f_004;//00DBA49C
	unsigned char f_005;//00DBA49D
	unsigned char f_006;//00DBA49E
	unsigned char f_007;//00DBA49F
	unsigned short f_008;//00DBA4A0
	unsigned short f_00a;//00DBA4A2
	unsigned short f_00c;//00DBA4A4
	unsigned short f_00e;//00DBA4A6
	short f_010,f_012;//HP/HPMAX//00DBA4A8,00DBA4AA
	short f_014,f_016;//MP/MPMAX//00DBA4AC,00DBA4AE
	unsigned short f_018;//WAIT//00DBA4B0
	unsigned short f_01a;//LIMIT//00DBA4B2
	unsigned short f_01c;//BARRIER(physical)//00DBA4B4
	unsigned short f_01e;//BARRIER(magical)//00DBA4B6
	unsigned char f_020;//00DBA4B8
	unsigned char f_021;//00DBA4B9
	unsigned char f_022;//00DBA4BA
	unsigned char f_023;//00DBA4BB
	char f_024[1][3];//00DBA4BC//check
	char __027[0x15];//00DBA4BF
	unsigned short f_03c;//00DBA4D4
	unsigned short f_03e;//00DBA4D6
	unsigned short f_040;//00DBA4D8
	unsigned short f_042;//00DBA4DA
	int f_044;//00DBA4DC
	int f_048;//00DBA4E0
	struct t_battle_local_toto_06 f_04c[0x10];//00DBA4E4
	//-- start of a structure? --
	unsigned char f_0ac[8];//00DBA544//f_0ac +00
	struct t_menu_something_size_1c f_0b4[3];//00DBA54C//f_0ac +08
	struct t_menu_something_size_08 f_108[0x38];//00DBA5A0
	struct t_menu_something_size_08 f_2c8[0x10];//00DBA760
	struct t_menu_something_size_08 f_348[0x18];//00DBA7E0
	struct t_menu_temp_2c f_408;//00DBA8A0
		//unsigned char _00DBA8A5;f_408.f_05
		//unsigned short _00DBA8B0;f_408.f_10
		//unsigned char _00DBA8B4[4];f_408.f_14
		//unsigned char _00DBA8B8[4];f_408.f_18
	char __434[3];//00DBA8CC
	unsigned char f_437;//00DBA8CF
	char __438[4];//00DBA8D0
	unsigned char f_43c;//00DBA8D4
	unsigned char f_43d;//00DBA8D5
	unsigned char f_43e;//00DBA8D6
	unsigned char f_43f;//00DBA8D7
};

struct t_battle_local_08_IIII {//size 8
	unsigned char f_00;
	unsigned char f_01;
	char f_02;
	char f_03;
	unsigned short f_04;
	unsigned short f_06;
};
////////////////////////////////////////
extern int D_00919928[];
extern unsigned char D_0091A8C0[][0x14];
extern tRGBA D_0091AB08[];
extern unsigned D_0091EFC8[/*4*/];
extern unsigned char D_0091EFD8[/*4*3*/];
extern unsigned char D_00920540[][0xa];
extern unsigned char D_00925760[][0x24];
extern unsigned char D_00925C98[][0x30];
extern unsigned char D_00926118[][0xc];

extern char D_00D8E490[/*0x1000*/];//check

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
extern int C_006C50DD(int);
extern int C_006C5154(int, int);
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
extern void *C_006CB8E2(int);
extern void *C_006CB928(int);
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
extern void C_006CC3E8(void);
extern void C_006CC446(void);
extern void C_006CC4A8(void);
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
extern void C_006E6C30(tRGBA *, unsigned char, unsigned char, unsigned char);
extern void C_006E6C5B(int, int, int, float);//draw portrait[HIRES]
extern void C_006E6E66(int, int, int, int, int, float);//draw portrait[for preview][HIRES]
extern void C_006E7B6A(int, int, int, int);//[HIRES]
extern void C_006E7BA1(struct t_menu_rect *, int, int, int, int);//menu:set rect
extern void C_006E7BD1(struct t_menu_rect *, int, int);//menu:rect += {x,y}
extern void C_006E7BF8(struct t_menu_rect *, struct t_menu_rect *);//menu:copy rect
extern void C_006E7C33(void);//menu:backup color option?
extern void C_006E7C69(void);//menu:restore color option?
extern void C_006E7C9F(tRGBA *);//menu:set color option?
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
extern void C_006F193E(int);//menu related?
extern void C_006F19F3(int);//set dialog y offset?
extern void C_006F1A00(struct t_menu_rect *, float);//window frame(3)[HIRES]
extern void C_006F3492(struct t_menu_rect *, float);//window frame(3)[LORES]
extern void C_006F4D15(int);
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
extern void C_006F7BFB(int, int, int, int, int, int, int, int, int, float);//2D sprite(for battle)[HIRES]
extern void C_006F9739(int, int, int, char, char, float);//display integer[HIRES]
extern void C_006F9C44(int, int, int, unsigned char, unsigned char, float);//display integer(2)[HIRES]
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
extern void C_006FCD45(int, int, int, int, int, int, int, int, int, float);//2D sprite(for battle)[LORES]
extern void C_006FCF5B(int, int, int, char, char, float);//display integer[LORES]
extern void C_006FD48B(int, int, int, unsigned char, unsigned char, float);//display integer(2)[LORES]
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
