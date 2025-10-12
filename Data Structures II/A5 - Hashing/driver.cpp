//*****************************************************************************************************
//
//		File:			    driver.cpp
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
//		This is a driver program for a Hash Table class that uses linked list chaining.
//
//		Other files required:
//                       1.   HashTable.h
//
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "Hashtable.h"

//*****************************************************************************************************

int main()
{
    int numStocks = 7;
    HashTable <Stock> stockTable(numStocks);
    Stock stocks[] = { Stock("Apple", "AAPL", 150.0),
                       Stock("Google", "GOOGL", 2800.0),
                       Stock("Tesla", "TSLA", 700.0),
                       Stock("Amazon", "AMAZ", 390.0),
                       Stock("Microsoft", "MSFT", 320.5),
                       Stock("Nvidia", "NVDA", 650.8),
                       Stock("Meta", "META", 340.2),
                       Stock("Netflix", "NFLX", 420.7),
                       Stock("Adobe", "ADBE", 570.3),
                       Stock("Intel", "INTC", 45.9) };
    bool success = false;

    for (int i = 0; i < 10; i++)
    {
        cout << "Inserting stock: " << stocks[i];
        if (stockTable.insert(stocks[i]))
        {
            cout << "- Successful" << endl;
        }
        else
            cout << "- Unsuccessful" << endl;
    }

    cout << endl << "Displaying Hashtable: " << endl;
    stockTable.display();

    cout << endl << "Removing Tesla" << endl;
    success = stockTable.remove(stocks[2]);
    if (success)
    {
        cout << "Successfully removed " << stocks[2] << endl;
    }
    else
        cout << "Unable to remove " << stocks[2] << endl;

    cout << endl << "Displaying Hashtable: " << endl;
    stockTable.display();

    cout << endl << "Finding Google: " << endl;
    success = stockTable.retrieve(stocks[1]);
    if (success)
    {
        cout << "[Found] -> " << stocks[1] << endl;
    }
    else
        cout << "[Not Found]" << endl;

    return 0;
}


/*

Inserting stock: [Company Name: Apple, Stock Symbol: AAPL, Price: 150]- Successful
Inserting stock: [Company Name: Google, Stock Symbol: GOOGL, Price: 2800]- Successful
Inserting stock: [Company Name: Tesla, Stock Symbol: TSLA, Price: 700]- Successful
Inserting stock: [Company Name: Amazon, Stock Symbol: AMAZ, Price: 390]- Successful
Inserting stock: [Company Name: Microsoft, Stock Symbol: MSFT, Price: 320.5]- Successful
Inserting stock: [Company Name: Nvidia, Stock Symbol: NVDA, Price: 650.8]- Successful
Inserting stock: [Company Name: Meta, Stock Symbol: META, Price: 340.2]- Successful
Inserting stock: [Company Name: Netflix, Stock Symbol: NFLX, Price: 420.7]- Successful
Inserting stock: [Company Name: Adobe, Stock Symbol: ADBE, Price: 570.3]- Successful
Inserting stock: [Company Name: Intel, Stock Symbol: INTC, Price: 45.9]- Successful

Displaying Hashtable:
Index 0: [Company Name: Microsoft, Stock Symbol: MSFT, Price: 320.5]
Index 1:
Index 2: [Company Name: Meta, Stock Symbol: META, Price: 340.2] 	[Company Name: Nvidia, Stock Symbol: NVDA, Price: 650.8] 	[Company Name: Tesla, Stock Symbol: TSLA, Price: 700]
Index 3:
Index 4: [Company Name: Intel, Stock Symbol: INTC, Price: 45.9] 	[Company Name: Netflix, Stock Symbol: NFLX, Price: 420.7]
Index 5:
Index 6: [Company Name: Adobe, Stock Symbol: ADBE, Price: 570.3] 	[Company Name: Amazon, Stock Symbol: AMAZ, Price: 390] 	[Company Name: Google, Stock Symbol: GOOGL, Price: 2800] 	[Company Name: Apple, Stock Symbol: AAPL, Price: 150]

Removing Tesla
Successfully removed [Company Name: Tesla, Stock Symbol: TSLA, Price: 700]

Displaying Hashtable:
Index 0: [Company Name: Microsoft, Stock Symbol: MSFT, Price: 320.5]
Index 1:
Index 2: [Company Name: Meta, Stock Symbol: META, Price: 340.2] 	[Company Name: Nvidia, Stock Symbol: NVDA, Price: 650.8]
Index 3:
Index 4: [Company Name: Intel, Stock Symbol: INTC, Price: 45.9] 	[Company Name: Netflix, Stock Symbol: NFLX, Price: 420.7]
Index 5:
Index 6: [Company Name: Adobe, Stock Symbol: ADBE, Price: 570.3] 	[Company Name: Amazon, Stock Symbol: AMAZ, Price: 390] 	[Company Name: Google, Stock Symbol: GOOGL, Price: 2800] 	[Company Name: Apple, Stock Symbol: AAPL, Price: 150]

Finding Google:
[Found] -> [Company Name: Google, Stock Symbol: GOOGL, Price: 2800]

 */