//*****************************************************************************************************
//
//		File:			    stackDriver.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #6
//
//		Course Name:		Data Structures I
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    October 24, 2024
//
//
//		This program creates a templated array based Stack and tested using a simple driver program.
//
//		Other files required:
//                       1.   stack.h
//
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "stack.h"

//*****************************************************************************************************

int main ()
{
    Stack <int> myStack (3);
    int topValue;

    if ( myStack.isEmpty() )
        cout << "Stack is empty." << endl;
    else
        cout << "Stack is not empty." << endl;

    cout << endl;

    if ( myStack.push (3) )
        cout << "Pushed 3 onto the stack." << endl;
    else
        cout << "Failed to push 3 onto the stack." << endl;

    if ( myStack.push (8) )
        cout << "Pushed 8 onto the stack." << endl;
    else
        cout << "Failed to push 8 onto the stack." << endl;

    if ( myStack.push (60) )
        cout << "Pushed 60 onto the stack." << endl;
    else
        cout << "Failed to push 60 onto the stack." << endl;

    cout << endl;

    if ( myStack.isFull() )
        cout << "Stack is full." << endl;
    else
        cout << "Stack is not full"  << endl;

    cout << endl;

    cout << "Number of values in the stack: " << myStack.getNumValues() << endl;

    if ( myStack.peek (topValue) )
        cout << "Top value in the stack (peek): " << topValue << endl;
    else
        cout << "Failed to peek." << endl;

    cout << endl;

    cout << "Popping topvalue from the stack. " << endl;

    if ( myStack.pop (topValue) )
        cout << "Popped " << topValue << " from the stack." << endl;
    else
        cout << "Failed to pop from the stack." << endl;

    if ( myStack.peek (topValue) )
        cout << "Top value in the stack (peek): " << topValue << endl;
    else
        cout << "Failed to peek." << endl;

    return 0;
}

//*****************************************************************************************************

/*

Stack is empty.

Pushed 3 onto the stack.
Pushed 8 onto the stack.
Pushed 60 onto the stack.

Stack is full.

Number of values in the stack: 3
Top value in the stack (peek): 60

Popping topvalue from the stack.
Popped 60 from the stack.
Top value in the stack (peek): 8

*/
