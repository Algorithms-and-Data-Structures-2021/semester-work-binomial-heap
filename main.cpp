#include <iostream>
#include "data_structure.hpp"


using namespace std;

int main() {

  auto *node7 = new itis::Node(nullptr, 7,38);
  auto *node8 = new itis::Node(nullptr, 7,33);
  auto *heap1 = new itis::BinomialHeap(node7);

  auto *heap2 = new itis::BinomialHeap(node8);


  heap1->merge(heap2);
  cout << heap1;
  heap1->printHeap();
  cout << "adff" << std::endl;
  return 0;
}