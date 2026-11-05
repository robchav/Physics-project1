#include <vector>
#include "Ref_3_planets.h"
#include "Baseclass.h"

BaseClass::BaseClass():Pi(3.14159265358979323846) {}

double BaseClass::radtodeg(double& radiants) const{
 double deg = radiants*(180/Pi);
 return deg;
}
double BaseClass:: degtorad(double& degrees) const{
double rad = degrees*(Pi/180);
return rad;
}

void BaseClass::processlight(vector<BaseClass*>& L) {
    string planet;
    light.push_back(planet); // only works if 'light' is a vector<string>

    for (BaseClass* ptr : L) {
        ptr->lightitems(); // use -> because ptr is a pointer
    }
}

    