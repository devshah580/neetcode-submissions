class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = nums[0];
        int result = INT_MAX;
        while(right < nums.size()) {
            if(sum < target) {
                right++;
                if(right < nums.size()) {
                    sum += nums[right];
                }
            } else {
                result = min(result, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        if(result == INT_MAX) {
            return 0;
        } else {
            return result;
        }
    }
};