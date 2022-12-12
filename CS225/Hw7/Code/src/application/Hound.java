package application;

public class Hound extends Projectile {
	private static final double HORIZONTAL_VEL = (11.3);
	private static final double VERTICAL_VEL = (9.81);
	private static final int INT_HEIGHT = 600;
	private static final double INITALX = 0.0;
	private double Xdisplacement, Ydisplacement;

	public Hound(String inputName, double height[]) {
		super(inputName, height);
		setDisplacementy(INT_HEIGHT);
	}

	public void move(double time) {
		if (!isFlying())
			return;
		// Equations

		Xdisplacement = (INITALX + HORIZONTAL_VEL + getDisplacementx());
		Ydisplacement = (getDisplacementy() - VERTICAL_VEL + burn());

		setDisplacementx(Xdisplacement);
		setDisplacementy(Ydisplacement);

		if (getDisplacementx() > MAX_WIDTH) {
			setisFlying(false);
			return;
		}
		if (getDisplacementy() > MAX_HEIGHT) {
			setisFlying(false);
			return;
		}

		int index = (int) ((getDisplacementx()) / 100);
		if (getDisplacementy() < heightArray[index]) {
			setisFlying(false);
		}
	}

	private int burn() {

		double temp = rand(0, 100);

		if (temp >= 60 && temp <= 90) {

			return (11);
		} else {
			return (0);
		}

	}

}