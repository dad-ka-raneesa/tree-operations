#include "array.h"

Int_Array_ptr create_Int_Array()
{
  Int_Array_ptr array = malloc(sizeof(Int_Array));
  array->values = malloc(sizeof(int) * 0);
  array->length = 0;
  return array;
}

void resize_Int_Array(Int_Array_ptr array, int length)
{
  int *array_values = array->values;
  array->values = realloc(array->values, sizeof(int) * length);
  memcpy(array->values, array_values, sizeof(int) * array->length);
}

void push_into_Int_Array(Int_Array_ptr array, int value){
  resize_Int_Array(array, array->length + 1);
  array->values[array->length] = value;
  array->length++;
}

void destroy_Int_Array(Int_Array_ptr array)
{
  free(array->values);
  free(array);
}