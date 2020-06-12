#include "tree.h"

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
  root = balance(root);
  return root;
}

Bool search(Node_ptr root, int value)
{
  Node_ptr p_walk = root;
  Bool flag = False;
  Node_ptr ptr_to_set = NULL;

  while (p_walk != NULL && !flag)
  {
    if (value == p_walk->value)
    {
      flag = True;
    }

    ptr_to_set = p_walk->right;
    if (value < p_walk->value)
    {
      ptr_to_set = p_walk->left;
    }
    p_walk = ptr_to_set;
  }
  
  return flag;
}

Node_ptr min_value_node(Node_ptr node){
   Node_ptr current = node;
   while (current && current->left != NULL)
      current = current->left;
   return current;
}

Node_ptr delete_node(Node_ptr root, int value){
  
  if(root == NULL) return root;

  root->left = value < root->value ? delete_node(root->left, value) : root->left;
  root->right = value > root->value ? delete_node(root->right, value) : root->right;
  
  if(value == root->value){
    if(root->left == NULL || root->right == NULL){
      Node_ptr temp = root->left ? root->left : root->right;;
      free(root);
      return temp;
    }

    Node_ptr min_node = min_value_node(root->right);
    root->value = min_node->value;
    root->right =  delete_node(root->right, min_node->value);
  }
  return root;
}

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

int get_height(Node_ptr root)
{
  if (root == NULL)
  {
    return 0;
  }
  return 1 + get_height(root->left) + get_height(root->right);
}

int get_balance_factor(Node_ptr tree)
{
  int r_height = get_height(tree->right);
  int l_height = get_height(tree->left);
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
