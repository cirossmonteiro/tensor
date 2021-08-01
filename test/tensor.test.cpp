#include <iostream>
#include <string>
#include <cassert>
#include "test.hpp"
#include "../lib/index.hpp"
#include "../lib/indexer.hpp"
#include "../lib/tensor.hpp"
using namespace std;

// todo

int tensor_test() {
  // preparing
  cout << "tensor test" << endl;
  int size = 3, a = -10, b = 10;
  unsigned int indexes[size], dimensions[size];
  for (int i = 0; i < size; i++) {
    dimensions[i] = i+2;
  }
  Indexer indexer(size, dimensions);

  // main
  Tensor target(indexer, a, b);
  for (; !indexer.is_last_one(); indexer++) {
    assert(a <= target[indexer] && target[indexer] <= b);
  }
  return 0;
}