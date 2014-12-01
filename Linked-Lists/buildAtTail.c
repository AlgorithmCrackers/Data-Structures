#include "linkedList.h"
//  building up the list {1, 2, 3, 4, 5} by appending the nodes to the tail end.

/* 
The difficulty is that the very first node must be added at the head pointer, but all
the other nodes are inserted after the last node using a tail pointer. The simplest way to
deal with both cases is to just have two separate cases in the code. Special case code first
adds the head node {1}. Then there is a separate loop that uses a tail pointer to add all the
other nodes. The tail pointer is kept pointing at the last node, and each new node is added
at tail->next. The only "problem" with this solution is that writing separate special
case code for the first node is a little unsatisfying. Nonetheless, this approach is a solid
one for production code — it is simple and runs fast
*/
struct node* BuildWithSpecialCase() {
    struct node* head = NULL;
    struct node* tail;
    int i;
    // Deal with the head node here, and set the tail pointer
    Push(&head, 1);
    tail = head;
    // Do all the other nodes using 'tail'
    for (i=2; i<6; i++) {
        Push(&(tail->next), i);
        // add node at tail->next
        tail = tail->next;
        // advance tail to point to last node
    }
    return(head);
    // head == {1, 2, 3, 4, 5};
}
/* 
Another solution is to use a temporary dummy node at the head of the list during the
computation. The trick is that with the dummy, every node appear to be added after the .next
field of a node. That way the code for the first node is the same as for the other
nodes. The tail pointer plays the same role as in the previous example. The difference is
that it now also handles the first node.
*/
struct node* BuildWithDummyNode(int n) {
    struct node dummy;
    // Dummy node is temporarily the first node
    struct node* tail = &dummy; // Start the tail at the dummy.
    // Build the list on dummy.next (aka tail->next)
    int i;
    dummy.next = NULL;
    for (i=1; i<(n+1); i++) {
        Push(&(tail->next), i);
        tail = tail->next;
    }
    // The real result list is now in dummy.next
    // dummy.next == {1, 2, 3, 4};
    return(dummy.next);
}
/*
Finally, here is a tricky way to unifying all the node cases without using a dummy node.
The trick is to use a local "reference pointer" which always points to the last
pointer in the list instead of to the last node. All additions to the list are made by following the
reference pointer. The reference pointer starts off pointing to the head pointer. Later, it
points to the .next field inside the last node in the list
*/
struct node* BuildWithLocalRef() {
    struct node* head = NULL;
    struct node** lastPtrRef= &head;
    // Start out pointing to the head pointer
    int i;
    for (i=1; i<6; i++) {
        Push(lastPtrRef, i);
        // Add node at the last pointer in the list
        lastPtrRef= &((*lastPtrRef)->next);
        // Advance to point to the
        // new last pointer
    }
    // head == {1, 2, 3, 4, 5};
    return(head);
}

struct node* buildThisArrayAsList(int arr[], int arrLen) {
    struct node dummy;
    // Dummy node is temporarily the first node
    struct node* tail = &dummy; // Start the tail at the dummy.
    // Build the list on dummy.next (aka tail->next)
    int i;
    dummy.next = NULL;
    for (i=0; i< arrLen; i++) {
        Push(&(tail->next), arr[i]);
        tail = tail->next;
    }
    // The real result list is now in dummy.next
    return(dummy.next);
}
