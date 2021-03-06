#ifndef _Jimmy_H
#define _Jimmy_H

/*
 * Generated by a program, not intended for human
 */

#include "SDModel.h"

typedef struct {
    int ground_,nbod_,ndof_,ncons_,nloop_,nldof_,nloopc_,nball_,nlball_,npres_,
      nuser_;
    int jtype_[21],inb_[21],outb_[21],njntdof_[21],njntc_[21],njntp_[21],firstq_
      [21],ballq_[21],firstm_[21],firstp_[21];
    int trans_[26];
} sdgtopo_Jimmy_t;
typedef struct {
    double grav_[3],mk_[21],ik_[21][3][3],pin_[26][3];
    double rk_[21][3],ri_[21][3],pres_[26],stabvel_,stabpos_;
    int mfrcflg_,roustate_,vpkflg_,inerflg_,mmflg_,mmlduflg_,wwflg_,ltauflg_,
      fs0flg_,ii_,mmap_[26];
    int gravq_[3],mkq_[21],ikq_[21][3][3],pinq_[26][3],rkq_[21][3],riq_[21][3],
      presq_[26],stabvelq_,stabposq_;
    double mtot_,psmkg_,rhead_[21][3],rcom_[21][3],mkrcomt_[21][3][3],psikg_[3][
      3],psrcomg_[3],psrkg_[3],psrig_[3],psmk_[26],psik_[26][3][3],psrcom_[26][3
      ],psrk_[26][3],psri_[26][3];
} sdginput_Jimmy_t;
typedef struct {
    double curtim_,q_[27],qn_[27],u_[26],cnk_[26][3][3],cnb_[21][3][3];
    double rnk_[26][3],vnk_[26][3],wk_[26][3],rnb_[21][3],vnb_[21][3],wb_[21][3]
      ,wbrcom_[21][3],com_[3],rnkg_[3];
    double Cik_[26][3][3],rikt_[26][3][3],Iko_[26][3][3],mkrk_[26][3][3],Cib_[21
      ][3][3];
    double Wkk_[26][3],Vkk_[26][3],dik_[26][3],rpp_[26][3],rpk_[26][3],rik_[26][
      3],rik2_[26][3];
    double rpri_[26][3],Wik_[26][3],Vik_[26][3],Wirk_[26][3],rkWkk_[26][3],
      Wkrpk_[26][3],VikWkr_[26][3];
    double perr_[1],verr_[1],aerr_[1],mult_[1],ufk_[21][3],utk_[21][3],mfk_[21][
      3],mtk_[21][3];
    double utau_[26],mtau_[26],uacc_[26],uvel_[26],upos_[27];
    double s6_,c6_,s7_,c7_,s8_,c8_,s9_,c9_,s10_,c10_,s11_,c11_,s12_,c12_,s13_,
      c13_,s14_,c14_,s15_,c15_,s16_,c16_,s17_,c17_,s18_,c18_,s19_,c19_,s20_,c20_
      ,s21_,c21_,s22_,c22_,s23_,c23_,s24_,c24_,s25_,c25_;
} sdgstate_Jimmy_t;
typedef struct {
    double fs0_[26],qdot_[27],Otk_[26][3],Atk_[26][3],AiOiWi_[26][3],Fstar_[26][
      3];
    double Tstar_[26][3],Fstark_[26][3],Tstark_[26][3],IkWk_[26][3],WkIkWk_[26][
      3],gk_[26][3],IkbWk_[21][3],WkIkbWk_[21][3];
    double w0w0_[21],w1w1_[21],w2w2_[21],w0w1_[21],w0w2_[21],w1w2_[21];
    double w00w11_[21],w00w22_[21],w11w22_[21],ww_[1][1],qraux_[1];
    double mm_[26][26],mlo_[26][26],mdi_[26],IkWpk_[26][26][3],works_[26],
      workss_[26][26];
    double Wpk_[26][26][3],Vpk_[26][26][3],VWri_[26][26][3];
    int wmap_[1],multmap_[1],jpvt_[1],wsiz_,wrank_;
} sdglhs_Jimmy_t;
typedef struct {
    double fs_[26],udot_[26],tauc_[26],dyad_[21][3][3],fc_[26][3],tc_[26][3];
    double ank_[26][3],onk_[26][3],Onkb_[26][3],AOnkri_[26][3],Ankb_[26][3],
      AnkAtk_[26][3],anb_[21][3],onb_[21][3],dyrcom_[21][3];
    double ffk_[26][3],ttk_[26][3],fccikt_[26][3],ffkb_[21][3],ttkb_[21][3];
} sdgrhs_Jimmy_t;
typedef struct {
    double temp_[3000],tmat1_[3][3],tmat2_[3][3],tvec1_[3],tvec2_[3],tvec3_[3],
      tvec4_[3],tvec5_[3];
    double tsc1_,tsc2_,tsc3_;
} sdgtemp_Jimmy_t;
typedef struct {
    int lasterr_,lastrou_;
} sdgerror_Jimmy_t;

