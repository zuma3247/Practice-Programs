#****************************************************************************************************
#
#   Name:         Muazuddin Mohammed
#   Course:       COSC 2110 Computer Languages: Python
#   Assignment:   Math.py
#   Due Date:     02/05/2025
#   Description:
#       This program does a simple math quiz of testing the user about adding
#       two numbers.
#
#****************************************************************************************************

import random as rnd

#****************************************************************************************************

def get_random():
    return rnd.randint(0, 999)

#****************************************************************************************************

def display_problem(num1, num2):
    print("=" * 50)
    print(f'{num1:>5}')
    print(f'+{num2:>4}')

#****************************************************************************************************

def get_answer(num1, num2):
    check = True

    while check:
        try:
            user_sum = int(input("Enter sum of numbers: "))
            check = False
        except ValueError:
            print("That's not numeric. Enter Integer only.")
            check = True
        else:
            return user_sum

#****************************************************************************************************

def show_result(num1, num2, user_sum):
    sum_nums = num1 + num2

    if user_sum == sum_nums:
        print("Correct! - Good Work!")
    else:
        print("Incorrect!... The correct answer was: ", sum_nums)

#****************************************************************************************************

def main():
    repeat_sum = 'Y'

    while repeat_sum == 'Y' or repeat_sum == 'y':
        num1 = get_random()
        num2 = get_random()

        display_problem(num1, num2)
        user_sum = get_answer(num1, num2)
        show_result(num1, num2, user_sum)
        repeat_sum = input("Again? Press Y/y to continue: ")

if __name__ == '__main__':
    main()

#****************************************************************************************************

"""
==================================================
   63
+ 881
Enter sum of numbers: 944
Correct! - Good Work!
Again? Press Y/y to continue: y
==================================================
  167
+ 497
Enter sum of numbers: 890
Incorrect!... The correct answer was:  664
Again? Press Y/y to continue: y
==================================================
  134
+ 519
Enter sum of numbers: abc
That's not numeric. Enter Integer only.
Enter sum of numbers: hu
That's not numeric. Enter Integer only.
Enter sum of numbers: bu
That's not numeric. Enter Integer only.
Enter sum of numbers: 653
Correct! - Good Work!
Again? Press Y/y to continue: n
"""