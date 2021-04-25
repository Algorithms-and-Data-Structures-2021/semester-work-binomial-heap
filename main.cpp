#include <iostream>
#include "data_structure.hpp"
#include <random>  // mt19937_64, random_device
#include <chrono>  // system_clock
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

using namespace std;
int *split (const string& s, char delimiter,int count) {
  int *tokens=new int [count];
  string token;
  istringstream tokenStream(s);
  while (getline(tokenStream, token, delimiter)) {
    for (int i = 0;  i< count; i++) {
      tokens[i]= stoi(token);
    }
  }
  return tokens;
}

int main() {
  auto *heap1 = new itis::BinomialHeap();
  const auto path = string("C:\\Users\\111\\CLionProjects\\semester-work-binomial-heapTheEnd\\dataset\\data\\100.csv");
  ifstream input_stream;
  input_stream.open(path);
  int *intValues = new int[100];
  string line;
  if (!input_stream.is_open()) {
  } else {
    while (getline(input_stream, line)) {
      for(int i =0;i<100;i++){
        intValues= split(line,',',100);
      }
      const auto time_point_before = std::chrono::steady_clock::now();
      input_stream.close();
      for (int i = 0; i < 100; ++i) {
        heap1->insert(intValues[i]);
      }
      const auto time_point_after = std::chrono::steady_clock::now();
      const auto time_diff = time_point_after - time_point_before;
      const long time_elapsed_mks = chrono::duration_cast<chrono::microseconds>(time_diff).count();
      cout << "Time elapsed (mks): " << time_elapsed_mks << '\n';
    }
    for (int i = 0; i < 100; i++) {
      cout << intValues[i];
    }
  }
  return 0;
}
