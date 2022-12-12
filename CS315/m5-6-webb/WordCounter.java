
/**
 * Implements a word frequency counter using a binary search tree and a heap.
 */
import java.util.NoSuchElementException;
import java.util.Arrays;
import java.util.Collections;
import java.util.ArrayList;

public class WordCounter {

	public static void countWords(String[] words) {
		// creation of bst
		BST<String, Integer> bst = new BST<String, Integer>();
		for (int i = 0; i < words.length; i++) {
			// if the bst already contains the word,
			// increment by 1
			if (bst.contains(words[i])) {
				int amount = bst.get(words[i]);
				int new_amount = amount + 1;
				bst.put(words[i], new_amount);
			} else {
				bst.put(words[i], 1);
			}
		}
		// In order Traversal Here
		System.out.println("BST - Word Count - Alphabetical - Beginning");
		bst.inorder_traversal();
		System.out.println("BST - Word Count - Alphabetical - End");

		// Heap Sorting here
		//
		// Iterate over all the bst keys to get values
		// Create two new arrays for data
		String[] word_array = new String[bst.size()];
		int[] amount_array = new int[bst.size()];
		int i = 0;
		for (String word : bst.keys()) {
			int amount = bst.get(word);
			// word being word, amount being amount of occurances of that word
			word_array[i] = word;
			amount_array[i] = amount;
			i++;
		}

		MaxHeap<Integer, String> h = new MaxHeap<Integer, String>(bst.size());
		for (i = 0; i < amount_array.length; i++) {
			h.enqueue(amount_array[i], word_array[i]);
		}
		while (h.isEmpty() == false) {
			System.out.println(h.dequeue().get(0) + ", " + h.dequeue().get(1));
		}

	}

	public static void main(String[] args) {
		String input = "input.txt";
		WordCounter.countWords(InputReader.parseInputFile(input));
	}
}

// Retrieved from Stansbury Github!
// To simplify this class, I am statically typing the data types of the
// arraylists and node functions, however, later on I should implement generic
// types <Key,Value>
/**
 * Implementation of a max heap (i.e. highest priority values are dequeued
 * sooner.
 * 
 * @param <P> - comparable type for priority
 * @param <T> - Information associated with the priority.
 */
class MaxHeap<P extends Comparable<P>, T> {

	HeapNode<P, T>[] heap;
	int count = 0;

	/**
	 * Default constructor for an empty heap.
	 * 
	 * @param maxSize - maximum storage size of heap.
	 */
	public MaxHeap(int maxSize) {
		heap = new HeapNode[maxSize];
	}

	/**
	 * Constructor for heap with the data passed in by two arrays (one for
	 * priorities and one for their corresponding
	 * information)
	 * 
	 * @param priority - array of priorities
	 * @param info     - array of info
	 */
	public MaxHeap(P[] priority, T[] info) {

		if (priority.length != info.length) {
			System.err.println("Invalid input");
			return;
		}

		// Copy data into an array
		this.heap = new HeapNode[priority.length];
		this.count = priority.length;

		for (int i = 0; i < priority.length; i++) {
			heap[i] = new HeapNode<P, T>(priority[i], info[i]);
		}

		// Heapify using Floyd's Algorithm
		floydsAlgorithm();
	}

	/**
	 * Enqueues a new item into the heap-based priority queue
	 * 
	 * @param priority - priority of new value
	 * @param item     - info of new value.
	 */
	public void enqueue(P priority, T item) {
		if (count == heap.length) {
			System.err.println("Heap full, unable to add");
			return;
		}

		int parent;
		int cur = count; // Add item to the last location
		heap[cur] = new HeapNode<P, T>(priority, item);
		count++; // Increment Count;

		while (cur > 0) {

			parent = getParentIndex(cur);

			// if cur is smaller than parent, then swap
			if (heap[cur].priority.compareTo(heap[parent].priority) > 0) {
				swap(cur, parent);
				cur = parent;
			} else
				return;
		}
	}

	/**
	 * Dequeues and returns maximum priority value from the heap.
	 * 
	 * @return info of maximum priority in heap.
	 */
	public ArrayList<Object> dequeue() {
		// Check for empty
		if (count == 0)
			return null;

		// Remove item and store in tmp
		T tmp = (T) heap[0].info;
		P tmp2 = (P) heap[0].priority;
		count--;

		// Copy last leaf into the root location
		heap[0] = heap[count];

		// Move new root down to its proper locaiton in the heap
		// i.e. repair heap
		moveDown(0, count - 1);
		ArrayList<Object> data = new ArrayList<Object>();
		data.add(tmp);
		data.add(tmp2);
		return data;
	}

