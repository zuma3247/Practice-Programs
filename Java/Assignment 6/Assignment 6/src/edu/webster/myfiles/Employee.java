package edu.webster.myfiles;

import java.io.Serializable;

public class Employee implements Serializable
{
    private int empID;
    private String firstName;
    private String lastName;
    private String position;
    private int salary;

    public Employee(int empID, String firstName, String lastName, String position, int salary)
    {
        this.empID = empID;
        this.firstName = firstName;
        this.lastName = lastName;
        this.position = position;
        this.salary = salary;
    }

    public String toString ()
    {
        return "Emp ID: " + empID + "\nName: " + firstName +
                        " " + lastName + "\nPosition: " + position +
                        "\nSalary: $" + salary;
    }

}
