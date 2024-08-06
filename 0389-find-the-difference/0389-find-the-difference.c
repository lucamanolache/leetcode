char findTheDifference(char* s, char* t) {
    int c1[26] = {}, c2[26] = {};
    while (*s != NULL) c1[*(s++) - 97]++;
    while (*t != NULL) c2[*(t++) - 97]++;
    for (char i = 0;; i++) if (c1[i] != c2[i]) return i + 97;
}