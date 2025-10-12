//*****************************************************************************************************
//
//		File:			    driverAList.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #4
//
//		Course Name:		Data Structures I
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    September 26, 2024
//
//
//		This program creates and manipulates a dynamically allocated array using various functions.
//
//		Other files required:
//                       1.   AList.h
//
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "AList.h"

//*****************************************************************************************************

int main()
{
    bool success = false;
    short min,
          removedData,
          retrievedData,
          remove5 = 5,
          retrieve12 = 12,
          updateVal = 72;
    AList <short> shortList (3);

    if ( shortList.isEmpty() )
        cout << "ShortList is now empty" << endl << endl;

    shortList.insertFront (8);
    shortList.insertBack (12);
    shortList.insertAtIndex ( 7, 2 );
    cout << "Starting list:" << endl;

    shortList.display();
    cout << endl;

    if ( shortList.insertFront (3) )
    {
        cout << endl << "After using InsertFront:" << endl;
        shortList.display();

        shortList.getSmallest ( min );
        cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
             << shortList.getNumValues() << "\t smallest value is " << min << endl;
    }
    else
        cout << "Unable to insert the value 3 at front";

    if ( shortList.isFull() )
        cout << endl << "ShortList is full at this point" << endl;

    if ( shortList.insertBack (2) )
    {
        cout << endl << "After using InsertBack:" << endl;
        shortList.display();

        shortList.getSmallest ( min );
        cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
             << shortList.getNumValues() << "\t smallest value is " << min << endl;
    }
    else
        cout << "Unable to insert the value 2 at back";

    if ( shortList.insertAtIndex ( 5, 2 ) )
    {
        cout << endl << "After using Insert at Index:" << endl;
        shortList.display();

        shortList.getSmallest( min );
        cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
             << shortList.getNumValues() << "\t smallest value is " << min << endl;
    }
    else
        cout << "Unable to insert the value 5 at index 2";

    if ( shortList.removeFront (removedData) )
    {
        cout << endl << "Used RemoveFront to remove: " << removedData << endl;
        shortList.display();

        shortList.getSmallest( min );
        cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
             << shortList.getNumValues() << "\t smallest value is " << min << endl;
    }
    else
        cout << "Unable to remove front value";

    if ( shortList.removeBack (removedData) )
    {
        cout << endl << "Used RemoveBack to remove: " << removedData << endl;
        shortList.display();

        shortList.getSmallest( min );
        cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
             << shortList.getNumValues() << "\t smallest value is " << min << endl;
    }
    else
        cout << "Unable to remove back value";

    if ( shortList.removeAtIndex ( removedData, 2 ) )
    {
        cout << endl << "Used Remove value at index#2 to remove: " << removedData << endl;
        shortList.display();

        shortList.getSmallest( min );
        cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
             << shortList.getNumValues() << "\t smallest value is " << min << endl;
    }
    else
        cout << "Unable to remove at index";

    if ( shortList.remove (remove5) )
    {
        cout << endl << "Used Remove() to remove 5: " << endl;
        shortList.display();

        shortList.getSmallest( min );
        cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
             << shortList.getNumValues() << "\t smallest value is " << min << endl;
    }
    else
        cout << "Unable to remove 5";

    if ( shortList.remove (removedData) )
    {
        cout << endl << "Used Remove() to remove previously removed value: " << endl;
        shortList.display();

        shortList.getSmallest( min );
        cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
             << shortList.getNumValues() << "\t smallest value is " << min << endl;
    }
    else
        cout << endl << "Unable to remove data, does not exist" << endl;

    cout << endl << "Commented out the Remove function calls at this point."
         << endl << "Current list:" << endl;
    shortList.display();
    cout << endl;

    if ( shortList.retrieveFront (retrievedData) )
    {
        cout << endl << "Used RetrieveFront to get: " << retrievedData << endl;
        shortList.display();

        shortList.getSmallest( min );
        cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
             << shortList.getNumValues() << "\t smallest value is " << min << endl;
    }
    else
        cout << endl << "Unable to retrieve front data" << endl;

    if ( shortList.retrieveBack (retrievedData) )
    {
        cout << endl << "Used RetrieveBack to get: " << retrievedData << endl;
        shortList.display();

        shortList.getSmallest( min );
        cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
             << shortList.getNumValues() << "\t smallest value is " << min << endl;
    }
    else
        cout << endl << "Unable to retrieve back data" << endl;

    if ( shortList.retrieveAtIndex ( retrievedData, 2 ) )
    {
        cout << endl << "Used RetrieveAtIndex to get: " << retrievedData << endl;
        shortList.display();

        shortList.getSmallest( min );
        cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
             << shortList.getNumValues() << "\t smallest value is " << min << endl;
    }
    else
        cout << endl << "Unable to retrieve data at Index" << endl;

    if ( shortList.retrieveAtIndex ( retrievedData, 8 ) )
    {
        cout << endl << "Used RetrieveAtIndex to get: " << retrievedData << endl;
        shortList.display();

        shortList.getSmallest( min );
        cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
             << shortList.getNumValues() << "\t smallest value is " << min << endl;
    }
    else
        cout << endl << "Unable to retrieve data at Index 8 (index does not exist)"
             << endl;

    if ( shortList.retrieve (retrieve12) )
    {
        cout << endl << "Used Retrieve() to get 12: " << endl;
        shortList.display();

        shortList.getSmallest( min );
        cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
             << shortList.getNumValues() << "\t smallest value is " << min << endl;
    }
    else
        cout << endl << "Unable to retrieve 12" << endl;

    if ( shortList.updateFront (updateVal) )
    {
        cout << endl << "Used updateFront to update 72: " << endl;
        shortList.display();

        shortList.getSmallest( min );
        cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
             << shortList.getNumValues() << "\t smallest value is " << min << endl;
    }
    else
        cout << endl << "Unable to update front data" << endl;

    updateVal = 3;

    if ( shortList.updateBack (updateVal) )
    {
        cout << endl << "Used updateBack to update 3: " << endl;
        shortList.display();

        shortList.getSmallest( min );
        cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
             << shortList.getNumValues() << "\t smallest value is " << min << endl;
    }
    else
        cout << endl << "Unable to update back data" << endl;

    updateVal = 45;

    if ( shortList.updateAtIndex ( updateVal, 2 ) )
    {
        cout << endl << "Used updateAtIndex to update index 2: " << endl;
        shortList.display();

        shortList.getSmallest( min );
        cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
             << shortList.getNumValues() << "\t smallest value is " << min << endl;
    }
    else
        cout << endl << "Unable to update at index 2" << endl;

    updateVal = 7;

    if ( shortList.update (updateVal) )
    {
        cout << endl << "Used update() to update: " << endl;
        shortList.display();

        shortList.getSmallest( min );
        cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
             << shortList.getNumValues() << "\t smallest value is " << min << endl;
    }
    else
        cout << endl << "Unable to update data" << endl;

    shortList.clear();
    cout << endl << "Cleared list:" << endl;
    shortList.display();

    if ( shortList.isEmpty() )
        cout << "ShortList is now empty" << endl << endl;

    return 0;
}

