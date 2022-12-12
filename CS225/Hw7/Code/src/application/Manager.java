package application;

import java.lang.Math;

public class Manager {
	private static final double TIME_INT = 0.5;
	public static double HHDistance = 0.0;
	public static boolean HareWin1 = false;

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
		// Run Hare
		while (Hare.isFlying()) {
			Hare.move(time);
			time += TIME_INT;
		}

		// Reset time
		time = 0;
		// Run hound
		while (Hound.isFlying()) {
			Hound.move(time);
			time += TIME_INT;
		}

		// HHdistance is distance between hound and hare
		HHDistance = Math.abs(Hare.getDisplacementx() - Hound.getDisplacementx());
		HHGUI.setDistance(HHDistance);

		// Begin Displaying
		if (HHDistance < 7) {
			HareWin1 = false;
			HHGUI.setHareWin(HareWin1);
		}
		if (HHDistance >= 7) {
			HareWin1 = true;
			HHGUI.setHareWin(HareWin1);
		}

		HHGUI.main(args);
	}

	// Random Number Generator
	public static double rand(double lower, double upper) {
		return Math.random() * (upper - lower) + lower;
	}
}
