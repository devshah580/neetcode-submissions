class Solution {
public:
    int helper(string& s, int index, vector<int>& dp) {
        if(index >= s.size()) {
            return 1;
        }

        if(dp[index] != -1) {
            return dp[index];
        }

        if(s[index] == '0') {
            dp[index] = 0;
            return 0;
        }

        int result = helper(s, index + 1, dp);
        if(index < s.size() - 1) {
            if(s[index] == '1') {
                result += helper(s, index + 2, dp);
            }

            if(s[index] == '2' && s[index + 1] >= '0' && s[index + 1] <= '6') {
                result += helper(s, index + 2, dp);
            } 
        }

        dp[index] = result;
        return result;

    }
    int numDecodings(string s) {
        int decodeWays = 0;
        vector<int> dp(s.size(), -1);
        return helper(s, 0, dp);
    }
};
