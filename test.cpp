#include <stdio.h>
#include "SphereBody.hpp"

int main(void)
{
    jpk::vec3f pos(0.0f, 0.0f, 0.0f);
    jpk::SphereBody sp(pos, 1.0f, 0.3f);
    
    jpk::vec3f force1(1.0f, 0.0f, 0.0f);
    sp.print();
    sp.apply_force(force1, 0.1f);
    sp.print();
    
    
    
    /*while(1)
    {
        x = cosf(c);
        z = sinf(c);
        c+= 0.02f;
        printf("ct3 %e %e %e 1\n", x,y,z);
        printf("F\n");
    }
    */
    return 0;
}