
/*
 * 
 * Racer.java
 * Written By: Jeremiah Webb ID 2545328
 * CS 225 Fall 2021
 * 
 *
 */
import java.util.Arrays;

public class racer {

	public static void main(String[] args) {
		
		// 1. declare all starting points
		double R1 = 0.0;
		double R2 = 0.0;
		double R3 = 0.0;
		double R4 = 0.0;
		// 2. while the any racer has not cross the finish line
		Final double finishLine = 100.0
		// 2-1. take a turn
		int turn = 0;
		// 2-2. move racer1, racer2, racer3, racer4
		do {
		R1 = Racer1Move();
		R2 = Racer2Move();
		R3 = Racer3Move();
		R4 = Racer4Move(turn);
		}
		while (R1 < FinishLine && R2 < finishLine> && R3 < finishLine && R4 < finishLine);
		
		// 3. find out who won
		
		double scores[] = new double [] {R1, R2, R3, R4};
		long winCount = Arrays.stream(scores).filter(value -> (value >= finishLine)).count());
		int winnerIndex = 0;
		for (int i = 1; i < scores.length; i++) {
			if (scores[i] > scores[winnerIndex]) {
				winnerIndex = i;
			}
		}
		if (winnerCount == 1) {
			System.out.println("Racer" + (winnerIndex + 1) + " Won the race with a distance of: " + scores[winnerIndex] + " after " + turn + " turns");
		} else {
			System.out.println("Its a tie!(" + winCount + " racers crossed the finish line in the same turn) But racer " + (winnerIndex + 1) + " Went the furthest with a distance of " + scores[winnerIndex] + " after " + turn + " turns");
		}
	
		}

	}

	// example of a random number generator given a lower and higher bound
	/*
	 * public static int randomFrom (int low, int high) {
	 * 
	 * int randNum = 0;
	 * 
	 * // (int) is casting since Math.random() return a double and randNum is an int
	 * randNum = (int) (Math.random()*(high-low) + low);
	 * 
	 * return randNum; }
	 */

	// MAIN DISTANCE FUNCTIONS
	public static int randomGen(int low, int high) {
		// (int) is casting since Math.random() return a double and randNum is an int
		return (int) (Math.random() * (high - low) + low);
	}

	// Racer 1
	public static int Racer1Move() {
		return randomFrom(0, 2) == 0 ? 4 : 8;
	}

	// Racer 2
	public static int Racer2Move() {
		return randomFrom(2, 10);
	}

	// Racer 3
	public static double Racer3Move() {
		if (randomFrom(0, 2) == 0) {
			return randomFrom(0, 10);
		} else {
			return 7.0 * Math.cos(7);
		}
	}

	// Racer 4
	public static double Racer4Move(int turn) {
		return Math.max(1.0, 45 / Math.pow(2, turn));
	}

}
