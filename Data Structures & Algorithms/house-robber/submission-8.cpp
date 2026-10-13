class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }

        vector<int> dp(nums.size(), 0);
        int maxSoFar = nums[0];
        dp[0] = nums[0];
        dp[1] = nums[1];
        for(int i = 2; i < nums.size(); i++) {
            dp[i] = maxSoFar + nums[i];
            maxSoFar = max(maxSoFar, dp[i - 1]);
        }
        return max(maxSoFar, dp[dp.size() - 1]);
    }
};
