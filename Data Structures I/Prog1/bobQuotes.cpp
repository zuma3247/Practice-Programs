//*****************************************************************************************************
//
//		File:			    bobQuotes.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #1
//
//		Course Name:		Data Structures I
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    August 29, 2024
//
//
//		This program displays a function in different ways using default arguments.
//
//		Other files required:
//                       1.   None
//
//*****************************************************************************************************

#include <iostream>
#include <cstring>
using namespace std;

//*****************************************************************************************************

void displayMsg ( const char msg[] = "Less is More", char symbol = ' ', int num1 = 10 );
void displaySymbol ( char symbol, int numTimes );

//*****************************************************************************************************

int main()
{
    displayMsg ( "Wake up and live.", '*', 20 );
    displayMsg ( "Do not worry, be happy.", '+' );
    displayMsg ( "Success is a poor teacher." );
    displayMsg ();

    return 0;
}

//*****************************************************************************************************

void displayMsg ( const char msg[], char symbol, int num1 )
{
    displaySymbol ( symbol, num1 );

    for ( int i = 0; i < strlen(msg); i++)
        cout << msg[i];

    displaySymbol ( symbol, num1 );
}

//*****************************************************************************************************

void displaySymbol ( char symbol, int numTimes )
{
    for ( int i = 0; i < numTimes; i++ )
        cout << symbol;
}

//*****************************************************************************************************

/*

********************Wake up and live.********************++++++++++Do not worry, be happy.++++++++++          Success is a poor teacher.                    Less is More

 */

