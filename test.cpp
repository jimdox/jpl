#include <stdio.h>
#include "SphereBody.hpp"

/* @author: James Doxtader
            github.com/jimdox/jpk
*/

int main(void)
{
    jpk::vec3f pos(0.0f, 0.0f, 0.0f);
    //jpk::SphereBody sp(pos, 1.0f, 0.3f);
    
    jpk::vec3f force1(0.0f, 0.00f, 0.01f);
    //sp.apply_force(force1, 0.3f, 2);

    jpk::vec3f vecA(0.4f, 0.5f, 1.0f);
    jpk::vec3f vecB(2.0f, 4.2f, 0.2f);
    


    vecA = vecA + (vecB * 0.1f);

    
    printf("%e\n", vecA.dot(&vecB));
    printf("%e %e %e \n", vecA.get_x(), vecA.get_y(), vecA.get_z());
    /*
    while(1)
    {
        sp.update(0.01f);
        sp.print();
        printf("F\n");
    }
    */
    return 0;
}