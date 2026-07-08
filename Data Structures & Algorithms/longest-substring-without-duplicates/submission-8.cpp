class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_seen;
        int longestLength = 0;
        int left = -1;
        for(int i = 0; i < s.size(); i++) {
            if(last_seen.count(s[i])) {
                left = max(left, last_seen[s[i]]);
            }
            longestLength = max(longestLength, i - left);
            last_seen[s[i]] = i;
        }
        return longestLength;
    }
};


