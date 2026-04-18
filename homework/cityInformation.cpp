//Programer: Savannah Thorstensen
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

struct City {
    string name;
    long population;
    string mayor;
};

bool compareByName(const City& a, const City& b) {
    string nameA = a.name, nameB = b.name;
    for (int i = 0; i < (int)nameA.size(); i++)
        nameA[i] = tolower(nameA[i]);
    for (int i = 0; i < (int)nameB.size(); i++)
        nameB[i] = tolower(nameB[i]);
    return nameA < nameB;
}




int main() {
    //part a: accept city data from keyboard and save to file

    ofstream outFile("cities.txt");
    if (!outFile) {
        cout << "error opening file for writing." << endl;
        return 1;
    }

    int numCities;
    cout << "enter a number of cities: ";
    cin >> numCities;
    cin.ignore();

    for (int i = 0; i < numCities; i++) {
        string name, mayor;
        long population;

        cout << "\ncity " << (i + 1) << ":\n";

        cout << "  Name: ";
        getline(cin, name);

        cout << "  Population: ";
        cin >> population;
        cin.ignore();

        cout << "  Mayor: ";
        getline(cin, mayor);

        outFile << name << "\n" << population << "\n" << mayor << "\n";
    }

    outFile.close();
    cout << "\nsaved to cities.txt\n";

    //part b: read file sort alphabetically and display

    ifstream inFile("cities.txt");
    if (!inFile) {
        cout << "error opening file \n";
        return 1;
    }

    vector<City> cities;
    City c;

    while (getline(inFile, c.name)) {
        inFile >> c.population;
        inFile.ignore();
        getline(inFile, c.mayor);
        cities.push_back(c);
    }

    inFile.close();

    sort(cities.begin(), cities.end(), compareByName);
    cout << "city's sorted alphabetically \n";
    for (int i = 0; i < (int)cities.size(); i++) {
        cout << "City:       " << cities[i].name       << "\n"
             << "Population: " << cities[i].population << "\n"
             << "Mayor:      " << cities[i].mayor      << "\n"
             <<"--------------------------------------"<< "\n";
    }


    return 0;
}