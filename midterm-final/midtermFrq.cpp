/******************************************************************************
Write a C++ program, in space given below, that implements following functionality:
1. Uses a Dynamic Array (2 pts):
2. Gets the absolute filepath (containing data) from the user (1 pt)
3. Reads integer data, separated by spaces, given in the file on the first line - the first integer gives
the count of valid values and as many integer values follow (3 pts)
4. Implements a function that counts and returns the number of odd & even integer values (3 pts)
5. Implements a function that calculates and returns the average of all integer values (2 pts)
6. Prints on screen and writes back to the same file - original data on first line, odd/even count on
second line and average on third line (3 pts)
7. Handles any potential exceptions e.g. unable to read or write the file (1 pt)
Hint: For testing your program create a file test-data.txt with following on first line:
10 34 23 76 12 81 6 123 43 1 49
*******************************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

// Function to count even and odd numbers
// Uses reference parameters so both values can be returned
void countEvenOdd(int data[], int size, int &evenCount, int &oddCount)
{
    evenCount = 0;
    oddCount = 0;

    for (int i = 0; i < size; i++) // loop through all elements in array
    {
        if (data[i] % 2 == 0) // check if number is even
        {
            evenCount++;
        }
        else
        {
            oddCount++;
        }
    }
}

double calculateAverage(int data[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)  // add all elements
    {
        sum += data[i];
    }
    double avg = sum / size;

    return avg;
}

int main()
{
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream inFile(filename);

    try
    {
        ifstream inFile(filename.c_str()); // open file again using C-style string

        if (inFile.fail())
        {
            throw 1; // breaks after this
        }

        int size;
        inFile >> size; // first value in file = number of elements

        int *data = new int[size]; // dynamically allocate array based on size

        for (int i = 0; i < size; i++)
        {
            inFile >> data[i]; // read each number from the file
        }
        inFile.close(); // close input file after reading

        int evenCount = 0, oddCount = 0, avg = 0;
        countEvenOdd(data, size, evenCount, oddCount);
        avg = calculateAverage(data, size);

        // output to file
        ofstream outFile(filename.c_str());
        if (outFile.fail())
        {
            throw 2; // breaks after this
        }

        cout << size;
        outFile << size;

        for (int i = 0; i < size; i++)
        {
            cout << " " << data[i];
            outFile << " " << data[i];
        }
        cout << endl;
        outFile << endl;

        cout << evenCount << " " << oddCount << endl;
        outFile << evenCount << " " << oddCount << endl;

        cout << avg << endl;
        outFile << avg << endl;

        delete[] data; // free dynamically allocated memory
        outFile.close();
    }
    catch (int e)
    {
        // handle errors
        if (e == 1)
        {
            cout << "Error: could not open file for input" << endl;
        }
        else if (e == 2)
        {
            cout << "Error: could not open file for output" << endl;
        }
    }

    return 0;
}
