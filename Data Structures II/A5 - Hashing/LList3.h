//*****************************************************************************************************
//
//		File:			    LList3.h
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
//		This header file has the definition of the templated class "LList3".
//
//		Other files required:
//                       1.   Node.h
//
//*****************************************************************************************************

#ifndef LLIST3_H
#define LLIST3_H
#include "Node.h"
#include <new>

//*****************************************************************************************************

template <typename TYPE>
class LList3
{
private:
    Node <TYPE> * front;

public:
    LList3();
    ~LList3();
    bool insertFront ( const TYPE & dataIn );
    bool remove ( TYPE & dataIO );
    bool retrieve ( TYPE & dataIO ) const;
    void display () const;
    int getNumValues () const;
    bool isEmpty () const;
};

//*****************************************************************************************************

template <typename TYPE>
LList3 <TYPE> :: LList3 ()
{
    front = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
LList3 <TYPE> :: ~LList3 ()
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
bool LList3 <TYPE> :: insertFront(const TYPE & dataIn)
{
    bool success = false;
    Node <TYPE> * pNew = new Node <TYPE> (dataIn, front);

    if (pNew)
    {
        front = pNew;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList3 <TYPE> :: remove(TYPE & dataIO)
{
    bool success = false;
    Node <TYPE> * pBefore = nullptr;
    Node <TYPE> * pTemp = front;

    while (pTemp && pTemp -> data != dataIO)
    {
        pBefore = pTemp;
        pTemp = pTemp -> next;
    }

    if (pTemp)
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
bool LList3 <TYPE> :: retrieve(TYPE & dataIO) const
{
    bool success = false;
    Node <TYPE> * pTemp = front;

    while (pTemp)
    {
        if (pTemp -> data == dataIO)
        {
            dataIO = pTemp -> data;
            success = true;
        }
        pTemp = pTemp -> next;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
void LList3 <TYPE> :: display () const
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
int LList3 <TYPE> :: getNumValues () const
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
bool LList3 <TYPE> :: isEmpty () const
{
    return (front == nullptr);
}

//*****************************************************************************************************

#endif LLIST3_H
