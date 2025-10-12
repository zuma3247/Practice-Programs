package edu.webster.behaviors;

public class Runnner
{
    public static void main(String[] args)
    {
        Athlete james = new Athlete();
        OfficeWorker brad = new Academic();

        System.out.println("toString for Athlete Object:");
        System.out.println( james.toString());

        System.out.println("toString for Academic Object:");
        System.out.println(brad.toString());

        System.out.println("The above program was written by: MUAZUDDIN MOHAMMED");
    }
}
