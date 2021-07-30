// install bazel for tests
// using googleTest
#include <iostream>
using namespace std;
#include "lib/tensor.hpp"

int main() {
  unsigned int indexes[] = {2,3};
  float numbers[] = {1,2,3,4,5,6};
  Tensor teste(2, indexes, numbers);
  teste.print();
  teste.indexer(0);
  return 0;
}