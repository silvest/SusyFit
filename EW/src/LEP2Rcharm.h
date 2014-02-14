/* 
 * Copyright (C) 2012-2013 SusyFit Collaboration
 * All rights reserved.
 *
 * For the licensing terms see doc/COPYING.
 */

#ifndef LEP2RCHARM_H
#define	LEP2RCHARM_H

#include "LEP2ThObservable.h"
#include "LEP2sigmaCharm.h"
#include "LEP2sigmaHadron.h"

/**
 * @class LEP2Rcharm
 * @ingroup EW
 * @brief A class for @f$R_c^0@f$ above the @f$Z@f$ pole.
 * @author SusyFit Collaboration
 * @copyright GNU General Public License
 * @details 
 */
class LEP2Rcharm : public LEP2ThObservable {
public:

    /**
     * @brief LEP2Rcharm constructor
     * @param[in] EW_i an object of EW class
     * @param[in] sqrt_s_i the CM energy of the e^+ e^- pair
     */
    LEP2Rcharm(const EW& EW_i, const double sqrt_s_i) 
    : LEP2ThObservable(EW_i, sqrt_s_i), myLEP2sigmaCharm(EW_i, sqrt_s_i), 
            myLEP2sigmaHadron(EW_i, sqrt_s_i, false, true)  
    {
        q_flavor = QCD::CHARM;
    }

    /**
     * @return the ratio of the c-cbar cross section to the hadronic cross section at sqrt_s
     */
    double computeThValue();

private:
    LEP2sigmaCharm myLEP2sigmaCharm;
    LEP2sigmaHadron myLEP2sigmaHadron;
    
};

#endif	/* LEP2RCHARM_H */

