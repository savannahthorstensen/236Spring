// programer: Savannah Thorstensen

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char ch;
    bool firstLetter = true;
    bool space = false;
    string invalidChars = "";

    cout << "enter a sentance with weird spaces and caps." << endl;

    while (cin.get(ch))
    {
        if (ch == '.')
        {
            cout << '.';
            break;
        }

        if (isalpha(ch)){ //is a letter
            if (firstLetter)
            {
                cout << (char)toupper(ch);
                firstLetter = false;
            }
            else
            {
                cout << (char)tolower(ch);
            }
            space = false;
        }
        else if (isspace(ch))
        {
            if (!space && !firstLetter)
            {
                cout << ' ';
                space = true;
            }
        }
        else {  // anything else invalid
            invalidChars += ch;
        }
    }

    cout << endl;

    if (!invalidChars.empty()) {
        cout << "Ignored characters: " << invalidChars << endl;
    } else {
        cout << "no invalid characters: " << endl;
    }

    return 0;
}