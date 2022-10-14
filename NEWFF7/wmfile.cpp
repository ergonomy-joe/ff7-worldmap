/*
	Final Fantasy VII
	(c) 1997 Square
	decompiled by ergonomy_joe in 2018
*/
#define __FF7FILE__ "C:\\FF7\\src\\wm\\wmfile.cpp"

#include "ff7.h"
#include "wm_data.h"
////////////////////////////////////////
struct t_wmfile_14 {//size 0x14
	/*00*/const char *f_00;
	/*04*/const char *f_04;
	/*08*/unsigned char bAnimationCount;
	/*09*/char __09[3];
	/*0c*/unsigned f_0c;
	/*10*/const char **f_10;
};
////////////////////////////////////////
struct t_wmfile_14 *D_00E2BBD0;
int D_00E2BBD4;
struct t_dx_sfx_e0 *D_00E2BBD8[0x200];//check
struct t_dx_sfx_e0 *D_00E2C3D8;
struct t_dx_sfx_e0 *D_00E2C3DC;
struct t_dx_sfx_e0 *D_00E2C3E0;
struct t_dx_sfx_e0 *D_00E2C3E4;
struct t_dx_sfx_e0 *D_00E2C3E8;
struct t_dx_sfx_e0 *D_00E2C3EC;
struct t_dx_sfx_e0 *D_00E2C3F0;
struct t_dx_sfx_e0 *D_00E2C3F4[3];
struct t_dx_sfx_e0 *D_00E2C400;
struct t_dx_sfx_e0 *D_00E2C404;
struct t_dx_sfx_e0 *D_00E2C408;
struct t_dx_sfx_e0 *D_00E2C40C;
struct t_dx_sfx_e0 *D_00E2C410;
struct t_dx_sfx_e0 *D_00E2C414;
//00E2C418
int D_00E2C41C;
int D_00E2C420;//current number of textures[terrain]
int D_00E2C424;//viewport x
int D_00E2C428;//viewport y
//00E2C42C
struct t_wm_b8 D_00E2C430[3];
struct t_dx_sfx_e0 *D_00E2C658[0x6c];
struct t_wm_b8 D_00E2C808[0xd];
struct t_wmfile_14 *D_00E2D160;
int D_00E2D164;
struct t_wm_file_04 *D_00E2D168;//check
//00E2D16C ""
//...
//00E2D1D8 ""
//00E2D1DC
////////////////////////////////////////
//-- surface --
const char *D_00969CE8[0x11a] = {
	/*0096B474*/"pond.tim",
	/*0096B480*/"riv_m2.tim",
	/*0096B48C*/"was_gs.tim",
	/*0096B498*/"wpcltr.tim",
	/*0096B4A4*/"wpcltr2.tim",
	/*0096B4B0*/"bzdun.tim",
	/*0096B4BC*/"bone.tim",
	/*0096B4C8*/"bone2.tim",
	/*0096B4D4*/"bornwd.tim",
	/*0096B4E0*/"bridge.tim",
	/*0096B4EC*/"bridge2.tim",
	/*0096B4F8*/"cave.tim",
	/*0096B504*/"cave2.tim",
	/*0096B510*/"cave_s.tim",
	/*0096B51C*/"cdl_cl2.tim",
	/*0096B528*/"cf01.tim",
	/*0096B534*/"clf_bgs.tim",
	/*0096B540*/"clf_ggl.tim",
	/*0096B54C*/"clf_ggs.tim",
	/*0096B558*/"clf_l.tim",
	/*0096B564*/"clf_ld.tim",
	/*0096B570*/"clf_lf.tim",
	/*0096B57C*/"clf_lg.tim",
	/*0096B588*/"clf_lr.tim",
	/*0096B594*/"clf_lsg.tim",
	/*0096B5A0*/"clf_r.tim",
	/*0096B5AC*/"clf_s.tim",
	/*0096B5B8*/"clf_sd.tim",
	/*0096B5C4*/"clf_sf.tim",
	/*0096B5D0*/"clf_sg.tim",
	/*0096B5DC*/"clf_sg2.tim",
	/*0096B5E8*/"clf_sr.tim",
	/*0096B5F4*/"clf_ss.tim",
	/*0096B600*/"clf_ssd.tim",
	/*0096B60C*/"clf_ssw.tim",
	/*0096B618*/"clf_sw.tim",
	/*0096B624*/"clf_w02.tim",
	/*0096B630*/"clf_w03.tim",
	/*0096B63C*/"clf_was.tim",
	/*0096B648*/"clfeg.tim",
	/*0096B654*/"clfegd.tim",
	/*0096B660*/"clftop.tim",
	/*0096B66C*/"clftop2.tim",
	/*0096B678*/"cndl_cl.tim",
	/*0096B684*/"cndlf.tim",
	/*0096B690*/"cndlf02.tim",
	/*0096B69C*/"comtr.tim",
	/*0096B6A8*/"cosinn.tim",
	/*0096B6B4*/"cosinn2.tim",
	/*0096B6C0*/"csmk.tim",
	/*0096B6CC*/"csmk2.tim",
	/*0096B6D8*/"cstds01.tim",
	/*0096B6E4*/"cstds02.tim",
	/*00E2D16C*/"",
	/*0096B6F0*/"desert.tim",
	/*0096B6FC*/"desor.tim",
	/*00E2D170*/"",
	/*00E2D174*/"",
	/*00E2D178*/"",
	/*0096B708*/"dsrt_d.tim",
	/*0096B714*/"dsrt_e.tim",
	/*00E2D17C*/"",
	/*0096B720*/"elm01.tim",
	/*0096B72C*/"elm02.tim",
	/*0096B738*/"elm_gro.tim",
	/*0096B744*/"elm_r.tim",
	/*0096B750*/"elm_r2.tim",
	/*00E2D180*/"",
	/*0096B75C*/"farm01.tim",
	/*0096B768*/"farm02.tim",
	/*0096B774*/"farm_g.tim",
	/*0096B780*/"farm_r.tim",
	/*0096B78C*/"fld.tim",
	/*0096B794*/"fld_02.tim",
	/*0096B7A0*/"fld_s.tim",
	/*0096B7AC*/"fld_s2.tim",
	/*0096B7B8*/"fld_sw.tim",
	/*0096B7C4*/"fld_v.tim",
	/*0096B7D0*/"fld_vd.tim",
	/*0096B7DC*/"fld_vd2.tim",
	/*0096B7E8*/"fvedge.tim",
	/*0096B7F4*/"gclf_d.tim",
	/*0096B800*/"gclf_g.tim",
	/*0096B80C*/"gclfwa.tim",
	/*0096B818*/"gclfwa2.tim",
	/*0096B824*/"gclfwag.tim",
	/*0096B830*/"gg_gro.tim",
	/*0096B83C*/"gg_mts.tim",
	/*0096B848*/"ggmk.tim",
	/*0096B854*/"ggmt.tim",
	/*0096B860*/"ggmt_e.tim",
	/*0096B86C*/"ggmt_ed.tim",
	/*0096B878*/"ggmt_eg.tim",
	/*0096B884*/"ggmtd.tim",
	/*0096B890*/"ggs_g.tim",
	/*0096B89C*/"ggshr.tim",
	/*0096B8A8*/"ggshrg.tim",
	/*0096B8B4*/"gia.tim",
	/*0096B8BC*/"gia2.tim",
	/*0096B8C8*/"gia_d.tim",
	/*0096B8D4*/"gia_d2.tim",
	/*0096B8E0*/"gia_g.tim",
	/*0096B8EC*/"gia_g2.tim",
	/*0096B8F8*/"gmt_eda.tim",
	/*0096B904*/"gonclf.tim",
	/*0096B910*/"gredge.tim",
	/*0096B91C*/"hyouga.tim",
	/*0096B928*/"iceclf.tim",
	/*0096B934*/"iceclfd.tim",
	/*0096B940*/"iceclfg.tim",
	/*0096B94C*/"jun.tim",
	/*0096B954*/"jun_d.tim",
	/*0096B960*/"jun_e.tim",
	/*0096B96C*/"jun_gro.tim",
	/*0096B978*/"junmk.tim",
	/*0096B984*/"junn01.tim",
	/*0096B990*/"junn02.tim",
	/*0096B99C*/"junn03.tim",
	/*0096B9A8*/"junn04.tim",
	/*0096B9B4*/"jutmpl01.tim",
	/*0096B9C4*/"lake-e.tim",
	/*0096B9D0*/"lake_ef.tim",
	/*0096B9DC*/"lake_fl.tim",
	/*0096B9E8*/"lostclf.tim",
	/*0096B9F4*/"lostmt.tim",
	/*0096BA00*/"lostmtd.tim",
	/*0096BA0C*/"lostmts.tim",
	/*0096BA18*/"lostwd_e.tim",
	/*0096BA28*/"lostwod.tim",
	/*00E2D184*/"",
	/*0096BA34*/"lstwd_e2.tim",
	/*0096BA44*/"mzes.tim",
	/*0096BA50*/"mzmt_e.tim",
	/*0096BA5C*/"mzmt_ed.tim",
	/*0096BA68*/"mzmt_edw.tim",
	/*0096BA78*/"mzmt_ew.tim",
	/*0096BA84*/"mzmt_o.tim",
	/*0096BA90*/"mzmt_od.tim",
	/*0096BA9C*/"mzmt_s.tim",
	/*0096BAA8*/"mzmt_sd.tim",
	/*0096BAB4*/"md01.tim",
	/*0096BAC0*/"md02.tim",
	/*0096BACC*/"md03.tim",
	/*0096BAD8*/"md04.tim",
	/*0096BAE4*/"md05.tim",
	/*0096BAF0*/"md06.tim",
	/*0096BAFC*/"md07.tim",
	/*0096BB08*/"md_mt.tim",
	/*0096BB14*/"md_mtd.tim",
	/*0096BB20*/"md_mts.tim",
	/*0096BB2C*/"md_snow.tim",
	/*0096BB38*/"md_snw2.tim",
	/*0096BB44*/"md_snwd.tim",
	/*0096BB50*/"md_snwe.tim",
	/*0096BB5C*/"md_snws.tim",
	/*0096BB68*/"md_snwt.tim",
	/*0096BB74*/"md_snww.tim",
	/*0096BB80*/"md_sw_s.tim",
	/*0096BB8C*/"md_swd2.tim",
	/*0096BB98*/"md_swnp.tim",
	/*0096BBA4*/"mdsrt_e.tim",
	/*0096BBB0*/"mdsrt_ed.tim",
	/*0096BBC0*/"mdsrt_eg.tim",
	/*0096BBD0*/"midil.tim",
	/*0096BBDC*/"midild.tim",
	/*0096BBE8*/"mt_ewg.tim",
	/*0096BBF4*/"mt_road.tim",
	/*0096BC00*/"mt_se.tim",
	/*0096BC0C*/"mt_se2.tim",
	/*0096BC18*/"mt_sg01.tim",
	/*0096BC24*/"mt_sg02.tim",
	/*0096BC30*/"mt_sg03.tim",
	/*0096BC3C*/"mt_sg04.tim",
	/*0096BC48*/"mtcoin.tim",
	/*0096BC54*/"mtwas_e.tim",
	/*0096BC60*/"mtwas_ed.tim",
	/*0096BC70*/"ncol_gro.tim",
	/*0096BC80*/"ncole01.tim",
	/*0096BC8C*/"ncole02.tim",
	/*0096BC98*/"nivl_gro.tim",
	/*0096BCA8*/"nivl_mt.tim",
	/*0096BCB4*/"nivl_top.tim",
	/*0096BCC4*/"nivlr.tim",
	/*0096BCD0*/"port.tim",
	/*0096BCDC*/"port_d.tim",
	/*0096BCE8*/"rzclf02.tim",
	/*0096BCF4*/"rct_gro.tim",
	/*0096BD00*/"riv_cls.tim",
	/*00E2D188*/"",
	/*0096BD0C*/"riv_m.tim",
	/*0096BD18*/"rivr.tim",
	/*0096BD24*/"rivrclf.tim",
	/*00E2D18C*/"",
	/*0096BD30*/"rivshr.tim",
	/*0096BD3C*/"rivssr.tim",
	/*0096BD48*/"rivstrt.tim",
	/*00E2D190*/"",
	/*0096BD54*/"rocet.tim",
	/*0096BD60*/"rs_ss.tim",
	/*0096BD6C*/"sango.tim",
	/*0096BD78*/"sango2.tim",
	/*0096BD84*/"sango3.tim",
	/*0096BD90*/"sango4.tim",
	/*0096BD9C*/"sdun.tim",
	/*0096BDA8*/"sdun02.tim",
	/*00E2D194*/"",
	/*00E2D198*/"",
	/*0096BDB4*/"shedge.tim",
	/*00E2D19C*/"",
	/*0096BDC0*/"shol.tim",
	/*0096BDCC*/"shol_s.tim",
	/*0096BDD8*/"shor.tim",
	/*0096BDE4*/"shor_s.tim",
	/*0096BDF0*/"shor_s2.tim",
	/*0096BDFC*/"shor_v.tim",
	/*0096BE08*/"silo.tim",
	/*0096BE14*/"slope.tim",
	/*0096BE20*/"snow_es.tim",
	/*0096BE2C*/"snow_es2.tim",
	/*0096BE3C*/"snow_es3.tim",
	/*0096BE4C*/"snw_mt.tim",
	/*0096BE58*/"snw_mtd.tim",
	/*0096BE64*/"snw_mte.tim",
	/*0096BE70*/"snw_mted.tim",
	/*0096BE80*/"snw_mts.tim",
	/*0096BE8C*/"snw_mts2.tim",
	/*0096BE9C*/"snwfld.tim",
	/*0096BEA8*/"snwfld_s.tim",
	/*0096BEB8*/"snwgra.tim",
	/*0096BEC4*/"snwhm01.tim",
	/*0096BED0*/"snwhm02.tim",
	/*0096BEDC*/"snwods.tim",
	/*0096BEE8*/"snwood.tim",
	/*0096BEF4*/"snwtrk.tim",
	/*00E2D1A0*/"",
	/*00E2D1A4*/"",
	/*00E2D1A8*/"",
	/*0096BF00*/"stown_r.tim",
	/*0096BF0C*/"stw_gro.tim",
	/*0096BF18*/"subrg2.tim",
	/*0096BF24*/"susbrg.tim",
	/*0096BF30*/"sw_se.tim",
	/*0096BF3C*/"swclf_l.tim",
	/*0096BF48*/"swclf_ld.tim",
	/*0096BF58*/"swclf_lg.tim",
	/*0096BF68*/"swclf_s.tim",
	/*0096BF74*/"swclf_sd.tim",
	/*0096BF84*/"swclf_sg.tim",
	/*0096BF94*/"swclf_wg.tim",
	/*0096BFA4*/"swfld_s2.tim",
	/*0096BFB4*/"swfld_s3.tim",
	/*0096BFC4*/"swmd_cg.tim",
	/*0096BFD0*/"swmd_clf.tim",
	/*00E2D1AC*/"",
	/*0096BFE0*/"trk.tim",
	/*0096BFE8*/"tyo_f.tim",
	/*0096BFF4*/"tyosnw.tim",
	/*00E2D1B0*/"",
	/*0096C000*/"utai01.tim",
	/*0096C00C*/"utai02.tim",
	/*0096C018*/"utai_gro.tim",
	/*0096C028*/"utaimt.tim",
	/*0096C034*/"utaimtd.tim",
	/*0096C040*/"utaimtg.tim",
	/*00E2D1B4*/"",
	/*00E2D1B8*/"",
	/*0096C04C*/"wzshr.tim",
	/*0096C058*/"wzshr2.tim",
	/*0096C064*/"wzshrs.tim",
	/*0096C070*/"was.tim",
	/*0096C078*/"was_d.tim",
	/*0096C084*/"was_g.tim",
	/*0096C090*/"was_s.tim",
	/*0096C09C*/"wasfld.tim",
	/*0096C0A8*/"wdedge.tim",
	/*00E2D1BC*/"",
	/*00E2D1C0*/"",
	/*0096C0B4*/"wedged.tim",
	/*0096C0C0*/"wod-e2.tim",
	/*0096C0CC*/"wood.tim",
	/*0096C0D8*/"wood_d.tim",
	/*0096C0E4*/"wtrk.tim"
};
//for surface too
const char *D_0096A150[0x6c] = {
	/*0096C0F0*/"wa1.tim",
	/*0096C0F8*/"wa2.tim",
	/*0096C100*/"wa3.tim",
	/*0096C108*/"wa4.tim",
	/*0096C110*/"wa5.tim",
	/*0096C118*/"wa6.tim",
	/*0096C120*/"wa7.tim",
	/*0096C128*/"wa8.tim",
	/*0096C130*/"we1.tim",
	/*0096C138*/"we2.tim",
	/*0096C140*/"we3.tim",
	/*0096C148*/"we4.tim",
	/*0096C150*/"we5.tim",
	/*0096C158*/"we6.tim",
	/*0096C160*/"we7.tim",
	/*0096C168*/"we8.tim",
	/*0096C170*/"wzs1.tim",
	/*0096C17C*/"wzs2.tim",
	/*0096C188*/"wzs3.tim",
	/*0096C194*/"wzs4.tim",
	/*0096C1A0*/"wzs5.tim",
	/*0096C1AC*/"wzs6.tim",
	/*0096C1B8*/"wzs7.tim",
	/*0096C1C4*/"wzs8.tim",
	/*0096C1D0*/"we_s1.tim",
	/*0096C1DC*/"we_s2.tim",
	/*0096C1E8*/"we_s3.tim",
	/*0096C1F4*/"we_s4.tim",
	/*0096C200*/"we_s5.tim",
	/*0096C20C*/"we_s6.tim",
	/*0096C218*/"we_s7.tim",
	/*0096C224*/"we_s8.tim",
	/*0096C230*/"fall1.tim",
	/*0096C23C*/"fall2.tim",
	/*0096C248*/"fall3.tim",
	/*0096C254*/"fall4.tim",
	/*0096C260*/"fall5.tim",
	/*0096C26C*/"fall6.tim",
	/*0096C278*/"fall7.tim",
	/*0096C284*/"fall8.tim",
	/*0096C290*/"uf1.tim",
	/*0096C298*/"uf2.tim",
	/*0096C2A0*/"uf3.tim",
	/*0096C2A8*/"uf4.tim",
	/*0096C2B0*/"lst1.tim",
	/*0096C2BC*/"lst2.tim",
	/*0096C2C8*/"lst3.tim",
	/*0096C2D4*/"lst4.tim",
	/*0096C2E0*/"sst1.tim",
	/*0096C2EC*/"sst2.tim",
	/*0096C2F8*/"sst3.tim",
	/*0096C304*/"sst4.tim",
	/*0096C310*/"rm1.tim",
	/*0096C318*/"rm2.tim",
	/*0096C320*/"rm3.tim",
	/*0096C328*/"rm4.tim",
	/*0096C330*/"ds1.tim",
	/*0096C338*/"ds2.tim",
	/*0096C340*/"ds3.tim",
	/*0096C348*/"ds4.tim",
	/*0096C350*/"sh1.tim",
	/*0096C358*/"sh2.tim",
	/*0096C360*/"sh3.tim",
	/*0096C368*/"sh4.tim",
	/*0096C370*/"ssee1.tim",
	/*0096C37C*/"ssee2.tim",
	/*0096C388*/"ssee3.tim",
	/*0096C394*/"ssee4.tim",
	/*0096C3A0*/"riv_l1.tim",
	/*0096C3AC*/"riv_l2.tim",
	/*0096C3B8*/"riv_l3.tim",
	/*0096C3C4*/"riv_l4.tim",
	/*0096C3D0*/"ds_s1.tim",
	/*0096C3DC*/"ds_s2.tim",
	/*0096C3E8*/"ds_s3.tim",
	/*0096C3F4*/"ds_s4.tim",
	/*0096C400*/"sh_s1.tim",
	/*0096C40C*/"sh_s2.tim",
	/*0096C418*/"sh_s3.tim",
	/*0096C424*/"sh_s4.tim",
	/*0096C430*/"sse_s1.tim",
	/*0096C43C*/"sse_s2.tim",
	/*0096C448*/"sse_s3.tim",
	/*0096C454*/"sse_s4.tim",
	/*0096C460*/"swp1.tim",
	/*0096C46C*/"swp2.tim",
	/*0096C478*/"swp3.tim",
	/*0096C484*/"swp4.tim",
	/*0096C490*/"dsee1.tim",
	/*0096C49C*/"dsee2.tim",
	/*0096C4A8*/"dsee3.tim",
	/*0096C4B4*/"dsee4.tim",
	/*0096C4C0*/"shlm_1.tim",
	/*0096C4CC*/"shlm_2.tim",
	/*0096C4D8*/"shlm_3.tim",
	/*0096C4E4*/"shlm_4.tim",
	/*0096C4F0*/"des01.tim",
	/*0096C4FC*/"des02.tim",
	/*0096C508*/"des03.tim",
	/*0096C514*/"des04.tim",
	/*0096C520*/"edes01.tim",
	/*0096C52C*/"edes02.tim",
	/*0096C538*/"edes03.tim",
	/*0096C544*/"edes04.tim",
	/*0096C550*/"rivs1.tim",
	/*0096C55C*/"rivs2.tim",
	/*0096C568*/"rivs3.tim",
	/*0096C574*/"rivs4.tim"
};
//-- undersea --
const char *D_0096A300[8] = {
	/*0096C580*/"cltr.tim",
	/*0096C58C*/"lake_a.tim",
	/*0096C598*/"rock.tim",
	/*0096C5A4*/"scave.tim",
	/*0096C5B0*/"ssand.tim",
	/*0096C5BC*/"swall02.tim",
	/*0096C5C8*/"sng01.tim",
	/*0096C5D4*/"sng02.tim"
};
//-- snowfield --
const char *D_0096A320[4] = {
	/*0096C5E0*/"hokola01.tim",
	/*0096C5F0*/"hokola02.tim",
	/*0096C600*/"snwfldl.tim",
	/*0096C60C*/"snwfld2.tim"
};
//-- surface --
struct t_wm_file_04 D_0096A330[0x11a] = {
	{0x00,0x160},{0x80,0x040},{0x40,0x0C0},{0x00,0x100},
	{0xA0,0x040},{0xC0,0x0C0},{0xE0,0x180},{0xE0,0x1A0},
	{0xA0,0x140},{0xC0,0x000},{0xE0,0x000},{0xE0,0x1C0},
	{0xE0,0x140},{0xA0,0x0E0},{0x60,0x060},{0xC0,0x120},
	{0xC0,0x180},{0x80,0x100},{0xC0,0x160},{0x00,0x000},
	{0x40,0x000},{0x80,0x000},{0x00,0x060},{0x80,0x000},
	{0x40,0x040},{0x00,0x060},{0xC0,0x000},{0xC0,0x020},
	{0x00,0x040},{0x20,0x060},{0x00,0x0A0},{0x20,0x060},
	{0x20,0x080},{0x00,0x0E0},{0xE0,0x020},{0xC0,0x020},
	{0x80,0x040},{0xC0,0x040},{0x40,0x040},{0xC0,0x140},
	{0x00,0x140},{0xC0,0x040},{0x80,0x040},{0x60,0x080},
	{0xA0,0x040},{0xD0,0x040},{0x90,0x060},{0xE0,0x1A0},
	{0xC0,0x1C0},{0x40,0x040},{0x60,0x040},{0xE0,0x0A0},
	{0x00,0x1C0},{0xA0,0x140},{0x80,0x080},{0xA0,0x040},
	{0x00,0x100},{0xC0,0x120},{0x60,0x120},{0xE0,0x000},
	{0x40,0x080},{0xE0,0x140},{0xA0,0x000},{0x40,0x060},
	{0x00,0x060},{0xC0,0x000},{0xE0,0x000},{0x80,0x100},
	{0xA0,0x020},{0xC0,0x020},{0x80,0x040},{0x80,0x030},
	{0x40,0x060},{0x00,0x040},{0x00,0x0A0},{0xE0,0x100},
	{0x80,0x0C0},{0x00,0x080},{0x60,0x080},{0xC0,0x1A0},
	{0x00,0x000},{0x80,0x080},{0xE0,0x080},{0x40,0x140},
	{0xA0,0x140},{0x20,0x140},{0x40,0x1C0},{0x00,0x080},
	{0x80,0x1C0},{0x00,0x000},{0x00,0x060},{0x80,0x060},
	{0x60,0x0E0},{0x80,0x000},{0x20,0x040},{0xC0,0x060},
	{0xE0,0x060},{0x40,0x0E0},{0x00,0x0E0},{0x80,0x0E0},
	{0x40,0x0E0},{0xC0,0x0E0},{0x80,0x0E0},{0x00,0x160},
	{0x60,0x040},{0xC0,0x0C0},{0xC0,0x040},{0x40,0x060},
	{0x80,0x060},{0x20,0x0E0},{0xC0,0x0C0},{0x80,0x0C0},
	{0x00,0x0F0},{0x00,0x040},{0x00,0x060},{0xA0,0x070},
	{0xC0,0x070},{0xE0,0x070},{0x40,0x080},{0x80,0x0C0},
	{0x60,0x0C0},{0x80,0x0E0},{0xA0,0x0E0},{0x80,0x180},
	{0x80,0x1C0},{0x80,0x1E0},{0xA0,0x180},{0x40,0x1E0},
	{0x00,0x1C0},{0xC0,0x100},{0x60,0x1E0},{0xE0,0x080},
	{0x80,0x040},{0x80,0x080},{0x80,0x0A0},{0x00,0x080},
	{0x40,0x1A0},{0x40,0x1C0},{0x00,0x0C0},{0x00,0x0A0},
	{0x60,0x010},{0x00,0x000},{0x70,0x040},{0x80,0x010},
	{0x60,0x000},{0x60,0x030},{0x70,0x030},{0x80,0x000},
	{0x00,0x000},{0x40,0x0A0},{0x80,0x000},{0x80,0x020},
	{0x00,0x080},{0x60,0x140},{0x80,0x080},{0x00,0x0C0},
	{0xE0,0x0E0},{0x00,0x000},{0xC0,0x100},{0x00,0x060},
	{0x80,0x0C0},{0x80,0x0E0},{0x40,0x0E0},{0x20,0x0C0},
	{0xE0,0x0C0},{0x40,0x060},{0xC0,0x080},{0xA0,0x1A0},
	{0x80,0x100},{0x00,0x0E0},{0x20,0x0E0},{0x00,0x0C0},
	{0xA0,0x180},{0x00,0x100},{0x00,0x0E0},{0x00,0x0E0},
	{0x40,0x180},{0xE0,0x180},{0xC0,0x1A0},{0x80,0x180},
	{0x00,0x000},{0x00,0x040},{0xC0,0x180},{0x60,0x0E0},
	{0xA0,0x000},{0x80,0x080},{0x00,0x1A0},{0x40,0x000},
	{0x60,0x140},{0x00,0x0E0},{0x40,0x0E0},{0x80,0x0C0},
	{0x80,0x140},{0xC0,0x0C0},{0xC0,0x0E0},{0xC0,0x0A0},
	{0x20,0x120},{0x80,0x0A0},{0x60,0x0E0},{0xE0,0x140},
	{0xE0,0x160},{0x80,0x180},{0x00,0x180},{0x00,0x0A0},
	{0x40,0x0A0},{0x20,0x100},{0xE0,0x120},{0xA0,0x0A0},
	{0xC0,0x140},{0x80,0x060},{0xC0,0x0C0},{0x00,0x000},
	{0x80,0x0C0},{0xE0,0x1A0},{0xC0,0x000},{0xE0,0x020},
	{0x00,0x180},{0xC0,0x1E0},{0xE0,0x1E0},{0xE0,0x1C0},
	{0x00,0x000},{0x80,0x000},{0x00,0x060},{0x40,0x060},
	{0x40,0x000},{0x80,0x0C0},{0x00,0x040},{0x80,0x080},
	{0xC0,0x0C0},{0x20,0x000},{0x20,0x020},{0xE0,0x0C0},
	{0xC0,0x080},{0x60,0x100},{0x20,0x140},{0x40,0x120},
	{0xE0,0x100},{0xC0,0x100},{0x00,0x180},{0xE0,0x0A0},
	{0xC0,0x060},{0x00,0x000},{0x40,0x080},{0xC0,0x080},
	{0x00,0x0C0},{0x80,0x060},{0xC0,0x060},{0x20,0x0C0},
	{0xC0,0x0C0},{0x80,0x0A0},{0xA0,0x0C0},{0x80,0x0C0},
	{0x40,0x0C0},{0x00,0x120},{0x80,0x000},{0x80,0x080},
	{0x40,0x180},{0xA0,0x100},{0x20,0x060},{0xE0,0x040},
	{0x80,0x060},{0x00,0x080},{0x60,0x060},{0x60,0x080},
	{0xC0,0x140},{0x80,0x120},{0xA0,0x020},{0x20,0x080},
	{0x20,0x0A0},{0x00,0x060},{0x00,0x0E0},{0x00,0x0C0},
	{0x80,0x000},{0x40,0x100},{0x40,0x0A0},{0x60,0x100},
	{0xA0,0x120},{0x80,0x0A0},{0x40,0x0E0},{0xC0,0x000},
	{0xC0,0x0A0},{0x40,0x060}
};
//-- undersea --
struct t_wm_file_04 D_0096A798[8] = {
	{0x00,0x00},
	{0x00,0x00},
	{0x00,0x00},
	{0x00,0x00},
	{0x00,0x00},
	{0x00,0x00},
	{0x80,0x00},
	{0x80,0x00}
};
//-- snowfield --
struct t_wm_file_04 D_0096A7B8[4] = {
	{0x00,0x00},
	{0x00,0x80},
	{0x00,0x40},
	{0x00,0xC0}
};
//-- --
const char *D_0096A7C8[1] = {
	/*0096C618*/"AAE.a"
};
//00 00 00 00
const char *D_0096A7D0[6] = {
	/*0096C620*/"AGE.a",
	/*0096C628*/"AHA.a",
	/*0096C630*/"AHB.a",
	/*0096C638*/"AHC.a",
	/*0096C640*/"AHD.a",
	/*0096C648*/"AHE.a"
};
const char *D_0096A7E8[1] = {
	/*0096C650*/"AIE.a"
};
//00 00 00 00
const char *D_0096A7F0[3] = {
	/*0096C658*/"ASC.a",
	/*0096C660*/"ASD.a",
	/*0096C668*/"ASE.a"
};
//00 00 00 00
const char *D_0096A800[0xa] = {
	/*0096C670*/"AZE.a",
	/*0096C678*/"BAA.a",
	/*0096C680*/"BAB.a",
	/*0096C688*/"BAC.a",
	/*0096C690*/"BAD.a",
	/*0096C698*/"BAE.a",
	/*0096C6A0*/"BBA.a",
	/*0096C6A8*/"BBB.a",
	/*0096C6B0*/"BBC.a",
	/*0096C6B8*/"BBD.a"
};
const char *D_0096A828[0xa] = {
	/*0096C6C0*/"BID.a",
	/*0096C6C8*/"BIE.a",
	/*0096C6D0*/"BJA.a",
	/*0096C6D8*/"BJB.a",
	/*0096C6E0*/"BJC.a",
	/*0096C6E8*/"BJD.a",
	/*0096C6F0*/"BJE.a",
	/*0096C6F8*/"BKA.a",
	/*0096C700*/"BKB.a",
	/*0096C708*/"BKC.a"
};
const char *D_0096A850[1] = {
	/*0096C710*/"BLD.a"
};
const char *D_0096A854[1] = {
	/*0096C718*/"BME.a"
};
const char *D_0096A858[5] = {
	/*0096C720*/"BTD.a",
	/*0096C728*/"BTE.a",
	/*0096C730*/"BUA.a",
	/*0096C738*/"BUB.a",
	/*0096C740*/"BUC.a"
};
//00 00 00 00
const char *D_0096A870[2] = {
	/*0096C748*/"CEA.a",
	/*0096C750*/"CEB.a"
};
const char *D_0096A878[1] = {
	/*0096C758*/"CFB.a"
};
const char *D_0096A87C[1] = {
	/*0096C760*/"CGC.a"
};
const char *D_0096A880[1] = {
	/*0096C768*/"CIC.a"
};
const char *D_0096A884[1] = {
	/*0096C770*/"CMA.a"
};
const char *D_0096A888[1] = {
	/*0096C778*/"CNA.a"
};
const char *D_0096A88C[1] = {
	/*0096C780*/"COB.a"
};
const char *D_0096A890[1] = {
	/*0096C788*/"CPB.a"
};
const char *D_0096A894[1] = {
	/*0096C790*/"CQB.a"
};
const char *D_0096A898[3] = {
	/*0096C798*/"DDA.a",
	/*0096C7A0*/"DDB.a",
	/*0096C7A8*/"DDC.a"
};
const char *D_0096A8A4[1] = {
	/*0096C7B0*/"DFE.a"
};
const char *D_0096A8A8[1] = {
	/*0096C7B8*/"DIB.a"
};
const char *D_0096A8AC[1] = {
	/*0096C7C0*/"DJB.a"
};
const char *D_0096A8B0[1] = {
	/*0096C7C8*/"DKB.a"
};
const char *D_0096A8B4[1] = {
	/*0096C7D0*/"DLA.a"
};
const char *D_0096A8B8[0xb] = {
	/*0096C7D8*/"DSE.a",
	/*0096C7E0*/"DTA.a",
	/*0096C7E8*/"DTB.a",
	/*0096C7F0*/"DTC.a",
	/*0096C7F8*/"DTD.a",
	/*0096C800*/"DTE.a",
	/*0096C808*/"DUA.a",
	/*0096C810*/"DUB.a",
	/*0096C818*/"DUC.a",
	/*0096C820*/"DUD.a",
	/*0096C828*/"DUE.a"
};
const char *D_0096A8E4[1] = {
	/*0096C830*/"DYA.a"
};
const char *D_0096A8E8[7] = {
	/*0096C838*/"EIC.a",
	/*0096C840*/"EID.a",
	/*0096C848*/"EIE.a",
	/*0096C850*/"EJA.a",
	/*0096C858*/"EJB.a",
	/*0096C860*/"EJC.a",
	/*0096C868*/"EJD.a" 
};
const char *D_0096A904[1] = {
	/*0096C870*/"EKD.a"
};
const char *D_0096A908[1] = {
	/*0096C878*/"ENA.a"
};
//0096A90C	00000000
struct t_wmfile_14 D_0096A910[0xa] = {
	{/*0096C880*/"choko",		/*0096C888*/"/aja.hrc", 3, {0,0,0}, 0x0200, D_0096A7F0},
	{/*0096C894*/"tybrco",		/*0096C89C*/"/dva.hrc", 1, {0,0,0}, 0x0280, D_0096A8E4},
	{/*0096C8A8*/"buggy",		/*0096C8B0*/"/aba.hrc", 6, {0,0,0}, 0x0200, D_0096A7D0},
	{/*0096C8BC*/"barrier",		/*0096C8C4*/"/aaa.hrc", 1, {0,0,0}, 0x0DAC, D_0096A7C8},
	{/*0096C8D0*/"condor",		/*0096C8D8*/"/bkd.hrc", 1, {0,0,0}, 0x0C80, D_0096A850},
	{/*0096C8E4*/"rocket",		/*0096C8EC*/"/coc.hrc", 1, {0,0,0}, 0x08FC, D_0096A890},
	{/*0096C8F8*/"rocketbase",	/*0096C904*/"/cpc.hrc", 1, {0,0,0}, 0x08FC, D_0096A894},
	{/*0096C910*/"goldsaucer",	/*0096C91C*/"/cfc.hrc", 1, {0,0,0}, 0x0AF0, D_0096A87C},
	{/*0096C928*/"canon",		/*0096C930*/"/aia.hrc", 1, {0,0,0}, 0x1000, D_0096A7E8},
	{/*0096C93C*/"rock",		/*0096C944*/"/cnb.hrc", 1, {0,0,0}, 0x0834, D_0096A88C},
};
struct t_wmfile_14 __0096A9D8[0xc] = {
	{/*0096C950*/"choko",		/*0096C958*/"/aja.hrc", 3, {0,0,0}, 0x0200, D_0096A7F0},
	{/*0096C964*/"choko",		/*0096C96C*/"/aja.hrc", 3, {0,0,0}, 0x0200, D_0096A7F0},
	{/*0096C978*/"highwind",	/*0096C984*/"/cgd.hrc", 1, {0,0,0}, 0x0300, D_0096A880},
	{/*0096C990*/"sbmrn",		/*0096C998*/"/ddd.hrc", 1, {0,0,0}, 0x0200, D_0096A8A4},
	{/*0096C9A4*/"condor",		/*0096C9AC*/"/bkd.hrc", 1, {0,0,0}, 0x0C80, D_0096A850},
	{/*0096C9B8*/"rocket",		/*0096C9C0*/"/coc.hrc", 1, {0,0,0}, 0x08FC, D_0096A890},
	{/*0096C9CC*/"rocketbase",	/*0096C9D8*/"/cpc.hrc", 1, {0,0,0}, 0x08FC, D_0096A894},
	{/*0096C9E4*/"goldsaucer",	/*0096C9F0*/"/cfc.hrc", 1, {0,0,0}, 0x0AF0, D_0096A87C},
	{/*0096C9FC*/"canon",		/*0096CA04*/"/aia.hrc", 1, {0,0,0}, 0x1000, D_0096A7E8},
	{/*0096CA10*/"tail",		/*0096CA18*/"/dkc.hrc", 1, {0,0,0}, 0x0300, D_0096A8B4},
	{/*0096CA24*/"barrier",		/*0096CA2C*/"/aaa.hrc", 1, {0,0,0}, 0x0DAC, D_0096A7C8},
	{/*0096CA38*/"diaweapon",	/*0096CA44*/"/bna.hrc", 5, {0,0,0}, 0x0400, D_0096A858}
};
struct t_wmfile_14 D_0096AAC8[2] = {
	{/*0096CA50*/"warship",		/*0096CA58*/"/eke.hrc", 1, {0,0,0}, 0x01B8, D_0096A908},
	{/*0096CA64*/"canon",		/*0096CA6C*/"/aia.hrc", 1, {0,0,0}, 0x1000, D_0096A7E8}
};
struct t_wmfile_14 D_0096AAF0[0xd] = {
	{/*0096CA78*/"choko",		/*0096CA80*/"/aja.hrc", 3, {0,0,0}, 0x0200, D_0096A7F0},
	{/*0096CA8C*/"choko",		/*0096CA94*/"/aja.hrc", 3, {0,0,0}, 0x0200, D_0096A7F0},
	{/*0096CAA0*/"highwind",	/*0096CAAC*/"/cgd.hrc", 1, {0,0,0}, 0x0300, D_0096A880},
	{/*0096CAB8*/"sbmrn",		/*0096CAC0*/"/ddd.hrc", 1, {0,0,0}, 0x0200, D_0096A8A4},
	{/*0096CACC*/"condor",		/*0096CAD4*/"/bkd.hrc", 1, {0,0,0}, 0x0C80, D_0096A850},
	{/*0096CAE0*/"rocket",		/*0096CAE8*/"/coc.hrc", 1, {0,0,0}, 0x08FC, D_0096A890},
	{/*0096CAF4*/"rocketbase",	/*0096CB00*/"/cpc.hrc", 1, {0,0,0}, 0x08FC, D_0096A894},
	{/*0096CB0C*/"goldsaucer",	/*0096CB18*/"/cfc.hrc", 1, {0,0,0}, 0x0AF0, D_0096A87C},
	{/*0096CB24*/"canon",		/*0096CB2C*/"/aia.hrc", 1, {0,0,0}, 0x1000, D_0096A7E8},
	{/*0096CB38*/"tail",		/*0096CB40*/"/dkc.hrc", 1, {0,0,0}, 0x0300, D_0096A8B4},
	{/*0096CB4C*/"barrier",		/*0096CB54*/"/aaa.hrc", 1, {0,0,0}, 0x0DAC, D_0096A7C8},
	{/*0096CB60*/"diaweapon",	/*0096CB6C*/"/bna.hrc", 5, {0,0,0}, 0x0400, D_0096A858},
	{/*0096CB78*/"rock",		/*0096CB80*/"/cnb.hrc", 1, {0,0,0}, 0x0834, D_0096A88C}
};
//0096ABF4  00 00 00 00
struct t_wmfile_14 D_0096ABF8[0xd] = {
	{/*0096CB8C*/"choko",		/*0096CB94*/"/aja.hrc", 3, {0,0,0}, 0x0200, D_0096A7F0},
	{/*0096CBA0*/"choko",		/*0096CBA8*/"/aja.hrc", 3, {0,0,0}, 0x0200, D_0096A7F0},
	{/*0096CBB4*/"highwind",	/*0096CBC0*/"/cgd.hrc", 1, {0,0,0}, 0x0300, D_0096A880},
	{/*0096CBCC*/"sbmrn",		/*0096CBD4*/"/ddd.hrc", 1, {0,0,0}, 0x0200, D_0096A8A4},
	{/*0096CBE0*/"condor",		/*0096CBE8*/"/bkd.hrc", 1, {0,0,0}, 0x0C80, D_0096A850},
	{/*0096CBF4*/"rocket",		/*0096CBFC*/"/coc.hrc", 1, {0,0,0}, 0x08FC, D_0096A890},
	{/*0096CC08*/"rocketbase",	/*0096CC14*/"/cpc.hrc", 1, {0,0,0}, 0x08FC, D_0096A894},
	{/*0096CC20*/"goldsaucer",	/*0096CC2C*/"/cfc.hrc", 1, {0,0,0}, 0x0AF0, D_0096A87C},
	{/*0096CC38*/"midgulcanon", /*0096CC44*/"/cmb.hrc", 1, {0,0,0}, 0x1000, D_0096A888},
	{/*0096CC50*/"tail",		/*0096CC58*/"/dkc.hrc", 1, {0,0,0}, 0x0300, D_0096A8B4},
	{/*0096CC64*/"barrier",		/*0096CC6C*/"/aaa.hrc", 1, {0,0,0}, 0x0DAC, D_0096A7C8},
	{/*0096CC78*/"diaweapon",	/*0096CC84*/"/bna.hrc", 5, {0,0,0}, 0x0400, D_0096A858},
	{/*0096CC90*/"rock",		/*0096CC98*/"/cnb.hrc", 1, {0,0,0}, 0x0834, D_0096A88C}
};
//0096ACFC  00 00 00 00
struct t_wmfile_14 D_0096AD00[0xd] = {
	{/*0096CCA4*/"choko",		/*0096CCAC*/"/aja.hrc", 3, {0,0,0}, 0x0200, D_0096A7F0},
	{/*0096CCB8*/"choko",		/*0096CCC0*/"/aja.hrc", 3, {0,0,0}, 0x0200, D_0096A7F0},
	{/*0096CCCC*/"highwind02",	/*0096CCD8*/"/cid.hrc", 1, {0,0,0}, 0x0300, D_0096A884},
	{/*0096CCE4*/"sbmrn",		/*0096CCEC*/"/ddd.hrc", 1, {0,0,0}, 0x0200, D_0096A8A4},
	{/*0096CCF8*/"condor",		/*0096CD00*/"/bkd.hrc", 1, {0,0,0}, 0x0C80, D_0096A850},
	{/*0096CD0C*/"rocket",		/*0096CD14*/"/coc.hrc", 1, {0,0,0}, 0x08FC, D_0096A890},
	{/*0096CD20*/"rocketbase",	/*0096CD2C*/"/cpc.hrc", 1, {0,0,0}, 0x08FC, D_0096A894},
	{/*0096CD38*/"goldsaucer",	/*0096CD44*/"/cfc.hrc", 1, {0,0,0}, 0x0AF0, D_0096A87C},
	{/*0096CD50*/"canon",		/*0096CD58*/"/aia.hrc", 1, {0,0,0}, 0x1000, D_0096A7E8},
	{/*0096CD64*/"tail",		/*0096CD6C*/"/dkc.hrc", 1, {0,0,0}, 0x0300, D_0096A8B4},
	{/*0096CD78*/"barrier",		/*0096CD80*/"/aaa.hrc", 1, {0,0,0}, 0x0DAC, D_0096A7C8},
	{/*0096CD8C*/"diaweapon",	/*0096CD98*/"/bna.hrc", 5, {0,0,0}, 0x0400, D_0096A858},
	{/*0096CDA4*/"rock",		/*0096CDAC*/"/cnb.hrc", 1, {0,0,0}, 0x0834, D_0096A88C}
};
//0096AE04  00 00 00 00
struct t_wmfile_14 D_0096AE08[0xd] = {
	{/*0096CDB8*/"choko",		/*0096CDC0*/"/aja.hrc", 3, {0,0,0}, 0x0200, D_0096A7F0},
	{/*0096CDCC*/"choko",		/*0096CDD4*/"/aja.hrc", 3, {0,0,0}, 0x0200, D_0096A7F0},
	{/*0096CDE0*/"highwind02",	/*0096CDEC*/"/cid.hrc", 1, {0,0,0}, 0x0300, D_0096A884},
	{/*0096CDF8*/"sbmrn",		/*0096CE00*/"/ddd.hrc", 1, {0,0,0}, 0x0200, D_0096A8A4},
	{/*0096CE0C*/"condor",		/*0096CE14*/"/bkd.hrc", 1, {0,0,0}, 0x0C80, D_0096A850},
	{/*0096CE20*/"rocket",		/*0096CE28*/"/coc.hrc", 1, {0,0,0}, 0x08FC, D_0096A890},
	{/*0096CE34*/"rocketbase",	/*0096CE40*/"/cpc.hrc", 1, {0,0,0}, 0x08FC, D_0096A894},
	{/*0096CE4C*/"goldsaucer",	/*0096CE58*/"/cfc.hrc", 1, {0,0,0}, 0x0AF0, D_0096A87C},
	{/*0096CE64*/"midgulcanon",	/*0096CE70*/"/cmb.hrc", 1, {0,0,0}, 0x1000, D_0096A888},
	{/*0096CE7C*/"tail",		/*0096CE84*/"/dkc.hrc", 1, {0,0,0}, 0x0300, D_0096A8B4},
	{/*0096CE90*/"barrier",		/*0096CE98*/"/aaa.hrc", 1, {0,0,0}, 0x0DAC, D_0096A7C8},
	{/*0096CEA4*/"diaweapon",	/*0096CEB0*/"/bna.hrc", 5, {0,0,0}, 0x0400, D_0096A858},
	{/*0096CEBC*/"rock",		/*0096CEC4*/"/cnb.hrc", 1, {0,0,0}, 0x0834, D_0096A88C}
};
//0096AF0C  00 00 00 00
struct t_wmfile_14 D_0096AF10[0xd] = {
	{/*0096CED0*/"choko",		/*0096CED8*/"/aja.hrc", 3, {0,0,0}, 0x0200, D_0096A7F0},
	{/*0096CEE4*/"choko",		/*0096CEEC*/"/aja.hrc", 3, {0,0,0}, 0x0200, D_0096A7F0},
	{/*0096CEF8*/"highwind",	/*0096CF04*/"/cgd.hrc", 1, {0,0,0}, 0x0300, D_0096A880},
	{/*0096CF10*/"sbmrn",		/*0096CF18*/"/ddd.hrc", 1, {0,0,0}, 0x0200, D_0096A8A4},
	{/*0096CF24*/"condor",		/*0096CF2C*/"/bkd.hrc", 1, {0,0,0}, 0x0C80, D_0096A850},
	{/*0096CF38*/"rocket",		/*0096CF40*/"/coc.hrc", 1, {0,0,0}, 0x08FC, D_0096A890},
	{/*0096CF4C*/"rocketbase",	/*0096CF58*/"/cpc.hrc", 1, {0,0,0}, 0x08FC, D_0096A894},
	{/*0096CF64*/"goldsaucer",	/*0096CF70*/"/cfc.hrc", 1, {0,0,0}, 0x0AF0, D_0096A87C},
	{/*0096CF7C*/"midgulcanon",	/*0096CF88*/"/cmb.hrc", 1, {0,0,0}, 0x1000, D_0096A888},
	{/*0096CF94*/"tail",		/*0096CF9C*/"/dkc.hrc", 1, {0,0,0}, 0x0300, D_0096A8B4},
	{/*0096CFA8*/"barrier",		/*0096CFB0*/"/aaa.hrc", 1, {0,0,0}, 0x0DAC, D_0096A7C8},
	{/*0096CFBC*/"ultima",		/*0096CFC4*/"/dyb.hrc", 7, {0,0,0}, 0x0200, D_0096A8E8},
	{/*0096CFD0*/"rock",		/*0096CFD8*/"/cnb.hrc", 1, {0,0,0}, 0x0834, D_0096A88C}
};
//0096B014  00 00 00 00
struct t_wmfile_14 D_0096B018[0xd] = {
	{/*0096CFE4*/"choko",		/*0096CFEC*/"/aja.hrc", 3, {0,0,0}, 0x0200, D_0096A7F0},
	{/*0096CFF8*/"choko",		/*0096D000*/"/aja.hrc", 3, {0,0,0}, 0x0200, D_0096A7F0},
	{/*0096D00C*/"highwind02",	/*0096D018*/"/cid.hrc", 1, {0,0,0}, 0x0300, D_0096A884},
	{/*0096D024*/"sbmrn",		/*0096D02C*/"/ddd.hrc", 1, {0,0,0}, 0x0200, D_0096A8A4},
	{/*0096D038*/"condor",		/*0096D040*/"/bkd.hrc", 1, {0,0,0}, 0x0C80, D_0096A850},
	{/*0096D04C*/"rocket",		/*0096D054*/"/coc.hrc", 1, {0,0,0}, 0x08FC, D_0096A890},
	{/*0096D060*/"rocketbase",	/*0096D06C*/"/cpc.hrc", 1, {0,0,0}, 0x08FC, D_0096A894},
	{/*0096D078*/"goldsaucer",	/*0096D084*/"/cfc.hrc", 1, {0,0,0}, 0x0AF0, D_0096A87C},
	{/*0096D090*/"midgulcanon",	/*0096D09C*/"/cmb.hrc", 1, {0,0,0}, 0x1000, D_0096A888},
	{/*0096D0A8*/"tail",		/*0096D0B0*/"/dkc.hrc", 1, {0,0,0}, 0x0300, D_0096A8B4},
	{/*0096D0BC*/"barrier",		/*0096D0C4*/"/aaa.hrc", 1, {0,0,0}, 0x0DAC, D_0096A7C8},
	{/*0096D0D0*/"ultima",		/*0096D0D8*/"/dyb.hrc", 7, {0,0,0}, 0x0200, D_0096A8E8},
	{/*0096D0E4*/"rock",		/*0096D0EC*/"/cnb.hrc", 1, {0,0,0}, 0x0834, D_0096A88C}
};
//0096B11C  00 00 00 00
struct t_wmfile_14 D_0096B120[0xc] = {
	{/*0096D0F8*/"choko",		/*0096D100*/"/aja.hrc", 3, {0,0,0}, 0x0200, D_0096A7F0},
	{/*0096D10C*/"choko",		/*0096D114*/"/aja.hrc", 3, {0,0,0}, 0x0200, D_0096A7F0},
	{/*0096D120*/"highwind",	/*0096D12C*/"/cgd.hrc", 1, {0,0,0}, 0x0300, D_0096A880},
	{/*0096D138*/"sbmrn",		/*0096D140*/"/ddd.hrc", 1, {0,0,0}, 0x0200, D_0096A8A4},
	{/*0096D14C*/"condor",		/*0096D154*/"/bkd.hrc", 1, {0,0,0}, 0x0C80, D_0096A850},
	{/*0096D160*/"rocket",		/*0096D168*/"/coc.hrc", 1, {0,0,0}, 0x08FC, D_0096A890},
	{/*0096D174*/"rocketbase",	/*0096D180*/"/cpc.hrc", 1, {0,0,0}, 0x08FC, D_0096A894},
	{/*0096D18C*/"goldsaucer",	/*0096D198*/"/cfc.hrc", 1, {0,0,0}, 0x0AF0, D_0096A87C},
	{/*0096D1A4*/"midgulcanon",	/*0096D1B0*/"/cmb.hrc", 1, {0,0,0}, 0x1000, D_0096A888},
	{/*0096D1BC*/"tail",		/*0096D1C4*/"/dkc.hrc", 1, {0,0,0}, 0x0300, D_0096A8B4},
	{/*0096D1D0*/"ruby",		/*0096D1D8*/"/cqc.hrc", 3, {0,0,0}, 0x0280, D_0096A898},
	{/*0096D1E4*/"rock",		/*0096D1EC*/"/cnb.hrc", 1, {0,0,0}, 0x0834, D_0096A88C}
};
struct t_wmfile_14 D_0096B210[0xc] = {
	{/*0096D1F8*/"choko",		/*0096D200*/"/aja.hrc", 3, {0,0,0}, 0x0200, D_0096A7F0},
	{/*0096D20C*/"choko",		/*0096D214*/"/aja.hrc", 3, {0,0,0}, 0x0200, D_0096A7F0},
	{/*0096D220*/"highwind02",	/*0096D22C*/"/cid.hrc", 1, {0,0,0}, 0x0300, D_0096A884},
	{/*0096D238*/"sbmrn",		/*0096D240*/"/ddd.hrc", 1, {0,0,0}, 0x0200, D_0096A8A4},
	{/*0096D24C*/"condor",		/*0096D254*/"/bkd.hrc", 1, {0,0,0}, 0x0C80, D_0096A850},
	{/*0096D260*/"rocket",		/*0096D268*/"/coc.hrc", 1, {0,0,0}, 0x08FC, D_0096A890},
	{/*0096D274*/"rocketbase",	/*0096D280*/"/cpc.hrc", 1, {0,0,0}, 0x08FC, D_0096A894},
	{/*0096D28C*/"goldsaucer",	/*0096D298*/"/cfc.hrc", 1, {0,0,0}, 0x0AF0, D_0096A87C},
	{/*0096D2A4*/"midgulcanon",	/*0096D2B0*/"/cmb.hrc", 1, {0,0,0}, 0x1000, D_0096A888},
	{/*0096D2BC*/"tail",		/*0096D2C4*/"/dkc.hrc", 1, {0,0,0}, 0x0300, D_0096A8B4},
	{/*0096D2D0*/"ruby",		/*0096D2D8*/"/cqc.hrc", 3, {0,0,0}, 0x0280, D_0096A898},
	{/*0096D2E4*/"rock",		/*0096D2EC*/"/cnb.hrc", 1, {0,0,0}, 0x0834, D_0096A88C}
};
struct t_wmfile_14 D_0096B300[7] = {
	{/*0096D2F8*/"sbmrn",		/*0096D300*/"/ddd.hrc", 1, {0,0,0}, 0x0200, D_0096A8A4},
	{/*0096D30C*/"gernika",		/*0096D314*/"/cec.hrc", 1, {0,0,0}, 0x1000, D_0096A878},
	{/*0096D320*/"underseemk",	/*0096D32C*/"/eje.hrc", 1, {0,0,0}, 0x1000, D_0096A904},
	{/*0096D338*/"coralkey",	/*0096D344*/"/ble.hrc", 1, {0,0,0}, 0x0300, D_0096A854},
	{/*0096D350*/"seeobject",	/*0096D35C*/"/dic.hrc", 1, {0,0,0}, 0x0800, D_0096A8AC},
	{/*0096D368*/"sbmrn2",		/*0096D370*/"/dga.hrc", 1, {0,0,0}, 0x0200, D_0096A8A8},
	{/*0096D37C*/"emerald",		/*0096D384*/"/bud.hrc", 2, {0,0,0}, 0x0280, D_0096A870}
};
//0096B38C  00 00 00 00
struct t_wmfile_14 D_0096B390[3] = {
	{/*0096D390*/"snowpole",	/*0096D39C*/"/djc.hrc", 1, {0,0,0}, 0x0300, D_0096A8B0},
	{/*0096D3A8*/"snowpole",	/*0096D3B4*/"/djc.hrc", 1, {0,0,0}, 0x0300, D_0096A8B0},
	{/*0096D3C0*/"snowpole",	/*0096D3CC*/"/djc.hrc", 1, {0,0,0}, 0x0300, D_0096A8B0}
};
//0096B3CC 00 00 00 00
struct t_wmfile_14 D_0096B3D0 = {/*0096D3D8*/"cloud", /*0096D3E0*/"/bbe.hrc", 0xA, {0,0,0}, 0x0200, D_0096A828};
//0096B3E4  00 00 00 00
struct t_wmfile_14 D_0096B3E8 = {/*0096D3EC*/"tifa", /*0096D3F4*/"/dlb.hrc", 0xB, {0,0,0}, 0x0200, D_0096A8B8};
//0096B3FC  00 00 00 00
struct t_wmfile_14 D_0096B400 = {/*0096D400*/"cid", /*0096D404*/"/ata.hrc", 0xA, {0,0,0}, 0x0200, D_0096A800};

