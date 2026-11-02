class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        int result = 0;
        int prefixSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            if(prefixSum == k) {
                result++;
            }
            result += freqs[prefixSum - k];
            freqs[prefixSum]++;
        }
        return result;
    }
};
//2, 1, 2, 4
//4, 2, 3, 2


//4,8,12,16,20,24
//24,20,16,12,8,4