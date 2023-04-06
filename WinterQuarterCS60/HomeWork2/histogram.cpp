// Sami Shibli Homework 2
// histogram cpp defines the functions that are declared in histogram class
// also overloades [], +=, and <<

#include "histogram.h"
#include <iostream>
using namespace std;

// intitalize all values of array to zero
Histogram::Histogram()
{
    for (int i = 0; i <= MAX; i++)
    {
        counts[i] = 0;
    }
}
// intialize obj that takes in data from "data.txt"
Histogram::Histogram(string filename) : Histogram()
{
    int val;
    ifstream in(filename);
    while (in >> val)
    { // read int tokens from stream 1-by-1 until end of file
        counts[val]++;
    }
    in.close();
}
// calulates the size of the txt file
size_t Histogram::size() const
{
    int size = 0;
    for (int i = 0; i <= MAX; i++)
    {
        size += counts[i];
    }
    return size;
}
// returns the smallest value in the array
size_t Histogram::min() const
{
    int min;
    for (int i = 0; i <= MAX; i++)
    {
        if (counts[i] != 0 && i < min)
        {
            min = i;
        }
    }

    return min;
}
// returns the largest value in the array
size_t Histogram::max() const
{
    int largest;
    for (int i = 0; i < MAX; i++)
    {
        if (counts[i] != 0 && i > largest)
        {
            largest = i;
        }
    }
    return largest;
}
// returns the number that occurs most often
size_t Histogram::mode() const
{
    int mode;
    for (int i = 0; i <= MAX; i++)
    {
        if (counts[i] > mode)
        {
            mode = i;
        }
    }
    return mode;
}
// returns the median of the list

size_t Histogram::median() const
{
    int median = size() / 2;
    for (int i = 0; i < MAX; i++)
    {
        median -= counts[i];
        if (median <= 0)
        {
            return i;
        }
    }
    return median;
}
// returns the mean of the values
double Histogram::mean() const
{
    double sum = 0;
    double mean;
    double lengthOfArray = 0;
    for (int i = 0; i <= MAX; i++)
    {
        if (counts[i] != 0)
        {
            lengthOfArray += counts[i];
            sum += counts[i] * i;
            mean = sum / lengthOfArray;
        }
    }
    return mean;
}
// returns the variance
double Histogram::variance() const
{
    double variance = 0;
    double lengthOfArray = 0;
    double sum = 0;
    double mean;

    for (int i = 0; i <= MAX; i++)
    {
        if (counts[i] != 0)
        {
            lengthOfArray += counts[i];
            sum += counts[i] * i;
            mean = sum / lengthOfArray;
            variance += (counts[i] * ((i - mean) * (i - mean)));
        }
    }
    return variance / lengthOfArray;
}
// overloads the += operator
void Histogram::operator+=(const Histogram &rhs)
{
    for (int i = 0; i <= MAX; i++)
    {
        counts[i] += rhs.counts[i];
    }
}
size_t Histogram::operator[](size_t val) const
{
    return counts[val];
}
ostream &operator<<(ostream &out, const Histogram &h)
{
    for (int i = 0; i < MAX; i++)
    {
    }
    return out;
}
