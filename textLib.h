#ifndef TEXTLIB
#define TEXTLIB

typedef char* String;
typedef struct {
    String str;
    int    len;
} poemString;



void intput (const char* stream, String* text, poemString** strarr, int* textlen, int* strarrlen);

void output (const char* stream, poemString* strarr, int len);

int strCompRev (const void* fToComp, const void* sToComp);

int strComp (const void* fToComp, const void* sToComp);

void clearFile (const char* stream);

void outputText (const char* stream, const String text);

#endif // TEXTLIB