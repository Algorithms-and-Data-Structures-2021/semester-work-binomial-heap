#include <iostream>
#include "data_structure.hpp"
using namespace std;

int main() {
  auto *node7 = new itis::Node(7, 16);
  auto *node8 = new itis::Node(8, 4);
  auto *heap1 = new itis::BinomialHeap();
  //  heap1->createSampleHeap2();

  //  auto *heap2 = new itis::BinomialHeap();
  //  heap2->createSampleHeap3();
  //  heap1->merge(heap2);
  //  heap1->printHeap();
  //  itis::BinomialHeap *heap1;
  //  itis::BinomialHeap *heap2;
  //  heap1->printHeap();
  //  heap1->insert(5);
  //  heap1->insert(6);
  //  heap1->insert(7);
  //  heap1->insert(8);
  //  heap1->insert(9);
  //  heap1->insert(10);
  //  heap1->insert(2);
  //  heap1->insert(1);
  //  heap1->insert(3);
  //  heap1->insert(5);
  for (int i = 0; i < 100; ++i) {
    heap1->insert(rand());
  }
  heap1->printHeap();
  //  delete heap1;
  return 0;
}