#pragma once
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* @author: James Doxtader
            github.com/jimdox/jpl
*/

namespace jpl 
{
class jpl_vector {

public:
    jpl_vector(){}
    virtual ~jpl_vector(){}

    virtual float get_x(){ return x; }
    virtual float get_y(){ return y; }

    virtual float mag(){ return x*x + y*y; }
    virtual void print(){}


private:
    float x,y;
};
};



