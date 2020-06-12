#ifndef __NODE_H_
#define __NODE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int value;
  struct node *left;
  struct node *right;
} Node;

typedef Node *Node_ptr;

Node_ptr create_node(int value);
Node_ptr insert_node(Node_ptr root, int value);

#endif