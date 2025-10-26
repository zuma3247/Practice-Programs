//*****************************************************************************************************
//
//     File:               Assignment 1.cpp
//
//     Student:            Muazuddin Mohammed
//
//     Assignment:         Assignment#1
//
//     Course Name:        Computer Programming #2
//
//     Course Number:      COSC 1560
//
//     Due:                September 04, 2023
//
//
//     This program revises programming concepts from the previous semester.
//
//     Other files required:
//     1. Assignment1Data.txt – text file of Student data
//
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int NUM_TESTS = 8;
const int NUM_STUDENTS = 10;

void readTestScores (const string& fileName, int scores [][NUM_TESTS], int numStds);
void displayTestScores (const int scores [][NUM_TESTS], int numStds);
void pressEnter ();

int totalOneTest (const int scores [][NUM_TESTS], int numStds, int testNumber);
int totalOneStudent (const int scores [][NUM_TESTS], int studentNumber);
int highestOneStudent (const int scores [][NUM_TESTS], int numStds, int studentNumber);
int topStudent (const int scores [][NUM_TESTS], int numStds);

double averageOneTest (const int scores [][NUM_TESTS], int numStds, int testNumber);
double averageOneStudent (const int scores [][NUM_TESTS], int numStds, int studentNumber);


//*****************************************************************************************************

int main()
{
    int testScores[NUM_STUDENTS][NUM_TESTS],
        testNumber = 1,
        total4Test,
        studentNumber = 3,
        total4Student,
        highest4Stud,
        topStud;

    double average4Test,
           average4Stud;

    string fileName = "Assignment1Data.txt";

    readTestScores (fileName, testScores, NUM_STUDENTS);

    displayTestScores (testScores, NUM_STUDENTS);
    pressEnter ();

    total4Test = totalOneTest (testScores, NUM_STUDENTS, testNumber);
    cout << "Total for Test #" << testNumber << " is: " << total4Test << endl;
    pressEnter ();

    testNumber = 5;
    total4Test = totalOneTest (testScores, NUM_STUDENTS, testNumber);
    cout << "Total for Test #" << testNumber << " is: " << total4Test << endl;
    pressEnter ();

    total4Student = totalOneStudent (testScores, studentNumber);
    cout << "Total for Student #" << studentNumber << " is: " << total4Student << endl;
    pressEnter ();

    studentNumber = 8;
    total4Student = totalOneStudent (testScores, studentNumber);
    cout << "Total for Student #" << studentNumber << " is: " << total4Student << endl;
    pressEnter ();

    cout << fixed << setprecision(2);

    average4Test = averageOneTest (testScores, NUM_STUDENTS, testNumber);
    cout << "Average for Test #" << testNumber << " is: " << average4Test << endl;
    pressEnter ();

    testNumber = 8;
    average4Test = averageOneTest (testScores, NUM_STUDENTS, testNumber);
    cout << "Average for Test #" << testNumber << " is: " << average4Test << endl;
    pressEnter ();

    studentNumber = 5;
    average4Stud = averageOneStudent (testScores, NUM_STUDENTS, studentNumber);
    cout << "Average for Student #" << studentNumber << " is: " << average4Stud << endl;
    pressEnter ();

    studentNumber = 9;
    average4Stud = averageOneStudent (testScores, NUM_STUDENTS, studentNumber);
    cout << "Average for Student #" << studentNumber << " is: " << average4Stud << endl;
    pressEnter ();

    studentNumber = 2;
    highest4Stud = highestOneStudent (testScores, NUM_STUDENTS, studentNumber);
    cout << "Highest test score for Student #" << studentNumber << " is: " << highest4Stud << endl;
    pressEnter ();

    topStud = topStudent (testScores, NUM_STUDENTS);
    cout << "The top Student: " << topStud << endl;
    pressEnter ();

    return 0;
}

//*****************************************************************************************************

