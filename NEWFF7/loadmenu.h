/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
#ifndef __LOADMENU_H__
#define __LOADMENU_H__

//====---- loadmenu.cpp ----====
struct t_loadmenu_preview {//size 0x54
	/*00*/int f_00;//checksum//00DBFD38
	//
	/*04*/unsigned char f_04;//00DBFD3C
	/*05*/unsigned char f_05[3];//00DBFD3D
	/*08*/unsigned char f_08[0x10];//00DBFD40
	/*18*/short f_18,f_1a;//HP,HPMax//00DBFD50,00DBFD52
	/*1c*/short f_1c,f_1e;//MP,MPMAX//00DBFD54,00DBFD56
	/*20*/int f_20;//00DBFD58
	/*24*/int f_24;//playtime in seconds//00DBFD5C
	/*28*/unsigned char f_28[0x20];//current place//00DBFD60
	/*48*/unsigned char f_48[4*3];//menu colors//00DBFD80
};

struct t_loadmenu_charaInfo {//size 0x84
	/*00*/unsigned char f_00;//00DBFD8C
	/*01*/unsigned char f_01;//Level//00DBFD8D
	/*02*/unsigned char f_02;//00DBFD8E
	/*03*/unsigned char f_03;//00DBFD8F
	/*04*/unsigned char f_04;//00DBFD90
	/*05*/unsigned char f_05;//00DBFD91
	/*06*/unsigned char f_06;//00DBFD92
	/*07*/unsigned char f_07;//00DBFD93
	/*08*/unsigned char f_08;//00DBFD94
	/*09*/unsigned char f_09;//00DBFD95
	/*0a*/unsigned char f_0a;//00DBFD96
	/*0b*/unsigned char f_0b;//00DBFD97
	/*0c*/unsigned char f_0c;//00DBFD98
	/*0d*/unsigned char f_0d;//00DBFD99
	/*0e*/unsigned char bLimitLvl;//00DBFD9A
	/*0f*/unsigned char bLimitGauge;//00DBFD9B
	/*10*/unsigned char f_10[0xc];//name//00DBFD9C
	/*1c*/unsigned char f_1c;//00DBFDA8
	/*1d*/unsigned char f_1d;//00DBFDA9
	/*1e*/unsigned char f_1e;//00DBFDAA
	/*1f*/unsigned char f_1f;//status//00DBFDAB
	/*20*/unsigned char f_20;//00DBFDAC
	/*21*/unsigned char f_21;//00DBFDAD
	/*22*/unsigned short f_22;//00DBFDAE
	/*24*/unsigned short f_24;//00DBFDB0
	/*26*/unsigned short f_26[3];//00DBFDB2
	/*2c*/unsigned short f_2c;//HP//00DBFDB8
	/*2e*/unsigned short f_2e;//00DBFDBA
	/*30*/unsigned short f_30;//MP//00DBFDBC
	/*32*/unsigned short f_32;//00DBFDBE
	/*34*/char _34[4];//00DBFDC0
	/*38*/unsigned short f_38;//maxHP//00DBFDC4
	/*3a*/unsigned short f_3a;//maxMP//00DBFDC6
	/*3c*/int f_3c;//00DBFDC8
	/*40*/unsigned f_40[8];//00DBFDCC
	/*60*/unsigned f_60[8];//00DBFDEC
	/*80*/int f_80;//00DBFE0C
};

/*
	config mask format
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
	|///|bat|///|magic order| camera| A T B | cursor|control|  ???  |
	|///|inf|///|           |       |       |       |       |       |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
*/

struct t_loadmenu_10f4 {//size 0x10f4
	/*0000*/struct t_loadmenu_preview f_0000;//00DBFD38
	//-- kernel.bin|section 3 --
	/*0054*/struct t_loadmenu_charaInfo f_0054[9];//00DBFD8C
	/*04f8*/unsigned char f_04f8[4];//00DC0230
	/*04fc*/unsigned short f_04fc[0x140];//00DC0234
	/*077c*/unsigned f_077c[0xc8];//00DC04B4
	/*0a9c*/int f_0a9c[0x30];//00DC07D4
	/*0b5c*/char __0b5c[0x20];//00DC0894
	//
	/*0b7c*/unsigned dwGIL;//00DC08B4
	/*0b80*/unsigned dwPlayTime;//(in seconds)//00DC08B8
	/*0b84*/unsigned dwTimer;//00DC08BC
	/*0b88*/unsigned dwCounter1;//00DC08C0
	/*0b8c*/unsigned dwCounter2;//00DC08C4
	//-- kernel load end --
	/*0b90*/int f_0b90;//00DC08C8
	/*0b94*/short f_0b94;//00DC08CC
	/*0b96*/short f_0b96;//00DC08CE
	/*0b98*/char __0b98[2];//00DC08D0
	/*0b9a*/short f_0b9a;//00DC08D2
	/*0b9c*/short f_0b9c;//00DC08D4
	/*0b9e*/short f_0b9e;//00DC08D6
	/*0ba0*/unsigned char f_0ba0;//00DC08D8
	/*0ba1*/char f_0ba1;//00DC08D9
	/*0ba2*/char f_0ba2;//00DC08DA
	/*0ba3*/char __0ba3[1];//00DC08DB
	/*0ba4*/unsigned char f_0ba4[0x500];//variable address space(2)//00DC08DC
	/*10a4*/unsigned short f_10a4;//00DC0DDC
	/*10a6*/unsigned short f_10a6;//phs related/00DC0DDE
	/*10a8*/char __10a8[0x30];//00DC0DE0
	/*10d8*/unsigned char f_10d8;//battle speed/00DC0E10
	/*10d9*/unsigned char f_10d9;//battle message speed/00DC0E11
	/*10da*/unsigned short wConfigMask;//00DC0E12
	/*10dc*/unsigned char f_10dc[0x10];//00DC0E14
	/*10ec*/unsigned char f_10ec;//field/world message speed/00DC0E24
	/*10ed*/char __10ed[7];//00DC0E25
	//~00DC0E2C
};

