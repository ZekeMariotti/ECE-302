#include "linked_list.hpp"
#include <iostream>

//destructor
template <typename T>
LinkedList<T>::LinkedList()
{
  headPtr=NULL;
	size=0;
}

//destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
  if (isEmpty())
		return;

	//delete start pointer
		delete headPtr;
}

//copy constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  //if x is empty, make calling object empty
  if (x.isEmpty())
  {
    headPtr=NULL;
    return;
  }

  //create new pointers
  headPtr=new Node<T>;
  Node<T>* newNode;

  //Create pointer to loop through list and to copy data
  Node<T>* loopx=x.headPtr;
  Node<T>* copy=headPtr;

  //Copy data by looping through list x
  for(int i=0; i<x.getLength(); i++)
  {
     //Set item of copy node to item of loop node
     copy->setItem(loopx->getItem());

     //Node to hold pointer to new node
     newNode=new Node<T>;

     //increment copy and loop to their next nodes
     copy->setNext(newNode);
     loopx=loopx->getNext();
     copy=copy->getNext();
  }
  
  //copy size
  size=x.size;
}

//swaps two lists
template <typename T>
void LinkedList<T>::swap(LinkedList<T>& x, LinkedList<T>& y)
{
  //Create new pointer to hold data 
  Node<T>* newStart=x.headPtr;
  int xsize=x.size;

  //switch start pointers 
  x.headPtr=y.headPtr;
  x.size=y.size;
  
  //Switch y pointers to new pointers
  y.headPtr=newStart;
  y.size=xsize;
}

//copy assignment
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
  //create new pointers
  headPtr=new Node<T>;

  //Create pointer to loop through list and to copy data
  Node<T>* loopx=x.headPtr;
  Node<T>* copy=headPtr;

  //Copy data by looping through list x
  for(int i=0; i<x.getLength(); i++)
  {
     //Set item of copy node to item of loop node
     copy->setItem(loopx->getItem());

     //Node to hold pointer to new node
     Node<T>* newNode=new Node<T>;

     //increment copy and loop to their next nodes
     copy->setNext(newNode);
     loopx=loopx->getNext();
     copy=copy->getNext();
  }

  //copy size
  size=x.size;

  //return pointer to LinkedList object
  return *this;
}

//return true if empty
template <typename T>
bool LinkedList<T>::isEmpty() const
{
  // return true if size=0
  return !(size);
}

//returns length of list
template <typename T>
std::size_t LinkedList<T>::getLength() const
{
  return size;
}

//inserts an item into the list
template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  //error check position
  if (position<0 || position>size)
  {
    return false;
  }
  
  //check if list is empty
	if (isEmpty())
	{
		//Create new pointer to only node in the list
		headPtr=new Node<T>;
		headPtr->setItem(item);
		headPtr->setNext(NULL);

		//increment size
		size++;

		return true;
	}

  //list size of one
  if (size==1)
  {
    //node at position
    Node<T>* currentNode=headPtr;

    //New node
    Node<T>* newNode=new Node<T>;
    newNode->setItem(item);

    //check if node should be inserted before or after headPtr
    if (position==1)
    {
      headPtr->setNext(newNode);
      newNode->setNext(NULL);
      size++;
      return true;
    }

    else
    {
      newNode->setNext(headPtr);
      headPtr=newNode;
       size++;
       return true;
    }
  }

  //pointer to hold current node and previous node
  Node<T>* currentNode=headPtr;
  Node<T>* prevNode=currentNode;
  

  //loop to the node at position
	for (int i=0; i<position; i++)
	{
      //currentNode will point to element at position
      prevNode=currentNode;
      currentNode=currentNode->getNext();
	}

  //Check for position=0
  if (position==0)
  {
    Node<T>* newNode=headPtr;
    headPtr=new Node<T>;
    headPtr->setItem(item);
    headPtr->setNext(newNode);
    
    size++; 

    return true;
  }

  //Create a node to add to the list, set its item, and link it to nodes before and after
	Node<T>* newNode=new Node<T>;
	newNode->setItem(item); 
	prevNode->setNext(newNode);
  
  if(prevNode->getNext()!=NULL)
	  newNode->setNext(currentNode);

	//increment size
	size++;

  return true;
}

//removes an item at position from the list
template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  //check for invalid position
  if(position<0 || position>size-1) 
    return false;

  //Check if position is 0
  if(position==0)
  {
    headPtr=headPtr->getNext();
    size--;
    return true;
  }

  //Node pointer to hold current node
  Node<T>* currentNode=headPtr;

  //loop through until position
  for (int i=0; i<position-1; i++)
  {
    currentNode=currentNode->getNext();
  }

  //create pointer to hold previous node
  Node<T>* previousNode=currentNode;

  //get position pointer
  currentNode=currentNode->getNext();

  if (currentNode->getNext()==NULL)
  {
    //if the item at position is the last item, make the previousNode point to nothing/NULL
    previousNode->setNext(NULL);
  }
  else
  {
    //Remove Node by making previousNode point to the node after the position
    previousNode->setNext(currentNode->getNext());
  }

  //decrease size by 1
  size--;

  //Return True
  return true;
}

//clears the list
template <typename T>
void LinkedList<T>::clear()
{
  //set headPtr to null, set size to zero
  headPtr=NULL;
  size=0;
}

//returns the entry at position
template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  //node to hold current position
  Node<T>* currentNode=headPtr;
  
  // loop until node at position
  for (int i=0; i<position; i++)
  {
    currentNode=currentNode->getNext();
  }

  //return item
  return currentNode->getItem();
}

//sets the entry at position 
template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  //check for invalid position
  if(position<0 || position>size-1)
    return;
  
  //variable to hold currentNode for looping
  Node<T>* currentNode=headPtr;

  //loop through list until position is reached
  for(int i=1; i<position; i++)
  {
    currentNode=currentNode->getNext();
  }

  //set item at position
  currentNode->setItem(newValue);
}

//checks if an item is contained in the list
template <typename T>
bool LinkedList<T>::contains(const T& item)
{
  //test if empty
  if (isEmpty())
  {
    return false;
  }

  //test for size of one
  if (size==1)
  {
    if (headPtr->getItem()==item)
    {
      return true;
    }
    
    else
    {
      return false;
    }
  }
  
  //node to loop through list
  Node<T>* currentNode=headPtr;
  
  //loop through list, return true if item found, else false
  for (int i=0; i<=size-1; i++)
  {
    if (currentNode->getItem()==item)
    {
      return true;
    }

    //increment currentNode
    currentNode=currentNode->getNext();
  }

  //if this line is reached, return false
  return false;
}