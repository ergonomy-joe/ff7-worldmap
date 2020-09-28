/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//WORLD MAP -- dialog?[very similar to C_00630940.cpp]

#include "ff7.h"
#include "loadmenu.h"
#include "menu_data.h"
#include "field_data.h"
////////////////////////////////////////
short D_00E3B130[4];
short D_00E3B138[4][8];
void *D_00E3B178;
unsigned char D_00E3B180[4][8];
unsigned char D_00E3B1A0[4][0x10];
short D_00E3B1E0[4];
short D_00E3B1E8[4];
short D_00E3B1F0[4];
short D_00E3B1F8[4];
short D_00E3B200[4];
short D_00E3B208[4];
unsigned char *D_00E3B210[4];
unsigned char D_00E3B220[4][0x100];
short D_00E3B620[4];
////////////////////////////////////////
void __00768C70() {
}

//<empty>
void C_00768C75(const char *_p08) {
	//
}

void C_00768CE4(short);//init dialog

//reset offset to strings(1)
void C_00768C7A() {
	int i;

	D_00CC0B64 = 0;
	for(i = 0; i < 4; i ++)
		C_00768CE4(i);//init dialog
	//-- --
	if(D_00CBF5E8->f_04)
		D_00E3B178 = (unsigned char *)D_00CBF5E8 + D_00CBF5E8->f_04;
	else
		D_00E3B178 = 0;
}

//
//
//
//
//
//
//

//init dialog
void C_00768CE4(short wDialogId/*bp08*/) {
	int i;

	switch(wDialogId) {
		case 1: D_00CFF5B8[wDialogId].wDialogY = 8; break;
		default:
			D_00CFF5B8[wDialogId].wDialogY = 0x95;
	}
	D_00CFF5B8[wDialogId].wStatus = 0;
	D_00CFF5B8[wDialogId].cAttr = 0;
	D_00CFF5B8[wDialogId].wDialogX = 8;
	D_00CFF5B8[wDialogId].wDialogWidth = 0x130;
	D_00CFF5B8[wDialogId].wDialogHeight = 0x49;
	D_00CFF5B8[wDialogId].wDialogCurWidth = 1;
	D_00CFF5B8[wDialogId].wDialogCurHeight = 1;
	D_00CFF5B8[wDialogId].cDisplayCount = 0;
	D_00CFF5B8[wDialogId].f_1c = 0;
	D_00CFF5B8[wDialogId].f_1d = 6;
	D_00CFF5B8[wDialogId].wRelCountX = 0;
	D_00CFF5B8[wDialogId].wRelCountY = 0;
	D_00CFF5B8[wDialogId].f_2e = 0;

	D_00CC0960[wDialogId] = 0xff;
	for(i = 0; i < 8; i ++) {
		D_00E3B180[wDialogId][i] = 0;
		D_00E3B138[wDialogId][i] = 0;
	}
	D_00E3B208[wDialogId] = 0;
}

int C_00768E3D(short wDialogId/*bp08*/) {
	switch(D_00CFF5B8[wDialogId].wStatus) {
		case 1:
			return 0;
		case 2: case 4: case 6: case 8: case 0xb: case 0xd:
			D_00CFF5B8[wDialogId].wStatus = 7;
			return 1;
		default:
			return 1;
	}//end switch
}

//dialog:set attributes ...
void C_00768EC3(short wDialogId/*bp08*/, short bp0c, short bp10) {
	D_00CFF5B8[wDialogId].cAttr = (char)bp0c;
	D_00CFF5B8[wDialogId].f_2e = bp10;
}

void __00768EEA() {
	int i;

	for(i = 0; i < 4; i ++) {
		D_00CFF5B8[i].wStatus = 0;
		D_00CFF5B8[i].wCharCount = 0;
		D_00CC0960[i] = 0xff;
		D_00E3B208[i] = 0;
	}
	D_00CC0B64 = 0;
}

//dialog:set location and size
void C_00768F48(short wDialogId/*bp08*/, short wDialogX/*bp0c*/, short wDialogY/*bp10*/, short wDialogWidth/*bp14*/, short wDialogHeight/*bp18*/) {
	if(wDialogX < 8)
		wDialogX = 8;
	if(wDialogX + wDialogWidth > 0x138)
		wDialogX = 0x138 - wDialogWidth;
	if(wDialogY < 8)
		wDialogY = 8;
	if(wDialogY + wDialogHeight > 0xe0)
		wDialogY = 0xe0 - wDialogHeight;
	D_00CFF5B8[wDialogId].wDialogX = wDialogX;
	D_00CFF5B8[wDialogId].wDialogY = wDialogY;
	D_00CFF5B8[wDialogId].wDialogWidth = wDialogWidth;
	D_00CFF5B8[wDialogId].wDialogHeight = wDialogHeight;
}

//dialog:move
void __00768FF4(short wDialogId/*bp08*/, short wIncrX/*bp0c*/, short wIncrY/*bp10*/) {
	D_00CFF5B8[wDialogId].wDialogX += wIncrX;
	D_00CFF5B8[wDialogId].wDialogY += wIncrY;
}

//dialog:set height
void __00769039(short wDialogId/*bp08*/, short bp0c) {
	D_00CFF5B8[wDialogId].wDialogHeight = bp0c;
}

