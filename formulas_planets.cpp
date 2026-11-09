#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <iomanip>
#include "Ref_3_planets.h"
#include "BaseClass.h"
using namespace std;

 Ref_3_planets::Ref_3_planets()
                 :R(8.314462618),Na(6.02214076e23), index_eye(0), index_atmo(0),P(101325), na(1),nb(0),fic_planet,per(8.85418782e-12){}
           
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
double* nbptr= nullptr;    
 index_atmo = 
    ((Na*alpha*P) /(2*per*R*T)) + 1; }
//get index of refraction
 double Ref_3_planets::getindex_atmo() const{
    double nb = index_atmo;
    return nb;
 }

 //SNELLS LAW for theta values!
 double Ref_3_planets::snellslaw(double& t_a, double& t_b) const{
    double r,d;
    double nb = getindex_atmo();
    double theta;
    double *tptr= &theta;
    
    cout<<"----------Press 1  for THETA_A----------"<< endl
        <<"----------Press 2  for THETA_B----------"<< endl
        <<"------------Press 3 to exit-------------"<<endl;
    int key;
    
    while (key!=3){
    
    cin >> key;
    //should be a way to make these formulas dynamic
    if (key==1){  
    cout <<"---We will find theta_a for you----"<<endl
         << "Enter Angle for theta b: " << endl;
    cin >> r;
     *tptr = degtorad(r);
     t_a = asin(nb * sin(*tptr) / na);

    cout << "nb value: " << nb <<endl
    << "theta in rads " << *tptr <<endl
    <<"Value for na " << na<< endl;
    cout << "theta_a is " << t_a<< endl;
    }  
    
    if(key==2){
    cout <<"---We will find theta_b for you----"<<endl
         << "Enter Angle for theta a: "<<endl;
    cin >> r;
    *tptr= degtorad(r);
    t_b = asin(na*sin(*tptr)/nb);
    cout << "nb value: " << nb
         << " pointer: " << *tptr 
         << " na vales is: "<< na << endl;
        cout<<"theta_b is: "<< t_b<<endl;
     
   }
   
   
}
 
cout<<endl;

    }

void Ref_3_planets::lightitems(){
double pol = 0.0;
double t =0.0;    
double ta=0;
double tb=0;

//Ref_3_planets n_b;
Ref_3_planets thval;



thval.setindex_atmo(pol,t);
cout << "Your index of refraction is: " << endl
     << "Your value for polarizability volume is: " << pol << " and"<< endl
     <<"your value for Temperature is: " << t << endl
     << "your index of refration is "<< fixed <<setprecision(8)<<thval.getindex_atmo()<< endl;
string str;
str= thval.snellslaw(ta,tb);
cout<< str;
}

//copy formulas to compare Different elements: As proof, He has almost same index of refraction 1.025 index of refraction do to the loss of kinetic energy do to cold temps(more than water).
//poriovng grandstoles Dale formula T is inversly proportional to the index of reftaction and directly proprtional to polarizaston volume and I would argue, Pressure is more omportant
//than polarization volume.Perhaps the strength of electric field it doesnt impact as much as the nuclear forces. 
