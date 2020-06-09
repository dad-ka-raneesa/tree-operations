#include "node.h"

Node_ptr create_node(int value)
{
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

Node_ptr insert_node(Node_ptr root, int value)
{
  Node_ptr p_walk = root;
  Node_ptr *pos_to_insert = &root;
  Node_ptr ptr_to_set = NULL;
  while (p_walk != NULL)
  {
    pos_to_insert = &p_walk->right;
    ptr_to_set = p_walk->right;
    if (value < p_walk->value)
    {
      pos_to_insert = &p_walk->left;
      ptr_to_set = p_walk->left;
    }
    p_walk = ptr_to_set;
  }
  *pos_to_insert = create_node(value);
  return root;
}