int C_00769836(short, short);//open dialog window?
void C_00769A66(short);//"1" -- expand window?
void C_00769C02(short);//"2" --
void C_0076ABE9(short);//"8" --
void C_0076AC4F(short);//"0xc" --
void C_0076AD5E(short);//"0xe/9" --
int C_0076ADF7(short);//reduce window?

//dialog:refresh(1)
int C_00769050(unsigned char wDialogId/*bp08*/, unsigned char wScriptId/*bp0c*/) {
	switch(D_00CFF5B8[wDialogId].wStatus) {
		case 0:
			if(C_00769836(wDialogId, wScriptId))//open dialog window?
				return 1;
		break;
		case 1:
			C_00769A66(wDialogId);//"1" -- expand window?
		break;
		case 2:
			C_00769C02(wDialogId);//"2" --
		break;
		case 8:
			C_0076ABE9(wDialogId);//"8" --
		break;
		case 0xc:
			C_0076AC4F(wDialogId);//"0xc" --
		break;
		case 0xd:
			if(D_00CBF9D8->f_78.dwKEYON & 0x20)
				D_00CFF5B8[wDialogId].wStatus = 2;
		break;
		case 3:
			if(D_00E3B208[wDialogId] == 0)
				D_00CFF5B8[wDialogId].wStatus = 2;
			else
				D_00E3B208[wDialogId] --;
		break;
		case 4:
			if(D_00CBF9D8->f_78.dwKEYON & 0x20) {//else 00769237
				if(D_00CFF5B8[wDialogId].wDispCRCount == (D_00CFF5B8[wDialogId].wDialogHeight - 9) / 0x10 + D_00E3B620[wDialogId] - 1) {//else 00769237
					D_00CFF5B8[wDialogId].wStatus = 8;
					D_00CFF5B8[wDialogId].wRelTextY -= 2;
					D_00E3B620[wDialogId] ++;
				}
			}
		break;
		case 6:
			if(D_00CFF5B8[wDialogId].f_2e & 1) {
				;//
			} else if(D_00CBF9D8->f_78.dwKEYON & 0x20) {
				D_00CFF5B8[wDialogId].wStatus = 7;
				C_0076ADF7(wDialogId);//reduce window?
			}
		break;
		case 0xe:
			if(D_00CBF9D8->f_78.dwKEYON & 0x20)
				C_0076AD5E(wDialogId);//"0xe/9" --
		break;
		case 0xb:
			if(D_00CBF9D8->f_78.dwKEYON & 0x20) {
				D_00CFF5B8[wDialogId].wStatus = 0xc;
				D_00E3B200[wDialogId] = D_00CFF5B8[wDialogId].wDispCRCount * 0x10 + 0x11;
				D_00CFF5B8[wDialogId].wRelTextY -= 2;
			}
		break;
		case 9:
			C_0076AD5E(wDialogId);//"0xe/9" --
		break;
		case 5: case 7:
			if(C_0076ADF7(wDialogId))//reduce window?
				return 1;
		break;
	}//end switch

	return 0;
}

void C_00769827(void);//play SE 1

//dialog:refresh(2)
int C_007693A1(unsigned char wDialogId/*bp08*/, unsigned char wScriptId/*bp0c*/, unsigned char bp10, unsigned char bp14, short *bp18) {
	switch(D_00CFF5B8[wDialogId].wStatus) {
		case 0:
			if(C_00769836(wDialogId, wScriptId))//open dialog window?
				return 1;
		break;
		case 1:
			C_00769A66(wDialogId);//"1" -- expand window?
		break;
		case 2:
			C_00769C02(wDialogId);//"2" --
		break;
		case 8:
			C_0076ABE9(wDialogId);//"8" --
		break;
		case 0xc:
			C_0076AC4F(wDialogId);//"0xc" --
		break;
		case 0xd:
			if(D_00CBF9D8->f_78.dwKEYON & 0x20)
				D_00CFF5B8[wDialogId].wStatus = 2;
		break;
		case 3:
			if(D_00E3B208[wDialogId] == 0)
				D_00CFF5B8[wDialogId].wStatus = 2;
			else
				D_00E3B208[wDialogId] --;
		break;
		case 4:
			if(D_00CBF9D8->f_78.dwKEYON & 0x20) {//else 00769588
				if(D_00CFF5B8[wDialogId].wDispCRCount == (D_00CFF5B8[wDialogId].wDialogHeight - 9) / 0x10 + D_00E3B620[wDialogId] - 1) {//else 00769588
					D_00CFF5B8[wDialogId].wStatus = 8;
					D_00CFF5B8[wDialogId].wRelTextY -= 2;
					D_00E3B620[wDialogId] ++;
				}
			}
		break;
		case 6:
			if(D_00CFF5B8[wDialogId].f_2e & 1) {
				;//goto 007696DE
			} else {
				D_00CFF5B8[wDialogId].cDisplayHand = 1;
				if(D_00CBF9D8->f_68.dwKEYON & 0x1000) {
					if(*bp18 > bp10)
						C_00769827();//play SE 1
					(*bp18) --;
				}
				if(D_00CBF9D8->f_68.dwKEYON & 0x4000) {
					if(*bp18 < bp14)
						C_00769827();//play SE 1
					(*bp18) ++;
				}
				if(*bp18 < bp10)
					*bp18 = bp10;
				if(*bp18 > bp14)
					*bp18 = bp14;
				D_00CFF5B8[wDialogId].wRelHandX = 5;
				D_00CFF5B8[wDialogId].wRelHandY = *bp18 * 0x10 + 6;
				if(D_00CBF9D8->f_78.dwKEYON & 0x20) {//else 007696DE
					C_00769827();//play SE 1
					D_00CFF5B8[wDialogId].wStatus = 7;
					C_0076ADF7(wDialogId);//reduce window?
				}
			}
		break;
		case 0xe:
			if(D_00CBF9D8->f_78.dwKEYON & 0x20)
				C_0076AD5E(wDialogId);//"0xe/9" --
		break;
		case 0xb:
			if(D_00CBF9D8->f_78.dwKEYON & 0x20) {
				D_00CFF5B8[wDialogId].wStatus = 0xc;
				D_00E3B200[wDialogId] = D_00CFF5B8[wDialogId].wDispCRCount * 0x10 + 0x11;
				D_00CFF5B8[wDialogId].wRelTextY -= 2;
			}
		break;
		case 9:
			C_0076AD5E(wDialogId);//"0xe/9" --
		break;
		case 5: case 7:
			if(C_0076ADF7(wDialogId)) {//reduce window?
				D_00CFF5B8[wDialogId].cDisplayHand = 0;
				return 1;
			}
			D_00CFF5B8[wDialogId].cDisplayHand ^= 1;
		break;
	}//end switch

	return 0;
}

