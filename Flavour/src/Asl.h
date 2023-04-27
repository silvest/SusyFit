/* 
 * Copyright (C) 2023 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#ifndef ASL_H
#define ASL_H
#include "ThObservable.h"
#include "AmpDB2.h"

#include "gslpp.h"


class Asl_d : public ThObservable, AmpDB2{
public:
    /**
     * @brief Constructor.
     * @param[in] SM_i a reference to an object of type StandardModel
     */
    Asl_d(const StandardModel& SM_i);
    
    /**
     * @brief Destructor.
     */
    virtual ~Asl_d();
    
    double computeThValue ();

    private:
};

class Asl_s : public ThObservable, AmpDB2{
public:
    /**
     * @brief Constructor.
     * @param[in] SM_i a reference to an object of type StandardModel
     */
    Asl_s(const StandardModel& SM_i);
    
    /**
     * @brief Destructor.
     */
    virtual ~Asl_s();
    
    double computeThValue();

    private:
};
 
#endif /* ASL_H */

