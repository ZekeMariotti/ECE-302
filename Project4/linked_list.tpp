#include "linked_list.hpp"

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
  //TODO
}

//swaps two lists
template <typename T>
void LinkedList<T>::swap(LinkedList<T>& x, LinkedList<T>& y)
{
  //TODO
}

//copy assignment
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
  //TODO
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
    return false;
  
  //check if list is empty
	if (isEmpty())
	{
		//Create new pointer to only node in the list
		Node<T>* currentNode=new Node<T>;
		headPtr=currentNode;
		headPtr->setItem(item);
		headPtr->setNext(NULL);

		//increment size
		size++;

		return true;
	}

  //pointer to hold current node and previous node
  Node<T>* currentNode=headPtr;
  Node<T>* prevNode=currentNode;

  //loop to the node at position
	for (int i=0; i<position; i++)
	{
		if (position!=0)
    {
      //currentNode will point to final element
      prevNode=currentNode;
      currentNode=currentNode->getNext();
    }
	}

  //Check for position=0
  if (position=0)
  {
    Node<T>* newNode=new Node<T>;
    newNode->setItem(item);
    newNode->setNext(currentNode);
    headPtr=newNode;
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
  //TODO
  return true;
}

//clears the list
template <typename T>
void LinkedList<T>::clear()
{
  //TODO
}

//returns the entry at position
template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  //node to hold current position
  Node<T>* currentNode=headPtr;
  
  // loop until node
  for (int i=0; i<=position-1; i++)
  {
    currentNode=currentNode->getNext();
  }

  return currentNode;
}

//sets the entry at position 
template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  //TODO
}
