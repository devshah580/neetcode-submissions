class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> next;
        for(int n : nums) {
            next[n] = n+1;
        }

        int maxCount = 0;
        for(const auto& [key, value] : next) {
            int count = 1;
            int temp = value;
            while(next.count(temp)) {
                temp = next[temp];
                count++;
            }
            if(count > maxCount) {
                maxCount = count;
            }
        }
        return maxCount;
    }
};
