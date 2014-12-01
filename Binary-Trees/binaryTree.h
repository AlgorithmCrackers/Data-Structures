#ifndef _BINARYTREE_H
#define _BINARYTREE_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

int lookup(struct node* node, int target);
struct node* NewNode(int data);
struct node* insert(struct node* node, int data);
struct node* build123();
void bst_print_dot(struct node* tree, FILE* stream);

#endif
