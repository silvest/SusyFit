/*
 * Copyright (C) 2014 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#include "NP_couplings.h"
#include "NPbase.h"


//-----  Zff couplings observables  ----------

/* -------------------------------------*/

deltagZveveL::deltagZveveL(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZveveL called with a class whose parent is not NPbase");
}


deltagZveveL::~deltagZveveL()
{}

double deltagZveveL::computeThValue()
{
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getLeptons(StandardModel::NEUTRINO_1));
    //double dgA = myNPbase->deltaGA_f(SM.getLeptons(StandardModel::NEUTRINO_1));
    double dg = myNPbase->deltaGL_f_mu(SM.getLeptons(StandardModel::NEUTRINO_1), mu);
    double gSM = (SM.getLeptons(StandardModel::NEUTRINO_1)).getIsospin() 
    - ((SM.getLeptons(StandardModel::NEUTRINO_1)).getCharge())*sw2_tree;
    
    //return 0.5*(dgV + dgA)/gSM;
    return dg/gSM;
}

/* -------------------------------------*/

deltagZvmuvmuL::deltagZvmuvmuL(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZvmuvmuL called with a class whose parent is not NPbase");
}


deltagZvmuvmuL::~deltagZvmuvmuL()
{}

double deltagZvmuvmuL::computeThValue()
{
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getLeptons(StandardModel::NEUTRINO_2));
    //double dgA = myNPbase->deltaGA_f(SM.getLeptons(StandardModel::NEUTRINO_2));
    double dg = myNPbase->deltaGL_f_mu(SM.getLeptons(StandardModel::NEUTRINO_2), mu);
    double gSM = (SM.getLeptons(StandardModel::NEUTRINO_2)).getIsospin() 
    - ((SM.getLeptons(StandardModel::NEUTRINO_2)).getCharge())*sw2_tree;
    
    //return 0.5*(dgV + dgA)/gSM;
    return dg/gSM;
}

/* -------------------------------------*/

deltagZvtavtaL::deltagZvtavtaL(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZvtavtaL called with a class whose parent is not NPbase");
}


deltagZvtavtaL::~deltagZvtavtaL()
{}

double deltagZvtavtaL::computeThValue()
{
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getLeptons(StandardModel::NEUTRINO_3));
    //double dgA = myNPbase->deltaGA_f(SM.getLeptons(StandardModel::NEUTRINO_3));   
    double dg = myNPbase->deltaGL_f_mu(SM.getLeptons(StandardModel::NEUTRINO_3), mu);
    double gSM = (SM.getLeptons(StandardModel::NEUTRINO_3)).getIsospin() 
    - ((SM.getLeptons(StandardModel::NEUTRINO_3)).getCharge())*sw2_tree;
    
    //return 0.5*(dgV + dgA)/gSM;
    return dg/gSM;
}


/* -------------------------------------*/

deltagZeeL::deltagZeeL(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZeeL called with a class whose parent is not NPbase");
}


deltagZeeL::~deltagZeeL()
{}

double deltagZeeL::computeThValue()
{
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getLeptons(StandardModel::ELECTRON));
    //double dgA = myNPbase->deltaGA_f(SM.getLeptons(StandardModel::ELECTRON));
    double dg = myNPbase->deltaGL_f_mu(SM.getLeptons(StandardModel::ELECTRON), mu);
    double gSM = (SM.getLeptons(StandardModel::ELECTRON)).getIsospin() 
    - ((SM.getLeptons(StandardModel::ELECTRON)).getCharge())*sw2_tree;
    
    //return 0.5*(dgV + dgA)/gSM;
    return dg/gSM;
}

/* -------------------------------------*/

deltagZeeR::deltagZeeR(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZeeR called with a class whose parent is not NPbase");
}


deltagZeeR::~deltagZeeR()
{}

double deltagZeeR::computeThValue()
{
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getLeptons(StandardModel::ELECTRON));
    //double dgA = myNPbase->deltaGA_f(SM.getLeptons(StandardModel::ELECTRON));
    double dg = myNPbase->deltaGR_f_mu(SM.getLeptons(StandardModel::ELECTRON), mu);
    double gSM = - ((SM.getLeptons(StandardModel::ELECTRON)).getCharge())*sw2_tree;

    //return 0.5*(dgV - dgA)/gSM;
    return dg/gSM;
}

/* -------------------------------------*/

deltagZmumuL::deltagZmumuL(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZmumuL called with a class whose parent is not NPbase");
}


deltagZmumuL::~deltagZmumuL()
{}

double deltagZmumuL::computeThValue()
{
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getLeptons(StandardModel::MU));
    //double dgA = myNPbase->deltaGA_f(SM.getLeptons(StandardModel::MU));
    double dg = myNPbase->deltaGL_f_mu(SM.getLeptons(StandardModel::MU), mu);
    double gSM = (SM.getLeptons(StandardModel::MU)).getIsospin() 
    - ((SM.getLeptons(StandardModel::MU)).getCharge())*sw2_tree;
    
    //return 0.5*(dgV + dgA)/gSM;
    return dg/gSM;
}

/* -------------------------------------*/

deltagZmumuR::deltagZmumuR(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZmumuR called with a class whose parent is not NPbase");
}


deltagZmumuR::~deltagZmumuR()
{}

double deltagZmumuR::computeThValue()
{
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getLeptons(StandardModel::MU));
    //double dgA = myNPbase->deltaGA_f(SM.getLeptons(StandardModel::MU));
    double dg = myNPbase->deltaGR_f_mu(SM.getLeptons(StandardModel::MU), mu);
    double gSM = - ((SM.getLeptons(StandardModel::MU)).getCharge())*sw2_tree;

    //return 0.5*(dgV - dgA)/gSM;
    return dg/gSM;
}

/* -------------------------------------*/

deltagZtataL::deltagZtataL(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZtataL called with a class whose parent is not NPbase");
}


deltagZtataL::~deltagZtataL()
{}

double deltagZtataL::computeThValue()
{
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getLeptons(StandardModel::TAU));
    //double dgA = myNPbase->deltaGA_f(SM.getLeptons(StandardModel::TAU));
    double dg = myNPbase->deltaGL_f_mu(SM.getLeptons(StandardModel::TAU), mu);
    double gSM = (SM.getLeptons(StandardModel::TAU)).getIsospin() 
    - ((SM.getLeptons(StandardModel::TAU)).getCharge())*sw2_tree;
    
    //return 0.5*(dgV + dgA)/gSM;
    return dg/gSM;
}

/* -------------------------------------*/

deltagZtataR::deltagZtataR(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZtataR called with a class whose parent is not NPbase");
}


deltagZtataR::~deltagZtataR()
{}

double deltagZtataR::computeThValue()
{
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getLeptons(StandardModel::TAU));
    //double dgA = myNPbase->deltaGA_f(SM.getLeptons(StandardModel::TAU));
    double dg = myNPbase->deltaGR_f_mu(SM.getLeptons(StandardModel::TAU), mu);
    double gSM = - ((SM.getLeptons(StandardModel::TAU)).getCharge())*sw2_tree;
    
    //return 0.5*(dgV - dgA)/gSM;
    return dg/gSM;
}


/* -------------------------------------*/

deltagZuuL::deltagZuuL(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZuuL called with a class whose parent is not NPbase");
}


deltagZuuL::~deltagZuuL()
{}

double deltagZuuL::computeThValue()
{
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getQuarks(StandardModel::UP));
    //double dgA = myNPbase->deltaGA_f(SM.getQuarks(StandardModel::UP));
    double dg = myNPbase->deltaGL_f_mu(SM.getQuarks(StandardModel::UP), mu);
    double gSM = (SM.getQuarks(StandardModel::UP)).getIsospin() 
    - ((SM.getQuarks(StandardModel::UP)).getCharge())*sw2_tree;
    
    //return 0.5*(dgV + dgA)/gSM;
    return dg/gSM;
}

/* -------------------------------------*/

deltagZuuR::deltagZuuR(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZuuR called with a class whose parent is not NPbase");
}


deltagZuuR::~deltagZuuR()
{}

double deltagZuuR::computeThValue()
{
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getQuarks(StandardModel::UP));
    //double dgA = myNPbase->deltaGA_f(SM.getQuarks(StandardModel::UP));
    double dg = myNPbase->deltaGR_f_mu(SM.getQuarks(StandardModel::UP), mu);
    double gSM = - ((SM.getQuarks(StandardModel::UP)).getCharge())*sw2_tree;

    //return 0.5*(dgV - dgA)/gSM;
    return dg/gSM;
}

