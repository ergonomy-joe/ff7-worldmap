/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
#include "ff7.h"

const char D_007B6448[] = FF7_REG_PATH "\\1.00\\Graphics";
const char D_007B6488[] = "Mode";

//Get "Graphics/Mode" Key
int C_00404D80() {
	struct {
		int dwValue;//local_6
		int dwGrMode;//local_5
		HKEY hKey;//local_4
		int dwResult;//local_3
		DWORD dwType;//local_2
		DWORD cbData;//local_1
	}lolo;

	lolo.dwGrMode = 2;
	lolo.dwResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B6448, 0, KEY_READ/*0x20019*/, &lolo.hKey);
	if(lolo.dwResult == 0) {
		lolo.cbData = 0x100;
		lolo.dwResult = RegQueryValueEx(lolo.hKey, D_007B6488, 0, &lolo.dwType, (LPBYTE)&lolo.dwValue, &lolo.cbData);
		if(lolo.dwResult == 0)
			lolo.dwGrMode = lolo.dwValue;
		RegCloseKey(lolo.hKey);
	}

	return lolo.dwGrMode;
}
