//*****************************************************************************************************
//
//		File:			    Node.h
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #7
//
//		Course Name:		Data Structures I
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    October 31, 2024
//
//
//		This header file has the definition of Nodes for Linked Lists.
//
//		To be used in Other files:
//                       1.   queue.h
//                       1.   qDriver.cpp
//
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename TYPE>
struct Node
{
    TYPE data;
    Node <TYPE> * next;

    Node ();
    Node ( const TYPE & dataIn, Node <TYPE> * nextNode = nullptr );
};

//*****************************************************************************************************

template <typename TYPE>
Node <TYPE> :: Node()
{
    data = 0;
    next = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
Node <TYPE> :: Node ( const TYPE & dataIn, Node <TYPE> * nextNode )
{
    data = dataIn;
    next = nextNode;
}

//*****************************************************************************************************

#endif NODE_H