//*****************************************************************************************************

/*

ShortList is now empty

Starting list:
[0] 8	[1] 12	[2] 7

After using InsertFront:
[0] 3	[1] 8	[2] 12	[3] 7
capacity is 4	 numValues is 4	 smallest value is 3

ShortList is full at this point

After using InsertBack:
[0] 3	[1] 8	[2] 12	[3] 7	[4] 2
capacity is 6	 numValues is 5	 smallest value is 2

After using Insert at Index:
[0] 3	[1] 8	[2] 5	[3] 12	[4] 7	[5] 2
capacity is 6	 numValues is 6	 smallest value is 2

Used RemoveFront to remove: 3
[0] 8	[1] 5	[2] 12	[3] 7	[4] 2
capacity is 6	 numValues is 5	 smallest value is 2

Used RemoveBack to remove: 2
[0] 8	[1] 5	[2] 12	[3] 7
capacity is 6	 numValues is 4	 smallest value is 5

Used Remove value at index#2 to remove: 12
[0] 8	[1] 5	[2] 7
capacity is 6	 numValues is 3	 smallest value is 5

Used Remove() to remove 5:
[0] 8	[1] 7
capacity is 6	 numValues is 2	 smallest value is 7

Unable to remove data, does not exist

Commented out the Remove function calls at this point.
Current list:
[0] 3	[1] 8	[2] 5	[3] 12	[4] 7	[5] 2

Used RetrieveFront to get: 3
[0] 3	[1] 8	[2] 5	[3] 12	[4] 7	[5] 2
capacity is 6	 numValues is 6	 smallest value is 2

Used RetrieveBack to get: 2
[0] 3	[1] 8	[2] 5	[3] 12	[4] 7	[5] 2
capacity is 6	 numValues is 6	 smallest value is 2

Used RetrieveAtIndex to get: 5
[0] 3	[1] 8	[2] 5	[3] 12	[4] 7	[5] 2
capacity is 6	 numValues is 6	 smallest value is 2

Unable to retrieve data at Index 8 (index does not exist)

Used Retrieve to get 12:
[0] 3	[1] 8	[2] 5	[3] 12	[4] 7	[5] 2
capacity is 6	 numValues is 6	 smallest value is 2

Commented out the Remove function calls at this point.
Current list:
[0] 3	[1] 8	[2] 5	[3] 12	[4] 7	[5] 2

Used RetrieveFront to get: 3
[0] 3	[1] 8	[2] 5	[3] 12	[4] 7	[5] 2
capacity is 6	 numValues is 6	 smallest value is 2

Used RetrieveBack to get: 2
[0] 3	[1] 8	[2] 5	[3] 12	[4] 7	[5] 2
capacity is 6	 numValues is 6	 smallest value is 2

Used RetrieveAtIndex to get: 5
[0] 3	[1] 8	[2] 5	[3] 12	[4] 7	[5] 2
capacity is 6	 numValues is 6	 smallest value is 2

Unable to retrieve data at Index 8 (index does not exist)

Used Retrieve() to get 12:
[0] 3	[1] 8	[2] 5	[3] 12	[4] 7	[5] 2
capacity is 6	 numValues is 6	 smallest value is 2

Used updateFront to update 72:
[0] 72	[1] 8	[2] 5	[3] 12	[4] 7	[5] 2
capacity is 6	 numValues is 6	 smallest value is 2

Used updateBack to update 3:
[0] 72	[1] 8	[2] 5	[3] 12	[4] 7	[5] 3
capacity is 6	 numValues is 6	 smallest value is 3

Used updateAtIndex to update index 2:
[0] 72	[1] 8	[2] 45	[3] 12	[4] 7	[5] 3
capacity is 6	 numValues is 6	 smallest value is 3

Used update() to update:
[0] 72	[1] 8	[2] 45	[3] 12	[4] 7	[5] 3
capacity is 6	 numValues is 6	 smallest value is 3

Cleared list:
ShortList is now empty

 */