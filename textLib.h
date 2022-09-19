#ifndef TEXTLIB
#define TEXTLIB
/**
 * @brief new types of data.
 * 
 * @note  String - is a string type(pointer to first character in ctring); poemString - is a struct witch contains string an it's length 
 */
typedef char* String;
typedef struct {
    String str;
    int    len;
} poemString;


/**
 * @brief this function input data
 * 
 * @param [in]  stream    - name of input file
 * @param [out] text      - pointer to array witch conteins text
 * @param [out] strarr    - pointer to array witch contains structs(watch note to new types)
 * @param [out] textlen   - pointer to int witch contains length of text
 * @param [out] strarrlen - pointer to int witch contains length of strarr
 */
void intput (const char* stream, String* text, poemString** strarr, int* textlen, int* strarrlen);

/**
 * @brief this function output data
 * 
 * @param [in] stream - name of output file
 * @param [in] strarr - pointer to array witch contains structs(watch note to new types)
 * @param [in] len    - length of strar
 */
void output (const char* stream, poemString* strarr, int len);

/**
 * @brief this function compre two string
 * 
 * @param [in] fToComp - pointer to 1st element to compare
 * @param [in] sToComp - pointer to 2nd element to compare
 * 
 * @return int below 0 if fToComp < sToComp, if 0 fToComp = sToComp, if more 0 fToComp > sToComp
 * 
 * @note in alphabet fron end to begin
 */
int strCompRev (const void* fToComp, const void* sToComp);

/**
 * @brief this function compre two string
 * 
 * @param [in] fToComp - pointer to 1st element to compare
 * @param [in] sToComp - pointer to 2nd element to compare
 * 
 * @return int below 0 if fToComp < sToComp, if 0 fToComp = sToComp, if more 0 fToComp > sToComp
 * 
 * @note in alphabet fron begin to end
 */
int strComp (const void* fToComp, const void* sToComp);

/**
 * @brief this function create(clear, if it was) file with name 'stream'
 * 
 * @param [in] stream - name of file to create(clear)
 */
void clearFile (const char* stream);

/**
 * @brief output text
 * 
 * @param [in] stream - name of output file
 * @param [in] text   - pointer to first character in text
 */
void outputText (const char* stream, const String text);

#endif // TEXTLIB