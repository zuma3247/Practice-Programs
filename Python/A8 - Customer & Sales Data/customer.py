#****************************************************************************************************
#
#   Name:       Muazuddin Mohammed
#   Course:     COSC 2110 Computer Languages: Python
#   Assignment: customer.py
#   Due Date:   03/21/2025
#   Description:
#       This program defines a Customer class.
#
#****************************************************************************************************

import person

#****************************************************************************************************

class Customer(person.Person):
    def __init__(self, name, telephone, customer_num, mail_list):
        person.Person.__init__(self, name, telephone)
        self.__customer_num = customer_num
        self.__mail_list = mail_list

#****************************************************************************************************

    def get_customer_num(self):
        return self.__customer_num

#****************************************************************************************************

    def set_customer_num(self, customer_num):
        self.__customer_num = customer_num

#****************************************************************************************************

    def get_mail_list(self):
        return self.__mail_list

#****************************************************************************************************

    def set_mail_list(self, mail_list):
        self.__mail_list = mail_list

#****************************************************************************************************

    def __str__(self):
        if self.__mail_list:
            mail_status = "on mailing list"
        else:
            mail_status = "not on mailing list"

        return f"{self.get_name()} {self.get_telephone()} {self.__customer_num} {mail_status}"

#****************************************************************************************************