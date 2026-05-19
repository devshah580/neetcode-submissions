class Solution {
public:
    int search(vector<int>& nums, int target) {
        int end = nums.size() - 1;
        int start = 0;
        while(start <= end) {
            int middle = start + ((end - start) / 2);
            if(nums[middle] < target) {
                start = middle + 1;
            } else if(nums[middle] > target){
                end = middle - 1;
            } else {
                return middle;
            }
        }
        return -1;
    }
};
