#include "binaryTree.h"
/*
 Given a binary tree, return true if a node
 with the target data is found in the tree. Recurs
 down the tree, chooses the left or right
 branch by comparing the target to each node.
*/
int lookup(struct node* node, int target) {
	// 1. Base case == empty tree
	// in that case, the target is not found so return false
	if (node == NULL) {
		return(false);
	}
	else {
		if (target == node->data) return(true);
		else {
			// 3. otherwise recur down the correct subtree
			if (target < node->data) return(lookup(node->left, target));
			else return(lookup(node->right, target));
		}
	}
}
/*
	Same function but implemented in a non recurive fashion.
	" Searching a tree without recursion is even simpler than with recursion,
		removes the problem of stack overflow, and has a tendency to execute faster
		 and with less memory use "
*/
int lookup_nonRecursive(struct node* node, int target) {
	struct node* it = node;
	while (it != NULL) {
		if (it->data == target) return(true);
		else {
			if (target < node->data) it = it->left;
			else it = it->right;
		}
	}
	return(false);
}
/*
 Helper function that allocates a new node
 with the given data and NULL left and right
 pointers.
*/
struct node* NewNode(int data) {
	struct node* node = malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}
/*
 Give a binary search tree and a number, inserts a new node
 with the given number in the correct place in the tree.
 Returns the new root pointer which the caller should
 then use (the standard trick to avoid using reference
 parameters).
*/
struct node* insert(struct node* node, int data) {
	// 1. If the tree is empty, return a new, single node
	if (node == NULL) {
		return(NewNode(data));
	}
	else {
		// 2. Otherwise, recur down the tree
		if (data <= node->data)
			node->left = insert(node->left, data);
		else
			node->right = insert(node->right, data);
	}
	return(node); // return the (unchanged) node pointer
}
/*
	" insertion needs to be careful not to actually get to a leaf.
	 Because a leaf is a null pointer, there's no way to determine which node in
	the tree we came from and it's impossible to link the new node into the tree.
	 That defeats the purpose of insertion since we can't make the change stick.
	So the loop tests the next link before going to it, and if it's a leaf,
	we break out of the loop and tack a new node onto that link. "
*/
struct node* insert_nonRecursive(struct node* node, int data) {
	// 1. If the tree is empty, return a new, single node
	if (node == NULL) return(NewNode(data));
	else {
		// 2. Otherwise, recur down the tree
		struct node* it = node;
		int dir;
		for ( ; ; ) {
			dir = it->data < data;
    	if ( it->data == data ) return (node); // duplicate case
			else if ( dir ) {
				if (it->left == NULL) break;
				else it = it->left;
			}
    	else {
				if (it->right == NULL) break;
				else it=it->right;
			}
  	}
		if ( dir ) it->left = NewNode(data);
		else it->right = NewNode(data);
	}
	return(node); // return the (unchanged) node pointer
}
/* Given a non-empty binary search tree, return the node with minimum
key value found in that tree. Note that the entire tree does not
need to be searched. */
struct node * minValueNode(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}
/*
	http://geeksquiz.com/binary-search-tree-set-2-delete/
	Delete a node in a BST.
	Three cases,
		* The node has no child(leaf) <== easy
		* The node has one child <== easy
		* The node has two children <== tricky
*/
struct node* deleteNode(struct node* node, int key) {
	// base case (also for cant find the key!)
	if (node == NULL) return(node);

	// left subtree
	if (key < node->data)
		node->left = deleteNode(node->left, key);
	// right subtree
	else if (key > node->data)
		node->right = deleteNode(node->right, key);
	//found the node to be deleted
	else {
		// node with only one child
		// or no child
		if (node->left == NULL) {
			struct node *temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL)
		{
			struct node *temp = node->left;
			free(node);
			return temp;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		// inorder prdecessor can also be used (greatest in right subtree)
		struct node* temp = minValueNode(node->right);

		// Copy the inorder successor's content to this node
		node->data = temp->data;

		// Delete the inorder successor // you just cant free, it may have a right child!
		node->right = deleteNode(node->right, temp->data);

		/* Why does this work?
		The inorder predecessor of a node never has a right child, and the inorder
		successor never has a left child. So we can be sure that the successor
		always has at most one child, and the left child is a leaf.
		*/
	}
	return node;
}
/*  This function traverses tree in post order to
to delete each and every node of the tree */
void _deleteTree(struct node* node)
{
	if (node == NULL) return;

	/* first delete both subtrees */
	_deleteTree(node->left);
	_deleteTree(node->right);

	/* then delete the node */
	printf("\n Deleting node: %d", node->data);
	free(node);
}
/* Deletes a tree and sets the root as NULL */
void deleteTree(struct node** node_ref)
{
	_deleteTree(*node_ref);
	*node_ref = NULL;
}
/*
we delete a node when there's no left link and do a right rotation
when there is, we can be sure that we'll see and delete every node in the tree.
see http://imgur.com/a/U2sA4
*/
void deleteTree_nonRecursive ( struct node* tree ) {
	struct node* it = tree;
	struct node* save;
	while ( it != NULL ) {
		if ( it->left != NULL ) {
	   	/* Right rotation */
	   	save = it->left;
	    it->left = save->right;
	    save->right = it;
	  }
	  	else {
       save = it->right;
       free ( it );
     }
     it = save;
   }
}
