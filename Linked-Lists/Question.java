package Question2_3;

import java.util.*;
// import CtCIDataStructurs.CtCIDataStructures.LinkedListNode;

public class Question {
	public Question() {}
	
	public static void main(String[] args) {
		LinkedListNode first = new LinkedListNode(1, null, null);
		LinkedListNode root = first;
		for(int i = 2; i < 10; i++) {
			LinkedListNode sec = new LinkedListNode(i, null, null);
			first.setNext(sec);
			sec.setPrev(first);
			first = sec;
		}
		System.out.println(root.printNode());
	}
}
class LinkedListNode {
	int data;
	LinkedListNode next;
	LinkedListNode prev;

	public LinkedListNode() {
	}

	public LinkedListNode(int d, LinkedListNode n, LinkedListNode p) {
		data = d;
		this.setNext(n);
		this.setPrev(p);
	}
	//sets the next node
	public void setNext(LinkedListNode n) {
		next = n;
		if(n != null && n.prev != this) {	//n.prev is checked in order stop adding the node recursively
			n.setPrev(this);			
		}
	}
	//sets the prev node
	public void setPrev(LinkedListNode p) {
		prev = p;
		if(p != null && p.next != this) { 	//p.next is to imply termination
			this.setNext(p);
		}
	}

	public String printNode() {
		if(next != null) {
			return data + ":" + next.printNode();
		}
		else
			return ((Integer) data).toString();
	}

	// public static void main(String[] args) {
	// 	LinkedListNode first = new LinkedListNode(10, null, null);
	// 	LinkedListNode sec = new LinkedListNode(20, null, null);
	// 	first.setNext(sec);
	// 	System.out.println(first.printNode());
	// }
}