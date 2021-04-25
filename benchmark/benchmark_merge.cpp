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
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

//парсинг
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

  bool flag = true;
  int count;

  //проверка, верно ли введено количество данных
  while (flag) {
    std::cin >> count;
    vector<int> integers = {100,    500,    1000,   5000,   10000,   25000,  50000,
                            100000, 250000, 500000, 750000, 1000000, 5000000};
    for (int i = 0; i < integers.size(); ++i) {
      if (count == integers[i]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << "Invalid amount of data." << endl;
    }
  }

  //чтение из файла
  const auto output_path = string(kProjectPath) + "/benchmark/test_data/merge/" + std::to_string(count) + ".csv";
  auto output_stream = ofstream(output_path);

  const auto path = string(kDatasetPath);
  string pathToFile = string(path + "/" + std::to_string(count) + ".csv");
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

    // замеры времени
    for (int j = 0; j < 10; ++j) {

      //создание двух куч из полученных данных
      BinomialHeap* heap1 = new BinomialHeap();
      for (int k = 0; k < count / 2; ++k) {
        heap1->insert(intValues[k]);
      }
      BinomialHeap* heap2 = new BinomialHeap();
      for (int k = count / 2; k < count; ++k) {
        heap2->insert(intValues[k]);
      }
      const auto time_point_before = chrono::high_resolution_clock::now();

      heap1->mergeHeaps(heap2);

      const auto time_point_after = chrono::high_resolution_clock::now();
      // переводим время в наносекунды
      const auto time_diff = time_point_after - time_point_before;
      const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

      //запись в файл
      if (output_stream) {
        output_stream << (float) time_elapsed_ns / 1000 << endl;
      }
    }
  }

  output_stream.close();
  return 0;
}
