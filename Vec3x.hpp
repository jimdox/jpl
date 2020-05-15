#pragma once
#include "Vec2x.hpp"

/* @author: James Doxtader
            github.com/jimdox/jpl

    Vec3x: 10 byte f.p. extended precision 3D vector
*/

namespace Rkt 
{
class Vec3x : public Vec2x
{
public:
    Vec3x() : Vec2x()
    {
        z = 0.0L;
    }    

    Vec3x(long double x, long double y, long double z) : Vec2x(x, y), z(z) {}

    Vec3x(const Vec3x& v)
    {
        this->x = v.x;
        this->y = v.y; 
        this->z = v.z;
    }

    Vec3x(Vec2x& v, long double z)
    {
        x = v.x;
        y = v.y;
        this->z = z;
    }

    ~Vec3x() {}

    inline long double GetZ() const { return z; }

    Vec3x operator+(const Vec3x &v)
    {
        return Vec3x(x + v.x, y + v.y, z + v.z);
    }

    void operator+=(const Vec3x& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
    }

    Vec3x operator-(const Vec3x& v)
    {
        return Vec3x(x - v.x, y - v.y, z - v.z);
    }

    void operator-=(const Vec3x& vec)
    {
        x -= vec.get_x();
        y -= vec.get_y();
        z -= vec.get_z();
    }

    Vec3x operator*(long double scale) const 
    { 
        return Vec3x(scale * x, scale * y, scale * z);
    }

    void operator*=(long double scale)
    {
        x * scale;
        y * scale;
        z * scale;
    }

    inline long double Dot(Vec3x& vector)
    {
        return x * vector.get_x() + y * vector.get_y() + z * vector.get_z();
    }

    void Cross(Vec3x& vector)
    {
        long double i,j,k;    // components of resulting vector
        i = (y * vector.get_z()) - (z * vector.get_y());
        j = (z * vector.get_x()) - (x * vector.get_z());
        k = (x * vector.get_y()) - (y * vector.get_x());

        x = i;
        y = j;
        z = k;
    }

    Vec3x Normalize()
    {
        Vec3x vec(x,y,z);
        return vec * (1/vec.length());
    }

    /* orthog. projection onto u vec. */
    Vec3x GetOrthoProjection(Vec3x& u)
    {
        return u * (dot(u)/(pow(u.length(), 2)));
    }

    /* return the magnitude */
    inline long double Length()
    {
        return sqrt( (x * x) + (y * y) + (z * z));
    }

    Vec3x Mix(Vec3x& vector)
    {
        return Vec3x((x+vector.get_x())/2, (y+vector.get_y())/2,  (z+vector.get_z())/2);
    } 


    long double z;
};
};