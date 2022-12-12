import java.util.Scanner;

/* 
*	SurfaceAreaCalculator.java 
*	Written By: Jeremiah Webb ID 2545328 Credit to Troy Neubauer for assisting me with this homework
*	CS 225 Fall 2021
*/

/*NOTE
 * Needed Equations
 * a. Surface area SA, in square inches. SA = 2 · (l · h + w · h + l · w).
 * b. Surface area in square centimeters, SASI = 2.54 · 2.54 · 2 · (l · h + w · h + l · w)
 * 
 * REQUIREMENTS
 * R1. The software shall correctly compute the package surface area, SA.
 * R2. The software shall correctly compute the package surface area, SASI.
 * R3. The software shall accept user input for package l, w, and h. Units are in inches.
 * R4. The software shall display SA and SASI for the l, w, and h values entered by the user.
 * R5. The software shall display SA and SASI for the three test cases provided below.
 * 
 */

public class SurfaceAreaCalculator {

	private static double getDouble(Scanner scanner, String message, String errorMessage) {
		while (true) {
			try {
				System.out.print(message);
				double value = scanner.nextDouble();
				return value;
			} catch (Exception e) {
				scanner.nextLine();
				System.out.println();
			}
			System.out.println(errorMessage);
		}
	}

	private static void runCase(double length, double width, double height, String message, double expectedSA,
			double expectedSASI) {
		System.out.println(message);
		// SA = = 2 · (l · h + w · h + l · w)
		double sa = 2 * (length * height + width * height + length * width);
		System.out.println("Surface area is " + sa + " in^2");

		final double IN_CM = 2.54;
		System.out.println("SI (CM) Surface area is " + (sa * IN_CM * IN_CM) + " cm^2");

		if (expectedSA != -1) {
			// We are in a test case. Compare the expected value with the calculated one
			if (sa != expectedSA) {
				System.err.println(
						"Test case has \"" + message + "\" failed! Expected SA " + expectedSA + " but got " + sa);
				System.exit(1);
			} else {
				System.out.println("Test case has passed");
			}
		}
		System.out.println();
	}

	public static void main(String[] args) {
		System.out.println("\nRunning built in test cases to ensure calculator functions correctly\n");
		// Test Case 1 length = height = width = 0.0
		runCase(0, 0, 0, "Test case 1", 0, 0);
		// Test Case 2 length = 15.0, height = 10.0, width = 0.0
		runCase(15, 10, 0, "Test case 2", 300.0, 1935.48);
		// Test Case 3 length = 10.0, height = width = 1.0
		runCase(10, 1, 1, "Test case 3", 42.0, 270.97);

		System.out.println("Entering input stage");
		System.out.println("_____________________");
		// Begin Scanner
		Scanner scanner = new Scanner(System.in);
		// Enter Length & Check
		double length = getDouble(scanner, "\nPlease enter the length of your package in inches: ",
				"Please enter a decimal number\n");
		// Enter Width & Check
		double width = getDouble(scanner, "\nPlease enter the width of your package in inches: ",
				"Please enter a decimal number\n");
		// Enter Height & Check
		double height = getDouble(scanner, "\nPlease enter the height of your package in inches: ",
				"Please enter a decimal number\n");
		// Run User input
		runCase(length, width, height, "User results: ", -1, -1);

		// Close Scanner
		scanner.close();
	}
}