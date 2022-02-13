#include "linked_list.hpp"
#include <iostream>

// default constructor
template <typename T>
LinkedList<T>::LinkedList()
{
  //set both pointers to NULL
  listStart=NULL;
}

//destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
  if (listStart==NULL)
    return;
  //delete start pointer
  delete listStart;
}

//copy constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  //if x is empty, make calling object empty
  if (x.isEmpty())
  {
    listStart=NULL;
    return;
  }

  //create new pointers
  listStart=new Node<T>;

  //Create pointer to loop through list and to copy data
  Node<T>* loop=x.listStart;
  Node<T>* data=listStart;

  //Copy data by looping through list x
  while(loop->getNext()!=NULL)
  {
     //Set item of data node to item of loop node
     data->setItem(loop->getItem());

     //Node to hold pointer to new node
     Node<T>* newNode=new Node<T>;

     //increment data and loop to their next nodes
     data->setNext(newNode);
     loop=loop->getNext();
     data=data->getNext();
  }
}

// swap two lists
template <typename T>
void LinkedList<T>::swap(LinkedList<T>& x, LinkedList<T>& y)
{
  //Create new pointer to hold data 
  Node<T>* newStart=x.listStart;

  //switch start pointers 
  x.listStart=y.listStart;
  
  //Switch y pointers to new pointers
  y.listStart=newStart;
}

//copy assignment
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{ 
  //create new pointers
  listStart=new Node<T>;

  //Create pointer to loop through list and to copy data
  Node<T>* loop=x.listStart;
  Node<T>* data=listStart;

  //Copy data by looping through list x
  while(loop->getNext()!=NULL)
  {
     //Set item of data node to item of loop node
     data->setItem(loop->getItem());

     //Node to hold pointer to new node
     Node<T>* newNode=new Node<T>;

     //increment data and loop to their next nodes
     data->setNext(newNode);
     loop=loop->getNext();
     data=data->getNext();
  }

  //return pointer to LinkedList object
  return *this;
}

//determine if a list is empty
template <typename T>
bool LinkedList<T>::isEmpty() const
{
  // return true if the beginning of the list is NULL
  if(listStart==NULL)
    return true;

  return false;
}

//return length of a list
template <typename T>
std::size_t LinkedList<T>::getLength() const
{
  //check if list is empty
  if(isEmpty())
    return 0;

  //variable to count length
  int length=1;

  //Pointer to hold node address
  Node<T>* currentNode=listStart;

  //Loop through list increasing length each time
  while(currentNode->getNext()!=NULL)
  {
    length++;
    currentNode=currentNode->getNext();
  }

  //Return length variable
  return length;
}

//insert item at position in the list using 1-based indexing
template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  //check position value
  if(position<=0)
    return false;

  //Check if position is 1
  if (position==1)
  {
    //Insert node/item at position one
    Node<T>* oldStart=listStart; 
    listStart=new Node<T>;
    listStart->setItem(item);
    
    //check for null
    if(oldStart!=NULL)
    {
       listStart->setNext(oldStart);
    }
    
    return true;
  }
  
  //create node pointer to store current node address
  Node<T>* currentNode=listStart;

  //Create count variable to hold value to be indexed
  int index=1;

  //loop until index is reached
  while(index<position-1)
  {
    currentNode=currentNode->getNext();
    index++;

  //If position is larger than size of list
    if(currentNode==NULL)
      return false;
  }

  //hold node before position
  Node<T>* beforeNode=currentNode;

  //hold node after position
  Node<T>* afterNode=currentNode->getNext();

  //set next node
  currentNode=new Node<T>;

  //Set item
  currentNode->setItem(item); 

  //Connect Nodes
  beforeNode->setNext(currentNode);

  //check if afternode exists/==NULL
  if(afterNode!=NULL)
    currentNode->setNext(afterNode);

  return true;
}

// remove item at position in the list using 1-based indexing
template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  //TODO
  return true;
}

// remove all items from the list
template <typename T>
void LinkedList<T>::clear()
{
  //TODO
}

// get a copy of the item at position using 1-based indexing
template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  //variable to hold item
  T item;
  
  //variable to hold node pointer
  Node<T>* currentNode=listStart;

  //loop until position
  for (int i=1; i<position; i++)
    currentNode=currentNode->getNext();

  //set item
  item=currentNode->getItem();
  
  //return item
  return item;
}

// set the value of the item at position using 1-based indexing
template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  //TODO
}
