//*****************************************************************************************************
//
//		File:			    stack.h
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
//		This file defines the class for a templated array based Stack.
//
//		Other files required:
//                       1.   stackDriver.cpp
//
//*****************************************************************************************************

#ifndef STACK_H
#define STACK_H

//*****************************************************************************************************

template <typename TYPE>
class Stack
{
    private:
        int top;
        int capacity;
        TYPE * stack;

    public:
        Stack(int cap = 100);
        ~Stack();
        bool push (const TYPE & dataIn);
        bool peek (TYPE & dataOut) const;
        bool pop ( TYPE & dataOut);
        int getNumValues () const;
        bool isFull() const;
        bool isEmpty() const;
};

//*****************************************************************************************************

template <typename TYPE>
Stack <TYPE> :: Stack (int cap)
{
    capacity = cap;
    stack = new TYPE [capacity];
    top = -1;
}

//*****************************************************************************************************

template <typename TYPE>
Stack <TYPE> :: ~Stack ()
{
    capacity = 0;
    delete [] stack;
    top = 0;
}

//*****************************************************************************************************
template <typename TYPE>
bool Stack <TYPE> :: push (const TYPE & dataIn)
{
    bool success = false;

    if ( (top + 1) < capacity )
    {
        top++;
        stack [top] = dataIn;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool Stack <TYPE> :: pop ( TYPE & dataOut)
{
    bool success = false;

    if (top > -1)
    {
        dataOut = stack [top];
        top--;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool Stack <TYPE> :: peek (TYPE & dataOut) const
{
    bool success = false;

    if (top > -1)
    {
        dataOut = stack[top];
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
int Stack <TYPE> :: getNumValues () const
{
    return top + 1;
}

//*****************************************************************************************************

template <typename TYPE>
bool Stack <TYPE> :: isFull() const
{
    return (top + 1) == capacity;
}

//*****************************************************************************************************

template <typename TYPE>
bool Stack <TYPE> :: isEmpty() const
{
    return top == -1;
}

//*****************************************************************************************************

#endif stack_h
