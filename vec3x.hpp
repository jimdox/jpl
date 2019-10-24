#pragma once
#include "vec2x.hpp"

/* @author: James Doxtader
            github.com/jimdox/jpl

    vec3x: extended precision type
*/

namespace jpl {
class vec3x : public vec2x
{
public:
    vec3x(){ x,y,z = 0.0f; }
    
    vec3x(long double x, long double y, long double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    vec3x(const vec3x* vec)
    {
        this->x = vec->get_x();
        this->y = vec->get_y(); 
        this->z = vec->get_z();
    }

    vec3x(vec2x* vector, long double z)
    {
        x = vector->get_x();
        y = vector->get_y();
        this->z = z;
    }

    ~vec3x(){ }

    inline long double get_x()const { return x; }
    inline long double get_y()const { return y; } 
    inline long double get_z()const { return z; }

    vec3x operator+(const vec3x &vector)
    { 
        long double i = x + vector.get_x(); 
        long double j = y + vector.get_y();
        long double k = z + vector.get_z();
        return vec3x(i, j, k);
    }

    void operator+=(const vec3x& vector)
    {
        x += vector.get_x();
        y += vector.get_y();
        z += vector.get_z();
    }

    vec3x operator-(const vec3x& vector)
    {
        long double i = x - vector.get_x();
        long double j = y - vector.get_y();
        long double k = z - vector.get_z();
        return vec3x(i, j, k);
    }

    void operator-=(const vec3x& vec)
    {
        x -= vec.get_x();
        y -= vec.get_y();
        z -= vec.get_z();
    }

    vec3x operator*(long double scale) const 
    { 
        return vec3x(scale * x, scale * y, scale * z);
    }

    void operator*=(long double scale)
    {
        x * scale;
        y * scale;
        z * scale;
    }
    
	vec3x operator*(const vec3x& vec_b)
    { 
        return vec3x(vec_b.get_x() * x, vec_b.get_y() * y, vec_b.get_z() * z); 
    } 

    long double dot(vec3x* vector)
    {
        return x * vector->get_x() + y * vector->get_y() + z * vector->get_z();
    }

    void cross(const vec3x* vector)
    {
        long double i,j,k;    // components of resulting vector
        i = (y * vector->get_z()) - (z * vector->get_y());
        j = (z * vector->get_x()) - (x * vector->get_z());
        k = (x * vector->get_y()) - (y * vector->get_x());

        x = i;
        y = j;
        z = k;
    }

    vec3x normalize()
    {
        vec3x vec(x,y,z);
        return vec * (1/vec.mag());
    }

    /* return the length of the vector */
    inline long double mag()
    {
        return sqrt( (x * x) + (y * y) + (z * z));
    }

    void mix(const vec3x* vector)
    {
        x = (x+vector->get_x()) / 2;
        y = (y+vector->get_y()) / 2;
        z = (z+vector->get_z()) / 2;
    } 

    void print()
    {
        printf("%Le %Le, %Le\n", x, y, z);
    }

private:

    long double x, y, z;

};
};
