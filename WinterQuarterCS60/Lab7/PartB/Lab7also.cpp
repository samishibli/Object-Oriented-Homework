#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class StudentInfo
{
public:
    StudentInfo() : gradePointAvg(0.0) {}
    StudentInfo(string first, string last, string grade, double gpa)
    {
        first = firstName;
        last = lastName;
        grade = gradeLevel;
        gpa = gradePointAvg;
    }
    string getFirstname() { return firstName; }
    string getLastName() { return lastName; }
    string getGradeLevel() { return gradeLevel; }
    double getGradePointAvg() { return gradePointAvg; }

private:
    string firstName;
    string lastName;
    string gradeLevel;
    double gradePointAvg;
};

int main()
{
    ifstream file("studentlist.txt");
    vector<StudentInfo> v;
    if (file.is_open())
    {
        while (!file.eof())
        {
            StudentInfo student;
        }
        cin >> getline(StudentInfo.getFirstName(), StudentInfo.getLastName()) >> StudentInfo.getGradeLevel >> StudenInfo.getGradePointAvg;
        file.close();
    }
    cout << v << endl;

    return 0;
}
// if (infile.is_open()) {
//         while (!infile.eof()) {
//             Person person;

//             infile >> person.name >> person.age >> person.gender;

//             if (!person.name.empty()) { // Check if name is not empty
//                 people.push_back(person);
//             }
//         }

//         infile.close();

//         // Do something with the people vector...
//     }
