#include <stdexcept>
#include "index.hpp"
#include "indexer.hpp"

Indexer::~Indexer() {
  delete[] dimensions;
  dimensions = NULL;
  delete &current;
}

Indexer::Indexer() {
  return;
}

Indexer::Indexer(unsigned int new_size) { // to do
  return;
}

Indexer::Indexer(unsigned int new_size, unsigned int *new_dimensions) { // to do
  return;
}

Indexer::Indexer(Index &index, unsigned int *new_dimensions) {
  current.copy(index);
  for(int i = 0; i < size(); i++) {
    dimensions[i] = new_dimensions[i];
  }
};

bool Indexer::is_last_one() {
  for (int i = 0; i < size(); i++) {
    if (current[i] < dimensions[i] - 1) {
      return false;
    }
  }
  return true;
}

void Indexer::operator++() {
  if (is_last_one()) {
    throw std::invalid_argument("Can't compute next value - the limit's been reached.");
  } else {
    for(int i = size() - 1; i >= 0; i++) {
      if (current[i] < dimensions[i] - 1) {
        current[i] = current[i] + 1;
      } else {
        current[i] = 0;
      }
    }
  }
}

void Indexer::next() {
  for (int i = 0; i < 1; i++) {
    operator++();
  }
}

unsigned int Indexer::maxAvailable() {
  unsigned int p = 1;
  for (int k = 0; k < size(); k++) {
    p *= dimensions[k];
  }
  return p;
}

unsigned int Indexer::convert_to_int() {
  unsigned int p = maxAvailable(), I = 0;
  for (int k = 0; k < size(); k++) {
    p /= dimensions[k];
    I += current[k]*p;
  }
  return I;
}

unsigned int Indexer::size() {
  return current.get_size();
}

void Indexer::set_by_int(unsigned int new_value) {
  unsigned int p = maxAvailable(), r = 0;
  for (int k = 0; k < size(); k++) {
    p /= dimensions[k];
    current[k] = (new_value - r) / p;
    r += current[k]*p;
  }
}