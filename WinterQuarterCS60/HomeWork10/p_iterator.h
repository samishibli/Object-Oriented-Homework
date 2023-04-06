// Starter iterator interface file for CSCI 60 Homework 10; due Thursday 3/16/23
//
// Design this P_iterator class so it works with the other Parity files.
// You may define your constructor(s) inline below, but all other functions
// should be declared in this file and implemented in p_iterator.cpp.
// Turn this in with p_iterator.cpp and parity.cpp.
//
// List any collaborators and write your name here

#ifndef P_ITERATOR_H
#define P_ITERATOR_H

#include "node.h"

class P_iterator
{
public:
	// TODO: define and implement constructor(s), *, ++, ==, !=
	P_iterator(node *headO, node *headE) : currO(headO), currE(headE) {}
	int operator*() const;
	P_iterator &operator++();
	P_iterator operator++(int);
	bool operator==(const P_iterator &rhs) const;
	bool operator!=(const P_iterator &rhs) const;

private:
	// TODO: declare private member variable(s)
	node *currE;
	node *currO;
};

#endif