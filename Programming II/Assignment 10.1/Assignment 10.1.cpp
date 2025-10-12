//*****************************************************************************************************
//
//     File:               Assignment 10.1.cpp
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
//     This program reads data from a text file and outputs to a binary file.
//
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//*****************************************************************************************************

int main()
{
    string fileName = "Testers.txt",
           binFile = "Testers.dat";
    char ch;

    ifstream fin (fileName, ios :: in);
    ofstream fout (binFile, ios :: out | ios :: binary);

    if (fin)
    {
        fin.get(ch);

        while (fin)
        {
            fout.write(&ch, sizeof(ch));
            fin.get(ch);
        }

        fin.close();
        fout.close();
        cout << "File Conversion Done.";
    }
    else
    {
        cout << "File not open";
    }


    return 0;
}

//*****************************************************************************************************

 /*
 File Conversion Done.
*/
