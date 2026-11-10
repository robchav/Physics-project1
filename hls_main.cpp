#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <iomanip>
#include "Ref_3_planets.h"
#include "BaseClass.h"

int main()
{ 


Ref_3_planets p1; //object of sublcalss created

p1.registernewplanet(&p1);     //object calling of new planet from base class vector
p1.runAllCalculations();       //object p1 calling for loop



    return 0;}