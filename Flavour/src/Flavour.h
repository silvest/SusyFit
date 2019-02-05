/*
 * Copyright (C) 2012 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#ifndef FLAVOUR_H
#define FLAVOUR_H

class StandardModel;
class HeffDF2;
class HeffDB1;
class HeffDS1;
class MVll;
class MPll;
class MVgamma;
class MVlnu;
class MPlnu;
#include "QCD.h"
#include <boost/tuple/tuple.hpp>
#include <memory>

/**
 * @class Flavour
 * @ingroup Flavour
 * @brief The parent class in Flavour for calculating all the Wilson coefficients for various Flavor Violating processes.
 * @author HEPfit Collaboration
 * @copyright GNU General Public License
 * @details The Flavour class aggregates the Wilson coefficients for each of the processes generated by the model by calling the Hamiltonians.
 */

class Flavour {
public:

    /**
     * @brief The constructor.
     * @param[in] SM_i a reference to an object of the class StandardModel
     */
    Flavour(const StandardModel& SM_i);

    /**
     * @brief The member that returns an object of the class HeffDF2.
     * @return returns the Hamiltonian for the \f$ \Delta F = 2 \f$ processes
     *
     */
    const HeffDF2& getHDF2() const
    {
        return *getPtr<HeffDF2>(HDF2);
    }

    /**
     * @brief The member that returns an object of the class HeffDS1.
     * @return returns the Hamiltonian for the \f$ \Delta S = 1 \f$ processes.
     *
     */
    const HeffDS1& getHDS1() const
    {
        return *getPtr<HeffDS1>(HDS1);
    }

    /**
     * @brief The member that returns an object of the class HeffDB1.
     * @return returns the Hamiltonian for the \f$ \Delta B = 1 \f$ processes.
     *
     */
    const HeffDB1& getHDB1() const
    {
        return *getPtr<HeffDB1>(HDB1);
    }

    /**
     * @brief Computes the Wilson coefficient for the process \f$ B_d \to \mu \mu \f$.
     * @param[in] mu the lower matching scale for the process
     * @param[in] scheme the scheme in which the Wilson Coefficients need to be calculated
     * @return returns the Wilson coefficients for the process \f$ B_d \to \mu \mu \f$
     *
     */
    gslpp::vector<gslpp::complex>** ComputeCoeffBd(double mu, schemes scheme = NDR) const;

    gslpp::vector<gslpp::complex>** ComputeCoeffDS1pnunu() const;

    gslpp::vector<gslpp::complex>** ComputeCoeffDS1mumu() const;

    /**
     * @brief Computes the Wilson coefficient for the process \f$ B_s \to \mu \mu \f$.
     * @param[in] mu the lower matching scale for the process
     * @param[in] scheme the scheme in which the Wilson Coefficients need to be calculated
     * @return returns the Wilson coefficients for the process \f$ B_s \to \mu \mu \f$
     *
     */
    gslpp::vector<gslpp::complex>** ComputeCoeffBs(double mu, schemes scheme = NDR, bool SM = false) const;

    gslpp::vector<gslpp::complex>** ComputeCoeffdd(double mu, schemes scheme = NDR) const;

    gslpp::vector<gslpp::complex>** ComputeCoeffK(double mu, schemes scheme = NDR) const;

    gslpp::vector<gslpp::complex>** ComputeCoeffmK(double mu, schemes scheme = NDR) const;

    gslpp::vector<gslpp::complex>** ComputeCoeffDS1PP(double mu, schemes scheme = NDR) const;

    /**
     * @brief Computes the Wilson coefficient for the process \f$ B_s \to \mu \mu \f$.
     * @param[in] mu the lower matching scale for the process
     * @param[in] scheme the scheme in which the Wilson Coefficients need to be calculated
     * @return returns the Wilson coefficients for the process \f$ B_s \to \mu \mu \f$
     *
     */
    gslpp::vector<gslpp::complex>** ComputeCoeffsmumu(double mu, schemes scheme = NDR) const;

    /**
     * @brief Computes the Wilson coefficient for the process \f$ B_d \to \mu \mu \f$.
     * @param[in] mu the lower matching scale for the process
     * @param[in] scheme the scheme in which the Wilson Coefficients need to be calculated
     * @return returns the Wilson coefficients for the process \f$ B_d \to \mu \mu \f$
     *
     */
    gslpp::vector<gslpp::complex>** ComputeCoeffdmumu(double mu, schemes scheme = NDR) const;

