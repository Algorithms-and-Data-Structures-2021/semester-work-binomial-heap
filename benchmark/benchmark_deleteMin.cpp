#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream
#include <vector>
#include <random>  // mt19937_64, random_device

// подключаем вашу структуру данных
#include "data_structure.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};

vector<int> split(const string& s, char delimiter) {
  vector<int> tokens;
  string token;
  istringstream tokenStream(s);
  while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(stoi(token));
  }
  return tokens;
}

void addNewData(string pathToFile, int count) {

  const auto path = string(kDatasetPath);

  auto output_stream = ofstream(path + pathToFile);
  output_stream.open(pathToFile);
  const auto seed = chrono::system_clock::now().time_since_epoch().count();
  auto engine = mt19937(seed);
  auto dist = uniform_int_distribution(0, 100);

  if (output_stream) {
    for (int counter = 0; counter < count; counter++) {
      output_stream << dist(engine) << ',';
    }
    output_stream << dist(engine) << '\n';
  }
}

int main() {
  const auto path = string(kDatasetPath);
  int count = 750000;
  string pathToFile = string(path + "/" + std::to_string(count)  + ".csv");

  for (int i = 0; i < 10; ++i) {

    addNewData(pathToFile, count);

    ifstream input_stream;
    input_stream.open(pathToFile);
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
      for (int j = 0; j < 10; ++j) {
      BinomialHeap* heap1 = new BinomialHeap();

      for (int k = 0; k < count; ++k) {
        heap1->insert(intValues[k]);
      }
        const auto time_point_before = chrono::high_resolution_clock::now();

        heap1->deleteMinNode();
        const auto time_point_after = chrono::high_resolution_clock::now();
        // переводим время в наносекунды
        const auto time_diff = time_point_after - time_point_before;
        const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
        float dou = (float) time_elapsed_ns;
        cout<< dou << '\n';
      }

    }

  }
  return 0;

}



