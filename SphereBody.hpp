#pragma once
#include "vec3f.h"
#include <stdio.h>
namespace jpk {
class SphereBody 
{
public:
    SphereBody(vec3f& pos, float rad) : position(pos)
    {
        radius = rad;
    };
    SphereBody(vec3f& pos, vec3f& vel, float rad) : position(pos), velocity(vel)
    {
        radius = rad;
    }

    ~SphereBody(){ };

    float get_radius()
    {
        return radius;
    }

    vec3f& get_position()
    {
        return position;
    }
    vec3f& get_velocity()
    {
        return velocity;
    }
    
    void set_position(vec3f& pos)
    {
        position = pos;
    }

    void set_velocity(vec3f& vel)
    {
        velocity = vel;
    }


    
private:
    vec3f position;
    vec3f velocity;
    float radius;
    bool isCollisionBody = false;
    
    
};

};