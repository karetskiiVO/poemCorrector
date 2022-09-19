#include "textLib.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ctype.h>

bool isSkipped (char ch) {
    const char less[] = "().,<>/?!!\"\n\t_:;{}[]#1234567890‘’ -";
    for (int i = 0; less[i] != '\0'; i++) {
        if (less[i] == ch) {
            return true;
        }
    }
    return false;
}

int slice (String const text, int* const len) {
    assert(text != NULL && "pointers mustn't be NULL");

    int delta = 0;
    int cnt   = 0;

    bool isonLine = false;

    for (int i = 0; i < *len; i++) {
        if (isonLine) {
            if (text[i] == '\0' || text[i] == '\n') {
                cnt++;
                isonLine = false;  
            }
            text[i - delta] = text[i];
        } else {
            if (text[i] == ' ' || text[i] == '\0' || text[i] == '\n' || text[i] == '\t' || text[i] == '*' || text[i] == '.' || text[i] == '\r') {
                delta++;
            } else {
                text[i - delta] = text[i];
                isonLine = true;
            }
        }
    }

    for (int i = *len - delta; i < *len; i++) {
        text[i] = '\0';
    }

    *len -= delta;

    return cnt;
}

void set (const String text, poemString* const arr, const int textlen, const int len) {
    String charptr = text;
    arr[0].str = text;
    
    while (charptr - text < textlen) {
        if (*charptr == '\0' || *charptr == '\n') {
            arr[0].len = charptr - arr[0].str;
            charptr++;
            break;
        }
        charptr++;
    }

    for (int i = 1; i < len; i++) {
        arr[i].str = charptr;
    
        while (charptr - text < textlen) {
            if (*charptr == '\0' || *charptr == '\n') {
                arr[i].len = charptr - arr[i].str;
                charptr++;
                break;
            }
            charptr++;
        }
    }
}

void intput (const char* stream, String* text, poemString** strarr, int* textlen, int* strarrlen) {
    FILE* file = fopen(stream, "r");
    assert(file != NULL && "No such file");

    struct stat out = {0};
    assert((fstat(fileno(file), &out) != -1) && "Error in file");
    *textlen = round(out.st_size / sizeof(char));

    *text = (String)calloc(*textlen, sizeof(char));

    assert(*text != NULL && "not enought memory");
    assert((size_t)*textlen != fread(*text, sizeof(char), *textlen, file) && "Error in input");
    fclose(file);

    *strarrlen = slice(*text, textlen);
    *strarr = (poemString*)calloc(*strarrlen, sizeof(poemString));
    
    assert(*strarr != NULL && "not enought memory");

    set(*text, *strarr, *textlen, *strarrlen);
}

void output (const char* stream, poemString* strarr, int len) {
    FILE* file = fopen(stream, "a");

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < strarr[i].len; j++) {
            putc(strarr[i].str[j], file);
        }
        putc('\n', file);
    }

    fprintf(file, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    fclose(file);
}

void outputText (const char* stream, const String strarr) {
    FILE* file = fopen(stream, "a");

    fprintf(file, "%s\n\n", strarr);

    fclose(file);
}

int strComp (const void* fToComp, const void* sToComp) {
    String fToComp_ = ((poemString*)fToComp)->str;
    String sToComp_ = ((poemString*)sToComp)->str;

    int fToComp_len = ((poemString*)fToComp)->len;
    int sToComp_len = ((poemString*)sToComp)->len;

    int f   = 0;
    int s   = 0;
    int buf = 0;

    while (isSkipped(fToComp_[f])) {
        f++;
    }
    while (isSkipped(sToComp_[s])) {
        s++;
    }

    while (f < fToComp_len && s < sToComp_len) {
        buf = tolower(fToComp_[f]) - tolower(sToComp_[s]);
        if (buf) {
            return buf;
        }
        f++;
        s++;
    }
    return fToComp_len - sToComp_len;
}

int strCompRev (const void* fToComp, const void* sToComp) {
    String fToComp_ = ((poemString*)fToComp)->str;
    String sToComp_ = ((poemString*)sToComp)->str;

    int fToComp_len = ((poemString*)fToComp)->len;
    int sToComp_len = ((poemString*)sToComp)->len;

    int f   = fToComp_len;
    int s   = sToComp_len;
    int buf = 0;

    while (isSkipped(fToComp_[f])) {
        f--;
    }
    while (isSkipped(sToComp_[s])) {
        s--;
    }

    while (f >= 0 && s >= 0) {
        buf = tolower(fToComp_[f]) - tolower(sToComp_[s]);
        if (buf) {
            return buf;
        }
        f--;
        s--;
    }
    return fToComp_len - sToComp_len;
}

void clearFile (const char* stream) {
    FILE* file = fopen(stream, "w");
    fclose(file);
}