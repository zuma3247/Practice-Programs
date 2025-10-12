//*****************************************************************************************************
//
//		File:			    stock.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #5
//
//		Course Name:		Data Structures II
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    February 19, 2025
//
//
//		This program implements a Stock class.
//
//		Other files required:
//                       1.   stock.h
//                       2.   driver.cpp
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
    int hash(int size) const;

    bool operator == (const Stock & rhs) const;
    bool operator != (const Stock & rhs) const;
    bool operator < (const Stock & rhs) const;
    operator string() const;
};

//*****************************************************************************************************

Stock :: Stock(const string & n, const string & s, double p)
{
    name = n;
    symbol = s;
    price = p;
}

//*****************************************************************************************************

Stock :: Stock(const Stock & s)
{
    this -> name = s.name;
    this -> symbol = s.symbol;
    this -> price = s.price;
}

//*****************************************************************************************************

ostream & operator << (ostream & out, const Stock & data)
{
    out << "[Company Name: " << data.name << ", "
        << "Stock Symbol: " << data.symbol << ", "
        << "Price: " << data.price << "]";

    return out;
}

//*****************************************************************************************************

string Stock :: getName() const
{
    return name;
}

//*****************************************************************************************************

string Stock :: getSymbol() const
{
    return symbol;
}

//*****************************************************************************************************

double Stock :: getPrice() const
{
    return price;
}

//*****************************************************************************************************

int Stock :: hash(int size) const
{
    int hashValue = 0;

    for (int i = 0; i < symbol.length(); i++) {
        hashValue = (hashValue * size) + symbol[i];
    }

    return hashValue % size;
}

//*****************************************************************************************************

bool Stock :: operator == (const Stock & rhs) const
{
    bool equals = false;

    if ( (this -> symbol) == (rhs.symbol) )
        equals = true;

    return equals;
}

//*****************************************************************************************************

bool Stock :: operator != (const Stock & rhs) const
{
    bool notEquals = false;

    if ( (this -> symbol) != (rhs.symbol) )
        notEquals = true;

    return notEquals;
}

//*****************************************************************************************************

bool Stock :: operator < (const Stock & rhs) const
{
    bool isBigger = false;

    if ( (this -> price) > (rhs.price) )
        isBigger = true;

    return isBigger;
}

//*****************************************************************************************************

Stock :: operator string() const
{
    return symbol;
}

//*****************************************************************************************************

#endif STOCK_H