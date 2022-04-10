#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "heap_priority_queue.h"

TEST_CASE("Test Construction", "[construction]") {
  HeapPriorityQueue<int>  pq;
  REQUIRE(pq.isEmpty());
}

TEST_CASE("Test add", "[add]") {
  HeapPriorityQueue<int>  pq;
  pq.add(25);

  REQUIRE(!pq.isEmpty());
  REQUIRE(pq.peek() == 25);

  pq.add(1);
  REQUIRE(pq.peek() == 25);

  pq.add(78);
  REQUIRE(pq.peek() == 78);
}

TEST_CASE("Test remove", "[remove]") {
  HeapPriorityQueue<int>  pq;
  pq.add(25);
  pq.add(1);
  pq.add(78);

  pq.remove();
  REQUIRE(pq.peek() == 25);
  pq.remove();
  REQUIRE(pq.peek() == 1);
  pq.remove();
  REQUIRE(pq.isEmpty());
}

TEST_CASE("Test All Methods", "[remove]") {
  HeapPriorityQueue<int>  pq;

  REQUIRE(pq.isEmpty());

  for (int i=0; i<=10; i++)
  {
    pq.add(i);
  }

  for (int i=10; i>=0; i--)
  {
    REQUIRE(pq.peek()==i);
    pq.remove();
  }

  REQUIRE(pq.isEmpty());
}