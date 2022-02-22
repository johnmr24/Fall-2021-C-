#include "clockType.h"
#include <iostream>
using namespace std;

int main() {

	clockType c1(6, 35, 40);
	clockType c2(5, 55, 30);


	//outputting the times of clock 1 and 2
	cout << "Clock 1: " << c1 << endl;
	cout << "Clock 2: " << c2 << endl;
	

	//adding and outputting the time of both clocks
	cout << "Adding the times of clock 1 and 2: ";
	cout << c1 + c2 << "\n";


	//outputting if both clocks have the same time or not
	if (c1 == c2) {
		cout << "The times for clock 1 and 2 are the same. \n \n";
	}
	else {
		cout << "The times for clock 1 and 2 are different. \n \n";
	}


	//setting the time of clock 1 to the time of clock 2
	c1 = c2;


	//outputting the changed time of clock 1 and if it is equal to clock 2
	cout << "Changed the time of clock 1 to: " << c1 << endl;
	if (c1 == c2) {
		cout << "The times for clock 1 and 2 are the same. \n \n";
	}
	else {
		cout << "The times for clock 1 and 2 are different. \n \n";
	}




}