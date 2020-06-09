#include "tree_void.h"
#include "traversals_void.h"

Element create_int_element(int value)
{
  Element element = malloc(sizeof(int));
  *(int *)element = value;
  return element;
}

Element create_char_element(char value)
{
  Element element = malloc(sizeof(char));
  *(char *)element = value;
  return element;
}

void display_int_element(Element number)
{
  printf("%d ", *(int *)number);
}

void display_char_element(Element number)
{
  printf("%c ", *(char *)number);
}

Compare_Status comparator_int(Element a, Element b)
{
  Compare_Status status = Equal;
  if (*(int *)a < *(int *)b)
  {
    status = Lesser;
  }
  if (*(int *)a > *(int *)b)
  {
    status = Greater;
  }
  return status;
}

Compare_Status comparator_char(Element a, Element b)
{
  Compare_Status status = Equal;
  if (*(char *)a < *(char *)b)
  {
    status = Lesser;
  }
  if (*(char *)a > *(char *)b)
  {
    status = Greater;
  }
  return status;
}

int main(void)
{
  //------------------ int -----------------------

  Node_ptr tree = create_node(create_int_element(3));
  tree = insert_node(tree, create_int_element(1), &comparator_int);
  tree = insert_node(tree, create_int_element(5), &comparator_int);
  tree = insert_node(tree, create_int_element(2), &comparator_int);
  tree = insert_node(tree, create_int_element(0), &comparator_int);
  tree = insert_node(tree, create_int_element(4), &comparator_int);
  tree = insert_node(tree, create_int_element(6), &comparator_int);

  printf("in_order\n");
  in_order(tree, &display_int_element);
  printf("\n\n");

  printf("pre_order\n");
  pre_order(tree, &display_int_element);
  printf("\n\n");

  printf("post_order\n");
  post_order(tree, &display_int_element);
  printf("\n\n");

  Bool result = search_node(tree, create_int_element(3), &comparator_int);
  printf("%d is %s in the list\n\n", 3, result ? "present" : "not present");

  tree = delete_node(tree, create_int_element(3), &comparator_int);

  printf("after deletion pre_order\n");
  in_order(tree, &display_int_element);
  printf("\n\n");

  result = search_node(tree, create_int_element(3), &comparator_int);
  printf("%d is %s in the list\n\n", 3, result ? "present" : "not present");

  destroy_nodes(tree);

  tree = NULL;
  tree = insert_node(tree, create_int_element(3), &comparator_int);
  tree = insert_node(tree, create_int_element(1), &comparator_int);
  tree = insert_node(tree, create_int_element(5), &comparator_int);
  tree = insert_node(tree, create_int_element(2), &comparator_int);
  tree = insert_node(tree, create_int_element(0), &comparator_int);
  tree = insert_node(tree, create_int_element(4), &comparator_int);
  tree = insert_node(tree, create_int_element(6), &comparator_int);

  printf("Rotate Right 1");
  printf("\nbefore => ");
  pre_order(tree, &display_int_element);
  tree = rotate_right(tree, get_node_of(tree, create_int_element(1), &comparator_int), &comparator_int);
  printf("\nafter => ");
  pre_order(tree, &display_int_element);

  printf("\n\nRotate Left 0");
  printf("\nbefore => ");
  pre_order(tree, &display_int_element);
  tree = rotate_left(tree, get_node_of(tree, create_int_element(0), &comparator_int), &comparator_int);
  printf("\nafter => ");
  pre_order(tree, &display_int_element);
  printf("\n\n");

  //----------------- char -------------------------

  tree = NULL;
  tree = insert_node(tree, create_char_element('d'), &comparator_char);
  tree = insert_node(tree, create_char_element('b'), &comparator_char);
  tree = insert_node(tree, create_char_element('f'), &comparator_char);
  tree = insert_node(tree, create_char_element('c'), &comparator_char);
  tree = insert_node(tree, create_char_element('a'), &comparator_char);
  tree = insert_node(tree, create_char_element('e'), &comparator_char);
  tree = insert_node(tree, create_char_element('g'), &comparator_char);

  printf("in_order\n");
  in_order(tree, &display_char_element);
  printf("\n\n");


  result = search_node(tree, create_char_element('c'), &comparator_char);
  printf("%c is %s in the list\n\n", 'c', result ? "present" : "not present");

  tree = delete_node(tree, create_char_element('c'), &comparator_char);

  printf("after deletion pre_order\n");
  in_order(tree, &display_char_element);
  printf("\n\n");

  result = search_node(tree, create_char_element('c'), &comparator_char);
  printf("%c is %s in the list\n\n", 'c', result ? "present" : "not present");

  destroy_nodes(tree);

  tree = NULL;
  tree = insert_node(tree, create_char_element('d'), &comparator_char);
  tree = insert_node(tree, create_char_element('b'), &comparator_char);
  tree = insert_node(tree, create_char_element('f'), &comparator_char);
  tree = insert_node(tree, create_char_element('c'), &comparator_char);
  tree = insert_node(tree, create_char_element('a'), &comparator_char);
  tree = insert_node(tree, create_char_element('e'), &comparator_char);
  tree = insert_node(tree, create_char_element('g'), &comparator_char);

  printf("Rotate Right b");
  printf("\nbefore => ");
  pre_order(tree, &display_char_element);
  tree = rotate_right(tree, get_node_of(tree, create_char_element('b'), &comparator_char), &comparator_char);
  printf("\nafter => ");
  pre_order(tree, &display_char_element);

  printf("\n\nRotate Left a");
  printf("\nbefore => ");
  pre_order(tree, &display_char_element);
  tree = rotate_left(tree, get_node_of(tree, create_char_element('a'), &comparator_char), &comparator_char);
  printf("\nafter => ");
  pre_order(tree, &display_char_element);
  printf("\n\n");

  return 0;
}