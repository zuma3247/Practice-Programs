//****************************************************************************************************
//     File:               Assignment9.cpp
// 
//     Student:            Anna Sargsyan
// 
//     Assignment:         Program #9
// 
//     Course Name:        Programming II
// 
//     Course Number:      COSC 1560-01
// 
//     Due:                November 13, 2023
//
//     This program translates from American to English.
//
//****************************************************************************************************

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>

using namespace std;

struct Translation
{
    string american;
    string english;  
};

struct Date
{
    int day;
    int month;
    int year;
};

struct Person
{
    char name[20];
    double score;
    Date testTaken;
};

Translation* readTranslation(const string& , int&);
Person* readTesters(const string&, int&);
void testingOptions(const Translation[], int, Person[], int);
void takeTest(const Translation[], int, Person&);
void displayTesters(const Person[], int);
void writeTesters(const string&, const Person[], int);

//****************************************************************************************************

int main()
{
    srand(static_cast<unsigned>(time(0)));

    int numTranslations;
    Translation* translations = readTranslation("Translation.txt", 
        numTranslations);

    if (translations == nullptr)
    {
        cout << "Error reading translations. Exiting program." << endl;
        return 1; 
    }

    int numTesters;
    Person* testers = readTesters("Testers.txt", numTesters);

    if (testers == nullptr)
    {
        cout << "Error reading testers. Exiting program." << endl;
        delete[] translations;
        return 1; 
    }

    testingOptions(translations, numTranslations, testers, numTesters);

    displayTesters(testers, numTesters);

    writeTesters("UpdatedTesters.txt", testers, numTesters);

    delete[] translations;
    delete[] testers;

    return 0;
}


//****************************************************************************************************

Translation* readTranslation(const string& filename, int& num)
{
    ifstream file(filename, ios::in);
  
    file >> num;
    file.ignore();
        
    Translation* translations = new Translation[num];

    for (int i = 0; i < num; i++)
    {
        getline(file, translations[i].american, ',');
        getline(file, translations[i].english);
    }

    file.close();

    return translations;
}

//****************************************************************************************************

Person* readTesters(const string& filename, int& num)
{
    ifstream file(filename);
    Person* testers = nullptr;

    if (file.fail())
    {
        cout << "File " << filename << "doesn't exist." << endl;
    }

    else
    {
        file >> num;

        testers = new Person[num];

        for (int i = 0; i < num; i++)
        {
            file >> testers[i].name >> testers[i].score 
                >> testers[i].testTaken.day >> testers[i].testTaken.month 
                >> testers[i].testTaken.year;
        }

        file.close();
    }
    
    return testers;
}

//****************************************************************************************************

void testingOptions(const Translation t[], int numT, Person people[], int numP)
{
    Date currentDate;

    while (true)
    {
        cout << "Enter the current day: ";
        cin >> currentDate.day;

        if (currentDate.day < 1 || currentDate.day > 31)
        {
            cout << "Invalid day. Enter a valid day (1-31)." << endl;
            cin.clear();  
        }
        else
        {
            break; 
        }
    }

    while (true)
    {
        cout << "Enter the current month: ";
        cin >> currentDate.month;

        if (currentDate.month < 1 || currentDate.month > 12)
        {
            cout << "Invalid month. Enter a valid month (1-12)." << endl;
            cin.clear();  
        }
        else
        {
            break; 
        }
    }

    while (true)
    {
        cout << "Enter the current year: ";
        cin >> currentDate.year;

        if (currentDate.year < 1900) 
        {
            cout << "Invalid year. Please enter a valid year (>= 1900)." 
                << endl;
            cin.clear(); 
        }
        else
        {
            break; 
        }
    }

    for (int i = 0; i < 3; i++)
    {
        int randomIndex = rand() % numP;
        takeTest(t, numT, people[randomIndex]);
        people[randomIndex].testTaken = currentDate;
    }
}

//****************************************************************************************************

void takeTest(const Translation t[], int numT, Person& p)
{
    const int numQuestions = 5;
    double totalScore = 0;

    for (int questionCount = 0; questionCount < numQuestions;)
    {
        int randomIndex = rand() % numT;
        string question = t[randomIndex].american;
        string answer;

        if (question.empty())
        {
            continue;
        }

        cout << "Translate '" << question << "' to English: ";
        cin >> answer;

        if (answer == t[randomIndex].english)
        {
            cout << "Correct!" << endl;
            totalScore += 20.0;
            questionCount++;
        }
        else
        {
            cout << "Incorrect. The correct translation is: '" << t[randomIndex].english << "'" << endl;
        }
    }

    p.score = totalScore / numQuestions;
}

//****************************************************************************************************

void displayTesters(const Person p[], int numP)
{
    cout << "Testers Information:\n\n";
    cout << "Name\t\tScore\tTest Taken Date\n\n";

    const string monthNames[] = { "January", "February", "March", "April", "May",
        "June", "July", "August", "September", "October", "November", 
        "December" };

    for (int i = 0; i < numP; i++)
    {
        cout << p[i].name << "\t\t" << p[i].score << "\t" << p[i].testTaken.day 
            << " " << monthNames[p[i].testTaken.month - 1] << " " 
            << p[i].testTaken.year << "\n";
    }
}

//****************************************************************************************************

void writeTesters(const string& filename, const Person p[], int numP)
{
    ofstream file(filename);
    if (file.fail())
    {
        cout << "File " << filename << "doesn't exist." << endl;
    }

    else
    {
        file << numP << endl; 

        for (int i = 0; i < numP; ++i)
        {
            file << p[i].name << " " << p[i].score << " " << p[i].testTaken.day 
                << " " << p[i].testTaken.month << " " 
                << p[i].testTaken.year << endl;
        }

        file.close();
    }    
}


