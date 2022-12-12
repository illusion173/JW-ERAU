/*
 * Racer4.java
 * Student: Jeremiah Webb ID 2545328
 * Class: 225L Section Fall 2021
 * 
 * 
 */
public class Racer4 extends GenericRacer {
	int location;

	public Racer4(String inputName) {
		super(inputName);
	}

	// move method
	public void move(int turn) {
		int move;
		move = (int) (Math.round((45.0) / (Math.pow(2.0, turn))));
		location = location + Math.max(move, 1);
		setLocation(getLocation() + move);
	}
}
