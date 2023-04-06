#include "lbiguint.h"

#include <cassert>
#include <sstream>
using namespace std;

lbiguint::lbiguint()
{

    head->set_data(0);
    head->set_link(nullptr);
}

lbiguint::lbiguint(const string &s)
{
    if (s.size() == 0)
        return;

    head = nullptr;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        int num = s[i] - '0';
        node *newNode = new node(num, head);
        head = newNode;
    }
}
lbiguint::~lbiguint()
{
    while (head != nullptr)
    {
        node *temp = head;
        head = head->link();
        delete temp;
    }
    head = tail = nullptr;
}

int lbiguint::operator[](int pos) const
{
    int count = 0;
    for (node *p = head; p != nullptr; p = p->link())
    {
        count++;
        if (count == pos)
            return p->data();
    }
    return 0;
}
int lbiguint::size() const
{
    int size = 0;
    node *p = head;
    while (p != nullptr)
    {
        p = p->link();
        size++;
    }
    return size;
}
ostream &operator<<(ostream &out, const lbiguint &b)
{
    for (int i = b.size() - 1; i >= 0; --i)
    {
        out << b[i] << endl;
    }
    return out;
}
// int biguint::compare(const biguint &b) const
// {
//     for (int i = CAPACITY - 1; i >= 0; --i)
//     {
//         if (_data[i] > b._data[i])
//             return 1;
//         else if (_data[i] < b._data[i])
//             return -1;
//     }
//     return 0;
// }

// void biguint::operator+=(const biguint &b)
// {
//     int carry = 0;
//     int next = 0;
//     for (int i = 0; i < CAPACITY; ++i)
//     {
//         next = carry + _data[i] + b._data[i];
//         _data[i] = next % 10;
//         carry = next / 10;
//     }
// }
// string biguint::toStdString() const
// {
//     stringstream ss;
//     ss << *this;
//     return ss.str();
// } // We haven't talked about stringstreams; just ignore this, I was being lazy.
// ostream &operator<<(ostream &os, const biguint &b)
// {

//     for (int i = biguint::CAPACITY - 1; i >= 0; --i)
//         os << b[i];
//     return os;
// }

// istream &operator>>(istream &is, biguint &b)
// {
//     string s;
//     is >> s;
//     b = biguint(s);
//     return is;
// }

// bool operator<(const biguint &a, const biguint &b)
// {
//     return (a.compare(b) == -1);
// }

// bool operator<=(const biguint &b1, const biguint &b2)
// {
//     return (b1.compare(b2) <= 0);
// }

// bool operator==(const biguint &b1, const biguint &b2)
// {
//     return (b1.compare(b2) == 0);
// }

// bool operator!=(const biguint &b1, const biguint &b2)
// {
//     return (b1.compare(b2) != 0);
// }

// // You do > and >=
