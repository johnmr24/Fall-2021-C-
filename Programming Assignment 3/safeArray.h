#pragma once
#include <iostream>

using namespace std;

class safeArray {

public:

	const safeArray& operator=(const safeArray& otherList); //overloaded = oeprator

	int listSize() const;                     //returns the list size
	bool isEmpty() const;                     //returns if the list is empty
	bool isFull() const;                      //returns if the list is full
	void add(int num);                        //adds a number at the end of the list
	void add(int num, int index);             //adds a number at specified index
	void remove();                            //removes a number at the end of the list
	void remove(int index);                   //removes the number at the index
	void print() const;                       //prints the list details
	int search(int num);                      //searches the list for a number

	safeArray(int size = 100);                //default constructor with 1 parameter
	safeArray(int firstIndex, int lastIndex); //default constructor with 2 parameters
	safeArray(const safeArray& otherList);    //copy constructor
	~safeArray();                             //destructor

private:

	int* list;                                //holds the list
	int length;                               //holds the list length
	int maxSize;                              //holds the max size of the list
	int firstIndex, lastIndex;                //holds the first and last index
};
