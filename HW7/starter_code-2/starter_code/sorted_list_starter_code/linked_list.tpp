#include "linked_list.hpp"

template <typename T>
<<<<<<< HEAD
LinkedList<T>::LinkedList()
{
  //TODO
}
=======
LinkedList<T>::LinkedList() : headPtr(nullptr), itemCount(0)
{
  
} //end default constructor 
>>>>>>> 345c6e4970cfc67544852adc097d82be2dc74111

template <typename T>
LinkedList<T>::~LinkedList()
{
<<<<<<< HEAD
  //TODO
}
=======
  //empty the existing linked list
  clear();
} // end destructor
>>>>>>> 345c6e4970cfc67544852adc097d82be2dc74111

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
<<<<<<< HEAD
  //TODO
}

template <typename T>
void LinkedList<T>::swap(LinkedList<T>& x, LinkedList<T>& y)
{
  //TODO
}
=======
  itemCount = x.itemCount;
  Node<T>* origPtr = x.headPtr;
  //check if original is empty, if so make copy empty
  if (origPtr == nullptr) 
    headPtr = nullptr;
  else {
      //make copy of first node
      headPtr = new Node<T>();
      headPtr -> setItem(origPtr -> getItem());
      //copy remaining nodes
      Node<T>* newPtr = headPtr; 
      origPtr = origPtr -> getNext();
      while (origPtr != nullptr) {
            //get next item in list, and make new node with item, and link
            T nextItem = origPtr -> getItem();
            Node<T>* newNodePtr = new Node<T>(nextItem);
            newPtr -> setNext(newNodePtr);
            //shift pointers
            newPtr = newPtr -> getNext();
            origPtr = origPtr -> getNext();
          } // end while
    } // end if
} // end copy
 
template <typename T>
void LinkedList<T>::swap(LinkedList<T>& x, LinkedList<T>& y)
{
  LinkedList<T> temp(x);
  x = y;
  y = temp;
} 
>>>>>>> 345c6e4970cfc67544852adc097d82be2dc74111

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
<<<<<<< HEAD
  //TODO
  return *this;
=======
    itemCount = x.itemCount;
      Node<T>* origPtr = x.headPtr;
        //check if original is empty, if so make copy empty
        if (origPtr == nullptr) 
              headPtr = nullptr;
          else {
              //make copy of first node
              headPtr = new Node<T>();
              headPtr -> setItem(origPtr -> getItem());
              //copy remaining nodes
              Node<T>* newPtr = headPtr; 
              origPtr = origPtr -> getNext();
              while (origPtr != nullptr) {
                    //get next item in list, and make new node with item, and link
                    T nextItem = origPtr -> getItem();
                    Node<T>* newNodePtr = new Node<T>(nextItem);
                    newPtr -> setNext(newNodePtr);
                    //shift pointers
                    newPtr = newPtr -> getNext();
                    origPtr = origPtr -> getNext();
                  } // end while
            } // end if
            return *this;
>>>>>>> 345c6e4970cfc67544852adc097d82be2dc74111
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
<<<<<<< HEAD
  //TODO
  return true;
=======
   return (itemCount == 0);
>>>>>>> 345c6e4970cfc67544852adc097d82be2dc74111
}

