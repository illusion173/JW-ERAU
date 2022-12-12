import java.util.Scanner;

public class Two_Lab2 {

	public static boolean checkPerfectSquare(double userNumberInput) {

		double sq = Math.sqrt(userNumberInput);

		return ((sq - Math.floor(sq)) == 0);
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String badPassword = "password";

		double userNumberInput = 0;
		System.out.println("Please Input a password");
		String userInputtedPassword = input.next();
		String correctPassword = "password1";

		int k = 0;
		while (k < 1) {
			if (userInputtedPassword.equals(correctPassword)) {
				System.out.println("CORRECT!");
				k++;
			} else if (userInputtedPassword.equals(badPassword)) {
				System.out.println("That password is too simple and obvious.");
				
			} else {
				System.out.println("That password is bad and not valid.");
			
			}
		}

		int i = 0;
		while (i < 1) {
			System.out.println("Input a random whole number value!");
			userNumberInput = input.nextDouble();
			if (userNumberInput > 100) {
				System.out.println("Number bigger than 100.");
				System.out.println("Please input a number less than 100.");
			} else if (userNumberInput <= 100 && userNumberInput > 3) {
				i++;
			} else {
				System.out.println("Number lower than 3");
				System.out.println("Please input a number bigger than 3.");
			}
		}

		int j = 0;
		int counter = 0;
		while (j < 1) {
			if (checkPerfectSquare(userNumberInput)) {
				System.out.println("The number's square root is: " + Math.sqrt(userNumberInput) + ".");
				j++;
			} else {
				System.out.println("The number was too large, subtracting one!");
				userNumberInput = userNumberInput - 1;
				counter++;
			}
		}

		if (counter <= 3 && userInputtedPassword.equals(correctPassword)) {
			System.out.println("Do or Do not, there is no try - Yoda");
		} else if (counter > 3) {
			System.out.println("Took more than 3 subtractions!");
			return;
		} else if (userInputtedPassword.equals(correctPassword)) {
			System.out.println("Wrong password!");
			return;
		}

	}
}