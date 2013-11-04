/*
 * Copyright (C) 2013 SusyFit Collaboration
 * All rights reserved.
 *
 * For the licensing terms see doc/COPYING.
 */

#ifndef EW_BURGESS_H
#define	EW_BURGESS_H

#include <StandardModel.h>

/**
 * @class EW_BURGESS
 * @ingroup EW
 * @brief A test class for the oblique corrections to the EWPO.
 * @author SusyFit Collaboration
 * @copyright GNU General Public License
 * @details A test class based on simple parameterizations of the
 * oblique corrections by Burgess in Pramana 45, S47 (1995) [hep-ph/9411257].
 */
class EW_BURGESS {
public:

    /**
     * @brief EW_BURGESS constructor.
     * @param SM_i An object of StandardModel class.
     */
    EW_BURGESS(const StandardModel& SM_i)
    : SM(SM_i)
    {
    };

    ////////////////////////////////////////////////////////////////////////

    double Mw(const double Mw_SM) const;
    double GammaW(const double GammaW_SM) const;
    double GammaZ(const double GammaZ_SM) const;
    double sigmaHadron(const double sigmaHadron_SM, const double GammaZ_SM,
                       const double GammaHad_SM, const double Gamma_l_SM) const;
    double sin2thetaEff(const double sin2thetaEff_SM) const;
    double PtauPol(const double PtauPol_SM) const;
    double Alepton(const double Alepton_SM) const;
    double Acharm(const double Acharm_SM, const double Alepton_SM) const;
    double Abottom(const double Abottom_SM, const double Alepton_SM) const;
    double AFBlepton(const double AFBlepton_SM) const;
    double AFBcharm(const double AFBcharm_SM) const;
    double AFBbottom(const double AFBbottom_SM) const;
    double Rlepton(const double Rlepton_SM, const double GammaHad_SM,
                   const double Gamma_l_SM) const;
    double Rcharm(const double Rcharm_SM, const double GammaHad_SM) const;
    double Rbottom(const double Rbottom_SM, const double GammaHad_SM,
                   const double Gamma_b_SM) const;

private:
    const StandardModel& SM;

};

#endif	/* EW_BURGESS_H */

