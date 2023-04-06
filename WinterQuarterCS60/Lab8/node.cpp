#include "node.h"
#include <iostream>
using namespace std;

std::size_t list_index(node *head_ptr, int target)
{
    int counter = 0;
    for (const node *p = head_ptr; p != nullptr; p = p->link())
    {
        if (p->data() = target)
            return counter;
        else
            counter++;
    }
}

node *list_at(node *head_ptr, std::size_t n)
{
    int counter = 0;
    for (const node *p = head_ptr; p != nullptr; p = (*p).link()))
        {
            if (counter = n)
            {
                return p;
            }
            counter++;
        }
}
double water(int n)
{
    if (n == 0)
        return 10;
    else
    {
        return .5 * water(n - 1) + 1.0;
    }
}
bool is_sorted(int a[], int n)
{
    if (n <= 1)
    {
        return true;
    }
    return (isSorted(a, n - 1) && (a[n - 1] >= a[n - 2]));
}

// You’re carrying out a rather odd experiment. You get a big bucket, and you start with 10 gallons of water.
//  Every day, you pour out half the water, then add another gallon.  So after 1 day you have 6 gallons of water.
//  Write a recursive function double water(int n) that returns the amount of water you have after n days.
//   Test your function in your main().  Copy your code into your lab report.
//   Be sure to get your work checked initialed before moving on.
