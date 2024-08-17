int maxSubArray(int* nums, int numsSize) {
    int *start = nums, *end = nums + numsSize;
    int max = *start, cur = *start;
    while (++start != end) {
        cur = cur + *start >= *start ? cur + *start : *start;
        max = max >= cur ? max : cur;
    }
    return max;
}