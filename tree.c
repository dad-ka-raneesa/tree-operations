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
  while (p_walk != NULL)
  {
    pos_to_insert = &p_walk->right;
    Node_ptr p_walk_to_set = p_walk->right;
    if (value < p_walk->value)
    {
      pos_to_insert = &p_walk->left;
      p_walk_to_set = p_walk->left;
    }
    p_walk = p_walk_to_set;
  }
  *pos_to_insert = create_node(value);
  return root;
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

Node_ptr rotate_node_right(Node_ptr root, Node_ptr pivot){
  if(root == NULL) return root;

  if(pivot->value < root->value){
    root->left = rotate_node_right(root->left, pivot);
    return root;
  }

  if(pivot->value > root->value){
    root->right = rotate_node_right(root->right, pivot);
    return root;
  }

  Node_ptr pivot_left = pivot->left;
  if(pivot_left == NULL) return root;

  Node_ptr temp = pivot_left->right;
  pivot_left->right = pivot;
  pivot->left = temp;

  return pivot_left; 
}


Node_ptr rotate_node_left(Node_ptr root, Node_ptr pivot){
  if(root == NULL) return root;

  if(pivot->value < root->value){
    root->left = rotate_node_left(root->left, pivot);
    return root;
  }

  if(pivot->value > root->value){
    root->right = rotate_node_left(root->right, pivot);
    return root;
  }

  Node_ptr pivot_right = pivot->right;
  if(pivot_right == NULL) return root;

  Node_ptr temp = pivot_right->left;
  pivot_right->left = pivot;
  pivot->right = temp;

  return pivot_right; 
}

void store_nodes_in_array(Node_ptr root, Int_Array_ptr array)
{
  if(root == NULL) return;

  store_nodes_in_array(root->left, array);
  push_into_Int_Array(array, root->value);
  store_nodes_in_array(root->right, array);
}

Node_ptr insert_array_into_tree(Node_ptr root, Int_Array_ptr array, int from, int to)
{
  for (int i = from; i < to; i++)
  {
    root = insert_node(root, array->values[i]);
  }
  return root;
}

Node_ptr balance_tree(Node_ptr root){
  Node_ptr new_root = NULL;
  Int_Array_ptr tree_nodes = create_Int_Array();
  store_nodes_in_array(root, tree_nodes);
  int pivot_index = (tree_nodes->length / 2);
  new_root = insert_array_into_tree(new_root, tree_nodes, pivot_index, pivot_index + 1);
  new_root = insert_array_into_tree(new_root, tree_nodes, 0, pivot_index);
  new_root = insert_array_into_tree(new_root, tree_nodes, pivot_index + 1, tree_nodes->length);
  destroy_Int_Array(tree_nodes);
  return new_root;
}