//*****************************************************************************************************
//
//     File:               Assignment 9.cpp
//
//     Student:            Muazuddin Mohammed
//
//     Assignment:         Assignment#9
//
//     Course Name:        Computer Programming #2
//
//     Course Number:      COSC 1560
//
//     Due:                November 13, 2023
//
//
//     This program enables people to learn how to translate from American to English
//     using file i/o and structures.
//
//*****************************************************************************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NAME_SIZE = 20;

struct Translation
{
    string american; // A word in American
    string english; // The equivalent (proper) word in English
};
struct Date
{
    int day;
    int month;
    int year;
};
struct Person
{
    char name [NAME_SIZE]; // Note that we are using ‘c-string’, not ‘string’
    double score;
    Date testTaken;
};

Translation* readTranslation (const string& filename, int& num);
Person* readTesters (const string& filename, int& num);
void testingOptions (const Translation t [], int numT, Person people [], int numP);
void takeTest (const Translation t [], int numT, Person& p);
void displayTesters (const Person p [], int numP);
void writeTesters (const string& filename, const Person p [], int numP);

//*****************************************************************************************************

int main()
{
    string fileTransl = "Translation.txt",
           fileTesters = "Testers.txt";
    int numTranslation,
        numTesters;
    Translation * transl = nullptr;
    Person * testers = nullptr;

    transl = readTranslation (fileTransl, numTranslation);
    testers = readTesters (fileTesters, numTesters);

    testingOptions (transl, numTranslation, testers, numTesters);

    displayTesters (testers, numTesters);

    writeTesters (fileTesters, testers, numTesters);

    return 0;
}

//*****************************************************************************************************

Translation* readTranslation (const string& filename, int& num)
{
    Translation * translations = nullptr; 
    fstream f;

    f.open (filename, ios::in);

    if (f)
    {
        f >> num;

        translations = new Translation [num];

        for (int i = 0; i < num; i++)
        {
            getline (f, translations [i].american, ',');
            getline (f, translations [i].english, ',');
            f.ignore ();
        }
    }
    else
    {
        cout << "File not open";
    }
    f.close ();

    return translations;
}

//*****************************************************************************************************

Person* readTesters (const string& filename, int& num)
{
    Person * testersArray = nullptr;
    string tempScore;
    fstream f;

    f.open (filename, ios::in);

    if (f)
    {
        f >> num;

        testersArray = new Person [num];

        for (int i = 0; i < num; i++)
        {
            f.ignore ();
            f.getline (testersArray [i].name, NAME_SIZE);

            getline (f, tempScore, ',');
            testersArray [i].score = stod(tempScore);

            f >> testersArray [i].testTaken.month;
            f.ignore ();

            f >> testersArray [i].testTaken.day;
            f.ignore ();

            f >> testersArray [i].testTaken.year;
        }

    }
    else
    {
        cout << "File not open";
    }

    f.close ();

    return testersArray;

}

//*****************************************************************************************************

void testingOptions (const Translation t[], int numT, Person people[], int numP)
{
    short seed = time (0);
    string tempMonth,
           tempDay,
           tempYear;
    int randNum;

    srand (seed);

    cout << "Enter the current date MM/DD/YYYY: ";
    getline (cin, tempMonth, '/');
    getline (cin, tempDay, '/');
    getline (cin, tempYear);

    for (int i = 0; i < 3; i++)
    {
        randNum = rand () % (numP);

        takeTest(t, numT, people [randNum]);

        people [randNum].testTaken.month = stoi (tempMonth);
        people [randNum].testTaken.day = stoi (tempDay);
        people [randNum].testTaken.year = stoi (tempYear);
    }
}

//*****************************************************************************************************

void takeTest(const Translation t[], int numT, Person& p)
{
    short seed = time (0);
    int qNum,
        correct = 0;
    string ans;
    srand (seed);

    cout << "Testing: " << p.name << endl << endl;

    for (int i = 0; i < 5; i++)
    {
        qNum = rand () % (numT + 1);

        cout << "\nWhat is the equivalent of \"" << t [qNum].american << "\" in English?";
        cin >> ans;

        if (ans == t [qNum].english)
        {
            correct++;
            cout << "Correct! The next question is: " << endl;
        }
        else
        {
            cout << "Incorrect! The next question is: " << endl;
        }
    }

    p.score = (static_cast <double> (correct)) / 5;
}

//*****************************************************************************************************

void displayTesters(const Person p[], int numP)
{
    cout << left << setw (20) << "NAME:"
         << setw (5) << "SCORE:"
         << setw (20) << "LAST TEST TAKEN:" << endl;

    for (int i = 0; i < numP; i++)
    {
        cout << left << setw (20) << p [i].name
             << setw (5) << p [i].score;

        cout << right << setfill('0') << setw(2) << p[i].testTaken.month << "/"
                << setw(2) << p[i].testTaken.day << "/"
                << setw(2) << p[i].testTaken.year << setfill(' ') << endl;
    }
}

//*****************************************************************************************************

void writeTesters(const string& filename, const Person p[], int numP)
{
    fstream f;

    f.open(filename, ios::out);

    if (f)
    {
        f << numP << endl;

        for (int i = 0; i < numP; i++)
        {
            f << p [i].name << endl
              << p [i].score << ","
              << p [i].testTaken.month << "/"
              << p [i].testTaken.day << "/"
              << p [i].testTaken.year << endl;
        }
    }
    else
    {
        cout << "File not open";
    }
    f.close();
}

//*****************************************************************************************************

/*
 Unable to Run file for some reason
 */
