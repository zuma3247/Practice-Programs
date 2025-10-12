package edu.webster.myfiles;

public class StringPlay
{
    public static void main(String[] args)
    {
        String s1 = "Mary brought a sandwich and chips for lunch";
        String s2 = "Mark had a burrito and cookie for lunch";
        String s3 = "racecar";

        String [] splitWords1 = s1.split(" ");
        String [] splitWords2 = s2.split(" ");

        System.out.println("Common words are: \n");

        for (int i = 0; i < splitWords1.length; i++)
        {
            for (int j = 0; j < splitWords2.length; j++)
            {
                if ( splitWords1[i].equals( splitWords2[j]) )
                {
                    System.out.println(splitWords1[i]);
                }
            }
        }

        StringBuffer deSpaced = new StringBuffer( s3.replaceAll(" ", "") );
        StringBuffer sb = new StringBuffer( deSpaced.reverse() );

        if ( deSpaced.equals(sb) )
        {
            System.out.println("S3 which has the value of: " + s3 + "is a palindrome.");
        }
        else
        {
            System.out.println( "S3 which has the value of: " + s3 + "is NOT a palindrome.");
        }

        System.out.println("The above program was written by: MUAZUDDIN MOHAMMED");
    }
}
