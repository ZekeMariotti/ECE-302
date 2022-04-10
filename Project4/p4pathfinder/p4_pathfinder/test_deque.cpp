#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "deque.hpp"
#include <iostream>
using std::cout;
using std::endl;

TEST_CASE( "Deque Tests", "[deque]" ) {
    Deque<int> D1;

    //Test empty deque
    REQUIRE(D1.isEmpty());
    REQUIRE(D1.contains(5)==false);

    //Testing deque size of one
    D1.pushFront(0);
    REQUIRE(D1.contains(0));
    D1.popFront();

   //Push to deque [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    for (int i=1; i<=5; i++)
    {
    D1.pushBack(6-i);
    }

    for (int i=6; i<=10; i++)
    {
    D1.pushFront(i);
    }

    //test contains
    for (int i=1; i<=10; i++)
    {
        REQUIRE(D1.contains(i));
        REQUIRE(!D1.contains(0));
        REQUIRE(!D1.contains(11));
    }

    //test copy assignment and copy constructor
    Deque<int> D2=D1;
    Deque<int> D3;
    D3=D2;

    //pop items off using popBack and popFront, also tests back() and front()
    for (int i=1; i<=5; i++)
    {
        //D1
        REQUIRE(D1.back()==i);
        D1.popBack();

        //D2
        REQUIRE(D2.back()==i);
        D2.popBack();

        //D3
        REQUIRE(D3.back()==i);
        D3.popBack();
    }

    for (int i=10; i>=6; i--)
    {
        //D1
        REQUIRE(D1.front()==i);
        D1.popFront();

        //D2
        REQUIRE(D2.front()==i);
        D2.popFront();

        //D3
        REQUIRE(D3.front()==i);
        D3.popFront();
    }

    //Test that all three deques are now empty
    REQUIRE(D1.isEmpty());
    REQUIRE(D2.isEmpty());
    REQUIRE(D3.isEmpty());
}
