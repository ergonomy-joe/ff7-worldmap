/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
//WORLD MAP -- 

#include "ff7.h"
#include "wm_data.h"
//////////////////////////////////////////////////
//TODO in another module?
struct t_wm_TerrainTriangle *D_00E36110;
int *D_00E36114;
unsigned char D_00E36118[8 + 0x1000];//"mes"
short D_00E37120[0x200];//"atn.tbl"
int D_00E37520;//[camera occlusion]flag?
int D_00E37524;//[undersea fog]distance threshold?
//char 00E37528[0x800]?
int D_00E37D28;//[camera occlusion]distance threshold?
struct t_wm_FieldTblEntry D_00E37D30[0x80];//"field.tbl"
struct t_wm_TerrainTriangle *D_00E38330;//seems unused
//////////////////////////////////////////////////
D3DVECTOR D_00E38338[0x80];
D3DVECTOR D_00E38938[0x80];//terrain vertices:screen coords
struct tVECTOR_F4 D_00E38F38[0x80];
D3DMATRIX D_00E39738;
D3DMATRIX D_00E39778;
int D_00E397B8[0x80];//screen clipping mask?
//////////////////////////////////////////////////
//wm:float to int
int C_0075F090(float bp08) {
	int bp_08;
//	LARGE_INTEGER bp_0c;

	_asm FLD bp08
	_asm FISTP QWORD PTR [EBP-0xc]
	_asm MOV EAX,[EBP-0xc]
	_asm MOV bp_08,EAX

	return bp_08;
}

//wm:send terrain vertices for rendering?
void C_0075F0AD(struct SVECTOR *bp08, int bp0c) {
	struct {
		float fOffsetY;//local_10
		float local_9;
		struct tVECTOR_F4 local_8;
		int i;//local_4
		int local_3;
		int local_2;
		int local_1;
	}lolo;

	C_006617E9(C_0066100D(), &D_00E39778);//psx:transformation to D3DMATRIX(3)
	C_0069C69F(&D_00E39778, D_00E360F4);//light:compute "result matrix"?
	C_0067D2BF(&D_00E39778, &D_00E39738);//dx_mat:matrix multiplication by "struct t_aa0::f_8d0" 4x4[transpose]
	lolo.local_3 = (D_00DE68F8 >> 1) + D_00E2C424;
	lolo.local_2 = 0;
	lolo.i = 0;
	do {
		D_00E38338[lolo.i].x = (float)bp08->vx;
		D_00E38338[lolo.i].y = (float)bp08->vy;
		D_00E38338[lolo.i].z = (float)bp08->vz;
		fast_multVectorByTransform(&D_00E39738, &(D_00E38338[lolo.i]), &lolo.local_8);
		fast_multVectorByRotTrans_Z_only(&D_00E39778, &(D_00E38338[lolo.i]), &(D_00E38938[lolo.i]));
		bp08 ++;
		lolo.local_2 -= bp0c;
		lolo.i ++;
		//-- "round earth" effect? --
		if(lolo.local_2 > 0) {//else 0075F21C
			lolo.fOffsetY = lolo.local_2 * (1.0f/64.0f);
			lolo.local_1 += -lolo.local_3;
			if(lolo.local_1 < 0)
				lolo.local_1 = 0 - lolo.local_1;
			lolo.local_9 = lolo.local_1 * (1.0f/32.0f);
			lolo.fOffsetY += lolo.local_9;
			lolo.fOffsetY *= lolo.fOffsetY;
			D_00E38338[lolo.i - 2].y -= lolo.fOffsetY;
		}
		//-- --
		lolo.local_2 = C_0075F090(D_00E38938[lolo.i - 1].z);//wm:float to int
		lolo.local_1 = C_0075F090(lolo.local_8.x / lolo.local_8.w);//wm:float to int
		lolo.local_2 >>= 2;
		//-- --
	} while(lolo.i < 0x7a);
}

