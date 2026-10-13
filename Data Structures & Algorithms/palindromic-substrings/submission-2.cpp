class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            count++;
            int left = i;
            int right = i;
            while(left - 1 >= 0 && right + 1 < s.size() && s[left - 1] == s[right + 1]) {
                count++;
                left--;
                right++;
            }

            left = i;
            right = i;
            if(right + 1 < s.size() && s[right + 1] == s[i]) {
                count++;
                right++;
            } else {
                continue;
            }

            
            while(left - 1 >= 0 && right + 1 < s.size() && s[left - 1] == s[right + 1]) {
                count++;
                left--;
                right++;
            }
        }
        return count;
    }
};
