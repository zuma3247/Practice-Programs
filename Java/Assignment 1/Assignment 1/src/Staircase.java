//*************************************************************************************************
//     File:               Staircase.java
//
//     Student:            Muazuddin Mohammed
//
//     Assignment:         Program#1
//
//     Course Name:        Java
//
//     Course Number:      COSC 2050
//
//     Due:                January 24, 2023
//
//     This program repeats a string by a user defined number and depth.
//
//*************************************************************************************************

import java.util.Scanner;

public class Staircase
{
    public static void main(String[] args)
    {
        String str,
               name,
               space = " ",
               repeatedSpace;
        int repeats = 0,
            depth = 0;
        Scanner keyboard = new Scanner( System.in );

        System.out.print( "Give me a string: ");
        str = keyboard.next();
        System.out.println();

        System.out.print( "Repeat Length: ");
        repeats = keyboard.nextInt();
        System.out.println();

        System.out.print( "Depth Length: ");
        depth = keyboard.nextInt();
        System.out.println();

        for ( int i = 0; i < repeats; i++)
        {
            for ( int j = 0; j < depth; j++)
            {
                repeatedSpace = space.repeat( j );
                System.out.print( repeatedSpace );
                System.out.print( str );
                System.out.println("\n");
            }
        }

        System.out.println( "The above program was written by: Muaz");
    }
}

//*************************************************************************************************

/*
Give me a string: Webster

Repeat Length: 3

Depth Length: 5

Webster

 Webster

  Webster

   Webster

    Webster

Webster

 Webster

  Webster

   Webster

    Webster

Webster

 Webster

  Webster

   Webster

    Webster

The above program was written by: Muaz

*/