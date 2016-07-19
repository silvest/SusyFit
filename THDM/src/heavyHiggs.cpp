/* 
 * Copyright (C) 2015 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#include "heavyHiggs.h"
#include "StandardModel.h"



Hobs_ggF_H_tautau_ATLAS::Hobs_ggF_H_tautau_ATLAS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Hobs_ggF_H_tautau_ATLAS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->THoEX_ggF_H_tautau_ATLAS;
}

Robs_ggF_H_tautau_ATLAS::Robs_ggF_H_tautau_ATLAS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Robs_ggF_H_tautau_ATLAS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->R_ggF_H_tautau_ATLAS;
}



Hobs_ggF_H_tautau_CMS::Hobs_ggF_H_tautau_CMS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Hobs_ggF_H_tautau_CMS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->THoEX_ggF_H_tautau_CMS;
}

Robs_ggF_H_tautau_CMS::Robs_ggF_H_tautau_CMS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Robs_ggF_H_tautau_CMS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->R_ggF_H_tautau_CMS;
}



Hobs_bbF_H_tautau_ATLAS::Hobs_bbF_H_tautau_ATLAS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Hobs_bbF_H_tautau_ATLAS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->THoEX_bbF_H_tautau_ATLAS;
}

Robs_bbF_H_tautau_ATLAS::Robs_bbF_H_tautau_ATLAS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Robs_bbF_H_tautau_ATLAS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->R_bbF_H_tautau_ATLAS;
}



Hobs_bbF_H_tautau_CMS::Hobs_bbF_H_tautau_CMS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Hobs_bbF_H_tautau_CMS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->THoEX_bbF_H_tautau_CMS;
}

Robs_bbF_H_tautau_CMS::Robs_bbF_H_tautau_CMS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Robs_bbF_H_tautau_CMS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->R_bbF_H_tautau_CMS;
}



Hobs_pp_H_gaga_ATLAS::Hobs_pp_H_gaga_ATLAS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Hobs_pp_H_gaga_ATLAS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->THoEX_pp_H_gaga_ATLAS;
}

Robs_pp_H_gaga_ATLAS::Robs_pp_H_gaga_ATLAS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Robs_pp_H_gaga_ATLAS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->R_pp_H_gaga_ATLAS;
}



Hobs_ggF_H_gaga_CMS::Hobs_ggF_H_gaga_CMS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Hobs_ggF_H_gaga_CMS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->THoEX_ggF_H_gaga_CMS;
}

Robs_ggF_H_gaga_CMS::Robs_ggF_H_gaga_CMS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Robs_ggF_H_gaga_CMS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->R_ggF_H_gaga_CMS;
}



Hobs_mu_pp_H_VV_CMS::Hobs_mu_pp_H_VV_CMS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Hobs_mu_pp_H_VV_CMS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->THoEX_mu_pp_H_VV_CMS;
}

Robs_mu_pp_H_VV_CMS::Robs_mu_pp_H_VV_CMS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Robs_mu_pp_H_VV_CMS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->R_mu_pp_H_VV_CMS;
}



Hobs_ggF_H_ZZ_ATLAS::Hobs_ggF_H_ZZ_ATLAS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Hobs_ggF_H_ZZ_ATLAS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->THoEX_ggF_H_ZZ_ATLAS;
}

Robs_ggF_H_ZZ_ATLAS::Robs_ggF_H_ZZ_ATLAS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Robs_ggF_H_ZZ_ATLAS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->R_ggF_H_ZZ_ATLAS;
}



Hobs_VBF_H_ZZ_ATLAS::Hobs_VBF_H_ZZ_ATLAS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Hobs_VBF_H_ZZ_ATLAS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->THoEX_VBF_H_ZZ_ATLAS;
}

Robs_VBF_H_ZZ_ATLAS::Robs_VBF_H_ZZ_ATLAS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Robs_VBF_H_ZZ_ATLAS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->R_VBF_H_ZZ_ATLAS;
}



Hobs_ggF_H_WW_ATLAS::Hobs_ggF_H_WW_ATLAS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Hobs_ggF_H_WW_ATLAS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->THoEX_ggF_H_WW_ATLAS;
}

Robs_ggF_H_WW_ATLAS::Robs_ggF_H_WW_ATLAS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Robs_ggF_H_WW_ATLAS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->R_ggF_H_WW_ATLAS;
}



Hobs_VBF_H_WW_ATLAS::Hobs_VBF_H_WW_ATLAS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Hobs_VBF_H_WW_ATLAS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->THoEX_VBF_H_WW_ATLAS;
}

Robs_VBF_H_WW_ATLAS::Robs_VBF_H_WW_ATLAS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Robs_VBF_H_WW_ATLAS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->R_VBF_H_WW_ATLAS;
}



Hobs_ggF_H_hh_ATLAS::Hobs_ggF_H_hh_ATLAS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Hobs_ggF_H_hh_ATLAS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->THoEX_ggF_H_hh_ATLAS;
}

Robs_ggF_H_hh_ATLAS::Robs_ggF_H_hh_ATLAS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Robs_ggF_H_hh_ATLAS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->R_ggF_H_hh_ATLAS;
}



Hobs_pp_H_hh_CMS::Hobs_pp_H_hh_CMS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Hobs_pp_H_hh_CMS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->THoEX_pp_H_hh_CMS;
}

Robs_pp_H_hh_CMS::Robs_pp_H_hh_CMS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Robs_pp_H_hh_CMS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->R_pp_H_hh_CMS;
}



Hobs_ggF_H_hh_bbtautau_CMS::Hobs_ggF_H_hh_bbtautau_CMS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Hobs_ggF_H_hh_bbtautau_CMS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->THoEX_ggF_H_hh_bbtautau_CMS;
}

Robs_ggF_H_hh_bbtautau_CMS::Robs_ggF_H_hh_bbtautau_CMS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Robs_ggF_H_hh_bbtautau_CMS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->R_ggF_H_hh_bbtautau_CMS;
}



Hobs_pp_H_hh_bbbb_CMS::Hobs_pp_H_hh_bbbb_CMS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Hobs_pp_H_hh_bbbb_CMS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->THoEX_pp_H_hh_bbbb_CMS;
}

Robs_pp_H_hh_bbbb_CMS::Robs_pp_H_hh_bbbb_CMS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Robs_pp_H_hh_bbbb_CMS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->R_pp_H_hh_bbbb_CMS;
}



Hobs_pp_H_hh_gagabb_CMS::Hobs_pp_H_hh_gagabb_CMS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Hobs_pp_H_hh_gagabb_CMS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->THoEX_pp_H_hh_gagabb_CMS;
}

Robs_pp_H_hh_gagabb_CMS::Robs_pp_H_hh_gagabb_CMS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Robs_pp_H_hh_gagabb_CMS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->R_pp_H_hh_gagabb_CMS;
}



Hobs_ggF_H_tt_ATLAS::Hobs_ggF_H_tt_ATLAS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Hobs_ggF_H_tt_ATLAS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->THoEX_ggF_H_tt_ATLAS;
}

Robs_ggF_H_tt_ATLAS::Robs_ggF_H_tt_ATLAS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Robs_ggF_H_tt_ATLAS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->R_ggF_H_tt_ATLAS;
}



Hobs_bbF_H_bb_CMS::Hobs_bbF_H_bb_CMS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Hobs_bbF_H_bb_CMS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->THoEX_bbF_H_bb_CMS;
}

Robs_bbF_H_bb_CMS::Robs_bbF_H_bb_CMS(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Robs_bbF_H_bb_CMS::computeThValue()
{
    return myTHDM.getMyTHDMCache()->R_bbF_H_bb_CMS;
}



log10_ggF_H_tautau_TH::log10_ggF_H_tautau_TH(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double log10_ggF_H_tautau_TH::computeThValue()
{
    return log10(myTHDM.getMyTHDMCache()->ggF_H_tautau_TH);
}



log10_bbF_H_tautau_TH::log10_bbF_H_tautau_TH(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double log10_bbF_H_tautau_TH::computeThValue()
{
    return log10(myTHDM.getMyTHDMCache()->bbF_H_tautau_TH);
}



log10_pp_H_gaga_TH::log10_pp_H_gaga_TH(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double log10_pp_H_gaga_TH::computeThValue()
{
    return log10(myTHDM.getMyTHDMCache()->pp_H_gaga_TH);
}



log10_ggF_H_gaga_TH::log10_ggF_H_gaga_TH(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double log10_ggF_H_gaga_TH::computeThValue()
{
    return log10(myTHDM.getMyTHDMCache()->ggF_H_gaga_TH);
}



log10_mu_pp_H_VV_TH::log10_mu_pp_H_VV_TH(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double log10_mu_pp_H_VV_TH::computeThValue()
{
    return log10(myTHDM.getMyTHDMCache()->mu_pp_H_VV_TH);
}



log10_ggF_H_ZZ_TH::log10_ggF_H_ZZ_TH(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double log10_ggF_H_ZZ_TH::computeThValue()
{
    return log10(myTHDM.getMyTHDMCache()->ggF_H_ZZ_TH);
}



log10_VBF_H_ZZ_TH::log10_VBF_H_ZZ_TH(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double log10_VBF_H_ZZ_TH::computeThValue()
{
    return log10(myTHDM.getMyTHDMCache()->VBF_H_ZZ_TH);
}



log10_ggF_H_WW_TH::log10_ggF_H_WW_TH(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double log10_ggF_H_WW_TH::computeThValue()
{
    return log10(myTHDM.getMyTHDMCache()->ggF_H_WW_TH);
}



log10_VBF_H_WW_TH::log10_VBF_H_WW_TH(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double log10_VBF_H_WW_TH::computeThValue()
{
    return log10(myTHDM.getMyTHDMCache()->VBF_H_WW_TH);
}



log10_ggF_H_hh_TH::log10_ggF_H_hh_TH(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double log10_ggF_H_hh_TH::computeThValue()
{
    return log10(myTHDM.getMyTHDMCache()->ggF_H_hh_TH);
}



log10_pp_H_hh_TH::log10_pp_H_hh_TH(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double log10_pp_H_hh_TH::computeThValue()
{
    return log10(myTHDM.getMyTHDMCache()->pp_H_hh_TH);
}



log10_ggF_H_hh_bbtautau_TH::log10_ggF_H_hh_bbtautau_TH(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double log10_ggF_H_hh_bbtautau_TH::computeThValue()
{
    return log10(myTHDM.getMyTHDMCache()->ggF_H_hh_bbtautau_TH);
}



log10_pp_H_hh_bbbb_TH::log10_pp_H_hh_bbbb_TH(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double log10_pp_H_hh_bbbb_TH::computeThValue()
{
    return log10(myTHDM.getMyTHDMCache()->pp_H_hh_bbbb_TH);
}



log10_pp_H_hh_gagabb_TH::log10_pp_H_hh_gagabb_TH(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double log10_pp_H_hh_gagabb_TH::computeThValue()
{
    return log10(myTHDM.getMyTHDMCache()->pp_H_hh_gagabb_TH);
}



log10_ggF_H_tt_TH::log10_ggF_H_tt_TH(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double log10_ggF_H_tt_TH::computeThValue()
{
    return log10(myTHDM.getMyTHDMCache()->ggF_H_tt_TH);
}



log10_bbF_H_bb_TH::log10_bbF_H_bb_TH(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double log10_bbF_H_bb_TH::computeThValue()
{
    return log10(myTHDM.getMyTHDMCache()->bbF_H_bb_TH);
}



Gamma_HH_THDM::Gamma_HH_THDM(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double Gamma_HH_THDM::computeThValue()
{
    return myTHDM.getMyTHDMCache()->GammaHtot;
}



//rHH_gaga_THDM::rHH_gaga_THDM(const StandardModel& SM_i)
//: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
//{}
//
//double rHH_gaga_THDM::computeThValue()
//{
//    return myTHDM.getMyTHDMCache()->rHH_gaga;
//}



rHH_gg_THDM::rHH_gg_THDM(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double rHH_gg_THDM::computeThValue()
{
    return myTHDM.getMyTHDMCache()->rHH_gg;
}



BR_HH_hh_THDM::BR_HH_hh_THDM(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double BR_HH_hh_THDM::computeThValue()
{
    return myTHDM.getMyTHDMCache()->Br_Htohh;
}



BR_HH_AA_THDM::BR_HH_AA_THDM(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double BR_HH_AA_THDM::computeThValue()
{
    return myTHDM.getMyTHDMCache()->Br_HtoAA;
}



BR_HH_HpHm_THDM::BR_HH_HpHm_THDM(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double BR_HH_HpHm_THDM::computeThValue()
{
    return myTHDM.getMyTHDMCache()->Br_HtoHpHm;
}



BR_HH_AZ_THDM::BR_HH_AZ_THDM(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double BR_HH_AZ_THDM::computeThValue()
{
    return myTHDM.getMyTHDMCache()->Br_HtoAZ;
}



BR_HH_HpW_THDM::BR_HH_HpW_THDM(const StandardModel& SM_i)
: ThObservable(SM_i),myTHDM(static_cast<const THDM&> (SM_i))
{}

double BR_HH_HpW_THDM::computeThValue()
{
    return myTHDM.getMyTHDMCache()->Br_HtoHpW;
}
