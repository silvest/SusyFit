/*
 * Copyright (C) 2012 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#include "DmBs.h"
#include "StandardModel.h"
#include "AmpDB2.h"

double  DmBs::computeThValue()
{
    return(2. * SM.getCBs() * SM.getFlavour().getDB2(1).getM21(FULLNLO).abs());
}

double  RmBs::computeThValue()
{
    return SM.getFlavour().getDB2(1).getRB(FULLNLO).abs()-1.;
}
