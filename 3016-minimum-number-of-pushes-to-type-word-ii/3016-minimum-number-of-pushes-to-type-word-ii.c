#include <stdio.h>
#include <string.h>

int comp(const void *a,const void *b) {
    return *((int *) b) - *((int *) a);
}

int minimumPushes(char* word) {
    int counts[26] = {};
    while (*word != NULL) counts[*(word++) - 97]++;
    
    qsort(counts, sizeof(counts)/sizeof(*counts), sizeof(*counts), comp);
    
    int sum = 0;
    int* cts = counts;
    for (int i = 8; i < 26 + 8 && *cts != 0; i++) sum += *(cts++) * (i / 8);
    
    return sum;
}