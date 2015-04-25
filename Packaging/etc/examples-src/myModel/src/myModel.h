/* 
 * Copyright (C) 2015 SusyFit Collaboration
 * All rights reserved.
 *
 * For the licensing terms see doc/COPYING.
 */

#ifndef MYMODEL_H
#define	MYMODEL_H

#include <SusyFit.h>

/**
 * @class myModel
 * @brief My own Model.
 */
class myModel: public StandardModel {
public:

    static const int NmyModelvars = 4; /* Define number of mandatory parameters in the model. */
    static const std::string myModelvars[NmyModelvars]; /* Vector of model variable names. */
    
    /**
     * @brief myModel constructor
     */
    myModel();
    
    /**
     * @brief myModel destructor
     */
    ~myModel();
    
    virtual bool InitializeModel();
    
    virtual bool Init(const std::map<std::string, double>& DPars);
    
    virtual bool PreUpdate();
    
    virtual bool Update(const std::map<std::string, double>& DPars);
    
    virtual bool PostUpdate();
    
    virtual bool CheckParameters(const std::map<std::string, double>& DPars);
    
    virtual bool setFlag(const std::string name, const bool value);
    
    
    /**
     * 
     * @return the coupling ct
     */
    double getct() const
    {
        return ct;
    };

    /**
     *
     * @return the coupling cg
     */
    double getcg() const
    {
        return cg;
    };
    
    /**
     *
     * @return the coupling cV
     */
    double getcV() const
    {
        return cV;
    };
    
    /**
     *
     * @return the coupling cA
     */
    double getcA() const
    {
        return cA;
    };
    
    /**
     *
     * @return the coupling cA
     */
    bool get_onshell_flag() const
    {
        return onshell;
    };


protected:
    
    virtual void setParameter(const std::string, const double&);

private:
    
    double ct, cg, cV, cA; /* Model Parameters */
    bool onshell;
    
};

#endif	/* MYMODEL_H */

