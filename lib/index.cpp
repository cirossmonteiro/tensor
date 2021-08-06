#include <iostream>
#include <string>
#include "index.hpp"
using namespace std;

void Index::check_internals() const {
  if (size == 0 && values != NULL) {
    throw "Values is not empty, though size is zero.";
  } else if (size != 0 && values == NULL) {
    throw "Values is empty, though size is not zero.";
  }
}


unsigned int Index::get_size() {
  check_internals();
  return size;
}

unsigned int *Index::get_values() {
  return values;
}

unsigned int &Index::operator[](int index) const {
  check_internals();
  if (0 < size && 0 <= index && index < size) {
    return values[index];
  } else {
    throw "Index: invalid value to operator[]";
  }
}

void Index::print() {
  check_internals();
  if (size == 0) {
    cout << "";
  } else {
    if (values == NULL) {
      throw "Values is empty, though size is not zero.";
    } else {
      for(int i = 0; i < size; i++) {
        cout << values[i] << ' ';
      }
      cout << endl;
    }
  }  
}

string Index::get_string() {
  check_internals();
  string ac = "";
  if (size == 0) {
    return ac;
  }
  for(int i = 0; i < size - 1; i++) {
    ac += to_string(values[i]) + ' ';
  }
  ac += to_string(values[size-1]);
  return ac;
}

string &operator<<(string &ac, Index &index) {
  index.check_internals();
  int size = index.get_size();
  if (size == 0) {
    return ac;
  }
  for(int i = 0; i < size - 1; i++) {
    ac += to_string(index[i]) + ' ';
  }
  ac += to_string(index[size-1]);
  return ac;
}

ostream &operator<<(ostream& out, Index &index) {
  index.check_internals();
  int size = index.get_size();
  if (size == 0) {
    return out;
  }
  for(int i = 0; i < size - 1; i++) {
    out << to_string(index[i]) + ' ';
  }
  out << to_string(index[size-1]);
  return out;
}

void Index::set_zero() {
  check_internals();
  for(int i = 0; i < size - 1; i++) {
    values[i] = 0;
  }
}