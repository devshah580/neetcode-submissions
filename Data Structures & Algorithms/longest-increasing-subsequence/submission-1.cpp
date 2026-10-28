class Solution {
public:
    int helper(vector<int>& nums, int currSeq, int index, int prevNum, map<pair<int, int>, int>& dp) {
        if(index >= nums.size()) {
            dp[{index, prevNum}] = 0;
            return 0;
        }
        if(dp.count({index, prevNum})) {
            return dp[{index, prevNum}];
        }

        dp[{index, prevNum}] = helper(nums, currSeq, index + 1, prevNum, dp);
        if(nums[index] > prevNum) {
            dp[{index, prevNum}] = max(1 + helper(nums, currSeq, index + 1, nums[index], dp), dp[{index, prevNum}]);
        }
        return dp[{index, prevNum}];
    }
    int lengthOfLIS(vector<int>& nums) {
        int currSeq = 0;
        int index = 0;
        int prevNum = INT_MIN;
        map<pair<int, int>, int> dp;
        helper(nums, currSeq, index, prevNum, dp);
        return dp[{0, INT_MIN}];
    }
};
