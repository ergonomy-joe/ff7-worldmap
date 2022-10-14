#include "NEWFF7/ff7.h"
#include "NEWFF7/loadmenu.h"
#include "NEWFF7/menu_data.h"
#include "NEWFF7/field_data.h"

#include "fontinfo.h"

#include <assert.h>
////////////////////////////////////////
int MAIN_frameCount = 0;

//#define MOUSE_TEST
//#define USE_DINPUT

#define KEYINPUT_ASYNC
#ifndef KEYINPUT_ASYNC
int MAIN_inputMask_prev = 0;
int MAIN_inputMask = 0;
int MAIN_triggerMask = 0;
int MAIN_inputMask2 = 0;//for some cheat mode in chocobo
#endif
////////////////////////////////////////
const char D_007B6658[] = "Software\\Square Soft, Inc.\\Final Fantasy VII\\1.00\\Graphics";
const char D_007B6698[] = "Software\\Square Soft, Inc.\\Final Fantasy VII\\1.00\\Sound";
const char D_007B66D0[] = "Software\\Square Soft, Inc.\\Final Fantasy VII\\1.00\\Midi";
const char D_007B6708[] = "DD_GUID";
const char D_007B6710[] = "MIDI_DeviceID";
const char D_007B6720[] = "Sound_GUID";
////////////////////////////////////////
#ifndef KEYINPUT_ASYNC
void patch_RefreshInput(int uMsg, int wParam, int lParam) {
	if(uMsg == WM_KEYDOWN && (HIWORD(lParam) & KF_REPEAT)) {
		return;
	}
	int mask = 0;
	int mask2 = 0;
	switch(wParam) {
		case VK_NUMPAD7: mask = PAD_00; break;
		case VK_NUMPAD1: mask = PAD_01; break;
		case VK_NUMPAD9: mask = PAD_02; break;
		case VK_NUMPAD3: mask = PAD_03; break;
		case VK_ADD: mask = PAD_04; break;
		case VK_RETURN: mask = PAD_05; break;
		case VK_NUMPAD0: mask = PAD_06; break;
		case VK_DECIMAL: mask = PAD_07; break;
		case VK_SUBTRACT: mask = PAD_08; break;
		case VK_NUMPAD5: mask = PAD_11; break;
		case VK_NUMPAD8: mask = PAD_UP; break;
		case VK_NUMPAD6: mask = PAD_RIGHT; break;
		case VK_NUMPAD2: mask = PAD_DOWN; break;
		case VK_NUMPAD4: mask = PAD_LEFT; break;
		//-- --
		case 'A': mask2 = PAD_00; break;
		case 'B': mask2 = PAD_01; break;
		case 'C': mask2 = PAD_02; break;
		case 'D': mask2 = PAD_03; break;
		case 'E': mask2 = PAD_04; break;
		case 'F': mask2 = PAD_05; break;
		case 'G': mask2 = PAD_06; break;
		case 'H': mask2 = PAD_07; break;
		case 'I': mask2 = PAD_08; break;
		case 'J': mask2 = PAD_09; break;
		case 'K': mask2 = PAD_10; break;
		case 'L': mask2 = PAD_11; break;
		case VK_UP: mask2 = PAD_UP; break;
		case VK_RIGHT: mask2 = PAD_RIGHT; break;
		case VK_DOWN: mask2 = PAD_DOWN; break;
		case VK_LEFT: mask2 = PAD_LEFT; break;

		//default:
	}
	if(mask) {
		switch(uMsg) {
			case WM_KEYDOWN: MAIN_inputMask |= mask; break;
			case WM_KEYUP: MAIN_inputMask &= ~mask; break;
			case WM_CHAR: break;
			default:
				assert(0);
		}
	}
	if(mask2) {
		switch(uMsg) {
			case WM_KEYDOWN: MAIN_inputMask2 |= mask2; break;
			case WM_KEYUP: MAIN_inputMask2 &= ~mask2; break;
			case WM_CHAR: break;
			default:
				assert(0);
		}
	}
}
#endif
////////////////////////////////////////
void patch_loadSaveFile(int fileIndex, int saveIndex) {
	static char path[256];
	sprintf(path, "%ssave/" "save%02d.ff7", D_009A0698, fileIndex);
	FILE *f = fopen(path, "rb");
	if(f) {
		fseek(f, 9 + saveIndex * sizeof(struct t_loadmenu_10f4), SEEK_SET);
		fread(&D_00DBFD38, sizeof(struct t_loadmenu_10f4), 1, f);
		fclose(f);
	}
	//-- compute checksum--
/*	int dwChecksum = 0;
	for(i = 0x380; i < 0x3ff; i ++) {
		dwChecksum += D_00DBFD38.f_0ba4[i];
	}
	//D_00DC0CDB =
	D_00DBFD38.f_0ba4[0x3ff] = -dwChecksum;*/
}
////////////////////////////////////////
//Declare this object to satisfy the linker
struct t_battle_progress_info {
	unsigned char __00[0x48];
};
struct t_battle_progress_info D_0099E2C0;
////////////////////////////////////////
int D_009A06CC = 0;//main.cpp
int D_009A06D0;//debug memory flag[ON/OFF]?

