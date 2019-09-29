#pragma once
#include "vec3f.h"

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
        x = vector->getX();
        y = vector->getY();
        z = vector->getZ();
        this->a = a;
    }   
    ~vec4f(){ }

    float getX(){ return x; }
    float getY(){ return y; } 
    float getZ(){ return z; }
    float getA(){ return a; }

    inline vec4f operator+(vec4f& vector)
    { 
        float i = x + vector.getX(); 
        float j = y + vector.getY();
        float k = z + vector.getZ();
        float m = a + vector.getA();
        return vec4f(i, j, k, m);
    }

    inline vec4f operator-(vec4f& vector)
    {
        float i = x - vector.getX();
        float j = y - vector.getY();
        float k = z - vector.getZ();
        float m = a - vector.getA();
        return vec4f(i, j, k, m);
    }

    inline vec4f operator*(float scale){ return vec4f(scale * x, scale * y, scale * z, scale * a); }
   	
	inline vec4f operator*(vec4f& vec_b){ return vec4f(vec_b.getX()*x, vec_b.getY()*y, vec_b.getZ()*z, vec_b.getA()*a); } 

    void dot(vec4f* vector)
    {
        x *= vector->getX();
        y *= vector->getY();
        z *= vector->getZ();
    }

    void mix(vec4f* vector)
    {
        x = (x+vector->getX())/2;
        y = (y+vector->getY())/2;
        z = (z+vector->getZ())/2;
        a = (a+vector->getA())/2;
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
