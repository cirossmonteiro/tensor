// install bazel for tests
// using googleTest
#include <iostream>
using namespace std;
#include "lib/tensor.hpp"

int main() {
  unsigned int indexes[] = {2,3};
  Tensor teste(2, indexes);
  teste.print();
  return 0;
}