//play SE 1
void C_00769827() {
	C_0074580A(1);//sound:play SE?
	//
	//
	//
	//
}

//open dialog window?
int C_00769836(short wDialogId/*bp08*/, short wScriptId/*bp0c*/) {
	if(D_00E3B178 == 0) {
		C_00768C75("No mes data!");
		return 1;
	}
	if(D_00CC0960[wDialogId] != 0xff)
		return 0;
	D_00CC0960[wDialogId] = D_00CC0964;
	D_00CFF5B8[wDialogId].wDialogCurWidth = D_00CFF5B8[wDialogId].wDialogWidth / 4;
	D_00CFF5B8[wDialogId].wDialogCurHeight = D_00CFF5B8[wDialogId].wDialogHeight / 4;
	if(D_00CFF5B8[wDialogId].wDialogCurHeight < 8)
		D_00CFF5B8[wDialogId].wDialogCurHeight = 8;
	if(D_00CFF5B8[wDialogId].wDialogCurWidth < 8)
		D_00CFF5B8[wDialogId].wDialogCurWidth = 8;
	D_00CFF5B8[wDialogId].wRelTextY = 0;
	D_00CFF5B8[wDialogId].wCharCount = 0;
	D_00CFF5B8[wDialogId].wDispTextLen = 0;
	D_00CFF5B8[wDialogId].wDispCRCount = 0;
	D_00CFF5B8[wDialogId].cDisplayHand = 0;
	D_00CFF5B8[wDialogId].pText = D_00E3B220[wDialogId];
	D_00E3B220[wDialogId][0] = 0xff;
	//-- --
	D_00E3B210[wDialogId] = (unsigned char *)D_00E3B178;
	D_00E3B210[wDialogId] += *((unsigned char *)D_00E3B178 + wScriptId * 2 + 2);
	D_00E3B210[wDialogId] += *((unsigned char *)D_00E3B178 + wScriptId * 2 + 3) << 8;
	//-- --
	D_00E3B1F0[wDialogId] = 1;
	D_00E3B1E8[wDialogId] = 0;
	D_00E3B620[wDialogId] = 0;
	D_00E3B1F8[wDialogId] = 0;
	D_00E3B130[wDialogId] = 0;
	D_00E3B1E0[wDialogId] = -1;
	D_00CFF5B8[wDialogId].wStatus = 1;
	D_00CC0B64 ++;

	return 0;
}

//"1" -- expand window?
void C_00769A66(short wDialogId/*bp08*/) {
	if(D_00CC0960[wDialogId] != D_00CC0964)
		return;
	D_00CFF5B8[wDialogId].wDialogCurWidth += D_00CFF5B8[wDialogId].wDialogWidth / 4;
	if(D_00CFF5B8[wDialogId].wDialogCurWidth < 8)
		D_00CFF5B8[wDialogId].wDialogCurWidth = 8;
	if(D_00CFF5B8[wDialogId].wDialogCurWidth > D_00CFF5B8[wDialogId].wDialogWidth)
		D_00CFF5B8[wDialogId].wDialogCurWidth = D_00CFF5B8[wDialogId].wDialogWidth;

	D_00CFF5B8[wDialogId].wDialogCurHeight += D_00CFF5B8[wDialogId].wDialogHeight / 4;
	if(D_00CFF5B8[wDialogId].wDialogCurHeight < 8)
		D_00CFF5B8[wDialogId].wDialogCurHeight = 8;
	if(D_00CFF5B8[wDialogId].wDialogCurHeight > D_00CFF5B8[wDialogId].wDialogHeight)
		D_00CFF5B8[wDialogId].wDialogCurHeight = D_00CFF5B8[wDialogId].wDialogHeight;

	if(D_00CFF5B8[wDialogId].wDialogCurWidth == D_00CFF5B8[wDialogId].wDialogWidth && D_00CFF5B8[wDialogId].wDialogCurHeight == D_00CFF5B8[wDialogId].wDialogHeight)
		D_00CFF5B8[wDialogId].wStatus = 2;
}

