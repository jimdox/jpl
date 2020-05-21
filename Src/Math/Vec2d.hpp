#pragma once
#include "Math.hpp"
/* @author: James Doxtader
            github.com/jimdox/RocketMath
    
    Vec2d: double precision 2D vector
*/

namespace Eros
{
class Vec2d
{
public:
    Vec2d() {}
    
    Vec2d(double x, double y) : x(x), y(y) {}

    Vec2d(const Vec2d& v)
    {
        this->x = v.x;
        this->y = v.y;
    }

    ~Vec2d() {}

    inline double GetX() const { return x; }
    inline double GetY() const { return y; }

    Vec2d operator+(const Vec2d& v)
    { 
        return Vec2d(x + v.x, y + v.y);
    }
    void operator+=(const Vec2d& v)
    {
        x += v.x;
        y += v.x;
    }

    Vec2d operator-(const Vec2d& v)
    {

        return Vec2d(x + v.x, y + v.y);
    }

    Vec2d operator-()
    {
        return Vec2d(-x, -y);
    }

    void operator-=(const Vec2d& vec)
    {
        x -= vec.x;
        y -= vec.y;
    }

    Vec2d operator*(double scale){ return Vec2d(scale * x, scale * y); }

    void operator*=(double scale){ x * scale; y * scale; }
    
    Vec2d operator*(Vec2d& v){ return Vec2d( x * v.x, y * v.y); }
    
    /* Scalar Product */
    long double Dot(const Vec2d& v)
    {
        return  x * v.x + y * v.y;
    }

    Vec2d GetNormalized()
    {
        Vec2d vec(x, y);
        return vec * (1 / vec.Length());
    }
    
    /* orthog. projection onto u vec. */
    Vec2d GetOrthoProjection(Vec2d& u)
    {
        return u * (Dot(u)/(u.Dot(u)));
    }

    Vec2d GetMix(Vec2d& vec)
    {
        return Vec2d((x + vec.x)/2, (y + vec.y)/2);
    }

    inline double Dir()
    {
        return atan(y/x);
    }

    /* magnitude of vector */
    inline double Length()
    {
        return sqrt( (x*x) + (y*y));
    }

    double x, y;
};
};
