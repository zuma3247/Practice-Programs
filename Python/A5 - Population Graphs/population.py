#****************************************************************************************************
#
#   Name:       Muazuddin Mohammed
#   Course:     COSC 2110 Computer Languages: Python
#   Assignment: population.py
#   Due Date:   02/19/2025
#   Description:
#       This program reads the file's contents into a list and displays data.
#
#****************************************************************************************************

import matplotlib.pyplot as plt

#****************************************************************************************************

def print_list(nums):

    for i in range(len(nums)):
        print( nums[i], end=', ')
        if (i + 1) % 10 == 0:
            print()

    print()

#****************************************************************************************************

def calc_difference(population_list):
    change_list = []

    for i in range(1, len(population_list)):
        change_list.append(population_list[i] - population_list[i - 1])

    return change_list

#****************************************************************************************************

def get_average(population_list):
    sum = 0

    for i in range(len(population_list)):
        sum += population_list[i]

    avg = sum / len(population_list)

    return avg

#****************************************************************************************************

def get_greatest_increase(change_list):
    return max(change_list)

#****************************************************************************************************

def get_smallest_increase(change_list):
    return min(change_list)

#****************************************************************************************************

def plot_bar(population_list):
    left_edge = [year for year in range(1950, 1991)]
    plt.bar(left_edge, population_list)
    plt.title('Population Chart')
    plt.show()

#****************************************************************************************************

def sort_ascending(change_list):
    change_list.sort()
    print_list(change_list)

#****************************************************************************************************

def sort_descending(change_list):
    change_list.sort(reverse=True)
    print_list(change_list)

#****************************************************************************************************

def search_population(population_list):
    pop = int(input('Enter a population: '))

    if pop in population_list:
        print('Population Found!')
    else:
        print('Population Not found!')

#****************************************************************************************************

def main():

    try:
        in_file = open('USPopulation.txt', 'r')
        population = in_file.readlines()
        population = [int(num.rstrip()) for num in population]

        print('The Population list is:')
        print_list(population)
        print()

        print('The Population changes are:')
        pop_change = calc_difference(population)
        print_list(pop_change)

        print(f'The average is: {get_average(population):.2f}')
        print('the greatest population change is: ', get_greatest_increase(pop_change))
        print('the smallest population change is: ', get_smallest_increase(pop_change))
        print()

        plot_bar(population)
        print('The Population change list sorted in ascending order:')
        sort_ascending(pop_change)

        print('The Population change list sorted in descending order:')
        sort_descending(pop_change)

        search_population(population)

    except FileNotFoundError:
        print('The file could not be found.')
    except:
        print('There was an error.')
    else:
        in_file.close()

#****************************************************************************************************

if __name__ == "__main__":
    main()

#****************************************************************************************************

"""

The Population list is:
151868, 153982, 156393, 158956, 161884, 165069, 168088, 171187, 174149, 177135, 
179979, 182992, 185771, 188483, 191141, 193526, 195576, 197457, 199399, 201385, 
203984, 206827, 209284, 211357, 213342, 215465, 217563, 219760, 222095, 224567, 
227225, 229466, 231664, 233792, 235825, 237924, 240133, 242289, 244499, 246819, 
249623, 

The Population changes are:
2114, 2411, 2563, 2928, 3185, 3019, 3099, 2962, 2986, 2844, 
3013, 2779, 2712, 2658, 2385, 2050, 1881, 1942, 1986, 2599, 
2843, 2457, 2073, 1985, 2123, 2098, 2197, 2335, 2472, 2658, 
2241, 2198, 2128, 2033, 2099, 2209, 2156, 2210, 2320, 2804, 

The average is: 202876.17
the greatest population change is:  3185
the smallest population change is:  1881

The Population change list sorted in ascending order:
1881, 1942, 1985, 1986, 2033, 2050, 2073, 2098, 2099, 2114, 
2123, 2128, 2156, 2197, 2198, 2209, 2210, 2241, 2320, 2335, 
2385, 2411, 2457, 2472, 2563, 2599, 2658, 2658, 2712, 2779, 
2804, 2843, 2844, 2928, 2962, 2986, 3013, 3019, 3099, 3185, 

The Population change list sorted in descending order:
3185, 3099, 3019, 3013, 2986, 2962, 2928, 2844, 2843, 2804, 
2779, 2712, 2658, 2658, 2599, 2563, 2472, 2457, 2411, 2385, 
2335, 2320, 2241, 2210, 2209, 2198, 2197, 2156, 2128, 2123, 
2114, 2099, 2098, 2073, 2050, 2033, 1986, 1985, 1942, 1881, 

Enter a population: 235825
Population Found!

"""