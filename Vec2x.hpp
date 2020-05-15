#pragma once
#include "Math.hpp"
/* @author: James Doxtader
            github.com/jimdox/RocketMath
    
    Vec2x: 10 byte f.p. extended precision 2D vector
*/

namespace Rkt
{
class Vec2x
{
public:
    Vec2x()
    {
        x, y = 0.0L; 
    }
    
    Vec2x(long double x, long double y) : x(x), y(y) {}

    Vec2x(const Vec2x& v)
    {
        this->x = v.x;
        this->y = v.y;
    }

    ~Vec2x() {}

    inline long double GetX() const { return x; }
    inline long double GetY() const { return y; }

    Vec2x operator+(const Vec2x& v)
    { 
        return Vec2x(x + v.x, y + v.y);
    }
    void operator+=(const Vec2x& v)
    {
        x += v.x;
        y += v.x;
    }

    Vec2x operator-(const Vec2x& v)
    {

        return Vec2x(x + v.x, y + v.y);
    }

    Vec2x operator-()
    {
        return Vec2x(-x, -y);
    }

    void operator-=(const Vec2x& vec)
    {
        x -= vec.x;
        y -= vec.y;
    }

    Vec2x operator*(long double scale){ return Vec2x(scale * x, scale * y); }

    void operator*=(long double scale){ x * scale; y * scale; }
    
    Vec2x operator*(Vec2x& v){ return Vec2x( x * v.x, y * v.y); }
    
    long double Dot(const Vec2x& v)
    {
        return  x * v.x + y * v.y;
    }

    Vec2x GetNormalized()
    {
        Vec2x vec(x, y);
        return vec * (1 / vec.Length());
    }
    
    /* orthog. projection onto u vec. */
    Vec2x GetOrthoProjection(Vec2x& u)
    {
        return u * (Dot(u)/(u.Dot(u)));
    }

    Vec2x GetMix(Vec2x& vec)
    {
        return Vec2x((x + vec.x)/2, (y + vec.y)/2);
    }

    inline long double Dir()
    {
        return atan(y/x);
    }

    inline long double Length()
    {
        return sqrt( (x*x) + (y*y));
    }

    long double x, y;
};
};
