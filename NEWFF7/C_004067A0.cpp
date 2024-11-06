/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/

#include "ff7.h"
////////////////////////////////////////
const char D_007B64A0[] = FF7_REG_PATH;
const char D_007B64D0[] = FF7_REG_PATH "\\1.00\\Graphics";
const char D_007B6510[] = "DD_GUID";
const char D_007B6518[] = "Driver";
const char D_007B6520[] = "DriverPath";
const char D_007B6530[] = "Mode";
const char D_007B6538[] = "Options";
const char D_007B6540[] = "SSI_DEBUG";
////////////////////////////////////////
struct t_config_local {//size 0x124, or more?
	/*000*/unsigned char f_00[0x10];//"DD_GUID"
	/*010*/int dwHasDD_GUID;
	/*014*/int dwDriver;//[0 "sw"; 1 "hw"; 2 "OpenGL"; >= 3 "dll driver"]
	/*018*/char f_18[MAX_PATH];//"DriverPath"
	/*11c*/int dwMode;
	/*120*/int dwOptions;
};
////////////////////////////////////////
int D_009A054C;//not in this module:should be extern?
////////////////////////////////////////
//get SSI_DEBUG option
int C_004067A0() {
	struct {
		char local_68[256];
		DWORD dwType;//local_4
		int dwResult;//local_3
		DWORD cbData;//local_2
		HKEY hKey;//local_1
	}lolo;

	lolo.dwResult = 0;
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B64A0, 0, KEY_QUERY_VALUE, &lolo.hKey) == 0) {
		lolo.cbData = 0x10;
		if(RegQueryValueEx(lolo.hKey, D_007B6540, 0, &lolo.dwType, (LPBYTE)lolo.local_68, &lolo.cbData) == 0) {
			if(lolo.cbData == 0x10 && stricmp("SHOWMETHEAPPLOG", lolo.local_68) == 0)
				lolo.dwResult = 1;
		}
		RegCloseKey(lolo.hKey);
	}
	return lolo.dwResult;
}

//graphic driver registry
int C_0040682D(struct t_config_local *bp08) {
	struct {
		unsigned char local_73[0x10];
		char local_69[MAX_PATH];
		int dwSuccess;//local_4
		DWORD dwType;//local_3
		HKEY hKey;//local_2
		DWORD cbData;//local_1
	}lolo;

	lolo.dwSuccess = 1;
#if (_MSC_VER < 1500)
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B64D0, 0, KEY_ALL_ACCESS/*0xf003f*/, &lolo.hKey) == 0) {
#else
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B64D0, 0, KEY_QUERY_VALUE, &lolo.hKey) == 0) {
#endif
		//-- "DD_GUID" --
		lolo.cbData = 0x10;
		if(RegQueryValueEx(lolo.hKey, D_007B6510, 0, &lolo.dwType, (LPBYTE)&(bp08->f_00), &lolo.cbData) == 0) {
			memset(lolo.local_73, 0, 0x10);//i.e lolo.local_73 = ""?
			if(memcmp(bp08->f_00, lolo.local_73, 0x10))
				bp08->dwHasDD_GUID = 1;
			else
				bp08->dwHasDD_GUID = 0;
		} else {
			lolo.dwSuccess = 0;
		}
		//-- "Driver" --
		lolo.cbData = 4;
		if(RegQueryValueEx(lolo.hKey, D_007B6518, 0, &lolo.dwType, (LPBYTE)&(bp08->dwDriver), &lolo.cbData) != 0)
			lolo.dwSuccess = 0;
#if 1
		//we can force the driver here
//		bp08->dwDriver = 0;//sw
		bp08->dwDriver = 1;//d3d
//		bp08->dwDriver = 2;//opengl
#endif
		//-- "DriverPath" --
		if(bp08->dwDriver >= 3) {
			lolo.cbData = MAX_PATH;
			if(RegQueryValueEx(lolo.hKey, D_007B6520, 0, &lolo.dwType, (LPBYTE)lolo.local_69, &lolo.cbData) != 0) {
				lolo.dwSuccess = 0;
				bp08->f_18[0] = 0;
			} else {
				strcpy(bp08->f_18, lolo.local_69);
			}
		}
		//-- "Mode" --
		lolo.cbData = 4;
		if(RegQueryValueEx(lolo.hKey, D_007B6530, 0, &lolo.dwType, (LPBYTE)&bp08->dwMode, &lolo.cbData) != 0)
			lolo.dwSuccess = 0;
		//note: mode is also polled with C_00404D80()
		//-- "Options" --
		lolo.cbData = 4;
		if(RegQueryValueEx(lolo.hKey, D_007B6538, 0, &lolo.dwType, (LPBYTE)&bp08->dwOptions, &lolo.cbData) != 0)
			lolo.dwSuccess = 0;
		//-- --
		RegCloseKey(lolo.hKey);
	} else {
		lolo.dwSuccess = 0;
	}

	return lolo.dwSuccess;
}

