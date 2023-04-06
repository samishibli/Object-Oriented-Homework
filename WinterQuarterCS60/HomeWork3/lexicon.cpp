// Sami Shibli
// implementation file for the Lexicon class
// default constructors created an array of strings that are taken in from a file
#include <iostream>
#include "lexicon.h"

using namespace std;

// 1-arg constructor takes in a file and populates array with distinct words in order from file
Lexicon::Lexicon(string filename) : Lexicon()
{
  string distinctword;
  ifstream in("filename");
  while (in >> distinctword)
  {
    // takes the first string assigns it to distinct word
    for (size_t i = 0; i < CAPACITY; i++)
    {
      if (data_[i] == distinctword)
      {
        break;
      }
      if (data_[i] == "")
      {
        data_[size_] = distinctword;
        size_++;
        break;
      }
    }
  }
  for (size_t i = 0; i < size_; i++)
  {
    cout << data_[i] << endl;
  }
  in.close();
}
// The truth value of whether the word is in the lexicon is returned
bool Lexicon::contains(string word) const
{
  for (size_t i = 0; i < size_; i++)
  {
    if (data_[i] == word)
    {
      return true;
    }
  }
  return false;
}
// Inserts a word into the Lexicon
bool Lexicon::insert(string word)
{
  if (size_ >= CAPACITY || contains(word))
  {
    return false;
  }

  data_[size_++] = word;
  return true;
}
// removes a word from the Lexicon
bool Lexicon::remove(string word)
{
  bool found = false;
  for (size_t i = 0; i < size_; i++)
  {
    if (data_[i] == word)
    {
      found = true;
    }
    if (found)
    {
      data_[i] = data_[i + 1];
    }
  }
  if (found)
    size_--;
  return found;
}
// Post: A union lexicon is constructed, populated with the first ≤CAPACITY
//       distinct elements of this object and rhs, and returned
Lexicon Lexicon::operator|(const Lexicon &rhs) const
{
  Lexicon l1;
  for (size_t i = 0; i < size_; i++)
  {
    l1.insert(data_[i]);
  }
  for (size_t i = 0; i < rhs.size_; i++)
  {
    if (l1.data_[i] != rhs.data_[i])
    {
      l1.insert(rhs.data_[i]);
    }
  }
  return l1;
}
// Post: An intersection lexicon is constructed, populated with the elements
//       common to this object and rhs, and returned
Lexicon Lexicon::operator&(const Lexicon &rhs) const
{
  Lexicon l1;
  if (size_ > rhs.size())
  {
    for (size_t i = 0; i < size_; i++)
    {
      if (rhs.contains(data_[i]))
      {
        l1.insert(data_[i]);
      }
    }
  }
  else
  {
    for (size_t i = 0; i < rhs.size(); i++)
    {
      if (contains(rhs[i]))
      {
        l1.insert(rhs[i]);
      }
    }
  }
  return l1;
}
// Post: A symmetric difference lexicon is constructed, populated with
//       the first ≤CAPACITY elements of this object XOR rhs, and returned
Lexicon Lexicon::operator^(const Lexicon &rhs) const
{
  Lexicon l1;
  if (size_ > rhs.size())
  {
    for (size_t i = 0; i < size_; i++)
    {
      if (!rhs.contains(data_[i]))
      {
        l1.insert(data_[i]);
      }
    }
  }
  else
  {
    for (size_t i = 0; i < size_; i++)
    {
      if (!contains(rhs[i]))
      {
        l1.insert(rhs[i]);
      }
    }
  }
  return l1;
}
// Post: True is returned iff the contents of lhs and rhs are identical
bool operator==(const Lexicon &lhs, const Lexicon &rhs)
{
  bool x = true;
  for (size_t i = 0; i < lhs.size(); i++)
  {
    if (!lhs.contains(rhs[i]))
      x = false;
  }
  return x;
}
// Post: True is returned iff the contents of lhs and rhs are not identical
bool operator!=(const Lexicon &lhs, const Lexicon &rhs)
{
  bool x = false;
  for (size_t i = 0; i < lhs.size(); i++)
  {
    if (!lhs.contains(rhs[i]))
      x = true;
  }
  return x;
}
// Post: True is returned iff the every lhs element is in rhs
bool operator<=(const Lexicon &lhs, const Lexicon &rhs)
{
  bool x = true;
  for (size_t i = 0; i < lhs.size(); i++)
  {
    if (!rhs.contains(lhs[i]))
    {
      x = false;
    }
  }
  return x;
}
// Post: True is returned iff every lhs element is in rhs which is not identical
bool operator<(const Lexicon &lhs, const Lexicon &rhs)
{
  return lhs <= rhs && !(lhs == rhs);
}
// Post: True is returned iff the every rhs element is in lhs
bool operator>=(const Lexicon &lhs, const Lexicon &rhs)
{
  bool x = true;
  for (size_t i = 0; i < rhs.size(); i++)
  {
    if (!lhs.contains(rhs[i]))
    {
      x = false;
    }
  }
  return x;
}
// Post: True is returned iff every rhs element is in lhs which is not identical
bool operator>(const Lexicon &lhs, const Lexicon &rhs)
{
  return lhs >= rhs && !(lhs == rhs);
}

// Inserts contents of lex in out in order, separated by spaces
ostream &operator<<(ostream &out, const Lexicon &lex)
{
  size_t n = lex.size();
  for (size_t i = 0; i < n; i++)
  {
    out << lex[i] << " ";
  }
  return out;
}
