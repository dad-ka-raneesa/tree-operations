#include "traversals.h"

void in_order(Node_ptr root)
{
  if (root == NULL) return;

  in_order(root->left);
  printf("%d ", root->value);
  in_order(root->right);
}

void pre_order(Node_ptr root)
{
  if (root == NULL) return;

  printf("%d ", root->value);
  pre_order(root->left);
  pre_order(root->right);
}

void post_order(Node_ptr root)
{
  if (root == NULL) return;

  post_order(root->left);
  post_order(root->right);
  printf("%d  ", root->value);
}