//wm:2d clip terrain vertices?
void C_0075F263() {
	struct {
		float fWH_3;//local_16
		float fWH_2;//local_15
		float fWH_1;//local_14
		int i;//local_13
		int dwScreenY_3;//local_12
		int dwCount;//local_11
		int dwScreenY_2;//local_10
		int dwScreenY_1;//local_9
		int dwScreenX_3;//local_8
		int dwYVisible;//local_7
		int dwScreenX_2;//local_6
		int dwScreenX_1;//local_5
		int dwViewportBottom;//local_4
		int dwViewportTop;//local_3
		int dwViewportRight;//local_2
		int dwViewportLeft;//local_1
	}lolo;

	lolo.i = 0;
	lolo.dwViewportLeft = D_00E2C424;
	lolo.dwViewportTop = D_00E2C428;
	lolo.dwViewportRight = D_00DE68F8 + D_00E2C424;
	lolo.dwViewportBottom = D_00DE67E8 + D_00E2C428;
	fast_multVectorByTransform(&D_00E39738, &(D_00E38338[lolo.i + 0]), &(D_00E38F38[lolo.i + 0]));
	fast_multVectorByTransform(&D_00E39738, &(D_00E38338[lolo.i + 1]), &(D_00E38F38[lolo.i + 1]));
	fast_multVectorByTransform(&D_00E39738, &(D_00E38338[lolo.i + 2]), &(D_00E38F38[lolo.i + 2]));
	for(lolo.dwCount = 0x29, lolo.i = 3; lolo.dwCount > 0; lolo.dwCount --, lolo.i += 3) {
		fast_multVectorByTransform(&D_00E39738, &(D_00E38338[lolo.i + 0]), &(D_00E38F38[lolo.i + 0]));
		fast_multVectorByTransform(&D_00E39738, &(D_00E38338[lolo.i + 1]), &(D_00E38F38[lolo.i + 1]));
		fast_multVectorByTransform(&D_00E39738, &(D_00E38338[lolo.i + 2]), &(D_00E38F38[lolo.i + 2]));
		lolo.fWH_1 = 1.0f / D_00E38F38[lolo.i - 3].w;
		lolo.fWH_2 = 1.0f / D_00E38F38[lolo.i - 2].w;
		lolo.fWH_3 = 1.0f / D_00E38F38[lolo.i - 1].w;
		D_00E38938[lolo.i - 3].x = D_00E38F38[lolo.i - 3].x * lolo.fWH_1;
		D_00E38938[lolo.i - 3].y = D_00E38F38[lolo.i - 3].y * lolo.fWH_1;
		D_00E38938[lolo.i - 2].x = D_00E38F38[lolo.i - 2].x * lolo.fWH_2;
		D_00E38938[lolo.i - 2].y = D_00E38F38[lolo.i - 2].y * lolo.fWH_2;
		D_00E38938[lolo.i - 1].x = D_00E38F38[lolo.i - 1].x * lolo.fWH_3;
		D_00E38938[lolo.i - 1].y = D_00E38F38[lolo.i - 1].y * lolo.fWH_3;
		lolo.dwScreenX_1 = C_0075F090(D_00E38938[lolo.i - 3].x);//wm:float to int
		lolo.dwScreenY_1 = C_0075F090(D_00E38938[lolo.i - 3].y);//wm:float to int
		lolo.dwScreenX_2 = C_0075F090(D_00E38938[lolo.i - 2].x);//wm:float to int
		lolo.dwScreenY_2 = C_0075F090(D_00E38938[lolo.i - 2].y);//wm:float to int
		lolo.dwScreenX_3 = C_0075F090(D_00E38938[lolo.i - 1].x);//wm:float to int
		lolo.dwScreenY_3 = C_0075F090(D_00E38938[lolo.i - 1].y);//wm:float to int
		D_00E397B8[lolo.i - 3] = (lolo.dwScreenX_1 < lolo.dwViewportRight) & (lolo.dwScreenX_1 >= lolo.dwViewportLeft);
		lolo.dwYVisible = (lolo.dwScreenY_1 < lolo.dwViewportBottom) & (lolo.dwScreenY_1 >= lolo.dwViewportTop);
		D_00E397B8[lolo.i - 3] |= lolo.dwYVisible << 8;
		D_00E397B8[lolo.i - 2] = (lolo.dwScreenX_2 < lolo.dwViewportRight) & (lolo.dwScreenX_2 >= lolo.dwViewportLeft);
		lolo.dwYVisible = (lolo.dwScreenY_2 < lolo.dwViewportBottom) & (lolo.dwScreenY_2 >= lolo.dwViewportTop);
		D_00E397B8[lolo.i - 2] |= lolo.dwYVisible << 8;
		D_00E397B8[lolo.i - 1] = (lolo.dwScreenX_3 < lolo.dwViewportRight) & (lolo.dwScreenX_3 >= lolo.dwViewportLeft);
		lolo.dwYVisible = (lolo.dwScreenY_3 < lolo.dwViewportBottom) & (lolo.dwScreenY_3 >= lolo.dwViewportTop);
		D_00E397B8[lolo.i - 1] |= lolo.dwYVisible << 8;
	}//end for
}

float C_00760CC4(LPD3DVECTOR, LPD3DVECTOR, LPD3DVECTOR);
void C_00760D1B(float *, float *, float*, int *, int *, int *);//Z-sort indexes