short C_0076AF3D(short);
void C_0076B375(unsigned short, unsigned char *);//int to FF7 string(1)
void C_0076B432(unsigned short, unsigned char *);//int to FF7 string(2)
void C_0076B515(unsigned short, unsigned char *);//int to FF7 string(3)

//"2" --
void C_00769C02(short wDialogId/*bp08*/) {
	struct {
		unsigned short bp_18; char _p_18[2];
		short bp_14; char _p_14[2];
		short bp_10; char _p_10[2];
		short bp_0c; char _p_0c[2];
		//
		unsigned char *bp_08;
		unsigned short bp_04; char _p_04[2];
	}lolo;

	//
	if(D_00CC0960[wDialogId] != D_00CC0964)
		return;
	if(D_00CFF5B8[wDialogId].f_2e & 2) {
		lolo.bp_10 = 0x100;
		lolo.bp_0c = 1;
	} else {
		if(D_00CBF9D8->f_78.dwKEY & 0x20) {//else 00769C9C
			D_00E3B1F0[wDialogId] ++;
			if(D_00E3B1F0[wDialogId] > 0x80)
				D_00E3B1F0[wDialogId] = 0x80;
		} else {
			D_00E3B1F0[wDialogId] --;
			if(D_00E3B1F0[wDialogId] <= 1)
				D_00E3B1F0[wDialogId] = 1;
		}
		if(D_00DBFD38.f_10ec < 0x80) {
			lolo.bp_10 = ((0x80 - D_00DBFD38.f_10ec) >> 5) + 2;
			lolo.bp_0c = 1;
		} else {
			lolo.bp_10 = 2;
			lolo.bp_0c = ((D_00DBFD38.f_10ec - 0x80) >> 5) + 1;
		}
	}
	D_00E3B1E8[wDialogId] += lolo.bp_10 + (D_00E3B1F0[wDialogId] >> 4) * lolo.bp_0c;
	while(D_00E3B1E8[wDialogId] > lolo.bp_0c) {//0076AB44
		switch(*D_00E3B210[wDialogId]) {
			case 0xff:
				D_00CFF5B8[wDialogId].wStatus = 6;
				D_00E3B1E8[wDialogId] = 0;
				goto C_0076AB44;
			case 0xe7:
				if(D_00CFF5B8[wDialogId].wDispCRCount == (D_00CFF5B8[wDialogId].wDialogHeight - 9) / 0x10 + D_00E3B620[wDialogId] - 1) {
					D_00CFF5B8[wDialogId].wStatus = 4;
					D_00E3B1F0[wDialogId] = 1;
					D_00E3B1E8[wDialogId] = 0;
					goto C_0076AB44;
				}
				D_00E3B220[wDialogId][D_00CFF5B8[wDialogId].wDispTextLen] = *D_00E3B210[wDialogId];
				*D_00E3B210[wDialogId] ++;//bug?
				D_00CFF5B8[wDialogId].wDispTextLen ++;
				D_00CFF5B8[wDialogId].wDispCRCount ++;
			break;
			case 0xe8: case 0xe9:
				D_00E3B210[wDialogId] ++;
				D_00CFF5B8[wDialogId].wStatus = 0xe;
				D_00E3B1F0[wDialogId] = 1;
				D_00E3B1E8[wDialogId] = 0;
				goto C_0076AB44;
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			case 0xea: case 0xeb: case 0xec: case 0xed: case 0xee: case 0xef: case 0xf0: case 0xf1: case 0xf2:
				lolo.bp_04 = *D_00E3B210[wDialogId] - 0xea;
				lolo.bp_08 = C_006CB9B8(lolo.bp_04);//get character's name?
				if(lolo.bp_08[D_00E3B1F8[wDialogId]] == 0xff || D_00E3B1F8[wDialogId] >= 9) {
					D_00E3B210[wDialogId] ++;
					D_00E3B1F8[wDialogId] = 0;
				} else {//else 0076A03C
					D_00E3B220[wDialogId][D_00CFF5B8[wDialogId].wDispTextLen] = lolo.bp_08[D_00E3B1F8[wDialogId]];
					D_00CFF5B8[wDialogId].wDispTextLen ++;
					D_00E3B1F8[wDialogId] ++;
					D_00CFF5B8[wDialogId].wCharCount ++;
					D_00E3B1E8[wDialogId] -= lolo.bp_0c;
				}
			break;
			case 0xf3: case 0xf4: case 0xf5:
				lolo.bp_04 = D_00DC08F2[*D_00E3B210[wDialogId]];
				if(lolo.bp_04 == 0xff) {//else 0076A148
					if(D_00E3B1F8[wDialogId] >= 9) {
						D_00E3B210[wDialogId] ++;
						D_00E3B1F8[wDialogId] = 0;
					} else {
						D_00E3B220[wDialogId][D_00CFF5B8[wDialogId].wDispTextLen] = 0xd2;
						D_00CFF5B8[wDialogId].wDispTextLen ++;
						D_00E3B1F8[wDialogId] ++;
						D_00CFF5B8[wDialogId].wCharCount ++;
						D_00E3B1E8[wDialogId] -= lolo.bp_0c;
					}
				} else {
					lolo.bp_08 = C_006CB9B8(lolo.bp_04);//get character's name?
					if(lolo.bp_08[D_00E3B1F8[wDialogId]] == 0xff || D_00E3B1F8[wDialogId] >= 9) {
						D_00E3B210[wDialogId] ++;
						D_00E3B1F8[wDialogId] = 0;
					} else {
						D_00E3B220[wDialogId][D_00CFF5B8[wDialogId].wDispTextLen] = lolo.bp_08[D_00E3B1F8[wDialogId]];
						D_00CFF5B8[wDialogId].wDispTextLen ++;
						D_00E3B1F8[wDialogId] ++;
						D_00CFF5B8[wDialogId].wCharCount ++;
						D_00E3B1E8[wDialogId] -= lolo.bp_0c;
					}
				}
			break;
			case 0xfe:
				D_00E3B220[wDialogId][D_00CFF5B8[wDialogId].wDispTextLen] = *D_00E3B210[wDialogId];
				D_00E3B210[wDialogId] ++;
				D_00CFF5B8[wDialogId].wDispTextLen ++;
				switch(*D_00E3B210[wDialogId]) {
					case 0xdc:
						D_00CFF5B8[wDialogId].wDispTextLen --;
						D_00E3B210[wDialogId] ++;
						D_00CFF5B8[wDialogId].wStatus = 0xd;
						D_00E3B1F0[wDialogId] = 1;
						D_00E3B1E8[wDialogId] = 0;
						goto C_0076AB44;
					case 0xe0:
						D_00CFF5B8[wDialogId].wDispTextLen --;
						D_00E3B210[wDialogId] ++;
						D_00CFF5B8[wDialogId].wStatus = 0xb;
						D_00E3B1F0[wDialogId] = 1;
						D_00E3B1E8[wDialogId] = 0;
						goto C_0076AB44;
					case 0xde: case 0xdf: case 0xe1:
						D_00CFF5B8[wDialogId].wDispTextLen --;
						D_00E3B210[wDialogId] --;
						if(D_00E3B1E0[wDialogId] == -1) {//else 0076A4C8
							lolo.bp_04 = C_0076AF3D(wDialogId);
							switch(D_00E3B210[wDialogId][1]) {
								case 0xde: C_0076B375(lolo.bp_04, D_00E3B1A0[wDialogId]); break;//int to FF7 string(1)
								case 0xe1: C_0076B432(lolo.bp_04, D_00E3B1A0[wDialogId]); break;//int to FF7 string(2)
								case 0xdf: C_0076B515(lolo.bp_04, D_00E3B1A0[wDialogId]); break;//int to FF7 string(3)
							}//end switch
							D_00E3B1E0[wDialogId] ++;
						} else if(D_00E3B1A0[wDialogId][D_00E3B1E0[wDialogId]] == 0xff || D_00E3B1E0[wDialogId] >= 0x10) {//else 0076A545
							D_00E3B210[wDialogId] += 2;
							D_00E3B1E0[wDialogId] = -1;
							D_00E3B130[wDialogId] ++;
						} else {
							D_00E3B220[wDialogId][D_00CFF5B8[wDialogId].wDispTextLen] = D_00E3B1A0[wDialogId][D_00E3B1E0[wDialogId]];
							D_00CFF5B8[wDialogId].wDispTextLen ++;
							D_00E3B1E0[wDialogId] ++;
							D_00CFF5B8[wDialogId].wCharCount ++;
							D_00E3B1E8[wDialogId] -= lolo.bp_0c;
						}
					break;
					case 0xe2:
						D_00CFF5B8[wDialogId].wDispTextLen --;
						D_00E3B210[wDialogId] --;
						if(D_00E3B1E0[wDialogId] == -1) {//else 0076A72A
							lolo.bp_04 = D_00E3B210[wDialogId][2];
							lolo.bp_04 |= D_00E3B210[wDialogId][3] << 8;
							lolo.bp_18 = D_00E3B210[wDialogId][4];
							lolo.bp_18 |= D_00E3B210[wDialogId][5] << 8;
							for(lolo.bp_14 = 0; lolo.bp_14 < lolo.bp_18; lolo.bp_14 ++)
								D_00E3B1A0[wDialogId][lolo.bp_14] = D_00DBFD38.f_0ba4[lolo.bp_04 + lolo.bp_14];
							D_00E3B1A0[wDialogId][lolo.bp_14] = 0xff;
							D_00E3B1E0[wDialogId] ++;
						} else if(D_00E3B1A0[wDialogId][D_00E3B1E0[wDialogId]] == 0xff) {//else 0076A77A
							D_00E3B210[wDialogId] += 6;
							D_00E3B1E0[wDialogId] = -1;
						} else {
							D_00E3B220[wDialogId][D_00CFF5B8[wDialogId].wDispTextLen] = D_00E3B1A0[wDialogId][D_00E3B1E0[wDialogId]];
							D_00CFF5B8[wDialogId].wDispTextLen ++;
							D_00E3B1E0[wDialogId] ++;
							D_00CFF5B8[wDialogId].wCharCount ++;
							D_00E3B1E8[wDialogId] -= lolo.bp_0c;
						}
					break;
					case 0xd2: case 0xd3: case 0xd4: case 0xd5:
					case 0xd6: case 0xd7: case 0xd8: case 0xd9:
					case 0xda: case 0xdb: case 0xe9:
						D_00E3B220[wDialogId][D_00CFF5B8[wDialogId].wDispTextLen] = *D_00E3B210[wDialogId];
						D_00E3B210[wDialogId] ++;
						D_00CFF5B8[wDialogId].wDispTextLen ++;
					break;
					case 0xdd:
						D_00CFF5B8[wDialogId].wStatus = 3;
						D_00E3B210[wDialogId] ++;
						D_00CFF5B8[wDialogId].wDispTextLen ++;
						D_00E3B208[wDialogId] = *D_00E3B210[wDialogId];
						D_00E3B210[wDialogId] ++;
						D_00CFF5B8[wDialogId].wDispTextLen ++;
						D_00E3B208[wDialogId] |= *D_00E3B210[wDialogId] << 8;
						D_00E3B210[wDialogId] ++;
						D_00CFF5B8[wDialogId].wDispTextLen ++;
						goto C_0076AB44;
					default:
						D_00E3B220[wDialogId][D_00CFF5B8[wDialogId].wDispTextLen] = *D_00E3B210[wDialogId];
						D_00E3B210[wDialogId] ++;
						D_00CFF5B8[wDialogId].wDispTextLen ++;
						D_00CFF5B8[wDialogId].wCharCount ++;
						D_00E3B1E8[wDialogId] -= lolo.bp_0c;
				}//end switch
			break;
			case 0xfa: case 0xfb: case 0xfc: case 0xfd:
				D_00E3B220[wDialogId][D_00CFF5B8[wDialogId].wDispTextLen] = *D_00E3B210[wDialogId];
				D_00E3B210[wDialogId] ++;
				D_00CFF5B8[wDialogId].wDispTextLen ++;
				//no break
			default:
				D_00E3B220[wDialogId][D_00CFF5B8[wDialogId].wDispTextLen] = *D_00E3B210[wDialogId];
				D_00E3B210[wDialogId] ++;
				D_00CFF5B8[wDialogId].wDispTextLen ++;
				D_00CFF5B8[wDialogId].wCharCount ++;
				D_00E3B1E8[wDialogId] -= lolo.bp_0c;
		}//end switch
	}//end while
C_0076AB44:
	D_00E3B220[wDialogId][D_00CFF5B8[wDialogId].wDispTextLen] = 0xff;
}

