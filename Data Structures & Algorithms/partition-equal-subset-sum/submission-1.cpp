class Solution {
public:
    bool helper(vector<int>& nums, int index, int& sum, int& currSum) {
        if(currSum == sum) {
            return true;
        }

        if(currSum > sum || index >= nums.size()) {
            return false;
        }

        bool found = false;
        for(int i = index; i < nums.size(); i++) {
            currSum += nums[i];
            if(helper(nums, i + 1, sum, currSum) == true) {
                found = true;
                break;
            }
            currSum -= nums[i];
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
        return helper(nums, index, sum, currSum);
    }
};
