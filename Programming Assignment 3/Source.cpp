#include "safeArray.h"
#include <iostream>
using namespace std;

int main() {

	safeArray list1(-5, 4);
	
	for (int i = 0; i < 10; i++) {
		list1.add(i);
	}

	list1.print();
	cout << endl;

	cout << "Removing the number in index -4 of the array..." << endl;
	list1.remove(-4);
	list1.print();
	cout << endl;

	cout << "Adding the number 25 into index -1..." << endl;
	list1.add(25, -1);
	list1.print();
	cout << endl;

	cout << "Adding the number 45 to the end of the list..." << endl;
	list1.add(45);
	cout << endl;

	cout << "Removing the number at index 3..." << endl;
	list1.remove(3);
	list1.print();
	cout << endl;

	cout << "Adding the number 23 to index -7..." << endl;
	list1.add(23, -7);
	cout << endl;
	
	cout << "Searching for 25 in the list..." << endl;
	if (list1.search(25) != -999) {
		cout << "Found at index: ";
		cout << list1.search(25) << endl;
	}
	else {
		cout << "25 is not in the list." << endl;
	}

	return 0;
}