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
	if (isEmpty())
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

// Pops the last element off of the stack
template<class ItemType>
bool Stack<ItemType>::pop() 
{
	//check if size of the stack is zero
	if (currentSize==0)
		return false;

	//Pointer for looping to last element and pointer to element right before the last stack element
	Node<ItemType>* currentNode=headPtr;
	Node<ItemType>* previousNode=headPtr;

	//get last node
	while(currentNode->getNext()!=NULL)
	{
		//previousNode points to element before current Node
		previousNode=currentNode;
		
		//currentNode will point to final element
		currentNode=currentNode->getNext();
	}

	//Unlink last node and delete it, decrement size
	previousNode->setNext(NULL);
	delete currentNode;
	currentSize--;

	return true;
}  // end pop

// Clears all elements of the stack
template<class ItemType>
void Stack<ItemType>::clear()
{
	//check if stack is empty
	if (isEmpty())
		return;
	
	//Pointer for looping to last element and to hold previous node
	Node<ItemType>* currentNode;
	Node<ItemType>* previousNode;

	//Delete each element except first
	while(currentSize>1)
	{
		currentNode=headPtr;
		previousNode=currentNode;

		//get last node and delete it
		while(currentNode->getNext()!=NULL)
		{
			//previousNode points to node before currentNode
			previousNode=currentNode;
			
			//currentNode will point to final element
			currentNode=currentNode->getNext();
		}

		//Delete last element
		previousNode->setNext(NULL);
		delete currentNode;
		currentSize--;
	}

	//set headPtr to null and decrease size
	headPtr=NULL;
	currentSize--;
}  // end clear

