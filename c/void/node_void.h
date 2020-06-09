#ifndef __NODE_VOID_H_
#define __NODE_VOID_H_

#include <stdio.h>
#include <stdlib.h>

typedef void *Element;

typedef struct node
{
  Element value;
  struct node *left;
  struct node *right;
} Node;

typedef Node *Node_ptr;


typedef enum
{
  Lesser = -1,
  Equal = 0,
  Greater = 1
} Compare_Status;

typedef Compare_Status Compare_Method(Element, Element);

Node_ptr create_node(Element value);
Node_ptr insert_node(Node_ptr root, Element value, Compare_Method *comparator);

#endif