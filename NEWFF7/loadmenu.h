/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
#ifndef __LOADMENU_H__
#define __LOADMENU_H__

//====---- loadmenu.cpp ----====
struct t_loadmenu_preview {//size 0x54
	int f_00;//checksum//00DBFD38
	//
	unsigned char f_04;//00DBFD3C
	unsigned char f_05[3];//00DBFD3D
	unsigned char f_08[0x10];//00DBFD40
	short f_18;//00DBFD50
	short f_1a;//00DBFD52
	short f_1c;//00DBFD54
	short f_1e;//00DBFD56
	int f_20;//00DBFD58
	int f_24;//playtime in seconds//00DBFD5C
	unsigned char f_28[0x20];//current place//00DBFD60
	unsigned char f_48[4*3];//menu colors//00DBFD80
};

struct t_loadmenu_charaInfo {//size 0x84
	unsigned char f_00;//00DBFD8C
	unsigned char f_01;//Level//00DBFD8D
	unsigned char f_02;//00DBFD8E
	unsigned char f_03;//00DBFD8F
	unsigned char f_04;//00DBFD90
	unsigned char f_05;//00DBFD91
	unsigned char f_06;//00DBFD92
	unsigned char f_07;//00DBFD93
	unsigned char f_08;//00DBFD94
	unsigned char f_09;//00DBFD95
	unsigned char f_0a;//00DBFD96
	unsigned char f_0b;//00DBFD97
	unsigned char f_0c;//00DBFD98
	unsigned char f_0d;//00DBFD99
	unsigned char f_0e;//00DBFD9A
	unsigned char f_0f;//00DBFD9B
	unsigned char f_10[0xc];//name//00DBFD9C
	unsigned char f_1c;//00DBFDA8
	unsigned char f_1d;//00DBFDA9
	unsigned char f_1e;//00DBFDAA
	unsigned char f_1f;//status//00DBFDAB
	unsigned char f_20;//00DBFDAC
	unsigned char f_21;//00DBFDAD
	unsigned short f_22;//00DBFDAE
	unsigned short f_24;//00DBFDB0
	unsigned short f_26[3];//00DBFDB2
	unsigned short f_2c;//HP//00DBFDB8
	unsigned short f_2e;//00DBFDBA
	unsigned short f_30;//MP//00DBFDBC
	unsigned short f_32;//00DBFDBE
	char _34[4];//00DBFDC0
	unsigned short f_38;//maxHP//00DBFDC4
	unsigned short f_3a;//maxMP//00DBFDC6
	int f_3c;//00DBFDC8
	unsigned f_40[8];//00DBFDCC
	unsigned f_60[8];//00DBFDEC
	int f_80;//00DBFE0C
};

struct t_loadmenu_10f4 {//size 0x10f4
	struct t_loadmenu_preview f_0000;//00DBFD38
	//-- kernel.bin|section 3 --
	struct t_loadmenu_charaInfo f_0054[9];//00DBFD8C
	unsigned char f_04f8[4];//00DC0230
	unsigned short f_04fc[0x140];//00DC0234
	unsigned f_077c[0xc8];//00DC04B4
	int f_0a9c[0x30];//00DC07D4
	char __0b5c[0x20];//00DC0894
	//
	unsigned f_0b7c;//GILs//00DC08B4
	unsigned f_0b80;//playtime in seconds//00DC08B8
	unsigned f_0b84;//00DC08BC
	unsigned f_0b88;//00DC08C0
	unsigned f_0b8c;//00DC08C4
	//-- kernel load end --
	int   f_0b90;//00DC08C8
	short f_0b94;//00DC08CC
	short f_0b96;//00DC08CE
	char __0b98[2];//00DC08D0
	short f_0b9a;//00DC08D2
	short f_0b9c;//00DC08D4
	short f_0b9e;//00DC08D6
	unsigned char f_0ba0;//00DC08D8
	char f_0ba1;//00DC08D9
	char f_0ba2;//00DC08DA
	char __0ba3[1];//00DC08DB
	unsigned char f_0ba4[0x500];//variable address space(2)//00DC08DC
	unsigned short f_10a4;//00DC0DDC
	unsigned short f_10a6;//00DC0DDE
	char __10a8[0x30];//00DC0DE0
	unsigned char f_10d8;//00DC0E10
	unsigned char f_10d9;//00DC0E11
	unsigned short f_10da;//config word//00DC0E12
	unsigned char f_10dc[0x10];//00DC0E14
	unsigned char f_10ec;//00DC0E24
	char __10ed[7];//00DC0E25
	//~00DC0E2C
};

