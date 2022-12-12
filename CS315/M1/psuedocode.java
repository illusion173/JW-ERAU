//Singly linked list
public void addUnique(int val){
	// So first we need to find the length of this linked list
	// Cycle!
	num_nodes = 0;
	dummyNode = head;
	while(head != Null){
			num_nodes += 1;
			head = head.next;
		}

	// Reassign head from dummyNode
	head = dummyNode

	int[] num_array = new int[num_nodes]
	// Now we fill array for items
	for(i=0;i<num_nodes;i++){
		num_array[i] = head.val;
		head = head.next;
	}
	// Dont do anything, just return head
	if(num_array.contains(val)){
		return;
	}
	else{
		// Reassign head 
		head = dummyNode
			// Stop at last Node
			for(i=0;i<num_nodes;i++){
				head = head.next;
			}
		head.next = newNode(val, Null);
	}	

}

//Doubly linked list add unique item
public void addUnique(int val){
	
	Node dummyNode = head
	int length_of_list = 0

	if(head == Null){
		Node newnode = NewNode(val, Null, Null);
		// Base case if head doesn't exist yet.
	}
	while(head != Null){
		head = head.next
		length_of_list += 1;

	}
	
	head = dummyNode; // ensure head starts at beginning
	// Technically we should do a hashset but an array will be fine for this
	// We could even do an arraylist
	int[] num_array = new int[length_of_list];				  

	// Now we fill in with node data
	for(i=0;i<length_of_list;i++){
		num_array[i] = head.val;
		head = head.next;
	}
	// Convert the array to a list, Technically the array doesn't have a .contains method, but the list does.
	List<int> num_list = Arrays.asList(num_array);
	//If value exists, dont add
	if(num_list.contains(val)){
		return;
	}
	else{
		// We need to create a node that has new value, and takes in pointer arguments
		Node newNode = new Node(val, tail, Null);
		// I am assuming there is a node class that takes in a value, prev pointer, next pointer
		tail.next = newNode;
		// We dont need to change the tails previous node just the next node pointer.
		
	}

}
