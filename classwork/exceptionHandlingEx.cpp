#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

int main()
{
    while (true)
    {
        try
        {
            int i;
            cin >> i;
            int r = divide(i, 10);
            cout << r;
            break;
        }
        catch (int c)
        {
            if (c == 1)
            {
                cout << "error: divide by 0" << endl;
            }
        }
    }
    return 0;
}

int divide(int x, int y)
{
    if (x == 0)
    {
        throw invalid_argument("Cannot divide by 0");
        return y / x;
    }
}