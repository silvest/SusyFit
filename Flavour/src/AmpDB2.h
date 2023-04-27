/*
 * Copyright (C) 2012 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#ifndef AMPDB2_H
#define	AMPDB2_H

class StandardModel;
#include "StandardModel.h"
#include "OrderScheme.h"
#include "gslpp.h"

/**
 * @addtogroup Flavour
 * @brief A module for all the flavour observables implemented in HEPfit.
 * @details This module has several flavour physics observables which include
 * quark flavour violation in the beauty, charm and strange sectors. This includes 
 * the evolutors, Hamiltonians and low energy observables.
 * @{
 */


/**
 * @class AmpDB2
 * @ingroup Flavour
 * @brief \f$ | \Delta B = 2 | \f$ Amplitude Class
 * @author HEPfit Collaboration
 * @copyright GNU General Public License
 * @details This class is related to the calculation of the \f$ B_{d,s}-\bar{B}_{d,s}\f$
 * mixing.
 *
 */

class AmpDB2 {
public:
    /**
    * @brief Constructor.
    * @param[in] SM_i a reference to an object of type StandardModel
    */
    AmpDB2(const StandardModel& SM_i);

    /**
    * @brief The value of @f$M_{12}^{bd}@f$.
    * @param[in] order the %QCD order of the computation
    * @return @f$M_{12}^{bd}@f$
    */
    gslpp::complex getM12_Bd(orders order){
        return M12_Bd(order);
    }

    /**
    * @brief The value of @f$M_{12}^{bs}@f$.
    * @param[in] order the %QCD order of the computation
    * @return @f$M_{12}^{bs}@f$
    */
    gslpp::complex getM12_Bs(orders order){
        return M12_Bs(order);
    }
    
    /**
    * @brief The value of @f$\frac{\Gamma_{12},M_{12}}^{bd}@f$.
    * @param[in] order the %QCD order of the computation
    * @return @f$\frac{\Gamma_{12},M_{12}}^{bd}@f$
    */
    gslpp::complex getGamma12oM12_Bd(orders order){
        return Gamma12oM12_Bd(order);
    }

    /**
    * @brief The value of @f$\frac{\Gamma_{12},M_{12}}^{bs}@f$.
    * @param[in] order the %QCD order of the computation
    * @return @f$\frac{\Gamma_{12},M_{12}}^{bs}@f$
    */
    gslpp::complex getGamma12oM12_Bs(orders order){
        return Gamma12oM12_Bs(order);
    }
    
    double getAsl_d(orders order){
        return Asl_d(order);
    }
    
    double getAsl_s(orders order){
        return Asl_s(order);
    }

    gslpp::complex getPBd(){
        return PBd();
    }

    gslpp::complex getPBs(){
        return PBs();
    }
    
protected:
    /**
    * @brief A method to compute @f$M_{12}^{bd}@f$.
    * @param[in] order the %QCD order of the computation
    * @return @f$M_{12}^{bd}@f$
    */
    gslpp::complex M12_Bd(orders order);
    
    /**
    * @brief A method to compute @f$M_{12}^{bs}@f$.
    * @param[in] order the %QCD order of the computation
    * @return @f$M_{12}^{bs}@f$
    */
    gslpp::complex M12_Bs(orders order);

    /**
    * @brief A method to compute @f$\frac{\Gamma_{12},M_{12}}^{bd}@f$.
    * @param[in] order the %QCD order of the computation
    * @return @f$\frac{\Gamma_{12},M_{12}}^{bd}@f$
    */
    gslpp::complex Gamma12oM12_Bd(orders order);
    

    /**
    * @brief A method to compute @f$\frac{\Gamma_{12},M_{12}}^{bs}@f$.
    * @param[in] order the %QCD order of the computation
    * @return @f$\frac{\Gamma_{12},M_{12}}^{bs}@f$
    */
    gslpp::complex Gamma12oM12_Bs(orders order);
    
    
    /**
    * @brief A method to compute the CP asymmetry in semileptonic B decays in the SM
    * @param[in] order the %QCD order of the computation
    * @return @f$A_{sl}@f$
    */
    double Asl_d(orders order);
    
    /**
    * @brief A method to compute the CP asymmetry in semileptonic B_s decays in the SM
    * @param[in] order the %QCD order of the computation
    * @return @f$A_{sl}@f$
    */
    double Asl_s(orders order);
    
