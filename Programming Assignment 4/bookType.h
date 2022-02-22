#pragma once
#include <iostream>
#include <string>
using namespace std;

class bookType {

public:

	bookType(); //default constructor with no parameters
	bookType(string t, string a1, string a2, string a3, string a4, string p,
		string i, double pr, int nc, int na); //default constructor with all parameters

	void print(); //prints the data of a bookType

	void showTitle(); //prints the title
	void setTitle(string otherTitle); //sets the title
	bool checkTitle(string otherTitle); //checks to see if another title is equal to the current title

	void showNumCopiesInStock(); //prints the number of copies in stock
	void setNumCopiesInStock(int num); //sets the number of copies in stock
	int returnNumCopiesInStock(); //returns the number of copies in stock

	void showPublisher(); //prints the title
	void setPublisher(string name); //sets the title
	string returnPublisher(); //returns the title

	void showIsbn(); //prints the isbn
	void setIsbn(string num); //sets the isbn
	string returnIsbn(); //returns the isbn
	bool checkIsbn(string num); //checks to see if another isbn is equal to the current isbn

	void showBookPrice(); //prints the book price
	void setBookPrice(double num); //sets the book price
	double returnBookPrice(); //returns the book price

	void showAuthors(); //prints the authors
	void setAuthor(int a, string name); //sets the author with a number for the author#, and a name
	string returnAuthor(int a); //returns the author by their author#

private:

	string title, //holds the title name
		author1,  //holds the name of author1
		author2,  //holds the name of author2
		author3,  //holds the name of author3
		author4,  //holds the name of author4
		publisher,//holds the publisher name
		isbn;     //holds the isbn string

	double price; //holds the price of the book

	int numCopiesInStock, //holds the number of copies in stock
		numAuthors;       //holds the number of authors
};
