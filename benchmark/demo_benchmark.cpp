#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream
#include <vector>

// подключаем вашу структуру данных
#include "data_structure.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

vector<int> split(const string& s, char delimiter) {
  vector<int> tokens;
  string token;
  istringstream tokenStream(s);
  while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(stoi(token));
  }
  return tokens;
}

int main(int argc, char** argv) {

  string path = string("C:\\Users\\79196\\CLionProjects\\semester-work-binomial-heap\\dataset\\data\\100.csv");
  ifstream input_stream;
  input_stream.open(path);
  vector<int> intValues;
  string line;
  if (!input_stream.is_open()) {
  } else {
    while (getline(input_stream, line)) {
      intValues = split(line, ',');
    }

    input_stream.close();

    // Tip 3: время работы программы (или участка кода) можно осуществить
    // как изнутри программы (std::chrono), так и сторонними утилитами

    BinomialHeap* heap1 = new BinomialHeap();
    BinomialHeap* heap2 = new BinomialHeap();

    for (int i = 0; i < intValues.size()/2; ++i) {
      heap1->insert(intValues[i]);
    }
    heap1->printHeap();
    for (int i = 0; i < intValues.size()/2; ++i) {
      heap2->insert(intValues[i]);
    }
    heap2->printHeap();

    const auto time_point_before = chrono::high_resolution_clock::now();

  heap1->merge(heap2);
    const auto time_point_after = chrono::high_resolution_clock::now();

    // переводим время в наносекунды
    const auto time_diff = time_point_after - time_point_before;
    const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

    cout << "Time elapsed (ns): " << time_elapsed_ns << '\n';

    return 0;
  }
}