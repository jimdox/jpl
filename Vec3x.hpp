#pragma once
#include "Vec2x.hpp"

/* @author: James Doxtader
            github.com/jimdox/RocketMath

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
        x -= vec.x;
        y -= vec.y;
        z -= vec.z;
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

    inline long double Dot(const Vec3x& vector)
    {
        return x * vector.x + y * vector.y + z * vector.z;
    }

    void Cross(Vec3x& vector)
    {
        long double i,j,k;    // components of resulting vector
        i = (y * vector.z) - (z * vector.y);
        j = (z * vector.x) - (x * vector.z);
        k = (x * vector.y) - (y * vector.x);

        x = i;
        y = j;
        z = k;
    }

    Vec3x GetNormalized()
    {
        Vec3x vec(x,y,z);
        return vec * (1/vec.Length());
    }

    /* orthog. projection onto u vec. */
    Vec3x GetOrthoProjection(Vec3x& u)
    {
        return u * (Dot(u)/(pow(u.Length(), 2)));
    }

    /* return the magnitude */
    inline long double Length()
    {
        return sqrt( (x * x) + (y * y) + (z * z));
    }

    Vec3x GetMix(const Vec3x& vec)
    {
        return Vec3x((x + vec.x) / 2, (y + vec.y) / 2,  (z + vec.z) / 2);
    } 

    long double z;
};
};