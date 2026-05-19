class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_index;
        int length = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++) {
            if(last_index.count(s[i]) != 0) {
                left = max(last_index[s[i]] + 1, left);
            }
            length = max(length, i - left + 1);
            last_index[s[i]] = i;
        }
        return length;
    }
};


