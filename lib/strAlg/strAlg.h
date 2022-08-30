#ifndef STRING_ALGORITHM
#define STRING_ALGORITHM

#include "strlib.h"

void merge_sort(String** begin, String** end, int (*comp)(String, String), String* buf);


#endif