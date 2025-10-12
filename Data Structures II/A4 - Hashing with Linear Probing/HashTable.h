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

//*****************************************************************************************************

template <typename T>
class HashTable
{
private:
    struct Entry
    {
        T data;
        bool isOccupied;
        bool isDeleted;
        Entry()
        {
            isOccupied = false;
            isDeleted = false;
        }
    };
    Entry * table;
    int tableSize;
    int count;

    void resize();
    int nextPrime(int n) const;
    bool isPrime(int n) const;
    int hash(const T & dataIn) const;
    void displayHelper(ostream & out) const;

public:
    HashTable(int size = 10);
    ~HashTable();
    bool insert(const T & item);
    bool remove(T & data);
    bool retrieve(T & dataOut) const;
    void display() const;

    template <typename T>
    friend ostream & operator << (ostream & out, const HashTable <T> & table);
};

//*****************************************************************************************************

template <typename T>
void HashTable <T> :: resize()
{
    int newSize;
    Entry * newTable;

    newSize = nextPrime(2 * tableSize);
    newTable = new Entry[newSize];

    for (int i = 0; i < tableSize; i++)
    {
        if (table[i].isOccupied && !table[i].isDeleted)
        {
            int loc = table[i].data % newSize;

            while (newTable[loc].isOccupied)
                loc = (loc + 1) % newSize;

            newTable[loc] = table[i];
        }
    }

    delete[] table;
    table = newTable;
    tableSize = newSize;
}

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
int HashTable <T> :: hash(const T & dataIn) const
{
    return dataIn % tableSize;
}

//*****************************************************************************************************

template <typename T>
void HashTable <T> :: displayHelper(ostream & out) const
{
    for (int i = 0; i < tableSize; i++)
    {
        out << i << ": ";

        if (!table[i].isOccupied)
        {
            out << "[empty]";
        }
        else if (table[i].isDeleted)
        {
            out << "[deleted]";
        }
        else
        {
            out << table[i].data;
        }
        out << endl;
    }
}

//*****************************************************************************************************

template <typename T>
HashTable <T> :: HashTable(int size)
{
    tableSize = nextPrime(size);
    table = new Entry[tableSize];
    count = 0;
}

//*****************************************************************************************************

template <typename T>
HashTable <T> :: ~HashTable()
{
    tableSize = 0;
    count = 0;
    delete[] table;
}

//*****************************************************************************************************

template <typename T>
bool HashTable <T> :: insert(const T & item)
{
    if (static_cast<double> (count) / tableSize > 0.5)
    {
        resize();
    }

    int loc = hash(item);
    bool success = false;

    while(table[loc].isOccupied && !table[loc].isDeleted
          && table[loc].data != item)
    {
        loc = (loc + 1) % tableSize;
    }

    if(!table[loc].isOccupied || table[loc].isDeleted)
    {
        table[loc].data = item;
        table[loc].isOccupied = true;
        table[loc].isDeleted = false;
        count++;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool HashTable <T> :: remove(T & data)
{
    int loc = hash(data);
    bool success = false;

    while(table[loc].isOccupied)
    {
        if(!table[loc].isDeleted && table[loc].data == data)
        {
            table[loc].isDeleted = true;
            table[loc].isOccupied = false;
            count--;
            success = true;
        }

        loc = (loc + 1) % tableSize;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool HashTable <T> :: retrieve(T & dataOut) const
{
    int loc = hash(dataOut);
    bool success = false;

    while (table[loc].isOccupied)
    {
        if (!table[loc].isDeleted && table[loc].data == dataOut)
        {
            dataOut = table[loc].data;
            success = true;
        }

        loc = (loc + 1) % tableSize;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
void HashTable <T> :: display() const
{
    displayHelper(cout);
}

//*****************************************************************************************************

template <typename T>
ostream & operator << (ostream & out, const HashTable <T> & table)
{
    table.displayHelper(out);
    return out;
}

//*****************************************************************************************************

#endif HASHTABLE_H
