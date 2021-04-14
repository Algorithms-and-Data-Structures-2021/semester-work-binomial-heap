#include <iostream>
#include "data_structure.hpp"
#include <ctime>
#include <chrono>
#include <fstream>
#include "iostream"
#include <string>
#include <algorithm>
#include <sstream>
#include "vector"
using namespace std;
vector<int> split(const string& s, char delimiter) {
  vector<int> tokens;
  string token;
  istringstream tokenStream(s);
  while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(stoi(token));
  }
  return tokens;
}
int main() {
  auto *node7 = new itis::Node(7, 16);
  auto *node8 = new itis::Node(8, 4);
  //  heap1->createSampleHeap2();
  auto *heap2 = new itis::BinomialHeap();
  string path = "C:\\Users\\111\\CLionProjects\\semester-work-binomial-heap123123\\dataset\\data\\insert\\01.csv";
  ifstream fin;
  fin.open(path);

  string line;
  vector<int> intValues;
  if (!fin.is_open()) {
    cout << "Error" << endl;

  } else {

    while (getline(fin, line)) {

      intValues = split(line, ',');
    }
  }

  auto *heap1 = new itis::BinomialHeap();
  vector<itis::Node> NodeValues;
  const auto time_point_before = std::chrono::steady_clock::now();
  for (int i=0; i < intValues.size()-1; i++) {
    heap1->insert(intValues[i]);
  }

  const auto time_point_after = std::chrono::steady_clock::now();

  const auto time_diff = time_point_after - time_point_before;
  const long time_elapsed_mks = chrono::duration_cast<chrono::microseconds>(time_diff).count();

  cout << "Time elapsed (ns): " << time_elapsed_mks << '\n';
  fin.close();
  return 0;

}

