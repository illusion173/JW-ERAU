
/*
 * Student: Jeremiah Webb
 * Submission Date:10/10/2022 
 * Program Description: 
 * Class of a iterable stack
 *
 */
import java.util.Iterator;
import java.util.NoSuchElementException;

public class Stack<Item> implements Iterable<Item> {

	private int size_of_stack = 0;
	private Node top_of_stack;

	// essentially a linked list, with the tail being the top.
	private class Node {
		private Item item;
		private Node next;
	}

	// Initialize the empty stack

	public Stack() {
		top_of_stack = null;
		size_of_stack = 0;
	}

	public int size() {
		return size_of_stack;
	}

	public Item pop() {
		if (isEmpty())
			throw new NoSuchElementException("Stack Underflow");
		Item item = top_of_stack.item;
		top_of_stack = top_of_stack.next;
		size_of_stack--;
		return item; // return the popped item
	}

	public void push(Item item) {
		Node oldFirst = top_of_stack;
		top_of_stack = new Node();
		top_of_stack.item = item;
		top_of_stack.next = oldFirst;
		size_of_stack++;

	}

	/**
	 *
	 * @return True if stack is empty, else False
	 */
	public boolean isEmpty() {
		return top_of_stack == null;
	}

	/**
	 * Returns an iterator to this stack that iterates through the items in LIFO
	 * order.
	 * 
	 * @return an iterator to this stack that iterates through the items in LIFO
	 *         order.
	 */
	public Iterator<Item> iterator() {
		return new LinkedIterator();
	}

	// an iterator for the class, generic
	private class LinkedIterator implements Iterator<Item> {
		private Node current = top_of_stack;

		public boolean hasNext() {
			return current != null;
		}

		public Item next() {
			if (!hasNext())
				throw new NoSuchElementException();
			Item item = current.item;
			current = current.next;
			return item;
		}
	}
}
