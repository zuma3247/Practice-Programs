//*****************************************************************************************************
//
//		File:			    driver.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #4
//
//		Course Name:		Data Structures II
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    February 14, 2025
//
//
//		This is a driver program for a Hash Table class that uses Linear Probing.
//
//		Other files required:
//                       1.   HashTable.h
//
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "HashTable.h"

//*****************************************************************************************************

int main()
{
    HashTable <int> hashTableX(23);
    bool success = false;
    int removeVal = 45,
        retrieveVal = 15;

    success = hashTableX.insert(35);
    success = hashTableX.insert(15);
    success = hashTableX.insert(25);
    success = hashTableX.insert(45);
    success = hashTableX.insert(75);
    success = hashTableX.insert(65);

    if (success)
    {
        cout << "Hash table after insertions: " << endl;
        hashTableX.display();
        cout << endl;
    }
    else
        cout << "Error in insertion." << endl;

    success = hashTableX.remove(removeVal);

    if (success)
    {
        cout << "Hash table after removing 45: " << endl
             << hashTableX << endl;
        hashTableX.display();
        cout << endl;
    }
    else
        cout << "Error in removal." << endl;

    success = hashTableX.retrieve(retrieveVal);

    if (success)
    {
        cout << "Retrieved: " << retrieveVal << endl;
    }
    else
        cout << "Error in retrieval." << endl;

    return 0;
}

//*****************************************************************************************************

/*
Hash table after insertions:
0: [empty]
1: [empty]
2: 25
3: [empty]
4: [empty]
5: [empty]
6: 75
7: [empty]
8: [empty]
9: [empty]
10: [empty]
11: [empty]
12: 35
13: [empty]
14: [empty]
15: 15
16: [empty]
17: [empty]
18: [empty]
19: 65
20: [empty]
21: [empty]
22: 45

Hash table after removing 45:
0: [empty]
1: [empty]
2: 25
3: [empty]
4: [empty]
5: [empty]
6: 75
7: [empty]
8: [empty]
9: [empty]
10: [empty]
11: [empty]
12: 35
13: [empty]
14: [empty]
15: 15
16: [empty]
17: [empty]
18: [empty]
19: 65
20: [empty]
21: [empty]
22: [deleted]

Retrieved: 15
 */