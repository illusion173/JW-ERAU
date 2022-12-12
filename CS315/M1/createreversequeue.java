public  Queue createReverseQueue(Queue q)
{
//Use these variables to implement the reverse
Stack s = new Stack();
Queue newQ = new Queue();

//Implement the reverse code here
// Input all items in q into a stack.
	while(!q.isEmpty()){
		s.push(q.dequeue())
	}

	

	while(!s.isEmpty()){
		newQ.enqueue(s.pop())
	}


return newQ; //return value resulting from reverse
}
