#include "traversals_void.h"

void in_order(Node_ptr tree, Display_Data *displayer)
{
  if (tree == NULL)
    return;
  in_order(tree->left, displayer);
  (*displayer)(tree->value);
  in_order(tree->right, displayer);
}

void pre_order(Node_ptr tree, Display_Data *displayer)
{
  if (tree == NULL)
    return;
  (*displayer)(tree->value);
  pre_order(tree->left, displayer);
  pre_order(tree->right, displayer);
}

void post_order(Node_ptr tree, Display_Data *displayer)
{
  if (tree == NULL)
    return;
  post_order(tree->left, displayer);
  post_order(tree->right, displayer);
  (*displayer)(tree->value);
}