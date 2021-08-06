#include <iostream>
#include <string>
#include "index.hpp"
using namespace std;

Index::~Index() {
  if(!values) {
    delete[] values;
    values = NULL;
  }
}

Index::Index() {
  check_internals();
}

Index::Index(unsigned int new_size) {
  check_internals();
  if (size != new_size) {
    size = new_size;
    if (values != NULL) {
      delete[] values;
    }
    if (size > 0) {
      values = new unsigned int[size];
    }
  }
}

Index::Index(unsigned int new_size, unsigned int *new_values) {
  check_internals();
  *this = Index(new_size);
  // size = new_size;
  // values = new unsigned int[size];
  for(int i = 0; i < size; i++) {
    values[i] = new_values[i];
  }
}

Index::Index(Index &index) {
  check_internals();
  *this = Index(index.get_size(), index.get_values());
  // size = index.get_size();
  // if(!values) {
  //   delete[] values;
  // }
  // values = new unsigned int[size];
  // for(int i = 0; i < size; i++) {
  //   values[i] = index[i];
  // }
}
