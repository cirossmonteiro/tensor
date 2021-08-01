#include <stdexcept>
#include <iostream>
#include "index.hpp"
#include "indexer.hpp"
using namespace std;

Indexer::~Indexer() {
  if(!dimensions) {
    delete[] dimensions;
    dimensions = NULL;
  }
}

Indexer::Indexer() {
  return;
}

Indexer::Indexer(unsigned int new_size) { // to do
  return;
}

Indexer::Indexer(unsigned int new_size, unsigned int *new_dimensions) { // to do
  current = Index(new_size);
  dimensions = new unsigned int[size()];
  for(int i = 0; i < size(); i++) {
    dimensions[i] = new_dimensions[i];
  }
  return;
}

Indexer::Indexer(Index index, unsigned int *new_dimensions) {
  current.copy(index);
  dimensions = new unsigned int[size()];
  for(int i = 0; i < size(); i++) {
    dimensions[i] = new_dimensions[i];
  }
};

unsigned int *Indexer::get_dimensions() {
  return dimensions;
}

bool Indexer::is_last_one() {
  for (int i = size()-1; i >= 0; i--) {
    if (current[i] < dimensions[i] - 1) {
      return false;
    }
  }
  return true;
}

unsigned int &Indexer::operator[](int index) {
  return current[index];
}

unsigned int &Indexer::operator()(int index) {
  return dimensions[index];
}

void operator++(Indexer &indexer, int) {
  if (indexer.is_last_one()) {
    throw invalid_argument("Can't compute next value - the limit's been reached.");
  } else {
    for(int i = indexer.size() - 1; i >= 0; i--) {
      if (indexer[i] < indexer(i) - 1) {
        indexer[i]++;
        break;
      } else {
        indexer[i] = 0;
      }
    }
  }
}

// void Indexer::next() {
//   for (int i = 0; i < 1; i++) {
//     operator++(0);
//   }
// }

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

Index& Indexer::index() {
  return current;
}

ostream &operator<<(ostream& out, Indexer &indexer) {
  out << indexer.index();
  return out;
}

void Indexer::set_zero() {
  current.set_zero();
}