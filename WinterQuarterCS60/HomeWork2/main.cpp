// Test program starter file for CSCI 60 Homework 2; due Monday 1/23/23
// Give a program description, list any collaborators, and write your name here

#include <iostream>
#include "histogram.h"

using namespace std;

int main()
{
  Histogram histogram1("data.txt");
  cout << "Size: " << histogram1.size() << endl;
  cout << "Min: " << histogram1.min() << endl;
  cout << "Max: " << histogram1.max() << endl;
  cout << "Mode: " << histogram1.mode() << endl;
  cout << "Median: " << histogram1.median() << endl;
  cout << "Mean: " << histogram1.mean() << endl;
  cout << "Variance: " << histogram1.variance() << endl;
  cout << "Values for histogram 2: " << endl;

  Histogram histogram2("data.txt");

  histogram2 += histogram1;

  cout << "Size: " << histogram2.size() << endl;
  cout << "Min: " << histogram2.min() << endl;
  cout << "Max: " << histogram2.max() << endl;
  cout << "Mode: " << histogram2.mode() << endl;
  cout << "Median: " << histogram1.median() << endl;
  cout << "Mean: " << histogram2.mean() << endl;
  cout << "Variance: " << histogram2.variance() << endl;

  cout << histogram1[2] << endl;

  /* TODO: replace this comment and the code below with your unit tests */

  // int total = 0; // var to store total
  // ifstream in("data.txt"); // open a file called data.txt as an input stream in
  // int val; // var to store one int at a time
  // while (in >> val) { // read int tokens from stream 1-by-1 until end of file
  //   total += val; // add value of each token to total
  // }
  // in.close(); // close file
  // cout << "Sum of all ints in a file = " << total << endl; // report total

  // Histogram h("data.txt");
  // cout << h; // after stage 5, compare this to the sample run in hw2.pdf

  return 0;
}
