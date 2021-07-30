#pragma once
#ifndef INDEXER_HPP
#define INDEXER_HPP
#include "index.hpp"

class Indexer {
  Index current;
  unsigned int *dimensions; // has the same size as current
  public:
    ~Indexer(); // done
    Indexer();
    Indexer(unsigned int new_size); // to do
    Indexer(unsigned int new_size, unsigned int *new_dimensions); // to do
    Indexer(Index &index, unsigned int *new_dimensions); // done
    unsigned int convert_to_int();
    unsigned int size(); // done
    unsigned int maxAvailable(); // done
    void set_by_int(unsigned int new_value); // done
    void operator++(); // done
    void next(); // todo: increment by <step> and check for dimensions
    void set_zero(); // check ITERATOR
    bool is_last_one(); // all indexes are equal to dimensions by one
};

#endif