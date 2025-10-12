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
//		This program implements a Stock class.
//
//		Other files required:
//                       1.   stock.h
//                       2.   driver.cpp
//
//*****************************************************************************************************

#include "stock.h"

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
    out << "Company Name: " << data.name << ", "
        << "Stock Symbol: " << data.symbol << ", "
        << "Price: " << data.price << endl;

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