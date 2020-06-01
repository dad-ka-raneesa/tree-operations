#include "tree.h"

Node_ptr create_node(int value)
{
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

Tree_ptr create_tree(void)
{
  Tree_ptr tree = malloc(sizeof(Tree));
  tree->root = NULL;
  return tree;
}

void insert_node(Tree_ptr tree, int value)
{
  Node_ptr p_walk = tree->root;
  Node_ptr *ptr_to_set = &tree->root;
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

Bool search(Tree_ptr tree, int value)
{
  Node_ptr p_walk = tree->root;
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

void in_order(Tree_ptr tree)
{
  if (tree->root == NULL)
  {
    return;
  }

  Tree_ptr left_tree = create_tree();
  Tree_ptr right_tree = create_tree();
  left_tree->root = tree->root->left;
  right_tree->root = tree->root->right;

  in_order(left_tree);
  printf("%d\n", tree->root->value);
  in_order(right_tree);

  free(left_tree);
  free(right_tree);
}

void pre_order(Tree_ptr tree)
{
  if (tree->root == NULL)
  {
    return;
  }

  Tree_ptr left_tree = create_tree();
  Tree_ptr right_tree = create_tree();
  left_tree->root = tree->root->left;
  right_tree->root = tree->root->right;

  printf("%d\n", tree->root->value);
  in_order(left_tree);
  in_order(right_tree);

  free(left_tree);
  free(right_tree);
}

void post_order(Tree_ptr tree)
{
  if (tree->root == NULL)
  {
    return;
  }

  Tree_ptr left_tree = create_tree();
  Tree_ptr right_tree = create_tree();
  left_tree->root = tree->root->left;
  right_tree->root = tree->root->right;

  in_order(left_tree);
  in_order(right_tree);
  printf("%d\n", tree->root->value);

  free(left_tree);
  free(right_tree);
}