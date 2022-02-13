#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#include "abstract_list.hpp"

template<typename T>
class ArrayList: public AbstractList<T>
{
public:

  // default constructor
  ArrayList();

  // destructor
  ~ArrayList();

  // copy constructor
  ArrayList(const ArrayList & rhs);

  // copy assignment
  ArrayList & operator=(const ArrayList & rhs);
  
  // determine if a list is empty
  bool isEmpty() const;

  // return current length of the list
  std::size_t getLength() const;
  
  // insert item at position in the list using 1-based indexing
  bool insert(std::size_t position, const T& item);

  // remove item at position in the list using 1-based indexing
  bool remove(std::size_t position);

  // remove all items from the list
  void clear();

  // get a copy of the item at position using 1-based indexing
  T getEntry(std::size_t position) const;

  // set the value of the item at position using 1-based indexing
  void setEntry(std::size_t position, const T& newValue);

private:

  // create ptr to list array
  T* listPtr;

  // variable to hold size
  int listSize=10;

  // variable to hold count position
  int count=0;

  // member function used to resize a list
  void listResize(void){
    //create new ptr to hold old list
    T* newListPtr = new T[2*listSize];

    //copy data
    for (int i=0; i<=count-1; i++)
    {
      *(newListPtr+i)=*(listPtr+i);
    }

    //delete old pointer
    delete [] listPtr;

    //reallocate memory
    listPtr=new T[2*listSize];

    //copy data back into listPtr
    for (int i=0; i<=count-1; i++)
    {
      *(listPtr+i)=*(newListPtr+i);
    }

    // change listSize to match new size
    listSize=listSize*2;
  }
  
};

#include "array_list.tpp"

#endif