//int D_009ACB90 = 1;//from Battle:flag "sys"(tem memory)?

unsigned char D_00CC165C;//index in pseudo-random table
unsigned char  D_00CC1660;
////////////////////////////////////////
//====---- WORLD MAP ----====
extern void C_0074BE49(struct t_aa0 *);//WORLD MAP[UPDATE][callback]
extern void C_0074BA80(int, int, int, struct t_aa0 *);//WORLD MAP[ONMOUSE][callback]
extern void C_0074BA85(int, int, int, struct t_aa0 *);//WORLD MAP[ONKEY][callback]
extern void C_0074BAF5(struct t_aa0 *);//WORLD MAP[BEGIN][callback]
extern void C_0074BD50(void);//WORLD MAP:clean?
extern void C_0074BD77(struct t_aa0 *);//WORLD MAP[END][callback]
////////////////////////////////////////
//from "request CD" module
////////////////////////////////////////
//currently inserted CD #?
int C_00404A7D() {
	//TODO
	return 1;
}
////////////////////////////////////////
//from main.cpp
////////////////////////////////////////
//main:before field?
void C_00408074() {
	D_009A06CC = 1;
	D_00CC1644 = D_00DBFD38.f_0b90;
	D_00CBF9DC = D_00DBFD38.f_0b94;
	if(D_00CBF9DC == 0x00)
		D_00CBF9DC = 0x01;
	D_00CC15D0 = D_00DBFD38.f_0b96;
	D_00CC0D88.f_64 = D_00DBFD38.f_0b96;
	D_00CC0D88.f_04 = D_00DBFD38.f_0b9a;
	D_00CC0D88.f_06 = D_00DBFD38.f_0b9c;

	D_00CC0D88.f_22 = D_00DBFD38.f_0b9e;

	D_00CC0D88.f_24 = D_00DBFD38.f_0ba0;
	D_00CC165C = D_00DBFD38.f_0ba1;
	D_00CC1660 = D_00DBFD38.f_0ba2;
}

//main:open main archives?
int C_004082BF() {
	struct {
		int local_129;
		char local_128[256];
		char local_64[256];
	} lolo;


	//...
	//5 - wm/world_us.lgp
	strcpy(lolo.local_64, D_009A06B4);
	strcat(lolo.local_64, "wm/world_us.lgp");
	if(C_00675511(lolo.local_64, ARCHIVE_05) == 0) {//is_lib:open archive?
		sprintf(lolo.local_128, "Failed to load: %s\n", lolo.local_64);
		dx_dbg_puts(lolo.local_128);
		D_00CBF9DC = 0x13;
		return lolo.local_129;
	}
	//...
	lolo.local_129 = 1;

	return lolo.local_129;
}

