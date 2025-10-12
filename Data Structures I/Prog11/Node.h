//*****************************************************************************************************
//
//		File:			    Node.h
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
//		This header file has the definition of Nodes for a Doubly Linked List.
//
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename TYPE>
struct Node
{
    TYPE data;
    Node <TYPE> * prev;
    Node <TYPE> * next;

    Node ();
    Node ( const TYPE & dataIn, Node <TYPE> * nextNode = nullptr,
           Node <TYPE> * p = nullptr);
};

//*****************************************************************************************************

template <typename TYPE>
Node <TYPE> :: Node()
{
    data = 0;
    next = nullptr;
    prev = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
Node <TYPE> :: Node ( const TYPE & dataIn, Node <TYPE> * nextNode, Node <TYPE> * p)
{
    data = dataIn;
    next = nextNode;
    prev = p;
}

//*****************************************************************************************************

#endif NODE_H
