/*
Push() in C++ -- we just add a '&' to the right hand
side of the head parameter type, and the compiler makes
that parameter work by reference. So this code changes
the caller's memory, but no extra uses of '*' are necessary --
we just access "head" directly, and the compiler makes that
change reference back to the caller.
*/
void Push(struct node*& head, int data) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    // No extra use of * necessary on head -- the compiler
    head = newNode;
    // just takes care of it behind the scenes.
}
void PushTest() {
    struct node* head = BuildTwoThree();// suppose this returns the list {2, 3}
    Push(head, 1);
    // No extra use & necessary -- the compiler takes
    Push(head, 13);
    // care of it here too. Head is being changed by
    // these calls.
    // head is now the list {13, 1, 2, 3}
}
