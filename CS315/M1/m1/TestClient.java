
/*
 * Student: Jeremiah Webb
 * Submission Date: 10/10/2022 
 * Program Description: 
 * Test client for a linked list, queue iterable, and stack iterable implementation.
 *
 */
import java.util.Iterator;

public class TestClient {

	public static void main(String[] args) {

		System.out.println("Beginning Test Client");

		System.out.println("Begin Linked List Test");
		list_test_client new_test_list_client = new list_test_client();
		new_test_list_client.run_tests();
		System.out.println("");
		System.out.println("");
		System.out.println("Begin Queue Test");
		// Begin testing
		queue_test_client new_queue_test_client = new queue_test_client();
		new_queue_test_client.run_tests();

		System.out.println("");
		System.out.println("");

		System.out.println("Begin Stack Testing");
		stack_test_client new_stack_test_client = new stack_test_client();
		new_stack_test_client.run_tests();

	}

}

// Below are classes to support the testing of the different implemented data
// structures.
//
//
// Class that tests the implemented Stack data structure.
class stack_test_client {
	stack_test_client() {

	}

	public void run_tests() {
		tpush();
		tpop();
		tIsEmpty();
		tSize();
		testIterator();
	}

	static void tpush() {
		System.out.println("-----Test push(Item item)-----");

		Stack s = new Stack<>();
		System.out.println("List Expected: 0");
		System.out.print("List Got: 0");
		System.out.println("");
		s.push(0);

		System.out.println("List Expected: 0, 1");
		System.out.print("List Got: 0,1 ");
		System.out.println("");
		s.push(1);

	}

	static void tpop() {
		System.out.println("-----Test pop()-----");

		Stack s = new Stack<>();
		s.push(0);
		s.push(1);
		System.out.println("Return Expected: 1");
		System.out.print("Return Got: ");
		System.out.println(s.pop());

		s.push(1);
		s.push(2);
		s.push(3);
		System.out.println("Return Expected:3");
		System.out.print("Return Got: ");
		System.out.println(s.pop());

		System.out.println("Return Expected: 2");
		System.out.print("Return Got: ");
		System.out.println(s.pop());

		System.out.println("Return Expected: 1");
		System.out.print("Return Got: ");
		System.out.println(s.pop());

	}

	static void tIsEmpty() {
		System.out.println("-----Test isEmpty()-----");

		Stack s = new Stack<>();
		System.out.println("Return Expected: true");
		System.out.print("Return Got: ");
		System.out.println(s.isEmpty());
		System.out.println("");
		s.push(0);
		System.out.println("Return Expected: false");
		System.out.print("Return Got: ");
		System.out.println(s.isEmpty());
		System.out.println("");
	}

	static void tSize() {
		System.out.println("-----Test size()-----");

		Stack s = new Stack<>();
		System.out.println("Return Expected: 0");
		System.out.print("Return Got: ");
		System.out.println(s.size());

		s.push(0);
		System.out.println("Return Expected: 1");
		System.out.print("Return Got: ");
		System.out.println(s.size());

	}

	static void testIterator() {
		System.out.println("-----Test Iterator-----");

		Stack s = new Stack<>();
		s.push(0);
		s.push(1);
		s.push(3);
		Iterator itr = s.iterator();

		while (itr.hasNext()) {
			Object element = itr.next();
			System.out.print(element + " ");
		}
		System.out.println();

	}
}

// Class that tests the implemented array queue data structure.
class queue_test_client {

	queue_test_client() {

	}

	public void run_tests() {
		testEnqueue();
		testDequeue();
		testIsEmpty();
		testSize();
		System.out.println("-----Test Iterator-----");
		testIterator();
	}

	static void testEnqueue() {
		System.out.println("-----Test enqueue(Item item)-----");

		Queue q = new Queue<>();
		System.out.println("List Expected: 3");
		System.out.print("List Got: ");
		q.enqueue(3);
		q.printqueue();
		System.out.println("");
		System.out.println("List Expected: 3, 4");
		System.out.print("List Got: ");
		q.enqueue(4);
		q.printqueue();
		System.out.println("");
	}

	static void testDequeue() {
		System.out.println("-----Test dequeue()-----");

		Queue q = new Queue<>();

		q.enqueue(0);
		q.enqueue(1);
		System.out.println("Return Expected: 0");
		System.out.print("Return Got: ");
		System.out.println(q.dequeue());
		q.enqueue(1);
		q.enqueue(2);
		System.out.println("Return Expected: 1");
		System.out.print("Return Got: ");
		System.out.println(q.dequeue());
	}

