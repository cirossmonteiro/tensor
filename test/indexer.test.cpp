#include <iostream>
#include <cassert>
#include "../lib/index.hpp"
#include "../lib/indexer.hpp"
using namespace std;

int main() {
  // preparing
  int size = 5;
  unsigned int dimensions[size], indexes[size];
  for (int i = 0; i < size; i++) {
    indexes[i] = 0;
    dimensions[i] = i + 2;
  }
  Index index(size, indexes);

  // main
  Indexer target(index, dimensions);
  assert(target.size() == size);
  for(int i = 0; !target.is_last_one(); i++, target++) {
    assert(target.convert_to_int() == i);
    target.set_by_int(i);
    assert(target.convert_to_int() == i);
  }
  return 0;
}