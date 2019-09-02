#pragma once
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


namespace jpk 
{
class jpk_vector {

public:
jpk_vector(){};
virtual ~jpk_vector(){};

virtual float getX(){};
virtual float getY(){};
virtual void print(){};
virtual float dir(){};  // direction of vector 
virtual float mag(){};  // magnitude of vector


private:



};
};



