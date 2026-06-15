class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int minNum = INT_MAX;
        while(left <= right) {
            int middle = left + (right - left) / 2;
            minNum = min(minNum, nums[middle]);
            if(nums[right] < nums[middle]) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return minNum;
    }
};
