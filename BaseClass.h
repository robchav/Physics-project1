#ifndef BASECLASS_H
#define BASECLASS_H
#include <vector>
#include <string>
using namespace std;



class BaseClass{
private:
vector<string> light;
vector<string> sound;
vector<string> heat;
const double Pi;


public:
BaseClass();
void processlight(vector<BaseClass*>& L);
void processheat(vector<BaseClass>* H);
void processsound(vector<BaseClass>& S);
double radtodeg(double& rad) const;
double degtorad(double& deg) const;
// needed a little help with polymorphism
virtual ~BaseClass()= default;
virtual void lightitems() = 0;
};
#endif