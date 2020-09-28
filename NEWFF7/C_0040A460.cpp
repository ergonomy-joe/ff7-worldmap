/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
#include "ff7.h"
////////////////////////////////////////
const char D_007B6730[] = "Software\\Square Soft, Inc.\\Final Fantasy VII";
const char D_007B6760[] = "MIDI_DeviceID";
const char D_007B6770[] = "Sound_GUID";
const char D_007B6780[] = "Options";
const char D_007B6788[] = "DD_GUID";
const char D_007B6790[] = "MIDI_data";
const char D_007B67A0[] = "Options";
const char D_007B67A8[] = "Software\\Square Soft, Inc.\\Final Fantasy VII\\1.00\\Sound";
const char D_007B67E0[] = "Software\\Square Soft, Inc.\\Final Fantasy VII\\1.00\\Midi";
////////////////////////////////////////
HKEY D_009A06EC;
////////////////////////////////////////
int __0040A460() {
	return RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B6730, 0, KEY_READ/*0x20019*/, &D_009A06EC) == 0;
}

int __0040A486() {
	return RegCloseKey(D_009A06EC) == 0;
}

int C_0040A8DD(HKEY, unsigned *);//get "Options"[SOUND]

//get registry ...\SOUND:"Options"
int C_0040A49C(unsigned *bp08) {
	HKEY hKey;//local_2
	int local_1;

	local_1 = 0;
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B67A8, 0, KEY_READ/*0x20019*/, &hKey) == 0) {
		local_1 = C_0040A8DD(hKey, bp08);//get "Options"[SOUND]
		RegCloseKey(hKey);
	}

	return local_1;
}

int C_0040A823(HKEY, char *);

//get registry ...\SOUND:"Sound_GUID"
int C_0040A4EC(LPGUID bp08) {
	HKEY hKey;//local_2
	int local_1;

	local_1 = 1;
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B67A8, 0, KEY_READ/*0x20019*/, &hKey) == 0) {
		local_1 = C_0040A823(hKey, (char *)bp08);
		RegCloseKey(hKey);
	} else {
		local_1 = 0;
	}

	return local_1;
}

int C_0040A989(HKEY, int *);

//get registry ...\MIDI:"MIDI_DeviceID"
int C_0040A545(int *bp08) {
	HKEY hKey;//local_2
	int local_1;

	local_1 = 1;
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B67E0, 0, KEY_READ/*0x20019*/, &hKey) == 0) {
		local_1 = C_0040A989(hKey, bp08);
		RegCloseKey(hKey);
	} else {
		local_1 = 0;
	}

	return local_1;
}

int C_0040A933(HKEY, int *);//get "Options"[MIDI]

//get registry ...\MIDI:"Options"
int C_0040A59E(int *bp08) {
	HKEY hKey;//local_2
	int local_1;

	local_1 = 0;
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B67E0, 0, KEY_READ/*0x20019*/, &hKey) == 0) {
		local_1 = C_0040A933(hKey, bp08);//get "Options"[MIDI]
		RegCloseKey(hKey);
	}

	return local_1;
}

int C_0040A89E(HKEY, char *);

//set registry ...\SOUND:"Sound_GUID"
int __0040A5EE(char *bp08) {
	HKEY hKey;//local_2
	int local_1;

	local_1 = 1;
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B67A8, 0, KEY_READ/*0x20019*/, &hKey) == 0) {
		local_1 = C_0040A89E(hKey, bp08);
		RegCloseKey(hKey);
	} else {
		local_1 = 0;
	}

	return local_1;
}

//set "DD_GUID"
int __0040A647(char *bp08) {
	if(bp08)
		return RegSetValueEx(D_009A06EC, D_007B6788, 0, REG_SZ/*1*/, (LPBYTE)bp08, strlen(bp08) + 1) == 0;

	return RegDeleteValue(D_009A06EC, D_007B6788) == 0;
}

int C_0040A9BC(HKEY, char *);//set "MIDI_DeviceID"

//set registry ...\MIDI:"MIDI_DeviceID"
int __0040A699(char *bp08) {
	HKEY hKey;//local_2
	int local_1;

	local_1 = 1;
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B67E0, 0, KEY_READ/*0x20019*/, &hKey) == 0) {
		local_1 = C_0040A9BC(hKey, bp08);//set "MIDI_DeviceID"
		RegCloseKey(hKey);
	} else {
		local_1 = 0;
	}

	return local_1;
}

//get "DD_GUID"
int __0040A6F2(char *bp08) {
	struct {
		int local_67;
		char local_66[256];
		DWORD dwType;//local_2
		DWORD cbData;//local_1
	}lolo;

	lolo.cbData = 0x100;
	lolo.local_67 = RegQueryValueEx(D_009A06EC, D_007B6788, 0, &lolo.dwType, (LPBYTE)&lolo.local_66, &lolo.cbData);
	if(lolo.local_67 == 0) {
		strcpy(bp08, lolo.local_66);
		return 1;
	}
	bp08 = 0;

	return 0;
}

int C_0040A9E7(HKEY, char *);//get "MIDI_data"

