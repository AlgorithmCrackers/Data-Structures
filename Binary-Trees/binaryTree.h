#ifndef _BINARYTREE_H
#define _BINARYTREE_H
#include <stdbool.h> // true and false
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

int lookup(struct node* node, int target);
int lookup_nonRecursive(struct node* node, int target);
struct node* NewNode(int data);
struct node* insert(struct node* node, int data);
struct node* insert_nonRecursive(struct node* node, int data)
struct node* build123();
void bst_print_dot(struct node* tree, FILE* stream);
struct node* buildN(int n);
void deleteTree(struct node** node_ref);

#endif
