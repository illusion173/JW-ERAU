import java.lang.Math;
public class Manager {

	private static final double GRAVITY = 9.81;
	private static final double TIME_INT = 0.5;

	public static void main(String[] args) {

		for (int i = 0; i < 2; i++) {
			double height = (i == 0) ? 0 : 120;
			double time = 0.0;
			
			System.out.println("\nStarting iteration #" + i + "\n");

			// Create Projectile objects Hare and Hound

			Projectile hare = new Projectile(0, rand(400, 1000), rand(70, 120), rand(0, 90), GRAVITY, height, "Hare");
			Projectile hound = new Projectile(0, 600, rand(50, 150), rand(0, 90), GRAVITY, height, "Hound");

			while (hare.isFlying() && hound.isFlying()) {

				hare.displayPos();
				hound.displayPos();

				hare.step(time);
				hound.step(time);
				time += TIME_INT;

			}
			System.out.println("Hare and hound hit ground " + Math.abs(hare.getX() - hound.getX()) + " Units apart");

		}

	}

	private static double rand(double lower, double upper) {
		return Math.random() * (upper - lower) + lower;
	}
}
