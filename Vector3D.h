//Vector3D.h
#ifndef Vector3D_h
#define Vector3D_h

#include<iostream>
#include<cmath>

class Vector3D {
 public:
  //constructors cartesiani
  static Vector3D Cartesian(){
    return Vector3D();
  };
  static Vector3D Cartesian(double x, double y, double z){
    return Vector3D(x,y,z);
  };
  /* il copia non funziona mi da errore a tutto, da capire, al momento rimetto il constructor basico publico anche se andrebbe privato
   static Vector3D Cartesian(const Vector3D& copia){
    return Vector3D(copia);
    };
  */
  Vector3D(const Vector3D& vec){  //è il copia cartesiano non posso implementare il copia polare
    x_[0]=vec.x_[0];
    x_[1]=vec.x_[1];
    x_[2]=vec.x_[2];
  }
  
  //polar constructors, non creo quello di reset perchè non ha senso mettere angoli a 0
  static Vector3D Polar(double r, double theta, double phi){
    return Vector3D(r*sin(theta)*cos(phi),r*sin(theta)*sin(phi),r*cos(theta));
  }
  //cylindrical constructors
  static Vector3D Cylindrical(double r, double theta, double z){
    return Vector3D(r*cos(theta),r*sin(theta),z);
  }
  

  //destructors
  ~Vector3D(){};

  //setters
  void setX(double x){x_[0]=x;}
  void setY(double y){x_[1]=y;}
  void setZ(double z){x_[2]=z;}
  
  //getters
  double x() const {return x_[0];}
  double y() const {return x_[1];}
  double z() const {return x_[2];}

  //operators
  Vector3D operator+(const Vector3D& rhs) const;
  Vector3D operator-(const Vector3D& rhs) const;
  const Vector3D& operator=(const Vector3D& rhs);
  Vector3D operator*(const double& rhs) const;
  Vector3D operator/(const double& rhs) const;
  
  //functions
  double magnitude() const;
  double theta() const;
  double phi() const;
  double angle(const Vector3D& rhs) const;
  double scalarProduct(const Vector3D& rhs) const;
  Vector3D vectorProduct(const Vector3D& rhs) const;
  
  friend Vector3D operator*(const double& lhs, const Vector3D& rhs);
  friend std::ostream& operator<<(std::ostream& os, const Vector3D& rhs);
  
 private:
  double x_[3];
 
  Vector3D(){
    x_[0]=0.0;
    x_[1]=0.0;
    x_[2]=0.0;
  }
  Vector3D(double x, double y, double z){
    x_[0]=x;
    x_[1]=y;
    x_[2]=z;
  }
 
};
#endif
