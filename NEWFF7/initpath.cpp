/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
#define __FF7FILE__ "C:\\FF7\\Src\\main\\initpath.cpp"

#include "ff7.h"
#include "menu_data.h"
////////////////////////////////////////
const char D_007B6550[] = "Software\\Square Soft, Inc.\\Final Fantasy VII";
const char D_007B6580[] = "AppPath";
const char D_007B6588[] = "MoviePath";
const char D_007B6598[] = "DataDrive";
const char D_007B65A8[] = "DataPath";
const char D_007B65B8[] = "MusicVolume";
const char D_007B65C8[] = "SFXVolume";
const char D_007B65D8[] = "FullInstall";
const char D_007B65E8[] = "Software\\Square Soft, Inc.\\Final Fantasy VII\\1.00\\Sound";
const char D_007B6620[] = "Software\\Square Soft, Inc.\\Final Fantasy VII\\1.00\\Midi";
////////////////////////////////////////
char D_009A0598[256];
char *D_009A0698;//AppPath
char *D_009A069C;//MoviePath
int   D_009A06A0;//sound "on" flag
char *D_009A06A4;//music path
char *D_009A06A8;//sound path
char *D_009A06AC;//midi path
int   D_009A06B0;//midi "on" flag
char *D_009A06B4;//a path
char *D_009A06B8;//DataPath
int   D_009A06BC;//FullInstall
char *D_009A06C0;//DataDrive
char *D_009A06C4;//minigame path
////////////////////////////////////////
//initpath:start?
void C_00406D10(void) {
	struct {
		HKEY hKey;//local_136
		char local_135[6]; char _ocal_135[2];// = "Sound";
		LONG local_133;
		char local_132[5]; char _ocal_132[3];// = "Midi";
		DWORD dwType;//local_130
		char local_129[256];
		char local_065[256];
		DWORD cbData;//local_001
	}lolo;

	memcpy(lolo.local_135, "Sound", 6);//char local_135[] = "Sound";
	memcpy(lolo.local_132, "Midi", 5);//char local_132[] = "Midi";

	D_009A0698 = (char *)C_0065FF59(0x100, 1, __FF7FILE__, 0x37);
	D_009A069C = (char *)C_0065FF59(0x100, 1, __FF7FILE__, 0x38);
	D_009A06C0 = (char *)C_0065FF59(0x100, 1, __FF7FILE__, 0x39);
	D_009A06B8 = (char *)C_0065FF59(0x100, 1, __FF7FILE__, 0x3A);
	D_009A06A8 = (char *)C_0065FF59(0x100, 1, __FF7FILE__, 0x3B);
	D_009A06A4 = (char *)C_0065FF59(0x100, 1, __FF7FILE__, 0x3C);
	D_009A06AC = (char *)C_0065FF59(0x100, 1, __FF7FILE__, 0x3D);
	D_009A06C4 = (char *)C_0065FF59(0x100, 1, __FF7FILE__, 0x3E);
	D_009A06B4 = (char *)C_0065FF59(0x100, 1, __FF7FILE__, 0x3f);

	//.../Final Fantasy VII:
	lolo.local_133 = RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B6550, 0, KEY_READ/*0x20019*/, &lolo.hKey);
	FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM/*0x1000*/, 0, GetLastError(), 0, (char *)&lolo.local_129, 0x100, 0);
	if(lolo.local_133 == 0) {
		//"DataDrive"
		lolo.cbData = 0x100;
		lolo.local_133 = RegQueryValueEx(lolo.hKey, D_007B6598, 0, &lolo.dwType, (LPBYTE)lolo.local_065, &lolo.cbData);
		strcpy(D_009A06C0, lolo.local_065);
		//"Sound"
		lolo.cbData = 0x100;
		lolo.local_133 = RegQueryValueEx(lolo.hKey, lolo.local_135, 0, &lolo.dwType, (LPBYTE)lolo.local_065, &lolo.cbData);
		if(lolo.local_133 == 0) {
			if(strcmp(lolo.local_065, "ON") == 0)
				D_009A06A0 = 1;
			else
				D_009A06A0 = 0;
		} else {
			D_009A06A0 = 1;
		}
		//"Midi"
		lolo.cbData = 0x100;
		lolo.local_133 = RegQueryValueEx(lolo.hKey, lolo.local_132, 0, &lolo.dwType, (LPBYTE)lolo.local_065, &lolo.cbData);
		if(lolo.local_133 == 0) {
			if(strcmp(lolo.local_065, "ON") == 0)
				D_009A06B0 = 1;
			else
				D_009A06B0 = 0;
		} else {
			D_009A06B0 = 1;
		}
		//"AppPath"
		lolo.cbData = 0x100;
		lolo.local_133 = RegQueryValueEx(lolo.hKey, D_007B6580, 0, &lolo.dwType, (LPBYTE)lolo.local_065, &lolo.cbData);
		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM/*0x1000*/, 0, GetLastError(), 0, (char *)&lolo.local_129, 0x100, 0);
		if(lolo.local_133 == 0)
			strcpy(D_009A0698, lolo.local_065);
		else
			strcpy(D_009A0698, "/ff7/");
		//"DataPath"
		lolo.cbData = 0x100;
		lolo.local_133 = RegQueryValueEx(lolo.hKey, D_007B65A8, 0, &lolo.dwType, (LPBYTE)lolo.local_065, &lolo.cbData);
		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM/*0x1000*/, 0, GetLastError(), 0, (char *)&lolo.local_129, 0x100, 0);
		if(lolo.local_133 == 0)
			strcpy(D_009A06B8, lolo.local_065);
		else
			strcpy(D_009A06B8, "/ff7/data/");
		//"MoviePath"
		lolo.cbData = 0x100;
		lolo.local_133 = RegQueryValueEx(lolo.hKey, D_007B6588, 0, &lolo.dwType, (LPBYTE)lolo.local_065, &lolo.cbData);
		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM/*0x1000*/, 0, GetLastError(), 0, (char *)lolo.local_129, 0x100, 0);
		if(lolo.local_133 == 0)
			strcpy(D_009A069C, lolo.local_065);
		else
			strcpy(D_009A069C, "/ff7/data/movies/");
		//"FullInstall"
		lolo.cbData = 4;
		lolo.local_133 = RegQueryValueEx(lolo.hKey, D_007B65D8, 0, &lolo.dwType, (LPBYTE)&D_009A06BC, &lolo.cbData);
		if(lolo.local_133 == 0) {//else 004072B2
			if(D_009A06BC) {
				strcpy(D_009A06B4, D_009A06B8);
			} else {
				strcpy(D_009A06B4, D_009A06C0);
				strcat(D_009A06B4, "ff7/");
			}
		} else {
			strcpy(D_009A06B4, D_009A06C0);
			strcat(D_009A06B4, "ff7/");
		}

		strcpy(D_009A06A8, D_009A06B8);
		strcat(D_009A06A8, "sound");

		strcpy(D_009A06A4, D_009A06B8);
		strcat(D_009A06A4, "music");

		strcpy(D_009A06AC, D_009A06B8);
		strcat(D_009A06AC, "midi");

		lolo.local_133 = RegCloseKey(lolo.hKey);
	}
}

