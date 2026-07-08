class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        int maxCount = nums[0];
        for(int i = 2; i < nums.size(); i++) {
            nums[i] = maxCount + nums[i];
            maxCount = max(maxCount, nums[i - 1]);
        }
        return max(maxCount, nums[nums.size() - 1]);
    }
};