    /**
    * @brief A method to compute the ratio of the absolute value of the $B_s$ mixing amplitude over the Standard Model value.
    * @param[in] order the %QCD order of the computation
    * @return @f$\vert (M_{12}^{bs})_\mathrm{full}/(M_{12}^{bs})_\mathrm{SM}\vert@f$
    */
    gslpp::complex RBs(orders order);
    gslpp::complex PBd();
    gslpp::complex PBs();


private:
    const StandardModel& mySM;/**< Model type */
    
    gslpp::complex C_1_SM;/**<Wilson coeffients H_{eff}^{DF2} @f$C_1@f$*/
    
public:
    enum quark {d,s};
    enum quarks {cc, cu, uu};
    
private:    
    double mu_1;
    double mu_2;    
    gslpp::vector<gslpp::complex> c(quark q); //requires computeCKMelements(); before use
    gslpp::complex delta_1overm(quark q); //requires computeCKMelements(); before use
    
//resummation to use z_bar instead of z and  eliminate z ln z terms (hep-ph/0612167)
    bool flag_resumz;
    
//access calculated function values
    double F0(quarks qq, int k, int i, int j);
    double F1(quarks qq, int k, int i, int j);
    double F(quarks qq, int k, int i, int j);
    double P(quarks qq, int k, int i, int j);
    gslpp::complex D(quarks qq, int k);
    gslpp::complex deltas_1overm(quarks qq, quark q);
    gslpp::vector<double> me = gslpp::vector<double>(5, 0.);
    gslpp::vector<double> me_R = gslpp::vector<double>(4, 0.);
    
//calculate function values
    void computeF0();
    void computeF1();   
    void computeP();
    void computeD(); //requires F and P
    void compute_deltas_1overm(quark q);
    void compute_matrixelements(quark q);

//array for caching function values
    double cacheF0[24];
    double cacheF1[24];
    double cacheP[84];
    gslpp::complex cacheD[6];
    gslpp::complex cache_deltas_1overm[6];

//returns position in the corresponding array
    int indexF(quarks qq, int k, int i, int j);
    int indexP(quarks qq, int k, int i, int j);
    int indexD(quarks qq, int k);
    int index_deltas(quarks qq, quark q);

    //CKM elements
    void computeCKMandMasses(); //requires mu_1

    gslpp::complex VtbVtd;
    gslpp::complex VtbVts;
    gslpp::complex VtbVtd2;
    gslpp::complex VtbVts2;
    gslpp::complex VcbVcd;
    gslpp::complex VcbVcs;
    gslpp::complex VcbVcd2;
    gslpp::complex VcbVcs2;
    
    //cache for often used values
    double Gf2;
    double z2; //z^2
    double z3; //z^3
    double z4; //z^4
    double logz; //log(z)
    double log1minusz; //log(1-z)
    double log1minus4z; //log(1-4z)
    double oneminusz2; //(1 - z)^2
    double sqrt1minus4z; //(1-4z)^(1/2)
    double sigma; //(1 - sqrt1minus4z)/(1 + sqrt1minus4z)
    double logsigma; //log(sigma)
    double log2sigma; //log^2(sigma)
    double x_1; //mu_1/Mb
    double x_2; //mu_2/Mb
    double logx_1; //log(x_1)
    double logx_2; //log(x_2)
    double Dilogz; //Li_2(z)
    double Dilogsigma; //Li_2(sigma)
    double Dilogsigma2; //Li_2(sigma^2)
    const double M_PI2 = M_PI * M_PI;
    double as_4pi; //alpha_s/(4Pi)
    
    double Md;
    double Ms;
    double Mc;
    double Mb;
    double Mt;
    double MW;
    double MB;
    double MB_s;
    double rhob;
    double etab;
    double Mb2;
    double Mt2;
    double MB2;
    double MW2;
    
    //Buras basis pdf/hep-ph/9512380v1
    void computeWilsonCoeffs();
    void computeWilsonCoeffsDB1bsg();
    gslpp::complex cacheC[6];
    gslpp::complex C_8G; //check
    gslpp::complex C(int i);
    
    //combinations of Wilson coeffients arxiv.org/abs/hep-ph/0202010
    gslpp::complex K_1;
    gslpp::complex K_2;
    gslpp::complex K_1prime;
    gslpp::complex K_2prime;
    gslpp::complex K_3prime;
    
    double z;
    gslpp::complex K12;

    double B1;
    double B2; //or B_s
    double B_sprime;
    double eta_B;
    double eta_Bb;
    double S_0;
    
    gslpp::complex kappa;
};

/**
 * @}
 */

#endif	/* AMPDB2_H */

