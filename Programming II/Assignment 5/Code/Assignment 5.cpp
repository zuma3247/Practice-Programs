//*****************************************************************************************************
//
//     File:               Assignment 5.cpp
//
//     Student:            Muazuddin Mohammed
//
//     Assignment:         Assignment#5
//
//     Course Name:        Computer Programming #2
//
//     Course Number:      COSC 1560
//
//     Due:                October 2, 2023
//
//
//     This program can be used to gather data about the number of cricket matches
//     college students play in a year. It involves dynamic memory allocation and strings.
//
//*****************************************************************************************************

#include <iostream>
#include <string>
using namespace std;

void input (string names [], int matches [], int size);
void display(const string names [], const int matches [], int size);
void displayMostMatches (const string names [], const int matches [], int size);
double mean(const int matches[], int num);
void sortStudents (string names [], int matches [], int size);

//*****************************************************************************************************

int main ()
{
    int *matches = nullptr,
        size;
    string *names = nullptr;
    double average;

    cout << "How many students were surveyed?" << endl;
    cin >> size;

    matches = new int [size];
    names = new string [size];

    input (names, matches, size);
    display (names, matches, size);
    displayMostMatches (names, matches, size);

    average = mean (matches, size);
    cout << "The mean of matches is: " << average << endl << endl;

    sortStudents (names, matches, size);
    display (names, matches, size);

    return 0;
}

//*****************************************************************************************************

void input (string names [], int matches [], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the name of student " << i + 1 << ": " << endl;
        cin.ignore();
        getline (cin, names [i]);

        do
        {
            cout << "Enter a positive number of matches played by " << names [i]
                 << ": " << endl;
            cin >> matches [i];
        }
        while (matches [i] < 0);

        cout << endl;
    }
}

//*****************************************************************************************************

void display(const string names [], const int matches [], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << names [i] << "\t\t" << matches [i] << endl;
    }
    cout << endl;
}

//*****************************************************************************************************

void displayMostMatches (const string names [], const int matches [], int size)
{
    int most = 0;
    string nameOfMost;

    for (int i = 0; i < size; i++)
    {
        if (matches [i] > most)
        {
            most = matches [i];
            nameOfMost = names [i];
        }
    }

    cout << "Most matches: " << most << endl
         << "Played by: " << nameOfMost << endl << endl;
}
//*****************************************************************************************************

double mean (const int matches [], int num)
{
    double sum = 0,
           mean;

    for (int i = 0; i < num; i++)
    {
        sum += matches [i];
    }

    mean = sum / num;

    return mean;
}

//*****************************************************************************************************

void sortStudents (string names [], int matches [], int size)
{
    int tempMatches;
    string temp;

    for (int i = 0; i < (size - 1); i++)
    {
        for (int count = 0; count < (size - i - 1); count++)
        {
            if (names [count] > names [count + 1])
            {
                temp = names[count];
                names[count] = names[count + 1];
                names[count + 1] = temp;

                tempMatches = matches [count];
                matches [count] = matches [count + 1];
                matches [count + 1] = tempMatches;
            }
        }
    }
}

//*****************************************************************************************************

/*

How many students were surveyed?
4
Enter the name of student 1:
Muaz Mohammed
Enter a positive number of matches played by Muaz Mohammed:
2

Enter the name of student 2:
Talha Mohammed
Enter a positive number of matches played by Talha Mohammed:
3

Enter the name of student 3:
Hamza Mohammed
Enter a positive number of matches played by Hamza Mohammed:
10

Enter the name of student 4:
Wahed Ali
Enter a positive number of matches played by Wahed Ali:
1

Muaz Mohammed		2
Talha Mohammed		3
Hamza Mohammed		10
Wahed Ali		1

Most matches: 10
Played by: Hamza Mohammed

The mean of matches is: 4

Hamza Mohammed		10
Muaz Mohammed		2
Talha Mohammed		3
Wahed Ali		1

 */