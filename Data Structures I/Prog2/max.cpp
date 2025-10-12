//*****************************************************************************************************
//
//		File:			    max.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #2
//
//		Course Name:		Data Structures I
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    September 5, 2024
//
//
//		This program finds maximums using a function template and an overloaded function.
//
//		Other files required:
//                       1.   None
//
//*****************************************************************************************************

#include <iostream>

using namespace std;

//*****************************************************************************************************

template < typename TYPE >
void getData ( TYPE & val1, TYPE & val2 );

template < typename TYPE >
TYPE findMax ( TYPE val1, TYPE val2 );

template < typename TYPE >
void displayMax ( TYPE val1, TYPE val2, TYPE maxVal );

void getData ( char str1[], char str2[] );
char * findMax ( char str1[], char str2[] );
void displayMax ( char str1[], char str2[], char maxStr );

//*****************************************************************************************************

int main()
{
    int aInt,
        bInt,
        maxInt;

    double aDouble,
           bDouble,
           maxDouble;

    char aChar,
         bChar,
         maxChar;

    char * aArray;
    char * bArray;
    char * maxArray;

    aArray = new char [100];
    bArray = new char [100];

    getData ( aInt, bInt );
    getData ( aDouble, bDouble );
    getData ( aChar, bChar );
    getData ( aArray, bArray) ;

    maxInt = findMax ( aInt, bInt );
    maxDouble = findMax ( aDouble, bDouble );
    maxChar = findMax ( aChar, bChar );
    maxArray = findMax ( aArray, bArray );

    displayMax ( aInt, bInt, maxInt );
    displayMax ( aDouble, bDouble, maxDouble );
    displayMax ( aChar, bChar, maxChar );
    displayMax ( aArray, bArray, maxArray );

    return 0;
}

//*****************************************************************************************************

template < typename TYPE >
void getData ( TYPE & val1, TYPE & val2 )
{
    cout << "Enter 1 " << typeid ( val1 ).name() << ": \t";
    cin >> val1;

    cout << "Enter another " << typeid ( val2 ).name() << ": \t";
    cin >> val2;

    cout << endl;
}

//*****************************************************************************************************

template < typename TYPE >
TYPE findMax ( TYPE val1, TYPE val2 )
{
    TYPE max;

    max = val1;

    if ( val2 > val1 )
        max = val2;

    return max;
}

//*****************************************************************************************************

template < typename TYPE >
void displayMax ( TYPE val1, TYPE val2, TYPE maxVal )
{
    cout << "The max between " << val1 << " and " << val2 << " is: \t"
         << maxVal << endl;
}

//*****************************************************************************************************

void getData ( char str1[], char str2[] )
{
    cout << "Enter a char string: \t";
    cin.ignore();
    cin.getline ( str1, 100);

    cout << "Enter another char string: \t";
    cin.getline ( str2, 100);

    cout << endl;
}

//*****************************************************************************************************

char * findMax ( char str1[], char str2[] )
{
    char * maxArray;

    maxArray = str1;

    if ( (strcmp (str1, str2)) < 0 )
        maxArray = str2;

    return maxArray;
}

//*****************************************************************************************************

void displayMax ( char str1[], char str2[], char maxStr )
{
    cout << "The alphabetically greater string between " << str1 << " and "
         << str2 << " is: \t" << maxStr << endl;
}

//*****************************************************************************************************

/*

Enter 1 i: 	111
Enter another i: 	22

Enter 1 d: 	75.35
Enter another d: 	1123.4

Enter 1 c: 	x
Enter another c: 	t

Enter a char string: 	dog house
Enter another char string: 	dog collar

The max between 111 and 22 is: 	111
The max between 75.35 and 1123.4 is: 	1123.4
The max between x and t is: 	x
The max between dog house and dog collar is: 	dog house

*/