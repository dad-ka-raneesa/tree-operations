#ifndef __ARRAY_H_
#define __ARRAY_H_

#include <string.h>
#include "node.h"

typedef struct
{
  int *values;
  int length;
} Int_Array;

typedef Int_Array *Int_Array_ptr;

Int_Array_ptr create_Int_Array();
void resize_Int_Array(Int_Array_ptr array, int length);
void push_into_Int_Array(Int_Array_ptr array, int value);
void destroy_Int_Array(Int_Array_ptr array);

#endif