#include "tree.h"

int main(void)
{
  Tree_ptr tree = create_tree();
  insert_node(tree, 8);
  insert_node(tree, 6);
  insert_node(tree, 20);
  insert_node(tree, 2);
  insert_node(tree, 9);
  insert_node(tree, 15);
  insert_node(tree, 25);
  printf("in_order:\n");
  in_order(tree);
  printf("\npre_order:\n");
  pre_order(tree);
  printf("\npost_order:\n");
  post_order(tree);
  return 0;
}