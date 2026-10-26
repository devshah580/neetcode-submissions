class Solution {
public:
    bool helper(vector<int>& nums, int index, int sum, int& currSum, vector<vector<int>>& dp) {
        cout << currSum << endl;
        if(currSum == sum) {
            return true;
        }

        if(currSum > sum || index >= nums.size()) {
            return false;
        }

        if(dp[index][currSum] == 1) {
            return true;
        } else if(dp[index][currSum] == 1) {
            return false;
        }
        bool found = false;
        for(int i = index; i < nums.size(); i++) {
            currSum += nums[i];
            if(helper(nums, i + 1, sum, currSum, dp) == true) {
                found = true;
                break;
            }
            currSum -= nums[i];
        }
        if(found) {
            dp[index][currSum] = 1;
        } else {
            dp[index][currSum] = 0;
        }
        return found;

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
