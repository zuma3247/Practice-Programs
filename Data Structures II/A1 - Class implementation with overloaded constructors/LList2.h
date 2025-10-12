//*****************************************************************************************************
//
//		File:			    LList2.h
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
//		This header file has the definition of the templated class "LList2".
//
//		Other files required:
//                       1.   Node.h
//
//*****************************************************************************************************

#ifndef LLIST_H
#define LLIST_H
#include "Node.h"
#include <new>

//*****************************************************************************************************

template <typename TYPE>
class LList2
{
    private:
        Node <TYPE> * front;
        void insertHelper ( Node <TYPE> * pPrev, Node <TYPE> * pAft,
                            Node <TYPE> * pNew);
        bool removeHelper ( Node <TYPE> * pPrev, Node <TYPE> * pCurr,
                            TYPE & dataIO);
        void displayHelper (Node <TYPE> * pTemp) const;


    public:
        LList2();
        ~LList2();
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
LList2 <TYPE> :: LList2 ()
{
    front = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
LList2 <TYPE> :: ~LList2 ()
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
bool LList2 <TYPE> :: insert (const TYPE & dataIn )
{
    bool success = true;
    Node <TYPE> * pBefore = nullptr;
    Node <TYPE> * pAfter = front;
    Node <TYPE> * pNew;

    pNew = new (nothrow) Node <TYPE> ( dataIn, pAfter );

    if (pNew == nullptr)
        success = false;
    else
        insertHelper(pBefore, pAfter, pNew);

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
void LList2 <TYPE> :: insertHelper (Node <TYPE> * pPrev, Node <TYPE> * pAfter,
                                    Node <TYPE> * pNew)
{
    if (pAfter == nullptr || pNew -> data < pAfter -> data)
    {
        if (pPrev != nullptr)
        {
            pPrev -> next = pNew;
            pNew -> next = pAfter;
        }
        else
        {
            front = pNew;
            pNew -> next = pAfter;
        }
        return;
    }

    insertHelper(pAfter, pAfter -> next, pNew);
}

//*****************************************************************************************************

template <typename TYPE>
bool LList2 <TYPE> :: remove (TYPE & dataIO )
{
    bool success = false;
    Node<TYPE>* pPrev = nullptr;
    Node<TYPE>* pCurr = front;

    if (removeHelper(pPrev, pCurr, dataIO))
    {
        success = true;
    }
    else
    {
        success = false;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList2 <TYPE> :: removeHelper (Node <TYPE> * pPrev, Node <TYPE> * pCurr,
                                    TYPE & dataIO)
{
    if (pCurr == nullptr)
        return false;

    if (pCurr -> data == dataIO)
    {
        dataIO = pCurr -> data;

        if (pPrev != nullptr)
        {
            pPrev -> next = pCurr -> next;
        } else
        {
            front = pCurr -> next;
        }
        delete pCurr;
        return true;
    }

    return removeHelper(pCurr, pCurr -> next, dataIO);
}

//*****************************************************************************************************

template <typename TYPE>
bool LList2 <TYPE> :: retrieve (TYPE & dataIO ) const
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
bool LList2 <TYPE> :: viewFront (TYPE & dataOut ) const
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
bool LList2 <TYPE> :: viewRear (TYPE & dataOut ) const
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
void LList2 <TYPE> :: display () const
{
    Node <TYPE> * pTemp = front;
    displayHelper (pTemp);
    cout << endl;
}

//*****************************************************************************************************

template <typename TYPE>
void LList2 <TYPE> :: displayHelper (Node <TYPE> * pTemp) const
{
    if (pTemp == nullptr)
    {
        return;
    }

    cout << pTemp -> data;
    displayHelper(pTemp -> next);
}

//*****************************************************************************************************

template <typename TYPE>
int LList2 <TYPE> :: getNumValues () const
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
bool LList2 <TYPE> :: isEmpty () const
{
    return (front == nullptr);
}

//*****************************************************************************************************

template <typename TYPE>
bool LList2 <TYPE> :: isFull () const
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

#endif LLIST_H
