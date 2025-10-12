#****************************************************************************************************
#
#   Name:       Muazuddin Mohammed
#   Course:     COSC 2110 Computer Languages: Python
#   Assignment: sales_associate.py
#   Due Date:   03/21/2025
#   Description:
#       This program defines a Sales Associate class.
#
#****************************************************************************************************

import person

#****************************************************************************************************

class SalesAssociate(person.Person):
    def __init__(self, name, telephone, sales_id, commission):
        person.Person.__init__(self, name, telephone)
        self.__sales_id = sales_id
        self.__commission = commission

#****************************************************************************************************

    def get_sales_id(self):
        return self.__sales_id

#****************************************************************************************************

    def set_sales_id(self, sales_id):
        self.__sales_id = sales_id

#****************************************************************************************************

    def get_commission(self):
        return self.__commission

#****************************************************************************************************

    def set_commission(self, commission):
        self.__commission = commission

#****************************************************************************************************

    def __str__(self):
        return f"{self.get_name()} {self.get_telephone()} {self.__sales_id} {self.__commission}"

#****************************************************************************************************
