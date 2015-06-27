#include "linkedList.h"
/*
http://cslibrary.stanford.edu/103/LinkedListBasics.pdf
*/

void testAll( void ) {
  PushTest();
  CountTest();
  GetNthTest();
  DeleteListTest();
  PopTest();
  InsertNthTest();
  SortedInsertTest();
  InsertSortTest();
  AppendTest();
  FrontBackSplitTest();
  RemoveDuplicatesTest();
  MoveNodeTest();
  AlternatingSplitTest();
  // ShuffleMergeTest();
  // SortedMergeTest();
  // MergeSortTest();
  SortedIntersectTest();
  ReverseTest();
  RecursiveReverseTest();
}
int main( void ) {
  testAll();
}
