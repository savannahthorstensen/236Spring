// programer: Savannah Thorstensen

/*
Modify your previous assignment "Programming: Arrays" to use an STL vector of doubles for grades,
instead of an array of doubles, to achieve the same functionality. Use accumulate() function from
STL numeric library to calculate sum of all double values in the vector. Use sort() function to sort
grades in ascending order. Display the sorted grades.
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
    vector<double> grades;
    int count = 0;
    double average, input;

    cout << "Enter your number grades (enter negative value to stop): " << endl;

    while (count < 100)
    {
        cin >> input;

        if (input < 0)
        {
            break;
        }

        grades.push_back(input);
        count++;
    }

    if (count == 0)
    {
        cout << "No grades entered." << endl;
        return 0;
    }
    double sum = accumulate(grades.begin(), grades.end(), 0.0);
    average = sum / count;

    cout << "sum: " << sum << endl;
    cout << "average: " << average << endl;

    sort(grades.begin(), grades.end());
    cout << "Sorted grades in ascending order:" << endl;

    for (int i = 0; i < count; i++)
    {
        cout << grades[i] << endl;
    }

    cout << "Grades with letter and below average with star:" << endl;

    for (int i = 0; i < count; i++)
    {
        if (grades[i] < average)
        {
            cout << "* ";
        }

        cout << grades[i] << " ";

        if (grades[i] >= 90)
            cout << "A";
        else if (grades[i] >= 80)
            cout << "B";
        else if (grades[i] >= 70)
            cout << "C";
        else if (grades[i] >= 60)
            cout << "D";
        else
            cout << "F";

        cout << endl;
    }

    return 0;
}