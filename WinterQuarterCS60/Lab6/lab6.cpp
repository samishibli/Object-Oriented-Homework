#include <iostream>
using namespace std;

template <typename T>
int count_exact(T a[], int size, T find)
{
    int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (a[i] == find)
            count++;
    }
    return count;
}
template <typename T>
int count_range(T a[], int size, T low, T high)
{
    int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (a[i] >= low && a[i] <= high)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int arr[] = {6, 2, 3, 2, 6, 2};
    int size = 6;
    string strArr[] = {"hello", "calvin", "has", "no", "drip", "i", "repeat", "no", "drip"};
    int strSize = 9;
    string strFind = "drip";
    string strFindAlso = "i";

    cout << count_exact(arr, size, 2) << endl;
    cout << count_exact(strArr, strSize, strFind) << endl;
    cout << count_range(arr, size, 2, 4) << endl;
    cout << count_range(strArr, strSize, strFind, strFindAlso) << endl;
}