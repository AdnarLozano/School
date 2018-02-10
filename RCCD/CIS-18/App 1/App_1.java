

import java.util.Scanner;

public class App_1
{
	public static void main (String[] args)
	{
		Scanner input = new Scanner (System.in);
		
		int num1, num2, num3;
		int	sum;
		
		String h = "Hello World!!!";
		
		System.out.println(h);
		System.out.println("--------------\n");

		System.out.println("You will enter three integers, then we will calculate the average.\n");

		System.out.print("Please enter first interger: ");

		num1 = input.nextInt();

		System.out.print("Please enter second interger: ");

		num2 = input.nextInt();

		System.out.print("Please enter third interger: ");

		num3 = input.nextInt();

		sum = num1 + num2 + num3;

		System.out.printf("\nThe sum of all three integers is %d\n\n", sum);

		if (num1 == num2)
			System.out.printf(num1 + " is equal to " + num2 + "\n");

		if (num1 != num2)
			System.out.printf( "%d != %d\n", num1, num2 );

		if (num1 < num2)
			System.out.printf( "%d < %d\n", num1, num2 );

		if (num1 > num2)
			System.out.printf( "%d > %d\n", num1, num2 );

		if (num1 <= num2)
			System.out.printf( "%d <= %d\n", num1, num2 );

		if (num1 >= num2)
			System.out.printf( "%d >= %d\n", num1, num2 );

	}

}
