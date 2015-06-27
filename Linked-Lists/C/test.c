#include "linkedList.h"

#define GREEN  "\x1B[32m"
#define RED  "\x1B[31m"
#define RESET "\033[0m"

void PushTest() {
    printf("Push..");
    struct node* head = BuildTwoThree();// suppose this returns the list {2, 3}
    Push(&head, 1);
    // note the &
    Push(&head, 13);
    // head is now the list {13, 1, 2, 3}
    int arr[] = {13, 1, 2, 3};
    int arrLen = sizeof(arr)/sizeof(arr[0]);
    if( testEquality(arr, arrLen, head) ) printf(GREEN "\tPASS\n" RESET);
    else printf(RED "\tFAIL\n" RESET);
}
void CountTest() {
    printf("Count..");
    struct node* myList = BuildOneTwoThree();
    // build {1, 2, 3}
    int count = Count(myList, 2);
    if( count == 1) printf(GREEN "\tPASS\n" RESET);
    // returns 1 since there's 1 '2' in the list
    else printf(RED "\tFAIL\n" RESET);
}
void GetNthTest() {
    printf("GetNth..");
    struct node* myList = BuildOneTwoThree();
    // build {1, 2, 3}
    int lastNode = GetNth(myList, 2);
    // returns the value 3
    if( lastNode == 3 ) printf(GREEN "\tPASS\n" RESET);
    else printf(RED "\tFAIL\n" RESET);
}

void DeleteListTest() {
    printf("DeleteList..");
    struct node* myList = BuildOneTwoThree();
    // build {1, 2, 3}
    DeleteList(&myList);
    if( myList == NULL ) printf(GREEN "\tPASS\n" RESET);
    else printf(RED "\tFAIL\n" RESET);
    // deletes the three nodes and sets myList to NULL
}
void PopTest() {
    printf("Pop..");
    struct node* head = BuildOneTwoThree();
    // build {1, 2, 3}
    int a = Pop(&head);
    // deletes "1" node and returns 1
    assert( a == 1 );
    int b = Pop(&head);
    assert( b == 2 );
    // deletes "2" node and returns 2
    int c = Pop(&head);
    assert( c == 3 );
    // deletes "3" node and returns 3
    int len = Length(head);
    if( len == 0 ) printf(GREEN "\tPASS\n" RESET);
    // the list is now empty, so len == 0
    else printf(RED "\tFAIL\n" RESET);
}
void InsertNthTest() {
    printf("InsertNth..");
    struct node* head = NULL;
    // start with the empty list
    InsertNth(&head, 0, 13);
    // build {13)
    InsertNth(&head, 1, 42);
    // build {13, 42}
    InsertNth(&head, 1, 5);
    // build {13, 5, 42}
    int arr[] = {13, 5, 42};
    int arrLen = sizeof(arr)/sizeof(arr[0]);
    if( testEquality(arr, arrLen, head) ) printf(GREEN "\tPASS\n" RESET);
    else printf(RED "\tFAIL\n" RESET);
    DeleteList(&head);
    // clean up after ourselves

}
void SortedInsertTest() {
    printf("SortedInsert..");
    struct node* head = BuildOneTwoThree();
    // build {1, 2, 3}
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = 2;
    newNode->next = NULL;
    SortedInsert( &head, newNode ); // {1, 2, 2, 3}
    int arr[] = {1, 2, 2, 3};
    int arrLen = sizeof(arr)/sizeof(arr[0]);
    if( ! testEquality(arr, arrLen, head) ) {
       printf(RED "\tFAIL\n" RESET);
       return;
     }
    struct node* newNode2 = malloc(sizeof(struct node));
    newNode2->data = 4;
    newNode2->next = NULL;
    SortedInsert( &head, newNode2 );
    int arrB[] = {1, 2, 2, 3, 4};
    int arrBLen = sizeof(arrB)/sizeof(arrB[0]);
    if( testEquality(arrB, arrBLen, head) ) printf(GREEN "\tPASS\n" RESET);
    else printf(RED "\tFAIL\n" RESET);
    DeleteList(&head);
    // clean up after ourselves
}

