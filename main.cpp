#include <iostream>
#include "data_structure.hpp"
#include <random>  // mt19937_64, random_device
#include <chrono>  // system_clock

using namespace std;

int main() {
  const auto seed = chrono::system_clock::now().time_since_epoch().count();
  auto engine = mt19937(seed);  // без seed`а генератор будет выдавать одни и те же значения

  auto *heap1 = new itis::BinomialHeap();
  for (int i = 0; i < 500000; ++i) {
    auto dist = uniform_int_distribution(0, 100);  // равновероятное распределение генерируемых чисел
    heap1->insert(dist(engine));
  }

  cout << heap1->deleteMinNode();
  cout << endl << "after delete" << endl<< endl;
  return 0;
}
