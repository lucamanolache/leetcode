int singleNumber(int* nums, int s) {
    int ans = 0;
    for (int i = 0; i < s; i++) ans ^= nums[i];
    return ans;
}