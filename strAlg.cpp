#include "strAlg.h"
#include "strlib.h"

#include <stdio.h>
#include <limits.h>

void strSwap (void* a, void* b) {
    String buf    = *((String*)a);
    *((String*)a) = *((String*)b);
    *((String*)b) = buf;
}

void strHeapSort (void* arr, int len, int sizeEl, int (*cmp)(const void*, const void*)) {
    heapBalanceFirst(arr, len, sizeEl, 0, cmp);
    strHeapSortAlg(arr, len, sizeEl, cmp);
}

void strHeapSortAlg (void* arr, int len, int sizeEl, int (*cmp)(const void*, const void*)) {
    if (len == 1) {
        return;
    }
    
    heapBalance(arr, len, 0, sizeEl, cmp);

    /*for (int i = 0; i < len; i++) {
        printf("%s ", ((String*)arr)[i]);
    }

    printf("\n");*/

    len--;
    strSwap(arr, (void*)((char*)arr + sizeEl * len));

    strHeapSortAlg(arr, len, sizeEl, cmp);
}

void heapBalance (void* arr, int len, int sizeEl, int x, int (*cmp)(const void*, const void*)) {
    int x1 = 2 * x + 1;
    int x2 = 2 * x + 2;

    if (x1 >= len) {
        return;
    }

    if (x2 >= len) {
        if (cmp((void*)((char*)arr + x * sizeEl), (void*)((char*)arr + x1 * sizeEl)) <= 0) {
            strSwap((void*)((char*)arr + x * sizeEl), (void*)((char*)arr + x1 * sizeEl));
        }
        return;
    }

    int x_max = x;

    if (cmp((void*)((char*)arr + x_max * sizeEl), (void*)((char*)arr + x1 * sizeEl)) <= 0) {
        x_max = x1;
    }
    if (cmp((void*)((char*)arr + x_max * sizeEl), (void*)((char*)arr + x2 * sizeEl)) <= 0) {
        x_max = x2;
    }

    if (x_max != x) {
        strSwap((void*)((char*)arr + x * sizeEl), (void*)((char*)arr + x_max * sizeEl));  
        heapBalance(arr, len, sizeEl, x_max, cmp);  
    }
}

void heapBalanceFirst (void* arr, int len, int sizeEl, int x, int (*cmp)(const void*, const void*)) {
    int x1 = 2 * x + 1;
    int x2 = 2 * x + 2;

    if (x1 >= len) {
        return;
    }

    if (x2 >= len) {
        if (cmp((void*)((char*)arr + x * sizeEl), (void*)((char*)arr + x1 * sizeEl)) <= 0) {
            strSwap((void*)((char*)arr + x * sizeEl), (void*)((char*)arr + x1 * sizeEl));
        }
        return;
    }

    int x_max = x;

    heapBalanceFirst(arr, len, sizeEl, x1, cmp);
    heapBalanceFirst(arr, len, sizeEl, x2, cmp);

    if (cmp((void*)((char*)arr + x_max * sizeEl), (void*)((char*)arr + x1 * sizeEl)) <= 0) {
        x_max = x1;
    }
    if (cmp((void*)((char*)arr + x_max * sizeEl), (void*)((char*)arr + x2 * sizeEl)) <= 0) {
        x_max = x2;
    }

    if (x_max != x) {
        strSwap((void*)((char*)arr + x * sizeEl), (void*)((char*)arr + x_max * sizeEl)); 

        heapBalanceFirst (arr, len, sizeEl, x_max, cmp);
    }
}