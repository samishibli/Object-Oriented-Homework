// Iterator implementation file for CSCI 60 Homework 10; due Thursday 3/16/23
//
// All non-constructor functions in your P_iterator class must be defined here.
// Turn this in with p_iterator.h and parity.cpp.
//
// List any collaborators and write your name here

#include "p_iterator.h"

// TODO: Implement your P_iterator member functions here

bool P_iterator::operator==(const P_iterator &rhs) const
{
    return (currE == rhs.currE && currO == rhs.currO);
}
bool P_iterator::operator!=(const P_iterator &rhs) const
{
    return (currE != rhs.currE || currO != rhs.currO);
}
int P_iterator::operator*() const
{
    if (currE != nullptr && (currO == nullptr || currE->data() < currO->data()))
    {
        return currE->data();
    }

    return currO->data();
}
P_iterator &P_iterator::operator++()
{
    if (currE != nullptr && (currO == nullptr || currE->data() <= currO->data()))
    {
        currE = currE->link();
    }
    else
    {
        currO = currO->link();
    }

    return *this;
}
P_iterator P_iterator::operator++(int)
{
    if (currE != nullptr && (currO == nullptr || currE->data() <= currO->data()))
    {
        P_iterator temp = *this;
        currE = currE->link();
        return temp;
    }
    else
    {
        P_iterator temp = *this;
        currO = currO->link();
        return temp;
    }
}