int D_0096B414 = -1;
//nonexistent textures index[surface]
short D_0096B418[0x16] = {
	0x035,0x038,0x039,0x03A,0x03D,0x043,0x081,0x0BC,
	0x0C0,0x0C4,0x0CD,0x0CE,0x0D0,0x0EA,0x0EB,0x0EC,
	0x0FD,0x101,0x108,0x109,0x113,0x114
};
//__0096B444 00 00 00 00
short D_0096B448[0x16] = {
	0x108,0x113,0x109,0x114,0x043,0x101,0x081,0x0EC,
	0x0C4,0x038,0x0CD,0x0EB,0x0BC,0x039,0x0CE,0x0EA,
	0x0FD,0x03A,0x0D0,0x035,0x03D,0x0C0
};
////////////////////////////////////////
//wmfile:texture does not exist?
int C_007592E0(int bp08) {
	int i;

	for(i = 0; i < 0x16; i ++) {
		if(D_0096B418[i] == bp08)
			return 1;
	}//end for

	return 0;
}

//wmfile:read file(archive)
int C_0075931B(const char *bp08, int bp0c, void *bp10, int _p14) {
	struct {
		char local_194[4];
		char local_193[256];
		char local_129[256];
		int local_65;
		char local_64[256];
	}lolo;

	_splitpath(bp08, lolo.local_194, lolo.local_193, lolo.local_64, lolo.local_129);
	strcat(lolo.local_64, lolo.local_129);
	lolo.local_65 = C_006759D2(lolo.local_64, ARCHIVE_05);//is_lib:get entry offset?
	if(lolo.local_65) {
		C_0067633E(lolo.local_65, 5, bp10, bp0c);//is_lib:load entry
		return 0;
	}

	return 1;
}

