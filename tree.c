#include "tree.h"

Node_ptr create_node(int value)
{
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void insert_node(Node_ptr root, int value)
{
  Node_ptr p_walk = root;
  Node_ptr *ptr_to_set = &root;
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

Bool search(Node_ptr root, int value)
{
  Node_ptr p_walk = root;
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

Node_ptr min_value_node(Node_ptr node){
   Node_ptr current = node;
   while (current && current->left != NULL)
      current = current->left;
   return current;
}

Node_ptr delete_node(Node_ptr root, int value){
  
  if(root == NULL) return root;

  if(value < root->value){
     root->left = delete_node(root->left, value);
     return root;
  }

  if(value > root->value){
     root->right = delete_node(root->right, value);
     return root;
  }

  if(root->left == NULL){
    Node_ptr temp = root->right;
    free(root);
    return temp;
  }
    
  if(root->right == NULL){
    Node_ptr temp = root->left;
    free(root);
    return temp;
  }

  Node_ptr min_node = min_value_node(root->right);
  root->value = min_node->value;
  root->right =  delete_node(root->right, min_node->value);
  return root;
}

void in_order(Node_ptr root)
{
  if (root == NULL)
  {
    return;
  }

  in_order(root->left);
  printf("%d\n", root->value);
  in_order(root->right);
}

void pre_order(Node_ptr root)
{
  if (root == NULL)
  {
    return;
  }

  printf("%d\n", root->value);
  in_order(root->left);
  in_order(root->right);
}

void post_order(Node_ptr root)
{
  if (root == NULL)
  {
    return;
  }

  in_order(root->left);
  in_order(root->right);
  printf("%d\n", root->value);
}