#include "index.hpp"

Index::~Index() {
  delete[] values;
  values = NULL;
}

Index::Index() {
  
}

void Index::copy(Index index) {
  size = index.get_size();
  if(!values) {
    delete values;
  }
  values = new unsigned int[size];
  for(int i = 0; i < size; i++) {
    values[i] = index[i];
  }
}

Index::Index(unsigned int new_size) {
  size = new_size;
  values = new unsigned int[size];
}

Index::Index(unsigned int new_size, unsigned int *new_values) {
  // Index(new_size);
  size = new_size;
  for(int i = 0; i < size; i++) {
    values[i] = new_values[i];
  }
}

Index::Index(Index &index) {
  copy(index);
}

unsigned int Index::get_size() {
  return size;
}

unsigned int &Index::operator[](int index) {
  return values[index];
}