//wmfile:read file
int C_007593CD(const char *bp08, int bp0c, int bp10, void *bp14, int _p18) {
	struct t_file_18 *local_1 = 0;

	local_1 = file_open(0, bp08);
	if(local_1) {
		file_lseek(local_1, bp0c);
		file_read(bp10, bp14, local_1);
		file_close(local_1);
		return 0;
	}

	return 1;
}

//load 3d models[world]?
void C_0075942C(int bp08) {
	struct {
		char *bp_41c;
		struct t_rsd_74 bp_418;
		struct tSkeleton *bp_3a4;
		int j;//bp_3a0
		int i;//bp_39c
		char bp_398[200];
		struct t_animationHeader *bp_2d0;
		struct t_aa0 *bp_2cc;
		char bp_2c8[0x100];
		char bp_1c8[0x100];
		char bp_0c8[200];
	}lolo;

	lolo.bp_2cc = C_00676578();
	lolo.i = 0;
	lolo.j = 0;
	//-- --
	if(D_00E2BBD4)
		C_00759EEA();//wmfile:release 3d models[world]?
	//-- --
	switch(bp08) {
		case 0:
			D_00E2BBD0 = D_0096A910;
			D_00E2BBD4 = 0xa;
		break;
		case 1:
			D_00E2BBD0 = D_0096AAF0;
			D_00E2BBD4 = 0xd;
		break;
		case 2:
			D_00E2BBD0 = D_0096ABF8;
			D_00E2BBD4 = 0xd;
		break;
		case 3:
			D_00E2BBD0 = D_0096AD00;
			D_00E2BBD4 = 0xd;
		break;
		case 4:
			D_00E2BBD0 = D_0096AE08;
			D_00E2BBD4 = 0xd;
		break;
		case 5:
			D_00E2BBD0 = D_0096AF10;
			D_00E2BBD4 = 0xd;
		break;
		case 6:
			D_00E2BBD0 = D_0096B018;
			D_00E2BBD4 = 0xd;
		break;
		case 7:
			D_00E2BBD0 = D_0096B120;
			D_00E2BBD4 = 0xc;
		break;
		case 8:
			D_00E2BBD0 = D_0096B210;
			D_00E2BBD4 = 0xc;
		break;
		case 9:
		case 0xa:
			D_00E2BBD0 = D_0096AAC8;
			D_00E2BBD4 = 2;
		break;
		case 0xb:
			D_00E2BBD0 = D_0096B300;
			D_00E2BBD4 = 7;
		break;
		case 0xc://snowfield
			D_00E2BBD0 = D_0096B390;
			D_00E2BBD4 = 3;
		break;
	}//end switch
	for(lolo.i = 0; lolo.i < D_00E2BBD4; lolo.i ++) {
		C_0067455E(&lolo.bp_418);//rsd:init with blend mode 4?
		lolo.bp_418.f_40.dwUseArchive = 1;
		lolo.bp_418.f_40.dwArchiveId = ARCHIVE_05;
		lolo.bp_418.f_40.f_0c = 0;
		lolo.bp_2c8[0] = 0;
		strcpy(lolo.bp_1c8, D_00E2BBD0[lolo.i].f_04);
		//-- scale --
		D_00E2C808[lolo.i].f_38 = (float)D_00E2BBD0[lolo.i].f_0c > 512.0f?
			(float)D_00E2BBD0[lolo.i].f_0c / 512.0f:
			1.0f
		;
		D_00E2C808[lolo.i].f_38 *= 15.2f;
		lolo.bp_418.fScaling = D_00E2C808[lolo.i].f_38;
		//
		//-- --
		lolo.bp_418.dwRSDFlags = RSD_02000000 | RSD_00100000;
		if(bp08 == 0xb) {
			if(lolo.i == 1 || lolo.i == 2 || lolo.i == 4) {
				lolo.bp_418.f_58 |= 1;//palette related flag
				lolo.bp_418.f_58 |= 2;//palette related flag
			}
		}
		//-- --
		if(strcmp(D_00E2BBD0[lolo.i].f_00, "choko") == 0)
			lolo.bp_418.f_30 = D_00E360F8;
		else
			lolo.bp_418.f_30 = 0;
		//-- north crater barrier? --
		if(strcmp(D_00E2BBD0[lolo.i].f_00, "barrier") == 0) {
			C_00674659(0, &lolo.bp_418);//rsd:set blend mode?
			D_00E2C808[lolo.i].dwIsTransparent = 1;
		} else {
			D_00E2C808[lolo.i].dwIsTransparent = 0;
		}
		//-- --
		lolo.bp_41c = 0;
		lolo.bp_3a4 = C_00692EE1(&lolo.bp_418.f_40, lolo.bp_41c, lolo.bp_1c8);//plytopd:load ".HRC" file?
		if(lolo.bp_3a4) {
			C_00693902(lolo.bp_2c8, lolo.bp_3a4, &lolo.bp_418, lolo.bp_2cc);//plytopd:load ".RSD" files?
			C_00693E0D(1, lolo.bp_3a4);//plytopd:set skeleton "active"?
			D_00E2C808[lolo.i].f_40 = lolo.bp_3a4;
			D_00E2C808[lolo.i].f_24 = 0;
			C_00695945(&(D_00E2C808[lolo.i].f_44));
			D_00E2C808[lolo.i].f_3c = (struct t_animationHeader **)mem_malloc(D_00E2BBD0[lolo.i].bAnimationCount * sizeof(struct t_animationHeader *), __FF7FILE__, 0x115);
			D_00E2C808[lolo.i].bAnimationCount = D_00E2BBD0[lolo.i].bAnimationCount;
			for(lolo.j = 0; lolo.j < D_00E2BBD0[lolo.i].bAnimationCount; lolo.j ++) {
				file_extRemove(D_00E2BBD0[lolo.i].f_10[lolo.j], lolo.bp_0c8);
				sprintf(lolo.bp_398, "%s.%s", lolo.bp_0c8, "A");
				if(C_0069254C(D_00E2BBD0[lolo.i].f_10[lolo.j], lolo.bp_398)) {//plytopd:convert ".anm"[TEXT] to ".A"[BIN]
					lolo.bp_2d0 = C_006921CE(&lolo.bp_418.f_40, lolo.bp_398);//plytopd:load ".A" file?
					if(lolo.bp_2d0) {
						D_00E2C808[lolo.i].f_3c[lolo.j] = lolo.bp_2d0;
						C_00692412(D_00E2C808[lolo.i].f_38, lolo.bp_2d0);
					}
				}
			}//end for
		}
	}//end for
}

