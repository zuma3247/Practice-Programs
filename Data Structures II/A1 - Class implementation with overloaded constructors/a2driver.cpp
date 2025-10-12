//*****************************************************************************************************
//
//		File:			    stock.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #2
//
//		Course Name:		Data Structures II
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    January 29, 2025
//
//
//		This is the driver program for developing a template Linked List class
//		to store Stock objects.
//
//		Other files required:
//                       1.   stock.h
//                       2.   stock.cpp
//                       3.   Node.h
//                       4.   LList2.h
//
//*****************************************************************************************************

#include "stock.h"
#include "LList2.h"

//*****************************************************************************************************

int main()
{
    LList2 <Stock> stockList;

    Stock stock1("Apple Inc.", "AAPL", 150.25);
    Stock stock2("Tesla", "TSLA", 350.75);
    Stock stock3("Microsoft Corp.", "MSFT", 320.50);
    Stock stock4("Amazon Inc.", "AMZN", 128.20);

    stockList.insert(stock1);
    stockList.insert(stock2);
    stockList.insert(stock3);
    stockList.insert(stock4);

    cout << "Displaying inserted stocks: " << endl;
    stockList.display();

    cout << "Removing " << string(stock2) << " and " <<  string(stock4)
         << "." << endl << endl;

    stockList.remove(stock2);
    stockList.remove(stock4);

    cout << "Displaying remaining stocks: " << endl;
    stockList.display();

    return 0;
}

//*****************************************************************************************************

/*
Displaying inserted stocks:
Company Name: Tesla, Stock Symbol: TSLA, Price: 350.75
Company Name: Microsoft Corp., Stock Symbol: MSFT, Price: 320.5
Company Name: Apple Inc., Stock Symbol: AAPL, Price: 150.25
Company Name: Amazon Inc., Stock Symbol: AMZN, Price: 128.2

Removing TSLA and AMZN.

Displaying remaining stocks:
Company Name: Microsoft Corp., Stock Symbol: MSFT, Price: 320.5
Company Name: Apple Inc., Stock Symbol: AAPL, Price: 150.25
*/