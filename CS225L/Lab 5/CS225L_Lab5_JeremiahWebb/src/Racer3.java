/*
 * Racer3.java
 * Student: Jeremiah Webb ID 2545328
 * Class: 225L Section Fall 2021
 * 
 * 
 */
public class Racer3 extends GenericRacer {
	int location;

	public Racer3(String inputName) {
		super(inputName);
	}

	// move method
	public void move() {
		int move;
		if (RaceGame.randomFrom(0, 2) == 1) {
			move = RaceGame.randomFrom(0, 10);
		} else {
			move = (int) (7 * (Math.acos(7)));
		}
		setLocation(getLocation() + move);
	}

}
