//*****************************************************************************************************
//
//		File:			    LList.h
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #5
//
//		Course Name:		Data Structures I
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    October 3, 2024
//
//
//		This header file has the definition of the templated class "LList".
//
//		Other files required:
//                       1.   Node.h
//
//*****************************************************************************************************

#ifndef PROG5_LLIST_H
#define PROG5_LLIST_H
#include "Node.h"
#include <new>

//*****************************************************************************************************

template <typename TYPE>
class LList
{
    private:
        Node <TYPE> * front;

    public:
        LList();
        ~LList();
        bool insert ( const TYPE & dataIn );
        bool remove ( TYPE & dataIO );
        bool retrieve ( TYPE & dataIO ) const;
        bool viewFront ( TYPE & dataOut ) const;
        bool viewRear ( TYPE & dataOut ) const;
        void display () const;
        int getNumValues () const;
        bool isEmpty () const;
        bool isFull () const;
};

//*****************************************************************************************************

template <typename TYPE>
LList <TYPE> :: LList ()
{
    front = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
LList <TYPE> :: ~LList ()
{
    Node <TYPE> * pTemp;

    while (front)
    {
        pTemp = front;
        front = front -> next;
        delete pTemp;
    }
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE> :: insert ( const TYPE & dataIn )
{
    bool success = false;
    Node <TYPE> * pBefore = nullptr;
    Node <TYPE> * pAfter = front;
    Node <TYPE> * pNew;

    while ( (pAfter) && ( pAfter -> data < dataIn ) )
    {
        pBefore = pAfter;
        pAfter = pAfter -> next;
    }

    pNew = new (nothrow) Node <TYPE> ( dataIn, pAfter );

    if (pNew)
    {
        if (pBefore)
            pBefore -> next = pNew;
        else
            front = pNew;

        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE> :: remove ( TYPE & dataIO )
{
    bool success = false;
    Node <TYPE> * pBefore = nullptr;
    Node <TYPE> * pTemp = front;

    while ( (pTemp) && ( pTemp -> data < dataIO ) )
    {
        pBefore = pTemp;
        pTemp = pTemp -> next;
    }

    if ( (pTemp) && ( pTemp -> data == dataIO ) )
    {
        dataIO = pTemp -> data;

        if (pBefore)
            pBefore -> next = pTemp -> next;
        else
            front = pTemp -> next;

        delete pTemp;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE> :: retrieve ( TYPE & dataIO ) const
{
    bool success = false;
    Node <TYPE> * pTemp = front;

    while ( (pTemp) && ( pTemp -> data < dataIO ) )
        pTemp = pTemp -> next;

    if ( (pTemp) && ( pTemp -> data == dataIO ) )
    {
        dataIO = pTemp -> data;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE> :: viewFront ( TYPE & dataOut ) const
{
    bool success = false;
    Node <TYPE> * pTemp = front;

    if (pTemp)
    {
        dataOut = pTemp -> data;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE> :: viewRear ( TYPE & dataOut ) const
{
    bool success = false;
    Node <TYPE> * pTemp = front;

    while ( (pTemp) && ( pTemp -> next ) )
        pTemp = pTemp -> next;

    if (pTemp)
    {
        dataOut = pTemp -> data;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
void LList <TYPE> :: display () const
{
    Node <TYPE> * pTemp = front;

    while (pTemp)
    {
        cout << pTemp -> data << " \t";
        pTemp = pTemp -> next;
    }
}

//*****************************************************************************************************

template <typename TYPE>
int LList <TYPE> :: getNumValues () const
{
    Node <TYPE> * pTemp = front;
    int numValues = 0;

    while (pTemp)
    {
        numValues++;
        pTemp = pTemp -> next;
    }

    return numValues;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE> :: isEmpty () const
{
    return (front == nullptr);
}

//*****************************************************************************************************

template <typename TYPE>
bool LList <TYPE> :: isFull () const
{
    bool success = true;
    Node <TYPE> * pTemp;

    pTemp = new (nothrow) Node <TYPE>;

    if (pTemp)
    {
        success = false;
        delete pTemp;
    }

    return success;
}

//*****************************************************************************************************

#endif //PROG5_LLIST_H
