/*
Linked List Implementation
@author: prakash.natarajan@outlook.com
*/

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

	public void setNext(LinkedListNode n) {
		next = n;
		if(n != null && n.prev != this) {
			n.setPrev(this);			
		}
	}
	public void setPrev(LinkedListNode p) {
		prev = p;
		if(p != null && p.next != this) {
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

	public static void main(String[] args) {
		LinkedListNode first = new LinkedListNode(10, null, null);
		LinkedListNode sec = new LinkedListNode(20, null, null);
		first.setNext(sec);
		System.out.println(first.printNode());
	}
}
