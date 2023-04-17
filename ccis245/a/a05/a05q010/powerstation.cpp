/***************************************************************************

File  : powerstation.cpp
Author: Carl Dalebout

Implementation of functions prototypes in powerstation.h




***************************************************************************/
#include <iostream>
#include "powerstation.h"


void init(PowerStation & p, int x, int y, int energylevel)
{
    p.x = x;
    p.y = y;
    p.energylevel = energylevel;
}
