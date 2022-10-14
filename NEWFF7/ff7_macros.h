/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
#ifndef __FF7_MACROS_H__
#define __FF7_MACROS_H__

//====---- ----====
#define BIT(a) ((unsigned)(1L<<(a)))
//====---- ----====
#define ALIGN(base, algn) (((unsigned)(base) + (algn) - 1) & ~((algn) - 1))
//====---- ----====
#define RELEASE(x) if(x) { (x)->Release(); (x) = 0; }
//====---- ----====
#define FKMB(t, p, o) (*(t *)((char *)p + o))
//====---- ----====
#define SWAP(a,b,t) ((t) = (a),(a) = (b), (b) = (t))
//====---- ----====
//fast float to integer conversion
#define fFloat2Int(d, s) __asm FLD s __asm FISTP d
//====---- ----====
#define FIX_DIV(a,b) (((a)<<0xc)/(b))
#define FIX_MUL(a,b) (((a)*(b))>>0xc)
////////////////////////////////////////
#define MK_VERTEX_0(p, vx, x, y, z, rhw, col, tx, ty) \
			vx = p; \
			vx->f_00 = x; \
			vx->f_04 = y; \
			vx->f_08 = z; \
			vx->f_0c = rhw; \
			vx->f_10.rgba = col; \
			vx->f_18 = tx; \
			vx->f_1c = ty;

#define MK_VERTEX(p, vx, x, y, z, rhw, col, sp, tx, ty) \
			vx = p; \
			vx->f_00 = x; \
			vx->f_04 = y; \
			vx->f_08 = z; \
			vx->f_0c = rhw; \
			vx->f_10.rgba = col; \
			vx->f_14 = sp; \
			vx->f_18 = tx; \
			vx->f_1c = ty;

#define MK_VERTEX_NOTEXTURE_0(p, vx, x, y, z, col) \
			vx = p; \
			vx->f_00 = x; \
			vx->f_04 = y; \
			vx->f_08 = z; \
			vx->f_10.rgba = col;

#define MK_VERTEX_NOTEXTURE_1(p, vx, x, y, z, rhw, col) \
			vx = p; \
			vx->f_00 = x; \
			vx->f_04 = y; \
			vx->f_08 = z; \
			vx->f_0c = rhw; \
			vx->f_10.rgba = col;

#define MK_VERTEX_NOTEXTURE(p, vx, x, y, z, rhw, col, sp) \
			vx = p; \
			vx->f_00 = x; \
			vx->f_04 = y; \
			vx->f_08 = z; \
			vx->f_0c = rhw; \
			vx->f_10.rgba = col; \
			vx->f_14 = sp;

#define MK_QUAD_2D_NOTEXTURE(p, vx, x, y, w, h, z, rhw, col, sp)     \
	MK_VERTEX_NOTEXTURE(p,     vx[3], x,     y,     z, rhw, col, sp) \
	MK_VERTEX_NOTEXTURE(p + 1, vx[2], x,     y + h, z, rhw, col, sp) \
	MK_VERTEX_NOTEXTURE(p + 2, vx[1], x + w, y,     z, rhw, col, sp) \
	MK_VERTEX_NOTEXTURE(p + 3, vx[0], x + w, y + h, z, rhw, col, sp)

#define MK_QUAD_2D(p, vx, x, y, w, h, z, rhw, col, sp, tx, ty, tw, th)       \
	MK_VERTEX(p,     vx[3], x,     y,     z, rhw, col, sp, tx,      ty     ) \
	MK_VERTEX(p + 1, vx[2], x,     y + h, z, rhw, col, sp, tx,      ty + th) \
	MK_VERTEX(p + 2, vx[1], x + w, y,     z, rhw, col, sp, tx + tw, ty     ) \
	MK_VERTEX(p + 3, vx[0], x + w, y + h, z, rhw, col, sp, tx + tw, ty + th)
////////////////////////////////////////
#define DX_DRAWPRIMITIVE_BIS(hr, lpd3dd2, pt, vtd, lpvt, vtcnt, flgs, app_ignored) \
	do { \
		hr = lpd3dd2->DrawPrimitive(pt, vtd, lpvt, vtcnt, flgs); \
		switch(hr) { \
			case D3D_OK: break; \
			case DDERR_WASSTILLDRAWING: /*C_006A479C(1, app); */break; \
			default: \
				C_00664C09(hr, __FILE__, __LINE__); \
				hr = D3D_OK; \
		} \
	} while(hr != D3D_OK);
////////////////////////////////////////
#define DX_DRAWPRIMITIVE(hr, lpd3dd2, pt, vtd, lpvt, vtcnt, flgs, app) \
	do { \
		hr = lpd3dd2->DrawPrimitive(pt, vtd, lpvt, vtcnt, flgs); \
		switch(hr) { \
			case D3D_OK: break; \
			case DDERR_WASSTILLDRAWING: C_006A479C(1, app); break; \
			default: \
				C_00664C09(hr, __FILE__, __LINE__); \
				hr = D3D_OK; \
		} \
	} while(hr != D3D_OK);
////////////////////////////////////////
#define DX_DRAWINDEXEDPRIMITIVE(hr, lpd3dd2, pt, vtd, lpvt, vtcnt, lpind, indcnt, flgs, app) \
	do { \
		hr = lpd3dd2->DrawIndexedPrimitive(pt, vtd, lpvt, vtcnt, lpind, indcnt, flgs); \
		switch(hr) { \
			case D3D_OK: break; \
			case DDERR_WASSTILLDRAWING: C_006A479C(1, app); break; \
			default: \
				C_00664C09(hr, __FILE__, __LINE__); \
				hr = D3D_OK; \
		} \
	} while(hr != D3D_OK);
////////////////////////////////////////
#define DX_DRAWINDEXEDPRIMITIVE_BIS(hr, lpd3dd2, pt, vtd, lpvt, vtcnt, lpind, indcnt, flgs, app) \
	do { \
		hr = lpd3dd2->DrawIndexedPrimitive(pt, vtd, lpvt, vtcnt, lpind, indcnt, flgs); \
		if(hr == D3D_OK) \
			break; \
		if(hr == DDERR_WASSTILLDRAWING) { \
			C_006A479C(1, app); \
		} else { \
			C_00664C09(hr, __FILE__, __LINE__); \
			hr = D3D_OK; \
		} \
	} while(hr != D3D_OK);
////////////////////////////////////////

#endif
