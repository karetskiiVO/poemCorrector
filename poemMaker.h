#ifndef POEMMAKER
#define POEMMAKER

#include "strAlg.h"

void input (const char* stream, String* str, int* len);

void output (poemString* arr, int cnt);

int slice (String str, int* len);

int comp (const void* a, const void* b);

void set (poemString* arr, String str, int cnt, int len);

int compRev (const void* a, const void* b);

#endif