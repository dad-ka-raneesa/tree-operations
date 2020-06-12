#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int value;
  struct Node *left;
  struct Node *right;
} Node;

typedef Node *Node_ptr;

Node_ptr create_node(int value)
{
  Node_ptr node = (Node_ptr)malloc(sizeof(Node));
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}
Node_ptr insert(Node_ptr tree, int value)
{
  if (tree == NULL)
  {
    return create_node(value);
  }
  if (value < tree->value)
  {
    tree->left = insert(tree->left, value);
  }
  else
  {
    tree->right = insert(tree->right, value);
  }
  return tree;
}
void print_pre_order(Node_ptr tree)
{
  if (tree == NULL)
  {
    return;
  }
  printf("%d ", tree->value);
  print_pre_order(tree->left);
  print_pre_order(tree->right);
}
Node_ptr rotate_right(Node_ptr root)
{
  if (root->left == NULL)
  {
    return root;
  }
  Node_ptr src = root->left;
  root->left = src->right;
  src->right = root;
  return src;
}

Node_ptr rotate_left(Node_ptr root)
{
  if (root->right == NULL)
  {
    return root;
  }
  Node_ptr src = root->right;
  root->right = src->left;
  src->left = root;
  return src;
}

int height(Node_ptr root)
{
  if (root == NULL)
  {
    return 0;
  }
  return 1 + height(root->left) + height(root->right);
}

int get_balance_factor(Node_ptr tree)
{
  int r_height = height(tree->right);
  int l_height = height(tree->left);
  return r_height - l_height;
}

Node_ptr rotate(Node_ptr tree, int balance_factor)
{
  if (balance_factor < 1)
  {
    int left_balance_factor = get_balance_factor(tree->left);
    if (left_balance_factor > 1)
    {
      tree->left = rotate_left(tree->left);
    }
    return rotate_right(tree);
  }
  int right_balance_factor = get_balance_factor(tree->right);
  if (right_balance_factor < -1)
  {
    tree->right = rotate_right(tree->right);
  }
  return rotate_left(tree);
}

Node_ptr balance(Node_ptr tree)
{
  if (tree == NULL)
  {
    return tree;
  }
  int balance_factor = get_balance_factor(tree);
  while (balance_factor > 1 || balance_factor < -1)
  {
    tree = rotate(tree, balance_factor);
    balance_factor = get_balance_factor(tree);
  }
  tree->right = balance(tree->right);
  tree->left = balance(tree->left);
  return tree;
}
int main(void)
{
  // Node_ptr tree = insert(NULL, 3);
  // tree = insert(tree, 4);
  // tree = insert(tree, 5);
  // tree = insert(tree, 1);
  // tree = insert(tree, 2);
  // tree = insert(tree, 8);
  // tree = insert(tree, 9);
  // tree = insert(tree, 7);
  // tree = insert(tree, 6);
  Node_ptr tree = insert(NULL, 1);
  tree = insert(tree, 2);
  tree = insert(tree, 3);
  tree = insert(tree, 4);
  tree = insert(tree, 5);
  tree = insert(tree, 6);
  // Node_ptr tree = insert(NULL, 3);
  // tree = insert(tree, 4);
  // tree = insert(tree, 5);
  print_pre_order(tree);
  tree = balance(tree);
  printf("\n");
  print_pre_order(tree);
  return 0;
}