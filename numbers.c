#include "tree.h"

int main(void)
{
  Node_ptr root = create_node(8);
  insert_node(root, 6);
  insert_node(root, 20);
  insert_node(root, 2);
  insert_node(root, 9);
  insert_node(root, 7);
  insert_node(root, 25);

  printf("in_order:\n");
  in_order(root);
  printf("\npre_order:\n");
  pre_order(root);
  printf("\npost_order:\n");
  post_order(root);

  root = delete_node(root, 6);
  printf("\nin_order traversal of modifed tree after deletion of existed node:\n");
  in_order(root);

  root = delete_node(root, 0);
  printf("\nin_order traversal of modifed tree after deletion of non existed node:\n");
  in_order(root);

  root = rotate_node_right(root, root->left);
  printf("\npre_order traversal of modifed tree after rotated given node right:\n");
  pre_order(root);

  root = rotate_node_right(root, root);
  printf("\npre_order traversal of modifed tree after rotated given node right:\n");
  pre_order(root);

  root = rotate_node_left(root, root);
  printf("\npre_order traversal of modifed tree after rotated given node left:\n");
  pre_order(root);

  root = rotate_node_left(root, root->left);
  printf("\npre_order traversal of modifed tree after rotated given node left:\n");
  pre_order(root);

  return 0;
}