//initpath:clean?
void C_004073F7() {
	C_0065FB40(D_009A0698, __FF7FILE__, 0xdf);
	C_0065FB40(D_009A069C, __FF7FILE__, 0xe0);
	C_0065FB40(D_009A06C0, __FF7FILE__, 0xe1);
	C_0065FB40(D_009A06B8, __FF7FILE__, 0xe2);
	C_0065FB40(D_009A06A8, __FF7FILE__, 0xe3);
	C_0065FB40(D_009A06A4, __FF7FILE__, 0xe4);
	C_0065FB40(D_009A06AC, __FF7FILE__, 0xe5);
	C_0065FB40(D_009A06C4, __FF7FILE__, 0xe6);
	C_0065FB40(D_009A06B4, __FF7FILE__, 0xe7);
}

//initpath:set music&sfx volume?
int C_004074DA(int bp08, int bp0c) {
	struct {
		HKEY hKey;//local_3
		int local_2;
		int local_1;
	}lolo;

	lolo.local_2 = 1;
	//.../Midi:"MusicVolume"
	lolo.local_1 = RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B6620, 0, KEY_WRITE/*0x20006*/, &lolo.hKey);
	if(lolo.local_1 == 0) {
		lolo.local_2 = 1;
		lolo.local_1 = RegSetValueEx(lolo.hKey, D_007B65B8, 0, REG_DWORD/*4*/, (LPBYTE)&bp08, 4);
		if(lolo.local_1 == 0)
			lolo.local_2 = 0;
		lolo.local_1 = RegCloseKey(lolo.hKey);
	}

	//.../Sound:SFXVolume
	lolo.local_1 = RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B65E8, 0, KEY_WRITE/*0x20006*/, &lolo.hKey);
	if(lolo.local_1 == 0) {
		lolo.local_2 = 1;
		lolo.local_1 = RegSetValueEx(lolo.hKey, D_007B65C8, 0, REG_DWORD/*4*/, (LPBYTE)&bp0c, 4);
		if(lolo.local_1 == 0)
			lolo.local_2 = 0;
		lolo.local_1 = RegCloseKey(lolo.hKey);
	}

	return lolo.local_2;
}

