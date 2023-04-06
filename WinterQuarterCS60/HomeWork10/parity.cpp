// Parity implementation file for CSCI 60 Homework 10; due Thursday 3/16/23
//
// Copy over all your parity.cpp implementation code from Homework 9,
// and add definitions for the new begin and end member functions.
// Turn this in with p_iterator.h and p_iterator.cpp.
//
// List any collaborators and write your name here

#include "parity.h"

// TODO: Copy your Homework 9 code and implement begin and end here
Parity::Parity()
{
    headE = tailE = headO = tailO = nullptr;
    nE = nO = 0;
}

// a copy-constructor that deep-copies the contents of another object
Parity::Parity(const Parity &other)
{
    node *curr = other.headE;
    while (curr != nullptr)
    {
        list_insert_tail(headE, tailE, curr->data());
        curr = curr->link();
    }
    curr = other.headO;
    while (curr != nullptr)
    {
        list_insert_tail(headO, tailO, curr->data());
        curr = curr->link();
    }
    nE = other.nE;
    nO = other.nO;
}
// inserting val into evens or odds list
void Parity::insert(int val)
{
    if (val % 2 == 0)
    {
        // insert into evens list using (list_insert_sorted)
        list_insert_sorted(headE, tailE, val);
        nE++;
    }
    else
    {
        // insert into odds list
        list_insert_sorted(headO, tailO, val);
        nO++;
    }
}

// destructor deletes memory of both list, sets variables to default values
Parity::~Parity()
{
    while (headE != nullptr)
    {
        node *temp = headE;
        headE = headE->link();
        delete temp;
    }
    while (headO != nullptr)
    {
        node *temp = headO;
        headO = headO->link();
        delete temp;
    }
    headE = tailE = headO = tailO = nullptr;
    nE = nO = 0;
}
Parity &Parity::operator=(const Parity &rhs)
{
    nE = rhs.nE;
    nO = rhs.nO;
    // calling destructor to release memory before reassigning
    this->~Parity();
    // old implementation to release old memory
    //  while (headE != nullptr)
    //  {
    //  	node *temp = headE;
    //  	headE = headE->link();
    //  	delete temp;
    //  }
    //  tailE = nullptr;
    node *curr = rhs.headE;
    while (curr != nullptr)
    {

        list_insert_tail(headE, tailE, curr->data());
        curr = curr->link();
    }
    // while (headO != nullptr)
    // {
    // 	node *temp = headO;
    // 	headO = headO->link();
    // 	delete temp;
    // }
    // tailO = nullptr;
    node *currO = rhs.headO;
    while (currO != nullptr)
    {
        list_insert_tail(headO, tailO, currO->data());
        currO = currO->link();
    }
    return *this;
}
int Parity::min() const
{
    int min = INT_MAX;
    for (node *p = headE; p != nullptr; p = p->link())
    {
        if (p->data() < min)
            min = p->data();
    }
    for (node *p = headO; p != nullptr; p = p->link())
    {
        if (p->data() < min)
            min = p->data();
    }
    return min;
}
int Parity::max() const
{
    int max = INT_MIN;
    for (node *p = headE; p != nullptr; p = p->link())
    {
        if (p->data() > max)
            max = p->data();
    }
    for (node *p = headO; p != nullptr; p = p->link())
    {
        if (p->data() > max)
            max = p->data();
    }
    return max;
}
Parity::iterator Parity::begin()
{
    return iterator(headO, headE);
}

Parity::iterator Parity::end()
{
    return iterator(nullptr, nullptr);
}
ostream &operator<<(ostream &out, const Parity &lists)
{
    // recursive implementation to output contents of object
    out << "Evens: ";
    if (lists.headE == nullptr && lists.headO == nullptr)
    {
        return out;
    }
    out << lists.headE->data() << " " << lists.headE->link();
    out << std::endl;
    out << "Odds: ";
    return out << lists.headO->data() << " " << lists.headO->link() << std::endl;
}