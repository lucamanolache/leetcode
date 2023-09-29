bool isMonotonic(int* nums, int numsSize){
    if (numsSize == 0 || numsSize == 1) {
        return true;
    }
    int inc = -1;
    for (int i = 0; i < numsSize - 1; i++, nums++) {
        if (nums[1] == nums[0]) {
            continue;
        }
        
        if (inc == -1 && nums[1] > nums[0]) {
            inc = 1;
        } else if (inc == -1) {
            inc = 0;
        }
        if (!(nums[1] > nums[0] && inc) && !(nums[1] < nums[0] && !inc)) {
            return false;
        }
    }
    return true;
}