//render terrain:1 "square"?
void C_0075F68C(struct t_wm_TerrainTriangle *bp08, struct t_wm_TerrainTriangle *bp0c, struct SVECTOR *pNormals/*bp10*/, struct POLY_GT3 *bp14_unused) {
	struct {
		//bp_100 and above for compiler
		struct t_dx_rend_vertex_20 *bp_fc;
		float fRHW2;//bp_f8
		struct t_dx_rend_vertex_20 *bp_f4;
		float fRHW1;//bp_f0
		struct t_dx_rend_vertex_20 *bp_ec;
		float fRHW0;//bp_e8
		tBGRA vcolor_0;//bp_e4
		DECL_unsigned_char(bClipSup2);
		int dwInd2;//bp_dc//check
		tBGRA vcolor_2;//bp_d8
		float fDiffZ12;//bp_d4
		DECL_unsigned_char(bClipSup);
		tBGRA vcolor_1;//bp_cc
		struct fBGRA bp_c8[3];
		float fDiffZ02;//bp_98
		DECL_unsigned_char(bClipInf);
		float fV2;//bp_90
		float fDiffZ01;//bp_8c
		struct SVECTOR *pNormal2;//bp_88
		int dwTex;//bp_84
		float fV1;//bp_80
		D3DVECTOR sNormalF2;//bp_7c
		int dw2DClipMask;//bp_70
		struct SVECTOR *pNormal1;//bp_6c
		DECL_unsigned_char(bClipInf2);
		float fV0;//bp_64
		D3DVECTOR sNormalF1;//bp_60
		float fScreenCenter;//bp_54
		struct SVECTOR *pNormal0;//bp_50
		unsigned dwPal_j;//bp_4c
		int dwInd0;//bp_48
		int dwInd1;//bp_44
		D3DVECTOR sNormalF0;//bp_40
		float fU2;//bp_34
		float fU1;//bp_30
		float fSomeDeterminant;//bp_2c
		float fTriangleZ;//bp_28
		float fU0;//bp_24
		tBGRA bp_20[3];
		int *bp_14;
		int dwDiffZ;//bp_10
		int dwPal_i;//bp_0c
		int bp_08_unused;
		struct t_wm_TerrainTriangle *bp_04;
	}lolo;

	//-- --
	lolo.bp_08_unused = 0;
	//-- --
	lolo.bp_20[0].bgra = lolo.bp_20[1].bgra = lolo.bp_20[2].bgra = 0xffffffff;

	lolo.bp_c8[0].r = lolo.bp_c8[1].r = lolo.bp_c8[2].r = 255.0f;
	lolo.bp_c8[0].g = lolo.bp_c8[1].g = lolo.bp_c8[2].g = 255.0f;
	lolo.bp_c8[0].b = lolo.bp_c8[1].b = lolo.bp_c8[2].b = 255.0f;
	lolo.bp_c8[0].a = lolo.bp_c8[1].a = lolo.bp_c8[2].a = 255.0f;
	//(used for camera occlusion test, for x and y)
	lolo.fScreenCenter = (float)/*lolo.bp_104/lolo.bp_100*/((D_00DE68F8 >> 1) + D_00E2C424);

	lolo.bp_04 = &(bp08[0]);
	do {
		lolo.dw2DClipMask = D_00E397B8[lolo.bp_04->vect0] | D_00E397B8[lolo.bp_04->vect1] | D_00E397B8[lolo.bp_04->vect2];
		if(!(lolo.dw2DClipMask & 0xff) | !(lolo.dw2DClipMask & 0xff00))
			goto next_triangle;//00760803 through 00760858
		//--  --
		lolo.fDiffZ01 = D_00E38938[lolo.bp_04->vect0].z - D_00E38938[lolo.bp_04->vect1].z;
		lolo.fTriangleZ = D_00E38938[lolo.bp_04->vect2].z;
		lolo.fSomeDeterminant = C_00760CC4(&(D_00E38938[lolo.bp_04->vect0]), &(D_00E38938[lolo.bp_04->vect1]), &(D_00E38938[lolo.bp_04->vect2]));
		//-- chocobo related? --
		if(D_00E36110 == 0)
			goto C_0075F866;//through 00760853
		if(D_00E36110 - lolo.bp_04 != 0)
			goto C_0075F866;//through 0076084E
		D_00E36110 = 0;
C_0075F866:
		//-- --
		lolo.fDiffZ02 = D_00E38938[lolo.bp_04->vect0].z - D_00E38938[lolo.bp_04->vect2].z;
		lolo.pNormal0 = &(pNormals[lolo.bp_04->vect0]);
		//-- --
		if(C_0075F090(lolo.fSomeDeterminant) < 0)//wm:float to int
			goto next_triangle;//00760803 through 0076084C
		//-- --
		lolo.pNormal1 = &(pNormals[lolo.bp_04->vect1]);
		if(C_0075F090(lolo.fDiffZ01) < 0)//wm:float to int
			goto C_0075F91F;//through 00760847
		lolo.pNormal2 = &(pNormals[lolo.bp_04->vect2]);
		if(C_0075F090(lolo.fDiffZ02) < 0)//wm:float to int
			goto C_0075F987;//through 00760842
		lolo.fTriangleZ = D_00E38938[lolo.bp_04->vect0].z;
		goto C_0075F987;//through 0076083D
C_0075F91F:
		lolo.fDiffZ12 = D_00E38938[lolo.bp_04->vect1].z - D_00E38938[lolo.bp_04->vect2].z;
		lolo.pNormal2 = &(pNormals[lolo.bp_04->vect2]);
		if(C_0075F090(lolo.fDiffZ12) < 0)//wm:float to int
			goto C_0075F987;//through 00760838
		lolo.fTriangleZ = D_00E38938[lolo.bp_04->vect1].z;
C_0075F987:
		//-- camera occlusion test? --
		//(when relief causes occlusion, a flag is set)
		lolo.dwDiffZ = C_0075F090(lolo.fTriangleZ) - D_00E37D28;//wm:float to int
		if(lolo.dwDiffZ > 0)
			goto occlusion_end;//0075FD4D through 00760833
		//-- x --
		lolo.bClipInf = /*lolo.bp_108*/D_00E38938[lolo.bp_04->vect0].x < lolo.fScreenCenter;
		lolo.bClipSup = /*lolo.bp_10c*/lolo.fScreenCenter < D_00E38938[lolo.bp_04->vect0].x;

		lolo.bClipInf2 = /*lolo.bp_110*/D_00E38938[lolo.bp_04->vect1].x < lolo.fScreenCenter;
		lolo.bClipSup2 = /*lolo.bp_114*/lolo.fScreenCenter < D_00E38938[lolo.bp_04->vect1].x;
		lolo.bClipInf |= lolo.bClipInf2;
		lolo.bClipSup |= lolo.bClipSup2;

		lolo.bClipInf2 = /*lolo.bp_118*/D_00E38938[lolo.bp_04->vect2].x < lolo.fScreenCenter;
		lolo.bClipSup2 = /*lolo.bp_11c*/lolo.fScreenCenter < D_00E38938[lolo.bp_04->vect2].x;
		lolo.bClipInf |= lolo.bClipInf2;
		lolo.bClipSup |= lolo.bClipSup2;

		lolo.bClipInf &= lolo.bClipSup;
		if(!lolo.bClipInf)
			goto occlusion_end;//0075FD4D through 0076082E
		//-- y --
		lolo.bClipInf = /*lolo.bp_120*/D_00E38938[lolo.bp_04->vect0].y < lolo.fScreenCenter;
		lolo.bClipSup = /*lolo.bp_124*/lolo.fScreenCenter < D_00E38938[lolo.bp_04->vect0].y;

		lolo.bClipInf2 = /*lolo.bp_128*/D_00E38938[lolo.bp_04->vect1].y < lolo.fScreenCenter;
		lolo.bClipSup2 = /*lolo.bp_12c*/lolo.fScreenCenter < D_00E38938[lolo.bp_04->vect1].y;
		lolo.bClipInf |= lolo.bClipInf2;
		lolo.bClipSup |= lolo.bClipSup2;

		lolo.bClipInf2 = /*lolo.bp_130*/D_00E38938[lolo.bp_04->vect2].y < lolo.fScreenCenter;
		lolo.bClipSup2 = /*lolo.bp_134*/lolo.fScreenCenter < D_00E38938[lolo.bp_04->vect2].y;
		lolo.bClipInf |= lolo.bClipInf2;
		lolo.bClipSup |= lolo.bClipSup2;

		lolo.bClipInf &= lolo.bClipSup;
		if(!lolo.bClipInf)
			goto occlusion_end;//0075FD4D through 00760829
		//-- center of screen is occluded, set flag --
		D_00E37520 = 1;
occlusion_end://0075FD4D:
		//-- --
		if(
			C_0075F090(D_00E38F38[lolo.bp_04->vect0].w) > 0 &&//wm:float to int
			C_0075F090(D_00E38F38[lolo.bp_04->vect1].w) > 0 &&//wm:float to int
			C_0075F090(D_00E38F38[lolo.bp_04->vect2].w) > 0//wm:float to int
		) {//else 007607FA
			//-- undersea palette "fog" --
			lolo.dwPal_j = 0;
			if(D_00E37524 == 0)
				goto palette_fog_end;//00760243 through 00760824
			C_00760D1B(
				&(D_00E38938[lolo.bp_04->vect0].z),
				&(D_00E38938[lolo.bp_04->vect1].z),
				&(D_00E38938[lolo.bp_04->vect2].z),
				&lolo.dwInd0,
				&lolo.dwInd1,
				&lolo.dwInd2
			);//Z-sort indexes

			lolo.bp_20[lolo.dwInd0].bgra = D_00E2B778[0].bgra;
			lolo.bp_20[lolo.dwInd1].bgra = D_00E2B778[4].bgra;
			lolo.bp_20[lolo.dwInd2].bgra = D_00E2B778[8].bgra;

			lolo.bp_c8[lolo.dwInd0].r = D_00E28F40[0].r;
			lolo.bp_c8[lolo.dwInd1].r = D_00E28F40[4].r;
			lolo.bp_c8[lolo.dwInd2].r = D_00E28F40[8].r;
			lolo.bp_c8[lolo.dwInd0].g = D_00E28F40[0].g;
			lolo.bp_c8[lolo.dwInd1].g = D_00E28F40[4].g;
			lolo.bp_c8[lolo.dwInd2].g = D_00E28F40[8].g;
			lolo.bp_c8[lolo.dwInd0].b = D_00E28F40[0].b;
			lolo.bp_c8[lolo.dwInd1].b = D_00E28F40[4].b;
			lolo.bp_c8[lolo.dwInd2].b = D_00E28F40[8].b;
			lolo.bp_c8[0].a =
			lolo.bp_c8[1].a =
			lolo.bp_c8[2].a = 255.0f;
//0075FF0E
			lolo.dwDiffZ = C_0075F090(lolo.fTriangleZ) - D_00E37524;//wm:float to int
			if(lolo.dwDiffZ <= 0)
				goto palette_fog_end;//00760243 through 0076081F
			lolo.dwDiffZ = (unsigned)lolo.dwDiffZ >> 3;
			lolo.dwDiffZ &= 0xffc0;
			lolo.dwPal_j = lolo.dwDiffZ;
			lolo.dwPal_i = (lolo.dwPal_j + 0x40) >> 2;

			lolo.bp_20[lolo.dwInd0].bgra = D_00E2B778[lolo.dwPal_i - 8].bgra;
			lolo.bp_20[lolo.dwInd1].bgra = D_00E2B778[lolo.dwPal_i - 4].bgra;
			lolo.bp_20[lolo.dwInd2].bgra = D_00E2B778[lolo.dwPal_i - 0].bgra;

			lolo.bp_c8[lolo.dwInd0].b = D_00E28F40[lolo.dwPal_i - 8].b;
			lolo.bp_c8[lolo.dwInd0].g = D_00E28F40[lolo.dwPal_i - 4].g;
			lolo.bp_c8[lolo.dwInd0].r = D_00E28F40[lolo.dwPal_i - 0].r;
			lolo.bp_c8[lolo.dwInd0].a = 255.0f;

			lolo.bp_c8[lolo.dwInd1].b = D_00E28F40[lolo.dwPal_i - 8].b;
			lolo.bp_c8[lolo.dwInd1].g = D_00E28F40[lolo.dwPal_i - 4].g;
			lolo.bp_c8[lolo.dwInd1].r = D_00E28F40[lolo.dwPal_i - 0].r;
			lolo.bp_c8[lolo.dwInd1].a = 255.0f;

			lolo.bp_c8[lolo.dwInd2].b = D_00E28F40[lolo.dwPal_i - 8].b;
			lolo.bp_c8[lolo.dwInd2].g = D_00E28F40[lolo.dwPal_i - 4].g;
			lolo.bp_c8[lolo.dwInd2].r = D_00E28F40[lolo.dwPal_i - 0].r;
			lolo.bp_c8[lolo.dwInd2].a = 255.0f;

			lolo.dwDiffZ -= 0x3c0;
			if(lolo.dwDiffZ <= 0)
				goto palette_fog_end;//00760243 through 0076081A
			lolo.dwPal_j = 0xff;

			lolo.bp_20[lolo.dwInd0].bgra = D_00E2B778[lolo.dwPal_j - 8].bgra;
			lolo.bp_20[lolo.dwInd1].bgra = D_00E2B778[lolo.dwPal_j - 4].bgra;
			lolo.bp_20[lolo.dwInd2].bgra = D_00E2B778[lolo.dwPal_j - 0].bgra;

			lolo.bp_c8[lolo.dwInd0].b = D_00E28F40[lolo.dwPal_j - 8].b;
			lolo.bp_c8[lolo.dwInd0].g = D_00E28F40[lolo.dwPal_j - 4].g;
			lolo.bp_c8[lolo.dwInd0].r = D_00E28F40[lolo.dwPal_j - 0].r;
			lolo.bp_c8[lolo.dwInd0].a = 255.0f;

			lolo.bp_c8[lolo.dwInd1].b = D_00E28F40[lolo.dwPal_j - 8].b;
			lolo.bp_c8[lolo.dwInd1].g = D_00E28F40[lolo.dwPal_j - 4].g;
			lolo.bp_c8[lolo.dwInd1].r = D_00E28F40[lolo.dwPal_j - 0].r;
			lolo.bp_c8[lolo.dwInd1].a = 255.0f;

			lolo.bp_c8[lolo.dwInd2].b = D_00E28F40[lolo.dwPal_j - 8].b;
			lolo.bp_c8[lolo.dwInd2].g = D_00E28F40[lolo.dwPal_j - 4].g;
			lolo.bp_c8[lolo.dwInd2].r = D_00E28F40[lolo.dwPal_j - 0].r;
			lolo.bp_c8[lolo.dwInd2].a = 255.0f;
palette_fog_end://00760243
			//-- --
			lolo.bp_14 = (int *)&(lolo.bp_04->u2);
			lolo.dwTex = *lolo.bp_14;
			lolo.dwTex >>= 14;
			lolo.dwTex &= 0x7fc;//9bits
			lolo.dwTex >>= 2;
			if(C_0074C969()) {//wm:get "isRendering"?//else 007607FA
				//====---- terrain triangle rendering? ----====
				if(C_0066E272(1, D_00E2BBD8[lolo.dwTex])) {//else 007607FA
					lolo.fU0 = (float)/*lolo.bp_138*/(lolo.bp_04->u0 - D_00E2D168[lolo.dwTex].u) * D_00E2BBD8[lolo.dwTex]->f_24;
					lolo.fV0 = (float)/*lolo.bp_13c*/(lolo.bp_04->v0 - D_00E2D168[lolo.dwTex].v) * D_00E2BBD8[lolo.dwTex]->f_28;

					lolo.fU1 = (float)/*lolo.bp_140*/(lolo.bp_04->u1 - D_00E2D168[lolo.dwTex].u) * D_00E2BBD8[lolo.dwTex]->f_24;
					lolo.fV1 = (float)/*lolo.bp_144*/(lolo.bp_04->v1 - D_00E2D168[lolo.dwTex].v) * D_00E2BBD8[lolo.dwTex]->f_28;

					lolo.fU2 = (float)/*lolo.bp_148*/(lolo.bp_04->u2 - D_00E2D168[lolo.dwTex].u) * D_00E2BBD8[lolo.dwTex]->f_24;
					lolo.fV2 = (float)/*lolo.bp_14c*/(lolo.bp_04->v2 - D_00E2D168[lolo.dwTex].v) * D_00E2BBD8[lolo.dwTex]->f_28;

					lolo.sNormalF0.x = (float)/*lolo.bp_150*/lolo.pNormal0->vx * (1.0f/4096.0f);
					lolo.sNormalF0.y = (float)/*lolo.bp_154*/lolo.pNormal0->vy * (1.0f/4096.0f);
					lolo.sNormalF0.z = (float)/*lolo.bp_158*/lolo.pNormal0->vz * (1.0f/4096.0f);

					lolo.sNormalF1.x = (float)/*lolo.bp_15c*/lolo.pNormal1->vx * (1.0f/4096.0f);
					lolo.sNormalF1.y = (float)/*lolo.bp_160*/lolo.pNormal1->vy * (1.0f/4096.0f);
					lolo.sNormalF1.z = (float)/*lolo.bp_164*/lolo.pNormal1->vz * (1.0f/4096.0f);

					lolo.sNormalF2.x = (float)/*lolo.bp_168*/lolo.pNormal2->vx * (1.0f/4096.0f);
					lolo.sNormalF2.y = (float)/*lolo.bp_16c*/lolo.pNormal2->vy * (1.0f/4096.0f);
					lolo.sNormalF2.z = (float)/*lolo.bp_170*/lolo.pNormal2->vz * (1.0f/4096.0f);

					C_0068DAE1(&(D_00E360F4->f_0f8), &lolo.sNormalF0, &(lolo.bp_c8[0]), &(lolo.bp_20[0]), &lolo.vcolor_0);//compute light at vertex(no flag)
					C_0068DAE1(&(D_00E360F4->f_0f8), &lolo.sNormalF1, &(lolo.bp_c8[1]), &(lolo.bp_20[1]), &lolo.vcolor_1);//compute light at vertex(no flag)
					C_0068DAE1(&(D_00E360F4->f_0f8), &lolo.sNormalF2, &(lolo.bp_c8[2]), &(lolo.bp_20[2]), &lolo.vcolor_2);//compute light at vertex(no flag)

					lolo.fRHW0 = 1.0f / D_00E38F38[lolo.bp_04->vect0].w;
					MK_VERTEX_0(&(D_00E2BBD8[lolo.dwTex]->f_70.asVertex[0]), lolo.bp_ec, D_00E38F38[lolo.bp_04->vect0].x * lolo.fRHW0, D_00E38F38[lolo.bp_04->vect0].y * lolo.fRHW0, D_00E38F38[lolo.bp_04->vect0].z * lolo.fRHW0, lolo.fRHW0, lolo.vcolor_0.bgra, lolo.fU0, lolo.fV0);
					lolo.fRHW1 = 1.0f / D_00E38F38[lolo.bp_04->vect1].w;
					MK_VERTEX_0(&(D_00E2BBD8[lolo.dwTex]->f_70.asVertex[1]), lolo.bp_f4, D_00E38F38[lolo.bp_04->vect1].x * lolo.fRHW1, D_00E38F38[lolo.bp_04->vect1].y * lolo.fRHW1, D_00E38F38[lolo.bp_04->vect1].z * lolo.fRHW1, lolo.fRHW1, lolo.vcolor_1.bgra, lolo.fU1, lolo.fV1);
					lolo.fRHW2 = 1.0f / D_00E38F38[lolo.bp_04->vect2].w;
					MK_VERTEX_0(&(D_00E2BBD8[lolo.dwTex]->f_70.asVertex[2]), lolo.bp_fc, D_00E38F38[lolo.bp_04->vect2].x * lolo.fRHW2, D_00E38F38[lolo.bp_04->vect2].y * lolo.fRHW2, D_00E38F38[lolo.bp_04->vect2].z * lolo.fRHW2, lolo.fRHW2, lolo.vcolor_2.bgra, lolo.fU2, lolo.fV2);
				}
			}
		}
//007607FA
		//-- --
		bp14_unused ++;
		//-- --
next_triangle://00760803
		lolo.bp_04 ++;
	} while(lolo.bp_04 != bp0c);
}

