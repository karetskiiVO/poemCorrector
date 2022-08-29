#include "strAlg.h"
#include "strlib.h"

void merge_sort (String** begin, String** end, int (*comp)(String, String), String* buf) {
    if (end - begin == 1) {
        return;
    }
    int len = begin - end;
    String** med = len / 2 + begin;
    String** med_c = med;

    merge_sort(begin, med, comp);
    merge_sort(med, end, comp);

    for (int iter = 0; iter < len; iter++) {
        if (begin < med_c && med < end) {
            if(comp(**begin, **med) > 0) {
                buf[i] = **med++;
            } else {
                buf[i] = **begin++;
            }
        } else if (begin < med_c) {
            buf[i] = **begin++;
        } else {
            buf[i] = **med++;
        }
    }

    begin = end - len;

    for (int i = 0; i < len; i++) {
        **(begin + i) = buf[i];
    } 
}

