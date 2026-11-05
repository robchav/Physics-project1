#ifndef REF_3_PLANETS_H
#define REF_3_PLANETS_H
#include <string>
#include <iostream>
#include <vector>
#include "BaseClass.h"

using namespace std;
class Ref_3_planets: public BaseClass{
    private:
    vector<string> planets;         //vector of planets that weill throw an int value and return a distance int
    vector<string> fic_planet;      //vecotr of false planets at 1 AU from sun (same as Earths). Might add more. 
    double index_atmo;
    double index_eye;
    
    int theta_diff;
    const double Na;
    const double R;
    double P;
    double na;
    double nb;
    //double temp;

    public:
    
    Ref_3_planets(); //constructor for index of refraction 
    void setindex_atmo(double& alpha, double& T); //GanstonDale index formula setter
    void setindex_eye(double);                            //snells law with nb as eye and na as atmos.
    void setindex_total(double);
    double snellslaw(double& th_a,double& th_b) const; //snells law 
   
    double getindex_atmo() const;
    double getindex_eye() const;
    double getindex_tot() const;
    void lightitems() override;

};
#endif