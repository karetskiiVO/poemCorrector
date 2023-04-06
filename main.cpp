#include "textLib.h"
#include "algorithmics.h"

#include <stdlib.h>
#include <stdio.h>

const char* inputFile  = "input.txt"; // static
const char* outputFile = "output.txt";

int main () {
    String originaltext = NULL;
    poemString* poem    = NULL;

    int textlen = 0;
    int poemLen = 0;

    readText(inputFile, &originaltext, &poem, &textlen, &poemLen);
    clearFile(outputFile); // del

    qsort(poem, poemLen, sizeof(poemString), strComp);
    write(outputFile, poem, poemLen, "w");

    heapSort(poem, poemLen, sizeof(poemString), strCompRev);
    write(outputFile, poem, poemLen, "a");

    writeText(outputFile, originaltext, textlen);

    free(originaltext);
    free(poem);

    return 0;
}