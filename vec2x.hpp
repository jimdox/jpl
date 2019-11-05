#pragma once
#include "vec2f.hpp"
/* @author: James Doxtader
            github.com/jimdox/jpl
    
    vec2x: extended precision type
*/

namespace jpl {
class vec2x
{
public:
    vec2x(){ x,y = 0.0L; }
    
    vec2x(long double x, long double y)
    { 
        this->x = x;
        this->y = y;
    }

    vec2x(const vec2x* vec)
    {
        this->x = vec->get_x();
        this->y = vec->get_y();
    }

    ~vec2x(){ };

    inline long double get_x()const { return x; }
    inline long double get_y()const { return y; }

    vec2x operator+(const vec2x& vec)
    { 
        float i = x + vec.get_x();
        float j = y + vec.get_y();
        return vec2x(i,j);
    }
    void operator+=(const vec2x& vec)
    {
        x += vec.get_x();
        y += vec.get_y();
    }

    vec2x operator-(const vec2x& vec)
    {
        float i = x - vec.get_x();
        float j = y - vec.get_y();
        return vec2x(i,j);
    }

    void operator-=(const vec2x& vec)
    {
        x -= vec.get_x();
        y -= vec.get_y();
    }

    vec2x operator*(float scale){ return vec2x(scale * x, scale * y); }

    void operator*=(float scale){ x * scale; y * scale; }
    
    vec2x operator*(vec2x& vec_b){ return vec2x( vec_b.get_x()*x, vec_b.get_y()*y); }
    
    long double dot(vec2x* vec)
    {
        return  x * vec->get_x() + y * vec->get_y();
    }

    vec2x normalize()
    {
        vec2x vec(x, y);
        return vec * (1/vec.mag());
    }

    void mix(vec2x* vec)
    {
        x = (x + vec->get_x())/2;
        y = (y + vec->get_y())/2;
    }

    inline double dir()
    {
        return atan(y/x);
    }

    inline double mag()
    {
        return sqrt( (x*x) + (y*y));
    }

    void print()
    {
        printf("%Le %Le\n", x, y);
    }

    long double x,y; 


protected: 
};
};
