// programer: Savannah Thorstensen
// 2/11/26

#include <iostream>
using namespace std;

int convertdays(int month, int day, int year);

int main()
{
    int month, day, year, result;

    cout << "Enter a month 1-12: " << endl;
    cin >> month;

    cout << "Enter a day 1-365: " << endl;
    cin >> day;

    cout << "Enter a year yyyy: " << endl;
    cin >> year;

    result = convertdays(month, day, year);
    cout << "converted date: " << result << endl;


    return 0;
}


int convertdays(int month, int day, int year)
{
    int date;
    date = year * 10000 + month * 100 + day;
    return date;
}
