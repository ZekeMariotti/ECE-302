#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "abstract_deque.hpp"
#include "linked_list.hpp"

template <typename T>
class Deque: public AbstractDeque<T>{
public:
  
  // default constructor
  Deque();
  
  // copy constructor
  Deque(const Deque& x);
    
  // destructor
  ~Deque();
  
  // copy assignment
  Deque& operator=(const Deque& x);

  // isEmpty
  bool isEmpty();

  // pushFront
  void pushFront(const T& item);

  // popFront
  void popFront();

  // front
  T front();

  // pushBack
  void pushBack(const T& item);

  // popBack
  void popBack();

  // back
  T back();

private:
  LinkedList<T> list;
  
};

#include "deque.tpp"

#endif
