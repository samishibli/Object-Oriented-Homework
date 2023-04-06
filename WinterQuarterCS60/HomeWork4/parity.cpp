// Parity.cpp defines all the functions that are declared in parity.h
// two-arg constructor takes in an array of ints and sorts into seperate array of
// evens and odds

#include "parity.h" // Do NOT add any additional libraries/namespaces!
// overloaded insertion operator to print out object
ostream &operator<<(ostream &out, const Parity &p)
{
  out << "E: ";
  for (int i = 0; i < p.nEven_; i++)
  {
    out << p.evens_[i] << " ";
  }

  out << endl;
  out << "O: ";
  for (int i = 0; i < p.nOdd_; i++)
  {
    out << p.odds_[i] << " ";
  }
  return out;
}
// two arg constructor that takes in array and sorts even and odds into respective arrays
// dynamically allocates space by roudning up to the nearest multiple of CAP
Parity::Parity(int *a, size_t n)
{
  nEven_ = 0;
  nOdd_ = 0;
  for (size_t i = 0; i < n; i++)
  {
    if (a[i] % 2 == 0)
    {
      nEven_++;
    }
    else
    {
      nOdd_++;
    }
  }
  evens_ = new int[(((nEven_ / CAP) + 1) * 5)];
  odds_ = new int[(((nOdd_ / CAP) + 1) * 5)];
  int evenIndex = 0;
  int oddIndex = 0;

  for (size_t i = 0; i < n; i++)
  {
    if (a[i] % 2 == 0)
    {
      evens_[evenIndex++] = a[i];
    }
    else
    {
      odds_[oddIndex++] = a[i];
    }
  }
}
// insert function allows for number to be inserted at end of array
// Creates space if neccessary

void Parity::insert(int val)
{
  if (val % 2 == 0)
  {
    evens_[nEven_] = val;
    nEven_++;
    if (nEven_ % 5 == 0)
    {
      int *tempPtr = new int[nEven_ + CAP];
      for (int i = 0; i < nEven_; i++)
      {
        tempPtr[i] = evens_[i];
      }
      delete[] evens_;
      evens_ = tempPtr;
      tempPtr = nullptr;
    }
  }
  else
  {
    odds_[nOdd_] = val;
    nOdd_++;
    if (nOdd_ % 5 == 0)
    {
      int *tempOddPtr = new int[nOdd_ + CAP];
      for (int i = 0; i < nOdd_; i++)
      {
        tempOddPtr[i] = odds_[i];
      }
      delete[] odds_;
      odds_ = tempOddPtr;
      tempOddPtr = nullptr;
    }
  }
}
// finds the smallest value of both arrays

int Parity::min() const
{
  int min = INT_MAX;
  for (size_t i = 0; i < nEven_; i++)
  {
    if (evens_[i] < min)
    {
      min = evens_[i];
    }
  }
  for (size_t i = 0; i < nOdd_; i++)
  {
    if (odds_[i] < min)
    {
      min = odds_[i];
    }
  }
  return min;
}
// finds the largest value of both arrays

int Parity::max() const
{
  int max = INT_MIN;
  for (size_t i = 0; i < nEven_; i++)
  {
    if (evens_[i] > max)
    {
      max = evens_[i];
    }
  }
  for (size_t i = 0; i < nOdd_; i++)
  {
    if (odds_[i] > max)
    {
      max = odds_[i];
    }
  }
  return max;
}
// returns true if the sum of both arrays is odd.
// this is my one line solution, but im unsure if correct.
// less efficent solution is commented out/
bool Parity::odd() const
{
  return (nOdd_ % 2 != 0);
  // int sum = 0;
  // for (int i = 0; i < nEven_; i++)
  // {
  //   sum += evens_[i];
  // }
  // for (int i = 0; i < nOdd_; i++)
  // {
  //   sum += odds_[i];
  // }
  // return sum % 2 != 0;
}
