#pragma once
#include <iostream>
using namespace std;

template <class Type>
class nodeType
{
public:
	//overloads the = operator to be able to sets two nodes equal to one another
	const nodeType<Type>& operator =(const nodeType<Type>& otherNode);

	//sets the info of the node
	void setInfo(const Type& elem);

	//returns the info of the node
	Type getInfo();

	//sets the link of the node
	void setLink(nodeType<Type>* ptr);

	//returns the link of the node
	nodeType<Type>* getLink();

	//default constructor
	nodeType();

	//default constructor with parameters
	nodeType(const Type& elem, nodeType<Type>* ptr);

	//copy constructor
	nodeType(const nodeType<Type>& otherNode);

	//destructor
	~nodeType();

private:
	Type info; //holds the info of the node
	nodeType<Type>* link; //holds the link of the node
};

//overloads the = operator the sets two nodes equal to one another
template<class Type>
const nodeType<Type>& nodeType<Type>::operator =(const nodeType<Type>& otherNode)
{
	if (this != &otherNode) //if this node is not equal to the other node
	{
		link = otherNode.link; //this info set to the other node info
		info = otherNode.info; //this link set to the other node link
	}

	return *this; //returns this node
}

//sets the info of the node
template <class Type>
void nodeType<Type>::setInfo(const Type& elem)
{
	info = elem;
}

//returns the info of the node
template <class Type>
Type nodeType<Type>::getInfo()
{
	return info;
}

//sets the link of the node
template <class Type>
void nodeType<Type>::setLink(nodeType<Type>* ptr)
{
	link = ptr;
}

//returns the link of the node
template <class Type>
nodeType<Type>* nodeType<Type>::getLink()
{
	return link;
}

//default constructor 
template <class Type>
nodeType<Type>::nodeType()
{
	link = NULL; //sets the link to null
}

//default constructor with parameters
template <class Type>
nodeType<Type>::nodeType(const Type& elem, nodeType<Type>* ptr)
{
	info = elem; //sets the info
	link = ptr; //sets the link
}

//copy constructor
template <class Type>
nodeType<Type>::nodeType(const nodeType<Type>& otherNode)
{
	info = otherNode.info; //sets the info equal to the other node info
	link = otherNode.link; //sets the link equal to the other node link
}

//destructor
template <class Type>
nodeType<Type>::~nodeType()
{
	link = NULL; //sets the link back to null
}

