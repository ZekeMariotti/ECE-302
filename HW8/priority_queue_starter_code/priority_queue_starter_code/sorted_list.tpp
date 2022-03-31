#include "sorted_list.h"

template <typename T, typename L>
SortedList<T, L>::SortedList()
{
  // nothing to do, plist gets created on the stack
}

template <typename T, typename L>
SortedList<T, L>::SortedList(const SortedList<T, L> & x)
{
  plist = x.plist; // use copy assignment to implement copy construction
}

template <typename T, typename L>
SortedList<T, L>& SortedList<T, L>::operator=(const SortedList<T, L>& x)
{
  plist = x.plist;
  return *this;
}

template <typename T, typename L>
SortedList<T, L>::~SortedList()
{
  // plist destructor gets called automatically
}

template <typename T, typename L>
bool SortedList<T, L>::isEmpty()
{
  return plist.isEmpty();
}

template <typename T, typename L>
std::size_t SortedList<T, L>::getLength()
{
  return plist.getLength();
}

//Insert an item of type T
//Higher priority items (higher T value) goes to the end of the list (with length N, N-1 is front of queue)
template <typename T, typename L>
void SortedList<T, L>::insert(const T& item)
{
  //check if list is empty
  if (isEmpty())
  {
    plist.insert(0, item);
    return;
  }
  
  //check proper spot with priority 
  int i=0; //holds index in the list
  int spot=0; //used to hold position of the item
  bool found=0; //used to exit loop if position found

  while (i<=plist.getLength()-1 && !found)
  {
    if (item>getEntry(i))
    {
      spot++; //increase position of item if its higher than the entry at i
    }

    else
    {
      found=1; //if item <= entry at i, it has same or less priority
    }
    
    i++; //increment i
  }

  //insert item at spot found from looping
  plist.insert(spot, item);
}

//removes item from the list 
template <typename T, typename L>
void SortedList<T, L>::remove(const T& item)
{
  //i used to index list, found used if item is in list
  int i=0; 
  bool found=0;

  // check if item is in list
  while (i<=plist.getLength()-1 && !found)
  {
    if (item==getEntry(i))
    {
      plist.remove(i);
      found=true;
    }
    i++; //increase index
  }
}

template <typename T, typename L>
void SortedList<T, L>::removeAt(std::size_t position)
{
  plist.remove(position);
}

template <typename T, typename L>
void SortedList<T, L>::clear()
{
  plist.clear();
}

template <typename T, typename L>
T SortedList<T, L>::getEntry(std::size_t position)
{
  return plist.getEntry(position);
}

template <typename T, typename L>
long int SortedList<T, L>::getPosition(const T& newValue)
{
  // get position of an item in the list
  //int i to hold index, found to check if item is in list
  int i=0;
  bool found=0;

  // check if item is in list
  while (i<=plist.getLength()-1 && !found)
  {
    if (newValue==getEntry(i))
    {
      plist.remove(i);
      found=true;
    }
    i++; //increase index
  }

  //if item not found, return position of -1
  if(found=false)
  {
    return -1;
  }

  //return index i if found
  return i;
}