extern struct t_loadmenu_10f4 D_00DBFD38;//~00DC0E2C
	//-- BANK 0x000~ --
	#define D_00DC08DC (*(unsigned short *)(D_00DBFD38.f_0ba4 + 0x000))
	#define D_00DC08DE (D_00DBFD38.f_0ba4[0x002])
	//-- time related? --
	#define D_00DC08EC (D_00DBFD38.f_0ba4[0x010])
	#define D_00DC08ED (D_00DBFD38.f_0ba4[0x011])
	#define D_00DC08EE (D_00DBFD38.f_0ba4[0x012])
	#define D_00DC08EF (D_00DBFD38.f_0ba4[0x013])
	#define D_00DC08F0 (D_00DBFD38.f_0ba4[0x014])
	#define D_00DC08F1 (D_00DBFD38.f_0ba4[0x015])
	//-- countdown? --
	#define D_00DC08F2 ((unsigned char *)(D_00DBFD38.f_0ba4 + 0x016))
	//#define D_00DC08F3 (D_00DC08F2[1])
	//-- --
	#define D_00DC08F4 (D_00DBFD38.f_0ba4[0x018])
	#define D_00DC08F5 (D_00DBFD38.f_0ba4[0x019])
	#define D_00DC08F6 (D_00DBFD38.f_0ba4[0x01a])
	#define D_00DC08F7 (D_00DBFD38.f_0ba4[0x01b])
	#define D_00DC08FA (*(unsigned short *)(D_00DBFD38.f_0ba4 + 0x01e))
	#define D_00DC091C ((unsigned char *)(D_00DBFD38.f_0ba4 + 0x040))
	#define D_00DC0927 (D_00DBFD38.f_0ba4[0x04b])
	#define D_00DC093B (D_00DBFD38.f_0ba4[0x05f])
	//-- battle point --
	#define D_00DC094C (D_00DBFD38.f_0ba4[0x070])
	#define D_00DC094D (D_00DBFD38.f_0ba4[0x071])
	#define D_00DC094E (D_00DBFD38.f_0ba4[0x072])
	#define D_00DC094F (D_00DBFD38.f_0ba4[0x073])
	//-- --
	#define D_00DC0950 (D_00DBFD38.f_0ba4[0x074])
	#define D_00DC0956 (D_00DBFD38.f_0ba4[0x07a])
	//-- BANK 0x100~ --
	#define D_00DC09E5 (&(D_00DBFD38.f_0ba4[0x109]))
	//#define D_00DC09E6 (D_00DC09E5[1])
	//#define D_00DC09E7 (D_00DC09E5[2])
	#define D_00DC0A3E (D_00DBFD38.f_0ba4[0x162])
	#define D_00DC0A3F (D_00DBFD38.f_0ba4[0x163])
	#define D_00DC0A4F (D_00DBFD38.f_0ba4[0x173])
	#define D_00DC0A50 (&(D_00DBFD38.f_0ba4[0x174]))
	#define D_00DC0A61 (D_00DBFD38.f_0ba4[0x185])
	#define D_00DC0AA0 (D_00DBFD38.f_0ba4 + 0x1c4)
	#define D_00DC0AAA (D_00DBFD38.f_0ba4[0x1ce])
	//-- BANK 0x200~ --
	//-- chocobo? --
	#define D_00DC0ADC ((unsigned char *)(D_00DBFD38.f_0ba4 + 0x200))
	#define D_00DC0AE2 (D_00DBFD38.f_0ba4[0x206])
	#define D_00DC0AE3 (D_00DBFD38.f_0ba4[0x207])
	#define D_00DC0AE4 (D_00DBFD38.f_0ba4[0x208])
	#define D_00DC0AE5 (D_00DBFD38.f_0ba4[0x209])
	#define D_00DC0AE6 (D_00DBFD38.f_0ba4[0x20a])
	#define D_00DC0AE7 (D_00DBFD38.f_0ba4[0x20b])
	#define D_00DC0AE8 (D_00DBFD38.f_0ba4[0x20c])
	#define D_00DC0AE9 (D_00DBFD38.f_0ba4[0x20d])
	#define D_00DC0AEA (D_00DBFD38.f_0ba4[0x20e])
	#define D_00DC0AEB (D_00DBFD38.f_0ba4[0x20f])
	#define D_00DC0AEC (D_00DBFD38.f_0ba4[0x210])
	#define D_00DC0AED (D_00DBFD38.f_0ba4[0x211])
	#define D_00DC0AEE (D_00DBFD38.f_0ba4[0x212])
	#define D_00DC0AF2 (D_00DBFD38.f_0ba4[0x216])
	#define D_00DC0AF3 (D_00DBFD38.f_0ba4[0x217])
	#define D_00DC0AF5 (D_00DBFD38.f_0ba4[0x219])
	#define D_00DC0AF6 (D_00DBFD38.f_0ba4[0x21a])
	#define D_00DC0AF7 (D_00DBFD38.f_0ba4[0x21b])
	#define D_00DC0AF8 (D_00DBFD38.f_0ba4[0x21c])
	//-- highway? --
	#define D_00DC0B47 (D_00DBFD38.f_0ba4[0x26b])
	#define D_00DC0B48 (D_00DBFD38.f_0ba4[0x26c])
	#define D_00DC0B49 (D_00DBFD38.f_0ba4[0x26d])
	#define D_00DC0B4A (D_00DBFD38.f_0ba4[0x26e])
	#define D_00DC0B4B (D_00DBFD38.f_0ba4[0x26f])
	#define D_00DC0B4C (D_00DBFD38.f_0ba4 + 0x270)
	#define D_00DC0B5B (D_00DBFD38.f_0ba4[0x27f])
	//-- BANK 0x300~ --
	//expected CD number?
	#define D_00DC0BDC (D_00DBFD38.f_0ba4[0x300])
	#define D_00DC0BDE (&(D_00DBFD38.f_0ba4[0x302]))
	#define D_00DC0BE2 (D_00DBFD38.f_0ba4[0x306])
	#define D_00DC0BE3 (D_00DBFD38.f_0ba4[0x307])
	#define D_00DC0BFA (D_00DBFD38.f_0ba4[0x31e])
	#define D_00DC0BFB (D_00DBFD38.f_0ba4[0x31f])
	#define D_00DC0C39 (D_00DBFD38.f_0ba4[0x35d])
	#define D_00DC0C3A (D_00DBFD38.f_0ba4[0x35e])
	#define D_00DC0C3B (D_00DBFD38.f_0ba4[0x35f])
	#define D_00DC0C3C (D_00DBFD38.f_0ba4[0x360])
	#define D_00DC0C3D (D_00DBFD38.f_0ba4[0x361])

	#define D_00DC0C44 ((unsigned char *)(D_00DBFD38.f_0ba4 + 0x368))
	#define D_00DC0C62 (D_00DBFD38.f_0ba4[0x386])
	#define D_00DC0C90 (*(unsigned short *)&(D_00DBFD38.f_0ba4[0x3b4]))
	#define D_00DC0C92 (*(unsigned short *)&(D_00DBFD38.f_0ba4[0x3b6]))
	#define D_00DC0C94 (D_00DBFD38.f_0ba4[0x3b8])
	#define D_00DC0CC4 ((unsigned *)&(D_00DBFD38.f_0ba4[0x3e8]))
	#define D_00DC0CD0 (*(int *)&(D_00DBFD38.f_0ba4[0x3f4]))
	#define D_00DC0CD4 (*(unsigned short *)(D_00DBFD38.f_0ba4 + 0x3f8))
	#define D_00DC0CD7 (D_00DBFD38.f_0ba4[0x3fb])
	#define D_00DC0CD8 (D_00DBFD38.f_0ba4[0x3fc])
	#define D_00DC0CD9 (D_00DBFD38.f_0ba4[0x3fd])
	#define D_00DC0CDA (D_00DBFD38.f_0ba4[0x3fe])
	#define D_00DC0CDB (D_00DBFD38.f_0ba4[0x3ff])
//00DC0CDC
	//-- BANK 0x400~ --
	#define D_00DC0D4B (D_00DBFD38.f_0ba4[0x46f])
	#define D_00DC0D5F (D_00DBFD38.f_0ba4[0x483])
	//-- --

//extern unsigned char D_00DC0E6C;//pause related?
//extern unsigned char D_00DC0E70;
extern char D_00DD74E8[/*256*/];//from loadmenu.cpp
extern char D_00DD75E8[0xa][3];
extern struct t_loadmenu_10f4 *D_00DD7700;

#endif
