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
//		This is the driver program for stock class.
//
//		Other files required:
//                       1.   stock.h
//                       2.   stock.cpp
//
//*****************************************************************************************************

#include "stock.h"

//*****************************************************************************************************

int main()
{
    Stock stock1("Apple Inc.", "AAPL", 150.25);
    Stock stock2("Tesla", "TSLA", -350.75);
    Stock stock3("Microsoft Corp.", "MSFT", 320.50);
    Stock stock4(stock3);

    cout << stock1;
    cout << stock2;
    cout << stock3;
    cout << stock4;

    cout << "Comparing " << string(stock3) << " and " << string(stock4) << endl;

    if (stock3 == stock4)
    {
        cout << "Stocks are equal!" << endl << endl;
    }
    else
    {
        cout << "Stocks are not equal!" << endl << endl;
    }

    cout << "Comparing " << string(stock1) << " and " << string(stock3) << endl;

    if (stock1 != stock3)
    {
        cout << "Stocks are different!" << endl << endl;
    }
    else
    {
        cout << "Stocks are the same!" << endl << endl;
    }

    cout << "Testing < operator between " << stock1.getSymbol() << " & "
         << stock2.getSymbol() << endl;

    if (stock1 < stock2)
    {
        cout << string(stock1) << " (" << stock1.getPrice()
             << ") is bigger than " << string(stock2)
             << " (" << stock2.getPrice() << ")" << endl;
    }
    else
    {
        cout << string(stock1) << " (" << stock1.getPrice()
             << ") is less than " << string(stock2)
             << " (" << stock2.getPrice() << ")" << endl;
    }

    return 0;
}

//*****************************************************************************************************

 */

/*

Company Name: Apple Inc.
Stock Symbol: AAPL
Price: 150.25

Company Name: Tesla
Stock Symbol: TSLA
Price: 0

Company Name: Microsoft Corp.
Stock Symbol: MSFT
Price: 320.5

Company Name: Microsoft Corp.
Stock Symbol: MSFT
Price: 320.5

Comparing MSFT and MSFT
Stocks are equal!

Comparing AAPL and MSFT
Stocks are different!

Testing < operator between AAPL & TSLA
AAPL (150.25) is bigger than TSLA (0)

 */