#include <stdio.h>
#include "SphereBody.hpp"

int main(void)
{
    jpk::vec3f pos(0.0f, 0.0f, 0.0f);
    jpk::SphereBody sp(pos, 1.0f, 0.3f);
    
    jpk::vec3f force1(0.0f, 0.00f, 0.01f);
    sp.apply_force(force1, 0.3f, 2);

    
    
    
    while(1)
    {
        sp.update(0.01f);
        sp.print();
        printf("F\n");
    }
    
    return 0;
}