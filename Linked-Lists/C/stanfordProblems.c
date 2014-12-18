#include "linkedList.h"

/*
http://cslibrary.stanford.edu/105/
*/

/*
Given a list and an int, return the number of times that int occurs
in the list.
*/
int Count(struct node* head, int searchFor) { 
    struct node* current;
    int count = 0;
    for (current = head; current != NULL; current = current->next) { 
        if( current->data == searchFor) {
            count++;
        }
    }
    return count;
}

// Given a list and an index, return the data
// in the nth node of the list. The nodes are numbered from 0.
// Assert fails if the index is invalid (outside 0..lengh-1).
int GetNth(struct node* head, int index) {
    assert( ( index >= 0 ) && ( index < Length(head) ) );
    struct node* current;
    int currentIndex = 0;
    for (current = head; current != NULL; current = current->next) { 
        if ( currentIndex == index ) {
            return current->data;
        }
        currentIndex++;
    }
    return -1;
}
// function DeleteList() that takes a list, deallocates all of its memory and sets its head pointer to NULL (the empty list)
//Essentially DeleteList() just needs to call free() once for each node and set the head pointer to NULL
void DeleteList(struct node** headRef) {
    struct node* current = *headRef;
    // deref headRef to get the real head
    struct node* next;
    while (current != NULL) {
        next = current->next;
        // note the next pointer
        free(current);
        // delete the node
        current = next;
        // advance to the next node
    }
    *headRef = NULL;
    // Again, deref headRef to affect the real head back
    // in the caller.
}
/*
Pop() function is the inverse of Push(). Pop() takes a non-empty list, deletes
the head node, and returns the head node's data. If all you ever used were Push() and
Pop(), then our linked list would really look like a stack. However, we provide more
general functions like GetNth() which what make our linked list more than just a stack.
Pop() should assert() fail if there is not a node to pop. H
*/
int Pop(struct node** headRef){
    struct node* head = *headRef;
    assert( head != NULL );
    *headRef = head->next;
    int data = head->data;
    free(head);
    return data;
}

/*
A more general version of Push().
Given a list, an index 'n' in the range 0..length,
and a data element, add a new node to the list so
that it has the given index.
*/
void InsertNth(struct node** headRef, int index, int data) {
    assert( ( index >= 0 ) && ( index <= Length(*headRef) ) );
    if (index == 0) {
        Push(headRef, data); // for position 0 insert node to an empty list
        return;
    }
    struct node* current  = *headRef;
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    for (int i = 0; i<index-1; i++) {
        current = current->next;
    }
    // insert the newNode on the current position
    newNode->next = current->next;
    current->next = newNode; 
}

void InsertNth_StanfordSolution(struct node** headRef, int index, int data) {
    // position 0 is a special case...
    if (index == 0) Push(headRef, data);
    else {
        struct node* current = *headRef;
        int i;
    for (i=0; i<index-1; i++) {
        assert(current != NULL);
        // if this fails, index was too big
        current = current->next;
    }
    assert(current != NULL);
    // tricky: you have to check one last time
    Push(&(current->next), data);
    // Tricky use of Push() --
    // The pointer being pushed on is not
    // in the stack. But actually this works
    // fine -- Push() works for any node pointer.
    }
}
/*
SortedInsert() function which given a list that is sorted in increasing order, and a
single node, inserts the node into the correct sorted position in the list. While Push()
allocates a new node to add to the list, SortedInsert() takes an existing node, and just
rearranges pointers to insert it into the list. There are many possible solutions to this
problem.
*/
// Dummy node strategy for the head end
void SortedInsert(struct node** headRef, struct node* newNode) {
    struct node dummy;
    struct node* current = &dummy;
    dummy.next = *headRef;
    while ( (current->next != NULL ) && ( current->next->data < newNode->data ) )  {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    *headRef = dummy.next;
}

//given a list, rearranges its nodes so they are sorted in increasing order
void InsertSort(struct node** headRef) {
    struct node* result = NULL; // build the answer here
    struct node* current = *headRef; // iterate over the original list
    struct node* next;
    while (current!=NULL) {
        next = current->next; // tricky - note the next pointer before we change it
        // Insert current into the sorted sequence list[1...i-1] - INSERTION SORT!
        SortedInsert(&result, current);
        current = next;
    }
    *headRef = result;
}

// Append 'b' onto the end of 'a', and then set 'b' to NULL.
void Append(struct node** aRef, struct node** bRef) { 
    // using dummy takes care of the special case when a is NULL
    struct node dummy;
    // Dummy node is temporarily the first node
    struct node* tail = &dummy; // Start the tail at the dummy.
    // Build the list on dummy.next (aka tail->next)
    dummy.next = *aRef;
    // traverse to the last node of [a]
    while ( tail->next != NULL) {
        tail = tail->next;
    }
    // now tail->next == NULL
    tail->next = *bRef;
    *aRef = dummy.next;    
    *bRef = NULL;
}

void Append_StanfordSoln(struct node** aRef, struct node** bRef) {
    struct node* current;
    if (*aRef == NULL) {
        // Special case if a is empty
        *aRef = *bRef;
    }
    else {
        // Otherwise, find the end of a, and append b there
        current = *aRef;
        while (current->next != NULL) {
            // find the last node
            current = current->next;
        }
        current->next = *bRef;
        // hang the b list off the last node
    }
    *bRef = NULL;
    // NULL the original b, since it has been appended above
}

/*
Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
If the length is odd, the extra node should go in the front list.
*/
void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef) { 
    int len = Length(source);
    if ( len <  2) {
        *frontRef = source;
        *backRef = NULL;
    }
    else {
        int mid = ( len + 2 - 1 ) / 2; // ceil( a/b ) http://stackoverflow.com/questions/2745074/fast-ceiling-of-an-integer-division-in-c-c
        // for ex: 3 elements on front [1, 2, 3]
        struct node* current = source;
        *frontRef = current; // front = [1,....]
        for ( int i = 1; i < mid; i++) { // for ex: 3 elements on front,  1->2, 2->3
            current = current->next; // [2, 3]           
        }
        struct node* next = current->next;
        *backRef = next;
        current->next = NULL; // front = [1,2,3->NULL]
    }

}

