#include "safeArray.h"
#include <iostream>
#include <cassert>

using namespace std;

//constructor that initializes a list with a set size
safeArray::safeArray(int size) {

	if (size < 0) { //size cannot be less than 0
		cout << "Size must be greater than or equal to 0." << endl;
		cout << "Now initializing size to 100." << endl;
		maxSize = 100; //intitializes max size to be 100
	}
	else {
		maxSize = size;
	}

	//since there are no specified indexes with this constuctor,
	//first and last index are normal
	firstIndex = 0; 
	lastIndex = 99;
	length = 0;
	list = new int[maxSize];
	assert(list != NULL);
}

//constructor that initializes the list using user inputs
//for first and last index
safeArray::safeArray(int first, int last) {

	if (first > last) { //if the orders are reversed...
		cout << "The first index must be smaller than the" << endl;
		cout << "last index. Reversing the two." << endl;

		maxSize = first - last + 1; //using the first and last index, find the size
		firstIndex = last; //since reversed, first and last index are also reversed
		lastIndex = first;
	}

	else {
		maxSize = last - first + 1;
		firstIndex = first;
		lastIndex = last;
	}

	length = 0;
	list = new int[maxSize]; //initialize list
	assert(list != NULL);
}

//returns true if the list is empty and false if it isnt empty
bool safeArray::isEmpty() const {

	return (length == 0);
}

//returns true if the list is full and false is it isnt full
bool safeArray::isFull() const {

	return (length == maxSize);
}

//returns the size of the list or the numbers of items in it
int safeArray::listSize() const {

	return length;
}

//adds a number at the end of the list
void safeArray::add(int num) {

	//if the list is not full, add the number
	if (length >= 0 && length < maxSize) {
		list[length++] = num;
	}
	//cannot add into a full list
	else if (length == maxSize) {
		cout << "Cannot add an item into a full list." << endl;
	}

}

//adds a number to the specified index
void safeArray::add(int num, int index) {

	//cannot add into a full list
	if (length == maxSize) {
		cout << "Cannot add an item into a full list." << endl;
	}
	//if the list is not full
	else {
		//make sure the index is in the range of the list
		if (index < firstIndex || index > lastIndex) {
			cout << "Index is out of range of the list." << endl;
		}
		else {
			//loop through the list and move the items past the index
			for (int i = length; i > (index - firstIndex); i--) {
				list[i] = list[i - 1];
			}

			//insert the number into the list and increase the length
			list[index - firstIndex] = num;
			length++;
		}
	}
	
}

//removes the number at the end of the list
void safeArray::remove() {

	//cannot remove from an empty list
	if (length == 0) {
		cout << "The list is empty are there are no items to remove." << endl;
	}
	//decrease the length of the list (remove the item at the end)
	else {
		length--;
	}
}

//removes the number at the specified index
void safeArray::remove(int index) {

	//make sure the index is in the range of the list
	if (index < firstIndex || index > lastIndex) {
		cout << "The index specified is out of range." << endl;
	}
	else {
		//loop through the list and move the items in front of the index
		for (int i = (index - firstIndex); i < length - 1; i++) {
			list[i] = list[i + 1];
		}
		length--; //decrease the length of the list
	}

}

//prints the contents of the array
void safeArray::print() const {

	cout << "Array Details: ";
	if (length == 0) {
		cout << "Empty List" << endl;
	}
	else {
		for (int i = 0; i < length; i++) {
			cout << list[i] << " ";
		}
	}
	cout << endl;

}

//searches the array for a number
int safeArray::search(int num) {

	int loc = -999; //unlikely number to choose

	for (int i = 0; i < length; i++) {
		if (list[i] == num) {
			loc = i;
			break;
		}
	}

	return loc + firstIndex; //convert the index to the format of the user array

}

//copy constructor to set a safeArray equal to another safeArray
safeArray::safeArray(const safeArray& otherList) {

	maxSize = otherList.maxSize;
	length = otherList.length;
	firstIndex = otherList.firstIndex;
	lastIndex = otherList.lastIndex;
	list = new int[maxSize];
	assert(list != NULL);

	for (int i = 0; i < length; i++) {
		list[i] = otherList.list[i];
	}

}

//destructor to deallocate memory for the array
safeArray::~safeArray() {
	delete[] list;
}

//overloaded = operator to set one safeArray equal to another
const safeArray& safeArray::operator=(const safeArray& otherList) {

	if (this != &otherList) {
		delete[] list;
		maxSize = otherList.maxSize;
		length = otherList.length;

		list = new int[maxSize];
		assert(list != NULL);

		for (int i = 0; i < length; i++) {
			list[i] = otherList.list[i];
		}
	}

	return *this;
}