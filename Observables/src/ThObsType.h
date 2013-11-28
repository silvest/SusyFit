/* 
 * Copyright (C) 2012-2013 SusyFit Collaboration
 * All rights reserved.
 *
 * For the licensing terms see doc/COPYING.
 */

#ifndef THOBSTYPE_H
#define	THOBSTYPE_H

#include <StandardModel.h>

/**
 * @class ThObsType
 * @ingroup Observable
 * @brief A class for a model prediction of an observable. 
 * @author SusyFit Collaboration
 * @copyright GNU General Public License
 * @details  
 */
class ThObsType {
public:
    
    /**
     * @brief The default constructor.
     */
    ThObsType(const StandardModel& SM_i)
    : SM(SM_i) 
    {};
    
    /**
     * @brief The copy constructor.
     */
    ThObsType(const ThObsType& orig)
    : SM(orig.SM) 
    {};
    
    /**
     * @brief The default destructor.
     */
    virtual ~ThObsType()
    {};
    
    /**
     * @brief A get method to access the reference to the model
     * @return the average value of the observable
     */
    const StandardModel& getModel() const
    {
        return SM;
    };

protected:
    const StandardModel& SM; /**< A reference to to an object of the type StandardModel(). */
};

#endif	/* THOBSTYPE_H */
