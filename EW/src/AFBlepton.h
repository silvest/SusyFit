/* 
 * File:   AFBlepton.h
 * Author: mishima
 */

#ifndef AFBLEPTON_H
#define	AFBLEPTON_H

#include <ThObservable.h>
#include "EW.h"


class AFBlepton : public ThObservable {
public:
 
    /**
     * @brief AFBlepton constructor
     * @param[in] EW_i an object of EW class
     */
    AFBlepton(const EW& EW_i) : ThObservable(EW_i), myEW(EW_i) {};

    /**
     * @return the forward-backward asymmetry of a leptonic channel
     */
    double getThValue();

    
private:
    const EW& myEW;
};

#endif	/* AFBLEPTON_H */

