
public class Racer {

	
	
	public static void main(String[] args) {
		
		// 1. declare all starting points
		
		// 2. while the any racer has not cross the finish line
		
			// 2-1. take a turn
			// 2-2. move racer1, racer2, racer3, racer4
		
		// 3. find out who won
			
	}

	
	// example of a random number generator given a lower and higher bound
	public static int randomFrom (int low, int high) {
		
		int randNum = 0;
		
		// (int) is casting since Math.random() return a double and randNum is an int
		randNum = (int) (Math.random()*(high-low) + low);
		
		return randNum;
	}
	
	
	// example for Racer1 
	public static int Racer1Move() {
		
		// declare variables
		int move; 
		// flip a coin
		int randNum = randomFrom(0, 2);
		
		// if 1 move 4
		if (randNum == 1) {
			move = 4;
			
		// if 0 move 8
		} else {
			move = 8;
		}
		return move;
	}
	
}
