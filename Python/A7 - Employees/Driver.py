#****************************************************************************************************
#
#   Name:       Muazuddin Mohammed
#   Course:     COSC 2110 Computer Languages: Python
#   Assignment: driver.py
#   Due Date:   03/07/2025
#   Description:
#       This is the driver program for an Employee class.
#
#****************************************************************************************************

import pickle
import Employee

#****************************************************************************************************

LOOK_UP = 1
ADD = 2
CHANGE = 3
DELETE = 4
QUIT = 5

FILENAME = 'employees.dat'

#****************************************************************************************************

def load_employees():
    try:
        in_file = open(FILENAME, 'rb')
        employee_dct = pickle.load(in_file)
    except IOError:
        employee_dct = {}
    except:
        print('An error occurred')
    else:
        in_file.close()

    return employee_dct

#****************************************************************************************************

def get_user_choice():
    print('Menu')
    print('-' * 40)
    print(LOOK_UP, '. Look up an employee')
    print(ADD, '. Add a new employee')
    print(CHANGE, '. Change an existing employee')
    print(DELETE, '. Delete an employee')
    print(QUIT, '. Quit the program')
    print()

    choice = int(input('Enter your choice: '))

    return choice

#****************************************************************************************************

def look_up(employee_dict):
    emp_id = input('Enter an employee ID number: ')
    print(employee_dict.get(emp_id, 'The specified ID number was not found.'))

#****************************************************************************************************

def add(employee_dict):
    emp_name = input('Enter employee name: ')
    emp_id = input('Enter employee ID number: ')

    if emp_id not in employee_dict:
        emp_dept = input('Enter employee department: ')
        emp_title = input('Enter employee title: ')

        employee_dict[emp_id] = Employee.Employee(emp_id, emp_name, emp_dept, emp_title)
        print('The new employee has been added.')
    else:
        print('An employee with that ID already exists.')

#****************************************************************************************************

def change(employee_dict):
    emp_id = input('Enter employee ID number: ')

    if emp_id in employee_dict:
        emp_name = input('Enter employee name: ')
        emp_dept = input('Enter employee department: ')
        emp_title = input('Enter employee title: ')

        employee_dict[emp_id] = Employee.Employee(emp_id, emp_name, emp_dept, emp_title)
        print('Employee record updated.')
    else:
        print('The specified ID number was not found.')

#****************************************************************************************************

def delete(employee_dict):
    emp_id = input('Enter employee ID number: ')

    if emp_id in employee_dict:
        del employee_dict[emp_id]
        print('Employee information deleted.')
    else:
        print('The specified ID number was not found.')

#****************************************************************************************************

def save_employees(employee_dict):
    try:
        in_file = open(FILENAME, 'wb')
        pickle.dump(employee_dict, in_file)
    except IOError:
        print('Cannot save employees info.')
    except:
        print('An error occurred.')
    else:
        in_file.close()

#****************************************************************************************************

def main():
    employee_dict = load_employees()

    employee_dict.update({
        '47899' : Employee.Employee('Susan Meyers', '47899', 'Accounting', 'Vice President'),
        '39119' : Employee.Employee('Mark Jones', '39119', 'IT', 'Programmer'),
        '81774' : Employee.Employee('Joy Rogers', '81774', 'Manufacturing', 'Engineer')})

    option = True

    while option:
        choice = get_user_choice()

        if choice == LOOK_UP:
            look_up(employee_dict)
            print()
        elif choice == ADD:
            add(employee_dict)
            print()
        elif choice == CHANGE:
            change(employee_dict)
            print()
        elif choice == DELETE:
            delete(employee_dict)
            print()
        elif choice == QUIT:
            save_employees(employee_dict)
            option = False
        else:
            print('Invalid choice.')

#****************************************************************************************************

if __name__ == '__main__':
    main()

#****************************************************************************************************

"""
Menu
----------------------------------------
1 . Look up an employee
2 . Add a new employee
3 . Change an existing employee
4 . Delete an employee
5 . Quit the program

Enter your choice: 1
Enter an employee ID number: 47899
Name: Susan Meyers
ID number: 47899
Department: Accounting
Title: Vice President

Menu
----------------------------------------
1 . Look up an employee
2 . Add a new employee
3 . Change an existing employee
4 . Delete an employee
5 . Quit the program

Enter your choice: 2
Enter employee name: John Doe
Enter employee ID number: 15632
Enter employee department: Management
Enter employee title: Manager
The new employee has been added.

Menu
----------------------------------------
1 . Look up an employee
2 . Add a new employee
3 . Change an existing employee
4 . Delete an employee
5 . Quit the program

Enter your choice: 3
Enter employee ID number: 100
The specified ID number was not found.

Menu
----------------------------------------
1 . Look up an employee
2 . Add a new employee
3 . Change an existing employee
4 . Delete an employee
5 . Quit the program

Enter your choice: 4
Enter employee ID number: 81774
Employee information deleted.

Menu
----------------------------------------
1 . Look up an employee
2 . Add a new employee
3 . Change an existing employee
4 . Delete an employee
5 . Quit the program

Enter your choice: 1
Enter an employee ID number: 81774
The specified ID number was not found.

Menu
----------------------------------------
1 . Look up an employee
2 . Add a new employee
3 . Change an existing employee
4 . Delete an employee
5 . Quit the program

Enter your choice: 5
"""