/* -------------------------------------*/

deltagZuuV::deltagZuuV(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZuuV called with a class whose parent is not NPbase");
}


deltagZuuV::~deltagZuuV()
{}

double deltagZuuV::computeThValue()
{
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getQuarks(StandardModel::UP));
    double dgL = myNPbase->deltaGL_f_mu(SM.getQuarks(StandardModel::UP), mu);
    double dgR = myNPbase->deltaGR_f_mu(SM.getQuarks(StandardModel::UP), mu);
    double gSM = ((SM.getQuarks(StandardModel::UP)).getIsospin()) * (1.0 - 4.0*fabs(SM.getQuarks(StandardModel::UP).getCharge())*sw2_tree);

    //return dgV/gSM;
    return (dgL + dgR)/gSM;
}


/* -------------------------------------*/

deltagZuuA::deltagZuuA(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZuuA called with a class whose parent is not NPbase");
}


deltagZuuA::~deltagZuuA()
{}

double deltagZuuA::computeThValue()
{
    //double dgA = myNPbase->deltaGA_f(SM.getQuarks(StandardModel::UP));
    double dgL = myNPbase->deltaGL_f_mu(SM.getQuarks(StandardModel::UP), mu);
    double dgR = myNPbase->deltaGR_f_mu(SM.getQuarks(StandardModel::UP), mu);
    double gSM = (SM.getQuarks(StandardModel::UP)).getIsospin();

    //return dgA/gSM;
    return (dgL - dgR)/gSM;
}

/* -------------------------------------*/

deltagZccL::deltagZccL(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZccLs called with a class whose parent is not NPbase");
}


deltagZccL::~deltagZccL()
{}

double deltagZccL::computeThValue()
{
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getQuarks(StandardModel::CHARM));
    //double dgA = myNPbase->deltaGA_f(SM.getQuarks(StandardModel::CHARM));
    double dg = myNPbase->deltaGL_f_mu(SM.getQuarks(StandardModel::CHARM), mu);
    double gSM = (SM.getQuarks(StandardModel::CHARM)).getIsospin() 
    - ((SM.getQuarks(StandardModel::CHARM)).getCharge())*sw2_tree;
    
    //return 0.5*(dgV + dgA)/gSM;
    return dg/gSM;
}

/* -------------------------------------*/

deltagZccR::deltagZccR(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZccR called with a class whose parent is not NPbase");
}


deltagZccR::~deltagZccR()
{}

double deltagZccR::computeThValue()
{
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getQuarks(StandardModel::CHARM));
    //double dgA = myNPbase->deltaGA_f(SM.getQuarks(StandardModel::CHARM));
    double dg = myNPbase->deltaGR_f_mu(SM.getQuarks(StandardModel::CHARM), mu);
    double gSM = - ((SM.getQuarks(StandardModel::CHARM)).getCharge())*sw2_tree;

    //return 0.5*(dgV - dgA)/gSM;
    return dg/gSM;
}


/* -------------------------------------*/

deltagZttL::deltagZttL(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZttL called with a class whose parent is not NPbase");
}


deltagZttL::~deltagZttL()
{}

double deltagZttL::computeThValue()
{
//    Corrections to Ztt eff. couplings are 0 by default in NPBase, unless overrriden. 
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getQuarks(StandardModel::TOP));
    //double dgA = myNPbase->deltaGA_f(SM.getQuarks(StandardModel::TOP));
    double dg = myNPbase->deltaGL_f_mu(SM.getQuarks(StandardModel::TOP), mu);
    double gSM = (SM.getQuarks(StandardModel::TOP)).getIsospin() 
    - ((SM.getQuarks(StandardModel::TOP)).getCharge())*sw2_tree;

    //return 0.5*(dgV + dgA)/gSM;
    return dg/gSM;
}

/* -------------------------------------*/

deltagZttR::deltagZttR(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZttR called with a class whose parent is not NPbase");
}


deltagZttR::~deltagZttR()
{}

double deltagZttR::computeThValue()
{
//    Corrections to Ztt eff. couplings are 0 by default in NPBase, unless overrriden. 
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getQuarks(StandardModel::TOP));
    //double dgA = myNPbase->deltaGA_f(SM.getQuarks(StandardModel::TOP));
    double dg = myNPbase->deltaGR_f_mu(SM.getQuarks(StandardModel::TOP), mu);
    double gSM = - ((SM.getQuarks(StandardModel::TOP)).getCharge())*sw2_tree;

    //return 0.5*(dgV - dgA)/gSM;
    return dg/gSM;
}

/* -------------------------------------*/

deltagZttV::deltagZttV(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZttV called with a class whose parent is not NPbase");
}


deltagZttV::~deltagZttV()
{}

double deltagZttV::computeThValue()
{
//    Corrections to Ztt eff. couplings are 0 by default in NPBase, unless overrriden. 
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getQuarks(StandardModel::TOP));
    double dgL = myNPbase->deltaGL_f_mu(SM.getQuarks(StandardModel::TOP), mu);
    double dgR = myNPbase->deltaGR_f_mu(SM.getQuarks(StandardModel::TOP), mu);
    double gSM = ((SM.getQuarks(StandardModel::TOP)).getIsospin()) * (1.0 - 4.0*fabs(SM.getQuarks(StandardModel::TOP).getCharge())*sw2_tree);

    //return dgV/gSM;
    return (dgL + dgR)/gSM;
}


/* -------------------------------------*/

deltagZttA::deltagZttA(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZttA called with a class whose parent is not NPbase");
}


deltagZttA::~deltagZttA()
{}

double deltagZttA::computeThValue()
{
//    Corrections to Ztt eff. couplings are 0 by default in NPBase, unless overrriden. 
    //double dgA = myNPbase->deltaGA_f(SM.getQuarks(StandardModel::TOP));
    double dgL = myNPbase->deltaGL_f_mu(SM.getQuarks(StandardModel::TOP), mu);
    double dgR = myNPbase->deltaGR_f_mu(SM.getQuarks(StandardModel::TOP), mu);
    double gSM = (SM.getQuarks(StandardModel::TOP)).getIsospin();

    //return dgA/gSM;
    return (dgL - dgR)/gSM;
}

/* -------------------------------------*/

deltagZddL::deltagZddL(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZddL called with a class whose parent is not NPbase");
}


deltagZddL::~deltagZddL()
{}

double deltagZddL::computeThValue()
{
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getQuarks(StandardModel::DOWN));
    //double dgA = myNPbase->deltaGA_f(SM.getQuarks(StandardModel::DOWN));
    double dg = myNPbase->deltaGL_f_mu(SM.getQuarks(StandardModel::DOWN), mu);
    double gSM = (SM.getQuarks(StandardModel::DOWN)).getIsospin() 
    - ((SM.getQuarks(StandardModel::DOWN)).getCharge())*sw2_tree;
    
    //return 0.5*(dgV + dgA)/gSM;
    return dg/gSM;
}

/* -------------------------------------*/

deltagZddV::deltagZddV(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZddV called with a class whose parent is not NPbase");
}


deltagZddV::~deltagZddV()
{}

double deltagZddV::computeThValue()
{
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getQuarks(StandardModel::DOWN));
    double dgL = myNPbase->deltaGL_f_mu(SM.getQuarks(StandardModel::DOWN), mu);
    double dgR = myNPbase->deltaGR_f_mu(SM.getQuarks(StandardModel::DOWN), mu);
    double gSM = ((SM.getQuarks(StandardModel::DOWN)).getIsospin()) * (1.0 - 4.0*fabs(SM.getQuarks(StandardModel::DOWN).getCharge())*sw2_tree);

    //return dgV/gSM;
    return (dgL + dgR)/gSM;
}


/* -------------------------------------*/

deltagZddA::deltagZddA(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZddA called with a class whose parent is not NPbase");
}


deltagZddA::~deltagZddA()
{}

double deltagZddA::computeThValue()
{
    //double dgA = myNPbase->deltaGA_f(SM.getQuarks(StandardModel::DOWN));
    double dgL = myNPbase->deltaGL_f_mu(SM.getQuarks(StandardModel::DOWN), mu);
    double dgR = myNPbase->deltaGR_f_mu(SM.getQuarks(StandardModel::DOWN), mu);
    double gSM = (SM.getQuarks(StandardModel::DOWN)).getIsospin();

    //return dgA/gSM;
    return (dgL - dgR)/gSM;
}

/* -------------------------------------*/

deltagZddR::deltagZddR(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZddR called with a class whose parent is not NPbase");
}


deltagZddR::~deltagZddR()
{}

