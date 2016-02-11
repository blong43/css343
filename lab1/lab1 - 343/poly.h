//-----------------------------------------------------------------------------
// poly.h
// Poly class uses arrays to make polynomials
// Authors: Blong Thao
//-----------------------------------------------------------------------------
// Polynomials:   an expression of more than two algebraic terms, esp. the sum
//   of several terms that contain different powers of the same variable(s).
//   i.e +5x^10 -3x^9 +4x^7 ... 
// 
// Assumptions and Implementation
//   -- Polynomials are stored as integer coefficients and exponents
//   -- Should only use exponents that are non-negative
//   -- Exponents are the indexes in the array data structure
//   -- Coefficients are the values in the array data struture
//   -- The value zero in the array are markers that the polynomial
//      does not exist
//-----------------------------------------------------------------------------

#ifndef POLY_H
#define POLY_H

#include <iostream>
using namespace std;

class Poly {

	// overloaded <<: Does not print zeros unless the polyArray only contains
	//    zeros and accounts for if value is one or larger than one
	friend ostream& operator<<(ostream&, const Poly&);
	// overloaded >>: first number is the coefficient and second is the exponent
	//    to terminate >>, input -1 -1
	friend istream& operator>>(istream&, Poly&);

public:
	// default constructor:  parameters are coefficient and exponent, resp.
	Poly(int = 0, int = 0);
	Poly(const Poly&);
	~Poly();
	
	// arithmetic operators
	Poly operator+(const Poly&) const;
	Poly operator-(const Poly&) const;
	Poly operator*(const Poly&) const;

	// assignment operators
	Poly& operator=(const Poly&);
	Poly& operator+=(const Poly&);
	Poly& operator-=(const Poly&);
	Poly& operator*=(const Poly&);

	// boolean comparision operators
	bool operator==(const Poly&) const;
	bool operator!=(const Poly&) const;

	// getters and setters
	int getCoeff(const int) const;
	void setCoeff(const int, const int);

private:
	int* polyArray;
	int size;

	// helper functions
	void resizeArray(const int);
	void addArrays(int*, const Poly&) const;
	void subtractArrays(int*, const Poly&) const;
	void multiplyArrays(int*, const Poly&) const;
};

#endif 
