#pragma once
#ifndef INDEX_HPP
#define INDEX_HPP
#include <cstddef>

class Index {
  unsigned int size = 0;
  unsigned int *values = NULL;
  public:
    ~Index(); // done
    Index(); // to do
    Index(unsigned int new_size); // done
    Index(unsigned int new_size, unsigned int *new_values); // done
    Index(Index &index); // done
    void copy(Index new_index); // done
    unsigned int get_size(); // done
    unsigned int &operator[](int index); // done
};

#endif