//wmfile:load 3d models[chara]?
void C_00759A65(int dwModelId/*bp08*/) {
	struct {
		char *bp_41c;
		struct t_rsd_74 bp_418;
		struct tSkeleton *bp_3a4;
		int j;//bp_3a0
		int i;//bp_39c
		char bp_398[200];
		struct t_animationHeader *bp_2d0;
		struct t_aa0 *bp_2cc;//local_179
		char bp_2c8[0x100];
		char bp_1c8[0x100];
		char bp_0c8[200];
	}lolo;

	lolo.bp_2cc = C_00676578();
	lolo.i = 0;
	lolo.j = 0;
	//-- --
	if(D_00E2D164)
		C_0075A01D();//wmfile:release 3d models[chara]?
	//-- --
	switch(dwModelId) {
		case 0://cloud
			D_00E2D160 = &D_0096B3D0;
			D_00E2D164 = 1;
		break;
		case 1://tifa
			D_00E2D160 = &D_0096B3E8;
			D_00E2D164 = 1;
		break;
		case 2://cid
			D_00E2D160 = &D_0096B400;
			D_00E2D164 = 1;
		break;
	}//end switch
	for(lolo.i = 0; lolo.i < D_00E2D164; lolo.i ++) {
		C_0067455E(&lolo.bp_418);//rsd:init with blend mode 4?
		lolo.bp_418.f_40.dwUseArchive = 1;
		lolo.bp_418.f_40.dwArchiveId = ARCHIVE_05;
		lolo.bp_418.f_40.f_0c = 0;
		lolo.bp_2c8[0] = 0;
		strcpy(lolo.bp_1c8, D_00E2D160[lolo.i].f_04);
		//-- scale --
		D_00E2C430[lolo.i].f_38 = (float)D_00E2D160[lolo.i].f_0c > 512.0f?
			(float)D_00E2D160[lolo.i].f_0c / 512.0f:
			1.0f
		;
		D_00E2C430[lolo.i].f_38 *= 15.2f;
		lolo.bp_418.fScaling = D_00E2C430[lolo.i].f_38;
		D_00E2C430[lolo.i].dwIsTransparent = 0;
		//-- --
		lolo.bp_418.dwRSDFlags = RSD_02000000 | RSD_00100000;
		lolo.bp_418.f_30 = D_00E360F8;
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
		lolo.bp_41c = 0;
		lolo.bp_3a4 = C_00692EE1(&lolo.bp_418.f_40, lolo.bp_41c, lolo.bp_1c8);//plytopd:load ".HRC" file?
		if(lolo.bp_3a4) {
			C_00693902(lolo.bp_2c8, lolo.bp_3a4, &lolo.bp_418, lolo.bp_2cc);//plytopd:load ".RSD" files?
			C_00693E0D(1, lolo.bp_3a4);//plytopd:set skeleton "active"?
			D_00E2C430[lolo.i].f_40 = lolo.bp_3a4;
			D_00E2C430[lolo.i].f_24 = 0;
			C_00695945(&(D_00E2C430[lolo.i].f_44));
			D_00E2C430[lolo.i].f_3c = (struct t_animationHeader **)mem_malloc(D_00E2D160[lolo.i].bAnimationCount * sizeof(struct t_animationHeader *), __FF7FILE__, 0x19a);
			D_00E2C430[lolo.i].bAnimationCount = D_00E2D160[lolo.i].bAnimationCount;
			for(lolo.j = 0; lolo.j < D_00E2D160[lolo.i].bAnimationCount; lolo.j ++) {
				file_extRemove(D_00E2D160[lolo.i].f_10[lolo.j], lolo.bp_0c8);
				sprintf(lolo.bp_398, "%s.%s", lolo.bp_0c8, "A");
				if(C_0069254C(D_00E2D160[lolo.i].f_10[lolo.j], lolo.bp_398)) {//plytopd:convert ".anm"[TEXT] to ".A"[BIN]
					lolo.bp_2d0 = C_006921CE(&lolo.bp_418.f_40, lolo.bp_398);//plytopd:load ".A" file?
					if(lolo.bp_2d0) {
						D_00E2C430[lolo.i].f_3c[lolo.j] = lolo.bp_2d0;
						C_00692412(D_00E2C430[lolo.i].f_38, lolo.bp_2d0);
					}
				}
			}//end for
		}
	}//end for
}

