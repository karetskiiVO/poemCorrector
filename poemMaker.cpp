#include "poemMaker.h"

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>

void input (const char* stream, String* str, int* len) {
    FILE* file = fopen(stream, "r");
    assert(file != NULL && "No such file");

    struct stat out = {0};
    assert((fstat(fileno(file), &out) != -1) && "Error in file");
    *len = round(out.st_size / sizeof(char));

    *str = (String)malloc(sizeof(char) * (*len));

    fread(*str, sizeof(char), (size_t)(*len), file);;

    fclose(file);
}

void output (poemString* arr, int cnt) {
    for (int i = 0; i < cnt; i++) {
        printf("%s\n", arr[i].s);
    }
}

int slice (String const str, int* len) {
    int delta = 0;
    int cnt   = 0;

    bool isonLine = false;

    for (int i = 0; i < *len; i++) {
        if (isonLine) {
            if (str[i] == '\0' || str[i] == '\n') {
                str[i] = '\0';
                cnt++;
                isonLine = false;  
            }
            str[i - delta] = str[i];
        } else {
            if (str[i] == ' ' || str[i] == '\0' || str[i] == '\n' || str[i] == '\t' || str[i] == '*' || str[i] == '.' || str[i] == '\r') {
                delta++;
            } else {
                str[i - delta] = str[i];
                isonLine = true;
            }
        }
    }

    *len -= delta;

    return cnt;
}

int comp (const void* a, const void* b) {
    return strCmp(((poemString*)a)->s, ((poemString*)b)->s);
}

int compRev (const void* a, const void* b) {
    poemString* a_ = (poemString*) a;
    poemString* b_ = (poemString*) b;
    return strCmpRev(*a_, *b_);
}

void set(poemString* arr, String str, int cnt, int len) {
    int iter = -1;
    int d = 0;
    bool isonLine = true;
    for (int i = 0; i < len && iter < cnt; i++) {
        if (isonLine) {
            arr[++iter].s = str + i;
            d = 0;
            isonLine = false;
        }
        if (str[i] == '\0') {
            if (iter != -1) {
                arr[iter].len = strLen(arr[iter].s);
            }

            d = 0;
            isonLine = true;
        }
        d++;
    }
}
