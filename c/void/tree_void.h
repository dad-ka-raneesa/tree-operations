#include <stdio.h>
#include <stdlib.h>

#ifndef __BINARY_SEARCH_TREE_VOID_H_
#define __BINARY_SEARCH_TREE_VOID_H_

#include "node_void.h"
#include "array_void.h"

typedef enum
{
  False,
  True
} Bool;

Bool search_in_node(Node_ptr root, Element value, Compare_Method *comparator);

Node_ptr get_min_of_tree(Node_ptr root);
Node_ptr get_max_of_tree(Node_ptr root);

Node_ptr delete_node(Node_ptr root, Element value, Compare_Method *comparator);

Node_ptr get_node_of(Node_ptr root, Element value, Compare_Method *comparator);
Node_ptr rotate_right(Node_ptr root, Node_ptr pivot, Compare_Method *comparator);
Node_ptr rotate_left(Node_ptr root, Node_ptr pivot, Compare_Method *comparator);

Array_void_ptr get_sorted_tree_list(Node_ptr root, Array_void_ptr array);
Node_ptr insert_array_into_tree(Node_ptr root, Array_void_ptr array, int from, int to, Compare_Method *comparator);
Node_ptr balance_tree(Node_ptr root, Compare_Method *comparator);

void destroy_nodes(Node_ptr root);

#endif