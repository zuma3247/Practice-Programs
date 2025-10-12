#****************************************************************************************************
#
#   Name:         Muazuddin Mohammed
#   Course:       COSC 2110 Computer Languages: Python
#   Assignment:   population.py
#   Due Date:     01/22/2025
#   Description:
#       This program predicts the approximate size of a population of organisms.
#
#****************************************************************************************************

MIN_NUM_OF_ORGS = 1
MIN_AVG_DAILY_INC = 0
MIN_NUM_DAYS = 1
MAX_NUM_DAYS = 100

numOrgs = int(input('Starting number of organisms: '))

while numOrgs < MIN_NUM_OF_ORGS:
    print('Please enter a number > 1: ')
    numOrgs = int(input('Starting number of organisms: '))

avgDailyInc = float(input('Average daily increase: '))

while avgDailyInc < MIN_AVG_DAILY_INC:
    print('Please enter a number > 0: ')
    avgDailyInc = float(input('Average daily increase: '))

if avgDailyInc > 1:
    avgDailyInc /= 100

numDays = int(input('Number of days to multiply: '))

while (numDays < MIN_NUM_DAYS) or (numDays > MAX_NUM_DAYS):
    print('Please enter a number between 1 and 100: ')
    numDays = int(input('Number of days to multiply: '))

print('Day Approximate\t\t\tPopulation')
print("-" * 40)

population = numOrgs

for num in range(1, (numDays + 1)):
    print(f'{num:<23} {population}')
    population = population + (population * avgDailyInc)

#****************************************************************************************************

'''
Starting number of organisms: 100
Average daily increase: 50
Number of days to multiply: 10
Day Approximate			Population
----------------------------------------
1                       100
2                       150.0
3                       225.0
4                       337.5
5                       506.25
6                       759.375
7                       1139.0625
8                       1708.59375
9                       2562.890625
10                      3844.3359375
'''
