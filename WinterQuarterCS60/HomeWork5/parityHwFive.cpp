// Parity.cpp defines all the functions that are declared in parity.h
// two-arg constructor takes in an array of ints and sorts into seperate array of
// evens and odds
//

#include "parity.h" // Do NOT add any additional libraries/namespaces!
// overloaded insertion operator to print out object
ostream &operator<<(ostream &out, const Parity &p)
{
  out << "E: ";
  for (size_t i = 0; i < p.nEven_; i++)
  {
    out << p.evens_[i] << " ";
  }

  out << endl;
  out << "O: ";
  for (size_t i = 0; i < p.nOdd_; i++)
  {
    out << p.odds_[i] << " ";
  }
  return out;
}
// Copy constructor creates a new object that copys the contents of the object passed in
Parity::Parity(const Parity &rhs)
{
  nEven_ = rhs.nEven_;
  nOdd_ = rhs.nOdd_;
  // allocating correct amount of space after resizing
  evens_ = new int[(((nEven_ / CAP) + 1) * 5)];
  odds_ = new int[(((nOdd_ / CAP) + 1) * 5)];
  for (size_t i = 0; i < nEven_; i++)
  {
    evens_[i] = rhs.evens_[i];
  }
  for (size_t i = 0; i < nOdd_; i++)
  {
    odds_[i] = rhs.odds_[i];
  }
  // different possible solution using = operator
  // evens_ = new int[1], odds_ = new int[1];
  // operator=(rhs);
}
// Destructor
Parity::~Parity()
{
  delete[] evens_;
  delete[] odds_;
  // evens_ = nullptr;
  // odds_ = nullptr;
}
// equals assignment operator function
Parity &Parity::operator=(const Parity &rhs)
{
  nEven_ = rhs.nEven_;
  nOdd_ = rhs.nOdd_;
  // relinquishing old memory to avoid orphaning
  delete[] evens_;
  delete[] odds_;
  evens_ = new int[(((nEven_ / CAP) + 1) * 5)];
  odds_ = new int[(((nOdd_ / CAP) + 1) * 5)];
  for (size_t i = 0; i < nEven_; i++)
  {
    evens_[i] = rhs.evens_[i];
  }
  for (size_t i = 0; i < nOdd_; i++)
  {
    odds_[i] = rhs.odds_[i];
  }
  return *this;
}
// two arg constructor that takes in array and sorts even and odds into respective arrays
// dynamically allocates space by roudning up to the nearest multiple of CAP
// sorts the arrays in ascending order
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
  // allocating correct amount of space
  evens_ = new int[(((nEven_ / CAP) + 1) * 5)];
  odds_ = new int[(((nOdd_ / CAP) + 1) * 5)];
  // int evenIndex = 0;
  // int oddIndex = 0;
  for (size_t i = 0; i < nEven_; i++)
  {
    evens_[i] = INT_MAX;
  }
  for (size_t i = 0; i < nOdd_; i++)
  {
    odds_[i] = INT_MAX;
  }
  for (size_t i = 0; i < n; i++)
  {
    if (a[i] % 2 == 0)
    {

      for (int j = nEven_ - 1; j >= 0; j--)
      {
        if (j == 0 || a[i] > evens_[j - 1])
        {
          evens_[j] = a[i];
          break;
        }
        evens_[j] = evens_[j - 1];
      }
    }
    else
    {
      for (int j = nOdd_ - 1; j >= 0; j--)
      {
        if (j == 0 || a[i] > odds_[j - 1])
        {
          odds_[j] = a[i];
          break;
        }
        odds_[j] = odds_[j - 1];
      }
    }
  }
}

// insert function allows for number to be inserted at end of array
// Creates space if neccessary
// insert the number into the correct order
void Parity::insert(int val)
{
  if (val % 2 == 0)
  {
    if (nEven_ % 5 == 0)
    {
      int *tempPtr = new int[nEven_ + CAP];
      for (int i = 0; i < nEven_; i++)
      {
        tempPtr[i] = INT_MAX;
      }
      for (int i = 0; i < nEven_; i++)
      {
        tempPtr[i] = evens_[i];
      }
      delete[] evens_;
      evens_ = tempPtr;
      tempPtr = nullptr;
    }
    // inserts the element and uses same functionality from default constructor
    for (int j = nEven_; j >= 0; j--)
    {
      if (j == 0 || val > evens_[j - 1])
      {
        evens_[j] = val;
        break;
      }
      evens_[j] = evens_[j - 1];
    }
    nEven_++;
  }
  else
  {
    if (nOdd_ % 5 == 0)
    {
      int *tempOddPtr = new int[nOdd_ + CAP];
      for (int i = 0; i < nOdd_; i++)
      {
        tempOddPtr[i] = INT_MAX;
      }
      for (int i = 0; i < nOdd_; i++)
      {
        tempOddPtr[i] = odds_[i];
      }
      delete[] odds_;
      odds_ = tempOddPtr;
      tempOddPtr = nullptr;
    }
    for (int j = nOdd_; j >= 0; j--)
    {
      if (j == 0 || val > odds_[j - 1])
      {
        odds_[j] = val;
        break;
      }
      odds_[j] = odds_[j - 1];
    }
    nOdd_++;
  }
}
// remove function removes all the occurances of val
size_t Parity::remove(int val)
{
  int counter = 0;
  if (val % 2 == 0)
  {
    for (size_t i = 0; i < nEven_; i++)
    {
      if (evens_[i] == val)
      {
        counter++;
      }
      else
      {
        evens_[i - counter] = evens_[i];
      }
    }
  }
  else
  {
    for (size_t i = 0; i < nOdd_; i++)
    {
      if (odds_[i] == val)
      {
        counter++;
      }
      else
      {
        odds_[i - counter] = evens_[i];
      }
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
