#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <iomanip>
#include "Ref_3_planets.h"
#include "BaseClass.h"
#include <utility>

using namespace std;

 Ref_3_planets::Ref_3_planets()
                 :Na(6.02214076e23),R(8.314462618), index_eye(0), index_atmo(0),P(101325), na(1),nb(0), permitivity(8.85418782e-12),angleapprox(0){
 distances.push_back(91691000);
 distances.push_back(41400000);
 distances.push_back(78340000);
 distances.push_back(628730000);
 distances.push_back(1275000000);
 distances.push_back(2723950000);
 distances.push_back(4351400000) ;
 
                 }
//gastondale Formula for index of refraction
void Ref_3_planets:: setindex_atmo(double& alpha, double& T)
{

cout<< "Choose your polarizability volume and Temperature to " << endl
    << "find index of refraction of gaseous atmosphere" << endl
    << "Enter alpha : ";
cin >> alpha;
cout << "Enter Temperature: ";
cin >> T;

alpha*=1e-30; 
 index_atmo = 
    ((Na*alpha*P) /(2*R*T)) + 1; }

    //get index of refraction
 double Ref_3_planets::getindex_atmo() const{
    double nb = index_atmo;
    return nb;
 }

 //global theta variables

 //SNELLS LAW for theta values!
 void Ref_3_planets::snellslaw(double& tha, double& thb){
    double t_b;
    double d;
    double nb = getindex_atmo();
    double result;
    
    cout<<"----------Press 1  for THETA_A----------"<< endl
        <<"----------Press 2  for THETA_B----------"<< endl
        <<"------------Press 3 to exit-------------"<<endl;
    
    cout <<"---We will find theta_b for you----"<<endl
         << "Enter Angle for theta a: "<<endl;
    cin >> d;
    tha = degtorad(d);
    t_b = asin(na*sin(tha)/nb);
    thb = t_b;
    cout << "nb value: " << nb << endl
         <<"theta a in rads is: " << tha << endl
        << "theta b in rads is: " << thb << endl
         << "na vales is: "<< na << endl;
        cout<<"theta_b is: "<<radtodeg(t_b)<<endl;
        result = tha - thb;
        angleapprox = result;
          
     }


void Ref_3_planets::changeindistance(){

cout << "The change in angle in radians is: " <<endl;
cout << fixed << setprecision(15) <<angleapprox << endl;
int choice;
cout<< "Choose 1. for Mercury distance" << endl
    << "Choose 2. for Venus distance" << endl
    << "Choose 3. for Mars distance" << endl
    << "Choose 4. for Jupiter distance" << endl
    << "Choose 5. for Saturn distance" << endl
    << "Choose 6. for Uranus distance" << endl
    << "Choose 7. for Neptune distance" << endl;
    cin >> choice;
    int d = distances[choice - 1];
cout << endl;
double newdistance = tan(angleapprox)*d;

  cout <<"Your current planet appears to be " <<  newdistance << " km" << endl 
       << " of its current position."<<endl;
}


void Ref_3_planets::lightitems(){
double pol = 0.0;
double t =0.0;    
double ta=0;
double tb=0;

//Ref_3_planets n_b;
Ref_3_planets planetillusion;
planetillusion.setindex_atmo(pol,t);
cout << "Your index of refraction is: " << endl
     << "Your value for polarizability volume is: " << pol << " and"<< endl
     <<"your value for Temperature is: " << t << endl
     << "your index of refration is "<< fixed <<setprecision(8)<<planetillusion.getindex_atmo()<< endl;
planetillusion.snellslaw(ta,tb);
planetillusion.changeindistance();
}

//copy formulas to compare Different elements: As proof, He has almost same index of refraction 1.025 index of refraction do to the loss of kinetic energy do to cold temps(more than water).
//poriovng grandstoles Dale formula T is inversly proportional to the index of reftaction and directly proprtional to polarizaston volume and I would argue, Pressure is more omportant
//than polarization volume.Perhaps the strength of electric field it doesnt impact as much as the nuclear forces. 
