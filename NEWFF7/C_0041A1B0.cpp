/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//high-level input module?

#include "ff7.h"
////////////////////////////////////////
int D_009A85C0,D_009A85C4;//pointer x,y
int D_009A85C8;//repeat delay(1)
unsigned char *D_009A85CC;
struct t_aa0 *D_009A85D0;
int D_009A85D4;//current mask
int D_009A85D8;//mouse mask(unused)
LPDIMOUSESTATE D_009A85DC;
int D_009A85E0;//trigger mask
int D_009A85E4;//repeat delay(2)
unsigned D_009A85E8[3][25];
unsigned D_009A8714;//current repeat delay
int D_009A8718;//time now
struct t_input_98 *D_009A871C;
int D_009A8720;//previous "time now"
int D_009A8724;//mouse mask[w repeat](unused)
int D_009A8728;//previous mask?
int D_009A872C;//current repeat state
unsigned D_009A8730;//time since last refresh
int D_009A8734;//"is repeating" flag
//009A8738
int D_009A873C,D_009A8740;//mouse x,y[for joypad simulation]?
////////////////////////////////////////
void C_0041A828(void);//key maps

/*0041A1B0*/void PAD_init(struct t_aa0 *bp08) {
	D_009A85E0 ^= D_009A85E0;
	D_009A85D4 ^= D_009A85D4;
	D_009A85D0 = bp08;
	C_0041EEA0(D_009A85D0);
	C_0041A828();//key maps
	D_009A8720 = 
	D_009A8718 = timeGetTime();
	D_009A8730 = 0;
}

/*0041A214*/void PAD_clean() {
	C_0041EF0E();//clean direct input driver?
}

void C_0041B108(void);

/*0041A21E*/void PAD_refresh(struct t_aa0 *bp08) {
	int j;//bp_08
	int i;//bp_04

	D_009A85DC = C_0041F139();//get mouse state?
	D_009A85CC = C_0041F55E();//get keyboard map?
	D_009A871C = C_0041F7D8();//get joypad related object?
	//-- game object --
	if(bp08) {
		D_009A85D0 = bp08;
	} else if(D_009A85D0 == 0) {
		return;
	}
	//-- mouse pointer --
	if(D_009A85DC) {
		D_009A85D0->dwPointerX += D_009A85DC->lX;
		if(D_009A85D0->dwPointerX < 0)
			D_009A85D0->dwPointerX = 0;
		if(D_009A85D0->dwPointerX >= D_009A85D0->dwDisplayWidth)
			D_009A85D0->dwPointerX = D_009A85D0->dwDisplayWidth - 1;

		D_009A85D0->dwPointerY += D_009A85DC->lY;
		if(D_009A85D0->dwPointerY < 0)
			D_009A85D0->dwPointerY = 0;
		if(D_009A85D0->dwPointerY >= D_009A85D0->dwDisplayHeight)
			D_009A85D0->dwPointerY = D_009A85D0->dwDisplayHeight - 1;
		D_009A85C0 = D_009A85D0->dwPointerX;
		D_009A85C4 = D_009A85D0->dwPointerY;
	}
	//-- --
	D_009A8728 = D_009A85D4;
	D_009A85D4 ^= D_009A85D4;
	for(i = 0; i < 3; i ++) {
		for(j = 0; j < 25; j ++) {
			if(D_009A85E8[i][j] < LOCAL_DIK_DE) {
				//keyboard
				if(D_009A85CC) {
#if 0 //"right shift" scancode is 0?
					if(D_009A85E8[i][j])
#endif
					if(D_009A85CC[D_009A85E8[i][j]] & 0x80)
						D_009A85D4 |= BIT(j);
				}
			} else {
				//mouse buttons
				if(D_009A85DC) {
					switch(D_009A85E8[i][j]) {
						case LOCAL_DIK_MOUSE_B1: if(D_009A85DC->rgbButtons[0] & 0x80) D_009A85D4 |= BIT(j); break;
						case LOCAL_DIK_MOUSE_B2: if(D_009A85DC->rgbButtons[1] & 0x80) D_009A85D4 |= BIT(j); break;
						case LOCAL_DIK_MOUSE_B3: if(D_009A85DC->rgbButtons[2] & 0x80) D_009A85D4 |= BIT(j); break;
					}//end switch
				}
				//joypad
				if(D_009A871C) {
					switch(D_009A85E8[i][j]) {
						case LOCAL_DIK_JOY_UP: if(D_009A871C->f_08) D_009A85D4 |= BIT(j); break;
						case LOCAL_DIK_JOY_DOWN: if(D_009A871C->f_0c) D_009A85D4 |= BIT(j); break;
						case LOCAL_DIK_JOY_LEFT: if(D_009A871C->f_10) D_009A85D4 |= BIT(j); break;
						case LOCAL_DIK_JOY_RIGHT: if(D_009A871C->f_14) D_009A85D4 |= BIT(j); break;
						case LOCAL_DIK_JOY_B1: if(D_009A871C->f_18[0]) D_009A85D4 |= BIT(j); break;
						case LOCAL_DIK_JOY_B2: if(D_009A871C->f_18[1]) D_009A85D4 |= BIT(j); break;
						case LOCAL_DIK_JOY_B3: if(D_009A871C->f_18[2]) D_009A85D4 |= BIT(j); break;
						case LOCAL_DIK_JOY_B4: if(D_009A871C->f_18[3]) D_009A85D4 |= BIT(j); break;
						case LOCAL_DIK_JOY_B5: if(D_009A871C->f_18[4]) D_009A85D4 |= BIT(j); break;
						case LOCAL_DIK_JOY_B6: if(D_009A871C->f_18[5]) D_009A85D4 |= BIT(j); break;
						case LOCAL_DIK_JOY_B7: if(D_009A871C->f_18[6]) D_009A85D4 |= BIT(j); break;
						case LOCAL_DIK_JOY_B8: if(D_009A871C->f_18[7]) D_009A85D4 |= BIT(j); break;
						case LOCAL_DIK_JOY_B9: if(D_009A871C->f_18[8]) D_009A85D4 |= BIT(j); break;
						case LOCAL_DIK_JOY_BA: if(D_009A871C->f_18[9]) D_009A85D4 |= BIT(j); break;
					}//end switch
				}
			}
		}//end for
	}//end for
	//-- make "trigger" mask --
	D_009A85E0 = ((D_009A85D4 & D_009A8728) ^ 0xffffffff) & D_009A85D4;
	//-- refresh "repeat" --
	if(D_009A85E4) {
		D_009A8718 = timeGetTime();
		D_009A8730 += D_009A8718 - D_009A8720;
		D_009A8720 = D_009A8718;
		C_0041B108();
	}
	//-- --
#if 0	//test joe: gives some mouse control in the menu
	extern int __0041AD4B(void);//make mouse mask[joypad simulation]?
	__0041AD4B();//make mouse mask[joypad simulation]?
#endif
}

