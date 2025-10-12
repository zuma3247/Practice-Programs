//*****************************************************************************************************
//
//		File:			    pal2.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #9
//
//		Course Name:		Data Structures I
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    November 18, 2024
//
//
//		This program uses a stack and a queue to test and display palindromes.
//
//		Other files required:
//                       1.   stack.h
//                       2.   node.h
//                       3.   queue.h
//                       4.   palindromes.txt
//
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
using namespace std;
#include "stack.h"
#include "queue.h"

//*****************************************************************************************************

bool testNdisplayPal ( Stack <char> & stk, Queue <char> & qu );
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
    Stack <char> st;
    Queue <char> que;
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
                    st.push ( val );
                    que.enqueue ( val );
                }
                else if ( isspace ( pal [i] ) )
                    hasSpace = true;
                else if ( ispunct ( pal [i] ) )
                    hasPunct = true;
            }

            isValid = testNdisplayPal ( st, que );
            palType = getPalType ( hasSpace, hasPunct );
            displayPalResult ( isValid, palType );
        }

        palFile.close();
    }

    delete [] pal;

    return 0;
}

//*****************************************************************************************************

bool testNdisplayPal ( Stack <char> & stk, Queue <char> & qu )
{
    char val1,
         val2;
    bool isPal = true;

    while ( stk.pop (val1) && qu.dequeue (val2) )
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