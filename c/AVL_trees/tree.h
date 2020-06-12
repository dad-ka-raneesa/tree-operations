#ifndef __AVL_TREE__
#define __AVL_TREE__

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int value;
  struct node *left;
  struct node *right;
} Node;

typedef Node *Node_ptr;

typedef enum
{
  False,
  True
} Bool;

Node_ptr create_node(int value);
Node_ptr insert_node(Node_ptr tree, int value);
Bool search(Node_ptr root, int value);
Node_ptr min_value_node(Node_ptr node);
Node_ptr delete_node(Node_ptr root, int value);
void in_order(Node_ptr tree);
void pre_order(Node_ptr tree);
void post_order(Node_ptr tree);
Node_ptr rotate_right(Node_ptr);
Node_ptr rotate_left(Node_ptr root);
int get_height(Node_ptr root);
int get_balance_factor(Node_ptr root);
Node_ptr rotate(Node_ptr root, int balance_factor);
Node_ptr balance(Node_ptr root);

#endif