//"8" --
void C_0076ABE9(short wDialogId/*bp08*/) {
	if(D_00CC0960[wDialogId] != D_00CC0964)
		return;
	if(D_00CFF5B8[wDialogId].wRelTextY & 0xf)
		D_00CFF5B8[wDialogId].wRelTextY -= 2;
	else
		D_00CFF5B8[wDialogId].wStatus = 2;
}

//"0xc" --
void C_0076AC4F(short wDialogId/*bp08*/) {
	if(D_00CC0960[wDialogId] != D_00CC0964)
		return;
	if(D_00CFF5B8[wDialogId].wRelTextY + D_00E3B200[wDialogId] > 0) {//else 0076AD4C
		D_00CFF5B8[wDialogId].wRelTextY -= D_00E3B1F0[wDialogId] >> 2;
		if(D_00CBF9D8->f_78.dwKEY & 0x20) {
			D_00E3B1F0[wDialogId] ++;
			if(D_00E3B1F0[wDialogId] > 0x80)
				D_00E3B1F0[wDialogId] = 0x80;
		} else {
			D_00E3B1F0[wDialogId] --;
			if(D_00E3B1F0[wDialogId] <= 1)
				D_00E3B1F0[wDialogId] = 1;
		}
	} else {
		D_00CFF5B8[wDialogId].wStatus = 9;
	}
}