double deltagZddR::computeThValue()
{
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getQuarks(StandardModel::DOWN));
    //double dgA = myNPbase->deltaGA_f(SM.getQuarks(StandardModel::DOWN)); 
    double dg = myNPbase->deltaGR_f_mu(SM.getQuarks(StandardModel::DOWN), mu); 
    double gSM = - ((SM.getQuarks(StandardModel::DOWN)).getCharge())*sw2_tree;

    //return 0.5*(dgV - dgA)/gSM;
    return dg/gSM;
}

/* -------------------------------------*/

deltagZssL::deltagZssL(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZssL called with a class whose parent is not NPbase");
}


deltagZssL::~deltagZssL()
{}

double deltagZssL::computeThValue()
{
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getQuarks(StandardModel::STRANGE));
    //double dgA = myNPbase->deltaGA_f(SM.getQuarks(StandardModel::STRANGE));
    double dg = myNPbase->deltaGL_f_mu(SM.getQuarks(StandardModel::STRANGE), mu);
    double gSM = (SM.getQuarks(StandardModel::STRANGE)).getIsospin() 
    - ((SM.getQuarks(StandardModel::STRANGE)).getCharge())*sw2_tree;
    
    //return 0.5*(dgV + dgA)/gSM;
    return dg/gSM;
}

/* -------------------------------------*/

deltagZssR::deltagZssR(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZssR called with a class whose parent is not NPbase");
}


deltagZssR::~deltagZssR()
{}

double deltagZssR::computeThValue()
{
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getQuarks(StandardModel::STRANGE));
    //double dgA = myNPbase->deltaGA_f(SM.getQuarks(StandardModel::STRANGE));
    double dg = myNPbase->deltaGR_f_mu(SM.getQuarks(StandardModel::STRANGE), mu);
    double gSM = - ((SM.getQuarks(StandardModel::STRANGE)).getCharge())*sw2_tree;

    //return 0.5*(dgV - dgA)/gSM;
    return dg/gSM;
}

/* -------------------------------------*/

deltagZbbL::deltagZbbL(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZbbL called with a class whose parent is not NPbase");
}


deltagZbbL::~deltagZbbL()
{}

double deltagZbbL::computeThValue()
{
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getQuarks(StandardModel::BOTTOM));
    //double dgA = myNPbase->deltaGA_f(SM.getQuarks(StandardModel::BOTTOM)); 
    double dg = myNPbase->deltaGL_f_mu(SM.getQuarks(StandardModel::BOTTOM), mu); 
    double gSM = (SM.getQuarks(StandardModel::BOTTOM)).getIsospin() 
    - ((SM.getQuarks(StandardModel::BOTTOM)).getCharge())*sw2_tree;
    
    //return 0.5*(dgV + dgA)/gSM;
    return dg/gSM;
}

/* -------------------------------------*/

deltagZbbR::deltagZbbR(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltagZbbR called with a class whose parent is not NPbase");
}


deltagZbbR::~deltagZbbR()
{}

double deltagZbbR::computeThValue()
{
    double sw2_tree = 1.0 - (SM.StandardModel::Mw_tree())*(SM.StandardModel::Mw_tree())/(SM.getMz())/(SM.getMz());
    //double dgV = myNPbase->deltaGV_f(SM.getQuarks(StandardModel::BOTTOM));
    //double dgA = myNPbase->deltaGA_f(SM.getQuarks(StandardModel::BOTTOM)); 
    double dg = myNPbase->deltaGR_f_mu(SM.getQuarks(StandardModel::BOTTOM), mu); 
    double gSM = - ((SM.getQuarks(StandardModel::BOTTOM)).getCharge())*sw2_tree;

    //return 0.5*(dgV - dgA)/gSM;
    return dg/gSM;
}

/* -------------------------------------*/


//-----  Wff couplings observables  ----------

/* -------------------------------------*/

deltaUWeve::deltaUWeve(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltaUWeve called with a class whose parent is not NPbase");
}


deltaUWeve::~deltaUWeve()
{}

double deltaUWeve::computeThValue()
{
    //double dU = myNPbase->deltaGL_Wff(SM.getLeptons(StandardModel::NEUTRINO_1), SM.getLeptons(StandardModel::ELECTRON)).real();
    double dU = myNPbase->deltaGL_Wff_mu(SM.getLeptons(StandardModel::NEUTRINO_1), SM.getLeptons(StandardModel::ELECTRON), mu).real();
    double gSM = 1.;
    
    return dU/gSM;
}

/* -------------------------------------*/

deltaUWmuvmu::deltaUWmuvmu(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltaUWmuvmu called with a class whose parent is not NPbase");
}


deltaUWmuvmu::~deltaUWmuvmu()
{}

double deltaUWmuvmu::computeThValue()
{
    //double dU = myNPbase->deltaGL_Wff(SM.getLeptons(StandardModel::NEUTRINO_2), SM.getLeptons(StandardModel::MU)).real();
    double dU = myNPbase->deltaGL_Wff_mu(SM.getLeptons(StandardModel::NEUTRINO_2), SM.getLeptons(StandardModel::MU), mu).real();
    double gSM = 1.;
    
    return dU/gSM;
}

/* -------------------------------------*/

deltaUWtavta::deltaUWtavta(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltaUWtavta called with a class whose parent is not NPbase");
}


deltaUWtavta::~deltaUWtavta()
{}

double deltaUWtavta::computeThValue()
{
    //double dU = myNPbase->deltaGL_Wff(SM.getLeptons(StandardModel::NEUTRINO_3), SM.getLeptons(StandardModel::TAU)).real();
    double dU = myNPbase->deltaGL_Wff_mu(SM.getLeptons(StandardModel::NEUTRINO_3), SM.getLeptons(StandardModel::TAU), mu).real();
    double gSM = 1.;
    
    return dU/gSM;
}

/* -------------------------------------*/

deltaVudL::deltaVudL(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltaVudL called with a class whose parent is not NPbase");
}


deltaVudL::~deltaVudL()
{}

double deltaVudL::computeThValue()
{
    //double dV = myNPbase->deltaGL_Wff(SM.getQuarks(StandardModel::UP), SM.getQuarks(StandardModel::DOWN)).real();
    double dV = myNPbase->deltaGL_Wff_mu(SM.getQuarks(StandardModel::UP), SM.getQuarks(StandardModel::DOWN), mu).real();
    double gSM = 1.;
    
    return dV/gSM;
}

/* -------------------------------------*/

deltaVudR::deltaVudR(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltaVudR called with a class whose parent is not NPbase");
}


deltaVudR::~deltaVudR()
{}

double deltaVudR::computeThValue()
{
    //double dV = myNPbase->deltaGR_Wff(SM.getQuarks(StandardModel::UP), SM.getQuarks(StandardModel::DOWN)).real();
    double dV = myNPbase->deltaGR_Wff_mu(SM.getQuarks(StandardModel::UP), SM.getQuarks(StandardModel::DOWN), mu).real();
    
    return dV;
}

/* -------------------------------------*/


deltaVcsL::deltaVcsL(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltaVcsL called with a class whose parent is not NPbase");
}


deltaVcsL::~deltaVcsL()
{}

double deltaVcsL::computeThValue()
{
    //double dV = myNPbase->deltaGL_Wff(SM.getQuarks(StandardModel::CHARM), SM.getQuarks(StandardModel::STRANGE)).real();
    double dV = myNPbase->deltaGL_Wff_mu(SM.getQuarks(StandardModel::CHARM), SM.getQuarks(StandardModel::STRANGE), mu).real();
    double gSM = 1.;
    
    return dV/gSM;
}

/* -------------------------------------*/

deltaVcsR::deltaVcsR(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltaVcsR called with a class whose parent is not NPbase");
}


deltaVcsR::~deltaVcsR()
{}

double deltaVcsR::computeThValue()
{
    //double dV = myNPbase->deltaGR_Wff(SM.getQuarks(StandardModel::CHARM), SM.getQuarks(StandardModel::STRANGE)).real();
    double dV = myNPbase->deltaGR_Wff_mu(SM.getQuarks(StandardModel::CHARM), SM.getQuarks(StandardModel::STRANGE), mu).real();
    
    return dV;
}

/* -------------------------------------*/


deltaVtbL::deltaVtbL(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltaVtbL called with a class whose parent is not NPbase");
}


deltaVtbL::~deltaVtbL()
{}

