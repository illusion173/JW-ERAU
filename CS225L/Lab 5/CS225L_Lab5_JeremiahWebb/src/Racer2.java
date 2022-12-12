/*
 * Racer2.java
 * Student: Jeremiah Webb ID 2545328
 * Class: 225L Section Fall 2021
 * 
 * 
 */
public class Racer2 extends GenericRacer {
	private int location;

	public Racer2(String inputName) {
		super(inputName);
	}

	public void move() {
		int move;
		int randNum = RaceGame.randomFrom(2, 10);
		move = randNum;
		setLocation(getLocation() + move);
	}
}
