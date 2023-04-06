// Starer test program for CSCI 60 Homework 4; due Tuesday 2/2/21

#include <iostream>
#include "parity.h"

using namespace std;

int main()
{
  Parity p; // a 0-argument function is implemented for you
            // cout << p; // the stub function for << exists but doesn't output anything
  int arr[] = {3, 5, -1, 2, 6, 8, 10, 7, -2, 11, 15};
  int diffArr[] = {
      3,
      3,
      4,
  };
  int size = 11;
  int diffSize = 3;
  Parity p2(diffArr, diffSize);
  Parity p1(arr, size);
  cout << p1 << endl;
  cout << p2 << endl;
  cout << endl;
  // p1.insert(10);
  // p1.insert(8);
  // p1.insert(3);
  // p1.insert(5);
  // p1.insert(99);
  // p1.insert(3);
  // cout << p1 << endl;
  // cout << "Min Value: " << p1.min() << endl;
  // cout << "Max Value: " << p1.max() << endl;
  // cout << p1.odd() << endl;
  return 0;
}
