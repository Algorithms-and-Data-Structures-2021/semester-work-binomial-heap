#include <fstream>      // ifstream, ofstream
#include <iostream>     // cout
#include <sstream>      // stringstream
#include <string>       // string, getline
#include <string_view>  // string_view
#include <random>       // mt19937_64, random_device
#include <chrono>       // system_clock

using namespace std;
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};

int main() {

  const auto path = string(kDatasetPath);

  vector<string> output_streams;

  output_streams.emplace_back("/100.csv");
  output_streams.emplace_back("/500.csv");
  output_streams.emplace_back("/1000.csv");
  output_streams.emplace_back("/5000.csv");
  output_streams.emplace_back("/10000.csv");
  output_streams.emplace_back("/25000.csv");
  output_streams.emplace_back("/50000.csv");
  output_streams.emplace_back("/100000.csv");
  output_streams.emplace_back("/250000.csv");
  output_streams.emplace_back("/500000.csv");
  output_streams.emplace_back("/750000.csv");
  output_streams.emplace_back("/1000000.csv");
  output_streams.emplace_back("/5000000.csv");

  vector<int> integers = {100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 250000, 500000, 750000, 1000000, 5000000};

  while (!integers.empty()){
    auto output_stream = ofstream(path + output_streams.front());

    const auto seed = chrono::system_clock::now().time_since_epoch().count();
    auto engine = mt19937(seed);
    auto dist = uniform_int_distribution(0, 100);

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