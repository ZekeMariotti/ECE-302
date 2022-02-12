#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

template class LinkedList<int>;

TEST_CASE( "isEmpty Test", "[LinkedList]" ) {
    LinkedList<int> list1;
    LinkedList<int> list2=list1;

    //Require list1 is empty, (default constructor sets list1 to empty, where listStart is NULL)
    REQUIRE(list1.isEmpty());
}

TEST_CASE("length test", "[LinkedList]"){

}

TEST_CASE("something test", "[LinkedList]"){
    
}
