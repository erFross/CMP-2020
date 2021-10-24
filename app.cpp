//app.cpp

#include"Datum.h"
#include<iostream>
#include<cmath>

using namespace std;

int main(){
  Datum d1(-1.1,0.1);
  Datum d2(-1.0,0.2);
  Datum d3(-1.11,0.099);  
  Datum d4(-1.10001,0.09999999);
  cout<<"d1"<<endl;
  d1.print();
  cout<<"d2"<<endl;
  d2.print();
  cout<<"d3"<<endl;
  d3.print();
  cout<<"d4"<<endl;
  d4.print();
  for(double eps=0.1;eps>1e-8;eps/=10){
    Datum::setTolerance(eps);
    cout<<"Datum tolerance= "<<eps<<endl;
    if(d1==d2) cout<<"\t d1 same as d2"<<endl;
    if(d1==d3) cout<<"\t d1 same as d3"<<endl;
    if(d1==d4) cout<<"\t d1 same as d4"<<endl;
  }
  return 0;
}
