#include "deque.hpp"
#include <iostream>
using std::cout;


// default constructor
template <typename T>
Deque<T>::Deque()
{
    //set size to 0
    size=0;
}

// copy constructor
template <typename T>
Deque<T>::Deque(const Deque &x)
{
    list=x.list;
    size=x.size;
}

// destructor
template <typename T>
Deque<T>::~Deque()
{
    //no memory allocation
}

// copy assignment
template <typename T>
Deque<T>& Deque<T>::operator=(const Deque &x)
{
    list=x.list;
    size=x.size;
    return *this;
}

// isEmpty
template <typename T>
bool Deque<T>::isEmpty() const noexcept
{
    return list.isEmpty();
}

// pushFront
template <typename T>
void Deque<T>::pushFront(const T &item)
{    
    //insert item at end of list
    list.insert(list.getLength(), item);
    size=list.getLength();
}

// popFront
template <typename T>
void Deque<T>::popFront()
{    
    //empty exception
    if (isEmpty())
        throw std::runtime_error("Deque is empty, cannot pop item");

    list.remove(list.getLength()-1);
    size=list.getLength();  
}

// front
template <typename T>
T Deque<T>::front() const
{
    //empty exception
    if (isEmpty())
        throw std::runtime_error("Deque is empty");

    return list.getEntry(list.getLength()-1);
}

// pushBack
template <typename T>
void Deque<T>::pushBack(const T &item)
{
    //insert item at beginning of list
    list.insert(0, item);
    size=list.getLength();
}

// popBack
template <typename T>
void Deque<T>::popBack()
{
    //empty exception
    if (isEmpty())
        throw std::runtime_error("Deque is empty, cannot pop item");
    
    list.remove(0);
    size=list.getLength();
}

// back
template <typename T>
T Deque<T>::back() const
{
    //empty exception
    if (isEmpty())
        throw std::runtime_error("Deque is empty");

    return list.getEntry(0);
}
