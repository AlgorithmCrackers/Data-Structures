public class BinarySearchTree<T extends Comparable<T>> {
	T value;
	BinarySearchTree<T> left;
	BinarySearchTree<T> right;
	public BinarySearchTree(T v) {
		value = v;
		left = null;
		right = null;
	}
	
	/*
	 * insert into binary search Tree
	 * @params: datatype T which has to be inserted
	 * @returns: void 
	 */
	public void insert(T data) {
		if(value == data) {
			return;
		}
		if(data.compareTo(value) < 0) {
			// left side tree
			if(left == null) {
				//create a new Tree
				left = new BinarySearchTree<T>(data);
			} else {
				left.insert(data);
			}
		} else {
			if(right == null) {
				///create a new Tree
				right = new BinarySearchTree<T>(data);
			} else {
				right.insert(data);
			}
		}
	}
	
	/*
	 * Delete the data
	 * @params: data T which needs to be deleted
	 * @return: Boolean if element is found and deleted
	 */
	public Boolean delete(T data) {
		
		return null;
		
	}
	
	public static void main(String[] args) {
		BinarySearchTree<Integer> bst = new BinarySearchTree<Integer>(5);
		bst.insert(3);
		bst.insert(7);
		assert(bst.left.value == 3);
		assert(bst.right.value == 7);
		System.out.println("Success..");
		assert(true);
	}

}


