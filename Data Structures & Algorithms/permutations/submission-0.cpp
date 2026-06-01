class Solution {
public:
    void dfs(int i, vector<int>& nums, vector<int>& curr, vector<vector<int>>& result, 
        unordered_set<int>& seen) {
        curr.push_back(nums[i]);
        seen.insert(nums[i]);
        if(curr.size() == nums.size()) {
            result.push_back(curr);
            curr.pop_back();
            seen.erase(nums[i]);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(!seen.count(nums[i])) {
                dfs(i, nums, curr, result, seen);
            }
        }
        curr.pop_back();
        seen.erase(nums[i]);
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        unordered_set<int> seen;
        for(int i = 0; i < nums.size(); i++) {
            dfs(i, nums, curr, result, seen);
        }
        return result;
    }
};
