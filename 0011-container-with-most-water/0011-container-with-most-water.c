int maxArea(int* height, int s) {
    int l = 0, r = s - 1;
    int max = --s * fmin(height[l], height[r]);
    while (--s) {
        if (height[l] < height[r])
            max = fmax(max, s * fmin(height[++l], height[r]));
        else
            max = fmax(max, s * fmin(height[l], height[--r]));
    }
    return max;
}