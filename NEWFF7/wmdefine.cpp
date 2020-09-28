/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
#define __FF7FILE__ "C:\\FF7\\src\\wm\\wmdefine.cpp"

#include "ff7.h"
#include "wm_data.h"
////////////////////////////////////////
//TODO in another module?
struct VECTOR D_00E2D1E0;
struct SVECTOR D_00E2D1F0;
struct SVECTOR D_00E2D1F8;
short D_00E2D200;
//char 00E2D204[0x3d4]?
struct SVECTOR D_00E2D5D8;
////////////////////////////////////////
unsigned char *D_00E2D5E0;
unsigned char *D_00E2D5E4;
unsigned char *D_00E2D5E8;
unsigned char *D_00E2D5EC;
unsigned char *D_00E2D5F0;
unsigned char *D_00E2D5F4;
unsigned char *D_00E2D5F8;
struct POLY_GT3 *D_00E2D5FC;
char *D_00E2D600;
////////////////////////////////////////
//wmdefine:init?
void C_0075AB50() {
	D_00E2D600 = (char *)mem_malloc(0xE7801, __FF7FILE__, 0x1f);
	if(D_00E2D600) {
		//-- unused --
		D_00E2D5E0 = (unsigned char *)(D_00E2D600);
		D_00E2D5E4 = (unsigned char *)(D_00E2D600 + 0x79000);
		//-- unused--
		D_00E2D5E8 = (unsigned char *)(D_00E2D600);
		D_00E2D5EC = (unsigned char *)(D_00E2D600 + 0x23800);
		D_00E2D5F0 = (unsigned char *)(D_00E2D600 + 0x33600);//0x23800 + 0xfe00
		D_00E2D5F4 = (unsigned char *)(D_00E2D600 + 0x38C00);//0x33600 + 0x5600
		//-- --
		D_00E2D5F8 = (unsigned char *)(D_00E2D600 + 0x3F000);//0x38C00 + 0x6400
		D_00E2D5FC = (struct POLY_GT3 *)(D_00E2D600 + 0xA6800);//0x3F000 + 9 * 0xb800
		//0xe7801 = 0xA6800 + 0x1a00 * 0x28 + 1
	}
}

//wmdefine:clean?
void C_0075ABF3() {
	if(D_00E2D600) {
		mem_free(D_00E2D600, __FF7FILE__, 0x34);
		D_00E2D600 = 0;

		D_00E2D5E0 =
		D_00E2D5E4 =
		D_00E2D5EC =
		D_00E2D5F0 =
		D_00E2D5F8 = 0;

		D_00E2D5E8 = 
		D_00E2D5F4 = 0;

		D_00E2D5FC = 0;
	}
}
