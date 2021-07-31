#include <iostream>
#include <string>
#include <cassert>
#include "../lib/index.hpp"
using namespace std;

int main() {
  // preparing
  int size = 10;
  string output = "";
  unsigned int indexes[size];
  for (int i = 0; i < size-1; i++) {
    indexes[i] = i;
    output += to_string(i) + ' ';
  }
  indexes[size-1] = size-1;
  output += to_string(size-1);

  // main
  Index target(size, indexes);
  for (int i = 0; i < size; i++) {
    assert(target[i] == i);
  }
  assert(target.get_size() == size);
  assert(output.compare(target.get_string()) == 0);
  return 0;
}