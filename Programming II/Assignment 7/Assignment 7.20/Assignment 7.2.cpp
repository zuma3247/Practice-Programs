//*****************************************************************************************************
//
//     File:               Assignment 7.2.cpp
//
//     Student:            Muazuddin Mohammed
//
//     Assignment:         Assignment#7
//
//     Course Name:        Computer Programming #2
//
//     Course Number:      COSC 1560
//
//     Due:                October 30, 2023
//
//
//     This program implements creation and manipulation of structures.
//
//*****************************************************************************************************

#include <iostream>
using namespace std;

struct Speaker
{
    string name,
            topic,
            phoneNum;
    double fee;
};

void inputSpeakers (Speaker members [], int numSpeakers);
void updateSpeaker (Speaker members [], int numSpeakers, const string& speakerName);
void displaySpeaker (Speaker members [], int numSpeakers, const string& speakerName);
void displayTopic (Speaker members [], int numSpeakers, const string& speakerTopic);
void displayArray (Speaker members [], int numSpeakers);

//*****************************************************************************************************

int main ()
{
    int numLecturers;
    Speaker *lecturers = nullptr;
    string lecturerName,
            lecturerTopic;

    cout << "How many Speakers are there?" << endl;
    cin >> numLecturers;
    cout << endl;

    lecturers = new Speaker [numLecturers];

    inputSpeakers (lecturers, numLecturers);

    cout << "Enter a Speaker's Name to be updated: ";
    cin.ignore();
    getline (cin, lecturerName);
    updateSpeaker (lecturers, numLecturers, lecturerName);

    cout << "Enter a Speaker's Name to be displayed: ";
    cin.ignore();
    getline (cin, lecturerName);
    displaySpeaker (lecturers, numLecturers, lecturerName);

    cout << "Enter a topic to find out which speakers are talking about it: " << endl;
    cin >> lecturerTopic;
    displayTopic (lecturers, numLecturers, lecturerTopic);

    cout << "Here is the entire list of Speakers: " << endl;
    displayArray (lecturers, numLecturers);

}

//*****************************************************************************************************

void inputSpeakers (Speaker members[], int numSpeakers)
{
    for (int i = 0; i < numSpeakers; i++)
    {
        cout << "Enter Speaker " << i + 1 << " details: " << endl
             << "Name: ";
        cin.ignore();
        getline (cin, members[i].name);

        cout << "Telephone Number: ";
        cin >> members[i].phoneNum;

        cout << "Topic: ";
        cin >> members[i].topic;

        do
        {
            cout << "(Non-Negative) Fee Required: ";
            cin >> members[i].fee;
        }
        while (members[i].fee < 0);

        cout << endl;
    }
}

//*****************************************************************************************************

void updateSpeaker (Speaker members [], int numSpeakers, const string& speakerName)
{
    int arrayNum = 0;
    bool found = false,
            response;

    while (!found)
    {
        if (members [arrayNum].name == speakerName)
        {
            found = true;
        }
        else
        {
            arrayNum++;

            if (arrayNum >= numSpeakers)
            {
                cout << "Name not found";
                found = true;
            }
        }
    }

    cout << "Do you need to update Telephone Number of " << speakerName << "?" << endl;
    cin >> response;

    if (response)
    {
        cout << "Update Telephone Number of " << speakerName << endl;
        cin >> members [arrayNum].phoneNum;
    }

    cout << "Do you need to update Topic of " << speakerName << "?" << endl;
    cin >> response;

    if (response)
    {
        cout << "Update Topic of " << speakerName << endl;
        cin >> members [arrayNum].topic;
    }

    cout << "Do you need to update Fee Required of " << speakerName << "?" << endl;
    cin >> response;

    if (response)
    {
        cout << "Update Fee Required of " << speakerName << endl;
        cin >> members [arrayNum].fee;
    }

    cout << endl;
}

//*****************************************************************************************************

void displaySpeaker (Speaker members [], int numSpeakers, const string& speakerName)
{
    int arrayNum = 0;
    bool found = false;

    while (!found)
    {
        if (members [arrayNum].name == speakerName)
        {
            found = true;
        }
        else
        {
            arrayNum++;

            if (arrayNum >= numSpeakers)
            {
                cout << "Name not found";
                found = true;
            }
        }
    }

    cout << "Speaker's Name: " << members [arrayNum].name << endl
         << "Speaker's Telephone Number: " << members [arrayNum].phoneNum << endl
         << "Speaker's Topic: " << members [arrayNum].topic << endl
         << "Speaker's Fee Required: " << members [arrayNum].fee << endl << endl;
}

//*****************************************************************************************************

void displayTopic (Speaker members [], int numSpeakers, const string& speakerTopic)
{
    int count = 0;

    cout << speakerTopic << " is being spoken by:" << endl;

    for (int i = 0; i < numSpeakers; i++)
    {
        if (members [i].topic == speakerTopic)
        {
            cout << members [i].name << endl;
            count++;
        }
    }

    if (!count)
    {
        cout << "No speakers for this topic found." << endl;
    }

    cout << "\n";
}

//*****************************************************************************************************

void displayArray (Speaker members [], int numSpeakers)
{
    for (int i = 0; i < numSpeakers; i++)
    {
        cout << "Speaker's Name: " << members [i].name << endl
             << "Speaker's Telephone Number: " << members [i].phoneNum << endl
             << "Speaker's Topic: " << members [i].topic << endl
             << "Speaker's Fee Required: " << members [i].fee << endl << endl;
    }
}

//*****************************************************************************************************

/*

How many Speakers are there?
3

Enter Speaker 1 details:
Name: A
Telephone Number: 1
Topic: aa
(Non-Negative) Fee Required: 10

Enter Speaker 2 details:
Name: B
Telephone Number: 2
Topic: bb
(Non-Negative) Fee Required: 20

Enter Speaker 3 details:
Name: C
Telephone Number: 3
Topic: cc
(Non-Negative) Fee Required: 30

Enter a Speaker's Name to be updated: C
Do you need to update Telephone Number of C?

0
Do you need to update Topic of C?
0
Do you need to update Fee Required of C?
1
Update Fee Required of C
50

Enter a Speaker's Name to be displayed: B
Speaker's Name: B
Speaker's Telephone Number: 2
Speaker's Topic: bb
Speaker's Fee Required: 20

Enter a topic to find out which speakers are talking about it:
aa
aa is being spoken by:
A

Here is the entire list of Speakers:
Speaker's Name: A
Speaker's Telephone Number: 1
Speaker's Topic: aa
Speaker's Fee Required: 10

Speaker's Name: B
Speaker's Telephone Number: 2
Speaker's Topic: bb
Speaker's Fee Required: 20

Speaker's Name: C
Speaker's Telephone Number: 3
Speaker's Topic: cc
Speaker's Fee Required: 50

 */