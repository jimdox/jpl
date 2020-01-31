#pragma once
#include "vec3x.hpp"

/* @author: James Doxtader
            github.com/jimdox/jpl
*/

namespace jpl {
class vec4f : public vec3x
{
public:
    vec4f()
    {
        x,y,z,a = 0;
    }

    vec4f(long double x, long double y, long double z, long double a) 
    {
        this->x = x;
        this->y = y; 
        this->z = z;
        this->a = a;
    }

    vec4f(const vec4f* vec)
    {
        x = vec->get_x();
        y = vec->get_y();
        z = vec->get_z();
        a = vec->get_a();
    }

    vec4f(vec3x* vec, long double a)
    {
        x = vec->get_x();
        y = vec->get_y();
        z = vec->get_z();
        this->a = a;
    }   
    
    ~vec4f(){ }

    inline long double get_a()const { return a; }

    vec4f operator+(vec4f& vec)
    { 
        long double i = x + vec.get_x(); 
        long double j = y + vec.get_y();
        long double k = z + vec.get_z();
        long double m = a + vec.get_a();
        return vec4f(i, j, k, m);
    }

    vec4f operator-(vec4f& vec)
    {
        long double i = x - vec.get_x();
        long double j = y - vec.get_y();
        long double k = z - vec.get_z();
        long double m = a - vec.get_a();
        return vec4f(i, j, k, m);
    }

    vec4f operator*(long double scale){ return vec4f(scale * x, scale * y, scale * z, scale * a); }
   	
    long double dot(vec4f* vec)
    {
        return x * vec->get_x() + y * vec->get_y() + z * vec->get_z() + a * vec->get_a();
    }

    inline long double mag()
    {
        return sqrt( (x*x) + (y*y) + (z*z) + (a*a));
    }

    void mix(vec4f* vec)
    {
        x = (x+vec->get_x())/2;
        y = (y+vec->get_y())/2;
        z = (z+vec->get_z())/2;
        a = (a+vec->get_a())/2;
    } 

    void print()
    {
        printf("%f %f, %f %f\n", x, y, z, a);
    }

    long double a;

protected:
};
};
