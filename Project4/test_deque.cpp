#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "deque.hpp"
#include <iostream>
using std::cout;
using std::endl;

//template class Deque<int>;

TEST_CASE( "Deque Tests", "[deque]" ) {
    Deque<int> D1;

    REQUIRE(D1.isEmpty());

   //Push to deque [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    for (int i=1; i<=5; i++)
    {
    D1.pushBack(6-i);
    }

    for (int i=6; i<=10; i++)
    {
    D1.pushFront(i);
    }

    for (int i=1; i<=5; i++)
    {
        REQUIRE(D1.back()==i);
        D1.popBack();
    }

    for (int i=10; i<=6; i--)
    {
        REQUIRE(D1.front()==i);
        D1.popFront();
    }
}
