// #include <ios>
#include "tensor.hpp"
#include <new>
#include <iostream>
#include <cstddef>
using namespace std;

Tensor::~Tensor() {
  delete[] dimensions;
  dimensions = NULL;
  delete[] values;
  values = NULL;
}

bool Tensor::__alloc_values() {
  values = new float[values_dimension];
  return values != NULL; // if null then allocation failed
}

void Tensor::__set_order(unsigned int new_order) {
  order = new_order;
}

bool Tensor::__set_dimensions(unsigned int *new_dimensions) {
  int total_space = 1;
  dimensions = new unsigned int[order];
  if (!dimensions) {
    return false;
  }
  for(int i = 0; i < order; i++) {
    dimensions[i] = new_dimensions[i];
  }
  for(int i = 0; i < order; i++) {
    total_space *= dimensions[i];
  }
  values_dimension = total_space;
  
  return __alloc_values();
}

Tensor::Tensor() {
  //
}

Tensor::Tensor(unsigned int new_order) {
  __set_order(new_order);
}

Tensor::Tensor(unsigned int new_order, unsigned int *new_dimensions) {
  __set_order(new_order);
  __set_dimensions(new_dimensions);
  __alloc_values();
};

Tensor::Tensor(unsigned int new_order, unsigned int *new_dimensions, float *new_values) {
  __set_order(new_order);
  __set_dimensions(new_dimensions);
  __alloc_values();
  for (int i = 0; i < values_dimension; i++) {
    values[i] = new_values[i];
  }
};

void Tensor::print() {
  // todo: print_whitespace(n)
  // pra cada dimensão maior, mais espaços separando
  cout << "Order: " << order << endl;
  cout << "Dimensions: ";
  for(int i = 0; i < order; i++) {
    cout << dimensions[i] << " ";
  }
  cout << endl;
  cout << "Values: ";
  for(int i = 0; i < values_dimension; i++) {
    cout << values[i] << " ";
  }
  cout << endl;
};

unsigned int Tensor::get_order() {
  return order;
}

unsigned int Tensor::total_space() {
  return values_dimension;
}

// Tensor Tensor::operator*(float scalar) {
//   for (int i = 0; i < values_dimension; i++) {
//     values[i]
//   }
// }

Indexer Tensor::indexer(unsigned int index) {
  Indexer indexer(order, dimensions);
  indexer.set_by_int(index);
  return indexer;
}



float Tensor::operator[](Indexer index) {
  return values[index.convert_to_int()];
}

float Tensor::operator[](Index index) {
  Indexer indexer(index, dimensions);
  return operator[](indexer);
}

float Tensor::operator[](unsigned int *index) {
  Index new_index(order, index);
  return operator[](new_index);
}

float Tensor::operator[](unsigned int index) {
  Indexer indexer(order, dimensions);
  indexer.set_by_int(index);
  return operator[](indexer);
}