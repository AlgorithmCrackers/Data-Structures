#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

struct node {
    int data;
    struct node* next;
};

void Push(struct node** headRef, int data);
int Length(struct node* head);
struct node* BuildOneTwoThree();
struct node* BuildTwoThree();
struct node* BuildWithSpecialCase();
struct node* BuildWithDummyNode();
struct node* BuildWithLocalRef();
struct node* buildThisArrayAsList(int arr[], int arrLen);
void AppendNode(struct node** headRef, int num);
void AppendNodeWithPush(struct node** headRef, int num);
struct node* CopyList(struct node* head);
struct node* CopyListWithPush(struct node* head);
struct node* CopyListWithDummy(struct node* head);
struct node* CopyListWithLocalRef(struct node* head);
struct node* CopyListRecursive(struct node* head);
int Count(struct node* head, int searchFor);
int GetNth(struct node* head, int index);
void DeleteList(struct node** headRef);
int Pop(struct node** headRef);
void printLinkedList(struct node* head);
bool testEquality(int arr[], int arrLen, struct node* head);
void InsertNth(struct node** headRef, int index, int data);
void SortedInsert(struct node** headRef, struct node* newNode);
void InsertSort(struct node** headRef);
void Append(struct node** aRef, struct node** bRef);
void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef);
void RemoveDuplicates(struct node* head);
void MoveNode(struct node** destRef, struct node** sourceRef);
void AlternatingSplit(struct node* source, struct node** aRef, struct node** bRef);
struct node* ShuffleMerge(struct node* a, struct node* b);
struct node* SortedMerge(struct node* a, struct node* b);
void MergeSort(struct node** headRef);
struct node* SortedIntersect(struct node* a, struct node* b);
void Reverse(struct node** headRef);
void RecursiveReverse(struct node** headRef);

#endif
