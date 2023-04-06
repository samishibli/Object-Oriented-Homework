
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// WANT: integers with CAPACITY digits, only non-negative
//
// support:
//    2 ructors: int, string
//    member functions:  [] returns individual digits given position
//                        +=
//                        -=
//                        compare: return +1, 0, -1, depending on
//                        whether this biguint >, ==, < than given biguint
//                        +, - (binary), - (unary), <, <=, ==, !=, >=, >
//                        <<, >>

class biguint
{
public:
    // ANTS

    const static int CAPACITY = 20;

    // RUCTORS

    // pre: none
    // post: creates a biguint with value 0
    biguint();

    // pre: s contains only decimal digits
    // post: creates a biguint whose value corresponds to given string of digits s
    biguint(string s);
    // ANT MEMBER FUNCTIONS

    // pre: pos < CAPACITY
    // post: returns the digit at position pos
    //          0 is the least significant (units) position

    unsigned short operator[](int pos);

    // pre: none
    // post: returns 1 if this biguint > b
    //               0 if this biguint == b
    //              -1 if this biguint < b
    int compare(biguint b);

    // MODIFICATION MEMBER FUNCTIONS

    // pre: none
    // post: b is added to this biguint; ignore last carry bit if any
    void operator+=(biguint b);
    void operator-=(biguint b);

private:
    unsigned short data_[CAPACITY];

    // INVARIANTS:
    //    data_[i] holds the i^th digit of this biguint or 0 if not used
    //    data_[0] holds the least significant (units) digit
};

// nonmember functions

biguint operator+(biguint b1, biguint b2);
biguint operator-(biguint b1, biguint b2);

bool operator<(biguint b1, biguint b2);
bool operator<=(biguint b1, biguint b2);
bool operator!=(biguint b1, biguint b2);
bool operator==(biguint b1, biguint b2);
bool operator>=(biguint b1, biguint b2);
bool operator>(biguint b1, biguint b2);
std::ostream &operator<<(std::ostream &, biguint b);

int main()
{
    biguint a = biguint();
    biguint b = biguint("2345");
    biguint c = biguint("3456");

    cout << b[0] << endl;
    b += c;
}
biguint::biguint()
{
    for (int i = 0; i < CAPACITY; i++)
    {
        data_[i] = 0;
    }
}
biguint::biguint(string s)
{
    int charIndex = s.length() - 1;
    for (int i = 0; i < CAPACITY; i++)
    {
        if (charIndex >= 0)
        {
            data_[i] = s.at(charIndex) - '0';
            charIndex--;
        }
        else
        {
            data_[i] = 0;
        }
    }
}
unsigned short biguint::operator[](int pos)
{
    if (pos >= CAPACITY || pos < 0)
    {
        cout << "Index out of bounds" << endl;
        return -1;
    }
    else
        return data_[pos];
}
void biguint::operator+=(biguint b)
{
    for (int i = 0; i < CAPACITY; i++)
    {
        unsigned short sum = data_[i] + b.data_[i];
        data_[i] = sum % 10;
        if (sum >= 10 && i < CAPACITY - 1)
        {
            data_[i + 1]++;
        }
    }
}