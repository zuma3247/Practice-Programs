//*****************************************************************************************************
//
//     File:               Assignment 8.cpp
//
//     Student:            Muazuddin Mohammed
//
//     Assignment:         Assignment#8
//
//     Course Name:        Computer Programming #2
//
//     Course Number:      COSC 1560
//
//     Due:                November 8, 2023
//
//
//     This program stores information for employees of a company using file i/o and structures.
//
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int NAME_SIZE = 31;

struct Date
{
    int month,
        day,
        year;
};

struct Employee
{
    string name;
    int age;
    Date dateEmp;
};

Employee* readEmployees(const string& empFile, int& numEmps);
void displayEmployees(const Employee emps[], int numEmps);
void inputEmployees(Employee*& emps, int& numEmps);

//*****************************************************************************************************

int main()
{
    int numEmps;
    Employee * emp = nullptr;
    string file = "Employees.txt";
    fstream f;

    emp = readEmployees(file, numEmps);
    displayEmployees(emp, numEmps);
    inputEmployees(emp, numEmps);

    f.open(file, ios::out);

    if (f)
    {
        for (int i = 0; i < numEmps; i++)
        {
            f << endl << setw(10) << left << "NAME:" << emp [i].name
                << endl;

            f << setw(10) << "AGE:"
                << emp [i].age << endl;

            f << setw(10) << "EMPLOYED:" << right
                << setfill('0') << setw(2) << emp[i].dateEmp.month << "/"
                << setw(2) << emp[i].dateEmp.day << "/"
                << setw(2) << emp[i].dateEmp.year << setfill(' ');

                f << endl;
        }
    }
    else
    {
        cout << "File not open";
    }

    f.close();
    delete [] emp;
    return 0;
}

//*****************************************************************************************************

Employee* readEmployees(const string& empFile, int& numEmps)
{
    Employee * employees = new Employee [numEmps];
    fstream f;

    f.open(empFile, ios::in);

    if (f)
    {
        f >> numEmps;
        f.ignore();

        for (int i = 0; i < numEmps; i++)
        {
            f.ignore();
            getline (f, employees [i].name, ',');

            f >> employees [i].age;
            f.ignore();

            f >> employees [i].dateEmp.day;
            f.ignore();

            f >> employees [i].dateEmp.month;
            f.ignore();

            f >> employees [i].dateEmp.year;

        }

    }
    else
    {
        cout << "File not open";
    }

    f.close();
    return employees;
}

//*****************************************************************************************************

void displayEmployees(const Employee emps[], int numEmps)
{
    cout << fixed << left << setw(NAME_SIZE) << "NAME"
         << setw(15) << "AGE" << setw(15) << "DATE EMPLOYED" << endl;

    for (int i = 0; i < numEmps; i++)
    {
        cout << setw(NAME_SIZE) << emps[i].name << setw(15) << emps[i].age;

        cout << right << setfill('0') << setw(2) << emps[i].dateEmp.month << "/"
                << setw(2) << emps[i].dateEmp.day << "/"
                << setw(2) << emps[i].dateEmp.year << setfill(' ');
    }
}

//*****************************************************************************************************

void inputEmployees(Employee*& emps, int& numEmps)
{
    char ans;
    int newEmps;
    int oldNumEmps;
    string tempMonth,
           tempDay,
           tempYear;

    Employee * newEmpList = nullptr;

    cout << "\n\n Are there any additional employees to be added? (Y/N)";
    cin >> ans;

    if (ans == 'Y')
    {
        cout << "How many additional employees to be added?";
        cin >> newEmps;

        oldNumEmps = numEmps;
        numEmps += newEmps;

        newEmpList = new Employee [numEmps];

        for (int i = 0; i < oldNumEmps; i++)
        {
            newEmpList [i] = emps [i];
        }

        cin.ignore();

        for (int i = oldNumEmps; i < numEmps; i++)
        {
            cout << endl << setw(10) << left << "NAME:";
            getline (cin, newEmpList [i].name);

            cout << setw(10) << "AGE:";
            cin >> newEmpList [i].age;

            cout << setw(10) << "EMPLOYED:";
            cin.ignore();
            getline(cin, tempMonth, '/');
            getline(cin, tempDay, '/');
            getline(cin, tempYear);

            newEmpList[i].dateEmp.month = stoi(tempMonth);
            newEmpList[i].dateEmp.day = stoi(tempDay);
            newEmpList[i].dateEmp.year = stoi(tempYear);

            cout << endl;
        }

        for (int i = 0; i < numEmps; i++)
        {
            cout << endl << setw(10) << left << "NAME:" << newEmpList [i].name
                 << endl;

            cout << setw(10) << "AGE:"
                 << newEmpList [i].age << endl;

            cout << setw(10) << "EMPLOYED:" << right
                 << setfill('0') << setw(2) << newEmpList[i].dateEmp.month << "/"
                 << setw(2) << newEmpList[i].dateEmp.day << "/"
                 << setw(2) << newEmpList[i].dateEmp.year << setfill(' ');

            emps [i] = newEmpList [i];
            cout << endl;
        }
    }

    delete [] newEmpList;
}

/*

 NAME                           AGE            DATE EMPLOYED
Stephen Smith                  25            12/15/2001
Susan Kim-Jones            3301/09/2012
Kun Joom Jadav            5208/22/1999

 Are there any additional employees to be added? (Y/N)Y
How many additional employees to be added?2

NAME:     Denise Lynch
AGE:      22
EMPLOYED: 12/22/2012


NAME:     James Fred
AGE:      35
EMPLOYED: 3/19/2018


NAME:     Stephen Smith
AGE:      25
EMPLOYED: 12/15/2001

NAME:
Susan Kim-Jones
AGE:      33
EMPLOYED: 01/09/2012

NAME:
Kun Joom Jadav
AGE:      52
EMPLOYED: 08/22/1999

NAME:     Denise Lynch
AGE:      22
EMPLOYED: 12/22/2012

NAME:     James Fred
AGE:      35
EMPLOYED: 03/19/2018

 */

