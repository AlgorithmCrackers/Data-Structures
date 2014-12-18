/*
Linked List Implementation
@author: prakash.natarajan@outlook.com
*/
class Node {
	int data;
	Node next;
	Node prev;
}
class LinkedList {
	Node head;
	Node tail;

	boolean insertFront(int newData) {
		Node newNode = new Node();
		newNode.data = newData;

		if(head == null ) {
			head = newNode;
			tail = head;
			return true;
		}
		else {
			Node oldHead = head;
			head = newNode;
			head.next = oldHead;
			oldHead.prev = head;
			return true;
		}
	}

	boolean insertTail(int newData) {
		Node newNode = new Node();
		newNode.data = newData;
		if(head == null ) {
			head = newNode;
			tail = head;
			return true;
		}
		else {
			//Node oldTail = tail;
			newNode.prev =  tail;
			tail.next = newNode;
			tail = newNode;
			return true;
		}
	}
	int delete(int data) {
		return 0;
	}
	void printList(){
		Node cur = head;
		while(cur != null) {
			System.out.println(cur.data);
			cur = cur.next;
		}
	}
	public static void main(String[] args) {
		LinkedList ll = new LinkedList();
		ll.insertFront(30);
		ll.insertFront(20);
		ll.insertFront(10);
		ll.printList();
	}
}
