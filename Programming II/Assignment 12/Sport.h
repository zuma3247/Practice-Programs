//Sport.h

#ifndef SPORT_H
#define SPORT_H

#include <string>

struct Date
{
    int day;
    int month;
    int year;
};

class Sport
{
private:
    std::string sportName;
    Date nextGameDate;
    int numTeams;
    char * teamName = new char [numTeams];

public:
    std::string getSportName() const;
    void setSportName (const std::string& name);
    Date getNextGameDate() const;
    void setNextGameDate(const Date& date);
    int getNumTeams() const;
    void setNumTeams(int teams);
    void displaySportInfo() const;
    void populateSport();
    Sport(const std::string& n = "");
    ~Sport();
};

//*****************************************************************************************************

inline
std::string Sport::getSportName() const
{
    return sportName;
}

//*****************************************************************************************************

inline
void Sport::setSportName (const std::string& name)
{
    sportName = name;
}

//*****************************************************************************************************

inline
Date Sport::getNextGameDate() const
{
    return nextGameDate;
}

//*****************************************************************************************************

inline
void Sport::setNextGameDate(const Date& date)
{
    nextGameDate = date;
}

//*****************************************************************************************************

inline
int Sport::getNumTeams() const
{
    return numTeams;
}

//*****************************************************************************************************

inline
void Sport::setNumTeams(int teams)
{
    numTeams = teams;
}

//*****************************************************************************************************

#endif //ASSIGNMENT_12_SPORT_H
