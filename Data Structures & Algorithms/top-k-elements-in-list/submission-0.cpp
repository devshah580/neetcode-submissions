class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       map<int, int> freq;
       for(int n : nums) {
        freq[n]++;
       }

       vector<vector<int>> buckets(nums.size() + 1);
       for(const auto& [key, value] : freq) {
        buckets[value].push_back(key);
       }
       
       vector<int> result;
       for(int i = buckets.size() - 1; i >= 0; i--) {
        for(int j = 0; j < buckets[i].size(); j++) {
            if(result.size() < k) {
                result.push_back(buckets[i][j]);
            }
        }
       }

       return result;
       
        
    }
};
