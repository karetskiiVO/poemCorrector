#include "strAlg.h"
#include "strlib.h"

void merge_sort (String** begin, String** end, int (*comp)(String, String), String* buf) {
    if (end - begin == 1) {
        return;
    }
    int len = end - begin;
    String** med = len / 2 + begin;
    String** med_c = med;

    merge_sort(begin, med, comp, buf);
    merge_sort(med, end, comp, buf);

    for (int iter = 0; iter < len; iter++) {
        if (begin < med_c && med < end) {
            if(comp(**begin, **med) > 0) {
                strCpy(buf[iter], **med++);
            } else {
                strCpy(buf[iter], **begin++);
            }
        } else if (begin < med_c) {
            strCpy(buf[iter], **begin++);
        } else {
            strCpy(buf[iter], **med++);
        }
    }

    begin = end - len;

    for (int i = 0; i < len; i++) {
        strCpy(**(begin + i), buf[i]);
    } 
}

