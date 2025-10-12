package webster.hr;

public class Assistants extends Hourly
{
    private String reportingSupervisor;
    private int securityClearance;

    public Assistants(String firstName, String lastName, int empID,
                      float hourlyRate, float startTime, float endTime,
                      String address, String reportingSupervisor,
                      int securityClearance)
    {
        super(firstName, lastName, empID, hourlyRate, startTime, endTime, address);
        this.reportingSupervisor = reportingSupervisor;
        this.securityClearance = securityClearance;
    }

    public Assistants()
    {
        super();
        this.reportingSupervisor = "None assigned";
        this.securityClearance = 0;
    }

    public String getReportingSupervisor()
    {
        return reportingSupervisor;
    }

    public void setReportingSupervisor(String reportingSupervisor)
    {
        this.reportingSupervisor = reportingSupervisor;
    }

    public int getSecurityClearance()
    {
        return securityClearance;
    }

    public void setSecurityClearance(int securityClearance)
    {
        this.securityClearance = securityClearance;
    }

    public void displayClearance ()
    {
        switch (getSecurityClearance())
        {
            case 1:
                System.out.println( "High Security Clearance");
                break;

            case 2:
                System.out.println( "Medium Security Clearance");
                break;

            case 3:
                System.out.println( "General Security Clearance");
                break;

            default:
                System.out.println( "No Security Clearance");
        }
    }

    public void displaySupervisor ()
    {
        System.out.println( "Supervisor: " + getReportingSupervisor() );
    }

    public String toString()
    {
        String output;

        output = super.toString() +
                "\nReporting Supervisor: " + getReportingSupervisor() +
                "\nSecurity Clearance: " + getSecurityClearance();

        return output;
    }
}
