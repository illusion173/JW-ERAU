import java.lang.Math;

public class Manager {
	private static final double TIME_INT = 0.5;
	private static double HHDistance = 0.0;

	public static double[] createPlateu() {
		int arraylength = 20;
		double heightArray[] = new double[arraylength];
		for (int i = 0; i < arraylength; i++) {
			heightArray[i] = rand(100, 350);
		}
		return (heightArray);
	}

	public static void main(String[] args) {

		double[] heightArray = createPlateu();
		// Create objects hare and Hound
		Projectile Hare = new Hare("Hare", heightArray);
		Projectile Hound = new Hound("Hound", heightArray);
		double time = 0.0;
		System.out.println("LAUNCHING HARE!");
		// Run Hare
		while (Hare.isFlying()) {
			System.out.println("The " + Hare.getName() + " is at: " + Hare.getDisplacementx() + ", "
					+ Hare.getDisplacementy() + " at time " + time + " seconds");
			Hare.move(time);
			time += TIME_INT;
		}

		// Reset time
		time = 0;
		System.out.println("LAUNCHING HOUND!");
		// Run hound
		while (Hound.isFlying()) {
			System.out.println("The " + Hound.getName() + " is at: " + Hound.getDisplacementx() + ", "
					+ Hound.getDisplacementy() + " at time " + time + " seconds");
			Hound.move(time);
			time += TIME_INT;
		}

		HHDistance = Math.abs(Hare.getDisplacementx() - Hound.getDisplacementx());

		System.out.println("Hare and hound hit ground " + HHDistance + " meters apart");

		if (HHDistance < 7) {
			System.out.println("The Hound Wins!");
		}
		if (HHDistance >= 7) {
			System.out.println("The Hare Wins!");
		}

	}

	// Random Number Generator
	public static double rand(double lower, double upper) {
		return Math.random() * (upper - lower) + lower;
	}
}
