#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    ifstream file("scores.txt");
    vector<int> v;
    int number;
    while (file >> number)
    {
        v.push_back(number);
    }
    int sum = 0;
    int avg = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        avg = sum / v.size();
    }
    file.close();

    ofstream otherFile("newScores.txt");
    otherFile << avg << endl;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > avg)
        {
            otherFile << v[i] << endl;
        }
    }
    otherFile.close();
}