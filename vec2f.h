    #pragma once
#include "jpk_vector.h"


namespace jpk {
class vec2f : public jpk_vector 
{

public:
    vec2f(float x, float y){ this->x = x; this->y = y; }
    ~vec2f(){ };

    inline float get_x() { return x; }
    inline float get_y() { return y; }

    inline vec2f operator+(vec2f* vector)
    { 
        float i = x + vector->get_x();
        float j = y + vector->get_y();
        return vec2f(i,j);
    }

    inline vec2f operator-(vec2f* vector)
    {
        float i = x - vector->get_x();
        float j = y - vector->get_y();
        return vec2f(i,j);
    }

    inline vec2f operator*(float scale){ return vec2f(scale * x, scale * y); }
    
    inline vec2f operator*(vec2f& vec_b){ return vec2f( vec_b.get_x()*x, vec_b.get_y()*y); }
    
    void dot(vec2f& vector)
    {
        x *= vector.get_x();
        y *= vector.get_y();
    }

    void mix(vec2f* vector)
    {
        x = (x + vector->get_x())/2;
        y = (y + vector->get_y())/2;
    }

    float dir()
    {
        return atan(y/x);
    }

    float mag()
    {
        return sqrt( (x*x) + (y*y));
    }

    void print()
    {
        printf("%f %f\n", x, y);
    }

private: 

    float x,y; 

};
};