//note:ff8 names it "set_command"
/*0041A7EF*/void PAD_setCommand(int dwMap, unsigned dwMask, int dwKeyCode) {
	int i;
	
	i = 1;
	while(dwMask >> i)
		i ++;
	D_009A85E8[dwMap][i - 1] = dwKeyCode;
}

void C_0041AA5F(void);//key map #3[joy]

//key maps
void C_0041A828() {
	memset(D_009A85E8, 0, sizeof(D_009A85E8));

	C_0041A96D();//key map #2[numpad]
	C_0041AA5F();//key map #3[joy]

	PAD_setCommand(0, PAD_16, DIK_ESCAPE);//0x01
	PAD_setCommand(1, PAD_16, LOCAL_DIK_JOY_B2);//0xec
	//-- --
	PAD_setCommand(0, PAD_21, DIK_RETURN);//0x1c
	PAD_setCommand(0, PAD_17, DIK_UP);//0xc8
	PAD_setCommand(0, PAD_18, DIK_DOWN);//0xd0
	PAD_setCommand(0, PAD_19, DIK_LEFT);//0xcb
	PAD_setCommand(0, PAD_20, DIK_RIGHT);//0xcd
	//-- --
	PAD_setCommand(1, PAD_17, LOCAL_DIK_JOY_UP);//0xe3
	PAD_setCommand(1, PAD_18, LOCAL_DIK_JOY_DOWN);//0xe4
	PAD_setCommand(1, PAD_19, LOCAL_DIK_JOY_LEFT);//0xe5
	PAD_setCommand(1, PAD_20, LOCAL_DIK_JOY_RIGHT);//0xe6
	//-- --
	PAD_setCommand(0, PAD_22, LOCAL_DIK_MOUSE_B1);//0xdf
	PAD_setCommand(1, PAD_22, LOCAL_DIK_MOUSE_B2);//0xe0
	//-- --
	PAD_setCommand(0, PAD_23, LOCAL_DIK_JOY_B1);//0xeb
	PAD_setCommand(0, PAD_24, LOCAL_DIK_JOY_B3);//0xed
}

