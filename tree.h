#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

typedef enum
{
  False,
  True
} Bool;

typedef struct node
{
  int value;
  struct node *left;
  struct node *right;
} Node;

typedef Node *Node_ptr;

Node_ptr create_node(int value);
Bool search(Node_ptr root, int value);
Node_ptr insert_node(Node_ptr root, int value);
Node_ptr min_value_node(Node_ptr node);
Node_ptr delete_node(Node_ptr root, int value);
void in_order(Node_ptr root);
void pre_order(Node_ptr root);
void post_order(Node_ptr root);
Node_ptr rotate_node_right(Node_ptr root, Node_ptr pivot);
Node_ptr rotate_node_left(Node_ptr root, Node_ptr pivot);
void store_nodes_in_array(Node_ptr root, Int_Array_ptr array);
Node_ptr insert_array_into_tree(Node_ptr root, Int_Array_ptr array, int from, int to);
Node_ptr balance_tree(Node_ptr root);

#endif