int removeElement(int* nums, int numsSize, int val){
    int i;
    numsSize--;
    for (i = 0; i <= numsSize; ++i) {
        if (nums[i] == val) {
            nums[i] = nums[numsSize--];
            i--;
        }
    }
    return i;
}