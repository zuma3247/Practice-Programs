//*****************************************************************************************************
//
//		File:			    AList2.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #3
//
//		Course Name:		Data Structures II
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    Feb 5, 2025
//
//
//		This is the header file for recursive implentation of Array List.
//
//		Other files required:
//                       1.   driver.cpp
//
//*****************************************************************************************************

#ifndef ALIST2_H
#define ALIST2_H
#include <new>

//*****************************************************************************************************

template < typename TYPE >
class AList2
{
private:
    TYPE * list;
    int capacity;
    int numValues;
    bool _resize();
    void insertHelper(int index, const TYPE & value);
    bool removeHelper(int index, const TYPE & value);
    int binSrchHelper(int low, int high, const TYPE & target) const;
    void printHelper(int index) const;

public:
    AList2 (int cap = 10 );
    ~AList2();
    AList2 (const AList2 <TYPE> & a);

    void insert ( const TYPE & dataIn );
    bool remove ( const TYPE & dataIn );
    int binarySearch(const TYPE & item) const;

    bool isFull () const;
    bool isEmpty () const;
    int listSize () const;
    void print () const;
};

//*****************************************************************************************************

template < typename TYPE >
AList2 < TYPE> :: AList2 (int cap )
{
    capacity = cap;
    list = new TYPE [ capacity ];
    numValues = 0;
}

//*****************************************************************************************************

template < typename TYPE >
AList2 < TYPE> :: ~AList2()
{
    delete [] list;
    capacity = 0;
    numValues = 0;
}

//*****************************************************************************************************

template < typename TYPE >
AList2 < TYPE> :: AList2 (const AList2 <TYPE> & a)
{
    this -> numValues = a.numValues;
    this -> capacity = a.capacity;

    for (int i = 0; i < numValues; i++)
        this -> list[i] = a.list[i];
}

//*****************************************************************************************************

template < typename TYPE >
bool AList2 < TYPE> :: _resize()
{
    bool success = false;
    int newCap;
    TYPE * newList;

    newCap = capacity * 2;
    newList = new (nothrow) TYPE [ newCap ];

    if ( newList )
    {
        for ( int i = 0; i < numValues; i++ )
            newList [i] = list [i];

        delete [] list;
        list = newList;
        capacity = newCap;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template < typename TYPE >
void AList2 < TYPE> :: insertHelper(int index, const TYPE & value)
{
    if (index < 0 || list[index] < value)
    {
        list[index + 1] = value;
        numValues++;
        return;
    }

    list[index + 1] = list[index];
    insertHelper(index - 1, value);
}

//*****************************************************************************************************

template < typename TYPE >
void AList2 < TYPE> :: insert (const TYPE & dataIn )
{
    if ( numValues == capacity )
        _resize();

    insertHelper(numValues - 1, dataIn);
}

//*****************************************************************************************************

template < typename TYPE >
bool AList2 <TYPE> :: removeHelper(int index, const TYPE & value )
{
    if (index == numValues)
        return false;

    if (list[index] == value)
    {
        for (int i = index; i < numValues - 1; i++)
        {
            list[i] = list[i + 1];
        }
        numValues--;
        return true;
    }
    return removeHelper(index + 1, value);
}

//*****************************************************************************************************

template < typename TYPE >
bool AList2 <TYPE> :: remove (const TYPE & value )
{
    bool success;

    success = removeHelper ( numValues - 1, value );

    return success;
}

//*****************************************************************************************************

template < typename TYPE >
int AList2 < TYPE> :: binSrchHelper(int low, int high, const TYPE & target) const
{
    int mid = 0;

    if (low <= high)
    {
        mid = (high + low) / 2;

        if (list[mid] == target)
            return mid;
        else if (target > list[mid])
            return binarySearch(mid + 1, high, target);
        else
            return binarySearch(low, mid - 1, target);
    }

    return -1;
}

//*****************************************************************************************************

template < typename TYPE >
int AList2 < TYPE> :: binarySearch(const TYPE & item) const
{
    return binSrchHelper(0, numValues - 1, item);
}

//*****************************************************************************************************

template < typename TYPE >
bool AList2 < TYPE> :: isEmpty () const
{
    return ( numValues == 0 );
}

//*****************************************************************************************************

template < typename TYPE >
bool AList2 < TYPE> :: isFull () const
{
    return ( numValues == capacity );
}

//*****************************************************************************************************

template < typename TYPE >
int AList2 < TYPE> :: listSize () const
{
    return numValues;
}

//*****************************************************************************************************

template < typename TYPE >
void AList2 < TYPE> :: printHelper(int index) const
{
    if (index < 0)
    {
        return;
    }

    cout << list[index] << " ";
    printHelper(index - 1);
}

//*****************************************************************************************************

template < typename TYPE >
void AList2 < TYPE> :: print() const
{
    printHelper(numValues - 1);
    cout << endl;
}

//*****************************************************************************************************

#endif
