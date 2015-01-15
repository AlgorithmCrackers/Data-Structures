#include "linkedList.h"
/*
Consider a CopyList() function that takes a list and returns a complete copy of that list.
One pointer can iterate over the original list in the usual way. Two other pointers can
keep track of the new list: one head pointer, and one tail pointer which always points to
the last node in the new list. The first node is done as a special case, and then the tail
pointer is used in the standard way for the others...
*/
struct node* CopyList(struct node* head) {
    struct node* current = head;
    // used to iterate over the original list
    struct node* newList = NULL;
    // head of the new list
    struct node* tail = NULL;
    // kept pointing to the last node in the new list
    while (current != NULL) {
        if (newList == NULL) {
            // special case for the first new node
            newList = malloc(sizeof(struct node));
            newList->data = current->data;
            newList->next = NULL;
            tail = newList;
        }
        else {
            tail->next = malloc(sizeof(struct node));
            tail = tail->next;
            tail->data = current->data;
            tail->next = NULL;
        }
        current = current->next;
    }
    return(newList);
}

// Variant of CopyList() that uses Push()
struct node* CopyListWithPush(struct node* head) {
    struct node* current = head;
    // used to iterate over the original list
    struct node* newList = NULL;
    // head of the new list
    struct node* tail = NULL;
    // kept pointing to the last node in the new list
    while (current != NULL) {
        if (newList == NULL) {
            // special case for the first new node
            Push(&newList, current->data);
            tail = newList;
        }
        else {
            Push(&(tail->next), current->data);
            // add each node at the tail
            tail = tail->next;
            // advance the tail to the new last node
        }
        current = current->next;
    }
    return(newList);
}
struct node* CopyListWithDummy(struct node* head) {
    struct node* current = head;
    // used to iterate over the original list
    struct node* tail;
    // kept pointing to the last node in the new list
    struct node dummy;
    // build the new list off this dummy node
    dummy.next = NULL;
    tail = &dummy;
    // start the tail pointing at the dummy
    while (current != NULL) {
        Push(&(tail->next), current->data);
        // add each node at the tail
        tail = tail->next;
        // advance the tail to the new last node
        current = current->next;
    }
    return(dummy.next);
}
/* 
The final, and most unusual version uses the "local references" strategy instead of a tail
pointer. The strategy is to keep a lastPtr that points to the last pointer in the list. All
node additions are done at the lastPtr, and it always points to the last pointer in the
list. When the list is empty, it points to the head pointer itself. Later it points to the
.next pointer inside the last node in the list
*/
struct node* CopyListWithLocalRef(struct node* head) {
    struct node* current = head;
    // used to iterate over the original list
    struct node* newList = NULL;
    struct node** lastPtr;
    lastPtr = &newList;
    // start off pointing to the head itself
    while (current != NULL) {
        Push(lastPtr, current->data);
        // add each node at the lastPtr
        lastPtr = &((*lastPtr)->next);
        // advance lastPtr
        current = current->next;
    }
    return(newList);
}
/* 
Here is the recursive version of CopyList(). It has the pleasing
shortness that recursive code often has. However, it is probably not good for production
code since it uses stack space proportional to the length of its list.
*/
struct node* CopyListRecursive(struct node* current) {
    if (current == NULL) return NULL;
    else {
        struct node* newList = malloc(sizeof(struct node));
        // make the one node
        newList->data = current->data;
        newList->next = CopyList(current->next);
        // recur for the rest
        return(newList);
    }
}