	static void testIsEmpty() {
		System.out.println("-----Test isEmpty()-----");

		Queue q = new Queue<>();
		System.out.println("Return Expected: true");
		System.out.print("Return Got: ");
		System.out.println(q.isEmpty());

		q.enqueue(0);
		System.out.println("Return Expected: false");
		System.out.print("Return Got: ");
		System.out.println(q.isEmpty());
	}

	static void testSize() {
		System.out.println("-----Test size()-----");

		Queue q = new Queue<>();
		System.out.println("Return Expected: 0");
		System.out.print("Return Got: ");
		System.out.println(q.size());

		q.enqueue(0);
		System.out.println("Return Expected: 1");
		System.out.print("Return Got: ");
		System.out.println(q.size());
	}

	static void testIterator() {

		Queue q = new Queue<>();
		q.enqueue(0);
		q.enqueue(1);
		q.enqueue(3);
		Iterator itra = q.iterator();

		while (itra.hasNext()) {
			Object element = itra.next();
			System.out.print(element + " ");
		}
		System.out.println();

	}

}

// Class that tests the implemented linked list data structure.
class list_test_client {

	list_test_client() {

	}

	public void run_tests() {
		testPrintFwd();
		testPrintRev();
		testGetAt();
		testDeleteAt();
		testAddtoHead();
		testAddToTail();
		testAddAt();
		testIsEmpty();
	}

	// Utility function for filling list with test items
	static SLList filledList(int num) {
		SLList list = new SLList<>();
		for (int i = 0; i < num; i++) {
			list.addToTail(i);
		}
		return list;
	}

	static void testIsEmpty() {
		System.out.println("-----Test isEmpty()-----");

		SLList list = filledList(0);
		System.out.println("Return Expected: true");
		System.out.print("Return Got: ");
		System.out.println(list.isEmpty());

		list = filledList(1);
		System.out.println("Return Expected: false");
		System.out.print("Return Got: ");
		System.out.println(list.isEmpty());
	}

	static void testAddAt() {
		System.out.println("-----Test addAt(int loc, Item item)-----");
		SLList list = filledList(0);
		System.out.println("List Expected: test");
		System.out.print("List Got: ");
		list.addAt(1, "test");
		list.printFwd();

		System.out.println("");
		System.out.println("List Expected: testtest");
		System.out.print("List Got: ");
		list.addAt(0, "test");
		list.printFwd();

		System.out.println("");
		list = filledList(6);
		System.out.println("List Expected: 0, 1, 2, 3, test, 4, 5");
		System.out.print("List Got: ");
		list.addAt(4, "test");
		list.printFwd();

		System.out.println("");
	}

	static void testAddToTail() {
		System.out.println("-----Test addToTail(Item item)-----");

		SLList list = filledList(0);
		System.out.println("List Expected: 0");
		list.addToTail(0);
		System.out.print("List Got: ");
		list.printFwd();
		System.out.println("");

		System.out.println("List Expected: 0, 1");
		list.addToTail(1);
		System.out.print("List Got: ");
		list.printFwd();

		System.out.println("");
	}

	static void testAddtoHead() {
		System.out.println("-----Test addToHead(Item item)-----");

		SLList list = filledList(0);
		System.out.println("List Expected: 1");
		list.addToHead(1);
		System.out.print("List Got: ");
		list.printFwd();

		System.out.println("");
		System.out.println("List Expected: 4, 1");
		list.addToHead(4);
		System.out.print("List Got: ");
		list.printFwd();

		System.out.println("");
	}

	static void testGetAt() {
		System.out.println("-----Test getAt(int loc)-----");

		SLList list = filledList(2);
		System.out.println("Return Expected: Null");
		System.out.print("Return Got: ");
		System.out.println(list.getAt(2));

		list = filledList(3);
		System.out.println("Return Expected: 2");
		System.out.print("Return Got: ");
		System.out.println(list.getAt(2));

	}

	static void testDeleteAt() {
		System.out.println("-----Test deleteAt(int loc)-----");

		SLList list = filledList(0);

		list = filledList(3);
		System.out.println("Return Expected: 1");
		System.out.print("Return Got: ");
		System.out.println(list.deleteAt(1));
		System.out.println("List Expected: 0, 2");
		System.out.print("List Got: ");
		list.printFwd();
		System.out.println("");

	}

	static void testPrintFwd() {

		System.out.println("-----Test printFwd()-----");
		SLList list = filledList(5);
		System.out.println("Expected: 01234");
		System.out.print("Got: ");
		list.printFwd();
		System.out.println("");
	}

	static void testPrintRev() {

		System.out.println("-----Test printRev()-----");
		SLList list = filledList(5);
		System.out.println("Expected: 43210");
		System.out.print("Got: ");
		list.printRev();
		System.out.println("");

	}

}
