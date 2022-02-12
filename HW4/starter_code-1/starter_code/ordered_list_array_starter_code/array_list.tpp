#include "array_list.hpp"

// default constructor
template <typename T>
ArrayList<T>::ArrayList() {}

// destructor
template <typename T>
ArrayList<T>::~ArrayList() {}

// copy constructor
template <typename T>
ArrayList<T>::ArrayList(const ArrayList & rhs){}

// copy assignment
template <typename T>
ArrayList<T> & ArrayList<T>::operator=(const ArrayList & rhs){
  return *this;
}

// determine if a list is empty
template <typename T>
bool ArrayList<T>::isEmpty() const{
  return false;
}

// return current length of the list
template <typename T>
std::size_t ArrayList<T>::getLength() const{
  return 0;
}

// insert item at position in the list using 1-based indexing
template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
  return false;
}

// remove item at position in the list using 1-based indexing
template <typename T>
bool ArrayList<T>::remove(std::size_t position){
  return false;
}

// remove all items from the list
template <typename T>
void ArrayList<T>::clear() {}

// get a copy of the item at position using 1-based indexing
template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
  return T();
}

// set the value of the item at position using 1-based indexing
template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {}