#ifdef __cplusplus
class Jimmy: public SDModel{
     protected:
        sdgtopo_Jimmy_t sdgtopo;
        sdginput_Jimmy_t sdginput;
        sdgstate_Jimmy_t sdgstate;
        sdglhs_Jimmy_t sdglhs;
        sdgrhs_Jimmy_t sdgrhs;
        sdgtemp_Jimmy_t sdgtemp;
        sdgerror_Jimmy_t sdgerror;
        int *idx_2_joint;
        int *idx_2_axis;
        int *idx_2_aux;
        int *idx_2_motor;
        int num_controls;
                        
     public:
        Jimmy();
        ~Jimmy();
        
void sdinit(void);
void sdst2ang(double st[27],    double stang[26]);
void sdang2st(double stang[26],    double st[27]);
void sdnrmsterr(double st[27],    double normst[27],    int routine);
void sdnormst(double st[27],    double normst[27]);
void sdstate(double timein,    double qin[27],    double uin[26]);
void sdqdot(double oqdot[27]);
void sdu2qdot(double uin[26],    double oqdot[27]);
void sdpsstate(double lqin[1]);
void sddovpk(void);
void sddoltau(void);
void sddoiner(void);
void sddofs0(void);
void sddomm(int routine);
void sddommldu(int routine);
void sdlhs(int routine);
void sdmfrc(double imult[1]);
void sdequivht(double tau[26]);
void sdfs0(void);
void sdfsmult(void);
void sdfsfull(void);
void sdfsgenmult(void);
void sdfsgenfull(void);
void sdfulltrq(double udotin[26],    double multin[1],    double trqout[26]);
void sdcomptrq(double udotin[26],    double trqout[26]);
void sdmulttrq(double multin[1],    double trqout[26]);
void sdrhs(void);
void sdmassmat(double *mmat);
void sdfrcmat(double fmat[26]);
void sdpseudo(double lqout[1],    double luout[1]);
void sdpsqdot(double lqdout[1]);
void sdpsudot(double ludout[1]);
void sdperr(double errs[1]);
void sdverr(double errs[1]);
void sdaerr(double errs[1]);
int sdchkbnum(int routine,    int bnum);
int sdchkjnum(int routine,    int jnum);
int sdchkucnum(int routine,    int ucnum);
int sdchkjaxis(int routine,    int jnum,    int axnum);
int sdchkjpin(int routine,    int jnum,    int pinno);
int sdindx(int joint,    int axis);
void sdpresacc(int joint,    int axis,    double prval);
void sdpresvel(int joint,    int axis,    double prval);
void sdprespos(int joint,    int axis,    double prval);
void sdgetht(int joint,    int axis,    double *torque);
void sdhinget(int joint,    int axis,    double torque);
void sdpointf(int body,    double point[3],    double force[3]);
void sdbodyt(int body,    double torque[3]);
void sddoww(int routine);
void sdxudot0(int routine,    double oudot0[26]);
void sdudot0(double oudot0[26]);
void sdsetudot(double iudot[26]);
void sdxudotm(int routine,    double imult[1],    double oudotm[26]);
void sdudotm(double imult[1],    double oudotm[26]);
void sdderiv(double oqdot[27],    double oudot[26]);
void sdresid(double eqdot[27],    double eudot[26],    double emults[1],    double resid[53]);
void sdmult(double omults[1],    int *owrank,    int omultmap[1]);
void sdreac(double force[21][3],    double torque[21][3]);
void sdmom(double lm[3],    double am[3],    double *ke);
void sdsys(double *mtoto,    double cm[3],    double icm[3][3]);
void sdpos(int body,    double pt[3],    double loc[3]);
void sdvel(int body,    double pt[3],    double velo[3]);
void sdorient(int body,    double dircos[3][3]);
void sdangvel(int body,    double avel[3]);
void sdtrans(int frbod,    double ivec[3],    int tobod,    double ovec[3]);
void sdrel2cart(int coord,    int body,    double point[3],    double linchg[3],    double rotchg[3]);
void sdacc(int body,    double pt[3],    double accel[3]);
void sdangacc(int body,    double aacc[3]);
void sdgrav(double gravin[3]);
void sdmass(int body,    double massin);
void sdiner(int body,    double inerin[3][3]);
void sdbtj(int joint,    double btjin[3]);
void sditj(int joint,    double itjin[3]);
void sdpin(int joint,    int pinno,    double pinin[3]);
void sdpres(int joint,    int axis,    int presin);
void sdconschg(void);
void sdstab(double velin,    double posin);
void sdgetgrav(double gravout[3]);
void sdgetmass(int body,    double *massout);
void sdgetiner(int body,    double inerout[3][3]);
void sdgetbtj(int joint,    double btjout[3]);
void sdgetitj(int joint,    double itjout[3]);
void sdgetpin(int joint,    int pinno,    double pinout[3]);
void sdgetpres(int joint,    int axis,    int *presout);
void sdgetstab(double *velout,    double *posout);
void sdinfo(int info[50]);
void sdjnt(int joint,    int info[50],    int tran[6]);
void sdcons(int consno,    int info[50]);
void sdgentime(int *gentm);
// analysis routines
void sdposfunc(double vars[26],    double param[1],    double resid[1]);
void sdvelfunc(double vars[26],    double param[28],    double resid[1]);
void sdstatfunc(double vars[26],    double param[27],    double resid[26]);
void sdstdyfunc(double vars[52],    double param[1],    double resid[26]);
void sdmotfunc(double time,    double state[53],    double dstate[53],    double param[1],    int *status);
void sdassemble(double time,    double state[53],    int lock[26],    double tol,    int maxevals,    int *fcnt,    int *err);
void sdinitvel(double time,    double state[53],    int lock[26],    double tol,    int maxevals,    int *fcnt,    int *err);
void sdstatic(double time,    double state[53],    int lock[26],    double ctol,    double tol,    int maxevals,    int *fcnt,    int *err);
void sdsteady(double time,    double state[53],    int lock[52],    double ctol,    double tol,    int maxevals,    int *fcnt,    int *err);
void sdmotion(double *time,    double state[53],    double dstate[53],    double dt,    double ctol,    double tol,    int *flag,    int *err);
void sdfmotion(double *time,    double state[53],    double dstate[53],    double dt,    double ctol,    int *flag,    double *errest,    int *err);
void sdprerrmsg(FILE *fnum,    int routine,    int errnum);
void sderror(int *routine,    int *errnum);
void sdprinterr(FILE *fnum);
void sdclearerr(void);
void sdseterr(int routine,    int errnum);
void sdldudcomp(int n,    int na,    int map[],    double tol,    double ld[],    double sum[],    double m[],    double l[],    double d[]);
void sdldubsl(int n,    int na,    int map[],    double l[],    double b[],    double x[]);
void sdldubsd(int n,    int na,    int map[],    double d[],    double b[],    double x[]);
void sdldubsu(int n,    int na,    int map[],    double l[],    double b[],    double x[]);
void sdldubslv(int n,    int na,    int map[],    double work[],    double l[],    double d[],    double b[],    double x[]);
void sdlduslv(int n,    int na,    int map[],    double tol,    double work1[],    double work2[],    double m[],    double b[],    double l[],    double d[],    double x[]);
void sdqrdcomp(int nr,    int nc,    int nra,    int nca,    int mapr[],    int mapc[],    double w[],    double local_qraux[],    int local_jpvt[]);
void sdqrsl(int nr,    int nc,    int nra,    int nca,    int mapr[],    int mapc[],    int k,    double work[],    double w[],    double local_qraux[],    double b[],    double x[]);
void sdqrbslv(int nr,    int nc,    int nra,    int nca,    int mapr[],    int mapc[],    double tol,    double work[],    int iwork[],    double w[],    double local_qraux[],    int local_jpvt[],    double b[],    double x[],    int *rank);
void sdqrslv(int nr,    int nc,    int nra,    int nca,    int mapr[],    int mapc[],    double tol,    int local_jpvt[],    double local_qraux[],    double work[],    int iwork[],    double w[],    double b[],    double x[],    int *rank);
void sdlsslv(int nr,    int nc,    int nra,    int nca,    int ndes,    int mapr[],    int mapc[],    double tol,    double dw[],    double rw[],    int iw[],    double w[],    double b[],    double x[]);
void sdcalcerrs(double fval[],    int nfunc,    int ndes,    int dnorm,    double *maxderr,    double *maxrerr,    double *derrnorm);
void sdadjvars(void (Jimmy::*func)(double *, double *, double * ),    double vars[],    double param[],    int nfunc,    int ndes,    int dnorm,    int nvar,    double deltas[],    double step,    double rerr,    double tderr,    double rtol,    int *fcnt,    double newvars[],    double newerrs[]);
void sdcalcjac(void (Jimmy::*func)(double *, double *, double * ),    double vars[],    double param[],    int nfunc,    int nvar,    int lock[],    double delta,    double fval[],    double ftmp[],    double jw[],    int *fcnt,    double scale[]);
void sdroot(void (Jimmy::*func)(double *, double *, double *),    double vars[],    double param[],    int nfunc,    int nvar,    int ndesin,    int lock[],    double rtol,    double dtol,    int maxeval,    double jw[],    double dw[],    double rw[],    int iw[],    double fret[],    int *fcnt,    int *err);
void sdrk4m(void (Jimmy::*func)(double, double *, double *, double *, int* ),    double time,    double st[],    double dst0[],    double param[],    double step,    double nst[],    int neq,    double work[],    double errs[],    double *maxerr,    int *which);
void sdfinteg(void (Jimmy::*func)(double, double *, double *, double *, int *),    double *time,    double st[],    double dst[],    double param[],    double step,    int neq,    double work[],    double *errest,    int *status);
void sdvinteg(void (Jimmy::*func)(double, double *, double *, double *, int *),    double *time,    double st[],    double dst[],    double param[],    double dt,    double *step,    int neqin,    double tol,    double work[],    int *err,    int *which);
void sddc2ang(double dircos[3][3],    double *a1,    double *a2,    double *a3);
void sddc2quat(double dircos[3][3],    double *e1,    double *e2,    double *e3,    double *e4);
void sdang2dc(double a1,    double a2,    double a3,    double dircos[3][3]);
void sdquat2dc(double ie1,    double ie2,    double ie3,    double ie4,    double dircos[3][3]);
double sdvdot(double ivec1[3],    double ivec2[3]);
double sdvnorm(double ivec[3]);
void sdvcopy(double ivec[3],    double ovec[3]);
void sdvset(double sclr1,    double sclr2,    double sclr3,    double ovec[3]);
void sdvadd(double ivec1[3],    double ivec2[3],    double ovec[3]);
void sdvsub(double ivec1[3],    double ivec2[3],    double ovec[3]);
void sdvmul(double sclr,    double ivec[3],    double ovec[3]);
void sdvaxpy(double sclr,    double ivec1[3],    double ivec2[3],    double ovec[3]);
void sdvcross(double ivec1[3],    double ivec2[3],    double ovec[3]);
void sdvrot(double ivec[3],    double rvec[3],    double theta,    double ovec[3]);
void sdserialno(int *serno);