void readTestScores (const string& fileName, int scores [][NUM_TESTS], int numStds)
{
    ifstream marks;
    marks.open (fileName);

    if (marks)
    {
        for (int i = 0; i < numStds; i++)
        {
            for (int j = 0; j < NUM_TESTS; j++)
            {
                marks >> scores [i][j];
            }
        }
    }
    else
    {
        cout << "Error reading file" << endl;
    }
    marks.close ();
}

//*****************************************************************************************************

void displayTestScores (const int scores [][NUM_TESTS], int numStds)
{
    cout << "All Test scores:" << endl;

    for (int i = 0; i < numStds; i++)
    {
        for (int j = 0; j < NUM_TESTS; j++)
        {
            cout << scores [i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//*****************************************************************************************************

int totalOneTest (const int scores [][NUM_TESTS], int numStds, int testNumber)
{
    int totalForTest = 0;
    testNumber--;

    for (int i = 0; i < numStds; i++)
    {
        totalForTest += scores [i][testNumber];
    }

    return totalForTest;
}

//*****************************************************************************************************

void pressEnter ()
{
    cout << "Press Enter to Continue" << endl << endl;
    cin.get ();
}

//*****************************************************************************************************

int totalOneStudent (const int scores [][NUM_TESTS], int studentNumber)
{
    int totalForStud = 0;
    studentNumber--;

    for (int i = 0; i < NUM_TESTS; i++)
    {
        totalForStud += scores [studentNumber][i];
    }

    return totalForStud;
}

//*****************************************************************************************************

double averageOneTest (const int scores [][NUM_TESTS], int numStds, int testNumber)
{
    double average4Test;
    int total4Test = totalOneTest (scores, numStds, testNumber);

    average4Test = total4Test / static_cast <double> (numStds);
    return average4Test;
}

//*****************************************************************************************************

double averageOneStudent (const int scores [][NUM_TESTS], int numStds, int studentNumber)
{
    double average4Stud;
    int total4Stud = totalOneStudent (scores, studentNumber);

    average4Stud = total4Stud / static_cast <double> (NUM_TESTS);
    return average4Stud;
}

//*****************************************************************************************************

int highestOneStudent (const int scores [][NUM_TESTS], int numStds, int studentNumber)
{
    int highest = 0;
    studentNumber--;

    for (int i = 0; i < NUM_TESTS; i++)
    {
        if (highest < scores [studentNumber][i])
        {
            highest = scores [studentNumber][i];
        }
    }
    return highest;
}

//*****************************************************************************************************

int topStudent (const int scores [][NUM_TESTS], int numStds)
{
    double highestAvg = 0,
           avgScore;
    int topStud = 0;


    for (int studentNumber = 0; studentNumber < numStds; studentNumber++)
    {
        avgScore = averageOneStudent (scores, numStds, (studentNumber+1));

        if (highestAvg < avgScore)
        {
            highestAvg = avgScore;
            topStud = studentNumber + 1;
        }
    }

    return topStud;
}

//*****************************************************************************************************

/*

All Test scores:
87 90 65 45 88 89 75 80
89 85 78 56 90 91 99 82
80 90 72 95 99 66 77 88
90 65 80 98 99 76 77 88
55 75 66 99 99 56 87 86
30 60 80 90 99 56 67 88
90 55 95 35 98 86 37 88
99 97 99 98 98 96 87 83
90 65 80 98 99 76 87 88
35 75 60 99 99 56 87 88

Press Enter to Continue

Total for Test #1 is: 745
Press Enter to Continue

Total for Test #5 is: 968
Press Enter to Continue


Total for Student #3 is: 667
Press Enter to Continue


Total for Student #8 is: 757
Press Enter to Continue


Average for Test #5 is: 96.80
Press Enter to Continue


Average for Test #8 is: 85.90
Press Enter to Continue


Average for Student #5 is: 77.88
Press Enter to Continue


Average for Student #9 is: 85.38
Press Enter to Continue


Highest test score for Student #2 is: 99
Press Enter to Continue


The top Student: 8
Press Enter to Continue

*/



