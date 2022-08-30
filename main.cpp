#include "strlib.h"
#include "strAlg.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main () {
    String arr[] = {"aboba", "Boba", "biba", "abc", "z"};
    String arr_buf[5] = {0};
    String** arr_mem;
    arr_mem = (String**)malloc(5 * sizeof(String*));
    for (int i = 0; i < 5; i++) {
        arr_mem[i] = &arr[i];
    }
    merge_sort(arr_mem, arr_mem + 5, strCmp, arr_buf);

    for (int i = 0; i < 5; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}