#include <fstream>      // ifstream, ofstream
#include <iostream>     // cout
#include <sstream>      // stringstream
#include <string>       // string, getline
#include <string_view>  // string_view
#include <random>       // mt19937_64, random_device
#include <chrono>       // system_clock

using namespace std;

// абсолютный путь до набора данных
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};

int main(int argc, char** argv) {

  // Tip 1: можете передать путь до входного/выходного файла в качестве аргумента
  for (int index = 0; index < argc; index++) {
    cout << "Arg: " << argv[index] << '\n';
  }

  const auto path = string(kDatasetPath);  // конвертация string_view в string
  cout << "Dataset path: " << path << endl;

  // Пример: чтение набора данных
  auto input_stream = ifstream(path + "/dataset-example.csv");

  if (input_stream) {
    int line_number = 0;

    // построчное чтение
    for (string line; getline(input_stream, line); /* ... */) {
      auto ss = stringstream(line);  // оборачиваем строку в объект "поток"

      for (string token; getline(ss, token, ','); /* ... */) {
        cout << "Token: [" << token << "] at line " << line_number << '\n';
      }

      cout << line << '\n';
      line_number++;
    }
  }

  // Пример: генерация набора данных

  vector<string> output_streams;

  output_streams.emplace_back("/dataset-generated100.csv");
  output_streams.emplace_back("/dataset-generated500.csv");
  output_streams.emplace_back("/dataset-generated1000.csv");
  output_streams.emplace_back("/dataset-generated5k.csv");
  output_streams.emplace_back("/dataset-generated10k.csv");
  output_streams.emplace_back("/dataset-generated25k.csv");
  output_streams.emplace_back("/dataset-generated50k.csv");
  output_streams.emplace_back("/dataset-generated100k.csv");
  output_streams.emplace_back("/dataset-generated250k.csv");
  output_streams.emplace_back("/dataset-generated500k.csv");
  output_streams.emplace_back("/dataset-generated750k.csv");
  output_streams.emplace_back("/dataset-generated1kk.csv");
  output_streams.emplace_back("/dataset-generated5kk.csv");

  vector<int> integers = {100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 250000, 500000, 750000, 1000000, 5000000};

  while (!integers.empty()){
    auto output_stream = ofstream(path + output_streams.front() /**, ios::ios_base::app**/);

    const auto seed = chrono::system_clock::now().time_since_epoch().count();
    auto engine = mt19937(seed);  // без seed`а генератор будет выдавать одни и те же значения
    auto dist = uniform_int_distribution(0, 100);  // равновероятное распределение генерируемых чисел

    if (output_stream) {
      for (int counter = 0; counter < integers.front(); counter++) {
        output_stream << dist(engine) << ',';
      }
      output_stream << dist(engine) << '\n';
    }

    integers.erase(integers.begin());
    output_streams.erase(output_streams.begin());
  }

  return 0;
}