//*****************************************************************************************************
//
//     File:               Assignment 4.cpp
//
//     Student:            Muazuddin Mohammed
//
//     Assignment:         Assignment#4
//
//     Course Name:        Computer Programming #2
//
//     Course Number:      COSC 1560
//
//     Due:                September 25, 2023
//
//
//     This program implements functions and pointers.
//
//*****************************************************************************************************

#include <iostream>
using namespace std;

void f1 (const int array [], int size);
void f2 (int *ptr, int size);
void f3 (int array [], int size);
void f4 (int array [], int size);

//*****************************************************************************************************

int main()
{
    const int SIZE = 5;
    int numbers [SIZE] = {10, 22, 34, 48, 59};
    int *ptr = nullptr;
    ptr = numbers;

    return 0;
}

//*****************************************************************************************************

void f1 (const int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Value: " << array [i] << endl
             << "Address" << &array [i] << endl
             << endl;
    }
}

//*****************************************************************************************************

void f2 (int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Value: " << * (ptr + i) << endl
             << "Address" << ptr + i << endl
             << endl;
    }
}

//*****************************************************************************************************

void f3 (int array [], int size)
{
    int value,
        *ptr = nullptr;
    bool errorcheck = true;
    ptr = array;

    for (int i = 0; i < 3; i++)
    {
        do
        {
            cout << "Enter value " << i + 1 << " between 0 and " << size - 1 << ":" << endl;
            cin >> value;

            if ((value >= 0) && (value <= 4))
            {
                errorcheck = false;
            }
        }
        while (errorcheck);

        ptr = &array [value];
        cout << "Address: " << ptr << endl << "Value: " << *ptr << endl << endl;
    }
}

//*****************************************************************************************************

void f4 (int array [], int size)
{
    int sum,
        value1,
        value2,
        *ptr1 = nullptr,
        *ptr2 = nullptr;

    bool errorcheck = true;

    do
    {
        cout << "Enter value 1 between 0 and " << size - 1 << ":" << endl;
        cin >> value1;

        if ((value1 >= 0) && (value1 <= 4))
        {
            errorcheck = false;
        }
    }
    while (errorcheck);

    ptr1 = &array [value1];

    do
    {
        cout << "Enter value 2 between 0 and " << size - 1 << ":" << endl;
        cin >> value2;

        if ((value2 >= 0) && (value2 <= 4))
        {
            errorcheck = false;
        }
    }
    while (errorcheck);

    ptr2 = &array [value2];

    sum = *ptr1 + *ptr2;
    cout << "Sum is: " << sum << endl;

}

//*****************************************************************************************************