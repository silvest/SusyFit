/* 
 * File:   Mw.h
 * Author: mishima
 */

#ifndef MW_H
#define	MW_H

#include <ThObservable.h>
#include "EW.h"
#include "EW_CHMN.h"


class Mw : public ThObservable {
public:

    /**
     * @brief Mw constructor
     * @param[in] EW_i an object of EW class
     * @param[in] bCHMN_i true if using EW_CHMN class 
     */
    Mw(const EW& EW_i, const bool bCHMN_i=false) : ThObservable(EW_i), 
            myEW(EW_i), myEW_CHMN(EW_i.getSM()), bCHMN(bCHMN_i) {};

    /**
     * @return the W-boson mass
     */
    double getThValue();

    
private:
    const EW& myEW;
    const EW_CHMN myEW_CHMN;
    const bool bCHMN;
};

#endif	/* MW_H */

