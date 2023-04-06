#include <iostream>
using namespace std;

void max_avg(int a[], int size, int *max, int *avg)
{
    int maxNum;
    int avgNum;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        maxNum = a[0];
        if (a[i] > maxNum)
        {
            maxNum = a[i];
        }
        sum += a[i];
        avgNum = sum / size;
    }
    *max = maxNum;
    *avg = avgNum;
}

int main()
{
    int arr[] = {11, 13, 15, 17};
    int size = 4;
    int x = 0;
    int y = 0;

    int *max = &x;
    int *avg = &y;

    max_avg(arr, size, max, avg);
    cout << &max << endl;
    cout << &avg << endl;
    cout << *max << endl;
    cout << *avg << endl;
    cout << x << endl;
    cout << y << endl;

    return 0;
}