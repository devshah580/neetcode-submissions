class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> idk;
        for(int i = 0; i < nums.size(); i++) {
            if(idk.count(nums[i]) > 0) {
                return {idk[nums[i]], i};
            } else {
                idk.insert(std::pair(target - nums[i], i));
            }
        }
        return {};
    }
};
