/*
 * GenericRacer.java
 * Student: Jeremiah Webb ID 2545328
 * Class: 225L Section Fall 2021
 * 
 */
public class GenericRacer {

	// declare location
	private int location;
	// declare name
	private String name;

	public GenericRacer(String inputName) {
		//set location to zero when GenericRacer is made
		location = 0;
		//set name to inputed name
		name = inputName;
	}
	
	public void move() {
		//do nothing
	}
	
	// get the location of GenericRacer
	public int getLocation() {
		return location;
	}
	// set the location of GenericRacer
	public void setLocation(int location) {
		this.location = location;
	}
	// get the name of GenericRacer
	public String getName() {
		return name;
	}
	// set the name of GenericRacer
	public void setName(String name) {
		this.name = name;
	}
	 
}
