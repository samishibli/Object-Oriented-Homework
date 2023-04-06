// Sami Shibli
// template class creates a object of two different types
// vectors are used to store values

#include <iostream>
#include <vector>
using namespace std;

// complete implementation of a simple class for storing immutable fractions
class Fraction
{
public:
  Fraction(int num, int denom) : n(num), d(denom) {}
  Fraction() : Fraction(0, 1) {}
  Fraction operator+(const Fraction &rhs) const;
  friend ostream &operator<<(ostream &o, const Fraction &f);

private:
  const int n;
  const int d;
};

Fraction Fraction::operator+(const Fraction &rhs) const
{
  return Fraction(n * rhs.d + rhs.n * d, d * rhs.d);
}

ostream &operator<<(ostream &o, const Fraction &f)
{
  return o << f.n << "/" << f.d;
}

// Milestone 1: overload << for vector
template <typename T>
ostream &operator<<(ostream &out, vector<T> &b)
{
  int n = b.size();
  for (size_t i = 0; i < n; i++)
  {
    out << b[i] << ", ";
  }
  return out;
}

// het pair class
template <typename T, typename U>
class HetPair
{
public:
  // 0-arg constructor, and two arg constructor being initalized
  HetPair() : x(T()), y(U()) {}
  HetPair(T x, U y) : x(x), y(y) {}

  T getX() const { return x; }
  U getY() const { return y; }

  HetPair<T, U> operator+(const HetPair<T, U> &rhs) const;

private:
  T x;
  U y;
};
// overloaded ostream operator to print out values of each HetPair object
template <typename T, typename U>
ostream &operator<<(ostream &out, const HetPair<T, U> &b)
{
  out << "(" << b.getX() << ", " << b.getY() << ")";

  return out;
}
//+ operator overloaded to add hetpairs of heterogenous types
template <typename T, typename U>
HetPair<T, U> HetPair<T, U>::operator+(const HetPair<T, U> &rhs) const
{
  return HetPair(x + rhs.x, y + rhs.y);
}

// Driver program to test as you go
int main()
{
  // Milestone 1 testcode
  vector<int> intVec;  // the standard version of templatized dynamic bag
  intVec.push_back(2); // push_back is analogous to insert
  intVec.push_back(4);
  intVec.push_back(4);
  intVec.push_back(-1);
  cout << intVec << endl;

  vector<Fraction> fracVec;
  fracVec.push_back(Fraction(3, 11));
  fracVec.push_back(Fraction(-1, 2));
  fracVec.push_back(Fraction(2, 1));
  cout << fracVec << endl;

  HetPair<int, double> h1(1, 2.5);
  HetPair<int, double> h2(2, 3.3);
  cout << h1.getX() << " " << h1.getY() << endl;
  HetPair<int, double> h3 = h1 + h2;
  cout << h1 << endl;
  cout << h2 << endl;
  cout << h3 << endl;

  // the following code reads in numerator and denominator values to create vectors of
  //  fractions and its respective double value
  int numer, denom;
  vector<HetPair<Fraction, double>> hetPairVec;
  while (denom != 0)
  {
    cout << "Enter a numerator and denominator (0 denom to quit): ";
    cin >> numer >> denom;
    if (denom == 0)
      break;
    hetPairVec.push_back(HetPair<Fraction, double>(Fraction(numer, denom), static_cast<double>(numer) / denom));
  }
  cout << hetPairVec << " ";
  return 0;
}
