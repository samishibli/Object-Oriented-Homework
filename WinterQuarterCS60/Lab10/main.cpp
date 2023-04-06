#include "bag10-1.h"
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = 9;
    bag<int> b1(arr, size);

    for (bag<int>::iterator it = b1.begin(); it != b1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    for (auto e : b1)
    {
        cout << e << " ";
    }
}