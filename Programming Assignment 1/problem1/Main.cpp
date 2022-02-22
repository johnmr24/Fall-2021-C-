#include "extClockType.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

	extClockType c1;
	extClockType c2(5, 30, 45, "EST");


	//setting and printing the time of clock 1
	c1.setTime(8, 65, 80, "CDT");
	cout << "Printing the time of clock 1: \n";
	c1.printTime();
	cout << "\n \n";


	//printing the time of clock 2
	cout << "Printing the time of clock 2: \n";
	c2.printTime();
	cout << "\n \n";


	//checking and printing if clock 1 and 2 are equal
	if (c1.equalTime(c2)) {
		cout << "These two times are equal. \n \n";
	}
	else {
		cout << "These two times are not equal. \n \n";
	}

	
	//changing the time of clock 1 and printing it to match the time of clock 2
	c1.setTime(5, 30, 45, "EST");
	cout << "Changed the time of clock 1 to: \n";
	c1.printTime();
	cout << "\n \n";


	//checking and printing if clock 1 and 2 are equal
	if (c1.equalTime(c2)) {
		cout << "These two times are equal. \n \n";
	}
	else {
		cout << "These two times are not equal. \n \n";
	}
	

	return 0;
}