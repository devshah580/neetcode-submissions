class Solution {
public:
    void helper(int& currSum, int target, int i, vector<int>& nums, vector<int>& currVec, vector<vector<int>>& result) {
        currVec.push_back(nums[i]);
        currSum += nums[i];

        if(currSum == target) {
            result.push_back(currVec);
            currSum -= nums[i];
            currVec.pop_back();
            return;
        }

        if(currSum > target) {
            currSum -= nums[i];
            currVec.pop_back();
            return;
        }

        for(int j = i; j < nums.size(); j++) {
            helper(currSum, target, j, nums, currVec, result);
        }

        currSum -= nums[i];
        currVec.pop_back();

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> vec;
        int sum;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            helper(sum, target, i, nums, vec, result);
        }
        return result;
    }
};
