//*************************************************************************************************
//     File:               Pennies.java
//
//     Student:            Muazuddin Mohammed
//
//     Assignment:         Program#1.2
//
//     Course Name:        Java
//
//     Course Number:      COSC 2050
//
//     Due:                January 24, 2023
//
//     This program doubles pennies for every day worked.
//     It also includes an error check.
//
//*************************************************************************************************

import java.util.Scanner;

public class Pennies
{
    public static void main(String[] args)
    {
        double totalPennies = 1,
               totalAmount = 0;
        int days = 0,
            dailyPennies = 1;

        Scanner keyboard = new Scanner( System.in );

        System.out.println( "Earning a Penny A Day keeps the Banker away!\n" );

        System.out.print( "How many days will you work for a penny a day and "
                          + "double each day? " );
        days = keyboard.nextInt();
        System.out.println();

        if ( days <= 0 )
        {
            System.out.println( "Number of days given was less than one - " +
                                "input not accepted - run program again.");
            System.out.println();
        }
        else if ( days > 31)
        {
            System.out.println( "Number of days given was greater than 31 - " +
                                 "input not accepted - run program again.");
            System.out.println();
        }
        else
        {

        System.out.println( "Day 1 pennies paid: " + dailyPennies + "\n" );

        for ( int i = 2; i <= days; i++)
        {
            dailyPennies *= 2;
            totalPennies += dailyPennies;

            System.out.println( "Day " + i + " pennies paid: " + dailyPennies + "\n" );
        }

        totalAmount = totalPennies / 100.0;

        System.out.printf("Total amount paid is: $%.2f%n", totalAmount);
        System.out.println();

        }

        System.out.println( "The above program was written by: Muaz");
        System.out.println( repeat( "ABC", "123" ) );
    }

    public static String repeat ( String s1, String s2 )
    {
        return s1 + s1 + s2 + s2;
    }


}

//*************************************************************************************************

/*

Earning a Penny A Day keeps the Banker away!

How many days will you work for a penny a day and double each day? 10

Day 1 pennies paid: 1

Day 2 pennies paid: 2

Day 3 pennies paid: 4

Day 4 pennies paid: 8

Day 5 pennies paid: 16

Day 6 pennies paid: 32

Day 7 pennies paid: 64

Day 8 pennies paid: 128

Day 9 pennies paid: 256

Day 10 pennies paid: 512

Total amount paid is: $10.23

The above program was written by: Muaz

----------------------------------------------------------

Earning a Penny A Day keeps the Banker away!

How many days will you work for a penny a day and double each day? -2

Number of days given was less than one - input not accepted - run program again.

The above program was written by: Muaz

*/