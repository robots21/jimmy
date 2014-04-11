#ifndef _SDMODEL_H
#define _SDMODEL_H
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
class SDModel{

public:
        int *idx_2_joint;
        int *idx_2_axis;
        int *idx_2_aux;
        int *idx_2_motor;
        int num_controls;
		double *q_local, *u_local, *qdot_local, *udot_local, *u_zero;

    public:

		//SDModel();
        //~SDModel();
        
virtual void sdinit(void)=0;
virtual void sdst2ang(double st[],    double stang[])=0;
virtual void sdang2st(double stang[],    double st[])=0;
virtual void sdnrmsterr(double st[],    double normst[],    int routine)=0;
virtual void sdnormst(double st[],    double normst[])=0;
virtual void sdstate(double timein,    double qin[],    double uin[])=0;
virtual void sdqdot(double oqdot[])=0;
virtual void sdu2qdot(double uin[],    double oqdot[])=0;
virtual void sdpsstate(double lqin[])=0;
virtual void sddovpk(void)=0;
virtual void sddoltau(void)=0;
virtual void sddoiner(void)=0;
virtual void sddofs0(void)=0;
virtual void sddomm(int routine)=0;
virtual void sddommldu(int routine)=0;
virtual void sdlhs(int routine)=0;
virtual void sdmfrc(double imult[])=0;
virtual void sdequivht(double tau[])=0;
virtual void sdfs0(void)=0;
virtual void sdfsmult(void)=0;
virtual void sdfsfull(void)=0;
virtual void sdfsgenmult(void)=0;
virtual void sdfsgenfull(void)=0;
virtual void sdfulltrq(double udotin[],    double multin[],    double trqout[])=0;
virtual void sdcomptrq(double udotin[],    double trqout[])=0;
virtual void sdmulttrq(double multin[],    double trqout[])=0;
virtual void sdrhs(void)=0;
virtual void sdmassmat(double *mmat)=0;
virtual void sdfrcmat(double fmat[])=0;
virtual void sdpseudo(double lqout[],    double luout[])=0;
virtual void sdpsqdot(double lqdout[])=0;
virtual void sdpsudot(double ludout[])=0;
virtual void sdperr(double errs[])=0;
virtual void sdverr(double errs[])=0;
virtual void sdaerr(double errs[])=0;
virtual int sdchkbnum(int routine,    int bnum)=0;
virtual int sdchkjnum(int routine,    int jnum)=0;
virtual int sdchkucnum(int routine,    int ucnum)=0;
virtual int sdchkjaxis(int routine,    int jnum,    int axnum)=0;
virtual int sdchkjpin(int routine,    int jnum,    int pinno)=0;
virtual int sdindx(int joint,    int axis)=0;
virtual void sdpresacc(int joint,    int axis,    double prval)=0;
virtual void sdpresvel(int joint,    int axis,    double prval)=0;
virtual void sdprespos(int joint,    int axis,    double prval)=0;
virtual void sdgetht(int joint,    int axis,    double *torque)=0;
virtual void sdhinget(int joint,    int axis,    double torque)=0;
virtual void sdpointf(int body,    double point[3],    double force[3])=0;
virtual void sdbodyt(int body,    double torque[3])=0;
virtual void sddoww(int routine)=0;
virtual void sdxudot0(int routine,    double oudot0[])=0;
virtual void sdudot0(double oudot0[])=0;
virtual void sdsetudot(double iudot[])=0;
virtual void sdxudotm(int routine,    double imult[],    double oudotm[])=0;
virtual void sdudotm(double imult[],    double oudotm[])=0;
virtual void sdderiv(double oqdot[],    double oudot[])=0;
virtual void sdresid(double eqdot[],    double eudot[],    double emults[],    double resid[])=0;
virtual void sdmult(double omults[],    int *owrank,    int omultmap[])=0;
virtual void sdreac(double force[][3],    double torque[][3])=0;
virtual void sdmom(double lm[3],    double am[3],    double *ke)=0;
virtual void sdsys(double *mtoto,    double cm[3],    double icm[3][3])=0;
virtual void sdpos(int body,    double pt[3],    double loc[3])=0;
virtual void sdvel(int body,    double pt[3],    double velo[3])=0;
virtual void sdorient(int body,    double dircos[3][3])=0;
virtual void sdangvel(int body,    double avel[3])=0;
virtual void sdtrans(int frbod,    double ivec[3],    int tobod,    double ovec[3])=0;
virtual void sdrel2cart(int coord,    int body,    double point[3],    double linchg[3],    double rotchg[3])=0;
virtual void sdacc(int body,    double pt[3],    double accel[3])=0;
virtual void sdangacc(int body,    double aacc[3])=0;
virtual void sdgrav(double gravin[3])=0;
virtual void sdmass(int body,    double massin)=0;
virtual void sdiner(int body,    double inerin[3][3])=0;
virtual void sdbtj(int joint,    double btjin[3])=0;
virtual void sditj(int joint,    double itjin[3])=0;
virtual void sdpin(int joint,    int pinno,    double pinin[3])=0;
virtual void sdpres(int joint,    int axis,    int presin)=0;
virtual void sdconschg(void)=0;
virtual void sdstab(double velin,    double posin)=0;
virtual void sdgetgrav(double gravout[3])=0;
virtual void sdgetmass(int body,    double *massout)=0;
virtual void sdgetiner(int body,    double inerout[3][3])=0;
virtual void sdgetbtj(int joint,    double btjout[3])=0;
virtual void sdgetitj(int joint,    double itjout[3])=0;
virtual void sdgetpin(int joint,    int pinno,    double pinout[3])=0;
virtual void sdgetpres(int joint,    int axis,    int *presout)=0;
virtual void sdgetstab(double *velout,    double *posout)=0;
virtual void sdinfo(int info[50])=0;
virtual void sdjnt(int joint,    int info[50],    int tran[6])=0;
virtual void sdcons(int consno,    int info[50])=0;
virtual void sdgentime(int *gentm)=0;

// analysis routines
//virtual void sdposfunc(double *vars,    double *param,    double *resid);
//virtual void sdvelfunc(double *vars,    double *param,    double *resid);
//virtual void sdstatfunc(double *vars,    double *param,    double *resid);
//virtual void sdstdyfunc(double *vars,    double *param,    double *resid);
//virtual void sdmotfunc(double time,    double *state,    double *dstate,    double *param,    int *status);
//virtual void sdassemble(double time,    double *state,    int *lock,    double tol,    int maxevals,    int *fcnt,    int *err);
//virtual void sdinitvel(double time,    double *state,    int *lock,    double tol,    int maxevals,    int *fcnt,    int *err);
//virtual void sdstatic(double time,    double *state,    int *lock,    double ctol,    double tol,    int maxevals,    int *fcnt,    int *err);
//virtual void sdsteady(double time,    double *state,    int *lock,    double ctol,    double tol,    int maxevals,    int *fcnt,    int *err);
//virtual void sdmotion(double *time,    double *state,    double *dstate,    double dt,    double ctol,    double tol,    int *flag,    int *err);
virtual void sdfmotion(double *time,    double *state,    double *dstate,    double dt,    double ctol,    int *flag,    double *errest,    int *err) {
	printf("This class has not implemented sdfmotion\n");
	exit(-1);
}

