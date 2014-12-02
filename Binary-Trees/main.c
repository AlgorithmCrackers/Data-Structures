#include "binaryTree.h"

/*
http://cslibrary.stanford.edu/110/BinaryTrees.html
*/

int main( void ) {
    FILE *fp;   
    fp = fopen("./tree.dot", "w+");
    bst_print_dot(build123(), fp);
    printf("%s\n", "run: dot -Tpng tree.dot -o tree.png");
    fclose(fp);
}

