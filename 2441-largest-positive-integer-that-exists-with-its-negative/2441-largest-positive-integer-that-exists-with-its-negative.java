class Solution {
    public int findMaxK(int[] nums) {
        if (nums.length == 0 || nums.length == 1)
            return -1;
        
        Arrays.sort(nums);
        
        int i = 0, j = nums.length - 1;
        while (i != j && nums[i] < 0 && nums[j] > 0) {
            if (-nums[i] == nums[j])
                return nums[j];
            else if (-nums[i] > nums[j])
                i++;
            else
                j--;
        }
        return -1;
    }
}