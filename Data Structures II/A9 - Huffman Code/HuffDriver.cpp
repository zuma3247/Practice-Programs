//*****************************************************************************************************
//
//		File:			    HuffDriver.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #9
//
//		Course Name:		Data Structures II
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    April 4, 2025
//
//
//		This file drives a Huffman class.
//
//
//*****************************************************************************************************

#include "Huffman.h"
#include <iostream>
using namespace std;

//*****************************************************************************************************

int main()
{
    string input,
           encoded,
           decoded;

    cout << "Enter a string: ";
    getline(cin, input);

    Huffman huff(input);

    cout << "========================" << endl;

    encoded = huff.encode();
    cout << "Encoded String: " << encoded << endl;

    decoded = huff.decode(encoded);
    cout << "Decoded String: " << decoded << endl;

    return 0;
}

//*****************************************************************************************************

/*

Enter a string: BANANA
========================
Encoded String: 100110110
Decoded String: BANANA

Enter a string: Muffman
========================
Encoded String: 100000101110101111
Decoded String: Muffman

 */