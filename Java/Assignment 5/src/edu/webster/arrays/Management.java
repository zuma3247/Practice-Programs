package edu.webster.arrays;

public class Management extends Staff
{
    private int numSubordinates;
    private float businessStipend;

    public Management(String firstName, String lastName, int empID,
                      float salary, float bonus, String address,
                      int numSubordinates, float businessStipend)
    {
        super(firstName, lastName, empID, salary, bonus, address);
        this.numSubordinates = numSubordinates;
        this.businessStipend = businessStipend;
    }

    public Management()
    {
        super();
        this.numSubordinates = 0;
        this.businessStipend = 0f;
    }

    public int getNumSubordinates()
    {
        return numSubordinates;
    }

    public void setNumSubordinates(int numSubordinates)
    {
        this.numSubordinates = numSubordinates;
    }

    public float getBusinessStipend()
    {
        return businessStipend;
    }

    public void setBusinessStipend(float businessStipend)
    {
        this.businessStipend = businessStipend;
    }

    public void conductPerfReview (Professionals emp, Management manager)
    {
        System.out.println( "Manager: Mr. " + manager.getLastName());
        System.out.println( "Reviewing: Mr. " + emp.getLastName());
        System.out.println( "Productivity: " + (int) (Math.random() * 100));
        System.out.println( "Teamwork: " + (int) (Math.random() * 100));
    }

    public float usedStipend ()
    {
        float usedAmount;
        int random = (int) (Math.random() * 100);

        usedAmount = (getBusinessStipend() * random) / 100;

        return usedAmount;
    }

    public String toString()
    {
        String output;

        output = super.toString() +
                "\nNum of Subordinates: " + getNumSubordinates() +
                "\nBusiness Stipend: " + getBusinessStipend();

        return output;
    }
}
