class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        int j = 0;
        while(true) {
            i = nums[i];
            j = nums[nums[j]];
            if(i == j) {
                int slow = 0;
                while(true) {
                    slow = nums[slow];
                    i = nums[i];
                    if(i == slow) {
                        return i;
                    }
                }
            }
        }
        return -1;
    }
};
