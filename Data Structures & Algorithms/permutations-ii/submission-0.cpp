class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& currVec, set<vector<int>>& perms, unordered_set<int>& usedIndexs) {
        if(currVec.size() >= nums.size()) {
            perms.insert(currVec);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(!usedIndexs.count(i)) {
                usedIndexs.insert(i);
                currVec.push_back(nums[i]);
                backtrack(nums, currVec, perms, usedIndexs);
                currVec.pop_back();
                usedIndexs.erase(i);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> perms;
        vector<int> currVec;
        unordered_set<int> usedIndexs;
        backtrack(nums, currVec, perms, usedIndexs);

        vector<vector<int>> result;
        for(auto elem : perms) {
            result.push_back(elem);
        }
        return result;
    }
};