//MainDispatcher[MAIN_INIT][callback]
int C_004089C5(struct t_aa0 *bp08) {
	struct {
		char bp_42c[256];
		char bp_32c[256];
		//
		HRESULT hResult;//local_132
		//...
		int local_130;
		//...
		char local_129[256];
		//...
		char local_64[256];
	}lolo;

	//...
	lolo.local_130 = 0;
	if(C_0067806E(bp08)) {//graphic driver:START?
		lolo.hResult = 0;
		//...
		PAD_init(bp08);//start input driver?
		//...
		PAD_setRepeatParams(200, 50);
		//-- init sound system --
		if(D_009A06A0) {
			if(C_00744400(D_009A06A8, D_009A06A4, bp08->hWnd) == 0) {//sound:init?
				D_00CBF9DC = 0x13;
				return 0;
			}
			C_00745CF3(0x2b, 0);//sound:load/prepare SFX?
		}
		//-- init midi system --
		if(D_009A06B0)
			C_00741780(D_009A06AC, bp08->hWnd);//MIDI:init
		//-- open some archives --
		//4 - menu/menu_us.lgp
		strcpy(lolo.local_64, D_009A06B8);
		strcat(lolo.local_64, "menu/menu_us.lgp");
		if(C_00675511(lolo.local_64, ARCHIVE_04) == 0) {//is_lib:open archive?
			sprintf(lolo.local_129, "Failed to load: %s\n", lolo.local_64);
			dx_dbg_puts(lolo.local_129);
			D_00CBF9DC = 0x13;
			return lolo.local_130;
		}
		//...
		//-- --
		if(C_004082BF() == 0)//main:open main archives?
			return 0;
		//-- --
		//...
		lolo.hResult = CoInitialize(0);
		if(FAILED(lolo.hResult))
			C_00414EE0("Failed to initialize COM (0x%8.8X)\n", lolo.hResult);//movie related debug printf?<empty>
		//...
		C_004075B0();//initpath:get music&sfx volume?
		//...
#if 1	//##### for FIELD/WORLD #####
		//-- --
		C_0067453A(0);//rsd:set "use PSX resources" flag
		//-- --
#endif
		//-- some patches --
		patch_loadSaveFile(0, 1);
	}
#if 1
	bp08->f_834 = 1;//log to console only
#endif

	return 1;
}

//MainDispatcher[MAIN_CLEAN][callback]
void C_00408EDC(struct t_aa0 *bp08) {
//	D_00CBF9DC = 0x13;
//	C_0040B1C0();//sm_movie:clean?
	//-- restore screensaver --
	int local_1;
	SystemParametersInfo(SPI_SCREENSAVERRUNNING, 0, &local_1, 0);
	//-- --
//	C_0040AB52();//kill time event -- counters?
//	C_0060E45D(bp08);//ad_app:Field quit
//	C_0040878B(D_009A06E0, bp08);//main:release t_main_90 obj
	C_004073F7();//initpath:clean?
	C_00676064();//is_lib:clean?
	//-- clean sound system --
	if(D_009A06A0) {
		C_00745DBB(0x2b, 0xf);//sound:free SFX?
		C_007446D7();//sound:sound_clean?
	}
	//-- clean midi system --
	if(D_009A06B0)
		C_00741F5F();//midi1:reset midi?
	//-- --
	PAD_clean();//Stop input driver?
	//-- clean something from menu system --
	if(D_00CC0D84 != 0x1a)
		C_006C12B1();//clean menu system?
	//-- --
//	C_0060E06F();//ad_app:clean
	C_0074BD50();//WORLD MAP:clean?
	C_00679864(bp08);//directx:graphic driver:STOP?
//	C_00417759();//release_movie_objects
	CoUninitialize();
//	C_00414EEC();//clean movie related debug module(called after "CoUninitialize")<empty>
	if(D_009A06D0) {
		C_006602EC();//mem:USAGE(2)?
		C_006602D9();//mem:USAGE(1)?
	}
}

//MainDispatcher[BEGIN][callback]
void C_00408FA6(struct t_aa0 *bp08) {
	//TODO
	//-- important! for field --
	C_00408074();//main:before field?
	//-- important! for field, world --
	D_00DB958C = FONTINFO;//from C_00401018:"init:load kernel files"
	C_006C0F60();//init system menu?
	//-- --
	C_0074BAF5(bp08);//WORLD MAP[BEGIN][callback]
}

//MainDispatcher[END][callback]
void C_004090C7(struct t_aa0 *bp08) {
	C_0074BD77(bp08);//WORLD MAP[END][callback]
}

//MainDispatcher[UPDATE][callback]
void C_004090E6(struct t_aa0 *bp08) {
	MAIN_frameCount ++;
	C_0074BE49(bp08);//WORLD MAP[UPDATE][callback]
}

//on WM_ACTIVATE[callback]
void C_00409CF2(int wParam/*bp08*/, struct t_aa0 *bp0c) {
	//TODO
}

//on WM_DEVICECHANGE[callback]
void C_00409D66(int wParam/*bp08*/, int lParam/*bp0c*/, struct t_aa0 *bp10) {
	//TODO
}

