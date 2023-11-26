/* 
 * Copyright (C) 2012 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#ifndef LEP2SIGMAMU_H
#define	LEP2SIGMAMU_H

#include "LEP2ThObservable.h"

/**
 * @class LEP2sigmaMu
 * @ingroup EW
 * @brief A class for the cross section of @f$e^+e^-\to \mu^+\mu^-@f$ above the @f$Z@f$ pole.
 * @author HEPfit Collaboration
 * @copyright GNU General Public License
 * @details 
 */
class LEP2sigmaMu : public LEP2ThObservable {
public:

    /**
     * @brief LEP2sigmaMu constructor
     * @param[in] SM_i a reference to an object of type StandardModel
     * @param[in] sqrt_s_i the CM energy of the e^+ e^- pair
     * @param[in] bSigmaForAFB_i true for the denominator of A_FB
     */
    LEP2sigmaMu(const StandardModel& SM_i, const double sqrt_s_i) 
    : LEP2ThObservable(SM_i, sqrt_s_i) 
    {
    }

    /**
     * @return the cross section for e^+ e^- -> mu^+ mu^- at sqrt_s in pb
     */
    double computeThValue();

private:
    
};


/**
 * @class LEP2dsigmadcosMu
 * @ingroup EW
 * @brief A class for the cross section of @f$e^+e^-\to \mu^+\mu^-@f$ above the @f$Z@f$ pole.
 * @author HEPfit Collaboration
 * @copyright GNU General Public License
 * @details 
 */
class LEP2dsigmadcosMu : public LEP2ThDiffObservable {
public:

    /**
     * @brief LEP2dsigmadcosMu constructor
     * @param[in] SM_i a reference to an object of type StandardModel
     * @param[in] sqrt_s_i the CM energy of the e^+ e^- pair
     * @param[in] cos_i the polar angle of the final state particle wrt e^-
     */
    LEP2dsigmadcosMu(const StandardModel& SM_i, const double sqrt_s_i, const double cos_i) 
    : LEP2ThDiffObservable(SM_i, sqrt_s_i, cos_i) 
    {
    }

    /**
     * @return the cross section for e^+ e^- -> mu^+ mu^- at sqrt_s in pb
     */
    double computeThValue();

private:
    
};


#endif	/* LEP2SIGMAMU_H */

