#include "strAlg.h"
#include "strlib.h"

#include <stdio.h>
#include <limits.h>

void strSwap (String* a,String* b) {
    static String buf = NULL;
    buf = *a;
    *a  = *b;
    *b  = buf;
}

void strHeapSort (String* arr, int len, int (*cmp)(const void*, const void*)) {
    if (len == 1) {
        return;
    }

    printf("ok\n");

    heapBalance(arr, len, 0, cmp);

    printf("ok\n");

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
        if (cmp(arr[x], arr[x1]) <=0){
            strSwap(&arr[x], &arr[x1]);
        }
        return;
    }

    

    heapBalance(arr, len, x1, cmp);
    heapBalance(arr, len, x2, cmp);
    printf("ok\n");
    if (cmp(arr[x], arr[x1]) <= 0){
        strSwap(&arr[x], &arr[x1]);
    }
    if (cmp(arr[x], arr[x2]) <= 0){
        strSwap(&arr[x], &arr[x2]);
    }
}

