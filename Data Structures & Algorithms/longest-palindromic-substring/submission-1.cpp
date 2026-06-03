class Solution {
public:
    string longestPalindrome(string s) {
        string longestSubstring = "";
        for(int i = 0; i < s.size(); i++) {
            string tempSubstring = "";
            tempSubstring += s[i];

            int left = i - 1;
            while(left >= 0 && s[left] == s[i]) {
                tempSubstring = s[left] + tempSubstring;
                left--;
            }
            int right = i + 1;
            while(right < s.size() && s[right] == s[i]) {
                tempSubstring += s[right];
                right++;
            }

            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                tempSubstring = s[left] + tempSubstring + s[right];
                left--;
                right++;
            }
            if(tempSubstring.size() > longestSubstring.size()) {
                longestSubstring = tempSubstring;
            }
        }
        return longestSubstring;
    }
};
