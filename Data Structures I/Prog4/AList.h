//*****************************************************************************************************
//
//		File:			    stock.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #2
//
//		Course Name:		Data Structures II
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    January 29, 2025
//
//
//		This is the driver program for developing a template Linked List class
//		to store Stock objects.
//
//		Other files required:
//                       1.   stock.h
//                       2.   stock.cpp
//                       3.   Node.h
//                       4.   LList2.h
//
//*****************************************************************************************************

#ifndef ALIST_H
#define ALIST_H
#include <new>

//*****************************************************************************************************

template < typename TYPE >
class AList
{
    private:
        TYPE * list;
        int capacity;
        int numValues;
        bool _resize();

    public:
        AList ( int cap = 5 );
        ~AList();

        bool insertFront ( const TYPE & dataIn );
        bool insertBack ( const TYPE & dataIn );
        bool insertAtIndex ( const TYPE & dataIn, int index );

        bool removeFront ( TYPE & dataOut );
        bool removeBack ( TYPE & dataOut );
        bool removeAtIndex ( TYPE & dataOut, int index );
        bool remove ( TYPE & dataIO );

        bool retrieveFront ( TYPE & dataOut ) const;
        bool retrieveBack ( TYPE & dataOut ) const;
        bool retrieveAtIndex ( TYPE & dataOut, int index ) const;
        bool retrieve ( TYPE & dataIO ) const;

        bool updateFront ( const TYPE & dataIn );
        bool updateBack ( const TYPE & dataIn );
        bool updateAtIndex ( const TYPE & dataIn, int index );
        bool update ( const TYPE & dataIn );

        bool display () const;
        bool getSmallest ( TYPE & dataOut ) const;
        int getCapacity () const;
        int getNumValues () const;
        bool isEmpty () const;
        bool isFull () const;
        bool clear ();
};

//*****************************************************************************************************

template < typename TYPE >
AList < TYPE> :: AList ( int cap )
{
    capacity = 5;

    if ( cap >= 2 )
        capacity = cap;

    list = new TYPE [ capacity ];
    numValues = 0;
}

//*****************************************************************************************************

template < typename TYPE >
AList < TYPE> :: ~AList()
{
    delete [] list;
    capacity = 0;
    numValues = 0;
}

//*****************************************************************************************************

