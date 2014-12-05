#include "binaryTree.h"

/*
http://cslibrary.stanford.edu/110/BinaryTrees.html
*/

int main( void ) {
    FILE *fp;
    fp = fopen("./tree.dot", "w+");
    struct node* tree = build123();
    bst_print_dot(tree, fp);
    printf("%s\n", "run: dot -Tpng tree.dot -o tree.png");
    fclose(fp);
    deleteTree(&tree);
}
