//Racer4 shall move 45/2^turn  spaces per turn but must move at least 1 unit
public class Racer4 {
	String name = "Dijkstra";
	int move;
	int location;

	public void move(int turn) {
		int move;
		move = (int) (Math.round((45.0) / (Math.pow(2.0, turn))));
		location = location + Math.max(move, 1);
	}
	
	public int getLocation() {
		return location;
	}
	
	public String getName() {
		return name;
	}

}