//on <CTRL+Q>?[callback]
int C_00409D7B(struct t_aa0 *bp08) {
	//TODO
	return 1;
}

//MainDispatcher[ONMOUSE][callback]
void C_00409DF1(int uMsg, int wParam, int lParam, struct t_aa0 *bp14) {
	C_0074BA80(uMsg, wParam, lParam, bp14);//WORLD MAP[ONMOUSE][callback]
}

//MainDispatcher[ONKEY][callback]
void C_00409E39(int uMsg, int wParam, int lParam, struct t_aa0 *bp14) {
	//TODO
#ifndef KEYINPUT_ASYNC
	patch_RefreshInput(uMsg, wParam, lParam);
#endif
	C_0074BA85(uMsg, wParam, lParam, bp14);//WORLD MAP[ONKEY][callback]
}

//main:some base init/config?
void C_0040A091(int unused1, int unused2) {
	struct {
		STARTUPINFO local_104;
		DWORD local_87;
		PROCESS_INFORMATION local_86;
		char local_82[256];
		HKEY hKey;//local_18
		DWORD local_17;
		MEMORYSTATUS local_16;
		DWORD dwType;//local_8
		int is_ok;//local_7
		struct t_aa0 *local_6;
		DWORD cbData;//local_5
		char local_4[16];
	} lolo;

	lolo.is_ok = 1;
	C_006602C1(D_009A06D0);//mem:set debug on/off?
	C_00406D10();//initpath:start?
	//-- we need 50000000 bytes --
	GlobalMemoryStatus(&lolo.local_16);
	if(lolo.local_16.dwAvailPageFile < 50000000L) {
		MessageBox(0, "There is insufficient swap space to play FF7.", "No Swap Space", MB_ICONHAND/*0x10*/);
		C_004073F7();//initpath:clean?
		D_00CBF9DC = 0x13;
	}
	//-- check Graphics."DD_GUID" --
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B6658, 0, KEY_QUERY_VALUE, &lolo.hKey) == 0) {//else 0040A148
		lolo.cbData = 0x10;
		if(RegQueryValueEx(lolo.hKey, D_007B6708, 0, &lolo.dwType, (LPBYTE)lolo.local_4, &lolo.cbData) == 0 && lolo.cbData == 0)
			lolo.is_ok = 0;
		RegCloseKey(lolo.hKey);
	} else {
		lolo.is_ok = 0;
	}
	//-- check Midi."MIDI_DeviceID" --
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B66D0, 0, KEY_QUERY_VALUE, &lolo.hKey) == 0) {
		lolo.cbData = 4;
		if(RegQueryValueEx(lolo.hKey, D_007B6710, 0, &lolo.dwType, (LPBYTE)&lolo.local_17, &lolo.cbData) == 0 && lolo.local_17 == -1)
			lolo.is_ok = 0;
		RegCloseKey(lolo.hKey);
	} else {
		lolo.is_ok = 0;
	}
	//-- check Sound."Sound_GUID" --
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, D_007B6698, 0, KEY_QUERY_VALUE, &lolo.hKey) == 0) {
		lolo.cbData = 0x10;
		if(RegQueryValueEx(lolo.hKey, D_007B6720, 0, &lolo.dwType, (LPBYTE)lolo.local_4, &lolo.cbData) == 0 && lolo.cbData == 0)
			lolo.is_ok = 0;
		RegCloseKey(lolo.hKey);
	} else {
		lolo.is_ok = 0;
	}
	//--        if error       --
	//-- lanch "ff7config.exe" --
	if(lolo.is_ok == 0) {//else 0040A34E
		lolo.local_104.cb = 0; memset(&(lolo.local_104.lpReserved), 0, sizeof(STARTUPINFO) - 4);//STARTUPINFO local_104 = {0};
		lolo.local_86.hProcess = 0; memset(&(lolo.local_86.hThread), 0, sizeof(PROCESS_INFORMATION) - 4);//PROCESS_INFORMATION local_86 = {0};

		lolo.local_104.cb = sizeof(STARTUPINFO);//0x44
		lolo.local_104.lpReserved = 0;
		lolo.local_104.lpReserved2 = 0;
		lolo.local_104.cbReserved2 = 0;
		lolo.local_104.lpDesktop = 0;
		lolo.local_104.dwFlags = 0;

		strcpy(lolo.local_82, D_009A0698);
		strcat(lolo.local_82, "ff7config.exe");

		CreateProcess(0, lolo.local_82, 0, 0, TRUE, NORMAL_PRIORITY_CLASS/*0x20*/, 0, 0, &lolo.local_104, &lolo.local_86);
		WaitForSingleObject(lolo.local_86.hProcess, -1);
		GetExitCodeProcess(lolo.local_86.hProcess, &lolo.local_87);
		if(lolo.local_87)
			D_00CBF9DC = 0x13;
	}
	//-- --
	if(C_00404A7D() == 0) {//currently inserted CD #?
		MessageBox(0, "Please insert FF7 Game Disc 1, 2, or 3 and try again.", "Insert Game Disc", MB_ICONHAND/*0x10*/);
		C_004073F7();//initpath:clean?
		D_00CBF9DC = 0x13;
	}
	//-- --
	lolo.local_6 = C_00676E7E();//directx:init some game object?
	if(lolo.local_6) {//else 0040A459
		lolo.local_6->f_99c = 90.0f;
		lolo.local_6->f_9a0 = 125.0f;
		lolo.local_6->f_9a4 = 50000.0f;
		C_004069FD(lolo.local_6);//prepare graphic driver?
		//-- set some major callbacks --
		lolo.local_6->f_9f0.f_00 = C_004089C5;//MainDispatcher[MAIN_INIT][callback]
		lolo.local_6->f_9f0.f_10 = C_004090E6;//MainDispatcher[UPDATE][callback]
		lolo.local_6->f_9f0.f_04 = C_00408EDC;//MainDispatcher[MAIN_CLEAN][callback]
		lolo.local_6->f_9f0.f_08 = C_00408FA6;//MainDispatcher[BEGIN][callback]
		lolo.local_6->f_9f0.f_0c = C_004090C7;//MainDispatcher[END][callback]
		lolo.local_6->f_a28 = C_00409CF2;//on WM_ACTIVATE[callback]
		lolo.local_6->f_a2c = C_00409D66;//on WM_DEVICECHANGE[callback]
		lolo.local_6->f_a58 = C_006C0E2D;//on "Exit box"?[callback]
		lolo.local_6->f_a5c = C_00409D7B;//on <CTRL+Q>?[callback]
		lolo.local_6->f_9f0.f_14 = C_00409DF1;//MainDispatcher[ONMOUSE][callback]
		lolo.local_6->f_9f0.f_18 = C_00409E39;//MainDispatcher[ONKEY][callback]
		C_0067656B(lolo.local_6);//directx:set some game object?
	}
}

