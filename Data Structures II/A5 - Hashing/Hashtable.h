//*****************************************************************************************************
//
//		File:			    HashTable.h
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #4
//
//		Course Name:		Data Structures II
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    February 14, 2025
//
//
//		This program defines a Hash Table class that uses chain linking.
//
//		Other files required:
//                       1.   LList3.cpp
//
//*****************************************************************************************************

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LList3.h"
#include "Stock.h"

//*****************************************************************************************************

template <typename T>
class HashTable
{
private:
    LList3 <T> * table;
    int tableSize;

    int nextPrime(int n) const;
    bool isPrime(int n) const;

public:
    HashTable(int size = 10);
    ~HashTable();
    bool insert(const T & item);
    bool remove(T & data);
    bool retrieve(T & dataOut) const;
    void display() const;
};

//*****************************************************************************************************

template <typename T>
int HashTable <T> :: nextPrime(int n) const
{
    while (!isPrime(n))
        n++;

    return n;
}

//*****************************************************************************************************

template <typename T>
bool HashTable <T> :: isPrime(int n) const
{
    bool success = true;

    if (n <= 1)
        success = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            success = false;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
HashTable <T> :: HashTable(int size)
{
    tableSize = nextPrime(size);
    table = new LList3 <T> [tableSize];
}

//*****************************************************************************************************

template <typename T>
HashTable <T> :: ~HashTable()
{
    tableSize = 0;
    delete[] table;
}

//*****************************************************************************************************

template <typename T>
bool HashTable <T> :: insert(const T & item)
{
    bool success = false;
    int index;

    index = item.hash(tableSize);
    success = table[index].insertFront(item);

    return success;
}

//*****************************************************************************************************

template <typename T>
bool HashTable <T> :: remove(T & item)
{
    bool success = false;
    int index;

    index = item.hash(tableSize);
    success = table[index].remove(item);

    return success;
}

//*****************************************************************************************************

template <typename T>
bool HashTable <T> :: retrieve(T & item) const
{
    bool success = false;
    int index;

    index = item.hash(tableSize);
    success = table[index].retrieve(item);

    return success;
}

//*****************************************************************************************************

template <typename T>
void HashTable <T> :: display() const
{
    for (int i = 0; i < tableSize; i++)
    {
        cout << "Index " << i << ": ";
        table[i].display();
        cout << endl;
    }
}

//*****************************************************************************************************

#endif HASHTABLE_H
