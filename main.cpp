#include <iostream>
#include "data_structure.hpp"

using namespace std;

int main() {

//  auto *node7 = new itis::Node(7, 16);
//  auto *node8 = new itis::Node(8, 4);

  auto *heap1 = new itis::BinomialHeap();
  for (int i = 0; i < 100; ++i) {
    heap1->insert(5);
  }
  heap1->printHeap();
  heap1->~BinomialHeap();
}