    /**
     * @brief Computes the Wilson coefficient for the process \f$ B_d \to \tau \nu \f$.
     * @param[in] mu the lower matching scale for the process
     * @param[in] scheme the scheme in which the Wilson Coefficients need to be calculated
     * @return returns the Wilson coefficients for the process \f$ B_d \to \tau \nu \f$
     *
     */
    gslpp::vector<gslpp::complex>** ComputeCoeffbtaunu(QCD::meson meson_i) const;

    gslpp::vector<gslpp::complex>** ComputeCoeffsnunu() const;

    gslpp::vector<gslpp::complex>** ComputeCoeffdnunu() const;

    /**
     * @brief Computes the Wilson coefficient for the process \f$ b \to s \gamma \f$.
     * @param[in] mu the lower matching scale for the process
     * @param[in] scheme the scheme in which the Wilson Coefficients need to be calculated
     * @return returns the Wilson coefficients for the process \f$ b \to s \gamma \f$
     *
     */
    gslpp::vector<gslpp::complex>** ComputeCoeffsgamma(double mu, bool noSM = false, schemes scheme = NDR) const;

    /**
     * @brief Computes the chirality flipped Wilson coefficient for the process \f$ b \to s \gamma \f$.
     * @param[in] mu the lower matching scale for the process
     * @param[in] scheme the scheme in which the Wilson Coefficients need to be calculated
     * @return returns the chirality flipped Wilson coefficients for the process \f$ b \to s \gamma \f$
     *
     */
    gslpp::vector<gslpp::complex>** ComputeCoeffprimesgamma(double mu, schemes scheme = NDR) const;

    /**
     * @brief Computes the Wilson coefficient for the process \f$ B \to V/P \ell^+ \ell^- \f$.
     * @param[in] mu the lower matching scale for the process
     * @param[in] scheme the scheme in which the Wilson Coefficients need to be calculated
     * @return returns the Wilson coefficients for the process \f$ B \to V/P \ell^+ \ell^- \f$
     *
     */
    gslpp::vector<gslpp::complex>** ComputeCoeffBMll(double mu, QCD::lepton lepton, bool noSM = false, schemes scheme = NDR) const;

    /**
     * @brief Computes the chirality flipped Wilson coefficient for the process \f$ B \to V/P \ell^+ \ell^- \f$.
     * @param[in] mu the lower matching scale for the process
     * @param[in] scheme the scheme in which the Wilson Coefficients need to be calculated
     * @return returns the chirality flipped Wilson coefficients for the process \f$ B \to V/P \ell^+ \ell^- \f$
     *
     */
    gslpp::vector<gslpp::complex>** ComputeCoeffprimeBMll(double mu, QCD::lepton lepton, schemes scheme = NDR) const;

    /**
     * @brief Returns the initial and final state dependent object for \f$ B \to V \ell^+ \ell^- \f$.
     * @param[in] meson_i specifies the meson in the initial state
     * @param[in] vector_i specifies the vector in the final state
     * @param[in] lepton_i specifies the lepton in the final state
     * @return returns a pointer to the initial and final state dependent object for the process \f$ B \to V \ell^+ \ell^- \f$
     *
     */
    MVll& getMVll(QCD::meson meson_i, QCD::meson vector_i, QCD::lepton lep_i) const;

    /**
     * @brief Returns the initial and final state dependent object for \f$ B \to P \ell^+ \ell^- \f$.
     * @param[in] meson_i specifies the meson in the initial state
     * @param[in] pseudoscalar_i specifies the vector in the final state
     * @param[in] lepton_i specifies the lepton in the final state
     * @return returns a pointer to the initial and final state dependent object for the process \f$ B \to P \ell^+ \ell^- \f$
     *
     */
    MPll& getMPll(QCD::meson meson_i, QCD::meson pseudoscalar_i, QCD::lepton lep_i) const;

    /**
     * @brief Returns the initial and final state dependent object for \f$ B \to V \gamma \f$.
     * @param[in] meson_i specifies the meson in the initial state
     * @param[in] vector_i specifies the vector in the final state
     * @return returns a pointer to the initial and final state dependent object for the process \f$ B \to V \gamma \f$
     *
     */
    MVgamma& getMVgamma(QCD::meson meson_i, QCD::meson vector_i) const;

