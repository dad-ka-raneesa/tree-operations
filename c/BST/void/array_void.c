#include "array_void.h"

Array_void_ptr create_Array_void()
{
  Array_void_ptr array = malloc(sizeof(Array_void));
  array->values = malloc(sizeof(Element));
  array->length = 0;
  return array;
}

void resize_Array_void(Array_void_ptr array, int length)
{
  Element *array_values = (Element *)array->values;
  array->values = (Element *)realloc(array->values, sizeof(Element) * length);
  memcpy(array->values, array_values, sizeof(Element) * array->length);
}

void push_into_Array_void(Array_void_ptr array, Element value)
{
  resize_Array_void(array, array->length + 1);
  array->values[array->length] = value;
  array->length++;
}

void destroy_Array_void(Array_void_ptr array)
{
  free(array->values);
  free(array);
}