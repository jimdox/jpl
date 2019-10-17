#pragma once
#include "vec2f.hpp"

/* @author: James Doxtader
            github.com/jimdox/jpl
*/

namespace jpl {
class vec3f : public jpl_vector
{

public:
    vec3f(){ x,y,z = 0.0f; }
    
    vec3f(float x, float y, float z){ this->x = x; this->y = y; this->z = z; }
    vec3f(vec2f* vector, float z){ x = vector->get_x(); y = vector->get_y(); this->z = z; }

    ~vec3f(){ }

    inline float get_x()const { return x; }
    inline float get_y()const { return y; } 
    inline float get_z()const { return z; }

    vec3f operator+(const vec3f &vector)
    { 
        float i = x + vector.get_x(); 
        float j = y + vector.get_y();
        float k = z + vector.get_z();
        return vec3f(i, j, k);
    }

    void operator+=(const vec3f& vector)
    {
        x += vector.get_x();
        y += vector.get_y();
        z += vector.get_z();
    }

    vec3f operator-(const vec3f& vector)
    {
        float i = x - vector.get_x();
        float j = y - vector.get_y();
        float k = z - vector.get_z();
        return vec3f(i, j, k);
    }

    vec3f operator*(float scale) const 
    { 
        return vec3f(scale * x, scale * y, scale * z);
    }

    void operator*=(float scale)
    {
        x * scale;
        y * scale;
        z * scale;
    }
    
	vec3f operator*(const vec3f& vec_b)
    { 
        return vec3f(vec_b.get_x() * x, vec_b.get_y() * y, vec_b.get_z() * z); 
    } 

    float dot(vec3f* vector)
    {
        return x * vector->get_x() + y * vector->get_y() + z * vector->get_z();
    }

    void cross(const vec3f* vector)
    {
        float i,j,k;    // components of resulting vector
        i = (y * vector->get_z()) - (z * vector->get_y());
        j = (z * vector->get_x()) - (x * vector->get_z());
        k = (x * vector->get_y()) - (y * vector->get_x());

        x = i;
        y = j;
        z = k;
    }

    /* return the length of the vector */
    inline float mag()
    {
        return sqrt( (x * x) + (y * y) + (z * z));
    }

    void mix(const vec3f* vector)
    {
        x = (x+vector->get_x()) / 2;
        y = (y+vector->get_y()) / 2;
        z = (z+vector->get_z()) / 2;
    } 

    void print()
    {
        printf("%f %f, %f\n", x, y, z);
    }

private:

    float x, y, z;

};
};