	/**
	 * Restores a heap by moving a value down through the array.
	 * 
	 * @param first - first index of move down algorithm
	 * @param last  - last index of the move down algorithm
	 */
	public void moveDown(int first, int last) {
		int cur = first;
		int largest = 2 * cur + 1; // Left child of cur

		while (largest <= last) {

			// If two children, find largest of two.
			if (largest < last)
				if (heap[largest].priority.compareTo(heap[largest + 1].priority) < 0)
					largest++;

			// Compare cur with largest sub-child.
			if (heap[cur].priority.compareTo(heap[largest].priority) < 0) {
				swap(cur, largest);
				cur = largest;
				largest = 2 * cur + 1;
			} else
				return; // Done restoring
		}

	}

	/**
	 * Returns index of the parent of the node specified by the parameter index.
	 * 
	 * @param index - index whose parent we are seeking.
	 * @return
	 */
	private int getParentIndex(int index) {
		if ((index % 2) == 0)
			return (index - 2) / 2;
		else
			return (index - 1) / 2;
	}

	/**
	 * Swaps values between locations in the heap.
	 * 
	 * @param cur
	 * @param parent
	 */
	private void swap(int cur, int parent) {
		HeapNode<P, T> tmp = heap[cur];
		heap[cur] = heap[parent];
		heap[parent] = tmp;
	}

	/**
	 * @return true if empty, else otherwise.
	 */
	public boolean isEmpty() {
		return (count == 0);
	}

	/**
	 *
	 * @return true if full, false othewise.
	 */
	public boolean isFull() {
		return (count == heap.length);
	}

	/**
	 * Simple wrapper class for the priority and information of a heap item.
	 * 
	 * @param <P>
	 * @param <T>
	 */
	public class HeapNode<P, T> {
		public P priority;
		public T info;

		public HeapNode(P priority, T info) {
			this.priority = priority;
			this.info = info;
		}
	}

	/**
	 * Algorithm that heapifies an array
	 */
	private void floydsAlgorithm() {
		int lastNonLeaf = (heap.length / 2 - 1);
		for (int i = lastNonLeaf; i >= 0; i--) {
			moveDown(i, count - 1);
		}
	}

	/**
	 * Generates an array of values from 0 to size - 1 that is
	 * randomly shuffled.
	 * 
	 * @param size - size of the array
	 * @return random array
	 */
	public static Integer[] getRandomArray(int size) {

		Integer[] arr = new Integer[size];

		for (int i = 0; i < size; i++) {
			arr[i] = (size - 1) - i;
		}

		Collections.shuffle(Arrays.asList(arr));

		return arr;
	}
}

// Received from Princeton Github!
class BST<Key extends Comparable<Key>, Value> {
	private Node root; // root of BST

	private class Node {
		private Key key; // sorted by key
		private Value val; // associated data
		private Node left, right; // left and right subtrees
		private int size;

		public Node(Key key, Value val, int size) {
			this.key = key;
			this.val = val;
			this.size = size;
		}
	}

	/**
	 * Initializes an empty symbol table.
	 */
	public BST() {
	}

	/**
	 * Returns the number of key-value pairs in this symbol table.
	 * 
	 * @return the number of key-value pairs in this symbol table
	 */
	public int size() {
		return size(root);
	}

	// return number of key-value pairs in BST rooted at x
	private int size(Node x) {
		if (x == null)
			return 0;
		else
			return x.size;
	}

	/**
	 * Returns true if this symbol table is empty.
	 * 
	 * @return {@code true} if this symbol table is empty; {@code false} otherwise
	 */
	public boolean isEmpty() {
		return size() == 0;
	}

	/**
	 * Does this symbol table contain the given key?
	 *
	 * @param key the key
	 * @return {@code true} if this symbol table contains {@code key} and
	 *         {@code false} otherwise
	 * @throws IllegalArgumentException if {@code key} is {@code null}
	 */
	public boolean contains(Key key) {
		if (key == null)
			throw new IllegalArgumentException("argument to contains() is null");
		return get(key) != null;
	}

	/**
	 * Returns the value associated with the given key.
	 *
	 * @param key the key
	 * @return the value associated with the given key if the key is in the symbol
	 *         table
	 *         and {@code null} if the key is not in the symbol table
	 * @throws IllegalArgumentException if {@code key} is {@code null}
	 */
	public Value get(Key key) {
		return get(root, key);
	}

	private Value get(Node x, Key key) {
		if (key == null)
			throw new IllegalArgumentException("calls get() with a null key");
		if (x == null)
			return null;
		int cmp = key.compareTo(x.key);
		if (cmp < 0)
			return get(x.left, key);
		else if (cmp > 0)
			return get(x.right, key);
		else
			return x.val;
	}

	/**
	 * Returns all keys in the symbol table in ascending order,
	 * as an {@code Iterable}.
	 * To iterate over all of the keys in the symbol table named {@code st},
	 * use the foreach notation: {@code for (Key key : st.keys())}.
	 *
	 * @return all keys in the symbol table in ascending order
	 */
	public Iterable<Key> keys() {
		if (isEmpty())
			return new Queue<Key>();
		return keys(min(), max());
	}

