class Solution {
public:
    void helper(vector<int>& nums, vector<int>& currVec, int index, set<vector<int>>& uniqueSubsets) {
        if(index >= nums.size()) {
            uniqueSubsets.insert(currVec);
            return;
        }

        for(int i = index; i < nums.size(); i++) {
            currVec.push_back(nums[i]);
            helper(nums, currVec, i + 1, uniqueSubsets);
            currVec.pop_back();
            helper(nums, currVec, i + 1, uniqueSubsets);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> uniqueSubsets;
        sort(nums.begin(), nums.end());
        vector<int> currVec;
        helper(nums, currVec, 0, uniqueSubsets);

        vector<vector<int>> result;
        for(auto& elem : uniqueSubsets) {
            result.push_back(elem);
        }
        return result;
    }
};
