#****************************************************************************************************
#
#   Name:       Muazuddin Mohammed
#   Course:     COSC 2110 Computer Languages: Python
#   Assignment: math_function.py
#   Due Date:   03/28/2025
#   Description:
#       This program implements recursion for a math function.
#
#****************************************************************************************************

def math_func(m, n):
    try:
        if m == 0:
            result = n + 1
        elif n == 0:
            result = math_func(m - 1, 1)
        else:
            result = math_func(m - 1, math_func(m, n - 1))
    except RecursionError:
        result = "Numbers are too big. Maximum recursion depth may be reached."
    return result

#****************************************************************************************************

def main():
    print("Your study efficiency factor is: ", math_func(0, 3))
    print("Your study efficiency factor is: ", math_func(2, 0))
    print("Your study efficiency factor is: ", math_func(2, 3))

    m = int(input("Enter the study time (m): "))
    n = int(input("Enter the quality of the study technique (n): "))

    if m > 10 or n > 10:
        print("Numbers are too big. Maximum recursion depth may be reached.")
    else:
        result = math_func(m, n)
        print("Your study efficiency factor is: ", result)

#****************************************************************************************************

if __name__ == "__main__":
    main()

#****************************************************************************************************

"""
Your study efficiency factor is:  4
Your study efficiency factor is:  3
Your study efficiency factor is:  9
Enter the study time (m): 2
Enter the quality of the study technique (n): 3
Your study efficiency factor is:  9

Enter the study time (m): 56
Enter the quality of the study technique (n): 89
Numbers are too big. Maximum recursion depth may be reached.

"""