//wmfile:get 3d models count[world]?
int C_00759EE0() {
	return D_00E2BBD4;
}

//wmfile:release 3d models[world]?
void C_00759EEA() {
	struct {
		int j;//local_2
		int i;//local_1
	}lolo;

	for(lolo.i = 0; lolo.i < D_00E2BBD4; lolo.i ++) {
		if(D_00E2C808[lolo.i].f_40) {
			C_00692CEE(D_00E2C808[lolo.i].f_40);//plytopd:release skeleton
			D_00E2C808[lolo.i].f_40 = 0;
			for(lolo.j = 0; lolo.j < D_00E2BBD0[lolo.i].bAnimationCount; lolo.j ++) {
				if(D_00E2C808[lolo.i].f_3c[lolo.j]) {
					C_00691E8E(D_00E2C808[lolo.i].f_3c[lolo.j]);//".A":release?
					D_00E2C808[lolo.i].f_3c[lolo.j] = 0;
				}
			}
		}
		mem_free(D_00E2C808[lolo.i].f_3c, __FF7FILE__, 0x1d2);
		D_00E2C808[lolo.i].f_3c = 0;
		D_00E2C808[lolo.i].f_24 = 0;
	}//end for
}

//wmfile:release 3d models[chara]?
void C_0075A01D() {
	struct {
		int j;//local_2
		int i;//local_1
	}lolo;

	for(lolo.i = 0; lolo.i < D_00E2D164; lolo.i ++) {
		if(D_00E2C430[lolo.i].f_40) {
			C_00692CEE(D_00E2C430[lolo.i].f_40);//plytopd:release skeleton
			D_00E2C430[lolo.i].f_40 = 0;
			for(lolo.j = 0; lolo.j < D_00E2D160[lolo.i].bAnimationCount; lolo.j ++) {
				if(D_00E2C430[lolo.i].f_3c[lolo.j]) {
					C_00691E8E(D_00E2C430[lolo.i].f_3c[lolo.j]);//".A":release?
					D_00E2C430[lolo.i].f_3c[lolo.j] = 0;
				}
			}
		}
		mem_free(D_00E2C430[lolo.i].f_3c, __FF7FILE__, 0x1ea);
		D_00E2C430[lolo.i].f_3c = 0;
		D_00E2C430[lolo.i].f_24 = 0;
	}//end for
}