////////////////////////////////////////
//from C_0040AAB0.cpp
////////////////////////////////////////
//get frame count
int C_0040AC84() {
	//used by world for 2D animation (map, rivers, snow, ...)

	return MAIN_frameCount;
}
////////////////////////////////////////
//from other module
////////////////////////////////////////
//movie related debug printf?<empty>
int C_00414EE0(const char *format, ...) {
	return 0;
}

//some inflate function?[not called yet]
void C_0041CF10(unsigned char *bp08, unsigned char *bp0c) {
	//...
}
////////////////////////////////////////
//from input.cpp
////////////////////////////////////////
unsigned char D_009ADAE4[0x100];

#ifdef MOUSE_TEST
struct {
	POINT previous_p;
	DIMOUSESTATE state;
	DIDEVICEOBJECTDATA mouse_data[0x40];
	unsigned char last_rgb[3];
	int index;
}fake_di;
#elif defined(USE_DINPUT)
#include <dinput.h>
LPDIRECTINPUT pDI = 0;
LPDIRECTINPUTDEVICE pDIDMouse = 0;
DIPROPDWORD diProp_mouse;
DIDEVCAPS diDevCaps_mouse;
DIMOUSESTATE diMouseState;
DIDEVICEOBJECTDATA diDeviceObjectData_mouse;
#endif

