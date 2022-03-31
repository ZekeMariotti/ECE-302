#include "deque.hpp"


// default constructor
template <typename T>
Deque<T>::Deque()
{
    //nothing to make default values for
}

// copy constructor
template <typename T>
Deque<T>::Deque(const Deque &x)
{

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

}

// isEmpty
template <typename T>
bool Deque<T>::isEmpty()
{
    return list.isEmpty();
}

// pushFront
template <typename T>
void Deque<T>::pushFront(const T &item)
{
    //insert item at end of list
    list.insert(list.getLength()-1, item);
}

// popFront
template <typename T>
void Deque<T>::popFront()
{

}

// front
template <typename T>
T Deque<T>::front()
{

}

// pushBack
template <typename T>
void Deque<T>::pushBack(const T &item)
{
    //insert item at beginning of list
    list.insert(0, item);
}

// popBack
template <typename T>
void Deque<T>::popBack()
{

}

// back
template <typename T>
T Deque<T>::back()
{
    
}
