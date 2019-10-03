#pragma once
#include "jpk_vector.h"
#include "vec2f.h"

namespace jpk {
class vec3f : public jpk_vector
{

public:
    vec3f(){ x,y,z = 0.0f; }
    vec3f(float x, float y, float z){ this->x = x; this->y = y; this->z = z; }
    vec3f(vec2f* vector, float z){ x = vector->get_x(); y = vector->get_y(); this->z = z; }
    ~vec3f(){ }

    float get_x(){ return x; }
    float get_y(){ return y; } 
    float get_z(){ return z; }


    inline vec3f operator+(vec3f& vector)
    { 
        float i = x + vector.get_x(); 
        float j = y + vector.get_y();
        float k = z + vector.get_z();
        return vec3f(i, j, k);
    }

    inline void operator+=(vec3f& vector)
    {
        x += vector.get_x();
        y += vector.get_y();
        z += vector.get_z();
    }

    inline vec3f operator-(vec3f& vector)
    {
        float i = x - vector.get_x();
        float j = y - vector.get_y();
        float k = z - vector.get_z();
        return vec3f(i, j, k);
    }

    inline vec3f operator*(float scale){ return vec3f(scale * x, scale * y, scale * z); }
    
	inline vec3f operator*(vec3f& vec_b){ return vec3f(vec_b.get_x()*x, vec_b.get_y()*y, vec_b.get_z()*z); } 
	

    void dot(vec3f* vector)
    {
        x *= vector->get_x();
        y *= vector->get_y();
        z *= vector->get_z();
    }

    void cross(vec3f* vector)
    {
        float i,j,k;    // components of resulting vector
        i = (y * vector->get_z()) - (z * vector->get_y());
        j = (z * vector->get_x()) - (x * vector->get_z());
        k = (x * vector->get_y()) - (y * vector->get_x());

        x = i;
        y = j;
        z = k;
    }

    void cross(vec2f* vector)
    {
        vec3f vb(vector->get_x(), vector->get_y(), 0.0f);
        cross(&vb);
    }

    void mix(vec3f* vector)
    {
        x = (x+vector->get_x())/2;
        y = (y+vector->get_y())/2;
        z = (z+vector->get_z())/2;

    } 

    float mag()
    {
        return sqrt( (x*x) + (y*y) + (z*z));
    }

    void print()
    {
        printf("%f %f, %f\n", x, y, z);
    }

private:

    float x,y,z;

};
};