double deltaVtbL::computeThValue()
{
    //double dV = myNPbase->deltaGL_Wff(SM.getQuarks(StandardModel::TOP), SM.getQuarks(StandardModel::BOTTOM)).real();
    double dV = myNPbase->deltaGL_Wff_mu(SM.getQuarks(StandardModel::TOP), SM.getQuarks(StandardModel::BOTTOM), mu).real();
    double gSM = 1.;
    
    return dV/gSM;
}

/* -------------------------------------*/

deltaVtbR::deltaVtbR(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("deltaVtbR called with a class whose parent is not NPbase");
}


deltaVtbR::~deltaVtbR()
{}

double deltaVtbR::computeThValue()
{
    //double dV = myNPbase->deltaGR_Wff(SM.getQuarks(StandardModel::TOP), SM.getQuarks(StandardModel::BOTTOM)).real();
    double dV = myNPbase->deltaGR_Wff_mu(SM.getQuarks(StandardModel::TOP), SM.getQuarks(StandardModel::BOTTOM), mu).real();
    
    return dV;
}

/* -------------------------------------*/


//-----  Hff couplings observables  ----------

/* -------------------------------------*/

deltagHee::deltagHee(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltagHee::~deltagHee()
{}

double deltagHee::computeThValue()
{
    double dg = myNPbase->deltaG_hff(SM.getLeptons(StandardModel::ELECTRON)).real();
    double gSM = -(SM.getLeptons(StandardModel::ELECTRON)).getMass() / (SM.v());
    
    return dg/gSM;
}

/* -------------------------------------*/

deltagHmumu::deltagHmumu(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltagHmumu::~deltagHmumu()
{}

double deltagHmumu::computeThValue()
{
    double dg = myNPbase->deltaG_hff(SM.getLeptons(StandardModel::MU)).real();
    double gSM = -(SM.getLeptons(StandardModel::MU)).getMass() / (SM.v());
    
    return dg/gSM;
}

/* -------------------------------------*/

gHmumueff::gHmumueff(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


gHmumueff::~gHmumueff()
{}

double gHmumueff::computeThValue()
{   
    return myNPbase->kappamueff();
}

/* -------------------------------------*/

deltagHtata::deltagHtata(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltagHtata::~deltagHtata()
{}

double deltagHtata::computeThValue()
{
    double dg = myNPbase->deltaG_hff(SM.getLeptons(StandardModel::TAU)).real();
    double gSM = -(SM.getLeptons(StandardModel::TAU)).getMass() / (SM.v());
    
    return dg/gSM;
}

/* -------------------------------------*/

gHtataeff::gHtataeff(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


gHtataeff::~gHtataeff()
{}

double gHtataeff::computeThValue()
{   
    return myNPbase->kappataueff();
}

/* -------------------------------------*/

deltagHuu::deltagHuu(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltagHuu::~deltagHuu()
{}

double deltagHuu::computeThValue()
{
    double dg = myNPbase->deltaG_hff(SM.getQuarks(StandardModel::UP)).real();
    double gSM = -(SM.getQuarks(StandardModel::UP)).getMass() / (SM.v());
    
    return dg/gSM;
}

/* -------------------------------------*/

deltagHcc::deltagHcc(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltagHcc::~deltagHcc()
{}

double deltagHcc::computeThValue()
{
    double dg = myNPbase->deltaG_hff(SM.getQuarks(StandardModel::CHARM)).real();
    double gSM = -(SM.getQuarks(StandardModel::CHARM)).getMass() / (SM.v());
    
    return dg/gSM;
}

/* -------------------------------------*/

gHcceff::gHcceff(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


gHcceff::~gHcceff()
{}

double gHcceff::computeThValue()
{   
    return myNPbase->kappaceff();
}

/* -------------------------------------*/

deltagHtt::deltagHtt(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltagHtt::~deltagHtt()
{}

double deltagHtt::computeThValue()
{
    double dg = myNPbase->deltaG_hff(SM.getQuarks(StandardModel::TOP)).real();
    double gSM = -(SM.getMtpole()) / (SM.v());
    
    return dg/gSM;
}

/* -------------------------------------*/

deltagHdd::deltagHdd(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltagHdd::~deltagHdd()
{}

double deltagHdd::computeThValue()
{
    double dg = myNPbase->deltaG_hff(SM.getQuarks(StandardModel::DOWN)).real();
    double gSM = -(SM.getQuarks(StandardModel::DOWN)).getMass() / (SM.v());
    
    return dg/gSM;
}

/* -------------------------------------*/

deltagHss::deltagHss(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltagHss::~deltagHss()
{}

double deltagHss::computeThValue()
{
    double dg = myNPbase->deltaG_hff(SM.getQuarks(StandardModel::STRANGE)).real();
    double gSM = -(SM.getQuarks(StandardModel::STRANGE)).getMass() / (SM.v());
    
    return dg/gSM;
}

/* -------------------------------------*/

deltagHbb::deltagHbb(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltagHbb::~deltagHbb()
{}

double deltagHbb::computeThValue()
{
    double dg = myNPbase->deltaG_hff(SM.getQuarks(StandardModel::BOTTOM)).real();
    double gSM = -(SM.getQuarks(StandardModel::BOTTOM)).getMass() / (SM.v());
    
    return dg/gSM;
}

/* -------------------------------------*/

gHbbeff::gHbbeff(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


gHbbeff::~gHbbeff()
{}

double gHbbeff::computeThValue()
{   
    return myNPbase->kappabeff();
}

/* -------------------------------------*/

//-----  HGG couplings observables  ----------

/* -------------------------------------*/

deltagHGG::deltagHGG(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltagHGG::~deltagHGG()
{}

double deltagHGG::computeThValue()
{   
    return myNPbase->deltaG_hggRatio();
}

/* -------------------------------------*/

gHGGeff::gHGGeff(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


gHGGeff::~gHGGeff()
{}

double gHGGeff::computeThValue()
{   
    return myNPbase->kappaGeff();
}

/* -------------------------------------*/

//-----  HZZ couplings observables  ----------

/* -------------------------------------*/

deltagHZZ::deltagHZZ(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltagHZZ::~deltagHZZ()
{}

double deltagHZZ::computeThValue()
{
    double dg = myNPbase->deltaG3_hZZ();
    double gSM = (SM.getMz()) * (SM.getMz()) / (SM.v());
    
    return dg/gSM;
}

/* -------------------------------------*/

gHZZeff::gHZZeff(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


gHZZeff::~gHZZeff()
{}

double gHZZeff::computeThValue()
{
    return myNPbase->kappaZeff();
}

/* -------------------------------------*/

gHZZ1::gHZZ1(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


gHZZ1::~gHZZ1()
{}

double gHZZ1::computeThValue()
{
    return myNPbase->deltaG1_hZZ();
}

/* -------------------------------------*/

gHZZ2::gHZZ2(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


gHZZ2::~gHZZ2()
{}

double gHZZ2::computeThValue()
{
    return myNPbase->deltaG2_hZZ();
}

/* -------------------------------------*/

//-----  HAA couplings observables  ----------

/* -------------------------------------*/

deltagHAA::deltagHAA(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltagHAA::~deltagHAA()
{}

double deltagHAA::computeThValue()
{
    return myNPbase->deltaG_hAARatio();
}

/* -------------------------------------*/

gHAAeff::gHAAeff(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


gHAAeff::~gHAAeff()
{}

double gHAAeff::computeThValue()
{   
    return myNPbase->kappaAeff();
}

/* -------------------------------------*/

//-----  HZA couplings observables  ----------

/* -------------------------------------*/

deltagHZA::deltagHZA(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltagHZA::~deltagHZA()
{}

double deltagHZA::computeThValue()
{
    return myNPbase->deltaG1_hZARatio();
}

/* -------------------------------------*/

gHZAeff::gHZAeff(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


gHZAeff::~gHZAeff()
{}

double gHZAeff::computeThValue()
{   
    return myNPbase->kappaZAeff();
}

/* -------------------------------------*/

gHZA2::gHZA2(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


gHZA2::~gHZA2()
{}

double gHZA2::computeThValue()
{
    return myNPbase->deltaG2_hZA();
}

/* -------------------------------------*/

//-----  HWW couplings observables  ----------
/* -------------------------------------*/

deltagHWW::deltagHWW(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltagHWW::~deltagHWW()
{}

double deltagHWW::computeThValue()
{
    double dg = myNPbase->deltaG3_hWW();
    double gSM = 2.0 * (SM.StandardModel::Mw_tree())* (SM.StandardModel::Mw_tree()) / (SM.v());
    
    return dg/gSM;
}


/* -------------------------------------*/

gHWWeff::gHWWeff(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


gHWWeff::~gHWWeff()
{}

double gHWWeff::computeThValue()
{
    return myNPbase->kappaWeff();
}

/* -------------------------------------*/

gHWW1::gHWW1(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


gHWW1::~gHWW1()
{}

double gHWW1::computeThValue()
{
    return myNPbase->deltaG1_hWW();
}

/* -------------------------------------*/

gHWW2::gHWW2(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


gHWW2::~gHWW2()
{}

double gHWW2::computeThValue()
{
    return myNPbase->deltaG2_hWW();
}

/* -------------------------------------*/

//-----  Other couplings observables  ----------
/* -------------------------------------*/

/* -------------------------------------*/

gHWZeff::gHWZeff(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


gHWZeff::~gHWZeff()
{}

double gHWZeff::computeThValue()
{
    return (myNPbase->kappaWeff())/(myNPbase->kappaZeff());
}

/* -------------------------------------*/

gHWZSMLin::gHWZSMLin(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


gHWZSMLin::~gHWZSMLin()
{}

double gHWZSMLin::computeThValue()
{   
    double dgZ = myNPbase->deltaG3_hZZ();
    double gZSM = (SM.getMz()) * (SM.getMz()) / (SM.v());
    
    double dgW = myNPbase->deltaG3_hWW();
    double gWSM = 2.0 * (SM.StandardModel::Mw_tree())* (SM.StandardModel::Mw_tree()) / (SM.v());
    
    return (1.0 + dgW/gWSM - dgZ/gZSM);
}

/* -------------------------------------*/

gHbWeff::gHbWeff(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


gHbWeff::~gHbWeff()
{}

double gHbWeff::computeThValue()
{
    return (myNPbase->kappabeff())/(myNPbase->kappaWeff());
}

/* -------------------------------------*/

gHtaWeff::gHtaWeff(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


gHtaWeff::~gHtaWeff()
{}

double gHtaWeff::computeThValue()
{
    return (myNPbase->kappataueff())/(myNPbase->kappaWeff());
}

/* -------------------------------------*/

//-----  HHH couplings observables  ----------

/* -------------------------------------*/

deltalHHH::deltalHHH(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltalHHH::~deltalHHH()
{}

double deltalHHH::computeThValue()
{
    return myNPbase->deltaG_hhhRatio();
}

/* -------------------------------------*/

//-----  VVV couplings observables  ----------

// See aTGC in EW. Here we define only the Effective couplings used in arXiv: 1708.09079 [hep-ph]

/* -------------------------------------*/

deltag1ZEff::deltag1ZEff(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltag1ZEff::~deltag1ZEff()
{}

double deltag1ZEff::computeThValue()
{
    return myNPbase->deltag1ZNPEff();
}

/* -------------------------------------*/

deltaKgammaEff::deltaKgammaEff(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}

deltaKgammaEff::~deltaKgammaEff()
{}

double deltaKgammaEff::computeThValue()
{
    return myNPbase->deltaKgammaNPEff();
}

/* -------------------------------------*/

//-----  Basic interactions of the so-called Higgs basis  ----------

/* -------------------------------------*/

deltaytHB::deltaytHB(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltaytHB::~deltaytHB()
{}

double deltaytHB::computeThValue()
{
    return myNPbase->deltayt_HB();
}

/* -------------------------------------*/

deltaybHB::deltaybHB(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltaybHB::~deltaybHB()
{}

double deltaybHB::computeThValue()
{
    return myNPbase->deltayb_HB();
}

/* -------------------------------------*/

deltaytauHB::deltaytauHB(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltaytauHB::~deltaytauHB()
{}

double deltaytauHB::computeThValue()
{
    return myNPbase->deltaytau_HB();
}

/* -------------------------------------*/

deltaycHB::deltaycHB(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltaycHB::~deltaycHB()
{}

double deltaycHB::computeThValue()
{
    return myNPbase->deltayc_HB();
}

/* -------------------------------------*/

deltaymuHB::deltaymuHB(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltaymuHB::~deltaymuHB()
{}

double deltaymuHB::computeThValue()
{
    return myNPbase->deltaymu_HB();
}

/* -------------------------------------*/

deltacZHB::deltacZHB(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltacZHB::~deltacZHB()
{}

double deltacZHB::computeThValue()
{
    return myNPbase->deltacZ_HB();
}

/* -------------------------------------*/

cZBoxHB::cZBoxHB(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


cZBoxHB::~cZBoxHB()
{}

double cZBoxHB::computeThValue()
{
    return myNPbase->cZBox_HB();
}

/* -------------------------------------*/

cZZHB::cZZHB(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


cZZHB::~cZZHB()
{}

double cZZHB::computeThValue()
{   
    return myNPbase->cZZ_HB();
}

/* -------------------------------------*/

cZgaHB::cZgaHB(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


cZgaHB::~cZgaHB()
{}

double cZgaHB::computeThValue()
{   
    return myNPbase->cZga_HB();
}

/* -------------------------------------*/

cgagaHB::cgagaHB(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


cgagaHB::~cgagaHB()
{}

double cgagaHB::computeThValue()
{   
    return myNPbase->cgaga_HB();
}

/* -------------------------------------*/

cggHB::cggHB(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


cggHB::~cggHB()
{}

double cggHB::computeThValue()
{
    return myNPbase->cgg_HB();
}

/* -------------------------------------*/

cggEffHB::cggEffHB(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


cggEffHB::~cggEffHB()
{}

double cggEffHB::computeThValue()
{
    return myNPbase->cggEff_HB();
}

/* -------------------------------------*/

lambzHB::lambzHB(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


lambzHB::~lambzHB()
{}

double lambzHB::computeThValue()
{   
    return myNPbase->lambz_HB();
}

/* -------------------------------------*/

//-----  Other useful observables to work with new physics  ----------

/* -------------------------------------*/

/* -------------------------------------*/

//-----  Relative correction to W mass  ----------

/* -------------------------------------*/

deltaMW::deltaMW(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


deltaMW::~deltaMW()
{}

double deltaMW::computeThValue()
{
    return (myNPbase->Mw())/SM.StandardModel::Mw() - 1.;
}

/* -------------------------------------*/

//-----  Absolute correction to some EW couplings (factoring e/sc or e/sqrt(2)s  ----------

/* -------------------------------------*/

/* -------------------------------------*/

delgZlL::delgZlL(const StandardModel& SM_i, const StandardModel::lepton lepton, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("delgZlL called with a class whose parent is not NPbase");
    
    this->lepton = lepton;
}


delgZlL::~delgZlL()
{}

double delgZlL::computeThValue()
{
    //double dgV = myNPbase->deltaGV_f(SM.getLeptons(lepton));
    //double dgA = myNPbase->deltaGA_f(SM.getLeptons(lepton));
    double dg = myNPbase->deltaGL_f_mu(SM.getLeptons(lepton), mu);
    
    //return 0.5*(dgV + dgA);
    return dg;
}

/* -------------------------------------*/

delgZlR::delgZlR(const StandardModel& SM_i, const StandardModel::lepton lepton, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("delgZlR called with a class whose parent is not NPbase");
    
    this->lepton = lepton;
}


delgZlR::~delgZlR()
{}

double delgZlR::computeThValue()
{
    //double dgV = myNPbase->deltaGV_f(SM.getLeptons(lepton));
    //double dgA = myNPbase->deltaGA_f(SM.getLeptons(lepton));
    double dg = myNPbase->deltaGR_f_mu(SM.getLeptons(lepton), mu);

    //return 0.5*(dgV - dgA);
    return dg;
}

/* -------------------------------------*/

delgZqL::delgZqL(const StandardModel& SM_i, const StandardModel::quark quark, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("delgZqL called with a class whose parent is not NPbase");
    
    this->quark = quark;
}


delgZqL::~delgZqL()
{}

double delgZqL::computeThValue()
{
    //double dgV = myNPbase->deltaGV_f(SM.getQuarks(quark));
    //double dgA = myNPbase->deltaGA_f(SM.getQuarks(quark));
    double dg = myNPbase->deltaGL_f_mu(SM.getQuarks(quark), mu);
    
    //return 0.5*(dgV + dgA);
    return dg;
}

/* -------------------------------------*/

delgZqR::delgZqR(const StandardModel& SM_i, const StandardModel::quark quark, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("delgZqR called with a class whose parent is not NPbase");
    
    this->quark = quark;
}


delgZqR::~delgZqR()
{}

double delgZqR::computeThValue()
{
    //double dgV = myNPbase->deltaGV_f(SM.getQuarks(quark));
    //double dgA = myNPbase->deltaGA_f(SM.getQuarks(quark));
    double dg = myNPbase->deltaGR_f_mu(SM.getQuarks(quark), mu);

    //return 0.5*(dgV - dgA);
    return dg;
}


/* -------------------------------------*/

//-----  Oblique parameters  ----------

/* -------------------------------------*/

/* -------------------------------------*/

oblS::oblS(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


oblS::~oblS()
{}

double oblS::computeThValue()
{    
    return (myNPbase->obliqueS());
}

/* -------------------------------------*/

oblT::oblT(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


oblT::~oblT()
{}

double oblT::computeThValue()
{    
    return (myNPbase->obliqueT());
}

/* -------------------------------------*/

oblW::oblW(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


oblW::~oblW()
{}

double oblW::computeThValue()
{    
    return (myNPbase->obliqueW());
}

/* -------------------------------------*/

oblY::oblY(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


oblY::~oblY()
{}

double oblY::computeThValue()
{    
    return (myNPbase->obliqueY());
}



/* -------------------------------------*/
/* -------------------------------------*/

//-----  Combinations of Warsaw basis coefficients constrained by EWPO  ----------

/* -------------------------------------*/
/* -------------------------------------*/


CEWHL111::CEWHL111(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHL111::~CEWHL111()
{}

double CEWHL111::computeThValue()
{    
    return (myNPbase->CEWHL111());
}

/* -------------------------------------*/

CEWHL122::CEWHL122(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHL122::~CEWHL122()
{}

double CEWHL122::computeThValue()
{    
    return (myNPbase->CEWHL122());
}

/* -------------------------------------*/

CEWHL133::CEWHL133(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHL133::~CEWHL133()
{}

double CEWHL133::computeThValue()
{    
    return (myNPbase->CEWHL133());
}

/* -------------------------------------*/

CEWHL311::CEWHL311(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHL311::~CEWHL311()
{}

double CEWHL311::computeThValue()
{    
    return (myNPbase->CEWHL311());
}

/* -------------------------------------*/

CEWHL322::CEWHL322(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHL322::~CEWHL322()
{}

double CEWHL322::computeThValue()
{    
    return (myNPbase->CEWHL322());
}

/* -------------------------------------*/

CEWHL333::CEWHL333(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHL333::~CEWHL333()
{}

double CEWHL333::computeThValue()
{    
    return (myNPbase->CEWHL333());
}

/* -------------------------------------*/

CEWHQ111::CEWHQ111(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHQ111::~CEWHQ111()
{}

double CEWHQ111::computeThValue()
{    
    return (myNPbase->CEWHQ111());
}

/* -------------------------------------*/

CEWHQ122::CEWHQ122(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHQ122::~CEWHQ122()
{}

double CEWHQ122::computeThValue()
{    
    return (myNPbase->CEWHQ122());
}

/* -------------------------------------*/

CEWHQ133::CEWHQ133(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHQ133::~CEWHQ133()
{}

double CEWHQ133::computeThValue()
{    
    return (myNPbase->CEWHQ133());
}

/* -------------------------------------*/

CEWHQ311::CEWHQ311(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHQ311::~CEWHQ311()
{}

double CEWHQ311::computeThValue()
{    
    return (myNPbase->CEWHQ311());
}

/* -------------------------------------*/

CEWHQ322::CEWHQ322(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHQ322::~CEWHQ322()
{}

double CEWHQ322::computeThValue()
{    
    return (myNPbase->CEWHQ322());
}

/* -------------------------------------*/

CEWHQ333::CEWHQ333(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHQ333::~CEWHQ333()
{}

double CEWHQ333::computeThValue()
{    
    return (myNPbase->CEWHQ333());
}

/* -------------------------------------*/

CEWHQd33::CEWHQd33(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHQd33::~CEWHQd33()
{}

double CEWHQd33::computeThValue()
{    
    return (myNPbase->CEWHQd33());
}

/* -------------------------------------*/

CEWHe11::CEWHe11(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHe11::~CEWHe11()
{}

double CEWHe11::computeThValue()
{    
    return (myNPbase->CEWHe11());
}

/* -------------------------------------*/

CEWHe22::CEWHe22(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHe22::~CEWHe22()
{}

double CEWHe22::computeThValue()
{    
    return (myNPbase->CEWHe22());
}

/* -------------------------------------*/

CEWHe33::CEWHe33(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHe33::~CEWHe33()
{}

double CEWHe33::computeThValue()
{    
    return (myNPbase->CEWHe33());
}

/* -------------------------------------*/

CEWHu11::CEWHu11(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHu11::~CEWHu11()
{}

double CEWHu11::computeThValue()
{    
    return (myNPbase->CEWHu11());
}

/* -------------------------------------*/

CEWHu22::CEWHu22(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHu22::~CEWHu22()
{}

double CEWHu22::computeThValue()
{    
    return (myNPbase->CEWHu22());
}

/* -------------------------------------*/

CEWHu33::CEWHu33(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHu33::~CEWHu33()
{}

double CEWHu33::computeThValue()
{    
    return (myNPbase->CEWHu33());
}

/* -------------------------------------*/

CEWHd11::CEWHd11(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHd11::~CEWHd11()
{}

double CEWHd11::computeThValue()
{    
    return (myNPbase->CEWHd11());
}

/* -------------------------------------*/

CEWHd22::CEWHd22(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHd22::~CEWHd22()
{}

double CEWHd22::computeThValue()
{    
    return (myNPbase->CEWHd22());
}

/* -------------------------------------*/

CEWHd33::CEWHd33(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


CEWHd33::~CEWHd33()
{}

double CEWHd33::computeThValue()
{    
    return (myNPbase->CEWHd33());
}

/* -------------------------------------*/


/* -------------------------------------*/
/* -------------------------------------*/

//-----  Auxiliary observables  ----------

/* -------------------------------------*/

/* -------------------------------------*/

AuxObsNP1::AuxObsNP1(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP1::~AuxObsNP1()
{}

double AuxObsNP1::computeThValue()
{    
    return (myNPbase->AuxObs_NP1());
}

/* -------------------------------------*/

AuxObsNP2::AuxObsNP2(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP2::~AuxObsNP2()
{}

double AuxObsNP2::computeThValue()
{    
    return (myNPbase->AuxObs_NP2());
}

/* -------------------------------------*/

AuxObsNP3::AuxObsNP3(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP3::~AuxObsNP3()
{}

double AuxObsNP3::computeThValue()
{    
    return (myNPbase->AuxObs_NP3());
}

/* -------------------------------------*/

AuxObsNP4::AuxObsNP4(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP4::~AuxObsNP4()
{}

double AuxObsNP4::computeThValue()
{    
    return (myNPbase->AuxObs_NP4());
}

/* -------------------------------------*/

AuxObsNP5::AuxObsNP5(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP5::~AuxObsNP5()
{}

double AuxObsNP5::computeThValue()
{    
    return (myNPbase->AuxObs_NP5());
}

/* -------------------------------------*/

AuxObsNP6::AuxObsNP6(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP6::~AuxObsNP6()
{}

double AuxObsNP6::computeThValue()
{    
    return (myNPbase->AuxObs_NP6());
}

/* -------------------------------------*/


AuxObsNP7::AuxObsNP7(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP7::~AuxObsNP7()
{}

double AuxObsNP7::computeThValue()
{    
    return (myNPbase->AuxObs_NP7());
}

/* -------------------------------------*/


AuxObsNP8::AuxObsNP8(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP8::~AuxObsNP8()
{}

double AuxObsNP8::computeThValue()
{    
    return (myNPbase->AuxObs_NP8());
}

/* -------------------------------------*/


AuxObsNP9::AuxObsNP9(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP9::~AuxObsNP9()
{}

double AuxObsNP9::computeThValue()
{    
    return (myNPbase->AuxObs_NP9());
}

/* -------------------------------------*/


AuxObsNP10::AuxObsNP10(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP10::~AuxObsNP10()
{}

double AuxObsNP10::computeThValue()
{    
    return (myNPbase->AuxObs_NP10());
}

/* -------------------------------------*/


AuxObsNP11::AuxObsNP11(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP11::~AuxObsNP11()
{}

double AuxObsNP11::computeThValue()
{    
    return (myNPbase->AuxObs_NP11());
}

/* -------------------------------------*/


AuxObsNP12::AuxObsNP12(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP12::~AuxObsNP12()
{}

double AuxObsNP12::computeThValue()
{    
    return (myNPbase->AuxObs_NP12());
}

/* -------------------------------------*/


AuxObsNP13::AuxObsNP13(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP13::~AuxObsNP13()
{}

double AuxObsNP13::computeThValue()
{    
    return (myNPbase->AuxObs_NP13());
}

/* -------------------------------------*/


AuxObsNP14::AuxObsNP14(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP14::~AuxObsNP14()
{}

double AuxObsNP14::computeThValue()
{    
    return (myNPbase->AuxObs_NP14());
}

/* -------------------------------------*/


AuxObsNP15::AuxObsNP15(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP15::~AuxObsNP15()
{}

double AuxObsNP15::computeThValue()
{    
    return (myNPbase->AuxObs_NP15());
}

/* -------------------------------------*/


AuxObsNP16::AuxObsNP16(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP16::~AuxObsNP16()
{}

double AuxObsNP16::computeThValue()
{    
    return (myNPbase->AuxObs_NP16());
}

/* -------------------------------------*/


AuxObsNP17::AuxObsNP17(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP17::~AuxObsNP17()
{}

double AuxObsNP17::computeThValue()
{    
    return (myNPbase->AuxObs_NP17());
}

/* -------------------------------------*/


AuxObsNP18::AuxObsNP18(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP18::~AuxObsNP18()
{}

double AuxObsNP18::computeThValue()
{    
    return (myNPbase->AuxObs_NP18());
}

/* -------------------------------------*/


AuxObsNP19::AuxObsNP19(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP19::~AuxObsNP19()
{}

double AuxObsNP19::computeThValue()
{    
    return (myNPbase->AuxObs_NP19());
}

/* -------------------------------------*/


AuxObsNP20::AuxObsNP20(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP20::~AuxObsNP20()
{}

double AuxObsNP20::computeThValue()
{    
    return (myNPbase->AuxObs_NP20());
}

/* -------------------------------------*/


AuxObsNP21::AuxObsNP21(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP21::~AuxObsNP21()
{}

double AuxObsNP21::computeThValue()
{    
    return (myNPbase->AuxObs_NP21());
}

/* -------------------------------------*/


AuxObsNP22::AuxObsNP22(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP22::~AuxObsNP22()
{}

double AuxObsNP22::computeThValue()
{    
    return (myNPbase->AuxObs_NP22());
}

/* -------------------------------------*/


AuxObsNP23::AuxObsNP23(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP23::~AuxObsNP23()
{}

double AuxObsNP23::computeThValue()
{    
    return (myNPbase->AuxObs_NP23());
}

/* -------------------------------------*/


AuxObsNP24::AuxObsNP24(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP24::~AuxObsNP24()
{}

double AuxObsNP24::computeThValue()
{    
    return (myNPbase->AuxObs_NP24());
}

/* -------------------------------------*/


AuxObsNP25::AuxObsNP25(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP25::~AuxObsNP25()
{}

double AuxObsNP25::computeThValue()
{    
    return (myNPbase->AuxObs_NP25());
}

/* -------------------------------------*/


AuxObsNP26::AuxObsNP26(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP26::~AuxObsNP26()
{}

double AuxObsNP26::computeThValue()
{    
    return (myNPbase->AuxObs_NP26());
}

/* -------------------------------------*/


AuxObsNP27::AuxObsNP27(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP27::~AuxObsNP27()
{}

double AuxObsNP27::computeThValue()
{    
    return (myNPbase->AuxObs_NP27());
}

/* -------------------------------------*/


AuxObsNP28::AuxObsNP28(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP28::~AuxObsNP28()
{}

double AuxObsNP28::computeThValue()
{    
    return (myNPbase->AuxObs_NP28());
}

/* -------------------------------------*/


AuxObsNP29::AuxObsNP29(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP29::~AuxObsNP29()
{}

double AuxObsNP29::computeThValue()
{    
    return (myNPbase->AuxObs_NP29());
}

/* -------------------------------------*/


AuxObsNP30::AuxObsNP30(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{}


AuxObsNP30::~AuxObsNP30()
{}

double AuxObsNP30::computeThValue()
{    
    return (myNPbase->AuxObs_NP30());
}

/* -------------------------------------*/


//-----  Deviations of SM inputs with respect to reference value  ----------
// (To use in future collider studies where the predictions are assumed to be SM at some
//  reference point)

/* -------------------------------------*/

dalphaMzRef::dalphaMzRef(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


dalphaMzRef::~dalphaMzRef()
{}

double dalphaMzRef::computeThValue()
{
    double aMz = SM.alphaMz();
    
    return (aMz - 0.007754942001072636)/0.007754942001072636;
}

/* -------------------------------------*/

dalphaSMzRef::dalphaSMzRef(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


dalphaSMzRef::~dalphaSMzRef()
{}

double dalphaSMzRef::computeThValue()
{
    double aSMz = SM.getAlsMz();
    
    return (aSMz - 0.1180)/0.1180;
}

/* -------------------------------------*/

dMzRef::dMzRef(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


dMzRef::~dMzRef()
{}

double dMzRef::computeThValue()
{
    double Mz = SM.getMz();
    
    return (Mz - 91.1882)/91.1882;
}

/* -------------------------------------*/

dMHRef::dMHRef(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


dMHRef::~dMHRef()
{}

double dMHRef::computeThValue()
{
    double Mh = SM.getMHl();
    
    return (Mh - 125.1)/125.1;
}

/* -------------------------------------*/

dmtRef::dmtRef(const StandardModel& SM_i):

        ThObservable(SM_i), 
        myNPbase(static_cast<const NPbase*> (&SM_i))
{
}


dmtRef::~dmtRef()
{}

double dmtRef::computeThValue()
{
    double mTop = SM.getMtpole();
    
    return (mTop - 173.2)/173.2;
}

/* -------------------------------------*/

// Top Wilson coefficients in the notation of LHC Top WG arXiv: 1802.07237

/* -------------------------------------*/

TWGctH::TWGctH(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGctH called with a class whose parent is not NPbase");
}


TWGctH::~TWGctH()
{}

double TWGctH::computeThValue()
{    
    return (myNPbase->ctH_TWG(mu));
}

/* -------------------------------------*/

TWGcHQm::TWGcHQm(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGcHQm called with a class whose parent is not NPbase");
}


TWGcHQm::~TWGcHQm()
{}

double TWGcHQm::computeThValue()
{    
    return (myNPbase->cHQm_TWG(mu));
}

/* -------------------------------------*/

TWGcHt::TWGcHt(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGcHt called with a class whose parent is not NPbase");
}


TWGcHt::~TWGcHt()
{}

double TWGcHt::computeThValue()
{    
    return (myNPbase->cHt_TWG(mu));
}

/* -------------------------------------*/

TWGctG::TWGctG(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGctG called with a class whose parent is not NPbase");
}


TWGctG::~TWGctG()
{}

double TWGctG::computeThValue()
{    
    return (myNPbase->ctG_TWG(mu));
}

/* -------------------------------------*/

TWGcHQ3::TWGcHQ3(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGcHQ3 called with a class whose parent is not NPbase");
}


TWGcHQ3::~TWGcHQ3()
{}

double TWGcHQ3::computeThValue()
{    
    return (myNPbase->cHQ3_TWG(mu));
}

/* -------------------------------------*/

TWGctW::TWGctW(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGctW called with a class whose parent is not NPbase");
}


TWGctW::~TWGctW()
{}

double TWGctW::computeThValue()
{    
    return (myNPbase->ctW_TWG(mu));
}

/* -------------------------------------*/

TWGImctW::TWGImctW(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGImctW called with a class whose parent is not NPbase");
}


TWGImctW::~TWGImctW()
{}

double TWGImctW::computeThValue()
{    
    return (myNPbase->IctW_TWG(mu));
}

/* -------------------------------------*/

TWGctZ::TWGctZ(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGctZ called with a class whose parent is not NPbase");
}


TWGctZ::~TWGctZ()
{}

double TWGctZ::computeThValue()
{    
    return (myNPbase->ctZ_TWG(mu));
}

/* -------------------------------------*/

TWGImctZ::TWGImctZ(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGImctZ called with a class whose parent is not NPbase");
}


TWGImctZ::~TWGImctZ()
{}

double TWGImctZ::computeThValue()
{    
    return (myNPbase->IctZ_TWG(mu));
}

/* -------------------------------------*/

TWGcHb::TWGcHb(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGcHb called with a class whose parent is not NPbase");
}


TWGcHb::~TWGcHb()
{}

double TWGcHb::computeThValue()
{    
    return (myNPbase->cHb_TWG(mu));
}

/* -------------------------------------*/

TWGctu8::TWGctu8(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGctu8 called with a class whose parent is not NPbase");
}


TWGctu8::~TWGctu8()
{}

double TWGctu8::computeThValue()
{    
    return (myNPbase->ctu8_TWG(mu));
}

/* -------------------------------------*/

TWGctd8::TWGctd8(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGctd8 called with a class whose parent is not NPbase");
}


TWGctd8::~TWGctd8()
{}

double TWGctd8::computeThValue()
{    
    return (myNPbase->ctd8_TWG(mu));
}

/* -------------------------------------*/

TWGcQq18::TWGcQq18(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGcQq18 called with a class whose parent is not NPbase");
}


TWGcQq18::~TWGcQq18()
{}

double TWGcQq18::computeThValue()
{    
    return (myNPbase->cQq18_TWG(mu));
}

/* -------------------------------------*/

TWGctq8::TWGctq8(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGctq8 called with a class whose parent is not NPbase");
}


TWGctq8::~TWGctq8()
{}

double TWGctq8::computeThValue()
{    
    return (myNPbase->ctq8_TWG(mu));
}

/* -------------------------------------*/

TWGcQq38::TWGcQq38(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGcQq38 called with a class whose parent is not NPbase");
}


TWGcQq38::~TWGcQq38()
{}

double TWGcQq38::computeThValue()
{    
    return (myNPbase->cQq38_TWG(mu));
}

/* -------------------------------------*/

TWGcQu8::TWGcQu8(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGcQu8 called with a class whose parent is not NPbase");
}


TWGcQu8::~TWGcQu8()
{}

double TWGcQu8::computeThValue()
{    
    return (myNPbase->cQu8_TWG(mu));
}

/* -------------------------------------*/

TWGcQd8::TWGcQd8(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGcQd8 called with a class whose parent is not NPbase");
}


TWGcQd8::~TWGcQd8()
{}

double TWGcQd8::computeThValue()
{    
    return (myNPbase->cQd8_TWG(mu));
}

/* -------------------------------------*/

TWGcQd1::TWGcQd1(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGcQd1 called with a class whose parent is not NPbase");
}


TWGcQd1::~TWGcQd1()
{}

double TWGcQd1::computeThValue()
{    
    return (myNPbase->cQd1_TWG(mu));
}

/* -------------------------------------*/

TWGcQu1::TWGcQu1(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGcQu1 called with a class whose parent is not NPbase");
}


TWGcQu1::~TWGcQu1()
{}

double TWGcQu1::computeThValue()
{    
    return (myNPbase->cQu1_TWG(mu));
}

/* -------------------------------------*/

TWGctd1::TWGctd1(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGctd1 called with a class whose parent is not NPbase");
}


TWGctd1::~TWGctd1()
{}

double TWGctd1::computeThValue()
{    
    return (myNPbase->ctd1_TWG(mu));
}

/* -------------------------------------*/

TWGctu1::TWGctu1(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGctu1 called with a class whose parent is not NPbase");
}


TWGctu1::~TWGctu1()
{}

double TWGctu1::computeThValue()
{    
    return (myNPbase->ctu1_TWG(mu));
}

/* -------------------------------------*/

TWGctq1::TWGctq1(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGctq1 called with a class whose parent is not NPbase");
}


TWGctq1::~TWGctq1()
{}

double TWGctq1::computeThValue()
{    
    return (myNPbase->ctq1_TWG(mu));
}

/* -------------------------------------*/

TWGcQq11::TWGcQq11(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGcQq11 called with a class whose parent is not NPbase");
}


TWGcQq11::~TWGcQq11()
{}

double TWGcQq11::computeThValue()
{    
    return (myNPbase->cQq11_TWG(mu));
}

/* -------------------------------------*/

TWGcQq31::TWGcQq31(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGcQq31 called with a class whose parent is not NPbase");
}


TWGcQq31::~TWGcQq31()
{}

double TWGcQq31::computeThValue()
{    
    return (myNPbase->cQq31_TWG(mu));
}

/* -------------------------------------*/

TWGcQlM::TWGcQlM(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGcQlM called with a class whose parent is not NPbase");
}


TWGcQlM::~TWGcQlM()
{}

double TWGcQlM::computeThValue()
{    
    return (myNPbase->cQlM_TWG(mu));
}

/* -------------------------------------*/

TWGcte::TWGcte(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGcte called with a class whose parent is not NPbase");
}


TWGcte::~TWGcte()
{}

double TWGcte::computeThValue()
{    
    return (myNPbase->cte_TWG(mu));
}

/* -------------------------------------*/

TWGctl::TWGctl(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGctl called with a class whose parent is not NPbase");
}


TWGctl::~TWGctl()
{}

double TWGctl::computeThValue()
{    
    return (myNPbase->ctl_TWG(mu));
}

/* -------------------------------------*/

TWGcQe::TWGcQe(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("TWGcQe called with a class whose parent is not NPbase");
}


TWGcQe::~TWGcQe()
{}

double TWGcQe::computeThValue()
{    
    return (myNPbase->cQe_TWG(mu));
}

/* -------------------------------------*/
// Definitions for optimal observable analyses

OOcHQplus::OOcHQplus(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("OOcHQplus called with a class whose parent is not NPbase");
}


OOcHQplus::~OOcHQplus()
{}

double OOcHQplus::computeThValue()
{    
    return (myNPbase->cHQpOO(mu));
}

/* -------------------------------------*/

OOcHQminus::OOcHQminus(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("OOcHQminus called with a class whose parent is not NPbase");
}


OOcHQminus::~OOcHQminus()
{}

double OOcHQminus::computeThValue()
{    
    return (myNPbase->cHQmOO(mu));
}

/* -------------------------------------*/

OOcHt::OOcHt(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("OOcHt called with a class whose parent is not NPbase");
}


OOcHt::~OOcHt()
{}

double OOcHt::computeThValue()
{    
    return (myNPbase->cHtOO(mu));
}

/* -------------------------------------*/

OOctW::OOctW(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("OOctW called with a class whose parent is not NPbase");
}


OOctW::~OOctW()
{}

double OOctW::computeThValue()
{    
    return (myNPbase->ctWOO(mu));
}

/* -------------------------------------*/

OOctZ::OOctZ(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("OOctZ called with a class whose parent is not NPbase");
}


OOctZ::~OOctZ()
{}

double OOctZ::computeThValue()
{    
    return (myNPbase->ctZOO(mu));
}

/* -------------------------------------*/

OOImctW::OOImctW(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("OOImctW called with a class whose parent is not NPbase");
}


OOImctW::~OOImctW()
{}

double OOImctW::computeThValue()
{    
    return (myNPbase->ImctWOO(mu));
}

/* -------------------------------------*/

OOImctZ::OOImctZ(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("OOImctZ called with a class whose parent is not NPbase");
}


OOImctZ::~OOImctZ()
{}

double OOImctZ::computeThValue()
{    
    return (myNPbase->ImctZOO(mu));
}


/* -------------------------------------*/

OOctH::OOctH(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("OOctH called with a class whose parent is not NPbase");
}


OOctH::~OOctH()
{}

double OOctH::computeThValue()
{    
    return (myNPbase->ctHOO(mu));
}

/* -------------------------------------*/

OOclQplus::OOclQplus(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("OOclQplus called with a class whose parent is not NPbase");
}


OOclQplus::~OOclQplus()
{}

double OOclQplus::computeThValue()
{    
    return (myNPbase->clQpOO(mu));
}

/* -------------------------------------*/

OOclQminus::OOclQminus(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("OOclQminus called with a class whose parent is not NPbase");
}


OOclQminus::~OOclQminus()
{}

double OOclQminus::computeThValue()
{    
    return (myNPbase->clQmOO(mu));
}

/* -------------------------------------*/

OOclt::OOclt(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("OOclt called with a class whose parent is not NPbase");
}


OOclt::~OOclt()
{}

double OOclt::computeThValue()
{    
    return (myNPbase->cltOO(mu));
}

/* -------------------------------------*/


OOcQe::OOcQe(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("OOcQe called with a class whose parent is not NPbase");
}


OOcQe::~OOcQe()
{}

double OOcQe::computeThValue()
{    
    return (myNPbase->cQeOO(mu));
}

/* -------------------------------------*/


OOcet::OOcet(const StandardModel& SM_i, const double mu_i)
:ThObservable(SM_i), mu(mu_i)
{
    if ((myNPbase = dynamic_cast<const NPbase*> (&SM)) == NULL)
        throw std::runtime_error("OOcet called with a class whose parent is not NPbase");
}


OOcet::~OOcet()
{}

double OOcet::computeThValue()
{    
    return (myNPbase->cetOO(mu));
}

/* -------------------------------------*/