template < typename TYPE >
bool AList < TYPE> :: _resize()
{
    bool success = false;
    int newCap;
    TYPE * newList;

    newCap = capacity * 1.5;
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
bool AList < TYPE> :: insertFront ( const TYPE & dataIn )
{
    bool success = true;

    if ( numValues == capacity )
        success = _resize();

    if ( success )
    {
        for ( int i = numValues; i > 0; i-- )
            list [i] = list [ i - 1 ];

        list [0] = dataIn;
        numValues++;
    }
    return success;
}

//*****************************************************************************************************

template < typename TYPE >
bool AList < TYPE> :: insertBack ( const TYPE & dataIn )
{
    bool success = true;

    if ( numValues == capacity )
        success = _resize();

    if ( success )
    {
        list [numValues] = dataIn;
        numValues++;
    }

    return success;
}

//*****************************************************************************************************

template < typename TYPE >
bool AList < TYPE> :: insertAtIndex ( const TYPE & dataIn, int index )
{
    bool success = false;

    if ( ( index <= numValues ) && ( index >= 0 ) )
    {
        success = true;

        if ( numValues == capacity )
            success = _resize();

        if ( success )
        {
            for ( int i = numValues; i > index; i-- )
                list [i] = list [ i - 1 ];

            list [index] = dataIn;
            numValues++;
        }
    }
    return success;
}

//*****************************************************************************************************

template < typename TYPE >
bool AList < TYPE> :: removeFront ( TYPE & dataOut )
{
    bool success = false;

    if ( numValues > 0 )
    {
        dataOut = list [0];

        for ( int i = 0; i < ( numValues - 1 ); i++ )
            list [i] = list [ i + 1 ];

        numValues--;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template < typename TYPE >
bool AList < TYPE> :: removeBack ( TYPE & dataOut )
{
    bool success = false;

    if ( numValues > 0 )
    {
        dataOut = list [ numValues - 1 ];
        numValues--;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template < typename TYPE >
bool AList < TYPE> :: removeAtIndex ( TYPE & dataOut, int index )
{
    bool success = false;

    if ( ( index < numValues ) && ( index >= 0 ) )
    {
        dataOut = list [index];

        for ( int i = index; i < numValues; i++ )
            list [i] = list [ i + 1 ];

        numValues--;
        success = true;
    }
    return success;
}

//*****************************************************************************************************

template < typename TYPE >
bool AList < TYPE> :: remove ( TYPE & dataIO )
{
    bool success = false;

    if ( numValues > 0 )
    {
        for ( int i = 0; i < numValues; i++ )
        {
            if ( list [i] == dataIO )
            {
                success = removeAtIndex ( dataIO, i );
                i = numValues;
            }
        }
    }

    return success;
}

//*****************************************************************************************************

template < typename TYPE >
bool AList < TYPE> :: retrieveFront ( TYPE & dataOut ) const
{
    bool success = false;

    if ( numValues > 0 )
    {
        dataOut = list [0];
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template < typename TYPE >
bool AList < TYPE> :: retrieveBack ( TYPE & dataOut ) const
{
    bool success = false;

    if ( numValues > 0 )
    {
        dataOut = list [ numValues - 1 ];
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template < typename TYPE >
bool AList < TYPE> :: retrieveAtIndex ( TYPE & dataOut, int index ) const
{
    bool success = false;

    if ( ( index < numValues ) && ( index >= 0 ) )
    {
        dataOut = list [index];
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template < typename TYPE >
bool AList < TYPE> :: retrieve ( TYPE & dataIO ) const
{
    bool success = false;

    if ( numValues > 0 )
    {
        for ( int i = 0; i < numValues; i++ )
        {
            if ( list [i] == dataIO )
            {
                success = retrieveAtIndex( dataIO, i );
                i = numValues;
            }
        }
    }

    return success;
}

//*****************************************************************************************************

template < typename TYPE >
bool AList < TYPE> :: updateFront ( const TYPE & dataIn )
{
    bool success = false;

    if ( numValues > 0 )
    {
        list [0] = dataIn;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template < typename TYPE >
bool AList < TYPE> :: updateBack ( const TYPE & dataIn )
{
    bool success = false;

    if ( numValues > 0 )
    {
        list [ numValues - 1 ] = dataIn;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template < typename TYPE >
bool AList < TYPE> :: updateAtIndex ( const TYPE & dataIn, int index )
{
    bool success = false;

    if ( ( index < numValues ) && ( index >= 0 ) )
    {
        list [index] = dataIn;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template < typename TYPE >
bool AList < TYPE> :: update ( const TYPE & dataIn )
{
    bool success = false;

    if ( numValues > 0 )
    {
        for ( int i = 0; i < numValues; i++ )
        {
            if ( list [i] == dataIn )
            {
                success = updateAtIndex ( dataIn, i );
                i = numValues;
            }
        }
    }

    return success;
}

//*****************************************************************************************************

template < typename TYPE >
bool AList < TYPE> :: display () const
{
    bool success = false;

    if ( numValues > 0 )
    {
        for ( int i = 0; i < numValues; i++ )
            cout << "[" << i << "]" << " " << list [i] << "\t";

        success = true;
    }

    return success;
}

//*****************************************************************************************************

template < typename TYPE >
bool AList < TYPE> :: getSmallest ( TYPE & dataOut ) const
{
    bool success = false;
    TYPE min = list [0];
    int minIndex = 0;

    if ( numValues > 0 )
    {
        for ( int i = 1; i < numValues; i++ )
        {
            if ( min > list [i] )
            {
                min = list [i];
                minIndex = i;
            }
        }

        dataOut = list [minIndex];
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template < typename TYPE >
int AList < TYPE> :: getCapacity () const
{
    return capacity;
}

//*****************************************************************************************************

template < typename TYPE >
int AList < TYPE> :: getNumValues () const
{
    return numValues;
}

//*****************************************************************************************************

template < typename TYPE >
bool AList < TYPE> :: isEmpty () const
{
    return ( numValues == 0 );
}

//*****************************************************************************************************

template < typename TYPE >
bool AList < TYPE> :: isFull () const
{
    return ( numValues == capacity );
}

//*****************************************************************************************************

template < typename TYPE >
bool AList < TYPE> :: clear ()
{
    numValues = 0;

    return true;
}

//*****************************************************************************************************

#endif
