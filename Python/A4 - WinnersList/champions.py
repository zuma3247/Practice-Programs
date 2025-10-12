#****************************************************************************************************
#
# Name: Your name
# Course: COSC 2110 Computer Languages: Python
# Assignment: champions.py
# Due Date: 02/15/2025
# Description:
# This program uses a menu to search, display and add team names.
#
#****************************************************************************************************

def search_team(team_list):
    victories = 0
    team_name = input("Enter team name: ")

    for team in team_list:
        if team == team_name:
            victories += 1

    if victories != 0:
        print(f"\nTeam {team_name} has {victories} victories")
    else:
        print(f"\nTeam {team_name} has no victory")

#****************************************************************************************************

def display_teams(team_list):
    set_teams = set(team_list)
    sorted_teams = sorted(set_teams)

    print("Team names:")

    for team in sorted_teams:
        print(team)

#****************************************************************************************************

def add_team(team_list):
    team_name = input("Enter team name: ")
    team_list.append(team_name)

    try:
        team_list_file = open("WorldseriesWinners.txt", "a")
    except FileNotFoundError:
        print("File not found")
    else:
        team_list_file.write(f"{team_name}\n")
        team_list_file.close()

    print("Team list updated.")

#****************************************************************************************************

def main():
    try:
        team_list_file = open("WorldseriesWinners.txt", "r")
    except FileNotFoundError:
        print("File not found")
    else:
        team_list = [line.rstrip('\n') for line in team_list_file if line.strip()]
        team_list_file.close()

    again = 1

    while again == 1:
        print("""\nMenu:
1. Search a team
2. Display team names
3. Add more teams
4. Quit""")

        choice = input("Enter your choice: ")

        if choice == '1':
            search_team(team_list)
        elif choice == '2':
            display_teams(team_list)
        elif choice == '3':
            add_team(team_list)
        elif choice == '4':
            again = 0
            print("Thank you for playing!")
        else:
            print("Invalid choice")


if __name__ == "__main__":
    main()

#****************************************************************************************************

"""

Menu:
1. Search a team
2. Display team names
3. Add more teams
4. Quit
Enter your choice: 2
Team names:
Anaheim Angels
Arizona Diamondbacks
Atlanta Braves
Baltimore Orioles
Boston Americans
Boston Braves
Boston Red Sox
Brooklyn Dodgers
Chicago Cubs
Chicago White Sox
Cincinnati Reds
Cleveland Indians
Detroit Tigers
Florida Marlins
Kansas City Royals
Los Angeles Dodgers
Milwaukee Braves
Minnesota Twins
New York Giants
New York Mets
New York Yankees
Oakland Athletics
Philadelphia Athletics
Philadelphia Phillies
Pittsburgh Pirates
St. Louis Cardinals
Toronto Blue Jays
Washington Senators
none

Menu:
1. Search a team
2. Display team names
3. Add more teams
4. Quit
Enter your choice: 1
Enter team name: Chicago Cubs

Team Chicago Cubs has 2 victories

Menu:
1. Search a team
2. Display team names
3. Add more teams
4. Quit
Enter your choice: 3
Enter team name: STL BLUES
Team list updated.

Menu:
1. Search a team
2. Display team names
3. Add more teams
4. Quit
Enter your choice: 2
Team names:
Anaheim Angels
Arizona Diamondbacks
Atlanta Braves
Baltimore Orioles
Boston Americans
Boston Braves
Boston Red Sox
Brooklyn Dodgers
Chicago Cubs
Chicago White Sox
Cincinnati Reds
Cleveland Indians
Detroit Tigers
Florida Marlins
Kansas City Royals
Los Angeles Dodgers
Milwaukee Braves
Minnesota Twins
New York Giants
New York Mets
New York Yankees
Oakland Athletics
Philadelphia Athletics
Philadelphia Phillies
Pittsburgh Pirates
STL BLUES
St. Louis Cardinals
Toronto Blue Jays
Washington Senators
none

Menu:
1. Search a team
2. Display team names
3. Add more teams
4. Quit
Enter your choice: 5
Invalid choice

Menu:
1. Search a team
2. Display team names
3. Add more teams
4. Quit
Enter your choice: 4
Thank you for playing!

"""