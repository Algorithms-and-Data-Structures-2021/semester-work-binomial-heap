#include <iostream>
#include "data_structure.hpp"

using namespace std;

int main() {

  //  auto *node7 = new itis::Node(7, 16);
  //  auto *node8 = new itis::Node(8, 4);
  auto *heap1 = new itis::BinomialHeap();
  heap1->createSampleHeap2();

  auto *heap2 = new itis::BinomialHeap();
  heap2->createSampleHeap3();
  //  heap1->merge(heap2);
  //  heap1->printHeap();
  //  itis::BinomialHeap *heap1;
  //  itis::BinomialHeap *heap2;
//  heap1->reverse();
//  heap1->printHeap();
//  heap1->deleteMin();
  heap1->printHeap();
  return 0;
}