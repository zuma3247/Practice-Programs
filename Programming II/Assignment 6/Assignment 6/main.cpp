//*****************************************************************************************************
//
//     File:               Assignment 6.1.cpp
//
//     Student:            Muazuddin Mohammed
//
//     Assignment:         Assignment#6
//
//     Course Name:        Computer Programming #2
//
//     Course Number:      COSC 1560
//
//     Due:                October 9, 2023
//
//
//     This program implements manipulation of strings.
//
//*****************************************************************************************************

#include <iostream>
#include <string>
using namespace std;

int numberWords (const char *words, int size);

//****************************************************************************************************

int main ()
{
    char *sentence = nullptr;
    int numWords,
        size = 60;

    sentence = new char [size];

    for (int i = 0; i < 2; i++)
    {
        cout << "Enter a line of words, ended by ‘.’: ";
        cin.getline (sentence, size, '.');

        numWords = numberWords (sentence, size);

        cout << "Number of words: " << numWords << endl << endl;
    }

    return 0;
}

//****************************************************************************************************

int numberWords (const char * words, int size)
{
    int count = 0;
    bool inWord = false;

    for (int i = 0; i < size; i++)
    {
        if ((isspace (words [i])) || (words [i] == 44))
        {
            count++;
            inWord = true;
        }
    }

    return count;
}

//****************************************************************************************************

/*
Enter a line of words, ended by ‘.’: This contains a name,address, and phone number.
Number of words: 8

Enter a line of words, ended by ‘.’: This contains a name,address, and phone number.
Number of words: 9
 */