//initpath:get music&sfx volume?
int C_004075B0() {
	struct {
		HKEY hKey;//local_7
		int local_6;
		int local_5;
		int local_4;
		DWORD dwType;//local_3
		int local_2;
		DWORD cbData;//local_1
	}lolo;

	lolo.local_6 = 1;
	//.../Midi:"MusicVolume"
	lolo.local_4 = RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B6620, 0, KEY_QUERY_VALUE, &lolo.hKey);
	if(lolo.local_4 == 0) {
		lolo.cbData = 4;
		lolo.local_4 = RegQueryValueEx(lolo.hKey, D_007B65B8, 0, &lolo.dwType, (LPBYTE)&lolo.local_2, &lolo.cbData);
		if(lolo.local_4 == 0) {
			if(lolo.local_2 < 0)
				lolo.local_2 = 0;
			if(lolo.local_2 > 0x64)
				lolo.local_2 = 0x64;
#ifndef __JOE_FIX_BUGS__
			//-- potential error: close 2 times --
			lolo.local_4 = RegCloseKey(lolo.hKey);
#endif
		} else {
			lolo.local_6 = 0;
		}
		RegCloseKey(lolo.hKey);
	}

	//.../Sound:SFXVolume
	lolo.local_4 = RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B65E8, 0, KEY_QUERY_VALUE, &lolo.hKey);
	if(lolo.local_4 == 0) {
		lolo.cbData = 4;
		lolo.local_4 = RegQueryValueEx(lolo.hKey, D_007B65C8, 0, &lolo.dwType, (LPBYTE)&lolo.local_5, &lolo.cbData);
		if(lolo.local_4 == 0) {
			if(lolo.local_5 < 0)
				lolo.local_5 = 0;
			if(lolo.local_5 > 0x64)
				lolo.local_5 = 0x64;
#ifndef __JOE_FIX_BUGS__
			//-- potential error: close 2 times --
			lolo.local_4 = RegCloseKey(lolo.hKey);
#endif
		} else {
			lolo.local_6 = 0;
		}
		RegCloseKey(lolo.hKey);
	}
	if(lolo.local_6)
		C_006C4946(lolo.local_2, lolo.local_5);//set SFX&MIDI volumes[menu related]?

	return lolo.local_6;
}

//initpath:...
const char *C_004076EA() {
	return D_009A06B8;
}

const char *__004076F4() {
	return D_009A06B4;
}

//minigame path(1) "chocobo"?
const char *C_004076FE() {
	memset(D_009A06C4, 0, 0x100);
	strcpy(D_009A06C4, D_009A06B4);
	strcat(D_009A06C4, "minigame/");

	return D_009A06C4;
}

