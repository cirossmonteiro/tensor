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

}

void Index::copy(Index &index) {
  size = index.get_size();
  if(!values) {
    delete[] values;
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
  values = new unsigned int[size];
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

void Index::print() {
  for(int i = 0; i < size; i++) {
    cout << values[i] << ' ';
  }
  cout << endl;
}

string Index::get_string() {
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
