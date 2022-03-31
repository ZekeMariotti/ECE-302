#include "dynamic_array_list.h"

#include <algorithm>
#include <stdexcept>

#include <iostream>

<<<<<<< HEAD
template <typename T>
DynamicArrayList<T>::DynamicArrayList()
{
  //TODO
}
  
template <typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T>& x)
{
    //TODO
}
    
=======
// default constructor
template <typename T>
DynamicArrayList<T>::DynamicArrayList()
{
  //set default capacity and size, and create array
  capacity=50;
  data=new T[capacity];
  size=0;
}

// copy constructor with list argument  
template <typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T>& x)
{
  //copy data from list x
  capacity=x.capacity;
  size=x.size;
  data=new T[capacity];

  //copy items from list x
  for (int i=0; i<=x.size-1; i++)
  {
    *(data+i)=*(x.data+i);
  }
}

// destructor    
>>>>>>> 345c6e4970cfc67544852adc097d82be2dc74111
template <typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
  std::clog << "DynamicArrayList Destructor called." << std::endl;
<<<<<<< HEAD
  //TODO
}

template <typename T>
DynamicArrayList<T>& DynamicArrayList<T>::operator=(DynamicArrayList<T> x)
{
  //TODO
  return *this;
}

template <typename T>
void DynamicArrayList<T>::swap(DynamicArrayList<T>& y)
{
  //TODO
}

template <typename T>
bool DynamicArrayList<T>::isEmpty()
{
  //TODO
  return false;
}

template <typename T>
std::size_t DynamicArrayList<T>::getLength()
{
  //TODO
  return 0;
}

template <typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T& item)
{
  //TODO
}

template <typename T>
void DynamicArrayList<T>::remove(std::size_t position)
{
  //TODO
}

template <typename T>
void DynamicArrayList<T>::clear()
{
  //TODO
}

template <typename T>
T DynamicArrayList<T>::getEntry(std::size_t position)
{
  //TODO
  return T();
}

template <typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T& newValue)
{
  //TODO
=======
  //delete array 
  delete [] data;
}

// = operator 
template <typename T>
DynamicArrayList<T>& DynamicArrayList<T>::operator=(DynamicArrayList<T> x)
{
  // copy x to calling object
  data=new T[x.size];

  //copy items from list x
  for (int i=0; i<=x.size-1; i++)
  {
    *(data+i)=*(x.data+i);
  }

  //copy sizes
  capacity=x.capacity;
  size=x.size;


  return *this;
}

// swaps two lists
template <typename T>
void DynamicArrayList<T>::swap(DynamicArrayList<T>& y)
{
  //create new list to store y
  DynamicArrayList temp=y;
  y=*this;
  *this=y;
}

// checks if list is empty
template <typename T>
bool DynamicArrayList<T>::isEmpty()
{
  return !(size);
}

// returns length
template <typename T>
std::size_t DynamicArrayList<T>::getLength()
{
  return size;
}

// insert an item
template <typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T& item)
{
  // check position
  if (position<0)
    return;

  //shift all items
  for (int i=size; i>position; i--)
  {
    *(data+i)=*(data+i-1); 
  }

  //set item at position
  *(data+position)=item;

  //increase size
  size++;
}

// removes an item
template <typename T>
void DynamicArrayList<T>::remove(std::size_t position)
{
  //test if position is zero/negative
  if (position<0)
    return;

  //test size of one
  if (size==1)
  {
    clear();
    return;
  }

  
  //shift all items
  for (int i=position; i<=size-1; i++)
  {
    //shift data    
    *(data+i)=*(data+i+1); 
  }

   //decrease size
    size--;

  
}

// clears a list
template <typename T>
void DynamicArrayList<T>::clear()
{
  delete [] data;
  data=new T[capacity];
  capacity=0;
  size=0; 
}

// returns an entry
template <typename T>
T DynamicArrayList<T>::getEntry(std::size_t position)
{
  // return item
  return *(data+position);
}

// sets an entry
template <typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T& newValue)
{
  //set an item
  *(data+position)=newValue;
>>>>>>> 345c6e4970cfc67544852adc097d82be2dc74111
}
