#include "bookType.h"
#include <iostream>
#include <string>
using namespace std;

//default constructor that sets each data member blank
bookType::bookType() {
	title = "";
	author1 = "";
	author2 = "";
	author3 = "";
	author4 = "";
	publisher = "";
	isbn = "";
	price = 0.0;
	numCopiesInStock = 0;
	numAuthors = 0;
}

//default constructor that sets each data member according to the parameters
bookType::bookType(string t, string a1, string a2, string a3, string a4,
	string p, string i, double pr, int nc, int na) {

	title = t;
	author1 = a1;
	author2 = a2;
	author3 = a3;
	author4 = a4;
	publisher = p;
	isbn = i;
	price = pr;
	numCopiesInStock = nc;
	numAuthors = na;
}

//prints the title of the book
void bookType::showTitle() {

	cout << "Title: " << title << endl;
}

//sets the title of the book according to the parameter
void bookType::setTitle(string otherTitle) {

	title = otherTitle;
}

//checks to see if another title is equal to the current title
bool bookType::checkTitle(string otherTitle) {

	if (title == otherTitle) {
		return true;
	}
	else {
		return false;
	}
}

//prints the number of copies in stock
void bookType::showNumCopiesInStock() {

	cout << "Number of copies in stock: " << numCopiesInStock << endl;
}

//sets the number of copies in stock according to the parameter
void bookType::setNumCopiesInStock(int num) {

	numCopiesInStock = num;
}

//returns the number of copies in stock
int bookType::returnNumCopiesInStock() {

	return numCopiesInStock;
}

//prints the publisher name
void bookType::showPublisher() {

	cout << "Publisher: " << publisher << endl;
}

//sets the publisher name according to the parameter
void bookType::setPublisher(string name) {

	publisher = name;
}

//returns the publisher name
string bookType::returnPublisher() {

	return publisher;
}

//prints the isbn string
void bookType::showIsbn() {

	cout << "ISBN: " << isbn << endl;
}

//sets the isbn string according to the parameter
void bookType::setIsbn(string num) {

	isbn = num;
}

//returns the isbn
string bookType::returnIsbn() {

	return isbn;
}

//checks to see if another isbn is equal to the current isbn
bool bookType::checkIsbn(string num) {

	if (isbn == num) {
		return true;
	}
	else {
		return false;
	}
}

//prints the book price
void bookType::showBookPrice() {

	cout << "Price: $" << price << endl;
}

//sets the book price according to the parameter
void bookType::setBookPrice(double num) {

	price = num;
}

//returns the book price
double bookType::returnBookPrice() {

	return price;
}

//prints the authors
void bookType::showAuthors() {

	cout << "Authors: " << author1 << " " << author2 << " " << author3 << " " << author4 << endl;
}

//sets the author, with the author# and a name
void bookType::setAuthor(int a, string name) {

	switch (a){
	case 1:
		author1 = name;
		break;
	case 2:
		author2 = name;
		break;
	case 3:
		author3 = name;
		break;
	case 4:
		author4 = name;
		break;
	default:
		cout << "Invalid entry. Setting the first author." << endl;
		author1 = name;
	}
}

//returns the author based on the number given
string bookType::returnAuthor(int a) {

	switch (a) {
	case 1:
		return author1;
		break;
	case 2:
		return author2;
		break;
	case 3:
		return author3;
		break;
	case 4:
		return author4;
		break;
	default:
		cout << "Invalid entry. Returning the first author." << endl;
		return author1;
	}
}

//prints all of the details of the bookType
void bookType::print() {

	showTitle();
	showAuthors();
	showPublisher();
	showIsbn();
	showBookPrice();
	showNumCopiesInStock();
}
