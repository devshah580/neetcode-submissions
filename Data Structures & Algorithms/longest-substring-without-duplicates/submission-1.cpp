class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0;
        int right = 0;
        int longestLength = 0;
        int length = 0;
        while(right < s.size()) {
            if(seen.count(s[right]) == 0) {
                length++;
                longestLength = max(length, longestLength);
                seen.insert(s[right]);
                right++;
            } else {
                length--;
                seen.erase(s[left]);
                left++;
            }
        }
        return longestLength;
    }
};
