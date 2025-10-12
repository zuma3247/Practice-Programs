package edu.webster.behaviors;

public class Academic implements edu.webster.behaviors.OfficeWorker, edu.webster.behaviors.Teacher
{

    @Override
    public String toString()
    {
        scheduleMeeting("noon","EAB");
        calculatePay(20,30);
        repeatAfterMe("JAVA CLASS", 3);

        return "Fav Subject is " + myFavoriteSubjectToTeachIs("Math") + "\n" +
               "My Full Name is " + myFullNameIs("Muazuddin", "Mohammed") + "\n";
    }

    @Override
    public void scheduleMeeting(String time, String location)
    {
        System.out.println("Meeting Time: " + time);
        System.out.println("Meeting location: " + location);
        System.out.println();
    }

    @Override
    public void calculatePay(int hoursWorked, float hourlyRate)
    {
        float pay = hoursWorked * hourlyRate;
        System.out.println("Pay = " + pay);
        System.out.println();
    }

    @Override
    public String myFavoriteSubjectToTeachIs(String subject)
    {
        return subject;
    }

    @Override
    public String myFullNameIs(String first, String last)
    {
        return first + " " + last;
    }


    @Override
    public void repeatAfterMe(String aWord, int count)
    {
        for (int i = 0; i < count; i++)
        {
            System.out.println(aWord);
        }
        System.out.println();
    }
}
