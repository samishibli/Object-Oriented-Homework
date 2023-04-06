// Interface file for CSCI 60 Homework 4; due Sunday 2/5/23

#ifndef PARITY_H
#define PARITY_H

#include <iostream>
#include <climits>

using std::cout;
using std::endl;
using std::ostream;

class Parity {
public:
  // constructors and functions to override for dynamic memory management
  Parity() : nEven_(0), nOdd_(0), evens_(nullptr), odds_(nullptr) { };
  Parity(int * a, size_t n);

  // mutator
  void insert(int val);

  // accessors
  int min() const;
  int max() const;
  bool odd() const;
  void printAll() const;
  friend ostream& operator <<(ostream& out, const Parity& p);

private:
  size_t nEven_;
  size_t nOdd_;
  int *evens_;
  int *odds_;
  static const size_t CAP = 5;
  // INVARIANTS: evens_ points to a dynamic array of the nEven_ even ints;
  //             odds_ points to a dynamic array of the nOdd_ odd ints.
  //             Both should reflect the order values have been provided to
  //             insert calls to this object. The space allocated for each
  //             should be the smallest multiple of CAP that is at least the
  //             number of elements in the array.
};


#endif
