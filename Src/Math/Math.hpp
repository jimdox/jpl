#pragma once
#include <cmath>

namespace Eros
{
/* polynomial rolling hash func. 
    https://cp-algorithms.com/string/string-hashing.html
*/
// inline uint32_t hash_filepath(const std::string& fp)
// {
//     const uint32_t poly = 53;               /* optimal for upper and lowercase strings, which has to be supported. */
//     const uint32_t m = 1e9 + 9;
//     uint32_t hash_val;

inline float Max(float a, float b)
{
    if(a > b)
        return a;
    return b;
}

inline float Min(float a, float b)
{
    if(a < b)
        return a;
    return b;
}

inline float ToRadians(float degrees)
{
    return degrees * (M_PI/180.0f);
}

inline float BaryCentricInterpolation(const Vec3d& p1, const Vec3d& p2, const Vec3d& p3, const Vec3d& pos)
{
    float det = (p2.z - p3.z) * (p1.x - p3.x) + (p3.x - p2.x) * (p1.z - p3.z);
    float L_1 = ((p2.z-p3.z) * (pos.x - p3.x) + (p3.x - p2.x) * (pos.y - p3.z)) / det;
    float L_2 = ((p3.z - p1.z) * (pos.x - p3.x) + (p1.x - p3.x) * (pos.y - p3.z)) / det;
    float L_3 = 1.0f - L_1 - L_2;
    return (L_1 * p1.y) + (L_2 * p2.y) + (L_3 * p3.y);
}

}