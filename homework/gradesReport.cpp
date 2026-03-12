/*
Programer: Savannah Thorstensen

create a program that creates a student grade report
grade report fpr each student should include: student name, id, courses taken,
credits, letter grade, and semester gpa
*/

#include <iostream>
#include <fstream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("/Users/savannah/Desktop/236Spring/236Spring/homework/grades.dat");

    if (inFile.fail())
    {
        cout << "error could not open";
        return 1;
    }

    cout << fixed << setprecision(2);

    int id, currentID, credits, totalCredits = 0;
    char grade;
    double totalPoints = 0;
    string first, last, courseCode;

    inFile >> id >> first >> last >> courseCode >> credits >> grade;
    currentID = id;

    cout << "student name: " << first << " " << last << endl;
    cout << "id number: " << id << endl;
    cout << "Course | Credits | Grade" << endl;

    while (!inFile.eof())
    {

        if (id != currentID)
        {
            cout << "Total Credits: " << totalCredits << endl;
            cout << "GPA: " << totalPoints / totalCredits << endl
                 << endl;

            totalCredits = 0;
            totalPoints = 0;

            currentID = id;

            cout << "student name: " << first << " " << last << endl;
            cout << "id number: " << id << endl;
            cout << "Course | Credits | Grade" << endl;
        }

        cout << courseCode << "       " << credits << "        " << grade << endl;

        int value;
        if (grade == 'A')
            value = 4;
        else if (grade == 'B')
            value = 3;
        else if (grade == 'C')
            value = 2;
        else if (grade == 'D')
            value = 1;
        else
            value = 0;

        totalCredits += credits;
        totalPoints += value * credits;

        inFile >> id >> first >> last >> courseCode >> credits >> grade;
    }

    cout << "Total Credits: " << totalCredits << endl;
    cout << "GPA: " << totalPoints / totalCredits << endl;

    inFile.close();
    return 0;
}