//"0xe/9" --
void C_0076AD5E(short wDialogId/*bp08*/) {
	if(D_00CC0960[wDialogId] != D_00CC0964)
		return;
	D_00CFF5B8[wDialogId].wDispTextLen = 0;
	D_00CFF5B8[wDialogId].wCharCount = 0;
	D_00CFF5B8[wDialogId].wRelTextY = 0;
	D_00CFF5B8[wDialogId].wDispCRCount = 0;
	D_00CFF5B8[wDialogId].wStatus = 2;
	D_00E3B220[wDialogId][0] = 0xff;
	D_00E3B620[wDialogId] = 0;
	D_00E3B1F0[wDialogId] = 1;
}

//reduce window?
int C_0076ADF7(short wDialogId/*bp08*/) {
	if(D_00CC0960[wDialogId] != D_00CC0964)
		return 1;
	if(D_00CFF5B8[wDialogId].wDialogCurWidth < 8)
		D_00CFF5B8[wDialogId].wDialogCurWidth = 8;
	else
		D_00CFF5B8[wDialogId].wDialogCurWidth -= D_00CFF5B8[wDialogId].wDialogWidth / 4;
	if(D_00CFF5B8[wDialogId].wDialogCurHeight < 8)
		D_00CFF5B8[wDialogId].wDialogCurHeight = 8;
	else
		D_00CFF5B8[wDialogId].wDialogCurHeight -= D_00CFF5B8[wDialogId].wDialogHeight / 4;
	if(D_00CFF5B8[wDialogId].wDialogCurWidth <= 8 && D_00CFF5B8[wDialogId].wDialogCurHeight <= 8) {
		D_00CFF5B8[wDialogId].wCharCount = 0;
		D_00CFF5B8[wDialogId].wStatus = 0;
		D_00CC0960[wDialogId] = 0xff;
		D_00CC0B64 --;

		return 1;
	}

	return 0;
}

