#include "algorithmics.h"

#include <assert.h>
#include <stdio.h>

void Swap (const void* a, const void* b, int sizeEl) {
    char buf = 0;
    for(int i = 0; i < sizeEl; i++) {
        buf = *((char*)a + i);
        *((char*)a + i) = *((char*)b + i);
        *((char*)b + i) = buf;
    }
}

void heapBalance (void* arr, int len, int sizeEl, int x, int (*cmp)(const void*, const void*)) {
    int x1 = 2 * x + 1;
    int x2 = 2 * x + 2;

    if (x1 >= len) {
        return;
    }

    if (x2 >= len) {
        if (cmp((void*)((char*)arr + x * sizeEl), (void*)((char*)arr + x1 * sizeEl)) <= 0) {
            Swap((void*)((char*)arr + x * sizeEl), (void*)((char*)arr + x1 * sizeEl), sizeEl);
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
        Swap((void*)((char*)arr + x * sizeEl), (void*)((char*)arr + x_max * sizeEl), sizeEl);  
        heapBalance(arr, len, sizeEl, x_max, cmp);  
    }
}

void HeapSortAlg (void* arr, int len, int sizeEl, int (*cmp)(const void*, const void*)) {
    if (len == 1) {
        return;
    }
    
    heapBalance(arr, len, sizeEl, 0, cmp);

    len--;
    Swap(arr, (void*)((char*)arr + sizeEl * len), sizeEl);

    HeapSortAlg(arr, len, sizeEl, cmp);
}

void heapBalanceFirst (void* arr, int len, int sizeEl, int x, int (*cmp)(const void*, const void*)) {
    int x1 = 2 * x + 1;
    int x2 = 2 * x + 2;

    if (x1 >= len) {
        return;
    }

    if (x2 >= len) {
        if (cmp((void*)((char*)arr + x * sizeEl), (void*)((char*)arr + x1 * sizeEl)) <= 0) {
            Swap((void*)((char*)arr + x * sizeEl), (void*)((char*)arr + x1 * sizeEl), sizeEl);
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
        Swap((void*)((char*)arr + x * sizeEl), (void*)((char*)arr + x_max * sizeEl), sizeEl); 

        heapBalanceFirst (arr, len, sizeEl, x_max, cmp);
    }
}

void heapSort (void* arr, int len, int sizeEl, int (*cmp)(const void*, const void*)) {
    assert(arr != NULL && "all pointers mustn't be NULL");
    assert(cmp != NULL && "no such function");

    heapBalanceFirst(arr, len, sizeEl, 0, cmp);
    HeapSortAlg(arr, len, sizeEl, cmp);
}