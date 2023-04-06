#include <iostream>
#include "Lab6.h"
using namespace std;

int main()
{
    int arr[] = {1, 3, 4, 5, 3};
    string strArr[] = {"hello", "my", "name", "is", "sami"};
    npoint<int> n1;
    npoint<int> n2(5);
    npoint<int> n3(5, arr);
    npoint<string> n4(5, strArr);
}