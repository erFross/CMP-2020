//Vector3D.cpp

#include"Vector3D.h"
#include<iostream>
#include<cmath>

using namespace std;
 
int main(){
  Vector3D e1 = Vector3D :: Cartesian(1,0,0);
  Vector3D e2=Vector3D::Cartesian(0,1,0);
  Vector3D e3=Vector3D::Cartesian(0,0,1);
  cout<<"theta_e1: "<<e1.theta()<<endl;
  cout<<"theta_e2: "<<e2.theta()<<endl;
  cout<<"theta_e3: "<<e3.theta()<<endl;
  cout<<"angle_e1_e2: "<<e1.angle(e2)<<endl;
  cout<<"phi_e1: "<<e1.phi()<<endl;
  cout<<"phi_e2: "<<e2.phi()<<endl;
  cout<<"phi_e3: "<<e3.phi()<<endl;
  cout<<"e1 x e2: "<<e1.vectorProduct(e2)<<endl;
  cout<<"e1 . e2: "<<e1.scalarProduct(e2)<<endl;
  cout<<"e1 . e1: "<<e1.scalarProduct(e1)<<endl;
  Vector3D cube=Vector3D::Cartesian(1,1,1);
  cout<<"|cube|: "<<cube.magnitude()<<endl;
  Vector3D sum=e1+e2;
  cout<<"sum: "<<sum.magnitude()<<endl;
  Vector3D prod=e1*3;
  cout<<"prod: "<<prod.magnitude()<<endl;
  cout<<"prod: "<<prod<<endl;
  Vector3D prodGlob=3*e2;
  cout<<"prodGlob: "<<prodGlob<<endl;
  
  //copia
  Vector3D copia(e1);
  cout<<"e1: "<<e1<<", copia: "<<copia<<endl; 
  Vector3D f1=Vector3D::Polar(1,0,0); //ha raggio 1 e angoli a 0, è e3
  cout<<"f1: "<<f1<<endl;
  Vector3D f2=Vector3D::Polar(1,M_PI/2,M_PI/2);
  cout<<"f2: "<<f2<<endl;
  Vector3D g1=Vector3D::Cylindrical(1,M_PI/2,0);
  cout<<"g1: "<<g1<<endl;
  cout<<"sin(M_PI/2): "<<fixed<<sin(M_PI/2)<<", cos(M_PI/2): "<<cos(M_PI/2)<<endl;

  //PURTROPPO cos(M_PI/2)=6.12323e-17  e non 0 ecco perchè stampa spesso quel numero, questo penso sia dovuto al fatto che M_PI è definito con poche cifre significative, grande mancanza di rispetto a mio avviso.
  return 0;
}