/*
Uses the fast/slow pointer strategy.
A "slow" pointer advances one nodes at a time, while the "fast" pointer goes two
nodes at a time. When the fast pointer reaches the end, the slow pointer will be about half way.
*/
void FrontBackSplit_StanfordSoln(struct node* source, struct node** frontRef, struct node** backRef) {
    struct node* fast;
    struct node* slow;
    if (source==NULL || source->next==NULL) {
        // length < 2 cases
        *frontRef = source;
        *backRef = NULL;
    }
    else {
        slow = source;
        fast = source->next;
        // Advance 'fast' two nodes, and advance 'slow' one node
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        // 'slow' is before the midpoint in the list, so split it in two
        // at that point.
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
}
/*
Remove duplicates from a sorted list.
*/
void RemoveDuplicates(struct node* head) {
    struct node dummy;
    struct node* current = head;
    struct node* prev = &dummy;
    prev->data = current->data + 1; // initialize the previous data to be non equal to the first element
    dummy.next = current;
    while (current != NULL) {
        if (prev->data == current->data) {
            prev->next = current->next;
            free(current);
            current = prev->next;
        }
        else {
            prev = current;
            current = prev->next;    
        }  
    } 
}

// Remove duplicates from a sorted list
void RemoveDuplicates_StanfordSoln(struct node* head) {
    struct node* current = head;
    if (current == NULL) return;
    // do nothing if the list is empty
    // Compare current node with next node
    while(current->next!=NULL) {
        if (current->data == current->next->data) {
            struct node* nextNext = current->next->next;
            free(current->next);
            current->next = nextNext;
        }
        else {
            current = current->next;
            // only advance if no deletion
        }
    }
}

/*
Take the node from the front of the source, and move it to
the front of the dest. It is an error to call this with the source list empty.
*/
void MoveNode(struct node** destRef, struct node** sourceRef) { 
    struct node* sourceFront = *sourceRef;
    assert ( sourceFront != NULL ); // source list should not be empty
    *sourceRef = sourceFront->next; // Advance the source pointer

    sourceFront->next = *destRef; // Link the old dest off to the old source front
    *destRef = sourceFront; // Move dest to point to the old source front
}

/*
Given the source list, split its nodes into two shorter lists.
If we number the elements 0, 1, 2, ... then all the even elements
should go in the first list, and all the odd elements in the second.
The elements in the new lists may be in any order.
*/
void AlternatingSplit(struct node* source, struct node** aRef, struct node** bRef) {
    struct node aDummy;
    struct node* aTail = &aDummy;
    // points to the last node in 'a'
    struct node bDummy;
    struct node* bTail = &bDummy;
    // points to the last node in 'b'
    struct node* current = source;
    aDummy.next = NULL;
    bDummy.next = NULL;
    while (current != NULL) {
        // move from front of current to a-tail
        MoveNode(&(aTail->next), &current); // add at 'a' tail
        aTail = aTail->next; // advance the 'a' tail
        if (current != NULL) {
            // move from front of current to b-tail
            MoveNode(&(bTail->next), &current);
            bTail = bTail->next;
        }
    }
    *aRef = aDummy.next;
    *bRef = bDummy.next;
}

/*
Merge the nodes of the two lists into a single list taking a node
alternately from each list, and return the new list.
*/
struct node* ShuffleMerge(struct node* a, struct node* b) {
    struct node dummy;
    struct node* newList = &dummy;
    dummy.next = NULL;

    while ( a != NULL && b != NULL ) {
        newList->next = a;
        newList = newList->next; // advance newList
        a = a->next;
        newList->next = b;
        newList = newList->next; // advance newList
        b = b->next;
    }

    if (a == NULL) { // add the rest of b
        newList->next = b;
    }
    else if (b == NULL) {
        newList->next = a;
    }

    return (dummy.next);
}

/*
Takes two lists sorted in increasing order, and
splices their nodes together to make one big
sorted list which is returned.
*/
struct node* SortedMerge(struct node* a, struct node* b) {
    struct node dummy;
    struct node* newList = &dummy;
    dummy.next = NULL;

    while ( a != NULL && b != NULL ) {
        if ( a->data < b->data) {
            newList->next = a;
            newList = newList->next; // advance newList
            a = a->next;
        }
        else {
            newList->next = b;
            newList = newList->next; // advance newList
            b = b->next;  
        }
    }

    if (a == NULL) { // add the rest of b
        newList->next = b;
    }
    else if (b == NULL) {
        newList->next = a;
    }

    return (dummy.next);
}

void MergeSort(struct node** headRef) {
    // Base case 
    if ( (*headRef == NULL) || ( (*headRef)->next == NULL ) ) {
        return;
    }
    struct node* left = NULL;
    struct node* right = NULL;
    FrontBackSplit( *headRef, &left, &right );
    MergeSort(&left);
    MergeSort(&right);
    *headRef = SortedMerge( left, right );
}

/*
Given two lists sorted in increasing order, create and return a new list representing the
intersection of the two lists. The new list should be made with its own memory — the
original lists should not be changed. In other words, this should be Push() list building,
not MoveNode(). Ideally, each list should only be traversed once. 

Compute a new sorted list that represents the intersection
of the two given sorted lists.
*/
struct node* SortedIntersect(struct node* a, struct node* b) {
    struct node dummy;
    struct node* newList = &dummy;
    dummy.next = NULL;
    while ( a != NULL && b != NULL ) {
        if ( a->data == b->data ) { // add to list only if it is equal
            Push( &(newList->next) , a->data );
            newList = newList->next; // if we skip this line we get a descending ordered list :P 
            a = a->next;
            b = b->next;
        }
        else if ( a->data < b->data) { // advance the smaller list
            a = a->next;
        }
        else { // b < a
            b = b->next;  
        }
    }
    return (dummy.next);
}

/*
Reverse the given linked list by changing its .next pointers and
its head pointer. Takes a pointer (reference) to the head pointer.
*/
void Reverse(struct node** headRef) {
    struct node* result = NULL;
    struct node* current = *headRef;
    struct node* next;
    while (current != NULL) {
        next = current->next; // tricky: note the next node

        current->next = result; // move the node onto the result
        result = current; // go to the head of resultList

        current = next;
    }
    *headRef = result;
}

/*
Recursively reverses the given linked list by changing its .next
pointers and its head pointer in one pass of the list.
*/
void RecursiveReverse(struct node** headRef) {
    struct node* first;
    struct node* rest;
    if (*headRef == NULL) return; // empty list base case

    first = *headRef; // suppose first = {1, 2, 3, 4}
    rest = first->next; // rest = {2, 3, 4}

    if (rest == NULL) return; // empty rest base case
    RecursiveReverse(&rest); // Recursively reverse the smaller {2, 3, 4} case
                             // after: rest = {4, 3, 2}

    first->next->next = first; 
    // put the first elem on the end of the list { first -> next = ( 2 ) now (2) -> next = 1 }
    // see http://www.geeksforgeeks.org/write-a-function-to-reverse-the-nodes-of-a-linked-lists/
    first->next = NULL; // (tricky step -- make a drawing)
    
    *headRef = rest; // fix the head pointer
}