void InsertSortTest() {
    printf("InsertSort..");
    struct node* head = NULL;
    // start with the empty list
    InsertNth(&head, 0, 13);
    // build {13)
    InsertNth(&head, 1, 42);
    // build {13, 42}
    InsertNth(&head, 1, 5);
    // build {13, 5, 42}
    InsertSort(&head);
    int arrB[] = {5, 13, 42};
    int arrBLen = sizeof(arrB)/sizeof(arrB[0]);
    if( testEquality(arrB, arrBLen, head) ) printf(GREEN "\tPASS\n" RESET);
    else printf(RED "\tFAIL\n" RESET);
    DeleteList(&head);
    // clean up after ourselves
}
void AppendTest() {
    printf("AppendTest..");
    struct node* a = BuildOneTwoThree(); // {1, 2, 3}
    struct node* b = BuildWithDummyNode(5); // {1, 2, 3, 4, 5}
    Append(&a, &b);
    int arr[] =  {1, 2, 3, 1, 2, 3, 4, 5};
    int arrLen = sizeof(arr)/sizeof(arr[0]);
    if( testEquality(arr, arrLen, a) ) printf(GREEN "\tPASS\n" RESET);
    else printf(RED "\tFAIL\n" RESET);
    DeleteList(&a);
    // clean up after ourselves
}
void FrontBackSplitTest() {
    printf("FrontBackSplit..");
    bool testResult = false;
    for ( int testLength = 0; testLength <= 4;  testLength++) { // from len 1...4 described in the pdf
        struct node* source = BuildWithDummyNode(testLength);
        struct node* front = NULL;
        struct node* back = NULL;
        FrontBackSplit( source, &front, &back);
        int mid = ( testLength + 2 - 1 ) / 2;  // ceil integer division
        int arrFront[mid];
        for (int i=0; i < mid; i++) {
            arrFront[i] = 1+i;
        }
        if ( testEquality(arrFront, mid, front) ) testResult = true;
        else testResult = false;

        int arrBack[testLength-mid];
        for (int j=0; j < (testLength-mid); j++) {
            arrBack[j] = (mid+j+1);
        }
        if ( testEquality(arrBack, (testLength-mid), back) ) testResult = true;
        else testResult = false;
        DeleteList(&front);
        DeleteList(&back);
    }
    if( testResult ) printf(GREEN "\tPASS\n" RESET);
    else printf(RED "\tFAIL\n" RESET);
}
void RemoveDuplicatesTest() {
    printf("RemoveDuplicates..");
    struct node* head = BuildWithDummyNode(5); // {1, 2, 3, 4, 5}
    Push(&head, 1); Push(&head, 1); // {1, 1, 1, 2, 3, 4, 5}
    InsertNth(&head, Length(head)-1 , 5); // {1, 1, 1, 2, 3, 4, 5, 5}
    RemoveDuplicates(head);  // {1, 2, 3, 4, 5}
    int arr[] = {1, 2, 3, 4, 5};
    int arrLen = sizeof(arr)/sizeof(arr[0]);
    if( testEquality(arr, arrLen, head) ) printf(GREEN "\tPASS\n" RESET);
    else printf(RED "\tFAIL\n" RESET);
}

void MoveNodeTest() {
    printf("MoveNode..");
    struct node* a = BuildOneTwoThree();
    // the list {1, 2, 3}
    struct node* b = BuildOneTwoThree(); // {1, 2, 3}
    MoveNode(&a, &b);
    // a == {1, 1, 2, 3}
    int arr[] = {1, 1, 2, 3};
    int arrLen = sizeof(arr)/sizeof(arr[0]);
    if( !testEquality(arr, arrLen, a) ) {
      printf(RED "\tFAIL\n" RESET);
      return;
    }
    // b == {2, 3}
    int arrB[] = {2, 3};
    int arrBLen = sizeof(arrB)/sizeof(arrB[0]);
    if( testEquality(arrB, arrBLen, b) ) printf(GREEN "\tPASS\n" RESET);
    else printf(RED "\tFAIL\n" RESET);
    DeleteList(&a);
    DeleteList(&b);
}

void AlternatingSplitTest() {
    printf("AlternatingSplit..");
    struct node* source = BuildWithDummyNode(5); // {1, 2, 3, 4, 5}
    struct node* a = NULL;
    struct node* b = NULL;
    AlternatingSplit( source, &a, &b );
    // {1,3,5}
    int arr[] = {1, 3, 5};
    int arrLen = sizeof(arr)/sizeof(arr[0]);
    if( !testEquality(arr, arrLen, a) ) {
      printf(RED "\tFAIL\n" RESET);
      return;
    }
    // {2, 4}
    int arrB[] = {2, 4};
    int arrBLen = sizeof(arrB)/sizeof(arrB[0]);
    if( testEquality(arrB, arrBLen, b) ) printf(GREEN "\tPASS\n" RESET);
    else printf(RED "\tFAIL\n" RESET);

    DeleteList(&a);
    DeleteList(&b);
}

