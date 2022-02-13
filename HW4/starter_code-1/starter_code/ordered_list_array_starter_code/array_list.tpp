#include "array_list.hpp"
#include <iostream>

// default constructor
template <typename T>
ArrayList<T>::ArrayList() {
  //allocate memory for listPtr
  listPtr=new T[listSize];
}

// destructor
template <typename T>
ArrayList<T>::~ArrayList() {
  delete [] listPtr;
}

// copy constructor
template <typename T>
ArrayList<T>::ArrayList(const ArrayList & rhs){
  //allocate memory for listPtr of same size as rhs
  listPtr=new T[rhs.listSize];

  //copy data
  for (int i=0; i<=rhs.count-1; i++)
  {
    *(listPtr+i)=*(rhs.listPtr+i);
  }

  //set count and list size
  count=rhs.count;
  listSize=rhs.listSize;
}

// copy assignment
template <typename T>
ArrayList<T> & ArrayList<T>::operator=(const ArrayList & rhs){
  //delete old listPtr
  delete [] listPtr;
  
  //allocate memory for listPtr of same size as rhs
  listPtr=new T[rhs.listSize];

  //copy data
  for (int i=0; i<=rhs.count; i++)
  {
    *(listPtr+i)=*(rhs.listPtr+i);
  }

  //set count and list size
  count=rhs.count;
  listSize=rhs.listSize;

  //return calling object ptr
  return *this;
}

// determine if a list is empty
template <typename T>
bool ArrayList<T>::isEmpty() const{
  //check if count is zero
  if (count==0)
    return true;
  
  //return false if count isn't zero
  return false;
}

// return current length of the list
template <typename T>
std::size_t ArrayList<T>::getLength() const{
  //Return count
  return count;
}

// insert item at position in the list using 1-based indexing
template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
  //check if position zero/negative
  if (position<=0)
    return false;

  //check if position is too large
  if (position>count)
    listResize();
  
  //shift all items
  for (int i=count; i>position-1; i--)
  {
    *(listPtr+i)=*(listPtr+i-1); 
  }

  //set item at position
  *(listPtr+position-1)=item;

  //increase count
  count++;
  
  return true;
}

// remove item at position in the list using 1-based indexing
template <typename T>
bool ArrayList<T>::remove(std::size_t position){  
  //test if position is zero/negative
  if (position<=0)
    return false;

  //shift all items
  for (int i=position-1; i<=count-1; i++)
  {
    *(listPtr+i)=*(listPtr+i+1);
  }

  //decrease count
  count--;

  return true;
}

// remove all items from the list
template <typename T>
void ArrayList<T>::clear() {
  //clear all items by setting count to 0
  count=0;
}

// get a copy of the item at position using 1-based indexing
template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
  //return item at position
  return *(listPtr+position-1); 
}

// set the value of the item at position using 1-based indexing
template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {
  //set item
  *(listPtr+position-1)=newValue;
}
