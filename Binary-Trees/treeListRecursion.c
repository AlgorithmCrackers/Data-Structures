/*
 TreeList.c
 
 C code version of the great Tree-List recursion problem.
 See http://cslibrary.stanford.edu/109/ for the full
 discussion and the Java solution.
 
 This code is free for any purpose.
 Feb 22, 2000
 Nick Parlante nick.parlante@cs.stanford.edu
*/


#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/* The node type from which both the tree and list are built */
struct node {
    int data;
    struct node* small;
    struct node* large;
};
typedef struct node* Node;


/*
 helper function -- given two list nodes, join them
 together so the second immediately follow the first.
 Sets the .next of the first and the .previous of the second.
*/
static void join(Node a, Node b) {
    a->large = b; // the "large" pointer should play the role of "next". 
    b->small = a; // The "small" pointer should play the role of "previous"
}


/*
 helper function -- given two circular doubly linked
 lists, append them and return the new list.
*/
static Node append(Node a, Node b) {
    Node aLast, bLast;
        
    if (a==NULL) return(b);
    if (b==NULL) return(a);
    
    // the previous of first element is the pointer to last node
    aLast = a->small; 
    bLast = b->small;
    
    join(aLast, b);
    join(bLast, a);
    
    return(a);
}


/*
 --Recursion--
 Given an ordered binary tree, recursively change it into
 a circular doubly linked list which is returned.
*/
static Node treeToList(Node root) {
    Node aList, bList;
        
    if (root==NULL) return(NULL);

    /* recursively solve subtrees -- leap of faith! */
    aList = treeToList(root->small);
    bList = treeToList(root->large);
        
    /* Make a length-1 list out of the root */ 
    // the root must point to itself
    root->small = root;
    root->large = root;

    /* Append everything together in sorted order */
    aList = append(aList, root);
    aList = append(aList, bList);
        
    return(aList);



/* Create a new node */
static Node newNode(int data) {
    Node node = (Node) malloc(sizeof(struct node));
    node->data = data;
    node->small = NULL;
    node->large = NULL;
    return(node);
}


/* Add a new node into a tree */
static void treeInsert(Node* rootRef, int data) {
    Node root = *rootRef;
    if (root == NULL) *rootRef = newNode(data);
    else {
        if (data <= root->data) treeInsert(&(root->small), data);
        else treeInsert(&(root->large), data);
    }
}


static void printList(Node head) {
    Node current = head;
    
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->large;
        if (current == head) break;
    }
    printf("\n");
}


/* Demo that the code works */
int main() {
    Node root = NULL;
    Node head;
    
    treeInsert(&root, 4);
    treeInsert(&root, 2);
    treeInsert(&root, 1);
    treeInsert(&root, 3);
    treeInsert(&root, 5);
    
    head = treeToList(root);
    
    printList(head);    /* prints: 1 2 3 4 5  */
    
    return(0);
}