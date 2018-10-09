/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
#include "ff7.h"

const char D_007B6448[] = "Software\\Square Soft, Inc.\\Final Fantasy VII\\1.00\\Graphics";
const char D_007B6488[] = "Mode";

//Get "Graphics/Mode" Key
int C_00404D80() {
	struct {
		int local_6;
		int local_5;
		HKEY hKey;//local_4
		int local_3;
		DWORD dwType;//local_2
		DWORD cbData;//local_1
	}lolo;

	lolo.local_5 = 2;
	lolo.local_3 = RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B6448, 0, KEY_READ/*0x20019*/, &lolo.hKey);
	if(lolo.local_3 == 0) {
		lolo.cbData = 0x100;
		lolo.local_3 = RegQueryValueEx(lolo.hKey, D_007B6488, 0, &lolo.dwType, (LPBYTE)&lolo.local_6, &lolo.cbData);
		if(lolo.local_3 == 0)
			lolo.local_5 = lolo.local_6;
		RegCloseKey(lolo.hKey);
	}

	return lolo.local_5;
}
