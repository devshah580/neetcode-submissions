class Solution {
public:
    int helper(vector<int>& nums, int target, int index, int currSum, vector<vector<int>>& dp, int totalSum) {
        if(index >= nums.size()) {
            if(currSum == target) {
                return 1;
            } else {
                return 0;
            }
        }

        if(dp[index][currSum + totalSum] != INT_MIN) {
            return dp[index][currSum + totalSum];
        }

        int result = helper(nums, target, index + 1, currSum + nums[index], dp, totalSum) + helper(nums, target, index + 1, currSum - nums[index], dp, totalSum);
        dp[index][currSum + totalSum] = result;
        return result;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for(auto elem : nums) {
            totalSum += elem;
        }
        vector<vector<int>> dp(nums.size(), vector<int>(totalSum * 2 + 1, INT_MIN));
        return helper(nums, target, 0, 0, dp, totalSum);
    }
};
