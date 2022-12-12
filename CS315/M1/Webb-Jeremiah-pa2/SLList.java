
/*
 * Student: Jeremiah Webb
 * Submission Date:10/10/2022 
 * Program Description: 
 * Class & interface implementing a singly linked list
 *
 */

// Given interface
interface LinkedList<Item> {
	public Item getAt(int loc);

	public Item deleteAt(int loc);

	public void addToHead(Item Node);

	public void addToTail(Item Node);

	public void addAt(int loc, Item node);

	public void printFwd();

	public void printRev();

	public boolean isEmpty();

}

public class SLList<Item> implements LinkedList<Item> {
	private Node head;
	private Node tail;

	private class Node {
		Item data;
		Node next;
	}

	public Item getAt(int loc) {

		if ((head == null) || (loc < 0)) {

			return null;
		}

		Node current = head;

		for (int i = 0; i < loc; i++) {
			if (current.next == null) {
				return null;
			}
			current = current.next;
		}
		return current.data;
	};

	public Item deleteAt(int loc) {

		// Special case - empty list
		if ((head == null) || (loc < 0))
			return null;

		// Iterate to the node prior
		Node prevNode = null;
		Node cur = head;
		for (int i = 0; i < loc; i++) {
			// If index is out of bounds, no delete.
			if (cur == null)
				return null;
			prevNode = cur;
			cur = cur.next;
		}

		Item item = cur.data;
		// Special case - last
		if ((cur == head) && (cur == tail)) {
			head = tail = null;
		}
		// Special Case - head
		else if (cur == head) {
			head = head.next;
		}
		// Special Case - tail
		else if (cur == tail) {
			tail = prevNode;
			tail.next = null;
		}
		// Default case
		else {
			prevNode.next = cur.next;
		}
		return item;
	}

	// Add to the head of the linked list
	public void addToHead(Item item) {
		Node newNode = new Node();
		newNode.next = head;
		newNode.data = item;

		if (head == null) {
			head = tail = newNode;
		} else {
			head = newNode;
		}

	};

	// Add to the end of the list
	public void addToTail(Item item) {
		Node newNode = new Node();
		newNode.next = null;
		newNode.data = item;
		if (tail == null) {
			head = tail = newNode;
		} else {
			tail.next = newNode;
			tail = newNode;
		}
		;
	};

	public void addAt(int loc, Item item) {

		// If the list doesn't exist yet, begin list.
		if ((loc <= 0) || (head == null)) {
			addToHead(item);
			return;
		}

		// Go to location -1, or tail

		Node current = head;

		for (int i = 0; i < (loc - 1); i++) {
			if (current.next == null)
				break;
			current = current.next;
		}

		// If adding to tail
		if (current == tail) {
			addToTail(item);
			return;
		}

		// Base case

		Node newNode = new Node();
		newNode.data = item;
		newNode.next = current.next;
		current.next = newNode;

	}

	public void printFwd() {
		Node current = head;
		while (current != null) {
			System.out.print("" + current.data);
			current = current.next;
		}
	};

	// We could do this recursively, so public and private are needed
	private void printRev(Node current) {
		if (current == null) {
			return;
		} else {
			printRev(current.next);
			System.out.print("" + current.data);
		}

	};

	// Print the reverse list
	public void printRev() {
		printRev(head);
	};

	// Is the list empty? Boolean
	public boolean isEmpty() {
		return head == null;
	};

}
