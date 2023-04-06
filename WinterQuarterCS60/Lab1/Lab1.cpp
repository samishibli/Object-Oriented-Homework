#include <iostream>
using namespace std;

int findMax(int arr[], int size)
{

    int maxNum = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > maxNum)
        {
            maxNum = arr[i];
        }
    }
    return maxNum;
}
void swap(int arr[], int size)
{
    int max = findMax(arr, size);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == max)
        {
            arr[i] = arr[size - 1];
            arr[size - 1] = max;
        }
    }
}
void swapTwice(int arr[], int size)
{
    for (int j = 0; j < 2; j++)
    {
        int max = findMax(arr, size);
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == max)
            {
                arr[i] = arr[size - 1];
                arr[size - 1] = max;
            }
        }
        size--;
    }
}
void swapAll(int arr[], int size)
{
    int max = findMax(arr, size);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == max)
        {
            arr[i] = arr[size - 1];
            arr[size - 1] = max;
        }
        size--;
        if (size > 1)
        {
            swapAll(arr, size);
        }
    }
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
}

int main()
{
    int arr[] = {1, 5, 9, 12, 3, 4};
    int size = 6;

    cout << findMax(arr, size) << endl;
    swap(arr, size);
    printArr(arr, size);
    cout << endl;
    swapTwice(arr, size);
    printArr(arr, size);
    cout << endl;
    swapAll(arr, size);
    printArr(arr, size);
}