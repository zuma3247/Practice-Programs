
package edu.webster.week2;

import java.io.*;
import java.util.Scanner;

public class Tail
{
    public static void main(String[] args) throws IOException
    {
        int linesToDisplay = 7; // try a variety of values here when testing 0, negative, positive.
        String temp;
        int startPrint = 0;
        int fileLength = 0;

        File myFile = new File( "src//edu//webster//week2//test.txt");

        if ( !myFile.exists())
        {
            System.out.println("Cannot find file " + myFile.getName() + " exiting program.");
            System.out.println("The above program was written by: PUT YOUR NAME HERE");
            System.exit(0);
        }
        
        Scanner inputFile = new Scanner( myFile );
        int lineCount = 0;
        
        while (inputFile.hasNext())
        {
            // Add logic here to figure out # of lines in the file.
            // Hint: Read a line with the scanner and increment the lineCount
            // you need just two lines of code here.
            // TODO START:
            temp = inputFile.nextLine();
            lineCount++;
            // TODO END:
        }

        inputFile.close();  // close the file
        
        System.out.println("Number of lines found in file: " + lineCount );        
        System.out.println("Will now display the last: " + linesToDisplay + " lines in the file." );
           
        // Now that you kmow how many lines are in the file
        // Determine where you want to start outputing 
        // If the display count is > # of lines in the file skip any file output
        // TODO START

        System.out.println();
        if ( linesToDisplay > lineCount )
        {
            System.out.println( "Display count is > # of lines in the file." );
        }
        else
        {

        // TODO END

        fileLength = lineCount;
        lineCount = 0;
        
        inputFile = new Scanner( myFile ); // open the file again
        
        // loop through the file again
        while (inputFile.hasNext())
        {
            // logic here to figure out what lines to print
            // Hint read the inputfile until you get the first line
            // to print and then print the remainder of the file. 
            // for example if your file is 10 lines long and you are 
            // asked to print the last 3 lines, start printing at line 8.
            // TODO START

            temp = inputFile.nextLine();
            lineCount++;

            startPrint = ( fileLength - linesToDisplay ) + 1;
            if ( (lineCount >= startPrint) && (lineCount <= fileLength))
            {
                System.out.println( temp );
            }
             // TODO END
        }
        inputFile.close();
        }
        System.out.println();
        System.out.println("The above program was written by: MUAZUDDIN MOHAMMED");
        
    }
}

/*
Number of lines found in file: 7
Will now display the last: 7 lines in the file.

One
Two
Three
Four
Five
Six
Seven

The above program was written by: MUAZUDDIN MOHAMMED
 */