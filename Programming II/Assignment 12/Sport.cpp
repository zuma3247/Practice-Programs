//Sport.cpp

#include "Sport.h"
#include <iostream>

using namespace std;

void isValidDate(int& month, int& day, int& year);

//*****************************************************************************************************

void Sport::displaySportInfo() const
{
    cout << "Sport: " << getSportName() << endl;
    cout << "Next Game Date: " << nextGameDate.day
         << "/" << nextGameDate.month << "/"
         << nextGameDate.year << endl;
    cout << "Number of Teams: " << getNumTeams() << endl;

    for (int i = 0; i < getNumTeams(); i++)
    {
        cout << "Name of Team " << i + 1 << ": " << teamName [i] << endl;
    }

    cout << endl;
}

//*****************************************************************************************************

void Sport::populateSport()
{
    cout << "Enter Sport Name: ";
    cin.ignore();
    getline (cin, sportName);
    setSportName(sportName);

    Sport(sportName);

    cout << "Enter Next Game Date (DD MM YYYY): ";
    cin >> nextGameDate.day >> nextGameDate.month
        >> nextGameDate.year;

    isValidDate(nextGameDate.day, nextGameDate.month, nextGameDate.year);
    setNextGameDate(nextGameDate);

    cout << "Enter Number of Teams: ";
    cin >> numTeams;
    cout << endl;

    if (numTeams < 0)
    {
        numTeams = 5;
    }

    for (int i = 0; i < numTeams; i++)
    {
        cout << "Enter the name of Team " << i + 1 << ": " << endl;
        cin >> teamName[i];
    }
    cout << endl;
}

//*****************************************************************************************************

void isValidDate(int& month, int& day, int& year)
{
    if (month < 1 || month > 12)
    {
        month = 1;
    }

    if (day < 1 || day > 30)
    {
        day = 1;
    }

    if (year < 2023 || year > 2033)
    {
        year = 2000;
    }
}

//*****************************************************************************************************


