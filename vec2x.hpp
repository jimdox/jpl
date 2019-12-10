#pragma once
#include <cmath>
#include <stdio.h>
/* @author: James Doxtader
            github.com/jimdox/jpl
    
    vec2x: extended precision type
*/

namespace jpl {

class vec2x
{
public:
    vec2x()
    {
        x = 0.0L;
        y = 0.0L; 
    }
    
    vec2x(long double x, long double y)
    { 
        this->x = x;
        this->y = y;
    }

    vec2x(const vec2x* v)
    {
        this->x = v->get_x();
        this->y = v->get_y();
    }

    ~vec2x(){ };

    inline long double get_x()const { return x; }
    inline long double get_y()const { return y; }

    vec2x operator+(const vec2x& v)
    { 
        return vec2x(x + v.x, y + v.y);
    }
    void operator+=(const vec2x& v)
    {
        x += v.x;
        y += v.x;
    }

    vec2x operator-(const vec2x& v)
    {

        return vec2x(x + v.x, y + v.y);
    }

    vec2x operator-()
    {
        return vec2x(-x, -y);
    }

    void operator-=(const vec2x& vec)
    {
        x -= vec.get_x();
        y -= vec.get_y();
    }

    vec2x operator*(long double scale){ return vec2x(scale * x, scale * y); }

    void operator*=(long double scale){ x * scale; y * scale; }
    
    vec2x operator*(vec2x& v){ return vec2x( x * v.x, y * v.y); }
    
    long double dot(const vec2x& v)
    {
        return  x * v.get_x() + y * v.get_y();
    }

    vec2x normalize()
    {
        vec2x vec(x, y);
        return vec * (1/vec.length());
    }

    vec2x proj(vec2x& u)
    {
        return u * (dot(u)/(u.dot(u)));
    }

    vec2x mix(vec2x* vec)
    {
        return vec2x((x + vec->get_x()), (y + vec->get_y())/2);
    }

    inline long double dir()
    {
        return atan(y/x);
    }

    inline long double length()
    {
        return sqrt( (x*x) + (y*y));
    }

    long double x, y;

protected: 
};
};
