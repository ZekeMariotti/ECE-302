#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "dynamic_array_list.h"
#include "sorted_list.h"
#include "priority_queue.h"

TEST_CASE("Testing Priority Queue", "[priority queue]") {
  typedef SortedList<int, DynamicArrayList<int> > SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;

  // test insert
  REQUIRE(pq.isEmpty());
  pq.add(0);
  REQUIRE(pq.peek()==0);

  //add multiple numbers

  //-1
  pq.add(-1);
  REQUIRE(pq.peek()==0);

  //5
  pq.add(5);
  REQUIRE(pq.peek()==5);

  //4, 3
  pq.add(4);
  pq.add(3);
  REQUIRE(pq.peek()==5);

  //remove items, test that priority was preserved
  pq.remove();
  REQUIRE(pq.peek()==4);

  pq.remove();
  REQUIRE(pq.peek()==3);

  pq.remove();
  REQUIRE(pq.peek()==0);

  pq.remove();
  REQUIRE(pq.peek()==-1);

  pq.remove();
  REQUIRE(pq.isEmpty());
  
}
