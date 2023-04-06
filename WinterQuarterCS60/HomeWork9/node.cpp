// Node implementation starter file for CSCI 60 Homework 9; due Sunday 3/12/23
// sami shibli
// implementation of list_insert_sorted

#include "node.h"

// overloaded << to print entire list
ostream &operator<<(ostream &out, const node *head)
{
  if (head == nullptr)
    return out;
  return out << head->data() << " " << head->link();
}

// inserts a node with specified value at the head (beginning/front) of a list
void list_insert_head(node *&head, node *&tail, int val)
{
  head = new node(val, head);
  if (tail == nullptr)
    tail = head;
}

// inserts a node with specified value at the tail (end/back) of a list
void list_insert_tail(node *&head, node *&tail, int val)
{
  // std::cout << val;
  node *temp = new node(val, nullptr);
  if (tail == nullptr)
  {
    head = tail = temp;
  }
  else
  {
    tail->set_link(temp);
    tail = tail->link();
  }
}

// iterates through list, keeping track of and then returning # nodes
size_t list_size(const node *head)
{
  if (head == nullptr)
    return 0;
  return 1 + list_size(head->link());
}

// iterates through list and returns true if given val is found, false otherwise
bool list_search(const node *head, int val)
{
  if (head == nullptr)
    return false;
  if (head->data() == val)
    return true;
  return list_search(head->link(), val);
}
void list_insert_sorted(node *&head, node *&tail, int val)
{
  node *prevNode = nullptr;
  node *temp = new node(val, nullptr);
  for (node *curr = head; head != nullptr; prevNode = curr, curr = curr->link())
  {
    if (curr->data() < val)
    {
      if (prevNode == nullptr)
      {
        head = temp;
        temp->set_link(curr);
      }
      else
      {
        prevNode->set_link(temp);
        temp->set_link(curr);
      }
      return;
    }
  }
  if (head == nullptr && tail == nullptr)
  {
    head = tail = temp;
  }
  else
  {
    tail->set_link(temp);
    tail = tail->link();
  }
}
// TODO: implement list_insert_sorted
// loop through & compare val to data of each node
// check at the head if val is < head->data() if true, node* newNOde = (val, head),
// void list_insert_sorted(node *&head, node *&tail, int val)
// {
//   node *prevNode = nullptr;
//   for (node *p = head; p != nullptr; prevNode = p, p = p->link())
//   {

//     if (val < p->data())
//     {
//       // create new node, and point to where p currently points
//       node *newNode = new node(val, p);
//       // edge case to see if were inserting at the head of list
//       if (prevNode == nullptr)
//       {
//         head = newNode;
//       }
//       else
//       {
//         prevNode->set_link(newNode);
//       }
//       return;
//     }
//   }
//   // edge case to insert at empty list
//   if (head == nullptr)
//   {
//     head = new node(val, nullptr);
//     tail = head;
//   }
//   // val is the greatest value of the list, insert at the end
//   else
//   {
//     node *newTailNode = new node(val, nullptr);
//     prevNode->set_link(newTailNode);
//     tail = newTailNode;
//   }
// }