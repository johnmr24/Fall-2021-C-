#include "NodeType.h"
#include <iostream>
using namespace std;

template <class Type>
class CircularLinkedList
{
public:
	void initialize(); //initializes the list to be empty
	bool isEmpty(); //checks whether or not the list is empty
	void destroy(); //destroys the list by removing all elements from the list
	void print(); //prints the elements of the list
	int length(); //returns the length of the list
	bool search(const Type& searchItem); //searches the list for a specific item
	void insert(const Type& insertItem); //inserts an item into the list
	void deleteItem(const Type& deleteItem); //deletes a specific item from the list
	void copy(const CircularLinkedList<Type>& otherList); //copys the elements of one list into another

	CircularLinkedList(); //default constructor with no parameters
	CircularLinkedList(const CircularLinkedList<Type>& otherList); //copy constructor
	~CircularLinkedList(); //destructor

protected:
	int count; //holds the numbers of elements in the list
	nodeType<Type>* first; //stores the address of the first node in the list
	nodeType<Type>* last; //stores the address of the last node in the list
};

//initializes the list to be empty
template <class Type>
void CircularLinkedList<Type>::initialize()
{
	destroy(); //call the destroy function
}

//checks whether or not the list is empty
template <class Type>
bool CircularLinkedList<Type>::isEmpty()
{
	return (first == NULL); //return true if the list is empty, false if there are items in the list
}

//destroys the list by removing the items from the list
template <class Type>
void CircularLinkedList<Type>::destroy() 
{
	nodeType<Type>* temp; //create a temp node so that no addresses are lost

	if (first != NULL) //if the list is not empty
	{
		last->setLink(NULL); //temporarily sets the last link to null so that you can step through 
	}                        //the list and reach the end (null). Otherwise the last link will point to
	                         //the first item and the loop will go on forever.

	while (first != NULL) //while the first item is not empty
	{
		temp = first; 
		first = first->getLink(); //sets the temp node to the first node, increments the first node
		delete temp;              //and then deletes the temp node.
	}

	count = 0; //return the count value back to 0
}

//prints the elements of the list
template <class Type>
void CircularLinkedList<Type>::print()
{
	
	nodeType<Type>* current; //create a node that will act as a iterator

	current = first; //sets the iterator equal to the first node
						
	if (current != NULL) //if the list is not empty
	{
		cout << current->getInfo() << " "; //output the first node info and increments to next node
		current = current->getLink();

		while (current != last->getLink()) //while the current node is not equal to the first node
		{                                  //this allows the loop to stop once the current prints out
			                               //the last node

			cout << current->getInfo() << " "; //outputs the node info and increments to next node
			current = current->getLink();
		}
	}

}

//returns the length of the list
template <class Type>
int CircularLinkedList<Type>::length()
{
	return count; //return the count variable
}

//searches the list for a certain item
template <class Type>
bool CircularLinkedList<Type>::search(const Type& searchItem)
{
	nodeType<Type>* current; //creates a node that will act as an iterator
	bool found = false; //creates a bool variable to hold the status of if the item is found

	last->setLink(NULL); //temporarily sets the last link to null
	current = first; //sets the current equal to the first node

	while (current != NULL && !found) //while current is not empty and the item is not found
	{
		if (current->getInfo() == searchItem) //if the current node info is equal to the search item
		{
			found = true; //found is set to true and breaks from the loop
			break;
		}
		else //else, the current info is not equal to the search item
		{
			current = current->getLink(); //current is incremented to the next node
		}
	}
	
	last->setLink(first); //after the loop, the last link is set back to the first node to complete 
	                      //the circular link

	return found; //returns true if found, false if not found
}

