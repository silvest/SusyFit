/* 
 * File:   CKM.h
 * Author: ayanpaul
 *
 * Created on April 23, 2015, 2:21 PM
 */

#ifndef VCKM_H
#define	VCKM_H

#include <ThObservable.h>

class VCKM : public ThObservable {
public:
    VCKM(const StandardModel& SM_i, unsigned int obsFlag_1,  unsigned int obsFlag_2);

    double computeThValue();
    
    virtual ~VCKM();
    
private:
    unsigned int obs_1;
    unsigned int obs_2;
        
};

#endif	/* VCKM_H */
