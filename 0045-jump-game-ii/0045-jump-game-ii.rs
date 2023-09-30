impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        let mut dp = vec![i32::MAX; nums.len()];
        dp[0] = 0;
        
        for i in 0..nums.len() {
            for j in 0..i {
                if i as i32 <= (j as i32 + nums[j]) as i32 && dp[j] != i32::MAX {
                    dp[i] = dp[j] + 1;
                    break;
                }
            }
        }
        
        return dp[nums.len() - 1];
    }
}