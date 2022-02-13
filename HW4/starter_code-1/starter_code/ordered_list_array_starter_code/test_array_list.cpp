#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

TEST_CASE( "constructor, copy constructor, destructor, and copy assignment Test", "[ArrayList]" ) {
  //Create list objects, call copy constructor and copy assignment
  ArrayList<int> list1;
  ArrayList<int> list2=list1;
  ArrayList<int> list3;
  list3=list2;

  //Require objects created and functions called with no errors
  REQUIRE(true);
}

TEST_CASE( "isEmpty, getLength, getEntry, insert, clear, remove, and setEntry Test", "ArrayList]" ) {
  //create list object
  ArrayList<int> list1;

  //Require default list1 is empty
  REQUIRE(list1.isEmpty()==true);

  //add 5 items to list1
  for(int i=1; i<=10; i++)
  {
    list1.insert(i, i);
  }

  //test that the array size is correct
  REQUIRE(list1.getLength()==10);

  //test that each item in list1 is correct
  for (int i=1; i<=10; i++)
  {
    REQUIRE(list1.getEntry(i)==i);
  }

  //Add an item in the 3rd slot, forcing the list length to 11
  list1.insert(3, 28);

  //Require list size to be 11
  REQUIRE(list1.getLength()==11);

  //Require item at position 3 to be 28
  REQUIRE(list1.getEntry(3)==28);

  //create list 2
  ArrayList<int> list2;

  //add 10 values to list2
  for (int i=1; i<=10; i++)
  {
    list2.insert(i, i);
  }

  //Remove the 7th item from list2
  list2.remove(7);

  //Require the 7th item to be 8
  REQUIRE(list2.getEntry(7)==8);

  //Require list1 length to be 9
  REQUIRE(list2.getLength()==9);

  //set first entry of list2 to be 117
  list2.setEntry(1, 117);

  //Require first item of list2 to be 117
  REQUIRE(list2.getEntry(1)==117);

  //clear list and require isEmpty to be true
  list2.clear();
  REQUIRE(list2.isEmpty()==true);
}
