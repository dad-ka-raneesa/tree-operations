#include "tree.h"
#include "traversals.h"

int main(void)
{
  Node_ptr tree = create_node(8);
  tree = insert_node(tree, 6);
  tree = insert_node(tree, 20);
  tree = insert_node(tree, 2);
  tree = insert_node(tree, 9);
  tree = insert_node(tree, 7);
  tree = insert_node(tree, 25);

  printf("in_order:\n");
  in_order(tree);
  printf("\npre_order:\n");
  pre_order(tree);
  printf("\npost_order:\n");
  post_order(tree);

  tree = delete_node(tree, 6);
  printf("\n\nin_order traversal of modifed tree after deletion of existed node:\n");
  in_order(tree);

  tree = delete_node(tree, 0);
  printf("\n\nin_order traversal of modifed tree after deletion of non existed node:\n");
  in_order(tree);

  tree = rotate_node_right(tree, tree->left);
  printf("\n\npre_order traversal of modifed tree after rotated given node right:\n");
  pre_order(tree);

  tree = rotate_node_right(tree, tree);
  printf("\n\npre_order traversal of modifed tree after rotated given node right:\n");
  pre_order(tree);

  tree = rotate_node_left(tree, tree);
  printf("\n\npre_order traversal of modifed tree after rotated given node left:\n");
  pre_order(tree);

  tree = rotate_node_left(tree, tree->left);
  printf("\n\npre_order traversal of modifed tree after rotated given node left:\n");
  pre_order(tree);

  destroy_nodes(tree);

  tree = NULL;
  tree = insert_node(tree, 1);
  tree = insert_node(tree, 0);
  tree = insert_node(tree, 2);
  tree = insert_node(tree, 3);
  tree = insert_node(tree, 4);
  tree = insert_node(tree, 5);
  tree = insert_node(tree, 6);

  printf("\n\nBefore Balancing:\n");
  pre_order(tree);
  tree = balance_tree(tree);

  printf("\nAfter Balancing:\n");
  pre_order(tree);
  return 0;
}