int C_0075A150(int bp08) {
	int bp_04;

	switch(bp08) {
		case 0:
		case 9:
			bp_04 = 0;
		break;
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 0xa:
			bp_04 = 0x80;
		break;
		case 0xb:
			bp_04 = 2;
		break;
		case 0xc:
			bp_04 = 3;
		break;
	}//end switch

	return bp_04;
}

void C_0075A5D5(int);//wmfile:init textures & models?

//wmfile:secure init?
void C_0075A1C6(int bp08) {
	struct {
		int local_4;
		int local_3;
		struct t_aa0 *local_2;
		int local_1;
	}lolo;

	lolo.local_1 = 0;
	lolo.local_4 = 0;
	lolo.local_3 = C_0075A150(bp08);
	lolo.local_2 = C_00676578();
	C_0067453A(0);//rsd:set "use PSX resources" flag
	if(D_0096B414 != (lolo.local_3 & 0xf)) {//else 0075A273
		if(D_00E2C420)
			C_0075A921();//wmfile:clean textures & models?
		D_0096B414 = lolo.local_3 & 0xf;
		C_0075A5D5(lolo.local_3);//wmfile:init textures & models?
		//-- --
		if(D_00E360F4)
			C_0075EACE();//wm:secure clean light(2)
		D_00E360F4 = C_0075E9B3(lolo.local_3 & 0xf);//wm:create light system(2)
		//-- --
		if(D_00E360F8)
			C_0075EAF6();//wm:secure clean light(1)
		D_00E360F8 = C_0075E7A0(lolo.local_3 & 0xf);//wm:create light system(1)
		//-- --
	}
	C_0075942C(bp08);//load 3d models[world]?
}

