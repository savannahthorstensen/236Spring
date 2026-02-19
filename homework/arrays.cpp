// programer: Savannah Thorstensen
#include <iostream>
using namespace std;

int main()
{
    double grades[100];
    int count = 0;
    double sum = 0, average, input;

    cout << "Enter your number grades (enter negative value to stop): " << endl;

    while (count < 100)
    {
        cin >> input;

        if (input < 0)
        {
            break;
        }
        grades[count] = input;
        sum += input;
        count++;
    }

    if (count == 0)
    {
        cout << "No grades entered." << endl;
        return 0;
    }
    average = sum / count;

    cout << "sum: " << sum << endl;
    cout << "average: " << average << endl;

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
