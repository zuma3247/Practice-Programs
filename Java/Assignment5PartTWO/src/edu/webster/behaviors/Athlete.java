package edu.webster.behaviors;

public class Athlete implements edu.webster.behaviors.BasketballPlayer
{

    @Override
    public String toString()
    {
        return "Jump: " + jump(7) + "\n" + "Position: " + myFavoritePositionToPlayIs() + "\n";
    }

    @Override
    public int jump(int howHigh)
    {
        return (howHigh - 1);
    }

    @Override
    public String myFavoritePositionToPlayIs()
    {
        int select = (int) (Math.random() * 3);
        String pos = "Initial";

        switch (select)
        {

            case 0:
                pos = "Attack";

                break;

            case 1:
                pos = "Midfield";

                break;

            case 2:
                pos = "Defence";
                break;

            default:
                System.out.println("Error");
        }

        return pos;
    }

}