//wmfile:load models?
void C_0075A283(int bp08) {
	struct {
		//local_35 and above for compiler
		struct t_rsd_74 local_34;
		int local_5;
		unsigned i;//local_4
		int local_3;
		const char **local_2;
		struct t_aa0 *local_1;
	}lolo;

	lolo.local_2 = 0;
	lolo.local_1 = C_00676578();
	lolo.local_3 = 0;
	lolo.local_5 = 0;
	C_006745E6(4, &lolo.local_34);//rsd:init with blend mode?
	lolo.local_34.f_40.dwUseArchive = 1;
	lolo.local_34.f_40.dwArchiveId = ARCHIVE_05;
	lolo.local_34.f_40.f_0c = 0;
	switch(bp08) {
		case 0://surface
			D_00E2C41C = 0x8f;
			D_00E2C420 = 0x11a;
			lolo.local_2 = D_00969CE8;
			D_00E2D168 = D_0096A330;
			lolo.local_34.szDir = "";//00E2D1C4
			D_00DE68FC = C_0074C179;
		break;
		case 2://undersea
			D_00E2C41C = 7;
			D_00E2C420 = 8;
			lolo.local_2 = D_0096A300;
			D_00E2D168 = D_0096A798;
			lolo.local_34.szDir = "";//00E2D1C8
			D_00DE68FC = C_0074C3F0;
		break;
		case 3://snowfield
			D_00E2C41C = 5;
			D_00E2C420 = 4;
			lolo.local_2 = D_0096A320;
			D_00E2D168 = D_0096A7B8;
			lolo.local_34.szDir = "";//00E2D1CC
			D_00DE68FC = C_0074C589;
		break;
	}//end switch
	lolo.local_34.f_2c |= 2;//LH/RH related?
	C_00674659(4, &lolo.local_34);//rsd:set blend mode?
	for(lolo.i = 0; lolo.i < D_00E2C420; lolo.i ++) {
		if(C_007592E0(lolo.i) == 0)//wmfile:texture does not exist?
			D_00E2BBD8[lolo.i] = C_006710AC(1, DX_SFX_TYPE_06, &lolo.local_34, lolo.local_2[lolo.i], lolo.local_1->f_910);//dx_sfx:alloc/create?
	}
	if(bp08 == 0 && D_00E2C420) {//else 0075A525
		lolo.local_2 = D_0096A150;
		lolo.local_34.szDir = "";//00E2D1D0
		lolo.local_34.f_2c |= 2;//LH/RH related?
		C_00674659(4, &lolo.local_34);//rsd:set blend mode?
		for(lolo.i = 0; lolo.i < 0x6c; lolo.i ++) {
			lolo.local_3 = 0;
			if(lolo.i < 0x28 && (lolo.i % 8))
				lolo.local_3 = 0;
			else if(lolo.i >= 0x28 && (lolo.i % 4))
				lolo.local_3 = 0;
			else
				lolo.local_3 = 1;
			D_00E2C658[lolo.i] = C_006710AC(1, DX_SFX_TYPE_06, &lolo.local_34, lolo.local_2[lolo.i], lolo.local_1->f_910);//dx_sfx:alloc/create?
			if(lolo.local_3) {
				D_00E2BBD8[D_0096B448[lolo.local_5]] = D_00E2C658[lolo.i];
				lolo.local_5 ++;
			}
		}
	} else if(bp08 == 3) {
		C_006745E6(4, &lolo.local_34);//rsd:init with blend mode?
		lolo.local_34.f_40.dwUseArchive = 1;
		lolo.local_34.f_40.dwArchiveId = ARCHIVE_05;
		lolo.local_34.f_40.f_0c = 0;
		lolo.local_34.szDir = "";//00E2D1D4
		C_00674659(1, &lolo.local_34);//rsd:set blend mode?
		for(lolo.i = 0; lolo.i < 2; lolo.i ++) {
			D_00E2C3F4[lolo.i + 1] = C_006710AC(1, DX_SFX_TYPE_0C, &lolo.local_34, /*lolo.local_36*/(lolo.i == 0)?"snow4.tim":"snow5.tim", lolo.local_1->f_910);//dx_sfx:alloc/create?
		}
	}
}

