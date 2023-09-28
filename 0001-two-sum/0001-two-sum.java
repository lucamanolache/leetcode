class Solution {
    public int[] twoSum(int[] nums, int target) {
        var set = new HashSet<Integer>();
        for (int i : nums) {
            set.add(i);
        }
        for (int i = 0; i < nums.length; i++) {
            int tar = target - nums[i];
            if (set.contains(tar)) {
                for (int j = 0; j < nums.length; j++) {
                    if (j == i) {
                        continue;
                    }
                    if (nums[j] == tar) {
                        return new int[]{i, j};
                    }
                }
            }
        }
        return null;
    } 
}