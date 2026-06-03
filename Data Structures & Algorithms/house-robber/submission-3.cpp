class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        vector<int> cache(nums.size(), 0);
        cache[0] = nums[0];
        cache[1] = nums[1];
        int maxSoFar = cache[0];
        for(int i = 2; i < nums.size(); i++) {
            cache[i] = nums[i] + maxSoFar;
            maxSoFar = max(maxSoFar, cache[i - 1]);
        }
        return max(maxSoFar, cache[cache.size() - 1]);
    }
};
