#pragma once
#include "vec2f.hpp"

/* @author: James Doxtader
            github.com/jimdox/jpl
*/

namespace jpl {
class vec3f : public vec2f
{
public:
    vec3f(){ x,y,z = 0.0f; }
    
    vec3f(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    vec3f(const vec3f* vec)
    {
        this->x = vec->get_x();
        this->y = vec->get_y(); 
        this->z = vec->get_z();
    }

    vec3f(vec2f* vector, float z)
    {
        x = vector->get_x();
        y = vector->get_y();
        this->z = z;
    }

    ~vec3f(){ }

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

    void operator-=(const vec3f& vec)
    {
        x -= vec.get_x();
        y -= vec.get_y();
        z -= vec.get_z();
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

    vec3f normalize()
    {
        vec3f vec(x,y,z);
        return vec * (1/vec.mag());
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
        printf("%e %e, %e\n", x, y, z);
    }
    
    float z;

protected:
};
};
