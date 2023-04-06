// Starer test program for CSCI 60 Homework 4; due Tuesday 2/2/21

#include <iostream>
#include "parity.h"

using namespace std;

int main()
{
  // Parity p; // a 0-argument function is implemented for you
  //  cout << p; // the stub function for << exists but doesn't output anything
  int arr[] = {3, 6, 7, 8, 22, 55, 66, 34, 22, 12, 15, 7};
  int arr2[] = {4, 3, 2, 2, 1};
  int arr3[] = {2, 2, 3};
  int x = 3;
  int n = 5;
  int size = 12;
  Parity p1(arr, size);
  Parity p2(arr2, n);
  Parity p3(arr3, x);
  p1.insert(4);
  p1.insert(5);
  p1.remove(12);
  p1.remove(7);
  cout << p1 << endl;
  cout << p2 << endl;
  cout << p3 << endl;
  p1 = p3;
  cout << p1 << endl;
  cout << endl;
  Parity p4(p1);
  cout << p4 << endl;

  return 0;
}
