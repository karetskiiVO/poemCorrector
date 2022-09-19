#ifndef ALGORITHM
#define ALGORITHM

/**
 * @brief this function use heap sort to sort array
 * 
 * @param [in] arr    - pointer to array
 * @param [in] len    - length of array
 * @param [in] sizeEl - size of element in bytes
 * @param [in] cmp    - pointer to function whitch compare elemets 
 */
void heapSort (void* arr, int len, int sizeEl, int (*cmp)(const void*, const void*));

#endif // ALGORITHM