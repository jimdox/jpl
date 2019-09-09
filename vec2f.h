#pragma once
#include "jpk_vector.h"


namespace jpk {
class vec2f : public jpk_vector 
{

public:
    vec2f(float x, float y){ this->x = x; this->y = y; }
    ~vec2f(){ };

    inline float getX() { return x; }
    inline float getY() { return y; }

    inline vec2f operator+(vec2f* vector)
    { 
        float i = x + vector->getX();
        float j = y + vector->getY();
        return vec2f(i,j);
    }

    inline vec2f operator-(vec2f* vector)
    {
        float i = x - vector->getX();
        float j = y - vector->getY();
        return vec2f(i,j);
    }

    inline vec2f operator*(float scale){ return vec2f(scale * x, scale * y); }


    void dot(vec2f* vector)
    {
        x *= vector->getX();
        y *= vector->getY();
    }

    void mix(vec2f* vector)
    {
        x = (x + vector->getX())/2;
        y = (y + vector->getY())/2;
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