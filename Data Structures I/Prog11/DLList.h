//*****************************************************************************************************
//
//		File:			    DList.h
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #11
//
//		Course Name:		Data Structures I
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    December 3, 2024
//
//
//		This header file has the definition of the templated class "DLList".
//
//		Other files required:
//                       1.   Node.h
//
//*****************************************************************************************************

#ifndef DLLIST_H
#define DLLIST_H
#include "Node.h"
#include <new>

//*****************************************************************************************************

template <typename TYPE>
class DLList
{
private:
    Node <TYPE> * front;
    Node <TYPE> * rear;

public:
    DLList();
    ~DLList();
    bool insert ( const TYPE & dataIn );
    bool remove ( TYPE & dataIO );
    bool retrieve ( TYPE & dataIO ) const;
    bool viewFront ( TYPE & dataOut ) const;
    bool viewRear ( TYPE & dataOut ) const;
    void display () const;
    void displayReverse() const;
    int getNumValues () const;
    bool isEmpty () const;
    bool isFull () const;
};

//*****************************************************************************************************

template <typename TYPE>
DLList <TYPE> :: DLList ()
{
    front = nullptr;
    rear = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
DLList <TYPE> :: ~DLList ()
{
    Node <TYPE> * pTemp;

    while (front)
    {
        pTemp = front;
        front = front -> next;
        delete pTemp;
    }

    rear = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
bool DLList <TYPE> :: insert ( const TYPE & dataIn )
{
    bool success = false;
    Node <TYPE> * pBefore = nullptr;
    Node <TYPE> * pAfter = front;
    Node <TYPE> * pNew;

    while ( (pAfter) && ( pAfter -> data < dataIn ) )
        pAfter = pAfter -> next;

    if (pAfter)
        pBefore = pAfter -> prev;
    else
        pBefore = rear;

    pNew = new (nothrow) Node <TYPE> ( dataIn, pAfter, pBefore );

    if (pNew)
    {
        if (pBefore)
            pBefore -> next = pNew;
        else
            front = pNew;

        if (pAfter)
            pAfter -> prev = pNew;
        else
            rear = pNew;

        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool DLList <TYPE> :: remove ( TYPE & dataIO )
{
    bool success = false;
    Node <TYPE> * pDel = front;

    while ( (pDel) && (pDel -> data < dataIO) )
        pDel = pDel -> next;

    if ( (pDel) && (pDel -> data == dataIO) )
    {
        if ( (pDel -> next) )
            (pDel -> next) -> prev = pDel -> prev;
        else
            rear = pDel -> prev;

        if ( (pDel -> prev) )
            (pDel -> prev) -> next = pDel -> next;
        else
            front = pDel -> next;

        delete pDel;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool DLList <TYPE> :: retrieve ( TYPE & dataIO ) const
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
bool DLList <TYPE> :: viewFront ( TYPE & dataOut ) const
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
bool DLList <TYPE> :: viewRear ( TYPE & dataOut ) const
{
    bool success = false;
    Node <TYPE> * pTemp = rear;

    if (pTemp)
    {
        dataOut = pTemp -> data;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
void DLList <TYPE> :: display () const
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
void DLList <TYPE> :: displayReverse() const
{
    Node <TYPE> * pTemp = rear;

    while (pTemp)
    {
        cout << pTemp -> data;
        pTemp = pTemp -> prev;
    }
}

//*****************************************************************************************************

template <typename TYPE>
int DLList <TYPE> :: getNumValues () const
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
bool DLList <TYPE> :: isEmpty () const
{
    return (front == nullptr);
}

//*****************************************************************************************************

template <typename TYPE>
bool DLList <TYPE> :: isFull () const
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

#endif DLLIST_H
