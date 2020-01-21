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
    vec3x()
    {
        x = 0.0L;
        y = 0.0L;
        z = 0.0L;
    }    

    vec3x(long double x, long double y, long double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    vec3x(const vec3x* v)
    {
        this->x = v->get_x();
        this->y = v->get_y(); 
        this->z = v->get_z();
    }

    vec3x(vec2x* v, long double z)
    {
        x = v->get_x();
        y = v->get_y();
        this->z = z;
    }

    ~vec3x(){ }

    inline long double get_z()const { return z; }

    vec3x operator+(const vec3x &v)
    {
        return vec3x(x + v.x, y + v.y, z + v.z);
    }

    void operator+=(const vec3x& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
    }

    vec3x operator-(const vec3x& v)
    {
        return vec3x(x - v.x, y - v.y, z - v.z);
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

    inline long double dot(vec3x& vector)
    {
        return x * vector.get_x() + y * vector.get_y() + z * vector.get_z();
    }

    void cross(vec3x& vector)
    {
        long double i,j,k;    // components of resulting vector
        i = (y * vector.get_z()) - (z * vector.get_y());
        j = (z * vector.get_x()) - (x * vector.get_z());
        k = (x * vector.get_y()) - (y * vector.get_x());

        x = i;
        y = j;
        z = k;
    }

    vec3x normalize()
    {
        vec3x vec(x,y,z);
        return vec * (1/vec.length());
    }

    /* orthog. projection onto u vec. */
    vec3x proj(vec3x& u)
    {
        return u * (dot(u)/(pow(u.length(), 2)));
    }

    /* return the magnitude */
    inline long double length()
    {
        return sqrt( (x * x) + (y * y) + (z * z));
    }

    vec3x mix(vec3x& vector)
    {
        return vec3x((x+vector.get_x())/2, (y+vector.get_y())/2,  (z+vector.get_z())/2);
    } 


    long double z;
};
};