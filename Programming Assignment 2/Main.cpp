#include "quadraticEq.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){

	quadraticEq q1;           //variables to hold a sample quadraticEq object
	quadraticEq q2(3, 4, 5);  //uses the default constructor to set the coefficients
	quadraticEq q3 = q1 + q3; //sets q3 to be equal to the coefficients of q1+q2
	cout << "Enter the a, b, and c coefficients of a quadratic equation: "; 
	cin >> q1; //user inputs the a, b, and c coefficients

	cout << endl;                  //outputs the roots to each quadraticEq object
	cout << "q1 - " << q1 << endl;
	cout << "q2 - " << q2 << endl;
	cout << "q3 - " << q3 << endl;

	return 0;
}