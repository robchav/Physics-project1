#ifndef BASECLASS_H
#define BASECLASS_H
#include <vector>
#include <string>
using namespace std;

class BaseClass{
private:
vector<BaseClass*> light;
vector<string> sound;
vector<string> heat;
const double Pi;

public:
BaseClass();
void registernewplanet(BaseClass *light); //relationship of light vector.
void processheat(vector<BaseClass>* H);
void processsound(vector<BaseClass>& S);
double radtodeg(double& rad) const;
double degtorad(double& deg) const;
void runAllCalculations();
// needed a little help with polymorphism
virtual ~BaseClass()= default;
virtual void lightitems() = 0;
};
#endif