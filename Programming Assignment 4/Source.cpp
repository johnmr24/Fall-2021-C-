#include "bookType.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findByTitle(vector<bookType> list, string t); //function to search a vector for a book title
int findByIsbn(vector<bookType> list, string i);  //function to search a vector for a book isbn

int main() {

	int position; //holds the index when searching for isbn or title
	vector<bookType> bookList; //vector to hold elements of type bookType
	bookType book1, book2, book3; //3 bookTypes that will be initialized

	//initializing book 1:
	book1.setTitle("The Hunger Games");
	book1.setAuthor(1, "Suzanne Collins");
	book1.setPublisher("Scholastic Press");
	book1.setIsbn("9780439023481");
	book1.setBookPrice(25.99);
	book1.setNumCopiesInStock(15);

	//initializing book2:
	book2.setTitle("To Kill A Mockingbird");
	book2.setAuthor(1, "Harper Lee");
	book2.setPublisher("J. B. Lippincott & Co.");
	book2.setIsbn("9780446310789");
	book2.setBookPrice(15.99);
	book2.setNumCopiesInStock(7);

	//initializing book3:
	book3.setTitle("Catch-22");
	book3.setAuthor(1, "Joseph Heller");
	book3.setPublisher("Simon & Schuster");
	book3.setIsbn("9780099529118");
	book3.setBookPrice(18.99);
	book3.setNumCopiesInStock(40);

	//adding the books to the vector:
	bookList.push_back(book1);
	bookList.push_back(book2);
	bookList.push_back(book3);

	//printing each bookType in the vector:
	cout << "Printing All Of The Books In The Book List..." << endl;
	for (int i = 0; i < bookList.size(); i++) { //steps through each bookType in the bookList
		cout << endl;
		bookList[i].print(); //prints the bookType and its data
	}

	cout << endl;
	cout << "Searching For Title Catch-22..." << endl;

	//searching the bookList for the title Catch-22:
	position = findByTitle(bookList, "Catch-22"); //sets position
	if (position == -1) { //if title not in the list...
		cout << "Catch-22 is not in the book list." << endl;
	}
	else { //else, the title is in the list...
		cout << "Catch-22 is in the book list, and at position " << position << "." << endl;
	}

	cout << endl;
	cout << "Searching For ISBN 19020483547682..." << endl;

	//searching the bookList for the isbn 19020483547682...
	position = findByIsbn(bookList, "19020483547682"); //sets position
	if (position == -1) { //if isbn not in the list
		cout << "19020483547682 is not in the book list." << endl;
	}
	else { //else, the isbn is in the list
		cout << "19020483547682 is in the book list, and at position " << position << "." << endl;
	}

	return 0;
}

//returns the index of a bookType in a vector, else returns -1
int findByTitle(vector<bookType> list, string t) {

	int position = -1;
	for (int i = 0; i < list.size(); i++) { //steps through the vector

		if (list[i].checkTitle(t)) { //checks each bookType to see if the title matches
			position = i;
		}
	}
	return position; //returns the index
}

//returns the isbn of a bookType in a vector, else returns -1
int findByIsbn(vector<bookType> list, string is) {

	int position = -1;
	for (int i = 0; i < list.size(); i++) { //steps through the vector

		if (list[i].checkIsbn(is)) { //checks each bookType to see if the isbn matches
			position = i;
		}
	}
	return position; //returns the index
}