//init?
int C_0041EEA0(struct t_aa0 *bp08) {
	memset(D_009ADAE4, 0, 0x100);
	//TODO
#ifdef MOUSE_TEST
	GetCursorPos(&fake_di.previous_p);
	fake_di.index = 0;
#elif defined(USE_DINPUT)
	if(FAILED(DirectInputCreate(bp08->f_058, 0x300, &pDI, 0))) return 0;
	if(FAILED(pDI->CreateDevice(GUID_SysMouse, &pDIDMouse, 0))) return 0;
	if(FAILED(pDIDMouse->SetDataFormat(&c_dfDIMouse))) return 0;
	if(FAILED(pDIDMouse->SetCooperativeLevel(bp08->hWnd, DISCL_FOREGROUND|DISCL_EXCLUSIVE))) return 0;

	diProp_mouse.diph.dwSize = sizeof(DIPROPDWORD);
	diProp_mouse.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	diProp_mouse.diph.dwObj = 0;
	diProp_mouse.diph.dwHow = 0;
	diProp_mouse.dwData = 0x40;
	if(FAILED(pDIDMouse->SetProperty(DIPROP_BUFFERSIZE, (LPDIPROPHEADER)&diProp_mouse))) return 0;

	diDevCaps_mouse.dwSize = sizeof(DIDEVCAPS);
	if(FAILED(pDIDMouse->GetCapabilities(&diDevCaps_mouse))) return 0;
	//-- --
	if(FAILED(pDIDMouse->Acquire())) return 0;
#endif

	return 0;
}

//clean direct input driver?
void C_0041EF0E() {
	//TODO
#ifdef USE_DINPUT
	HRESULT hResult;
	hResult = pDIDMouse->Unacquire();
	RELEASE(pDIDMouse);
	RELEASE(pDI);
#endif
}

//get mouse state?
LPDIMOUSESTATE C_0041F139() {
#ifdef MOUSE_TEST
	POINT p;
	GetCursorPos(&p);

	fake_di.state.lX = p.x - fake_di.previous_p.x;
	fake_di.state.lY = p.y - fake_di.previous_p.y;
	fake_di.state.lZ = 0;
	fake_di.state.rgbButtons[0] = GetAsyncKeyState(VK_LBUTTON)?0x80:0;
	fake_di.state.rgbButtons[1] = GetAsyncKeyState(VK_RBUTTON)?0x80:0;
	fake_di.state.rgbButtons[2] = GetAsyncKeyState(VK_MBUTTON)?0x80:0;

	fake_di.previous_p = p;
	//-- --
	int i = fake_di.index;
	if(fake_di.state.lX) {
		fake_di.mouse_data[i].dwOfs = DIMOFS_X;
		fake_di.mouse_data[i].dwData = fake_di.state.lX;
		i++;
	}
	if(fake_di.state.lY) {
		fake_di.mouse_data[i].dwOfs = DIMOFS_Y;
		fake_di.mouse_data[i].dwData = fake_di.state.lY;
		i++;
	}
	for(int j = 0; j < 3; j ++) {
		if(fake_di.state.rgbButtons[j] != fake_di.last_rgb[j]) {
			fake_di.mouse_data[i].dwOfs = DIMOFS_BUTTON0 + j;
			fake_di.mouse_data[i].dwData = fake_di.state.rgbButtons[j];
			i++;

			fake_di.last_rgb[j] = fake_di.state.rgbButtons[j];
		}
	}
	fake_di.index = i;
	//-- --

	return &fake_di.state;
#elif defined(USE_DINPUT)
	HRESULT hResult;

	if(pDIDMouse) {
		hResult = pDIDMouse->GetDeviceState(sizeof(DIMOUSESTATE), &diMouseState);
		if(hResult == DI_OK)
			return &diMouseState;
		if(hResult == DIERR_INPUTLOST) {//0x8007001E
			//D_009ADC54 = 0;
			if(SUCCEEDED(pDIDMouse->Acquire())/*C_0041F0CE()*/) {
				if(SUCCEEDED(pDIDMouse->GetDeviceState(sizeof(DIMOUSESTATE), &diMouseState)))
					return &diMouseState;
			}
		}
	}

	return 0;
#else
	return 0;
#endif
}

//get mouse DeviceObjectData?
LPDIDEVICEOBJECTDATA C_0041F1C3() {
#ifdef MOUSE_TEST
	if(fake_di.index == 0)
		return 0;
	fake_di.index --;
	return &(fake_di.mouse_data[fake_di.index]);
#elif defined(USE_DINPUT)
	struct {
		HRESULT hResult;//local_2
		DWORD dwItems;//local_1
	}lolo;

	lolo.dwItems = 1;
	if(pDIDMouse) {
		lolo.hResult = pDIDMouse->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), &diDeviceObjectData_mouse, &lolo.dwItems, 0);
		if(lolo.hResult == DI_OK/*0*/ || lolo.hResult == DI_BUFFEROVERFLOW/*1*/) {
			//
			//
			//D_009ADC58 = 0;
			return lolo.dwItems?&diDeviceObjectData_mouse:0;
		}
		if(lolo.hResult == DIERR_INPUTLOST) {//0x8007001E
			//D_009ADC54 = 0;
			pDIDMouse->Acquire();//C_0041F0CE();//acquire mouse?
		}
	}

	return 0;