    /**
     * @brief Returns the initial and final state dependent object for \f$ B \to V \ell \nu \f$.
     * @param[in] meson_i specifies the meson in the initial state
     * @param[in] vector_i specifies the vector in the final state
     * @param[in] lepton_i specifies the lepton in the final state
     * @return returns a pointer to the initial and final state dependent object for the process \f$ B \to V \ell^+ \ell^- \f$
     *
     */
    MVlnu& getMVlnu(QCD::meson meson_i, QCD::meson vector_i, QCD::lepton lep_i) const;

    /**
     * @brief Returns the initial and final state dependent object for \f$ B \to P \ell \nu \f$.
     * @param[in] meson_i specifies the meson in the initial state
     * @param[in] pseudoscalar_i specifies the vector in the final state
     * @param[in] lepton_i specifies the lepton in the final state
     * @return returns a pointer to the initial and final state dependent object for the process \f$ B \to V \ell \nu \f$
     *
     */
    MPlnu& getMPlnu(QCD::meson meson_i, QCD::meson pseudoscalar_i, QCD::lepton lep_i) const;

    /**
     * @brief sets the update flag for the initial and final state dependent object for \f$ B \to V \ell^+ \ell^- \f$.
     * @param[in] meson_i specifies the meson in the initial state
     * @param[in] vector_i specifies the vector in the final state
     * @param[in] lepton_i specifies the lepton in the final state
     *
     */
    void setUpdateFlag(QCD::meson meson_i, QCD::meson meson_j, QCD::lepton lep_i, bool updated_i) const;

    /**
     * @brief gets the update flag for the initial and final state dependent object for \f$ B \to V \ell^+ \ell^- \f$.
     * @param[in] meson_i specifies the meson in the initial state
     * @param[in] vector_i specifies the vector in the final state
     * @param[in] lepton_i specifies the lepton in the final state
     *
     */
    bool getUpdateFlag(QCD::meson meson_i, QCD::meson meson_j, QCD::lepton lep_i) const;

    /**
     * @brief a member used for the caching for \f$ B \to V \ell^+ \ell^- \f$.
     *
     */
    void setSMupdated() const;

    bool setFlagUseDispersionRelation(bool dispersion)
    {
        return (this->dispersion = dispersion);
    }

    bool setFlagCLN(bool CLNflag)
    {
        return (this->CLNflag = CLNflag);
    }

    bool setFlagbtocNPpm(bool btocNPpmflag)
    {
        return (this->btocNPpmflag = btocNPpmflag);
    }

    bool setFlagFixedWCbtos(bool FixedWCbtosflag)
    {
        return (this->FixedWCbtosflag = FixedWCbtosflag);
    }

    bool getFlagUseDispersionRelation() const
    {
        return dispersion;
    }

    bool getFlagCLN() const
    {
        return CLNflag;
    }

    bool getbtocNPpmflag() const
    {
        return btocNPpmflag;
    }

    bool getFlagFixedWCbtos() const
    {
        return FixedWCbtosflag;
    }

private:
    template<typename T, typename... Args> std::shared_ptr<T>& getPtr(std::shared_ptr<T>& x, Args... args) const;
    
