#ifndef __FF7_SOUND_H__
#define __FF7_SOUND_H__

#include <windows.h>
#include <dsound.h>
//#include <stdio.h>

#define NUM_SONGS 0x62
//====---- sound ----====
struct t_sound_related_24 {//size 0x24
	/*00*/unsigned short wOpCode; char __02[2];
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
	/*0c*/char *szThreadName;
};
//====---- C_00740D80.cpp ----====
#define SOUND_OP_10 0x10	//"MUSIC"
#define SOUND_OP_14 0x14	//"MUSVT"
#define SOUND_OP_15 0x15	//"MUSVM"

#define SOUND_OP_18 0x18	//"MUSIC"+cross fade
#define SOUND_OP_19 0x19	//"MUSVT"+cross fade

#define SOUND_OP_20 0x20	//"SOUND"//play 1 sfx
#define SOUND_OP_21 0x21	//play 2 sfx
#define SOUND_OP_22 0x22	//play 3 sfx
#define SOUND_OP_23 0x23	//play 4 sfx

#define SOUND_OP_24 0x24	//play 1 sfx
#define SOUND_OP_25 0x25	//play 2 sfx
#define SOUND_OP_26 0x26	//play 3 sfx
#define SOUND_OP_27 0x27	//play 4 sfx

#define SOUND_OP_28 0x28	//[ch=1]
#define SOUND_OP_29 0x29	//[ch=2]
#define SOUND_OP_2A 0x2a	//[ch=3]
#define SOUND_OP_2B 0x2b	//[ch=4]

#define SOUND_OP_30 0x30	//sound:play SE?

#define SOUND_OP_98 0x98	//resume
#define SOUND_OP_99 0x99	//pause
#define SOUND_OP_9A 0x9a	//resume
#define SOUND_OP_9B 0x9b	//pause
#define SOUND_OP_9C 0x9c	//sound:resume
#define SOUND_OP_9D 0x9d	//sound:pause

#define SOUND_OP_A0 0xa0	//[ch=1]volume
#define SOUND_OP_A1 0xa1	//[ch=2]volume
#define SOUND_OP_A2 0xa2	//[ch=3]volume
#define SOUND_OP_A3 0xa3	//[ch=4]volume

#define SOUND_OP_A4 0xa4	//[ch=1]Volume transition
#define SOUND_OP_A5 0xa5	//[ch=2]Volume transition
#define SOUND_OP_A6 0xa6	//[ch=3]Volume transition
#define SOUND_OP_A7 0xa7	//[ch=4]Volume transition

#define SOUND_OP_A8 0xa8	//[ch=1]PAN
#define SOUND_OP_A9 0xa9	//[ch=2]PAN
#define SOUND_OP_AA 0xaa	//[ch=3]PAN
#define SOUND_OP_AB 0xab	//[ch=4]PAN

#define SOUND_OP_AC 0xac	//[ch=1]Pan transition
#define SOUND_OP_AD 0xad	//[ch=2]Pan transition
#define SOUND_OP_AE 0xae	//[ch=3]Pan transition
#define SOUND_OP_AF 0xaf	//[ch=4]Pan transition

#define SOUND_OP_B0 0xb0	//[ch=1]Tempo
#define SOUND_OP_B1 0xb1	//[ch=2]Tempo
#define SOUND_OP_B2 0xb2	//[ch=3]Tempo
#define SOUND_OP_B3 0xb3	//[ch=4]Tempo

#define SOUND_OP_B4 0xb4	//[ch=1]Tempo transition
#define SOUND_OP_B5 0xb5	//[ch=2]Tempo transition
#define SOUND_OP_B6 0xb6	//[ch=3]Tempo transition
#define SOUND_OP_B7 0xb7	//[ch=4]Tempo transition

#define SOUND_OP_B8 0xb8	//volume
#define SOUND_OP_B9 0xb9	//Volume transition
#define SOUND_OP_BA 0xba	//PAN
#define SOUND_OP_BB 0xbb	//Pan transition
#define SOUND_OP_BC 0xbc	//Tempo
#define SOUND_OP_BD 0xbd	//Tempo transition

#define SOUND_OP_C0 0xc0	//volume(music)
#define SOUND_OP_C1 0xc1	//volume trans(music)
#define SOUND_OP_C2 0xc2	//volume fade(music)

#define SOUND_OP_D0 0xd0	//"MIDI set tempo"
#define SOUND_OP_D1 0xd1	//"MIDI set tempo trans"
#define SOUND_OP_D2 0xd2	//"MIDI fade tempo"

#define SOUND_OP_E4 0xe4	//???

#define SOUND_OP_F0 0xf0	//stop
#define SOUND_OP_F1 0xf1	//stop

#define SOUND_OP_F4 0xf4	//???
#define SOUND_OP_F5 0xf5	//???

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
/*C_00745CF3*/extern int sound_load(int, LPDIRECTSOUNDBUFFER *);
/*C_00745DBB*/extern void sound_unload(int, int);
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
/*C_0074938D*/extern void sound_group_init(struct t_sound_thread_10 **);
/*C_00749404*/extern void sound_group_play(unsigned char, int);
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
