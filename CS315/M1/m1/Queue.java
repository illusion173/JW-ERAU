import java.util.NoSuchElementException;
import java.util.Iterator;

/*
 * Student: Jeremiah Webb
 * Submission Date:
 * Program Description:
 * Class & Iterable interface implementing an Array based queue.
 *
 *
 *
 */

public class Queue<Item> implements Iterable<Item> {
	// Base initial cap of items
	private static final int INIT_CAPACITY = 10;

	private Item[] q_elements; // queue elements array
	private int num_of_elements; // amount of elements
	private int first_element; // index of first element
	private int last_element; // index of last element

	/**
	 *
	 * Constructor for empty queue
	 *
	 * 
	 */
	public Queue() {
		q_elements = (Item[]) new Object[INIT_CAPACITY]; // Actually creating the array
		num_of_elements = 0;
		first_element = 0;
		last_element = 0;
	}

	/*
	 * Print out queue.
	 *
	 */
	public void printqueue() {
		for (int i = 0; i < num_of_elements; i++) {
			System.out.print(q_elements[i]);
		}
	}

	/*
	 * Returns the number of items in the queue.
	 *
	 * 
	 * @return the number of items in the queue.
	 *
	 */

	public int size() {
		return num_of_elements;
	}

	/*
	 * The Queue Empty?
	 * 
	 * @returns boolean, true if empty, else false.
	 *
	 */
	public boolean isEmpty() {
		return num_of_elements == 0;
	}

	// resize the underlying array
	private void resize(int capacity) {
		assert capacity >= num_of_elements;
		Item[] copy = (Item[]) new Object[capacity];
		for (int i = 0; i < num_of_elements; i++) {
			copy[i] = q_elements[(first_element + i) % q_elements.length];
		}
		q_elements = copy;
		first_element = 0;
		last_element = num_of_elements;
	}

	/*
	 *
	 * @param item the item to be added to the queue
	 *
	 */

	public void enqueue(Item item) {
		// If the current number of elements is at limit, double size.
		if (num_of_elements == q_elements.length)
			resize(2 * q_elements.length);
		q_elements[last_element++] = item; // Physically add the item to the array.
		if (last_element == q_elements.length)
			last_element = 0; // Do a wrap around!
		num_of_elements++; // Update item amount.
	}

	/*
	 * @return item on this queue that was least recently added.
	 * 
	 * @throws java.util.NoSuchElementException if queue is empty.
	 *
	 */

	public Item dequeue() {
		if (isEmpty())
			throw new NoSuchElementException("Queue Underflow");

		Item item = q_elements[first_element];
		q_elements[first_element] = null;
		num_of_elements--;
		first_element++;
		// Wrap around
		if (first_element == q_elements.length)
			first_element = 0;
		// Shrink size of array
		if (num_of_elements > 0 && num_of_elements == q_elements.length / 5)
			resize(q_elements.length / 5);
		return item;
	}

	/**
	 * Returns an iterator that iterates over the items in this queue in FIFO order.
	 * 
	 * @return an iterator that iterates over the items in this queue in FIFO order
	 */
	public Iterator<Item> iterator() {
		return new ArrayIterator();
	}

	// an iterator, doesn't implement remove() since it's optional
	private class ArrayIterator implements Iterator<Item> {
		private int i = 0;

		public boolean hasNext() {
			return i < num_of_elements;
		}

		public Item next() {
			if (!hasNext())
				throw new NoSuchElementException();
			Item item = q_elements[(i + first_element) % q_elements.length];
			i++;
			return item;
		}
	}
};
