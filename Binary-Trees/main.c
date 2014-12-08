#include "binaryTree.h"

/*
http://cslibrary.stanford.edu/110/BinaryTrees.html
*/
void graphviz_tree(struct node* tree){
  FILE *fp;
  fp = fopen("./tree.dot", "w+");
  bst_print_dot(tree, fp);
  printf("%s\n", "run: dot -Tpng tree.dot -o tree.png");
  fclose(fp);
}

int main( void ) {
    struct node* tree = build123();
    structure(tree);
    deleteTree(&tree);
}
