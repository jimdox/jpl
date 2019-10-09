#pragma once
#include "vec3f.hpp"

namespace jpk {
class vec4f : public jpk_vector
{
public:
    vec4f(float x, float y, float z, float a) 
    {
        this->x = x;
        this->y = y; 
        this->z = z;
        this->a = a;
    }
    vec4f(vec3f* vector, float a)
    {
        x = vector->get_x();
        y = vector->get_y();
        z = vector->get_z();
        this->a = a;
    }   
    ~vec4f(){ }

    float get_x(){ return x; }
    float get_y(){ return y; } 
    float get_z(){ return z; }
    float get_a(){ return a; }

    inline vec4f operator+(vec4f& vector)
    { 
        float i = x + vector.get_x(); 
        float j = y + vector.get_y();
        float k = z + vector.get_z();
        float m = a + vector.get_a();
        return vec4f(i, j, k, m);
    }

    inline vec4f operator-(vec4f& vector)
    {
        float i = x - vector.get_x();
        float j = y - vector.get_y();
        float k = z - vector.get_z();
        float m = a - vector.get_a();
        return vec4f(i, j, k, m);
    }

    inline vec4f operator*(float scale){ return vec4f(scale * x, scale * y, scale * z, scale * a); }
   	
	inline vec4f operator*(vec4f& vec_b){ return vec4f(vec_b.get_x()*x, vec_b.get_y()*y, vec_b.get_z()*z, vec_b.get_a()*a); } 

    void dot(vec4f* vector)
    {
        return x * vector->get_x() + y * vector->get_y() + z * vector->get_z() + a * vector->get_a();
    }

    void mix(vec4f* vector)
    {
        x = (x+vector->get_x())/2;
        y = (y+vector->get_y())/2;
        z = (z+vector->get_z())/2;
        a = (a+vector->get_a())/2;
    } 

    float mag()
    {
        return sqrt( (x*x) + (y*y) + (z*z) + (a*a));
    }

    void print()
    {
        printf("%f %f, %f %f\n", x, y, z, a);
    }




private:
    float x,y,z,a;

};
};
