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

        for(int j = i + 1; j < nums.size(); j++) {
            if(j > i + 1 && nums[j] == nums[j - 1])
                continue;
            helper(currSum, target, j, nums, currVec, result);
        }

        currSum -= nums[i];
        currVec.pop_back();

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> vec;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        for(int i = 0; i < candidates.size(); i++) {
            if(i > 0 && candidates[i] == candidates[i - 1])
                continue;
            helper(sum, target, i, candidates, vec, result);
        }
        return result;
    }
};
