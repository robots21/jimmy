#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sdlib.h"
#include "Jimmy.h"

/*
 * sdfast generated file, has all kinematics and dynamics for Jimmy. 
 * not intented for human reading.
 */

#define ground (sdgtopo.ground_)
#define nbod (sdgtopo.nbod_)
#define ndof (sdgtopo.ndof_)
#define ncons (sdgtopo.ncons_)
#define nloop (sdgtopo.nloop_)
#define nldof (sdgtopo.nldof_)
#define nloopc (sdgtopo.nloopc_)
#define nball (sdgtopo.nball_)
#define nlball (sdgtopo.nlball_)
#define npres (sdgtopo.npres_)
#define nuser (sdgtopo.nuser_)
#define jtype (sdgtopo.jtype_)
#define inb (sdgtopo.inb_)
#define outb (sdgtopo.outb_)
#define njntdof (sdgtopo.njntdof_)
#define njntc (sdgtopo.njntc_)
#define njntp (sdgtopo.njntp_)
#define firstq (sdgtopo.firstq_)
#define ballq (sdgtopo.ballq_)
#define firstm (sdgtopo.firstm_)
#define firstp (sdgtopo.firstp_)
#define trans (sdgtopo.trans_)
#define grav (sdginput.grav_)
#define mk (sdginput.mk_)
#define ik (sdginput.ik_)
#define pin (sdginput.pin_)
#define rk (sdginput.rk_)
#define ri (sdginput.ri_)
#define pres (sdginput.pres_)
#define stabvel (sdginput.stabvel_)
#define stabpos (sdginput.stabpos_)
#define rhead (sdginput.rhead_)
#define rcom (sdginput.rcom_)
#define psrcomg (sdginput.psrcomg_)
#define psrcom (sdginput.psrcom_)
#define mkrcomt (sdginput.mkrcomt_)
#define psmk (sdginput.psmk_)
#define psik (sdginput.psik_)
#define psrk (sdginput.psrk_)
#define psri (sdginput.psri_)
#define psmkg (sdginput.psmkg_)
#define psikg (sdginput.psikg_)
#define psrkg (sdginput.psrkg_)
#define psrig (sdginput.psrig_)
#define mtot (sdginput.mtot_)
#define mfrcflg (sdginput.mfrcflg_)
#define roustate (sdginput.roustate_)
#define vpkflg (sdginput.vpkflg_)
#define inerflg (sdginput.inerflg_)
#define mmflg (sdginput.mmflg_)
#define mmlduflg (sdginput.mmlduflg_)
#define wwflg (sdginput.wwflg_)
#define ltauflg (sdginput.ltauflg_)
#define fs0flg (sdginput.fs0flg_)
#define ii (sdginput.ii_)
#define mmap (sdginput.mmap_)
#define gravq (sdginput.gravq_)
#define mkq (sdginput.mkq_)
#define ikq (sdginput.ikq_)
#define pinq (sdginput.pinq_)
#define rkq (sdginput.rkq_)
#define riq (sdginput.riq_)
#define presq (sdginput.presq_)
#define stabvelq (sdginput.stabvelq_)
#define stabposq (sdginput.stabposq_)
#define curtim (sdgstate.curtim_)
#define q (sdgstate.q_)
#define qn (sdgstate.qn_)
#define u (sdgstate.u_)
#define cnk (sdgstate.cnk_)
#define cnb (sdgstate.cnb_)
#define rnkg (sdgstate.rnkg_)
#define rnk (sdgstate.rnk_)
#define rnb (sdgstate.rnb_)
#define vnk (sdgstate.vnk_)
#define vnb (sdgstate.vnb_)
#define wk (sdgstate.wk_)
#define wb (sdgstate.wb_)
#define com (sdgstate.com_)
#define Cik (sdgstate.Cik_)
#define Cib (sdgstate.Cib_)
#define rikt (sdgstate.rikt_)
#define Iko (sdgstate.Iko_)
#define mkrk (sdgstate.mkrk_)
#define Wkk (sdgstate.Wkk_)
#define Vkk (sdgstate.Vkk_)
#define dik (sdgstate.dik_)
#define rpp (sdgstate.rpp_)
#define rpk (sdgstate.rpk_)
#define rik (sdgstate.rik_)
#define rik2 (sdgstate.rik2_)
#define rpri (sdgstate.rpri_)
#define Wik (sdgstate.Wik_)
#define Vik (sdgstate.Vik_)
#define Wirk (sdgstate.Wirk_)
#define rkWkk (sdgstate.rkWkk_)
#define Wkrpk (sdgstate.Wkrpk_)
#define VikWkr (sdgstate.VikWkr_)
#define wbrcom (sdgstate.wbrcom_)
#define perr (sdgstate.perr_)
#define verr (sdgstate.verr_)
#define aerr (sdgstate.aerr_)
#define mult (sdgstate.mult_)
#define ufk (sdgstate.ufk_)
#define utk (sdgstate.utk_)
#define utau (sdgstate.utau_)
#define mfk (sdgstate.mfk_)
#define mtk (sdgstate.mtk_)
#define mtau (sdgstate.mtau_)
#define uacc (sdgstate.uacc_)
#define uvel (sdgstate.uvel_)
#define upos (sdgstate.upos_)
#define s6 (sdgstate.s6_)
#define c6 (sdgstate.c6_)
#define s7 (sdgstate.s7_)
#define c7 (sdgstate.c7_)
#define s8 (sdgstate.s8_)
#define c8 (sdgstate.c8_)
#define s9 (sdgstate.s9_)
#define c9 (sdgstate.c9_)
#define s10 (sdgstate.s10_)
#define c10 (sdgstate.c10_)
#define s11 (sdgstate.s11_)
#define c11 (sdgstate.c11_)
#define s12 (sdgstate.s12_)
#define c12 (sdgstate.c12_)
#define s13 (sdgstate.s13_)
#define c13 (sdgstate.c13_)
#define s14 (sdgstate.s14_)
#define c14 (sdgstate.c14_)
#define s15 (sdgstate.s15_)
#define c15 (sdgstate.c15_)
#define s16 (sdgstate.s16_)
#define c16 (sdgstate.c16_)
#define s17 (sdgstate.s17_)
#define c17 (sdgstate.c17_)
#define s18 (sdgstate.s18_)
#define c18 (sdgstate.c18_)
#define s19 (sdgstate.s19_)
#define c19 (sdgstate.c19_)
#define s20 (sdgstate.s20_)
#define c20 (sdgstate.c20_)
#define s21 (sdgstate.s21_)
#define c21 (sdgstate.c21_)
#define s22 (sdgstate.s22_)
#define c22 (sdgstate.c22_)
#define s23 (sdgstate.s23_)
#define c23 (sdgstate.c23_)
#define s24 (sdgstate.s24_)
#define c24 (sdgstate.c24_)
#define s25 (sdgstate.s25_)
#define c25 (sdgstate.c25_)
#define qdot (sdglhs.qdot_)
#define Otk (sdglhs.Otk_)
#define Atk (sdglhs.Atk_)
#define AiOiWi (sdglhs.AiOiWi_)
#define Fstar (sdglhs.Fstar_)
#define Tstar (sdglhs.Tstar_)
#define fs0 (sdglhs.fs0_)
#define Fstark (sdglhs.Fstark_)
#define Tstark (sdglhs.Tstark_)
#define IkWk (sdglhs.IkWk_)
#define IkbWk (sdglhs.IkbWk_)
#define WkIkWk (sdglhs.WkIkWk_)
#define WkIkbWk (sdglhs.WkIkbWk_)
#define gk (sdglhs.gk_)
#define w0w0 (sdglhs.w0w0_)
#define w1w1 (sdglhs.w1w1_)
#define w2w2 (sdglhs.w2w2_)
#define w0w1 (sdglhs.w0w1_)
#define w0w2 (sdglhs.w0w2_)
#define w1w2 (sdglhs.w1w2_)
#define w00w11 (sdglhs.w00w11_)
#define w00w22 (sdglhs.w00w22_)
#define w11w22 (sdglhs.w11w22_)
#define ww (sdglhs.ww_)
#define qraux (sdglhs.qraux_)
#define mm (sdglhs.mm_)
#define mlo (sdglhs.mlo_)
#define mdi (sdglhs.mdi_)
#define IkWpk (sdglhs.IkWpk_)
#define works (sdglhs.works_)
#define workss (sdglhs.workss_)
#define Wpk (sdglhs.Wpk_)
#define Vpk (sdglhs.Vpk_)
#define VWri (sdglhs.VWri_)
#define wmap (sdglhs.wmap_)
#define multmap (sdglhs.multmap_)
#define jpvt (sdglhs.jpvt_)
#define wsiz (sdglhs.wsiz_)
#define wrank (sdglhs.wrank_)
#define fs (sdgrhs.fs_)
#define udot (sdgrhs.udot_)
#define ank (sdgrhs.ank_)
#define anb (sdgrhs.anb_)
#define onk (sdgrhs.onk_)
#define onb (sdgrhs.onb_)
#define Onkb (sdgrhs.Onkb_)
#define AOnkri (sdgrhs.AOnkri_)
#define Ankb (sdgrhs.Ankb_)
#define AnkAtk (sdgrhs.AnkAtk_)
#define dyrcom (sdgrhs.dyrcom_)
#define ffk (sdgrhs.ffk_)
#define ttk (sdgrhs.ttk_)
#define fccikt (sdgrhs.fccikt_)
#define ffkb (sdgrhs.ffkb_)
#define ttkb (sdgrhs.ttkb_)
#define dyad (sdgrhs.dyad_)
#define fc (sdgrhs.fc_)
#define tc (sdgrhs.tc_)
#define tauc (sdgrhs.tauc_)
#define temp (sdgtemp.temp_)
#define tmat1 (sdgtemp.tmat1_)
#define tmat2 (sdgtemp.tmat2_)
#define tvec1 (sdgtemp.tvec1_)
#define tvec2 (sdgtemp.tvec2_)
#define tvec3 (sdgtemp.tvec3_)
#define tvec4 (sdgtemp.tvec4_)
#define tvec5 (sdgtemp.tvec5_)
#define tsc1 (sdgtemp.tsc1_)
#define tsc2 (sdgtemp.tsc2_)
#define tsc3 (sdgtemp.tsc3_)

#define lasterr (sdgerror.lasterr_)
#define lastrou (sdgerror.lastrou_)

Jimmy::Jimmy(){    
    int dof_num=0;
sdgtopo_Jimmy_t sdgtopo_temp = {
/*  Topological information
*/
    /* ground */ 1,
    /* nbod */ 21,
    /* ndof */ 26,
    /* ncons */ 0,
    /* nloop */ 0,
    /* nldof */ 0,
    /* nloopc */ 0,
    /* nball */ 1,
    /* nlball */ 0,
    /* npres */ 0,
    /* nuser */ 0,
    /* jtype[0] */ 6,
    /* jtype[1] */ 1,
    /* jtype[2] */ 1,
    /* jtype[3] */ 1,
    /* jtype[4] */ 1,
    /* jtype[5] */ 1,
    /* jtype[6] */ 1,
    /* jtype[7] */ 1,
    /* jtype[8] */ 1,
    /* jtype[9] */ 1,
    /* jtype[10] */ 1,
    /* jtype[11] */ 1,
    /* jtype[12] */ 1,
    /* jtype[13] */ 1,
    /* jtype[14] */ 1,
    /* jtype[15] */ 1,
    /* jtype[16] */ 1,
    /* jtype[17] */ 1,
    /* jtype[18] */ 1,
    /* jtype[19] */ 1,
    /* jtype[20] */ 1,
    /* inb[0] */ -1,
    /* inb[1] */ 0,
    /* inb[2] */ 1,
    /* inb[3] */ 2,
    /* inb[4] */ 3,
    /* inb[5] */ 4,
    /* inb[6] */ 5,
    /* inb[7] */ 0,
    /* inb[8] */ 7,
    /* inb[9] */ 8,
    /* inb[10] */ 9,
    /* inb[11] */ 10,
    /* inb[12] */ 11,
    /* inb[13] */ 0,
    /* inb[14] */ 13,
    /* inb[15] */ 14,
    /* inb[16] */ 15,
    /* inb[17] */ 0,
    /* inb[18] */ 17,
    /* inb[19] */ 18,
    /* inb[20] */ 19,
    /* outb[0] */ 0,
    /* outb[1] */ 1,
    /* outb[2] */ 2,
    /* outb[3] */ 3,
    /* outb[4] */ 4,
    /* outb[5] */ 5,
    /* outb[6] */ 6,
    /* outb[7] */ 7,
    /* outb[8] */ 8,
    /* outb[9] */ 9,
    /* outb[10] */ 10,
    /* outb[11] */ 11,
    /* outb[12] */ 12,
    /* outb[13] */ 13,
    /* outb[14] */ 14,
    /* outb[15] */ 15,
    /* outb[16] */ 16,
    /* outb[17] */ 17,
    /* outb[18] */ 18,
    /* outb[19] */ 19,
    /* outb[20] */ 20,
    /* njntdof[0] */ 6,
    /* njntdof[1] */ 1,
    /* njntdof[2] */ 1,
    /* njntdof[3] */ 1,
    /* njntdof[4] */ 1,
    /* njntdof[5] */ 1,
    /* njntdof[6] */ 1,
    /* njntdof[7] */ 1,
    /* njntdof[8] */ 1,
    /* njntdof[9] */ 1,
    /* njntdof[10] */ 1,
    /* njntdof[11] */ 1,
    /* njntdof[12] */ 1,
    /* njntdof[13] */ 1,
    /* njntdof[14] */ 1,
    /* njntdof[15] */ 1,
    /* njntdof[16] */ 1,
    /* njntdof[17] */ 1,
    /* njntdof[18] */ 1,
    /* njntdof[19] */ 1,
    /* njntdof[20] */ 1,
    /* njntc[0] */ 0,
    /* njntc[1] */ 0,
    /* njntc[2] */ 0,
    /* njntc[3] */ 0,
    /* njntc[4] */ 0,
    /* njntc[5] */ 0,
    /* njntc[6] */ 0,
    /* njntc[7] */ 0,
    /* njntc[8] */ 0,
    /* njntc[9] */ 0,
    /* njntc[10] */ 0,
    /* njntc[11] */ 0,
    /* njntc[12] */ 0,
    /* njntc[13] */ 0,
    /* njntc[14] */ 0,
    /* njntc[15] */ 0,
    /* njntc[16] */ 0,
    /* njntc[17] */ 0,
    /* njntc[18] */ 0,
    /* njntc[19] */ 0,
    /* njntc[20] */ 0,
    /* njntp[0] */ 0,
    /* njntp[1] */ 0,
    /* njntp[2] */ 0,
    /* njntp[3] */ 0,
    /* njntp[4] */ 0,
    /* njntp[5] */ 0,
    /* njntp[6] */ 0,
    /* njntp[7] */ 0,
    /* njntp[8] */ 0,
    /* njntp[9] */ 0,
    /* njntp[10] */ 0,
    /* njntp[11] */ 0,
    /* njntp[12] */ 0,
    /* njntp[13] */ 0,
    /* njntp[14] */ 0,
    /* njntp[15] */ 0,
    /* njntp[16] */ 0,
    /* njntp[17] */ 0,
    /* njntp[18] */ 0,
    /* njntp[19] */ 0,
    /* njntp[20] */ 0,
    /* firstq[0] */ 0,
    /* firstq[1] */ 6,
    /* firstq[2] */ 7,
    /* firstq[3] */ 8,
    /* firstq[4] */ 9,
    /* firstq[5] */ 10,
    /* firstq[6] */ 11,
    /* firstq[7] */ 12,
    /* firstq[8] */ 13,
    /* firstq[9] */ 14,
    /* firstq[10] */ 15,
    /* firstq[11] */ 16,
    /* firstq[12] */ 17,
    /* firstq[13] */ 18,
    /* firstq[14] */ 19,
    /* firstq[15] */ 20,
    /* firstq[16] */ 21,
    /* firstq[17] */ 22,
    /* firstq[18] */ 23,
    /* firstq[19] */ 24,
    /* firstq[20] */ 25,
    /* ballq[0] */ 26,
    /* ballq[1] */ -104,
    /* ballq[2] */ -104,
    /* ballq[3] */ -104,
    /* ballq[4] */ -104,
    /* ballq[5] */ -104,
    /* ballq[6] */ -104,
    /* ballq[7] */ -104,
    /* ballq[8] */ -104,
    /* ballq[9] */ -104,
    /* ballq[10] */ -104,
    /* ballq[11] */ -104,
    /* ballq[12] */ -104,
    /* ballq[13] */ -104,
    /* ballq[14] */ -104,
    /* ballq[15] */ -104,
    /* ballq[16] */ -104,
    /* ballq[17] */ -104,
    /* ballq[18] */ -104,
    /* ballq[19] */ -104,
    /* ballq[20] */ -104,
    /* firstm[0] */ -1,
    /* firstm[1] */ -1,
    /* firstm[2] */ -1,
    /* firstm[3] */ -1,
    /* firstm[4] */ -1,
    /* firstm[5] */ -1,
    /* firstm[6] */ -1,
    /* firstm[7] */ -1,
    /* firstm[8] */ -1,
    /* firstm[9] */ -1,
    /* firstm[10] */ -1,
    /* firstm[11] */ -1,
    /* firstm[12] */ -1,
    /* firstm[13] */ -1,
    /* firstm[14] */ -1,
    /* firstm[15] */ -1,
    /* firstm[16] */ -1,
    /* firstm[17] */ -1,
    /* firstm[18] */ -1,
    /* firstm[19] */ -1,
    /* firstm[20] */ -1,
    /* firstp[0] */ -1,
    /* firstp[1] */ -1,
    /* firstp[2] */ -1,
    /* firstp[3] */ -1,
    /* firstp[4] */ -1,
    /* firstp[5] */ -1,
    /* firstp[6] */ -1,
    /* firstp[7] */ -1,
    /* firstp[8] */ -1,
    /* firstp[9] */ -1,
    /* firstp[10] */ -1,
    /* firstp[11] */ -1,
    /* firstp[12] */ -1,
    /* firstp[13] */ -1,
    /* firstp[14] */ -1,
    /* firstp[15] */ -1,
    /* firstp[16] */ -1,
    /* firstp[17] */ -1,
    /* firstp[18] */ -1,
    /* firstp[19] */ -1,
    /* firstp[20] */ -1,
    /* trans[0] */ 1,
    /* trans[1] */ 1,
    /* trans[2] */ 1,
    /* trans[3] */ 0,
    /* trans[4] */ 0,
    /* trans[5] */ 0,
    /* trans[6] */ 0,
    /* trans[7] */ 0,
    /* trans[8] */ 0,
    /* trans[9] */ 0,
    /* trans[10] */ 0,
    /* trans[11] */ 0,
    /* trans[12] */ 0,
    /* trans[13] */ 0,
    /* trans[14] */ 0,
    /* trans[15] */ 0,
    /* trans[16] */ 0,
    /* trans[17] */ 0,
    /* trans[18] */ 0,
    /* trans[19] */ 0,
    /* trans[20] */ 0,
    /* trans[21] */ 0,
    /* trans[22] */ 0,
    /* trans[23] */ 0,
    /* trans[24] */ 0,
    /* trans[25] */ 0,
};
sdginput_Jimmy_t sdginput_temp = {
/* Model parameters from the input file */

/* gravity */
    /* grav[0] */ 0.,
    /* grav[1] */ 0.,
    /* grav[2] */ -9.81,

/* mass */
    /* mk[0] */ 4.091,
    /* mk[1] */ .016,
    /* mk[2] */ .308,
    /* mk[3] */ .363,
    /* mk[4] */ .354,
    /* mk[5] */ .308,
    /* mk[6] */ .746,
    /* mk[7] */ .016,
    /* mk[8] */ .308,
    /* mk[9] */ .363,
    /* mk[10] */ .354,
    /* mk[11] */ .308,
    /* mk[12] */ .746,
    /* mk[13] */ .096,
    /* mk[14] */ .451,
    /* mk[15] */ .061,
    /* mk[16] */ .274,
    /* mk[17] */ .096,
    /* mk[18] */ .451,
    /* mk[19] */ .061,
    /* mk[20] */ .274,

/* inertia */
    /* ik[0][0][0] */ .1267,
    /* ik[0][0][1] */ 0.,
    /* ik[0][0][2] */ -.004,
    /* ik[0][1][0] */ 0.,
    /* ik[0][1][1] */ .1239,
    /* ik[0][1][2] */ 0.,
    /* ik[0][2][0] */ -.004,
    /* ik[0][2][1] */ 0.,
    /* ik[0][2][2] */ .026,
    /* ik[1][0][0] */ 3e-5,
    /* ik[1][0][1] */ 0.,
    /* ik[1][0][2] */ 0.,
    /* ik[1][1][0] */ 0.,
    /* ik[1][1][1] */ .0001,
    /* ik[1][1][2] */ 0.,
    /* ik[1][2][0] */ 0.,
    /* ik[1][2][1] */ 0.,
    /* ik[1][2][2] */ 3e-5,
    /* ik[2][0][0] */ .00031,
    /* ik[2][0][1] */ 0.,
    /* ik[2][0][2] */ 0.,
    /* ik[2][1][0] */ 0.,
    /* ik[2][1][1] */ .00016,
    /* ik[2][1][2] */ 0.,
    /* ik[2][2][0] */ 0.,
    /* ik[2][2][1] */ 0.,
    /* ik[2][2][2] */ .00026,
    /* ik[3][0][0] */ .00216,
    /* ik[3][0][1] */ 0.,
    /* ik[3][0][2] */ -4e-5,
    /* ik[3][1][0] */ 0.,
    /* ik[3][1][1] */ .00239,
    /* ik[3][1][2] */ -.00011,
    /* ik[3][2][0] */ -4e-5,
    /* ik[3][2][1] */ -.00011,
    /* ik[3][2][2] */ .00061,
    /* ik[4][0][0] */ .00122,
    /* ik[4][0][1] */ 0.,
    /* ik[4][0][2] */ 2e-5,
    /* ik[4][1][0] */ 0.,
    /* ik[4][1][1] */ .00116,
    /* ik[4][1][2] */ 0.,
    /* ik[4][2][0] */ 2e-5,
    /* ik[4][2][1] */ 0.,
    /* ik[4][2][2] */ .00027,
    /* ik[5][0][0] */ .00016,
    /* ik[5][0][1] */ 0.,
    /* ik[5][0][2] */ 0.,
    /* ik[5][1][0] */ 0.,
    /* ik[5][1][1] */ .00031,
    /* ik[5][1][2] */ 0.,
    /* ik[5][2][0] */ 0.,
    /* ik[5][2][1] */ 0.,
    /* ik[5][2][2] */ .00026,
    /* ik[6][0][0] */ .00113,
    /* ik[6][0][1] */ 0.,
    /* ik[6][0][2] */ -.00015,
    /* ik[6][1][0] */ 0.,
    /* ik[6][1][1] */ .00538,
    /* ik[6][1][2] */ 0.,
    /* ik[6][2][0] */ -.00015,
    /* ik[6][2][1] */ 0.,
    /* ik[6][2][2] */ .00578,
    /* ik[7][0][0] */ 3e-5,
    /* ik[7][0][1] */ 0.,
    /* ik[7][0][2] */ 0.,
    /* ik[7][1][0] */ 0.,
    /* ik[7][1][1] */ .0001,
    /* ik[7][1][2] */ 0.,
    /* ik[7][2][0] */ 0.,
    /* ik[7][2][1] */ 0.,
    /* ik[7][2][2] */ 3e-5,
    /* ik[8][0][0] */ .00031,
    /* ik[8][0][1] */ 0.,
    /* ik[8][0][2] */ 0.,
    /* ik[8][1][0] */ 0.,
    /* ik[8][1][1] */ .00016,
    /* ik[8][1][2] */ 0.,
    /* ik[8][2][0] */ 0.,
    /* ik[8][2][1] */ 0.,
    /* ik[8][2][2] */ .00026,
    /* ik[9][0][0] */ .00216,
    /* ik[9][0][1] */ 0.,
    /* ik[9][0][2] */ -4e-5,
    /* ik[9][1][0] */ 0.,
    /* ik[9][1][1] */ .00239,
    /* ik[9][1][2] */ -.00011,
    /* ik[9][2][0] */ -4e-5,
    /* ik[9][2][1] */ -.00011,
    /* ik[9][2][2] */ .00061,
    /* ik[10][0][0] */ .00122,
    /* ik[10][0][1] */ 0.,
    /* ik[10][0][2] */ 2e-5,
    /* ik[10][1][0] */ 0.,
    /* ik[10][1][1] */ .00116,
    /* ik[10][1][2] */ 0.,
    /* ik[10][2][0] */ 2e-5,
    /* ik[10][2][1] */ 0.,
    /* ik[10][2][2] */ .00027,
    /* ik[11][0][0] */ .00016,
    /* ik[11][0][1] */ 0.,
    /* ik[11][0][2] */ 0.,
    /* ik[11][1][0] */ 0.,
    /* ik[11][1][1] */ .00031,
    /* ik[11][1][2] */ 0.,
    /* ik[11][2][0] */ 0.,
    /* ik[11][2][1] */ 0.,
    /* ik[11][2][2] */ .00026,
    /* ik[12][0][0] */ .00113,
    /* ik[12][0][1] */ 0.,
    /* ik[12][0][2] */ -.00015,
    /* ik[12][1][0] */ 0.,
    /* ik[12][1][1] */ .00538,
    /* ik[12][1][2] */ 0.,
    /* ik[12][2][0] */ -.00015,
    /* ik[12][2][1] */ 0.,
    /* ik[12][2][2] */ .00578,
    /* ik[13][0][0] */ 7e-5,
    /* ik[13][0][1] */ 0.,
    /* ik[13][0][2] */ 0.,
    /* ik[13][1][0] */ 0.,
    /* ik[13][1][1] */ .0001,
    /* ik[13][1][2] */ 0.,
    /* ik[13][2][0] */ 0.,
    /* ik[13][2][1] */ 0.,
    /* ik[13][2][2] */ .00011,
    /* ik[14][0][0] */ .00092,
    /* ik[14][0][1] */ 0.,
    /* ik[14][0][2] */ 0.,
    /* ik[14][1][0] */ 0.,
    /* ik[14][1][1] */ .00018,
    /* ik[14][1][2] */ 0.,
    /* ik[14][2][0] */ 0.,
    /* ik[14][2][1] */ 0.,
    /* ik[14][2][2] */ .00095,
    /* ik[15][0][0] */ 6e-5,
    /* ik[15][0][1] */ -1e-5,
    /* ik[15][0][2] */ 0.,
    /* ik[15][1][0] */ -1e-5,
    /* ik[15][1][1] */ 5e-5,
    /* ik[15][1][2] */ 0.,
    /* ik[15][2][0] */ 0.,
    /* ik[15][2][1] */ 0.,
    /* ik[15][2][2] */ 3e-5,
    /* ik[16][0][0] */ .0015,
    /* ik[16][0][1] */ -1e-5,
    /* ik[16][0][2] */ 0.,
    /* ik[16][1][0] */ -1e-5,
    /* ik[16][1][1] */ .00016,
    /* ik[16][1][2] */ -5e-5,
    /* ik[16][2][0] */ 0.,
    /* ik[16][2][1] */ -5e-5,
    /* ik[16][2][2] */ .0015,
    /* ik[17][0][0] */ 7e-5,
    /* ik[17][0][1] */ 0.,
    /* ik[17][0][2] */ 0.,
    /* ik[17][1][0] */ 0.,
    /* ik[17][1][1] */ .0001,
    /* ik[17][1][2] */ 0.,
    /* ik[17][2][0] */ 0.,
    /* ik[17][2][1] */ 0.,
    /* ik[17][2][2] */ .00011,
    /* ik[18][0][0] */ .00092,
    /* ik[18][0][1] */ 0.,
    /* ik[18][0][2] */ 0.,
    /* ik[18][1][0] */ 0.,
    /* ik[18][1][1] */ .00018,
    /* ik[18][1][2] */ 0.,
    /* ik[18][2][0] */ 0.,
    /* ik[18][2][1] */ 0.,
    /* ik[18][2][2] */ .00095,
    /* ik[19][0][0] */ 6e-5,
    /* ik[19][0][1] */ -1e-5,
    /* ik[19][0][2] */ 0.,
    /* ik[19][1][0] */ -1e-5,
    /* ik[19][1][1] */ 5e-5,
    /* ik[19][1][2] */ 0.,
    /* ik[19][2][0] */ 0.,
    /* ik[19][2][1] */ 0.,
    /* ik[19][2][2] */ 3e-5,
    /* ik[20][0][0] */ .0015,
    /* ik[20][0][1] */ -1e-5,
    /* ik[20][0][2] */ 0.,
    /* ik[20][1][0] */ -1e-5,
    /* ik[20][1][1] */ .00016,
    /* ik[20][1][2] */ -5e-5,
    /* ik[20][2][0] */ 0.,
    /* ik[20][2][1] */ -5e-5,
    /* ik[20][2][2] */ .0015,

/* tree hinge axis vectors */
    /* pin[0][0] */ 1.,
    /* pin[0][1] */ 0.,
    /* pin[0][2] */ 0.,
    /* pin[1][0] */ 0.,
    /* pin[1][1] */ 1.,
    /* pin[1][2] */ 0.,
    /* pin[2][0] */ 0.,
    /* pin[2][1] */ 0.,
    /* pin[2][2] */ 1.,
    /* pin[3][0] */ 0.,
    /* pin[3][1] */ 0.,
    /* pin[3][2] */ 0.,
    /* pin[4][0] */ 0.,
    /* pin[4][1] */ 0.,
    /* pin[4][2] */ 0.,
    /* pin[5][0] */ 0.,
    /* pin[5][1] */ 0.,
    /* pin[5][2] */ 0.,
    /* pin[6][0] */ 0.,
    /* pin[6][1] */ 0.,
    /* pin[6][2] */ 1.,
    /* pin[7][0] */ 0.,
    /* pin[7][1] */ 1.,
    /* pin[7][2] */ 0.,
    /* pin[8][0] */ 1.,
    /* pin[8][1] */ 0.,
    /* pin[8][2] */ 0.,
    /* pin[9][0] */ 0.,
    /* pin[9][1] */ 1.,
    /* pin[9][2] */ 0.,
    /* pin[10][0] */ 0.,
    /* pin[10][1] */ 1.,
    /* pin[10][2] */ 0.,
    /* pin[11][0] */ 1.,
    /* pin[11][1] */ 0.,
    /* pin[11][2] */ 0.,
    /* pin[12][0] */ 0.,
    /* pin[12][1] */ 0.,
    /* pin[12][2] */ 1.,
    /* pin[13][0] */ 0.,
    /* pin[13][1] */ 1.,
    /* pin[13][2] */ 0.,
    /* pin[14][0] */ 1.,
    /* pin[14][1] */ 0.,
    /* pin[14][2] */ 0.,
    /* pin[15][0] */ 0.,
    /* pin[15][1] */ 1.,
    /* pin[15][2] */ 0.,
    /* pin[16][0] */ 0.,
    /* pin[16][1] */ 1.,
    /* pin[16][2] */ 0.,
    /* pin[17][0] */ 1.,
    /* pin[17][1] */ 0.,
    /* pin[17][2] */ 0.,
    /* pin[18][0] */ 0.,
    /* pin[18][1] */ 1.,
    /* pin[18][2] */ 0.,
    /* pin[19][0] */ 1.,
    /* pin[19][1] */ 0.,
    /* pin[19][2] */ 0.,
    /* pin[20][0] */ 0.,
    /* pin[20][1] */ 1.,
    /* pin[20][2] */ 0.,
    /* pin[21][0] */ 0.,
    /* pin[21][1] */ 0.,
    /* pin[21][2] */ 1.,
    /* pin[22][0] */ 0.,
    /* pin[22][1] */ 1.,
    /* pin[22][2] */ 0.,
    /* pin[23][0] */ 1.,
    /* pin[23][1] */ 0.,
    /* pin[23][2] */ 0.,
    /* pin[24][0] */ 0.,
    /* pin[24][1] */ 1.,
    /* pin[24][2] */ 0.,
    /* pin[25][0] */ 0.,
    /* pin[25][1] */ 0.,
    /* pin[25][2] */ 1.,

/* tree bodytojoint vectors */
    /* rk[0][0] */ -.001,
    /* rk[0][1] */ 0.,
    /* rk[0][2] */ -.298,
    /* rk[1][0] */ 0.,
    /* rk[1][1] */ .017,
    /* rk[1][2] */ -.024,
    /* rk[2][0] */ 0.,
    /* rk[2][1] */ .021,
    /* rk[2][2] */ .016,
    /* rk[3][0] */ -.002,
    /* rk[3][1] */ -.039,
    /* rk[3][2] */ .066,
    /* rk[4][0] */ .002,
    /* rk[4][1] */ 0.,
    /* rk[4][2] */ .062,
    /* rk[5][0] */ .021,
    /* rk[5][1] */ 0.,
    /* rk[5][2] */ .016,
    /* rk[6][0] */ -.017,
    /* rk[6][1] */ 0.,
    /* rk[6][2] */ .064,
    /* rk[7][0] */ 0.,
    /* rk[7][1] */ -.017,
    /* rk[7][2] */ -.024,
    /* rk[8][0] */ 0.,
    /* rk[8][1] */ -.021,
    /* rk[8][2] */ .016,
    /* rk[9][0] */ -.002,
    /* rk[9][1] */ .039,
    /* rk[9][2] */ .066,
    /* rk[10][0] */ .002,
    /* rk[10][1] */ 0.,
    /* rk[10][2] */ .062,
    /* rk[11][0] */ .021,
    /* rk[11][1] */ 0.,
    /* rk[11][2] */ .016,
    /* rk[12][0] */ -.017,
    /* rk[12][1] */ 0.,
    /* rk[12][2] */ .064,
    /* rk[13][0] */ 0.,
    /* rk[13][1] */ .009,
    /* rk[13][2] */ -.006,
    /* rk[14][0] */ 0.,
    /* rk[14][1] */ -.063,
    /* rk[14][2] */ 0.,
    /* rk[15][0] */ -.009,
    /* rk[15][1] */ -.154,
    /* rk[15][2] */ 0.,
    /* rk[16][0] */ 0.,
    /* rk[16][1] */ -.072,
    /* rk[16][2] */ -.001,
    /* rk[17][0] */ 0.,
    /* rk[17][1] */ -.009,
    /* rk[17][2] */ -.006,
    /* rk[18][0] */ 0.,
    /* rk[18][1] */ .063,
    /* rk[18][2] */ 0.,
    /* rk[19][0] */ -.009,
    /* rk[19][1] */ .154,
    /* rk[19][2] */ 0.,
    /* rk[20][0] */ 0.,
    /* rk[20][1] */ .072,
    /* rk[20][2] */ -.001,

/* tree inbtojoint vectors */
    /* ri[0][0] */ 0.,
    /* ri[0][1] */ 0.,
    /* ri[0][2] */ 0.,
    /* ri[1][0] */ -.001,
    /* ri[1][1] */ .083,
    /* ri[1][2] */ -.298,
    /* ri[2][0] */ 0.,
    /* ri[2][1] */ .017,
    /* ri[2][2] */ -.024,
    /* ri[3][0] */ 0.,
    /* ri[3][1] */ .021,
    /* ri[3][2] */ .016,
    /* ri[4][0] */ -.002,
    /* ri[4][1] */ -.007,
    /* ri[4][2] */ -.11,
    /* ri[5][0] */ .002,
    /* ri[5][1] */ 0.,
    /* ri[5][2] */ -.094,
    /* ri[6][0] */ .021,
    /* ri[6][1] */ 0.,
    /* ri[6][2] */ .016,
    /* ri[7][0] */ -.001,
    /* ri[7][1] */ -.083,
    /* ri[7][2] */ -.298,
    /* ri[8][0] */ 0.,
    /* ri[8][1] */ -.017,
    /* ri[8][2] */ -.024,
    /* ri[9][0] */ 0.,
    /* ri[9][1] */ -.021,
    /* ri[9][2] */ .016,
    /* ri[10][0] */ -.002,
    /* ri[10][1] */ .007,
    /* ri[10][2] */ -.11,
    /* ri[11][0] */ .002,
    /* ri[11][1] */ 0.,
    /* ri[11][2] */ -.094,
    /* ri[12][0] */ .021,
    /* ri[12][1] */ 0.,
    /* ri[12][2] */ .016,
    /* ri[13][0] */ -.001,
    /* ri[13][1] */ .095,
    /* ri[13][2] */ -.044,
    /* ri[14][0] */ 0.,
    /* ri[14][1] */ .009,
    /* ri[14][2] */ -.006,
    /* ri[15][0] */ 0.,
    /* ri[15][1] */ -.063,
    /* ri[15][2] */ 0.,
    /* ri[16][0] */ .007,
    /* ri[16][1] */ .013,
    /* ri[16][2] */ 0.,
    /* ri[17][0] */ -.001,
    /* ri[17][1] */ -.095,
    /* ri[17][2] */ -.044,
    /* ri[18][0] */ 0.,
    /* ri[18][1] */ -.009,
    /* ri[18][2] */ -.006,
    /* ri[19][0] */ 0.,
    /* ri[19][1] */ .063,
    /* ri[19][2] */ 0.,
    /* ri[20][0] */ .007,
    /* ri[20][1] */ -.013,
    /* ri[20][2] */ 0.,

/* tree prescribed motion */
    /* pres[0] */ 0.,
    /* pres[1] */ 0.,
    /* pres[2] */ 0.,
    /* pres[3] */ 0.,
    /* pres[4] */ 0.,
    /* pres[5] */ 0.,
    /* pres[6] */ 0.,
    /* pres[7] */ 0.,
    /* pres[8] */ 0.,
    /* pres[9] */ 0.,
    /* pres[10] */ 0.,
    /* pres[11] */ 0.,
    /* pres[12] */ 0.,
    /* pres[13] */ 0.,
    /* pres[14] */ 0.,
    /* pres[15] */ 0.,
    /* pres[16] */ 0.,
    /* pres[17] */ 0.,
    /* pres[18] */ 0.,
    /* pres[19] */ 0.,
    /* pres[20] */ 0.,
    /* pres[21] */ 0.,
    /* pres[22] */ 0.,
    /* pres[23] */ 0.,
    /* pres[24] */ 0.,
    /* pres[25] */ 0.,

/* stabilization parameters */
    /* stabvel */ 0.,
    /* stabpos */ 0.,

/* miscellaneous */
    /* mfrcflg */ 0,
    /* roustate */ 0,
    /* vpkflg */ 0,
    /* inerflg */ 0,
    /* mmflg */ 0,
    /* mmlduflg */ 0,
    /* wwflg */ 0,
    /* ltauflg */ 0,
    /* fs0flg */ 0,
    /* ii */ 0,
    /* mmap[0] */ 0,
    /* mmap[1] */ 1,
    /* mmap[2] */ 2,
    /* mmap[3] */ 3,
    /* mmap[4] */ 4,
    /* mmap[5] */ 5,
    /* mmap[6] */ 6,
    /* mmap[7] */ 7,
    /* mmap[8] */ 8,
    /* mmap[9] */ 9,
    /* mmap[10] */ 10,
    /* mmap[11] */ 11,
    /* mmap[12] */ 12,
    /* mmap[13] */ 13,
    /* mmap[14] */ 14,
    /* mmap[15] */ 15,
    /* mmap[16] */ 16,
    /* mmap[17] */ 17,
    /* mmap[18] */ 18,
    /* mmap[19] */ 19,
    /* mmap[20] */ 20,
    /* mmap[21] */ 21,
    /* mmap[22] */ 22,
    /* mmap[23] */ 23,
    /* mmap[24] */ 24,
    /* mmap[25] */ 25,

/* Which parameters were "?" (1) or "<nominal>?" (3) */
    /* gravq[0] */ 0,
    /* gravq[1] */ 0,
    /* gravq[2] */ 0,
    /* mkq[0] */ 3,
    /* mkq[1] */ 3,
    /* mkq[2] */ 3,
    /* mkq[3] */ 3,
    /* mkq[4] */ 3,
    /* mkq[5] */ 3,
    /* mkq[6] */ 3,
    /* mkq[7] */ 3,
    /* mkq[8] */ 3,
    /* mkq[9] */ 3,
    /* mkq[10] */ 3,
    /* mkq[11] */ 3,
    /* mkq[12] */ 3,
    /* mkq[13] */ 3,
    /* mkq[14] */ 3,
    /* mkq[15] */ 3,
    /* mkq[16] */ 3,
    /* mkq[17] */ 3,
    /* mkq[18] */ 3,
    /* mkq[19] */ 3,
    /* mkq[20] */ 3,
    /* ikq[0][0][0] */ 3,
    /* ikq[0][0][1] */ 3,
    /* ikq[0][0][2] */ 3,
    /* ikq[0][1][0] */ 3,
    /* ikq[0][1][1] */ 3,
    /* ikq[0][1][2] */ 3,
    /* ikq[0][2][0] */ 3,
    /* ikq[0][2][1] */ 3,
    /* ikq[0][2][2] */ 3,
    /* ikq[1][0][0] */ 3,
    /* ikq[1][0][1] */ 3,
    /* ikq[1][0][2] */ 3,
    /* ikq[1][1][0] */ 3,
    /* ikq[1][1][1] */ 3,
    /* ikq[1][1][2] */ 3,
    /* ikq[1][2][0] */ 3,
    /* ikq[1][2][1] */ 3,
    /* ikq[1][2][2] */ 3,
    /* ikq[2][0][0] */ 3,
    /* ikq[2][0][1] */ 3,
    /* ikq[2][0][2] */ 3,
    /* ikq[2][1][0] */ 3,
    /* ikq[2][1][1] */ 3,
    /* ikq[2][1][2] */ 3,
    /* ikq[2][2][0] */ 3,
    /* ikq[2][2][1] */ 3,
    /* ikq[2][2][2] */ 3,
    /* ikq[3][0][0] */ 3,
    /* ikq[3][0][1] */ 3,
    /* ikq[3][0][2] */ 3,
    /* ikq[3][1][0] */ 3,
    /* ikq[3][1][1] */ 3,
    /* ikq[3][1][2] */ 3,
    /* ikq[3][2][0] */ 3,
    /* ikq[3][2][1] */ 3,
    /* ikq[3][2][2] */ 3,
    /* ikq[4][0][0] */ 3,
    /* ikq[4][0][1] */ 3,
    /* ikq[4][0][2] */ 3,
    /* ikq[4][1][0] */ 3,
    /* ikq[4][1][1] */ 3,
    /* ikq[4][1][2] */ 3,
    /* ikq[4][2][0] */ 3,
    /* ikq[4][2][1] */ 3,
    /* ikq[4][2][2] */ 3,
    /* ikq[5][0][0] */ 3,
    /* ikq[5][0][1] */ 3,
    /* ikq[5][0][2] */ 3,
    /* ikq[5][1][0] */ 3,
    /* ikq[5][1][1] */ 3,
    /* ikq[5][1][2] */ 3,
    /* ikq[5][2][0] */ 3,
    /* ikq[5][2][1] */ 3,
    /* ikq[5][2][2] */ 3,
    /* ikq[6][0][0] */ 3,
    /* ikq[6][0][1] */ 3,
    /* ikq[6][0][2] */ 3,
    /* ikq[6][1][0] */ 3,
    /* ikq[6][1][1] */ 3,
    /* ikq[6][1][2] */ 3,
    /* ikq[6][2][0] */ 3,
    /* ikq[6][2][1] */ 3,
    /* ikq[6][2][2] */ 3,
    /* ikq[7][0][0] */ 3,
    /* ikq[7][0][1] */ 3,
    /* ikq[7][0][2] */ 3,
    /* ikq[7][1][0] */ 3,
    /* ikq[7][1][1] */ 3,
    /* ikq[7][1][2] */ 3,
    /* ikq[7][2][0] */ 3,
    /* ikq[7][2][1] */ 3,
    /* ikq[7][2][2] */ 3,
    /* ikq[8][0][0] */ 3,
    /* ikq[8][0][1] */ 3,
    /* ikq[8][0][2] */ 3,
    /* ikq[8][1][0] */ 3,
    /* ikq[8][1][1] */ 3,
    /* ikq[8][1][2] */ 3,
    /* ikq[8][2][0] */ 3,
    /* ikq[8][2][1] */ 3,
    /* ikq[8][2][2] */ 3,
    /* ikq[9][0][0] */ 3,
    /* ikq[9][0][1] */ 3,
    /* ikq[9][0][2] */ 3,
    /* ikq[9][1][0] */ 3,
    /* ikq[9][1][1] */ 3,
    /* ikq[9][1][2] */ 3,
    /* ikq[9][2][0] */ 3,
    /* ikq[9][2][1] */ 3,
    /* ikq[9][2][2] */ 3,
    /* ikq[10][0][0] */ 3,
    /* ikq[10][0][1] */ 3,
    /* ikq[10][0][2] */ 3,
    /* ikq[10][1][0] */ 3,
    /* ikq[10][1][1] */ 3,
    /* ikq[10][1][2] */ 3,
    /* ikq[10][2][0] */ 3,
    /* ikq[10][2][1] */ 3,
    /* ikq[10][2][2] */ 3,
    /* ikq[11][0][0] */ 3,
    /* ikq[11][0][1] */ 3,
    /* ikq[11][0][2] */ 3,
    /* ikq[11][1][0] */ 3,
    /* ikq[11][1][1] */ 3,
    /* ikq[11][1][2] */ 3,
    /* ikq[11][2][0] */ 3,
    /* ikq[11][2][1] */ 3,
    /* ikq[11][2][2] */ 3,
    /* ikq[12][0][0] */ 3,
    /* ikq[12][0][1] */ 3,
    /* ikq[12][0][2] */ 3,
    /* ikq[12][1][0] */ 3,
    /* ikq[12][1][1] */ 3,
    /* ikq[12][1][2] */ 3,
    /* ikq[12][2][0] */ 3,
    /* ikq[12][2][1] */ 3,
    /* ikq[12][2][2] */ 3,
    /* ikq[13][0][0] */ 3,
    /* ikq[13][0][1] */ 3,
    /* ikq[13][0][2] */ 3,
    /* ikq[13][1][0] */ 3,
    /* ikq[13][1][1] */ 3,
    /* ikq[13][1][2] */ 3,
    /* ikq[13][2][0] */ 3,
    /* ikq[13][2][1] */ 3,
    /* ikq[13][2][2] */ 3,
    /* ikq[14][0][0] */ 3,
    /* ikq[14][0][1] */ 3,
    /* ikq[14][0][2] */ 3,
    /* ikq[14][1][0] */ 3,
    /* ikq[14][1][1] */ 3,
    /* ikq[14][1][2] */ 3,
    /* ikq[14][2][0] */ 3,
    /* ikq[14][2][1] */ 3,
    /* ikq[14][2][2] */ 3,
    /* ikq[15][0][0] */ 3,
    /* ikq[15][0][1] */ 3,
    /* ikq[15][0][2] */ 3,
    /* ikq[15][1][0] */ 3,
    /* ikq[15][1][1] */ 3,
    /* ikq[15][1][2] */ 3,
    /* ikq[15][2][0] */ 3,
    /* ikq[15][2][1] */ 3,
    /* ikq[15][2][2] */ 3,
    /* ikq[16][0][0] */ 3,
    /* ikq[16][0][1] */ 3,
    /* ikq[16][0][2] */ 3,
    /* ikq[16][1][0] */ 3,
    /* ikq[16][1][1] */ 3,
    /* ikq[16][1][2] */ 3,
    /* ikq[16][2][0] */ 3,
    /* ikq[16][2][1] */ 3,
    /* ikq[16][2][2] */ 3,
    /* ikq[17][0][0] */ 3,
    /* ikq[17][0][1] */ 3,
    /* ikq[17][0][2] */ 3,
    /* ikq[17][1][0] */ 3,
    /* ikq[17][1][1] */ 3,
    /* ikq[17][1][2] */ 3,
    /* ikq[17][2][0] */ 3,
    /* ikq[17][2][1] */ 3,
    /* ikq[17][2][2] */ 3,
    /* ikq[18][0][0] */ 3,
    /* ikq[18][0][1] */ 3,
    /* ikq[18][0][2] */ 3,
    /* ikq[18][1][0] */ 3,
    /* ikq[18][1][1] */ 3,
    /* ikq[18][1][2] */ 3,
    /* ikq[18][2][0] */ 3,
    /* ikq[18][2][1] */ 3,
    /* ikq[18][2][2] */ 3,
    /* ikq[19][0][0] */ 3,
    /* ikq[19][0][1] */ 3,
    /* ikq[19][0][2] */ 3,
    /* ikq[19][1][0] */ 3,
    /* ikq[19][1][1] */ 3,
    /* ikq[19][1][2] */ 3,
    /* ikq[19][2][0] */ 3,
    /* ikq[19][2][1] */ 3,
    /* ikq[19][2][2] */ 3,
    /* ikq[20][0][0] */ 3,
    /* ikq[20][0][1] */ 3,
    /* ikq[20][0][2] */ 3,
    /* ikq[20][1][0] */ 3,
    /* ikq[20][1][1] */ 3,
    /* ikq[20][1][2] */ 3,
    /* ikq[20][2][0] */ 3,
    /* ikq[20][2][1] */ 3,
    /* ikq[20][2][2] */ 3,
    /* pinq[0][0] */ 0,
    /* pinq[0][1] */ 0,
    /* pinq[0][2] */ 0,
    /* pinq[1][0] */ 0,
    /* pinq[1][1] */ 0,
    /* pinq[1][2] */ 0,
    /* pinq[2][0] */ 0,
    /* pinq[2][1] */ 0,
    /* pinq[2][2] */ 0,
    /* pinq[3][0] */ 0,
    /* pinq[3][1] */ 0,
    /* pinq[3][2] */ 0,
    /* pinq[4][0] */ 0,
    /* pinq[4][1] */ 0,
    /* pinq[4][2] */ 0,
    /* pinq[5][0] */ 0,
    /* pinq[5][1] */ 0,
    /* pinq[5][2] */ 0,
    /* pinq[6][0] */ 0,
    /* pinq[6][1] */ 0,
    /* pinq[6][2] */ 0,
    /* pinq[7][0] */ 0,
    /* pinq[7][1] */ 0,
    /* pinq[7][2] */ 0,
    /* pinq[8][0] */ 0,
    /* pinq[8][1] */ 0,
    /* pinq[8][2] */ 0,
    /* pinq[9][0] */ 0,
    /* pinq[9][1] */ 0,
    /* pinq[9][2] */ 0,
    /* pinq[10][0] */ 0,
    /* pinq[10][1] */ 0,
    /* pinq[10][2] */ 0,
    /* pinq[11][0] */ 0,
    /* pinq[11][1] */ 0,
    /* pinq[11][2] */ 0,
    /* pinq[12][0] */ 0,
    /* pinq[12][1] */ 0,
    /* pinq[12][2] */ 0,
    /* pinq[13][0] */ 0,
    /* pinq[13][1] */ 0,
    /* pinq[13][2] */ 0,
    /* pinq[14][0] */ 0,
    /* pinq[14][1] */ 0,
    /* pinq[14][2] */ 0,
    /* pinq[15][0] */ 0,
    /* pinq[15][1] */ 0,
    /* pinq[15][2] */ 0,
    /* pinq[16][0] */ 0,
    /* pinq[16][1] */ 0,
    /* pinq[16][2] */ 0,
    /* pinq[17][0] */ 0,
    /* pinq[17][1] */ 0,
    /* pinq[17][2] */ 0,
    /* pinq[18][0] */ 0,
    /* pinq[18][1] */ 0,
    /* pinq[18][2] */ 0,
    /* pinq[19][0] */ 0,
    /* pinq[19][1] */ 0,
    /* pinq[19][2] */ 0,
    /* pinq[20][0] */ 0,
    /* pinq[20][1] */ 0,
    /* pinq[20][2] */ 0,
    /* pinq[21][0] */ 0,
    /* pinq[21][1] */ 0,
    /* pinq[21][2] */ 0,
    /* pinq[22][0] */ 0,
    /* pinq[22][1] */ 0,
    /* pinq[22][2] */ 0,
    /* pinq[23][0] */ 0,
    /* pinq[23][1] */ 0,
    /* pinq[23][2] */ 0,
    /* pinq[24][0] */ 0,
    /* pinq[24][1] */ 0,
    /* pinq[24][2] */ 0,
    /* pinq[25][0] */ 0,
    /* pinq[25][1] */ 0,
    /* pinq[25][2] */ 0,
    /* rkq[0][0] */ 3,
    /* rkq[0][1] */ 3,
    /* rkq[0][2] */ 3,
    /* rkq[1][0] */ 3,
    /* rkq[1][1] */ 3,
    /* rkq[1][2] */ 3,
    /* rkq[2][0] */ 3,
    /* rkq[2][1] */ 3,
    /* rkq[2][2] */ 3,
    /* rkq[3][0] */ 3,
    /* rkq[3][1] */ 3,
    /* rkq[3][2] */ 3,
    /* rkq[4][0] */ 3,
    /* rkq[4][1] */ 3,
    /* rkq[4][2] */ 3,
    /* rkq[5][0] */ 3,
    /* rkq[5][1] */ 3,
    /* rkq[5][2] */ 3,
    /* rkq[6][0] */ 3,
    /* rkq[6][1] */ 3,
    /* rkq[6][2] */ 3,
    /* rkq[7][0] */ 3,
    /* rkq[7][1] */ 3,
    /* rkq[7][2] */ 3,
    /* rkq[8][0] */ 3,
    /* rkq[8][1] */ 3,
    /* rkq[8][2] */ 3,
    /* rkq[9][0] */ 3,
    /* rkq[9][1] */ 3,
    /* rkq[9][2] */ 3,
    /* rkq[10][0] */ 3,
    /* rkq[10][1] */ 3,
    /* rkq[10][2] */ 3,
    /* rkq[11][0] */ 3,
    /* rkq[11][1] */ 3,
    /* rkq[11][2] */ 3,
    /* rkq[12][0] */ 3,
    /* rkq[12][1] */ 3,
    /* rkq[12][2] */ 3,
    /* rkq[13][0] */ 3,
    /* rkq[13][1] */ 3,
    /* rkq[13][2] */ 3,
    /* rkq[14][0] */ 3,
    /* rkq[14][1] */ 3,
    /* rkq[14][2] */ 3,
    /* rkq[15][0] */ 3,
    /* rkq[15][1] */ 3,
    /* rkq[15][2] */ 3,
    /* rkq[16][0] */ 3,
    /* rkq[16][1] */ 3,
    /* rkq[16][2] */ 3,
    /* rkq[17][0] */ 3,
    /* rkq[17][1] */ 3,
    /* rkq[17][2] */ 3,
    /* rkq[18][0] */ 3,
    /* rkq[18][1] */ 3,
    /* rkq[18][2] */ 3,
    /* rkq[19][0] */ 3,
    /* rkq[19][1] */ 3,
    /* rkq[19][2] */ 3,
    /* rkq[20][0] */ 3,
    /* rkq[20][1] */ 3,
    /* rkq[20][2] */ 3,
    /* riq[0][0] */ 3,
    /* riq[0][1] */ 3,
    /* riq[0][2] */ 3,
    /* riq[1][0] */ 3,
    /* riq[1][1] */ 3,
    /* riq[1][2] */ 3,
    /* riq[2][0] */ 3,
    /* riq[2][1] */ 3,
    /* riq[2][2] */ 3,
    /* riq[3][0] */ 3,
    /* riq[3][1] */ 3,
    /* riq[3][2] */ 3,
    /* riq[4][0] */ 3,
    /* riq[4][1] */ 3,
    /* riq[4][2] */ 3,
    /* riq[5][0] */ 3,
    /* riq[5][1] */ 3,
    /* riq[5][2] */ 3,
    /* riq[6][0] */ 3,
    /* riq[6][1] */ 3,
    /* riq[6][2] */ 3,
    /* riq[7][0] */ 3,
    /* riq[7][1] */ 3,
    /* riq[7][2] */ 3,
    /* riq[8][0] */ 3,
    /* riq[8][1] */ 3,
    /* riq[8][2] */ 3,
    /* riq[9][0] */ 3,
    /* riq[9][1] */ 3,
    /* riq[9][2] */ 3,
    /* riq[10][0] */ 3,
    /* riq[10][1] */ 3,
    /* riq[10][2] */ 3,
    /* riq[11][0] */ 3,
    /* riq[11][1] */ 3,
    /* riq[11][2] */ 3,
    /* riq[12][0] */ 3,
    /* riq[12][1] */ 3,
    /* riq[12][2] */ 3,
    /* riq[13][0] */ 3,
    /* riq[13][1] */ 3,
    /* riq[13][2] */ 3,
    /* riq[14][0] */ 3,
    /* riq[14][1] */ 3,
    /* riq[14][2] */ 3,
    /* riq[15][0] */ 3,
    /* riq[15][1] */ 3,
    /* riq[15][2] */ 3,
    /* riq[16][0] */ 3,
    /* riq[16][1] */ 3,
    /* riq[16][2] */ 3,
    /* riq[17][0] */ 3,
    /* riq[17][1] */ 3,
    /* riq[17][2] */ 3,
    /* riq[18][0] */ 3,
    /* riq[18][1] */ 3,
    /* riq[18][2] */ 3,
    /* riq[19][0] */ 3,
    /* riq[19][1] */ 3,
    /* riq[19][2] */ 3,
    /* riq[20][0] */ 3,
    /* riq[20][1] */ 3,
    /* riq[20][2] */ 3,
    /* presq[0] */ 0,
    /* presq[1] */ 0,
    /* presq[2] */ 0,
    /* presq[3] */ 0,
    /* presq[4] */ 0,
    /* presq[5] */ 0,
    /* presq[6] */ 0,
    /* presq[7] */ 0,
    /* presq[8] */ 0,
    /* presq[9] */ 0,
    /* presq[10] */ 0,
    /* presq[11] */ 0,
    /* presq[12] */ 0,
    /* presq[13] */ 0,
    /* presq[14] */ 0,
    /* presq[15] */ 0,
    /* presq[16] */ 0,
    /* presq[17] */ 0,
    /* presq[18] */ 0,
    /* presq[19] */ 0,
    /* presq[20] */ 0,
    /* presq[21] */ 0,
    /* presq[22] */ 0,
    /* presq[23] */ 0,
    /* presq[24] */ 0,
    /* presq[25] */ 0,
    /* stabvelq */ 3,
    /* stabposq */ 3,

/* End of values from input file */

};
sdgerror_Jimmy_t sdgerror_temp = {
/* Error parameters
*/
    /* lasterr */ 0,
    /* lastrou */ 0,
};
sdgtopo = sdgtopo_temp;
sdginput = sdginput_temp;
sdgerror = sdgerror_temp;
    
    idx_2_joint = (int *)malloc((ndof)*sizeof(int));
    idx_2_axis = (int *)malloc((ndof)*sizeof(int));
    idx_2_aux = (int *)malloc((ndof)*sizeof(int));
    idx_2_motor = (int *)malloc((ndof)*sizeof(int));
    num_controls=0;    
    for(int i=0;i<nbod;i++){
        if (njntdof[i]==1){
            idx_2_joint[num_controls] = i;
            idx_2_axis[num_controls] = 0;
            idx_2_motor[num_controls] = dof_num;
            num_controls++;
        }
        dof_num+=njntdof[i];
    }
    q_local = (double *)malloc((ndof+nball)*sizeof(double));
    u_local = (double *)malloc((ndof)*sizeof(double));
    qdot_local = (double *)malloc((ndof+nball)*sizeof(double));    
    udot_local = (double *)malloc((ndof)*sizeof(double));  
    u_zero = (double *)malloc((ndof)*sizeof(double));
    for(int i=0;i<ndof;i++){
        q_local[i] = 0.0;
        qdot_local[i] = 0.0;
        u_local[i] = 0.0;
        udot_local[i] = 0.0;
        u_zero[i] = 0.0;
    }
    q_local[ndof+nball-1]=1.0;
    qdot_local[ndof+nball-1]=0.0;
}

Jimmy::~Jimmy(void){
	free(idx_2_joint);
    free(idx_2_axis);
    free(idx_2_aux);
    free(idx_2_motor);
    free(q_local);
    free(u_local);
    free(qdot_local);
    free(udot_local);
    free(u_zero);
}

void Jimmy::sdinit(void)
{
/*
Initialization routine


 This routine must be called before the first call to sdstate(), after
 supplying values for any `?' parameters in the input.
*/
    double sumsq,norminv;
    int i,j,k;


/* Check that all `?' parameters have been assigned values */

    for (k = 0; k < 3; k++) {
        if (gravq[k] == 1) {
            sdseterr(7,25);
        }
    }
    for (k = 0; k < 21; k++) {
        if (mkq[k] == 1) {
            sdseterr(7,26);
        }
        for (i = 0; i < 3; i++) {
            if (rkq[k][i] == 1) {
                sdseterr(7,29);
            }
            if (riq[k][i] == 1) {
                sdseterr(7,30);
            }
            for (j = 0; j < 3; j++) {
                if (ikq[k][i][j] == 1) {
                    sdseterr(7,27);
                }
            }
        }
    }
    for (k = 0; k < 26; k++) {
        for (i = 0; i < 3; i++) {
            if (pinq[k][i] == 1) {
                sdseterr(7,28);
            }
        }
    }

/* Normalize pin vectors if necessary */


/* Zero out Vpk and Wpk */

    for (i = 0; i < 26; i++) {
        for (j = i; j <= 25; j++) {
            for (k = 0; k < 3; k++) {
                Vpk[i][j][k] = 0.;
                Wpk[i][j][k] = 0.;
            }
        }
    }

/* Compute pseudobody-related constants */

    rcom[0][0] = 0.;
    rcom[0][1] = 0.;
    rcom[0][2] = 0.;
    rcom[1][0] = 0.;
    rcom[1][1] = 0.;
    rcom[1][2] = 0.;
    rcom[2][0] = 0.;
    rcom[2][1] = 0.;
    rcom[2][2] = 0.;
    rcom[3][0] = 0.;
    rcom[3][1] = 0.;
    rcom[3][2] = 0.;
    rcom[4][0] = 0.;
    rcom[4][1] = 0.;
    rcom[4][2] = 0.;
    rcom[5][0] = 0.;
    rcom[5][1] = 0.;
    rcom[5][2] = 0.;
    rcom[6][0] = 0.;
    rcom[6][1] = 0.;
    rcom[6][2] = 0.;
    rcom[7][0] = 0.;
    rcom[7][1] = 0.;
    rcom[7][2] = 0.;
    rcom[8][0] = 0.;
    rcom[8][1] = 0.;
    rcom[8][2] = 0.;
    rcom[9][0] = 0.;
    rcom[9][1] = 0.;
    rcom[9][2] = 0.;
    rcom[10][0] = 0.;
    rcom[10][1] = 0.;
    rcom[10][2] = 0.;
    rcom[11][0] = 0.;
    rcom[11][1] = 0.;
    rcom[11][2] = 0.;
    rcom[12][0] = 0.;
    rcom[12][1] = 0.;
    rcom[12][2] = 0.;
    rcom[13][0] = 0.;
    rcom[13][1] = 0.;
    rcom[13][2] = 0.;
    rcom[14][0] = 0.;
    rcom[14][1] = 0.;
    rcom[14][2] = 0.;
    rcom[15][0] = 0.;
    rcom[15][1] = 0.;
    rcom[15][2] = 0.;
    rcom[16][0] = 0.;
    rcom[16][1] = 0.;
    rcom[16][2] = 0.;
    rcom[17][0] = 0.;
    rcom[17][1] = 0.;
    rcom[17][2] = 0.;
    rcom[18][0] = 0.;
    rcom[18][1] = 0.;
    rcom[18][2] = 0.;
    rcom[19][0] = 0.;
    rcom[19][1] = 0.;
    rcom[19][2] = 0.;
    rcom[20][0] = 0.;
    rcom[20][1] = 0.;
    rcom[20][2] = 0.;
    dik[6][0] = (ri[1][0]-rk[0][0]);
    dik[6][1] = (ri[1][1]-rk[0][1]);
    dik[6][2] = (ri[1][2]-rk[0][2]);
    dik[7][0] = (ri[2][0]-rk[1][0]);
    dik[7][1] = (ri[2][1]-rk[1][1]);
    dik[7][2] = (ri[2][2]-rk[1][2]);
    dik[8][0] = (ri[3][0]-rk[2][0]);
    dik[8][1] = (ri[3][1]-rk[2][1]);
    dik[8][2] = (ri[3][2]-rk[2][2]);
    dik[9][0] = (ri[4][0]-rk[3][0]);
    dik[9][1] = (ri[4][1]-rk[3][1]);
    dik[9][2] = (ri[4][2]-rk[3][2]);
    dik[10][0] = (ri[5][0]-rk[4][0]);
    dik[10][1] = (ri[5][1]-rk[4][1]);
    dik[10][2] = (ri[5][2]-rk[4][2]);
    dik[11][0] = (ri[6][0]-rk[5][0]);
    dik[11][1] = (ri[6][1]-rk[5][1]);
    dik[11][2] = (ri[6][2]-rk[5][2]);
    dik[12][0] = (ri[7][0]-rk[0][0]);
    dik[12][1] = (ri[7][1]-rk[0][1]);
    dik[12][2] = (ri[7][2]-rk[0][2]);
    dik[13][0] = (ri[8][0]-rk[7][0]);
    dik[13][1] = (ri[8][1]-rk[7][1]);
    dik[13][2] = (ri[8][2]-rk[7][2]);
    dik[14][0] = (ri[9][0]-rk[8][0]);
    dik[14][1] = (ri[9][1]-rk[8][1]);
    dik[14][2] = (ri[9][2]-rk[8][2]);
    dik[15][0] = (ri[10][0]-rk[9][0]);
    dik[15][1] = (ri[10][1]-rk[9][1]);
    dik[15][2] = (ri[10][2]-rk[9][2]);
    dik[16][0] = (ri[11][0]-rk[10][0]);
    dik[16][1] = (ri[11][1]-rk[10][1]);
    dik[16][2] = (ri[11][2]-rk[10][2]);
    dik[17][0] = (ri[12][0]-rk[11][0]);
    dik[17][1] = (ri[12][1]-rk[11][1]);
    dik[17][2] = (ri[12][2]-rk[11][2]);
    dik[18][0] = (ri[13][0]-rk[0][0]);
    dik[18][1] = (ri[13][1]-rk[0][1]);
    dik[18][2] = (ri[13][2]-rk[0][2]);
    dik[19][0] = (ri[14][0]-rk[13][0]);
    dik[19][1] = (ri[14][1]-rk[13][1]);
    dik[19][2] = (ri[14][2]-rk[13][2]);
    dik[20][0] = (ri[15][0]-rk[14][0]);
    dik[20][1] = (ri[15][1]-rk[14][1]);
    dik[20][2] = (ri[15][2]-rk[14][2]);
    dik[21][0] = (ri[16][0]-rk[15][0]);
    dik[21][1] = (ri[16][1]-rk[15][1]);
    dik[21][2] = (ri[16][2]-rk[15][2]);
    dik[22][0] = (ri[17][0]-rk[0][0]);
    dik[22][1] = (ri[17][1]-rk[0][1]);
    dik[22][2] = (ri[17][2]-rk[0][2]);
    dik[23][0] = (ri[18][0]-rk[17][0]);
    dik[23][1] = (ri[18][1]-rk[17][1]);
    dik[23][2] = (ri[18][2]-rk[17][2]);
    dik[24][0] = (ri[19][0]-rk[18][0]);
    dik[24][1] = (ri[19][1]-rk[18][1]);
    dik[24][2] = (ri[19][2]-rk[18][2]);
    dik[25][0] = (ri[20][0]-rk[19][0]);
    dik[25][1] = (ri[20][1]-rk[19][1]);
    dik[25][2] = (ri[20][2]-rk[19][2]);

/* Compute mass properties-related constants */

    mtot = (mk[20]+(mk[19]+(mk[18]+(mk[17]+(mk[16]+(mk[15]+(mk[14]+(mk[13]+(
      mk[12]+(mk[11]+(mk[10]+(mk[9]+(mk[8]+(mk[7]+(mk[6]+(mk[5]+(mk[4]+(mk[3]+(
      mk[2]+(mk[0]+mk[1]))))))))))))))))))));
    mkrk[5][0][1] = -(mk[0]*rk[0][2]);
    mkrk[5][0][2] = (mk[0]*rk[0][1]);
    mkrk[5][1][0] = (mk[0]*rk[0][2]);
    mkrk[5][1][2] = -(mk[0]*rk[0][0]);
    mkrk[5][2][0] = -(mk[0]*rk[0][1]);
    mkrk[5][2][1] = (mk[0]*rk[0][0]);
    mkrk[6][0][1] = -(mk[1]*rk[1][2]);
    mkrk[6][0][2] = (mk[1]*rk[1][1]);
    mkrk[6][1][0] = (mk[1]*rk[1][2]);
    mkrk[6][1][2] = -(mk[1]*rk[1][0]);
    mkrk[6][2][0] = -(mk[1]*rk[1][1]);
    mkrk[6][2][1] = (mk[1]*rk[1][0]);
    mkrk[7][0][1] = -(mk[2]*rk[2][2]);
    mkrk[7][0][2] = (mk[2]*rk[2][1]);
    mkrk[7][1][0] = (mk[2]*rk[2][2]);
    mkrk[7][1][2] = -(mk[2]*rk[2][0]);
    mkrk[7][2][0] = -(mk[2]*rk[2][1]);
    mkrk[7][2][1] = (mk[2]*rk[2][0]);
    mkrk[8][0][1] = -(mk[3]*rk[3][2]);
    mkrk[8][0][2] = (mk[3]*rk[3][1]);
    mkrk[8][1][0] = (mk[3]*rk[3][2]);
    mkrk[8][1][2] = -(mk[3]*rk[3][0]);
    mkrk[8][2][0] = -(mk[3]*rk[3][1]);
    mkrk[8][2][1] = (mk[3]*rk[3][0]);
    mkrk[9][0][1] = -(mk[4]*rk[4][2]);
    mkrk[9][0][2] = (mk[4]*rk[4][1]);
    mkrk[9][1][0] = (mk[4]*rk[4][2]);
    mkrk[9][1][2] = -(mk[4]*rk[4][0]);
    mkrk[9][2][0] = -(mk[4]*rk[4][1]);
    mkrk[9][2][1] = (mk[4]*rk[4][0]);
    mkrk[10][0][1] = -(mk[5]*rk[5][2]);
    mkrk[10][0][2] = (mk[5]*rk[5][1]);
    mkrk[10][1][0] = (mk[5]*rk[5][2]);
    mkrk[10][1][2] = -(mk[5]*rk[5][0]);
    mkrk[10][2][0] = -(mk[5]*rk[5][1]);
    mkrk[10][2][1] = (mk[5]*rk[5][0]);
    mkrk[11][0][1] = -(mk[6]*rk[6][2]);
    mkrk[11][0][2] = (mk[6]*rk[6][1]);
    mkrk[11][1][0] = (mk[6]*rk[6][2]);
    mkrk[11][1][2] = -(mk[6]*rk[6][0]);
    mkrk[11][2][0] = -(mk[6]*rk[6][1]);
    mkrk[11][2][1] = (mk[6]*rk[6][0]);
    mkrk[12][0][1] = -(mk[7]*rk[7][2]);
    mkrk[12][0][2] = (mk[7]*rk[7][1]);
    mkrk[12][1][0] = (mk[7]*rk[7][2]);
    mkrk[12][1][2] = -(mk[7]*rk[7][0]);
    mkrk[12][2][0] = -(mk[7]*rk[7][1]);
    mkrk[12][2][1] = (mk[7]*rk[7][0]);
    mkrk[13][0][1] = -(mk[8]*rk[8][2]);
    mkrk[13][0][2] = (mk[8]*rk[8][1]);
    mkrk[13][1][0] = (mk[8]*rk[8][2]);
    mkrk[13][1][2] = -(mk[8]*rk[8][0]);
    mkrk[13][2][0] = -(mk[8]*rk[8][1]);
    mkrk[13][2][1] = (mk[8]*rk[8][0]);
    mkrk[14][0][1] = -(mk[9]*rk[9][2]);
    mkrk[14][0][2] = (mk[9]*rk[9][1]);
    mkrk[14][1][0] = (mk[9]*rk[9][2]);
    mkrk[14][1][2] = -(mk[9]*rk[9][0]);
    mkrk[14][2][0] = -(mk[9]*rk[9][1]);
    mkrk[14][2][1] = (mk[9]*rk[9][0]);
    mkrk[15][0][1] = -(mk[10]*rk[10][2]);
    mkrk[15][0][2] = (mk[10]*rk[10][1]);
    mkrk[15][1][0] = (mk[10]*rk[10][2]);
    mkrk[15][1][2] = -(mk[10]*rk[10][0]);
    mkrk[15][2][0] = -(mk[10]*rk[10][1]);
    mkrk[15][2][1] = (mk[10]*rk[10][0]);
    mkrk[16][0][1] = -(mk[11]*rk[11][2]);
    mkrk[16][0][2] = (mk[11]*rk[11][1]);
    mkrk[16][1][0] = (mk[11]*rk[11][2]);
    mkrk[16][1][2] = -(mk[11]*rk[11][0]);
    mkrk[16][2][0] = -(mk[11]*rk[11][1]);
    mkrk[16][2][1] = (mk[11]*rk[11][0]);
    mkrk[17][0][1] = -(mk[12]*rk[12][2]);
    mkrk[17][0][2] = (mk[12]*rk[12][1]);
    mkrk[17][1][0] = (mk[12]*rk[12][2]);
    mkrk[17][1][2] = -(mk[12]*rk[12][0]);
    mkrk[17][2][0] = -(mk[12]*rk[12][1]);
    mkrk[17][2][1] = (mk[12]*rk[12][0]);
    mkrk[18][0][1] = -(mk[13]*rk[13][2]);
    mkrk[18][0][2] = (mk[13]*rk[13][1]);
    mkrk[18][1][0] = (mk[13]*rk[13][2]);
    mkrk[18][1][2] = -(mk[13]*rk[13][0]);
    mkrk[18][2][0] = -(mk[13]*rk[13][1]);
    mkrk[18][2][1] = (mk[13]*rk[13][0]);
    mkrk[19][0][1] = -(mk[14]*rk[14][2]);
    mkrk[19][0][2] = (mk[14]*rk[14][1]);
    mkrk[19][1][0] = (mk[14]*rk[14][2]);
    mkrk[19][1][2] = -(mk[14]*rk[14][0]);
    mkrk[19][2][0] = -(mk[14]*rk[14][1]);
    mkrk[19][2][1] = (mk[14]*rk[14][0]);
    mkrk[20][0][1] = -(mk[15]*rk[15][2]);
    mkrk[20][0][2] = (mk[15]*rk[15][1]);
    mkrk[20][1][0] = (mk[15]*rk[15][2]);
    mkrk[20][1][2] = -(mk[15]*rk[15][0]);
    mkrk[20][2][0] = -(mk[15]*rk[15][1]);
    mkrk[20][2][1] = (mk[15]*rk[15][0]);
    mkrk[21][0][1] = -(mk[16]*rk[16][2]);
    mkrk[21][0][2] = (mk[16]*rk[16][1]);
    mkrk[21][1][0] = (mk[16]*rk[16][2]);
    mkrk[21][1][2] = -(mk[16]*rk[16][0]);
    mkrk[21][2][0] = -(mk[16]*rk[16][1]);
    mkrk[21][2][1] = (mk[16]*rk[16][0]);
    mkrk[22][0][1] = -(mk[17]*rk[17][2]);
    mkrk[22][0][2] = (mk[17]*rk[17][1]);
    mkrk[22][1][0] = (mk[17]*rk[17][2]);
    mkrk[22][1][2] = -(mk[17]*rk[17][0]);
    mkrk[22][2][0] = -(mk[17]*rk[17][1]);
    mkrk[22][2][1] = (mk[17]*rk[17][0]);
    mkrk[23][0][1] = -(mk[18]*rk[18][2]);
    mkrk[23][0][2] = (mk[18]*rk[18][1]);
    mkrk[23][1][0] = (mk[18]*rk[18][2]);
    mkrk[23][1][2] = -(mk[18]*rk[18][0]);
    mkrk[23][2][0] = -(mk[18]*rk[18][1]);
    mkrk[23][2][1] = (mk[18]*rk[18][0]);
    mkrk[24][0][1] = -(mk[19]*rk[19][2]);
    mkrk[24][0][2] = (mk[19]*rk[19][1]);
    mkrk[24][1][0] = (mk[19]*rk[19][2]);
    mkrk[24][1][2] = -(mk[19]*rk[19][0]);
    mkrk[24][2][0] = -(mk[19]*rk[19][1]);
    mkrk[24][2][1] = (mk[19]*rk[19][0]);
    mkrk[25][0][1] = -(mk[20]*rk[20][2]);
    mkrk[25][0][2] = (mk[20]*rk[20][1]);
    mkrk[25][1][0] = (mk[20]*rk[20][2]);
    mkrk[25][1][2] = -(mk[20]*rk[20][0]);
    mkrk[25][2][0] = -(mk[20]*rk[20][1]);
    mkrk[25][2][1] = (mk[20]*rk[20][0]);
    Iko[5][0][0] = (ik[0][0][0]-((mkrk[5][0][1]*rk[0][2])-(mkrk[5][0][2]*
      rk[0][1])));
    Iko[5][0][1] = (ik[0][0][1]-(mkrk[5][0][2]*rk[0][0]));
    Iko[5][0][2] = (ik[0][0][2]+(mkrk[5][0][1]*rk[0][0]));
    Iko[5][1][0] = (ik[0][1][0]+(mkrk[5][1][2]*rk[0][1]));
    Iko[5][1][1] = (ik[0][1][1]-((mkrk[5][1][2]*rk[0][0])-(mkrk[5][1][0]*
      rk[0][2])));
    Iko[5][1][2] = (ik[0][1][2]-(mkrk[5][1][0]*rk[0][1]));
    Iko[5][2][0] = (ik[0][2][0]-(mkrk[5][2][1]*rk[0][2]));
    Iko[5][2][1] = (ik[0][2][1]+(mkrk[5][2][0]*rk[0][2]));
    Iko[5][2][2] = (ik[0][2][2]-((mkrk[5][2][0]*rk[0][1])-(mkrk[5][2][1]*
      rk[0][0])));
    Iko[6][0][0] = (ik[1][0][0]-((mkrk[6][0][1]*rk[1][2])-(mkrk[6][0][2]*
      rk[1][1])));
    Iko[6][0][1] = (ik[1][0][1]-(mkrk[6][0][2]*rk[1][0]));
    Iko[6][0][2] = (ik[1][0][2]+(mkrk[6][0][1]*rk[1][0]));
    Iko[6][1][0] = (ik[1][1][0]+(mkrk[6][1][2]*rk[1][1]));
    Iko[6][1][1] = (ik[1][1][1]-((mkrk[6][1][2]*rk[1][0])-(mkrk[6][1][0]*
      rk[1][2])));
    Iko[6][1][2] = (ik[1][1][2]-(mkrk[6][1][0]*rk[1][1]));
    Iko[6][2][0] = (ik[1][2][0]-(mkrk[6][2][1]*rk[1][2]));
    Iko[6][2][1] = (ik[1][2][1]+(mkrk[6][2][0]*rk[1][2]));
    Iko[6][2][2] = (ik[1][2][2]-((mkrk[6][2][0]*rk[1][1])-(mkrk[6][2][1]*
      rk[1][0])));
    Iko[7][0][0] = (ik[2][0][0]-((mkrk[7][0][1]*rk[2][2])-(mkrk[7][0][2]*
      rk[2][1])));
    Iko[7][0][1] = (ik[2][0][1]-(mkrk[7][0][2]*rk[2][0]));
    Iko[7][0][2] = (ik[2][0][2]+(mkrk[7][0][1]*rk[2][0]));
    Iko[7][1][0] = (ik[2][1][0]+(mkrk[7][1][2]*rk[2][1]));
    Iko[7][1][1] = (ik[2][1][1]-((mkrk[7][1][2]*rk[2][0])-(mkrk[7][1][0]*
      rk[2][2])));
    Iko[7][1][2] = (ik[2][1][2]-(mkrk[7][1][0]*rk[2][1]));
    Iko[7][2][0] = (ik[2][2][0]-(mkrk[7][2][1]*rk[2][2]));
    Iko[7][2][1] = (ik[2][2][1]+(mkrk[7][2][0]*rk[2][2]));
    Iko[7][2][2] = (ik[2][2][2]-((mkrk[7][2][0]*rk[2][1])-(mkrk[7][2][1]*
      rk[2][0])));
    Iko[8][0][0] = (ik[3][0][0]-((mkrk[8][0][1]*rk[3][2])-(mkrk[8][0][2]*
      rk[3][1])));
    Iko[8][0][1] = (ik[3][0][1]-(mkrk[8][0][2]*rk[3][0]));
    Iko[8][0][2] = (ik[3][0][2]+(mkrk[8][0][1]*rk[3][0]));
    Iko[8][1][0] = (ik[3][1][0]+(mkrk[8][1][2]*rk[3][1]));
    Iko[8][1][1] = (ik[3][1][1]-((mkrk[8][1][2]*rk[3][0])-(mkrk[8][1][0]*
      rk[3][2])));
    Iko[8][1][2] = (ik[3][1][2]-(mkrk[8][1][0]*rk[3][1]));
    Iko[8][2][0] = (ik[3][2][0]-(mkrk[8][2][1]*rk[3][2]));
    Iko[8][2][1] = (ik[3][2][1]+(mkrk[8][2][0]*rk[3][2]));
    Iko[8][2][2] = (ik[3][2][2]-((mkrk[8][2][0]*rk[3][1])-(mkrk[8][2][1]*
      rk[3][0])));
    Iko[9][0][0] = (ik[4][0][0]-((mkrk[9][0][1]*rk[4][2])-(mkrk[9][0][2]*
      rk[4][1])));
    Iko[9][0][1] = (ik[4][0][1]-(mkrk[9][0][2]*rk[4][0]));
    Iko[9][0][2] = (ik[4][0][2]+(mkrk[9][0][1]*rk[4][0]));
    Iko[9][1][0] = (ik[4][1][0]+(mkrk[9][1][2]*rk[4][1]));
    Iko[9][1][1] = (ik[4][1][1]-((mkrk[9][1][2]*rk[4][0])-(mkrk[9][1][0]*
      rk[4][2])));
    Iko[9][1][2] = (ik[4][1][2]-(mkrk[9][1][0]*rk[4][1]));
    Iko[9][2][0] = (ik[4][2][0]-(mkrk[9][2][1]*rk[4][2]));
    Iko[9][2][1] = (ik[4][2][1]+(mkrk[9][2][0]*rk[4][2]));
    Iko[9][2][2] = (ik[4][2][2]-((mkrk[9][2][0]*rk[4][1])-(mkrk[9][2][1]*
      rk[4][0])));
    Iko[10][0][0] = (ik[5][0][0]-((mkrk[10][0][1]*rk[5][2])-(mkrk[10][0][2]*
      rk[5][1])));
    Iko[10][0][1] = (ik[5][0][1]-(mkrk[10][0][2]*rk[5][0]));
    Iko[10][0][2] = (ik[5][0][2]+(mkrk[10][0][1]*rk[5][0]));
    Iko[10][1][0] = (ik[5][1][0]+(mkrk[10][1][2]*rk[5][1]));
    Iko[10][1][1] = (ik[5][1][1]-((mkrk[10][1][2]*rk[5][0])-(mkrk[10][1][0]*
      rk[5][2])));
    Iko[10][1][2] = (ik[5][1][2]-(mkrk[10][1][0]*rk[5][1]));
    Iko[10][2][0] = (ik[5][2][0]-(mkrk[10][2][1]*rk[5][2]));
    Iko[10][2][1] = (ik[5][2][1]+(mkrk[10][2][0]*rk[5][2]));
    Iko[10][2][2] = (ik[5][2][2]-((mkrk[10][2][0]*rk[5][1])-(mkrk[10][2][1]*
      rk[5][0])));
    Iko[11][0][0] = (ik[6][0][0]-((mkrk[11][0][1]*rk[6][2])-(mkrk[11][0][2]*
      rk[6][1])));
    Iko[11][0][1] = (ik[6][0][1]-(mkrk[11][0][2]*rk[6][0]));
    Iko[11][0][2] = (ik[6][0][2]+(mkrk[11][0][1]*rk[6][0]));
    Iko[11][1][0] = (ik[6][1][0]+(mkrk[11][1][2]*rk[6][1]));
    Iko[11][1][1] = (ik[6][1][1]-((mkrk[11][1][2]*rk[6][0])-(mkrk[11][1][0]*
      rk[6][2])));
    Iko[11][1][2] = (ik[6][1][2]-(mkrk[11][1][0]*rk[6][1]));
    Iko[11][2][0] = (ik[6][2][0]-(mkrk[11][2][1]*rk[6][2]));
    Iko[11][2][1] = (ik[6][2][1]+(mkrk[11][2][0]*rk[6][2]));
    Iko[11][2][2] = (ik[6][2][2]-((mkrk[11][2][0]*rk[6][1])-(mkrk[11][2][1]*
      rk[6][0])));
    Iko[12][0][0] = (ik[7][0][0]-((mkrk[12][0][1]*rk[7][2])-(mkrk[12][0][2]*
      rk[7][1])));
    Iko[12][0][1] = (ik[7][0][1]-(mkrk[12][0][2]*rk[7][0]));
    Iko[12][0][2] = (ik[7][0][2]+(mkrk[12][0][1]*rk[7][0]));
    Iko[12][1][0] = (ik[7][1][0]+(mkrk[12][1][2]*rk[7][1]));
    Iko[12][1][1] = (ik[7][1][1]-((mkrk[12][1][2]*rk[7][0])-(mkrk[12][1][0]*
      rk[7][2])));
    Iko[12][1][2] = (ik[7][1][2]-(mkrk[12][1][0]*rk[7][1]));
    Iko[12][2][0] = (ik[7][2][0]-(mkrk[12][2][1]*rk[7][2]));
    Iko[12][2][1] = (ik[7][2][1]+(mkrk[12][2][0]*rk[7][2]));
    Iko[12][2][2] = (ik[7][2][2]-((mkrk[12][2][0]*rk[7][1])-(mkrk[12][2][1]*
      rk[7][0])));
    Iko[13][0][0] = (ik[8][0][0]-((mkrk[13][0][1]*rk[8][2])-(mkrk[13][0][2]*
      rk[8][1])));
    Iko[13][0][1] = (ik[8][0][1]-(mkrk[13][0][2]*rk[8][0]));
    Iko[13][0][2] = (ik[8][0][2]+(mkrk[13][0][1]*rk[8][0]));
    Iko[13][1][0] = (ik[8][1][0]+(mkrk[13][1][2]*rk[8][1]));
    Iko[13][1][1] = (ik[8][1][1]-((mkrk[13][1][2]*rk[8][0])-(mkrk[13][1][0]*
      rk[8][2])));
    Iko[13][1][2] = (ik[8][1][2]-(mkrk[13][1][0]*rk[8][1]));
    Iko[13][2][0] = (ik[8][2][0]-(mkrk[13][2][1]*rk[8][2]));
    Iko[13][2][1] = (ik[8][2][1]+(mkrk[13][2][0]*rk[8][2]));
    Iko[13][2][2] = (ik[8][2][2]-((mkrk[13][2][0]*rk[8][1])-(mkrk[13][2][1]*
      rk[8][0])));
    Iko[14][0][0] = (ik[9][0][0]-((mkrk[14][0][1]*rk[9][2])-(mkrk[14][0][2]*
      rk[9][1])));
    Iko[14][0][1] = (ik[9][0][1]-(mkrk[14][0][2]*rk[9][0]));
    Iko[14][0][2] = (ik[9][0][2]+(mkrk[14][0][1]*rk[9][0]));
    Iko[14][1][0] = (ik[9][1][0]+(mkrk[14][1][2]*rk[9][1]));
    Iko[14][1][1] = (ik[9][1][1]-((mkrk[14][1][2]*rk[9][0])-(mkrk[14][1][0]*
      rk[9][2])));
    Iko[14][1][2] = (ik[9][1][2]-(mkrk[14][1][0]*rk[9][1]));
    Iko[14][2][0] = (ik[9][2][0]-(mkrk[14][2][1]*rk[9][2]));
    Iko[14][2][1] = (ik[9][2][1]+(mkrk[14][2][0]*rk[9][2]));
    Iko[14][2][2] = (ik[9][2][2]-((mkrk[14][2][0]*rk[9][1])-(mkrk[14][2][1]*
      rk[9][0])));
    Iko[15][0][0] = (ik[10][0][0]-((mkrk[15][0][1]*rk[10][2])-(mkrk[15][0][2]*
      rk[10][1])));
    Iko[15][0][1] = (ik[10][0][1]-(mkrk[15][0][2]*rk[10][0]));
    Iko[15][0][2] = (ik[10][0][2]+(mkrk[15][0][1]*rk[10][0]));
    Iko[15][1][0] = (ik[10][1][0]+(mkrk[15][1][2]*rk[10][1]));
    Iko[15][1][1] = (ik[10][1][1]-((mkrk[15][1][2]*rk[10][0])-(mkrk[15][1][0]*
      rk[10][2])));
    Iko[15][1][2] = (ik[10][1][2]-(mkrk[15][1][0]*rk[10][1]));
    Iko[15][2][0] = (ik[10][2][0]-(mkrk[15][2][1]*rk[10][2]));
    Iko[15][2][1] = (ik[10][2][1]+(mkrk[15][2][0]*rk[10][2]));
    Iko[15][2][2] = (ik[10][2][2]-((mkrk[15][2][0]*rk[10][1])-(mkrk[15][2][1]*
      rk[10][0])));
    Iko[16][0][0] = (ik[11][0][0]-((mkrk[16][0][1]*rk[11][2])-(mkrk[16][0][2]*
      rk[11][1])));
    Iko[16][0][1] = (ik[11][0][1]-(mkrk[16][0][2]*rk[11][0]));
    Iko[16][0][2] = (ik[11][0][2]+(mkrk[16][0][1]*rk[11][0]));
    Iko[16][1][0] = (ik[11][1][0]+(mkrk[16][1][2]*rk[11][1]));
    Iko[16][1][1] = (ik[11][1][1]-((mkrk[16][1][2]*rk[11][0])-(mkrk[16][1][0]*
      rk[11][2])));
    Iko[16][1][2] = (ik[11][1][2]-(mkrk[16][1][0]*rk[11][1]));
    Iko[16][2][0] = (ik[11][2][0]-(mkrk[16][2][1]*rk[11][2]));
    Iko[16][2][1] = (ik[11][2][1]+(mkrk[16][2][0]*rk[11][2]));
    Iko[16][2][2] = (ik[11][2][2]-((mkrk[16][2][0]*rk[11][1])-(mkrk[16][2][1]*
      rk[11][0])));
    Iko[17][0][0] = (ik[12][0][0]-((mkrk[17][0][1]*rk[12][2])-(mkrk[17][0][2]*
      rk[12][1])));
    Iko[17][0][1] = (ik[12][0][1]-(mkrk[17][0][2]*rk[12][0]));
    Iko[17][0][2] = (ik[12][0][2]+(mkrk[17][0][1]*rk[12][0]));
    Iko[17][1][0] = (ik[12][1][0]+(mkrk[17][1][2]*rk[12][1]));
    Iko[17][1][1] = (ik[12][1][1]-((mkrk[17][1][2]*rk[12][0])-(mkrk[17][1][0]*
      rk[12][2])));
    Iko[17][1][2] = (ik[12][1][2]-(mkrk[17][1][0]*rk[12][1]));
    Iko[17][2][0] = (ik[12][2][0]-(mkrk[17][2][1]*rk[12][2]));
    Iko[17][2][1] = (ik[12][2][1]+(mkrk[17][2][0]*rk[12][2]));
    Iko[17][2][2] = (ik[12][2][2]-((mkrk[17][2][0]*rk[12][1])-(mkrk[17][2][1]*
      rk[12][0])));
    Iko[18][0][0] = (ik[13][0][0]-((mkrk[18][0][1]*rk[13][2])-(mkrk[18][0][2]*
      rk[13][1])));
    Iko[18][0][1] = (ik[13][0][1]-(mkrk[18][0][2]*rk[13][0]));
    Iko[18][0][2] = (ik[13][0][2]+(mkrk[18][0][1]*rk[13][0]));
    Iko[18][1][0] = (ik[13][1][0]+(mkrk[18][1][2]*rk[13][1]));
    Iko[18][1][1] = (ik[13][1][1]-((mkrk[18][1][2]*rk[13][0])-(mkrk[18][1][0]*
      rk[13][2])));
    Iko[18][1][2] = (ik[13][1][2]-(mkrk[18][1][0]*rk[13][1]));
    Iko[18][2][0] = (ik[13][2][0]-(mkrk[18][2][1]*rk[13][2]));
    Iko[18][2][1] = (ik[13][2][1]+(mkrk[18][2][0]*rk[13][2]));
    Iko[18][2][2] = (ik[13][2][2]-((mkrk[18][2][0]*rk[13][1])-(mkrk[18][2][1]*
      rk[13][0])));
    Iko[19][0][0] = (ik[14][0][0]-((mkrk[19][0][1]*rk[14][2])-(mkrk[19][0][2]*
      rk[14][1])));
    Iko[19][0][1] = (ik[14][0][1]-(mkrk[19][0][2]*rk[14][0]));
    Iko[19][0][2] = (ik[14][0][2]+(mkrk[19][0][1]*rk[14][0]));
    Iko[19][1][0] = (ik[14][1][0]+(mkrk[19][1][2]*rk[14][1]));
    Iko[19][1][1] = (ik[14][1][1]-((mkrk[19][1][2]*rk[14][0])-(mkrk[19][1][0]*
      rk[14][2])));
    Iko[19][1][2] = (ik[14][1][2]-(mkrk[19][1][0]*rk[14][1]));
    Iko[19][2][0] = (ik[14][2][0]-(mkrk[19][2][1]*rk[14][2]));
    Iko[19][2][1] = (ik[14][2][1]+(mkrk[19][2][0]*rk[14][2]));
    Iko[19][2][2] = (ik[14][2][2]-((mkrk[19][2][0]*rk[14][1])-(mkrk[19][2][1]*
      rk[14][0])));
    Iko[20][0][0] = (ik[15][0][0]-((mkrk[20][0][1]*rk[15][2])-(mkrk[20][0][2]*
      rk[15][1])));
    Iko[20][0][1] = (ik[15][0][1]-(mkrk[20][0][2]*rk[15][0]));
    Iko[20][0][2] = (ik[15][0][2]+(mkrk[20][0][1]*rk[15][0]));
    Iko[20][1][0] = (ik[15][1][0]+(mkrk[20][1][2]*rk[15][1]));
    Iko[20][1][1] = (ik[15][1][1]-((mkrk[20][1][2]*rk[15][0])-(mkrk[20][1][0]*
      rk[15][2])));
    Iko[20][1][2] = (ik[15][1][2]-(mkrk[20][1][0]*rk[15][1]));
    Iko[20][2][0] = (ik[15][2][0]-(mkrk[20][2][1]*rk[15][2]));
    Iko[20][2][1] = (ik[15][2][1]+(mkrk[20][2][0]*rk[15][2]));
    Iko[20][2][2] = (ik[15][2][2]-((mkrk[20][2][0]*rk[15][1])-(mkrk[20][2][1]*
      rk[15][0])));
    Iko[21][0][0] = (ik[16][0][0]-((mkrk[21][0][1]*rk[16][2])-(mkrk[21][0][2]*
      rk[16][1])));
    Iko[21][0][1] = (ik[16][0][1]-(mkrk[21][0][2]*rk[16][0]));
    Iko[21][0][2] = (ik[16][0][2]+(mkrk[21][0][1]*rk[16][0]));
    Iko[21][1][0] = (ik[16][1][0]+(mkrk[21][1][2]*rk[16][1]));
    Iko[21][1][1] = (ik[16][1][1]-((mkrk[21][1][2]*rk[16][0])-(mkrk[21][1][0]*
      rk[16][2])));
    Iko[21][1][2] = (ik[16][1][2]-(mkrk[21][1][0]*rk[16][1]));
    Iko[21][2][0] = (ik[16][2][0]-(mkrk[21][2][1]*rk[16][2]));
    Iko[21][2][1] = (ik[16][2][1]+(mkrk[21][2][0]*rk[16][2]));
    Iko[21][2][2] = (ik[16][2][2]-((mkrk[21][2][0]*rk[16][1])-(mkrk[21][2][1]*
      rk[16][0])));
    Iko[22][0][0] = (ik[17][0][0]-((mkrk[22][0][1]*rk[17][2])-(mkrk[22][0][2]*
      rk[17][1])));
    Iko[22][0][1] = (ik[17][0][1]-(mkrk[22][0][2]*rk[17][0]));
    Iko[22][0][2] = (ik[17][0][2]+(mkrk[22][0][1]*rk[17][0]));
    Iko[22][1][0] = (ik[17][1][0]+(mkrk[22][1][2]*rk[17][1]));
    Iko[22][1][1] = (ik[17][1][1]-((mkrk[22][1][2]*rk[17][0])-(mkrk[22][1][0]*
      rk[17][2])));
    Iko[22][1][2] = (ik[17][1][2]-(mkrk[22][1][0]*rk[17][1]));
    Iko[22][2][0] = (ik[17][2][0]-(mkrk[22][2][1]*rk[17][2]));
    Iko[22][2][1] = (ik[17][2][1]+(mkrk[22][2][0]*rk[17][2]));
    Iko[22][2][2] = (ik[17][2][2]-((mkrk[22][2][0]*rk[17][1])-(mkrk[22][2][1]*
      rk[17][0])));
    Iko[23][0][0] = (ik[18][0][0]-((mkrk[23][0][1]*rk[18][2])-(mkrk[23][0][2]*
      rk[18][1])));
    Iko[23][0][1] = (ik[18][0][1]-(mkrk[23][0][2]*rk[18][0]));
    Iko[23][0][2] = (ik[18][0][2]+(mkrk[23][0][1]*rk[18][0]));
    Iko[23][1][0] = (ik[18][1][0]+(mkrk[23][1][2]*rk[18][1]));
    Iko[23][1][1] = (ik[18][1][1]-((mkrk[23][1][2]*rk[18][0])-(mkrk[23][1][0]*
      rk[18][2])));
    Iko[23][1][2] = (ik[18][1][2]-(mkrk[23][1][0]*rk[18][1]));
    Iko[23][2][0] = (ik[18][2][0]-(mkrk[23][2][1]*rk[18][2]));
    Iko[23][2][1] = (ik[18][2][1]+(mkrk[23][2][0]*rk[18][2]));
    Iko[23][2][2] = (ik[18][2][2]-((mkrk[23][2][0]*rk[18][1])-(mkrk[23][2][1]*
      rk[18][0])));
    Iko[24][0][0] = (ik[19][0][0]-((mkrk[24][0][1]*rk[19][2])-(mkrk[24][0][2]*
      rk[19][1])));
    Iko[24][0][1] = (ik[19][0][1]-(mkrk[24][0][2]*rk[19][0]));
    Iko[24][0][2] = (ik[19][0][2]+(mkrk[24][0][1]*rk[19][0]));
    Iko[24][1][0] = (ik[19][1][0]+(mkrk[24][1][2]*rk[19][1]));
    Iko[24][1][1] = (ik[19][1][1]-((mkrk[24][1][2]*rk[19][0])-(mkrk[24][1][0]*
      rk[19][2])));
    Iko[24][1][2] = (ik[19][1][2]-(mkrk[24][1][0]*rk[19][1]));
    Iko[24][2][0] = (ik[19][2][0]-(mkrk[24][2][1]*rk[19][2]));
    Iko[24][2][1] = (ik[19][2][1]+(mkrk[24][2][0]*rk[19][2]));
    Iko[24][2][2] = (ik[19][2][2]-((mkrk[24][2][0]*rk[19][1])-(mkrk[24][2][1]*
      rk[19][0])));
    Iko[25][0][0] = (ik[20][0][0]-((mkrk[25][0][1]*rk[20][2])-(mkrk[25][0][2]*
      rk[20][1])));
    Iko[25][0][1] = (ik[20][0][1]-(mkrk[25][0][2]*rk[20][0]));
    Iko[25][0][2] = (ik[20][0][2]+(mkrk[25][0][1]*rk[20][0]));
    Iko[25][1][0] = (ik[20][1][0]+(mkrk[25][1][2]*rk[20][1]));
    Iko[25][1][1] = (ik[20][1][1]-((mkrk[25][1][2]*rk[20][0])-(mkrk[25][1][0]*
      rk[20][2])));
    Iko[25][1][2] = (ik[20][1][2]-(mkrk[25][1][0]*rk[20][1]));
    Iko[25][2][0] = (ik[20][2][0]-(mkrk[25][2][1]*rk[20][2]));
    Iko[25][2][1] = (ik[20][2][1]+(mkrk[25][2][0]*rk[20][2]));
    Iko[25][2][2] = (ik[20][2][2]-((mkrk[25][2][0]*rk[20][1])-(mkrk[25][2][1]*
      rk[20][0])));
    sdserialno(&i);
    if (i != 30123) {
        sdseterr(7,41);
    }
    roustate = 1;
}

/* Convert state to form using 1-2-3 Euler angles for ball joints. */

void Jimmy::sdst2ang(double st[27],
    double stang[26])
{
    int i;
    double dc[3][3];

    for (i = 0; i < 26; i++) {
        stang[i] = st[i];
    }
    sdquat2dc(st[3],st[4],st[5],st[26],dc);
    sddc2ang(dc,&stang[3],&stang[4],&stang[5]);
}

/* Convert 1-2-3 form of state back to Euler parameters for ball joints. */

void Jimmy::sdang2st(double stang[26],
    double st[27])
{
    int i;
    double dc[3][3];

    for (i = 0; i < 26; i++) {
        st[i] = stang[i];
    }
    sdang2dc(stang[3],stang[4],stang[5],dc);
    sddc2quat(dc,&st[3],&st[4],&st[5],&st[26]);
}

/* Normalize Euler parameters in state. */

void Jimmy::sdnrmsterr(double st[27],
    double normst[27],
    int routine)
{
    int i;
    double norm;

    for (i = 0; i < 27; i++) {
        normst[i] = st[i];
    }
    norm = sqrt(st[3]*st[3]+st[4]*st[4]+st[5]*st[5]+st[26]*st[26]);
    if (routine != 0) {
        if ((norm < .9) || (norm > 1.1)) {
            sdseterr(routine,14);
        }
    }
    if (norm == 0.) {
        normst[26] = 1.;
        norm = 1.;
    }
    norm = 1./norm;
    normst[3] = normst[3]*norm;
    normst[4] = normst[4]*norm;
    normst[5] = normst[5]*norm;
    normst[26] = normst[26]*norm;
}

void Jimmy::sdnormst(double st[27],
    double normst[27])
{

    sdnrmsterr(st,normst,0);
}

void Jimmy::sdstate(double timein,
    double qin[27],
    double uin[26])
{
/*
Compute kinematic information and store it in sdgstate.

Generated 27-Jan-2007 11:40:24 by SD/FAST, Kane's formulation
(sdfast B.2.8 #30123) on machine ID unknown
Copyright (c) 1990-1997 Symbolic Dynamics, Inc.
Copyright (c) 1990-1997 Parametric Technology Corp.
RESTRICTED RIGHTS LEGEND: Use, duplication, or disclosure by the U.S.
Government is subject to restrictions as set forth in subparagraph
(c)(1)(ii) of the Rights in Technical Data and Computer Software
clause at DFARS 52.227-7013 and similar clauses in the FAR and NASA
FAR Supplement.  Symbolic Dynamics, Inc., Mountain View, CA 94041
*/
    int i,j,qchg,uchg;
    double ee,stab;

    if ((roustate != 1) && (roustate != 2) && (roustate != 3)) {
        sdseterr(8,22);
        return;
    }
    if (roustate == 1) {
        for (i = 0; i < 26; i++) {
            if (presq[i] == 1) {
                sdseterr(8,31);
            }
        }
    }
/*
See if time or any qs have changed since last call
*/
    if ((roustate != 1) && (timein == curtim)) {
        qchg = 0;
        for (i = 0; i < 27; i++) {
            if (qin[i] != q[i]) {
                qchg = 1;
                break;
            }
        }
    } else {
        qchg = 1;
    }
/*
If time and qs are unchanged, check us
*/
    if (qchg == 0) {
        uchg = 0;
        for (i = 0; i < 26; i++) {
            if (uin[i] != u[i]) {
                uchg = 1;
                break;
            }
        }
    } else {
        uchg = 1;
    }
    curtim = timein;
    roustate = 2;
    if (qchg == 0) {
        goto skipqs;
    }
/*
Position-related variables need to be computed
*/
    vpkflg = 0;
    mmflg = 0;
    mmlduflg = 0;
    wwflg = 0;
    for (i = 0; i < 27; i++) {
        q[i] = qin[i];
    }
/*
Normalize Euler parameters in state
*/
    sdnrmsterr(q,qn,8);
/*
Compute sines and cosines of q
*/
    s6 = sin(q[6]);
    c6 = cos(q[6]);
    s7 = sin(q[7]);
    c7 = cos(q[7]);
    s8 = sin(q[8]);
    c8 = cos(q[8]);
    s9 = sin(q[9]);
    c9 = cos(q[9]);
    s10 = sin(q[10]);
    c10 = cos(q[10]);
    s11 = sin(q[11]);
    c11 = cos(q[11]);
    s12 = sin(q[12]);
    c12 = cos(q[12]);
    s13 = sin(q[13]);
    c13 = cos(q[13]);
    s14 = sin(q[14]);
    c14 = cos(q[14]);
    s15 = sin(q[15]);
    c15 = cos(q[15]);
    s16 = sin(q[16]);
    c16 = cos(q[16]);
    s17 = sin(q[17]);
    c17 = cos(q[17]);
    s18 = sin(q[18]);
    c18 = cos(q[18]);
    s19 = sin(q[19]);
    c19 = cos(q[19]);
    s20 = sin(q[20]);
    c20 = cos(q[20]);
    s21 = sin(q[21]);
    c21 = cos(q[21]);
    s22 = sin(q[22]);
    c22 = cos(q[22]);
    s23 = sin(q[23]);
    c23 = cos(q[23]);
    s24 = sin(q[24]);
    c24 = cos(q[24]);
    s25 = sin(q[25]);
    c25 = cos(q[25]);
/*
Compute across-axis direction cosines Cik
*/
    Cik[3][0][0] = (1.-(2.*((qn[4]*qn[4])+(qn[5]*qn[5]))));
    Cik[3][0][1] = (2.*((qn[3]*qn[4])-(qn[5]*qn[26])));
    Cik[3][0][2] = (2.*((qn[3]*qn[5])+(qn[4]*qn[26])));
    Cik[3][1][0] = (2.*((qn[3]*qn[4])+(qn[5]*qn[26])));
    Cik[3][1][1] = (1.-(2.*((qn[3]*qn[3])+(qn[5]*qn[5]))));
    Cik[3][1][2] = (2.*((qn[4]*qn[5])-(qn[3]*qn[26])));
    Cik[3][2][0] = (2.*((qn[3]*qn[5])-(qn[4]*qn[26])));
    Cik[3][2][1] = (2.*((qn[3]*qn[26])+(qn[4]*qn[5])));
    Cik[3][2][2] = (1.-(2.*((qn[3]*qn[3])+(qn[4]*qn[4]))));
/*
Compute across-joint direction cosines Cib
*/
/*
Compute gravity
*/
    gk[6][0] = -(9.81*((Cik[3][2][0]*c6)+(Cik[3][2][1]*s6)));
    gk[6][1] = (9.81*((Cik[3][2][0]*s6)-(Cik[3][2][1]*c6)));
    gk[7][0] = ((9.81*(Cik[3][2][2]*s7))+(gk[6][0]*c7));
    gk[7][2] = ((gk[6][0]*s7)-(9.81*(Cik[3][2][2]*c7)));
    gk[8][1] = ((gk[6][1]*c8)+(gk[7][2]*s8));
    gk[8][2] = ((gk[7][2]*c8)-(gk[6][1]*s8));
    gk[9][0] = ((gk[7][0]*c9)-(gk[8][2]*s9));
    gk[9][2] = ((gk[7][0]*s9)+(gk[8][2]*c9));
    gk[10][0] = ((gk[9][0]*c10)-(gk[9][2]*s10));
    gk[10][2] = ((gk[9][0]*s10)+(gk[9][2]*c10));
    gk[11][1] = ((gk[8][1]*c11)+(gk[10][2]*s11));
    gk[11][2] = ((gk[10][2]*c11)-(gk[8][1]*s11));
    gk[12][0] = -(9.81*((Cik[3][2][0]*c12)+(Cik[3][2][1]*s12)));
    gk[12][1] = (9.81*((Cik[3][2][0]*s12)-(Cik[3][2][1]*c12)));
    gk[13][0] = ((9.81*(Cik[3][2][2]*s13))+(gk[12][0]*c13));
    gk[13][2] = ((gk[12][0]*s13)-(9.81*(Cik[3][2][2]*c13)));
    gk[14][1] = ((gk[12][1]*c14)+(gk[13][2]*s14));
    gk[14][2] = ((gk[13][2]*c14)-(gk[12][1]*s14));
    gk[15][0] = ((gk[13][0]*c15)-(gk[14][2]*s15));
    gk[15][2] = ((gk[13][0]*s15)+(gk[14][2]*c15));
    gk[16][0] = ((gk[15][0]*c16)-(gk[15][2]*s16));
    gk[16][2] = ((gk[15][0]*s16)+(gk[15][2]*c16));
    gk[17][1] = ((gk[14][1]*c17)+(gk[16][2]*s17));
    gk[17][2] = ((gk[16][2]*c17)-(gk[14][1]*s17));
    gk[18][0] = (9.81*((Cik[3][2][2]*s18)-(Cik[3][2][0]*c18)));
    gk[18][2] = -(9.81*((Cik[3][2][0]*s18)+(Cik[3][2][2]*c18)));
    gk[19][1] = ((gk[18][2]*s19)-(9.81*(Cik[3][2][1]*c19)));
    gk[19][2] = ((9.81*(Cik[3][2][1]*s19))+(gk[18][2]*c19));
    gk[20][0] = ((gk[18][0]*c20)-(gk[19][2]*s20));
    gk[20][2] = ((gk[18][0]*s20)+(gk[19][2]*c20));
    gk[21][0] = ((gk[19][1]*s21)+(gk[20][0]*c21));
    gk[21][1] = ((gk[19][1]*c21)-(gk[20][0]*s21));
    gk[22][0] = (9.81*((Cik[3][2][2]*s22)-(Cik[3][2][0]*c22)));
    gk[22][2] = -(9.81*((Cik[3][2][0]*s22)+(Cik[3][2][2]*c22)));
    gk[23][1] = ((gk[22][2]*s23)-(9.81*(Cik[3][2][1]*c23)));
    gk[23][2] = ((9.81*(Cik[3][2][1]*s23))+(gk[22][2]*c23));
    gk[24][0] = ((gk[22][0]*c24)-(gk[23][2]*s24));
    gk[24][2] = ((gk[22][0]*s24)+(gk[23][2]*c24));
    gk[25][0] = ((gk[23][1]*s25)+(gk[24][0]*c25));
    gk[25][1] = ((gk[23][1]*c25)-(gk[24][0]*s25));
/*
Compute cnk & cnb (direction cosines in N)
*/
    cnk[6][0][0] = ((Cik[3][0][0]*c6)+(Cik[3][0][1]*s6));
    cnk[6][0][1] = ((Cik[3][0][1]*c6)-(Cik[3][0][0]*s6));
    cnk[6][1][0] = ((Cik[3][1][0]*c6)+(Cik[3][1][1]*s6));
    cnk[6][1][1] = ((Cik[3][1][1]*c6)-(Cik[3][1][0]*s6));
    cnk[6][2][0] = ((Cik[3][2][0]*c6)+(Cik[3][2][1]*s6));
    cnk[6][2][1] = ((Cik[3][2][1]*c6)-(Cik[3][2][0]*s6));
    cnk[7][0][0] = ((cnk[6][0][0]*c7)-(Cik[3][0][2]*s7));
    cnk[7][0][2] = ((Cik[3][0][2]*c7)+(cnk[6][0][0]*s7));
    cnk[7][1][0] = ((cnk[6][1][0]*c7)-(Cik[3][1][2]*s7));
    cnk[7][1][2] = ((Cik[3][1][2]*c7)+(cnk[6][1][0]*s7));
    cnk[7][2][0] = ((cnk[6][2][0]*c7)-(Cik[3][2][2]*s7));
    cnk[7][2][2] = ((Cik[3][2][2]*c7)+(cnk[6][2][0]*s7));
    cnk[8][0][1] = ((cnk[6][0][1]*c8)+(cnk[7][0][2]*s8));
    cnk[8][0][2] = ((cnk[7][0][2]*c8)-(cnk[6][0][1]*s8));
    cnk[8][1][1] = ((cnk[6][1][1]*c8)+(cnk[7][1][2]*s8));
    cnk[8][1][2] = ((cnk[7][1][2]*c8)-(cnk[6][1][1]*s8));
    cnk[8][2][1] = ((cnk[6][2][1]*c8)+(cnk[7][2][2]*s8));
    cnk[8][2][2] = ((cnk[7][2][2]*c8)-(cnk[6][2][1]*s8));
    cnk[9][0][0] = ((cnk[7][0][0]*c9)-(cnk[8][0][2]*s9));
    cnk[9][0][2] = ((cnk[7][0][0]*s9)+(cnk[8][0][2]*c9));
    cnk[9][1][0] = ((cnk[7][1][0]*c9)-(cnk[8][1][2]*s9));
    cnk[9][1][2] = ((cnk[7][1][0]*s9)+(cnk[8][1][2]*c9));
    cnk[9][2][0] = ((cnk[7][2][0]*c9)-(cnk[8][2][2]*s9));
    cnk[9][2][2] = ((cnk[7][2][0]*s9)+(cnk[8][2][2]*c9));
    cnk[10][0][0] = ((cnk[9][0][0]*c10)-(cnk[9][0][2]*s10));
    cnk[10][0][2] = ((cnk[9][0][0]*s10)+(cnk[9][0][2]*c10));
    cnk[10][1][0] = ((cnk[9][1][0]*c10)-(cnk[9][1][2]*s10));
    cnk[10][1][2] = ((cnk[9][1][0]*s10)+(cnk[9][1][2]*c10));
    cnk[10][2][0] = ((cnk[9][2][0]*c10)-(cnk[9][2][2]*s10));
    cnk[10][2][2] = ((cnk[9][2][0]*s10)+(cnk[9][2][2]*c10));
    cnk[11][0][1] = ((cnk[8][0][1]*c11)+(cnk[10][0][2]*s11));
    cnk[11][0][2] = ((cnk[10][0][2]*c11)-(cnk[8][0][1]*s11));
    cnk[11][1][1] = ((cnk[8][1][1]*c11)+(cnk[10][1][2]*s11));
    cnk[11][1][2] = ((cnk[10][1][2]*c11)-(cnk[8][1][1]*s11));
    cnk[11][2][1] = ((cnk[8][2][1]*c11)+(cnk[10][2][2]*s11));
    cnk[11][2][2] = ((cnk[10][2][2]*c11)-(cnk[8][2][1]*s11));
    cnk[12][0][0] = ((Cik[3][0][0]*c12)+(Cik[3][0][1]*s12));
    cnk[12][0][1] = ((Cik[3][0][1]*c12)-(Cik[3][0][0]*s12));
    cnk[12][1][0] = ((Cik[3][1][0]*c12)+(Cik[3][1][1]*s12));
    cnk[12][1][1] = ((Cik[3][1][1]*c12)-(Cik[3][1][0]*s12));
    cnk[12][2][0] = ((Cik[3][2][0]*c12)+(Cik[3][2][1]*s12));
    cnk[12][2][1] = ((Cik[3][2][1]*c12)-(Cik[3][2][0]*s12));
    cnk[13][0][0] = ((cnk[12][0][0]*c13)-(Cik[3][0][2]*s13));
    cnk[13][0][2] = ((Cik[3][0][2]*c13)+(cnk[12][0][0]*s13));
    cnk[13][1][0] = ((cnk[12][1][0]*c13)-(Cik[3][1][2]*s13));
    cnk[13][1][2] = ((Cik[3][1][2]*c13)+(cnk[12][1][0]*s13));
    cnk[13][2][0] = ((cnk[12][2][0]*c13)-(Cik[3][2][2]*s13));
    cnk[13][2][2] = ((Cik[3][2][2]*c13)+(cnk[12][2][0]*s13));
    cnk[14][0][1] = ((cnk[12][0][1]*c14)+(cnk[13][0][2]*s14));
    cnk[14][0][2] = ((cnk[13][0][2]*c14)-(cnk[12][0][1]*s14));
    cnk[14][1][1] = ((cnk[12][1][1]*c14)+(cnk[13][1][2]*s14));
    cnk[14][1][2] = ((cnk[13][1][2]*c14)-(cnk[12][1][1]*s14));
    cnk[14][2][1] = ((cnk[12][2][1]*c14)+(cnk[13][2][2]*s14));
    cnk[14][2][2] = ((cnk[13][2][2]*c14)-(cnk[12][2][1]*s14));
    cnk[15][0][0] = ((cnk[13][0][0]*c15)-(cnk[14][0][2]*s15));
    cnk[15][0][2] = ((cnk[13][0][0]*s15)+(cnk[14][0][2]*c15));
    cnk[15][1][0] = ((cnk[13][1][0]*c15)-(cnk[14][1][2]*s15));
    cnk[15][1][2] = ((cnk[13][1][0]*s15)+(cnk[14][1][2]*c15));
    cnk[15][2][0] = ((cnk[13][2][0]*c15)-(cnk[14][2][2]*s15));
    cnk[15][2][2] = ((cnk[13][2][0]*s15)+(cnk[14][2][2]*c15));
    cnk[16][0][0] = ((cnk[15][0][0]*c16)-(cnk[15][0][2]*s16));
    cnk[16][0][2] = ((cnk[15][0][0]*s16)+(cnk[15][0][2]*c16));
    cnk[16][1][0] = ((cnk[15][1][0]*c16)-(cnk[15][1][2]*s16));
    cnk[16][1][2] = ((cnk[15][1][0]*s16)+(cnk[15][1][2]*c16));
    cnk[16][2][0] = ((cnk[15][2][0]*c16)-(cnk[15][2][2]*s16));
    cnk[16][2][2] = ((cnk[15][2][0]*s16)+(cnk[15][2][2]*c16));
    cnk[17][0][1] = ((cnk[14][0][1]*c17)+(cnk[16][0][2]*s17));
    cnk[17][0][2] = ((cnk[16][0][2]*c17)-(cnk[14][0][1]*s17));
    cnk[17][1][1] = ((cnk[14][1][1]*c17)+(cnk[16][1][2]*s17));
    cnk[17][1][2] = ((cnk[16][1][2]*c17)-(cnk[14][1][1]*s17));
    cnk[17][2][1] = ((cnk[14][2][1]*c17)+(cnk[16][2][2]*s17));
    cnk[17][2][2] = ((cnk[16][2][2]*c17)-(cnk[14][2][1]*s17));
    cnk[18][0][0] = ((Cik[3][0][0]*c18)-(Cik[3][0][2]*s18));
    cnk[18][0][2] = ((Cik[3][0][0]*s18)+(Cik[3][0][2]*c18));
    cnk[18][1][0] = ((Cik[3][1][0]*c18)-(Cik[3][1][2]*s18));
    cnk[18][1][2] = ((Cik[3][1][0]*s18)+(Cik[3][1][2]*c18));
    cnk[18][2][0] = ((Cik[3][2][0]*c18)-(Cik[3][2][2]*s18));
    cnk[18][2][2] = ((Cik[3][2][0]*s18)+(Cik[3][2][2]*c18));
    cnk[19][0][1] = ((Cik[3][0][1]*c19)+(cnk[18][0][2]*s19));
    cnk[19][0][2] = ((cnk[18][0][2]*c19)-(Cik[3][0][1]*s19));
    cnk[19][1][1] = ((Cik[3][1][1]*c19)+(cnk[18][1][2]*s19));
    cnk[19][1][2] = ((cnk[18][1][2]*c19)-(Cik[3][1][1]*s19));
    cnk[19][2][1] = ((Cik[3][2][1]*c19)+(cnk[18][2][2]*s19));
    cnk[19][2][2] = ((cnk[18][2][2]*c19)-(Cik[3][2][1]*s19));
    cnk[20][0][0] = ((cnk[18][0][0]*c20)-(cnk[19][0][2]*s20));
    cnk[20][0][2] = ((cnk[18][0][0]*s20)+(cnk[19][0][2]*c20));
    cnk[20][1][0] = ((cnk[18][1][0]*c20)-(cnk[19][1][2]*s20));
    cnk[20][1][2] = ((cnk[18][1][0]*s20)+(cnk[19][1][2]*c20));
    cnk[20][2][0] = ((cnk[18][2][0]*c20)-(cnk[19][2][2]*s20));
    cnk[20][2][2] = ((cnk[18][2][0]*s20)+(cnk[19][2][2]*c20));
    cnk[21][0][0] = ((cnk[19][0][1]*s21)+(cnk[20][0][0]*c21));
    cnk[21][0][1] = ((cnk[19][0][1]*c21)-(cnk[20][0][0]*s21));
    cnk[21][1][0] = ((cnk[19][1][1]*s21)+(cnk[20][1][0]*c21));
    cnk[21][1][1] = ((cnk[19][1][1]*c21)-(cnk[20][1][0]*s21));
    cnk[21][2][0] = ((cnk[19][2][1]*s21)+(cnk[20][2][0]*c21));
    cnk[21][2][1] = ((cnk[19][2][1]*c21)-(cnk[20][2][0]*s21));
    cnk[22][0][0] = ((Cik[3][0][0]*c22)-(Cik[3][0][2]*s22));
    cnk[22][0][2] = ((Cik[3][0][0]*s22)+(Cik[3][0][2]*c22));
    cnk[22][1][0] = ((Cik[3][1][0]*c22)-(Cik[3][1][2]*s22));
    cnk[22][1][2] = ((Cik[3][1][0]*s22)+(Cik[3][1][2]*c22));
    cnk[22][2][0] = ((Cik[3][2][0]*c22)-(Cik[3][2][2]*s22));
    cnk[22][2][2] = ((Cik[3][2][0]*s22)+(Cik[3][2][2]*c22));
    cnk[23][0][1] = ((Cik[3][0][1]*c23)+(cnk[22][0][2]*s23));
    cnk[23][0][2] = ((cnk[22][0][2]*c23)-(Cik[3][0][1]*s23));
    cnk[23][1][1] = ((Cik[3][1][1]*c23)+(cnk[22][1][2]*s23));
    cnk[23][1][2] = ((cnk[22][1][2]*c23)-(Cik[3][1][1]*s23));
    cnk[23][2][1] = ((Cik[3][2][1]*c23)+(cnk[22][2][2]*s23));
    cnk[23][2][2] = ((cnk[22][2][2]*c23)-(Cik[3][2][1]*s23));
    cnk[24][0][0] = ((cnk[22][0][0]*c24)-(cnk[23][0][2]*s24));
    cnk[24][0][2] = ((cnk[22][0][0]*s24)+(cnk[23][0][2]*c24));
    cnk[24][1][0] = ((cnk[22][1][0]*c24)-(cnk[23][1][2]*s24));
    cnk[24][1][2] = ((cnk[22][1][0]*s24)+(cnk[23][1][2]*c24));
    cnk[24][2][0] = ((cnk[22][2][0]*c24)-(cnk[23][2][2]*s24));
    cnk[24][2][2] = ((cnk[22][2][0]*s24)+(cnk[23][2][2]*c24));
    cnk[25][0][0] = ((cnk[23][0][1]*s25)+(cnk[24][0][0]*c25));
    cnk[25][0][1] = ((cnk[23][0][1]*c25)-(cnk[24][0][0]*s25));
    cnk[25][1][0] = ((cnk[23][1][1]*s25)+(cnk[24][1][0]*c25));
    cnk[25][1][1] = ((cnk[23][1][1]*c25)-(cnk[24][1][0]*s25));
    cnk[25][2][0] = ((cnk[23][2][1]*s25)+(cnk[24][2][0]*c25));
    cnk[25][2][1] = ((cnk[23][2][1]*c25)-(cnk[24][2][0]*s25));
    cnb[0][0][0] = Cik[3][0][0];
    cnb[0][0][1] = Cik[3][0][1];
    cnb[0][0][2] = Cik[3][0][2];
    cnb[0][1][0] = Cik[3][1][0];
    cnb[0][1][1] = Cik[3][1][1];
    cnb[0][1][2] = Cik[3][1][2];
    cnb[0][2][0] = Cik[3][2][0];
    cnb[0][2][1] = Cik[3][2][1];
    cnb[0][2][2] = Cik[3][2][2];
    cnb[1][0][0] = cnk[6][0][0];
    cnb[1][0][1] = cnk[6][0][1];
    cnb[1][0][2] = Cik[3][0][2];
    cnb[1][1][0] = cnk[6][1][0];
    cnb[1][1][1] = cnk[6][1][1];
    cnb[1][1][2] = Cik[3][1][2];
    cnb[1][2][0] = cnk[6][2][0];
    cnb[1][2][1] = cnk[6][2][1];
    cnb[1][2][2] = Cik[3][2][2];
    cnb[2][0][0] = cnk[7][0][0];
    cnb[2][0][1] = cnk[6][0][1];
    cnb[2][0][2] = cnk[7][0][2];
    cnb[2][1][0] = cnk[7][1][0];
    cnb[2][1][1] = cnk[6][1][1];
    cnb[2][1][2] = cnk[7][1][2];
    cnb[2][2][0] = cnk[7][2][0];
    cnb[2][2][1] = cnk[6][2][1];
    cnb[2][2][2] = cnk[7][2][2];
    cnb[3][0][0] = cnk[7][0][0];
    cnb[3][0][1] = cnk[8][0][1];
    cnb[3][0][2] = cnk[8][0][2];
    cnb[3][1][0] = cnk[7][1][0];
    cnb[3][1][1] = cnk[8][1][1];
    cnb[3][1][2] = cnk[8][1][2];
    cnb[3][2][0] = cnk[7][2][0];
    cnb[3][2][1] = cnk[8][2][1];
    cnb[3][2][2] = cnk[8][2][2];
    cnb[4][0][0] = cnk[9][0][0];
    cnb[4][0][1] = cnk[8][0][1];
    cnb[4][0][2] = cnk[9][0][2];
    cnb[4][1][0] = cnk[9][1][0];
    cnb[4][1][1] = cnk[8][1][1];
    cnb[4][1][2] = cnk[9][1][2];
    cnb[4][2][0] = cnk[9][2][0];
    cnb[4][2][1] = cnk[8][2][1];
    cnb[4][2][2] = cnk[9][2][2];
    cnb[5][0][0] = cnk[10][0][0];
    cnb[5][0][1] = cnk[8][0][1];
    cnb[5][0][2] = cnk[10][0][2];
    cnb[5][1][0] = cnk[10][1][0];
    cnb[5][1][1] = cnk[8][1][1];
    cnb[5][1][2] = cnk[10][1][2];
    cnb[5][2][0] = cnk[10][2][0];
    cnb[5][2][1] = cnk[8][2][1];
    cnb[5][2][2] = cnk[10][2][2];
    cnb[6][0][0] = cnk[10][0][0];
    cnb[6][0][1] = cnk[11][0][1];
    cnb[6][0][2] = cnk[11][0][2];
    cnb[6][1][0] = cnk[10][1][0];
    cnb[6][1][1] = cnk[11][1][1];
    cnb[6][1][2] = cnk[11][1][2];
    cnb[6][2][0] = cnk[10][2][0];
    cnb[6][2][1] = cnk[11][2][1];
    cnb[6][2][2] = cnk[11][2][2];
    cnb[7][0][0] = cnk[12][0][0];
    cnb[7][0][1] = cnk[12][0][1];
    cnb[7][0][2] = Cik[3][0][2];
    cnb[7][1][0] = cnk[12][1][0];
    cnb[7][1][1] = cnk[12][1][1];
    cnb[7][1][2] = Cik[3][1][2];
    cnb[7][2][0] = cnk[12][2][0];
    cnb[7][2][1] = cnk[12][2][1];
    cnb[7][2][2] = Cik[3][2][2];
    cnb[8][0][0] = cnk[13][0][0];
    cnb[8][0][1] = cnk[12][0][1];
    cnb[8][0][2] = cnk[13][0][2];
    cnb[8][1][0] = cnk[13][1][0];
    cnb[8][1][1] = cnk[12][1][1];
    cnb[8][1][2] = cnk[13][1][2];
    cnb[8][2][0] = cnk[13][2][0];
    cnb[8][2][1] = cnk[12][2][1];
    cnb[8][2][2] = cnk[13][2][2];
    cnb[9][0][0] = cnk[13][0][0];
    cnb[9][0][1] = cnk[14][0][1];
    cnb[9][0][2] = cnk[14][0][2];
    cnb[9][1][0] = cnk[13][1][0];
    cnb[9][1][1] = cnk[14][1][1];
    cnb[9][1][2] = cnk[14][1][2];
    cnb[9][2][0] = cnk[13][2][0];
    cnb[9][2][1] = cnk[14][2][1];
    cnb[9][2][2] = cnk[14][2][2];
    cnb[10][0][0] = cnk[15][0][0];
    cnb[10][0][1] = cnk[14][0][1];
    cnb[10][0][2] = cnk[15][0][2];
    cnb[10][1][0] = cnk[15][1][0];
    cnb[10][1][1] = cnk[14][1][1];
    cnb[10][1][2] = cnk[15][1][2];
    cnb[10][2][0] = cnk[15][2][0];
    cnb[10][2][1] = cnk[14][2][1];
    cnb[10][2][2] = cnk[15][2][2];
    cnb[11][0][0] = cnk[16][0][0];
    cnb[11][0][1] = cnk[14][0][1];
    cnb[11][0][2] = cnk[16][0][2];
    cnb[11][1][0] = cnk[16][1][0];
    cnb[11][1][1] = cnk[14][1][1];
    cnb[11][1][2] = cnk[16][1][2];
    cnb[11][2][0] = cnk[16][2][0];
    cnb[11][2][1] = cnk[14][2][1];
    cnb[11][2][2] = cnk[16][2][2];
    cnb[12][0][0] = cnk[16][0][0];
    cnb[12][0][1] = cnk[17][0][1];
    cnb[12][0][2] = cnk[17][0][2];
    cnb[12][1][0] = cnk[16][1][0];
    cnb[12][1][1] = cnk[17][1][1];
    cnb[12][1][2] = cnk[17][1][2];
    cnb[12][2][0] = cnk[16][2][0];
    cnb[12][2][1] = cnk[17][2][1];
    cnb[12][2][2] = cnk[17][2][2];
    cnb[13][0][0] = cnk[18][0][0];
    cnb[13][0][1] = Cik[3][0][1];
    cnb[13][0][2] = cnk[18][0][2];
    cnb[13][1][0] = cnk[18][1][0];
    cnb[13][1][1] = Cik[3][1][1];
    cnb[13][1][2] = cnk[18][1][2];
    cnb[13][2][0] = cnk[18][2][0];
    cnb[13][2][1] = Cik[3][2][1];
    cnb[13][2][2] = cnk[18][2][2];
    cnb[14][0][0] = cnk[18][0][0];
    cnb[14][0][1] = cnk[19][0][1];
    cnb[14][0][2] = cnk[19][0][2];
    cnb[14][1][0] = cnk[18][1][0];
    cnb[14][1][1] = cnk[19][1][1];
    cnb[14][1][2] = cnk[19][1][2];
    cnb[14][2][0] = cnk[18][2][0];
    cnb[14][2][1] = cnk[19][2][1];
    cnb[14][2][2] = cnk[19][2][2];
    cnb[15][0][0] = cnk[20][0][0];
    cnb[15][0][1] = cnk[19][0][1];
    cnb[15][0][2] = cnk[20][0][2];
    cnb[15][1][0] = cnk[20][1][0];
    cnb[15][1][1] = cnk[19][1][1];
    cnb[15][1][2] = cnk[20][1][2];
    cnb[15][2][0] = cnk[20][2][0];
    cnb[15][2][1] = cnk[19][2][1];
    cnb[15][2][2] = cnk[20][2][2];
    cnb[16][0][0] = cnk[21][0][0];
    cnb[16][0][1] = cnk[21][0][1];
    cnb[16][0][2] = cnk[20][0][2];
    cnb[16][1][0] = cnk[21][1][0];
    cnb[16][1][1] = cnk[21][1][1];
    cnb[16][1][2] = cnk[20][1][2];
    cnb[16][2][0] = cnk[21][2][0];
    cnb[16][2][1] = cnk[21][2][1];
    cnb[16][2][2] = cnk[20][2][2];
    cnb[17][0][0] = cnk[22][0][0];
    cnb[17][0][1] = Cik[3][0][1];
    cnb[17][0][2] = cnk[22][0][2];
    cnb[17][1][0] = cnk[22][1][0];
    cnb[17][1][1] = Cik[3][1][1];
    cnb[17][1][2] = cnk[22][1][2];
    cnb[17][2][0] = cnk[22][2][0];
    cnb[17][2][1] = Cik[3][2][1];
    cnb[17][2][2] = cnk[22][2][2];
    cnb[18][0][0] = cnk[22][0][0];
    cnb[18][0][1] = cnk[23][0][1];
    cnb[18][0][2] = cnk[23][0][2];
    cnb[18][1][0] = cnk[22][1][0];
    cnb[18][1][1] = cnk[23][1][1];
    cnb[18][1][2] = cnk[23][1][2];
    cnb[18][2][0] = cnk[22][2][0];
    cnb[18][2][1] = cnk[23][2][1];
    cnb[18][2][2] = cnk[23][2][2];
    cnb[19][0][0] = cnk[24][0][0];
    cnb[19][0][1] = cnk[23][0][1];
    cnb[19][0][2] = cnk[24][0][2];
    cnb[19][1][0] = cnk[24][1][0];
    cnb[19][1][1] = cnk[23][1][1];
    cnb[19][1][2] = cnk[24][1][2];
    cnb[19][2][0] = cnk[24][2][0];
    cnb[19][2][1] = cnk[23][2][1];
    cnb[19][2][2] = cnk[24][2][2];
    cnb[20][0][0] = cnk[25][0][0];
    cnb[20][0][1] = cnk[25][0][1];
    cnb[20][0][2] = cnk[24][0][2];
    cnb[20][1][0] = cnk[25][1][0];
    cnb[20][1][1] = cnk[25][1][1];
    cnb[20][1][2] = cnk[24][1][2];
    cnb[20][2][0] = cnk[25][2][0];
    cnb[20][2][1] = cnk[25][2][1];
    cnb[20][2][2] = cnk[24][2][2];
/*
Compute q-related auxiliary variables
*/
    rpri[0][0] = (q[0]+ri[0][0]);
    rik[0][0] = (q[0]+ri[0][0]);
    rik[6][0] = (((ri[1][0]*c6)+(ri[1][1]*s6))-rk[1][0]);
    rik[6][1] = (((ri[1][1]*c6)-(ri[1][0]*s6))-rk[1][1]);
    rik[6][2] = (ri[1][2]-rk[1][2]);
    rik[7][0] = (((ri[2][0]*c7)-(ri[2][2]*s7))-rk[2][0]);
    rik[7][1] = (ri[2][1]-rk[2][1]);
    rik[7][2] = (((ri[2][0]*s7)+(ri[2][2]*c7))-rk[2][2]);
    rik[8][0] = (ri[3][0]-rk[3][0]);
    rik[8][1] = (((ri[3][1]*c8)+(ri[3][2]*s8))-rk[3][1]);
    rik[8][2] = (((ri[3][2]*c8)-(ri[3][1]*s8))-rk[3][2]);
    rik[9][0] = (((ri[4][0]*c9)-(ri[4][2]*s9))-rk[4][0]);
    rik[9][1] = (ri[4][1]-rk[4][1]);
    rik[9][2] = (((ri[4][0]*s9)+(ri[4][2]*c9))-rk[4][2]);
    rik[10][0] = (((ri[5][0]*c10)-(ri[5][2]*s10))-rk[5][0]);
    rik[10][1] = (ri[5][1]-rk[5][1]);
    rik[10][2] = (((ri[5][0]*s10)+(ri[5][2]*c10))-rk[5][2]);
    rik[11][0] = (ri[6][0]-rk[6][0]);
    rik[11][1] = (((ri[6][1]*c11)+(ri[6][2]*s11))-rk[6][1]);
    rik[11][2] = (((ri[6][2]*c11)-(ri[6][1]*s11))-rk[6][2]);
    rik[12][0] = (((ri[7][0]*c12)+(ri[7][1]*s12))-rk[7][0]);
    rik[12][1] = (((ri[7][1]*c12)-(ri[7][0]*s12))-rk[7][1]);
    rik[12][2] = (ri[7][2]-rk[7][2]);
    rik[13][0] = (((ri[8][0]*c13)-(ri[8][2]*s13))-rk[8][0]);
    rik[13][1] = (ri[8][1]-rk[8][1]);
    rik[13][2] = (((ri[8][0]*s13)+(ri[8][2]*c13))-rk[8][2]);
    rik[14][0] = (ri[9][0]-rk[9][0]);
    rik[14][1] = (((ri[9][1]*c14)+(ri[9][2]*s14))-rk[9][1]);
    rik[14][2] = (((ri[9][2]*c14)-(ri[9][1]*s14))-rk[9][2]);
    rik[15][0] = (((ri[10][0]*c15)-(ri[10][2]*s15))-rk[10][0]);
    rik[15][1] = (ri[10][1]-rk[10][1]);
    rik[15][2] = (((ri[10][0]*s15)+(ri[10][2]*c15))-rk[10][2]);
    rik[16][0] = (((ri[11][0]*c16)-(ri[11][2]*s16))-rk[11][0]);
    rik[16][1] = (ri[11][1]-rk[11][1]);
    rik[16][2] = (((ri[11][0]*s16)+(ri[11][2]*c16))-rk[11][2]);
    rik[17][0] = (ri[12][0]-rk[12][0]);
    rik[17][1] = (((ri[12][1]*c17)+(ri[12][2]*s17))-rk[12][1]);
    rik[17][2] = (((ri[12][2]*c17)-(ri[12][1]*s17))-rk[12][2]);
    rik[18][0] = (((ri[13][0]*c18)-(ri[13][2]*s18))-rk[13][0]);
    rik[18][1] = (ri[13][1]-rk[13][1]);
    rik[18][2] = (((ri[13][0]*s18)+(ri[13][2]*c18))-rk[13][2]);
    rik[19][0] = (ri[14][0]-rk[14][0]);
    rik[19][1] = (((ri[14][1]*c19)+(ri[14][2]*s19))-rk[14][1]);
    rik[19][2] = (((ri[14][2]*c19)-(ri[14][1]*s19))-rk[14][2]);
    rik[20][0] = (((ri[15][0]*c20)-(ri[15][2]*s20))-rk[15][0]);
    rik[20][1] = (ri[15][1]-rk[15][1]);
    rik[20][2] = (((ri[15][0]*s20)+(ri[15][2]*c20))-rk[15][2]);
    rik[21][0] = (((ri[16][0]*c21)+(ri[16][1]*s21))-rk[16][0]);
    rik[21][1] = (((ri[16][1]*c21)-(ri[16][0]*s21))-rk[16][1]);
    rik[21][2] = (ri[16][2]-rk[16][2]);
    rik[22][0] = (((ri[17][0]*c22)-(ri[17][2]*s22))-rk[17][0]);
    rik[22][1] = (ri[17][1]-rk[17][1]);
    rik[22][2] = (((ri[17][0]*s22)+(ri[17][2]*c22))-rk[17][2]);
    rik[23][0] = (ri[18][0]-rk[18][0]);
    rik[23][1] = (((ri[18][1]*c23)+(ri[18][2]*s23))-rk[18][1]);
    rik[23][2] = (((ri[18][2]*c23)-(ri[18][1]*s23))-rk[18][2]);
    rik[24][0] = (((ri[19][0]*c24)-(ri[19][2]*s24))-rk[19][0]);
    rik[24][1] = (ri[19][1]-rk[19][1]);
    rik[24][2] = (((ri[19][0]*s24)+(ri[19][2]*c24))-rk[19][2]);
    rik[25][0] = (((ri[20][0]*c25)+(ri[20][1]*s25))-rk[20][0]);
    rik[25][1] = (((ri[20][1]*c25)-(ri[20][0]*s25))-rk[20][1]);
    rik[25][2] = (ri[20][2]-rk[20][2]);
/*
Compute rnk & rnb (mass center locations in N)
*/
    rnk[0][0] = (q[0]+ri[0][0]);
    rnk[1][1] = (q[1]+ri[0][1]);
    rnk[2][2] = (q[2]+ri[0][2]);
    rnk[5][0] = (rnk[0][0]-((Cik[3][0][2]*rk[0][2])+((Cik[3][0][0]*rk[0][0])+(
      Cik[3][0][1]*rk[0][1]))));
    rnk[5][1] = (rnk[1][1]-((Cik[3][1][2]*rk[0][2])+((Cik[3][1][0]*rk[0][0])+(
      Cik[3][1][1]*rk[0][1]))));
    rnk[5][2] = (rnk[2][2]-((Cik[3][2][2]*rk[0][2])+((Cik[3][2][0]*rk[0][0])+(
      Cik[3][2][1]*rk[0][1]))));
    rnk[6][0] = ((rnk[5][0]+((Cik[3][0][2]*ri[1][2])+((Cik[3][0][0]*ri[1][0])+(
      Cik[3][0][1]*ri[1][1]))))-((Cik[3][0][2]*rk[1][2])+((cnk[6][0][0]*rk[1][0]
      )+(cnk[6][0][1]*rk[1][1]))));
    rnk[6][1] = ((rnk[5][1]+((Cik[3][1][2]*ri[1][2])+((Cik[3][1][0]*ri[1][0])+(
      Cik[3][1][1]*ri[1][1]))))-((Cik[3][1][2]*rk[1][2])+((cnk[6][1][0]*rk[1][0]
      )+(cnk[6][1][1]*rk[1][1]))));
    rnk[6][2] = ((rnk[5][2]+((Cik[3][2][2]*ri[1][2])+((Cik[3][2][0]*ri[1][0])+(
      Cik[3][2][1]*ri[1][1]))))-((Cik[3][2][2]*rk[1][2])+((cnk[6][2][0]*rk[1][0]
      )+(cnk[6][2][1]*rk[1][1]))));
    rnk[7][0] = ((rnk[6][0]+((Cik[3][0][2]*ri[2][2])+((cnk[6][0][0]*ri[2][0])+(
      cnk[6][0][1]*ri[2][1]))))-((cnk[7][0][2]*rk[2][2])+((cnk[6][0][1]*rk[2][1]
      )+(cnk[7][0][0]*rk[2][0]))));
    rnk[7][1] = ((rnk[6][1]+((Cik[3][1][2]*ri[2][2])+((cnk[6][1][0]*ri[2][0])+(
      cnk[6][1][1]*ri[2][1]))))-((cnk[7][1][2]*rk[2][2])+((cnk[6][1][1]*rk[2][1]
      )+(cnk[7][1][0]*rk[2][0]))));
    rnk[7][2] = ((rnk[6][2]+((Cik[3][2][2]*ri[2][2])+((cnk[6][2][0]*ri[2][0])+(
      cnk[6][2][1]*ri[2][1]))))-((cnk[7][2][2]*rk[2][2])+((cnk[6][2][1]*rk[2][1]
      )+(cnk[7][2][0]*rk[2][0]))));
    rnk[8][0] = ((rnk[7][0]+((cnk[7][0][2]*ri[3][2])+((cnk[6][0][1]*ri[3][1])+(
      cnk[7][0][0]*ri[3][0]))))-((cnk[8][0][2]*rk[3][2])+((cnk[7][0][0]*rk[3][0]
      )+(cnk[8][0][1]*rk[3][1]))));
    rnk[8][1] = ((rnk[7][1]+((cnk[7][1][2]*ri[3][2])+((cnk[6][1][1]*ri[3][1])+(
      cnk[7][1][0]*ri[3][0]))))-((cnk[8][1][2]*rk[3][2])+((cnk[7][1][0]*rk[3][0]
      )+(cnk[8][1][1]*rk[3][1]))));
    rnk[8][2] = ((rnk[7][2]+((cnk[7][2][2]*ri[3][2])+((cnk[6][2][1]*ri[3][1])+(
      cnk[7][2][0]*ri[3][0]))))-((cnk[8][2][2]*rk[3][2])+((cnk[7][2][0]*rk[3][0]
      )+(cnk[8][2][1]*rk[3][1]))));
    rnk[9][0] = ((rnk[8][0]+((cnk[8][0][2]*ri[4][2])+((cnk[7][0][0]*ri[4][0])+(
      cnk[8][0][1]*ri[4][1]))))-((cnk[9][0][2]*rk[4][2])+((cnk[8][0][1]*rk[4][1]
      )+(cnk[9][0][0]*rk[4][0]))));
    rnk[9][1] = ((rnk[8][1]+((cnk[8][1][2]*ri[4][2])+((cnk[7][1][0]*ri[4][0])+(
      cnk[8][1][1]*ri[4][1]))))-((cnk[9][1][2]*rk[4][2])+((cnk[8][1][1]*rk[4][1]
      )+(cnk[9][1][0]*rk[4][0]))));
    rnk[9][2] = ((rnk[8][2]+((cnk[8][2][2]*ri[4][2])+((cnk[7][2][0]*ri[4][0])+(
      cnk[8][2][1]*ri[4][1]))))-((cnk[9][2][2]*rk[4][2])+((cnk[8][2][1]*rk[4][1]
      )+(cnk[9][2][0]*rk[4][0]))));
    rnk[10][0] = ((rnk[9][0]+((cnk[9][0][2]*ri[5][2])+((cnk[8][0][1]*ri[5][1])+(
      cnk[9][0][0]*ri[5][0]))))-((cnk[10][0][2]*rk[5][2])+((cnk[8][0][1]*
      rk[5][1])+(cnk[10][0][0]*rk[5][0]))));
    rnk[10][1] = ((rnk[9][1]+((cnk[9][1][2]*ri[5][2])+((cnk[8][1][1]*ri[5][1])+(
      cnk[9][1][0]*ri[5][0]))))-((cnk[10][1][2]*rk[5][2])+((cnk[8][1][1]*
      rk[5][1])+(cnk[10][1][0]*rk[5][0]))));
    rnk[10][2] = ((rnk[9][2]+((cnk[9][2][2]*ri[5][2])+((cnk[8][2][1]*ri[5][1])+(
      cnk[9][2][0]*ri[5][0]))))-((cnk[10][2][2]*rk[5][2])+((cnk[8][2][1]*
      rk[5][1])+(cnk[10][2][0]*rk[5][0]))));
    rnk[11][0] = ((rnk[10][0]+((cnk[10][0][2]*ri[6][2])+((cnk[8][0][1]*ri[6][1])
      +(cnk[10][0][0]*ri[6][0]))))-((cnk[11][0][2]*rk[6][2])+((cnk[10][0][0]*
      rk[6][0])+(cnk[11][0][1]*rk[6][1]))));
    rnk[11][1] = ((rnk[10][1]+((cnk[10][1][2]*ri[6][2])+((cnk[8][1][1]*ri[6][1])
      +(cnk[10][1][0]*ri[6][0]))))-((cnk[11][1][2]*rk[6][2])+((cnk[10][1][0]*
      rk[6][0])+(cnk[11][1][1]*rk[6][1]))));
    rnk[11][2] = ((rnk[10][2]+((cnk[10][2][2]*ri[6][2])+((cnk[8][2][1]*ri[6][1])
      +(cnk[10][2][0]*ri[6][0]))))-((cnk[11][2][2]*rk[6][2])+((cnk[10][2][0]*
      rk[6][0])+(cnk[11][2][1]*rk[6][1]))));
    rnk[12][0] = ((rnk[5][0]+((Cik[3][0][2]*ri[7][2])+((Cik[3][0][0]*ri[7][0])+(
      Cik[3][0][1]*ri[7][1]))))-((Cik[3][0][2]*rk[7][2])+((cnk[12][0][0]*
      rk[7][0])+(cnk[12][0][1]*rk[7][1]))));
    rnk[12][1] = ((rnk[5][1]+((Cik[3][1][2]*ri[7][2])+((Cik[3][1][0]*ri[7][0])+(
      Cik[3][1][1]*ri[7][1]))))-((Cik[3][1][2]*rk[7][2])+((cnk[12][1][0]*
      rk[7][0])+(cnk[12][1][1]*rk[7][1]))));
    rnk[12][2] = ((rnk[5][2]+((Cik[3][2][2]*ri[7][2])+((Cik[3][2][0]*ri[7][0])+(
      Cik[3][2][1]*ri[7][1]))))-((Cik[3][2][2]*rk[7][2])+((cnk[12][2][0]*
      rk[7][0])+(cnk[12][2][1]*rk[7][1]))));
    rnk[13][0] = ((rnk[12][0]+((Cik[3][0][2]*ri[8][2])+((cnk[12][0][0]*ri[8][0])
      +(cnk[12][0][1]*ri[8][1]))))-((cnk[13][0][2]*rk[8][2])+((cnk[12][0][1]*
      rk[8][1])+(cnk[13][0][0]*rk[8][0]))));
    rnk[13][1] = ((rnk[12][1]+((Cik[3][1][2]*ri[8][2])+((cnk[12][1][0]*ri[8][0])
      +(cnk[12][1][1]*ri[8][1]))))-((cnk[13][1][2]*rk[8][2])+((cnk[12][1][1]*
      rk[8][1])+(cnk[13][1][0]*rk[8][0]))));
    rnk[13][2] = ((rnk[12][2]+((Cik[3][2][2]*ri[8][2])+((cnk[12][2][0]*ri[8][0])
      +(cnk[12][2][1]*ri[8][1]))))-((cnk[13][2][2]*rk[8][2])+((cnk[12][2][1]*
      rk[8][1])+(cnk[13][2][0]*rk[8][0]))));
    rnk[14][0] = ((rnk[13][0]+((cnk[13][0][2]*ri[9][2])+((cnk[12][0][1]*ri[9][1]
      )+(cnk[13][0][0]*ri[9][0]))))-((cnk[14][0][2]*rk[9][2])+((cnk[13][0][0]*
      rk[9][0])+(cnk[14][0][1]*rk[9][1]))));
    rnk[14][1] = ((rnk[13][1]+((cnk[13][1][2]*ri[9][2])+((cnk[12][1][1]*ri[9][1]
      )+(cnk[13][1][0]*ri[9][0]))))-((cnk[14][1][2]*rk[9][2])+((cnk[13][1][0]*
      rk[9][0])+(cnk[14][1][1]*rk[9][1]))));
    rnk[14][2] = ((rnk[13][2]+((cnk[13][2][2]*ri[9][2])+((cnk[12][2][1]*ri[9][1]
      )+(cnk[13][2][0]*ri[9][0]))))-((cnk[14][2][2]*rk[9][2])+((cnk[13][2][0]*
      rk[9][0])+(cnk[14][2][1]*rk[9][1]))));
    rnk[15][0] = ((rnk[14][0]+((cnk[14][0][2]*ri[10][2])+((cnk[13][0][0]*
      ri[10][0])+(cnk[14][0][1]*ri[10][1]))))-((cnk[15][0][2]*rk[10][2])+((
      cnk[14][0][1]*rk[10][1])+(cnk[15][0][0]*rk[10][0]))));
    rnk[15][1] = ((rnk[14][1]+((cnk[14][1][2]*ri[10][2])+((cnk[13][1][0]*
      ri[10][0])+(cnk[14][1][1]*ri[10][1]))))-((cnk[15][1][2]*rk[10][2])+((
      cnk[14][1][1]*rk[10][1])+(cnk[15][1][0]*rk[10][0]))));
    rnk[15][2] = ((rnk[14][2]+((cnk[14][2][2]*ri[10][2])+((cnk[13][2][0]*
      ri[10][0])+(cnk[14][2][1]*ri[10][1]))))-((cnk[15][2][2]*rk[10][2])+((
      cnk[14][2][1]*rk[10][1])+(cnk[15][2][0]*rk[10][0]))));
    rnk[16][0] = ((rnk[15][0]+((cnk[15][0][2]*ri[11][2])+((cnk[14][0][1]*
      ri[11][1])+(cnk[15][0][0]*ri[11][0]))))-((cnk[16][0][2]*rk[11][2])+((
      cnk[14][0][1]*rk[11][1])+(cnk[16][0][0]*rk[11][0]))));
    rnk[16][1] = ((rnk[15][1]+((cnk[15][1][2]*ri[11][2])+((cnk[14][1][1]*
      ri[11][1])+(cnk[15][1][0]*ri[11][0]))))-((cnk[16][1][2]*rk[11][2])+((
      cnk[14][1][1]*rk[11][1])+(cnk[16][1][0]*rk[11][0]))));
    rnk[16][2] = ((rnk[15][2]+((cnk[15][2][2]*ri[11][2])+((cnk[14][2][1]*
      ri[11][1])+(cnk[15][2][0]*ri[11][0]))))-((cnk[16][2][2]*rk[11][2])+((
      cnk[14][2][1]*rk[11][1])+(cnk[16][2][0]*rk[11][0]))));
    rnk[17][0] = ((rnk[16][0]+((cnk[16][0][2]*ri[12][2])+((cnk[14][0][1]*
      ri[12][1])+(cnk[16][0][0]*ri[12][0]))))-((cnk[17][0][2]*rk[12][2])+((
      cnk[16][0][0]*rk[12][0])+(cnk[17][0][1]*rk[12][1]))));
    rnk[17][1] = ((rnk[16][1]+((cnk[16][1][2]*ri[12][2])+((cnk[14][1][1]*
      ri[12][1])+(cnk[16][1][0]*ri[12][0]))))-((cnk[17][1][2]*rk[12][2])+((
      cnk[16][1][0]*rk[12][0])+(cnk[17][1][1]*rk[12][1]))));
    rnk[17][2] = ((rnk[16][2]+((cnk[16][2][2]*ri[12][2])+((cnk[14][2][1]*
      ri[12][1])+(cnk[16][2][0]*ri[12][0]))))-((cnk[17][2][2]*rk[12][2])+((
      cnk[16][2][0]*rk[12][0])+(cnk[17][2][1]*rk[12][1]))));
    rnk[18][0] = ((rnk[5][0]+((Cik[3][0][2]*ri[13][2])+((Cik[3][0][0]*ri[13][0])
      +(Cik[3][0][1]*ri[13][1]))))-((cnk[18][0][2]*rk[13][2])+((Cik[3][0][1]*
      rk[13][1])+(cnk[18][0][0]*rk[13][0]))));
    rnk[18][1] = ((rnk[5][1]+((Cik[3][1][2]*ri[13][2])+((Cik[3][1][0]*ri[13][0])
      +(Cik[3][1][1]*ri[13][1]))))-((cnk[18][1][2]*rk[13][2])+((Cik[3][1][1]*
      rk[13][1])+(cnk[18][1][0]*rk[13][0]))));
    rnk[18][2] = ((rnk[5][2]+((Cik[3][2][2]*ri[13][2])+((Cik[3][2][0]*ri[13][0])
      +(Cik[3][2][1]*ri[13][1]))))-((cnk[18][2][2]*rk[13][2])+((Cik[3][2][1]*
      rk[13][1])+(cnk[18][2][0]*rk[13][0]))));
    rnk[19][0] = ((rnk[18][0]+((cnk[18][0][2]*ri[14][2])+((Cik[3][0][1]*
      ri[14][1])+(cnk[18][0][0]*ri[14][0]))))-((cnk[19][0][2]*rk[14][2])+((
      cnk[18][0][0]*rk[14][0])+(cnk[19][0][1]*rk[14][1]))));
    rnk[19][1] = ((rnk[18][1]+((cnk[18][1][2]*ri[14][2])+((Cik[3][1][1]*
      ri[14][1])+(cnk[18][1][0]*ri[14][0]))))-((cnk[19][1][2]*rk[14][2])+((
      cnk[18][1][0]*rk[14][0])+(cnk[19][1][1]*rk[14][1]))));
    rnk[19][2] = ((rnk[18][2]+((cnk[18][2][2]*ri[14][2])+((Cik[3][2][1]*
      ri[14][1])+(cnk[18][2][0]*ri[14][0]))))-((cnk[19][2][2]*rk[14][2])+((
      cnk[18][2][0]*rk[14][0])+(cnk[19][2][1]*rk[14][1]))));
    rnk[20][0] = ((rnk[19][0]+((cnk[19][0][2]*ri[15][2])+((cnk[18][0][0]*
      ri[15][0])+(cnk[19][0][1]*ri[15][1]))))-((cnk[20][0][2]*rk[15][2])+((
      cnk[19][0][1]*rk[15][1])+(cnk[20][0][0]*rk[15][0]))));
    rnk[20][1] = ((rnk[19][1]+((cnk[19][1][2]*ri[15][2])+((cnk[18][1][0]*
      ri[15][0])+(cnk[19][1][1]*ri[15][1]))))-((cnk[20][1][2]*rk[15][2])+((
      cnk[19][1][1]*rk[15][1])+(cnk[20][1][0]*rk[15][0]))));
    rnk[20][2] = ((rnk[19][2]+((cnk[19][2][2]*ri[15][2])+((cnk[18][2][0]*
      ri[15][0])+(cnk[19][2][1]*ri[15][1]))))-((cnk[20][2][2]*rk[15][2])+((
      cnk[19][2][1]*rk[15][1])+(cnk[20][2][0]*rk[15][0]))));
    rnk[21][0] = ((rnk[20][0]+((cnk[20][0][2]*ri[16][2])+((cnk[19][0][1]*
      ri[16][1])+(cnk[20][0][0]*ri[16][0]))))-((cnk[20][0][2]*rk[16][2])+((
      cnk[21][0][0]*rk[16][0])+(cnk[21][0][1]*rk[16][1]))));
    rnk[21][1] = ((rnk[20][1]+((cnk[20][1][2]*ri[16][2])+((cnk[19][1][1]*
      ri[16][1])+(cnk[20][1][0]*ri[16][0]))))-((cnk[20][1][2]*rk[16][2])+((
      cnk[21][1][0]*rk[16][0])+(cnk[21][1][1]*rk[16][1]))));
    rnk[21][2] = ((rnk[20][2]+((cnk[20][2][2]*ri[16][2])+((cnk[19][2][1]*
      ri[16][1])+(cnk[20][2][0]*ri[16][0]))))-((cnk[20][2][2]*rk[16][2])+((
      cnk[21][2][0]*rk[16][0])+(cnk[21][2][1]*rk[16][1]))));
    rnk[22][0] = ((rnk[5][0]+((Cik[3][0][2]*ri[17][2])+((Cik[3][0][0]*ri[17][0])
      +(Cik[3][0][1]*ri[17][1]))))-((cnk[22][0][2]*rk[17][2])+((Cik[3][0][1]*
      rk[17][1])+(cnk[22][0][0]*rk[17][0]))));
    rnk[22][1] = ((rnk[5][1]+((Cik[3][1][2]*ri[17][2])+((Cik[3][1][0]*ri[17][0])
      +(Cik[3][1][1]*ri[17][1]))))-((cnk[22][1][2]*rk[17][2])+((Cik[3][1][1]*
      rk[17][1])+(cnk[22][1][0]*rk[17][0]))));
    rnk[22][2] = ((rnk[5][2]+((Cik[3][2][2]*ri[17][2])+((Cik[3][2][0]*ri[17][0])
      +(Cik[3][2][1]*ri[17][1]))))-((cnk[22][2][2]*rk[17][2])+((Cik[3][2][1]*
      rk[17][1])+(cnk[22][2][0]*rk[17][0]))));
    rnk[23][0] = ((rnk[22][0]+((cnk[22][0][2]*ri[18][2])+((Cik[3][0][1]*
      ri[18][1])+(cnk[22][0][0]*ri[18][0]))))-((cnk[23][0][2]*rk[18][2])+((
      cnk[22][0][0]*rk[18][0])+(cnk[23][0][1]*rk[18][1]))));
    rnk[23][1] = ((rnk[22][1]+((cnk[22][1][2]*ri[18][2])+((Cik[3][1][1]*
      ri[18][1])+(cnk[22][1][0]*ri[18][0]))))-((cnk[23][1][2]*rk[18][2])+((
      cnk[22][1][0]*rk[18][0])+(cnk[23][1][1]*rk[18][1]))));
    rnk[23][2] = ((rnk[22][2]+((cnk[22][2][2]*ri[18][2])+((Cik[3][2][1]*
      ri[18][1])+(cnk[22][2][0]*ri[18][0]))))-((cnk[23][2][2]*rk[18][2])+((
      cnk[22][2][0]*rk[18][0])+(cnk[23][2][1]*rk[18][1]))));
    rnk[24][0] = ((rnk[23][0]+((cnk[23][0][2]*ri[19][2])+((cnk[22][0][0]*
      ri[19][0])+(cnk[23][0][1]*ri[19][1]))))-((cnk[24][0][2]*rk[19][2])+((
      cnk[23][0][1]*rk[19][1])+(cnk[24][0][0]*rk[19][0]))));
    rnk[24][1] = ((rnk[23][1]+((cnk[23][1][2]*ri[19][2])+((cnk[22][1][0]*
      ri[19][0])+(cnk[23][1][1]*ri[19][1]))))-((cnk[24][1][2]*rk[19][2])+((
      cnk[23][1][1]*rk[19][1])+(cnk[24][1][0]*rk[19][0]))));
    rnk[24][2] = ((rnk[23][2]+((cnk[23][2][2]*ri[19][2])+((cnk[22][2][0]*
      ri[19][0])+(cnk[23][2][1]*ri[19][1]))))-((cnk[24][2][2]*rk[19][2])+((
      cnk[23][2][1]*rk[19][1])+(cnk[24][2][0]*rk[19][0]))));
    rnk[25][0] = ((rnk[24][0]+((cnk[24][0][2]*ri[20][2])+((cnk[23][0][1]*
      ri[20][1])+(cnk[24][0][0]*ri[20][0]))))-((cnk[24][0][2]*rk[20][2])+((
      cnk[25][0][0]*rk[20][0])+(cnk[25][0][1]*rk[20][1]))));
    rnk[25][1] = ((rnk[24][1]+((cnk[24][1][2]*ri[20][2])+((cnk[23][1][1]*
      ri[20][1])+(cnk[24][1][0]*ri[20][0]))))-((cnk[24][1][2]*rk[20][2])+((
      cnk[25][1][0]*rk[20][0])+(cnk[25][1][1]*rk[20][1]))));
    rnk[25][2] = ((rnk[24][2]+((cnk[24][2][2]*ri[20][2])+((cnk[23][2][1]*
      ri[20][1])+(cnk[24][2][0]*ri[20][0]))))-((cnk[24][2][2]*rk[20][2])+((
      cnk[25][2][0]*rk[20][0])+(cnk[25][2][1]*rk[20][1]))));
    rnb[0][0] = rnk[5][0];
    rnb[0][1] = rnk[5][1];
    rnb[0][2] = rnk[5][2];
    rnb[1][0] = rnk[6][0];
    rnb[1][1] = rnk[6][1];
    rnb[1][2] = rnk[6][2];
    rnb[2][0] = rnk[7][0];
    rnb[2][1] = rnk[7][1];
    rnb[2][2] = rnk[7][2];
    rnb[3][0] = rnk[8][0];
    rnb[3][1] = rnk[8][1];
    rnb[3][2] = rnk[8][2];
    rnb[4][0] = rnk[9][0];
    rnb[4][1] = rnk[9][1];
    rnb[4][2] = rnk[9][2];
    rnb[5][0] = rnk[10][0];
    rnb[5][1] = rnk[10][1];
    rnb[5][2] = rnk[10][2];
    rnb[6][0] = rnk[11][0];
    rnb[6][1] = rnk[11][1];
    rnb[6][2] = rnk[11][2];
    rnb[7][0] = rnk[12][0];
    rnb[7][1] = rnk[12][1];
    rnb[7][2] = rnk[12][2];
    rnb[8][0] = rnk[13][0];
    rnb[8][1] = rnk[13][1];
    rnb[8][2] = rnk[13][2];
    rnb[9][0] = rnk[14][0];
    rnb[9][1] = rnk[14][1];
    rnb[9][2] = rnk[14][2];
    rnb[10][0] = rnk[15][0];
    rnb[10][1] = rnk[15][1];
    rnb[10][2] = rnk[15][2];
    rnb[11][0] = rnk[16][0];
    rnb[11][1] = rnk[16][1];
    rnb[11][2] = rnk[16][2];
    rnb[12][0] = rnk[17][0];
    rnb[12][1] = rnk[17][1];
    rnb[12][2] = rnk[17][2];
    rnb[13][0] = rnk[18][0];
    rnb[13][1] = rnk[18][1];
    rnb[13][2] = rnk[18][2];
    rnb[14][0] = rnk[19][0];
    rnb[14][1] = rnk[19][1];
    rnb[14][2] = rnk[19][2];
    rnb[15][0] = rnk[20][0];
    rnb[15][1] = rnk[20][1];
    rnb[15][2] = rnk[20][2];
    rnb[16][0] = rnk[21][0];
    rnb[16][1] = rnk[21][1];
    rnb[16][2] = rnk[21][2];
    rnb[17][0] = rnk[22][0];
    rnb[17][1] = rnk[22][1];
    rnb[17][2] = rnk[22][2];
    rnb[18][0] = rnk[23][0];
    rnb[18][1] = rnk[23][1];
    rnb[18][2] = rnk[23][2];
    rnb[19][0] = rnk[24][0];
    rnb[19][1] = rnk[24][1];
    rnb[19][2] = rnk[24][2];
    rnb[20][0] = rnk[25][0];
    rnb[20][1] = rnk[25][1];
    rnb[20][2] = rnk[25][2];
/*
Compute com (system mass center location in N)
*/
    temp[0] = ((mk[19]*rnk[24][0])+((mk[18]*rnk[23][0])+((mk[17]*rnk[22][0])+((
      mk[16]*rnk[21][0])+((mk[15]*rnk[20][0])+((mk[14]*rnk[19][0])+((mk[13]*
      rnk[18][0])+((mk[12]*rnk[17][0])+((mk[11]*rnk[16][0])+((mk[10]*rnk[15][0])
      +((mk[9]*rnk[14][0])+((mk[8]*rnk[13][0])+((mk[7]*rnk[12][0])+((mk[6]*
      rnk[11][0])+((mk[5]*rnk[10][0])+((mk[4]*rnk[9][0])+((mk[3]*rnk[8][0])+((
      mk[2]*rnk[7][0])+((mk[0]*rnk[5][0])+(mk[1]*rnk[6][0]))))))))))))))))))));
    com[0] = ((1./mtot)*((mk[20]*rnk[25][0])+temp[0]));
    temp[0] = ((mk[19]*rnk[24][1])+((mk[18]*rnk[23][1])+((mk[17]*rnk[22][1])+((
      mk[16]*rnk[21][1])+((mk[15]*rnk[20][1])+((mk[14]*rnk[19][1])+((mk[13]*
      rnk[18][1])+((mk[12]*rnk[17][1])+((mk[11]*rnk[16][1])+((mk[10]*rnk[15][1])
      +((mk[9]*rnk[14][1])+((mk[8]*rnk[13][1])+((mk[7]*rnk[12][1])+((mk[6]*
      rnk[11][1])+((mk[5]*rnk[10][1])+((mk[4]*rnk[9][1])+((mk[3]*rnk[8][1])+((
      mk[2]*rnk[7][1])+((mk[0]*rnk[5][1])+(mk[1]*rnk[6][1]))))))))))))))))))));
    com[1] = ((1./mtot)*((mk[20]*rnk[25][1])+temp[0]));
    temp[0] = ((mk[19]*rnk[24][2])+((mk[18]*rnk[23][2])+((mk[17]*rnk[22][2])+((
      mk[16]*rnk[21][2])+((mk[15]*rnk[20][2])+((mk[14]*rnk[19][2])+((mk[13]*
      rnk[18][2])+((mk[12]*rnk[17][2])+((mk[11]*rnk[16][2])+((mk[10]*rnk[15][2])
      +((mk[9]*rnk[14][2])+((mk[8]*rnk[13][2])+((mk[7]*rnk[12][2])+((mk[6]*
      rnk[11][2])+((mk[5]*rnk[10][2])+((mk[4]*rnk[9][2])+((mk[3]*rnk[8][2])+((
      mk[2]*rnk[7][2])+((mk[0]*rnk[5][2])+(mk[1]*rnk[6][2]))))))))))))))))))));
    com[2] = ((1./mtot)*((mk[20]*rnk[25][2])+temp[0]));
    skipqs: ;
    if (uchg == 0) {
        goto skipus;
    }
/*
Velocity-related variables need to be computed
*/
    inerflg = 0;
    for (i = 0; i < 26; i++) {
        u[i] = uin[i];
    }
/*
Compute u-related auxiliary variables
*/
/*
Compute wk & wb (angular velocities)
*/
    wk[6][0] = ((u[3]*c6)+(u[4]*s6));
    wk[6][1] = ((u[4]*c6)-(u[3]*s6));
    wk[6][2] = (u[5]+u[6]);
    wk[7][0] = ((wk[6][0]*c7)-(wk[6][2]*s7));
    wk[7][1] = (u[7]+wk[6][1]);
    wk[7][2] = ((wk[6][0]*s7)+(wk[6][2]*c7));
    wk[8][0] = (u[8]+wk[7][0]);
    wk[8][1] = ((wk[7][1]*c8)+(wk[7][2]*s8));
    wk[8][2] = ((wk[7][2]*c8)-(wk[7][1]*s8));
    wk[9][0] = ((wk[8][0]*c9)-(wk[8][2]*s9));
    wk[9][1] = (u[9]+wk[8][1]);
    wk[9][2] = ((wk[8][0]*s9)+(wk[8][2]*c9));
    wk[10][0] = ((wk[9][0]*c10)-(wk[9][2]*s10));
    wk[10][1] = (u[10]+wk[9][1]);
    wk[10][2] = ((wk[9][0]*s10)+(wk[9][2]*c10));
    wk[11][0] = (u[11]+wk[10][0]);
    wk[11][1] = ((wk[10][1]*c11)+(wk[10][2]*s11));
    wk[11][2] = ((wk[10][2]*c11)-(wk[10][1]*s11));
    wk[12][0] = ((u[3]*c12)+(u[4]*s12));
    wk[12][1] = ((u[4]*c12)-(u[3]*s12));
    wk[12][2] = (u[5]+u[12]);
    wk[13][0] = ((wk[12][0]*c13)-(wk[12][2]*s13));
    wk[13][1] = (u[13]+wk[12][1]);
    wk[13][2] = ((wk[12][0]*s13)+(wk[12][2]*c13));
    wk[14][0] = (u[14]+wk[13][0]);
    wk[14][1] = ((wk[13][1]*c14)+(wk[13][2]*s14));
    wk[14][2] = ((wk[13][2]*c14)-(wk[13][1]*s14));
    wk[15][0] = ((wk[14][0]*c15)-(wk[14][2]*s15));
    wk[15][1] = (u[15]+wk[14][1]);
    wk[15][2] = ((wk[14][0]*s15)+(wk[14][2]*c15));
    wk[16][0] = ((wk[15][0]*c16)-(wk[15][2]*s16));
    wk[16][1] = (u[16]+wk[15][1]);
    wk[16][2] = ((wk[15][0]*s16)+(wk[15][2]*c16));
    wk[17][0] = (u[17]+wk[16][0]);
    wk[17][1] = ((wk[16][1]*c17)+(wk[16][2]*s17));
    wk[17][2] = ((wk[16][2]*c17)-(wk[16][1]*s17));
    wk[18][0] = ((u[3]*c18)-(u[5]*s18));
    wk[18][1] = (u[4]+u[18]);
    wk[18][2] = ((u[3]*s18)+(u[5]*c18));
    wk[19][0] = (u[19]+wk[18][0]);
    wk[19][1] = ((wk[18][1]*c19)+(wk[18][2]*s19));
    wk[19][2] = ((wk[18][2]*c19)-(wk[18][1]*s19));
    wk[20][0] = ((wk[19][0]*c20)-(wk[19][2]*s20));
    wk[20][1] = (u[20]+wk[19][1]);
    wk[20][2] = ((wk[19][0]*s20)+(wk[19][2]*c20));
    wk[21][0] = ((wk[20][0]*c21)+(wk[20][1]*s21));
    wk[21][1] = ((wk[20][1]*c21)-(wk[20][0]*s21));
    wk[21][2] = (u[21]+wk[20][2]);
    wk[22][0] = ((u[3]*c22)-(u[5]*s22));
    wk[22][1] = (u[4]+u[22]);
    wk[22][2] = ((u[3]*s22)+(u[5]*c22));
    wk[23][0] = (u[23]+wk[22][0]);
    wk[23][1] = ((wk[22][1]*c23)+(wk[22][2]*s23));
    wk[23][2] = ((wk[22][2]*c23)-(wk[22][1]*s23));
    wk[24][0] = ((wk[23][0]*c24)-(wk[23][2]*s24));
    wk[24][1] = (u[24]+wk[23][1]);
    wk[24][2] = ((wk[23][0]*s24)+(wk[23][2]*c24));
    wk[25][0] = ((wk[24][0]*c25)+(wk[24][1]*s25));
    wk[25][1] = ((wk[24][1]*c25)-(wk[24][0]*s25));
    wk[25][2] = (u[25]+wk[24][2]);
    wb[0][0] = u[3];
    wb[0][1] = u[4];
    wb[0][2] = u[5];
    wb[1][0] = wk[6][0];
    wb[1][1] = wk[6][1];
    wb[1][2] = wk[6][2];
    wb[2][0] = wk[7][0];
    wb[2][1] = wk[7][1];
    wb[2][2] = wk[7][2];
    wb[3][0] = wk[8][0];
    wb[3][1] = wk[8][1];
    wb[3][2] = wk[8][2];
    wb[4][0] = wk[9][0];
    wb[4][1] = wk[9][1];
    wb[4][2] = wk[9][2];
    wb[5][0] = wk[10][0];
    wb[5][1] = wk[10][1];
    wb[5][2] = wk[10][2];
    wb[6][0] = wk[11][0];
    wb[6][1] = wk[11][1];
    wb[6][2] = wk[11][2];
    wb[7][0] = wk[12][0];
    wb[7][1] = wk[12][1];
    wb[7][2] = wk[12][2];
    wb[8][0] = wk[13][0];
    wb[8][1] = wk[13][1];
    wb[8][2] = wk[13][2];
    wb[9][0] = wk[14][0];
    wb[9][1] = wk[14][1];
    wb[9][2] = wk[14][2];
    wb[10][0] = wk[15][0];
    wb[10][1] = wk[15][1];
    wb[10][2] = wk[15][2];
    wb[11][0] = wk[16][0];
    wb[11][1] = wk[16][1];
    wb[11][2] = wk[16][2];
    wb[12][0] = wk[17][0];
    wb[12][1] = wk[17][1];
    wb[12][2] = wk[17][2];
    wb[13][0] = wk[18][0];
    wb[13][1] = wk[18][1];
    wb[13][2] = wk[18][2];
    wb[14][0] = wk[19][0];
    wb[14][1] = wk[19][1];
    wb[14][2] = wk[19][2];
    wb[15][0] = wk[20][0];
    wb[15][1] = wk[20][1];
    wb[15][2] = wk[20][2];
    wb[16][0] = wk[21][0];
    wb[16][1] = wk[21][1];
    wb[16][2] = wk[21][2];
    wb[17][0] = wk[22][0];
    wb[17][1] = wk[22][1];
    wb[17][2] = wk[22][2];
    wb[18][0] = wk[23][0];
    wb[18][1] = wk[23][1];
    wb[18][2] = wk[23][2];
    wb[19][0] = wk[24][0];
    wb[19][1] = wk[24][1];
    wb[19][2] = wk[24][2];
    wb[20][0] = wk[25][0];
    wb[20][1] = wk[25][1];
    wb[20][2] = wk[25][2];
/*
Compute auxiliary variables involving wk
*/
    Wirk[6][0] = ((ri[1][2]*u[4])-(ri[1][1]*u[5]));
    Wirk[6][1] = ((ri[1][0]*u[5])-(ri[1][2]*u[3]));
    Wirk[6][2] = ((ri[1][1]*u[3])-(ri[1][0]*u[4]));
    Wirk[7][0] = ((ri[2][2]*wk[6][1])-(ri[2][1]*wk[6][2]));
    Wirk[7][1] = ((ri[2][0]*wk[6][2])-(ri[2][2]*wk[6][0]));
    Wirk[7][2] = ((ri[2][1]*wk[6][0])-(ri[2][0]*wk[6][1]));
    Wirk[8][0] = ((ri[3][2]*wk[7][1])-(ri[3][1]*wk[7][2]));
    Wirk[8][1] = ((ri[3][0]*wk[7][2])-(ri[3][2]*wk[7][0]));
    Wirk[8][2] = ((ri[3][1]*wk[7][0])-(ri[3][0]*wk[7][1]));
    Wirk[9][0] = ((ri[4][2]*wk[8][1])-(ri[4][1]*wk[8][2]));
    Wirk[9][1] = ((ri[4][0]*wk[8][2])-(ri[4][2]*wk[8][0]));
    Wirk[9][2] = ((ri[4][1]*wk[8][0])-(ri[4][0]*wk[8][1]));
    Wirk[10][0] = ((ri[5][2]*wk[9][1])-(ri[5][1]*wk[9][2]));
    Wirk[10][1] = ((ri[5][0]*wk[9][2])-(ri[5][2]*wk[9][0]));
    Wirk[10][2] = ((ri[5][1]*wk[9][0])-(ri[5][0]*wk[9][1]));
    Wirk[11][0] = ((ri[6][2]*wk[10][1])-(ri[6][1]*wk[10][2]));
    Wirk[11][1] = ((ri[6][0]*wk[10][2])-(ri[6][2]*wk[10][0]));
    Wirk[11][2] = ((ri[6][1]*wk[10][0])-(ri[6][0]*wk[10][1]));
    Wirk[12][0] = ((ri[7][2]*u[4])-(ri[7][1]*u[5]));
    Wirk[12][1] = ((ri[7][0]*u[5])-(ri[7][2]*u[3]));
    Wirk[12][2] = ((ri[7][1]*u[3])-(ri[7][0]*u[4]));
    Wirk[13][0] = ((ri[8][2]*wk[12][1])-(ri[8][1]*wk[12][2]));
    Wirk[13][1] = ((ri[8][0]*wk[12][2])-(ri[8][2]*wk[12][0]));
    Wirk[13][2] = ((ri[8][1]*wk[12][0])-(ri[8][0]*wk[12][1]));
    Wirk[14][0] = ((ri[9][2]*wk[13][1])-(ri[9][1]*wk[13][2]));
    Wirk[14][1] = ((ri[9][0]*wk[13][2])-(ri[9][2]*wk[13][0]));
    Wirk[14][2] = ((ri[9][1]*wk[13][0])-(ri[9][0]*wk[13][1]));
    Wirk[15][0] = ((ri[10][2]*wk[14][1])-(ri[10][1]*wk[14][2]));
    Wirk[15][1] = ((ri[10][0]*wk[14][2])-(ri[10][2]*wk[14][0]));
    Wirk[15][2] = ((ri[10][1]*wk[14][0])-(ri[10][0]*wk[14][1]));
    Wirk[16][0] = ((ri[11][2]*wk[15][1])-(ri[11][1]*wk[15][2]));
    Wirk[16][1] = ((ri[11][0]*wk[15][2])-(ri[11][2]*wk[15][0]));
    Wirk[16][2] = ((ri[11][1]*wk[15][0])-(ri[11][0]*wk[15][1]));
    Wirk[17][0] = ((ri[12][2]*wk[16][1])-(ri[12][1]*wk[16][2]));
    Wirk[17][1] = ((ri[12][0]*wk[16][2])-(ri[12][2]*wk[16][0]));
    Wirk[17][2] = ((ri[12][1]*wk[16][0])-(ri[12][0]*wk[16][1]));
    Wirk[18][0] = ((ri[13][2]*u[4])-(ri[13][1]*u[5]));
    Wirk[18][1] = ((ri[13][0]*u[5])-(ri[13][2]*u[3]));
    Wirk[18][2] = ((ri[13][1]*u[3])-(ri[13][0]*u[4]));
    Wirk[19][0] = ((ri[14][2]*wk[18][1])-(ri[14][1]*wk[18][2]));
    Wirk[19][1] = ((ri[14][0]*wk[18][2])-(ri[14][2]*wk[18][0]));
    Wirk[19][2] = ((ri[14][1]*wk[18][0])-(ri[14][0]*wk[18][1]));
    Wirk[20][0] = ((ri[15][2]*wk[19][1])-(ri[15][1]*wk[19][2]));
    Wirk[20][1] = ((ri[15][0]*wk[19][2])-(ri[15][2]*wk[19][0]));
    Wirk[20][2] = ((ri[15][1]*wk[19][0])-(ri[15][0]*wk[19][1]));
    Wirk[21][0] = ((ri[16][2]*wk[20][1])-(ri[16][1]*wk[20][2]));
    Wirk[21][1] = ((ri[16][0]*wk[20][2])-(ri[16][2]*wk[20][0]));
    Wirk[21][2] = ((ri[16][1]*wk[20][0])-(ri[16][0]*wk[20][1]));
    Wirk[22][0] = ((ri[17][2]*u[4])-(ri[17][1]*u[5]));
    Wirk[22][1] = ((ri[17][0]*u[5])-(ri[17][2]*u[3]));
    Wirk[22][2] = ((ri[17][1]*u[3])-(ri[17][0]*u[4]));
    Wirk[23][0] = ((ri[18][2]*wk[22][1])-(ri[18][1]*wk[22][2]));
    Wirk[23][1] = ((ri[18][0]*wk[22][2])-(ri[18][2]*wk[22][0]));
    Wirk[23][2] = ((ri[18][1]*wk[22][0])-(ri[18][0]*wk[22][1]));
    Wirk[24][0] = ((ri[19][2]*wk[23][1])-(ri[19][1]*wk[23][2]));
    Wirk[24][1] = ((ri[19][0]*wk[23][2])-(ri[19][2]*wk[23][0]));
    Wirk[24][2] = ((ri[19][1]*wk[23][0])-(ri[19][0]*wk[23][1]));
    Wirk[25][0] = ((ri[20][2]*wk[24][1])-(ri[20][1]*wk[24][2]));
    Wirk[25][1] = ((ri[20][0]*wk[24][2])-(ri[20][2]*wk[24][0]));
    Wirk[25][2] = ((ri[20][1]*wk[24][0])-(ri[20][0]*wk[24][1]));
    Wkrpk[5][0] = ((rk[0][1]*u[5])-(rk[0][2]*u[4]));
    Wkrpk[5][1] = ((rk[0][2]*u[3])-(rk[0][0]*u[5]));
    Wkrpk[5][2] = ((rk[0][0]*u[4])-(rk[0][1]*u[3]));
    Wkrpk[6][0] = ((rk[1][1]*wk[6][2])-(rk[1][2]*wk[6][1]));
    Wkrpk[6][1] = ((rk[1][2]*wk[6][0])-(rk[1][0]*wk[6][2]));
    Wkrpk[6][2] = ((rk[1][0]*wk[6][1])-(rk[1][1]*wk[6][0]));
    Wkrpk[7][0] = ((rk[2][1]*wk[7][2])-(rk[2][2]*wk[7][1]));
    Wkrpk[7][1] = ((rk[2][2]*wk[7][0])-(rk[2][0]*wk[7][2]));
    Wkrpk[7][2] = ((rk[2][0]*wk[7][1])-(rk[2][1]*wk[7][0]));
    Wkrpk[8][0] = ((rk[3][1]*wk[8][2])-(rk[3][2]*wk[8][1]));
    Wkrpk[8][1] = ((rk[3][2]*wk[8][0])-(rk[3][0]*wk[8][2]));
    Wkrpk[8][2] = ((rk[3][0]*wk[8][1])-(rk[3][1]*wk[8][0]));
    Wkrpk[9][0] = ((rk[4][1]*wk[9][2])-(rk[4][2]*wk[9][1]));
    Wkrpk[9][1] = ((rk[4][2]*wk[9][0])-(rk[4][0]*wk[9][2]));
    Wkrpk[9][2] = ((rk[4][0]*wk[9][1])-(rk[4][1]*wk[9][0]));
    Wkrpk[10][0] = ((rk[5][1]*wk[10][2])-(rk[5][2]*wk[10][1]));
    Wkrpk[10][1] = ((rk[5][2]*wk[10][0])-(rk[5][0]*wk[10][2]));
    Wkrpk[10][2] = ((rk[5][0]*wk[10][1])-(rk[5][1]*wk[10][0]));
    Wkrpk[11][0] = ((rk[6][1]*wk[11][2])-(rk[6][2]*wk[11][1]));
    Wkrpk[11][1] = ((rk[6][2]*wk[11][0])-(rk[6][0]*wk[11][2]));
    Wkrpk[11][2] = ((rk[6][0]*wk[11][1])-(rk[6][1]*wk[11][0]));
    Wkrpk[12][0] = ((rk[7][1]*wk[12][2])-(rk[7][2]*wk[12][1]));
    Wkrpk[12][1] = ((rk[7][2]*wk[12][0])-(rk[7][0]*wk[12][2]));
    Wkrpk[12][2] = ((rk[7][0]*wk[12][1])-(rk[7][1]*wk[12][0]));
    Wkrpk[13][0] = ((rk[8][1]*wk[13][2])-(rk[8][2]*wk[13][1]));
    Wkrpk[13][1] = ((rk[8][2]*wk[13][0])-(rk[8][0]*wk[13][2]));
    Wkrpk[13][2] = ((rk[8][0]*wk[13][1])-(rk[8][1]*wk[13][0]));
    Wkrpk[14][0] = ((rk[9][1]*wk[14][2])-(rk[9][2]*wk[14][1]));
    Wkrpk[14][1] = ((rk[9][2]*wk[14][0])-(rk[9][0]*wk[14][2]));
    Wkrpk[14][2] = ((rk[9][0]*wk[14][1])-(rk[9][1]*wk[14][0]));
    Wkrpk[15][0] = ((rk[10][1]*wk[15][2])-(rk[10][2]*wk[15][1]));
    Wkrpk[15][1] = ((rk[10][2]*wk[15][0])-(rk[10][0]*wk[15][2]));
    Wkrpk[15][2] = ((rk[10][0]*wk[15][1])-(rk[10][1]*wk[15][0]));
    Wkrpk[16][0] = ((rk[11][1]*wk[16][2])-(rk[11][2]*wk[16][1]));
    Wkrpk[16][1] = ((rk[11][2]*wk[16][0])-(rk[11][0]*wk[16][2]));
    Wkrpk[16][2] = ((rk[11][0]*wk[16][1])-(rk[11][1]*wk[16][0]));
    Wkrpk[17][0] = ((rk[12][1]*wk[17][2])-(rk[12][2]*wk[17][1]));
    Wkrpk[17][1] = ((rk[12][2]*wk[17][0])-(rk[12][0]*wk[17][2]));
    Wkrpk[17][2] = ((rk[12][0]*wk[17][1])-(rk[12][1]*wk[17][0]));
    Wkrpk[18][0] = ((rk[13][1]*wk[18][2])-(rk[13][2]*wk[18][1]));
    Wkrpk[18][1] = ((rk[13][2]*wk[18][0])-(rk[13][0]*wk[18][2]));
    Wkrpk[18][2] = ((rk[13][0]*wk[18][1])-(rk[13][1]*wk[18][0]));
    Wkrpk[19][0] = ((rk[14][1]*wk[19][2])-(rk[14][2]*wk[19][1]));
    Wkrpk[19][1] = ((rk[14][2]*wk[19][0])-(rk[14][0]*wk[19][2]));
    Wkrpk[19][2] = ((rk[14][0]*wk[19][1])-(rk[14][1]*wk[19][0]));
    Wkrpk[20][0] = ((rk[15][1]*wk[20][2])-(rk[15][2]*wk[20][1]));
    Wkrpk[20][1] = ((rk[15][2]*wk[20][0])-(rk[15][0]*wk[20][2]));
    Wkrpk[20][2] = ((rk[15][0]*wk[20][1])-(rk[15][1]*wk[20][0]));
    Wkrpk[21][0] = ((rk[16][1]*wk[21][2])-(rk[16][2]*wk[21][1]));
    Wkrpk[21][1] = ((rk[16][2]*wk[21][0])-(rk[16][0]*wk[21][2]));
    Wkrpk[21][2] = ((rk[16][0]*wk[21][1])-(rk[16][1]*wk[21][0]));
    Wkrpk[22][0] = ((rk[17][1]*wk[22][2])-(rk[17][2]*wk[22][1]));
    Wkrpk[22][1] = ((rk[17][2]*wk[22][0])-(rk[17][0]*wk[22][2]));
    Wkrpk[22][2] = ((rk[17][0]*wk[22][1])-(rk[17][1]*wk[22][0]));
    Wkrpk[23][0] = ((rk[18][1]*wk[23][2])-(rk[18][2]*wk[23][1]));
    Wkrpk[23][1] = ((rk[18][2]*wk[23][0])-(rk[18][0]*wk[23][2]));
    Wkrpk[23][2] = ((rk[18][0]*wk[23][1])-(rk[18][1]*wk[23][0]));
    Wkrpk[24][0] = ((rk[19][1]*wk[24][2])-(rk[19][2]*wk[24][1]));
    Wkrpk[24][1] = ((rk[19][2]*wk[24][0])-(rk[19][0]*wk[24][2]));
    Wkrpk[24][2] = ((rk[19][0]*wk[24][1])-(rk[19][1]*wk[24][0]));
    Wkrpk[25][0] = ((rk[20][1]*wk[25][2])-(rk[20][2]*wk[25][1]));
    Wkrpk[25][1] = ((rk[20][2]*wk[25][0])-(rk[20][0]*wk[25][2]));
    Wkrpk[25][2] = ((rk[20][0]*wk[25][1])-(rk[20][1]*wk[25][0]));
    IkWk[5][0] = ((ik[0][0][2]*u[5])+((ik[0][0][0]*u[3])+(ik[0][0][1]*u[4])));
    IkWk[5][1] = ((ik[0][1][2]*u[5])+((ik[0][1][0]*u[3])+(ik[0][1][1]*u[4])));
    IkWk[5][2] = ((ik[0][2][2]*u[5])+((ik[0][2][0]*u[3])+(ik[0][2][1]*u[4])));
    WkIkWk[5][0] = ((IkWk[5][2]*u[4])-(IkWk[5][1]*u[5]));
    WkIkWk[5][1] = ((IkWk[5][0]*u[5])-(IkWk[5][2]*u[3]));
    WkIkWk[5][2] = ((IkWk[5][1]*u[3])-(IkWk[5][0]*u[4]));
    IkWk[6][0] = ((ik[1][0][2]*wk[6][2])+((ik[1][0][0]*wk[6][0])+(ik[1][0][1]*
      wk[6][1])));
    IkWk[6][1] = ((ik[1][1][2]*wk[6][2])+((ik[1][1][0]*wk[6][0])+(ik[1][1][1]*
      wk[6][1])));
    IkWk[6][2] = ((ik[1][2][2]*wk[6][2])+((ik[1][2][0]*wk[6][0])+(ik[1][2][1]*
      wk[6][1])));
    WkIkWk[6][0] = ((IkWk[6][2]*wk[6][1])-(IkWk[6][1]*wk[6][2]));
    WkIkWk[6][1] = ((IkWk[6][0]*wk[6][2])-(IkWk[6][2]*wk[6][0]));
    WkIkWk[6][2] = ((IkWk[6][1]*wk[6][0])-(IkWk[6][0]*wk[6][1]));
    IkWk[7][0] = ((ik[2][0][2]*wk[7][2])+((ik[2][0][0]*wk[7][0])+(ik[2][0][1]*
      wk[7][1])));
    IkWk[7][1] = ((ik[2][1][2]*wk[7][2])+((ik[2][1][0]*wk[7][0])+(ik[2][1][1]*
      wk[7][1])));
    IkWk[7][2] = ((ik[2][2][2]*wk[7][2])+((ik[2][2][0]*wk[7][0])+(ik[2][2][1]*
      wk[7][1])));
    WkIkWk[7][0] = ((IkWk[7][2]*wk[7][1])-(IkWk[7][1]*wk[7][2]));
    WkIkWk[7][1] = ((IkWk[7][0]*wk[7][2])-(IkWk[7][2]*wk[7][0]));
    WkIkWk[7][2] = ((IkWk[7][1]*wk[7][0])-(IkWk[7][0]*wk[7][1]));
    IkWk[8][0] = ((ik[3][0][2]*wk[8][2])+((ik[3][0][0]*wk[8][0])+(ik[3][0][1]*
      wk[8][1])));
    IkWk[8][1] = ((ik[3][1][2]*wk[8][2])+((ik[3][1][0]*wk[8][0])+(ik[3][1][1]*
      wk[8][1])));
    IkWk[8][2] = ((ik[3][2][2]*wk[8][2])+((ik[3][2][0]*wk[8][0])+(ik[3][2][1]*
      wk[8][1])));
    WkIkWk[8][0] = ((IkWk[8][2]*wk[8][1])-(IkWk[8][1]*wk[8][2]));
    WkIkWk[8][1] = ((IkWk[8][0]*wk[8][2])-(IkWk[8][2]*wk[8][0]));
    WkIkWk[8][2] = ((IkWk[8][1]*wk[8][0])-(IkWk[8][0]*wk[8][1]));
    IkWk[9][0] = ((ik[4][0][2]*wk[9][2])+((ik[4][0][0]*wk[9][0])+(ik[4][0][1]*
      wk[9][1])));
    IkWk[9][1] = ((ik[4][1][2]*wk[9][2])+((ik[4][1][0]*wk[9][0])+(ik[4][1][1]*
      wk[9][1])));
    IkWk[9][2] = ((ik[4][2][2]*wk[9][2])+((ik[4][2][0]*wk[9][0])+(ik[4][2][1]*
      wk[9][1])));
    WkIkWk[9][0] = ((IkWk[9][2]*wk[9][1])-(IkWk[9][1]*wk[9][2]));
    WkIkWk[9][1] = ((IkWk[9][0]*wk[9][2])-(IkWk[9][2]*wk[9][0]));
    WkIkWk[9][2] = ((IkWk[9][1]*wk[9][0])-(IkWk[9][0]*wk[9][1]));
    IkWk[10][0] = ((ik[5][0][2]*wk[10][2])+((ik[5][0][0]*wk[10][0])+(ik[5][0][1]
      *wk[10][1])));
    IkWk[10][1] = ((ik[5][1][2]*wk[10][2])+((ik[5][1][0]*wk[10][0])+(ik[5][1][1]
      *wk[10][1])));
    IkWk[10][2] = ((ik[5][2][2]*wk[10][2])+((ik[5][2][0]*wk[10][0])+(ik[5][2][1]
      *wk[10][1])));
    WkIkWk[10][0] = ((IkWk[10][2]*wk[10][1])-(IkWk[10][1]*wk[10][2]));
    WkIkWk[10][1] = ((IkWk[10][0]*wk[10][2])-(IkWk[10][2]*wk[10][0]));
    WkIkWk[10][2] = ((IkWk[10][1]*wk[10][0])-(IkWk[10][0]*wk[10][1]));
    IkWk[11][0] = ((ik[6][0][2]*wk[11][2])+((ik[6][0][0]*wk[11][0])+(ik[6][0][1]
      *wk[11][1])));
    IkWk[11][1] = ((ik[6][1][2]*wk[11][2])+((ik[6][1][0]*wk[11][0])+(ik[6][1][1]
      *wk[11][1])));
    IkWk[11][2] = ((ik[6][2][2]*wk[11][2])+((ik[6][2][0]*wk[11][0])+(ik[6][2][1]
      *wk[11][1])));
    WkIkWk[11][0] = ((IkWk[11][2]*wk[11][1])-(IkWk[11][1]*wk[11][2]));
    WkIkWk[11][1] = ((IkWk[11][0]*wk[11][2])-(IkWk[11][2]*wk[11][0]));
    WkIkWk[11][2] = ((IkWk[11][1]*wk[11][0])-(IkWk[11][0]*wk[11][1]));
    IkWk[12][0] = ((ik[7][0][2]*wk[12][2])+((ik[7][0][0]*wk[12][0])+(ik[7][0][1]
      *wk[12][1])));
    IkWk[12][1] = ((ik[7][1][2]*wk[12][2])+((ik[7][1][0]*wk[12][0])+(ik[7][1][1]
      *wk[12][1])));
    IkWk[12][2] = ((ik[7][2][2]*wk[12][2])+((ik[7][2][0]*wk[12][0])+(ik[7][2][1]
      *wk[12][1])));
    WkIkWk[12][0] = ((IkWk[12][2]*wk[12][1])-(IkWk[12][1]*wk[12][2]));
    WkIkWk[12][1] = ((IkWk[12][0]*wk[12][2])-(IkWk[12][2]*wk[12][0]));
    WkIkWk[12][2] = ((IkWk[12][1]*wk[12][0])-(IkWk[12][0]*wk[12][1]));
    IkWk[13][0] = ((ik[8][0][2]*wk[13][2])+((ik[8][0][0]*wk[13][0])+(ik[8][0][1]
      *wk[13][1])));
    IkWk[13][1] = ((ik[8][1][2]*wk[13][2])+((ik[8][1][0]*wk[13][0])+(ik[8][1][1]
      *wk[13][1])));
    IkWk[13][2] = ((ik[8][2][2]*wk[13][2])+((ik[8][2][0]*wk[13][0])+(ik[8][2][1]
      *wk[13][1])));
    WkIkWk[13][0] = ((IkWk[13][2]*wk[13][1])-(IkWk[13][1]*wk[13][2]));
    WkIkWk[13][1] = ((IkWk[13][0]*wk[13][2])-(IkWk[13][2]*wk[13][0]));
    WkIkWk[13][2] = ((IkWk[13][1]*wk[13][0])-(IkWk[13][0]*wk[13][1]));
    IkWk[14][0] = ((ik[9][0][2]*wk[14][2])+((ik[9][0][0]*wk[14][0])+(ik[9][0][1]
      *wk[14][1])));
    IkWk[14][1] = ((ik[9][1][2]*wk[14][2])+((ik[9][1][0]*wk[14][0])+(ik[9][1][1]
      *wk[14][1])));
    IkWk[14][2] = ((ik[9][2][2]*wk[14][2])+((ik[9][2][0]*wk[14][0])+(ik[9][2][1]
      *wk[14][1])));
    WkIkWk[14][0] = ((IkWk[14][2]*wk[14][1])-(IkWk[14][1]*wk[14][2]));
    WkIkWk[14][1] = ((IkWk[14][0]*wk[14][2])-(IkWk[14][2]*wk[14][0]));
    WkIkWk[14][2] = ((IkWk[14][1]*wk[14][0])-(IkWk[14][0]*wk[14][1]));
    IkWk[15][0] = ((ik[10][0][2]*wk[15][2])+((ik[10][0][0]*wk[15][0])+(
      ik[10][0][1]*wk[15][1])));
    IkWk[15][1] = ((ik[10][1][2]*wk[15][2])+((ik[10][1][0]*wk[15][0])+(
      ik[10][1][1]*wk[15][1])));
    IkWk[15][2] = ((ik[10][2][2]*wk[15][2])+((ik[10][2][0]*wk[15][0])+(
      ik[10][2][1]*wk[15][1])));
    WkIkWk[15][0] = ((IkWk[15][2]*wk[15][1])-(IkWk[15][1]*wk[15][2]));
    WkIkWk[15][1] = ((IkWk[15][0]*wk[15][2])-(IkWk[15][2]*wk[15][0]));
    WkIkWk[15][2] = ((IkWk[15][1]*wk[15][0])-(IkWk[15][0]*wk[15][1]));
    IkWk[16][0] = ((ik[11][0][2]*wk[16][2])+((ik[11][0][0]*wk[16][0])+(
      ik[11][0][1]*wk[16][1])));
    IkWk[16][1] = ((ik[11][1][2]*wk[16][2])+((ik[11][1][0]*wk[16][0])+(
      ik[11][1][1]*wk[16][1])));
    IkWk[16][2] = ((ik[11][2][2]*wk[16][2])+((ik[11][2][0]*wk[16][0])+(
      ik[11][2][1]*wk[16][1])));
    WkIkWk[16][0] = ((IkWk[16][2]*wk[16][1])-(IkWk[16][1]*wk[16][2]));
    WkIkWk[16][1] = ((IkWk[16][0]*wk[16][2])-(IkWk[16][2]*wk[16][0]));
    WkIkWk[16][2] = ((IkWk[16][1]*wk[16][0])-(IkWk[16][0]*wk[16][1]));
    IkWk[17][0] = ((ik[12][0][2]*wk[17][2])+((ik[12][0][0]*wk[17][0])+(
      ik[12][0][1]*wk[17][1])));
    IkWk[17][1] = ((ik[12][1][2]*wk[17][2])+((ik[12][1][0]*wk[17][0])+(
      ik[12][1][1]*wk[17][1])));
    IkWk[17][2] = ((ik[12][2][2]*wk[17][2])+((ik[12][2][0]*wk[17][0])+(
      ik[12][2][1]*wk[17][1])));
    WkIkWk[17][0] = ((IkWk[17][2]*wk[17][1])-(IkWk[17][1]*wk[17][2]));
    WkIkWk[17][1] = ((IkWk[17][0]*wk[17][2])-(IkWk[17][2]*wk[17][0]));
    WkIkWk[17][2] = ((IkWk[17][1]*wk[17][0])-(IkWk[17][0]*wk[17][1]));
    IkWk[18][0] = ((ik[13][0][2]*wk[18][2])+((ik[13][0][0]*wk[18][0])+(
      ik[13][0][1]*wk[18][1])));
    IkWk[18][1] = ((ik[13][1][2]*wk[18][2])+((ik[13][1][0]*wk[18][0])+(
      ik[13][1][1]*wk[18][1])));
    IkWk[18][2] = ((ik[13][2][2]*wk[18][2])+((ik[13][2][0]*wk[18][0])+(
      ik[13][2][1]*wk[18][1])));
    WkIkWk[18][0] = ((IkWk[18][2]*wk[18][1])-(IkWk[18][1]*wk[18][2]));
    WkIkWk[18][1] = ((IkWk[18][0]*wk[18][2])-(IkWk[18][2]*wk[18][0]));
    WkIkWk[18][2] = ((IkWk[18][1]*wk[18][0])-(IkWk[18][0]*wk[18][1]));
    IkWk[19][0] = ((ik[14][0][2]*wk[19][2])+((ik[14][0][0]*wk[19][0])+(
      ik[14][0][1]*wk[19][1])));
    IkWk[19][1] = ((ik[14][1][2]*wk[19][2])+((ik[14][1][0]*wk[19][0])+(
      ik[14][1][1]*wk[19][1])));
    IkWk[19][2] = ((ik[14][2][2]*wk[19][2])+((ik[14][2][0]*wk[19][0])+(
      ik[14][2][1]*wk[19][1])));
    WkIkWk[19][0] = ((IkWk[19][2]*wk[19][1])-(IkWk[19][1]*wk[19][2]));
    WkIkWk[19][1] = ((IkWk[19][0]*wk[19][2])-(IkWk[19][2]*wk[19][0]));
    WkIkWk[19][2] = ((IkWk[19][1]*wk[19][0])-(IkWk[19][0]*wk[19][1]));
    IkWk[20][0] = ((ik[15][0][2]*wk[20][2])+((ik[15][0][0]*wk[20][0])+(
      ik[15][0][1]*wk[20][1])));
    IkWk[20][1] = ((ik[15][1][2]*wk[20][2])+((ik[15][1][0]*wk[20][0])+(
      ik[15][1][1]*wk[20][1])));
    IkWk[20][2] = ((ik[15][2][2]*wk[20][2])+((ik[15][2][0]*wk[20][0])+(
      ik[15][2][1]*wk[20][1])));
    WkIkWk[20][0] = ((IkWk[20][2]*wk[20][1])-(IkWk[20][1]*wk[20][2]));
    WkIkWk[20][1] = ((IkWk[20][0]*wk[20][2])-(IkWk[20][2]*wk[20][0]));
    WkIkWk[20][2] = ((IkWk[20][1]*wk[20][0])-(IkWk[20][0]*wk[20][1]));
    IkWk[21][0] = ((ik[16][0][2]*wk[21][2])+((ik[16][0][0]*wk[21][0])+(
      ik[16][0][1]*wk[21][1])));
    IkWk[21][1] = ((ik[16][1][2]*wk[21][2])+((ik[16][1][0]*wk[21][0])+(
      ik[16][1][1]*wk[21][1])));
    IkWk[21][2] = ((ik[16][2][2]*wk[21][2])+((ik[16][2][0]*wk[21][0])+(
      ik[16][2][1]*wk[21][1])));
    WkIkWk[21][0] = ((IkWk[21][2]*wk[21][1])-(IkWk[21][1]*wk[21][2]));
    WkIkWk[21][1] = ((IkWk[21][0]*wk[21][2])-(IkWk[21][2]*wk[21][0]));
    WkIkWk[21][2] = ((IkWk[21][1]*wk[21][0])-(IkWk[21][0]*wk[21][1]));
    IkWk[22][0] = ((ik[17][0][2]*wk[22][2])+((ik[17][0][0]*wk[22][0])+(
      ik[17][0][1]*wk[22][1])));
    IkWk[22][1] = ((ik[17][1][2]*wk[22][2])+((ik[17][1][0]*wk[22][0])+(
      ik[17][1][1]*wk[22][1])));
    IkWk[22][2] = ((ik[17][2][2]*wk[22][2])+((ik[17][2][0]*wk[22][0])+(
      ik[17][2][1]*wk[22][1])));
    WkIkWk[22][0] = ((IkWk[22][2]*wk[22][1])-(IkWk[22][1]*wk[22][2]));
    WkIkWk[22][1] = ((IkWk[22][0]*wk[22][2])-(IkWk[22][2]*wk[22][0]));
    WkIkWk[22][2] = ((IkWk[22][1]*wk[22][0])-(IkWk[22][0]*wk[22][1]));
    IkWk[23][0] = ((ik[18][0][2]*wk[23][2])+((ik[18][0][0]*wk[23][0])+(
      ik[18][0][1]*wk[23][1])));
    IkWk[23][1] = ((ik[18][1][2]*wk[23][2])+((ik[18][1][0]*wk[23][0])+(
      ik[18][1][1]*wk[23][1])));
    IkWk[23][2] = ((ik[18][2][2]*wk[23][2])+((ik[18][2][0]*wk[23][0])+(
      ik[18][2][1]*wk[23][1])));
    WkIkWk[23][0] = ((IkWk[23][2]*wk[23][1])-(IkWk[23][1]*wk[23][2]));
    WkIkWk[23][1] = ((IkWk[23][0]*wk[23][2])-(IkWk[23][2]*wk[23][0]));
    WkIkWk[23][2] = ((IkWk[23][1]*wk[23][0])-(IkWk[23][0]*wk[23][1]));
    IkWk[24][0] = ((ik[19][0][2]*wk[24][2])+((ik[19][0][0]*wk[24][0])+(
      ik[19][0][1]*wk[24][1])));
    IkWk[24][1] = ((ik[19][1][2]*wk[24][2])+((ik[19][1][0]*wk[24][0])+(
      ik[19][1][1]*wk[24][1])));
    IkWk[24][2] = ((ik[19][2][2]*wk[24][2])+((ik[19][2][0]*wk[24][0])+(
      ik[19][2][1]*wk[24][1])));
    WkIkWk[24][0] = ((IkWk[24][2]*wk[24][1])-(IkWk[24][1]*wk[24][2]));
    WkIkWk[24][1] = ((IkWk[24][0]*wk[24][2])-(IkWk[24][2]*wk[24][0]));
    WkIkWk[24][2] = ((IkWk[24][1]*wk[24][0])-(IkWk[24][0]*wk[24][1]));
    IkWk[25][0] = ((ik[20][0][2]*wk[25][2])+((ik[20][0][0]*wk[25][0])+(
      ik[20][0][1]*wk[25][1])));
    IkWk[25][1] = ((ik[20][1][2]*wk[25][2])+((ik[20][1][0]*wk[25][0])+(
      ik[20][1][1]*wk[25][1])));
    IkWk[25][2] = ((ik[20][2][2]*wk[25][2])+((ik[20][2][0]*wk[25][0])+(
      ik[20][2][1]*wk[25][1])));
    WkIkWk[25][0] = ((IkWk[25][2]*wk[25][1])-(IkWk[25][1]*wk[25][2]));
    WkIkWk[25][1] = ((IkWk[25][0]*wk[25][2])-(IkWk[25][2]*wk[25][0]));
    WkIkWk[25][2] = ((IkWk[25][1]*wk[25][0])-(IkWk[25][0]*wk[25][1]));
/*
Compute temporaries for use in SDRHS
*/
    w0w0[0] = (u[3]*u[3]);
    w0w0[1] = (wk[6][0]*wk[6][0]);
    w0w0[2] = (wk[7][0]*wk[7][0]);
    w0w0[3] = (wk[8][0]*wk[8][0]);
    w0w0[4] = (wk[9][0]*wk[9][0]);
    w0w0[5] = (wk[10][0]*wk[10][0]);
    w0w0[6] = (wk[11][0]*wk[11][0]);
    w0w0[7] = (wk[12][0]*wk[12][0]);
    w0w0[8] = (wk[13][0]*wk[13][0]);
    w0w0[9] = (wk[14][0]*wk[14][0]);
    w0w0[10] = (wk[15][0]*wk[15][0]);
    w0w0[11] = (wk[16][0]*wk[16][0]);
    w0w0[12] = (wk[17][0]*wk[17][0]);
    w0w0[13] = (wk[18][0]*wk[18][0]);
    w0w0[14] = (wk[19][0]*wk[19][0]);
    w0w0[15] = (wk[20][0]*wk[20][0]);
    w0w0[16] = (wk[21][0]*wk[21][0]);
    w0w0[17] = (wk[22][0]*wk[22][0]);
    w0w0[18] = (wk[23][0]*wk[23][0]);
    w0w0[19] = (wk[24][0]*wk[24][0]);
    w0w0[20] = (wk[25][0]*wk[25][0]);
    w1w1[0] = (u[4]*u[4]);
    w1w1[1] = (wk[6][1]*wk[6][1]);
    w1w1[2] = (wk[7][1]*wk[7][1]);
    w1w1[3] = (wk[8][1]*wk[8][1]);
    w1w1[4] = (wk[9][1]*wk[9][1]);
    w1w1[5] = (wk[10][1]*wk[10][1]);
    w1w1[6] = (wk[11][1]*wk[11][1]);
    w1w1[7] = (wk[12][1]*wk[12][1]);
    w1w1[8] = (wk[13][1]*wk[13][1]);
    w1w1[9] = (wk[14][1]*wk[14][1]);
    w1w1[10] = (wk[15][1]*wk[15][1]);
    w1w1[11] = (wk[16][1]*wk[16][1]);
    w1w1[12] = (wk[17][1]*wk[17][1]);
    w1w1[13] = (wk[18][1]*wk[18][1]);
    w1w1[14] = (wk[19][1]*wk[19][1]);
    w1w1[15] = (wk[20][1]*wk[20][1]);
    w1w1[16] = (wk[21][1]*wk[21][1]);
    w1w1[17] = (wk[22][1]*wk[22][1]);
    w1w1[18] = (wk[23][1]*wk[23][1]);
    w1w1[19] = (wk[24][1]*wk[24][1]);
    w1w1[20] = (wk[25][1]*wk[25][1]);
    w2w2[0] = (u[5]*u[5]);
    w2w2[1] = (wk[6][2]*wk[6][2]);
    w2w2[2] = (wk[7][2]*wk[7][2]);
    w2w2[3] = (wk[8][2]*wk[8][2]);
    w2w2[4] = (wk[9][2]*wk[9][2]);
    w2w2[5] = (wk[10][2]*wk[10][2]);
    w2w2[6] = (wk[11][2]*wk[11][2]);
    w2w2[7] = (wk[12][2]*wk[12][2]);
    w2w2[8] = (wk[13][2]*wk[13][2]);
    w2w2[9] = (wk[14][2]*wk[14][2]);
    w2w2[10] = (wk[15][2]*wk[15][2]);
    w2w2[11] = (wk[16][2]*wk[16][2]);
    w2w2[12] = (wk[17][2]*wk[17][2]);
    w2w2[13] = (wk[18][2]*wk[18][2]);
    w2w2[14] = (wk[19][2]*wk[19][2]);
    w2w2[15] = (wk[20][2]*wk[20][2]);
    w2w2[16] = (wk[21][2]*wk[21][2]);
    w2w2[17] = (wk[22][2]*wk[22][2]);
    w2w2[18] = (wk[23][2]*wk[23][2]);
    w2w2[19] = (wk[24][2]*wk[24][2]);
    w2w2[20] = (wk[25][2]*wk[25][2]);
    w0w1[0] = (u[3]*u[4]);
    w0w1[1] = (wk[6][0]*wk[6][1]);
    w0w1[2] = (wk[7][0]*wk[7][1]);
    w0w1[3] = (wk[8][0]*wk[8][1]);
    w0w1[4] = (wk[9][0]*wk[9][1]);
    w0w1[5] = (wk[10][0]*wk[10][1]);
    w0w1[6] = (wk[11][0]*wk[11][1]);
    w0w1[7] = (wk[12][0]*wk[12][1]);
    w0w1[8] = (wk[13][0]*wk[13][1]);
    w0w1[9] = (wk[14][0]*wk[14][1]);
    w0w1[10] = (wk[15][0]*wk[15][1]);
    w0w1[11] = (wk[16][0]*wk[16][1]);
    w0w1[12] = (wk[17][0]*wk[17][1]);
    w0w1[13] = (wk[18][0]*wk[18][1]);
    w0w1[14] = (wk[19][0]*wk[19][1]);
    w0w1[15] = (wk[20][0]*wk[20][1]);
    w0w1[16] = (wk[21][0]*wk[21][1]);
    w0w1[17] = (wk[22][0]*wk[22][1]);
    w0w1[18] = (wk[23][0]*wk[23][1]);
    w0w1[19] = (wk[24][0]*wk[24][1]);
    w0w1[20] = (wk[25][0]*wk[25][1]);
    w0w2[0] = (u[3]*u[5]);
    w0w2[1] = (wk[6][0]*wk[6][2]);
    w0w2[2] = (wk[7][0]*wk[7][2]);
    w0w2[3] = (wk[8][0]*wk[8][2]);
    w0w2[4] = (wk[9][0]*wk[9][2]);
    w0w2[5] = (wk[10][0]*wk[10][2]);
    w0w2[6] = (wk[11][0]*wk[11][2]);
    w0w2[7] = (wk[12][0]*wk[12][2]);
    w0w2[8] = (wk[13][0]*wk[13][2]);
    w0w2[9] = (wk[14][0]*wk[14][2]);
    w0w2[10] = (wk[15][0]*wk[15][2]);
    w0w2[11] = (wk[16][0]*wk[16][2]);
    w0w2[12] = (wk[17][0]*wk[17][2]);
    w0w2[13] = (wk[18][0]*wk[18][2]);
    w0w2[14] = (wk[19][0]*wk[19][2]);
    w0w2[15] = (wk[20][0]*wk[20][2]);
    w0w2[16] = (wk[21][0]*wk[21][2]);
    w0w2[17] = (wk[22][0]*wk[22][2]);
    w0w2[18] = (wk[23][0]*wk[23][2]);
    w0w2[19] = (wk[24][0]*wk[24][2]);
    w0w2[20] = (wk[25][0]*wk[25][2]);
    w1w2[0] = (u[4]*u[5]);
    w1w2[1] = (wk[6][1]*wk[6][2]);
    w1w2[2] = (wk[7][1]*wk[7][2]);
    w1w2[3] = (wk[8][1]*wk[8][2]);
    w1w2[4] = (wk[9][1]*wk[9][2]);
    w1w2[5] = (wk[10][1]*wk[10][2]);
    w1w2[6] = (wk[11][1]*wk[11][2]);
    w1w2[7] = (wk[12][1]*wk[12][2]);
    w1w2[8] = (wk[13][1]*wk[13][2]);
    w1w2[9] = (wk[14][1]*wk[14][2]);
    w1w2[10] = (wk[15][1]*wk[15][2]);
    w1w2[11] = (wk[16][1]*wk[16][2]);
    w1w2[12] = (wk[17][1]*wk[17][2]);
    w1w2[13] = (wk[18][1]*wk[18][2]);
    w1w2[14] = (wk[19][1]*wk[19][2]);
    w1w2[15] = (wk[20][1]*wk[20][2]);
    w1w2[16] = (wk[21][1]*wk[21][2]);
    w1w2[17] = (wk[22][1]*wk[22][2]);
    w1w2[18] = (wk[23][1]*wk[23][2]);
    w1w2[19] = (wk[24][1]*wk[24][2]);
    w1w2[20] = (wk[25][1]*wk[25][2]);
    w00w11[0] = -(w0w0[0]+w1w1[0]);
    w00w11[1] = -(w0w0[1]+w1w1[1]);
    w00w11[2] = -(w0w0[2]+w1w1[2]);
    w00w11[3] = -(w0w0[3]+w1w1[3]);
    w00w11[4] = -(w0w0[4]+w1w1[4]);
    w00w11[5] = -(w0w0[5]+w1w1[5]);
    w00w11[6] = -(w0w0[6]+w1w1[6]);
    w00w11[7] = -(w0w0[7]+w1w1[7]);
    w00w11[8] = -(w0w0[8]+w1w1[8]);
    w00w11[9] = -(w0w0[9]+w1w1[9]);
    w00w11[10] = -(w0w0[10]+w1w1[10]);
    w00w11[11] = -(w0w0[11]+w1w1[11]);
    w00w11[12] = -(w0w0[12]+w1w1[12]);
    w00w11[13] = -(w0w0[13]+w1w1[13]);
    w00w11[14] = -(w0w0[14]+w1w1[14]);
    w00w11[15] = -(w0w0[15]+w1w1[15]);
    w00w11[16] = -(w0w0[16]+w1w1[16]);
    w00w11[17] = -(w0w0[17]+w1w1[17]);
    w00w11[18] = -(w0w0[18]+w1w1[18]);
    w00w11[19] = -(w0w0[19]+w1w1[19]);
    w00w11[20] = -(w0w0[20]+w1w1[20]);
    w00w22[0] = -(w0w0[0]+w2w2[0]);
    w00w22[1] = -(w0w0[1]+w2w2[1]);
    w00w22[2] = -(w0w0[2]+w2w2[2]);
    w00w22[3] = -(w0w0[3]+w2w2[3]);
    w00w22[4] = -(w0w0[4]+w2w2[4]);
    w00w22[5] = -(w0w0[5]+w2w2[5]);
    w00w22[6] = -(w0w0[6]+w2w2[6]);
    w00w22[7] = -(w0w0[7]+w2w2[7]);
    w00w22[8] = -(w0w0[8]+w2w2[8]);
    w00w22[9] = -(w0w0[9]+w2w2[9]);
    w00w22[10] = -(w0w0[10]+w2w2[10]);
    w00w22[11] = -(w0w0[11]+w2w2[11]);
    w00w22[12] = -(w0w0[12]+w2w2[12]);
    w00w22[13] = -(w0w0[13]+w2w2[13]);
    w00w22[14] = -(w0w0[14]+w2w2[14]);
    w00w22[15] = -(w0w0[15]+w2w2[15]);
    w00w22[16] = -(w0w0[16]+w2w2[16]);
    w00w22[17] = -(w0w0[17]+w2w2[17]);
    w00w22[18] = -(w0w0[18]+w2w2[18]);
    w00w22[19] = -(w0w0[19]+w2w2[19]);
    w00w22[20] = -(w0w0[20]+w2w2[20]);
    w11w22[0] = -(w1w1[0]+w2w2[0]);
    w11w22[1] = -(w1w1[1]+w2w2[1]);
    w11w22[2] = -(w1w1[2]+w2w2[2]);
    w11w22[3] = -(w1w1[3]+w2w2[3]);
    w11w22[4] = -(w1w1[4]+w2w2[4]);
    w11w22[5] = -(w1w1[5]+w2w2[5]);
    w11w22[6] = -(w1w1[6]+w2w2[6]);
    w11w22[7] = -(w1w1[7]+w2w2[7]);
    w11w22[8] = -(w1w1[8]+w2w2[8]);
    w11w22[9] = -(w1w1[9]+w2w2[9]);
    w11w22[10] = -(w1w1[10]+w2w2[10]);
    w11w22[11] = -(w1w1[11]+w2w2[11]);
    w11w22[12] = -(w1w1[12]+w2w2[12]);
    w11w22[13] = -(w1w1[13]+w2w2[13]);
    w11w22[14] = -(w1w1[14]+w2w2[14]);
    w11w22[15] = -(w1w1[15]+w2w2[15]);
    w11w22[16] = -(w1w1[16]+w2w2[16]);
    w11w22[17] = -(w1w1[17]+w2w2[17]);
    w11w22[18] = -(w1w1[18]+w2w2[18]);
    w11w22[19] = -(w1w1[19]+w2w2[19]);
    w11w22[20] = -(w1w1[20]+w2w2[20]);
/*
Compute vnk & vnb (mass center linear velocities in N)
*/
    vnk[5][0] = (u[0]+((Cik[3][0][2]*Wkrpk[5][2])+((Cik[3][0][0]*Wkrpk[5][0])+(
      Cik[3][0][1]*Wkrpk[5][1]))));
    vnk[5][1] = (u[1]+((Cik[3][1][2]*Wkrpk[5][2])+((Cik[3][1][0]*Wkrpk[5][0])+(
      Cik[3][1][1]*Wkrpk[5][1]))));
    vnk[5][2] = (u[2]+((Cik[3][2][2]*Wkrpk[5][2])+((Cik[3][2][0]*Wkrpk[5][0])+(
      Cik[3][2][1]*Wkrpk[5][1]))));
    vnk[6][0] = ((vnk[5][0]+((Cik[3][0][2]*Wirk[6][2])+((Cik[3][0][0]*Wirk[6][0]
      )+(Cik[3][0][1]*Wirk[6][1]))))+((Cik[3][0][2]*Wkrpk[6][2])+((cnk[6][0][0]*
      Wkrpk[6][0])+(cnk[6][0][1]*Wkrpk[6][1]))));
    vnk[6][1] = ((vnk[5][1]+((Cik[3][1][2]*Wirk[6][2])+((Cik[3][1][0]*Wirk[6][0]
      )+(Cik[3][1][1]*Wirk[6][1]))))+((Cik[3][1][2]*Wkrpk[6][2])+((cnk[6][1][0]*
      Wkrpk[6][0])+(cnk[6][1][1]*Wkrpk[6][1]))));
    vnk[6][2] = ((vnk[5][2]+((Cik[3][2][2]*Wirk[6][2])+((Cik[3][2][0]*Wirk[6][0]
      )+(Cik[3][2][1]*Wirk[6][1]))))+((Cik[3][2][2]*Wkrpk[6][2])+((cnk[6][2][0]*
      Wkrpk[6][0])+(cnk[6][2][1]*Wkrpk[6][1]))));
    vnk[7][0] = ((vnk[6][0]+((Cik[3][0][2]*Wirk[7][2])+((cnk[6][0][0]*Wirk[7][0]
      )+(cnk[6][0][1]*Wirk[7][1]))))+((cnk[7][0][2]*Wkrpk[7][2])+((cnk[6][0][1]*
      Wkrpk[7][1])+(cnk[7][0][0]*Wkrpk[7][0]))));
    vnk[7][1] = ((vnk[6][1]+((Cik[3][1][2]*Wirk[7][2])+((cnk[6][1][0]*Wirk[7][0]
      )+(cnk[6][1][1]*Wirk[7][1]))))+((cnk[7][1][2]*Wkrpk[7][2])+((cnk[6][1][1]*
      Wkrpk[7][1])+(cnk[7][1][0]*Wkrpk[7][0]))));
    vnk[7][2] = ((vnk[6][2]+((Cik[3][2][2]*Wirk[7][2])+((cnk[6][2][0]*Wirk[7][0]
      )+(cnk[6][2][1]*Wirk[7][1]))))+((cnk[7][2][2]*Wkrpk[7][2])+((cnk[6][2][1]*
      Wkrpk[7][1])+(cnk[7][2][0]*Wkrpk[7][0]))));
    vnk[8][0] = ((vnk[7][0]+((cnk[7][0][2]*Wirk[8][2])+((cnk[6][0][1]*Wirk[8][1]
      )+(cnk[7][0][0]*Wirk[8][0]))))+((cnk[8][0][2]*Wkrpk[8][2])+((cnk[7][0][0]*
      Wkrpk[8][0])+(cnk[8][0][1]*Wkrpk[8][1]))));
    vnk[8][1] = ((vnk[7][1]+((cnk[7][1][2]*Wirk[8][2])+((cnk[6][1][1]*Wirk[8][1]
      )+(cnk[7][1][0]*Wirk[8][0]))))+((cnk[8][1][2]*Wkrpk[8][2])+((cnk[7][1][0]*
      Wkrpk[8][0])+(cnk[8][1][1]*Wkrpk[8][1]))));
    vnk[8][2] = ((vnk[7][2]+((cnk[7][2][2]*Wirk[8][2])+((cnk[6][2][1]*Wirk[8][1]
      )+(cnk[7][2][0]*Wirk[8][0]))))+((cnk[8][2][2]*Wkrpk[8][2])+((cnk[7][2][0]*
      Wkrpk[8][0])+(cnk[8][2][1]*Wkrpk[8][1]))));
    vnk[9][0] = ((vnk[8][0]+((cnk[8][0][2]*Wirk[9][2])+((cnk[7][0][0]*Wirk[9][0]
      )+(cnk[8][0][1]*Wirk[9][1]))))+((cnk[9][0][2]*Wkrpk[9][2])+((cnk[8][0][1]*
      Wkrpk[9][1])+(cnk[9][0][0]*Wkrpk[9][0]))));
    vnk[9][1] = ((vnk[8][1]+((cnk[8][1][2]*Wirk[9][2])+((cnk[7][1][0]*Wirk[9][0]
      )+(cnk[8][1][1]*Wirk[9][1]))))+((cnk[9][1][2]*Wkrpk[9][2])+((cnk[8][1][1]*
      Wkrpk[9][1])+(cnk[9][1][0]*Wkrpk[9][0]))));
    vnk[9][2] = ((vnk[8][2]+((cnk[8][2][2]*Wirk[9][2])+((cnk[7][2][0]*Wirk[9][0]
      )+(cnk[8][2][1]*Wirk[9][1]))))+((cnk[9][2][2]*Wkrpk[9][2])+((cnk[8][2][1]*
      Wkrpk[9][1])+(cnk[9][2][0]*Wkrpk[9][0]))));
    vnk[10][0] = ((vnk[9][0]+((cnk[9][0][2]*Wirk[10][2])+((cnk[8][0][1]*
      Wirk[10][1])+(cnk[9][0][0]*Wirk[10][0]))))+((cnk[10][0][2]*Wkrpk[10][2])+(
      (cnk[8][0][1]*Wkrpk[10][1])+(cnk[10][0][0]*Wkrpk[10][0]))));
    vnk[10][1] = ((vnk[9][1]+((cnk[9][1][2]*Wirk[10][2])+((cnk[8][1][1]*
      Wirk[10][1])+(cnk[9][1][0]*Wirk[10][0]))))+((cnk[10][1][2]*Wkrpk[10][2])+(
      (cnk[8][1][1]*Wkrpk[10][1])+(cnk[10][1][0]*Wkrpk[10][0]))));
    vnk[10][2] = ((vnk[9][2]+((cnk[9][2][2]*Wirk[10][2])+((cnk[8][2][1]*
      Wirk[10][1])+(cnk[9][2][0]*Wirk[10][0]))))+((cnk[10][2][2]*Wkrpk[10][2])+(
      (cnk[8][2][1]*Wkrpk[10][1])+(cnk[10][2][0]*Wkrpk[10][0]))));
    vnk[11][0] = ((vnk[10][0]+((cnk[10][0][2]*Wirk[11][2])+((cnk[8][0][1]*
      Wirk[11][1])+(cnk[10][0][0]*Wirk[11][0]))))+((cnk[11][0][2]*Wkrpk[11][2])+
      ((cnk[10][0][0]*Wkrpk[11][0])+(cnk[11][0][1]*Wkrpk[11][1]))));
    vnk[11][1] = ((vnk[10][1]+((cnk[10][1][2]*Wirk[11][2])+((cnk[8][1][1]*
      Wirk[11][1])+(cnk[10][1][0]*Wirk[11][0]))))+((cnk[11][1][2]*Wkrpk[11][2])+
      ((cnk[10][1][0]*Wkrpk[11][0])+(cnk[11][1][1]*Wkrpk[11][1]))));
    vnk[11][2] = ((vnk[10][2]+((cnk[10][2][2]*Wirk[11][2])+((cnk[8][2][1]*
      Wirk[11][1])+(cnk[10][2][0]*Wirk[11][0]))))+((cnk[11][2][2]*Wkrpk[11][2])+
      ((cnk[10][2][0]*Wkrpk[11][0])+(cnk[11][2][1]*Wkrpk[11][1]))));
    vnk[12][0] = ((vnk[5][0]+((Cik[3][0][2]*Wirk[12][2])+((Cik[3][0][0]*
      Wirk[12][0])+(Cik[3][0][1]*Wirk[12][1]))))+((Cik[3][0][2]*Wkrpk[12][2])+((
      cnk[12][0][0]*Wkrpk[12][0])+(cnk[12][0][1]*Wkrpk[12][1]))));
    vnk[12][1] = ((vnk[5][1]+((Cik[3][1][2]*Wirk[12][2])+((Cik[3][1][0]*
      Wirk[12][0])+(Cik[3][1][1]*Wirk[12][1]))))+((Cik[3][1][2]*Wkrpk[12][2])+((
      cnk[12][1][0]*Wkrpk[12][0])+(cnk[12][1][1]*Wkrpk[12][1]))));
    vnk[12][2] = ((vnk[5][2]+((Cik[3][2][2]*Wirk[12][2])+((Cik[3][2][0]*
      Wirk[12][0])+(Cik[3][2][1]*Wirk[12][1]))))+((Cik[3][2][2]*Wkrpk[12][2])+((
      cnk[12][2][0]*Wkrpk[12][0])+(cnk[12][2][1]*Wkrpk[12][1]))));
    vnk[13][0] = ((vnk[12][0]+((Cik[3][0][2]*Wirk[13][2])+((cnk[12][0][0]*
      Wirk[13][0])+(cnk[12][0][1]*Wirk[13][1]))))+((cnk[13][0][2]*Wkrpk[13][2])+
      ((cnk[12][0][1]*Wkrpk[13][1])+(cnk[13][0][0]*Wkrpk[13][0]))));
    vnk[13][1] = ((vnk[12][1]+((Cik[3][1][2]*Wirk[13][2])+((cnk[12][1][0]*
      Wirk[13][0])+(cnk[12][1][1]*Wirk[13][1]))))+((cnk[13][1][2]*Wkrpk[13][2])+
      ((cnk[12][1][1]*Wkrpk[13][1])+(cnk[13][1][0]*Wkrpk[13][0]))));
    vnk[13][2] = ((vnk[12][2]+((Cik[3][2][2]*Wirk[13][2])+((cnk[12][2][0]*
      Wirk[13][0])+(cnk[12][2][1]*Wirk[13][1]))))+((cnk[13][2][2]*Wkrpk[13][2])+
      ((cnk[12][2][1]*Wkrpk[13][1])+(cnk[13][2][0]*Wkrpk[13][0]))));
    vnk[14][0] = ((vnk[13][0]+((cnk[13][0][2]*Wirk[14][2])+((cnk[12][0][1]*
      Wirk[14][1])+(cnk[13][0][0]*Wirk[14][0]))))+((cnk[14][0][2]*Wkrpk[14][2])+
      ((cnk[13][0][0]*Wkrpk[14][0])+(cnk[14][0][1]*Wkrpk[14][1]))));
    vnk[14][1] = ((vnk[13][1]+((cnk[13][1][2]*Wirk[14][2])+((cnk[12][1][1]*
      Wirk[14][1])+(cnk[13][1][0]*Wirk[14][0]))))+((cnk[14][1][2]*Wkrpk[14][2])+
      ((cnk[13][1][0]*Wkrpk[14][0])+(cnk[14][1][1]*Wkrpk[14][1]))));
    vnk[14][2] = ((vnk[13][2]+((cnk[13][2][2]*Wirk[14][2])+((cnk[12][2][1]*
      Wirk[14][1])+(cnk[13][2][0]*Wirk[14][0]))))+((cnk[14][2][2]*Wkrpk[14][2])+
      ((cnk[13][2][0]*Wkrpk[14][0])+(cnk[14][2][1]*Wkrpk[14][1]))));
    vnk[15][0] = ((vnk[14][0]+((cnk[14][0][2]*Wirk[15][2])+((cnk[13][0][0]*
      Wirk[15][0])+(cnk[14][0][1]*Wirk[15][1]))))+((cnk[15][0][2]*Wkrpk[15][2])+
      ((cnk[14][0][1]*Wkrpk[15][1])+(cnk[15][0][0]*Wkrpk[15][0]))));
    vnk[15][1] = ((vnk[14][1]+((cnk[14][1][2]*Wirk[15][2])+((cnk[13][1][0]*
      Wirk[15][0])+(cnk[14][1][1]*Wirk[15][1]))))+((cnk[15][1][2]*Wkrpk[15][2])+
      ((cnk[14][1][1]*Wkrpk[15][1])+(cnk[15][1][0]*Wkrpk[15][0]))));
    vnk[15][2] = ((vnk[14][2]+((cnk[14][2][2]*Wirk[15][2])+((cnk[13][2][0]*
      Wirk[15][0])+(cnk[14][2][1]*Wirk[15][1]))))+((cnk[15][2][2]*Wkrpk[15][2])+
      ((cnk[14][2][1]*Wkrpk[15][1])+(cnk[15][2][0]*Wkrpk[15][0]))));
    vnk[16][0] = ((vnk[15][0]+((cnk[15][0][2]*Wirk[16][2])+((cnk[14][0][1]*
      Wirk[16][1])+(cnk[15][0][0]*Wirk[16][0]))))+((cnk[16][0][2]*Wkrpk[16][2])+
      ((cnk[14][0][1]*Wkrpk[16][1])+(cnk[16][0][0]*Wkrpk[16][0]))));
    vnk[16][1] = ((vnk[15][1]+((cnk[15][1][2]*Wirk[16][2])+((cnk[14][1][1]*
      Wirk[16][1])+(cnk[15][1][0]*Wirk[16][0]))))+((cnk[16][1][2]*Wkrpk[16][2])+
      ((cnk[14][1][1]*Wkrpk[16][1])+(cnk[16][1][0]*Wkrpk[16][0]))));
    vnk[16][2] = ((vnk[15][2]+((cnk[15][2][2]*Wirk[16][2])+((cnk[14][2][1]*
      Wirk[16][1])+(cnk[15][2][0]*Wirk[16][0]))))+((cnk[16][2][2]*Wkrpk[16][2])+
      ((cnk[14][2][1]*Wkrpk[16][1])+(cnk[16][2][0]*Wkrpk[16][0]))));
    vnk[17][0] = ((vnk[16][0]+((cnk[16][0][2]*Wirk[17][2])+((cnk[14][0][1]*
      Wirk[17][1])+(cnk[16][0][0]*Wirk[17][0]))))+((cnk[17][0][2]*Wkrpk[17][2])+
      ((cnk[16][0][0]*Wkrpk[17][0])+(cnk[17][0][1]*Wkrpk[17][1]))));
    vnk[17][1] = ((vnk[16][1]+((cnk[16][1][2]*Wirk[17][2])+((cnk[14][1][1]*
      Wirk[17][1])+(cnk[16][1][0]*Wirk[17][0]))))+((cnk[17][1][2]*Wkrpk[17][2])+
      ((cnk[16][1][0]*Wkrpk[17][0])+(cnk[17][1][1]*Wkrpk[17][1]))));
    vnk[17][2] = ((vnk[16][2]+((cnk[16][2][2]*Wirk[17][2])+((cnk[14][2][1]*
      Wirk[17][1])+(cnk[16][2][0]*Wirk[17][0]))))+((cnk[17][2][2]*Wkrpk[17][2])+
      ((cnk[16][2][0]*Wkrpk[17][0])+(cnk[17][2][1]*Wkrpk[17][1]))));
    vnk[18][0] = ((vnk[5][0]+((Cik[3][0][2]*Wirk[18][2])+((Cik[3][0][0]*
      Wirk[18][0])+(Cik[3][0][1]*Wirk[18][1]))))+((cnk[18][0][2]*Wkrpk[18][2])+(
      (Cik[3][0][1]*Wkrpk[18][1])+(cnk[18][0][0]*Wkrpk[18][0]))));
    vnk[18][1] = ((vnk[5][1]+((Cik[3][1][2]*Wirk[18][2])+((Cik[3][1][0]*
      Wirk[18][0])+(Cik[3][1][1]*Wirk[18][1]))))+((cnk[18][1][2]*Wkrpk[18][2])+(
      (Cik[3][1][1]*Wkrpk[18][1])+(cnk[18][1][0]*Wkrpk[18][0]))));
    vnk[18][2] = ((vnk[5][2]+((Cik[3][2][2]*Wirk[18][2])+((Cik[3][2][0]*
      Wirk[18][0])+(Cik[3][2][1]*Wirk[18][1]))))+((cnk[18][2][2]*Wkrpk[18][2])+(
      (Cik[3][2][1]*Wkrpk[18][1])+(cnk[18][2][0]*Wkrpk[18][0]))));
    vnk[19][0] = ((vnk[18][0]+((cnk[18][0][2]*Wirk[19][2])+((Cik[3][0][1]*
      Wirk[19][1])+(cnk[18][0][0]*Wirk[19][0]))))+((cnk[19][0][2]*Wkrpk[19][2])+
      ((cnk[18][0][0]*Wkrpk[19][0])+(cnk[19][0][1]*Wkrpk[19][1]))));
    vnk[19][1] = ((vnk[18][1]+((cnk[18][1][2]*Wirk[19][2])+((Cik[3][1][1]*
      Wirk[19][1])+(cnk[18][1][0]*Wirk[19][0]))))+((cnk[19][1][2]*Wkrpk[19][2])+
      ((cnk[18][1][0]*Wkrpk[19][0])+(cnk[19][1][1]*Wkrpk[19][1]))));
    vnk[19][2] = ((vnk[18][2]+((cnk[18][2][2]*Wirk[19][2])+((Cik[3][2][1]*
      Wirk[19][1])+(cnk[18][2][0]*Wirk[19][0]))))+((cnk[19][2][2]*Wkrpk[19][2])+
      ((cnk[18][2][0]*Wkrpk[19][0])+(cnk[19][2][1]*Wkrpk[19][1]))));
    vnk[20][0] = ((vnk[19][0]+((cnk[19][0][2]*Wirk[20][2])+((cnk[18][0][0]*
      Wirk[20][0])+(cnk[19][0][1]*Wirk[20][1]))))+((cnk[20][0][2]*Wkrpk[20][2])+
      ((cnk[19][0][1]*Wkrpk[20][1])+(cnk[20][0][0]*Wkrpk[20][0]))));
    vnk[20][1] = ((vnk[19][1]+((cnk[19][1][2]*Wirk[20][2])+((cnk[18][1][0]*
      Wirk[20][0])+(cnk[19][1][1]*Wirk[20][1]))))+((cnk[20][1][2]*Wkrpk[20][2])+
      ((cnk[19][1][1]*Wkrpk[20][1])+(cnk[20][1][0]*Wkrpk[20][0]))));
    vnk[20][2] = ((vnk[19][2]+((cnk[19][2][2]*Wirk[20][2])+((cnk[18][2][0]*
      Wirk[20][0])+(cnk[19][2][1]*Wirk[20][1]))))+((cnk[20][2][2]*Wkrpk[20][2])+
      ((cnk[19][2][1]*Wkrpk[20][1])+(cnk[20][2][0]*Wkrpk[20][0]))));
    vnk[21][0] = ((vnk[20][0]+((cnk[20][0][2]*Wirk[21][2])+((cnk[19][0][1]*
      Wirk[21][1])+(cnk[20][0][0]*Wirk[21][0]))))+((cnk[20][0][2]*Wkrpk[21][2])+
      ((cnk[21][0][0]*Wkrpk[21][0])+(cnk[21][0][1]*Wkrpk[21][1]))));
    vnk[21][1] = ((vnk[20][1]+((cnk[20][1][2]*Wirk[21][2])+((cnk[19][1][1]*
      Wirk[21][1])+(cnk[20][1][0]*Wirk[21][0]))))+((cnk[20][1][2]*Wkrpk[21][2])+
      ((cnk[21][1][0]*Wkrpk[21][0])+(cnk[21][1][1]*Wkrpk[21][1]))));
    vnk[21][2] = ((vnk[20][2]+((cnk[20][2][2]*Wirk[21][2])+((cnk[19][2][1]*
      Wirk[21][1])+(cnk[20][2][0]*Wirk[21][0]))))+((cnk[20][2][2]*Wkrpk[21][2])+
      ((cnk[21][2][0]*Wkrpk[21][0])+(cnk[21][2][1]*Wkrpk[21][1]))));
    vnk[22][0] = ((vnk[5][0]+((Cik[3][0][2]*Wirk[22][2])+((Cik[3][0][0]*
      Wirk[22][0])+(Cik[3][0][1]*Wirk[22][1]))))+((cnk[22][0][2]*Wkrpk[22][2])+(
      (Cik[3][0][1]*Wkrpk[22][1])+(cnk[22][0][0]*Wkrpk[22][0]))));
    vnk[22][1] = ((vnk[5][1]+((Cik[3][1][2]*Wirk[22][2])+((Cik[3][1][0]*
      Wirk[22][0])+(Cik[3][1][1]*Wirk[22][1]))))+((cnk[22][1][2]*Wkrpk[22][2])+(
      (Cik[3][1][1]*Wkrpk[22][1])+(cnk[22][1][0]*Wkrpk[22][0]))));
    vnk[22][2] = ((vnk[5][2]+((Cik[3][2][2]*Wirk[22][2])+((Cik[3][2][0]*
      Wirk[22][0])+(Cik[3][2][1]*Wirk[22][1]))))+((cnk[22][2][2]*Wkrpk[22][2])+(
      (Cik[3][2][1]*Wkrpk[22][1])+(cnk[22][2][0]*Wkrpk[22][0]))));
    vnk[23][0] = ((vnk[22][0]+((cnk[22][0][2]*Wirk[23][2])+((Cik[3][0][1]*
      Wirk[23][1])+(cnk[22][0][0]*Wirk[23][0]))))+((cnk[23][0][2]*Wkrpk[23][2])+
      ((cnk[22][0][0]*Wkrpk[23][0])+(cnk[23][0][1]*Wkrpk[23][1]))));
    vnk[23][1] = ((vnk[22][1]+((cnk[22][1][2]*Wirk[23][2])+((Cik[3][1][1]*
      Wirk[23][1])+(cnk[22][1][0]*Wirk[23][0]))))+((cnk[23][1][2]*Wkrpk[23][2])+
      ((cnk[22][1][0]*Wkrpk[23][0])+(cnk[23][1][1]*Wkrpk[23][1]))));
    vnk[23][2] = ((vnk[22][2]+((cnk[22][2][2]*Wirk[23][2])+((Cik[3][2][1]*
      Wirk[23][1])+(cnk[22][2][0]*Wirk[23][0]))))+((cnk[23][2][2]*Wkrpk[23][2])+
      ((cnk[22][2][0]*Wkrpk[23][0])+(cnk[23][2][1]*Wkrpk[23][1]))));
    vnk[24][0] = ((vnk[23][0]+((cnk[23][0][2]*Wirk[24][2])+((cnk[22][0][0]*
      Wirk[24][0])+(cnk[23][0][1]*Wirk[24][1]))))+((cnk[24][0][2]*Wkrpk[24][2])+
      ((cnk[23][0][1]*Wkrpk[24][1])+(cnk[24][0][0]*Wkrpk[24][0]))));
    vnk[24][1] = ((vnk[23][1]+((cnk[23][1][2]*Wirk[24][2])+((cnk[22][1][0]*
      Wirk[24][0])+(cnk[23][1][1]*Wirk[24][1]))))+((cnk[24][1][2]*Wkrpk[24][2])+
      ((cnk[23][1][1]*Wkrpk[24][1])+(cnk[24][1][0]*Wkrpk[24][0]))));
    vnk[24][2] = ((vnk[23][2]+((cnk[23][2][2]*Wirk[24][2])+((cnk[22][2][0]*
      Wirk[24][0])+(cnk[23][2][1]*Wirk[24][1]))))+((cnk[24][2][2]*Wkrpk[24][2])+
      ((cnk[23][2][1]*Wkrpk[24][1])+(cnk[24][2][0]*Wkrpk[24][0]))));
    vnk[25][0] = ((vnk[24][0]+((cnk[24][0][2]*Wirk[25][2])+((cnk[23][0][1]*
      Wirk[25][1])+(cnk[24][0][0]*Wirk[25][0]))))+((cnk[24][0][2]*Wkrpk[25][2])+
      ((cnk[25][0][0]*Wkrpk[25][0])+(cnk[25][0][1]*Wkrpk[25][1]))));
    vnk[25][1] = ((vnk[24][1]+((cnk[24][1][2]*Wirk[25][2])+((cnk[23][1][1]*
      Wirk[25][1])+(cnk[24][1][0]*Wirk[25][0]))))+((cnk[24][1][2]*Wkrpk[25][2])+
      ((cnk[25][1][0]*Wkrpk[25][0])+(cnk[25][1][1]*Wkrpk[25][1]))));
    vnk[25][2] = ((vnk[24][2]+((cnk[24][2][2]*Wirk[25][2])+((cnk[23][2][1]*
      Wirk[25][1])+(cnk[24][2][0]*Wirk[25][0]))))+((cnk[24][2][2]*Wkrpk[25][2])+
      ((cnk[25][2][0]*Wkrpk[25][0])+(cnk[25][2][1]*Wkrpk[25][1]))));
    vnb[0][0] = vnk[5][0];
    vnb[0][1] = vnk[5][1];
    vnb[0][2] = vnk[5][2];
    vnb[1][0] = vnk[6][0];
    vnb[1][1] = vnk[6][1];
    vnb[1][2] = vnk[6][2];
    vnb[2][0] = vnk[7][0];
    vnb[2][1] = vnk[7][1];
    vnb[2][2] = vnk[7][2];
    vnb[3][0] = vnk[8][0];
    vnb[3][1] = vnk[8][1];
    vnb[3][2] = vnk[8][2];
    vnb[4][0] = vnk[9][0];
    vnb[4][1] = vnk[9][1];
    vnb[4][2] = vnk[9][2];
    vnb[5][0] = vnk[10][0];
    vnb[5][1] = vnk[10][1];
    vnb[5][2] = vnk[10][2];
    vnb[6][0] = vnk[11][0];
    vnb[6][1] = vnk[11][1];
    vnb[6][2] = vnk[11][2];
    vnb[7][0] = vnk[12][0];
    vnb[7][1] = vnk[12][1];
    vnb[7][2] = vnk[12][2];
    vnb[8][0] = vnk[13][0];
    vnb[8][1] = vnk[13][1];
    vnb[8][2] = vnk[13][2];
    vnb[9][0] = vnk[14][0];
    vnb[9][1] = vnk[14][1];
    vnb[9][2] = vnk[14][2];
    vnb[10][0] = vnk[15][0];
    vnb[10][1] = vnk[15][1];
    vnb[10][2] = vnk[15][2];
    vnb[11][0] = vnk[16][0];
    vnb[11][1] = vnk[16][1];
    vnb[11][2] = vnk[16][2];
    vnb[12][0] = vnk[17][0];
    vnb[12][1] = vnk[17][1];
    vnb[12][2] = vnk[17][2];
    vnb[13][0] = vnk[18][0];
    vnb[13][1] = vnk[18][1];
    vnb[13][2] = vnk[18][2];
    vnb[14][0] = vnk[19][0];
    vnb[14][1] = vnk[19][1];
    vnb[14][2] = vnk[19][2];
    vnb[15][0] = vnk[20][0];
    vnb[15][1] = vnk[20][1];
    vnb[15][2] = vnk[20][2];
    vnb[16][0] = vnk[21][0];
    vnb[16][1] = vnk[21][1];
    vnb[16][2] = vnk[21][2];
    vnb[17][0] = vnk[22][0];
    vnb[17][1] = vnk[22][1];
    vnb[17][2] = vnk[22][2];
    vnb[18][0] = vnk[23][0];
    vnb[18][1] = vnk[23][1];
    vnb[18][2] = vnk[23][2];
    vnb[19][0] = vnk[24][0];
    vnb[19][1] = vnk[24][1];
    vnb[19][2] = vnk[24][2];
    vnb[20][0] = vnk[25][0];
    vnb[20][1] = vnk[25][1];
    vnb[20][2] = vnk[25][2];
/*
Compute qdot (kinematical equations)
*/
    qdot[0] = u[0];
    qdot[1] = u[1];
    qdot[2] = u[2];
    qdot[3] = (.5*((q[26]*u[3])+((q[4]*u[5])-(q[5]*u[4]))));
    qdot[4] = (.5*((q[5]*u[3])+((q[26]*u[4])-(q[3]*u[5]))));
    qdot[5] = (.5*(((q[3]*u[4])+(q[26]*u[5]))-(q[4]*u[3])));
    qdot[26] = -(.5*((q[3]*u[3])+((q[4]*u[4])+(q[5]*u[5]))));
    if (stabvel  !=  0.) {
        ee = ((q[26]*q[26])+((q[5]*q[5])+((q[3]*q[3])+(q[4]*q[4]))));
        stab = ((stabvel*(1.-ee))/ee);
        qdot[3] = (qdot[3]+(q[3]*stab));
        qdot[4] = (qdot[4]+(q[4]*stab));
        qdot[5] = (qdot[5]+(q[5]*stab));
        qdot[26] = (qdot[26]+(q[26]*stab));
    }
    qdot[6] = u[6];
    qdot[7] = u[7];
    qdot[8] = u[8];
    qdot[9] = u[9];
    qdot[10] = u[10];
    qdot[11] = u[11];
    qdot[12] = u[12];
    qdot[13] = u[13];
    qdot[14] = u[14];
    qdot[15] = u[15];
    qdot[16] = u[16];
    qdot[17] = u[17];
    qdot[18] = u[18];
    qdot[19] = u[19];
    qdot[20] = u[20];
    qdot[21] = u[21];
    qdot[22] = u[22];
    qdot[23] = u[23];
    qdot[24] = u[24];
    qdot[25] = u[25];
    skipus: ;
/*
Initialize applied forces and torques to zero
*/
    for (i = 0; i < 21; i++) {
        for (j = 0; j < 3; j++) {
            ufk[i][j] = 0.;
            utk[i][j] = 0.;
        }
    }
    for (i = 0; i < 26; i++) {
        utau[i] = 0.;
    }
    ltauflg = 0;
    fs0flg = 0;
/*
 Used 0.06 seconds CPU time,
 0 additional bytes of memory.
 Equations contain 1594 adds/subtracts/negates
                   2039 multiplies
                      4 divides
                   1480 assignments
*/
}

void Jimmy::sdqdot(double oqdot[27])
{
/*
Return position coordinate derivatives for tree joints.
*/
    int i;

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(63,23);
        return;
    }
    for (i = 0; i <= 26; i++) {
        oqdot[i] = qdot[i];
    }
}

void Jimmy::sdu2qdot(double uin[26],
    double oqdot[27])
{
/*
Convert velocities to qdots.
*/
    int i;

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(64,23);
        return;
    }
    for (i = 0; i <= 25; i++) {
        oqdot[i] = uin[i];
    }
    oqdot[3] = (.5*((q[26]*uin[3])+((q[4]*uin[5])-(q[5]*uin[4]))));
    oqdot[4] = (.5*((q[5]*uin[3])+((q[26]*uin[4])-(q[3]*uin[5]))));
    oqdot[5] = (.5*(((q[3]*uin[4])+(q[26]*uin[5]))-(q[4]*uin[3])));
    oqdot[26] = -(.5*((q[3]*uin[3])+((q[4]*uin[4])+(q[5]*uin[5]))));
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    9 adds/subtracts/negates
                     16 multiplies
                      0 divides
                     30 assignments
*/
}

void Jimmy::sdpsstate(double lqin[1])
{

    if (roustate != 2) {
        sdseterr(9,23);
        return;
    }
}

void Jimmy::sddovpk(void)
{

    if (vpkflg == 0) {
/*
Compute Wpk (partial angular velocities)
*/
        Wpk[3][3][0] = 1.;
        Wpk[3][4][0] = 1.;
        Wpk[3][5][0] = 1.;
        Wpk[3][6][0] = c6;
        Wpk[3][6][1] = -s6;
        Wpk[3][7][0] = (c6*c7);
        Wpk[3][7][1] = -s6;
        Wpk[3][7][2] = (s7*c6);
        Wpk[3][8][0] = Wpk[3][7][0];
        Wpk[3][8][1] = ((Wpk[3][7][2]*s8)-(s6*c8));
        Wpk[3][8][2] = ((Wpk[3][7][2]*c8)+(s6*s8));
        Wpk[3][9][0] = ((Wpk[3][7][0]*c9)-(Wpk[3][8][2]*s9));
        Wpk[3][9][1] = Wpk[3][8][1];
        Wpk[3][9][2] = ((Wpk[3][7][0]*s9)+(Wpk[3][8][2]*c9));
        Wpk[3][10][0] = ((Wpk[3][9][0]*c10)-(Wpk[3][9][2]*s10));
        Wpk[3][10][1] = Wpk[3][8][1];
        Wpk[3][10][2] = ((Wpk[3][9][0]*s10)+(Wpk[3][9][2]*c10));
        Wpk[3][11][0] = Wpk[3][10][0];
        Wpk[3][11][1] = ((Wpk[3][8][1]*c11)+(Wpk[3][10][2]*s11));
        Wpk[3][11][2] = ((Wpk[3][10][2]*c11)-(Wpk[3][8][1]*s11));
        Wpk[3][12][0] = c12;
        Wpk[3][12][1] = -s12;
        Wpk[3][13][0] = (c12*c13);
        Wpk[3][13][1] = -s12;
        Wpk[3][13][2] = (s13*c12);
        Wpk[3][14][0] = Wpk[3][13][0];
        Wpk[3][14][1] = ((Wpk[3][13][2]*s14)-(s12*c14));
        Wpk[3][14][2] = ((Wpk[3][13][2]*c14)+(s12*s14));
        Wpk[3][15][0] = ((Wpk[3][13][0]*c15)-(Wpk[3][14][2]*s15));
        Wpk[3][15][1] = Wpk[3][14][1];
        Wpk[3][15][2] = ((Wpk[3][13][0]*s15)+(Wpk[3][14][2]*c15));
        Wpk[3][16][0] = ((Wpk[3][15][0]*c16)-(Wpk[3][15][2]*s16));
        Wpk[3][16][1] = Wpk[3][14][1];
        Wpk[3][16][2] = ((Wpk[3][15][0]*s16)+(Wpk[3][15][2]*c16));
        Wpk[3][17][0] = Wpk[3][16][0];
        Wpk[3][17][1] = ((Wpk[3][14][1]*c17)+(Wpk[3][16][2]*s17));
        Wpk[3][17][2] = ((Wpk[3][16][2]*c17)-(Wpk[3][14][1]*s17));
        Wpk[3][18][0] = c18;
        Wpk[3][18][2] = s18;
        Wpk[3][19][0] = c18;
        Wpk[3][19][1] = (s18*s19);
        Wpk[3][19][2] = (s18*c19);
        Wpk[3][20][0] = ((c18*c20)-(Wpk[3][19][2]*s20));
        Wpk[3][20][1] = Wpk[3][19][1];
        Wpk[3][20][2] = ((Wpk[3][19][2]*c20)+(s20*c18));
        Wpk[3][21][0] = ((Wpk[3][19][1]*s21)+(Wpk[3][20][0]*c21));
        Wpk[3][21][1] = ((Wpk[3][19][1]*c21)-(Wpk[3][20][0]*s21));
        Wpk[3][21][2] = Wpk[3][20][2];
        Wpk[3][22][0] = c22;
        Wpk[3][22][2] = s22;
        Wpk[3][23][0] = c22;
        Wpk[3][23][1] = (s22*s23);
        Wpk[3][23][2] = (s22*c23);
        Wpk[3][24][0] = ((c22*c24)-(Wpk[3][23][2]*s24));
        Wpk[3][24][1] = Wpk[3][23][1];
        Wpk[3][24][2] = ((Wpk[3][23][2]*c24)+(s24*c22));
        Wpk[3][25][0] = ((Wpk[3][23][1]*s25)+(Wpk[3][24][0]*c25));
        Wpk[3][25][1] = ((Wpk[3][23][1]*c25)-(Wpk[3][24][0]*s25));
        Wpk[3][25][2] = Wpk[3][24][2];
        Wpk[4][4][1] = 1.;
        Wpk[4][5][1] = 1.;
        Wpk[4][6][0] = s6;
        Wpk[4][6][1] = c6;
        Wpk[4][7][0] = (s6*c7);
        Wpk[4][7][1] = c6;
        Wpk[4][7][2] = (s6*s7);
        Wpk[4][8][0] = Wpk[4][7][0];
        Wpk[4][8][1] = ((Wpk[4][7][2]*s8)+(c6*c8));
        Wpk[4][8][2] = ((Wpk[4][7][2]*c8)-(s8*c6));
        Wpk[4][9][0] = ((Wpk[4][7][0]*c9)-(Wpk[4][8][2]*s9));
        Wpk[4][9][1] = Wpk[4][8][1];
        Wpk[4][9][2] = ((Wpk[4][7][0]*s9)+(Wpk[4][8][2]*c9));
        Wpk[4][10][0] = ((Wpk[4][9][0]*c10)-(Wpk[4][9][2]*s10));
        Wpk[4][10][1] = Wpk[4][8][1];
        Wpk[4][10][2] = ((Wpk[4][9][0]*s10)+(Wpk[4][9][2]*c10));
        Wpk[4][11][0] = Wpk[4][10][0];
        Wpk[4][11][1] = ((Wpk[4][8][1]*c11)+(Wpk[4][10][2]*s11));
        Wpk[4][11][2] = ((Wpk[4][10][2]*c11)-(Wpk[4][8][1]*s11));
        Wpk[4][12][0] = s12;
        Wpk[4][12][1] = c12;
        Wpk[4][13][0] = (s12*c13);
        Wpk[4][13][1] = c12;
        Wpk[4][13][2] = (s12*s13);
        Wpk[4][14][0] = Wpk[4][13][0];
        Wpk[4][14][1] = ((Wpk[4][13][2]*s14)+(c12*c14));
        Wpk[4][14][2] = ((Wpk[4][13][2]*c14)-(s14*c12));
        Wpk[4][15][0] = ((Wpk[4][13][0]*c15)-(Wpk[4][14][2]*s15));
        Wpk[4][15][1] = Wpk[4][14][1];
        Wpk[4][15][2] = ((Wpk[4][13][0]*s15)+(Wpk[4][14][2]*c15));
        Wpk[4][16][0] = ((Wpk[4][15][0]*c16)-(Wpk[4][15][2]*s16));
        Wpk[4][16][1] = Wpk[4][14][1];
        Wpk[4][16][2] = ((Wpk[4][15][0]*s16)+(Wpk[4][15][2]*c16));
        Wpk[4][17][0] = Wpk[4][16][0];
        Wpk[4][17][1] = ((Wpk[4][14][1]*c17)+(Wpk[4][16][2]*s17));
        Wpk[4][17][2] = ((Wpk[4][16][2]*c17)-(Wpk[4][14][1]*s17));
        Wpk[4][18][1] = 1.;
        Wpk[4][19][1] = c19;
        Wpk[4][19][2] = -s19;
        Wpk[4][20][0] = (s19*s20);
        Wpk[4][20][1] = c19;
        Wpk[4][20][2] = -(s19*c20);
        Wpk[4][21][0] = ((Wpk[4][20][0]*c21)+(s21*c19));
        Wpk[4][21][1] = ((c19*c21)-(Wpk[4][20][0]*s21));
        Wpk[4][21][2] = Wpk[4][20][2];
        Wpk[4][22][1] = 1.;
        Wpk[4][23][1] = c23;
        Wpk[4][23][2] = -s23;
        Wpk[4][24][0] = (s23*s24);
        Wpk[4][24][1] = c23;
        Wpk[4][24][2] = -(s23*c24);
        Wpk[4][25][0] = ((Wpk[4][24][0]*c25)+(s25*c23));
        Wpk[4][25][1] = ((c23*c25)-(Wpk[4][24][0]*s25));
        Wpk[4][25][2] = Wpk[4][24][2];
        Wpk[5][5][2] = 1.;
        Wpk[5][6][2] = 1.;
        Wpk[5][7][0] = -s7;
        Wpk[5][7][2] = c7;
        Wpk[5][8][0] = -s7;
        Wpk[5][8][1] = (s8*c7);
        Wpk[5][8][2] = (c7*c8);
        Wpk[5][9][0] = -((Wpk[5][8][2]*s9)+(s7*c9));
        Wpk[5][9][1] = Wpk[5][8][1];
        Wpk[5][9][2] = ((Wpk[5][8][2]*c9)-(s7*s9));
        Wpk[5][10][0] = ((Wpk[5][9][0]*c10)-(Wpk[5][9][2]*s10));
        Wpk[5][10][1] = Wpk[5][8][1];
        Wpk[5][10][2] = ((Wpk[5][9][0]*s10)+(Wpk[5][9][2]*c10));
        Wpk[5][11][0] = Wpk[5][10][0];
        Wpk[5][11][1] = ((Wpk[5][8][1]*c11)+(Wpk[5][10][2]*s11));
        Wpk[5][11][2] = ((Wpk[5][10][2]*c11)-(Wpk[5][8][1]*s11));
        Wpk[5][12][2] = 1.;
        Wpk[5][13][0] = -s13;
        Wpk[5][13][2] = c13;
        Wpk[5][14][0] = -s13;
        Wpk[5][14][1] = (s14*c13);
        Wpk[5][14][2] = (c13*c14);
        Wpk[5][15][0] = -((Wpk[5][14][2]*s15)+(s13*c15));
        Wpk[5][15][1] = Wpk[5][14][1];
        Wpk[5][15][2] = ((Wpk[5][14][2]*c15)-(s13*s15));
        Wpk[5][16][0] = ((Wpk[5][15][0]*c16)-(Wpk[5][15][2]*s16));
        Wpk[5][16][1] = Wpk[5][14][1];
        Wpk[5][16][2] = ((Wpk[5][15][0]*s16)+(Wpk[5][15][2]*c16));
        Wpk[5][17][0] = Wpk[5][16][0];
        Wpk[5][17][1] = ((Wpk[5][14][1]*c17)+(Wpk[5][16][2]*s17));
        Wpk[5][17][2] = ((Wpk[5][16][2]*c17)-(Wpk[5][14][1]*s17));
        Wpk[5][18][0] = -s18;
        Wpk[5][18][2] = c18;
        Wpk[5][19][0] = -s18;
        Wpk[5][19][1] = (s19*c18);
        Wpk[5][19][2] = (c18*c19);
        Wpk[5][20][0] = -((Wpk[5][19][2]*s20)+(s18*c20));
        Wpk[5][20][1] = Wpk[5][19][1];
        Wpk[5][20][2] = ((Wpk[5][19][2]*c20)-(s18*s20));
        Wpk[5][21][0] = ((Wpk[5][19][1]*s21)+(Wpk[5][20][0]*c21));
        Wpk[5][21][1] = ((Wpk[5][19][1]*c21)-(Wpk[5][20][0]*s21));
        Wpk[5][21][2] = Wpk[5][20][2];
        Wpk[5][22][0] = -s22;
        Wpk[5][22][2] = c22;
        Wpk[5][23][0] = -s22;
        Wpk[5][23][1] = (s23*c22);
        Wpk[5][23][2] = (c22*c23);
        Wpk[5][24][0] = -((Wpk[5][23][2]*s24)+(s22*c24));
        Wpk[5][24][1] = Wpk[5][23][1];
        Wpk[5][24][2] = ((Wpk[5][23][2]*c24)-(s22*s24));
        Wpk[5][25][0] = ((Wpk[5][23][1]*s25)+(Wpk[5][24][0]*c25));
        Wpk[5][25][1] = ((Wpk[5][23][1]*c25)-(Wpk[5][24][0]*s25));
        Wpk[5][25][2] = Wpk[5][24][2];
        Wpk[6][6][2] = 1.;
        Wpk[6][7][0] = -s7;
        Wpk[6][7][2] = c7;
        Wpk[6][8][0] = -s7;
        Wpk[6][8][1] = (s8*c7);
        Wpk[6][8][2] = (c7*c8);
        Wpk[6][9][0] = -((Wpk[6][8][2]*s9)+(s7*c9));
        Wpk[6][9][1] = Wpk[6][8][1];
        Wpk[6][9][2] = ((Wpk[6][8][2]*c9)-(s7*s9));
        Wpk[6][10][0] = ((Wpk[6][9][0]*c10)-(Wpk[6][9][2]*s10));
        Wpk[6][10][1] = Wpk[6][8][1];
        Wpk[6][10][2] = ((Wpk[6][9][0]*s10)+(Wpk[6][9][2]*c10));
        Wpk[6][11][0] = Wpk[6][10][0];
        Wpk[6][11][1] = ((Wpk[6][8][1]*c11)+(Wpk[6][10][2]*s11));
        Wpk[6][11][2] = ((Wpk[6][10][2]*c11)-(Wpk[6][8][1]*s11));
        Wpk[7][7][1] = 1.;
        Wpk[7][8][1] = c8;
        Wpk[7][8][2] = -s8;
        Wpk[7][9][0] = (s8*s9);
        Wpk[7][9][1] = c8;
        Wpk[7][9][2] = -(s8*c9);
        Wpk[7][10][0] = ((Wpk[7][9][0]*c10)-(Wpk[7][9][2]*s10));
        Wpk[7][10][1] = c8;
        Wpk[7][10][2] = ((Wpk[7][9][0]*s10)+(Wpk[7][9][2]*c10));
        Wpk[7][11][0] = Wpk[7][10][0];
        Wpk[7][11][1] = ((Wpk[7][10][2]*s11)+(c8*c11));
        Wpk[7][11][2] = ((Wpk[7][10][2]*c11)-(s11*c8));
        Wpk[8][8][0] = 1.;
        Wpk[8][9][0] = c9;
        Wpk[8][9][2] = s9;
        Wpk[8][10][0] = ((c9*c10)-(s9*s10));
        Wpk[8][10][2] = ((s9*c10)+(s10*c9));
        Wpk[8][11][0] = Wpk[8][10][0];
        Wpk[8][11][1] = (Wpk[8][10][2]*s11);
        Wpk[8][11][2] = (Wpk[8][10][2]*c11);
        Wpk[9][9][1] = 1.;
        Wpk[9][10][1] = 1.;
        Wpk[9][11][1] = c11;
        Wpk[9][11][2] = -s11;
        Wpk[10][10][1] = 1.;
        Wpk[10][11][1] = c11;
        Wpk[10][11][2] = -s11;
        Wpk[11][11][0] = 1.;
        Wpk[12][12][2] = 1.;
        Wpk[12][13][0] = -s13;
        Wpk[12][13][2] = c13;
        Wpk[12][14][0] = -s13;
        Wpk[12][14][1] = (s14*c13);
        Wpk[12][14][2] = (c13*c14);
        Wpk[12][15][0] = -((Wpk[12][14][2]*s15)+(s13*c15));
        Wpk[12][15][1] = Wpk[12][14][1];
        Wpk[12][15][2] = ((Wpk[12][14][2]*c15)-(s13*s15));
        Wpk[12][16][0] = ((Wpk[12][15][0]*c16)-(Wpk[12][15][2]*s16));
        Wpk[12][16][1] = Wpk[12][14][1];
        Wpk[12][16][2] = ((Wpk[12][15][0]*s16)+(Wpk[12][15][2]*c16));
        Wpk[12][17][0] = Wpk[12][16][0];
        Wpk[12][17][1] = ((Wpk[12][14][1]*c17)+(Wpk[12][16][2]*s17));
        Wpk[12][17][2] = ((Wpk[12][16][2]*c17)-(Wpk[12][14][1]*s17));
        Wpk[13][13][1] = 1.;
        Wpk[13][14][1] = c14;
        Wpk[13][14][2] = -s14;
        Wpk[13][15][0] = (s14*s15);
        Wpk[13][15][1] = c14;
        Wpk[13][15][2] = -(s14*c15);
        Wpk[13][16][0] = ((Wpk[13][15][0]*c16)-(Wpk[13][15][2]*s16));
        Wpk[13][16][1] = c14;
        Wpk[13][16][2] = ((Wpk[13][15][0]*s16)+(Wpk[13][15][2]*c16));
        Wpk[13][17][0] = Wpk[13][16][0];
        Wpk[13][17][1] = ((Wpk[13][16][2]*s17)+(c14*c17));
        Wpk[13][17][2] = ((Wpk[13][16][2]*c17)-(s17*c14));
        Wpk[14][14][0] = 1.;
        Wpk[14][15][0] = c15;
        Wpk[14][15][2] = s15;
        Wpk[14][16][0] = ((c15*c16)-(s15*s16));
        Wpk[14][16][2] = ((s15*c16)+(s16*c15));
        Wpk[14][17][0] = Wpk[14][16][0];
        Wpk[14][17][1] = (Wpk[14][16][2]*s17);
        Wpk[14][17][2] = (Wpk[14][16][2]*c17);
        Wpk[15][15][1] = 1.;
        Wpk[15][16][1] = 1.;
        Wpk[15][17][1] = c17;
        Wpk[15][17][2] = -s17;
        Wpk[16][16][1] = 1.;
        Wpk[16][17][1] = c17;
        Wpk[16][17][2] = -s17;
        Wpk[17][17][0] = 1.;
        Wpk[18][18][1] = 1.;
        Wpk[18][19][1] = c19;
        Wpk[18][19][2] = -s19;
        Wpk[18][20][0] = (s19*s20);
        Wpk[18][20][1] = c19;
        Wpk[18][20][2] = -(s19*c20);
        Wpk[18][21][0] = ((Wpk[18][20][0]*c21)+(s21*c19));
        Wpk[18][21][1] = ((c19*c21)-(Wpk[18][20][0]*s21));
        Wpk[18][21][2] = Wpk[18][20][2];
        Wpk[19][19][0] = 1.;
        Wpk[19][20][0] = c20;
        Wpk[19][20][2] = s20;
        Wpk[19][21][0] = (c20*c21);
        Wpk[19][21][1] = -(s21*c20);
        Wpk[19][21][2] = s20;
        Wpk[20][20][1] = 1.;
        Wpk[20][21][0] = s21;
        Wpk[20][21][1] = c21;
        Wpk[21][21][2] = 1.;
        Wpk[22][22][1] = 1.;
        Wpk[22][23][1] = c23;
        Wpk[22][23][2] = -s23;
        Wpk[22][24][0] = (s23*s24);
        Wpk[22][24][1] = c23;
        Wpk[22][24][2] = -(s23*c24);
        Wpk[22][25][0] = ((Wpk[22][24][0]*c25)+(s25*c23));
        Wpk[22][25][1] = ((c23*c25)-(Wpk[22][24][0]*s25));
        Wpk[22][25][2] = Wpk[22][24][2];
        Wpk[23][23][0] = 1.;
        Wpk[23][24][0] = c24;
        Wpk[23][24][2] = s24;
        Wpk[23][25][0] = (c24*c25);
        Wpk[23][25][1] = -(s25*c24);
        Wpk[23][25][2] = s24;
        Wpk[24][24][1] = 1.;
        Wpk[24][25][0] = s25;
        Wpk[24][25][1] = c25;
        Wpk[25][25][2] = 1.;
/*
Compute Vpk (partial velocities)
*/
        Vpk[0][0][0] = 1.;
        Vpk[0][1][0] = 1.;
        Vpk[0][2][0] = 1.;
        Vpk[0][3][0] = Cik[3][0][0];
        Vpk[0][3][1] = Cik[3][0][1];
        Vpk[0][3][2] = Cik[3][0][2];
        Vpk[0][4][0] = Cik[3][0][0];
        Vpk[0][4][1] = Cik[3][0][1];
        Vpk[0][4][2] = Cik[3][0][2];
        Vpk[0][5][0] = Cik[3][0][0];
        Vpk[0][5][1] = Cik[3][0][1];
        Vpk[0][5][2] = Cik[3][0][2];
        Vpk[0][6][0] = ((Cik[3][0][0]*c6)+(Cik[3][0][1]*s6));
        Vpk[0][6][1] = ((Cik[3][0][1]*c6)-(Cik[3][0][0]*s6));
        Vpk[0][6][2] = Cik[3][0][2];
        Vpk[0][7][0] = ((Vpk[0][6][0]*c7)-(Cik[3][0][2]*s7));
        Vpk[0][7][1] = Vpk[0][6][1];
        Vpk[0][7][2] = ((Cik[3][0][2]*c7)+(Vpk[0][6][0]*s7));
        Vpk[0][8][0] = Vpk[0][7][0];
        Vpk[0][8][1] = ((Vpk[0][6][1]*c8)+(Vpk[0][7][2]*s8));
        Vpk[0][8][2] = ((Vpk[0][7][2]*c8)-(Vpk[0][6][1]*s8));
        Vpk[0][9][0] = ((Vpk[0][7][0]*c9)-(Vpk[0][8][2]*s9));
        Vpk[0][9][1] = Vpk[0][8][1];
        Vpk[0][9][2] = ((Vpk[0][7][0]*s9)+(Vpk[0][8][2]*c9));
        Vpk[0][10][0] = ((Vpk[0][9][0]*c10)-(Vpk[0][9][2]*s10));
        Vpk[0][10][1] = Vpk[0][8][1];
        Vpk[0][10][2] = ((Vpk[0][9][0]*s10)+(Vpk[0][9][2]*c10));
        Vpk[0][11][0] = Vpk[0][10][0];
        Vpk[0][11][1] = ((Vpk[0][8][1]*c11)+(Vpk[0][10][2]*s11));
        Vpk[0][11][2] = ((Vpk[0][10][2]*c11)-(Vpk[0][8][1]*s11));
        Vpk[0][12][0] = ((Cik[3][0][0]*c12)+(Cik[3][0][1]*s12));
        Vpk[0][12][1] = ((Cik[3][0][1]*c12)-(Cik[3][0][0]*s12));
        Vpk[0][12][2] = Cik[3][0][2];
        Vpk[0][13][0] = ((Vpk[0][12][0]*c13)-(Cik[3][0][2]*s13));
        Vpk[0][13][1] = Vpk[0][12][1];
        Vpk[0][13][2] = ((Cik[3][0][2]*c13)+(Vpk[0][12][0]*s13));
        Vpk[0][14][0] = Vpk[0][13][0];
        Vpk[0][14][1] = ((Vpk[0][12][1]*c14)+(Vpk[0][13][2]*s14));
        Vpk[0][14][2] = ((Vpk[0][13][2]*c14)-(Vpk[0][12][1]*s14));
        Vpk[0][15][0] = ((Vpk[0][13][0]*c15)-(Vpk[0][14][2]*s15));
        Vpk[0][15][1] = Vpk[0][14][1];
        Vpk[0][15][2] = ((Vpk[0][13][0]*s15)+(Vpk[0][14][2]*c15));
        Vpk[0][16][0] = ((Vpk[0][15][0]*c16)-(Vpk[0][15][2]*s16));
        Vpk[0][16][1] = Vpk[0][14][1];
        Vpk[0][16][2] = ((Vpk[0][15][0]*s16)+(Vpk[0][15][2]*c16));
        Vpk[0][17][0] = Vpk[0][16][0];
        Vpk[0][17][1] = ((Vpk[0][14][1]*c17)+(Vpk[0][16][2]*s17));
        Vpk[0][17][2] = ((Vpk[0][16][2]*c17)-(Vpk[0][14][1]*s17));
        Vpk[0][18][0] = ((Cik[3][0][0]*c18)-(Cik[3][0][2]*s18));
        Vpk[0][18][1] = Cik[3][0][1];
        Vpk[0][18][2] = ((Cik[3][0][0]*s18)+(Cik[3][0][2]*c18));
        Vpk[0][19][0] = Vpk[0][18][0];
        Vpk[0][19][1] = ((Cik[3][0][1]*c19)+(Vpk[0][18][2]*s19));
        Vpk[0][19][2] = ((Vpk[0][18][2]*c19)-(Cik[3][0][1]*s19));
        Vpk[0][20][0] = ((Vpk[0][18][0]*c20)-(Vpk[0][19][2]*s20));
        Vpk[0][20][1] = Vpk[0][19][1];
        Vpk[0][20][2] = ((Vpk[0][18][0]*s20)+(Vpk[0][19][2]*c20));
        Vpk[0][21][0] = ((Vpk[0][19][1]*s21)+(Vpk[0][20][0]*c21));
        Vpk[0][21][1] = ((Vpk[0][19][1]*c21)-(Vpk[0][20][0]*s21));
        Vpk[0][21][2] = Vpk[0][20][2];
        Vpk[0][22][0] = ((Cik[3][0][0]*c22)-(Cik[3][0][2]*s22));
        Vpk[0][22][1] = Cik[3][0][1];
        Vpk[0][22][2] = ((Cik[3][0][0]*s22)+(Cik[3][0][2]*c22));
        Vpk[0][23][0] = Vpk[0][22][0];
        Vpk[0][23][1] = ((Cik[3][0][1]*c23)+(Vpk[0][22][2]*s23));
        Vpk[0][23][2] = ((Vpk[0][22][2]*c23)-(Cik[3][0][1]*s23));
        Vpk[0][24][0] = ((Vpk[0][22][0]*c24)-(Vpk[0][23][2]*s24));
        Vpk[0][24][1] = Vpk[0][23][1];
        Vpk[0][24][2] = ((Vpk[0][22][0]*s24)+(Vpk[0][23][2]*c24));
        Vpk[0][25][0] = ((Vpk[0][23][1]*s25)+(Vpk[0][24][0]*c25));
        Vpk[0][25][1] = ((Vpk[0][23][1]*c25)-(Vpk[0][24][0]*s25));
        Vpk[0][25][2] = Vpk[0][24][2];
        Vpk[1][1][1] = 1.;
        Vpk[1][2][1] = 1.;
        Vpk[1][3][0] = Cik[3][1][0];
        Vpk[1][3][1] = Cik[3][1][1];
        Vpk[1][3][2] = Cik[3][1][2];
        Vpk[1][4][0] = Cik[3][1][0];
        Vpk[1][4][1] = Cik[3][1][1];
        Vpk[1][4][2] = Cik[3][1][2];
        Vpk[1][5][0] = Cik[3][1][0];
        Vpk[1][5][1] = Cik[3][1][1];
        Vpk[1][5][2] = Cik[3][1][2];
        Vpk[1][6][0] = ((Cik[3][1][0]*c6)+(Cik[3][1][1]*s6));
        Vpk[1][6][1] = ((Cik[3][1][1]*c6)-(Cik[3][1][0]*s6));
        Vpk[1][6][2] = Cik[3][1][2];
        Vpk[1][7][0] = ((Vpk[1][6][0]*c7)-(Cik[3][1][2]*s7));
        Vpk[1][7][1] = Vpk[1][6][1];
        Vpk[1][7][2] = ((Cik[3][1][2]*c7)+(Vpk[1][6][0]*s7));
        Vpk[1][8][0] = Vpk[1][7][0];
        Vpk[1][8][1] = ((Vpk[1][6][1]*c8)+(Vpk[1][7][2]*s8));
        Vpk[1][8][2] = ((Vpk[1][7][2]*c8)-(Vpk[1][6][1]*s8));
        Vpk[1][9][0] = ((Vpk[1][7][0]*c9)-(Vpk[1][8][2]*s9));
        Vpk[1][9][1] = Vpk[1][8][1];
        Vpk[1][9][2] = ((Vpk[1][7][0]*s9)+(Vpk[1][8][2]*c9));
        Vpk[1][10][0] = ((Vpk[1][9][0]*c10)-(Vpk[1][9][2]*s10));
        Vpk[1][10][1] = Vpk[1][8][1];
        Vpk[1][10][2] = ((Vpk[1][9][0]*s10)+(Vpk[1][9][2]*c10));
        Vpk[1][11][0] = Vpk[1][10][0];
        Vpk[1][11][1] = ((Vpk[1][8][1]*c11)+(Vpk[1][10][2]*s11));
        Vpk[1][11][2] = ((Vpk[1][10][2]*c11)-(Vpk[1][8][1]*s11));
        Vpk[1][12][0] = ((Cik[3][1][0]*c12)+(Cik[3][1][1]*s12));
        Vpk[1][12][1] = ((Cik[3][1][1]*c12)-(Cik[3][1][0]*s12));
        Vpk[1][12][2] = Cik[3][1][2];
        Vpk[1][13][0] = ((Vpk[1][12][0]*c13)-(Cik[3][1][2]*s13));
        Vpk[1][13][1] = Vpk[1][12][1];
        Vpk[1][13][2] = ((Cik[3][1][2]*c13)+(Vpk[1][12][0]*s13));
        Vpk[1][14][0] = Vpk[1][13][0];
        Vpk[1][14][1] = ((Vpk[1][12][1]*c14)+(Vpk[1][13][2]*s14));
        Vpk[1][14][2] = ((Vpk[1][13][2]*c14)-(Vpk[1][12][1]*s14));
        Vpk[1][15][0] = ((Vpk[1][13][0]*c15)-(Vpk[1][14][2]*s15));
        Vpk[1][15][1] = Vpk[1][14][1];
        Vpk[1][15][2] = ((Vpk[1][13][0]*s15)+(Vpk[1][14][2]*c15));
        Vpk[1][16][0] = ((Vpk[1][15][0]*c16)-(Vpk[1][15][2]*s16));
        Vpk[1][16][1] = Vpk[1][14][1];
        Vpk[1][16][2] = ((Vpk[1][15][0]*s16)+(Vpk[1][15][2]*c16));
        Vpk[1][17][0] = Vpk[1][16][0];
        Vpk[1][17][1] = ((Vpk[1][14][1]*c17)+(Vpk[1][16][2]*s17));
        Vpk[1][17][2] = ((Vpk[1][16][2]*c17)-(Vpk[1][14][1]*s17));
        Vpk[1][18][0] = ((Cik[3][1][0]*c18)-(Cik[3][1][2]*s18));
        Vpk[1][18][1] = Cik[3][1][1];
        Vpk[1][18][2] = ((Cik[3][1][0]*s18)+(Cik[3][1][2]*c18));
        Vpk[1][19][0] = Vpk[1][18][0];
        Vpk[1][19][1] = ((Cik[3][1][1]*c19)+(Vpk[1][18][2]*s19));
        Vpk[1][19][2] = ((Vpk[1][18][2]*c19)-(Cik[3][1][1]*s19));
        Vpk[1][20][0] = ((Vpk[1][18][0]*c20)-(Vpk[1][19][2]*s20));
        Vpk[1][20][1] = Vpk[1][19][1];
        Vpk[1][20][2] = ((Vpk[1][18][0]*s20)+(Vpk[1][19][2]*c20));
        Vpk[1][21][0] = ((Vpk[1][19][1]*s21)+(Vpk[1][20][0]*c21));
        Vpk[1][21][1] = ((Vpk[1][19][1]*c21)-(Vpk[1][20][0]*s21));
        Vpk[1][21][2] = Vpk[1][20][2];
        Vpk[1][22][0] = ((Cik[3][1][0]*c22)-(Cik[3][1][2]*s22));
        Vpk[1][22][1] = Cik[3][1][1];
        Vpk[1][22][2] = ((Cik[3][1][0]*s22)+(Cik[3][1][2]*c22));
        Vpk[1][23][0] = Vpk[1][22][0];
        Vpk[1][23][1] = ((Cik[3][1][1]*c23)+(Vpk[1][22][2]*s23));
        Vpk[1][23][2] = ((Vpk[1][22][2]*c23)-(Cik[3][1][1]*s23));
        Vpk[1][24][0] = ((Vpk[1][22][0]*c24)-(Vpk[1][23][2]*s24));
        Vpk[1][24][1] = Vpk[1][23][1];
        Vpk[1][24][2] = ((Vpk[1][22][0]*s24)+(Vpk[1][23][2]*c24));
        Vpk[1][25][0] = ((Vpk[1][23][1]*s25)+(Vpk[1][24][0]*c25));
        Vpk[1][25][1] = ((Vpk[1][23][1]*c25)-(Vpk[1][24][0]*s25));
        Vpk[1][25][2] = Vpk[1][24][2];
        Vpk[2][2][2] = 1.;
        Vpk[2][3][0] = Cik[3][2][0];
        Vpk[2][3][1] = Cik[3][2][1];
        Vpk[2][3][2] = Cik[3][2][2];
        Vpk[2][4][0] = Cik[3][2][0];
        Vpk[2][4][1] = Cik[3][2][1];
        Vpk[2][4][2] = Cik[3][2][2];
        Vpk[2][5][0] = Cik[3][2][0];
        Vpk[2][5][1] = Cik[3][2][1];
        Vpk[2][5][2] = Cik[3][2][2];
        Vpk[2][6][0] = ((Cik[3][2][0]*c6)+(Cik[3][2][1]*s6));
        Vpk[2][6][1] = ((Cik[3][2][1]*c6)-(Cik[3][2][0]*s6));
        Vpk[2][6][2] = Cik[3][2][2];
        Vpk[2][7][0] = ((Vpk[2][6][0]*c7)-(Cik[3][2][2]*s7));
        Vpk[2][7][1] = Vpk[2][6][1];
        Vpk[2][7][2] = ((Cik[3][2][2]*c7)+(Vpk[2][6][0]*s7));
        Vpk[2][8][0] = Vpk[2][7][0];
        Vpk[2][8][1] = ((Vpk[2][6][1]*c8)+(Vpk[2][7][2]*s8));
        Vpk[2][8][2] = ((Vpk[2][7][2]*c8)-(Vpk[2][6][1]*s8));
        Vpk[2][9][0] = ((Vpk[2][7][0]*c9)-(Vpk[2][8][2]*s9));
        Vpk[2][9][1] = Vpk[2][8][1];
        Vpk[2][9][2] = ((Vpk[2][7][0]*s9)+(Vpk[2][8][2]*c9));
        Vpk[2][10][0] = ((Vpk[2][9][0]*c10)-(Vpk[2][9][2]*s10));
        Vpk[2][10][1] = Vpk[2][8][1];
        Vpk[2][10][2] = ((Vpk[2][9][0]*s10)+(Vpk[2][9][2]*c10));
        Vpk[2][11][0] = Vpk[2][10][0];
        Vpk[2][11][1] = ((Vpk[2][8][1]*c11)+(Vpk[2][10][2]*s11));
        Vpk[2][11][2] = ((Vpk[2][10][2]*c11)-(Vpk[2][8][1]*s11));
        Vpk[2][12][0] = ((Cik[3][2][0]*c12)+(Cik[3][2][1]*s12));
        Vpk[2][12][1] = ((Cik[3][2][1]*c12)-(Cik[3][2][0]*s12));
        Vpk[2][12][2] = Cik[3][2][2];
        Vpk[2][13][0] = ((Vpk[2][12][0]*c13)-(Cik[3][2][2]*s13));
        Vpk[2][13][1] = Vpk[2][12][1];
        Vpk[2][13][2] = ((Cik[3][2][2]*c13)+(Vpk[2][12][0]*s13));
        Vpk[2][14][0] = Vpk[2][13][0];
        Vpk[2][14][1] = ((Vpk[2][12][1]*c14)+(Vpk[2][13][2]*s14));
        Vpk[2][14][2] = ((Vpk[2][13][2]*c14)-(Vpk[2][12][1]*s14));
        Vpk[2][15][0] = ((Vpk[2][13][0]*c15)-(Vpk[2][14][2]*s15));
        Vpk[2][15][1] = Vpk[2][14][1];
        Vpk[2][15][2] = ((Vpk[2][13][0]*s15)+(Vpk[2][14][2]*c15));
        Vpk[2][16][0] = ((Vpk[2][15][0]*c16)-(Vpk[2][15][2]*s16));
        Vpk[2][16][1] = Vpk[2][14][1];
        Vpk[2][16][2] = ((Vpk[2][15][0]*s16)+(Vpk[2][15][2]*c16));
        Vpk[2][17][0] = Vpk[2][16][0];
        Vpk[2][17][1] = ((Vpk[2][14][1]*c17)+(Vpk[2][16][2]*s17));
        Vpk[2][17][2] = ((Vpk[2][16][2]*c17)-(Vpk[2][14][1]*s17));
        Vpk[2][18][0] = ((Cik[3][2][0]*c18)-(Cik[3][2][2]*s18));
        Vpk[2][18][1] = Cik[3][2][1];
        Vpk[2][18][2] = ((Cik[3][2][0]*s18)+(Cik[3][2][2]*c18));
        Vpk[2][19][0] = Vpk[2][18][0];
        Vpk[2][19][1] = ((Cik[3][2][1]*c19)+(Vpk[2][18][2]*s19));
        Vpk[2][19][2] = ((Vpk[2][18][2]*c19)-(Cik[3][2][1]*s19));
        Vpk[2][20][0] = ((Vpk[2][18][0]*c20)-(Vpk[2][19][2]*s20));
        Vpk[2][20][1] = Vpk[2][19][1];
        Vpk[2][20][2] = ((Vpk[2][18][0]*s20)+(Vpk[2][19][2]*c20));
        Vpk[2][21][0] = ((Vpk[2][19][1]*s21)+(Vpk[2][20][0]*c21));
        Vpk[2][21][1] = ((Vpk[2][19][1]*c21)-(Vpk[2][20][0]*s21));
        Vpk[2][21][2] = Vpk[2][20][2];
        Vpk[2][22][0] = ((Cik[3][2][0]*c22)-(Cik[3][2][2]*s22));
        Vpk[2][22][1] = Cik[3][2][1];
        Vpk[2][22][2] = ((Cik[3][2][0]*s22)+(Cik[3][2][2]*c22));
        Vpk[2][23][0] = Vpk[2][22][0];
        Vpk[2][23][1] = ((Cik[3][2][1]*c23)+(Vpk[2][22][2]*s23));
        Vpk[2][23][2] = ((Vpk[2][22][2]*c23)-(Cik[3][2][1]*s23));
        Vpk[2][24][0] = ((Vpk[2][22][0]*c24)-(Vpk[2][23][2]*s24));
        Vpk[2][24][1] = Vpk[2][23][1];
        Vpk[2][24][2] = ((Vpk[2][22][0]*s24)+(Vpk[2][23][2]*c24));
        Vpk[2][25][0] = ((Vpk[2][23][1]*s25)+(Vpk[2][24][0]*c25));
        Vpk[2][25][1] = ((Vpk[2][23][1]*c25)-(Vpk[2][24][0]*s25));
        Vpk[2][25][2] = Vpk[2][24][2];
        Vpk[3][5][1] = rk[0][2];
        Vpk[3][5][2] = -rk[0][1];
        VWri[3][6][1] = (rk[0][2]-ri[1][2]);
        VWri[3][6][2] = (ri[1][1]-rk[0][1]);
        Vpk[3][6][0] = ((rk[1][2]*s6)+(VWri[3][6][1]*s6));
        Vpk[3][6][1] = ((rk[1][2]*c6)+(VWri[3][6][1]*c6));
        Vpk[3][6][2] = (VWri[3][6][2]-((rk[1][0]*s6)+(rk[1][1]*c6)));
        VWri[3][7][0] = (Vpk[3][6][0]-(ri[2][2]*s6));
        VWri[3][7][1] = (Vpk[3][6][1]-(ri[2][2]*c6));
        VWri[3][7][2] = (Vpk[3][6][2]+((ri[2][0]*s6)+(ri[2][1]*c6)));
        Vpk[3][7][0] = (((rk[2][1]*Wpk[3][7][2])+(rk[2][2]*s6))+((VWri[3][7][0]*
          c7)-(VWri[3][7][2]*s7)));
        Vpk[3][7][1] = (VWri[3][7][1]+((rk[2][2]*Wpk[3][7][0])-(rk[2][0]*
          Wpk[3][7][2])));
        Vpk[3][7][2] = (((VWri[3][7][0]*s7)+(VWri[3][7][2]*c7))-((rk[2][0]*s6)+(
          rk[2][1]*Wpk[3][7][0])));
        VWri[3][8][0] = (Vpk[3][7][0]-((ri[3][1]*Wpk[3][7][2])+(ri[3][2]*s6)));
        VWri[3][8][1] = (Vpk[3][7][1]+((ri[3][0]*Wpk[3][7][2])-(ri[3][2]*
          Wpk[3][7][0])));
        VWri[3][8][2] = (Vpk[3][7][2]+((ri[3][0]*s6)+(ri[3][1]*Wpk[3][7][0])));
        Vpk[3][8][0] = (VWri[3][8][0]+((rk[3][1]*Wpk[3][8][2])-(rk[3][2]*
          Wpk[3][8][1])));
        Vpk[3][8][1] = (((rk[3][2]*Wpk[3][7][0])-(rk[3][0]*Wpk[3][8][2]))+((
          VWri[3][8][1]*c8)+(VWri[3][8][2]*s8)));
        Vpk[3][8][2] = (((rk[3][0]*Wpk[3][8][1])-(rk[3][1]*Wpk[3][7][0]))+((
          VWri[3][8][2]*c8)-(VWri[3][8][1]*s8)));
        VWri[3][9][0] = (Vpk[3][8][0]+((ri[4][2]*Wpk[3][8][1])-(ri[4][1]*
          Wpk[3][8][2])));
        VWri[3][9][1] = (Vpk[3][8][1]+((ri[4][0]*Wpk[3][8][2])-(ri[4][2]*
          Wpk[3][7][0])));
        VWri[3][9][2] = (Vpk[3][8][2]+((ri[4][1]*Wpk[3][7][0])-(ri[4][0]*
          Wpk[3][8][1])));
        Vpk[3][9][0] = (((rk[4][1]*Wpk[3][9][2])-(rk[4][2]*Wpk[3][8][1]))+((
          VWri[3][9][0]*c9)-(VWri[3][9][2]*s9)));
        Vpk[3][9][1] = (VWri[3][9][1]+((rk[4][2]*Wpk[3][9][0])-(rk[4][0]*
          Wpk[3][9][2])));
        Vpk[3][9][2] = (((rk[4][0]*Wpk[3][8][1])-(rk[4][1]*Wpk[3][9][0]))+((
          VWri[3][9][0]*s9)+(VWri[3][9][2]*c9)));
        VWri[3][10][0] = (Vpk[3][9][0]+((ri[5][2]*Wpk[3][8][1])-(ri[5][1]*
          Wpk[3][9][2])));
        VWri[3][10][1] = (Vpk[3][9][1]+((ri[5][0]*Wpk[3][9][2])-(ri[5][2]*
          Wpk[3][9][0])));
        VWri[3][10][2] = (Vpk[3][9][2]+((ri[5][1]*Wpk[3][9][0])-(ri[5][0]*
          Wpk[3][8][1])));
        Vpk[3][10][0] = (((rk[5][1]*Wpk[3][10][2])-(rk[5][2]*Wpk[3][8][1]))+((
          VWri[3][10][0]*c10)-(VWri[3][10][2]*s10)));
        Vpk[3][10][1] = (VWri[3][10][1]+((rk[5][2]*Wpk[3][10][0])-(rk[5][0]*
          Wpk[3][10][2])));
        Vpk[3][10][2] = (((rk[5][0]*Wpk[3][8][1])-(rk[5][1]*Wpk[3][10][0]))+((
          VWri[3][10][0]*s10)+(VWri[3][10][2]*c10)));
        VWri[3][11][0] = (Vpk[3][10][0]+((ri[6][2]*Wpk[3][8][1])-(ri[6][1]*
          Wpk[3][10][2])));
        VWri[3][11][1] = (Vpk[3][10][1]+((ri[6][0]*Wpk[3][10][2])-(ri[6][2]*
          Wpk[3][10][0])));
        VWri[3][11][2] = (Vpk[3][10][2]+((ri[6][1]*Wpk[3][10][0])-(ri[6][0]*
          Wpk[3][8][1])));
        Vpk[3][11][0] = (VWri[3][11][0]+((rk[6][1]*Wpk[3][11][2])-(rk[6][2]*
          Wpk[3][11][1])));
        Vpk[3][11][1] = (((rk[6][2]*Wpk[3][10][0])-(rk[6][0]*Wpk[3][11][2]))+((
          VWri[3][11][1]*c11)+(VWri[3][11][2]*s11)));
        Vpk[3][11][2] = (((rk[6][0]*Wpk[3][11][1])-(rk[6][1]*Wpk[3][10][0]))+((
          VWri[3][11][2]*c11)-(VWri[3][11][1]*s11)));
        VWri[3][12][1] = (rk[0][2]-ri[7][2]);
        VWri[3][12][2] = (ri[7][1]-rk[0][1]);
        Vpk[3][12][0] = ((rk[7][2]*s12)+(VWri[3][12][1]*s12));
        Vpk[3][12][1] = ((rk[7][2]*c12)+(VWri[3][12][1]*c12));
        Vpk[3][12][2] = (VWri[3][12][2]-((rk[7][0]*s12)+(rk[7][1]*c12)));
        VWri[3][13][0] = (Vpk[3][12][0]-(ri[8][2]*s12));
        VWri[3][13][1] = (Vpk[3][12][1]-(ri[8][2]*c12));
        VWri[3][13][2] = (Vpk[3][12][2]+((ri[8][0]*s12)+(ri[8][1]*c12)));
        Vpk[3][13][0] = (((rk[8][1]*Wpk[3][13][2])+(rk[8][2]*s12))+((
          VWri[3][13][0]*c13)-(VWri[3][13][2]*s13)));
        Vpk[3][13][1] = (VWri[3][13][1]+((rk[8][2]*Wpk[3][13][0])-(rk[8][0]*
          Wpk[3][13][2])));
        Vpk[3][13][2] = (((VWri[3][13][0]*s13)+(VWri[3][13][2]*c13))-((rk[8][0]*
          s12)+(rk[8][1]*Wpk[3][13][0])));
        VWri[3][14][0] = (Vpk[3][13][0]-((ri[9][1]*Wpk[3][13][2])+(ri[9][2]*s12)
          ));
        VWri[3][14][1] = (Vpk[3][13][1]+((ri[9][0]*Wpk[3][13][2])-(ri[9][2]*
          Wpk[3][13][0])));
        VWri[3][14][2] = (Vpk[3][13][2]+((ri[9][0]*s12)+(ri[9][1]*Wpk[3][13][0])
          ));
        Vpk[3][14][0] = (VWri[3][14][0]+((rk[9][1]*Wpk[3][14][2])-(rk[9][2]*
          Wpk[3][14][1])));
        Vpk[3][14][1] = (((rk[9][2]*Wpk[3][13][0])-(rk[9][0]*Wpk[3][14][2]))+((
          VWri[3][14][1]*c14)+(VWri[3][14][2]*s14)));
        Vpk[3][14][2] = (((rk[9][0]*Wpk[3][14][1])-(rk[9][1]*Wpk[3][13][0]))+((
          VWri[3][14][2]*c14)-(VWri[3][14][1]*s14)));
        VWri[3][15][0] = (Vpk[3][14][0]+((ri[10][2]*Wpk[3][14][1])-(ri[10][1]*
          Wpk[3][14][2])));
        VWri[3][15][1] = (Vpk[3][14][1]+((ri[10][0]*Wpk[3][14][2])-(ri[10][2]*
          Wpk[3][13][0])));
        VWri[3][15][2] = (Vpk[3][14][2]+((ri[10][1]*Wpk[3][13][0])-(ri[10][0]*
          Wpk[3][14][1])));
        Vpk[3][15][0] = (((rk[10][1]*Wpk[3][15][2])-(rk[10][2]*Wpk[3][14][1]))+(
          (VWri[3][15][0]*c15)-(VWri[3][15][2]*s15)));
        Vpk[3][15][1] = (VWri[3][15][1]+((rk[10][2]*Wpk[3][15][0])-(rk[10][0]*
          Wpk[3][15][2])));
        Vpk[3][15][2] = (((rk[10][0]*Wpk[3][14][1])-(rk[10][1]*Wpk[3][15][0]))+(
          (VWri[3][15][0]*s15)+(VWri[3][15][2]*c15)));
        VWri[3][16][0] = (Vpk[3][15][0]+((ri[11][2]*Wpk[3][14][1])-(ri[11][1]*
          Wpk[3][15][2])));
        VWri[3][16][1] = (Vpk[3][15][1]+((ri[11][0]*Wpk[3][15][2])-(ri[11][2]*
          Wpk[3][15][0])));
        VWri[3][16][2] = (Vpk[3][15][2]+((ri[11][1]*Wpk[3][15][0])-(ri[11][0]*
          Wpk[3][14][1])));
        Vpk[3][16][0] = (((rk[11][1]*Wpk[3][16][2])-(rk[11][2]*Wpk[3][14][1]))+(
          (VWri[3][16][0]*c16)-(VWri[3][16][2]*s16)));
        Vpk[3][16][1] = (VWri[3][16][1]+((rk[11][2]*Wpk[3][16][0])-(rk[11][0]*
          Wpk[3][16][2])));
        Vpk[3][16][2] = (((rk[11][0]*Wpk[3][14][1])-(rk[11][1]*Wpk[3][16][0]))+(
          (VWri[3][16][0]*s16)+(VWri[3][16][2]*c16)));
        VWri[3][17][0] = (Vpk[3][16][0]+((ri[12][2]*Wpk[3][14][1])-(ri[12][1]*
          Wpk[3][16][2])));
        VWri[3][17][1] = (Vpk[3][16][1]+((ri[12][0]*Wpk[3][16][2])-(ri[12][2]*
          Wpk[3][16][0])));
        VWri[3][17][2] = (Vpk[3][16][2]+((ri[12][1]*Wpk[3][16][0])-(ri[12][0]*
          Wpk[3][14][1])));
        Vpk[3][17][0] = (VWri[3][17][0]+((rk[12][1]*Wpk[3][17][2])-(rk[12][2]*
          Wpk[3][17][1])));
        Vpk[3][17][1] = (((rk[12][2]*Wpk[3][16][0])-(rk[12][0]*Wpk[3][17][2]))+(
          (VWri[3][17][1]*c17)+(VWri[3][17][2]*s17)));
        Vpk[3][17][2] = (((rk[12][0]*Wpk[3][17][1])-(rk[12][1]*Wpk[3][16][0]))+(
          (VWri[3][17][2]*c17)-(VWri[3][17][1]*s17)));
        VWri[3][18][1] = (rk[0][2]-ri[13][2]);
        VWri[3][18][2] = (ri[13][1]-rk[0][1]);
        Vpk[3][18][0] = ((rk[13][1]*s18)-(VWri[3][18][2]*s18));
        Vpk[3][18][1] = (VWri[3][18][1]+((rk[13][2]*c18)-(rk[13][0]*s18)));
        Vpk[3][18][2] = ((VWri[3][18][2]*c18)-(rk[13][1]*c18));
        VWri[3][19][0] = (Vpk[3][18][0]-(ri[14][1]*s18));
        VWri[3][19][1] = (Vpk[3][18][1]+((ri[14][0]*s18)-(ri[14][2]*c18)));
        VWri[3][19][2] = (Vpk[3][18][2]+(ri[14][1]*c18));
        Vpk[3][19][0] = (VWri[3][19][0]+((rk[14][1]*Wpk[3][19][2])-(rk[14][2]*
          Wpk[3][19][1])));
        Vpk[3][19][1] = (((rk[14][2]*c18)-(rk[14][0]*Wpk[3][19][2]))+((
          VWri[3][19][1]*c19)+(VWri[3][19][2]*s19)));
        Vpk[3][19][2] = (((rk[14][0]*Wpk[3][19][1])-(rk[14][1]*c18))+((
          VWri[3][19][2]*c19)-(VWri[3][19][1]*s19)));
        VWri[3][20][0] = (Vpk[3][19][0]+((ri[15][2]*Wpk[3][19][1])-(ri[15][1]*
          Wpk[3][19][2])));
        VWri[3][20][1] = (Vpk[3][19][1]+((ri[15][0]*Wpk[3][19][2])-(ri[15][2]*
          c18)));
        VWri[3][20][2] = (Vpk[3][19][2]+((ri[15][1]*c18)-(ri[15][0]*
          Wpk[3][19][1])));
        Vpk[3][20][0] = (((rk[15][1]*Wpk[3][20][2])-(rk[15][2]*Wpk[3][19][1]))+(
          (VWri[3][20][0]*c20)-(VWri[3][20][2]*s20)));
        Vpk[3][20][1] = (VWri[3][20][1]+((rk[15][2]*Wpk[3][20][0])-(rk[15][0]*
          Wpk[3][20][2])));
        Vpk[3][20][2] = (((rk[15][0]*Wpk[3][19][1])-(rk[15][1]*Wpk[3][20][0]))+(
          (VWri[3][20][0]*s20)+(VWri[3][20][2]*c20)));
        VWri[3][21][0] = (Vpk[3][20][0]+((ri[16][2]*Wpk[3][19][1])-(ri[16][1]*
          Wpk[3][20][2])));
        VWri[3][21][1] = (Vpk[3][20][1]+((ri[16][0]*Wpk[3][20][2])-(ri[16][2]*
          Wpk[3][20][0])));
        VWri[3][21][2] = (Vpk[3][20][2]+((ri[16][1]*Wpk[3][20][0])-(ri[16][0]*
          Wpk[3][19][1])));
        Vpk[3][21][0] = (((rk[16][1]*Wpk[3][20][2])-(rk[16][2]*Wpk[3][21][1]))+(
          (VWri[3][21][0]*c21)+(VWri[3][21][1]*s21)));
        Vpk[3][21][1] = (((rk[16][2]*Wpk[3][21][0])-(rk[16][0]*Wpk[3][20][2]))+(
          (VWri[3][21][1]*c21)-(VWri[3][21][0]*s21)));
        Vpk[3][21][2] = (VWri[3][21][2]+((rk[16][0]*Wpk[3][21][1])-(rk[16][1]*
          Wpk[3][21][0])));
        VWri[3][22][1] = (rk[0][2]-ri[17][2]);
        VWri[3][22][2] = (ri[17][1]-rk[0][1]);
        Vpk[3][22][0] = ((rk[17][1]*s22)-(VWri[3][22][2]*s22));
        Vpk[3][22][1] = (VWri[3][22][1]+((rk[17][2]*c22)-(rk[17][0]*s22)));
        Vpk[3][22][2] = ((VWri[3][22][2]*c22)-(rk[17][1]*c22));
        VWri[3][23][0] = (Vpk[3][22][0]-(ri[18][1]*s22));
        VWri[3][23][1] = (Vpk[3][22][1]+((ri[18][0]*s22)-(ri[18][2]*c22)));
        VWri[3][23][2] = (Vpk[3][22][2]+(ri[18][1]*c22));
        Vpk[3][23][0] = (VWri[3][23][0]+((rk[18][1]*Wpk[3][23][2])-(rk[18][2]*
          Wpk[3][23][1])));
        Vpk[3][23][1] = (((rk[18][2]*c22)-(rk[18][0]*Wpk[3][23][2]))+((
          VWri[3][23][1]*c23)+(VWri[3][23][2]*s23)));
        Vpk[3][23][2] = (((rk[18][0]*Wpk[3][23][1])-(rk[18][1]*c22))+((
          VWri[3][23][2]*c23)-(VWri[3][23][1]*s23)));
        VWri[3][24][0] = (Vpk[3][23][0]+((ri[19][2]*Wpk[3][23][1])-(ri[19][1]*
          Wpk[3][23][2])));
        VWri[3][24][1] = (Vpk[3][23][1]+((ri[19][0]*Wpk[3][23][2])-(ri[19][2]*
          c22)));
        VWri[3][24][2] = (Vpk[3][23][2]+((ri[19][1]*c22)-(ri[19][0]*
          Wpk[3][23][1])));
        Vpk[3][24][0] = (((rk[19][1]*Wpk[3][24][2])-(rk[19][2]*Wpk[3][23][1]))+(
          (VWri[3][24][0]*c24)-(VWri[3][24][2]*s24)));
        Vpk[3][24][1] = (VWri[3][24][1]+((rk[19][2]*Wpk[3][24][0])-(rk[19][0]*
          Wpk[3][24][2])));
        Vpk[3][24][2] = (((rk[19][0]*Wpk[3][23][1])-(rk[19][1]*Wpk[3][24][0]))+(
          (VWri[3][24][0]*s24)+(VWri[3][24][2]*c24)));
        VWri[3][25][0] = (Vpk[3][24][0]+((ri[20][2]*Wpk[3][23][1])-(ri[20][1]*
          Wpk[3][24][2])));
        VWri[3][25][1] = (Vpk[3][24][1]+((ri[20][0]*Wpk[3][24][2])-(ri[20][2]*
          Wpk[3][24][0])));
        VWri[3][25][2] = (Vpk[3][24][2]+((ri[20][1]*Wpk[3][24][0])-(ri[20][0]*
          Wpk[3][23][1])));
        Vpk[3][25][0] = (((rk[20][1]*Wpk[3][24][2])-(rk[20][2]*Wpk[3][25][1]))+(
          (VWri[3][25][0]*c25)+(VWri[3][25][1]*s25)));
        Vpk[3][25][1] = (((rk[20][2]*Wpk[3][25][0])-(rk[20][0]*Wpk[3][24][2]))+(
          (VWri[3][25][1]*c25)-(VWri[3][25][0]*s25)));
        Vpk[3][25][2] = (VWri[3][25][2]+((rk[20][0]*Wpk[3][25][1])-(rk[20][1]*
          Wpk[3][25][0])));
        Vpk[4][5][0] = -rk[0][2];
        Vpk[4][5][2] = rk[0][0];
        VWri[4][6][0] = (ri[1][2]-rk[0][2]);
        VWri[4][6][2] = (rk[0][0]-ri[1][0]);
        Vpk[4][6][0] = ((VWri[4][6][0]*c6)-(rk[1][2]*c6));
        Vpk[4][6][1] = ((rk[1][2]*s6)-(VWri[4][6][0]*s6));
        Vpk[4][6][2] = (VWri[4][6][2]+((rk[1][0]*c6)-(rk[1][1]*s6)));
        VWri[4][7][0] = (Vpk[4][6][0]+(ri[2][2]*c6));
        VWri[4][7][1] = (Vpk[4][6][1]-(ri[2][2]*s6));
        VWri[4][7][2] = (Vpk[4][6][2]+((ri[2][1]*s6)-(ri[2][0]*c6)));
        Vpk[4][7][0] = (((rk[2][1]*Wpk[4][7][2])-(rk[2][2]*c6))+((VWri[4][7][0]*
          c7)-(VWri[4][7][2]*s7)));
        Vpk[4][7][1] = (VWri[4][7][1]+((rk[2][2]*Wpk[4][7][0])-(rk[2][0]*
          Wpk[4][7][2])));
        Vpk[4][7][2] = (((rk[2][0]*c6)-(rk[2][1]*Wpk[4][7][0]))+((VWri[4][7][0]*
          s7)+(VWri[4][7][2]*c7)));
        VWri[4][8][0] = (Vpk[4][7][0]+((ri[3][2]*c6)-(ri[3][1]*Wpk[4][7][2])));
        VWri[4][8][1] = (Vpk[4][7][1]+((ri[3][0]*Wpk[4][7][2])-(ri[3][2]*
          Wpk[4][7][0])));
        VWri[4][8][2] = (Vpk[4][7][2]+((ri[3][1]*Wpk[4][7][0])-(ri[3][0]*c6)));
        Vpk[4][8][0] = (VWri[4][8][0]+((rk[3][1]*Wpk[4][8][2])-(rk[3][2]*
          Wpk[4][8][1])));
        Vpk[4][8][1] = (((rk[3][2]*Wpk[4][7][0])-(rk[3][0]*Wpk[4][8][2]))+((
          VWri[4][8][1]*c8)+(VWri[4][8][2]*s8)));
        Vpk[4][8][2] = (((rk[3][0]*Wpk[4][8][1])-(rk[3][1]*Wpk[4][7][0]))+((
          VWri[4][8][2]*c8)-(VWri[4][8][1]*s8)));
        VWri[4][9][0] = (Vpk[4][8][0]+((ri[4][2]*Wpk[4][8][1])-(ri[4][1]*
          Wpk[4][8][2])));
        VWri[4][9][1] = (Vpk[4][8][1]+((ri[4][0]*Wpk[4][8][2])-(ri[4][2]*
          Wpk[4][7][0])));
        VWri[4][9][2] = (Vpk[4][8][2]+((ri[4][1]*Wpk[4][7][0])-(ri[4][0]*
          Wpk[4][8][1])));
        Vpk[4][9][0] = (((rk[4][1]*Wpk[4][9][2])-(rk[4][2]*Wpk[4][8][1]))+((
          VWri[4][9][0]*c9)-(VWri[4][9][2]*s9)));
        Vpk[4][9][1] = (VWri[4][9][1]+((rk[4][2]*Wpk[4][9][0])-(rk[4][0]*
          Wpk[4][9][2])));
        Vpk[4][9][2] = (((rk[4][0]*Wpk[4][8][1])-(rk[4][1]*Wpk[4][9][0]))+((
          VWri[4][9][0]*s9)+(VWri[4][9][2]*c9)));
        VWri[4][10][0] = (Vpk[4][9][0]+((ri[5][2]*Wpk[4][8][1])-(ri[5][1]*
          Wpk[4][9][2])));
        VWri[4][10][1] = (Vpk[4][9][1]+((ri[5][0]*Wpk[4][9][2])-(ri[5][2]*
          Wpk[4][9][0])));
        VWri[4][10][2] = (Vpk[4][9][2]+((ri[5][1]*Wpk[4][9][0])-(ri[5][0]*
          Wpk[4][8][1])));
        Vpk[4][10][0] = (((rk[5][1]*Wpk[4][10][2])-(rk[5][2]*Wpk[4][8][1]))+((
          VWri[4][10][0]*c10)-(VWri[4][10][2]*s10)));
        Vpk[4][10][1] = (VWri[4][10][1]+((rk[5][2]*Wpk[4][10][0])-(rk[5][0]*
          Wpk[4][10][2])));
        Vpk[4][10][2] = (((rk[5][0]*Wpk[4][8][1])-(rk[5][1]*Wpk[4][10][0]))+((
          VWri[4][10][0]*s10)+(VWri[4][10][2]*c10)));
        VWri[4][11][0] = (Vpk[4][10][0]+((ri[6][2]*Wpk[4][8][1])-(ri[6][1]*
          Wpk[4][10][2])));
        VWri[4][11][1] = (Vpk[4][10][1]+((ri[6][0]*Wpk[4][10][2])-(ri[6][2]*
          Wpk[4][10][0])));
        VWri[4][11][2] = (Vpk[4][10][2]+((ri[6][1]*Wpk[4][10][0])-(ri[6][0]*
          Wpk[4][8][1])));
        Vpk[4][11][0] = (VWri[4][11][0]+((rk[6][1]*Wpk[4][11][2])-(rk[6][2]*
          Wpk[4][11][1])));
        Vpk[4][11][1] = (((rk[6][2]*Wpk[4][10][0])-(rk[6][0]*Wpk[4][11][2]))+((
          VWri[4][11][1]*c11)+(VWri[4][11][2]*s11)));
        Vpk[4][11][2] = (((rk[6][0]*Wpk[4][11][1])-(rk[6][1]*Wpk[4][10][0]))+((
          VWri[4][11][2]*c11)-(VWri[4][11][1]*s11)));
        VWri[4][12][0] = (ri[7][2]-rk[0][2]);
        VWri[4][12][2] = (rk[0][0]-ri[7][0]);
        Vpk[4][12][0] = ((VWri[4][12][0]*c12)-(rk[7][2]*c12));
        Vpk[4][12][1] = ((rk[7][2]*s12)-(VWri[4][12][0]*s12));
        Vpk[4][12][2] = (VWri[4][12][2]+((rk[7][0]*c12)-(rk[7][1]*s12)));
        VWri[4][13][0] = (Vpk[4][12][0]+(ri[8][2]*c12));
        VWri[4][13][1] = (Vpk[4][12][1]-(ri[8][2]*s12));
        VWri[4][13][2] = (Vpk[4][12][2]+((ri[8][1]*s12)-(ri[8][0]*c12)));
        Vpk[4][13][0] = (((rk[8][1]*Wpk[4][13][2])-(rk[8][2]*c12))+((
          VWri[4][13][0]*c13)-(VWri[4][13][2]*s13)));
        Vpk[4][13][1] = (VWri[4][13][1]+((rk[8][2]*Wpk[4][13][0])-(rk[8][0]*
          Wpk[4][13][2])));
        Vpk[4][13][2] = (((rk[8][0]*c12)-(rk[8][1]*Wpk[4][13][0]))+((
          VWri[4][13][0]*s13)+(VWri[4][13][2]*c13)));
        VWri[4][14][0] = (Vpk[4][13][0]+((ri[9][2]*c12)-(ri[9][1]*Wpk[4][13][2])
          ));
        VWri[4][14][1] = (Vpk[4][13][1]+((ri[9][0]*Wpk[4][13][2])-(ri[9][2]*
          Wpk[4][13][0])));
        VWri[4][14][2] = (Vpk[4][13][2]+((ri[9][1]*Wpk[4][13][0])-(ri[9][0]*c12)
          ));
        Vpk[4][14][0] = (VWri[4][14][0]+((rk[9][1]*Wpk[4][14][2])-(rk[9][2]*
          Wpk[4][14][1])));
        Vpk[4][14][1] = (((rk[9][2]*Wpk[4][13][0])-(rk[9][0]*Wpk[4][14][2]))+((
          VWri[4][14][1]*c14)+(VWri[4][14][2]*s14)));
        Vpk[4][14][2] = (((rk[9][0]*Wpk[4][14][1])-(rk[9][1]*Wpk[4][13][0]))+((
          VWri[4][14][2]*c14)-(VWri[4][14][1]*s14)));
        VWri[4][15][0] = (Vpk[4][14][0]+((ri[10][2]*Wpk[4][14][1])-(ri[10][1]*
          Wpk[4][14][2])));
        VWri[4][15][1] = (Vpk[4][14][1]+((ri[10][0]*Wpk[4][14][2])-(ri[10][2]*
          Wpk[4][13][0])));
        VWri[4][15][2] = (Vpk[4][14][2]+((ri[10][1]*Wpk[4][13][0])-(ri[10][0]*
          Wpk[4][14][1])));
        Vpk[4][15][0] = (((rk[10][1]*Wpk[4][15][2])-(rk[10][2]*Wpk[4][14][1]))+(
          (VWri[4][15][0]*c15)-(VWri[4][15][2]*s15)));
        Vpk[4][15][1] = (VWri[4][15][1]+((rk[10][2]*Wpk[4][15][0])-(rk[10][0]*
          Wpk[4][15][2])));
        Vpk[4][15][2] = (((rk[10][0]*Wpk[4][14][1])-(rk[10][1]*Wpk[4][15][0]))+(
          (VWri[4][15][0]*s15)+(VWri[4][15][2]*c15)));
        VWri[4][16][0] = (Vpk[4][15][0]+((ri[11][2]*Wpk[4][14][1])-(ri[11][1]*
          Wpk[4][15][2])));
        VWri[4][16][1] = (Vpk[4][15][1]+((ri[11][0]*Wpk[4][15][2])-(ri[11][2]*
          Wpk[4][15][0])));
        VWri[4][16][2] = (Vpk[4][15][2]+((ri[11][1]*Wpk[4][15][0])-(ri[11][0]*
          Wpk[4][14][1])));
        Vpk[4][16][0] = (((rk[11][1]*Wpk[4][16][2])-(rk[11][2]*Wpk[4][14][1]))+(
          (VWri[4][16][0]*c16)-(VWri[4][16][2]*s16)));
        Vpk[4][16][1] = (VWri[4][16][1]+((rk[11][2]*Wpk[4][16][0])-(rk[11][0]*
          Wpk[4][16][2])));
        Vpk[4][16][2] = (((rk[11][0]*Wpk[4][14][1])-(rk[11][1]*Wpk[4][16][0]))+(
          (VWri[4][16][0]*s16)+(VWri[4][16][2]*c16)));
        VWri[4][17][0] = (Vpk[4][16][0]+((ri[12][2]*Wpk[4][14][1])-(ri[12][1]*
          Wpk[4][16][2])));
        VWri[4][17][1] = (Vpk[4][16][1]+((ri[12][0]*Wpk[4][16][2])-(ri[12][2]*
          Wpk[4][16][0])));
        VWri[4][17][2] = (Vpk[4][16][2]+((ri[12][1]*Wpk[4][16][0])-(ri[12][0]*
          Wpk[4][14][1])));
        Vpk[4][17][0] = (VWri[4][17][0]+((rk[12][1]*Wpk[4][17][2])-(rk[12][2]*
          Wpk[4][17][1])));
        Vpk[4][17][1] = (((rk[12][2]*Wpk[4][16][0])-(rk[12][0]*Wpk[4][17][2]))+(
          (VWri[4][17][1]*c17)+(VWri[4][17][2]*s17)));
        Vpk[4][17][2] = (((rk[12][0]*Wpk[4][17][1])-(rk[12][1]*Wpk[4][16][0]))+(
          (VWri[4][17][2]*c17)-(VWri[4][17][1]*s17)));
        VWri[4][18][0] = (ri[13][2]-rk[0][2]);
        VWri[4][18][2] = (rk[0][0]-ri[13][0]);
        Vpk[4][18][0] = (((VWri[4][18][0]*c18)-(VWri[4][18][2]*s18))-rk[13][2]);
        Vpk[4][18][2] = (rk[13][0]+((VWri[4][18][0]*s18)+(VWri[4][18][2]*c18)));
        VWri[4][19][0] = (ri[14][2]+Vpk[4][18][0]);
        VWri[4][19][2] = (Vpk[4][18][2]-ri[14][0]);
        Vpk[4][19][0] = (VWri[4][19][0]-((rk[14][1]*s19)+(rk[14][2]*c19)));
        Vpk[4][19][1] = ((rk[14][0]*s19)+(VWri[4][19][2]*s19));
        Vpk[4][19][2] = ((rk[14][0]*c19)+(VWri[4][19][2]*c19));
        VWri[4][20][0] = (Vpk[4][19][0]+((ri[15][1]*s19)+(ri[15][2]*c19)));
        VWri[4][20][1] = (Vpk[4][19][1]-(ri[15][0]*s19));
        VWri[4][20][2] = (Vpk[4][19][2]-(ri[15][0]*c19));
        Vpk[4][20][0] = (((rk[15][1]*Wpk[4][20][2])-(rk[15][2]*c19))+((
          VWri[4][20][0]*c20)-(VWri[4][20][2]*s20)));
        Vpk[4][20][1] = (VWri[4][20][1]+((rk[15][2]*Wpk[4][20][0])-(rk[15][0]*
          Wpk[4][20][2])));
        Vpk[4][20][2] = (((rk[15][0]*c19)-(rk[15][1]*Wpk[4][20][0]))+((
          VWri[4][20][0]*s20)+(VWri[4][20][2]*c20)));
        VWri[4][21][0] = (Vpk[4][20][0]+((ri[16][2]*c19)-(ri[16][1]*
          Wpk[4][20][2])));
        VWri[4][21][1] = (Vpk[4][20][1]+((ri[16][0]*Wpk[4][20][2])-(ri[16][2]*
          Wpk[4][20][0])));
        VWri[4][21][2] = (Vpk[4][20][2]+((ri[16][1]*Wpk[4][20][0])-(ri[16][0]*
          c19)));
        Vpk[4][21][0] = (((rk[16][1]*Wpk[4][20][2])-(rk[16][2]*Wpk[4][21][1]))+(
          (VWri[4][21][0]*c21)+(VWri[4][21][1]*s21)));
        Vpk[4][21][1] = (((rk[16][2]*Wpk[4][21][0])-(rk[16][0]*Wpk[4][20][2]))+(
          (VWri[4][21][1]*c21)-(VWri[4][21][0]*s21)));
        Vpk[4][21][2] = (VWri[4][21][2]+((rk[16][0]*Wpk[4][21][1])-(rk[16][1]*
          Wpk[4][21][0])));
        VWri[4][22][0] = (ri[17][2]-rk[0][2]);
        VWri[4][22][2] = (rk[0][0]-ri[17][0]);
        Vpk[4][22][0] = (((VWri[4][22][0]*c22)-(VWri[4][22][2]*s22))-rk[17][2]);
        Vpk[4][22][2] = (rk[17][0]+((VWri[4][22][0]*s22)+(VWri[4][22][2]*c22)));
        VWri[4][23][0] = (ri[18][2]+Vpk[4][22][0]);
        VWri[4][23][2] = (Vpk[4][22][2]-ri[18][0]);
        Vpk[4][23][0] = (VWri[4][23][0]-((rk[18][1]*s23)+(rk[18][2]*c23)));
        Vpk[4][23][1] = ((rk[18][0]*s23)+(VWri[4][23][2]*s23));
        Vpk[4][23][2] = ((rk[18][0]*c23)+(VWri[4][23][2]*c23));
        VWri[4][24][0] = (Vpk[4][23][0]+((ri[19][1]*s23)+(ri[19][2]*c23)));
        VWri[4][24][1] = (Vpk[4][23][1]-(ri[19][0]*s23));
        VWri[4][24][2] = (Vpk[4][23][2]-(ri[19][0]*c23));
        Vpk[4][24][0] = (((rk[19][1]*Wpk[4][24][2])-(rk[19][2]*c23))+((
          VWri[4][24][0]*c24)-(VWri[4][24][2]*s24)));
        Vpk[4][24][1] = (VWri[4][24][1]+((rk[19][2]*Wpk[4][24][0])-(rk[19][0]*
          Wpk[4][24][2])));
        Vpk[4][24][2] = (((rk[19][0]*c23)-(rk[19][1]*Wpk[4][24][0]))+((
          VWri[4][24][0]*s24)+(VWri[4][24][2]*c24)));
        VWri[4][25][0] = (Vpk[4][24][0]+((ri[20][2]*c23)-(ri[20][1]*
          Wpk[4][24][2])));
        VWri[4][25][1] = (Vpk[4][24][1]+((ri[20][0]*Wpk[4][24][2])-(ri[20][2]*
          Wpk[4][24][0])));
        VWri[4][25][2] = (Vpk[4][24][2]+((ri[20][1]*Wpk[4][24][0])-(ri[20][0]*
          c23)));
        Vpk[4][25][0] = (((rk[20][1]*Wpk[4][24][2])-(rk[20][2]*Wpk[4][25][1]))+(
          (VWri[4][25][0]*c25)+(VWri[4][25][1]*s25)));
        Vpk[4][25][1] = (((rk[20][2]*Wpk[4][25][0])-(rk[20][0]*Wpk[4][24][2]))+(
          (VWri[4][25][1]*c25)-(VWri[4][25][0]*s25)));
        Vpk[4][25][2] = (VWri[4][25][2]+((rk[20][0]*Wpk[4][25][1])-(rk[20][1]*
          Wpk[4][25][0])));
        Vpk[5][5][0] = rk[0][1];
        Vpk[5][5][1] = -rk[0][0];
        VWri[5][6][0] = (rk[0][1]-ri[1][1]);
        VWri[5][6][1] = (ri[1][0]-rk[0][0]);
        Vpk[5][6][0] = (rk[1][1]+((VWri[5][6][0]*c6)+(VWri[5][6][1]*s6)));
        Vpk[5][6][1] = (((VWri[5][6][1]*c6)-(VWri[5][6][0]*s6))-rk[1][0]);
        VWri[5][7][0] = (Vpk[5][6][0]-ri[2][1]);
        VWri[5][7][1] = (ri[2][0]+Vpk[5][6][1]);
        Vpk[5][7][0] = ((rk[2][1]*c7)+(VWri[5][7][0]*c7));
        Vpk[5][7][1] = (VWri[5][7][1]-((rk[2][0]*c7)+(rk[2][2]*s7)));
        Vpk[5][7][2] = ((rk[2][1]*s7)+(VWri[5][7][0]*s7));
        VWri[5][8][0] = (Vpk[5][7][0]-(ri[3][1]*c7));
        VWri[5][8][1] = (Vpk[5][7][1]+((ri[3][0]*c7)+(ri[3][2]*s7)));
        VWri[5][8][2] = (Vpk[5][7][2]-(ri[3][1]*s7));
        Vpk[5][8][0] = (VWri[5][8][0]+((rk[3][1]*Wpk[5][8][2])-(rk[3][2]*
          Wpk[5][8][1])));
        Vpk[5][8][1] = (((VWri[5][8][1]*c8)+(VWri[5][8][2]*s8))-((rk[3][0]*
          Wpk[5][8][2])+(rk[3][2]*s7)));
        Vpk[5][8][2] = (((rk[3][0]*Wpk[5][8][1])+(rk[3][1]*s7))+((VWri[5][8][2]*
          c8)-(VWri[5][8][1]*s8)));
        VWri[5][9][0] = (Vpk[5][8][0]+((ri[4][2]*Wpk[5][8][1])-(ri[4][1]*
          Wpk[5][8][2])));
        VWri[5][9][1] = (Vpk[5][8][1]+((ri[4][0]*Wpk[5][8][2])+(ri[4][2]*s7)));
        VWri[5][9][2] = (Vpk[5][8][2]-((ri[4][0]*Wpk[5][8][1])+(ri[4][1]*s7)));
        Vpk[5][9][0] = (((rk[4][1]*Wpk[5][9][2])-(rk[4][2]*Wpk[5][8][1]))+((
          VWri[5][9][0]*c9)-(VWri[5][9][2]*s9)));
        Vpk[5][9][1] = (VWri[5][9][1]+((rk[4][2]*Wpk[5][9][0])-(rk[4][0]*
          Wpk[5][9][2])));
        Vpk[5][9][2] = (((rk[4][0]*Wpk[5][8][1])-(rk[4][1]*Wpk[5][9][0]))+((
          VWri[5][9][0]*s9)+(VWri[5][9][2]*c9)));
        VWri[5][10][0] = (Vpk[5][9][0]+((ri[5][2]*Wpk[5][8][1])-(ri[5][1]*
          Wpk[5][9][2])));
        VWri[5][10][1] = (Vpk[5][9][1]+((ri[5][0]*Wpk[5][9][2])-(ri[5][2]*
          Wpk[5][9][0])));
        VWri[5][10][2] = (Vpk[5][9][2]+((ri[5][1]*Wpk[5][9][0])-(ri[5][0]*
          Wpk[5][8][1])));
        Vpk[5][10][0] = (((rk[5][1]*Wpk[5][10][2])-(rk[5][2]*Wpk[5][8][1]))+((
          VWri[5][10][0]*c10)-(VWri[5][10][2]*s10)));
        Vpk[5][10][1] = (VWri[5][10][1]+((rk[5][2]*Wpk[5][10][0])-(rk[5][0]*
          Wpk[5][10][2])));
        Vpk[5][10][2] = (((rk[5][0]*Wpk[5][8][1])-(rk[5][1]*Wpk[5][10][0]))+((
          VWri[5][10][0]*s10)+(VWri[5][10][2]*c10)));
        VWri[5][11][0] = (Vpk[5][10][0]+((ri[6][2]*Wpk[5][8][1])-(ri[6][1]*
          Wpk[5][10][2])));
        VWri[5][11][1] = (Vpk[5][10][1]+((ri[6][0]*Wpk[5][10][2])-(ri[6][2]*
          Wpk[5][10][0])));
        VWri[5][11][2] = (Vpk[5][10][2]+((ri[6][1]*Wpk[5][10][0])-(ri[6][0]*
          Wpk[5][8][1])));
        Vpk[5][11][0] = (VWri[5][11][0]+((rk[6][1]*Wpk[5][11][2])-(rk[6][2]*
          Wpk[5][11][1])));
        Vpk[5][11][1] = (((rk[6][2]*Wpk[5][10][0])-(rk[6][0]*Wpk[5][11][2]))+((
          VWri[5][11][1]*c11)+(VWri[5][11][2]*s11)));
        Vpk[5][11][2] = (((rk[6][0]*Wpk[5][11][1])-(rk[6][1]*Wpk[5][10][0]))+((
          VWri[5][11][2]*c11)-(VWri[5][11][1]*s11)));
        VWri[5][12][0] = (rk[0][1]-ri[7][1]);
        VWri[5][12][1] = (ri[7][0]-rk[0][0]);
        Vpk[5][12][0] = (rk[7][1]+((VWri[5][12][0]*c12)+(VWri[5][12][1]*s12)));
        Vpk[5][12][1] = (((VWri[5][12][1]*c12)-(VWri[5][12][0]*s12))-rk[7][0]);
        VWri[5][13][0] = (Vpk[5][12][0]-ri[8][1]);
        VWri[5][13][1] = (ri[8][0]+Vpk[5][12][1]);
        Vpk[5][13][0] = ((rk[8][1]*c13)+(VWri[5][13][0]*c13));
        Vpk[5][13][1] = (VWri[5][13][1]-((rk[8][0]*c13)+(rk[8][2]*s13)));
        Vpk[5][13][2] = ((rk[8][1]*s13)+(VWri[5][13][0]*s13));
        VWri[5][14][0] = (Vpk[5][13][0]-(ri[9][1]*c13));
        VWri[5][14][1] = (Vpk[5][13][1]+((ri[9][0]*c13)+(ri[9][2]*s13)));
        VWri[5][14][2] = (Vpk[5][13][2]-(ri[9][1]*s13));
        Vpk[5][14][0] = (VWri[5][14][0]+((rk[9][1]*Wpk[5][14][2])-(rk[9][2]*
          Wpk[5][14][1])));
        Vpk[5][14][1] = (((VWri[5][14][1]*c14)+(VWri[5][14][2]*s14))-((rk[9][0]*
          Wpk[5][14][2])+(rk[9][2]*s13)));
        Vpk[5][14][2] = (((rk[9][0]*Wpk[5][14][1])+(rk[9][1]*s13))+((
          VWri[5][14][2]*c14)-(VWri[5][14][1]*s14)));
        VWri[5][15][0] = (Vpk[5][14][0]+((ri[10][2]*Wpk[5][14][1])-(ri[10][1]*
          Wpk[5][14][2])));
        VWri[5][15][1] = (Vpk[5][14][1]+((ri[10][0]*Wpk[5][14][2])+(ri[10][2]*
          s13)));
        VWri[5][15][2] = (Vpk[5][14][2]-((ri[10][0]*Wpk[5][14][1])+(ri[10][1]*
          s13)));
        Vpk[5][15][0] = (((rk[10][1]*Wpk[5][15][2])-(rk[10][2]*Wpk[5][14][1]))+(
          (VWri[5][15][0]*c15)-(VWri[5][15][2]*s15)));
        Vpk[5][15][1] = (VWri[5][15][1]+((rk[10][2]*Wpk[5][15][0])-(rk[10][0]*
          Wpk[5][15][2])));
        Vpk[5][15][2] = (((rk[10][0]*Wpk[5][14][1])-(rk[10][1]*Wpk[5][15][0]))+(
          (VWri[5][15][0]*s15)+(VWri[5][15][2]*c15)));
        VWri[5][16][0] = (Vpk[5][15][0]+((ri[11][2]*Wpk[5][14][1])-(ri[11][1]*
          Wpk[5][15][2])));
        VWri[5][16][1] = (Vpk[5][15][1]+((ri[11][0]*Wpk[5][15][2])-(ri[11][2]*
          Wpk[5][15][0])));
        VWri[5][16][2] = (Vpk[5][15][2]+((ri[11][1]*Wpk[5][15][0])-(ri[11][0]*
          Wpk[5][14][1])));
        Vpk[5][16][0] = (((rk[11][1]*Wpk[5][16][2])-(rk[11][2]*Wpk[5][14][1]))+(
          (VWri[5][16][0]*c16)-(VWri[5][16][2]*s16)));
        Vpk[5][16][1] = (VWri[5][16][1]+((rk[11][2]*Wpk[5][16][0])-(rk[11][0]*
          Wpk[5][16][2])));
        Vpk[5][16][2] = (((rk[11][0]*Wpk[5][14][1])-(rk[11][1]*Wpk[5][16][0]))+(
          (VWri[5][16][0]*s16)+(VWri[5][16][2]*c16)));
        VWri[5][17][0] = (Vpk[5][16][0]+((ri[12][2]*Wpk[5][14][1])-(ri[12][1]*
          Wpk[5][16][2])));
        VWri[5][17][1] = (Vpk[5][16][1]+((ri[12][0]*Wpk[5][16][2])-(ri[12][2]*
          Wpk[5][16][0])));
        VWri[5][17][2] = (Vpk[5][16][2]+((ri[12][1]*Wpk[5][16][0])-(ri[12][0]*
          Wpk[5][14][1])));
        Vpk[5][17][0] = (VWri[5][17][0]+((rk[12][1]*Wpk[5][17][2])-(rk[12][2]*
          Wpk[5][17][1])));
        Vpk[5][17][1] = (((rk[12][2]*Wpk[5][16][0])-(rk[12][0]*Wpk[5][17][2]))+(
          (VWri[5][17][1]*c17)+(VWri[5][17][2]*s17)));
        Vpk[5][17][2] = (((rk[12][0]*Wpk[5][17][1])-(rk[12][1]*Wpk[5][16][0]))+(
          (VWri[5][17][2]*c17)-(VWri[5][17][1]*s17)));
        VWri[5][18][0] = (rk[0][1]-ri[13][1]);
        VWri[5][18][1] = (ri[13][0]-rk[0][0]);
        Vpk[5][18][0] = ((rk[13][1]*c18)+(VWri[5][18][0]*c18));
        Vpk[5][18][1] = (VWri[5][18][1]-((rk[13][0]*c18)+(rk[13][2]*s18)));
        Vpk[5][18][2] = ((rk[13][1]*s18)+(VWri[5][18][0]*s18));
        VWri[5][19][0] = (Vpk[5][18][0]-(ri[14][1]*c18));
        VWri[5][19][1] = (Vpk[5][18][1]+((ri[14][0]*c18)+(ri[14][2]*s18)));
        VWri[5][19][2] = (Vpk[5][18][2]-(ri[14][1]*s18));
        Vpk[5][19][0] = (VWri[5][19][0]+((rk[14][1]*Wpk[5][19][2])-(rk[14][2]*
          Wpk[5][19][1])));
        Vpk[5][19][1] = (((VWri[5][19][1]*c19)+(VWri[5][19][2]*s19))-((rk[14][0]
          *Wpk[5][19][2])+(rk[14][2]*s18)));
        Vpk[5][19][2] = (((rk[14][0]*Wpk[5][19][1])+(rk[14][1]*s18))+((
          VWri[5][19][2]*c19)-(VWri[5][19][1]*s19)));
        VWri[5][20][0] = (Vpk[5][19][0]+((ri[15][2]*Wpk[5][19][1])-(ri[15][1]*
          Wpk[5][19][2])));
        VWri[5][20][1] = (Vpk[5][19][1]+((ri[15][0]*Wpk[5][19][2])+(ri[15][2]*
          s18)));
        VWri[5][20][2] = (Vpk[5][19][2]-((ri[15][0]*Wpk[5][19][1])+(ri[15][1]*
          s18)));
        Vpk[5][20][0] = (((rk[15][1]*Wpk[5][20][2])-(rk[15][2]*Wpk[5][19][1]))+(
          (VWri[5][20][0]*c20)-(VWri[5][20][2]*s20)));
        Vpk[5][20][1] = (VWri[5][20][1]+((rk[15][2]*Wpk[5][20][0])-(rk[15][0]*
          Wpk[5][20][2])));
        Vpk[5][20][2] = (((rk[15][0]*Wpk[5][19][1])-(rk[15][1]*Wpk[5][20][0]))+(
          (VWri[5][20][0]*s20)+(VWri[5][20][2]*c20)));
        VWri[5][21][0] = (Vpk[5][20][0]+((ri[16][2]*Wpk[5][19][1])-(ri[16][1]*
          Wpk[5][20][2])));
        VWri[5][21][1] = (Vpk[5][20][1]+((ri[16][0]*Wpk[5][20][2])-(ri[16][2]*
          Wpk[5][20][0])));
        VWri[5][21][2] = (Vpk[5][20][2]+((ri[16][1]*Wpk[5][20][0])-(ri[16][0]*
          Wpk[5][19][1])));
        Vpk[5][21][0] = (((rk[16][1]*Wpk[5][20][2])-(rk[16][2]*Wpk[5][21][1]))+(
          (VWri[5][21][0]*c21)+(VWri[5][21][1]*s21)));
        Vpk[5][21][1] = (((rk[16][2]*Wpk[5][21][0])-(rk[16][0]*Wpk[5][20][2]))+(
          (VWri[5][21][1]*c21)-(VWri[5][21][0]*s21)));
        Vpk[5][21][2] = (VWri[5][21][2]+((rk[16][0]*Wpk[5][21][1])-(rk[16][1]*
          Wpk[5][21][0])));
        VWri[5][22][0] = (rk[0][1]-ri[17][1]);
        VWri[5][22][1] = (ri[17][0]-rk[0][0]);
        Vpk[5][22][0] = ((rk[17][1]*c22)+(VWri[5][22][0]*c22));
        Vpk[5][22][1] = (VWri[5][22][1]-((rk[17][0]*c22)+(rk[17][2]*s22)));
        Vpk[5][22][2] = ((rk[17][1]*s22)+(VWri[5][22][0]*s22));
        VWri[5][23][0] = (Vpk[5][22][0]-(ri[18][1]*c22));
        VWri[5][23][1] = (Vpk[5][22][1]+((ri[18][0]*c22)+(ri[18][2]*s22)));
        VWri[5][23][2] = (Vpk[5][22][2]-(ri[18][1]*s22));
        Vpk[5][23][0] = (VWri[5][23][0]+((rk[18][1]*Wpk[5][23][2])-(rk[18][2]*
          Wpk[5][23][1])));
        Vpk[5][23][1] = (((VWri[5][23][1]*c23)+(VWri[5][23][2]*s23))-((rk[18][0]
          *Wpk[5][23][2])+(rk[18][2]*s22)));
        Vpk[5][23][2] = (((rk[18][0]*Wpk[5][23][1])+(rk[18][1]*s22))+((
          VWri[5][23][2]*c23)-(VWri[5][23][1]*s23)));
        VWri[5][24][0] = (Vpk[5][23][0]+((ri[19][2]*Wpk[5][23][1])-(ri[19][1]*
          Wpk[5][23][2])));
        VWri[5][24][1] = (Vpk[5][23][1]+((ri[19][0]*Wpk[5][23][2])+(ri[19][2]*
          s22)));
        VWri[5][24][2] = (Vpk[5][23][2]-((ri[19][0]*Wpk[5][23][1])+(ri[19][1]*
          s22)));
        Vpk[5][24][0] = (((rk[19][1]*Wpk[5][24][2])-(rk[19][2]*Wpk[5][23][1]))+(
          (VWri[5][24][0]*c24)-(VWri[5][24][2]*s24)));
        Vpk[5][24][1] = (VWri[5][24][1]+((rk[19][2]*Wpk[5][24][0])-(rk[19][0]*
          Wpk[5][24][2])));
        Vpk[5][24][2] = (((rk[19][0]*Wpk[5][23][1])-(rk[19][1]*Wpk[5][24][0]))+(
          (VWri[5][24][0]*s24)+(VWri[5][24][2]*c24)));
        VWri[5][25][0] = (Vpk[5][24][0]+((ri[20][2]*Wpk[5][23][1])-(ri[20][1]*
          Wpk[5][24][2])));
        VWri[5][25][1] = (Vpk[5][24][1]+((ri[20][0]*Wpk[5][24][2])-(ri[20][2]*
          Wpk[5][24][0])));
        VWri[5][25][2] = (Vpk[5][24][2]+((ri[20][1]*Wpk[5][24][0])-(ri[20][0]*
          Wpk[5][23][1])));
        Vpk[5][25][0] = (((rk[20][1]*Wpk[5][24][2])-(rk[20][2]*Wpk[5][25][1]))+(
          (VWri[5][25][0]*c25)+(VWri[5][25][1]*s25)));
        Vpk[5][25][1] = (((rk[20][2]*Wpk[5][25][0])-(rk[20][0]*Wpk[5][24][2]))+(
          (VWri[5][25][1]*c25)-(VWri[5][25][0]*s25)));
        Vpk[5][25][2] = (VWri[5][25][2]+((rk[20][0]*Wpk[5][25][1])-(rk[20][1]*
          Wpk[5][25][0])));
        Vpk[6][6][0] = rk[1][1];
        Vpk[6][6][1] = -rk[1][0];
        VWri[6][7][0] = (rk[1][1]-ri[2][1]);
        VWri[6][7][1] = (ri[2][0]-rk[1][0]);
        Vpk[6][7][0] = ((rk[2][1]*c7)+(VWri[6][7][0]*c7));
        Vpk[6][7][1] = (VWri[6][7][1]-((rk[2][0]*c7)+(rk[2][2]*s7)));
        Vpk[6][7][2] = ((rk[2][1]*s7)+(VWri[6][7][0]*s7));
        VWri[6][8][0] = (Vpk[6][7][0]-(ri[3][1]*c7));
        VWri[6][8][1] = (Vpk[6][7][1]+((ri[3][0]*c7)+(ri[3][2]*s7)));
        VWri[6][8][2] = (Vpk[6][7][2]-(ri[3][1]*s7));
        Vpk[6][8][0] = (VWri[6][8][0]+((rk[3][1]*Wpk[6][8][2])-(rk[3][2]*
          Wpk[6][8][1])));
        Vpk[6][8][1] = (((VWri[6][8][1]*c8)+(VWri[6][8][2]*s8))-((rk[3][0]*
          Wpk[6][8][2])+(rk[3][2]*s7)));
        Vpk[6][8][2] = (((rk[3][0]*Wpk[6][8][1])+(rk[3][1]*s7))+((VWri[6][8][2]*
          c8)-(VWri[6][8][1]*s8)));
        VWri[6][9][0] = (Vpk[6][8][0]+((ri[4][2]*Wpk[6][8][1])-(ri[4][1]*
          Wpk[6][8][2])));
        VWri[6][9][1] = (Vpk[6][8][1]+((ri[4][0]*Wpk[6][8][2])+(ri[4][2]*s7)));
        VWri[6][9][2] = (Vpk[6][8][2]-((ri[4][0]*Wpk[6][8][1])+(ri[4][1]*s7)));
        Vpk[6][9][0] = (((rk[4][1]*Wpk[6][9][2])-(rk[4][2]*Wpk[6][8][1]))+((
          VWri[6][9][0]*c9)-(VWri[6][9][2]*s9)));
        Vpk[6][9][1] = (VWri[6][9][1]+((rk[4][2]*Wpk[6][9][0])-(rk[4][0]*
          Wpk[6][9][2])));
        Vpk[6][9][2] = (((rk[4][0]*Wpk[6][8][1])-(rk[4][1]*Wpk[6][9][0]))+((
          VWri[6][9][0]*s9)+(VWri[6][9][2]*c9)));
        VWri[6][10][0] = (Vpk[6][9][0]+((ri[5][2]*Wpk[6][8][1])-(ri[5][1]*
          Wpk[6][9][2])));
        VWri[6][10][1] = (Vpk[6][9][1]+((ri[5][0]*Wpk[6][9][2])-(ri[5][2]*
          Wpk[6][9][0])));
        VWri[6][10][2] = (Vpk[6][9][2]+((ri[5][1]*Wpk[6][9][0])-(ri[5][0]*
          Wpk[6][8][1])));
        Vpk[6][10][0] = (((rk[5][1]*Wpk[6][10][2])-(rk[5][2]*Wpk[6][8][1]))+((
          VWri[6][10][0]*c10)-(VWri[6][10][2]*s10)));
        Vpk[6][10][1] = (VWri[6][10][1]+((rk[5][2]*Wpk[6][10][0])-(rk[5][0]*
          Wpk[6][10][2])));
        Vpk[6][10][2] = (((rk[5][0]*Wpk[6][8][1])-(rk[5][1]*Wpk[6][10][0]))+((
          VWri[6][10][0]*s10)+(VWri[6][10][2]*c10)));
        VWri[6][11][0] = (Vpk[6][10][0]+((ri[6][2]*Wpk[6][8][1])-(ri[6][1]*
          Wpk[6][10][2])));
        VWri[6][11][1] = (Vpk[6][10][1]+((ri[6][0]*Wpk[6][10][2])-(ri[6][2]*
          Wpk[6][10][0])));
        VWri[6][11][2] = (Vpk[6][10][2]+((ri[6][1]*Wpk[6][10][0])-(ri[6][0]*
          Wpk[6][8][1])));
        Vpk[6][11][0] = (VWri[6][11][0]+((rk[6][1]*Wpk[6][11][2])-(rk[6][2]*
          Wpk[6][11][1])));
        Vpk[6][11][1] = (((rk[6][2]*Wpk[6][10][0])-(rk[6][0]*Wpk[6][11][2]))+((
          VWri[6][11][1]*c11)+(VWri[6][11][2]*s11)));
        Vpk[6][11][2] = (((rk[6][0]*Wpk[6][11][1])-(rk[6][1]*Wpk[6][10][0]))+((
          VWri[6][11][2]*c11)-(VWri[6][11][1]*s11)));
        Vpk[7][7][0] = -rk[2][2];
        Vpk[7][7][2] = rk[2][0];
        VWri[7][8][0] = (ri[3][2]-rk[2][2]);
        VWri[7][8][2] = (rk[2][0]-ri[3][0]);
        Vpk[7][8][0] = (VWri[7][8][0]-((rk[3][1]*s8)+(rk[3][2]*c8)));
        Vpk[7][8][1] = ((rk[3][0]*s8)+(VWri[7][8][2]*s8));
        Vpk[7][8][2] = ((rk[3][0]*c8)+(VWri[7][8][2]*c8));
        VWri[7][9][0] = (Vpk[7][8][0]+((ri[4][1]*s8)+(ri[4][2]*c8)));
        VWri[7][9][1] = (Vpk[7][8][1]-(ri[4][0]*s8));
        VWri[7][9][2] = (Vpk[7][8][2]-(ri[4][0]*c8));
        Vpk[7][9][0] = (((rk[4][1]*Wpk[7][9][2])-(rk[4][2]*c8))+((VWri[7][9][0]*
          c9)-(VWri[7][9][2]*s9)));
        Vpk[7][9][1] = (VWri[7][9][1]+((rk[4][2]*Wpk[7][9][0])-(rk[4][0]*
          Wpk[7][9][2])));
        Vpk[7][9][2] = (((rk[4][0]*c8)-(rk[4][1]*Wpk[7][9][0]))+((VWri[7][9][0]*
          s9)+(VWri[7][9][2]*c9)));
        VWri[7][10][0] = (Vpk[7][9][0]+((ri[5][2]*c8)-(ri[5][1]*Wpk[7][9][2])));
        VWri[7][10][1] = (Vpk[7][9][1]+((ri[5][0]*Wpk[7][9][2])-(ri[5][2]*
          Wpk[7][9][0])));
        VWri[7][10][2] = (Vpk[7][9][2]+((ri[5][1]*Wpk[7][9][0])-(ri[5][0]*c8)));
        Vpk[7][10][0] = (((rk[5][1]*Wpk[7][10][2])-(rk[5][2]*c8))+((
          VWri[7][10][0]*c10)-(VWri[7][10][2]*s10)));
        Vpk[7][10][1] = (VWri[7][10][1]+((rk[5][2]*Wpk[7][10][0])-(rk[5][0]*
          Wpk[7][10][2])));
        Vpk[7][10][2] = (((rk[5][0]*c8)-(rk[5][1]*Wpk[7][10][0]))+((
          VWri[7][10][0]*s10)+(VWri[7][10][2]*c10)));
        VWri[7][11][0] = (Vpk[7][10][0]+((ri[6][2]*c8)-(ri[6][1]*Wpk[7][10][2]))
          );
        VWri[7][11][1] = (Vpk[7][10][1]+((ri[6][0]*Wpk[7][10][2])-(ri[6][2]*
          Wpk[7][10][0])));
        VWri[7][11][2] = (Vpk[7][10][2]+((ri[6][1]*Wpk[7][10][0])-(ri[6][0]*c8))
          );
        Vpk[7][11][0] = (VWri[7][11][0]+((rk[6][1]*Wpk[7][11][2])-(rk[6][2]*
          Wpk[7][11][1])));
        Vpk[7][11][1] = (((rk[6][2]*Wpk[7][10][0])-(rk[6][0]*Wpk[7][11][2]))+((
          VWri[7][11][1]*c11)+(VWri[7][11][2]*s11)));
        Vpk[7][11][2] = (((rk[6][0]*Wpk[7][11][1])-(rk[6][1]*Wpk[7][10][0]))+((
          VWri[7][11][2]*c11)-(VWri[7][11][1]*s11)));
        Vpk[8][8][1] = rk[3][2];
        Vpk[8][8][2] = -rk[3][1];
        VWri[8][9][1] = (rk[3][2]-ri[4][2]);
        VWri[8][9][2] = (ri[4][1]-rk[3][1]);
        Vpk[8][9][0] = ((rk[4][1]*s9)-(VWri[8][9][2]*s9));
        Vpk[8][9][1] = (VWri[8][9][1]+((rk[4][2]*c9)-(rk[4][0]*s9)));
        Vpk[8][9][2] = ((VWri[8][9][2]*c9)-(rk[4][1]*c9));
        VWri[8][10][0] = (Vpk[8][9][0]-(ri[5][1]*s9));
        VWri[8][10][1] = (Vpk[8][9][1]+((ri[5][0]*s9)-(ri[5][2]*c9)));
        VWri[8][10][2] = (Vpk[8][9][2]+(ri[5][1]*c9));
        Vpk[8][10][0] = ((rk[5][1]*Wpk[8][10][2])+((VWri[8][10][0]*c10)-(
          VWri[8][10][2]*s10)));
        Vpk[8][10][1] = (VWri[8][10][1]+((rk[5][2]*Wpk[8][10][0])-(rk[5][0]*
          Wpk[8][10][2])));
        Vpk[8][10][2] = (((VWri[8][10][0]*s10)+(VWri[8][10][2]*c10))-(rk[5][1]*
          Wpk[8][10][0]));
        VWri[8][11][0] = (Vpk[8][10][0]-(ri[6][1]*Wpk[8][10][2]));
        VWri[8][11][1] = (Vpk[8][10][1]+((ri[6][0]*Wpk[8][10][2])-(ri[6][2]*
          Wpk[8][10][0])));
        VWri[8][11][2] = (Vpk[8][10][2]+(ri[6][1]*Wpk[8][10][0]));
        Vpk[8][11][0] = (VWri[8][11][0]+((rk[6][1]*Wpk[8][11][2])-(rk[6][2]*
          Wpk[8][11][1])));
        Vpk[8][11][1] = (((rk[6][2]*Wpk[8][10][0])-(rk[6][0]*Wpk[8][11][2]))+((
          VWri[8][11][1]*c11)+(VWri[8][11][2]*s11)));
        Vpk[8][11][2] = (((rk[6][0]*Wpk[8][11][1])-(rk[6][1]*Wpk[8][10][0]))+((
          VWri[8][11][2]*c11)-(VWri[8][11][1]*s11)));
        Vpk[9][9][0] = -rk[4][2];
        Vpk[9][9][2] = rk[4][0];
        VWri[9][10][0] = (ri[5][2]-rk[4][2]);
        VWri[9][10][2] = (rk[4][0]-ri[5][0]);
        Vpk[9][10][0] = (((VWri[9][10][0]*c10)-(VWri[9][10][2]*s10))-rk[5][2]);
        Vpk[9][10][2] = (rk[5][0]+((VWri[9][10][0]*s10)+(VWri[9][10][2]*c10)));
        VWri[9][11][0] = (ri[6][2]+Vpk[9][10][0]);
        VWri[9][11][2] = (Vpk[9][10][2]-ri[6][0]);
        Vpk[9][11][0] = (VWri[9][11][0]-((rk[6][1]*s11)+(rk[6][2]*c11)));
        Vpk[9][11][1] = ((rk[6][0]*s11)+(VWri[9][11][2]*s11));
        Vpk[9][11][2] = ((rk[6][0]*c11)+(VWri[9][11][2]*c11));
        Vpk[10][10][0] = -rk[5][2];
        Vpk[10][10][2] = rk[5][0];
        VWri[10][11][0] = (ri[6][2]-rk[5][2]);
        VWri[10][11][2] = (rk[5][0]-ri[6][0]);
        Vpk[10][11][0] = (VWri[10][11][0]-((rk[6][1]*s11)+(rk[6][2]*c11)));
        Vpk[10][11][1] = ((rk[6][0]*s11)+(VWri[10][11][2]*s11));
        Vpk[10][11][2] = ((rk[6][0]*c11)+(VWri[10][11][2]*c11));
        Vpk[11][11][1] = rk[6][2];
        Vpk[11][11][2] = -rk[6][1];
        Vpk[12][12][0] = rk[7][1];
        Vpk[12][12][1] = -rk[7][0];
        VWri[12][13][0] = (rk[7][1]-ri[8][1]);
        VWri[12][13][1] = (ri[8][0]-rk[7][0]);
        Vpk[12][13][0] = ((rk[8][1]*c13)+(VWri[12][13][0]*c13));
        Vpk[12][13][1] = (VWri[12][13][1]-((rk[8][0]*c13)+(rk[8][2]*s13)));
        Vpk[12][13][2] = ((rk[8][1]*s13)+(VWri[12][13][0]*s13));
        VWri[12][14][0] = (Vpk[12][13][0]-(ri[9][1]*c13));
        VWri[12][14][1] = (Vpk[12][13][1]+((ri[9][0]*c13)+(ri[9][2]*s13)));
        VWri[12][14][2] = (Vpk[12][13][2]-(ri[9][1]*s13));
        Vpk[12][14][0] = (VWri[12][14][0]+((rk[9][1]*Wpk[12][14][2])-(rk[9][2]*
          Wpk[12][14][1])));
        Vpk[12][14][1] = (((VWri[12][14][1]*c14)+(VWri[12][14][2]*s14))-((
          rk[9][0]*Wpk[12][14][2])+(rk[9][2]*s13)));
        Vpk[12][14][2] = (((rk[9][0]*Wpk[12][14][1])+(rk[9][1]*s13))+((
          VWri[12][14][2]*c14)-(VWri[12][14][1]*s14)));
        VWri[12][15][0] = (Vpk[12][14][0]+((ri[10][2]*Wpk[12][14][1])-(ri[10][1]
          *Wpk[12][14][2])));
        VWri[12][15][1] = (Vpk[12][14][1]+((ri[10][0]*Wpk[12][14][2])+(ri[10][2]
          *s13)));
        VWri[12][15][2] = (Vpk[12][14][2]-((ri[10][0]*Wpk[12][14][1])+(ri[10][1]
          *s13)));
        Vpk[12][15][0] = (((rk[10][1]*Wpk[12][15][2])-(rk[10][2]*Wpk[12][14][1])
          )+((VWri[12][15][0]*c15)-(VWri[12][15][2]*s15)));
        Vpk[12][15][1] = (VWri[12][15][1]+((rk[10][2]*Wpk[12][15][0])-(rk[10][0]
          *Wpk[12][15][2])));
        Vpk[12][15][2] = (((rk[10][0]*Wpk[12][14][1])-(rk[10][1]*Wpk[12][15][0])
          )+((VWri[12][15][0]*s15)+(VWri[12][15][2]*c15)));
        VWri[12][16][0] = (Vpk[12][15][0]+((ri[11][2]*Wpk[12][14][1])-(ri[11][1]
          *Wpk[12][15][2])));
        VWri[12][16][1] = (Vpk[12][15][1]+((ri[11][0]*Wpk[12][15][2])-(ri[11][2]
          *Wpk[12][15][0])));
        VWri[12][16][2] = (Vpk[12][15][2]+((ri[11][1]*Wpk[12][15][0])-(ri[11][0]
          *Wpk[12][14][1])));
        Vpk[12][16][0] = (((rk[11][1]*Wpk[12][16][2])-(rk[11][2]*Wpk[12][14][1])
          )+((VWri[12][16][0]*c16)-(VWri[12][16][2]*s16)));
        Vpk[12][16][1] = (VWri[12][16][1]+((rk[11][2]*Wpk[12][16][0])-(rk[11][0]
          *Wpk[12][16][2])));
        Vpk[12][16][2] = (((rk[11][0]*Wpk[12][14][1])-(rk[11][1]*Wpk[12][16][0])
          )+((VWri[12][16][0]*s16)+(VWri[12][16][2]*c16)));
        VWri[12][17][0] = (Vpk[12][16][0]+((ri[12][2]*Wpk[12][14][1])-(ri[12][1]
          *Wpk[12][16][2])));
        VWri[12][17][1] = (Vpk[12][16][1]+((ri[12][0]*Wpk[12][16][2])-(ri[12][2]
          *Wpk[12][16][0])));
        VWri[12][17][2] = (Vpk[12][16][2]+((ri[12][1]*Wpk[12][16][0])-(ri[12][0]
          *Wpk[12][14][1])));
        Vpk[12][17][0] = (VWri[12][17][0]+((rk[12][1]*Wpk[12][17][2])-(rk[12][2]
          *Wpk[12][17][1])));
        Vpk[12][17][1] = (((rk[12][2]*Wpk[12][16][0])-(rk[12][0]*Wpk[12][17][2])
          )+((VWri[12][17][1]*c17)+(VWri[12][17][2]*s17)));
        Vpk[12][17][2] = (((rk[12][0]*Wpk[12][17][1])-(rk[12][1]*Wpk[12][16][0])
          )+((VWri[12][17][2]*c17)-(VWri[12][17][1]*s17)));
        Vpk[13][13][0] = -rk[8][2];
        Vpk[13][13][2] = rk[8][0];
        VWri[13][14][0] = (ri[9][2]-rk[8][2]);
        VWri[13][14][2] = (rk[8][0]-ri[9][0]);
        Vpk[13][14][0] = (VWri[13][14][0]-((rk[9][1]*s14)+(rk[9][2]*c14)));
        Vpk[13][14][1] = ((rk[9][0]*s14)+(VWri[13][14][2]*s14));
        Vpk[13][14][2] = ((rk[9][0]*c14)+(VWri[13][14][2]*c14));
        VWri[13][15][0] = (Vpk[13][14][0]+((ri[10][1]*s14)+(ri[10][2]*c14)));
        VWri[13][15][1] = (Vpk[13][14][1]-(ri[10][0]*s14));
        VWri[13][15][2] = (Vpk[13][14][2]-(ri[10][0]*c14));
        Vpk[13][15][0] = (((rk[10][1]*Wpk[13][15][2])-(rk[10][2]*c14))+((
          VWri[13][15][0]*c15)-(VWri[13][15][2]*s15)));
        Vpk[13][15][1] = (VWri[13][15][1]+((rk[10][2]*Wpk[13][15][0])-(rk[10][0]
          *Wpk[13][15][2])));
        Vpk[13][15][2] = (((rk[10][0]*c14)-(rk[10][1]*Wpk[13][15][0]))+((
          VWri[13][15][0]*s15)+(VWri[13][15][2]*c15)));
        VWri[13][16][0] = (Vpk[13][15][0]+((ri[11][2]*c14)-(ri[11][1]*
          Wpk[13][15][2])));
        VWri[13][16][1] = (Vpk[13][15][1]+((ri[11][0]*Wpk[13][15][2])-(ri[11][2]
          *Wpk[13][15][0])));
        VWri[13][16][2] = (Vpk[13][15][2]+((ri[11][1]*Wpk[13][15][0])-(ri[11][0]
          *c14)));
        Vpk[13][16][0] = (((rk[11][1]*Wpk[13][16][2])-(rk[11][2]*c14))+((
          VWri[13][16][0]*c16)-(VWri[13][16][2]*s16)));
        Vpk[13][16][1] = (VWri[13][16][1]+((rk[11][2]*Wpk[13][16][0])-(rk[11][0]
          *Wpk[13][16][2])));
        Vpk[13][16][2] = (((rk[11][0]*c14)-(rk[11][1]*Wpk[13][16][0]))+((
          VWri[13][16][0]*s16)+(VWri[13][16][2]*c16)));
        VWri[13][17][0] = (Vpk[13][16][0]+((ri[12][2]*c14)-(ri[12][1]*
          Wpk[13][16][2])));
        VWri[13][17][1] = (Vpk[13][16][1]+((ri[12][0]*Wpk[13][16][2])-(ri[12][2]
          *Wpk[13][16][0])));
        VWri[13][17][2] = (Vpk[13][16][2]+((ri[12][1]*Wpk[13][16][0])-(ri[12][0]
          *c14)));
        Vpk[13][17][0] = (VWri[13][17][0]+((rk[12][1]*Wpk[13][17][2])-(rk[12][2]
          *Wpk[13][17][1])));
        Vpk[13][17][1] = (((rk[12][2]*Wpk[13][16][0])-(rk[12][0]*Wpk[13][17][2])
          )+((VWri[13][17][1]*c17)+(VWri[13][17][2]*s17)));
        Vpk[13][17][2] = (((rk[12][0]*Wpk[13][17][1])-(rk[12][1]*Wpk[13][16][0])
          )+((VWri[13][17][2]*c17)-(VWri[13][17][1]*s17)));
        Vpk[14][14][1] = rk[9][2];
        Vpk[14][14][2] = -rk[9][1];
        VWri[14][15][1] = (rk[9][2]-ri[10][2]);
        VWri[14][15][2] = (ri[10][1]-rk[9][1]);
        Vpk[14][15][0] = ((rk[10][1]*s15)-(VWri[14][15][2]*s15));
        Vpk[14][15][1] = (VWri[14][15][1]+((rk[10][2]*c15)-(rk[10][0]*s15)));
        Vpk[14][15][2] = ((VWri[14][15][2]*c15)-(rk[10][1]*c15));
        VWri[14][16][0] = (Vpk[14][15][0]-(ri[11][1]*s15));
        VWri[14][16][1] = (Vpk[14][15][1]+((ri[11][0]*s15)-(ri[11][2]*c15)));
        VWri[14][16][2] = (Vpk[14][15][2]+(ri[11][1]*c15));
        Vpk[14][16][0] = ((rk[11][1]*Wpk[14][16][2])+((VWri[14][16][0]*c16)-(
          VWri[14][16][2]*s16)));
        Vpk[14][16][1] = (VWri[14][16][1]+((rk[11][2]*Wpk[14][16][0])-(rk[11][0]
          *Wpk[14][16][2])));
        Vpk[14][16][2] = (((VWri[14][16][0]*s16)+(VWri[14][16][2]*c16))-(
          rk[11][1]*Wpk[14][16][0]));
        VWri[14][17][0] = (Vpk[14][16][0]-(ri[12][1]*Wpk[14][16][2]));
        VWri[14][17][1] = (Vpk[14][16][1]+((ri[12][0]*Wpk[14][16][2])-(ri[12][2]
          *Wpk[14][16][0])));
        VWri[14][17][2] = (Vpk[14][16][2]+(ri[12][1]*Wpk[14][16][0]));
        Vpk[14][17][0] = (VWri[14][17][0]+((rk[12][1]*Wpk[14][17][2])-(rk[12][2]
          *Wpk[14][17][1])));
        Vpk[14][17][1] = (((rk[12][2]*Wpk[14][16][0])-(rk[12][0]*Wpk[14][17][2])
          )+((VWri[14][17][1]*c17)+(VWri[14][17][2]*s17)));
        Vpk[14][17][2] = (((rk[12][0]*Wpk[14][17][1])-(rk[12][1]*Wpk[14][16][0])
          )+((VWri[14][17][2]*c17)-(VWri[14][17][1]*s17)));
        Vpk[15][15][0] = -rk[10][2];
        Vpk[15][15][2] = rk[10][0];
        VWri[15][16][0] = (ri[11][2]-rk[10][2]);
        VWri[15][16][2] = (rk[10][0]-ri[11][0]);
        Vpk[15][16][0] = (((VWri[15][16][0]*c16)-(VWri[15][16][2]*s16))-
          rk[11][2]);
        Vpk[15][16][2] = (rk[11][0]+((VWri[15][16][0]*s16)+(VWri[15][16][2]*c16)
          ));
        VWri[15][17][0] = (ri[12][2]+Vpk[15][16][0]);
        VWri[15][17][2] = (Vpk[15][16][2]-ri[12][0]);
        Vpk[15][17][0] = (VWri[15][17][0]-((rk[12][1]*s17)+(rk[12][2]*c17)));
        Vpk[15][17][1] = ((rk[12][0]*s17)+(VWri[15][17][2]*s17));
        Vpk[15][17][2] = ((rk[12][0]*c17)+(VWri[15][17][2]*c17));
        Vpk[16][16][0] = -rk[11][2];
        Vpk[16][16][2] = rk[11][0];
        VWri[16][17][0] = (ri[12][2]-rk[11][2]);
        VWri[16][17][2] = (rk[11][0]-ri[12][0]);
        Vpk[16][17][0] = (VWri[16][17][0]-((rk[12][1]*s17)+(rk[12][2]*c17)));
        Vpk[16][17][1] = ((rk[12][0]*s17)+(VWri[16][17][2]*s17));
        Vpk[16][17][2] = ((rk[12][0]*c17)+(VWri[16][17][2]*c17));
        Vpk[17][17][1] = rk[12][2];
        Vpk[17][17][2] = -rk[12][1];
        Vpk[18][18][0] = -rk[13][2];
        Vpk[18][18][2] = rk[13][0];
        VWri[18][19][0] = (ri[14][2]-rk[13][2]);
        VWri[18][19][2] = (rk[13][0]-ri[14][0]);
        Vpk[18][19][0] = (VWri[18][19][0]-((rk[14][1]*s19)+(rk[14][2]*c19)));
        Vpk[18][19][1] = ((rk[14][0]*s19)+(VWri[18][19][2]*s19));
        Vpk[18][19][2] = ((rk[14][0]*c19)+(VWri[18][19][2]*c19));
        VWri[18][20][0] = (Vpk[18][19][0]+((ri[15][1]*s19)+(ri[15][2]*c19)));
        VWri[18][20][1] = (Vpk[18][19][1]-(ri[15][0]*s19));
        VWri[18][20][2] = (Vpk[18][19][2]-(ri[15][0]*c19));
        Vpk[18][20][0] = (((rk[15][1]*Wpk[18][20][2])-(rk[15][2]*c19))+((
          VWri[18][20][0]*c20)-(VWri[18][20][2]*s20)));
        Vpk[18][20][1] = (VWri[18][20][1]+((rk[15][2]*Wpk[18][20][0])-(rk[15][0]
          *Wpk[18][20][2])));
        Vpk[18][20][2] = (((rk[15][0]*c19)-(rk[15][1]*Wpk[18][20][0]))+((
          VWri[18][20][0]*s20)+(VWri[18][20][2]*c20)));
        VWri[18][21][0] = (Vpk[18][20][0]+((ri[16][2]*c19)-(ri[16][1]*
          Wpk[18][20][2])));
        VWri[18][21][1] = (Vpk[18][20][1]+((ri[16][0]*Wpk[18][20][2])-(ri[16][2]
          *Wpk[18][20][0])));
        VWri[18][21][2] = (Vpk[18][20][2]+((ri[16][1]*Wpk[18][20][0])-(ri[16][0]
          *c19)));
        Vpk[18][21][0] = (((rk[16][1]*Wpk[18][20][2])-(rk[16][2]*Wpk[18][21][1])
          )+((VWri[18][21][0]*c21)+(VWri[18][21][1]*s21)));
        Vpk[18][21][1] = (((rk[16][2]*Wpk[18][21][0])-(rk[16][0]*Wpk[18][20][2])
          )+((VWri[18][21][1]*c21)-(VWri[18][21][0]*s21)));
        Vpk[18][21][2] = (VWri[18][21][2]+((rk[16][0]*Wpk[18][21][1])-(rk[16][1]
          *Wpk[18][21][0])));
        Vpk[19][19][1] = rk[14][2];
        Vpk[19][19][2] = -rk[14][1];
        VWri[19][20][1] = (rk[14][2]-ri[15][2]);
        VWri[19][20][2] = (ri[15][1]-rk[14][1]);
        Vpk[19][20][0] = ((rk[15][1]*s20)-(VWri[19][20][2]*s20));
        Vpk[19][20][1] = (VWri[19][20][1]+((rk[15][2]*c20)-(rk[15][0]*s20)));
        Vpk[19][20][2] = ((VWri[19][20][2]*c20)-(rk[15][1]*c20));
        VWri[19][21][0] = (Vpk[19][20][0]-(ri[16][1]*s20));
        VWri[19][21][1] = (Vpk[19][20][1]+((ri[16][0]*s20)-(ri[16][2]*c20)));
        VWri[19][21][2] = (Vpk[19][20][2]+(ri[16][1]*c20));
        Vpk[19][21][0] = (((rk[16][1]*s20)-(rk[16][2]*Wpk[19][21][1]))+((
          VWri[19][21][0]*c21)+(VWri[19][21][1]*s21)));
        Vpk[19][21][1] = (((rk[16][2]*Wpk[19][21][0])-(rk[16][0]*s20))+((
          VWri[19][21][1]*c21)-(VWri[19][21][0]*s21)));
        Vpk[19][21][2] = (VWri[19][21][2]+((rk[16][0]*Wpk[19][21][1])-(rk[16][1]
          *Wpk[19][21][0])));
        Vpk[20][20][0] = -rk[15][2];
        Vpk[20][20][2] = rk[15][0];
        VWri[20][21][0] = (ri[16][2]-rk[15][2]);
        VWri[20][21][2] = (rk[15][0]-ri[16][0]);
        Vpk[20][21][0] = ((VWri[20][21][0]*c21)-(rk[16][2]*c21));
        Vpk[20][21][1] = ((rk[16][2]*s21)-(VWri[20][21][0]*s21));
        Vpk[20][21][2] = (VWri[20][21][2]+((rk[16][0]*c21)-(rk[16][1]*s21)));
        Vpk[21][21][0] = rk[16][1];
        Vpk[21][21][1] = -rk[16][0];
        Vpk[22][22][0] = -rk[17][2];
        Vpk[22][22][2] = rk[17][0];
        VWri[22][23][0] = (ri[18][2]-rk[17][2]);
        VWri[22][23][2] = (rk[17][0]-ri[18][0]);
        Vpk[22][23][0] = (VWri[22][23][0]-((rk[18][1]*s23)+(rk[18][2]*c23)));
        Vpk[22][23][1] = ((rk[18][0]*s23)+(VWri[22][23][2]*s23));
        Vpk[22][23][2] = ((rk[18][0]*c23)+(VWri[22][23][2]*c23));
        VWri[22][24][0] = (Vpk[22][23][0]+((ri[19][1]*s23)+(ri[19][2]*c23)));
        VWri[22][24][1] = (Vpk[22][23][1]-(ri[19][0]*s23));
        VWri[22][24][2] = (Vpk[22][23][2]-(ri[19][0]*c23));
        Vpk[22][24][0] = (((rk[19][1]*Wpk[22][24][2])-(rk[19][2]*c23))+((
          VWri[22][24][0]*c24)-(VWri[22][24][2]*s24)));
        Vpk[22][24][1] = (VWri[22][24][1]+((rk[19][2]*Wpk[22][24][0])-(rk[19][0]
          *Wpk[22][24][2])));
        Vpk[22][24][2] = (((rk[19][0]*c23)-(rk[19][1]*Wpk[22][24][0]))+((
          VWri[22][24][0]*s24)+(VWri[22][24][2]*c24)));
        VWri[22][25][0] = (Vpk[22][24][0]+((ri[20][2]*c23)-(ri[20][1]*
          Wpk[22][24][2])));
        VWri[22][25][1] = (Vpk[22][24][1]+((ri[20][0]*Wpk[22][24][2])-(ri[20][2]
          *Wpk[22][24][0])));
        VWri[22][25][2] = (Vpk[22][24][2]+((ri[20][1]*Wpk[22][24][0])-(ri[20][0]
          *c23)));
        Vpk[22][25][0] = (((rk[20][1]*Wpk[22][24][2])-(rk[20][2]*Wpk[22][25][1])
          )+((VWri[22][25][0]*c25)+(VWri[22][25][1]*s25)));
        Vpk[22][25][1] = (((rk[20][2]*Wpk[22][25][0])-(rk[20][0]*Wpk[22][24][2])
          )+((VWri[22][25][1]*c25)-(VWri[22][25][0]*s25)));
        Vpk[22][25][2] = (VWri[22][25][2]+((rk[20][0]*Wpk[22][25][1])-(rk[20][1]
          *Wpk[22][25][0])));
        Vpk[23][23][1] = rk[18][2];
        Vpk[23][23][2] = -rk[18][1];
        VWri[23][24][1] = (rk[18][2]-ri[19][2]);
        VWri[23][24][2] = (ri[19][1]-rk[18][1]);
        Vpk[23][24][0] = ((rk[19][1]*s24)-(VWri[23][24][2]*s24));
        Vpk[23][24][1] = (VWri[23][24][1]+((rk[19][2]*c24)-(rk[19][0]*s24)));
        Vpk[23][24][2] = ((VWri[23][24][2]*c24)-(rk[19][1]*c24));
        VWri[23][25][0] = (Vpk[23][24][0]-(ri[20][1]*s24));
        VWri[23][25][1] = (Vpk[23][24][1]+((ri[20][0]*s24)-(ri[20][2]*c24)));
        VWri[23][25][2] = (Vpk[23][24][2]+(ri[20][1]*c24));
        Vpk[23][25][0] = (((rk[20][1]*s24)-(rk[20][2]*Wpk[23][25][1]))+((
          VWri[23][25][0]*c25)+(VWri[23][25][1]*s25)));
        Vpk[23][25][1] = (((rk[20][2]*Wpk[23][25][0])-(rk[20][0]*s24))+((
          VWri[23][25][1]*c25)-(VWri[23][25][0]*s25)));
        Vpk[23][25][2] = (VWri[23][25][2]+((rk[20][0]*Wpk[23][25][1])-(rk[20][1]
          *Wpk[23][25][0])));
        Vpk[24][24][0] = -rk[19][2];
        Vpk[24][24][2] = rk[19][0];
        VWri[24][25][0] = (ri[20][2]-rk[19][2]);
        VWri[24][25][2] = (rk[19][0]-ri[20][0]);
        Vpk[24][25][0] = ((VWri[24][25][0]*c25)-(rk[20][2]*c25));
        Vpk[24][25][1] = ((rk[20][2]*s25)-(VWri[24][25][0]*s25));
        Vpk[24][25][2] = (VWri[24][25][2]+((rk[20][0]*c25)-(rk[20][1]*s25)));
        Vpk[25][25][0] = rk[20][1];
        Vpk[25][25][1] = -rk[20][0];
        vpkflg = 1;
    }
/*
 Used 0.05 seconds CPU time,
 0 additional bytes of memory.
 Equations contain 1379 adds/subtracts/negates
                   1696 multiplies
                      0 divides
                   1121 assignments
*/
}

void Jimmy::sddoltau(void)
{

/*
Compute effect of loop hinge torques
*/
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                      0 assignments
*/
}

void Jimmy::sddoiner(void)
{

/*
Compute inertial accelerations and related temps
*/
    if (inerflg == 0) {
/*
Compute Otk (inertial angular acceleration)
*/
        Otk[6][0] = (u[6]*wk[6][1]);
        Otk[6][1] = -(u[6]*wk[6][0]);
        Otk[7][0] = ((Otk[6][0]*c7)-(u[7]*wk[7][2]));
        Otk[7][2] = ((Otk[6][0]*s7)+(u[7]*wk[7][0]));
        Otk[8][1] = ((u[8]*wk[8][2])+((Otk[6][1]*c8)+(Otk[7][2]*s8)));
        Otk[8][2] = (((Otk[7][2]*c8)-(Otk[6][1]*s8))-(u[8]*wk[8][1]));
        Otk[9][0] = (((Otk[7][0]*c9)-(Otk[8][2]*s9))-(u[9]*wk[9][2]));
        Otk[9][2] = ((u[9]*wk[9][0])+((Otk[7][0]*s9)+(Otk[8][2]*c9)));
        Otk[10][0] = (((Otk[9][0]*c10)-(Otk[9][2]*s10))-(u[10]*wk[10][2]));
        Otk[10][2] = ((u[10]*wk[10][0])+((Otk[9][0]*s10)+(Otk[9][2]*c10)));
        Otk[11][1] = ((u[11]*wk[11][2])+((Otk[8][1]*c11)+(Otk[10][2]*s11)));
        Otk[11][2] = (((Otk[10][2]*c11)-(Otk[8][1]*s11))-(u[11]*wk[11][1]));
        Otk[12][0] = (u[12]*wk[12][1]);
        Otk[12][1] = -(u[12]*wk[12][0]);
        Otk[13][0] = ((Otk[12][0]*c13)-(u[13]*wk[13][2]));
        Otk[13][2] = ((Otk[12][0]*s13)+(u[13]*wk[13][0]));
        Otk[14][1] = ((u[14]*wk[14][2])+((Otk[12][1]*c14)+(Otk[13][2]*s14)));
        Otk[14][2] = (((Otk[13][2]*c14)-(Otk[12][1]*s14))-(u[14]*wk[14][1]));
        Otk[15][0] = (((Otk[13][0]*c15)-(Otk[14][2]*s15))-(u[15]*wk[15][2]));
        Otk[15][2] = ((u[15]*wk[15][0])+((Otk[13][0]*s15)+(Otk[14][2]*c15)));
        Otk[16][0] = (((Otk[15][0]*c16)-(Otk[15][2]*s16))-(u[16]*wk[16][2]));
        Otk[16][2] = ((u[16]*wk[16][0])+((Otk[15][0]*s16)+(Otk[15][2]*c16)));
        Otk[17][1] = ((u[17]*wk[17][2])+((Otk[14][1]*c17)+(Otk[16][2]*s17)));
        Otk[17][2] = (((Otk[16][2]*c17)-(Otk[14][1]*s17))-(u[17]*wk[17][1]));
        Otk[18][0] = -(u[18]*wk[18][2]);
        Otk[18][2] = (u[18]*wk[18][0]);
        Otk[19][1] = ((Otk[18][2]*s19)+(u[19]*wk[19][2]));
        Otk[19][2] = ((Otk[18][2]*c19)-(u[19]*wk[19][1]));
        Otk[20][0] = (((Otk[18][0]*c20)-(Otk[19][2]*s20))-(u[20]*wk[20][2]));
        Otk[20][2] = ((u[20]*wk[20][0])+((Otk[18][0]*s20)+(Otk[19][2]*c20)));
        Otk[21][0] = ((u[21]*wk[21][1])+((Otk[19][1]*s21)+(Otk[20][0]*c21)));
        Otk[21][1] = (((Otk[19][1]*c21)-(Otk[20][0]*s21))-(u[21]*wk[21][0]));
        Otk[22][0] = -(u[22]*wk[22][2]);
        Otk[22][2] = (u[22]*wk[22][0]);
        Otk[23][1] = ((Otk[22][2]*s23)+(u[23]*wk[23][2]));
        Otk[23][2] = ((Otk[22][2]*c23)-(u[23]*wk[23][1]));
        Otk[24][0] = (((Otk[22][0]*c24)-(Otk[23][2]*s24))-(u[24]*wk[24][2]));
        Otk[24][2] = ((u[24]*wk[24][0])+((Otk[22][0]*s24)+(Otk[23][2]*c24)));
        Otk[25][0] = ((u[25]*wk[25][1])+((Otk[23][1]*s25)+(Otk[24][0]*c25)));
        Otk[25][1] = (((Otk[23][1]*c25)-(Otk[24][0]*s25))-(u[25]*wk[25][0]));
/*
Compute Atk (inertial linear acceleration)
*/
        Atk[5][0] = ((u[4]*Wkrpk[5][2])-(u[5]*Wkrpk[5][1]));
        Atk[5][1] = ((u[5]*Wkrpk[5][0])-(u[3]*Wkrpk[5][2]));
        Atk[5][2] = ((u[3]*Wkrpk[5][1])-(u[4]*Wkrpk[5][0]));
        AiOiWi[6][0] = (Atk[5][0]+((u[4]*Wirk[6][2])-(u[5]*Wirk[6][1])));
        AiOiWi[6][1] = (Atk[5][1]+((u[5]*Wirk[6][0])-(u[3]*Wirk[6][2])));
        AiOiWi[6][2] = (Atk[5][2]+((u[3]*Wirk[6][1])-(u[4]*Wirk[6][0])));
        Atk[6][0] = (((AiOiWi[6][0]*c6)+(AiOiWi[6][1]*s6))+(((wk[6][1]*
          Wkrpk[6][2])-(wk[6][2]*Wkrpk[6][1]))-(Otk[6][1]*rk[1][2])));
        Atk[6][1] = (((AiOiWi[6][1]*c6)-(AiOiWi[6][0]*s6))+((Otk[6][0]*rk[1][2])
          +((wk[6][2]*Wkrpk[6][0])-(wk[6][0]*Wkrpk[6][2]))));
        Atk[6][2] = (AiOiWi[6][2]+(((Otk[6][1]*rk[1][0])-(Otk[6][0]*rk[1][1]))+(
          (wk[6][0]*Wkrpk[6][1])-(wk[6][1]*Wkrpk[6][0]))));
        AiOiWi[7][0] = (Atk[6][0]+((Otk[6][1]*ri[2][2])+((Wirk[7][2]*wk[6][1])-(
          Wirk[7][1]*wk[6][2]))));
        AiOiWi[7][1] = (Atk[6][1]+(((Wirk[7][0]*wk[6][2])-(Wirk[7][2]*wk[6][0]))
          -(Otk[6][0]*ri[2][2])));
        AiOiWi[7][2] = (Atk[6][2]+(((Otk[6][0]*ri[2][1])-(Otk[6][1]*ri[2][0]))+(
          (Wirk[7][1]*wk[6][0])-(Wirk[7][0]*wk[6][1]))));
        Atk[7][0] = (((AiOiWi[7][0]*c7)-(AiOiWi[7][2]*s7))+(((Otk[7][2]*rk[2][1]
          )-(Otk[6][1]*rk[2][2]))+((wk[7][1]*Wkrpk[7][2])-(wk[7][2]*Wkrpk[7][1])
          )));
        Atk[7][1] = (AiOiWi[7][1]+(((Otk[7][0]*rk[2][2])-(Otk[7][2]*rk[2][0]))+(
          (wk[7][2]*Wkrpk[7][0])-(wk[7][0]*Wkrpk[7][2]))));
        Atk[7][2] = (((AiOiWi[7][0]*s7)+(AiOiWi[7][2]*c7))+(((Otk[6][1]*rk[2][0]
          )-(Otk[7][0]*rk[2][1]))+((wk[7][0]*Wkrpk[7][1])-(wk[7][1]*Wkrpk[7][0])
          )));
        AiOiWi[8][0] = (Atk[7][0]+(((Otk[6][1]*ri[3][2])-(Otk[7][2]*ri[3][1]))+(
          (Wirk[8][2]*wk[7][1])-(Wirk[8][1]*wk[7][2]))));
        AiOiWi[8][1] = (Atk[7][1]+(((Otk[7][2]*ri[3][0])-(Otk[7][0]*ri[3][2]))+(
          (Wirk[8][0]*wk[7][2])-(Wirk[8][2]*wk[7][0]))));
        AiOiWi[8][2] = (Atk[7][2]+(((Otk[7][0]*ri[3][1])-(Otk[6][1]*ri[3][0]))+(
          (Wirk[8][1]*wk[7][0])-(Wirk[8][0]*wk[7][1]))));
        Atk[8][0] = (AiOiWi[8][0]+(((Otk[8][2]*rk[3][1])-(Otk[8][1]*rk[3][2]))+(
          (wk[8][1]*Wkrpk[8][2])-(wk[8][2]*Wkrpk[8][1]))));
        Atk[8][1] = (((AiOiWi[8][1]*c8)+(AiOiWi[8][2]*s8))+(((Otk[7][0]*rk[3][2]
          )-(Otk[8][2]*rk[3][0]))+((wk[8][2]*Wkrpk[8][0])-(wk[8][0]*Wkrpk[8][2])
          )));
        Atk[8][2] = (((AiOiWi[8][2]*c8)-(AiOiWi[8][1]*s8))+(((Otk[8][1]*rk[3][0]
          )-(Otk[7][0]*rk[3][1]))+((wk[8][0]*Wkrpk[8][1])-(wk[8][1]*Wkrpk[8][0])
          )));
        AiOiWi[9][0] = (Atk[8][0]+(((Otk[8][1]*ri[4][2])-(Otk[8][2]*ri[4][1]))+(
          (Wirk[9][2]*wk[8][1])-(Wirk[9][1]*wk[8][2]))));
        AiOiWi[9][1] = (Atk[8][1]+(((Otk[8][2]*ri[4][0])-(Otk[7][0]*ri[4][2]))+(
          (Wirk[9][0]*wk[8][2])-(Wirk[9][2]*wk[8][0]))));
        AiOiWi[9][2] = (Atk[8][2]+(((Otk[7][0]*ri[4][1])-(Otk[8][1]*ri[4][0]))+(
          (Wirk[9][1]*wk[8][0])-(Wirk[9][0]*wk[8][1]))));
        Atk[9][0] = (((AiOiWi[9][0]*c9)-(AiOiWi[9][2]*s9))+(((Otk[9][2]*rk[4][1]
          )-(Otk[8][1]*rk[4][2]))+((wk[9][1]*Wkrpk[9][2])-(wk[9][2]*Wkrpk[9][1])
          )));
        Atk[9][1] = (AiOiWi[9][1]+(((Otk[9][0]*rk[4][2])-(Otk[9][2]*rk[4][0]))+(
          (wk[9][2]*Wkrpk[9][0])-(wk[9][0]*Wkrpk[9][2]))));
        Atk[9][2] = (((AiOiWi[9][0]*s9)+(AiOiWi[9][2]*c9))+(((Otk[8][1]*rk[4][0]
          )-(Otk[9][0]*rk[4][1]))+((wk[9][0]*Wkrpk[9][1])-(wk[9][1]*Wkrpk[9][0])
          )));
        AiOiWi[10][0] = (Atk[9][0]+(((Otk[8][1]*ri[5][2])-(Otk[9][2]*ri[5][1]))+
          ((Wirk[10][2]*wk[9][1])-(Wirk[10][1]*wk[9][2]))));
        AiOiWi[10][1] = (Atk[9][1]+(((Otk[9][2]*ri[5][0])-(Otk[9][0]*ri[5][2]))+
          ((Wirk[10][0]*wk[9][2])-(Wirk[10][2]*wk[9][0]))));
        AiOiWi[10][2] = (Atk[9][2]+(((Otk[9][0]*ri[5][1])-(Otk[8][1]*ri[5][0]))+
          ((Wirk[10][1]*wk[9][0])-(Wirk[10][0]*wk[9][1]))));
        Atk[10][0] = (((AiOiWi[10][0]*c10)-(AiOiWi[10][2]*s10))+(((Otk[10][2]*
          rk[5][1])-(Otk[8][1]*rk[5][2]))+((wk[10][1]*Wkrpk[10][2])-(wk[10][2]*
          Wkrpk[10][1]))));
        Atk[10][1] = (AiOiWi[10][1]+(((Otk[10][0]*rk[5][2])-(Otk[10][2]*rk[5][0]
          ))+((wk[10][2]*Wkrpk[10][0])-(wk[10][0]*Wkrpk[10][2]))));
        Atk[10][2] = (((AiOiWi[10][0]*s10)+(AiOiWi[10][2]*c10))+(((Otk[8][1]*
          rk[5][0])-(Otk[10][0]*rk[5][1]))+((wk[10][0]*Wkrpk[10][1])-(wk[10][1]*
          Wkrpk[10][0]))));
        AiOiWi[11][0] = (Atk[10][0]+(((Otk[8][1]*ri[6][2])-(Otk[10][2]*ri[6][1])
          )+((Wirk[11][2]*wk[10][1])-(Wirk[11][1]*wk[10][2]))));
        AiOiWi[11][1] = (Atk[10][1]+(((Otk[10][2]*ri[6][0])-(Otk[10][0]*ri[6][2]
          ))+((Wirk[11][0]*wk[10][2])-(Wirk[11][2]*wk[10][0]))));
        AiOiWi[11][2] = (Atk[10][2]+(((Otk[10][0]*ri[6][1])-(Otk[8][1]*ri[6][0])
          )+((Wirk[11][1]*wk[10][0])-(Wirk[11][0]*wk[10][1]))));
        Atk[11][0] = (AiOiWi[11][0]+(((Otk[11][2]*rk[6][1])-(Otk[11][1]*rk[6][2]
          ))+((wk[11][1]*Wkrpk[11][2])-(wk[11][2]*Wkrpk[11][1]))));
        Atk[11][1] = (((AiOiWi[11][1]*c11)+(AiOiWi[11][2]*s11))+(((Otk[10][0]*
          rk[6][2])-(Otk[11][2]*rk[6][0]))+((wk[11][2]*Wkrpk[11][0])-(wk[11][0]*
          Wkrpk[11][2]))));
        Atk[11][2] = (((AiOiWi[11][2]*c11)-(AiOiWi[11][1]*s11))+(((Otk[11][1]*
          rk[6][0])-(Otk[10][0]*rk[6][1]))+((wk[11][0]*Wkrpk[11][1])-(wk[11][1]*
          Wkrpk[11][0]))));
        AiOiWi[12][0] = (Atk[5][0]+((u[4]*Wirk[12][2])-(u[5]*Wirk[12][1])));
        AiOiWi[12][1] = (Atk[5][1]+((u[5]*Wirk[12][0])-(u[3]*Wirk[12][2])));
        AiOiWi[12][2] = (Atk[5][2]+((u[3]*Wirk[12][1])-(u[4]*Wirk[12][0])));
        Atk[12][0] = (((AiOiWi[12][0]*c12)+(AiOiWi[12][1]*s12))+(((wk[12][1]*
          Wkrpk[12][2])-(wk[12][2]*Wkrpk[12][1]))-(Otk[12][1]*rk[7][2])));
        Atk[12][1] = (((AiOiWi[12][1]*c12)-(AiOiWi[12][0]*s12))+((Otk[12][0]*
          rk[7][2])+((wk[12][2]*Wkrpk[12][0])-(wk[12][0]*Wkrpk[12][2]))));
        Atk[12][2] = (AiOiWi[12][2]+(((Otk[12][1]*rk[7][0])-(Otk[12][0]*rk[7][1]
          ))+((wk[12][0]*Wkrpk[12][1])-(wk[12][1]*Wkrpk[12][0]))));
        AiOiWi[13][0] = (Atk[12][0]+((Otk[12][1]*ri[8][2])+((Wirk[13][2]*
          wk[12][1])-(Wirk[13][1]*wk[12][2]))));
        AiOiWi[13][1] = (Atk[12][1]+(((Wirk[13][0]*wk[12][2])-(Wirk[13][2]*
          wk[12][0]))-(Otk[12][0]*ri[8][2])));
        AiOiWi[13][2] = (Atk[12][2]+(((Otk[12][0]*ri[8][1])-(Otk[12][1]*ri[8][0]
          ))+((Wirk[13][1]*wk[12][0])-(Wirk[13][0]*wk[12][1]))));
        Atk[13][0] = (((AiOiWi[13][0]*c13)-(AiOiWi[13][2]*s13))+(((Otk[13][2]*
          rk[8][1])-(Otk[12][1]*rk[8][2]))+((wk[13][1]*Wkrpk[13][2])-(wk[13][2]*
          Wkrpk[13][1]))));
        Atk[13][1] = (AiOiWi[13][1]+(((Otk[13][0]*rk[8][2])-(Otk[13][2]*rk[8][0]
          ))+((wk[13][2]*Wkrpk[13][0])-(wk[13][0]*Wkrpk[13][2]))));
        Atk[13][2] = (((AiOiWi[13][0]*s13)+(AiOiWi[13][2]*c13))+(((Otk[12][1]*
          rk[8][0])-(Otk[13][0]*rk[8][1]))+((wk[13][0]*Wkrpk[13][1])-(wk[13][1]*
          Wkrpk[13][0]))));
        AiOiWi[14][0] = (Atk[13][0]+(((Otk[12][1]*ri[9][2])-(Otk[13][2]*ri[9][1]
          ))+((Wirk[14][2]*wk[13][1])-(Wirk[14][1]*wk[13][2]))));
        AiOiWi[14][1] = (Atk[13][1]+(((Otk[13][2]*ri[9][0])-(Otk[13][0]*ri[9][2]
          ))+((Wirk[14][0]*wk[13][2])-(Wirk[14][2]*wk[13][0]))));
        AiOiWi[14][2] = (Atk[13][2]+(((Otk[13][0]*ri[9][1])-(Otk[12][1]*ri[9][0]
          ))+((Wirk[14][1]*wk[13][0])-(Wirk[14][0]*wk[13][1]))));
        Atk[14][0] = (AiOiWi[14][0]+(((Otk[14][2]*rk[9][1])-(Otk[14][1]*rk[9][2]
          ))+((wk[14][1]*Wkrpk[14][2])-(wk[14][2]*Wkrpk[14][1]))));
        Atk[14][1] = (((AiOiWi[14][1]*c14)+(AiOiWi[14][2]*s14))+(((Otk[13][0]*
          rk[9][2])-(Otk[14][2]*rk[9][0]))+((wk[14][2]*Wkrpk[14][0])-(wk[14][0]*
          Wkrpk[14][2]))));
        Atk[14][2] = (((AiOiWi[14][2]*c14)-(AiOiWi[14][1]*s14))+(((Otk[14][1]*
          rk[9][0])-(Otk[13][0]*rk[9][1]))+((wk[14][0]*Wkrpk[14][1])-(wk[14][1]*
          Wkrpk[14][0]))));
        AiOiWi[15][0] = (Atk[14][0]+(((Otk[14][1]*ri[10][2])-(Otk[14][2]*
          ri[10][1]))+((Wirk[15][2]*wk[14][1])-(Wirk[15][1]*wk[14][2]))));
        AiOiWi[15][1] = (Atk[14][1]+(((Otk[14][2]*ri[10][0])-(Otk[13][0]*
          ri[10][2]))+((Wirk[15][0]*wk[14][2])-(Wirk[15][2]*wk[14][0]))));
        AiOiWi[15][2] = (Atk[14][2]+(((Otk[13][0]*ri[10][1])-(Otk[14][1]*
          ri[10][0]))+((Wirk[15][1]*wk[14][0])-(Wirk[15][0]*wk[14][1]))));
        Atk[15][0] = (((AiOiWi[15][0]*c15)-(AiOiWi[15][2]*s15))+(((Otk[15][2]*
          rk[10][1])-(Otk[14][1]*rk[10][2]))+((wk[15][1]*Wkrpk[15][2])-(
          wk[15][2]*Wkrpk[15][1]))));
        Atk[15][1] = (AiOiWi[15][1]+(((Otk[15][0]*rk[10][2])-(Otk[15][2]*
          rk[10][0]))+((wk[15][2]*Wkrpk[15][0])-(wk[15][0]*Wkrpk[15][2]))));
        Atk[15][2] = (((AiOiWi[15][0]*s15)+(AiOiWi[15][2]*c15))+(((Otk[14][1]*
          rk[10][0])-(Otk[15][0]*rk[10][1]))+((wk[15][0]*Wkrpk[15][1])-(
          wk[15][1]*Wkrpk[15][0]))));
        AiOiWi[16][0] = (Atk[15][0]+(((Otk[14][1]*ri[11][2])-(Otk[15][2]*
          ri[11][1]))+((Wirk[16][2]*wk[15][1])-(Wirk[16][1]*wk[15][2]))));
        AiOiWi[16][1] = (Atk[15][1]+(((Otk[15][2]*ri[11][0])-(Otk[15][0]*
          ri[11][2]))+((Wirk[16][0]*wk[15][2])-(Wirk[16][2]*wk[15][0]))));
        AiOiWi[16][2] = (Atk[15][2]+(((Otk[15][0]*ri[11][1])-(Otk[14][1]*
          ri[11][0]))+((Wirk[16][1]*wk[15][0])-(Wirk[16][0]*wk[15][1]))));
        Atk[16][0] = (((AiOiWi[16][0]*c16)-(AiOiWi[16][2]*s16))+(((Otk[16][2]*
          rk[11][1])-(Otk[14][1]*rk[11][2]))+((wk[16][1]*Wkrpk[16][2])-(
          wk[16][2]*Wkrpk[16][1]))));
        Atk[16][1] = (AiOiWi[16][1]+(((Otk[16][0]*rk[11][2])-(Otk[16][2]*
          rk[11][0]))+((wk[16][2]*Wkrpk[16][0])-(wk[16][0]*Wkrpk[16][2]))));
        Atk[16][2] = (((AiOiWi[16][0]*s16)+(AiOiWi[16][2]*c16))+(((Otk[14][1]*
          rk[11][0])-(Otk[16][0]*rk[11][1]))+((wk[16][0]*Wkrpk[16][1])-(
          wk[16][1]*Wkrpk[16][0]))));
        AiOiWi[17][0] = (Atk[16][0]+(((Otk[14][1]*ri[12][2])-(Otk[16][2]*
          ri[12][1]))+((Wirk[17][2]*wk[16][1])-(Wirk[17][1]*wk[16][2]))));
        AiOiWi[17][1] = (Atk[16][1]+(((Otk[16][2]*ri[12][0])-(Otk[16][0]*
          ri[12][2]))+((Wirk[17][0]*wk[16][2])-(Wirk[17][2]*wk[16][0]))));
        AiOiWi[17][2] = (Atk[16][2]+(((Otk[16][0]*ri[12][1])-(Otk[14][1]*
          ri[12][0]))+((Wirk[17][1]*wk[16][0])-(Wirk[17][0]*wk[16][1]))));
        Atk[17][0] = (AiOiWi[17][0]+(((Otk[17][2]*rk[12][1])-(Otk[17][1]*
          rk[12][2]))+((wk[17][1]*Wkrpk[17][2])-(wk[17][2]*Wkrpk[17][1]))));
        Atk[17][1] = (((AiOiWi[17][1]*c17)+(AiOiWi[17][2]*s17))+(((Otk[16][0]*
          rk[12][2])-(Otk[17][2]*rk[12][0]))+((wk[17][2]*Wkrpk[17][0])-(
          wk[17][0]*Wkrpk[17][2]))));
        Atk[17][2] = (((AiOiWi[17][2]*c17)-(AiOiWi[17][1]*s17))+(((Otk[17][1]*
          rk[12][0])-(Otk[16][0]*rk[12][1]))+((wk[17][0]*Wkrpk[17][1])-(
          wk[17][1]*Wkrpk[17][0]))));
        AiOiWi[18][0] = (Atk[5][0]+((u[4]*Wirk[18][2])-(u[5]*Wirk[18][1])));
        AiOiWi[18][1] = (Atk[5][1]+((u[5]*Wirk[18][0])-(u[3]*Wirk[18][2])));
        AiOiWi[18][2] = (Atk[5][2]+((u[3]*Wirk[18][1])-(u[4]*Wirk[18][0])));
        Atk[18][0] = (((AiOiWi[18][0]*c18)-(AiOiWi[18][2]*s18))+((Otk[18][2]*
          rk[13][1])+((wk[18][1]*Wkrpk[18][2])-(wk[18][2]*Wkrpk[18][1]))));
        Atk[18][1] = (AiOiWi[18][1]+(((Otk[18][0]*rk[13][2])-(Otk[18][2]*
          rk[13][0]))+((wk[18][2]*Wkrpk[18][0])-(wk[18][0]*Wkrpk[18][2]))));
        Atk[18][2] = (((AiOiWi[18][0]*s18)+(AiOiWi[18][2]*c18))+(((wk[18][0]*
          Wkrpk[18][1])-(wk[18][1]*Wkrpk[18][0]))-(Otk[18][0]*rk[13][1])));
        AiOiWi[19][0] = (Atk[18][0]+(((Wirk[19][2]*wk[18][1])-(Wirk[19][1]*
          wk[18][2]))-(Otk[18][2]*ri[14][1])));
        AiOiWi[19][1] = (Atk[18][1]+(((Otk[18][2]*ri[14][0])-(Otk[18][0]*
          ri[14][2]))+((Wirk[19][0]*wk[18][2])-(Wirk[19][2]*wk[18][0]))));
        AiOiWi[19][2] = (Atk[18][2]+((Otk[18][0]*ri[14][1])+((Wirk[19][1]*
          wk[18][0])-(Wirk[19][0]*wk[18][1]))));
        Atk[19][0] = (AiOiWi[19][0]+(((Otk[19][2]*rk[14][1])-(Otk[19][1]*
          rk[14][2]))+((wk[19][1]*Wkrpk[19][2])-(wk[19][2]*Wkrpk[19][1]))));
        Atk[19][1] = (((AiOiWi[19][1]*c19)+(AiOiWi[19][2]*s19))+(((Otk[18][0]*
          rk[14][2])-(Otk[19][2]*rk[14][0]))+((wk[19][2]*Wkrpk[19][0])-(
          wk[19][0]*Wkrpk[19][2]))));
        Atk[19][2] = (((AiOiWi[19][2]*c19)-(AiOiWi[19][1]*s19))+(((Otk[19][1]*
          rk[14][0])-(Otk[18][0]*rk[14][1]))+((wk[19][0]*Wkrpk[19][1])-(
          wk[19][1]*Wkrpk[19][0]))));
        AiOiWi[20][0] = (Atk[19][0]+(((Otk[19][1]*ri[15][2])-(Otk[19][2]*
          ri[15][1]))+((Wirk[20][2]*wk[19][1])-(Wirk[20][1]*wk[19][2]))));
        AiOiWi[20][1] = (Atk[19][1]+(((Otk[19][2]*ri[15][0])-(Otk[18][0]*
          ri[15][2]))+((Wirk[20][0]*wk[19][2])-(Wirk[20][2]*wk[19][0]))));
        AiOiWi[20][2] = (Atk[19][2]+(((Otk[18][0]*ri[15][1])-(Otk[19][1]*
          ri[15][0]))+((Wirk[20][1]*wk[19][0])-(Wirk[20][0]*wk[19][1]))));
        Atk[20][0] = (((AiOiWi[20][0]*c20)-(AiOiWi[20][2]*s20))+(((Otk[20][2]*
          rk[15][1])-(Otk[19][1]*rk[15][2]))+((wk[20][1]*Wkrpk[20][2])-(
          wk[20][2]*Wkrpk[20][1]))));
        Atk[20][1] = (AiOiWi[20][1]+(((Otk[20][0]*rk[15][2])-(Otk[20][2]*
          rk[15][0]))+((wk[20][2]*Wkrpk[20][0])-(wk[20][0]*Wkrpk[20][2]))));
        Atk[20][2] = (((AiOiWi[20][0]*s20)+(AiOiWi[20][2]*c20))+(((Otk[19][1]*
          rk[15][0])-(Otk[20][0]*rk[15][1]))+((wk[20][0]*Wkrpk[20][1])-(
          wk[20][1]*Wkrpk[20][0]))));
        AiOiWi[21][0] = (Atk[20][0]+(((Otk[19][1]*ri[16][2])-(Otk[20][2]*
          ri[16][1]))+((Wirk[21][2]*wk[20][1])-(Wirk[21][1]*wk[20][2]))));
        AiOiWi[21][1] = (Atk[20][1]+(((Otk[20][2]*ri[16][0])-(Otk[20][0]*
          ri[16][2]))+((Wirk[21][0]*wk[20][2])-(Wirk[21][2]*wk[20][0]))));
        AiOiWi[21][2] = (Atk[20][2]+(((Otk[20][0]*ri[16][1])-(Otk[19][1]*
          ri[16][0]))+((Wirk[21][1]*wk[20][0])-(Wirk[21][0]*wk[20][1]))));
        Atk[21][0] = (((AiOiWi[21][0]*c21)+(AiOiWi[21][1]*s21))+(((Otk[20][2]*
          rk[16][1])-(Otk[21][1]*rk[16][2]))+((wk[21][1]*Wkrpk[21][2])-(
          wk[21][2]*Wkrpk[21][1]))));
        Atk[21][1] = (((AiOiWi[21][1]*c21)-(AiOiWi[21][0]*s21))+(((Otk[21][0]*
          rk[16][2])-(Otk[20][2]*rk[16][0]))+((wk[21][2]*Wkrpk[21][0])-(
          wk[21][0]*Wkrpk[21][2]))));
        Atk[21][2] = (AiOiWi[21][2]+(((Otk[21][1]*rk[16][0])-(Otk[21][0]*
          rk[16][1]))+((wk[21][0]*Wkrpk[21][1])-(wk[21][1]*Wkrpk[21][0]))));
        AiOiWi[22][0] = (Atk[5][0]+((u[4]*Wirk[22][2])-(u[5]*Wirk[22][1])));
        AiOiWi[22][1] = (Atk[5][1]+((u[5]*Wirk[22][0])-(u[3]*Wirk[22][2])));
        AiOiWi[22][2] = (Atk[5][2]+((u[3]*Wirk[22][1])-(u[4]*Wirk[22][0])));
        Atk[22][0] = (((AiOiWi[22][0]*c22)-(AiOiWi[22][2]*s22))+((Otk[22][2]*
          rk[17][1])+((wk[22][1]*Wkrpk[22][2])-(wk[22][2]*Wkrpk[22][1]))));
        Atk[22][1] = (AiOiWi[22][1]+(((Otk[22][0]*rk[17][2])-(Otk[22][2]*
          rk[17][0]))+((wk[22][2]*Wkrpk[22][0])-(wk[22][0]*Wkrpk[22][2]))));
        Atk[22][2] = (((AiOiWi[22][0]*s22)+(AiOiWi[22][2]*c22))+(((wk[22][0]*
          Wkrpk[22][1])-(wk[22][1]*Wkrpk[22][0]))-(Otk[22][0]*rk[17][1])));
        AiOiWi[23][0] = (Atk[22][0]+(((Wirk[23][2]*wk[22][1])-(Wirk[23][1]*
          wk[22][2]))-(Otk[22][2]*ri[18][1])));
        AiOiWi[23][1] = (Atk[22][1]+(((Otk[22][2]*ri[18][0])-(Otk[22][0]*
          ri[18][2]))+((Wirk[23][0]*wk[22][2])-(Wirk[23][2]*wk[22][0]))));
        AiOiWi[23][2] = (Atk[22][2]+((Otk[22][0]*ri[18][1])+((Wirk[23][1]*
          wk[22][0])-(Wirk[23][0]*wk[22][1]))));
        Atk[23][0] = (AiOiWi[23][0]+(((Otk[23][2]*rk[18][1])-(Otk[23][1]*
          rk[18][2]))+((wk[23][1]*Wkrpk[23][2])-(wk[23][2]*Wkrpk[23][1]))));
        Atk[23][1] = (((AiOiWi[23][1]*c23)+(AiOiWi[23][2]*s23))+(((Otk[22][0]*
          rk[18][2])-(Otk[23][2]*rk[18][0]))+((wk[23][2]*Wkrpk[23][0])-(
          wk[23][0]*Wkrpk[23][2]))));
        Atk[23][2] = (((AiOiWi[23][2]*c23)-(AiOiWi[23][1]*s23))+(((Otk[23][1]*
          rk[18][0])-(Otk[22][0]*rk[18][1]))+((wk[23][0]*Wkrpk[23][1])-(
          wk[23][1]*Wkrpk[23][0]))));
        AiOiWi[24][0] = (Atk[23][0]+(((Otk[23][1]*ri[19][2])-(Otk[23][2]*
          ri[19][1]))+((Wirk[24][2]*wk[23][1])-(Wirk[24][1]*wk[23][2]))));
        AiOiWi[24][1] = (Atk[23][1]+(((Otk[23][2]*ri[19][0])-(Otk[22][0]*
          ri[19][2]))+((Wirk[24][0]*wk[23][2])-(Wirk[24][2]*wk[23][0]))));
        AiOiWi[24][2] = (Atk[23][2]+(((Otk[22][0]*ri[19][1])-(Otk[23][1]*
          ri[19][0]))+((Wirk[24][1]*wk[23][0])-(Wirk[24][0]*wk[23][1]))));
        Atk[24][0] = (((AiOiWi[24][0]*c24)-(AiOiWi[24][2]*s24))+(((Otk[24][2]*
          rk[19][1])-(Otk[23][1]*rk[19][2]))+((wk[24][1]*Wkrpk[24][2])-(
          wk[24][2]*Wkrpk[24][1]))));
        Atk[24][1] = (AiOiWi[24][1]+(((Otk[24][0]*rk[19][2])-(Otk[24][2]*
          rk[19][0]))+((wk[24][2]*Wkrpk[24][0])-(wk[24][0]*Wkrpk[24][2]))));
        Atk[24][2] = (((AiOiWi[24][0]*s24)+(AiOiWi[24][2]*c24))+(((Otk[23][1]*
          rk[19][0])-(Otk[24][0]*rk[19][1]))+((wk[24][0]*Wkrpk[24][1])-(
          wk[24][1]*Wkrpk[24][0]))));
        AiOiWi[25][0] = (Atk[24][0]+(((Otk[23][1]*ri[20][2])-(Otk[24][2]*
          ri[20][1]))+((Wirk[25][2]*wk[24][1])-(Wirk[25][1]*wk[24][2]))));
        AiOiWi[25][1] = (Atk[24][1]+(((Otk[24][2]*ri[20][0])-(Otk[24][0]*
          ri[20][2]))+((Wirk[25][0]*wk[24][2])-(Wirk[25][2]*wk[24][0]))));
        AiOiWi[25][2] = (Atk[24][2]+(((Otk[24][0]*ri[20][1])-(Otk[23][1]*
          ri[20][0]))+((Wirk[25][1]*wk[24][0])-(Wirk[25][0]*wk[24][1]))));
        Atk[25][0] = (((AiOiWi[25][0]*c25)+(AiOiWi[25][1]*s25))+(((Otk[24][2]*
          rk[20][1])-(Otk[25][1]*rk[20][2]))+((wk[25][1]*Wkrpk[25][2])-(
          wk[25][2]*Wkrpk[25][1]))));
        Atk[25][1] = (((AiOiWi[25][1]*c25)-(AiOiWi[25][0]*s25))+(((Otk[25][0]*
          rk[20][2])-(Otk[24][2]*rk[20][0]))+((wk[25][2]*Wkrpk[25][0])-(
          wk[25][0]*Wkrpk[25][2]))));
        Atk[25][2] = (AiOiWi[25][2]+(((Otk[25][1]*rk[20][0])-(Otk[25][0]*
          rk[20][1]))+((wk[25][0]*Wkrpk[25][1])-(wk[25][1]*Wkrpk[25][0]))));
        inerflg = 1;
    }
/*
 Used 0.01 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  543 adds/subtracts/negates
                    622 multiplies
                      0 divides
                    163 assignments
*/
}

void Jimmy::sddofs0(void)
{

/*
Compute effect of all applied loads
*/
    if (fs0flg == 0) {
        sddoltau();
        sddoiner();
/*
Compute Fstar (forces)
*/
        Fstar[5][0] = ((mk[0]*(Atk[5][0]+(9.81*Cik[3][2][0])))-ufk[0][0]);
        Fstar[5][1] = ((mk[0]*(Atk[5][1]+(9.81*Cik[3][2][1])))-ufk[0][1]);
        Fstar[5][2] = ((mk[0]*(Atk[5][2]+(9.81*Cik[3][2][2])))-ufk[0][2]);
        Fstar[6][0] = ((mk[1]*(Atk[6][0]-gk[6][0]))-ufk[1][0]);
        Fstar[6][1] = ((mk[1]*(Atk[6][1]-gk[6][1]))-ufk[1][1]);
        Fstar[6][2] = ((mk[1]*(Atk[6][2]+(9.81*Cik[3][2][2])))-ufk[1][2]);
        Fstar[7][0] = ((mk[2]*(Atk[7][0]-gk[7][0]))-ufk[2][0]);
        Fstar[7][1] = ((mk[2]*(Atk[7][1]-gk[6][1]))-ufk[2][1]);
        Fstar[7][2] = ((mk[2]*(Atk[7][2]-gk[7][2]))-ufk[2][2]);
        Fstar[8][0] = ((mk[3]*(Atk[8][0]-gk[7][0]))-ufk[3][0]);
        Fstar[8][1] = ((mk[3]*(Atk[8][1]-gk[8][1]))-ufk[3][1]);
        Fstar[8][2] = ((mk[3]*(Atk[8][2]-gk[8][2]))-ufk[3][2]);
        Fstar[9][0] = ((mk[4]*(Atk[9][0]-gk[9][0]))-ufk[4][0]);
        Fstar[9][1] = ((mk[4]*(Atk[9][1]-gk[8][1]))-ufk[4][1]);
        Fstar[9][2] = ((mk[4]*(Atk[9][2]-gk[9][2]))-ufk[4][2]);
        Fstar[10][0] = ((mk[5]*(Atk[10][0]-gk[10][0]))-ufk[5][0]);
        Fstar[10][1] = ((mk[5]*(Atk[10][1]-gk[8][1]))-ufk[5][1]);
        Fstar[10][2] = ((mk[5]*(Atk[10][2]-gk[10][2]))-ufk[5][2]);
        Fstar[11][0] = ((mk[6]*(Atk[11][0]-gk[10][0]))-ufk[6][0]);
        Fstar[11][1] = ((mk[6]*(Atk[11][1]-gk[11][1]))-ufk[6][1]);
        Fstar[11][2] = ((mk[6]*(Atk[11][2]-gk[11][2]))-ufk[6][2]);
        Fstar[12][0] = ((mk[7]*(Atk[12][0]-gk[12][0]))-ufk[7][0]);
        Fstar[12][1] = ((mk[7]*(Atk[12][1]-gk[12][1]))-ufk[7][1]);
        Fstar[12][2] = ((mk[7]*(Atk[12][2]+(9.81*Cik[3][2][2])))-ufk[7][2]);
        Fstar[13][0] = ((mk[8]*(Atk[13][0]-gk[13][0]))-ufk[8][0]);
        Fstar[13][1] = ((mk[8]*(Atk[13][1]-gk[12][1]))-ufk[8][1]);
        Fstar[13][2] = ((mk[8]*(Atk[13][2]-gk[13][2]))-ufk[8][2]);
        Fstar[14][0] = ((mk[9]*(Atk[14][0]-gk[13][0]))-ufk[9][0]);
        Fstar[14][1] = ((mk[9]*(Atk[14][1]-gk[14][1]))-ufk[9][1]);
        Fstar[14][2] = ((mk[9]*(Atk[14][2]-gk[14][2]))-ufk[9][2]);
        Fstar[15][0] = ((mk[10]*(Atk[15][0]-gk[15][0]))-ufk[10][0]);
        Fstar[15][1] = ((mk[10]*(Atk[15][1]-gk[14][1]))-ufk[10][1]);
        Fstar[15][2] = ((mk[10]*(Atk[15][2]-gk[15][2]))-ufk[10][2]);
        Fstar[16][0] = ((mk[11]*(Atk[16][0]-gk[16][0]))-ufk[11][0]);
        Fstar[16][1] = ((mk[11]*(Atk[16][1]-gk[14][1]))-ufk[11][1]);
        Fstar[16][2] = ((mk[11]*(Atk[16][2]-gk[16][2]))-ufk[11][2]);
        Fstar[17][0] = ((mk[12]*(Atk[17][0]-gk[16][0]))-ufk[12][0]);
        Fstar[17][1] = ((mk[12]*(Atk[17][1]-gk[17][1]))-ufk[12][1]);
        Fstar[17][2] = ((mk[12]*(Atk[17][2]-gk[17][2]))-ufk[12][2]);
        Fstar[18][0] = ((mk[13]*(Atk[18][0]-gk[18][0]))-ufk[13][0]);
        Fstar[18][1] = ((mk[13]*(Atk[18][1]+(9.81*Cik[3][2][1])))-ufk[13][1]);
        Fstar[18][2] = ((mk[13]*(Atk[18][2]-gk[18][2]))-ufk[13][2]);
        Fstar[19][0] = ((mk[14]*(Atk[19][0]-gk[18][0]))-ufk[14][0]);
        Fstar[19][1] = ((mk[14]*(Atk[19][1]-gk[19][1]))-ufk[14][1]);
        Fstar[19][2] = ((mk[14]*(Atk[19][2]-gk[19][2]))-ufk[14][2]);
        Fstar[20][0] = ((mk[15]*(Atk[20][0]-gk[20][0]))-ufk[15][0]);
        Fstar[20][1] = ((mk[15]*(Atk[20][1]-gk[19][1]))-ufk[15][1]);
        Fstar[20][2] = ((mk[15]*(Atk[20][2]-gk[20][2]))-ufk[15][2]);
        Fstar[21][0] = ((mk[16]*(Atk[21][0]-gk[21][0]))-ufk[16][0]);
        Fstar[21][1] = ((mk[16]*(Atk[21][1]-gk[21][1]))-ufk[16][1]);
        Fstar[21][2] = ((mk[16]*(Atk[21][2]-gk[20][2]))-ufk[16][2]);
        Fstar[22][0] = ((mk[17]*(Atk[22][0]-gk[22][0]))-ufk[17][0]);
        Fstar[22][1] = ((mk[17]*(Atk[22][1]+(9.81*Cik[3][2][1])))-ufk[17][1]);
        Fstar[22][2] = ((mk[17]*(Atk[22][2]-gk[22][2]))-ufk[17][2]);
        Fstar[23][0] = ((mk[18]*(Atk[23][0]-gk[22][0]))-ufk[18][0]);
        Fstar[23][1] = ((mk[18]*(Atk[23][1]-gk[23][1]))-ufk[18][1]);
        Fstar[23][2] = ((mk[18]*(Atk[23][2]-gk[23][2]))-ufk[18][2]);
        Fstar[24][0] = ((mk[19]*(Atk[24][0]-gk[24][0]))-ufk[19][0]);
        Fstar[24][1] = ((mk[19]*(Atk[24][1]-gk[23][1]))-ufk[19][1]);
        Fstar[24][2] = ((mk[19]*(Atk[24][2]-gk[24][2]))-ufk[19][2]);
        Fstar[25][0] = ((mk[20]*(Atk[25][0]-gk[25][0]))-ufk[20][0]);
        Fstar[25][1] = ((mk[20]*(Atk[25][1]-gk[25][1]))-ufk[20][1]);
        Fstar[25][2] = ((mk[20]*(Atk[25][2]-gk[24][2]))-ufk[20][2]);
/*
Compute Tstar (torques)
*/
        Tstar[5][0] = (WkIkWk[5][0]-utk[0][0]);
        Tstar[5][1] = (WkIkWk[5][1]-utk[0][1]);
        Tstar[5][2] = (WkIkWk[5][2]-utk[0][2]);
        Tstar[6][0] = ((WkIkWk[6][0]+((ik[1][0][0]*Otk[6][0])+(ik[1][0][1]*
          Otk[6][1])))-utk[1][0]);
        Tstar[6][1] = ((WkIkWk[6][1]+((ik[1][1][0]*Otk[6][0])+(ik[1][1][1]*
          Otk[6][1])))-utk[1][1]);
        Tstar[6][2] = ((WkIkWk[6][2]+((ik[1][2][0]*Otk[6][0])+(ik[1][2][1]*
          Otk[6][1])))-utk[1][2]);
        Tstar[7][0] = ((WkIkWk[7][0]+((ik[2][0][2]*Otk[7][2])+((ik[2][0][0]*
          Otk[7][0])+(ik[2][0][1]*Otk[6][1]))))-utk[2][0]);
        Tstar[7][1] = ((WkIkWk[7][1]+((ik[2][1][2]*Otk[7][2])+((ik[2][1][0]*
          Otk[7][0])+(ik[2][1][1]*Otk[6][1]))))-utk[2][1]);
        Tstar[7][2] = ((WkIkWk[7][2]+((ik[2][2][2]*Otk[7][2])+((ik[2][2][0]*
          Otk[7][0])+(ik[2][2][1]*Otk[6][1]))))-utk[2][2]);
        Tstar[8][0] = ((WkIkWk[8][0]+((ik[3][0][2]*Otk[8][2])+((ik[3][0][0]*
          Otk[7][0])+(ik[3][0][1]*Otk[8][1]))))-utk[3][0]);
        Tstar[8][1] = ((WkIkWk[8][1]+((ik[3][1][2]*Otk[8][2])+((ik[3][1][0]*
          Otk[7][0])+(ik[3][1][1]*Otk[8][1]))))-utk[3][1]);
        Tstar[8][2] = ((WkIkWk[8][2]+((ik[3][2][2]*Otk[8][2])+((ik[3][2][0]*
          Otk[7][0])+(ik[3][2][1]*Otk[8][1]))))-utk[3][2]);
        Tstar[9][0] = ((WkIkWk[9][0]+((ik[4][0][2]*Otk[9][2])+((ik[4][0][0]*
          Otk[9][0])+(ik[4][0][1]*Otk[8][1]))))-utk[4][0]);
        Tstar[9][1] = ((WkIkWk[9][1]+((ik[4][1][2]*Otk[9][2])+((ik[4][1][0]*
          Otk[9][0])+(ik[4][1][1]*Otk[8][1]))))-utk[4][1]);
        Tstar[9][2] = ((WkIkWk[9][2]+((ik[4][2][2]*Otk[9][2])+((ik[4][2][0]*
          Otk[9][0])+(ik[4][2][1]*Otk[8][1]))))-utk[4][2]);
        Tstar[10][0] = ((WkIkWk[10][0]+((ik[5][0][2]*Otk[10][2])+((ik[5][0][0]*
          Otk[10][0])+(ik[5][0][1]*Otk[8][1]))))-utk[5][0]);
        Tstar[10][1] = ((WkIkWk[10][1]+((ik[5][1][2]*Otk[10][2])+((ik[5][1][0]*
          Otk[10][0])+(ik[5][1][1]*Otk[8][1]))))-utk[5][1]);
        Tstar[10][2] = ((WkIkWk[10][2]+((ik[5][2][2]*Otk[10][2])+((ik[5][2][0]*
          Otk[10][0])+(ik[5][2][1]*Otk[8][1]))))-utk[5][2]);
        Tstar[11][0] = ((WkIkWk[11][0]+((ik[6][0][2]*Otk[11][2])+((ik[6][0][0]*
          Otk[10][0])+(ik[6][0][1]*Otk[11][1]))))-utk[6][0]);
        Tstar[11][1] = ((WkIkWk[11][1]+((ik[6][1][2]*Otk[11][2])+((ik[6][1][0]*
          Otk[10][0])+(ik[6][1][1]*Otk[11][1]))))-utk[6][1]);
        Tstar[11][2] = ((WkIkWk[11][2]+((ik[6][2][2]*Otk[11][2])+((ik[6][2][0]*
          Otk[10][0])+(ik[6][2][1]*Otk[11][1]))))-utk[6][2]);
        Tstar[12][0] = ((WkIkWk[12][0]+((ik[7][0][0]*Otk[12][0])+(ik[7][0][1]*
          Otk[12][1])))-utk[7][0]);
        Tstar[12][1] = ((WkIkWk[12][1]+((ik[7][1][0]*Otk[12][0])+(ik[7][1][1]*
          Otk[12][1])))-utk[7][1]);
        Tstar[12][2] = ((WkIkWk[12][2]+((ik[7][2][0]*Otk[12][0])+(ik[7][2][1]*
          Otk[12][1])))-utk[7][2]);
        Tstar[13][0] = ((WkIkWk[13][0]+((ik[8][0][2]*Otk[13][2])+((ik[8][0][0]*
          Otk[13][0])+(ik[8][0][1]*Otk[12][1]))))-utk[8][0]);
        Tstar[13][1] = ((WkIkWk[13][1]+((ik[8][1][2]*Otk[13][2])+((ik[8][1][0]*
          Otk[13][0])+(ik[8][1][1]*Otk[12][1]))))-utk[8][1]);
        Tstar[13][2] = ((WkIkWk[13][2]+((ik[8][2][2]*Otk[13][2])+((ik[8][2][0]*
          Otk[13][0])+(ik[8][2][1]*Otk[12][1]))))-utk[8][2]);
        Tstar[14][0] = ((WkIkWk[14][0]+((ik[9][0][2]*Otk[14][2])+((ik[9][0][0]*
          Otk[13][0])+(ik[9][0][1]*Otk[14][1]))))-utk[9][0]);
        Tstar[14][1] = ((WkIkWk[14][1]+((ik[9][1][2]*Otk[14][2])+((ik[9][1][0]*
          Otk[13][0])+(ik[9][1][1]*Otk[14][1]))))-utk[9][1]);
        Tstar[14][2] = ((WkIkWk[14][2]+((ik[9][2][2]*Otk[14][2])+((ik[9][2][0]*
          Otk[13][0])+(ik[9][2][1]*Otk[14][1]))))-utk[9][2]);
        Tstar[15][0] = ((WkIkWk[15][0]+((ik[10][0][2]*Otk[15][2])+((ik[10][0][0]
          *Otk[15][0])+(ik[10][0][1]*Otk[14][1]))))-utk[10][0]);
        Tstar[15][1] = ((WkIkWk[15][1]+((ik[10][1][2]*Otk[15][2])+((ik[10][1][0]
          *Otk[15][0])+(ik[10][1][1]*Otk[14][1]))))-utk[10][1]);
        Tstar[15][2] = ((WkIkWk[15][2]+((ik[10][2][2]*Otk[15][2])+((ik[10][2][0]
          *Otk[15][0])+(ik[10][2][1]*Otk[14][1]))))-utk[10][2]);
        Tstar[16][0] = ((WkIkWk[16][0]+((ik[11][0][2]*Otk[16][2])+((ik[11][0][0]
          *Otk[16][0])+(ik[11][0][1]*Otk[14][1]))))-utk[11][0]);
        Tstar[16][1] = ((WkIkWk[16][1]+((ik[11][1][2]*Otk[16][2])+((ik[11][1][0]
          *Otk[16][0])+(ik[11][1][1]*Otk[14][1]))))-utk[11][1]);
        Tstar[16][2] = ((WkIkWk[16][2]+((ik[11][2][2]*Otk[16][2])+((ik[11][2][0]
          *Otk[16][0])+(ik[11][2][1]*Otk[14][1]))))-utk[11][2]);
        Tstar[17][0] = ((WkIkWk[17][0]+((ik[12][0][2]*Otk[17][2])+((ik[12][0][0]
          *Otk[16][0])+(ik[12][0][1]*Otk[17][1]))))-utk[12][0]);
        Tstar[17][1] = ((WkIkWk[17][1]+((ik[12][1][2]*Otk[17][2])+((ik[12][1][0]
          *Otk[16][0])+(ik[12][1][1]*Otk[17][1]))))-utk[12][1]);
        Tstar[17][2] = ((WkIkWk[17][2]+((ik[12][2][2]*Otk[17][2])+((ik[12][2][0]
          *Otk[16][0])+(ik[12][2][1]*Otk[17][1]))))-utk[12][2]);
        Tstar[18][0] = ((WkIkWk[18][0]+((ik[13][0][0]*Otk[18][0])+(ik[13][0][2]*
          Otk[18][2])))-utk[13][0]);
        Tstar[18][1] = ((WkIkWk[18][1]+((ik[13][1][0]*Otk[18][0])+(ik[13][1][2]*
          Otk[18][2])))-utk[13][1]);
        Tstar[18][2] = ((WkIkWk[18][2]+((ik[13][2][0]*Otk[18][0])+(ik[13][2][2]*
          Otk[18][2])))-utk[13][2]);
        Tstar[19][0] = ((WkIkWk[19][0]+((ik[14][0][2]*Otk[19][2])+((ik[14][0][0]
          *Otk[18][0])+(ik[14][0][1]*Otk[19][1]))))-utk[14][0]);
        Tstar[19][1] = ((WkIkWk[19][1]+((ik[14][1][2]*Otk[19][2])+((ik[14][1][0]
          *Otk[18][0])+(ik[14][1][1]*Otk[19][1]))))-utk[14][1]);
        Tstar[19][2] = ((WkIkWk[19][2]+((ik[14][2][2]*Otk[19][2])+((ik[14][2][0]
          *Otk[18][0])+(ik[14][2][1]*Otk[19][1]))))-utk[14][2]);
        Tstar[20][0] = ((WkIkWk[20][0]+((ik[15][0][2]*Otk[20][2])+((ik[15][0][0]
          *Otk[20][0])+(ik[15][0][1]*Otk[19][1]))))-utk[15][0]);
        Tstar[20][1] = ((WkIkWk[20][1]+((ik[15][1][2]*Otk[20][2])+((ik[15][1][0]
          *Otk[20][0])+(ik[15][1][1]*Otk[19][1]))))-utk[15][1]);
        Tstar[20][2] = ((WkIkWk[20][2]+((ik[15][2][2]*Otk[20][2])+((ik[15][2][0]
          *Otk[20][0])+(ik[15][2][1]*Otk[19][1]))))-utk[15][2]);
        Tstar[21][0] = ((WkIkWk[21][0]+((ik[16][0][2]*Otk[20][2])+((ik[16][0][0]
          *Otk[21][0])+(ik[16][0][1]*Otk[21][1]))))-utk[16][0]);
        Tstar[21][1] = ((WkIkWk[21][1]+((ik[16][1][2]*Otk[20][2])+((ik[16][1][0]
          *Otk[21][0])+(ik[16][1][1]*Otk[21][1]))))-utk[16][1]);
        Tstar[21][2] = ((WkIkWk[21][2]+((ik[16][2][2]*Otk[20][2])+((ik[16][2][0]
          *Otk[21][0])+(ik[16][2][1]*Otk[21][1]))))-utk[16][2]);
        Tstar[22][0] = ((WkIkWk[22][0]+((ik[17][0][0]*Otk[22][0])+(ik[17][0][2]*
          Otk[22][2])))-utk[17][0]);
        Tstar[22][1] = ((WkIkWk[22][1]+((ik[17][1][0]*Otk[22][0])+(ik[17][1][2]*
          Otk[22][2])))-utk[17][1]);
        Tstar[22][2] = ((WkIkWk[22][2]+((ik[17][2][0]*Otk[22][0])+(ik[17][2][2]*
          Otk[22][2])))-utk[17][2]);
        Tstar[23][0] = ((WkIkWk[23][0]+((ik[18][0][2]*Otk[23][2])+((ik[18][0][0]
          *Otk[22][0])+(ik[18][0][1]*Otk[23][1]))))-utk[18][0]);
        Tstar[23][1] = ((WkIkWk[23][1]+((ik[18][1][2]*Otk[23][2])+((ik[18][1][0]
          *Otk[22][0])+(ik[18][1][1]*Otk[23][1]))))-utk[18][1]);
        Tstar[23][2] = ((WkIkWk[23][2]+((ik[18][2][2]*Otk[23][2])+((ik[18][2][0]
          *Otk[22][0])+(ik[18][2][1]*Otk[23][1]))))-utk[18][2]);
        Tstar[24][0] = ((WkIkWk[24][0]+((ik[19][0][2]*Otk[24][2])+((ik[19][0][0]
          *Otk[24][0])+(ik[19][0][1]*Otk[23][1]))))-utk[19][0]);
        Tstar[24][1] = ((WkIkWk[24][1]+((ik[19][1][2]*Otk[24][2])+((ik[19][1][0]
          *Otk[24][0])+(ik[19][1][1]*Otk[23][1]))))-utk[19][1]);
        Tstar[24][2] = ((WkIkWk[24][2]+((ik[19][2][2]*Otk[24][2])+((ik[19][2][0]
          *Otk[24][0])+(ik[19][2][1]*Otk[23][1]))))-utk[19][2]);
        Tstar[25][0] = ((WkIkWk[25][0]+((ik[20][0][2]*Otk[24][2])+((ik[20][0][0]
          *Otk[25][0])+(ik[20][0][1]*Otk[25][1]))))-utk[20][0]);
        Tstar[25][1] = ((WkIkWk[25][1]+((ik[20][1][2]*Otk[24][2])+((ik[20][1][0]
          *Otk[25][0])+(ik[20][1][1]*Otk[25][1]))))-utk[20][1]);
        Tstar[25][2] = ((WkIkWk[25][2]+((ik[20][2][2]*Otk[24][2])+((ik[20][2][0]
          *Otk[25][0])+(ik[20][2][1]*Otk[25][1]))))-utk[20][2]);
/*
Compute fs0 (RHS ignoring constraints)
*/
        sddovpk();
        temp[0] = (((Fstar[8][2]*Vpk[0][8][2])+((Fstar[8][0]*Vpk[0][7][0])+(
          Fstar[8][1]*Vpk[0][8][1])))+(((Fstar[7][2]*Vpk[0][7][2])+((Fstar[7][0]
          *Vpk[0][7][0])+(Fstar[7][1]*Vpk[0][6][1])))+(((Cik[3][0][2]*
          Fstar[5][2])+((Cik[3][0][0]*Fstar[5][0])+(Cik[3][0][1]*Fstar[5][1])))+
          ((Cik[3][0][2]*Fstar[6][2])+((Fstar[6][0]*Vpk[0][6][0])+(Fstar[6][1]*
          Vpk[0][6][1]))))));
        temp[1] = (((Cik[3][0][2]*Fstar[12][2])+((Fstar[12][0]*Vpk[0][12][0])+(
          Fstar[12][1]*Vpk[0][12][1])))+(((Fstar[11][2]*Vpk[0][11][2])+((
          Fstar[11][0]*Vpk[0][10][0])+(Fstar[11][1]*Vpk[0][11][1])))+(((
          Fstar[10][2]*Vpk[0][10][2])+((Fstar[10][0]*Vpk[0][10][0])+(
          Fstar[10][1]*Vpk[0][8][1])))+(((Fstar[9][2]*Vpk[0][9][2])+((
          Fstar[9][0]*Vpk[0][9][0])+(Fstar[9][1]*Vpk[0][8][1])))+temp[0]))));
        temp[2] = (((Fstar[16][2]*Vpk[0][16][2])+((Fstar[16][0]*Vpk[0][16][0])+(
          Fstar[16][1]*Vpk[0][14][1])))+(((Fstar[15][2]*Vpk[0][15][2])+((
          Fstar[15][0]*Vpk[0][15][0])+(Fstar[15][1]*Vpk[0][14][1])))+(((
          Fstar[14][2]*Vpk[0][14][2])+((Fstar[14][0]*Vpk[0][13][0])+(
          Fstar[14][1]*Vpk[0][14][1])))+(((Fstar[13][2]*Vpk[0][13][2])+((
          Fstar[13][0]*Vpk[0][13][0])+(Fstar[13][1]*Vpk[0][12][1])))+temp[1]))))
          ;
        temp[3] = (((Fstar[20][2]*Vpk[0][20][2])+((Fstar[20][0]*Vpk[0][20][0])+(
          Fstar[20][1]*Vpk[0][19][1])))+(((Fstar[19][2]*Vpk[0][19][2])+((
          Fstar[19][0]*Vpk[0][18][0])+(Fstar[19][1]*Vpk[0][19][1])))+(((
          Fstar[18][2]*Vpk[0][18][2])+((Cik[3][0][1]*Fstar[18][1])+(Fstar[18][0]
          *Vpk[0][18][0])))+(((Fstar[17][2]*Vpk[0][17][2])+((Fstar[17][0]*
          Vpk[0][16][0])+(Fstar[17][1]*Vpk[0][17][1])))+temp[2]))));
        temp[4] = (((Fstar[24][2]*Vpk[0][24][2])+((Fstar[24][0]*Vpk[0][24][0])+(
          Fstar[24][1]*Vpk[0][23][1])))+(((Fstar[23][2]*Vpk[0][23][2])+((
          Fstar[23][0]*Vpk[0][22][0])+(Fstar[23][1]*Vpk[0][23][1])))+(((
          Fstar[22][2]*Vpk[0][22][2])+((Cik[3][0][1]*Fstar[22][1])+(Fstar[22][0]
          *Vpk[0][22][0])))+(((Fstar[21][2]*Vpk[0][20][2])+((Fstar[21][0]*
          Vpk[0][21][0])+(Fstar[21][1]*Vpk[0][21][1])))+temp[3]))));
        fs0[0] = (utau[0]-(((Fstar[25][2]*Vpk[0][24][2])+((Fstar[25][0]*
          Vpk[0][25][0])+(Fstar[25][1]*Vpk[0][25][1])))+temp[4]));
        temp[0] = (((Fstar[8][2]*Vpk[1][8][2])+((Fstar[8][0]*Vpk[1][7][0])+(
          Fstar[8][1]*Vpk[1][8][1])))+(((Fstar[7][2]*Vpk[1][7][2])+((Fstar[7][0]
          *Vpk[1][7][0])+(Fstar[7][1]*Vpk[1][6][1])))+(((Cik[3][1][2]*
          Fstar[5][2])+((Cik[3][1][0]*Fstar[5][0])+(Cik[3][1][1]*Fstar[5][1])))+
          ((Cik[3][1][2]*Fstar[6][2])+((Fstar[6][0]*Vpk[1][6][0])+(Fstar[6][1]*
          Vpk[1][6][1]))))));
        temp[1] = (((Cik[3][1][2]*Fstar[12][2])+((Fstar[12][0]*Vpk[1][12][0])+(
          Fstar[12][1]*Vpk[1][12][1])))+(((Fstar[11][2]*Vpk[1][11][2])+((
          Fstar[11][0]*Vpk[1][10][0])+(Fstar[11][1]*Vpk[1][11][1])))+(((
          Fstar[10][2]*Vpk[1][10][2])+((Fstar[10][0]*Vpk[1][10][0])+(
          Fstar[10][1]*Vpk[1][8][1])))+(((Fstar[9][2]*Vpk[1][9][2])+((
          Fstar[9][0]*Vpk[1][9][0])+(Fstar[9][1]*Vpk[1][8][1])))+temp[0]))));
        temp[2] = (((Fstar[16][2]*Vpk[1][16][2])+((Fstar[16][0]*Vpk[1][16][0])+(
          Fstar[16][1]*Vpk[1][14][1])))+(((Fstar[15][2]*Vpk[1][15][2])+((
          Fstar[15][0]*Vpk[1][15][0])+(Fstar[15][1]*Vpk[1][14][1])))+(((
          Fstar[14][2]*Vpk[1][14][2])+((Fstar[14][0]*Vpk[1][13][0])+(
          Fstar[14][1]*Vpk[1][14][1])))+(((Fstar[13][2]*Vpk[1][13][2])+((
          Fstar[13][0]*Vpk[1][13][0])+(Fstar[13][1]*Vpk[1][12][1])))+temp[1]))))
          ;
        temp[3] = (((Fstar[20][2]*Vpk[1][20][2])+((Fstar[20][0]*Vpk[1][20][0])+(
          Fstar[20][1]*Vpk[1][19][1])))+(((Fstar[19][2]*Vpk[1][19][2])+((
          Fstar[19][0]*Vpk[1][18][0])+(Fstar[19][1]*Vpk[1][19][1])))+(((
          Fstar[18][2]*Vpk[1][18][2])+((Cik[3][1][1]*Fstar[18][1])+(Fstar[18][0]
          *Vpk[1][18][0])))+(((Fstar[17][2]*Vpk[1][17][2])+((Fstar[17][0]*
          Vpk[1][16][0])+(Fstar[17][1]*Vpk[1][17][1])))+temp[2]))));
        temp[4] = (((Fstar[24][2]*Vpk[1][24][2])+((Fstar[24][0]*Vpk[1][24][0])+(
          Fstar[24][1]*Vpk[1][23][1])))+(((Fstar[23][2]*Vpk[1][23][2])+((
          Fstar[23][0]*Vpk[1][22][0])+(Fstar[23][1]*Vpk[1][23][1])))+(((
          Fstar[22][2]*Vpk[1][22][2])+((Cik[3][1][1]*Fstar[22][1])+(Fstar[22][0]
          *Vpk[1][22][0])))+(((Fstar[21][2]*Vpk[1][20][2])+((Fstar[21][0]*
          Vpk[1][21][0])+(Fstar[21][1]*Vpk[1][21][1])))+temp[3]))));
        fs0[1] = (utau[1]-(((Fstar[25][2]*Vpk[1][24][2])+((Fstar[25][0]*
          Vpk[1][25][0])+(Fstar[25][1]*Vpk[1][25][1])))+temp[4]));
        temp[0] = (((Fstar[8][2]*Vpk[2][8][2])+((Fstar[8][0]*Vpk[2][7][0])+(
          Fstar[8][1]*Vpk[2][8][1])))+(((Fstar[7][2]*Vpk[2][7][2])+((Fstar[7][0]
          *Vpk[2][7][0])+(Fstar[7][1]*Vpk[2][6][1])))+(((Cik[3][2][2]*
          Fstar[5][2])+((Cik[3][2][0]*Fstar[5][0])+(Cik[3][2][1]*Fstar[5][1])))+
          ((Cik[3][2][2]*Fstar[6][2])+((Fstar[6][0]*Vpk[2][6][0])+(Fstar[6][1]*
          Vpk[2][6][1]))))));
        temp[1] = (((Cik[3][2][2]*Fstar[12][2])+((Fstar[12][0]*Vpk[2][12][0])+(
          Fstar[12][1]*Vpk[2][12][1])))+(((Fstar[11][2]*Vpk[2][11][2])+((
          Fstar[11][0]*Vpk[2][10][0])+(Fstar[11][1]*Vpk[2][11][1])))+(((
          Fstar[10][2]*Vpk[2][10][2])+((Fstar[10][0]*Vpk[2][10][0])+(
          Fstar[10][1]*Vpk[2][8][1])))+(((Fstar[9][2]*Vpk[2][9][2])+((
          Fstar[9][0]*Vpk[2][9][0])+(Fstar[9][1]*Vpk[2][8][1])))+temp[0]))));
        temp[2] = (((Fstar[16][2]*Vpk[2][16][2])+((Fstar[16][0]*Vpk[2][16][0])+(
          Fstar[16][1]*Vpk[2][14][1])))+(((Fstar[15][2]*Vpk[2][15][2])+((
          Fstar[15][0]*Vpk[2][15][0])+(Fstar[15][1]*Vpk[2][14][1])))+(((
          Fstar[14][2]*Vpk[2][14][2])+((Fstar[14][0]*Vpk[2][13][0])+(
          Fstar[14][1]*Vpk[2][14][1])))+(((Fstar[13][2]*Vpk[2][13][2])+((
          Fstar[13][0]*Vpk[2][13][0])+(Fstar[13][1]*Vpk[2][12][1])))+temp[1]))))
          ;
        temp[3] = (((Fstar[20][2]*Vpk[2][20][2])+((Fstar[20][0]*Vpk[2][20][0])+(
          Fstar[20][1]*Vpk[2][19][1])))+(((Fstar[19][2]*Vpk[2][19][2])+((
          Fstar[19][0]*Vpk[2][18][0])+(Fstar[19][1]*Vpk[2][19][1])))+(((
          Fstar[18][2]*Vpk[2][18][2])+((Cik[3][2][1]*Fstar[18][1])+(Fstar[18][0]
          *Vpk[2][18][0])))+(((Fstar[17][2]*Vpk[2][17][2])+((Fstar[17][0]*
          Vpk[2][16][0])+(Fstar[17][1]*Vpk[2][17][1])))+temp[2]))));
        temp[4] = (((Fstar[24][2]*Vpk[2][24][2])+((Fstar[24][0]*Vpk[2][24][0])+(
          Fstar[24][1]*Vpk[2][23][1])))+(((Fstar[23][2]*Vpk[2][23][2])+((
          Fstar[23][0]*Vpk[2][22][0])+(Fstar[23][1]*Vpk[2][23][1])))+(((
          Fstar[22][2]*Vpk[2][22][2])+((Cik[3][2][1]*Fstar[22][1])+(Fstar[22][0]
          *Vpk[2][22][0])))+(((Fstar[21][2]*Vpk[2][20][2])+((Fstar[21][0]*
          Vpk[2][21][0])+(Fstar[21][1]*Vpk[2][21][1])))+temp[3]))));
        fs0[2] = (utau[2]-(((Fstar[25][2]*Vpk[2][24][2])+((Fstar[25][0]*
          Vpk[2][25][0])+(Fstar[25][1]*Vpk[2][25][1])))+temp[4]));
        temp[0] = (((Tstar[5][0]+((Fstar[5][1]*rk[0][2])-(Fstar[5][2]*rk[0][1]))
          )+(((Fstar[6][2]*Vpk[3][6][2])+((Fstar[6][0]*Vpk[3][6][0])+(
          Fstar[6][1]*Vpk[3][6][1])))+((Tstar[6][0]*c6)-(Tstar[6][1]*s6))))+(((
          Fstar[7][2]*Vpk[3][7][2])+((Fstar[7][0]*Vpk[3][7][0])+(Fstar[7][1]*
          Vpk[3][7][1])))+((Tstar[7][2]*Wpk[3][7][2])+((Tstar[7][0]*Wpk[3][7][0]
          )-(Tstar[7][1]*s6)))));
        temp[1] = ((((Fstar[9][2]*Vpk[3][9][2])+((Fstar[9][0]*Vpk[3][9][0])+(
          Fstar[9][1]*Vpk[3][9][1])))+((Tstar[9][2]*Wpk[3][9][2])+((Tstar[9][0]*
          Wpk[3][9][0])+(Tstar[9][1]*Wpk[3][8][1]))))+((((Fstar[8][2]*
          Vpk[3][8][2])+((Fstar[8][0]*Vpk[3][8][0])+(Fstar[8][1]*Vpk[3][8][1])))
          +((Tstar[8][2]*Wpk[3][8][2])+((Tstar[8][0]*Wpk[3][7][0])+(Tstar[8][1]*
          Wpk[3][8][1]))))+temp[0]));
        temp[2] = ((((Fstar[11][2]*Vpk[3][11][2])+((Fstar[11][0]*Vpk[3][11][0])+
          (Fstar[11][1]*Vpk[3][11][1])))+((Tstar[11][2]*Wpk[3][11][2])+((
          Tstar[11][0]*Wpk[3][10][0])+(Tstar[11][1]*Wpk[3][11][1]))))+((((
          Fstar[10][2]*Vpk[3][10][2])+((Fstar[10][0]*Vpk[3][10][0])+(
          Fstar[10][1]*Vpk[3][10][1])))+((Tstar[10][2]*Wpk[3][10][2])+((
          Tstar[10][0]*Wpk[3][10][0])+(Tstar[10][1]*Wpk[3][8][1]))))+temp[1]));
        temp[3] = ((((Fstar[13][2]*Vpk[3][13][2])+((Fstar[13][0]*Vpk[3][13][0])+
          (Fstar[13][1]*Vpk[3][13][1])))+((Tstar[13][2]*Wpk[3][13][2])+((
          Tstar[13][0]*Wpk[3][13][0])-(Tstar[13][1]*s12))))+((((Fstar[12][2]*
          Vpk[3][12][2])+((Fstar[12][0]*Vpk[3][12][0])+(Fstar[12][1]*
          Vpk[3][12][1])))+((Tstar[12][0]*c12)-(Tstar[12][1]*s12)))+temp[2]));
        temp[4] = ((((Fstar[15][2]*Vpk[3][15][2])+((Fstar[15][0]*Vpk[3][15][0])+
          (Fstar[15][1]*Vpk[3][15][1])))+((Tstar[15][2]*Wpk[3][15][2])+((
          Tstar[15][0]*Wpk[3][15][0])+(Tstar[15][1]*Wpk[3][14][1]))))+((((
          Fstar[14][2]*Vpk[3][14][2])+((Fstar[14][0]*Vpk[3][14][0])+(
          Fstar[14][1]*Vpk[3][14][1])))+((Tstar[14][2]*Wpk[3][14][2])+((
          Tstar[14][0]*Wpk[3][13][0])+(Tstar[14][1]*Wpk[3][14][1]))))+temp[3]));
        temp[5] = ((((Fstar[17][2]*Vpk[3][17][2])+((Fstar[17][0]*Vpk[3][17][0])+
          (Fstar[17][1]*Vpk[3][17][1])))+((Tstar[17][2]*Wpk[3][17][2])+((
          Tstar[17][0]*Wpk[3][16][0])+(Tstar[17][1]*Wpk[3][17][1]))))+((((
          Fstar[16][2]*Vpk[3][16][2])+((Fstar[16][0]*Vpk[3][16][0])+(
          Fstar[16][1]*Vpk[3][16][1])))+((Tstar[16][2]*Wpk[3][16][2])+((
          Tstar[16][0]*Wpk[3][16][0])+(Tstar[16][1]*Wpk[3][14][1]))))+temp[4]));
        temp[6] = ((((Fstar[19][2]*Vpk[3][19][2])+((Fstar[19][0]*Vpk[3][19][0])+
          (Fstar[19][1]*Vpk[3][19][1])))+((Tstar[19][2]*Wpk[3][19][2])+((
          Tstar[19][0]*c18)+(Tstar[19][1]*Wpk[3][19][1]))))+((((Fstar[18][2]*
          Vpk[3][18][2])+((Fstar[18][0]*Vpk[3][18][0])+(Fstar[18][1]*
          Vpk[3][18][1])))+((Tstar[18][0]*c18)+(Tstar[18][2]*s18)))+temp[5]));
        temp[7] = ((((Fstar[21][2]*Vpk[3][21][2])+((Fstar[21][0]*Vpk[3][21][0])+
          (Fstar[21][1]*Vpk[3][21][1])))+((Tstar[21][2]*Wpk[3][20][2])+((
          Tstar[21][0]*Wpk[3][21][0])+(Tstar[21][1]*Wpk[3][21][1]))))+((((
          Fstar[20][2]*Vpk[3][20][2])+((Fstar[20][0]*Vpk[3][20][0])+(
          Fstar[20][1]*Vpk[3][20][1])))+((Tstar[20][2]*Wpk[3][20][2])+((
          Tstar[20][0]*Wpk[3][20][0])+(Tstar[20][1]*Wpk[3][19][1]))))+temp[6]));
        temp[8] = ((((Fstar[23][2]*Vpk[3][23][2])+((Fstar[23][0]*Vpk[3][23][0])+
          (Fstar[23][1]*Vpk[3][23][1])))+((Tstar[23][2]*Wpk[3][23][2])+((
          Tstar[23][0]*c22)+(Tstar[23][1]*Wpk[3][23][1]))))+((((Fstar[22][2]*
          Vpk[3][22][2])+((Fstar[22][0]*Vpk[3][22][0])+(Fstar[22][1]*
          Vpk[3][22][1])))+((Tstar[22][0]*c22)+(Tstar[22][2]*s22)))+temp[7]));
        fs0[3] = (utau[3]-((((Fstar[25][2]*Vpk[3][25][2])+((Fstar[25][0]*
          Vpk[3][25][0])+(Fstar[25][1]*Vpk[3][25][1])))+((Tstar[25][2]*
          Wpk[3][24][2])+((Tstar[25][0]*Wpk[3][25][0])+(Tstar[25][1]*
          Wpk[3][25][1]))))+((((Fstar[24][2]*Vpk[3][24][2])+((Fstar[24][0]*
          Vpk[3][24][0])+(Fstar[24][1]*Vpk[3][24][1])))+((Tstar[24][2]*
          Wpk[3][24][2])+((Tstar[24][0]*Wpk[3][24][0])+(Tstar[24][1]*
          Wpk[3][23][1]))))+temp[8])));
        temp[0] = (((Tstar[5][1]+((Fstar[5][2]*rk[0][0])-(Fstar[5][0]*rk[0][2]))
          )+(((Fstar[6][2]*Vpk[4][6][2])+((Fstar[6][0]*Vpk[4][6][0])+(
          Fstar[6][1]*Vpk[4][6][1])))+((Tstar[6][0]*s6)+(Tstar[6][1]*c6))))+(((
          Fstar[7][2]*Vpk[4][7][2])+((Fstar[7][0]*Vpk[4][7][0])+(Fstar[7][1]*
          Vpk[4][7][1])))+((Tstar[7][2]*Wpk[4][7][2])+((Tstar[7][0]*Wpk[4][7][0]
          )+(Tstar[7][1]*c6)))));
        temp[1] = ((((Fstar[9][2]*Vpk[4][9][2])+((Fstar[9][0]*Vpk[4][9][0])+(
          Fstar[9][1]*Vpk[4][9][1])))+((Tstar[9][2]*Wpk[4][9][2])+((Tstar[9][0]*
          Wpk[4][9][0])+(Tstar[9][1]*Wpk[4][8][1]))))+((((Fstar[8][2]*
          Vpk[4][8][2])+((Fstar[8][0]*Vpk[4][8][0])+(Fstar[8][1]*Vpk[4][8][1])))
          +((Tstar[8][2]*Wpk[4][8][2])+((Tstar[8][0]*Wpk[4][7][0])+(Tstar[8][1]*
          Wpk[4][8][1]))))+temp[0]));
        temp[2] = ((((Fstar[11][2]*Vpk[4][11][2])+((Fstar[11][0]*Vpk[4][11][0])+
          (Fstar[11][1]*Vpk[4][11][1])))+((Tstar[11][2]*Wpk[4][11][2])+((
          Tstar[11][0]*Wpk[4][10][0])+(Tstar[11][1]*Wpk[4][11][1]))))+((((
          Fstar[10][2]*Vpk[4][10][2])+((Fstar[10][0]*Vpk[4][10][0])+(
          Fstar[10][1]*Vpk[4][10][1])))+((Tstar[10][2]*Wpk[4][10][2])+((
          Tstar[10][0]*Wpk[4][10][0])+(Tstar[10][1]*Wpk[4][8][1]))))+temp[1]));
        temp[3] = ((((Fstar[13][2]*Vpk[4][13][2])+((Fstar[13][0]*Vpk[4][13][0])+
          (Fstar[13][1]*Vpk[4][13][1])))+((Tstar[13][2]*Wpk[4][13][2])+((
          Tstar[13][0]*Wpk[4][13][0])+(Tstar[13][1]*c12))))+((((Fstar[12][2]*
          Vpk[4][12][2])+((Fstar[12][0]*Vpk[4][12][0])+(Fstar[12][1]*
          Vpk[4][12][1])))+((Tstar[12][0]*s12)+(Tstar[12][1]*c12)))+temp[2]));
        temp[4] = ((((Fstar[15][2]*Vpk[4][15][2])+((Fstar[15][0]*Vpk[4][15][0])+
          (Fstar[15][1]*Vpk[4][15][1])))+((Tstar[15][2]*Wpk[4][15][2])+((
          Tstar[15][0]*Wpk[4][15][0])+(Tstar[15][1]*Wpk[4][14][1]))))+((((
          Fstar[14][2]*Vpk[4][14][2])+((Fstar[14][0]*Vpk[4][14][0])+(
          Fstar[14][1]*Vpk[4][14][1])))+((Tstar[14][2]*Wpk[4][14][2])+((
          Tstar[14][0]*Wpk[4][13][0])+(Tstar[14][1]*Wpk[4][14][1]))))+temp[3]));
        temp[5] = ((((Fstar[17][2]*Vpk[4][17][2])+((Fstar[17][0]*Vpk[4][17][0])+
          (Fstar[17][1]*Vpk[4][17][1])))+((Tstar[17][2]*Wpk[4][17][2])+((
          Tstar[17][0]*Wpk[4][16][0])+(Tstar[17][1]*Wpk[4][17][1]))))+((((
          Fstar[16][2]*Vpk[4][16][2])+((Fstar[16][0]*Vpk[4][16][0])+(
          Fstar[16][1]*Vpk[4][16][1])))+((Tstar[16][2]*Wpk[4][16][2])+((
          Tstar[16][0]*Wpk[4][16][0])+(Tstar[16][1]*Wpk[4][14][1]))))+temp[4]));
        temp[6] = ((((Fstar[20][2]*Vpk[4][20][2])+((Fstar[20][0]*Vpk[4][20][0])+
          (Fstar[20][1]*Vpk[4][20][1])))+((Tstar[20][2]*Wpk[4][20][2])+((
          Tstar[20][0]*Wpk[4][20][0])+(Tstar[20][1]*c19))))+(((Tstar[18][1]+((
          Fstar[18][0]*Vpk[4][18][0])+(Fstar[18][2]*Vpk[4][18][2])))+temp[5])+((
          (Fstar[19][2]*Vpk[4][19][2])+((Fstar[19][0]*Vpk[4][19][0])+(
          Fstar[19][1]*Vpk[4][19][1])))+((Tstar[19][1]*c19)-(Tstar[19][2]*s19)))
          ));
        temp[7] = (((Tstar[22][1]+((Fstar[22][0]*Vpk[4][22][0])+(Fstar[22][2]*
          Vpk[4][22][2])))+((((Fstar[21][2]*Vpk[4][21][2])+((Fstar[21][0]*
          Vpk[4][21][0])+(Fstar[21][1]*Vpk[4][21][1])))+((Tstar[21][2]*
          Wpk[4][20][2])+((Tstar[21][0]*Wpk[4][21][0])+(Tstar[21][1]*
          Wpk[4][21][1]))))+temp[6]))+(((Fstar[23][2]*Vpk[4][23][2])+((
          Fstar[23][0]*Vpk[4][23][0])+(Fstar[23][1]*Vpk[4][23][1])))+((
          Tstar[23][1]*c23)-(Tstar[23][2]*s23))));
        fs0[4] = (utau[4]-((((Fstar[25][2]*Vpk[4][25][2])+((Fstar[25][0]*
          Vpk[4][25][0])+(Fstar[25][1]*Vpk[4][25][1])))+((Tstar[25][2]*
          Wpk[4][24][2])+((Tstar[25][0]*Wpk[4][25][0])+(Tstar[25][1]*
          Wpk[4][25][1]))))+((((Fstar[24][2]*Vpk[4][24][2])+((Fstar[24][0]*
          Vpk[4][24][0])+(Fstar[24][1]*Vpk[4][24][1])))+((Tstar[24][2]*
          Wpk[4][24][2])+((Tstar[24][0]*Wpk[4][24][0])+(Tstar[24][1]*c23))))+
          temp[7])));
        temp[0] = ((((Fstar[8][2]*Vpk[5][8][2])+((Fstar[8][0]*Vpk[5][8][0])+(
          Fstar[8][1]*Vpk[5][8][1])))+((Tstar[8][2]*Wpk[5][8][2])+((Tstar[8][1]*
          Wpk[5][8][1])-(Tstar[8][0]*s7))))+(((Tstar[5][2]+((Fstar[5][0]*
          rk[0][1])-(Fstar[5][1]*rk[0][0])))+(Tstar[6][2]+((Fstar[6][0]*
          Vpk[5][6][0])+(Fstar[6][1]*Vpk[5][6][1]))))+(((Fstar[7][2]*
          Vpk[5][7][2])+((Fstar[7][0]*Vpk[5][7][0])+(Fstar[7][1]*Vpk[5][7][1])))
          +((Tstar[7][2]*c7)-(Tstar[7][0]*s7)))));
        temp[1] = ((((Fstar[10][2]*Vpk[5][10][2])+((Fstar[10][0]*Vpk[5][10][0])+
          (Fstar[10][1]*Vpk[5][10][1])))+((Tstar[10][2]*Wpk[5][10][2])+((
          Tstar[10][0]*Wpk[5][10][0])+(Tstar[10][1]*Wpk[5][8][1]))))+((((
          Fstar[9][2]*Vpk[5][9][2])+((Fstar[9][0]*Vpk[5][9][0])+(Fstar[9][1]*
          Vpk[5][9][1])))+((Tstar[9][2]*Wpk[5][9][2])+((Tstar[9][0]*Wpk[5][9][0]
          )+(Tstar[9][1]*Wpk[5][8][1]))))+temp[0]));
        temp[2] = (((Tstar[12][2]+((Fstar[12][0]*Vpk[5][12][0])+(Fstar[12][1]*
          Vpk[5][12][1])))+((((Fstar[11][2]*Vpk[5][11][2])+((Fstar[11][0]*
          Vpk[5][11][0])+(Fstar[11][1]*Vpk[5][11][1])))+((Tstar[11][2]*
          Wpk[5][11][2])+((Tstar[11][0]*Wpk[5][10][0])+(Tstar[11][1]*
          Wpk[5][11][1]))))+temp[1]))+(((Fstar[13][2]*Vpk[5][13][2])+((
          Fstar[13][0]*Vpk[5][13][0])+(Fstar[13][1]*Vpk[5][13][1])))+((
          Tstar[13][2]*c13)-(Tstar[13][0]*s13))));
        temp[3] = ((((Fstar[15][2]*Vpk[5][15][2])+((Fstar[15][0]*Vpk[5][15][0])+
          (Fstar[15][1]*Vpk[5][15][1])))+((Tstar[15][2]*Wpk[5][15][2])+((
          Tstar[15][0]*Wpk[5][15][0])+(Tstar[15][1]*Wpk[5][14][1]))))+((((
          Fstar[14][2]*Vpk[5][14][2])+((Fstar[14][0]*Vpk[5][14][0])+(
          Fstar[14][1]*Vpk[5][14][1])))+((Tstar[14][2]*Wpk[5][14][2])+((
          Tstar[14][1]*Wpk[5][14][1])-(Tstar[14][0]*s13))))+temp[2]));
        temp[4] = ((((Fstar[17][2]*Vpk[5][17][2])+((Fstar[17][0]*Vpk[5][17][0])+
          (Fstar[17][1]*Vpk[5][17][1])))+((Tstar[17][2]*Wpk[5][17][2])+((
          Tstar[17][0]*Wpk[5][16][0])+(Tstar[17][1]*Wpk[5][17][1]))))+((((
          Fstar[16][2]*Vpk[5][16][2])+((Fstar[16][0]*Vpk[5][16][0])+(
          Fstar[16][1]*Vpk[5][16][1])))+((Tstar[16][2]*Wpk[5][16][2])+((
          Tstar[16][0]*Wpk[5][16][0])+(Tstar[16][1]*Wpk[5][14][1]))))+temp[3]));
        temp[5] = ((((Fstar[19][2]*Vpk[5][19][2])+((Fstar[19][0]*Vpk[5][19][0])+
          (Fstar[19][1]*Vpk[5][19][1])))+((Tstar[19][2]*Wpk[5][19][2])+((
          Tstar[19][1]*Wpk[5][19][1])-(Tstar[19][0]*s18))))+((((Fstar[18][2]*
          Vpk[5][18][2])+((Fstar[18][0]*Vpk[5][18][0])+(Fstar[18][1]*
          Vpk[5][18][1])))+((Tstar[18][2]*c18)-(Tstar[18][0]*s18)))+temp[4]));
        temp[6] = ((((Fstar[21][2]*Vpk[5][21][2])+((Fstar[21][0]*Vpk[5][21][0])+
          (Fstar[21][1]*Vpk[5][21][1])))+((Tstar[21][2]*Wpk[5][20][2])+((
          Tstar[21][0]*Wpk[5][21][0])+(Tstar[21][1]*Wpk[5][21][1]))))+((((
          Fstar[20][2]*Vpk[5][20][2])+((Fstar[20][0]*Vpk[5][20][0])+(
          Fstar[20][1]*Vpk[5][20][1])))+((Tstar[20][2]*Wpk[5][20][2])+((
          Tstar[20][0]*Wpk[5][20][0])+(Tstar[20][1]*Wpk[5][19][1]))))+temp[5]));
        temp[7] = ((((Fstar[23][2]*Vpk[5][23][2])+((Fstar[23][0]*Vpk[5][23][0])+
          (Fstar[23][1]*Vpk[5][23][1])))+((Tstar[23][2]*Wpk[5][23][2])+((
          Tstar[23][1]*Wpk[5][23][1])-(Tstar[23][0]*s22))))+((((Fstar[22][2]*
          Vpk[5][22][2])+((Fstar[22][0]*Vpk[5][22][0])+(Fstar[22][1]*
          Vpk[5][22][1])))+((Tstar[22][2]*c22)-(Tstar[22][0]*s22)))+temp[6]));
        fs0[5] = (utau[5]-((((Fstar[25][2]*Vpk[5][25][2])+((Fstar[25][0]*
          Vpk[5][25][0])+(Fstar[25][1]*Vpk[5][25][1])))+((Tstar[25][2]*
          Wpk[5][24][2])+((Tstar[25][0]*Wpk[5][25][0])+(Tstar[25][1]*
          Wpk[5][25][1]))))+((((Fstar[24][2]*Vpk[5][24][2])+((Fstar[24][0]*
          Vpk[5][24][0])+(Fstar[24][1]*Vpk[5][24][1])))+((Tstar[24][2]*
          Wpk[5][24][2])+((Tstar[24][0]*Wpk[5][24][0])+(Tstar[24][1]*
          Wpk[5][23][1]))))+temp[7])));
        temp[0] = (((Tstar[6][2]+((Fstar[6][0]*rk[1][1])-(Fstar[6][1]*rk[1][0]))
          )+(((Fstar[7][2]*Vpk[6][7][2])+((Fstar[7][0]*Vpk[6][7][0])+(
          Fstar[7][1]*Vpk[6][7][1])))+((Tstar[7][2]*c7)-(Tstar[7][0]*s7))))+(((
          Fstar[8][2]*Vpk[6][8][2])+((Fstar[8][0]*Vpk[6][8][0])+(Fstar[8][1]*
          Vpk[6][8][1])))+((Tstar[8][2]*Wpk[6][8][2])+((Tstar[8][1]*Wpk[6][8][1]
          )-(Tstar[8][0]*s7)))));
        temp[1] = ((((Fstar[10][2]*Vpk[6][10][2])+((Fstar[10][0]*Vpk[6][10][0])+
          (Fstar[10][1]*Vpk[6][10][1])))+((Tstar[10][2]*Wpk[6][10][2])+((
          Tstar[10][0]*Wpk[6][10][0])+(Tstar[10][1]*Wpk[6][8][1]))))+((((
          Fstar[9][2]*Vpk[6][9][2])+((Fstar[9][0]*Vpk[6][9][0])+(Fstar[9][1]*
          Vpk[6][9][1])))+((Tstar[9][2]*Wpk[6][9][2])+((Tstar[9][0]*Wpk[6][9][0]
          )+(Tstar[9][1]*Wpk[6][8][1]))))+temp[0]));
        fs0[6] = (utau[6]-((((Fstar[11][2]*Vpk[6][11][2])+((Fstar[11][0]*
          Vpk[6][11][0])+(Fstar[11][1]*Vpk[6][11][1])))+((Tstar[11][2]*
          Wpk[6][11][2])+((Tstar[11][0]*Wpk[6][10][0])+(Tstar[11][1]*
          Wpk[6][11][1]))))+temp[1]));
        temp[0] = (((Tstar[7][1]+((Fstar[7][2]*rk[2][0])-(Fstar[7][0]*rk[2][2]))
          )+(((Fstar[8][2]*Vpk[7][8][2])+((Fstar[8][0]*Vpk[7][8][0])+(
          Fstar[8][1]*Vpk[7][8][1])))+((Tstar[8][1]*c8)-(Tstar[8][2]*s8))))+(((
          Fstar[9][2]*Vpk[7][9][2])+((Fstar[9][0]*Vpk[7][9][0])+(Fstar[9][1]*
          Vpk[7][9][1])))+((Tstar[9][2]*Wpk[7][9][2])+((Tstar[9][0]*Wpk[7][9][0]
          )+(Tstar[9][1]*c8)))));
        fs0[7] = (utau[7]-((((Fstar[11][2]*Vpk[7][11][2])+((Fstar[11][0]*
          Vpk[7][11][0])+(Fstar[11][1]*Vpk[7][11][1])))+((Tstar[11][2]*
          Wpk[7][11][2])+((Tstar[11][0]*Wpk[7][10][0])+(Tstar[11][1]*
          Wpk[7][11][1]))))+((((Fstar[10][2]*Vpk[7][10][2])+((Fstar[10][0]*
          Vpk[7][10][0])+(Fstar[10][1]*Vpk[7][10][1])))+((Tstar[10][2]*
          Wpk[7][10][2])+((Tstar[10][0]*Wpk[7][10][0])+(Tstar[10][1]*c8))))+
          temp[0])));
        temp[0] = (((Tstar[8][0]+((Fstar[8][1]*rk[3][2])-(Fstar[8][2]*rk[3][1]))
          )+(((Fstar[9][2]*Vpk[8][9][2])+((Fstar[9][0]*Vpk[8][9][0])+(
          Fstar[9][1]*Vpk[8][9][1])))+((Tstar[9][0]*c9)+(Tstar[9][2]*s9))))+(((
          Fstar[10][2]*Vpk[8][10][2])+((Fstar[10][0]*Vpk[8][10][0])+(
          Fstar[10][1]*Vpk[8][10][1])))+((Tstar[10][0]*Wpk[8][10][0])+(
          Tstar[10][2]*Wpk[8][10][2]))));
        fs0[8] = (utau[8]-((((Fstar[11][2]*Vpk[8][11][2])+((Fstar[11][0]*
          Vpk[8][11][0])+(Fstar[11][1]*Vpk[8][11][1])))+((Tstar[11][2]*
          Wpk[8][11][2])+((Tstar[11][0]*Wpk[8][10][0])+(Tstar[11][1]*
          Wpk[8][11][1]))))+temp[0]));
        fs0[9] = (utau[9]-(((Tstar[9][1]+((Fstar[9][2]*rk[4][0])-(Fstar[9][0]*
          rk[4][2])))+(Tstar[10][1]+((Fstar[10][0]*Vpk[9][10][0])+(Fstar[10][2]*
          Vpk[9][10][2]))))+(((Fstar[11][2]*Vpk[9][11][2])+((Fstar[11][0]*
          Vpk[9][11][0])+(Fstar[11][1]*Vpk[9][11][1])))+((Tstar[11][1]*c11)-(
          Tstar[11][2]*s11)))));
        fs0[10] = (utau[10]-((Tstar[10][1]+((Fstar[10][2]*rk[5][0])-(
          Fstar[10][0]*rk[5][2])))+(((Fstar[11][2]*Vpk[10][11][2])+((
          Fstar[11][0]*Vpk[10][11][0])+(Fstar[11][1]*Vpk[10][11][1])))+((
          Tstar[11][1]*c11)-(Tstar[11][2]*s11)))));
        fs0[11] = (utau[11]-(Tstar[11][0]+((Fstar[11][1]*rk[6][2])-(Fstar[11][2]
          *rk[6][1]))));
        temp[0] = (((Tstar[12][2]+((Fstar[12][0]*rk[7][1])-(Fstar[12][1]*
          rk[7][0])))+(((Fstar[13][2]*Vpk[12][13][2])+((Fstar[13][0]*
          Vpk[12][13][0])+(Fstar[13][1]*Vpk[12][13][1])))+((Tstar[13][2]*c13)-(
          Tstar[13][0]*s13))))+(((Fstar[14][2]*Vpk[12][14][2])+((Fstar[14][0]*
          Vpk[12][14][0])+(Fstar[14][1]*Vpk[12][14][1])))+((Tstar[14][2]*
          Wpk[12][14][2])+((Tstar[14][1]*Wpk[12][14][1])-(Tstar[14][0]*s13)))));
        temp[1] = ((((Fstar[16][2]*Vpk[12][16][2])+((Fstar[16][0]*Vpk[12][16][0]
          )+(Fstar[16][1]*Vpk[12][16][1])))+((Tstar[16][2]*Wpk[12][16][2])+((
          Tstar[16][0]*Wpk[12][16][0])+(Tstar[16][1]*Wpk[12][14][1]))))+((((
          Fstar[15][2]*Vpk[12][15][2])+((Fstar[15][0]*Vpk[12][15][0])+(
          Fstar[15][1]*Vpk[12][15][1])))+((Tstar[15][2]*Wpk[12][15][2])+((
          Tstar[15][0]*Wpk[12][15][0])+(Tstar[15][1]*Wpk[12][14][1]))))+temp[0])
          );
        fs0[12] = (utau[12]-((((Fstar[17][2]*Vpk[12][17][2])+((Fstar[17][0]*
          Vpk[12][17][0])+(Fstar[17][1]*Vpk[12][17][1])))+((Tstar[17][2]*
          Wpk[12][17][2])+((Tstar[17][0]*Wpk[12][16][0])+(Tstar[17][1]*
          Wpk[12][17][1]))))+temp[1]));
        temp[0] = (((Tstar[13][1]+((Fstar[13][2]*rk[8][0])-(Fstar[13][0]*
          rk[8][2])))+(((Fstar[14][2]*Vpk[13][14][2])+((Fstar[14][0]*
          Vpk[13][14][0])+(Fstar[14][1]*Vpk[13][14][1])))+((Tstar[14][1]*c14)-(
          Tstar[14][2]*s14))))+(((Fstar[15][2]*Vpk[13][15][2])+((Fstar[15][0]*
          Vpk[13][15][0])+(Fstar[15][1]*Vpk[13][15][1])))+((Tstar[15][2]*
          Wpk[13][15][2])+((Tstar[15][0]*Wpk[13][15][0])+(Tstar[15][1]*c14)))));
        fs0[13] = (utau[13]-((((Fstar[17][2]*Vpk[13][17][2])+((Fstar[17][0]*
          Vpk[13][17][0])+(Fstar[17][1]*Vpk[13][17][1])))+((Tstar[17][2]*
          Wpk[13][17][2])+((Tstar[17][0]*Wpk[13][16][0])+(Tstar[17][1]*
          Wpk[13][17][1]))))+((((Fstar[16][2]*Vpk[13][16][2])+((Fstar[16][0]*
          Vpk[13][16][0])+(Fstar[16][1]*Vpk[13][16][1])))+((Tstar[16][2]*
          Wpk[13][16][2])+((Tstar[16][0]*Wpk[13][16][0])+(Tstar[16][1]*c14))))+
          temp[0])));
        temp[0] = (((Tstar[14][0]+((Fstar[14][1]*rk[9][2])-(Fstar[14][2]*
          rk[9][1])))+(((Fstar[15][2]*Vpk[14][15][2])+((Fstar[15][0]*
          Vpk[14][15][0])+(Fstar[15][1]*Vpk[14][15][1])))+((Tstar[15][0]*c15)+(
          Tstar[15][2]*s15))))+(((Fstar[16][2]*Vpk[14][16][2])+((Fstar[16][0]*
          Vpk[14][16][0])+(Fstar[16][1]*Vpk[14][16][1])))+((Tstar[16][0]*
          Wpk[14][16][0])+(Tstar[16][2]*Wpk[14][16][2]))));
        fs0[14] = (utau[14]-((((Fstar[17][2]*Vpk[14][17][2])+((Fstar[17][0]*
          Vpk[14][17][0])+(Fstar[17][1]*Vpk[14][17][1])))+((Tstar[17][2]*
          Wpk[14][17][2])+((Tstar[17][0]*Wpk[14][16][0])+(Tstar[17][1]*
          Wpk[14][17][1]))))+temp[0]));
        fs0[15] = (utau[15]-(((Tstar[15][1]+((Fstar[15][2]*rk[10][0])-(
          Fstar[15][0]*rk[10][2])))+(Tstar[16][1]+((Fstar[16][0]*Vpk[15][16][0])
          +(Fstar[16][2]*Vpk[15][16][2]))))+(((Fstar[17][2]*Vpk[15][17][2])+((
          Fstar[17][0]*Vpk[15][17][0])+(Fstar[17][1]*Vpk[15][17][1])))+((
          Tstar[17][1]*c17)-(Tstar[17][2]*s17)))));
        fs0[16] = (utau[16]-((Tstar[16][1]+((Fstar[16][2]*rk[11][0])-(
          Fstar[16][0]*rk[11][2])))+(((Fstar[17][2]*Vpk[16][17][2])+((
          Fstar[17][0]*Vpk[16][17][0])+(Fstar[17][1]*Vpk[16][17][1])))+((
          Tstar[17][1]*c17)-(Tstar[17][2]*s17)))));
        fs0[17] = (utau[17]-(Tstar[17][0]+((Fstar[17][1]*rk[12][2])-(
          Fstar[17][2]*rk[12][1]))));
        temp[0] = (((Tstar[18][1]+((Fstar[18][2]*rk[13][0])-(Fstar[18][0]*
          rk[13][2])))+(((Fstar[19][2]*Vpk[18][19][2])+((Fstar[19][0]*
          Vpk[18][19][0])+(Fstar[19][1]*Vpk[18][19][1])))+((Tstar[19][1]*c19)-(
          Tstar[19][2]*s19))))+(((Fstar[20][2]*Vpk[18][20][2])+((Fstar[20][0]*
          Vpk[18][20][0])+(Fstar[20][1]*Vpk[18][20][1])))+((Tstar[20][2]*
          Wpk[18][20][2])+((Tstar[20][0]*Wpk[18][20][0])+(Tstar[20][1]*c19)))));
        fs0[18] = (utau[18]-((((Fstar[21][2]*Vpk[18][21][2])+((Fstar[21][0]*
          Vpk[18][21][0])+(Fstar[21][1]*Vpk[18][21][1])))+((Tstar[21][2]*
          Wpk[18][20][2])+((Tstar[21][0]*Wpk[18][21][0])+(Tstar[21][1]*
          Wpk[18][21][1]))))+temp[0]));
        fs0[19] = (utau[19]-(((Tstar[19][0]+((Fstar[19][1]*rk[14][2])-(
          Fstar[19][2]*rk[14][1])))+(((Fstar[20][2]*Vpk[19][20][2])+((
          Fstar[20][0]*Vpk[19][20][0])+(Fstar[20][1]*Vpk[19][20][1])))+((
          Tstar[20][0]*c20)+(Tstar[20][2]*s20))))+(((Fstar[21][2]*Vpk[19][21][2]
          )+((Fstar[21][0]*Vpk[19][21][0])+(Fstar[21][1]*Vpk[19][21][1])))+((
          Tstar[21][2]*s20)+((Tstar[21][0]*Wpk[19][21][0])+(Tstar[21][1]*
          Wpk[19][21][1]))))));
        fs0[20] = (utau[20]-((Tstar[20][1]+((Fstar[20][2]*rk[15][0])-(
          Fstar[20][0]*rk[15][2])))+(((Fstar[21][2]*Vpk[20][21][2])+((
          Fstar[21][0]*Vpk[20][21][0])+(Fstar[21][1]*Vpk[20][21][1])))+((
          Tstar[21][0]*s21)+(Tstar[21][1]*c21)))));
        fs0[21] = (utau[21]-(Tstar[21][2]+((Fstar[21][0]*rk[16][1])-(
          Fstar[21][1]*rk[16][0]))));
        temp[0] = (((Tstar[22][1]+((Fstar[22][2]*rk[17][0])-(Fstar[22][0]*
          rk[17][2])))+(((Fstar[23][2]*Vpk[22][23][2])+((Fstar[23][0]*
          Vpk[22][23][0])+(Fstar[23][1]*Vpk[22][23][1])))+((Tstar[23][1]*c23)-(
          Tstar[23][2]*s23))))+(((Fstar[24][2]*Vpk[22][24][2])+((Fstar[24][0]*
          Vpk[22][24][0])+(Fstar[24][1]*Vpk[22][24][1])))+((Tstar[24][2]*
          Wpk[22][24][2])+((Tstar[24][0]*Wpk[22][24][0])+(Tstar[24][1]*c23)))));
        fs0[22] = (utau[22]-((((Fstar[25][2]*Vpk[22][25][2])+((Fstar[25][0]*
          Vpk[22][25][0])+(Fstar[25][1]*Vpk[22][25][1])))+((Tstar[25][2]*
          Wpk[22][24][2])+((Tstar[25][0]*Wpk[22][25][0])+(Tstar[25][1]*
          Wpk[22][25][1]))))+temp[0]));
        fs0[23] = (utau[23]-(((Tstar[23][0]+((Fstar[23][1]*rk[18][2])-(
          Fstar[23][2]*rk[18][1])))+(((Fstar[24][2]*Vpk[23][24][2])+((
          Fstar[24][0]*Vpk[23][24][0])+(Fstar[24][1]*Vpk[23][24][1])))+((
          Tstar[24][0]*c24)+(Tstar[24][2]*s24))))+(((Fstar[25][2]*Vpk[23][25][2]
          )+((Fstar[25][0]*Vpk[23][25][0])+(Fstar[25][1]*Vpk[23][25][1])))+((
          Tstar[25][2]*s24)+((Tstar[25][0]*Wpk[23][25][0])+(Tstar[25][1]*
          Wpk[23][25][1]))))));
        fs0[24] = (utau[24]-((Tstar[24][1]+((Fstar[24][2]*rk[19][0])-(
          Fstar[24][0]*rk[19][2])))+(((Fstar[25][2]*Vpk[24][25][2])+((
          Fstar[25][0]*Vpk[24][25][0])+(Fstar[25][1]*Vpk[24][25][1])))+((
          Tstar[25][0]*s25)+(Tstar[25][1]*c25)))));
        fs0[25] = (utau[25]-(Tstar[25][2]+((Fstar[25][0]*rk[20][1])-(
          Fstar[25][1]*rk[20][0]))));
        fs0flg = 1;
    }
/*
 Used 0.02 seconds CPU time,
 0 additional bytes of memory.
 Equations contain 1179 adds/subtracts/negates
                   1031 multiplies
                      0 divides
                    202 assignments
*/
}

void Jimmy::sddomm(int routine)
{
    int dumroutine,errnum;
    int i;

    if (mmflg == 0) {
/*
Compute mass matrix (MM)
*/
        sddovpk();
        IkWpk[3][6][0] = ((ik[1][0][0]*c6)-(ik[1][0][1]*s6));
        IkWpk[3][6][1] = ((ik[1][1][0]*c6)-(ik[1][1][1]*s6));
        IkWpk[3][6][2] = ((ik[1][2][0]*c6)-(ik[1][2][1]*s6));
        IkWpk[3][7][0] = ((ik[2][0][2]*Wpk[3][7][2])+((ik[2][0][0]*Wpk[3][7][0])
          -(ik[2][0][1]*s6)));
        IkWpk[3][7][1] = ((ik[2][1][2]*Wpk[3][7][2])+((ik[2][1][0]*Wpk[3][7][0])
          -(ik[2][1][1]*s6)));
        IkWpk[3][7][2] = ((ik[2][2][2]*Wpk[3][7][2])+((ik[2][2][0]*Wpk[3][7][0])
          -(ik[2][2][1]*s6)));
        IkWpk[3][8][0] = ((ik[3][0][2]*Wpk[3][8][2])+((ik[3][0][0]*Wpk[3][7][0])
          +(ik[3][0][1]*Wpk[3][8][1])));
        IkWpk[3][8][1] = ((ik[3][1][2]*Wpk[3][8][2])+((ik[3][1][0]*Wpk[3][7][0])
          +(ik[3][1][1]*Wpk[3][8][1])));
        IkWpk[3][8][2] = ((ik[3][2][2]*Wpk[3][8][2])+((ik[3][2][0]*Wpk[3][7][0])
          +(ik[3][2][1]*Wpk[3][8][1])));
        IkWpk[3][9][0] = ((ik[4][0][2]*Wpk[3][9][2])+((ik[4][0][0]*Wpk[3][9][0])
          +(ik[4][0][1]*Wpk[3][8][1])));
        IkWpk[3][9][1] = ((ik[4][1][2]*Wpk[3][9][2])+((ik[4][1][0]*Wpk[3][9][0])
          +(ik[4][1][1]*Wpk[3][8][1])));
        IkWpk[3][9][2] = ((ik[4][2][2]*Wpk[3][9][2])+((ik[4][2][0]*Wpk[3][9][0])
          +(ik[4][2][1]*Wpk[3][8][1])));
        IkWpk[3][10][0] = ((ik[5][0][2]*Wpk[3][10][2])+((ik[5][0][0]*
          Wpk[3][10][0])+(ik[5][0][1]*Wpk[3][8][1])));
        IkWpk[3][10][1] = ((ik[5][1][2]*Wpk[3][10][2])+((ik[5][1][0]*
          Wpk[3][10][0])+(ik[5][1][1]*Wpk[3][8][1])));
        IkWpk[3][10][2] = ((ik[5][2][2]*Wpk[3][10][2])+((ik[5][2][0]*
          Wpk[3][10][0])+(ik[5][2][1]*Wpk[3][8][1])));
        IkWpk[3][11][0] = ((ik[6][0][2]*Wpk[3][11][2])+((ik[6][0][0]*
          Wpk[3][10][0])+(ik[6][0][1]*Wpk[3][11][1])));
        IkWpk[3][11][1] = ((ik[6][1][2]*Wpk[3][11][2])+((ik[6][1][0]*
          Wpk[3][10][0])+(ik[6][1][1]*Wpk[3][11][1])));
        IkWpk[3][11][2] = ((ik[6][2][2]*Wpk[3][11][2])+((ik[6][2][0]*
          Wpk[3][10][0])+(ik[6][2][1]*Wpk[3][11][1])));
        IkWpk[3][12][0] = ((ik[7][0][0]*c12)-(ik[7][0][1]*s12));
        IkWpk[3][12][1] = ((ik[7][1][0]*c12)-(ik[7][1][1]*s12));
        IkWpk[3][12][2] = ((ik[7][2][0]*c12)-(ik[7][2][1]*s12));
        IkWpk[3][13][0] = ((ik[8][0][2]*Wpk[3][13][2])+((ik[8][0][0]*
          Wpk[3][13][0])-(ik[8][0][1]*s12)));
        IkWpk[3][13][1] = ((ik[8][1][2]*Wpk[3][13][2])+((ik[8][1][0]*
          Wpk[3][13][0])-(ik[8][1][1]*s12)));
        IkWpk[3][13][2] = ((ik[8][2][2]*Wpk[3][13][2])+((ik[8][2][0]*
          Wpk[3][13][0])-(ik[8][2][1]*s12)));
        IkWpk[3][14][0] = ((ik[9][0][2]*Wpk[3][14][2])+((ik[9][0][0]*
          Wpk[3][13][0])+(ik[9][0][1]*Wpk[3][14][1])));
        IkWpk[3][14][1] = ((ik[9][1][2]*Wpk[3][14][2])+((ik[9][1][0]*
          Wpk[3][13][0])+(ik[9][1][1]*Wpk[3][14][1])));
        IkWpk[3][14][2] = ((ik[9][2][2]*Wpk[3][14][2])+((ik[9][2][0]*
          Wpk[3][13][0])+(ik[9][2][1]*Wpk[3][14][1])));
        IkWpk[3][15][0] = ((ik[10][0][2]*Wpk[3][15][2])+((ik[10][0][0]*
          Wpk[3][15][0])+(ik[10][0][1]*Wpk[3][14][1])));
        IkWpk[3][15][1] = ((ik[10][1][2]*Wpk[3][15][2])+((ik[10][1][0]*
          Wpk[3][15][0])+(ik[10][1][1]*Wpk[3][14][1])));
        IkWpk[3][15][2] = ((ik[10][2][2]*Wpk[3][15][2])+((ik[10][2][0]*
          Wpk[3][15][0])+(ik[10][2][1]*Wpk[3][14][1])));
        IkWpk[3][16][0] = ((ik[11][0][2]*Wpk[3][16][2])+((ik[11][0][0]*
          Wpk[3][16][0])+(ik[11][0][1]*Wpk[3][14][1])));
        IkWpk[3][16][1] = ((ik[11][1][2]*Wpk[3][16][2])+((ik[11][1][0]*
          Wpk[3][16][0])+(ik[11][1][1]*Wpk[3][14][1])));
        IkWpk[3][16][2] = ((ik[11][2][2]*Wpk[3][16][2])+((ik[11][2][0]*
          Wpk[3][16][0])+(ik[11][2][1]*Wpk[3][14][1])));
        IkWpk[3][17][0] = ((ik[12][0][2]*Wpk[3][17][2])+((ik[12][0][0]*
          Wpk[3][16][0])+(ik[12][0][1]*Wpk[3][17][1])));
        IkWpk[3][17][1] = ((ik[12][1][2]*Wpk[3][17][2])+((ik[12][1][0]*
          Wpk[3][16][0])+(ik[12][1][1]*Wpk[3][17][1])));
        IkWpk[3][17][2] = ((ik[12][2][2]*Wpk[3][17][2])+((ik[12][2][0]*
          Wpk[3][16][0])+(ik[12][2][1]*Wpk[3][17][1])));
        IkWpk[3][18][0] = ((ik[13][0][0]*c18)+(ik[13][0][2]*s18));
        IkWpk[3][18][1] = ((ik[13][1][0]*c18)+(ik[13][1][2]*s18));
        IkWpk[3][18][2] = ((ik[13][2][0]*c18)+(ik[13][2][2]*s18));
        IkWpk[3][19][0] = ((ik[14][0][2]*Wpk[3][19][2])+((ik[14][0][0]*c18)+(
          ik[14][0][1]*Wpk[3][19][1])));
        IkWpk[3][19][1] = ((ik[14][1][2]*Wpk[3][19][2])+((ik[14][1][0]*c18)+(
          ik[14][1][1]*Wpk[3][19][1])));
        IkWpk[3][19][2] = ((ik[14][2][2]*Wpk[3][19][2])+((ik[14][2][0]*c18)+(
          ik[14][2][1]*Wpk[3][19][1])));
        IkWpk[3][20][0] = ((ik[15][0][2]*Wpk[3][20][2])+((ik[15][0][0]*
          Wpk[3][20][0])+(ik[15][0][1]*Wpk[3][19][1])));
        IkWpk[3][20][1] = ((ik[15][1][2]*Wpk[3][20][2])+((ik[15][1][0]*
          Wpk[3][20][0])+(ik[15][1][1]*Wpk[3][19][1])));
        IkWpk[3][20][2] = ((ik[15][2][2]*Wpk[3][20][2])+((ik[15][2][0]*
          Wpk[3][20][0])+(ik[15][2][1]*Wpk[3][19][1])));
        IkWpk[3][21][0] = ((ik[16][0][2]*Wpk[3][20][2])+((ik[16][0][0]*
          Wpk[3][21][0])+(ik[16][0][1]*Wpk[3][21][1])));
        IkWpk[3][21][1] = ((ik[16][1][2]*Wpk[3][20][2])+((ik[16][1][0]*
          Wpk[3][21][0])+(ik[16][1][1]*Wpk[3][21][1])));
        IkWpk[3][21][2] = ((ik[16][2][2]*Wpk[3][20][2])+((ik[16][2][0]*
          Wpk[3][21][0])+(ik[16][2][1]*Wpk[3][21][1])));
        IkWpk[3][22][0] = ((ik[17][0][0]*c22)+(ik[17][0][2]*s22));
        IkWpk[3][22][1] = ((ik[17][1][0]*c22)+(ik[17][1][2]*s22));
        IkWpk[3][22][2] = ((ik[17][2][0]*c22)+(ik[17][2][2]*s22));
        IkWpk[3][23][0] = ((ik[18][0][2]*Wpk[3][23][2])+((ik[18][0][0]*c22)+(
          ik[18][0][1]*Wpk[3][23][1])));
        IkWpk[3][23][1] = ((ik[18][1][2]*Wpk[3][23][2])+((ik[18][1][0]*c22)+(
          ik[18][1][1]*Wpk[3][23][1])));
        IkWpk[3][23][2] = ((ik[18][2][2]*Wpk[3][23][2])+((ik[18][2][0]*c22)+(
          ik[18][2][1]*Wpk[3][23][1])));
        IkWpk[3][24][0] = ((ik[19][0][2]*Wpk[3][24][2])+((ik[19][0][0]*
          Wpk[3][24][0])+(ik[19][0][1]*Wpk[3][23][1])));
        IkWpk[3][24][1] = ((ik[19][1][2]*Wpk[3][24][2])+((ik[19][1][0]*
          Wpk[3][24][0])+(ik[19][1][1]*Wpk[3][23][1])));
        IkWpk[3][24][2] = ((ik[19][2][2]*Wpk[3][24][2])+((ik[19][2][0]*
          Wpk[3][24][0])+(ik[19][2][1]*Wpk[3][23][1])));
        IkWpk[3][25][0] = ((ik[20][0][2]*Wpk[3][24][2])+((ik[20][0][0]*
          Wpk[3][25][0])+(ik[20][0][1]*Wpk[3][25][1])));
        IkWpk[3][25][1] = ((ik[20][1][2]*Wpk[3][24][2])+((ik[20][1][0]*
          Wpk[3][25][0])+(ik[20][1][1]*Wpk[3][25][1])));
        IkWpk[3][25][2] = ((ik[20][2][2]*Wpk[3][24][2])+((ik[20][2][0]*
          Wpk[3][25][0])+(ik[20][2][1]*Wpk[3][25][1])));
        IkWpk[4][6][0] = ((ik[1][0][0]*s6)+(ik[1][0][1]*c6));
        IkWpk[4][6][1] = ((ik[1][1][0]*s6)+(ik[1][1][1]*c6));
        IkWpk[4][6][2] = ((ik[1][2][0]*s6)+(ik[1][2][1]*c6));
        IkWpk[4][7][0] = ((ik[2][0][2]*Wpk[4][7][2])+((ik[2][0][0]*Wpk[4][7][0])
          +(ik[2][0][1]*c6)));
        IkWpk[4][7][1] = ((ik[2][1][2]*Wpk[4][7][2])+((ik[2][1][0]*Wpk[4][7][0])
          +(ik[2][1][1]*c6)));
        IkWpk[4][7][2] = ((ik[2][2][2]*Wpk[4][7][2])+((ik[2][2][0]*Wpk[4][7][0])
          +(ik[2][2][1]*c6)));
        IkWpk[4][8][0] = ((ik[3][0][2]*Wpk[4][8][2])+((ik[3][0][0]*Wpk[4][7][0])
          +(ik[3][0][1]*Wpk[4][8][1])));
        IkWpk[4][8][1] = ((ik[3][1][2]*Wpk[4][8][2])+((ik[3][1][0]*Wpk[4][7][0])
          +(ik[3][1][1]*Wpk[4][8][1])));
        IkWpk[4][8][2] = ((ik[3][2][2]*Wpk[4][8][2])+((ik[3][2][0]*Wpk[4][7][0])
          +(ik[3][2][1]*Wpk[4][8][1])));
        IkWpk[4][9][0] = ((ik[4][0][2]*Wpk[4][9][2])+((ik[4][0][0]*Wpk[4][9][0])
          +(ik[4][0][1]*Wpk[4][8][1])));
        IkWpk[4][9][1] = ((ik[4][1][2]*Wpk[4][9][2])+((ik[4][1][0]*Wpk[4][9][0])
          +(ik[4][1][1]*Wpk[4][8][1])));
        IkWpk[4][9][2] = ((ik[4][2][2]*Wpk[4][9][2])+((ik[4][2][0]*Wpk[4][9][0])
          +(ik[4][2][1]*Wpk[4][8][1])));
        IkWpk[4][10][0] = ((ik[5][0][2]*Wpk[4][10][2])+((ik[5][0][0]*
          Wpk[4][10][0])+(ik[5][0][1]*Wpk[4][8][1])));
        IkWpk[4][10][1] = ((ik[5][1][2]*Wpk[4][10][2])+((ik[5][1][0]*
          Wpk[4][10][0])+(ik[5][1][1]*Wpk[4][8][1])));
        IkWpk[4][10][2] = ((ik[5][2][2]*Wpk[4][10][2])+((ik[5][2][0]*
          Wpk[4][10][0])+(ik[5][2][1]*Wpk[4][8][1])));
        IkWpk[4][11][0] = ((ik[6][0][2]*Wpk[4][11][2])+((ik[6][0][0]*
          Wpk[4][10][0])+(ik[6][0][1]*Wpk[4][11][1])));
        IkWpk[4][11][1] = ((ik[6][1][2]*Wpk[4][11][2])+((ik[6][1][0]*
          Wpk[4][10][0])+(ik[6][1][1]*Wpk[4][11][1])));
        IkWpk[4][11][2] = ((ik[6][2][2]*Wpk[4][11][2])+((ik[6][2][0]*
          Wpk[4][10][0])+(ik[6][2][1]*Wpk[4][11][1])));
        IkWpk[4][12][0] = ((ik[7][0][0]*s12)+(ik[7][0][1]*c12));
        IkWpk[4][12][1] = ((ik[7][1][0]*s12)+(ik[7][1][1]*c12));
        IkWpk[4][12][2] = ((ik[7][2][0]*s12)+(ik[7][2][1]*c12));
        IkWpk[4][13][0] = ((ik[8][0][2]*Wpk[4][13][2])+((ik[8][0][0]*
          Wpk[4][13][0])+(ik[8][0][1]*c12)));
        IkWpk[4][13][1] = ((ik[8][1][2]*Wpk[4][13][2])+((ik[8][1][0]*
          Wpk[4][13][0])+(ik[8][1][1]*c12)));
        IkWpk[4][13][2] = ((ik[8][2][2]*Wpk[4][13][2])+((ik[8][2][0]*
          Wpk[4][13][0])+(ik[8][2][1]*c12)));
        IkWpk[4][14][0] = ((ik[9][0][2]*Wpk[4][14][2])+((ik[9][0][0]*
          Wpk[4][13][0])+(ik[9][0][1]*Wpk[4][14][1])));
        IkWpk[4][14][1] = ((ik[9][1][2]*Wpk[4][14][2])+((ik[9][1][0]*
          Wpk[4][13][0])+(ik[9][1][1]*Wpk[4][14][1])));
        IkWpk[4][14][2] = ((ik[9][2][2]*Wpk[4][14][2])+((ik[9][2][0]*
          Wpk[4][13][0])+(ik[9][2][1]*Wpk[4][14][1])));
        IkWpk[4][15][0] = ((ik[10][0][2]*Wpk[4][15][2])+((ik[10][0][0]*
          Wpk[4][15][0])+(ik[10][0][1]*Wpk[4][14][1])));
        IkWpk[4][15][1] = ((ik[10][1][2]*Wpk[4][15][2])+((ik[10][1][0]*
          Wpk[4][15][0])+(ik[10][1][1]*Wpk[4][14][1])));
        IkWpk[4][15][2] = ((ik[10][2][2]*Wpk[4][15][2])+((ik[10][2][0]*
          Wpk[4][15][0])+(ik[10][2][1]*Wpk[4][14][1])));
        IkWpk[4][16][0] = ((ik[11][0][2]*Wpk[4][16][2])+((ik[11][0][0]*
          Wpk[4][16][0])+(ik[11][0][1]*Wpk[4][14][1])));
        IkWpk[4][16][1] = ((ik[11][1][2]*Wpk[4][16][2])+((ik[11][1][0]*
          Wpk[4][16][0])+(ik[11][1][1]*Wpk[4][14][1])));
        IkWpk[4][16][2] = ((ik[11][2][2]*Wpk[4][16][2])+((ik[11][2][0]*
          Wpk[4][16][0])+(ik[11][2][1]*Wpk[4][14][1])));
        IkWpk[4][17][0] = ((ik[12][0][2]*Wpk[4][17][2])+((ik[12][0][0]*
          Wpk[4][16][0])+(ik[12][0][1]*Wpk[4][17][1])));
        IkWpk[4][17][1] = ((ik[12][1][2]*Wpk[4][17][2])+((ik[12][1][0]*
          Wpk[4][16][0])+(ik[12][1][1]*Wpk[4][17][1])));
        IkWpk[4][17][2] = ((ik[12][2][2]*Wpk[4][17][2])+((ik[12][2][0]*
          Wpk[4][16][0])+(ik[12][2][1]*Wpk[4][17][1])));
        IkWpk[4][19][0] = ((ik[14][0][1]*c19)-(ik[14][0][2]*s19));
        IkWpk[4][19][1] = ((ik[14][1][1]*c19)-(ik[14][1][2]*s19));
        IkWpk[4][19][2] = ((ik[14][2][1]*c19)-(ik[14][2][2]*s19));
        IkWpk[4][20][0] = ((ik[15][0][2]*Wpk[4][20][2])+((ik[15][0][0]*
          Wpk[4][20][0])+(ik[15][0][1]*c19)));
        IkWpk[4][20][1] = ((ik[15][1][2]*Wpk[4][20][2])+((ik[15][1][0]*
          Wpk[4][20][0])+(ik[15][1][1]*c19)));
        IkWpk[4][20][2] = ((ik[15][2][2]*Wpk[4][20][2])+((ik[15][2][0]*
          Wpk[4][20][0])+(ik[15][2][1]*c19)));
        IkWpk[4][21][0] = ((ik[16][0][2]*Wpk[4][20][2])+((ik[16][0][0]*
          Wpk[4][21][0])+(ik[16][0][1]*Wpk[4][21][1])));
        IkWpk[4][21][1] = ((ik[16][1][2]*Wpk[4][20][2])+((ik[16][1][0]*
          Wpk[4][21][0])+(ik[16][1][1]*Wpk[4][21][1])));
        IkWpk[4][21][2] = ((ik[16][2][2]*Wpk[4][20][2])+((ik[16][2][0]*
          Wpk[4][21][0])+(ik[16][2][1]*Wpk[4][21][1])));
        IkWpk[4][23][0] = ((ik[18][0][1]*c23)-(ik[18][0][2]*s23));
        IkWpk[4][23][1] = ((ik[18][1][1]*c23)-(ik[18][1][2]*s23));
        IkWpk[4][23][2] = ((ik[18][2][1]*c23)-(ik[18][2][2]*s23));
        IkWpk[4][24][0] = ((ik[19][0][2]*Wpk[4][24][2])+((ik[19][0][0]*
          Wpk[4][24][0])+(ik[19][0][1]*c23)));
        IkWpk[4][24][1] = ((ik[19][1][2]*Wpk[4][24][2])+((ik[19][1][0]*
          Wpk[4][24][0])+(ik[19][1][1]*c23)));
        IkWpk[4][24][2] = ((ik[19][2][2]*Wpk[4][24][2])+((ik[19][2][0]*
          Wpk[4][24][0])+(ik[19][2][1]*c23)));
        IkWpk[4][25][0] = ((ik[20][0][2]*Wpk[4][24][2])+((ik[20][0][0]*
          Wpk[4][25][0])+(ik[20][0][1]*Wpk[4][25][1])));
        IkWpk[4][25][1] = ((ik[20][1][2]*Wpk[4][24][2])+((ik[20][1][0]*
          Wpk[4][25][0])+(ik[20][1][1]*Wpk[4][25][1])));
        IkWpk[4][25][2] = ((ik[20][2][2]*Wpk[4][24][2])+((ik[20][2][0]*
          Wpk[4][25][0])+(ik[20][2][1]*Wpk[4][25][1])));
        IkWpk[5][7][0] = ((ik[2][0][2]*c7)-(ik[2][0][0]*s7));
        IkWpk[5][7][1] = ((ik[2][1][2]*c7)-(ik[2][1][0]*s7));
        IkWpk[5][7][2] = ((ik[2][2][2]*c7)-(ik[2][2][0]*s7));
        IkWpk[5][8][0] = ((ik[3][0][2]*Wpk[5][8][2])+((ik[3][0][1]*Wpk[5][8][1])
          -(ik[3][0][0]*s7)));
        IkWpk[5][8][1] = ((ik[3][1][2]*Wpk[5][8][2])+((ik[3][1][1]*Wpk[5][8][1])
          -(ik[3][1][0]*s7)));
        IkWpk[5][8][2] = ((ik[3][2][2]*Wpk[5][8][2])+((ik[3][2][1]*Wpk[5][8][1])
          -(ik[3][2][0]*s7)));
        IkWpk[5][9][0] = ((ik[4][0][2]*Wpk[5][9][2])+((ik[4][0][0]*Wpk[5][9][0])
          +(ik[4][0][1]*Wpk[5][8][1])));
        IkWpk[5][9][1] = ((ik[4][1][2]*Wpk[5][9][2])+((ik[4][1][0]*Wpk[5][9][0])
          +(ik[4][1][1]*Wpk[5][8][1])));
        IkWpk[5][9][2] = ((ik[4][2][2]*Wpk[5][9][2])+((ik[4][2][0]*Wpk[5][9][0])
          +(ik[4][2][1]*Wpk[5][8][1])));
        IkWpk[5][10][0] = ((ik[5][0][2]*Wpk[5][10][2])+((ik[5][0][0]*
          Wpk[5][10][0])+(ik[5][0][1]*Wpk[5][8][1])));
        IkWpk[5][10][1] = ((ik[5][1][2]*Wpk[5][10][2])+((ik[5][1][0]*
          Wpk[5][10][0])+(ik[5][1][1]*Wpk[5][8][1])));
        IkWpk[5][10][2] = ((ik[5][2][2]*Wpk[5][10][2])+((ik[5][2][0]*
          Wpk[5][10][0])+(ik[5][2][1]*Wpk[5][8][1])));
        IkWpk[5][11][0] = ((ik[6][0][2]*Wpk[5][11][2])+((ik[6][0][0]*
          Wpk[5][10][0])+(ik[6][0][1]*Wpk[5][11][1])));
        IkWpk[5][11][1] = ((ik[6][1][2]*Wpk[5][11][2])+((ik[6][1][0]*
          Wpk[5][10][0])+(ik[6][1][1]*Wpk[5][11][1])));
        IkWpk[5][11][2] = ((ik[6][2][2]*Wpk[5][11][2])+((ik[6][2][0]*
          Wpk[5][10][0])+(ik[6][2][1]*Wpk[5][11][1])));
        IkWpk[5][13][0] = ((ik[8][0][2]*c13)-(ik[8][0][0]*s13));
        IkWpk[5][13][1] = ((ik[8][1][2]*c13)-(ik[8][1][0]*s13));
        IkWpk[5][13][2] = ((ik[8][2][2]*c13)-(ik[8][2][0]*s13));
        IkWpk[5][14][0] = ((ik[9][0][2]*Wpk[5][14][2])+((ik[9][0][1]*
          Wpk[5][14][1])-(ik[9][0][0]*s13)));
        IkWpk[5][14][1] = ((ik[9][1][2]*Wpk[5][14][2])+((ik[9][1][1]*
          Wpk[5][14][1])-(ik[9][1][0]*s13)));
        IkWpk[5][14][2] = ((ik[9][2][2]*Wpk[5][14][2])+((ik[9][2][1]*
          Wpk[5][14][1])-(ik[9][2][0]*s13)));
        IkWpk[5][15][0] = ((ik[10][0][2]*Wpk[5][15][2])+((ik[10][0][0]*
          Wpk[5][15][0])+(ik[10][0][1]*Wpk[5][14][1])));
        IkWpk[5][15][1] = ((ik[10][1][2]*Wpk[5][15][2])+((ik[10][1][0]*
          Wpk[5][15][0])+(ik[10][1][1]*Wpk[5][14][1])));
        IkWpk[5][15][2] = ((ik[10][2][2]*Wpk[5][15][2])+((ik[10][2][0]*
          Wpk[5][15][0])+(ik[10][2][1]*Wpk[5][14][1])));
        IkWpk[5][16][0] = ((ik[11][0][2]*Wpk[5][16][2])+((ik[11][0][0]*
          Wpk[5][16][0])+(ik[11][0][1]*Wpk[5][14][1])));
        IkWpk[5][16][1] = ((ik[11][1][2]*Wpk[5][16][2])+((ik[11][1][0]*
          Wpk[5][16][0])+(ik[11][1][1]*Wpk[5][14][1])));
        IkWpk[5][16][2] = ((ik[11][2][2]*Wpk[5][16][2])+((ik[11][2][0]*
          Wpk[5][16][0])+(ik[11][2][1]*Wpk[5][14][1])));
        IkWpk[5][17][0] = ((ik[12][0][2]*Wpk[5][17][2])+((ik[12][0][0]*
          Wpk[5][16][0])+(ik[12][0][1]*Wpk[5][17][1])));
        IkWpk[5][17][1] = ((ik[12][1][2]*Wpk[5][17][2])+((ik[12][1][0]*
          Wpk[5][16][0])+(ik[12][1][1]*Wpk[5][17][1])));
        IkWpk[5][17][2] = ((ik[12][2][2]*Wpk[5][17][2])+((ik[12][2][0]*
          Wpk[5][16][0])+(ik[12][2][1]*Wpk[5][17][1])));
        IkWpk[5][18][0] = ((ik[13][0][2]*c18)-(ik[13][0][0]*s18));
        IkWpk[5][18][1] = ((ik[13][1][2]*c18)-(ik[13][1][0]*s18));
        IkWpk[5][18][2] = ((ik[13][2][2]*c18)-(ik[13][2][0]*s18));
        IkWpk[5][19][0] = ((ik[14][0][2]*Wpk[5][19][2])+((ik[14][0][1]*
          Wpk[5][19][1])-(ik[14][0][0]*s18)));
        IkWpk[5][19][1] = ((ik[14][1][2]*Wpk[5][19][2])+((ik[14][1][1]*
          Wpk[5][19][1])-(ik[14][1][0]*s18)));
        IkWpk[5][19][2] = ((ik[14][2][2]*Wpk[5][19][2])+((ik[14][2][1]*
          Wpk[5][19][1])-(ik[14][2][0]*s18)));
        IkWpk[5][20][0] = ((ik[15][0][2]*Wpk[5][20][2])+((ik[15][0][0]*
          Wpk[5][20][0])+(ik[15][0][1]*Wpk[5][19][1])));
        IkWpk[5][20][1] = ((ik[15][1][2]*Wpk[5][20][2])+((ik[15][1][0]*
          Wpk[5][20][0])+(ik[15][1][1]*Wpk[5][19][1])));
        IkWpk[5][20][2] = ((ik[15][2][2]*Wpk[5][20][2])+((ik[15][2][0]*
          Wpk[5][20][0])+(ik[15][2][1]*Wpk[5][19][1])));
        IkWpk[5][21][0] = ((ik[16][0][2]*Wpk[5][20][2])+((ik[16][0][0]*
          Wpk[5][21][0])+(ik[16][0][1]*Wpk[5][21][1])));
        IkWpk[5][21][1] = ((ik[16][1][2]*Wpk[5][20][2])+((ik[16][1][0]*
          Wpk[5][21][0])+(ik[16][1][1]*Wpk[5][21][1])));
        IkWpk[5][21][2] = ((ik[16][2][2]*Wpk[5][20][2])+((ik[16][2][0]*
          Wpk[5][21][0])+(ik[16][2][1]*Wpk[5][21][1])));
        IkWpk[5][22][0] = ((ik[17][0][2]*c22)-(ik[17][0][0]*s22));
        IkWpk[5][22][1] = ((ik[17][1][2]*c22)-(ik[17][1][0]*s22));
        IkWpk[5][22][2] = ((ik[17][2][2]*c22)-(ik[17][2][0]*s22));
        IkWpk[5][23][0] = ((ik[18][0][2]*Wpk[5][23][2])+((ik[18][0][1]*
          Wpk[5][23][1])-(ik[18][0][0]*s22)));
        IkWpk[5][23][1] = ((ik[18][1][2]*Wpk[5][23][2])+((ik[18][1][1]*
          Wpk[5][23][1])-(ik[18][1][0]*s22)));
        IkWpk[5][23][2] = ((ik[18][2][2]*Wpk[5][23][2])+((ik[18][2][1]*
          Wpk[5][23][1])-(ik[18][2][0]*s22)));
        IkWpk[5][24][0] = ((ik[19][0][2]*Wpk[5][24][2])+((ik[19][0][0]*
          Wpk[5][24][0])+(ik[19][0][1]*Wpk[5][23][1])));
        IkWpk[5][24][1] = ((ik[19][1][2]*Wpk[5][24][2])+((ik[19][1][0]*
          Wpk[5][24][0])+(ik[19][1][1]*Wpk[5][23][1])));
        IkWpk[5][24][2] = ((ik[19][2][2]*Wpk[5][24][2])+((ik[19][2][0]*
          Wpk[5][24][0])+(ik[19][2][1]*Wpk[5][23][1])));
        IkWpk[5][25][0] = ((ik[20][0][2]*Wpk[5][24][2])+((ik[20][0][0]*
          Wpk[5][25][0])+(ik[20][0][1]*Wpk[5][25][1])));
        IkWpk[5][25][1] = ((ik[20][1][2]*Wpk[5][24][2])+((ik[20][1][0]*
          Wpk[5][25][0])+(ik[20][1][1]*Wpk[5][25][1])));
        IkWpk[5][25][2] = ((ik[20][2][2]*Wpk[5][24][2])+((ik[20][2][0]*
          Wpk[5][25][0])+(ik[20][2][1]*Wpk[5][25][1])));
        IkWpk[6][7][0] = ((ik[2][0][2]*c7)-(ik[2][0][0]*s7));
        IkWpk[6][7][1] = ((ik[2][1][2]*c7)-(ik[2][1][0]*s7));
        IkWpk[6][7][2] = ((ik[2][2][2]*c7)-(ik[2][2][0]*s7));
        IkWpk[6][8][0] = ((ik[3][0][2]*Wpk[6][8][2])+((ik[3][0][1]*Wpk[6][8][1])
          -(ik[3][0][0]*s7)));
        IkWpk[6][8][1] = ((ik[3][1][2]*Wpk[6][8][2])+((ik[3][1][1]*Wpk[6][8][1])
          -(ik[3][1][0]*s7)));
        IkWpk[6][8][2] = ((ik[3][2][2]*Wpk[6][8][2])+((ik[3][2][1]*Wpk[6][8][1])
          -(ik[3][2][0]*s7)));
        IkWpk[6][9][0] = ((ik[4][0][2]*Wpk[6][9][2])+((ik[4][0][0]*Wpk[6][9][0])
          +(ik[4][0][1]*Wpk[6][8][1])));
        IkWpk[6][9][1] = ((ik[4][1][2]*Wpk[6][9][2])+((ik[4][1][0]*Wpk[6][9][0])
          +(ik[4][1][1]*Wpk[6][8][1])));
        IkWpk[6][9][2] = ((ik[4][2][2]*Wpk[6][9][2])+((ik[4][2][0]*Wpk[6][9][0])
          +(ik[4][2][1]*Wpk[6][8][1])));
        IkWpk[6][10][0] = ((ik[5][0][2]*Wpk[6][10][2])+((ik[5][0][0]*
          Wpk[6][10][0])+(ik[5][0][1]*Wpk[6][8][1])));
        IkWpk[6][10][1] = ((ik[5][1][2]*Wpk[6][10][2])+((ik[5][1][0]*
          Wpk[6][10][0])+(ik[5][1][1]*Wpk[6][8][1])));
        IkWpk[6][10][2] = ((ik[5][2][2]*Wpk[6][10][2])+((ik[5][2][0]*
          Wpk[6][10][0])+(ik[5][2][1]*Wpk[6][8][1])));
        IkWpk[6][11][0] = ((ik[6][0][2]*Wpk[6][11][2])+((ik[6][0][0]*
          Wpk[6][10][0])+(ik[6][0][1]*Wpk[6][11][1])));
        IkWpk[6][11][1] = ((ik[6][1][2]*Wpk[6][11][2])+((ik[6][1][0]*
          Wpk[6][10][0])+(ik[6][1][1]*Wpk[6][11][1])));
        IkWpk[6][11][2] = ((ik[6][2][2]*Wpk[6][11][2])+((ik[6][2][0]*
          Wpk[6][10][0])+(ik[6][2][1]*Wpk[6][11][1])));
        IkWpk[7][8][0] = ((ik[3][0][1]*c8)-(ik[3][0][2]*s8));
        IkWpk[7][8][1] = ((ik[3][1][1]*c8)-(ik[3][1][2]*s8));
        IkWpk[7][8][2] = ((ik[3][2][1]*c8)-(ik[3][2][2]*s8));
        IkWpk[7][9][0] = ((ik[4][0][2]*Wpk[7][9][2])+((ik[4][0][0]*Wpk[7][9][0])
          +(ik[4][0][1]*c8)));
        IkWpk[7][9][1] = ((ik[4][1][2]*Wpk[7][9][2])+((ik[4][1][0]*Wpk[7][9][0])
          +(ik[4][1][1]*c8)));
        IkWpk[7][9][2] = ((ik[4][2][2]*Wpk[7][9][2])+((ik[4][2][0]*Wpk[7][9][0])
          +(ik[4][2][1]*c8)));
        IkWpk[7][10][0] = ((ik[5][0][2]*Wpk[7][10][2])+((ik[5][0][0]*
          Wpk[7][10][0])+(ik[5][0][1]*c8)));
        IkWpk[7][10][1] = ((ik[5][1][2]*Wpk[7][10][2])+((ik[5][1][0]*
          Wpk[7][10][0])+(ik[5][1][1]*c8)));
        IkWpk[7][10][2] = ((ik[5][2][2]*Wpk[7][10][2])+((ik[5][2][0]*
          Wpk[7][10][0])+(ik[5][2][1]*c8)));
        IkWpk[7][11][0] = ((ik[6][0][2]*Wpk[7][11][2])+((ik[6][0][0]*
          Wpk[7][10][0])+(ik[6][0][1]*Wpk[7][11][1])));
        IkWpk[7][11][1] = ((ik[6][1][2]*Wpk[7][11][2])+((ik[6][1][0]*
          Wpk[7][10][0])+(ik[6][1][1]*Wpk[7][11][1])));
        IkWpk[7][11][2] = ((ik[6][2][2]*Wpk[7][11][2])+((ik[6][2][0]*
          Wpk[7][10][0])+(ik[6][2][1]*Wpk[7][11][1])));
        IkWpk[8][9][0] = ((ik[4][0][0]*c9)+(ik[4][0][2]*s9));
        IkWpk[8][9][1] = ((ik[4][1][0]*c9)+(ik[4][1][2]*s9));
        IkWpk[8][9][2] = ((ik[4][2][0]*c9)+(ik[4][2][2]*s9));
        IkWpk[8][10][0] = ((ik[5][0][0]*Wpk[8][10][0])+(ik[5][0][2]*
          Wpk[8][10][2]));
        IkWpk[8][10][1] = ((ik[5][1][0]*Wpk[8][10][0])+(ik[5][1][2]*
          Wpk[8][10][2]));
        IkWpk[8][10][2] = ((ik[5][2][0]*Wpk[8][10][0])+(ik[5][2][2]*
          Wpk[8][10][2]));
        IkWpk[8][11][0] = ((ik[6][0][2]*Wpk[8][11][2])+((ik[6][0][0]*
          Wpk[8][10][0])+(ik[6][0][1]*Wpk[8][11][1])));
        IkWpk[8][11][1] = ((ik[6][1][2]*Wpk[8][11][2])+((ik[6][1][0]*
          Wpk[8][10][0])+(ik[6][1][1]*Wpk[8][11][1])));
        IkWpk[8][11][2] = ((ik[6][2][2]*Wpk[8][11][2])+((ik[6][2][0]*
          Wpk[8][10][0])+(ik[6][2][1]*Wpk[8][11][1])));
        IkWpk[9][11][0] = ((ik[6][0][1]*c11)-(ik[6][0][2]*s11));
        IkWpk[9][11][1] = ((ik[6][1][1]*c11)-(ik[6][1][2]*s11));
        IkWpk[9][11][2] = ((ik[6][2][1]*c11)-(ik[6][2][2]*s11));
        IkWpk[10][11][0] = ((ik[6][0][1]*c11)-(ik[6][0][2]*s11));
        IkWpk[10][11][1] = ((ik[6][1][1]*c11)-(ik[6][1][2]*s11));
        IkWpk[10][11][2] = ((ik[6][2][1]*c11)-(ik[6][2][2]*s11));
        IkWpk[12][13][0] = ((ik[8][0][2]*c13)-(ik[8][0][0]*s13));
        IkWpk[12][13][1] = ((ik[8][1][2]*c13)-(ik[8][1][0]*s13));
        IkWpk[12][13][2] = ((ik[8][2][2]*c13)-(ik[8][2][0]*s13));
        IkWpk[12][14][0] = ((ik[9][0][2]*Wpk[12][14][2])+((ik[9][0][1]*
          Wpk[12][14][1])-(ik[9][0][0]*s13)));
        IkWpk[12][14][1] = ((ik[9][1][2]*Wpk[12][14][2])+((ik[9][1][1]*
          Wpk[12][14][1])-(ik[9][1][0]*s13)));
        IkWpk[12][14][2] = ((ik[9][2][2]*Wpk[12][14][2])+((ik[9][2][1]*
          Wpk[12][14][1])-(ik[9][2][0]*s13)));
        IkWpk[12][15][0] = ((ik[10][0][2]*Wpk[12][15][2])+((ik[10][0][0]*
          Wpk[12][15][0])+(ik[10][0][1]*Wpk[12][14][1])));
        IkWpk[12][15][1] = ((ik[10][1][2]*Wpk[12][15][2])+((ik[10][1][0]*
          Wpk[12][15][0])+(ik[10][1][1]*Wpk[12][14][1])));
        IkWpk[12][15][2] = ((ik[10][2][2]*Wpk[12][15][2])+((ik[10][2][0]*
          Wpk[12][15][0])+(ik[10][2][1]*Wpk[12][14][1])));
        IkWpk[12][16][0] = ((ik[11][0][2]*Wpk[12][16][2])+((ik[11][0][0]*
          Wpk[12][16][0])+(ik[11][0][1]*Wpk[12][14][1])));
        IkWpk[12][16][1] = ((ik[11][1][2]*Wpk[12][16][2])+((ik[11][1][0]*
          Wpk[12][16][0])+(ik[11][1][1]*Wpk[12][14][1])));
        IkWpk[12][16][2] = ((ik[11][2][2]*Wpk[12][16][2])+((ik[11][2][0]*
          Wpk[12][16][0])+(ik[11][2][1]*Wpk[12][14][1])));
        IkWpk[12][17][0] = ((ik[12][0][2]*Wpk[12][17][2])+((ik[12][0][0]*
          Wpk[12][16][0])+(ik[12][0][1]*Wpk[12][17][1])));
        IkWpk[12][17][1] = ((ik[12][1][2]*Wpk[12][17][2])+((ik[12][1][0]*
          Wpk[12][16][0])+(ik[12][1][1]*Wpk[12][17][1])));
        IkWpk[12][17][2] = ((ik[12][2][2]*Wpk[12][17][2])+((ik[12][2][0]*
          Wpk[12][16][0])+(ik[12][2][1]*Wpk[12][17][1])));
        IkWpk[13][14][0] = ((ik[9][0][1]*c14)-(ik[9][0][2]*s14));
        IkWpk[13][14][1] = ((ik[9][1][1]*c14)-(ik[9][1][2]*s14));
        IkWpk[13][14][2] = ((ik[9][2][1]*c14)-(ik[9][2][2]*s14));
        IkWpk[13][15][0] = ((ik[10][0][2]*Wpk[13][15][2])+((ik[10][0][0]*
          Wpk[13][15][0])+(ik[10][0][1]*c14)));
        IkWpk[13][15][1] = ((ik[10][1][2]*Wpk[13][15][2])+((ik[10][1][0]*
          Wpk[13][15][0])+(ik[10][1][1]*c14)));
        IkWpk[13][15][2] = ((ik[10][2][2]*Wpk[13][15][2])+((ik[10][2][0]*
          Wpk[13][15][0])+(ik[10][2][1]*c14)));
        IkWpk[13][16][0] = ((ik[11][0][2]*Wpk[13][16][2])+((ik[11][0][0]*
          Wpk[13][16][0])+(ik[11][0][1]*c14)));
        IkWpk[13][16][1] = ((ik[11][1][2]*Wpk[13][16][2])+((ik[11][1][0]*
          Wpk[13][16][0])+(ik[11][1][1]*c14)));
        IkWpk[13][16][2] = ((ik[11][2][2]*Wpk[13][16][2])+((ik[11][2][0]*
          Wpk[13][16][0])+(ik[11][2][1]*c14)));
        IkWpk[13][17][0] = ((ik[12][0][2]*Wpk[13][17][2])+((ik[12][0][0]*
          Wpk[13][16][0])+(ik[12][0][1]*Wpk[13][17][1])));
        IkWpk[13][17][1] = ((ik[12][1][2]*Wpk[13][17][2])+((ik[12][1][0]*
          Wpk[13][16][0])+(ik[12][1][1]*Wpk[13][17][1])));
        IkWpk[13][17][2] = ((ik[12][2][2]*Wpk[13][17][2])+((ik[12][2][0]*
          Wpk[13][16][0])+(ik[12][2][1]*Wpk[13][17][1])));
        IkWpk[14][15][0] = ((ik[10][0][0]*c15)+(ik[10][0][2]*s15));
        IkWpk[14][15][1] = ((ik[10][1][0]*c15)+(ik[10][1][2]*s15));
        IkWpk[14][15][2] = ((ik[10][2][0]*c15)+(ik[10][2][2]*s15));
        IkWpk[14][16][0] = ((ik[11][0][0]*Wpk[14][16][0])+(ik[11][0][2]*
          Wpk[14][16][2]));
        IkWpk[14][16][1] = ((ik[11][1][0]*Wpk[14][16][0])+(ik[11][1][2]*
          Wpk[14][16][2]));
        IkWpk[14][16][2] = ((ik[11][2][0]*Wpk[14][16][0])+(ik[11][2][2]*
          Wpk[14][16][2]));
        IkWpk[14][17][0] = ((ik[12][0][2]*Wpk[14][17][2])+((ik[12][0][0]*
          Wpk[14][16][0])+(ik[12][0][1]*Wpk[14][17][1])));
        IkWpk[14][17][1] = ((ik[12][1][2]*Wpk[14][17][2])+((ik[12][1][0]*
          Wpk[14][16][0])+(ik[12][1][1]*Wpk[14][17][1])));
        IkWpk[14][17][2] = ((ik[12][2][2]*Wpk[14][17][2])+((ik[12][2][0]*
          Wpk[14][16][0])+(ik[12][2][1]*Wpk[14][17][1])));
        IkWpk[15][17][0] = ((ik[12][0][1]*c17)-(ik[12][0][2]*s17));
        IkWpk[15][17][1] = ((ik[12][1][1]*c17)-(ik[12][1][2]*s17));
        IkWpk[15][17][2] = ((ik[12][2][1]*c17)-(ik[12][2][2]*s17));
        IkWpk[16][17][0] = ((ik[12][0][1]*c17)-(ik[12][0][2]*s17));
        IkWpk[16][17][1] = ((ik[12][1][1]*c17)-(ik[12][1][2]*s17));
        IkWpk[16][17][2] = ((ik[12][2][1]*c17)-(ik[12][2][2]*s17));
        IkWpk[18][19][0] = ((ik[14][0][1]*c19)-(ik[14][0][2]*s19));
        IkWpk[18][19][1] = ((ik[14][1][1]*c19)-(ik[14][1][2]*s19));
        IkWpk[18][19][2] = ((ik[14][2][1]*c19)-(ik[14][2][2]*s19));
        IkWpk[18][20][0] = ((ik[15][0][2]*Wpk[18][20][2])+((ik[15][0][0]*
          Wpk[18][20][0])+(ik[15][0][1]*c19)));
        IkWpk[18][20][1] = ((ik[15][1][2]*Wpk[18][20][2])+((ik[15][1][0]*
          Wpk[18][20][0])+(ik[15][1][1]*c19)));
        IkWpk[18][20][2] = ((ik[15][2][2]*Wpk[18][20][2])+((ik[15][2][0]*
          Wpk[18][20][0])+(ik[15][2][1]*c19)));
        IkWpk[18][21][0] = ((ik[16][0][2]*Wpk[18][20][2])+((ik[16][0][0]*
          Wpk[18][21][0])+(ik[16][0][1]*Wpk[18][21][1])));
        IkWpk[18][21][1] = ((ik[16][1][2]*Wpk[18][20][2])+((ik[16][1][0]*
          Wpk[18][21][0])+(ik[16][1][1]*Wpk[18][21][1])));
        IkWpk[18][21][2] = ((ik[16][2][2]*Wpk[18][20][2])+((ik[16][2][0]*
          Wpk[18][21][0])+(ik[16][2][1]*Wpk[18][21][1])));
        IkWpk[19][20][0] = ((ik[15][0][0]*c20)+(ik[15][0][2]*s20));
        IkWpk[19][20][1] = ((ik[15][1][0]*c20)+(ik[15][1][2]*s20));
        IkWpk[19][20][2] = ((ik[15][2][0]*c20)+(ik[15][2][2]*s20));
        IkWpk[19][21][0] = ((ik[16][0][2]*s20)+((ik[16][0][0]*Wpk[19][21][0])+(
          ik[16][0][1]*Wpk[19][21][1])));
        IkWpk[19][21][1] = ((ik[16][1][2]*s20)+((ik[16][1][0]*Wpk[19][21][0])+(
          ik[16][1][1]*Wpk[19][21][1])));
        IkWpk[19][21][2] = ((ik[16][2][2]*s20)+((ik[16][2][0]*Wpk[19][21][0])+(
          ik[16][2][1]*Wpk[19][21][1])));
        IkWpk[20][21][0] = ((ik[16][0][0]*s21)+(ik[16][0][1]*c21));
        IkWpk[20][21][1] = ((ik[16][1][0]*s21)+(ik[16][1][1]*c21));
        IkWpk[20][21][2] = ((ik[16][2][0]*s21)+(ik[16][2][1]*c21));
        IkWpk[22][23][0] = ((ik[18][0][1]*c23)-(ik[18][0][2]*s23));
        IkWpk[22][23][1] = ((ik[18][1][1]*c23)-(ik[18][1][2]*s23));
        IkWpk[22][23][2] = ((ik[18][2][1]*c23)-(ik[18][2][2]*s23));
        IkWpk[22][24][0] = ((ik[19][0][2]*Wpk[22][24][2])+((ik[19][0][0]*
          Wpk[22][24][0])+(ik[19][0][1]*c23)));
        IkWpk[22][24][1] = ((ik[19][1][2]*Wpk[22][24][2])+((ik[19][1][0]*
          Wpk[22][24][0])+(ik[19][1][1]*c23)));
        IkWpk[22][24][2] = ((ik[19][2][2]*Wpk[22][24][2])+((ik[19][2][0]*
          Wpk[22][24][0])+(ik[19][2][1]*c23)));
        IkWpk[22][25][0] = ((ik[20][0][2]*Wpk[22][24][2])+((ik[20][0][0]*
          Wpk[22][25][0])+(ik[20][0][1]*Wpk[22][25][1])));
        IkWpk[22][25][1] = ((ik[20][1][2]*Wpk[22][24][2])+((ik[20][1][0]*
          Wpk[22][25][0])+(ik[20][1][1]*Wpk[22][25][1])));
        IkWpk[22][25][2] = ((ik[20][2][2]*Wpk[22][24][2])+((ik[20][2][0]*
          Wpk[22][25][0])+(ik[20][2][1]*Wpk[22][25][1])));
        IkWpk[23][24][0] = ((ik[19][0][0]*c24)+(ik[19][0][2]*s24));
        IkWpk[23][24][1] = ((ik[19][1][0]*c24)+(ik[19][1][2]*s24));
        IkWpk[23][24][2] = ((ik[19][2][0]*c24)+(ik[19][2][2]*s24));
        IkWpk[23][25][0] = ((ik[20][0][2]*s24)+((ik[20][0][0]*Wpk[23][25][0])+(
          ik[20][0][1]*Wpk[23][25][1])));
        IkWpk[23][25][1] = ((ik[20][1][2]*s24)+((ik[20][1][0]*Wpk[23][25][0])+(
          ik[20][1][1]*Wpk[23][25][1])));
        IkWpk[23][25][2] = ((ik[20][2][2]*s24)+((ik[20][2][0]*Wpk[23][25][0])+(
          ik[20][2][1]*Wpk[23][25][1])));
        IkWpk[24][25][0] = ((ik[20][0][0]*s25)+(ik[20][0][1]*c25));
        IkWpk[24][25][1] = ((ik[20][1][0]*s25)+(ik[20][1][1]*c25));
        IkWpk[24][25][2] = ((ik[20][2][0]*s25)+(ik[20][2][1]*c25));
        temp[0] = ((mk[2]*((Vpk[0][7][2]*Vpk[0][7][2])+((Vpk[0][6][1]*
          Vpk[0][6][1])+(Vpk[0][7][0]*Vpk[0][7][0]))))+((mk[0]*((Cik[3][0][2]*
          Cik[3][0][2])+((Cik[3][0][0]*Cik[3][0][0])+(Cik[3][0][1]*Cik[3][0][1])
          )))+(mk[1]*((Cik[3][0][2]*Cik[3][0][2])+((Vpk[0][6][0]*Vpk[0][6][0])+(
          Vpk[0][6][1]*Vpk[0][6][1]))))));
        temp[1] = ((mk[5]*((Vpk[0][10][2]*Vpk[0][10][2])+((Vpk[0][8][1]*
          Vpk[0][8][1])+(Vpk[0][10][0]*Vpk[0][10][0]))))+((mk[4]*((Vpk[0][9][2]*
          Vpk[0][9][2])+((Vpk[0][8][1]*Vpk[0][8][1])+(Vpk[0][9][0]*Vpk[0][9][0])
          )))+((mk[3]*((Vpk[0][8][2]*Vpk[0][8][2])+((Vpk[0][7][0]*Vpk[0][7][0])+
          (Vpk[0][8][1]*Vpk[0][8][1]))))+temp[0])));
        temp[2] = ((mk[8]*((Vpk[0][13][2]*Vpk[0][13][2])+((Vpk[0][12][1]*
          Vpk[0][12][1])+(Vpk[0][13][0]*Vpk[0][13][0]))))+((mk[7]*((Cik[3][0][2]
          *Cik[3][0][2])+((Vpk[0][12][0]*Vpk[0][12][0])+(Vpk[0][12][1]*
          Vpk[0][12][1]))))+((mk[6]*((Vpk[0][11][2]*Vpk[0][11][2])+((
          Vpk[0][10][0]*Vpk[0][10][0])+(Vpk[0][11][1]*Vpk[0][11][1]))))+temp[1])
          ));
        temp[3] = ((mk[11]*((Vpk[0][16][2]*Vpk[0][16][2])+((Vpk[0][14][1]*
          Vpk[0][14][1])+(Vpk[0][16][0]*Vpk[0][16][0]))))+((mk[10]*((
          Vpk[0][15][2]*Vpk[0][15][2])+((Vpk[0][14][1]*Vpk[0][14][1])+(
          Vpk[0][15][0]*Vpk[0][15][0]))))+((mk[9]*((Vpk[0][14][2]*Vpk[0][14][2])
          +((Vpk[0][13][0]*Vpk[0][13][0])+(Vpk[0][14][1]*Vpk[0][14][1]))))+
          temp[2])));
        temp[4] = ((mk[14]*((Vpk[0][19][2]*Vpk[0][19][2])+((Vpk[0][18][0]*
          Vpk[0][18][0])+(Vpk[0][19][1]*Vpk[0][19][1]))))+((mk[13]*((
          Vpk[0][18][2]*Vpk[0][18][2])+((Cik[3][0][1]*Cik[3][0][1])+(
          Vpk[0][18][0]*Vpk[0][18][0]))))+((mk[12]*((Vpk[0][17][2]*Vpk[0][17][2]
          )+((Vpk[0][16][0]*Vpk[0][16][0])+(Vpk[0][17][1]*Vpk[0][17][1]))))+
          temp[3])));
        temp[5] = ((mk[17]*((Vpk[0][22][2]*Vpk[0][22][2])+((Cik[3][0][1]*
          Cik[3][0][1])+(Vpk[0][22][0]*Vpk[0][22][0]))))+((mk[16]*((
          Vpk[0][20][2]*Vpk[0][20][2])+((Vpk[0][21][0]*Vpk[0][21][0])+(
          Vpk[0][21][1]*Vpk[0][21][1]))))+((mk[15]*((Vpk[0][20][2]*Vpk[0][20][2]
          )+((Vpk[0][19][1]*Vpk[0][19][1])+(Vpk[0][20][0]*Vpk[0][20][0]))))+
          temp[4])));
        mm[0][0] = ((mk[20]*((Vpk[0][24][2]*Vpk[0][24][2])+((Vpk[0][25][0]*
          Vpk[0][25][0])+(Vpk[0][25][1]*Vpk[0][25][1]))))+((mk[19]*((
          Vpk[0][24][2]*Vpk[0][24][2])+((Vpk[0][23][1]*Vpk[0][23][1])+(
          Vpk[0][24][0]*Vpk[0][24][0]))))+((mk[18]*((Vpk[0][23][2]*Vpk[0][23][2]
          )+((Vpk[0][22][0]*Vpk[0][22][0])+(Vpk[0][23][1]*Vpk[0][23][1]))))+
          temp[5])));
        temp[0] = ((mk[2]*((Vpk[0][7][2]*Vpk[1][7][2])+((Vpk[0][6][1]*
          Vpk[1][6][1])+(Vpk[0][7][0]*Vpk[1][7][0]))))+((mk[0]*((Cik[3][0][2]*
          Cik[3][1][2])+((Cik[3][0][0]*Cik[3][1][0])+(Cik[3][0][1]*Cik[3][1][1])
          )))+(mk[1]*((Cik[3][0][2]*Cik[3][1][2])+((Vpk[0][6][0]*Vpk[1][6][0])+(
          Vpk[0][6][1]*Vpk[1][6][1]))))));
        temp[1] = ((mk[5]*((Vpk[0][10][2]*Vpk[1][10][2])+((Vpk[0][8][1]*
          Vpk[1][8][1])+(Vpk[0][10][0]*Vpk[1][10][0]))))+((mk[4]*((Vpk[0][9][2]*
          Vpk[1][9][2])+((Vpk[0][8][1]*Vpk[1][8][1])+(Vpk[0][9][0]*Vpk[1][9][0])
          )))+((mk[3]*((Vpk[0][8][2]*Vpk[1][8][2])+((Vpk[0][7][0]*Vpk[1][7][0])+
          (Vpk[0][8][1]*Vpk[1][8][1]))))+temp[0])));
        temp[2] = ((mk[8]*((Vpk[0][13][2]*Vpk[1][13][2])+((Vpk[0][12][1]*
          Vpk[1][12][1])+(Vpk[0][13][0]*Vpk[1][13][0]))))+((mk[7]*((Cik[3][0][2]
          *Cik[3][1][2])+((Vpk[0][12][0]*Vpk[1][12][0])+(Vpk[0][12][1]*
          Vpk[1][12][1]))))+((mk[6]*((Vpk[0][11][2]*Vpk[1][11][2])+((
          Vpk[0][10][0]*Vpk[1][10][0])+(Vpk[0][11][1]*Vpk[1][11][1]))))+temp[1])
          ));
        temp[3] = ((mk[11]*((Vpk[0][16][2]*Vpk[1][16][2])+((Vpk[0][14][1]*
          Vpk[1][14][1])+(Vpk[0][16][0]*Vpk[1][16][0]))))+((mk[10]*((
          Vpk[0][15][2]*Vpk[1][15][2])+((Vpk[0][14][1]*Vpk[1][14][1])+(
          Vpk[0][15][0]*Vpk[1][15][0]))))+((mk[9]*((Vpk[0][14][2]*Vpk[1][14][2])
          +((Vpk[0][13][0]*Vpk[1][13][0])+(Vpk[0][14][1]*Vpk[1][14][1]))))+
          temp[2])));
        temp[4] = ((mk[14]*((Vpk[0][19][2]*Vpk[1][19][2])+((Vpk[0][18][0]*
          Vpk[1][18][0])+(Vpk[0][19][1]*Vpk[1][19][1]))))+((mk[13]*((
          Vpk[0][18][2]*Vpk[1][18][2])+((Cik[3][0][1]*Cik[3][1][1])+(
          Vpk[0][18][0]*Vpk[1][18][0]))))+((mk[12]*((Vpk[0][17][2]*Vpk[1][17][2]
          )+((Vpk[0][16][0]*Vpk[1][16][0])+(Vpk[0][17][1]*Vpk[1][17][1]))))+
          temp[3])));
        temp[5] = ((mk[17]*((Vpk[0][22][2]*Vpk[1][22][2])+((Cik[3][0][1]*
          Cik[3][1][1])+(Vpk[0][22][0]*Vpk[1][22][0]))))+((mk[16]*((
          Vpk[0][20][2]*Vpk[1][20][2])+((Vpk[0][21][0]*Vpk[1][21][0])+(
          Vpk[0][21][1]*Vpk[1][21][1]))))+((mk[15]*((Vpk[0][20][2]*Vpk[1][20][2]
          )+((Vpk[0][19][1]*Vpk[1][19][1])+(Vpk[0][20][0]*Vpk[1][20][0]))))+
          temp[4])));
        mm[0][1] = ((mk[20]*((Vpk[0][24][2]*Vpk[1][24][2])+((Vpk[0][25][0]*
          Vpk[1][25][0])+(Vpk[0][25][1]*Vpk[1][25][1]))))+((mk[19]*((
          Vpk[0][24][2]*Vpk[1][24][2])+((Vpk[0][23][1]*Vpk[1][23][1])+(
          Vpk[0][24][0]*Vpk[1][24][0]))))+((mk[18]*((Vpk[0][23][2]*Vpk[1][23][2]
          )+((Vpk[0][22][0]*Vpk[1][22][0])+(Vpk[0][23][1]*Vpk[1][23][1]))))+
          temp[5])));
        temp[0] = ((mk[2]*((Vpk[0][7][2]*Vpk[2][7][2])+((Vpk[0][6][1]*
          Vpk[2][6][1])+(Vpk[0][7][0]*Vpk[2][7][0]))))+((mk[0]*((Cik[3][0][2]*
          Cik[3][2][2])+((Cik[3][0][0]*Cik[3][2][0])+(Cik[3][0][1]*Cik[3][2][1])
          )))+(mk[1]*((Cik[3][0][2]*Cik[3][2][2])+((Vpk[0][6][0]*Vpk[2][6][0])+(
          Vpk[0][6][1]*Vpk[2][6][1]))))));
        temp[1] = ((mk[5]*((Vpk[0][10][2]*Vpk[2][10][2])+((Vpk[0][8][1]*
          Vpk[2][8][1])+(Vpk[0][10][0]*Vpk[2][10][0]))))+((mk[4]*((Vpk[0][9][2]*
          Vpk[2][9][2])+((Vpk[0][8][1]*Vpk[2][8][1])+(Vpk[0][9][0]*Vpk[2][9][0])
          )))+((mk[3]*((Vpk[0][8][2]*Vpk[2][8][2])+((Vpk[0][7][0]*Vpk[2][7][0])+
          (Vpk[0][8][1]*Vpk[2][8][1]))))+temp[0])));
        temp[2] = ((mk[8]*((Vpk[0][13][2]*Vpk[2][13][2])+((Vpk[0][12][1]*
          Vpk[2][12][1])+(Vpk[0][13][0]*Vpk[2][13][0]))))+((mk[7]*((Cik[3][0][2]
          *Cik[3][2][2])+((Vpk[0][12][0]*Vpk[2][12][0])+(Vpk[0][12][1]*
          Vpk[2][12][1]))))+((mk[6]*((Vpk[0][11][2]*Vpk[2][11][2])+((
          Vpk[0][10][0]*Vpk[2][10][0])+(Vpk[0][11][1]*Vpk[2][11][1]))))+temp[1])
          ));
        temp[3] = ((mk[11]*((Vpk[0][16][2]*Vpk[2][16][2])+((Vpk[0][14][1]*
          Vpk[2][14][1])+(Vpk[0][16][0]*Vpk[2][16][0]))))+((mk[10]*((
          Vpk[0][15][2]*Vpk[2][15][2])+((Vpk[0][14][1]*Vpk[2][14][1])+(
          Vpk[0][15][0]*Vpk[2][15][0]))))+((mk[9]*((Vpk[0][14][2]*Vpk[2][14][2])
          +((Vpk[0][13][0]*Vpk[2][13][0])+(Vpk[0][14][1]*Vpk[2][14][1]))))+
          temp[2])));
        temp[4] = ((mk[14]*((Vpk[0][19][2]*Vpk[2][19][2])+((Vpk[0][18][0]*
          Vpk[2][18][0])+(Vpk[0][19][1]*Vpk[2][19][1]))))+((mk[13]*((
          Vpk[0][18][2]*Vpk[2][18][2])+((Cik[3][0][1]*Cik[3][2][1])+(
          Vpk[0][18][0]*Vpk[2][18][0]))))+((mk[12]*((Vpk[0][17][2]*Vpk[2][17][2]
          )+((Vpk[0][16][0]*Vpk[2][16][0])+(Vpk[0][17][1]*Vpk[2][17][1]))))+
          temp[3])));
        temp[5] = ((mk[17]*((Vpk[0][22][2]*Vpk[2][22][2])+((Cik[3][0][1]*
          Cik[3][2][1])+(Vpk[0][22][0]*Vpk[2][22][0]))))+((mk[16]*((
          Vpk[0][20][2]*Vpk[2][20][2])+((Vpk[0][21][0]*Vpk[2][21][0])+(
          Vpk[0][21][1]*Vpk[2][21][1]))))+((mk[15]*((Vpk[0][20][2]*Vpk[2][20][2]
          )+((Vpk[0][19][1]*Vpk[2][19][1])+(Vpk[0][20][0]*Vpk[2][20][0]))))+
          temp[4])));
        mm[0][2] = ((mk[20]*((Vpk[0][24][2]*Vpk[2][24][2])+((Vpk[0][25][0]*
          Vpk[2][25][0])+(Vpk[0][25][1]*Vpk[2][25][1]))))+((mk[19]*((
          Vpk[0][24][2]*Vpk[2][24][2])+((Vpk[0][23][1]*Vpk[2][23][1])+(
          Vpk[0][24][0]*Vpk[2][24][0]))))+((mk[18]*((Vpk[0][23][2]*Vpk[2][23][2]
          )+((Vpk[0][22][0]*Vpk[2][22][0])+(Vpk[0][23][1]*Vpk[2][23][1]))))+
          temp[5])));
        temp[0] = ((mk[3]*((Vpk[0][8][2]*Vpk[3][8][2])+((Vpk[0][7][0]*
          Vpk[3][8][0])+(Vpk[0][8][1]*Vpk[3][8][1]))))+((mk[2]*((Vpk[0][7][2]*
          Vpk[3][7][2])+((Vpk[0][6][1]*Vpk[3][7][1])+(Vpk[0][7][0]*Vpk[3][7][0])
          )))+((mk[0]*((Cik[3][0][1]*rk[0][2])-(Cik[3][0][2]*rk[0][1])))+(mk[1]*
          ((Cik[3][0][2]*Vpk[3][6][2])+((Vpk[0][6][0]*Vpk[3][6][0])+(
          Vpk[0][6][1]*Vpk[3][6][1])))))));
        temp[1] = ((mk[6]*((Vpk[0][11][2]*Vpk[3][11][2])+((Vpk[0][10][0]*
          Vpk[3][11][0])+(Vpk[0][11][1]*Vpk[3][11][1]))))+((mk[5]*((
          Vpk[0][10][2]*Vpk[3][10][2])+((Vpk[0][8][1]*Vpk[3][10][1])+(
          Vpk[0][10][0]*Vpk[3][10][0]))))+((mk[4]*((Vpk[0][9][2]*Vpk[3][9][2])+(
          (Vpk[0][8][1]*Vpk[3][9][1])+(Vpk[0][9][0]*Vpk[3][9][0]))))+temp[0])));
        temp[2] = ((mk[9]*((Vpk[0][14][2]*Vpk[3][14][2])+((Vpk[0][13][0]*
          Vpk[3][14][0])+(Vpk[0][14][1]*Vpk[3][14][1]))))+((mk[8]*((
          Vpk[0][13][2]*Vpk[3][13][2])+((Vpk[0][12][1]*Vpk[3][13][1])+(
          Vpk[0][13][0]*Vpk[3][13][0]))))+((mk[7]*((Cik[3][0][2]*Vpk[3][12][2])+
          ((Vpk[0][12][0]*Vpk[3][12][0])+(Vpk[0][12][1]*Vpk[3][12][1]))))+
          temp[1])));
        temp[3] = ((mk[12]*((Vpk[0][17][2]*Vpk[3][17][2])+((Vpk[0][16][0]*
          Vpk[3][17][0])+(Vpk[0][17][1]*Vpk[3][17][1]))))+((mk[11]*((
          Vpk[0][16][2]*Vpk[3][16][2])+((Vpk[0][14][1]*Vpk[3][16][1])+(
          Vpk[0][16][0]*Vpk[3][16][0]))))+((mk[10]*((Vpk[0][15][2]*Vpk[3][15][2]
          )+((Vpk[0][14][1]*Vpk[3][15][1])+(Vpk[0][15][0]*Vpk[3][15][0]))))+
          temp[2])));
        temp[4] = ((mk[15]*((Vpk[0][20][2]*Vpk[3][20][2])+((Vpk[0][19][1]*
          Vpk[3][20][1])+(Vpk[0][20][0]*Vpk[3][20][0]))))+((mk[14]*((
          Vpk[0][19][2]*Vpk[3][19][2])+((Vpk[0][18][0]*Vpk[3][19][0])+(
          Vpk[0][19][1]*Vpk[3][19][1]))))+((mk[13]*((Vpk[0][18][2]*Vpk[3][18][2]
          )+((Cik[3][0][1]*Vpk[3][18][1])+(Vpk[0][18][0]*Vpk[3][18][0]))))+
          temp[3])));
        temp[5] = ((mk[18]*((Vpk[0][23][2]*Vpk[3][23][2])+((Vpk[0][22][0]*
          Vpk[3][23][0])+(Vpk[0][23][1]*Vpk[3][23][1]))))+((mk[17]*((
          Vpk[0][22][2]*Vpk[3][22][2])+((Cik[3][0][1]*Vpk[3][22][1])+(
          Vpk[0][22][0]*Vpk[3][22][0]))))+((mk[16]*((Vpk[0][20][2]*Vpk[3][21][2]
          )+((Vpk[0][21][0]*Vpk[3][21][0])+(Vpk[0][21][1]*Vpk[3][21][1]))))+
          temp[4])));
        mm[0][3] = ((mk[20]*((Vpk[0][24][2]*Vpk[3][25][2])+((Vpk[0][25][0]*
          Vpk[3][25][0])+(Vpk[0][25][1]*Vpk[3][25][1]))))+((mk[19]*((
          Vpk[0][24][2]*Vpk[3][24][2])+((Vpk[0][23][1]*Vpk[3][24][1])+(
          Vpk[0][24][0]*Vpk[3][24][0]))))+temp[5]));
        temp[0] = ((mk[3]*((Vpk[0][8][2]*Vpk[4][8][2])+((Vpk[0][7][0]*
          Vpk[4][8][0])+(Vpk[0][8][1]*Vpk[4][8][1]))))+((mk[2]*((Vpk[0][7][2]*
          Vpk[4][7][2])+((Vpk[0][6][1]*Vpk[4][7][1])+(Vpk[0][7][0]*Vpk[4][7][0])
          )))+((mk[0]*((Cik[3][0][2]*rk[0][0])-(Cik[3][0][0]*rk[0][2])))+(mk[1]*
          ((Cik[3][0][2]*Vpk[4][6][2])+((Vpk[0][6][0]*Vpk[4][6][0])+(
          Vpk[0][6][1]*Vpk[4][6][1])))))));
        temp[1] = ((mk[6]*((Vpk[0][11][2]*Vpk[4][11][2])+((Vpk[0][10][0]*
          Vpk[4][11][0])+(Vpk[0][11][1]*Vpk[4][11][1]))))+((mk[5]*((
          Vpk[0][10][2]*Vpk[4][10][2])+((Vpk[0][8][1]*Vpk[4][10][1])+(
          Vpk[0][10][0]*Vpk[4][10][0]))))+((mk[4]*((Vpk[0][9][2]*Vpk[4][9][2])+(
          (Vpk[0][8][1]*Vpk[4][9][1])+(Vpk[0][9][0]*Vpk[4][9][0]))))+temp[0])));
        temp[2] = ((mk[9]*((Vpk[0][14][2]*Vpk[4][14][2])+((Vpk[0][13][0]*
          Vpk[4][14][0])+(Vpk[0][14][1]*Vpk[4][14][1]))))+((mk[8]*((
          Vpk[0][13][2]*Vpk[4][13][2])+((Vpk[0][12][1]*Vpk[4][13][1])+(
          Vpk[0][13][0]*Vpk[4][13][0]))))+((mk[7]*((Cik[3][0][2]*Vpk[4][12][2])+
          ((Vpk[0][12][0]*Vpk[4][12][0])+(Vpk[0][12][1]*Vpk[4][12][1]))))+
          temp[1])));
        temp[3] = ((mk[13]*((Vpk[0][18][0]*Vpk[4][18][0])+(Vpk[0][18][2]*
          Vpk[4][18][2])))+((mk[12]*((Vpk[0][17][2]*Vpk[4][17][2])+((
          Vpk[0][16][0]*Vpk[4][17][0])+(Vpk[0][17][1]*Vpk[4][17][1]))))+((mk[11]
          *((Vpk[0][16][2]*Vpk[4][16][2])+((Vpk[0][14][1]*Vpk[4][16][1])+(
          Vpk[0][16][0]*Vpk[4][16][0]))))+((mk[10]*((Vpk[0][15][2]*Vpk[4][15][2]
          )+((Vpk[0][14][1]*Vpk[4][15][1])+(Vpk[0][15][0]*Vpk[4][15][0]))))+
          temp[2]))));
        temp[4] = ((mk[17]*((Vpk[0][22][0]*Vpk[4][22][0])+(Vpk[0][22][2]*
          Vpk[4][22][2])))+((mk[16]*((Vpk[0][20][2]*Vpk[4][21][2])+((
          Vpk[0][21][0]*Vpk[4][21][0])+(Vpk[0][21][1]*Vpk[4][21][1]))))+((mk[15]
          *((Vpk[0][20][2]*Vpk[4][20][2])+((Vpk[0][19][1]*Vpk[4][20][1])+(
          Vpk[0][20][0]*Vpk[4][20][0]))))+((mk[14]*((Vpk[0][19][2]*Vpk[4][19][2]
          )+((Vpk[0][18][0]*Vpk[4][19][0])+(Vpk[0][19][1]*Vpk[4][19][1]))))+
          temp[3]))));
        mm[0][4] = ((mk[20]*((Vpk[0][24][2]*Vpk[4][25][2])+((Vpk[0][25][0]*
          Vpk[4][25][0])+(Vpk[0][25][1]*Vpk[4][25][1]))))+((mk[19]*((
          Vpk[0][24][2]*Vpk[4][24][2])+((Vpk[0][23][1]*Vpk[4][24][1])+(
          Vpk[0][24][0]*Vpk[4][24][0]))))+((mk[18]*((Vpk[0][23][2]*Vpk[4][23][2]
          )+((Vpk[0][22][0]*Vpk[4][23][0])+(Vpk[0][23][1]*Vpk[4][23][1]))))+
          temp[4])));
        temp[0] = ((mk[3]*((Vpk[0][8][2]*Vpk[5][8][2])+((Vpk[0][7][0]*
          Vpk[5][8][0])+(Vpk[0][8][1]*Vpk[5][8][1]))))+((mk[2]*((Vpk[0][7][2]*
          Vpk[5][7][2])+((Vpk[0][6][1]*Vpk[5][7][1])+(Vpk[0][7][0]*Vpk[5][7][0])
          )))+((mk[0]*((Cik[3][0][0]*rk[0][1])-(Cik[3][0][1]*rk[0][0])))+(mk[1]*
          ((Vpk[0][6][0]*Vpk[5][6][0])+(Vpk[0][6][1]*Vpk[5][6][1]))))));
        temp[1] = ((mk[7]*((Vpk[0][12][0]*Vpk[5][12][0])+(Vpk[0][12][1]*
          Vpk[5][12][1])))+((mk[6]*((Vpk[0][11][2]*Vpk[5][11][2])+((
          Vpk[0][10][0]*Vpk[5][11][0])+(Vpk[0][11][1]*Vpk[5][11][1]))))+((mk[5]*
          ((Vpk[0][10][2]*Vpk[5][10][2])+((Vpk[0][8][1]*Vpk[5][10][1])+(
          Vpk[0][10][0]*Vpk[5][10][0]))))+((mk[4]*((Vpk[0][9][2]*Vpk[5][9][2])+(
          (Vpk[0][8][1]*Vpk[5][9][1])+(Vpk[0][9][0]*Vpk[5][9][0]))))+temp[0]))))
          ;
        temp[2] = ((mk[10]*((Vpk[0][15][2]*Vpk[5][15][2])+((Vpk[0][14][1]*
          Vpk[5][15][1])+(Vpk[0][15][0]*Vpk[5][15][0]))))+((mk[9]*((
          Vpk[0][14][2]*Vpk[5][14][2])+((Vpk[0][13][0]*Vpk[5][14][0])+(
          Vpk[0][14][1]*Vpk[5][14][1]))))+((mk[8]*((Vpk[0][13][2]*Vpk[5][13][2])
          +((Vpk[0][12][1]*Vpk[5][13][1])+(Vpk[0][13][0]*Vpk[5][13][0]))))+
          temp[1])));
        temp[3] = ((mk[13]*((Vpk[0][18][2]*Vpk[5][18][2])+((Cik[3][0][1]*
          Vpk[5][18][1])+(Vpk[0][18][0]*Vpk[5][18][0]))))+((mk[12]*((
          Vpk[0][17][2]*Vpk[5][17][2])+((Vpk[0][16][0]*Vpk[5][17][0])+(
          Vpk[0][17][1]*Vpk[5][17][1]))))+((mk[11]*((Vpk[0][16][2]*Vpk[5][16][2]
          )+((Vpk[0][14][1]*Vpk[5][16][1])+(Vpk[0][16][0]*Vpk[5][16][0]))))+
          temp[2])));
        temp[4] = ((mk[16]*((Vpk[0][20][2]*Vpk[5][21][2])+((Vpk[0][21][0]*
          Vpk[5][21][0])+(Vpk[0][21][1]*Vpk[5][21][1]))))+((mk[15]*((
          Vpk[0][20][2]*Vpk[5][20][2])+((Vpk[0][19][1]*Vpk[5][20][1])+(
          Vpk[0][20][0]*Vpk[5][20][0]))))+((mk[14]*((Vpk[0][19][2]*Vpk[5][19][2]
          )+((Vpk[0][18][0]*Vpk[5][19][0])+(Vpk[0][19][1]*Vpk[5][19][1]))))+
          temp[3])));
        temp[5] = ((mk[19]*((Vpk[0][24][2]*Vpk[5][24][2])+((Vpk[0][23][1]*
          Vpk[5][24][1])+(Vpk[0][24][0]*Vpk[5][24][0]))))+((mk[18]*((
          Vpk[0][23][2]*Vpk[5][23][2])+((Vpk[0][22][0]*Vpk[5][23][0])+(
          Vpk[0][23][1]*Vpk[5][23][1]))))+((mk[17]*((Vpk[0][22][2]*Vpk[5][22][2]
          )+((Cik[3][0][1]*Vpk[5][22][1])+(Vpk[0][22][0]*Vpk[5][22][0]))))+
          temp[4])));
        mm[0][5] = ((mk[20]*((Vpk[0][24][2]*Vpk[5][25][2])+((Vpk[0][25][0]*
          Vpk[5][25][0])+(Vpk[0][25][1]*Vpk[5][25][1]))))+temp[5]);
        temp[0] = ((mk[4]*((Vpk[0][9][2]*Vpk[6][9][2])+((Vpk[0][8][1]*
          Vpk[6][9][1])+(Vpk[0][9][0]*Vpk[6][9][0]))))+((mk[3]*((Vpk[0][8][2]*
          Vpk[6][8][2])+((Vpk[0][7][0]*Vpk[6][8][0])+(Vpk[0][8][1]*Vpk[6][8][1])
          )))+((mk[1]*((rk[1][1]*Vpk[0][6][0])-(rk[1][0]*Vpk[0][6][1])))+(mk[2]*
          ((Vpk[0][7][2]*Vpk[6][7][2])+((Vpk[0][6][1]*Vpk[6][7][1])+(
          Vpk[0][7][0]*Vpk[6][7][0])))))));
        mm[0][6] = ((mk[6]*((Vpk[0][11][2]*Vpk[6][11][2])+((Vpk[0][10][0]*
          Vpk[6][11][0])+(Vpk[0][11][1]*Vpk[6][11][1]))))+((mk[5]*((
          Vpk[0][10][2]*Vpk[6][10][2])+((Vpk[0][8][1]*Vpk[6][10][1])+(
          Vpk[0][10][0]*Vpk[6][10][0]))))+temp[0]));
        temp[0] = ((mk[5]*((Vpk[0][10][2]*Vpk[7][10][2])+((Vpk[0][8][1]*
          Vpk[7][10][1])+(Vpk[0][10][0]*Vpk[7][10][0]))))+((mk[4]*((Vpk[0][9][2]
          *Vpk[7][9][2])+((Vpk[0][8][1]*Vpk[7][9][1])+(Vpk[0][9][0]*Vpk[7][9][0]
          ))))+((mk[2]*((rk[2][0]*Vpk[0][7][2])-(rk[2][2]*Vpk[0][7][0])))+(mk[3]
          *((Vpk[0][8][2]*Vpk[7][8][2])+((Vpk[0][7][0]*Vpk[7][8][0])+(
          Vpk[0][8][1]*Vpk[7][8][1])))))));
        mm[0][7] = ((mk[6]*((Vpk[0][11][2]*Vpk[7][11][2])+((Vpk[0][10][0]*
          Vpk[7][11][0])+(Vpk[0][11][1]*Vpk[7][11][1]))))+temp[0]);
        mm[0][8] = ((mk[6]*((Vpk[0][11][2]*Vpk[8][11][2])+((Vpk[0][10][0]*
          Vpk[8][11][0])+(Vpk[0][11][1]*Vpk[8][11][1]))))+((mk[5]*((
          Vpk[0][10][2]*Vpk[8][10][2])+((Vpk[0][8][1]*Vpk[8][10][1])+(
          Vpk[0][10][0]*Vpk[8][10][0]))))+((mk[3]*((rk[3][2]*Vpk[0][8][1])-(
          rk[3][1]*Vpk[0][8][2])))+(mk[4]*((Vpk[0][9][2]*Vpk[8][9][2])+((
          Vpk[0][8][1]*Vpk[8][9][1])+(Vpk[0][9][0]*Vpk[8][9][0])))))));
        mm[0][9] = ((mk[6]*((Vpk[0][11][2]*Vpk[9][11][2])+((Vpk[0][10][0]*
          Vpk[9][11][0])+(Vpk[0][11][1]*Vpk[9][11][1]))))+((mk[4]*((rk[4][0]*
          Vpk[0][9][2])-(rk[4][2]*Vpk[0][9][0])))+(mk[5]*((Vpk[0][10][0]*
          Vpk[9][10][0])+(Vpk[0][10][2]*Vpk[9][10][2])))));
        mm[0][10] = ((mk[5]*((rk[5][0]*Vpk[0][10][2])-(rk[5][2]*Vpk[0][10][0])))
          +(mk[6]*((Vpk[0][11][2]*Vpk[10][11][2])+((Vpk[0][10][0]*Vpk[10][11][0]
          )+(Vpk[0][11][1]*Vpk[10][11][1])))));
        mm[0][11] = (mk[6]*((rk[6][2]*Vpk[0][11][1])-(rk[6][1]*Vpk[0][11][2])));
        temp[0] = ((mk[10]*((Vpk[0][15][2]*Vpk[12][15][2])+((Vpk[0][14][1]*
          Vpk[12][15][1])+(Vpk[0][15][0]*Vpk[12][15][0]))))+((mk[9]*((
          Vpk[0][14][2]*Vpk[12][14][2])+((Vpk[0][13][0]*Vpk[12][14][0])+(
          Vpk[0][14][1]*Vpk[12][14][1]))))+((mk[7]*((rk[7][1]*Vpk[0][12][0])-(
          rk[7][0]*Vpk[0][12][1])))+(mk[8]*((Vpk[0][13][2]*Vpk[12][13][2])+((
          Vpk[0][12][1]*Vpk[12][13][1])+(Vpk[0][13][0]*Vpk[12][13][0])))))));
        mm[0][12] = ((mk[12]*((Vpk[0][17][2]*Vpk[12][17][2])+((Vpk[0][16][0]*
          Vpk[12][17][0])+(Vpk[0][17][1]*Vpk[12][17][1]))))+((mk[11]*((
          Vpk[0][16][2]*Vpk[12][16][2])+((Vpk[0][14][1]*Vpk[12][16][1])+(
          Vpk[0][16][0]*Vpk[12][16][0]))))+temp[0]));
        temp[0] = ((mk[11]*((Vpk[0][16][2]*Vpk[13][16][2])+((Vpk[0][14][1]*
          Vpk[13][16][1])+(Vpk[0][16][0]*Vpk[13][16][0]))))+((mk[10]*((
          Vpk[0][15][2]*Vpk[13][15][2])+((Vpk[0][14][1]*Vpk[13][15][1])+(
          Vpk[0][15][0]*Vpk[13][15][0]))))+((mk[8]*((rk[8][0]*Vpk[0][13][2])-(
          rk[8][2]*Vpk[0][13][0])))+(mk[9]*((Vpk[0][14][2]*Vpk[13][14][2])+((
          Vpk[0][13][0]*Vpk[13][14][0])+(Vpk[0][14][1]*Vpk[13][14][1])))))));
        mm[0][13] = ((mk[12]*((Vpk[0][17][2]*Vpk[13][17][2])+((Vpk[0][16][0]*
          Vpk[13][17][0])+(Vpk[0][17][1]*Vpk[13][17][1]))))+temp[0]);
        mm[0][14] = ((mk[12]*((Vpk[0][17][2]*Vpk[14][17][2])+((Vpk[0][16][0]*
          Vpk[14][17][0])+(Vpk[0][17][1]*Vpk[14][17][1]))))+((mk[11]*((
          Vpk[0][16][2]*Vpk[14][16][2])+((Vpk[0][14][1]*Vpk[14][16][1])+(
          Vpk[0][16][0]*Vpk[14][16][0]))))+((mk[9]*((rk[9][2]*Vpk[0][14][1])-(
          rk[9][1]*Vpk[0][14][2])))+(mk[10]*((Vpk[0][15][2]*Vpk[14][15][2])+((
          Vpk[0][14][1]*Vpk[14][15][1])+(Vpk[0][15][0]*Vpk[14][15][0])))))));
        mm[0][15] = ((mk[12]*((Vpk[0][17][2]*Vpk[15][17][2])+((Vpk[0][16][0]*
          Vpk[15][17][0])+(Vpk[0][17][1]*Vpk[15][17][1]))))+((mk[10]*((rk[10][0]
          *Vpk[0][15][2])-(rk[10][2]*Vpk[0][15][0])))+(mk[11]*((Vpk[0][16][0]*
          Vpk[15][16][0])+(Vpk[0][16][2]*Vpk[15][16][2])))));
        mm[0][16] = ((mk[11]*((rk[11][0]*Vpk[0][16][2])-(rk[11][2]*Vpk[0][16][0]
          )))+(mk[12]*((Vpk[0][17][2]*Vpk[16][17][2])+((Vpk[0][16][0]*
          Vpk[16][17][0])+(Vpk[0][17][1]*Vpk[16][17][1])))));
        mm[0][17] = (mk[12]*((rk[12][2]*Vpk[0][17][1])-(rk[12][1]*Vpk[0][17][2])
          ));
        mm[0][18] = ((mk[16]*((Vpk[0][20][2]*Vpk[18][21][2])+((Vpk[0][21][0]*
          Vpk[18][21][0])+(Vpk[0][21][1]*Vpk[18][21][1]))))+((mk[15]*((
          Vpk[0][20][2]*Vpk[18][20][2])+((Vpk[0][19][1]*Vpk[18][20][1])+(
          Vpk[0][20][0]*Vpk[18][20][0]))))+((mk[13]*((rk[13][0]*Vpk[0][18][2])-(
          rk[13][2]*Vpk[0][18][0])))+(mk[14]*((Vpk[0][19][2]*Vpk[18][19][2])+((
          Vpk[0][18][0]*Vpk[18][19][0])+(Vpk[0][19][1]*Vpk[18][19][1])))))));
        mm[0][19] = ((mk[16]*((Vpk[0][20][2]*Vpk[19][21][2])+((Vpk[0][21][0]*
          Vpk[19][21][0])+(Vpk[0][21][1]*Vpk[19][21][1]))))+((mk[14]*((rk[14][2]
          *Vpk[0][19][1])-(rk[14][1]*Vpk[0][19][2])))+(mk[15]*((Vpk[0][20][2]*
          Vpk[19][20][2])+((Vpk[0][19][1]*Vpk[19][20][1])+(Vpk[0][20][0]*
          Vpk[19][20][0]))))));
        mm[0][20] = ((mk[15]*((rk[15][0]*Vpk[0][20][2])-(rk[15][2]*Vpk[0][20][0]
          )))+(mk[16]*((Vpk[0][20][2]*Vpk[20][21][2])+((Vpk[0][21][0]*
          Vpk[20][21][0])+(Vpk[0][21][1]*Vpk[20][21][1])))));
        mm[0][21] = (mk[16]*((rk[16][1]*Vpk[0][21][0])-(rk[16][0]*Vpk[0][21][1])
          ));
        mm[0][22] = ((mk[20]*((Vpk[0][24][2]*Vpk[22][25][2])+((Vpk[0][25][0]*
          Vpk[22][25][0])+(Vpk[0][25][1]*Vpk[22][25][1]))))+((mk[19]*((
          Vpk[0][24][2]*Vpk[22][24][2])+((Vpk[0][23][1]*Vpk[22][24][1])+(
          Vpk[0][24][0]*Vpk[22][24][0]))))+((mk[17]*((rk[17][0]*Vpk[0][22][2])-(
          rk[17][2]*Vpk[0][22][0])))+(mk[18]*((Vpk[0][23][2]*Vpk[22][23][2])+((
          Vpk[0][22][0]*Vpk[22][23][0])+(Vpk[0][23][1]*Vpk[22][23][1])))))));
        mm[0][23] = ((mk[20]*((Vpk[0][24][2]*Vpk[23][25][2])+((Vpk[0][25][0]*
          Vpk[23][25][0])+(Vpk[0][25][1]*Vpk[23][25][1]))))+((mk[18]*((rk[18][2]
          *Vpk[0][23][1])-(rk[18][1]*Vpk[0][23][2])))+(mk[19]*((Vpk[0][24][2]*
          Vpk[23][24][2])+((Vpk[0][23][1]*Vpk[23][24][1])+(Vpk[0][24][0]*
          Vpk[23][24][0]))))));
        mm[0][24] = ((mk[19]*((rk[19][0]*Vpk[0][24][2])-(rk[19][2]*Vpk[0][24][0]
          )))+(mk[20]*((Vpk[0][24][2]*Vpk[24][25][2])+((Vpk[0][25][0]*
          Vpk[24][25][0])+(Vpk[0][25][1]*Vpk[24][25][1])))));
        mm[0][25] = (mk[20]*((rk[20][1]*Vpk[0][25][0])-(rk[20][0]*Vpk[0][25][1])
          ));
        temp[0] = ((mk[2]*((Vpk[1][7][2]*Vpk[1][7][2])+((Vpk[1][6][1]*
          Vpk[1][6][1])+(Vpk[1][7][0]*Vpk[1][7][0]))))+((mk[0]*((Cik[3][1][2]*
          Cik[3][1][2])+((Cik[3][1][0]*Cik[3][1][0])+(Cik[3][1][1]*Cik[3][1][1])
          )))+(mk[1]*((Cik[3][1][2]*Cik[3][1][2])+((Vpk[1][6][0]*Vpk[1][6][0])+(
          Vpk[1][6][1]*Vpk[1][6][1]))))));
        temp[1] = ((mk[5]*((Vpk[1][10][2]*Vpk[1][10][2])+((Vpk[1][8][1]*
          Vpk[1][8][1])+(Vpk[1][10][0]*Vpk[1][10][0]))))+((mk[4]*((Vpk[1][9][2]*
          Vpk[1][9][2])+((Vpk[1][8][1]*Vpk[1][8][1])+(Vpk[1][9][0]*Vpk[1][9][0])
          )))+((mk[3]*((Vpk[1][8][2]*Vpk[1][8][2])+((Vpk[1][7][0]*Vpk[1][7][0])+
          (Vpk[1][8][1]*Vpk[1][8][1]))))+temp[0])));
        temp[2] = ((mk[8]*((Vpk[1][13][2]*Vpk[1][13][2])+((Vpk[1][12][1]*
          Vpk[1][12][1])+(Vpk[1][13][0]*Vpk[1][13][0]))))+((mk[7]*((Cik[3][1][2]
          *Cik[3][1][2])+((Vpk[1][12][0]*Vpk[1][12][0])+(Vpk[1][12][1]*
          Vpk[1][12][1]))))+((mk[6]*((Vpk[1][11][2]*Vpk[1][11][2])+((
          Vpk[1][10][0]*Vpk[1][10][0])+(Vpk[1][11][1]*Vpk[1][11][1]))))+temp[1])
          ));
        temp[3] = ((mk[11]*((Vpk[1][16][2]*Vpk[1][16][2])+((Vpk[1][14][1]*
          Vpk[1][14][1])+(Vpk[1][16][0]*Vpk[1][16][0]))))+((mk[10]*((
          Vpk[1][15][2]*Vpk[1][15][2])+((Vpk[1][14][1]*Vpk[1][14][1])+(
          Vpk[1][15][0]*Vpk[1][15][0]))))+((mk[9]*((Vpk[1][14][2]*Vpk[1][14][2])
          +((Vpk[1][13][0]*Vpk[1][13][0])+(Vpk[1][14][1]*Vpk[1][14][1]))))+
          temp[2])));
        temp[4] = ((mk[14]*((Vpk[1][19][2]*Vpk[1][19][2])+((Vpk[1][18][0]*
          Vpk[1][18][0])+(Vpk[1][19][1]*Vpk[1][19][1]))))+((mk[13]*((
          Vpk[1][18][2]*Vpk[1][18][2])+((Cik[3][1][1]*Cik[3][1][1])+(
          Vpk[1][18][0]*Vpk[1][18][0]))))+((mk[12]*((Vpk[1][17][2]*Vpk[1][17][2]
          )+((Vpk[1][16][0]*Vpk[1][16][0])+(Vpk[1][17][1]*Vpk[1][17][1]))))+
          temp[3])));
        temp[5] = ((mk[17]*((Vpk[1][22][2]*Vpk[1][22][2])+((Cik[3][1][1]*
          Cik[3][1][1])+(Vpk[1][22][0]*Vpk[1][22][0]))))+((mk[16]*((
          Vpk[1][20][2]*Vpk[1][20][2])+((Vpk[1][21][0]*Vpk[1][21][0])+(
          Vpk[1][21][1]*Vpk[1][21][1]))))+((mk[15]*((Vpk[1][20][2]*Vpk[1][20][2]
          )+((Vpk[1][19][1]*Vpk[1][19][1])+(Vpk[1][20][0]*Vpk[1][20][0]))))+
          temp[4])));
        mm[1][1] = ((mk[20]*((Vpk[1][24][2]*Vpk[1][24][2])+((Vpk[1][25][0]*
          Vpk[1][25][0])+(Vpk[1][25][1]*Vpk[1][25][1]))))+((mk[19]*((
          Vpk[1][24][2]*Vpk[1][24][2])+((Vpk[1][23][1]*Vpk[1][23][1])+(
          Vpk[1][24][0]*Vpk[1][24][0]))))+((mk[18]*((Vpk[1][23][2]*Vpk[1][23][2]
          )+((Vpk[1][22][0]*Vpk[1][22][0])+(Vpk[1][23][1]*Vpk[1][23][1]))))+
          temp[5])));
        temp[0] = ((mk[2]*((Vpk[1][7][2]*Vpk[2][7][2])+((Vpk[1][6][1]*
          Vpk[2][6][1])+(Vpk[1][7][0]*Vpk[2][7][0]))))+((mk[0]*((Cik[3][1][2]*
          Cik[3][2][2])+((Cik[3][1][0]*Cik[3][2][0])+(Cik[3][1][1]*Cik[3][2][1])
          )))+(mk[1]*((Cik[3][1][2]*Cik[3][2][2])+((Vpk[1][6][0]*Vpk[2][6][0])+(
          Vpk[1][6][1]*Vpk[2][6][1]))))));
        temp[1] = ((mk[5]*((Vpk[1][10][2]*Vpk[2][10][2])+((Vpk[1][8][1]*
          Vpk[2][8][1])+(Vpk[1][10][0]*Vpk[2][10][0]))))+((mk[4]*((Vpk[1][9][2]*
          Vpk[2][9][2])+((Vpk[1][8][1]*Vpk[2][8][1])+(Vpk[1][9][0]*Vpk[2][9][0])
          )))+((mk[3]*((Vpk[1][8][2]*Vpk[2][8][2])+((Vpk[1][7][0]*Vpk[2][7][0])+
          (Vpk[1][8][1]*Vpk[2][8][1]))))+temp[0])));
        temp[2] = ((mk[8]*((Vpk[1][13][2]*Vpk[2][13][2])+((Vpk[1][12][1]*
          Vpk[2][12][1])+(Vpk[1][13][0]*Vpk[2][13][0]))))+((mk[7]*((Cik[3][1][2]
          *Cik[3][2][2])+((Vpk[1][12][0]*Vpk[2][12][0])+(Vpk[1][12][1]*
          Vpk[2][12][1]))))+((mk[6]*((Vpk[1][11][2]*Vpk[2][11][2])+((
          Vpk[1][10][0]*Vpk[2][10][0])+(Vpk[1][11][1]*Vpk[2][11][1]))))+temp[1])
          ));
        temp[3] = ((mk[11]*((Vpk[1][16][2]*Vpk[2][16][2])+((Vpk[1][14][1]*
          Vpk[2][14][1])+(Vpk[1][16][0]*Vpk[2][16][0]))))+((mk[10]*((
          Vpk[1][15][2]*Vpk[2][15][2])+((Vpk[1][14][1]*Vpk[2][14][1])+(
          Vpk[1][15][0]*Vpk[2][15][0]))))+((mk[9]*((Vpk[1][14][2]*Vpk[2][14][2])
          +((Vpk[1][13][0]*Vpk[2][13][0])+(Vpk[1][14][1]*Vpk[2][14][1]))))+
          temp[2])));
        temp[4] = ((mk[14]*((Vpk[1][19][2]*Vpk[2][19][2])+((Vpk[1][18][0]*
          Vpk[2][18][0])+(Vpk[1][19][1]*Vpk[2][19][1]))))+((mk[13]*((
          Vpk[1][18][2]*Vpk[2][18][2])+((Cik[3][1][1]*Cik[3][2][1])+(
          Vpk[1][18][0]*Vpk[2][18][0]))))+((mk[12]*((Vpk[1][17][2]*Vpk[2][17][2]
          )+((Vpk[1][16][0]*Vpk[2][16][0])+(Vpk[1][17][1]*Vpk[2][17][1]))))+
          temp[3])));
        temp[5] = ((mk[17]*((Vpk[1][22][2]*Vpk[2][22][2])+((Cik[3][1][1]*
          Cik[3][2][1])+(Vpk[1][22][0]*Vpk[2][22][0]))))+((mk[16]*((
          Vpk[1][20][2]*Vpk[2][20][2])+((Vpk[1][21][0]*Vpk[2][21][0])+(
          Vpk[1][21][1]*Vpk[2][21][1]))))+((mk[15]*((Vpk[1][20][2]*Vpk[2][20][2]
          )+((Vpk[1][19][1]*Vpk[2][19][1])+(Vpk[1][20][0]*Vpk[2][20][0]))))+
          temp[4])));
        mm[1][2] = ((mk[20]*((Vpk[1][24][2]*Vpk[2][24][2])+((Vpk[1][25][0]*
          Vpk[2][25][0])+(Vpk[1][25][1]*Vpk[2][25][1]))))+((mk[19]*((
          Vpk[1][24][2]*Vpk[2][24][2])+((Vpk[1][23][1]*Vpk[2][23][1])+(
          Vpk[1][24][0]*Vpk[2][24][0]))))+((mk[18]*((Vpk[1][23][2]*Vpk[2][23][2]
          )+((Vpk[1][22][0]*Vpk[2][22][0])+(Vpk[1][23][1]*Vpk[2][23][1]))))+
          temp[5])));
        temp[0] = ((mk[3]*((Vpk[1][8][2]*Vpk[3][8][2])+((Vpk[1][7][0]*
          Vpk[3][8][0])+(Vpk[1][8][1]*Vpk[3][8][1]))))+((mk[2]*((Vpk[1][7][2]*
          Vpk[3][7][2])+((Vpk[1][6][1]*Vpk[3][7][1])+(Vpk[1][7][0]*Vpk[3][7][0])
          )))+((mk[0]*((Cik[3][1][1]*rk[0][2])-(Cik[3][1][2]*rk[0][1])))+(mk[1]*
          ((Cik[3][1][2]*Vpk[3][6][2])+((Vpk[1][6][0]*Vpk[3][6][0])+(
          Vpk[1][6][1]*Vpk[3][6][1])))))));
        temp[1] = ((mk[6]*((Vpk[1][11][2]*Vpk[3][11][2])+((Vpk[1][10][0]*
          Vpk[3][11][0])+(Vpk[1][11][1]*Vpk[3][11][1]))))+((mk[5]*((
          Vpk[1][10][2]*Vpk[3][10][2])+((Vpk[1][8][1]*Vpk[3][10][1])+(
          Vpk[1][10][0]*Vpk[3][10][0]))))+((mk[4]*((Vpk[1][9][2]*Vpk[3][9][2])+(
          (Vpk[1][8][1]*Vpk[3][9][1])+(Vpk[1][9][0]*Vpk[3][9][0]))))+temp[0])));
        temp[2] = ((mk[9]*((Vpk[1][14][2]*Vpk[3][14][2])+((Vpk[1][13][0]*
          Vpk[3][14][0])+(Vpk[1][14][1]*Vpk[3][14][1]))))+((mk[8]*((
          Vpk[1][13][2]*Vpk[3][13][2])+((Vpk[1][12][1]*Vpk[3][13][1])+(
          Vpk[1][13][0]*Vpk[3][13][0]))))+((mk[7]*((Cik[3][1][2]*Vpk[3][12][2])+
          ((Vpk[1][12][0]*Vpk[3][12][0])+(Vpk[1][12][1]*Vpk[3][12][1]))))+
          temp[1])));
        temp[3] = ((mk[12]*((Vpk[1][17][2]*Vpk[3][17][2])+((Vpk[1][16][0]*
          Vpk[3][17][0])+(Vpk[1][17][1]*Vpk[3][17][1]))))+((mk[11]*((
          Vpk[1][16][2]*Vpk[3][16][2])+((Vpk[1][14][1]*Vpk[3][16][1])+(
          Vpk[1][16][0]*Vpk[3][16][0]))))+((mk[10]*((Vpk[1][15][2]*Vpk[3][15][2]
          )+((Vpk[1][14][1]*Vpk[3][15][1])+(Vpk[1][15][0]*Vpk[3][15][0]))))+
          temp[2])));
        temp[4] = ((mk[15]*((Vpk[1][20][2]*Vpk[3][20][2])+((Vpk[1][19][1]*
          Vpk[3][20][1])+(Vpk[1][20][0]*Vpk[3][20][0]))))+((mk[14]*((
          Vpk[1][19][2]*Vpk[3][19][2])+((Vpk[1][18][0]*Vpk[3][19][0])+(
          Vpk[1][19][1]*Vpk[3][19][1]))))+((mk[13]*((Vpk[1][18][2]*Vpk[3][18][2]
          )+((Cik[3][1][1]*Vpk[3][18][1])+(Vpk[1][18][0]*Vpk[3][18][0]))))+
          temp[3])));
        temp[5] = ((mk[18]*((Vpk[1][23][2]*Vpk[3][23][2])+((Vpk[1][22][0]*
          Vpk[3][23][0])+(Vpk[1][23][1]*Vpk[3][23][1]))))+((mk[17]*((
          Vpk[1][22][2]*Vpk[3][22][2])+((Cik[3][1][1]*Vpk[3][22][1])+(
          Vpk[1][22][0]*Vpk[3][22][0]))))+((mk[16]*((Vpk[1][20][2]*Vpk[3][21][2]
          )+((Vpk[1][21][0]*Vpk[3][21][0])+(Vpk[1][21][1]*Vpk[3][21][1]))))+
          temp[4])));
        mm[1][3] = ((mk[20]*((Vpk[1][24][2]*Vpk[3][25][2])+((Vpk[1][25][0]*
          Vpk[3][25][0])+(Vpk[1][25][1]*Vpk[3][25][1]))))+((mk[19]*((
          Vpk[1][24][2]*Vpk[3][24][2])+((Vpk[1][23][1]*Vpk[3][24][1])+(
          Vpk[1][24][0]*Vpk[3][24][0]))))+temp[5]));
        temp[0] = ((mk[3]*((Vpk[1][8][2]*Vpk[4][8][2])+((Vpk[1][7][0]*
          Vpk[4][8][0])+(Vpk[1][8][1]*Vpk[4][8][1]))))+((mk[2]*((Vpk[1][7][2]*
          Vpk[4][7][2])+((Vpk[1][6][1]*Vpk[4][7][1])+(Vpk[1][7][0]*Vpk[4][7][0])
          )))+((mk[0]*((Cik[3][1][2]*rk[0][0])-(Cik[3][1][0]*rk[0][2])))+(mk[1]*
          ((Cik[3][1][2]*Vpk[4][6][2])+((Vpk[1][6][0]*Vpk[4][6][0])+(
          Vpk[1][6][1]*Vpk[4][6][1])))))));
        temp[1] = ((mk[6]*((Vpk[1][11][2]*Vpk[4][11][2])+((Vpk[1][10][0]*
          Vpk[4][11][0])+(Vpk[1][11][1]*Vpk[4][11][1]))))+((mk[5]*((
          Vpk[1][10][2]*Vpk[4][10][2])+((Vpk[1][8][1]*Vpk[4][10][1])+(
          Vpk[1][10][0]*Vpk[4][10][0]))))+((mk[4]*((Vpk[1][9][2]*Vpk[4][9][2])+(
          (Vpk[1][8][1]*Vpk[4][9][1])+(Vpk[1][9][0]*Vpk[4][9][0]))))+temp[0])));
        temp[2] = ((mk[9]*((Vpk[1][14][2]*Vpk[4][14][2])+((Vpk[1][13][0]*
          Vpk[4][14][0])+(Vpk[1][14][1]*Vpk[4][14][1]))))+((mk[8]*((
          Vpk[1][13][2]*Vpk[4][13][2])+((Vpk[1][12][1]*Vpk[4][13][1])+(
          Vpk[1][13][0]*Vpk[4][13][0]))))+((mk[7]*((Cik[3][1][2]*Vpk[4][12][2])+
          ((Vpk[1][12][0]*Vpk[4][12][0])+(Vpk[1][12][1]*Vpk[4][12][1]))))+
          temp[1])));
        temp[3] = ((mk[13]*((Vpk[1][18][0]*Vpk[4][18][0])+(Vpk[1][18][2]*
          Vpk[4][18][2])))+((mk[12]*((Vpk[1][17][2]*Vpk[4][17][2])+((
          Vpk[1][16][0]*Vpk[4][17][0])+(Vpk[1][17][1]*Vpk[4][17][1]))))+((mk[11]
          *((Vpk[1][16][2]*Vpk[4][16][2])+((Vpk[1][14][1]*Vpk[4][16][1])+(
          Vpk[1][16][0]*Vpk[4][16][0]))))+((mk[10]*((Vpk[1][15][2]*Vpk[4][15][2]
          )+((Vpk[1][14][1]*Vpk[4][15][1])+(Vpk[1][15][0]*Vpk[4][15][0]))))+
          temp[2]))));
        temp[4] = ((mk[17]*((Vpk[1][22][0]*Vpk[4][22][0])+(Vpk[1][22][2]*
          Vpk[4][22][2])))+((mk[16]*((Vpk[1][20][2]*Vpk[4][21][2])+((
          Vpk[1][21][0]*Vpk[4][21][0])+(Vpk[1][21][1]*Vpk[4][21][1]))))+((mk[15]
          *((Vpk[1][20][2]*Vpk[4][20][2])+((Vpk[1][19][1]*Vpk[4][20][1])+(
          Vpk[1][20][0]*Vpk[4][20][0]))))+((mk[14]*((Vpk[1][19][2]*Vpk[4][19][2]
          )+((Vpk[1][18][0]*Vpk[4][19][0])+(Vpk[1][19][1]*Vpk[4][19][1]))))+
          temp[3]))));
        mm[1][4] = ((mk[20]*((Vpk[1][24][2]*Vpk[4][25][2])+((Vpk[1][25][0]*
          Vpk[4][25][0])+(Vpk[1][25][1]*Vpk[4][25][1]))))+((mk[19]*((
          Vpk[1][24][2]*Vpk[4][24][2])+((Vpk[1][23][1]*Vpk[4][24][1])+(
          Vpk[1][24][0]*Vpk[4][24][0]))))+((mk[18]*((Vpk[1][23][2]*Vpk[4][23][2]
          )+((Vpk[1][22][0]*Vpk[4][23][0])+(Vpk[1][23][1]*Vpk[4][23][1]))))+
          temp[4])));
        temp[0] = ((mk[3]*((Vpk[1][8][2]*Vpk[5][8][2])+((Vpk[1][7][0]*
          Vpk[5][8][0])+(Vpk[1][8][1]*Vpk[5][8][1]))))+((mk[2]*((Vpk[1][7][2]*
          Vpk[5][7][2])+((Vpk[1][6][1]*Vpk[5][7][1])+(Vpk[1][7][0]*Vpk[5][7][0])
          )))+((mk[0]*((Cik[3][1][0]*rk[0][1])-(Cik[3][1][1]*rk[0][0])))+(mk[1]*
          ((Vpk[1][6][0]*Vpk[5][6][0])+(Vpk[1][6][1]*Vpk[5][6][1]))))));
        temp[1] = ((mk[7]*((Vpk[1][12][0]*Vpk[5][12][0])+(Vpk[1][12][1]*
          Vpk[5][12][1])))+((mk[6]*((Vpk[1][11][2]*Vpk[5][11][2])+((
          Vpk[1][10][0]*Vpk[5][11][0])+(Vpk[1][11][1]*Vpk[5][11][1]))))+((mk[5]*
          ((Vpk[1][10][2]*Vpk[5][10][2])+((Vpk[1][8][1]*Vpk[5][10][1])+(
          Vpk[1][10][0]*Vpk[5][10][0]))))+((mk[4]*((Vpk[1][9][2]*Vpk[5][9][2])+(
          (Vpk[1][8][1]*Vpk[5][9][1])+(Vpk[1][9][0]*Vpk[5][9][0]))))+temp[0]))))
          ;
        temp[2] = ((mk[10]*((Vpk[1][15][2]*Vpk[5][15][2])+((Vpk[1][14][1]*
          Vpk[5][15][1])+(Vpk[1][15][0]*Vpk[5][15][0]))))+((mk[9]*((
          Vpk[1][14][2]*Vpk[5][14][2])+((Vpk[1][13][0]*Vpk[5][14][0])+(
          Vpk[1][14][1]*Vpk[5][14][1]))))+((mk[8]*((Vpk[1][13][2]*Vpk[5][13][2])
          +((Vpk[1][12][1]*Vpk[5][13][1])+(Vpk[1][13][0]*Vpk[5][13][0]))))+
          temp[1])));
        temp[3] = ((mk[13]*((Vpk[1][18][2]*Vpk[5][18][2])+((Cik[3][1][1]*
          Vpk[5][18][1])+(Vpk[1][18][0]*Vpk[5][18][0]))))+((mk[12]*((
          Vpk[1][17][2]*Vpk[5][17][2])+((Vpk[1][16][0]*Vpk[5][17][0])+(
          Vpk[1][17][1]*Vpk[5][17][1]))))+((mk[11]*((Vpk[1][16][2]*Vpk[5][16][2]
          )+((Vpk[1][14][1]*Vpk[5][16][1])+(Vpk[1][16][0]*Vpk[5][16][0]))))+
          temp[2])));
        temp[4] = ((mk[16]*((Vpk[1][20][2]*Vpk[5][21][2])+((Vpk[1][21][0]*
          Vpk[5][21][0])+(Vpk[1][21][1]*Vpk[5][21][1]))))+((mk[15]*((
          Vpk[1][20][2]*Vpk[5][20][2])+((Vpk[1][19][1]*Vpk[5][20][1])+(
          Vpk[1][20][0]*Vpk[5][20][0]))))+((mk[14]*((Vpk[1][19][2]*Vpk[5][19][2]
          )+((Vpk[1][18][0]*Vpk[5][19][0])+(Vpk[1][19][1]*Vpk[5][19][1]))))+
          temp[3])));
        temp[5] = ((mk[19]*((Vpk[1][24][2]*Vpk[5][24][2])+((Vpk[1][23][1]*
          Vpk[5][24][1])+(Vpk[1][24][0]*Vpk[5][24][0]))))+((mk[18]*((
          Vpk[1][23][2]*Vpk[5][23][2])+((Vpk[1][22][0]*Vpk[5][23][0])+(
          Vpk[1][23][1]*Vpk[5][23][1]))))+((mk[17]*((Vpk[1][22][2]*Vpk[5][22][2]
          )+((Cik[3][1][1]*Vpk[5][22][1])+(Vpk[1][22][0]*Vpk[5][22][0]))))+
          temp[4])));
        mm[1][5] = ((mk[20]*((Vpk[1][24][2]*Vpk[5][25][2])+((Vpk[1][25][0]*
          Vpk[5][25][0])+(Vpk[1][25][1]*Vpk[5][25][1]))))+temp[5]);
        temp[0] = ((mk[4]*((Vpk[1][9][2]*Vpk[6][9][2])+((Vpk[1][8][1]*
          Vpk[6][9][1])+(Vpk[1][9][0]*Vpk[6][9][0]))))+((mk[3]*((Vpk[1][8][2]*
          Vpk[6][8][2])+((Vpk[1][7][0]*Vpk[6][8][0])+(Vpk[1][8][1]*Vpk[6][8][1])
          )))+((mk[1]*((rk[1][1]*Vpk[1][6][0])-(rk[1][0]*Vpk[1][6][1])))+(mk[2]*
          ((Vpk[1][7][2]*Vpk[6][7][2])+((Vpk[1][6][1]*Vpk[6][7][1])+(
          Vpk[1][7][0]*Vpk[6][7][0])))))));
        mm[1][6] = ((mk[6]*((Vpk[1][11][2]*Vpk[6][11][2])+((Vpk[1][10][0]*
          Vpk[6][11][0])+(Vpk[1][11][1]*Vpk[6][11][1]))))+((mk[5]*((
          Vpk[1][10][2]*Vpk[6][10][2])+((Vpk[1][8][1]*Vpk[6][10][1])+(
          Vpk[1][10][0]*Vpk[6][10][0]))))+temp[0]));
        temp[0] = ((mk[5]*((Vpk[1][10][2]*Vpk[7][10][2])+((Vpk[1][8][1]*
          Vpk[7][10][1])+(Vpk[1][10][0]*Vpk[7][10][0]))))+((mk[4]*((Vpk[1][9][2]
          *Vpk[7][9][2])+((Vpk[1][8][1]*Vpk[7][9][1])+(Vpk[1][9][0]*Vpk[7][9][0]
          ))))+((mk[2]*((rk[2][0]*Vpk[1][7][2])-(rk[2][2]*Vpk[1][7][0])))+(mk[3]
          *((Vpk[1][8][2]*Vpk[7][8][2])+((Vpk[1][7][0]*Vpk[7][8][0])+(
          Vpk[1][8][1]*Vpk[7][8][1])))))));
        mm[1][7] = ((mk[6]*((Vpk[1][11][2]*Vpk[7][11][2])+((Vpk[1][10][0]*
          Vpk[7][11][0])+(Vpk[1][11][1]*Vpk[7][11][1]))))+temp[0]);
        mm[1][8] = ((mk[6]*((Vpk[1][11][2]*Vpk[8][11][2])+((Vpk[1][10][0]*
          Vpk[8][11][0])+(Vpk[1][11][1]*Vpk[8][11][1]))))+((mk[5]*((
          Vpk[1][10][2]*Vpk[8][10][2])+((Vpk[1][8][1]*Vpk[8][10][1])+(
          Vpk[1][10][0]*Vpk[8][10][0]))))+((mk[3]*((rk[3][2]*Vpk[1][8][1])-(
          rk[3][1]*Vpk[1][8][2])))+(mk[4]*((Vpk[1][9][2]*Vpk[8][9][2])+((
          Vpk[1][8][1]*Vpk[8][9][1])+(Vpk[1][9][0]*Vpk[8][9][0])))))));
        mm[1][9] = ((mk[6]*((Vpk[1][11][2]*Vpk[9][11][2])+((Vpk[1][10][0]*
          Vpk[9][11][0])+(Vpk[1][11][1]*Vpk[9][11][1]))))+((mk[4]*((rk[4][0]*
          Vpk[1][9][2])-(rk[4][2]*Vpk[1][9][0])))+(mk[5]*((Vpk[1][10][0]*
          Vpk[9][10][0])+(Vpk[1][10][2]*Vpk[9][10][2])))));
        mm[1][10] = ((mk[5]*((rk[5][0]*Vpk[1][10][2])-(rk[5][2]*Vpk[1][10][0])))
          +(mk[6]*((Vpk[1][11][2]*Vpk[10][11][2])+((Vpk[1][10][0]*Vpk[10][11][0]
          )+(Vpk[1][11][1]*Vpk[10][11][1])))));
        mm[1][11] = (mk[6]*((rk[6][2]*Vpk[1][11][1])-(rk[6][1]*Vpk[1][11][2])));
        temp[0] = ((mk[10]*((Vpk[1][15][2]*Vpk[12][15][2])+((Vpk[1][14][1]*
          Vpk[12][15][1])+(Vpk[1][15][0]*Vpk[12][15][0]))))+((mk[9]*((
          Vpk[1][14][2]*Vpk[12][14][2])+((Vpk[1][13][0]*Vpk[12][14][0])+(
          Vpk[1][14][1]*Vpk[12][14][1]))))+((mk[7]*((rk[7][1]*Vpk[1][12][0])-(
          rk[7][0]*Vpk[1][12][1])))+(mk[8]*((Vpk[1][13][2]*Vpk[12][13][2])+((
          Vpk[1][12][1]*Vpk[12][13][1])+(Vpk[1][13][0]*Vpk[12][13][0])))))));
        mm[1][12] = ((mk[12]*((Vpk[1][17][2]*Vpk[12][17][2])+((Vpk[1][16][0]*
          Vpk[12][17][0])+(Vpk[1][17][1]*Vpk[12][17][1]))))+((mk[11]*((
          Vpk[1][16][2]*Vpk[12][16][2])+((Vpk[1][14][1]*Vpk[12][16][1])+(
          Vpk[1][16][0]*Vpk[12][16][0]))))+temp[0]));
        temp[0] = ((mk[11]*((Vpk[1][16][2]*Vpk[13][16][2])+((Vpk[1][14][1]*
          Vpk[13][16][1])+(Vpk[1][16][0]*Vpk[13][16][0]))))+((mk[10]*((
          Vpk[1][15][2]*Vpk[13][15][2])+((Vpk[1][14][1]*Vpk[13][15][1])+(
          Vpk[1][15][0]*Vpk[13][15][0]))))+((mk[8]*((rk[8][0]*Vpk[1][13][2])-(
          rk[8][2]*Vpk[1][13][0])))+(mk[9]*((Vpk[1][14][2]*Vpk[13][14][2])+((
          Vpk[1][13][0]*Vpk[13][14][0])+(Vpk[1][14][1]*Vpk[13][14][1])))))));
        mm[1][13] = ((mk[12]*((Vpk[1][17][2]*Vpk[13][17][2])+((Vpk[1][16][0]*
          Vpk[13][17][0])+(Vpk[1][17][1]*Vpk[13][17][1]))))+temp[0]);
        mm[1][14] = ((mk[12]*((Vpk[1][17][2]*Vpk[14][17][2])+((Vpk[1][16][0]*
          Vpk[14][17][0])+(Vpk[1][17][1]*Vpk[14][17][1]))))+((mk[11]*((
          Vpk[1][16][2]*Vpk[14][16][2])+((Vpk[1][14][1]*Vpk[14][16][1])+(
          Vpk[1][16][0]*Vpk[14][16][0]))))+((mk[9]*((rk[9][2]*Vpk[1][14][1])-(
          rk[9][1]*Vpk[1][14][2])))+(mk[10]*((Vpk[1][15][2]*Vpk[14][15][2])+((
          Vpk[1][14][1]*Vpk[14][15][1])+(Vpk[1][15][0]*Vpk[14][15][0])))))));
        mm[1][15] = ((mk[12]*((Vpk[1][17][2]*Vpk[15][17][2])+((Vpk[1][16][0]*
          Vpk[15][17][0])+(Vpk[1][17][1]*Vpk[15][17][1]))))+((mk[10]*((rk[10][0]
          *Vpk[1][15][2])-(rk[10][2]*Vpk[1][15][0])))+(mk[11]*((Vpk[1][16][0]*
          Vpk[15][16][0])+(Vpk[1][16][2]*Vpk[15][16][2])))));
        mm[1][16] = ((mk[11]*((rk[11][0]*Vpk[1][16][2])-(rk[11][2]*Vpk[1][16][0]
          )))+(mk[12]*((Vpk[1][17][2]*Vpk[16][17][2])+((Vpk[1][16][0]*
          Vpk[16][17][0])+(Vpk[1][17][1]*Vpk[16][17][1])))));
        mm[1][17] = (mk[12]*((rk[12][2]*Vpk[1][17][1])-(rk[12][1]*Vpk[1][17][2])
          ));
        mm[1][18] = ((mk[16]*((Vpk[1][20][2]*Vpk[18][21][2])+((Vpk[1][21][0]*
          Vpk[18][21][0])+(Vpk[1][21][1]*Vpk[18][21][1]))))+((mk[15]*((
          Vpk[1][20][2]*Vpk[18][20][2])+((Vpk[1][19][1]*Vpk[18][20][1])+(
          Vpk[1][20][0]*Vpk[18][20][0]))))+((mk[13]*((rk[13][0]*Vpk[1][18][2])-(
          rk[13][2]*Vpk[1][18][0])))+(mk[14]*((Vpk[1][19][2]*Vpk[18][19][2])+((
          Vpk[1][18][0]*Vpk[18][19][0])+(Vpk[1][19][1]*Vpk[18][19][1])))))));
        mm[1][19] = ((mk[16]*((Vpk[1][20][2]*Vpk[19][21][2])+((Vpk[1][21][0]*
          Vpk[19][21][0])+(Vpk[1][21][1]*Vpk[19][21][1]))))+((mk[14]*((rk[14][2]
          *Vpk[1][19][1])-(rk[14][1]*Vpk[1][19][2])))+(mk[15]*((Vpk[1][20][2]*
          Vpk[19][20][2])+((Vpk[1][19][1]*Vpk[19][20][1])+(Vpk[1][20][0]*
          Vpk[19][20][0]))))));
        mm[1][20] = ((mk[15]*((rk[15][0]*Vpk[1][20][2])-(rk[15][2]*Vpk[1][20][0]
          )))+(mk[16]*((Vpk[1][20][2]*Vpk[20][21][2])+((Vpk[1][21][0]*
          Vpk[20][21][0])+(Vpk[1][21][1]*Vpk[20][21][1])))));
        mm[1][21] = (mk[16]*((rk[16][1]*Vpk[1][21][0])-(rk[16][0]*Vpk[1][21][1])
          ));
        mm[1][22] = ((mk[20]*((Vpk[1][24][2]*Vpk[22][25][2])+((Vpk[1][25][0]*
          Vpk[22][25][0])+(Vpk[1][25][1]*Vpk[22][25][1]))))+((mk[19]*((
          Vpk[1][24][2]*Vpk[22][24][2])+((Vpk[1][23][1]*Vpk[22][24][1])+(
          Vpk[1][24][0]*Vpk[22][24][0]))))+((mk[17]*((rk[17][0]*Vpk[1][22][2])-(
          rk[17][2]*Vpk[1][22][0])))+(mk[18]*((Vpk[1][23][2]*Vpk[22][23][2])+((
          Vpk[1][22][0]*Vpk[22][23][0])+(Vpk[1][23][1]*Vpk[22][23][1])))))));
        mm[1][23] = ((mk[20]*((Vpk[1][24][2]*Vpk[23][25][2])+((Vpk[1][25][0]*
          Vpk[23][25][0])+(Vpk[1][25][1]*Vpk[23][25][1]))))+((mk[18]*((rk[18][2]
          *Vpk[1][23][1])-(rk[18][1]*Vpk[1][23][2])))+(mk[19]*((Vpk[1][24][2]*
          Vpk[23][24][2])+((Vpk[1][23][1]*Vpk[23][24][1])+(Vpk[1][24][0]*
          Vpk[23][24][0]))))));
        mm[1][24] = ((mk[19]*((rk[19][0]*Vpk[1][24][2])-(rk[19][2]*Vpk[1][24][0]
          )))+(mk[20]*((Vpk[1][24][2]*Vpk[24][25][2])+((Vpk[1][25][0]*
          Vpk[24][25][0])+(Vpk[1][25][1]*Vpk[24][25][1])))));
        mm[1][25] = (mk[20]*((rk[20][1]*Vpk[1][25][0])-(rk[20][0]*Vpk[1][25][1])
          ));
        temp[0] = ((mk[2]*((Vpk[2][7][2]*Vpk[2][7][2])+((Vpk[2][6][1]*
          Vpk[2][6][1])+(Vpk[2][7][0]*Vpk[2][7][0]))))+((mk[0]*((Cik[3][2][2]*
          Cik[3][2][2])+((Cik[3][2][0]*Cik[3][2][0])+(Cik[3][2][1]*Cik[3][2][1])
          )))+(mk[1]*((Cik[3][2][2]*Cik[3][2][2])+((Vpk[2][6][0]*Vpk[2][6][0])+(
          Vpk[2][6][1]*Vpk[2][6][1]))))));
        temp[1] = ((mk[5]*((Vpk[2][10][2]*Vpk[2][10][2])+((Vpk[2][8][1]*
          Vpk[2][8][1])+(Vpk[2][10][0]*Vpk[2][10][0]))))+((mk[4]*((Vpk[2][9][2]*
          Vpk[2][9][2])+((Vpk[2][8][1]*Vpk[2][8][1])+(Vpk[2][9][0]*Vpk[2][9][0])
          )))+((mk[3]*((Vpk[2][8][2]*Vpk[2][8][2])+((Vpk[2][7][0]*Vpk[2][7][0])+
          (Vpk[2][8][1]*Vpk[2][8][1]))))+temp[0])));
        temp[2] = ((mk[8]*((Vpk[2][13][2]*Vpk[2][13][2])+((Vpk[2][12][1]*
          Vpk[2][12][1])+(Vpk[2][13][0]*Vpk[2][13][0]))))+((mk[7]*((Cik[3][2][2]
          *Cik[3][2][2])+((Vpk[2][12][0]*Vpk[2][12][0])+(Vpk[2][12][1]*
          Vpk[2][12][1]))))+((mk[6]*((Vpk[2][11][2]*Vpk[2][11][2])+((
          Vpk[2][10][0]*Vpk[2][10][0])+(Vpk[2][11][1]*Vpk[2][11][1]))))+temp[1])
          ));
        temp[3] = ((mk[11]*((Vpk[2][16][2]*Vpk[2][16][2])+((Vpk[2][14][1]*
          Vpk[2][14][1])+(Vpk[2][16][0]*Vpk[2][16][0]))))+((mk[10]*((
          Vpk[2][15][2]*Vpk[2][15][2])+((Vpk[2][14][1]*Vpk[2][14][1])+(
          Vpk[2][15][0]*Vpk[2][15][0]))))+((mk[9]*((Vpk[2][14][2]*Vpk[2][14][2])
          +((Vpk[2][13][0]*Vpk[2][13][0])+(Vpk[2][14][1]*Vpk[2][14][1]))))+
          temp[2])));
        temp[4] = ((mk[14]*((Vpk[2][19][2]*Vpk[2][19][2])+((Vpk[2][18][0]*
          Vpk[2][18][0])+(Vpk[2][19][1]*Vpk[2][19][1]))))+((mk[13]*((
          Vpk[2][18][2]*Vpk[2][18][2])+((Cik[3][2][1]*Cik[3][2][1])+(
          Vpk[2][18][0]*Vpk[2][18][0]))))+((mk[12]*((Vpk[2][17][2]*Vpk[2][17][2]
          )+((Vpk[2][16][0]*Vpk[2][16][0])+(Vpk[2][17][1]*Vpk[2][17][1]))))+
          temp[3])));
        temp[5] = ((mk[17]*((Vpk[2][22][2]*Vpk[2][22][2])+((Cik[3][2][1]*
          Cik[3][2][1])+(Vpk[2][22][0]*Vpk[2][22][0]))))+((mk[16]*((
          Vpk[2][20][2]*Vpk[2][20][2])+((Vpk[2][21][0]*Vpk[2][21][0])+(
          Vpk[2][21][1]*Vpk[2][21][1]))))+((mk[15]*((Vpk[2][20][2]*Vpk[2][20][2]
          )+((Vpk[2][19][1]*Vpk[2][19][1])+(Vpk[2][20][0]*Vpk[2][20][0]))))+
          temp[4])));
        mm[2][2] = ((mk[20]*((Vpk[2][24][2]*Vpk[2][24][2])+((Vpk[2][25][0]*
          Vpk[2][25][0])+(Vpk[2][25][1]*Vpk[2][25][1]))))+((mk[19]*((
          Vpk[2][24][2]*Vpk[2][24][2])+((Vpk[2][23][1]*Vpk[2][23][1])+(
          Vpk[2][24][0]*Vpk[2][24][0]))))+((mk[18]*((Vpk[2][23][2]*Vpk[2][23][2]
          )+((Vpk[2][22][0]*Vpk[2][22][0])+(Vpk[2][23][1]*Vpk[2][23][1]))))+
          temp[5])));
        temp[0] = ((mk[3]*((Vpk[2][8][2]*Vpk[3][8][2])+((Vpk[2][7][0]*
          Vpk[3][8][0])+(Vpk[2][8][1]*Vpk[3][8][1]))))+((mk[2]*((Vpk[2][7][2]*
          Vpk[3][7][2])+((Vpk[2][6][1]*Vpk[3][7][1])+(Vpk[2][7][0]*Vpk[3][7][0])
          )))+((mk[0]*((Cik[3][2][1]*rk[0][2])-(Cik[3][2][2]*rk[0][1])))+(mk[1]*
          ((Cik[3][2][2]*Vpk[3][6][2])+((Vpk[2][6][0]*Vpk[3][6][0])+(
          Vpk[2][6][1]*Vpk[3][6][1])))))));
        temp[1] = ((mk[6]*((Vpk[2][11][2]*Vpk[3][11][2])+((Vpk[2][10][0]*
          Vpk[3][11][0])+(Vpk[2][11][1]*Vpk[3][11][1]))))+((mk[5]*((
          Vpk[2][10][2]*Vpk[3][10][2])+((Vpk[2][8][1]*Vpk[3][10][1])+(
          Vpk[2][10][0]*Vpk[3][10][0]))))+((mk[4]*((Vpk[2][9][2]*Vpk[3][9][2])+(
          (Vpk[2][8][1]*Vpk[3][9][1])+(Vpk[2][9][0]*Vpk[3][9][0]))))+temp[0])));
        temp[2] = ((mk[9]*((Vpk[2][14][2]*Vpk[3][14][2])+((Vpk[2][13][0]*
          Vpk[3][14][0])+(Vpk[2][14][1]*Vpk[3][14][1]))))+((mk[8]*((
          Vpk[2][13][2]*Vpk[3][13][2])+((Vpk[2][12][1]*Vpk[3][13][1])+(
          Vpk[2][13][0]*Vpk[3][13][0]))))+((mk[7]*((Cik[3][2][2]*Vpk[3][12][2])+
          ((Vpk[2][12][0]*Vpk[3][12][0])+(Vpk[2][12][1]*Vpk[3][12][1]))))+
          temp[1])));
        temp[3] = ((mk[12]*((Vpk[2][17][2]*Vpk[3][17][2])+((Vpk[2][16][0]*
          Vpk[3][17][0])+(Vpk[2][17][1]*Vpk[3][17][1]))))+((mk[11]*((
          Vpk[2][16][2]*Vpk[3][16][2])+((Vpk[2][14][1]*Vpk[3][16][1])+(
          Vpk[2][16][0]*Vpk[3][16][0]))))+((mk[10]*((Vpk[2][15][2]*Vpk[3][15][2]
          )+((Vpk[2][14][1]*Vpk[3][15][1])+(Vpk[2][15][0]*Vpk[3][15][0]))))+
          temp[2])));
        temp[4] = ((mk[15]*((Vpk[2][20][2]*Vpk[3][20][2])+((Vpk[2][19][1]*
          Vpk[3][20][1])+(Vpk[2][20][0]*Vpk[3][20][0]))))+((mk[14]*((
          Vpk[2][19][2]*Vpk[3][19][2])+((Vpk[2][18][0]*Vpk[3][19][0])+(
          Vpk[2][19][1]*Vpk[3][19][1]))))+((mk[13]*((Vpk[2][18][2]*Vpk[3][18][2]
          )+((Cik[3][2][1]*Vpk[3][18][1])+(Vpk[2][18][0]*Vpk[3][18][0]))))+
          temp[3])));
        temp[5] = ((mk[18]*((Vpk[2][23][2]*Vpk[3][23][2])+((Vpk[2][22][0]*
          Vpk[3][23][0])+(Vpk[2][23][1]*Vpk[3][23][1]))))+((mk[17]*((
          Vpk[2][22][2]*Vpk[3][22][2])+((Cik[3][2][1]*Vpk[3][22][1])+(
          Vpk[2][22][0]*Vpk[3][22][0]))))+((mk[16]*((Vpk[2][20][2]*Vpk[3][21][2]
          )+((Vpk[2][21][0]*Vpk[3][21][0])+(Vpk[2][21][1]*Vpk[3][21][1]))))+
          temp[4])));
        mm[2][3] = ((mk[20]*((Vpk[2][24][2]*Vpk[3][25][2])+((Vpk[2][25][0]*
          Vpk[3][25][0])+(Vpk[2][25][1]*Vpk[3][25][1]))))+((mk[19]*((
          Vpk[2][24][2]*Vpk[3][24][2])+((Vpk[2][23][1]*Vpk[3][24][1])+(
          Vpk[2][24][0]*Vpk[3][24][0]))))+temp[5]));
        temp[0] = ((mk[3]*((Vpk[2][8][2]*Vpk[4][8][2])+((Vpk[2][7][0]*
          Vpk[4][8][0])+(Vpk[2][8][1]*Vpk[4][8][1]))))+((mk[2]*((Vpk[2][7][2]*
          Vpk[4][7][2])+((Vpk[2][6][1]*Vpk[4][7][1])+(Vpk[2][7][0]*Vpk[4][7][0])
          )))+((mk[0]*((Cik[3][2][2]*rk[0][0])-(Cik[3][2][0]*rk[0][2])))+(mk[1]*
          ((Cik[3][2][2]*Vpk[4][6][2])+((Vpk[2][6][0]*Vpk[4][6][0])+(
          Vpk[2][6][1]*Vpk[4][6][1])))))));
        temp[1] = ((mk[6]*((Vpk[2][11][2]*Vpk[4][11][2])+((Vpk[2][10][0]*
          Vpk[4][11][0])+(Vpk[2][11][1]*Vpk[4][11][1]))))+((mk[5]*((
          Vpk[2][10][2]*Vpk[4][10][2])+((Vpk[2][8][1]*Vpk[4][10][1])+(
          Vpk[2][10][0]*Vpk[4][10][0]))))+((mk[4]*((Vpk[2][9][2]*Vpk[4][9][2])+(
          (Vpk[2][8][1]*Vpk[4][9][1])+(Vpk[2][9][0]*Vpk[4][9][0]))))+temp[0])));
        temp[2] = ((mk[9]*((Vpk[2][14][2]*Vpk[4][14][2])+((Vpk[2][13][0]*
          Vpk[4][14][0])+(Vpk[2][14][1]*Vpk[4][14][1]))))+((mk[8]*((
          Vpk[2][13][2]*Vpk[4][13][2])+((Vpk[2][12][1]*Vpk[4][13][1])+(
          Vpk[2][13][0]*Vpk[4][13][0]))))+((mk[7]*((Cik[3][2][2]*Vpk[4][12][2])+
          ((Vpk[2][12][0]*Vpk[4][12][0])+(Vpk[2][12][1]*Vpk[4][12][1]))))+
          temp[1])));
        temp[3] = ((mk[13]*((Vpk[2][18][0]*Vpk[4][18][0])+(Vpk[2][18][2]*
          Vpk[4][18][2])))+((mk[12]*((Vpk[2][17][2]*Vpk[4][17][2])+((
          Vpk[2][16][0]*Vpk[4][17][0])+(Vpk[2][17][1]*Vpk[4][17][1]))))+((mk[11]
          *((Vpk[2][16][2]*Vpk[4][16][2])+((Vpk[2][14][1]*Vpk[4][16][1])+(
          Vpk[2][16][0]*Vpk[4][16][0]))))+((mk[10]*((Vpk[2][15][2]*Vpk[4][15][2]
          )+((Vpk[2][14][1]*Vpk[4][15][1])+(Vpk[2][15][0]*Vpk[4][15][0]))))+
          temp[2]))));
        temp[4] = ((mk[17]*((Vpk[2][22][0]*Vpk[4][22][0])+(Vpk[2][22][2]*
          Vpk[4][22][2])))+((mk[16]*((Vpk[2][20][2]*Vpk[4][21][2])+((
          Vpk[2][21][0]*Vpk[4][21][0])+(Vpk[2][21][1]*Vpk[4][21][1]))))+((mk[15]
          *((Vpk[2][20][2]*Vpk[4][20][2])+((Vpk[2][19][1]*Vpk[4][20][1])+(
          Vpk[2][20][0]*Vpk[4][20][0]))))+((mk[14]*((Vpk[2][19][2]*Vpk[4][19][2]
          )+((Vpk[2][18][0]*Vpk[4][19][0])+(Vpk[2][19][1]*Vpk[4][19][1]))))+
          temp[3]))));
        mm[2][4] = ((mk[20]*((Vpk[2][24][2]*Vpk[4][25][2])+((Vpk[2][25][0]*
          Vpk[4][25][0])+(Vpk[2][25][1]*Vpk[4][25][1]))))+((mk[19]*((
          Vpk[2][24][2]*Vpk[4][24][2])+((Vpk[2][23][1]*Vpk[4][24][1])+(
          Vpk[2][24][0]*Vpk[4][24][0]))))+((mk[18]*((Vpk[2][23][2]*Vpk[4][23][2]
          )+((Vpk[2][22][0]*Vpk[4][23][0])+(Vpk[2][23][1]*Vpk[4][23][1]))))+
          temp[4])));
        temp[0] = ((mk[3]*((Vpk[2][8][2]*Vpk[5][8][2])+((Vpk[2][7][0]*
          Vpk[5][8][0])+(Vpk[2][8][1]*Vpk[5][8][1]))))+((mk[2]*((Vpk[2][7][2]*
          Vpk[5][7][2])+((Vpk[2][6][1]*Vpk[5][7][1])+(Vpk[2][7][0]*Vpk[5][7][0])
          )))+((mk[0]*((Cik[3][2][0]*rk[0][1])-(Cik[3][2][1]*rk[0][0])))+(mk[1]*
          ((Vpk[2][6][0]*Vpk[5][6][0])+(Vpk[2][6][1]*Vpk[5][6][1]))))));
        temp[1] = ((mk[7]*((Vpk[2][12][0]*Vpk[5][12][0])+(Vpk[2][12][1]*
          Vpk[5][12][1])))+((mk[6]*((Vpk[2][11][2]*Vpk[5][11][2])+((
          Vpk[2][10][0]*Vpk[5][11][0])+(Vpk[2][11][1]*Vpk[5][11][1]))))+((mk[5]*
          ((Vpk[2][10][2]*Vpk[5][10][2])+((Vpk[2][8][1]*Vpk[5][10][1])+(
          Vpk[2][10][0]*Vpk[5][10][0]))))+((mk[4]*((Vpk[2][9][2]*Vpk[5][9][2])+(
          (Vpk[2][8][1]*Vpk[5][9][1])+(Vpk[2][9][0]*Vpk[5][9][0]))))+temp[0]))))
          ;
        temp[2] = ((mk[10]*((Vpk[2][15][2]*Vpk[5][15][2])+((Vpk[2][14][1]*
          Vpk[5][15][1])+(Vpk[2][15][0]*Vpk[5][15][0]))))+((mk[9]*((
          Vpk[2][14][2]*Vpk[5][14][2])+((Vpk[2][13][0]*Vpk[5][14][0])+(
          Vpk[2][14][1]*Vpk[5][14][1]))))+((mk[8]*((Vpk[2][13][2]*Vpk[5][13][2])
          +((Vpk[2][12][1]*Vpk[5][13][1])+(Vpk[2][13][0]*Vpk[5][13][0]))))+
          temp[1])));
        temp[3] = ((mk[13]*((Vpk[2][18][2]*Vpk[5][18][2])+((Cik[3][2][1]*
          Vpk[5][18][1])+(Vpk[2][18][0]*Vpk[5][18][0]))))+((mk[12]*((
          Vpk[2][17][2]*Vpk[5][17][2])+((Vpk[2][16][0]*Vpk[5][17][0])+(
          Vpk[2][17][1]*Vpk[5][17][1]))))+((mk[11]*((Vpk[2][16][2]*Vpk[5][16][2]
          )+((Vpk[2][14][1]*Vpk[5][16][1])+(Vpk[2][16][0]*Vpk[5][16][0]))))+
          temp[2])));
        temp[4] = ((mk[16]*((Vpk[2][20][2]*Vpk[5][21][2])+((Vpk[2][21][0]*
          Vpk[5][21][0])+(Vpk[2][21][1]*Vpk[5][21][1]))))+((mk[15]*((
          Vpk[2][20][2]*Vpk[5][20][2])+((Vpk[2][19][1]*Vpk[5][20][1])+(
          Vpk[2][20][0]*Vpk[5][20][0]))))+((mk[14]*((Vpk[2][19][2]*Vpk[5][19][2]
          )+((Vpk[2][18][0]*Vpk[5][19][0])+(Vpk[2][19][1]*Vpk[5][19][1]))))+
          temp[3])));
        temp[5] = ((mk[19]*((Vpk[2][24][2]*Vpk[5][24][2])+((Vpk[2][23][1]*
          Vpk[5][24][1])+(Vpk[2][24][0]*Vpk[5][24][0]))))+((mk[18]*((
          Vpk[2][23][2]*Vpk[5][23][2])+((Vpk[2][22][0]*Vpk[5][23][0])+(
          Vpk[2][23][1]*Vpk[5][23][1]))))+((mk[17]*((Vpk[2][22][2]*Vpk[5][22][2]
          )+((Cik[3][2][1]*Vpk[5][22][1])+(Vpk[2][22][0]*Vpk[5][22][0]))))+
          temp[4])));
        mm[2][5] = ((mk[20]*((Vpk[2][24][2]*Vpk[5][25][2])+((Vpk[2][25][0]*
          Vpk[5][25][0])+(Vpk[2][25][1]*Vpk[5][25][1]))))+temp[5]);
        temp[0] = ((mk[4]*((Vpk[2][9][2]*Vpk[6][9][2])+((Vpk[2][8][1]*
          Vpk[6][9][1])+(Vpk[2][9][0]*Vpk[6][9][0]))))+((mk[3]*((Vpk[2][8][2]*
          Vpk[6][8][2])+((Vpk[2][7][0]*Vpk[6][8][0])+(Vpk[2][8][1]*Vpk[6][8][1])
          )))+((mk[1]*((rk[1][1]*Vpk[2][6][0])-(rk[1][0]*Vpk[2][6][1])))+(mk[2]*
          ((Vpk[2][7][2]*Vpk[6][7][2])+((Vpk[2][6][1]*Vpk[6][7][1])+(
          Vpk[2][7][0]*Vpk[6][7][0])))))));
        mm[2][6] = ((mk[6]*((Vpk[2][11][2]*Vpk[6][11][2])+((Vpk[2][10][0]*
          Vpk[6][11][0])+(Vpk[2][11][1]*Vpk[6][11][1]))))+((mk[5]*((
          Vpk[2][10][2]*Vpk[6][10][2])+((Vpk[2][8][1]*Vpk[6][10][1])+(
          Vpk[2][10][0]*Vpk[6][10][0]))))+temp[0]));
        temp[0] = ((mk[5]*((Vpk[2][10][2]*Vpk[7][10][2])+((Vpk[2][8][1]*
          Vpk[7][10][1])+(Vpk[2][10][0]*Vpk[7][10][0]))))+((mk[4]*((Vpk[2][9][2]
          *Vpk[7][9][2])+((Vpk[2][8][1]*Vpk[7][9][1])+(Vpk[2][9][0]*Vpk[7][9][0]
          ))))+((mk[2]*((rk[2][0]*Vpk[2][7][2])-(rk[2][2]*Vpk[2][7][0])))+(mk[3]
          *((Vpk[2][8][2]*Vpk[7][8][2])+((Vpk[2][7][0]*Vpk[7][8][0])+(
          Vpk[2][8][1]*Vpk[7][8][1])))))));
        mm[2][7] = ((mk[6]*((Vpk[2][11][2]*Vpk[7][11][2])+((Vpk[2][10][0]*
          Vpk[7][11][0])+(Vpk[2][11][1]*Vpk[7][11][1]))))+temp[0]);
        mm[2][8] = ((mk[6]*((Vpk[2][11][2]*Vpk[8][11][2])+((Vpk[2][10][0]*
          Vpk[8][11][0])+(Vpk[2][11][1]*Vpk[8][11][1]))))+((mk[5]*((
          Vpk[2][10][2]*Vpk[8][10][2])+((Vpk[2][8][1]*Vpk[8][10][1])+(
          Vpk[2][10][0]*Vpk[8][10][0]))))+((mk[3]*((rk[3][2]*Vpk[2][8][1])-(
          rk[3][1]*Vpk[2][8][2])))+(mk[4]*((Vpk[2][9][2]*Vpk[8][9][2])+((
          Vpk[2][8][1]*Vpk[8][9][1])+(Vpk[2][9][0]*Vpk[8][9][0])))))));
        mm[2][9] = ((mk[6]*((Vpk[2][11][2]*Vpk[9][11][2])+((Vpk[2][10][0]*
          Vpk[9][11][0])+(Vpk[2][11][1]*Vpk[9][11][1]))))+((mk[4]*((rk[4][0]*
          Vpk[2][9][2])-(rk[4][2]*Vpk[2][9][0])))+(mk[5]*((Vpk[2][10][0]*
          Vpk[9][10][0])+(Vpk[2][10][2]*Vpk[9][10][2])))));
        mm[2][10] = ((mk[5]*((rk[5][0]*Vpk[2][10][2])-(rk[5][2]*Vpk[2][10][0])))
          +(mk[6]*((Vpk[2][11][2]*Vpk[10][11][2])+((Vpk[2][10][0]*Vpk[10][11][0]
          )+(Vpk[2][11][1]*Vpk[10][11][1])))));
        mm[2][11] = (mk[6]*((rk[6][2]*Vpk[2][11][1])-(rk[6][1]*Vpk[2][11][2])));
        temp[0] = ((mk[10]*((Vpk[2][15][2]*Vpk[12][15][2])+((Vpk[2][14][1]*
          Vpk[12][15][1])+(Vpk[2][15][0]*Vpk[12][15][0]))))+((mk[9]*((
          Vpk[2][14][2]*Vpk[12][14][2])+((Vpk[2][13][0]*Vpk[12][14][0])+(
          Vpk[2][14][1]*Vpk[12][14][1]))))+((mk[7]*((rk[7][1]*Vpk[2][12][0])-(
          rk[7][0]*Vpk[2][12][1])))+(mk[8]*((Vpk[2][13][2]*Vpk[12][13][2])+((
          Vpk[2][12][1]*Vpk[12][13][1])+(Vpk[2][13][0]*Vpk[12][13][0])))))));
        mm[2][12] = ((mk[12]*((Vpk[2][17][2]*Vpk[12][17][2])+((Vpk[2][16][0]*
          Vpk[12][17][0])+(Vpk[2][17][1]*Vpk[12][17][1]))))+((mk[11]*((
          Vpk[2][16][2]*Vpk[12][16][2])+((Vpk[2][14][1]*Vpk[12][16][1])+(
          Vpk[2][16][0]*Vpk[12][16][0]))))+temp[0]));
        temp[0] = ((mk[11]*((Vpk[2][16][2]*Vpk[13][16][2])+((Vpk[2][14][1]*
          Vpk[13][16][1])+(Vpk[2][16][0]*Vpk[13][16][0]))))+((mk[10]*((
          Vpk[2][15][2]*Vpk[13][15][2])+((Vpk[2][14][1]*Vpk[13][15][1])+(
          Vpk[2][15][0]*Vpk[13][15][0]))))+((mk[8]*((rk[8][0]*Vpk[2][13][2])-(
          rk[8][2]*Vpk[2][13][0])))+(mk[9]*((Vpk[2][14][2]*Vpk[13][14][2])+((
          Vpk[2][13][0]*Vpk[13][14][0])+(Vpk[2][14][1]*Vpk[13][14][1])))))));
        mm[2][13] = ((mk[12]*((Vpk[2][17][2]*Vpk[13][17][2])+((Vpk[2][16][0]*
          Vpk[13][17][0])+(Vpk[2][17][1]*Vpk[13][17][1]))))+temp[0]);
        mm[2][14] = ((mk[12]*((Vpk[2][17][2]*Vpk[14][17][2])+((Vpk[2][16][0]*
          Vpk[14][17][0])+(Vpk[2][17][1]*Vpk[14][17][1]))))+((mk[11]*((
          Vpk[2][16][2]*Vpk[14][16][2])+((Vpk[2][14][1]*Vpk[14][16][1])+(
          Vpk[2][16][0]*Vpk[14][16][0]))))+((mk[9]*((rk[9][2]*Vpk[2][14][1])-(
          rk[9][1]*Vpk[2][14][2])))+(mk[10]*((Vpk[2][15][2]*Vpk[14][15][2])+((
          Vpk[2][14][1]*Vpk[14][15][1])+(Vpk[2][15][0]*Vpk[14][15][0])))))));
        mm[2][15] = ((mk[12]*((Vpk[2][17][2]*Vpk[15][17][2])+((Vpk[2][16][0]*
          Vpk[15][17][0])+(Vpk[2][17][1]*Vpk[15][17][1]))))+((mk[10]*((rk[10][0]
          *Vpk[2][15][2])-(rk[10][2]*Vpk[2][15][0])))+(mk[11]*((Vpk[2][16][0]*
          Vpk[15][16][0])+(Vpk[2][16][2]*Vpk[15][16][2])))));
        mm[2][16] = ((mk[11]*((rk[11][0]*Vpk[2][16][2])-(rk[11][2]*Vpk[2][16][0]
          )))+(mk[12]*((Vpk[2][17][2]*Vpk[16][17][2])+((Vpk[2][16][0]*
          Vpk[16][17][0])+(Vpk[2][17][1]*Vpk[16][17][1])))));
        mm[2][17] = (mk[12]*((rk[12][2]*Vpk[2][17][1])-(rk[12][1]*Vpk[2][17][2])
          ));
        mm[2][18] = ((mk[16]*((Vpk[2][20][2]*Vpk[18][21][2])+((Vpk[2][21][0]*
          Vpk[18][21][0])+(Vpk[2][21][1]*Vpk[18][21][1]))))+((mk[15]*((
          Vpk[2][20][2]*Vpk[18][20][2])+((Vpk[2][19][1]*Vpk[18][20][1])+(
          Vpk[2][20][0]*Vpk[18][20][0]))))+((mk[13]*((rk[13][0]*Vpk[2][18][2])-(
          rk[13][2]*Vpk[2][18][0])))+(mk[14]*((Vpk[2][19][2]*Vpk[18][19][2])+((
          Vpk[2][18][0]*Vpk[18][19][0])+(Vpk[2][19][1]*Vpk[18][19][1])))))));
        mm[2][19] = ((mk[16]*((Vpk[2][20][2]*Vpk[19][21][2])+((Vpk[2][21][0]*
          Vpk[19][21][0])+(Vpk[2][21][1]*Vpk[19][21][1]))))+((mk[14]*((rk[14][2]
          *Vpk[2][19][1])-(rk[14][1]*Vpk[2][19][2])))+(mk[15]*((Vpk[2][20][2]*
          Vpk[19][20][2])+((Vpk[2][19][1]*Vpk[19][20][1])+(Vpk[2][20][0]*
          Vpk[19][20][0]))))));
        mm[2][20] = ((mk[15]*((rk[15][0]*Vpk[2][20][2])-(rk[15][2]*Vpk[2][20][0]
          )))+(mk[16]*((Vpk[2][20][2]*Vpk[20][21][2])+((Vpk[2][21][0]*
          Vpk[20][21][0])+(Vpk[2][21][1]*Vpk[20][21][1])))));
        mm[2][21] = (mk[16]*((rk[16][1]*Vpk[2][21][0])-(rk[16][0]*Vpk[2][21][1])
          ));
        mm[2][22] = ((mk[20]*((Vpk[2][24][2]*Vpk[22][25][2])+((Vpk[2][25][0]*
          Vpk[22][25][0])+(Vpk[2][25][1]*Vpk[22][25][1]))))+((mk[19]*((
          Vpk[2][24][2]*Vpk[22][24][2])+((Vpk[2][23][1]*Vpk[22][24][1])+(
          Vpk[2][24][0]*Vpk[22][24][0]))))+((mk[17]*((rk[17][0]*Vpk[2][22][2])-(
          rk[17][2]*Vpk[2][22][0])))+(mk[18]*((Vpk[2][23][2]*Vpk[22][23][2])+((
          Vpk[2][22][0]*Vpk[22][23][0])+(Vpk[2][23][1]*Vpk[22][23][1])))))));
        mm[2][23] = ((mk[20]*((Vpk[2][24][2]*Vpk[23][25][2])+((Vpk[2][25][0]*
          Vpk[23][25][0])+(Vpk[2][25][1]*Vpk[23][25][1]))))+((mk[18]*((rk[18][2]
          *Vpk[2][23][1])-(rk[18][1]*Vpk[2][23][2])))+(mk[19]*((Vpk[2][24][2]*
          Vpk[23][24][2])+((Vpk[2][23][1]*Vpk[23][24][1])+(Vpk[2][24][0]*
          Vpk[23][24][0]))))));
        mm[2][24] = ((mk[19]*((rk[19][0]*Vpk[2][24][2])-(rk[19][2]*Vpk[2][24][0]
          )))+(mk[20]*((Vpk[2][24][2]*Vpk[24][25][2])+((Vpk[2][25][0]*
          Vpk[24][25][0])+(Vpk[2][25][1]*Vpk[24][25][1])))));
        mm[2][25] = (mk[20]*((rk[20][1]*Vpk[2][25][0])-(rk[20][0]*Vpk[2][25][1])
          ));
        temp[0] = ((ik[0][0][0]+(mk[0]*((rk[0][1]*rk[0][1])+(rk[0][2]*rk[0][2]))
          ))+((mk[1]*((Vpk[3][6][2]*Vpk[3][6][2])+((Vpk[3][6][0]*Vpk[3][6][0])+(
          Vpk[3][6][1]*Vpk[3][6][1]))))+((IkWpk[3][6][0]*c6)-(IkWpk[3][6][1]*s6)
          )));
        temp[1] = (((mk[3]*((Vpk[3][8][2]*Vpk[3][8][2])+((Vpk[3][8][0]*
          Vpk[3][8][0])+(Vpk[3][8][1]*Vpk[3][8][1]))))+((IkWpk[3][8][2]*
          Wpk[3][8][2])+((IkWpk[3][8][0]*Wpk[3][7][0])+(IkWpk[3][8][1]*
          Wpk[3][8][1]))))+(temp[0]+((mk[2]*((Vpk[3][7][2]*Vpk[3][7][2])+((
          Vpk[3][7][0]*Vpk[3][7][0])+(Vpk[3][7][1]*Vpk[3][7][1]))))+((
          IkWpk[3][7][2]*Wpk[3][7][2])+((IkWpk[3][7][0]*Wpk[3][7][0])-(
          IkWpk[3][7][1]*s6))))));
        temp[2] = (((mk[4]*((Vpk[3][9][2]*Vpk[3][9][2])+((Vpk[3][9][0]*
          Vpk[3][9][0])+(Vpk[3][9][1]*Vpk[3][9][1]))))+((IkWpk[3][9][2]*
          Wpk[3][9][2])+((IkWpk[3][9][0]*Wpk[3][9][0])+(IkWpk[3][9][1]*
          Wpk[3][8][1]))))+temp[1]);
        temp[3] = (((mk[5]*((Vpk[3][10][2]*Vpk[3][10][2])+((Vpk[3][10][0]*
          Vpk[3][10][0])+(Vpk[3][10][1]*Vpk[3][10][1]))))+((IkWpk[3][10][2]*
          Wpk[3][10][2])+((IkWpk[3][10][0]*Wpk[3][10][0])+(IkWpk[3][10][1]*
          Wpk[3][8][1]))))+temp[2]);
        temp[4] = (((mk[7]*((Vpk[3][12][2]*Vpk[3][12][2])+((Vpk[3][12][0]*
          Vpk[3][12][0])+(Vpk[3][12][1]*Vpk[3][12][1]))))+((IkWpk[3][12][0]*c12)
          -(IkWpk[3][12][1]*s12)))+(((mk[6]*((Vpk[3][11][2]*Vpk[3][11][2])+((
          Vpk[3][11][0]*Vpk[3][11][0])+(Vpk[3][11][1]*Vpk[3][11][1]))))+((
          IkWpk[3][11][2]*Wpk[3][11][2])+((IkWpk[3][11][0]*Wpk[3][10][0])+(
          IkWpk[3][11][1]*Wpk[3][11][1]))))+temp[3]));
        temp[5] = (((mk[9]*((Vpk[3][14][2]*Vpk[3][14][2])+((Vpk[3][14][0]*
          Vpk[3][14][0])+(Vpk[3][14][1]*Vpk[3][14][1]))))+((IkWpk[3][14][2]*
          Wpk[3][14][2])+((IkWpk[3][14][0]*Wpk[3][13][0])+(IkWpk[3][14][1]*
          Wpk[3][14][1]))))+(((mk[8]*((Vpk[3][13][2]*Vpk[3][13][2])+((
          Vpk[3][13][0]*Vpk[3][13][0])+(Vpk[3][13][1]*Vpk[3][13][1]))))+((
          IkWpk[3][13][2]*Wpk[3][13][2])+((IkWpk[3][13][0]*Wpk[3][13][0])-(
          IkWpk[3][13][1]*s12))))+temp[4]));
        temp[6] = (((mk[10]*((Vpk[3][15][2]*Vpk[3][15][2])+((Vpk[3][15][0]*
          Vpk[3][15][0])+(Vpk[3][15][1]*Vpk[3][15][1]))))+((IkWpk[3][15][2]*
          Wpk[3][15][2])+((IkWpk[3][15][0]*Wpk[3][15][0])+(IkWpk[3][15][1]*
          Wpk[3][14][1]))))+temp[5]);
        temp[7] = (((mk[11]*((Vpk[3][16][2]*Vpk[3][16][2])+((Vpk[3][16][0]*
          Vpk[3][16][0])+(Vpk[3][16][1]*Vpk[3][16][1]))))+((IkWpk[3][16][2]*
          Wpk[3][16][2])+((IkWpk[3][16][0]*Wpk[3][16][0])+(IkWpk[3][16][1]*
          Wpk[3][14][1]))))+temp[6]);
        temp[8] = (((mk[13]*((Vpk[3][18][2]*Vpk[3][18][2])+((Vpk[3][18][0]*
          Vpk[3][18][0])+(Vpk[3][18][1]*Vpk[3][18][1]))))+((IkWpk[3][18][0]*c18)
          +(IkWpk[3][18][2]*s18)))+(((mk[12]*((Vpk[3][17][2]*Vpk[3][17][2])+((
          Vpk[3][17][0]*Vpk[3][17][0])+(Vpk[3][17][1]*Vpk[3][17][1]))))+((
          IkWpk[3][17][2]*Wpk[3][17][2])+((IkWpk[3][17][0]*Wpk[3][16][0])+(
          IkWpk[3][17][1]*Wpk[3][17][1]))))+temp[7]));
        temp[9] = (((mk[15]*((Vpk[3][20][2]*Vpk[3][20][2])+((Vpk[3][20][0]*
          Vpk[3][20][0])+(Vpk[3][20][1]*Vpk[3][20][1]))))+((IkWpk[3][20][2]*
          Wpk[3][20][2])+((IkWpk[3][20][0]*Wpk[3][20][0])+(IkWpk[3][20][1]*
          Wpk[3][19][1]))))+(((mk[14]*((Vpk[3][19][2]*Vpk[3][19][2])+((
          Vpk[3][19][0]*Vpk[3][19][0])+(Vpk[3][19][1]*Vpk[3][19][1]))))+((
          IkWpk[3][19][2]*Wpk[3][19][2])+((IkWpk[3][19][0]*c18)+(IkWpk[3][19][1]
          *Wpk[3][19][1]))))+temp[8]));
        temp[10] = (((mk[17]*((Vpk[3][22][2]*Vpk[3][22][2])+((Vpk[3][22][0]*
          Vpk[3][22][0])+(Vpk[3][22][1]*Vpk[3][22][1]))))+((IkWpk[3][22][0]*c22)
          +(IkWpk[3][22][2]*s22)))+(((mk[16]*((Vpk[3][21][2]*Vpk[3][21][2])+((
          Vpk[3][21][0]*Vpk[3][21][0])+(Vpk[3][21][1]*Vpk[3][21][1]))))+((
          IkWpk[3][21][2]*Wpk[3][20][2])+((IkWpk[3][21][0]*Wpk[3][21][0])+(
          IkWpk[3][21][1]*Wpk[3][21][1]))))+temp[9]));
        temp[11] = (((mk[19]*((Vpk[3][24][2]*Vpk[3][24][2])+((Vpk[3][24][0]*
          Vpk[3][24][0])+(Vpk[3][24][1]*Vpk[3][24][1]))))+((IkWpk[3][24][2]*
          Wpk[3][24][2])+((IkWpk[3][24][0]*Wpk[3][24][0])+(IkWpk[3][24][1]*
          Wpk[3][23][1]))))+(((mk[18]*((Vpk[3][23][2]*Vpk[3][23][2])+((
          Vpk[3][23][0]*Vpk[3][23][0])+(Vpk[3][23][1]*Vpk[3][23][1]))))+((
          IkWpk[3][23][2]*Wpk[3][23][2])+((IkWpk[3][23][0]*c22)+(IkWpk[3][23][1]
          *Wpk[3][23][1]))))+temp[10]));
        mm[3][3] = (((mk[20]*((Vpk[3][25][2]*Vpk[3][25][2])+((Vpk[3][25][0]*
          Vpk[3][25][0])+(Vpk[3][25][1]*Vpk[3][25][1]))))+((IkWpk[3][25][2]*
          Wpk[3][24][2])+((IkWpk[3][25][0]*Wpk[3][25][0])+(IkWpk[3][25][1]*
          Wpk[3][25][1]))))+temp[11]);
        temp[0] = (((ik[0][0][1]-(mk[0]*(rk[0][0]*rk[0][1])))+((mk[1]*((
          Vpk[3][6][2]*Vpk[4][6][2])+((Vpk[3][6][0]*Vpk[4][6][0])+(Vpk[3][6][1]*
          Vpk[4][6][1]))))+((IkWpk[4][6][0]*c6)-(IkWpk[4][6][1]*s6))))+((mk[2]*(
          (Vpk[3][7][2]*Vpk[4][7][2])+((Vpk[3][7][0]*Vpk[4][7][0])+(Vpk[3][7][1]
          *Vpk[4][7][1]))))+((IkWpk[4][7][2]*Wpk[3][7][2])+((IkWpk[4][7][0]*
          Wpk[3][7][0])-(IkWpk[4][7][1]*s6)))));
        temp[1] = (((mk[3]*((Vpk[3][8][2]*Vpk[4][8][2])+((Vpk[3][8][0]*
          Vpk[4][8][0])+(Vpk[3][8][1]*Vpk[4][8][1]))))+((IkWpk[4][8][2]*
          Wpk[3][8][2])+((IkWpk[4][8][0]*Wpk[3][7][0])+(IkWpk[4][8][1]*
          Wpk[3][8][1]))))+temp[0]);
        temp[2] = (((mk[4]*((Vpk[3][9][2]*Vpk[4][9][2])+((Vpk[3][9][0]*
          Vpk[4][9][0])+(Vpk[3][9][1]*Vpk[4][9][1]))))+((IkWpk[4][9][2]*
          Wpk[3][9][2])+((IkWpk[4][9][0]*Wpk[3][9][0])+(IkWpk[4][9][1]*
          Wpk[3][8][1]))))+temp[1]);
        temp[3] = (((mk[5]*((Vpk[3][10][2]*Vpk[4][10][2])+((Vpk[3][10][0]*
          Vpk[4][10][0])+(Vpk[3][10][1]*Vpk[4][10][1]))))+((IkWpk[4][10][2]*
          Wpk[3][10][2])+((IkWpk[4][10][0]*Wpk[3][10][0])+(IkWpk[4][10][1]*
          Wpk[3][8][1]))))+temp[2]);
        temp[4] = (((mk[7]*((Vpk[3][12][2]*Vpk[4][12][2])+((Vpk[3][12][0]*
          Vpk[4][12][0])+(Vpk[3][12][1]*Vpk[4][12][1]))))+((IkWpk[4][12][0]*c12)
          -(IkWpk[4][12][1]*s12)))+(((mk[6]*((Vpk[3][11][2]*Vpk[4][11][2])+((
          Vpk[3][11][0]*Vpk[4][11][0])+(Vpk[3][11][1]*Vpk[4][11][1]))))+((
          IkWpk[4][11][2]*Wpk[3][11][2])+((IkWpk[4][11][0]*Wpk[3][10][0])+(
          IkWpk[4][11][1]*Wpk[3][11][1]))))+temp[3]));
        temp[5] = (((mk[9]*((Vpk[3][14][2]*Vpk[4][14][2])+((Vpk[3][14][0]*
          Vpk[4][14][0])+(Vpk[3][14][1]*Vpk[4][14][1]))))+((IkWpk[4][14][2]*
          Wpk[3][14][2])+((IkWpk[4][14][0]*Wpk[3][13][0])+(IkWpk[4][14][1]*
          Wpk[3][14][1]))))+(((mk[8]*((Vpk[3][13][2]*Vpk[4][13][2])+((
          Vpk[3][13][0]*Vpk[4][13][0])+(Vpk[3][13][1]*Vpk[4][13][1]))))+((
          IkWpk[4][13][2]*Wpk[3][13][2])+((IkWpk[4][13][0]*Wpk[3][13][0])-(
          IkWpk[4][13][1]*s12))))+temp[4]));
        temp[6] = (((mk[10]*((Vpk[3][15][2]*Vpk[4][15][2])+((Vpk[3][15][0]*
          Vpk[4][15][0])+(Vpk[3][15][1]*Vpk[4][15][1]))))+((IkWpk[4][15][2]*
          Wpk[3][15][2])+((IkWpk[4][15][0]*Wpk[3][15][0])+(IkWpk[4][15][1]*
          Wpk[3][14][1]))))+temp[5]);
        temp[7] = (((mk[11]*((Vpk[3][16][2]*Vpk[4][16][2])+((Vpk[3][16][0]*
          Vpk[4][16][0])+(Vpk[3][16][1]*Vpk[4][16][1]))))+((IkWpk[4][16][2]*
          Wpk[3][16][2])+((IkWpk[4][16][0]*Wpk[3][16][0])+(IkWpk[4][16][1]*
          Wpk[3][14][1]))))+temp[6]);
        temp[8] = (((mk[13]*((Vpk[3][18][0]*Vpk[4][18][0])+(Vpk[3][18][2]*
          Vpk[4][18][2])))+((ik[13][0][1]*c18)+(ik[13][2][1]*s18)))+(((mk[12]*((
          Vpk[3][17][2]*Vpk[4][17][2])+((Vpk[3][17][0]*Vpk[4][17][0])+(
          Vpk[3][17][1]*Vpk[4][17][1]))))+((IkWpk[4][17][2]*Wpk[3][17][2])+((
          IkWpk[4][17][0]*Wpk[3][16][0])+(IkWpk[4][17][1]*Wpk[3][17][1]))))+
          temp[7]));
        temp[9] = (((mk[15]*((Vpk[3][20][2]*Vpk[4][20][2])+((Vpk[3][20][0]*
          Vpk[4][20][0])+(Vpk[3][20][1]*Vpk[4][20][1]))))+((IkWpk[4][20][2]*
          Wpk[3][20][2])+((IkWpk[4][20][0]*Wpk[3][20][0])+(IkWpk[4][20][1]*
          Wpk[3][19][1]))))+(((mk[14]*((Vpk[3][19][2]*Vpk[4][19][2])+((
          Vpk[3][19][0]*Vpk[4][19][0])+(Vpk[3][19][1]*Vpk[4][19][1]))))+((
          IkWpk[4][19][2]*Wpk[3][19][2])+((IkWpk[4][19][0]*c18)+(IkWpk[4][19][1]
          *Wpk[3][19][1]))))+temp[8]));
        temp[10] = (((mk[17]*((Vpk[3][22][0]*Vpk[4][22][0])+(Vpk[3][22][2]*
          Vpk[4][22][2])))+((ik[17][0][1]*c22)+(ik[17][2][1]*s22)))+(((mk[16]*((
          Vpk[3][21][2]*Vpk[4][21][2])+((Vpk[3][21][0]*Vpk[4][21][0])+(
          Vpk[3][21][1]*Vpk[4][21][1]))))+((IkWpk[4][21][2]*Wpk[3][20][2])+((
          IkWpk[4][21][0]*Wpk[3][21][0])+(IkWpk[4][21][1]*Wpk[3][21][1]))))+
          temp[9]));
        temp[11] = (((mk[19]*((Vpk[3][24][2]*Vpk[4][24][2])+((Vpk[3][24][0]*
          Vpk[4][24][0])+(Vpk[3][24][1]*Vpk[4][24][1]))))+((IkWpk[4][24][2]*
          Wpk[3][24][2])+((IkWpk[4][24][0]*Wpk[3][24][0])+(IkWpk[4][24][1]*
          Wpk[3][23][1]))))+(((mk[18]*((Vpk[3][23][2]*Vpk[4][23][2])+((
          Vpk[3][23][0]*Vpk[4][23][0])+(Vpk[3][23][1]*Vpk[4][23][1]))))+((
          IkWpk[4][23][2]*Wpk[3][23][2])+((IkWpk[4][23][0]*c22)+(IkWpk[4][23][1]
          *Wpk[3][23][1]))))+temp[10]));
        mm[3][4] = (((mk[20]*((Vpk[3][25][2]*Vpk[4][25][2])+((Vpk[3][25][0]*
          Vpk[4][25][0])+(Vpk[3][25][1]*Vpk[4][25][1]))))+((IkWpk[4][25][2]*
          Wpk[3][24][2])+((IkWpk[4][25][0]*Wpk[3][25][0])+(IkWpk[4][25][1]*
          Wpk[3][25][1]))))+temp[11]);
        temp[0] = (((ik[0][0][2]-(mk[0]*(rk[0][0]*rk[0][2])))+((mk[1]*((
          Vpk[3][6][0]*Vpk[5][6][0])+(Vpk[3][6][1]*Vpk[5][6][1])))+((ik[1][0][2]
          *c6)-(ik[1][1][2]*s6))))+((mk[2]*((Vpk[3][7][2]*Vpk[5][7][2])+((
          Vpk[3][7][0]*Vpk[5][7][0])+(Vpk[3][7][1]*Vpk[5][7][1]))))+((
          IkWpk[5][7][2]*Wpk[3][7][2])+((IkWpk[5][7][0]*Wpk[3][7][0])-(
          IkWpk[5][7][1]*s6)))));
        temp[1] = (((mk[3]*((Vpk[3][8][2]*Vpk[5][8][2])+((Vpk[3][8][0]*
          Vpk[5][8][0])+(Vpk[3][8][1]*Vpk[5][8][1]))))+((IkWpk[5][8][2]*
          Wpk[3][8][2])+((IkWpk[5][8][0]*Wpk[3][7][0])+(IkWpk[5][8][1]*
          Wpk[3][8][1]))))+temp[0]);
        temp[2] = (((mk[4]*((Vpk[3][9][2]*Vpk[5][9][2])+((Vpk[3][9][0]*
          Vpk[5][9][0])+(Vpk[3][9][1]*Vpk[5][9][1]))))+((IkWpk[5][9][2]*
          Wpk[3][9][2])+((IkWpk[5][9][0]*Wpk[3][9][0])+(IkWpk[5][9][1]*
          Wpk[3][8][1]))))+temp[1]);
        temp[3] = (((mk[5]*((Vpk[3][10][2]*Vpk[5][10][2])+((Vpk[3][10][0]*
          Vpk[5][10][0])+(Vpk[3][10][1]*Vpk[5][10][1]))))+((IkWpk[5][10][2]*
          Wpk[3][10][2])+((IkWpk[5][10][0]*Wpk[3][10][0])+(IkWpk[5][10][1]*
          Wpk[3][8][1]))))+temp[2]);
        temp[4] = (((mk[7]*((Vpk[3][12][0]*Vpk[5][12][0])+(Vpk[3][12][1]*
          Vpk[5][12][1])))+((ik[7][0][2]*c12)-(ik[7][1][2]*s12)))+(((mk[6]*((
          Vpk[3][11][2]*Vpk[5][11][2])+((Vpk[3][11][0]*Vpk[5][11][0])+(
          Vpk[3][11][1]*Vpk[5][11][1]))))+((IkWpk[5][11][2]*Wpk[3][11][2])+((
          IkWpk[5][11][0]*Wpk[3][10][0])+(IkWpk[5][11][1]*Wpk[3][11][1]))))+
          temp[3]));
        temp[5] = (((mk[9]*((Vpk[3][14][2]*Vpk[5][14][2])+((Vpk[3][14][0]*
          Vpk[5][14][0])+(Vpk[3][14][1]*Vpk[5][14][1]))))+((IkWpk[5][14][2]*
          Wpk[3][14][2])+((IkWpk[5][14][0]*Wpk[3][13][0])+(IkWpk[5][14][1]*
          Wpk[3][14][1]))))+(((mk[8]*((Vpk[3][13][2]*Vpk[5][13][2])+((
          Vpk[3][13][0]*Vpk[5][13][0])+(Vpk[3][13][1]*Vpk[5][13][1]))))+((
          IkWpk[5][13][2]*Wpk[3][13][2])+((IkWpk[5][13][0]*Wpk[3][13][0])-(
          IkWpk[5][13][1]*s12))))+temp[4]));
        temp[6] = (((mk[10]*((Vpk[3][15][2]*Vpk[5][15][2])+((Vpk[3][15][0]*
          Vpk[5][15][0])+(Vpk[3][15][1]*Vpk[5][15][1]))))+((IkWpk[5][15][2]*
          Wpk[3][15][2])+((IkWpk[5][15][0]*Wpk[3][15][0])+(IkWpk[5][15][1]*
          Wpk[3][14][1]))))+temp[5]);
        temp[7] = (((mk[11]*((Vpk[3][16][2]*Vpk[5][16][2])+((Vpk[3][16][0]*
          Vpk[5][16][0])+(Vpk[3][16][1]*Vpk[5][16][1]))))+((IkWpk[5][16][2]*
          Wpk[3][16][2])+((IkWpk[5][16][0]*Wpk[3][16][0])+(IkWpk[5][16][1]*
          Wpk[3][14][1]))))+temp[6]);
        temp[8] = (((mk[13]*((Vpk[3][18][2]*Vpk[5][18][2])+((Vpk[3][18][0]*
          Vpk[5][18][0])+(Vpk[3][18][1]*Vpk[5][18][1]))))+((IkWpk[5][18][0]*c18)
          +(IkWpk[5][18][2]*s18)))+(((mk[12]*((Vpk[3][17][2]*Vpk[5][17][2])+((
          Vpk[3][17][0]*Vpk[5][17][0])+(Vpk[3][17][1]*Vpk[5][17][1]))))+((
          IkWpk[5][17][2]*Wpk[3][17][2])+((IkWpk[5][17][0]*Wpk[3][16][0])+(
          IkWpk[5][17][1]*Wpk[3][17][1]))))+temp[7]));
        temp[9] = (((mk[15]*((Vpk[3][20][2]*Vpk[5][20][2])+((Vpk[3][20][0]*
          Vpk[5][20][0])+(Vpk[3][20][1]*Vpk[5][20][1]))))+((IkWpk[5][20][2]*
          Wpk[3][20][2])+((IkWpk[5][20][0]*Wpk[3][20][0])+(IkWpk[5][20][1]*
          Wpk[3][19][1]))))+(((mk[14]*((Vpk[3][19][2]*Vpk[5][19][2])+((
          Vpk[3][19][0]*Vpk[5][19][0])+(Vpk[3][19][1]*Vpk[5][19][1]))))+((
          IkWpk[5][19][2]*Wpk[3][19][2])+((IkWpk[5][19][0]*c18)+(IkWpk[5][19][1]
          *Wpk[3][19][1]))))+temp[8]));
        temp[10] = (((mk[17]*((Vpk[3][22][2]*Vpk[5][22][2])+((Vpk[3][22][0]*
          Vpk[5][22][0])+(Vpk[3][22][1]*Vpk[5][22][1]))))+((IkWpk[5][22][0]*c22)
          +(IkWpk[5][22][2]*s22)))+(((mk[16]*((Vpk[3][21][2]*Vpk[5][21][2])+((
          Vpk[3][21][0]*Vpk[5][21][0])+(Vpk[3][21][1]*Vpk[5][21][1]))))+((
          IkWpk[5][21][2]*Wpk[3][20][2])+((IkWpk[5][21][0]*Wpk[3][21][0])+(
          IkWpk[5][21][1]*Wpk[3][21][1]))))+temp[9]));
        temp[11] = (((mk[19]*((Vpk[3][24][2]*Vpk[5][24][2])+((Vpk[3][24][0]*
          Vpk[5][24][0])+(Vpk[3][24][1]*Vpk[5][24][1]))))+((IkWpk[5][24][2]*
          Wpk[3][24][2])+((IkWpk[5][24][0]*Wpk[3][24][0])+(IkWpk[5][24][1]*
          Wpk[3][23][1]))))+(((mk[18]*((Vpk[3][23][2]*Vpk[5][23][2])+((
          Vpk[3][23][0]*Vpk[5][23][0])+(Vpk[3][23][1]*Vpk[5][23][1]))))+((
          IkWpk[5][23][2]*Wpk[3][23][2])+((IkWpk[5][23][0]*c22)+(IkWpk[5][23][1]
          *Wpk[3][23][1]))))+temp[10]));
        mm[3][5] = (((mk[20]*((Vpk[3][25][2]*Vpk[5][25][2])+((Vpk[3][25][0]*
          Vpk[5][25][0])+(Vpk[3][25][1]*Vpk[5][25][1]))))+((IkWpk[5][25][2]*
          Wpk[3][24][2])+((IkWpk[5][25][0]*Wpk[3][25][0])+(IkWpk[5][25][1]*
          Wpk[3][25][1]))))+temp[11]);
        temp[0] = (((mk[1]*((rk[1][1]*Vpk[3][6][0])-(rk[1][0]*Vpk[3][6][1])))+((
          ik[1][0][2]*c6)-(ik[1][1][2]*s6)))+((mk[2]*((Vpk[3][7][2]*Vpk[6][7][2]
          )+((Vpk[3][7][0]*Vpk[6][7][0])+(Vpk[3][7][1]*Vpk[6][7][1]))))+((
          IkWpk[6][7][2]*Wpk[3][7][2])+((IkWpk[6][7][0]*Wpk[3][7][0])-(
          IkWpk[6][7][1]*s6)))));
        temp[1] = (((mk[3]*((Vpk[3][8][2]*Vpk[6][8][2])+((Vpk[3][8][0]*
          Vpk[6][8][0])+(Vpk[3][8][1]*Vpk[6][8][1]))))+((IkWpk[6][8][2]*
          Wpk[3][8][2])+((IkWpk[6][8][0]*Wpk[3][7][0])+(IkWpk[6][8][1]*
          Wpk[3][8][1]))))+temp[0]);
        temp[2] = (((mk[4]*((Vpk[3][9][2]*Vpk[6][9][2])+((Vpk[3][9][0]*
          Vpk[6][9][0])+(Vpk[3][9][1]*Vpk[6][9][1]))))+((IkWpk[6][9][2]*
          Wpk[3][9][2])+((IkWpk[6][9][0]*Wpk[3][9][0])+(IkWpk[6][9][1]*
          Wpk[3][8][1]))))+temp[1]);
        temp[3] = (((mk[5]*((Vpk[3][10][2]*Vpk[6][10][2])+((Vpk[3][10][0]*
          Vpk[6][10][0])+(Vpk[3][10][1]*Vpk[6][10][1]))))+((IkWpk[6][10][2]*
          Wpk[3][10][2])+((IkWpk[6][10][0]*Wpk[3][10][0])+(IkWpk[6][10][1]*
          Wpk[3][8][1]))))+temp[2]);
        mm[3][6] = (((mk[6]*((Vpk[3][11][2]*Vpk[6][11][2])+((Vpk[3][11][0]*
          Vpk[6][11][0])+(Vpk[3][11][1]*Vpk[6][11][1]))))+((IkWpk[6][11][2]*
          Wpk[3][11][2])+((IkWpk[6][11][0]*Wpk[3][10][0])+(IkWpk[6][11][1]*
          Wpk[3][11][1]))))+temp[3]);
        temp[0] = (((mk[2]*((rk[2][0]*Vpk[3][7][2])-(rk[2][2]*Vpk[3][7][0])))+((
          ik[2][2][1]*Wpk[3][7][2])+((ik[2][0][1]*Wpk[3][7][0])-(ik[2][1][1]*s6)
          )))+((mk[3]*((Vpk[3][8][2]*Vpk[7][8][2])+((Vpk[3][8][0]*Vpk[7][8][0])+
          (Vpk[3][8][1]*Vpk[7][8][1]))))+((IkWpk[7][8][2]*Wpk[3][8][2])+((
          IkWpk[7][8][0]*Wpk[3][7][0])+(IkWpk[7][8][1]*Wpk[3][8][1])))));
        temp[1] = (((mk[4]*((Vpk[3][9][2]*Vpk[7][9][2])+((Vpk[3][9][0]*
          Vpk[7][9][0])+(Vpk[3][9][1]*Vpk[7][9][1]))))+((IkWpk[7][9][2]*
          Wpk[3][9][2])+((IkWpk[7][9][0]*Wpk[3][9][0])+(IkWpk[7][9][1]*
          Wpk[3][8][1]))))+temp[0]);
        temp[2] = (((mk[5]*((Vpk[3][10][2]*Vpk[7][10][2])+((Vpk[3][10][0]*
          Vpk[7][10][0])+(Vpk[3][10][1]*Vpk[7][10][1]))))+((IkWpk[7][10][2]*
          Wpk[3][10][2])+((IkWpk[7][10][0]*Wpk[3][10][0])+(IkWpk[7][10][1]*
          Wpk[3][8][1]))))+temp[1]);
        mm[3][7] = (((mk[6]*((Vpk[3][11][2]*Vpk[7][11][2])+((Vpk[3][11][0]*
          Vpk[7][11][0])+(Vpk[3][11][1]*Vpk[7][11][1]))))+((IkWpk[7][11][2]*
          Wpk[3][11][2])+((IkWpk[7][11][0]*Wpk[3][10][0])+(IkWpk[7][11][1]*
          Wpk[3][11][1]))))+temp[2]);
        temp[0] = (((mk[3]*((rk[3][2]*Vpk[3][8][1])-(rk[3][1]*Vpk[3][8][2])))+((
          ik[3][2][0]*Wpk[3][8][2])+((ik[3][0][0]*Wpk[3][7][0])+(ik[3][1][0]*
          Wpk[3][8][1]))))+((mk[4]*((Vpk[3][9][2]*Vpk[8][9][2])+((Vpk[3][9][0]*
          Vpk[8][9][0])+(Vpk[3][9][1]*Vpk[8][9][1]))))+((IkWpk[8][9][2]*
          Wpk[3][9][2])+((IkWpk[8][9][0]*Wpk[3][9][0])+(IkWpk[8][9][1]*
          Wpk[3][8][1])))));
        temp[1] = (((mk[5]*((Vpk[3][10][2]*Vpk[8][10][2])+((Vpk[3][10][0]*
          Vpk[8][10][0])+(Vpk[3][10][1]*Vpk[8][10][1]))))+((IkWpk[8][10][2]*
          Wpk[3][10][2])+((IkWpk[8][10][0]*Wpk[3][10][0])+(IkWpk[8][10][1]*
          Wpk[3][8][1]))))+temp[0]);
        mm[3][8] = (((mk[6]*((Vpk[3][11][2]*Vpk[8][11][2])+((Vpk[3][11][0]*
          Vpk[8][11][0])+(Vpk[3][11][1]*Vpk[8][11][1]))))+((IkWpk[8][11][2]*
          Wpk[3][11][2])+((IkWpk[8][11][0]*Wpk[3][10][0])+(IkWpk[8][11][1]*
          Wpk[3][11][1]))))+temp[1]);
        temp[0] = (((mk[4]*((rk[4][0]*Vpk[3][9][2])-(rk[4][2]*Vpk[3][9][0])))+((
          ik[4][2][1]*Wpk[3][9][2])+((ik[4][0][1]*Wpk[3][9][0])+(ik[4][1][1]*
          Wpk[3][8][1]))))+((mk[5]*((Vpk[3][10][0]*Vpk[9][10][0])+(Vpk[3][10][2]
          *Vpk[9][10][2])))+((ik[5][2][1]*Wpk[3][10][2])+((ik[5][0][1]*
          Wpk[3][10][0])+(ik[5][1][1]*Wpk[3][8][1])))));
        mm[3][9] = (((mk[6]*((Vpk[3][11][2]*Vpk[9][11][2])+((Vpk[3][11][0]*
          Vpk[9][11][0])+(Vpk[3][11][1]*Vpk[9][11][1]))))+((IkWpk[9][11][2]*
          Wpk[3][11][2])+((IkWpk[9][11][0]*Wpk[3][10][0])+(IkWpk[9][11][1]*
          Wpk[3][11][1]))))+temp[0]);
        mm[3][10] = (((mk[5]*((rk[5][0]*Vpk[3][10][2])-(rk[5][2]*Vpk[3][10][0]))
          )+((ik[5][2][1]*Wpk[3][10][2])+((ik[5][0][1]*Wpk[3][10][0])+(
          ik[5][1][1]*Wpk[3][8][1]))))+((mk[6]*((Vpk[3][11][2]*Vpk[10][11][2])+(
          (Vpk[3][11][0]*Vpk[10][11][0])+(Vpk[3][11][1]*Vpk[10][11][1]))))+((
          IkWpk[10][11][2]*Wpk[3][11][2])+((IkWpk[10][11][0]*Wpk[3][10][0])+(
          IkWpk[10][11][1]*Wpk[3][11][1])))));
        mm[3][11] = ((mk[6]*((rk[6][2]*Vpk[3][11][1])-(rk[6][1]*Vpk[3][11][2])))
          +((ik[6][2][0]*Wpk[3][11][2])+((ik[6][0][0]*Wpk[3][10][0])+(
          ik[6][1][0]*Wpk[3][11][1]))));
        temp[0] = (((mk[7]*((rk[7][1]*Vpk[3][12][0])-(rk[7][0]*Vpk[3][12][1])))+
          ((ik[7][0][2]*c12)-(ik[7][1][2]*s12)))+((mk[8]*((Vpk[3][13][2]*
          Vpk[12][13][2])+((Vpk[3][13][0]*Vpk[12][13][0])+(Vpk[3][13][1]*
          Vpk[12][13][1]))))+((IkWpk[12][13][2]*Wpk[3][13][2])+((
          IkWpk[12][13][0]*Wpk[3][13][0])-(IkWpk[12][13][1]*s12)))));
        temp[1] = (((mk[9]*((Vpk[3][14][2]*Vpk[12][14][2])+((Vpk[3][14][0]*
          Vpk[12][14][0])+(Vpk[3][14][1]*Vpk[12][14][1]))))+((IkWpk[12][14][2]*
          Wpk[3][14][2])+((IkWpk[12][14][0]*Wpk[3][13][0])+(IkWpk[12][14][1]*
          Wpk[3][14][1]))))+temp[0]);
        temp[2] = (((mk[10]*((Vpk[3][15][2]*Vpk[12][15][2])+((Vpk[3][15][0]*
          Vpk[12][15][0])+(Vpk[3][15][1]*Vpk[12][15][1]))))+((IkWpk[12][15][2]*
          Wpk[3][15][2])+((IkWpk[12][15][0]*Wpk[3][15][0])+(IkWpk[12][15][1]*
          Wpk[3][14][1]))))+temp[1]);
        temp[3] = (((mk[11]*((Vpk[3][16][2]*Vpk[12][16][2])+((Vpk[3][16][0]*
          Vpk[12][16][0])+(Vpk[3][16][1]*Vpk[12][16][1]))))+((IkWpk[12][16][2]*
          Wpk[3][16][2])+((IkWpk[12][16][0]*Wpk[3][16][0])+(IkWpk[12][16][1]*
          Wpk[3][14][1]))))+temp[2]);
        mm[3][12] = (((mk[12]*((Vpk[3][17][2]*Vpk[12][17][2])+((Vpk[3][17][0]*
          Vpk[12][17][0])+(Vpk[3][17][1]*Vpk[12][17][1]))))+((IkWpk[12][17][2]*
          Wpk[3][17][2])+((IkWpk[12][17][0]*Wpk[3][16][0])+(IkWpk[12][17][1]*
          Wpk[3][17][1]))))+temp[3]);
        temp[0] = (((mk[8]*((rk[8][0]*Vpk[3][13][2])-(rk[8][2]*Vpk[3][13][0])))+
          ((ik[8][2][1]*Wpk[3][13][2])+((ik[8][0][1]*Wpk[3][13][0])-(ik[8][1][1]
          *s12))))+((mk[9]*((Vpk[3][14][2]*Vpk[13][14][2])+((Vpk[3][14][0]*
          Vpk[13][14][0])+(Vpk[3][14][1]*Vpk[13][14][1]))))+((IkWpk[13][14][2]*
          Wpk[3][14][2])+((IkWpk[13][14][0]*Wpk[3][13][0])+(IkWpk[13][14][1]*
          Wpk[3][14][1])))));
        temp[1] = (((mk[10]*((Vpk[3][15][2]*Vpk[13][15][2])+((Vpk[3][15][0]*
          Vpk[13][15][0])+(Vpk[3][15][1]*Vpk[13][15][1]))))+((IkWpk[13][15][2]*
          Wpk[3][15][2])+((IkWpk[13][15][0]*Wpk[3][15][0])+(IkWpk[13][15][1]*
          Wpk[3][14][1]))))+temp[0]);
        temp[2] = (((mk[11]*((Vpk[3][16][2]*Vpk[13][16][2])+((Vpk[3][16][0]*
          Vpk[13][16][0])+(Vpk[3][16][1]*Vpk[13][16][1]))))+((IkWpk[13][16][2]*
          Wpk[3][16][2])+((IkWpk[13][16][0]*Wpk[3][16][0])+(IkWpk[13][16][1]*
          Wpk[3][14][1]))))+temp[1]);
        mm[3][13] = (((mk[12]*((Vpk[3][17][2]*Vpk[13][17][2])+((Vpk[3][17][0]*
          Vpk[13][17][0])+(Vpk[3][17][1]*Vpk[13][17][1]))))+((IkWpk[13][17][2]*
          Wpk[3][17][2])+((IkWpk[13][17][0]*Wpk[3][16][0])+(IkWpk[13][17][1]*
          Wpk[3][17][1]))))+temp[2]);
        temp[0] = (((mk[9]*((rk[9][2]*Vpk[3][14][1])-(rk[9][1]*Vpk[3][14][2])))+
          ((ik[9][2][0]*Wpk[3][14][2])+((ik[9][0][0]*Wpk[3][13][0])+(ik[9][1][0]
          *Wpk[3][14][1]))))+((mk[10]*((Vpk[3][15][2]*Vpk[14][15][2])+((
          Vpk[3][15][0]*Vpk[14][15][0])+(Vpk[3][15][1]*Vpk[14][15][1]))))+((
          IkWpk[14][15][2]*Wpk[3][15][2])+((IkWpk[14][15][0]*Wpk[3][15][0])+(
          IkWpk[14][15][1]*Wpk[3][14][1])))));
        temp[1] = (((mk[11]*((Vpk[3][16][2]*Vpk[14][16][2])+((Vpk[3][16][0]*
          Vpk[14][16][0])+(Vpk[3][16][1]*Vpk[14][16][1]))))+((IkWpk[14][16][2]*
          Wpk[3][16][2])+((IkWpk[14][16][0]*Wpk[3][16][0])+(IkWpk[14][16][1]*
          Wpk[3][14][1]))))+temp[0]);
        mm[3][14] = (((mk[12]*((Vpk[3][17][2]*Vpk[14][17][2])+((Vpk[3][17][0]*
          Vpk[14][17][0])+(Vpk[3][17][1]*Vpk[14][17][1]))))+((IkWpk[14][17][2]*
          Wpk[3][17][2])+((IkWpk[14][17][0]*Wpk[3][16][0])+(IkWpk[14][17][1]*
          Wpk[3][17][1]))))+temp[1]);
        temp[0] = (((mk[10]*((rk[10][0]*Vpk[3][15][2])-(rk[10][2]*Vpk[3][15][0])
          ))+((ik[10][2][1]*Wpk[3][15][2])+((ik[10][0][1]*Wpk[3][15][0])+(
          ik[10][1][1]*Wpk[3][14][1]))))+((mk[11]*((Vpk[3][16][0]*Vpk[15][16][0]
          )+(Vpk[3][16][2]*Vpk[15][16][2])))+((ik[11][2][1]*Wpk[3][16][2])+((
          ik[11][0][1]*Wpk[3][16][0])+(ik[11][1][1]*Wpk[3][14][1])))));
        mm[3][15] = (((mk[12]*((Vpk[3][17][2]*Vpk[15][17][2])+((Vpk[3][17][0]*
          Vpk[15][17][0])+(Vpk[3][17][1]*Vpk[15][17][1]))))+((IkWpk[15][17][2]*
          Wpk[3][17][2])+((IkWpk[15][17][0]*Wpk[3][16][0])+(IkWpk[15][17][1]*
          Wpk[3][17][1]))))+temp[0]);
        mm[3][16] = (((mk[11]*((rk[11][0]*Vpk[3][16][2])-(rk[11][2]*
          Vpk[3][16][0])))+((ik[11][2][1]*Wpk[3][16][2])+((ik[11][0][1]*
          Wpk[3][16][0])+(ik[11][1][1]*Wpk[3][14][1]))))+((mk[12]*((
          Vpk[3][17][2]*Vpk[16][17][2])+((Vpk[3][17][0]*Vpk[16][17][0])+(
          Vpk[3][17][1]*Vpk[16][17][1]))))+((IkWpk[16][17][2]*Wpk[3][17][2])+((
          IkWpk[16][17][0]*Wpk[3][16][0])+(IkWpk[16][17][1]*Wpk[3][17][1])))));
        mm[3][17] = ((mk[12]*((rk[12][2]*Vpk[3][17][1])-(rk[12][1]*Vpk[3][17][2]
          )))+((ik[12][2][0]*Wpk[3][17][2])+((ik[12][0][0]*Wpk[3][16][0])+(
          ik[12][1][0]*Wpk[3][17][1]))));
        temp[0] = (((mk[13]*((rk[13][0]*Vpk[3][18][2])-(rk[13][2]*Vpk[3][18][0])
          ))+((ik[13][0][1]*c18)+(ik[13][2][1]*s18)))+((mk[14]*((Vpk[3][19][2]*
          Vpk[18][19][2])+((Vpk[3][19][0]*Vpk[18][19][0])+(Vpk[3][19][1]*
          Vpk[18][19][1]))))+((IkWpk[18][19][2]*Wpk[3][19][2])+((
          IkWpk[18][19][0]*c18)+(IkWpk[18][19][1]*Wpk[3][19][1])))));
        temp[1] = (((mk[15]*((Vpk[3][20][2]*Vpk[18][20][2])+((Vpk[3][20][0]*
          Vpk[18][20][0])+(Vpk[3][20][1]*Vpk[18][20][1]))))+((IkWpk[18][20][2]*
          Wpk[3][20][2])+((IkWpk[18][20][0]*Wpk[3][20][0])+(IkWpk[18][20][1]*
          Wpk[3][19][1]))))+temp[0]);
        mm[3][18] = (((mk[16]*((Vpk[3][21][2]*Vpk[18][21][2])+((Vpk[3][21][0]*
          Vpk[18][21][0])+(Vpk[3][21][1]*Vpk[18][21][1]))))+((IkWpk[18][21][2]*
          Wpk[3][20][2])+((IkWpk[18][21][0]*Wpk[3][21][0])+(IkWpk[18][21][1]*
          Wpk[3][21][1]))))+temp[1]);
        temp[0] = (((mk[14]*((rk[14][2]*Vpk[3][19][1])-(rk[14][1]*Vpk[3][19][2])
          ))+((ik[14][2][0]*Wpk[3][19][2])+((ik[14][0][0]*c18)+(ik[14][1][0]*
          Wpk[3][19][1]))))+((mk[15]*((Vpk[3][20][2]*Vpk[19][20][2])+((
          Vpk[3][20][0]*Vpk[19][20][0])+(Vpk[3][20][1]*Vpk[19][20][1]))))+((
          IkWpk[19][20][2]*Wpk[3][20][2])+((IkWpk[19][20][0]*Wpk[3][20][0])+(
          IkWpk[19][20][1]*Wpk[3][19][1])))));
        mm[3][19] = (((mk[16]*((Vpk[3][21][2]*Vpk[19][21][2])+((Vpk[3][21][0]*
          Vpk[19][21][0])+(Vpk[3][21][1]*Vpk[19][21][1]))))+((IkWpk[19][21][2]*
          Wpk[3][20][2])+((IkWpk[19][21][0]*Wpk[3][21][0])+(IkWpk[19][21][1]*
          Wpk[3][21][1]))))+temp[0]);
        mm[3][20] = (((mk[15]*((rk[15][0]*Vpk[3][20][2])-(rk[15][2]*
          Vpk[3][20][0])))+((ik[15][2][1]*Wpk[3][20][2])+((ik[15][0][1]*
          Wpk[3][20][0])+(ik[15][1][1]*Wpk[3][19][1]))))+((mk[16]*((
          Vpk[3][21][2]*Vpk[20][21][2])+((Vpk[3][21][0]*Vpk[20][21][0])+(
          Vpk[3][21][1]*Vpk[20][21][1]))))+((IkWpk[20][21][2]*Wpk[3][20][2])+((
          IkWpk[20][21][0]*Wpk[3][21][0])+(IkWpk[20][21][1]*Wpk[3][21][1])))));
        mm[3][21] = ((mk[16]*((rk[16][1]*Vpk[3][21][0])-(rk[16][0]*Vpk[3][21][1]
          )))+((ik[16][2][2]*Wpk[3][20][2])+((ik[16][0][2]*Wpk[3][21][0])+(
          ik[16][1][2]*Wpk[3][21][1]))));
        temp[0] = (((mk[17]*((rk[17][0]*Vpk[3][22][2])-(rk[17][2]*Vpk[3][22][0])
          ))+((ik[17][0][1]*c22)+(ik[17][2][1]*s22)))+((mk[18]*((Vpk[3][23][2]*
          Vpk[22][23][2])+((Vpk[3][23][0]*Vpk[22][23][0])+(Vpk[3][23][1]*
          Vpk[22][23][1]))))+((IkWpk[22][23][2]*Wpk[3][23][2])+((
          IkWpk[22][23][0]*c22)+(IkWpk[22][23][1]*Wpk[3][23][1])))));
        temp[1] = (((mk[19]*((Vpk[3][24][2]*Vpk[22][24][2])+((Vpk[3][24][0]*
          Vpk[22][24][0])+(Vpk[3][24][1]*Vpk[22][24][1]))))+((IkWpk[22][24][2]*
          Wpk[3][24][2])+((IkWpk[22][24][0]*Wpk[3][24][0])+(IkWpk[22][24][1]*
          Wpk[3][23][1]))))+temp[0]);
        mm[3][22] = (((mk[20]*((Vpk[3][25][2]*Vpk[22][25][2])+((Vpk[3][25][0]*
          Vpk[22][25][0])+(Vpk[3][25][1]*Vpk[22][25][1]))))+((IkWpk[22][25][2]*
          Wpk[3][24][2])+((IkWpk[22][25][0]*Wpk[3][25][0])+(IkWpk[22][25][1]*
          Wpk[3][25][1]))))+temp[1]);
        temp[0] = (((mk[18]*((rk[18][2]*Vpk[3][23][1])-(rk[18][1]*Vpk[3][23][2])
          ))+((ik[18][2][0]*Wpk[3][23][2])+((ik[18][0][0]*c22)+(ik[18][1][0]*
          Wpk[3][23][1]))))+((mk[19]*((Vpk[3][24][2]*Vpk[23][24][2])+((
          Vpk[3][24][0]*Vpk[23][24][0])+(Vpk[3][24][1]*Vpk[23][24][1]))))+((
          IkWpk[23][24][2]*Wpk[3][24][2])+((IkWpk[23][24][0]*Wpk[3][24][0])+(
          IkWpk[23][24][1]*Wpk[3][23][1])))));
        mm[3][23] = (((mk[20]*((Vpk[3][25][2]*Vpk[23][25][2])+((Vpk[3][25][0]*
          Vpk[23][25][0])+(Vpk[3][25][1]*Vpk[23][25][1]))))+((IkWpk[23][25][2]*
          Wpk[3][24][2])+((IkWpk[23][25][0]*Wpk[3][25][0])+(IkWpk[23][25][1]*
          Wpk[3][25][1]))))+temp[0]);
        mm[3][24] = (((mk[19]*((rk[19][0]*Vpk[3][24][2])-(rk[19][2]*
          Vpk[3][24][0])))+((ik[19][2][1]*Wpk[3][24][2])+((ik[19][0][1]*
          Wpk[3][24][0])+(ik[19][1][1]*Wpk[3][23][1]))))+((mk[20]*((
          Vpk[3][25][2]*Vpk[24][25][2])+((Vpk[3][25][0]*Vpk[24][25][0])+(
          Vpk[3][25][1]*Vpk[24][25][1]))))+((IkWpk[24][25][2]*Wpk[3][24][2])+((
          IkWpk[24][25][0]*Wpk[3][25][0])+(IkWpk[24][25][1]*Wpk[3][25][1])))));
        mm[3][25] = ((mk[20]*((rk[20][1]*Vpk[3][25][0])-(rk[20][0]*Vpk[3][25][1]
          )))+((ik[20][2][2]*Wpk[3][24][2])+((ik[20][0][2]*Wpk[3][25][0])+(
          ik[20][1][2]*Wpk[3][25][1]))));
        temp[0] = ((ik[0][1][1]+(mk[0]*((rk[0][0]*rk[0][0])+(rk[0][2]*rk[0][2]))
          ))+((mk[1]*((Vpk[4][6][2]*Vpk[4][6][2])+((Vpk[4][6][0]*Vpk[4][6][0])+(
          Vpk[4][6][1]*Vpk[4][6][1]))))+((IkWpk[4][6][0]*s6)+(IkWpk[4][6][1]*c6)
          )));
        temp[1] = (((mk[3]*((Vpk[4][8][2]*Vpk[4][8][2])+((Vpk[4][8][0]*
          Vpk[4][8][0])+(Vpk[4][8][1]*Vpk[4][8][1]))))+((IkWpk[4][8][2]*
          Wpk[4][8][2])+((IkWpk[4][8][0]*Wpk[4][7][0])+(IkWpk[4][8][1]*
          Wpk[4][8][1]))))+(temp[0]+((mk[2]*((Vpk[4][7][2]*Vpk[4][7][2])+((
          Vpk[4][7][0]*Vpk[4][7][0])+(Vpk[4][7][1]*Vpk[4][7][1]))))+((
          IkWpk[4][7][2]*Wpk[4][7][2])+((IkWpk[4][7][0]*Wpk[4][7][0])+(
          IkWpk[4][7][1]*c6))))));
        temp[2] = (((mk[4]*((Vpk[4][9][2]*Vpk[4][9][2])+((Vpk[4][9][0]*
          Vpk[4][9][0])+(Vpk[4][9][1]*Vpk[4][9][1]))))+((IkWpk[4][9][2]*
          Wpk[4][9][2])+((IkWpk[4][9][0]*Wpk[4][9][0])+(IkWpk[4][9][1]*
          Wpk[4][8][1]))))+temp[1]);
        temp[3] = (((mk[5]*((Vpk[4][10][2]*Vpk[4][10][2])+((Vpk[4][10][0]*
          Vpk[4][10][0])+(Vpk[4][10][1]*Vpk[4][10][1]))))+((IkWpk[4][10][2]*
          Wpk[4][10][2])+((IkWpk[4][10][0]*Wpk[4][10][0])+(IkWpk[4][10][1]*
          Wpk[4][8][1]))))+temp[2]);
        temp[4] = (((mk[7]*((Vpk[4][12][2]*Vpk[4][12][2])+((Vpk[4][12][0]*
          Vpk[4][12][0])+(Vpk[4][12][1]*Vpk[4][12][1]))))+((IkWpk[4][12][0]*s12)
          +(IkWpk[4][12][1]*c12)))+(((mk[6]*((Vpk[4][11][2]*Vpk[4][11][2])+((
          Vpk[4][11][0]*Vpk[4][11][0])+(Vpk[4][11][1]*Vpk[4][11][1]))))+((
          IkWpk[4][11][2]*Wpk[4][11][2])+((IkWpk[4][11][0]*Wpk[4][10][0])+(
          IkWpk[4][11][1]*Wpk[4][11][1]))))+temp[3]));
        temp[5] = (((mk[9]*((Vpk[4][14][2]*Vpk[4][14][2])+((Vpk[4][14][0]*
          Vpk[4][14][0])+(Vpk[4][14][1]*Vpk[4][14][1]))))+((IkWpk[4][14][2]*
          Wpk[4][14][2])+((IkWpk[4][14][0]*Wpk[4][13][0])+(IkWpk[4][14][1]*
          Wpk[4][14][1]))))+(((mk[8]*((Vpk[4][13][2]*Vpk[4][13][2])+((
          Vpk[4][13][0]*Vpk[4][13][0])+(Vpk[4][13][1]*Vpk[4][13][1]))))+((
          IkWpk[4][13][2]*Wpk[4][13][2])+((IkWpk[4][13][0]*Wpk[4][13][0])+(
          IkWpk[4][13][1]*c12))))+temp[4]));
        temp[6] = (((mk[10]*((Vpk[4][15][2]*Vpk[4][15][2])+((Vpk[4][15][0]*
          Vpk[4][15][0])+(Vpk[4][15][1]*Vpk[4][15][1]))))+((IkWpk[4][15][2]*
          Wpk[4][15][2])+((IkWpk[4][15][0]*Wpk[4][15][0])+(IkWpk[4][15][1]*
          Wpk[4][14][1]))))+temp[5]);
        temp[7] = (((mk[11]*((Vpk[4][16][2]*Vpk[4][16][2])+((Vpk[4][16][0]*
          Vpk[4][16][0])+(Vpk[4][16][1]*Vpk[4][16][1]))))+((IkWpk[4][16][2]*
          Wpk[4][16][2])+((IkWpk[4][16][0]*Wpk[4][16][0])+(IkWpk[4][16][1]*
          Wpk[4][14][1]))))+temp[6]);
        temp[8] = ((ik[13][1][1]+(mk[13]*((Vpk[4][18][0]*Vpk[4][18][0])+(
          Vpk[4][18][2]*Vpk[4][18][2]))))+(((mk[12]*((Vpk[4][17][2]*
          Vpk[4][17][2])+((Vpk[4][17][0]*Vpk[4][17][0])+(Vpk[4][17][1]*
          Vpk[4][17][1]))))+((IkWpk[4][17][2]*Wpk[4][17][2])+((IkWpk[4][17][0]*
          Wpk[4][16][0])+(IkWpk[4][17][1]*Wpk[4][17][1]))))+temp[7]));
        temp[9] = (((mk[15]*((Vpk[4][20][2]*Vpk[4][20][2])+((Vpk[4][20][0]*
          Vpk[4][20][0])+(Vpk[4][20][1]*Vpk[4][20][1]))))+((IkWpk[4][20][2]*
          Wpk[4][20][2])+((IkWpk[4][20][0]*Wpk[4][20][0])+(IkWpk[4][20][1]*c19))
          ))+(temp[8]+((mk[14]*((Vpk[4][19][2]*Vpk[4][19][2])+((Vpk[4][19][0]*
          Vpk[4][19][0])+(Vpk[4][19][1]*Vpk[4][19][1]))))+((IkWpk[4][19][1]*c19)
          -(IkWpk[4][19][2]*s19)))));
        temp[10] = ((ik[17][1][1]+(mk[17]*((Vpk[4][22][0]*Vpk[4][22][0])+(
          Vpk[4][22][2]*Vpk[4][22][2]))))+(((mk[16]*((Vpk[4][21][2]*
          Vpk[4][21][2])+((Vpk[4][21][0]*Vpk[4][21][0])+(Vpk[4][21][1]*
          Vpk[4][21][1]))))+((IkWpk[4][21][2]*Wpk[4][20][2])+((IkWpk[4][21][0]*
          Wpk[4][21][0])+(IkWpk[4][21][1]*Wpk[4][21][1]))))+temp[9]));
        temp[11] = (((mk[19]*((Vpk[4][24][2]*Vpk[4][24][2])+((Vpk[4][24][0]*
          Vpk[4][24][0])+(Vpk[4][24][1]*Vpk[4][24][1]))))+((IkWpk[4][24][2]*
          Wpk[4][24][2])+((IkWpk[4][24][0]*Wpk[4][24][0])+(IkWpk[4][24][1]*c23))
          ))+(temp[10]+((mk[18]*((Vpk[4][23][2]*Vpk[4][23][2])+((Vpk[4][23][0]*
          Vpk[4][23][0])+(Vpk[4][23][1]*Vpk[4][23][1]))))+((IkWpk[4][23][1]*c23)
          -(IkWpk[4][23][2]*s23)))));
        mm[4][4] = (((mk[20]*((Vpk[4][25][2]*Vpk[4][25][2])+((Vpk[4][25][0]*
          Vpk[4][25][0])+(Vpk[4][25][1]*Vpk[4][25][1]))))+((IkWpk[4][25][2]*
          Wpk[4][24][2])+((IkWpk[4][25][0]*Wpk[4][25][0])+(IkWpk[4][25][1]*
          Wpk[4][25][1]))))+temp[11]);
        temp[0] = (((ik[0][1][2]-(mk[0]*(rk[0][1]*rk[0][2])))+((mk[1]*((
          Vpk[4][6][0]*Vpk[5][6][0])+(Vpk[4][6][1]*Vpk[5][6][1])))+((ik[1][0][2]
          *s6)+(ik[1][1][2]*c6))))+((mk[2]*((Vpk[4][7][2]*Vpk[5][7][2])+((
          Vpk[4][7][0]*Vpk[5][7][0])+(Vpk[4][7][1]*Vpk[5][7][1]))))+((
          IkWpk[5][7][2]*Wpk[4][7][2])+((IkWpk[5][7][0]*Wpk[4][7][0])+(
          IkWpk[5][7][1]*c6)))));
        temp[1] = (((mk[3]*((Vpk[4][8][2]*Vpk[5][8][2])+((Vpk[4][8][0]*
          Vpk[5][8][0])+(Vpk[4][8][1]*Vpk[5][8][1]))))+((IkWpk[5][8][2]*
          Wpk[4][8][2])+((IkWpk[5][8][0]*Wpk[4][7][0])+(IkWpk[5][8][1]*
          Wpk[4][8][1]))))+temp[0]);
        temp[2] = (((mk[4]*((Vpk[4][9][2]*Vpk[5][9][2])+((Vpk[4][9][0]*
          Vpk[5][9][0])+(Vpk[4][9][1]*Vpk[5][9][1]))))+((IkWpk[5][9][2]*
          Wpk[4][9][2])+((IkWpk[5][9][0]*Wpk[4][9][0])+(IkWpk[5][9][1]*
          Wpk[4][8][1]))))+temp[1]);
        temp[3] = (((mk[5]*((Vpk[4][10][2]*Vpk[5][10][2])+((Vpk[4][10][0]*
          Vpk[5][10][0])+(Vpk[4][10][1]*Vpk[5][10][1]))))+((IkWpk[5][10][2]*
          Wpk[4][10][2])+((IkWpk[5][10][0]*Wpk[4][10][0])+(IkWpk[5][10][1]*
          Wpk[4][8][1]))))+temp[2]);
        temp[4] = (((mk[7]*((Vpk[4][12][0]*Vpk[5][12][0])+(Vpk[4][12][1]*
          Vpk[5][12][1])))+((ik[7][0][2]*s12)+(ik[7][1][2]*c12)))+(((mk[6]*((
          Vpk[4][11][2]*Vpk[5][11][2])+((Vpk[4][11][0]*Vpk[5][11][0])+(
          Vpk[4][11][1]*Vpk[5][11][1]))))+((IkWpk[5][11][2]*Wpk[4][11][2])+((
          IkWpk[5][11][0]*Wpk[4][10][0])+(IkWpk[5][11][1]*Wpk[4][11][1]))))+
          temp[3]));
        temp[5] = (((mk[9]*((Vpk[4][14][2]*Vpk[5][14][2])+((Vpk[4][14][0]*
          Vpk[5][14][0])+(Vpk[4][14][1]*Vpk[5][14][1]))))+((IkWpk[5][14][2]*
          Wpk[4][14][2])+((IkWpk[5][14][0]*Wpk[4][13][0])+(IkWpk[5][14][1]*
          Wpk[4][14][1]))))+(((mk[8]*((Vpk[4][13][2]*Vpk[5][13][2])+((
          Vpk[4][13][0]*Vpk[5][13][0])+(Vpk[4][13][1]*Vpk[5][13][1]))))+((
          IkWpk[5][13][2]*Wpk[4][13][2])+((IkWpk[5][13][0]*Wpk[4][13][0])+(
          IkWpk[5][13][1]*c12))))+temp[4]));
        temp[6] = (((mk[10]*((Vpk[4][15][2]*Vpk[5][15][2])+((Vpk[4][15][0]*
          Vpk[5][15][0])+(Vpk[4][15][1]*Vpk[5][15][1]))))+((IkWpk[5][15][2]*
          Wpk[4][15][2])+((IkWpk[5][15][0]*Wpk[4][15][0])+(IkWpk[5][15][1]*
          Wpk[4][14][1]))))+temp[5]);
        temp[7] = (((mk[11]*((Vpk[4][16][2]*Vpk[5][16][2])+((Vpk[4][16][0]*
          Vpk[5][16][0])+(Vpk[4][16][1]*Vpk[5][16][1]))))+((IkWpk[5][16][2]*
          Wpk[4][16][2])+((IkWpk[5][16][0]*Wpk[4][16][0])+(IkWpk[5][16][1]*
          Wpk[4][14][1]))))+temp[6]);
        temp[8] = ((IkWpk[5][18][1]+(mk[13]*((Vpk[4][18][0]*Vpk[5][18][0])+(
          Vpk[4][18][2]*Vpk[5][18][2]))))+(((mk[12]*((Vpk[4][17][2]*
          Vpk[5][17][2])+((Vpk[4][17][0]*Vpk[5][17][0])+(Vpk[4][17][1]*
          Vpk[5][17][1]))))+((IkWpk[5][17][2]*Wpk[4][17][2])+((IkWpk[5][17][0]*
          Wpk[4][16][0])+(IkWpk[5][17][1]*Wpk[4][17][1]))))+temp[7]));
        temp[9] = (((mk[15]*((Vpk[4][20][2]*Vpk[5][20][2])+((Vpk[4][20][0]*
          Vpk[5][20][0])+(Vpk[4][20][1]*Vpk[5][20][1]))))+((IkWpk[5][20][2]*
          Wpk[4][20][2])+((IkWpk[5][20][0]*Wpk[4][20][0])+(IkWpk[5][20][1]*c19))
          ))+(temp[8]+((mk[14]*((Vpk[4][19][2]*Vpk[5][19][2])+((Vpk[4][19][0]*
          Vpk[5][19][0])+(Vpk[4][19][1]*Vpk[5][19][1]))))+((IkWpk[5][19][1]*c19)
          -(IkWpk[5][19][2]*s19)))));
        temp[10] = ((IkWpk[5][22][1]+(mk[17]*((Vpk[4][22][0]*Vpk[5][22][0])+(
          Vpk[4][22][2]*Vpk[5][22][2]))))+(((mk[16]*((Vpk[4][21][2]*
          Vpk[5][21][2])+((Vpk[4][21][0]*Vpk[5][21][0])+(Vpk[4][21][1]*
          Vpk[5][21][1]))))+((IkWpk[5][21][2]*Wpk[4][20][2])+((IkWpk[5][21][0]*
          Wpk[4][21][0])+(IkWpk[5][21][1]*Wpk[4][21][1]))))+temp[9]));
        temp[11] = (((mk[19]*((Vpk[4][24][2]*Vpk[5][24][2])+((Vpk[4][24][0]*
          Vpk[5][24][0])+(Vpk[4][24][1]*Vpk[5][24][1]))))+((IkWpk[5][24][2]*
          Wpk[4][24][2])+((IkWpk[5][24][0]*Wpk[4][24][0])+(IkWpk[5][24][1]*c23))
          ))+(temp[10]+((mk[18]*((Vpk[4][23][2]*Vpk[5][23][2])+((Vpk[4][23][0]*
          Vpk[5][23][0])+(Vpk[4][23][1]*Vpk[5][23][1]))))+((IkWpk[5][23][1]*c23)
          -(IkWpk[5][23][2]*s23)))));
        mm[4][5] = (((mk[20]*((Vpk[4][25][2]*Vpk[5][25][2])+((Vpk[4][25][0]*
          Vpk[5][25][0])+(Vpk[4][25][1]*Vpk[5][25][1]))))+((IkWpk[5][25][2]*
          Wpk[4][24][2])+((IkWpk[5][25][0]*Wpk[4][25][0])+(IkWpk[5][25][1]*
          Wpk[4][25][1]))))+temp[11]);
        temp[0] = (((mk[1]*((rk[1][1]*Vpk[4][6][0])-(rk[1][0]*Vpk[4][6][1])))+((
          ik[1][0][2]*s6)+(ik[1][1][2]*c6)))+((mk[2]*((Vpk[4][7][2]*Vpk[6][7][2]
          )+((Vpk[4][7][0]*Vpk[6][7][0])+(Vpk[4][7][1]*Vpk[6][7][1]))))+((
          IkWpk[6][7][2]*Wpk[4][7][2])+((IkWpk[6][7][0]*Wpk[4][7][0])+(
          IkWpk[6][7][1]*c6)))));
        temp[1] = (((mk[3]*((Vpk[4][8][2]*Vpk[6][8][2])+((Vpk[4][8][0]*
          Vpk[6][8][0])+(Vpk[4][8][1]*Vpk[6][8][1]))))+((IkWpk[6][8][2]*
          Wpk[4][8][2])+((IkWpk[6][8][0]*Wpk[4][7][0])+(IkWpk[6][8][1]*
          Wpk[4][8][1]))))+temp[0]);
        temp[2] = (((mk[4]*((Vpk[4][9][2]*Vpk[6][9][2])+((Vpk[4][9][0]*
          Vpk[6][9][0])+(Vpk[4][9][1]*Vpk[6][9][1]))))+((IkWpk[6][9][2]*
          Wpk[4][9][2])+((IkWpk[6][9][0]*Wpk[4][9][0])+(IkWpk[6][9][1]*
          Wpk[4][8][1]))))+temp[1]);
        temp[3] = (((mk[5]*((Vpk[4][10][2]*Vpk[6][10][2])+((Vpk[4][10][0]*
          Vpk[6][10][0])+(Vpk[4][10][1]*Vpk[6][10][1]))))+((IkWpk[6][10][2]*
          Wpk[4][10][2])+((IkWpk[6][10][0]*Wpk[4][10][0])+(IkWpk[6][10][1]*
          Wpk[4][8][1]))))+temp[2]);
        mm[4][6] = (((mk[6]*((Vpk[4][11][2]*Vpk[6][11][2])+((Vpk[4][11][0]*
          Vpk[6][11][0])+(Vpk[4][11][1]*Vpk[6][11][1]))))+((IkWpk[6][11][2]*
          Wpk[4][11][2])+((IkWpk[6][11][0]*Wpk[4][10][0])+(IkWpk[6][11][1]*
          Wpk[4][11][1]))))+temp[3]);
        temp[0] = (((mk[2]*((rk[2][0]*Vpk[4][7][2])-(rk[2][2]*Vpk[4][7][0])))+((
          ik[2][2][1]*Wpk[4][7][2])+((ik[2][0][1]*Wpk[4][7][0])+(ik[2][1][1]*c6)
          )))+((mk[3]*((Vpk[4][8][2]*Vpk[7][8][2])+((Vpk[4][8][0]*Vpk[7][8][0])+
          (Vpk[4][8][1]*Vpk[7][8][1]))))+((IkWpk[7][8][2]*Wpk[4][8][2])+((
          IkWpk[7][8][0]*Wpk[4][7][0])+(IkWpk[7][8][1]*Wpk[4][8][1])))));
        temp[1] = (((mk[4]*((Vpk[4][9][2]*Vpk[7][9][2])+((Vpk[4][9][0]*
          Vpk[7][9][0])+(Vpk[4][9][1]*Vpk[7][9][1]))))+((IkWpk[7][9][2]*
          Wpk[4][9][2])+((IkWpk[7][9][0]*Wpk[4][9][0])+(IkWpk[7][9][1]*
          Wpk[4][8][1]))))+temp[0]);
        temp[2] = (((mk[5]*((Vpk[4][10][2]*Vpk[7][10][2])+((Vpk[4][10][0]*
          Vpk[7][10][0])+(Vpk[4][10][1]*Vpk[7][10][1]))))+((IkWpk[7][10][2]*
          Wpk[4][10][2])+((IkWpk[7][10][0]*Wpk[4][10][0])+(IkWpk[7][10][1]*
          Wpk[4][8][1]))))+temp[1]);
        mm[4][7] = (((mk[6]*((Vpk[4][11][2]*Vpk[7][11][2])+((Vpk[4][11][0]*
          Vpk[7][11][0])+(Vpk[4][11][1]*Vpk[7][11][1]))))+((IkWpk[7][11][2]*
          Wpk[4][11][2])+((IkWpk[7][11][0]*Wpk[4][10][0])+(IkWpk[7][11][1]*
          Wpk[4][11][1]))))+temp[2]);
        temp[0] = (((mk[3]*((rk[3][2]*Vpk[4][8][1])-(rk[3][1]*Vpk[4][8][2])))+((
          ik[3][2][0]*Wpk[4][8][2])+((ik[3][0][0]*Wpk[4][7][0])+(ik[3][1][0]*
          Wpk[4][8][1]))))+((mk[4]*((Vpk[4][9][2]*Vpk[8][9][2])+((Vpk[4][9][0]*
          Vpk[8][9][0])+(Vpk[4][9][1]*Vpk[8][9][1]))))+((IkWpk[8][9][2]*
          Wpk[4][9][2])+((IkWpk[8][9][0]*Wpk[4][9][0])+(IkWpk[8][9][1]*
          Wpk[4][8][1])))));
        temp[1] = (((mk[5]*((Vpk[4][10][2]*Vpk[8][10][2])+((Vpk[4][10][0]*
          Vpk[8][10][0])+(Vpk[4][10][1]*Vpk[8][10][1]))))+((IkWpk[8][10][2]*
          Wpk[4][10][2])+((IkWpk[8][10][0]*Wpk[4][10][0])+(IkWpk[8][10][1]*
          Wpk[4][8][1]))))+temp[0]);
        mm[4][8] = (((mk[6]*((Vpk[4][11][2]*Vpk[8][11][2])+((Vpk[4][11][0]*
          Vpk[8][11][0])+(Vpk[4][11][1]*Vpk[8][11][1]))))+((IkWpk[8][11][2]*
          Wpk[4][11][2])+((IkWpk[8][11][0]*Wpk[4][10][0])+(IkWpk[8][11][1]*
          Wpk[4][11][1]))))+temp[1]);
        temp[0] = (((mk[4]*((rk[4][0]*Vpk[4][9][2])-(rk[4][2]*Vpk[4][9][0])))+((
          ik[4][2][1]*Wpk[4][9][2])+((ik[4][0][1]*Wpk[4][9][0])+(ik[4][1][1]*
          Wpk[4][8][1]))))+((mk[5]*((Vpk[4][10][0]*Vpk[9][10][0])+(Vpk[4][10][2]
          *Vpk[9][10][2])))+((ik[5][2][1]*Wpk[4][10][2])+((ik[5][0][1]*
          Wpk[4][10][0])+(ik[5][1][1]*Wpk[4][8][1])))));
        mm[4][9] = (((mk[6]*((Vpk[4][11][2]*Vpk[9][11][2])+((Vpk[4][11][0]*
          Vpk[9][11][0])+(Vpk[4][11][1]*Vpk[9][11][1]))))+((IkWpk[9][11][2]*
          Wpk[4][11][2])+((IkWpk[9][11][0]*Wpk[4][10][0])+(IkWpk[9][11][1]*
          Wpk[4][11][1]))))+temp[0]);
        mm[4][10] = (((mk[5]*((rk[5][0]*Vpk[4][10][2])-(rk[5][2]*Vpk[4][10][0]))
          )+((ik[5][2][1]*Wpk[4][10][2])+((ik[5][0][1]*Wpk[4][10][0])+(
          ik[5][1][1]*Wpk[4][8][1]))))+((mk[6]*((Vpk[4][11][2]*Vpk[10][11][2])+(
          (Vpk[4][11][0]*Vpk[10][11][0])+(Vpk[4][11][1]*Vpk[10][11][1]))))+((
          IkWpk[10][11][2]*Wpk[4][11][2])+((IkWpk[10][11][0]*Wpk[4][10][0])+(
          IkWpk[10][11][1]*Wpk[4][11][1])))));
        mm[4][11] = ((mk[6]*((rk[6][2]*Vpk[4][11][1])-(rk[6][1]*Vpk[4][11][2])))
          +((ik[6][2][0]*Wpk[4][11][2])+((ik[6][0][0]*Wpk[4][10][0])+(
          ik[6][1][0]*Wpk[4][11][1]))));
        temp[0] = (((mk[7]*((rk[7][1]*Vpk[4][12][0])-(rk[7][0]*Vpk[4][12][1])))+
          ((ik[7][0][2]*s12)+(ik[7][1][2]*c12)))+((mk[8]*((Vpk[4][13][2]*
          Vpk[12][13][2])+((Vpk[4][13][0]*Vpk[12][13][0])+(Vpk[4][13][1]*
          Vpk[12][13][1]))))+((IkWpk[12][13][2]*Wpk[4][13][2])+((
          IkWpk[12][13][0]*Wpk[4][13][0])+(IkWpk[12][13][1]*c12)))));
        temp[1] = (((mk[9]*((Vpk[4][14][2]*Vpk[12][14][2])+((Vpk[4][14][0]*
          Vpk[12][14][0])+(Vpk[4][14][1]*Vpk[12][14][1]))))+((IkWpk[12][14][2]*
          Wpk[4][14][2])+((IkWpk[12][14][0]*Wpk[4][13][0])+(IkWpk[12][14][1]*
          Wpk[4][14][1]))))+temp[0]);
        temp[2] = (((mk[10]*((Vpk[4][15][2]*Vpk[12][15][2])+((Vpk[4][15][0]*
          Vpk[12][15][0])+(Vpk[4][15][1]*Vpk[12][15][1]))))+((IkWpk[12][15][2]*
          Wpk[4][15][2])+((IkWpk[12][15][0]*Wpk[4][15][0])+(IkWpk[12][15][1]*
          Wpk[4][14][1]))))+temp[1]);
        temp[3] = (((mk[11]*((Vpk[4][16][2]*Vpk[12][16][2])+((Vpk[4][16][0]*
          Vpk[12][16][0])+(Vpk[4][16][1]*Vpk[12][16][1]))))+((IkWpk[12][16][2]*
          Wpk[4][16][2])+((IkWpk[12][16][0]*Wpk[4][16][0])+(IkWpk[12][16][1]*
          Wpk[4][14][1]))))+temp[2]);
        mm[4][12] = (((mk[12]*((Vpk[4][17][2]*Vpk[12][17][2])+((Vpk[4][17][0]*
          Vpk[12][17][0])+(Vpk[4][17][1]*Vpk[12][17][1]))))+((IkWpk[12][17][2]*
          Wpk[4][17][2])+((IkWpk[12][17][0]*Wpk[4][16][0])+(IkWpk[12][17][1]*
          Wpk[4][17][1]))))+temp[3]);
        temp[0] = (((mk[8]*((rk[8][0]*Vpk[4][13][2])-(rk[8][2]*Vpk[4][13][0])))+
          ((ik[8][2][1]*Wpk[4][13][2])+((ik[8][0][1]*Wpk[4][13][0])+(ik[8][1][1]
          *c12))))+((mk[9]*((Vpk[4][14][2]*Vpk[13][14][2])+((Vpk[4][14][0]*
          Vpk[13][14][0])+(Vpk[4][14][1]*Vpk[13][14][1]))))+((IkWpk[13][14][2]*
          Wpk[4][14][2])+((IkWpk[13][14][0]*Wpk[4][13][0])+(IkWpk[13][14][1]*
          Wpk[4][14][1])))));
        temp[1] = (((mk[10]*((Vpk[4][15][2]*Vpk[13][15][2])+((Vpk[4][15][0]*
          Vpk[13][15][0])+(Vpk[4][15][1]*Vpk[13][15][1]))))+((IkWpk[13][15][2]*
          Wpk[4][15][2])+((IkWpk[13][15][0]*Wpk[4][15][0])+(IkWpk[13][15][1]*
          Wpk[4][14][1]))))+temp[0]);
        temp[2] = (((mk[11]*((Vpk[4][16][2]*Vpk[13][16][2])+((Vpk[4][16][0]*
          Vpk[13][16][0])+(Vpk[4][16][1]*Vpk[13][16][1]))))+((IkWpk[13][16][2]*
          Wpk[4][16][2])+((IkWpk[13][16][0]*Wpk[4][16][0])+(IkWpk[13][16][1]*
          Wpk[4][14][1]))))+temp[1]);
        mm[4][13] = (((mk[12]*((Vpk[4][17][2]*Vpk[13][17][2])+((Vpk[4][17][0]*
          Vpk[13][17][0])+(Vpk[4][17][1]*Vpk[13][17][1]))))+((IkWpk[13][17][2]*
          Wpk[4][17][2])+((IkWpk[13][17][0]*Wpk[4][16][0])+(IkWpk[13][17][1]*
          Wpk[4][17][1]))))+temp[2]);
        temp[0] = (((mk[9]*((rk[9][2]*Vpk[4][14][1])-(rk[9][1]*Vpk[4][14][2])))+
          ((ik[9][2][0]*Wpk[4][14][2])+((ik[9][0][0]*Wpk[4][13][0])+(ik[9][1][0]
          *Wpk[4][14][1]))))+((mk[10]*((Vpk[4][15][2]*Vpk[14][15][2])+((
          Vpk[4][15][0]*Vpk[14][15][0])+(Vpk[4][15][1]*Vpk[14][15][1]))))+((
          IkWpk[14][15][2]*Wpk[4][15][2])+((IkWpk[14][15][0]*Wpk[4][15][0])+(
          IkWpk[14][15][1]*Wpk[4][14][1])))));
        temp[1] = (((mk[11]*((Vpk[4][16][2]*Vpk[14][16][2])+((Vpk[4][16][0]*
          Vpk[14][16][0])+(Vpk[4][16][1]*Vpk[14][16][1]))))+((IkWpk[14][16][2]*
          Wpk[4][16][2])+((IkWpk[14][16][0]*Wpk[4][16][0])+(IkWpk[14][16][1]*
          Wpk[4][14][1]))))+temp[0]);
        mm[4][14] = (((mk[12]*((Vpk[4][17][2]*Vpk[14][17][2])+((Vpk[4][17][0]*
          Vpk[14][17][0])+(Vpk[4][17][1]*Vpk[14][17][1]))))+((IkWpk[14][17][2]*
          Wpk[4][17][2])+((IkWpk[14][17][0]*Wpk[4][16][0])+(IkWpk[14][17][1]*
          Wpk[4][17][1]))))+temp[1]);
        temp[0] = (((mk[10]*((rk[10][0]*Vpk[4][15][2])-(rk[10][2]*Vpk[4][15][0])
          ))+((ik[10][2][1]*Wpk[4][15][2])+((ik[10][0][1]*Wpk[4][15][0])+(
          ik[10][1][1]*Wpk[4][14][1]))))+((mk[11]*((Vpk[4][16][0]*Vpk[15][16][0]
          )+(Vpk[4][16][2]*Vpk[15][16][2])))+((ik[11][2][1]*Wpk[4][16][2])+((
          ik[11][0][1]*Wpk[4][16][0])+(ik[11][1][1]*Wpk[4][14][1])))));
        mm[4][15] = (((mk[12]*((Vpk[4][17][2]*Vpk[15][17][2])+((Vpk[4][17][0]*
          Vpk[15][17][0])+(Vpk[4][17][1]*Vpk[15][17][1]))))+((IkWpk[15][17][2]*
          Wpk[4][17][2])+((IkWpk[15][17][0]*Wpk[4][16][0])+(IkWpk[15][17][1]*
          Wpk[4][17][1]))))+temp[0]);
        mm[4][16] = (((mk[11]*((rk[11][0]*Vpk[4][16][2])-(rk[11][2]*
          Vpk[4][16][0])))+((ik[11][2][1]*Wpk[4][16][2])+((ik[11][0][1]*
          Wpk[4][16][0])+(ik[11][1][1]*Wpk[4][14][1]))))+((mk[12]*((
          Vpk[4][17][2]*Vpk[16][17][2])+((Vpk[4][17][0]*Vpk[16][17][0])+(
          Vpk[4][17][1]*Vpk[16][17][1]))))+((IkWpk[16][17][2]*Wpk[4][17][2])+((
          IkWpk[16][17][0]*Wpk[4][16][0])+(IkWpk[16][17][1]*Wpk[4][17][1])))));
        mm[4][17] = ((mk[12]*((rk[12][2]*Vpk[4][17][1])-(rk[12][1]*Vpk[4][17][2]
          )))+((ik[12][2][0]*Wpk[4][17][2])+((ik[12][0][0]*Wpk[4][16][0])+(
          ik[12][1][0]*Wpk[4][17][1]))));
        temp[0] = ((ik[13][1][1]+(mk[13]*((rk[13][0]*Vpk[4][18][2])-(rk[13][2]*
          Vpk[4][18][0]))))+((mk[14]*((Vpk[4][19][2]*Vpk[18][19][2])+((
          Vpk[4][19][0]*Vpk[18][19][0])+(Vpk[4][19][1]*Vpk[18][19][1]))))+((
          IkWpk[18][19][1]*c19)-(IkWpk[18][19][2]*s19))));
        mm[4][18] = (((mk[16]*((Vpk[4][21][2]*Vpk[18][21][2])+((Vpk[4][21][0]*
          Vpk[18][21][0])+(Vpk[4][21][1]*Vpk[18][21][1]))))+((IkWpk[18][21][2]*
          Wpk[4][20][2])+((IkWpk[18][21][0]*Wpk[4][21][0])+(IkWpk[18][21][1]*
          Wpk[4][21][1]))))+(temp[0]+((mk[15]*((Vpk[4][20][2]*Vpk[18][20][2])+((
          Vpk[4][20][0]*Vpk[18][20][0])+(Vpk[4][20][1]*Vpk[18][20][1]))))+((
          IkWpk[18][20][2]*Wpk[4][20][2])+((IkWpk[18][20][0]*Wpk[4][20][0])+(
          IkWpk[18][20][1]*c19))))));
        temp[0] = (((mk[14]*((rk[14][2]*Vpk[4][19][1])-(rk[14][1]*Vpk[4][19][2])
          ))+((ik[14][1][0]*c19)-(ik[14][2][0]*s19)))+((mk[15]*((Vpk[4][20][2]*
          Vpk[19][20][2])+((Vpk[4][20][0]*Vpk[19][20][0])+(Vpk[4][20][1]*
          Vpk[19][20][1]))))+((IkWpk[19][20][2]*Wpk[4][20][2])+((
          IkWpk[19][20][0]*Wpk[4][20][0])+(IkWpk[19][20][1]*c19)))));
        mm[4][19] = (((mk[16]*((Vpk[4][21][2]*Vpk[19][21][2])+((Vpk[4][21][0]*
          Vpk[19][21][0])+(Vpk[4][21][1]*Vpk[19][21][1]))))+((IkWpk[19][21][2]*
          Wpk[4][20][2])+((IkWpk[19][21][0]*Wpk[4][21][0])+(IkWpk[19][21][1]*
          Wpk[4][21][1]))))+temp[0]);
        mm[4][20] = (((mk[15]*((rk[15][0]*Vpk[4][20][2])-(rk[15][2]*
          Vpk[4][20][0])))+((ik[15][2][1]*Wpk[4][20][2])+((ik[15][0][1]*
          Wpk[4][20][0])+(ik[15][1][1]*c19))))+((mk[16]*((Vpk[4][21][2]*
          Vpk[20][21][2])+((Vpk[4][21][0]*Vpk[20][21][0])+(Vpk[4][21][1]*
          Vpk[20][21][1]))))+((IkWpk[20][21][2]*Wpk[4][20][2])+((
          IkWpk[20][21][0]*Wpk[4][21][0])+(IkWpk[20][21][1]*Wpk[4][21][1])))));
        mm[4][21] = ((mk[16]*((rk[16][1]*Vpk[4][21][0])-(rk[16][0]*Vpk[4][21][1]
          )))+((ik[16][2][2]*Wpk[4][20][2])+((ik[16][0][2]*Wpk[4][21][0])+(
          ik[16][1][2]*Wpk[4][21][1]))));
        temp[0] = ((ik[17][1][1]+(mk[17]*((rk[17][0]*Vpk[4][22][2])-(rk[17][2]*
          Vpk[4][22][0]))))+((mk[18]*((Vpk[4][23][2]*Vpk[22][23][2])+((
          Vpk[4][23][0]*Vpk[22][23][0])+(Vpk[4][23][1]*Vpk[22][23][1]))))+((
          IkWpk[22][23][1]*c23)-(IkWpk[22][23][2]*s23))));
        mm[4][22] = (((mk[20]*((Vpk[4][25][2]*Vpk[22][25][2])+((Vpk[4][25][0]*
          Vpk[22][25][0])+(Vpk[4][25][1]*Vpk[22][25][1]))))+((IkWpk[22][25][2]*
          Wpk[4][24][2])+((IkWpk[22][25][0]*Wpk[4][25][0])+(IkWpk[22][25][1]*
          Wpk[4][25][1]))))+(temp[0]+((mk[19]*((Vpk[4][24][2]*Vpk[22][24][2])+((
          Vpk[4][24][0]*Vpk[22][24][0])+(Vpk[4][24][1]*Vpk[22][24][1]))))+((
          IkWpk[22][24][2]*Wpk[4][24][2])+((IkWpk[22][24][0]*Wpk[4][24][0])+(
          IkWpk[22][24][1]*c23))))));
        temp[0] = (((mk[18]*((rk[18][2]*Vpk[4][23][1])-(rk[18][1]*Vpk[4][23][2])
          ))+((ik[18][1][0]*c23)-(ik[18][2][0]*s23)))+((mk[19]*((Vpk[4][24][2]*
          Vpk[23][24][2])+((Vpk[4][24][0]*Vpk[23][24][0])+(Vpk[4][24][1]*
          Vpk[23][24][1]))))+((IkWpk[23][24][2]*Wpk[4][24][2])+((
          IkWpk[23][24][0]*Wpk[4][24][0])+(IkWpk[23][24][1]*c23)))));
        mm[4][23] = (((mk[20]*((Vpk[4][25][2]*Vpk[23][25][2])+((Vpk[4][25][0]*
          Vpk[23][25][0])+(Vpk[4][25][1]*Vpk[23][25][1]))))+((IkWpk[23][25][2]*
          Wpk[4][24][2])+((IkWpk[23][25][0]*Wpk[4][25][0])+(IkWpk[23][25][1]*
          Wpk[4][25][1]))))+temp[0]);
        mm[4][24] = (((mk[19]*((rk[19][0]*Vpk[4][24][2])-(rk[19][2]*
          Vpk[4][24][0])))+((ik[19][2][1]*Wpk[4][24][2])+((ik[19][0][1]*
          Wpk[4][24][0])+(ik[19][1][1]*c23))))+((mk[20]*((Vpk[4][25][2]*
          Vpk[24][25][2])+((Vpk[4][25][0]*Vpk[24][25][0])+(Vpk[4][25][1]*
          Vpk[24][25][1]))))+((IkWpk[24][25][2]*Wpk[4][24][2])+((
          IkWpk[24][25][0]*Wpk[4][25][0])+(IkWpk[24][25][1]*Wpk[4][25][1])))));
        mm[4][25] = ((mk[20]*((rk[20][1]*Vpk[4][25][0])-(rk[20][0]*Vpk[4][25][1]
          )))+((ik[20][2][2]*Wpk[4][24][2])+((ik[20][0][2]*Wpk[4][25][0])+(
          ik[20][1][2]*Wpk[4][25][1]))));
        temp[0] = (((ik[0][2][2]+(mk[0]*((rk[0][0]*rk[0][0])+(rk[0][1]*rk[0][1])
          )))+(ik[1][2][2]+(mk[1]*((Vpk[5][6][0]*Vpk[5][6][0])+(Vpk[5][6][1]*
          Vpk[5][6][1])))))+((mk[2]*((Vpk[5][7][2]*Vpk[5][7][2])+((Vpk[5][7][0]*
          Vpk[5][7][0])+(Vpk[5][7][1]*Vpk[5][7][1]))))+((IkWpk[5][7][2]*c7)-(
          IkWpk[5][7][0]*s7))));
        temp[1] = (((mk[4]*((Vpk[5][9][2]*Vpk[5][9][2])+((Vpk[5][9][0]*
          Vpk[5][9][0])+(Vpk[5][9][1]*Vpk[5][9][1]))))+((IkWpk[5][9][2]*
          Wpk[5][9][2])+((IkWpk[5][9][0]*Wpk[5][9][0])+(IkWpk[5][9][1]*
          Wpk[5][8][1]))))+(((mk[3]*((Vpk[5][8][2]*Vpk[5][8][2])+((Vpk[5][8][0]*
          Vpk[5][8][0])+(Vpk[5][8][1]*Vpk[5][8][1]))))+((IkWpk[5][8][2]*
          Wpk[5][8][2])+((IkWpk[5][8][1]*Wpk[5][8][1])-(IkWpk[5][8][0]*s7))))+
          temp[0]));
        temp[2] = (((mk[5]*((Vpk[5][10][2]*Vpk[5][10][2])+((Vpk[5][10][0]*
          Vpk[5][10][0])+(Vpk[5][10][1]*Vpk[5][10][1]))))+((IkWpk[5][10][2]*
          Wpk[5][10][2])+((IkWpk[5][10][0]*Wpk[5][10][0])+(IkWpk[5][10][1]*
          Wpk[5][8][1]))))+temp[1]);
        temp[3] = ((ik[7][2][2]+(mk[7]*((Vpk[5][12][0]*Vpk[5][12][0])+(
          Vpk[5][12][1]*Vpk[5][12][1]))))+(((mk[6]*((Vpk[5][11][2]*Vpk[5][11][2]
          )+((Vpk[5][11][0]*Vpk[5][11][0])+(Vpk[5][11][1]*Vpk[5][11][1]))))+((
          IkWpk[5][11][2]*Wpk[5][11][2])+((IkWpk[5][11][0]*Wpk[5][10][0])+(
          IkWpk[5][11][1]*Wpk[5][11][1]))))+temp[2]));
        temp[4] = (((mk[9]*((Vpk[5][14][2]*Vpk[5][14][2])+((Vpk[5][14][0]*
          Vpk[5][14][0])+(Vpk[5][14][1]*Vpk[5][14][1]))))+((IkWpk[5][14][2]*
          Wpk[5][14][2])+((IkWpk[5][14][1]*Wpk[5][14][1])-(IkWpk[5][14][0]*s13))
          ))+(temp[3]+((mk[8]*((Vpk[5][13][2]*Vpk[5][13][2])+((Vpk[5][13][0]*
          Vpk[5][13][0])+(Vpk[5][13][1]*Vpk[5][13][1]))))+((IkWpk[5][13][2]*c13)
          -(IkWpk[5][13][0]*s13)))));
        temp[5] = (((mk[10]*((Vpk[5][15][2]*Vpk[5][15][2])+((Vpk[5][15][0]*
          Vpk[5][15][0])+(Vpk[5][15][1]*Vpk[5][15][1]))))+((IkWpk[5][15][2]*
          Wpk[5][15][2])+((IkWpk[5][15][0]*Wpk[5][15][0])+(IkWpk[5][15][1]*
          Wpk[5][14][1]))))+temp[4]);
        temp[6] = (((mk[11]*((Vpk[5][16][2]*Vpk[5][16][2])+((Vpk[5][16][0]*
          Vpk[5][16][0])+(Vpk[5][16][1]*Vpk[5][16][1]))))+((IkWpk[5][16][2]*
          Wpk[5][16][2])+((IkWpk[5][16][0]*Wpk[5][16][0])+(IkWpk[5][16][1]*
          Wpk[5][14][1]))))+temp[5]);
        temp[7] = (((mk[13]*((Vpk[5][18][2]*Vpk[5][18][2])+((Vpk[5][18][0]*
          Vpk[5][18][0])+(Vpk[5][18][1]*Vpk[5][18][1]))))+((IkWpk[5][18][2]*c18)
          -(IkWpk[5][18][0]*s18)))+(((mk[12]*((Vpk[5][17][2]*Vpk[5][17][2])+((
          Vpk[5][17][0]*Vpk[5][17][0])+(Vpk[5][17][1]*Vpk[5][17][1]))))+((
          IkWpk[5][17][2]*Wpk[5][17][2])+((IkWpk[5][17][0]*Wpk[5][16][0])+(
          IkWpk[5][17][1]*Wpk[5][17][1]))))+temp[6]));
        temp[8] = (((mk[15]*((Vpk[5][20][2]*Vpk[5][20][2])+((Vpk[5][20][0]*
          Vpk[5][20][0])+(Vpk[5][20][1]*Vpk[5][20][1]))))+((IkWpk[5][20][2]*
          Wpk[5][20][2])+((IkWpk[5][20][0]*Wpk[5][20][0])+(IkWpk[5][20][1]*
          Wpk[5][19][1]))))+(((mk[14]*((Vpk[5][19][2]*Vpk[5][19][2])+((
          Vpk[5][19][0]*Vpk[5][19][0])+(Vpk[5][19][1]*Vpk[5][19][1]))))+((
          IkWpk[5][19][2]*Wpk[5][19][2])+((IkWpk[5][19][1]*Wpk[5][19][1])-(
          IkWpk[5][19][0]*s18))))+temp[7]));
        temp[9] = (((mk[17]*((Vpk[5][22][2]*Vpk[5][22][2])+((Vpk[5][22][0]*
          Vpk[5][22][0])+(Vpk[5][22][1]*Vpk[5][22][1]))))+((IkWpk[5][22][2]*c22)
          -(IkWpk[5][22][0]*s22)))+(((mk[16]*((Vpk[5][21][2]*Vpk[5][21][2])+((
          Vpk[5][21][0]*Vpk[5][21][0])+(Vpk[5][21][1]*Vpk[5][21][1]))))+((
          IkWpk[5][21][2]*Wpk[5][20][2])+((IkWpk[5][21][0]*Wpk[5][21][0])+(
          IkWpk[5][21][1]*Wpk[5][21][1]))))+temp[8]));
        temp[10] = (((mk[19]*((Vpk[5][24][2]*Vpk[5][24][2])+((Vpk[5][24][0]*
          Vpk[5][24][0])+(Vpk[5][24][1]*Vpk[5][24][1]))))+((IkWpk[5][24][2]*
          Wpk[5][24][2])+((IkWpk[5][24][0]*Wpk[5][24][0])+(IkWpk[5][24][1]*
          Wpk[5][23][1]))))+(((mk[18]*((Vpk[5][23][2]*Vpk[5][23][2])+((
          Vpk[5][23][0]*Vpk[5][23][0])+(Vpk[5][23][1]*Vpk[5][23][1]))))+((
          IkWpk[5][23][2]*Wpk[5][23][2])+((IkWpk[5][23][1]*Wpk[5][23][1])-(
          IkWpk[5][23][0]*s22))))+temp[9]));
        mm[5][5] = (((mk[20]*((Vpk[5][25][2]*Vpk[5][25][2])+((Vpk[5][25][0]*
          Vpk[5][25][0])+(Vpk[5][25][1]*Vpk[5][25][1]))))+((IkWpk[5][25][2]*
          Wpk[5][24][2])+((IkWpk[5][25][0]*Wpk[5][25][0])+(IkWpk[5][25][1]*
          Wpk[5][25][1]))))+temp[10]);
        temp[0] = ((ik[1][2][2]+(mk[1]*((rk[1][1]*Vpk[5][6][0])-(rk[1][0]*
          Vpk[5][6][1]))))+((mk[2]*((Vpk[5][7][2]*Vpk[6][7][2])+((Vpk[5][7][0]*
          Vpk[6][7][0])+(Vpk[5][7][1]*Vpk[6][7][1]))))+((IkWpk[6][7][2]*c7)-(
          IkWpk[6][7][0]*s7))));
        temp[1] = (((mk[4]*((Vpk[5][9][2]*Vpk[6][9][2])+((Vpk[5][9][0]*
          Vpk[6][9][0])+(Vpk[5][9][1]*Vpk[6][9][1]))))+((IkWpk[6][9][2]*
          Wpk[5][9][2])+((IkWpk[6][9][0]*Wpk[5][9][0])+(IkWpk[6][9][1]*
          Wpk[5][8][1]))))+(temp[0]+((mk[3]*((Vpk[5][8][2]*Vpk[6][8][2])+((
          Vpk[5][8][0]*Vpk[6][8][0])+(Vpk[5][8][1]*Vpk[6][8][1]))))+((
          IkWpk[6][8][2]*Wpk[5][8][2])+((IkWpk[6][8][1]*Wpk[5][8][1])-(
          IkWpk[6][8][0]*s7))))));
        temp[2] = (((mk[5]*((Vpk[5][10][2]*Vpk[6][10][2])+((Vpk[5][10][0]*
          Vpk[6][10][0])+(Vpk[5][10][1]*Vpk[6][10][1]))))+((IkWpk[6][10][2]*
          Wpk[5][10][2])+((IkWpk[6][10][0]*Wpk[5][10][0])+(IkWpk[6][10][1]*
          Wpk[5][8][1]))))+temp[1]);
        mm[5][6] = (((mk[6]*((Vpk[5][11][2]*Vpk[6][11][2])+((Vpk[5][11][0]*
          Vpk[6][11][0])+(Vpk[5][11][1]*Vpk[6][11][1]))))+((IkWpk[6][11][2]*
          Wpk[5][11][2])+((IkWpk[6][11][0]*Wpk[5][10][0])+(IkWpk[6][11][1]*
          Wpk[5][11][1]))))+temp[2]);
        temp[0] = (((mk[2]*((rk[2][0]*Vpk[5][7][2])-(rk[2][2]*Vpk[5][7][0])))+((
          ik[2][2][1]*c7)-(ik[2][0][1]*s7)))+((mk[3]*((Vpk[5][8][2]*Vpk[7][8][2]
          )+((Vpk[5][8][0]*Vpk[7][8][0])+(Vpk[5][8][1]*Vpk[7][8][1]))))+((
          IkWpk[7][8][2]*Wpk[5][8][2])+((IkWpk[7][8][1]*Wpk[5][8][1])-(
          IkWpk[7][8][0]*s7)))));
        temp[1] = (((mk[4]*((Vpk[5][9][2]*Vpk[7][9][2])+((Vpk[5][9][0]*
          Vpk[7][9][0])+(Vpk[5][9][1]*Vpk[7][9][1]))))+((IkWpk[7][9][2]*
          Wpk[5][9][2])+((IkWpk[7][9][0]*Wpk[5][9][0])+(IkWpk[7][9][1]*
          Wpk[5][8][1]))))+temp[0]);
        temp[2] = (((mk[5]*((Vpk[5][10][2]*Vpk[7][10][2])+((Vpk[5][10][0]*
          Vpk[7][10][0])+(Vpk[5][10][1]*Vpk[7][10][1]))))+((IkWpk[7][10][2]*
          Wpk[5][10][2])+((IkWpk[7][10][0]*Wpk[5][10][0])+(IkWpk[7][10][1]*
          Wpk[5][8][1]))))+temp[1]);
        mm[5][7] = (((mk[6]*((Vpk[5][11][2]*Vpk[7][11][2])+((Vpk[5][11][0]*
          Vpk[7][11][0])+(Vpk[5][11][1]*Vpk[7][11][1]))))+((IkWpk[7][11][2]*
          Wpk[5][11][2])+((IkWpk[7][11][0]*Wpk[5][10][0])+(IkWpk[7][11][1]*
          Wpk[5][11][1]))))+temp[2]);
        temp[0] = (((mk[3]*((rk[3][2]*Vpk[5][8][1])-(rk[3][1]*Vpk[5][8][2])))+((
          ik[3][2][0]*Wpk[5][8][2])+((ik[3][1][0]*Wpk[5][8][1])-(ik[3][0][0]*s7)
          )))+((mk[4]*((Vpk[5][9][2]*Vpk[8][9][2])+((Vpk[5][9][0]*Vpk[8][9][0])+
          (Vpk[5][9][1]*Vpk[8][9][1]))))+((IkWpk[8][9][2]*Wpk[5][9][2])+((
          IkWpk[8][9][0]*Wpk[5][9][0])+(IkWpk[8][9][1]*Wpk[5][8][1])))));
        temp[1] = (((mk[5]*((Vpk[5][10][2]*Vpk[8][10][2])+((Vpk[5][10][0]*
          Vpk[8][10][0])+(Vpk[5][10][1]*Vpk[8][10][1]))))+((IkWpk[8][10][2]*
          Wpk[5][10][2])+((IkWpk[8][10][0]*Wpk[5][10][0])+(IkWpk[8][10][1]*
          Wpk[5][8][1]))))+temp[0]);
        mm[5][8] = (((mk[6]*((Vpk[5][11][2]*Vpk[8][11][2])+((Vpk[5][11][0]*
          Vpk[8][11][0])+(Vpk[5][11][1]*Vpk[8][11][1]))))+((IkWpk[8][11][2]*
          Wpk[5][11][2])+((IkWpk[8][11][0]*Wpk[5][10][0])+(IkWpk[8][11][1]*
          Wpk[5][11][1]))))+temp[1]);
        temp[0] = (((mk[4]*((rk[4][0]*Vpk[5][9][2])-(rk[4][2]*Vpk[5][9][0])))+((
          ik[4][2][1]*Wpk[5][9][2])+((ik[4][0][1]*Wpk[5][9][0])+(ik[4][1][1]*
          Wpk[5][8][1]))))+((mk[5]*((Vpk[5][10][0]*Vpk[9][10][0])+(Vpk[5][10][2]
          *Vpk[9][10][2])))+((ik[5][2][1]*Wpk[5][10][2])+((ik[5][0][1]*
          Wpk[5][10][0])+(ik[5][1][1]*Wpk[5][8][1])))));
        mm[5][9] = (((mk[6]*((Vpk[5][11][2]*Vpk[9][11][2])+((Vpk[5][11][0]*
          Vpk[9][11][0])+(Vpk[5][11][1]*Vpk[9][11][1]))))+((IkWpk[9][11][2]*
          Wpk[5][11][2])+((IkWpk[9][11][0]*Wpk[5][10][0])+(IkWpk[9][11][1]*
          Wpk[5][11][1]))))+temp[0]);
        mm[5][10] = (((mk[5]*((rk[5][0]*Vpk[5][10][2])-(rk[5][2]*Vpk[5][10][0]))
          )+((ik[5][2][1]*Wpk[5][10][2])+((ik[5][0][1]*Wpk[5][10][0])+(
          ik[5][1][1]*Wpk[5][8][1]))))+((mk[6]*((Vpk[5][11][2]*Vpk[10][11][2])+(
          (Vpk[5][11][0]*Vpk[10][11][0])+(Vpk[5][11][1]*Vpk[10][11][1]))))+((
          IkWpk[10][11][2]*Wpk[5][11][2])+((IkWpk[10][11][0]*Wpk[5][10][0])+(
          IkWpk[10][11][1]*Wpk[5][11][1])))));
        mm[5][11] = ((mk[6]*((rk[6][2]*Vpk[5][11][1])-(rk[6][1]*Vpk[5][11][2])))
          +((ik[6][2][0]*Wpk[5][11][2])+((ik[6][0][0]*Wpk[5][10][0])+(
          ik[6][1][0]*Wpk[5][11][1]))));
        temp[0] = ((ik[7][2][2]+(mk[7]*((rk[7][1]*Vpk[5][12][0])-(rk[7][0]*
          Vpk[5][12][1]))))+((mk[8]*((Vpk[5][13][2]*Vpk[12][13][2])+((
          Vpk[5][13][0]*Vpk[12][13][0])+(Vpk[5][13][1]*Vpk[12][13][1]))))+((
          IkWpk[12][13][2]*c13)-(IkWpk[12][13][0]*s13))));
        temp[1] = (((mk[10]*((Vpk[5][15][2]*Vpk[12][15][2])+((Vpk[5][15][0]*
          Vpk[12][15][0])+(Vpk[5][15][1]*Vpk[12][15][1]))))+((IkWpk[12][15][2]*
          Wpk[5][15][2])+((IkWpk[12][15][0]*Wpk[5][15][0])+(IkWpk[12][15][1]*
          Wpk[5][14][1]))))+(temp[0]+((mk[9]*((Vpk[5][14][2]*Vpk[12][14][2])+((
          Vpk[5][14][0]*Vpk[12][14][0])+(Vpk[5][14][1]*Vpk[12][14][1]))))+((
          IkWpk[12][14][2]*Wpk[5][14][2])+((IkWpk[12][14][1]*Wpk[5][14][1])-(
          IkWpk[12][14][0]*s13))))));
        temp[2] = (((mk[11]*((Vpk[5][16][2]*Vpk[12][16][2])+((Vpk[5][16][0]*
          Vpk[12][16][0])+(Vpk[5][16][1]*Vpk[12][16][1]))))+((IkWpk[12][16][2]*
          Wpk[5][16][2])+((IkWpk[12][16][0]*Wpk[5][16][0])+(IkWpk[12][16][1]*
          Wpk[5][14][1]))))+temp[1]);
        mm[5][12] = (((mk[12]*((Vpk[5][17][2]*Vpk[12][17][2])+((Vpk[5][17][0]*
          Vpk[12][17][0])+(Vpk[5][17][1]*Vpk[12][17][1]))))+((IkWpk[12][17][2]*
          Wpk[5][17][2])+((IkWpk[12][17][0]*Wpk[5][16][0])+(IkWpk[12][17][1]*
          Wpk[5][17][1]))))+temp[2]);
        temp[0] = (((mk[8]*((rk[8][0]*Vpk[5][13][2])-(rk[8][2]*Vpk[5][13][0])))+
          ((ik[8][2][1]*c13)-(ik[8][0][1]*s13)))+((mk[9]*((Vpk[5][14][2]*
          Vpk[13][14][2])+((Vpk[5][14][0]*Vpk[13][14][0])+(Vpk[5][14][1]*
          Vpk[13][14][1]))))+((IkWpk[13][14][2]*Wpk[5][14][2])+((
          IkWpk[13][14][1]*Wpk[5][14][1])-(IkWpk[13][14][0]*s13)))));
        temp[1] = (((mk[10]*((Vpk[5][15][2]*Vpk[13][15][2])+((Vpk[5][15][0]*
          Vpk[13][15][0])+(Vpk[5][15][1]*Vpk[13][15][1]))))+((IkWpk[13][15][2]*
          Wpk[5][15][2])+((IkWpk[13][15][0]*Wpk[5][15][0])+(IkWpk[13][15][1]*
          Wpk[5][14][1]))))+temp[0]);
        temp[2] = (((mk[11]*((Vpk[5][16][2]*Vpk[13][16][2])+((Vpk[5][16][0]*
          Vpk[13][16][0])+(Vpk[5][16][1]*Vpk[13][16][1]))))+((IkWpk[13][16][2]*
          Wpk[5][16][2])+((IkWpk[13][16][0]*Wpk[5][16][0])+(IkWpk[13][16][1]*
          Wpk[5][14][1]))))+temp[1]);
        mm[5][13] = (((mk[12]*((Vpk[5][17][2]*Vpk[13][17][2])+((Vpk[5][17][0]*
          Vpk[13][17][0])+(Vpk[5][17][1]*Vpk[13][17][1]))))+((IkWpk[13][17][2]*
          Wpk[5][17][2])+((IkWpk[13][17][0]*Wpk[5][16][0])+(IkWpk[13][17][1]*
          Wpk[5][17][1]))))+temp[2]);
        temp[0] = (((mk[9]*((rk[9][2]*Vpk[5][14][1])-(rk[9][1]*Vpk[5][14][2])))+
          ((ik[9][2][0]*Wpk[5][14][2])+((ik[9][1][0]*Wpk[5][14][1])-(ik[9][0][0]
          *s13))))+((mk[10]*((Vpk[5][15][2]*Vpk[14][15][2])+((Vpk[5][15][0]*
          Vpk[14][15][0])+(Vpk[5][15][1]*Vpk[14][15][1]))))+((IkWpk[14][15][2]*
          Wpk[5][15][2])+((IkWpk[14][15][0]*Wpk[5][15][0])+(IkWpk[14][15][1]*
          Wpk[5][14][1])))));
        temp[1] = (((mk[11]*((Vpk[5][16][2]*Vpk[14][16][2])+((Vpk[5][16][0]*
          Vpk[14][16][0])+(Vpk[5][16][1]*Vpk[14][16][1]))))+((IkWpk[14][16][2]*
          Wpk[5][16][2])+((IkWpk[14][16][0]*Wpk[5][16][0])+(IkWpk[14][16][1]*
          Wpk[5][14][1]))))+temp[0]);
        mm[5][14] = (((mk[12]*((Vpk[5][17][2]*Vpk[14][17][2])+((Vpk[5][17][0]*
          Vpk[14][17][0])+(Vpk[5][17][1]*Vpk[14][17][1]))))+((IkWpk[14][17][2]*
          Wpk[5][17][2])+((IkWpk[14][17][0]*Wpk[5][16][0])+(IkWpk[14][17][1]*
          Wpk[5][17][1]))))+temp[1]);
        temp[0] = (((mk[10]*((rk[10][0]*Vpk[5][15][2])-(rk[10][2]*Vpk[5][15][0])
          ))+((ik[10][2][1]*Wpk[5][15][2])+((ik[10][0][1]*Wpk[5][15][0])+(
          ik[10][1][1]*Wpk[5][14][1]))))+((mk[11]*((Vpk[5][16][0]*Vpk[15][16][0]
          )+(Vpk[5][16][2]*Vpk[15][16][2])))+((ik[11][2][1]*Wpk[5][16][2])+((
          ik[11][0][1]*Wpk[5][16][0])+(ik[11][1][1]*Wpk[5][14][1])))));
        mm[5][15] = (((mk[12]*((Vpk[5][17][2]*Vpk[15][17][2])+((Vpk[5][17][0]*
          Vpk[15][17][0])+(Vpk[5][17][1]*Vpk[15][17][1]))))+((IkWpk[15][17][2]*
          Wpk[5][17][2])+((IkWpk[15][17][0]*Wpk[5][16][0])+(IkWpk[15][17][1]*
          Wpk[5][17][1]))))+temp[0]);
        mm[5][16] = (((mk[11]*((rk[11][0]*Vpk[5][16][2])-(rk[11][2]*
          Vpk[5][16][0])))+((ik[11][2][1]*Wpk[5][16][2])+((ik[11][0][1]*
          Wpk[5][16][0])+(ik[11][1][1]*Wpk[5][14][1]))))+((mk[12]*((
          Vpk[5][17][2]*Vpk[16][17][2])+((Vpk[5][17][0]*Vpk[16][17][0])+(
          Vpk[5][17][1]*Vpk[16][17][1]))))+((IkWpk[16][17][2]*Wpk[5][17][2])+((
          IkWpk[16][17][0]*Wpk[5][16][0])+(IkWpk[16][17][1]*Wpk[5][17][1])))));
        mm[5][17] = ((mk[12]*((rk[12][2]*Vpk[5][17][1])-(rk[12][1]*Vpk[5][17][2]
          )))+((ik[12][2][0]*Wpk[5][17][2])+((ik[12][0][0]*Wpk[5][16][0])+(
          ik[12][1][0]*Wpk[5][17][1]))));
        temp[0] = (((mk[13]*((rk[13][0]*Vpk[5][18][2])-(rk[13][2]*Vpk[5][18][0])
          ))+((ik[13][2][1]*c18)-(ik[13][0][1]*s18)))+((mk[14]*((Vpk[5][19][2]*
          Vpk[18][19][2])+((Vpk[5][19][0]*Vpk[18][19][0])+(Vpk[5][19][1]*
          Vpk[18][19][1]))))+((IkWpk[18][19][2]*Wpk[5][19][2])+((
          IkWpk[18][19][1]*Wpk[5][19][1])-(IkWpk[18][19][0]*s18)))));
        temp[1] = (((mk[15]*((Vpk[5][20][2]*Vpk[18][20][2])+((Vpk[5][20][0]*
          Vpk[18][20][0])+(Vpk[5][20][1]*Vpk[18][20][1]))))+((IkWpk[18][20][2]*
          Wpk[5][20][2])+((IkWpk[18][20][0]*Wpk[5][20][0])+(IkWpk[18][20][1]*
          Wpk[5][19][1]))))+temp[0]);
        mm[5][18] = (((mk[16]*((Vpk[5][21][2]*Vpk[18][21][2])+((Vpk[5][21][0]*
          Vpk[18][21][0])+(Vpk[5][21][1]*Vpk[18][21][1]))))+((IkWpk[18][21][2]*
          Wpk[5][20][2])+((IkWpk[18][21][0]*Wpk[5][21][0])+(IkWpk[18][21][1]*
          Wpk[5][21][1]))))+temp[1]);
        temp[0] = (((mk[14]*((rk[14][2]*Vpk[5][19][1])-(rk[14][1]*Vpk[5][19][2])
          ))+((ik[14][2][0]*Wpk[5][19][2])+((ik[14][1][0]*Wpk[5][19][1])-(
          ik[14][0][0]*s18))))+((mk[15]*((Vpk[5][20][2]*Vpk[19][20][2])+((
          Vpk[5][20][0]*Vpk[19][20][0])+(Vpk[5][20][1]*Vpk[19][20][1]))))+((
          IkWpk[19][20][2]*Wpk[5][20][2])+((IkWpk[19][20][0]*Wpk[5][20][0])+(
          IkWpk[19][20][1]*Wpk[5][19][1])))));
        mm[5][19] = (((mk[16]*((Vpk[5][21][2]*Vpk[19][21][2])+((Vpk[5][21][0]*
          Vpk[19][21][0])+(Vpk[5][21][1]*Vpk[19][21][1]))))+((IkWpk[19][21][2]*
          Wpk[5][20][2])+((IkWpk[19][21][0]*Wpk[5][21][0])+(IkWpk[19][21][1]*
          Wpk[5][21][1]))))+temp[0]);
        mm[5][20] = (((mk[15]*((rk[15][0]*Vpk[5][20][2])-(rk[15][2]*
          Vpk[5][20][0])))+((ik[15][2][1]*Wpk[5][20][2])+((ik[15][0][1]*
          Wpk[5][20][0])+(ik[15][1][1]*Wpk[5][19][1]))))+((mk[16]*((
          Vpk[5][21][2]*Vpk[20][21][2])+((Vpk[5][21][0]*Vpk[20][21][0])+(
          Vpk[5][21][1]*Vpk[20][21][1]))))+((IkWpk[20][21][2]*Wpk[5][20][2])+((
          IkWpk[20][21][0]*Wpk[5][21][0])+(IkWpk[20][21][1]*Wpk[5][21][1])))));
        mm[5][21] = ((mk[16]*((rk[16][1]*Vpk[5][21][0])-(rk[16][0]*Vpk[5][21][1]
          )))+((ik[16][2][2]*Wpk[5][20][2])+((ik[16][0][2]*Wpk[5][21][0])+(
          ik[16][1][2]*Wpk[5][21][1]))));
        temp[0] = (((mk[17]*((rk[17][0]*Vpk[5][22][2])-(rk[17][2]*Vpk[5][22][0])
          ))+((ik[17][2][1]*c22)-(ik[17][0][1]*s22)))+((mk[18]*((Vpk[5][23][2]*
          Vpk[22][23][2])+((Vpk[5][23][0]*Vpk[22][23][0])+(Vpk[5][23][1]*
          Vpk[22][23][1]))))+((IkWpk[22][23][2]*Wpk[5][23][2])+((
          IkWpk[22][23][1]*Wpk[5][23][1])-(IkWpk[22][23][0]*s22)))));
        temp[1] = (((mk[19]*((Vpk[5][24][2]*Vpk[22][24][2])+((Vpk[5][24][0]*
          Vpk[22][24][0])+(Vpk[5][24][1]*Vpk[22][24][1]))))+((IkWpk[22][24][2]*
          Wpk[5][24][2])+((IkWpk[22][24][0]*Wpk[5][24][0])+(IkWpk[22][24][1]*
          Wpk[5][23][1]))))+temp[0]);
        mm[5][22] = (((mk[20]*((Vpk[5][25][2]*Vpk[22][25][2])+((Vpk[5][25][0]*
          Vpk[22][25][0])+(Vpk[5][25][1]*Vpk[22][25][1]))))+((IkWpk[22][25][2]*
          Wpk[5][24][2])+((IkWpk[22][25][0]*Wpk[5][25][0])+(IkWpk[22][25][1]*
          Wpk[5][25][1]))))+temp[1]);
        temp[0] = (((mk[18]*((rk[18][2]*Vpk[5][23][1])-(rk[18][1]*Vpk[5][23][2])
          ))+((ik[18][2][0]*Wpk[5][23][2])+((ik[18][1][0]*Wpk[5][23][1])-(
          ik[18][0][0]*s22))))+((mk[19]*((Vpk[5][24][2]*Vpk[23][24][2])+((
          Vpk[5][24][0]*Vpk[23][24][0])+(Vpk[5][24][1]*Vpk[23][24][1]))))+((
          IkWpk[23][24][2]*Wpk[5][24][2])+((IkWpk[23][24][0]*Wpk[5][24][0])+(
          IkWpk[23][24][1]*Wpk[5][23][1])))));
        mm[5][23] = (((mk[20]*((Vpk[5][25][2]*Vpk[23][25][2])+((Vpk[5][25][0]*
          Vpk[23][25][0])+(Vpk[5][25][1]*Vpk[23][25][1]))))+((IkWpk[23][25][2]*
          Wpk[5][24][2])+((IkWpk[23][25][0]*Wpk[5][25][0])+(IkWpk[23][25][1]*
          Wpk[5][25][1]))))+temp[0]);
        mm[5][24] = (((mk[19]*((rk[19][0]*Vpk[5][24][2])-(rk[19][2]*
          Vpk[5][24][0])))+((ik[19][2][1]*Wpk[5][24][2])+((ik[19][0][1]*
          Wpk[5][24][0])+(ik[19][1][1]*Wpk[5][23][1]))))+((mk[20]*((
          Vpk[5][25][2]*Vpk[24][25][2])+((Vpk[5][25][0]*Vpk[24][25][0])+(
          Vpk[5][25][1]*Vpk[24][25][1]))))+((IkWpk[24][25][2]*Wpk[5][24][2])+((
          IkWpk[24][25][0]*Wpk[5][25][0])+(IkWpk[24][25][1]*Wpk[5][25][1])))));
        mm[5][25] = ((mk[20]*((rk[20][1]*Vpk[5][25][0])-(rk[20][0]*Vpk[5][25][1]
          )))+((ik[20][2][2]*Wpk[5][24][2])+((ik[20][0][2]*Wpk[5][25][0])+(
          ik[20][1][2]*Wpk[5][25][1]))));
        temp[0] = ((ik[1][2][2]+(mk[1]*((rk[1][0]*rk[1][0])+(rk[1][1]*rk[1][1]))
          ))+((mk[2]*((Vpk[6][7][2]*Vpk[6][7][2])+((Vpk[6][7][0]*Vpk[6][7][0])+(
          Vpk[6][7][1]*Vpk[6][7][1]))))+((IkWpk[6][7][2]*c7)-(IkWpk[6][7][0]*s7)
          )));
        temp[1] = (((mk[4]*((Vpk[6][9][2]*Vpk[6][9][2])+((Vpk[6][9][0]*
          Vpk[6][9][0])+(Vpk[6][9][1]*Vpk[6][9][1]))))+((IkWpk[6][9][2]*
          Wpk[6][9][2])+((IkWpk[6][9][0]*Wpk[6][9][0])+(IkWpk[6][9][1]*
          Wpk[6][8][1]))))+(temp[0]+((mk[3]*((Vpk[6][8][2]*Vpk[6][8][2])+((
          Vpk[6][8][0]*Vpk[6][8][0])+(Vpk[6][8][1]*Vpk[6][8][1]))))+((
          IkWpk[6][8][2]*Wpk[6][8][2])+((IkWpk[6][8][1]*Wpk[6][8][1])-(
          IkWpk[6][8][0]*s7))))));
        temp[2] = (((mk[5]*((Vpk[6][10][2]*Vpk[6][10][2])+((Vpk[6][10][0]*
          Vpk[6][10][0])+(Vpk[6][10][1]*Vpk[6][10][1]))))+((IkWpk[6][10][2]*
          Wpk[6][10][2])+((IkWpk[6][10][0]*Wpk[6][10][0])+(IkWpk[6][10][1]*
          Wpk[6][8][1]))))+temp[1]);
        mm[6][6] = (((mk[6]*((Vpk[6][11][2]*Vpk[6][11][2])+((Vpk[6][11][0]*
          Vpk[6][11][0])+(Vpk[6][11][1]*Vpk[6][11][1]))))+((IkWpk[6][11][2]*
          Wpk[6][11][2])+((IkWpk[6][11][0]*Wpk[6][10][0])+(IkWpk[6][11][1]*
          Wpk[6][11][1]))))+temp[2]);
        temp[0] = (((mk[2]*((rk[2][0]*Vpk[6][7][2])-(rk[2][2]*Vpk[6][7][0])))+((
          ik[2][2][1]*c7)-(ik[2][0][1]*s7)))+((mk[3]*((Vpk[6][8][2]*Vpk[7][8][2]
          )+((Vpk[6][8][0]*Vpk[7][8][0])+(Vpk[6][8][1]*Vpk[7][8][1]))))+((
          IkWpk[7][8][2]*Wpk[6][8][2])+((IkWpk[7][8][1]*Wpk[6][8][1])-(
          IkWpk[7][8][0]*s7)))));
        temp[1] = (((mk[4]*((Vpk[6][9][2]*Vpk[7][9][2])+((Vpk[6][9][0]*
          Vpk[7][9][0])+(Vpk[6][9][1]*Vpk[7][9][1]))))+((IkWpk[7][9][2]*
          Wpk[6][9][2])+((IkWpk[7][9][0]*Wpk[6][9][0])+(IkWpk[7][9][1]*
          Wpk[6][8][1]))))+temp[0]);
        temp[2] = (((mk[5]*((Vpk[6][10][2]*Vpk[7][10][2])+((Vpk[6][10][0]*
          Vpk[7][10][0])+(Vpk[6][10][1]*Vpk[7][10][1]))))+((IkWpk[7][10][2]*
          Wpk[6][10][2])+((IkWpk[7][10][0]*Wpk[6][10][0])+(IkWpk[7][10][1]*
          Wpk[6][8][1]))))+temp[1]);
        mm[6][7] = (((mk[6]*((Vpk[6][11][2]*Vpk[7][11][2])+((Vpk[6][11][0]*
          Vpk[7][11][0])+(Vpk[6][11][1]*Vpk[7][11][1]))))+((IkWpk[7][11][2]*
          Wpk[6][11][2])+((IkWpk[7][11][0]*Wpk[6][10][0])+(IkWpk[7][11][1]*
          Wpk[6][11][1]))))+temp[2]);
        temp[0] = (((mk[3]*((rk[3][2]*Vpk[6][8][1])-(rk[3][1]*Vpk[6][8][2])))+((
          ik[3][2][0]*Wpk[6][8][2])+((ik[3][1][0]*Wpk[6][8][1])-(ik[3][0][0]*s7)
          )))+((mk[4]*((Vpk[6][9][2]*Vpk[8][9][2])+((Vpk[6][9][0]*Vpk[8][9][0])+
          (Vpk[6][9][1]*Vpk[8][9][1]))))+((IkWpk[8][9][2]*Wpk[6][9][2])+((
          IkWpk[8][9][0]*Wpk[6][9][0])+(IkWpk[8][9][1]*Wpk[6][8][1])))));
        temp[1] = (((mk[5]*((Vpk[6][10][2]*Vpk[8][10][2])+((Vpk[6][10][0]*
          Vpk[8][10][0])+(Vpk[6][10][1]*Vpk[8][10][1]))))+((IkWpk[8][10][2]*
          Wpk[6][10][2])+((IkWpk[8][10][0]*Wpk[6][10][0])+(IkWpk[8][10][1]*
          Wpk[6][8][1]))))+temp[0]);
        mm[6][8] = (((mk[6]*((Vpk[6][11][2]*Vpk[8][11][2])+((Vpk[6][11][0]*
          Vpk[8][11][0])+(Vpk[6][11][1]*Vpk[8][11][1]))))+((IkWpk[8][11][2]*
          Wpk[6][11][2])+((IkWpk[8][11][0]*Wpk[6][10][0])+(IkWpk[8][11][1]*
          Wpk[6][11][1]))))+temp[1]);
        temp[0] = (((mk[4]*((rk[4][0]*Vpk[6][9][2])-(rk[4][2]*Vpk[6][9][0])))+((
          ik[4][2][1]*Wpk[6][9][2])+((ik[4][0][1]*Wpk[6][9][0])+(ik[4][1][1]*
          Wpk[6][8][1]))))+((mk[5]*((Vpk[6][10][0]*Vpk[9][10][0])+(Vpk[6][10][2]
          *Vpk[9][10][2])))+((ik[5][2][1]*Wpk[6][10][2])+((ik[5][0][1]*
          Wpk[6][10][0])+(ik[5][1][1]*Wpk[6][8][1])))));
        mm[6][9] = (((mk[6]*((Vpk[6][11][2]*Vpk[9][11][2])+((Vpk[6][11][0]*
          Vpk[9][11][0])+(Vpk[6][11][1]*Vpk[9][11][1]))))+((IkWpk[9][11][2]*
          Wpk[6][11][2])+((IkWpk[9][11][0]*Wpk[6][10][0])+(IkWpk[9][11][1]*
          Wpk[6][11][1]))))+temp[0]);
        mm[6][10] = (((mk[5]*((rk[5][0]*Vpk[6][10][2])-(rk[5][2]*Vpk[6][10][0]))
          )+((ik[5][2][1]*Wpk[6][10][2])+((ik[5][0][1]*Wpk[6][10][0])+(
          ik[5][1][1]*Wpk[6][8][1]))))+((mk[6]*((Vpk[6][11][2]*Vpk[10][11][2])+(
          (Vpk[6][11][0]*Vpk[10][11][0])+(Vpk[6][11][1]*Vpk[10][11][1]))))+((
          IkWpk[10][11][2]*Wpk[6][11][2])+((IkWpk[10][11][0]*Wpk[6][10][0])+(
          IkWpk[10][11][1]*Wpk[6][11][1])))));
        mm[6][11] = ((mk[6]*((rk[6][2]*Vpk[6][11][1])-(rk[6][1]*Vpk[6][11][2])))
          +((ik[6][2][0]*Wpk[6][11][2])+((ik[6][0][0]*Wpk[6][10][0])+(
          ik[6][1][0]*Wpk[6][11][1]))));
        mm[6][12] = 0.;
        mm[6][13] = 0.;
        mm[6][14] = 0.;
        mm[6][15] = 0.;
        mm[6][16] = 0.;
        mm[6][17] = 0.;
        mm[6][18] = 0.;
        mm[6][19] = 0.;
        mm[6][20] = 0.;
        mm[6][21] = 0.;
        mm[6][22] = 0.;
        mm[6][23] = 0.;
        mm[6][24] = 0.;
        mm[6][25] = 0.;
        temp[0] = ((ik[2][1][1]+(mk[2]*((rk[2][0]*rk[2][0])+(rk[2][2]*rk[2][2]))
          ))+((mk[3]*((Vpk[7][8][2]*Vpk[7][8][2])+((Vpk[7][8][0]*Vpk[7][8][0])+(
          Vpk[7][8][1]*Vpk[7][8][1]))))+((IkWpk[7][8][1]*c8)-(IkWpk[7][8][2]*s8)
          )));
        temp[1] = (((mk[5]*((Vpk[7][10][2]*Vpk[7][10][2])+((Vpk[7][10][0]*
          Vpk[7][10][0])+(Vpk[7][10][1]*Vpk[7][10][1]))))+((IkWpk[7][10][2]*
          Wpk[7][10][2])+((IkWpk[7][10][0]*Wpk[7][10][0])+(IkWpk[7][10][1]*c8)))
          )+(temp[0]+((mk[4]*((Vpk[7][9][2]*Vpk[7][9][2])+((Vpk[7][9][0]*
          Vpk[7][9][0])+(Vpk[7][9][1]*Vpk[7][9][1]))))+((IkWpk[7][9][2]*
          Wpk[7][9][2])+((IkWpk[7][9][0]*Wpk[7][9][0])+(IkWpk[7][9][1]*c8))))));
        mm[7][7] = (((mk[6]*((Vpk[7][11][2]*Vpk[7][11][2])+((Vpk[7][11][0]*
          Vpk[7][11][0])+(Vpk[7][11][1]*Vpk[7][11][1]))))+((IkWpk[7][11][2]*
          Wpk[7][11][2])+((IkWpk[7][11][0]*Wpk[7][10][0])+(IkWpk[7][11][1]*
          Wpk[7][11][1]))))+temp[1]);
        temp[0] = (((mk[3]*((rk[3][2]*Vpk[7][8][1])-(rk[3][1]*Vpk[7][8][2])))+((
          ik[3][1][0]*c8)-(ik[3][2][0]*s8)))+((mk[4]*((Vpk[7][9][2]*Vpk[8][9][2]
          )+((Vpk[7][9][0]*Vpk[8][9][0])+(Vpk[7][9][1]*Vpk[8][9][1]))))+((
          IkWpk[8][9][2]*Wpk[7][9][2])+((IkWpk[8][9][0]*Wpk[7][9][0])+(
          IkWpk[8][9][1]*c8)))));
        mm[7][8] = (((mk[6]*((Vpk[7][11][2]*Vpk[8][11][2])+((Vpk[7][11][0]*
          Vpk[8][11][0])+(Vpk[7][11][1]*Vpk[8][11][1]))))+((IkWpk[8][11][2]*
          Wpk[7][11][2])+((IkWpk[8][11][0]*Wpk[7][10][0])+(IkWpk[8][11][1]*
          Wpk[7][11][1]))))+(((mk[5]*((Vpk[7][10][2]*Vpk[8][10][2])+((
          Vpk[7][10][0]*Vpk[8][10][0])+(Vpk[7][10][1]*Vpk[8][10][1]))))+((
          IkWpk[8][10][2]*Wpk[7][10][2])+((IkWpk[8][10][0]*Wpk[7][10][0])+(
          IkWpk[8][10][1]*c8))))+temp[0]));
        temp[0] = (((mk[4]*((rk[4][0]*Vpk[7][9][2])-(rk[4][2]*Vpk[7][9][0])))+((
          ik[4][2][1]*Wpk[7][9][2])+((ik[4][0][1]*Wpk[7][9][0])+(ik[4][1][1]*c8)
          )))+((mk[5]*((Vpk[7][10][0]*Vpk[9][10][0])+(Vpk[7][10][2]*
          Vpk[9][10][2])))+((ik[5][2][1]*Wpk[7][10][2])+((ik[5][0][1]*
          Wpk[7][10][0])+(ik[5][1][1]*c8)))));
        mm[7][9] = (((mk[6]*((Vpk[7][11][2]*Vpk[9][11][2])+((Vpk[7][11][0]*
          Vpk[9][11][0])+(Vpk[7][11][1]*Vpk[9][11][1]))))+((IkWpk[9][11][2]*
          Wpk[7][11][2])+((IkWpk[9][11][0]*Wpk[7][10][0])+(IkWpk[9][11][1]*
          Wpk[7][11][1]))))+temp[0]);
        mm[7][10] = (((mk[5]*((rk[5][0]*Vpk[7][10][2])-(rk[5][2]*Vpk[7][10][0]))
          )+((ik[5][2][1]*Wpk[7][10][2])+((ik[5][0][1]*Wpk[7][10][0])+(
          ik[5][1][1]*c8))))+((mk[6]*((Vpk[7][11][2]*Vpk[10][11][2])+((
          Vpk[7][11][0]*Vpk[10][11][0])+(Vpk[7][11][1]*Vpk[10][11][1]))))+((
          IkWpk[10][11][2]*Wpk[7][11][2])+((IkWpk[10][11][0]*Wpk[7][10][0])+(
          IkWpk[10][11][1]*Wpk[7][11][1])))));
        mm[7][11] = ((mk[6]*((rk[6][2]*Vpk[7][11][1])-(rk[6][1]*Vpk[7][11][2])))
          +((ik[6][2][0]*Wpk[7][11][2])+((ik[6][0][0]*Wpk[7][10][0])+(
          ik[6][1][0]*Wpk[7][11][1]))));
        mm[7][12] = 0.;
        mm[7][13] = 0.;
        mm[7][14] = 0.;
        mm[7][15] = 0.;
        mm[7][16] = 0.;
        mm[7][17] = 0.;
        mm[7][18] = 0.;
        mm[7][19] = 0.;
        mm[7][20] = 0.;
        mm[7][21] = 0.;
        mm[7][22] = 0.;
        mm[7][23] = 0.;
        mm[7][24] = 0.;
        mm[7][25] = 0.;
        temp[0] = (((ik[3][0][0]+(mk[3]*((rk[3][1]*rk[3][1])+(rk[3][2]*rk[3][2])
          )))+((mk[4]*((Vpk[8][9][2]*Vpk[8][9][2])+((Vpk[8][9][0]*Vpk[8][9][0])+
          (Vpk[8][9][1]*Vpk[8][9][1]))))+((IkWpk[8][9][0]*c9)+(IkWpk[8][9][2]*s9
          ))))+((mk[5]*((Vpk[8][10][2]*Vpk[8][10][2])+((Vpk[8][10][0]*
          Vpk[8][10][0])+(Vpk[8][10][1]*Vpk[8][10][1]))))+((IkWpk[8][10][0]*
          Wpk[8][10][0])+(IkWpk[8][10][2]*Wpk[8][10][2]))));
        mm[8][8] = (((mk[6]*((Vpk[8][11][2]*Vpk[8][11][2])+((Vpk[8][11][0]*
          Vpk[8][11][0])+(Vpk[8][11][1]*Vpk[8][11][1]))))+((IkWpk[8][11][2]*
          Wpk[8][11][2])+((IkWpk[8][11][0]*Wpk[8][10][0])+(IkWpk[8][11][1]*
          Wpk[8][11][1]))))+temp[0]);
        temp[0] = (((mk[4]*((rk[4][0]*Vpk[8][9][2])-(rk[4][2]*Vpk[8][9][0])))+((
          ik[4][0][1]*c9)+(ik[4][2][1]*s9)))+((mk[5]*((Vpk[8][10][0]*
          Vpk[9][10][0])+(Vpk[8][10][2]*Vpk[9][10][2])))+((ik[5][0][1]*
          Wpk[8][10][0])+(ik[5][2][1]*Wpk[8][10][2]))));
        mm[8][9] = (((mk[6]*((Vpk[8][11][2]*Vpk[9][11][2])+((Vpk[8][11][0]*
          Vpk[9][11][0])+(Vpk[8][11][1]*Vpk[9][11][1]))))+((IkWpk[9][11][2]*
          Wpk[8][11][2])+((IkWpk[9][11][0]*Wpk[8][10][0])+(IkWpk[9][11][1]*
          Wpk[8][11][1]))))+temp[0]);
        mm[8][10] = (((mk[5]*((rk[5][0]*Vpk[8][10][2])-(rk[5][2]*Vpk[8][10][0]))
          )+((ik[5][0][1]*Wpk[8][10][0])+(ik[5][2][1]*Wpk[8][10][2])))+((mk[6]*(
          (Vpk[8][11][2]*Vpk[10][11][2])+((Vpk[8][11][0]*Vpk[10][11][0])+(
          Vpk[8][11][1]*Vpk[10][11][1]))))+((IkWpk[10][11][2]*Wpk[8][11][2])+((
          IkWpk[10][11][0]*Wpk[8][10][0])+(IkWpk[10][11][1]*Wpk[8][11][1])))));
        mm[8][11] = ((mk[6]*((rk[6][2]*Vpk[8][11][1])-(rk[6][1]*Vpk[8][11][2])))
          +((ik[6][2][0]*Wpk[8][11][2])+((ik[6][0][0]*Wpk[8][10][0])+(
          ik[6][1][0]*Wpk[8][11][1]))));
        mm[8][12] = 0.;
        mm[8][13] = 0.;
        mm[8][14] = 0.;
        mm[8][15] = 0.;
        mm[8][16] = 0.;
        mm[8][17] = 0.;
        mm[8][18] = 0.;
        mm[8][19] = 0.;
        mm[8][20] = 0.;
        mm[8][21] = 0.;
        mm[8][22] = 0.;
        mm[8][23] = 0.;
        mm[8][24] = 0.;
        mm[8][25] = 0.;
        mm[9][9] = (((ik[4][1][1]+(mk[4]*((rk[4][0]*rk[4][0])+(rk[4][2]*rk[4][2]
          ))))+(ik[5][1][1]+(mk[5]*((Vpk[9][10][0]*Vpk[9][10][0])+(Vpk[9][10][2]
          *Vpk[9][10][2])))))+((mk[6]*((Vpk[9][11][2]*Vpk[9][11][2])+((
          Vpk[9][11][0]*Vpk[9][11][0])+(Vpk[9][11][1]*Vpk[9][11][1]))))+((
          IkWpk[9][11][1]*c11)-(IkWpk[9][11][2]*s11))));
        mm[9][10] = ((ik[5][1][1]+(mk[5]*((rk[5][0]*Vpk[9][10][2])-(rk[5][2]*
          Vpk[9][10][0]))))+((mk[6]*((Vpk[9][11][2]*Vpk[10][11][2])+((
          Vpk[9][11][0]*Vpk[10][11][0])+(Vpk[9][11][1]*Vpk[10][11][1]))))+((
          IkWpk[10][11][1]*c11)-(IkWpk[10][11][2]*s11))));
        mm[9][11] = ((mk[6]*((rk[6][2]*Vpk[9][11][1])-(rk[6][1]*Vpk[9][11][2])))
          +((ik[6][1][0]*c11)-(ik[6][2][0]*s11)));
        mm[9][12] = 0.;
        mm[9][13] = 0.;
        mm[9][14] = 0.;
        mm[9][15] = 0.;
        mm[9][16] = 0.;
        mm[9][17] = 0.;
        mm[9][18] = 0.;
        mm[9][19] = 0.;
        mm[9][20] = 0.;
        mm[9][21] = 0.;
        mm[9][22] = 0.;
        mm[9][23] = 0.;
        mm[9][24] = 0.;
        mm[9][25] = 0.;
        mm[10][10] = ((ik[5][1][1]+(mk[5]*((rk[5][0]*rk[5][0])+(rk[5][2]*
          rk[5][2]))))+((mk[6]*((Vpk[10][11][2]*Vpk[10][11][2])+((Vpk[10][11][0]
          *Vpk[10][11][0])+(Vpk[10][11][1]*Vpk[10][11][1]))))+((IkWpk[10][11][1]
          *c11)-(IkWpk[10][11][2]*s11))));
        mm[10][11] = ((mk[6]*((rk[6][2]*Vpk[10][11][1])-(rk[6][1]*Vpk[10][11][2]
          )))+((ik[6][1][0]*c11)-(ik[6][2][0]*s11)));
        mm[10][12] = 0.;
        mm[10][13] = 0.;
        mm[10][14] = 0.;
        mm[10][15] = 0.;
        mm[10][16] = 0.;
        mm[10][17] = 0.;
        mm[10][18] = 0.;
        mm[10][19] = 0.;
        mm[10][20] = 0.;
        mm[10][21] = 0.;
        mm[10][22] = 0.;
        mm[10][23] = 0.;
        mm[10][24] = 0.;
        mm[10][25] = 0.;
        mm[11][11] = (ik[6][0][0]+(mk[6]*((rk[6][1]*rk[6][1])+(rk[6][2]*rk[6][2]
          ))));
        mm[11][12] = 0.;
        mm[11][13] = 0.;
        mm[11][14] = 0.;
        mm[11][15] = 0.;
        mm[11][16] = 0.;
        mm[11][17] = 0.;
        mm[11][18] = 0.;
        mm[11][19] = 0.;
        mm[11][20] = 0.;
        mm[11][21] = 0.;
        mm[11][22] = 0.;
        mm[11][23] = 0.;
        mm[11][24] = 0.;
        mm[11][25] = 0.;
        temp[0] = ((ik[7][2][2]+(mk[7]*((rk[7][0]*rk[7][0])+(rk[7][1]*rk[7][1]))
          ))+((mk[8]*((Vpk[12][13][2]*Vpk[12][13][2])+((Vpk[12][13][0]*
          Vpk[12][13][0])+(Vpk[12][13][1]*Vpk[12][13][1]))))+((IkWpk[12][13][2]*
          c13)-(IkWpk[12][13][0]*s13))));
        temp[1] = (((mk[10]*((Vpk[12][15][2]*Vpk[12][15][2])+((Vpk[12][15][0]*
          Vpk[12][15][0])+(Vpk[12][15][1]*Vpk[12][15][1]))))+((IkWpk[12][15][2]*
          Wpk[12][15][2])+((IkWpk[12][15][0]*Wpk[12][15][0])+(IkWpk[12][15][1]*
          Wpk[12][14][1]))))+(temp[0]+((mk[9]*((Vpk[12][14][2]*Vpk[12][14][2])+(
          (Vpk[12][14][0]*Vpk[12][14][0])+(Vpk[12][14][1]*Vpk[12][14][1]))))+((
          IkWpk[12][14][2]*Wpk[12][14][2])+((IkWpk[12][14][1]*Wpk[12][14][1])-(
          IkWpk[12][14][0]*s13))))));
        temp[2] = (((mk[11]*((Vpk[12][16][2]*Vpk[12][16][2])+((Vpk[12][16][0]*
          Vpk[12][16][0])+(Vpk[12][16][1]*Vpk[12][16][1]))))+((IkWpk[12][16][2]*
          Wpk[12][16][2])+((IkWpk[12][16][0]*Wpk[12][16][0])+(IkWpk[12][16][1]*
          Wpk[12][14][1]))))+temp[1]);
        mm[12][12] = (((mk[12]*((Vpk[12][17][2]*Vpk[12][17][2])+((Vpk[12][17][0]
          *Vpk[12][17][0])+(Vpk[12][17][1]*Vpk[12][17][1]))))+((IkWpk[12][17][2]
          *Wpk[12][17][2])+((IkWpk[12][17][0]*Wpk[12][16][0])+(IkWpk[12][17][1]*
          Wpk[12][17][1]))))+temp[2]);
        temp[0] = (((mk[8]*((rk[8][0]*Vpk[12][13][2])-(rk[8][2]*Vpk[12][13][0]))
          )+((ik[8][2][1]*c13)-(ik[8][0][1]*s13)))+((mk[9]*((Vpk[12][14][2]*
          Vpk[13][14][2])+((Vpk[12][14][0]*Vpk[13][14][0])+(Vpk[12][14][1]*
          Vpk[13][14][1]))))+((IkWpk[13][14][2]*Wpk[12][14][2])+((
          IkWpk[13][14][1]*Wpk[12][14][1])-(IkWpk[13][14][0]*s13)))));
        temp[1] = (((mk[10]*((Vpk[12][15][2]*Vpk[13][15][2])+((Vpk[12][15][0]*
          Vpk[13][15][0])+(Vpk[12][15][1]*Vpk[13][15][1]))))+((IkWpk[13][15][2]*
          Wpk[12][15][2])+((IkWpk[13][15][0]*Wpk[12][15][0])+(IkWpk[13][15][1]*
          Wpk[12][14][1]))))+temp[0]);
        temp[2] = (((mk[11]*((Vpk[12][16][2]*Vpk[13][16][2])+((Vpk[12][16][0]*
          Vpk[13][16][0])+(Vpk[12][16][1]*Vpk[13][16][1]))))+((IkWpk[13][16][2]*
          Wpk[12][16][2])+((IkWpk[13][16][0]*Wpk[12][16][0])+(IkWpk[13][16][1]*
          Wpk[12][14][1]))))+temp[1]);
        mm[12][13] = (((mk[12]*((Vpk[12][17][2]*Vpk[13][17][2])+((Vpk[12][17][0]
          *Vpk[13][17][0])+(Vpk[12][17][1]*Vpk[13][17][1]))))+((IkWpk[13][17][2]
          *Wpk[12][17][2])+((IkWpk[13][17][0]*Wpk[12][16][0])+(IkWpk[13][17][1]*
          Wpk[12][17][1]))))+temp[2]);
        temp[0] = (((mk[9]*((rk[9][2]*Vpk[12][14][1])-(rk[9][1]*Vpk[12][14][2]))
          )+((ik[9][2][0]*Wpk[12][14][2])+((ik[9][1][0]*Wpk[12][14][1])-(
          ik[9][0][0]*s13))))+((mk[10]*((Vpk[12][15][2]*Vpk[14][15][2])+((
          Vpk[12][15][0]*Vpk[14][15][0])+(Vpk[12][15][1]*Vpk[14][15][1]))))+((
          IkWpk[14][15][2]*Wpk[12][15][2])+((IkWpk[14][15][0]*Wpk[12][15][0])+(
          IkWpk[14][15][1]*Wpk[12][14][1])))));
        temp[1] = (((mk[11]*((Vpk[12][16][2]*Vpk[14][16][2])+((Vpk[12][16][0]*
          Vpk[14][16][0])+(Vpk[12][16][1]*Vpk[14][16][1]))))+((IkWpk[14][16][2]*
          Wpk[12][16][2])+((IkWpk[14][16][0]*Wpk[12][16][0])+(IkWpk[14][16][1]*
          Wpk[12][14][1]))))+temp[0]);
        mm[12][14] = (((mk[12]*((Vpk[12][17][2]*Vpk[14][17][2])+((Vpk[12][17][0]
          *Vpk[14][17][0])+(Vpk[12][17][1]*Vpk[14][17][1]))))+((IkWpk[14][17][2]
          *Wpk[12][17][2])+((IkWpk[14][17][0]*Wpk[12][16][0])+(IkWpk[14][17][1]*
          Wpk[12][17][1]))))+temp[1]);
        temp[0] = (((mk[10]*((rk[10][0]*Vpk[12][15][2])-(rk[10][2]*
          Vpk[12][15][0])))+((ik[10][2][1]*Wpk[12][15][2])+((ik[10][0][1]*
          Wpk[12][15][0])+(ik[10][1][1]*Wpk[12][14][1]))))+((mk[11]*((
          Vpk[12][16][0]*Vpk[15][16][0])+(Vpk[12][16][2]*Vpk[15][16][2])))+((
          ik[11][2][1]*Wpk[12][16][2])+((ik[11][0][1]*Wpk[12][16][0])+(
          ik[11][1][1]*Wpk[12][14][1])))));
        mm[12][15] = (((mk[12]*((Vpk[12][17][2]*Vpk[15][17][2])+((Vpk[12][17][0]
          *Vpk[15][17][0])+(Vpk[12][17][1]*Vpk[15][17][1]))))+((IkWpk[15][17][2]
          *Wpk[12][17][2])+((IkWpk[15][17][0]*Wpk[12][16][0])+(IkWpk[15][17][1]*
          Wpk[12][17][1]))))+temp[0]);
        mm[12][16] = (((mk[11]*((rk[11][0]*Vpk[12][16][2])-(rk[11][2]*
          Vpk[12][16][0])))+((ik[11][2][1]*Wpk[12][16][2])+((ik[11][0][1]*
          Wpk[12][16][0])+(ik[11][1][1]*Wpk[12][14][1]))))+((mk[12]*((
          Vpk[12][17][2]*Vpk[16][17][2])+((Vpk[12][17][0]*Vpk[16][17][0])+(
          Vpk[12][17][1]*Vpk[16][17][1]))))+((IkWpk[16][17][2]*Wpk[12][17][2])+(
          (IkWpk[16][17][0]*Wpk[12][16][0])+(IkWpk[16][17][1]*Wpk[12][17][1]))))
          );
        mm[12][17] = ((mk[12]*((rk[12][2]*Vpk[12][17][1])-(rk[12][1]*
          Vpk[12][17][2])))+((ik[12][2][0]*Wpk[12][17][2])+((ik[12][0][0]*
          Wpk[12][16][0])+(ik[12][1][0]*Wpk[12][17][1]))));
        mm[12][18] = 0.;
        mm[12][19] = 0.;
        mm[12][20] = 0.;
        mm[12][21] = 0.;
        mm[12][22] = 0.;
        mm[12][23] = 0.;
        mm[12][24] = 0.;
        mm[12][25] = 0.;
        temp[0] = ((ik[8][1][1]+(mk[8]*((rk[8][0]*rk[8][0])+(rk[8][2]*rk[8][2]))
          ))+((mk[9]*((Vpk[13][14][2]*Vpk[13][14][2])+((Vpk[13][14][0]*
          Vpk[13][14][0])+(Vpk[13][14][1]*Vpk[13][14][1]))))+((IkWpk[13][14][1]*
          c14)-(IkWpk[13][14][2]*s14))));
        temp[1] = (((mk[11]*((Vpk[13][16][2]*Vpk[13][16][2])+((Vpk[13][16][0]*
          Vpk[13][16][0])+(Vpk[13][16][1]*Vpk[13][16][1]))))+((IkWpk[13][16][2]*
          Wpk[13][16][2])+((IkWpk[13][16][0]*Wpk[13][16][0])+(IkWpk[13][16][1]*
          c14))))+(temp[0]+((mk[10]*((Vpk[13][15][2]*Vpk[13][15][2])+((
          Vpk[13][15][0]*Vpk[13][15][0])+(Vpk[13][15][1]*Vpk[13][15][1]))))+((
          IkWpk[13][15][2]*Wpk[13][15][2])+((IkWpk[13][15][0]*Wpk[13][15][0])+(
          IkWpk[13][15][1]*c14))))));
        mm[13][13] = (((mk[12]*((Vpk[13][17][2]*Vpk[13][17][2])+((Vpk[13][17][0]
          *Vpk[13][17][0])+(Vpk[13][17][1]*Vpk[13][17][1]))))+((IkWpk[13][17][2]
          *Wpk[13][17][2])+((IkWpk[13][17][0]*Wpk[13][16][0])+(IkWpk[13][17][1]*
          Wpk[13][17][1]))))+temp[1]);
        temp[0] = (((mk[9]*((rk[9][2]*Vpk[13][14][1])-(rk[9][1]*Vpk[13][14][2]))
          )+((ik[9][1][0]*c14)-(ik[9][2][0]*s14)))+((mk[10]*((Vpk[13][15][2]*
          Vpk[14][15][2])+((Vpk[13][15][0]*Vpk[14][15][0])+(Vpk[13][15][1]*
          Vpk[14][15][1]))))+((IkWpk[14][15][2]*Wpk[13][15][2])+((
          IkWpk[14][15][0]*Wpk[13][15][0])+(IkWpk[14][15][1]*c14)))));
        mm[13][14] = (((mk[12]*((Vpk[13][17][2]*Vpk[14][17][2])+((Vpk[13][17][0]
          *Vpk[14][17][0])+(Vpk[13][17][1]*Vpk[14][17][1]))))+((IkWpk[14][17][2]
          *Wpk[13][17][2])+((IkWpk[14][17][0]*Wpk[13][16][0])+(IkWpk[14][17][1]*
          Wpk[13][17][1]))))+(((mk[11]*((Vpk[13][16][2]*Vpk[14][16][2])+((
          Vpk[13][16][0]*Vpk[14][16][0])+(Vpk[13][16][1]*Vpk[14][16][1]))))+((
          IkWpk[14][16][2]*Wpk[13][16][2])+((IkWpk[14][16][0]*Wpk[13][16][0])+(
          IkWpk[14][16][1]*c14))))+temp[0]));
        temp[0] = (((mk[10]*((rk[10][0]*Vpk[13][15][2])-(rk[10][2]*
          Vpk[13][15][0])))+((ik[10][2][1]*Wpk[13][15][2])+((ik[10][0][1]*
          Wpk[13][15][0])+(ik[10][1][1]*c14))))+((mk[11]*((Vpk[13][16][0]*
          Vpk[15][16][0])+(Vpk[13][16][2]*Vpk[15][16][2])))+((ik[11][2][1]*
          Wpk[13][16][2])+((ik[11][0][1]*Wpk[13][16][0])+(ik[11][1][1]*c14)))));
        mm[13][15] = (((mk[12]*((Vpk[13][17][2]*Vpk[15][17][2])+((Vpk[13][17][0]
          *Vpk[15][17][0])+(Vpk[13][17][1]*Vpk[15][17][1]))))+((IkWpk[15][17][2]
          *Wpk[13][17][2])+((IkWpk[15][17][0]*Wpk[13][16][0])+(IkWpk[15][17][1]*
          Wpk[13][17][1]))))+temp[0]);
        mm[13][16] = (((mk[11]*((rk[11][0]*Vpk[13][16][2])-(rk[11][2]*
          Vpk[13][16][0])))+((ik[11][2][1]*Wpk[13][16][2])+((ik[11][0][1]*
          Wpk[13][16][0])+(ik[11][1][1]*c14))))+((mk[12]*((Vpk[13][17][2]*
          Vpk[16][17][2])+((Vpk[13][17][0]*Vpk[16][17][0])+(Vpk[13][17][1]*
          Vpk[16][17][1]))))+((IkWpk[16][17][2]*Wpk[13][17][2])+((
          IkWpk[16][17][0]*Wpk[13][16][0])+(IkWpk[16][17][1]*Wpk[13][17][1])))))
          ;
        mm[13][17] = ((mk[12]*((rk[12][2]*Vpk[13][17][1])-(rk[12][1]*
          Vpk[13][17][2])))+((ik[12][2][0]*Wpk[13][17][2])+((ik[12][0][0]*
          Wpk[13][16][0])+(ik[12][1][0]*Wpk[13][17][1]))));
        mm[13][18] = 0.;
        mm[13][19] = 0.;
        mm[13][20] = 0.;
        mm[13][21] = 0.;
        mm[13][22] = 0.;
        mm[13][23] = 0.;
        mm[13][24] = 0.;
        mm[13][25] = 0.;
        temp[0] = (((ik[9][0][0]+(mk[9]*((rk[9][1]*rk[9][1])+(rk[9][2]*rk[9][2])
          )))+((mk[10]*((Vpk[14][15][2]*Vpk[14][15][2])+((Vpk[14][15][0]*
          Vpk[14][15][0])+(Vpk[14][15][1]*Vpk[14][15][1]))))+((IkWpk[14][15][0]*
          c15)+(IkWpk[14][15][2]*s15))))+((mk[11]*((Vpk[14][16][2]*
          Vpk[14][16][2])+((Vpk[14][16][0]*Vpk[14][16][0])+(Vpk[14][16][1]*
          Vpk[14][16][1]))))+((IkWpk[14][16][0]*Wpk[14][16][0])+(
          IkWpk[14][16][2]*Wpk[14][16][2]))));
        mm[14][14] = (((mk[12]*((Vpk[14][17][2]*Vpk[14][17][2])+((Vpk[14][17][0]
          *Vpk[14][17][0])+(Vpk[14][17][1]*Vpk[14][17][1]))))+((IkWpk[14][17][2]
          *Wpk[14][17][2])+((IkWpk[14][17][0]*Wpk[14][16][0])+(IkWpk[14][17][1]*
          Wpk[14][17][1]))))+temp[0]);
        temp[0] = (((mk[10]*((rk[10][0]*Vpk[14][15][2])-(rk[10][2]*
          Vpk[14][15][0])))+((ik[10][0][1]*c15)+(ik[10][2][1]*s15)))+((mk[11]*((
          Vpk[14][16][0]*Vpk[15][16][0])+(Vpk[14][16][2]*Vpk[15][16][2])))+((
          ik[11][0][1]*Wpk[14][16][0])+(ik[11][2][1]*Wpk[14][16][2]))));
        mm[14][15] = (((mk[12]*((Vpk[14][17][2]*Vpk[15][17][2])+((Vpk[14][17][0]
          *Vpk[15][17][0])+(Vpk[14][17][1]*Vpk[15][17][1]))))+((IkWpk[15][17][2]
          *Wpk[14][17][2])+((IkWpk[15][17][0]*Wpk[14][16][0])+(IkWpk[15][17][1]*
          Wpk[14][17][1]))))+temp[0]);
        mm[14][16] = (((mk[11]*((rk[11][0]*Vpk[14][16][2])-(rk[11][2]*
          Vpk[14][16][0])))+((ik[11][0][1]*Wpk[14][16][0])+(ik[11][2][1]*
          Wpk[14][16][2])))+((mk[12]*((Vpk[14][17][2]*Vpk[16][17][2])+((
          Vpk[14][17][0]*Vpk[16][17][0])+(Vpk[14][17][1]*Vpk[16][17][1]))))+((
          IkWpk[16][17][2]*Wpk[14][17][2])+((IkWpk[16][17][0]*Wpk[14][16][0])+(
          IkWpk[16][17][1]*Wpk[14][17][1])))));
        mm[14][17] = ((mk[12]*((rk[12][2]*Vpk[14][17][1])-(rk[12][1]*
          Vpk[14][17][2])))+((ik[12][2][0]*Wpk[14][17][2])+((ik[12][0][0]*
          Wpk[14][16][0])+(ik[12][1][0]*Wpk[14][17][1]))));
        mm[14][18] = 0.;
        mm[14][19] = 0.;
        mm[14][20] = 0.;
        mm[14][21] = 0.;
        mm[14][22] = 0.;
        mm[14][23] = 0.;
        mm[14][24] = 0.;
        mm[14][25] = 0.;
        mm[15][15] = (((ik[10][1][1]+(mk[10]*((rk[10][0]*rk[10][0])+(rk[10][2]*
          rk[10][2]))))+(ik[11][1][1]+(mk[11]*((Vpk[15][16][0]*Vpk[15][16][0])+(
          Vpk[15][16][2]*Vpk[15][16][2])))))+((mk[12]*((Vpk[15][17][2]*
          Vpk[15][17][2])+((Vpk[15][17][0]*Vpk[15][17][0])+(Vpk[15][17][1]*
          Vpk[15][17][1]))))+((IkWpk[15][17][1]*c17)-(IkWpk[15][17][2]*s17))));
        mm[15][16] = ((ik[11][1][1]+(mk[11]*((rk[11][0]*Vpk[15][16][2])-(
          rk[11][2]*Vpk[15][16][0]))))+((mk[12]*((Vpk[15][17][2]*Vpk[16][17][2])
          +((Vpk[15][17][0]*Vpk[16][17][0])+(Vpk[15][17][1]*Vpk[16][17][1]))))+(
          (IkWpk[16][17][1]*c17)-(IkWpk[16][17][2]*s17))));
        mm[15][17] = ((mk[12]*((rk[12][2]*Vpk[15][17][1])-(rk[12][1]*
          Vpk[15][17][2])))+((ik[12][1][0]*c17)-(ik[12][2][0]*s17)));
        mm[15][18] = 0.;
        mm[15][19] = 0.;
        mm[15][20] = 0.;
        mm[15][21] = 0.;
        mm[15][22] = 0.;
        mm[15][23] = 0.;
        mm[15][24] = 0.;
        mm[15][25] = 0.;
        mm[16][16] = ((ik[11][1][1]+(mk[11]*((rk[11][0]*rk[11][0])+(rk[11][2]*
          rk[11][2]))))+((mk[12]*((Vpk[16][17][2]*Vpk[16][17][2])+((
          Vpk[16][17][0]*Vpk[16][17][0])+(Vpk[16][17][1]*Vpk[16][17][1]))))+((
          IkWpk[16][17][1]*c17)-(IkWpk[16][17][2]*s17))));
        mm[16][17] = ((mk[12]*((rk[12][2]*Vpk[16][17][1])-(rk[12][1]*
          Vpk[16][17][2])))+((ik[12][1][0]*c17)-(ik[12][2][0]*s17)));
        mm[16][18] = 0.;
        mm[16][19] = 0.;
        mm[16][20] = 0.;
        mm[16][21] = 0.;
        mm[16][22] = 0.;
        mm[16][23] = 0.;
        mm[16][24] = 0.;
        mm[16][25] = 0.;
        mm[17][17] = (ik[12][0][0]+(mk[12]*((rk[12][1]*rk[12][1])+(rk[12][2]*
          rk[12][2]))));
        mm[17][18] = 0.;
        mm[17][19] = 0.;
        mm[17][20] = 0.;
        mm[17][21] = 0.;
        mm[17][22] = 0.;
        mm[17][23] = 0.;
        mm[17][24] = 0.;
        mm[17][25] = 0.;
        temp[0] = ((ik[13][1][1]+(mk[13]*((rk[13][0]*rk[13][0])+(rk[13][2]*
          rk[13][2]))))+((mk[14]*((Vpk[18][19][2]*Vpk[18][19][2])+((
          Vpk[18][19][0]*Vpk[18][19][0])+(Vpk[18][19][1]*Vpk[18][19][1]))))+((
          IkWpk[18][19][1]*c19)-(IkWpk[18][19][2]*s19))));
        mm[18][18] = (((mk[16]*((Vpk[18][21][2]*Vpk[18][21][2])+((Vpk[18][21][0]
          *Vpk[18][21][0])+(Vpk[18][21][1]*Vpk[18][21][1]))))+((IkWpk[18][21][2]
          *Wpk[18][20][2])+((IkWpk[18][21][0]*Wpk[18][21][0])+(IkWpk[18][21][1]*
          Wpk[18][21][1]))))+(temp[0]+((mk[15]*((Vpk[18][20][2]*Vpk[18][20][2])+
          ((Vpk[18][20][0]*Vpk[18][20][0])+(Vpk[18][20][1]*Vpk[18][20][1]))))+((
          IkWpk[18][20][2]*Wpk[18][20][2])+((IkWpk[18][20][0]*Wpk[18][20][0])+(
          IkWpk[18][20][1]*c19))))));
        temp[0] = (((mk[14]*((rk[14][2]*Vpk[18][19][1])-(rk[14][1]*
          Vpk[18][19][2])))+((ik[14][1][0]*c19)-(ik[14][2][0]*s19)))+((mk[15]*((
          Vpk[18][20][2]*Vpk[19][20][2])+((Vpk[18][20][0]*Vpk[19][20][0])+(
          Vpk[18][20][1]*Vpk[19][20][1]))))+((IkWpk[19][20][2]*Wpk[18][20][2])+(
          (IkWpk[19][20][0]*Wpk[18][20][0])+(IkWpk[19][20][1]*c19)))));
        mm[18][19] = (((mk[16]*((Vpk[18][21][2]*Vpk[19][21][2])+((Vpk[18][21][0]
          *Vpk[19][21][0])+(Vpk[18][21][1]*Vpk[19][21][1]))))+((IkWpk[19][21][2]
          *Wpk[18][20][2])+((IkWpk[19][21][0]*Wpk[18][21][0])+(IkWpk[19][21][1]*
          Wpk[18][21][1]))))+temp[0]);
        mm[18][20] = (((mk[15]*((rk[15][0]*Vpk[18][20][2])-(rk[15][2]*
          Vpk[18][20][0])))+((ik[15][2][1]*Wpk[18][20][2])+((ik[15][0][1]*
          Wpk[18][20][0])+(ik[15][1][1]*c19))))+((mk[16]*((Vpk[18][21][2]*
          Vpk[20][21][2])+((Vpk[18][21][0]*Vpk[20][21][0])+(Vpk[18][21][1]*
          Vpk[20][21][1]))))+((IkWpk[20][21][2]*Wpk[18][20][2])+((
          IkWpk[20][21][0]*Wpk[18][21][0])+(IkWpk[20][21][1]*Wpk[18][21][1])))))
          ;
        mm[18][21] = ((mk[16]*((rk[16][1]*Vpk[18][21][0])-(rk[16][0]*
          Vpk[18][21][1])))+((ik[16][2][2]*Wpk[18][20][2])+((ik[16][0][2]*
          Wpk[18][21][0])+(ik[16][1][2]*Wpk[18][21][1]))));
        mm[18][22] = 0.;
        mm[18][23] = 0.;
        mm[18][24] = 0.;
        mm[18][25] = 0.;
        temp[0] = ((ik[14][0][0]+(mk[14]*((rk[14][1]*rk[14][1])+(rk[14][2]*
          rk[14][2]))))+((mk[15]*((Vpk[19][20][2]*Vpk[19][20][2])+((
          Vpk[19][20][0]*Vpk[19][20][0])+(Vpk[19][20][1]*Vpk[19][20][1]))))+((
          IkWpk[19][20][0]*c20)+(IkWpk[19][20][2]*s20))));
        mm[19][19] = (temp[0]+((mk[16]*((Vpk[19][21][2]*Vpk[19][21][2])+((
          Vpk[19][21][0]*Vpk[19][21][0])+(Vpk[19][21][1]*Vpk[19][21][1]))))+((
          IkWpk[19][21][2]*s20)+((IkWpk[19][21][0]*Wpk[19][21][0])+(
          IkWpk[19][21][1]*Wpk[19][21][1])))));
        mm[19][20] = (((mk[15]*((rk[15][0]*Vpk[19][20][2])-(rk[15][2]*
          Vpk[19][20][0])))+((ik[15][0][1]*c20)+(ik[15][2][1]*s20)))+((mk[16]*((
          Vpk[19][21][2]*Vpk[20][21][2])+((Vpk[19][21][0]*Vpk[20][21][0])+(
          Vpk[19][21][1]*Vpk[20][21][1]))))+((IkWpk[20][21][2]*s20)+((
          IkWpk[20][21][0]*Wpk[19][21][0])+(IkWpk[20][21][1]*Wpk[19][21][1])))))
          ;
        mm[19][21] = ((mk[16]*((rk[16][1]*Vpk[19][21][0])-(rk[16][0]*
          Vpk[19][21][1])))+((ik[16][2][2]*s20)+((ik[16][0][2]*Wpk[19][21][0])+(
          ik[16][1][2]*Wpk[19][21][1]))));
        mm[19][22] = 0.;
        mm[19][23] = 0.;
        mm[19][24] = 0.;
        mm[19][25] = 0.;
        mm[20][20] = ((ik[15][1][1]+(mk[15]*((rk[15][0]*rk[15][0])+(rk[15][2]*
          rk[15][2]))))+((mk[16]*((Vpk[20][21][2]*Vpk[20][21][2])+((
          Vpk[20][21][0]*Vpk[20][21][0])+(Vpk[20][21][1]*Vpk[20][21][1]))))+((
          IkWpk[20][21][0]*s21)+(IkWpk[20][21][1]*c21))));
        mm[20][21] = ((mk[16]*((rk[16][1]*Vpk[20][21][0])-(rk[16][0]*
          Vpk[20][21][1])))+((ik[16][0][2]*s21)+(ik[16][1][2]*c21)));
        mm[20][22] = 0.;
        mm[20][23] = 0.;
        mm[20][24] = 0.;
        mm[20][25] = 0.;
        mm[21][21] = (ik[16][2][2]+(mk[16]*((rk[16][0]*rk[16][0])+(rk[16][1]*
          rk[16][1]))));
        mm[21][22] = 0.;
        mm[21][23] = 0.;
        mm[21][24] = 0.;
        mm[21][25] = 0.;
        temp[0] = ((ik[17][1][1]+(mk[17]*((rk[17][0]*rk[17][0])+(rk[17][2]*
          rk[17][2]))))+((mk[18]*((Vpk[22][23][2]*Vpk[22][23][2])+((
          Vpk[22][23][0]*Vpk[22][23][0])+(Vpk[22][23][1]*Vpk[22][23][1]))))+((
          IkWpk[22][23][1]*c23)-(IkWpk[22][23][2]*s23))));
        mm[22][22] = (((mk[20]*((Vpk[22][25][2]*Vpk[22][25][2])+((Vpk[22][25][0]
          *Vpk[22][25][0])+(Vpk[22][25][1]*Vpk[22][25][1]))))+((IkWpk[22][25][2]
          *Wpk[22][24][2])+((IkWpk[22][25][0]*Wpk[22][25][0])+(IkWpk[22][25][1]*
          Wpk[22][25][1]))))+(temp[0]+((mk[19]*((Vpk[22][24][2]*Vpk[22][24][2])+
          ((Vpk[22][24][0]*Vpk[22][24][0])+(Vpk[22][24][1]*Vpk[22][24][1]))))+((
          IkWpk[22][24][2]*Wpk[22][24][2])+((IkWpk[22][24][0]*Wpk[22][24][0])+(
          IkWpk[22][24][1]*c23))))));
        temp[0] = (((mk[18]*((rk[18][2]*Vpk[22][23][1])-(rk[18][1]*
          Vpk[22][23][2])))+((ik[18][1][0]*c23)-(ik[18][2][0]*s23)))+((mk[19]*((
          Vpk[22][24][2]*Vpk[23][24][2])+((Vpk[22][24][0]*Vpk[23][24][0])+(
          Vpk[22][24][1]*Vpk[23][24][1]))))+((IkWpk[23][24][2]*Wpk[22][24][2])+(
          (IkWpk[23][24][0]*Wpk[22][24][0])+(IkWpk[23][24][1]*c23)))));
        mm[22][23] = (((mk[20]*((Vpk[22][25][2]*Vpk[23][25][2])+((Vpk[22][25][0]
          *Vpk[23][25][0])+(Vpk[22][25][1]*Vpk[23][25][1]))))+((IkWpk[23][25][2]
          *Wpk[22][24][2])+((IkWpk[23][25][0]*Wpk[22][25][0])+(IkWpk[23][25][1]*
          Wpk[22][25][1]))))+temp[0]);
        mm[22][24] = (((mk[19]*((rk[19][0]*Vpk[22][24][2])-(rk[19][2]*
          Vpk[22][24][0])))+((ik[19][2][1]*Wpk[22][24][2])+((ik[19][0][1]*
          Wpk[22][24][0])+(ik[19][1][1]*c23))))+((mk[20]*((Vpk[22][25][2]*
          Vpk[24][25][2])+((Vpk[22][25][0]*Vpk[24][25][0])+(Vpk[22][25][1]*
          Vpk[24][25][1]))))+((IkWpk[24][25][2]*Wpk[22][24][2])+((
          IkWpk[24][25][0]*Wpk[22][25][0])+(IkWpk[24][25][1]*Wpk[22][25][1])))))
          ;
        mm[22][25] = ((mk[20]*((rk[20][1]*Vpk[22][25][0])-(rk[20][0]*
          Vpk[22][25][1])))+((ik[20][2][2]*Wpk[22][24][2])+((ik[20][0][2]*
          Wpk[22][25][0])+(ik[20][1][2]*Wpk[22][25][1]))));
        temp[0] = ((ik[18][0][0]+(mk[18]*((rk[18][1]*rk[18][1])+(rk[18][2]*
          rk[18][2]))))+((mk[19]*((Vpk[23][24][2]*Vpk[23][24][2])+((
          Vpk[23][24][0]*Vpk[23][24][0])+(Vpk[23][24][1]*Vpk[23][24][1]))))+((
          IkWpk[23][24][0]*c24)+(IkWpk[23][24][2]*s24))));
        mm[23][23] = (temp[0]+((mk[20]*((Vpk[23][25][2]*Vpk[23][25][2])+((
          Vpk[23][25][0]*Vpk[23][25][0])+(Vpk[23][25][1]*Vpk[23][25][1]))))+((
          IkWpk[23][25][2]*s24)+((IkWpk[23][25][0]*Wpk[23][25][0])+(
          IkWpk[23][25][1]*Wpk[23][25][1])))));
        mm[23][24] = (((mk[19]*((rk[19][0]*Vpk[23][24][2])-(rk[19][2]*
          Vpk[23][24][0])))+((ik[19][0][1]*c24)+(ik[19][2][1]*s24)))+((mk[20]*((
          Vpk[23][25][2]*Vpk[24][25][2])+((Vpk[23][25][0]*Vpk[24][25][0])+(
          Vpk[23][25][1]*Vpk[24][25][1]))))+((IkWpk[24][25][2]*s24)+((
          IkWpk[24][25][0]*Wpk[23][25][0])+(IkWpk[24][25][1]*Wpk[23][25][1])))))
          ;
        mm[23][25] = ((mk[20]*((rk[20][1]*Vpk[23][25][0])-(rk[20][0]*
          Vpk[23][25][1])))+((ik[20][2][2]*s24)+((ik[20][0][2]*Wpk[23][25][0])+(
          ik[20][1][2]*Wpk[23][25][1]))));
        mm[24][24] = ((ik[19][1][1]+(mk[19]*((rk[19][0]*rk[19][0])+(rk[19][2]*
          rk[19][2]))))+((mk[20]*((Vpk[24][25][2]*Vpk[24][25][2])+((
          Vpk[24][25][0]*Vpk[24][25][0])+(Vpk[24][25][1]*Vpk[24][25][1]))))+((
          IkWpk[24][25][0]*s25)+(IkWpk[24][25][1]*c25))));
        mm[24][25] = ((mk[20]*((rk[20][1]*Vpk[24][25][0])-(rk[20][0]*
          Vpk[24][25][1])))+((ik[20][0][2]*s25)+(ik[20][1][2]*c25)));
        mm[25][25] = (ik[20][2][2]+(mk[20]*((rk[20][0]*rk[20][0])+(rk[20][1]*
          rk[20][1]))));
/*
Check for singular mass matrix
*/
        for (i = 0; i < 26; i++) {
            if (mm[i][i] < 1e-13) {
                sdseterr(routine,47);
            }
        }
        sderror(&dumroutine,&errnum);
        if (errnum == 0) {
            mmflg = 1;
        }
    }
/*
 Used 0.08 seconds CPU time,
 0 additional bytes of memory.
 Equations contain 4166 adds/subtracts/negates
                   5582 multiplies
                      0 divides
                    919 assignments
*/
}

void Jimmy::sddommldu(int routine)
{
    int i;
    int dumroutine,errnum;

    if (mmlduflg == 0) {
        sddomm(routine);
/*
Numerically decompose the mass matrix
*/
        sdldudcomp(26,26,mmap,1e-13,(double*)workss,works,(double*)mm,(double*)mlo,mdi);
/*
Check for singular mass matrix
*/
        for (i = 0; i < 26; i++) {
            if (mdi[i] <= 1e-13) {
                sdseterr(routine,47);
            }
        }
        sderror(&dumroutine,&errnum);
        if (errnum == 0) {
            mmlduflg = 1;
        }
    }
}

void Jimmy::sdlhs(int routine)
{
/* Compute all remaining state- and force-dependent quantities
*/

    roustate = 2;
    sddommldu(routine);
    sddofs0();
}

void Jimmy::sdmfrc(double imult[1])
{

}

void Jimmy::sdequivht(double tau[26])
{
/* Compute tree hinge torques to match effect of applied loads
*/
    double fstareq[26][3],tstareq[26][3];

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(56,23);
        return;
    }
/*
Compute fstareq (forces)
*/
    fstareq[5][0] = ((9.81*(Cik[3][2][0]*mk[0]))-ufk[0][0]);
    fstareq[5][1] = ((9.81*(Cik[3][2][1]*mk[0]))-ufk[0][1]);
    fstareq[5][2] = ((9.81*(Cik[3][2][2]*mk[0]))-ufk[0][2]);
    fstareq[6][0] = -(ufk[1][0]+(gk[6][0]*mk[1]));
    fstareq[6][1] = -(ufk[1][1]+(gk[6][1]*mk[1]));
    fstareq[6][2] = ((9.81*(Cik[3][2][2]*mk[1]))-ufk[1][2]);
    fstareq[7][0] = -(ufk[2][0]+(gk[7][0]*mk[2]));
    fstareq[7][1] = -(ufk[2][1]+(gk[6][1]*mk[2]));
    fstareq[7][2] = -(ufk[2][2]+(gk[7][2]*mk[2]));
    fstareq[8][0] = -(ufk[3][0]+(gk[7][0]*mk[3]));
    fstareq[8][1] = -(ufk[3][1]+(gk[8][1]*mk[3]));
    fstareq[8][2] = -(ufk[3][2]+(gk[8][2]*mk[3]));
    fstareq[9][0] = -(ufk[4][0]+(gk[9][0]*mk[4]));
    fstareq[9][1] = -(ufk[4][1]+(gk[8][1]*mk[4]));
    fstareq[9][2] = -(ufk[4][2]+(gk[9][2]*mk[4]));
    fstareq[10][0] = -(ufk[5][0]+(gk[10][0]*mk[5]));
    fstareq[10][1] = -(ufk[5][1]+(gk[8][1]*mk[5]));
    fstareq[10][2] = -(ufk[5][2]+(gk[10][2]*mk[5]));
    fstareq[11][0] = -(ufk[6][0]+(gk[10][0]*mk[6]));
    fstareq[11][1] = -(ufk[6][1]+(gk[11][1]*mk[6]));
    fstareq[11][2] = -(ufk[6][2]+(gk[11][2]*mk[6]));
    fstareq[12][0] = -(ufk[7][0]+(gk[12][0]*mk[7]));
    fstareq[12][1] = -(ufk[7][1]+(gk[12][1]*mk[7]));
    fstareq[12][2] = ((9.81*(Cik[3][2][2]*mk[7]))-ufk[7][2]);
    fstareq[13][0] = -(ufk[8][0]+(gk[13][0]*mk[8]));
    fstareq[13][1] = -(ufk[8][1]+(gk[12][1]*mk[8]));
    fstareq[13][2] = -(ufk[8][2]+(gk[13][2]*mk[8]));
    fstareq[14][0] = -(ufk[9][0]+(gk[13][0]*mk[9]));
    fstareq[14][1] = -(ufk[9][1]+(gk[14][1]*mk[9]));
    fstareq[14][2] = -(ufk[9][2]+(gk[14][2]*mk[9]));
    fstareq[15][0] = -(ufk[10][0]+(gk[15][0]*mk[10]));
    fstareq[15][1] = -(ufk[10][1]+(gk[14][1]*mk[10]));
    fstareq[15][2] = -(ufk[10][2]+(gk[15][2]*mk[10]));
    fstareq[16][0] = -(ufk[11][0]+(gk[16][0]*mk[11]));
    fstareq[16][1] = -(ufk[11][1]+(gk[14][1]*mk[11]));
    fstareq[16][2] = -(ufk[11][2]+(gk[16][2]*mk[11]));
    fstareq[17][0] = -(ufk[12][0]+(gk[16][0]*mk[12]));
    fstareq[17][1] = -(ufk[12][1]+(gk[17][1]*mk[12]));
    fstareq[17][2] = -(ufk[12][2]+(gk[17][2]*mk[12]));
    fstareq[18][0] = -(ufk[13][0]+(gk[18][0]*mk[13]));
    fstareq[18][1] = ((9.81*(Cik[3][2][1]*mk[13]))-ufk[13][1]);
    fstareq[18][2] = -(ufk[13][2]+(gk[18][2]*mk[13]));
    fstareq[19][0] = -(ufk[14][0]+(gk[18][0]*mk[14]));
    fstareq[19][1] = -(ufk[14][1]+(gk[19][1]*mk[14]));
    fstareq[19][2] = -(ufk[14][2]+(gk[19][2]*mk[14]));
    fstareq[20][0] = -(ufk[15][0]+(gk[20][0]*mk[15]));
    fstareq[20][1] = -(ufk[15][1]+(gk[19][1]*mk[15]));
    fstareq[20][2] = -(ufk[15][2]+(gk[20][2]*mk[15]));
    fstareq[21][0] = -(ufk[16][0]+(gk[21][0]*mk[16]));
    fstareq[21][1] = -(ufk[16][1]+(gk[21][1]*mk[16]));
    fstareq[21][2] = -(ufk[16][2]+(gk[20][2]*mk[16]));
    fstareq[22][0] = -(ufk[17][0]+(gk[22][0]*mk[17]));
    fstareq[22][1] = ((9.81*(Cik[3][2][1]*mk[17]))-ufk[17][1]);
    fstareq[22][2] = -(ufk[17][2]+(gk[22][2]*mk[17]));
    fstareq[23][0] = -(ufk[18][0]+(gk[22][0]*mk[18]));
    fstareq[23][1] = -(ufk[18][1]+(gk[23][1]*mk[18]));
    fstareq[23][2] = -(ufk[18][2]+(gk[23][2]*mk[18]));
    fstareq[24][0] = -(ufk[19][0]+(gk[24][0]*mk[19]));
    fstareq[24][1] = -(ufk[19][1]+(gk[23][1]*mk[19]));
    fstareq[24][2] = -(ufk[19][2]+(gk[24][2]*mk[19]));
    fstareq[25][0] = -(ufk[20][0]+(gk[25][0]*mk[20]));
    fstareq[25][1] = -(ufk[20][1]+(gk[25][1]*mk[20]));
    fstareq[25][2] = -(ufk[20][2]+(gk[24][2]*mk[20]));
/*
Compute tstareq (torques)
*/
/*
Compute taus (RHS ignoring constraints and inertial forces)
*/
    sddovpk();
    temp[0] = (((fstareq[8][2]*Vpk[0][8][2])+((fstareq[8][0]*Vpk[0][7][0])+(
      fstareq[8][1]*Vpk[0][8][1])))+(((fstareq[7][2]*Vpk[0][7][2])+((
      fstareq[7][0]*Vpk[0][7][0])+(fstareq[7][1]*Vpk[0][6][1])))+(((Cik[3][0][2]
      *fstareq[5][2])+((Cik[3][0][0]*fstareq[5][0])+(Cik[3][0][1]*fstareq[5][1])
      ))+((Cik[3][0][2]*fstareq[6][2])+((fstareq[6][0]*Vpk[0][6][0])+(
      fstareq[6][1]*Vpk[0][6][1]))))));
    temp[1] = (((Cik[3][0][2]*fstareq[12][2])+((fstareq[12][0]*Vpk[0][12][0])+(
      fstareq[12][1]*Vpk[0][12][1])))+(((fstareq[11][2]*Vpk[0][11][2])+((
      fstareq[11][0]*Vpk[0][10][0])+(fstareq[11][1]*Vpk[0][11][1])))+(((
      fstareq[10][2]*Vpk[0][10][2])+((fstareq[10][0]*Vpk[0][10][0])+(
      fstareq[10][1]*Vpk[0][8][1])))+(((fstareq[9][2]*Vpk[0][9][2])+((
      fstareq[9][0]*Vpk[0][9][0])+(fstareq[9][1]*Vpk[0][8][1])))+temp[0]))));
    temp[2] = (((fstareq[16][2]*Vpk[0][16][2])+((fstareq[16][0]*Vpk[0][16][0])+(
      fstareq[16][1]*Vpk[0][14][1])))+(((fstareq[15][2]*Vpk[0][15][2])+((
      fstareq[15][0]*Vpk[0][15][0])+(fstareq[15][1]*Vpk[0][14][1])))+(((
      fstareq[14][2]*Vpk[0][14][2])+((fstareq[14][0]*Vpk[0][13][0])+(
      fstareq[14][1]*Vpk[0][14][1])))+(((fstareq[13][2]*Vpk[0][13][2])+((
      fstareq[13][0]*Vpk[0][13][0])+(fstareq[13][1]*Vpk[0][12][1])))+temp[1]))))
      ;
    temp[3] = (((fstareq[20][2]*Vpk[0][20][2])+((fstareq[20][0]*Vpk[0][20][0])+(
      fstareq[20][1]*Vpk[0][19][1])))+(((fstareq[19][2]*Vpk[0][19][2])+((
      fstareq[19][0]*Vpk[0][18][0])+(fstareq[19][1]*Vpk[0][19][1])))+(((
      fstareq[18][2]*Vpk[0][18][2])+((Cik[3][0][1]*fstareq[18][1])+(
      fstareq[18][0]*Vpk[0][18][0])))+(((fstareq[17][2]*Vpk[0][17][2])+((
      fstareq[17][0]*Vpk[0][16][0])+(fstareq[17][1]*Vpk[0][17][1])))+temp[2]))))
      ;
    temp[4] = (((fstareq[24][2]*Vpk[0][24][2])+((fstareq[24][0]*Vpk[0][24][0])+(
      fstareq[24][1]*Vpk[0][23][1])))+(((fstareq[23][2]*Vpk[0][23][2])+((
      fstareq[23][0]*Vpk[0][22][0])+(fstareq[23][1]*Vpk[0][23][1])))+(((
      fstareq[22][2]*Vpk[0][22][2])+((Cik[3][0][1]*fstareq[22][1])+(
      fstareq[22][0]*Vpk[0][22][0])))+(((fstareq[21][2]*Vpk[0][20][2])+((
      fstareq[21][0]*Vpk[0][21][0])+(fstareq[21][1]*Vpk[0][21][1])))+temp[3]))))
      ;
    tau[0] = (utau[0]-(((fstareq[25][2]*Vpk[0][24][2])+((fstareq[25][0]*
      Vpk[0][25][0])+(fstareq[25][1]*Vpk[0][25][1])))+temp[4]));
    temp[0] = (((fstareq[8][2]*Vpk[1][8][2])+((fstareq[8][0]*Vpk[1][7][0])+(
      fstareq[8][1]*Vpk[1][8][1])))+(((fstareq[7][2]*Vpk[1][7][2])+((
      fstareq[7][0]*Vpk[1][7][0])+(fstareq[7][1]*Vpk[1][6][1])))+(((Cik[3][1][2]
      *fstareq[5][2])+((Cik[3][1][0]*fstareq[5][0])+(Cik[3][1][1]*fstareq[5][1])
      ))+((Cik[3][1][2]*fstareq[6][2])+((fstareq[6][0]*Vpk[1][6][0])+(
      fstareq[6][1]*Vpk[1][6][1]))))));
    temp[1] = (((Cik[3][1][2]*fstareq[12][2])+((fstareq[12][0]*Vpk[1][12][0])+(
      fstareq[12][1]*Vpk[1][12][1])))+(((fstareq[11][2]*Vpk[1][11][2])+((
      fstareq[11][0]*Vpk[1][10][0])+(fstareq[11][1]*Vpk[1][11][1])))+(((
      fstareq[10][2]*Vpk[1][10][2])+((fstareq[10][0]*Vpk[1][10][0])+(
      fstareq[10][1]*Vpk[1][8][1])))+(((fstareq[9][2]*Vpk[1][9][2])+((
      fstareq[9][0]*Vpk[1][9][0])+(fstareq[9][1]*Vpk[1][8][1])))+temp[0]))));
    temp[2] = (((fstareq[16][2]*Vpk[1][16][2])+((fstareq[16][0]*Vpk[1][16][0])+(
      fstareq[16][1]*Vpk[1][14][1])))+(((fstareq[15][2]*Vpk[1][15][2])+((
      fstareq[15][0]*Vpk[1][15][0])+(fstareq[15][1]*Vpk[1][14][1])))+(((
      fstareq[14][2]*Vpk[1][14][2])+((fstareq[14][0]*Vpk[1][13][0])+(
      fstareq[14][1]*Vpk[1][14][1])))+(((fstareq[13][2]*Vpk[1][13][2])+((
      fstareq[13][0]*Vpk[1][13][0])+(fstareq[13][1]*Vpk[1][12][1])))+temp[1]))))
      ;
    temp[3] = (((fstareq[20][2]*Vpk[1][20][2])+((fstareq[20][0]*Vpk[1][20][0])+(
      fstareq[20][1]*Vpk[1][19][1])))+(((fstareq[19][2]*Vpk[1][19][2])+((
      fstareq[19][0]*Vpk[1][18][0])+(fstareq[19][1]*Vpk[1][19][1])))+(((
      fstareq[18][2]*Vpk[1][18][2])+((Cik[3][1][1]*fstareq[18][1])+(
      fstareq[18][0]*Vpk[1][18][0])))+(((fstareq[17][2]*Vpk[1][17][2])+((
      fstareq[17][0]*Vpk[1][16][0])+(fstareq[17][1]*Vpk[1][17][1])))+temp[2]))))
      ;
    temp[4] = (((fstareq[24][2]*Vpk[1][24][2])+((fstareq[24][0]*Vpk[1][24][0])+(
      fstareq[24][1]*Vpk[1][23][1])))+(((fstareq[23][2]*Vpk[1][23][2])+((
      fstareq[23][0]*Vpk[1][22][0])+(fstareq[23][1]*Vpk[1][23][1])))+(((
      fstareq[22][2]*Vpk[1][22][2])+((Cik[3][1][1]*fstareq[22][1])+(
      fstareq[22][0]*Vpk[1][22][0])))+(((fstareq[21][2]*Vpk[1][20][2])+((
      fstareq[21][0]*Vpk[1][21][0])+(fstareq[21][1]*Vpk[1][21][1])))+temp[3]))))
      ;
    tau[1] = (utau[1]-(((fstareq[25][2]*Vpk[1][24][2])+((fstareq[25][0]*
      Vpk[1][25][0])+(fstareq[25][1]*Vpk[1][25][1])))+temp[4]));
    temp[0] = (((fstareq[8][2]*Vpk[2][8][2])+((fstareq[8][0]*Vpk[2][7][0])+(
      fstareq[8][1]*Vpk[2][8][1])))+(((fstareq[7][2]*Vpk[2][7][2])+((
      fstareq[7][0]*Vpk[2][7][0])+(fstareq[7][1]*Vpk[2][6][1])))+(((Cik[3][2][2]
      *fstareq[5][2])+((Cik[3][2][0]*fstareq[5][0])+(Cik[3][2][1]*fstareq[5][1])
      ))+((Cik[3][2][2]*fstareq[6][2])+((fstareq[6][0]*Vpk[2][6][0])+(
      fstareq[6][1]*Vpk[2][6][1]))))));
    temp[1] = (((Cik[3][2][2]*fstareq[12][2])+((fstareq[12][0]*Vpk[2][12][0])+(
      fstareq[12][1]*Vpk[2][12][1])))+(((fstareq[11][2]*Vpk[2][11][2])+((
      fstareq[11][0]*Vpk[2][10][0])+(fstareq[11][1]*Vpk[2][11][1])))+(((
      fstareq[10][2]*Vpk[2][10][2])+((fstareq[10][0]*Vpk[2][10][0])+(
      fstareq[10][1]*Vpk[2][8][1])))+(((fstareq[9][2]*Vpk[2][9][2])+((
      fstareq[9][0]*Vpk[2][9][0])+(fstareq[9][1]*Vpk[2][8][1])))+temp[0]))));
    temp[2] = (((fstareq[16][2]*Vpk[2][16][2])+((fstareq[16][0]*Vpk[2][16][0])+(
      fstareq[16][1]*Vpk[2][14][1])))+(((fstareq[15][2]*Vpk[2][15][2])+((
      fstareq[15][0]*Vpk[2][15][0])+(fstareq[15][1]*Vpk[2][14][1])))+(((
      fstareq[14][2]*Vpk[2][14][2])+((fstareq[14][0]*Vpk[2][13][0])+(
      fstareq[14][1]*Vpk[2][14][1])))+(((fstareq[13][2]*Vpk[2][13][2])+((
      fstareq[13][0]*Vpk[2][13][0])+(fstareq[13][1]*Vpk[2][12][1])))+temp[1]))))
      ;
    temp[3] = (((fstareq[20][2]*Vpk[2][20][2])+((fstareq[20][0]*Vpk[2][20][0])+(
      fstareq[20][1]*Vpk[2][19][1])))+(((fstareq[19][2]*Vpk[2][19][2])+((
      fstareq[19][0]*Vpk[2][18][0])+(fstareq[19][1]*Vpk[2][19][1])))+(((
      fstareq[18][2]*Vpk[2][18][2])+((Cik[3][2][1]*fstareq[18][1])+(
      fstareq[18][0]*Vpk[2][18][0])))+(((fstareq[17][2]*Vpk[2][17][2])+((
      fstareq[17][0]*Vpk[2][16][0])+(fstareq[17][1]*Vpk[2][17][1])))+temp[2]))))
      ;
    temp[4] = (((fstareq[24][2]*Vpk[2][24][2])+((fstareq[24][0]*Vpk[2][24][0])+(
      fstareq[24][1]*Vpk[2][23][1])))+(((fstareq[23][2]*Vpk[2][23][2])+((
      fstareq[23][0]*Vpk[2][22][0])+(fstareq[23][1]*Vpk[2][23][1])))+(((
      fstareq[22][2]*Vpk[2][22][2])+((Cik[3][2][1]*fstareq[22][1])+(
      fstareq[22][0]*Vpk[2][22][0])))+(((fstareq[21][2]*Vpk[2][20][2])+((
      fstareq[21][0]*Vpk[2][21][0])+(fstareq[21][1]*Vpk[2][21][1])))+temp[3]))))
      ;
    tau[2] = (utau[2]-(((fstareq[25][2]*Vpk[2][24][2])+((fstareq[25][0]*
      Vpk[2][25][0])+(fstareq[25][1]*Vpk[2][25][1])))+temp[4]));
    temp[0] = ((((fstareq[7][2]*Vpk[3][7][2])+((fstareq[7][0]*Vpk[3][7][0])+(
      fstareq[7][1]*Vpk[3][7][1])))+(((utk[2][1]*s6)-(utk[2][0]*Wpk[3][7][0]))-(
      utk[2][2]*Wpk[3][7][2])))+((((fstareq[5][1]*rk[0][2])-(fstareq[5][2]*
      rk[0][1]))-utk[0][0])+(((fstareq[6][2]*Vpk[3][6][2])+((fstareq[6][0]*
      Vpk[3][6][0])+(fstareq[6][1]*Vpk[3][6][1])))+((utk[1][1]*s6)-(utk[1][0]*c6
      )))));
    temp[1] = ((((fstareq[9][2]*Vpk[3][9][2])+((fstareq[9][0]*Vpk[3][9][0])+(
      fstareq[9][1]*Vpk[3][9][1])))-((utk[4][2]*Wpk[3][9][2])+((utk[4][0]*
      Wpk[3][9][0])+(utk[4][1]*Wpk[3][8][1]))))+((((fstareq[8][2]*Vpk[3][8][2])+
      ((fstareq[8][0]*Vpk[3][8][0])+(fstareq[8][1]*Vpk[3][8][1])))-((utk[3][2]*
      Wpk[3][8][2])+((utk[3][0]*Wpk[3][7][0])+(utk[3][1]*Wpk[3][8][1]))))+
      temp[0]));
    temp[2] = ((((fstareq[11][2]*Vpk[3][11][2])+((fstareq[11][0]*Vpk[3][11][0])+
      (fstareq[11][1]*Vpk[3][11][1])))-((utk[6][2]*Wpk[3][11][2])+((utk[6][0]*
      Wpk[3][10][0])+(utk[6][1]*Wpk[3][11][1]))))+((((fstareq[10][2]*
      Vpk[3][10][2])+((fstareq[10][0]*Vpk[3][10][0])+(fstareq[10][1]*
      Vpk[3][10][1])))-((utk[5][2]*Wpk[3][10][2])+((utk[5][0]*Wpk[3][10][0])+(
      utk[5][1]*Wpk[3][8][1]))))+temp[1]));
    temp[3] = ((((fstareq[13][2]*Vpk[3][13][2])+((fstareq[13][0]*Vpk[3][13][0])+
      (fstareq[13][1]*Vpk[3][13][1])))+(((utk[8][1]*s12)-(utk[8][0]*
      Wpk[3][13][0]))-(utk[8][2]*Wpk[3][13][2])))+((((fstareq[12][2]*
      Vpk[3][12][2])+((fstareq[12][0]*Vpk[3][12][0])+(fstareq[12][1]*
      Vpk[3][12][1])))+((utk[7][1]*s12)-(utk[7][0]*c12)))+temp[2]));
    temp[4] = ((((fstareq[15][2]*Vpk[3][15][2])+((fstareq[15][0]*Vpk[3][15][0])+
      (fstareq[15][1]*Vpk[3][15][1])))-((utk[10][2]*Wpk[3][15][2])+((utk[10][0]*
      Wpk[3][15][0])+(utk[10][1]*Wpk[3][14][1]))))+((((fstareq[14][2]*
      Vpk[3][14][2])+((fstareq[14][0]*Vpk[3][14][0])+(fstareq[14][1]*
      Vpk[3][14][1])))-((utk[9][2]*Wpk[3][14][2])+((utk[9][0]*Wpk[3][13][0])+(
      utk[9][1]*Wpk[3][14][1]))))+temp[3]));
    temp[5] = ((((fstareq[17][2]*Vpk[3][17][2])+((fstareq[17][0]*Vpk[3][17][0])+
      (fstareq[17][1]*Vpk[3][17][1])))-((utk[12][2]*Wpk[3][17][2])+((utk[12][0]*
      Wpk[3][16][0])+(utk[12][1]*Wpk[3][17][1]))))+((((fstareq[16][2]*
      Vpk[3][16][2])+((fstareq[16][0]*Vpk[3][16][0])+(fstareq[16][1]*
      Vpk[3][16][1])))-((utk[11][2]*Wpk[3][16][2])+((utk[11][0]*Wpk[3][16][0])+(
      utk[11][1]*Wpk[3][14][1]))))+temp[4]));
    temp[6] = ((((fstareq[19][2]*Vpk[3][19][2])+((fstareq[19][0]*Vpk[3][19][0])+
      (fstareq[19][1]*Vpk[3][19][1])))-((utk[14][2]*Wpk[3][19][2])+((utk[14][0]*
      c18)+(utk[14][1]*Wpk[3][19][1]))))+((((fstareq[18][2]*Vpk[3][18][2])+((
      fstareq[18][0]*Vpk[3][18][0])+(fstareq[18][1]*Vpk[3][18][1])))-((
      utk[13][0]*c18)+(utk[13][2]*s18)))+temp[5]));
    temp[7] = ((((fstareq[21][2]*Vpk[3][21][2])+((fstareq[21][0]*Vpk[3][21][0])+
      (fstareq[21][1]*Vpk[3][21][1])))-((utk[16][2]*Wpk[3][20][2])+((utk[16][0]*
      Wpk[3][21][0])+(utk[16][1]*Wpk[3][21][1]))))+((((fstareq[20][2]*
      Vpk[3][20][2])+((fstareq[20][0]*Vpk[3][20][0])+(fstareq[20][1]*
      Vpk[3][20][1])))-((utk[15][2]*Wpk[3][20][2])+((utk[15][0]*Wpk[3][20][0])+(
      utk[15][1]*Wpk[3][19][1]))))+temp[6]));
    temp[8] = ((((fstareq[23][2]*Vpk[3][23][2])+((fstareq[23][0]*Vpk[3][23][0])+
      (fstareq[23][1]*Vpk[3][23][1])))-((utk[18][2]*Wpk[3][23][2])+((utk[18][0]*
      c22)+(utk[18][1]*Wpk[3][23][1]))))+((((fstareq[22][2]*Vpk[3][22][2])+((
      fstareq[22][0]*Vpk[3][22][0])+(fstareq[22][1]*Vpk[3][22][1])))-((
      utk[17][0]*c22)+(utk[17][2]*s22)))+temp[7]));
    tau[3] = (utau[3]-((((fstareq[25][2]*Vpk[3][25][2])+((fstareq[25][0]*
      Vpk[3][25][0])+(fstareq[25][1]*Vpk[3][25][1])))-((utk[20][2]*Wpk[3][24][2]
      )+((utk[20][0]*Wpk[3][25][0])+(utk[20][1]*Wpk[3][25][1]))))+((((
      fstareq[24][2]*Vpk[3][24][2])+((fstareq[24][0]*Vpk[3][24][0])+(
      fstareq[24][1]*Vpk[3][24][1])))-((utk[19][2]*Wpk[3][24][2])+((utk[19][0]*
      Wpk[3][24][0])+(utk[19][1]*Wpk[3][23][1]))))+temp[8])));
    temp[0] = ((((fstareq[7][2]*Vpk[4][7][2])+((fstareq[7][0]*Vpk[4][7][0])+(
      fstareq[7][1]*Vpk[4][7][1])))-((utk[2][2]*Wpk[4][7][2])+((utk[2][0]*
      Wpk[4][7][0])+(utk[2][1]*c6))))+((((fstareq[5][2]*rk[0][0])-(fstareq[5][0]
      *rk[0][2]))-utk[0][1])+(((fstareq[6][2]*Vpk[4][6][2])+((fstareq[6][0]*
      Vpk[4][6][0])+(fstareq[6][1]*Vpk[4][6][1])))-((utk[1][0]*s6)+(utk[1][1]*c6
      )))));
    temp[1] = ((((fstareq[9][2]*Vpk[4][9][2])+((fstareq[9][0]*Vpk[4][9][0])+(
      fstareq[9][1]*Vpk[4][9][1])))-((utk[4][2]*Wpk[4][9][2])+((utk[4][0]*
      Wpk[4][9][0])+(utk[4][1]*Wpk[4][8][1]))))+((((fstareq[8][2]*Vpk[4][8][2])+
      ((fstareq[8][0]*Vpk[4][8][0])+(fstareq[8][1]*Vpk[4][8][1])))-((utk[3][2]*
      Wpk[4][8][2])+((utk[3][0]*Wpk[4][7][0])+(utk[3][1]*Wpk[4][8][1]))))+
      temp[0]));
    temp[2] = ((((fstareq[11][2]*Vpk[4][11][2])+((fstareq[11][0]*Vpk[4][11][0])+
      (fstareq[11][1]*Vpk[4][11][1])))-((utk[6][2]*Wpk[4][11][2])+((utk[6][0]*
      Wpk[4][10][0])+(utk[6][1]*Wpk[4][11][1]))))+((((fstareq[10][2]*
      Vpk[4][10][2])+((fstareq[10][0]*Vpk[4][10][0])+(fstareq[10][1]*
      Vpk[4][10][1])))-((utk[5][2]*Wpk[4][10][2])+((utk[5][0]*Wpk[4][10][0])+(
      utk[5][1]*Wpk[4][8][1]))))+temp[1]));
    temp[3] = ((((fstareq[13][2]*Vpk[4][13][2])+((fstareq[13][0]*Vpk[4][13][0])+
      (fstareq[13][1]*Vpk[4][13][1])))-((utk[8][2]*Wpk[4][13][2])+((utk[8][0]*
      Wpk[4][13][0])+(utk[8][1]*c12))))+((((fstareq[12][2]*Vpk[4][12][2])+((
      fstareq[12][0]*Vpk[4][12][0])+(fstareq[12][1]*Vpk[4][12][1])))-((utk[7][0]
      *s12)+(utk[7][1]*c12)))+temp[2]));
    temp[4] = ((((fstareq[15][2]*Vpk[4][15][2])+((fstareq[15][0]*Vpk[4][15][0])+
      (fstareq[15][1]*Vpk[4][15][1])))-((utk[10][2]*Wpk[4][15][2])+((utk[10][0]*
      Wpk[4][15][0])+(utk[10][1]*Wpk[4][14][1]))))+((((fstareq[14][2]*
      Vpk[4][14][2])+((fstareq[14][0]*Vpk[4][14][0])+(fstareq[14][1]*
      Vpk[4][14][1])))-((utk[9][2]*Wpk[4][14][2])+((utk[9][0]*Wpk[4][13][0])+(
      utk[9][1]*Wpk[4][14][1]))))+temp[3]));
    temp[5] = ((((fstareq[17][2]*Vpk[4][17][2])+((fstareq[17][0]*Vpk[4][17][0])+
      (fstareq[17][1]*Vpk[4][17][1])))-((utk[12][2]*Wpk[4][17][2])+((utk[12][0]*
      Wpk[4][16][0])+(utk[12][1]*Wpk[4][17][1]))))+((((fstareq[16][2]*
      Vpk[4][16][2])+((fstareq[16][0]*Vpk[4][16][0])+(fstareq[16][1]*
      Vpk[4][16][1])))-((utk[11][2]*Wpk[4][16][2])+((utk[11][0]*Wpk[4][16][0])+(
      utk[11][1]*Wpk[4][14][1]))))+temp[4]));
    temp[6] = ((((fstareq[20][2]*Vpk[4][20][2])+((fstareq[20][0]*Vpk[4][20][0])+
      (fstareq[20][1]*Vpk[4][20][1])))-((utk[15][2]*Wpk[4][20][2])+((utk[15][0]*
      Wpk[4][20][0])+(utk[15][1]*c19))))+((((fstareq[19][2]*Vpk[4][19][2])+((
      fstareq[19][0]*Vpk[4][19][0])+(fstareq[19][1]*Vpk[4][19][1])))+((
      utk[14][2]*s19)-(utk[14][1]*c19)))+((((fstareq[18][0]*Vpk[4][18][0])+(
      fstareq[18][2]*Vpk[4][18][2]))-utk[13][1])+temp[5])));
    temp[7] = ((((fstareq[23][2]*Vpk[4][23][2])+((fstareq[23][0]*Vpk[4][23][0])+
      (fstareq[23][1]*Vpk[4][23][1])))+((utk[18][2]*s23)-(utk[18][1]*c23)))+((((
      fstareq[22][0]*Vpk[4][22][0])+(fstareq[22][2]*Vpk[4][22][2]))-utk[17][1])+
      ((((fstareq[21][2]*Vpk[4][21][2])+((fstareq[21][0]*Vpk[4][21][0])+(
      fstareq[21][1]*Vpk[4][21][1])))-((utk[16][2]*Wpk[4][20][2])+((utk[16][0]*
      Wpk[4][21][0])+(utk[16][1]*Wpk[4][21][1]))))+temp[6])));
    tau[4] = (utau[4]-((((fstareq[25][2]*Vpk[4][25][2])+((fstareq[25][0]*
      Vpk[4][25][0])+(fstareq[25][1]*Vpk[4][25][1])))-((utk[20][2]*Wpk[4][24][2]
      )+((utk[20][0]*Wpk[4][25][0])+(utk[20][1]*Wpk[4][25][1]))))+((((
      fstareq[24][2]*Vpk[4][24][2])+((fstareq[24][0]*Vpk[4][24][0])+(
      fstareq[24][1]*Vpk[4][24][1])))-((utk[19][2]*Wpk[4][24][2])+((utk[19][0]*
      Wpk[4][24][0])+(utk[19][1]*c23))))+temp[7])));
    temp[0] = ((((fstareq[8][2]*Vpk[5][8][2])+((fstareq[8][0]*Vpk[5][8][0])+(
      fstareq[8][1]*Vpk[5][8][1])))+(((utk[3][0]*s7)-(utk[3][1]*Wpk[5][8][1]))-(
      utk[3][2]*Wpk[5][8][2])))+((((fstareq[7][2]*Vpk[5][7][2])+((fstareq[7][0]*
      Vpk[5][7][0])+(fstareq[7][1]*Vpk[5][7][1])))+((utk[2][0]*s7)-(utk[2][2]*c7
      )))+((((fstareq[5][0]*rk[0][1])-(fstareq[5][1]*rk[0][0]))-utk[0][2])+(((
      fstareq[6][0]*Vpk[5][6][0])+(fstareq[6][1]*Vpk[5][6][1]))-utk[1][2]))));
    temp[1] = ((((fstareq[10][2]*Vpk[5][10][2])+((fstareq[10][0]*Vpk[5][10][0])+
      (fstareq[10][1]*Vpk[5][10][1])))-((utk[5][2]*Wpk[5][10][2])+((utk[5][0]*
      Wpk[5][10][0])+(utk[5][1]*Wpk[5][8][1]))))+((((fstareq[9][2]*Vpk[5][9][2])
      +((fstareq[9][0]*Vpk[5][9][0])+(fstareq[9][1]*Vpk[5][9][1])))-((utk[4][2]*
      Wpk[5][9][2])+((utk[4][0]*Wpk[5][9][0])+(utk[4][1]*Wpk[5][8][1]))))+
      temp[0]));
    temp[2] = ((((fstareq[13][2]*Vpk[5][13][2])+((fstareq[13][0]*Vpk[5][13][0])+
      (fstareq[13][1]*Vpk[5][13][1])))+((utk[8][0]*s13)-(utk[8][2]*c13)))+((((
      fstareq[12][0]*Vpk[5][12][0])+(fstareq[12][1]*Vpk[5][12][1]))-utk[7][2])+(
      (((fstareq[11][2]*Vpk[5][11][2])+((fstareq[11][0]*Vpk[5][11][0])+(
      fstareq[11][1]*Vpk[5][11][1])))-((utk[6][2]*Wpk[5][11][2])+((utk[6][0]*
      Wpk[5][10][0])+(utk[6][1]*Wpk[5][11][1]))))+temp[1])));
    temp[3] = ((((fstareq[15][2]*Vpk[5][15][2])+((fstareq[15][0]*Vpk[5][15][0])+
      (fstareq[15][1]*Vpk[5][15][1])))-((utk[10][2]*Wpk[5][15][2])+((utk[10][0]*
      Wpk[5][15][0])+(utk[10][1]*Wpk[5][14][1]))))+((((fstareq[14][2]*
      Vpk[5][14][2])+((fstareq[14][0]*Vpk[5][14][0])+(fstareq[14][1]*
      Vpk[5][14][1])))+(((utk[9][0]*s13)-(utk[9][1]*Wpk[5][14][1]))-(utk[9][2]*
      Wpk[5][14][2])))+temp[2]));
    temp[4] = ((((fstareq[17][2]*Vpk[5][17][2])+((fstareq[17][0]*Vpk[5][17][0])+
      (fstareq[17][1]*Vpk[5][17][1])))-((utk[12][2]*Wpk[5][17][2])+((utk[12][0]*
      Wpk[5][16][0])+(utk[12][1]*Wpk[5][17][1]))))+((((fstareq[16][2]*
      Vpk[5][16][2])+((fstareq[16][0]*Vpk[5][16][0])+(fstareq[16][1]*
      Vpk[5][16][1])))-((utk[11][2]*Wpk[5][16][2])+((utk[11][0]*Wpk[5][16][0])+(
      utk[11][1]*Wpk[5][14][1]))))+temp[3]));
    temp[5] = ((((fstareq[19][2]*Vpk[5][19][2])+((fstareq[19][0]*Vpk[5][19][0])+
      (fstareq[19][1]*Vpk[5][19][1])))+(((utk[14][0]*s18)-(utk[14][1]*
      Wpk[5][19][1]))-(utk[14][2]*Wpk[5][19][2])))+((((fstareq[18][2]*
      Vpk[5][18][2])+((fstareq[18][0]*Vpk[5][18][0])+(fstareq[18][1]*
      Vpk[5][18][1])))+((utk[13][0]*s18)-(utk[13][2]*c18)))+temp[4]));
    temp[6] = ((((fstareq[21][2]*Vpk[5][21][2])+((fstareq[21][0]*Vpk[5][21][0])+
      (fstareq[21][1]*Vpk[5][21][1])))-((utk[16][2]*Wpk[5][20][2])+((utk[16][0]*
      Wpk[5][21][0])+(utk[16][1]*Wpk[5][21][1]))))+((((fstareq[20][2]*
      Vpk[5][20][2])+((fstareq[20][0]*Vpk[5][20][0])+(fstareq[20][1]*
      Vpk[5][20][1])))-((utk[15][2]*Wpk[5][20][2])+((utk[15][0]*Wpk[5][20][0])+(
      utk[15][1]*Wpk[5][19][1]))))+temp[5]));
    temp[7] = ((((fstareq[23][2]*Vpk[5][23][2])+((fstareq[23][0]*Vpk[5][23][0])+
      (fstareq[23][1]*Vpk[5][23][1])))+(((utk[18][0]*s22)-(utk[18][1]*
      Wpk[5][23][1]))-(utk[18][2]*Wpk[5][23][2])))+((((fstareq[22][2]*
      Vpk[5][22][2])+((fstareq[22][0]*Vpk[5][22][0])+(fstareq[22][1]*
      Vpk[5][22][1])))+((utk[17][0]*s22)-(utk[17][2]*c22)))+temp[6]));
    tau[5] = (utau[5]-((((fstareq[25][2]*Vpk[5][25][2])+((fstareq[25][0]*
      Vpk[5][25][0])+(fstareq[25][1]*Vpk[5][25][1])))-((utk[20][2]*Wpk[5][24][2]
      )+((utk[20][0]*Wpk[5][25][0])+(utk[20][1]*Wpk[5][25][1]))))+((((
      fstareq[24][2]*Vpk[5][24][2])+((fstareq[24][0]*Vpk[5][24][0])+(
      fstareq[24][1]*Vpk[5][24][1])))-((utk[19][2]*Wpk[5][24][2])+((utk[19][0]*
      Wpk[5][24][0])+(utk[19][1]*Wpk[5][23][1]))))+temp[7])));
    temp[0] = ((((fstareq[8][2]*Vpk[6][8][2])+((fstareq[8][0]*Vpk[6][8][0])+(
      fstareq[8][1]*Vpk[6][8][1])))+(((utk[3][0]*s7)-(utk[3][1]*Wpk[6][8][1]))-(
      utk[3][2]*Wpk[6][8][2])))+((((fstareq[6][0]*rk[1][1])-(fstareq[6][1]*
      rk[1][0]))-utk[1][2])+(((fstareq[7][2]*Vpk[6][7][2])+((fstareq[7][0]*
      Vpk[6][7][0])+(fstareq[7][1]*Vpk[6][7][1])))+((utk[2][0]*s7)-(utk[2][2]*c7
      )))));
    temp[1] = ((((fstareq[10][2]*Vpk[6][10][2])+((fstareq[10][0]*Vpk[6][10][0])+
      (fstareq[10][1]*Vpk[6][10][1])))-((utk[5][2]*Wpk[6][10][2])+((utk[5][0]*
      Wpk[6][10][0])+(utk[5][1]*Wpk[6][8][1]))))+((((fstareq[9][2]*Vpk[6][9][2])
      +((fstareq[9][0]*Vpk[6][9][0])+(fstareq[9][1]*Vpk[6][9][1])))-((utk[4][2]*
      Wpk[6][9][2])+((utk[4][0]*Wpk[6][9][0])+(utk[4][1]*Wpk[6][8][1]))))+
      temp[0]));
    tau[6] = (utau[6]-((((fstareq[11][2]*Vpk[6][11][2])+((fstareq[11][0]*
      Vpk[6][11][0])+(fstareq[11][1]*Vpk[6][11][1])))-((utk[6][2]*Wpk[6][11][2])
      +((utk[6][0]*Wpk[6][10][0])+(utk[6][1]*Wpk[6][11][1]))))+temp[1]));
    temp[0] = ((((fstareq[9][2]*Vpk[7][9][2])+((fstareq[9][0]*Vpk[7][9][0])+(
      fstareq[9][1]*Vpk[7][9][1])))-((utk[4][2]*Wpk[7][9][2])+((utk[4][0]*
      Wpk[7][9][0])+(utk[4][1]*c8))))+((((fstareq[7][2]*rk[2][0])-(fstareq[7][0]
      *rk[2][2]))-utk[2][1])+(((fstareq[8][2]*Vpk[7][8][2])+((fstareq[8][0]*
      Vpk[7][8][0])+(fstareq[8][1]*Vpk[7][8][1])))+((utk[3][2]*s8)-(utk[3][1]*c8
      )))));
    tau[7] = (utau[7]-((((fstareq[11][2]*Vpk[7][11][2])+((fstareq[11][0]*
      Vpk[7][11][0])+(fstareq[11][1]*Vpk[7][11][1])))-((utk[6][2]*Wpk[7][11][2])
      +((utk[6][0]*Wpk[7][10][0])+(utk[6][1]*Wpk[7][11][1]))))+((((
      fstareq[10][2]*Vpk[7][10][2])+((fstareq[10][0]*Vpk[7][10][0])+(
      fstareq[10][1]*Vpk[7][10][1])))-((utk[5][2]*Wpk[7][10][2])+((utk[5][0]*
      Wpk[7][10][0])+(utk[5][1]*c8))))+temp[0])));
    temp[0] = ((((fstareq[10][2]*Vpk[8][10][2])+((fstareq[10][0]*Vpk[8][10][0])+
      (fstareq[10][1]*Vpk[8][10][1])))-((utk[5][0]*Wpk[8][10][0])+(utk[5][2]*
      Wpk[8][10][2])))+((((fstareq[8][1]*rk[3][2])-(fstareq[8][2]*rk[3][1]))-
      utk[3][0])+(((fstareq[9][2]*Vpk[8][9][2])+((fstareq[9][0]*Vpk[8][9][0])+(
      fstareq[9][1]*Vpk[8][9][1])))-((utk[4][0]*c9)+(utk[4][2]*s9)))));
    tau[8] = (utau[8]-((((fstareq[11][2]*Vpk[8][11][2])+((fstareq[11][0]*
      Vpk[8][11][0])+(fstareq[11][1]*Vpk[8][11][1])))-((utk[6][2]*Wpk[8][11][2])
      +((utk[6][0]*Wpk[8][10][0])+(utk[6][1]*Wpk[8][11][1]))))+temp[0]));
    tau[9] = (utau[9]-((((fstareq[11][2]*Vpk[9][11][2])+((fstareq[11][0]*
      Vpk[9][11][0])+(fstareq[11][1]*Vpk[9][11][1])))+((utk[6][2]*s11)-(
      utk[6][1]*c11)))+((((fstareq[9][2]*rk[4][0])-(fstareq[9][0]*rk[4][2]))-
      utk[4][1])+(((fstareq[10][0]*Vpk[9][10][0])+(fstareq[10][2]*Vpk[9][10][2])
      )-utk[5][1]))));
    tau[10] = (utau[10]-((((fstareq[10][2]*rk[5][0])-(fstareq[10][0]*rk[5][2]))-
      utk[5][1])+(((fstareq[11][2]*Vpk[10][11][2])+((fstareq[11][0]*
      Vpk[10][11][0])+(fstareq[11][1]*Vpk[10][11][1])))+((utk[6][2]*s11)-(
      utk[6][1]*c11)))));
    tau[11] = (utau[11]-(((fstareq[11][1]*rk[6][2])-(fstareq[11][2]*rk[6][1]))-
      utk[6][0]));
    temp[0] = ((((fstareq[14][2]*Vpk[12][14][2])+((fstareq[14][0]*Vpk[12][14][0]
      )+(fstareq[14][1]*Vpk[12][14][1])))+(((utk[9][0]*s13)-(utk[9][1]*
      Wpk[12][14][1]))-(utk[9][2]*Wpk[12][14][2])))+((((fstareq[12][0]*rk[7][1])
      -(fstareq[12][1]*rk[7][0]))-utk[7][2])+(((fstareq[13][2]*Vpk[12][13][2])+(
      (fstareq[13][0]*Vpk[12][13][0])+(fstareq[13][1]*Vpk[12][13][1])))+((
      utk[8][0]*s13)-(utk[8][2]*c13)))));
    temp[1] = ((((fstareq[16][2]*Vpk[12][16][2])+((fstareq[16][0]*Vpk[12][16][0]
      )+(fstareq[16][1]*Vpk[12][16][1])))-((utk[11][2]*Wpk[12][16][2])+((
      utk[11][0]*Wpk[12][16][0])+(utk[11][1]*Wpk[12][14][1]))))+((((
      fstareq[15][2]*Vpk[12][15][2])+((fstareq[15][0]*Vpk[12][15][0])+(
      fstareq[15][1]*Vpk[12][15][1])))-((utk[10][2]*Wpk[12][15][2])+((utk[10][0]
      *Wpk[12][15][0])+(utk[10][1]*Wpk[12][14][1]))))+temp[0]));
    tau[12] = (utau[12]-((((fstareq[17][2]*Vpk[12][17][2])+((fstareq[17][0]*
      Vpk[12][17][0])+(fstareq[17][1]*Vpk[12][17][1])))-((utk[12][2]*
      Wpk[12][17][2])+((utk[12][0]*Wpk[12][16][0])+(utk[12][1]*Wpk[12][17][1])))
      )+temp[1]));
    temp[0] = ((((fstareq[15][2]*Vpk[13][15][2])+((fstareq[15][0]*Vpk[13][15][0]
      )+(fstareq[15][1]*Vpk[13][15][1])))-((utk[10][2]*Wpk[13][15][2])+((
      utk[10][0]*Wpk[13][15][0])+(utk[10][1]*c14))))+((((fstareq[13][2]*rk[8][0]
      )-(fstareq[13][0]*rk[8][2]))-utk[8][1])+(((fstareq[14][2]*Vpk[13][14][2])+
      ((fstareq[14][0]*Vpk[13][14][0])+(fstareq[14][1]*Vpk[13][14][1])))+((
      utk[9][2]*s14)-(utk[9][1]*c14)))));
    tau[13] = (utau[13]-((((fstareq[17][2]*Vpk[13][17][2])+((fstareq[17][0]*
      Vpk[13][17][0])+(fstareq[17][1]*Vpk[13][17][1])))-((utk[12][2]*
      Wpk[13][17][2])+((utk[12][0]*Wpk[13][16][0])+(utk[12][1]*Wpk[13][17][1])))
      )+((((fstareq[16][2]*Vpk[13][16][2])+((fstareq[16][0]*Vpk[13][16][0])+(
      fstareq[16][1]*Vpk[13][16][1])))-((utk[11][2]*Wpk[13][16][2])+((utk[11][0]
      *Wpk[13][16][0])+(utk[11][1]*c14))))+temp[0])));
    temp[0] = ((((fstareq[16][2]*Vpk[14][16][2])+((fstareq[16][0]*Vpk[14][16][0]
      )+(fstareq[16][1]*Vpk[14][16][1])))-((utk[11][0]*Wpk[14][16][0])+(
      utk[11][2]*Wpk[14][16][2])))+((((fstareq[14][1]*rk[9][2])-(fstareq[14][2]*
      rk[9][1]))-utk[9][0])+(((fstareq[15][2]*Vpk[14][15][2])+((fstareq[15][0]*
      Vpk[14][15][0])+(fstareq[15][1]*Vpk[14][15][1])))-((utk[10][0]*c15)+(
      utk[10][2]*s15)))));
    tau[14] = (utau[14]-((((fstareq[17][2]*Vpk[14][17][2])+((fstareq[17][0]*
      Vpk[14][17][0])+(fstareq[17][1]*Vpk[14][17][1])))-((utk[12][2]*
      Wpk[14][17][2])+((utk[12][0]*Wpk[14][16][0])+(utk[12][1]*Wpk[14][17][1])))
      )+temp[0]));
    tau[15] = (utau[15]-((((fstareq[17][2]*Vpk[15][17][2])+((fstareq[17][0]*
      Vpk[15][17][0])+(fstareq[17][1]*Vpk[15][17][1])))+((utk[12][2]*s17)-(
      utk[12][1]*c17)))+((((fstareq[15][2]*rk[10][0])-(fstareq[15][0]*rk[10][2])
      )-utk[10][1])+(((fstareq[16][0]*Vpk[15][16][0])+(fstareq[16][2]*
      Vpk[15][16][2]))-utk[11][1]))));
    tau[16] = (utau[16]-((((fstareq[16][2]*rk[11][0])-(fstareq[16][0]*rk[11][2])
      )-utk[11][1])+(((fstareq[17][2]*Vpk[16][17][2])+((fstareq[17][0]*
      Vpk[16][17][0])+(fstareq[17][1]*Vpk[16][17][1])))+((utk[12][2]*s17)-(
      utk[12][1]*c17)))));
    tau[17] = (utau[17]-(((fstareq[17][1]*rk[12][2])-(fstareq[17][2]*rk[12][1]))
      -utk[12][0]));
    temp[0] = ((((fstareq[20][2]*Vpk[18][20][2])+((fstareq[20][0]*Vpk[18][20][0]
      )+(fstareq[20][1]*Vpk[18][20][1])))-((utk[15][2]*Wpk[18][20][2])+((
      utk[15][0]*Wpk[18][20][0])+(utk[15][1]*c19))))+((((fstareq[18][2]*
      rk[13][0])-(fstareq[18][0]*rk[13][2]))-utk[13][1])+(((fstareq[19][2]*
      Vpk[18][19][2])+((fstareq[19][0]*Vpk[18][19][0])+(fstareq[19][1]*
      Vpk[18][19][1])))+((utk[14][2]*s19)-(utk[14][1]*c19)))));
    tau[18] = (utau[18]-((((fstareq[21][2]*Vpk[18][21][2])+((fstareq[21][0]*
      Vpk[18][21][0])+(fstareq[21][1]*Vpk[18][21][1])))-((utk[16][2]*
      Wpk[18][20][2])+((utk[16][0]*Wpk[18][21][0])+(utk[16][1]*Wpk[18][21][1])))
      )+temp[0]));
    tau[19] = (utau[19]-((((fstareq[21][2]*Vpk[19][21][2])+((fstareq[21][0]*
      Vpk[19][21][0])+(fstareq[21][1]*Vpk[19][21][1])))-((utk[16][2]*s20)+((
      utk[16][0]*Wpk[19][21][0])+(utk[16][1]*Wpk[19][21][1]))))+((((
      fstareq[19][1]*rk[14][2])-(fstareq[19][2]*rk[14][1]))-utk[14][0])+(((
      fstareq[20][2]*Vpk[19][20][2])+((fstareq[20][0]*Vpk[19][20][0])+(
      fstareq[20][1]*Vpk[19][20][1])))-((utk[15][0]*c20)+(utk[15][2]*s20))))));
    tau[20] = (utau[20]-((((fstareq[20][2]*rk[15][0])-(fstareq[20][0]*rk[15][2])
      )-utk[15][1])+(((fstareq[21][2]*Vpk[20][21][2])+((fstareq[21][0]*
      Vpk[20][21][0])+(fstareq[21][1]*Vpk[20][21][1])))-((utk[16][0]*s21)+(
      utk[16][1]*c21)))));
    tau[21] = (utau[21]-(((fstareq[21][0]*rk[16][1])-(fstareq[21][1]*rk[16][0]))
      -utk[16][2]));
    temp[0] = ((((fstareq[24][2]*Vpk[22][24][2])+((fstareq[24][0]*Vpk[22][24][0]
      )+(fstareq[24][1]*Vpk[22][24][1])))-((utk[19][2]*Wpk[22][24][2])+((
      utk[19][0]*Wpk[22][24][0])+(utk[19][1]*c23))))+((((fstareq[22][2]*
      rk[17][0])-(fstareq[22][0]*rk[17][2]))-utk[17][1])+(((fstareq[23][2]*
      Vpk[22][23][2])+((fstareq[23][0]*Vpk[22][23][0])+(fstareq[23][1]*
      Vpk[22][23][1])))+((utk[18][2]*s23)-(utk[18][1]*c23)))));
    tau[22] = (utau[22]-((((fstareq[25][2]*Vpk[22][25][2])+((fstareq[25][0]*
      Vpk[22][25][0])+(fstareq[25][1]*Vpk[22][25][1])))-((utk[20][2]*
      Wpk[22][24][2])+((utk[20][0]*Wpk[22][25][0])+(utk[20][1]*Wpk[22][25][1])))
      )+temp[0]));
    tau[23] = (utau[23]-((((fstareq[25][2]*Vpk[23][25][2])+((fstareq[25][0]*
      Vpk[23][25][0])+(fstareq[25][1]*Vpk[23][25][1])))-((utk[20][2]*s24)+((
      utk[20][0]*Wpk[23][25][0])+(utk[20][1]*Wpk[23][25][1]))))+((((
      fstareq[23][1]*rk[18][2])-(fstareq[23][2]*rk[18][1]))-utk[18][0])+(((
      fstareq[24][2]*Vpk[23][24][2])+((fstareq[24][0]*Vpk[23][24][0])+(
      fstareq[24][1]*Vpk[23][24][1])))-((utk[19][0]*c24)+(utk[19][2]*s24))))));
    tau[24] = (utau[24]-((((fstareq[24][2]*rk[19][0])-(fstareq[24][0]*rk[19][2])
      )-utk[19][1])+(((fstareq[25][2]*Vpk[24][25][2])+((fstareq[25][0]*
      Vpk[24][25][0])+(fstareq[25][1]*Vpk[24][25][1])))-((utk[20][0]*s25)+(
      utk[20][1]*c25)))));
    tau[25] = (utau[25]-(((fstareq[25][0]*rk[20][1])-(fstareq[25][1]*rk[20][0]))
      -utk[20][2]));
/*
Op counts below do not include called subroutines
*/
/*
 Used 0.02 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  941 adds/subtracts/negates
                    863 multiplies
                      0 divides
                    139 assignments
*/
}

void Jimmy::sdfs0(void)
{

/*
Compute Fs (ignoring multiplier forces)
*/
    fs[0] = fs0[0];
    fs[1] = fs0[1];
    fs[2] = fs0[2];
    fs[3] = fs0[3];
    fs[4] = fs0[4];
    fs[5] = fs0[5];
    fs[6] = fs0[6];
    fs[7] = fs0[7];
    fs[8] = fs0[8];
    fs[9] = fs0[9];
    fs[10] = fs0[10];
    fs[11] = fs0[11];
    fs[12] = fs0[12];
    fs[13] = fs0[13];
    fs[14] = fs0[14];
    fs[15] = fs0[15];
    fs[16] = fs0[16];
    fs[17] = fs0[17];
    fs[18] = fs0[18];
    fs[19] = fs0[19];
    fs[20] = fs0[20];
    fs[21] = fs0[21];
    fs[22] = fs0[22];
    fs[23] = fs0[23];
    fs[24] = fs0[24];
    fs[25] = fs0[25];
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     26 assignments
*/
}

void Jimmy::sdfsmult(void)
{
    int i;

/*
Compute Fs (multiplier-generated forces only)
*/
    for (i = 0; i < 26; i++) {
        fs[i] = 0.;
    }
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     26 assignments
*/
}

void Jimmy::sdfsfull(void)
{

/*
Compute Fs (including all forces)
*/
    sdfsmult();
    fs[0] = (fs[0]+fs0[0]);
    fs[1] = (fs[1]+fs0[1]);
    fs[2] = (fs[2]+fs0[2]);
    fs[3] = (fs[3]+fs0[3]);
    fs[4] = (fs[4]+fs0[4]);
    fs[5] = (fs[5]+fs0[5]);
    fs[6] = (fs[6]+fs0[6]);
    fs[7] = (fs[7]+fs0[7]);
    fs[8] = (fs[8]+fs0[8]);
    fs[9] = (fs[9]+fs0[9]);
    fs[10] = (fs[10]+fs0[10]);
    fs[11] = (fs[11]+fs0[11]);
    fs[12] = (fs[12]+fs0[12]);
    fs[13] = (fs[13]+fs0[13]);
    fs[14] = (fs[14]+fs0[14]);
    fs[15] = (fs[15]+fs0[15]);
    fs[16] = (fs[16]+fs0[16]);
    fs[17] = (fs[17]+fs0[17]);
    fs[18] = (fs[18]+fs0[18]);
    fs[19] = (fs[19]+fs0[19]);
    fs[20] = (fs[20]+fs0[20]);
    fs[21] = (fs[21]+fs0[21]);
    fs[22] = (fs[22]+fs0[22]);
    fs[23] = (fs[23]+fs0[23]);
    fs[24] = (fs[24]+fs0[24]);
    fs[25] = (fs[25]+fs0[25]);
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain   26 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     26 assignments
*/
}

void Jimmy::sdfsgenmult(void)
{
    int i;

/*
Compute Fs (generic multiplier-generated forces)
*/
    for (i = 0; i < 26; i++) {
        fs[i] = 0.;
    }
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     26 assignments
*/
}

void Jimmy::sdfsgenfull(void)
{

/*
Compute Fs (incl generic mult & other forces)
*/
    sdfsgenmult();
    fs[0] = (fs[0]+fs0[0]);
    fs[1] = (fs[1]+fs0[1]);
    fs[2] = (fs[2]+fs0[2]);
    fs[3] = (fs[3]+fs0[3]);
    fs[4] = (fs[4]+fs0[4]);
    fs[5] = (fs[5]+fs0[5]);
    fs[6] = (fs[6]+fs0[6]);
    fs[7] = (fs[7]+fs0[7]);
    fs[8] = (fs[8]+fs0[8]);
    fs[9] = (fs[9]+fs0[9]);
    fs[10] = (fs[10]+fs0[10]);
    fs[11] = (fs[11]+fs0[11]);
    fs[12] = (fs[12]+fs0[12]);
    fs[13] = (fs[13]+fs0[13]);
    fs[14] = (fs[14]+fs0[14]);
    fs[15] = (fs[15]+fs0[15]);
    fs[16] = (fs[16]+fs0[16]);
    fs[17] = (fs[17]+fs0[17]);
    fs[18] = (fs[18]+fs0[18]);
    fs[19] = (fs[19]+fs0[19]);
    fs[20] = (fs[20]+fs0[20]);
    fs[21] = (fs[21]+fs0[21]);
    fs[22] = (fs[22]+fs0[22]);
    fs[23] = (fs[23]+fs0[23]);
    fs[24] = (fs[24]+fs0[24]);
    fs[25] = (fs[25]+fs0[25]);
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain   26 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     26 assignments
*/
}

void Jimmy::sdfulltrq(double udotin[26],
    double multin[1],
    double trqout[26])
{
/* Compute hinge torques which would produce indicated udots
*/
    double fstarr[26][3],tstarr[26][3],Otkr[26][3],Atir[26][3],Atkr[26][3];

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(61,23);
        return;
    }
/*
Account for inertial accelerations and supplied udots
*/
    Otkr[6][0] = ((u[6]*wk[6][1])+((udotin[3]*c6)+(udotin[4]*s6)));
    Otkr[6][1] = (((udotin[4]*c6)-(udotin[3]*s6))-(u[6]*wk[6][0]));
    Otkr[6][2] = (udotin[5]+udotin[6]);
    Otkr[7][0] = (((Otkr[6][0]*c7)-(Otkr[6][2]*s7))-(u[7]*wk[7][2]));
    Otkr[7][1] = (Otkr[6][1]+udotin[7]);
    Otkr[7][2] = ((u[7]*wk[7][0])+((Otkr[6][0]*s7)+(Otkr[6][2]*c7)));
    Otkr[8][0] = (Otkr[7][0]+udotin[8]);
    Otkr[8][1] = ((u[8]*wk[8][2])+((Otkr[7][1]*c8)+(Otkr[7][2]*s8)));
    Otkr[8][2] = (((Otkr[7][2]*c8)-(Otkr[7][1]*s8))-(u[8]*wk[8][1]));
    Otkr[9][0] = (((Otkr[8][0]*c9)-(Otkr[8][2]*s9))-(u[9]*wk[9][2]));
    Otkr[9][1] = (Otkr[8][1]+udotin[9]);
    Otkr[9][2] = ((u[9]*wk[9][0])+((Otkr[8][0]*s9)+(Otkr[8][2]*c9)));
    Otkr[10][0] = (((Otkr[9][0]*c10)-(Otkr[9][2]*s10))-(u[10]*wk[10][2]));
    Otkr[10][1] = (Otkr[9][1]+udotin[10]);
    Otkr[10][2] = ((u[10]*wk[10][0])+((Otkr[9][0]*s10)+(Otkr[9][2]*c10)));
    Otkr[11][0] = (Otkr[10][0]+udotin[11]);
    Otkr[11][1] = ((u[11]*wk[11][2])+((Otkr[10][1]*c11)+(Otkr[10][2]*s11)));
    Otkr[11][2] = (((Otkr[10][2]*c11)-(Otkr[10][1]*s11))-(u[11]*wk[11][1]));
    Otkr[12][0] = ((u[12]*wk[12][1])+((udotin[3]*c12)+(udotin[4]*s12)));
    Otkr[12][1] = (((udotin[4]*c12)-(udotin[3]*s12))-(u[12]*wk[12][0]));
    Otkr[12][2] = (udotin[5]+udotin[12]);
    Otkr[13][0] = (((Otkr[12][0]*c13)-(Otkr[12][2]*s13))-(u[13]*wk[13][2]));
    Otkr[13][1] = (Otkr[12][1]+udotin[13]);
    Otkr[13][2] = ((u[13]*wk[13][0])+((Otkr[12][0]*s13)+(Otkr[12][2]*c13)));
    Otkr[14][0] = (Otkr[13][0]+udotin[14]);
    Otkr[14][1] = ((u[14]*wk[14][2])+((Otkr[13][1]*c14)+(Otkr[13][2]*s14)));
    Otkr[14][2] = (((Otkr[13][2]*c14)-(Otkr[13][1]*s14))-(u[14]*wk[14][1]));
    Otkr[15][0] = (((Otkr[14][0]*c15)-(Otkr[14][2]*s15))-(u[15]*wk[15][2]));
    Otkr[15][1] = (Otkr[14][1]+udotin[15]);
    Otkr[15][2] = ((u[15]*wk[15][0])+((Otkr[14][0]*s15)+(Otkr[14][2]*c15)));
    Otkr[16][0] = (((Otkr[15][0]*c16)-(Otkr[15][2]*s16))-(u[16]*wk[16][2]));
    Otkr[16][1] = (Otkr[15][1]+udotin[16]);
    Otkr[16][2] = ((u[16]*wk[16][0])+((Otkr[15][0]*s16)+(Otkr[15][2]*c16)));
    Otkr[17][0] = (Otkr[16][0]+udotin[17]);
    Otkr[17][1] = ((u[17]*wk[17][2])+((Otkr[16][1]*c17)+(Otkr[16][2]*s17)));
    Otkr[17][2] = (((Otkr[16][2]*c17)-(Otkr[16][1]*s17))-(u[17]*wk[17][1]));
    Otkr[18][0] = (((udotin[3]*c18)-(udotin[5]*s18))-(u[18]*wk[18][2]));
    Otkr[18][1] = (udotin[4]+udotin[18]);
    Otkr[18][2] = ((u[18]*wk[18][0])+((udotin[3]*s18)+(udotin[5]*c18)));
    Otkr[19][0] = (Otkr[18][0]+udotin[19]);
    Otkr[19][1] = ((u[19]*wk[19][2])+((Otkr[18][1]*c19)+(Otkr[18][2]*s19)));
    Otkr[19][2] = (((Otkr[18][2]*c19)-(Otkr[18][1]*s19))-(u[19]*wk[19][1]));
    Otkr[20][0] = (((Otkr[19][0]*c20)-(Otkr[19][2]*s20))-(u[20]*wk[20][2]));
    Otkr[20][1] = (Otkr[19][1]+udotin[20]);
    Otkr[20][2] = ((u[20]*wk[20][0])+((Otkr[19][0]*s20)+(Otkr[19][2]*c20)));
    Otkr[21][0] = ((u[21]*wk[21][1])+((Otkr[20][0]*c21)+(Otkr[20][1]*s21)));
    Otkr[21][1] = (((Otkr[20][1]*c21)-(Otkr[20][0]*s21))-(u[21]*wk[21][0]));
    Otkr[21][2] = (Otkr[20][2]+udotin[21]);
    Otkr[22][0] = (((udotin[3]*c22)-(udotin[5]*s22))-(u[22]*wk[22][2]));
    Otkr[22][1] = (udotin[4]+udotin[22]);
    Otkr[22][2] = ((u[22]*wk[22][0])+((udotin[3]*s22)+(udotin[5]*c22)));
    Otkr[23][0] = (Otkr[22][0]+udotin[23]);
    Otkr[23][1] = ((u[23]*wk[23][2])+((Otkr[22][1]*c23)+(Otkr[22][2]*s23)));
    Otkr[23][2] = (((Otkr[22][2]*c23)-(Otkr[22][1]*s23))-(u[23]*wk[23][1]));
    Otkr[24][0] = (((Otkr[23][0]*c24)-(Otkr[23][2]*s24))-(u[24]*wk[24][2]));
    Otkr[24][1] = (Otkr[23][1]+udotin[24]);
    Otkr[24][2] = ((u[24]*wk[24][0])+((Otkr[23][0]*s24)+(Otkr[23][2]*c24)));
    Otkr[25][0] = ((u[25]*wk[25][1])+((Otkr[24][0]*c25)+(Otkr[24][1]*s25)));
    Otkr[25][1] = (((Otkr[24][1]*c25)-(Otkr[24][0]*s25))-(u[25]*wk[25][0]));
    Otkr[25][2] = (Otkr[24][2]+udotin[25]);
    Atkr[3][0] = ((Cik[3][2][0]*udotin[2])+((Cik[3][0][0]*udotin[0])+(
      Cik[3][1][0]*udotin[1])));
    Atkr[3][1] = ((Cik[3][2][1]*udotin[2])+((Cik[3][0][1]*udotin[0])+(
      Cik[3][1][1]*udotin[1])));
    Atkr[3][2] = ((Cik[3][2][2]*udotin[2])+((Cik[3][0][2]*udotin[0])+(
      Cik[3][1][2]*udotin[1])));
    Atkr[5][0] = (Atkr[3][0]+(((rk[0][1]*udotin[5])-(rk[0][2]*udotin[4]))+((u[4]
      *Wkrpk[5][2])-(u[5]*Wkrpk[5][1]))));
    Atkr[5][1] = (Atkr[3][1]+(((rk[0][2]*udotin[3])-(rk[0][0]*udotin[5]))+((u[5]
      *Wkrpk[5][0])-(u[3]*Wkrpk[5][2]))));
    Atkr[5][2] = (Atkr[3][2]+(((rk[0][0]*udotin[4])-(rk[0][1]*udotin[3]))+((u[3]
      *Wkrpk[5][1])-(u[4]*Wkrpk[5][0]))));
    Atir[6][0] = (Atkr[5][0]+(((ri[1][2]*udotin[4])-(ri[1][1]*udotin[5]))+((u[4]
      *Wirk[6][2])-(u[5]*Wirk[6][1]))));
    Atir[6][1] = (Atkr[5][1]+(((ri[1][0]*udotin[5])-(ri[1][2]*udotin[3]))+((u[5]
      *Wirk[6][0])-(u[3]*Wirk[6][2]))));
    Atir[6][2] = (Atkr[5][2]+(((ri[1][1]*udotin[3])-(ri[1][0]*udotin[4]))+((u[3]
      *Wirk[6][1])-(u[4]*Wirk[6][0]))));
    Atkr[6][0] = (((Atir[6][0]*c6)+(Atir[6][1]*s6))+(((Otkr[6][2]*rk[1][1])-(
      Otkr[6][1]*rk[1][2]))+((wk[6][1]*Wkrpk[6][2])-(wk[6][2]*Wkrpk[6][1]))));
    Atkr[6][1] = (((Atir[6][1]*c6)-(Atir[6][0]*s6))+(((Otkr[6][0]*rk[1][2])-(
      Otkr[6][2]*rk[1][0]))+((wk[6][2]*Wkrpk[6][0])-(wk[6][0]*Wkrpk[6][2]))));
    Atkr[6][2] = (Atir[6][2]+(((Otkr[6][1]*rk[1][0])-(Otkr[6][0]*rk[1][1]))+((
      wk[6][0]*Wkrpk[6][1])-(wk[6][1]*Wkrpk[6][0]))));
    Atir[7][0] = (Atkr[6][0]+(((Otkr[6][1]*ri[2][2])-(Otkr[6][2]*ri[2][1]))+((
      Wirk[7][2]*wk[6][1])-(Wirk[7][1]*wk[6][2]))));
    Atir[7][1] = (Atkr[6][1]+(((Otkr[6][2]*ri[2][0])-(Otkr[6][0]*ri[2][2]))+((
      Wirk[7][0]*wk[6][2])-(Wirk[7][2]*wk[6][0]))));
    Atir[7][2] = (Atkr[6][2]+(((Otkr[6][0]*ri[2][1])-(Otkr[6][1]*ri[2][0]))+((
      Wirk[7][1]*wk[6][0])-(Wirk[7][0]*wk[6][1]))));
    Atkr[7][0] = (((Atir[7][0]*c7)-(Atir[7][2]*s7))+(((Otkr[7][2]*rk[2][1])-(
      Otkr[7][1]*rk[2][2]))+((wk[7][1]*Wkrpk[7][2])-(wk[7][2]*Wkrpk[7][1]))));
    Atkr[7][1] = (Atir[7][1]+(((Otkr[7][0]*rk[2][2])-(Otkr[7][2]*rk[2][0]))+((
      wk[7][2]*Wkrpk[7][0])-(wk[7][0]*Wkrpk[7][2]))));
    Atkr[7][2] = (((Atir[7][0]*s7)+(Atir[7][2]*c7))+(((Otkr[7][1]*rk[2][0])-(
      Otkr[7][0]*rk[2][1]))+((wk[7][0]*Wkrpk[7][1])-(wk[7][1]*Wkrpk[7][0]))));
    Atir[8][0] = (Atkr[7][0]+(((Otkr[7][1]*ri[3][2])-(Otkr[7][2]*ri[3][1]))+((
      Wirk[8][2]*wk[7][1])-(Wirk[8][1]*wk[7][2]))));
    Atir[8][1] = (Atkr[7][1]+(((Otkr[7][2]*ri[3][0])-(Otkr[7][0]*ri[3][2]))+((
      Wirk[8][0]*wk[7][2])-(Wirk[8][2]*wk[7][0]))));
    Atir[8][2] = (Atkr[7][2]+(((Otkr[7][0]*ri[3][1])-(Otkr[7][1]*ri[3][0]))+((
      Wirk[8][1]*wk[7][0])-(Wirk[8][0]*wk[7][1]))));
    Atkr[8][0] = (Atir[8][0]+(((Otkr[8][2]*rk[3][1])-(Otkr[8][1]*rk[3][2]))+((
      wk[8][1]*Wkrpk[8][2])-(wk[8][2]*Wkrpk[8][1]))));
    Atkr[8][1] = (((Atir[8][1]*c8)+(Atir[8][2]*s8))+(((Otkr[8][0]*rk[3][2])-(
      Otkr[8][2]*rk[3][0]))+((wk[8][2]*Wkrpk[8][0])-(wk[8][0]*Wkrpk[8][2]))));
    Atkr[8][2] = (((Atir[8][2]*c8)-(Atir[8][1]*s8))+(((Otkr[8][1]*rk[3][0])-(
      Otkr[8][0]*rk[3][1]))+((wk[8][0]*Wkrpk[8][1])-(wk[8][1]*Wkrpk[8][0]))));
    Atir[9][0] = (Atkr[8][0]+(((Otkr[8][1]*ri[4][2])-(Otkr[8][2]*ri[4][1]))+((
      Wirk[9][2]*wk[8][1])-(Wirk[9][1]*wk[8][2]))));
    Atir[9][1] = (Atkr[8][1]+(((Otkr[8][2]*ri[4][0])-(Otkr[8][0]*ri[4][2]))+((
      Wirk[9][0]*wk[8][2])-(Wirk[9][2]*wk[8][0]))));
    Atir[9][2] = (Atkr[8][2]+(((Otkr[8][0]*ri[4][1])-(Otkr[8][1]*ri[4][0]))+((
      Wirk[9][1]*wk[8][0])-(Wirk[9][0]*wk[8][1]))));
    Atkr[9][0] = (((Atir[9][0]*c9)-(Atir[9][2]*s9))+(((Otkr[9][2]*rk[4][1])-(
      Otkr[9][1]*rk[4][2]))+((wk[9][1]*Wkrpk[9][2])-(wk[9][2]*Wkrpk[9][1]))));
    Atkr[9][1] = (Atir[9][1]+(((Otkr[9][0]*rk[4][2])-(Otkr[9][2]*rk[4][0]))+((
      wk[9][2]*Wkrpk[9][0])-(wk[9][0]*Wkrpk[9][2]))));
    Atkr[9][2] = (((Atir[9][0]*s9)+(Atir[9][2]*c9))+(((Otkr[9][1]*rk[4][0])-(
      Otkr[9][0]*rk[4][1]))+((wk[9][0]*Wkrpk[9][1])-(wk[9][1]*Wkrpk[9][0]))));
    Atir[10][0] = (Atkr[9][0]+(((Otkr[9][1]*ri[5][2])-(Otkr[9][2]*ri[5][1]))+((
      Wirk[10][2]*wk[9][1])-(Wirk[10][1]*wk[9][2]))));
    Atir[10][1] = (Atkr[9][1]+(((Otkr[9][2]*ri[5][0])-(Otkr[9][0]*ri[5][2]))+((
      Wirk[10][0]*wk[9][2])-(Wirk[10][2]*wk[9][0]))));
    Atir[10][2] = (Atkr[9][2]+(((Otkr[9][0]*ri[5][1])-(Otkr[9][1]*ri[5][0]))+((
      Wirk[10][1]*wk[9][0])-(Wirk[10][0]*wk[9][1]))));
    Atkr[10][0] = (((Atir[10][0]*c10)-(Atir[10][2]*s10))+(((Otkr[10][2]*rk[5][1]
      )-(Otkr[10][1]*rk[5][2]))+((wk[10][1]*Wkrpk[10][2])-(wk[10][2]*
      Wkrpk[10][1]))));
    Atkr[10][1] = (Atir[10][1]+(((Otkr[10][0]*rk[5][2])-(Otkr[10][2]*rk[5][0]))+
      ((wk[10][2]*Wkrpk[10][0])-(wk[10][0]*Wkrpk[10][2]))));
    Atkr[10][2] = (((Atir[10][0]*s10)+(Atir[10][2]*c10))+(((Otkr[10][1]*rk[5][0]
      )-(Otkr[10][0]*rk[5][1]))+((wk[10][0]*Wkrpk[10][1])-(wk[10][1]*
      Wkrpk[10][0]))));
    Atir[11][0] = (Atkr[10][0]+(((Otkr[10][1]*ri[6][2])-(Otkr[10][2]*ri[6][1]))+
      ((Wirk[11][2]*wk[10][1])-(Wirk[11][1]*wk[10][2]))));
    Atir[11][1] = (Atkr[10][1]+(((Otkr[10][2]*ri[6][0])-(Otkr[10][0]*ri[6][2]))+
      ((Wirk[11][0]*wk[10][2])-(Wirk[11][2]*wk[10][0]))));
    Atir[11][2] = (Atkr[10][2]+(((Otkr[10][0]*ri[6][1])-(Otkr[10][1]*ri[6][0]))+
      ((Wirk[11][1]*wk[10][0])-(Wirk[11][0]*wk[10][1]))));
    Atkr[11][0] = (Atir[11][0]+(((Otkr[11][2]*rk[6][1])-(Otkr[11][1]*rk[6][2]))+
      ((wk[11][1]*Wkrpk[11][2])-(wk[11][2]*Wkrpk[11][1]))));
    Atkr[11][1] = (((Atir[11][1]*c11)+(Atir[11][2]*s11))+(((Otkr[11][0]*rk[6][2]
      )-(Otkr[11][2]*rk[6][0]))+((wk[11][2]*Wkrpk[11][0])-(wk[11][0]*
      Wkrpk[11][2]))));
    Atkr[11][2] = (((Atir[11][2]*c11)-(Atir[11][1]*s11))+(((Otkr[11][1]*rk[6][0]
      )-(Otkr[11][0]*rk[6][1]))+((wk[11][0]*Wkrpk[11][1])-(wk[11][1]*
      Wkrpk[11][0]))));
    Atir[12][0] = (Atkr[5][0]+(((ri[7][2]*udotin[4])-(ri[7][1]*udotin[5]))+((
      u[4]*Wirk[12][2])-(u[5]*Wirk[12][1]))));
    Atir[12][1] = (Atkr[5][1]+(((ri[7][0]*udotin[5])-(ri[7][2]*udotin[3]))+((
      u[5]*Wirk[12][0])-(u[3]*Wirk[12][2]))));
    Atir[12][2] = (Atkr[5][2]+(((ri[7][1]*udotin[3])-(ri[7][0]*udotin[4]))+((
      u[3]*Wirk[12][1])-(u[4]*Wirk[12][0]))));
    Atkr[12][0] = (((Atir[12][0]*c12)+(Atir[12][1]*s12))+(((Otkr[12][2]*rk[7][1]
      )-(Otkr[12][1]*rk[7][2]))+((wk[12][1]*Wkrpk[12][2])-(wk[12][2]*
      Wkrpk[12][1]))));
    Atkr[12][1] = (((Atir[12][1]*c12)-(Atir[12][0]*s12))+(((Otkr[12][0]*rk[7][2]
      )-(Otkr[12][2]*rk[7][0]))+((wk[12][2]*Wkrpk[12][0])-(wk[12][0]*
      Wkrpk[12][2]))));
    Atkr[12][2] = (Atir[12][2]+(((Otkr[12][1]*rk[7][0])-(Otkr[12][0]*rk[7][1]))+
      ((wk[12][0]*Wkrpk[12][1])-(wk[12][1]*Wkrpk[12][0]))));
    Atir[13][0] = (Atkr[12][0]+(((Otkr[12][1]*ri[8][2])-(Otkr[12][2]*ri[8][1]))+
      ((Wirk[13][2]*wk[12][1])-(Wirk[13][1]*wk[12][2]))));
    Atir[13][1] = (Atkr[12][1]+(((Otkr[12][2]*ri[8][0])-(Otkr[12][0]*ri[8][2]))+
      ((Wirk[13][0]*wk[12][2])-(Wirk[13][2]*wk[12][0]))));
    Atir[13][2] = (Atkr[12][2]+(((Otkr[12][0]*ri[8][1])-(Otkr[12][1]*ri[8][0]))+
      ((Wirk[13][1]*wk[12][0])-(Wirk[13][0]*wk[12][1]))));
    Atkr[13][0] = (((Atir[13][0]*c13)-(Atir[13][2]*s13))+(((Otkr[13][2]*rk[8][1]
      )-(Otkr[13][1]*rk[8][2]))+((wk[13][1]*Wkrpk[13][2])-(wk[13][2]*
      Wkrpk[13][1]))));
    Atkr[13][1] = (Atir[13][1]+(((Otkr[13][0]*rk[8][2])-(Otkr[13][2]*rk[8][0]))+
      ((wk[13][2]*Wkrpk[13][0])-(wk[13][0]*Wkrpk[13][2]))));
    Atkr[13][2] = (((Atir[13][0]*s13)+(Atir[13][2]*c13))+(((Otkr[13][1]*rk[8][0]
      )-(Otkr[13][0]*rk[8][1]))+((wk[13][0]*Wkrpk[13][1])-(wk[13][1]*
      Wkrpk[13][0]))));
    Atir[14][0] = (Atkr[13][0]+(((Otkr[13][1]*ri[9][2])-(Otkr[13][2]*ri[9][1]))+
      ((Wirk[14][2]*wk[13][1])-(Wirk[14][1]*wk[13][2]))));
    Atir[14][1] = (Atkr[13][1]+(((Otkr[13][2]*ri[9][0])-(Otkr[13][0]*ri[9][2]))+
      ((Wirk[14][0]*wk[13][2])-(Wirk[14][2]*wk[13][0]))));
    Atir[14][2] = (Atkr[13][2]+(((Otkr[13][0]*ri[9][1])-(Otkr[13][1]*ri[9][0]))+
      ((Wirk[14][1]*wk[13][0])-(Wirk[14][0]*wk[13][1]))));
    Atkr[14][0] = (Atir[14][0]+(((Otkr[14][2]*rk[9][1])-(Otkr[14][1]*rk[9][2]))+
      ((wk[14][1]*Wkrpk[14][2])-(wk[14][2]*Wkrpk[14][1]))));
    Atkr[14][1] = (((Atir[14][1]*c14)+(Atir[14][2]*s14))+(((Otkr[14][0]*rk[9][2]
      )-(Otkr[14][2]*rk[9][0]))+((wk[14][2]*Wkrpk[14][0])-(wk[14][0]*
      Wkrpk[14][2]))));
    Atkr[14][2] = (((Atir[14][2]*c14)-(Atir[14][1]*s14))+(((Otkr[14][1]*rk[9][0]
      )-(Otkr[14][0]*rk[9][1]))+((wk[14][0]*Wkrpk[14][1])-(wk[14][1]*
      Wkrpk[14][0]))));
    Atir[15][0] = (Atkr[14][0]+(((Otkr[14][1]*ri[10][2])-(Otkr[14][2]*ri[10][1])
      )+((Wirk[15][2]*wk[14][1])-(Wirk[15][1]*wk[14][2]))));
    Atir[15][1] = (Atkr[14][1]+(((Otkr[14][2]*ri[10][0])-(Otkr[14][0]*ri[10][2])
      )+((Wirk[15][0]*wk[14][2])-(Wirk[15][2]*wk[14][0]))));
    Atir[15][2] = (Atkr[14][2]+(((Otkr[14][0]*ri[10][1])-(Otkr[14][1]*ri[10][0])
      )+((Wirk[15][1]*wk[14][0])-(Wirk[15][0]*wk[14][1]))));
    Atkr[15][0] = (((Atir[15][0]*c15)-(Atir[15][2]*s15))+(((Otkr[15][2]*
      rk[10][1])-(Otkr[15][1]*rk[10][2]))+((wk[15][1]*Wkrpk[15][2])-(wk[15][2]*
      Wkrpk[15][1]))));
    Atkr[15][1] = (Atir[15][1]+(((Otkr[15][0]*rk[10][2])-(Otkr[15][2]*rk[10][0])
      )+((wk[15][2]*Wkrpk[15][0])-(wk[15][0]*Wkrpk[15][2]))));
    Atkr[15][2] = (((Atir[15][0]*s15)+(Atir[15][2]*c15))+(((Otkr[15][1]*
      rk[10][0])-(Otkr[15][0]*rk[10][1]))+((wk[15][0]*Wkrpk[15][1])-(wk[15][1]*
      Wkrpk[15][0]))));
    Atir[16][0] = (Atkr[15][0]+(((Otkr[15][1]*ri[11][2])-(Otkr[15][2]*ri[11][1])
      )+((Wirk[16][2]*wk[15][1])-(Wirk[16][1]*wk[15][2]))));
    Atir[16][1] = (Atkr[15][1]+(((Otkr[15][2]*ri[11][0])-(Otkr[15][0]*ri[11][2])
      )+((Wirk[16][0]*wk[15][2])-(Wirk[16][2]*wk[15][0]))));
    Atir[16][2] = (Atkr[15][2]+(((Otkr[15][0]*ri[11][1])-(Otkr[15][1]*ri[11][0])
      )+((Wirk[16][1]*wk[15][0])-(Wirk[16][0]*wk[15][1]))));
    Atkr[16][0] = (((Atir[16][0]*c16)-(Atir[16][2]*s16))+(((Otkr[16][2]*
      rk[11][1])-(Otkr[16][1]*rk[11][2]))+((wk[16][1]*Wkrpk[16][2])-(wk[16][2]*
      Wkrpk[16][1]))));
    Atkr[16][1] = (Atir[16][1]+(((Otkr[16][0]*rk[11][2])-(Otkr[16][2]*rk[11][0])
      )+((wk[16][2]*Wkrpk[16][0])-(wk[16][0]*Wkrpk[16][2]))));
    Atkr[16][2] = (((Atir[16][0]*s16)+(Atir[16][2]*c16))+(((Otkr[16][1]*
      rk[11][0])-(Otkr[16][0]*rk[11][1]))+((wk[16][0]*Wkrpk[16][1])-(wk[16][1]*
      Wkrpk[16][0]))));
    Atir[17][0] = (Atkr[16][0]+(((Otkr[16][1]*ri[12][2])-(Otkr[16][2]*ri[12][1])
      )+((Wirk[17][2]*wk[16][1])-(Wirk[17][1]*wk[16][2]))));
    Atir[17][1] = (Atkr[16][1]+(((Otkr[16][2]*ri[12][0])-(Otkr[16][0]*ri[12][2])
      )+((Wirk[17][0]*wk[16][2])-(Wirk[17][2]*wk[16][0]))));
    Atir[17][2] = (Atkr[16][2]+(((Otkr[16][0]*ri[12][1])-(Otkr[16][1]*ri[12][0])
      )+((Wirk[17][1]*wk[16][0])-(Wirk[17][0]*wk[16][1]))));
    Atkr[17][0] = (Atir[17][0]+(((Otkr[17][2]*rk[12][1])-(Otkr[17][1]*rk[12][2])
      )+((wk[17][1]*Wkrpk[17][2])-(wk[17][2]*Wkrpk[17][1]))));
    Atkr[17][1] = (((Atir[17][1]*c17)+(Atir[17][2]*s17))+(((Otkr[17][0]*
      rk[12][2])-(Otkr[17][2]*rk[12][0]))+((wk[17][2]*Wkrpk[17][0])-(wk[17][0]*
      Wkrpk[17][2]))));
    Atkr[17][2] = (((Atir[17][2]*c17)-(Atir[17][1]*s17))+(((Otkr[17][1]*
      rk[12][0])-(Otkr[17][0]*rk[12][1]))+((wk[17][0]*Wkrpk[17][1])-(wk[17][1]*
      Wkrpk[17][0]))));
    Atir[18][0] = (Atkr[5][0]+(((ri[13][2]*udotin[4])-(ri[13][1]*udotin[5]))+((
      u[4]*Wirk[18][2])-(u[5]*Wirk[18][1]))));
    Atir[18][1] = (Atkr[5][1]+(((ri[13][0]*udotin[5])-(ri[13][2]*udotin[3]))+((
      u[5]*Wirk[18][0])-(u[3]*Wirk[18][2]))));
    Atir[18][2] = (Atkr[5][2]+(((ri[13][1]*udotin[3])-(ri[13][0]*udotin[4]))+((
      u[3]*Wirk[18][1])-(u[4]*Wirk[18][0]))));
    Atkr[18][0] = (((Atir[18][0]*c18)-(Atir[18][2]*s18))+(((Otkr[18][2]*
      rk[13][1])-(Otkr[18][1]*rk[13][2]))+((wk[18][1]*Wkrpk[18][2])-(wk[18][2]*
      Wkrpk[18][1]))));
    Atkr[18][1] = (Atir[18][1]+(((Otkr[18][0]*rk[13][2])-(Otkr[18][2]*rk[13][0])
      )+((wk[18][2]*Wkrpk[18][0])-(wk[18][0]*Wkrpk[18][2]))));
    Atkr[18][2] = (((Atir[18][0]*s18)+(Atir[18][2]*c18))+(((Otkr[18][1]*
      rk[13][0])-(Otkr[18][0]*rk[13][1]))+((wk[18][0]*Wkrpk[18][1])-(wk[18][1]*
      Wkrpk[18][0]))));
    Atir[19][0] = (Atkr[18][0]+(((Otkr[18][1]*ri[14][2])-(Otkr[18][2]*ri[14][1])
      )+((Wirk[19][2]*wk[18][1])-(Wirk[19][1]*wk[18][2]))));
    Atir[19][1] = (Atkr[18][1]+(((Otkr[18][2]*ri[14][0])-(Otkr[18][0]*ri[14][2])
      )+((Wirk[19][0]*wk[18][2])-(Wirk[19][2]*wk[18][0]))));
    Atir[19][2] = (Atkr[18][2]+(((Otkr[18][0]*ri[14][1])-(Otkr[18][1]*ri[14][0])
      )+((Wirk[19][1]*wk[18][0])-(Wirk[19][0]*wk[18][1]))));
    Atkr[19][0] = (Atir[19][0]+(((Otkr[19][2]*rk[14][1])-(Otkr[19][1]*rk[14][2])
      )+((wk[19][1]*Wkrpk[19][2])-(wk[19][2]*Wkrpk[19][1]))));
    Atkr[19][1] = (((Atir[19][1]*c19)+(Atir[19][2]*s19))+(((Otkr[19][0]*
      rk[14][2])-(Otkr[19][2]*rk[14][0]))+((wk[19][2]*Wkrpk[19][0])-(wk[19][0]*
      Wkrpk[19][2]))));
    Atkr[19][2] = (((Atir[19][2]*c19)-(Atir[19][1]*s19))+(((Otkr[19][1]*
      rk[14][0])-(Otkr[19][0]*rk[14][1]))+((wk[19][0]*Wkrpk[19][1])-(wk[19][1]*
      Wkrpk[19][0]))));
    Atir[20][0] = (Atkr[19][0]+(((Otkr[19][1]*ri[15][2])-(Otkr[19][2]*ri[15][1])
      )+((Wirk[20][2]*wk[19][1])-(Wirk[20][1]*wk[19][2]))));
    Atir[20][1] = (Atkr[19][1]+(((Otkr[19][2]*ri[15][0])-(Otkr[19][0]*ri[15][2])
      )+((Wirk[20][0]*wk[19][2])-(Wirk[20][2]*wk[19][0]))));
    Atir[20][2] = (Atkr[19][2]+(((Otkr[19][0]*ri[15][1])-(Otkr[19][1]*ri[15][0])
      )+((Wirk[20][1]*wk[19][0])-(Wirk[20][0]*wk[19][1]))));
    Atkr[20][0] = (((Atir[20][0]*c20)-(Atir[20][2]*s20))+(((Otkr[20][2]*
      rk[15][1])-(Otkr[20][1]*rk[15][2]))+((wk[20][1]*Wkrpk[20][2])-(wk[20][2]*
      Wkrpk[20][1]))));
    Atkr[20][1] = (Atir[20][1]+(((Otkr[20][0]*rk[15][2])-(Otkr[20][2]*rk[15][0])
      )+((wk[20][2]*Wkrpk[20][0])-(wk[20][0]*Wkrpk[20][2]))));
    Atkr[20][2] = (((Atir[20][0]*s20)+(Atir[20][2]*c20))+(((Otkr[20][1]*
      rk[15][0])-(Otkr[20][0]*rk[15][1]))+((wk[20][0]*Wkrpk[20][1])-(wk[20][1]*
      Wkrpk[20][0]))));
    Atir[21][0] = (Atkr[20][0]+(((Otkr[20][1]*ri[16][2])-(Otkr[20][2]*ri[16][1])
      )+((Wirk[21][2]*wk[20][1])-(Wirk[21][1]*wk[20][2]))));
    Atir[21][1] = (Atkr[20][1]+(((Otkr[20][2]*ri[16][0])-(Otkr[20][0]*ri[16][2])
      )+((Wirk[21][0]*wk[20][2])-(Wirk[21][2]*wk[20][0]))));
    Atir[21][2] = (Atkr[20][2]+(((Otkr[20][0]*ri[16][1])-(Otkr[20][1]*ri[16][0])
      )+((Wirk[21][1]*wk[20][0])-(Wirk[21][0]*wk[20][1]))));
    Atkr[21][0] = (((Atir[21][0]*c21)+(Atir[21][1]*s21))+(((Otkr[21][2]*
      rk[16][1])-(Otkr[21][1]*rk[16][2]))+((wk[21][1]*Wkrpk[21][2])-(wk[21][2]*
      Wkrpk[21][1]))));
    Atkr[21][1] = (((Atir[21][1]*c21)-(Atir[21][0]*s21))+(((Otkr[21][0]*
      rk[16][2])-(Otkr[21][2]*rk[16][0]))+((wk[21][2]*Wkrpk[21][0])-(wk[21][0]*
      Wkrpk[21][2]))));
    Atkr[21][2] = (Atir[21][2]+(((Otkr[21][1]*rk[16][0])-(Otkr[21][0]*rk[16][1])
      )+((wk[21][0]*Wkrpk[21][1])-(wk[21][1]*Wkrpk[21][0]))));
    Atir[22][0] = (Atkr[5][0]+(((ri[17][2]*udotin[4])-(ri[17][1]*udotin[5]))+((
      u[4]*Wirk[22][2])-(u[5]*Wirk[22][1]))));
    Atir[22][1] = (Atkr[5][1]+(((ri[17][0]*udotin[5])-(ri[17][2]*udotin[3]))+((
      u[5]*Wirk[22][0])-(u[3]*Wirk[22][2]))));
    Atir[22][2] = (Atkr[5][2]+(((ri[17][1]*udotin[3])-(ri[17][0]*udotin[4]))+((
      u[3]*Wirk[22][1])-(u[4]*Wirk[22][0]))));
    Atkr[22][0] = (((Atir[22][0]*c22)-(Atir[22][2]*s22))+(((Otkr[22][2]*
      rk[17][1])-(Otkr[22][1]*rk[17][2]))+((wk[22][1]*Wkrpk[22][2])-(wk[22][2]*
      Wkrpk[22][1]))));
    Atkr[22][1] = (Atir[22][1]+(((Otkr[22][0]*rk[17][2])-(Otkr[22][2]*rk[17][0])
      )+((wk[22][2]*Wkrpk[22][0])-(wk[22][0]*Wkrpk[22][2]))));
    Atkr[22][2] = (((Atir[22][0]*s22)+(Atir[22][2]*c22))+(((Otkr[22][1]*
      rk[17][0])-(Otkr[22][0]*rk[17][1]))+((wk[22][0]*Wkrpk[22][1])-(wk[22][1]*
      Wkrpk[22][0]))));
    Atir[23][0] = (Atkr[22][0]+(((Otkr[22][1]*ri[18][2])-(Otkr[22][2]*ri[18][1])
      )+((Wirk[23][2]*wk[22][1])-(Wirk[23][1]*wk[22][2]))));
    Atir[23][1] = (Atkr[22][1]+(((Otkr[22][2]*ri[18][0])-(Otkr[22][0]*ri[18][2])
      )+((Wirk[23][0]*wk[22][2])-(Wirk[23][2]*wk[22][0]))));
    Atir[23][2] = (Atkr[22][2]+(((Otkr[22][0]*ri[18][1])-(Otkr[22][1]*ri[18][0])
      )+((Wirk[23][1]*wk[22][0])-(Wirk[23][0]*wk[22][1]))));
    Atkr[23][0] = (Atir[23][0]+(((Otkr[23][2]*rk[18][1])-(Otkr[23][1]*rk[18][2])
      )+((wk[23][1]*Wkrpk[23][2])-(wk[23][2]*Wkrpk[23][1]))));
    Atkr[23][1] = (((Atir[23][1]*c23)+(Atir[23][2]*s23))+(((Otkr[23][0]*
      rk[18][2])-(Otkr[23][2]*rk[18][0]))+((wk[23][2]*Wkrpk[23][0])-(wk[23][0]*
      Wkrpk[23][2]))));
    Atkr[23][2] = (((Atir[23][2]*c23)-(Atir[23][1]*s23))+(((Otkr[23][1]*
      rk[18][0])-(Otkr[23][0]*rk[18][1]))+((wk[23][0]*Wkrpk[23][1])-(wk[23][1]*
      Wkrpk[23][0]))));
    Atir[24][0] = (Atkr[23][0]+(((Otkr[23][1]*ri[19][2])-(Otkr[23][2]*ri[19][1])
      )+((Wirk[24][2]*wk[23][1])-(Wirk[24][1]*wk[23][2]))));
    Atir[24][1] = (Atkr[23][1]+(((Otkr[23][2]*ri[19][0])-(Otkr[23][0]*ri[19][2])
      )+((Wirk[24][0]*wk[23][2])-(Wirk[24][2]*wk[23][0]))));
    Atir[24][2] = (Atkr[23][2]+(((Otkr[23][0]*ri[19][1])-(Otkr[23][1]*ri[19][0])
      )+((Wirk[24][1]*wk[23][0])-(Wirk[24][0]*wk[23][1]))));
    Atkr[24][0] = (((Atir[24][0]*c24)-(Atir[24][2]*s24))+(((Otkr[24][2]*
      rk[19][1])-(Otkr[24][1]*rk[19][2]))+((wk[24][1]*Wkrpk[24][2])-(wk[24][2]*
      Wkrpk[24][1]))));
    Atkr[24][1] = (Atir[24][1]+(((Otkr[24][0]*rk[19][2])-(Otkr[24][2]*rk[19][0])
      )+((wk[24][2]*Wkrpk[24][0])-(wk[24][0]*Wkrpk[24][2]))));
    Atkr[24][2] = (((Atir[24][0]*s24)+(Atir[24][2]*c24))+(((Otkr[24][1]*
      rk[19][0])-(Otkr[24][0]*rk[19][1]))+((wk[24][0]*Wkrpk[24][1])-(wk[24][1]*
      Wkrpk[24][0]))));
    Atir[25][0] = (Atkr[24][0]+(((Otkr[24][1]*ri[20][2])-(Otkr[24][2]*ri[20][1])
      )+((Wirk[25][2]*wk[24][1])-(Wirk[25][1]*wk[24][2]))));
    Atir[25][1] = (Atkr[24][1]+(((Otkr[24][2]*ri[20][0])-(Otkr[24][0]*ri[20][2])
      )+((Wirk[25][0]*wk[24][2])-(Wirk[25][2]*wk[24][0]))));
    Atir[25][2] = (Atkr[24][2]+(((Otkr[24][0]*ri[20][1])-(Otkr[24][1]*ri[20][0])
      )+((Wirk[25][1]*wk[24][0])-(Wirk[25][0]*wk[24][1]))));
    Atkr[25][0] = (((Atir[25][0]*c25)+(Atir[25][1]*s25))+(((Otkr[25][2]*
      rk[20][1])-(Otkr[25][1]*rk[20][2]))+((wk[25][1]*Wkrpk[25][2])-(wk[25][2]*
      Wkrpk[25][1]))));
    Atkr[25][1] = (((Atir[25][1]*c25)-(Atir[25][0]*s25))+(((Otkr[25][0]*
      rk[20][2])-(Otkr[25][2]*rk[20][0]))+((wk[25][2]*Wkrpk[25][0])-(wk[25][0]*
      Wkrpk[25][2]))));
    Atkr[25][2] = (Atir[25][2]+(((Otkr[25][1]*rk[20][0])-(Otkr[25][0]*rk[20][1])
      )+((wk[25][0]*Wkrpk[25][1])-(wk[25][1]*Wkrpk[25][0]))));
/*
Accumulate all forces and torques
*/
    fstarr[5][0] = (ufk[0][0]-(mk[0]*(Atkr[5][0]+(9.81*Cik[3][2][0]))));
    fstarr[5][1] = (ufk[0][1]-(mk[0]*(Atkr[5][1]+(9.81*Cik[3][2][1]))));
    fstarr[5][2] = (ufk[0][2]-(mk[0]*(Atkr[5][2]+(9.81*Cik[3][2][2]))));
    fstarr[6][0] = (ufk[1][0]+(mk[1]*(gk[6][0]-Atkr[6][0])));
    fstarr[6][1] = (ufk[1][1]+(mk[1]*(gk[6][1]-Atkr[6][1])));
    fstarr[6][2] = (ufk[1][2]-(mk[1]*(Atkr[6][2]+(9.81*Cik[3][2][2]))));
    fstarr[7][0] = (ufk[2][0]+(mk[2]*(gk[7][0]-Atkr[7][0])));
    fstarr[7][1] = (ufk[2][1]+(mk[2]*(gk[6][1]-Atkr[7][1])));
    fstarr[7][2] = (ufk[2][2]+(mk[2]*(gk[7][2]-Atkr[7][2])));
    fstarr[8][0] = (ufk[3][0]+(mk[3]*(gk[7][0]-Atkr[8][0])));
    fstarr[8][1] = (ufk[3][1]+(mk[3]*(gk[8][1]-Atkr[8][1])));
    fstarr[8][2] = (ufk[3][2]+(mk[3]*(gk[8][2]-Atkr[8][2])));
    fstarr[9][0] = (ufk[4][0]+(mk[4]*(gk[9][0]-Atkr[9][0])));
    fstarr[9][1] = (ufk[4][1]+(mk[4]*(gk[8][1]-Atkr[9][1])));
    fstarr[9][2] = (ufk[4][2]+(mk[4]*(gk[9][2]-Atkr[9][2])));
    fstarr[10][0] = (ufk[5][0]+(mk[5]*(gk[10][0]-Atkr[10][0])));
    fstarr[10][1] = (ufk[5][1]+(mk[5]*(gk[8][1]-Atkr[10][1])));
    fstarr[10][2] = (ufk[5][2]+(mk[5]*(gk[10][2]-Atkr[10][2])));
    fstarr[11][0] = (ufk[6][0]+(mk[6]*(gk[10][0]-Atkr[11][0])));
    fstarr[11][1] = (ufk[6][1]+(mk[6]*(gk[11][1]-Atkr[11][1])));
    fstarr[11][2] = (ufk[6][2]+(mk[6]*(gk[11][2]-Atkr[11][2])));
    fstarr[12][0] = (ufk[7][0]+(mk[7]*(gk[12][0]-Atkr[12][0])));
    fstarr[12][1] = (ufk[7][1]+(mk[7]*(gk[12][1]-Atkr[12][1])));
    fstarr[12][2] = (ufk[7][2]-(mk[7]*(Atkr[12][2]+(9.81*Cik[3][2][2]))));
    fstarr[13][0] = (ufk[8][0]+(mk[8]*(gk[13][0]-Atkr[13][0])));
    fstarr[13][1] = (ufk[8][1]+(mk[8]*(gk[12][1]-Atkr[13][1])));
    fstarr[13][2] = (ufk[8][2]+(mk[8]*(gk[13][2]-Atkr[13][2])));
    fstarr[14][0] = (ufk[9][0]+(mk[9]*(gk[13][0]-Atkr[14][0])));
    fstarr[14][1] = (ufk[9][1]+(mk[9]*(gk[14][1]-Atkr[14][1])));
    fstarr[14][2] = (ufk[9][2]+(mk[9]*(gk[14][2]-Atkr[14][2])));
    fstarr[15][0] = (ufk[10][0]+(mk[10]*(gk[15][0]-Atkr[15][0])));
    fstarr[15][1] = (ufk[10][1]+(mk[10]*(gk[14][1]-Atkr[15][1])));
    fstarr[15][2] = (ufk[10][2]+(mk[10]*(gk[15][2]-Atkr[15][2])));
    fstarr[16][0] = (ufk[11][0]+(mk[11]*(gk[16][0]-Atkr[16][0])));
    fstarr[16][1] = (ufk[11][1]+(mk[11]*(gk[14][1]-Atkr[16][1])));
    fstarr[16][2] = (ufk[11][2]+(mk[11]*(gk[16][2]-Atkr[16][2])));
    fstarr[17][0] = (ufk[12][0]+(mk[12]*(gk[16][0]-Atkr[17][0])));
    fstarr[17][1] = (ufk[12][1]+(mk[12]*(gk[17][1]-Atkr[17][1])));
    fstarr[17][2] = (ufk[12][2]+(mk[12]*(gk[17][2]-Atkr[17][2])));
    fstarr[18][0] = (ufk[13][0]+(mk[13]*(gk[18][0]-Atkr[18][0])));
    fstarr[18][1] = (ufk[13][1]-(mk[13]*(Atkr[18][1]+(9.81*Cik[3][2][1]))));
    fstarr[18][2] = (ufk[13][2]+(mk[13]*(gk[18][2]-Atkr[18][2])));
    fstarr[19][0] = (ufk[14][0]+(mk[14]*(gk[18][0]-Atkr[19][0])));
    fstarr[19][1] = (ufk[14][1]+(mk[14]*(gk[19][1]-Atkr[19][1])));
    fstarr[19][2] = (ufk[14][2]+(mk[14]*(gk[19][2]-Atkr[19][2])));
    fstarr[20][0] = (ufk[15][0]+(mk[15]*(gk[20][0]-Atkr[20][0])));
    fstarr[20][1] = (ufk[15][1]+(mk[15]*(gk[19][1]-Atkr[20][1])));
    fstarr[20][2] = (ufk[15][2]+(mk[15]*(gk[20][2]-Atkr[20][2])));
    fstarr[21][0] = (ufk[16][0]+(mk[16]*(gk[21][0]-Atkr[21][0])));
    fstarr[21][1] = (ufk[16][1]+(mk[16]*(gk[21][1]-Atkr[21][1])));
    fstarr[21][2] = (ufk[16][2]+(mk[16]*(gk[20][2]-Atkr[21][2])));
    fstarr[22][0] = (ufk[17][0]+(mk[17]*(gk[22][0]-Atkr[22][0])));
    fstarr[22][1] = (ufk[17][1]-(mk[17]*(Atkr[22][1]+(9.81*Cik[3][2][1]))));
    fstarr[22][2] = (ufk[17][2]+(mk[17]*(gk[22][2]-Atkr[22][2])));
    fstarr[23][0] = (ufk[18][0]+(mk[18]*(gk[22][0]-Atkr[23][0])));
    fstarr[23][1] = (ufk[18][1]+(mk[18]*(gk[23][1]-Atkr[23][1])));
    fstarr[23][2] = (ufk[18][2]+(mk[18]*(gk[23][2]-Atkr[23][2])));
    fstarr[24][0] = (ufk[19][0]+(mk[19]*(gk[24][0]-Atkr[24][0])));
    fstarr[24][1] = (ufk[19][1]+(mk[19]*(gk[23][1]-Atkr[24][1])));
    fstarr[24][2] = (ufk[19][2]+(mk[19]*(gk[24][2]-Atkr[24][2])));
    fstarr[25][0] = (ufk[20][0]+(mk[20]*(gk[25][0]-Atkr[25][0])));
    fstarr[25][1] = (ufk[20][1]+(mk[20]*(gk[25][1]-Atkr[25][1])));
    fstarr[25][2] = (ufk[20][2]+(mk[20]*(gk[24][2]-Atkr[25][2])));
    tstarr[5][0] = (utk[0][0]-(WkIkWk[5][0]+((ik[0][0][2]*udotin[5])+((
      ik[0][0][0]*udotin[3])+(ik[0][0][1]*udotin[4])))));
    tstarr[5][1] = (utk[0][1]-(WkIkWk[5][1]+((ik[0][1][2]*udotin[5])+((
      ik[0][1][0]*udotin[3])+(ik[0][1][1]*udotin[4])))));
    tstarr[5][2] = (utk[0][2]-(WkIkWk[5][2]+((ik[0][2][2]*udotin[5])+((
      ik[0][2][0]*udotin[3])+(ik[0][2][1]*udotin[4])))));
    tstarr[6][0] = (utk[1][0]-(WkIkWk[6][0]+((ik[1][0][2]*Otkr[6][2])+((
      ik[1][0][0]*Otkr[6][0])+(ik[1][0][1]*Otkr[6][1])))));
    tstarr[6][1] = (utk[1][1]-(WkIkWk[6][1]+((ik[1][1][2]*Otkr[6][2])+((
      ik[1][1][0]*Otkr[6][0])+(ik[1][1][1]*Otkr[6][1])))));
    tstarr[6][2] = (utk[1][2]-(WkIkWk[6][2]+((ik[1][2][2]*Otkr[6][2])+((
      ik[1][2][0]*Otkr[6][0])+(ik[1][2][1]*Otkr[6][1])))));
    tstarr[7][0] = (utk[2][0]-(WkIkWk[7][0]+((ik[2][0][2]*Otkr[7][2])+((
      ik[2][0][0]*Otkr[7][0])+(ik[2][0][1]*Otkr[7][1])))));
    tstarr[7][1] = (utk[2][1]-(WkIkWk[7][1]+((ik[2][1][2]*Otkr[7][2])+((
      ik[2][1][0]*Otkr[7][0])+(ik[2][1][1]*Otkr[7][1])))));
    tstarr[7][2] = (utk[2][2]-(WkIkWk[7][2]+((ik[2][2][2]*Otkr[7][2])+((
      ik[2][2][0]*Otkr[7][0])+(ik[2][2][1]*Otkr[7][1])))));
    tstarr[8][0] = (utk[3][0]-(WkIkWk[8][0]+((ik[3][0][2]*Otkr[8][2])+((
      ik[3][0][0]*Otkr[8][0])+(ik[3][0][1]*Otkr[8][1])))));
    tstarr[8][1] = (utk[3][1]-(WkIkWk[8][1]+((ik[3][1][2]*Otkr[8][2])+((
      ik[3][1][0]*Otkr[8][0])+(ik[3][1][1]*Otkr[8][1])))));
    tstarr[8][2] = (utk[3][2]-(WkIkWk[8][2]+((ik[3][2][2]*Otkr[8][2])+((
      ik[3][2][0]*Otkr[8][0])+(ik[3][2][1]*Otkr[8][1])))));
    tstarr[9][0] = (utk[4][0]-(WkIkWk[9][0]+((ik[4][0][2]*Otkr[9][2])+((
      ik[4][0][0]*Otkr[9][0])+(ik[4][0][1]*Otkr[9][1])))));
    tstarr[9][1] = (utk[4][1]-(WkIkWk[9][1]+((ik[4][1][2]*Otkr[9][2])+((
      ik[4][1][0]*Otkr[9][0])+(ik[4][1][1]*Otkr[9][1])))));
    tstarr[9][2] = (utk[4][2]-(WkIkWk[9][2]+((ik[4][2][2]*Otkr[9][2])+((
      ik[4][2][0]*Otkr[9][0])+(ik[4][2][1]*Otkr[9][1])))));
    tstarr[10][0] = (utk[5][0]-(WkIkWk[10][0]+((ik[5][0][2]*Otkr[10][2])+((
      ik[5][0][0]*Otkr[10][0])+(ik[5][0][1]*Otkr[10][1])))));
    tstarr[10][1] = (utk[5][1]-(WkIkWk[10][1]+((ik[5][1][2]*Otkr[10][2])+((
      ik[5][1][0]*Otkr[10][0])+(ik[5][1][1]*Otkr[10][1])))));
    tstarr[10][2] = (utk[5][2]-(WkIkWk[10][2]+((ik[5][2][2]*Otkr[10][2])+((
      ik[5][2][0]*Otkr[10][0])+(ik[5][2][1]*Otkr[10][1])))));
    tstarr[11][0] = (utk[6][0]-(WkIkWk[11][0]+((ik[6][0][2]*Otkr[11][2])+((
      ik[6][0][0]*Otkr[11][0])+(ik[6][0][1]*Otkr[11][1])))));
    tstarr[11][1] = (utk[6][1]-(WkIkWk[11][1]+((ik[6][1][2]*Otkr[11][2])+((
      ik[6][1][0]*Otkr[11][0])+(ik[6][1][1]*Otkr[11][1])))));
    tstarr[11][2] = (utk[6][2]-(WkIkWk[11][2]+((ik[6][2][2]*Otkr[11][2])+((
      ik[6][2][0]*Otkr[11][0])+(ik[6][2][1]*Otkr[11][1])))));
    tstarr[12][0] = (utk[7][0]-(WkIkWk[12][0]+((ik[7][0][2]*Otkr[12][2])+((
      ik[7][0][0]*Otkr[12][0])+(ik[7][0][1]*Otkr[12][1])))));
    tstarr[12][1] = (utk[7][1]-(WkIkWk[12][1]+((ik[7][1][2]*Otkr[12][2])+((
      ik[7][1][0]*Otkr[12][0])+(ik[7][1][1]*Otkr[12][1])))));
    tstarr[12][2] = (utk[7][2]-(WkIkWk[12][2]+((ik[7][2][2]*Otkr[12][2])+((
      ik[7][2][0]*Otkr[12][0])+(ik[7][2][1]*Otkr[12][1])))));
    tstarr[13][0] = (utk[8][0]-(WkIkWk[13][0]+((ik[8][0][2]*Otkr[13][2])+((
      ik[8][0][0]*Otkr[13][0])+(ik[8][0][1]*Otkr[13][1])))));
    tstarr[13][1] = (utk[8][1]-(WkIkWk[13][1]+((ik[8][1][2]*Otkr[13][2])+((
      ik[8][1][0]*Otkr[13][0])+(ik[8][1][1]*Otkr[13][1])))));
    tstarr[13][2] = (utk[8][2]-(WkIkWk[13][2]+((ik[8][2][2]*Otkr[13][2])+((
      ik[8][2][0]*Otkr[13][0])+(ik[8][2][1]*Otkr[13][1])))));
    tstarr[14][0] = (utk[9][0]-(WkIkWk[14][0]+((ik[9][0][2]*Otkr[14][2])+((
      ik[9][0][0]*Otkr[14][0])+(ik[9][0][1]*Otkr[14][1])))));
    tstarr[14][1] = (utk[9][1]-(WkIkWk[14][1]+((ik[9][1][2]*Otkr[14][2])+((
      ik[9][1][0]*Otkr[14][0])+(ik[9][1][1]*Otkr[14][1])))));
    tstarr[14][2] = (utk[9][2]-(WkIkWk[14][2]+((ik[9][2][2]*Otkr[14][2])+((
      ik[9][2][0]*Otkr[14][0])+(ik[9][2][1]*Otkr[14][1])))));
    tstarr[15][0] = (utk[10][0]-(WkIkWk[15][0]+((ik[10][0][2]*Otkr[15][2])+((
      ik[10][0][0]*Otkr[15][0])+(ik[10][0][1]*Otkr[15][1])))));
    tstarr[15][1] = (utk[10][1]-(WkIkWk[15][1]+((ik[10][1][2]*Otkr[15][2])+((
      ik[10][1][0]*Otkr[15][0])+(ik[10][1][1]*Otkr[15][1])))));
    tstarr[15][2] = (utk[10][2]-(WkIkWk[15][2]+((ik[10][2][2]*Otkr[15][2])+((
      ik[10][2][0]*Otkr[15][0])+(ik[10][2][1]*Otkr[15][1])))));
    tstarr[16][0] = (utk[11][0]-(WkIkWk[16][0]+((ik[11][0][2]*Otkr[16][2])+((
      ik[11][0][0]*Otkr[16][0])+(ik[11][0][1]*Otkr[16][1])))));
    tstarr[16][1] = (utk[11][1]-(WkIkWk[16][1]+((ik[11][1][2]*Otkr[16][2])+((
      ik[11][1][0]*Otkr[16][0])+(ik[11][1][1]*Otkr[16][1])))));
    tstarr[16][2] = (utk[11][2]-(WkIkWk[16][2]+((ik[11][2][2]*Otkr[16][2])+((
      ik[11][2][0]*Otkr[16][0])+(ik[11][2][1]*Otkr[16][1])))));
    tstarr[17][0] = (utk[12][0]-(WkIkWk[17][0]+((ik[12][0][2]*Otkr[17][2])+((
      ik[12][0][0]*Otkr[17][0])+(ik[12][0][1]*Otkr[17][1])))));
    tstarr[17][1] = (utk[12][1]-(WkIkWk[17][1]+((ik[12][1][2]*Otkr[17][2])+((
      ik[12][1][0]*Otkr[17][0])+(ik[12][1][1]*Otkr[17][1])))));
    tstarr[17][2] = (utk[12][2]-(WkIkWk[17][2]+((ik[12][2][2]*Otkr[17][2])+((
      ik[12][2][0]*Otkr[17][0])+(ik[12][2][1]*Otkr[17][1])))));
    tstarr[18][0] = (utk[13][0]-(WkIkWk[18][0]+((ik[13][0][2]*Otkr[18][2])+((
      ik[13][0][0]*Otkr[18][0])+(ik[13][0][1]*Otkr[18][1])))));
    tstarr[18][1] = (utk[13][1]-(WkIkWk[18][1]+((ik[13][1][2]*Otkr[18][2])+((
      ik[13][1][0]*Otkr[18][0])+(ik[13][1][1]*Otkr[18][1])))));
    tstarr[18][2] = (utk[13][2]-(WkIkWk[18][2]+((ik[13][2][2]*Otkr[18][2])+((
      ik[13][2][0]*Otkr[18][0])+(ik[13][2][1]*Otkr[18][1])))));
    tstarr[19][0] = (utk[14][0]-(WkIkWk[19][0]+((ik[14][0][2]*Otkr[19][2])+((
      ik[14][0][0]*Otkr[19][0])+(ik[14][0][1]*Otkr[19][1])))));
    tstarr[19][1] = (utk[14][1]-(WkIkWk[19][1]+((ik[14][1][2]*Otkr[19][2])+((
      ik[14][1][0]*Otkr[19][0])+(ik[14][1][1]*Otkr[19][1])))));
    tstarr[19][2] = (utk[14][2]-(WkIkWk[19][2]+((ik[14][2][2]*Otkr[19][2])+((
      ik[14][2][0]*Otkr[19][0])+(ik[14][2][1]*Otkr[19][1])))));
    tstarr[20][0] = (utk[15][0]-(WkIkWk[20][0]+((ik[15][0][2]*Otkr[20][2])+((
      ik[15][0][0]*Otkr[20][0])+(ik[15][0][1]*Otkr[20][1])))));
    tstarr[20][1] = (utk[15][1]-(WkIkWk[20][1]+((ik[15][1][2]*Otkr[20][2])+((
      ik[15][1][0]*Otkr[20][0])+(ik[15][1][1]*Otkr[20][1])))));
    tstarr[20][2] = (utk[15][2]-(WkIkWk[20][2]+((ik[15][2][2]*Otkr[20][2])+((
      ik[15][2][0]*Otkr[20][0])+(ik[15][2][1]*Otkr[20][1])))));
    tstarr[21][0] = (utk[16][0]-(WkIkWk[21][0]+((ik[16][0][2]*Otkr[21][2])+((
      ik[16][0][0]*Otkr[21][0])+(ik[16][0][1]*Otkr[21][1])))));
    tstarr[21][1] = (utk[16][1]-(WkIkWk[21][1]+((ik[16][1][2]*Otkr[21][2])+((
      ik[16][1][0]*Otkr[21][0])+(ik[16][1][1]*Otkr[21][1])))));
    tstarr[21][2] = (utk[16][2]-(WkIkWk[21][2]+((ik[16][2][2]*Otkr[21][2])+((
      ik[16][2][0]*Otkr[21][0])+(ik[16][2][1]*Otkr[21][1])))));
    tstarr[22][0] = (utk[17][0]-(WkIkWk[22][0]+((ik[17][0][2]*Otkr[22][2])+((
      ik[17][0][0]*Otkr[22][0])+(ik[17][0][1]*Otkr[22][1])))));
    tstarr[22][1] = (utk[17][1]-(WkIkWk[22][1]+((ik[17][1][2]*Otkr[22][2])+((
      ik[17][1][0]*Otkr[22][0])+(ik[17][1][1]*Otkr[22][1])))));
    tstarr[22][2] = (utk[17][2]-(WkIkWk[22][2]+((ik[17][2][2]*Otkr[22][2])+((
      ik[17][2][0]*Otkr[22][0])+(ik[17][2][1]*Otkr[22][1])))));
    tstarr[23][0] = (utk[18][0]-(WkIkWk[23][0]+((ik[18][0][2]*Otkr[23][2])+((
      ik[18][0][0]*Otkr[23][0])+(ik[18][0][1]*Otkr[23][1])))));
    tstarr[23][1] = (utk[18][1]-(WkIkWk[23][1]+((ik[18][1][2]*Otkr[23][2])+((
      ik[18][1][0]*Otkr[23][0])+(ik[18][1][1]*Otkr[23][1])))));
    tstarr[23][2] = (utk[18][2]-(WkIkWk[23][2]+((ik[18][2][2]*Otkr[23][2])+((
      ik[18][2][0]*Otkr[23][0])+(ik[18][2][1]*Otkr[23][1])))));
    tstarr[24][0] = (utk[19][0]-(WkIkWk[24][0]+((ik[19][0][2]*Otkr[24][2])+((
      ik[19][0][0]*Otkr[24][0])+(ik[19][0][1]*Otkr[24][1])))));
    tstarr[24][1] = (utk[19][1]-(WkIkWk[24][1]+((ik[19][1][2]*Otkr[24][2])+((
      ik[19][1][0]*Otkr[24][0])+(ik[19][1][1]*Otkr[24][1])))));
    tstarr[24][2] = (utk[19][2]-(WkIkWk[24][2]+((ik[19][2][2]*Otkr[24][2])+((
      ik[19][2][0]*Otkr[24][0])+(ik[19][2][1]*Otkr[24][1])))));
    tstarr[25][0] = (utk[20][0]-(WkIkWk[25][0]+((ik[20][0][2]*Otkr[25][2])+((
      ik[20][0][0]*Otkr[25][0])+(ik[20][0][1]*Otkr[25][1])))));
    tstarr[25][1] = (utk[20][1]-(WkIkWk[25][1]+((ik[20][1][2]*Otkr[25][2])+((
      ik[20][1][0]*Otkr[25][0])+(ik[20][1][1]*Otkr[25][1])))));
    tstarr[25][2] = (utk[20][2]-(WkIkWk[25][2]+((ik[20][2][2]*Otkr[25][2])+((
      ik[20][2][0]*Otkr[25][0])+(ik[20][2][1]*Otkr[25][1])))));
/*
Now calculate the torques
*/
    sddovpk();
    temp[0] = (((fstarr[8][2]*Vpk[0][8][2])+((fstarr[8][0]*Vpk[0][7][0])+(
      fstarr[8][1]*Vpk[0][8][1])))+(((fstarr[7][2]*Vpk[0][7][2])+((fstarr[7][0]*
      Vpk[0][7][0])+(fstarr[7][1]*Vpk[0][6][1])))+(((Cik[3][0][2]*fstarr[5][2])+
      ((Cik[3][0][0]*fstarr[5][0])+(Cik[3][0][1]*fstarr[5][1])))+((Cik[3][0][2]*
      fstarr[6][2])+((fstarr[6][0]*Vpk[0][6][0])+(fstarr[6][1]*Vpk[0][6][1])))))
      );
    temp[1] = (((Cik[3][0][2]*fstarr[12][2])+((fstarr[12][0]*Vpk[0][12][0])+(
      fstarr[12][1]*Vpk[0][12][1])))+(((fstarr[11][2]*Vpk[0][11][2])+((
      fstarr[11][0]*Vpk[0][10][0])+(fstarr[11][1]*Vpk[0][11][1])))+(((
      fstarr[10][2]*Vpk[0][10][2])+((fstarr[10][0]*Vpk[0][10][0])+(fstarr[10][1]
      *Vpk[0][8][1])))+(((fstarr[9][2]*Vpk[0][9][2])+((fstarr[9][0]*Vpk[0][9][0]
      )+(fstarr[9][1]*Vpk[0][8][1])))+temp[0]))));
    temp[2] = (((fstarr[16][2]*Vpk[0][16][2])+((fstarr[16][0]*Vpk[0][16][0])+(
      fstarr[16][1]*Vpk[0][14][1])))+(((fstarr[15][2]*Vpk[0][15][2])+((
      fstarr[15][0]*Vpk[0][15][0])+(fstarr[15][1]*Vpk[0][14][1])))+(((
      fstarr[14][2]*Vpk[0][14][2])+((fstarr[14][0]*Vpk[0][13][0])+(fstarr[14][1]
      *Vpk[0][14][1])))+(((fstarr[13][2]*Vpk[0][13][2])+((fstarr[13][0]*
      Vpk[0][13][0])+(fstarr[13][1]*Vpk[0][12][1])))+temp[1]))));
    temp[3] = (((fstarr[20][2]*Vpk[0][20][2])+((fstarr[20][0]*Vpk[0][20][0])+(
      fstarr[20][1]*Vpk[0][19][1])))+(((fstarr[19][2]*Vpk[0][19][2])+((
      fstarr[19][0]*Vpk[0][18][0])+(fstarr[19][1]*Vpk[0][19][1])))+(((
      fstarr[18][2]*Vpk[0][18][2])+((Cik[3][0][1]*fstarr[18][1])+(fstarr[18][0]*
      Vpk[0][18][0])))+(((fstarr[17][2]*Vpk[0][17][2])+((fstarr[17][0]*
      Vpk[0][16][0])+(fstarr[17][1]*Vpk[0][17][1])))+temp[2]))));
    temp[4] = (((fstarr[24][2]*Vpk[0][24][2])+((fstarr[24][0]*Vpk[0][24][0])+(
      fstarr[24][1]*Vpk[0][23][1])))+(((fstarr[23][2]*Vpk[0][23][2])+((
      fstarr[23][0]*Vpk[0][22][0])+(fstarr[23][1]*Vpk[0][23][1])))+(((
      fstarr[22][2]*Vpk[0][22][2])+((Cik[3][0][1]*fstarr[22][1])+(fstarr[22][0]*
      Vpk[0][22][0])))+(((fstarr[21][2]*Vpk[0][20][2])+((fstarr[21][0]*
      Vpk[0][21][0])+(fstarr[21][1]*Vpk[0][21][1])))+temp[3]))));
    trqout[0] = -(utau[0]+(((fstarr[25][2]*Vpk[0][24][2])+((fstarr[25][0]*
      Vpk[0][25][0])+(fstarr[25][1]*Vpk[0][25][1])))+temp[4]));
    temp[0] = (((fstarr[8][2]*Vpk[1][8][2])+((fstarr[8][0]*Vpk[1][7][0])+(
      fstarr[8][1]*Vpk[1][8][1])))+(((fstarr[7][2]*Vpk[1][7][2])+((fstarr[7][0]*
      Vpk[1][7][0])+(fstarr[7][1]*Vpk[1][6][1])))+(((Cik[3][1][2]*fstarr[5][2])+
      ((Cik[3][1][0]*fstarr[5][0])+(Cik[3][1][1]*fstarr[5][1])))+((Cik[3][1][2]*
      fstarr[6][2])+((fstarr[6][0]*Vpk[1][6][0])+(fstarr[6][1]*Vpk[1][6][1])))))
      );
    temp[1] = (((Cik[3][1][2]*fstarr[12][2])+((fstarr[12][0]*Vpk[1][12][0])+(
      fstarr[12][1]*Vpk[1][12][1])))+(((fstarr[11][2]*Vpk[1][11][2])+((
      fstarr[11][0]*Vpk[1][10][0])+(fstarr[11][1]*Vpk[1][11][1])))+(((
      fstarr[10][2]*Vpk[1][10][2])+((fstarr[10][0]*Vpk[1][10][0])+(fstarr[10][1]
      *Vpk[1][8][1])))+(((fstarr[9][2]*Vpk[1][9][2])+((fstarr[9][0]*Vpk[1][9][0]
      )+(fstarr[9][1]*Vpk[1][8][1])))+temp[0]))));
    temp[2] = (((fstarr[16][2]*Vpk[1][16][2])+((fstarr[16][0]*Vpk[1][16][0])+(
      fstarr[16][1]*Vpk[1][14][1])))+(((fstarr[15][2]*Vpk[1][15][2])+((
      fstarr[15][0]*Vpk[1][15][0])+(fstarr[15][1]*Vpk[1][14][1])))+(((
      fstarr[14][2]*Vpk[1][14][2])+((fstarr[14][0]*Vpk[1][13][0])+(fstarr[14][1]
      *Vpk[1][14][1])))+(((fstarr[13][2]*Vpk[1][13][2])+((fstarr[13][0]*
      Vpk[1][13][0])+(fstarr[13][1]*Vpk[1][12][1])))+temp[1]))));
    temp[3] = (((fstarr[20][2]*Vpk[1][20][2])+((fstarr[20][0]*Vpk[1][20][0])+(
      fstarr[20][1]*Vpk[1][19][1])))+(((fstarr[19][2]*Vpk[1][19][2])+((
      fstarr[19][0]*Vpk[1][18][0])+(fstarr[19][1]*Vpk[1][19][1])))+(((
      fstarr[18][2]*Vpk[1][18][2])+((Cik[3][1][1]*fstarr[18][1])+(fstarr[18][0]*
      Vpk[1][18][0])))+(((fstarr[17][2]*Vpk[1][17][2])+((fstarr[17][0]*
      Vpk[1][16][0])+(fstarr[17][1]*Vpk[1][17][1])))+temp[2]))));
    temp[4] = (((fstarr[24][2]*Vpk[1][24][2])+((fstarr[24][0]*Vpk[1][24][0])+(
      fstarr[24][1]*Vpk[1][23][1])))+(((fstarr[23][2]*Vpk[1][23][2])+((
      fstarr[23][0]*Vpk[1][22][0])+(fstarr[23][1]*Vpk[1][23][1])))+(((
      fstarr[22][2]*Vpk[1][22][2])+((Cik[3][1][1]*fstarr[22][1])+(fstarr[22][0]*
      Vpk[1][22][0])))+(((fstarr[21][2]*Vpk[1][20][2])+((fstarr[21][0]*
      Vpk[1][21][0])+(fstarr[21][1]*Vpk[1][21][1])))+temp[3]))));
    trqout[1] = -(utau[1]+(((fstarr[25][2]*Vpk[1][24][2])+((fstarr[25][0]*
      Vpk[1][25][0])+(fstarr[25][1]*Vpk[1][25][1])))+temp[4]));
    temp[0] = (((fstarr[8][2]*Vpk[2][8][2])+((fstarr[8][0]*Vpk[2][7][0])+(
      fstarr[8][1]*Vpk[2][8][1])))+(((fstarr[7][2]*Vpk[2][7][2])+((fstarr[7][0]*
      Vpk[2][7][0])+(fstarr[7][1]*Vpk[2][6][1])))+(((Cik[3][2][2]*fstarr[5][2])+
      ((Cik[3][2][0]*fstarr[5][0])+(Cik[3][2][1]*fstarr[5][1])))+((Cik[3][2][2]*
      fstarr[6][2])+((fstarr[6][0]*Vpk[2][6][0])+(fstarr[6][1]*Vpk[2][6][1])))))
      );
    temp[1] = (((Cik[3][2][2]*fstarr[12][2])+((fstarr[12][0]*Vpk[2][12][0])+(
      fstarr[12][1]*Vpk[2][12][1])))+(((fstarr[11][2]*Vpk[2][11][2])+((
      fstarr[11][0]*Vpk[2][10][0])+(fstarr[11][1]*Vpk[2][11][1])))+(((
      fstarr[10][2]*Vpk[2][10][2])+((fstarr[10][0]*Vpk[2][10][0])+(fstarr[10][1]
      *Vpk[2][8][1])))+(((fstarr[9][2]*Vpk[2][9][2])+((fstarr[9][0]*Vpk[2][9][0]
      )+(fstarr[9][1]*Vpk[2][8][1])))+temp[0]))));
    temp[2] = (((fstarr[16][2]*Vpk[2][16][2])+((fstarr[16][0]*Vpk[2][16][0])+(
      fstarr[16][1]*Vpk[2][14][1])))+(((fstarr[15][2]*Vpk[2][15][2])+((
      fstarr[15][0]*Vpk[2][15][0])+(fstarr[15][1]*Vpk[2][14][1])))+(((
      fstarr[14][2]*Vpk[2][14][2])+((fstarr[14][0]*Vpk[2][13][0])+(fstarr[14][1]
      *Vpk[2][14][1])))+(((fstarr[13][2]*Vpk[2][13][2])+((fstarr[13][0]*
      Vpk[2][13][0])+(fstarr[13][1]*Vpk[2][12][1])))+temp[1]))));
    temp[3] = (((fstarr[20][2]*Vpk[2][20][2])+((fstarr[20][0]*Vpk[2][20][0])+(
      fstarr[20][1]*Vpk[2][19][1])))+(((fstarr[19][2]*Vpk[2][19][2])+((
      fstarr[19][0]*Vpk[2][18][0])+(fstarr[19][1]*Vpk[2][19][1])))+(((
      fstarr[18][2]*Vpk[2][18][2])+((Cik[3][2][1]*fstarr[18][1])+(fstarr[18][0]*
      Vpk[2][18][0])))+(((fstarr[17][2]*Vpk[2][17][2])+((fstarr[17][0]*
      Vpk[2][16][0])+(fstarr[17][1]*Vpk[2][17][1])))+temp[2]))));
    temp[4] = (((fstarr[24][2]*Vpk[2][24][2])+((fstarr[24][0]*Vpk[2][24][0])+(
      fstarr[24][1]*Vpk[2][23][1])))+(((fstarr[23][2]*Vpk[2][23][2])+((
      fstarr[23][0]*Vpk[2][22][0])+(fstarr[23][1]*Vpk[2][23][1])))+(((
      fstarr[22][2]*Vpk[2][22][2])+((Cik[3][2][1]*fstarr[22][1])+(fstarr[22][0]*
      Vpk[2][22][0])))+(((fstarr[21][2]*Vpk[2][20][2])+((fstarr[21][0]*
      Vpk[2][21][0])+(fstarr[21][1]*Vpk[2][21][1])))+temp[3]))));
    trqout[2] = -(utau[2]+(((fstarr[25][2]*Vpk[2][24][2])+((fstarr[25][0]*
      Vpk[2][25][0])+(fstarr[25][1]*Vpk[2][25][1])))+temp[4]));
    temp[0] = (((tstarr[5][0]+((fstarr[5][1]*rk[0][2])-(fstarr[5][2]*rk[0][1])))
      +(((fstarr[6][2]*Vpk[3][6][2])+((fstarr[6][0]*Vpk[3][6][0])+(fstarr[6][1]*
      Vpk[3][6][1])))+((tstarr[6][0]*c6)-(tstarr[6][1]*s6))))+(((fstarr[7][2]*
      Vpk[3][7][2])+((fstarr[7][0]*Vpk[3][7][0])+(fstarr[7][1]*Vpk[3][7][1])))+(
      (tstarr[7][2]*Wpk[3][7][2])+((tstarr[7][0]*Wpk[3][7][0])-(tstarr[7][1]*s6)
      ))));
    temp[1] = ((((fstarr[9][2]*Vpk[3][9][2])+((fstarr[9][0]*Vpk[3][9][0])+(
      fstarr[9][1]*Vpk[3][9][1])))+((tstarr[9][2]*Wpk[3][9][2])+((tstarr[9][0]*
      Wpk[3][9][0])+(tstarr[9][1]*Wpk[3][8][1]))))+((((fstarr[8][2]*Vpk[3][8][2]
      )+((fstarr[8][0]*Vpk[3][8][0])+(fstarr[8][1]*Vpk[3][8][1])))+((
      tstarr[8][2]*Wpk[3][8][2])+((tstarr[8][0]*Wpk[3][7][0])+(tstarr[8][1]*
      Wpk[3][8][1]))))+temp[0]));
    temp[2] = ((((fstarr[11][2]*Vpk[3][11][2])+((fstarr[11][0]*Vpk[3][11][0])+(
      fstarr[11][1]*Vpk[3][11][1])))+((tstarr[11][2]*Wpk[3][11][2])+((
      tstarr[11][0]*Wpk[3][10][0])+(tstarr[11][1]*Wpk[3][11][1]))))+((((
      fstarr[10][2]*Vpk[3][10][2])+((fstarr[10][0]*Vpk[3][10][0])+(fstarr[10][1]
      *Vpk[3][10][1])))+((tstarr[10][2]*Wpk[3][10][2])+((tstarr[10][0]*
      Wpk[3][10][0])+(tstarr[10][1]*Wpk[3][8][1]))))+temp[1]));
    temp[3] = ((((fstarr[13][2]*Vpk[3][13][2])+((fstarr[13][0]*Vpk[3][13][0])+(
      fstarr[13][1]*Vpk[3][13][1])))+((tstarr[13][2]*Wpk[3][13][2])+((
      tstarr[13][0]*Wpk[3][13][0])-(tstarr[13][1]*s12))))+((((fstarr[12][2]*
      Vpk[3][12][2])+((fstarr[12][0]*Vpk[3][12][0])+(fstarr[12][1]*Vpk[3][12][1]
      )))+((tstarr[12][0]*c12)-(tstarr[12][1]*s12)))+temp[2]));
    temp[4] = ((((fstarr[15][2]*Vpk[3][15][2])+((fstarr[15][0]*Vpk[3][15][0])+(
      fstarr[15][1]*Vpk[3][15][1])))+((tstarr[15][2]*Wpk[3][15][2])+((
      tstarr[15][0]*Wpk[3][15][0])+(tstarr[15][1]*Wpk[3][14][1]))))+((((
      fstarr[14][2]*Vpk[3][14][2])+((fstarr[14][0]*Vpk[3][14][0])+(fstarr[14][1]
      *Vpk[3][14][1])))+((tstarr[14][2]*Wpk[3][14][2])+((tstarr[14][0]*
      Wpk[3][13][0])+(tstarr[14][1]*Wpk[3][14][1]))))+temp[3]));
    temp[5] = ((((fstarr[17][2]*Vpk[3][17][2])+((fstarr[17][0]*Vpk[3][17][0])+(
      fstarr[17][1]*Vpk[3][17][1])))+((tstarr[17][2]*Wpk[3][17][2])+((
      tstarr[17][0]*Wpk[3][16][0])+(tstarr[17][1]*Wpk[3][17][1]))))+((((
      fstarr[16][2]*Vpk[3][16][2])+((fstarr[16][0]*Vpk[3][16][0])+(fstarr[16][1]
      *Vpk[3][16][1])))+((tstarr[16][2]*Wpk[3][16][2])+((tstarr[16][0]*
      Wpk[3][16][0])+(tstarr[16][1]*Wpk[3][14][1]))))+temp[4]));
    temp[6] = ((((fstarr[19][2]*Vpk[3][19][2])+((fstarr[19][0]*Vpk[3][19][0])+(
      fstarr[19][1]*Vpk[3][19][1])))+((tstarr[19][2]*Wpk[3][19][2])+((
      tstarr[19][0]*c18)+(tstarr[19][1]*Wpk[3][19][1]))))+((((fstarr[18][2]*
      Vpk[3][18][2])+((fstarr[18][0]*Vpk[3][18][0])+(fstarr[18][1]*Vpk[3][18][1]
      )))+((tstarr[18][0]*c18)+(tstarr[18][2]*s18)))+temp[5]));
    temp[7] = ((((fstarr[21][2]*Vpk[3][21][2])+((fstarr[21][0]*Vpk[3][21][0])+(
      fstarr[21][1]*Vpk[3][21][1])))+((tstarr[21][2]*Wpk[3][20][2])+((
      tstarr[21][0]*Wpk[3][21][0])+(tstarr[21][1]*Wpk[3][21][1]))))+((((
      fstarr[20][2]*Vpk[3][20][2])+((fstarr[20][0]*Vpk[3][20][0])+(fstarr[20][1]
      *Vpk[3][20][1])))+((tstarr[20][2]*Wpk[3][20][2])+((tstarr[20][0]*
      Wpk[3][20][0])+(tstarr[20][1]*Wpk[3][19][1]))))+temp[6]));
    temp[8] = ((((fstarr[23][2]*Vpk[3][23][2])+((fstarr[23][0]*Vpk[3][23][0])+(
      fstarr[23][1]*Vpk[3][23][1])))+((tstarr[23][2]*Wpk[3][23][2])+((
      tstarr[23][0]*c22)+(tstarr[23][1]*Wpk[3][23][1]))))+((((fstarr[22][2]*
      Vpk[3][22][2])+((fstarr[22][0]*Vpk[3][22][0])+(fstarr[22][1]*Vpk[3][22][1]
      )))+((tstarr[22][0]*c22)+(tstarr[22][2]*s22)))+temp[7]));
    trqout[3] = -(utau[3]+((((fstarr[25][2]*Vpk[3][25][2])+((fstarr[25][0]*
      Vpk[3][25][0])+(fstarr[25][1]*Vpk[3][25][1])))+((tstarr[25][2]*
      Wpk[3][24][2])+((tstarr[25][0]*Wpk[3][25][0])+(tstarr[25][1]*Wpk[3][25][1]
      ))))+((((fstarr[24][2]*Vpk[3][24][2])+((fstarr[24][0]*Vpk[3][24][0])+(
      fstarr[24][1]*Vpk[3][24][1])))+((tstarr[24][2]*Wpk[3][24][2])+((
      tstarr[24][0]*Wpk[3][24][0])+(tstarr[24][1]*Wpk[3][23][1]))))+temp[8])));
    temp[0] = (((tstarr[5][1]+((fstarr[5][2]*rk[0][0])-(fstarr[5][0]*rk[0][2])))
      +(((fstarr[6][2]*Vpk[4][6][2])+((fstarr[6][0]*Vpk[4][6][0])+(fstarr[6][1]*
      Vpk[4][6][1])))+((tstarr[6][0]*s6)+(tstarr[6][1]*c6))))+(((fstarr[7][2]*
      Vpk[4][7][2])+((fstarr[7][0]*Vpk[4][7][0])+(fstarr[7][1]*Vpk[4][7][1])))+(
      (tstarr[7][2]*Wpk[4][7][2])+((tstarr[7][0]*Wpk[4][7][0])+(tstarr[7][1]*c6)
      ))));
    temp[1] = ((((fstarr[9][2]*Vpk[4][9][2])+((fstarr[9][0]*Vpk[4][9][0])+(
      fstarr[9][1]*Vpk[4][9][1])))+((tstarr[9][2]*Wpk[4][9][2])+((tstarr[9][0]*
      Wpk[4][9][0])+(tstarr[9][1]*Wpk[4][8][1]))))+((((fstarr[8][2]*Vpk[4][8][2]
      )+((fstarr[8][0]*Vpk[4][8][0])+(fstarr[8][1]*Vpk[4][8][1])))+((
      tstarr[8][2]*Wpk[4][8][2])+((tstarr[8][0]*Wpk[4][7][0])+(tstarr[8][1]*
      Wpk[4][8][1]))))+temp[0]));
    temp[2] = ((((fstarr[11][2]*Vpk[4][11][2])+((fstarr[11][0]*Vpk[4][11][0])+(
      fstarr[11][1]*Vpk[4][11][1])))+((tstarr[11][2]*Wpk[4][11][2])+((
      tstarr[11][0]*Wpk[4][10][0])+(tstarr[11][1]*Wpk[4][11][1]))))+((((
      fstarr[10][2]*Vpk[4][10][2])+((fstarr[10][0]*Vpk[4][10][0])+(fstarr[10][1]
      *Vpk[4][10][1])))+((tstarr[10][2]*Wpk[4][10][2])+((tstarr[10][0]*
      Wpk[4][10][0])+(tstarr[10][1]*Wpk[4][8][1]))))+temp[1]));
    temp[3] = ((((fstarr[13][2]*Vpk[4][13][2])+((fstarr[13][0]*Vpk[4][13][0])+(
      fstarr[13][1]*Vpk[4][13][1])))+((tstarr[13][2]*Wpk[4][13][2])+((
      tstarr[13][0]*Wpk[4][13][0])+(tstarr[13][1]*c12))))+((((fstarr[12][2]*
      Vpk[4][12][2])+((fstarr[12][0]*Vpk[4][12][0])+(fstarr[12][1]*Vpk[4][12][1]
      )))+((tstarr[12][0]*s12)+(tstarr[12][1]*c12)))+temp[2]));
    temp[4] = ((((fstarr[15][2]*Vpk[4][15][2])+((fstarr[15][0]*Vpk[4][15][0])+(
      fstarr[15][1]*Vpk[4][15][1])))+((tstarr[15][2]*Wpk[4][15][2])+((
      tstarr[15][0]*Wpk[4][15][0])+(tstarr[15][1]*Wpk[4][14][1]))))+((((
      fstarr[14][2]*Vpk[4][14][2])+((fstarr[14][0]*Vpk[4][14][0])+(fstarr[14][1]
      *Vpk[4][14][1])))+((tstarr[14][2]*Wpk[4][14][2])+((tstarr[14][0]*
      Wpk[4][13][0])+(tstarr[14][1]*Wpk[4][14][1]))))+temp[3]));
    temp[5] = ((((fstarr[17][2]*Vpk[4][17][2])+((fstarr[17][0]*Vpk[4][17][0])+(
      fstarr[17][1]*Vpk[4][17][1])))+((tstarr[17][2]*Wpk[4][17][2])+((
      tstarr[17][0]*Wpk[4][16][0])+(tstarr[17][1]*Wpk[4][17][1]))))+((((
      fstarr[16][2]*Vpk[4][16][2])+((fstarr[16][0]*Vpk[4][16][0])+(fstarr[16][1]
      *Vpk[4][16][1])))+((tstarr[16][2]*Wpk[4][16][2])+((tstarr[16][0]*
      Wpk[4][16][0])+(tstarr[16][1]*Wpk[4][14][1]))))+temp[4]));
    temp[6] = ((((fstarr[20][2]*Vpk[4][20][2])+((fstarr[20][0]*Vpk[4][20][0])+(
      fstarr[20][1]*Vpk[4][20][1])))+((tstarr[20][2]*Wpk[4][20][2])+((
      tstarr[20][0]*Wpk[4][20][0])+(tstarr[20][1]*c19))))+(((tstarr[18][1]+((
      fstarr[18][0]*Vpk[4][18][0])+(fstarr[18][2]*Vpk[4][18][2])))+temp[5])+(((
      fstarr[19][2]*Vpk[4][19][2])+((fstarr[19][0]*Vpk[4][19][0])+(fstarr[19][1]
      *Vpk[4][19][1])))+((tstarr[19][1]*c19)-(tstarr[19][2]*s19)))));
    temp[7] = (((tstarr[22][1]+((fstarr[22][0]*Vpk[4][22][0])+(fstarr[22][2]*
      Vpk[4][22][2])))+((((fstarr[21][2]*Vpk[4][21][2])+((fstarr[21][0]*
      Vpk[4][21][0])+(fstarr[21][1]*Vpk[4][21][1])))+((tstarr[21][2]*
      Wpk[4][20][2])+((tstarr[21][0]*Wpk[4][21][0])+(tstarr[21][1]*Wpk[4][21][1]
      ))))+temp[6]))+(((fstarr[23][2]*Vpk[4][23][2])+((fstarr[23][0]*
      Vpk[4][23][0])+(fstarr[23][1]*Vpk[4][23][1])))+((tstarr[23][1]*c23)-(
      tstarr[23][2]*s23))));
    trqout[4] = -(utau[4]+((((fstarr[25][2]*Vpk[4][25][2])+((fstarr[25][0]*
      Vpk[4][25][0])+(fstarr[25][1]*Vpk[4][25][1])))+((tstarr[25][2]*
      Wpk[4][24][2])+((tstarr[25][0]*Wpk[4][25][0])+(tstarr[25][1]*Wpk[4][25][1]
      ))))+((((fstarr[24][2]*Vpk[4][24][2])+((fstarr[24][0]*Vpk[4][24][0])+(
      fstarr[24][1]*Vpk[4][24][1])))+((tstarr[24][2]*Wpk[4][24][2])+((
      tstarr[24][0]*Wpk[4][24][0])+(tstarr[24][1]*c23))))+temp[7])));
    temp[0] = ((((fstarr[8][2]*Vpk[5][8][2])+((fstarr[8][0]*Vpk[5][8][0])+(
      fstarr[8][1]*Vpk[5][8][1])))+((tstarr[8][2]*Wpk[5][8][2])+((tstarr[8][1]*
      Wpk[5][8][1])-(tstarr[8][0]*s7))))+(((tstarr[5][2]+((fstarr[5][0]*rk[0][1]
      )-(fstarr[5][1]*rk[0][0])))+(tstarr[6][2]+((fstarr[6][0]*Vpk[5][6][0])+(
      fstarr[6][1]*Vpk[5][6][1]))))+(((fstarr[7][2]*Vpk[5][7][2])+((fstarr[7][0]
      *Vpk[5][7][0])+(fstarr[7][1]*Vpk[5][7][1])))+((tstarr[7][2]*c7)-(
      tstarr[7][0]*s7)))));
    temp[1] = ((((fstarr[10][2]*Vpk[5][10][2])+((fstarr[10][0]*Vpk[5][10][0])+(
      fstarr[10][1]*Vpk[5][10][1])))+((tstarr[10][2]*Wpk[5][10][2])+((
      tstarr[10][0]*Wpk[5][10][0])+(tstarr[10][1]*Wpk[5][8][1]))))+((((
      fstarr[9][2]*Vpk[5][9][2])+((fstarr[9][0]*Vpk[5][9][0])+(fstarr[9][1]*
      Vpk[5][9][1])))+((tstarr[9][2]*Wpk[5][9][2])+((tstarr[9][0]*Wpk[5][9][0])+
      (tstarr[9][1]*Wpk[5][8][1]))))+temp[0]));
    temp[2] = (((tstarr[12][2]+((fstarr[12][0]*Vpk[5][12][0])+(fstarr[12][1]*
      Vpk[5][12][1])))+((((fstarr[11][2]*Vpk[5][11][2])+((fstarr[11][0]*
      Vpk[5][11][0])+(fstarr[11][1]*Vpk[5][11][1])))+((tstarr[11][2]*
      Wpk[5][11][2])+((tstarr[11][0]*Wpk[5][10][0])+(tstarr[11][1]*Wpk[5][11][1]
      ))))+temp[1]))+(((fstarr[13][2]*Vpk[5][13][2])+((fstarr[13][0]*
      Vpk[5][13][0])+(fstarr[13][1]*Vpk[5][13][1])))+((tstarr[13][2]*c13)-(
      tstarr[13][0]*s13))));
    temp[3] = ((((fstarr[15][2]*Vpk[5][15][2])+((fstarr[15][0]*Vpk[5][15][0])+(
      fstarr[15][1]*Vpk[5][15][1])))+((tstarr[15][2]*Wpk[5][15][2])+((
      tstarr[15][0]*Wpk[5][15][0])+(tstarr[15][1]*Wpk[5][14][1]))))+((((
      fstarr[14][2]*Vpk[5][14][2])+((fstarr[14][0]*Vpk[5][14][0])+(fstarr[14][1]
      *Vpk[5][14][1])))+((tstarr[14][2]*Wpk[5][14][2])+((tstarr[14][1]*
      Wpk[5][14][1])-(tstarr[14][0]*s13))))+temp[2]));
    temp[4] = ((((fstarr[17][2]*Vpk[5][17][2])+((fstarr[17][0]*Vpk[5][17][0])+(
      fstarr[17][1]*Vpk[5][17][1])))+((tstarr[17][2]*Wpk[5][17][2])+((
      tstarr[17][0]*Wpk[5][16][0])+(tstarr[17][1]*Wpk[5][17][1]))))+((((
      fstarr[16][2]*Vpk[5][16][2])+((fstarr[16][0]*Vpk[5][16][0])+(fstarr[16][1]
      *Vpk[5][16][1])))+((tstarr[16][2]*Wpk[5][16][2])+((tstarr[16][0]*
      Wpk[5][16][0])+(tstarr[16][1]*Wpk[5][14][1]))))+temp[3]));
    temp[5] = ((((fstarr[19][2]*Vpk[5][19][2])+((fstarr[19][0]*Vpk[5][19][0])+(
      fstarr[19][1]*Vpk[5][19][1])))+((tstarr[19][2]*Wpk[5][19][2])+((
      tstarr[19][1]*Wpk[5][19][1])-(tstarr[19][0]*s18))))+((((fstarr[18][2]*
      Vpk[5][18][2])+((fstarr[18][0]*Vpk[5][18][0])+(fstarr[18][1]*Vpk[5][18][1]
      )))+((tstarr[18][2]*c18)-(tstarr[18][0]*s18)))+temp[4]));
    temp[6] = ((((fstarr[21][2]*Vpk[5][21][2])+((fstarr[21][0]*Vpk[5][21][0])+(
      fstarr[21][1]*Vpk[5][21][1])))+((tstarr[21][2]*Wpk[5][20][2])+((
      tstarr[21][0]*Wpk[5][21][0])+(tstarr[21][1]*Wpk[5][21][1]))))+((((
      fstarr[20][2]*Vpk[5][20][2])+((fstarr[20][0]*Vpk[5][20][0])+(fstarr[20][1]
      *Vpk[5][20][1])))+((tstarr[20][2]*Wpk[5][20][2])+((tstarr[20][0]*
      Wpk[5][20][0])+(tstarr[20][1]*Wpk[5][19][1]))))+temp[5]));
    temp[7] = ((((fstarr[23][2]*Vpk[5][23][2])+((fstarr[23][0]*Vpk[5][23][0])+(
      fstarr[23][1]*Vpk[5][23][1])))+((tstarr[23][2]*Wpk[5][23][2])+((
      tstarr[23][1]*Wpk[5][23][1])-(tstarr[23][0]*s22))))+((((fstarr[22][2]*
      Vpk[5][22][2])+((fstarr[22][0]*Vpk[5][22][0])+(fstarr[22][1]*Vpk[5][22][1]
      )))+((tstarr[22][2]*c22)-(tstarr[22][0]*s22)))+temp[6]));
    trqout[5] = -(utau[5]+((((fstarr[25][2]*Vpk[5][25][2])+((fstarr[25][0]*
      Vpk[5][25][0])+(fstarr[25][1]*Vpk[5][25][1])))+((tstarr[25][2]*
      Wpk[5][24][2])+((tstarr[25][0]*Wpk[5][25][0])+(tstarr[25][1]*Wpk[5][25][1]
      ))))+((((fstarr[24][2]*Vpk[5][24][2])+((fstarr[24][0]*Vpk[5][24][0])+(
      fstarr[24][1]*Vpk[5][24][1])))+((tstarr[24][2]*Wpk[5][24][2])+((
      tstarr[24][0]*Wpk[5][24][0])+(tstarr[24][1]*Wpk[5][23][1]))))+temp[7])));
    temp[0] = (((tstarr[6][2]+((fstarr[6][0]*rk[1][1])-(fstarr[6][1]*rk[1][0])))
      +(((fstarr[7][2]*Vpk[6][7][2])+((fstarr[7][0]*Vpk[6][7][0])+(fstarr[7][1]*
      Vpk[6][7][1])))+((tstarr[7][2]*c7)-(tstarr[7][0]*s7))))+(((fstarr[8][2]*
      Vpk[6][8][2])+((fstarr[8][0]*Vpk[6][8][0])+(fstarr[8][1]*Vpk[6][8][1])))+(
      (tstarr[8][2]*Wpk[6][8][2])+((tstarr[8][1]*Wpk[6][8][1])-(tstarr[8][0]*s7)
      ))));
    temp[1] = ((((fstarr[10][2]*Vpk[6][10][2])+((fstarr[10][0]*Vpk[6][10][0])+(
      fstarr[10][1]*Vpk[6][10][1])))+((tstarr[10][2]*Wpk[6][10][2])+((
      tstarr[10][0]*Wpk[6][10][0])+(tstarr[10][1]*Wpk[6][8][1]))))+((((
      fstarr[9][2]*Vpk[6][9][2])+((fstarr[9][0]*Vpk[6][9][0])+(fstarr[9][1]*
      Vpk[6][9][1])))+((tstarr[9][2]*Wpk[6][9][2])+((tstarr[9][0]*Wpk[6][9][0])+
      (tstarr[9][1]*Wpk[6][8][1]))))+temp[0]));
    trqout[6] = -(utau[6]+((((fstarr[11][2]*Vpk[6][11][2])+((fstarr[11][0]*
      Vpk[6][11][0])+(fstarr[11][1]*Vpk[6][11][1])))+((tstarr[11][2]*
      Wpk[6][11][2])+((tstarr[11][0]*Wpk[6][10][0])+(tstarr[11][1]*Wpk[6][11][1]
      ))))+temp[1]));
    temp[0] = (((tstarr[7][1]+((fstarr[7][2]*rk[2][0])-(fstarr[7][0]*rk[2][2])))
      +(((fstarr[8][2]*Vpk[7][8][2])+((fstarr[8][0]*Vpk[7][8][0])+(fstarr[8][1]*
      Vpk[7][8][1])))+((tstarr[8][1]*c8)-(tstarr[8][2]*s8))))+(((fstarr[9][2]*
      Vpk[7][9][2])+((fstarr[9][0]*Vpk[7][9][0])+(fstarr[9][1]*Vpk[7][9][1])))+(
      (tstarr[9][2]*Wpk[7][9][2])+((tstarr[9][0]*Wpk[7][9][0])+(tstarr[9][1]*c8)
      ))));
    trqout[7] = -(utau[7]+((((fstarr[11][2]*Vpk[7][11][2])+((fstarr[11][0]*
      Vpk[7][11][0])+(fstarr[11][1]*Vpk[7][11][1])))+((tstarr[11][2]*
      Wpk[7][11][2])+((tstarr[11][0]*Wpk[7][10][0])+(tstarr[11][1]*Wpk[7][11][1]
      ))))+((((fstarr[10][2]*Vpk[7][10][2])+((fstarr[10][0]*Vpk[7][10][0])+(
      fstarr[10][1]*Vpk[7][10][1])))+((tstarr[10][2]*Wpk[7][10][2])+((
      tstarr[10][0]*Wpk[7][10][0])+(tstarr[10][1]*c8))))+temp[0])));
    temp[0] = (((tstarr[8][0]+((fstarr[8][1]*rk[3][2])-(fstarr[8][2]*rk[3][1])))
      +(((fstarr[9][2]*Vpk[8][9][2])+((fstarr[9][0]*Vpk[8][9][0])+(fstarr[9][1]*
      Vpk[8][9][1])))+((tstarr[9][0]*c9)+(tstarr[9][2]*s9))))+(((fstarr[10][2]*
      Vpk[8][10][2])+((fstarr[10][0]*Vpk[8][10][0])+(fstarr[10][1]*Vpk[8][10][1]
      )))+((tstarr[10][0]*Wpk[8][10][0])+(tstarr[10][2]*Wpk[8][10][2]))));
    trqout[8] = -(utau[8]+((((fstarr[11][2]*Vpk[8][11][2])+((fstarr[11][0]*
      Vpk[8][11][0])+(fstarr[11][1]*Vpk[8][11][1])))+((tstarr[11][2]*
      Wpk[8][11][2])+((tstarr[11][0]*Wpk[8][10][0])+(tstarr[11][1]*Wpk[8][11][1]
      ))))+temp[0]));
    trqout[9] = -(utau[9]+(((tstarr[9][1]+((fstarr[9][2]*rk[4][0])-(fstarr[9][0]
      *rk[4][2])))+(tstarr[10][1]+((fstarr[10][0]*Vpk[9][10][0])+(fstarr[10][2]*
      Vpk[9][10][2]))))+(((fstarr[11][2]*Vpk[9][11][2])+((fstarr[11][0]*
      Vpk[9][11][0])+(fstarr[11][1]*Vpk[9][11][1])))+((tstarr[11][1]*c11)-(
      tstarr[11][2]*s11)))));
    trqout[10] = -(utau[10]+((tstarr[10][1]+((fstarr[10][2]*rk[5][0])-(
      fstarr[10][0]*rk[5][2])))+(((fstarr[11][2]*Vpk[10][11][2])+((fstarr[11][0]
      *Vpk[10][11][0])+(fstarr[11][1]*Vpk[10][11][1])))+((tstarr[11][1]*c11)-(
      tstarr[11][2]*s11)))));
    trqout[11] = -(utau[11]+(tstarr[11][0]+((fstarr[11][1]*rk[6][2])-(
      fstarr[11][2]*rk[6][1]))));
    temp[0] = (((tstarr[12][2]+((fstarr[12][0]*rk[7][1])-(fstarr[12][1]*rk[7][0]
      )))+(((fstarr[13][2]*Vpk[12][13][2])+((fstarr[13][0]*Vpk[12][13][0])+(
      fstarr[13][1]*Vpk[12][13][1])))+((tstarr[13][2]*c13)-(tstarr[13][0]*s13)))
      )+(((fstarr[14][2]*Vpk[12][14][2])+((fstarr[14][0]*Vpk[12][14][0])+(
      fstarr[14][1]*Vpk[12][14][1])))+((tstarr[14][2]*Wpk[12][14][2])+((
      tstarr[14][1]*Wpk[12][14][1])-(tstarr[14][0]*s13)))));
    temp[1] = ((((fstarr[16][2]*Vpk[12][16][2])+((fstarr[16][0]*Vpk[12][16][0])+
      (fstarr[16][1]*Vpk[12][16][1])))+((tstarr[16][2]*Wpk[12][16][2])+((
      tstarr[16][0]*Wpk[12][16][0])+(tstarr[16][1]*Wpk[12][14][1]))))+((((
      fstarr[15][2]*Vpk[12][15][2])+((fstarr[15][0]*Vpk[12][15][0])+(
      fstarr[15][1]*Vpk[12][15][1])))+((tstarr[15][2]*Wpk[12][15][2])+((
      tstarr[15][0]*Wpk[12][15][0])+(tstarr[15][1]*Wpk[12][14][1]))))+temp[0]));
    trqout[12] = -(utau[12]+((((fstarr[17][2]*Vpk[12][17][2])+((fstarr[17][0]*
      Vpk[12][17][0])+(fstarr[17][1]*Vpk[12][17][1])))+((tstarr[17][2]*
      Wpk[12][17][2])+((tstarr[17][0]*Wpk[12][16][0])+(tstarr[17][1]*
      Wpk[12][17][1]))))+temp[1]));
    temp[0] = (((tstarr[13][1]+((fstarr[13][2]*rk[8][0])-(fstarr[13][0]*rk[8][2]
      )))+(((fstarr[14][2]*Vpk[13][14][2])+((fstarr[14][0]*Vpk[13][14][0])+(
      fstarr[14][1]*Vpk[13][14][1])))+((tstarr[14][1]*c14)-(tstarr[14][2]*s14)))
      )+(((fstarr[15][2]*Vpk[13][15][2])+((fstarr[15][0]*Vpk[13][15][0])+(
      fstarr[15][1]*Vpk[13][15][1])))+((tstarr[15][2]*Wpk[13][15][2])+((
      tstarr[15][0]*Wpk[13][15][0])+(tstarr[15][1]*c14)))));
    trqout[13] = -(utau[13]+((((fstarr[17][2]*Vpk[13][17][2])+((fstarr[17][0]*
      Vpk[13][17][0])+(fstarr[17][1]*Vpk[13][17][1])))+((tstarr[17][2]*
      Wpk[13][17][2])+((tstarr[17][0]*Wpk[13][16][0])+(tstarr[17][1]*
      Wpk[13][17][1]))))+((((fstarr[16][2]*Vpk[13][16][2])+((fstarr[16][0]*
      Vpk[13][16][0])+(fstarr[16][1]*Vpk[13][16][1])))+((tstarr[16][2]*
      Wpk[13][16][2])+((tstarr[16][0]*Wpk[13][16][0])+(tstarr[16][1]*c14))))+
      temp[0])));
    temp[0] = (((tstarr[14][0]+((fstarr[14][1]*rk[9][2])-(fstarr[14][2]*rk[9][1]
      )))+(((fstarr[15][2]*Vpk[14][15][2])+((fstarr[15][0]*Vpk[14][15][0])+(
      fstarr[15][1]*Vpk[14][15][1])))+((tstarr[15][0]*c15)+(tstarr[15][2]*s15)))
      )+(((fstarr[16][2]*Vpk[14][16][2])+((fstarr[16][0]*Vpk[14][16][0])+(
      fstarr[16][1]*Vpk[14][16][1])))+((tstarr[16][0]*Wpk[14][16][0])+(
      tstarr[16][2]*Wpk[14][16][2]))));
    trqout[14] = -(utau[14]+((((fstarr[17][2]*Vpk[14][17][2])+((fstarr[17][0]*
      Vpk[14][17][0])+(fstarr[17][1]*Vpk[14][17][1])))+((tstarr[17][2]*
      Wpk[14][17][2])+((tstarr[17][0]*Wpk[14][16][0])+(tstarr[17][1]*
      Wpk[14][17][1]))))+temp[0]));
    trqout[15] = -(utau[15]+(((tstarr[15][1]+((fstarr[15][2]*rk[10][0])-(
      fstarr[15][0]*rk[10][2])))+(tstarr[16][1]+((fstarr[16][0]*Vpk[15][16][0])+
      (fstarr[16][2]*Vpk[15][16][2]))))+(((fstarr[17][2]*Vpk[15][17][2])+((
      fstarr[17][0]*Vpk[15][17][0])+(fstarr[17][1]*Vpk[15][17][1])))+((
      tstarr[17][1]*c17)-(tstarr[17][2]*s17)))));
    trqout[16] = -(utau[16]+((tstarr[16][1]+((fstarr[16][2]*rk[11][0])-(
      fstarr[16][0]*rk[11][2])))+(((fstarr[17][2]*Vpk[16][17][2])+((
      fstarr[17][0]*Vpk[16][17][0])+(fstarr[17][1]*Vpk[16][17][1])))+((
      tstarr[17][1]*c17)-(tstarr[17][2]*s17)))));
    trqout[17] = -(utau[17]+(tstarr[17][0]+((fstarr[17][1]*rk[12][2])-(
      fstarr[17][2]*rk[12][1]))));
    temp[0] = (((tstarr[18][1]+((fstarr[18][2]*rk[13][0])-(fstarr[18][0]*
      rk[13][2])))+(((fstarr[19][2]*Vpk[18][19][2])+((fstarr[19][0]*
      Vpk[18][19][0])+(fstarr[19][1]*Vpk[18][19][1])))+((tstarr[19][1]*c19)-(
      tstarr[19][2]*s19))))+(((fstarr[20][2]*Vpk[18][20][2])+((fstarr[20][0]*
      Vpk[18][20][0])+(fstarr[20][1]*Vpk[18][20][1])))+((tstarr[20][2]*
      Wpk[18][20][2])+((tstarr[20][0]*Wpk[18][20][0])+(tstarr[20][1]*c19)))));
    trqout[18] = -(utau[18]+((((fstarr[21][2]*Vpk[18][21][2])+((fstarr[21][0]*
      Vpk[18][21][0])+(fstarr[21][1]*Vpk[18][21][1])))+((tstarr[21][2]*
      Wpk[18][20][2])+((tstarr[21][0]*Wpk[18][21][0])+(tstarr[21][1]*
      Wpk[18][21][1]))))+temp[0]));
    trqout[19] = -(utau[19]+(((tstarr[19][0]+((fstarr[19][1]*rk[14][2])-(
      fstarr[19][2]*rk[14][1])))+(((fstarr[20][2]*Vpk[19][20][2])+((
      fstarr[20][0]*Vpk[19][20][0])+(fstarr[20][1]*Vpk[19][20][1])))+((
      tstarr[20][0]*c20)+(tstarr[20][2]*s20))))+(((fstarr[21][2]*Vpk[19][21][2])
      +((fstarr[21][0]*Vpk[19][21][0])+(fstarr[21][1]*Vpk[19][21][1])))+((
      tstarr[21][2]*s20)+((tstarr[21][0]*Wpk[19][21][0])+(tstarr[21][1]*
      Wpk[19][21][1]))))));
    trqout[20] = -(utau[20]+((tstarr[20][1]+((fstarr[20][2]*rk[15][0])-(
      fstarr[20][0]*rk[15][2])))+(((fstarr[21][2]*Vpk[20][21][2])+((
      fstarr[21][0]*Vpk[20][21][0])+(fstarr[21][1]*Vpk[20][21][1])))+((
      tstarr[21][0]*s21)+(tstarr[21][1]*c21)))));
    trqout[21] = -(utau[21]+(tstarr[21][2]+((fstarr[21][0]*rk[16][1])-(
      fstarr[21][1]*rk[16][0]))));
    temp[0] = (((tstarr[22][1]+((fstarr[22][2]*rk[17][0])-(fstarr[22][0]*
      rk[17][2])))+(((fstarr[23][2]*Vpk[22][23][2])+((fstarr[23][0]*
      Vpk[22][23][0])+(fstarr[23][1]*Vpk[22][23][1])))+((tstarr[23][1]*c23)-(
      tstarr[23][2]*s23))))+(((fstarr[24][2]*Vpk[22][24][2])+((fstarr[24][0]*
      Vpk[22][24][0])+(fstarr[24][1]*Vpk[22][24][1])))+((tstarr[24][2]*
      Wpk[22][24][2])+((tstarr[24][0]*Wpk[22][24][0])+(tstarr[24][1]*c23)))));
    trqout[22] = -(utau[22]+((((fstarr[25][2]*Vpk[22][25][2])+((fstarr[25][0]*
      Vpk[22][25][0])+(fstarr[25][1]*Vpk[22][25][1])))+((tstarr[25][2]*
      Wpk[22][24][2])+((tstarr[25][0]*Wpk[22][25][0])+(tstarr[25][1]*
      Wpk[22][25][1]))))+temp[0]));
    trqout[23] = -(utau[23]+(((tstarr[23][0]+((fstarr[23][1]*rk[18][2])-(
      fstarr[23][2]*rk[18][1])))+(((fstarr[24][2]*Vpk[23][24][2])+((
      fstarr[24][0]*Vpk[23][24][0])+(fstarr[24][1]*Vpk[23][24][1])))+((
      tstarr[24][0]*c24)+(tstarr[24][2]*s24))))+(((fstarr[25][2]*Vpk[23][25][2])
      +((fstarr[25][0]*Vpk[23][25][0])+(fstarr[25][1]*Vpk[23][25][1])))+((
      tstarr[25][2]*s24)+((tstarr[25][0]*Wpk[23][25][0])+(tstarr[25][1]*
      Wpk[23][25][1]))))));
    trqout[24] = -(utau[24]+((tstarr[24][1]+((fstarr[24][2]*rk[19][0])-(
      fstarr[24][0]*rk[19][2])))+(((fstarr[25][2]*Vpk[24][25][2])+((
      fstarr[25][0]*Vpk[24][25][0])+(fstarr[25][1]*Vpk[24][25][1])))+((
      tstarr[25][0]*s25)+(tstarr[25][1]*c25)))));
    trqout[25] = -(utau[25]+(tstarr[25][2]+((fstarr[25][0]*rk[20][1])-(
      fstarr[25][1]*rk[20][0]))));
/*
Op counts below do not include called subroutines
*/
/*
 Used 0.03 seconds CPU time,
 0 additional bytes of memory.
 Equations contain 1864 adds/subtracts/negates
                   1753 multiplies
                      0 divides
                    388 assignments
*/
}

void Jimmy::sdcomptrq(double udotin[26],
    double trqout[26])
{
/* Compute hinge torques to produce these udots, ignoring constraints
*/
    double multin[1];

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(60,23);
        return;
    }
    sdfulltrq(udotin,multin,trqout);
}

void Jimmy::sdmulttrq(double multin[1],
    double trqout[26])
{
/* Compute hinge trqs which would be produced by these mults.
*/
    int i;

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(65,23);
        return;
    }
    for (i = 0; i < 26; i++) {
        trqout[i] = 0.;
    }
}

void Jimmy::sdrhs(void)
{
/*
Generated 27-Jan-2007 11:40:25 by SD/FAST, Kane's formulation
(sdfast B.2.8 #30123) on machine ID unknown
Copyright (c) 1990-1997 Symbolic Dynamics, Inc.
Copyright (c) 1990-1997 Parametric Technology Corp.
RESTRICTED RIGHTS LEGEND: Use, duplication, or disclosure by the U.S.
Government is subject to restrictions as set forth in subparagraph
(c)(1)(ii) of the Rights in Technical Data and Computer Software
clause at DFARS 52.227-7013 and similar clauses in the FAR and NASA
FAR Supplement.  Symbolic Dynamics, Inc., Mountain View, CA 94041
*/

/*
Compute hinge torques for tree hinges
*/
    tauc[0] = utau[0];
    tauc[1] = utau[1];
    tauc[2] = utau[2];
    tauc[3] = utau[3];
    tauc[4] = utau[4];
    tauc[5] = utau[5];
    tauc[6] = utau[6];
    tauc[7] = utau[7];
    tauc[8] = utau[8];
    tauc[9] = utau[9];
    tauc[10] = utau[10];
    tauc[11] = utau[11];
    tauc[12] = utau[12];
    tauc[13] = utau[13];
    tauc[14] = utau[14];
    tauc[15] = utau[15];
    tauc[16] = utau[16];
    tauc[17] = utau[17];
    tauc[18] = utau[18];
    tauc[19] = utau[19];
    tauc[20] = utau[20];
    tauc[21] = utau[21];
    tauc[22] = utau[22];
    tauc[23] = utau[23];
    tauc[24] = utau[24];
    tauc[25] = utau[25];
    sddoiner();
/*
Compute onk & onb (angular accels in N)
*/
    Onkb[6][0] = ((udot[3]*c6)+(udot[4]*s6));
    Onkb[6][1] = ((udot[4]*c6)-(udot[3]*s6));
    Onkb[6][2] = (udot[5]+udot[6]);
    Onkb[7][0] = ((Onkb[6][0]*c7)-(Onkb[6][2]*s7));
    Onkb[7][1] = (Onkb[6][1]+udot[7]);
    Onkb[7][2] = ((Onkb[6][0]*s7)+(Onkb[6][2]*c7));
    Onkb[8][0] = (Onkb[7][0]+udot[8]);
    Onkb[8][1] = ((Onkb[7][1]*c8)+(Onkb[7][2]*s8));
    Onkb[8][2] = ((Onkb[7][2]*c8)-(Onkb[7][1]*s8));
    Onkb[9][0] = ((Onkb[8][0]*c9)-(Onkb[8][2]*s9));
    Onkb[9][1] = (Onkb[8][1]+udot[9]);
    Onkb[9][2] = ((Onkb[8][0]*s9)+(Onkb[8][2]*c9));
    Onkb[10][0] = ((Onkb[9][0]*c10)-(Onkb[9][2]*s10));
    Onkb[10][1] = (Onkb[9][1]+udot[10]);
    Onkb[10][2] = ((Onkb[9][0]*s10)+(Onkb[9][2]*c10));
    Onkb[11][0] = (Onkb[10][0]+udot[11]);
    Onkb[11][1] = ((Onkb[10][1]*c11)+(Onkb[10][2]*s11));
    Onkb[11][2] = ((Onkb[10][2]*c11)-(Onkb[10][1]*s11));
    Onkb[12][0] = ((udot[3]*c12)+(udot[4]*s12));
    Onkb[12][1] = ((udot[4]*c12)-(udot[3]*s12));
    Onkb[12][2] = (udot[5]+udot[12]);
    Onkb[13][0] = ((Onkb[12][0]*c13)-(Onkb[12][2]*s13));
    Onkb[13][1] = (Onkb[12][1]+udot[13]);
    Onkb[13][2] = ((Onkb[12][0]*s13)+(Onkb[12][2]*c13));
    Onkb[14][0] = (Onkb[13][0]+udot[14]);
    Onkb[14][1] = ((Onkb[13][1]*c14)+(Onkb[13][2]*s14));
    Onkb[14][2] = ((Onkb[13][2]*c14)-(Onkb[13][1]*s14));
    Onkb[15][0] = ((Onkb[14][0]*c15)-(Onkb[14][2]*s15));
    Onkb[15][1] = (Onkb[14][1]+udot[15]);
    Onkb[15][2] = ((Onkb[14][0]*s15)+(Onkb[14][2]*c15));
    Onkb[16][0] = ((Onkb[15][0]*c16)-(Onkb[15][2]*s16));
    Onkb[16][1] = (Onkb[15][1]+udot[16]);
    Onkb[16][2] = ((Onkb[15][0]*s16)+(Onkb[15][2]*c16));
    Onkb[17][0] = (Onkb[16][0]+udot[17]);
    Onkb[17][1] = ((Onkb[16][1]*c17)+(Onkb[16][2]*s17));
    Onkb[17][2] = ((Onkb[16][2]*c17)-(Onkb[16][1]*s17));
    Onkb[18][0] = ((udot[3]*c18)-(udot[5]*s18));
    Onkb[18][1] = (udot[4]+udot[18]);
    Onkb[18][2] = ((udot[3]*s18)+(udot[5]*c18));
    Onkb[19][0] = (Onkb[18][0]+udot[19]);
    Onkb[19][1] = ((Onkb[18][1]*c19)+(Onkb[18][2]*s19));
    Onkb[19][2] = ((Onkb[18][2]*c19)-(Onkb[18][1]*s19));
    Onkb[20][0] = ((Onkb[19][0]*c20)-(Onkb[19][2]*s20));
    Onkb[20][1] = (Onkb[19][1]+udot[20]);
    Onkb[20][2] = ((Onkb[19][0]*s20)+(Onkb[19][2]*c20));
    Onkb[21][0] = ((Onkb[20][0]*c21)+(Onkb[20][1]*s21));
    Onkb[21][1] = ((Onkb[20][1]*c21)-(Onkb[20][0]*s21));
    Onkb[21][2] = (Onkb[20][2]+udot[21]);
    Onkb[22][0] = ((udot[3]*c22)-(udot[5]*s22));
    Onkb[22][1] = (udot[4]+udot[22]);
    Onkb[22][2] = ((udot[3]*s22)+(udot[5]*c22));
    Onkb[23][0] = (Onkb[22][0]+udot[23]);
    Onkb[23][1] = ((Onkb[22][1]*c23)+(Onkb[22][2]*s23));
    Onkb[23][2] = ((Onkb[22][2]*c23)-(Onkb[22][1]*s23));
    Onkb[24][0] = ((Onkb[23][0]*c24)-(Onkb[23][2]*s24));
    Onkb[24][1] = (Onkb[23][1]+udot[24]);
    Onkb[24][2] = ((Onkb[23][0]*s24)+(Onkb[23][2]*c24));
    Onkb[25][0] = ((Onkb[24][0]*c25)+(Onkb[24][1]*s25));
    Onkb[25][1] = ((Onkb[24][1]*c25)-(Onkb[24][0]*s25));
    Onkb[25][2] = (Onkb[24][2]+udot[25]);
    onk[6][0] = (Onkb[6][0]+Otk[6][0]);
    onk[6][1] = (Onkb[6][1]+Otk[6][1]);
    onk[7][0] = (Onkb[7][0]+Otk[7][0]);
    onk[7][1] = (Onkb[7][1]+Otk[6][1]);
    onk[7][2] = (Onkb[7][2]+Otk[7][2]);
    onk[8][0] = (Onkb[8][0]+Otk[7][0]);
    onk[8][1] = (Onkb[8][1]+Otk[8][1]);
    onk[8][2] = (Onkb[8][2]+Otk[8][2]);
    onk[9][0] = (Onkb[9][0]+Otk[9][0]);
    onk[9][1] = (Onkb[9][1]+Otk[8][1]);
    onk[9][2] = (Onkb[9][2]+Otk[9][2]);
    onk[10][0] = (Onkb[10][0]+Otk[10][0]);
    onk[10][1] = (Onkb[10][1]+Otk[8][1]);
    onk[10][2] = (Onkb[10][2]+Otk[10][2]);
    onk[11][0] = (Onkb[11][0]+Otk[10][0]);
    onk[11][1] = (Onkb[11][1]+Otk[11][1]);
    onk[11][2] = (Onkb[11][2]+Otk[11][2]);
    onk[12][0] = (Onkb[12][0]+Otk[12][0]);
    onk[12][1] = (Onkb[12][1]+Otk[12][1]);
    onk[13][0] = (Onkb[13][0]+Otk[13][0]);
    onk[13][1] = (Onkb[13][1]+Otk[12][1]);
    onk[13][2] = (Onkb[13][2]+Otk[13][2]);
    onk[14][0] = (Onkb[14][0]+Otk[13][0]);
    onk[14][1] = (Onkb[14][1]+Otk[14][1]);
    onk[14][2] = (Onkb[14][2]+Otk[14][2]);
    onk[15][0] = (Onkb[15][0]+Otk[15][0]);
    onk[15][1] = (Onkb[15][1]+Otk[14][1]);
    onk[15][2] = (Onkb[15][2]+Otk[15][2]);
    onk[16][0] = (Onkb[16][0]+Otk[16][0]);
    onk[16][1] = (Onkb[16][1]+Otk[14][1]);
    onk[16][2] = (Onkb[16][2]+Otk[16][2]);
    onk[17][0] = (Onkb[17][0]+Otk[16][0]);
    onk[17][1] = (Onkb[17][1]+Otk[17][1]);
    onk[17][2] = (Onkb[17][2]+Otk[17][2]);
    onk[18][0] = (Onkb[18][0]+Otk[18][0]);
    onk[18][2] = (Onkb[18][2]+Otk[18][2]);
    onk[19][0] = (Onkb[19][0]+Otk[18][0]);
    onk[19][1] = (Onkb[19][1]+Otk[19][1]);
    onk[19][2] = (Onkb[19][2]+Otk[19][2]);
    onk[20][0] = (Onkb[20][0]+Otk[20][0]);
    onk[20][1] = (Onkb[20][1]+Otk[19][1]);
    onk[20][2] = (Onkb[20][2]+Otk[20][2]);
    onk[21][0] = (Onkb[21][0]+Otk[21][0]);
    onk[21][1] = (Onkb[21][1]+Otk[21][1]);
    onk[21][2] = (Onkb[21][2]+Otk[20][2]);
    onk[22][0] = (Onkb[22][0]+Otk[22][0]);
    onk[22][2] = (Onkb[22][2]+Otk[22][2]);
    onk[23][0] = (Onkb[23][0]+Otk[22][0]);
    onk[23][1] = (Onkb[23][1]+Otk[23][1]);
    onk[23][2] = (Onkb[23][2]+Otk[23][2]);
    onk[24][0] = (Onkb[24][0]+Otk[24][0]);
    onk[24][1] = (Onkb[24][1]+Otk[23][1]);
    onk[24][2] = (Onkb[24][2]+Otk[24][2]);
    onk[25][0] = (Onkb[25][0]+Otk[25][0]);
    onk[25][1] = (Onkb[25][1]+Otk[25][1]);
    onk[25][2] = (Onkb[25][2]+Otk[24][2]);
    onb[0][0] = udot[3];
    onb[0][1] = udot[4];
    onb[0][2] = udot[5];
    onb[1][0] = onk[6][0];
    onb[1][1] = onk[6][1];
    onb[1][2] = Onkb[6][2];
    onb[2][0] = onk[7][0];
    onb[2][1] = onk[7][1];
    onb[2][2] = onk[7][2];
    onb[3][0] = onk[8][0];
    onb[3][1] = onk[8][1];
    onb[3][2] = onk[8][2];
    onb[4][0] = onk[9][0];
    onb[4][1] = onk[9][1];
    onb[4][2] = onk[9][2];
    onb[5][0] = onk[10][0];
    onb[5][1] = onk[10][1];
    onb[5][2] = onk[10][2];
    onb[6][0] = onk[11][0];
    onb[6][1] = onk[11][1];
    onb[6][2] = onk[11][2];
    onb[7][0] = onk[12][0];
    onb[7][1] = onk[12][1];
    onb[7][2] = Onkb[12][2];
    onb[8][0] = onk[13][0];
    onb[8][1] = onk[13][1];
    onb[8][2] = onk[13][2];
    onb[9][0] = onk[14][0];
    onb[9][1] = onk[14][1];
    onb[9][2] = onk[14][2];
    onb[10][0] = onk[15][0];
    onb[10][1] = onk[15][1];
    onb[10][2] = onk[15][2];
    onb[11][0] = onk[16][0];
    onb[11][1] = onk[16][1];
    onb[11][2] = onk[16][2];
    onb[12][0] = onk[17][0];
    onb[12][1] = onk[17][1];
    onb[12][2] = onk[17][2];
    onb[13][0] = onk[18][0];
    onb[13][1] = Onkb[18][1];
    onb[13][2] = onk[18][2];
    onb[14][0] = onk[19][0];
    onb[14][1] = onk[19][1];
    onb[14][2] = onk[19][2];
    onb[15][0] = onk[20][0];
    onb[15][1] = onk[20][1];
    onb[15][2] = onk[20][2];
    onb[16][0] = onk[21][0];
    onb[16][1] = onk[21][1];
    onb[16][2] = onk[21][2];
    onb[17][0] = onk[22][0];
    onb[17][1] = Onkb[22][1];
    onb[17][2] = onk[22][2];
    onb[18][0] = onk[23][0];
    onb[18][1] = onk[23][1];
    onb[18][2] = onk[23][2];
    onb[19][0] = onk[24][0];
    onb[19][1] = onk[24][1];
    onb[19][2] = onk[24][2];
    onb[20][0] = onk[25][0];
    onb[20][1] = onk[25][1];
    onb[20][2] = onk[25][2];
/*
Compute acceleration dyadics
*/
    dyad[0][0][0] = w11w22[0];
    dyad[0][0][1] = (w0w1[0]-udot[5]);
    dyad[0][0][2] = (udot[4]+w0w2[0]);
    dyad[0][1][0] = (udot[5]+w0w1[0]);
    dyad[0][1][1] = w00w22[0];
    dyad[0][1][2] = (w1w2[0]-udot[3]);
    dyad[0][2][0] = (w0w2[0]-udot[4]);
    dyad[0][2][1] = (udot[3]+w1w2[0]);
    dyad[0][2][2] = w00w11[0];
    dyad[1][0][0] = w11w22[1];
    dyad[1][0][1] = (w0w1[1]-Onkb[6][2]);
    dyad[1][0][2] = (onk[6][1]+w0w2[1]);
    dyad[1][1][0] = (Onkb[6][2]+w0w1[1]);
    dyad[1][1][1] = w00w22[1];
    dyad[1][1][2] = (w1w2[1]-onk[6][0]);
    dyad[1][2][0] = (w0w2[1]-onk[6][1]);
    dyad[1][2][1] = (onk[6][0]+w1w2[1]);
    dyad[1][2][2] = w00w11[1];
    dyad[2][0][0] = w11w22[2];
    dyad[2][0][1] = (w0w1[2]-onk[7][2]);
    dyad[2][0][2] = (onk[7][1]+w0w2[2]);
    dyad[2][1][0] = (onk[7][2]+w0w1[2]);
    dyad[2][1][1] = w00w22[2];
    dyad[2][1][2] = (w1w2[2]-onk[7][0]);
    dyad[2][2][0] = (w0w2[2]-onk[7][1]);
    dyad[2][2][1] = (onk[7][0]+w1w2[2]);
    dyad[2][2][2] = w00w11[2];
    dyad[3][0][0] = w11w22[3];
    dyad[3][0][1] = (w0w1[3]-onk[8][2]);
    dyad[3][0][2] = (onk[8][1]+w0w2[3]);
    dyad[3][1][0] = (onk[8][2]+w0w1[3]);
    dyad[3][1][1] = w00w22[3];
    dyad[3][1][2] = (w1w2[3]-onk[8][0]);
    dyad[3][2][0] = (w0w2[3]-onk[8][1]);
    dyad[3][2][1] = (onk[8][0]+w1w2[3]);
    dyad[3][2][2] = w00w11[3];
    dyad[4][0][0] = w11w22[4];
    dyad[4][0][1] = (w0w1[4]-onk[9][2]);
    dyad[4][0][2] = (onk[9][1]+w0w2[4]);
    dyad[4][1][0] = (onk[9][2]+w0w1[4]);
    dyad[4][1][1] = w00w22[4];
    dyad[4][1][2] = (w1w2[4]-onk[9][0]);
    dyad[4][2][0] = (w0w2[4]-onk[9][1]);
    dyad[4][2][1] = (onk[9][0]+w1w2[4]);
    dyad[4][2][2] = w00w11[4];
    dyad[5][0][0] = w11w22[5];
    dyad[5][0][1] = (w0w1[5]-onk[10][2]);
    dyad[5][0][2] = (onk[10][1]+w0w2[5]);
    dyad[5][1][0] = (onk[10][2]+w0w1[5]);
    dyad[5][1][1] = w00w22[5];
    dyad[5][1][2] = (w1w2[5]-onk[10][0]);
    dyad[5][2][0] = (w0w2[5]-onk[10][1]);
    dyad[5][2][1] = (onk[10][0]+w1w2[5]);
    dyad[5][2][2] = w00w11[5];
    dyad[6][0][0] = w11w22[6];
    dyad[6][0][1] = (w0w1[6]-onk[11][2]);
    dyad[6][0][2] = (onk[11][1]+w0w2[6]);
    dyad[6][1][0] = (onk[11][2]+w0w1[6]);
    dyad[6][1][1] = w00w22[6];
    dyad[6][1][2] = (w1w2[6]-onk[11][0]);
    dyad[6][2][0] = (w0w2[6]-onk[11][1]);
    dyad[6][2][1] = (onk[11][0]+w1w2[6]);
    dyad[6][2][2] = w00w11[6];
    dyad[7][0][0] = w11w22[7];
    dyad[7][0][1] = (w0w1[7]-Onkb[12][2]);
    dyad[7][0][2] = (onk[12][1]+w0w2[7]);
    dyad[7][1][0] = (Onkb[12][2]+w0w1[7]);
    dyad[7][1][1] = w00w22[7];
    dyad[7][1][2] = (w1w2[7]-onk[12][0]);
    dyad[7][2][0] = (w0w2[7]-onk[12][1]);
    dyad[7][2][1] = (onk[12][0]+w1w2[7]);
    dyad[7][2][2] = w00w11[7];
    dyad[8][0][0] = w11w22[8];
    dyad[8][0][1] = (w0w1[8]-onk[13][2]);
    dyad[8][0][2] = (onk[13][1]+w0w2[8]);
    dyad[8][1][0] = (onk[13][2]+w0w1[8]);
    dyad[8][1][1] = w00w22[8];
    dyad[8][1][2] = (w1w2[8]-onk[13][0]);
    dyad[8][2][0] = (w0w2[8]-onk[13][1]);
    dyad[8][2][1] = (onk[13][0]+w1w2[8]);
    dyad[8][2][2] = w00w11[8];
    dyad[9][0][0] = w11w22[9];
    dyad[9][0][1] = (w0w1[9]-onk[14][2]);
    dyad[9][0][2] = (onk[14][1]+w0w2[9]);
    dyad[9][1][0] = (onk[14][2]+w0w1[9]);
    dyad[9][1][1] = w00w22[9];
    dyad[9][1][2] = (w1w2[9]-onk[14][0]);
    dyad[9][2][0] = (w0w2[9]-onk[14][1]);
    dyad[9][2][1] = (onk[14][0]+w1w2[9]);
    dyad[9][2][2] = w00w11[9];
    dyad[10][0][0] = w11w22[10];
    dyad[10][0][1] = (w0w1[10]-onk[15][2]);
    dyad[10][0][2] = (onk[15][1]+w0w2[10]);
    dyad[10][1][0] = (onk[15][2]+w0w1[10]);
    dyad[10][1][1] = w00w22[10];
    dyad[10][1][2] = (w1w2[10]-onk[15][0]);
    dyad[10][2][0] = (w0w2[10]-onk[15][1]);
    dyad[10][2][1] = (onk[15][0]+w1w2[10]);
    dyad[10][2][2] = w00w11[10];
    dyad[11][0][0] = w11w22[11];
    dyad[11][0][1] = (w0w1[11]-onk[16][2]);
    dyad[11][0][2] = (onk[16][1]+w0w2[11]);
    dyad[11][1][0] = (onk[16][2]+w0w1[11]);
    dyad[11][1][1] = w00w22[11];
    dyad[11][1][2] = (w1w2[11]-onk[16][0]);
    dyad[11][2][0] = (w0w2[11]-onk[16][1]);
    dyad[11][2][1] = (onk[16][0]+w1w2[11]);
    dyad[11][2][2] = w00w11[11];
    dyad[12][0][0] = w11w22[12];
    dyad[12][0][1] = (w0w1[12]-onk[17][2]);
    dyad[12][0][2] = (onk[17][1]+w0w2[12]);
    dyad[12][1][0] = (onk[17][2]+w0w1[12]);
    dyad[12][1][1] = w00w22[12];
    dyad[12][1][2] = (w1w2[12]-onk[17][0]);
    dyad[12][2][0] = (w0w2[12]-onk[17][1]);
    dyad[12][2][1] = (onk[17][0]+w1w2[12]);
    dyad[12][2][2] = w00w11[12];
    dyad[13][0][0] = w11w22[13];
    dyad[13][0][1] = (w0w1[13]-onk[18][2]);
    dyad[13][0][2] = (Onkb[18][1]+w0w2[13]);
    dyad[13][1][0] = (onk[18][2]+w0w1[13]);
    dyad[13][1][1] = w00w22[13];
    dyad[13][1][2] = (w1w2[13]-onk[18][0]);
    dyad[13][2][0] = (w0w2[13]-Onkb[18][1]);
    dyad[13][2][1] = (onk[18][0]+w1w2[13]);
    dyad[13][2][2] = w00w11[13];
    dyad[14][0][0] = w11w22[14];
    dyad[14][0][1] = (w0w1[14]-onk[19][2]);
    dyad[14][0][2] = (onk[19][1]+w0w2[14]);
    dyad[14][1][0] = (onk[19][2]+w0w1[14]);
    dyad[14][1][1] = w00w22[14];
    dyad[14][1][2] = (w1w2[14]-onk[19][0]);
    dyad[14][2][0] = (w0w2[14]-onk[19][1]);
    dyad[14][2][1] = (onk[19][0]+w1w2[14]);
    dyad[14][2][2] = w00w11[14];
    dyad[15][0][0] = w11w22[15];
    dyad[15][0][1] = (w0w1[15]-onk[20][2]);
    dyad[15][0][2] = (onk[20][1]+w0w2[15]);
    dyad[15][1][0] = (onk[20][2]+w0w1[15]);
    dyad[15][1][1] = w00w22[15];
    dyad[15][1][2] = (w1w2[15]-onk[20][0]);
    dyad[15][2][0] = (w0w2[15]-onk[20][1]);
    dyad[15][2][1] = (onk[20][0]+w1w2[15]);
    dyad[15][2][2] = w00w11[15];
    dyad[16][0][0] = w11w22[16];
    dyad[16][0][1] = (w0w1[16]-onk[21][2]);
    dyad[16][0][2] = (onk[21][1]+w0w2[16]);
    dyad[16][1][0] = (onk[21][2]+w0w1[16]);
    dyad[16][1][1] = w00w22[16];
    dyad[16][1][2] = (w1w2[16]-onk[21][0]);
    dyad[16][2][0] = (w0w2[16]-onk[21][1]);
    dyad[16][2][1] = (onk[21][0]+w1w2[16]);
    dyad[16][2][2] = w00w11[16];
    dyad[17][0][0] = w11w22[17];
    dyad[17][0][1] = (w0w1[17]-onk[22][2]);
    dyad[17][0][2] = (Onkb[22][1]+w0w2[17]);
    dyad[17][1][0] = (onk[22][2]+w0w1[17]);
    dyad[17][1][1] = w00w22[17];
    dyad[17][1][2] = (w1w2[17]-onk[22][0]);
    dyad[17][2][0] = (w0w2[17]-Onkb[22][1]);
    dyad[17][2][1] = (onk[22][0]+w1w2[17]);
    dyad[17][2][2] = w00w11[17];
    dyad[18][0][0] = w11w22[18];
    dyad[18][0][1] = (w0w1[18]-onk[23][2]);
    dyad[18][0][2] = (onk[23][1]+w0w2[18]);
    dyad[18][1][0] = (onk[23][2]+w0w1[18]);
    dyad[18][1][1] = w00w22[18];
    dyad[18][1][2] = (w1w2[18]-onk[23][0]);
    dyad[18][2][0] = (w0w2[18]-onk[23][1]);
    dyad[18][2][1] = (onk[23][0]+w1w2[18]);
    dyad[18][2][2] = w00w11[18];
    dyad[19][0][0] = w11w22[19];
    dyad[19][0][1] = (w0w1[19]-onk[24][2]);
    dyad[19][0][2] = (onk[24][1]+w0w2[19]);
    dyad[19][1][0] = (onk[24][2]+w0w1[19]);
    dyad[19][1][1] = w00w22[19];
    dyad[19][1][2] = (w1w2[19]-onk[24][0]);
    dyad[19][2][0] = (w0w2[19]-onk[24][1]);
    dyad[19][2][1] = (onk[24][0]+w1w2[19]);
    dyad[19][2][2] = w00w11[19];
    dyad[20][0][0] = w11w22[20];
    dyad[20][0][1] = (w0w1[20]-onk[25][2]);
    dyad[20][0][2] = (onk[25][1]+w0w2[20]);
    dyad[20][1][0] = (onk[25][2]+w0w1[20]);
    dyad[20][1][1] = w00w22[20];
    dyad[20][1][2] = (w1w2[20]-onk[25][0]);
    dyad[20][2][0] = (w0w2[20]-onk[25][1]);
    dyad[20][2][1] = (onk[25][0]+w1w2[20]);
    dyad[20][2][2] = w00w11[20];
/*
Compute ank & anb (mass center linear accels in N)
*/
    Ankb[3][0] = ((Cik[3][2][0]*udot[2])+((Cik[3][0][0]*udot[0])+(Cik[3][1][0]*
      udot[1])));
    Ankb[3][1] = ((Cik[3][2][1]*udot[2])+((Cik[3][0][1]*udot[0])+(Cik[3][1][1]*
      udot[1])));
    Ankb[3][2] = ((Cik[3][2][2]*udot[2])+((Cik[3][0][2]*udot[0])+(Cik[3][1][2]*
      udot[1])));
    Ankb[5][0] = (Ankb[3][0]+((rk[0][1]*udot[5])-(rk[0][2]*udot[4])));
    Ankb[5][1] = (Ankb[3][1]+((rk[0][2]*udot[3])-(rk[0][0]*udot[5])));
    Ankb[5][2] = (Ankb[3][2]+((rk[0][0]*udot[4])-(rk[0][1]*udot[3])));
    AOnkri[6][0] = (Ankb[5][0]+((ri[1][2]*udot[4])-(ri[1][1]*udot[5])));
    AOnkri[6][1] = (Ankb[5][1]+((ri[1][0]*udot[5])-(ri[1][2]*udot[3])));
    AOnkri[6][2] = (Ankb[5][2]+((ri[1][1]*udot[3])-(ri[1][0]*udot[4])));
    Ankb[6][0] = (((AOnkri[6][0]*c6)+(AOnkri[6][1]*s6))+((Onkb[6][2]*rk[1][1])-(
      Onkb[6][1]*rk[1][2])));
    Ankb[6][1] = (((AOnkri[6][1]*c6)-(AOnkri[6][0]*s6))+((Onkb[6][0]*rk[1][2])-(
      Onkb[6][2]*rk[1][0])));
    Ankb[6][2] = (AOnkri[6][2]+((Onkb[6][1]*rk[1][0])-(Onkb[6][0]*rk[1][1])));
    AOnkri[7][0] = (Ankb[6][0]+((Onkb[6][1]*ri[2][2])-(Onkb[6][2]*ri[2][1])));
    AOnkri[7][1] = (Ankb[6][1]+((Onkb[6][2]*ri[2][0])-(Onkb[6][0]*ri[2][2])));
    AOnkri[7][2] = (Ankb[6][2]+((Onkb[6][0]*ri[2][1])-(Onkb[6][1]*ri[2][0])));
    Ankb[7][0] = (((AOnkri[7][0]*c7)-(AOnkri[7][2]*s7))+((Onkb[7][2]*rk[2][1])-(
      Onkb[7][1]*rk[2][2])));
    Ankb[7][1] = (AOnkri[7][1]+((Onkb[7][0]*rk[2][2])-(Onkb[7][2]*rk[2][0])));
    Ankb[7][2] = (((AOnkri[7][0]*s7)+(AOnkri[7][2]*c7))+((Onkb[7][1]*rk[2][0])-(
      Onkb[7][0]*rk[2][1])));
    AOnkri[8][0] = (Ankb[7][0]+((Onkb[7][1]*ri[3][2])-(Onkb[7][2]*ri[3][1])));
    AOnkri[8][1] = (Ankb[7][1]+((Onkb[7][2]*ri[3][0])-(Onkb[7][0]*ri[3][2])));
    AOnkri[8][2] = (Ankb[7][2]+((Onkb[7][0]*ri[3][1])-(Onkb[7][1]*ri[3][0])));
    Ankb[8][0] = (AOnkri[8][0]+((Onkb[8][2]*rk[3][1])-(Onkb[8][1]*rk[3][2])));
    Ankb[8][1] = (((AOnkri[8][1]*c8)+(AOnkri[8][2]*s8))+((Onkb[8][0]*rk[3][2])-(
      Onkb[8][2]*rk[3][0])));
    Ankb[8][2] = (((AOnkri[8][2]*c8)-(AOnkri[8][1]*s8))+((Onkb[8][1]*rk[3][0])-(
      Onkb[8][0]*rk[3][1])));
    AOnkri[9][0] = (Ankb[8][0]+((Onkb[8][1]*ri[4][2])-(Onkb[8][2]*ri[4][1])));
    AOnkri[9][1] = (Ankb[8][1]+((Onkb[8][2]*ri[4][0])-(Onkb[8][0]*ri[4][2])));
    AOnkri[9][2] = (Ankb[8][2]+((Onkb[8][0]*ri[4][1])-(Onkb[8][1]*ri[4][0])));
    Ankb[9][0] = (((AOnkri[9][0]*c9)-(AOnkri[9][2]*s9))+((Onkb[9][2]*rk[4][1])-(
      Onkb[9][1]*rk[4][2])));
    Ankb[9][1] = (AOnkri[9][1]+((Onkb[9][0]*rk[4][2])-(Onkb[9][2]*rk[4][0])));
    Ankb[9][2] = (((AOnkri[9][0]*s9)+(AOnkri[9][2]*c9))+((Onkb[9][1]*rk[4][0])-(
      Onkb[9][0]*rk[4][1])));
    AOnkri[10][0] = (Ankb[9][0]+((Onkb[9][1]*ri[5][2])-(Onkb[9][2]*ri[5][1])));
    AOnkri[10][1] = (Ankb[9][1]+((Onkb[9][2]*ri[5][0])-(Onkb[9][0]*ri[5][2])));
    AOnkri[10][2] = (Ankb[9][2]+((Onkb[9][0]*ri[5][1])-(Onkb[9][1]*ri[5][0])));
    Ankb[10][0] = (((AOnkri[10][0]*c10)-(AOnkri[10][2]*s10))+((Onkb[10][2]*
      rk[5][1])-(Onkb[10][1]*rk[5][2])));
    Ankb[10][1] = (AOnkri[10][1]+((Onkb[10][0]*rk[5][2])-(Onkb[10][2]*rk[5][0]))
      );
    Ankb[10][2] = (((AOnkri[10][0]*s10)+(AOnkri[10][2]*c10))+((Onkb[10][1]*
      rk[5][0])-(Onkb[10][0]*rk[5][1])));
    AOnkri[11][0] = (Ankb[10][0]+((Onkb[10][1]*ri[6][2])-(Onkb[10][2]*ri[6][1]))
      );
    AOnkri[11][1] = (Ankb[10][1]+((Onkb[10][2]*ri[6][0])-(Onkb[10][0]*ri[6][2]))
      );
    AOnkri[11][2] = (Ankb[10][2]+((Onkb[10][0]*ri[6][1])-(Onkb[10][1]*ri[6][0]))
      );
    Ankb[11][0] = (AOnkri[11][0]+((Onkb[11][2]*rk[6][1])-(Onkb[11][1]*rk[6][2]))
      );
    Ankb[11][1] = (((AOnkri[11][1]*c11)+(AOnkri[11][2]*s11))+((Onkb[11][0]*
      rk[6][2])-(Onkb[11][2]*rk[6][0])));
    Ankb[11][2] = (((AOnkri[11][2]*c11)-(AOnkri[11][1]*s11))+((Onkb[11][1]*
      rk[6][0])-(Onkb[11][0]*rk[6][1])));
    AOnkri[12][0] = (Ankb[5][0]+((ri[7][2]*udot[4])-(ri[7][1]*udot[5])));
    AOnkri[12][1] = (Ankb[5][1]+((ri[7][0]*udot[5])-(ri[7][2]*udot[3])));
    AOnkri[12][2] = (Ankb[5][2]+((ri[7][1]*udot[3])-(ri[7][0]*udot[4])));
    Ankb[12][0] = (((AOnkri[12][0]*c12)+(AOnkri[12][1]*s12))+((Onkb[12][2]*
      rk[7][1])-(Onkb[12][1]*rk[7][2])));
    Ankb[12][1] = (((AOnkri[12][1]*c12)-(AOnkri[12][0]*s12))+((Onkb[12][0]*
      rk[7][2])-(Onkb[12][2]*rk[7][0])));
    Ankb[12][2] = (AOnkri[12][2]+((Onkb[12][1]*rk[7][0])-(Onkb[12][0]*rk[7][1]))
      );
    AOnkri[13][0] = (Ankb[12][0]+((Onkb[12][1]*ri[8][2])-(Onkb[12][2]*ri[8][1]))
      );
    AOnkri[13][1] = (Ankb[12][1]+((Onkb[12][2]*ri[8][0])-(Onkb[12][0]*ri[8][2]))
      );
    AOnkri[13][2] = (Ankb[12][2]+((Onkb[12][0]*ri[8][1])-(Onkb[12][1]*ri[8][0]))
      );
    Ankb[13][0] = (((AOnkri[13][0]*c13)-(AOnkri[13][2]*s13))+((Onkb[13][2]*
      rk[8][1])-(Onkb[13][1]*rk[8][2])));
    Ankb[13][1] = (AOnkri[13][1]+((Onkb[13][0]*rk[8][2])-(Onkb[13][2]*rk[8][0]))
      );
    Ankb[13][2] = (((AOnkri[13][0]*s13)+(AOnkri[13][2]*c13))+((Onkb[13][1]*
      rk[8][0])-(Onkb[13][0]*rk[8][1])));
    AOnkri[14][0] = (Ankb[13][0]+((Onkb[13][1]*ri[9][2])-(Onkb[13][2]*ri[9][1]))
      );
    AOnkri[14][1] = (Ankb[13][1]+((Onkb[13][2]*ri[9][0])-(Onkb[13][0]*ri[9][2]))
      );
    AOnkri[14][2] = (Ankb[13][2]+((Onkb[13][0]*ri[9][1])-(Onkb[13][1]*ri[9][0]))
      );
    Ankb[14][0] = (AOnkri[14][0]+((Onkb[14][2]*rk[9][1])-(Onkb[14][1]*rk[9][2]))
      );
    Ankb[14][1] = (((AOnkri[14][1]*c14)+(AOnkri[14][2]*s14))+((Onkb[14][0]*
      rk[9][2])-(Onkb[14][2]*rk[9][0])));
    Ankb[14][2] = (((AOnkri[14][2]*c14)-(AOnkri[14][1]*s14))+((Onkb[14][1]*
      rk[9][0])-(Onkb[14][0]*rk[9][1])));
    AOnkri[15][0] = (Ankb[14][0]+((Onkb[14][1]*ri[10][2])-(Onkb[14][2]*ri[10][1]
      )));
    AOnkri[15][1] = (Ankb[14][1]+((Onkb[14][2]*ri[10][0])-(Onkb[14][0]*ri[10][2]
      )));
    AOnkri[15][2] = (Ankb[14][2]+((Onkb[14][0]*ri[10][1])-(Onkb[14][1]*ri[10][0]
      )));
    Ankb[15][0] = (((AOnkri[15][0]*c15)-(AOnkri[15][2]*s15))+((Onkb[15][2]*
      rk[10][1])-(Onkb[15][1]*rk[10][2])));
    Ankb[15][1] = (AOnkri[15][1]+((Onkb[15][0]*rk[10][2])-(Onkb[15][2]*rk[10][0]
      )));
    Ankb[15][2] = (((AOnkri[15][0]*s15)+(AOnkri[15][2]*c15))+((Onkb[15][1]*
      rk[10][0])-(Onkb[15][0]*rk[10][1])));
    AOnkri[16][0] = (Ankb[15][0]+((Onkb[15][1]*ri[11][2])-(Onkb[15][2]*ri[11][1]
      )));
    AOnkri[16][1] = (Ankb[15][1]+((Onkb[15][2]*ri[11][0])-(Onkb[15][0]*ri[11][2]
      )));
    AOnkri[16][2] = (Ankb[15][2]+((Onkb[15][0]*ri[11][1])-(Onkb[15][1]*ri[11][0]
      )));
    Ankb[16][0] = (((AOnkri[16][0]*c16)-(AOnkri[16][2]*s16))+((Onkb[16][2]*
      rk[11][1])-(Onkb[16][1]*rk[11][2])));
    Ankb[16][1] = (AOnkri[16][1]+((Onkb[16][0]*rk[11][2])-(Onkb[16][2]*rk[11][0]
      )));
    Ankb[16][2] = (((AOnkri[16][0]*s16)+(AOnkri[16][2]*c16))+((Onkb[16][1]*
      rk[11][0])-(Onkb[16][0]*rk[11][1])));
    AOnkri[17][0] = (Ankb[16][0]+((Onkb[16][1]*ri[12][2])-(Onkb[16][2]*ri[12][1]
      )));
    AOnkri[17][1] = (Ankb[16][1]+((Onkb[16][2]*ri[12][0])-(Onkb[16][0]*ri[12][2]
      )));
    AOnkri[17][2] = (Ankb[16][2]+((Onkb[16][0]*ri[12][1])-(Onkb[16][1]*ri[12][0]
      )));
    Ankb[17][0] = (AOnkri[17][0]+((Onkb[17][2]*rk[12][1])-(Onkb[17][1]*rk[12][2]
      )));
    Ankb[17][1] = (((AOnkri[17][1]*c17)+(AOnkri[17][2]*s17))+((Onkb[17][0]*
      rk[12][2])-(Onkb[17][2]*rk[12][0])));
    Ankb[17][2] = (((AOnkri[17][2]*c17)-(AOnkri[17][1]*s17))+((Onkb[17][1]*
      rk[12][0])-(Onkb[17][0]*rk[12][1])));
    AOnkri[18][0] = (Ankb[5][0]+((ri[13][2]*udot[4])-(ri[13][1]*udot[5])));
    AOnkri[18][1] = (Ankb[5][1]+((ri[13][0]*udot[5])-(ri[13][2]*udot[3])));
    AOnkri[18][2] = (Ankb[5][2]+((ri[13][1]*udot[3])-(ri[13][0]*udot[4])));
    Ankb[18][0] = (((AOnkri[18][0]*c18)-(AOnkri[18][2]*s18))+((Onkb[18][2]*
      rk[13][1])-(Onkb[18][1]*rk[13][2])));
    Ankb[18][1] = (AOnkri[18][1]+((Onkb[18][0]*rk[13][2])-(Onkb[18][2]*rk[13][0]
      )));
    Ankb[18][2] = (((AOnkri[18][0]*s18)+(AOnkri[18][2]*c18))+((Onkb[18][1]*
      rk[13][0])-(Onkb[18][0]*rk[13][1])));
    AOnkri[19][0] = (Ankb[18][0]+((Onkb[18][1]*ri[14][2])-(Onkb[18][2]*ri[14][1]
      )));
    AOnkri[19][1] = (Ankb[18][1]+((Onkb[18][2]*ri[14][0])-(Onkb[18][0]*ri[14][2]
      )));
    AOnkri[19][2] = (Ankb[18][2]+((Onkb[18][0]*ri[14][1])-(Onkb[18][1]*ri[14][0]
      )));
    Ankb[19][0] = (AOnkri[19][0]+((Onkb[19][2]*rk[14][1])-(Onkb[19][1]*rk[14][2]
      )));
    Ankb[19][1] = (((AOnkri[19][1]*c19)+(AOnkri[19][2]*s19))+((Onkb[19][0]*
      rk[14][2])-(Onkb[19][2]*rk[14][0])));
    Ankb[19][2] = (((AOnkri[19][2]*c19)-(AOnkri[19][1]*s19))+((Onkb[19][1]*
      rk[14][0])-(Onkb[19][0]*rk[14][1])));
    AOnkri[20][0] = (Ankb[19][0]+((Onkb[19][1]*ri[15][2])-(Onkb[19][2]*ri[15][1]
      )));
    AOnkri[20][1] = (Ankb[19][1]+((Onkb[19][2]*ri[15][0])-(Onkb[19][0]*ri[15][2]
      )));
    AOnkri[20][2] = (Ankb[19][2]+((Onkb[19][0]*ri[15][1])-(Onkb[19][1]*ri[15][0]
      )));
    Ankb[20][0] = (((AOnkri[20][0]*c20)-(AOnkri[20][2]*s20))+((Onkb[20][2]*
      rk[15][1])-(Onkb[20][1]*rk[15][2])));
    Ankb[20][1] = (AOnkri[20][1]+((Onkb[20][0]*rk[15][2])-(Onkb[20][2]*rk[15][0]
      )));
    Ankb[20][2] = (((AOnkri[20][0]*s20)+(AOnkri[20][2]*c20))+((Onkb[20][1]*
      rk[15][0])-(Onkb[20][0]*rk[15][1])));
    AOnkri[21][0] = (Ankb[20][0]+((Onkb[20][1]*ri[16][2])-(Onkb[20][2]*ri[16][1]
      )));
    AOnkri[21][1] = (Ankb[20][1]+((Onkb[20][2]*ri[16][0])-(Onkb[20][0]*ri[16][2]
      )));
    AOnkri[21][2] = (Ankb[20][2]+((Onkb[20][0]*ri[16][1])-(Onkb[20][1]*ri[16][0]
      )));
    Ankb[21][0] = (((AOnkri[21][0]*c21)+(AOnkri[21][1]*s21))+((Onkb[21][2]*
      rk[16][1])-(Onkb[21][1]*rk[16][2])));
    Ankb[21][1] = (((AOnkri[21][1]*c21)-(AOnkri[21][0]*s21))+((Onkb[21][0]*
      rk[16][2])-(Onkb[21][2]*rk[16][0])));
    Ankb[21][2] = (AOnkri[21][2]+((Onkb[21][1]*rk[16][0])-(Onkb[21][0]*rk[16][1]
      )));
    AOnkri[22][0] = (Ankb[5][0]+((ri[17][2]*udot[4])-(ri[17][1]*udot[5])));
    AOnkri[22][1] = (Ankb[5][1]+((ri[17][0]*udot[5])-(ri[17][2]*udot[3])));
    AOnkri[22][2] = (Ankb[5][2]+((ri[17][1]*udot[3])-(ri[17][0]*udot[4])));
    Ankb[22][0] = (((AOnkri[22][0]*c22)-(AOnkri[22][2]*s22))+((Onkb[22][2]*
      rk[17][1])-(Onkb[22][1]*rk[17][2])));
    Ankb[22][1] = (AOnkri[22][1]+((Onkb[22][0]*rk[17][2])-(Onkb[22][2]*rk[17][0]
      )));
    Ankb[22][2] = (((AOnkri[22][0]*s22)+(AOnkri[22][2]*c22))+((Onkb[22][1]*
      rk[17][0])-(Onkb[22][0]*rk[17][1])));
    AOnkri[23][0] = (Ankb[22][0]+((Onkb[22][1]*ri[18][2])-(Onkb[22][2]*ri[18][1]
      )));
    AOnkri[23][1] = (Ankb[22][1]+((Onkb[22][2]*ri[18][0])-(Onkb[22][0]*ri[18][2]
      )));
    AOnkri[23][2] = (Ankb[22][2]+((Onkb[22][0]*ri[18][1])-(Onkb[22][1]*ri[18][0]
      )));
    Ankb[23][0] = (AOnkri[23][0]+((Onkb[23][2]*rk[18][1])-(Onkb[23][1]*rk[18][2]
      )));
    Ankb[23][1] = (((AOnkri[23][1]*c23)+(AOnkri[23][2]*s23))+((Onkb[23][0]*
      rk[18][2])-(Onkb[23][2]*rk[18][0])));
    Ankb[23][2] = (((AOnkri[23][2]*c23)-(AOnkri[23][1]*s23))+((Onkb[23][1]*
      rk[18][0])-(Onkb[23][0]*rk[18][1])));
    AOnkri[24][0] = (Ankb[23][0]+((Onkb[23][1]*ri[19][2])-(Onkb[23][2]*ri[19][1]
      )));
    AOnkri[24][1] = (Ankb[23][1]+((Onkb[23][2]*ri[19][0])-(Onkb[23][0]*ri[19][2]
      )));
    AOnkri[24][2] = (Ankb[23][2]+((Onkb[23][0]*ri[19][1])-(Onkb[23][1]*ri[19][0]
      )));
    Ankb[24][0] = (((AOnkri[24][0]*c24)-(AOnkri[24][2]*s24))+((Onkb[24][2]*
      rk[19][1])-(Onkb[24][1]*rk[19][2])));
    Ankb[24][1] = (AOnkri[24][1]+((Onkb[24][0]*rk[19][2])-(Onkb[24][2]*rk[19][0]
      )));
    Ankb[24][2] = (((AOnkri[24][0]*s24)+(AOnkri[24][2]*c24))+((Onkb[24][1]*
      rk[19][0])-(Onkb[24][0]*rk[19][1])));
    AOnkri[25][0] = (Ankb[24][0]+((Onkb[24][1]*ri[20][2])-(Onkb[24][2]*ri[20][1]
      )));
    AOnkri[25][1] = (Ankb[24][1]+((Onkb[24][2]*ri[20][0])-(Onkb[24][0]*ri[20][2]
      )));
    AOnkri[25][2] = (Ankb[24][2]+((Onkb[24][0]*ri[20][1])-(Onkb[24][1]*ri[20][0]
      )));
    Ankb[25][0] = (((AOnkri[25][0]*c25)+(AOnkri[25][1]*s25))+((Onkb[25][2]*
      rk[20][1])-(Onkb[25][1]*rk[20][2])));
    Ankb[25][1] = (((AOnkri[25][1]*c25)-(AOnkri[25][0]*s25))+((Onkb[25][0]*
      rk[20][2])-(Onkb[25][2]*rk[20][0])));
    Ankb[25][2] = (AOnkri[25][2]+((Onkb[25][1]*rk[20][0])-(Onkb[25][0]*rk[20][1]
      )));
    AnkAtk[5][0] = (Ankb[5][0]+Atk[5][0]);
    AnkAtk[5][1] = (Ankb[5][1]+Atk[5][1]);
    AnkAtk[5][2] = (Ankb[5][2]+Atk[5][2]);
    ank[5][0] = ((AnkAtk[5][2]*Cik[3][0][2])+((AnkAtk[5][0]*Cik[3][0][0])+(
      AnkAtk[5][1]*Cik[3][0][1])));
    ank[5][1] = ((AnkAtk[5][2]*Cik[3][1][2])+((AnkAtk[5][0]*Cik[3][1][0])+(
      AnkAtk[5][1]*Cik[3][1][1])));
    ank[5][2] = ((AnkAtk[5][2]*Cik[3][2][2])+((AnkAtk[5][0]*Cik[3][2][0])+(
      AnkAtk[5][1]*Cik[3][2][1])));
    AnkAtk[6][0] = (Ankb[6][0]+Atk[6][0]);
    AnkAtk[6][1] = (Ankb[6][1]+Atk[6][1]);
    AnkAtk[6][2] = (Ankb[6][2]+Atk[6][2]);
    ank[6][0] = ((AnkAtk[6][2]*Cik[3][0][2])+((AnkAtk[6][0]*cnk[6][0][0])+(
      AnkAtk[6][1]*cnk[6][0][1])));
    ank[6][1] = ((AnkAtk[6][2]*Cik[3][1][2])+((AnkAtk[6][0]*cnk[6][1][0])+(
      AnkAtk[6][1]*cnk[6][1][1])));
    ank[6][2] = ((AnkAtk[6][2]*Cik[3][2][2])+((AnkAtk[6][0]*cnk[6][2][0])+(
      AnkAtk[6][1]*cnk[6][2][1])));
    AnkAtk[7][0] = (Ankb[7][0]+Atk[7][0]);
    AnkAtk[7][1] = (Ankb[7][1]+Atk[7][1]);
    AnkAtk[7][2] = (Ankb[7][2]+Atk[7][2]);
    ank[7][0] = ((AnkAtk[7][2]*cnk[7][0][2])+((AnkAtk[7][0]*cnk[7][0][0])+(
      AnkAtk[7][1]*cnk[6][0][1])));
    ank[7][1] = ((AnkAtk[7][2]*cnk[7][1][2])+((AnkAtk[7][0]*cnk[7][1][0])+(
      AnkAtk[7][1]*cnk[6][1][1])));
    ank[7][2] = ((AnkAtk[7][2]*cnk[7][2][2])+((AnkAtk[7][0]*cnk[7][2][0])+(
      AnkAtk[7][1]*cnk[6][2][1])));
    AnkAtk[8][0] = (Ankb[8][0]+Atk[8][0]);
    AnkAtk[8][1] = (Ankb[8][1]+Atk[8][1]);
    AnkAtk[8][2] = (Ankb[8][2]+Atk[8][2]);
    ank[8][0] = ((AnkAtk[8][2]*cnk[8][0][2])+((AnkAtk[8][0]*cnk[7][0][0])+(
      AnkAtk[8][1]*cnk[8][0][1])));
    ank[8][1] = ((AnkAtk[8][2]*cnk[8][1][2])+((AnkAtk[8][0]*cnk[7][1][0])+(
      AnkAtk[8][1]*cnk[8][1][1])));
    ank[8][2] = ((AnkAtk[8][2]*cnk[8][2][2])+((AnkAtk[8][0]*cnk[7][2][0])+(
      AnkAtk[8][1]*cnk[8][2][1])));
    AnkAtk[9][0] = (Ankb[9][0]+Atk[9][0]);
    AnkAtk[9][1] = (Ankb[9][1]+Atk[9][1]);
    AnkAtk[9][2] = (Ankb[9][2]+Atk[9][2]);
    ank[9][0] = ((AnkAtk[9][2]*cnk[9][0][2])+((AnkAtk[9][0]*cnk[9][0][0])+(
      AnkAtk[9][1]*cnk[8][0][1])));
    ank[9][1] = ((AnkAtk[9][2]*cnk[9][1][2])+((AnkAtk[9][0]*cnk[9][1][0])+(
      AnkAtk[9][1]*cnk[8][1][1])));
    ank[9][2] = ((AnkAtk[9][2]*cnk[9][2][2])+((AnkAtk[9][0]*cnk[9][2][0])+(
      AnkAtk[9][1]*cnk[8][2][1])));
    AnkAtk[10][0] = (Ankb[10][0]+Atk[10][0]);
    AnkAtk[10][1] = (Ankb[10][1]+Atk[10][1]);
    AnkAtk[10][2] = (Ankb[10][2]+Atk[10][2]);
    ank[10][0] = ((AnkAtk[10][2]*cnk[10][0][2])+((AnkAtk[10][0]*cnk[10][0][0])+(
      AnkAtk[10][1]*cnk[8][0][1])));
    ank[10][1] = ((AnkAtk[10][2]*cnk[10][1][2])+((AnkAtk[10][0]*cnk[10][1][0])+(
      AnkAtk[10][1]*cnk[8][1][1])));
    ank[10][2] = ((AnkAtk[10][2]*cnk[10][2][2])+((AnkAtk[10][0]*cnk[10][2][0])+(
      AnkAtk[10][1]*cnk[8][2][1])));
    AnkAtk[11][0] = (Ankb[11][0]+Atk[11][0]);
    AnkAtk[11][1] = (Ankb[11][1]+Atk[11][1]);
    AnkAtk[11][2] = (Ankb[11][2]+Atk[11][2]);
    ank[11][0] = ((AnkAtk[11][2]*cnk[11][0][2])+((AnkAtk[11][0]*cnk[10][0][0])+(
      AnkAtk[11][1]*cnk[11][0][1])));
    ank[11][1] = ((AnkAtk[11][2]*cnk[11][1][2])+((AnkAtk[11][0]*cnk[10][1][0])+(
      AnkAtk[11][1]*cnk[11][1][1])));
    ank[11][2] = ((AnkAtk[11][2]*cnk[11][2][2])+((AnkAtk[11][0]*cnk[10][2][0])+(
      AnkAtk[11][1]*cnk[11][2][1])));
    AnkAtk[12][0] = (Ankb[12][0]+Atk[12][0]);
    AnkAtk[12][1] = (Ankb[12][1]+Atk[12][1]);
    AnkAtk[12][2] = (Ankb[12][2]+Atk[12][2]);
    ank[12][0] = ((AnkAtk[12][2]*Cik[3][0][2])+((AnkAtk[12][0]*cnk[12][0][0])+(
      AnkAtk[12][1]*cnk[12][0][1])));
    ank[12][1] = ((AnkAtk[12][2]*Cik[3][1][2])+((AnkAtk[12][0]*cnk[12][1][0])+(
      AnkAtk[12][1]*cnk[12][1][1])));
    ank[12][2] = ((AnkAtk[12][2]*Cik[3][2][2])+((AnkAtk[12][0]*cnk[12][2][0])+(
      AnkAtk[12][1]*cnk[12][2][1])));
    AnkAtk[13][0] = (Ankb[13][0]+Atk[13][0]);
    AnkAtk[13][1] = (Ankb[13][1]+Atk[13][1]);
    AnkAtk[13][2] = (Ankb[13][2]+Atk[13][2]);
    ank[13][0] = ((AnkAtk[13][2]*cnk[13][0][2])+((AnkAtk[13][0]*cnk[13][0][0])+(
      AnkAtk[13][1]*cnk[12][0][1])));
    ank[13][1] = ((AnkAtk[13][2]*cnk[13][1][2])+((AnkAtk[13][0]*cnk[13][1][0])+(
      AnkAtk[13][1]*cnk[12][1][1])));
    ank[13][2] = ((AnkAtk[13][2]*cnk[13][2][2])+((AnkAtk[13][0]*cnk[13][2][0])+(
      AnkAtk[13][1]*cnk[12][2][1])));
    AnkAtk[14][0] = (Ankb[14][0]+Atk[14][0]);
    AnkAtk[14][1] = (Ankb[14][1]+Atk[14][1]);
    AnkAtk[14][2] = (Ankb[14][2]+Atk[14][2]);
    ank[14][0] = ((AnkAtk[14][2]*cnk[14][0][2])+((AnkAtk[14][0]*cnk[13][0][0])+(
      AnkAtk[14][1]*cnk[14][0][1])));
    ank[14][1] = ((AnkAtk[14][2]*cnk[14][1][2])+((AnkAtk[14][0]*cnk[13][1][0])+(
      AnkAtk[14][1]*cnk[14][1][1])));
    ank[14][2] = ((AnkAtk[14][2]*cnk[14][2][2])+((AnkAtk[14][0]*cnk[13][2][0])+(
      AnkAtk[14][1]*cnk[14][2][1])));
    AnkAtk[15][0] = (Ankb[15][0]+Atk[15][0]);
    AnkAtk[15][1] = (Ankb[15][1]+Atk[15][1]);
    AnkAtk[15][2] = (Ankb[15][2]+Atk[15][2]);
    ank[15][0] = ((AnkAtk[15][2]*cnk[15][0][2])+((AnkAtk[15][0]*cnk[15][0][0])+(
      AnkAtk[15][1]*cnk[14][0][1])));
    ank[15][1] = ((AnkAtk[15][2]*cnk[15][1][2])+((AnkAtk[15][0]*cnk[15][1][0])+(
      AnkAtk[15][1]*cnk[14][1][1])));
    ank[15][2] = ((AnkAtk[15][2]*cnk[15][2][2])+((AnkAtk[15][0]*cnk[15][2][0])+(
      AnkAtk[15][1]*cnk[14][2][1])));
    AnkAtk[16][0] = (Ankb[16][0]+Atk[16][0]);
    AnkAtk[16][1] = (Ankb[16][1]+Atk[16][1]);
    AnkAtk[16][2] = (Ankb[16][2]+Atk[16][2]);
    ank[16][0] = ((AnkAtk[16][2]*cnk[16][0][2])+((AnkAtk[16][0]*cnk[16][0][0])+(
      AnkAtk[16][1]*cnk[14][0][1])));
    ank[16][1] = ((AnkAtk[16][2]*cnk[16][1][2])+((AnkAtk[16][0]*cnk[16][1][0])+(
      AnkAtk[16][1]*cnk[14][1][1])));
    ank[16][2] = ((AnkAtk[16][2]*cnk[16][2][2])+((AnkAtk[16][0]*cnk[16][2][0])+(
      AnkAtk[16][1]*cnk[14][2][1])));
    AnkAtk[17][0] = (Ankb[17][0]+Atk[17][0]);
    AnkAtk[17][1] = (Ankb[17][1]+Atk[17][1]);
    AnkAtk[17][2] = (Ankb[17][2]+Atk[17][2]);
    ank[17][0] = ((AnkAtk[17][2]*cnk[17][0][2])+((AnkAtk[17][0]*cnk[16][0][0])+(
      AnkAtk[17][1]*cnk[17][0][1])));
    ank[17][1] = ((AnkAtk[17][2]*cnk[17][1][2])+((AnkAtk[17][0]*cnk[16][1][0])+(
      AnkAtk[17][1]*cnk[17][1][1])));
    ank[17][2] = ((AnkAtk[17][2]*cnk[17][2][2])+((AnkAtk[17][0]*cnk[16][2][0])+(
      AnkAtk[17][1]*cnk[17][2][1])));
    AnkAtk[18][0] = (Ankb[18][0]+Atk[18][0]);
    AnkAtk[18][1] = (Ankb[18][1]+Atk[18][1]);
    AnkAtk[18][2] = (Ankb[18][2]+Atk[18][2]);
    ank[18][0] = ((AnkAtk[18][2]*cnk[18][0][2])+((AnkAtk[18][0]*cnk[18][0][0])+(
      AnkAtk[18][1]*Cik[3][0][1])));
    ank[18][1] = ((AnkAtk[18][2]*cnk[18][1][2])+((AnkAtk[18][0]*cnk[18][1][0])+(
      AnkAtk[18][1]*Cik[3][1][1])));
    ank[18][2] = ((AnkAtk[18][2]*cnk[18][2][2])+((AnkAtk[18][0]*cnk[18][2][0])+(
      AnkAtk[18][1]*Cik[3][2][1])));
    AnkAtk[19][0] = (Ankb[19][0]+Atk[19][0]);
    AnkAtk[19][1] = (Ankb[19][1]+Atk[19][1]);
    AnkAtk[19][2] = (Ankb[19][2]+Atk[19][2]);
    ank[19][0] = ((AnkAtk[19][2]*cnk[19][0][2])+((AnkAtk[19][0]*cnk[18][0][0])+(
      AnkAtk[19][1]*cnk[19][0][1])));
    ank[19][1] = ((AnkAtk[19][2]*cnk[19][1][2])+((AnkAtk[19][0]*cnk[18][1][0])+(
      AnkAtk[19][1]*cnk[19][1][1])));
    ank[19][2] = ((AnkAtk[19][2]*cnk[19][2][2])+((AnkAtk[19][0]*cnk[18][2][0])+(
      AnkAtk[19][1]*cnk[19][2][1])));
    AnkAtk[20][0] = (Ankb[20][0]+Atk[20][0]);
    AnkAtk[20][1] = (Ankb[20][1]+Atk[20][1]);
    AnkAtk[20][2] = (Ankb[20][2]+Atk[20][2]);
    ank[20][0] = ((AnkAtk[20][2]*cnk[20][0][2])+((AnkAtk[20][0]*cnk[20][0][0])+(
      AnkAtk[20][1]*cnk[19][0][1])));
    ank[20][1] = ((AnkAtk[20][2]*cnk[20][1][2])+((AnkAtk[20][0]*cnk[20][1][0])+(
      AnkAtk[20][1]*cnk[19][1][1])));
    ank[20][2] = ((AnkAtk[20][2]*cnk[20][2][2])+((AnkAtk[20][0]*cnk[20][2][0])+(
      AnkAtk[20][1]*cnk[19][2][1])));
    AnkAtk[21][0] = (Ankb[21][0]+Atk[21][0]);
    AnkAtk[21][1] = (Ankb[21][1]+Atk[21][1]);
    AnkAtk[21][2] = (Ankb[21][2]+Atk[21][2]);
    ank[21][0] = ((AnkAtk[21][2]*cnk[20][0][2])+((AnkAtk[21][0]*cnk[21][0][0])+(
      AnkAtk[21][1]*cnk[21][0][1])));
    ank[21][1] = ((AnkAtk[21][2]*cnk[20][1][2])+((AnkAtk[21][0]*cnk[21][1][0])+(
      AnkAtk[21][1]*cnk[21][1][1])));
    ank[21][2] = ((AnkAtk[21][2]*cnk[20][2][2])+((AnkAtk[21][0]*cnk[21][2][0])+(
      AnkAtk[21][1]*cnk[21][2][1])));
    AnkAtk[22][0] = (Ankb[22][0]+Atk[22][0]);
    AnkAtk[22][1] = (Ankb[22][1]+Atk[22][1]);
    AnkAtk[22][2] = (Ankb[22][2]+Atk[22][2]);
    ank[22][0] = ((AnkAtk[22][2]*cnk[22][0][2])+((AnkAtk[22][0]*cnk[22][0][0])+(
      AnkAtk[22][1]*Cik[3][0][1])));
    ank[22][1] = ((AnkAtk[22][2]*cnk[22][1][2])+((AnkAtk[22][0]*cnk[22][1][0])+(
      AnkAtk[22][1]*Cik[3][1][1])));
    ank[22][2] = ((AnkAtk[22][2]*cnk[22][2][2])+((AnkAtk[22][0]*cnk[22][2][0])+(
      AnkAtk[22][1]*Cik[3][2][1])));
    AnkAtk[23][0] = (Ankb[23][0]+Atk[23][0]);
    AnkAtk[23][1] = (Ankb[23][1]+Atk[23][1]);
    AnkAtk[23][2] = (Ankb[23][2]+Atk[23][2]);
    ank[23][0] = ((AnkAtk[23][2]*cnk[23][0][2])+((AnkAtk[23][0]*cnk[22][0][0])+(
      AnkAtk[23][1]*cnk[23][0][1])));
    ank[23][1] = ((AnkAtk[23][2]*cnk[23][1][2])+((AnkAtk[23][0]*cnk[22][1][0])+(
      AnkAtk[23][1]*cnk[23][1][1])));
    ank[23][2] = ((AnkAtk[23][2]*cnk[23][2][2])+((AnkAtk[23][0]*cnk[22][2][0])+(
      AnkAtk[23][1]*cnk[23][2][1])));
    AnkAtk[24][0] = (Ankb[24][0]+Atk[24][0]);
    AnkAtk[24][1] = (Ankb[24][1]+Atk[24][1]);
    AnkAtk[24][2] = (Ankb[24][2]+Atk[24][2]);
    ank[24][0] = ((AnkAtk[24][2]*cnk[24][0][2])+((AnkAtk[24][0]*cnk[24][0][0])+(
      AnkAtk[24][1]*cnk[23][0][1])));
    ank[24][1] = ((AnkAtk[24][2]*cnk[24][1][2])+((AnkAtk[24][0]*cnk[24][1][0])+(
      AnkAtk[24][1]*cnk[23][1][1])));
    ank[24][2] = ((AnkAtk[24][2]*cnk[24][2][2])+((AnkAtk[24][0]*cnk[24][2][0])+(
      AnkAtk[24][1]*cnk[23][2][1])));
    AnkAtk[25][0] = (Ankb[25][0]+Atk[25][0]);
    AnkAtk[25][1] = (Ankb[25][1]+Atk[25][1]);
    AnkAtk[25][2] = (Ankb[25][2]+Atk[25][2]);
    ank[25][0] = ((AnkAtk[25][2]*cnk[24][0][2])+((AnkAtk[25][0]*cnk[25][0][0])+(
      AnkAtk[25][1]*cnk[25][0][1])));
    ank[25][1] = ((AnkAtk[25][2]*cnk[24][1][2])+((AnkAtk[25][0]*cnk[25][1][0])+(
      AnkAtk[25][1]*cnk[25][1][1])));
    ank[25][2] = ((AnkAtk[25][2]*cnk[24][2][2])+((AnkAtk[25][0]*cnk[25][2][0])+(
      AnkAtk[25][1]*cnk[25][2][1])));
    anb[0][0] = ank[5][0];
    anb[0][1] = ank[5][1];
    anb[0][2] = ank[5][2];
    anb[1][0] = ank[6][0];
    anb[1][1] = ank[6][1];
    anb[1][2] = ank[6][2];
    anb[2][0] = ank[7][0];
    anb[2][1] = ank[7][1];
    anb[2][2] = ank[7][2];
    anb[3][0] = ank[8][0];
    anb[3][1] = ank[8][1];
    anb[3][2] = ank[8][2];
    anb[4][0] = ank[9][0];
    anb[4][1] = ank[9][1];
    anb[4][2] = ank[9][2];
    anb[5][0] = ank[10][0];
    anb[5][1] = ank[10][1];
    anb[5][2] = ank[10][2];
    anb[6][0] = ank[11][0];
    anb[6][1] = ank[11][1];
    anb[6][2] = ank[11][2];
    anb[7][0] = ank[12][0];
    anb[7][1] = ank[12][1];
    anb[7][2] = ank[12][2];
    anb[8][0] = ank[13][0];
    anb[8][1] = ank[13][1];
    anb[8][2] = ank[13][2];
    anb[9][0] = ank[14][0];
    anb[9][1] = ank[14][1];
    anb[9][2] = ank[14][2];
    anb[10][0] = ank[15][0];
    anb[10][1] = ank[15][1];
    anb[10][2] = ank[15][2];
    anb[11][0] = ank[16][0];
    anb[11][1] = ank[16][1];
    anb[11][2] = ank[16][2];
    anb[12][0] = ank[17][0];
    anb[12][1] = ank[17][1];
    anb[12][2] = ank[17][2];
    anb[13][0] = ank[18][0];
    anb[13][1] = ank[18][1];
    anb[13][2] = ank[18][2];
    anb[14][0] = ank[19][0];
    anb[14][1] = ank[19][1];
    anb[14][2] = ank[19][2];
    anb[15][0] = ank[20][0];
    anb[15][1] = ank[20][1];
    anb[15][2] = ank[20][2];
    anb[16][0] = ank[21][0];
    anb[16][1] = ank[21][1];
    anb[16][2] = ank[21][2];
    anb[17][0] = ank[22][0];
    anb[17][1] = ank[22][1];
    anb[17][2] = ank[22][2];
    anb[18][0] = ank[23][0];
    anb[18][1] = ank[23][1];
    anb[18][2] = ank[23][2];
    anb[19][0] = ank[24][0];
    anb[19][1] = ank[24][1];
    anb[19][2] = ank[24][2];
    anb[20][0] = ank[25][0];
    anb[20][1] = ank[25][1];
    anb[20][2] = ank[25][2];
    roustate = 3;
/*
 Used 0.01 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  723 adds/subtracts/negates
                    604 multiplies
                      0 divides
                    709 assignments
*/
}

void Jimmy::sdmassmat(double *mmat)
{
/* Return the system mass matrix (LHS)
*/
    int i,j;

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(57,23);
        return;
    }
    sddomm(57);
    for (i = 0; i < 26; i++) {
        for (j = i; j <= 25; j++) {
            mmat[i*ndof + j] = mm[i][j];
            mmat[j*ndof + i] = mm[i][j];
        }
    }
}

void Jimmy::sdfrcmat(double fmat[26])
{
/* Return the system force matrix (RHS), excluding constraints
*/
    int i;

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(58,23);
        return;
    }
    sddofs0();
    for (i = 0; i < 26; i++) {
        fmat[i] = fs0[i];
    }
}

void Jimmy::sdpseudo(double lqout[1],
    double luout[1])
{
/*
Return pseudo-coordinates for loop joints.

*/
/*
There are no loop joints in this system.

*/
}

void Jimmy::sdpsqdot(double lqdout[1])
{
/*
Return pseudo-coordinate derivatives for loop joints.

*/
/*
There are no loop joints in this system.

*/
}

void Jimmy::sdpsudot(double ludout[1])
{
/*
Return pseudo-coordinate accelerations for loop joints.

*/
/*
There are no loop joints in this system.

*/
}

void Jimmy::sdperr(double errs[1])
{

}

void Jimmy::sdverr(double errs[1])
{

}

void Jimmy::sdaerr(double errs[1])
{

}
int Jimmy::sdchkbnum(int routine,

    int bnum)
{

    if ((bnum < -1) || (bnum > 20)) {
        sdseterr(routine,15);
        return 1;
    }
    return 0;
}
int Jimmy::sdchkjnum(int routine,

    int jnum)
{

    if ((jnum < 0) || (jnum > 20)) {
        sdseterr(routine,16);
        return 1;
    }
    return 0;
}
int Jimmy::sdchkucnum(int routine,

    int ucnum)
{

    if ((ucnum < 0) || (ucnum > -1)) {
        sdseterr(routine,21);
        return 1;
    }
    return 0;
}
int Jimmy::sdchkjaxis(int routine,

    int jnum,
    int axnum)
{
    int maxax;

    if (sdchkjnum(routine,jnum) != 0) {
        return 1;
    }
    if ((axnum < 0) || (axnum > 6)) {
        sdseterr(routine,17);
        return 1;
    }
    maxax = njntdof[jnum]-1;
    if ((jtype[jnum] == 4) || (jtype[jnum] == 6) || (jtype[jnum] == 21)) {
        maxax = maxax+1;
    }
    if (axnum > maxax) {
        sdseterr(routine,18);
        return 1;
    }
    return 0;
}
int Jimmy::sdchkjpin(int routine,

    int jnum,
    int pinno)
{
    int maxax,pinok;

    if (sdchkjnum(routine,jnum) != 0) {
        return 1;
    }
    if ((pinno < 0) || (pinno > 5)) {
        sdseterr(routine,17);
        return 1;
    }
    if (njntdof[jnum] >= 3) {
        maxax = 2;
    } else {
        maxax = njntdof[jnum]-1;
    }
    if (jtype[jnum] == 4) {
        maxax = -1;
    }
    if (jtype[jnum] == 7) {
        maxax = 0;
    }
    pinok = 0;
    if (pinno <= maxax) {
        pinok = 1;
    }
    if (pinok == 0) {
        sdseterr(routine,18);
        return 1;
    }
    return 0;
}
int Jimmy::sdindx(int joint,

    int axis)
{
    int offs,gotit;

    if (sdchkjaxis(36,joint,axis) != 0) {
        return 0;
    }
    gotit = 0;
    if (jtype[joint] == 4) {
        if (axis == 3) {
            offs = ballq[joint];
            gotit = 1;
        }
    } else {
        if ((jtype[joint] == 6) || (jtype[joint] == 21)) {
            if (axis == 6) {
                offs = ballq[joint];
                gotit = 1;
            }
        }
    }
    if (gotit == 0) {
        offs = firstq[joint]+axis;
    }
    return offs;
}

void Jimmy::sdpresacc(int joint,
    int axis,
    double prval)
{

}

void Jimmy::sdpresvel(int joint,
    int axis,
    double prval)
{

}

void Jimmy::sdprespos(int joint,
    int axis,
    double prval)
{

}

void Jimmy::sdgetht(int joint,
    int axis,
    double *torque)
{

    if (sdchkjaxis(30,joint,axis) != 0) {
        return;
    }
    if (roustate != 3) {
        sdseterr(30,24);
        return;
    }
    *torque = tauc[sdindx(joint,axis)];
}

void Jimmy::sdhinget(int joint,
    int axis,
    double torque)
{

    if (sdchkjaxis(10,joint,axis) != 0) {
        return;
    }
    if (roustate != 2) {
        sdseterr(10,23);
        return;
    }
    if (mfrcflg != 0) {
        mtau[sdindx(joint,axis)] = mtau[sdindx(joint,axis)]+torque;
    } else {
        fs0flg = 0;
        utau[sdindx(joint,axis)] = utau[sdindx(joint,axis)]+torque;
    }
}

void Jimmy::sdpointf(int body,
    double point[3],
    double force[3])
{
    double torque[3];

    if (sdchkbnum(11,body) != 0) {
        return;
    }
    if (roustate != 2) {
        sdseterr(11,23);
        return;
    }
    if (body == -1) {
        return;
    }
    torque[0] = point[1]*force[2]-point[2]*force[1];
    torque[1] = point[2]*force[0]-point[0]*force[2];
    torque[2] = point[0]*force[1]-point[1]*force[0];
    if (mfrcflg != 0) {
        mfk[body][0] = mfk[body][0]+force[0];
        mtk[body][0] = mtk[body][0]+torque[0];
        mfk[body][1] = mfk[body][1]+force[1];
        mtk[body][1] = mtk[body][1]+torque[1];
        mfk[body][2] = mfk[body][2]+force[2];
        mtk[body][2] = mtk[body][2]+torque[2];
    } else {
        fs0flg = 0;
        ufk[body][0] = ufk[body][0]+force[0];
        utk[body][0] = utk[body][0]+torque[0];
        ufk[body][1] = ufk[body][1]+force[1];
        utk[body][1] = utk[body][1]+torque[1];
        ufk[body][2] = ufk[body][2]+force[2];
        utk[body][2] = utk[body][2]+torque[2];
    }
}

void Jimmy::sdbodyt(int body,
    double torque[3])
{

    if (sdchkbnum(12,body) != 0) {
        return;
    }
    if (roustate != 2) {
        sdseterr(12,23);
        return;
    }
    if (body == -1) {
        return;
    }
    if (mfrcflg != 0) {
        mtk[body][0] = mtk[body][0]+torque[0];
        mtk[body][1] = mtk[body][1]+torque[1];
        mtk[body][2] = mtk[body][2]+torque[2];
    } else {
        fs0flg = 0;
        utk[body][0] = utk[body][0]+torque[0];
        utk[body][1] = utk[body][1]+torque[1];
        utk[body][2] = utk[body][2]+torque[2];
    }
}

void Jimmy::sddoww(int routine)
{

    roustate = 2;
    if (wwflg == 0) {
        wwflg = 1;
    }
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                      0 assignments
*/
}

void Jimmy::sdxudot0(int routine,
    double oudot0[26])
{
/*
Compute unconstrained equations
*/
    int i;

    sdlhs(routine);
/*
Solve equations for udots
*/
    sdfs0();
    sdldubslv(26,26,mmap,works,(double*)(double*)mlo,mdi,fs,udot);
    for (i = 0; i <= 25; i++) {
        oudot0[i] = udot[i];
    }
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     26 assignments
*/
}

void Jimmy::sdudot0(double oudot0[26])
{

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(66,23);
        return;
    }
    sdxudot0(66,oudot0);
}

void Jimmy::sdsetudot(double iudot[26])
{
/*
Assign udots and advance to stage Dynamics Ready
*/
    int i;

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(68,23);
        return;
    }
    for (i = 0; i <= 25; i++) {
        udot[i] = iudot[i];
    }
    sdrhs();
}

void Jimmy::sdxudotm(int routine,
    double imult[1],
    double oudotm[26])
{
/*
Compute udots due only to multipliers
*/
    int i;

    sdlhs(routine);
    for (i = 0; i <= 25; i++) {
        udot[i] = 0.;
    }
    for (i = 0; i <= 25; i++) {
        oudotm[i] = udot[i];
    }
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     52 assignments
*/
}

void Jimmy::sdudotm(double imult[1],
    double oudotm[26])
{

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(67,23);
        return;
    }
    sdxudotm(67,imult,oudotm);
}

void Jimmy::sdderiv(double oqdot[27],
    double oudot[26])
{
/*
This is the derivative section for a 21-body ground-based
system with 26 hinge degree(s) of freedom.
*/
    int i;
    double udot0[26],udot1[26];

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(17,23);
        return;
    }
    if (stabvelq == 1) {
        sdseterr(17,32);
    }
    if (stabposq == 1) {
        sdseterr(17,33);
    }
    wsiz = 0;
/*
Compute unconstrained equations
*/
    sdxudot0(17,udot0);
    sdrhs();
    wrank = 0;
    for (i = 0; i <= 26; i++) {
        oqdot[i] = qdot[i];
    }
    for (i = 0; i <= 25; i++) {
        oudot[i] = udot[i];
    }
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     53 assignments
*/
}
/*
Compute residuals for use with DAE integrator
*/

void Jimmy::sdresid(double eqdot[27],
    double eudot[26],
    double emults[1],
    double resid[53])
{
    int i;
    double uderrs[26];

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(16,23);
        return;
    }
    if (stabposq == 1) {
        sdseterr(16,33);
    }
    sdfulltrq(eudot,emults,uderrs);
    for (i = 0; i < 27; i++) {
        resid[i] = eqdot[i]-qdot[i];
    }
    for (i = 0; i < 26; i++) {
        resid[27+i] = uderrs[i];
    }
    for (i = 0; i < 26; i++) {
        udot[i] = eudot[i];
    }
    sdrhs();
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain   27 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     79 assignments
*/
}

void Jimmy::sdmult(double omults[1],
    int *owrank,
    int omultmap[1])
{

    if (roustate != 3) {
        sdseterr(34,24);
        return;
    }
    *owrank = wrank;
}

void Jimmy::sdreac(double force[21][3],
    double torque[21][3])
{
/*
Generated 27-Jan-2007 11:40:25 by SD/FAST, Kane's formulation
(sdfast B.2.8 #30123) on machine ID unknown
Copyright (c) 1990-1997 Symbolic Dynamics, Inc.
Copyright (c) 1990-1997 Parametric Technology Corp.
RESTRICTED RIGHTS LEGEND: Use, duplication, or disclosure by the U.S.
Government is subject to restrictions as set forth in subparagraph
(c)(1)(ii) of the Rights in Technical Data and Computer Software
clause at DFARS 52.227-7013 and similar clauses in the FAR and NASA
FAR Supplement.  Symbolic Dynamics, Inc., Mountain View, CA 94041
*/

    if (roustate != 3) {
        sdseterr(31,24);
        return;
    }
/*
Compute reaction forces for non-weld tree joints
*/
    fc[25][0] = ((mk[20]*(AnkAtk[25][0]-gk[25][0]))-ufk[20][0]);
    fc[25][1] = ((mk[20]*(AnkAtk[25][1]-gk[25][1]))-ufk[20][1]);
    fc[25][2] = ((mk[20]*(AnkAtk[25][2]-gk[24][2]))-ufk[20][2]);
    tc[25][0] = ((WkIkWk[25][0]+((ik[20][0][2]*onk[25][2])+((ik[20][0][0]*
      onk[25][0])+(ik[20][0][1]*onk[25][1]))))-(utk[20][0]+((fc[25][2]*rk[20][1]
      )-(fc[25][1]*rk[20][2]))));
    tc[25][1] = ((WkIkWk[25][1]+((ik[20][1][2]*onk[25][2])+((ik[20][1][0]*
      onk[25][0])+(ik[20][1][1]*onk[25][1]))))-(utk[20][1]+((fc[25][0]*rk[20][2]
      )-(fc[25][2]*rk[20][0]))));
    tc[25][2] = ((WkIkWk[25][2]+((ik[20][2][2]*onk[25][2])+((ik[20][2][0]*
      onk[25][0])+(ik[20][2][1]*onk[25][1]))))-(utk[20][2]+((fc[25][1]*rk[20][0]
      )-(fc[25][0]*rk[20][1]))));
    fccikt[25][0] = ((fc[25][0]*c25)-(fc[25][1]*s25));
    fccikt[25][1] = ((fc[25][0]*s25)+(fc[25][1]*c25));
    fccikt[25][2] = fc[25][2];
    ffk[24][0] = (ufk[19][0]-fccikt[25][0]);
    ffk[24][1] = (ufk[19][1]-fccikt[25][1]);
    ffk[24][2] = (ufk[19][2]-fccikt[25][2]);
    ttk[24][0] = (utk[19][0]-(((fccikt[25][2]*ri[20][1])-(fccikt[25][1]*
      ri[20][2]))+((tc[25][0]*c25)-(tc[25][1]*s25))));
    ttk[24][1] = (utk[19][1]-(((fccikt[25][0]*ri[20][2])-(fccikt[25][2]*
      ri[20][0]))+((tc[25][0]*s25)+(tc[25][1]*c25))));
    ttk[24][2] = (utk[19][2]-(tc[25][2]+((fccikt[25][1]*ri[20][0])-(
      fccikt[25][0]*ri[20][1]))));
    fc[24][0] = ((mk[19]*(AnkAtk[24][0]-gk[24][0]))-ffk[24][0]);
    fc[24][1] = ((mk[19]*(AnkAtk[24][1]-gk[23][1]))-ffk[24][1]);
    fc[24][2] = ((mk[19]*(AnkAtk[24][2]-gk[24][2]))-ffk[24][2]);
    tc[24][0] = ((WkIkWk[24][0]+((ik[19][0][2]*onk[24][2])+((ik[19][0][0]*
      onk[24][0])+(ik[19][0][1]*onk[24][1]))))-(ttk[24][0]+((fc[24][2]*rk[19][1]
      )-(fc[24][1]*rk[19][2]))));
    tc[24][1] = ((WkIkWk[24][1]+((ik[19][1][2]*onk[24][2])+((ik[19][1][0]*
      onk[24][0])+(ik[19][1][1]*onk[24][1]))))-(ttk[24][1]+((fc[24][0]*rk[19][2]
      )-(fc[24][2]*rk[19][0]))));
    tc[24][2] = ((WkIkWk[24][2]+((ik[19][2][2]*onk[24][2])+((ik[19][2][0]*
      onk[24][0])+(ik[19][2][1]*onk[24][1]))))-(ttk[24][2]+((fc[24][1]*rk[19][0]
      )-(fc[24][0]*rk[19][1]))));
    fccikt[24][0] = ((fc[24][0]*c24)+(fc[24][2]*s24));
    fccikt[24][1] = fc[24][1];
    fccikt[24][2] = ((fc[24][2]*c24)-(fc[24][0]*s24));
    ffk[23][0] = (ufk[18][0]-fccikt[24][0]);
    ffk[23][1] = (ufk[18][1]-fccikt[24][1]);
    ffk[23][2] = (ufk[18][2]-fccikt[24][2]);
    ttk[23][0] = (utk[18][0]-(((fccikt[24][2]*ri[19][1])-(fccikt[24][1]*
      ri[19][2]))+((tc[24][0]*c24)+(tc[24][2]*s24))));
    ttk[23][1] = (utk[18][1]-(tc[24][1]+((fccikt[24][0]*ri[19][2])-(
      fccikt[24][2]*ri[19][0]))));
    ttk[23][2] = (utk[18][2]-(((fccikt[24][1]*ri[19][0])-(fccikt[24][0]*
      ri[19][1]))+((tc[24][2]*c24)-(tc[24][0]*s24))));
    fc[23][0] = ((mk[18]*(AnkAtk[23][0]-gk[22][0]))-ffk[23][0]);
    fc[23][1] = ((mk[18]*(AnkAtk[23][1]-gk[23][1]))-ffk[23][1]);
    fc[23][2] = ((mk[18]*(AnkAtk[23][2]-gk[23][2]))-ffk[23][2]);
    tc[23][0] = ((WkIkWk[23][0]+((ik[18][0][2]*onk[23][2])+((ik[18][0][0]*
      onk[23][0])+(ik[18][0][1]*onk[23][1]))))-(ttk[23][0]+((fc[23][2]*rk[18][1]
      )-(fc[23][1]*rk[18][2]))));
    tc[23][1] = ((WkIkWk[23][1]+((ik[18][1][2]*onk[23][2])+((ik[18][1][0]*
      onk[23][0])+(ik[18][1][1]*onk[23][1]))))-(ttk[23][1]+((fc[23][0]*rk[18][2]
      )-(fc[23][2]*rk[18][0]))));
    tc[23][2] = ((WkIkWk[23][2]+((ik[18][2][2]*onk[23][2])+((ik[18][2][0]*
      onk[23][0])+(ik[18][2][1]*onk[23][1]))))-(ttk[23][2]+((fc[23][1]*rk[18][0]
      )-(fc[23][0]*rk[18][1]))));
    fccikt[23][0] = fc[23][0];
    fccikt[23][1] = ((fc[23][1]*c23)-(fc[23][2]*s23));
    fccikt[23][2] = ((fc[23][1]*s23)+(fc[23][2]*c23));
    ffk[22][0] = (ufk[17][0]-fccikt[23][0]);
    ffk[22][1] = (ufk[17][1]-fccikt[23][1]);
    ffk[22][2] = (ufk[17][2]-fccikt[23][2]);
    ttk[22][0] = (utk[17][0]-(tc[23][0]+((fccikt[23][2]*ri[18][1])-(
      fccikt[23][1]*ri[18][2]))));
    ttk[22][1] = (utk[17][1]-(((fccikt[23][0]*ri[18][2])-(fccikt[23][2]*
      ri[18][0]))+((tc[23][1]*c23)-(tc[23][2]*s23))));
    ttk[22][2] = (utk[17][2]-(((fccikt[23][1]*ri[18][0])-(fccikt[23][0]*
      ri[18][1]))+((tc[23][1]*s23)+(tc[23][2]*c23))));
    fc[22][0] = ((mk[17]*(AnkAtk[22][0]-gk[22][0]))-ffk[22][0]);
    fc[22][1] = ((mk[17]*(AnkAtk[22][1]+(9.81*Cik[3][2][1])))-ffk[22][1]);
    fc[22][2] = ((mk[17]*(AnkAtk[22][2]-gk[22][2]))-ffk[22][2]);
    tc[22][0] = ((WkIkWk[22][0]+((ik[17][0][2]*onk[22][2])+((ik[17][0][0]*
      onk[22][0])+(ik[17][0][1]*Onkb[22][1]))))-(ttk[22][0]+((fc[22][2]*
      rk[17][1])-(fc[22][1]*rk[17][2]))));
    tc[22][1] = ((WkIkWk[22][1]+((ik[17][1][2]*onk[22][2])+((ik[17][1][0]*
      onk[22][0])+(ik[17][1][1]*Onkb[22][1]))))-(ttk[22][1]+((fc[22][0]*
      rk[17][2])-(fc[22][2]*rk[17][0]))));
    tc[22][2] = ((WkIkWk[22][2]+((ik[17][2][2]*onk[22][2])+((ik[17][2][0]*
      onk[22][0])+(ik[17][2][1]*Onkb[22][1]))))-(ttk[22][2]+((fc[22][1]*
      rk[17][0])-(fc[22][0]*rk[17][1]))));
    fccikt[22][0] = ((fc[22][0]*c22)+(fc[22][2]*s22));
    fccikt[22][1] = fc[22][1];
    fccikt[22][2] = ((fc[22][2]*c22)-(fc[22][0]*s22));
    ffk[5][0] = (ufk[0][0]-fccikt[22][0]);
    ffk[5][1] = (ufk[0][1]-fccikt[22][1]);
    ffk[5][2] = (ufk[0][2]-fccikt[22][2]);
    ttk[5][0] = (utk[0][0]-(((fccikt[22][2]*ri[17][1])-(fccikt[22][1]*ri[17][2])
      )+((tc[22][0]*c22)+(tc[22][2]*s22))));
    ttk[5][1] = (utk[0][1]-(tc[22][1]+((fccikt[22][0]*ri[17][2])-(fccikt[22][2]*
      ri[17][0]))));
    ttk[5][2] = (utk[0][2]-(((fccikt[22][1]*ri[17][0])-(fccikt[22][0]*ri[17][1])
      )+((tc[22][2]*c22)-(tc[22][0]*s22))));
    fc[21][0] = ((mk[16]*(AnkAtk[21][0]-gk[21][0]))-ufk[16][0]);
    fc[21][1] = ((mk[16]*(AnkAtk[21][1]-gk[21][1]))-ufk[16][1]);
    fc[21][2] = ((mk[16]*(AnkAtk[21][2]-gk[20][2]))-ufk[16][2]);
    tc[21][0] = ((WkIkWk[21][0]+((ik[16][0][2]*onk[21][2])+((ik[16][0][0]*
      onk[21][0])+(ik[16][0][1]*onk[21][1]))))-(utk[16][0]+((fc[21][2]*rk[16][1]
      )-(fc[21][1]*rk[16][2]))));
    tc[21][1] = ((WkIkWk[21][1]+((ik[16][1][2]*onk[21][2])+((ik[16][1][0]*
      onk[21][0])+(ik[16][1][1]*onk[21][1]))))-(utk[16][1]+((fc[21][0]*rk[16][2]
      )-(fc[21][2]*rk[16][0]))));
    tc[21][2] = ((WkIkWk[21][2]+((ik[16][2][2]*onk[21][2])+((ik[16][2][0]*
      onk[21][0])+(ik[16][2][1]*onk[21][1]))))-(utk[16][2]+((fc[21][1]*rk[16][0]
      )-(fc[21][0]*rk[16][1]))));
    fccikt[21][0] = ((fc[21][0]*c21)-(fc[21][1]*s21));
    fccikt[21][1] = ((fc[21][0]*s21)+(fc[21][1]*c21));
    fccikt[21][2] = fc[21][2];
    ffk[20][0] = (ufk[15][0]-fccikt[21][0]);
    ffk[20][1] = (ufk[15][1]-fccikt[21][1]);
    ffk[20][2] = (ufk[15][2]-fccikt[21][2]);
    ttk[20][0] = (utk[15][0]-(((fccikt[21][2]*ri[16][1])-(fccikt[21][1]*
      ri[16][2]))+((tc[21][0]*c21)-(tc[21][1]*s21))));
    ttk[20][1] = (utk[15][1]-(((fccikt[21][0]*ri[16][2])-(fccikt[21][2]*
      ri[16][0]))+((tc[21][0]*s21)+(tc[21][1]*c21))));
    ttk[20][2] = (utk[15][2]-(tc[21][2]+((fccikt[21][1]*ri[16][0])-(
      fccikt[21][0]*ri[16][1]))));
    fc[20][0] = ((mk[15]*(AnkAtk[20][0]-gk[20][0]))-ffk[20][0]);
    fc[20][1] = ((mk[15]*(AnkAtk[20][1]-gk[19][1]))-ffk[20][1]);
    fc[20][2] = ((mk[15]*(AnkAtk[20][2]-gk[20][2]))-ffk[20][2]);
    tc[20][0] = ((WkIkWk[20][0]+((ik[15][0][2]*onk[20][2])+((ik[15][0][0]*
      onk[20][0])+(ik[15][0][1]*onk[20][1]))))-(ttk[20][0]+((fc[20][2]*rk[15][1]
      )-(fc[20][1]*rk[15][2]))));
    tc[20][1] = ((WkIkWk[20][1]+((ik[15][1][2]*onk[20][2])+((ik[15][1][0]*
      onk[20][0])+(ik[15][1][1]*onk[20][1]))))-(ttk[20][1]+((fc[20][0]*rk[15][2]
      )-(fc[20][2]*rk[15][0]))));
    tc[20][2] = ((WkIkWk[20][2]+((ik[15][2][2]*onk[20][2])+((ik[15][2][0]*
      onk[20][0])+(ik[15][2][1]*onk[20][1]))))-(ttk[20][2]+((fc[20][1]*rk[15][0]
      )-(fc[20][0]*rk[15][1]))));
    fccikt[20][0] = ((fc[20][0]*c20)+(fc[20][2]*s20));
    fccikt[20][1] = fc[20][1];
    fccikt[20][2] = ((fc[20][2]*c20)-(fc[20][0]*s20));
    ffk[19][0] = (ufk[14][0]-fccikt[20][0]);
    ffk[19][1] = (ufk[14][1]-fccikt[20][1]);
    ffk[19][2] = (ufk[14][2]-fccikt[20][2]);
    ttk[19][0] = (utk[14][0]-(((fccikt[20][2]*ri[15][1])-(fccikt[20][1]*
      ri[15][2]))+((tc[20][0]*c20)+(tc[20][2]*s20))));
    ttk[19][1] = (utk[14][1]-(tc[20][1]+((fccikt[20][0]*ri[15][2])-(
      fccikt[20][2]*ri[15][0]))));
    ttk[19][2] = (utk[14][2]-(((fccikt[20][1]*ri[15][0])-(fccikt[20][0]*
      ri[15][1]))+((tc[20][2]*c20)-(tc[20][0]*s20))));
    fc[19][0] = ((mk[14]*(AnkAtk[19][0]-gk[18][0]))-ffk[19][0]);
    fc[19][1] = ((mk[14]*(AnkAtk[19][1]-gk[19][1]))-ffk[19][1]);
    fc[19][2] = ((mk[14]*(AnkAtk[19][2]-gk[19][2]))-ffk[19][2]);
    tc[19][0] = ((WkIkWk[19][0]+((ik[14][0][2]*onk[19][2])+((ik[14][0][0]*
      onk[19][0])+(ik[14][0][1]*onk[19][1]))))-(ttk[19][0]+((fc[19][2]*rk[14][1]
      )-(fc[19][1]*rk[14][2]))));
    tc[19][1] = ((WkIkWk[19][1]+((ik[14][1][2]*onk[19][2])+((ik[14][1][0]*
      onk[19][0])+(ik[14][1][1]*onk[19][1]))))-(ttk[19][1]+((fc[19][0]*rk[14][2]
      )-(fc[19][2]*rk[14][0]))));
    tc[19][2] = ((WkIkWk[19][2]+((ik[14][2][2]*onk[19][2])+((ik[14][2][0]*
      onk[19][0])+(ik[14][2][1]*onk[19][1]))))-(ttk[19][2]+((fc[19][1]*rk[14][0]
      )-(fc[19][0]*rk[14][1]))));
    fccikt[19][0] = fc[19][0];
    fccikt[19][1] = ((fc[19][1]*c19)-(fc[19][2]*s19));
    fccikt[19][2] = ((fc[19][1]*s19)+(fc[19][2]*c19));
    ffk[18][0] = (ufk[13][0]-fccikt[19][0]);
    ffk[18][1] = (ufk[13][1]-fccikt[19][1]);
    ffk[18][2] = (ufk[13][2]-fccikt[19][2]);
    ttk[18][0] = (utk[13][0]-(tc[19][0]+((fccikt[19][2]*ri[14][1])-(
      fccikt[19][1]*ri[14][2]))));
    ttk[18][1] = (utk[13][1]-(((fccikt[19][0]*ri[14][2])-(fccikt[19][2]*
      ri[14][0]))+((tc[19][1]*c19)-(tc[19][2]*s19))));
    ttk[18][2] = (utk[13][2]-(((fccikt[19][1]*ri[14][0])-(fccikt[19][0]*
      ri[14][1]))+((tc[19][1]*s19)+(tc[19][2]*c19))));
    fc[18][0] = ((mk[13]*(AnkAtk[18][0]-gk[18][0]))-ffk[18][0]);
    fc[18][1] = ((mk[13]*(AnkAtk[18][1]+(9.81*Cik[3][2][1])))-ffk[18][1]);
    fc[18][2] = ((mk[13]*(AnkAtk[18][2]-gk[18][2]))-ffk[18][2]);
    tc[18][0] = ((WkIkWk[18][0]+((ik[13][0][2]*onk[18][2])+((ik[13][0][0]*
      onk[18][0])+(ik[13][0][1]*Onkb[18][1]))))-(ttk[18][0]+((fc[18][2]*
      rk[13][1])-(fc[18][1]*rk[13][2]))));
    tc[18][1] = ((WkIkWk[18][1]+((ik[13][1][2]*onk[18][2])+((ik[13][1][0]*
      onk[18][0])+(ik[13][1][1]*Onkb[18][1]))))-(ttk[18][1]+((fc[18][0]*
      rk[13][2])-(fc[18][2]*rk[13][0]))));
    tc[18][2] = ((WkIkWk[18][2]+((ik[13][2][2]*onk[18][2])+((ik[13][2][0]*
      onk[18][0])+(ik[13][2][1]*Onkb[18][1]))))-(ttk[18][2]+((fc[18][1]*
      rk[13][0])-(fc[18][0]*rk[13][1]))));
    fccikt[18][0] = ((fc[18][0]*c18)+(fc[18][2]*s18));
    fccikt[18][1] = fc[18][1];
    fccikt[18][2] = ((fc[18][2]*c18)-(fc[18][0]*s18));
    ffk[5][0] = (ffk[5][0]-fccikt[18][0]);
    ffk[5][1] = (ffk[5][1]-fccikt[18][1]);
    ffk[5][2] = (ffk[5][2]-fccikt[18][2]);
    ttk[5][0] = (ttk[5][0]-(((fccikt[18][2]*ri[13][1])-(fccikt[18][1]*ri[13][2])
      )+((tc[18][0]*c18)+(tc[18][2]*s18))));
    ttk[5][1] = (ttk[5][1]-(tc[18][1]+((fccikt[18][0]*ri[13][2])-(fccikt[18][2]*
      ri[13][0]))));
    ttk[5][2] = (ttk[5][2]-(((fccikt[18][1]*ri[13][0])-(fccikt[18][0]*ri[13][1])
      )+((tc[18][2]*c18)-(tc[18][0]*s18))));
    fc[17][0] = ((mk[12]*(AnkAtk[17][0]-gk[16][0]))-ufk[12][0]);
    fc[17][1] = ((mk[12]*(AnkAtk[17][1]-gk[17][1]))-ufk[12][1]);
    fc[17][2] = ((mk[12]*(AnkAtk[17][2]-gk[17][2]))-ufk[12][2]);
    tc[17][0] = ((WkIkWk[17][0]+((ik[12][0][2]*onk[17][2])+((ik[12][0][0]*
      onk[17][0])+(ik[12][0][1]*onk[17][1]))))-(utk[12][0]+((fc[17][2]*rk[12][1]
      )-(fc[17][1]*rk[12][2]))));
    tc[17][1] = ((WkIkWk[17][1]+((ik[12][1][2]*onk[17][2])+((ik[12][1][0]*
      onk[17][0])+(ik[12][1][1]*onk[17][1]))))-(utk[12][1]+((fc[17][0]*rk[12][2]
      )-(fc[17][2]*rk[12][0]))));
    tc[17][2] = ((WkIkWk[17][2]+((ik[12][2][2]*onk[17][2])+((ik[12][2][0]*
      onk[17][0])+(ik[12][2][1]*onk[17][1]))))-(utk[12][2]+((fc[17][1]*rk[12][0]
      )-(fc[17][0]*rk[12][1]))));
    fccikt[17][0] = fc[17][0];
    fccikt[17][1] = ((fc[17][1]*c17)-(fc[17][2]*s17));
    fccikt[17][2] = ((fc[17][1]*s17)+(fc[17][2]*c17));
    ffk[16][0] = (ufk[11][0]-fccikt[17][0]);
    ffk[16][1] = (ufk[11][1]-fccikt[17][1]);
    ffk[16][2] = (ufk[11][2]-fccikt[17][2]);
    ttk[16][0] = (utk[11][0]-(tc[17][0]+((fccikt[17][2]*ri[12][1])-(
      fccikt[17][1]*ri[12][2]))));
    ttk[16][1] = (utk[11][1]-(((fccikt[17][0]*ri[12][2])-(fccikt[17][2]*
      ri[12][0]))+((tc[17][1]*c17)-(tc[17][2]*s17))));
    ttk[16][2] = (utk[11][2]-(((fccikt[17][1]*ri[12][0])-(fccikt[17][0]*
      ri[12][1]))+((tc[17][1]*s17)+(tc[17][2]*c17))));
    fc[16][0] = ((mk[11]*(AnkAtk[16][0]-gk[16][0]))-ffk[16][0]);
    fc[16][1] = ((mk[11]*(AnkAtk[16][1]-gk[14][1]))-ffk[16][1]);
    fc[16][2] = ((mk[11]*(AnkAtk[16][2]-gk[16][2]))-ffk[16][2]);
    tc[16][0] = ((WkIkWk[16][0]+((ik[11][0][2]*onk[16][2])+((ik[11][0][0]*
      onk[16][0])+(ik[11][0][1]*onk[16][1]))))-(ttk[16][0]+((fc[16][2]*rk[11][1]
      )-(fc[16][1]*rk[11][2]))));
    tc[16][1] = ((WkIkWk[16][1]+((ik[11][1][2]*onk[16][2])+((ik[11][1][0]*
      onk[16][0])+(ik[11][1][1]*onk[16][1]))))-(ttk[16][1]+((fc[16][0]*rk[11][2]
      )-(fc[16][2]*rk[11][0]))));
    tc[16][2] = ((WkIkWk[16][2]+((ik[11][2][2]*onk[16][2])+((ik[11][2][0]*
      onk[16][0])+(ik[11][2][1]*onk[16][1]))))-(ttk[16][2]+((fc[16][1]*rk[11][0]
      )-(fc[16][0]*rk[11][1]))));
    fccikt[16][0] = ((fc[16][0]*c16)+(fc[16][2]*s16));
    fccikt[16][1] = fc[16][1];
    fccikt[16][2] = ((fc[16][2]*c16)-(fc[16][0]*s16));
    ffk[15][0] = (ufk[10][0]-fccikt[16][0]);
    ffk[15][1] = (ufk[10][1]-fccikt[16][1]);
    ffk[15][2] = (ufk[10][2]-fccikt[16][2]);
    ttk[15][0] = (utk[10][0]-(((fccikt[16][2]*ri[11][1])-(fccikt[16][1]*
      ri[11][2]))+((tc[16][0]*c16)+(tc[16][2]*s16))));
    ttk[15][1] = (utk[10][1]-(tc[16][1]+((fccikt[16][0]*ri[11][2])-(
      fccikt[16][2]*ri[11][0]))));
    ttk[15][2] = (utk[10][2]-(((fccikt[16][1]*ri[11][0])-(fccikt[16][0]*
      ri[11][1]))+((tc[16][2]*c16)-(tc[16][0]*s16))));
    fc[15][0] = ((mk[10]*(AnkAtk[15][0]-gk[15][0]))-ffk[15][0]);
    fc[15][1] = ((mk[10]*(AnkAtk[15][1]-gk[14][1]))-ffk[15][1]);
    fc[15][2] = ((mk[10]*(AnkAtk[15][2]-gk[15][2]))-ffk[15][2]);
    tc[15][0] = ((WkIkWk[15][0]+((ik[10][0][2]*onk[15][2])+((ik[10][0][0]*
      onk[15][0])+(ik[10][0][1]*onk[15][1]))))-(ttk[15][0]+((fc[15][2]*rk[10][1]
      )-(fc[15][1]*rk[10][2]))));
    tc[15][1] = ((WkIkWk[15][1]+((ik[10][1][2]*onk[15][2])+((ik[10][1][0]*
      onk[15][0])+(ik[10][1][1]*onk[15][1]))))-(ttk[15][1]+((fc[15][0]*rk[10][2]
      )-(fc[15][2]*rk[10][0]))));
    tc[15][2] = ((WkIkWk[15][2]+((ik[10][2][2]*onk[15][2])+((ik[10][2][0]*
      onk[15][0])+(ik[10][2][1]*onk[15][1]))))-(ttk[15][2]+((fc[15][1]*rk[10][0]
      )-(fc[15][0]*rk[10][1]))));
    fccikt[15][0] = ((fc[15][0]*c15)+(fc[15][2]*s15));
    fccikt[15][1] = fc[15][1];
    fccikt[15][2] = ((fc[15][2]*c15)-(fc[15][0]*s15));
    ffk[14][0] = (ufk[9][0]-fccikt[15][0]);
    ffk[14][1] = (ufk[9][1]-fccikt[15][1]);
    ffk[14][2] = (ufk[9][2]-fccikt[15][2]);
    ttk[14][0] = (utk[9][0]-(((fccikt[15][2]*ri[10][1])-(fccikt[15][1]*ri[10][2]
      ))+((tc[15][0]*c15)+(tc[15][2]*s15))));
    ttk[14][1] = (utk[9][1]-(tc[15][1]+((fccikt[15][0]*ri[10][2])-(fccikt[15][2]
      *ri[10][0]))));
    ttk[14][2] = (utk[9][2]-(((fccikt[15][1]*ri[10][0])-(fccikt[15][0]*ri[10][1]
      ))+((tc[15][2]*c15)-(tc[15][0]*s15))));
    fc[14][0] = ((mk[9]*(AnkAtk[14][0]-gk[13][0]))-ffk[14][0]);
    fc[14][1] = ((mk[9]*(AnkAtk[14][1]-gk[14][1]))-ffk[14][1]);
    fc[14][2] = ((mk[9]*(AnkAtk[14][2]-gk[14][2]))-ffk[14][2]);
    tc[14][0] = ((WkIkWk[14][0]+((ik[9][0][2]*onk[14][2])+((ik[9][0][0]*
      onk[14][0])+(ik[9][0][1]*onk[14][1]))))-(ttk[14][0]+((fc[14][2]*rk[9][1])-
      (fc[14][1]*rk[9][2]))));
    tc[14][1] = ((WkIkWk[14][1]+((ik[9][1][2]*onk[14][2])+((ik[9][1][0]*
      onk[14][0])+(ik[9][1][1]*onk[14][1]))))-(ttk[14][1]+((fc[14][0]*rk[9][2])-
      (fc[14][2]*rk[9][0]))));
    tc[14][2] = ((WkIkWk[14][2]+((ik[9][2][2]*onk[14][2])+((ik[9][2][0]*
      onk[14][0])+(ik[9][2][1]*onk[14][1]))))-(ttk[14][2]+((fc[14][1]*rk[9][0])-
      (fc[14][0]*rk[9][1]))));
    fccikt[14][0] = fc[14][0];
    fccikt[14][1] = ((fc[14][1]*c14)-(fc[14][2]*s14));
    fccikt[14][2] = ((fc[14][1]*s14)+(fc[14][2]*c14));
    ffk[13][0] = (ufk[8][0]-fccikt[14][0]);
    ffk[13][1] = (ufk[8][1]-fccikt[14][1]);
    ffk[13][2] = (ufk[8][2]-fccikt[14][2]);
    ttk[13][0] = (utk[8][0]-(tc[14][0]+((fccikt[14][2]*ri[9][1])-(fccikt[14][1]*
      ri[9][2]))));
    ttk[13][1] = (utk[8][1]-(((fccikt[14][0]*ri[9][2])-(fccikt[14][2]*ri[9][0]))
      +((tc[14][1]*c14)-(tc[14][2]*s14))));
    ttk[13][2] = (utk[8][2]-(((fccikt[14][1]*ri[9][0])-(fccikt[14][0]*ri[9][1]))
      +((tc[14][1]*s14)+(tc[14][2]*c14))));
    fc[13][0] = ((mk[8]*(AnkAtk[13][0]-gk[13][0]))-ffk[13][0]);
    fc[13][1] = ((mk[8]*(AnkAtk[13][1]-gk[12][1]))-ffk[13][1]);
    fc[13][2] = ((mk[8]*(AnkAtk[13][2]-gk[13][2]))-ffk[13][2]);
    tc[13][0] = ((WkIkWk[13][0]+((ik[8][0][2]*onk[13][2])+((ik[8][0][0]*
      onk[13][0])+(ik[8][0][1]*onk[13][1]))))-(ttk[13][0]+((fc[13][2]*rk[8][1])-
      (fc[13][1]*rk[8][2]))));
    tc[13][1] = ((WkIkWk[13][1]+((ik[8][1][2]*onk[13][2])+((ik[8][1][0]*
      onk[13][0])+(ik[8][1][1]*onk[13][1]))))-(ttk[13][1]+((fc[13][0]*rk[8][2])-
      (fc[13][2]*rk[8][0]))));
    tc[13][2] = ((WkIkWk[13][2]+((ik[8][2][2]*onk[13][2])+((ik[8][2][0]*
      onk[13][0])+(ik[8][2][1]*onk[13][1]))))-(ttk[13][2]+((fc[13][1]*rk[8][0])-
      (fc[13][0]*rk[8][1]))));
    fccikt[13][0] = ((fc[13][0]*c13)+(fc[13][2]*s13));
    fccikt[13][1] = fc[13][1];
    fccikt[13][2] = ((fc[13][2]*c13)-(fc[13][0]*s13));
    ffk[12][0] = (ufk[7][0]-fccikt[13][0]);
    ffk[12][1] = (ufk[7][1]-fccikt[13][1]);
    ffk[12][2] = (ufk[7][2]-fccikt[13][2]);
    ttk[12][0] = (utk[7][0]-(((fccikt[13][2]*ri[8][1])-(fccikt[13][1]*ri[8][2]))
      +((tc[13][0]*c13)+(tc[13][2]*s13))));
    ttk[12][1] = (utk[7][1]-(tc[13][1]+((fccikt[13][0]*ri[8][2])-(fccikt[13][2]*
      ri[8][0]))));
    ttk[12][2] = (utk[7][2]-(((fccikt[13][1]*ri[8][0])-(fccikt[13][0]*ri[8][1]))
      +((tc[13][2]*c13)-(tc[13][0]*s13))));
    fc[12][0] = ((mk[7]*(AnkAtk[12][0]-gk[12][0]))-ffk[12][0]);
    fc[12][1] = ((mk[7]*(AnkAtk[12][1]-gk[12][1]))-ffk[12][1]);
    fc[12][2] = ((mk[7]*(AnkAtk[12][2]+(9.81*Cik[3][2][2])))-ffk[12][2]);
    tc[12][0] = ((WkIkWk[12][0]+((ik[7][0][2]*Onkb[12][2])+((ik[7][0][0]*
      onk[12][0])+(ik[7][0][1]*onk[12][1]))))-(ttk[12][0]+((fc[12][2]*rk[7][1])-
      (fc[12][1]*rk[7][2]))));
    tc[12][1] = ((WkIkWk[12][1]+((ik[7][1][2]*Onkb[12][2])+((ik[7][1][0]*
      onk[12][0])+(ik[7][1][1]*onk[12][1]))))-(ttk[12][1]+((fc[12][0]*rk[7][2])-
      (fc[12][2]*rk[7][0]))));
    tc[12][2] = ((WkIkWk[12][2]+((ik[7][2][2]*Onkb[12][2])+((ik[7][2][0]*
      onk[12][0])+(ik[7][2][1]*onk[12][1]))))-(ttk[12][2]+((fc[12][1]*rk[7][0])-
      (fc[12][0]*rk[7][1]))));
    fccikt[12][0] = ((fc[12][0]*c12)-(fc[12][1]*s12));
    fccikt[12][1] = ((fc[12][0]*s12)+(fc[12][1]*c12));
    fccikt[12][2] = fc[12][2];
    ffk[5][0] = (ffk[5][0]-fccikt[12][0]);
    ffk[5][1] = (ffk[5][1]-fccikt[12][1]);
    ffk[5][2] = (ffk[5][2]-fccikt[12][2]);
    ttk[5][0] = (ttk[5][0]-(((fccikt[12][2]*ri[7][1])-(fccikt[12][1]*ri[7][2]))+
      ((tc[12][0]*c12)-(tc[12][1]*s12))));
    ttk[5][1] = (ttk[5][1]-(((fccikt[12][0]*ri[7][2])-(fccikt[12][2]*ri[7][0]))+
      ((tc[12][0]*s12)+(tc[12][1]*c12))));
    ttk[5][2] = (ttk[5][2]-(tc[12][2]+((fccikt[12][1]*ri[7][0])-(fccikt[12][0]*
      ri[7][1]))));
    fc[11][0] = ((mk[6]*(AnkAtk[11][0]-gk[10][0]))-ufk[6][0]);
    fc[11][1] = ((mk[6]*(AnkAtk[11][1]-gk[11][1]))-ufk[6][1]);
    fc[11][2] = ((mk[6]*(AnkAtk[11][2]-gk[11][2]))-ufk[6][2]);
    tc[11][0] = ((WkIkWk[11][0]+((ik[6][0][2]*onk[11][2])+((ik[6][0][0]*
      onk[11][0])+(ik[6][0][1]*onk[11][1]))))-(utk[6][0]+((fc[11][2]*rk[6][1])-(
      fc[11][1]*rk[6][2]))));
    tc[11][1] = ((WkIkWk[11][1]+((ik[6][1][2]*onk[11][2])+((ik[6][1][0]*
      onk[11][0])+(ik[6][1][1]*onk[11][1]))))-(utk[6][1]+((fc[11][0]*rk[6][2])-(
      fc[11][2]*rk[6][0]))));
    tc[11][2] = ((WkIkWk[11][2]+((ik[6][2][2]*onk[11][2])+((ik[6][2][0]*
      onk[11][0])+(ik[6][2][1]*onk[11][1]))))-(utk[6][2]+((fc[11][1]*rk[6][0])-(
      fc[11][0]*rk[6][1]))));
    fccikt[11][0] = fc[11][0];
    fccikt[11][1] = ((fc[11][1]*c11)-(fc[11][2]*s11));
    fccikt[11][2] = ((fc[11][1]*s11)+(fc[11][2]*c11));
    ffk[10][0] = (ufk[5][0]-fccikt[11][0]);
    ffk[10][1] = (ufk[5][1]-fccikt[11][1]);
    ffk[10][2] = (ufk[5][2]-fccikt[11][2]);
    ttk[10][0] = (utk[5][0]-(tc[11][0]+((fccikt[11][2]*ri[6][1])-(fccikt[11][1]*
      ri[6][2]))));
    ttk[10][1] = (utk[5][1]-(((fccikt[11][0]*ri[6][2])-(fccikt[11][2]*ri[6][0]))
      +((tc[11][1]*c11)-(tc[11][2]*s11))));
    ttk[10][2] = (utk[5][2]-(((fccikt[11][1]*ri[6][0])-(fccikt[11][0]*ri[6][1]))
      +((tc[11][1]*s11)+(tc[11][2]*c11))));
    fc[10][0] = ((mk[5]*(AnkAtk[10][0]-gk[10][0]))-ffk[10][0]);
    fc[10][1] = ((mk[5]*(AnkAtk[10][1]-gk[8][1]))-ffk[10][1]);
    fc[10][2] = ((mk[5]*(AnkAtk[10][2]-gk[10][2]))-ffk[10][2]);
    tc[10][0] = ((WkIkWk[10][0]+((ik[5][0][2]*onk[10][2])+((ik[5][0][0]*
      onk[10][0])+(ik[5][0][1]*onk[10][1]))))-(ttk[10][0]+((fc[10][2]*rk[5][1])-
      (fc[10][1]*rk[5][2]))));
    tc[10][1] = ((WkIkWk[10][1]+((ik[5][1][2]*onk[10][2])+((ik[5][1][0]*
      onk[10][0])+(ik[5][1][1]*onk[10][1]))))-(ttk[10][1]+((fc[10][0]*rk[5][2])-
      (fc[10][2]*rk[5][0]))));
    tc[10][2] = ((WkIkWk[10][2]+((ik[5][2][2]*onk[10][2])+((ik[5][2][0]*
      onk[10][0])+(ik[5][2][1]*onk[10][1]))))-(ttk[10][2]+((fc[10][1]*rk[5][0])-
      (fc[10][0]*rk[5][1]))));
    fccikt[10][0] = ((fc[10][0]*c10)+(fc[10][2]*s10));
    fccikt[10][1] = fc[10][1];
    fccikt[10][2] = ((fc[10][2]*c10)-(fc[10][0]*s10));
    ffk[9][0] = (ufk[4][0]-fccikt[10][0]);
    ffk[9][1] = (ufk[4][1]-fccikt[10][1]);
    ffk[9][2] = (ufk[4][2]-fccikt[10][2]);
    ttk[9][0] = (utk[4][0]-(((fccikt[10][2]*ri[5][1])-(fccikt[10][1]*ri[5][2]))+
      ((tc[10][0]*c10)+(tc[10][2]*s10))));
    ttk[9][1] = (utk[4][1]-(tc[10][1]+((fccikt[10][0]*ri[5][2])-(fccikt[10][2]*
      ri[5][0]))));
    ttk[9][2] = (utk[4][2]-(((fccikt[10][1]*ri[5][0])-(fccikt[10][0]*ri[5][1]))+
      ((tc[10][2]*c10)-(tc[10][0]*s10))));
    fc[9][0] = ((mk[4]*(AnkAtk[9][0]-gk[9][0]))-ffk[9][0]);
    fc[9][1] = ((mk[4]*(AnkAtk[9][1]-gk[8][1]))-ffk[9][1]);
    fc[9][2] = ((mk[4]*(AnkAtk[9][2]-gk[9][2]))-ffk[9][2]);
    tc[9][0] = ((WkIkWk[9][0]+((ik[4][0][2]*onk[9][2])+((ik[4][0][0]*onk[9][0])+
      (ik[4][0][1]*onk[9][1]))))-(ttk[9][0]+((fc[9][2]*rk[4][1])-(fc[9][1]*
      rk[4][2]))));
    tc[9][1] = ((WkIkWk[9][1]+((ik[4][1][2]*onk[9][2])+((ik[4][1][0]*onk[9][0])+
      (ik[4][1][1]*onk[9][1]))))-(ttk[9][1]+((fc[9][0]*rk[4][2])-(fc[9][2]*
      rk[4][0]))));
    tc[9][2] = ((WkIkWk[9][2]+((ik[4][2][2]*onk[9][2])+((ik[4][2][0]*onk[9][0])+
      (ik[4][2][1]*onk[9][1]))))-(ttk[9][2]+((fc[9][1]*rk[4][0])-(fc[9][0]*
      rk[4][1]))));
    fccikt[9][0] = ((fc[9][0]*c9)+(fc[9][2]*s9));
    fccikt[9][1] = fc[9][1];
    fccikt[9][2] = ((fc[9][2]*c9)-(fc[9][0]*s9));
    ffk[8][0] = (ufk[3][0]-fccikt[9][0]);
    ffk[8][1] = (ufk[3][1]-fccikt[9][1]);
    ffk[8][2] = (ufk[3][2]-fccikt[9][2]);
    ttk[8][0] = (utk[3][0]-(((fccikt[9][2]*ri[4][1])-(fccikt[9][1]*ri[4][2]))+((
      tc[9][0]*c9)+(tc[9][2]*s9))));
    ttk[8][1] = (utk[3][1]-(tc[9][1]+((fccikt[9][0]*ri[4][2])-(fccikt[9][2]*
      ri[4][0]))));
    ttk[8][2] = (utk[3][2]-(((fccikt[9][1]*ri[4][0])-(fccikt[9][0]*ri[4][1]))+((
      tc[9][2]*c9)-(tc[9][0]*s9))));
    fc[8][0] = ((mk[3]*(AnkAtk[8][0]-gk[7][0]))-ffk[8][0]);
    fc[8][1] = ((mk[3]*(AnkAtk[8][1]-gk[8][1]))-ffk[8][1]);
    fc[8][2] = ((mk[3]*(AnkAtk[8][2]-gk[8][2]))-ffk[8][2]);
    tc[8][0] = ((WkIkWk[8][0]+((ik[3][0][2]*onk[8][2])+((ik[3][0][0]*onk[8][0])+
      (ik[3][0][1]*onk[8][1]))))-(ttk[8][0]+((fc[8][2]*rk[3][1])-(fc[8][1]*
      rk[3][2]))));
    tc[8][1] = ((WkIkWk[8][1]+((ik[3][1][2]*onk[8][2])+((ik[3][1][0]*onk[8][0])+
      (ik[3][1][1]*onk[8][1]))))-(ttk[8][1]+((fc[8][0]*rk[3][2])-(fc[8][2]*
      rk[3][0]))));
    tc[8][2] = ((WkIkWk[8][2]+((ik[3][2][2]*onk[8][2])+((ik[3][2][0]*onk[8][0])+
      (ik[3][2][1]*onk[8][1]))))-(ttk[8][2]+((fc[8][1]*rk[3][0])-(fc[8][0]*
      rk[3][1]))));
    fccikt[8][0] = fc[8][0];
    fccikt[8][1] = ((fc[8][1]*c8)-(fc[8][2]*s8));
    fccikt[8][2] = ((fc[8][1]*s8)+(fc[8][2]*c8));
    ffk[7][0] = (ufk[2][0]-fccikt[8][0]);
    ffk[7][1] = (ufk[2][1]-fccikt[8][1]);
    ffk[7][2] = (ufk[2][2]-fccikt[8][2]);
    ttk[7][0] = (utk[2][0]-(tc[8][0]+((fccikt[8][2]*ri[3][1])-(fccikt[8][1]*
      ri[3][2]))));
    ttk[7][1] = (utk[2][1]-(((fccikt[8][0]*ri[3][2])-(fccikt[8][2]*ri[3][0]))+((
      tc[8][1]*c8)-(tc[8][2]*s8))));
    ttk[7][2] = (utk[2][2]-(((fccikt[8][1]*ri[3][0])-(fccikt[8][0]*ri[3][1]))+((
      tc[8][1]*s8)+(tc[8][2]*c8))));
    fc[7][0] = ((mk[2]*(AnkAtk[7][0]-gk[7][0]))-ffk[7][0]);
    fc[7][1] = ((mk[2]*(AnkAtk[7][1]-gk[6][1]))-ffk[7][1]);
    fc[7][2] = ((mk[2]*(AnkAtk[7][2]-gk[7][2]))-ffk[7][2]);
    tc[7][0] = ((WkIkWk[7][0]+((ik[2][0][2]*onk[7][2])+((ik[2][0][0]*onk[7][0])+
      (ik[2][0][1]*onk[7][1]))))-(ttk[7][0]+((fc[7][2]*rk[2][1])-(fc[7][1]*
      rk[2][2]))));
    tc[7][1] = ((WkIkWk[7][1]+((ik[2][1][2]*onk[7][2])+((ik[2][1][0]*onk[7][0])+
      (ik[2][1][1]*onk[7][1]))))-(ttk[7][1]+((fc[7][0]*rk[2][2])-(fc[7][2]*
      rk[2][0]))));
    tc[7][2] = ((WkIkWk[7][2]+((ik[2][2][2]*onk[7][2])+((ik[2][2][0]*onk[7][0])+
      (ik[2][2][1]*onk[7][1]))))-(ttk[7][2]+((fc[7][1]*rk[2][0])-(fc[7][0]*
      rk[2][1]))));
    fccikt[7][0] = ((fc[7][0]*c7)+(fc[7][2]*s7));
    fccikt[7][1] = fc[7][1];
    fccikt[7][2] = ((fc[7][2]*c7)-(fc[7][0]*s7));
    ffk[6][0] = (ufk[1][0]-fccikt[7][0]);
    ffk[6][1] = (ufk[1][1]-fccikt[7][1]);
    ffk[6][2] = (ufk[1][2]-fccikt[7][2]);
    ttk[6][0] = (utk[1][0]-(((fccikt[7][2]*ri[2][1])-(fccikt[7][1]*ri[2][2]))+((
      tc[7][0]*c7)+(tc[7][2]*s7))));
    ttk[6][1] = (utk[1][1]-(tc[7][1]+((fccikt[7][0]*ri[2][2])-(fccikt[7][2]*
      ri[2][0]))));
    ttk[6][2] = (utk[1][2]-(((fccikt[7][1]*ri[2][0])-(fccikt[7][0]*ri[2][1]))+((
      tc[7][2]*c7)-(tc[7][0]*s7))));
    fc[6][0] = ((mk[1]*(AnkAtk[6][0]-gk[6][0]))-ffk[6][0]);
    fc[6][1] = ((mk[1]*(AnkAtk[6][1]-gk[6][1]))-ffk[6][1]);
    fc[6][2] = ((mk[1]*(AnkAtk[6][2]+(9.81*Cik[3][2][2])))-ffk[6][2]);
    tc[6][0] = ((WkIkWk[6][0]+((ik[1][0][2]*Onkb[6][2])+((ik[1][0][0]*onk[6][0])
      +(ik[1][0][1]*onk[6][1]))))-(ttk[6][0]+((fc[6][2]*rk[1][1])-(fc[6][1]*
      rk[1][2]))));
    tc[6][1] = ((WkIkWk[6][1]+((ik[1][1][2]*Onkb[6][2])+((ik[1][1][0]*onk[6][0])
      +(ik[1][1][1]*onk[6][1]))))-(ttk[6][1]+((fc[6][0]*rk[1][2])-(fc[6][2]*
      rk[1][0]))));
    tc[6][2] = ((WkIkWk[6][2]+((ik[1][2][2]*Onkb[6][2])+((ik[1][2][0]*onk[6][0])
      +(ik[1][2][1]*onk[6][1]))))-(ttk[6][2]+((fc[6][1]*rk[1][0])-(fc[6][0]*
      rk[1][1]))));
    fccikt[6][0] = ((fc[6][0]*c6)-(fc[6][1]*s6));
    fccikt[6][1] = ((fc[6][0]*s6)+(fc[6][1]*c6));
    fccikt[6][2] = fc[6][2];
    ffk[5][0] = (ffk[5][0]-fccikt[6][0]);
    ffk[5][1] = (ffk[5][1]-fccikt[6][1]);
    ffk[5][2] = (ffk[5][2]-fccikt[6][2]);
    ttk[5][0] = (ttk[5][0]-(((fccikt[6][2]*ri[1][1])-(fccikt[6][1]*ri[1][2]))+((
      tc[6][0]*c6)-(tc[6][1]*s6))));
    ttk[5][1] = (ttk[5][1]-(((fccikt[6][0]*ri[1][2])-(fccikt[6][2]*ri[1][0]))+((
      tc[6][0]*s6)+(tc[6][1]*c6))));
    ttk[5][2] = (ttk[5][2]-(tc[6][2]+((fccikt[6][1]*ri[1][0])-(fccikt[6][0]*
      ri[1][1]))));
    fc[5][0] = ((mk[0]*(AnkAtk[5][0]+(9.81*Cik[3][2][0])))-ffk[5][0]);
    fc[5][1] = ((mk[0]*(AnkAtk[5][1]+(9.81*Cik[3][2][1])))-ffk[5][1]);
    fc[5][2] = ((mk[0]*(AnkAtk[5][2]+(9.81*Cik[3][2][2])))-ffk[5][2]);
    tc[5][0] = ((WkIkWk[5][0]+((ik[0][0][2]*udot[5])+((ik[0][0][0]*udot[3])+(
      ik[0][0][1]*udot[4]))))-(ttk[5][0]+((fc[5][2]*rk[0][1])-(fc[5][1]*rk[0][2]
      ))));
    tc[5][1] = ((WkIkWk[5][1]+((ik[0][1][2]*udot[5])+((ik[0][1][0]*udot[3])+(
      ik[0][1][1]*udot[4]))))-(ttk[5][1]+((fc[5][0]*rk[0][2])-(fc[5][2]*rk[0][0]
      ))));
    tc[5][2] = ((WkIkWk[5][2]+((ik[0][2][2]*udot[5])+((ik[0][2][0]*udot[3])+(
      ik[0][2][1]*udot[4]))))-(ttk[5][2]+((fc[5][1]*rk[0][0])-(fc[5][0]*rk[0][1]
      ))));
    fccikt[5][0] = fc[5][0];
    fccikt[5][1] = fc[5][1];
    fccikt[5][2] = fc[5][2];
    ffk[4][0] = -fccikt[5][0];
    ffk[4][1] = -fccikt[5][1];
    ffk[4][2] = -fccikt[5][2];
    ttk[4][0] = -tc[5][0];
    ttk[4][1] = -tc[5][1];
    ttk[4][2] = -tc[5][2];
    fc[4][0] = -ffk[4][0];
    fc[4][1] = -ffk[4][1];
    fc[4][2] = -ffk[4][2];
    tc[4][0] = -ttk[4][0];
    tc[4][1] = -ttk[4][1];
    tc[4][2] = -ttk[4][2];
    fccikt[4][0] = fc[4][0];
    fccikt[4][1] = fc[4][1];
    fccikt[4][2] = fc[4][2];
    ffk[3][0] = -fccikt[4][0];
    ffk[3][1] = -fccikt[4][1];
    ffk[3][2] = -fccikt[4][2];
    ttk[3][0] = -tc[4][0];
    ttk[3][1] = -tc[4][1];
    ttk[3][2] = -tc[4][2];
    fc[3][0] = -ffk[3][0];
    fc[3][1] = -ffk[3][1];
    fc[3][2] = -ffk[3][2];
    tc[3][0] = -ttk[3][0];
    tc[3][1] = -ttk[3][1];
    tc[3][2] = -ttk[3][2];
    fccikt[3][0] = ((Cik[3][0][2]*fc[3][2])+((Cik[3][0][0]*fc[3][0])+(
      Cik[3][0][1]*fc[3][1])));
    fccikt[3][1] = ((Cik[3][1][2]*fc[3][2])+((Cik[3][1][0]*fc[3][0])+(
      Cik[3][1][1]*fc[3][1])));
    fccikt[3][2] = ((Cik[3][2][2]*fc[3][2])+((Cik[3][2][0]*fc[3][0])+(
      Cik[3][2][1]*fc[3][1])));
    ffk[2][0] = -fccikt[3][0];
    ffk[2][1] = -fccikt[3][1];
    ffk[2][2] = -fccikt[3][2];
    ttk[2][0] = -((Cik[3][0][2]*tc[3][2])+((Cik[3][0][0]*tc[3][0])+(Cik[3][0][1]
      *tc[3][1])));
    ttk[2][1] = -((Cik[3][1][2]*tc[3][2])+((Cik[3][1][0]*tc[3][0])+(Cik[3][1][1]
      *tc[3][1])));
    ttk[2][2] = -((Cik[3][2][2]*tc[3][2])+((Cik[3][2][0]*tc[3][0])+(Cik[3][2][1]
      *tc[3][1])));
    fc[2][0] = -ffk[2][0];
    fc[2][1] = -ffk[2][1];
    fc[2][2] = -ffk[2][2];
    tc[2][0] = -ttk[2][0];
    tc[2][1] = -ttk[2][1];
    tc[2][2] = -ttk[2][2];
    fccikt[2][0] = fc[2][0];
    fccikt[2][1] = fc[2][1];
    fccikt[2][2] = fc[2][2];
    ffk[1][0] = -fccikt[2][0];
    ffk[1][1] = -fccikt[2][1];
    ffk[1][2] = -fccikt[2][2];
    ttk[1][0] = -(tc[2][0]-(fccikt[2][1]*q[2]));
    ttk[1][1] = -(tc[2][1]+(fccikt[2][0]*q[2]));
    ttk[1][2] = -tc[2][2];
    fc[1][0] = -ffk[1][0];
    fc[1][1] = -ffk[1][1];
    fc[1][2] = -ffk[1][2];
    tc[1][0] = -ttk[1][0];
    tc[1][1] = -ttk[1][1];
    tc[1][2] = -ttk[1][2];
    fccikt[1][0] = fc[1][0];
    fccikt[1][1] = fc[1][1];
    fccikt[1][2] = fc[1][2];
    ffk[0][0] = -fccikt[1][0];
    ffk[0][1] = -fccikt[1][1];
    ffk[0][2] = -fccikt[1][2];
    ttk[0][0] = -(tc[1][0]+(fccikt[1][2]*q[1]));
    ttk[0][1] = -tc[1][1];
    ttk[0][2] = -(tc[1][2]-(fccikt[1][0]*q[1]));
    fc[0][0] = -ffk[0][0];
    fc[0][1] = -ffk[0][1];
    fc[0][2] = -ffk[0][2];
    tc[0][0] = -ttk[0][0];
    tc[0][1] = -ttk[0][1];
    tc[0][2] = -ttk[0][2];
    force[0][0] = fc[5][0];
    torque[0][0] = tc[5][0];
    force[0][1] = fc[5][1];
    torque[0][1] = tc[5][1];
    force[0][2] = fc[5][2];
    torque[0][2] = tc[5][2];
    force[1][0] = fc[6][0];
    torque[1][0] = tc[6][0];
    force[1][1] = fc[6][1];
    torque[1][1] = tc[6][1];
    force[1][2] = fc[6][2];
    torque[1][2] = tc[6][2];
    force[2][0] = fc[7][0];
    torque[2][0] = tc[7][0];
    force[2][1] = fc[7][1];
    torque[2][1] = tc[7][1];
    force[2][2] = fc[7][2];
    torque[2][2] = tc[7][2];
    force[3][0] = fc[8][0];
    torque[3][0] = tc[8][0];
    force[3][1] = fc[8][1];
    torque[3][1] = tc[8][1];
    force[3][2] = fc[8][2];
    torque[3][2] = tc[8][2];
    force[4][0] = fc[9][0];
    torque[4][0] = tc[9][0];
    force[4][1] = fc[9][1];
    torque[4][1] = tc[9][1];
    force[4][2] = fc[9][2];
    torque[4][2] = tc[9][2];
    force[5][0] = fc[10][0];
    torque[5][0] = tc[10][0];
    force[5][1] = fc[10][1];
    torque[5][1] = tc[10][1];
    force[5][2] = fc[10][2];
    torque[5][2] = tc[10][2];
    force[6][0] = fc[11][0];
    torque[6][0] = tc[11][0];
    force[6][1] = fc[11][1];
    torque[6][1] = tc[11][1];
    force[6][2] = fc[11][2];
    torque[6][2] = tc[11][2];
    force[7][0] = fc[12][0];
    torque[7][0] = tc[12][0];
    force[7][1] = fc[12][1];
    torque[7][1] = tc[12][1];
    force[7][2] = fc[12][2];
    torque[7][2] = tc[12][2];
    force[8][0] = fc[13][0];
    torque[8][0] = tc[13][0];
    force[8][1] = fc[13][1];
    torque[8][1] = tc[13][1];
    force[8][2] = fc[13][2];
    torque[8][2] = tc[13][2];
    force[9][0] = fc[14][0];
    torque[9][0] = tc[14][0];
    force[9][1] = fc[14][1];
    torque[9][1] = tc[14][1];
    force[9][2] = fc[14][2];
    torque[9][2] = tc[14][2];
    force[10][0] = fc[15][0];
    torque[10][0] = tc[15][0];
    force[10][1] = fc[15][1];
    torque[10][1] = tc[15][1];
    force[10][2] = fc[15][2];
    torque[10][2] = tc[15][2];
    force[11][0] = fc[16][0];
    torque[11][0] = tc[16][0];
    force[11][1] = fc[16][1];
    torque[11][1] = tc[16][1];
    force[11][2] = fc[16][2];
    torque[11][2] = tc[16][2];
    force[12][0] = fc[17][0];
    torque[12][0] = tc[17][0];
    force[12][1] = fc[17][1];
    torque[12][1] = tc[17][1];
    force[12][2] = fc[17][2];
    torque[12][2] = tc[17][2];
    force[13][0] = fc[18][0];
    torque[13][0] = tc[18][0];
    force[13][1] = fc[18][1];
    torque[13][1] = tc[18][1];
    force[13][2] = fc[18][2];
    torque[13][2] = tc[18][2];
    force[14][0] = fc[19][0];
    torque[14][0] = tc[19][0];
    force[14][1] = fc[19][1];
    torque[14][1] = tc[19][1];
    force[14][2] = fc[19][2];
    torque[14][2] = tc[19][2];
    force[15][0] = fc[20][0];
    torque[15][0] = tc[20][0];
    force[15][1] = fc[20][1];
    torque[15][1] = tc[20][1];
    force[15][2] = fc[20][2];
    torque[15][2] = tc[20][2];
    force[16][0] = fc[21][0];
    torque[16][0] = tc[21][0];
    force[16][1] = fc[21][1];
    torque[16][1] = tc[21][1];
    force[16][2] = fc[21][2];
    torque[16][2] = tc[21][2];
    force[17][0] = fc[22][0];
    torque[17][0] = tc[22][0];
    force[17][1] = fc[22][1];
    torque[17][1] = tc[22][1];
    force[17][2] = fc[22][2];
    torque[17][2] = tc[22][2];
    force[18][0] = fc[23][0];
    torque[18][0] = tc[23][0];
    force[18][1] = fc[23][1];
    torque[18][1] = tc[23][1];
    force[18][2] = fc[23][2];
    torque[18][2] = tc[23][2];
    force[19][0] = fc[24][0];
    torque[19][0] = tc[24][0];
    force[19][1] = fc[24][1];
    torque[19][1] = tc[24][1];
    force[19][2] = fc[24][2];
    torque[19][2] = tc[24][2];
    force[20][0] = fc[25][0];
    torque[20][0] = tc[25][0];
    force[20][1] = fc[25][1];
    torque[20][1] = tc[25][1];
    force[20][2] = fc[25][2];
    torque[20][2] = tc[25][2];
/*
Compute reaction forces for tree weld joints
*/
/*
 Used 0.01 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  900 adds/subtracts/negates
                    687 multiplies
                      0 divides
                    507 assignments
*/
}

void Jimmy::sdmom(double lm[3],
    double am[3],
    double *ke)
{
/*
Compute system linear and angular momentum, and kinetic energy.

Generated 27-Jan-2007 11:40:25 by SD/FAST, Kane's formulation
(sdfast B.2.8 #30123) on machine ID unknown
Copyright (c) 1990-1997 Symbolic Dynamics, Inc.
Copyright (c) 1990-1997 Parametric Technology Corp.
RESTRICTED RIGHTS LEGEND: Use, duplication, or disclosure by the U.S.
Government is subject to restrictions as set forth in subparagraph
(c)(1)(ii) of the Rights in Technical Data and Computer Software
clause at DFARS 52.227-7013 and similar clauses in the FAR and NASA
FAR Supplement.  Symbolic Dynamics, Inc., Mountain View, CA 94041
*/
    double lk[21][3],hnk[21][3];

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(19,23);
        return;
    }
    lk[0][0] = (mk[0]*vnk[5][0]);
    lk[0][1] = (mk[0]*vnk[5][1]);
    lk[0][2] = (mk[0]*vnk[5][2]);
    lk[1][0] = (mk[1]*vnk[6][0]);
    lk[1][1] = (mk[1]*vnk[6][1]);
    lk[1][2] = (mk[1]*vnk[6][2]);
    lk[2][0] = (mk[2]*vnk[7][0]);
    lk[2][1] = (mk[2]*vnk[7][1]);
    lk[2][2] = (mk[2]*vnk[7][2]);
    lk[3][0] = (mk[3]*vnk[8][0]);
    lk[3][1] = (mk[3]*vnk[8][1]);
    lk[3][2] = (mk[3]*vnk[8][2]);
    lk[4][0] = (mk[4]*vnk[9][0]);
    lk[4][1] = (mk[4]*vnk[9][1]);
    lk[4][2] = (mk[4]*vnk[9][2]);
    lk[5][0] = (mk[5]*vnk[10][0]);
    lk[5][1] = (mk[5]*vnk[10][1]);
    lk[5][2] = (mk[5]*vnk[10][2]);
    lk[6][0] = (mk[6]*vnk[11][0]);
    lk[6][1] = (mk[6]*vnk[11][1]);
    lk[6][2] = (mk[6]*vnk[11][2]);
    lk[7][0] = (mk[7]*vnk[12][0]);
    lk[7][1] = (mk[7]*vnk[12][1]);
    lk[7][2] = (mk[7]*vnk[12][2]);
    lk[8][0] = (mk[8]*vnk[13][0]);
    lk[8][1] = (mk[8]*vnk[13][1]);
    lk[8][2] = (mk[8]*vnk[13][2]);
    lk[9][0] = (mk[9]*vnk[14][0]);
    lk[9][1] = (mk[9]*vnk[14][1]);
    lk[9][2] = (mk[9]*vnk[14][2]);
    lk[10][0] = (mk[10]*vnk[15][0]);
    lk[10][1] = (mk[10]*vnk[15][1]);
    lk[10][2] = (mk[10]*vnk[15][2]);
    lk[11][0] = (mk[11]*vnk[16][0]);
    lk[11][1] = (mk[11]*vnk[16][1]);
    lk[11][2] = (mk[11]*vnk[16][2]);
    lk[12][0] = (mk[12]*vnk[17][0]);
    lk[12][1] = (mk[12]*vnk[17][1]);
    lk[12][2] = (mk[12]*vnk[17][2]);
    lk[13][0] = (mk[13]*vnk[18][0]);
    lk[13][1] = (mk[13]*vnk[18][1]);
    lk[13][2] = (mk[13]*vnk[18][2]);
    lk[14][0] = (mk[14]*vnk[19][0]);
    lk[14][1] = (mk[14]*vnk[19][1]);
    lk[14][2] = (mk[14]*vnk[19][2]);
    lk[15][0] = (mk[15]*vnk[20][0]);
    lk[15][1] = (mk[15]*vnk[20][1]);
    lk[15][2] = (mk[15]*vnk[20][2]);
    lk[16][0] = (mk[16]*vnk[21][0]);
    lk[16][1] = (mk[16]*vnk[21][1]);
    lk[16][2] = (mk[16]*vnk[21][2]);
    lk[17][0] = (mk[17]*vnk[22][0]);
    lk[17][1] = (mk[17]*vnk[22][1]);
    lk[17][2] = (mk[17]*vnk[22][2]);
    lk[18][0] = (mk[18]*vnk[23][0]);
    lk[18][1] = (mk[18]*vnk[23][1]);
    lk[18][2] = (mk[18]*vnk[23][2]);
    lk[19][0] = (mk[19]*vnk[24][0]);
    lk[19][1] = (mk[19]*vnk[24][1]);
    lk[19][2] = (mk[19]*vnk[24][2]);
    lk[20][0] = (mk[20]*vnk[25][0]);
    lk[20][1] = (mk[20]*vnk[25][1]);
    lk[20][2] = (mk[20]*vnk[25][2]);
    hnk[0][0] = ((ik[0][0][2]*u[5])+((ik[0][0][0]*u[3])+(ik[0][0][1]*u[4])));
    hnk[0][1] = ((ik[0][1][2]*u[5])+((ik[0][1][0]*u[3])+(ik[0][1][1]*u[4])));
    hnk[0][2] = ((ik[0][2][2]*u[5])+((ik[0][2][0]*u[3])+(ik[0][2][1]*u[4])));
    hnk[1][0] = ((ik[1][0][2]*wk[6][2])+((ik[1][0][0]*wk[6][0])+(ik[1][0][1]*
      wk[6][1])));
    hnk[1][1] = ((ik[1][1][2]*wk[6][2])+((ik[1][1][0]*wk[6][0])+(ik[1][1][1]*
      wk[6][1])));
    hnk[1][2] = ((ik[1][2][2]*wk[6][2])+((ik[1][2][0]*wk[6][0])+(ik[1][2][1]*
      wk[6][1])));
    hnk[2][0] = ((ik[2][0][2]*wk[7][2])+((ik[2][0][0]*wk[7][0])+(ik[2][0][1]*
      wk[7][1])));
    hnk[2][1] = ((ik[2][1][2]*wk[7][2])+((ik[2][1][0]*wk[7][0])+(ik[2][1][1]*
      wk[7][1])));
    hnk[2][2] = ((ik[2][2][2]*wk[7][2])+((ik[2][2][0]*wk[7][0])+(ik[2][2][1]*
      wk[7][1])));
    hnk[3][0] = ((ik[3][0][2]*wk[8][2])+((ik[3][0][0]*wk[8][0])+(ik[3][0][1]*
      wk[8][1])));
    hnk[3][1] = ((ik[3][1][2]*wk[8][2])+((ik[3][1][0]*wk[8][0])+(ik[3][1][1]*
      wk[8][1])));
    hnk[3][2] = ((ik[3][2][2]*wk[8][2])+((ik[3][2][0]*wk[8][0])+(ik[3][2][1]*
      wk[8][1])));
    hnk[4][0] = ((ik[4][0][2]*wk[9][2])+((ik[4][0][0]*wk[9][0])+(ik[4][0][1]*
      wk[9][1])));
    hnk[4][1] = ((ik[4][1][2]*wk[9][2])+((ik[4][1][0]*wk[9][0])+(ik[4][1][1]*
      wk[9][1])));
    hnk[4][2] = ((ik[4][2][2]*wk[9][2])+((ik[4][2][0]*wk[9][0])+(ik[4][2][1]*
      wk[9][1])));
    hnk[5][0] = ((ik[5][0][2]*wk[10][2])+((ik[5][0][0]*wk[10][0])+(ik[5][0][1]*
      wk[10][1])));
    hnk[5][1] = ((ik[5][1][2]*wk[10][2])+((ik[5][1][0]*wk[10][0])+(ik[5][1][1]*
      wk[10][1])));
    hnk[5][2] = ((ik[5][2][2]*wk[10][2])+((ik[5][2][0]*wk[10][0])+(ik[5][2][1]*
      wk[10][1])));
    hnk[6][0] = ((ik[6][0][2]*wk[11][2])+((ik[6][0][0]*wk[11][0])+(ik[6][0][1]*
      wk[11][1])));
    hnk[6][1] = ((ik[6][1][2]*wk[11][2])+((ik[6][1][0]*wk[11][0])+(ik[6][1][1]*
      wk[11][1])));
    hnk[6][2] = ((ik[6][2][2]*wk[11][2])+((ik[6][2][0]*wk[11][0])+(ik[6][2][1]*
      wk[11][1])));
    hnk[7][0] = ((ik[7][0][2]*wk[12][2])+((ik[7][0][0]*wk[12][0])+(ik[7][0][1]*
      wk[12][1])));
    hnk[7][1] = ((ik[7][1][2]*wk[12][2])+((ik[7][1][0]*wk[12][0])+(ik[7][1][1]*
      wk[12][1])));
    hnk[7][2] = ((ik[7][2][2]*wk[12][2])+((ik[7][2][0]*wk[12][0])+(ik[7][2][1]*
      wk[12][1])));
    hnk[8][0] = ((ik[8][0][2]*wk[13][2])+((ik[8][0][0]*wk[13][0])+(ik[8][0][1]*
      wk[13][1])));
    hnk[8][1] = ((ik[8][1][2]*wk[13][2])+((ik[8][1][0]*wk[13][0])+(ik[8][1][1]*
      wk[13][1])));
    hnk[8][2] = ((ik[8][2][2]*wk[13][2])+((ik[8][2][0]*wk[13][0])+(ik[8][2][1]*
      wk[13][1])));
    hnk[9][0] = ((ik[9][0][2]*wk[14][2])+((ik[9][0][0]*wk[14][0])+(ik[9][0][1]*
      wk[14][1])));
    hnk[9][1] = ((ik[9][1][2]*wk[14][2])+((ik[9][1][0]*wk[14][0])+(ik[9][1][1]*
      wk[14][1])));
    hnk[9][2] = ((ik[9][2][2]*wk[14][2])+((ik[9][2][0]*wk[14][0])+(ik[9][2][1]*
      wk[14][1])));
    hnk[10][0] = ((ik[10][0][2]*wk[15][2])+((ik[10][0][0]*wk[15][0])+(
      ik[10][0][1]*wk[15][1])));
    hnk[10][1] = ((ik[10][1][2]*wk[15][2])+((ik[10][1][0]*wk[15][0])+(
      ik[10][1][1]*wk[15][1])));
    hnk[10][2] = ((ik[10][2][2]*wk[15][2])+((ik[10][2][0]*wk[15][0])+(
      ik[10][2][1]*wk[15][1])));
    hnk[11][0] = ((ik[11][0][2]*wk[16][2])+((ik[11][0][0]*wk[16][0])+(
      ik[11][0][1]*wk[16][1])));
    hnk[11][1] = ((ik[11][1][2]*wk[16][2])+((ik[11][1][0]*wk[16][0])+(
      ik[11][1][1]*wk[16][1])));
    hnk[11][2] = ((ik[11][2][2]*wk[16][2])+((ik[11][2][0]*wk[16][0])+(
      ik[11][2][1]*wk[16][1])));
    hnk[12][0] = ((ik[12][0][2]*wk[17][2])+((ik[12][0][0]*wk[17][0])+(
      ik[12][0][1]*wk[17][1])));
    hnk[12][1] = ((ik[12][1][2]*wk[17][2])+((ik[12][1][0]*wk[17][0])+(
      ik[12][1][1]*wk[17][1])));
    hnk[12][2] = ((ik[12][2][2]*wk[17][2])+((ik[12][2][0]*wk[17][0])+(
      ik[12][2][1]*wk[17][1])));
    hnk[13][0] = ((ik[13][0][2]*wk[18][2])+((ik[13][0][0]*wk[18][0])+(
      ik[13][0][1]*wk[18][1])));
    hnk[13][1] = ((ik[13][1][2]*wk[18][2])+((ik[13][1][0]*wk[18][0])+(
      ik[13][1][1]*wk[18][1])));
    hnk[13][2] = ((ik[13][2][2]*wk[18][2])+((ik[13][2][0]*wk[18][0])+(
      ik[13][2][1]*wk[18][1])));
    hnk[14][0] = ((ik[14][0][2]*wk[19][2])+((ik[14][0][0]*wk[19][0])+(
      ik[14][0][1]*wk[19][1])));
    hnk[14][1] = ((ik[14][1][2]*wk[19][2])+((ik[14][1][0]*wk[19][0])+(
      ik[14][1][1]*wk[19][1])));
    hnk[14][2] = ((ik[14][2][2]*wk[19][2])+((ik[14][2][0]*wk[19][0])+(
      ik[14][2][1]*wk[19][1])));
    hnk[15][0] = ((ik[15][0][2]*wk[20][2])+((ik[15][0][0]*wk[20][0])+(
      ik[15][0][1]*wk[20][1])));
    hnk[15][1] = ((ik[15][1][2]*wk[20][2])+((ik[15][1][0]*wk[20][0])+(
      ik[15][1][1]*wk[20][1])));
    hnk[15][2] = ((ik[15][2][2]*wk[20][2])+((ik[15][2][0]*wk[20][0])+(
      ik[15][2][1]*wk[20][1])));
    hnk[16][0] = ((ik[16][0][2]*wk[21][2])+((ik[16][0][0]*wk[21][0])+(
      ik[16][0][1]*wk[21][1])));
    hnk[16][1] = ((ik[16][1][2]*wk[21][2])+((ik[16][1][0]*wk[21][0])+(
      ik[16][1][1]*wk[21][1])));
    hnk[16][2] = ((ik[16][2][2]*wk[21][2])+((ik[16][2][0]*wk[21][0])+(
      ik[16][2][1]*wk[21][1])));
    hnk[17][0] = ((ik[17][0][2]*wk[22][2])+((ik[17][0][0]*wk[22][0])+(
      ik[17][0][1]*wk[22][1])));
    hnk[17][1] = ((ik[17][1][2]*wk[22][2])+((ik[17][1][0]*wk[22][0])+(
      ik[17][1][1]*wk[22][1])));
    hnk[17][2] = ((ik[17][2][2]*wk[22][2])+((ik[17][2][0]*wk[22][0])+(
      ik[17][2][1]*wk[22][1])));
    hnk[18][0] = ((ik[18][0][2]*wk[23][2])+((ik[18][0][0]*wk[23][0])+(
      ik[18][0][1]*wk[23][1])));
    hnk[18][1] = ((ik[18][1][2]*wk[23][2])+((ik[18][1][0]*wk[23][0])+(
      ik[18][1][1]*wk[23][1])));
    hnk[18][2] = ((ik[18][2][2]*wk[23][2])+((ik[18][2][0]*wk[23][0])+(
      ik[18][2][1]*wk[23][1])));
    hnk[19][0] = ((ik[19][0][2]*wk[24][2])+((ik[19][0][0]*wk[24][0])+(
      ik[19][0][1]*wk[24][1])));
    hnk[19][1] = ((ik[19][1][2]*wk[24][2])+((ik[19][1][0]*wk[24][0])+(
      ik[19][1][1]*wk[24][1])));
    hnk[19][2] = ((ik[19][2][2]*wk[24][2])+((ik[19][2][0]*wk[24][0])+(
      ik[19][2][1]*wk[24][1])));
    hnk[20][0] = ((ik[20][0][2]*wk[25][2])+((ik[20][0][0]*wk[25][0])+(
      ik[20][0][1]*wk[25][1])));
    hnk[20][1] = ((ik[20][1][2]*wk[25][2])+((ik[20][1][0]*wk[25][0])+(
      ik[20][1][1]*wk[25][1])));
    hnk[20][2] = ((ik[20][2][2]*wk[25][2])+((ik[20][2][0]*wk[25][0])+(
      ik[20][2][1]*wk[25][1])));
    lm[0] = (lk[20][0]+(lk[19][0]+(lk[18][0]+(lk[17][0]+(lk[16][0]+(lk[15][0]+(
      lk[14][0]+(lk[13][0]+(lk[12][0]+(lk[11][0]+(lk[10][0]+(lk[9][0]+(lk[8][0]+
      (lk[7][0]+(lk[6][0]+(lk[5][0]+(lk[4][0]+(lk[3][0]+(lk[2][0]+(lk[0][0]+
      lk[1][0]))))))))))))))))))));
    lm[1] = (lk[20][1]+(lk[19][1]+(lk[18][1]+(lk[17][1]+(lk[16][1]+(lk[15][1]+(
      lk[14][1]+(lk[13][1]+(lk[12][1]+(lk[11][1]+(lk[10][1]+(lk[9][1]+(lk[8][1]+
      (lk[7][1]+(lk[6][1]+(lk[5][1]+(lk[4][1]+(lk[3][1]+(lk[2][1]+(lk[0][1]+
      lk[1][1]))))))))))))))))))));
    lm[2] = (lk[20][2]+(lk[19][2]+(lk[18][2]+(lk[17][2]+(lk[16][2]+(lk[15][2]+(
      lk[14][2]+(lk[13][2]+(lk[12][2]+(lk[11][2]+(lk[10][2]+(lk[9][2]+(lk[8][2]+
      (lk[7][2]+(lk[6][2]+(lk[5][2]+(lk[4][2]+(lk[3][2]+(lk[2][2]+(lk[0][2]+
      lk[1][2]))))))))))))))))))));
    temp[0] = ((((cnk[7][0][2]*hnk[2][2])+((cnk[6][0][1]*hnk[2][1])+(
      cnk[7][0][0]*hnk[2][0])))+((lk[2][2]*rnk[7][1])-(lk[2][1]*rnk[7][2])))+(((
      (Cik[3][0][2]*hnk[0][2])+((Cik[3][0][0]*hnk[0][0])+(Cik[3][0][1]*hnk[0][1]
      )))+((lk[0][2]*rnk[5][1])-(lk[0][1]*rnk[5][2])))+(((Cik[3][0][2]*hnk[1][2]
      )+((cnk[6][0][0]*hnk[1][0])+(cnk[6][0][1]*hnk[1][1])))+((lk[1][2]*
      rnk[6][1])-(lk[1][1]*rnk[6][2])))));
    temp[1] = ((((cnk[9][0][2]*hnk[4][2])+((cnk[8][0][1]*hnk[4][1])+(
      cnk[9][0][0]*hnk[4][0])))+((lk[4][2]*rnk[9][1])-(lk[4][1]*rnk[9][2])))+(((
      (cnk[8][0][2]*hnk[3][2])+((cnk[7][0][0]*hnk[3][0])+(cnk[8][0][1]*hnk[3][1]
      )))+((lk[3][2]*rnk[8][1])-(lk[3][1]*rnk[8][2])))+temp[0]));
    temp[2] = ((((cnk[11][0][2]*hnk[6][2])+((cnk[10][0][0]*hnk[6][0])+(
      cnk[11][0][1]*hnk[6][1])))+((lk[6][2]*rnk[11][1])-(lk[6][1]*rnk[11][2])))+
      ((((cnk[10][0][2]*hnk[5][2])+((cnk[8][0][1]*hnk[5][1])+(cnk[10][0][0]*
      hnk[5][0])))+((lk[5][2]*rnk[10][1])-(lk[5][1]*rnk[10][2])))+temp[1]));
    temp[3] = ((((cnk[13][0][2]*hnk[8][2])+((cnk[12][0][1]*hnk[8][1])+(
      cnk[13][0][0]*hnk[8][0])))+((lk[8][2]*rnk[13][1])-(lk[8][1]*rnk[13][2])))+
      ((((Cik[3][0][2]*hnk[7][2])+((cnk[12][0][0]*hnk[7][0])+(cnk[12][0][1]*
      hnk[7][1])))+((lk[7][2]*rnk[12][1])-(lk[7][1]*rnk[12][2])))+temp[2]));
    temp[4] = ((((cnk[15][0][2]*hnk[10][2])+((cnk[14][0][1]*hnk[10][1])+(
      cnk[15][0][0]*hnk[10][0])))+((lk[10][2]*rnk[15][1])-(lk[10][1]*rnk[15][2])
      ))+((((cnk[14][0][2]*hnk[9][2])+((cnk[13][0][0]*hnk[9][0])+(cnk[14][0][1]*
      hnk[9][1])))+((lk[9][2]*rnk[14][1])-(lk[9][1]*rnk[14][2])))+temp[3]));
    temp[5] = ((((cnk[17][0][2]*hnk[12][2])+((cnk[16][0][0]*hnk[12][0])+(
      cnk[17][0][1]*hnk[12][1])))+((lk[12][2]*rnk[17][1])-(lk[12][1]*rnk[17][2])
      ))+((((cnk[16][0][2]*hnk[11][2])+((cnk[14][0][1]*hnk[11][1])+(
      cnk[16][0][0]*hnk[11][0])))+((lk[11][2]*rnk[16][1])-(lk[11][1]*rnk[16][2])
      ))+temp[4]));
    temp[6] = ((((cnk[19][0][2]*hnk[14][2])+((cnk[18][0][0]*hnk[14][0])+(
      cnk[19][0][1]*hnk[14][1])))+((lk[14][2]*rnk[19][1])-(lk[14][1]*rnk[19][2])
      ))+((((cnk[18][0][2]*hnk[13][2])+((Cik[3][0][1]*hnk[13][1])+(cnk[18][0][0]
      *hnk[13][0])))+((lk[13][2]*rnk[18][1])-(lk[13][1]*rnk[18][2])))+temp[5]));
    temp[7] = ((((cnk[20][0][2]*hnk[16][2])+((cnk[21][0][0]*hnk[16][0])+(
      cnk[21][0][1]*hnk[16][1])))+((lk[16][2]*rnk[21][1])-(lk[16][1]*rnk[21][2])
      ))+((((cnk[20][0][2]*hnk[15][2])+((cnk[19][0][1]*hnk[15][1])+(
      cnk[20][0][0]*hnk[15][0])))+((lk[15][2]*rnk[20][1])-(lk[15][1]*rnk[20][2])
      ))+temp[6]));
    temp[8] = ((((cnk[23][0][2]*hnk[18][2])+((cnk[22][0][0]*hnk[18][0])+(
      cnk[23][0][1]*hnk[18][1])))+((lk[18][2]*rnk[23][1])-(lk[18][1]*rnk[23][2])
      ))+((((cnk[22][0][2]*hnk[17][2])+((Cik[3][0][1]*hnk[17][1])+(cnk[22][0][0]
      *hnk[17][0])))+((lk[17][2]*rnk[22][1])-(lk[17][1]*rnk[22][2])))+temp[7]));
    am[0] = (((((cnk[24][0][2]*hnk[20][2])+((cnk[25][0][0]*hnk[20][0])+(
      cnk[25][0][1]*hnk[20][1])))+((lk[20][2]*rnk[25][1])-(lk[20][1]*rnk[25][2])
      ))+((((cnk[24][0][2]*hnk[19][2])+((cnk[23][0][1]*hnk[19][1])+(
      cnk[24][0][0]*hnk[19][0])))+((lk[19][2]*rnk[24][1])-(lk[19][1]*rnk[24][2])
      ))+temp[8]))-((com[1]*lm[2])-(com[2]*lm[1])));
    temp[0] = ((((cnk[7][1][2]*hnk[2][2])+((cnk[6][1][1]*hnk[2][1])+(
      cnk[7][1][0]*hnk[2][0])))+((lk[2][0]*rnk[7][2])-(lk[2][2]*rnk[7][0])))+(((
      (Cik[3][1][2]*hnk[0][2])+((Cik[3][1][0]*hnk[0][0])+(Cik[3][1][1]*hnk[0][1]
      )))+((lk[0][0]*rnk[5][2])-(lk[0][2]*rnk[5][0])))+(((Cik[3][1][2]*hnk[1][2]
      )+((cnk[6][1][0]*hnk[1][0])+(cnk[6][1][1]*hnk[1][1])))+((lk[1][0]*
      rnk[6][2])-(lk[1][2]*rnk[6][0])))));
    temp[1] = ((((cnk[9][1][2]*hnk[4][2])+((cnk[8][1][1]*hnk[4][1])+(
      cnk[9][1][0]*hnk[4][0])))+((lk[4][0]*rnk[9][2])-(lk[4][2]*rnk[9][0])))+(((
      (cnk[8][1][2]*hnk[3][2])+((cnk[7][1][0]*hnk[3][0])+(cnk[8][1][1]*hnk[3][1]
      )))+((lk[3][0]*rnk[8][2])-(lk[3][2]*rnk[8][0])))+temp[0]));
    temp[2] = ((((cnk[11][1][2]*hnk[6][2])+((cnk[10][1][0]*hnk[6][0])+(
      cnk[11][1][1]*hnk[6][1])))+((lk[6][0]*rnk[11][2])-(lk[6][2]*rnk[11][0])))+
      ((((cnk[10][1][2]*hnk[5][2])+((cnk[8][1][1]*hnk[5][1])+(cnk[10][1][0]*
      hnk[5][0])))+((lk[5][0]*rnk[10][2])-(lk[5][2]*rnk[10][0])))+temp[1]));
    temp[3] = ((((cnk[13][1][2]*hnk[8][2])+((cnk[12][1][1]*hnk[8][1])+(
      cnk[13][1][0]*hnk[8][0])))+((lk[8][0]*rnk[13][2])-(lk[8][2]*rnk[13][0])))+
      ((((Cik[3][1][2]*hnk[7][2])+((cnk[12][1][0]*hnk[7][0])+(cnk[12][1][1]*
      hnk[7][1])))+((lk[7][0]*rnk[12][2])-(lk[7][2]*rnk[12][0])))+temp[2]));
    temp[4] = ((((cnk[15][1][2]*hnk[10][2])+((cnk[14][1][1]*hnk[10][1])+(
      cnk[15][1][0]*hnk[10][0])))+((lk[10][0]*rnk[15][2])-(lk[10][2]*rnk[15][0])
      ))+((((cnk[14][1][2]*hnk[9][2])+((cnk[13][1][0]*hnk[9][0])+(cnk[14][1][1]*
      hnk[9][1])))+((lk[9][0]*rnk[14][2])-(lk[9][2]*rnk[14][0])))+temp[3]));
    temp[5] = ((((cnk[17][1][2]*hnk[12][2])+((cnk[16][1][0]*hnk[12][0])+(
      cnk[17][1][1]*hnk[12][1])))+((lk[12][0]*rnk[17][2])-(lk[12][2]*rnk[17][0])
      ))+((((cnk[16][1][2]*hnk[11][2])+((cnk[14][1][1]*hnk[11][1])+(
      cnk[16][1][0]*hnk[11][0])))+((lk[11][0]*rnk[16][2])-(lk[11][2]*rnk[16][0])
      ))+temp[4]));
    temp[6] = ((((cnk[19][1][2]*hnk[14][2])+((cnk[18][1][0]*hnk[14][0])+(
      cnk[19][1][1]*hnk[14][1])))+((lk[14][0]*rnk[19][2])-(lk[14][2]*rnk[19][0])
      ))+((((cnk[18][1][2]*hnk[13][2])+((Cik[3][1][1]*hnk[13][1])+(cnk[18][1][0]
      *hnk[13][0])))+((lk[13][0]*rnk[18][2])-(lk[13][2]*rnk[18][0])))+temp[5]));
    temp[7] = ((((cnk[20][1][2]*hnk[16][2])+((cnk[21][1][0]*hnk[16][0])+(
      cnk[21][1][1]*hnk[16][1])))+((lk[16][0]*rnk[21][2])-(lk[16][2]*rnk[21][0])
      ))+((((cnk[20][1][2]*hnk[15][2])+((cnk[19][1][1]*hnk[15][1])+(
      cnk[20][1][0]*hnk[15][0])))+((lk[15][0]*rnk[20][2])-(lk[15][2]*rnk[20][0])
      ))+temp[6]));
    temp[8] = ((((cnk[23][1][2]*hnk[18][2])+((cnk[22][1][0]*hnk[18][0])+(
      cnk[23][1][1]*hnk[18][1])))+((lk[18][0]*rnk[23][2])-(lk[18][2]*rnk[23][0])
      ))+((((cnk[22][1][2]*hnk[17][2])+((Cik[3][1][1]*hnk[17][1])+(cnk[22][1][0]
      *hnk[17][0])))+((lk[17][0]*rnk[22][2])-(lk[17][2]*rnk[22][0])))+temp[7]));
    am[1] = (((((cnk[24][1][2]*hnk[20][2])+((cnk[25][1][0]*hnk[20][0])+(
      cnk[25][1][1]*hnk[20][1])))+((lk[20][0]*rnk[25][2])-(lk[20][2]*rnk[25][0])
      ))+((((cnk[24][1][2]*hnk[19][2])+((cnk[23][1][1]*hnk[19][1])+(
      cnk[24][1][0]*hnk[19][0])))+((lk[19][0]*rnk[24][2])-(lk[19][2]*rnk[24][0])
      ))+temp[8]))-((com[2]*lm[0])-(com[0]*lm[2])));
    temp[0] = ((((cnk[7][2][2]*hnk[2][2])+((cnk[6][2][1]*hnk[2][1])+(
      cnk[7][2][0]*hnk[2][0])))+((lk[2][1]*rnk[7][0])-(lk[2][0]*rnk[7][1])))+(((
      (Cik[3][2][2]*hnk[0][2])+((Cik[3][2][0]*hnk[0][0])+(Cik[3][2][1]*hnk[0][1]
      )))+((lk[0][1]*rnk[5][0])-(lk[0][0]*rnk[5][1])))+(((Cik[3][2][2]*hnk[1][2]
      )+((cnk[6][2][0]*hnk[1][0])+(cnk[6][2][1]*hnk[1][1])))+((lk[1][1]*
      rnk[6][0])-(lk[1][0]*rnk[6][1])))));
    temp[1] = ((((cnk[9][2][2]*hnk[4][2])+((cnk[8][2][1]*hnk[4][1])+(
      cnk[9][2][0]*hnk[4][0])))+((lk[4][1]*rnk[9][0])-(lk[4][0]*rnk[9][1])))+(((
      (cnk[8][2][2]*hnk[3][2])+((cnk[7][2][0]*hnk[3][0])+(cnk[8][2][1]*hnk[3][1]
      )))+((lk[3][1]*rnk[8][0])-(lk[3][0]*rnk[8][1])))+temp[0]));
    temp[2] = ((((cnk[11][2][2]*hnk[6][2])+((cnk[10][2][0]*hnk[6][0])+(
      cnk[11][2][1]*hnk[6][1])))+((lk[6][1]*rnk[11][0])-(lk[6][0]*rnk[11][1])))+
      ((((cnk[10][2][2]*hnk[5][2])+((cnk[8][2][1]*hnk[5][1])+(cnk[10][2][0]*
      hnk[5][0])))+((lk[5][1]*rnk[10][0])-(lk[5][0]*rnk[10][1])))+temp[1]));
    temp[3] = ((((cnk[13][2][2]*hnk[8][2])+((cnk[12][2][1]*hnk[8][1])+(
      cnk[13][2][0]*hnk[8][0])))+((lk[8][1]*rnk[13][0])-(lk[8][0]*rnk[13][1])))+
      ((((Cik[3][2][2]*hnk[7][2])+((cnk[12][2][0]*hnk[7][0])+(cnk[12][2][1]*
      hnk[7][1])))+((lk[7][1]*rnk[12][0])-(lk[7][0]*rnk[12][1])))+temp[2]));
    temp[4] = ((((cnk[15][2][2]*hnk[10][2])+((cnk[14][2][1]*hnk[10][1])+(
      cnk[15][2][0]*hnk[10][0])))+((lk[10][1]*rnk[15][0])-(lk[10][0]*rnk[15][1])
      ))+((((cnk[14][2][2]*hnk[9][2])+((cnk[13][2][0]*hnk[9][0])+(cnk[14][2][1]*
      hnk[9][1])))+((lk[9][1]*rnk[14][0])-(lk[9][0]*rnk[14][1])))+temp[3]));
    temp[5] = ((((cnk[17][2][2]*hnk[12][2])+((cnk[16][2][0]*hnk[12][0])+(
      cnk[17][2][1]*hnk[12][1])))+((lk[12][1]*rnk[17][0])-(lk[12][0]*rnk[17][1])
      ))+((((cnk[16][2][2]*hnk[11][2])+((cnk[14][2][1]*hnk[11][1])+(
      cnk[16][2][0]*hnk[11][0])))+((lk[11][1]*rnk[16][0])-(lk[11][0]*rnk[16][1])
      ))+temp[4]));
    temp[6] = ((((cnk[19][2][2]*hnk[14][2])+((cnk[18][2][0]*hnk[14][0])+(
      cnk[19][2][1]*hnk[14][1])))+((lk[14][1]*rnk[19][0])-(lk[14][0]*rnk[19][1])
      ))+((((cnk[18][2][2]*hnk[13][2])+((Cik[3][2][1]*hnk[13][1])+(cnk[18][2][0]
      *hnk[13][0])))+((lk[13][1]*rnk[18][0])-(lk[13][0]*rnk[18][1])))+temp[5]));
    temp[7] = ((((cnk[20][2][2]*hnk[16][2])+((cnk[21][2][0]*hnk[16][0])+(
      cnk[21][2][1]*hnk[16][1])))+((lk[16][1]*rnk[21][0])-(lk[16][0]*rnk[21][1])
      ))+((((cnk[20][2][2]*hnk[15][2])+((cnk[19][2][1]*hnk[15][1])+(
      cnk[20][2][0]*hnk[15][0])))+((lk[15][1]*rnk[20][0])-(lk[15][0]*rnk[20][1])
      ))+temp[6]));
    temp[8] = ((((cnk[23][2][2]*hnk[18][2])+((cnk[22][2][0]*hnk[18][0])+(
      cnk[23][2][1]*hnk[18][1])))+((lk[18][1]*rnk[23][0])-(lk[18][0]*rnk[23][1])
      ))+((((cnk[22][2][2]*hnk[17][2])+((Cik[3][2][1]*hnk[17][1])+(cnk[22][2][0]
      *hnk[17][0])))+((lk[17][1]*rnk[22][0])-(lk[17][0]*rnk[22][1])))+temp[7]));
    am[2] = (((((cnk[24][2][2]*hnk[20][2])+((cnk[25][2][0]*hnk[20][0])+(
      cnk[25][2][1]*hnk[20][1])))+((lk[20][1]*rnk[25][0])-(lk[20][0]*rnk[25][1])
      ))+((((cnk[24][2][2]*hnk[19][2])+((cnk[23][2][1]*hnk[19][1])+(
      cnk[24][2][0]*hnk[19][0])))+((lk[19][1]*rnk[24][0])-(lk[19][0]*rnk[24][1])
      ))+temp[8]))-((com[0]*lm[1])-(com[1]*lm[0])));
    temp[0] = ((((hnk[0][2]*u[5])+((hnk[0][0]*u[3])+(hnk[0][1]*u[4])))+((
      lk[0][2]*vnk[5][2])+((lk[0][0]*vnk[5][0])+(lk[0][1]*vnk[5][1]))))+(((
      hnk[1][2]*wk[6][2])+((hnk[1][0]*wk[6][0])+(hnk[1][1]*wk[6][1])))+((
      lk[1][2]*vnk[6][2])+((lk[1][0]*vnk[6][0])+(lk[1][1]*vnk[6][1])))));
    temp[1] = ((((hnk[3][2]*wk[8][2])+((hnk[3][0]*wk[8][0])+(hnk[3][1]*wk[8][1])
      ))+((lk[3][2]*vnk[8][2])+((lk[3][0]*vnk[8][0])+(lk[3][1]*vnk[8][1]))))+(((
      (hnk[2][2]*wk[7][2])+((hnk[2][0]*wk[7][0])+(hnk[2][1]*wk[7][1])))+((
      lk[2][2]*vnk[7][2])+((lk[2][0]*vnk[7][0])+(lk[2][1]*vnk[7][1]))))+temp[0])
      );
    temp[2] = ((((hnk[5][2]*wk[10][2])+((hnk[5][0]*wk[10][0])+(hnk[5][1]*
      wk[10][1])))+((lk[5][2]*vnk[10][2])+((lk[5][0]*vnk[10][0])+(lk[5][1]*
      vnk[10][1]))))+((((hnk[4][2]*wk[9][2])+((hnk[4][0]*wk[9][0])+(hnk[4][1]*
      wk[9][1])))+((lk[4][2]*vnk[9][2])+((lk[4][0]*vnk[9][0])+(lk[4][1]*
      vnk[9][1]))))+temp[1]));
    temp[3] = ((((hnk[7][2]*wk[12][2])+((hnk[7][0]*wk[12][0])+(hnk[7][1]*
      wk[12][1])))+((lk[7][2]*vnk[12][2])+((lk[7][0]*vnk[12][0])+(lk[7][1]*
      vnk[12][1]))))+((((hnk[6][2]*wk[11][2])+((hnk[6][0]*wk[11][0])+(hnk[6][1]*
      wk[11][1])))+((lk[6][2]*vnk[11][2])+((lk[6][0]*vnk[11][0])+(lk[6][1]*
      vnk[11][1]))))+temp[2]));
    temp[4] = ((((hnk[9][2]*wk[14][2])+((hnk[9][0]*wk[14][0])+(hnk[9][1]*
      wk[14][1])))+((lk[9][2]*vnk[14][2])+((lk[9][0]*vnk[14][0])+(lk[9][1]*
      vnk[14][1]))))+((((hnk[8][2]*wk[13][2])+((hnk[8][0]*wk[13][0])+(hnk[8][1]*
      wk[13][1])))+((lk[8][2]*vnk[13][2])+((lk[8][0]*vnk[13][0])+(lk[8][1]*
      vnk[13][1]))))+temp[3]));
    temp[5] = ((((hnk[11][2]*wk[16][2])+((hnk[11][0]*wk[16][0])+(hnk[11][1]*
      wk[16][1])))+((lk[11][2]*vnk[16][2])+((lk[11][0]*vnk[16][0])+(lk[11][1]*
      vnk[16][1]))))+((((hnk[10][2]*wk[15][2])+((hnk[10][0]*wk[15][0])+(
      hnk[10][1]*wk[15][1])))+((lk[10][2]*vnk[15][2])+((lk[10][0]*vnk[15][0])+(
      lk[10][1]*vnk[15][1]))))+temp[4]));
    temp[6] = ((((hnk[13][2]*wk[18][2])+((hnk[13][0]*wk[18][0])+(hnk[13][1]*
      wk[18][1])))+((lk[13][2]*vnk[18][2])+((lk[13][0]*vnk[18][0])+(lk[13][1]*
      vnk[18][1]))))+((((hnk[12][2]*wk[17][2])+((hnk[12][0]*wk[17][0])+(
      hnk[12][1]*wk[17][1])))+((lk[12][2]*vnk[17][2])+((lk[12][0]*vnk[17][0])+(
      lk[12][1]*vnk[17][1]))))+temp[5]));
    temp[7] = ((((hnk[15][2]*wk[20][2])+((hnk[15][0]*wk[20][0])+(hnk[15][1]*
      wk[20][1])))+((lk[15][2]*vnk[20][2])+((lk[15][0]*vnk[20][0])+(lk[15][1]*
      vnk[20][1]))))+((((hnk[14][2]*wk[19][2])+((hnk[14][0]*wk[19][0])+(
      hnk[14][1]*wk[19][1])))+((lk[14][2]*vnk[19][2])+((lk[14][0]*vnk[19][0])+(
      lk[14][1]*vnk[19][1]))))+temp[6]));
    temp[8] = ((((hnk[17][2]*wk[22][2])+((hnk[17][0]*wk[22][0])+(hnk[17][1]*
      wk[22][1])))+((lk[17][2]*vnk[22][2])+((lk[17][0]*vnk[22][0])+(lk[17][1]*
      vnk[22][1]))))+((((hnk[16][2]*wk[21][2])+((hnk[16][0]*wk[21][0])+(
      hnk[16][1]*wk[21][1])))+((lk[16][2]*vnk[21][2])+((lk[16][0]*vnk[21][0])+(
      lk[16][1]*vnk[21][1]))))+temp[7]));
    temp[9] = ((((hnk[19][2]*wk[24][2])+((hnk[19][0]*wk[24][0])+(hnk[19][1]*
      wk[24][1])))+((lk[19][2]*vnk[24][2])+((lk[19][0]*vnk[24][0])+(lk[19][1]*
      vnk[24][1]))))+((((hnk[18][2]*wk[23][2])+((hnk[18][0]*wk[23][0])+(
      hnk[18][1]*wk[23][1])))+((lk[18][2]*vnk[23][2])+((lk[18][0]*vnk[23][0])+(
      lk[18][1]*vnk[23][1]))))+temp[8]));
    *ke = (.5*((((hnk[20][2]*wk[25][2])+((hnk[20][0]*wk[25][0])+(hnk[20][1]*
      wk[25][1])))+((lk[20][2]*vnk[25][2])+((lk[20][0]*vnk[25][0])+(lk[20][1]*
      vnk[25][1]))))+temp[9]));
/*
 Used 0.01 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  629 adds/subtracts/negates
                    700 multiplies
                      0 divides
                    170 assignments
*/
}

void Jimmy::sdsys(double *mtoto,
    double cm[3],
    double icm[3][3])
{
/*
Compute system total mass, and instantaneous center of mass and
inertia matrix.

Generated 27-Jan-2007 11:40:25 by SD/FAST, Kane's formulation
(sdfast B.2.8 #30123) on machine ID unknown
Copyright (c) 1990-1997 Symbolic Dynamics, Inc.
Copyright (c) 1990-1997 Parametric Technology Corp.
RESTRICTED RIGHTS LEGEND: Use, duplication, or disclosure by the U.S.
Government is subject to restrictions as set forth in subparagraph
(c)(1)(ii) of the Rights in Technical Data and Computer Software
clause at DFARS 52.227-7013 and similar clauses in the FAR and NASA
FAR Supplement.  Symbolic Dynamics, Inc., Mountain View, CA 94041
*/
    double ikcnkt[26][3][3];

    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(20,23);
        return;
    }
    *mtoto = mtot;
    cm[0] = com[0];
    cm[1] = com[1];
    cm[2] = com[2];
    ikcnkt[5][0][0] = ((Cik[3][0][2]*ik[0][0][2])+((Cik[3][0][0]*ik[0][0][0])+(
      Cik[3][0][1]*ik[0][0][1])));
    ikcnkt[5][0][1] = ((Cik[3][1][2]*ik[0][0][2])+((Cik[3][1][0]*ik[0][0][0])+(
      Cik[3][1][1]*ik[0][0][1])));
    ikcnkt[5][0][2] = ((Cik[3][2][2]*ik[0][0][2])+((Cik[3][2][0]*ik[0][0][0])+(
      Cik[3][2][1]*ik[0][0][1])));
    ikcnkt[5][1][0] = ((Cik[3][0][2]*ik[0][1][2])+((Cik[3][0][0]*ik[0][1][0])+(
      Cik[3][0][1]*ik[0][1][1])));
    ikcnkt[5][1][1] = ((Cik[3][1][2]*ik[0][1][2])+((Cik[3][1][0]*ik[0][1][0])+(
      Cik[3][1][1]*ik[0][1][1])));
    ikcnkt[5][1][2] = ((Cik[3][2][2]*ik[0][1][2])+((Cik[3][2][0]*ik[0][1][0])+(
      Cik[3][2][1]*ik[0][1][1])));
    ikcnkt[5][2][0] = ((Cik[3][0][2]*ik[0][2][2])+((Cik[3][0][0]*ik[0][2][0])+(
      Cik[3][0][1]*ik[0][2][1])));
    ikcnkt[5][2][1] = ((Cik[3][1][2]*ik[0][2][2])+((Cik[3][1][0]*ik[0][2][0])+(
      Cik[3][1][1]*ik[0][2][1])));
    ikcnkt[5][2][2] = ((Cik[3][2][2]*ik[0][2][2])+((Cik[3][2][0]*ik[0][2][0])+(
      Cik[3][2][1]*ik[0][2][1])));
    ikcnkt[6][0][0] = ((Cik[3][0][2]*ik[1][0][2])+((cnk[6][0][0]*ik[1][0][0])+(
      cnk[6][0][1]*ik[1][0][1])));
    ikcnkt[6][0][1] = ((Cik[3][1][2]*ik[1][0][2])+((cnk[6][1][0]*ik[1][0][0])+(
      cnk[6][1][1]*ik[1][0][1])));
    ikcnkt[6][0][2] = ((Cik[3][2][2]*ik[1][0][2])+((cnk[6][2][0]*ik[1][0][0])+(
      cnk[6][2][1]*ik[1][0][1])));
    ikcnkt[6][1][0] = ((Cik[3][0][2]*ik[1][1][2])+((cnk[6][0][0]*ik[1][1][0])+(
      cnk[6][0][1]*ik[1][1][1])));
    ikcnkt[6][1][1] = ((Cik[3][1][2]*ik[1][1][2])+((cnk[6][1][0]*ik[1][1][0])+(
      cnk[6][1][1]*ik[1][1][1])));
    ikcnkt[6][1][2] = ((Cik[3][2][2]*ik[1][1][2])+((cnk[6][2][0]*ik[1][1][0])+(
      cnk[6][2][1]*ik[1][1][1])));
    ikcnkt[6][2][0] = ((Cik[3][0][2]*ik[1][2][2])+((cnk[6][0][0]*ik[1][2][0])+(
      cnk[6][0][1]*ik[1][2][1])));
    ikcnkt[6][2][1] = ((Cik[3][1][2]*ik[1][2][2])+((cnk[6][1][0]*ik[1][2][0])+(
      cnk[6][1][1]*ik[1][2][1])));
    ikcnkt[6][2][2] = ((Cik[3][2][2]*ik[1][2][2])+((cnk[6][2][0]*ik[1][2][0])+(
      cnk[6][2][1]*ik[1][2][1])));
    ikcnkt[7][0][0] = ((cnk[7][0][2]*ik[2][0][2])+((cnk[6][0][1]*ik[2][0][1])+(
      cnk[7][0][0]*ik[2][0][0])));
    ikcnkt[7][0][1] = ((cnk[7][1][2]*ik[2][0][2])+((cnk[6][1][1]*ik[2][0][1])+(
      cnk[7][1][0]*ik[2][0][0])));
    ikcnkt[7][0][2] = ((cnk[7][2][2]*ik[2][0][2])+((cnk[6][2][1]*ik[2][0][1])+(
      cnk[7][2][0]*ik[2][0][0])));
    ikcnkt[7][1][0] = ((cnk[7][0][2]*ik[2][1][2])+((cnk[6][0][1]*ik[2][1][1])+(
      cnk[7][0][0]*ik[2][1][0])));
    ikcnkt[7][1][1] = ((cnk[7][1][2]*ik[2][1][2])+((cnk[6][1][1]*ik[2][1][1])+(
      cnk[7][1][0]*ik[2][1][0])));
    ikcnkt[7][1][2] = ((cnk[7][2][2]*ik[2][1][2])+((cnk[6][2][1]*ik[2][1][1])+(
      cnk[7][2][0]*ik[2][1][0])));
    ikcnkt[7][2][0] = ((cnk[7][0][2]*ik[2][2][2])+((cnk[6][0][1]*ik[2][2][1])+(
      cnk[7][0][0]*ik[2][2][0])));
    ikcnkt[7][2][1] = ((cnk[7][1][2]*ik[2][2][2])+((cnk[6][1][1]*ik[2][2][1])+(
      cnk[7][1][0]*ik[2][2][0])));
    ikcnkt[7][2][2] = ((cnk[7][2][2]*ik[2][2][2])+((cnk[6][2][1]*ik[2][2][1])+(
      cnk[7][2][0]*ik[2][2][0])));
    ikcnkt[8][0][0] = ((cnk[8][0][2]*ik[3][0][2])+((cnk[7][0][0]*ik[3][0][0])+(
      cnk[8][0][1]*ik[3][0][1])));
    ikcnkt[8][0][1] = ((cnk[8][1][2]*ik[3][0][2])+((cnk[7][1][0]*ik[3][0][0])+(
      cnk[8][1][1]*ik[3][0][1])));
    ikcnkt[8][0][2] = ((cnk[8][2][2]*ik[3][0][2])+((cnk[7][2][0]*ik[3][0][0])+(
      cnk[8][2][1]*ik[3][0][1])));
    ikcnkt[8][1][0] = ((cnk[8][0][2]*ik[3][1][2])+((cnk[7][0][0]*ik[3][1][0])+(
      cnk[8][0][1]*ik[3][1][1])));
    ikcnkt[8][1][1] = ((cnk[8][1][2]*ik[3][1][2])+((cnk[7][1][0]*ik[3][1][0])+(
      cnk[8][1][1]*ik[3][1][1])));
    ikcnkt[8][1][2] = ((cnk[8][2][2]*ik[3][1][2])+((cnk[7][2][0]*ik[3][1][0])+(
      cnk[8][2][1]*ik[3][1][1])));
    ikcnkt[8][2][0] = ((cnk[8][0][2]*ik[3][2][2])+((cnk[7][0][0]*ik[3][2][0])+(
      cnk[8][0][1]*ik[3][2][1])));
    ikcnkt[8][2][1] = ((cnk[8][1][2]*ik[3][2][2])+((cnk[7][1][0]*ik[3][2][0])+(
      cnk[8][1][1]*ik[3][2][1])));
    ikcnkt[8][2][2] = ((cnk[8][2][2]*ik[3][2][2])+((cnk[7][2][0]*ik[3][2][0])+(
      cnk[8][2][1]*ik[3][2][1])));
    ikcnkt[9][0][0] = ((cnk[9][0][2]*ik[4][0][2])+((cnk[8][0][1]*ik[4][0][1])+(
      cnk[9][0][0]*ik[4][0][0])));
    ikcnkt[9][0][1] = ((cnk[9][1][2]*ik[4][0][2])+((cnk[8][1][1]*ik[4][0][1])+(
      cnk[9][1][0]*ik[4][0][0])));
    ikcnkt[9][0][2] = ((cnk[9][2][2]*ik[4][0][2])+((cnk[8][2][1]*ik[4][0][1])+(
      cnk[9][2][0]*ik[4][0][0])));
    ikcnkt[9][1][0] = ((cnk[9][0][2]*ik[4][1][2])+((cnk[8][0][1]*ik[4][1][1])+(
      cnk[9][0][0]*ik[4][1][0])));
    ikcnkt[9][1][1] = ((cnk[9][1][2]*ik[4][1][2])+((cnk[8][1][1]*ik[4][1][1])+(
      cnk[9][1][0]*ik[4][1][0])));
    ikcnkt[9][1][2] = ((cnk[9][2][2]*ik[4][1][2])+((cnk[8][2][1]*ik[4][1][1])+(
      cnk[9][2][0]*ik[4][1][0])));
    ikcnkt[9][2][0] = ((cnk[9][0][2]*ik[4][2][2])+((cnk[8][0][1]*ik[4][2][1])+(
      cnk[9][0][0]*ik[4][2][0])));
    ikcnkt[9][2][1] = ((cnk[9][1][2]*ik[4][2][2])+((cnk[8][1][1]*ik[4][2][1])+(
      cnk[9][1][0]*ik[4][2][0])));
    ikcnkt[9][2][2] = ((cnk[9][2][2]*ik[4][2][2])+((cnk[8][2][1]*ik[4][2][1])+(
      cnk[9][2][0]*ik[4][2][0])));
    ikcnkt[10][0][0] = ((cnk[10][0][2]*ik[5][0][2])+((cnk[8][0][1]*ik[5][0][1])+
      (cnk[10][0][0]*ik[5][0][0])));
    ikcnkt[10][0][1] = ((cnk[10][1][2]*ik[5][0][2])+((cnk[8][1][1]*ik[5][0][1])+
      (cnk[10][1][0]*ik[5][0][0])));
    ikcnkt[10][0][2] = ((cnk[10][2][2]*ik[5][0][2])+((cnk[8][2][1]*ik[5][0][1])+
      (cnk[10][2][0]*ik[5][0][0])));
    ikcnkt[10][1][0] = ((cnk[10][0][2]*ik[5][1][2])+((cnk[8][0][1]*ik[5][1][1])+
      (cnk[10][0][0]*ik[5][1][0])));
    ikcnkt[10][1][1] = ((cnk[10][1][2]*ik[5][1][2])+((cnk[8][1][1]*ik[5][1][1])+
      (cnk[10][1][0]*ik[5][1][0])));
    ikcnkt[10][1][2] = ((cnk[10][2][2]*ik[5][1][2])+((cnk[8][2][1]*ik[5][1][1])+
      (cnk[10][2][0]*ik[5][1][0])));
    ikcnkt[10][2][0] = ((cnk[10][0][2]*ik[5][2][2])+((cnk[8][0][1]*ik[5][2][1])+
      (cnk[10][0][0]*ik[5][2][0])));
    ikcnkt[10][2][1] = ((cnk[10][1][2]*ik[5][2][2])+((cnk[8][1][1]*ik[5][2][1])+
      (cnk[10][1][0]*ik[5][2][0])));
    ikcnkt[10][2][2] = ((cnk[10][2][2]*ik[5][2][2])+((cnk[8][2][1]*ik[5][2][1])+
      (cnk[10][2][0]*ik[5][2][0])));
    ikcnkt[11][0][0] = ((cnk[11][0][2]*ik[6][0][2])+((cnk[10][0][0]*ik[6][0][0])
      +(cnk[11][0][1]*ik[6][0][1])));
    ikcnkt[11][0][1] = ((cnk[11][1][2]*ik[6][0][2])+((cnk[10][1][0]*ik[6][0][0])
      +(cnk[11][1][1]*ik[6][0][1])));
    ikcnkt[11][0][2] = ((cnk[11][2][2]*ik[6][0][2])+((cnk[10][2][0]*ik[6][0][0])
      +(cnk[11][2][1]*ik[6][0][1])));
    ikcnkt[11][1][0] = ((cnk[11][0][2]*ik[6][1][2])+((cnk[10][0][0]*ik[6][1][0])
      +(cnk[11][0][1]*ik[6][1][1])));
    ikcnkt[11][1][1] = ((cnk[11][1][2]*ik[6][1][2])+((cnk[10][1][0]*ik[6][1][0])
      +(cnk[11][1][1]*ik[6][1][1])));
    ikcnkt[11][1][2] = ((cnk[11][2][2]*ik[6][1][2])+((cnk[10][2][0]*ik[6][1][0])
      +(cnk[11][2][1]*ik[6][1][1])));
    ikcnkt[11][2][0] = ((cnk[11][0][2]*ik[6][2][2])+((cnk[10][0][0]*ik[6][2][0])
      +(cnk[11][0][1]*ik[6][2][1])));
    ikcnkt[11][2][1] = ((cnk[11][1][2]*ik[6][2][2])+((cnk[10][1][0]*ik[6][2][0])
      +(cnk[11][1][1]*ik[6][2][1])));
    ikcnkt[11][2][2] = ((cnk[11][2][2]*ik[6][2][2])+((cnk[10][2][0]*ik[6][2][0])
      +(cnk[11][2][1]*ik[6][2][1])));
    ikcnkt[12][0][0] = ((Cik[3][0][2]*ik[7][0][2])+((cnk[12][0][0]*ik[7][0][0])+
      (cnk[12][0][1]*ik[7][0][1])));
    ikcnkt[12][0][1] = ((Cik[3][1][2]*ik[7][0][2])+((cnk[12][1][0]*ik[7][0][0])+
      (cnk[12][1][1]*ik[7][0][1])));
    ikcnkt[12][0][2] = ((Cik[3][2][2]*ik[7][0][2])+((cnk[12][2][0]*ik[7][0][0])+
      (cnk[12][2][1]*ik[7][0][1])));
    ikcnkt[12][1][0] = ((Cik[3][0][2]*ik[7][1][2])+((cnk[12][0][0]*ik[7][1][0])+
      (cnk[12][0][1]*ik[7][1][1])));
    ikcnkt[12][1][1] = ((Cik[3][1][2]*ik[7][1][2])+((cnk[12][1][0]*ik[7][1][0])+
      (cnk[12][1][1]*ik[7][1][1])));
    ikcnkt[12][1][2] = ((Cik[3][2][2]*ik[7][1][2])+((cnk[12][2][0]*ik[7][1][0])+
      (cnk[12][2][1]*ik[7][1][1])));
    ikcnkt[12][2][0] = ((Cik[3][0][2]*ik[7][2][2])+((cnk[12][0][0]*ik[7][2][0])+
      (cnk[12][0][1]*ik[7][2][1])));
    ikcnkt[12][2][1] = ((Cik[3][1][2]*ik[7][2][2])+((cnk[12][1][0]*ik[7][2][0])+
      (cnk[12][1][1]*ik[7][2][1])));
    ikcnkt[12][2][2] = ((Cik[3][2][2]*ik[7][2][2])+((cnk[12][2][0]*ik[7][2][0])+
      (cnk[12][2][1]*ik[7][2][1])));
    ikcnkt[13][0][0] = ((cnk[13][0][2]*ik[8][0][2])+((cnk[12][0][1]*ik[8][0][1])
      +(cnk[13][0][0]*ik[8][0][0])));
    ikcnkt[13][0][1] = ((cnk[13][1][2]*ik[8][0][2])+((cnk[12][1][1]*ik[8][0][1])
      +(cnk[13][1][0]*ik[8][0][0])));
    ikcnkt[13][0][2] = ((cnk[13][2][2]*ik[8][0][2])+((cnk[12][2][1]*ik[8][0][1])
      +(cnk[13][2][0]*ik[8][0][0])));
    ikcnkt[13][1][0] = ((cnk[13][0][2]*ik[8][1][2])+((cnk[12][0][1]*ik[8][1][1])
      +(cnk[13][0][0]*ik[8][1][0])));
    ikcnkt[13][1][1] = ((cnk[13][1][2]*ik[8][1][2])+((cnk[12][1][1]*ik[8][1][1])
      +(cnk[13][1][0]*ik[8][1][0])));
    ikcnkt[13][1][2] = ((cnk[13][2][2]*ik[8][1][2])+((cnk[12][2][1]*ik[8][1][1])
      +(cnk[13][2][0]*ik[8][1][0])));
    ikcnkt[13][2][0] = ((cnk[13][0][2]*ik[8][2][2])+((cnk[12][0][1]*ik[8][2][1])
      +(cnk[13][0][0]*ik[8][2][0])));
    ikcnkt[13][2][1] = ((cnk[13][1][2]*ik[8][2][2])+((cnk[12][1][1]*ik[8][2][1])
      +(cnk[13][1][0]*ik[8][2][0])));
    ikcnkt[13][2][2] = ((cnk[13][2][2]*ik[8][2][2])+((cnk[12][2][1]*ik[8][2][1])
      +(cnk[13][2][0]*ik[8][2][0])));
    ikcnkt[14][0][0] = ((cnk[14][0][2]*ik[9][0][2])+((cnk[13][0][0]*ik[9][0][0])
      +(cnk[14][0][1]*ik[9][0][1])));
    ikcnkt[14][0][1] = ((cnk[14][1][2]*ik[9][0][2])+((cnk[13][1][0]*ik[9][0][0])
      +(cnk[14][1][1]*ik[9][0][1])));
    ikcnkt[14][0][2] = ((cnk[14][2][2]*ik[9][0][2])+((cnk[13][2][0]*ik[9][0][0])
      +(cnk[14][2][1]*ik[9][0][1])));
    ikcnkt[14][1][0] = ((cnk[14][0][2]*ik[9][1][2])+((cnk[13][0][0]*ik[9][1][0])
      +(cnk[14][0][1]*ik[9][1][1])));
    ikcnkt[14][1][1] = ((cnk[14][1][2]*ik[9][1][2])+((cnk[13][1][0]*ik[9][1][0])
      +(cnk[14][1][1]*ik[9][1][1])));
    ikcnkt[14][1][2] = ((cnk[14][2][2]*ik[9][1][2])+((cnk[13][2][0]*ik[9][1][0])
      +(cnk[14][2][1]*ik[9][1][1])));
    ikcnkt[14][2][0] = ((cnk[14][0][2]*ik[9][2][2])+((cnk[13][0][0]*ik[9][2][0])
      +(cnk[14][0][1]*ik[9][2][1])));
    ikcnkt[14][2][1] = ((cnk[14][1][2]*ik[9][2][2])+((cnk[13][1][0]*ik[9][2][0])
      +(cnk[14][1][1]*ik[9][2][1])));
    ikcnkt[14][2][2] = ((cnk[14][2][2]*ik[9][2][2])+((cnk[13][2][0]*ik[9][2][0])
      +(cnk[14][2][1]*ik[9][2][1])));
    ikcnkt[15][0][0] = ((cnk[15][0][2]*ik[10][0][2])+((cnk[14][0][1]*
      ik[10][0][1])+(cnk[15][0][0]*ik[10][0][0])));
    ikcnkt[15][0][1] = ((cnk[15][1][2]*ik[10][0][2])+((cnk[14][1][1]*
      ik[10][0][1])+(cnk[15][1][0]*ik[10][0][0])));
    ikcnkt[15][0][2] = ((cnk[15][2][2]*ik[10][0][2])+((cnk[14][2][1]*
      ik[10][0][1])+(cnk[15][2][0]*ik[10][0][0])));
    ikcnkt[15][1][0] = ((cnk[15][0][2]*ik[10][1][2])+((cnk[14][0][1]*
      ik[10][1][1])+(cnk[15][0][0]*ik[10][1][0])));
    ikcnkt[15][1][1] = ((cnk[15][1][2]*ik[10][1][2])+((cnk[14][1][1]*
      ik[10][1][1])+(cnk[15][1][0]*ik[10][1][0])));
    ikcnkt[15][1][2] = ((cnk[15][2][2]*ik[10][1][2])+((cnk[14][2][1]*
      ik[10][1][1])+(cnk[15][2][0]*ik[10][1][0])));
    ikcnkt[15][2][0] = ((cnk[15][0][2]*ik[10][2][2])+((cnk[14][0][1]*
      ik[10][2][1])+(cnk[15][0][0]*ik[10][2][0])));
    ikcnkt[15][2][1] = ((cnk[15][1][2]*ik[10][2][2])+((cnk[14][1][1]*
      ik[10][2][1])+(cnk[15][1][0]*ik[10][2][0])));
    ikcnkt[15][2][2] = ((cnk[15][2][2]*ik[10][2][2])+((cnk[14][2][1]*
      ik[10][2][1])+(cnk[15][2][0]*ik[10][2][0])));
    ikcnkt[16][0][0] = ((cnk[16][0][2]*ik[11][0][2])+((cnk[14][0][1]*
      ik[11][0][1])+(cnk[16][0][0]*ik[11][0][0])));
    ikcnkt[16][0][1] = ((cnk[16][1][2]*ik[11][0][2])+((cnk[14][1][1]*
      ik[11][0][1])+(cnk[16][1][0]*ik[11][0][0])));
    ikcnkt[16][0][2] = ((cnk[16][2][2]*ik[11][0][2])+((cnk[14][2][1]*
      ik[11][0][1])+(cnk[16][2][0]*ik[11][0][0])));
    ikcnkt[16][1][0] = ((cnk[16][0][2]*ik[11][1][2])+((cnk[14][0][1]*
      ik[11][1][1])+(cnk[16][0][0]*ik[11][1][0])));
    ikcnkt[16][1][1] = ((cnk[16][1][2]*ik[11][1][2])+((cnk[14][1][1]*
      ik[11][1][1])+(cnk[16][1][0]*ik[11][1][0])));
    ikcnkt[16][1][2] = ((cnk[16][2][2]*ik[11][1][2])+((cnk[14][2][1]*
      ik[11][1][1])+(cnk[16][2][0]*ik[11][1][0])));
    ikcnkt[16][2][0] = ((cnk[16][0][2]*ik[11][2][2])+((cnk[14][0][1]*
      ik[11][2][1])+(cnk[16][0][0]*ik[11][2][0])));
    ikcnkt[16][2][1] = ((cnk[16][1][2]*ik[11][2][2])+((cnk[14][1][1]*
      ik[11][2][1])+(cnk[16][1][0]*ik[11][2][0])));
    ikcnkt[16][2][2] = ((cnk[16][2][2]*ik[11][2][2])+((cnk[14][2][1]*
      ik[11][2][1])+(cnk[16][2][0]*ik[11][2][0])));
    ikcnkt[17][0][0] = ((cnk[17][0][2]*ik[12][0][2])+((cnk[16][0][0]*
      ik[12][0][0])+(cnk[17][0][1]*ik[12][0][1])));
    ikcnkt[17][0][1] = ((cnk[17][1][2]*ik[12][0][2])+((cnk[16][1][0]*
      ik[12][0][0])+(cnk[17][1][1]*ik[12][0][1])));
    ikcnkt[17][0][2] = ((cnk[17][2][2]*ik[12][0][2])+((cnk[16][2][0]*
      ik[12][0][0])+(cnk[17][2][1]*ik[12][0][1])));
    ikcnkt[17][1][0] = ((cnk[17][0][2]*ik[12][1][2])+((cnk[16][0][0]*
      ik[12][1][0])+(cnk[17][0][1]*ik[12][1][1])));
    ikcnkt[17][1][1] = ((cnk[17][1][2]*ik[12][1][2])+((cnk[16][1][0]*
      ik[12][1][0])+(cnk[17][1][1]*ik[12][1][1])));
    ikcnkt[17][1][2] = ((cnk[17][2][2]*ik[12][1][2])+((cnk[16][2][0]*
      ik[12][1][0])+(cnk[17][2][1]*ik[12][1][1])));
    ikcnkt[17][2][0] = ((cnk[17][0][2]*ik[12][2][2])+((cnk[16][0][0]*
      ik[12][2][0])+(cnk[17][0][1]*ik[12][2][1])));
    ikcnkt[17][2][1] = ((cnk[17][1][2]*ik[12][2][2])+((cnk[16][1][0]*
      ik[12][2][0])+(cnk[17][1][1]*ik[12][2][1])));
    ikcnkt[17][2][2] = ((cnk[17][2][2]*ik[12][2][2])+((cnk[16][2][0]*
      ik[12][2][0])+(cnk[17][2][1]*ik[12][2][1])));
    ikcnkt[18][0][0] = ((cnk[18][0][2]*ik[13][0][2])+((Cik[3][0][1]*ik[13][0][1]
      )+(cnk[18][0][0]*ik[13][0][0])));
    ikcnkt[18][0][1] = ((cnk[18][1][2]*ik[13][0][2])+((Cik[3][1][1]*ik[13][0][1]
      )+(cnk[18][1][0]*ik[13][0][0])));
    ikcnkt[18][0][2] = ((cnk[18][2][2]*ik[13][0][2])+((Cik[3][2][1]*ik[13][0][1]
      )+(cnk[18][2][0]*ik[13][0][0])));
    ikcnkt[18][1][0] = ((cnk[18][0][2]*ik[13][1][2])+((Cik[3][0][1]*ik[13][1][1]
      )+(cnk[18][0][0]*ik[13][1][0])));
    ikcnkt[18][1][1] = ((cnk[18][1][2]*ik[13][1][2])+((Cik[3][1][1]*ik[13][1][1]
      )+(cnk[18][1][0]*ik[13][1][0])));
    ikcnkt[18][1][2] = ((cnk[18][2][2]*ik[13][1][2])+((Cik[3][2][1]*ik[13][1][1]
      )+(cnk[18][2][0]*ik[13][1][0])));
    ikcnkt[18][2][0] = ((cnk[18][0][2]*ik[13][2][2])+((Cik[3][0][1]*ik[13][2][1]
      )+(cnk[18][0][0]*ik[13][2][0])));
    ikcnkt[18][2][1] = ((cnk[18][1][2]*ik[13][2][2])+((Cik[3][1][1]*ik[13][2][1]
      )+(cnk[18][1][0]*ik[13][2][0])));
    ikcnkt[18][2][2] = ((cnk[18][2][2]*ik[13][2][2])+((Cik[3][2][1]*ik[13][2][1]
      )+(cnk[18][2][0]*ik[13][2][0])));
    ikcnkt[19][0][0] = ((cnk[19][0][2]*ik[14][0][2])+((cnk[18][0][0]*
      ik[14][0][0])+(cnk[19][0][1]*ik[14][0][1])));
    ikcnkt[19][0][1] = ((cnk[19][1][2]*ik[14][0][2])+((cnk[18][1][0]*
      ik[14][0][0])+(cnk[19][1][1]*ik[14][0][1])));
    ikcnkt[19][0][2] = ((cnk[19][2][2]*ik[14][0][2])+((cnk[18][2][0]*
      ik[14][0][0])+(cnk[19][2][1]*ik[14][0][1])));
    ikcnkt[19][1][0] = ((cnk[19][0][2]*ik[14][1][2])+((cnk[18][0][0]*
      ik[14][1][0])+(cnk[19][0][1]*ik[14][1][1])));
    ikcnkt[19][1][1] = ((cnk[19][1][2]*ik[14][1][2])+((cnk[18][1][0]*
      ik[14][1][0])+(cnk[19][1][1]*ik[14][1][1])));
    ikcnkt[19][1][2] = ((cnk[19][2][2]*ik[14][1][2])+((cnk[18][2][0]*
      ik[14][1][0])+(cnk[19][2][1]*ik[14][1][1])));
    ikcnkt[19][2][0] = ((cnk[19][0][2]*ik[14][2][2])+((cnk[18][0][0]*
      ik[14][2][0])+(cnk[19][0][1]*ik[14][2][1])));
    ikcnkt[19][2][1] = ((cnk[19][1][2]*ik[14][2][2])+((cnk[18][1][0]*
      ik[14][2][0])+(cnk[19][1][1]*ik[14][2][1])));
    ikcnkt[19][2][2] = ((cnk[19][2][2]*ik[14][2][2])+((cnk[18][2][0]*
      ik[14][2][0])+(cnk[19][2][1]*ik[14][2][1])));
    ikcnkt[20][0][0] = ((cnk[20][0][2]*ik[15][0][2])+((cnk[19][0][1]*
      ik[15][0][1])+(cnk[20][0][0]*ik[15][0][0])));
    ikcnkt[20][0][1] = ((cnk[20][1][2]*ik[15][0][2])+((cnk[19][1][1]*
      ik[15][0][1])+(cnk[20][1][0]*ik[15][0][0])));
    ikcnkt[20][0][2] = ((cnk[20][2][2]*ik[15][0][2])+((cnk[19][2][1]*
      ik[15][0][1])+(cnk[20][2][0]*ik[15][0][0])));
    ikcnkt[20][1][0] = ((cnk[20][0][2]*ik[15][1][2])+((cnk[19][0][1]*
      ik[15][1][1])+(cnk[20][0][0]*ik[15][1][0])));
    ikcnkt[20][1][1] = ((cnk[20][1][2]*ik[15][1][2])+((cnk[19][1][1]*
      ik[15][1][1])+(cnk[20][1][0]*ik[15][1][0])));
    ikcnkt[20][1][2] = ((cnk[20][2][2]*ik[15][1][2])+((cnk[19][2][1]*
      ik[15][1][1])+(cnk[20][2][0]*ik[15][1][0])));
    ikcnkt[20][2][0] = ((cnk[20][0][2]*ik[15][2][2])+((cnk[19][0][1]*
      ik[15][2][1])+(cnk[20][0][0]*ik[15][2][0])));
    ikcnkt[20][2][1] = ((cnk[20][1][2]*ik[15][2][2])+((cnk[19][1][1]*
      ik[15][2][1])+(cnk[20][1][0]*ik[15][2][0])));
    ikcnkt[20][2][2] = ((cnk[20][2][2]*ik[15][2][2])+((cnk[19][2][1]*
      ik[15][2][1])+(cnk[20][2][0]*ik[15][2][0])));
    ikcnkt[21][0][0] = ((cnk[20][0][2]*ik[16][0][2])+((cnk[21][0][0]*
      ik[16][0][0])+(cnk[21][0][1]*ik[16][0][1])));
    ikcnkt[21][0][1] = ((cnk[20][1][2]*ik[16][0][2])+((cnk[21][1][0]*
      ik[16][0][0])+(cnk[21][1][1]*ik[16][0][1])));
    ikcnkt[21][0][2] = ((cnk[20][2][2]*ik[16][0][2])+((cnk[21][2][0]*
      ik[16][0][0])+(cnk[21][2][1]*ik[16][0][1])));
    ikcnkt[21][1][0] = ((cnk[20][0][2]*ik[16][1][2])+((cnk[21][0][0]*
      ik[16][1][0])+(cnk[21][0][1]*ik[16][1][1])));
    ikcnkt[21][1][1] = ((cnk[20][1][2]*ik[16][1][2])+((cnk[21][1][0]*
      ik[16][1][0])+(cnk[21][1][1]*ik[16][1][1])));
    ikcnkt[21][1][2] = ((cnk[20][2][2]*ik[16][1][2])+((cnk[21][2][0]*
      ik[16][1][0])+(cnk[21][2][1]*ik[16][1][1])));
    ikcnkt[21][2][0] = ((cnk[20][0][2]*ik[16][2][2])+((cnk[21][0][0]*
      ik[16][2][0])+(cnk[21][0][1]*ik[16][2][1])));
    ikcnkt[21][2][1] = ((cnk[20][1][2]*ik[16][2][2])+((cnk[21][1][0]*
      ik[16][2][0])+(cnk[21][1][1]*ik[16][2][1])));
    ikcnkt[21][2][2] = ((cnk[20][2][2]*ik[16][2][2])+((cnk[21][2][0]*
      ik[16][2][0])+(cnk[21][2][1]*ik[16][2][1])));
    ikcnkt[22][0][0] = ((cnk[22][0][2]*ik[17][0][2])+((Cik[3][0][1]*ik[17][0][1]
      )+(cnk[22][0][0]*ik[17][0][0])));
    ikcnkt[22][0][1] = ((cnk[22][1][2]*ik[17][0][2])+((Cik[3][1][1]*ik[17][0][1]
      )+(cnk[22][1][0]*ik[17][0][0])));
    ikcnkt[22][0][2] = ((cnk[22][2][2]*ik[17][0][2])+((Cik[3][2][1]*ik[17][0][1]
      )+(cnk[22][2][0]*ik[17][0][0])));
    ikcnkt[22][1][0] = ((cnk[22][0][2]*ik[17][1][2])+((Cik[3][0][1]*ik[17][1][1]
      )+(cnk[22][0][0]*ik[17][1][0])));
    ikcnkt[22][1][1] = ((cnk[22][1][2]*ik[17][1][2])+((Cik[3][1][1]*ik[17][1][1]
      )+(cnk[22][1][0]*ik[17][1][0])));
    ikcnkt[22][1][2] = ((cnk[22][2][2]*ik[17][1][2])+((Cik[3][2][1]*ik[17][1][1]
      )+(cnk[22][2][0]*ik[17][1][0])));
    ikcnkt[22][2][0] = ((cnk[22][0][2]*ik[17][2][2])+((Cik[3][0][1]*ik[17][2][1]
      )+(cnk[22][0][0]*ik[17][2][0])));
    ikcnkt[22][2][1] = ((cnk[22][1][2]*ik[17][2][2])+((Cik[3][1][1]*ik[17][2][1]
      )+(cnk[22][1][0]*ik[17][2][0])));
    ikcnkt[22][2][2] = ((cnk[22][2][2]*ik[17][2][2])+((Cik[3][2][1]*ik[17][2][1]
      )+(cnk[22][2][0]*ik[17][2][0])));
    ikcnkt[23][0][0] = ((cnk[23][0][2]*ik[18][0][2])+((cnk[22][0][0]*
      ik[18][0][0])+(cnk[23][0][1]*ik[18][0][1])));
    ikcnkt[23][0][1] = ((cnk[23][1][2]*ik[18][0][2])+((cnk[22][1][0]*
      ik[18][0][0])+(cnk[23][1][1]*ik[18][0][1])));
    ikcnkt[23][0][2] = ((cnk[23][2][2]*ik[18][0][2])+((cnk[22][2][0]*
      ik[18][0][0])+(cnk[23][2][1]*ik[18][0][1])));
    ikcnkt[23][1][0] = ((cnk[23][0][2]*ik[18][1][2])+((cnk[22][0][0]*
      ik[18][1][0])+(cnk[23][0][1]*ik[18][1][1])));
    ikcnkt[23][1][1] = ((cnk[23][1][2]*ik[18][1][2])+((cnk[22][1][0]*
      ik[18][1][0])+(cnk[23][1][1]*ik[18][1][1])));
    ikcnkt[23][1][2] = ((cnk[23][2][2]*ik[18][1][2])+((cnk[22][2][0]*
      ik[18][1][0])+(cnk[23][2][1]*ik[18][1][1])));
    ikcnkt[23][2][0] = ((cnk[23][0][2]*ik[18][2][2])+((cnk[22][0][0]*
      ik[18][2][0])+(cnk[23][0][1]*ik[18][2][1])));
    ikcnkt[23][2][1] = ((cnk[23][1][2]*ik[18][2][2])+((cnk[22][1][0]*
      ik[18][2][0])+(cnk[23][1][1]*ik[18][2][1])));
    ikcnkt[23][2][2] = ((cnk[23][2][2]*ik[18][2][2])+((cnk[22][2][0]*
      ik[18][2][0])+(cnk[23][2][1]*ik[18][2][1])));
    ikcnkt[24][0][0] = ((cnk[24][0][2]*ik[19][0][2])+((cnk[23][0][1]*
      ik[19][0][1])+(cnk[24][0][0]*ik[19][0][0])));
    ikcnkt[24][0][1] = ((cnk[24][1][2]*ik[19][0][2])+((cnk[23][1][1]*
      ik[19][0][1])+(cnk[24][1][0]*ik[19][0][0])));
    ikcnkt[24][0][2] = ((cnk[24][2][2]*ik[19][0][2])+((cnk[23][2][1]*
      ik[19][0][1])+(cnk[24][2][0]*ik[19][0][0])));
    ikcnkt[24][1][0] = ((cnk[24][0][2]*ik[19][1][2])+((cnk[23][0][1]*
      ik[19][1][1])+(cnk[24][0][0]*ik[19][1][0])));
    ikcnkt[24][1][1] = ((cnk[24][1][2]*ik[19][1][2])+((cnk[23][1][1]*
      ik[19][1][1])+(cnk[24][1][0]*ik[19][1][0])));
    ikcnkt[24][1][2] = ((cnk[24][2][2]*ik[19][1][2])+((cnk[23][2][1]*
      ik[19][1][1])+(cnk[24][2][0]*ik[19][1][0])));
    ikcnkt[24][2][0] = ((cnk[24][0][2]*ik[19][2][2])+((cnk[23][0][1]*
      ik[19][2][1])+(cnk[24][0][0]*ik[19][2][0])));
    ikcnkt[24][2][1] = ((cnk[24][1][2]*ik[19][2][2])+((cnk[23][1][1]*
      ik[19][2][1])+(cnk[24][1][0]*ik[19][2][0])));
    ikcnkt[24][2][2] = ((cnk[24][2][2]*ik[19][2][2])+((cnk[23][2][1]*
      ik[19][2][1])+(cnk[24][2][0]*ik[19][2][0])));
    ikcnkt[25][0][0] = ((cnk[24][0][2]*ik[20][0][2])+((cnk[25][0][0]*
      ik[20][0][0])+(cnk[25][0][1]*ik[20][0][1])));
    ikcnkt[25][0][1] = ((cnk[24][1][2]*ik[20][0][2])+((cnk[25][1][0]*
      ik[20][0][0])+(cnk[25][1][1]*ik[20][0][1])));
    ikcnkt[25][0][2] = ((cnk[24][2][2]*ik[20][0][2])+((cnk[25][2][0]*
      ik[20][0][0])+(cnk[25][2][1]*ik[20][0][1])));
    ikcnkt[25][1][0] = ((cnk[24][0][2]*ik[20][1][2])+((cnk[25][0][0]*
      ik[20][1][0])+(cnk[25][0][1]*ik[20][1][1])));
    ikcnkt[25][1][1] = ((cnk[24][1][2]*ik[20][1][2])+((cnk[25][1][0]*
      ik[20][1][0])+(cnk[25][1][1]*ik[20][1][1])));
    ikcnkt[25][1][2] = ((cnk[24][2][2]*ik[20][1][2])+((cnk[25][2][0]*
      ik[20][1][0])+(cnk[25][2][1]*ik[20][1][1])));
    ikcnkt[25][2][0] = ((cnk[24][0][2]*ik[20][2][2])+((cnk[25][0][0]*
      ik[20][2][0])+(cnk[25][0][1]*ik[20][2][1])));
    ikcnkt[25][2][1] = ((cnk[24][1][2]*ik[20][2][2])+((cnk[25][1][0]*
      ik[20][2][0])+(cnk[25][1][1]*ik[20][2][1])));
    ikcnkt[25][2][2] = ((cnk[24][2][2]*ik[20][2][2])+((cnk[25][2][0]*
      ik[20][2][0])+(cnk[25][2][1]*ik[20][2][1])));
    temp[0] = (((mk[0]*((rnk[5][1]*rnk[5][1])+(rnk[5][2]*rnk[5][2])))+((
      Cik[3][0][2]*ikcnkt[5][2][0])+((Cik[3][0][0]*ikcnkt[5][0][0])+(
      Cik[3][0][1]*ikcnkt[5][1][0]))))+((mk[1]*((rnk[6][1]*rnk[6][1])+(rnk[6][2]
      *rnk[6][2])))+((Cik[3][0][2]*ikcnkt[6][2][0])+((cnk[6][0][0]*
      ikcnkt[6][0][0])+(cnk[6][0][1]*ikcnkt[6][1][0])))));
    temp[1] = (((mk[3]*((rnk[8][1]*rnk[8][1])+(rnk[8][2]*rnk[8][2])))+((
      cnk[8][0][2]*ikcnkt[8][2][0])+((cnk[7][0][0]*ikcnkt[8][0][0])+(
      cnk[8][0][1]*ikcnkt[8][1][0]))))+(((mk[2]*((rnk[7][1]*rnk[7][1])+(
      rnk[7][2]*rnk[7][2])))+((cnk[7][0][2]*ikcnkt[7][2][0])+((cnk[6][0][1]*
      ikcnkt[7][1][0])+(cnk[7][0][0]*ikcnkt[7][0][0]))))+temp[0]));
    temp[2] = (((mk[5]*((rnk[10][1]*rnk[10][1])+(rnk[10][2]*rnk[10][2])))+((
      cnk[10][0][2]*ikcnkt[10][2][0])+((cnk[8][0][1]*ikcnkt[10][1][0])+(
      cnk[10][0][0]*ikcnkt[10][0][0]))))+(((mk[4]*((rnk[9][1]*rnk[9][1])+(
      rnk[9][2]*rnk[9][2])))+((cnk[9][0][2]*ikcnkt[9][2][0])+((cnk[8][0][1]*
      ikcnkt[9][1][0])+(cnk[9][0][0]*ikcnkt[9][0][0]))))+temp[1]));
    temp[3] = (((mk[7]*((rnk[12][1]*rnk[12][1])+(rnk[12][2]*rnk[12][2])))+((
      Cik[3][0][2]*ikcnkt[12][2][0])+((cnk[12][0][0]*ikcnkt[12][0][0])+(
      cnk[12][0][1]*ikcnkt[12][1][0]))))+(((mk[6]*((rnk[11][1]*rnk[11][1])+(
      rnk[11][2]*rnk[11][2])))+((cnk[11][0][2]*ikcnkt[11][2][0])+((cnk[10][0][0]
      *ikcnkt[11][0][0])+(cnk[11][0][1]*ikcnkt[11][1][0]))))+temp[2]));
    temp[4] = (((mk[9]*((rnk[14][1]*rnk[14][1])+(rnk[14][2]*rnk[14][2])))+((
      cnk[14][0][2]*ikcnkt[14][2][0])+((cnk[13][0][0]*ikcnkt[14][0][0])+(
      cnk[14][0][1]*ikcnkt[14][1][0]))))+(((mk[8]*((rnk[13][1]*rnk[13][1])+(
      rnk[13][2]*rnk[13][2])))+((cnk[13][0][2]*ikcnkt[13][2][0])+((cnk[12][0][1]
      *ikcnkt[13][1][0])+(cnk[13][0][0]*ikcnkt[13][0][0]))))+temp[3]));
    temp[5] = (((mk[11]*((rnk[16][1]*rnk[16][1])+(rnk[16][2]*rnk[16][2])))+((
      cnk[16][0][2]*ikcnkt[16][2][0])+((cnk[14][0][1]*ikcnkt[16][1][0])+(
      cnk[16][0][0]*ikcnkt[16][0][0]))))+(((mk[10]*((rnk[15][1]*rnk[15][1])+(
      rnk[15][2]*rnk[15][2])))+((cnk[15][0][2]*ikcnkt[15][2][0])+((cnk[14][0][1]
      *ikcnkt[15][1][0])+(cnk[15][0][0]*ikcnkt[15][0][0]))))+temp[4]));
    temp[6] = (((mk[13]*((rnk[18][1]*rnk[18][1])+(rnk[18][2]*rnk[18][2])))+((
      cnk[18][0][2]*ikcnkt[18][2][0])+((Cik[3][0][1]*ikcnkt[18][1][0])+(
      cnk[18][0][0]*ikcnkt[18][0][0]))))+(((mk[12]*((rnk[17][1]*rnk[17][1])+(
      rnk[17][2]*rnk[17][2])))+((cnk[17][0][2]*ikcnkt[17][2][0])+((cnk[16][0][0]
      *ikcnkt[17][0][0])+(cnk[17][0][1]*ikcnkt[17][1][0]))))+temp[5]));
    temp[7] = (((mk[15]*((rnk[20][1]*rnk[20][1])+(rnk[20][2]*rnk[20][2])))+((
      cnk[20][0][2]*ikcnkt[20][2][0])+((cnk[19][0][1]*ikcnkt[20][1][0])+(
      cnk[20][0][0]*ikcnkt[20][0][0]))))+(((mk[14]*((rnk[19][1]*rnk[19][1])+(
      rnk[19][2]*rnk[19][2])))+((cnk[19][0][2]*ikcnkt[19][2][0])+((cnk[18][0][0]
      *ikcnkt[19][0][0])+(cnk[19][0][1]*ikcnkt[19][1][0]))))+temp[6]));
    temp[8] = (((mk[17]*((rnk[22][1]*rnk[22][1])+(rnk[22][2]*rnk[22][2])))+((
      cnk[22][0][2]*ikcnkt[22][2][0])+((Cik[3][0][1]*ikcnkt[22][1][0])+(
      cnk[22][0][0]*ikcnkt[22][0][0]))))+(((mk[16]*((rnk[21][1]*rnk[21][1])+(
      rnk[21][2]*rnk[21][2])))+((cnk[20][0][2]*ikcnkt[21][2][0])+((cnk[21][0][0]
      *ikcnkt[21][0][0])+(cnk[21][0][1]*ikcnkt[21][1][0]))))+temp[7]));
    temp[9] = (((mk[19]*((rnk[24][1]*rnk[24][1])+(rnk[24][2]*rnk[24][2])))+((
      cnk[24][0][2]*ikcnkt[24][2][0])+((cnk[23][0][1]*ikcnkt[24][1][0])+(
      cnk[24][0][0]*ikcnkt[24][0][0]))))+(((mk[18]*((rnk[23][1]*rnk[23][1])+(
      rnk[23][2]*rnk[23][2])))+((cnk[23][0][2]*ikcnkt[23][2][0])+((cnk[22][0][0]
      *ikcnkt[23][0][0])+(cnk[23][0][1]*ikcnkt[23][1][0]))))+temp[8]));
    icm[0][0] = ((((mk[20]*((rnk[25][1]*rnk[25][1])+(rnk[25][2]*rnk[25][2])))+((
      cnk[24][0][2]*ikcnkt[25][2][0])+((cnk[25][0][0]*ikcnkt[25][0][0])+(
      cnk[25][0][1]*ikcnkt[25][1][0]))))+temp[9])-(mtot*((com[1]*com[1])+(com[2]
      *com[2]))));
    temp[0] = ((((cnk[7][0][2]*ikcnkt[7][2][1])+((cnk[6][0][1]*ikcnkt[7][1][1])+
      (cnk[7][0][0]*ikcnkt[7][0][1])))-(mk[2]*(rnk[7][0]*rnk[7][1])))+((((
      Cik[3][0][2]*ikcnkt[5][2][1])+((Cik[3][0][0]*ikcnkt[5][0][1])+(
      Cik[3][0][1]*ikcnkt[5][1][1])))-(mk[0]*(rnk[5][0]*rnk[5][1])))+(((
      Cik[3][0][2]*ikcnkt[6][2][1])+((cnk[6][0][0]*ikcnkt[6][0][1])+(
      cnk[6][0][1]*ikcnkt[6][1][1])))-(mk[1]*(rnk[6][0]*rnk[6][1])))));
    temp[1] = ((((cnk[10][0][2]*ikcnkt[10][2][1])+((cnk[8][0][1]*
      ikcnkt[10][1][1])+(cnk[10][0][0]*ikcnkt[10][0][1])))-(mk[5]*(rnk[10][0]*
      rnk[10][1])))+((((cnk[9][0][2]*ikcnkt[9][2][1])+((cnk[8][0][1]*
      ikcnkt[9][1][1])+(cnk[9][0][0]*ikcnkt[9][0][1])))-(mk[4]*(rnk[9][0]*
      rnk[9][1])))+((((cnk[8][0][2]*ikcnkt[8][2][1])+((cnk[7][0][0]*
      ikcnkt[8][0][1])+(cnk[8][0][1]*ikcnkt[8][1][1])))-(mk[3]*(rnk[8][0]*
      rnk[8][1])))+temp[0])));
    temp[2] = ((((cnk[13][0][2]*ikcnkt[13][2][1])+((cnk[12][0][1]*
      ikcnkt[13][1][1])+(cnk[13][0][0]*ikcnkt[13][0][1])))-(mk[8]*(rnk[13][0]*
      rnk[13][1])))+((((Cik[3][0][2]*ikcnkt[12][2][1])+((cnk[12][0][0]*
      ikcnkt[12][0][1])+(cnk[12][0][1]*ikcnkt[12][1][1])))-(mk[7]*(rnk[12][0]*
      rnk[12][1])))+((((cnk[11][0][2]*ikcnkt[11][2][1])+((cnk[10][0][0]*
      ikcnkt[11][0][1])+(cnk[11][0][1]*ikcnkt[11][1][1])))-(mk[6]*(rnk[11][0]*
      rnk[11][1])))+temp[1])));
    temp[3] = ((((cnk[16][0][2]*ikcnkt[16][2][1])+((cnk[14][0][1]*
      ikcnkt[16][1][1])+(cnk[16][0][0]*ikcnkt[16][0][1])))-(mk[11]*(rnk[16][0]*
      rnk[16][1])))+((((cnk[15][0][2]*ikcnkt[15][2][1])+((cnk[14][0][1]*
      ikcnkt[15][1][1])+(cnk[15][0][0]*ikcnkt[15][0][1])))-(mk[10]*(rnk[15][0]*
      rnk[15][1])))+((((cnk[14][0][2]*ikcnkt[14][2][1])+((cnk[13][0][0]*
      ikcnkt[14][0][1])+(cnk[14][0][1]*ikcnkt[14][1][1])))-(mk[9]*(rnk[14][0]*
      rnk[14][1])))+temp[2])));
    temp[4] = ((((cnk[19][0][2]*ikcnkt[19][2][1])+((cnk[18][0][0]*
      ikcnkt[19][0][1])+(cnk[19][0][1]*ikcnkt[19][1][1])))-(mk[14]*(rnk[19][0]*
      rnk[19][1])))+((((cnk[18][0][2]*ikcnkt[18][2][1])+((Cik[3][0][1]*
      ikcnkt[18][1][1])+(cnk[18][0][0]*ikcnkt[18][0][1])))-(mk[13]*(rnk[18][0]*
      rnk[18][1])))+((((cnk[17][0][2]*ikcnkt[17][2][1])+((cnk[16][0][0]*
      ikcnkt[17][0][1])+(cnk[17][0][1]*ikcnkt[17][1][1])))-(mk[12]*(rnk[17][0]*
      rnk[17][1])))+temp[3])));
    temp[5] = ((((cnk[22][0][2]*ikcnkt[22][2][1])+((Cik[3][0][1]*
      ikcnkt[22][1][1])+(cnk[22][0][0]*ikcnkt[22][0][1])))-(mk[17]*(rnk[22][0]*
      rnk[22][1])))+((((cnk[20][0][2]*ikcnkt[21][2][1])+((cnk[21][0][0]*
      ikcnkt[21][0][1])+(cnk[21][0][1]*ikcnkt[21][1][1])))-(mk[16]*(rnk[21][0]*
      rnk[21][1])))+((((cnk[20][0][2]*ikcnkt[20][2][1])+((cnk[19][0][1]*
      ikcnkt[20][1][1])+(cnk[20][0][0]*ikcnkt[20][0][1])))-(mk[15]*(rnk[20][0]*
      rnk[20][1])))+temp[4])));
    temp[6] = ((((cnk[24][0][2]*ikcnkt[25][2][1])+((cnk[25][0][0]*
      ikcnkt[25][0][1])+(cnk[25][0][1]*ikcnkt[25][1][1])))-(mk[20]*(rnk[25][0]*
      rnk[25][1])))+((((cnk[24][0][2]*ikcnkt[24][2][1])+((cnk[23][0][1]*
      ikcnkt[24][1][1])+(cnk[24][0][0]*ikcnkt[24][0][1])))-(mk[19]*(rnk[24][0]*
      rnk[24][1])))+((((cnk[23][0][2]*ikcnkt[23][2][1])+((cnk[22][0][0]*
      ikcnkt[23][0][1])+(cnk[23][0][1]*ikcnkt[23][1][1])))-(mk[18]*(rnk[23][0]*
      rnk[23][1])))+temp[5])));
    icm[0][1] = ((mtot*(com[0]*com[1]))+temp[6]);
    temp[0] = ((((cnk[7][0][2]*ikcnkt[7][2][2])+((cnk[6][0][1]*ikcnkt[7][1][2])+
      (cnk[7][0][0]*ikcnkt[7][0][2])))-(mk[2]*(rnk[7][0]*rnk[7][2])))+((((
      Cik[3][0][2]*ikcnkt[5][2][2])+((Cik[3][0][0]*ikcnkt[5][0][2])+(
      Cik[3][0][1]*ikcnkt[5][1][2])))-(mk[0]*(rnk[5][0]*rnk[5][2])))+(((
      Cik[3][0][2]*ikcnkt[6][2][2])+((cnk[6][0][0]*ikcnkt[6][0][2])+(
      cnk[6][0][1]*ikcnkt[6][1][2])))-(mk[1]*(rnk[6][0]*rnk[6][2])))));
    temp[1] = ((((cnk[10][0][2]*ikcnkt[10][2][2])+((cnk[8][0][1]*
      ikcnkt[10][1][2])+(cnk[10][0][0]*ikcnkt[10][0][2])))-(mk[5]*(rnk[10][0]*
      rnk[10][2])))+((((cnk[9][0][2]*ikcnkt[9][2][2])+((cnk[8][0][1]*
      ikcnkt[9][1][2])+(cnk[9][0][0]*ikcnkt[9][0][2])))-(mk[4]*(rnk[9][0]*
      rnk[9][2])))+((((cnk[8][0][2]*ikcnkt[8][2][2])+((cnk[7][0][0]*
      ikcnkt[8][0][2])+(cnk[8][0][1]*ikcnkt[8][1][2])))-(mk[3]*(rnk[8][0]*
      rnk[8][2])))+temp[0])));
    temp[2] = ((((cnk[13][0][2]*ikcnkt[13][2][2])+((cnk[12][0][1]*
      ikcnkt[13][1][2])+(cnk[13][0][0]*ikcnkt[13][0][2])))-(mk[8]*(rnk[13][0]*
      rnk[13][2])))+((((Cik[3][0][2]*ikcnkt[12][2][2])+((cnk[12][0][0]*
      ikcnkt[12][0][2])+(cnk[12][0][1]*ikcnkt[12][1][2])))-(mk[7]*(rnk[12][0]*
      rnk[12][2])))+((((cnk[11][0][2]*ikcnkt[11][2][2])+((cnk[10][0][0]*
      ikcnkt[11][0][2])+(cnk[11][0][1]*ikcnkt[11][1][2])))-(mk[6]*(rnk[11][0]*
      rnk[11][2])))+temp[1])));
    temp[3] = ((((cnk[16][0][2]*ikcnkt[16][2][2])+((cnk[14][0][1]*
      ikcnkt[16][1][2])+(cnk[16][0][0]*ikcnkt[16][0][2])))-(mk[11]*(rnk[16][0]*
      rnk[16][2])))+((((cnk[15][0][2]*ikcnkt[15][2][2])+((cnk[14][0][1]*
      ikcnkt[15][1][2])+(cnk[15][0][0]*ikcnkt[15][0][2])))-(mk[10]*(rnk[15][0]*
      rnk[15][2])))+((((cnk[14][0][2]*ikcnkt[14][2][2])+((cnk[13][0][0]*
      ikcnkt[14][0][2])+(cnk[14][0][1]*ikcnkt[14][1][2])))-(mk[9]*(rnk[14][0]*
      rnk[14][2])))+temp[2])));
    temp[4] = ((((cnk[19][0][2]*ikcnkt[19][2][2])+((cnk[18][0][0]*
      ikcnkt[19][0][2])+(cnk[19][0][1]*ikcnkt[19][1][2])))-(mk[14]*(rnk[19][0]*
      rnk[19][2])))+((((cnk[18][0][2]*ikcnkt[18][2][2])+((Cik[3][0][1]*
      ikcnkt[18][1][2])+(cnk[18][0][0]*ikcnkt[18][0][2])))-(mk[13]*(rnk[18][0]*
      rnk[18][2])))+((((cnk[17][0][2]*ikcnkt[17][2][2])+((cnk[16][0][0]*
      ikcnkt[17][0][2])+(cnk[17][0][1]*ikcnkt[17][1][2])))-(mk[12]*(rnk[17][0]*
      rnk[17][2])))+temp[3])));
    temp[5] = ((((cnk[22][0][2]*ikcnkt[22][2][2])+((Cik[3][0][1]*
      ikcnkt[22][1][2])+(cnk[22][0][0]*ikcnkt[22][0][2])))-(mk[17]*(rnk[22][0]*
      rnk[22][2])))+((((cnk[20][0][2]*ikcnkt[21][2][2])+((cnk[21][0][0]*
      ikcnkt[21][0][2])+(cnk[21][0][1]*ikcnkt[21][1][2])))-(mk[16]*(rnk[21][0]*
      rnk[21][2])))+((((cnk[20][0][2]*ikcnkt[20][2][2])+((cnk[19][0][1]*
      ikcnkt[20][1][2])+(cnk[20][0][0]*ikcnkt[20][0][2])))-(mk[15]*(rnk[20][0]*
      rnk[20][2])))+temp[4])));
    temp[6] = ((((cnk[24][0][2]*ikcnkt[25][2][2])+((cnk[25][0][0]*
      ikcnkt[25][0][2])+(cnk[25][0][1]*ikcnkt[25][1][2])))-(mk[20]*(rnk[25][0]*
      rnk[25][2])))+((((cnk[24][0][2]*ikcnkt[24][2][2])+((cnk[23][0][1]*
      ikcnkt[24][1][2])+(cnk[24][0][0]*ikcnkt[24][0][2])))-(mk[19]*(rnk[24][0]*
      rnk[24][2])))+((((cnk[23][0][2]*ikcnkt[23][2][2])+((cnk[22][0][0]*
      ikcnkt[23][0][2])+(cnk[23][0][1]*ikcnkt[23][1][2])))-(mk[18]*(rnk[23][0]*
      rnk[23][2])))+temp[5])));
    icm[0][2] = ((mtot*(com[0]*com[2]))+temp[6]);
    icm[1][0] = icm[0][1];
    temp[0] = (((mk[0]*((rnk[5][0]*rnk[5][0])+(rnk[5][2]*rnk[5][2])))+((
      Cik[3][1][2]*ikcnkt[5][2][1])+((Cik[3][1][0]*ikcnkt[5][0][1])+(
      Cik[3][1][1]*ikcnkt[5][1][1]))))+((mk[1]*((rnk[6][0]*rnk[6][0])+(rnk[6][2]
      *rnk[6][2])))+((Cik[3][1][2]*ikcnkt[6][2][1])+((cnk[6][1][0]*
      ikcnkt[6][0][1])+(cnk[6][1][1]*ikcnkt[6][1][1])))));
    temp[1] = (((mk[3]*((rnk[8][0]*rnk[8][0])+(rnk[8][2]*rnk[8][2])))+((
      cnk[8][1][2]*ikcnkt[8][2][1])+((cnk[7][1][0]*ikcnkt[8][0][1])+(
      cnk[8][1][1]*ikcnkt[8][1][1]))))+(((mk[2]*((rnk[7][0]*rnk[7][0])+(
      rnk[7][2]*rnk[7][2])))+((cnk[7][1][2]*ikcnkt[7][2][1])+((cnk[6][1][1]*
      ikcnkt[7][1][1])+(cnk[7][1][0]*ikcnkt[7][0][1]))))+temp[0]));
    temp[2] = (((mk[5]*((rnk[10][0]*rnk[10][0])+(rnk[10][2]*rnk[10][2])))+((
      cnk[10][1][2]*ikcnkt[10][2][1])+((cnk[8][1][1]*ikcnkt[10][1][1])+(
      cnk[10][1][0]*ikcnkt[10][0][1]))))+(((mk[4]*((rnk[9][0]*rnk[9][0])+(
      rnk[9][2]*rnk[9][2])))+((cnk[9][1][2]*ikcnkt[9][2][1])+((cnk[8][1][1]*
      ikcnkt[9][1][1])+(cnk[9][1][0]*ikcnkt[9][0][1]))))+temp[1]));
    temp[3] = (((mk[7]*((rnk[12][0]*rnk[12][0])+(rnk[12][2]*rnk[12][2])))+((
      Cik[3][1][2]*ikcnkt[12][2][1])+((cnk[12][1][0]*ikcnkt[12][0][1])+(
      cnk[12][1][1]*ikcnkt[12][1][1]))))+(((mk[6]*((rnk[11][0]*rnk[11][0])+(
      rnk[11][2]*rnk[11][2])))+((cnk[11][1][2]*ikcnkt[11][2][1])+((cnk[10][1][0]
      *ikcnkt[11][0][1])+(cnk[11][1][1]*ikcnkt[11][1][1]))))+temp[2]));
    temp[4] = (((mk[9]*((rnk[14][0]*rnk[14][0])+(rnk[14][2]*rnk[14][2])))+((
      cnk[14][1][2]*ikcnkt[14][2][1])+((cnk[13][1][0]*ikcnkt[14][0][1])+(
      cnk[14][1][1]*ikcnkt[14][1][1]))))+(((mk[8]*((rnk[13][0]*rnk[13][0])+(
      rnk[13][2]*rnk[13][2])))+((cnk[13][1][2]*ikcnkt[13][2][1])+((cnk[12][1][1]
      *ikcnkt[13][1][1])+(cnk[13][1][0]*ikcnkt[13][0][1]))))+temp[3]));
    temp[5] = (((mk[11]*((rnk[16][0]*rnk[16][0])+(rnk[16][2]*rnk[16][2])))+((
      cnk[16][1][2]*ikcnkt[16][2][1])+((cnk[14][1][1]*ikcnkt[16][1][1])+(
      cnk[16][1][0]*ikcnkt[16][0][1]))))+(((mk[10]*((rnk[15][0]*rnk[15][0])+(
      rnk[15][2]*rnk[15][2])))+((cnk[15][1][2]*ikcnkt[15][2][1])+((cnk[14][1][1]
      *ikcnkt[15][1][1])+(cnk[15][1][0]*ikcnkt[15][0][1]))))+temp[4]));
    temp[6] = (((mk[13]*((rnk[18][0]*rnk[18][0])+(rnk[18][2]*rnk[18][2])))+((
      cnk[18][1][2]*ikcnkt[18][2][1])+((Cik[3][1][1]*ikcnkt[18][1][1])+(
      cnk[18][1][0]*ikcnkt[18][0][1]))))+(((mk[12]*((rnk[17][0]*rnk[17][0])+(
      rnk[17][2]*rnk[17][2])))+((cnk[17][1][2]*ikcnkt[17][2][1])+((cnk[16][1][0]
      *ikcnkt[17][0][1])+(cnk[17][1][1]*ikcnkt[17][1][1]))))+temp[5]));
    temp[7] = (((mk[15]*((rnk[20][0]*rnk[20][0])+(rnk[20][2]*rnk[20][2])))+((
      cnk[20][1][2]*ikcnkt[20][2][1])+((cnk[19][1][1]*ikcnkt[20][1][1])+(
      cnk[20][1][0]*ikcnkt[20][0][1]))))+(((mk[14]*((rnk[19][0]*rnk[19][0])+(
      rnk[19][2]*rnk[19][2])))+((cnk[19][1][2]*ikcnkt[19][2][1])+((cnk[18][1][0]
      *ikcnkt[19][0][1])+(cnk[19][1][1]*ikcnkt[19][1][1]))))+temp[6]));
    temp[8] = (((mk[17]*((rnk[22][0]*rnk[22][0])+(rnk[22][2]*rnk[22][2])))+((
      cnk[22][1][2]*ikcnkt[22][2][1])+((Cik[3][1][1]*ikcnkt[22][1][1])+(
      cnk[22][1][0]*ikcnkt[22][0][1]))))+(((mk[16]*((rnk[21][0]*rnk[21][0])+(
      rnk[21][2]*rnk[21][2])))+((cnk[20][1][2]*ikcnkt[21][2][1])+((cnk[21][1][0]
      *ikcnkt[21][0][1])+(cnk[21][1][1]*ikcnkt[21][1][1]))))+temp[7]));
    temp[9] = (((mk[19]*((rnk[24][0]*rnk[24][0])+(rnk[24][2]*rnk[24][2])))+((
      cnk[24][1][2]*ikcnkt[24][2][1])+((cnk[23][1][1]*ikcnkt[24][1][1])+(
      cnk[24][1][0]*ikcnkt[24][0][1]))))+(((mk[18]*((rnk[23][0]*rnk[23][0])+(
      rnk[23][2]*rnk[23][2])))+((cnk[23][1][2]*ikcnkt[23][2][1])+((cnk[22][1][0]
      *ikcnkt[23][0][1])+(cnk[23][1][1]*ikcnkt[23][1][1]))))+temp[8]));
    icm[1][1] = ((((mk[20]*((rnk[25][0]*rnk[25][0])+(rnk[25][2]*rnk[25][2])))+((
      cnk[24][1][2]*ikcnkt[25][2][1])+((cnk[25][1][0]*ikcnkt[25][0][1])+(
      cnk[25][1][1]*ikcnkt[25][1][1]))))+temp[9])-(mtot*((com[0]*com[0])+(com[2]
      *com[2]))));
    temp[0] = ((((cnk[7][1][2]*ikcnkt[7][2][2])+((cnk[6][1][1]*ikcnkt[7][1][2])+
      (cnk[7][1][0]*ikcnkt[7][0][2])))-(mk[2]*(rnk[7][1]*rnk[7][2])))+((((
      Cik[3][1][2]*ikcnkt[5][2][2])+((Cik[3][1][0]*ikcnkt[5][0][2])+(
      Cik[3][1][1]*ikcnkt[5][1][2])))-(mk[0]*(rnk[5][1]*rnk[5][2])))+(((
      Cik[3][1][2]*ikcnkt[6][2][2])+((cnk[6][1][0]*ikcnkt[6][0][2])+(
      cnk[6][1][1]*ikcnkt[6][1][2])))-(mk[1]*(rnk[6][1]*rnk[6][2])))));
    temp[1] = ((((cnk[10][1][2]*ikcnkt[10][2][2])+((cnk[8][1][1]*
      ikcnkt[10][1][2])+(cnk[10][1][0]*ikcnkt[10][0][2])))-(mk[5]*(rnk[10][1]*
      rnk[10][2])))+((((cnk[9][1][2]*ikcnkt[9][2][2])+((cnk[8][1][1]*
      ikcnkt[9][1][2])+(cnk[9][1][0]*ikcnkt[9][0][2])))-(mk[4]*(rnk[9][1]*
      rnk[9][2])))+((((cnk[8][1][2]*ikcnkt[8][2][2])+((cnk[7][1][0]*
      ikcnkt[8][0][2])+(cnk[8][1][1]*ikcnkt[8][1][2])))-(mk[3]*(rnk[8][1]*
      rnk[8][2])))+temp[0])));
    temp[2] = ((((cnk[13][1][2]*ikcnkt[13][2][2])+((cnk[12][1][1]*
      ikcnkt[13][1][2])+(cnk[13][1][0]*ikcnkt[13][0][2])))-(mk[8]*(rnk[13][1]*
      rnk[13][2])))+((((Cik[3][1][2]*ikcnkt[12][2][2])+((cnk[12][1][0]*
      ikcnkt[12][0][2])+(cnk[12][1][1]*ikcnkt[12][1][2])))-(mk[7]*(rnk[12][1]*
      rnk[12][2])))+((((cnk[11][1][2]*ikcnkt[11][2][2])+((cnk[10][1][0]*
      ikcnkt[11][0][2])+(cnk[11][1][1]*ikcnkt[11][1][2])))-(mk[6]*(rnk[11][1]*
      rnk[11][2])))+temp[1])));
    temp[3] = ((((cnk[16][1][2]*ikcnkt[16][2][2])+((cnk[14][1][1]*
      ikcnkt[16][1][2])+(cnk[16][1][0]*ikcnkt[16][0][2])))-(mk[11]*(rnk[16][1]*
      rnk[16][2])))+((((cnk[15][1][2]*ikcnkt[15][2][2])+((cnk[14][1][1]*
      ikcnkt[15][1][2])+(cnk[15][1][0]*ikcnkt[15][0][2])))-(mk[10]*(rnk[15][1]*
      rnk[15][2])))+((((cnk[14][1][2]*ikcnkt[14][2][2])+((cnk[13][1][0]*
      ikcnkt[14][0][2])+(cnk[14][1][1]*ikcnkt[14][1][2])))-(mk[9]*(rnk[14][1]*
      rnk[14][2])))+temp[2])));
    temp[4] = ((((cnk[19][1][2]*ikcnkt[19][2][2])+((cnk[18][1][0]*
      ikcnkt[19][0][2])+(cnk[19][1][1]*ikcnkt[19][1][2])))-(mk[14]*(rnk[19][1]*
      rnk[19][2])))+((((cnk[18][1][2]*ikcnkt[18][2][2])+((Cik[3][1][1]*
      ikcnkt[18][1][2])+(cnk[18][1][0]*ikcnkt[18][0][2])))-(mk[13]*(rnk[18][1]*
      rnk[18][2])))+((((cnk[17][1][2]*ikcnkt[17][2][2])+((cnk[16][1][0]*
      ikcnkt[17][0][2])+(cnk[17][1][1]*ikcnkt[17][1][2])))-(mk[12]*(rnk[17][1]*
      rnk[17][2])))+temp[3])));
    temp[5] = ((((cnk[22][1][2]*ikcnkt[22][2][2])+((Cik[3][1][1]*
      ikcnkt[22][1][2])+(cnk[22][1][0]*ikcnkt[22][0][2])))-(mk[17]*(rnk[22][1]*
      rnk[22][2])))+((((cnk[20][1][2]*ikcnkt[21][2][2])+((cnk[21][1][0]*
      ikcnkt[21][0][2])+(cnk[21][1][1]*ikcnkt[21][1][2])))-(mk[16]*(rnk[21][1]*
      rnk[21][2])))+((((cnk[20][1][2]*ikcnkt[20][2][2])+((cnk[19][1][1]*
      ikcnkt[20][1][2])+(cnk[20][1][0]*ikcnkt[20][0][2])))-(mk[15]*(rnk[20][1]*
      rnk[20][2])))+temp[4])));
    temp[6] = ((((cnk[24][1][2]*ikcnkt[25][2][2])+((cnk[25][1][0]*
      ikcnkt[25][0][2])+(cnk[25][1][1]*ikcnkt[25][1][2])))-(mk[20]*(rnk[25][1]*
      rnk[25][2])))+((((cnk[24][1][2]*ikcnkt[24][2][2])+((cnk[23][1][1]*
      ikcnkt[24][1][2])+(cnk[24][1][0]*ikcnkt[24][0][2])))-(mk[19]*(rnk[24][1]*
      rnk[24][2])))+((((cnk[23][1][2]*ikcnkt[23][2][2])+((cnk[22][1][0]*
      ikcnkt[23][0][2])+(cnk[23][1][1]*ikcnkt[23][1][2])))-(mk[18]*(rnk[23][1]*
      rnk[23][2])))+temp[5])));
    icm[1][2] = ((mtot*(com[1]*com[2]))+temp[6]);
    icm[2][0] = icm[0][2];
    icm[2][1] = icm[1][2];
    temp[0] = (((mk[0]*((rnk[5][0]*rnk[5][0])+(rnk[5][1]*rnk[5][1])))+((
      Cik[3][2][2]*ikcnkt[5][2][2])+((Cik[3][2][0]*ikcnkt[5][0][2])+(
      Cik[3][2][1]*ikcnkt[5][1][2]))))+((mk[1]*((rnk[6][0]*rnk[6][0])+(rnk[6][1]
      *rnk[6][1])))+((Cik[3][2][2]*ikcnkt[6][2][2])+((cnk[6][2][0]*
      ikcnkt[6][0][2])+(cnk[6][2][1]*ikcnkt[6][1][2])))));
    temp[1] = (((mk[3]*((rnk[8][0]*rnk[8][0])+(rnk[8][1]*rnk[8][1])))+((
      cnk[8][2][2]*ikcnkt[8][2][2])+((cnk[7][2][0]*ikcnkt[8][0][2])+(
      cnk[8][2][1]*ikcnkt[8][1][2]))))+(((mk[2]*((rnk[7][0]*rnk[7][0])+(
      rnk[7][1]*rnk[7][1])))+((cnk[7][2][2]*ikcnkt[7][2][2])+((cnk[6][2][1]*
      ikcnkt[7][1][2])+(cnk[7][2][0]*ikcnkt[7][0][2]))))+temp[0]));
    temp[2] = (((mk[5]*((rnk[10][0]*rnk[10][0])+(rnk[10][1]*rnk[10][1])))+((
      cnk[10][2][2]*ikcnkt[10][2][2])+((cnk[8][2][1]*ikcnkt[10][1][2])+(
      cnk[10][2][0]*ikcnkt[10][0][2]))))+(((mk[4]*((rnk[9][0]*rnk[9][0])+(
      rnk[9][1]*rnk[9][1])))+((cnk[9][2][2]*ikcnkt[9][2][2])+((cnk[8][2][1]*
      ikcnkt[9][1][2])+(cnk[9][2][0]*ikcnkt[9][0][2]))))+temp[1]));
    temp[3] = (((mk[7]*((rnk[12][0]*rnk[12][0])+(rnk[12][1]*rnk[12][1])))+((
      Cik[3][2][2]*ikcnkt[12][2][2])+((cnk[12][2][0]*ikcnkt[12][0][2])+(
      cnk[12][2][1]*ikcnkt[12][1][2]))))+(((mk[6]*((rnk[11][0]*rnk[11][0])+(
      rnk[11][1]*rnk[11][1])))+((cnk[11][2][2]*ikcnkt[11][2][2])+((cnk[10][2][0]
      *ikcnkt[11][0][2])+(cnk[11][2][1]*ikcnkt[11][1][2]))))+temp[2]));
    temp[4] = (((mk[9]*((rnk[14][0]*rnk[14][0])+(rnk[14][1]*rnk[14][1])))+((
      cnk[14][2][2]*ikcnkt[14][2][2])+((cnk[13][2][0]*ikcnkt[14][0][2])+(
      cnk[14][2][1]*ikcnkt[14][1][2]))))+(((mk[8]*((rnk[13][0]*rnk[13][0])+(
      rnk[13][1]*rnk[13][1])))+((cnk[13][2][2]*ikcnkt[13][2][2])+((cnk[12][2][1]
      *ikcnkt[13][1][2])+(cnk[13][2][0]*ikcnkt[13][0][2]))))+temp[3]));
    temp[5] = (((mk[11]*((rnk[16][0]*rnk[16][0])+(rnk[16][1]*rnk[16][1])))+((
      cnk[16][2][2]*ikcnkt[16][2][2])+((cnk[14][2][1]*ikcnkt[16][1][2])+(
      cnk[16][2][0]*ikcnkt[16][0][2]))))+(((mk[10]*((rnk[15][0]*rnk[15][0])+(
      rnk[15][1]*rnk[15][1])))+((cnk[15][2][2]*ikcnkt[15][2][2])+((cnk[14][2][1]
      *ikcnkt[15][1][2])+(cnk[15][2][0]*ikcnkt[15][0][2]))))+temp[4]));
    temp[6] = (((mk[13]*((rnk[18][0]*rnk[18][0])+(rnk[18][1]*rnk[18][1])))+((
      cnk[18][2][2]*ikcnkt[18][2][2])+((Cik[3][2][1]*ikcnkt[18][1][2])+(
      cnk[18][2][0]*ikcnkt[18][0][2]))))+(((mk[12]*((rnk[17][0]*rnk[17][0])+(
      rnk[17][1]*rnk[17][1])))+((cnk[17][2][2]*ikcnkt[17][2][2])+((cnk[16][2][0]
      *ikcnkt[17][0][2])+(cnk[17][2][1]*ikcnkt[17][1][2]))))+temp[5]));
    temp[7] = (((mk[15]*((rnk[20][0]*rnk[20][0])+(rnk[20][1]*rnk[20][1])))+((
      cnk[20][2][2]*ikcnkt[20][2][2])+((cnk[19][2][1]*ikcnkt[20][1][2])+(
      cnk[20][2][0]*ikcnkt[20][0][2]))))+(((mk[14]*((rnk[19][0]*rnk[19][0])+(
      rnk[19][1]*rnk[19][1])))+((cnk[19][2][2]*ikcnkt[19][2][2])+((cnk[18][2][0]
      *ikcnkt[19][0][2])+(cnk[19][2][1]*ikcnkt[19][1][2]))))+temp[6]));
    temp[8] = (((mk[17]*((rnk[22][0]*rnk[22][0])+(rnk[22][1]*rnk[22][1])))+((
      cnk[22][2][2]*ikcnkt[22][2][2])+((Cik[3][2][1]*ikcnkt[22][1][2])+(
      cnk[22][2][0]*ikcnkt[22][0][2]))))+(((mk[16]*((rnk[21][0]*rnk[21][0])+(
      rnk[21][1]*rnk[21][1])))+((cnk[20][2][2]*ikcnkt[21][2][2])+((cnk[21][2][0]
      *ikcnkt[21][0][2])+(cnk[21][2][1]*ikcnkt[21][1][2]))))+temp[7]));
    temp[9] = (((mk[19]*((rnk[24][0]*rnk[24][0])+(rnk[24][1]*rnk[24][1])))+((
      cnk[24][2][2]*ikcnkt[24][2][2])+((cnk[23][2][1]*ikcnkt[24][1][2])+(
      cnk[24][2][0]*ikcnkt[24][0][2]))))+(((mk[18]*((rnk[23][0]*rnk[23][0])+(
      rnk[23][1]*rnk[23][1])))+((cnk[23][2][2]*ikcnkt[23][2][2])+((cnk[22][2][0]
      *ikcnkt[23][0][2])+(cnk[23][2][1]*ikcnkt[23][1][2]))))+temp[8]));
    icm[2][2] = ((((mk[20]*((rnk[25][0]*rnk[25][0])+(rnk[25][1]*rnk[25][1])))+((
      cnk[24][2][2]*ikcnkt[25][2][2])+((cnk[25][2][0]*ikcnkt[25][0][2])+(
      cnk[25][2][1]*ikcnkt[25][1][2]))))+temp[9])-(mtot*((com[0]*com[0])+(com[1]
      *com[1]))));
/*
 Used 0.05 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  948 adds/subtracts/negates
                   1275 multiplies
                      0 divides
                    253 assignments
*/
}

void Jimmy::sdpos(int body,
    double pt[3],
    double loc[3])
{
/*
Return inertial frame location of a point on a body.

*/
    double pv[3];

    if (sdchkbnum(21,body) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(21,23);
        return;
    }
    if (body  ==  -1) {
        loc[0] = pt[0];
        loc[1] = pt[1];
        loc[2] = pt[2];
    } else {
        pv[0] = rnb[body][0]+pt[0]*cnb[body][0][0]+pt[1]*cnb[body][0][1]+pt[2]*
          cnb[body][0][2];
        pv[1] = rnb[body][1]+pt[0]*cnb[body][1][0]+pt[1]*cnb[body][1][1]+pt[2]*
          cnb[body][1][2];
        pv[2] = rnb[body][2]+pt[0]*cnb[body][2][0]+pt[1]*cnb[body][2][1]+pt[2]*
          cnb[body][2][2];
        loc[0] = pv[0];
        loc[1] = pv[1];
        loc[2] = pv[2];
    }
}

void Jimmy::sdvel(int body,
    double pt[3],
    double velo[3])
{
/*
Return inertial frame velocity of a point on a body.

*/
    double pv[3];

    if (sdchkbnum(22,body) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(22,23);
        return;
    }
    if (body  ==  -1) {
        velo[0] = 0.;
        velo[1] = 0.;
        velo[2] = 0.;
    } else {
        pv[0] = wb[body][1]*pt[2]-wb[body][2]*pt[1];
        pv[1] = wb[body][2]*pt[0]-wb[body][0]*pt[2];
        pv[2] = wb[body][0]*pt[1]-wb[body][1]*pt[0];
        velo[0] = vnb[body][0]+pv[0]*cnb[body][0][0]+pv[1]*cnb[body][0][1]+pv[2]
          *cnb[body][0][2];
        velo[1] = vnb[body][1]+pv[0]*cnb[body][1][0]+pv[1]*cnb[body][1][1]+pv[2]
          *cnb[body][1][2];
        velo[2] = vnb[body][2]+pv[0]*cnb[body][2][0]+pv[1]*cnb[body][2][1]+pv[2]
          *cnb[body][2][2];
    }
}

void Jimmy::sdorient(int body,
    double dircos[3][3])
{
/*
Return orientation of body w.r.t. ground frame.

*/

    if (sdchkbnum(23,body) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(23,23);
        return;
    }
    if (body == -1) {
        dircos[0][0] = 1.;
        dircos[0][1] = 0.;
        dircos[0][2] = 0.;
        dircos[1][0] = 0.;
        dircos[1][1] = 1.;
        dircos[1][2] = 0.;
        dircos[2][0] = 0.;
        dircos[2][1] = 0.;
        dircos[2][2] = 1.;
    } else {
        dircos[0][0] = cnb[body][0][0];
        dircos[0][1] = cnb[body][0][1];
        dircos[0][2] = cnb[body][0][2];
        dircos[1][0] = cnb[body][1][0];
        dircos[1][1] = cnb[body][1][1];
        dircos[1][2] = cnb[body][1][2];
        dircos[2][0] = cnb[body][2][0];
        dircos[2][1] = cnb[body][2][1];
        dircos[2][2] = cnb[body][2][2];
    }
}

void Jimmy::sdangvel(int body,
    double avel[3])
{
/*
Return angular velocity of the body.

*/

    if (sdchkbnum(24,body) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(24,23);
        return;
    }
    if (body == -1) {
        avel[0] = 0.;
        avel[1] = 0.;
        avel[2] = 0.;
    } else {
        avel[0] = wb[body][0];
        avel[1] = wb[body][1];
        avel[2] = wb[body][2];
    }
}

void Jimmy::sdtrans(int frbod,
    double ivec[3],
    int tobod,
    double ovec[3])
{
/*
Transform ivec from frbod frame to tobod frame.

*/
    double pv[3];

    if (sdchkbnum(25,frbod) != 0) {
        return;
    }
    if (sdchkbnum(25,tobod) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(25,23);
        return;
    }
    if (frbod == tobod) {
        sdvcopy(ivec,ovec);
        return;
    }
    if (frbod == -1) {
        sdvcopy(ivec,pv);
        ovec[0] = pv[0]*cnb[tobod][0][0]+pv[1]*cnb[tobod][1][0]+pv[2]*cnb[tobod
          ][2][0];
        ovec[1] = pv[0]*cnb[tobod][0][1]+pv[1]*cnb[tobod][1][1]+pv[2]*cnb[tobod
          ][2][1];
        ovec[2] = pv[0]*cnb[tobod][0][2]+pv[1]*cnb[tobod][1][2]+pv[2]*cnb[tobod
          ][2][2];
        return;
    }
    if (tobod == -1) {
        sdvcopy(ivec,pv);
        ovec[0] = pv[0]*cnb[frbod][0][0]+pv[1]*cnb[frbod][0][1]+pv[2]*cnb[frbod
          ][0][2];
        ovec[1] = pv[0]*cnb[frbod][1][0]+pv[1]*cnb[frbod][1][1]+pv[2]*cnb[frbod
          ][1][2];
        ovec[2] = pv[0]*cnb[frbod][2][0]+pv[1]*cnb[frbod][2][1]+pv[2]*cnb[frbod
          ][2][2];
        return;
    }
    pv[0] = ivec[0]*cnb[frbod][0][0]+ivec[1]*cnb[frbod][0][1]+ivec[2]*cnb[frbod
      ][0][2];
    pv[1] = ivec[0]*cnb[frbod][1][0]+ivec[1]*cnb[frbod][1][1]+ivec[2]*cnb[frbod
      ][1][2];
    pv[2] = ivec[0]*cnb[frbod][2][0]+ivec[1]*cnb[frbod][2][1]+ivec[2]*cnb[frbod
      ][2][2];
    ovec[0] = pv[0]*cnb[tobod][0][0]+pv[1]*cnb[tobod][1][0]+pv[2]*cnb[tobod][2][
      0];
    ovec[1] = pv[0]*cnb[tobod][0][1]+pv[1]*cnb[tobod][1][1]+pv[2]*cnb[tobod][2][
      1];
    ovec[2] = pv[0]*cnb[tobod][0][2]+pv[1]*cnb[tobod][1][2]+pv[2]*cnb[tobod][2][
      2];
}

void Jimmy::sdrel2cart(int coord,
    int body,
    double point[3],
    double linchg[3],
    double rotchg[3])
{
/* Return derivative of pt loc and body orient w.r.t. hinge rate
*/
    int x,i,gnd;
    double lin[3],pv[3];

    if ((coord < 0) || (coord > 25)) {
        sdseterr(59,45);
        return;
    }
    if (sdchkbnum(59,body) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        sdseterr(59,23);
        return;
    }
    gnd = -1;
    if (body == gnd) {
        x = -1;
    } else {
        x = firstq[body]+njntdof[body]-1;
    }
    if (x < coord) {
        sdvset(0.,0.,0.,linchg);
        sdvset(0.,0.,0.,rotchg);
        return;
    }
    sddovpk();
    for (i = 0; i < 3; i++) {
        rotchg[i] = Wpk[coord][x][i];
        lin[i] = Vpk[coord][x][i];
    }
    if (body == gnd) {
        sdvcopy(point,pv);
    } else {
        pv[0] = rcom[body][0]+point[0];
        pv[1] = rcom[body][1]+point[1];
        pv[2] = rcom[body][2]+point[2];
    }
    sdvcross(rotchg,pv,linchg);
    sdvadd(linchg,lin,linchg);
}

void Jimmy::sdacc(int body,
    double pt[3],
    double accel[3])
{
/*
Return linear acceleration a point of the specified body.

*/
    double pv[3];

    if (sdchkbnum(32,body) != 0) {
        return;
    }
    if (roustate != 3) {
        sdseterr(32,24);
        return;
    }
    if (body  ==  -1) {
        accel[0] = 0.;
        accel[1] = 0.;
        accel[2] = 0.;
    } else {
        pv[0] = pt[0]*dyad[body][0][0]+pt[1]*dyad[body][0][1]+pt[2]*dyad[body][0
          ][2];
        pv[1] = pt[0]*dyad[body][1][0]+pt[1]*dyad[body][1][1]+pt[2]*dyad[body][1
          ][2];
        pv[2] = pt[0]*dyad[body][2][0]+pt[1]*dyad[body][2][1]+pt[2]*dyad[body][2
          ][2];
        accel[0] = anb[body][0]+pv[0]*cnb[body][0][0]+pv[1]*cnb[body][0][1]+pv[2
          ]*cnb[body][0][2];
        accel[1] = anb[body][1]+pv[0]*cnb[body][1][0]+pv[1]*cnb[body][1][1]+pv[2
          ]*cnb[body][1][2];
        accel[2] = anb[body][2]+pv[0]*cnb[body][2][0]+pv[1]*cnb[body][2][1]+pv[2
          ]*cnb[body][2][2];
    }
}

void Jimmy::sdangacc(int body,
    double aacc[3])
{
/*
Return angular acceleration of the body.

*/

    if (sdchkbnum(33,body) != 0) {
        return;
    }
    if (roustate != 3) {
        sdseterr(33,24);
        return;
    }
    if (body == -1) {
        aacc[0] = 0.;
        aacc[1] = 0.;
        aacc[2] = 0.;
    } else {
        aacc[0] = onb[body][0];
        aacc[1] = onb[body][1];
        aacc[2] = onb[body][2];
    }
}

void Jimmy::sdgrav(double gravin[3])
{

    sdseterr(1,19);
    roustate = 0;
}

void Jimmy::sdmass(int body,
    double massin)
{

    if (sdchkbnum(2,body) != 0) {
        return;
    }
    if (body == -1) {
        sdseterr(2,15);
        return;
    }
    if (mkq[body] != 0) {
        mk[body] = massin;
        mkq[body] = 3;
    } else {
        sdseterr(2,19);
    }
    roustate = 0;
}

void Jimmy::sdiner(int body,
    double inerin[3][3])
{
    int anyques;

    if (sdchkbnum(3,body) != 0) {
        return;
    }
    if (body == -1) {
        sdseterr(3,15);
        return;
    }
    anyques = 0;
    if (ikq[body][0][0]  !=  0) {
        ik[body][0][0] = inerin[0][0];
        ikq[body][0][0] = 3;
        anyques = 1;
    }
    if (ikq[body][0][1]  !=  0) {
        ik[body][0][1] = inerin[0][1];
        ikq[body][0][1] = 3;
        ik[body][1][0] = inerin[0][1];
        ikq[body][1][0] = 3;
        anyques = 1;
    }
    if (ikq[body][0][2]  !=  0) {
        ik[body][0][2] = inerin[0][2];
        ikq[body][0][2] = 3;
        ik[body][2][0] = inerin[0][2];
        ikq[body][2][0] = 3;
        anyques = 1;
    }
    if (ikq[body][1][1]  !=  0) {
        ik[body][1][1] = inerin[1][1];
        ikq[body][1][1] = 3;
        anyques = 1;
    }
    if (ikq[body][1][2]  !=  0) {
        ik[body][1][2] = inerin[1][2];
        ikq[body][1][2] = 3;
        ik[body][2][1] = inerin[1][2];
        ikq[body][2][1] = 3;
        anyques = 1;
    }
    if (ikq[body][2][2]  !=  0) {
        ik[body][2][2] = inerin[2][2];
        ikq[body][2][2] = 3;
        anyques = 1;
    }
    if (anyques == 0) {
        sdseterr(3,19);
    }
    roustate = 0;
}

void Jimmy::sdbtj(int joint,
    double btjin[3])
{
    int anyques;

    if (sdchkjnum(4,joint) != 0) {
        return;
    }
    anyques = 0;
    if (rkq[joint][0]  !=  0) {
        rk[joint][0] = btjin[0];
        rkq[joint][0] = 3;
        anyques = 1;
    }
    if (rkq[joint][1]  !=  0) {
        rk[joint][1] = btjin[1];
        rkq[joint][1] = 3;
        anyques = 1;
    }
    if (rkq[joint][2]  !=  0) {
        rk[joint][2] = btjin[2];
        rkq[joint][2] = 3;
        anyques = 1;
    }
    if (anyques == 0) {
        sdseterr(4,19);
    }
    roustate = 0;
}

void Jimmy::sditj(int joint,
    double itjin[3])
{
    int anyques;

    if (sdchkjnum(5,joint) != 0) {
        return;
    }
    anyques = 0;
    if (riq[joint][0]  !=  0) {
        ri[joint][0] = itjin[0];
        riq[joint][0] = 3;
        anyques = 1;
    }
    if (riq[joint][1]  !=  0) {
        ri[joint][1] = itjin[1];
        riq[joint][1] = 3;
        anyques = 1;
    }
    if (riq[joint][2]  !=  0) {
        ri[joint][2] = itjin[2];
        riq[joint][2] = 3;
        anyques = 1;
    }
    if (anyques == 0) {
        sdseterr(5,19);
    }
    roustate = 0;
}

void Jimmy::sdpin(int joint,
    int pinno,
    double pinin[3])
{
    int anyques,offs;

    if (sdchkjpin(6,joint,pinno) != 0) {
        return;
    }
    anyques = 0;
    offs = firstq[joint]+pinno;
    if (jtype[joint] == 21) {
        offs = offs+3;
    }
    if (jtype[joint] == 11) {
        offs = offs+1;
    }
    if (pinq[offs][0]  !=  0) {
        pin[offs][0] = pinin[0];
        pinq[offs][0] = 3;
        anyques = 1;
    }
    if (pinq[offs][1]  !=  0) {
        pin[offs][1] = pinin[1];
        pinq[offs][1] = 3;
        anyques = 1;
    }
    if (pinq[offs][2]  !=  0) {
        pin[offs][2] = pinin[2];
        pinq[offs][2] = 3;
        anyques = 1;
    }
    if (anyques == 0) {
        sdseterr(6,19);
    }
    roustate = 0;
}

void Jimmy::sdpres(int joint,
    int axis,
    int presin)
{
    int anyques;

    if (sdchkjaxis(37,joint,axis) != 0) {
        return;
    }
    if ((presin != 0) && (presin != 1)) {
        sdseterr(37,20);
    }
    anyques = 0;
    if (presq[sdindx(joint,axis)]  !=  0) {
        if (presin  !=  0) {
            pres[sdindx(joint,axis)] = 1.;
        } else {
            pres[sdindx(joint,axis)] = 0.;
        }
        presq[sdindx(joint,axis)] = 3;
        anyques = 1;
    }
    if (anyques == 0) {
        sdseterr(37,19);
    }
    wwflg = 0;
}

void Jimmy::sdconschg(void)
{

    wwflg = 0;
}

void Jimmy::sdstab(double velin,
    double posin)
{

    stabvel = velin;
    stabvelq = 3;
    stabpos = posin;
    stabposq = 3;
}

void Jimmy::sdgetgrav(double gravout[3])
{

    gravout[0] = grav[0];
    gravout[1] = grav[1];
    gravout[2] = grav[2];
}

void Jimmy::sdgetmass(int body,
    double *massout)
{

    if (sdchkbnum(40,body) != 0) {
        return;
    }
    if (body == -1) {
        sdseterr(40,15);
        return;
    }
    *massout = mk[body];
}

void Jimmy::sdgetiner(int body,
    double inerout[3][3])
{

    if (sdchkbnum(41,body) != 0) {
        return;
    }
    if (body == -1) {
        sdseterr(41,15);
        return;
    }
    inerout[0][0] = ik[body][0][0];
    inerout[0][1] = ik[body][0][1];
    inerout[0][2] = ik[body][0][2];
    inerout[1][0] = ik[body][1][0];
    inerout[1][1] = ik[body][1][1];
    inerout[1][2] = ik[body][1][2];
    inerout[2][0] = ik[body][2][0];
    inerout[2][1] = ik[body][2][1];
    inerout[2][2] = ik[body][2][2];
}

void Jimmy::sdgetbtj(int joint,
    double btjout[3])
{

    if (sdchkjnum(42,joint) != 0) {
        return;
    }
    btjout[0] = rk[joint][0];
    btjout[1] = rk[joint][1];
    btjout[2] = rk[joint][2];
}

void Jimmy::sdgetitj(int joint,
    double itjout[3])
{

    if (sdchkjnum(43,joint) != 0) {
        return;
    }
    itjout[0] = ri[joint][0];
    itjout[1] = ri[joint][1];
    itjout[2] = ri[joint][2];
}

void Jimmy::sdgetpin(int joint,
    int pinno,
    double pinout[3])
{
    int offs;

    if (sdchkjpin(44,joint,pinno) != 0) {
        return;
    }
    offs = firstq[joint]+pinno;
    if (jtype[joint] == 21) {
        offs = offs+3;
    }
    if (jtype[joint] == 11) {
        offs = offs+1;
    }
    pinout[0] = pin[offs][0];
    pinout[1] = pin[offs][1];
    pinout[2] = pin[offs][2];
}

void Jimmy::sdgetpres(int joint,
    int axis,
    int *presout)
{

    if (sdchkjaxis(45,joint,axis) != 0) {
        return;
    }
    if (pres[sdindx(joint,axis)]  !=  0.) {
        *presout = 1;
    } else {
        *presout = 0;
    }
}

void Jimmy::sdgetstab(double *velout,
    double *posout)
{

    *velout = stabvel;
    *posout = stabpos;
}

void Jimmy::sdinfo(int info[50])
{

    info[0] = ground;
    info[1] = nbod;
    info[2] = ndof;
    info[3] = ncons;
    info[4] = nloop;
    info[5] = nldof;
    info[6] = nloopc;
    info[7] = nball;
    info[8] = nlball;
    info[9] = npres;
    info[10] = nuser;
    info[11] = 0;
/* info entries from 12-49 are reserved */
}

void Jimmy::sdjnt(int joint,
    int info[50],
    int tran[6])
{
    int i,offs;

    if (sdchkjnum(48,joint) != 0) {
        return;
    }
    info[0] = jtype[joint];
    info[1] = 0;
    offs = 0;
    info[2] = inb[joint];
    info[3] = outb[joint];
    info[4] = njntdof[joint];
    info[5] = njntc[joint];
    info[6] = njntp[joint];
    info[7] = firstq[joint];
    info[8] = ballq[joint];
    info[9] = firstm[joint];
    info[10] = firstp[joint];
/* info entries from 11-49 are reserved */

    for (i = 0; i <= 5; i++) {
        if (i  <  njntdof[joint]) {
            tran[i] = trans[offs+firstq[joint]+i];
        } else {
            tran[i] = -1;
        }
    }
}

void Jimmy::sdcons(int consno,
    int info[50])
{

    if (sdchkucnum(49,consno) != 0) {
        return;
    }
/* There are no user constraints in this problem. */
}

void Jimmy::sdgentime(int *gentm)
{

    *gentm = 114024;
}
// start of analysis routines
void Jimmy::sdposfunc(double vars[26],
    double param[1],
    double resid[1])
{
    int i;
    double pos[27],vel[26];

    for (i = 0; i < 26; i++) {
        vel[i] = 0.;
    }
    sdang2st(vars,pos);
    sdstate(param[0],pos,vel);
    sdperr(resid);
}

void Jimmy::sdvelfunc(double vars[26],
    double param[28],
    double resid[1])
{

    sdstate(param[27],param,vars);
    sdverr(resid);
}

void Jimmy::sdstatfunc(double vars[26],
    double param[27],
    double resid[26])
{
    double pos[27],qdotdum[27];

    sdang2st(vars,pos);
    sdstate(param[26],pos,param);
    sduforce(param[26],pos,param);
    sdperr(resid);
    sdderiv(qdotdum,&resid[0]);
}

void Jimmy::sdstdyfunc(double vars[52],
    double param[1],
    double resid[26])
{
    double pos[27],qdotdum[27];

    sdang2st(vars,pos);
    sdstate(param[0],pos,&vars[26]);
    sduforce(param[0],pos,&vars[26]);
    sdperr(resid);
    sdverr(&resid[0]);
    sdderiv(qdotdum,&resid[0]);
}

/* This routine is passed to the integrator. */

void Jimmy::sdmotfunc(double time,
    double state[53],
    double dstate[53],
    double param[1],
    int *status)
{

    sdstate(time,state,&state[27]);
    sduforce(time,state,&state[27]);
    sdderiv(dstate,&dstate[27]);
    *status = 0;
}

/* This routine performs assembly analysis. */

void Jimmy::sdassemble(double time,
    double state[53],
    int lock[26],
    double tol,
    int maxevals,
    int *fcnt,
    int *err)
{
    double perrs[1],param[1];
    int i;

    sdgentime(&i);
    if (i != 114024) {
        sdseterr(50,42);
    }
    param[0] = time;
    sdst2ang(state,state);
    *err = 0;
    *fcnt = 0;
    sdposfunc(state,param,perrs);
    *fcnt = *fcnt+1;
    sdang2st(state,state);
}

/* This routine performs initial velocity analysis. */

void Jimmy::sdinitvel(double time,
    double state[53],
    int lock[26],
    double tol,
    int maxevals,
    int *fcnt,
    int *err)
{
    double verrs[1],param[28];
    int i;

    sdgentime(&i);
    if (i != 114024) {
        sdseterr(51,42);
    }
    for (i = 0; i < 27; i++) {
        param[i] = state[i];
    }
    param[27] = time;
    *err = 0;
    *fcnt = 0;
    sdvelfunc(&state[27],param,verrs);
    *fcnt = *fcnt+1;
}

/* This routine performs static analysis. */

void Jimmy::sdstatic(double time,
    double state[53],
    int lock[26],
    double ctol,
    double tol,
    int maxevals,
    int *fcnt,
    int *err)
{
    double resid[26],param[27],jw[676],dw[5408],rw[416];
    int iw[208],rooterr,i;

    sdgentime(&i);
    if (i != 114024) {
        sdseterr(52,42);
    }
    for (i = 0; i < 26; i++) {
        param[i] = state[27+i];
    }
    param[26] = time;
    sdst2ang(state,state);
    sdroot(&Jimmy::sdstatfunc,state,param,26,26,26,lock,
      ctol,tol,maxevals,jw,dw,rw,iw,resid,fcnt,&rooterr);
    sdstatfunc(state,param,resid);
    *fcnt = *fcnt+1;
    sdang2st(state,state);
    if (rooterr == 0) {
        *err = 0;
    } else {
        if (*fcnt >= maxevals) {
            *err = 2;
        } else {
            *err = 1;
        }
    }
}

/* This routine performs steady motion analysis. */

void Jimmy::sdsteady(double time,
    double state[53],
    int lock[52],
    double ctol,
    double tol,
    int maxevals,
    int *fcnt,
    int *err)
{
    double resid[26],param[1],vars[52];
    double jw[1352],dw[12168],rw[650];
    int iw[312],rooterr,i;

    sdgentime(&i);
    if (i != 114024) {
        sdseterr(53,42);
    }
    param[0] = time;
    sdst2ang(state,vars);
    for (i = 0; i < 26; i++) {
        vars[26+i] = state[27+i];
    }
    sdroot(&Jimmy::sdstdyfunc,vars,param,26,52,26,lock,
      ctol,tol,maxevals,jw,dw,rw,iw,resid,fcnt,&rooterr);
    sdstdyfunc(vars,param,resid);
    *fcnt = *fcnt+1;
    sdang2st(vars,state);
    for (i = 0; i < 26; i++) {
        state[27+i] = vars[26+i];
    }
    if (rooterr == 0) {
        *err = 0;
    } else {
        if (*fcnt >= maxevals) {
            *err = 2;
        } else {
            *err = 1;
        }
    }
}

/* This routine performs state integration. */

void Jimmy::sdmotion(double *time,
    double state[53],
    double dstate[53],
    double dt,
    double ctol,
    double tol,
    int *flag,
    int *err)
{
    static double step;
    double work[318],ttime,param[1];
    int vintgerr,which,ferr,i;

    sdgentime(&i);
    if (i != 114024) {
        sdseterr(54,42);
    }
    param[0] = ctol;
    ttime = *time;
    if (*flag != 0) {
        sdmotfunc(ttime,state,dstate,param,&ferr);
        step = dt;
        *flag = 0;
    }
    if (step <= 0.) {
        step = dt;
    }
    sdvinteg(&Jimmy::sdmotfunc,&ttime,state,dstate,param,dt,&step,53,tol,work,&vintgerr,
      &which);
    *time = ttime;
    *err = vintgerr;
}

/* This routine performs state integration with a fixed-step integrator. */

void Jimmy::sdfmotion(double *time,
    double state[53],
    double dstate[53],
    double dt,
    double ctol,
    int *flag,
    double *errest,
    int *err)
{
    double work[212],ttime,param[1];
    int ferr,i;

    sdgentime(&i);
    if (i != 114024) {
        sdseterr(55,42);
    }
    param[0] = ctol;
    *err = 0;
    ttime = *time;
    if (*flag != 0) {
        sdmotfunc(ttime,state,dstate,param,&ferr);
        *flag = 0;
    }
    sdfinteg(&Jimmy::sdmotfunc,&ttime,state,dstate,param,dt,53,work,errest,&ferr);
    if (ferr != 0) {
        *err = 1;
    }
    *time = ttime;
}
// start of sdlib routines
void Jimmy::sdprerrmsg(FILE *fnum,
    int routine,
    int errnum)
{

    if (errnum == 0) {
        return;
    }
    fprintf(fnum,"\n");
    if (routine == 1) {
        fprintf(fnum,"sdgrav:\n");
    }
    if (routine == 2) {
        fprintf(fnum,"sdmass:\n");
    }
    if (routine == 3) {
        fprintf(fnum,"sdiner:\n");
    }
    if (routine == 4) {
        fprintf(fnum,"sdbtj:\n");
    }
    if (routine == 5) {
        fprintf(fnum,"sditj:\n");
    }
    if (routine == 6) {
        fprintf(fnum,"sdpin:\n");
    }
    if (routine == 7) {
        fprintf(fnum,"sdinit:\n");
    }
    if (routine == 8) {
        fprintf(fnum,"sdstate:\n");
    }
    if (routine == 9) {
        fprintf(fnum,"sdpsstate:\n");
    }
    if (routine == 13) {
        fprintf(fnum,"sdpresacc:\n");
    }
    if (routine == 14) {
        fprintf(fnum,"sdpresvel:\n");
    }
    if (routine == 15) {
        fprintf(fnum,"sdprespos:\n");
    }
    if (routine == 10) {
        fprintf(fnum,"sdhinget:\n");
    }
    if (routine == 11) {
        fprintf(fnum,"sdpointf:\n");
    }
    if (routine == 12) {
        fprintf(fnum,"sdbodyt:\n");
    }
    if (routine == 17) {
        fprintf(fnum,"sdderiv:\n");
    }
    if (routine == 16) {
        fprintf(fnum,"sdresid:\n");
    }
    if (routine == 18) {
        fprintf(fnum,"sdpseudo:\n");
    }
    if (routine == 19) {
        fprintf(fnum,"sdmom:\n");
    }
    if (routine == 20) {
        fprintf(fnum,"sdsys:\n");
    }
    if (routine == 21) {
        fprintf(fnum,"sdpos:\n");
    }
    if (routine == 22) {
        fprintf(fnum,"sdvel:\n");
    }
    if (routine == 23) {
        fprintf(fnum,"sdorient:\n");
    }
    if (routine == 24) {
        fprintf(fnum,"sdangvel:\n");
    }
    if (routine == 25) {
        fprintf(fnum,"sdtrans:\n");
    }
    if (routine == 26) {
        fprintf(fnum,"sdperr:\n");
    }
    if (routine == 27) {
        fprintf(fnum,"sdverr:\n");
    }
    if (routine == 28) {
        fprintf(fnum,"sdpsqdot:\n");
    }
    if (routine == 29) {
        fprintf(fnum,"sdpsudot:\n");
    }
    if (routine == 30) {
        fprintf(fnum,"sdgetht:\n");
    }
    if (routine == 31) {
        fprintf(fnum,"sdreac:\n");
    }
    if (routine == 32) {
        fprintf(fnum,"sdacc:\n");
    }
    if (routine == 33) {
        fprintf(fnum,"sdangacc:\n");
    }
    if (routine == 34) {
        fprintf(fnum,"sdmult:\n");
    }
    if (routine == 35) {
        fprintf(fnum,"sdaerr:\n");
    }
    if (routine == 36) {
        fprintf(fnum,"sdindx:\n");
    }
    if (routine == 37) {
        fprintf(fnum,"sdpres:\n");
    }
    if (routine == 38) {
        fprintf(fnum,"sdstab:\n");
    }
    if (routine == 39) {
        fprintf(fnum,"sdgetgrav:\n");
    }
    if (routine == 40) {
        fprintf(fnum,"sdgetmass:\n");
    }
    if (routine == 41) {
        fprintf(fnum,"sdgetiner:\n");
    }
    if (routine == 42) {
        fprintf(fnum,"sdgetbtj:\n");
    }
    if (routine == 43) {
        fprintf(fnum,"sdgetitj:\n");
    }
    if (routine == 44) {
        fprintf(fnum,"sdgetpin:\n");
    }
    if (routine == 45) {
        fprintf(fnum,"sdgetpres:\n");
    }
    if (routine == 46) {
        fprintf(fnum,"sdgetstab:\n");
    }
    if (routine == 47) {
        fprintf(fnum,"sdinfo:\n");
    }
    if (routine == 48) {
        fprintf(fnum,"sdjnt:\n");
    }
    if (routine == 49) {
        fprintf(fnum,"sdcons:\n");
    }
    if (routine == 50) {
        fprintf(fnum,"sdassemble:\n");
    }
    if (routine == 51) {
        fprintf(fnum,"sdinitvel:\n");
    }
    if (routine == 52) {
        fprintf(fnum,"sdstatic:\n");
    }
    if (routine == 53) {
        fprintf(fnum,"sdsteady:\n");
    }
    if (routine == 54) {
        fprintf(fnum,"sdmotion:\n");
    }
    if (routine == 55) {
        fprintf(fnum,"sdfmotion:\n");
    }
    if (routine == 56) {
        fprintf(fnum,"sdequivht:\n");
    }
    if (routine == 57) {
        fprintf(fnum,"sdmassmat:\n");
    }
    if (routine == 58) {
        fprintf(fnum,"sdfrcmat:\n");
    }
    if (routine == 59) {
        fprintf(fnum,"sdrel2cart:\n");
    }
    if (routine == 60) {
        fprintf(fnum,"sdcomptrq:\n");
    }
    if (routine == 61) {
        fprintf(fnum,"sdfulltrq:\n");
    }
    if (routine == 62) {
        fprintf(fnum,"sdvrot:\n");
    }
    if (errnum == 1) {
        fprintf(fnum,"a tree joint pin axis was zero\n");
    }
    if (errnum == 2) {
        fprintf(fnum,"the 1st inboard pin for a loop joint was zero\n");
    }
    if (errnum == 3) {
        fprintf(fnum,"the 2nd inboard pin for a loop joint was zero\n");
    }
    if (errnum == 4) {
        fprintf(fnum,"the 3rd inboard pin for a loop joint was zero\n");
    }
    if (errnum == 5) {
        fprintf(fnum,"an inboard reference line was zero\n");
    }
    if (errnum == 6) {
        fprintf(fnum,"a set of loop joint axes was not right handed\n");
    }
    if (errnum == 7) {
        fprintf(fnum,"a loop joint bodypin was zero\n");
    }
    if (errnum == 8) {
        fprintf(fnum,"a loop joint body reference line was zero\n");
    }
    if (errnum == 9) {
        fprintf(fnum,"1st/2nd pins in a loop joint not perpendicular\n");
    }
    if (errnum == 10) {
        fprintf(fnum,"2nd/3rd pins in a loop joint not perpendicular\n");
    }
    if (errnum == 11) {
        fprintf(fnum,"1st/3rd pins in a loop joint not perpendicular\n");
    }
    if (errnum == 12) {
        fprintf(fnum,"a loop jt pin and inbref were not perpendicular\n");
    }
    if (errnum == 13) {
        fprintf(fnum,"a bodypin and bodyref were not perpendicular\n");
    }
    if (errnum == 14) {
        fprintf(fnum,"Euler parameters were far from normalized\n");
    }
    if (errnum == 15) {
        fprintf(fnum,"illegal body number\n");
    }
    if (errnum == 16) {
        fprintf(fnum,"illegal joint number\n");
    }
    if (errnum == 17) {
        fprintf(fnum,"illegal axis number\n");
    }
    if (errnum == 18) {
        fprintf(fnum,"illegal axis number for this joint\n");
    }
    if (errnum == 19) {
        fprintf(fnum,"tried to set non-variable (i.e., non-?) parameter\n");
    }
    if (errnum == 20) {
        fprintf(fnum,"prescribed motion was neither 0 (off) or 1 (on)\n");
    }
    if (errnum == 21) {
        fprintf(fnum,"illegal user constraint number\n");
    }
    if (errnum == 22) {
        fprintf(fnum,"sdinit must be called first\n");
    }
    if (errnum == 23) {
        fprintf(fnum,"sdstate must be called first\n");
    }
    if (errnum == 24) {
        fprintf(fnum,"sdderiv must be called first\n");
    }
    if (errnum == 25) {
        fprintf(fnum,"a gravity ? parameter is unspecified\n");
    }
    if (errnum == 26) {
        fprintf(fnum,"a ? mass is unspecified\n");
    }
    if (errnum == 27) {
        fprintf(fnum,"a ? inertia is unspecified\n");
    }
    if (errnum == 28) {
        fprintf(fnum,"a ? tree jt pin is unspecified\n");
    }
    if (errnum == 29) {
        fprintf(fnum,"a ? tree bodyToJoint vector is unspecified\n");
    }
    if (errnum == 30) {
        fprintf(fnum,"a ? tree inbToJoint vector is unspecified\n");
    }
    if (errnum == 31) {
        fprintf(fnum,"a ? prescribed tree jt axis is unspecified\n");
    }
    if (errnum == 32) {
        fprintf(fnum,"the stabvel ? parameter is unspecified\n");
    }
    if (errnum == 33) {
        fprintf(fnum,"the stabpos ? parameter is unspecified\n");
    }
    if (errnum == 34) {
        fprintf(fnum,"a ? loop jt inboard pin is unspecified\n");
    }
    if (errnum == 35) {
        fprintf(fnum,"a ? loop jt inbref is unspecified\n");
    }
    if (errnum == 36) {
        fprintf(fnum,"a ? loop jt bodypin is unspecified\n");
    }
    if (errnum == 37) {
        fprintf(fnum,"a ? loop jt bodyref is unspecified\n");
    }
    if (errnum == 38) {
        fprintf(fnum,"a ? loop jt bodyToJoint vector is unspecified\n");
    }
    if (errnum == 39) {
        fprintf(fnum,"a ? loop jt inbToJoint vector is unspecified\n");
    }
    if (errnum == 40) {
        fprintf(fnum,"a ? prescribed loop jt axis is unspecified\n");
    }
    if (errnum == 41) {
        fprintf(fnum,"Dynamics & Library File serial nos. differ\n");
    }
    if (errnum == 42) {
        fprintf(fnum,"Dynamics & Analysis File gen. times differ\n");
    }
    if (errnum == 43) {
        fprintf(fnum,"A tree gimbal joint is in gimbal lock\n");
    }
    if (errnum == 44) {
        fprintf(fnum,"A loop gimbal joint is in gimbal lock\n");
    }
    if (errnum == 45) {
        fprintf(fnum,"Bad relative coordinate number\n");
    }
    if (errnum == 46) {
        fprintf(fnum,"The vector about which to rotate was zero\n");
    }
    if (errnum == 47) {
        fprintf(fnum,"Singular mass matrix - bad inertialess body?\n");
    }
}

void Jimmy::sderror(int *routine,
    int *errnum)
{

    *errnum = lasterr;
    *routine = lastrou;
}

void Jimmy::sdprinterr(FILE *fnum)
{

    sdprerrmsg(fnum,lastrou,lasterr);
}

void Jimmy::sdclearerr(void)
{

    lasterr = 0;
    lastrou = 0;
}

void Jimmy::sdseterr(int routine,
    int errnum)
{

    if (lasterr == 0) {
        lasterr = errnum;
        lastrou = routine;
    }
}

/*
===========================================================
LDU decomposition scheme for solving Mx=b
  M: na X na symmetric, pos. definite, upper rt triangle filled
  b: na X 1
  x: na X 1 (returned)
Actual dimensions (n) may be larger, map says where to find
the na interesting elements.
===========================================================
*/

void Jimmy::sdldudcomp(int n,
    int na,
    int map[],
    double tol,
    double ld[],
    double sum[],
    double m[],
    double l[],
    double d[])
{
    int r,c,row,col,cm1,j,mj;
    double dlocal_temp,dlocal_tempi,ldlocal_temp,tsum;

    for (c = 0; c <= na-1; c++) {
        col = map[c];
        cm1 = c-1;

        for (r = c; r <= na-1; r++) {
            row = map[r];
            tsum = m[col*n+row];
            for (j = 0; j <= cm1; j++) {
                mj = map[j];
                tsum = tsum-ld[r*na+j]*l[col*n+mj];
            }
            sum[r] = tsum;
        }
        dlocal_temp = sum[c];
        dlocal_tempi = 0.;
        if (fabs(dlocal_temp) > tol)
            dlocal_tempi = 1./dlocal_temp;
        d[col] = dlocal_tempi;
        for (r = c; r <= na-1; r++) {
            row = map[r];
            ldlocal_temp = sum[r];
            ld[r*na+c] = ldlocal_temp;
            l[row*n+col] = ldlocal_temp*dlocal_tempi;
        }
    }
}

void Jimmy::sdldubsl(int n,
    int na,
    int map[],
    double l[],
    double b[],
    double x[])
{
    int i,j,im1,mi,mj;
    double sum;

    mi = map[0];
    x[mi] = b[mi];
    for (i = 1; i <= na-1; i++) {
        mi = map[i];
        im1 = i-1;
        sum = b[mi];
        for (j = 0; j <= im1; j++) {
            mj = map[j];
            sum = sum-l[mi*n+mj]*x[mj];
        }
        x[mi] = sum;
    }
}

void Jimmy::sdldubsd(int n,
    int na,
    int map[],
    double d[],
    double b[],
    double x[])
{
    int i,mi;

    for (i = 0; i <= na-1; i++) {
        mi = map[i];
        x[mi] = b[mi]*d[mi];
    }
}

void Jimmy::sdldubsu(int n,
    int na,
    int map[],
    double l[],
    double b[],
    double x[])
{
    int i,j,ip1,mi,mj;
    double sum;

    mi = map[na-1];
    x[mi] = b[mi];
    i = na-2;
    while (i  >=  0) {
        mi = map[i];
        ip1 = i+1;
        sum = b[mi];
        for (j = ip1; j <= na-1; j++) {
            mj = map[j];
            sum = sum-l[mj*n+mi]*x[mj];
        }
        x[mi] = sum;
        i = i-1;
    }
}

void Jimmy::sdldubslv(int n,
    int na,
    int map[],
    double work[],
    double l[],
    double d[],
    double b[],
    double x[])
{

    sdldubsl(n,na,map,l,b,work);
    sdldubsd(n,na,map,d,work,work);
    sdldubsu(n,na,map,l,work,x);
}

void Jimmy::sdlduslv(int n,
    int na,
    int map[],
    double tol,
    double work1[],
    double work2[],
    double m[],
    double b[],
    double l[],
    double d[],
    double x[])
{

    sdldudcomp(n,na,map,tol,work1,work2,m,l,d);
    sdldubslv(n,na,map,work2,l,d,b,x);
}

/*
===========================================================
QR decomposition scheme for solving Wx=b
  W is nra by nca
  b is nra by 1
  x (returned) is nca by 1
Actual dimensions (nr,nc) may be larger, mapr (mapc) says where
to find the nra (nca) interesting rows (columns).  On return, W is
overwritten by the Q and R matrices in compact form.  Solution yields
least squares residual for overdetermined systems.  Underdetermined
systems give a solution in which elements corresponding to redundant
or missing equations are set to 0. (Not necessarily the LS solution.)
===========================================================
*/

void Jimmy::sdqrdcomp(int nr,
    int nc,
    int nra,
    int nca,
    int mapr[],
    int mapc[],
    double w[],
    double local_qraux[],
    int local_jpvt[])
{
    int i,j,l,lp1,maxj,mi,mj,mlr,mlc,mmaxj,minrca;
    double maxnrm,nrmxl,t;

    for (j = 0; j <= nca-1; j++) {
        mj = mapc[j];
        local_jpvt[j] = j;
        t = 0.;
        for (l = 0; l <= nra-1; l++) {
            mlr = mapr[l];
            t = t+w[mlr*nc+mj]*w[mlr*nc+mj];
        }
        local_qraux[j] = sqrt(t);
    }
    if (nca  <  nra) {
        minrca = nca;
    } else {
        minrca = nra;
    }
    for (l = 0; l <= minrca-1; l++) {
        mlr = mapr[l];
        mlc = mapc[l];
        maxnrm = 0.;
        maxj = l;
        for (j = l; j <= nca-1; j++) {
            if (local_qraux[j]  >  maxnrm) {
                maxnrm = local_qraux[j];
                maxj = j;
            }
        }
        if (maxj  !=  l) {
            mmaxj = mapc[maxj];
            for (i = 0; i <= nra-1; i++) {
                mi = mapr[i];
                t = w[mi*nc+mlc];
                w[mi*nc+mlc] = w[mi*nc+mmaxj];
                w[mi*nc+mmaxj] = t;
            }
            local_qraux[maxj] = local_qraux[l];
            i = local_jpvt[maxj];
            local_jpvt[maxj] = local_jpvt[l];
            local_jpvt[l] = i;
        }
        local_qraux[l] = 0.;
        if (l  !=  nra-1) {
            t = 0.;
            for (i = l; i <= nra-1; i++) {
                mi = mapr[i];
                t = t+w[mi*nc+mlc]*w[mi*nc+mlc];
            }
            nrmxl = sqrt(t);
            if (nrmxl  !=  0.) {
                if (w[mlr*nc+mlc]  <  0.) {
                    nrmxl =  -nrmxl;
                }
                t = 1./nrmxl;
                for (i = l; i <= nra-1; i++) {
                    mi = mapr[i];
                    w[mi*nc+mlc] = t*w[mi*nc+mlc];
                }
                w[mlr*nc+mlc] = 1.+w[mlr*nc+mlc];
                lp1 = l+1;
                for (j = lp1; j <= nca-1; j++) {
                    mj = mapc[j];
                    t = 0.;
                    for (i = l; i <= nra-1; i++) {
                        mi = mapr[i];
                        t = t-w[mi*nc+mlc]*w[mi*nc+mj];
                    }
                    t = t/w[mlr*nc+mlc];
                    for (i = l; i <= nra-1; i++) {
                        mi = mapr[i];
                        w[mi*nc+mj] = w[mi*nc+mj]+t*w[mi*nc+mlc];
                    }
                    t = 0.;
                    for (i = lp1; i <= nra-1; i++) {
                        mi = mapr[i];
                        t = t+w[mi*nc+mj]*w[mi*nc+mj];
                    }
                    local_qraux[j] = sqrt(t);
                }
                local_qraux[l] = w[mlr*nc+mlc];
                w[mlr*nc+mlc] =  -nrmxl;
            }
        }
    }
}

void Jimmy::sdqrsl(int nr,
    int nc,
    int nra,
    int nca,
    int mapr[],
    int mapc[],
    int k,
    double work[],
    double w[],
    double local_qraux[],
    double b[],
    double x[])
{
    int i,j,jj,jm1,mir,mic,mjr,mjc,minrk;
    double t,tt;

    for (i = 0; i <= nra-1; i++) {
        mir = mapr[i];
        work[i] = b[mir];
    }
    minrk = nra-1;
    if (k  <  minrk) {
        minrk = k;
    }
    for (j = 0; j <= minrk-1; j++) {
        mjr = mapr[j];
        mjc = mapc[j];
        if (local_qraux[j]  !=  0.) {
            tt = w[mjr*nc+mjc];
            w[mjr*nc+mjc] = local_qraux[j];
            t = 0.;
            for (i = j; i <= nra-1; i++) {
                mir = mapr[i];
                t = t-w[mir*nc+mjc]*work[i];
            }
            t = t/w[mjr*nc+mjc];
            for (i = j; i <= nra-1; i++) {
                mir = mapr[i];
                work[i] = work[i]+t*w[mir*nc+mjc];
            }
            w[mjr*nc+mjc] = tt;
        }
    }
    for (j = 0; j <= k-1; j++) {
        mjc = mapc[j];
        x[mjc] = work[j];
    }
    for (jj = 0; jj <= k-1; jj++) {
        j = k-jj-1;
        jm1 = j-1;
        mjr = mapr[j];
        mjc = mapc[j];
        x[mjc] = x[mjc]/w[mjr*nc+mjc];
        t =  -x[mjc];
        for (i = 0; i <= jm1; i++) {
            mir = mapr[i];
            mic = mapc[i];
            x[mic] = x[mic]+t*w[mir*nc+mjc];
        }
    }
}

void Jimmy::sdqrbslv(int nr,
    int nc,
    int nra,
    int nca,
    int mapr[],
    int mapc[],
    double tol,
    double work[],
    int iwork[],
    double w[],
    double local_qraux[],
    int local_jpvt[],
    double b[],
    double x[],
    int *rank)
{
    int j,k,kk,mjc,mkkr,mkkc,minrca;
    double t;

    for (j = 0; j < nca; j++) {
        iwork[j] = local_jpvt[j];
    }
    if (nca  <  nra) {
        minrca = nca;
    } else {
        minrca = nra;
    }
    k = 0;
    mkkr = mapr[0];
    mkkc = mapc[0];
    t = tol*fabs(w[mkkr*nc+mkkc]);
    for (kk = 0; kk <= minrca-1; kk++) {
        mkkr = mapr[kk];
        mkkc = mapc[kk];
        if (fabs(w[mkkr*nc+mkkc])  <=  t) {
            break;
        } else {
            k = k+1;
        }
    }
    if (k  !=  0) {
        sdqrsl(nr,nc,nra,nca,mapr,mapc,k,work,w,local_qraux,b,x);
    }
    for (j = k; j <= nca-1; j++) {
        x[mapc[j]] = 0.;
    }
    for (j = 0; j <= nca-1; j++) {
        kk = iwork[j];
        while (kk  !=  j) {
            mjc = mapc[j];
            mkkc = mapc[kk];
            t = x[mjc];
            x[mjc] = x[mkkc];
            x[mkkc] = t;
            iwork[j] = iwork[kk];
            iwork[kk] = kk;
            kk = iwork[j];
        }
    }
    *rank = k;
}

void Jimmy::sdqrslv(int nr,
    int nc,
    int nra,
    int nca,
    int mapr[],
    int mapc[],
    double tol,
    int local_jpvt[],
    double local_qraux[],
    double work[],
    int iwork[],
    double w[],
    double b[],
    double x[],
    int *rank)
{

    sdqrdcomp(nr,nc,nra,nca,mapr,mapc,w,local_qraux,local_jpvt);
    sdqrbslv(nr,nc,nra,nca,mapr,mapc,tol,work,iwork,w,local_qraux,local_jpvt,b,x,rank);
}

/*
===========================================================
Linear equation solver for Wx=b
  W is nra by nca
  b is nra by 1
  x (returned) is nca by 1
Actual dimensions (nr,nc) may be larger, mapr (mapc) says where
to find the nra (nca) interesting rows (columns).  On return, W and
b are unchanged.  Solution yields least squares residual for
overdetermined systems and a least squares solution vector for
underdetermined systems.  If ndes > 0, the first nra-ndes rows
are `required' while the remaining ndes rows are `desired'.  The
returned solution minimizes the residual for the required rows,
then does the best it can on the desired rows.

The performance and numerical properties of this routine are
considerably worse than those of the qrslv routine.  However, it
works very well as a guide to the root finding routine.

Work arrays should be dimensioned as follows:
  dw is 2*(nra+nca)**2
  rw is 4*(nra+nca)
  iw is 3*(nra+nca)
===========================================================
*/

void Jimmy::sdlsslv(int nr,
    int nc,
    int nra,
    int nca,
    int ndes,
    int mapr[],
    int mapc[],
    double tol,
    double dw[],
    double rw[],
    int iw[],
    double w[],
    double b[],
    double x[])
{
    int i,j,k,nreq,dsiz,rank,mapi,mapj,mapk;
    int ix,wwt,dloc,ddt,local_qraux,work,rhs,soln,map,local_jpvt,iwork;

    nreq = nra-ndes;
    dsiz = nca+nreq;
    wwt = 0;
    dloc = 0;
    ddt = dloc+dsiz*dsiz;
    local_qraux = 0;
    work = local_qraux+nca+nra;
    rhs = work+nca+nra;
    soln = rhs+nca+nra;
    map = 0;
    local_jpvt = map+nca+nra;
    iwork = local_jpvt+nca+nra;
    if (ndes  ==  0) {
        for (i = 0; i <= nra-1; i++) {
            mapi = mapr[i];
            rw[rhs+i] = b[mapi];
            for (j = i; j <= nra-1; j++) {
                mapj = mapr[j];
                ix = wwt+i*nra+j;
                dw[ix] = 0.;
                for (k = 0; k <= nca-1; k++) {
                    mapk = mapc[k];
                    dw[ix] = dw[ix]+w[mapi*nc+mapk]*w[mapj*nc+mapk];
                }
                dw[wwt+j*nra+i] = dw[ix];
            }
            iw[map+i] = i;
        }
        sdqrslv(nra,nra,nra,nra,&iw[map],&iw[map],tol,&iw[local_jpvt],&rw[local_qraux],&rw[
          work],&iw[iwork],&dw[wwt],&rw[rhs],&rw[soln],&rank);
        for (i = 0; i <= nca-1; i++) {
            mapi = mapc[i];
            x[mapi] = 0.;
            for (j = 0; j <= nra-1; j++) {
                mapj = mapr[j];
                x[mapi] = x[mapi]+w[mapj*nc+mapi]*rw[soln+j];
            }
        }
    } else {
        for (i = 0; i <= nca-1; i++) {
            mapi = mapc[i];
            for (j = i; j <= nca-1; j++) {
                mapj = mapc[j];
                ix = dloc+i*dsiz+j;
                dw[ix] = 0.;
                for (k = 0; k <= ndes-1; k++) {
                    mapk = mapr[nreq+k];
                    dw[ix] = dw[ix]+w[mapk*nc+mapi]*w[mapk*nc+mapj];
                }
                dw[dloc+j*dsiz+i] = dw[ix];
            }
            for (j = 0; j <= nreq-1; j++) {
                mapj = mapr[j];
                ix = dloc+i*dsiz+(j+nca);
                dw[ix] = w[mapj*nc+mapi];
                dw[dloc+(j+nca)*dsiz+i] = dw[ix];
            }
            rw[rhs+i] = 0.;
            for (j = 0; j <= ndes-1; j++) {
                mapj = mapr[nreq+j];
                rw[rhs+i] = rw[rhs+i]+w[mapj*nc+mapi]*b[mapj];
            }
        }
        for (i = 0; i <= nreq-1; i++) {
            for (j = 0; j <= nreq-1; j++) {
                dw[dloc+(i+nca)*dsiz+(j+nca)] = 0.;
            }
            rw[rhs+(i+nca)] = b[mapr[i]];
        }
        for (i = 0; i <= dsiz-1; i++) {
            iw[map+i] = i;
            for (j = i; j <= dsiz-1; j++) {
                ix = ddt+i*dsiz+j;
                dw[ix] = 0.;
                for (k = 0; k <= dsiz-1; k++) {
                    dw[ix] = dw[ix]+dw[dloc+i*dsiz+k]*dw[dloc+j*dsiz+k];
                }
                dw[ddt+j*dsiz+i] = dw[ix];
            }
        }
        sdqrslv(dsiz,dsiz,dsiz,dsiz,&iw[map],&iw[map],tol,&iw[local_jpvt],&rw[local_qraux],&
          rw[work],&iw[iwork],&dw[ddt],&rw[rhs],&rw[soln],&rank);
        for (i = 0; i <= nca-1; i++) {
            mapi = mapc[i];
            x[mapi] = 0.;
            for (j = 0; j <= dsiz-1; j++) {
                x[mapi] = x[mapi]+dw[dloc+j*dsiz+i]*rw[soln+j];
            }
        }
    }
}

/* Utility routines for use with sdroot. */


void Jimmy::sdcalcerrs(double fval[],
    int nfunc,
    int ndes,
    int dnorm,
    double *maxderr,
    double *maxrerr,
    double *derrnorm)
{
    int i,nreq;
    double tmp;

    nreq = nfunc-ndes;
    *maxderr = 0.;
    *maxrerr = 0.;
    *derrnorm = 0.;
    for (i = 0; i < nreq; i++) {
        tmp = fabs(fval[i]);
        if (tmp > *maxrerr) {
            *maxrerr = tmp;
        }
    }
    for (i = 0; i < ndes; i++) {
        tmp = fabs(fval[nreq+i]);
        if (tmp > *maxderr) {
            *maxderr = tmp;
        }
        *derrnorm = *derrnorm+tmp;
    }
    if (dnorm == 1) {
        *derrnorm = *maxderr;
    }
}

void Jimmy::sdadjvars(void (Jimmy::*func)(double *, double *, double * ),
    double vars[],
    double param[],
    int nfunc,
    int ndes,
    int dnorm,
    int nvar,
    double deltas[],
    double step,
    double rerr,
    double tderr,
    double rtol,
    int *fcnt,
    double newvars[],
    double newerrs[])
{
    int i,cnt,alldone;
    double impr,maxchg,pmaxfact,maxfact,pmaxrerr,pderrnorm,maxderr,maxrerr,
      derrnorm,mag;

    maxfact = 1.;
    for (i = 0; i < nvar; i++) {
        impr = fabs(deltas[i]*step);
        maxchg = .1*fabs(vars[i])+1.;
        if (impr/maxchg > maxfact) {
            maxfact = impr/maxchg;
        }
    }
    maxfact = 1./maxfact;
    pmaxrerr = rerr;
    pderrnorm = tderr;
    pmaxfact = maxfact;
    cnt = 0;
    alldone = 0;
    retry: ;
    cnt = cnt+1;
    for (i = 0; i < nvar; i++) {
        impr = deltas[i]*step;
        newvars[i] = vars[i] - impr*maxfact;
    }
    (this->*func)(newvars,param,newerrs);
    *fcnt = *fcnt+1;
    if (alldone != 0) {
        return;
    }
    sdcalcerrs(newerrs,nfunc,ndes,dnorm,&maxderr,&maxrerr,&derrnorm);
    if ((pmaxrerr <= rtol) && (maxrerr <= rtol)) {
        impr = pderrnorm-derrnorm;
    } else {
        impr = pmaxrerr-maxrerr;
    }
    pmaxrerr = maxrerr;
    pderrnorm = derrnorm;
    if (impr <= 0.) {
        if (maxfact != pmaxfact) {
            maxfact = pmaxfact;
            alldone = 1;
            goto retry;
        }
    } else {
        if (maxfact < .5) {
            if (cnt < 5) {
                mag = 1.25;
            } else {
                if (cnt < 10) {
                    mag = 2.;
                } else {
                    mag = 10.;
                }
            }
            pmaxfact = maxfact;
            maxfact = mag*maxfact;
            if (maxfact > 1.) {
                maxfact = 1.;
            }
            goto retry;
        }
    }
}

void Jimmy::sdcalcjac(void (Jimmy::*func)(double *, double *, double * ),
    double vars[],
    double param[],
    int nfunc,
    int nvar,
    int lock[],
    double delta,
    double fval[],
    double ftmp[],
    double jw[],
    int *fcnt,
    double scale[])
{
    int i,j;
    double save,chg,vchg,maxelt;

    for (j = 0; j < nvar; j++) {
        if (lock[j] != 0) {
            for (i = 0; i < nfunc; i++) {
                jw[i*nvar+j] = 0.;
            }
        } else {
            save = vars[j];
            vchg = delta*(fabs(save)+1.);
            vars[j] = vars[j]+vchg;
            (this->*func)(vars,param,ftmp);
            *fcnt = *fcnt+1;
            vars[j] = save;
            for (i = 0; i < nfunc; i++) {
                chg = ftmp[i]-fval[i];
                if (fabs(chg) < 1e-13) {
                    jw[i*nvar+j] = 0.;
                } else {
                    jw[i*nvar+j] = chg/vchg;
                }
            }
        }
    }
    for (i = 0; i < nfunc; i++) {
        maxelt = 0.;
        for (j = 0; j < nvar; j++) {
            if (fabs(jw[i*nvar+j]) > maxelt) {
                maxelt = fabs(jw[i*nvar+j]);
            }
        }
        if (maxelt > 0.) {
            scale[i] = 1./maxelt;
            for (j = 0; j < nvar; j++) {
                jw[i*nvar+j] = jw[i*nvar+j]*scale[i];
            }
        } else {
            scale[i] = 1.;
        }
    }
}

/*
====================================================================
Root-finding scheme for solving a set of nfunc=nreq+ndes nonlinear
equations in nvar unknowns:
  r (v) = r (v) = ... = r (v) = 0    (actually |r | <= rtol)
   1       2             nreq                    i

  d (v) = d (v) = ... = d (v) = 0    (actually |d | <= dtol)
   1       2             ndes                    i
The r's are "required" functions while the d's are only "desired".
That is, we adjust the nvar variables v to find a solution which keeps
each of the r's below rtol, and keeps the d's as small as possible
without violating any of the r's.  Least squares residuals are atlocal_tempted
if the equations cannot be solved.  No guarantees can be made that
this routine will find a solution even if there is one.  The better
the initial values for the v's, the more likely it is to succeed and
the more quickly it will converge.

A single function func is provided which calculates all of the
r's and d's for the current v and returns the residuals.  A parameter
param is passed through unchanged to the function. 

The array lock has an element corresponding to each variable.  Any
variable which may be modified should have its corresponding lock
element set to 0.  If non-zero, the variable will not be altered here.

Maxeval sets an upper limit on the number of calls to func which may
be made.  The root finder only returns after complete iterations, so
it may make somewhat more than maxeval calls.  On return, the actual
number of calls made is returned in fcnt.  Err is returned 0 if we
successfully reduce all the r's to below rtol and all the d's to below
dtol.  If the r's are met but not the d's, we return with err=1, and if
the r's are not met we return err=2.

Work arrays should be dimensioned as follows:
  jw is nf*nv
  dw is 2*(nf+nv)**2
  rw is 7*nf+9*nv
  iw is 4*(nf+nv)
====================================================================
*/

void Jimmy::sdroot(void (Jimmy::*func)(double *, double *, double *),
    double vars[],
    double param[],
    int nfunc,
    int nvar,
    int ndesin,
    int lock[],
    double rtol,
    double dtol,
    int maxeval,
    double jw[],
    double dw[],
    double rw[],
    int iw[],
    double fret[],
    int *fcnt,
    int *err)
{
    int i,slowcnt,tooslow,ntrys,nreq,fixits,ndes,dnorm;
    int f1,f2,scale,deltav,guess,rvars,rdeltav,rguess,morerw,mapf,mapv,moreiw;
    double qrtol,maxderr,maxrerr,derrnorm,pmaxderr,pmaxrerr,pderrnorm,step,crude
      ,impr,rstep,preverr;

    if (ndesin < 0) {
        ndes = -ndesin;
        dnorm = 1;
    } else {
        ndes = ndesin;
        dnorm = 0;
    }
    nreq = nfunc-ndes;
    qrtol = 1e-13;
    *fcnt = 0;
    *err = 0;
    f1 = 0;
    f2 = f1+nfunc;
    scale = f2+nfunc;
    deltav = scale+nfunc;
    guess = deltav+nvar;
    rvars = guess+nvar;
    rdeltav = rvars+nvar;
    rguess = rdeltav+nvar;
    morerw = rguess+nvar;
    mapf = 0;
    mapv = mapf+nfunc;
    moreiw = mapv+nvar;
    for (i = 0; i < nfunc; i++) {
        iw[mapf+i] = i;
    }
    for (i = 0; i < nvar; i++) {
        iw[mapv+i] = i;
    }
    (this->*func)(vars,param,fret);
    *fcnt = *fcnt+1;
    sdcalcerrs(fret,nfunc,ndes,dnorm,&pmaxderr,&pmaxrerr,&pderrnorm);
    crude = 1e-6;
    for (ntrys = 0; ntrys < 2; ntrys++) {
        slowcnt = 0;
        step = 1.;
        for (;;) {
            if ((pmaxrerr <= rtol) && (pmaxderr <= dtol)) {
                return;
            }
            if (*fcnt >= maxeval) {
                goto givingUp;
            }
            sdcalcjac(func,vars,param,nfunc,nvar,lock,crude,fret,&rw[f1]
              ,jw,fcnt,&rw[scale]);
            for (i = 0; i < nfunc; i++) {
                rw[f1+i] = fret[i]*rw[scale+i];
            }
            sdlsslv(nfunc,nvar,nfunc,nvar,ndes,&iw[mapf],&iw[mapv],qrtol,dw,&rw[
              morerw],&iw[moreiw],jw,&rw[f1],&rw[deltav]);
            for (;;) {
                sdadjvars(func,vars,param,nfunc,ndes,dnorm,nvar,&rw[deltav]
                  ,step,pmaxrerr,pderrnorm,rtol,fcnt,&rw[guess],&rw[f1]);
                sdcalcerrs(&rw[f1],nfunc,ndes,dnorm,&maxderr,&maxrerr,&derrnorm)
                  ;
                if ((pderrnorm > derrnorm) && (pmaxrerr <= rtol) && (maxrerr > 
                  rtol) && (maxrerr <= .05)) {
                    for (i = 0; i < nvar; i++) {
                        rw[rvars+i] = rw[guess+i];
                    }
                    rstep = 1.;
                    preverr = maxrerr;
                    for (fixits = 0; fixits < 5; fixits++) {
                        sdcalcjac(func,&rw[rvars],param,nreq,nvar,lock,crude,&rw
                          [f1],&rw[f2],jw,fcnt,&rw[scale]);
                        for (i = 0; i < nreq; i++) {
                            rw[f2+i] = rw[f1+i]*rw[scale+i];
                        }
                        sdlsslv(nreq,nvar,nreq,nvar,0,&iw[mapf],&iw[mapv]
                          ,qrtol,dw,&rw[morerw],&iw[moreiw],jw,&rw[f2],&rw[
                          rdeltav]);
                        for (;;) {
                            sdadjvars(func,&rw[rvars]
                              ,param,nfunc,ndes,dnorm,nvar,&rw[rdeltav]
                              ,rstep,preverr,pderrnorm,rtol,fcnt,&rw[rguess],&rw
                              [f2]);
                            sdcalcerrs(&rw[f2],nfunc,ndes,dnorm,&maxderr,&
                              maxrerr,&derrnorm);
                            if (preverr-maxrerr >= rtol) {
                                break;
                            } else {
                                rstep = rstep*.5;
                                if (rstep < .01) {
                                    goto couldntFixReqs;
                                }
                            }
                        }
                        if (derrnorm > pderrnorm) {
                            goto couldntFixReqs;
                        }
                        for (i = 0; i < nfunc; i++) {
                            rw[f1+i] = rw[f2+i];
                        }
                        for (i = 0; i < nvar; i++) {
                            rw[rvars+i] = rw[rguess+i];
                        }
                        preverr = maxrerr;
                        if (maxrerr <= rtol) {
                            goto fixUpSucceeded;
                        }
                        rstep = rstep*2.;
                        if (rstep > 1.) {
                            rstep = 1.;
                        }
                    }
                    goto couldntFixReqs;
                    fixUpSucceeded: ;
                    for (i = 0; i < nvar; i++) {
                        rw[guess+i] = rw[rvars+i];
                    }
                }
                if ((pmaxrerr <= rtol) && (maxrerr <= rtol)) {
                    impr = pderrnorm-derrnorm;
                    if (impr < .1*dtol+.01*derrnorm) {
                        tooslow = 1;
                    } else {
                        tooslow = 0;
                    }
                } else {
                    impr = pmaxrerr-maxrerr;
                    if (impr < .01*rtol+.01*maxrerr) {
                        tooslow = 1;
                    } else {
                        tooslow = 0;
                    }
                }
                if (impr >= 0.) {
                    break;
                }
                couldntFixReqs: ;
                step = step*.5;
                if (ntrys == 1) {
                    if (step < 1e-5) {
                        goto nextcrude;
                    }
                } else {
                    if (step < .01) {
                        goto nextcrude;
                    }
                }
            }
            for (i = 0; i < nfunc; i++) {
                fret[i] = rw[f1+i];
            }
            for (i = 0; i < nvar; i++) {
                vars[i] = rw[guess+i];
            }
            pmaxderr = maxderr;
            pmaxrerr = maxrerr;
            pderrnorm = derrnorm;
            if (tooslow != 0) {
                slowcnt = slowcnt+1;
                if (slowcnt >= 3) {
                    goto nextcrude;
                }
            } else {
                slowcnt = 0;
            }
            step = step*2.;
            if (step > 1.) {
                step = 1.;
            }
        }
        nextcrude: ;
        crude = crude*.001;
    }
    givingUp: ;
    if (pmaxrerr > rtol) {
        *err = 2;
    } else {
        if (pmaxderr > dtol) {
            *err = 1;
        }
    }
}

/* Utility routine for use with sdfinteg and sdvinteg.  Work is 2*neq. */


void Jimmy::sdrk4m(void (Jimmy::*func)(double, double *, double *, double *, int* ),
    double time,
    double st[],
    double dst0[],
    double param[],
    double step,
    double nst[],
    int neq,
    double work[],
    double errs[],
    double *maxerr,
    int *which)
{
    int i,dst1,dst2,errf;
    double step2,step3,step6,step8,err,old,ast;

    dst1 = 0;
    dst2 = dst1+neq;
    step2 = step/2.;
    step3 = step/3.;
    step6 = step/6.;
    step8 = step/8.;
    for (i = 0; i < neq; i++) {
        nst[i] = st[i]+dst0[i]*step3;
    }
    (this->*func)(time+step3,nst,&work[dst1],param,&errf);
    for (i = 0; i < neq; i++) {
        nst[i] = st[i]+(dst0[i]+work[dst1+i])*step6;
    }
    (this->*func)(time+step3,nst,&work[dst1],param,&errf);
    for (i = 0; i < neq; i++) {
        nst[i] = st[i]+(dst0[i]+3.*work[dst1+i])*step8;
    }
    (this->*func)(time+step2,nst,&work[dst2],param,&errf);
    for (i = 0; i < neq; i++) {
        nst[i] = st[i]+(dst0[i]-3.*work[dst1+i]+4.*work[dst2+i])*step2;
    }
    (this->*func)(time+step,nst,&work[dst1],param,&errf);
    *maxerr = 0.;
    *which = 0;
    for (i = 0; i < neq; i++) {
        old = nst[i];
        nst[i] = st[i]+(dst0[i]+4.*work[dst2+i]+work[dst1+i])*step6;
        err = fabs(.2*(old-nst[i]));
        ast = fabs(nst[i]);
        if (ast > .1) {
            errs[i] = err/(ast+1e-20);
        } else {
            errs[i] = 10.*err;
        }
        if (errs[i] > *maxerr) {
            *maxerr = errs[i];
            *which = i;
        }
    }
}

/* A fixed-step integrator.  Work should be dimensioned 4*neq. */


void Jimmy::sdfinteg(void (Jimmy::*func)(double, double *, double *, double *, int *),
    double *time,
    double st[],
    double dst[],
    double param[],
    double step,
    int neq,
    double work[],
    double *errest,
    int *status)
{
    int i,which,nst,errs,morework;
    double ttime;

    nst = 0;
    errs = nst+neq;
    morework = errs+neq;
    ttime = *time;
    if (step > 0.) {
        sdrk4m(func,ttime,st,dst,param,step,&work[nst],neq,&work[morework],&work
          [errs],errest,&which);
        for (i = 0; i < neq; i++) {
            st[i] = work[nst+i];
        }
        ttime = ttime+step;
    } else {
        *errest = 0.;
    }
    *status = 0;
    (this->*func)(ttime,st,dst,param,status);
    *time = ttime;
}

/* A variable-step integrator.  Work should be dimensioned 6*neq. */

void Jimmy::sdvinteg(void (Jimmy::*func)(double, double *, double *, double *, int *),
    double *time,
    double st[],
    double dst[],
    double param[],
    double dt,
    double *step,
    int neqin,
    double tol,
    double work[],
    int *err,
    int *which)
{
    int i,wh,wh2,xst,xst2,xdst,errs,morework,errf,neq,earlyret;
    double ttime,ntime,xtime,tfin,stp,stp2,nstp,maxerr,minstep;

    if (neqin < 0) {
        neq = -neqin;
        earlyret = 1;
    } else {
        neq = neqin;
        earlyret = 0;
    }
    xst = 0;
    xst2 = xst+neq;
    xdst = xst2+neq;
    errs = xdst+neq;
    morework = errs+neq;
    minstep = 1e-10;
    ttime = *time;
    tfin = ttime+dt;
    stp = *step;
    if (stp < minstep) {
        stp = minstep;
    }
    *err = 0;
    if (dt <= 0.) {
        errf = 0;
        (this->*func)(ttime,st,dst,param,&errf);
        if (errf != 0) {
            *err = 3;
            *which = errf;
        }
        return;
    }
    while (ttime  <  tfin) {
        if (ttime+1.25*stp >= tfin) {
            stp = tfin-ttime;
        }
        nstp = stp;
        for (;;) {
            sdrk4m(func,ttime,st,dst,param,nstp,&work[xst],neq,&work[morework],&
              work[errs],&maxerr,&wh);
            xtime = ttime+nstp;
            if (maxerr <= tol) {
                errf = 0;
                (this->*func)(xtime,&work[xst],&work[xdst],param,&errf);
                if (errf == 0) {
                    stp2 = 2.*nstp;
                    if ((maxerr*64. <= tol) && (stp2 <= dt)) {
                        stp = stp2;
                    } else {
                        stp = nstp;
                    }
                    break;
                }
            }
            stp2 = nstp/2.;
            if (stp2 < minstep) {
                errf = 0;
                (this->*func)(xtime,&work[xst],&work[xdst],param,&errf);
                if (errf != 0) {
                    *err = 3;
                    *which = errf;
                    *time = ttime;
                    *step = nstp;
                    (this->*func)(ttime,st,dst,param,&errf);
                    return;
                }
                if (*err == 0) {
                    *err = 1;
                    *which = wh;
                }
                if (xtime+nstp > tfin) {
                    stp2 = tfin-xtime;
                } else {
                    stp2 = nstp;
                }
                ntime = xtime+stp2;
                if (ntime == xtime) {
                    stp = nstp;
                    break;
                }
                sdrk4m(func,xtime,&work[xst],&work[xdst],param,stp2,&work[xst2]
                  ,neq,&work[morework],&work[errs],&maxerr,&wh2);
                if (work[errs+wh] <= tol) {
                    (this->*func)(xtime,&work[xst],&work[xdst],param,&errf);
                    stp = nstp;
                    break;
                }
                *err = 2;
                *which = wh;
                *time = ttime;
                *step = nstp;
                (this->*func)(ttime,st,dst,param,&errf);
                return;
            } else {
                nstp = stp2;
            }
        }
        ttime = xtime;
        for (i = 0; i < neq; i++) {
            st[i] = work[xst+i];
            dst[i] = work[xdst+i];
        }
        if (stp >= minstep) {
            *step = stp;
        }
        ntime = ttime+stp;
        if (ntime == ttime) {
            ttime = tfin;
        }
        if (earlyret != 0) {
            *time = ttime;
            return;
        }
    }
    *time = tfin;
}

void Jimmy::sddc2ang(double dircos[3][3],
    double *a1,
    double *a2,
    double *a3)
{
    double th1,th2,th3,local_temp[10];

    if (((fabs(dircos[0][2])-1.) >= -1e-15)  ) {
        th1 = atan2(dircos[2][1],dircos[1][1]);
        if ((dircos[0][2] > 0.)  ) {
            local_temp[0] = 1.5707963267949;
        } else {
            local_temp[0] = -1.5707963267949;
        }
        th2 = local_temp[0];
        th3 = 0.;
    } else {
        th1 = atan2(-dircos[1][2],dircos[2][2]);
        th2 = asin(dircos[0][2]);
        th3 = atan2(-dircos[0][1],dircos[0][0]);
    }
    *a1 = th1;
    *a2 = th2;
    *a3 = th3;
}

void Jimmy::sddc2quat(double dircos[3][3],
    double *e1,
    double *e2,
    double *e3,
    double *e4)
{
    double tmp,tmp1,tmp2,tmp3,tmp4,local_temp[10];

    tmp = (dircos[0][0]+(dircos[1][1]+dircos[2][2]));
    if (((tmp >= dircos[0][0]) && ((tmp >= dircos[1][1]) && (tmp >= dircos[2][2]
      )))  ) {
        tmp1 = (dircos[2][1]-dircos[1][2]);
        tmp2 = (dircos[0][2]-dircos[2][0]);
        tmp3 = (dircos[1][0]-dircos[0][1]);
        tmp4 = (1.+tmp);
    } else {
        if (((dircos[0][0] >= dircos[1][1]) && (dircos[0][0] >= dircos[2][2]))  
          ) {
            tmp1 = (1.-(tmp-(2.*dircos[0][0])));
            tmp2 = (dircos[0][1]+dircos[1][0]);
            tmp3 = (dircos[0][2]+dircos[2][0]);
            tmp4 = (dircos[2][1]-dircos[1][2]);
        } else {
            if ((dircos[1][1] >= dircos[2][2])  ) {
                tmp1 = (dircos[0][1]+dircos[1][0]);
                tmp2 = (1.-(tmp-(2.*dircos[1][1])));
                tmp3 = (dircos[1][2]+dircos[2][1]);
                tmp4 = (dircos[0][2]-dircos[2][0]);
            } else {
                tmp1 = (dircos[0][2]+dircos[2][0]);
                tmp2 = (dircos[1][2]+dircos[2][1]);
                tmp3 = (1.-(tmp-(2.*dircos[2][2])));
                tmp4 = (dircos[1][0]-dircos[0][1]);
            }
        }
    }
    tmp = (1./sqrt(((tmp1*tmp1)+((tmp2*tmp2)+((tmp3*tmp3)+(tmp4*tmp4))))));
    *e1 = (tmp*tmp1);
    *e2 = (tmp*tmp2);
    *e3 = (tmp*tmp3);
    *e4 = (tmp*tmp4);
}

void Jimmy::sdang2dc(double a1,
    double a2,
    double a3,
    double dircos[3][3])
{
    double cos1,cos2,cos3,sin1,sin2,sin3;

    cos1 = cos(a1);
    cos2 = cos(a2);
    cos3 = cos(a3);
    sin1 = sin(a1);
    sin2 = sin(a2);
    sin3 = sin(a3);
    dircos[0][0] = (cos2*cos3);
    dircos[0][1] = -(cos2*sin3);
    dircos[0][2] = sin2;
    dircos[1][0] = ((cos1*sin3)+(sin1*(cos3*sin2)));
    dircos[1][1] = ((cos1*cos3)-(sin1*(sin2*sin3)));
    dircos[1][2] = -(cos2*sin1);
    dircos[2][0] = ((sin1*sin3)-(cos1*(cos3*sin2)));
    dircos[2][1] = ((cos1*(sin2*sin3))+(cos3*sin1));
    dircos[2][2] = (cos1*cos2);
}

void Jimmy::sdquat2dc(double ie1,
    double ie2,
    double ie3,
    double ie4,
    double dircos[3][3])
{
    double e1,e2,e3,e4,e11,e22,e33,e44,norm;

    e11 = ie1*ie1;
    e22 = ie2*ie2;
    e33 = ie3*ie3;
    e44 = ie4*ie4;
    norm = sqrt(e11+e22+e33+e44);
    if (norm == 0.) {
        e4 = 1.;
        norm = 1.;
    } else {
        e4 = ie4;
    }
    norm = 1./norm;
    e1 = ie1*norm;
    e2 = ie2*norm;
    e3 = ie3*norm;
    e4 = e4*norm;
    e11 = e1*e1;
    e22 = e2*e2;
    e33 = e3*e3;
    dircos[0][0] = 1.-(2.*(e22+e33));
    dircos[0][1] = 2.*(e1*e2-e3*e4);
    dircos[0][2] = 2.*(e1*e3+e2*e4);
    dircos[1][0] = 2.*(e1*e2+e3*e4);
    dircos[1][1] = 1.-(2.*(e11+e33));
    dircos[1][2] = 2.*(e2*e3-e1*e4);
    dircos[2][0] = 2.*(e1*e3-e2*e4);
    dircos[2][1] = 2.*(e2*e3+e1*e4);
    dircos[2][2] = 1.-(2.*(e11+e22));
}
double Jimmy::sdvdot(double ivec1[3],

    double ivec2[3])
{
    double dprod;

/* Compute the dot product of two vectors
*/
    dprod = ivec1[0]*ivec2[0]+ivec1[1]*ivec2[1]+ivec1[2]*ivec2[2];
    return dprod;
}
double Jimmy::sdvnorm(double ivec[3])

{
    double norm;

/* Compute the length (norm) of a vector
*/
    norm = sqrt(sdvdot(ivec,ivec));
    return norm;
}

void Jimmy::sdvcopy(double ivec[3],
    double ovec[3])
{

/* Copy vector ivec to vector ovec
*/
    ovec[0] = ivec[0];
    ovec[1] = ivec[1];
    ovec[2] = ivec[2];
}

void Jimmy::sdvset(double sclr1,
    double sclr2,
    double sclr3,
    double ovec[3])
{

/* Set ovec to [sclr1,sclr2,sclr3]
*/
    ovec[0] = sclr1;
    ovec[1] = sclr2;
    ovec[2] = sclr3;
}

void Jimmy::sdvadd(double ivec1[3],
    double ivec2[3],
    double ovec[3])
{

/* Add two vectors
*/
    ovec[0] = ivec1[0]+ivec2[0];
    ovec[1] = ivec1[1]+ivec2[1];
    ovec[2] = ivec1[2]+ivec2[2];
}

void Jimmy::sdvsub(double ivec1[3],
    double ivec2[3],
    double ovec[3])
{

/* Subtract two vectors
*/
    ovec[0] = ivec1[0]-ivec2[0];
    ovec[1] = ivec1[1]-ivec2[1];
    ovec[2] = ivec1[2]-ivec2[2];
}

void Jimmy::sdvmul(double sclr,
    double ivec[3],
    double ovec[3])
{

/* Multiply a vector by a scalar
*/
    ovec[0] = sclr*ivec[0];
    ovec[1] = sclr*ivec[1];
    ovec[2] = sclr*ivec[2];
}

void Jimmy::sdvaxpy(double sclr,
    double ivec1[3],
    double ivec2[3],
    double ovec[3])
{

/* Multiply a vector by a scalar and add in another vector
*/
    ovec[0] = sclr*ivec1[0]+ivec2[0];
    ovec[1] = sclr*ivec1[1]+ivec2[1];
    ovec[2] = sclr*ivec1[2]+ivec2[2];
}

void Jimmy::sdvcross(double ivec1[3],
    double ivec2[3],
    double ovec[3])
{
    double local_tempout[3];

/* Compute the cross product of two vectors
*/
    local_tempout[0] = ivec1[1]*ivec2[2]-ivec1[2]*ivec2[1];
    local_tempout[1] = ivec1[2]*ivec2[0]-ivec1[0]*ivec2[2];
    local_tempout[2] = ivec1[0]*ivec2[1]-ivec1[1]*ivec2[0];
    ovec[0] = local_tempout[0];
    ovec[1] = local_tempout[1];
    ovec[2] = local_tempout[2];
}

void Jimmy::sdvrot(double ivec[3],
    double rvec[3],
    double theta,
    double ovec[3])
{
    double norm,idotu,ctheta,stheta,dotcos,uvec[3],icosvec[3],isinvec[3],uxisin[
      3];

/* Rotate a vector ivec around vector rvec by angle theta
*/
    norm = sdvnorm(rvec);
    if (norm == 0.) {
        ovec[0] = ivec[0];
        ovec[1] = ivec[1];
        ovec[2] = ivec[2];
        sdseterr(62,46);
        return;
    }
    stheta = sin(theta);
    ctheta = cos(theta);
    sdvmul(stheta,ivec,isinvec);
    sdvmul(ctheta,ivec,icosvec);
    norm = 1./norm;
    sdvmul(norm,rvec,uvec);
    idotu = sdvdot(ivec,uvec);
    sdvcross(uvec,isinvec,uxisin);
    dotcos = idotu*(1.-ctheta);
    sdvaxpy(dotcos,uvec,icosvec,ovec);
    sdvadd(ovec,uxisin,ovec);
}

void Jimmy::sdserialno(int *serno)
{

    *serno = 30123;
}

int Jimmy::NQ(void){
    return ndof + nball;
}

int Jimmy::NU(void){
    return ndof;
}

int Jimmy::BQ(void){
	if (jtype[0]==6)	return 6;
	else				return 0;
}

int Jimmy::NBOD(void){
    return nbod;
}

int Jimmy::NM(void){
    return num_controls;
}

int Jimmy::NJNT(void){
    return nbod+nloop;
}

int Jimmy::joint(int idx){
    return idx_2_joint[idx];
}

int Jimmy::axis(int idx){
    return idx_2_axis[idx];
}

int Jimmy::aux(int idx){
    return idx_2_aux[idx];
}

int Jimmy::motor(int idx){
    return idx_2_motor[idx];
}

void Jimmy::set_aux(int *map){
    for(int i=0;i<num_controls;i++){
        idx_2_aux[i] = map[i];
    }
}

// double * Jimmy::get_q(int i){
//     return &q_local[i];
// }
// double * Jimmy::get_u(int i){
//     return &u_local[i];
// }
// double * Jimmy::get_qdot(int i){
//     return &qdot_local[i];
// }
// double * Jimmy::get_udot(int i){
//     return &udot_local[i];
// }

//Jimmy Jimmy::operator= (Jimmy x){
//    Jimmy y;
//    y.sdgtopo=x.sdgtopo;
//    y.sdginput=x.sdginput;
//    y.sdgstate=x.sdgstate;
//    y.sdglhs=x.sdglhs;
//    y.sdgrhs=x.sdgrhs;
//    y.sdgtemp=x.sdgtemp;
//    return y;
//}
