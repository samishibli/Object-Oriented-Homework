#ifndef BAG_H
#define BAG_H
#include <ostream>
using namespace std;

template <typename T>
class npoint
{
public:
    npoint();
    npoint(int dimension);
    npoint(int dimension, T arr[]);

    T operator[](size_t pos) const { return arr[pos]; }
    size_t size() const { return dimension; }

private:
    int dimension;
    T arr[10];
};

#endif
// Three constructors: one constructor that takes 0 arguments, one that takes in just the dimension of the point, and one that takes in the dimension of the point and an initializing array.
// A single getter that returns the ith item in the tuple
// A getter for the size

// size_t size() const { return size_; }
//   size_t cap() const { return cap_; }
//   size_t count(T target) const; // #copies of target
//   T operator [](size_t pos) const { return data_[pos]; }