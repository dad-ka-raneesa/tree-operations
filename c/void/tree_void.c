#include "tree_void.h"

Bool search_in_node(Node_ptr root, Element value, Compare_Method *comparator)
{
  Node_ptr p_walk = root;
  Bool flag = False;
  while (p_walk != NULL && !flag)
  {
    if ((*comparator)(value, p_walk->value) == Equal)
    {
      flag = True;
    }
    Node_ptr ptr_to_set_p_walk = p_walk->right;
    if ((*comparator)(value, p_walk->value) == Lesser)
    {
      ptr_to_set_p_walk = p_walk->left;
    }
    p_walk = ptr_to_set_p_walk;
  }
  return flag;
}

Node_ptr get_min_of_tree(Node_ptr root)
{
  Node_ptr min_of_tree = root;
  while (min_of_tree && min_of_tree->left != NULL)
  {
    min_of_tree = min_of_tree->left;
  }
  return min_of_tree;
}

Node_ptr get_max_of_tree(Node_ptr root)
{
  Node_ptr max_of_tree = root;
  while (max_of_tree && max_of_tree->right != NULL)
  {
    max_of_tree = max_of_tree->right;
  }
  return max_of_tree;
}

Node_ptr delete_node(Node_ptr root, Element value, Compare_Method *comparator)
{
  if (root == NULL)
    return root;
  Compare_Status result = (*comparator)(value, root->value);
  root->left = result == Lesser ? delete_node(root->left, value, comparator) : root->left;
  root->right = result == Greater ? delete_node(root->right, value, comparator) : root->right;
  if (result == Equal)
  {
    if (root->left == NULL || root->right == NULL)
    {
      Node_ptr temp = root->left ? root->left : root->right;
      free(root);
      return temp;
    }
    Node_ptr minOfRight = get_min_of_tree(root->right);
    root->value = minOfRight->value;
    root->right = delete_node(root->right, minOfRight->value, comparator);
  }
  return root;
}

Node_ptr get_node_of(Node_ptr root, Element value, Compare_Method *comparator)
{
  Compare_Status result = (*comparator)(value, root->value);
  if (root == NULL || result == Equal)
    return root;
  if (result == Lesser)
    return get_node_of(root->left, value, comparator);
  return get_node_of(root->right, value, comparator);
}

Node_ptr rotate_right(Node_ptr root, Node_ptr pivot, Compare_Method *comparator)
{
  if (root == NULL)
    return root;
  Compare_Status result = (*comparator)(pivot->value, root->value);
  if (result == Lesser)
  {
    root->left = rotate_right(root->left, pivot, comparator);
    return root;
  }
  if (result == Greater)
  {
    root->right = rotate_right(root->right, pivot, comparator);
    return root;
  }
  Node_ptr pivot_left = pivot->left;
  if (pivot_left == NULL)
    return pivot;
  pivot->left = pivot_left->right;
  pivot_left->right = pivot;
  return pivot_left;
}

Node_ptr rotate_left(Node_ptr root, Node_ptr pivot, Compare_Method *comparator)
{
  if (root == NULL)
    return root;
  Compare_Status result = (*comparator)(pivot->value, root->value);
  if (result == Lesser)
  {
    root->left = rotate_left(root->left, pivot, comparator);
    return root;
  }
  if (result == Greater)
  {
    root->right = rotate_left(root->right, pivot, comparator);
    return root;
  }
  Node_ptr pivot_right = pivot->right;
  if (pivot_right == NULL)
    return pivot;
  pivot->right = pivot_right->left;
  pivot_right->left = pivot;
  return pivot_right;
}

Array_void_ptr get_sorted_tree_list(Node_ptr root, Array_void_ptr array)
{
  if (root == NULL)
    return array;
  get_sorted_tree_list(root->left, array);
  push_to_Array_void(array, root->value);
  get_sorted_tree_list(root->right, array);
  return array;
}

Node_ptr insert_array_into_tree(Node_ptr root, Array_void_ptr array, int from, int to, Compare_Method *comparator)
{
  for (int i = from; i < to; i++)
  {
    root = insert_into_tree(root, array->values[i], comparator);
  }
  return root;
}

Node_ptr balance_tree(Node_ptr root, Compare_Method *comparator)
{
  Node_ptr new_root = NULL;
  Array_void_ptr tree_values_in_order = create_Array_void();
  tree_values_in_order = get_sorted_tree_list(root, tree_values_in_order);
  int pivot_index = (tree_values_in_order->length / 2);
  new_root = insert_array_into_tree(new_root, tree_values_in_order, pivot_index, pivot_index + 1, comparator);
  new_root = insert_array_into_tree(new_root, tree_values_in_order, 0, pivot_index, comparator);
  new_root = insert_array_into_tree(new_root, tree_values_in_order, pivot_index + 1, tree_values_in_order->length, comparator);
  destroy_Array_void(tree_values_in_order);
  return new_root;
}

void destroy_nodes(Node_ptr root)
{
  if (root == NULL)
    return;
  destroy_nodes(root->left);
  destroy_nodes(root->right);
  free(root);
}


