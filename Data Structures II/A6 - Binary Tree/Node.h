//*****************************************************************************************************
//
//		File:			    Node.h
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #2
//
//		Course Name:		Data Structures II
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    October 3, 2024
//
//
//		This header file has the definition of Nodes for Binary Tree.
//
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename T>
struct Node
{
    T data;
    Node <T> * left;
    Node <T> * right;
    Node(const T& value, Node <T> * left = nullptr, Node <T> * right = nullptr);
};

//*****************************************************************************************************

template <typename T>
Node <T> :: Node(const T& value, Node <T> * l, Node <T> * r)
{
    data = value;
    left = l;
    right = r;
}

//*****************************************************************************************************

#endif NODE_H
