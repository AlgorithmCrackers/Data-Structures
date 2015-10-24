package heap;

public class MinHeap {
	int[] arr;
	int N;

	public MinHeap(int capacity) {
		arr = new int[capacity + 1];
		N = 0;
	}
	
	public void insert(int value) {
		arr[++N] = value;
		swim(N);
	}
	
	public int deleteMin() {
		swap(N, 1, arr);
		int max = arr[N];
		arr[N] = Integer.MAX_VALUE;
		N--;
		sink(1);
		return max;
	}
	
	public boolean isEmpty() {
		return N == 0;
	}
	
	/*
	 * swim max to top
	 */
	private void swim(int index) {
		while(arr[index] < arr[index/2] && index != 0 && index/2 != 0) {
			swap(index, index/2, arr);
			index = index/2;
		}
	}
	
	/*
	 * Sink the element from top to bottom
	 */
	private void sink(int index) {
		while(index < N) {
			int childIndex = 2 * index;
			int minChildIndex = (arr[childIndex] < arr[childIndex + 1])?childIndex :(childIndex + 1);
			if(arr[index] < arr[minChildIndex]) {
				break;
			}
			//System.out.println("max child index :" + maxChildIndex);
			swap(index, minChildIndex, arr);
			index = minChildIndex;
		}
	}
	
	/*
	 * swaps entries between two index in arr
	 */
	private void swap(int index1, int index2, int[] arr) {
		int temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}
	
	/*
	 * diplays elements of queue
	 */
	public void display() {
		for(int i = 1; i <= N; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}
	
	public static void main(String[] args) {
		MinHeap h = new MinHeap(20);
		h.insert(5);
		h.display();
		h.insert(3);
		h.display();
		h.insert(2);
		h.display();
		h.insert(1);
		h.display();
		h.insert(10);
		h.display();
		System.out.println("first smallest element is " + h.deleteMin());
		h.display();
		System.out.println("second smallest element is " + h.deleteMin());
		h.display();
		System.out.println("third smallest element is " + h.deleteMin());
		
//		int[] arr = {1, 23, 12, 9, 30, 2, 50}; 
//		for(int i = 0; i < arr.length; i++) {
//			h.insert(arr[i]);
//		}
//		System.out.println("first smallest element is " + h.deleteMin());
//		System.out.println("second smallest element is " + h.deleteMin());
//		System.out.println("third smallest element is " + h.deleteMin());
	}

}
