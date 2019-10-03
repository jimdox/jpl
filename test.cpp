#include <math.h>
#include <stdio.h>
#include "SphereBody.hpp"

int main(void)
{
    float x,y,z = 0.0f;
    float c = 0.0f; 
    while(1)
    {
        x = cosf(c);
        z = sinf(c);
        c+= 0.02f;
        printf("ct3 %e %e %e 1\n", x,y,z);
        printf("F\n");
    }

    return 0;
}