#****************************************************************************************************
#
#   Name:       Muazuddin Mohammed
#   Course:     COSC 2110 Computer Languages: Python
#   Assignment: champions2.py
#   Due Date:   02/26/2025
#   Description:
#       This program reads the file's contents into a dictionary and displays data.
#
#****************************************************************************************************

def get_dict(team_list):
    team_dict = {}
    year = 1903

    for team in team_list:
        if team != 'none':
            if team not in team_dict:
                team_dict[team] = []

            team_dict[team].append(year)
        year += 1

    return team_dict

#****************************************************************************************************

def display(dict):

    for team, years in dict.items():
        print(f'{team}:')
        i = 0

        for year in years:
            print(year, end=' ')
            i += 1
            if i % 8 == 0:
                print()

        print('\n')

#****************************************************************************************************

def display_team(team_dict):
    team = input("Enter a team's name: ")

    if team in team_dict:
        print(team_dict[team])
    else:
        print(f'{team} not found.')

#****************************************************************************************************

def delete_team(team_dict):
    team = input("Enter a team's name: ")

    if team in team_dict:
        del team_dict[team]
        print(f'{team} deleted.')
    else:
        print(f'{team} not found.')

#****************************************************************************************************

def change_team(team_dict):
    team = input("Enter a team's name: ")
    if team in team_dict:
        years = input("Enter this team's new winning year(s): ")
        new_years = years.split(' ')

        for year in new_years:
            team_dict[team].append(int(year))

        print(f'{team} changed')
    else:
        print(f'{team} not found.')

#****************************************************************************************************

def main():
    try:
        team_list = []
        in_file = open("WorldSeriesWinners.txt", "r")
        team_list = [team.rstrip('\n') for team in in_file]
    except FileNotFoundError:
        print('File not found.')
    else:
        in_file.close()

    again = False
    team_dict = get_dict(team_list)

    while not again:
        print('-' * 50)
        print('Menu:')
        print("1. View a team's info")
        print("2. View all team's info")
        print("3. Delete a team's info")
        print("4. Change a team's info")
        print("5. Quit")
        choice = input('Please choose an option: ')

        if choice == '1':
            display_team(team_dict)

        elif choice == '2':
            display(team_dict)

        elif choice == '3':
            delete_team(team_dict)

        elif choice == '4':
            change_team(team_dict)

        elif choice == '5':
            print('Goodbye.')
            again = True

        else:
            print('Enter a valid choice.')

#****************************************************************************************************

if __name__ == '__main__':
    main()

#****************************************************************************************************

"""
--------------------------------------------------
Menu:
1. View a team's info
2. View all team's info
3. Delete a team's info
4. Change a team's info
5. Quit
Please choose an option: 1
Enter a team's name: New York Mets
[1969, 1986]
--------------------------------------------------
Menu:
1. View a team's info
2. View all team's info
3. Delete a team's info
4. Change a team's info
5. Quit
Please choose an option: 2
Boston Americans:
1903 

New York Giants:
1905 1921 1922 1933 1954 

Chicago White Sox:
1906 1917 2005 

Chicago Cubs:
1907 1908 

Pittsburgh Pirates:
1909 1925 1960 1971 1979 

Philadelphia Athletics:
1910 1911 1913 1929 1930 

Boston Red Sox:
1912 1915 1916 1918 2004 2007 

Boston Braves:
1914 

Cincinnati Reds:
1919 1940 1975 1976 1990 

Cleveland Indians:
1920 1948 

New York Yankees:
1923 1927 1928 1932 1936 1937 1938 1939 
1941 1943 1947 1949 1950 1951 1952 1953 
1956 1958 1961 1962 1977 1978 1996 1998 
1999 2000 

Washington Senators:
1924 

St. Louis Cardinals:
1926 1931 1934 1942 1944 1946 1964 1967 
1982 2006 

Detroit Tigers:
1935 1945 1968 1984 

Brooklyn Dodgers:
1955 

Milwaukee Braves:
1957 

Los Angeles Dodgers:
1959 1963 1965 1981 1988 

Baltimore Orioles:
1966 1970 1983 

New York Mets:
1969 1986 

Oakland Athletics:
1972 1973 1974 1989 

Philadelphia Phillies:
1980 2008 

Kansas City Royals:
1985 

Minnesota Twins:
1987 1991 

Toronto Blue Jays:
1992 1993 

Atlanta Braves:
1995 

Florida Marlins:
1997 2003 

Arizona Diamondbacks:
2001 

Anaheim Angels:
2002 

--------------------------------------------------
Menu:
1. View a team's info
2. View all team's info
3. Delete a team's info
4. Change a team's info
5. Quit
Please choose an option: 3
Enter a team's name: Anaheim Angels
Anaheim Angels deleted.
--------------------------------------------------
Menu:
1. View a team's info
2. View all team's info
3. Delete a team's info
4. Change a team's info
5. Quit
Please choose an option: 1
Enter a team's name: Anaheim Angels
Anaheim Angels not found.
--------------------------------------------------
Menu:
1. View a team's info
2. View all team's info
3. Delete a team's info
4. Change a team's info
5. Quit
Please choose an option: 4
Enter a team's name: New York Mets
Enter this team's new winning year(s): 2025 2030
New York Mets changed
--------------------------------------------------
Menu:
1. View a team's info
2. View all team's info
3. Delete a team's info
4. Change a team's info
5. Quit
Please choose an option: 1
Enter a team's name: New York Mets
[1969, 1986, 2025, 2030]
--------------------------------------------------
Menu:
1. View a team's info
2. View all team's info
3. Delete a team's info
4. Change a team's info
5. Quit
Please choose an option: 5
Goodbye.

"""