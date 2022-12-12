import java.util.Scanner;

public class CS225_Whitebox {

	public static void main(String[] paramArrayOfString) {
		int RectArea1;
		int RectArea2;
		Scanner scan = new Scanner(System.in);

		System.out.println("Please Input a number.");
		int RectX1 = scan.nextInt();
		System.out.println("Please Input a number.");
		int RectX2 = scan.nextInt();
		System.out.println("Please Input a number.");
		int RectY1 = scan.nextInt();
		System.out.println("Please Input a number.");
		int RectY2 = scan.nextInt();

		if (RectX1 < 0 || RectX2 < 0 || RectY1 < 0 || RectY2 < 0) {

			System.out.println("The numbers must be non-zero, positive numbers.");
			System.exit(0);
		}
		RectArea1 = RectX1 * RectY1;
		RectArea2 = RectX2 * RectY2;
		System.out.println("The Area of Rectangle 1: ," + RectArea1 + " The Area of Rectangle 2: " + RectArea2 + ".");
		if (RectArea1 == RectArea2) {
			System.out.println("The rectangles are equal in area!");
		} else if (RectArea1 > RectArea2) {
			System.out.println("Rectangle 1 has the larger area.");
		} else if (RectArea1 < RectArea2) {
			System.out.println("Rectangle 2 has the larger area.");
		}
	}

}