void C_00760C64(LPD3DVECTOR, LPD3DVECTOR, LPD3DVECTOR);//cross product?

int C_0076085F(struct t_wm_TerrainTriangle *bp08, struct SVECTOR *bp0c, int *bp10) {
	struct {
		//local_17 and above for compiler
		D3DVECTOR sVect1;//local_16
		float local_13;
		float fSqZ;//local_12
		float fSqX;//local_11
		float fSqSum;//local_10
		D3DVECTOR sVectR;//local_9
		D3DVECTOR sVectO;//local_6
		D3DVECTOR sVect2;//local_3
	}lolo;

	lolo.sVectO.x = /*lolo.local_17*/(float)bp0c->vx;
	lolo.sVectO.y = /*lolo.local_18*/(float)bp0c->vy;
	lolo.sVectO.z = /*lolo.local_19*/(float)bp0c->vz;

	lolo.sVect1.y =
	lolo.sVect2.y = 0;
	//-- edge 0-1 --
	lolo.sVect1.x = D_00E38338[bp08->vect1].x - D_00E38338[bp08->vect0].x;
	lolo.sVect1.z = D_00E38338[bp08->vect1].z - D_00E38338[bp08->vect0].z;
	lolo.sVect2.z = lolo.sVectO.z - D_00E38338[bp08->vect0].z;
	lolo.sVect2.x = lolo.sVectO.x - D_00E38338[bp08->vect0].x;
	lolo.sVectR.y = lolo.sVect1.z * lolo.sVect2.x - lolo.sVect1.x * lolo.sVect2.z;
	if(C_0075F090(lolo.sVectR.y) > 0)//wm:float to int
		goto C_00760C52;//00760C5E
	//-- edge 1-2 --
	lolo.sVect1.x = D_00E38338[bp08->vect2].x - D_00E38338[bp08->vect1].x;
	lolo.sVect1.z = D_00E38338[bp08->vect2].z - D_00E38338[bp08->vect1].z;
	lolo.sVect2.z = lolo.sVectO.z - D_00E38338[bp08->vect1].z;
	lolo.sVect2.x = lolo.sVectO.x - D_00E38338[bp08->vect1].x;
	lolo.sVectR.y = lolo.sVect1.z * lolo.sVect2.x - lolo.sVect1.x * lolo.sVect2.z;
	if(C_0075F090(lolo.sVectR.y) > 0)//wm:float to int
		goto C_00760C52;//00760C5C
	//-- edge 2-0 --
	lolo.sVect1.x = D_00E38338[bp08->vect0].x - D_00E38338[bp08->vect2].x;
	lolo.sVect1.z = D_00E38338[bp08->vect0].z - D_00E38338[bp08->vect2].z;
	lolo.sVect2.z = lolo.sVectO.z - D_00E38338[bp08->vect2].z;
	lolo.sVect2.x = lolo.sVectO.x - D_00E38338[bp08->vect2].x;
	lolo.sVectR.y = lolo.sVect1.z * lolo.sVect2.x - lolo.sVect1.x * lolo.sVect2.z;
	if(C_0075F090(lolo.sVectR.y) > 0)//wm:float to int
		goto C_00760C52;//00760C5A
	//-- inside triangle->compute height? --
	lolo.sVect1.x = D_00E38338[bp08->vect1].x - D_00E38338[bp08->vect0].x;
	lolo.sVect1.y = D_00E38338[bp08->vect1].y - D_00E38338[bp08->vect0].y;
	lolo.sVect2.x = D_00E38338[bp08->vect2].x - D_00E38338[bp08->vect0].x;
	lolo.sVect2.y = D_00E38338[bp08->vect2].y - D_00E38338[bp08->vect0].y;
	lolo.sVect1.z = D_00E38338[bp08->vect1].z - D_00E38338[bp08->vect0].z;
	lolo.sVect2.z = D_00E38338[bp08->vect2].z - D_00E38338[bp08->vect0].z;
	C_00760C64(&lolo.sVect1, &lolo.sVect2, &lolo.sVectR);//cross product?
	lolo.sVectR.y *= 1.0f/256.0f;
	if(C_0075F090(lolo.sVectR.y) == 0)//wm:float to int
		goto C_00760BFC;//00760C58

	lolo.fSqSum = lolo.sVectR.y * D_00E38338[bp08->vect0].y;

	lolo.sVectR.x *= 1.0f/256.0f;
	lolo.fSqX = D_00E38338[bp08->vect0].x - lolo.sVectO.x;
	lolo.fSqX *= lolo.sVectR.x;

	lolo.sVectR.z *= 1.0f/256.0f;
	lolo.fSqZ = D_00E38338[bp08->vect0].z - lolo.sVectO.z;
	lolo.fSqZ *= lolo.sVectR.z;

	lolo.fSqSum += lolo.fSqX + lolo.fSqZ;
	lolo.local_13 = lolo.fSqSum / lolo.sVectR.y;
	goto C_00760C3A;//00760C56
C_00760BFC:
	lolo.fSqSum = D_00E38338[bp08->vect0].y + D_00E38338[bp08->vect1].y + D_00E38338[bp08->vect2].y;
	lolo.local_13 = lolo.fSqSum * (1.0f/3.0f);

C_00760C3A:
	*bp10 = C_0075F090(lolo.local_13);//wm:float to int
	return 1;
	//-- outside triangle --
C_00760C52:
	return 0;
}

