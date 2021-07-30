#pragma once
#ifndef TENSOR_HPP
#define TENSOR_HPP
#include <cstddef>
#include "index.hpp"
#include "indexer.hpp"

class Tensor {
  unsigned int order = 0; // order
  unsigned int *dimensions = NULL; // multidimensional index - size = order
  unsigned int values_dimension = 0; // product of values of *dimensions
  float *values = NULL;

  void __set_order(unsigned int new_order);
  bool __set_dimensions(unsigned int *new_dimensions);
  bool __alloc_values();

  public:
    ~Tensor();
    Tensor();
    Tensor(unsigned int new_order);
    Tensor(unsigned int new_order, unsigned int *new_dimensions);
    Tensor(unsigned int new_order, unsigned int *new_dimensions, float *values);
    Indexer indexer(unsigned int index);
    void print();
    unsigned int get_order();
    unsigned int total_space();
    float operator[](unsigned int index);
    float operator[](unsigned int *index);
    float operator[](Index index);
    float operator[](Indexer index);
    Tensor operator*(float scalar);
};

#endif