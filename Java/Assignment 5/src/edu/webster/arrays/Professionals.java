package edu.webster.arrays;

public class Professionals extends Staff
{
    private String certifications;
    private int numClients;

    public Professionals(String firstName, String lastName, int empID,
                         float salary, float bonus, String address,
                         String certifications, int numClients)
    {
        super(firstName, lastName, empID, salary, bonus, address);
        this.certifications = certifications;
        this.numClients = numClients;
    }

    public Professionals()
    {
        super();
        this.certifications = "No certifications assigned";
        this.numClients = 0;
    }

    public String getCertifications()
    {
        return certifications;
    }

    public void setCertifications(String certifications)
    {
        this.certifications = certifications;
    }

    public int getNumClients()
    {
        return numClients;
    }

    public void setNumClients(int numClients)
    {
        this.numClients = numClients;
    }

    public void clientNames ()
    {
        String[] names =
        {
            "John Doe",
            "Jane Smith",
            "Michael Johnson",
            "Emily Davis",
            "Christopher Wilson",
            "Jessica Brown",
            "Matthew Taylor",
            "Sarah Martinez",
            "David Anderson",
            "Jennifer Thomas"
        };

        int numNamesToPrint = getNumClients();

        System.out.println( "Client Names:" );
        for (int i = 0; i < numNamesToPrint; i++)
        {
            System.out.println( names[i] );
        }
    }

    public void displayCerts ()
    {
        System.out.println( "Certificates gained by: Mr. " + getLastName());
        System.out.println( getCertifications() );
    }

    public String toString()
    {
        String output;

        output = super.toString() +
                "\nCertifications: " + getCertifications() +
                "\nNum of Clients: " + getNumClients();

        return output;
    }
}
