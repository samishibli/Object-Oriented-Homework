#include "dbiguint.h"
#include <iostream>
using namespace std;

dbiguint::dbiguint()
{
    capacity_ = 0;
    data_ = nullptr;
}
dbiguint::dbiguint(const string &s)
{
    capacity_ = s.length();
    data_ = new unsigned short[capacity_];
    for (size_t i = 0; i < capacity_; i++)
    {
        data_[i] = s.at(capacity_ - 1 - i) - '0';
    }
}
dbiguint::~dbiguint()
{
    capacity_ = 0;
    delete[] data_;
}
unsigned short dbiguint::operator[](int pos) const
{
    if (pos >= capacity_ || pos < 0)
    {
        return 0;
    }
    else
    {
        return data_[pos];
    }
}
// void biguint::operator+=(biguint b)
// {
//     for (int i = 0; i < CAPACITY; i++)
//     {
//         unsigned short sum = data_[i] + b.data_[i];
//         data_[i] = sum % 10;
//         if (sum >= 10 && i < CAPACITY - 1)
//         {
//             data_[i + 1]++;
//         }
//     }
// }
int dbiguint::size() const
{
    return capacity_;
}
ostream &operator<<(ostream &out, const dbiguint &d)
{
    for (int i = d.size() - 1; i >= 0; i--)
    {
        out << d[i];
    }
    return out;
}
void dbiguint::reserve(int newcapacity)
{
    if (capacity_ >= newcapacity)
    {
    }
}

// void dbiguint::clean()
// {
//     int count = 0;
//     for (size_t i = 0; data[i] == 0 && i < size(); i++)
//     {
//         if (data[i] == 0)
//         {
//             count++;
//         }
//     }
//     int newSize = size - count;
//     int *temp = new int[newSize];
//     for (size_t i = 0; i < size(); i++)
//     {
//         temp[i] = data[count + i];
//     }
//     delete data;
//     data = temp;
//     temp = nullptr;
// }