//get registry ...\MIDI:"MIDI_data"
int C_0040A771(char *bp08) {
	HKEY hKey;//local_2
	int local_1;

	local_1 = 1;
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B67E0, 0, KEY_READ/*0x20019*/, &hKey) == 0) {
		local_1 = C_0040A9E7(hKey, bp08);//get "MIDI_data"
		RegCloseKey(hKey);
	} else {
		local_1 = 0;
	}

	return local_1;
}

int C_0040AA64(HKEY, char *);//set "MIDI_data"

//set registry ...\MIDI:"MIDI_data"
int __0040A7CA(char *bp08) {
	HKEY hKey;//local_2
	int local_1;

	local_1 = 1;
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B67E0, 0, KEY_READ/*0x20019*/, &hKey) == 0) {
		local_1 = C_0040AA64(hKey, bp08);//set "MIDI_data"
		RegCloseKey(hKey);
	} else {
		local_1 = 0;
	}

	return local_1;
}

//get "Sound_GUID"
int C_0040A823(HKEY hKey/*bp08*/, char *bp0c) {
	struct {
		unsigned i;//local_4
		int local_3;
		DWORD dwType;//local_2
		DWORD cbData;//local_1
	}lolo;

	lolo.local_3 = 1;
	lolo.cbData = 0x10;
	if(RegQueryValueEx(hKey, D_007B6770, 0, &lolo.dwType, (LPBYTE)bp0c, &lolo.cbData) == 0) {
		if(bp0c && lolo.cbData == 0) {
			for(lolo.i = 0; lolo.i < 0x10; lolo.i ++)
				bp0c[lolo.i] = (char)0xff;
			lolo.local_3 = 0;
		}
	} else {
		lolo.local_3 = 0;
	}

	return lolo.local_3;
}

//set "Sound_GUID"
int C_0040A89E(HKEY hKey/*bp08*/, char *bp0c) {
	if(bp0c)
		return RegSetValueEx(hKey, D_007B6770, 0, REG_BINARY/*3*/, (LPBYTE)bp0c, 0x10) == 0;

	return RegDeleteValue(hKey, D_007B6770) == 0;
}

//get "Options"[SOUND]
int C_0040A8DD(HKEY hKey/*bp08*/, unsigned *bp0c) {
	struct {
		DWORD dwType;//local_2
		DWORD cbData;//local_1
	}lolo;

	lolo.cbData = 4;

	return RegQueryValueEx(hKey, D_007B6780, 0, &lolo.dwType, (LPBYTE)bp0c, &lolo.cbData) == 0;
}

//set "Options"
int __0040A910(HKEY hKey/*bp08*/, char *bp0c) {
	return RegSetValueEx(hKey, D_007B6780, 0, REG_DWORD/*4*/, (LPBYTE)bp0c, 4) == 0;
}

//get "Options"[MIDI]
int C_0040A933(HKEY hKey/*bp08*/, int *bp0c) {
	struct {
		DWORD dwType;//local_2
		DWORD cbData;//local_1
	}lolo;

	lolo.cbData = 4;

	return RegQueryValueEx(hKey, D_007B67A0, 0, &lolo.dwType, (LPBYTE)bp0c, &lolo.cbData) == 0;
}

//set "Options"
int __0040A966(HKEY hKey/*bp08*/, char *bp0c) {
	return RegSetValueEx(hKey, D_007B67A0, 0, REG_DWORD/*4*/, (LPBYTE)bp0c, 4) == 0;
}

//get "MIDI_DeviceID"
int C_0040A989(HKEY hKey/*bp08*/, int *bp0c) {
	struct {
		DWORD dwType;//local_2
		DWORD cbData;//local_1
	}lolo;

	lolo.cbData = 4;

	return RegQueryValueEx(hKey, D_007B6760, 0, &lolo.dwType, (LPBYTE)bp0c, &lolo.cbData) == 0;
}

//set "MIDI_DeviceID"
int C_0040A9BC(HKEY hKey/*bp08*/, char *bp0c) {
	if(RegSetValueEx(hKey, D_007B6760, 0, REG_DWORD/*4*/, (LPBYTE)bp0c, 4) == 0)
		return 1;

	return 0;
}

//get "MIDI_data"
int C_0040A9E7(HKEY hKey/*bp08*/, char *bp0c) {
	struct {
		int local_67;
		char local_66[256];
		DWORD dwType;//local_2
		DWORD cbData;//local_1
	}lolo;

	lolo.cbData = 0x100;
	lolo.local_67 = RegQueryValueEx(hKey, D_007B6790, 0, &lolo.dwType, (LPBYTE)&lolo.local_66, &lolo.cbData);
	if(lolo.local_67 == 0) {
		strcpy(bp0c, lolo.local_66);
		return 1;
	}
	bp0c = 0;

	return 0;
}

//set "MIDI_data"
int C_0040AA64(HKEY hKey/*bp08*/, char *bp0c) {
	if(bp0c)
		return RegSetValueEx(hKey, D_007B6790, 0, REG_SZ/*1*/, (LPBYTE)bp0c, strlen(bp0c) + 1) == 0;

	return RegDeleteValue(hKey, D_007B6790) == 0;
}