        // user-defined functions
void sduforce(double t, double *q, double *u) {}
	  //        void sdumotion(double t, double *q, double *u);
        


        void sduderiv(double t, double *y, double *dy, double *params, int *status);
        void sdueval(double *vars, double *params, double *redid);
        
        void set_aux(int *map); // pass in an array of aux numbers
        
  //      Jimmy operator= (Jimmy);
        
        int NQ(void);   // get number of q coordinates
        int NU(void);   // get number of u coordinates
		int BQ(void);	// number of base coordinates (6 if floating, 0 otherwise)
        int NM(void);   // number of control joints ("motors")
        int NBOD(void);   // number of bodies
        int NJNT(void);     // number of joints
        
        int joint(int idx); // get joint number of coordinate
        int axis(int idx);  // get axis of coordinate
        int aux(int idx); // get aux number of coordinate
        int motor(int idx); // get the coordinate of motor

	//void massmat( double *mat );

	
	//#include "Jimmy_ext.h"

		//double **M;
        
//         double * get_q(int i);
//         double * get_u(int i);
//         double * get_qdot(int i);
//         double * get_udot(int i);
//         double *q_local, *u_local, *qdot_local, *udot_local, *u_zero;
};
#else
typedef struct Jimmy Jimmy;
#endif



#endif
