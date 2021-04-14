#include <iostream>
#include "data_structure.hpp"
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include "vector"
#include <string_view>
#include <fstream>      // ifstream, ofstream
#include <iostream>     // cout
#include <sstream>      // stringstream
#include <string>       // string, getline
#include <string_view>  // string_view
#include <random>       // mt19937_64, random_device
#include <chrono>
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
  auto* heap1 = new itis::BinomialHeap();
  string path = string("C:\\Users\\111\\CLionProjects\\semester-work-binomial-heapheap\\dataset\\data\\dataset-generated10k.csv");
  ifstream input_stream;
                           input_stream.open(path);
  vector<int> intValues;
  string line;
  if(!input_stream.is_open()){
  } else{
    while(getline(input_stream,line)){
      intValues=split(line,',');
    }
  }
  input_stream.close();
  const auto time_point_before = std::chrono::steady_clock::now();

  for (int i = 0; i <intValues.size() ; ++i) {
heap1->insert(intValues[i]);
  }
  const auto time_point_after = std::chrono::steady_clock::now();
  const auto time_diff = time_point_after - time_point_before;
  const long time_elapsed_mks = chrono::duration_cast<chrono::microseconds>(time_diff).count();
  cout << "Time elapsed (mks): " << time_elapsed_mks << '\n';
}


