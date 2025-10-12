//*****************************************************************************************************
//
//     File:               Assignment 3.1.cpp
//
//     Student:            Muazuddin Mohammed
//
//     Assignment:         Assignment#3
//
//     Course Name:        Computer Programming #2
//
//     Course Number:      COSC 1560
//
//     Due:                September 18, 2023
//
//
//     This program implements functions containing different search and sort algorithms.
//
//
//     Other files required:
//     1. StudentNames.txt – text file of Names
//
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int NUMNAMES = 10;

void readNames (const string& inputFile, string names []);
void displayNames (const string names [], int numNames);
int searchNames (const string names [], int numNames, const string& name);

void bubbleSort (string names [], int numNames);
void bubbleSortDescending (string names [], int numNames);

int binarySearchNames (const string names[], int numNames, const string& name);
void selectionSort (string names[], int numNames);
void selectionSortDescending(string names[], int numNames);

//*****************************************************************************************************

int main()
{
    int arrayIndex;
    string names [NUMNAMES],
            fileName = "StudentNames.txt",
            name;

    readNames (fileName, names);
    displayNames (names, NUMNAMES);

    cout << "Enter name to search: " << endl;
    getline (cin, name);
    arrayIndex = searchNames (names, NUMNAMES, name);
    cout << endl << "Array index is: " << arrayIndex << endl << endl;

    return 0;
}

//*****************************************************************************************************

void readNames(const string& inputFile, string names [])
{
    ifstream inputNames;
    inputNames.open (inputFile);

    if (inputNames)
    {
        for (int i = 0; i < NUMNAMES; i++)
        {
            getline (inputNames, names [i]);
        }
    }
    else
    {
        cout << "Error reading file" << endl;
    }
    inputNames.close();
}

//*****************************************************************************************************

void displayNames (const string names [], int numNames)
{
    for (int i = 0; i < numNames; i++)
    {
        cout << names[i] << endl;
    }
    cout << endl;
}

//*****************************************************************************************************

int searchNames (const string names [], int numNames, const string& name)
{
    int index = -1;

    for (int i = 0; i < numNames; i++)
    {
        if (names [i] == name)
        {
            index = i;
        }
    }

    return index;
}

//*****************************************************************************************************

void bubbleSort (string names[], int numNames)
{
    char letter1,
            letter2;
    string temp,
            firstName,
            nextName;

    for (int i = 0; i < (numNames - 1); i++)
    {
        for (int count = 0; count < (numNames - i - 1); count++)
        {
            firstName = names[count];
            nextName = names[count + 1];

            letter1 = firstName[0];
            letter2 = nextName[0];

            if (letter1 >= letter2)
            {
                temp = names[count];
                names[count] = names[count + 1];
                names[count + 1] = temp;
            }
        }
    }
}

//*****************************************************************************************************

void bubbleSortDescending (string names [], int numNames)
{
    char letter1,
            letter2;
    string temp,
            firstName,
            nextName;

    for (int i = 0; i < (numNames - 1); i++)
    {
        for (int count = 0; count < (numNames - i - 1); count++)
        {
            firstName = names [count];
            nextName = names [count + 1];

            letter1 = firstName [0];
            letter2 = nextName [0];

            if (letter1 <= letter2)
            {
                temp = names[count];
                names [count] = names[count + 1];
                names [count + 1] = temp;
            }
        }
    }
}

//*****************************************************************************************************

int binarySearchNames (const string names[], int numNames, const string& name)
{
    int first = 0,
        last = numNames - 1,
        middle,
        position = -1;

    bool found = false;

    while ( (!found ) && ( first <= last) )
    {
        middle = (first + last) / 2;

        if (names [middle] == name)
        {
            found = true;
            position = middle;
        }
        else
        {
            if (names [middle] > name)
            {
                last = middle - 1;
            }
            else
            {
                first = middle + 1;
            }
        }
    }

    return position;
}

//*****************************************************************************************************

void selectionSort (string names[], int numNames)
{
    int minIndex;
    string minValue;

    for (int startScan = 0; startScan < (numNames - 1); startScan++)
    {
        minIndex = startScan;
        minValue = names [minIndex];

        for (int index = startScan + 1; index < numNames; index++)
        {
            if (names [index] < minValue)
            {
                minValue = names [index];
                minIndex = index;
            }
        }
        names [minIndex] = names [startScan];
        names [startScan] = minValue;
    }
}

//*****************************************************************************************************

void selectionSortDescending(string names[], int numNames)
{
    int minIndex;
    string minValue;

    for (int startScan = 0; startScan < (numNames - 1); startScan++)
    {
        minIndex = startScan;
        minValue = names [minIndex];

        for (int index = startScan + 1; index < numNames; index++)
        {
            if (names [index] > minValue)
            {
                minValue = names [index];
                minIndex = index;
            }
        }
        names [minIndex] = names [startScan];
        names [startScan] = minValue;
    }
}

//*****************************************************************************************************

/*

Smith, John
Song, Mona
Jones, Trevor
Li, Na
Zhang, Xiu Ying
Saleem, Mohammad
Lloyd, Arthur
Jones, Rhys
Evans, Olivia
Davies, Emily

Enter name to search:
Smith, John

Array index is: 0

*/