//inserts a certain item into the list based on where it need to go (ascending order)
template <class Type>
void CircularLinkedList<Type>::insert(const Type& insertItem)
{
	nodeType<Type>* current; //node to act as an iterator
	nodeType<Type>* trailCurrent; //trails the current node
	nodeType<Type>* newNode; //new node to be inserted in the list

	bool found; //bool to help determine where the insertItem should be inserted

	newNode = new nodeType<Type>; //dynamically creates a new node, sets its info to the insert
	newNode->setInfo(insertItem); //item, and temporarily sets its link to null
	newNode->setLink(NULL);

	if (first == NULL) //if the list is empty
	{
		first = newNode;
		last = newNode;  //sets the first and last node equal to the new node and increments the count
		count++;         //variable (the length)
	}
	
	else //else, the list has some elements
	{
		trailCurrent = first; //initializes trailcurrent and current to the first node
		current = first;

		found = false; //initializes found to false

		last->setLink(NULL); //temporarily sets the last link to null

		while (current!=NULL && !found) //while the current node is not empty and the insertItem is not found
		{

			if (count == 1) //if there is only one node in the list
			{
				break; //break from the loop
			}

			else if (current->getInfo() >= insertItem) //if the current node info is greater than or equal to the 
			{                                          //insert item

				found = true; //found equal true, now know where the item needs to be inserted
			}
			
			else if (current->getInfo() < insertItem) //if the current node info is less than the insert item
			{
				trailCurrent = current; //increment to trailcurrent node by one
				current = current->getLink(); //increment the current node by one
			}
			
		}
		
		if (count == 1) //if there is only one item in the list
		{
			if (current->getInfo() <= insertItem) //if the current node info is greater than or equal to the insert item
			{
				first->setLink(newNode); //inserts the new node after the first node, sets the last equal to the new node,
				newNode->setLink(first); //and sets the last link equal to the first, completing the circle link
				last = newNode;
				count++; //increments the length of the list
			}
			
			else //else, the current node info is less than the insert item
			{	
				last->setLink(newNode); //inserts the new node before the last node, sets the first equal to the new node,
				newNode->setLink(last); //and sets the first link equal to the last, completing the circle link
				first = newNode;
				count++; //increments the length of the list
			}
			
		}
		
		else //if there is more than one item in the list
		{
			if (trailCurrent == last) //if the trail current reached the last item, the item needs to be inserted after
			{                         //the last node
				 
				trailCurrent->setLink(newNode); //sets the trailcurrent link equal to the new node, sets last equal to the new node,
				last = newNode;                 //and then sets the last link back to the first, completing the circle link
				last->setLink(first);
				count++; //increments the length of the list
			}
			else //else, the item needs to be inserted at the beginning or between 2 other nodes
			{
				if (current == first) //if the current is equal to the first node, the item needs to be inserted before
				{                     //the first node

					last->setLink(newNode);  //sets the last link equal to the new node, sets the new node link equal to the first node,
					newNode->setLink(first); //and then sets the first equal to the new node
					first = newNode;
					count++; //increments the length of the list
				}
				else //else, the item needs to be inserted between 2 nodes in the middle of the list
				{
					trailCurrent->setLink(newNode); //sets the trailcurrent link equal to the new node and sets the new node
					newNode->setLink(current);      //link equal to the current node
					count++; //increments the length of the list
				}
			}
		}
	}
}

//default constructor 
template <class Type>
CircularLinkedList<Type>::CircularLinkedList()
{
	first = NULL; //sets first to null
	last = NULL; //sets last to null
	count = 0; //sets count (length) to 0
}

//destructor
template <class Type>
CircularLinkedList<Type>::~CircularLinkedList()
{
	destroy(); //calls the destroy function
}

