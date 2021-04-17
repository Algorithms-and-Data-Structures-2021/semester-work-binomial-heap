#include <iostream>
#include "data_structure.hpp"
#include <random>  // mt19937_64, random_device
#include <chrono>  // system_clock

using namespace std;

int main() {
  const auto seed = chrono::system_clock::now().time_since_epoch().count();
  auto engine = mt19937(seed);  // без seed`а генератор будет выдавать одни и те же значения

  //  auto *node7 = new itis::Node(7, 16);
  //  auto *node8 = new itis::Node(8, 4);

  auto *heap1 = new itis::BinomialHeap();
  for (int i = 0; i < 100; ++i) {
    auto dist = uniform_int_distribution(0, 100);  // равновероятное распределение генерируемых чисел
    heap1->insert(dist(engine));
  }
  heap1->printHeap();
  heap1->~BinomialHeap();
}