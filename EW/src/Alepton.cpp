/* 
 * Copyright (C) 2012-2013 SusyFit Collaboration
 * All rights reserved.
 *
 * For the licensing terms see doc/COPYING.
 */

#include "Alepton.h"


double Alepton::getThValue() 
{ 
    double A_l;
    EW::EWTYPE myEWTYPE = myEW.getEWTYPE();

    if (myEWTYPE==EW::EWCHMN)  
        A_l = myEW.getMyEW_CHMN().A_l(SM.ELECTRON);
    else if (myEWTYPE==EW::EWABC) 
        A_l = myEW.getMyEW_ABC().A_l(SM.ELECTRON,SM.epsilon1(),SM.epsilon3());
    else if (myEWTYPE==EW::EWABC2) {
        double delta_alpha = (SM.alphaMz() - 1.0/128.90)/SM.getAle();
        double x0 = 0.075619 - 1.32*delta_alpha;
        double x = x0*(1.0 + 17.6*SM.epsilon1() - 22.9*SM.epsilon3());
        A_l = 2.0*x/(1.0 + x*x);
    } else {
        A_l = myEW.A_l(SM.ELECTRON);
        
        if ( myEW.checkModelForSTU() ) {
            if(myEWTYPE==EW::EWBURGESS) {
                // TEST: the fit result by Gfitter in arXiv:1209.2716, 
                //       corresponding to MH=125.7 and Mt=173.52 
                //A_l = 0.1473;
            
                A_l += - 0.0284*myEW.S() + 0.0201*myEW.T();
            } else {
                double alpha = myEW.alpha0();  
                double c2 = myEW.c02();
                double s2 = myEW.s02();
                double s4 = s2*s2;
                
                A_l -= 4.0*alpha*s2/pow(1.0-4.0*s2+8.0*s4, 2.0)
                       *( myEW.S() - 4.0*c2*s2*myEW.T() );
            }
        }
    }
    
    return A_l;
}
        

