#include "strlib.h"
#include "strAlg.h"

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>

const char* filename = "input.txt";
String text = NULL;

void input (String str, int* len);
void output (String* arr, int cnt);
int slice (String str, int* len);
int comp (const void* a, const void* b);

int main () {
    int len = 0, cnt = 0;

    //setlocale(LC_CTYPE, "rus");
    input(text, &len);
    printf("%s", text);
    cnt = slice(text, &len);
    String* arr = NULL;
    arr = (String*)malloc(cnt * sizeof(String*));
    qsort(arr, cnt, sizeof(String*), comp);



    return 0;
}

void input (String str, int* len) {
    FILE* file = fopen(filename, "r");
    assert(file != NULL && "No such file");

    struct stat out = {0};
    assert((fstat(fileno(file), &out) != -1) && "Error in file");
    *len = round(out.st_size / sizeof(char));

    str = Init(*len);
    str = {};

    fread(str, sizeof(char), (size_t)*len, file);;

    fclose(file);
}

void output (String* arr, int cnt) {
    for (int i = 0; i < cnt; i++) {
        printf("%s\n", arr[i]);
    }
}

int slice (String str, int* len) {
    int delta = 0;
    int cnt   = 0;

    bool isonLine = false;

    for (int i = 0; i < *len; i++) {
        //printf("%c\n", str[i]);
        if (isonLine) {
            if (str[i] == '\0' || str[i] == '\n') {
                str[i] = '\0';
                cnt++;
                isonLine = false;  
            }
            str[i - delta] = str[i];
        } else {
            printf("ok\n");
            if (str[i] == '\0' || str[i] == ' ' || str[i] == '\t' || str[i] == '*') {
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
    return strCmp(*((String*)a), *((String*)b));
}


