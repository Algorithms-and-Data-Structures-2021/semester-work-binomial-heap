#include <iostream>
#include "data_structure.hpp"


int main() {

    auto *node7 = new itis::Node(7, 16);
   auto *node8 = new itis::Node(8, 4);
  auto *heap1 = new itis::BinomialHeap();
  heap1->createSampleHeap3();

//  auto *heap2 = new itis::BinomialHeap();
//  heap2->createSampleHeap3();
  //  heap1->merge(heap2);
  //  heap1->printHeap();
  //  itis::BinomialHeap *heap1;
  //  itis::BinomialHeap *heap2;
  //  heap1->printHeap();
  heap1->deleteMin();
  heap1->printHeap();
  return 0;
}