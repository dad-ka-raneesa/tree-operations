#include "tree.h"

Node_ptr create_node(int value)
{
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void insert_node(Node_ptr tree, int value)
{
  Node_ptr p_walk = tree;
  Node_ptr *ptr_to_set = &tree;
  while (p_walk != NULL)
  {
    if (value < p_walk->value)
    {
      ptr_to_set = &p_walk->left;
      p_walk = p_walk->left;
    }
    else
    {
      ptr_to_set = &p_walk->right;
      p_walk = p_walk->right;
    }
  }
  *ptr_to_set = create_node(value);
}

Bool search(Node_ptr tree, int value)
{
  Node_ptr p_walk = tree;
  Bool flag = False;

  while (p_walk != NULL && !flag)
  {
    if (value == p_walk->value)
    {
      flag = True;
    }

    if (value < p_walk->value)
    {
      p_walk = p_walk->left;
    }
    else
    {
      p_walk = p_walk->right;
    }
  }
  
  return flag;
}


void in_order(Node_ptr tree)
{
  if (tree == NULL)
  {
    return;
  }

  in_order(tree->left);
  printf("%d\n", tree->value);
  in_order(tree->right);
}

void pre_order(Node_ptr tree)
{
  if (tree == NULL)
  {
    return;
  }

  printf("%d\n", tree->value);
  in_order(tree->left);
  in_order(tree->right);
}

void post_order(Node_ptr tree)
{
  if (tree == NULL)
  {
    return;
  }

  in_order(tree->left);
  in_order(tree->right);
  printf("%d\n", tree->value);
}