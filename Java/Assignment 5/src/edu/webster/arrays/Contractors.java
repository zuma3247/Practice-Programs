package edu.webster.arrays;

public class Contractors extends Hourly
{
    private String assignments;
    private int numMonthlyRequests;

    public Contractors(String firstName, String lastName, int empID,
                       float hourlyRate, float startTime, float endTime,
                       String address, String assignments, int numMonthlyRequests)
    {
        super(firstName, lastName, empID, hourlyRate, startTime, endTime, address);
        this.assignments = assignments;
        this.numMonthlyRequests = numMonthlyRequests;
    }

    public Contractors()
    {
        super();
        this.assignments = "None Assigned";
        this.numMonthlyRequests = 0;
    }

    public String getAssignments()
    {
        return assignments;
    }

    public void setAssignments(String assignments)
    {
        this.assignments = assignments;
    }

    public int getNumMonthlyRequests()
    {
        return numMonthlyRequests;
    }

    public void setNumMonthlyRequests(int numMonthlyRequests)
    {
        this.numMonthlyRequests = numMonthlyRequests;
    }

    public void displayAssignments ()
    {
        System.out.println( "Assignment(s): " + getAssignments() );
    }

    public void displayMonthlyReq ()
    {
        System.out.println( "Monthly Requests: " + getNumMonthlyRequests() );
    }

    public String toString()
    {
        String output;

        output = super.toString() +
                "\nAssignments: " + getAssignments() +
                "\n# of Monthly Requests: " + getNumMonthlyRequests();

        return output;
    }
}
