/******************************************
Fraction.h
Base class managing fractional mathematics operations
Each instance is a fraction object capable of results output
Instances can be created using zero, one or two parameters
Zero parameters will create zero, one parameter is string, two are ints
Author: Alex Sukharevsky
********************************************/
#include <string>
using namespace std;
#ifndef FRACTION_H
#define FRACTION_H

namespace Fraction_al {
  class Fraction {

	  int numerator;
	  int denominator;

    public:
	  Fraction();
	  Fraction(const string&);
	  Fraction(int, int);
	  virtual ~Fraction(){}
	  Fraction Add(const Fraction&) const;
	  Fraction Subtract(const Fraction&) const;
	  Fraction Multiply(const Fraction&) const;
	  Fraction Divide(const Fraction&) const;
	  bool IsEqual(const Fraction&) const;
	  bool IsNotEqual(const Fraction&) const;
	  bool GreaterThan(const Fraction&) const;
	  bool LessThan(const Fraction&) const;
	  void Display() const;
	  void init_fraction(int, int);
	  void parse(const string&);
	  void reduce();
  };
  //other functions declarations
  constexpr int myhash(const string&);
  // arguments: input1, input2, output
  void SafeAddition(int, int, int&);
  // arguments: input1, input2, output
  void SafeMultiplication(int, int, int&);
  int Gcd(int , int);
  int Lcm(int, int);
}
#endif
