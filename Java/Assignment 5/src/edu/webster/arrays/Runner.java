package edu.webster.arrays;

import java.util.ArrayList;

public class Runner
{
    public static void main(String[] args)
    {
        Management m1 = new Management ( "Jim", "Thomas", 1001,
                                         100000, 20000, "Webster Groves",
                                         3, 2300);

        Professionals p1 = new Professionals ( "Tyler", "Pratt", 1002, 90000,
                                                10000, "Lindberg",
                                                "AWS, Microsoft", 5);

        Assistants a1 = new Assistants ( "Zach", "Drew", 1003, 40,
                                         8.5f, 17.5f, "St. Charles",
                                         "Jim Thomas", 1);

        Contractors c1 = new Contractors ( "Muaz", "Mohammed", 1004, 50,
                                           9, 17, "Ballwin",
                                           "Design & Implementation", 3);

        System.out.println( m1.toString() );
        System.out.println();

        m1.conductPerfReview( p1, m1 );
        System.out.println( "Used Stipend ($): " + (m1.usedStipend()) );

        spaces();

        System.out.println( p1.toString() );
        System.out.println();

        p1.displayCerts();
        p1.clientNames();

        spaces();

        System.out.println( a1.toString() );
        System.out.println();

        a1.displayClearance();
        a1.displaySupervisor();

        spaces();

        System.out.println( c1.toString() );
        System.out.println();

        c1.displayAssignments();
        c1.displayMonthlyReq();

        spaces();

        int rand = randomGen(20,40);
        int select = 0;

        ArrayList<Employee> companyEmployees = new ArrayList<Employee>(rand);

        for (int i = 1; i < rand; i++)
        {
            select = (int) (Math.random() * 4);

            switch (select)
            {

                case 0:
                    Management m2 = new Management ( "James", "Curtis", 1001,
                            100000, 20000, "Webster Groves",
                            3, 2300);

                    companyEmployees.add(m2);

                    break;

                case 1:
                    Professionals p2 = new Professionals ( "Zendaya", "Kane", 1002, 90000,
                            10000, "Lindberg",
                            "AWS, Microsoft", 5);

                    companyEmployees.add(p2);
                    break;

                case 2:
                    Assistants a2 = new Assistants ( "Basel", "Longford", 1003, 40,
                            8.5f, 17.5f, "St. Charles",
                            "Jim Thomas", 1);

                    companyEmployees.add(a2);
                    break;

                case 3:
                    Contractors c2 = new Contractors ( "Happy", "Hogan", 1004, 50,
                            9, 17, "Ballwin",
                            "Design & Implementation", 3);

                    companyEmployees.add(c2);
                    break;

                default:
                    System.out.println("Error");
            }

            for (int j = 1; j < companyEmployees.size(); j++)
            {
                System.out.println(companyEmployees.get(j).toString());
                System.out.println();
            }
            System.out.println("Total Num of Employees created: " + rand);
        }

        System.out.println( "The above program was written by: MUAZUDDIN MOHAMMED" );
    }

    public static void spaces()
    {
        System.out.println();
        for (int i = 0; i < 50; i++)
        {
            System.out.print( "-" );
        }
        System.out.println("\n");
    }

    public static int randomGen(int min, int max)
    {
        double randomDouble = Math.random();
        int rangeSize = max - min;

        double scaledRandom = (randomDouble * rangeSize) + min;

        int randomInt = (int) scaledRandom;

        return randomInt;
    }

}
