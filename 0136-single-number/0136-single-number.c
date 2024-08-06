int singleNumber(int* nums, int s) {
    int ans = 0;
    while (s--) ans ^= *nums++;
    return ans;
}