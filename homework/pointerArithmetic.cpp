/* Savannah Thorstensen

a) Write a program that has a declaration in main() to store the following numbers
in an array named rates: 6.5, 7.2, 7.5, 8.3, 8.6, 9.4, 9.6, 9.8, and 10.0. Include a function call to
show() that accepts rates in a parameter named rates and then displays the numbers by
using the pointer notation *(rates + i).

b) Modify the show() function written in Exercise 6a to alter the address in rates. Always
use the expression *rates rather than *(rates + i) to retrieve the correct element.
*/

#include <iostream>
using namespace std;

// prototypes
void showA(double *rates, int size); // part a
void showB(double *rates, int size); // part b

int main()
{
    double rates[] = {6.5, 7.2, 7.5, 8.3, 8.6, 9.4, 9.6, 9.8, 10.0};
    int size = sizeof(rates) / sizeof(rates[0]);

    cout << "part a: ";
    showA(rates, size);
    cout << "part b: ";
    showB(rates, size);

    return 0;
}

// part a
void showA(double *rates, int size)
{
    for (int i = 0; i < size; i++){
        cout << *(rates + i) << " " ;
    }
    cout << endl;
}

// part b
void showB(double *rates, int size)
{
    for (int i = 0; i < size; i++){
        cout << *rates << " ";
        rates++;
    }
    cout << endl;
}