	/**
	 * Returns all keys in the symbol table in the given range
	 * in ascending order, as an {@code Iterable}.
	 *
	 * @param lo minimum endpoint
	 * @param hi maximum endpoint
	 * @return all keys in the symbol table between {@code lo}
	 *         (inclusive) and {@code hi} (inclusive) in ascending order
	 * @throws IllegalArgumentException if either {@code lo} or {@code hi}
	 *                                  is {@code null}
	 */
	private Iterable<Key> keys(Key lo, Key hi) {
		if (lo == null)
			throw new IllegalArgumentException("first argument to keys() is null");
		if (hi == null)
			throw new IllegalArgumentException("second argument to keys() is null");

		Queue<Key> queue = new Queue<Key>();
		keys(root, queue, lo, hi);
		return queue;
	}

	private void keys(Node x, Queue<Key> queue, Key lo, Key hi) {
		if (x == null)
			return;
		int cmplo = lo.compareTo(x.key);
		int cmphi = hi.compareTo(x.key);
		if (cmplo < 0)
			keys(x.left, queue, lo, hi);
		if (cmplo <= 0 && cmphi >= 0)
			queue.enqueue(x.key);
		if (cmphi > 0)
			keys(x.right, queue, lo, hi);
	}

	/**
	 * Returns the smallest key in the symbol table.
	 *
	 * @return the smallest key in the symbol table
	 * @throws NoSuchElementException if the symbol table is empty
	 */
	public Key min() {
		if (isEmpty())
			throw new NoSuchElementException("calls min() with empty symbol table");
		return min(root).key;
	}

	private Node min(Node x) {
		if (x.left == null)
			return x;
		else
			return min(x.left);
	}

	/**
	 * Returns the largest key in the symbol table.
	 *
	 * @return the largest key in the symbol table
	 * @throws NoSuchElementException if the symbol table is empty
	 */
	public Key max() {
		if (isEmpty())
			throw new NoSuchElementException("calls max() with empty symbol table");
		return max(root).key;
	}

	private Node max(Node x) {
		if (x.right == null)
			return x;
		else
			return max(x.right);
	}

	/**
	 * Removes the smallest key and associated value from the symbol table.
	 *
	 * @throws NoSuchElementException if the symbol table is empty
	 */
	public void deleteMin() {
		if (isEmpty())
			throw new NoSuchElementException("Symbol table underflow");
		root = deleteMin(root);
	}

	private Node deleteMin(Node x) {
		if (x.left == null)
			return x.right;
		x.left = deleteMin(x.left);
		x.size = size(x.left) + size(x.right) + 1;
		return x;
	}

	public void delete(Key key) {
		if (key == null)
			throw new IllegalArgumentException("calls delete() with a null key");
		root = delete(root, key);
	}

	private Node delete(Node x, Key key) {
		if (x == null)
			return null;

		int cmp = key.compareTo(x.key);
		if (cmp < 0)
			x.left = delete(x.left, key);
		else if (cmp > 0)
			x.right = delete(x.right, key);
		else {
			if (x.right == null)
				return x.left;
			if (x.left == null)
				return x.right;
			Node t = x;
			x = min(t.right);
			x.right = deleteMin(t.right);
			x.left = t.left;
		}
		x.size = size(x.left) + size(x.right) + 1;
		return x;
	}

	/**
	 * Inserts the specified key-value pair into the symbol table, overwriting the
	 * old
	 * value with the new value if the symbol table already contains the specified
	 * key.
	 * Deletes the specified key (and its associated value) from this symbol table
	 * if the specified value is {@code null}.
	 *
	 * @param key the key
	 * @param val the value
	 * @throws IllegalArgumentException if {@code key} is {@code null}
	 */
	public void put(Key key, Value val) {
		if (key == null)
			throw new IllegalArgumentException("calls put() with a null key");
		if (val == null) {
			delete(key);
			return;
		}
		root = put(root, key, val);

	}

	private Node put(Node x, Key key, Value val) {
		if (x == null)
			return new Node(key, val, 1);
		int cmp = key.compareTo(x.key);
		if (cmp < 0)
			x.left = put(x.left, key, val);
		else if (cmp > 0)
			x.right = put(x.right, key, val);
		else
			x.val = val;
		x.size = 1 + size(x.left) + size(x.right);
		return x;
	}

	private void inorder_traversal(Node node) {

		if (node == null) {
			return;
		}
		inorder_traversal(node.left);
		System.out.println(node.key + ", " + node.val);
		inorder_traversal(node.right);
	}

	public void inorder_traversal() {
		inorder_traversal(root);
	}

}
