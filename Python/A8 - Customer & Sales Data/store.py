#****************************************************************************************************
#
#   Name:       Muazuddin Mohammed
#   Course:     COSC 2110 Computer Languages: Python
#   Assignment: store.py
#   Due Date:   03/21/2025
#   Description:
#       This is the driver program utilizing both classes.
#
#****************************************************************************************************

from customer import Customer
from sales_associate import SalesAssociate

#****************************************************************************************************

def main():
    sale_1 = SalesAssociate("Jane", "123-987", "A905", 8.7)
    sale_2 = SalesAssociate("John", "905-437", "X337", 9.5)
    sale_3 = SalesAssociate("Joe", "314-636", "B522", 10.7)
    sale_4 = SalesAssociate("Anna", "765-432", "D789", 7.5)

    cust_1 = Customer("Mary", "909-457", "C921", True)
    cust_2 = Customer("Mike", "415-678", "C100", False)
    cust_3 = Customer("Moe", "897-909", "C607", True)
    cust_4 = Customer("Lisa", "112-334", "C345", False)

    store_dict = { sale_1 : cust_1, sale_2 : cust_2,
                   sale_3 : cust_3, sale_4 : cust_4 }

    print("All Sales:")
    print("*" * 50)
    for sales in store_dict.keys():
        print(sales)
        print()

    print('All Customers:')
    print("*" * 50)
    for customers in store_dict.values():
        print(customers)
        print()

    print(f"\n{'Sales':<10}Customers:")
    print("*" * 50)
    for sales, customers in store_dict.items():
        print(f'{sales.get_name():<10}{customers.get_name():<10}')

#****************************************************************************************************

if __name__ == "__main__":
    main()

#****************************************************************************************************

'''
All Sales:
**************************************************
Jane 123-987 A905 8.7

John 905-437 X337 9.5

Joe 314-636 B522 10.7

Anna 765-432 D789 7.5

All Customers:
**************************************************
Mary 909-457 C921 on mailing list

Mike 415-678 C100 not on mailing list

Moe 897-909 C607 on mailing list

Lisa 112-334 C345 not on mailing list


Sales     Customers:
**************************************************
Jane      Mary      
John      Mike      
Joe       Moe       
Anna      Lisa      

'''