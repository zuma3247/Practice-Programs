//*****************************************************************************************************
//
//     File:               Assignment 11.cpp
//
//     Student:            Muazuddin Mohammed
//
//     Assignment:         Assignment#11
//
//     Course Name:        Computer Programming #2
//
//     Course Number:      COSC 1560
//
//     Due:                November 29, 2023
//
//     This program uses classes to store and display information about sports using a menu.
//
//*****************************************************************************************************

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

class Sport
{
    private:
        string sportName;
        Date nextGameDate;
        int numTeams;

    public:
    string getSportName() const;
    void setSportName (const string& name);
    Date getNextGameDate() const;
    void setNextGameDate(const Date& date);
    int getNumTeams() const;
    void setNumTeams(int teams);
    void displaySportInfo() const;
    void populateSport();
};

//*****************************************************************************************************

string Sport::getSportName() const
{
    return sportName;
}

//*****************************************************************************************************

void Sport::setSportName (const string& name)
        {
            sportName = name;
        }

//*****************************************************************************************************

Date Sport::getNextGameDate() const
{
    return nextGameDate;
}

//*****************************************************************************************************

void Sport::setNextGameDate(const Date& date)
{
    nextGameDate = date;
}

//*****************************************************************************************************

int Sport::getNumTeams() const
{
    return numTeams;
}

//*****************************************************************************************************

void Sport::setNumTeams(int teams)
{
    numTeams = teams;
}

//*****************************************************************************************************

void Sport::displaySportInfo() const
{
    cout << "Sport: " << sportName << endl;
    cout << "Next Game Date: " << nextGameDate.day
         << "/" << nextGameDate.month << "/"
         << nextGameDate.year << endl;
    cout << "Number of Teams: " << numTeams << endl << endl;
}

//*****************************************************************************************************

void Sport::populateSport()
{
    cout << "Enter Sport Name: ";
    cin.ignore();
    getline (cin, sportName);

    cout << "Enter Next Game Date (DD MM YYYY): ";
    cin >> nextGameDate.day >> nextGameDate.month
        >> nextGameDate.year;

    cout << "Enter Number of Teams: ";
    cin >> numTeams;
    cout << endl;
}

//*****************************************************************************************************

void displayAverageTeams(const Sport sports[], int size);
void sportOperations(Sport sports[], int size);
void displayEarliestGame(const Sport sports[], int size);

//*****************************************************************************************************

int main()
{
    const int SIZE = 3;
    Sport sports[SIZE];

    sportOperations(sports, SIZE);

    return 0;
}

//*****************************************************************************************************

void displayAverageTeams(const Sport sports[], int size)
{
    int totalTeams = 0;
    for (int i = 0; i < size; ++i)
    {
        totalTeams += sports[i].getNumTeams();
    }

    double averageTeams = static_cast <double> (totalTeams) / size;

    cout << "Average Number of Teams: " << fixed << setprecision(2) << averageTeams << endl;
}

//*****************************************************************************************************

void displayEarliestGame(const Sport sports[], int size)
{
    int earliestIndex = 0;
    Date date1,
         date2;

    for (int i = 1; i < size; ++i)
    {
        date1 = sports[i].getNextGameDate();
        date2 = sports[earliestIndex].getNextGameDate();

        if (date1.year < date2.year)
        {
            earliestIndex = i;
        }
        else if (date1.month < date2.month)
        {
            earliestIndex = i;
        }
        else if (date1.day < date2.day)
        {
            earliestIndex = i;
        }
    }

    cout << "Sport with Earliest Game: " << sports[earliestIndex].getSportName() << endl;
}

//*****************************************************************************************************

void sportOperations(Sport sports[], int size)
{
    char option;

    do
    {
        cout << endl << "Options:" << endl
             << "a) Populate all sports" << endl
             << "b) Display all sports" << endl
             << "c) Populate a particular sport" << endl
             << "d) Display a particular sport" << endl
             << "e) Display average number of teams" << endl
             << "f) Display sport with earliest game" << endl
             << "g) Quit" << endl << endl
             << "Enter your choice (a-g): ";
        cin >> option;

        switch (option)
        {
            case 'a':
                for (int i = 0; i < size; ++i)
                {
                    sports[i].populateSport();
                }
                break;

            case 'b':
                for (int i = 0; i < size; ++i)
                {
                    sports[i].displaySportInfo();
                }
                break;

            case 'c':
                int indexToPopulate;
                cout << "Enter the index of the sport to populate: ";
                cin >> indexToPopulate;

                if (indexToPopulate >= 0 && indexToPopulate < size)
                {
                    sports[indexToPopulate].populateSport();
                }
                else
                {
                    cout << "Invalid index!" << endl;
                }
                break;

            case 'd':
                int indexToDisplay;
                cout << "Enter the index of the sport to display: ";
                cin >> indexToDisplay;

                if (indexToDisplay >= 0 && indexToDisplay < size)
                {
                    sports[indexToDisplay].displaySportInfo();
                }
                else
                {
                    cout << "Invalid index!" << endl;
                }
                break;

            case 'e':
                displayAverageTeams(sports, size);
                break;

            case 'f':
                displayEarliestGame(sports, size);
                break;

            case 'g':
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid option. Please try again.\n";
        }
    }
    while (option != 'g');
}

/*
"/Users/mac/Desktop/Webster/Studies/COSC 1560 - Pro 2/Assignment 11/cmake-build-debug/Assignment_11"

Options:
a) Populate all sports
b) Display all sports
c) Populate a particular sport
d) Display a particular sport
e) Display average number of teams
f) Display sport with earliest game
g) Quit

Enter your choice (a-g): a
Enter Sport Name: a
Enter Next Game Date (DD MM YYYY): 11 11 1111
Enter Number of Teams: 2

Enter Sport Name: b
Enter Next Game Date (DD MM YYYY): 22 22 2222
Enter Number of Teams: 4

Enter Sport Name: c
Enter Next Game Date (DD MM YYYY): 10 11 1111
Enter Number of Teams: 6


Options:
a) Populate all sports
b) Display all sports
c) Populate a particular sport
d) Display a particular sport
e) Display average number of teams
f) Display sport with earliest game
g) Quit

Enter your choice (a-g): b
Sport: a
Next Game Date: 11/11/1111
Number of Teams: 2

Sport: b
Next Game Date: 22/22/2222
Number of Teams: 4

Sport: c
Next Game Date: 10/11/1111
Number of Teams: 6


Options:
a) Populate all sports
b) Display all sports
c) Populate a particular sport
d) Display a particular sport
e) Display average number of teams
f) Display sport with earliest game
g) Quit

Enter your choice (a-g): f
Sport with Earliest Game: c

Options:
a) Populate all sports
b) Display all sports
c) Populate a particular sport
d) Display a particular sport
e) Display average number of teams
f) Display sport with earliest game
g) Quit

Enter your choice (a-g):
 */

