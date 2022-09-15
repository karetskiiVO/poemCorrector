#ifndef STRING_ALGORITHM
#define STRING_ALGORITHM

#include "strlib.h"

void strHeapSort (void* arr, int len, int sizeEl, int (*cmp)(const void*, const void*));

void strHeapSortAlg (void* arr, int len, int sizeEl, int (*cmp)(const void*, const void*));

void heapBalance (void* arr, int len, int sizeEl, int x, int (*cmp)(const void*, const void*));

void heapBalanceFirst (void* arr, int len, int sizeEl, int x, int (*cmp)(const void*, const void*));

#endif