class Solution {
public:
    string longestPalindrome(string s) {
        string longestSubstring = "";
        for(int i = 0; i < s.size(); i++) {
            int left = i;
            while(left - 1 >= 0 && s[left - 1] == s[i]) {
                left--;
            }

            int right = i;
            while(right + 1 < s.size() && s[right + 1] == s[i]) {
                right++;
            }

            while(left - 1 >= 0 && right + 1 < s.size() && s[left - 1] == s[right + 1]) {
                left--;
                right++;
            }

            if(right - left + 1 > longestSubstring.size()) {
                longestSubstring = s.substr(left, right - left + 1);
            }
        }
        return longestSubstring;
    }
};
