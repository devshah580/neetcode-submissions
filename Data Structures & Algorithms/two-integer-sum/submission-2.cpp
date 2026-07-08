class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        for(int i = 0; i < nums.size(); i++) {
            if(indices.count(nums[i])) {
                return {indices[nums[i]], i};
            } else {
                indices[target - nums[i]] = i;
            }
        }
        return {};
    }
};


