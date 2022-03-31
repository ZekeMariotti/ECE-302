#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "abstract_deque.hpp"
#include "linked_list.hpp"

template <typename T>
class Deque: public AbstractDeque<T>{

  // TODO
  LinkedList<T> a;
  
};

#include "deque.tpp"

#endif
