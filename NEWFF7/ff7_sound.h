#ifndef __FF7_SOUND_H__
#define __FF7_SOUND_H__

#include <windows.h>
#include <dsound.h>
//#include <stdio.h>

#define NUM_SONGS 0x62
//====---- sound ----====
struct t_sound_related_24 {//size 0x24
	/*00*/unsigned short f_00; char __02[2];
	/*04*/int f_04[6];
	/*1c*/char __1c[8];
};

#define NUM_THREADSOUNDS 4

struct t_sound_thread_10 {//size 0x10
	/*00*/int aSoundId[NUM_THREADSOUNDS];
};

//thread info?
struct t_thread_10 {//size 0x10
	/*00*/int f_00;
	/*04*/int dwStackSize;
	/*08*/void (*pCallback)(void);
	/*0c*/char *f_0c;
};
//====---- C_00740D80.cpp ----====
extern int C_00740D80(unsigned short, int, int, int, int, int, int, int, int);
//====---- midi1.cpp ----====
extern int C_00741780(const char *, HWND);//MIDI:init
extern void C_00741F5F(void);//MIDI:reset
extern void C_00742055(int, int, int);//"MIDI play"
extern void C_00742BEE(int, int);//"MIDI cross fade"
extern void C_00742D7B(void);//"MIDI pause"
extern void C_00742DD3(void);//"MIDI resume"
extern void C_00742E2B(void);//"MIDI stop"
extern int C_00742EB3(void);//"MIDI status"
extern void C_00742EDA(unsigned);//"MIDI set master volume
extern void C_00742F37(unsigned);//"MIDI set volume"
extern void C_0074304C(unsigned, int);//"MIDI set volume trans"
extern void C_0074313D(int, unsigned, unsigned);//"MIDI fade volume"
extern void C_007431BD(char);//"MIDI set tempo"
extern void C_0074327A(char, int);//"MIDI set tempo trans"
extern void C_007432AC(char, unsigned char, char);//"MIDI fade tempo"
extern void C_00743C57(void);//midi1:refresh "trans"
extern int C_00744090(void);//get "volume control supported" flag
extern const char *C_007443E7(void);//MIDI:get archive's name
//====---- sound.cpp ----====
extern int C_00744400(const char *, const char *, HWND);//sound:init?
extern void C_007446D7(void);//sound:clean
extern void C_00744B13(void);//sound:refresh trans?
extern void C_00745160(unsigned char, int, int/*?*/);
extern void C_00745606(unsigned char, int, int/*?*/, int/*?*/, int/*?*/);
extern void C_0074580A(int);//sound:play SE?
extern void C_00745873(void);//sound:pause
extern void C_00745995(void);//sound:resume
extern void C_00745B64(void);//sound:stop(2)?
extern int C_00745CF3(int, LPDIRECTSOUNDBUFFER *);
extern void C_00745DBB(int, int);
extern void C_007478BD(int, int);
extern void C_00747AED(void);//sound:stop?
extern void C_00747B53(void);
extern void C_00747B9A(void);
extern int C_00747B3C(void);
extern void C_00747BE3(char);
extern void C_00747C15(char, char);
extern void C_00747C4B(unsigned char, int);
extern void C_00747DDA(unsigned char, int, unsigned char);
extern void C_00747F31(unsigned char);
extern void C_00747F63(unsigned char, unsigned char);
extern void C_00747F99(unsigned char, int);
extern void C_0074809E(unsigned char, int, unsigned char);
extern void C_007481AD(char);
extern void C_007481DF(char, unsigned char);
extern void C_00748215(char, int);
extern void C_00748309(char, int, unsigned char);
extern void C_00748525(int, int);
extern void C_00748669(unsigned char);
extern void C_00748750(unsigned char, unsigned char);
extern void C_00748861(unsigned char, unsigned char, unsigned char);
extern void C_00748D69(int, unsigned char, unsigned char, unsigned char);//sound:...
extern void C_00748F8F(int);
extern void C_0074908D(int);//sound:...
extern void C_007490EF(int);//sound:...
extern void C_0074913C(int);//sound:...
extern void C_007491CB(int, unsigned char);//sound:...
extern void C_0074933D(int);//set SE volume?
extern void C_0074934A(int);//set SE main volume?
extern int C_00749366(void);//get SE main volume?
extern int C_00749370(void);//get SE volume?
extern void C_0074938D(struct t_sound_thread_10 **);//sound:(called from battle)
extern void C_00749404(unsigned char, int);
extern void C_007497AC(void);
extern void C_007498AF(void);
extern void C_007498FA(void);
extern void C_00749C0D(int);//sound thread related
//====---- from C_00749EE0.cpp ----====
extern int C_0074A071(int, const char *, int);//check midi error?
//====---- from C_0074a0d0.cpp ----====
extern const char *C_0074A0D0(int);//get_midi_name
//====---- from C_0074AB90.cpp ----====
extern int C_0074AD6D(HRESULT, const char *, int);
//====---- from sfutils.cpp ----====
typedef WORD SFDEVINDEX;

extern int C_0074ADE0(void);//sfutils:load SFMAN32.DLL
extern int C_0074AF09(SFDEVINDEX);//sfutils:
extern int C_0074AF57(SFDEVINDEX);//sfutils:
extern int C_0074AF7D(SFDEVINDEX);//sfutils:
extern int C_0074AF93(SFDEVINDEX);//sfutils:
extern void C_0074AFA9(SFDEVINDEX);//sfutils:free library
extern SFDEVINDEX C_0074AFBA(unsigned *, unsigned *);//sfutils:
extern int C_0074B275(SFDEVINDEX);//sfutils:
extern int C_0074B3AF(SFDEVINDEX);//sfutils:
extern int C_0074B438(SFDEVINDEX);//sfutils:
extern int C_0074B4B4(unsigned/*?!?*/, unsigned short, char *);//sfutils:
extern int C_0074B4F6(SFDEVINDEX, unsigned short, unsigned short, unsigned short, unsigned short, const char *);//sfutils:
extern int C_0074B6EE(SFDEVINDEX, unsigned *, unsigned *);//sfutils:
extern int C_0074B746(SFDEVINDEX);//sfutils:
extern int C_0074B860(void);//sfutils:
extern int C_0074B87F(SFDEVINDEX);//sfutils:SF_ClearLoadedPreset
extern const char *C_0074B96C(int);
//====---- ----====

extern int D_00DDFFE4;//wave_music flag?

#endif
