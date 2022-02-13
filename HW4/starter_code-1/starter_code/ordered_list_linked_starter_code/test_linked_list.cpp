#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

template class LinkedList<int>;

TEST_CASE( "Constructor and isEmpty Test", "[LinkedList]" ) {
    //create List object
    LinkedList<int> list1;
    LinkedList<int> list2=list1;

    //Require list1 is empty, (default constructor sets list1 to empty, where listStart is NULL)
    REQUIRE(list1.isEmpty());
}

TEST_CASE("length, getEntry, remove, clear, setEntry and insert test", "[LinkedList]"){
    //create List object
    LinkedList<int> list1;

    //Insert 10 items
    for (int i=1; i<=10; i++)
    {
        list1.insert(i, i);
    }

    REQUIRE(list1.getEntry(5)==5);

    //Require list1 has length 10
    REQUIRE(list1.getLength()==10);

    //Insert an item at position 5 
    list1.insert(5, 1);

    //Require that length increased to 11
    REQUIRE(list1.getLength()==11);

    //copy list1 to list 2
    LinkedList<int> list2;
    list2=list1;

    //require length of list2 to be same as list1
    REQUIRE(list2.getLength()==11);

    //Require each item in list2 to be the same as list1
    for (int i=1; i<list2.getLength(); i++)
    {
        REQUIRE(list2.getEntry(i)==list1.getEntry(i));
    }

    //Remove an item from list 2
    list2.remove(3);

    //Require that the item at position 3 is 4
    REQUIRE(list2.getEntry(3)==4);

    //Remove last item
    list2.remove(10);

    //Require last item to be 9
    REQUIRE(list2.getEntry(9)==9);

    //Remove first item
    list2.remove(1);

    //Require first item to be 2
    REQUIRE(list2.getEntry(1)==2);

    //Clear list2
    list2.clear();

    //Require list2 to be empty
    REQUIRE(list2.isEmpty());

    //Set entry at position 5 for list1
    list1.setEntry(5, 27);

    //Require that the 5th item is 27
    REQUIRE(list1.getEntry(5)==27);

    //Set entry at position 1
    list1.setEntry(1, 32);

    //Require 1st item is 32
    REQUIRE(list1.getEntry(1)==32);
}

TEST_CASE("something test", "[LinkedList]"){
    
}
