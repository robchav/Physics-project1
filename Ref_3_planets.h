#ifndef REF_3_PLANETS_H
#define REF_3_PLANETS_H
#include <string>
#include <iostream>
#include <vector>
#include "BaseClass.h"

using namespace std;
class Ref_3_planets: public BaseClass{
    private:
    vector<long long int> distances;
    const double Na;
    const double R;
    double index_atmo;
    double index_eye;
    double P;
    double na;
    double nb;
    double angleapprox;
    int theta_diff;

    public:
    Ref_3_planets(); //constructor for index of refraction 
    void setindex_atmo(double& alpha, double& T); //GanstonDale index formula setter
    void setindex_eye(double);                            //snells law with nb as eye and na as atmos.
    void setindex_total(double);
    void snellslaw(double& tha, double& thb); //snells law 
    void changeindistance();
    double getindex_atmo() const;
    double getindex_eye() const;
    double getindex_tot() const;
    void lightitems() override;

};
#endif

/*https://wikis.mit.edu/confluence/display/RELATE/small+angle+approximation for small angle aprox(taylor series)
https://www.sciencedirect.com/science/article/abs/pii/S0010218019305759   for refractive index

*/