#include "jpkVector.h"


namespace jpk {
class Vec3f : public Vector
{
public:
Vec3f(float x, float y, float z){ this->x = x; this->y = y; this->z = z; }
~Vec3f(){ }

float getX(){ return this->x; }
float getY(){ return this->y; } 
float getZ(){ return this->z; }


inline void operator+(Vec3f* vector)
{ 
    this->x += vector->getX(); 
    this->y += vector->getY();
    this->z += vector->getZ();
}

inline void operator-(Vec3f* vector)
{
    this->x -= vector->getX();
    this->y -= vector->getY();
    this->z -= vector->getZ();
}

void dot(Vec3f* vector)
{
    x *= vector->getX();
    y *= vector->getY();
    z *= vector->getZ();
}
private:

float x;
float y;
float z;

};
};