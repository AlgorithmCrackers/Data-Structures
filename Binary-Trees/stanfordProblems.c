#include "binaryTree.h"

struct node* build123(){
    struct node* root = NULL;
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);
    return(root);
}

struct node* buildN(int n){
    struct node* root = NULL;
    for (int i=1; i<=n ; i++ ) {
        insert(root, i);
    }
    return(root);
}

/*
 Compute the number of nodes in a tree.
*/
int size(struct node* node) {
    if( node == NULL ) {
        return 0;
    }
    return size(node->left) + 1 + size(node->right);
}

/*
 Compute the "maxDepth" of a tree -- the number of nodes along
 the longest path from the root node down to the farthest leaf node.
*/
int maxDepth(struct node* node) {
    if( node == NULL ) {
        return 0;
    }
    int lDepth = maxDepth(node->left);
    int rDepth = maxDepth(node->right);

    if ( lDepth > rDepth) return (lDepth+1);
    else return (rDepth+1);
}

/*
 Given a non-empty binary search tree,
 return the minimum data value found in that tree.
 Note that the entire tree does not need to be searched.
*/
int minValue(struct node* node) {
    struct node* current = node;
    // loop down to find the leftmost leaf
    while (current->left != NULL) {
        current = current->left;
    }
    return(current->data);
}

/*
 Given a non-empty binary search tree,
 return the maximum data value found in that tree.
 Note that the entire tree does not need to be searched.
*/
int maxValue(struct node* node) {
    struct node* current = node;
    // loop down to find the leftmost leaf
    while (current->right != NULL) {
        current = current->right;
    }
    return(current->data);
}

/*
 Given a binary search tree, print out
 its data elements in increasing
 sorted order.
 This is known as an "inorder" traversal of the tree.
*/
void printTree(struct node* node) {
    if (node == NULL) return;
    printTree(node->left);
    printf("%d ", node->data);
    printTree(node->right);
}

/*
 Given a binary tree, print its nodes according to the "bottom-up" postorder
 traversal.
-- both subtrees of a node are printed out completely before the node itself
 is printed, and each left subtree is printed before the right subtree.
*/
void printPostorder(struct node* node) {
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

/*
 Given a binary tree and a sum, return true if the tree has a root-to-leaf
 path such that adding up all the values along the path equals the given sum.
 Return false if no such path can be found.

 Strategy: subtract the node value from the sum when recurring down,
 and check to see if the sum is 0 when you run out of tree.
*/
int hasPathSum(struct node* node, int sum) {
    if (node == NULL) return sum == 0;
    else {
        return hasPathSum(node->left, sum - node->data)
               || hasPathSum(node->right, sum - node->data);
    }
}

// Utility that prints out an array on a line.
void printArray(int ints[], int len) {
  int i;
  for (i=0; i<len; i++)
    printf("%d ", ints[i]);
    printf("\n");
}

/*
 Recursive helper function -- given a node, and an array containing
 the path from the root node up to but not including this node,
 print out all the root-leaf paths.
*/
void printPathsRecur(struct node* node, int path[], int pathLen) {
    if (node==NULL) return;
    // append this node to the path array
    path[pathLen] = node->data;
    pathLen++;
    // it's a leaf, so print the path that led to here
    if (node->left==NULL && node->right==NULL) {
        printArray(path, pathLen);
    }
    else {
    // otherwise try both subtrees
        printPathsRecur(node->left, path, pathLen);
        printPathsRecur(node->right, path, pathLen);
    }
}
/*
Given a binary tree, print out all of its root-to-leaf
paths, one per line. Uses a recursive helper to do the work.
*/
void printPaths(struct node* node) {
  int path[1000];
  printPathsRecur(node, path, 0);
}



/*
Change a tree so that the roles of the left and right pointers are swapped
at every node.
*/
void mirror(struct node* node) {
    if (node==NULL) return;

    // do for sub-trees first
    mirror(node->left);
    mirror(node->right);

    // swap the pointers
    struct node* prevRight = node->right;
    node->right = node->left;
    node->left = prevRight;

}

/*
For each node in a binary search tree, create a new duplicate node,
and insert the duplicate as the left child of the original node.
*/
void doubleTree(struct node* node) {
    if (node==NULL) return;

    // do for sub-trees first
    doubleTree(node->left);
    doubleTree(node->right);

    // duplicate the root
    struct node* prevLeft = node->left;
    node->left = NewNode(node->data);
    node->left->left = prevLeft;
}

/*
Given two binary trees, return true if they are structurally
identical -- they are made of nodes with the same values
arranged in the same way.
 */
int sameTree(struct node* a, struct node* b) {
    if( a == NULL && b == NULL) // both empty
        return true;
    else if( a != NULL && b != NULL ) // both non-empty, so compare
        return( (a->data == b->data) &&
                sameTree(a->left, b->left) &&
                sameTree(a->right, b->right) );
    else
        return false;

}

/*
 For the key values 1...numKeys, how many structurally unique
 binary search trees are possible that store those keys.

 Strategy: consider that each value could be the root.
 Recursively find the size of the left and right subtrees.
*/
int countTrees(int numKeys) {

  if (numKeys <=1) {
    return(1);
  }
  else {
    // there will be one value at the root, with whatever remains
    // on the left and right each forming their own subtrees.
    // Iterate through all the values that could be the root...
    int sum = 0;
    int left, right, root;

    for (root=1; root<=numKeys; root++) {
      left = countTrees(root - 1);
      right = countTrees(numKeys - root);

      // number of possible trees with this root == left*right
      sum += left*right;
    }

    return(sum);
  }
}

int isBST(struct node* node) {
  if (node==NULL) return(true);

  // false if the max of the left is > than us

  // (bug -- an earlier version had min/max backwards here)
  if (node->left!=NULL && maxValue(node->left) > node->data)
    return(false);

  // false if the min of the right is <= than us
  if (node->right!=NULL && minValue(node->right) <= node->data)
    return(false);

  // false if, recursively, the left or right is not a BST
  if (!isBST(node->left) || !isBST(node->right))
    return(false);

  // passing all
    return true;
}

/*
 Returns true if the given tree is a BST and its
 values are >= min and <= max.
*/
int isBSTRecur(struct node* node, int min, int max) {
    if (node==NULL) return(true);
    if (min > node->data)
        return(false);
    // false if the min of the right is <= than us
    if (max <= node->data)
        return(false);

  // false if, recursively, the left or right is not a BST
    return (isBSTRecur(node->left, min, node->data) &&
        isBSTRecur(node->right, node->data+1, max)); // note the +1
}
/*
Returns true if the given tree is a binary search tree
(efficient version).
*/
int isBST2(struct node* node) {
  return(isBSTRecur(node, INT_MIN, INT_MAX));
}