//note PAD_09 is not assigned

//key map #2[numpad]
void C_0041A96D() {
	PAD_setCommand(0, PAD_05, DIK_NUMPADENTER);//0x9c
	PAD_setCommand(0, PAD_06, DIK_NUMPAD0);//0x52
	PAD_setCommand(0, PAD_04, DIK_ADD);//0x4e
	PAD_setCommand(0, PAD_08, DIK_SUBTRACT);//0x4a
	PAD_setCommand(0, PAD_07, DIK_DECIMAL);//0x53
	PAD_setCommand(0, PAD_UP, DIK_NUMPAD8);//0x48
	PAD_setCommand(0, PAD_RIGHT, DIK_NUMPAD6);//0x4d
	PAD_setCommand(0, PAD_DOWN, DIK_NUMPAD2);//0x50
	PAD_setCommand(0, PAD_LEFT, DIK_NUMPAD4);//0x4b
	PAD_setCommand(0, PAD_00, DIK_NUMPAD7);//0x47
	PAD_setCommand(0, PAD_02, DIK_NUMPAD9);//0x49
	PAD_setCommand(0, PAD_01, DIK_NUMPAD1);//0x4f
	PAD_setCommand(0, PAD_03, DIK_NUMPAD3);//0x51
	PAD_setCommand(0, PAD_08, DIK_SUBTRACT);//0x4a//why twice?
	PAD_setCommand(0, PAD_11, DIK_NUMPAD5);//0x4c
}

//key map #3[joy]
void C_0041AA5F() {
	PAD_setCommand(1, PAD_00, LOCAL_DIK_JOY_B7);//0xF1
	PAD_setCommand(1, PAD_01, LOCAL_DIK_JOY_B8);//0xF2
	PAD_setCommand(1, PAD_02, LOCAL_DIK_JOY_B5);//0xEF
	PAD_setCommand(1, PAD_03, LOCAL_DIK_JOY_B6);//0xF0
	PAD_setCommand(1, PAD_04, LOCAL_DIK_JOY_B4);//0xEE
	PAD_setCommand(1, PAD_05, LOCAL_DIK_JOY_B3);//0xED
	PAD_setCommand(1, PAD_06, LOCAL_DIK_JOY_B2);//0xEC
	PAD_setCommand(1, PAD_07, LOCAL_DIK_JOY_B1);//0xEB
	PAD_setCommand(1, PAD_08, LOCAL_DIK_JOY_B9);//0xF3
	PAD_setCommand(1, PAD_11, LOCAL_DIK_JOY_BA);//0xF4
	PAD_setCommand(1, PAD_UP, LOCAL_DIK_JOY_UP);//0xE3
	PAD_setCommand(1, PAD_RIGHT, LOCAL_DIK_JOY_RIGHT);//0xE6
	PAD_setCommand(1, PAD_DOWN, LOCAL_DIK_JOY_DOWN);//0xE4
	PAD_setCommand(1, PAD_LEFT, LOCAL_DIK_JOY_LEFT);//0xE5
}

//test input mask[pressed]?
/*0041AB67*/unsigned PAD_test(unsigned bp08) {
	return D_009A85D4 & bp08;
}

//test input mask[trigger]?
/*0041AB74*/unsigned PAD_testTrigger(unsigned  bp08) {
	return D_009A85E0 & bp08;
}

