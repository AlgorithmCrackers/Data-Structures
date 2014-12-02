/*
http://eli.thegreenplace.net/2009/11/23/visualizing-binary-trees-with-graphviz/
*/
#include "binaryTree.h"

/*
 point representation for NULL
*/
void bst_print_dot_null(int data, int nullcount, FILE* stream) {
    fprintf(stream, "    null%d [shape=point];\n", nullcount); // unique variable for null
    fprintf(stream, "    %d -> null%d;\n", data, nullcount);
}
/*
Given a BST node and a file pointer, prints its root,left and right
according to dot language, recursively
*/
void bst_print_dot_aux(struct node* node, FILE* stream) {
    static int nullcount = 0;

    if (node->left) { // print the root and traverse left
        fprintf(stream, "    %d -> %d;\n", node->data, node->left->data);
        bst_print_dot_aux(node->left, stream); // recurse
    }
    else // print the root and null for left
        bst_print_dot_null(node->data, nullcount++, stream);

    if (node->right) { // print the root and traverse right
        fprintf(stream, "    %d -> %d;\n", node->data, node->right->data);
        bst_print_dot_aux(node->right, stream); // recurse
    }
    else // print the root and null for right
        bst_print_dot_null(node->data, nullcount++, stream);
}
/*
Given a BST and a filePointer, prints the dot file implementation to the filepointer 
*/
void bst_print_dot(struct node* tree, FILE *stream) {
    fprintf(stream, "digraph BST {\n");
    fprintf(stream, "    node [fontname=\"Arial\"];\n");

    if (!tree) // NULL tree
        fprintf(stream, "\n");
    else if (!tree->right && !tree->left) // single node tree
        fprintf(stream, "    %d;\n", tree->data);
    else // common case
        bst_print_dot_aux(tree, stream);

    fprintf(stream, "}\n");
}