        // user-defined functions
        //virtual void sduforce(double t, double *q, double *u)=0;
        //virtual void sdumotion(double t, double *q, double *u)=0;
        //
        //virtual void sduaerr(double t, double *q, double *u, double *udot, double *errs)=0;
        //virtual void sduconsfrc(double t, double *q, double *u, double *mults)=0;
        //virtual void sduderiv(double t, double *y, double *dy, double *params, int *status)=0;
        //virtual void sdueval(double *vars, double *params, double *redid)=0;
        //virtual void sduperr(double t, double *q, double *errs)=0;
        //virtual void sduverr(double t, double *q, double *u, double *errs)=0;
        
        virtual void sderror(int *routine, int *errnum)=0;
        virtual void sdclearerr(void)=0;
        
        virtual void set_aux(int *map)=0; // pass in an array of aux numbers
        
        //NAME operator= (NAME);
        
        virtual int NQ(void)=0;   // get number of q coordinates
        virtual int NU(void)=0;   // get number of u coordinates
		virtual int BQ(void)=0;	// number of base coordinates (6 if floating, 0 otherwise)
        virtual int NM(void)=0;   // number of control joints ("motors")
        virtual int NBOD(void)=0;   // number of bodies
        virtual int NJNT(void)=0;
        
        virtual int joint(int idx)=0; // get joint number of coordinate
        virtual int axis(int idx)=0;  // get axis of coordinate
        virtual int aux(int idx)=0; // get aux number of coordinate
        virtual int motor(int idx)=0; // get the coordinate of motor

        //virtual double *get_massmat_ptr(void)=0; // get pointer to mass matrix
};
#else
typedef struct SDModel SDModel;
#endif





#endif