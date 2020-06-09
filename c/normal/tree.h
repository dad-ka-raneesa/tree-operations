#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_

#include "node.h"
#include "array.h"

typedef enum
{
  False,
  True
} Bool;

Bool search(Node_ptr root, int value);
Node_ptr min_value_node(Node_ptr node);
Node_ptr delete_node(Node_ptr root, int value);
Node_ptr rotate_node_right(Node_ptr root, Node_ptr pivot);
Node_ptr rotate_node_left(Node_ptr root, Node_ptr pivot);
void store_nodes_in_array(Node_ptr root, Int_Array_ptr array);
Node_ptr insert_array_into_tree(Node_ptr root, Int_Array_ptr array, int from, int to);
Node_ptr balance_tree(Node_ptr root);

#endif