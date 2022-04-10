
#ifndef _HEAP_PRIORITY_QUEUE_H_
#define _HEAP_PRIORITY_QUEUE_H_

#include "abstract_priority_queue.h"
#include "dynamic_array_list.h"
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class HeapPriorityQueue: public AbstractPriorityQueue<T>
{
public:
    
    // return true if the priority queue is empty
    bool isEmpty();
    
    // insert item into the queue
    void add(const T& item);
    
    // remove highest priority item from the queue
    void remove();
    
    // get the item with the highest priority from the queue
    T peek();
    
private:
    
    DynamicArrayList<T> lst;
};

template <typename T>
bool HeapPriorityQueue<T>::isEmpty()
{
    //return true if empty

    return lst.isEmpty();;
}

template <typename T>
void HeapPriorityQueue<T>::add(const T& item)
{
    //check if empty
    if (isEmpty())
    {
        lst.insert(0, item);
        return;
    }

    // adds item based on its priority 
    int position=0; 

    //find correct position by looping through list
    for (int i=0; i<=lst.getLength()-1; i++)
    {
        if (item>lst.getEntry(position))
        {
            position++;
        }
    }

   
    //insert item
    lst.insert(position, item);
}

template <typename T>
void HeapPriorityQueue<T>::remove()
{
    //remove highest priority item from heap
    lst.remove(lst.getLength()-1);
}

template <typename T>
T HeapPriorityQueue<T>::peek()
{
    //return item with highest priority
    T item=lst.getEntry(lst.getLength()-1);

    return item;
}


#endif // _HEAP_PRIORITY_QUEUE_H_
