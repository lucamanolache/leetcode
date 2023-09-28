#include <string.h>

char * mergeAlternately(char * word1, char * word2){
    char *ret = malloc(strlen(word1) + strlen(word2) + 1);
    int i = 0;
    while (*word1 != 0 && *word2 != 0) {
        ret[i] = *word1;
        i++;
        word1++;
        ret[i] = *word2;
        i++;
        word2++;
    }
    while (*word1 != 0) {
        ret[i] = *word1;
        i++;
        word1++;
    }
    while (*word2 != 0) {
        ret[i] = *word2;
        i++;
        word2++;
    }
    ret[i] = 0;
    return (char *) ret;
}