#else
	return 0;
#endif
}

//count mouse DeviceObjectData?
int C_0041F32A() {
#ifdef MOUSE_TEST
	return fake_di.index;
#elif defined(USE_DINPUT)
	struct {
		HRESULT hResult;//local_2
		DWORD dwItems;//local_1
	}lolo;

	lolo.dwItems = INFINITE;//-1
	if(pDIDMouse) {
		lolo.hResult = pDIDMouse->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), 0, &lolo.dwItems, DIGDD_PEEK);
		if(lolo.hResult == DI_OK/*0*/)
			return lolo.dwItems;
		if(lolo.hResult == DI_BUFFEROVERFLOW/*1*/) {
			//D_009ADC58 = 1;
			return lolo.dwItems;
		}
		if(lolo.hResult == DIERR_INPUTLOST) {//0x8007001E
			//D_009ADC54 = 0;
			pDIDMouse->Acquire();//C_0041F0CE();
		}
	}

	return 0;
#else
	return 0;
#endif
}

#ifdef KEYINPUT_ASYNC
const int MaxKbdObj = 32;
DIDEVICEOBJECTDATA g_KbdObj[MaxKbdObj];
int g_KbdIdx = 0;

void kb_helper(DWORD dik, int vk) {
	DWORD newval = GetAsyncKeyState(vk)?0x80:0;
	if(D_009ADAE4[dik] != newval) {
		DIDEVICEOBJECTDATA dat;
		dat.dwTimeStamp = 0;
		dat.dwSequence = 0;
		dat.dwOfs = dik;
		dat.dwData = newval;
		if(g_KbdIdx < MaxKbdObj) {
			g_KbdObj[g_KbdIdx] = dat;
			g_KbdIdx ++;
		}
	}
	D_009ADAE4[dik] = (unsigned char)newval;
}
#endif

//get keyboard map?
unsigned char *C_0041F55E() {
#ifdef KEYINPUT_ASYNC
	kb_helper(DIK_NUMPAD7, VK_NUMPAD7);
	kb_helper(DIK_NUMPAD1, VK_NUMPAD1);
	kb_helper(DIK_NUMPAD9, VK_NUMPAD9);
	kb_helper(DIK_NUMPAD3, VK_NUMPAD3);
	kb_helper(DIK_ADD, VK_ADD);
	kb_helper(DIK_NUMPADENTER, VK_RETURN);
	kb_helper(DIK_NUMPAD0, VK_NUMPAD0);
	kb_helper(DIK_DECIMAL, VK_DECIMAL);
	kb_helper(DIK_SUBTRACT, VK_SUBTRACT);
	kb_helper(DIK_NUMPAD5, VK_NUMPAD5);
	kb_helper(DIK_NUMPAD8, VK_NUMPAD8);
	kb_helper(DIK_NUMPAD6, VK_NUMPAD6);
	kb_helper(DIK_NUMPAD2, VK_NUMPAD2);
	kb_helper(DIK_NUMPAD4, VK_NUMPAD4);
	//-- --
	//kb_helper(0, VK_RSHIFT);
	if(0) {//for text input
		kb_helper(DIK_RSHIFT, VK_RSHIFT);
		kb_helper(DIK_LSHIFT, VK_LSHIFT);
		kb_helper(DIK_SPACE, VK_SPACE);
		kb_helper(DIK_BACK, VK_BACK);
		kb_helper(DIK_0, '0'); kb_helper(DIK_1, '1');
		kb_helper(DIK_2, '2'); kb_helper(DIK_3, '3');
		kb_helper(DIK_4, '4'); kb_helper(DIK_5, '5');
		kb_helper(DIK_6, '6'); kb_helper(DIK_7, '7');
		kb_helper(DIK_8, '8'); kb_helper(DIK_9, '9');
		kb_helper(DIK_A, 'A'); kb_helper(DIK_B, 'B');
		kb_helper(DIK_C, 'C'); kb_helper(DIK_D, 'D');
		kb_helper(DIK_E, 'E'); kb_helper(DIK_F, 'F');
		kb_helper(DIK_G, 'G'); kb_helper(DIK_H, 'H');
		kb_helper(DIK_I, 'I'); kb_helper(DIK_J, 'J');
		kb_helper(DIK_K, 'K'); kb_helper(DIK_L, 'L');
		kb_helper(DIK_M, 'M'); kb_helper(DIK_N, 'N');
		kb_helper(DIK_O, 'O'); kb_helper(DIK_P, 'P');
		kb_helper(DIK_Q, 'Q'); kb_helper(DIK_R, 'R');
		kb_helper(DIK_S, 'S'); kb_helper(DIK_T, 'T');
		kb_helper(DIK_U, 'U'); kb_helper(DIK_V, 'V');
		kb_helper(DIK_W, 'W'); kb_helper(DIK_X, 'X');
		kb_helper(DIK_Y, 'Y'); kb_helper(DIK_Z, 'Z');
		kb_helper(DIK_PERIOD, VK_OEM_PERIOD);
		kb_helper(DIK_SEMICOLON, VK_OEM_PLUS);
		kb_helper(DIK_COMMA, VK_OEM_COMMA);
		kb_helper(DIK_EQUALS, VK_OEM_MINUS);
		kb_helper(DIK_MINUS, VK_OEM_1);
	}
	//-- --
	kb_helper(DIK_UP, VK_UP);
	kb_helper(DIK_RIGHT, VK_RIGHT);
	kb_helper(DIK_DOWN, VK_DOWN);
	kb_helper(DIK_LEFT, VK_LEFT);
#endif
	return D_009ADAE4;
}

