//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"

// set headptr to null, set current size to zero
template<class ItemType>
Stack<ItemType>::Stack() 
{
	headPtr=NULL;
	currentSize=0;
}  // end default constructor

// TODO: Implement the destructor here
template<class ItemType>
Stack<ItemType>::~Stack()
{
	if (headPtr==NULL)
		return;

	//delete start pointer
	delete headPtr;
}  // end destructor

// Return true if currentSize is 0
template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	return !(size());
}  // end isEmpty

// return currentSize
template<class ItemType>
int Stack<ItemType>::size() const
{
	return currentSize;
}  // end size

// pushes an item to the end of the stack
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{	
	//check if stack is empty
	if (isEmpty())
	{
		//Create new pointer to only node in the stack
		Node<ItemType>* currentNode=new Node<ItemType>;
		headPtr=currentNode;
		headPtr->setItem(newItem);
		headPtr->setNext(NULL);

		//increment size
		currentSize++;

		return true;
	}

	//pointer to node to loop through the stack
	Node<ItemType>* currentNode=headPtr;
	
	//loop to the end of the stack (last element)
	while(currentNode->getNext()!=NULL)
	{
		//currentNode will point to final element
		currentNode=currentNode->getNext();
	}

	//Create a node to add to the stack, set its item, and link it to previous node
	Node<ItemType>* endNode=new Node<ItemType>;
	endNode->setItem(newItem); 
	currentNode->setNext(endNode);
	endNode->setNext(NULL);

	//increment size
	currentSize++;

	return true;
}  // end push

// return last element in the stack
template<class ItemType>
ItemType Stack<ItemType>::peek() const throw(logic_error)
{
	//returnItem stores the item in the last stack element
	ItemType returnItem;

	//node used to loop through stack
	Node<ItemType>* currentNode=headPtr;

	//get last node
	while(currentNode->getNext()!=NULL)
	{
		//currentNode will point to final element
		currentNode=currentNode->getNext();
	}

	//set returnItem to item in last stack element and return it
	returnItem=currentNode->getItem();
	return returnItem;
}  // end peek

// TODO: Implement the pop method here
template<class ItemType>
bool Stack<ItemType>::pop() 
{
	return false;
}  // end pop

// TODO: Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear()
{
}  // end clear

