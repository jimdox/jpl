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
    jpl_vector(){};
    virtual ~jpl_vector(){};

    virtual float getX(){ return x; };
    virtual float getY(){ return y; };
    virtual void print(){};


private:
    float x,y;
};
};