int __0041AB81() {
	struct {
		struct t_input_98 *bp_0c;
		LPDIDEVICEOBJECTDATA bp_08;
		int i;//bp_04
	}lolo;

	//-- --
#if (_MSC_VER < 1500)
	//!!!bug!!!
	//C_0041F766() should be called only once, before the loop!!!
	for(lolo.i = 0; lolo.i < C_0041F766(); lolo.i ++) {
#else
	while(C_0041F766() > 0) {
#endif
		lolo.bp_08 = C_0041F5F5();//get keyboard DeviceObjectData?
		if(lolo.bp_08 && lolo.bp_08->dwData & 0x80)
			return lolo.bp_08->dwOfs;
	}//end for
	//-- --
	if(D_009A85D8 & BIT(4)) return LOCAL_DIK_MOUSE_B1;
	if(D_009A85D8 & BIT(5)) return LOCAL_DIK_MOUSE_B2;
	if(D_009A85D8 & BIT(6)) return LOCAL_DIK_MOUSE_B3;
	//-- --
	if(PAD_testTrigger(PAD_17)) return LOCAL_DIK_JOY_UP;
	if(PAD_testTrigger(PAD_18)) return LOCAL_DIK_JOY_DOWN;
	if(PAD_testTrigger(PAD_19)) return LOCAL_DIK_JOY_LEFT;
	if(PAD_testTrigger(PAD_20)) return LOCAL_DIK_JOY_RIGHT;
	if(PAD_testTrigger(PAD_23)) return LOCAL_DIK_JOY_B1;
	if(PAD_testTrigger(PAD_24)) return LOCAL_DIK_JOY_B3;
	//-- --
	lolo.bp_0c = C_0041F7D8();//get joypad related object?
	if(lolo.bp_0c) {
		if(lolo.bp_0c->f_18[1]) return LOCAL_DIK_JOY_B2;
		if(lolo.bp_0c->f_18[3]) return LOCAL_DIK_JOY_B4;
		if(lolo.bp_0c->f_18[4]) return LOCAL_DIK_JOY_B5;
		if(lolo.bp_0c->f_18[5]) return LOCAL_DIK_JOY_B6;
		if(lolo.bp_0c->f_18[6]) return LOCAL_DIK_JOY_B7;
		if(lolo.bp_0c->f_18[7]) return LOCAL_DIK_JOY_B8;
		if(lolo.bp_0c->f_18[8]) return LOCAL_DIK_JOY_B9;
		if(lolo.bp_0c->f_18[9]) return LOCAL_DIK_JOY_BA;
	}

	return 0;
}

//make mouse mask[joypad simulation]?
int __0041AD4B() {
	struct {
		LPDIDEVICEOBJECTDATA bp_14;
		int dwMouseMin;//bp_10
		unsigned bp_0c;
		int i;//bp_08
		int dwMouseMax;//bp_04
	}lolo;

	lolo.dwMouseMin = 15;
	lolo.dwMouseMax = 200;
	D_009A85D8 ^= D_009A85D8;
	D_009A8724 ^= D_009A8724;
	if(D_009A85E4 == 0) {
		D_009A873C = 0;
		D_009A8740 = 0;
	}
#if (_MSC_VER < 1500)
	//!!!bug!!!
	//C_0041F32A() should be called only once, before the loop!!!
	for(lolo.i = 0; lolo.i < C_0041F32A(); lolo.i ++) {
#else
	while(C_0041F32A() > 0) {
#endif
		lolo.bp_14 = C_0041F1C3();//get mouse DeviceObjectData?
		if(lolo.bp_14) {
			switch(lolo.bp_14->dwOfs) {
				case DIMOFS_X/*0x00*/: D_009A873C += lolo.bp_14->dwData; break;
				case DIMOFS_Y/*0x04*/: D_009A8740 += lolo.bp_14->dwData; break;
				case DIMOFS_BUTTON0/*0x0c*/: if(lolo.bp_14->dwData & 0x80) D_009A85D8 |= BIT(4); break;
				case DIMOFS_BUTTON1/*0x0d*/: if(lolo.bp_14->dwData & 0x80) D_009A85D8 |= BIT(5); break;
				case DIMOFS_BUTTON2/*0x0e*/: if(lolo.bp_14->dwData & 0x80) D_009A85D8 |= BIT(6); break;
			}//end switch
		}
	}//end for
	//-- LEFT --
	if(D_009A873C < -lolo.dwMouseMin) {
		D_009A85D8 |= BIT(3);
		//-- repeat --
		if(D_009A85E4) {
			if(D_009A873C < -lolo.dwMouseMax)
				D_009A873C = -lolo.dwMouseMax;
			lolo.bp_0c = D_009A85E4 - D_009A85E4 * (-D_009A873C / lolo.dwMouseMax);
			if(D_009A8730 >= lolo.bp_0c)
				D_009A8724 |= BIT(3);
		}
		//-- --
		D_009A873C = 0;
	}
	//-- RIGHT --
	if(D_009A873C > lolo.dwMouseMin) {
		D_009A85D8 |= BIT(2);
		//-- repeat --
		if(D_009A85E4) {
			if(D_009A873C > lolo.dwMouseMax)
				D_009A873C = lolo.dwMouseMax;
			lolo.bp_0c = D_009A85E4 - D_009A85E4 * (D_009A873C / lolo.dwMouseMax);
			if(D_009A8730 >= lolo.bp_0c)
				D_009A8724 |= BIT(2);
		}
		//-- --
		D_009A873C = 0;
	}
	//-- UP --
	if(D_009A8740 < -lolo.dwMouseMin) {
		D_009A85D8 |= BIT(0);
		//-- repeat --
		if(D_009A85E4) {
			if(D_009A8740 < -lolo.dwMouseMax)
				D_009A8740 = -lolo.dwMouseMax;
			lolo.bp_0c = D_009A85E4 - D_009A85E4 * (-D_009A8740 / lolo.dwMouseMax);
			if(D_009A8730 >= lolo.bp_0c)
				D_009A8724 |= BIT(0);
		}
		//-- --
		D_009A8740 = 0;
	}
	//-- DOWN --
	if(D_009A8740 > lolo.dwMouseMin) {
		D_009A85D8 |= BIT(1);
		//-- repeat --
		if(D_009A85E4) {
			if(D_009A8740 > lolo.dwMouseMax)
				D_009A8740 = lolo.dwMouseMax;
			lolo.bp_0c = D_009A85E4 - D_009A85E4 * (D_009A8740 / lolo.dwMouseMax);
			if(D_009A8730 >= lolo.bp_0c)
				D_009A8724 |= BIT(1);
		}
		//-- --
		D_009A8740 = 0;
	}
	//-- --

	return D_009A85D8;
}

//get mouse mask[unused]?
/*0041B08F*/int PAD_getMouseMask() {
	return D_009A85D8;
}

//test input mask[w repeat]?
/*0041B099*/int PAD_testRepeat(unsigned dwMask/*bp08*/) {
	if(D_009A85E4 == 0)
		return PAD_test(dwMask);
	if(PAD_test(dwMask))
		return D_009A872C;

	return 0;
}

//get mouse mask[w repeat][unused]?
/*0041B0CE*/int PAD_getMouseMaskRepeat() {
	return D_009A8724;
}

/*0041B0D8*/void PAD_setRepeatParams(int bp08, int bp0c) {
	D_009A85C8 = bp08;
	D_009A85E4 = bp0c;
}

//get input repeat parameters?
void __0041B0EE(int *bp08, int *bp0c) {
	*bp08 = D_009A85C8;
	*bp0c = D_009A85E4;
}

//manage repeat
void C_0041B108() {
	D_009A872C = 0;
	if(D_009A85E0 != 0) {
		D_009A8734 = 0;
		D_009A8714 = D_009A85C8;
		D_009A872C = 1;
		D_009A8730 = 0;
	} else if(D_009A85D4 && D_009A8730 >= D_009A8714) {
		D_009A8714 = D_009A85E4;
		D_009A8734 = 1;
		D_009A872C = 1;
		D_009A8730 = 0;
	}
}

void __0041B18B() {
	D_009A8730 = 0;
	D_009A85C8 = 0;
	D_009A85E4 = D_009A85C8;
	D_009A8734 = 0;
}

//[condor only]
/*0041B1B8*/int PAD_isMouseButtonPressed(int bp08) {
	if(D_009A85DC) {
		switch(bp08) {
			case LOCAL_DIK_MOUSE_B1: return D_009A85DC->rgbButtons[0] & 0x80; break;
			case LOCAL_DIK_MOUSE_B2: return D_009A85DC->rgbButtons[1] & 0x80; break;
			case LOCAL_DIK_MOUSE_B3: return D_009A85DC->rgbButtons[2] & 0x80; break;
			default:
				return 0;
		}//end switch
	}

	return 0;
}

//[submarine only]
/*0041B22B*/int PAD_isKeyPressed(unsigned bp08) {
	if(bp08 > 0xff)
		return 0;
	if(D_009A85CC)
		return D_009A85CC[bp08] & 0x80;

	return 0;
}

//get mouse X/Y
void *__0041B25D() {
	return &D_009A85C0;
}

//mouse related
void __0041B267(int dwPointerX/*bp08*/, int dwPointerY/*bp0c*/) {
	if(dwPointerX < 0 || dwPointerY < 0)
		return;
	if(D_009A85D0) {
		if(D_009A85D0->dwDisplayWidth >= dwPointerX)
			D_009A85D0->dwPointerX = D_009A85C0 = dwPointerX;
		if(D_009A85D0->dwDisplayHeight >= dwPointerY)
			D_009A85D0->dwPointerY = D_009A85C4 = dwPointerY;
	}
}

void __0041B2D8() {
	D_009A8730 = 0;
	D_009A8734 = 0;
}
