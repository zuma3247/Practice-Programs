//*****************************************************************************************************
//
//		File:			    Student.h
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #11
//
//		Course Name:		Data Structures I
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    December 3, 2024
//
//
//		This file declares the structure for a student.
//
//*****************************************************************************************************

#ifndef STUDENT_H
#define STUDENT_H

struct Student
{
    int id;
    char name[50];
    char citystate[50];
    char phone[12];
    char gender;
    int year;
    int credits;
    float gpa;
    char major[6];

    Student();
    friend ostream & operator << (ostream & out, const Student & data);

    bool operator == (const Student & rhs) const;
    bool operator == (int value) const;
    bool operator != (const Student & rhs) const;
    bool operator != (int value) const;
    bool operator < (const Student & rhs) const;
    bool operator < (int value) const;
    bool operator > (const Student & rhs) const;
    bool operator > (int value) const;
    bool operator <= (const Student & rhs) const;
    bool operator <= (int value) const;
    bool operator >= (const Student & rhs) const;
    bool operator >= (int value) const;
};

//*****************************************************************************************************

Student :: Student()
{
    id = 0;
}

//*****************************************************************************************************

ostream & operator << (ostream & out, const Student & data)
{
    out << left << setw(10) << data.id << setw(25) << data.name << setw(10) << data.major << data.gpa
        << endl;

    return out;
}

//*****************************************************************************************************

bool Student :: operator == (const Student & rhs) const
{
    return (this -> id == rhs.id);
}

//*****************************************************************************************************

bool Student :: operator == (int value) const
{
    return (this -> id == value);
}

//*****************************************************************************************************

bool Student :: operator != (const Student & rhs) const
{
    return (this -> id != rhs.id);
}

//*****************************************************************************************************

bool Student :: operator != (int value) const
{
    return (this -> id != value);
}

//*****************************************************************************************************

bool Student :: operator < (const Student & rhs) const
{
    return (this -> id < rhs.id);
}

//*****************************************************************************************************

bool Student :: operator < (int value) const
{
    return (this -> id < value);
}

//*****************************************************************************************************

bool Student :: operator > (const Student & rhs) const
{
    return (this -> id > rhs.id);
}

//*****************************************************************************************************

bool Student :: operator > (int value) const
{
    return (this -> id > value);
}

//*****************************************************************************************************

bool Student :: operator <= (const Student & rhs) const
{
    return (this -> id <= rhs.id);
}

//*****************************************************************************************************

bool Student :: operator <= (int value) const
{
    return (this -> id <= value);
}

//*****************************************************************************************************

bool Student :: operator >= (const Student & rhs) const
{
    return (this -> id >= rhs.id);
}

//*****************************************************************************************************

bool Student :: operator >= (int value) const
{
    return (this -> id >= value);
}

//*****************************************************************************************************

#endif
