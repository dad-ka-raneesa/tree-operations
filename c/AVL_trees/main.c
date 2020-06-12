#include "tree.h"

int main(void)
{
  Node_ptr tree = create_node(5);
  tree = insert_node(tree, 3);
  tree = insert_node(tree, 4);
  // tree = insert_node(tree, 4);
  // tree = insert_node(tree, 5);
  // tree = insert_node(tree, 6);
  // tree = insert_node(tree, 7);

  printf("\n\nBefore Balancing:\n");
  pre_order(tree);
  tree = balance(tree);
  printf("\nAfter Balancing:\n");
  pre_order(tree);

  // tree = NULL;
  // tree = insert_node(tree, 1);
  // tree = insert_node(tree, 0);
  // tree = insert_node(tree, 2);
  // tree = insert_node(tree, 3);
  // tree = insert_node(tree, 4);
  // tree = insert_node(tree, 5);
  // tree = insert_node(tree, 6);

  // printf("\n\nBefore Balancing:\n");
  // pre_order(tree);
  // tree =balance_with_rotation(tree);

  // printf("\nAfter Balancing:\n");
  // pre_order(tree);
  return 0;
}