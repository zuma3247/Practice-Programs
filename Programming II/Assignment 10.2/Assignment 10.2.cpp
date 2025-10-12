//*****************************************************************************************************
//
//     File:               Assignment 10.2.cpp
//
//     Student:            Muazuddin Mohammed
//
//     Assignment:         Assignment#10
//
//     Course Name:        Computer Programming #2
//
//     Course Number:      COSC 1560
//
//     Due:                November 20, 2023
//
//
//     This program enables people to learn how to translate from American to English
//     using binary files and structures.
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
void testersUpdates(const Translation t[], int numT, const string& fileName);
void takeTest (const Translation t [], int numT, Person& p);
void displayTesters(const string& fileName);
void showStruct (Person tester);


//*****************************************************************************************************

int main()
{
    string fileTransl = "Translation.txt",
           binFile = "Testers.dat";
    int numTranslation,
        numTesters;
    Translation * transl = nullptr;

    transl = readTranslation (fileTransl, numTranslation);
    testersUpdates (transl, numTesters, binFile);
    displayTesters (binFile);

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

        cout << "Translations entered successfully" << endl;
    }
    else
    {
        cout << "File not open";
    }
    f.close ();

    return translations;
}

//*****************************************************************************************************

void testersUpdates (const Translation t[], int numT, const string& fileName)
{
    int numP,
        randNum;
    Person * people = nullptr;
    short seed = time (0);
    string tempMonth,
            tempDay,
            tempYear;
    fstream f (fileName, ios:: in | ios ::out | ios:: binary);
    srand (seed);

    f.read (reinterpret_cast <char *> (&numP), sizeof (numP));

    people = new Person [numP];

    cout << "Enter the current date MM/DD/YYYY: ";
    getline (cin, tempMonth, '/');
    getline (cin, tempDay, '/');
    getline (cin, tempYear);

    for (int i = 0; i < 3; i++)
    {
        randNum = (rand () % numP) + 1;

        f.seekg (sizeof(int) + sizeof (Person) * (randNum - 1), ios :: beg);
        f.read (reinterpret_cast <char *> (&people [randNum - 1]), sizeof (Person));

        takeTest(t, numT, people [randNum - 1]);

        people [randNum - 1].testTaken.month = stoi (tempMonth);
        people [randNum - 1].testTaken.day = stoi (tempDay);
        people [randNum - 1].testTaken.year = stoi (tempYear);

        f.seekp (sizeof(int) + sizeof (Person) * (randNum - 1), ios :: beg);
        f.write (reinterpret_cast <char *> (&people [randNum - 1]), sizeof (Person));
    }

    f.close();
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

void displayTesters(const string& fileName)
{
    fstream f (fileName, ios::in | ios::binary);
    int num;
    Person tester;

    if (f)
    {
        f.read (reinterpret_cast <char *> (&num), sizeof (num));

        cout << endl << "Testers: " << endl << endl;

        for (int i = 0; i < num; i++)
        {
            f.read (reinterpret_cast <char *> (&tester), sizeof (tester));
            showStruct (tester);
        }
    }
    else
    {
        cout << "File not open";
    }
    f.close ();

}

//*****************************************************************************************************

void showStruct (Person tester)
{
    cout << left << setw (NAME_SIZE) << "NAME:"
         << setw (NAME_SIZE) << tester.name << endl;

    cout << setw (NAME_SIZE) << "SCORE:"
         << setw (NAME_SIZE) << tester.score << endl;

    cout << setw (NAME_SIZE) << "TEST TAKEN:"
         << right << setfill('0') << setw(2) << tester.testTaken.month << "/"
         << setw(2) << tester.testTaken.day << "/"
         << setw(2) << tester.testTaken.year << setfill(' ') << endl << endl;
}

//*****************************************************************************************************






