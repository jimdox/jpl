#pragma once
#include "Vec2d.hpp"

/* @author: James Doxtader
            github.com/jimdox/RocketMath

    Vec3d: double precision 3D vector
*/

namespace Rkt 
{
class Vec3d : public Vec2d
{
public:
    Vec3d() : Vec2d() {}    

    Vec3d(double x, double y, double z) : Vec2d(x, y), z(z) {}

    Vec3d(const Vec3d& v)
    {
        this->x = v.x;
        this->y = v.y; 
        this->z = v.z;
    }

    Vec3d(Vec2d& v, double z)
    {
        x = v.x;
        y = v.y;
        this->z = z;
    }

    ~Vec3d() {}

    inline double GetZ() const { return z; }

    Vec3d operator+(const Vec3d &v)
    {
        return Vec3d(x + v.x, y + v.y, z + v.z);
    }

    void operator+=(const Vec3d& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
    }

    Vec3d operator-(const Vec3d& v)
    {
        return Vec3d(x - v.x, y - v.y, z - v.z);
    }

    void operator-=(const Vec3d& vec)
    {
        x -= vec.x;
        y -= vec.y;
        z -= vec.z;
    }

    Vec3d operator*(double scale) const 
    { 
        return Vec3d(scale * x, scale * y, scale * z);
    }

    void operator*=(double scale)
    {
        x * scale;
        y * scale;
        z * scale;
    }
    
    /* Scalar Product */
    inline long double Dot(const Vec3d& vector)
    {
        return x * vector.x + y * vector.y + z * vector.z;
    }

    void Cross(Vec3d& vector)
    {
        long double i,j,k;    // components of resulting vector
        i = (y * vector.z) - (z * vector.y);
        j = (z * vector.x) - (x * vector.z);
        k = (x * vector.y) - (y * vector.x);

        x = i;
        y = j;
        z = k;
    }

    Vec3d GetNormalized()
    {
        Vec3d vec(x,y,z);
        return vec * (1/vec.Length());
    }

    /* orthog. projection onto u vec. */
    Vec3d GetOrthoProjection(Vec3d& u)
    {
        return u * (Dot(u)/(pow(u.Length(), 2)));
    }

    /* magnitude of vector */
    inline double Length()
    {
        return sqrt( (x * x) + (y * y) + (z * z));
    }

    Vec3d GetMix(const Vec3d& vec)
    {
        return Vec3d((x + vec.x) / 2, (y + vec.y) / 2,  (z + vec.z) / 2);
    } 

    double z;
};
};