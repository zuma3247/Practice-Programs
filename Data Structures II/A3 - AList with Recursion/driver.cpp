//*****************************************************************************************************
//
//		File:			    driver.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #3
//
//		Course Name:		Data Structures II
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    Feb 5, 2025
//
//
//		This is the driver program for recursive implentation of Array List.
//
//		Other files required:
//                       1.   AList2.cpp
//                       2.   Stock.cpp
//                       3.   Stock.h
//
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "Alist2.h"
#include "Stock.cpp"

//*****************************************************************************************************

int main()
{
    AList2 <int> intList(10);
    AList2 <Stock> stockList(5);
    int num;
    int temp;
    Stock st;

    intList.insert(50);
    intList.insert(20);
    intList.insert(70);
    intList.insert(10);
    intList.insert(40);

    cout << "Integer List: " ;
    intList.print();
    cout << endl;

    intList.remove(70);
    cout << "After Deleting 70: ";
    intList.print();
    cout << endl;

    num = intList.binarySearch(90);
    cout << "Binary Search for 90: " << num << endl;

    Stock stock1("Apple Inc.", "AAPL", 150.25);
    Stock stock2("Tesla", "TSLA", 350.75);
    Stock stock3("Microsoft Corp.", "MSFT", 320.50);
    Stock stock4("Amazon Inc.", "AMZN", 128.20);
    Stock stock5(stock4);

    stockList.insert(stock1);
    stockList.insert(stock2);
    stockList.insert(stock3);
    stockList.insert(stock4);
    stockList.insert(stock5);

    cout << "Stock List: " ;
    stockList.print();
    cout << endl;

    cout << "Removing stock4: ";
    stockList.remove(stock4);
    stockList.print();
    cout << endl;

    num = stockList.binarySearch(stock2);
    cout << "Find stock2: " << num;

    return 0;
}

//*****************************************************************************************************