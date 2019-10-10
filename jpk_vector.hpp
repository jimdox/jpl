#pragma once
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* @author: James Doxtader
            github.com/jimdox/jpk
*/

namespace jpk 
{
class jpk_vector {

public:
    jpk_vector(){};
    virtual ~jpk_vector(){};

    virtual float getX(){ return x; };
    virtual float getY(){ return y; };
    virtual void print(){};


private:
    float x,y;
};
};



