package application;

import java.lang.Math;

public class Projectile {
	// declare name
	private String name;
	private double Xdis;
	private double Ydis;
	private boolean isFlying = true;
	public static final double MAX_HEIGHT = 2500;
	public static final double MAX_WIDTH = 2000;

	public double heightArray[];

	public Projectile(String inputName, double height[]) {
		// set name to inputed name
		heightArray = height;
		name = inputName;
	}

	public String getName() {
		return name;
	}

	public void move(double time) {

	}

	// setter of Y displacement
	public void setDisplacementy(double Ydis) {

		this.Ydis = Ydis;
	}

	// setter of X displacement
	public void setDisplacementx(double Xdis) {

		this.Xdis = Xdis;
	}

	// getter of X displacement
	public double getDisplacementx() {

		return (Xdis);
	}

	// getter of y displacement
	public double getDisplacementy() {
		return (Ydis);
	}

	// Setter of isFlying
	public void setisFlying(boolean isFlying) {

		this.isFlying = isFlying;
	}

	// getter of isflying boolean
	public boolean isFlying() {

		return (isFlying);
	}

	public static double rand(double lower, double upper) {
		return Math.random() * (upper - lower) + lower;
	}

}