//prepare graphic driver?
int C_004069FD(struct t_aa0 *bp08) {
	struct {
		struct t_extdll_24 bp_2d8;
		int dwShowLog;//bp_2b4
		int dwSuccess;//bp_2b0
		struct t_config_local bp_2ac;
		char _dummy_[0x188];//should be in t_config_local?
	}lolo;

	lolo.dwSuccess = C_0040682D(&lolo.bp_2ac);//graphic driver registry
	if(lolo.dwSuccess) {
		switch(lolo.bp_2ac.dwMode) {
			case 0:
				bp08->dwDisplayWidth = 320;
				bp08->dwDisplayHeight = 240;
				D_009A054C = 0;
			break;
			case 1:
				bp08->dwDisplayWidth = 640;
				bp08->dwDisplayHeight = 480;
				D_009A054C = 1;
			break;
			case 2:
				bp08->dwDisplayWidth = 640;
				bp08->dwDisplayHeight = 480;
				D_009A054C = 2;
			break;
		}//end switch
		switch(lolo.bp_2ac.dwHasDD_GUID) {
			case 0: bp08->f_968 = 1; break;
			case 1: bp08->f_968 = 0; break;
		}//end switch
		bp08->f_988 = 0;//HEL off
		if(lolo.bp_2ac.dwOptions & 1)
			bp08->f_96c = 1;
		else
			bp08->f_96c = 0;
		bp08->f_a94 = 0;
		if(lolo.bp_2ac.dwOptions & 2) {//else 00406B9D
			bp08->f_a90 = 1;//nvidia
			if(lolo.bp_2ac.dwOptions & 8)
				bp08->f_a98 = 0;//texture bleeding patch(field)
			if(lolo.bp_2ac.dwOptions & 0x10) {
				bp08->f_a98 = 0;
				bp08->f_a94 = 1;//"tnt_fix"
			}
		} else {
			bp08->f_a90 = 0;
		}
#if 1	//[debug]force window mode
		bp08->dwIsFullScreen = 0;
#else
		bp08->dwIsFullScreen = 1;
#endif
		bp08->f_948 = 0;
		bp08->f_94c = 1;
		bp08->dwUseD3D2 = 1;
		switch(lolo.bp_2ac.dwDriver) {
			case 0: bp08->f_a60 = 1; break;//Software renderer
			case 1: bp08->f_a60 = 0; break;//Hardware renderer
			case 2: bp08->f_a60 = 3; break;//OpenGL
			case 3://extern DLL ("custom driver")
				bp08->f_a60 = 2;
				bp08->f_a64 = mem_strdup(lolo.bp_2ac.f_18);
				C_00666AB0(2, &lolo.bp_2d8);
				lolo.bp_2d8.f_04 = bp08->f_a64;
				if(C_00666AD5(&lolo.bp_2d8, bp08)) {//load graphic dll?
					//ok
				} else {
					//failed:fallback to sw renderer
					bp08->f_a60 = 1;
				}
			break;
			default:
				bp08->f_a60 = 1;
		}//end switch
		//-- log --
		lolo.dwShowLog = C_004067A0();//get SSI_DEBUG option
		bp08->f_838 = lolo.dwShowLog;
		bp08->f_834 = lolo.dwShowLog;
		//-- --
		bp08->f_a30 = 1;
	}

	return lolo.dwSuccess;
}
