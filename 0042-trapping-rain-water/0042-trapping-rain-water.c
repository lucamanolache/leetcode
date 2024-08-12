int trap(int* height, int heightSize) {
    int sum = 0, max = 0;
    int *p1 = height, *p2 = height + heightSize - 1;

    while (p1 != p2) {
        if (*p1 < *p2) {
            max = max >= *p1 ? max : *p1;
            sum += max - *p1++;
        } else {
            max = max >= *p2 ? max : *p2;
            sum += max - *p2--;
        }
    }

    return sum;
}