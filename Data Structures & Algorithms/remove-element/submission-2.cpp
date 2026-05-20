class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) {
            return 0;
        }

        int left = 0;
        int right = nums.size() - 1;
        while(right >= 0 && nums[right] == val) {
            right--;
        }
        while(left <= right && right >= 0 && left < nums.size()) {
            if(nums[left] == val) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                right--;
                while(right >= 0 && nums[right] == val) {
                    right--;
                }
            }
            left++;
        }
        return left;
    }
};