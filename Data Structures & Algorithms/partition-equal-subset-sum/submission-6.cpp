class Solution {
public:
    bool helper(vector<int>& nums, int index, int sum, int& currSum, vector<vector<int>>& dp) {
        if(currSum == sum) {
            return true;
        }

        if(currSum > sum || index >= nums.size()) {
            return false;
        }

        if(dp[index][currSum] == 1) {
            return true;
        } else if(dp[index][currSum] == 0) {
            return false;
        }

        currSum += nums[index];
        if(helper(nums, index + 1, sum, currSum, dp) == true) {
            dp[index][currSum - nums[index]] = 1;
            return true;
        }
        currSum -= nums[index];

        if(helper(nums, index + 1, sum, currSum, dp) == true) {
            dp[index][currSum] = 1;
            return true;
        }

        if(dp[index][currSum] != 1) {
            dp[index][currSum] = 0;
            return false;
        } else {
            return true;
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto& elem : nums) {
            sum += elem;
        }
        if(sum % 2 != 0) {
            return false;
        } else {
            sum = sum / 2;
        }

        int currSum = 0;
        int index = 0;
        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));
        return helper(nums, index, sum, currSum, dp);
    }
};
