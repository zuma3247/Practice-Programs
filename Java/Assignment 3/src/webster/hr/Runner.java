package webster.hr;

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
}