void ShuffleMergeTest() {
    printf("ShuffleMerge..");
    struct node* a = BuildWithDummyNode(5); // {1, 2, 3, 4, 5}
    struct node* b = BuildWithDummyNode(3); // {1, 2, 3}
    struct node* mergedList = ShuffleMerge( a, b );

    int arr[] = {1, 1, 2, 2, 3, 3, 4, 5};
    int arrLen = sizeof(arr)/sizeof(arr[0]);
    if( testEquality( arr, arrLen, mergedList ) ) printf(GREEN "\tPASS\n" RESET);
    else printf(RED "\tFAIL\n" RESET);
    DeleteList(&a);
    DeleteList(&b);
    DeleteList(&mergedList);
}

void SortedMergeTest() {
    printf("SortedMerge..");
    struct node* a = BuildWithDummyNode(5); // {1, 2, 3, 4, 5}

    int arr[] = {2, 8, 9};
    int arrLen = sizeof(arr)/sizeof(arr[0]);
    struct node* b = buildThisArrayAsList( arr, arrLen ); // {2, 8, 9}

    struct node* mergedList = SortedMerge( a, b );
    int arrResult[] = {1, 2, 2, 3, 4, 5, 8, 9};
    int arrResultLen = sizeof(arrResult)/sizeof(arrResult[0]);
    if( testEquality( arrResult, arrResultLen, mergedList ) ) printf(GREEN "\tPASS\n" RESET);
    else printf(RED "\tFAIL\n" RESET);
    DeleteList(&a);
    DeleteList(&b);
    DeleteList(&mergedList);
}

void MergeSortTest() {
    printf("MergeSort..");
    int arr[] = {2, 8, 9, 3, 7, 6, 5, 4, 1};
    int arrLen = sizeof(arr)/sizeof(arr[0]);
    struct node* head = buildThisArrayAsList( arr, arrLen ); // {7, 8, 9}
    MergeSort( &head );
    int arrResult[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arrResultLen = sizeof(arrResult)/sizeof(arrResult[0]);
    if( testEquality( arrResult, arrResultLen, head ) ) printf(GREEN "\tPASS\n" RESET);
    else printf(RED "\tFAIL\n" RESET);
    DeleteList(&head);
}

void SortedIntersectTest() {
    printf("SortedIntersect..");
    struct node* a = BuildWithDummyNode(4); // {1, 2, 3, 4}

    int arr[] = {2, 3, 5, 8, 9};
    int arrLen = sizeof(arr)/sizeof(arr[0]);
    struct node* b = buildThisArrayAsList( arr, arrLen ); // {2, 3, 5, 8, 9}

    struct node* intersectList = SortedIntersect( a, b );
    int arrResult[] = {2, 3};
    int arrResultLen = sizeof(arrResult)/sizeof(arrResult[0]);
    if( testEquality( arrResult, arrResultLen, intersectList ) ) printf(GREEN "\tPASS\n" RESET);
    else printf(RED "\tFAIL\n" RESET);
    DeleteList(&a);
}

void ReverseTest() {
    printf("Reverse..");
    struct node* head = BuildOneTwoThree(); // {1, 2, 3}
    Reverse(&head);
    // head now points to the list {3, 2, 1}
    int arrResult[] = {3, 2, 1};
    int arrResultLen = sizeof(arrResult)/sizeof(arrResult[0]);
    if( testEquality( arrResult, arrResultLen, head ) ) printf(GREEN "\tPASS\n" RESET);
    else printf(RED "\tFAIL\n" RESET);
    DeleteList(&head);
    // clean up after ourselves
}

void RecursiveReverseTest() {
    printf("RecursiveReverse..");
    struct node* head = BuildWithDummyNode(4); // {1, 2, 3, 4}
    RecursiveReverse(&head); // head now points to the list {4, 3, 2, 1}
    int arrResult[] = {4, 3, 2, 1};
    int arrResultLen = sizeof(arrResult)/sizeof(arrResult[0]);
    if( testEquality( arrResult, arrResultLen, head ) ) printf(GREEN "\tPASS\n" RESET);
    else printf(RED "\tFAIL\n" RESET);
    DeleteList(&head);
}
