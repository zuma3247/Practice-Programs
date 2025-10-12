package edu.webster.week2;

public class RockPaperScissors
{
    public static void main(String[] args)
    {
        int fredWins = 0;
        int wilmaWins = 0;
        int noOneWins = 0;

        for (int x = 1; x <= 10; x++)
        {
            String wilmaChooses = randomlyPickRockPaperScissors();
            String fredChooses = randomlyPickRockPaperScissors();

            wilmaWins = wilmaWins + scoreAPoint(wilmaChooses, fredChooses);
            fredWins = fredWins + scoreAPoint(fredChooses, wilmaChooses);

            if (wilmaChooses.equals(fredChooses))
            {
                noOneWins++;
            }
        }

        System.out.println("Wilma win count:    " + wilmaWins);
        System.out.println("Fred win count:     " + fredWins);
        System.out.println("No One Wins count:  " + noOneWins);
        System.out.println("The above program was written by: Muaz");
    }

    public static String randomlyPickRockPaperScissors()
    {
        // add code here returning Rock, Paper or Scissors
        // See switch syntax in your book.

        String selection;

        switch ((int) (Math.random() * 3))
        {
            // TODO START

            case 1:
                selection = "Rock";
                break;

            case 2:
                selection = "Paper";
                break;

            default:
                selection = "Scissors";

           // TODO END
        }

        return selection;
    }

    public static int scoreAPoint(String player1, String player2)
    {
        // LOGIC to determine who beats who.  According to the game.
        // Rock beats Scissors
        // Scissors beats Paper
        // Paper beats Rock
        // Return a 1 if its a beats, else a 0
        // TODO START

        int outcome = 0;

        if ( (player1 == "Rock") && (player2 == "Scissors") )
        {
            outcome = 1;
        }
        else if ( (player1 == "Scissors") && (player2 == "Paper") )
        {
            outcome = 1;
        }
        else if ( (player1 == "Paper") && (player2 == "Rock") )
        {
            outcome = 1;
        }
        //no need to say else outcome = 0 because it was already initialized.

        return outcome;

        // TODO END

    }
}

/*
Wilma win count:    6
Fred win count:     3
No One Wins count:  1
The above program was written by: Muaz
 */