//deletes a specific item from the list
template <class Type>
void CircularLinkedList<Type>::deleteItem(const Type& deleteItem)
{
	nodeType<Type>* current; //node that acts as an iterator
	nodeType<Type>* trailCurrent; //trails the current node
	bool found = false; //helps determine where the item needs to be deleted from

	if (first == NULL) //if the list is empty
	{
		cout << "Cannot delete from an empty list." << endl;
	}
	
	else //else, there are items in the list
	{
		last->setLink(NULL); //temporarily sets the last link equal to null

		current = first; //current and trailcurrent are initialized to the first node
		trailCurrent = first;

		while (current != NULL && !found) //while the current node is not empty and the item is not found
		{
			if (current->getInfo() >= deleteItem) //if the current node info is greater than or equal to the 
			{                                     //delete item

				found = true; //found is set to true, now know where the item needs to be deleted from
			}
			else //else, the item is not found yet
			{
				trailCurrent = current; //increments the trailcurrent and current by one
				current = current->getLink();
			}
		}

		if (current == NULL) //if the current item is equal to null, the loop completed without the item being found
		{
			cout << "The item to be deleted is not in the list" << endl;
		}
		else //else, the item was found
		{
			if (current->getInfo() == deleteItem) //if the current node info is equal to the delete item
			{
				if (current == first) //if the current node is equal to the first, the item needs to be deleted from the
				{                     //front of the list
					 
					first = first->getLink(); //first node is set to the next node

					if (first == NULL) //if the first node is now empty
					{
						last = NULL; //sets the last the null, and no items are not in the list
					}

					delete current; //deletes the node that contains the delete item
				}
				else //else, the node needs to be deleted after the first item
				{
					trailCurrent->setLink(current->getLink()); //trailcurrent is set to the currents link and skips over the node
					                                           //between trailcurrent and current

					if (current == last) //if the current node is equal to the last, the item was deleted from the end of the list
					{                    //and the last needs to be reset to the item before the last item

						last = trailCurrent; 
					}

					delete current; //deletes the node contained the delete item
				}
				count--; //decrements the length of the list
			}
			else //else, the item is not in the list
			{
				cout << "The item to be deleted is not in the list" << endl;
			}
		}
		last->setLink(first); //returns the last link back to the first, completing the circle link
	}
	
}

//copies the nodes from one list to another
template <class Type>
void CircularLinkedList<Type>::copy(const CircularLinkedList<Type>& otherList)
{
	nodeType<Type>* newNode; //pointer to create a node
	nodeType<Type>* current; //pointer to traverse the list

	if (first != NULL) //if the list is not empty, destroys the list to initialize it
	{
		destroy(); 
	}

	if (otherList.first == NULL) //if the other list is empty, sets this list to empty
	{
		first = NULL; //sets first to null
		last = NULL; //sets last to null
		count = 0; //sets count to 0
	}
	else //else, the other list has nodes in it
	{
		otherList.last->setLink(NULL); //temporarily sets the otherList last link to null

		current = otherList.first; //sets current to the otherList first node to traverse the list

		count = otherList.count; //sets the count equal to the otherList count

		first = new nodeType<Type>;	//sets the first node equal to the otherList first node	
		first->setInfo(current->getInfo()); 
		first->setLink(NULL);				
											
		last = first; //since one item was added, first and last are equal				
											
		current = current->getLink(); //current is incremented by 1	
											
		while (current != NULL) //while the current item is not empty, copy the rest of the nodes
		{
			newNode = new nodeType<Type>;			
			newNode->setInfo(current->getInfo()); //new node gets the info from the otherList current node
			newNode->setLink(NULL);	//link temporarily set to null	
													
			last->setLink(newNode);	//sets the last link to the new node			
			last = newNode;	//changes the last to point to the new node			
													
			current = current->getLink(); //current is incremented by 1		
													
		}
		otherList.last->setLink(otherList.first); //otherList last link set back to first, completing the circle link
		last->setLink(first); //this last link set back to first, completing the circle link
	}
}

//copy constructor
template <class Type>
CircularLinkedList<Type>::CircularLinkedList(const CircularLinkedList<Type>& otherList)
{
	first = NULL; //sets the first equal to null to prepare to copy
	copy(otherList); //calls the copy function
}

