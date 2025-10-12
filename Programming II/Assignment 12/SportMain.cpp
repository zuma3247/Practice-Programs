//*****************************************************************************************************
//
//     File:               Assignment 12.cpp
//
//     Student:            Muazuddin Mohammed
//
//     Assignment:         Assignment#12
//
//     Course Name:        Computer Programming #2
//
//     Course Number:      COSC 1560
//
//     Due:                Dec 8, 2023
//
//     This program uses classes to store and display information about sports using a menu.
//
//*****************************************************************************************************

#include "Sport.cpp"
#include <iostream>
using namespace std;

void averageNumTeams(const Sport sports[], int size);

//*****************************************************************************************************

int main ()
{
    int numSports = 0;
    Sport * sports = nullptr;

    cout << "Enter the number of Sports: " << endl;
    cin >> numSports;

    sports = new Sport [numSports];

    for (int i = 0; i < numSports; i++)
    {
        sports[i].populateSport();
    }

    for (int i = 0; i < numSports; i++)
    {
        sports[i].displaySportInfo();
    }

    averageNumTeams (sports, numSports);

    return 0;
}

//*****************************************************************************************************

void averageNumTeams(const Sport sports[], int size)
{
    int totalTeams = sports [0].getNumTeams();
    double average = 0;

    for (int i = 0; i < size; i++)
    {
        totalTeams += sports [i].getNumTeams();
    }

    average = static_cast<double>(totalTeams) / size;

    cout << "The average number of teams is: " << average << endl;
}

//*****************************************************************************************************


