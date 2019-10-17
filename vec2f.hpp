#pragma once
#include "jpl_vector.hpp"

/* @author: James Doxtader
            github.com/jimdox/jpl
*/

namespace jpl {
class vec2f : public jpl_vector 
{

public:
    vec2f(float x, float y){ this->x = x; this->y = y; }
    ~vec2f(){ };

    inline float get_x()const { return x; }
    inline float get_y()const { return y; }

    vec2f operator+(const vec2f& vector)
    { 
        float i = x + vector.get_x();
        float j = y + vector.get_y();
        return vec2f(i,j);
    }
    void operator+=(const vec2f& vector)
    {
        x += vector.get_x();
        y += vector.get_y();
    }

    vec2f operator-(const vec2f& vector)
    {
        float i = x - vector.get_x();
        float j = y - vector.get_y();
        return vec2f(i,j);
    }
    

    vec2f operator*(float scale){ return vec2f(scale * x, scale * y); }

    void operator*=(float scale){ x * scale; y * scale; }
    
    vec2f operator*(vec2f& vec_b){ return vec2f( vec_b.get_x()*x, vec_b.get_y()*y); }
    
    float dot(vec2f* vector)
    {
        return  x * vector->get_x() + y * vector->get_y();
    }

    void mix(vec2f* vector)
    {
        x = (x + vector->get_x())/2;
        y = (y + vector->get_y())/2;
    }

    inline float dir()
    {
        return atan(y/x);
    }

    inline float mag()
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

