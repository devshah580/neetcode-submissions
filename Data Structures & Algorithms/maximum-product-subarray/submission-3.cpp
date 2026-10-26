class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = INT_MIN;
        int negProduct = 1;
        int currProduct = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                currProduct *= nums[i];
                result = max(currProduct, result);
                negProduct *= nums[i];
            } else if(nums[i] == 0) {
                currProduct = 1;
                negProduct = 1;
                result = max(result, 0);
            } else {
                if(negProduct > 0) {
                    negProduct *= nums[i];
                    result = max(result, negProduct);
                    currProduct = 1;
                } else {
                    negProduct *= nums[i];
                    currProduct = negProduct;
                    result = max(result, negProduct);
                }
            }
        }

        currProduct = 1;
        negProduct = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] > 0) {
                currProduct *= nums[i];
                result = max(currProduct, result);
                negProduct *= nums[i];
            } else if(nums[i] == 0) {
                currProduct = 1;
                negProduct = 1;
                result = max(result, 0);
            } else {
                if(negProduct > 0) {
                    negProduct *= nums[i];
                    result = max(result, negProduct);
                    currProduct = 1;
                } else {
                    negProduct *= nums[i];
                    currProduct = negProduct;
                    result = max(result, negProduct);
                }
            }
        }

        return result;
    }
};
