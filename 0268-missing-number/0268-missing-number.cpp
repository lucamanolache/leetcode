class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans ^= i;
            sum ^= nums[i];
        }
        return nums.size() ^ ans ^ sum;
    }
};
