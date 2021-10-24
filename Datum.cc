//Datum.cc

#include"Datum.h"
#include<iostream>
#include<cmath>

using std::cout;
using std::endl;
using std::ostream;

//Constructors
Datum::Datum(){
  value_=0.0;
  error_=0.0;
}

Datum::Datum(double x, double y){
  value_=x;
  error_=y;
}

Datum::Datum(const Datum& datum){
  value_=datum.value_;
  error_=datum.error_;
}

//Destructor
Datum::~Datum(){
using namespace std;
cout<<"~Datum called"<<endl;
}

//set tolerance
double Datum::tolerance_=1e-4;

//Getters
double Datum::significance() const{
return value_/error_;
}

//Print
void Datum::print(){
using namespace std;
cout<<value_<<" +/- "<<error_<<endl;
}

//Overloads
Datum Datum::operator+(const Datum& rhs) const{
double val=value_+rhs.value_;
double err=sqrt(error_*error_+rhs.error_*rhs.error_);
return Datum(val,err);
}

Datum Datum::operator-(const Datum& rhs) const{
double val= value_-rhs.value_;
double err= sqrt(error_*error_+rhs.error_*rhs.error_);
return Datum(val,err);
}

Datum Datum::operator*(const Datum& rhs) const{
double val=value_*rhs.value_;
double err=sqrt(rhs.value_*rhs.value_*error_*error_+value_*value_*rhs.error_*rhs.error_);
return
Datum(val,err);
}

Datum Datum::operator*(const double& rhs) const{
double val=value_*rhs;
return Datum(val,rhs*error_);
}

Datum Datum::operator/(const Datum& rhs) const{
double val= value_/rhs.value_;
double err=sqrt(error_*error_/(rhs.value_*rhs.value_)+value_*value_/(rhs.value_*rhs.value_*rhs.value_*rhs.value_)*rhs.error_*rhs.error_);
return Datum(val,err);
}

const Datum& Datum::operator=(const Datum& rhs){
  value_=rhs.value_;
  error_=rhs.error_;
  return *this;
}

const Datum& Datum::operator+=(const Datum& rhs){
  value_+=rhs.value_;
  error_=sqrt(rhs.error_*rhs.error_+error_*error_);
  return *this;
}
bool Datum::operator==(const Datum& rhs) const{
return(fabs(value_-rhs.value_)<tolerance_ && fabs(error_-rhs.error_)<tolerance_);
}

bool Datum::operator<(const Datum& rhs) const{
return value_<rhs.value_;
}

bool Datum::operator>(const Datum& rhs) const{
return value_>rhs.value_;
}

Datum operator*(const double& lhs, const Datum& rhs){
  double val= lhs*rhs.value_;
  double err= lhs*rhs.error_;
  return Datum(val,err);
}

ostream& operator<<(ostream& os, const Datum& rhs){
  os<<rhs.value_<<" +/- "<<rhs.error_;
  return os;
}
