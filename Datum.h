//Datum.h

#ifndef Datum_h
#define Datum_h

#include<iostream>

class Datum{
 public:
  //Constructors
  Datum();
  Datum(double x, double y);
  Datum(const Datum& datum);

  //Destructor
  ~Datum();

  //Getters
  double value() const {return value_;}
  double error() const {return error_;}
  double significance() const;

  //Print
  void print();

  //Setters
  void setValue(double x){value_=x;}
  void setError(double x){error_=x;}
  static void setTolerance(double x){tolerance_=x;}

  //Overloads
  Datum operator+(const Datum& rhs) const;
  Datum operator-(const Datum& rhs) const;
  Datum operator*(const Datum& rhs) const;
  Datum operator*(const double& rhs) const;
  Datum operator/(const Datum& rhs) const;

  const Datum& operator=(const Datum& rhs);
  const Datum& operator+=(const Datum& rhs);
  bool operator==(const Datum& rhs) const;
  bool operator<(const Datum& rhs) const;
  bool operator>(const Datum& rhs) const;

  friend Datum operator*(const double& lhs, const Datum& rhs);
  friend std::ostream& operator<<(std::ostream& os, const Datum& rhs);
    
 private:
  double value_;
  double error_;
  static double tolerance_;
};

#endif