//minigame path(2) "condor"?
const char *C_0040776F() {
	memset(D_009A06C4, 0, 0x100);
	strcpy(D_009A06C4, D_009A06B4);
	strcat(D_009A06C4, "minigame/");

	return D_009A06C4;
}

//minigame path(3) "highway"?
const char *C_004077E0() {
	memset(D_009A06C4, 0, 0x100);
	strcpy(D_009A06C4, D_009A06B4);
	strcat(D_009A06C4, "minigame/");

	return D_009A06C4;
}

//minigame path(4) "coaster"?
const char *C_00407851() {
	memset(D_009A06C4, 0, 0x100);
	strcpy(D_009A06C4, D_009A06B4);
	strcat(D_009A06C4, "minigame/");

	return D_009A06C4;
}

//minigame path(5) "snowboard"?
const char *C_004078C2() {
	memset(D_009A06C4, 0, 0x100);
	strcpy(D_009A06C4, D_009A06B4);
	strcat(D_009A06C4, "minigame/");

	return D_009A06C4;
}

//minigame path(6) "submarine"?
const char *C_00407933() {
	memset(D_009A06C4, 0, 0x100);
	strcpy(D_009A06C4, D_009A06B4);
	strcat(D_009A06C4, "minigame/");

	return D_009A06C4;
}

const char *__004079A4() {
	return D_009A06AC;
}

const char *__004079AE() {
	return D_009A06A8;
}

const char *__004079B8(int bp08) {
	const char *bp_04;
	switch(bp08) {
		case 0x00:
			strcpy(D_009A0598, D_009A06B4);
			strcat(D_009A0598, "field/char.lgp");
		break;
		case 0x01:
			strcpy(D_009A0598, D_009A06B4);
			strcat(D_009A0598, "field/flevel.lgp");
		break;
		case 0x02:
			strcpy(D_009A0598, D_009A06B8);
			strcat(D_009A0598, "battle/battle.lgp");
		break;
		case 0x03:
			strcpy(D_009A0598, D_009A06B8);
			strcat(D_009A0598, "battle/magic.lgp");
		break;
		case 0x04:
			strcpy(D_009A0598, D_009A06B8);
			strcat(D_009A0598, "menu/menu_us.lgp");
		break;
		case 0x05:
			strcpy(D_009A0598, D_009A06B4);
			strcat(D_009A0598, "wm/world_us.lgp");
		break;
		case 0x06:
			strcpy(D_009A0598, C_0040776F());
			strcat(D_009A0598, "condor.lgp");
		break;
		case 0x07:
			strcpy(D_009A0598, C_004076FE());
			strcat(D_009A0598, "chocobo.lgp");
		break;
		case 0x08:
			strcpy(D_009A0598, C_004077E0());
			strcat(D_009A0598, "high-us.lgp");
		break;
		case 0x09:
			strcpy(D_009A0598, C_00407851());
			strcat(D_009A0598, "coaster.lgp");
		break;
		case 0x0a:
			strcpy(D_009A0598, C_004078C2());
			strcat(D_009A0598, "snowboard-us.lgp");
		break;
		case 0x0b:
			bp_04 = C_007443E7();//MIDI:get archive's name
			if(bp_04)
				strcpy(D_009A0598, bp_04);
		break;
		case 0x0e:
			strcpy(D_009A0598, D_009A06B8);
			strcat(D_009A0598, "cd/moviecam.lgp");
		break;
		case 0x0f:
			strcpy(D_009A0598, D_009A06B8);
			strcat(D_009A0598, "cd/cr_us.lgp");
		break;
		case 0x10:
			strcpy(D_009A0598, C_004076EA());
			strcat(D_009A0598, "cd/disc_us.lgp");
		break;
		case 0x11:
			strcpy(D_009A0598, C_00407933());
			strcat(D_009A0598, "sub.lgp");
		break;
	}

	return D_009A0598;
}
