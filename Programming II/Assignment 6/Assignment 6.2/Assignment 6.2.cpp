//*****************************************************************************************************
//
//     File:               Assignment 6.2.cpp
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
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    int size = 0,
        numLetters = 0,
        numDigits = 0,
        numLowerCase = 0,
        numUpperCase = 0;

     string words = "This is a 101 SAMPLE to demonstrate string processing";

    size = strlen (words);

    for (char i = 0; i < size; i++)
    {
        if (isalpha (words [i]))
        {
            numLetters++;
            if (islower (words [i]))
            {
                numLowerCase++;
            } else
            {
                numUpperCase++;
            }
        }
        else if (isdigit (words [i]))
        {
            numDigits++;
        }

    }

    cout << "Size of the string: " << size << endl;
    cout << "Number of letters: " << numLetters << endl;
    cout << "Number of digits: " << numDigits << endl;
    cout << "Number of lower case letters: " << numLowerCase << endl;
    cout << "Number of upper case letters: " << numUpperCase << endl;
    cout << "Character at index 16: " << words[16] << endl;
    cout << "Last character of the string: " << words[size - 1] << endl;

    int indexFirstA = -1;
    for (int i = 0; i < size; i++)
    {
        if ( words.find ('a'))
        {
            indexFirstA = i;
        }
    }

    int indexSecondA = -1;
    for (int i = indexFirstA + 1; i < size; i++)
    {
        if (words[i] == 'a')
        {
            indexSecondA = i;
            break;
        }
    }

    cout << "Index of the first 'a': " << indexFirstA << endl;
    cout << "Index of the second 'a': " << indexSecondA << endl;

    return 0;
}