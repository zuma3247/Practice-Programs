//*****************************************************************************************************
//
//		File:			    pal1.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #8
//
//		Course Name:		Data Structures I
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    November 7, 2024
//
//
//		This program uses stacks to test and display palindromes.
//
//		Other files required:
//                       1.   stack.h
//                       2.   palindromes.txt
//
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
using namespace std;
#include "stack.h"

//*****************************************************************************************************

void fillStack3 ( Stack <char> & s2, Stack <char> & s3 );
bool testNdisplayPal ( Stack <char> & s1, Stack <char> & s3 );
char getPalType ( bool hasSpaces, bool hasPuncts );
void displayPalResult ( bool isValid, char palType );

//*****************************************************************************************************

int main()
{
    int len;
    char palType,
         val;
    char * pal;
    bool hasPunct,
         hasSpace,
         isValid;
    Stack <char> s1;
    Stack <char> s2;
    Stack <char> s3;
    ifstream palFile;

    pal = new char [80];

    palFile.open ( "palindromes.txt" );

    if (!palFile)
        cout << "Error opening file" << endl;
    else
    {
        while ( palFile.getline ( pal, 80, '#' ) )
        {
            len = static_cast <int> ( strlen (pal) );
            hasPunct = false;
            hasSpace = false;

            for ( int i = 0; i < len; i++ )
            {
                if ( isalpha ( pal [i] ) )
                {
                    val = tolower (pal [i]);
                    s1.push ( val );
                    s2.push ( val );
                }
                else if ( isspace ( pal [i] ) )
                    hasSpace = true;
                else if ( ispunct ( pal [i] ) )
                    hasPunct = true;
            }

            fillStack3 ( s2, s3 );
            isValid = testNdisplayPal ( s1, s3 );
            palType = getPalType ( hasSpace, hasPunct );
            displayPalResult ( isValid, palType );
        }
        palFile.close();
    }

    delete [] pal;

    return 0;
}

//*****************************************************************************************************

void fillStack3 ( Stack <char> & s2, Stack <char> & s3 )
{
    char val;

    while ( s2.pop (val) )
        s3.push (val);
}

//*****************************************************************************************************

bool testNdisplayPal ( Stack <char> & s1, Stack <char> & s3 )
{
    char val1,
         val2;
    bool isPal = true;

    while ( s1.pop (val1) && s3.pop (val2) )
    {
        if ( val1 != val2 )
            isPal = false;

        cout << val1;
    }

    return isPal;
}

//*****************************************************************************************************

char getPalType ( bool hasSpaces, bool hasPuncts )
{
    char type = '1';

    if (hasPuncts)
        type = '3';
    else if (hasSpaces)
        type = '2';

    return type;
}

//*****************************************************************************************************

void displayPalResult ( bool isValid, char palType )
{
    cout << "\t\t\t\t";

    if (isValid)
        cout << "type " << palType;
    else
        cout << "invalid";

    cout << endl;
}

//*****************************************************************************************************

/*
aha				type 3
isitiitisi				type 3
deed				type 1
srotor				invalid
neveroddoreven				type 2
nolemonsnomelon				type 3
racecar				type 2
cimoc				invalid
wasitacaroracatisaw				type 3
yddad				invalid
 */