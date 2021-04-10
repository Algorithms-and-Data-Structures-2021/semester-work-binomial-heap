#include <iostream>
#include "data_structure.hpp"

using namespace std;

int main() {

  auto *node7 = new itis::Node(7, 16);
  auto *node8 = new itis::Node(8, 4);
  auto *heap1 = new itis::BinomialHeap(node7);
  auto *heap2 = new itis::BinomialHeap(node8);

  heap1->merge(heap2);

  return 0;
}