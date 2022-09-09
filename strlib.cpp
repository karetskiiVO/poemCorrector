#include "strlib.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>

#define NULLBYTE '\0'

String Init (int len) {
    return (String) malloc(len * sizeof(char));
}

int strLen (const String str) {
    assert(str != NULL && "the string mustnt be NULL\n");

    String str_buf = str;

    while (*str_buf != NULLBYTE) {
        str_buf++;
    }

    return str_buf - str;
}

String strCpy (String s1, const String s2) {
    //assert(s1 != NULL && s2 != NULL && "the string mustnt be NULL\n");

    int i = 0;

    for (i = 0; s2[i] != NULLBYTE; i++) {
        s1[i] = s2[i];
    }

    s1[++i] = NULLBYTE;

    return s1;
}

char* strChr (const String str, int ch) {
    assert(str != NULL && "the string mustnt be NULL\n");
    
    char* ptr = NULL;
    int strl = strLen(str);
    
    for (int i = 0; i < strl && ptr == NULL; i++) {
        if (str[i] == (char)ch) {
            ptr = str + i;
        }
    }
    
    return ptr;
}

char* strrChr (const String str, int ch) {
    assert(str != NULL && "the string mustnt be NULL\n");

    char* ptr = NULL;
    int strl = strLen(str) - 1;
    
    for (int i = strl; i > -1 && ptr == NULL; i--) {
        if (str[i] == (char)ch) {
            ptr = str + i;
        }
    }
    
    return ptr;
}

int strCmp (const String s1, const String s2) {
    assert(s1 != NULL && s2 != NULL && "the string mustnt be NULL\n");
    
    String buf1 = s1, buf2 = s2;

    while (*buf1 != NULLBYTE && *buf2 != NULLBYTE) {
        if (!(*buf1 != NULLBYTE && *buf2 != NULLBYTE)) {
            if (!(*buf1 != NULLBYTE || *buf2 != NULLBYTE)) {
                return tolower(*buf1) - tolower(*buf2);
            }

            if (*buf1 == '(' || *buf1 == '"' || *buf1 == ')' || *buf1 == '-' || *buf1 == ' ') {
                buf1++;
            } else if (*buf2 == '(' || *buf2 == '"' || *buf2 == ')' || *buf2 == '-' || *buf2 == ' ') {
                buf2++;
            } else {
                if (*buf1 != *buf2) {
                    return tolower(*buf1) - tolower(*buf2);
                }

                buf1++;
                buf2++;
            }
        }
    }
    /*for (int i = 0; s1[i] != NULLBYTE || s2[i] != NULLBYTE; i++) { // segmentation in for 
        if (!(s1[i] != NULLBYTE && s2[i] != NULLBYTE)) {
            return tolower(s1[i]) - tolower(s2[i]); 
        }
        if (s1[i] != s2[i]) {
            return tolower(s1[i]) - tolower(s2[i]);
        }
    }*/

    return 0;
}

String strCat (String s1, const String s2) {
    assert(s1 != NULL && s2 != NULL && "the string mustnt be NULL\n");
    
    printf("%s\n", s2);

    int s1len = strLen(s1);

    int i = 0;

    for (i = 0; s2[i] != NULLBYTE; i++) {
        s1[i + s1len] = s2[i];
    }

    s1[++i + s1len] = NULLBYTE;
    return s1;
}

void strSwap (String s1, String s2, String buf){
    strCpy(buf, s1);
    strCpy(s1,  s2);
    strCpy(s2, buf);
}

#undef NULLBYTE