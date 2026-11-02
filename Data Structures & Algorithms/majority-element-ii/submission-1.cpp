class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freqs;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            if(freqs.count(nums[i]) && freqs[nums[i]] == -1) {
                continue;
            }
            freqs[nums[i]]++;
            if(freqs[nums[i]] > nums.size() / 3) {
                result.push_back(nums[i]);
                freqs[nums[i]] = -1;
            }
        }
        return result;
    }
};