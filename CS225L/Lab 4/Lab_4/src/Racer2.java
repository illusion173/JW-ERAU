//Racer 2 shall move randomly 2 to 10 units per turn. 
public class Racer2 {


	String name = "Fenix";
	int move;
	int location;

	public void move() {

		int randNum = RaceGame.randomFrom(2, 11);
		move = randNum;
		location = location + move;
	}

	public int getLocation() {
		return location;
	}

	public String getName() {
		return name;
	}

}
