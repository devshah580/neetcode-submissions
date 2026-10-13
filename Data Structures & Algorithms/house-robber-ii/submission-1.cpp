class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }

        if(nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> dpOne(nums.size(), 0);
        int maxSoFarOne = nums[0];
        dpOne[0] = nums[0];
        dpOne[1] = nums[1];
        for(int i = 2; i < nums.size() - 1; i++) {
            dpOne[i] = maxSoFarOne + nums[i];
            maxSoFarOne = max(maxSoFarOne, dpOne[i - 1]);
        }
        maxSoFarOne = max(maxSoFarOne, dpOne[dpOne.size() - 2]);

        vector<int> dpTwo(nums.size(), 0);
        int maxSoFarTwo = nums[1];
        dpTwo[1] = nums[1];
        dpTwo[2] = nums[2];
        for(int i = 3; i < nums.size(); i++) {
            dpTwo[i] = maxSoFarTwo + nums[i];
            maxSoFarTwo = max(maxSoFarTwo, dpTwo[i - 1]);
        }
        maxSoFarTwo = max(maxSoFarTwo, dpTwo[dpTwo.size() - 1]);
        return max(maxSoFarOne, maxSoFarTwo);
    }
};