//get keyboard DeviceObjectData?
LPDIDEVICEOBJECTDATA C_0041F5F5() {
#ifdef KEYINPUT_ASYNC
	if(g_KbdIdx == 0)
		return 0;
	g_KbdIdx --;
	return &(g_KbdObj[g_KbdIdx]);
#else
	return 0;
#endif
}

//empty keyboard buffer?
int C_0041F678() {
#ifdef KEYINPUT_ASYNC
	int ret = g_KbdIdx;
	g_KbdIdx = 0;
	return ret;
#else
	return 0;
#endif
}

//count keyboard DeviceObjectData?
int C_0041F766() {
#ifdef KEYINPUT_ASYNC
	return g_KbdIdx;
#else
	return 0;
#endif
}

//get joypad related object?
struct t_input_98 *C_0041F7D8() {
	//TODO
	return 0;
}
////////////////////////////////////////
//unimplemented stuff
////////////////////////////////////////
struct t_combat_static_560 { char __000[0x560]; } D_0099DDA8;

unsigned short D_009AAD6C;
struct t_battle_menu_06_B { char __00[6]; } D_009AC354[0x140];

unsigned char D_00C068B4 = 0;
struct t_menu_shop_local___ *D_00C06910 = 0;
unsigned char D_00C06914 = 0;
unsigned short D_00C069B0[3];

unsigned char *C_0041963C(unsigned int bp08, int bp0c, int bp10) { return 0; }

void C_005C7336(struct t_loadmenu_charaInfo *bp08) {}
int C_005C81A3(int bp08) { return 0;}
void C_005C84ED() {}
int C_005C8684(int bp08,int bp0c) { return 0;}

void C_005CB127() { /*OutputDebugString(__FUNCTION__);*/ }
void C_005CB2CC(char bp08) { /*OutputDebugString(__FUNCTION__);*/ }

void C_005CD078(unsigned int bp08) {}
////////////////////////////////////////
struct t_script_20 *D_00CBF5E8;
struct t_main_infos *D_00CBF9D8;
short D_00CBF9DC;
char D_00CBFB6C;
short D_00CC0828;
unsigned char D_00CC0888;
void *D_00CC08F0;
unsigned char D_00CC0960[4];
unsigned char D_00CC0964;
short D_00CC0974;
char D_00CC0B64;
int D_00CC0D80;
short D_00CC0D84;
struct t_main_infos D_00CC0D88;
unsigned char D_00CC14D0[1];
short D_00CC15D0;
short D_00CC15D8;
short D_00CC15DC;
int D_00CC1644;
int D_00CC1648;
struct t_script_DialogInfo_30 D_00CFF5B8[8/*or 4?*/];//check

void C_0061C577() {}
////////////////////////////////////////
