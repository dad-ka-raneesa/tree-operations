#include "tree.h"

int main(void)
{
  Node_ptr tree = create_node(8);
  insert_node(tree, 6);
  insert_node(tree, 20);
  insert_node(tree, 2);
  insert_node(tree, 9);
  insert_node(tree, 7);
  insert_node(tree, 25);

  printf("in_order:\n");
  in_order(tree);
  printf("\npre_order:\n");
  pre_order(tree);
  printf("\npost_order:\n");
  post_order(tree);

  tree = delete_node(tree, 6);
  printf("\nin_order traversal of modifed tree after deletion of existed node:\n");
  in_order(tree);

  tree = delete_node(tree, 0);
  printf("\nin_order traversal of modifed tree after deletion of non existed node:\n");
  in_order(tree);
  return 0;
}