short C_0076AF3D(short wDialogId/*bp08*/) {
	unsigned short bp_08;
	unsigned short bp_04;

	switch(D_00E3B180[wDialogId][D_00E3B130[wDialogId]]) {
		case 0:
			bp_08 = D_00E3B138[wDialogId][D_00E3B130[wDialogId]];
		break;
		case 1:
			bp_04 = D_00E3B138[wDialogId][D_00E3B130[wDialogId]];
			bp_08 = D_00DBFD38.f_0ba4[bp_04];
		break;
		case 2:
			bp_04 = D_00E3B138[wDialogId][D_00E3B130[wDialogId]];
			bp_08 = D_00DBFD38.f_0ba4[bp_04];
			bp_08 |= D_00DBFD38.f_0ba4[bp_04 + 1] << 8;
		break;
		case 3:
			bp_04 = D_00E3B138[wDialogId][D_00E3B130[wDialogId]] + 0x100;
			bp_08 = D_00DBFD38.f_0ba4[bp_04];
		break;
		case 4:
			bp_04 = D_00E3B138[wDialogId][D_00E3B130[wDialogId]] + 0x100;
			bp_08 = D_00DBFD38.f_0ba4[bp_04];
			bp_08 |= D_00DBFD38.f_0ba4[bp_04 + 1] << 8;
		break;
		case 0xb:
			bp_04 = D_00E3B138[wDialogId][D_00E3B130[wDialogId]] + 0x200;
			bp_08 = D_00DBFD38.f_0ba4[bp_04];
		break;
		case 0xc:
			bp_04 = D_00E3B138[wDialogId][D_00E3B130[wDialogId]] + 0x200;
			bp_08 = D_00DBFD38.f_0ba4[bp_04];
			bp_08 |= D_00DBFD38.f_0ba4[bp_04 + 1] << 8;
		break;
		case 0xd:
			bp_04 = D_00E3B138[wDialogId][D_00E3B130[wDialogId]] + 0x300;
			bp_08 = D_00DBFD38.f_0ba4[bp_04];
		break;
		case 0xf:
			bp_04 = D_00E3B138[wDialogId][D_00E3B130[wDialogId]] + 0x400;
			bp_08 = D_00DBFD38.f_0ba4[bp_04];
		break;
		case 0xe:
			bp_04 = D_00E3B138[wDialogId][D_00E3B130[wDialogId]] + 0x300;
			bp_08 = D_00DBFD38.f_0ba4[bp_04];
			bp_08 |= D_00DBFD38.f_0ba4[bp_04 + 1] << 8;
		break;
		case 7:
			bp_04 = D_00E3B138[wDialogId][D_00E3B130[wDialogId]] + 0x400;
			bp_08 = D_00DBFD38.f_0ba4[bp_04];
			bp_08 |= D_00DBFD38.f_0ba4[bp_04 + 1] << 8;
		break;
		case 5:
			bp_04 = D_00E3B138[wDialogId][D_00E3B130[wDialogId]];
			bp_08 = D_00CC14D0[bp_04];
		break;
		case 6:
			bp_04 = D_00E3B138[wDialogId][D_00E3B130[wDialogId]];
			bp_08 = D_00CC14D0[bp_04];
			bp_08 |= D_00CC14D0[bp_04 + 1] << 8;
		break;
		default:
			bp_08 = 0;
	}//end switch

	return bp_08;
}

//FF7 codes for '0123456789abcdef'
unsigned char D_0096E0B0[] = {0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0xB4,0xB5,0xB6,0xB7,0xB8,0xB9};

//int to FF7 string(1)
void C_0076B375(unsigned short wValue/*bp08*/, unsigned char *bp0c) {
	struct {
		int local_4;
		short local_3; char _ocal_3[2];
		short local_2; char _ocal_2[2];
		short local_1; char _ocal_1[2];
	}lolo;
	
	lolo.local_4 = 0;
	lolo.local_3 = 10000;
	lolo.local_2 = 0;
	for(; lolo.local_3 > 1; lolo.local_3 /= 10) {
		lolo.local_1 = wValue / lolo.local_3;
		if(lolo.local_4 || lolo.local_1) {
			lolo.local_4 = 1;
			bp0c[lolo.local_2] = D_0096E0B0[lolo.local_1];
			lolo.local_2 ++;
			//
			//
			//
		}
		wValue -= lolo.local_1 * lolo.local_3;
	}
	bp0c[lolo.local_2] = D_0096E0B0[wValue];
	bp0c[lolo.local_2 + 1] = 0xff;
}

