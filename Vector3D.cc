//Vector3D.cc

#include"Vector3D.h"
#include<iostream>
#include<cmath>
using namespace std;

Vector3D Vector3D::operator+(const Vector3D& rhs) const{
  return Vector3D(x_[0]+rhs.x_[0],x_[1]+rhs.x_[1],x_[2]+rhs.x_[2]);
}

Vector3D Vector3D::operator-(const Vector3D& rhs) const{
  return Vector3D(x_[0]-rhs.x_[0],x_[1]-rhs.x_[1],x_[2]-rhs.x_[2]);
}

const Vector3D& Vector3D::operator=(const Vector3D& rhs){
  x_[0]=rhs.x_[0];
  x_[1]=rhs.x_[1];
  x_[2]=rhs.x_[2];
  return *this;
}

Vector3D Vector3D::operator*(const double& rhs) const{
  return Vector3D(x_[0]*rhs,x_[1]*rhs,x_[2]*rhs);
}

Vector3D Vector3D::operator/(const double& rhs) const{
  return Vector3D(x_[0]/rhs,x_[1]/rhs,x_[2]/rhs);
}

double Vector3D::magnitude() const{
  return sqrt(x_[0]*x_[0]+x_[1]*x_[1]+x_[2]*x_[2]);
}

double Vector3D::theta() const{
  return atan(x_[1]/x_[0]);
}

double Vector3D::phi() const{
  double r=this->magnitude();
  return acos(x_[2]/r);
}

double Vector3D::angle(const Vector3D& rhs) const{
  double sp=sqrt(x_[0]*rhs.x_[0]+x_[1]*rhs.x_[1]+x_[2]*rhs.x_[2]);
  double v1=this->magnitude();
  double v2=rhs.magnitude();
  return acos(sp/(v1*v2));
}

double Vector3D::scalarProduct(const Vector3D& rhs) const{
  return sqrt(x_[0]*rhs.x_[0]+x_[1]*rhs.x_[1]+x_[2]*rhs.x_[2]);
}

Vector3D Vector3D::vectorProduct(const Vector3D& rhs) const{
  double x=x_[1]*rhs.x_[2]-x_[2]*rhs.x_[1];
  double y=-x_[0]*rhs.x_[2]+x_[2]*rhs.x_[0];
  double z=x_[0]*rhs.x_[1]-x_[1]*rhs.x_[0];
  return Vector3D(x,y,z);
}

Vector3D operator*(const double& lhs, const Vector3D& rhs){
  return Vector3D(lhs*rhs.x_[0],lhs*rhs.x_[1],lhs*rhs.x_[2]);
}

ostream& operator<<(ostream& os, const Vector3D& rhs){
  return os<<"Cartesian( "<<rhs.x_[0]<<" , "<<rhs.x_[1]<<" , "<<rhs.x_[2]<<" )\tPolar("<<rhs.magnitude()<<" , "<<rhs.theta()<<" , "<<rhs.phi()<<" )";
}

