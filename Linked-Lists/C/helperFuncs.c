#include "linkedList.h"

/*
Takes a list and a data value.
Creates a new link with the given data and pushes
it onto the front of the list.
The list is not passed in by its head pointer.
Instead the list is passed in as a "reference" pointer
to the head pointer -- this allows us
to modify the caller's memory.
*/
void Push(struct node** headRef, int data) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *headRef;
    // The '*' to dereferences back to the real head
    *headRef = newNode;
    // ditto
}
/*
Given a linked list head pointer, compute
and return the number of nodes in the list.
*/
int Length(struct node* head) {
    struct node* current = head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
    // can also be iterated as,
    // for (current = head; current != NULL; current = current->next) { }
}
/*
Build the list {1, 2, 3} in the heap and store
its head pointer in a local stack variable.
Returns the head pointer to the caller.
*/
struct node* BuildOneTwoThree() {
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;
    head = malloc(sizeof(struct node));
    // allocate 3 nodes in the heap
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));
    head->data = 1;
    // setup first node
    head->next = second;
    // note: pointer assignment rule
    second->data = 2;
    // setup second node
    second->next = third;
    third->data = 3;
    // setup third link
    third->next = NULL;
    // At this point, the linked list referenced by "head"
    // matches the list in the drawing.
    return head;
}
/*
Build the list {2, 3} in the heap and store
its head pointer in a local stack variable.
Returns the head pointer to the caller.
*/
struct node* BuildTwoThree() {
    struct node* head = NULL;
    struct node* second = NULL;
    head = malloc(sizeof(struct node));
    // allocate 2 nodes in the heap
    second = malloc(sizeof(struct node));
    head->data = 2;
    // setup first node
    head->next = second;
    // note: pointer assignment rule
    second->data = 3;
    // setup second link
    second->next = NULL;
    // At this point, the linked list referenced by "head"
    // matches the list in the drawing.
    return head;
}



struct node* AddAtHead() {
    struct node* head = NULL;
    int i;
    for (i=1; i<6; i++) {
        Push(&head, i);
    }
    // head == {5, 4, 3, 2, 1};
    return(head);
}
void printLinkedList(struct node* head) {
    struct node* current = head;
    printf("\n");
    while (current != NULL) {
        printf( "(%d) -> ", current->data );
        current = current->next;
    }
    printf("NULL\n");
}

bool testEquality(int arr[], int arrLen, struct node* head) {
    if( arrLen != Length(head)) {
        return false;
    }
    struct node* current = head;
    for (int i=0; i<arrLen ; ++i) {
        if ( arr[i] != current->data ) {
            return false;
        }
        current = current->next;
    }
    if ( current != NULL ) {
        return false;
    }
    return true;
}
