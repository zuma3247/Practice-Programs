//*****************************************************************************************************
//
//		File:			    PriorityQueue.h
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #7
//
//		Course Name:		Data Structures II
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    March 19, 2025
//
//
//		This program defines a Priority Queue.
//
//		Other files required:
//                       1.   driver.cpp
//
//*****************************************************************************************************

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

//*****************************************************************************************************

#include <iostream>
#include <algorithm>
using namespace std;

//*****************************************************************************************************

template <typename T>
class PriorityQueue
{
    private:
        T * heap;
        int capacity;
        int size;
        void heapify(int i);

    public:
        PriorityQueue(int cap = 20);
        ~PriorityQueue();
        void enqueue(const T & value);
        bool dequeue(T & value);
        bool isEmpty() const;
        void makeEmpty();
        void print() const;
};

//*****************************************************************************************************

template <typename T>
PriorityQueue <T> :: PriorityQueue(int cap)
{
    capacity = cap;
    size = 0;
    heap = new T[capacity];
}

//*****************************************************************************************************

template <typename T>
PriorityQueue <T> :: ~PriorityQueue()
{
    capacity = 0;
    size = 0;
    delete [] heap;
}

//*****************************************************************************************************

template <typename T>
void PriorityQueue <T> :: enqueue(const T & value)
{
    int child = size;
    size++;
    int parent = (child - 1) / 2;

    if (size >= capacity)
    {
        cout << "Priority queue is full (overflow)" << endl;
        return;
    }

    while ((child > 0) && (value > heap[parent]))
    {
        heap[child] = heap[parent];
        child = parent;
        parent = (child - 1) / 2;
    }

    heap[child] = value;
}

//*****************************************************************************************************

template <typename T>
bool PriorityQueue <T> :: dequeue(T & value)
{
    bool success = false;

    if (!isEmpty())
    {
        value = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(0);

        success = true;
    }
    else
    {
        cout << "Priority queue is Empty" << endl;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool PriorityQueue <T> :: isEmpty() const
{
    return (size == 0);
}

//*****************************************************************************************************

template <typename T>
void PriorityQueue <T> :: makeEmpty()
{
    size = 0;
}

//*****************************************************************************************************

template <typename T>
void PriorityQueue <T> :: print() const
{
    cout << "Priority Queue as array: [";

    for (int i = 0; i < size; ++i)
    {
        cout << heap[i];
        if (i < size - 1)
        {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

//*****************************************************************************************************

template <typename T>
void PriorityQueue <T> :: heapify(int i)
{
    bool success = true;
    int left,
        right,
        largest;

    while (success == true)
    {
        left = 2 * i + 1;
        right = 2 * i + 2;
        largest = i;

        if (left < size && heap[left] > heap[largest])
        {
            largest = left;
        }

        if (right < size && heap[right] > heap[largest])
        {
            largest = right;
        }

        if (largest == i)
        {
            success = false;
        }
        else
        {
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }
}

//*****************************************************************************************************

#endif