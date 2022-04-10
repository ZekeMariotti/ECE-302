#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "abstract_deque.hpp"
#include "linked_list.hpp"
#include <stdexcept>

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
  bool isEmpty() const noexcept;

  // pushFront
  void pushFront(const T& item);

  // popFront
  void popFront();

  // front
  T front() const;

  // pushBack
  void pushBack(const T& item);

  // popBack
  void popBack();

  // back
  T back() const;

  // contains
  bool contains(const T& item);

private:
  LinkedList<T> list;
  int size;
  
};

#include "deque.tpp"

#endif
