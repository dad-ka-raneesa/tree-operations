#include "traversals.h"

void in_order(Node_ptr root)
{
  if (root == NULL) return;

  in_order(root->left);
  printf("%d\n", root->value);
  in_order(root->right);
}

void pre_order(Node_ptr root)
{
  if (root == NULL) return;

  printf("%d\n", root->value);
  in_order(root->left);
  in_order(root->right);
}

void post_order(Node_ptr root)
{
  if (root == NULL) return;

  in_order(root->left);
  in_order(root->right);
  printf("%d\n", root->value);
}