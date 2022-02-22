#include "quadraticEq.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double quadraticEq::calcDiscriminant() { //calculates the discriminant;
	return ((b * b) - (4 * a * c));      //discriminant formula
}

quadraticEq::quadraticEq() { //default constructor with no parameters
	a = 0; 
	b = 0;
	c = 0;
}

quadraticEq::quadraticEq(double x, double y, double z) { //default constructor with parameters
	a = x;
	b = y;
	c = z;
}

quadraticEq quadraticEq::operator+(const quadraticEq& otherQuad) { //overloads the + operator

	quadraticEq temp;

	temp.a = a + otherQuad.a;
	temp.b = b + otherQuad.b;
	temp.c = c + otherQuad.c;

	return temp;
}

quadraticEq quadraticEq::operator-(const quadraticEq& otherQuad) { //overloads the - operator

	quadraticEq temp;

	temp.a = a - otherQuad.a;
	temp.b = b - otherQuad.b;
	temp.c = c - otherQuad.c;

	return temp;
}

bool quadraticEq::operator==(const quadraticEq& otherQuad) { //overloads the == operator

	if (a == otherQuad.a && b == otherQuad.b && c == otherQuad.c) {
		return true;
	}
	else {
		return false;
	}
}

bool quadraticEq::operator!=(const quadraticEq& otherQuad) { //overloads the != operator

	if (a != otherQuad.a && b != otherQuad.b && c != otherQuad.c) {
		return true;
	}
	else {
		return false;
	}
}

string quadraticEq::calcRoot1() {                                      //calculates the first root

	if (calcDiscriminant() == 0 || calcDiscriminant() > 0) {           //if the discriminant has
		                                                               //two roots, it will calc
		double temp = ((-1 * b) + sqrt(calcDiscriminant())) / (2 * a); //the root and turn it to 
		r1 = to_string(temp);                                          //a string
	}
	else {                                                             //if the discriminant has
		r1 = to_string((-1*b)/(2*a));                                  //two complex roots, calc
		r1 += "+";                                                     //the root and turn it to
		r1 += to_string(sqrt((-1*calcDiscriminant())) / (2 * a));      //a string
		r1 += "i";
	}

	return r1;
}

string quadraticEq::calcRoot2() {                                      //calculates the first root

	if (calcDiscriminant() == 0 || calcDiscriminant() > 0) {           //if the discriminant has
																	   //two roots, it will calc
		double temp = ((-1 * b) - sqrt(calcDiscriminant())) / (2 * a); //the root and turn it to 
		r2 = to_string(temp);                                          //a string
	}
	else {                                                             //if the discriminant has
		r2 = to_string((-1 * b) / (2 * a));                            //two complex roots, calc
		r2 += "-";                                                     //the root and turn it to
		r2 += to_string(sqrt((-1*calcDiscriminant())) / (2 * a));      //a string
		r2 += "i";
	}

	return r2;
}

ostream& operator<<(ostream& output, quadraticEq& r) { //overloads the extraction operator

	if (r.calcRoot1() == r.calcRoot2()) {

		output << "One root: " << r.calcRoot1() << endl;
	}
	
	else {
		output << "Two roots: \n" <<  r.calcRoot1() << " and " << r.calcRoot2() << endl;
	}

	return output;
}

istream& operator>>(istream& input, quadraticEq& r) { //overloads the insertion operator

	input >> r.a >> r.b >> r.c;

	return input;
}
