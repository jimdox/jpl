#include "jpkVector.h"


namespace jpk {
class Vec2f : public Vector {

public:
Vec2f(float x, float y){ this->x = x; this->y = y; }
~Vec2f(){};

inline float getX() { return this->x; }
inline float getY() { return this->y; }

inline void operator+(Vec2f* vector){ x += vector->getX(); y += vector->getY(); }
inline void operator-(Vec2f* vector){ x -= vector->getX(); y -= vector->getY(); }



void dot(Vec2f* vector)
{
    x *= vector->getX();
    y *= vector->getY();
}

void mix(Vec2f* vector)
{
    x = (x + vector->getX())/2;
    y = (y + vector->getY())/2;
}

private: 

float x; 
float y;


};
};