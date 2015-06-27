#include "linkedList.h"
/*
Consider a AppendNode() function which is like Push(), except it adds the new node at
the tail end of the list instead of the head. If the list is empty, it uses the reference pointer
to change the head pointer. Otherwise it uses a loop to locate the last node in the list. This
version does not use Push(). It builds the new node directly.
*/
void AppendNode(struct node** headRef, int num) {
    struct node* current = *headRef;
    struct node* newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = NULL;
    // special case for length 0
    if (current == NULL) {
        *headRef = newNode;
    }
    else {
        // Locate the last node
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void AppendNodeWithPush(struct node** headRef, int num) {
    struct node* current = *headRef;
    // special case for the empty list
    if (current == NULL) {
        Push(headRef, num);
    }
    else {
        // Locate the last node
        while (current->next != NULL) {
            current = current->next;
        }
        // Build the node after the last node
        Push(&(current->next), num);
    }
}
