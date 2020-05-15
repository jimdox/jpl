#pragma once
#include "Vec3x.hpp"

/* @author: James Doxtader
            github.com/jimdox/jpl

    Vec4x: 10 byte f.p. extended precision 4D vector
*/

namespace Rkt 
{
class Vec4x : public Vec3x
{
public:
    Vec4x() : Vec3x()
    {
        w = 0.0L;
    }

    Vec4x(long double x, long double y, long double z, long double w) : Vec3x(x, y, z), w(w) {}

    Vec4x(const Vec4x& vec)
    {
        x = vec.x;
        y = vec.y;
        z = vec.z;
        w = vec.w;
    }

    Vec4x(const Vec3x& vec, long double w)
    {
        x = vec.x;
        y = vec.y;
        z = vec.z;
        this->w = w;
    }   
    
    ~Vec4x() {}

    inline long double getW()const { return w; }

    Vec4x operator+(Vec4x& vec)
    { 
        long double i = x + vec.x; 
        long double j = y + vec.y;
        long double k = z + vec.z;
        long double m = w + vec.w;
        return Vec4x(i, j, k, m);
    }

    Vec4x operator-(Vec4x& vec)
    {
        long double i = x - vec.x;
        long double j = y - vec.y;
        long double k = z - vec.z;
        long double m = w - vec.w;
        return Vec4x(i, j, k, m);
    }

    Vec4x operator*(long double scalar){ return Vec4x(scalar * x, scalar * y, scalar * z, scalar * w); }
   	
    long double Dot(Vec4x& vec)
    {
        return x * vec.x + y * vec.y + z * vec.z + w * vec.w;
    }

    inline long double Mag()
    {
        return sqrt( (x*x) + (y*y) + (z*z) + (w*w));
    }

    void Mix(Vec4x& vec)
    {
        x = (x + vec.x) / 2.0L;
        y = (y + vec.y) / 2.0L;
        z = (z + vec.z) / 2.0L;
        w = (w + vec.w) / 2.0L;
    } 

    long double w;
};
};
