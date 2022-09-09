#include "strAlg.h"
#include "strlib.h"

#include <stdio.h>
#include <limits.h>

void strSwap (String* a,String* b) {
    String buf = NULL;
    buf = *a;
    *a  = *b;
    *b  = buf;
}

void strHeapSort (String* arr, int len, int (*cmp)(const void*, const void*)) {
    if (len == 1) {
        return;
    }

    heapBalance(arr, len, 0, cmp);

    strSwap(&arr[0], &arr[--len]);

    strHeapSort(arr, len, cmp);
}

void heapBalance (String* arr, int len, int x, int (*cmp)(const void*, const void*)) {
    int x1 = 2 * x + 1;
    int x2 = 2 * x + 2;

    if (x1 >= len) {
        return;
    }

    if (x2 >= len) {
        if (cmp(&arr[x], &arr[x1]) <=0){
            strSwap(&arr[x], &arr[x1]);
        }
        return;
    }

    int x_max = x;

    if (cmp(&arr[x_max], &arr[x1]) <= 0) {
        x_max = x1;
    }
    if (cmp(&arr[x_max], &arr[x2]) <= 0) {
        x_max = x2;
    }

    if (x_max != x) {
        strSwap(&arr[x], &arr[x_max]);  
        heapBalance(arr, len, x_max, cmp);  
    }
}

void heapBalanceFirst (String* arr, int len, int x, int (*cmp)(const void*, const void*)) {
    int x1 = 2 * x + 1;
    int x2 = 2 * x + 2;

    if (x1 >= len) {
        return;
    }

    if (x2 >= len) {
        if (cmp(&arr[x], &arr[x1]) <=0){
            strSwap(&arr[x], &arr[x1]);
        }
        return;
    }

    int x_max = x;

    heapBalanceFirst(arr, len, x1, cmp);
    heapBalanceFirst(arr, len, x2, cmp);

    if (cmp(&arr[x_max], &arr[x1]) <= 0) {
        x_max = x1;
    }
    if (cmp(&arr[x_max], &arr[x2]) <= 0) {
        x_max = x2;
    }

    if (x_max != x) {
        strSwap(&arr[x], &arr[x_max]); 

        heapBalanceFirst (arr, len, x_max, cmp);
    }
}