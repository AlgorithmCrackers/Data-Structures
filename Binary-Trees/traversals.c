#include "binaryTree.h"
/*
*****  DEPTH FIRST ******
*/
// visit, move left, move right
void preorder_printTree(struct node* node) {
  if (node == NULL) return;
  printf("%d ", node->data);
  preorder_printTree(node->left);
  preorder_printTree(node->right);
}
// move left, visit, move right
void inorder_printTree(struct node* node) {
  if (node == NULL) return;
  inorder_printTree(node->left);
  printf("%d ", node->data);
  inorder_printTree(node->right);
}
// move left, move right, visit
void postorder_printTree(struct node* node) {
  if (node == NULL) return;
  postorder_printTree(node->left);
  postorder_printTree(node->right);
  printf("%d ", node->data);
}

void structure_recursive ( struct node *root, int level ) {
  int i;
  if ( root == NULL ) {
    for ( i = 0; i < level; i++ )
      putchar ( '\t' );
    puts ( "~" );
  }
  else {
    structure_r ( root->right, level + 1 );
      for ( i = 0; i < level; i++ )
        putchar ( '\t' );
      printf ( "%d\n", root->data );
    structure_r ( root->left, level + 1 );
  }
}
/*
for example,
       2
      / \
     1   3

prints as,
    ~
  3
    ~
2
    ~
  1
    ~
*/
void structure_printTree ( struct node *tree ) {
  structure_recursive ( tree, 0 );
}
// visit, move left, move right
void preorder_nonrecursive ( struct node *tree ) {
  struct node *it = tree;
  struct node *up[50];
  int top = 0;
  if ( it == NULL ) return;
  up[top++] = it;

  while ( top != 0 ) {
    it = up[--top];
    printf ( "%d\n", it->data );
    if ( it->right != NULL ) up[top++] = it->right;
    if ( it->left != NULL ) up[top++] = it->left;
  }
}
// move left, visit, move right
// see http://imgur.com/9RxHnr8
void inorder_nonrecursive ( struct node* tree ) {
  /*
  Inorder traversal is harder. We need to walk to the left without losing any
   of the right links or any of the parents. This implies at least several
   loops, one to save the links for backtracking, one to visit the saved links,
    and another to manage successive branches. Fortunately, while the logic is
     rather complex, the code is surprisingly simple
  */
  struct node *it = tree;
  struct node *up[50];
  int top = 0;
  while ( it != NULL ) {
    // This loop handles the saving of right links
    // and parents while moving down the left links.
    while ( it != NULL ) {
      if ( it->right != NULL ) up[top++] = it->right;

      up[top++] = it;
      it = it->left;
    }
    it = up[--top];
    // The second inner loop handles the visiting of parents.
    while ( top != 0 && it->right == NULL ) {
      printf ( "%d\n", it->data );
      it = up[--top];
    }
    // the final call to printf takes care of lingering right links.
    printf ( "%d\n", it->data );

    if ( top == 0 ) break;
    it = up[--top];
  }
}
