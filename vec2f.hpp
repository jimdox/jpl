#pragma once
#include "jpl_vector.hpp"

/* @author: James Doxtader
            github.com/jimdox/jpl
*/

namespace jpl {
class vec2f : public jpl_vector
{
public:
    vec2f(){ x,y = 0; }
    
    vec2f(float x, float y)
    { 
        this->x = x;
        this->y = y;
    }

    vec2f(const vec2f* vec)
    {
        this->x = vec->get_x();
        this->y = vec->get_y();
    }

    ~vec2f(){ };

    inline float get_x()const { return x; }
    inline float get_y()const { return y; }

    vec2f operator+(const vec2f& vec)
    { 
        float i = x + vec.get_x();
        float j = y + vec.get_y();
        return vec2f(i,j);
    }
    void operator+=(const vec2f& vec)
    {
        x += vec.get_x();
        y += vec.get_y();
    }

    vec2f operator-(const vec2f& vec)
    {
        float i = x - vec.get_x();
        float j = y - vec.get_y();
        return vec2f(i,j);
    }

    void operator-=(const vec2f& vec)
    {
        x -= vec.get_x();
        y -= vec.get_y();
    }

    vec2f operator*(float scale){ return vec2f(scale * x, scale * y); }

    void operator*=(float scale){ x * scale; y * scale; }
    
    vec2f operator*(vec2f& vec_b){ return vec2f( vec_b.get_x()*x, vec_b.get_y()*y); }
    
    float dot(vec2f* vec)
    {
        return  x * vec->get_x() + y * vec->get_y();
    }

    vec2f normalize()
    {
        vec2f vec(x, y);
        return vec * (1/vec.mag());
    }

    void mix(vec2f* vec)
    {
        x = (x + vec->get_x())/2;
        y = (y + vec->get_y())/2;
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