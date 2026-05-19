class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int countZeros = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                product *= nums[i];
            } else {
                countZeros++;
            }
        }

        if(countZeros > 1 || countZeros == nums.size()) {
            return vector<int>(nums.size(), 0);
        }
        vector<int> result(nums.size(), 0);
        for(int i = 0; i < result.size(); i++) {
            if(countZeros == 1 && nums[i] != 0) {
                result[i] = 0;
            } else if(countZeros == 1){
                result[i] = product;
            } else {
                result[i] = product / nums[i];
            }
        }
        return result;
    }
};
