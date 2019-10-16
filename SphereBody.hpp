#pragma once
#include "vec3f.hpp"
#include <math.h>
#include <stdio.h>

/* @author: James Doxtader
            github.com/jimdox/jpl
*/

namespace jpl {
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

    ~SphereBody()
    {
        /* explicitly call destructors */
        position.~vec3f();
        velocity.~vec3f();
        accleration.~vec3f();
    }

    float get_radius()
    {
        return radius;
    }

    void set_radius(float r)
    {
        radius = r;
    }

    float get_mass()
    {
        return mass;
    }

    void set_mass(float m)
    {
        mass = m;
    }

    vec3f& get_position()
    {
        return position;
    }

    void set_position(vec3f& pos)
    {
        position = pos;
    }

    vec3f& get_velocity()
    {
        return velocity;
    }
    

    void set_velocity(vec3f& vel)
    {
        velocity = vel;
    }

    void offset_pos(vec3f d_pos)
    {
        position += d_pos;
    }


    void apply_force(vec3f& force, float duration, unsigned int num_steps)
    {
        vec3f d_a = force * (1.0f/mass);
        float dt = duration/num_steps;                          /* interval to update object */

        for(int i = 0; i < num_steps; i++)
        {
        accleration += d_a;
        update(dt);
        }

        accleration += (d_a*(-1));                             /* setting it to 0 would cancel net force */
    }

    void update(float dt)
    {
        velocity += (accleration * dt);
        position += (velocity*dt);

        if(isCollisionBody)
        {

        }
    }
    
    void print()
    {
        printf("c3 %e %e %e %e\n", position.get_x(), position.get_y(), position.get_z(), radius);
    }
    /* bounding sphere collision detection */
    bool check_collision(SphereBody* sphere_b)
    {
        float total_radius = this->radius + sphere_b->get_radius();

        /* components of relative distance */
        float d_x = sphere_b->get_position().get_x() - position.get_x();
        float d_y = sphere_b->get_position().get_y() - position.get_y();
        float d_z = sphere_b->get_position().get_z() - position.get_z();

        float com_distance = (float)sqrt((d_x*d_x) + (d_y*d_y) + (d_z*d_z));

        if(com_distance < total_radius)
        {
            return true;
        }
        return false;
    }

    static void collision_handler(SphereBody* a, SphereBody* b)
    {
        if(a->check_collision(b))
        {
            float d_momentum = a->get_position().get_x();
        }
    }


private:
    vec3f position;
    vec3f velocity;
    vec3f accleration;

    float radius;
    float mass;
    bool isCollisionBody = false;
    
    
};

};