extern struct t_loadmenu_10f4 D_00DBFD38;//~00DC0E2C
	#define D_00DBFD3C (D_00DBFD38.f_0000.f_04)
	#define D_00DBFD3D (D_00DBFD38.f_0000.f_05)
	#define D_00DBFD40 (D_00DBFD38.f_0000.f_08)
	#define D_00DBFD50 (D_00DBFD38.f_0000.f_18)
	#define D_00DBFD52 (D_00DBFD38.f_0000.f_1a)
	#define D_00DBFD54 (D_00DBFD38.f_0000.f_1c)
	#define D_00DBFD56 (D_00DBFD38.f_0000.f_1e)
	#define D_00DBFD58 (D_00DBFD38.f_0000.f_20)
	#define D_00DBFD5C (D_00DBFD38.f_0000.f_24)
	#define D_00DBFD60 (D_00DBFD38.f_0000.f_28)
	#define D_00DBFD80 (D_00DBFD38.f_0000.f_48)
	#define D_00DC0230 (D_00DBFD38.f_04f8)
	#define D_00DC0234 (D_00DBFD38.f_04fc)
	#define D_00DC04B4 (D_00DBFD38.f_077c)
	#define D_00DC08B4 (D_00DBFD38.f_0b7c)
	#define D_00DC08B8 (D_00DBFD38.f_0b80)
	#define D_00DC08BC (D_00DBFD38.f_0b84)
	#define D_00DC08C0 (D_00DBFD38.f_0b88)
	//-- BANK 0x000~ --
	#define D_00DC08DC (D_00DBFD38.f_0ba4[0x000])
	#define D_00DC08DD (D_00DBFD38.f_0ba4[0x001])
	#define D_00DC08DE (D_00DBFD38.f_0ba4[0x002])
	//-- time related? --
	#define D_00DC08EC (D_00DBFD38.f_0ba4[0x010])
	#define D_00DC08ED (D_00DBFD38.f_0ba4[0x011])
	#define D_00DC08EE (D_00DBFD38.f_0ba4[0x012])
	#define D_00DC08EF (D_00DBFD38.f_0ba4[0x013])
	#define D_00DC08F0 (D_00DBFD38.f_0ba4[0x014])
	#define D_00DC08F1 (D_00DBFD38.f_0ba4[0x015])
	//-- countdown? --
	#define D_00DC08F2 ((unsigned char *)(D_00DBFD38.f_0ba4 + 0x16))
	//#define D_00DC08F3 (D_00DC08F2[1])
	//-- --
	#define D_00DC08F4 (D_00DBFD38.f_0ba4[0x018])
	#define D_00DC08F5 (D_00DBFD38.f_0ba4[0x019])
	#define D_00DC08F6 (D_00DBFD38.f_0ba4[0x01a])
	#define D_00DC08F7 (D_00DBFD38.f_0ba4[0x01b])
	#define D_00DC08F8 (D_00DBFD38.f_0ba4[0x01c])
	#define D_00DC08F9 (D_00DBFD38.f_0ba4[0x01d])
	#define D_00DC08FA (D_00DBFD38.f_0ba4[0x01e])
	#define D_00DC08FB (D_00DBFD38.f_0ba4[0x01f])
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
	#define D_00DC0DDE (D_00DBFD38.f_10a6)
	#define D_00DC0E10 (D_00DBFD38.f_10d8)
	#define D_00DC0E11 (D_00DBFD38.f_10d9)
	#define D_00DC0E12 (D_00DBFD38.f_10da)
	#define D_00DC0E24 (D_00DBFD38.f_10ec)

//extern unsigned char D_00DC0E6C;//pause related?
//extern unsigned char D_00DC0E70;

#endif
