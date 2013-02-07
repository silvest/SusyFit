/* 
 * Copyright (C) 2012 SusyFit Collaboration
 * All rights reserved.
 *
 * For the licensing terms see doc/COPYING.
 */

#ifndef RLEPTON_H
#define	RLEPTON_H

#include <stdexcept>
#include <ThObservable.h>
#include "EW.h"

/**
 * @class Rlepton
 * @ingroup EW 
 * @brief A class for @f$R_\ell=\Gamma(Z\to {\rm hadrons})/\Gamma(Z\to \ell\bar{\ell})@f$ 
 * at the @f$Z@f$ pole.
 * @author SusyFit Collaboration
 * @copyright GNU General Public License
 * @details This class is used to compute the ratio of the @f$Z@f$-boson 
 * hadronic width to the @f$Z\to \ell\bar{\ell}@f$ width at the @f$Z@f$ pole.
 */
class Rlepton : public ThObservable {
public:

    /**
     * A constructor.
     * @param[in] EW_i A reference to an object of EW class, which is the base 
     * class of the electroweak precision observables.
     */
    Rlepton(const EW& EW_i) 
    : ThObservable(EW_i), myEW(EW_i), myEWTYPE(EW_i.getEWTYPE()) 
    {
    };

    /**
     * @return The ratio of the @f$Z@f$-boson hadronic width to the 
     * @f$Z\to \ell\bar{\ell}@f$ width at the @f$Z@f$ pole. 
     */
    double getThValue();

    
private:

    /**
     * A reference to an object of EW class, which is the base class of the 
     * electroweak precision observables.
     */
    const EW& myEW;

    /**
     * An enumerator controlling the formulae used in the computation.
     */
    const EW::EWTYPE myEWTYPE;
};

#endif	/* RLEPTON_H */

