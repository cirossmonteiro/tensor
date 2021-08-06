#include <iostream>
#include <string>
#include <cassert>
#include "test.hpp"
#include "../lib/index.hpp"
using namespace std;

int index_test() {
  // preparing
  cout << "index test" << endl;
  int size = 100;
  string output = "";
  unsigned int indexes[size];
  for (int i = 0; i < size-1; i++) {
    indexes[i] = i;
    output += to_string(i) + ' ';
  }
  indexes[size-1] = size-1;
  output += to_string(size-1);

  // main
  Index target1, target2, target3, target4;
  target1 = Index();
  target2 = Index(size);
  target3 = Index(size, indexes);
  target4 = Index(target3);
  for (int i = 0; i < size; i++) {
    assert(target4[i] == i);
    target4[i] = i;
    assert(target4[i] == i);
  }
  assert(target4.get_size() == size);
  assert(output.compare(target4.get_string()) == 0);
  target1.check_internals();
  target2.check_internals();
  target3.check_internals();
  target4.check_internals();
  return 0;
}