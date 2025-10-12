//*****************************************************************************************************
//
//		File:			    stock.h
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
//		This header file defines a Stock class.
//
//
//*****************************************************************************************************

#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>
using namespace std;

//*****************************************************************************************************

class Stock
{
private:
    string name;
    string symbol;
    double price;

public:
    Stock(const string & n = "", const string & s = "", double p = 0);
    Stock(const Stock & s);
    friend ostream & operator << (ostream & out, const Stock & data);
    string getName() const;
    string getSymbol() const;
    double getPrice() const;
    bool operator == (const Stock & rhs) const;
    bool operator != (const Stock & rhs) const;
    bool operator < (const Stock & rhs) const;
    operator string() const;
};

//*****************************************************************************************************

#endif