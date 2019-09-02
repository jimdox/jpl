#include "jpk_vector.h"


namespace jpk {
class vec2f : public jpk_vector 
{

public:
vec2f(float x, float y){ this->x = x; this->y = y; }
~vec2f(){};

inline float getX() { return this->x; }
inline float getY() { return this->y; }

inline vec2f operator+(vec2f* vector){ x += vector->getX(); y += vector->getY(); return vec2f(x,y); }
inline vec2f operator-(vec2f* vector){ x -= vector->getX(); y -= vector->getY(); return vec2f(x,y); }



void dot(vec2f* vector)
{
    x *= vector->getX();
    y *= vector->getY();
}

void mix(vec2f* vector)
{
    x = (x + vector->getX())/2;
    y = (y + vector->getY())/2;
}

private: 

float x; 
float y;


};
};