    const StandardModel & mySM;
    mutable std::shared_ptr<HeffDF2> HDF2; ///< An Object for the Hamiltonian of the \f$ \Delta F = 2 \f$ processes.
    mutable std::shared_ptr<HeffDB1> HDB1; ///< An Object for the Hamiltonian of the \f$ \Delta B = 1 \f$ processes.
    mutable std::shared_ptr<HeffDS1> HDS1; ///< An Object for the Hamiltonian of the \f$ \Delta S = 1 \f$ processes.
    mutable std::shared_ptr<MVll> MVll_BdKstarmu; ///< An object for the process \f$ B_d \to K^* \mu^+ \mu^- \f$.
    mutable std::shared_ptr<MVll> MVll_BdKstarel; ///< An object for the process \f$ B_d \to K^* \e^+ \e^- \f$.
    mutable std::shared_ptr<MVll> MVll_BpKstarmu; ///< An object for the process \f$ B^\pm \to K^{*\pm} \mu^+ \mu^- \f$.
    mutable std::shared_ptr<MVll> MVll_BpKstarel; ///< An object for the process \f$ B^\pm \to K^{*\pm} \e^+ \e^- \f$.
    mutable std::shared_ptr<MVll> MVll_Bsphimu; ///< An object for the process \f$ B_s \to \phi \mu^+ \mu^- \f$.
    mutable std::shared_ptr<MVll> MVll_Bsphiel; ///< An object for the process \f$ B_s \to \phi \e^+ \e^- \f$.
    mutable std::shared_ptr<MPll> MPll_BpKmu; ///< An object for the process \f$ B^+ \to K^+ \mu^+ \mu^- \f$.
    mutable std::shared_ptr<MPll> MPll_BpKel; ///< An object for the process \f$ B^+ \to K^+ \e^+ \e^- \f$.
    mutable std::shared_ptr<MPll> MPll_B0Kmu; ///< An object for the process \f$ B^0 \to K^0 \mu^+ \mu^- \f$.
    mutable std::shared_ptr<MPll> MPll_B0Kel; ///< An object for the process \f$ B^0 \to K^0 \e^+ \e^- \f$.
    mutable std::shared_ptr<MVgamma> MVgamma_BdKstgamma;
    mutable std::shared_ptr<MVgamma> MVgamma_BpKstgamma;
    mutable std::shared_ptr<MVgamma> MVgamma_Bsphigamma;
    mutable std::shared_ptr<MVlnu> MVlnu_BdbarDstartaunu; ///< An object for the process \f$ \bar{B} \to D^* \tau^- \nu \f$.
    mutable std::shared_ptr<MVlnu> MVlnu_BdbarDstarmunu; ///< An object for the process \f$ \bar{B} \to D^* \mu^- \nu  \f$.
    mutable std::shared_ptr<MVlnu> MVlnu_BdbarDstarelnu; ///< An object for the process \f$ \bar{B} \to D^* \e^- \nu  \f$.
    mutable std::shared_ptr<MPlnu> MPlnu_BdbarDtaunu; ///< An object for the process \f$ \bar{B} \to D \tau^- \nu \f$.
    mutable std::shared_ptr<MPlnu> MPlnu_BdbarDmunu; ///< An object for the process \f$ \bar{B} \to D \mu^- \nu  \f$.
    mutable std::shared_ptr<MPlnu> MPlnu_BdbarDelnu; ///< An object for the process \f$ \bar{B} \to D \e^- \nu  \f$.
    mutable bool update_BdKstarmu; ///< A flag used for caching of \f$ B_d \to K^* \mu^+ \mu^- \f$.
    mutable bool update_BdKstarel; ///< A flag used for caching of \f$ B_d \to K^* \e^+ \e^- \f$.
    mutable bool update_BpKstarmu; ///< A flag used for caching of \f$ B_d \to K^{*\pm} \mu^+ \mu^- \f$.
    mutable bool update_BpKstarel; ///< A flag used for caching of \f$ B_d \to K^{*\pm} \e^+ \e^- \f$.
    mutable bool update_Bsphimu; ///< A flag used for caching of \f$ B_s \to \phi \mu^+ \mu^- \f$.
    mutable bool update_Bsphiel; ///< A flag used for caching of \f$ B_s \to \phi \e^+ \e^- \f$.
    mutable bool update_BpKmu; ///< A flag used for caching of \f$ B^+ \to K^+ \mu^+ \mu^- \f$.
    mutable bool update_BpKel; ///< A flag used for caching of \f$ B^+ \to K^+ \e^+ \e^- \f$.
    mutable bool update_B0Kmu; ///< A flag used for caching of \f$ B^0 \to K^0 \mu^+ \mu^- \f$.
    mutable bool update_B0Kel; ///< A flag used for caching of \f$ B^0 \to K^0 \e^+ \e^- \f$.
    mutable bool update_BdKstgamma;
    mutable bool update_BpKstgamma;
    mutable bool update_Bsphigamma;
    mutable bool update_BdDstartaunu;
    mutable bool update_BdDstarmunu;
    mutable bool update_BdDstarelnu;
    mutable bool update_BdDtaunu;
    mutable bool update_BdDmunu;
    mutable bool update_BdDelnu;
    mutable bool dispersion;
    mutable bool CLNflag;
    mutable bool btocNPpmflag;
    mutable bool FixedWCbtosflag;
};

/**
 * @}
 */

#endif /* FLAVOUR_H */