//cross product?
void C_00760C64(LPD3DVECTOR bp08, LPD3DVECTOR bp0c, LPD3DVECTOR bp10) {
	bp10->x = bp08->y * bp0c->z - bp08->z * bp0c->y;
	bp10->y = bp08->z * bp0c->x - bp08->x * bp0c->z;
	bp10->z = bp08->x * bp0c->y - bp08->y * bp0c->x;
}

/*(looks like 3 vector determinant with z forced to 1)
	|bp08->f_00 bp0c->f_00 bp10->f_00|
	|bp08->f_04 bp0c->f_04 bp10->f_04|
	|         1          1          1|
*/
float C_00760CC4(LPD3DVECTOR bp08, LPD3DVECTOR bp0c, LPD3DVECTOR bp10) {
	float local_1 =
		  bp08->x * bp0c->y + bp0c->x * bp10->y + bp10->x * bp08->y
		- bp08->x * bp10->y - bp0c->x * bp08->y - bp10->x * bp0c->y
	;

	return local_1;
}

//Z-sort indexes
void C_00760D1B(
	float *pfZ0/*bp08*/,
	float *pfZ1/*bp0c*/,
	float *pfZ2/*bp10*/,
	int *pInd0/*bp14*/,
	int *pInd1/*bp18*/,
	int *pInd2/*bp1c*/
) {
	struct {
		int local_5;
		float local_4[3];
		int local_1;
	}lolo;

	lolo.local_4[0] = *pfZ0;
	lolo.local_4[1] = *pfZ1;
	lolo.local_4[2] = *pfZ2;

	lolo.local_5 = /*lolo.local_6*/lolo.local_4[0] < lolo.local_4[1]?1:0;
	lolo.local_1 = /*lolo.local_7*/lolo.local_4[lolo.local_5] < lolo.local_4[2]?2:lolo.local_5;
	if(lolo.local_1 != 0) {//else 00760DDD
		*pInd2 = lolo.local_1;
		if(lolo.local_1 == 1)
			lolo.local_5 = 2;
		else
			lolo.local_5 = 1;
		if(lolo.local_4[0] < lolo.local_4[lolo.local_5]) {
			*pInd0 = 0;
			*pInd1 = lolo.local_5;
		} else {
			*pInd0 = lolo.local_5;
			*pInd1 = 0;
		}
	} else {
		*pInd2 = 0;
		if(lolo.local_4[1] < lolo.local_4[2]) {
			*pInd0 = 1;
			*pInd1 = 2;
		} else {
			*pInd0 = 2;
			*pInd1 = 1;
		}
	}
}

