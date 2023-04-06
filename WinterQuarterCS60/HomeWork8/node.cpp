// Implementation file for CSCI 60 Homework 8; due Sunday 3/5/23
// Sami Shibli
// Node file implements 4 functions recursively

#include "node.h"
#include <iostream>
using namespace std;

// overloaded << for debugging
ostream &operator<<(ostream &out, const node *head)
{
  if (head == nullptr)
    return out;                 // base case: empty list
  out << head->data() << " ";   // non-recursively output the data of the head
  return (out << head->link()); // recursively output everything else
}

// stubs for HW8 functions
// recursive function to return value of num in fibonnaci sequence
int f1(int n)
{
  // base case
  if (n < 2)
  {
    return 1;
  }

  return f1(n - 2) + n - 1;
}
// recursive reverse array function
void f2(int *a, int first, int last)
{
  // base case
  if (first >= last)
  {
    return;
  }
  // reverse once, call again until condition of base case met
  int temp = a[first];
  a[first] = a[last];
  a[last] = temp;
  f2(a, first + 1, last - 1);
}

void f3(node *&head, node *&tail, int *a, int n)
{
  // base case
  if (n == 0)
  {
    return;
  }
  head = new node(a[n - 1], head);
  if (tail == nullptr)
  {
    tail = head;
  }
  f3(head, tail, a, n - 1);
}
void f5(node *&head, node *&tail, int *a)
{
  if (head == nullptr)
    return;
  tail = head;
  node *temp = head->link();
  temp->set_link(head);
  head = temp;
  f5(head, tail, a);
}
// OLD IMPLEMENTATION
// create a new node for every element of the array
// node *newNode = new node(a[n - 1], nullptr);
// f3(head, tail, a, n - 1);
// // if the list was empty, assign head & tail to the newly created node
// if (head == nullptr)
// {
//   head = newNode;
//   tail = newNode;
// }
// // link prev node to new node using tail pointer, reset tail
// else
// {
//   tail->set_link(newNode);
//   tail = newNode;
// }

// recursive function to delete memory of all nodes
void f4(node *&head, node *&tail)
{
  // base case checks to see if head is pointing to a nullptr.
  // if so list is empty & set tail to null ptr as well.
  if (head == nullptr)
  {
    tail = nullptr;
    return;
  }
  // create a temp node to hold the current value of head.
  node *temp = head;
  // assign head to next node in list
  head = head->link();
  // delete old head
  delete temp;
  f4(head, tail);
}