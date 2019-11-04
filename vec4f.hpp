#pragma once
#include "vec3f.hpp"

/* @author: James Doxtader
            github.com/jimdox/jpl
*/

namespace jpl {
class vec4f : public vec3f
{
public:
    vec4f()
    {
        x,y,z,a = 0;
    }

    vec4f(float x, float y, float z, float a) 
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

    vec4f(vec3f* vec, float a)
    {
        x = vec->get_x();
        y = vec->get_y();
        z = vec->get_z();
        this->a = a;
    }   
    
    ~vec4f(){ }

    inline float get_a()const { return a; }

    vec4f operator+(vec4f& vec)
    { 
        float i = x + vec.get_x(); 
        float j = y + vec.get_y();
        float k = z + vec.get_z();
        float m = a + vec.get_a();
        return vec4f(i, j, k, m);
    }

    vec4f operator-(vec4f& vec)
    {
        float i = x - vec.get_x();
        float j = y - vec.get_y();
        float k = z - vec.get_z();
        float m = a - vec.get_a();
        return vec4f(i, j, k, m);
    }

    vec4f operator*(float scale){ return vec4f(scale * x, scale * y, scale * z, scale * a); }
   	
    vec4f operator*(vec4f& vec_b){ return vec4f(vec_b.get_x()*x, vec_b.get_y()*y, vec_b.get_z()*z, vec_b.get_a()*a); } 

    float dot(vec4f* vec)
    {
        return x * vec->get_x() + y * vec->get_y() + z * vec->get_z() + a * vec->get_a();
    }

    inline float mag()
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

protected:
    float a;

};
};
