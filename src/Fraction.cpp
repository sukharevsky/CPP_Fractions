/***********************************************************
Fraction.cpp base class managing fractional mathematics operations
Each instance is a fraction object capable of results output, created using zero, one or two parameters
Zero parameters will create zero, one parameter is string, two are integers
Author: Alex Sukharevsky
************************************************************/
#include <stdio.h>
#include <climits>
#include <stdexcept>
#include <string>
#include <iostream>
#include "Fraction.h"

using namespace std;
namespace Fraction_al {
	Fraction::Fraction() {
		this->numerator = 0;
		this->denominator = 1;
	}

	Fraction::Fraction(const string &str_fraction) {
		this->numerator = 0;
		this->denominator = 1;
		this->parse(str_fraction);
	}

	Fraction::Fraction(int numerator, int denominator) {
		if (denominator == 0)
			throw std::overflow_error("Exception:Attempt to divide by zero");
		this->numerator = numerator;
		this->denominator = denominator;
		this->reduce();
	}

	void Fraction::init_fraction(int numerator, int denominator) {
		if (denominator == 0)
			throw std::overflow_error("Exception:Attempt to divide by zero");
		this->numerator = numerator;
		this->denominator = denominator;
		this->reduce();
	}

	void Fraction::parse(const string &str_fraction) {
		 int div_index = str_fraction.find('/');
		 int string_len = str_fraction.length();
		 if (div_index > 0 && string_len > div_index) {
			 try {
				 this->numerator = stoi(str_fraction.substr(0, div_index));
				 this->denominator = stoi(str_fraction.substr(div_index + 1, string_len - div_index));
			 }
			 catch (invalid_argument const &e)	{
			 	cout << "Bad input: invalid_argument thrown" << '\n';
			 }
			 catch (out_of_range const &e)	{
			 	cout << "Integer overflow: out_of_range thrown" << '\n';
			 }
		 } else {
			 throw overflow_error("Exception: no fraction specified. Please check input and use / ");
		 }
	}

	void Fraction::reduce() {
		int temp1;
		temp1 = this->numerator;
		this->numerator = this->numerator/Gcd(temp1, this->denominator);
		this->denominator = this->denominator/Gcd(temp1, this->denominator);
		if ((this->denominator) < 0) {
			this->numerator = this->numerator*(-1);
			this->denominator = this->denominator*(-1);
		}
		return;
	}
/*// Alternative operator overload prototype
	Fraction& operator+=(const Fraction &f)
	{
		numerator += f.numerator * denominator;
		denominator += f.denominator * nominator;
		reduce();
	    return *this;
	}

	Fraction operator+(Fraction l, const Fraction &r)
	{
	    l += r;
	    return l;
	}
*/
	Fraction Fraction::Add(const Fraction &b) const {
		int tmp1, tmp2, new_numerator, new_denominator;
		new_denominator = Lcm(this->denominator, b.denominator);
		SafeMultiplication((this->numerator), (new_denominator/(this->denominator)), tmp1);
		SafeMultiplication((b.numerator), (new_denominator/(b.denominator)), tmp2);
		SafeAddition(tmp1, tmp2, new_numerator);
		Fraction result(new_numerator, new_denominator);
		return result;
	}

	Fraction Fraction::Subtract(const Fraction &b) const {
		int tmp1, tmp2, new_numerator, new_denominator;
		new_denominator = Lcm(this->denominator, b.denominator);
		SafeMultiplication((this->numerator), (new_denominator/(this->denominator)), tmp1);
		SafeMultiplication((b.numerator), (new_denominator/(b.denominator)), tmp2);
		SafeAddition(tmp1, (-1)*tmp2, new_numerator);
		Fraction result(new_numerator, new_denominator);
		return result;
	}

	Fraction Fraction::Multiply(const Fraction &b) const {
		int new_numerator, new_denominator;
		SafeMultiplication((this->numerator), (b.numerator), new_numerator);
		SafeMultiplication((this->denominator), (b.denominator), new_denominator);
		Fraction result(new_numerator, new_denominator);
		return result;
	}

	Fraction Fraction::Divide(const Fraction &b) const {
		int new_numerator, new_denominator;
		SafeMultiplication((this->numerator), (b.denominator), new_numerator);
		SafeMultiplication((this->denominator), (b.numerator), new_denominator);
		Fraction result(new_numerator, new_denominator);
		return result;
	}

	bool Fraction::IsEqual(const Fraction &b) const {
	  return (((this->numerator) == (b.numerator)) && ((this->denominator) == (b.denominator))?1:0);
	}

	bool Fraction::IsNotEqual(const Fraction &b) const {
		return (!(*this).IsEqual(b));
	}

	bool Fraction::GreaterThan(const Fraction &b) const {
		int num1, num2;
		SafeMultiplication((this->numerator), (b.denominator), num1);
		SafeMultiplication((this->denominator), (b.numerator), num2);
		return ((num1 > num2)?1:0);
	}

	bool Fraction::LessThan(const Fraction &b) const {
		return (b.GreaterThan(*this));
	}

	void Fraction::Display() const {
		printf("%d/%d", this->numerator, this->denominator);
	}


	// arguments: input1, input2, output.
	void SafeAddition(int a, int b, int &answer) {
		long long result;
		result = static_cast<long long>(a) + static_cast<long long>(b);
		if((result > INT_MAX) || (result < INT_MIN))
			throw std::overflow_error("Exception:Integer overflow");
		else {
			answer = static_cast<int>(result);
			return;
		}
	}

	// arguments: input1, input2, output
	void SafeMultiplication(int a, int b, int &answer) {
		long long result;
		result = static_cast<long long>(a) * \
				static_cast<long long>(b);
		if((result > INT_MAX) || (result < INT_MIN))
			throw std::overflow_error("Exception:Integer overflow");
		else {
			answer = static_cast<int>(result);
			return;
		}
	}

	int Gcd(int a, int b) {
		int temp;
		while(b != 0) {
			temp = b;
			b = a%b;
			a = temp;
		}
		return a;
	}

	int Lcm(int a, int b) {
		int result;
		SafeMultiplication(a, (b/Gcd(a, b)), result);
		return result;
	}
}
