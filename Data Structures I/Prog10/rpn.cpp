//*****************************************************************************************************
//
//		File:			    rpn.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #10
//
//		Course Name:		Data Structures I
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    November 26, 2024
//
//
//		This program uses stacks to evaluate RPN expressions.
//
//		Other files required:
//                       1.   stack.h
//                       2.   results.txt
//                       3.   expressions.txt
//
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "stack.h"

//*****************************************************************************************************

void outputToken (char token[], ofstream & resultsFile);
void processNumber (char token[], Stack <int> & s1, ofstream & resultsFile);
bool processOperator (char oper, Stack <int> & s1, ofstream & resultsFile);
void displayResult (Stack <int> & s1, ofstream & resultsFile);
void resetFlagStack (Stack <int> & s1);

//*****************************************************************************************************

int main()
{
    bool isValid = true;
    char * tokn;
    Stack <int> stk;
    ifstream inFile;
    ofstream outFile;

    inFile.open ( "expressions.txt" );
    outFile.open ( "results.txt" );

    tokn = new char [5];

    if (!inFile)
        cout << "Error opening file" << endl;
    else
    {
        while ( inFile >> tokn )
        {
            outputToken ( tokn, outFile );

            if ( tokn[0] == ';' )
            {
                displayResult (stk, outFile);
                resetFlagStack (stk);
                isValid = true;
                cout << endl;
            }
            else if ( (isValid) && ( isdigit (tokn[0]) )  )
            {
                processNumber (tokn, stk, outFile);
            }
            else if ( (isValid) && ( ispunct (tokn[0]) ) )
            {
                isValid = processOperator (tokn[0], stk, outFile);
            }
        }
    }

    inFile.close();
    outFile.close();
    delete[] tokn;

    return 0;
}

//*****************************************************************************************************

void outputToken(char token[], ofstream & resultsFile)
{
    resultsFile << endl << "( Token: " << token << " ) \t\t";

    if (token[0] != ';')
        cout << token << " ";
}

//*****************************************************************************************************

void processNumber (char token[], Stack <int> & s1, ofstream & resultsFile)
{
    int num;

    num = atoi (token);
    s1.push (num);
    resultsFile << "\tPush " << num;
}

//*****************************************************************************************************

bool processOperator (char oper, Stack <int> & s1, ofstream & resultsFile)
{
    bool success = true;
    int num1,
        num2,
        result;

    if (oper != ';')
    {
        if ( (s1.pop(num2)) && (s1.pop(num1)) )
        {
            switch (oper)
            {
                case '+':
                    result = num1 + num2;
                    break;

                case '-':
                    result = num1 - num2;
                    break;

                case '*':
                    result = num1 * num2;
                    break;

                case '/':
                    result = num1 / num2;
                    break;

                case '%':
                    result = num1 % num2;
                    break;
            }

            s1.push (result);
            resultsFile << "\tPop  " << num2 << "\t\tPop  " << num1
                        << "\t\tPush " << result;
        }
        else
        {
            success = false;
        }
    }

    return success;
}

//*****************************************************************************************************

void displayResult (Stack <int> & s1, ofstream & resultsFile)
{
    int result;

    if (s1.pop(result))
    {
        if (s1.isEmpty())
        {
            resultsFile << "\tPop  " << result << endl;
            resultsFile << "\t\t\t\tValid: result = " << result << endl;
            cout << "= " << result;
        }
        else
        {
            resultsFile << "\nInvalid RPN expression - too many operands"
                        << endl;
            cout << "\t\t\t\t\t" << "invalid";
        }
    }
    else
    {
        resultsFile << "\nInvalid RPN expression - not enough operands" << endl;
        cout << "\t\t\t\t\t" << "invalid";
    }
}

//*****************************************************************************************************

void resetFlagStack (Stack <int> & s1)
{
    int temp;
    while (!s1.isEmpty())
    {
        s1.pop(temp);
    }
}

//*****************************************************************************************************

/*

2 4 * 5 + = 13
13 5 % 5 + = 8
15 1 + 2 / 1 - = 7
15 + 1 + 2 / 1 - 					invalid
3 4 + 15 10 - * = 35
3 4 + 6 15 10 - * 					invalid
2 13 + 14 6 - - 5 * 4 + = 39
35 6 4 2 2 / + * - = 5
3 4 + 1 2 - * 4 2 / 3 - + = -8
3 14 1 2 4 2 3 + % * + - + = 8

 */