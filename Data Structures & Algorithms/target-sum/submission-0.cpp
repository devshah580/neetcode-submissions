class Solution {
public:
    int helper(vector<int>& nums, int target, int index, int currSum, map<pair<int, int>, int>& dp) {
        if(index >= nums.size()) {
            if(currSum == target) {
                return 1;
            } else {
                return 0;
            }
        }

        if(dp.count({index, currSum})) {
            return dp[{index, currSum}];
        }

        int result = helper(nums, target, index + 1, currSum + nums[index], dp) + helper(nums, target, index + 1, currSum - nums[index], dp);
        dp[{index, currSum}] = result;
        return result;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int> dp;
        return helper(nums, target, 0, 0, dp);
    }
};
