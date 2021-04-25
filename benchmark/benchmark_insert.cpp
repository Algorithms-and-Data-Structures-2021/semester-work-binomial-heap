#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <vector>
#include <fstream>      // ifstream, ofstream
#include <iostream>     // cout
#include <sstream>      // stringstream
#include <string>       // string, getline
#include <string_view>  // string_view
#include <random>       // mt19937_64, random_device
#include <chrono>       // system_clock

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
    cout << "Enter the amount of data (100, 500, 1000, 5000,"
            " 10000, 25000, 50000, 100000, 250000, 500000, 750000, 1000000)"
         << endl;

    int temporaryCount;
    std::cin >> temporaryCount;

    vector<int> integers = {100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 250000, 500000, 750000, 1000000};
    for (int i = 0; i < integers.size(); ++i) {
      if (temporaryCount == integers[i]) {
        flag = false;
        count = temporaryCount;
        break;
      }
    }
    if (flag) {
      cout << "Invalid amount of data." << endl;
    }
  }

  //чтение из файла
  const auto output_path = string(kProjectPath) + "/benchmark/metrics.csv";
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

    //создание кучи из полученных данных

    // замеры времени
    for (int j = 0; j < 10; ++j) {
      BinomialHeap* heap1 = new BinomialHeap();

      const auto time_point_before = std::chrono::steady_clock::now();

      for (int k = 0; k < count; ++k) {
        heap1->insert(intValues[k]);
      }

      const auto time_point_after = std::chrono::steady_clock::now();
      // переводим время в наносекунды
      const auto time_diff = time_point_after - time_point_before;
      const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
      cout << time_elapsed_ns / count << endl;
      //запись в файл
      if (output_stream) {
        output_stream << time_elapsed_ns / count << endl;
      }
      delete heap1;
    }
  }
  output_stream.close();

  return 0;
}