template <typename T>
std::size_t LinkedList<T>::getLength() const
{
<<<<<<< HEAD
  //TODO
  return 0;
=======
  return itemCount;
>>>>>>> 345c6e4970cfc67544852adc097d82be2dc74111
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
<<<<<<< HEAD
  //TODO
  return true;
=======
  bool canInsert = (position >= 1) && (position <= itemCount +1);
    Node<T>* prevPtr = getNodeAt(position - 1);
      
      bool isValid;
        if (position+1 <= itemCount) {
          Node<T>* postPtr = getNodeAt(position + 1);
            if (position-1 >= 1 ) {
                  isValid = (prevPtr -> getItem() < item) && (postPtr -> getItem() > item); } 
            else { 
                  isValid = (postPtr -> getItem()) > item; 
                } // end if
          } // end if
          else { isValid = true; }
           
            if (canInsert) {
              //new node with entry
                Node<T>* newNodePtr = new Node<T>(item);
              //Link new node to list
                if (position == 1) {
                      //put node at beginning of the chain is position is 1
                      newNodePtr -> setNext(headPtr);
                      headPtr = newNodePtr;
                    }
                else {
                      //put node after the node at position - 1
                      newNodePtr -> setNext( prevPtr -> getNext() );
                      prevPtr -> setNext( newNodePtr );
                    } //end if
              //increment count
                itemCount++;
              } 
              else {
                  throw(std::range_error("error in range"));
                } //end if
                return canInsert; 
>>>>>>> 345c6e4970cfc67544852adc097d82be2dc74111
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
<<<<<<< HEAD
  //TODO
  return true;
=======
  bool canRemove = (position >= 1) && (position <= itemCount);
    if (canRemove) {
      Node<T>* curPtr = nullptr;
      if (position == 1) {
          //Remove first node
            curPtr = headPtr;
            headPtr = headPtr -> getNext();
        }
      else {
          //get node in position before one to be removed
            Node<T>* prevPtr = getNodeAt(position - 1);
          //point to node being removed
            curPtr = prevPtr -> getNext();
          //connect node before the one being removed to the position after it, unlinking the node to be removed
            prevPtr -> setNext( curPtr -> getNext() );
        } // end if
      //set current pointer back to null
        curPtr -> setNext(nullptr);
        delete curPtr;
        curPtr = nullptr;
      //deincrement count
        itemCount--;
      } 
      else {
        throw(std::range_error("error in range"));
        } // end if
        return canRemove; 
>>>>>>> 345c6e4970cfc67544852adc097d82be2dc74111
}

template <typename T>
void LinkedList<T>::clear()
{
<<<<<<< HEAD
  //TODO
=======
  while (!isEmpty())
      //remove the first entry until isEmpty() returns true
      remove(1); 
>>>>>>> 345c6e4970cfc67544852adc097d82be2dc74111
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
<<<<<<< HEAD
  //TODO
  return T();
=======
  //preconditions
    bool canGet = (position >= 1) && (position <= itemCount);
      if (canGet) {
        Node<T>* nodePtr = getNodeAt(position);
        return nodePtr -> getItem();
        }
        else {
            throw(std::range_error("error in range"));
          } // end if
           
>>>>>>> 345c6e4970cfc67544852adc097d82be2dc74111
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
<<<<<<< HEAD
  //TODO
}
=======
  bool canSet = (position >= 1) && (position <= itemCount +1);
    Node<T>* prevPtr = getNodeAt(position - 1);
      
      bool isValid;
        if (position+1 <= itemCount) {
          Node<T>* postPtr = getNodeAt(position + 1);
            if (position-1 >= 1 ) {
                  isValid = (prevPtr -> getItem() < newValue) && (postPtr -> getItem() > newValue); } 
            else { 
                  isValid = (postPtr -> getItem()) > newValue; 
                } // end if
          } // end if
          else { isValid = true; }
           
            
            if (canSet) {
              while ( itemCount >= position) {
                  remove(position); }
              insert(position, newValue);
              
              }  // end if
              else { throw(std::range_error("error in range")); } 
}
template <typename T>
Node<T>* LinkedList<T>::getNodeAt(int position) const
{
  // precondition: make sure function only preforms if condition is met (should always be met
      //because getNodeAt() is private function)
    //assert((position >= 1) && (position <= itemCount));
  //count through from beginning of list to position
    Node<T>* curPtr = headPtr;
    for (std::size_t next = 1; next < position; next++)
      curPtr = curPtr -> getNext();
    return curPtr;
} //end getNodeAt
>>>>>>> 345c6e4970cfc67544852adc097d82be2dc74111
