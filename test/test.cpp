#include <iostream>
#include "test.hpp"
using namespace std;

int main() {
  cout << "running test files..." << endl;
  index_test();
  indexer_test();
  tensor_test();
  cout << "DONE" << endl;
  return 0;
}