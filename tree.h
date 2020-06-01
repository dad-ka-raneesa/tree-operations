#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int value;
  struct node *left;
  struct node *right;
} Node;

typedef Node *Node_ptr;

typedef struct
{
  Node_ptr root;
} Tree;

typedef Tree *Tree_ptr;

Node_ptr create_node(int value);
Tree_ptr create_tree(void);
void insert_node(Tree_ptr tree, int value);
void in_order(Tree_ptr tree);

#endif