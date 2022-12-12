
public class Hare extends Projectile {

	private double rads, initialVel, initialHeight, angle;
	private double Xdisplacement, Ydisplacement;
	private static final double GRAVITY = 9.81;
	private static final double VELOCITYX_INC = (10);
	private static final double INITALX = 0.0;

	public Hare(String inputName, double height[]) {
		super(inputName, height);
		// Initial angle between 0 and 90
		angle = rand(0, 90);
		// Convert
		rads = Math.toRadians(angle);
		// Initial velocity from 70 to 120 m/s
		initialVel = rand(70, 120);
		// Initial height from 400 to 1000
		initialHeight = rand(400, 1000);
		setDisplacementy(initialHeight);
	}

	public void move(double time) {

		if (!isFlying())
			return;

		// Equations
		Xdisplacement = (initialVel * time * Math.cos(rads)) + INITALX;

		Ydisplacement = (initialVel * time * Math.sin(rads)) - (0.5 * GRAVITY * time * time) + initialHeight;

		if ((time % (1.5)) == 0) {
			Xdisplacement = Xdisplacement + VELOCITYX_INC;
		}

		setDisplacementx(Xdisplacement);
		setDisplacementy(Ydisplacement);

		if (getDisplacementy() > MAX_HEIGHT) {
			setisFlying(false);
			return;
		}

		if (getDisplacementx() > MAX_WIDTH) {
			setisFlying(false);
			return;
		}

		int index = (int) ((getDisplacementx()) / 100);

		if (getDisplacementy() < heightArray[index]) {
			setisFlying(false);
		}

	}
}