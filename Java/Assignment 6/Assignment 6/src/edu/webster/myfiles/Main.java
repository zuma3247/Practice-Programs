package edu.webster.myfiles;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Random;


public class Main
{
    public static void main(String[] args) throws IOException, ClassNotFoundException
    {
        ObjectOutputStream objectOutputFile;
        try (FileOutputStream outStream = new
                FileOutputStream("src//edu//webster//myfiles//MyEmployeeObjects.dat", false))
        {
            objectOutputFile = new ObjectOutputStream(outStream);
        }

        int numEmps = getRandomNum();

        ArrayList<Employee> empsOut = new ArrayList<Employee>();

        for ( int i = 0; i < numEmps; i++)
        {
            Employee emp = new Employee( getRandomEmpID(), getRandomFirstName(), getRandomLastName(),
                    getRandomCompanyPosition(), getRandomSalary() );
            empsOut.add(i, emp);

            objectOutputFile.writeObject(empsOut.get(i));
        }

        objectOutputFile.close();

        FileInputStream inStream = new
                FileInputStream("src//edu//webster//myfiles//MyEmployeeObjects.dat");
        ObjectInputStream objectInputFile = new ObjectInputStream( inStream );

        ArrayList<Employee> empsIn = new ArrayList<Employee>();

        for ( int i = 0; i < numEmps; i++)
        {
            Employee temp = (Employee) objectInputFile.readObject();
            empsIn.add(temp);
        }
        System.out.println(empsIn.toString());

        objectInputFile.close();

        System.out.println("The above program was written by: MUAZUDDIN MOHAMMED");
    }

    public static String getRandomFirstName()
    {
        String[] firstNames = { "John", "Mary", "Michael", "Jennifer",
                                "David", "Linda", "Robert",
                                "Patricia", "James", "Susan", "William",
                                "Karen", "Richard",
                                "Jessica", "Joseph", "Sarah", "Charles",
                                "Nancy", "Thomas", "Lisa" };
        Random random = new Random();
        int randomIndex = random.nextInt(firstNames.length);
        return firstNames[randomIndex];
    }

    public static String getRandomLastName()
    {
        String[] lastNames = { "Smith", "Johnson", "Williams", "Jones",
                               "Brown", "Davis", "Miller", "Wilson", "Moore",
                               "Taylor", "Anderson", "Thomas", "Jackson",
                               "White", "Harris", "Martin", "Thompson",
                               "Garcia", "Martinez", "Robinson" };

        Random random = new Random();
        int randomIndex = random.nextInt(lastNames.length);
        return lastNames[randomIndex];
    }

    public static int getRandomEmpID()
    {
        Random random = new Random();
        return random.nextInt(9000) + 1000;
    }

    public static int getRandomSalary()
    {
        Random random = new Random();
        return random.nextInt(90000) + 10000;
    }

    public static int getRandomNum()
    {
        Random random = new Random();
        return random.nextInt(11) + 10;
    }

    public static String getRandomCompanyPosition()
    {
        String[] companyPositions = { "CEO", "CTO", "CFO", "COO", "CMO",
                "Software Engineer", "Data Scientist", "Product Manager",
                "Marketing Manager", "Sales Manager",
                "HR Manager", "Operations Manager", "Finance Manager",
                "Business Analyst", "UX/UI Designer",
                "QA Engineer", "Technical Support Specialist",
                "System Administrator", "Network Engineer", "DevOps Engineer" };

        Random rand = new Random();
        int index = rand.nextInt(companyPositions.length);
        return companyPositions[index];
    }



}
