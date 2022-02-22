#include "CircularLinkedList.h"
#include <iostream>
using namespace std;

int main() {

	bool isEmpty; //holds if the list is empty
	bool found; //holds if an item is found in a list
	CircularLinkedList<int> c1; 
	CircularLinkedList<int> c2;
    
	isEmpty = c1.isEmpty(); 
	if (isEmpty) //the list is empty
	{
		cout << "c1 is empty." << endl;
	}
	else //the list is not empty
	{
		cout << "c1 is not empty." << endl;
	}
	cout << endl;

	//insert five items
	c1.insert(4);
	c1.insert(20);
	c1.insert(2);
	c1.insert(15);
	c1.insert(9);
	
	//prints the contents of c1
	cout << "c1 contents after adding items: ";
	c1.print();
	cout << endl;

	//prints the length of c1
	cout << "The length of c1 is: " << c1.length() << endl;
	cout << endl;

	//copies the elements of c1 into c2 and prints c2
	c2.copy(c1);
	cout << "c2 has copied the elements of c1, contents: ";
	c2.print();
	cout << endl;

	//searches c2 for 15
	cout << endl;
	cout << "Searching for 15 in list c2..." << endl;
	found = c2.search(15);
	if (found) //15 is in the list
	{
		cout << "15 is in c2." << endl;
	}
	else //15 is not in the list
	{
		cout << "15 is not in c2" << endl;
	}

	//initializes c3 using the copy constructor and prints the contents of c3
	cout << endl;
	CircularLinkedList<int> c3(c2);
	cout << "c3 contents: ";
	c3.print();
	cout << endl;

	//deletes 20 from c3 and prints the contents of c3
	cout << endl;
	c3.deleteItem(20);
	cout << "c3 after deleting 20: ";
	c3.print();
	cout << endl;

	return 0;
}