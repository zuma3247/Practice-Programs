package edu.webster.arrays;

public class ArrayUtilities
{

	public static void main(String[] args)
	{
		int myArray[][] = {{ 1, 2, 3, 4},   // row 0
						   { 5, 6, 7, 8}};  // row 1
	
		System.out.println("Total value of array is: " + getTotalValue(myArray));
		System.out.println("Average of array is:     " + getAverageOfArray(myArray));
		System.out.println("Row total is:            " + getRowTotal(myArray, 1));  // total for row #1
		System.out.println("Column total is:         " + getColumnTotal(myArray, 2));  // total for column #2
		
        System.out.println("\nThe above program was written by: MUAZUDDIN MOHAMMED");
	}

	private static int getTotalValue(int[][] myArray)
	{
		int total=0;	
		for (int row = 0; row < myArray.length; row++)
		{
			for (int col = 0; col < myArray[0].length; col++)
			{
				total = total + myArray[row][col];
			}
		}
		return total;
	}
	
	private static double getAverageOfArray(int[][] myArray)
	{
		double avg;
		int total = 0;
		int numOfNumbers = 0;

		for (int row = 0; row < myArray.length; row++)
		{
			for (int col = 0; col < myArray[0].length; col++)
			{
				total = total + myArray[row][col];
				numOfNumbers++;
			}
		}

		avg = ((double) total) / numOfNumbers;

		// TODO Fill in code here.
		return avg;
	}
	
	private static int getRowTotal(int[][] myArray, int rowNumber )
	{
		int total = myArray[rowNumber][0];

		for (int col = 1; col < myArray[0].length; col++)
		{
			total = total + myArray[rowNumber][col];
		}
		// TODO Fill in code here.
		return total;
	}
	
	private static int getColumnTotal(int[][] myArray, int columnNumber)
	{
		int total = myArray[0][columnNumber];


		for (int row = 1; row < myArray.length; row++)
		{
			total = total + myArray[row][columnNumber];
		}
		// TODO Fill in code here.
		return total;
	}
}
