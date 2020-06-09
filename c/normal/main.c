#include "tree.h"
#include "traversals.h"

int main(void)
{
  Node_ptr root = create_node(8);
  root = insert_node(root, 6);
  root = insert_node(root, 20);
  root = insert_node(root, 2);
  root = insert_node(root, 9);
  root = insert_node(root, 7);
  root = insert_node(root, 25);

  printf("in_order:\n");
  in_order(root);
  printf("\npre_order:\n");
  pre_order(root);
  printf("\npost_order:\n");
  post_order(root);

  root = delete_node(root, 6);
  printf("\n\nin_order traversal of modifed tree after deletion of existed node:\n");
  in_order(root);

  root = delete_node(root, 0);
  printf("\n\nin_order traversal of modifed tree after deletion of non existed node:\n");
  in_order(root);

  root = rotate_node_right(root, root->left);
  printf("\n\npre_order traversal of modifed tree after rotated given node right:\n");
  pre_order(root);

  root = rotate_node_right(root, root);
  printf("\n\npre_order traversal of modifed tree after rotated given node right:\n");
  pre_order(root);

  root = rotate_node_left(root, root);
  printf("\n\npre_order traversal of modifed tree after rotated given node left:\n");
  pre_order(root);

  root = rotate_node_left(root, root->left);
  printf("\n\npre_order traversal of modifed tree after rotated given node left:\n");
  pre_order(root);

  root = NULL;
  root = insert_node(root, 1);
  root = insert_node(root, 0);
  root = insert_node(root, 2);
  root = insert_node(root, 3);
  root = insert_node(root, 4);
  root = insert_node(root, 5);
  root = insert_node(root, 6);

  printf("\n\nBefore Balancing:\n");
  pre_order(root);
  root = balance_tree(root);

  printf("\n\nAfter Balancing:\n");
  pre_order(root);
  return 0;
}