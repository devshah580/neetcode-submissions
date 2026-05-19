class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> unique_nums;
        for(int i = 0; i < nums.size(); i++) {
            if(unique_nums.count(nums[i])) {
                return true;
            } 
            unique_nums.insert(nums[i]);
        }
        return false;
    }
};