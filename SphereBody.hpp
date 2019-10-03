#pragma once
#include "vec3f.hpp"
#include <stdio.h>
namespace jpk {
class SphereBody 
{
public:
    SphereBody(vec3f& pos, float rad, float m) : position(pos)
    {
        radius = rad;
        mass = m;
    }
    SphereBody(vec3f& pos, vec3f& vel, float rad) : position(pos), velocity(vel)
    {
        radius = rad;
        mass = 0.0f;
    }               

    SphereBody(vec3f& pos, vec3f& vel, float r, float m) : position(pos), velocity(vel)
    {
        radius = r;
        mass = m;

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

    void offset_pos(vec3f d_pos)
    {
        position += d_pos;
    }


    void apply_force(vec3f& force, float dt)
    {
        vec3f d_a = force * (1.0f/mass);
        accleration += d_a;
        update(dt);
    }

    void update(float dt)
    {
        velocity += (accleration * dt);
        position += (velocity*dt);

        if(isCollisionBody)
        {
            check_bounds();
        }
    }
    
    void print()
    {
        printf("c3 %e %e %e %e\n", position.get_x(), position.get_y(), position.get_z(), radius);
    }

    void check_bounds() { }
private:
    vec3f position;
    vec3f velocity;
    vec3f accleration;

    float radius;
    float mass;
    bool isCollisionBody = false;
    
    
};

};