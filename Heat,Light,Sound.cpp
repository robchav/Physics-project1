#include <vector>
#include "Ref_3_planets.h"
#include "BaseClass.h"

BaseClass::BaseClass():Pi(3.14159265358979323846) {}

double BaseClass::radtodeg(double& radiants) const{
 double deg = radiants*(180/Pi);
 return deg;
}
double BaseClass:: degtorad(double& degrees) const{
double rad = degrees*(Pi/180);
return rad;
}

void BaseClass::registernewplanet(BaseClass* p) {
    light.push_back(p); //create slot in light vector for pointer p
    }
    
void BaseClass::runAllCalculations() { //memeber function runs for loop from ptr of parent class to vector light
        for (BaseClass* ptr : light) {  //ptr to light vector
            ptr->lightitems(); //ptr points to function in child class with virtual
        }
    }

   