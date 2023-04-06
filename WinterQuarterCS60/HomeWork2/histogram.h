// Interface file for CSCI 60 Homework 2; DO NOT MODIFY OR UPLOAD
// Sara Krehbiel, 1/18/23

#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <iostream>
#include <fstream>

using namespace std;

class Histogram
{
public:
  static const size_t MAX = 100;         // largest value that can be stored
  Histogram(string filename);            // read in histogram from file
  Histogram();                           // construct histogram with no entries
  size_t size() const;                   // total counts across all values
  size_t min() const;                    // smallest value with positive count
  size_t max() const;                    // largest value with positive count
  size_t mode() const;                   // (one of) the value(s) with highest count
  size_t median() const;                 // (the average of) the middle value(s)
  double mean() const;                   // arithmetic average of the values
  double variance() const;               // mean squared difference between each value and the mean
  void operator+=(const Histogram &rhs); // add each rhs count to these counts
  size_t operator[](size_t val) const;   // # times value occurs
private:
  size_t counts[MAX + 1]; // stores the frequency of each value 0...MAX
};

// display histogram contents to ostream out as in HW1
ostream &operator<<(ostream &out, const Histogram &h);

#endif
