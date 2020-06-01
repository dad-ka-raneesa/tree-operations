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
  in_order(tree);
  return 0;
}