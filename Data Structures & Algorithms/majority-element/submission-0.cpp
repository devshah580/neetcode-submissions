class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std:unordered_map<int, int> freqs;
        for(int i = 0; i < nums.size(); i++) {
            freqs[nums[i]]++;
            if(freqs[nums[i]] > (nums.size() / 2)) {
                return nums[i];
            }
        }
        return -1;
    }
};