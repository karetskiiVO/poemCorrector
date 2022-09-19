#include "textLib.h"
#include "algorithmics.h"

#include <stdlib.h>
#include <stdio.h>

const char* inputFile  = "input.txt";
const char* outputFile = "output.txt";

int main () {
    String originaltext = NULL;
    poemString* poem    = NULL;

    int textlen = 0;
    int poemLen = 0;
    

    intput(inputFile, &originaltext, &poem, &textlen, &poemLen);
    clearFile(outputFile);

    qsort(poem, poemLen, sizeof(poemString), strComp);
    output(outputFile, poem, poemLen);

    heapSort(poem, poemLen, sizeof(poemString), strCompRev);
    output(outputFile, poem, poemLen);

    outputText(outputFile, originaltext);

    return 0;
}