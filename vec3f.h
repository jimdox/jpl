#include "jpk_vector.h"


namespace jpk {
class vec3f : public jpk_vector
{

public:
vec3f(float x, float y, float z){ this->x = x; this->y = y; this->z = z; }
~vec3f(){ }

float getX(){ return this->x; }
float getY(){ return this->y; } 
float getZ(){ return this->z; }

inline void operator+(vec3f* vector)
{ 
    this->x += vector->getX(); 
    this->y += vector->getY();
    this->z += vector->getZ();
}

inline void operator-(vec3f* vector)
{
    this->x -= vector->getX();
    this->y -= vector->getY();
    this->z -= vector->getZ();
}

void dot(vec3f* vector)
{
    x *= vector->getX();
    y *= vector->getY();
    z *= vector->getZ();
}

void cross(vec3f* vector)
{
    float i,j,k;    // components of resulting vector
    i = (y * vector->getZ()) - (z * vector->getY());
    j = (z * vector->getX()) - (x * vector->getZ());
    k = (x * vector->getY()) - (y * vector->getX());

    x = i;
    y = j;
    z = k;
}

void cross(vec2f* vector)
{
    vec3f vb(vector->getX(), vector->getY(), 0.0f);
    cross(&vb);

}


private:

float x;
float y;
float z;

};
};