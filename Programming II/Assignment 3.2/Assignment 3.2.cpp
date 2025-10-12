//*****************************************************************************************************
//
//     File:               Assignment 3.2.cpp
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
//     This program implements basic pointer programming.
//
//
//*****************************************************************************************************

#include <iostream>
using namespace std;

//*****************************************************************************************************

int main ()
{
    double d1 = 10.5,
           d2 = 2.2,
           d3 = 11.8;

    double *p1 = &d1;
    double *p2 = &d2;

    *p1 *= 3;

    cout << "Sum of d1 & d2: " << *p1 + *p2 << endl;

    p1 = &d3;

    cout << "Sum of d2 & d3: " << *p1 + *p2 << endl;

}

//*****************************************************************************************************

/*

Sum of d1 & d2: 33.7
Sum of d2 & d3: 14

 */
