#pragma once
#include <iostream>
#include <string>
using namespace std;

class quadraticEq {

	friend ostream& operator<<(ostream&, quadraticEq&); //overloaded output
	friend istream& operator>>(istream&, quadraticEq&); //overloaded input

public:

	double calcDiscriminant(); //calculates the discriminant
	string calcRoot1();        //calculates the first root
	string calcRoot2();        //calculates the second root

	quadraticEq operator +(const quadraticEq&); //overloads the + operator
	quadraticEq operator -(const quadraticEq&); //overloads the - operator
	bool operator==(const quadraticEq&);        //overloads the == operator
	bool operator!=(const quadraticEq&);        //overloads the != operator

	quadraticEq();                       //default constructor with no parameters
	quadraticEq(double, double, double); //default constructor with parameters

private:
	double a, b, c; //holds the a, b, and c coefficients
	string r1, r2;  //holds the first and second root
};
