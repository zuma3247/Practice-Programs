package webster.hr;

public class Employee
{
    private String firstName;

    private String lastName;

    private int empID;

    public Employee(String firstName, String lastName, int empID)
    {
        this.firstName = firstName;
        this.lastName = lastName;
        this.empID = empID;
    }

    public Employee()
    {
        this.firstName = "firstName missing";
        this.lastName = "lastName missing";
        this.empID = 0;
    }

    public String getFirstName()
    {
        return firstName;
    }

    public void setFirstName(String firstName)
    {
        this.firstName = firstName;
    }

    public String getLastName()
    {
        return lastName;
    }

    public void setLastName(String lastName)
    {
        this.lastName = lastName;
    }

    public int getEmpID()
    {
        return empID;
    }

    public void setEmpID(int empID)
    {
        this.empID = empID;
    }

    public String toString ()
    {
        String output;
        output = "First Name: " + getFirstName() +
                "\nLast Name: " + getLastName() +
                "\nEmp ID: " + getEmpID();

        return output;
    }
}
