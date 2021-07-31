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
  int size = 10;
  string output = "";
  unsigned int indexes[size];
  for (int i = 0; i < size-1; i++) {
    indexes[i] = i;
    output += to_string(i) + ' ';
  }

  // main
  
  return 0;
}