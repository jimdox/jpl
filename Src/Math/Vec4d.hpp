#pragma once
#include "Vec3d.hpp"

/* @author: James Doxtader
            github.com/jimdox/RocketMath

    Vec4d: double precision 4D vector
*/

namespace Eros 
{
class Vec4d : public Vec3d
{
public:
    Vec4d() : Vec3d() {}

    Vec4d(long double x, long double y, long double z, long double w) : Vec3d(x, y, z), w(w) {}

    Vec4d(const Vec4d& vec)
    {
        x = vec.x;
        y = vec.y;
        z = vec.z;
        w = vec.w;
    }

    Vec4d(const Vec3d& vec, long double w)
    {
        x = vec.x;
        y = vec.y;
        z = vec.z;
        this->w = w;
    }   
    
    ~Vec4d() {}

    inline long double getW()const { return w; }

    Vec4d operator+(Vec4d& vec)
    { 
        long double i = x + vec.x; 
        long double j = y + vec.y;
        long double k = z + vec.z;
        long double m = w + vec.w;
        return Vec4d(i, j, k, m);
    }

    Vec4d operator-(Vec4d& vec)
    {
        long double i = x - vec.x;
        long double j = y - vec.y;
        long double k = z - vec.z;
        long double m = w - vec.w;
        return Vec4d(i, j, k, m);
    }

    Vec4d operator*(long double scalar){ return Vec4d(scalar * x, scalar * y, scalar * z, scalar * w); }
   	
    /* Scalar Product */
    long double Dot(Vec4d& vec)
    {
        return x * vec.x + y * vec.y + z * vec.z + w * vec.w;
    }

    /* magnitude of vector */
    inline long double Length()
    {
        return sqrt( (x*x) + (y*y) + (z*z) + (w*w));
    }

    void Mix(Vec4d& vec)
    {
        x = (x + vec.x) / 2.0L;
        y = (y + vec.y) / 2.0L;
        z = (z + vec.z) / 2.0L;
        w = (w + vec.w) / 2.0L;
    } 

    double w;
};
};
