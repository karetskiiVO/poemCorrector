#include "strlib.h"
#include "strAlg.h"
#include "poemMaker.h"

#include <stdio.h>
#include <stdlib.h>

const char* filename = "input.txt";
String text = NULL;

int main () {
    int len = 0, cnt = 0;

    input(filename, &text, &len);

    cnt = slice(text, &len);

    poemString* arr = NULL;
    arr = (poemString*)calloc(cnt, sizeof(poemString));

    set(arr, text, cnt, len);
    qsort(arr, 5, sizeof(poemString), compRev);

    /*for (int i = 0; i < cnt; i++) {
        printf("%d  ", strCmpRev(arr[i], arr[i + 1]));
    }*/

    //output(arr, cnt);

    //strHeapSort(arr, cnt, sizeof(poemString), compRev);

    output(arr, 5);
    
    free(text);
    return 0;
}