//wm:adjust terrain triangle u,v?
void C_00760E1D(struct t_wm_TerrainTriangle *bp08, struct t_wm_TerrainTriangle *bp0c, int bp10) {
	struct {
		int dwAvgV;//local_3
		int dwAvgU;//local_2
		struct t_wm_TerrainTriangle *local_1;
	}lolo;

	lolo.local_1 = bp08;
	while(lolo.local_1 != bp0c) {
		lolo.dwAvgU = (lolo.local_1->u0 + lolo.local_1->u1 + lolo.local_1->u2) / 3;
		lolo.dwAvgV = (lolo.local_1->v0 + lolo.local_1->v1 + lolo.local_1->v2) / 3;
		//-- adjust U --
		if(lolo.dwAvgU < lolo.local_1->u0)
			lolo.local_1->u0 -= bp10;
		else
			lolo.local_1->u0 += bp10;
		if(lolo.dwAvgU < lolo.local_1->u1)
			lolo.local_1->u1 -= bp10;
		else
			lolo.local_1->u1 += bp10;
		if(lolo.dwAvgU < lolo.local_1->u2)
			lolo.local_1->u2 -= bp10;
		else
			lolo.local_1->u2 += bp10;
		//-- adjust V --
		if(lolo.dwAvgV < lolo.local_1->v0)
			lolo.local_1->v0 -= bp10;
		else
			lolo.local_1->v0 += bp10;
		if(lolo.dwAvgV < lolo.local_1->v1)
			lolo.local_1->v1 -= bp10;
		else
			lolo.local_1->v1 += bp10;
		if(lolo.dwAvgV < lolo.local_1->v2)
			lolo.local_1->v2 -= bp10;
		else
			lolo.local_1->v2 += bp10;
		//-- --
		lolo.local_1 ++;
	}//end while
}
