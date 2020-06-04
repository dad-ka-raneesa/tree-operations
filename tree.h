#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

#include <stdio.h>
#include <stdlib.h>

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
Bool search(Node_ptr tree, int value);
void insert_node(Node_ptr tree, int value);
void in_order(Node_ptr tree);
void pre_order(Node_ptr tree);
void post_order(Node_ptr tree);

#endif