//*****************************************************************************************************
//
//		File:			    dyadDriver.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #3
//
//		Course Name:		Data Structures I
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    September 12, 2024
//
//
//		This program uses a class template to create a class for a dyad of values.
//
//		Other files required:
//                       1.   dyad.h
//
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "dyad.h"

//*****************************************************************************************************

int main()
{
    int num1,
        num2;

    double dub1,
           dub2;

    char let1,
         let2;

    Dyad < int > dyad1 ( 5, 10 );
    Dyad < double > dyad2 ( 5.5, 10.5 );
    Dyad < char > dyad3 ( 'A', 'Z' );

    num1 = dyad1.getFirst();
    num2 = dyad1.getSecond();

    cout << "First int is: " << num1 << endl
         << "Second int is: " << num2 << endl << endl;

    dyad1.swapValues ( num1, num2 );
    dyad1.get2Values ( num1, num2 );

    cout << "First int is now: " << num1 << endl
         << "Second int is now: " << num2 << endl << endl;


    dub1 = dyad2.getFirst();
    dub2 = dyad2.getSecond();

    cout << "First double is: " << dub1 << endl
         << "Second double is: " << dub2 << endl << endl;

    dyad2.swapValues ( dub1, dub2 );
    dyad2.get2Values ( dub1, dub2 );

    cout << "First double is now: " << dub1 << endl
         << "Second double is now: " << dub2 << endl << endl;


    let1 = dyad3.getFirst();
    let2 = dyad3.getSecond();

    cout << "First char is: " << let1 << endl
         << "Second char is: " << let2 << endl << endl;

    dyad3.swapValues ( let1, let2 );
    dyad3.get2Values ( let1, let2 );

    cout << "First char is now: " << let1 << endl
         << "Second char is now: " << let2 << endl << endl;

    return 0;
}

//*****************************************************************************************************

/*

First int is: 5
Second int is: 10

First int is now: 10
Second int is now: 5

First double is: 5.5
Second double is: 10.5

First double is now: 10.5
Second double is now: 5.5

First char is: A
Second char is: Z

First char is now: Z
Second char is now: A

 */