//int to FF7 string(2)
void C_0076B432(unsigned short wValue/*bp08*/, unsigned char *bp0c) {
	struct {
		int local_4;
		short local_3; char _ocal_3[2];
		short local_2; char _ocal_2[2];
		short local_1; char _ocal_1[2];
	}lolo;
	
	lolo.local_4 = 0;
	lolo.local_3 = 10000;
	lolo.local_2 = 0;
	for(; lolo.local_3 > 1; lolo.local_3 /= 10) {
		lolo.local_1 = wValue / lolo.local_3;
		if(lolo.local_4 || lolo.local_1) {
			lolo.local_4 = 1;
			bp0c[lolo.local_2] = D_0096E0B0[lolo.local_1];
			lolo.local_2 ++;
		} else if(lolo.local_4 == 0) {
			bp0c[lolo.local_2] = 0x3f;
			lolo.local_2 ++;
		}
		wValue -= lolo.local_1 * lolo.local_3;
	}
	bp0c[lolo.local_2] = D_0096E0B0[wValue];
	bp0c[lolo.local_2 + 1] = 0xff;
}

//int to FF7 string(3)
void C_0076B515(unsigned short wValue/*bp08*/, unsigned char *bp0c) {
	struct {
		int local_4;
		short local_3; char _ocal_3[2];
		short local_2; char _ocal_2[2];
		short local_1; char _ocal_1[2];
	}lolo;

	lolo.local_4 = 0;
	lolo.local_3 = 0x1000;
	lolo.local_2 = 0;
	for(; lolo.local_3 > 1; lolo.local_3 /= 0x10) {
		lolo.local_1 = wValue / lolo.local_3;
		if(lolo.local_4 || lolo.local_1) {
			lolo.local_4 = 1;
			bp0c[lolo.local_2] = D_0096E0B0[lolo.local_1];
			lolo.local_2 ++;
			//
			//
			//
		}
		wValue -= lolo.local_1 * lolo.local_3;
	}
	bp0c[lolo.local_2] = D_0096E0B0[wValue];
	bp0c[lolo.local_2 + 1] = 0xff;
}

int __0076B5D3(short bp08) {
	struct {
		unsigned char *bp_14;
		short bp_10; char _p_10[2];
		short bp_0c; char _p_0c[2];
		//
		unsigned char *bp_08;
		short bp_04; char _p_04[2];
	}lolo;

	//
	if(D_00E3B178 == 0) {
		C_00768C75("No mes data!");
		return 0;
	}
	lolo.bp_14 = (unsigned char *)D_00E3B178;
	lolo.bp_14 += *((unsigned char *)D_00E3B178 + bp08 * 2 + 2);
	lolo.bp_14 += *((unsigned char *)D_00E3B178 + bp08 * 2 + 3) << 8;
	lolo.bp_10 = 0;
	lolo.bp_0c = 0;
	while(lolo.bp_0c < 0x17) {
		switch(*lolo.bp_14) {
			case 0xff:
				goto C_0076B749;
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			//
			case 0xea: case 0xeb: case 0xec: case 0xed: case 0xee: case 0xef: case 0xf0: case 0xf1: case 0xf2:
				lolo.bp_04 = *lolo.bp_14 - 0xea;
				lolo.bp_08 = C_006CB9B8(lolo.bp_04);//get character's name?
				if(lolo.bp_08[lolo.bp_10] == 0xff || lolo.bp_10 >= 9) {
					lolo.bp_14 ++;
					lolo.bp_10 = 0;
				} else {
					D_00DC0C44[lolo.bp_0c] = lolo.bp_08[lolo.bp_10];
					lolo.bp_10 ++;
					lolo.bp_0c ++;
				}
			break;
			case 0xfa: case 0xfb: case 0xfc: case 0xfd: case 0xfe:
				D_00DC0C44[lolo.bp_0c] = *lolo.bp_14;
				lolo.bp_14 ++;
				lolo.bp_0c ++;
			//break;
			default:
				D_00DC0C44[lolo.bp_0c] = *lolo.bp_14;
				lolo.bp_14 ++;
				lolo.bp_0c ++;
		}//end switch
	}//end while
C_0076B749:
	D_00DC0C44[lolo.bp_0c] = 0xff;

	return 1;
}

void __0076B787(short bp08, short bp0c) {
	struct {
		unsigned char *local_3;
		short local_2; char _ocal_2[2];
		unsigned char *local_1;
	}lolo;

	if(D_00E3B178 == 0) {
		C_00768C75("No mes data!");
		return;
	}
	lolo.local_3 = (unsigned char *)D_00E3B178;
	lolo.local_3 += *((unsigned char *)D_00E3B178 + bp0c * 2 + 2);
	lolo.local_3 += *((unsigned char *)D_00E3B178 + bp0c * 2 + 3) << 8;
	lolo.local_2 = 0;
	lolo.local_1 = C_006CB9B8(bp08);//get character's name?
	while(*lolo.local_3 != 0xff) {
		*lolo.local_1 = *lolo.local_3;
		lolo.local_1 ++;
		lolo.local_3 ++;
		lolo.local_2 ++;
	}
	if(lolo.local_2 < 9)
		*lolo.local_1 = 0xff;
}
