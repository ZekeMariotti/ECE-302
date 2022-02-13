#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

TEST_CASE( "constructor, copy constructor, destructor, and copy assignment Test", "[ArrayList]" ) {

  ArrayList<int> list1;
  ArrayList<int> list2=list1;
  ArrayList<int> list3;
  list3=list2;

  //Require objects created and functions called with no errors
  REQUIRE(true):
}

TEST_CASE(" test", "ArrayList]" ) {
  
}