//wmfile:init textures & models?
void C_0075A5D5(int bp08) {
	struct {
		const char *local_32;
		struct t_rsd_74 local_31;
		int local_2;
		struct t_aa0 *local_1;
	}lolo;

	lolo.local_1 = C_00676578();
	C_006745E6(4, &lolo.local_31);//rsd:init with blend mode?
	lolo.local_31.f_40.dwUseArchive = 1;
	lolo.local_31.f_40.dwArchiveId = ARCHIVE_05;
	lolo.local_31.f_40.f_0c = 0;
	lolo.local_31.szDir = "";//00E2D1D8
	lolo.local_2 = 0;
	C_00674659(lolo.local_2, &lolo.local_31);//rsd:set blend mode?
	if(bp08 & 0x80) {
		lolo.local_32 = "midlmap2.tim";
		bp08 &= 0xf;
	} else {
		lolo.local_32 = "midlmap.tim";
	}
	D_00E2C3DC = C_006710AC(1, DX_SFX_TYPE_0C, &lolo.local_31, lolo.local_32, lolo.local_1->f_910);//dx_sfx:alloc/create?
	lolo.local_32 = "radar.tim";
	D_00E2C3D8 = C_006710AC(1, DX_SFX_TYPE_0C, &lolo.local_31, lolo.local_32, lolo.local_1->f_910);//dx_sfx:alloc/create?
	lolo.local_32 = "map.tim";
	D_00E2C3E4 = C_006710AC(1, DX_SFX_TYPE_0C, &lolo.local_31, lolo.local_32, lolo.local_1->f_910);//dx_sfx:alloc/create?
	lolo.local_31.f_70 |= SWRENDERFLAG_00004000;
	D_00E2C3F4[0] = C_006710AC(1, DX_SFX_TYPE_08, &lolo.local_31, 0, lolo.local_1->f_910);//dx_sfx:alloc/create?
	lolo.local_31.f_70 &= ~SWRENDERFLAG_00004000;
	lolo.local_31.f_2c |= 2;//LH/RH related?
	C_00674659(1, &lolo.local_31);//rsd:set blend mode?
	D_00E2C3E0 = C_006710AC(1, DX_SFX_TYPE_02, &lolo.local_31, 0, lolo.local_1->f_910);//dx_sfx:alloc/create?
	if(bp08 != 2) {
		lolo.local_32 = "shadow.tim";
		C_00674659(0, &lolo.local_31);//rsd:set blend mode?
		D_00E2C400 = C_006710AC(1, DX_SFX_TYPE_0C, &lolo.local_31, lolo.local_32, lolo.local_1->f_910);//dx_sfx:alloc/create?
	}
	//-- --
	lolo.local_32 = "dfx.tim";
	C_00674659(0, &lolo.local_31);//rsd:set blend mode?
	D_00E2C404 = C_006710AC(1, DX_SFX_TYPE_0C, &lolo.local_31, lolo.local_32, lolo.local_1->f_910);//dx_sfx:alloc/create?
	lolo.local_32 = "dfx.tim";
	C_00674659(1, &lolo.local_31);//rsd:set blend mode?
	D_00E2C408 = C_006710AC(1, DX_SFX_TYPE_0C, &lolo.local_31, lolo.local_32, lolo.local_1->f_910);//dx_sfx:alloc/create?
	lolo.local_32 = "dfx.tim";
	C_00674659(2, &lolo.local_31);//rsd:set blend mode?
	D_00E2C40C = C_006710AC(1, DX_SFX_TYPE_0C, &lolo.local_31, lolo.local_32, lolo.local_1->f_910);//dx_sfx:alloc/create?
	lolo.local_32 = "dfx.tim";
	C_00674659(3, &lolo.local_31);//rsd:set blend mode?
	D_00E2C410 = C_006710AC(1, DX_SFX_TYPE_0C, &lolo.local_31, lolo.local_32, lolo.local_1->f_910);//dx_sfx:alloc/create?
	//-- --
	if(bp08 == 0) {
		lolo.local_32 = "midg.tim";
		C_00674659(4, &lolo.local_31);//rsd:set blend mode?
		D_00E2C414 = C_006710AC(1, DX_SFX_TYPE_0C, &lolo.local_31, lolo.local_32, lolo.local_1->f_910);//dx_sfx:alloc/create?
		D_00E2C3E8 = C_006710AC(1, DX_SFX_TYPE_0A, &lolo.local_31, 0, lolo.local_1->f_910);//dx_sfx:alloc/create?
		lolo.local_32 = "wm_kumo.tim";
		C_00674659(1, &lolo.local_31);//rsd:set blend mode?
		D_00E2C3EC = C_006710AC(1, DX_SFX_TYPE_0C, &lolo.local_31, lolo.local_32, lolo.local_1->f_910);//dx_sfx:alloc/create?
		lolo.local_32 = "meteo.tim";
		D_00E2C3F0 = C_006710AC(1, DX_SFX_TYPE_0C, &lolo.local_31, lolo.local_32, lolo.local_1->f_910);//dx_sfx:alloc/create?
	}
	//-- --
	C_0075A283(bp08);//wmfile:load models?
}

//wmfile:clean textures & models?
void C_0075A921() {
	unsigned i;

	C_00671082(&D_00E2C3DC);//dx_sfx:release "struct t_dx_sfx_e0 **"
	C_00671082(&D_00E2C3D8);//dx_sfx:release "struct t_dx_sfx_e0 **"
	C_00671082(&D_00E2C3E0);//dx_sfx:release "struct t_dx_sfx_e0 **"
	C_00671082(&D_00E2C400);//dx_sfx:release "struct t_dx_sfx_e0 **"
	C_00671082(&D_00E2C404);//dx_sfx:release "struct t_dx_sfx_e0 **"
	C_00671082(&D_00E2C408);//dx_sfx:release "struct t_dx_sfx_e0 **"
	C_00671082(&D_00E2C40C);//dx_sfx:release "struct t_dx_sfx_e0 **"
	C_00671082(&D_00E2C410);//dx_sfx:release "struct t_dx_sfx_e0 **"
	C_00671082(&D_00E2C3E4);//dx_sfx:release "struct t_dx_sfx_e0 **"
	C_00671082(&D_00E2C3F4[0]);//dx_sfx:release "struct t_dx_sfx_e0 **"
	for(i = 0; i < D_00E2C420; i ++) {
		if(C_007592E0(i) == 0) {//wmfile:texture does not exist?
			if(D_00E2BBD8[i])
				C_00671082(&D_00E2BBD8[i]);//dx_sfx:release "struct t_dx_sfx_e0 **"
		} else {
			D_00E2BBD8[i] = 0;
		}
	}
	if(D_00E2C420 == 0x11a) {
		for(i = 0; i < 0x6c; i ++) {
			if(D_00E2C658[i])
				C_00671082(&D_00E2C658[i]);//dx_sfx:release "struct t_dx_sfx_e0 **"
		}
		C_00671082(&D_00E2C414);//dx_sfx:release "struct t_dx_sfx_e0 **"
		C_00671082(&D_00E2C3E8);//dx_sfx:release "struct t_dx_sfx_e0 **"
		C_00671082(&D_00E2C3EC);//dx_sfx:release "struct t_dx_sfx_e0 **"
		C_00671082(&D_00E2C3F0);//dx_sfx:release "struct t_dx_sfx_e0 **"
	} else if(D_00E2C420 == 4) {
		for(i = 0; i < 2; i ++) {
			if(D_00E2C3F4[i + 1])
				C_00671082(&D_00E2C3F4[i + 1]);//dx_sfx:release "struct t_dx_sfx_e0 **"
		}
	}
	D_00E2C41C =
	D_00E2C420 = 0;
}

int __0075AADD(const char *pFileName/*bp08*/, int _bp0c, void *bp10, void (*bp14)()) {
	struct {
		void *local_2;
		int dwSize;//local_1
	}lolo;

	lolo.local_2 = file_allocLoad(&lolo.dwSize, pFileName);
	if(lolo.local_2) {
		C_0041CF10((unsigned char *)lolo.local_2, (unsigned char *)bp10);//some inflate function?
		if(bp14)
			bp14();
		mem_free(lolo.local_2, __FF7FILE__, 0x398);
	}

	return lolo.dwSize;
}

void __0075AB32() {
	D_00E2BBD4 =
	D_00E2D164 = 0;
}
