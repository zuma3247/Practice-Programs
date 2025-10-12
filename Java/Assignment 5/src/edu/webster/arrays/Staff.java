package edu.webster.arrays;

public class Staff extends Employee
{
    private float salary;
    private float bonus;
    private String address;

    public Staff(String firstName, String lastName, int empID, float salary,
                 float bonus, String address)
    {
        super(firstName, lastName, empID);
        this.salary = salary;
        this.bonus = bonus;
        this.address = address;
    }

    public Staff()
    {
        super();
        this.salary = 0f;
        this.bonus = 0f;
        this.address = "Unknown address";
    }



    public float getSalary()
    {
        return salary;
    }

    public void setSalary(float salary)
    {
        this.salary = salary;
    }

    public double getBonus()
    {
        return bonus;
    }

    public void setBonus(float bonus)
    {
        this.bonus = bonus;
    }

    public String getAddress()
    {
        return address;
    }

    public void setAddress(String address)
    {
        this.address = address;
    }

    public String toString()
    {
        String output;

        output = super.toString() + "\nSalary: " + getSalary() + "\nBonus: " +
                getBonus() + "\nAddress: " + getAddress();

        return output;
    }
}
